import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BoardC from '@rpi.distro.2040/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export const ButEdge = $delegate(BoardC.AppButEdge)
export const ButPin = $delegate(BoardC.AppButPin)

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('IO_IRQ_BANK0')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    IntrVec.NVIC_enable(e$`IO_IRQ_BANK0_IRQn`)
    ButEdge.init(false)
    ButEdge.setDetectFalling()
    ButEdge.enableDetect()
    Common.GlobalInterrupts.enable()
    printf`ready...\n`()
    while (true) {
        Common.Idle.exec()
    }
    Common.BusyWait.wait(10_000_000)
}

export function IO_IRQ_BANK0_isr$$() {
    $['%%a']
    printf`but = %d\n`(ButEdge.getState())
    ButEdge.clearDetect()
    IntrVec.NVIC_clear(e$`IO_IRQ_BANK0_IRQn`)
}
