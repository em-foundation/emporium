import * as Fs from 'fs'

import em from '../../em.core/em.lang/emscript'

const TYPE_SET = new Set<string>([
    'BURTC',
    'CMU',
    'DEVINFO',
    'DPLL',
    'EMU',
    'EUSART',
    'GPIO',
    'GPIO_PORT',
    'HFRCO',
    'HFXO',
    'RTCC',
    'TIMER',
    'USART',
])
const INSTS = [
    ['BURTC', 'BURTC'],
    ['CMU', 'CMU'],
    ['DEVINFO', 'DEVINFO'],
    ['DPLL0', 'DPLL'],
    ['EMU', 'EMU'],
    ['EUART0', 'EUSART'],
    ['GPIO', 'GPIO'],
    ['HFRCO0', 'HFRCO'],
    ['HFXO0', 'HFXO'],
    ['RTCC', 'RTCC'],
    ['TIMER0', 'TIMER'],
    ['USART0', 'USART'],
]

let meta = em.$outfile('REGS.em.ts')

let src_lines = new Array<string>()
let cur_idx = 0

function genConsts() {
    while (true) {
        const ln = nextLine()
        if (ln === null) break
        const m = ln.match(/^\s*\#define\s+(\w+)\s+(.+)$/)
        if (!m) break
        meta.print("export const %1: any = '%2'\n", m[1], m[2])
    }
}

function nextLine(): string | null {
    return cur_idx == src_lines.length ? null : src_lines[cur_idx++]
}

function scanConsts(): boolean {
    while (true) {
        const ln = nextLine()
        if (ln === null) break
        if (ln.startsWith('/* Bit fields')) return true
    }
    return false
}

function scanFields(): Array<[string, string, string]> {
    let res = new Array<[string, string, string]>()
    while (true) {
        const ln = nextLine()
        if (!ln) break
        if (ln.startsWith('}')) break
        if (ln.indexOf('RESERVED') != -1) continue
        const pre = ln.slice(0, ln.indexOf(';')).trimStart()
        let segs = pre.split(/\s+/)
        if (segs.length == 3) {
            segs.shift()
        }
        const ftype = (segs[0] == 'uint32_t') ? '$Reg' : segs[0].replace('_TypeDef', '_t')
        const m = segs[1].match(/^(\w+)(\[(\d+))?/)!
        const fname = m[1]
        const fdim = m[3] ?? ''
        res.push([fname, ftype, fdim])
    }
    return res
}

function scanStruct(): string | null {
    while (true) {
        const ln = nextLine()
        if (ln === null) return null
        const m = ln.match(/^typedef struct (\w+)_typedef/)
        if (!m) continue
        return m[1].toUpperCase()
    }
}

// -------- main -------- //

meta.addText(`import em from '@$$emscript'\n`)
meta.addText(`export const $U = em.$declare('COMPOSITE')\n`)
meta.addText(`
export function em$generate() {
    let out = $outfile('silabs.distro.efr32x/REGS.hpp')
    out.addFile('../silabs.efr32x/silabs.distro.efr32x/REGS.hpp.txt')
    out.close()
}
`)

for (const itype of TYPE_SET) {
    src_lines = Fs.readFileSync(`inc/efr32mg22_${itype.toLowerCase()}.h`, 'utf-8').split('\n')
    cur_idx = 0
    while (true) {
        const sname = scanStruct()
        if (!sname) break
        meta.genTitle(sname)
        meta.print('export interface %1_t {\n%+', sname)
        for (const [fname, ftype, fdim] of scanFields()) {
            if (fdim) {
                meta.print('%t%1: dim_t<%2, %3>\n', fname, ftype, fdim)

            } else {
                meta.print('%t%1: %2\n', fname, ftype)
            }
        }
        meta.print('%-}\n')
    }
    cur_idx = 0
    while (scanConsts()) {
        genConsts()
    }
}

meta.genTitle('INSTANCES')
for (const [iname, itype] of INSTS) {
    meta.print('export const %1 = {} as %2_t\n', iname, itype)
}

meta.close()