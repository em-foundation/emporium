import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@ti.distro.cc23xx/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_OUT_PIN = 20

export function em$run() {
    // setup
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_UART0
    const pin = APP_OUT_PIN
    const mask = 1 << pin
    const select = 2
    $R.GPIO.DOESET31_0.$$ = mask
    $R.IOC.IOC0.$[pin].$$ &= ~$R.IOC_IOC0_INPEN
    $R.GPIO.DOUTSET31_0.$$ = mask
    $R.IOC.IOC0.$[pin].$$ = select
    $R.UART0.CTL.$$ &= ~$R.UART_CTL_UARTEN
    $R.UART0.IBRD.$$ = 26
    $R.UART0.FBRD.$$ = 3
    $R.UART0.LCRH.$$ = $R.UART_LCRH_WLEN_BITL8
    $R.UART0.CTL.$$ |= $R.UART_CTL_UARTEN
    // output
    put(c$`h`)
    put(c$`i`)
}

function put(data: u8): void {
    $R.UART0.DR.$$ = data
    while ($R.UART0.FR.$$ & $R.UART_FR_BUSY) { }
}