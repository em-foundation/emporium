import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as Mem from '@em.utils/Mem.em'
import * as AtCmd from '@nordic.modem.nrf91/AtCmd.em'
import * as Rpc from '@nordic.modem.nrf91/Rpc.em'

import * as T from '@nordic.modem.nrf91/Types.em'

const AppLed = $delegate(BoardC.AppLed)

const NETWORK_CFG = $config<AtCmd.OperationId>()
const REGISTER = $config<AtCmd.OperationId>()
const POWER_OFF = $config<AtCmd.OperationId>()

export namespace em$meta {
    //
    export function em$configure() {
        NETWORK_CFG.$$val = AtCmd.em$meta.declare([
            ["AT%XCOEX0=1,1,1565,1586", 0],
            ["AT%XSYSTEMMODE=0,1,0,0", 0],
            ['AT+CPSMS=1,,,"00100001","00000000"', 0],
            ["AT%FEACONF=0,0,0", 0],
            ["AT%FEACONF=0,3,1", 0],
            ["AT+CEDRXS=3", 0],
            ["AT%RAI=2", 0],
        ])
        REGISTER.$$val = AtCmd.em$meta.declare([
            ["AT+CEREG?", 1],
            ["AT+CFUN?", 1],
            ["AT+CEREG=5", 0],
            ["AT+CSCON=1", 0],
            ["AT+CFUN=1", 0],
        ])
        POWER_OFF.$$val = AtCmd.em$meta.declare([
            ["AT+CFUN=0", 0],
        ])

    }
}

//>> ---- em$targ ---- <<//

const SEND_RSP = 0x80060004
const SOCKET_RSP = 0x80010004

var enabled: bool_t = false
var udp_fd: u32 = 0xFFFFFFFF

export function disable() {
    if (enabled) {
        modemShutdown()
        enabled = false
        udp_fd = 0xFFFFFFFF
    }
}

export function enable(): bool_t {
    if (enabled) {
        return true
    }
    if (!Rpc.start() || !Rpc.atInit()) {
        return false
    }
    modemPostInit()
    AppLed.on()
    $['%%d+']
    if (!networkBringUp()) {
        return false
    }
    AppLed.off()
    $['%%d-']
    enabled = true
    return true
}

export function openUdp(addr: u32, port: u16): bool_t {
    /// assert enabled
    return openUdpInternal(addr, port)
}

export function send(data: ptr_t<u8>, len: u32): bool_t {
    /// assert udp_fd != 0xFFFFFFFF
    return sendUdp(udp_fd, data, len)
}

export function handshake() {
    const payload = $cast2<ptr_t<u8>>(Rpc.txBase())
    Mem.set(payload, 0, 20)
    if (!enable()) {
        fail()
    }
    if (!openUdp(0x08080808, 2469)) {
        fail()
    }
    if (!send(payload, 20)) {
        fail()
    }
    disable()
}

export function init() {
    // POWER/CLOCK are assumed non-secure before entry.
    modemPrep()
}

function modemShutdown() {
    AtCmd.run(POWER_OFF)
}

function modemPostInit() {
    const MODEM_POST = $cast2<ptr_t<u32>>(0x4000506C)
    MODEM_POST[0] = 1
}

function modemPrep() {
    const MODEM_PREP = $cast2<ptr_t<u32>>(0x40005068)
    MODEM_PREP[0] = 1
    Common.BusyWait.wait(200)
}

function networkBringUp(): bool_t {
    if (!AtCmd.run(NETWORK_CFG) || !AtCmd.run(REGISTER)) {
        return false
    }
    if (!AtCmd.waitForRegistration()) {
        return false
    }
    if (!AtCmd.waitForCsconIdle()) {
        return false
    }
    return true
}

function connectUdp(fd: u32, addr: u32, port: u16): bool_t {
    // Exact IPv4 connect() request shape from the Zephyr UDP image.
    const msg = Rpc.alloc(T.RPC_TEMPLATE_CONNECT_REQ.$ptr(), T.RPC_TEMPLATE_CONNECT_REQ.$len)
    msg[6] = fd
    msg[7] = 0x00040000 | (($cast2<u32>(port) & 0xFF) << 8) | (($cast2<u32>(port) >> 8) & 0xFF)
    msg[8] = addr
    Rpc.send(msg)
    for (const outer of $range(2000000)) {
        if (!Rpc.next()) {
            continue
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            continue
        }
        const rsp = Rpc.message()
        if (AtCmd.handleAsync(rsp)) {
            Rpc.retire()
            continue
        }
        if (rsp[0] == 0x80020004 && rsp[6] == fd) {
            const okay = rsp[7] == 0
            Rpc.retire()
            return okay
        }
        Rpc.retire()
    }
    return false
}

function sendUdp(fd: u32, data: ptr_t<u8>, len: u32): bool_t {
    // Connected UDP send with RAI_LAST.
    const msg = Rpc.alloc(T.RPC_TEMPLATE_SEND_REQ.$ptr(), T.RPC_TEMPLATE_SEND_REQ.$len)
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    msg[2] = $cast2<u32>(data)
    msg[3] = len
    msg[5] = $cast2<u32>(result)
    msg[7] = 0x01000000
    result[0] = T.RPC_RESULT_PENDING
    result[1] = 0
    Rpc.send(msg)
    $['%%d+']
    let sent = false
    for (const outer of $range(2000000)) {
        if (!Rpc.next()) {
            continue
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            continue
        }
        const rsp = Rpc.message()
        const idle = AtCmd.asyncCsconIdle(rsp)
        if (AtCmd.handleAsync(rsp)) {
            Rpc.retire()
            if (sent && idle) {
                $['%%d-']
                return true
            }
            continue
        }
        if (rsp[0] == SEND_RSP) {
            sent = true
            Rpc.retire()
            continue
        }
        Rpc.retire()
    }
    return false
}

function openUdpInternal(addr: u32, port: u16): bool_t {
    // Exact first socket() control request from the Zephyr UDP image.
    const msg = Rpc.alloc(T.RPC_TEMPLATE_SOCKET_REQ.$ptr(), T.RPC_TEMPLATE_SOCKET_REQ.$len)
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    msg[5] = $cast2<u32>(result)
    result[0] = T.RPC_RESULT_PENDING
    result[1] = 0
    Rpc.send(msg)
    for (const outer of $range(2000000)) {
        if (!Rpc.next()) {
            continue
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            continue
        }
        const rsp = Rpc.message()
        if (AtCmd.handleAsync(rsp)) {
            Rpc.retire()
            continue
        }
        if (rsp[0] == SOCKET_RSP && rsp[5] == $cast2<u32>(result)) {
            result[0] = rsp[8]
            result[1] = rsp[7]
            Rpc.retire()
            if (result[1] != 0) {
                return false
            }
            udp_fd = result[0]
            if (!connectUdp(udp_fd, addr, port)) {
                return false
            }
            return true
        }
        Rpc.retire()
    }
    return false
}

//>> ---- test ---- <<//

export function em$run() {
    init()
    handshake()
}
