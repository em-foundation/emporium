import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

export function enable(): void {
    // CC27xx has an automatic HFXT startup state machine.
    $R.CKMD.HFXTCTL.$$ |= $R.CKMD_HFXTCTL_EN
    for (const _ of $range(10000)) {
        if ($R.CKMD.RIS.$$ & $R.CKMD_RIS_AMPSETTLED) return
        Common.BusyWait.wait(1)
    }
    printf`CC27xx HFXT startup timeout\n`()
    fail()
}

export function disable(): void {
    $R.CKMD.HFXTCTL.$$ &= ~($R.CKMD_HFXTCTL_EN | $R.CKMD_HFXTCTL_AUTOEN)
}
