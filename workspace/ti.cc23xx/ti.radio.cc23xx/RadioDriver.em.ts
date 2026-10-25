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
// Calibrated RX-to-TX command delay; RX uses a separate SYSTIM trigger.
const RX_IMMEDIATE_LEAD_US = 50

var cur_chan: u8
var cur_params: $$<TL.Params>
var cur_rx_buf: TL.BufPtr
var cur_state: volatile_t<State> = State.IDLE
var pause_handler: RadioDriverI.Handler = $null
var prepared_tx_power: u16
var prepared_tx_level: i8
var rx_end_time: u32
var rx_timeout: volatile_t<bool_t> = false
var tx_chained = false
var tx_start = 0
var enable_notify: bool_t

export function disable() {
    const key = GlobalInterrupts.disable()
    TxPacket_o.cancel()
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
    if (!CryptoExchange_o.configureRx()) {
        GlobalInterrupts.restore(key)
        return
    }
    setState(State.RX)
    cur_rx_buf = buf
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

    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_RX

    GlobalInterrupts.restore(key)
}

export function prepareTx(buf: TL.BufFrame) {
    TxPacket_o.prepare(buf)
}

export function startTx(chan: u8) {
    const buf = TxPacket_o.take()
    if (buf == $null) return
    const key = GlobalInterrupts.disable()

    setState(State.TX)
    cur_chan = chan

    CryptoExchange_o.beginTx(buf)
    if (!TxPacket_o.write(buf)) {
        GlobalInterrupts.restore(key)
        return
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
    // Calibrate the synthesizer for each TX.
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
                rx_timeout = true
                break
            }
            if ((mis & LRF.EventOpError) != 0) {
                const cause = $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE]
                printf`TI radio RX error=%04x FAIL\n`(cause)
                fail()
            }
            if ((mis & LRF.EventRxOk) == 0) {
                return
            }
            rx_end_time = nowTimeUs()
            tx_start = $R.SYSTIM.TIME250N.$$ + (TX_CHAIN_DELAY * 4)
            if (RfFifo.readPkt(cur_rx_buf, cur_params.$$.ble_acc_adr != 0, CryptoExchange_o.rxEncrypted()) == 0) {
                cur_rx_buf = $null
                break
            }

            if (CryptoExchange_o.rxEncrypted()) {
                CryptoExchange_o.deferRx()
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
                printf`TI radio TX error=%04x FAIL\n`(cause)
                fail()
            }

            if ((mis & LRF.EventOpDone) == 0) {
                return
            }
            if (CryptoExchange_o.completeTx()) return
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

