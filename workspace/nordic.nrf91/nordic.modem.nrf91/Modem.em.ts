import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as BusyWait from '@em.utils/BusyWait.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

import * as T from '@nordic.modem.nrf91/Types.em'

var shmem_tab = $table<T.SharedMem>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('IPC')
        const shmem = shmem_tab.$$add()
        const ctrl = shmem.$$.ctrl
        ctrl.host.version = T.CTRL_VERSION
        ctrl.list_a.count = T.NUM_DESCS
        ctrl.list_b.count = T.NUM_DESCS
        for (const i of $range(T.NUM_DESCS)) {
            ctrl.list_a.descs[i].state = T.DESC_FREE
            ctrl.list_b.descs[i].state = T.DESC_FREE
        }
        ctrl.host.data_size = T.SHMEM_SIZE
    }
}

//>> ---- em$targ ---- <<//

const AT_CEDRXS_OFF = 3
const AT_CEREG = 6
const AT_CFUN_FULL = 5
const AT_CFUN_OFFLINE = 0
const AT_CFUN_POWER_OFF = 7
const AT_CPSMS_ON = 2
const AT_RAI_ON = 4
const AT_SYSTEMMODE_NBIOT = 1
const RECV_RPC = T.IPC_RECV_RPC
const SEND_CTRL = T.IPC_SEND_CTRL
const SEND_RPC = T.IPC_SEND_RPC
const SEND_RAI_LAST = 0x01000000
const SEND_REQ = 0x70060004
const SEND_RSP = 0x80060004
const SOCKET_RSP = 0x80010004

let rpc_tx_seq: u32 = 0

export function em$startup() {
    shmemConstruct()
}

export function handshake() {
    if (transportStart() && rpcAtInit()) {
        modemPostInit()
        $['%%d+']
        if (networkBringUp()) {
            $['%%d-']
            rpcSocketProbe()
            modemShutdown()
        }
    }
}

export function init() {
    // POWER/CLOCK and IPC are assumed non-secure before entry.
    modemPrep()
    platformInit()
}

export function IPC_isr$$() {
    IntrVec.NVIC_clear(e$`IPC_IRQn`)
}

function ipcInit() {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    $R.IPC.SEND_CNF[1].$$ = 0x02
    $R.IPC.SEND_CNF[3].$$ = 0x08
    $R.IPC.SEND_CNF[5].$$ = 0x20
    $R.IPC.RECEIVE_CNF[0].$$ = 0x01
    $R.IPC.RECEIVE_CNF[2].$$ = 0x04
    $R.IPC.RECEIVE_CNF[4].$$ = 0x10
    $R.IPC.RECEIVE_CNF[6].$$ = 0x40
    $R.IPC.RECEIVE_CNF[7].$$ = 0x80
    $R.IPC.INTENSET.$$ = 0xD5
    $R.IPC.GPMEM[0].$$ = $cast2<u32>(ctrl)
    $R.IPC.GPMEM[1].$$ = 0
}

function modemShutdown() {
    if (rpcAtCommand(AT_CFUN_POWER_OFF, false)) {
        printf`MODEM CFUN=0\n`()
    }
}

function modemPostInit() {
    const MODEM_POST = $cast2<ptr_t<u32>>(0x4000506C)
    MODEM_POST[0] = 1
}

function modemPrep() {
    const MODEM_PREP = $cast2<ptr_t<u32>>(0x40005068)
    MODEM_PREP[0] = 1
    BusyWait.wait(200)
}

function platformInit() {
    transportInit()
}


function networkBringUp(): bool_t {
    if (!rpcAtCommand(AT_CFUN_OFFLINE, false) ||
        !rpcAtCommand(AT_SYSTEMMODE_NBIOT, false) ||
        !rpcAtCommand(AT_CPSMS_ON, false) ||
        !rpcAtCommand(AT_CEDRXS_OFF, false) ||
        !rpcAtCommand(AT_RAI_ON, false) ||
        !rpcAtCommand(AT_CFUN_FULL, false)) {
        return false
    }
    for (const i of $range(120)) {
        if (rpcAtCommand(AT_CEREG, true)) {
            printf`MODEM registered\n`()
            return true
        }
        BusyWait.wait(500000)
    }
    printf`MODEM registration timeout\n`()
    return false
}

