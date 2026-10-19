import '@$$emscript'
export const $U = $declare('MODULE')

import * as Common from '@em.mcu/Common.em'
import * as P256Cracen from '@nordic.mcu.nrf54/P256Cracen.em'
import * as T from '@em.crypto.p256/Types.em'
import * as TestVectors from '@em.crypto.p256/TestVectors.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$run() {
    Common.UsCounter.start()
    P256Cracen.initialize()
    const usecs = Common.UsCounter.stop()
    printf`CRACEN initialization (%d usecs; 4892 microcode bytes)\n`(usecs)
    TestVectors.em$run()
    // A second pass checks repeated operations within one powered session.
    TestVectors.em$run()
    let invalid = T.PubKey.$make()
    for (const i of $range(T.U256_LEN)) {
        invalid.x[i] = 0
        invalid.y[i] = 0
    }
    if (P256Cracen.validatePublicKey($$(invalid))) {
        printf`FAIL invalid public key accepted\n`()
        fail()
        return
    }
    printf`PASS invalid public key rejected\n`()
    P256Cracen.shutdown()
}