import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BusyWait from '@em.utils/BusyWait.em'
import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'

export const TxPin = $proxy<GpioI.$I>()

export namespace em$meta {
}

//>> ---- em$targ ---- <<//

export function em$startup() {
    TxPin.makeOutput()
    TxPin.set()
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_uart0_Msk
    const pn = TxPin.pinId()
    $reg32[e$`IO_BANK0_CTRL_get(pn)`] = 2
    $R.UART0.UARTCR.$$ = 0
    $R.UART0.UARTIBRD.$$ = 67
    $R.UART0.UARTFBRD.$$ = 52
    $R.UART0.UARTLCR_H.$$ = (3 << $R.UART0_UARTLCR_H_WLEN_Pos)
    $R.UART0.UARTCR.$$ = $R.UART0_UARTCR_TXE_Msk | $R.UART0_UARTCR_UARTEN_Msk
}

export function flush() {
    BusyWait.wait(100)
}

export function put(data: u8) {
    $['%%d+']
    $R.UART0.UARTDR.$$ = data
    flush()
    $['%%d-']
}
