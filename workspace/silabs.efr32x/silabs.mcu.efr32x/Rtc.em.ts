import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'

export type Handler = RtcI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RTCC')
    }
}

//>> ---- em$targ ---- <<//

var cur_hlr = <Handler>$null

export function em$startup() {
    // IntrVec.NVIC_enable(e$`RTCC_IRQn`)
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_RTCC
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_LFRCO
    $R.CMU.RTCCCLKCTRL_SET.$$ = $R.CMU_RTCCCLKCTRL_CLKSEL_LFRCO
    $R.RTCC.EN.$$ = 0
    $R.RTCC.CFG_SET.$$ = $R.RTCC_CFG_CNTPRESC_DIV8192
    $R.RTCC.EN.$$ = 1
    $R.RTCC.CMD_SET.$$ = $R.RTCC_CMD_START
    $['%%c']
}

export function disable() {
    cur_hlr = $null
}

export function enable(thresh: T.RtcThresh, handler: Handler) {
    cur_hlr = handler
}

export function getRawTime(): T.RawTime {
    let res = T.RawTime.$make()
    // TODO -- read/read-again
    res.secs = $R.RTCC.CNT.$$ >> 2
    res.subs = $R.RTCC.COMBCNT.$$ << 14
    return res
}

export function toThresh(secs: T.Secs30p2): T.RtcThresh {
    return T.Secs30p2ToUsecs(secs)
}

export function RTCC_isr$$() {
}