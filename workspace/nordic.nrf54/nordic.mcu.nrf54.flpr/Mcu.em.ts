import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@nordic.distro.nrf54.flpr/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

//>> ---- em$targ ---- <<//

export function startup(): void {
    $R.CLOCK.LFCLK.SRC.$$ = $R.CLOCK_LFCLK_SRC_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_LFCLKSTARTED.$$ == 0) { }
    $R.REGULATORS.VREGMAIN.DCDCEN.$$ = 1
    Debug.startup()
    $['%%a:'](isWarm() ? 2 : 3)
}

export function isWarm(): bool_t {
    return false
}

export function getResetFlags(): u32 {
    return 0
}
