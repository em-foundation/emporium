import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BusyWaitConfig from '@em.mark.busywait/BusyWaitConfig.em'

export namespace em$meta {
    export function em$configure() {
        BusyWaitConfig.em$meta.bind('Os', 'sram')
    }
}
