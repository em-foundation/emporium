import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as Rtc from '@emm.mcu.9305/RtcSleepTimer.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.GlobalInterrupts.enable()
    Rtc.enable(32768, handler)
    Common.Idle.exec()
}

function handler() {
    $['%%d']
}