import '@$$emscript'
export const $U = $declare('MODULE')

import * as Idle from '@nordic.mcu.nrf91/Idle.em'

export function em$run() {
    printf`Entering idle\n`()
    while (true) {
        Idle.exec()
    }
}
