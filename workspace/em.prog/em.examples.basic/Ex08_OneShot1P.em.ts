import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

export const AppLed = $delegate(BoardC.AppLed)
export const OneShot = $delegate(BoardC.OneShot)

var active_flag: volatile_t<bool_t> = false

export function em$run() {
    Common.GlobalInterrupts.enable()
    for (const _ of $range(5)) {
        $['%%d']
        AppLed.on()
        Common.BusyWait.wait(5_000)
        AppLed.off()
        OneShot.uenable(1_000_000, $cb(handler), 0)
        active_flag = true
        while (active_flag) Common.Idle.exec()
    }
}

function handler(arg: arg_t) {
    $['%%c']
    active_flag = false
}
