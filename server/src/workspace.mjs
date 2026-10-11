import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import fg from 'fast-glob';
import Parser from 'web-tree-sitter';
import { TextDocument } from 'vscode-languageserver-textdocument';

const ignore = ['**/.git/**', '**/node_modules/**', '**/vendor/**', '**/target/**', '**/grammars/**', '**/temp/**', '**/cache/**'];
const scalarTypes = new Set(['unquoted_string', 'single_quote_string', 'double_quote_string', 'entity_name']);
const normalizeClass = name => name.replace(/^\\/, '').toLowerCase();
const fileUri = file => pathToFileURL(path.resolve(file)).href;
const filePath = uri => {
  try { return fileURLToPath(uri); } catch { return null; }
};
const isFile = file => {
  try { return fs.statSync(file).isFile(); } catch { return false; }
};
const contains = (token, offset) => token.start <= offset && offset <= token.end;

function* walk(node) {
  yield node;
  for (const child of node.namedChildren) yield* walk(child);
}

function valueOf(node) {
  if (!node) return null;
  const text = node.text.trim();
  if (node.type === 'single_quote_string') return text.slice(1, -1).replace(/''/g, "'");
  if (node.type === 'double_quote_string') {
    try { return JSON.parse(text); } catch { return text.slice(1, -1); }
  }
  return text;
}

function tokenOf(node, document) {
  const quote = ['single_quote_string', 'double_quote_string'].includes(node.type) ? 1 : 0;
  const start = node.startIndex + quote;
  const end = node.endIndex - quote;
  return { start, end, range: { start: document.positionAt(start), end: document.positionAt(end) } };
}

function indentAt(node, text) {
  const lineStart = text.lastIndexOf('\n', node.startIndex - 1) + 1;
  const leading = text.slice(lineStart, node.startIndex).match(/^[ \t]*/)[0];
  let indent = 0;
  for (const character of leading) indent += character === '\t' ? 4 - indent % 4 : 1;
  return indent;
}

function recordOf(node, text) {
  const sequence = node.type === 'block_sequence_item';
  const pair = sequence ? node.namedChildren.find(child => child.type === 'block_mapping_pair') : node;
  const key = pair?.childForFieldName('key');
  const value = key ? pair.childForFieldName('value') : sequence ? node.namedChildren[0] : node;
  const record = { node, key, name: key ? valueOf(key) : null, value, sequence, indent: indentAt(node, text), children: [] };
  if (value?.type === 'inline_mapping') {
    record.children = value.namedChildren.filter(child => child.type === 'inline_mapping_pair').map(child => recordOf(child, text));
  }
  return record;
}

// The highlighting grammar keeps block lines flat; indentation supplies block ownership.
function blockRecords(tree, text) {
  const records = [];
  const stack = [];
  for (const node of tree.rootNode.namedChildren) {
    if (node.type === 'comment') continue;
    if (node.type === 'inline_mapping') {
      records.push(...node.namedChildren.filter(child => child.type === 'inline_mapping_pair').map(child => recordOf(child, text)));
      continue;
    }
    const record = recordOf(node, text);
    while (stack.length) {
      const parent = stack.at(-1);
      const sameLevelSequence = record.sequence && record.indent === parent.indent && parent.key && !parent.value;
      if (record.indent > parent.indent || sameLevelSequence) break;
      stack.pop();
    }
    (stack.at(-1)?.children ?? records).push(record);
    if ((record.key && !record.value) || (record.sequence && record.key)) stack.push(record);
  }
  return records;
}

function classReference(value, entity = false) {
  const match = /^(\\?(?:[A-Za-z_\u0080-\uFFFF][\w\u0080-\uFFFF]*\\)*[A-Za-z_\u0080-\uFFFF][\w\u0080-\uFFFF]*)(?:::(\w+))?$/.exec(value);
  if (!match || (!entity && !value.includes('\\') && !/^[A-Z]/.test(value))) return null;
  return { kind: 'class', name: match[1], method: match[2] };
}

function serviceReference(value) {
  const match = /^@([^@:\s()]+)(?:::(\w+))?$/.exec(value);
  return match ? { kind: 'service', name: match[1], method: match[2] } : null;
}

