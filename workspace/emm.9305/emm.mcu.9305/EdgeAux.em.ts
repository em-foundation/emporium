import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@emm.distro.9305/REGS.em'

import * as EdgeI from '@em.hal/EdgeI.em'
import * as Idle from '@emm.mcu.9305/Idle.em'

export class HandlerInfo extends $struct {
    handler: EdgeI.Handler
}

const handler_info_tab = $table<HandlerInfo>()

export namespace em$meta {
    export function em$construct() {
        Idle.em$meta.addSleepLeave($cb(sleepLeave))
    }
    export function addHandlerInfo(hi: HandlerInfo) {
        handler_info_tab.$$add(hi)
    }
}

function sleepLeave() {
    for (let hi of handler_info_tab) {
        if (hi.handler != $null) {
            hi.handler()
        }
    }
}

