import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as RunnerP from '@em.mark/RunnerP.em'
import * as BusyWaitA from '@em.mark.busywait/BusyWaitA.em'

export namespace em$meta {
    export function bind(optimization: 'Oz' | 'Os' | 'O3', placement: 'flash' | 'sram') {
        $using(RunnerP)
        RunnerP.Activity.$$dlg = BusyWaitA
        RunnerP.em$meta.optimization_level = optimization
        RunnerP.run_from_sram.$$val = placement === 'sram'
        if (placement === 'flash') $property['em.build.BootFlash'] = false
    }
}
