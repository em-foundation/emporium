import '@$$emscript'
export const $U = $declare('MODULE', RadioDriverI)

import * as Channel from '@em.link.ble/Channel.em'
import * as Common from '@em.mcu/Common.em'
import * as GlobalInterrupts from '@em.arch.arm/GlobalInterrupts.em'
import * as IntrVec from '@em.arch.arm/IntrVec.em'
import * as RadioDriverI from '@em.link/RadioDriverI.em'
import * as Registry from '@em.link/Registry.em'
import * as TL from '@em.link/Types.em'
import * as Idle from '@ti.mcu.cc27xx/Idle.em'
import * as RfCtrl from '@ti.radio.cc27xx/RfCtrl.em'
import * as RfFifo from '@ti.radio.cc27xx/RfFifo.em'
import * as RfFreq from '@ti.radio.cc27xx/RfFreq.em'
import * as RfPatch from '@ti.radio.cc27xx/RfPatch.em'
import * as RfPower from '@ti.radio.cc27xx/RfPower.em'
import * as RfRegs from '@ti.radio.cc27xx/RfRegs.em'
import * as RfTrim from '@ti.radio.cc27xx/RfTrim.em'
import * as RfXtal from '@ti.radio.cc27xx/RfXtal.em'
import * as $R from '@ti.distro.cc27xx/REGS.em'

const handler = $config<RadioDriverI.Handler>()

export namespace em$meta {
    export function em$construct() {
        IntrVec.em$meta.useIntr('LRFD_IRQ0')
    }
    export function bindHandler(h: RadioDriverI.Handler) {
        handler.$$val = h
    }
}

enum State { OFF, READY, TX }
var state: volatile_t<State> = State.OFF
var prepared: TL.BufFrame = $null
var old_ipeak: u32
var tx_channel: u8

function setIpeak(value: u32): void {
    const key = GlobalInterrupts.disable()
    const reg = ($reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] & ~$R.SYS0_TMUTE4_IPEAK_M)
        | (value << $R.SYS0_TMUTE4_IPEAK_S)
    $reg32[$R.SYS0_BASE + $R.SYS0_O_MUNLOCK] = $R.SYS0_MUNLOCK_KEY_UNLOCK
    $reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] = reg
    $reg32[$R.SYS0_BASE + $R.SYS0_O_MUNLOCK] = $R.SYS0_MUNLOCK_KEY_LOCK
    GlobalInterrupts.restore(key)
}

export function enable(): void {
    startEnable()
    waitReady()
}

export function startEnable(): void {
    if (state != State.OFF) fail()
    const params = Registry.getParams()
    if (params.$$.radio_phy != TL.Phy.BLE_1M
        || params.$$.radio_power != 0 || params.$$.ble_acc_adr != 0
        || params.$$.ble_tx_encrypted) fail()
    Idle.setLevel(1)
    RfXtal.enable()
    RfCtrl.enableClocks()
    RfCtrl.resetBlocks()
    RfPatch.loadAll()
    RfRegs.setup()
    RfTrim.apply()
    old_ipeak = ($reg32[$R.SYS0_BASE + $R.SYS0_O_TMUTE4] & $R.SYS0_TMUTE4_IPEAK_M) >> $R.SYS0_TMUTE4_IPEAK_S
    setIpeak(3)
    $reg32[$R.LRFDPBE32_BASE + $R.LRFDPBE32_O_MDMSYNCA] = 0x8e89bed6
    $reg32[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_CRCINITL] = 0x55555500
    state = State.READY
    if (handler != $null) handler()
}

export function prepareTx(buf: TL.BufFrame): void {
    if (state != State.READY || buf.$len < 2 || buf.$len > 39) fail()
    prepared = buf
}

