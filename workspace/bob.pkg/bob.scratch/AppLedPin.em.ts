import em from '@$$emscript'
export const $U = em.$declare('MODULE')

// import * as $R from '@$distro/REGS.em'

const pin = 15
const mask = 1 << pin

export function clear(): void {
    $R.GPIO.DOUTCLR31_0.$$ = mask
}

export function functionSelect(select: u8): void {
    $R.IOC.IOC0.$[pin].$$ = select
}

export function makeOutput(): void {
    $R.GPIO.DOESET31_0.$$ = mask
    $R.IOC.IOC0.$[pin].$$ &= ~$R.IOC_IOC0_INPEN
}

export function set(): void {
    $R.GPIO.DOUTSET31_0.$$ = mask
}

export function toggle(): void {
    $R.GPIO.DOUTTGL31_0.$$ = mask
}
