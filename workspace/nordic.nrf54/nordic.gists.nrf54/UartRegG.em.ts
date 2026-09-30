import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

var txd: u8

export function em$run() {
    // setup
    $R.UARTE30.PSEL.TXD.$$ = 0  /// TODO: fix hard-coded P0.00
    $R.UARTE30.BAUDRATE.$$ = $R.UARTE_BAUDRATE_BAUDRATE_Baud115200
    $R.UARTE30.ENABLE.$$ = $R.UARTE_ENABLE_ENABLE_Enabled
    //
    e$`NRF_UARTE30_S->DMA.TX.PTR = (uint32_t)&txd`
    $R.UARTE30.DMA.TX.MAXCNT.$$ = 1
    $R.UARTE30.EVENTS_DMA.TX.END.$$ = 1
    // output
    put(c$`h`)
    put(c$`i`)
}

function put(data: u8) {
    txd = data
    $R.UARTE30.EVENTS_DMA.TX.END.$$ = 0
    $R.UARTE30.TASKS_DMA.TX.START.$$ = 1
    while ($R.UARTE30.EVENTS_DMA.TX.END.$$ == 0) { }
    $R.UARTE30.EVENTS_DMA.TX.END.$$ = 1
}