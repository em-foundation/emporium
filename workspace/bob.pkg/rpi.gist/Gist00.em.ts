import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    e$`RESETS_CLR->RESET = RESETS_RESET_io_bank0_Msk | RESETS_RESET_pads_bank0_Msk`
    e$`IO_BANK0->GPIO13_CTRL = IO_BANK0_GPIO13_CTRL_FUNCSEL_sio_13`
    e$`SIO->GPIO_OE_SET = (1 << 13)`
    e$`SIO->GPIO_OUT_SET = (1 << 13)`
}