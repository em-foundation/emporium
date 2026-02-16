import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@maxim.distro.326xx/REGS.em'

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    $R.GCR.PCLKDIS0.$$ &= ~$R.F_GCR_PCLKDIS0_TMR0
    // const ticks = usecsToTicks(500_000)
    // $['%%>'](ticks)
    $R.TMR0.CMP.$$ = 1000
    $R.TMR0.CTRL1.$$ |= $R.F_TMR_CTRL1_CASCADE | $R.F_TMR_CTRL1_IE_A
    $R.TMR0.CTRL0.$$ = $R.F_TMR_CTRL0_CLKEN_A | $R.S_TMR_CTRL0_CLKDIV_A_DIV_BY_16
    $R.TMR0.CTRL0.$$ |= $R.F_TMR_CTRL0_EN_A
    $['%%a+']
    while (($R.TMR0.INTFL.$$ & $R.F_TMR_INTFL_IRQ_A) == 0) { }
    $['%%a-']
    // printf`cnt = %d\n`($R.TMR0.CNT.$$)
    // while ($R.TMR0.CNT.$$ < 5000) { }
    // printf`ifl = %08x\n`(ifl & $R.F_TMR_INTFL_IRQ_A)
    // printf`intfl = %08x\n`($R.TMR0.INTFL.$$ & $R.F_TMR_INTFL_IRQ_A)
    // Common.BusyWait.$$.wait(100)
    // printf`cnt = %d\n`($R.TMR0.CNT.$$)


    // $R.TMR0.CTRL0.$$ = $R.F_TMR_CTRL0_CLKEN_A | $R.F_TMR_CTRL0_EN_A
    // $R.TMR0.CTRL1.$$ = $R.F_TMR_CTRL1_CLKEN_A | 2

    // printf`ctrl0 = %08x\n`($R.TMR0.CTRL0.$$)
    // printf`ctrl1 = %08x\n`($R.TMR0.CTRL1.$$)

    // printf`cmp = %d\n`($R.TMR0.CMP.$$)
}

function usecsToTicks(us: u32): u32 {
    return (((us * 44) / 3)) - 4
}