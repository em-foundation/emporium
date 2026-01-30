import '@$$emscript'
export const $U = $declare('COMPOSITE')

import * as BoardC from '@emm.distro.9305/BoardC.em'
import * as IntrVec from '@em.arch.arc/IntrVec.em'
import * as IsrDefault from '@em.utils/IsrEmpty.em'
import * as LinkerC from '@emm.distro.9305/LinkerC.em'
import * as REGS from '@emm.distro.9305/REGS.em'
import * as StartupC from '@emm.distro.9305/StartupC.em'
import * as TargC from '@em.lang/TargC.em'

const INTRS = <Array<string>>[
    'ARC_TIMER_0',
    'ARC_TIMER_1',
    'ARC_WATCHDOG',
    'ARC_DMA_DONE',
    'ARC_DMA_ERROR',
    'PROTOCOL_TIMER_OUT_CMP_0',
    'PROTOCOL_TIMER_OUT_CMP_1',
    'PROTOCOL_TIMER_OUT_CMP_2',
    'PROTOCOL_TIMER_OUT_CMP_3',
    'PROTOCOL_TIMER_OUT_CMP_4',
    'PROTOCOL_TIMER_OUT_CMP_5',
    'PROTOCOL_TIMER_OUT_CMP_6',
    'PROTOCOL_TIMER_OUT_CMP_7',
    'PROTOCOL_TIMER_FULL_VAL',
    'PROTOCOL_TIMER_SYNC',
    'SLEEP_TIMER_OUT_CMP_0',
    'SLEEP_TIMER_OUT_CMP_1',
    'SLEEP_TIMER_OUT_CMP_2',
    'SLEEP_TIMER_OUT_CMP_3',
    'SLEEP_TIMER_FULL_VAL',
    'RADIO_TX',
    'RADIO_RX',
    'SPI_SLAVE_TX',
    'SPI_SLAVE_RX',
    'UART_TX',
    'UART_RX',
    'GPIO',
    'UNIVERSAL_TIMER_2',
    'UNIVERSAL_TIMER_3',
    'SPI_MASTER',
    'I2C_MASTER',
    'RC_CALIB',
    'ADC',
    'PML_SVLD',
    'PML_CLOCK',
    'NVM',
    'QDEC',
    'USB',
    'CRYPTO_UNIT',
    'I2S',
    'SWI_0',
    'SWI_1',
    'SWI_2',
    'SWI_3',
    'SWI_4',
    'SWI_5',
    'SWI_6',
    'SWI_7',
    'SWI_8',
    'SWI_9',
]

export function em$configure() {
    $using(BoardC)
    $using(IntrVec)
    $using(LinkerC)
    $using(REGS)
    $using(StartupC)
    $using(TargC)
    IntrVec.IsrDefault.$$dlg = IsrDefault
    for (let name of INTRS) IntrVec.em$meta.addIntr(name)
}

export function em$generate() {
    LinkerC.genScript()
    let opt = $property('em.build.Optimize', 'Oz')
    let tools = $property('em.build.ToolsHome', '')
    let bld_out = $outfile('build.sh', 0o755)
    bld_out.addFile('../emm.9305/emm.distro.9305/build.sh')
    bld_out.close()
    let dbg_out = $outfile('debug.sh', 0o755)
    dbg_out.addFile('../emm.9305/emm.distro.9305/debug.sh')
    dbg_out.close()
    let lod_out = $outfile('load.sh', 0o755)
    lod_out.addFile('../emm.9305/emm.distro.9305/load.sh')
    lod_out.close()
}