import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@ti.distro.cc27xx/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

const GREEN_LED_PIN = 12

export function em$run() {
    $R.CLKCTL.CLKENSET0.$$ |= $R.CLKCTL_CLKENSET0_GPIO
    const mask = 1 << GREEN_LED_PIN
    $R.IOC.IOC12.$$ = $R.IOC_IOC12_PORTCFG_BASE | $R.IOC_IOC12_PULLCTL_PULL_DIS
    $R.GPIO.DOUTSET31_0.$$ = mask
    $R.GPIO.DOE31_0.$$ |= mask

    // CC27xx GPIO pads on the VDDIO segment need a separate enable.
    $R.PMCTL.AONRSET1.$$ = $R.PMCTL_AONRSET1_VDDIOPGIO_SET
}
