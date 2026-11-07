import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('AON_RTC_COMB')
    }
}

const IRQn = e$`AON_RTC_COMB_IRQn`
const TICKS_PER_SEC = 125_000
const TICKS_PER_QSEC = TICKS_PER_SEC / 4

var cur_handler: RtcI.Handler = $null

export function em$startup(): void {
    $R.RTC.CTL.$$ = $R.RTC_CTL_RST
    disable()
    IntrVec.NVIC_enable(IRQn)
}

export function disable(): void {
    $R.RTC.IMCLR.$$ = $R.RTC_IMCLR_EV0
    $R.RTC.ARMCLR.$$ = $R.RTC_ARMCLR_CH0
    $R.RTC.ICLR.$$ = $R.RTC_ICLR_EV0
    IntrVec.NVIC_clear(IRQn)
    cur_handler = $null
}

export function enable(thresh: T.RtcThresh, handler: RtcI.Handler): void {
    cur_handler = handler
    $R.RTC.CH0CC8U.$$ = thresh
    $R.RTC.IMSET.$$ = $R.RTC_IMSET_EV0
}

export function getRawTime(): T.RawTime {
    let hi: u32
    let lo: u32
    while (true) {
        hi = $R.RTC.TIME524M.$$
        lo = $R.RTC.TIME8U.$$
        if (hi == $R.RTC.TIME524M.$$) break
    }
    // The two views overlap by 16 bits.
    const ticks = (<u64>hi << 16) | (lo & 0xffff)
    let raw = T.RawTime.$make()
    raw.secs = <u32>(ticks / TICKS_PER_SEC)
    raw.subs = T.UsecsToRawSubs(<u32>(ticks % TICKS_PER_SEC) * 8)
    return raw
}

export function toThresh(qsecs: T.Secs30p2): T.RtcThresh {
    return qsecs * TICKS_PER_QSEC
}

export function AON_RTC_COMB_isr$$(): void {
    const handler = cur_handler
    disable()
    if (handler != $null) handler()
}
