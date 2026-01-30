import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as HfXtal from '@nordic.mcu.nrf54/HfXtal.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    $['%%>']($R.RESET.RESETREAS.$$)
    $R.RESET.RESETREAS.$$ = 0xFFFF
    Common.GlobalInterrupts.$$.enable()
    HfXtal.start()
    HfXtal.wait()
    HfXtal.stop()
    Common.BusyWait.$$.wait(1000)
    $['%%d:'](4)
    HfXtal.start()
    HfXtal.wait()
    HfXtal.stop()
}