import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

var txd: u8

export function em$run() {
    e$`NRF_UARTE30_S->PSEL.TXD = 0` // P0.0
    e$`NRF_UARTE30_S->BAUDRATE = UARTE_BAUDRATE_BAUDRATE_Baud115200`
    e$`NRF_UARTE30_S->ENABLE = UARTE_ENABLE_ENABLE_Enabled`
    //
    e$`NRF_UARTE30_S->DMA.TX.PTR = (uint32_t)&txd`
    e$`NRF_UARTE30_S->DMA.TX.MAXCNT = 1`
    //
    put(c$`h`)
}

function put(b: u8) {
    txd = b
    e$`NRF_UARTE30_S->TASKS_DMA.TX.START = 1`
}