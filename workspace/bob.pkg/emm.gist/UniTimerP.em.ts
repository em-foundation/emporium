import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as IntrVec from '@em.arch.arc/IntrVec.em'

import * as Common from '@em.mcu/Common.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('UNIVERSAL_TIMER_2')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.GlobalInterrupts.enable()
    $R.IRQ.RegIRQUniTimEnSet.$$ = $R.IRQ_UT2_FULL_VAL_EN_SET_MASK
    $R.IRQ.RegIRQUniTimMskSet.$$ = $R.IRQ_UT2_FULL_VAL_MSK_SET_MASK
    $R.UTIM.RegUniTimer2Cfg.$$ = 5
    $R.UTIM.RegUniTimer2Ctrl.$$ = $R.UT2_CLEAR_MASK
    $R.UTIM.RegUniTimer2Limit.$$ = 500000
    $R.UTIM.RegUniTimer2Ctrl.$$ = ($R.UT2_ENABLE_MASK | $R.UT2_START_SW_MASK)
    $['%%d']
    Common.Idle.exec()
}

export function UNIVERSAL_TIMER_2_isr$$() {
    $['%%a']
    $R.IRQ.RegIRQUniTimStsClr.$$ = $R.IRQ_UT2_FULL_VAL_STS_CLR_MASK
    $R.UTIM.RegUniTimer2Ctrl.$$ = 0
}