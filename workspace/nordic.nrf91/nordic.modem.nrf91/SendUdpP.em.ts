import '@$$emscript'
export const $U = $declare('MODULE')

import * as Modem from '@nordic.modem.nrf91/Modem.em'

var payload = $table<u8>()

export namespace em$meta {
    export function em$construct() {
        for (const _ of $range(20)) {
            payload.$$add()
        }
    }
}

//>> ---- em$targ ---- <<//

const SERVER_ADDR = 0x08080808
const SERVER_PORT = 2469

export function em$run() {
    Modem.init()
    if (!Modem.enable()) {
        fail()
    }
    if (!Modem.openUdp(SERVER_ADDR, SERVER_PORT)) {
        fail()
    }
    for (const _ of $range(10)) {
        $['%%c']
        if (!Modem.send(payload.$ptr(), payload.$len)) {
            fail()
        }
    }
    // printf`UDP send succeeded\n`()
}
