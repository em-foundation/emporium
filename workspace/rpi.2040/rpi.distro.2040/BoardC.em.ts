import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BusyWait from '@em.utils/BusyWait.em'
import * as GpioT from '@rpi.mcu.2040/GpioT.em'

export const AppLedPin = $clone(GpioT)
export const SysLedPin = $clone(GpioT)

export const DEFAULTS = {
    activeLowLeds: false,
    pins: {
        appBut: <i16>-1,
        appLed: <i16>-1,
        appOut: <i16>-1,
        sysDbgA: <i16>-1,
        sysDbgB: <i16>-1,
        sysDbgC: <i16>-1,
        sysDbgD: <i16>-1,
        sysLed: <i16>-1,
    }
}

export function em$configure(): void {
    if ($isbare()) return
    const brd = $board(DEFAULTS)
    AppLedPin.pin_num.$$val = brd.pins.appLed
    BusyWait.scalar.$$val = 16
    SysLedPin.pin_num.$$val = brd.pins.sysLed
}