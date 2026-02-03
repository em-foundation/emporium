import '@$$emscript'
export const $T = $declare('TEMPLATE')

import * as $R from '@rpi.distro.2040/REGS.em'

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
        $R.SIO.GPIO_OUT_CLR.$$ = mask
    }

    export function functionSelect(select: u8): void {
        $reg32[e$`IO_BANK0_CTRL_get(pid)`] = select
    }

    export function get(): bool_t {
        return ($R.SIO.GPIO_IN.$$ & mask) ? true : false
    }

    export function isInput(): bool_t {
        return ($R.SIO.GPIO_OE.$$ & mask) == 0
    }

    export function isOutput(): bool_t {
        return ($R.SIO.GPIO_OE.$$ & mask) != 0
    }

    export function makeInput(): void {
        $R.SIO.GPIO_OE_CLR.$$ = mask
        $reg32[e$`IO_BANK0_CTRL_get(pid)`] = 5
        $reg32[e$`PADS_BANK0_GPIO_get(pid)`] |= $R.PADS_BANK0_GPIO0_IE_Msk
        $reg32[e$`PADS_BANK0_GPIO_get(pid)`] &= ~$R.PADS_BANK0_GPIO0_OD_Msk
    }

    export function makeOutput(): void {
        $R.SIO.GPIO_OE_SET.$$ = mask
        $reg32[e$`IO_BANK0_CTRL_get(pid)`] = 5
    }

    export function pinId(): i16 {
        return pid
    }

    export function reset(): void {
        // $R.GPIO.RegGPIOInputEn.$$ &= ~mask
        // $R.GPIO.RegGPIOOutputEn.$$ &= ~mask
    }

    export function set(): void {
        $R.SIO.GPIO_OUT_SET.$$ = mask
    }

    export function setInternalPulldown(enable: bool_t): void {
        if (enable) {
            $reg32[e$`PADS_BANK0_GPIO_get(pid)`] |= $R.PADS_BANK0_GPIO0_PDE_Msk
        } else {
            $reg32[e$`PADS_BANK0_GPIO_get(pid)`] &= ~$R.PADS_BANK0_GPIO0_PDE_Msk
        }
    }

    export function setInternalPullup(enable: bool_t): void {
        if (enable) {
            $reg32[e$`PADS_BANK0_GPIO_get(pid)`] |= $R.PADS_BANK0_GPIO0_PUE_Msk
        } else {
            $reg32[e$`PADS_BANK0_GPIO_get(pid)`] &= ~$R.PADS_BANK0_GPIO0_PUE_Msk
        }
    }

    export function toggle(): void {
        $R.SIO.GPIO_OUT_XOR.$$ = mask
    }
}

export function $clone() {
    return { $T, ...em$template }
}
