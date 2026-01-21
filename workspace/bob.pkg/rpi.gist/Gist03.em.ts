import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as BoardC from '@rpi.distro.2040/BoardC.em'
import * as BusyWait from '@em.utils/BusyWait.em'

export const AppLedPin = $delegate(BoardC.AppLedPin)
export const SysLedPin = $delegate(BoardC.SysLedPin)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    delayMs(100)
    $R.RESETS_CLR.RESET.$$ = $R.RESETS_RESET_io_bank0_Msk | $R.RESETS_RESET_pads_bank0_Msk
    AppLedPin.makeOutput()
    AppLedPin.clear()
    SysLedPin.makeOutput()
    SysLedPin.clear()
    // GPIO
    for (const _ of $range(10)) {
        AppLedPin.toggle()
        delayMs(200)        
    }
    AppLedPin.clear()
    SysLedPin.set()
    stop()
}

function delayMs(ms: u32) {
    BusyWait.wait(ms * 1000)
}

function stop() {
    while (true) {
        e$`__asm volatile ("bkpt #0")`
    }
}
