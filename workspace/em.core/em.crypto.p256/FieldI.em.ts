import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.crypto.p256/Types.em'

export interface $I {
    add(a: T.U256_Ref, b: T.U256_Ref): void
    addPointJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>): void
    copy(a: T.U256_Ref, b: T.U256_Ref): void
    doublePoint(p: $$<T.PointJ>): void
    half(a: T.U256_Ref): void
    inv(a: T.U256_Ref): void
    mul(a: T.U256_Ref, b: T.U256_Ref): void
    square(a: T.U256_Ref): void
    sub(a: T.U256_Ref, b: T.U256_Ref): void
    times2(a: T.U256_Ref): void
}
