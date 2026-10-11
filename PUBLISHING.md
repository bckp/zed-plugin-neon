# Publishing NEON For Zed

## Server Releases

The extension downloads a platform-independent server package from GitHub Releases in this repository. The server version is pinned to the Rust package version; it never fetches an arbitrary latest release.

The package contains neon-server.cjs, its legal notices, three WASM parser/runtime files, licenses, and manifest.json with a version and per-file SHA-256 hashes. SHA256SUMS accompanies the archive for external verification. The manifest detects incomplete or corrupted cache files; it is not a signature or an independent authenticity proof. Downloads use HTTPS from the project's release URL.

For each release:

1. Update package.json, Cargo.toml, extension.toml, serverInfo.version in server/src/main.mjs, and RELEASE_NOTES.md to the same version. Update Cargo.lock with cargo check.
2. Regenerate changed grammar sources and update the pinned grammar revision in extension.toml if needed.
3. Run the local checks and push the release commit to main. Wait for CI to pass.
4. Create and push a new version tag, such as v0.1.1. Do not move a published tag or replace a published server archive.
5. The Release workflow repeats CI, packages the tested build, and publishes the archive and SHA256SUMS. No custom repository secrets are needed.

~~~fish
pnpm install --frozen-lockfile
pnpm --filter tree-sitter-neon run generate
pnpm --filter tree-sitter-neon test
pnpm run build
pnpm test
pnpm run test:lsp
pnpm run test:release
cargo test --locked
cargo build --locked --release --target wasm32-wasip2
~~~

Local packaging can be inspected with pnpm run package:server. Output is written to the ignored dist/ directory. You can run node scripts/smoke-lsp.mjs --server-dir /absolute/path/to/extracted/neon-navigation against a downloaded package.

## Installation Checks

Before submitting a release, install the exact candidate commit as a dev extension in Zed and use the synthetic projects in examples/:

- Confirm .neon files select the NEON language and highlight comments, keys, strings, and literals.
- Go to Definition on an include path, a service reference, a PHP class, and a parameter.
- Confirm the server is downloaded into the extension's working directory and uses neon-navigation-VERSION/ rather than repository files.
- Restart the server and confirm the valid cache is reused. First installation requires internet; cached startup does not contact GitHub.
- Check that parameter hover explains origins without exposing values.

Download failures are shown through Zed's language-server installation status. Check connectivity and extension download permissions, then restart the language server. Syntax highlighting does not depend on the server. Only downloaded files within the extension working directory are replaced during cache repair; older versions are retained for rollback.

## Registry Submission

Follow the [Zed publishing prerequisites](https://zed.dev/docs/extensions/publishing/prerequisites) and [publishing guide](https://zed.dev/docs/extensions/publishing/publishing-guide).

The repository is public, uses the MIT license, and provides the NEON grammar at a pinned public revision. User-facing extension text is English. The server is downloaded through Zed's Rust API, not embedded into the extension WASM.

After the release and exact-commit Zed checks pass, submit one PR to zed-industries/extensions:

- Add https://github.com/bckp/zed-plugin-neon as the extensions/neon Git submodule, checked out at a tested commit present on main.
- Add this entry to extensions.toml, with the version matching extension.toml:

~~~toml
[neon]
submodule = "extensions/neon"
version = "0.1.0"
~~~

- Run pnpm sort-extensions in the registry repository.
- Include the tested Zed version, release URL, and CI link in the PR description.

This repository's release workflow does not create a registry PR or publish the extension to Zed automatically. Registry publication follows acceptance and merge of that PR.
