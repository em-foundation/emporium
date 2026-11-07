import '@$$emscript'
export const $U = $declare('MODULE')

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const GREEN_LED_PIN = 12

export function em$run() {
    e$`HWREG(CLKCTL_BASE + CLKCTL_O_CLKENSET0) |= CLKCTL_CLKENSET0_GPIO`
    const mask = 1 << GREEN_LED_PIN
    e$`HWREG(IOC_BASE + IOC_O_IOC12) = IOC_IOC12_PORTCFG_BASE | IOC_IOC12_PULLCTL_PULL_DIS`
    e$`HWREG(GPIO_BASE + GPIO_O_DOUTSET31_0) = mask`
    e$`HWREG(GPIO_BASE + GPIO_O_DOE31_0) |= mask`

    // CC27xx GPIO pads on the VDDIO segment need a separate enable.
    e$`HWREG(PMCTL_BASE + PMCTL_O_AONRSET1) = PMCTL_AONRSET1_VDDIOPGIO_SET`
}
