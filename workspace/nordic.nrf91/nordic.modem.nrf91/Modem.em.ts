import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

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
const AT_CEREG_ENABLE = 12
const AT_CEREG_QUERY = 10
const AT_CFUN_FULL = 5
const AT_CFUN_POWER_OFF = 7
const AT_CFUN_QUERY = 11
const AT_CPSMS_ON = 2
const AT_CSCON_ON = 13
const AT_FEACONF_000 = 9
const AT_FEACONF_031 = 8
const AT_RAI_ON = 4
const AT_SYSTEMMODE_NBIOT = 1
const AT_XCOEX0 = 14
const RECV_RPC = T.IPC_RECV_RPC
const SEND_CTRL = T.IPC_SEND_CTRL
const SEND_RPC = T.IPC_SEND_RPC
const SEND_RAI_LAST = 0x01000000
const SEND_REQ = 0x70060004
const SEND_RSP = 0x80060004
const SOCKET_RSP = 0x80010004

let rpc_rx_k: u32 = 0
let rpc_rx_list: ptr_t<u32> = $null
let rpc_rx_msg: ptr_t<u32> = $null
let rpc_rx_seq: u32 = 0
let at_tx_busy_mask: u32 = 0
let rpc_rx_state: u32 = 0
let rpc_tx_seq: u32 = 0
let rpc_tx_slot: u32 = 0

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
    rpcAtCommand(AT_CFUN_POWER_OFF, false)
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
    if (!rpcAtCommand(AT_XCOEX0, false) ||
        !rpcAtCommand(AT_SYSTEMMODE_NBIOT, false) ||
        !rpcAtCommand(AT_CPSMS_ON, false) ||
        !rpcAtCommand(AT_FEACONF_000, false) ||
        !rpcAtCommand(AT_FEACONF_031, false) ||
        !rpcAtCommand(AT_CEDRXS_OFF, false) ||
        !rpcAtCommand(AT_RAI_ON, false) ||
        !rpcAtCommand(AT_CEREG_QUERY, true) ||
        !rpcAtCommand(AT_CFUN_QUERY, true) ||
        !rpcAtCommand(AT_CEREG_ENABLE, false) ||
        !rpcAtCommand(AT_CSCON_ON, false) ||
        !rpcAtCommand(AT_CFUN_FULL, false)) {
        return false
    }
    if (!waitForRegistration()) {
        return false
    }
    if (!waitForCsconIdle()) {
        return false
    }
    return true
}

function rpcDrainAt(kind: u32, want_data: bool_t, done: ptr_t<u32>, okay: ptr_t<u32>, data_seen: ptr_t<u32>): bool_t {
    let handled = false
    for (const outer of $range(64)) {
        if (!rpcRxNext()) {
            break
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            handled = true
            continue
        }
        const rsp = rpc_rx_msg
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 2) {
                okay[0] = rsp[6] == 0 ? 1 : 0
                done[0] = 1
            }
            else if (event == 3) {
                data_seen[0] = 1
                if (kind == AT_CEREG) {
                    okay[0] = registrationReady(rsp[2], rsp[3]) ? 1 : 0
                }
                else {
                    okay[0] = 1
                }
                if (rsp[2] != 0) {
                    rpcRxDataFree(rsp[2])
                }
            }
            else if (event == 4) {
                if (rsp[2] != 0) {
                    rpcRxDataFree(rsp[2])
                }
            }
        }
        rpcRxRetire()
        handled = true
        if (done[0] != 0 && (!want_data || data_seen[0] != 0)) {
            return true
        }
    }
    return handled
}

