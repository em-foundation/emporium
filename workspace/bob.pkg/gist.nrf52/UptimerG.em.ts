import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    const t0 = Common.Uptimer.$$.read()
    Common.BusyWait.$$.wait(500_000)
    const t1 = Common.Uptimer.$$.read()
    printf`t0 = %08x:%08x, t1 = %08x:%08x\n`(t0.secs, t0.subs, t1.secs, t1.subs)
}