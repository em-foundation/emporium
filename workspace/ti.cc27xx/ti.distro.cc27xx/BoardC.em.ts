import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Console from '@em.lang/Console.em'
import * as Common from '@em.mcu/Common.em'
import * as BoardController from '@em.utils/BoardController.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as LedT from '@em.utils/LedT.em'
import * as ConsoleUart0 from '@ti.mcu.cc27xx/ConsoleUart0.em'
import * as GpioT from '@ti.mcu.cc27xx/GpioT.em'
import * as Mcu from '@ti.mcu.cc27xx/Mcu.em'

const AppOutPin = $clone(GpioT)
export const SysLed = $clone(LedT)
const SysLedPin = $clone(GpioT)

const BRD_DEFAULTS = {
    activeLowLeds: false,
    baudRate: 115200,
    clockFreq: 96000000,
    pins: {
        appOut: <i16>-1,
        sysLed: <i16>-1,
    }
}

export function em$configure(): void {
    if ($isbare()) return
    const brd = $board(BRD_DEFAULTS)
    $using(BoardController)
    $using(Console)
    AppOutPin.pin_num.$$val = brd.pins.appOut
    BoardController.Led.$$dlg = SysLed
    // Initial estimate scaled from CC23xx at 48 MHz.
    BusyWait.scalar.$$val = 12
    Common.BusyWait.$$dlg = BusyWait
    Common.ConsoleUart.$$dlg = ConsoleUart0
    Common.GlobalInterrupts.$$dlg = GlobalInterrupts
    Common.Mcu.$$dlg = Mcu
    ConsoleUart0.TxPin.$$dlg = AppOutPin
    // UART reference clock is half the board clock. The divisor has six fractional bits.
    ConsoleUart0.baud_div.$$val = Math.round(2 * brd.clockFreq / brd.baudRate)
    SysLed.Pin.$$dlg = SysLedPin
    SysLed.active_low.$$val = brd.activeLowLeds
    SysLedPin.pin_num.$$val = brd.pins.sysLed
}
