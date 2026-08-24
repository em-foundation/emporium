import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'
import * as Idle from '@nordic.mcu.nrf91/Idle.em'

export const TxPin = $proxy<GpioI.$I>()

export namespace em$meta {
    export function em$construct() {
        Idle.em$meta.addSleepEnter($cb(sleepEnter))
        Idle.em$meta.addSleepLeave($cb(sleepLeave))
    }
}

//>> ---- em$targ ---- <<//

var txd_buf: u8

export function em$startup() {
    sleepLeave()
}

export function flush() { }

export function put(data: u8) {
    txd_buf = data
    $R.UARTE0.TASKS_STARTTX.$$ = 1
    while ($R.UARTE0.EVENTS_TXDRDY.$$ == 0) { }
    $R.UARTE0.EVENTS_TXDRDY.$$ = 0
}

function sleepEnter() {
    $R.UARTE0.TASKS_STOPTX.$$ = 1
    $R.UARTE0.EVENTS_TXDRDY.$$ = 0
    $R.UARTE0.ENABLE.$$ = $R.UARTE_ENABLE_ENABLE_Disabled
    $R.UARTE0.PSEL.TXD.$$ = ~0
    TxPin.reset()
}

function sleepLeave() {
    $R.UARTE0.PSEL.TXD.$$ = TxPin.pinId()
    $R.UARTE0.BAUDRATE.$$ = $R.UARTE_BAUDRATE_BAUDRATE_Baud115200
    $R.UARTE0.ENABLE.$$ = $R.UARTE_ENABLE_ENABLE_Enabled
    $R.UARTE0.TXD.PTR.$$ = $cast2<u32>($$(txd_buf))
    $R.UARTE0.TXD.MAXCNT.$$ = 1
}


