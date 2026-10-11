use std::{fs, path::Path};
use zed_extension_api::{self as zed, Command, LanguageServerId, Result, Worktree};

struct NeonExtension;

impl zed::Extension for NeonExtension {
    fn new() -> Self {
        Self
    }

    fn language_server_command(
        &mut self,
        _id: &LanguageServerId,
        worktree: &Worktree,
    ) -> Result<Command> {
        fs::create_dir_all("assets").map_err(|e| e.to_string())?;
        for (name, bytes) in [
            ("assets/tree-sitter.wasm", include_bytes!("../server/assets/tree-sitter.wasm").as_slice()),
            ("assets/tree-sitter-neon.wasm", include_bytes!("../server/assets/tree-sitter-neon.wasm").as_slice()),
            ("assets/tree-sitter-php.wasm", include_bytes!("../server/assets/tree-sitter-php.wasm").as_slice()),
            ("neon-server.cjs", include_bytes!("../server/dist/neon-server.cjs").as_slice()),
            ("neon-server.cjs.LEGAL.txt", include_bytes!("../server/dist/neon-server.cjs.LEGAL.txt").as_slice()),
        ] {
            if fs::read(name).ok().as_deref() != Some(bytes) {
                fs::write(name, bytes).map_err(|e| e.to_string())?;
            }
        }
        let cwd = std::env::current_dir().map_err(|e| e.to_string())?;
        let node = match worktree.which("node") {
            Some(node) => node,
            None => zed::node_binary_path()?,
        };
        Ok(Command {
            command: node,
            args: vec![
                cwd.join(Path::new("neon-server.cjs")).to_string_lossy().into_owned(),
                "--stdio".to_string(),
                "--assets-dir".to_string(),
                cwd.join("assets").to_string_lossy().into_owned(),
            ],
            env: vec![],
        })
    }
}

zed::register_extension!(NeonExtension);