function parseNeon(uri, text, parser) {
  const document = TextDocument.create(uri, 'neon', 0, text);
  const tree = parser.parse(text);
  const records = blockRecords(tree, text);
  const includes = [];
  const services = [];
  const parameters = {};
  const references = [];
  for (const record of records) {
    const section = record.name?.replace(/!$/, '');
    if (section === 'includes') {
      const nodes = record.value?.type === 'inline_sequence' ? record.value.namedChildren
        : record.value ? [record.value] : record.children.filter(child => child.sequence).map(child => child.value);
      for (const node of nodes.filter(node => node && scalarTypes.has(node.type))) {
        includes.push({ source: uri, expression: valueOf(node), ...tokenOf(node, document) });
      }
    }
    if (section === 'parameters') {
      const collect = (children, prefix = '') => {
        for (const child of children) {
          if (!child.name) continue;
          const name = prefix + child.name;
          if (child.value && scalarTypes.has(child.value.type)) parameters[name] = valueOf(child.value);
          if (child.children.length) collect(child.children, name + '.');
        }
      };
      collect(record.children);
    }
    if (section === 'services') {
      for (const child of record.children) {
        const factory = child.children.find(item => ['factory', 'class', 'type'].includes(item.name));
        const candidate = factory?.value ?? child.value;
        const nameNode = candidate && [...walk(candidate)].find(node => scalarTypes.has(node.type));
        const value = nameNode ? valueOf(nameNode) : '';
        const reference = serviceReference(value) ?? classReference(value, nameNode?.type === 'entity_name');
        if (!child.key && reference?.kind !== 'class') continue;
        const id = child.name?.replace(/!$/, '') ?? reference.name.replace(/^\\/, '');
        const declaration = child.key ?? nameNode;
        services.push({ id, uri, ...tokenOf(declaration, document), className: reference?.kind === 'class' ? reference.name : null,
          factoryService: reference?.kind === 'service' ? reference.name : null });
      }
    }
  }
  for (const node of walk(tree.rootNode)) {
    if (!scalarTypes.has(node.type)) continue;
    const key = node.parent?.childForFieldName('key');
    if (key?.id === node.id) continue;
    const value = valueOf(node);
    const reference = serviceReference(value) ?? classReference(value, node.type === 'entity_name');
    if (reference) references.push({ ...reference, uri, ...tokenOf(node, document) });
  }
  return { uri, text, document, tree, records, includes, services, parameters, references };
}

export class Workspace {
  static async create(roots, assets) {
    await Parser.init({ locateFile: () => path.join(assets, 'tree-sitter.wasm') });
    const [neon, php] = await Promise.all([
      Parser.Language.load(path.join(assets, 'tree-sitter-neon.wasm')),
      Parser.Language.load(path.join(assets, 'tree-sitter-php.wasm')),
    ]);
    return new Workspace(roots, neon, php);
  }

  constructor(roots, neon, php) {
    this.roots = roots.map(root => path.resolve(root));
    this.neonParser = new Parser();
    this.neonParser.setLanguage(neon);
    this.phpParser = new Parser();
    this.phpParser.setLanguage(php);
    this.open = new Map();
    this.documents = new Map();
    this.phpDocuments = new Map();
    this.edges = [];
    this.lastRefresh = 0;
    this.revision = 0;
    this.composer = [];
  }

  update(uri, text) { this.open.set(uri, text); this.invalidate(); }
  close(uri) { this.open.delete(uri); this.invalidate(); }
  invalidate() { this.lastRefresh = 0; this.revision++; }

  read(uri) {
    if (this.open.has(uri)) return { text: this.open.get(uri), stamp: 'open:' + this.open.get(uri) };
    const file = filePath(uri);
    if (!file) return null;
    try {
      const stat = fs.statSync(file);
      if (!stat.isFile() || stat.size > 2 * 1024 * 1024) return null;
      return { text: fs.readFileSync(file, 'utf8'), stamp: stat.mtimeMs + ':' + stat.size };
    } catch { return null; }
  }

  loadNeon(uri) {
    const source = this.read(uri);
    if (!source) return null;
    const previous = this.documents.get(uri);
    if (previous?.stamp === source.stamp) return previous;
    previous?.tree.delete();
    const record = { ...parseNeon(uri, source.text, this.neonParser), stamp: source.stamp };
    this.documents.set(uri, record);
    return record;
  }

