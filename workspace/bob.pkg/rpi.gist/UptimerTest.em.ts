import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    printTime()
    Common.BusyWait.wait(250_000)
    printTime()
}

function printTime() {
    // const lo = $R.TIMER.TIMELR.$$
    // const hi = $R.TIMER.TIMEHR.$$
    // printf`%08d:%08d\n`(hi, lo)
    const raw = Common.Uptimer.read()
    printf`%08x:%08x\n`(raw.secs, raw.subs)
}
