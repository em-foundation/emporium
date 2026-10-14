import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 5

export function em$run() {
    const pid = APP_LED_PIN
    const mask = 1 << pid
    e$`SIO->GPIO_OE_SET = mask`
    $reg32[e$`IO_BANK0_BASE` + (pid * 8) + 4] = 5
    e$`SIO->GPIO_OUT_SET = mask`
}