function rpcAtCommand(kind: u32, want_data: bool_t): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const msg = rpcTxAlloc(tx_list, msgs)
    const tx = rpcAtTxAlloc()
    if (tx == $null) {
        return false
    }
    const flags = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x30)
    let len = 0
    for (const i of $range(9)) {
        tx[i] = 0
    }
    if (kind == AT_XCOEX0) {
        tx[0] = 0x58255441
        tx[1] = 0x58454F43
        tx[2] = 0x2C313D30
        tx[3] = 0x35312C31
        tx[4] = 0x312C3536
        tx[5] = 0x00363835
        len = 24
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
        tx[2] = 0x2C2C313D
        tx[3] = 0x3030222C
        tx[4] = 0x30303031
        tx[5] = 0x2C223130
        tx[6] = 0x30303022
        tx[7] = 0x30303030
        tx[8] = 0x00002230
        len = 35
    }
    else if (kind == AT_FEACONF_000) {
        tx[0] = 0x46255441
        tx[1] = 0x4F434145
        tx[2] = 0x303D464E
        tx[3] = 0x302C302C
        len = 17
    }
    else if (kind == AT_FEACONF_031) {
        tx[0] = 0x46255441
        tx[1] = 0x4F434145
        tx[2] = 0x303D464E
        tx[3] = 0x312C332C
        len = 17
    }
    else if (kind == AT_CEDRXS_OFF) {
        tx[0] = 0x432B5441
        tx[1] = 0x58524445
        tx[2] = 0x00333D53
        len = 12
    }
    else if (kind == AT_RAI_ON) {
        tx[0] = 0x52255441
        tx[1] = 0x323D4941
        len = 9
    }
    else if (kind == AT_CEREG_QUERY || kind == AT_CEREG) {
        tx[0] = 0x432B5441
        tx[1] = 0x47455245
        tx[2] = 0x0000003F
        len = 10
    }
    else if (kind == AT_CFUN_QUERY) {
        tx[0] = 0x432B5441
        tx[1] = 0x3F4E5546
        len = 9
    }
    else if (kind == AT_CEREG_ENABLE) {
        tx[0] = 0x432B5441
        tx[1] = 0x47455245
        tx[2] = 0x0000353D
        len = 11
    }
    else if (kind == AT_CSCON_ON) {
        tx[0] = 0x432B5441
        tx[1] = 0x4E4F4353
        tx[2] = 0x0000313D
        len = 11
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
        tx[1] = 0x3D4E5546
        tx[2] = 0x00000034
        len = 10
    }
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
            $R.IPC.EVENTS_RECEIVE[0].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[2].$$ != 0) {
            $R.IPC.EVENTS_RECEIVE[2].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[4].$$ != 0) {
            $R.IPC.EVENTS_RECEIVE[4].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[6].$$ != 0) {
            $R.IPC.EVENTS_RECEIVE[6].$$ = 0
            fired = true
        }
        if ($R.IPC.EVENTS_RECEIVE[7].$$ != 0) {
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
            rpcTxFree(tx_list)
            return flags[1] != 0
        }
    }
    return false
}

function csconIdle(addr: u32, len: u32): bool_t {
    if (addr == 0 || len < 9) {
        return false
    }
    const data = $cast2<ptr_t<u8>>(addr)
    for (const i of $range(64)) {
        if (i + 8 >= len) {
            break
        }
        if (data[i + 0] == 0x2B &&
            data[i + 1] == 0x43 &&
            data[i + 2] == 0x53 &&
            data[i + 3] == 0x43 &&
            data[i + 4] == 0x4F &&
            data[i + 5] == 0x4E &&
            data[i + 6] == 0x3A) {
            let j = i + 7
            if (j < len && data[j] == 0x20) {
                j += 1
            }
            return j < len && data[j] == 0x30
        }
    }
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
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const msg = rpcTxAlloc(list, msgs)
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
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const msg = rpcTxAlloc(tx_list, msgs)
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
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const rsp = rpc_rx_msg
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                rpcRxDataFree(rsp[2])
            }
            rpcRxRetire()
            continue
        }
        if (rsp[0] == 0x80020004 && rsp[6] == fd) {
            const okay = rsp[7] == 0
            rpcRxRetire()
            rpcTxFree(tx_list)
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            return okay
        }
        rpcRxRetire()
    }
    return false
}

function rpcRxFind(list_addr: u32): bool_t {
    if (list_addr == 0) {
        return false
    }
    const list = $cast2<ptr_t<u32>>(list_addr)
    const count = list[0]
    for (const i of $range(32)) {
        if (i >= count) {
            break
        }
        const k = 1 + i * 2
        const state = list[k]
        if ((state & 0xFF) != T.DESC_BUSY) {
            continue
        }
        if (((state >> 16) & 0xFFFF) != (rpc_rx_seq & 0xFFFF)) {
            continue
        }
        rpc_rx_list = list
        rpc_rx_k = k
        rpc_rx_state = state
        rpc_rx_msg = $cast2<ptr_t<u32>>(list[k + 1])
        return true
    }
    return false
}

