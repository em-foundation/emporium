import em from '@$$emscript'
export const $U = em.$declare('COMPOSITE')

import * as GpioT from '@maxim.mcu.326xx/GpioT.em'

export const TxPin = $clone(GpioT)

export function em$configure() {
    TxPin.pin_num.$$ = 0x001
}