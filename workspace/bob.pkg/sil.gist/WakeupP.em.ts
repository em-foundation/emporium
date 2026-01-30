import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RTCC')
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    IntrVec.NVIC_enable(e$`RTCC_IRQn`)
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_RTCC
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_LFRCO
    $R.CMU.RTCCCLKCTRL_SET.$$ = $R.CMU_RTCCCLKCTRL_CLKSEL_LFRCO
    $R.RTCC.EN.$$ = 0
    $R.RTCC.CFG_SET.$$ = $R.RTCC_CFG_CNTPRESC_DIV8192
    $R.RTCC.CC[0].CTRL.$$ = $R.RTCC_CC_CTRL_MODE_OUTPUTCOMPARE
    $R.RTCC.CC[0].OCVALUE.$$ = 6
    $R.RTCC.EN.$$ = 1
    $R.RTCC.IEN_SET.$$ = $R.RTCC_IEN_CC0
    $R.RTCC.CMD_SET.$$ = $R.RTCC_CMD_START
    $['%%d+']
    Common.GlobalInterrupts.enable()
    Common.Idle.exec()
    // Common.BusyWait.wait(1_500_000)
    // while ($R.RTCC.STATUS.$$ == 0) { }
    const cnt = $R.RTCC.CNT.$$
    const flg = $R.RTCC.IF.$$
    // $['%%d-']
    // printf`cnt = %d, flg = %08x\n`(cnt, flg)
}

export function RTCC_isr$$() {
    $['%%d-']
    halt()
}