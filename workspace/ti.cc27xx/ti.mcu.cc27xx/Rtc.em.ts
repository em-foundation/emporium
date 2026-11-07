import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
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
var cur_thresh: u32
var aux_handler: RtcI.Handler = $null
var aux_thresh: u32

export function em$startup(): void {
    $R.RTC.CTL.$$ = $R.RTC_CTL_RST
    disarm()
    IntrVec.NVIC_enable(IRQn)
}

export function disable(): void {
    const key = GlobalInterrupts.disable()
    cur_handler = $null
    armNext()
    GlobalInterrupts.restore(key)
}

export function enable(thresh: T.RtcThresh, handler: RtcI.Handler): void {
    const key = GlobalInterrupts.disable()
    cur_handler = handler
    cur_thresh = thresh
    armNext()
    GlobalInterrupts.restore(key)
}

// CH1 is capture-only. Multiplex the two clients onto CH0 compare,
// preserving the earlier AlarmMgr deadline when the radio arms a pause.
export function enableAuxDelay(usecs: u32, handler: RtcI.Handler): void {
    const key = GlobalInterrupts.disable()
    aux_handler = handler
    aux_thresh = $R.RTC.TIME8U.$$ + ((usecs + 7) / 8)
    armNext()
    GlobalInterrupts.restore(key)
}

export function disableAux(): void {
    const key = GlobalInterrupts.disable()
    aux_handler = $null
    armNext()
    GlobalInterrupts.restore(key)
}

export function getRawUsecs(): u32 {
    return $R.RTC.TIME8U.$$ << 3
}

function disarm(): void {
    $R.RTC.IMCLR.$$ = $R.RTC_IMCLR_EV0
    $R.RTC.ARMCLR.$$ = $R.RTC_ARMCLR_CH0
    $R.RTC.ICLR.$$ = $R.RTC_ICLR_EV0
    IntrVec.NVIC_clear(IRQn)
}

function armNext(): void {
    disarm()
    if (cur_handler == $null && aux_handler == $null) return
    let thresh = cur_thresh
    if (cur_handler == $null || (aux_handler != $null && <i32>(aux_thresh - thresh) < 0)) {
        thresh = aux_thresh
    }
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
    disarm()
    const now = $R.RTC.TIME8U.$$
    let main: RtcI.Handler = $null
    let aux: RtcI.Handler = $null
    if (cur_handler != $null && <i32>(now - cur_thresh) >= 0) {
        main = cur_handler
        cur_handler = $null
    }
    if (aux_handler != $null && <i32>(now - aux_thresh) >= 0) {
        aux = aux_handler
        aux_handler = $null
    }
    if (main != $null) main()
    if (aux != $null) aux()
    armNext()
}

