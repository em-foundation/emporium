import '@$$emscript'
export const $U = $declare('MODULE')

import * as Rpc from '@nordic.modem.nrf91/Rpc.em'
import * as T from '@nordic.modem.nrf91/Types.em'

export type OperationId = u8

class CommandDesc extends $struct {
    offset: u16
    length: u8
    flags: u8
}

var command_tab = $table<CommandDesc>()
var data_tab = $table<u8>()

export namespace em$meta {
    //
    type CommandSpec = readonly [command: string, flags: u8]
    type OperationSpec = readonly CommandSpec[]
    //
    const op_specs: OperationSpec[] = []
    //
    export function declare(spec: OperationSpec): OperationId {
        op_specs.push(spec)
        return op_specs.length - 1
    }
    //
    export function em$construct() {
        const cmd_map = new Map<string, number>()
        let data_offset = 0
        for (const op_spec of op_specs) {
            for (const [command, flags] of op_spec) {
                const key = `${flags}:${command}`
                if (cmd_map.has(key)) {
                    continue
                }
                cmd_map.set(key, command_tab.$len)
                const desc = command_tab.$$add()
                desc.$$.offset = data_offset
                desc.$$.length = command.length
                desc.$$.flags = flags
                for (let i = 0; i < command.length; i++) {
                    data_tab.$$add(command.charCodeAt(i))
                }
                data_offset += command.length
            }
        }
    }
}

//>> ---- em$targ ---- <<//

const AT_CEREG = 6
export const CEDRXS_OFF = 3
export const CEREG_ENABLE = 12
export const CEREG_QUERY = 10
export const CFUN_FULL = 5
export const CFUN_POWER_OFF = 7
export const CFUN_QUERY = 11
export const CPSMS_ON = 2
export const CSCON_ON = 13
export const FEACONF_000 = 9
export const FEACONF_031 = 8
export const RAI_ON = 4
export const SYSTEMMODE_NBIOT = 1
export const XCOEX0 = 14

export function command(kind: u32, want_data: bool_t): bool_t {
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
    if (kind == XCOEX0) {
        tx[0] = 0x58255441
        tx[1] = 0x58454F43
        tx[2] = 0x2C313D30
        tx[3] = 0x35312C31
        tx[4] = 0x312C3536
        tx[5] = 0x00363835
        len = 24
    }
    else if (kind == SYSTEMMODE_NBIOT) {
        tx[0] = 0x58255441
        tx[1] = 0x54535953
        tx[2] = 0x4F4D4D45
        tx[3] = 0x303D4544
        tx[4] = 0x302C312C
        tx[5] = 0x0000302C
        len = 23
    }
    else if (kind == CPSMS_ON) {
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
    else if (kind == FEACONF_000) {
        tx[0] = 0x46255441
        tx[1] = 0x4F434145
        tx[2] = 0x303D464E
        tx[3] = 0x302C302C
        len = 17
    }
    else if (kind == FEACONF_031) {
        tx[0] = 0x46255441
        tx[1] = 0x4F434145
        tx[2] = 0x303D464E
        tx[3] = 0x312C332C
        len = 17
    }
    else if (kind == CEDRXS_OFF) {
        tx[0] = 0x432B5441
        tx[1] = 0x58524445
        tx[2] = 0x00333D53
        len = 12
    }
    else if (kind == RAI_ON) {
        tx[0] = 0x52255441
        tx[1] = 0x323D4941
        len = 9
    }
    else if (kind == CEREG_QUERY || kind == AT_CEREG) {
        tx[0] = 0x432B5441
        tx[1] = 0x47455245
        tx[2] = 0x0000003F
        len = 10
    }
    else if (kind == CFUN_QUERY) {
        tx[0] = 0x432B5441
        tx[1] = 0x3F4E5546
        len = 9
    }
    else if (kind == CEREG_ENABLE) {
        tx[0] = 0x432B5441
        tx[1] = 0x47455245
        tx[2] = 0x0000353D
        len = 11
    }
    else if (kind == CSCON_ON) {
        tx[0] = 0x432B5441
        tx[1] = 0x4E4F4353
        tx[2] = 0x0000313D
        len = 11
    }
    else if (kind == CFUN_FULL) {
        tx[0] = 0x432B5441
        tx[1] = 0x3D4E5546
        tx[2] = 0x00000031
        len = 10
    }
    else if (kind == CFUN_POWER_OFF) {
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

export function handleAsync(rsp: ptr_t<u32>): bool_t {
    if ((rsp[5] & 0xFF) != T.RPC_OP_AT_INIT) {
        return false
    }
    const event = (rsp[0] >> 16) & 0xFF
    if ((event == 3 || event == 4) && rsp[2] != 0) {
        Rpc.freeData(rsp[2])
    }
    return true
}

export function waitForCsconIdle(): bool_t {
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

export function waitForRegistration(): bool_t {
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
