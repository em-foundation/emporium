import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as Common from '@em.mcu/Common.em'
import * as Console from '@em.lang/Console.em'
import * as ConsoleUart from '@rpi.mcu.2040/ConsoleUart0.em'
import * as Debug from '@em.lang/Debug.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as GpioT from '@rpi.mcu.2040/GpioT.em'
import * as Idle from '@em.hal/IdleN.em'
import * as LedT from '@em.utils/LedT.em'
import * as Mcu from '@rpi.mcu.2040/Mcu.em'
import * as OneShot from '@em.hal/OneShotN.em'
import * as Poller from '@em.mcu/Poller.em'
import * as Uptimer from '@em.hal/UptimerN.em'
import * as UsCounter from '@em.arch.arm/UsCounterSystick.em'

export const AppButPin = $clone(GpioT)
export const AppLed = $clone(LedT)
export const AppLedPin = $clone(GpioT)
export const AppOutPin = $clone(GpioT)
export const DbgA = $clone(GpioT)
export const DbgB = $clone(GpioT)
export const DbgC = $clone(GpioT)
export const DbgD = $clone(GpioT)
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
    $using(BoardController)
    $using(Console)
    const brd = $board(DEFAULTS)
    AppButPin.pin_num.$$val = brd.pins.appBut
    AppLed.Pin.$$dlg = AppLedPin
    AppLed.active_low.$$val = brd.activeLowLeds
    AppLedPin.pin_num.$$val = brd.pins.appLed
    AppOutPin.pin_num.$$val = brd.pins.appOut
    BoardController.Led.$$dlg = SysLed
    BusyWait.scalar.$$val = 16
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart
    Common.GlobalInterrupts.$$dlg = GlobalInterrupts
    Common.Idle.$$dlg = Idle
    Common.Mcu.$$dlg = Mcu
    Common.Uptimer.$$dlg = Uptimer
    Common.UsCounter.$$dlg = UsCounter
    ConsoleUart.TxPin.$$dlg = AppOutPin
    DbgA.pin_num.$$val = brd.pins.sysDbgA
    DbgB.pin_num.$$val = brd.pins.sysDbgB
    DbgC.pin_num.$$val = brd.pins.sysDbgC
    DbgD.pin_num.$$val = brd.pins.sysDbgD
    Debug.DbgA.$$dlg = DbgA
    Debug.DbgB.$$dlg = DbgB
    Debug.DbgC.$$dlg = DbgC
    Debug.DbgD.$$dlg = DbgD
    Poller.OneShot.$$dlg = OneShot
    SysLed.Pin.$$dlg = SysLedPin
    SysLed.active_low.$$val = brd.activeLowLeds
    SysLedPin.pin_num.$$val = brd.pins.sysLed
}