import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    //
    $R.UART0.PSELTXD.$$ = 5
    $R.UART0.BAUDRATE.$$ = $R.UART_BAUDRATE_BAUDRATE_Baud115200
    $R.UART0.ENABLE.$$ = $R.UART_ENABLE_ENABLE_Enabled
    //
    $R.UART0.TASKS_STARTTX.$$ = 1
    $R.UART0.TXD.$$ = 0xAA
}