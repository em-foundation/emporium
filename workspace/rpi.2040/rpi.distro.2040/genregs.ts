import * as Fs from 'fs'

import em from '../../em.core/em.lang/emscript'

const PERI_MAP = new Map<string, string>([
    ['IO_BANK0', 'IO_BANK0'],
    ['PADS_BANK0', 'PADS_BANK0'],
    ['RESETS', 'RESETS'],
    ['SIO', 'SIO'],
    ['UART0', 'UART0'],
    ['XIP_CTRL', 'XIP_CTRL'],
])

let meta = em.$outfile('REGS.em.ts')

let src_lines = new Array<string>()
let cur_idx = 0

function nextLine(): string | null {
    return cur_idx == src_lines.length ? null : src_lines[cur_idx++]
}

function scanConsts(pt: string): Array<[string, string]> {
    let res = new Array<[string, string]>()
    const pre = `${pt}_`
    while (true) {
        const ln = nextLine()
        if (ln === null) break
        const mA = ln.match(/^#define (\w+)(.+)$/)
        if (mA) {
            if (!mA[1].startsWith(pre)) continue
            if (mA[1].match(/(CLR|SET|XOR)$/)) continue
            res.push([mA[1], mA[2].trimStart()])
            continue
        }
        const mB = ln.match(/^  (\w+)\s+= (\d+),/)
        if (mB) {
            if (!mB[1].startsWith(pre)) continue
            res.push([mB[1], mB[2].trimStart()])
            continue
        }
    }
    return res
}

function scanFields(): Array<[string, string]> {
    let res = new Array<[string, string]>()
    while (true) {
        const ln = nextLine()!
        if (ln.startsWith('}')) break
        if (!ln.startsWith('  union {')) continue
        const ln2 = nextLine()!
        const k = ln2.indexOf(';')
        const segs = ln2.slice(0, k).trimStart().split(' ')
        const cmt = ln2.slice(k + 1).trim()        
        res.push([segs[2], cmt]) 
    }
    return res
}

function scanStruct(pt: string): string | null {
    while (true) {
        const ln = nextLine()
        if (ln === null) return null
        if (!ln.startsWith('typedef struct')) continue
        const segs = ln.split(/\s+/)
        if (segs[6] == pt) return segs[5].slice(0, 10)
    }
}

// -------- main -------- //

meta.addText(`import em from '@$$emscript'\n`)
meta.addText(`export const $U = em.$declare('COMPOSITE')\n`)
meta.addText(`
export function em$generate() {
    let out = $outfile('rpi.distro.2040/REGS.hpp')
    out.addFile('../rpi.2040/rpi.distro.2040/REGS.hpp.txt')
    out.close()
}
`)

src_lines = Fs.readFileSync(`inc/rp2040.h`, 'utf-8').split('\n')

for (const pt of PERI_MAP.values()) {
    cur_idx = 0
    const pa = scanStruct(pt)
    if (pa === null) continue
    meta.genTitle(`${pt} TYPE`)
    meta.print('export interface %1_t {  // @ %2\n%+', pt, pa)
    for (const [fld, cmt] of scanFields()) {
        const sp = ' '.repeat(30 - fld.length)
        meta.print('%t%1: $Reg%2// %3\n', fld, sp, cmt)
    }
    meta.print('%-}\n')
    meta.genTitle(`${pt} CONSTANTS`)
    for (const [cn, cv] of scanConsts(pt)) {
        meta.print("export const %1: any = '%2'\n", cn, cv)
    }
}
meta.genTitle('INSTANCES')
for (const [pn, pt] of PERI_MAP) {
    meta.print('export const %1 = {} as %2_t\n', pn, pt)
    meta.print('export const %1_CLR = {} as %2_t\n', pn, pt)
    meta.print('export const %1_SET = {} as %2_t\n', pn, pt)
    meta.print('export const %1_XOR = {} as %2_t\n', pn, pt)
}
meta.close()