function cryptoFB(_: arg_t) {
    CryptoExchange_o.completeRx()
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

// ---- TX packet storage ----

class WirePacket extends $vector<u8> { $len = 34 }

// One prepared candidate plus retained ciphertext for link-layer retries.
class TxPacket extends $struct {
    prepared_buf: TL.BufPtr
    prepared_len: u16
    cipher_buf: TL.BufPtr
    cipher_source: TL.BufPtr
    cipher_lo: u32
    cipher_hi: u8
    wire_source: TL.BufPtr
    wire_lo: u32
    wire_hi: u8
    wire: WirePacket
}
interface TxPacket {
    prepare(this: TxPacket, buf: TL.BufFrame): void
    stage(this: TxPacket, buf: TL.BufFrame): bool_t
    take(this: TxPacket): TL.BufFrame
    write(this: TxPacket, buf: TL.BufFrame): bool_t
    cancel(this: TxPacket): void
}

var TxPacket_o: TxPacket

TxPacket.prototype.prepare = function (this: TxPacket, buf: TL.BufFrame): void {
    // A fiber can prepare while a radio interrupt consumes the previous packet.
    const key = GlobalInterrupts.disable()
    const params = Registry.getParams()
    const src = <TL.BufPtr>$$(buf[0])
    if (!params.$$.ble_tx_encrypted) {
        this.cipher_buf = $null
        this.cipher_source = $null
        this.wire_source = $null
    } else if (src[1] != 0) {
        const lo = params.$$.ble_tx_ctr_lo
        const hi = params.$$.ble_tx_ctr_hi
        if (!(this.wire_source == src && this.wire_lo == lo && this.wire_hi == hi)
            && !(this.cipher_source == src && this.cipher_lo == lo && this.cipher_hi == hi)) {
            this.cipher_buf = Link.PacketCrypto.prepareTx(src, lo, hi)
            if (this.cipher_buf == $null) {
                GlobalInterrupts.restore(key)
                fail()
                return
            }
            this.cipher_source = src
            this.cipher_lo = lo
            this.cipher_hi = hi
        }
    }
    this.prepared_len = buf.$len
    this.prepared_buf = src
    GlobalInterrupts.restore(key)
}

TxPacket.prototype.stage = function (this: TxPacket, buf: TL.BufFrame): bool_t {
    const src = <TL.BufPtr>$$(buf[0])
    const lo = cur_params.$$.ble_tx_ctr_lo
    const hi = cur_params.$$.ble_tx_ctr_hi
    if (!(this.wire_source == src && this.wire_lo == lo && this.wire_hi == hi)) {
        if (this.cipher_source != src || this.cipher_lo != lo || this.cipher_hi != hi || this.cipher_buf == $null) {
            printf`TI TX ciphertext not prepared FAIL\n`()
            fail()
            return false
        }
        Mem.cpy(this.wire.$ptr(), this.cipher_buf, 3 + this.cipher_buf[1])
        this.wire_source = src
        this.wire_lo = lo
        this.wire_hi = hi
    }
    // CCM excludes SN/NESN/MD from AAD.
    this.wire[0] = buf[0]
    return true
}

TxPacket.prototype.take = function (this: TxPacket): TL.BufFrame {
    if (this.prepared_buf == $null) {
        printf`RadioDriver TX not prepared FAIL\n`()
        fail()
        return $null
    }
    const buf = this.prepared_buf.$frame(this.prepared_len)
    this.prepared_buf = $null
    return buf
}

TxPacket.prototype.cancel = function (this: TxPacket): void {
    this.prepared_buf = $null
}

TxPacket.prototype.write = function (this: TxPacket, buf: TL.BufFrame): bool_t {
    if (CryptoExchange_o.txEncrypted() && buf[1] != 0) {
        if (!this.stage(buf)) return false
        RfFifo.writePkt(this.wire.$frame(0, 3 + this.wire[1]), true)
    } else {
        RfFifo.writePkt(buf, cur_params.$$.ble_acc_adr != 0)
    }
    return true
}

// ---- Deferred crypto exchange ----

class EmptyReply extends $vector<u8> { $len = 3 }

class CryptoExchange extends $struct {
    empty_reply: EmptyReply
    reply_buf: TL.BufPtr
    reply_len: u16
    last_tx_flags: u8
    ack_pending: bool_t
    ack_flags: u8
    pending: volatile_t<bool_t>
    rx_lo: u32
    rx_hi: u8
    rx_encrypted: bool_t
    tx_encrypted: bool_t
}
interface CryptoExchange {
    configureRx(this: CryptoExchange): bool_t
    rxEncrypted(this: CryptoExchange): bool_t
    txEncrypted(this: CryptoExchange): bool_t
    beginTx(this: CryptoExchange, buf: TL.BufFrame): void
    deferRx(this: CryptoExchange): void
    completeTx(this: CryptoExchange): bool_t
    completeRx(this: CryptoExchange): void
}

var CryptoExchange_o: CryptoExchange

CryptoExchange.prototype.configureRx = function (this: CryptoExchange): bool_t {
    if (this.pending) {
        printf`TI RX buffer still owned by crypto FAIL\n`()
        fail()
        return false
    }
    this.rx_encrypted = cur_params.$$.ble_rx_encrypted
    if (!this.rx_encrypted) {
        this.reply_buf = $null
        this.ack_pending = false
    }
    // Profiles reset each event; pending ACKs must survive RX timeouts.
    cur_params.$$.ble_rx_ack_pending = this.ack_pending
    return true
}

CryptoExchange.prototype.rxEncrypted = function (this: CryptoExchange): bool_t {
    return this.rx_encrypted
}

CryptoExchange.prototype.txEncrypted = function (this: CryptoExchange): bool_t {
    return this.tx_encrypted
}

CryptoExchange.prototype.beginTx = function (this: CryptoExchange, buf: TL.BufFrame): void {
    this.tx_encrypted = cur_params.$$.ble_tx_encrypted
    this.last_tx_flags = buf[0]
}

CryptoExchange.prototype.deferRx = function (this: CryptoExchange): void {
    this.rx_lo = cur_params.$$.ble_rx_ctr_lo
    this.rx_hi = cur_params.$$.ble_rx_ctr_hi
    // A retry uses the last authenticated RX counter.
    if (cur_rx_buf[1] != 0 && (cur_rx_buf[0] & 0x08) != cur_params.$$.ble_rx_next_sn
        && (this.rx_lo != 0 || this.rx_hi != 0)) {
        if (this.rx_lo == 0) this.rx_hi -= 1
        this.rx_lo -= 1
    }
    this.pending = true
    this.rx_encrypted = false
    tx_chained = true
    if (this.reply_buf != $null) {
        // This reply was selected and encrypted after the previous event.
        prepareTx(this.reply_buf.$frame(this.reply_len))
    } else {
        // Do not acknowledge this RX until its MIC has been verified.
        // Reuse the old TX SN: the controller has not selected a new PDU.
        this.empty_reply[0] = 0x01 | (this.last_tx_flags & 0x08) | (cur_params.$$.ble_rx_next_sn >> 1)
        this.empty_reply[1] = 0
        this.empty_reply[2] = 0
        prepareTx(this.empty_reply.$frame())
    }
}

CryptoExchange.prototype.completeTx = function (this: CryptoExchange): bool_t {
    if (this.tx_encrypted) {
        Link.PacketCrypto.completeTx()
        this.tx_encrypted = false
    }
    if (this.ack_pending && (this.last_tx_flags & 0x04) == this.ack_flags) {
        this.ack_pending = false
        cur_params.$$.ble_rx_ack_pending = false
    }
    if (this.pending) {
        $R.LRFDDBELL.IMASK0.$$ = 0
        setState(State.READY)
        cryptoF.$$.post()
        return true
    }
    return false
}

// Own cur_rx_buf until authentication and the controller callback have finished.
// The next event is scheduled only after this fiber releases that ownership.
CryptoExchange.prototype.completeRx = function (this: CryptoExchange): void {
    if (!this.pending) return
    Link.PacketCrypto.prepareRx(cur_rx_buf, this.rx_lo, this.rx_hi)
    const plain = Link.PacketCrypto.completeRx()
    if (plain == $null) {
        printf`TI deferred RX MIC verification FAIL\n`()
        fail()
        return
    }
    if (plain != cur_rx_buf) Mem.cpy(cur_rx_buf, plain, 3 + plain[1])
    this.reply_buf = $null
    if (cur_params.$$.ble_chain != $null) {
        const tx = cur_params.$$.ble_chain(cur_rx_buf)
        if (tx != $null) {
            prepareTx(tx)
            if (cur_params.$$.ble_tx_encrypted && tx[1] != 0 && !TxPacket_o.stage(tx)) return
            this.reply_buf = <TL.BufPtr>$$(tx[0])
            this.reply_len = tx.$len
            this.ack_flags = tx[0] & 0x04
            this.ack_pending = (this.last_tx_flags & 0x04) != this.ack_flags
            cur_params.$$.ble_rx_ack_pending = this.ack_pending
        }
    }
    this.pending = false
    if (handler != $null) handler()
}
