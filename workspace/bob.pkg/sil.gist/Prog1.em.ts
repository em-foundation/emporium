import '@$$emscript'
export const $U = $declare('MODULE')

import * as BusyWait from '@em.utils/BusyWait.em'
import * as GpioT from '@silabs.mcu.efr32x/GpioT.em'
import * as Mcu from '@silabs.mcu.efr32x/Mcu.em'

const LedPin = $clone(GpioT)

export namespace em$meta {
    export function em$configure() {
        BusyWait.scalar.$$val = 6
        LedPin.pin_num.$$val = 0xA04
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Mcu.startup()
    LedPin.makeOutput()
    LedPin.clear()
    for (const _ of $range(10)) {
        LedPin.toggle()
        BusyWait.wait(100_000)
    }
    LedPin.set()
}