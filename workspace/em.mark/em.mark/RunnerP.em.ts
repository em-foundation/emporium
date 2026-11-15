import '@$$emscript'
export const $U = $declare('MODULE')

import * as ActivityI from '@em.mark/ActivityI.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'

export const Activity = $proxy<ActivityI.$I>()
export const interval_ms = $config<u16>(1000)
export const wake_count = $config<u16>(10)
export const run_from_sram = $config<bool_t>(false)

const ticker = $config<TickerMgr.Obj>()

export namespace em$meta {
    export let optimization_level = ''

    export function em$configure() {
        if (optimization_level) $property['em.build.Optimize'] = optimization_level
        if (run_from_sram.$$val) $property['em.build.BootFlash'] = true
    }

    export function em$construct() {
        if (!Number.isInteger(wake_count.$$val) || wake_count.$$val < 1 || wake_count.$$val > 65535) {
            throw new Error('RunnerP.wake_count must be in 1..65535')
        }
        if (!Number.isInteger(interval_ms.$$val) || interval_ms.$$val < 250
            || interval_ms.$$val > 65500 || interval_ms.$$val % 250 != 0) {
            throw new Error('RunnerP.interval_ms must be a multiple of 250 in 250..65500')
        }
        ticker.$$val = TickerMgr.em$meta.create()
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
}
