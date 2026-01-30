import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.UsCounter.set(1000)
    $['%%d+']
    Common.UsCounter.spin()
    $['%%d-']
}