function rpcDrainAt(kind: u32, want_data: bool_t, done: ptr_t<u32>, okay: ptr_t<u32>, data_seen: ptr_t<u32>): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    let handled = rpcDrainAtList(
        modem.$$.ptr0,
        kind,
        want_data,
        done,
        okay,
        data_seen
    )
    if (rpcDrainAtList(
        modem.$$.ptr1,
        kind,
        want_data,
        done,
        okay,
        data_seen
    )) {
        handled = true
    }
    return handled
}

function rpcDrainAtList(list_addr: u32, kind: u32, want_data: bool_t, done: ptr_t<u32>, okay: ptr_t<u32>, data_seen: ptr_t<u32>): bool_t {
    if (list_addr == 0) {
        return false
    }
    const rx_list = $cast2<ptr_t<u32>>(list_addr)
    const count = rx_list[0]
    let handled = false
    for (const i of $range(16)) {
        if (i >= count) {
            break
        }
        const state = rx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        const rsp = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 2) {
                okay[0] = rsp[6] == 0 ? 1 : 0
                done[0] = 1
                handled = true
            }
            else if (event == 3) {
                data_seen[0] = 1
                if (kind == AT_CEREG) {
                    okay[0] = registrationReady(rsp[2], rsp[3]) ? 1 : 0
                }
                handled = true
            }
        }
        rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
    }
    return handled
}

function rpcAtCommand(kind: u32, want_data: bool_t): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const tx = $cast2<ptr_t<u32>>($$(shmem.$$.tx))
    const flags = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x30)
    let len = 0
    for (const i of $range(6)) {
        tx[i] = 0
    }
    if (kind == AT_CFUN_OFFLINE) {
        tx[0] = 0x432B5441
        tx[1] = 0x3D4E5546
        tx[2] = 0x00000034
        len = 10
    }
    else if (kind == AT_SYSTEMMODE_NBIOT) {
        tx[0] = 0x58255441
        tx[1] = 0x54535953
        tx[2] = 0x4F4D4D45
        tx[3] = 0x303D4544
        tx[4] = 0x302C312C
        tx[5] = 0x0000302C
        len = 23
    }
    else if (kind == AT_CPSMS_ON) {
        tx[0] = 0x432B5441
        tx[1] = 0x534D5350
        tx[2] = 0x0000313D
        len = 11
    }
    else if (kind == AT_CEDRXS_OFF) {
        tx[0] = 0x432B5441
        tx[1] = 0x58524445
        tx[2] = 0x00303D53
        len = 12
    }
    else if (kind == AT_RAI_ON) {
        tx[0] = 0x52255441
        tx[1] = 0x313D4941
        len = 9
    }
    else if (kind == AT_CFUN_FULL) {
        tx[0] = 0x432B5441
        tx[1] = 0x3D4E5546
        tx[2] = 0x00000031
        len = 10
    }
    else if (kind == AT_CFUN_POWER_OFF) {
        tx[0] = 0x432B5441
        tx[1] = 0x3D4E5546
        tx[2] = 0x00000030
        len = 10
    }
    else {
        tx[0] = 0x432B5441
        tx[1] = 0x47455245
        tx[2] = 0x0000003F
        len = 10
    }
    tx_list[1] = T.DESC_ALLOC
    tx_list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = T.RPC_PREAMBLE_AT_REQ
    msg[1] = T.RPC_KIND_REQ
    msg[2] = $cast2<u32>(tx)
    msg[3] = len
    msg[4] = T.RPC_CTRL_SIZE_AT_INIT
    msg[5] = T.RPC_OP_AT_INIT
    flags[0] = 0
    flags[1] = 0
    flags[2] = 0
    $R.IPC.EVENTS_RECEIVE[0].$$ = 0
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    $R.IPC.EVENTS_RECEIVE[4].$$ = 0
    $R.IPC.EVENTS_RECEIVE[6].$$ = 0
    $R.IPC.EVENTS_RECEIVE[7].$$ = 0
    rpcSendData(tx_list, msg)
    for (const outer of $range(2000000)) {
        let fired = false
        if ($R.IPC.EVENTS_RECEIVE[0].$$ != 0) {
            printf`MODEM AT recv: kind=%x ev=0\n`(kind)
            $R.IPC.EVENTS_RECEIVE[0].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[2].$$ != 0) {
            printf`MODEM AT recv: kind=%x ev=2\n`(kind)
            $R.IPC.EVENTS_RECEIVE[2].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[4].$$ != 0) {
            printf`MODEM AT recv: kind=%x ev=4\n`(kind)
            $R.IPC.EVENTS_RECEIVE[4].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[6].$$ != 0) {
            printf`MODEM AT recv: kind=%x ev=6\n`(kind)
            $R.IPC.EVENTS_RECEIVE[6].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[7].$$ != 0) {
            printf`MODEM AT recv: kind=%x ev=7\n`(kind)
            $R.IPC.EVENTS_RECEIVE[7].$$ = 0
            fired = true
        }
        if (fired) {
            rpcDrainAt(
                kind,
                want_data,
                $cast2<ptr_t<u32>>($cast2<u32>(flags) + 0),
                $cast2<ptr_t<u32>>($cast2<u32>(flags) + 4),
                $cast2<ptr_t<u32>>($cast2<u32>(flags) + 8)
            )
        }
        if (flags[0] != 0 && (!want_data || flags[2] != 0)) {
            const tx_state = tx_list[1]
            if ((tx_state & 0xFF) == T.DESC_DONE) {
                tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
            }
            return flags[1] != 0
        }
    }
    printf`MODEM AT timeout: kind=%x txstate=%08x\n`(
        kind,
        tx_list[1]
    )
    return false
}