  async refresh() {
    if (this.refreshing) return this.refreshing;
    if (this.lastRefresh && Date.now() - this.lastRefresh < 1000) return;
    const revision = this.revision;
    this.refreshing = this.refreshFiles().finally(() => {
      this.lastRefresh = revision === this.revision ? Date.now() : 0;
      this.refreshing = null;
    });
    return this.refreshing;
  }

  async refreshFiles() {
    const paths = (await Promise.all(this.roots.map(cwd => fg(['**/*.neon'], { cwd, absolute: true, ignore, followSymbolicLinks: false })))).flat();
    const active = new Set([...paths.map(fileUri), ...this.open.keys()]);
    for (const uri of active) this.loadNeon(uri);
    this.edges = [];
    // A second pass resolves path parameters inherited through ordinary includes.
    for (let pass = 0; pass < 4; pass++) {
      const edges = [];
      for (const uri of active) {
        const document = this.documents.get(uri);
        if (!document) continue;
        const parameters = this.parametersFor(uri);
        for (const include of document.includes) {
          const target = this.resolvePath(uri, include.expression, parameters);
          edges.push({ ...include, target });
          if (target && !active.has(target)) {
            active.add(target);
            this.loadNeon(target);
          }
        }
      }
      const same = edges.length === this.edges.length && edges.every((edge, index) => edge.target === this.edges[index].target);
      this.edges = edges;
      if (same) break;
    }
    for (const [uri, document] of this.documents) {
      if (!active.has(uri) || !this.read(uri)) {
        document.tree.delete();
        this.documents.delete(uri);
      }
    }
    this.phpFiles = (await Promise.all(this.roots.map(cwd => fg('**/*.php', { cwd, absolute: true, ignore, followSymbolicLinks: false })))).flat();
    this.composer = [];
    for (const root of this.roots) {
      const manifests = [path.join(root, 'composer.json'), ...await fg('vendor/*/*/composer.json', { cwd: root, absolute: true, followSymbolicLinks: false })];
      for (const manifest of manifests) {
        try {
          const json = JSON.parse(fs.readFileSync(manifest, 'utf8'));
          for (const section of ['autoload', ...(manifest === path.join(root, 'composer.json') ? ['autoload-dev'] : [])]) {
            for (const [prefix, directories] of Object.entries(json[section]?.['psr-4'] ?? {})) {
              for (const directory of Array.isArray(directories) ? directories : [directories]) {
                if (typeof directory === 'string') this.composer.push({ prefix, directory: path.resolve(path.dirname(manifest), directory) });
              }
            }
          }
        } catch { /* Missing or partially edited Composer metadata is harmless. */ }
      }
    }
    this.composer.sort((a, b) => b.prefix.length - a.prefix.length);
  }

  component(uri) {
    const seen = new Set([uri]);
    const queue = [uri];
    for (const current of queue) {
      for (const edge of this.edges) {
        const neighbor = edge.source === current ? edge.target : edge.target === current ? edge.source : null;
        if (neighbor && !seen.has(neighbor)) { seen.add(neighbor); queue.push(neighbor); }
      }
    }
    return [...seen];
  }

  parametersFor(uri) {
    const file = filePath(uri);
    const root = this.roots.find(root => file && (file === root || file.startsWith(root + path.sep))) ?? this.roots[0];
    const parameters = { rootDir: root };
    if (fs.existsSync(path.join(root, 'app'))) parameters.appDir = path.join(root, 'app');
    for (const member of this.component(uri).reverse()) Object.assign(parameters, this.documents.get(member)?.parameters);
    return parameters;
  }

  resolvePath(uri, expression, parameters) {
    let value = expression;
    for (let pass = 0; pass < 8 && /%[^%]+%/.test(value); pass++) {
      const previous = value;
      value = value.replace(/%([^%]+)%/g, (match, name) => parameters[name] ?? match);
      if (value === previous) break;
    }
    if (/%[^%]+%/.test(value) || !filePath(uri)) return null;
    const resolved = path.resolve(path.dirname(filePath(uri)), value);
    if (!isFile(resolved)) return null;
    return fileUri(resolved);
  }

