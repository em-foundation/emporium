import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as IntrVec from '@em.arch.arc/IntrVec.em'

export namespace em$meta {
    // IntrVec.em$meta.useIntr('SWI')
}

//>> ---- em$targ ---- <<//

var zero: volatile_t<u32> = 0

export function em$run() {
    // let ivec: ptr_t<u32> = e$`_lr(INT_VECTOR_BASE)`
    // printf`ivec = %08x\n`(ivec)
    // for (const i of $range(4)) {
    //     printf`v[%d] = %06x\n`(i, ivec[i])
    // }

    // const val = $reg32[1000]
    // printf`val = %08x\n`(val)

    // const val = 100 / zero
    // printf`val = %d\n`(val)

    // e$`asm("swi")`

    const stat32: u32 = e$`_lr(STATUS32)`
    printf`stat32 = %08x\n`(stat32)
    const ctrl: u32 = e$`_lr(AUX_IRQ_CONTROL)`
    printf`ctrl = %08x\n`(ctrl)
}

export function SWI_isr$$() {
    fail()
}