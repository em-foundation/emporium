import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    // GPIO
    e$`RESETS_CLR->RESET = RESETS_RESET_io_bank0_Msk | RESETS_RESET_pads_bank0_Msk`
    e$`IO_BANK0->GPIO13_CTRL = IO_BANK0_GPIO13_CTRL_FUNCSEL_sio_13`
    e$`SIO->GPIO_OE_SET = (1 << 13)`
    e$`SIO->GPIO_OUT_SET = (1 << 13)`
    // UART
    e$`RESETS_CLR->RESET = RESETS_RESET_uart0_Msk`
    e$`IO_BANK0->GPIO0_CTRL = IO_BANK0_GPIO0_CTRL_FUNCSEL_uart0_tx`
    e$`UART0->UARTCR = 0`
    e$`UART0->UARTIBRD = 26`
    e$`UART0->UARTFBRD = 3`
    e$`UART0->UARTLCR_H = (3 << 5)` // WLEN=3 => 8-bit
    e$`UART0->UARTCR = (1 << 0) | (1 << 8)` // UARTEN | TXE
    //
    e$`UART0->UARTDR = 'h'`
}