import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as FiberMgr from '@em.utils/FiberMgr.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as Idle from '@ti.mcu.cc23xx/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LRF from '@ti.radio.cc23xx/LRF.em'
import * as Link from '@em.link/Link.em'
import * as Mem from '@em.utils/Mem.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as RfCtrl from '@ti.radio.cc23xx/RfCtrl.em'
import * as RfFifo from '@ti.radio.cc23xx/RfFifo.em'
import * as RfFreq from '@ti.radio.cc23xx/RfFreq.em'
import * as RfPatch from '@ti.radio.cc23xx/RfPatch.em'
import * as RfPower from '@ti.radio.cc23xx/RfPower.em'
import * as RfRegs from '@ti.radio.cc23xx/RfRegs.em'
import * as RfTrim from '@ti.radio.cc23xx/RfTrim.em'
import * as RfXtal from '@ti.radio.cc23xx/RfXtal.em'
import * as Rtc from '@ti.mcu.cc23xx/Rtc.em'
import * as TL from '@em.link/Types.em'

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

const handler = $config<RadioDriverI.Handler>()
const cryptoF = $config<FiberMgr.Obj>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LRFD_IRQ0')
        cryptoF.$$val = FiberMgr.em$meta.create($cb(cryptoFB))
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

//>> ---- em$targ ---- <<//

const TX_CHAIN_DELAY = 47
// RX starts on a future SYSTIM trigger; TX replies use the calibrated delay above.
const RX_IMMEDIATE_LEAD_US = 50

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_rx_buf: TL.BufPtr
var prepared_tx_buf: TL.BufPtr = $null
var prepared_tx_len: u16
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
class WirePacket extends $vector<u8> { $len = 34 }
var tx_wire: WirePacket
// Prepared ciphertext and the last transmitted ciphertext have independent ownership.
var cipher_buf: TL.BufPtr = $null
var cipher_source: TL.BufPtr = $null
var cipher_lo: u32
var cipher_hi: u8
var wire_source: TL.BufPtr = $null
var wire_lo: u32
var wire_hi: u8
class EmptyReply extends $vector<u8> { $len = 3 }
var empty_reply: EmptyReply
var reply_buf: TL.BufPtr = $null
var reply_len: u16
var last_tx_flags: u8
var rx_ack_pending: bool_t
var rx_ack_flags: u8
var crypto_pending: volatile_t<bool_t> = false
var crypto_lo: u32
var crypto_hi: u8
var rx_crypto: bool_t
var tx_crypto: bool_t
var prepared_tx_power: u16
var prepared_tx_level: i8
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false
var tx_chained = false
var tx_start = 0
var enable_notify: bool_t

export function disable() {
    const key = GlobalInterrupts.disable()
    prepared_tx_buf = $null
    setState(State.IDLE)
    enable_notify = false
    pause_handler = $null
    tx_chained = false
    Rtc.disableAux()
    IntrVec.NVIC_disable(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ = 0
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    RfCtrl.disable()
    RfXtal.disable()
    $['%%c-']
    $['%%d-']
    Idle.setLevel(0)
    GlobalInterrupts.restore(key)
}

// Synchronous entry point; startEnable() reports readiness through the handler.
export function enable() {
    beginEnable(false)
    waitReady()
}

function beginEnable(notify: bool_t) {
    const key = GlobalInterrupts.disable()
    cur_params = Registry.getParams()
    if (cur_params.$$.radio_phy != TL.Phy.BLE_1M) {
        printf`TI RadioDriver supports BLE_1M only\n`()
        fail()
    }
    enable_notify = notify
    Idle.setLevel(1) // keep radio RAM/clocks powered until disable()
    if (cur_state == State.IDLE) {
        setState(State.SETUP)
        RfXtal.start($cb(hfReadyHandler))
        RfCtrl.enableClocks()
        RfCtrl.resetBlocks()
        RfPatch.loadAll()
        // CPUIRQ3 cannot enter the ready callback until this setup is complete.
    } else {
        configureProfile()
        setState(State.READY)
        if (notify && handler != $null) handler()
    }
    GlobalInterrupts.restore(key)
}

function hfReadyHandler() {
    if (cur_state != State.SETUP) return
    RfRegs.setup()
    // Reset RX FIFO while PBE is stopped, preserving auto-deallocation settings.
    $R.LRFDPBE.FCMD.$$ = $R.LRFDPBE_FCMD_DATA_RXFIFO_RESET >> $R.LRFDPBE_FCMD_DATA_S
    RfTrim.apply()
    configureProfile()
    setState(State.READY)
    if (enable_notify && handler != $null) handler()
}

function configureProfile() {
    // Calculate temperature compensation before any RX/TX turnaround.
    prepared_tx_level = cur_params.$$.radio_power
    prepared_tx_power = RfPower.calculate(prepared_tx_level)
    const acc_adr = cur_params.$$.ble_acc_adr
    const crc_init = cur_params.$$.ble_crc_init
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2
    $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = acc_adr != 0 ? acc_adr : 0x8E89_BED6
    $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_CRCINITL] = (crc_init != 0 ? crc_init : 0x555555) << 8
}

