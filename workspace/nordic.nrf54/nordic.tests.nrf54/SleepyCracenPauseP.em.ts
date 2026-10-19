import '@$$emscript'
export const $U = $declare('MODULE')

import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'
import * as P256CracenActivity from '@nordic.tests.nrf54/P256CracenActivity.em'
import * as SleepyRunner from '@em.utils/SleepyRunner.em'

export namespace em$meta {
    export function em$configure() {
        SleepyRunner.Activity.$$dlg = P256CracenActivity
        SleepyRunner.iterations.$$val = 10
        SleepyRunner.interval_ms.$$val = 1000
        P256CracenActivity.public_key_only.$$val = false
        P256Cracen.light_pause.$$val = true
    }
}

export function em$run() {
    SleepyRunner.run()
}