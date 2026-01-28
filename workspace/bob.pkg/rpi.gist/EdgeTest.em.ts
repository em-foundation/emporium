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
    $reg32[e$`IO_BANK0_PROC_INTE_get(pid)`] = $R.IO_BANK0_INTR3_GPIO28_EDGE_HIGH_Msk
    Common.GlobalInterrupts.enable()
    printf`ready...\n`()
    Common.BusyWait.wait(10_000_000)
}

export function IO_IRQ_BANK0_isr$$() {
    $['%%a']
    printf`pressed\n`()
    const pid = AppButPin.pinId()
    $reg32[e$`IO_BANK0_INTR_get(pid)`] = $R.IO_BANK0_INTR3_GPIO28_EDGE_HIGH_Msk
    IntrVec.NVIC_clear(e$`IO_IRQ_BANK0_IRQn`)
}
