import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    $['%%a+']
    Common.BusyWait.$$.wait(1000)
    $['%%a-']
}