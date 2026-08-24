import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function isWarm(): bool_t {
    return false
}

export function startup(): void {
    Debug.startup()
    $['%%a:'](2)
    $R.NVMC.ICACHECNF.$$ = $R.NVMC_ICACHECNF_CACHEEN_Msk
    $R.POWER.TASKS_LOWPWR.$$ = 1
    $R.POWER.LTEMODEM.FORCEOFF.$$ = 1
    $R.CLOCK.LFCLKSRC.$$ = $R.CLOCK_LFCLKSRCCOPY_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_LFCLKSTARTED.$$ == 0) { }
    $R.CLOCK.EVENTS_LFCLKSTARTED.$$ = 0


}
