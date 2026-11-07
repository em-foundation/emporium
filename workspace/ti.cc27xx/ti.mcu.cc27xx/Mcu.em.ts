import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as Debug from '@em.lang/Debug.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'
import * as McuI from '@em.hal/McuI.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

const use_sram = $config<bool_t>()

export namespace em$meta {
    export function em$construct() {
        use_sram.$$val = $property('em.build.BootFlash', false)
        Idle.em$meta.addSleepLeave($cb(configureMemory))
    }
}

function configureMemory(): void {
    while ($R.VIMS.CCHSTA.$$ & $R.VIMS_CCHSTA_BUSY) { }
    if (use_sram) {
        $R.CLKCTL.IDLECFG.$$ = $R.CLKCTL_IDLECFG_MODE_LDO_OFF
        $R.VIMS.CCHCTL.$$ = 0
    } else {
        $R.CLKCTL.IDLECFG.$$ = $R.CLKCTL_IDLECFG_MODE_LDO_ON
        $R.VIMS.CCHCTL.$$ = $R.VIMS_CCHCTL_CCHEN_EN
            | $R.VIMS_CCHCTL_LINEN_EN | $R.VIMS_CCHCTL_CNTEN_EN
    }
    while ($R.VIMS.CCHSTA.$$ & $R.VIMS_CCHSTA_BUSY) { }
    e$`__DSB(); __ISB()`
}

export function isWarm(): bool_t {
    return false
}

export function startup(): void {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_GPIO
    $R.PMCTL.AONRSET1.$$ = $R.PMCTL_AONRSET1_VDDIOPGIO_SET
    configureMemory()
    Debug.startup()
    $['%%a:'](2)
}
