import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as Poller from '@em.mcu/Poller.em'
import * as T from '@em.utils/TimeTypes.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    for (const _ of $range(5)) {
        let cur = T.RawTimeToSecs30p2(Common.Uptimer.read())
        let lim = $R.PML.RegSleepTimCompare0.$$
        printf`cur = %d, lim = %d\n`(cur, lim)
        $R.PML.RegSleepTimCompare0.$$ = cur + 4
        Poller.pause(1000)
    }
}