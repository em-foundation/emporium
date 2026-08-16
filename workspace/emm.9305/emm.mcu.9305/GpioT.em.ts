import '@$$emscript'
export const $T = $declare('TEMPLATE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as GpioI from '@em.hal/GpioI.em'

export namespace em$template {
    export const $U = $declare('MODULE', GpioI)

    export const pin_num = $config<i16>(-1)

    export namespace em$meta {
        export function pinId(): i16 {
            return pin_num
        }
    }

    const pid: u16 = pin_num & 0xff
    const mask = 1 << pid

    export function clear(): void {
        $R.GPIO.RegGPIODataOutClr.$$ = mask
    }

    export function functionSelect(select: u8): void {
    }

    export function get(): bool_t {
        return ($R.GPIO.RegGPIODataIn.$$ & mask) ? true : false
    }

    export function isInput(): bool_t {
        return ($R.GPIO.RegGPIOInputEn.$$ & mask) != 0
    }

    export function isOutput(): bool_t {
        return ($R.GPIO.RegGPIOOutputEn.$$ & mask) != 0
    }

    export function makeInput(): void {
        $R.GPIO.RegGPIOInputEn.$$ |= mask
        // $R.GPIO.RegGPIOOutputEn.$$ &= ~mask
    }

    export function makeOutput(): void {
        $R.GPIO.RegGPIOOutputEn.$$ |= mask
        // $R.GPIO.RegGPIOInputEn.$$ &= ~mask
    }

    export function pinId(): i16 {
        return pid
    }

    export function reset(): void {
        $R.GPIO.RegGPIOInputEn.$$ &= ~mask
        $R.GPIO.RegGPIOOutputEn.$$ &= ~mask
    }

    export function set(): void {
        $R.GPIO.RegGPIODataOutSet.$$ = mask
    }

    export function setInternalPulldown(enable: bool_t): void {
        $R.GPIO.RegGPIOPdEn.$$ |= mask
        // $R.GPIO.RegGPIOPuEn.$$ &= ~mask
    }

    export function setInternalPullup(enable: bool_t): void {
        $R.GPIO.RegGPIOPuEn.$$ |= mask
        // $R.GPIO.RegGPIOPdEn.$$ &= ~mask
    }

    export function toggle(): void {
        $R.GPIO.RegGPIODataOut.$$ ^= mask
    }
}

export function $clone() {
    return { $T, ...em$template }
}
