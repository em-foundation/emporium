import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Config from '@em.rf.driver/Config.em'
import * as RadioDriver from '@nordic.radio.nrf52/RadioDriver.em'

export namespace em$meta {
    export function em$construct() {
        Config.phy.$$ = Config.Phy.BLE_1M
        Config.tx_pwr.$$ = 5
    }
}

//>> ---- em$targ ---- <<//

var pktbuf = $table<u8>('rw', 16)

export function em$run() {
    Common.GlobalInterrupts.$$.enable()
    RadioDriver.enable()
    RadioDriver.startRx(pktbuf.$frame(0), 17)
    RadioDriver.waitReady()
    for (const b of pktbuf.$frame(0)) printf`%02x `(b)
    printf`\n`()
    RadioDriver.disable()
}