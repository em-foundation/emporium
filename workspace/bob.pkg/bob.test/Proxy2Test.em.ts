import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as BusyWaitI from '@em.hal/BusyWaitI.em'
import * as BusyWaitM from '@em.utils/BusyWait.em'

const Prx = $proxy<BusyWaitI.$I>()
const Prx2 = $proxy2<BusyWaitI.$I>()

export namespace em$meta {
    export function em$configure() {
        Prx.$$ = BusyWaitM
        Prx2.$bind(BusyWaitM)
        // console.log(BusyWaitX.$deleg)
        // BusyWaitX.$bind(BusyWaitM)
        // console.log(BusyWaitX.$deleg)
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Prx.$$.wait(1000)
    Prx2.wait(1000)
}