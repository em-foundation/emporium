import '@$$emscript'
export const $T = $declare('TEMPLATE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as Aux from '@emm.mcu.9305/EdgeAux.em'
import * as EdgeI from '@em.hal/EdgeI.em'
import * as GpioI from '@em.hal/GpioI.em'

export namespace em$template {
    export const $U = $declare('MODULE', EdgeI)

    export const Pin = $proxy<GpioI.$I>()
    export const pin_num = $config<i16>()

    const pin_chan = $config<u8>()

    export namespace em$meta {
        export function setDetectHandler(h: EdgeI.Handler) {
            let hi = Aux.HandlerInfo.$make()
            hi.handler = h
            Aux.em$meta.addHandlerInfo(hi)
        }
    }

    const pid = pin_num & 0xff
    const mask = 1 << pid

    export function clearDetect(): void {
        $R.PML.RegPmlPadWake.$$ &= ~(mask << $R.PML_PAD_WAKE_EN_SHIFT)
    }

    export function disableDetect(): void {
        $R.PML.RegPmlPadWake.$$ &= ~(mask << $R.PML_PAD_WAKE_EN_SHIFT)
    }

    export function enableDetect(): void {
        $R.IRQ.RegIRQGPIOStsClr.$$ = mask
        $R.IRQ.RegIRQGPIOMskSet.$$ = mask
        $R.IRQ.RegIRQGPIOEnSet.$$ = mask
        $R.PML.RegPmlPadWake.$$ |= (mask << $R.PML_PAD_WAKE_EN_SHIFT)
    }

    export function getState(): bool_t {
        return Pin.get()
    }

    export function init(pullup: bool_t) {
        Pin.makeInput()
        Pin.setInternalPullup(pullup)
        clearDetect()
    }

    export function setDetectFalling() {
        $R.PML.RegPmlPadWake.$$ &= ~(mask << $R.PML_PAD_WAKE_POL_SHIFT)
        $R.GPIO.RegGPIOIRQPolarity.$$ &= ~mask
    }

    export function setDetectRising() {
        $R.PML.RegPmlPadWake.$$ |= (mask << $R.PML_PAD_WAKE_POL_SHIFT)
        $R.GPIO.RegGPIOIRQPolarity.$$ |= mask
    }
}

export function $clone() {
    return { $T, ...em$template }
}
