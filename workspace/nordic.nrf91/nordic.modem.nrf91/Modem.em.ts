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
    modemStart()
    waitForHandshake()
}

export function init() {
    modemPrep()
    platformInit()
    modemPostInit()
}

export function IPC_isr$$() {
    IntrVec.NVIC_clear(e$`IPC_IRQn`)
}

// rpc_transport_ipc_init(): configure IPC channels, interrupts,
// and publish the host control block to the modem.
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

// nrf_modem_init(): write POWER_NS + 0x6c after platform init succeeds.
function modemPostInit() {
    const MODEM_POST = $cast2<ptr_t<u32>>(0x4000506C)
    MODEM_POST[0] = 1
}

// nrf_modem_init(): write POWER_NS + 0x68, then wait 200 us.
function modemPrep() {
    const MODEM_PREP = $cast2<ptr_t<u32>>(0x40005068)
    MODEM_PREP[0] = 1
    BusyWait.wait(200)
}

// STARTN is written after transport initialization is complete.
function modemStart() {
    $R.POWER.LTEMODEM.STARTN.$$ = 0
}

// nrf_modem_platform_init():
//   rpc_init()
//     -> rpc_transport_init()
//       -> rpc_transport_ipc_init()
// Five additional subsystem initializers follow rpc_init(); for now
// they remain outside the handshake reconstruction.
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

// rpc_transport_ipc_init() contains more work than just register setup.
// The remaining shared-memory/OS details will be filled in directly
// from its disassembly.
function transportInit() {
    txHeapInit()
    ipcInit()
}

// Host-side TX shared-memory allocator initialization.
// Exact behavior is the next reconstruction target.
function txHeapInit() {
}

// rpc_transport_ipc_init() waits on a semaphore after STARTN.
// For now model only the first observable startup event.
function waitForHandshake() {
    while ($R.IPC.EVENTS_RECEIVE[2].$$ == 0) {
    }
}
