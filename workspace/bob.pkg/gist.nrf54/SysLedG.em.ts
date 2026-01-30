import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export function em$run() {
    const mask = 1 << 14
    const pn = 1
    $R.P[pn].DIRSET.$$ = mask
    $R.P[pn].OUTSET.$$ = mask
}
