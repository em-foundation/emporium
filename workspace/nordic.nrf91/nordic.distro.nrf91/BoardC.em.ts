import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as Common from '@em.mcu/Common.em'
import * as Console from '@em.lang/Console.em'
import * as ConsoleUart from '@nordic.mcu.nrf91/ConsoleUart0.em'
import * as GpioT from '@nordic.mcu.nrf91/GpioT.em'
import * as LedT from '@em.utils/LedT.em'

export const AppOutPin = $clone(GpioT)
export const SysLed = $clone(LedT)
export const SysLedPin = $clone(GpioT)

export const DEFAULTS = {
    /** setting applies to {app,com,sys}Led pins */ activeLowLeds: false,
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
    $using(BoardController)
    $using(Console)
    AppOutPin.pin_num.$$val = brd.pins.appOut
    BoardController.Led.$$dlg = SysLed
    BusyWait.scalar.$$val = 9
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart
    ConsoleUart.TxPin.$$dlg = AppOutPin
    SysLed.Pin.$$dlg = SysLedPin
    SysLed.active_low.$$val = brd.activeLowLeds
    SysLedPin.pin_num.$$val = brd.pins.sysLed
}

