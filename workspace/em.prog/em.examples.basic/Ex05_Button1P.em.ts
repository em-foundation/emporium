import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'

export const AppButEdge = $delegate(BoardC.AppButEdge)
export const AppLed = $delegate(BoardC.AppLed)

export namespace em$meta {
    export function em$construct() {
        AppButEdge.em$meta.setDetectHandler($cb(handler))
    }
}

//>> ---- em$targ ---- <<//

var pressed_flag: volatile_t<bool_t>

export function em$startup() {
    AppButEdge.init(true)
    AppButEdge.setDetectFalling()
}

export function em$run() {
    Common.GlobalInterrupts.enable()
    while (true) {
        AppButEdge.enableDetect()
        pressed_flag = false
        while (!pressed_flag) Common.Idle.exec()
        AppLed.wink(5)
    }
}

function handler() {
    $['%%c']
    AppButEdge.clearDetect()
    pressed_flag = true
}
