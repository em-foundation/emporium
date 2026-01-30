import em from '@$$emscript'
export const $U = em.$declare('MODULE', FooI)

import * as FooI from '@bob.test/FooI.em'

export namespace em$meta {}

export function em$run() {
    halt()

}
