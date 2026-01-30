import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@adi.distro.max326xx/REGS.em'

export function em$run() {
    startup()
    const LED1 = 1 << 25
    e$`MXC_GPIO0->outen_set = LED1`
    e$`MXC_GPIO0->en0_set = LED1`
    e$`MXC_GPIO0->out_set = LED1`
    //
    e$`MXC_GPIO0->out_clr = LED1`
    delay(2000000)
    e$`MXC_GPIO0->out_set = LED1`
    delay(5000000)
    disablePins()
    $R.PWRSEQ.LPCN.$$ |= $R.F_PWRSEQ_LPCN_LPWKST_CLR
    $R.MCR.CTRL.$$ |= $R.F_MCR_CTRL_ERTCO_EN
    e$`SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk`
    $R.GCR.PM.$$ |= $R.S_GCR_PM_MODE_STANDBY
    e$`asm volatile ("wfi")`
}

function delay(cnt: u32) {
    let dummy: volatile_t<u32>
    while (cnt) {
        dummy = 0
        cnt -= 1
    }
}

function disablePins() {
    const mask = 0xffffffff
    $R.GPIO0.PADCTRL0.$$ = mask
    $R.GPIO0.PADCTRL1.$$ = mask
    $R.GPIO0.VSSEL.$$ = ~mask
    $R.GPIO0.INEN.$$ |= mask
    // $R.GPIO0.EN0_SET.$$ = mask
    // $R.GPIO0.OUTEN_SET.$$ = mask
    $R.GPIO0.EN0_SET.$$ = mask
    $R.GPIO0.EN1_CLR.$$ = mask
    $R.GPIO0.EN2_CLR.$$ = mask
    $R.GPIO0.DS0.$$ = ~mask
    $R.GPIO0.DS1.$$ = ~mask
    $R.GPIO0.OUT_SET.$$ = mask
}

export function startup(): void {
    const vrego_A = $R.F_SIMO_VREGO_A_RANGEA | ((1750 - 600) / 10)
    $R.SIMO.VREGO_A.$$ = vrego_A
    $R.SIMO.VREGO_A.$$ = vrego_A
    const vrego_B = $R.F_SIMO_VREGO_B_RANGEB | ((1100 - 600) / 10)
    $R.SIMO.VREGO_B.$$ = vrego_B
    $R.SIMO.VREGO_B.$$ = vrego_B
    const vrego_C = $R.F_SIMO_VREGO_C_RANGEC | ((1100 - 600) / 10)
    $R.SIMO.VREGO_C.$$ = vrego_C
    $R.SIMO.VREGO_C.$$ = vrego_C
    //
    $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_IPO_EN
    while (($R.GCR.CLKCTRL.$$ & $R.F_GCR_CLKCTRL_IPO_RDY) == 0) { }
    $R.GCR.CLKCTRL.$$ |= $R.S_GCR_CLKCTRL_SYSCLK_SEL_IPO
    $R.GCR.CLKCTRL.$$ |= $R.S_GCR_CLKCTRL_SYSCLK_DIV_DIV1
    //
    $R.GCR.PCLKDIS0.$$ &= ~($R.F_GCR_PCLKDIS0_GPIO0)
    // $R.GCR.PCLKDIS0.$$ &= ~($R.F_GCR_PCLKDIS0_GPIO0 | $R.F_GCR_PCLKDIS0_GPIO1)
    $R.LPGCR.PCLKDIS.$$ &= ~($R.F_LPGCR_PCLKDIS_GPIO2)
}