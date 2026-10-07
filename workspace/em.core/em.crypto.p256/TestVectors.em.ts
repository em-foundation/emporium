import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Engine from '@em.crypto.p256/Engine.em'
import * as Mem from '@em.utils/Mem.em'
import * as T from '@em.crypto.p256/Types.em'

const K_TEST = $config<T.U256>()
const PUBLIC_X_EXPECTED = $config<T.U256>()
const PUBLIC_Y_EXPECTED = $config<T.U256>()
const PEER_X_TEST = $config<T.U256>()
const PEER_Y_TEST = $config<T.U256>()
const SECRET_EXPECTED = $config<T.U256>()

export namespace em$meta {

    export function em$construct() {
        T.em$meta.initU256(K_TEST.$$val, 'c88f01f5_10d9ac3f_70a292da_a2316de5_44e9aab8_afe84049_c62a9c57_862d1433')
        T.em$meta.initU256(PUBLIC_X_EXPECTED.$$val, 'dad0b653_94221cf9_b051e1fe_ca5787d0_98dfe637_fc90b9ef_945d0c37_72581180')
        T.em$meta.initU256(PUBLIC_Y_EXPECTED.$$val, '5271a046_1cdb8252_d61f1c45_6fa3e59a_b1f45b33_accf5f58_389e0577_b8990bb3')
        T.em$meta.initU256(PEER_X_TEST.$$val, 'd12dfb52_89c8d4f8_1208b702_70398c34_2296970a_0bccb74c_736fc755_4494bf63')
        T.em$meta.initU256(PEER_Y_TEST.$$val, '56fbf3ca_366cc23e_8157854c_13c58d6a_ac23f046_ada30f83_53e74f33_039872ab')
        T.em$meta.initU256(SECRET_EXPECTED.$$val, 'd6840f6b_42f6edaf_d13116e0_e1256520_2fef8e9e_ce7dce03_812464d0_4b9442de')
    }
}

//>> ---- em$targ ---- <<//

function equal(a: T.U256_Ref, b: T.U256_Ref): bool_t {
    for (const i of $range(T.U256_LEN)) {
        if (a[i] != b[i]) return false
    }
    return true
}

function testMakePublicKey() {
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), K_TEST.$ptr(), $sizeof<T.U256>())

    let pk = T.PubKey.$make()
    $['%%d+']
    Common.UsCounter.start()
    Engine.makePublicKey(sk, $$(pk))
    const usecs = Common.UsCounter.stop()
    $['%%d-']

    if (!equal(pk.x.$ptr(), PUBLIC_X_EXPECTED.$ptr())) {
        printf`FAIL makePublicKey.x\n`()
        T.print(pk.x.$ptr(), t$`actual`)
        T.print(PUBLIC_X_EXPECTED.$ptr(), t$`expected`)
    } else if (!equal(pk.y.$ptr(), PUBLIC_Y_EXPECTED.$ptr())) {
        printf`FAIL makePublicKey.y\n`()
        T.print(pk.y.$ptr(), t$`actual`)
        T.print(PUBLIC_Y_EXPECTED.$ptr(), t$`expected`)
    } else {
        printf`PASS makePublicKey (%d usecs)\n`(usecs)
    }
}

function testEcdh() {
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), K_TEST.$ptr(), $sizeof<T.U256>())

    let peer = T.PubKey.$make()
    Mem.cpy(peer.x.$ptr(), PEER_X_TEST.$ptr(), $sizeof<T.U256>())
    Mem.cpy(peer.y.$ptr(), PEER_Y_TEST.$ptr(), $sizeof<T.U256>())

    let secret = T.U256.$make()
    $['%%d+']
    Common.UsCounter.start()
    Engine.ecdh(sk, $$(peer), secret.$ptr())
    const usecs = Common.UsCounter.stop()
    $['%%d-']

    if (!equal(secret.$ptr(), SECRET_EXPECTED.$ptr())) {
        printf`FAIL ecdh\n`()
        T.print(secret.$ptr(), t$`actual`)
        T.print(SECRET_EXPECTED.$ptr(), t$`expected`)
    } else {
        printf`PASS ecdh          (%d usecs)\n`(usecs)
    }
}

export function em$run() {
    testMakePublicKey()
    testEcdh()
}
