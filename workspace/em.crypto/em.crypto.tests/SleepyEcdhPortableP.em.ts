import '@$$emscript'
export const $U = $declare('MODULE')

import * as P256SoftwareActivity from '@em.crypto.tests/P256SoftwareActivity.em'
import * as SleepyRunner from '@em.utils/SleepyRunner.em'

export namespace em$meta {
    export function em$configure() {
        SleepyRunner.Activity.$$dlg = P256SoftwareActivity
        SleepyRunner.iterations.$$val = 1
        SleepyRunner.interval_ms.$$val = 1000
        P256SoftwareActivity.public_key_only.$$val = false
        P256SoftwareActivity.portable_math.$$val = true
    }
}

export function em$run() {
    SleepyRunner.run()
}