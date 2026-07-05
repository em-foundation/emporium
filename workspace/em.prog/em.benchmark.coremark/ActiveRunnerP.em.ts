import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as CoreBench from '@em.benchmark.coremark/CoreBench.em'
import * as UT from '@em.benchmark.coremark/Utils.em'

const AppLed = $delegate(BoardC.AppLed)

const iterations = $config<u16>(10)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$startup() {
    CoreBench.setup()
}

export function em$run() {
    AppLed.wink(1000)
    Common.UsCounter.start()
    for (const _ of $range(iterations)) {
        CoreBench.run(0)
    }
    const usecs = Common.UsCounter.stop()
    AppLed.wink(1000)
    printf`usecs = %d\n`(usecs)
    printf`list crc = %04x\n`(UT.getCrc(UT.Kind.LIST))
    printf`matrix crc = %04x\n`(UT.getCrc(UT.Kind.MATRIX))
    printf`state crc = %04x\n`(UT.getCrc(UT.Kind.STATE))
    printf`final crc = %04x\n`(UT.getCrc(UT.Kind.FINAL))
}
