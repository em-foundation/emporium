import em from '@$$emscript'
export const $U = em.$declare('MODULE')

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as Dma from '@ti.mcu.cc23xx/Dma.em'
import * as Idle from '@ti.mcu.cc23xx/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'

class ChanCtrl extends $struct {
    src_end_addr: u32
    dst_end_addr: u32
    ctrl_word: u32
    unused: u32
}

var ctrl_tab = $table<ChanCtrl>('rw', 8, 256)

const BUFLEN = 1000

var src_buf = $table<u32>('rw', BUFLEN)
var dst_buf = $table<u32>('rw', BUFLEN)

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('DMA_DONE_COMB')
        for (const i of $range(BUFLEN)) {
            src_buf.$add(i)
        }
    }
}

//>> ---- em$targ ---- <<//

const chan_mask = 1 << 6

var active_flag: volatile_t<bool_t>

export function em$run() {
    $R.CLKCTL.CLKENSET0.$$ = $R.CLKCTL_CLKENSET0_DMA
    $R.DMA.CFG.$$ = $R.DMA_CFG_MASTERENABLE
    $R.DMA.CTRL.$$ = <u32><arg_t>ctrl_tab.$ptr()
    $R.DMA.CLEARCHNLPRIALT.$$ = chan_mask
    $R.DMA.CLEARBURST.$$ = chan_mask
    $R.DMA.CLEARREQMASK.$$ = chan_mask
    ctrl_tab[6].src_end_addr = <u32><arg_t>src_buf.$ptr() + (BUFLEN * 4)
    ctrl_tab[6].dst_end_addr = <u32><arg_t>dst_buf.$ptr() + (BUFLEN * 4)
    ctrl_tab[6].ctrl_word = (BUFLEN << Dma.XFER_SIZE_S) |
        Dma.MODE_AUTO | Dma.SIZE_32 | Dma.SRC_INC_32 | Dma.DST_INC_32 | Dma.ARB_1024

    IntrVec.NVIC_enable(e$`DMA_DONE_COMB_IRQn`)
    active_flag = true
    $R.DMA.DONEMASK.$$ = chan_mask
    $R.DMA.SETCHANNELEN.$$ = chan_mask
    $R.DMA.SOFTREQ.$$ = chan_mask
    $['%%d+']
    Common.GlobalInterrupts.$$.enable()
    Idle.setPauseOnly(true)
    while (active_flag) Idle.exec()
    $['%%d-']
    $['%%c+']
    for (const i of $range(BUFLEN)) {
        dst_buf[i] = src_buf[i]
    }
    $['%%c-']
    // printf`last = %d\n`(dst_buf[BUFLEN - 1])
}

export function DMA_DONE_COMB_isr$$() {
    $['%%a']
    $R.DMA.REQDONE.$$ = chan_mask
    IntrVec.NVIC_clear(e$`DMA_DONE_COMB_IRQn`)
    active_flag = false
}