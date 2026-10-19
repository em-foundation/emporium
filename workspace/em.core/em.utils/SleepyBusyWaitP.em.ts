import '@$$emscript'
export const $U = $declare('MODULE')

import * as BusyWaitActivity from '@em.utils/BusyWaitActivity.em'
import * as SleepyRunner from '@em.utils/SleepyRunner.em'

export namespace em$meta {
    export function em$configure() {
        SleepyRunner.Activity.$$dlg = BusyWaitActivity
        SleepyRunner.iterations.$$val = 10
        SleepyRunner.interval_ms.$$val = 1000
        BusyWaitActivity.duration_us.$$val = 50000
    }
}

export function em$run() {
    SleepyRunner.run()
}