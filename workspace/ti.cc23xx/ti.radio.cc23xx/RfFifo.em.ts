import '@$$emscript'
export const $U = $declare('MODULE')



import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Common from '@em.mcu/Common.em'
import * as TL from '@em.link/Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

export function prepareRX() {
    $R.LRFDPBE.FCMD.$$ = $R.LRFDPBE_FCMD_DATA_RXFIFO_RESET >> $R.LRFDPBE_FCMD_DATA_S
    let fcfg0 = $R.LRFDPBE.FCFG0.$$
    fcfg0 &= ~(<u32>($R.LRFDPBE_FCFG0_RXADEAL_M | $R.LRFDPBE_FCFG0_RXACOM_M))
    $R.LRFDPBE.FCFG0.$$ = fcfg0
    writeFifoPtr($R.LRFDPBE.RXFRP.$$ + 255, $R.LRFDPBE_BASE + $R.LRFDPBE_O_RXFSRP)
}

export function prepareTX() {
    $R.LRFDPBE.FCMD.$$ = ($R.LRFDPBE_FCMD_DATA_TXFIFO_RESET >> $R.LRFDPBE_FCMD_DATA_S)
    let txcfg = $R.LRFDPBE.FCFG0.$$
    txcfg &= ~(<u32>$R.LRFDPBE_FCFG0_TXADEAL_M)
    txcfg |= $R.LRFDPBE_FCFG0_TXACOM_M
    $R.LRFDPBE.FCFG0.$$ = txcfg
}


export function readPkt(buf: TL.BufPtr): u8 {
    var word = $reg32[$R.LRFDRXF_BASE]
    // printf`rxd[0] = %08x\n`(word)
    word = $reg32[$R.LRFDRXF_BASE]
    // printf`rxd[1] = %08x\n`(word)
    buf[0] = <u8>(word >> 16)
    buf[1] = <u8>(word >> 24)
    const sz = <u8>((buf[1] & 0x3f) + 2)
    var i: u8 = 2
    while (i < sz) {
        word = $reg32[$R.LRFDRXF_BASE]
        // printf`rxd[%d] = %08x\n`(i, word)
        buf[i] = <u8>(word >> 0)
        i += 1
        if (i >= sz) break
        buf[i] = <u8>(word >> 8)
        i += 1
        if (i >= sz) break
        buf[i] = <u8>(word >> 16)
        i += 1
        if (i >= sz) break
        buf[i] = <u8>(word >> 24)
        i += 1
    }
    return sz
}

export function writePkt(buf: TL.BufFrame) {
    prepareTX()
    const sz = <u8>buf.$len
    let word = <u32>(0x02030000 | (sz + 4))
    let addr = <u32>($R.LRFD_BUFRAM_BASE + ($R.LRFDPBE.FCFG1.$$ << 2))
    $reg32[addr] = word
    // printf`[%08x] = %08x\n`(addr, word)
    addr += 4
    word = <u32>0x00000001
    let mask: u32 = 0x00ff0000
    let shift: u8 = 16
    for (const b of buf) {
        if (mask == 0) {
            mask = 0x000000ff
            shift = 0
            $reg32[addr] = word
            // printf`[%08x] = %08x\n`(addr, word)
            addr += 4
            word = 0x00000000
        }
        word = (word & ~mask) | (<u32>b.$$ << shift)
        mask <<= 8
        shift += 8
    }
    $reg32[addr] = word
    // printf`[%08x] = %08x\n`(addr, word)
    writeFifoPtr(addr + 4, ($R.LRFDPBE_BASE + $R.LRFDPBE_O_TXFWP))

}

function writeFifoPtr(value: u32, regAddr: u32) {
    const key = Common.GlobalInterrupts.disable()
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>((($R.LRFDPBE_BASE + $R.LRFDPBE_O_FSTAT) & 0x0FFF) >> 2)
    // delay
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD]
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD]
    $reg32[regAddr] = value
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>((($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2)
    Common.GlobalInterrupts.restore(key)
}
