# NEON For Zed

NEON syntax highlighting and navigation for Nette configuration files.

## Features

- .neon file detection, comments, keys, strings, multiline strings, numbers, booleans, nulls, arrays, entities, and PHP namespaces.
- Bracket matching, quote scopes, and indentation after block mapping keys.
- Open relative paths in includes, including inline arrays and static NEON path parameters.
- Find incoming includes with Find All References on an include path. Hover shows the target and the files that include it.
- Go to Definition on @service references across connected configuration files.
- Go to Definition on PHP class names and @service::method() / Class::method() calls.
- Composer PSR-4 lookup, including installed packages, with a workspace PHP class index as fallback.
- Unsaved NEON changes are reflected immediately. Include cycles are handled.

The language server provides navigation. Completion, formatting, schema validation, and diagnostics are not implemented.

## Install Locally

This checkout is configured for /Users/bckp/Projects/vibecode/zed-plugin-neon.

1. In Zed, run zed: install dev extension.
2. Select this directory.
3. Open examples/demo/config.neon.
4. Use Go to Definition on Product/import-product.neon, @importer, or App\Service\ProductExporter.

The grammar points to this local Git repository, branch main, with path = "tree-sitter-neon". The source grammar lives outside Zed's generated grammars/ directory. The branch must have a commit before installing.

The navigation server and its parser assets are bundled into the Rust extension. The installed plugin needs no npm installation; it uses Node from the worktree or Zed's managed Node runtime.

If the checkout moves, update [grammars.neon].repository in extension.toml to its new file:// URL and reinstall the dev extension.

## Development

Install Rust through rustup. Zed uses the wasm32-wasip2 target and wasi-sdk for extension compilation.

~~~fish
pnpm install
rustup target add wasm32-wasip2
pnpm run build
pnpm test
~~~

The build script finds wasi-sdk in Zed's extension cache. A different installation can be selected with WASI_SDK_PATH.

For grammar changes:

~~~fish
pnpm --dir tree-sitter-neon run generate
pnpm --dir tree-sitter-neon test
pnpm run build
~~~

Commit the generated grammar sources before rebuilding the dev extension, because Zed checks out the committed main revision. Rebuild the extension in Zed after changing server code or bundled assets.

## Navigation Details

Include paths are relative to the file that contains them. Static values from parameters in connected configs can expand %name%. %rootDir% is the workspace root; %appDir% is available when a workspace app/ directory exists.

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

## References

- [NEON](https://github.com/nette/neon)
- [Zed language extensions](https://zed.dev/docs/extensions/languages)
- [Developing Zed extensions](https://zed.dev/docs/extensions/developing-extensions)

## License

MIT. Bundled dependency notices are in server/dist/neon-server.cjs.LEGAL.txt and THIRD_PARTY_NOTICES.md.
