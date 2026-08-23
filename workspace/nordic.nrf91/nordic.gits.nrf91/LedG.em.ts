import '@$$emscript'
export const $U = $declare('MODULE')

//>> ---- em$targ ---- <<//

const MASK = 1 << 0

export function em$run() {
    e$`NRF_P0_NS->DIRSET = MASK`
    e$`NRF_P0_NS->OUTSET = MASK`
}
