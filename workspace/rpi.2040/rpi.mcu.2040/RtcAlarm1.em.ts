import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as $R from '@rpi.distro.2040/REGS.em'

import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'

export type Handler = RtcI.Handler

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('TIMER_IRQ_1')
    }
}

//>> ---- em$targ ---- <<//

export function disable() {
}

export function enable(thresh: T.RtcThresh, handler: Handler) {
}

export function getRawTime(): T.RawTime {
    let res = T.RawTime.$make()
    const hi_low: u64 = readHiLo()
    res.secs = <u32>(hi_low / 1_000_000)
    res.subs = T.UsecsToRawSubs(<u32>(hi_low % 1_000_000))
    return res
}

export function toThresh(secs: T.Secs30p2): T.RtcThresh {
    return T.Secs30p2ToUsecs(secs)
}

export function TIMER_IRQ_1_isr$$() {
    // IntrVec.NVIC_clear(e$`GRTC_0_IRQn`)
    // const hlr = cur_hlr
    // disable()
    // if (hlr != $null) hlr()
}

function readHiLo(): u64 {
    const lo = $R.TIMER.TIMELR.$$
    const hi = $R.TIMER.TIMEHR.$$
    const hi_lo: u64 = (<u64>hi << 32) | lo
    return hi_lo
}
