#!/usr/bin/env node

const fs = require("fs");
const path = require("path");
const { spawnSync } = require("child_process");

const root = __dirname;
const dataDir = path.join(root, ".data");
const extensionsDir = path.join(root, ".extensions");

const code = "code";

fs.mkdirSync(dataDir, { recursive: true });
fs.mkdirSync(extensionsDir, { recursive: true });

function run(args) {
    console.log(`> code ${args.join(" ")}`);

    const result = spawnSync(code, args, {
        cwd: root,
        stdio: "inherit"
    });

    if (result.error) {
        console.error(result.error.message);
        process.exit(1);
    }

    if (result.status !== 0) {
        process.exit(result.status ?? 1);
    }
}

// Certified EM•Builder for this Emporium state.
run([
    "--install-extension",
    "the-em-foundation.em-builder@26.1.1",
    "--extensions-dir",
    extensionsDir,
    "--force"
]);

// External simulator dependency.
// We can pin an exact Wokwi version once we decide that policy.
run([
    "--install-extension",
    "Wokwi.wokwi-vscode",
    "--extensions-dir",
    extensionsDir
]);

// Launch this Emporium in its clone-local VS Code environment.
run([
    "--skip-welcome",
    "--user-data-dir",
    dataDir,
    "--extensions-dir",
    extensionsDir,
    root
]);
