import '@$$emscript'
export const $U = $declare('MODULE', RtcI)

import * as $R from '@emm.distro.9305/REGS.em'

import * as Idle from '@emm.mcu.9305/Idle.em'
import * as RtcI from '@em.hal/RtcI.em'
import * as T from '@em.utils/TimeTypes.em'

export type Handler = RtcI.Handler

export namespace em$meta {
    export function em$construct() {
        Idle.em$meta.addSleepLeave($cb(sleepLeave))
    }
}

//>> ---- em$targ ---- <<//

var cur_hlr = <Handler>$null

export function em$startup() {
    $R.PML.RegSleepTimCtrl.$$ = $R.ST_RUN_EN_MASK
}

export function disable(): void {
    cur_hlr = $null
}

export function enable(thresh: T.RtcThresh, handler: Handler): void {
    cur_hlr = handler
    $R.PML.RegSleepTimCompareCfg.$$ = 0x0001_0001
    $R.PML.RegSleepTimCompare0.$$ = thresh
}

export function getRawTime(): T.RawTime {
    const cnt = $R.PML.RegSleepTimCount.$$
    let res = T.RawTime.$make()
    res.secs = cnt >> 15
    res.subs = cnt << 17
    return res
}

export function toThresh(qsecs: T.Secs30p2): T.RtcThresh {
    return qsecs << 13
}

function sleepLeave() {
    const hlr = cur_hlr
    cur_hlr = $null
    if (hlr != $null) hlr()
}
