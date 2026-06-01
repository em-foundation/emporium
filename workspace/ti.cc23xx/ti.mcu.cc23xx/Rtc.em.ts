import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'

export type Handler = RtcI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('CPUIRQ0')
    }
}

const RTC_RES_BITS = <u8>20
const RTC_TICKS_PER_SEC = 1 << 16
const RTC_USECS_PER_TICK_NUM = 15625
const RTC_USECS_PER_TICK_DEN = 1024
const RTC_TICKS_PER_QSEC = RTC_TICKS_PER_SEC >> 2

var cur_hlr = <Handler>$null
var cur_thresh: T.RtcThresh = 0
var cur_active = false
var aux_hlr = <Handler>$null
var aux_thresh: T.RtcThresh = 0
var aux_active = false

export function em$startup() {
    $R.CKMD.LFINCOVR.$$ = 0x8000_0000 + (1 << RTC_RES_BITS)
    $R.RTC.CTL.$$ = $R.RTC_CTL_RST
    $R.EVTSVT.CPUIRQ0SEL.$$ = $R.EVTSVT_CPUIRQ0SEL_PUBID_AON_RTC_COMB
    IntrVec.NVIC_enable(e$`CPUIRQ0_IRQn`)
}

export function disable() {
    cur_hlr = $null
    cur_active = false
    if (!aux_active) {
        disarm()
    }
}

export function disableAux() {
    aux_hlr = $null
    aux_active = false
    restoreMain()
}

export function enable(thresh: T.RtcThresh, handler: Handler) {
    cur_hlr = handler
    cur_thresh = thresh
    cur_active = true
    if (!aux_active) {
        arm(cur_thresh)
    }
}

export function enableAux(thresh: T.RtcThresh, handler: Handler) {
    aux_hlr = handler
    aux_thresh = thresh
    aux_active = true
    arm(aux_thresh)
}

export function enableAuxUsecs(usecs: u32, handler: Handler) {
    enableAux(usecsToTicks(usecs), handler)
}

export function getCounter(): u32 {
    return $R.RTC.TIME8U.$$
}

export function getRawTime(): T.RawTime {
    let lo: u32
    let hi: u32
    while (true) {
        lo = $R.RTC.TIME8U.$$
        hi = $R.RTC.TIME524M.$$
        if (lo == $R.RTC.TIME8U.$$) break
    }
    let res = T.RawTime.$make()
    res.secs = hi
    res.subs = lo << 16
    return res
}

export function getRawUsecs(): u32 {
    return ticksToUsecs(getCounter())
}

export function toThresh(qsecs: T.Secs30p2): T.RtcThresh {
    return qsecs * RTC_TICKS_PER_QSEC
}

export function CPUIRQ0_isr$$() {
    $R.RTC.ICLR.$$ = $R.RTC_ICLR_EV0
    IntrVec.NVIC_clear(e$`CPUIRQ0_IRQn`)
    if (aux_active) {
        const hlr = aux_hlr
        aux_hlr = $null
        aux_active = false
        if (hlr != $null) hlr()
        if (!aux_active) {
            restoreMain()
        }
        return
    }
    if (cur_active) {
        const hlr = cur_hlr
        cur_hlr = $null
        cur_active = false
        if (hlr != $null) hlr()
    }
}

function arm(thresh: T.RtcThresh) {
    $R.RTC.CH0CC8U.$$ = thresh
    $R.RTC.IMSET.$$ = $R.RTC_IMSET_EV0
}

function disarm() {
    $R.RTC.IMCLR.$$ = $R.RTC_IMCLR_EV0
    $R.RTC.ARMCLR.$$ = 1
    $R.RTC.ICLR.$$ = $R.RTC_ICLR_EV0
}

function restoreMain() {
    if (cur_active) {
        arm(cur_thresh)
    } else {
        disarm()
    }
}

function usecsToTicks(usecs: u32): u32 {
    return ((usecs / RTC_USECS_PER_TICK_NUM) * RTC_USECS_PER_TICK_DEN) + ((((usecs % RTC_USECS_PER_TICK_NUM) * RTC_USECS_PER_TICK_DEN) + (RTC_USECS_PER_TICK_NUM - 1)) / RTC_USECS_PER_TICK_NUM)
}

function ticksToUsecs(ticks: u32): u32 {
    return ((ticks / RTC_USECS_PER_TICK_DEN) * RTC_USECS_PER_TICK_NUM) + (((ticks % RTC_USECS_PER_TICK_DEN) * RTC_USECS_PER_TICK_NUM) / RTC_USECS_PER_TICK_DEN)
}
