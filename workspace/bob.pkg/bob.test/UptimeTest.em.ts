import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    $['%%d+']
    Common.BusyWait.$$.wait(500_000)
    $['%%d-']
    let rt = Common.Uptimer.$$.read()
    printf`secs = %d, subs = %x\n`(rt.secs, rt.subs)
}
