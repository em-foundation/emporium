import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Types from '@bob.test/Types.em'

let PairFac = $factory(Types.Pair.$make())

export namespace em$meta {
    let p0 = PairFac.$create()
    let p1 = PairFac.$create()
    p0.$$.x += 100
    p1.$$.x += 200
    // console.log(PairFac)
}

export function em$run() {
    printf`len = %d\n`(PairFac.$len)
    PairFac[1].x += 200
    for (let i = 0; i < PairFac.$len; i++) printf`x = %d\n`(PairFac[i].x)
}