export function getRxBuf(): TL.BufPtr {
    return rx_timeout ? $null : cur_rx_buf
}

export function getRxEndTimeUs(): u32 {
    return rx_end_time
}

export function nowTimeUs(): u32 {
    return Rtc.getRawUsecs()
}

export function pause(usecs: u32, handler: RadioDriverI.Handler) {
    pause_handler = handler
    Rtc.enableAuxUsecs(Rtc.getRawUsecs() + usecs, $cb(rtcHandler))
}

export function startEnable() {
    beginEnable(true)
}

export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16) {
    const key = GlobalInterrupts.disable()
    if (crypto_pending) {
        GlobalInterrupts.restore(key)
        printf`TI RX buffer still owned by crypto FAIL\n`()
        fail()
        return
    }
    setState(State.RX)
    cur_rx_buf = buf
    rx_crypto = cur_params.$$.ble_rx_encrypted
    if (!rx_crypto) {
        reply_buf = $null
        rx_ack_pending = false
    }
    // Registry profiles reset each event; retain pending ACKs across RX timeouts.
    cur_params.$$.ble_rx_ack_pending = rx_ack_pending
    cur_chan = chan
    RfCtrl.enableImages()
    rx_timeout = false
    rx_end_time = 0
    const whiten_init = chan | 0x40
    const cfg_val =
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXINCLUDEHDR_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATNOK_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = whiten_init
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_MAXLEN] = 256 // RfFifo enforces BLE packet length limits
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_RXTIMEOUT] = 0
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_FIRSTRXTIMEOUT] = 0
    let demc1be1 = $R.LRFDMDM.DEMC1BE1.$$
    demc1be1 = (demc1be1 & ~$R.LRFDMDM_DEMC1BE1_THRESHOLDB_M) | (0x7F << $R.LRFDMDM_DEMC1BE1_THRESHOLDB_S)
    $R.LRFDMDM.DEMC1BE1.$$ = demc1be1
    RfFreq.program(Channel.getFrequency(chan))
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ =
        LRF.EventOpDone |
        LRF.EventOpError |
        LRF.EventRxCtrl |
        LRF.EventRxNok |
        LRF.EventRxIgnored |
        LRF.EventRxEmpty |
        LRF.EventRxBufFull |
        LRF.EventRxOk |
        (timeout > 0 ? LRF.EventSystim1 : 0)
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    const rx_start_ticks = $R.SYSTIM.TIME250N.$$ + (RX_IMMEDIATE_LEAD_US * 4)
    $R.SYSTIM.CH2CC.$$ = rx_start_ticks
    if (timeout > 0) {
        $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM1_M
        $R.SYSTIM.CH3CC.$$ = rx_start_ticks + (<u32>timeout * 4000)
    }

    $['%%c+'] // RX active until receive completion or timeout
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_RX

    GlobalInterrupts.restore(key)
}

// Prepare RAM only; RX may still own radio registers and FIFOs.
export function prepareTx(buf: TL.BufFrame) {
    // A fiber can prepare while a radio interrupt consumes the previous packet.
    const key = GlobalInterrupts.disable()
    const params = Registry.getParams()
    const src = <TL.BufPtr>$$(buf[0])
    if (!params.$$.ble_tx_encrypted) {
        cipher_buf = $null
        cipher_source = $null
        wire_source = $null
    } else if (src[1] != 0) {
        const lo = params.$$.ble_tx_ctr_lo
        const hi = params.$$.ble_tx_ctr_hi
        if (!(wire_source == src && wire_lo == lo && wire_hi == hi)
            && !(cipher_source == src && cipher_lo == lo && cipher_hi == hi)) {
            cipher_buf = Link.PacketCrypto.prepareTx(src, lo, hi)
            if (cipher_buf == $null) {
                GlobalInterrupts.restore(key)
                fail()
                return
            }
            cipher_source = src
            cipher_lo = lo
            cipher_hi = hi
        }
    }
    prepared_tx_len = buf.$len
    prepared_tx_buf = src
    GlobalInterrupts.restore(key)
}

