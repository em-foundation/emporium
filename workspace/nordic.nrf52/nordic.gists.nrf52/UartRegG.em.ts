import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_OUT_PIN = 6

export function em$run() {
    // setup
    $R.UART0.PSELTXD.$$ = APP_OUT_PIN
    $R.UART0.BAUDRATE.$$ = $R.UART_BAUDRATE_BAUDRATE_Baud115200
    $R.UART0.ENABLE.$$ = $R.UART_ENABLE_ENABLE_Enabled
    $R.UART0.TASKS_STARTTX.$$ = 1
    // output
    put(c$`h`)
    put(c$`i`)
}

function put(data: u8) {
    $R.UART0.TXD.$$ = data
    while ($R.UART0.EVENTS_TXDRDY.$$ == 0) { }
    $R.UART0.EVENTS_TXDRDY.$$ = 0
}