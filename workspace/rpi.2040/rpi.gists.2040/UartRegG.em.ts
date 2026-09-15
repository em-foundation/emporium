import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_OUT_PIN = 0

export function em$run() {
    // setup
    const pid = APP_OUT_PIN
    const mask = 1 << pid
    $R.SIO.GPIO_OE_SET.$$ = mask
    $reg32[e$`IO_BANK0_CTRL_get(pid)`] = 5
    $R.SIO.GPIO_OUT_SET.$$ = mask
    $reg32[e$`IO_BANK0_CTRL_get(pid)`] = 2
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_uart0_Msk
    $R.UART0.UARTCR.$$ = 0
    $R.UART0.UARTIBRD.$$ = 67  // 115200 baud
    $R.UART0.UARTFBRD.$$ = 52  // 115200 baud
    $R.UART0.UARTLCR_H.$$ = (3 << $R.UART0_UARTLCR_H_WLEN_Pos)
    $R.UART0.UARTCR.$$ = $R.UART0_UARTCR_TXE_Msk | $R.UART0_UARTCR_UARTEN_Msk
    // output
    put(c$`h`)
    put(c$`i`)
}

function put(data: u8) {
    $R.UART0.UARTDR.$$ = data
    let delay: volatile_t<u32> = 1000  // ~100 us
    while (delay--) { }
}