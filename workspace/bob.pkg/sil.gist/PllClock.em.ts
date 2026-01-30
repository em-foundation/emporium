import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@silabs.distro.efr32x/REGS.em'

import * as Common from '@em.mcu/Common.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    for (const i of $range(5)) {
        delay(10)
        pr32(i)
    }
}

function delay(ms: u32) {
    Common.BusyWait.wait(ms * 1000)
}

function pr32(v: u32) {
    delay(1)
    $['%%>'](v)
}