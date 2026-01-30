import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arc/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('ARC_TIMER_1')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    e$`_sr(24_000_000, REG_LIMIT1)`
    e$`_sr(0x1, REG_CONTROL1)`
    e$`_sr(0, REG_COUNT1)`
    Common.GlobalInterrupts.enable()
    $['%%a+']
    Common.Idle.exec()
}

export function ARC_TIMER_1_isr$$() {
    e$`_sr(0x0, REG_CONTROL1)`
    $['%%a-']
}