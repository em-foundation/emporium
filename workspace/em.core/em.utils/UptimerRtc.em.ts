import '@$$emscript'
export const $U = $declare('MODULE', UptimerI)

import * as RtcI from '@em.hal/RtcI.em'
import * as UptimerI from '@em.hal/UptimerI.em'
import * as T from '@em.utils/TimeTypes.em'

export const Rtc = $proxy<RtcI.$I>()

export function read(): T.RawTime {
    return Rtc.getRawTime()
}
