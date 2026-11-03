import '@$$emscript'
export const $U = $declare('MODULE', BasicI)

import * as BasicI from '@em.makem.basic/BasicI.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function showString(text: text_t): void {
    printf`%s\n`(text)
}
