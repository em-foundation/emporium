import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'
import * as Idle from '@silabs.mcu.efr32x/Idle.em'

export const TxPin = $proxy<GpioI.$I>()

export namespace em$meta {
    export function em$construct() {
        // Idle.em$meta.addSleepEnter($cb(sleepEnter))
        // Idle.em$meta.addSleepLeave($cb(sleepLeave))
    }
}

//>> ---- em$targ ---- <<//

export function em$startup() {
    sleepLeave()
}

export function flush() {
    while (($R.USART0.STATUS.$$ & $R.USART_STATUS_TXBL) == 0) { }
}

export function put(data: u8) {
    $R.USART0.TXDATA_SET.$$ = data
    flush()
}

function sleepEnter() {
    TxPin.reset()
    $R.CMU.CLKEN0_CLR.$$ = $R.CMU_CLKEN0_USART0
    $R.USART0.EN_CLR.$$ = 1
}

function sleepLeave() {
    TxPin.makeOutput()
    TxPin.set()
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_USART0
    $R.USART0.EN_SET.$$ = 1
    $R.GPIO.USARTROUTE[0].ROUTEEN.$$ = $R.GPIO_USART_ROUTEEN_TXPEN
    $R.GPIO.USARTROUTE[0].TXROUTE.$$ = 0x10001
    const div: u32 = 0x0000_0800
    $R.USART0.CLKDIV_SET.$$ = div
    $R.USART0.CMD_SET.$$ = $R.USART_CMD_TXEN
}
