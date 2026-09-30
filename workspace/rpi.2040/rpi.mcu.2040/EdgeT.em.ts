import '@$$emscript'
export const $T = $declare('TEMPLATE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as Aux from '@rpi.mcu.2040/EdgeAux.em'
import * as EdgeI from '@em.hal/EdgeI.em'
import * as GpioI from '@em.hal/GpioI.em'

export namespace em$template {
    export const $U = $declare('MODULE', EdgeI)

    export const Pin = $proxy<GpioI.$I>()
    export const pin_num = $config<i16>()

    const edge_handler = $config<EdgeI.Handler>()

    export namespace em$meta {

        export function em$construct() {
            let hi = Aux.HandlerInfo.$make()
            hi.handler = $cb(handler)
            Aux.em$meta.addHandlerInfo(hi)
        }

        export function setDetectHandler(h: EdgeI.Handler) {
            edge_handler.$$val = h
        }
    }

    //>> ---- em$targ ---- <<//

    const pid = pin_num & 0xff
    const shift = (pid & 0x7) * 4

    let mask = 0

    export function clearDetect(): void {
        $reg32[e$`IO_BANK0_INTR_get(pid)`] = mask
    }

    export function disableDetect(): void {
        $reg32[e$`IO_BANK0_PROC_INTE_get(pid)`] &= ~mask
    }

    export function enableDetect(): void {
        $reg32[e$`IO_BANK0_PROC_INTE_get(pid)`] |= mask
    }

    export function getState(): bool_t {
        return Pin.get()
    }

    export function init(pullup: bool_t) {
        Pin.makeInput()
        if (pullup) {
            Pin.setInternalPullup(true)
            Pin.setInternalPulldown(false)
        } else {
            Pin.setInternalPullup(false)
            Pin.setInternalPulldown(true)
        }
    }

    export function setDetectFalling() {
        mask = $R.IO_BANK0_INTR0_GPIO0_EDGE_LOW_Msk << shift
    }

    export function setDetectRising() {
        mask = $R.IO_BANK0_INTR0_GPIO0_EDGE_HIGH_Msk << shift
    }

    function handler() {
        if (($reg32[e$`IO_BANK0_PROC_INTS_get(pid)`] & mask) && edge_handler != $null) {
            edge_handler()
        }
    }
}

export function $clone() {
    return { $T, ...em$template }
}
