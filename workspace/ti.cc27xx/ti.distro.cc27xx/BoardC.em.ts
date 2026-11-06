import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Console from '@em.lang/Console.em'
import * as Debug from '@em.lang/Debug.em'
import * as Common from '@em.mcu/Common.em'
import * as Poller from '@em.mcu/Poller.em'
import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as LedT from '@em.utils/LedT.em'
import * as ConsoleUart0 from '@ti.mcu.cc27xx/ConsoleUart0.em'
import * as GpioT from '@ti.mcu.cc27xx/GpioT.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'
import * as Mcu from '@ti.mcu.cc27xx/Mcu.em'
import * as OneShot from '@ti.mcu.cc27xx/OneShotGpt3.em'

export { OneShot }

export const AppLed = $clone(LedT)
const AppLedPin = $clone(GpioT)
const AppOutPin = $clone(GpioT)
const DbgA = $clone(GpioT)
const DbgB = $clone(GpioT)
const DbgC = $clone(GpioT)
const DbgD = $clone(GpioT)
export const SysLed = $clone(LedT)
const SysLedPin = $clone(GpioT)

const BRD_DEFAULTS = {
    activeLowLeds: false,
    baudRate: 115200,
    clockFreq: 96000000,
    pins: {
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
    const brd = $board(BRD_DEFAULTS)
    $using(BoardController)
    $using(Console)
    AppLed.Pin.$$dlg = AppLedPin
    AppLed.active_low.$$val = brd.activeLowLeds
    AppLedPin.pin_num.$$val = brd.pins.appLed
    AppOutPin.pin_num.$$val = brd.pins.appOut
    BoardController.Led.$$dlg = SysLed
    // Saleae measured 494.81 ms at scalar 19 for a requested 500 ms.
    BusyWait.scalar.$$val = 20
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart0
    Common.GlobalInterrupts.$$dlg = GlobalInterrupts
    Common.Idle.$$dlg = Idle
    Common.Mcu.$$dlg = Mcu
    ConsoleUart0.TxPin.$$dlg = AppOutPin
    // UART reference clock is half the board clock. The divisor has six fractional bits.
    ConsoleUart0.baud_div.$$val = Math.round(2 * brd.clockFreq / brd.baudRate)
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
