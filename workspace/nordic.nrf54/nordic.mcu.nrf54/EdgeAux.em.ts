import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as EdgeI from '@em.hal/EdgeI.em'

export class HandlerInfo extends $struct {
    handler: EdgeI.Handler
}

const handler_info_tab = $table<HandlerInfo>()

export namespace em$meta {
    export function em$construct() {
        Common.Irq.em$meta.useIntr('GPIOTE20_0')
    }

    export function addHandlerInfo(hi: HandlerInfo): u8 {
        const chan = <u8>handler_info_tab.$len
        handler_info_tab.$$add(hi)
        return chan
    }
}

export function em$startup() {
    Common.Irq.enable(e$`GPIOTE20_0_IRQn`)
}

export function GPIOTE20_0_isr$$() {
    let pc = 0
    for (let hi of handler_info_tab) {
        if ($R.GPIOTE20.EVENTS_IN[pc].$$ && hi.handler != $null) {
            hi.handler()
        }
        pc += 1
    }
}
