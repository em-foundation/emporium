import * as Path from 'path'
import * as Fs from 'fs'

import em from '../../em.core/em.lang/emscript'

const base_names = Array.from(
    Fs.readFileSync('inc/hw_memmap.h', 'utf-8').matchAll(/^#define\s+(\w+)_BASE\s+0x[\da-f]+U?\b/gim),
    m => m[1]
)

let meta = em.$outfile('REGS.em.ts')
let targ = em.$outfile('REGS.hpp.txt')

meta.addText(`import '@$$emscript'\n`)
meta.addText(`export const $U = $declare('COMPOSITE')\n`)
meta.addText(`
export function em$generate() {
    let out = $outfile('ti.distro.cc27xx/REGS.hpp')
    out.addFile('../ti.cc27xx/ti.distro.cc27xx/REGS.hpp.txt')
    out.close()
}
`)

targ.addText('#ifndef __REGS_M\n')
targ.addText('#define __REGS_M\n\n')
targ.addText('#include "../../ti.cc27xx/ti.distro.cc27xx/inc/cc27xx.h"\n')

targ.addText('#include "../../ti.cc27xx/ti.distro.cc27xx/driverlib/hapi.h"\n')
targ.addText('#include "../../ti.cc27xx/ti.distro.cc27xx/inc/hw_memmap.h"\n\n')

for (const file of Fs.readdirSync('./inc').sort()) {
    targ.addText(`#include "../../ti.cc27xx/ti.distro.cc27xx/inc/${file}"\n`)
    let in_type = false
    let tname = ''
    const src_lines = Fs.readFileSync(`inc/${file}`, 'utf-8').split('\n')
    for (const ln of src_lines) {
        const m = ln.match(/^#define (\w+)\s+(\w+)/)
        if (m == null) continue
        let segs = m[1].split('_O_')
        if (segs.length < 2) {
            if (in_type) {
                in_type = false
                meta.print('%-}\n')
            }
            continue
        }
        if (!in_type) {
            in_type = true
            tname = segs[0]
            meta.genTitle(`${tname} TYPE`)
            meta.print('export interface %1_t {\n%+', segs[0])
        }
        meta.print('%t%1: $Reg // offset %2\n', segs[1], m[2])
    }
    for (const ln of src_lines) {
        const m = ln.match(/^#define (\w+)\s+(\w+)/)
        if (m == null) continue
        meta.print("export const %1: any = '%2'\n", m[1], m[2])
    }
    if (!tname) continue
    meta.genTitle(`${tname} INSTANCES`)
    for (const name of base_names) {
        if (name === tname || name.replace(/\d+$/, '') === tname) {
            meta.print('export const %1 = { } as %2_t\n', name, tname)
        }
    }
}
targ.addText('\n// Use CMSIS core register bases after all TI peripheral headers.\n')
for (const name of ['SCB_BASE', 'NVIC_BASE', 'MPU_BASE', 'DCB_BASE', 'DIB_BASE']) {
    targ.addText(`#undef ${name}\n`)
}
targ.addText('#include "../../em.core/em.arch.arm/inc/core_cm33.h"\n')
targ.addText('static_assert(SCB_BASE + offsetof(SCB_Type, VTOR) == 0xE000ED08UL, "Invalid CMSIS VTOR address");\n')
targ.addText('static_assert(SCB_BASE + offsetof(SCB_Type, SCR) == 0xE000ED10UL, "Invalid CMSIS SCR address");\n')
targ.addText('\n#endif\n')
meta.close()
targ.close()
