import { createConnection, TextDocuments, ProposedFeatures, TextDocumentSyncKind } from 'vscode-languageserver/node.js';
import { TextDocument } from 'vscode-languageserver-textdocument';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { Workspace } from './workspace.mjs';

const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);
const assetsIndex = process.argv.indexOf('--assets-dir');
const assets = assetsIndex >= 0 ? process.argv[assetsIndex + 1] : path.resolve(path.dirname(process.argv[1]), '../assets');
let workspace;

connection.onInitialize(async params => {
  const roots = params.workspaceFolders?.map(folder => fileURLToPath(folder.uri))
    ?? (params.rootUri ? [fileURLToPath(params.rootUri)] : [process.cwd()]);
  workspace = await Workspace.create(roots, assets);
  return {
    serverInfo: { name: 'NEON Navigation', version: '0.1.0' },
    capabilities: {
      textDocumentSync: TextDocumentSyncKind.Full,
      definitionProvider: true,
      referencesProvider: true,
      hoverProvider: true,
      documentLinkProvider: { resolveProvider: false },
      documentSymbolProvider: true,
    },
  };
});

documents.onDidOpen(({ document }) => workspace?.update(document.uri, document.getText()));
documents.onDidChangeContent(({ document }) => workspace?.update(document.uri, document.getText()));
documents.onDidClose(({ document }) => workspace?.close(document.uri));
connection.onDidChangeWatchedFiles(() => workspace?.invalidate());
connection.onDefinition(params => workspace.definition(params.textDocument.uri, params.position));
connection.onReferences(params => workspace.references(params.textDocument.uri, params.position, params.context.includeDeclaration));
connection.onHover(params => workspace.hover(params.textDocument.uri, params.position));
connection.onDocumentLinks(params => workspace.links(params.textDocument.uri));
connection.onDocumentSymbol(params => workspace.symbols(params.textDocument.uri));
connection.onRequest('neon/includeGraph', () => workspace.includeGraph());
documents.listen(connection);
connection.listen();
