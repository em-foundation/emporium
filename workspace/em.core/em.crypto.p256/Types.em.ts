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

    export function em$generate() {
        let out = $outfile('em.crypto.p256/Types-gen.cpp')
        out.addFrag(`
                    |-> namespace em_crypto_p256_Types {
                    |->  
                    |-> __attribute__((always_inline)) inline
                    |-> void copyU256_inline(U256_Ref dst, U256_Ref src) {
                    |->     dst.p_[0] = src.p_[0];
                    |->     dst.p_[1] = src.p_[1];
                    |->     dst.p_[2] = src.p_[2];
                    |->     dst.p_[3] = src.p_[3];
                    |->     dst.p_[4] = src.p_[4];
                    |->     dst.p_[5] = src.p_[5];
                    |->     dst.p_[6] = src.p_[6];
                    |->     dst.p_[7] = src.p_[7];
                    |-> }
                    |->  
                    |-> };
        `)
        out.close()
    }
}

//>> ---- em$targ ---- <<//

export function copyU256(dst: U256_Ref, src: U256_Ref) {
    e$`copyU256_inline(dst, src)`
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
