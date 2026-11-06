import '@$$emscript'
export const $U = $declare('MODULE', OneShotI)

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as OneShotI from '@em.hal/OneShotI.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'

export type Handler = OneShotI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LGPT3_COMB')
    }
}

const IRQn = e$`LGPT3_COMB_IRQn`
// Bench timing indicates a 48 MHz LGPT3 input. Divide by 48 for a 1 us tick.
const TICK_DIV = 47

var cur_arg: arg_t
var cur_fxn: Handler = $null

export function em$startup(): void {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_LGPT3
}

export function disable(): void {
    const mask = IntrVec.PRIMASK_get()
    IntrVec.PRIMASK_set(1)
    IntrVec.NVIC_disable(IRQn)
    $R.LGPT3.CTL.$$ = $R.LGPT_CTL_MODE_DIS
    $R.LGPT3.IMCLR.$$ = $R.LGPT_IMCLR_TGT
    $R.LGPT3.ICLR.$$ = $R.LGPT_ICLR_TGT
    IntrVec.NVIC_clear(IRQn)
    cur_fxn = $null
    Idle.setLevel(0)
    IntrVec.PRIMASK_set(mask)
}

export function enable(msecs: u32, handler: Handler, arg: arg_t): void {
    if (msecs > $R.LGPT3_TGT_VAL_M / 1000) fail()
    uenable(msecs * 1000, handler, arg)
}

export function uenable(usecs: u32, handler: Handler, arg: arg_t): void {
    if (usecs > $R.LGPT3_TGT_VAL_M) fail()
    const mask = IntrVec.PRIMASK_get()
    IntrVec.PRIMASK_set(1)
    disable()
    cur_fxn = handler
    cur_arg = arg
    Idle.setLevel(1)
    $R.LGPT3.PRECFG.$$ = TICK_DIV << $R.LGPT_PRECFG_TICKDIV_S
    $R.LGPT3.TGT.$$ = usecs == 0 ? 1 : usecs
    $R.LGPT3.IMSET.$$ = $R.LGPT_IMSET_TGT
    IntrVec.NVIC_enable(IRQn)
    $R.LGPT3.CTL.$$ = $R.LGPT_CTL_MODE_UP_ONCE
    IntrVec.PRIMASK_set(mask)
}

export function LGPT3_COMB_isr$$(): void {
    const fxn = cur_fxn
    const arg = cur_arg
    disable()
    if (fxn != $null) fxn(arg)
}
