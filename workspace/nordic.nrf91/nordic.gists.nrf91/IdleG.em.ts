import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as BusyWait from '@em.utils/BusyWait.em'

//>> ---- em$targ ---- <<//

export function em$run() {
    // Make absolutely sure the modem domain is off.
    $R.POWER.LTEMODEM.FORCEOFF.$$ = 1
    while ($R.POWER.POWERSTATUS.$$ != 0) { }

    // Variable-latency / low-power mode.
    $R.POWER.TASKS_LOWPWR.$$ = 1

    $R.REGULATORS.DCDCEN.$$ = 1

    // Start the 32.768-kHz crystal.
    $R.CLOCK.EVENTS_LFCLKSTARTED.$$ = 0
    $R.CLOCK.LFCLKSRC.$$ = $R.CLOCK_LFCLKSRCCOPY_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_LFCLKSTARTED.$$ == 0) { }
    $R.CLOCK.EVENTS_LFCLKSTARTED.$$ = 0

    // Release any explicit HFXO request.
    $R.CLOCK.TASKS_HFCLKSTOP.$$ = 1

    const MASK = 1 << 0

    $R.P0.DIRSET.$$ = MASK
    $R.P0.OUTCLR.$$ = MASK   // LED off initially, assuming active high

    e$`asm volatile ("wfi")`

    $R.P0.OUTSET.$$ = MASK   // lights if WFI returns

    while (true) { }

    // // Never return into any distro/board termination code.
    // while (true) {
    //     e$`asm volatile ("wfi")`
    // }
}
