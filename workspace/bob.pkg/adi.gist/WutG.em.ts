import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@adi.distro.max326xx/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('WUT')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    $R.GCR.PM.$$ |= $R.F_GCR_PM_WUT_WE
    $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_ERTCO_EN
    $R.WUT.CMP.$$ = 32780
    $R.WUT.CNT.$$ = 1
    $R.WUT.INTR.$$ = 1
    IntrVec.NVIC_clear(e$`WUT_IRQn`)
    IntrVec.NVIC_enable(e$`WUT_IRQn`)
    $['%%d']
    $R.WUT.CTRL.$$ = $R.F_WUT_CTRL_TEN
    while ($R.WUT.CNT.$$ < 3) { }
    Common.GlobalInterrupts.$$.enable()
    Common.Idle.$$.exec()
}

export function WUT_isr$$() {
    $['%%d']
    $R.WUT.INTR.$$ = 1
    IntrVec.NVIC_clear(e$`WUT_IRQn`)
    halt()
}