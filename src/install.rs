use sha2::{Digest, Sha256};
use std::{
    fs,
    path::{Path, PathBuf},
};
use zed_extension_api::serde_json;

fn remove_installation(path: &Path) -> Result<(), String> {
    match fs::symlink_metadata(path) {
        Ok(metadata) if metadata.is_dir() => fs::remove_dir_all(path),
        Ok(_) => fs::remove_file(path),
        Err(error) if error.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(error) => return Err(error.to_string()),
    }
    .map_err(|error| error.to_string())
}

pub const REQUIRED_FILES: &[&str] = &[
    "neon-server.cjs",
    "neon-server.cjs.LEGAL.txt",
    "assets/tree-sitter.wasm",
    "assets/tree-sitter-neon.wasm",
    "assets/tree-sitter-php.wasm",
    "LICENSE",
    "THIRD_PARTY_NOTICES.md",
    "licenses/tree-sitter.txt",
    "licenses/tree-sitter-php.txt",
    "licenses/tree-sitter-wasms.txt",
    "licenses/vscode-languageserver.txt",
    "licenses/fast-glob.txt",
];

fn validate(dir: &Path, version: &str) -> Result<(), String> {
    let bytes = fs::read(dir.join("manifest.json")).map_err(|e| e.to_string())?;
    let manifest: serde_json::Value = serde_json::from_slice(&bytes).map_err(|e| e.to_string())?;
    if manifest["version"].as_str() != Some(version) {
        return Err("The navigation server version does not match the extension.".into());
    }
    for file in REQUIRED_FILES {
        let bytes =
            fs::read(dir.join(file)).map_err(|e| format!("Missing server file {file}: {e}"))?;
        let digest = format!("{:x}", Sha256::digest(&bytes));
        if bytes.is_empty() || manifest["files"][file].as_str() != Some(digest.as_str()) {
            return Err(format!(
                "The navigation server file {file} failed its integrity check."
            ));
        }
    }
    Ok(())
}

pub fn ensure_server(
    root: &Path,
    version: &str,
    download: impl FnOnce(&Path) -> Result<(), String>,
) -> Result<PathBuf, String> {
    let cache = root.join(format!("neon-navigation-{version}"));
    if validate(&cache, version).is_ok() {
        return Ok(cache);
    }
    let staging = root.join(format!(".neon-navigation-{version}.download"));
    remove_installation(&staging)?;
    fs::create_dir_all(&staging).map_err(|e| e.to_string())?;
    download(&staging)?;
    let bundle = staging.join("neon-navigation");
    validate(&bundle, version)?;
    // Only promote a complete download; an interrupted install is retried next time.
    remove_installation(&cache)?;
    fs::rename(&bundle, &cache).map_err(|e| e.to_string())?;
    fs::remove_dir(&staging).map_err(|e| e.to_string())?;
    Ok(cache)
}