function rpcRxHandleCtrl() {
    if (!rpcRxIsCtrl()) {
        return
    }
    const type = (rpc_rx_msg[0] >> 16) & 0xFFFF
    if (type == 2) {
        rpcAtTxFree(rpc_rx_msg[2])
    }
    rpcRxRetire()
}

function rpcRxIsCtrl(): bool_t {
    if (rpc_rx_list == $null || rpc_rx_msg == $null) {
        return false
    }
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    return $cast2<u32>(rpc_rx_list) == modem.$$.ptr0
}

function rpcRxNext(): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    rpc_rx_list = $null
    rpc_rx_msg = $null
    if (rpcRxFind(modem.$$.ptr1)) {
        return true
    }
    return rpcRxFind(modem.$$.ptr0)
}

function rpcRxRetire() {
    if (rpc_rx_list == $null) {
        return
    }
    rpc_rx_list[rpc_rx_k] = (rpc_rx_state & 0xFFFFFF00) | T.DESC_FREE
    rpc_rx_seq = (rpc_rx_seq + 1) & 0xFFFF
    rpc_rx_list = $null
    rpc_rx_msg = $null
}

function rpcRxDataFree(data: u32) {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_a))
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_a))
    const count = list[0]
    for (const i of $range(T.NUM_DESCS)) {
        if (i >= count) {
            break
        }
        let state = list[1 + i * 2]
        if ((state & 0xFF) == T.DESC_ALLOC) {
            list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
            state = list[1 + i * 2]
        }
        if ((state & 0xFF) != T.DESC_FREE) {
            continue
        }
        const msg = $cast2<ptr_t<u32>>($cast2<u32>(msgs) + i * T.MSG_WORDS * 4)
        for (const j of $range(T.MSG_WORDS)) {
            msg[j] = 0
        }
        msg[0] = 0x00020001
        msg[1] = 1
        msg[2] = data
        list[2 + i * 2] = $cast2<u32>(msg)
        list[1 + i * 2] = ((rpc_tx_seq & 0xFFFF) << 16) | T.DESC_BUSY
        rpc_tx_seq = (rpc_tx_seq + 1) & 0xFFFF
        BusyWait.wait(3)
        $R.IPC.TASKS_SEND[SEND_CTRL].$$ = 1
        return
    }
}

function rpcTxAlloc(tx_list: ptr_t<u32>, msgs: ptr_t<u32>): ptr_t<u32> {
    const count = tx_list[0]
    for (const i of $range(T.NUM_DESCS)) {
        if (i >= count) {
            break
        }
        const state = tx_list[1 + i * 2]
        if ((state & 0xFF) == T.DESC_FREE) {
            rpc_tx_slot = i
            const msg = $cast2<ptr_t<u32>>($cast2<u32>(msgs) + i * T.MSG_WORDS * 4)
            tx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_ALLOC
            tx_list[2 + i * 2] = $cast2<u32>(msg)
            return msg
        }
    }
    return $null
}

function rpcTxFree(tx_list: ptr_t<u32>) {
    const k = 1 + rpc_tx_slot * 2
    const state = tx_list[k]
    if ((state & 0xFF) == T.DESC_ALLOC) {
        tx_list[k] = (state & 0xFFFFFF00) | T.DESC_FREE
    }
}

function rpcSendData(tx_list: ptr_t<u32>, msg: ptr_t<u32>) {
    msg[1] = (msg[1] & 0xFFFFFF00) | 2
    const k = 1 + rpc_tx_slot * 2
    const state = tx_list[k]
    tx_list[k] = ((rpc_tx_seq & 0xFFFF) << 16) | (state & 0x0000FF00) | T.DESC_BUSY
    rpc_tx_seq = (rpc_tx_seq + 1) & 0xFFFF
    BusyWait.wait(3)
    $R.IPC.TASKS_SEND[SEND_RPC].$$ = 1
}

