import '@$$emscript'
export const $U = $declare('MODULE', ConsoleUartI)

import * as ConsoleUartI from '@em.hal/ConsoleUartI.em'
import * as GpioI from '@em.hal/GpioI.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

export const TxPin = $proxy<GpioI.$I>()
export const baud_div = $config<u32>()

export function em$startup(): void {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_UART0
    TxPin.functionSelect(4)
    $R.UART0.CTL.$$ = 0
    $R.UART0.IBRD.$$ = baud_div >> 6
    $R.UART0.FBRD.$$ = baud_div & 63
    $R.UART0.LCRH.$$ = $R.UART_LCRH_WLEN_BITL8
    $R.UART0.CTL.$$ = $R.UART_CTL_UARTEN | $R.UART_CTL_TXE
}

export function flush(): void {
    while ($R.UART0.FR.$$ & $R.UART_FR_BUSY) { }
}

export function put(data: u8): void {
    while ($R.UART0.FR.$$ & $R.UART_FR_TXFF) { }
    $R.UART0.DR.$$ = data
}
