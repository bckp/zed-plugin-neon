import { spawn } from 'node:child_process';
import { fileURLToPath, pathToFileURL } from 'node:url';
import path from 'node:path';
import assert from 'node:assert/strict';
import { createMessageConnection, StreamMessageReader, StreamMessageWriter } from 'vscode-languageserver/node.js';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const demo = path.join(root, 'examples/demo');
const parameters = path.join(root, 'examples/parameters');
const uri = file => pathToFileURL(path.join(demo, file)).href;
const parameterUri = file => pathToFileURL(path.join(parameters, file)).href;
const child = spawn(process.execPath, [path.join(root, 'server/dist/neon-server.cjs'), '--stdio', '--assets-dir', path.join(root, 'server/assets')]);
const connection = createMessageConnection(new StreamMessageReader(child.stdout), new StreamMessageWriter(child.stdin));
child.stderr.on('data', data => process.stderr.write(data));
connection.listen();
const timeout = setTimeout(() => { child.kill(); process.exitCode = 1; }, 15000);
try {
  const initialization = await connection.sendRequest('initialize', { processId: process.pid, rootUri: pathToFileURL(demo).href,
    workspaceFolders: [{ uri: pathToFileURL(demo).href, name: 'demo' }, { uri: pathToFileURL(parameters).href, name: 'parameters' }], capabilities: {} });
  assert.equal(initialization.capabilities.definitionProvider, true);
  await connection.sendNotification('initialized', {});
  const links = await connection.sendRequest('textDocument/documentLink', { textDocument: { uri: uri('config.neon') } });
  assert.equal(links[0].target, uri('Product/import-product.neon'));
  const service = await connection.sendRequest('textDocument/definition', { textDocument: { uri: uri('config.neon') }, position: { line: 14, character: 53 } });
  assert.equal(service[0].uri, uri('services.neon'));
  const php = await connection.sendRequest('textDocument/definition', { textDocument: { uri: uri('config.neon') }, position: { line: 14, character: 22 } });
  assert.equal(php[0].uri, uri('src/Service/ProductExporter.php'));
  const parameter = await connection.sendRequest('textDocument/definition', { textDocument: { uri: parameterUri('shared.neon') }, position: { line: 1, character: 16 } });
  assert.deepEqual(new Set(parameter.map(item => item.uri)), new Set([parameterUri('dev.neon'), parameterUri('prod.neon')]));
  const hover = await connection.sendRequest('textDocument/hover', { textDocument: { uri: parameterUri('shared.neon') }, position: { line: 1, character: 16 } });
  assert.match(hover.contents.value, /local\.neon/);
  assert.doesNotMatch(hover.contents.value, /build\/dev|build\/prod/);
  const references = await connection.sendRequest('textDocument/references', { textDocument: { uri: parameterUri('dev.neon') }, position: { line: 6, character: 9 }, context: { includeDeclaration: false } });
  assert.equal(references.length, 3);
  await connection.sendRequest('shutdown', null);
  await connection.sendNotification('exit');
  console.log('LSP startup, includes, services, PHP classes, and parameter navigation passed.');
} finally {
  clearTimeout(timeout);
  connection.dispose();
  if (child.exitCode === null) child.kill();
}
