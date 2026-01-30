import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BoardC from '@nordic.nrf5x/nordic.distro.nrf54/BoardC.em'
import * as Common from '@em.mcu/Common.em'

export const AppLedPin = em.$delegate(BoardC.AppLedPin)
export const SysLedPin = em.$delegate(BoardC.SysLedPin)

export function em$startup() {
    AppLedPin.$$.makeOutput()
    SysLedPin.$$.makeOutput()
}

export function em$run() {
    for (let i = 0; i < 10; i++) {
        AppLedPin.$$.toggle()
        Common.BusyWait.$$.wait(250_000)
    }
    SysLedPin.$$.set()
}
