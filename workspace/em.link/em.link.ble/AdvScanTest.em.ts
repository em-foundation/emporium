import '@$$emscript'
export const $U = $declare('MODULE')

import * as AppSchema from '@em.link.ble/BlueJouleGatt.em'
import * as Binder from '@em.link.ble/Binder.em'
import * as BoardC from '@$distro/BoardC.em'
import * as Controller from '@em.link.ble/Controller.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as Registry from '@em.link/Registry.em'
import * as TL from '@em.link/Types.em'

const appF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$configure() {
        Binder.AppSchema.$$dlg = AppSchema
        Controller.Led.$$dlg = $delegate(BoardC.AppLed)
        Controller.OneShot.$$dlg = $delegate(BoardC.OneShot)
        Controller.RadioDriver.$$dlg = $delegate(BoardC.RadioDriver)
        Registry.DEFAULT_PARAMS.$$val.ble_connectible = true
        Registry.DEFAULT_PARAMS.$$val.ble_adv_chan_mask = 0x1
        Registry.DEFAULT_PARAMS.$$val.send_count = 50
        Registry.DEFAULT_PARAMS.$$val.send_interval_ms = 500
    }
    export function em$construct() {
        appF.$$val = FiberMgr.em$meta.create($cb(appFb))
        Controller.em$meta.bindStatusHandler($cb(statusHandler))
    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
    appF.$$.post()
    FiberMgr.run()
}

function appFb(_: arg_t) {
    Controller.start()
}


function statusHandler(stat: TL.ConnectionStatus) {
    // $['%%>'](stat)
    if (stat == TL.ConnectionStatus.CLOSED) halt()
}
