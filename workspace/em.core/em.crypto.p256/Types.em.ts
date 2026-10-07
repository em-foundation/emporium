import '@$$emscript'
export const $U = $declare('MODULE')

export const U256_LEN = 8
export type U256_BASE = u32

export class U256 extends $vector<U256_BASE> { $len = U256_LEN }
export class NAF257 extends $vector<i8> { $len = 257 }

export type U256_Ref = ptr_t<U256_BASE>

export class PubKey extends $struct {
    x: U256
    y: U256
}

export class PointJ extends $struct {
    x: U256
    y: U256
    z: U256
}

export const FIELD_PRIME = $config<U256>()

export namespace em$meta {
    export function initU256(u: U256, val: string) {
        let limbs = val.split('_')
        for (const i of $range(U256_LEN)) {
            u[U256_LEN - i - 1] = Number.parseInt(limbs[i], 16) >>> 0
        }
    }

    export function em$construct() {
        initU256(FIELD_PRIME.$$val, 'ffffffff_00000001_00000000_00000000_00000000_ffffffff_ffffffff_ffffffff')
    }
}

//>> ---- em$targ ---- <<//

a$`always_inline`
export function copyU256(dst: U256_Ref, src: U256_Ref) {
    dst[0] = src[0]
    dst[1] = src[1]
    dst[2] = src[2]
    dst[3] = src[3]
    dst[4] = src[4]
    dst[5] = src[5]
    dst[6] = src[6]
    dst[7] = src[7]
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