export function startTx(chan: u8): void {
    if (state != State.READY || prepared == $null || chan < 37 || chan > 39) fail()
    const key = GlobalInterrupts.disable()
    state = State.TX
    tx_channel = chan
    RfPower.program(0)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_OPCFG] =
        (2 << $R.PBE_GENERIC_RAM_OPCFG_TXFCMD_S) | (1 << $R.PBE_GENERIC_RAM_OPCFG_SINGLE_S)
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_WHITEINIT] = chan | 0x40
    $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_GENERIC_RAM_O_NESB] = $R.PBE_GENERIC_RAM_NESB_NESBMODE_OFF
    $reg32[$R.LRFDRFE32_BASE + $R.LRFDRFE32_O_ATSTREF] |= $R.LRFDRFE32_ATSTREF_BIAS_M
    RfFreq.program(Channel.getFrequency(chan))
    Common.BusyWait.wait(30)
    RfCtrl.enableImages()
    $R.LRFDDBELL.ICLR0.$$ = 0xffffffff
    $R.LRFDDBELL.IMASK0.$$ = $R.LRFDDBELL_IMASK0_PBE0 | $R.LRFDDBELL_IMASK0_PBE15
    IntrVec.NVIC_enable(e$`LRFD_IRQ0_IRQn`)
    let tries: u32 = 0
    while ($reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_MSGBOX] == 0) {
        if (tries++ == 10000) {
            GlobalInterrupts.restore(key)
            printf`CC27xx PBE startup timeout\n`()
            fail()
        }
        Common.BusyWait.wait(1)
    }
    RfFifo.writePkt(prepared, false)
    prepared = $null
    // Allow PBE to accept OP_TX before its scheduled start event.
    $R.LRFDDBELL.ICLR0.$$ = $R.LRFDDBELL_ICLR0_SYSTIM0
    $R.SYSTIM.CH2CC.$$ = $R.SYSTIM.TIME250N.$$ + 400 // 100 us at 4 MHz
    $R.LRFDPBE.API.$$ = $R.PBE_GENERIC_REGDEF_API_OP_TX
    GlobalInterrupts.restore(key)
}

export function waitReady(): void {
    while (true) {
        const key = GlobalInterrupts.disable()
        if (state == State.READY) {
            GlobalInterrupts.restore(key)
            return
        }
        Idle.exec()
        GlobalInterrupts.restore(key)
    }
}

export function LRFD_IRQ0_isr$$(): void {
    const mis = $R.LRFDDBELL.MIS0.$$
    $R.LRFDDBELL.ICLR0.$$ = mis
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    if (mis & $R.LRFDDBELL_IMASK0_PBE15) {
        printf`CC27xx TX error %04x, channel=%d, RFE=%04x, HFXTSTAT=%08x, CKMD_RIS=%08x\n`(
            $reg16[$R.LRFD_BUFRAM_BASE + $R.PBE_COMMON_RAM_O_ENDCAUSE],
            tx_channel, $R.LRFDRFE.MSGBOX.$$, $R.CKMD.HFXTSTAT.$$, $R.CKMD.RIS.$$)
        fail()
    }
    if (!(mis & $R.LRFDDBELL_IMASK0_PBE0)) return
    RfCtrl.disable()
    $R.LRFDDBELL.IMASK0.$$ = 0
    state = State.READY
    if (handler != $null) handler()
}

export function disable(): void {
    if (state != State.READY) fail()
    IntrVec.NVIC_disable(e$`LRFD_IRQ0_IRQn`)
    $R.LRFDDBELL.IMASK0.$$ = 0
    $R.LRFDDBELL.ICLR0.$$ = 0xffffffff
    IntrVec.NVIC_clear(e$`LRFD_IRQ0_IRQn`)
    RfCtrl.disable()
    setIpeak(old_ipeak)
    RfXtal.disable()
    prepared = $null
    state = State.OFF
    Idle.setLevel(0)
}

export function nowTimeUs(): u32 {
    return $R.SYSTIM.TIME1U.$$
}
export function getRxBuf(): TL.BufPtr {
    fail()
    return $null
}
export function getRxEndTimeUs(): u32 {
    fail()
    return 0
}
export function pause(usecs: u32, h: RadioDriverI.Handler): void {
    fail()
}
export function startRx(buf: TL.BufPtr, chan: u8, timeout: u16): void {
    fail()
}
