import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppLed = $delegate(BoardC.AppLed)
const SysLed = $delegate(BoardC.SysLed)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

let count = 5

export function em$run() {
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    e$`asm("nop")`
    // for (const i of $range(5)) {
    //     count = i
    // }
    printf`count = %d\n`(count)
}