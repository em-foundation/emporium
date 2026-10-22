import '@$$emscript'
export const $U = $declare('MODULE')

import * as Aes128TestP from '@em.crypto.tests/Aes128TestP.em'
import * as CmacTestP from '@em.crypto.tests/CmacTestP.em'
import * as CryptoC from '@nordic.distro.nrf54/CryptoC.em'

export namespace em$meta {
    export function em$configure() {
        $using(CryptoC)
    }
}

export function em$run() {
    Aes128TestP.em$run()
    CmacTestP.em$run()
}
