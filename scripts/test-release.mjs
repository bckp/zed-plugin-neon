import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { execFileSync, spawnSync } from 'node:child_process';
import { mkdtempSync, readFileSync, readdirSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const temp = mkdtempSync(path.join(tmpdir(), 'neon release test '));
const version = JSON.parse(readFileSync(path.join(root, 'package.json'), 'utf8')).version;
try {
  const packaged = spawnSync(process.execPath, [path.join(root, 'scripts/package-server.mjs'), '--output-dir', temp], { encoding: 'utf8' });
  assert.equal(packaged.status, 0, `Packaging failed: ${packaged.stderr}`);
  const archive = path.join(temp, `neon-navigation-${version}.tar.gz`);
  const hash = createHash('sha256').update(readFileSync(archive)).digest('hex');
  assert.equal(readFileSync(path.join(temp, 'SHA256SUMS'), 'utf8'), `${hash}  neon-navigation-${version}.tar.gz\n`);
  execFileSync('tar', ['-xzf', archive, '-C', temp]);
  const server = path.join(temp, 'neon-navigation');
  const manifest = JSON.parse(readFileSync(path.join(server, 'manifest.json'), 'utf8'));
  assert.equal(manifest.version, version);
  for (const file of [
    'neon-server.cjs', 'neon-server.cjs.LEGAL.txt',
    'assets/tree-sitter.wasm', 'assets/tree-sitter-neon.wasm', 'assets/tree-sitter-php.wasm',
    'LICENSE', 'THIRD_PARTY_NOTICES.md', 'licenses/tree-sitter.txt', 'licenses/tree-sitter-php.txt',
    'licenses/tree-sitter-wasms.txt', 'licenses/vscode-languageserver.txt', 'licenses/fast-glob.txt',
  ]) {
    assert(Object.hasOwn(manifest.files, file), `Missing required release file: ${file}`);
    const bytes = readFileSync(path.join(server, file));
    assert(bytes.length > 0, `Empty required release file: ${file}`);
    assert.equal(manifest.files[file], createHash('sha256').update(bytes).digest('hex'));
  }
  assert(!readdirSync(server).includes('node_modules'));
  assert(!readdirSync(server).includes('src'));
  const smoke = spawnSync(process.execPath, [path.join(root, 'scripts/smoke-lsp.mjs'), '--server-dir', server], { encoding: 'utf8', timeout: 20000 });
  assert.equal(smoke.status, 0, `Packaged LSP failed: ${smoke.stderr}`);
  console.log(smoke.stdout.trim());
  console.log('Release archive, checksums, licenses, and extracted LSP passed.');
} finally {
  rmSync(temp, { recursive: true, force: true });
}
