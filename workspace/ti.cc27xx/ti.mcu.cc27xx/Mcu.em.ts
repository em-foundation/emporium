import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as McuI from '@em.hal/McuI.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

export function isWarm(): bool_t {
    return false
}

export function startup(): void {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_GPIO
    $R.PMCTL.AONRSET1.$$ = $R.PMCTL_AONRSET1_VDDIOPGIO_SET
}
