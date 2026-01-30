import '@$$emscript'
export const $U = $declare('MODULE')

import * as GpioT from '@silabs.mcu.efr32x/GpioT.em'
import * as SoftUart from '@em.utils/SoftUart.em'

const TxPin = $clone(GpioT)

export namespace em$meta {
    export function em$configure() {
        SoftUart.TxPin.$$dlg = TxPin
        TxPin.pin_num.$$val = 0xB01
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    $['%%d+']
    SoftUart.put(0x55)
    $['%%d-']
}
