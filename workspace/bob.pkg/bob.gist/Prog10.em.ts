import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Console from '@em.lang/Console.em'

export function em$run() {
    Console.wrC(0xAA)
    Console.wrU8(20)
    Console.wrU32(0x12345678)
}
