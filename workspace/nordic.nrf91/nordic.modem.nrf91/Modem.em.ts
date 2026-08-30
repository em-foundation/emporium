import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@nordic.distro.nrf91/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as Rpc from '@nordic.modem.nrf91/Rpc.em'

import * as T from '@nordic.modem.nrf91/Types.em'

const AppLed = $delegate(BoardC.AppLed)

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
    atCommand(AT_CFUN_POWER_OFF, false)
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
    if (!atCommand(AT_XCOEX0, false) ||
        !atCommand(AT_SYSTEMMODE_NBIOT, false) ||
        !atCommand(AT_CPSMS_ON, false) ||
        !atCommand(AT_FEACONF_000, false) ||
        !atCommand(AT_FEACONF_031, false) ||
        !atCommand(AT_CEDRXS_OFF, false) ||
        !atCommand(AT_RAI_ON, false) ||
        !atCommand(AT_CEREG_QUERY, true) ||
        !atCommand(AT_CFUN_QUERY, true) ||
        !atCommand(AT_CEREG_ENABLE, false) ||
        !atCommand(AT_CSCON_ON, false) ||
        !atCommand(AT_CFUN_FULL, false)) {
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

function drainAt(kind: u32, want_data: bool_t, done: ptr_t<u32>, okay: ptr_t<u32>, data_seen: ptr_t<u32>): bool_t {
    let handled = false
    for (const outer of $range(64)) {
        if (!Rpc.next()) {
            break
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            handled = true
            continue
        }
        const rsp = Rpc.message()
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
                    Rpc.freeData(rsp[2])
                }
            }
            else if (event == 4) {
                if (rsp[2] != 0) {
                    Rpc.freeData(rsp[2])
                }
            }
        }
        Rpc.retire()
        handled = true
        if (done[0] != 0 && (!want_data || data_seen[0] != 0)) {
            return true
        }
    }
    return handled
}

function atCommand(kind: u32, want_data: bool_t): bool_t {
    const msg = Rpc.alloc()
    const tx = Rpc.allocData()
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




    Rpc.send(msg)
    for (const outer of $range(2000000)) {
        drainAt(
            kind,
            want_data,
            $cast2<ptr_t<u32>>($cast2<u32>(flags) + 0),
            $cast2<ptr_t<u32>>($cast2<u32>(flags) + 4),
            $cast2<ptr_t<u32>>($cast2<u32>(flags) + 8)
        )
        if (flags[0] != 0 && (!want_data || flags[2] != 0)) {
            Rpc.free()
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
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                Rpc.freeData(rsp[2])
            }
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
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                Rpc.freeData(rsp[2])
            }
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
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if ((event == 3 || event == 4) && rsp[2] != 0) {
                Rpc.freeData(rsp[2])
            }
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

function waitForCsconIdle(): bool_t {
    for (const outer of $range(2000000)) {
        if (!Rpc.next()) {
            continue
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            continue
        }
        const rsp = Rpc.message()
        let idle = false
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 4) {
                idle = csconIdle(rsp[2], rsp[3])
                if (rsp[2] != 0) {
                    Rpc.freeData(rsp[2])
                }
            }
            else if (event == 3 && rsp[2] != 0) {
                Rpc.freeData(rsp[2])
            }
        }
        Rpc.retire()
        if (idle) {
            return true
        }
    }
    return false
}

function waitForRegistration(): bool_t {
    for (const outer of $range(2000000)) {
        if (!Rpc.next()) {
            continue
        }
        if (Rpc.isCtrl()) {
            Rpc.handleCtrl()
            continue
        }
        const rsp = Rpc.message()
        let ready = false
        if ((rsp[5] & 0xFF) == T.RPC_OP_AT_INIT) {
            const event = (rsp[0] >> 16) & 0xFF
            if (event == 4) {
                ready = registrationReady(rsp[2], rsp[3])
                if (rsp[2] != 0) {
                    Rpc.freeData(rsp[2])
                }
            }
            else if (event == 3 && rsp[2] != 0) {
                Rpc.freeData(rsp[2])
            }
        }
        Rpc.retire()
        if (ready) {
            return true
        }
    }
    return false
}

//>> ---- test ---- <<//

export function em$run() {
    init()
    handshake()
}

