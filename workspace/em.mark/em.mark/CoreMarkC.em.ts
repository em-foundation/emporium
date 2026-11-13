import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as CoreMarkActivity from '@em.mark.activities/CoreMarkActivity.em'
import * as RunnerP from '@em.mark/RunnerP.em'

export namespace em$meta {
    export function em$configure() {
        $using(RunnerP)
        RunnerP.Activity.$$dlg = CoreMarkActivity
        RunnerP.interval_ms.$$val = 1000
        RunnerP.wake_count.$$val = 10
    }
}
