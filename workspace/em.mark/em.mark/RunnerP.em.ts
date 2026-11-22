import '@$$emscript'
export const $U = $declare('MODULE')

import * as ActivityI from '@em.mark/ActivityI.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as T from '@em.utils/TimeTypes.em'

export const Activity = $proxy<ActivityI.$I>()

export const interval_ms = $config<u16>(1000)
export const wake_count = $config<u16>(10)

export const optimization_level = $config<string>()
export const run_from_sram = $config<bool_t>()

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        if (optimization_level.$$val) $property['em.build.Optimize'] = optimization_level.$$val
        if (run_from_sram.$$val) $property['em.build.BootFlash'] = true
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
    }
}

//>> ---- em$targ ---- <<//

var count: u16 = wake_count

export function em$run() {
    Activity.setup()
    ticker.$$.start(T.Secs30p2_initMsecs(interval_ms), $cb(tickCB))
    FiberMgr.run()
}

function tickCB() {
    $['%%d+']
    Activity.exec()
    $['%%d-']
    Activity.report()
    if (--count > 0) return
    ticker.$$.stop()
    Activity.teardown()
    halt()
}
