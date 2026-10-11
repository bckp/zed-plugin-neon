import { before, test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { TextDocument } from 'vscode-languageserver-textdocument';
import { Workspace } from '../src/workspace.mjs';

const root = fileURLToPath(new URL('../../examples/demo', import.meta.url));
const assets = fileURLToPath(new URL('../assets', import.meta.url));
const uri = name => pathToFileURL(path.join(root, name)).href;
const at = (name, text, delta = 0) => {
  const content = fs.readFileSync(path.join(root, name), 'utf8');
  const offset = content.indexOf(text);
  assert.notEqual(offset, -1);
  return TextDocument.create(uri(name), 'neon', 0, content).positionAt(offset + delta);
};
let workspace;
before(async () => { workspace = await Workspace.create([root], assets); });

test('relative includes open the file and return incoming references', async () => {
  const links = await workspace.links(uri('config.neon'));
  assert.equal(links[0].target, uri('Product/import-product.neon'));
  const definitions = await workspace.definition(uri('config.neon'), at('config.neon', 'Product/import-product.neon', 3));
  assert.equal(definitions[0].uri, uri('Product/import-product.neon'));
  const incoming = await workspace.references(uri('config.neon'), at('config.neon', 'services.neon', 3));
  assert.deepEqual(new Set(incoming.map(item => item.uri)), new Set([uri('config.neon'), uri('Product/import-product.neon')]));
});

test('path parameters resolve inside inline includes', async () => {
  const links = await workspace.links(uri('parameter-includes.neon'));
  assert.equal(links[0].target, uri('Product/import-product.neon'));
});

test('service references resolve across includes without crossing unrelated configs', async () => {
  const definitions = await workspace.definition(uri('config.neon'), at('config.neon', '@importer', 3));
  assert.equal(definitions[0].uri, uri('services.neon'));
  const references = await workspace.references(uri('services.neon'), at('services.neon', 'importer', 2));
  assert.equal(references.length, 2);
  assert(references.every(item => item.uri === uri('config.neon')));
  const unrelated = await workspace.definition(uri('Other/config.neon'), at('Other/config.neon', '@importer', 3));
  assert.equal(unrelated[0].uri, uri('Other/config.neon'));
});

test('PHP classes and service methods navigate to PHP declarations', async () => {
  const classes = await workspace.definition(uri('config.neon'), at('config.neon', 'App\\Service\\ProductExporter', 5));
  assert.equal(classes[0].uri, uri('src/Service/ProductExporter.php'));
  assert.equal(classes[0].range.start.line, 4);
  const methods = await workspace.definition(uri('config.neon'), at('config.neon', '@importer::import', 14));
  assert.equal(methods[0].uri, uri('src/Service/ProductImporter.php'));
  assert.equal(methods[0].range.start.line, 6);
  const file = uri('class-key.neon');
  const content = 'services:\n    App\\Service\\ProductImporter:\n';
  workspace.update(file, content);
  const keyedClass = await workspace.definition(file, { line: 1, character: 10 });
  assert.equal(keyedClass[0].uri, uri('src/Service/ProductImporter.php'));
  workspace.close(file);
});

test('unsaved edits update links and include cycles terminate', async () => {
  const file = uri('parameter-includes.neon');
  workspace.update(file, 'includes:\n    - config.neon\n    - parameter-includes.neon\n');
  const links = await workspace.links(file);
  assert.equal(links.length, 2);
  assert.equal(links[1].target, file);
  const graph = await workspace.includeGraph();
  assert(graph.edges.some(edge => edge.source === file && edge.target === file));
  workspace.close(file);
});
