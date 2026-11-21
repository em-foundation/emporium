import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as RunnerP from '@em.mark/RunnerP.em'
import * as CoreMarkA from '@em.mark.coremark/CoreMarkA.em'

export namespace em$meta {
    export function em$configure() {
        $using(RunnerP)
        RunnerP.Activity.$$dlg = CoreMarkA
    }
}
