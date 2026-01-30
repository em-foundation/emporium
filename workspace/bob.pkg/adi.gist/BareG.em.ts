import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as IntrVec from '@em.arch.arm/IntrVec.em'

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('WUT')
    }
}

//>> ---- em$targ ---- <<//

import * as $R from '@adi.distro.max326xx/REGS.em'

const RED_LED = 24
const GRN_LED = 25

export function em$run() {
    startup()
    blinkLED(RED_LED)
    busyWait(5000000)
    enableWUT()
    enterSleep()
    blinkLED(GRN_LED)
}

function blinkLED(pin: u32) {
    const mask = 1 << pin
    e$`MXC_GPIO0->outen_set = mask`
    e$`MXC_GPIO0->en0_set = mask`
    e$`MXC_GPIO0->out_set = mask`
    //
    e$`MXC_GPIO0->out_clr = mask`
    busyWait(2000000)
    e$`MXC_GPIO0->out_set = mask`
}

function busyWait(cnt: u32) {
    let dummy: volatile_t<u32>
    while (cnt) {
        dummy = 0
        cnt -= 1
    }
}

function disablePins() {
    const mask = 0xE7F3FFF0
    // const mask = 0xffffffff
    $R.GPIO0.PADCTRL0.$$ = mask
    $R.GPIO0.PADCTRL1.$$ = mask
    $R.GPIO0.VSSEL.$$ = ~mask
    $R.GPIO0.INEN.$$ |= mask
    $R.GPIO0.EN0_SET.$$ = mask
    $R.GPIO0.EN1_CLR.$$ = mask
    $R.GPIO0.EN2_CLR.$$ = mask
    $R.GPIO0.DS0.$$ = ~mask
    $R.GPIO0.DS1.$$ = ~mask
    $R.GPIO0.OUT_SET.$$ = mask
}

function enableWUT() {
    $R.GCR.PM.$$ |= $R.F_GCR_PM_WUT_WE
    $R.GCR.CLKCTRL.$$ |= $R.F_GCR_CLKCTRL_ERTCO_EN
    $R.WUT.CMP.$$ = 32678
    $R.WUT.INTR.$$ = 1
    IntrVec.NVIC_clear(e$`WUT_IRQn`)
    IntrVec.NVIC_enable(e$`WUT_IRQn`)
    $R.WUT.CTRL.$$ = $R.F_WUT_CTRL_TEN
    while ($R.WUT.CNT.$$ < 3) { }
}

function enterSleep() {
    disablePins()
    IntrVec.PRIMASK_set(1)
    $R.PWRSEQ.LPCN.$$ |= $R.F_PWRSEQ_LPCN_LPWKST_CLR
    $R.MCR.CTRL.$$ |= $R.F_MCR_CTRL_ERTCO_EN
    e$`SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk`
    $R.GCR.PM.$$ |= $R.S_GCR_PM_MODE_STANDBY
    e$`asm volatile ("wfi")`
}

function startup(): void {
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
}

export function WUT_isr$$() {
    $R.WUT.INTR.$$ = 1
    IntrVec.NVIC_clear(e$`WUT_IRQn`)
}
