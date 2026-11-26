import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as Controller from '@em.link.ble/Controller.em'
import * as PacketCryptoN from '@em.link/PacketCryptoN.em'
import * as Smp from '@em.link.ble/Smp.em'
import * as SmpN from '@em.link.ble/SmpN.em'
import * as Link from '@em.link/Link.em'
import * as CryptoC from '@$distro/CryptoC.em'
import * as RadioC from '@$distro/RadioC.em'

export function em$configure(): void {
    $using(RadioC)
    Link.RadioDriver.$$dlg = RadioC.RadioDriver
    if (Controller.security_enabled.$$val) {
        $using(CryptoC)
        Controller.Smp.$$dlg = Smp
        Link.PacketCrypto.$$dlg = RadioC.PacketCrypto
    } else {
        Controller.Smp.$$dlg = SmpN
        Link.PacketCrypto.$$dlg = PacketCryptoN
    }
}
