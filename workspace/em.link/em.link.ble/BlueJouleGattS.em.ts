import '@$$emscript'
export const $U = $declare('MODULE', SchemaI)

import * as SchemaI from '@em.link/SchemaI.em'
import * as TL from '@em.link/Types.em'

export const $S_name = 'BlueJouleGatt'
export const $S_uuid = '0000b100-0000-1000-8000-00805f9b34fb'

export type Status_T = u8
export const Status_uuid = '0000b101-0000-1000-8000-00805f9b34fb'

export type Command_T = u8
export const Command_uuid = '0000b102-0000-1000-8000-00805f9b34fb'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var status_val: Status_T = 0x80
var command_val: Command_T = 0

export function Status_read(obuf: TL.BufPtr): u8 {
    obuf[0] = status_val
    return $sizeof<u8>()
}

export function Command_write(ibuf: TL.BufPtr) {
    command_val = ibuf[0]
    status_val = command_val | 0x80
}