  loadPhp(uri) {
    const source = this.read(uri);
    if (!source) return [];
    const previous = this.phpDocuments.get(uri);
    if (previous?.stamp === source.stamp) return previous.classes;
    const document = TextDocument.create(uri, 'php', 0, source.text);
    const tree = this.phpParser.parse(source.text);
    const classes = [];
    const visit = (nodes, namespace = '') => {
      let currentNamespace = namespace;
      for (const node of nodes) {
        if (node.type === 'namespace_definition') {
          const name = node.childForFieldName('name')?.text ?? node.namedChildren.find(child => child.type === 'namespace_name')?.text ?? '';
          const body = node.childForFieldName('body') ?? node.namedChildren.find(child => child.type === 'compound_statement');
          if (body) visit(body.namedChildren, name);
          else currentNamespace = name;
        } else if (['class_declaration', 'interface_declaration', 'trait_declaration', 'enum_declaration'].includes(node.type)) {
          const name = node.childForFieldName('name');
          if (!name) continue;
          const className = (currentNamespace ? currentNamespace + '\\' : '') + name.text;
          const body = node.childForFieldName('body');
          const methods = new Map();
          for (const method of body?.namedChildren ?? []) {
            if (method.type !== 'method_declaration') continue;
            const methodName = method.childForFieldName('name');
            if (methodName) methods.set(methodName.text.toLowerCase(), { uri, ...tokenOf(methodName, document) });
          }
          classes.push({ name: className, uri, ...tokenOf(name, document), methods });
        }
      }
    };
    visit(tree.rootNode.namedChildren);
    tree.delete();
    this.phpDocuments.set(uri, { stamp: source.stamp, classes });
    return classes;
  }

  classes(name) {
    const canonical = name.replace(/^\\/, '');
    const candidates = [];
    for (const mapping of this.composer) {
      if (!canonical.startsWith(mapping.prefix)) continue;
      candidates.push(path.join(mapping.directory, canonical.slice(mapping.prefix.length).replace(/\\/g, '/') + '.php'));
    }
    for (const file of candidates.filter(isFile)) {
      const found = this.loadPhp(fileUri(file)).filter(item => normalizeClass(item.name) === normalizeClass(canonical));
      if (found.length) return found;
    }
    const all = this.phpFiles.flatMap(file => this.loadPhp(fileUri(file)));
    const exact = all.filter(item => normalizeClass(item.name) === normalizeClass(canonical));
    if (exact.length || canonical.includes('\\')) return exact;
    return all.filter(item => item.name.split('\\').at(-1).toLowerCase() === canonical.toLowerCase());
  }

  serviceDeclarations(uri, name) {
    const results = this.component(uri).flatMap(member => this.documents.get(member)?.services.filter(service => service.id === name) ?? []);
    const local = results.filter(service => service.uri === uri);
    return local.length ? local : results;
  }

  serviceClasses(uri, service, seen = new Set()) {
    const key = service.uri + ':' + service.id;
    if (seen.has(key)) return [];
    seen.add(key);
    if (service.className) return this.classes(service.className);
    return service.factoryService ? this.serviceDeclarations(uri, service.factoryService).flatMap(base => this.serviceClasses(uri, base, seen)) : [];
  }

  targetAt(uri, position) {
    const document = this.documents.get(uri);
    if (!document) return null;
    const offset = document.document.offsetAt(position);
    const include = this.edges.find(edge => edge.source === uri && contains(edge, offset));
    if (include) return { kind: 'include', ...include };
    const service = document.services.find(item => contains(item, offset));
    if (service) return { kind: 'declaration', service };
    const reference = document.references.find(item => contains(item, offset));
    if (reference) return { ...reference, onMethod: reference.method && offset >= reference.end - reference.method.length };
    const section = document.records.find(record => record.name === 'includes' && record.key && contains(tokenOf(record.key, document.document), offset));
    if (section) return { kind: 'file', target: uri };
    return null;
  }

  location(item) { return { uri: item.uri, range: item.range }; }