function registrationReady(addr: u32, len: u32): bool_t {
    if (addr == 0 || len == 0) {
        return false
    }
    const data = $cast2<ptr_t<u8>>(addr)
    for (const i of $range(64)) {
        if (i + 1 >= len) {
            break
        }
        if (data[i] == 0x3A) {
            let j = i + 1
            if (j < len && data[j] == 0x20) {
                j += 1
            }
            if (j < len && (data[j] == 0x31 || data[j] == 0x35)) {
                return true
            }
        }
        if (data[i] == 0x2C &&
            (data[i + 1] == 0x31 || data[i + 1] == 0x35)) {
            return true
        }
    }
    return false
}

function rpcAtInit(): bool_t {
    // Reproduce libmodem's first post-handshake AT control RPC.
    return rpcCall(T.RPC_OP_AT_INIT, T.RPC_CTRL_SIZE_AT_INIT)
}

function rpcCall(opcode: u32, ctrl_size: u32): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    list[1] = T.DESC_ALLOC
    list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = T.RPC_PREAMBLE_REQ
    msg[1] = T.RPC_KIND_REQ
    msg[4] = ctrl_size
    msg[5] = opcode
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    rpcSendData(list, msg)
    return waitForRpc(opcode)
}

function rpcConnectProbe(fd: u32): bool_t {
    // Exact IPv4 connect() request shape from the Zephyr UDP image.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    tx_list[1] = T.DESC_ALLOC
    tx_list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = T.RPC_PREAMBLE_CONNECT_REQ
    msg[1] = 0
    msg[4] = T.RPC_CTRL_SIZE_CONNECT
    msg[5] = 0
    msg[6] = fd
    msg[7] = 0x0004A509
    msg[8] = 0x08080808
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    rpcSendData(tx_list, msg)
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM connect timeout: txstate=%08x\n`(tx_list[1])
        return false
    }
    const rx_list = $cast2<ptr_t<u32>>(modem.$$.ptr1)
    const count = rx_list[0]
    for (const i of $range(16)) {
        if (i >= count) {
            break
        }
        const state = rx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        const rsp = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        const okay = rsp[0] == 0x80020004 && rsp[7] == 0
        printf`MODEM connect: fd=%x errno=%x ok=%x\n`(
            fd,
            rsp[7],
            okay
        )
        rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
        const tx_state = tx_list[1]
        if ((tx_state & 0xFF) == T.DESC_DONE) {
            tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
        }
        $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
        return okay
    }
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    printf`MODEM connect bad response: count=%x txstate=%08x\n`(
        count,
        tx_list[1]
    )
    return false
}

function rpcSendData(tx_list: ptr_t<u32>, msg: ptr_t<u32>) {
    msg[1] = (msg[1] & 0xFFFFFF00) | 2
    const state = tx_list[1]
    tx_list[1] = ((rpc_tx_seq & 0xFFFF) << 16) | (state & 0x0000FF00) | T.DESC_BUSY
    rpc_tx_seq = (rpc_tx_seq + 1) & 0xFFFF
    BusyWait.wait(3)
    $R.IPC.TASKS_SEND[SEND_RPC].$$ = 1
}

function rpcSendProbe(fd: u32): bool_t {
    // Fixed connected UDP send: 20-byte payload with RAI_LAST.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const payload = $cast2<ptr_t<u32>>($cast2<u32>($$(shmem.$$.tx)) + 0x44)
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    for (const i of $range(5)) {
        payload[i] = 0
    }
    tx_list[1] = T.DESC_ALLOC
    tx_list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = SEND_REQ
    msg[1] = 0
    msg[2] = $cast2<u32>(payload)
    msg[3] = 20
    msg[4] = 0x0E
    msg[5] = $cast2<u32>(result)
    msg[6] = 0
    msg[7] = SEND_RAI_LAST
    msg[8] = 0
    result[0] = T.RPC_RESULT_PENDING
    result[1] = 0
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    rpcSendData(tx_list, msg)
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM send timeout: txstate=%08x\n`(tx_list[1])
        return false
    }
    const rx_list = $cast2<ptr_t<u32>>(modem.$$.ptr1)
    const count = rx_list[0]
    for (const i of $range(16)) {
        if (i >= count) {
            break
        }
        const state = rx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        const rsp = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        if (rsp[0] == SEND_RSP) {
            printf`MODEM send rsp: w0=%08x w1=%08x w2=%08x w3=%08x\n`(
                rsp[0],
                rsp[1],
                rsp[2],
                rsp[3]
            )
            printf`MODEM send rsp2: w4=%08x w5=%08x w6=%08x w7=%08x\n`(
                rsp[4],
                rsp[5],
                rsp[6],
                rsp[7]
            )
            printf`MODEM send rsp3: w8=%08x txstate=%08x result=%08x\n`(
                rsp[8],
                tx_list[1],
                result[0]
            )
            rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
            const tx_state = tx_list[1]
            if ((tx_state & 0xFF) == T.DESC_DONE) {
                tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
            }
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            return true
        }
    }
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    printf`MODEM send bad response: count=%x txstate=%08x\n`(
        count,
        tx_list[1]
    )
    return false
}

