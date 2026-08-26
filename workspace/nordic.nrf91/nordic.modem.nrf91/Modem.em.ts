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
    transportStart()
    modemPostInit()
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

function transportStart() {
    // STARTN is followed by the first modem response on RECEIVE[2].
    $R.POWER.LTEMODEM.STARTN.$$ = 0
    waitForHandshake()
}

function waitForHandshake() {
    const shmem = $$(shmem_tab[0])
    const ctrl = $$(shmem.$$.ctrl)
    const modem = $$(ctrl.$$.modem)
    while ($R.IPC.EVENTS_RECEIVE[2].$$ == 0) {
    }
    $R.IPC.EVENTS_RECEIVE[2].$$ = 0
    while (modem.$$.state != 1) {
    }
    $R.IPC.GPMEM[1].$$ = $cast2<u32>(modem)
}
