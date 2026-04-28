import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as $R from '@ti.distro.cc23xx/REGS.em'

import * as Channel from '@em.link.ble/Channel.em'
import * as Idle from '@ti.mcu.cc23xx/Idle.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as LRF from '@ti.radio.cc23xx/LRF.em'
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
import * as T from '@em.link/Types.em'

enum State {
    IDLE, SETUP, READY, RX, TX, CS, CW
}

const handler = $config<RadioDriverI.Handler>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LRFD_IRQ0')
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

//>> ---- em$targ ---- <<//

var cur_params: $$<const_t<T.Params>>
var cur_phy: T.Phy
var cur_state: volatile_t<State> = State.IDLE
var rx_timeout = false

export function disable() {
    Idle.setPauseOnly(false)
    setState(State.IDLE)
    RfCtrl.disable()
    RfXtal.disable()
}

export function enable() {
    cur_params = Registry.getParams()
    cur_phy = cur_params.$$.radio_phy
    setState(State.SETUP)
    RfXtal.enable()
    RfCtrl.enableClocks()
    RfPatch.loadAll(cur_phy)
    RfXtal.waitReady() // latest possible sync point
    RfRegs.setup()
    $reg32[$R.LRFDRFE_BASE + $R.LRFDRFE_O_RSSI] = 127
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_FIFOCMDADD] = <u16>(($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD) & 0x0FFF) >> 2
    RfTrim.apply()
    switch (cur_phy) {
        case T.Phy.BLE_1M:
            $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = 0x8E89_BED6
            $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_CRCINITL] = (0x555555 << 8)
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_EXTRABYTES] = 6 // stat + rssi + timestamp
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRL] = 0xAAAA
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRM] = 0xBBBB
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRH] = 0xCCCC
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_ADVCFG] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FILTPOLICY] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_RPACONNECT] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_RPACONNECT] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FL1MASK] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_FL2MASK] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 0
            break
        case T.Phy.PROP_1M:
        case T.Phy.PROP_250K:
            $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = 0x7B8A_D0C9 // scramble(0x930B_51DE)
            break
    }
    Idle.setPauseOnly(true)
    setState(State.READY)
}

export function readPkt(pkt: frame_t<u8>): u8 {
    if (rx_timeout) return 0
    const sz = RfFifo.readPkt(pkt);
    return sz
}

function setState(s: State) {
    // $['%%c:'](s)
    cur_state = s
}

export function startCs(chan: u8, timeout: u16) {
    setState(State.CS)
    RfCtrl.enableImages()
    const cfg_val: u32 =
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXFILTEROP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXINCLUDEHDR_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATNOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
        // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
        // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_MAXLEN] = 32 // TODO
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_RXTIMEOUT] = timeout * 4
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_FIRSTRXTIMEOUT] = timeout * 4
    RfFreq.program(Channel.getFrequency(chan), cur_phy)
    $R.LRFDDBELL.IMASK0.$$ |= LRF.EventOpDone | LRF.EventOpError
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_RX
}

