import em from '@$$emscript'
export const $U = em.$declare('MODULE')

// import * as $R from '@$distro/REGS.em'

export function em$run() {
    const pin = 15 // appLed
    const mask = 1 << pin
    $R.GPIO.DOESET31_0.$$ = mask
    $R.IOC.IOC0.$[pin].$$ &= ~$R.IOC_IOC0_INPEN
    $R.GPIO.DOUTSET31_0.$$ = mask
}
