import '@$$emscript'
export const $U = $declare('MODULE')

import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as LinkC from '@em.link.ble/LinkC.em'
import * as Registry from '@em.link/Registry.em'
import * as T from '@em.link/Types.em'

const Adapter = $delegate(LinkC.Adapter)

const recvF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        Registry.DEFAULT_PARAMS.$$val.ble_connectible = true
        Registry.DEFAULT_PARAMS.$$val.ble_adv_chan_mask = 0x1
        Registry.DEFAULT_PARAMS.$$val.send_count = 50
        Registry.DEFAULT_PARAMS.$$val.send_interval_ms = 500
    }
    export function em$construct() {
        recvF.$$val = FiberMgr.em$meta.create($cb(recvFB))
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    recvF.$$.post()
    FiberMgr.run()
}

function onDone(stat: T.ConnectionStatus) {
    // printf`stat = %d\n`(stat)
}

function recvFB(a: arg_t) {
    Adapter.recvMsg($cb(onDone))
}
