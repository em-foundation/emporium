import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function disable() {
    $R.LRFDPBE.PDREQ.$$ = $R.LRFDPBE_PDREQ_TOPSMPDREQ_M
    $R.LRFDPBE.ENABLE.$$ = 0
    $R.LRFDPBE.PDREQ.$$ = 0
    //
    $R.LRFDMDM.PDREQ.$$ = $R.LRFDMDM_PDREQ_TOPSMPDREQ_M
    $R.LRFDMDM.ENABLE.$$ = 0
    $R.LRFDMDM.PDREQ.$$ = 0
    //
    $R.LRFDRFE.PDREQ.$$ = $R.LRFDRFE_PDREQ_TOPSMPDREQ_M
    $R.LRFDRFE.ENABLE.$$ = 0
    $R.LRFDRFE.PDREQ.$$ = 0
    //
    // Keep synth REFSYS alive across engine restarts during an exchange.
}

export function enableClocks() {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_LRFD
    let tries: u32 = 0
    while (($R.CLKCTL.CLKCFG0.$$ & $R.CLKCTL_CLKCFG0_LRFD_M) != $R.CLKCTL_CLKCFG0_LRFD_CLK_EN) {
        if (tries++ == 10000) {
            printf`CC27xx LRFD clock timeout, CLKCFG0=%08x\n`($R.CLKCTL.CLKCFG0.$$)
            fail()
        }
        Common.BusyWait.wait(1)
    }
    $R.PMUD.CTL.$$ = $R.PMUD_CTL_CALC_EN | $R.PMUD_CTL_MEAS_EN | $R.PMUD_CTL_HYST_EN_DIS
    tries = 0
    while (($R.PMUD.TEMPUPD.$$ & $R.PMUD_TEMPUPD_STA_M) != $R.PMUD_TEMPUPD_STA_M) {
        if (tries++ == 10000) {
            printf`CC27xx temperature timeout, TEMPUPD=%08x\n`($R.PMUD.TEMPUPD.$$)
            fail()
        }
        Common.BusyWait.wait(1)
    }
    $R.LRFDDBELL.CLKCTL.$$ =
        $R.LRFDDBELL_CLKCTL_BUFRAM_M |
        $R.LRFDDBELL_CLKCTL_DSBRAM_M |
        $R.LRFDDBELL_CLKCTL_RFERAM_M |
        $R.LRFDDBELL_CLKCTL_MCERAM_M |
        $R.LRFDDBELL_CLKCTL_PBERAM_M |
        $R.LRFDDBELL_CLKCTL_RFE_M |
        $R.LRFDDBELL_CLKCTL_MDM_M |
        $R.LRFDDBELL_CLKCTL_PBE_M
    $R.CKMD.HFXTCTL.$$ |= $R.CKMD_HFXTCTL_HPBUFEN
}

// Full-enable restart: standby clears these controls, but light pause does not.
// Keep separate from enableImages(), which also runs during chained exchanges.
export function resetBlocks() {
    $R.LRFDRFE.DLOCTL1.$$ = 0 // disable retained DCO/loop controls first
    $R.LRFDRFE.DLOCTL0.$$ = 0
    $R.LRFDRFE.DCOOVR0.$$ = 0
    $R.LRFDRFE.DCOOVR1.$$ = 0
}

export function enableImages() {
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] = 0
    $R.LRFDPBE.INIT.$$ = $R.LRFDPBE_INIT_MDMF_M | $R.LRFDPBE_INIT_TOPSM_M
    $R.LRFDPBE.ENABLE.$$ = $R.LRFDPBE_ENABLE_MDMF_M | $R.LRFDPBE_ENABLE_TOPSM_M
    $R.LRFDMDM.INIT.$$ = $R.LRFDMDM_INIT_TXRXFIFO_M | $R.LRFDMDM_INIT_TOPSM_M
    $R.LRFDMDM.ENABLE.$$ = $R.LRFDMDM_ENABLE_TXRXFIFO_M | $R.LRFDMDM_ENABLE_TOPSM_M
    $R.LRFDRFE.INIT.$$ = $R.LRFDRFE_INIT_TOPSM_M
    $R.LRFDRFE.ENABLE.$$ = $R.LRFDRFE_ENABLE_TOPSM_M

}
export function disableSynthRefsys(): void {
    $reg32[$R.LRFDRFE32_BASE + $R.LRFDRFE32_O_ATSTREF] &= ~$R.LRFDRFE32_ATSTREF_BIAS_M
}
