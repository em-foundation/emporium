import * as Fs from 'fs'

import em from '../../em.core/em.lang/emscript'

const PERI_MAP = new Map<string, string>([
    ['GPIO', 'GPIO'],
    ['IRQ', 'IRQ'],
    ['PML', 'PML'],
    ['SYS', 'System'],
    ['UART', 'UART'],
    ['UTIM', 'UNI_TIM']
])

let meta = em.$outfile('REGS.em.ts')

let src_lines = new Array<string>()
let cur_idx = 0

function genConsts() {
    while (true) {
        const ln = nextLine()
        if (ln === null) break
        if (ln.startsWith('/')) break
        const segs = ln.split(/\s+/)
        if (segs.length < 3) continue
        if (segs[1].indexOf('(') != -1) continue
        meta.print("export const %1: any = '%2'\n", segs[1], segs[2])
    }
}

function mkOff(n: number): string {
    return n.toString(16).padStart(2, '0')
}

function nextLine(): string | null {
    return cur_idx == src_lines.length ? null : src_lines[cur_idx++]
}

function scanConsts(): boolean {
    while (true) {
        const ln = nextLine()
        if (ln === null) break
        const m = ln.match(/^\/\/\s(\w+)\.r32$/)
        if (!m) continue
        meta.print("// REGISTER %1\n", m[1])
        return true
    }
    return false
}

function scanFields(): Array<string> {
    let res = new Array<string>
    while (true) {
        const ln = nextLine()
        if (!ln) break
        if (ln.startsWith('}')) break
        const pre = ln.slice(0, ln.indexOf(';')).trimStart()
        let segs = pre.split(/\s+/)
        res.push(segs[2])
    }
    return res
}

function scanStruct(): boolean {
    while (true) {
        const ln = nextLine()
        if (ln === null) return false
        if (ln != 'typedef struct') continue
        const ln2 = nextLine()
        return (ln2 == '{')
    }
}

// -------- main -------- //

meta.addText(`import em from '@$$emscript'\n`)
meta.addText(`export const $U = em.$declare('COMPOSITE')\n`)
meta.addText(`
export function em$generate() {
    let out = $outfile('emm.distro.9305/REGS.hpp')
    out.addFile('../emm.9305/emm.distro.9305/REGS.hpp.txt')
    out.close()
}
`)

for (const pt of PERI_MAP.values()) {
    src_lines = Fs.readFileSync(`inc/t9305_${pt.toLowerCase()}.h`, 'utf-8').split('\n')
    cur_idx = 0
    if (!scanStruct()) break
    meta.genTitle(`${pt} TYPE`)
    meta.print('export interface %1_t {\n%+', pt)
    let off = 0
    for (const fld of scanFields()) {
        const sp = ' '.repeat(30 - fld.length)
        const os = off
        meta.print('%t%1: $Reg%2// 0x%3\n', fld, sp, mkOff(off))
        off += 4
    }
    meta.print('%-}\n')
    cur_idx = 0
    meta.genTitle(`${pt} CONSTANTS`)
    while (scanConsts()) {
        genConsts()
    }
}
meta.genTitle('INSTANCES')
for (const [pn, pt] of PERI_MAP) {
    meta.print('export const %1 = {} as %2_t\n', pn, pt)
}
meta.close()