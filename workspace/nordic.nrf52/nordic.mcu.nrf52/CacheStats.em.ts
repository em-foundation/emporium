import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf52/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function print() {
    const hit: u32 = $R.NVMC.IHIT.$$
    const miss: u32 = $R.NVMC.IMISS.$$
    printf`*** cache stats: hit = %d, miss = %d\n`(hit, miss)
}

export function start() {
    $R.NVMC.ICACHECNF.$$ |= $R.NVMC_ICACHECNF_CACHEPROFEN_Msk
    $R.NVMC.IHIT.$$ = 0
    $R.NVMC.IMISS.$$ = 0
}

export function stop() {
    $R.NVMC.ICACHECNF.$$ &= ~$R.NVMC_ICACHECNF_CACHEPROFEN_Msk
}