function rpcSendProbe(fd: u32): bool_t {
    // Fixed connected UDP send: 20-byte payload with RAI_LAST.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const msg = rpcTxAlloc(tx_list, msgs)
    const payload = $cast2<ptr_t<u32>>($cast2<u32>($$(shmem.$$.tx)) + 0x44)
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    for (const i of $range(5)) {
        payload[i] = 0
    }
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
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const rsp = rpc_rx_msg
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                rpcRxDataFree(rsp[2])
            }
            rpcRxRetire()
            continue
        }
        if (rsp[0] == SEND_RSP) {
            rpcRxRetire()
            rpcTxFree(tx_list)
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            return true
        }
        rpcRxRetire()
    }
    return false
}

function rpcSocketProbe(): bool_t {
    // Exact first socket() control request from the Zephyr UDP image.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msgs = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    const msg = rpcTxAlloc(tx_list, msgs)
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
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
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const rsp = rpc_rx_msg
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                rpcRxDataFree(rsp[2])
            }
            rpcRxRetire()
            continue
        }
        if (rsp[0] == SOCKET_RSP && rsp[5] == $cast2<u32>(result)) {
            result[0] = rsp[8]
            result[1] = rsp[7]
            rpcRxRetire()
            rpcTxFree(tx_list)
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            if (result[1] != 0) {
                return false
            }
            if (!rpcConnectProbe(result[0])) {
                return false
            }
            return rpcSendProbe(result[0])
        }
        rpcRxRetire()
    }
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
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    $R.POWER.LTEMODEM.STARTN.$$ = 0
    return waitForHandshake()
}

function rpcAtTxAlloc(): ptr_t<u32> {
    const shmem = $$(shmem_tab[0])
    const base = $cast2<u32>($$(shmem.$$.tx))
    for (const i of $range(4)) {
        const bit = 1 << i
        if ((at_tx_busy_mask & bit) != 0) {
            continue
        }
        at_tx_busy_mask |= bit
        return $cast2<ptr_t<u32>>(base + i * 0x100)
    }
    return $null
}

function rpcAtTxFree(addr: u32) {
    const shmem = $$(shmem_tab[0])
    const base = $cast2<u32>($$(shmem.$$.tx))
    for (const i of $range(4)) {
        if (addr == base + i * 0x100) {
            at_tx_busy_mask &= ~(1 << i)
            return
        }
    }
}

function waitForCsconIdle(): bool_t {
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const rsp = rpc_rx_msg
        let idle = false
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 4) {
                idle = csconIdle(rsp[2], rsp[3])
                if (rsp[2] != 0) {
                    rpcRxDataFree(rsp[2])
                }
            }
            else if (event == 3 && rsp[2] != 0) {
                rpcRxDataFree(rsp[2])
            }
        }
        rpcRxRetire()
        if (idle) {
            return true
        }
    }
    return false
}

function waitForRegistration(): bool_t {
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const rsp = rpc_rx_msg
        let ready = false
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 4) {
                ready = registrationReady(rsp[2], rsp[3])
                if (rsp[2] != 0) {
                    rpcRxDataFree(rsp[2])
                }
            }
            else if (event == 3 && rsp[2] != 0) {
                rpcRxDataFree(rsp[2])
            }
        }
        rpcRxRetire()
        if (ready) {
            return true
        }
    }
    return false
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
        return false
    }
    let ready = false
    for (const i of $range(2000000)) {
        if (modem.$$.state == 1) {
            ready = true
            break
        }
    }
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    return ready
}

function waitForRpc(opcode: u32): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    for (const outer of $range(2000000)) {
        if (!rpcRxNext()) {
            continue
        }
        if (rpcRxIsCtrl()) {
            rpcRxHandleCtrl()
            continue
        }
        const msg = rpc_rx_msg
        const preamble = msg[0]
        if (preamble == T.RPC_PREAMBLE_RSP &&
            (msg[5] & 0xFF) == (opcode & 0xFF)) {
            rpcRxRetire()
            rpcTxFree(tx_list)
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            return true
        }
        rpcRxRetire()
    }
    return false
}

//>> ---- test ---- <<//

export function em$run() {
    init()
    handshake()
}

