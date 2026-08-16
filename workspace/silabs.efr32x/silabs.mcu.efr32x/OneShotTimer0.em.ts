import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as Idle from '@silabs.mcu.efr32x/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export type Handler = OneShotI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('TIMER0')
    }
}

//>> ---- em$targ ---- <<//

var cur_arg: arg_t
var cur_fxn: Handler = $null

export function em$startup() {
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_TIMER0
}

export function disable(): void {
    $R.TIMER0.EN_CLR.$$ = 1
    Idle.setPauseOnly(false)
    IntrVec.NVIC_disable(e$`TIMER0_IRQn`)
}

export function enable(msecs: u32, handler: OneShotI.Handler, arg: arg_t): void {
    ustart(msecs * 1000, handler, arg)
}

export function uenable(usecs: u32, handler: OneShotI.Handler, arg: arg_t): void {
    ustart(usecs, handler, arg)
}

function ustart(usecs: u32, handler: OneShotI.Handler, arg: arg_t) {
    cur_fxn = handler
    cur_arg = arg
    Idle.setPauseOnly(true)
    $R.TIMER0.EN_CLR.$$ = 1
    const pre = 20 << $R._TIMER_CFG_PRESC_SHIFT
    $R.TIMER0.CFG_SET.$$ = pre | $R.TIMER_CFG_OSMEN | $R.TIMER_CFG_MODE_DOWN
    $R.TIMER0.EN_SET.$$ = 1
    $R.TIMER0.TOP.$$ = $R.TIMER0.CNT.$$ = usecs
    $R.TIMER0.IEN_SET.$$ = $R.TIMER_IEN_UF
    IntrVec.NVIC_enable(e$`TIMER0_IRQn`)
    $R.TIMER0.CMD.$$ = $R.TIMER_CMD_START
}

export function TIMER0_isr$$() {
    $R.TIMER0.IF_CLR.$$ = $R.TIMER_IF_UF
    const fxn = cur_fxn
    disable()
    fxn(cur_arg)
}
