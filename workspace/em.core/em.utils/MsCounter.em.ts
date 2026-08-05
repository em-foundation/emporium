import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function start() {
    Common.UsCounter.start()
}

export function stop(): u32 {
    return (Common.UsCounter.stop() + 500) / 1000
}
