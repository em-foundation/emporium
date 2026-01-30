import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    e$`NRF_OSCILLATORS_S->PLL.FREQ = 1` // 128 MHz
    unprotect()
    e$`SCB->NSACR |= (3UL << 10ul)`
    e$`NRF_GLITCHDET_S->CONFIG = (GLITCHDET_CONFIG_ENABLE_Disable << GLITCHDET_CONFIG_ENABLE_Pos)`
    $R.RRAMC.POWER.LOWPOWERCONFIG.$$ = $R.RRAMC_POWER_LOWPOWERCONFIG_MODE_PowerOff
    e$`NRF_APPLICATION_ICACHE_S->ENABLE = 1`
    $R.MEMCONF.POWER[0].CONTROL.$$ = 0x1 // retain 32K sram
    $R.MEMCONF.POWER[1].CONTROL.$$ = 0x0
    $R.CLOCK.LFCLK.SRC.$$ = $R.CLOCK_LFCLK_SRC_SRC_LFXO
    $R.CLOCK.TASKS_LFCLKSTART.$$ = 1
    $R.REGULATORS.VREGMAIN.DCDCEN.$$ = 1
    //
    wink(5_000_000)
    wakeup()
    wink(5_000_000)
    // for (const _ of $range(5)) {
    //     delay(2_000_000)
    //     wink(5_000_000)
    // }
    e$`asm volatile ("isb")`
    e$`asm volatile ("dsb sy")`
    e$`asm volatile ("wfi")`
}

function delay(cnt: u32) {
    let dummy: volatile_t<u32>
    while (cnt) {
        dummy = 0
        cnt -= 1
    }
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

function wakeup() {
    $R.GRTC.TASKS_STOP.$$ = 1
    $R.GRTC.MODE.$$ = $R.GRTC_MODE_SYSCOUNTEREN_Msk
    $R.GRTC.TASKS_START.$$ = 1
    $R.GRTC.CC[0].CCL.$$ = 10000
    $R.GRTC.CC[0].CCH.$$ = 0
    $R.GRTC.CC[0].CCEN.$$ = 1
    $R.GRTC.INTENSET0.$$ = 1
    $R.GRTC.EVENTS_COMPARE[0].$$ = 0
    while ($R.GRTC.EVENTS_COMPARE[0].$$ == 0) { }
}

function wink(ticks: u32) {
    const mask = 1 << 14
    const pn = 1
    $R.P[pn].DIRSET.$$ = mask
    $R.P[pn].OUTSET.$$ = mask
    delay(ticks)
    $R.P[pn].OUTCLR.$$ = mask
}