import * as Fs from 'fs'
import * as Path from 'path'

function main() {
    const [, , vcdFile, nNsStr] = process.argv
    if (!vcdFile || !nNsStr) throw new Error('Usage: node scale-vcd.js <vcd_file> <n_ns>')

    const n = Number(nNsStr)
    if (!Number.isFinite(n) || n <= 0 || Math.floor(n) !== n) throw new Error('n_ns must be a positive integer')

    const input = Fs.readFileSync(vcdFile, 'utf8')

    // Replace $timescale 1ns $end -> $timescale <n>ns $end
    let out = input.replace(/^\$timescale\s+1ns\s+\$end\s*$/m, `$timescale ${n}ns $end`)

    // Scale timestamps: #t -> #(t / n)   (integer truncation)
    out = out.replace(/^#(\d+)\s*$/gm, (_line, tStr: string) => `#${Math.floor(Number(tStr) / n)}`)

    const p = Path.parse(vcdFile)
    const outFile = Path.join(p.dir, `${p.name}.${n}ns${p.ext}`)
    Fs.writeFileSync(outFile, out, 'utf8')
    console.log(outFile)
}

main()
