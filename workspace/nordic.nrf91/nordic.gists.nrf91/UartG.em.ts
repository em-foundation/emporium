import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf91/REGS.em'

//>> ---- em$targ ---- <<//

var buf: u8

export function em$run() {
    $R.UARTE0.PSEL.TXD.$$ = 27
    $R.UARTE0.BAUDRATE.$$ = $R.UARTE_BAUDRATE_BAUDRATE_Baud115200
    $R.UARTE0.ENABLE.$$ = $R.UARTE_ENABLE_ENABLE_Enabled
    $R.UARTE0.TXD.PTR.$$ = $cast2<u32>($$(buf))
    $R.UARTE0.TXD.MAXCNT.$$ = 1
    put(0xab)
}

function put(b: u8) {
    buf = b
    $R.UARTE0.TASKS_STARTTX.$$ = 1
}