  async definition(uri, position) {
    await this.refresh();
    const target = this.targetAt(uri, position);
    if (!target) return [];
    if (target.kind === 'include') return target.target ? [{ uri: target.target, range: { start: { line: 0, character: 0 }, end: { line: 0, character: 0 } } }] : [];
    if (target.kind === 'declaration') return this.serviceClasses(uri, target.service).map(item => this.location(item));
    if (target.kind === 'service') {
      const services = this.serviceDeclarations(uri, target.name);
      if (!target.onMethod) return services.map(item => this.location(item));
      return services.flatMap(service => this.serviceClasses(uri, service)).map(item => item.methods.get(target.method.toLowerCase()) ?? item).map(item => this.location(item));
    }
    if (target.kind === 'class') return this.classes(target.name).map(item => target.onMethod ? item.methods.get(target.method.toLowerCase()) ?? item : item).map(item => this.location(item));
    return [];
  }

  async links(uri) {
    await this.refresh();
    return this.edges.filter(edge => edge.source === uri && edge.target).map(edge => ({ range: edge.range, target: edge.target, tooltip: 'Open ' + edge.expression }));
  }

  async references(uri, position, includeDeclaration = false) {
    await this.refresh();
    const target = this.targetAt(uri, position);
    if (!target) return [];
    if (['include', 'file'].includes(target.kind)) {
      return this.edges.filter(edge => edge.target && edge.target === target.target).map(edge => ({ uri: edge.source, range: edge.range }));
    }
    const documents = this.component(uri).map(member => this.documents.get(member)).filter(Boolean);
    if (['service', 'declaration'].includes(target.kind)) {
      const name = target.kind === 'declaration' ? target.service.id : target.name;
      const locations = documents.flatMap(document => document.references.filter(item => item.kind === 'service' && item.name === name).map(item => this.location(item)));
      if (includeDeclaration) locations.push(...this.serviceDeclarations(uri, name).map(item => this.location(item)));
      return locations;
    }
    if (target.kind === 'class') {
      const classes = this.classes(target.name);
      const names = new Set(classes.map(item => normalizeClass(item.name)));
      const locations = documents.flatMap(document => document.references.filter(item => item.kind === 'class' &&
        (names.has(normalizeClass(item.name)) || this.classes(item.name).some(found => names.has(normalizeClass(found.name))))).map(item => this.location(item)));
      if (includeDeclaration) locations.push(...classes.map(item => this.location(item)));
      return locations;
    }
    return [];
  }

  label(uri) {
    const file = filePath(uri);
    if (!file) return uri;
    const root = this.roots.find(root => file.startsWith(root + path.sep));
    return root ? path.relative(root, file) : file;
  }

  async hover(uri, position) {
    await this.refresh();
    const target = this.targetAt(uri, position);
    if (!target) return null;
    let value;
    if (['include', 'file'].includes(target.kind)) {
      if (!target.target) value = 'Unresolved include: ' + target.expression;
      else {
        const incoming = this.edges.filter(edge => edge.target === target.target);
        value = '[' + this.label(target.target) + '](' + target.target + ')\n\nIncluded by:\n' +
          incoming.map(edge => '- [' + this.label(edge.source) + ':' + (edge.range.start.line + 1) + '](' + edge.source + '#L' + (edge.range.start.line + 1) + ')').join('\n');
      }
    } else {
      const definitions = await this.definition(uri, position);
      const name = target.kind === 'declaration' ? target.service.id : target.name;
      value = name + (definitions.length ? '\n\n' + definitions.map(item => '[' + this.label(item.uri) + ':' + (item.range.start.line + 1) + '](' + item.uri + '#L' + (item.range.start.line + 1) + ')').join('\n\n') : '\n\nDeclaration not found.');
    }
    return { contents: { kind: 'markdown', value } };
  }

  async symbols(uri) {
    await this.refresh();
    const document = this.documents.get(uri);
    if (!document) return [];
    const endOf = record => Math.max(record.node.endIndex, ...record.children.map(endOf));
    const symbol = record => ({
      name: record.name ?? valueOf(record.value) ?? '-',
      kind: record.name === 'services' ? 3 : 13,
      range: { start: document.document.positionAt(record.node.startIndex),
        end: document.document.positionAt(endOf(record)) },
      selectionRange: tokenOf(record.key ?? record.node, document.document).range,
      children: record.children.filter(child => child.key || child.sequence).map(symbol),
    });
    return document.records.filter(record => record.key).map(symbol);
  }

  async includeGraph() {
    await this.refresh();
    return { nodes: [...this.documents.keys()], edges: this.edges.map(edge => ({ source: edge.source, target: edge.target, expression: edge.expression, range: edge.range })) };
  }
}
