/*
* Copyright (c) 2018-2026, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* *  Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* *  Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* *  Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
* OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
import '@$$emscript'
export const $U = $declare('MODULE')

import * as $R from '@ti.distro.cc27xx/REGS.em'

class Setting extends $struct {
    addr: u32
    value: u16
}

const settings = $table<Setting>()

export namespace em$meta {
    export function em$construct() {
        { // LRFDPBE.MDMCMDPAR0
            const setting = Setting.$make()
            setting.addr = 0x40081090
            setting.value = 0x8007
            settings.$$add(setting)
        }
        { // LRFDPBE.MDMCMDPAR1
            const setting = Setting.$make()
            setting.addr = 0x40081094
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDPBE.MDMCMDPAR2
            const setting = Setting.$make()
            setting.addr = 0x40081098
            setting.value = 0xaaaa
            settings.$$add(setting)
        }
        { // LRFDPBE.POLY0L
            const setting = Setting.$make()
            setting.addr = 0x400810a0
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDPBE.POLY0H
            const setting = Setting.$make()
            setting.addr = 0x400810a4
            setting.value = 0x2200
            settings.$$add(setting)
        }
        { // LRFDPBE.POLY1L
            const setting = Setting.$make()
            setting.addr = 0x400810a8
            setting.value = 0x5b00
            settings.$$add(setting)
        }
        { // LRFDPBE.POLY1H
            const setting = Setting.$make()
            setting.addr = 0x400810ac
            setting.value = 0x0006
            settings.$$add(setting)
        }
        { // LRFDPBE.PHACFG
            const setting = Setting.$make()
            setting.addr = 0x400810b0
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDPBE.FCFG0
            const setting = Setting.$make()
            setting.addr = 0x400810b4
            setting.value = 0x0021
            settings.$$add(setting)
        }
        { // LRFDPBE.FCFG1
            const setting = Setting.$make()
            setting.addr = 0x400810b8
            setting.value = 0x00c4
            settings.$$add(setting)
        }
        { // LRFDPBE.FCFG2
            const setting = Setting.$make()
            setting.addr = 0x400810bc
            setting.value = 0x0086
            settings.$$add(setting)
        }
        { // LRFDPBE.FCFG3
            const setting = Setting.$make()
            setting.addr = 0x400810c0
            setting.value = 0x0080
            settings.$$add(setting)
        }
        { // LRFDPBE.FCFG4
            const setting = Setting.$make()
            setting.addr = 0x400810c4
            setting.value = 0x0044
            settings.$$add(setting)
        }
        { // LRFDPBE.TXFWBTHRS
            const setting = Setting.$make()
            setting.addr = 0x400810d4
            setting.value = 0x0002
            settings.$$add(setting)
        }
        { // LRFDPBE.RXFRBTHRS
            const setting = Setting.$make()
            setting.addr = 0x400810d0
            setting.value = 0x0004
            settings.$$add(setting)
        }
        { // LRFDPBE.TIMCTL
            const setting = Setting.$make()
            setting.addr = 0x400810dc
            setting.value = 0x0202
            settings.$$add(setting)
        }
        { // LRFDPBE.TIMPRE
            const setting = Setting.$make()
            setting.addr = 0x400810e0
            setting.value = 0x0b0b
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.PHY
            const setting = Setting.$make()
            setting.addr = 0x40092020
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.SYNTHCALTIMEOUT
            const setting = Setting.$make()
            setting.addr = 0x40092022
            setting.value = 0x00b4
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.PKTCFG
            const setting = Setting.$make()
            setting.addr = 0x40092024
            setting.value = 0x0090
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.NUMCRCBITS
            const setting = Setting.$make()
            setting.addr = 0x40092026
            setting.value = 0x0018
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.FIFOCFG
            const setting = Setting.$make()
            setting.addr = 0x40092028
            setting.value = 0x03b0
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.EXTRABYTES
            const setting = Setting.$make()
            setting.addr = 0x4009202a
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.WHITEINIT
            const setting = Setting.$make()
            setting.addr = 0x4009202c
            setting.value = 0x0065
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.CRCINITL
            const setting = Setting.$make()
            setting.addr = 0x40092030
            setting.value = 0x5500
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.CRCINITH
            const setting = Setting.$make()
            setting.addr = 0x40092032
            setting.value = 0x5555
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.LENCFG
            const setting = Setting.$make()
            setting.addr = 0x40092034
            setting.value = 0x0108
            settings.$$add(setting)
        }
        { // PBE_GENERIC_RAM.LENOFFSET
            const setting = Setting.$make()
            setting.addr = 0x40092036
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.LNA
            const setting = Setting.$make()
            setting.addr = 0x400830b4
            setting.value = 0x0006
            settings.$$add(setting)
        }
        { // LRFDRFE.IFAMPRFLDO
            const setting = Setting.$make()
            setting.addr = 0x400830b8
            setting.value = 0x0006
            settings.$$add(setting)
        }
        { // LRFDRFE.PA0
            const setting = Setting.$make()
            setting.addr = 0x400830bc
            setting.value = 0x2970
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADC0
            const setting = Setting.$make()
            setting.addr = 0x400830c4
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADC1
            const setting = Setting.$make()
            setting.addr = 0x400830c8
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADCLF
            const setting = Setting.$make()
            setting.addr = 0x400830cc
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADCQUANT
            const setting = Setting.$make()
            setting.addr = 0x400830d0
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADCALDO
            const setting = Setting.$make()
            setting.addr = 0x400830d4
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.IFADCDLDO
            const setting = Setting.$make()
            setting.addr = 0x400830d8
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.ATSTREFH
            const setting = Setting.$make()
            setting.addr = 0x400830e4
            setting.value = 0x0200
            settings.$$add(setting)
        }
        { // LRFDRFE.DCO
            const setting = Setting.$make()
            setting.addr = 0x400830e8
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.DIV
            const setting = Setting.$make()
            setting.addr = 0x400830ec
            setting.value = 0x0008
            settings.$$add(setting)
        }
        { // LRFDRFE.DIVLDO
            const setting = Setting.$make()
            setting.addr = 0x400830f0
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.TDCLDO
            const setting = Setting.$make()
            setting.addr = 0x400830f4
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.DCOLDO0
            const setting = Setting.$make()
            setting.addr = 0x400830f8
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.DCOLDO1
            const setting = Setting.$make()
            setting.addr = 0x400830fc
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.PRE1
            const setting = Setting.$make()
            setting.addr = 0x40083104
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.PRE2
            const setting = Setting.$make()
            setting.addr = 0x40083108
            setting.value = 0x0605
            settings.$$add(setting)
        }
        { // LRFDRFE.PRE3
            const setting = Setting.$make()
            setting.addr = 0x4008310c
            setting.value = 0x0603
            settings.$$add(setting)
        }
        { // LRFDRFE.CAL0
            const setting = Setting.$make()
            setting.addr = 0x40083110
            setting.value = 0x4008
            settings.$$add(setting)
        }
        { // LRFDRFE.MISC0
            const setting = Setting.$make()
            setting.addr = 0x40083120
            setting.value = 0xd820
            settings.$$add(setting)
        }
        { // LRFDRFE.PHEDISC
            const setting = Setting.$make()
            setting.addr = 0x40083130
            setting.value = 0x0c07
            settings.$$add(setting)
        }
        { // LRFDRFE.PLLMON0
            const setting = Setting.$make()
            setting.addr = 0x40083138
            setting.value = 0xdf7f
            settings.$$add(setting)
        }
        { // LRFDRFE.PLLMON1
            const setting = Setting.$make()
            setting.addr = 0x4008313c
            setting.value = 0x047f
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.TDCCAL0
            const setting = Setting.$make()
            setting.addr = 0x40096806
            setting.value = 0x0300
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.TDCCAL1
            const setting = Setting.$make()
            setting.addr = 0x40096808
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.TDCCAL2
            const setting = Setting.$make()
            setting.addr = 0x4009680a
            setting.value = 0x0010
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DIVI
            const setting = Setting.$make()
            setting.addr = 0x40096828
            setting.value = 0x0008
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DIVF
            const setting = Setting.$make()
            setting.addr = 0x4009682a
            setting.value = 0x4808
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DIVLDOI
            const setting = Setting.$make()
            setting.addr = 0x4009682c
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DIVLDOF
            const setting = Setting.$make()
            setting.addr = 0x4009682e
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DIVLDOIOFF
            const setting = Setting.$make()
            setting.addr = 0x40096830
            setting.value = 0x0014
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.LDOSETTLE
            const setting = Setting.$make()
            setting.addr = 0x40096832
            setting.value = 0x0047
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.CHRGSETTLE
            const setting = Setting.$make()
            setting.addr = 0x40096834
            setting.value = 0x002e
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.DCOSETTLE
            const setting = Setting.$make()
            setting.addr = 0x40096836
            setting.value = 0x0005
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.IFAMPRFLDODEFAULT
            const setting = Setting.$make()
            setting.addr = 0x4009683a
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.IFAMPRFLDOTX
            const setting = Setting.$make()
            setting.addr = 0x40096838
            setting.value = 0xfe00
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.PATRIM01
            const setting = Setting.$make()
            setting.addr = 0x4009684e
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.PATRIM23
            const setting = Setting.$make()
            setting.addr = 0x40096850
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.RTRIMMIN
            const setting = Setting.$make()
            setting.addr = 0x40096822
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.RTRIMOFF
            const setting = Setting.$make()
            setting.addr = 0x40096820
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.SYNTHCTL
            const setting = Setting.$make()
            setting.addr = 0x40096804
            setting.value = 0x0012
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.TDCPLL
            const setting = Setting.$make()
            setting.addr = 0x4009680c
            setting.value = 0x0400
            settings.$$add(setting)
        }
        { // LRFDRFE.CAL1
            const setting = Setting.$make()
            setting.addr = 0x40083114
            setting.value = 0x7f00
            settings.$$add(setting)
        }
        { // LRFDRFE.PRE0
            const setting = Setting.$make()
            setting.addr = 0x40083100
            setting.value = 0x0706
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K1MSB
            const setting = Setting.$make()
            setting.addr = 0x40096810
            setting.value = 0x010a
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K1LSB
            const setting = Setting.$make()
            setting.addr = 0x4009680e
            setting.value = 0x569b
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K2BL
            const setting = Setting.$make()
            setting.addr = 0x40096812
            setting.value = 0x012d
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K2AL
            const setting = Setting.$make()
            setting.addr = 0x40096814
            setting.value = 0x0034
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K3BL
            const setting = Setting.$make()
            setting.addr = 0x40096816
            setting.value = 0x132c
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K3AL
            const setting = Setting.$make()
            setting.addr = 0x40096818
            setting.value = 0x07ab
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.K5
            const setting = Setting.$make()
            setting.addr = 0x4009681a
            setting.value = 0x916f
            settings.$$add(setting)
        }
        { // LRFDPBE.TIMPER1
            const setting = Setting.$make()
            setting.addr = 0x400810e8
            setting.value = 0x03e8
            settings.$$add(setting)
        }
        { // LRFDMDM.ADCDIGCONF
            const setting = Setting.$make()
            setting.addr = 0x400820c0
            setting.value = 0x0003
            settings.$$add(setting)
        }
        { // LRFDMDM.MODPRECTRL
            const setting = Setting.$make()
            setting.addr = 0x400820c4
            setting.value = 0x0007
            settings.$$add(setting)
        }
        { // LRFDMDM.MODSYMMAP0
            const setting = Setting.$make()
            setting.addr = 0x400820c8
            setting.value = 0x001f
            settings.$$add(setting)
        }
        { // LRFDMDM.BAUD
            const setting = Setting.$make()
            setting.addr = 0x400820d4
            setting.value = 0x4000
            settings.$$add(setting)
        }
        { // LRFDMDM.BAUDPRE
            const setting = Setting.$make()
            setting.addr = 0x400820d8
            setting.value = 0x000c
            settings.$$add(setting)
        }
        { // LRFDMDM.MODMAIN
            const setting = Setting.$make()
            setting.addr = 0x400820dc
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMISC3
            const setting = Setting.$make()
            setting.addr = 0x400820ec
            setting.value = 0x1182
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMISC0
            const setting = Setting.$make()
            setting.addr = 0x400820e0
            setting.value = 0x0387
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMIQMC0
            const setting = Setting.$make()
            setting.addr = 0x400820f0
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMISC1
            const setting = Setting.$make()
            setting.addr = 0x400820e4
            setting.value = 0x0001
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMISC2
            const setting = Setting.$make()
            setting.addr = 0x400820e8
            setting.value = 0x00fb
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMDSBU2
            const setting = Setting.$make()
            setting.addr = 0x400820f8
            setting.value = 0x0080
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMDSBU
            const setting = Setting.$make()
            setting.addr = 0x400820f4
            setting.value = 0x0087
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMCODC0
            const setting = Setting.$make()
            setting.addr = 0x400820fc
            setting.value = 0x0f50
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMFIDC0
            const setting = Setting.$make()
            setting.addr = 0x40082100
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMFEXB0
            const setting = Setting.$make()
            setting.addr = 0x40082104
            setting.value = 0x0224
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMDSXB0
            const setting = Setting.$make()
            setting.addr = 0x400821a8
            setting.value = 0x0004
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMD2XB0
            const setting = Setting.$make()
            setting.addr = 0x400821ac
            setting.value = 0x0054
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMFIFE0
            const setting = Setting.$make()
            setting.addr = 0x40082108
            setting.value = 0x0005
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMAFI0
            const setting = Setting.$make()
            setting.addr = 0x4008210c
            setting.value = 0x0400
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMAFI1
            const setting = Setting.$make()
            setting.addr = 0x40082110
            setting.value = 0x7b20
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMMAFI2
            const setting = Setting.$make()
            setting.addr = 0x40082114
            setting.value = 0x00c1
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMC1BE0
            const setting = Setting.$make()
            setting.addr = 0x40082118
            setting.value = 0x000f
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMC1BE1
            const setting = Setting.$make()
            setting.addr = 0x4008211c
            setting.value = 0x7f27
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMC1BE2
            const setting = Setting.$make()
            setting.addr = 0x40082120
            setting.value = 0x017f
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMC1BE12
            const setting = Setting.$make()
            setting.addr = 0x4008232c
            setting.value = 0x7f00
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMSWQU0
            const setting = Setting.$make()
            setting.addr = 0x40082134
            setting.value = 0x005f
            settings.$$add(setting)
        }
        { // LRFDMDM.SPARE0
            const setting = Setting.$make()
            setting.addr = 0x40082124
            setting.value = 0x2318
            settings.$$add(setting)
        }
        { // LRFDMDM.SYSTIMEVTMUX0
            const setting = Setting.$make()
            setting.addr = 0x400820b8
            setting.value = 0x0015
            settings.$$add(setting)
        }
        { // LRFDMDM.BAUDCOMP
            const setting = Setting.$make()
            setting.addr = 0x400822a0
            setting.value = 0x0003
            settings.$$add(setting)
        }
        { // LRFDMDM.MODCTRL
            const setting = Setting.$make()
            setting.addr = 0x40082148
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDMDM.DEMDEBUG
            const setting = Setting.$make()
            setting.addr = 0x40082184
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDMDM.GPOCTRL0
            const setting = Setting.$make()
            setting.addr = 0x40082248
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.SPARE2
            const setting = Setting.$make()
            setting.addr = 0x400830a4
            setting.value = 0xa246
            settings.$$add(setting)
        }
        { // LRFDRFE.SPARE3
            const setting = Setting.$make()
            setting.addr = 0x400830a8
            setting.value = 0x1f40
            settings.$$add(setting)
        }
        { // LRFDRFE.SPARE4
            const setting = Setting.$make()
            setting.addr = 0x400830ac
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.RSSIOFFSET
            const setting = Setting.$make()
            setting.addr = 0x4008308c
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // LRFDRFE.MOD0
            const setting = Setting.$make()
            setting.addr = 0x40083140
            setting.value = 0x1804
            settings.$$add(setting)
        }
        { // LRFDRFE.MAGNTHRCFG
            const setting = Setting.$make()
            setting.addr = 0x40083084
            setting.value = 0x0000
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.PHYRSSIOFFSET
            const setting = Setting.$make()
            setting.addr = 0x40096844
            setting.value = 0x0051
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.SPARE0SHADOW
            const setting = Setting.$make()
            setting.addr = 0x40096846
            setting.value = 0x75f8
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.SPARE1SHADOW
            const setting = Setting.$make()
            setting.addr = 0x40096848
            setting.value = 0x0045
            settings.$$add(setting)
        }
        { // RFE_COMMON_RAM.AGCINFO
            const setting = Setting.$make()
            setting.addr = 0x4009684a
            setting.value = 0x0000
            settings.$$add(setting)
        }
    }
}

export function setup(): void {
    for (const setting of settings) {
        $reg16[setting.addr] = setting.value
    }
}
