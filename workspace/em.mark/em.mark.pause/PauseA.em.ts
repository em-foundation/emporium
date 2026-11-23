import '@$$emscript'
export const $U = $declare('MODULE', ActivityI)

import * as ActivityI from '@em.mark/ActivityI.em'
import * as BoardC from '@$distro/BoardC.em'
import * as Poller from '@em.mcu/Poller.em'

export const OneShot = $delegate(BoardC.OneShot)

export const duration_us = $config<u32>(50000)

export namespace em$meta {
    export function em$construct() {
        Poller.OneShot.$$dlg = BoardC.OneShot
    }
}

export function setup() { }

export function exec() {
    Poller.upause(duration_us)
}

export function report() { }

export function teardown() { }
