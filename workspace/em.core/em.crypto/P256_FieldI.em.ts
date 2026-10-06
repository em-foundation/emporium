import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.crypto/P256_Types.em'

export interface $I {
    add(a: T.U256_Ref, b: T.U256_Ref): void
    mul(a: T.U256_Ref, b: T.U256_Ref): void
    sub(a: T.U256_Ref, b: T.U256_Ref): void
}
