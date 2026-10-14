import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 17

export function em$run() {
    const mask = 1 << APP_LED_PIN
    e$`NRF_P0->DIRSET = mask`
    e$`NRF_P0->OUTCLR = mask`
}