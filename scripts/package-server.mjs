import { createHash } from 'node:crypto';
import { execFileSync } from 'node:child_process';
import { cpSync, mkdirSync, mkdtempSync, readFileSync, readdirSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseArgs } from 'node:util';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const { values } = parseArgs({ options: { 'output-dir': { type: 'string', default: path.join(root, 'dist') } } });
const { version } = JSON.parse(readFileSync(path.join(root, 'package.json'), 'utf8'));
if (process.env.GITHUB_REF_TYPE === 'tag' && process.env.GITHUB_REF_NAME !== `v${version}`) {
  throw new Error(`Release tag must be v${version}.`);
}
const output = path.resolve(values['output-dir']);
mkdirSync(output, { recursive: true });
const temp = mkdtempSync(path.join(tmpdir(), 'neon-package-'));
const bundle = path.join(temp, 'neon-navigation');
try {
  mkdirSync(bundle);
  for (const [source, destination] of [
    ['server/dist/neon-server.cjs', 'neon-server.cjs'],
    ['server/dist/neon-server.cjs.LEGAL.txt', 'neon-server.cjs.LEGAL.txt'],
    ['server/assets', 'assets'], ['LICENSE', 'LICENSE'],
    ['THIRD_PARTY_NOTICES.md', 'THIRD_PARTY_NOTICES.md'], ['licenses', 'licenses'],
  ]) cpSync(path.join(root, source), path.join(bundle, destination), { recursive: true });
  const files = {};
  function checksums(dir, prefix = '') {
    for (const entry of readdirSync(dir, { withFileTypes: true }).sort((a, b) => a.name.localeCompare(b.name))) {
      const name = prefix + entry.name;
      if (entry.isDirectory()) checksums(path.join(dir, entry.name), `${name}/`);
      else files[name] = createHash('sha256').update(readFileSync(path.join(dir, entry.name))).digest('hex');
    }
  }
  checksums(bundle);
  writeFileSync(path.join(bundle, 'manifest.json'), `${JSON.stringify({ version, files }, null, 2)}\n`);
  const name = `neon-navigation-${version}.tar.gz`;
  const archive = path.join(output, name);
  execFileSync('tar', ['-czf', archive, '-C', temp, 'neon-navigation']);
  writeFileSync(path.join(output, 'SHA256SUMS'), `${createHash('sha256').update(readFileSync(archive)).digest('hex')}  ${name}\n`);
  console.log(`Packaged ${archive}`);
} finally { rmSync(temp, { recursive: true, force: true }); }
