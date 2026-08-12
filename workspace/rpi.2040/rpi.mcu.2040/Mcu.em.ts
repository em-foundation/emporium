import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BusyWait from '@em.utils/BusyWait.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

export function isWarm(): bool_t {
    return false
}

export function startup(): void {
    BusyWait.wait(1_000)
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_io_bank0_Msk | $R.RESETS_RESET_pads_bank0_Msk
    Debug.startup()
    // $R.XIP_CTRL.CTRL.$$ = 0
    $['%%a:'](2)
}
