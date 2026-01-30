import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as GpioT from '@silabs.mcu.efr32x/GpioT.em'
import * as Mcu from '@silabs.mcu.efr32x/Mcu.em'

const LedPin = $clone(GpioT)
const TxPin = $clone(GpioT)

export namespace em$meta {
    export function em$configure() {
        LedPin.pin_num.$$val = 0xA04
        TxPin.pin_num.$$val = 0xB01
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Mcu.startup()
    LedPin.makeOutput()
    TxPin.makeOutput()
    TxPin.set()
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_USART0
    $R.USART0.EN_SET.$$ = 1
    $R.GPIO.USARTROUTE[0].ROUTEEN.$$ = $R.GPIO_USART_ROUTEEN_TXPEN
    $R.GPIO.USARTROUTE[0].TXROUTE.$$ = 0x10001
    const div: u32 = 0x0000a000
    $R.USART0.CLKDIV_SET.$$ = div
    $R.USART0.CMD_SET.$$ = $R.USART_CMD_TXEN
    $R.USART0.TXDATA_SET.$$ = 0x55
    LedPin.set()
}