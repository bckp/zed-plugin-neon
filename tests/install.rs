#[path = "../src/install.rs"]
mod install;

use std::{
    fs,
    path::{Path, PathBuf},
    sync::atomic::{AtomicUsize, Ordering},
};

static NEXT: AtomicUsize = AtomicUsize::new(0);

struct Temp(PathBuf);
impl Temp {
    fn new() -> Self {
        let path = std::env::temp_dir().join(format!(
            "neon-cache-{}-{}",
            std::process::id(),
            NEXT.fetch_add(1, Ordering::Relaxed)
        ));
        fs::create_dir_all(&path).unwrap();
        Self(path)
    }
}
impl Drop for Temp {
    fn drop(&mut self) {
        let _ = fs::remove_dir_all(&self.0);
    }
}

fn fixture(dir: &Path, version: &str) -> Result<(), String> {
    let dir = dir.join("neon-navigation");
    let mut files = zed_extension_api::serde_json::Map::new();
    for name in install::REQUIRED_FILES {
        let file = dir.join(name);
        fs::create_dir_all(file.parent().unwrap()).unwrap();
        fs::write(file, b"test").unwrap();
        files.insert(
            (*name).into(),
            "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08".into(),
        );
    }
    fs::write(
        dir.join("manifest.json"),
        zed_extension_api::serde_json::json!({"version": version, "files": files}).to_string(),
    )
    .unwrap();
    Ok(())
}

#[test]
fn cold_install_and_offline_cache_reuse() {
    let temp = Temp::new();
    let first = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    assert_eq!(fs::read(first.join("neon-server.cjs")).unwrap(), b"test");
    let cached = install::ensure_server(&temp.0, "0.1.0", |_| {
        panic!("valid cache must not download")
    })
    .unwrap();
    assert_eq!(cached, first);
}

#[test]
fn corrupted_cache_is_replaced_with_verified_download() {
    let temp = Temp::new();
    let dir = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    fs::write(dir.join("assets/tree-sitter-neon.wasm"), "bad!").unwrap();
    let repaired = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    assert_eq!(
        fs::read(repaired.join("assets/tree-sitter-neon.wasm")).unwrap(),
        b"test"
    );
}

#[test]
fn interrupted_download_can_retry_without_poisoning_cache() {
    let temp = Temp::new();
    let failure = install::ensure_server(&temp.0, "0.1.0", |dir| {
        fs::create_dir_all(dir).unwrap();
        fs::write(dir.join("neon-server.cjs"), "partial").unwrap();
        Err("offline".into())
    })
    .unwrap_err();
    assert!(failure.contains("offline"));
    assert!(!temp.0.join("neon-navigation-0.1.0").exists());
    let installed = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    assert!(installed.join("manifest.json").is_file());
}

#[test]
fn invalid_release_is_not_promoted_to_cache() {
    let temp = Temp::new();
    let result = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "9.9.9"));
    assert!(result.is_err());
    assert!(!temp.0.join("neon-navigation-0.1.0").exists());
    let result = install::ensure_server(&temp.0, "0.1.0", |dir| {
        fixture(dir, "0.1.0")?;
        fs::remove_file(dir.join("neon-navigation/assets/tree-sitter-php.wasm")).unwrap();
        Ok(())
    });
    assert!(result.is_err());
}

#[test]
fn versions_have_separate_caches_and_failed_updates_keep_old_version() {
    let temp = Temp::new();
    let old = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    assert!(install::ensure_server(&temp.0, "0.2.0", |_| Err("offline".into())).is_err());
    assert!(old.join("neon-server.cjs").is_file());
    let new = install::ensure_server(&temp.0, "0.2.0", |dir| fixture(dir, "0.2.0")).unwrap();
    assert_ne!(old, new);
}

#[test]
fn regular_files_at_cache_and_staging_paths_are_repaired() {
    let temp = Temp::new();
    fs::write(temp.0.join("neon-navigation-0.1.0"), "broken cache").unwrap();
    fs::write(
        temp.0.join(".neon-navigation-0.1.0.download"),
        "broken staging",
    )
    .unwrap();
    let installed = install::ensure_server(&temp.0, "0.1.0", |dir| fixture(dir, "0.1.0")).unwrap();
    assert_eq!(
        fs::read(installed.join("neon-server.cjs")).unwrap(),
        b"test"
    );
}
