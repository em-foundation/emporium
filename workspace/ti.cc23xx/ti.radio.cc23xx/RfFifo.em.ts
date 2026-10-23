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


export function readPkt(buf: TL.BufPtr, connected: bool_t): u8 {
    var word = $reg32[$R.LRFDRXF_BASE]
    // printf`rxd[0] = %08x\n`(word)
    word = $reg32[$R.LRFDRXF_BASE]
    // printf`rxd[1] = %08x\n`(word)
    buf[0] = <u8>(word >> 16)
    buf[1] = <u8>(word >> 24)
    const payload_len = connected ? buf[1] : (buf[1] & 0x3f)
    // Controller buffers are 40 bytes. Connected RAM has an extra S1 byte;
    // advertising/CONNECT_IND retain the original two-byte header.
    if (payload_len > (connected ? 27 : 37)) return 0
    const header_len: u8 = connected ? 3 : 2
    if (connected) buf[2] = 0
    const sz = <u8>(payload_len + header_len)
    var i: u8 = header_len
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

export function writePkt(buf: TL.BufFrame, connected: bool_t) {
    prepareTX()
    const sz = <u8>(buf.$len - (connected ? 1 : 0))
    let word = <u32>(0x02030000 | (sz + 4))
    let addr = <u32>($R.LRFD_BUFRAM_BASE + ($R.LRFDPBE.FCFG1.$$ << 2))
    $reg32[addr] = word
    // printf`[%08x] = %08x\n`(addr, word)
    addr += 4
    // First FIFO word contains the command and the two on-air header bytes.
    // Skip the connected packet's RAM-only S1 byte once, before the payload.
    word = <u32>0x00000001 | (<u32>buf[0] << 16) | (<u32>buf[1] << 24)
    $reg32[addr] = word
    addr += 4
    let i: u16 = connected ? 3 : 2
    while (i + 4 <= buf.$len) {
        word = <u32>buf[i] | (<u32>buf[i + 1] << 8)
            | (<u32>buf[i + 2] << 16) | (<u32>buf[i + 3] << 24)
        $reg32[addr] = word
        addr += 4
        i += 4
    }
    // Zero-pad a partial final payload word.
    word = 0
    let shift: u8 = 0
    while (i < buf.$len) {
        word |= <u32>buf[i] << shift
        shift += 8
        i += 1
    }
    if (shift != 0) {
        $reg32[addr] = word
        addr += 4
    }
    writeFifoPtr(addr, ($R.LRFDPBE_BASE + $R.LRFDPBE_O_TXFWP))

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
