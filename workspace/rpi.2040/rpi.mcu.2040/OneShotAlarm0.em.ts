import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as $R from '@rpi.distro.2040/REGS.em'

import * as Idle from '@rpi.mcu.2040/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as OneShotI from '@em.hal/OneShotI.em'

export type Handler = OneShotI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('TIMER_IRQ_0')
    }
}

//>> ---- em$targ ---- <<//

const ALARM_MASK = 0x1 << 0 // ALARM0
const IRQn = e$`TIMER_IRQ_0_IRQn`

var cur_arg: arg_t
var cur_fxn: Handler = $null

export function disable(): void {
    $R.TIMER.ARMED.$$ = ALARM_MASK
    Idle.setPauseOnly(false)
    IntrVec.NVIC_disable(IRQn)
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
    $R.TIMER.ALARM0.$$ = $R.TIMER.TIMERAWL.$$ + usecs
    $R.TIMER_SET.INTE.$$ = ALARM_MASK
    IntrVec.NVIC_enable(IRQn)
}

export function TIMER_IRQ_0_isr$$() {
    $R.TIMER_CLR.INTR.$$ = ALARM_MASK
    IntrVec.NVIC_clear(IRQn)
    const fxn = cur_fxn
    disable()
    fxn(cur_arg)
}
