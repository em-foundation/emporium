#!/usr/bin/env node

const Cp = require('child_process')
const Fs = require('fs')
const Path = require('path')

const ROOT = __dirname
const DATA = Path.join(ROOT, '.data')
const EXTS = Path.join(ROOT, '.extensions')

const EXTENSIONS = [
    'the-em-foundation.em-builder@26.1.1',
    'Wokwi.wokwi-vscode@3.6.0'
]

const VERBOSE = process.argv.includes('--verbose')
const REFRESH = process.argv.includes('--refresh')

function run(cli, quiet = false) {
    if (VERBOSE) console.log(`> ${cli.join(' ')}`)
    const r = Cp.spawnSync(cli[0], cli.slice(1), {
        cwd: ROOT,
        shell: process.platform === 'win32',
        encoding: quiet ? 'utf8' : undefined,
        stdio: quiet ? undefined : 'inherit'
    })
    if (r.error) {
        console.error(`couldn't run '${cli[0]}': ${r.error.message}`)
        process.exit(1)
    }
    if (r.status) {
        if (quiet) console.error((r.stderr || r.stdout || '').trim())
        process.exit(r.status)
    }
    return quiet ? r.stdout ?? '' : ''
}

function installedExtensions() {
    const txt = run([
        'code',
        '--list-extensions',
        '--show-versions',
        '--extensions-dir', EXTS
    ], true)
    return new Set(txt.trim().split(/\r?\n/).filter(Boolean).map(s => s.toLowerCase()))
}

Fs.mkdirSync(DATA, { recursive: true })
Fs.mkdirSync(EXTS, { recursive: true })

const installed = REFRESH ? new Set() : installedExtensions()
const missing = EXTENSIONS.filter(ext => !installed.has(ext.toLowerCase()))

if (missing.length) {
    console.log('EM•porium: configuring VS Code environment…')
    for (const ext of missing) {
        run([
            'code',
            '--install-extension', ext,
            '--extensions-dir', EXTS,
            '--force'
        ], !VERBOSE)
    }
}

if (VERBOSE || missing.length) {
    console.log('EM•porium: launching VS Code…')
}

run([
    'code',
    '--skip-welcome',
    '--user-data-dir', DATA,
    '--extensions-dir', EXTS,
    ROOT
])
