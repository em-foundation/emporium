import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const APP_LED_PIN = 9

export function em$run() {
    const mask = 1 << APP_LED_PIN
    e$`NRF_P2_S->DIRSET = mask`
    e$`NRF_P2_S->OUTSET = mask`
}