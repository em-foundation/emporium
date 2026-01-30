import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.nrf5x/nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    $R.GRTC.TASKS_STOP.$$ = 1
    $R.GRTC.MODE.$$ = $R.GRTC_MODE_SYSCOUNTEREN_Msk
    $R.GRTC.TASKS_START.$$ = 1
    Common.BusyWait.$$.wait(1000)
    let lo: u32
    let hi: u32
    while (true) {
        lo = $R.GRTC.SYSCOUNTER[1].SYSCOUNTERL.$$
        const hi_reg = $R.GRTC.SYSCOUNTER[1].SYSCOUNTERH.$$
        hi = hi_reg & $R.GRTC_SYSCOUNTER_SYSCOUNTERH_VALUE_Msk
        if ((hi & $R.GRTC_SYSCOUNTER_SYSCOUNTERH_OVERFLOW_Msk) != 0) {
            hi - + 1
        }
        if ((hi_reg & $R.GRTC_SYSCOUNTER_SYSCOUNTERH_BUSY_Msk) == 0) break
    }
    printf`hi = %08x, lo = %08x\n`(hi, lo)
}