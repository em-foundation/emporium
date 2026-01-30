import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as GpioI from '@em.hal/GpioI.em'

const em$_C = {
    pin: $config<u8>()
}

namespace em$meta {
    export const c_pin = em$_C.pin
}

export default { $U, em$_C, ...em$meta, ...em.isa<GpioI.$I>() }
