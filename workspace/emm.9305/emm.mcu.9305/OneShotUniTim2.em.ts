import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as $R from '@emm.distro.9305/REGS.em'

import * as Idle from '@emm.mcu.9305/Idle.em'
import * as IntrVec from '@em.arch.arc/IntrVec.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export type Handler = OneShotI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('UNIVERSAL_TIMER_2')
    }
}

//>> ---- em$targ ---- <<//

let cur_arg: arg_t = 0
let cur_fxn: Handler = $null

export function disable(): void {
    $R.UTIM.RegUniTimer2Ctrl.$$ = 0
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
    $R.IRQ.RegIRQUniTimEnSet.$$ = $R.IRQ_UT2_FULL_VAL_EN_SET_MASK
    $R.IRQ.RegIRQUniTimMskSet.$$ = $R.IRQ_UT2_FULL_VAL_MSK_SET_MASK
    $R.UTIM.RegUniTimer2Cfg.$$ = 5
    $R.UTIM.RegUniTimer2Ctrl.$$ = $R.UT2_CLEAR_MASK
    $R.UTIM.RegUniTimer2Limit.$$ = (usecs * 3) / 4
    $R.UTIM.RegUniTimer2Ctrl.$$ = ($R.UT2_ENABLE_MASK | $R.UT2_START_SW_MASK)
}

export function UNIVERSAL_TIMER_2_isr$$() {
    $R.IRQ.RegIRQUniTimStsClr.$$ = $R.IRQ_UT2_FULL_VAL_STS_CLR_MASK
    let fxn = cur_fxn
    disable()
    fxn(cur_arg)
}
