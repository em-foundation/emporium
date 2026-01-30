import '@$$emscript'
export const $U = $declare('MODULE', McuI)

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as McuI from '@em.hal/McuI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function startup(): void {
    //
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_HFXO0
    $R.HFXO0.XTALCFG.$$ = 0x0b200820
    $R.HFXO0.XTALCTRL.$$ = 0x83797907
    $R.HFXO0.CTRL_SET.$$ = $R.HFXO_CTRL_FORCEEN
    while (($R.HFXO0.STATUS.$$ & $R.HFXO_STATUS_RDY) == 0) { }
    $R.CMU.SYSCLKCTRL_SET.$$ = ($R.CMU_SYSCLKCTRL_CLKSEL_HFXO | $R.CMU_SYSCLKCTRL_PCLKPRESC_DIV2)
    //
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_DPLL0
    $R.CMU.DPLLREFCLKCTRL.$$ = $R.CMU_DPLLREFCLKCTRL_CLKSEL_HFXO
    $R.DPLL0.EN.$$ = 0
    $R.DPLL0.CFG.$$ = 0x5 // TODO
    $R.DPLL0.CFG1.$$ = 0x0eff077f // TODO
    $R.DPLL0.EN.$$ = 1
    $R.CMU.SYSCLKCTRL_CLR.$$ = $R._CMU_SYSCLKCTRL_CLKSEL_MASK
    $R.CMU.SYSCLKCTRL_SET.$$ = $R.CMU_SYSCLKCTRL_CLKSEL_HFRCODPLL
    //
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_FSRCO
    $R.CMU.EM01GRPACLKCTRL_SET.$$ = $R.CMU_EM01GRPACLKCTRL_CLKSEL_FSRCO
    //
    $R.CMU.CLKEN0_SET.$$ = $R.CMU_CLKEN0_GPIO
    Debug.startup()
    $['%%a:'](3)
}
