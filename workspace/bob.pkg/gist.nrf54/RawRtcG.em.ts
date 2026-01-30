import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.BusyWait.$$.wait(2500000)
    const raw = Common.Uptimer.$$.read()
    printf`secs = %08x, subs = %08x\n`(raw.secs, raw.subs)
}