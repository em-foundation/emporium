import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as GpioT from '@silabs.mcu.efr32x/GpioT.em'

const TxPin = $clone(GpioT)

export namespace em$meta {
    export function em$configure() {
        TxPin.pin_num.$$val = 0xB02
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    TxPin.makeOutput()
    TxPin.set()
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_USART0
    $R.USART0.EN_SET.$$ = 1
    $R.GPIO.USARTROUTE[0].ROUTEEN.$$ = $R.GPIO_USART_ROUTEEN_TXPEN
    $R.GPIO.USARTROUTE[0].TXROUTE.$$ = 0x40001
    const div: u32 = 0x0000_0800
    $R.USART0.CLKDIV_SET.$$ = div
    $R.USART0.CMD_SET.$$ = $R.USART_CMD_TXEN
    for (const i of $range(10)) {
        $R.USART0.TXDATA_SET.$$ = 0x55 + i
        while (($R.USART0.STATUS.$$ & $R.USART_STATUS_TXC) == 0) { }
    }
}