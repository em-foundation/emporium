import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as T from '@em.utils/TimeTypes.em'

//>> ---- em$targ ---- <<//

export function em$run() {
    printf`qsecs = %d\n`(T.Secs30p2_initMsecs(1000))
}