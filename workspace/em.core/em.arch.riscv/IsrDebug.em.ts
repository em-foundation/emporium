import '@$$emscript'
export const $U = $declare('MODULE', IsrI)

import * as CSR from '@em.arch.riscv/CSR.em'
import * as IsrI from '@em.hal/IsrI.em'

//>> ---- em$targ ---- <<//

export function exec() {
    $['%%b:'](3)
    $['%%>'](CSR.read(CSR.MCAUSE))
    $['%%>'](CSR.read(CSR.MEPC))
    $['%%>'](CSR.read(CSR.MTVAL))
    $['%%>'](CSR.read(CSR.MSTATUS))
    const fp = <u32>e$`({ uint32_t v; asm volatile ("mv %0, s0" : "=r"(v)); v; })`
    const ra = <u32>e$`({ uint32_t v; asm volatile ("mv %0, ra" : "=r"(v)); v; })`
    let sp = <ptr_t<u32>>e$`({ uint32_t v; asm volatile ("mv %0, sp" : "=r"(v)); v; })`
    $['%%>'](sp)
    $['%%>'](fp)
    $['%%>'](ra)
    for (const _ of $range(8)) {
        $['%%b']
        $['%%>'](sp.$$)
        sp.$inc()
    }
}
