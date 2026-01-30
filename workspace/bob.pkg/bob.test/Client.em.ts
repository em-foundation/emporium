import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@nordic.nrf5x/nordic.distro.nrf54/BoardC.em'

const em$_C = {}

namespace em$meta {
    export function em$construct() {
        // console.log($U)
        // console.log(BoardC.AppLed.x_Pin)
    }
}

namespace em$targ { }

export default { $U, ...em$meta /*, ...em$targ */ }
