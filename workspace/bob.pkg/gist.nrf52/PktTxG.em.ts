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

var pktbuf = $table<u8>('rw', 10)

export function em$run() {
    Common.GlobalInterrupts.$$.enable()
    pktbuf[0] = pktbuf.$len - 1
    for (const i of $range(<u16>1, pktbuf.$len)) pktbuf[i] = 0x80 + i
    RadioDriver.enable()
    RadioDriver.startTx(pktbuf.$frame(0), 17)
    $['%%c+']
    RadioDriver.waitReady()
    $['%%c-']
    RadioDriver.disable()
}