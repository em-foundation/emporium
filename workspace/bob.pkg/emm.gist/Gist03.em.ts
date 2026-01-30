import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as BoardC from '@$distro/BoardC.em'

const AppLedPin = $delegate(BoardC.AppLedPin)
const AppOutPin = $delegate(BoardC.AppOutPin)
const SysLedPin = $delegate(BoardC.SysLedPin)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    AppLedPin.makeOutput()
    AppLedPin.clear()
    SysLedPin.makeOutput()
    SysLedPin.clear()
    //
    AppOutPin.makeOutput()
    AppOutPin.set()
    $R.GPIO.RegGPIOOutSel1.$$ |= 3 << $R.GPIO_OUT_SEL7_SHIFT
    $R.UART.RegUARTCtrl.$$ |= $R.UART_TX_EN_MASK
    //
    for (const i of $range(5)) {
        put(0x10 + i)
        AppLedPin.set()
        flush()
        AppLedPin.clear()
    }
    //
    SysLedPin.set()
}

function put(b: u8) {
    $R.UART.RegUARTTxFIFO1B.$$ = b
}

function flush() {
    while ($R.UART.RegUARTStat.$$ & $R.UART_TX_BUSY_MASK) { }
}