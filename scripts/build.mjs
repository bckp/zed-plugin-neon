import { execFileSync } from 'node:child_process';
import { copyFileSync, mkdirSync, existsSync } from 'node:fs';
import { homedir } from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { build } from 'esbuild';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const assets = path.join(root, 'server/assets');
mkdirSync(assets, { recursive: true });
const candidates = [
  process.env.WASI_SDK_PATH && path.join(process.env.WASI_SDK_PATH, 'bin/clang'),
  path.join(homedir(), 'Library/Application Support/Zed/extensions/build/wasi-sdk/bin/clang'),
  path.join(homedir(), '.local/share/zed/extensions/build/wasi-sdk/bin/clang'),
].filter(Boolean);
const clang = candidates.find(existsSync);
if (!clang) throw new Error('Set WASI_SDK_PATH to a wasi-sdk installation before building.');
const src = path.join(root, 'tree-sitter-neon/src');
execFileSync(clang, [
  '-fPIC', '-shared', '-Os', '-Wl,--export=tree_sitter_neon',
  '-I', src, path.join(src, 'parser.c'), '-o', path.join(assets, 'tree-sitter-neon.wasm'),
], { stdio: 'inherit' });
copyFileSync(path.join(root, 'node_modules/web-tree-sitter/tree-sitter.wasm'), path.join(assets, 'tree-sitter.wasm'));
copyFileSync(path.join(root, 'node_modules/tree-sitter-wasms/out/tree-sitter-php.wasm'), path.join(assets, 'tree-sitter-php.wasm'));
await build({
  entryPoints: [path.join(root, 'server/src/main.mjs')],
  outfile: path.join(root, 'server/dist/neon-server.cjs'),
  bundle: true, platform: 'node', format: 'cjs', target: 'node18', legalComments: 'linked',
});
console.log('Built NEON grammar and navigation server.');
