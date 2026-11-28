import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as Rpc from '@nordic.modem.nrf91/Rpc.em'

export function em$startup() {
    // POWER/CLOCK are non-secure after TF-M hands off to the application.
    const modem_prep = $cast2<ptr_t<u32>>(0x40005068)
    modem_prep[0] = 1
    Common.BusyWait.wait(200)

    if (!Rpc.start() || !Rpc.atInit()) fail()

    const modem_post = $cast2<ptr_t<u32>>(0x4000506C)
    modem_post[0] = 1
}
