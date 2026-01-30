import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    $['%%d+']
    Common.BusyWait.wait(100_000)
    $['%%d-']
    Common.BusyWait.wait(100_000)
    $['%%a+']
    $['%%b+']
    $['%%c+']
    $['%%d+']
}