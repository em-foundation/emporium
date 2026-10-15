import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'

export type Handler = RtcI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('RTC0')
    }
}

//>> ---- em$targ ---- <<//

const AUX_MIN_LEAD_TICKS = 3
const AUX_OVERDUE_TICKS = 3277
const COUNTER_MASK = 0x00ffffff
const SUBS_Cnt = 15  // 32kHz 
const SUBS_Msk = (1 << SUBS_Cnt) - 1

var aux_arm_after: u32
var aux_arm_before: u32
var aux_deadline: u32
var aux_fired: u32 = 0
var aux_reported: bool_t = false
var cur_hlr = <Handler>$null
var cur_hlr_aux = <Handler>$null

var ovr_cnt: u32 = 0

export function em$startup() {
    $R.RTC0.INTENSET.$$ = $R.RTC_INTENSET_OVRFLW_Msk
    $R.RTC0.TASKS_START.$$ = 1
    IntrVec.NVIC_enable(e$`RTC0_IRQn`)
}

export function disable() {
    cur_hlr = $null
    $R.RTC0.INTENCLR.$$ = $R.RTC_INTENCLR_COMPARE0_Msk
    $R.RTC0.EVENTS_COMPARE[0].$$ = 0
}

export function disableAux() {
    cur_hlr_aux = $null
    $R.RTC0.INTENCLR.$$ = $R.RTC_INTENCLR_COMPARE1_Msk
    $R.RTC0.EVENTS_COMPARE[1].$$ = 0
}

export function enable(thresh: T.RtcThresh, handler: Handler) {
    const ctr = $R.RTC0.COUNTER.$$
    cur_hlr = handler
    $R.RTC0.CC[0].$$ = thresh
    $R.RTC0.INTENSET.$$ = $R.RTC_INTENSET_COMPARE0_Msk
}

export function enableAux(thresh: T.RtcThresh, handler: Handler) {
    const key = GlobalInterrupts.disable()
    $R.RTC0.INTENCLR.$$ = $R.RTC_INTENCLR_COMPARE1_Msk
    $R.RTC0.EVENTS_COMPARE[1].$$ = 0
    aux_arm_before = $R.RTC0.COUNTER.$$
    aux_deadline = thresh & COUNTER_MASK
    const lead: u32 = (aux_deadline - aux_arm_before) & COUNTER_MASK
    if (lead < AUX_MIN_LEAD_TICKS || lead >= 0x00800000) {
        aux_deadline = (aux_arm_before + AUX_MIN_LEAD_TICKS) & COUNTER_MASK
    }
    aux_reported = false
    cur_hlr_aux = handler
    $R.RTC0.CC[1].$$ = aux_deadline
    $R.RTC0.INTENSET.$$ = $R.RTC_INTENSET_COMPARE1_Msk
    aux_arm_after = $R.RTC0.COUNTER.$$
    $['%%c']
    GlobalInterrupts.restore(key)
}

export function enableAuxUsecs(usecs: u32, handler: Handler) {
    enableAux(usecsToTicks(usecs), handler)
}

export function getCounter(): u32 {
    return $R.RTC0.COUNTER.$$
}

export function getRawTime(): T.RawTime {
    let res = T.RawTime.$make()
    const ctr = $R.RTC0.COUNTER.$$
    res.secs = ((ovr_cnt << 9)) | (ctr >> SUBS_Cnt) // TODO -- add overflow count
    res.subs = (ctr & SUBS_Msk) << (32 - SUBS_Cnt)
    return res
}

export function getRawUsecs(): u32 {
    return ticksToUsecs(getCounter())
}

export function toThresh(qsecs: T.Secs30p2): T.RtcThresh {
    return qsecs << 13   // 32 kHz
}

export function RTC0_isr$$() {
    IntrVec.NVIC_clear(e$`RTC0_IRQn`)
    if ($R.RTC0.EVENTS_OVRFLW.$$) {
        $R.RTC0.EVENTS_OVRFLW.$$ = 0
        ovr_cnt += 1
        $['%%>']($R.RTC0.COUNTER.$$)
        return
    }
    if ($R.RTC0.EVENTS_COMPARE[0].$$) {
        checkAux()
        const hlr = cur_hlr
        disable()
        if (hlr != $null) hlr()
    }
    if ($R.RTC0.EVENTS_COMPARE[1].$$) {
        aux_fired += 1
        const hlr = cur_hlr_aux
        disableAux()
        if (hlr != $null) {
            $['%%c:'](1)
            hlr()
        }
    }
}

function checkAux() {
    if (cur_hlr_aux == $null || aux_reported) return
    const now: u32 = $R.RTC0.COUNTER.$$
    const overdue: u32 = (now - aux_deadline) & COUNTER_MASK
    if (overdue < AUX_OVERDUE_TICKS || overdue >= 0x00800000) return
    const compare: u32 = $R.RTC0.CC[1].$$
    const event: u32 = $R.RTC0.EVENTS_COMPARE[1].$$
    const enabled: u32 = $R.RTC0.INTENSET.$$
    const before: u32 = aux_arm_before
    const after: u32 = aux_arm_after
    const deadline: u32 = aux_deadline
    const fired: u32 = aux_fired
    aux_reported = true
    printf`RTC AUX overdue before=%d after=%d target=%d now=%d\n`(before, after, deadline, now)
    printf`RTC AUX compare=%d event=%d inten=%08x fired=%d late_ticks=%d\n`(compare, event, enabled, fired, overdue)
}

function usecsToTicks(usecs: u32): u32 {
    return ((usecs / 15625) * 512) + ((((usecs % 15625) * 512) + 15624) / 15625)
}

function ticksToUsecs(ticks: u32): u32 {
    return ((ticks >> 9) * 15625) + (((ticks & 0x1ff) * 15625) >> 9)
}
