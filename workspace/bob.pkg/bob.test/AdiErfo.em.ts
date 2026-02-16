import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@maxim.distro.326xx/REGS.em'

export function em$run() {
    $R.GCR.BTLELDOCTRL.$$ |= $R.F_GCR_BTLELDOCTRL_LDORXEN | $R.F_GCR_BTLELDOCTRL_LDOTXEN
    $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_ISO_EN
    while (($R.GCR.CLKCTRL.$$ & $R.F_GCR_CLKCTRL_ISO_RDY) == 0) { }
    $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_ERFO_EN
    while (($R.GCR.CLKCTRL.$$ & $R.F_GCR_CLKCTRL_ERFO_RDY) == 0) { }
    $R.GCR.CLKCTRL.$$ |= $R.S_GCR_CLKCTRL_SYSCLK_SEL_ERFO
}

/*

To use this oscillator as SYS_OSC, the following steps must be followed:
1. Enable the internal secondary oscillator (ISO) by setting GCR_CLKCTRL.iso_en to 1.
2. Wait until GCR_CLKCTRL.iso_rdy reads 1. The ISO is now operating.
3. Enable the ERFO by setting GCR_CLKCTRL.erfo_en to 1.
4. Wait until GCR_CLKCTRL.erfo_rdy reads 1. The ERFO is now operating.
5. Set GCR_CLKCTRL.sysclk_sel = 2. This will select the ERFO as the SYS_OSC.
6. Wait until GCR_CLKCTRL.sysclk_rdy is set. The ERFO is now operating as the SYS_OSC.

*/