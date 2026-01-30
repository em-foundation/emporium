import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('TIMER0')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    IntrVec.NVIC_enable(e$`TIMER0_IRQn`)
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_TIMER0
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_FSRCO
    $R.CMU.EM01GRPACLKCTRL_SET.$$ = $R.CMU_EM01GRPACLKCTRL_CLKSEL_FSRCO
    $R.TIMER0.EN_CLR.$$ = 1
    const pre = 20 << $R._TIMER_CFG_PRESC_SHIFT
    $R.TIMER0.CFG_SET.$$ = pre | $R.TIMER_CFG_OSMEN | $R.TIMER_CFG_MODE_DOWN
    $R.TIMER0.EN_SET.$$ = 1
    $R.TIMER0.TOP.$$ = $R.TIMER0.CNT.$$ = 1000
    $R.TIMER0.IEN_SET.$$ = $R.TIMER_IEN_UF
    $R.TIMER0.IF.$$ = 0
    $R.TIMER0.CMD.$$ = $R.TIMER_CMD_START
    $['%%d+']
    Common.GlobalInterrupts.enable()
    Common.Idle.exec()
}

export function TIMER0_isr$$() {
    $['%%d-']
    halt()
}