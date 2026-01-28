import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BoardC from '@rpi.distro.2040/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export const AppButPin = $delegate(BoardC.AppButPin)

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('IO_IRQ_BANK0')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    IntrVec.NVIC_enable(e$`IO_IRQ_BANK0_IRQn`)
    AppButPin.makeInput()
    AppButPin.setInternalPulldown(true)
    const pid = AppButPin.pinId()
    Common.GlobalInterrupts.enable()
    $reg32[e$`IO_BANK0_PROC_INTE_get(pid)`] = $R.IO_BANK0_INTR3_GPIO28_EDGE_HIGH_Msk
    printf`waiting...\n`()
    while (!AppButPin.get()) {}
    printf`but = %d\n`(AppButPin.get())
}

export function IO_IRQ_BANK0_isr$$() {
    fail()
}
