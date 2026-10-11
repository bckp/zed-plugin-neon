# tree-sitter-neon

Tree-sitter grammar for [NEON](https://github.com/nette/neon), the configuration format used by Nette.

This grammar is intentionally permissive. It prioritizes stable editor highlighting while users are editing over strict NEON validation.

## Development

```sh
pnpm install
pnpm run generate
pnpm test
```

Generated parser sources are committed under `src/` so editor integrations can compile the grammar directly.

## License

MIT
