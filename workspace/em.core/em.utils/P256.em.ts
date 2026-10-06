import '@$$emscript'
export const $U = $declare('MODULE')

const U256_LEN = 8
type U256_BASE = u32

export class U256 extends $vector<U256_BASE> { $len = U256_LEN }

export type U256_Ref = ptr_t<U256_BASE>

export class PubKey extends $struct {
    x: U256
    y: U256
}

const FIELD_PRIME_INIT = 'FFFFFFFF_00000001_00000000_00000000_00000000_FFFFFFFF_FFFFFFFF_FFFFFFFF'

const FIELD_PRIME = $config<U256>()

export namespace em$meta {
    export function em$construct() {
        let limbs = FIELD_PRIME_INIT.split('_')
        for (const i of $range(U256_LEN)) {
            FIELD_PRIME.$$val[i] = Number.parseInt(limbs[i], 16) >>> 0
        }
    }
}

//>> ---- em$targ ---- <<//

export function validatePublicKey(pk: $$<PubKey>): bool_t {
    return true
}

export function makePublicKey(sk: U256, pk_OUT: $$<PubKey>) {

}

export function ecdh(sk: U256, peer_pk: $$<PubKey>, secret_OUT: U256) {

}

export function print(uref: U256_Ref, lab: text_t = t$``) {
    if (lab.$len > 0) {
        printf`%s = `(lab)
    }
    let sep = t$``
    for (const i of $range(U256_LEN - 1, -1, -1)) {
        printf`%s%08x`(sep, uref[i])
        sep = t$`_`
    }
    printf`\n`()
}

export function em$run() {
    print(FIELD_PRIME.$ptr())


    //    let u = U256.$make()
    //    for (const i of $range(u.$len)) {
    //        u[i] = 0x10 + i
    //    }
    //    print(u.$ptr())
    //    print(u.$ptr(), t$`my_u`)
}
