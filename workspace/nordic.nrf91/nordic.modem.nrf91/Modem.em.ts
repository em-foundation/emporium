import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as AtCmd from '@nordic.modem.nrf91/AtCmd.em'
import * as Rpc from '@nordic.modem.nrf91/Rpc.em'

import * as T from '@nordic.modem.nrf91/Types.em'

const AppLed = $delegate(BoardC.AppLed)

const SEND_RAI_LAST = 0x01000000
const SEND_REQ = 0x70060004
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
    if (!enabled) {
        return false
    }
    return openUdpInternal(addr, port)
}

export function send(data: ptr_t<u8>, len: u32): bool_t {
    if (udp_fd == 0xFFFFFFFF) {
        return false
    }
    return sendUdp(udp_fd, data, len)
}

export function handshake() {
    const payload = $cast2<ptr_t<u8>>(Rpc.txBase())
    for (const i of $range(20)) {
        payload[i] = 0
    }
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
    AtCmd.command(AtCmd.CFUN_POWER_OFF, false)
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
    if (!AtCmd.command(AtCmd.XCOEX0, false) ||
        !AtCmd.command(AtCmd.SYSTEMMODE_NBIOT, false) ||
        !AtCmd.command(AtCmd.CPSMS_ON, false) ||
        !AtCmd.command(AtCmd.FEACONF_000, false) ||
        !AtCmd.command(AtCmd.FEACONF_031, false) ||
        !AtCmd.command(AtCmd.CEDRXS_OFF, false) ||
        !AtCmd.command(AtCmd.RAI_ON, false) ||
        !AtCmd.command(AtCmd.CEREG_QUERY, true) ||
        !AtCmd.command(AtCmd.CFUN_QUERY, true) ||
        !AtCmd.command(AtCmd.CEREG_ENABLE, false) ||
        !AtCmd.command(AtCmd.CSCON_ON, false) ||
        !AtCmd.command(AtCmd.CFUN_FULL, false)) {
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
    const msg = Rpc.alloc()
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = T.RPC_PREAMBLE_CONNECT_REQ
    msg[1] = 0
    msg[4] = T.RPC_CTRL_SIZE_CONNECT
    msg[5] = 0
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
            Rpc.free()
            return okay
        }
        Rpc.retire()
    }
    return false
}

function sendUdp(fd: u32, data: ptr_t<u8>, len: u32): bool_t {
    // Connected UDP send with RAI_LAST.
    const msg = Rpc.alloc()
    const result = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x38)
    for (const i of $range(T.MSG_WORDS)) {
        msg[i] = 0
    }
    msg[0] = SEND_REQ
    msg[1] = 0
    msg[2] = $cast2<u32>(data)
    msg[3] = len
    msg[4] = 0x0E
    msg[5] = $cast2<u32>(result)
    msg[6] = 0
    msg[7] = SEND_RAI_LAST
    msg[8] = 0
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
        if (rsp[0] == SEND_RSP) {
            Rpc.retire()
            Rpc.free()
            return true
        }
        Rpc.retire()
    }
    return false
}

function openUdpInternal(addr: u32, port: u16): bool_t {
    // Exact first socket() control request from the Zephyr UDP image.
    const msg = Rpc.alloc()
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
            Rpc.free()
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
