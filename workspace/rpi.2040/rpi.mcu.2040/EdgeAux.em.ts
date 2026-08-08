import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@rpi.distro.2040/REGS.em'

import * as EdgeI from '@em.hal/EdgeI.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

export class HandlerInfo extends $struct {
    handler: EdgeI.Handler
}

const handler_info_tab = $table<HandlerInfo>()

export namespace em$meta {

    export function em$construct() {
        IntrVec.em$meta.useIntr('IO_IRQ_BANK0')
    }

    export function addHandlerInfo(hi: HandlerInfo): u8 {
        const chan = <u8>handler_info_tab.$len
        handler_info_tab.$$add(hi)
        return chan
    }
}

//>> ---- em$targ ---- <<//

export function em$startup() {
    IntrVec.NVIC_enable(e$`IO_IRQ_BANK0_IRQn`)
}

export function IO_IRQ_BANK0_isr$$() {
    IntrVec.NVIC_clear(e$`IO_IRQ_BANK0_IRQn`)
    for (const hi of handler_info_tab) {
        if (hi.handler != $null) {
            hi.handler()
        }
    }
}
