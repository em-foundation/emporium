#!/usr/bin/env node

const Cp = require('child_process')
const Fs = require('fs')
const Path = require('path')

const ROOT = __dirname
const DATA = Path.join(ROOT, '.data')
const EXTS = Path.join(ROOT, '.extensions')

const EXT_BUILDER = 'the-em-foundation.em-builder@26.1.1'
const EXT_WOKWI = 'Wokwi.wokwi-vscode'

function run(cli) {
    console.log(`> ${cli.join(' ')}`)
    const r = Cp.spawnSync(cli[0], cli.slice(1), {
        cwd: ROOT,
        shell: process.platform === 'win32',
        stdio: 'inherit'
    })
    if (r.error) {
        console.error(`couldn't run '${cli[0]}': ${r.error.message}`)
        process.exit(1)
    }
    if (r.status) process.exit(r.status)
}

Fs.mkdirSync(DATA, { recursive: true })
Fs.mkdirSync(EXTS, { recursive: true })

run([
    'code',
    '--install-extension', EXT_BUILDER,
    '--extensions-dir', EXTS,
    '--force'
])

run([
    'code',
    '--install-extension', EXT_WOKWI,
    '--extensions-dir', EXTS
])

run([
    'code',
    '--skip-welcome',
    '--user-data-dir', DATA,
    '--extensions-dir', EXTS,
    ROOT
])
