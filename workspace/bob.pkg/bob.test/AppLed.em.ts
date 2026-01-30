import em from '@$$emscript'

import * as GpioI from '@em.hal/GpioI.em'
import * as LedI from '@em.hal/LedI.em'

import Poller from '@em.mcu/Poller.em'

namespace em$template {

    export const $U = em.$declare('MODULE')

    const em$_C = {
        Pin: $proxy<GpioI.$I>(),
        active_low: $config<bool_t>(false)
    }

    namespace em$meta {
        export const x_Pin = em$_C.Pin
        export const c_active_low = em$_C.active_low
    }

    namespace em$targ {
        //
        const Pin = em$_C.Pin.$$
        const active_low = em$_C.active_low.$$

        export function em$startup(): void {
            Pin.makeOutput()
            off()
        }

        export function off(): void {
            if (active_low) { Pin.set() } else { Pin.clear() }
        }

        export function on(): void {
            if (active_low) { Pin.clear() } else { Pin.set() }
        }

        export function toggle(): void {
            Pin.toggle()
        }

        export function wink(msecs: u32): void {
            on()
            Poller.pause(msecs)
            off()
        }
    }

    export const $clone = { $U, em$_C, ...em$meta, ...em$targ }
}

export default { ...em$template.$clone }
