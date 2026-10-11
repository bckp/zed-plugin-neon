mod install;

use std::path::Path;
use zed_extension_api::{self as zed, Command, LanguageServerId, Result, Worktree};

const SERVER_VERSION: &str = env!("CARGO_PKG_VERSION");
struct NeonExtension;

impl zed::Extension for NeonExtension {
    fn new() -> Self {
        Self
    }

    fn language_server_command(
        &mut self,
        id: &LanguageServerId,
        worktree: &Worktree,
    ) -> Result<Command> {
        let server = install::ensure_server(Path::new("."), SERVER_VERSION, |staging| {
            zed::set_language_server_installation_status(
                id,
                &zed::LanguageServerInstallationStatus::Downloading,
            );
            let url = format!("https://github.com/bckp/zed-plugin-neon/releases/download/v{SERVER_VERSION}/neon-navigation-{SERVER_VERSION}.tar.gz");
            zed::download_file(&url, &staging.to_string_lossy(), zed::DownloadedFileType::GzipTar)
                .map_err(|e| format!("Could not download NEON Navigation {SERVER_VERSION}. Check your connection and extension download permissions, then restart the language server: {e}"))
        });
        let server = match server {
            Ok(server) => server,
            Err(error) => {
                zed::set_language_server_installation_status(
                    id,
                    &zed::LanguageServerInstallationStatus::Failed(error.clone()),
                );
                return Err(error);
            }
        };
        zed::set_language_server_installation_status(
            id,
            &zed::LanguageServerInstallationStatus::None,
        );
        let server = std::env::current_dir()
            .map_err(|e| e.to_string())?
            .join(server);
        let node = match worktree.which("node") {
            Some(node) => node,
            None => zed::node_binary_path()?,
        };
        Ok(Command {
            command: node,
            args: vec![
                server
                    .join("neon-server.cjs")
                    .to_string_lossy()
                    .into_owned(),
                "--stdio".into(),
                "--assets-dir".into(),
                server.join("assets").to_string_lossy().into_owned(),
            ],
            env: vec![],
        })
    }
}

zed::register_extension!(NeonExtension);
