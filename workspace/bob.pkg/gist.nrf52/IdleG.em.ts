import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

import * as BusyWait from '@em.utils/BusyWait.em'
import * as Idle from '@nordic.mcu.nrf52/Idle.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    BusyWait.wait(1_000_000)
    Idle.exec()
}