import '@$$emscript'
export const $U = $declare('MODULE', ActivityI)

import * as ActivityI from '@em.utils/ActivityI.em'
import * as Crypto from '@em.crypto/Crypto.em'
import * as CmacN from '@em.crypto.cmac/CmacN.em'
import * as Engine from '@em.crypto.p256/Engine.em'
import * as MathOpsArmM4 from '@em.crypto.p256/MathOpsArmM4.em'
import * as MathOpsPortable from '@em.crypto.p256/MathOpsPortable.em'
import * as Mem from '@em.utils/Mem.em'
import * as T from '@em.crypto.p256/Types.em'

export const public_key_only = $config<bool_t>(false)
export const portable_math = $config<bool_t>(false)

const SK = $config<T.U256>()
const PEER = $config<T.PubKey>()
const EXPECT_X = $config<T.U256>()
const EXPECT_Y = $config<T.U256>()
const EXPECT_SECRET = $config<T.U256>()

export namespace em$meta {
    export function em$configure() {
        Crypto.Cmac.$$dlg = CmacN
        Crypto.P256.$$dlg = Engine
        if (portable_math.$$val) {
            Engine.MathOps.$$dlg = MathOpsPortable
        } else {
            Engine.MathOps.$$dlg = MathOpsArmM4
        }
    }
    export function em$construct() {
        T.em$meta.initU256(SK.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
        T.em$meta.initU256(PEER.$$val.x, 'd12dfb52_89c8d4f8_1208b702_70398c34_2296970a_0bccb74c_736fc755_4494bf63')
        T.em$meta.initU256(PEER.$$val.y, '56fbf3ca_366cc23e_8157854c_13c58d6a_ac23f046_ada30f83_53e74f33_039872ab')
        T.em$meta.initU256(EXPECT_X.$$val, 'dad0b653_94221cf9_b051e1fe_ca5787d0_98dfe637_fc90b9ef_945d0c37_72581180')
        T.em$meta.initU256(EXPECT_Y.$$val, '5271a046_1cdb8252_d61f1c45_6fa3e59a_b1f45b33_accf5f58_389e0577_b8990bb3')
        T.em$meta.initU256(EXPECT_SECRET.$$val, 'd6840f6b_42f6edaf_d13116e0_e1256520_2fef8e9e_ce7dce03_812464d0_4b9442de')
    }
}

//>> ---- em$targ ---- <<//

var public_key: T.PubKey
var secret: T.U256

export function setup() { }

// Check the final iteration after the runner has closed Debug D. No console
// output or vector comparisons are included in the measured activity.
export function teardown() {
    const pass = public_key_only
        ? (equal(public_key.x.$ptr(), EXPECT_X.$ptr()) && equal(public_key.y.$ptr(), EXPECT_Y.$ptr()))
        : equal(secret.$ptr(), EXPECT_SECRET.$ptr())
    if (!pass) {
        printf`FAIL software P256 final %s result\n`(public_key_only ? t$`public key` : t$`ECDH`)
        fail()
        return
    }
    printf`PASS software P256 final %s result\n`(public_key_only ? t$`public key` : t$`ECDH`)
}

export function exec() {
    // The marked energy boundary includes input staging and software arithmetic.
    // This existing software engine does not implement peer-point validation;
    // CRACEN ECDH includes that additional work. Use the same known-valid peer.
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), SK.$ptr(), $sizeof<T.U256>())
    if (public_key_only) {
        Crypto.P256.makePublicKey(sk, $$(public_key))
    } else {
        let peer = T.PubKey.$make()
        Mem.cpy(peer.x.$ptr(), PEER.x.$ptr(), $sizeof<T.U256>())
        Mem.cpy(peer.y.$ptr(), PEER.y.$ptr(), $sizeof<T.U256>())
        Crypto.P256.ecdh(sk, $$(peer), secret.$ptr())
    }
}

function equal(a: T.U256_Ref, b: T.U256_Ref): bool_t {
    for (const i of $range(T.U256_LEN)) {
        if (a[i] != b[i]) return false
    }
    return true
}