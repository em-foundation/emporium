import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    e$`RESETS_CLR->RESET = RESETS_RESET_io_bank0_Msk | RESETS_RESET_pads_bank0_Msk`
    e$`IO_BANK0->GPIO15_CTRL = IO_BANK0_GPIO15_CTRL_FUNCSEL_sio_15`
    e$`SIO->GPIO_OE_SET = (1 << 15)`
    e$`SIO->GPIO_OUT_SET = (1 << 15)`
}