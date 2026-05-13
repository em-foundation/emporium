import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var active: volatile_t<bool_t> = false

export function disable() {
    $['%%d-']
    active = false
    Common.UsCounter.stop()
}

export function enable(dt_us: u32) {
    $['%%d+']
    active = true
    Common.UsCounter.set(dt_us)
}

export function wait() {
    if (!active) return
    Common.UsCounter.spin()
    disable()
}