export function startCw(chan: u8, power: i8) {
    setState(State.CW)
    RfPower.program(power)
    RfCtrl.enableImages()
    const cfg_val: u32 =
        (1 << $R.PBE_GENERIC_RAM_OPCFG_TXINFINITE_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_TXPATTERN_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
        // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
        // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
        (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
        (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = ($R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_PATTERN] = 0
    $R.LRFDMDM.MODCTRL.$$ |= $R.LRFDMDM_MODCTRL_TONEINSERT_M
    RfFreq.program(Channel.getFrequency(chan), cur_phy)
    $R.LRFDDBELL.IMASK0.$$ |= LRF.EventOpDone | LRF.EventOpError
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_TX
}

/// TODO: re-work RX

export function startRx(chan: u8, timeout: u16) {
    setState(State.RX)
    RfFifo.prepareRX()
    RfCtrl.enableImages()
    rx_timeout = false
    const whiten_init = chan | 0x40
    let op = 0
    switch (cur_phy) {
        case T.Phy.BLE_1M:
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_MAXLEN] = 37
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 1 << $R.PBE_BLE5_RAM_OPCFG_REPEAT_S
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_WHITEINIT] = whiten_init
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRL] = 0xDDDD
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRM] = 0xEEEE
            // $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OWNADRH] = 0xFFFF

            // hal_setup_sync_found_cap
            $R.LRFDMDM.SYSTIMEVTMUX0.$$ = (21 << $R.LRFDMDM_SYSTIMEVTMUX0_SEL0_S)
            $R.LRFDDBELL.SYSTIMOEV.$$ = $R.LRFDDBELL_SYSTIMOEV_SRC2_MCESYSTIM0
            $R.SYSTIM.CH4CFG.$$ |= $R.SYSTIM_CH4CFG_INP_RISE | $R.SYSTIM_CH4CFG_MODE_CAPT | $R.SYSTIM_CH4CFG_REARM_EN;

            // reg($R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA).* = 0x8E89_BED6 ^ (em.as(u32, whiten_init) << 24)

            // reg($R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA).* = 0x7176_4129
            // var demc1be0 = reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE0).*
            // var demc1be2 = reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE2).*
            // demc1be0 |= $R.LRFDMDM_DEMC1BE0_MASKA_M | $R.LRFDMDM_DEMC1BE0_MASKB_M
            // demc1be2 = (demc1be2 & ~$R.LRFDMDM_DEMC1BE2_THRESHOLDC_M) | (0x7F << $R.LRFDMDM_DEMC1BE2_THRESHOLDC_S)
            // reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE0).* = demc1be0
            // reg($R.LRFDMDM_BASE + $R.LRFDMDM_O_DEMC1BE2).* = demc1be2
            op = $R.PBE_BLE5_REGDEF_API_OP_RXRAW
            break
        case T.Phy.PROP_1M:
        case T.Phy.PROP_250K:
            const cfg_val: u32 =
                (0 << $R.PBE_GENERIC_RAM_OPCFG_RXFILTEROP_S) |
                (1 << $R.PBE_GENERIC_RAM_OPCFG_RXINCLUDEHDR_S) |
                (1 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATNOK_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
                // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
                // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
                (1 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
                (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_MAXLEN] = 256 // TODO
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_RXTIMEOUT] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_FIRSTRXTIMEOUT] = 0
            let demc1be1 = $R.LRFDMDM.DEMC1BE1.$$
            demc1be1 = (demc1be1 & ~$R.LRFDMDM_DEMC1BE1_THRESHOLDB_M) | (0x7F << $R.LRFDMDM_DEMC1BE1_THRESHOLDB_S)
            $R.LRFDMDM.DEMC1BE1.$$ = demc1be1
            op = $R.PBE_GENERIC_REGDEF_API_OP_RX
            break
    }
    RfFreq.program(Channel.getFrequency(chan), cur_phy)
    $R.LRFDDBELL.IMASK0.$$ |= LRF.EventOpError | LRF.EventRxNok | LRF.EventRxOk | LRF.EventSystim1
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$ + 1000
    if (timeout > 0) {
        $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM1_M
        $R.SYSTIM.CH3CC.$$ = $R.SYSTIM.TIME250N.$$ + (<u32>timeout * 4000)
    }
    $R.LRFDPBE.API.$$ = op
}

export function startTx(buf: T.BufFrame, chan: u8) {
    setState(State.TX)
    // _ = pkt
    RfFifo.writePkt(buf)
    // reg($R.LRFDPBE_BASE + $R.LRFDPBE_O_FCMD).* = ($R.LRFDPBE_FCMD_DATA_TXFIFO_RETRY >> $R.LRFDPBE_FCMD_DATA_S)
    RfPower.program(cur_params.$$.radio_power)
    RfCtrl.enableImages()
    let op = 0
    switch (cur_phy) {
        case T.Phy.BLE_1M:
            op = $R.PBE_BLE5_REGDEF_API_OP_TXRAW
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_OPCFG] = 0
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_BLE5_RAM_O_WHITEINIT] = chan | 0x40
            break
        case T.Phy.PROP_1M:
        case T.Phy.PROP_250K:
            op = $R.PBE_GENERIC_REGDEF_API_OP_TX
            const cfg_val =
                (0 << $R.PBE_GENERIC_RAM_OPCFG_TXINFINITE_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_TXPATTERN_S) |
                (2 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_START_S) |
                // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_NOCAL_S) |
                // (1 << $R.PBE_GENERIC_RAM_OPCFG_FS_KEEPON_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_RXREPEATOK_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_NEXTOP_S) |
                (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_IFSPERIOD_S) |
                (0 << $R.PBE_GENERIC_RAM_OPCFG_RFINTERVAL_S)
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] = <u16>cfg_val
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
            break
    }
    RfFreq.program(Channel.getFrequency(chan), cur_phy)
    $R.LRFDDBELL.IMASK0.$$ |= LRF.EventOpDone | LRF.EventOpError
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    while ($reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) { }
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$
    $R.LRFDPBE.API.$$ = op
}

export function waitReady() {
    while (cur_state != State.READY) {
        Idle.exec()
    }
}

export function LRFD_IRQ0_isr$$() {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    // $['%%a']
    // $['%%>'](mis)
    if ((mis & LRF.EventOpError) != 0) {
        $['%%>']($reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE])
        fail()
    }
    if ((mis & LRF.EventSystim1) != 0) {
        rx_timeout = true
    }
    // if ((mis & $R.LRF_EventRxOk) != 0) {
    //     em.print("peek {x}\n", .{RfFifo.peek(0)})
    // }
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    if (cur_params.$$.ble_chain != $null) {
        printf`chain`()
        halt()
    }
    setState(State.READY)
    if (handler != $null) handler()
}
