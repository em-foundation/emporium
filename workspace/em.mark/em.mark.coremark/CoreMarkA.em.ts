import '@$$emscript'
export const $U = $declare('MODULE', ActivityI)

import * as ActivityI from '@em.mark/ActivityI.em'
import * as CoreBench from '@em.benchmark.coremark/CoreBench.em'

var crc: u16

export function setup() {
    CoreBench.setup()
}

export function exec() {
    crc = CoreBench.run(0)
}

export function report() {
    printf`crc = %04x\n`(crc)
}

export function teardown() { }
