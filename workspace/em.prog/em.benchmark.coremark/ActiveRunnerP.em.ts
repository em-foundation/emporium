import '@$$emscript'
export const $U = $declare('MODULE')

import * as BoardC from '@$distro/BoardC.em'
import * as Common from '@em.mcu/Common.em'
import * as CoreBench from '@em.benchmark.coremark/CoreBench.em'
import * as Utils from '@em.benchmark.coremark/Utils.em'

const AppLed = $delegate(BoardC.AppLed)
const CacheStats = $delegate(BoardC.CacheStats)

const iterations = $config<u16>(10)

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function em$startup() {
    CoreBench.setup()
}

export function em$run() {
    AppLed.on()
    Common.BusyWait.wait(1_000_000)
    AppLed.off()
    CacheStats.start()
    Common.UsCounter.start()
    $['%%d+']
    for (const _ of $range(iterations)) {
        CoreBench.run(0)
    }
    $['%%d-']
    let usecs = Common.UsCounter.stop()
    CacheStats.stop()
    AppLed.on()
    Common.BusyWait.wait(1_000_000)
    AppLed.off()
    CacheStats.print()
    printf`usecs = %d\n`(usecs)
    printf`list crc = %04x\n`(Utils.getCrc(Utils.Kind.LIST))
    printf`matrix crc = %04x\n`(Utils.getCrc(Utils.Kind.MATRIX))
    printf`state crc = %04x\n`(Utils.getCrc(Utils.Kind.STATE))
    printf`final crc = %04x\n`(Utils.getCrc(Utils.Kind.FINAL))
}
