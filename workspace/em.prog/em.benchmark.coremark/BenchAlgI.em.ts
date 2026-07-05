import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as UT from '@em.benchmark.coremark/Utils.em'

export interface $I {
    kind(): UT.Kind
    print(): void
    run(arg: i16): UT.sum_t
    setup(): void
}
