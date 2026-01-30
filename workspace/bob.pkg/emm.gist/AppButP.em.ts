import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

import * as MemDump from '@em.utils/MemDump.em'

const AppButEdge = $delegate(BoardC.AppButEdge)
const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta {
    export function em$construct() {
        AppButEdge.em$meta.setDetectHandler($cb(handler))
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    // if (Common.Mcu.isWarm()) {
    //     const flags: u32 = e$`PML_GetResetFlags()`
    //     $['%%>'](flags)
    //     halt()
    // }
    AppButEdge.init(true)
    AppButEdge.setDetectFalling()
    AppButEdge.enableDetect()

    //     MemDump.print(t$`PWRM`, e$`PML_BASE`, e$`sizeof(PML_RegMap_t)`)
    //     MemDump.print(t$`GPIO`, e$`GPIO_BASE`, e$`sizeof(GPIO_RegMap_t)`)
    //     halt()


    Common.Idle.exec()
}

function handler() {
    AppLed.on()
    Common.BusyWait.wait(20000)
    AppLed.off()
}
