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

export function em$startup() {
    shmemConstruct()
}

export function handshake() {
    if (transportStart() && rpcAtInit()) {
        modemPostInit()
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


function rpcAtInit(): bool_t {
    // Reproduce libmodem's first post-handshake AT control RPC.
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    const msg = $cast2<ptr_t<u32>>($$(ctrl.$$.msgs_b))
    list[1] = 0
    list[2] = $cast2<u32>(msg)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = 0x00050003
    msg[1] = 0x00000002
    msg[4] = 0x00000004
    msg[5] = 0x000000A7
    $R.IPC.EVENTS_RECEIVE[4].$$ = 0
    list[1] = 1
    BusyWait.wait(3)
    $R.IPC.TASKS_SEND[3].$$ = 1
    return waitForRpcAtInit()
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


function waitForRpcAtInit(): bool_t {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    const tx_list = $cast2<ptr_t<u32>>($$(ctrl.$$.list_b))
    let fired = false
    for (const i of $range(2000000)) {
        if ($R.IPC.EVENTS_RECEIVE[4].$$ != 0) {
            fired = true
            break
        }
    }
    if (!fired) {
        printf`MODEM rpc_at timeout: ev4=%x txstate=%08x\n`(
            $R.IPC.EVENTS_RECEIVE[4].$$,
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
        if ((state & 0xFF) != 1) {
            continue
        }
        const msg = $cast2<ptr_t<u32>>(rx_list[2 + i * 2])
        const preamble = msg[0]
        if ((preamble & 0xFF) == 3 &&
            ((preamble >> 16) & 0xFFFF) == 2 &&
            (msg[5] & 0xFF) == 0xA7) {
            rx_list[1 + i * 2] = (state & 0xFFFFFF00) | T.DESC_FREE
            const tx_state = tx_list[1]
            if ((tx_state & 0xFF) == 0) {
                tx_list[1] = (tx_state & 0xFFFFFF00) | T.DESC_FREE
            }
            $R.IPC.EVENTS_RECEIVE[4].$$ = 0
            printf`MODEM rpc_at response: pre=%08x rxstate=%08x txstate=%08x\n`(
                preamble,
                state,
                tx_state
            )
            return true
        }
    }
    printf`MODEM rpc_at bad response: ev4=%x count=%x txstate=%08x\n`(
        $R.IPC.EVENTS_RECEIVE[4].$$,
        count,
        tx_list[1]
    )
    $R.IPC.EVENTS_RECEIVE[4].$$ = 0
    return false
}

//>> ---- test ---- <<//

export function em$run() {
    init()
    handshake()
}

