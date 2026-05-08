import '@$$emscript'
export const $U = $declare('MODULE')

export const ADDR_SIZE = 6
export const HASH_SIZE = 6

export class Addr extends $vector<u8> { $len = ADDR_SIZE }
export class SchemaHash extends $vector<u8> { $len = HASH_SIZE }

export enum ConnectionStatus {
    ACTIVE, CLOSED, HANGUP, OPENING, RESTART, TIMEOUT
}

export enum Phy {
    NONE, BLE_1M, PROP_1M, PROP_250K,
}

export type BufPtr = ptr_t<u8>
export type BufFrame = frame_t<u8>
export type Profile = cb_t<[$$<Params>]>
export type Chain = cb_t<[BufPtr], BufFrame>

export class Params extends $struct {
    // bleAccAdr: u32
    ble_adv_chan_mask: u8
    ble_chain: Chain
    ble_connectible: bool_t
    // bleCrcInit: u32
    ble_enable: bool_t
    ble_exch_buf: BufPtr
    ble_exch_end_ms: u16
    // radioAckProf: Profile
    // radioAlign256: u16
    // radioChannel: u8
    radio_phy: Phy
    // radioNextProf: Profile
    radio_power: i8
    // radioRssiFloor: i8
    // radioTimestamp: bool_t
    // radioWhiten: bool_t
    // recvSniffMs: u16
    // recvStartMs: u16
    // recvTimeoutMs: u32
    send_count: u16
    // sendLbtFlag: bool_t
    // sendHailMs: u16
    send_interval_ms: u16
    // sendStartMs: u16
    // sendStartWindowMs: u16
}

export class NodeId extends $struct {
    schemaNumber: u16
    devAddr: Addr
}

export type RecvDoneFxn = cb_t<[ConnectionStatus]>
export type SendDoneFxn = cb_t<[]>


export namespace em$meta {
    export function setAddr(addr: Addr, val: string) {
        const barr = val.split('.').map(bs => Number.parseInt(bs, 16))
        for (const i of $range(addr.$len)) {
            addr[i] = barr[i] ?? 0
        }
    }
}

//>> ---- em$targ ---- <<//

export function equalAddr(addrA: Addr, addrB: Addr): bool_t {
    for (const i of $range(ADDR_SIZE)) {
        if (addrA[i] != addrB[i]) return false
    }
    return true
}

export function printAddr(addr: Addr): void {
    let sep = t$``
    for (const b of addr.$frame(0)) {
        printf`%s%02x`(sep, b)
        sep = t$`.`
    }
    printf`\n`()
}