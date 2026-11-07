import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@ti.distro.cc27xx/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_GPIO | $R.CLKCTL_CLKENSET0_UART0
    $R.IOC.IOC1.$$ = $R.IOC_IOC1_PORTCFG_PFUNC4 | $R.IOC_IOC1_PULLCTL_PULL_DIS
    $R.PMCTL.AONRSET1.$$ = $R.PMCTL_AONRSET1_VDDIOPGIO_SET

    $R.UART0.CTL.$$ = 0
    // TI's 96 MHz clock argument gives a 48 MHz UART reference clock.
    $R.UART0.IBRD.$$ = 26
    $R.UART0.FBRD.$$ = 3
    $R.UART0.LCRH.$$ = $R.UART_LCRH_WLEN_BITL8
    $R.UART0.CTL.$$ = $R.UART_CTL_UARTEN | $R.UART_CTL_TXE

    put(c$`C`)
    put(c$`C`)
    put(c$`2`)
    put(c$`7`)
    put(c$`x`)
    put(c$`x`)
    put(c$` `)
    put(c$`U`)
    put(c$`A`)
    put(c$`R`)
    put(c$`T`)
    put(13)
    put(10)
    while ($R.UART0.FR.$$ & $R.UART_FR_BUSY) { }
}

function put(data: u8): void {
    while ($R.UART0.FR.$$ & $R.UART_FR_TXFF) { }
    $R.UART0.DR.$$ = data
}
