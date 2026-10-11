import { before, test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { TextDocument } from 'vscode-languageserver-textdocument';
import { Workspace } from '../src/workspace.mjs';

const root = fileURLToPath(new URL('../../examples/parameters', import.meta.url));
const assets = fileURLToPath(new URL('../assets', import.meta.url));
const uri = name => pathToFileURL(path.join(root, name)).href;
const at = (name, text, delta = 1) => {
  const content = fs.readFileSync(path.join(root, name), 'utf8');
  const offset = content.indexOf(text);
  assert.notEqual(offset, -1);
  return TextDocument.create(uri(name), 'neon', 0, content).positionAt(offset + delta);
};
const destinations = locations => locations.map(item => path.basename(fileURLToPath(item.uri))).sort();
let workspace;
before(async () => { workspace = await Workspace.create([root], assets); });

test('parameter jumps include numeric, boolean, null, and array declarations', async () => {
  for (const name of ['retries', 'enabled', 'optional', 'tags']) {
    const definitions = await workspace.definition(uri('shared.neon'), at('shared.neon', '%' + name + '%'));
    assert(definitions.some(item => item.uri === uri('base.neon')), name + ' declaration is navigable');
    const declaration = definitions.find(item => item.uri === uri('base.neon'));
    const content = fs.readFileSync(path.join(root, 'base.neon'), 'utf8');
    const document = TextDocument.create(uri('base.neon'), 'neon', 0, content);
    assert.equal(document.getText(declaration.range), name);
  }
});

test('parent parameters override ordered recursive includes', async () => {
  const own = await workspace.definition(uri('dev.neon'), at('dev.neon', '%outputDir%'));
  assert.deepEqual(destinations(own), ['dev.neon']);
  workspace.update(uri('dev.neon'), 'includes: [base.neon, local.neon, shared.neon]\nservices:\n    worker: Worker(%outputDir%)\n');
  try {
    const inherited = await workspace.definition(uri('dev.neon'), { line: 2, character: 21 });
    assert.deepEqual(destinations(inherited), ['local.neon']);
  } finally { workspace.close(uri('dev.neon')); }
});

test('shared files return distinct winners for dev and prod entry points', async () => {
  const definitions = await workspace.definition(uri('shared.neon'), at('shared.neon', '%outputDir%'));
  assert.deepEqual(destinations(definitions), ['dev.neon', 'prod.neon']);
  const unrelated = await workspace.definition(uri('unrelated.neon'), at('unrelated.neon', '%outputDir%'));
  assert.deepEqual(destinations(unrelated), ['unrelated.neon']);
});

test('parameterized includes use the later included parameter definition', async () => {
  workspace.update(uri('prod.neon'), 'includes: [base.neon, local.neon, %configFile%]\n');
  try {
    const links = await workspace.links(uri('prod.neon'));
    assert.equal(links[2].target, uri('shared.neon'));
    const definitions = await workspace.definition(uri('prod.neon'), { line: 0, character: 35 });
    assert.deepEqual(destinations(definitions), ['local.neon']);
  } finally { workspace.close(uri('prod.neon')); }
});

test('nested aliases follow merged keys while exclamation marks remove inherited keys', async () => {
  const nested = await workspace.definition(uri('shared.neon'), at('shared.neon', '%mailer.host%'));
  assert.deepEqual(destinations(nested), ['base.neon']);
  const reset = await workspace.definition(uri('reset.neon'), at('reset.neon', '%outputDir%'));
  assert.deepEqual(reset, []);
  const retained = await workspace.definition(uri('reset.neon'), at('reset.neon', '%only%'));
  assert.deepEqual(destinations(retained), ['reset.neon']);
});

test('parameter references omit escaped percent signs and comments', async () => {
  const references = await workspace.references(uri('dev.neon'), at('dev.neon', 'outputDir:'), false);
  assert.deepEqual(destinations(references), ['dev.neon', 'shared.neon', 'shared.neon']);
  const declarations = await workspace.references(uri('dev.neon'), at('dev.neon', 'outputDir:'), true);
  assert(declarations.some(item => item.uri === uri('prod.neon') && item.range.start.line === 5));
});

test('hover describes winning origins and overrides without revealing values', async () => {
  const hover = await workspace.hover(uri('shared.neon'), at('shared.neon', '%outputDir%'));
  assert.match(hover.contents.value, /dev\.neon/);
  assert.match(hover.contents.value, /prod\.neon/);
  assert.match(hover.contents.value, /base\.neon/);
  assert.match(hover.contents.value, /local\.neon/);
  assert.doesNotMatch(hover.contents.value, /build\/dev|build\/prod|build\/base|build\/local/);
});

test('merged array indices navigate to their contributing item', async () => {
  workspace.update(uri('shared.neon'), 'services:\n    worker: Worker(%tags.4%)\n');
  try {
    const definitions = await workspace.definition(uri('shared.neon'), { line: 1, character: 24 });
    assert.deepEqual(destinations(definitions), ['local.neon']);
    const document = TextDocument.create(uri('local.neon'), 'neon', 0, fs.readFileSync(path.join(root, 'local.neon'), 'utf8'));
    assert.equal(document.getText(definitions[0].range), 'three');
    const references = await workspace.references(uri('shared.neon'), { line: 1, character: 24 }, true);
    assert(references.some(item => item.uri === uri('local.neon') && document.getText(item.range) === 'three'));
  } finally { workspace.close(uri('shared.neon')); }
});

test('circular parameter aliases terminate without losing ordinary navigation', async () => {
  workspace.update(uri('shared.neon'), 'parameters:\n    a: %b.child%\n    b: %a%\nservices:\n    worker: Worker(%a.leaf%, %outputDir%)\n');
  try {
    const cycle = await workspace.definition(uri('shared.neon'), { line: 4, character: 24 });
    assert.deepEqual(cycle, []);
    const normal = await workspace.definition(uri('shared.neon'), { line: 4, character: 34 });
    assert.deepEqual(destinations(normal), ['dev.neon', 'prod.neon']);
  } finally { workspace.close(uri('shared.neon')); }
});

test('nested block and inline array mappings preserve member locations', async () => {
  const content = 'parameters:\n    rows:\n        - host: first.example\n        - host: second.example\n    inline: [{host: inline.example}]\nservices:\n    worker: Worker(%rows.1.host%, %inline.0.host%)\n';
  workspace.update(uri('shared.neon'), content);
  try {
    const document = TextDocument.create(uri('shared.neon'), 'neon', 0, content);
    for (const [reference, expectedLine] of [['%rows.1.host%', 3], ['%inline.0.host%', 4]]) {
      const definitions = await workspace.definition(uri('shared.neon'), document.positionAt(content.indexOf(reference) + 2));
      assert.equal(definitions.length, 1);
      assert.equal(definitions[0].range.start.line, expectedLine);
      assert.equal(document.getText(definitions[0].range), 'host');
    }
  } finally { workspace.close(uri('shared.neon')); }
});

test('resetting configured parameters keeps workspace path builtins available', async () => {
  workspace.update(uri('reset.neon'), 'includes: [%rootDir%/base.neon]\nparameters!: {only: 42}\n');
  try {
    const links = await workspace.links(uri('reset.neon'));
    assert.equal(links.length, 1);
    assert.equal(links[0].target, uri('base.neon'));
  } finally { workspace.close(uri('reset.neon')); }
});

test('parameterized include chains resolve until the graph stabilizes', async () => {
  const links = await workspace.links(uri('Chain/entry.neon'));
  assert.equal(links.length, 5);
  assert.equal(links[4].target, uri('Chain/four.neon'));
  const definitions = await workspace.definition(uri('Chain/entry.neon'), at('Chain/entry.neon', '%last%'));
  assert.deepEqual(destinations(definitions), ['four.neon']);
});

test('a nested mapping in a sequence keeps sibling keys outside its first key', async () => {
  const content = 'parameters:\n    rows:\n        - host:\n              name: first\n          port: 80\nservices:\n    worker: Worker(%rows.0.port%, %rows.0.host.port%)\n';
  workspace.update(uri('shared.neon'), content);
  try {
    const document = TextDocument.create(uri('shared.neon'), 'neon', 0, content);
    const sibling = await workspace.definition(uri('shared.neon'), document.positionAt(content.indexOf('%rows.0.port%') + 2));
    assert.equal(sibling.length, 1);
    assert.equal(document.getText(sibling[0].range), 'port');
    const invalid = await workspace.definition(uri('shared.neon'), document.positionAt(content.indexOf('%rows.0.host.port%') + 2));
    assert.deepEqual(invalid, []);
  } finally { workspace.close(uri('shared.neon')); }
});

test('implicit sequence indices continue after explicit numeric keys', async () => {
  const content = 'parameters:\n    list:\n        3: first\n        - second\nservices:\n    worker: Worker(%list.4%, %list.0%)\n';
  workspace.update(uri('shared.neon'), content);
  try {
    const document = TextDocument.create(uri('shared.neon'), 'neon', 0, content);
    const appended = await workspace.definition(uri('shared.neon'), document.positionAt(content.indexOf('%list.4%') + 2));
    assert.equal(appended.length, 1);
    assert.match(document.getText(appended[0].range), /second/);
    const absent = await workspace.definition(uri('shared.neon'), document.positionAt(content.indexOf('%list.0%') + 2));
    assert.deepEqual(absent, []);
  } finally { workspace.close(uri('shared.neon')); }
});
