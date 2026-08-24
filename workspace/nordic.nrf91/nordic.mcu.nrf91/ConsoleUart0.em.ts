import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'

export const TxPin = $proxy<GpioI.$I>()

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var txd_buf: u8

export function em$startup() {
    $R.UARTE0.PSEL.TXD.$$ = TxPin.pinId()
    $R.UARTE0.BAUDRATE.$$ = $R.UARTE_BAUDRATE_BAUDRATE_Baud115200
    $R.UARTE0.ENABLE.$$ = $R.UARTE_ENABLE_ENABLE_Enabled
    $R.UARTE0.TXD.PTR.$$ = $cast2<u32>($$(txd_buf))
    $R.UARTE0.TXD.MAXCNT.$$ = 1
}

export function flush() { }

export function put(data: u8) {
    txd_buf = data
    $R.UARTE0.TASKS_STARTTX.$$ = 1
    while ($R.UARTE0.EVENTS_TXDRDY.$$ == 0) { }
    $R.UARTE0.EVENTS_TXDRDY.$$ = 0
}