function rpcSocketProbe(): bool_t {
    // Exact first socket() control request from the Zephyr UDP image.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    tx_list[1] = T.DESC_ALLOC
    tx_list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = T.RPC_PREAMBLE_SOCKET_REQ
    msg[1] = 0
    msg[4] = T.RPC_CTRL_SIZE_SOCKET
    msg[5] = $cast2<u32>(result)
    msg[6] = 0xFFFFFFFF
    msg[7] = 1
    msg[8] = T.RPC_SOCK_DGRAM
    msg[9] = T.RPC_IPPROTO_UDP
    result[0] = T.RPC_RESULT_PENDING
    result[1] = 0
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    rpcSendData(tx_list, msg)
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM socket timeout: txstate=%08x\n`(tx_list[1])
        return false
    }
    const rx_list = $cast2<ptr_t<u32>>(modem.$$.ptr1)
    const count = rx_list[0]
    for (const i of $range(16)) {
        if (i >= count) {
            break
        }
        const state = rx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        const rsp = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        if (rsp[0] == SOCKET_RSP && rsp[5] == $cast2<u32>(result)) {
            result[0] = rsp[8]
            result[1] = rsp[7]
            rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
            const tx_state = tx_list[1]
            if ((tx_state & 0xFF) == T.DESC_DONE) {
                tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
            }
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            printf`MODEM socket: fd=%x errno=%x\n`(
                result[0],
                result[1]
            )
            if (result[1] != 0) {
                return false
            }
            if (!rpcConnectProbe(result[0])) {
                return false
            }
            return rpcSendProbe(result[0])
        }
    }
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    printf`MODEM socket bad response: txstate=%08x\n`(tx_list[1])
    return false
}

function shmemConstruct() {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const rx = $$(shmem.$$.rx)
    ctrl.$$.host.data_base = $cast2<u32>(rx)
    ctrl.$$.host.list_a = $$(ctrl.$$.list_a)
    ctrl.$$.host.list_b = $$(ctrl.$$.list_b)
    ctrl.$$.host.modem_hdr = $cast2<u32>($$(ctrl.$$.modem))
}

function transportInit() {
    ipcInit()
}

function transportStart(): bool_t {
    // STARTN is followed by the first modem response on RECEIVE[2].
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    printf`MODEM start: ctrl=%08x g0=%08x\n`(
        $cast2<u32>(ctrl),
        $R.IPC.GPMEM[0].$$
    )
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    $R.POWER.LTEMODEM.STARTN.$$ = 0
    return waitForHandshake()
}

function waitForHandshake(): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[2].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM timeout: ev2=%x g1=%08x state=%08x\n`(
            $R.IPC.EVENTS_RECEIVE[2].$$,
            $R.IPC.GPMEM[1].$$,
            modem.$$.state
        )
        return false
    }
    let ready = false
    for (const i of $range(2000000)) {
        if (modem.$$.state == 1) {
            ready = true
            break
        }
    }
    printf`MODEM response: state=%08x ptr0=%08x ptr1=%08x\n`(
        modem.$$.state,
        modem.$$.ptr0,
        modem.$$.ptr1
    )
    printf`MODEM response: g0=%08x g1=%08x ready=%x\n`(
        $R.IPC.GPMEM[0].$$,
        $R.IPC.GPMEM[1].$$,
        ready
    )
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    return ready
}


function waitForRpc(opcode: u32): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM rpc timeout: op=%x txstate=%08x\n`(
            opcode,
            tx_list[1]
        )
        return false
    }
    const rx_list = $cast2<ptr_t<u32>>(modem.$$.ptr1)
    const count = rx_list[0]
    for (const i of $range(16)) {
        if (i >= count) {
            break
        }
        const state = rx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        const msg = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        const preamble = msg[0]
        if (preamble == T.RPC_PREAMBLE_RSP &&
            (msg[5] & 0xFF) == (opcode & 0xFF)) {
            rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
            const tx_state = tx_list[1]
            if ((tx_state & 0xFF) == T.DESC_DONE) {
                tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
            }
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            printf`MODEM rpc response: op=%x pre=%08x txstate=%08x\n`(
                opcode,
                preamble,
                tx_state
            )
            return true
        }
    }
    printf`MODEM rpc bad response: op=%x count=%x txstate=%08x\n`(
        opcode,
        count,
        tx_list[1]
    )
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    return false
}

//>> ---- test ---- <<//

export function em$run() {
    init()
    handshake()
}

