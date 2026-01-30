import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

//>> ---- em$targ ---- <<//

export function em$run() {
    const pid = 13
    const mask = 1 << pid
    const pn = 1
    $R.P[pn].DIRCLR.$$ = mask
    $R.P[pn].PIN_CNF[pid].$$ |= $R.GPIO_PIN_CNF_PULL_Pullup << $R.GPIO_PIN_CNF_PULL_Pos
}