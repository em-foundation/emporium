import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as Common from '@em.mcu/Common.em'
import * as Console from '@em.lang/Console.em'
import * as ConsoleUart from '@silabs.mcu.efr32x/ConsoleUart0.em'
import * as Debug from '@em.lang/Debug.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as GpioT from '@silabs.mcu.efr32x/GpioT.em'
import * as Idle from '@silabs.mcu.efr32x/Idle.em'
import * as LedT from '@em.utils/LedT.em'
import * as Mcu from '@silabs.mcu.efr32x/Mcu.em'
import * as OneShot from '@silabs.mcu.efr32x/OneShotTimer0.em'
import * as Poller from '@em.mcu/Poller.em'
import * as Uptimer from '@em.hal/UptimerN.em'
import * as UsCounter from '@em.arch.arm/UsCounterSystick.em'

export { OneShot }

export const AppButPin = $clone(GpioT)
export const AppLed = $clone(LedT)
export const AppLedPin = $clone(GpioT)
export const AppOut = $clone(GpioT)
export const DbgA = $clone(GpioT)
export const DbgB = $clone(GpioT)
export const DbgC = $clone(GpioT)
export const DbgD = $clone(GpioT)
export const SysLed = $clone(LedT)
export const SysLedPin = $clone(GpioT)

export const BOARD = {
    /** setting applies to {app,com,sys}Led pins */ activeLowLeds: false,
    pins: {
        appBut: <i16>0xA00,
        appLed: <i16>0xC00,
        appOut: <i16>0xB01,
        sysDbgA: <i16>0xB02,
        sysDbgB: <i16>0xB03,
        sysDbgC: <i16>0xB04,
        sysDbgD: <i16>0xB00,
        sysLed: <i16>0xA04,
    }
}

export function em$configure(): void {
    if ($isbare()) return
    const brd = BOARD
    $using(BoardController)
    $using(Console)
    AppButPin.pin_num.$$val = brd.pins.appBut
    AppLed.Pin.$$dlg = AppLedPin
    AppLed.active_low.$$val = brd.activeLowLeds
    AppLedPin.pin_num.$$val = brd.pins.appLed
    AppOut.pin_num.$$val = brd.pins.appOut
    BoardController.Led.$$dlg = SysLed
    BusyWait.scalar.$$val = 7
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart
    Common.GlobalInterrupts.$$dlg = GlobalInterrupts
    Common.Idle.$$dlg = Idle
    Common.Mcu.$$dlg = Mcu
    Common.Uptimer.$$dlg = Uptimer
    Common.UsCounter.$$dlg = UsCounter
    ConsoleUart.TxPin.$$dlg = AppOut
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
    UsCounter.MHZ_P.$$val = 192
    UsCounter.MHZ_Q.$$val = 5
}

