import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Link from '@em.link/Link.em'
import * as CryptoC from '@$distro/CryptoC.em'
import * as RadioC from '@$distro/RadioC.em'

export function em$configure(): void {
    $using(CryptoC)
    $using(RadioC)
    Link.RadioDriver.$$dlg = RadioC.RadioDriver
    Link.PacketCrypto.$$dlg = RadioC.PacketCrypto
}
