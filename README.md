# NEON For Zed

NEON syntax highlighting and navigation for Nette configuration files.

## Features

- .neon file detection, comments, keys, strings, multiline strings, numbers, booleans, nulls, arrays, entities, and PHP namespaces.
- Bracket matching, quote scopes, and indentation after block mapping keys.
- Open relative paths in includes, including inline arrays and static NEON path parameters.
- Find incoming includes with Find All References on an include path. Hover shows the target and the files that include it.
- Go to Definition on @service references across connected configuration files.
- Go to Definition on PHP class names and @service::method() / Class::method() calls.
- Go to Definition on %parameter%, dotted paths such as %mail.host%, and array indices.
- Parameter references and hover with effective declarations and overridden origins per entry point.
- Composer PSR-4 lookup, including installed packages, with a workspace PHP class index as fallback.
- Unsaved NEON changes are reflected immediately. Include cycles are handled.

The language server provides navigation. Completion, formatting, schema validation, and diagnostics are not implemented.

## Install Locally

Clone the repository:

~~~fish
git clone https://github.com/bckp/zed-plugin-neon.git
cd zed-plugin-neon
~~~

1. In Zed, run zed: install dev extension.
2. Select the cloned zed-plugin-neon directory.
3. Open examples/demo/config.neon.
4. Use Go to Definition on Product/import-product.neon, @importer, or App\Service\ProductExporter.

The examples/parameters/ project demonstrates parameter navigation. Open dev.neon for a single winning declaration, or shared.neon for separate dev and prod candidates.

The grammar points to a pinned commit in the public GitHub repository, with path = "tree-sitter-neon". The source grammar lives outside Zed's generated grammars/ directory. Moving the checkout does not require changes to the manifest.

The navigation server and its parser assets are bundled into the Rust extension. The installed plugin needs no npm installation; it uses Node from the worktree or Zed's managed Node runtime.

Marketplace publication is in preparation. Before submission to the Zed registry, the bundled navigation server will be moved to a versioned downloadable release.

## Development

Install Rust through rustup. Zed uses the wasm32-wasip2 target and wasi-sdk for extension compilation.

~~~fish
pnpm install
rustup target add wasm32-wasip2
pnpm run build
pnpm test
pnpm run test:lsp
~~~

The build script finds wasi-sdk in Zed's extension cache. A different installation can be selected with WASI_SDK_PATH.

For grammar changes:

~~~fish
pnpm --filter tree-sitter-neon run generate
pnpm --filter tree-sitter-neon test
pnpm run build
~~~

Commit and push the generated grammar sources, then update [grammars.neon].rev in extension.toml to that commit before rebuilding the dev extension. Zed loads the pinned grammar revision rather than uncommitted local changes.

For offline grammar development, temporarily set [grammars.neon].repository to a file:// URL for your local checkout and rev to a committed local revision. Restore the public URL and pinned commit before publishing.

Rebuild the extension in Zed after changing server code or bundled assets.

## Navigation Details

Include paths are relative to the file that contains them. Static values from parameters in connected configs can expand %name%. %rootDir% is the workspace root; %appDir% is available when a workspace app/ directory exists.

Parameters follow ordered recursive includes: later includes take priority, then the containing file is applied. Named array keys merge recursively, numeric items append, and a trailing ! replaces inherited content. Parameter aliases, inline structures, and unsaved edits are supported.

Entry points are inferred from files with no incoming include. A shared file can have different winning declarations for different entry points; Go to Definition returns those candidates rather than choosing an environment. Hover lists the entry points, effective origins, and overwritten declarations without displaying parameter values. Find All References omits comments and escaped %% placeholders.

This is a static NEON model, not runtime container evaluation. Bootstrap addConfig() ordering, externally supplied parameters, PHP configuration includes, and dynamic values are not inferred. Unresolved or cyclic includes are marked as partial in parameter hover. A parameterized include is linked only when the inferred contexts agree on its path.

Service names are resolved within the connected include graph. Unrelated configuration files do not share service declarations. A service declaration can point at an entity, a PHP class, a factory / class / type entry, or another service.

PHP declarations are read with Tree-sitter, never executed. Dynamic PHP factories, environment-dependent paths, runtime DI extensions, and inherited method lookup are outside this version's static navigation.

The highlighting grammar is deliberately permissive. Block nesting is reconstructed from indentation for navigation. It does not implement strict NEON validation.

## Layout

- languages/neon/: Zed language config and queries.
- tree-sitter-neon/: grammar, generated C parser, and corpus tests.
- server/src/: navigation language server.
- server/assets/ and server/dist/: bundled runtime assets.
- src/lib.rs: Zed language server launcher.
- examples/demo/: self-contained Nette-style navigation example.
- examples/parameters/: ordered overrides and shared dev/prod parameter example.

## References

- [NEON](https://github.com/nette/neon)
- [Nette parameter and include merging](https://doc.nette.org/en/dependency-injection/configuration)
- [Zed language extensions](https://zed.dev/docs/extensions/languages)
- [Developing Zed extensions](https://zed.dev/docs/extensions/developing-extensions)

## License

MIT. Bundled dependency notices are in server/dist/neon-server.cjs.LEGAL.txt and THIRD_PARTY_NOTICES.md.
