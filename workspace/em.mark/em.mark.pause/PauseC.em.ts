import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as RunnerP from '@em.mark/RunnerP.em'
import * as PauseA from '@em.mark.pause/PauseA.em'

export namespace em$meta {
    export function em$configure() {
        $using(RunnerP)
        RunnerP.Activity.$$dlg = PauseA
    }
}
