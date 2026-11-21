import '@$$emscript'
export const $U = $declare('MODULE', ActivityI)

import * as ActivityI from '@em.mark/ActivityI.em'
import * as Common from '@em.mcu/Common.em'

export const duration_us = $config<u32>(50000)

export function setup() { }

export function exec() {
    Common.BusyWait.wait(duration_us)
}

export function teardown() { }