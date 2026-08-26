import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as BusyWait from '@em.utils/BusyWait.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

const NUM_DESCS = 8
const MSG_SIZE = 0x40
const MSG_WORDS = MSG_SIZE / 4
const CTRL_SIZE = 0x4E8

const CTRL_VERSION = 0x00010000
const DESC_FREE = 3

class Msg extends $vector<u32> {
    $len = MSG_WORDS
}

class MsgVec extends $vector<Msg> {
    $len = NUM_DESCS
}

class Desc extends $struct {
    state: u32
    msg: $$<Msg>
}

class DescVec extends $vector<Desc> {
    $len = NUM_DESCS
}

class RpcList extends $struct {
    count: u32
    descs: DescVec
}

class HostHdr extends $struct {
    version: u32
    data_base: u32
    data_size: u32
    list_a: $$<RpcList>
    list_b: $$<RpcList>
    modem_hdr: u32
    reserved0: u32
    reserved1: u32
}

class ModemHdrRest extends $vector<u32> {
    $len = 13
}

class ModemHdr extends $struct {
    state: u32
    ptr0: u32
    ptr1: u32
    rest: ModemHdrRest
}

class Ctrl extends $struct {
    host: HostHdr          // +0x000, size 0x20
    modem: ModemHdr        // +0x020, size 0x40
    list_a: RpcList        // +0x060, size 0x44
    list_b: RpcList        // +0x0A4, size 0x44
    msgs_a: MsgVec         // +0x0E8, size 0x200
    msgs_b: MsgVec         // +0x2E8, size 0x200
}

const SHMEM_SIZE = 0x2000
const SHMEM_WORDS = SHMEM_SIZE / 4
const TX_RX_PAD_SIZE = 0x80
const TX_RX_PAD_WORDS = TX_RX_PAD_SIZE / 4

class ShmemArea extends $vector<u32> {
    $len = SHMEM_WORDS
}

class TxRxPad extends $vector<u32> {
    $len = TX_RX_PAD_WORDS
}

class SharedMem extends $struct {
    ctrl: Ctrl             // +0x0000, size 0x04E8
    tx: ShmemArea          // +0x04E8, size 0x2000
    pad: TxRxPad           // +0x24E8, size 0x0080
    rx: ShmemArea          // +0x2568, size 0x2000
}

var shmem_tab = $table<SharedMem>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('IPC')

        const shmem = shmem_tab.$$add()
        const ctrl = shmem.$$.ctrl

        ctrl.host.version = CTRL_VERSION
        ctrl.list_a.count = NUM_DESCS
        ctrl.list_b.count = NUM_DESCS

        for (const i of $range(NUM_DESCS)) {
            ctrl.list_a.descs[i].state = DESC_FREE
            ctrl.list_b.descs[i].state = DESC_FREE
        }

        ctrl.host.data_size = SHMEM_SIZE
    }
}

//>> ---- em$targ ---- <<//

// POWER and IPC are made non-secure before either peripheral is touched.
const POWER_PREP = $cast2<ptr_t<u32>>(0x40005068)
const MODEM_STARTN = $cast2<ptr_t<u32>>(0x40005610)
const NVIC_ITNS1 = $cast2<ptr_t<u32>>(0xE000E384)

export function em$startup() {
    // Match the TF-M security attribution before touching POWER or IPC.
    $R.SPU.PERIPHID[5].PERM.$$ = 0      // POWER -> non-secure
    $R.SPU.PERIPHID[42].PERM.$$ = 0     // IPC   -> non-secure

    // TF-M maps the NS SRAM as R/W/X, non-secure, and locked.
    for (const i of $range(4, 32)) {
        $R.SPU.RAMREGION[i].PERM.$$ = 0x107
    }

    // IRQ42 is Non-Secure in the TF-M/Zephyr configuration.
    NVIC_ITNS1[0] |= 1 << 10

    // Enable only after its target security state has been established.
    IntrVec.NVIC_enable(e$`IPC_IRQn`)

    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const rx = $$(shmem.$$.rx)

    ctrl.$$.host.data_base = $cast2<u32>(rx)
    ctrl.$$.host.list_a = $$(ctrl.$$.list_a)
    ctrl.$$.host.list_b = $$(ctrl.$$.list_b)
    ctrl.$$.host.modem_hdr = $cast2<u32>($$(ctrl.$$.modem))
}

export function em$run() {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)

    // libmodem pre-start POWER write, then ~200 us delay.
    POWER_PREP[0] = 1
    BusyWait.wait(200)

    // IPC channel routing used by libmodem.
    $R.IPC.SEND_CNF[1].$$ = 0x02
    $R.IPC.SEND_CNF[3].$$ = 0x08
    $R.IPC.SEND_CNF[5].$$ = 0x20

    $R.IPC.RECEIVE_CNF[0].$$ = 0x01
    $R.IPC.RECEIVE_CNF[2].$$ = 0x04
    $R.IPC.RECEIVE_CNF[4].$$ = 0x10
    $R.IPC.RECEIVE_CNF[6].$$ = 0x40
    $R.IPC.RECEIVE_CNF[7].$$ = 0x80

    $R.IPC.INTENSET.$$ = 0xD5

    // Publish CTRL and clear stale startup/error events.
    $R.IPC.GPMEM[0].$$ = $cast2<u32>(ctrl)
    $R.IPC.GPMEM[1].$$ = 0

    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    $R.SPU.EVENTS_RAMACCERR.$$ = 0
    $R.SPU.EVENTS_PERIPHACCERR.$$ = 0

    // Start the modem through the non-secure POWER alias.
    MODEM_STARTN[0] = 0

    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[2].$$ != 0) {
            printf`modem handshake: state=%08x ptr0=%08x ptr1=%08x\n`(
                ctrl.$$.modem.state,
                ctrl.$$.modem.ptr0,
                ctrl.$$.modem.ptr1
            )
            $R.IPC.EVENTS_RECEIVE[2].$$ = 0
            return
        }
    }

    printf`NO HANDSHAKE ramerr=%x peripherr=%x\n`(
        $R.SPU.EVENTS_RAMACCERR.$$,
        $R.SPU.EVENTS_PERIPHACCERR.$$
    )
}

export function IPC_isr$$() {
    IntrVec.NVIC_clear(e$`IPC_IRQn`)
    fail()
}
