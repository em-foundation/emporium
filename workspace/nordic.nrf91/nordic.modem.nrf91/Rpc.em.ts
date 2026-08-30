import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as Mem from '@em.utils/Mem.em'

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

const RECV_RPC = T.IPC_RECV_RPC
const SEND_CTRL = T.IPC_SEND_CTRL
const SEND_RPC = T.IPC_SEND_RPC

let at_tx_busy_mask: u32 = 0
let rx_k: u32 = 0
let rx_list: ptr_t<u32> = $null
let rx_msg: ptr_t<u32> = $null
let rx_seq: u32 = 0
let rx_state: u32 = 0
let tx_seq: u32 = 0
let tx_slot: u32 = 0

export function em$startup() {
    shmemConstruct()
}

export function IPC_isr$$() {
    IntrVec.NVIC_clear(e$`IPC_IRQn`)
}

export function atInit(): bool_t {
    return call(T.RPC_OP_AT_INIT, T.RPC_CTRL_SIZE_AT_INIT)
}

export function allocData(): ptr_t<u32> {
    const shmem = $$(shmem_tab[0])
    const base = $cast2<u32>($$(shmem.$$.tx))
    for (const i of $range(2)) {
        const bit = 1 << i
        if ((at_tx_busy_mask & bit) != 0) {
            continue
        }
        at_tx_busy_mask |= bit
        return $cast2<ptr_t<u32>>(base + i * 0x100)
    }
    return $null
}

export function dataTxBusy(addr: u32): bool_t {
    const shmem = $$(shmem_tab[0])
    const base = $cast2<u32>($$(shmem.$$.tx))
    for (const i of $range(2)) {
        if (addr == base + i * 0x100) {
            return (at_tx_busy_mask & (1 << i)) != 0
        }
    }
    return false
}

function freeDataTx(addr: u32) {
    const shmem = $$(shmem_tab[0])
    const base = $cast2<u32>($$(shmem.$$.tx))
    for (const i of $range(2)) {
        if (addr == base + i * 0x100) {
            at_tx_busy_mask &= ~(1 << i)
            return
        }
    }
}

export function call(opcode: u32, ctrl_size: u32): bool_t {
    const msg = alloc(T.RPC_TEMPLATE_REQ.$ptr(), T.RPC_TEMPLATE_REQ.$len)
    msg[4] = ctrl_size
    msg[5] = opcode
    $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
    send(msg)
    return waitForRpc(opcode)
}

export function freeData(data: u32) {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_a))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_a))
    let state = list[1]
    if ((state & 0xFF) == T.DESC_ALLOC) {
        list[1] = (state & 0xFFFFFF00) | T.DESC_FREE
        state = list[1]
    }
    if ((state & 0xFF) != T.DESC_FREE) {
        return
    }
    Mem.set(msg, 0, T.MSG_SIZE)
    msg[0] = 0x00020001
    msg[1] = 1
    msg[2] = data
    list[2] = $cast2<u32>(msg)
    list[1] = ((tx_seq & 0xFFFF) << 16) | T.DESC_BUSY
    tx_seq = (tx_seq + 1) & 0xFFFF
    Common.BusyWait.wait(3)
    $R.IPC.TASKS_SEND[SEND_CTRL].$$ = 1
}

export function handleCtrl() {
    if (!isCtrl()) {
        return
    }
    const type = (rx_msg[0] >> 16) & 0xFFFF
    if (type == 2) {
        freeDataTx(rx_msg[2])
    }
    retire()
}

export function isCtrl(): bool_t {
    if (rx_list == $null || rx_msg == $null) {
        return false
    }
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    return $cast2<u32>(rx_list) == modem.$$.ptr0
}

export function message(): ptr_t<u32> {
    return rx_msg
}

export function next(): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    rx_list = $null
    rx_msg = $null
    if (rxFind(modem.$$.ptr1)) {
        return true
    }
    return rxFind(modem.$$.ptr0)
}

export function retire() {
    if (rx_list == $null) {
        return
    }
    rx_list[rx_k] = (rx_state & 0xFFFFFF00) | T.DESC_FREE
    rx_seq = (rx_seq + 1) & 0xFFFF
    rx_list = $null
    rx_msg = $null
}

export function send(msg: ptr_t<u32>) {
    const tx_list = txList()
    msg[1] = (msg[1] & 0xFFFFFF00) | 2
    const k = 1 + tx_slot * 2
    const state = tx_list[k]
    tx_list[k] = ((tx_seq & 0xFFFF) << 16) | (state & 0x0000FF00) | T.DESC_BUSY
    tx_seq = (tx_seq + 1) & 0xFFFF
    Common.BusyWait.wait(3)
    $R.IPC.TASKS_SEND[SEND_RPC].$$ = 1
}

export function txBase(): ptr_t<u32> {
    const shmem = $$(shmem_tab[0])
    return $cast2<ptr_t<u32>>($$(shmem.$$.tx))
}

export function start(): bool_t {
    ipcInit()
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    $R.POWER.LTEMODEM.STARTN.$$ = 0
    return waitForHandshake()
}

export function alloc(tmplt: ptr_t<u32> = $null, word_cnt: u16 = 0): ptr_t<u32> {
    const tx_list = txList()
    const msgs = txMessages()
    const count = tx_list[0]
    for (const i of $range(T.NUM_DESCS)) {
        if (i >= count) {
            break
        }
        const state = tx_list[1 + i * 2]
        if ((state & 0xFF) != T.DESC_FREE) {
            continue
        }
        tx_slot = i
        const msg = $cast2<ptr_t<u32>>($cast2<u32>(msgs) + i * T.MSG_WORDS * 4)
        tx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_ALLOC
        tx_list[2 + i * 2] = $cast2<u32>(msg)
        Mem.set(msg, 0, T.MSG_SIZE)
        if (word_cnt != 0) {
            Mem.cpy(msg, tmplt, word_cnt * 4)
        }
        return msg
    }
    return $null
}



function txList(): ptr_t<u32> {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    return $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
}

function txMessages(): ptr_t<u32> {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    return $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
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

function rxFind(list_addr: u32): bool_t {
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
        if (((state >> 16) & 0xFFFF) != (rx_seq & 0xFFFF)) {
            continue
        }
        rx_list = list
        rx_k = k
        rx_state = state
        rx_msg = $cast2<ptr_t<u32>>(list[k + 1])
        return true
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
    for (const outer of $range(2000000)) {
        if (!next()) {
            continue
        }
        if (isCtrl()) {
            handleCtrl()
            continue
        }
        const msg = message()
        const preamble = msg[0]
        if (preamble == T.RPC_PREAMBLE_RSP &&
            (msg[5] & 0xFF) == (opcode & 0xFF)) {
            retire()
            $R.IPC.EVENTS_RECEIVE[RECV_RPC].$$ = 0
            return true
        }
        retire()
    }
    return false
}