// Copy only in RAM; FIFO loading stays in startTx().
function stageCipher(buf: TL.BufFrame): bool_t {
    const src = <TL.BufPtr>$$(buf[0])
    const lo = cur_params.$$.ble_tx_ctr_lo
    const hi = cur_params.$$.ble_tx_ctr_hi
    if (!(wire_source == src && wire_lo == lo && wire_hi == hi)) {
        if (cipher_source != src || cipher_lo != lo || cipher_hi != hi || cipher_buf == $null) {
            printf`TI TX ciphertext not prepared FAIL\n`()
            fail()
            return false
        }
        Mem.cpy(tx_wire.$ptr(), cipher_buf, 3 + cipher_buf[1])
        wire_source = src
        wire_lo = lo
        wire_hi = hi
    }
    // CCM excludes SN/NESN/MD from AAD.
    tx_wire[0] = buf[0]
    return true
}

export function startTx(chan: u8) {
    if (prepared_tx_buf == $null) {
        printf`RadioDriver TX not prepared FAIL\n`()
        fail()
        return
    }
    const buf = prepared_tx_buf.$frame(prepared_tx_len)
    prepared_tx_buf = $null
    const key = GlobalInterrupts.disable()

    $['%%d+'] // TX preparation through completion
    setState(State.TX)
    cur_chan = chan

    tx_crypto = cur_params.$$.ble_tx_encrypted
    last_tx_flags = buf[0]
    if (tx_crypto && buf[1] != 0) {
        if (!stageCipher(buf)) {
            GlobalInterrupts.restore(key)
            return
        }
        RfFifo.writePkt(tx_wire.$frame(0, 3 + tx_wire[1]), true)
    } else {
        RfFifo.writePkt(buf, cur_params.$$.ble_acc_adr != 0)
    }

    if (cur_params.$$.radio_power == prepared_tx_level) {
        $R.LRFDRFE.SPARE5.$$ = prepared_tx_power
    } else {
        // Preserve dynamic power changes made after profile setup.
        RfPower.program(cur_params.$$.radio_power)
    }

    RfCtrl.enableImages()

    const whiten_init = chan | 0x40
    const keep_fs = cur_params.$$.ble_chain != $null
    // FS_NOCAL remains clear: every TX uses synthesizer calibration.
    const cfg_val =
        (2 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) |
        ((keep_fs ? 1 : 0) << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = whiten_init
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    if (!tx_chained) {
        RfFreq.program(Channel.getFrequency(chan))
    }
    $R.LRFDDBELL.ICLR0.$$ = 0xffff_ffff
    $R.LRFDDBELL.IMASK0.$$ = LRF.EventOpDone | LRF.EventOpError
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)

    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = tx_chained ? tx_start : $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_TX
    tx_chained = false
    GlobalInterrupts.restore(key)
}

export function waitReady() {
    while (true) {
        const key = GlobalInterrupts.disable()
        if (cur_state == State.READY) {
            GlobalInterrupts.restore(key)
            break
        }
        Idle.exec()
        GlobalInterrupts.restore(key)
    }
}

