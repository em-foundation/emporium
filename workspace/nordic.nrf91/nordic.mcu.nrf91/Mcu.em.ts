import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

const use_sram = $config<bool_t>()

export namespace em$meta {
    export function em$construct() {
        use_sram.$$val = $property('em.build.BootFlash', false)
    }
}

//>> ---- em$targ ---- <<//

export function isWarm(): bool_t {
    return false
}

export function startup(): void {
    Debug.startup()
    $['%%a:'](2)
    //
    if (!use_sram) {
        $R.NVMC.ICACHECNF.$$ = $R.NVMC_ICACHECNF_CACHEEN_Msk
    }
    $R.POWER.TASKS_LOWPWR.$$ = 1
    //
    $R.CLOCK.LFCLKSRC.$$ = $R.CLOCK_LFCLKSRCCOPY_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_LFCLKSTARTED.$$ == 0) { }
    $R.CLOCK.EVENTS_LFCLKSTARTED.$$ = 0
    //
    // $R.VMC.RAM[0].POWERCLR.$$ = 0x0f0f
    // for (const i of $range(2, 8)) {
    //     $R.VMC.RAM[i].POWERCLR.$$ = 0x0f0f
    // }
}
