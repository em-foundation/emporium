import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Config from '@em.rf.driver/Config.em'
import * as RadioDriver from '@nordic.radio.nrf54/RadioDriver.em'

var adv_pkt = $table<u8>('rw')

export namespace em$meta {
    export function em$configure() {
        Config.phy.$$ = Config.Phy.BLE_1M
        Config.tx_pwr.$$ = 5
    }
    export function em$construct() {
        const bytes = [0x22, 14, 0xCC, 0xCC, 0xBB, 0xBB, 0xAA, 0xAA, 4, 0x08, c$`E`, c$`M`, c$`S`, 2, 0x01, 0x06]
        for (const b of bytes) {
            adv_pkt.$add(b)
        }
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.GlobalInterrupts.$$.enable()
    RadioDriver.enable()
    RadioDriver.startTx(adv_pkt.$frame(0), 17)
    $['%%c+']
    RadioDriver.waitReady()
    $['%%c-']
    RadioDriver.disable()
}