export function LRFD_IRQ0_isr$$() {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    switch (cur_state) {
        case State.RX: {
            if ((mis & LRF.EventSystim1) != 0 && (mis & LRF.EventRxOk) == 0) {
                $['%%c-']
                rx_timeout = true
                break
            }
            if ((mis & LRF.EventOpError) != 0) {
                const cause = $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE]
                printf`OpError: %04x\n`(cause)
                printf`FCFG0: %08x\n`($R.LRFDPBE.FCFG0.$$)
                printf`RXFRP: %08x\n`($R.LRFDPBE.RXFRP.$$)
                printf`RXFWP: %08x\n`($R.LRFDPBE.RXFWP.$$)
                printf`RXFREADABLE: %08x\n`($R.LRFDPBE.RXFREADABLE.$$)
                printf`RXFWRITABLE: %08x\n`($R.LRFDPBE.RXFWRITABLE.$$)
                fail()
            }
            if ((mis & LRF.EventRxOk) == 0) {
                return
            }
            rx_end_time = nowTimeUs()
            tx_start = $R.SYSTIM.TIME250N.$$ + (TX_CHAIN_DELAY * 4)
            $['%%c-']
            if (RfFifo.readPkt(cur_rx_buf, cur_params.$$.ble_acc_adr != 0, rx_crypto) == 0) {
                cur_rx_buf = $null
                break
            }

            if (rx_crypto) {
                crypto_lo = cur_params.$$.ble_rx_ctr_lo
                crypto_hi = cur_params.$$.ble_rx_ctr_hi
                // A retry uses the last authenticated RX counter.
                if (cur_rx_buf[1] != 0 && (cur_rx_buf[0] & 0x08) != cur_params.$$.ble_rx_next_sn
                    && (crypto_lo != 0 || crypto_hi != 0)) {
                    if (crypto_lo == 0) crypto_hi -= 1
                    crypto_lo -= 1
                }
                crypto_pending = true
                rx_crypto = false
                tx_chained = true
                if (reply_buf != $null) {
                    // This reply was selected and encrypted after the previous event.
                    prepareTx(reply_buf.$frame(reply_len))
                } else {
                    // Do not acknowledge this RX until its MIC has been verified.
                    // Reuse the old TX SN: the controller has not selected a new PDU.
                    empty_reply[0] = 0x01 | (last_tx_flags & 0x08) | (cur_params.$$.ble_rx_next_sn >> 1)
                    empty_reply[1] = 0
                    empty_reply[2] = 0
                    prepareTx(empty_reply.$frame())
                }
                startTx(cur_chan)
                return
            }

            if (cur_params.$$.ble_chain != $null) {
                const tx_buf = cur_params.$$.ble_chain(cur_rx_buf)
                if (tx_buf != $null) {
                    tx_chained = true
                    prepareTx(tx_buf)
                    startTx(cur_chan)
                    return
                }
            }
            break
        }
        case State.TX: {
            if ((mis & LRF.EventOpError) != 0) {
                const cause = $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE]
                $['%%>'](cause)
                fail()
            }

            if ((mis & LRF.EventOpDone) == 0) {
                return
            }
            if (tx_crypto) {
                Link.PacketCrypto.completeTx()
                tx_crypto = false
            }
            $['%%d-']
            if (rx_ack_pending && (last_tx_flags & 0x04) == rx_ack_flags) {
                rx_ack_pending = false
                cur_params.$$.ble_rx_ack_pending = false
            }
            if (crypto_pending) {
                $R.LRFDDBELL.IMASK0.$$ = 0
                setState(State.READY)
                cryptoF.$$.post()
                return
            }
            if (cur_params.$$.ble_exch_buf != $null) {
                startRx(cur_params.$$.ble_exch_buf, cur_chan, cur_params.$$.ble_exch_end_ms)
                return
            }
            break
        }
        default: {
            return
        }
    }
    $R.LRFDDBELL.IMASK0.$$ = 0
    setState(State.READY)
    if (handler != $null) handler()
}

// Own cur_rx_buf until authentication and the controller callback have finished.
// The next event is scheduled only after this fiber releases that ownership.
function cryptoFB(_: arg_t) {
    if (!crypto_pending) return
    Link.PacketCrypto.prepareRx(cur_rx_buf, crypto_lo, crypto_hi)
    const plain = Link.PacketCrypto.completeRx()
    if (plain == $null) {
        printf`TI deferred RX MIC verification FAIL\n`()
        fail()
        return
    }
    if (plain != cur_rx_buf) Mem.cpy(cur_rx_buf, plain, 3 + plain[1])
    reply_buf = $null
    if (cur_params.$$.ble_chain != $null) {
        const tx = cur_params.$$.ble_chain(cur_rx_buf)
        if (tx != $null) {
            prepareTx(tx)
            if (cur_params.$$.ble_tx_encrypted && tx[1] != 0 && !stageCipher(tx)) return
            reply_buf = <TL.BufPtr>$$(tx[0])
            reply_len = tx.$len
            rx_ack_flags = tx[0] & 0x04
            rx_ack_pending = (last_tx_flags & 0x04) != rx_ack_flags
            cur_params.$$.ble_rx_ack_pending = rx_ack_pending
        }
    }
    crypto_pending = false
    if (handler != $null) handler()
}

function rtcHandler() {
    Rtc.disableAux()
    if (pause_handler != $null) {
        const h = pause_handler
        pause_handler = $null
        h()
        return
    }
}

function setState(s: State) {
    cur_state = s
}

