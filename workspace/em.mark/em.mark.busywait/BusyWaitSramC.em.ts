import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as RunnerP from '@em.mark/RunnerP.em'
import * as BusyWaitA from '@em.mark.busywait/BusyWaitA.em'

export namespace em$meta {
    export function em$configure() {
        $using(RunnerP)
        RunnerP.Activity.$$dlg = BusyWaitA
        RunnerP.run_from_sram.$$val = true
    }
}
