import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@nordic.nrf5x/nordic.distro.nrf54/BoardC.em'
import * as LedT from '@em.utils/LedT.em'

export const AppLed = em.$delegate(BoardC.AppLed)
export const SysLed = em.$delegate(BoardC.SysLed)

export function em$run() {
    AppLed.$$.wink(500)
    SysLed.$$.on()
}
