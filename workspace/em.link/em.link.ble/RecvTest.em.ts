import '@$$emscript'
export const $U = $declare('MODULE')

import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as LinkC from '@em.link.ble/LinkC.em'
import * as T from '@em.link/Types.em'

const Adapter = $delegate(LinkC.Adapter)

const recvF = $config<FiberMgr.Obj>()

export namespace em$meta {
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
    printf`stat = %d\n`(stat)
    halt()
}

function recvFB(a: arg_t) {
    Adapter.recvMsg($cb(onDone))
}
