import '@$$emscript'
export const $U = $declare('MODULE')

import * as ActivityI from '@em.utils/ActivityI.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TT from '@em.utils/TimeTypes.em'

export const Activity = $proxy<ActivityI.$I>()
export const iterations = $config<u16>(10)
export const interval_ms = $config<u16>(1000)

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        if (!Number.isInteger(iterations.$$val) || iterations.$$val < 1 || iterations.$$val > 65535) {
            throw new Error('SleepyRunner.iterations must be in 1..65535')
        }
        // TickerMgr uses quarter-second fixed-point intervals.
        if (!Number.isInteger(interval_ms.$$val) || interval_ms.$$val < 250
            || interval_ms.$$val > 65500 || interval_ms.$$val % 250 != 0) {
            throw new Error('SleepyRunner.interval_ms must be a multiple of 250 in 250..65500')
        }
        ticker.$$val = TickerMgr.em$meta.create()
    }
}

//>> ---- em$targ ---- <<//

var remaining: u16

// One campaign per program. Activities may have their own configs and state.
// exec must fit within interval_ms and return only after its work is complete.
// Teardown output and the completion LED are outside Debug D; exclude them
// when measuring a complete sleep/activity interval at the end of a campaign.
export function run() {
    remaining = iterations
    Activity.setup()
    ticker.$$.start(TT.Secs30p2_initMsecs(interval_ms), $cb(tickCB))
    FiberMgr.run()
}

function tickCB() {
    $['%%d+']
    Activity.exec()
    $['%%d-']
    remaining -= 1
    if (remaining != 0) return
    ticker.$$.stop()
    Activity.teardown()
    halt()
}