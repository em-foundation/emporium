import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as UsCounter from '@em.arch.arm/UsCounterSystick.em'
import * as Console from '@em.lang/Console.em'
import * as Debug from '@em.lang/Debug.em'
import * as Common from '@em.mcu/Common.em'
import * as Poller from '@em.mcu/Poller.em'
import * as AlarmMgr from '@em.utils/AlarmMgr.em'
import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as ButtonT from '@em.utils/ButtonT.em'
import * as LedT from '@em.utils/LedT.em'
import * as Uptimer from '@em.utils/UptimerRtc.em'
import * as ConsoleUart0 from '@ti.mcu.cc27xx/ConsoleUart0.em'
import * as EdgeT from '@ti.mcu.cc27xx/EdgeT.em'
import * as ExtFlashDisabler from '@ti.mcu.cc27xx/ExtFlashDisabler.em'
import * as GpioT from '@ti.mcu.cc27xx/GpioT.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'
import * as Mcu from '@ti.mcu.cc27xx/Mcu.em'
import * as OneShot from '@ti.mcu.cc27xx/OneShotGpt3.em'
import * as Rtc from '@ti.mcu.cc27xx/Rtc.em'

export { OneShot }

export const AppBut = $clone(ButtonT)
export const AppButEdge = $clone(EdgeT)
const AppButPin = $clone(GpioT)
export const AppLed = $clone(LedT)
const AppLedPin = $clone(GpioT)
const AppOutPin = $clone(GpioT)
const DbgA = $clone(GpioT)
const DbgB = $clone(GpioT)
const DbgC = $clone(GpioT)
const DbgD = $clone(GpioT)
const FlashCLK = $clone(GpioT)
const FlashCS = $clone(GpioT)
const FlashPICO = $clone(GpioT)
const FlashPOCI = $clone(GpioT)
export const SysLed = $clone(LedT)
const SysLedPin = $clone(GpioT)

const BRD_DEFAULTS = {
    activeLowLeds: false,
    baudRate: 115200,
    clockFreq: 96000000,
    extFlashDisable: false,
    pins: {
        appBut: <i16>-1,
        appLed: <i16>-1,
        appOut: <i16>-1,
        extFlashCLK: <i16>-1,
        extFlashCS: <i16>-1,
        extFlashPICO: <i16>-1,
        extFlashPOCI: <i16>-1,
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
    AlarmMgr.Rtc.$$dlg = Rtc
    AppBut.Edge.$$dlg = AppButEdge
    AppButEdge.Pin.$$dlg = AppButPin
    AppButEdge.pin_num.$$val = AppButPin.pin_num.$$val = brd.pins.appBut
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
    Common.Uptimer.$$dlg = Uptimer
    Common.UsCounter.$$dlg = UsCounter
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
    if (brd.extFlashDisable) {
        $using(ExtFlashDisabler)
        ExtFlashDisabler.CLK.$$dlg = FlashCLK
        ExtFlashDisabler.CS.$$dlg = FlashCS
        ExtFlashDisabler.PICO.$$dlg = FlashPICO
        ExtFlashDisabler.POCI.$$dlg = FlashPOCI
        FlashCLK.pin_num.$$val = brd.pins.extFlashCLK
        FlashCS.pin_num.$$val = brd.pins.extFlashCS
        FlashPICO.pin_num.$$val = brd.pins.extFlashPICO
        FlashPOCI.pin_num.$$val = brd.pins.extFlashPOCI
    }
    Poller.OneShot.$$dlg = OneShot
    SysLed.Pin.$$dlg = SysLedPin
    SysLed.active_low.$$val = brd.activeLowLeds
    SysLedPin.pin_num.$$val = brd.pins.sysLed
    Uptimer.Rtc.$$dlg = Rtc
    UsCounter.MHZ_P.$$val = brd.clockFreq / 1000000
}
