import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.crypto.p256/Types.em'

export interface em$meta { }

export interface $I {
    ecdh(sk: T.U256, peer_pk: $$<T.PubKey>, secret_OUT: T.U256_Ref): void
    makePublicKey(sk: T.U256, pk_OUT: $$<T.PubKey>): void
    validatePublicKey(pk: $$<T.PubKey>): bool_t
}
