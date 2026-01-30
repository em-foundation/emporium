import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BusyWait from '@ti.mcu.cc23xx/BusyWait.em'
import * as Pin from '@bob.scratch/AppLedPin.em'

export namespace em$meta {
    export function em$configure() {
        BusyWait.scalar.$$ = 20
    }
}

export function em$run() {
    Pin.makeOutput()
    for (let i = 0; i < 10; i++) {
        Pin.toggle()
        BusyWait.wait(100_000)
    }
    Pin.set()
}
