import '@$$emscript'
export const $U = $declare('MODULE')

import * as Crypto from '@em.crypto/Crypto.em'
import * as CryptoC from '@$distro/CryptoC.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Mem from '@em.utils/Mem.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'
import * as T from '@em.crypto.p256/Types.em'
import * as TickerMgr from '@em.utils/TickerMgr.em'
import * as TT from '@em.utils/TimeTypes.em'

export const interval_ms = $config<u16>(1000)
export const public_key_only = $config<bool_t>(false)
// Observe sleep current before CRACEN has ever been enabled.
export const baseline_ticks = $config<u8>(3)

const ticker = $config<TickerMgr.Obj>()
const SK = $config<T.U256>()
const PEER = $config<T.PubKey>()
const EXPECT_X = $config<T.U256>()
const EXPECT_Y = $config<T.U256>()
const EXPECT_SECRET = $config<T.U256>()

export namespace em$meta {
    export function em$configure() {
        $using(CryptoC)
        P256Cracen.verify_microcode.$$val = false
    }
    export function em$construct() {
        ticker.$$val = TickerMgr.em$meta.create()
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

var quiet_ticks: u8 = 0
var preflight_done: bool_t = false

export function em$run() {
    // No crypto preflight here: it would contaminate the pre-CRACEN baseline.
    printf`CRACEN sleepy: %d baseline ticks, then %s every %d ms\n`(
        baseline_ticks, public_key_only ? t$`public key` : t$`ECDH`, interval_ms)
    ticker.$$.start(TT.Secs30p2_initMsecs(interval_ms), $cb(tickCB))
    FiberMgr.run()
}

function tickCB() {
    if (quiet_ticks < baseline_ticks) {
        quiet_ticks += 1
        return
    }
    $['%%d+']
    doWork()
    $['%%d-']
    // Validate only the first active cycle, outside the workload marker.
    // Its one-time print is outside later steady-state measurement cycles.
    if (preflight_done) return
    const pass = public_key_only
        ? (equal(public_key.x.$ptr(), EXPECT_X.$ptr()) && equal(public_key.y.$ptr(), EXPECT_Y.$ptr()))
        : equal(secret.$ptr(), EXPECT_SECRET.$ptr())
    if (!pass) {
        printf`FAIL CRACEN sleepy preflight\n`()
        fail()
        return
    }
    preflight_done = true
    printf`PASS CRACEN sleepy preflight; subsequent cycles quiet\n`()
}

function doWork() {
    // The marked energy boundary includes input staging, load/initialization,
    // arithmetic (including ECDH peer validation), operand clearing and shutdown.
    let sk = T.U256.$make()
    Mem.cpy(sk.$ptr(), SK.$ptr(), $sizeof<T.U256>())
    P256Cracen.initialize()
    if (public_key_only) {
        Crypto.P256.makePublicKey(sk, $$(public_key))
    } else {
        let peer = T.PubKey.$make()
        Mem.cpy(peer.x.$ptr(), PEER.x.$ptr(), $sizeof<T.U256>())
        Mem.cpy(peer.y.$ptr(), PEER.y.$ptr(), $sizeof<T.U256>())
        Crypto.P256.ecdh(sk, $$(peer), secret.$ptr())
    }
    P256Cracen.shutdown()
}

function equal(a: T.U256_Ref, b: T.U256_Ref): bool_t {
    for (const i of $range(T.U256_LEN)) {
        if (a[i] != b[i]) return false
    }
    return true
}