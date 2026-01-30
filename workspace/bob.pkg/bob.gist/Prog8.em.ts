import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'

export function em$run() {
    Common.ConsoleUart.$$.put(0x65)
    Common.ConsoleUart.$$.put(0x66)
}
