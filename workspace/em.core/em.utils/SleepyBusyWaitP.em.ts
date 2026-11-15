import '@$$emscript'
export const $U = $declare('MODULE')

import * as BusyWaitA from '@em.mark.busywait/BusyWaitA.em'
import * as SleepyRunner from '@em.mark/SleepyRunner.em'

export namespace em$meta {
    export function em$configure() {
        SleepyRunner.Activity.$$dlg = BusyWaitA
        SleepyRunner.iterations.$$val = 10
        SleepyRunner.interval_ms.$$val = 1000
        BusyWaitA.duration_us.$$val = 50000
    }
}

export function em$run() {
    SleepyRunner.run()
}