import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BusyWait from '@em.utils/BusyWait.em'
import * as Common from '@em.mcu/Common.em'
import * as ConsoleUart from '@nordic.mcu.nrf54.flpr/ConsoleUart3.em'
import * as GpioT from '@nordic.mcu.nrf54/GpioT.em'
import * as LedT from '@em.utils/LedT.em'

export const AppLed = $clone(LedT)
export const AppLedPin = $clone(GpioT)
export const SysLed = $clone(LedT)
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
    AppLed.Pin.$$dlg = AppLedPin
    AppLed.active_low.$$val = brd.activeLowLeds
    AppLedPin.pin_num.$$val = brd.pins.appLed
    BusyWait.scalar.$$val = 13
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart
    SysLed.Pin.$$dlg = SysLedPin
    SysLed.active_low.$$val = brd.activeLowLeds
    SysLedPin.pin_num.$$val = brd.pins.sysLed
}