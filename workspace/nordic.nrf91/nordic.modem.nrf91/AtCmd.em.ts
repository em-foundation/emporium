import '@$$emscript'
export const $U = $declare('MODULE')

import * as Mem from '@em.utils/Mem.em'
import * as Rpc from '@nordic.modem.nrf91/Rpc.em'
import * as T from '@nordic.modem.nrf91/Types.em'

export type OperationId = u8

class CommandDesc extends $struct {
    offset: u16
    length: u8
    flags: u8
}

class OperationDesc extends $struct {
    offset: u8
    length: u8
}

const command_tab = $table<CommandDesc>()
const data_tab = $table<u8>()
const operation_tab = $table<OperationDesc>()
const operation_cmd_tab = $table<u8>()

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
            const op = operation_tab.$$add()
            op.$$.offset = operation_cmd_tab.$len
            op.$$.length = op_spec.length
            for (const [command, flags] of op_spec) {
                const key = `${flags}:${command}`
                let cmd_id = cmd_map.get(key)
                if (cmd_id === undefined) {
                    cmd_id = command_tab.$len
                    cmd_map.set(key, cmd_id)
                    const desc = command_tab.$$add()
                    desc.$$.offset = data_offset
                    desc.$$.length = command.length + 1
                    desc.$$.flags = flags
                    for (let i = 0; i < command.length; i++) {
                        data_tab.$$add(command.charCodeAt(i))
                    }
                    data_tab.$$add(0)
                    data_offset += command.length + 1
                }
                operation_cmd_tab.$$add(cmd_id)
            }
        }
    }
}

//>> ---- em$targ ---- <<//

const FLAG_WANT_DATA = 0x01

function command(cmd_id: u8): bool_t {
    const desc = $$(command_tab[cmd_id])
    const msg = Rpc.alloc(T.RPC_TEMPLATE_AT_REQ.$ptr(), T.RPC_TEMPLATE_AT_REQ.$len)
    const tx = Rpc.allocData()
    if (tx == $null) return false
    const state = $cast2<ptr_t<u32>>($cast2<u32>(msg) + 0x30)
    const len = desc.$$.length
    Mem.cpy(tx, $$(data_tab[desc.$$.offset]), len)
    msg[2] = $cast2<u32>(tx)
    msg[3] = len
    Rpc.send(msg)
    const want_data = (desc.$$.flags & FLAG_WANT_DATA) != 0
    for (const outer of $range(2000000)) {
        drainAt(
            want_data,
            $cast2<ptr_t<u32>>($cast2<u32>(state) + 0),
            $cast2<ptr_t<u32>>($cast2<u32>(state) + 4),
            $cast2<ptr_t<u32>>($cast2<u32>(state) + 8)
        )
        if (state[0] != 0 &&
            (!want_data || state[2] != 0) &&
            !Rpc.dataTxBusy($cast2<u32>(tx))) {
            return state[1] != 0
        }
    }
    return false
}

export function run(op_id: OperationId): bool_t {
    const op = $$(operation_tab[op_id])
    for (const i of $range(op.$$.length)) {
        if (!command(operation_cmd_tab[op.$$.offset + i])) {
            return false
        }
    }
    return true
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

function drainAt(want_data: bool_t, done: ptr_t<u32>, okay: ptr_t<u32>, data_seen: ptr_t<u32>): bool_t {
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
                okay[0] = 1
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
