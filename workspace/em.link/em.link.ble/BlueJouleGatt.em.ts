import '@$$emscript'
export const $U = $declare('MODULE')

export const $S_name = 'BlueJouleGatt'
export const $S_uuid = '0000b100-0000-1000-8000-00805f9b34fb'

export type Status_T = u8
export const Status_uuid = '0000b101-0000-1000-8000-00805f9b34fb'

export type Command_T = u8
export const Command_uuid = '0000b102-0000-1000-8000-00805f9b34fb'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var status_val: Status_T = 0
var command_val: Command_T = 0

export function Status_read(): Status_T {
    return status_val
}

export function Command_write(value: Command_T) {
    command_val = value
    status_val = value
}
