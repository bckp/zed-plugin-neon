# NEON For Zed 0.1.0

Initial NEON language support for Zed:

- File detection, Tree-sitter highlighting, brackets, and basic indentation.
- Navigation through includes, services, PHP classes and methods, and parameters.
- Ordered parameter overrides, include references, and hover provenance.
- A local Node.js language server distributed through GitHub Releases.
- Versioned, integrity-checked server cache with offline reuse and interrupted-download recovery.

The navigation server package works across platforms supported by Zed. It contains bundled JavaScript, WebAssembly parsers, and third-party licenses; no PHP or npm installation is required.

Navigation is static. Runtime PHP configuration, completion, formatting, semantic diagnostics, and schema validation are not included.

Install the extension as a Zed dev extension from the repository until it is accepted into the Zed extension registry.
