import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as Idle from '@emm.mcu.9305/Idle.em'
import * as IntrVec from '@em.arch.arc/IntrVec.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export type Handler = OneShotI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('ARC_TIMER_1')
    }
}

//>> ---- em$targ ---- <<//

let cur_arg: arg_t = 0
let cur_fxn: Handler = $null

export function disable(): void {
    e$`_sr(0x0, REG_CONTROL1)`
    cur_fxn = $null
    Idle.setPauseOnly(false)
}

export function enable(msecs: u32, handler: Handler, arg: arg_t): void {
    uenable(msecs * 1000, handler, arg)
}

export function uenable(usecs: u32, handler: Handler, arg: arg_t): void {
    cur_fxn = handler
    cur_arg = arg
    Idle.setPauseOnly(true)
    const limit = usecs * 48
    e$`_sr(limit, REG_LIMIT1)`
    e$`_sr(0x1, REG_CONTROL1)`
    e$`_sr(0, REG_COUNT1)`
}

export function ARC_TIMER_1_isr$$() {
    let fxn = cur_fxn
    disable()
    fxn(cur_arg)
}
