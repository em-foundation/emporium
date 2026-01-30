import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@emm.distro.9305/BoardC.em'
import * as Common from '@em.mcu/Common.em'

const AppButPin = $delegate(BoardC.AppButPin)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

e$`extern "C" void PML_ConfigWakeUpByGpio(uint8_t gpio, bool wakePolarity, bool wakeEnable, bool irqEnable)`

export function em$run() {
    if (Common.Mcu.isWarm()) {
        printf`get = %d\n`(AppButPin.get())
        halt()
    }
    AppButPin.makeInput()
    AppButPin.setInternalPullup(true)
    // AppLed.on()
    // while (AppButPin.get()) { }
    // AppLed.off()
    e$`PML_ConfigWakeUpByGpio(5, 1, 1, 1)`
    Common.Idle.exec()
}