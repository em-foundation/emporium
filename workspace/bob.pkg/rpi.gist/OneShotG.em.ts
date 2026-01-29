import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as OneShot from '@rpi.mcu.2040/OneShotAlarm0.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.GlobalInterrupts.enable()
    Common.BusyWait.wait(100000)
    $['%%d']
    OneShot.uenable(1_000_000, $cb(handler), 0)
    // printf`TIMELR = %08x, ALARM0 = %08x\n`($R.TIMER.TIMELR.$$, $R.TIMER.ALARM0.$$)
    // Common.BusyWait.wait(100_000)
    // printf`TIMELR = %08x, ALARM0 = %08x\n`($R.TIMER.TIMELR.$$, $R.TIMER.ALARM0.$$)
    // printf`INTE = %01x, INTS = %01x\n`($R.TIMER.INTE.$$, $R.TIMER.INTS.$$)
    // fail()

    while (true) {
        Common.Idle.exec()
    }
}

function handler(a: arg_t) {
    $['%%c']
    fail()
}