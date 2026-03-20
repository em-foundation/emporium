import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@nordic.distro.nrf54/REGS.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//


export function print() {
    const reads: u32 = $R.APPLICATION_ICACHE.PROFILING.READS.$$
    const writes: u32 = $R.APPLICATION_ICACHE.PROFILING.WRITES.$$
    const hit: u32 = $R.APPLICATION_ICACHE.PROFILING.HIT.$$
    const miss: u32 = $R.APPLICATION_ICACHE.PROFILING.MISS.$$
    const lmiss: u32 = $R.APPLICATION_ICACHE.PROFILING.LMISS.$$
    printf`*** cache stats: reads = %d, writes = %d, hit = %d, miss = %d, lmiss = %d\n`(reads, writes, hit, miss, lmiss)
}

export function start() {
    $R.APPLICATION_ICACHE.PROFILING.CLEAR.$$ = 1
    $R.APPLICATION_ICACHE.PROFILING.ENABLE.$$ = 1
}

export function stop() {
    $R.APPLICATION_ICACHE.PROFILING.ENABLE.$$ = 0
}
