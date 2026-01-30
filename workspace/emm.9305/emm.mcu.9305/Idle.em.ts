import '@$$emscript'
export const $U = $declare('MODULE', IdleI)

import * as $R from '@emm.distro.9305/REGS.em'

import * as Debug from '@em.lang/Debug.em'
import * as IdleI from '@em.hal/IdleI.em'

export type SleepCB = cb_t<[]>

const sleep_enter_tab = $table<SleepCB>()
const sleep_leave_tab = $table<SleepCB>()

export namespace em$meta {
    export function addSleepEnter(cb: SleepCB) {
        sleep_enter_tab.$$add(cb)
    }

    export function addSleepLeave(cb: SleepCB) {
        sleep_leave_tab.$$add(cb)
    }
}

//>> ---- em$targ ---- <<//

var cur_pause_only = false

export function em$startup() {
    $['%%b+']
}

function doPause() {
    $['%%b:'](1)
    $['%%b-']
    e$`asm ("sleep 0x10")`  // enable interrupts
    $['%%b+']
}


function doSleep() {
    $R.PML.RegPmlCtrl.$$ &= ~$R.PML_WAKE_FLG_EN_MASK
    $R.PML.RegPmlCtrl.$$ |= $R.PML_WAKE_CLEAR_MASK
    $R.PML.RegPmlCtrl.$$ |= $R.PML_WAKE_FLG_EN_MASK
    $R.PML.RegPmlCtrl.$$ |= $R.PML_LATCH_PAD_EN_MASK
    for (let cb of sleep_enter_tab) cb()
    $['%%b:'](2)
    $['%%b-']
    Debug.reset()
    e$`PML_PowerDownNvmAndSleep(6)`
}

export function exec() {
    if (cur_pause_only) {
        doPause()
    } else {
        doSleep()
    }
}

export function setPauseOnly(pause_only: bool_t) {
    cur_pause_only = pause_only
}

export function wakeup() {
    for (let cb of sleep_leave_tab) cb()
}
