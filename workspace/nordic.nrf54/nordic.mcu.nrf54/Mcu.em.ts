import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

const use_sram = $config<bool_t>()

export namespace em$meta {
    export function em$construct() {
        use_sram.$$val = $property('em.build.BootFlash', false)
    }
}

export function startup(): void {
    e$`NRF_OSCILLATORS_S->PLL.FREQ = 1` // 128 MHz
    // e$`NRF_OSCILLATORS_S->PLL.FREQ = 3` // 64 MHz
    // $reg32[0x5005340C] = 1  // errata 37
    unprotect()
    e$`SCB->NSACR |= (3UL << 10ul)`  // FPU
    for (const i of $range($R.FICR_TRIMCNF_MaxCount)) {
        const addr = $R.FICR.TRIMCNF[i].ADDR.$$
        if (addr == 0xFFFFFFFF || addr == 0) break
        $reg32[addr] = $R.FICR.TRIMCNF[i].DATA.$$
    }
    // if ($reg32[0x50120440] == 0x00) { // ES PDK
    //     $reg32[0x50120440] = 0xC8
    // }
    // if ($reg32[0x00FFC334] <= 0x180A1D00) { // errata 32
    //     $reg32[0x50120640] = 0x1EA9E040
    // }
    // $reg32[0x5008A7AC] = 0x040A0078  // errata 40
    // $reg32[0x50120624] = (20 | (1 << 5)) // errata 31
    // $reg32[0x5012063C] &= ~(1 << 19) // errata 31
    if ($R.RESET.RESETREAS.$$ & $R.RESET_RESETREAS_RESETPIN_Msk) {
        $R.RESET.RESETREAS.$$ = ~$R.RESET_RESETREAS_RESETPIN_Msk
    }
    $R.RRAMC.POWER.LOWPOWERCONFIG.$$ = $R.RRAMC_POWER_LOWPOWERCONFIG_MODE_PowerOff
    e$`NRF_GLITCHDET_S->CONFIG = (GLITCHDET_CONFIG_ENABLE_Disable << GLITCHDET_CONFIG_ENABLE_Pos)`
    e$`NRF_APPLICATION_ICACHE_S->ENABLE = 1`
    if (!use_sram) {
        $R.MEMCONF.POWER[0].CONTROL.$$ = 0x80 // retain 16K sram
        $R.MEMCONF.POWER[0].RET.$$ = 0x80
        $R.MEMCONF.POWER[0].RET2.$$ = 0x00

    } else {
        $R.MEMCONF.POWER[0].CONTROL.$$ = 0x82 // retain 64K sram
        $R.MEMCONF.POWER[0].RET.$$ = 0x82
        $R.MEMCONF.POWER[0].RET2.$$ = 0x0
    }
    $R.MEMCONF.POWER[1].CONTROL.$$ = 0x0
    $R.MEMCONF.POWER[1].RET.$$ = 0x0
    $R.MEMCONF.POWER[1].RET2.$$ = 0x0
    $R.CLOCK.LFCLK.SRC.$$ = $R.CLOCK_LFCLK_SRC_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    while ($R.CLOCK.EVENTS_LFCLKSTARTED.$$ == 0) { }
    $R.REGULATORS.VREGMAIN.DCDCEN.$$ = 1
    Debug.startup()
    $['%%a:'](2)
}

export function isWarm(): bool_t {
    return false
}

function unprotect() {
    const CLEAR: u32 = (
        $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Clear << $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Pos |
        $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY << $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos
    )
    const OPEN: u32 = (
        $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_High << $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_Pos |
        $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Disabled << $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Pos |
        $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY << $R.TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos
    )
    $R.TAMPC.PROTECT.DOMAIN[0].DBGEN.CTRL.$$ = CLEAR
    $R.TAMPC.PROTECT.DOMAIN[0].DBGEN.CTRL.$$ = OPEN
    $R.TAMPC.PROTECT.DOMAIN[0].NIDEN.CTRL.$$ = CLEAR
    $R.TAMPC.PROTECT.DOMAIN[0].NIDEN.CTRL.$$ = OPEN
    $R.TAMPC.PROTECT.DOMAIN[0].SPIDEN.CTRL.$$ = CLEAR
    $R.TAMPC.PROTECT.DOMAIN[0].SPIDEN.CTRL.$$ = OPEN
    $R.TAMPC.PROTECT.DOMAIN[0].SPNIDEN.CTRL.$$ = CLEAR
    $R.TAMPC.PROTECT.DOMAIN[0].SPNIDEN.CTRL.$$ = OPEN
    $R.TAMPC.PROTECT.AP[0].DBGEN.CTRL.$$ = CLEAR
    $R.TAMPC.PROTECT.AP[0].DBGEN.CTRL.$$ = OPEN
}

