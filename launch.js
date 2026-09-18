#!/usr/bin/env node

const Cp = require('child_process')
const Fs = require('fs')
const Path = require('path')

const ROOT = __dirname
const DATA = Path.join(ROOT, '.data')
const EXTS = Path.join(ROOT, '.extensions')
const NODE_MODULES = Path.join(ROOT, 'node_modules')
const TOOLS = Path.join(ROOT, 'tools')

const EXTENSIONS = [
    'em-builder-26.3.0.202609150318',
    'Wokwi.wokwi-vscode@3.7.0',
    'ms-vscode.vscode-serial-monitor@0.13.1',
    'ms-vscode.cpptools-extension-pack@1.5.1',
    'squarewave.linker-script-syntax@1.1.0',
    'trond-snekvik.gnu-mapfiles@1.1.0',
]

const INTERNAL_RELEASE_URL =
    'https://github.com/em-foundation/npm-packages/releases/download/resources'

const VERBOSE = process.argv.includes('--verbose')
const REFRESH = process.argv.includes('--refresh')
const RESET = process.argv.includes('--reset')
const EMBUILDER = process.argv.includes('--embuilder')

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

    return new Set(
        txt
            .trim()
            .split(/\r?\n/)
            .filter(Boolean)
            .map(s => s.toLowerCase())
    )
}

function internalExtension(ext) {
    return /-\d+\.\d+\.\d+\.\d{12}$/.test(ext)
}

function internalStamp(ext) {
    return Path.join(DATA, `${ext.replace(/[^a-z0-9.-]/gi, '_')}.installed`)
}

function installInternalExtension(ext) {
    const stamp = internalStamp(ext)
    if (Fs.existsSync(stamp)) return

    const vsix = Path.join(DATA, `${ext}.vsix`)
    const url = `${INTERNAL_RELEASE_URL}/${ext}.vsix`

    const script = `
const Fs = require('fs')
const Https = require('https')

const url = process.argv[1]
const file = process.argv[2]

function get(uri) {
    Https.get(uri, res => {
        if (res.statusCode >= 300 && res.statusCode < 400 && res.headers.location) {
            get(res.headers.location)
            return
        }

        if (res.statusCode !== 200) {
            console.error(\`download failed: HTTP \${res.statusCode}\`)
            process.exit(1)
        }

        const out = Fs.createWriteStream(file)
        res.pipe(out)

        out.on('finish', () => out.close())
    }).on('error', err => {
        console.error(err.message)
        process.exit(1)
    })
}

get(url)
`

    const r = Cp.spawnSync(
        process.execPath,
        ['-e', script, url, vsix],
        {
            cwd: ROOT,
            shell: false,
            stdio: VERBOSE ? 'inherit' : 'ignore'
        }
    )

    if (r.error || r.status) {
        console.error(`couldn't download '${ext}'`)
        process.exit(r.status || 1)
    }

    run([
        'code',
        '--install-extension', vsix,
        '--extensions-dir', EXTS,
        '--force'
    ], !VERBOSE)

    Fs.writeFileSync(stamp, ext)
    Fs.rmSync(vsix, { force: true })
}

if (RESET) {
    console.log('EM•porium: removing old environment…')

    Fs.rmSync(DATA, { recursive: true, force: true })
    Fs.rmSync(EXTS, { recursive: true, force: true })
    Fs.rmSync(NODE_MODULES, { recursive: true, force: true })
    Fs.rmSync(TOOLS, { recursive: true, force: true })
}

Fs.mkdirSync(DATA, { recursive: true })
Fs.mkdirSync(EXTS, { recursive: true })

if (EMBUILDER) {
    const installed = installedExtensions()
    const embuilder = [...installed].find(ext =>
        ext.startsWith('the-em-foundation.em-builder@')
    )

    if (embuilder) {
        console.log('EM•porium: refreshing EM•Builder…')

        run([
            'code',
            '--uninstall-extension', 'the-em-foundation.em-builder',
            '--extensions-dir', EXTS
        ], !VERBOSE)
    }

    for (const name of Fs.readdirSync(DATA)) {
        if (name.startsWith('em-builder-') && name.endsWith('.installed'))
            Fs.rmSync(Path.join(DATA, name), { force: true })
    }
}

console.log('EM•porium: updating npm dependencies (this may take a while)…')
run(['npm', 'install', '--loglevel=error'], !VERBOSE)

const installed = (REFRESH || RESET) ? new Set() : installedExtensions()

const missing = EXTENSIONS.filter(ext => {
    if (internalExtension(ext)) {
        return REFRESH || RESET || !Fs.existsSync(internalStamp(ext))
    }

    return !installed.has(ext.toLowerCase())
})

if (missing.length) {
    console.log('EM•porium: configuring VS Code environment…')

    for (const ext of missing) {
        if (internalExtension(ext)) {
            installInternalExtension(ext)
            continue
        }

        run([
            'code',
            '--install-extension', ext,
            '--extensions-dir', EXTS,
            '--force'
        ], !VERBOSE)
    }
}

console.log('EM•porium: launching VS Code…')

run([
    'code',
    '--skip-welcome',
    '--user-data-dir', DATA,
    '--extensions-dir', EXTS,
    ROOT
])
