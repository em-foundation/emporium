////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_pml.h
///
/// @project    T9305
///
/// @brief      Power Management Logic register and bit field definitions
///
/// @classification  Public
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (C) 2015 EM Microelectronic
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

// WARNING: This file is auto-generated, DO NOT MODIFY!

#ifndef _T9305_PML_H
#define _T9305_PML_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup PML_Registers PML Register Map - registers
 * @{
 ******************************************************************************/


/** PML flags */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PmlFlg;                                    /**< Reset flags */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegPmlFlg_t;


/** PML device mode control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlClkCtrl;                                /**< Clock control */
        uint8_t  PmlWakeCtrl;                               /**< Wake control */
        uint8_t  PmlPwrCtrl;                                /**< Power (regulators) control */
        uint8_t  PmlModeCtrl;                               /**< Mode transition contron */
    } regs;
} RegPmlCtrl_t;


/** PML domain control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlDRAMRetOn;                              /**< DRAM retention enable */
        uint8_t  PmlDomainCtrl;                             /**< Power domain control */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegPmlDomain_t;


/** PML levels defintion */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlVcc;                                    /**< VCC level configuration */
        uint8_t  PmlVbat;                                   /**< VBAT level configuration */
        uint8_t  PmlLdoVcc;                                 /**< LDO VCC level configuration */
        uint8_t  PmlLdoDig;                                 /**< LDO DIG level configuration */
    } regs;
} RegPmlLvl_t;


/** PML pad wake-up configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PmlPadWakeEn;                              /**< Pad wake-up enable */
        uint16_t PmlPadWakePol;                             /**< Pad wake-up polarity */
    } regs;
} RegPmlPadWake_t;


/** PML DCDC T1/T2 timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlDCDCT1;                                 /**< DCDC end of T1 for RX */
        uint8_t  PmlDCDCT2;                                 /**< DCDC end of T2 for RX */
        uint8_t  PmlDCDCT1TX;                               /**< DCDC end of T1 for TX */
        uint8_t  PmlDCDCT2TX;                               /**< DCDC end of T2 for TX */
    } regs;
} RegPmlDCDCTim_t;


/** PML DCDC periods */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlDCDCPer;                                /**< DCDC cycle period */
        uint8_t  PmlADCPer;                                 /**< ADC cycle period */
        uint16_t PmlBypassTim;                              /**< Bypass timer value */
    } regs;
} RegPmlDCDCPer_t;


/** PML DCDC control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlDcdcCtrl;                               /**< DCDC control */
        uint8_t  PmlScDbCtrl;                               /**< DCDC control */
        uint8_t  PmlScDbPwm;                                /**< Switched cap Doubler PWM value */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegPmlDCDCCtrl_t;


/** System lock bits */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlLockBits_t;


/** SW reset */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlSWRst_t;


/** PML Trimming */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlTrim_t;


/** PML Mask and Device Revision */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlRev_t;


/** GPIO output of System Mode enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlSysMode_t;


/** Selection of clock on GPIO */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlPadClk_t;


/** GPIO debouncer configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t GPIODebEn;                                 /**< Debouncer enable (bit mask). 0: do not debounce input, 1: debounce input */
        uint16_t GPIODebClock;                              /**< Debouncer clock selector */
    } regs;
} RegGPIOCfgDeb_t;


/** Test enable unclock */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstEn_t;


/** Scan enable unclock */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstScanEn_t;


/** GPIO pad Test mode */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstPadMode_t;


/** GPIO pad Test mode */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstPadLoop_t;


/** Test control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstCtrl_t;


/** Test control of analog blocks */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstAna_t;


/** Test control of analog test bus */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstBus_t;


/** Sleep Timer control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  STRunEn;                                   /**< Sleep Timer run enable: : '0' - timer stopped, '1' - timer enabled to run */
        uint8_t  STCtrl;                                    /**< Sleep Timer clear/load control */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegSleepTimCtrl_t;


/** Sleep Timer counter value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCount_t;


/** Sleep Timer counter value - high part (extension to 48 bits) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCountHigh_t;


/** Sleep Timer output compare configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  STCompareEn;                               /**< Sleep Timer output compare enable */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  STWakeUpEn;                                /**< Sleep Timer wake-up enable */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegSleepTimCompareCfg_t;


/** Sleep Timer output compare value - channel 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCompare0_t;


/** Sleep Timer output compare value - channel 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCompare1_t;


/** Sleep Timer output compare value - channel 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCompare2_t;


/** Sleep Timer output compare value - channel 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCompare3_t;


/** Sleep Timer input capture control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  STCaptureSW;                               /**< Sleep Timer input capture SW */
        uint8_t  STGPIOEvtCfg;                              /**< Sleep Timer GPIO HW event configuration */
        uint8_t  STCaptureHW;                               /**< Sleep Timer input capture enable by HW event */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegSleepTimCaptureCtrl_t;


/** Sleep Timer input capture HW event selection */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  STCapture0HWEvtSel;                        /**< Sleep Timer input capture HW event selection - channel 0 */
        uint8_t  STCapture1HWEvtSel;                        /**< Sleep Timer input capture HW event selection - channel 1 */
        uint8_t  STCapture2HWEvtSel;                        /**< Sleep Timer input capture HW event selection - channel 2 */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegSleepTimCaptureHWEvtSel_t;


/** Sleep Timer input capture value - channel 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCapture0_t;


/** Sleep Timer input capture value - channel 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCapture1_t;


/** Sleep Timer input capture value - channel 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCapture2_t;


/** Sleep Timer input capture value - channel 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSleepTimCapture3_t;


/** Lock bits for erase/write page operation - pages 0-31 of main area */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint32_t NvmLockMainPage0;                          /**< Lock bits for page erase/write operation - pages 0-31 of main area */
    } regs;
} RegNvmLockMain0_t;


/** Lock bits for erase/write page operation - pages 32-63 of main area */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint32_t NvmLockMainPage1;                          /**< Lock bits for page erase/write operation - pages 32-63 of main area */
    } regs;
} RegNvmLockMain1_t;


/** Lock bits for erase/write page operation - pages 0-3 of info area */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t NvmLockInfoPage;                           /**< Lock bits for erase/write page operation - pages 0-3 of info area */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegNvmLockInfo_t;


/** NVM master lock bits */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmLockMaster_t;


/** Lock bits for keys in key container - keys 0-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  NvmKcLockKey;                              /**< Lock bits for keys in key container - keys 0-7 */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
        uint8_t  RESERVED2;                                 /**< RESERVED */
    } regs;
} RegNvmKcLockKey_t;


/** NVM redundancy page mapping configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t NvmRedunPage0;                             /**< NVM redundancy page 0 configuration */
        uint16_t NvmRedunPage1;                             /**< NVM redundancy page 1 configuration */
    } regs;
} RegNvmRedunCfg_t;


/** Test mode enable signal for LF RC test */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegTstLFRC_t;


/** Enable of LF RC Frequency chopper */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlLFRC_t;

/** @} end of group PML_Regs */



/***************************************************************************//**
 * @defgroup PML_RegMap PML Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegPmlFlg_t                                       RegPmlFlg;                    /**< PML flags */
    __IO  RegPmlCtrl_t                                      RegPmlCtrl;                   /**< PML device mode control */
    __IO  RegPmlDomain_t                                    RegPmlDomain;                 /**< PML domain control */
    __IO  RegPmlLvl_t                                       RegPmlLvl;                    /**< PML levels defintion */
    __IO  RegPmlPadWake_t                                   RegPmlPadWake;                /**< PML pad wake-up configuration */
    __IO  RegPmlDCDCTim_t                                   RegPmlDCDCTim;                /**< PML DCDC T1/T2 timing */
    __IO  RegPmlDCDCPer_t                                   RegPmlDCDCPer;                /**< PML DCDC periods */
    __IO  RegPmlDCDCCtrl_t                                  RegPmlDCDCCtrl;               /**< PML DCDC control */
    __IO  RegPmlLockBits_t                                  RegPmlLockBits;               /**< System lock bits */
    __IO  RegPmlSWRst_t                                     RegPmlSWRst;                  /**< SW reset */
    __IO  RegPmlTrim_t                                      RegPmlTrim;                   /**< PML Trimming */
    __I   RegPmlRev_t                                       RegPmlRev;                    /**< PML Mask and Device Revision */
    __IO  RegPmlSysMode_t                                   RegPmlSysMode;                /**< GPIO output of System Mode enable */
    __IO  RegPmlPadClk_t                                    RegPmlPadClk;                 /**< Selection of clock on GPIO */
    __IO  RegGPIOCfgDeb_t                                   RegGPIOCfgDeb;                /**< GPIO debouncer configuration */
    __IO  RegTstEn_t                                        RegTstEn;                     /**< Test enable unclock */
    __O   RegTstScanEn_t                                    RegTstScanEn;                 /**< Scan enable unclock */
    __IO  RegTstPadMode_t                                   RegTstPadMode;                /**< GPIO pad Test mode */
    __IO  RegTstPadLoop_t                                   RegTstPadLoop;                /**< GPIO pad Test mode */
    __IO  RegTstCtrl_t                                      RegTstCtrl;                   /**< Test control */
    __IO  RegTstAna_t                                       RegTstAna;                    /**< Test control of analog blocks */
    __IO  RegTstBus_t                                       RegTstBus;                    /**< Test control of analog test bus */
    __IO  RegSleepTimCtrl_t                                 RegSleepTimCtrl;              /**< Sleep Timer control */
    __I   RegSleepTimCount_t                                RegSleepTimCount;             /**< Sleep Timer counter value */
    __I   RegSleepTimCountHigh_t                            RegSleepTimCountHigh;         /**< Sleep Timer counter value - high part (extension to 48 bits) */
    __IO  RegSleepTimCompareCfg_t                           RegSleepTimCompareCfg;        /**< Sleep Timer output compare configuration */
    __IO  RegSleepTimCompare0_t                             RegSleepTimCompare0;          /**< Sleep Timer output compare value - channel 0 */
    __IO  RegSleepTimCompare1_t                             RegSleepTimCompare1;          /**< Sleep Timer output compare value - channel 1 */
    __IO  RegSleepTimCompare2_t                             RegSleepTimCompare2;          /**< Sleep Timer output compare value - channel 2 */
    __IO  RegSleepTimCompare3_t                             RegSleepTimCompare3;          /**< Sleep Timer output compare value - channel 3 */
    __IO  RegSleepTimCaptureCtrl_t                          RegSleepTimCaptureCtrl;       /**< Sleep Timer input capture control */
    __IO  RegSleepTimCaptureHWEvtSel_t                      RegSleepTimCaptureHWEvtSel;   /**< Sleep Timer input capture HW event selection */
    __I   RegSleepTimCapture0_t                             RegSleepTimCapture0;          /**< Sleep Timer input capture value - channel 0 */
    __I   RegSleepTimCapture1_t                             RegSleepTimCapture1;          /**< Sleep Timer input capture value - channel 1 */
    __I   RegSleepTimCapture2_t                             RegSleepTimCapture2;          /**< Sleep Timer input capture value - channel 2 */
    __I   RegSleepTimCapture3_t                             RegSleepTimCapture3;          /**< Sleep Timer input capture value - channel 3 */
    __IO  RegNvmLockMain0_t                                 RegNvmLockMain0;              /**< Lock bits for erase/write page operation - pages 0-31 of main area */
    __IO  RegNvmLockMain1_t                                 RegNvmLockMain1;              /**< Lock bits for erase/write page operation - pages 32-63 of main area */
    __IO  RegNvmLockInfo_t                                  RegNvmLockInfo;               /**< Lock bits for erase/write page operation - pages 0-3 of info area */
    __IO  RegNvmLockMaster_t                                RegNvmLockMaster;             /**< NVM master lock bits */
    __IO  RegNvmKcLockKey_t                                 RegNvmKcLockKey;              /**< Lock bits for keys in key container - keys 0-7 */
    __IO  RegNvmRedunCfg_t                                  RegNvmRedunCfg;               /**< NVM redundancy page mapping configuration */
    __IO  RegTstLFRC_t                                      RegTstLFRC;                   /**< Test mode enable signal for LF RC test */
    __IO  RegPmlLFRC_t                                      RegPmlLFRC;                   /**< Enable of LF RC Frequency chopper */
} PML_RegMap_t;

/** @} end of group PML_RegMap */



/***************************************************************************//**
 * @defgroup PML_BitFields PML bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegPmlFlg
 * @{
 */
// RegPmlFlg.r32
#define  REG_PML_FLG_RESET_VALUE                            0x00000000u                   /**< Reset value of RegPmlFlg */
#define  REG_PML_FLG_MASK                                   0x0000031Fu                   /**< Mask for RegPmlFlg */

#define  PML_POR_FLG_SHIFT                                  0                             /**< Shift for PmlPORFlg */
#define  PML_POR_FLG_MASK                                   0x00000001u                   /**< Mask for PmlPORFlg */
#define  PML_POR_FLG_BMASK                                  0x1u                          /**< Base mask for PmlPORFlg */
#define  PML_POR_FLG(x)                                     (((x)&0x1u)<<0)               /**< Set PmlPORFlg in register */
#define  GET_PML_POR_FLG(reg)                               (((reg)>>0)&0x1u)             /**< Get PmlPORFlg from register */
#define  PML_PWR_CHK_FLG_SHIFT                              1                             /**< Shift for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG_MASK                               0x00000002u                   /**< Mask for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG_BMASK                              0x1u                          /**< Base mask for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG(x)                                 (((x)&0x1u)<<1)               /**< Set PmlPwrChkFlg in register */
#define  GET_PML_PWR_CHK_FLG(reg)                           (((reg)>>1)&0x1u)             /**< Get PmlPwrChkFlg from register */
#define  PML_SW_RST_FLG_SHIFT                               2                             /**< Shift for PmlSWRstFlg */
#define  PML_SW_RST_FLG_MASK                                0x00000004u                   /**< Mask for PmlSWRstFlg */
#define  PML_SW_RST_FLG_BMASK                               0x1u                          /**< Base mask for PmlSWRstFlg */
#define  PML_SW_RST_FLG(x)                                  (((x)&0x1u)<<2)               /**< Set PmlSWRstFlg in register */
#define  GET_PML_SW_RST_FLG(reg)                            (((reg)>>2)&0x1u)             /**< Get PmlSWRstFlg from register */
#define  PML_WD_FLG_SHIFT                                   3                             /**< Shift for PmlWDFlg */
#define  PML_WD_FLG_MASK                                    0x00000008u                   /**< Mask for PmlWDFlg */
#define  PML_WD_FLG_BMASK                                   0x1u                          /**< Base mask for PmlWDFlg */
#define  PML_WD_FLG(x)                                      (((x)&0x1u)<<3)               /**< Set PmlWDFlg in register */
#define  GET_PML_WD_FLG(reg)                                (((reg)>>3)&0x1u)             /**< Get PmlWDFlg from register */
#define  PML_NVM_BO_FLG_SHIFT                               4                             /**< Shift for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG_MASK                                0x00000010u                   /**< Mask for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG_BMASK                               0x1u                          /**< Base mask for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG(x)                                  (((x)&0x1u)<<4)               /**< Set PmlNvmBoFlg in register */
#define  GET_PML_NVM_BO_FLG(reg)                            (((reg)>>4)&0x1u)             /**< Get PmlNvmBoFlg from register */
#define  PML_SLEEP_FLG_SHIFT                                8                             /**< Shift for PmlSleepFlg */
#define  PML_SLEEP_FLG_MASK                                 0x00000100u                   /**< Mask for PmlSleepFlg */
#define  PML_SLEEP_FLG_BMASK                                0x1u                          /**< Base mask for PmlSleepFlg */
#define  PML_SLEEP_FLG(x)                                   (((x)&0x1u)<<8)               /**< Set PmlSleepFlg in register */
#define  GET_PML_SLEEP_FLG(reg)                             (((reg)>>8)&0x1u)             /**< Get PmlSleepFlg from register */
#define  PML_DEEP_SLEEP_FLG_SHIFT                           9                             /**< Shift for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG_MASK                            0x00000200u                   /**< Mask for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG_BMASK                           0x1u                          /**< Base mask for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG(x)                              (((x)&0x1u)<<9)               /**< Set PmlDeepSleepFlg in register */
#define  GET_PML_DEEP_SLEEP_FLG(reg)                        (((reg)>>9)&0x1u)             /**< Get PmlDeepSleepFlg from register */

// RegPmlFlg.regs.PmlFlg
#define  PML_FLG_GSHIFT                                     0                             /**< Shift for group PmlFlg */
#define  PML_FLG_GSIZE                                      16                            /**< Size of group PmlFlg */
#define  PML_FLG_GMASK                                      0x0000FFFFu                   /**< Mask for group PmlFlg */

#define  PML_POR_FLG_RSHIFT                                 0                             /**< Shift for PmlPORFlg */
#define  PML_POR_FLG_RMASK                                  0x0001u                       /**< Mask for PmlPORFlg */
#define  PML_POR_FLG_RBMASK                                 0x1u                          /**< Base mask for PmlPORFlg */
#define  PML_POR_FLG_R(x)                                   (((x)&0x1u)<<0)               /**< Set PmlPORFlg in register */
#define  GET_PML_POR_FLG_R(reg)                             (((reg)>>0)&0x1u)             /**< Get PmlPORFlg from register */
#define  PML_PWR_CHK_FLG_RSHIFT                             1                             /**< Shift for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG_RMASK                              0x0002u                       /**< Mask for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG_RBMASK                             0x1u                          /**< Base mask for PmlPwrChkFlg */
#define  PML_PWR_CHK_FLG_R(x)                               (((x)&0x1u)<<1)               /**< Set PmlPwrChkFlg in register */
#define  GET_PML_PWR_CHK_FLG_R(reg)                         (((reg)>>1)&0x1u)             /**< Get PmlPwrChkFlg from register */
#define  PML_SW_RST_FLG_RSHIFT                              2                             /**< Shift for PmlSWRstFlg */
#define  PML_SW_RST_FLG_RMASK                               0x0004u                       /**< Mask for PmlSWRstFlg */
#define  PML_SW_RST_FLG_RBMASK                              0x1u                          /**< Base mask for PmlSWRstFlg */
#define  PML_SW_RST_FLG_R(x)                                (((x)&0x1u)<<2)               /**< Set PmlSWRstFlg in register */
#define  GET_PML_SW_RST_FLG_R(reg)                          (((reg)>>2)&0x1u)             /**< Get PmlSWRstFlg from register */
#define  PML_WD_FLG_RSHIFT                                  3                             /**< Shift for PmlWDFlg */
#define  PML_WD_FLG_RMASK                                   0x0008u                       /**< Mask for PmlWDFlg */
#define  PML_WD_FLG_RBMASK                                  0x1u                          /**< Base mask for PmlWDFlg */
#define  PML_WD_FLG_R(x)                                    (((x)&0x1u)<<3)               /**< Set PmlWDFlg in register */
#define  GET_PML_WD_FLG_R(reg)                              (((reg)>>3)&0x1u)             /**< Get PmlWDFlg from register */
#define  PML_NVM_BO_FLG_RSHIFT                              4                             /**< Shift for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG_RMASK                               0x0010u                       /**< Mask for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG_RBMASK                              0x1u                          /**< Base mask for PmlNvmBoFlg */
#define  PML_NVM_BO_FLG_R(x)                                (((x)&0x1u)<<4)               /**< Set PmlNvmBoFlg in register */
#define  GET_PML_NVM_BO_FLG_R(reg)                          (((reg)>>4)&0x1u)             /**< Get PmlNvmBoFlg from register */
#define  PML_SLEEP_FLG_RSHIFT                               8                             /**< Shift for PmlSleepFlg */
#define  PML_SLEEP_FLG_RMASK                                0x0100u                       /**< Mask for PmlSleepFlg */
#define  PML_SLEEP_FLG_RBMASK                               0x1u                          /**< Base mask for PmlSleepFlg */
#define  PML_SLEEP_FLG_R(x)                                 (((x)&0x1u)<<8)               /**< Set PmlSleepFlg in register */
#define  GET_PML_SLEEP_FLG_R(reg)                           (((reg)>>8)&0x1u)             /**< Get PmlSleepFlg from register */
#define  PML_DEEP_SLEEP_FLG_RSHIFT                          9                             /**< Shift for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG_RMASK                           0x0200u                       /**< Mask for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG_RBMASK                          0x1u                          /**< Base mask for PmlDeepSleepFlg */
#define  PML_DEEP_SLEEP_FLG_R(x)                            (((x)&0x1u)<<9)               /**< Set PmlDeepSleepFlg in register */
#define  GET_PML_DEEP_SLEEP_FLG_R(reg)                      (((reg)>>9)&0x1u)             /**< Get PmlDeepSleepFlg from register */
/** @} */


/**
 * @name RegPmlCtrl
 * @{
 */
// RegPmlCtrl.r32
#define  REG_PML_CTRL_RESET_VALUE                           0x00210000u                   /**< Reset value of RegPmlCtrl */
#define  REG_PML_CTRL_MASK                                  0x077F031Fu                   /**< Mask for RegPmlCtrl */

#define  PML_LF_XTAL_EN_SHIFT                               0                             /**< Shift for PmlLFXtalEn */
#define  PML_LF_XTAL_EN_MASK                                0x00000003u                   /**< Mask for PmlLFXtalEn */
#define  PML_LF_XTAL_EN_BMASK                               0x3u                          /**< Base mask for PmlLFXtalEn */
#define  PML_LF_XTAL_EN(x)                                  (((x)&0x3u)<<0)               /**< Set PmlLFXtalEn in register */
#define  GET_PML_LF_XTAL_EN(reg)                            (((reg)>>0)&0x3u)             /**< Get PmlLFXtalEn from register */
#define  PML_LF_RC_LP_EN_SHIFT                              2                             /**< Shift for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN_MASK                               0x00000004u                   /**< Mask for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN_BMASK                              0x1u                          /**< Base mask for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN(x)                                 (((x)&0x1u)<<2)               /**< Set PmlLFRCLPEn in register */
#define  GET_PML_LF_RC_LP_EN(reg)                           (((reg)>>2)&0x1u)             /**< Get PmlLFRCLPEn from register */
#define  PML_SLP_TIM_ON_XTAL_SHIFT                          3                             /**< Shift for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL_MASK                           0x00000008u                   /**< Mask for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL_BMASK                          0x1u                          /**< Base mask for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL(x)                             (((x)&0x1u)<<3)               /**< Set PmlSlpTimOnXTAL in register */
#define  GET_PML_SLP_TIM_ON_XTAL(reg)                       (((reg)>>3)&0x1u)             /**< Get PmlSlpTimOnXTAL from register */
#define  PML_SLP_TIM_ON_LP_SHIFT                            4                             /**< Shift for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP_MASK                             0x00000010u                   /**< Mask for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP_BMASK                            0x1u                          /**< Base mask for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP(x)                               (((x)&0x1u)<<4)               /**< Set PmlSlpTimOnLP in register */
#define  GET_PML_SLP_TIM_ON_LP(reg)                         (((reg)>>4)&0x1u)             /**< Get PmlSlpTimOnLP from register */
#define  PML_WAKE_FLG_EN_SHIFT                              8                             /**< Shift for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN_MASK                               0x00000100u                   /**< Mask for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN_BMASK                              0x1u                          /**< Base mask for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN(x)                                 (((x)&0x1u)<<8)               /**< Set PmlWakeFlgEn in register */
#define  GET_PML_WAKE_FLG_EN(reg)                           (((reg)>>8)&0x1u)             /**< Get PmlWakeFlgEn from register */
#define  PML_LATCH_PAD_EN_SHIFT                             9                             /**< Shift for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN_MASK                              0x00000200u                   /**< Mask for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN_BMASK                             0x1u                          /**< Base mask for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN(x)                                (((x)&0x1u)<<9)               /**< Set PmlLatchPadEn in register */
#define  GET_PML_LATCH_PAD_EN(reg)                          (((reg)>>9)&0x1u)             /**< Get PmlLatchPadEn from register */
#define  PML_SLEEP_BYPASS_EN_SHIFT                          16                            /**< Shift for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN_MASK                           0x00010000u                   /**< Mask for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN_BMASK                          0x1u                          /**< Base mask for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN(x)                             (((x)&0x1u)<<16)              /**< Set PmlSleepBypassEn in register */
#define  GET_PML_SLEEP_BYPASS_EN(reg)                       (((reg)>>16)&0x1u)            /**< Get PmlSleepBypassEn from register */
#define  PML_LDO_VCC_EN_SHIFT                               17                            /**< Shift for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN_MASK                                0x00020000u                   /**< Mask for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN_BMASK                               0x1u                          /**< Base mask for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN(x)                                  (((x)&0x1u)<<17)              /**< Set PmlLDOVCCEn in register */
#define  GET_PML_LDO_VCC_EN(reg)                            (((reg)>>17)&0x1u)            /**< Get PmlLDOVCCEn from register */
#define  PML_VBAT_MON_EN_SHIFT                              18                            /**< Shift for PmlVBATMonEn */
#define  PML_VBAT_MON_EN_MASK                               0x00040000u                   /**< Mask for PmlVBATMonEn */
#define  PML_VBAT_MON_EN_BMASK                              0x1u                          /**< Base mask for PmlVBATMonEn */
#define  PML_VBAT_MON_EN(x)                                 (((x)&0x1u)<<18)              /**< Set PmlVBATMonEn in register */
#define  GET_PML_VBAT_MON_EN(reg)                           (((reg)>>18)&0x1u)            /**< Get PmlVBATMonEn from register */
#define  PML_NVM_BO_RST_EN_SHIFT                            19                            /**< Shift for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN_MASK                             0x00080000u                   /**< Mask for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN_BMASK                            0x1u                          /**< Base mask for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN(x)                               (((x)&0x1u)<<19)              /**< Set PmlNvmBoRstEn in register */
#define  GET_PML_NVM_BO_RST_EN(reg)                         (((reg)>>19)&0x1u)            /**< Get PmlNvmBoRstEn from register */
#define  PML_NVM_SW_EN_SHIFT                                20                            /**< Shift for PmlNvmSwEn */
#define  PML_NVM_SW_EN_MASK                                 0x00100000u                   /**< Mask for PmlNvmSwEn */
#define  PML_NVM_SW_EN_BMASK                                0x1u                          /**< Base mask for PmlNvmSwEn */
#define  PML_NVM_SW_EN(x)                                   (((x)&0x1u)<<20)              /**< Set PmlNvmSwEn in register */
#define  GET_PML_NVM_SW_EN(reg)                             (((reg)>>20)&0x1u)            /**< Get PmlNvmSwEn from register */
#define  PML_RF_SW_EN_SHIFT                                 21                            /**< Shift for PmlRfSwEn */
#define  PML_RF_SW_EN_MASK                                  0x00200000u                   /**< Mask for PmlRfSwEn */
#define  PML_RF_SW_EN_BMASK                                 0x1u                          /**< Base mask for PmlRfSwEn */
#define  PML_RF_SW_EN(x)                                    (((x)&0x1u)<<21)              /**< Set PmlRfSwEn in register */
#define  GET_PML_RF_SW_EN(reg)                              (((reg)>>21)&0x1u)            /**< Get PmlRfSwEn from register */
#define  PML_LDO_VCC_TX_EN_SHIFT                            22                            /**< Shift for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN_MASK                             0x00400000u                   /**< Mask for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN_BMASK                            0x1u                          /**< Base mask for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN(x)                               (((x)&0x1u)<<22)              /**< Set PmlLDOVCCTXEn in register */
#define  GET_PML_LDO_VCC_TX_EN(reg)                         (((reg)>>22)&0x1u)            /**< Get PmlLDOVCCTXEn from register */
#define  PML_GO_XTAL_SHIFT                                  24                            /**< Shift for PmlGoXtal */
#define  PML_GO_XTAL_MASK                                   0x01000000u                   /**< Mask for PmlGoXtal */
#define  PML_GO_XTAL_BMASK                                  0x1u                          /**< Base mask for PmlGoXtal */
#define  PML_GO_XTAL(x)                                     (((x)&0x1u)<<24)              /**< Set PmlGoXtal in register */
#define  GET_PML_GO_XTAL(reg)                               (((reg)>>24)&0x1u)            /**< Get PmlGoXtal from register */
#define  PML_GO_RC_SHIFT                                    25                            /**< Shift for PmlGoRC */
#define  PML_GO_RC_MASK                                     0x02000000u                   /**< Mask for PmlGoRC */
#define  PML_GO_RC_BMASK                                    0x1u                          /**< Base mask for PmlGoRC */
#define  PML_GO_RC(x)                                       (((x)&0x1u)<<25)              /**< Set PmlGoRC in register */
#define  GET_PML_GO_RC(reg)                                 (((reg)>>25)&0x1u)            /**< Get PmlGoRC from register */
#define  PML_WAKE_CLEAR_SHIFT                               26                            /**< Shift for PmlWakeClear */
#define  PML_WAKE_CLEAR_MASK                                0x04000000u                   /**< Mask for PmlWakeClear */
#define  PML_WAKE_CLEAR_BMASK                               0x1u                          /**< Base mask for PmlWakeClear */
#define  PML_WAKE_CLEAR(x)                                  (((x)&0x1u)<<26)              /**< Set PmlWakeClear in register */
#define  GET_PML_WAKE_CLEAR(reg)                            (((reg)>>26)&0x1u)            /**< Get PmlWakeClear from register */

// RegPmlCtrl.regs.PmlClkCtrl
#define  PML_CLK_CTRL_GSHIFT                                0                             /**< Shift for group PmlClkCtrl */
#define  PML_CLK_CTRL_GSIZE                                 8                             /**< Size of group PmlClkCtrl */
#define  PML_CLK_CTRL_GMASK                                 0x000000FFu                   /**< Mask for group PmlClkCtrl */

#define  PML_LF_XTAL_EN_RSHIFT                              0                             /**< Shift for PmlLFXtalEn */
#define  PML_LF_XTAL_EN_RMASK                               0x03u                         /**< Mask for PmlLFXtalEn */
#define  PML_LF_XTAL_EN_RBMASK                              0x3u                          /**< Base mask for PmlLFXtalEn */
#define  PML_LF_XTAL_EN_R(x)                                (((x)&0x3u)<<0)               /**< Set PmlLFXtalEn in register */
#define  GET_PML_LF_XTAL_EN_R(reg)                          (((reg)>>0)&0x3u)             /**< Get PmlLFXtalEn from register */
#define  PML_LF_RC_LP_EN_RSHIFT                             2                             /**< Shift for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN_RMASK                              0x04u                         /**< Mask for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN_RBMASK                             0x1u                          /**< Base mask for PmlLFRCLPEn */
#define  PML_LF_RC_LP_EN_R(x)                               (((x)&0x1u)<<2)               /**< Set PmlLFRCLPEn in register */
#define  GET_PML_LF_RC_LP_EN_R(reg)                         (((reg)>>2)&0x1u)             /**< Get PmlLFRCLPEn from register */
#define  PML_SLP_TIM_ON_XTAL_RSHIFT                         3                             /**< Shift for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL_RMASK                          0x08u                         /**< Mask for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL_RBMASK                         0x1u                          /**< Base mask for PmlSlpTimOnXTAL */
#define  PML_SLP_TIM_ON_XTAL_R(x)                           (((x)&0x1u)<<3)               /**< Set PmlSlpTimOnXTAL in register */
#define  GET_PML_SLP_TIM_ON_XTAL_R(reg)                     (((reg)>>3)&0x1u)             /**< Get PmlSlpTimOnXTAL from register */
#define  PML_SLP_TIM_ON_LP_RSHIFT                           4                             /**< Shift for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP_RMASK                            0x10u                         /**< Mask for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP_RBMASK                           0x1u                          /**< Base mask for PmlSlpTimOnLP */
#define  PML_SLP_TIM_ON_LP_R(x)                             (((x)&0x1u)<<4)               /**< Set PmlSlpTimOnLP in register */
#define  GET_PML_SLP_TIM_ON_LP_R(reg)                       (((reg)>>4)&0x1u)             /**< Get PmlSlpTimOnLP from register */

// RegPmlCtrl.regs.PmlWakeCtrl
#define  PML_WAKE_CTRL_GSHIFT                               8                             /**< Shift for group PmlWakeCtrl */
#define  PML_WAKE_CTRL_GSIZE                                8                             /**< Size of group PmlWakeCtrl */
#define  PML_WAKE_CTRL_GMASK                                0x0000FF00u                   /**< Mask for group PmlWakeCtrl */

#define  PML_WAKE_FLG_EN_RSHIFT                             0                             /**< Shift for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN_RMASK                              0x01u                         /**< Mask for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN_RBMASK                             0x1u                          /**< Base mask for PmlWakeFlgEn */
#define  PML_WAKE_FLG_EN_R(x)                               (((x)&0x1u)<<0)               /**< Set PmlWakeFlgEn in register */
#define  GET_PML_WAKE_FLG_EN_R(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlWakeFlgEn from register */
#define  PML_LATCH_PAD_EN_RSHIFT                            1                             /**< Shift for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN_RMASK                             0x02u                         /**< Mask for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN_RBMASK                            0x1u                          /**< Base mask for PmlLatchPadEn */
#define  PML_LATCH_PAD_EN_R(x)                              (((x)&0x1u)<<1)               /**< Set PmlLatchPadEn in register */
#define  GET_PML_LATCH_PAD_EN_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PmlLatchPadEn from register */

// RegPmlCtrl.regs.PmlPwrCtrl
#define  PML_PWR_CTRL_GSHIFT                                16                            /**< Shift for group PmlPwrCtrl */
#define  PML_PWR_CTRL_GSIZE                                 8                             /**< Size of group PmlPwrCtrl */
#define  PML_PWR_CTRL_GMASK                                 0x00FF0000u                   /**< Mask for group PmlPwrCtrl */

#define  PML_SLEEP_BYPASS_EN_RSHIFT                         0                             /**< Shift for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN_RMASK                          0x01u                         /**< Mask for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN_RBMASK                         0x1u                          /**< Base mask for PmlSleepBypassEn */
#define  PML_SLEEP_BYPASS_EN_R(x)                           (((x)&0x1u)<<0)               /**< Set PmlSleepBypassEn in register */
#define  GET_PML_SLEEP_BYPASS_EN_R(reg)                     (((reg)>>0)&0x1u)             /**< Get PmlSleepBypassEn from register */
#define  PML_LDO_VCC_EN_RSHIFT                              1                             /**< Shift for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN_RMASK                               0x02u                         /**< Mask for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN_RBMASK                              0x1u                          /**< Base mask for PmlLDOVCCEn */
#define  PML_LDO_VCC_EN_R(x)                                (((x)&0x1u)<<1)               /**< Set PmlLDOVCCEn in register */
#define  GET_PML_LDO_VCC_EN_R(reg)                          (((reg)>>1)&0x1u)             /**< Get PmlLDOVCCEn from register */
#define  PML_VBAT_MON_EN_RSHIFT                             2                             /**< Shift for PmlVBATMonEn */
#define  PML_VBAT_MON_EN_RMASK                              0x04u                         /**< Mask for PmlVBATMonEn */
#define  PML_VBAT_MON_EN_RBMASK                             0x1u                          /**< Base mask for PmlVBATMonEn */
#define  PML_VBAT_MON_EN_R(x)                               (((x)&0x1u)<<2)               /**< Set PmlVBATMonEn in register */
#define  GET_PML_VBAT_MON_EN_R(reg)                         (((reg)>>2)&0x1u)             /**< Get PmlVBATMonEn from register */
#define  PML_NVM_BO_RST_EN_RSHIFT                           3                             /**< Shift for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN_RMASK                            0x08u                         /**< Mask for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN_RBMASK                           0x1u                          /**< Base mask for PmlNvmBoRstEn */
#define  PML_NVM_BO_RST_EN_R(x)                             (((x)&0x1u)<<3)               /**< Set PmlNvmBoRstEn in register */
#define  GET_PML_NVM_BO_RST_EN_R(reg)                       (((reg)>>3)&0x1u)             /**< Get PmlNvmBoRstEn from register */
#define  PML_NVM_SW_EN_RSHIFT                               4                             /**< Shift for PmlNvmSwEn */
#define  PML_NVM_SW_EN_RMASK                                0x10u                         /**< Mask for PmlNvmSwEn */
#define  PML_NVM_SW_EN_RBMASK                               0x1u                          /**< Base mask for PmlNvmSwEn */
#define  PML_NVM_SW_EN_R(x)                                 (((x)&0x1u)<<4)               /**< Set PmlNvmSwEn in register */
#define  GET_PML_NVM_SW_EN_R(reg)                           (((reg)>>4)&0x1u)             /**< Get PmlNvmSwEn from register */
#define  PML_RF_SW_EN_RSHIFT                                5                             /**< Shift for PmlRfSwEn */
#define  PML_RF_SW_EN_RMASK                                 0x20u                         /**< Mask for PmlRfSwEn */
#define  PML_RF_SW_EN_RBMASK                                0x1u                          /**< Base mask for PmlRfSwEn */
#define  PML_RF_SW_EN_R(x)                                  (((x)&0x1u)<<5)               /**< Set PmlRfSwEn in register */
#define  GET_PML_RF_SW_EN_R(reg)                            (((reg)>>5)&0x1u)             /**< Get PmlRfSwEn from register */
#define  PML_LDO_VCC_TX_EN_RSHIFT                           6                             /**< Shift for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN_RMASK                            0x40u                         /**< Mask for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN_RBMASK                           0x1u                          /**< Base mask for PmlLDOVCCTXEn */
#define  PML_LDO_VCC_TX_EN_R(x)                             (((x)&0x1u)<<6)               /**< Set PmlLDOVCCTXEn in register */
#define  GET_PML_LDO_VCC_TX_EN_R(reg)                       (((reg)>>6)&0x1u)             /**< Get PmlLDOVCCTXEn from register */

// RegPmlCtrl.regs.PmlModeCtrl
#define  PML_MODE_CTRL_GSHIFT                               24                            /**< Shift for group PmlModeCtrl */
#define  PML_MODE_CTRL_GSIZE                                8                             /**< Size of group PmlModeCtrl */
#define  PML_MODE_CTRL_GMASK                                0xFF000000u                   /**< Mask for group PmlModeCtrl */

#define  PML_GO_XTAL_RSHIFT                                 0                             /**< Shift for PmlGoXtal */
#define  PML_GO_XTAL_RMASK                                  0x01u                         /**< Mask for PmlGoXtal */
#define  PML_GO_XTAL_RBMASK                                 0x1u                          /**< Base mask for PmlGoXtal */
#define  PML_GO_XTAL_R(x)                                   (((x)&0x1u)<<0)               /**< Set PmlGoXtal in register */
#define  GET_PML_GO_XTAL_R(reg)                             (((reg)>>0)&0x1u)             /**< Get PmlGoXtal from register */
#define  PML_GO_RC_RSHIFT                                   1                             /**< Shift for PmlGoRC */
#define  PML_GO_RC_RMASK                                    0x02u                         /**< Mask for PmlGoRC */
#define  PML_GO_RC_RBMASK                                   0x1u                          /**< Base mask for PmlGoRC */
#define  PML_GO_RC_R(x)                                     (((x)&0x1u)<<1)               /**< Set PmlGoRC in register */
#define  GET_PML_GO_RC_R(reg)                               (((reg)>>1)&0x1u)             /**< Get PmlGoRC from register */
#define  PML_WAKE_CLEAR_RSHIFT                              2                             /**< Shift for PmlWakeClear */
#define  PML_WAKE_CLEAR_RMASK                               0x04u                         /**< Mask for PmlWakeClear */
#define  PML_WAKE_CLEAR_RBMASK                              0x1u                          /**< Base mask for PmlWakeClear */
#define  PML_WAKE_CLEAR_R(x)                                (((x)&0x1u)<<2)               /**< Set PmlWakeClear in register */
#define  GET_PML_WAKE_CLEAR_R(reg)                          (((reg)>>2)&0x1u)             /**< Get PmlWakeClear from register */
/** @} */


/**
 * @name RegPmlDomain
 * @{
 */
// RegPmlDomain.r32
#define  REG_PML_DOMAIN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegPmlDomain */
#define  REG_PML_DOMAIN_MASK                                0x0000037Fu                   /**< Mask for RegPmlDomain */

#define  PML_DRAM_RET_ON_SHIFT                              0                             /**< Shift for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_MASK                               0x0000007Fu                   /**< Mask for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_BMASK                              0x7Fu                         /**< Base mask for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON(x)                                 (((x)&0x7Fu)<<0)              /**< Set PmlDRAMRetOn in register */
#define  GET_PML_DRAM_RET_ON(reg)                           (((reg)>>0)&0x7Fu)            /**< Get PmlDRAMRetOn from register */
#define  PML_QDEC_REQ_ON_SHIFT                              8                             /**< Shift for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON_MASK                               0x00000100u                   /**< Mask for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON_BMASK                              0x1u                          /**< Base mask for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON(x)                                 (((x)&0x1u)<<8)               /**< Set PmlQDECReqOn in register */
#define  GET_PML_QDEC_REQ_ON(reg)                           (((reg)>>8)&0x1u)             /**< Get PmlQDECReqOn from register */
#define  PML_NVM_REQ_ON_SHIFT                               9                             /**< Shift for PmlNvmReqOn */
#define  PML_NVM_REQ_ON_MASK                                0x00000200u                   /**< Mask for PmlNvmReqOn */
#define  PML_NVM_REQ_ON_BMASK                               0x1u                          /**< Base mask for PmlNvmReqOn */
#define  PML_NVM_REQ_ON(x)                                  (((x)&0x1u)<<9)               /**< Set PmlNvmReqOn in register */
#define  GET_PML_NVM_REQ_ON(reg)                            (((reg)>>9)&0x1u)             /**< Get PmlNvmReqOn from register */

// RegPmlDomain.regs.PmlDRAMRetOn
#define  PML_DRAM_RET_ON_GSHIFT                             0                             /**< Shift for group PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_GSIZE                              8                             /**< Size of group PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_GMASK                              0x000000FFu                   /**< Mask for group PmlDRAMRetOn */

#define  PML_DRAM_RET_ON_RSHIFT                             0                             /**< Shift for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_RMASK                              0x0000007Fu                   /**< Mask for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_RBMASK                             0x7Fu                         /**< Base mask for PmlDRAMRetOn */
#define  PML_DRAM_RET_ON_R(x)                               (((x)&0x7Fu)<<0)              /**< Set PmlDRAMRetOn in register */
#define  GET_PML_DRAM_RET_ON_R(reg)                         (((reg)>>0)&0x7Fu)            /**< Get PmlDRAMRetOn from register */

// RegPmlDomain.regs.PmlDomainCtrl
#define  PML_DOMAIN_CTRL_GSHIFT                             8                             /**< Shift for group PmlDomainCtrl */
#define  PML_DOMAIN_CTRL_GSIZE                              8                             /**< Size of group PmlDomainCtrl */
#define  PML_DOMAIN_CTRL_GMASK                              0x0000FF00u                   /**< Mask for group PmlDomainCtrl */

#define  PML_QDEC_REQ_ON_RSHIFT                             0                             /**< Shift for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON_RMASK                              0x01u                         /**< Mask for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON_RBMASK                             0x1u                          /**< Base mask for PmlQDECReqOn */
#define  PML_QDEC_REQ_ON_R(x)                               (((x)&0x1u)<<0)               /**< Set PmlQDECReqOn in register */
#define  GET_PML_QDEC_REQ_ON_R(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlQDECReqOn from register */
#define  PML_NVM_REQ_ON_RSHIFT                              1                             /**< Shift for PmlNvmReqOn */
#define  PML_NVM_REQ_ON_RMASK                               0x02u                         /**< Mask for PmlNvmReqOn */
#define  PML_NVM_REQ_ON_RBMASK                              0x1u                          /**< Base mask for PmlNvmReqOn */
#define  PML_NVM_REQ_ON_R(x)                                (((x)&0x1u)<<1)               /**< Set PmlNvmReqOn in register */
#define  GET_PML_NVM_REQ_ON_R(reg)                          (((reg)>>1)&0x1u)             /**< Get PmlNvmReqOn from register */
/** @} */


/**
 * @name RegPmlLvl
 * @{
 */
// RegPmlLvl.r32
#define  REG_PML_LVL_RESET_VALUE                            0x00000044u                   /**< Reset value of RegPmlLvl */
#define  REG_PML_LVL_MASK                                   0x010F1FFFu                   /**< Mask for RegPmlLvl */

#define  PML_VCC_LVL_SHIFT                                  0                             /**< Shift for PmlVCCLvl */
#define  PML_VCC_LVL_MASK                                   0x0000000Fu                   /**< Mask for PmlVCCLvl */
#define  PML_VCC_LVL_BMASK                                  0xFu                          /**< Base mask for PmlVCCLvl */
#define  PML_VCC_LVL(x)                                     (((x)&0xFu)<<0)               /**< Set PmlVCCLvl in register */
#define  GET_PML_VCC_LVL(reg)                               (((reg)>>0)&0xFu)             /**< Get PmlVCCLvl from register */
#define  PML_VCC_LVL_TX_SHIFT                               4                             /**< Shift for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX_MASK                                0x000000F0u                   /**< Mask for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX_BMASK                               0xFu                          /**< Base mask for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX(x)                                  (((x)&0xFu)<<4)               /**< Set PmlVCCLvlTX in register */
#define  GET_PML_VCC_LVL_TX(reg)                            (((reg)>>4)&0xFu)             /**< Get PmlVCCLvlTX from register */
#define  PML_VBAT_LVL_SHIFT                                 8                             /**< Shift for PmlVBATLvl */
#define  PML_VBAT_LVL_MASK                                  0x00000F00u                   /**< Mask for PmlVBATLvl */
#define  PML_VBAT_LVL_BMASK                                 0xFu                          /**< Base mask for PmlVBATLvl */
#define  PML_VBAT_LVL(x)                                    (((x)&0xFu)<<8)               /**< Set PmlVBATLvl in register */
#define  GET_PML_VBAT_LVL(reg)                              (((reg)>>8)&0xFu)             /**< Get PmlVBATLvl from register */
#define  PML_VBAT_1P7_LVL_SHIFT                             12                            /**< Shift for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL_MASK                              0x00001000u                   /**< Mask for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL_BMASK                             0x1u                          /**< Base mask for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL(x)                                (((x)&0x1u)<<12)              /**< Set PmlVBAT1p7Lvl in register */
#define  GET_PML_VBAT_1P7_LVL(reg)                          (((reg)>>12)&0x1u)            /**< Get PmlVBAT1p7Lvl from register */
#define  PML_LDO_VCC_LVL_SHIFT                              16                            /**< Shift for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL_MASK                               0x00030000u                   /**< Mask for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL_BMASK                              0x3u                          /**< Base mask for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL(x)                                 (((x)&0x3u)<<16)              /**< Set PmlLDOVCCLvl in register */
#define  GET_PML_LDO_VCC_LVL(reg)                           (((reg)>>16)&0x3u)            /**< Get PmlLDOVCCLvl from register */
#define  PML_LDO_VCC_LVL_TX_SHIFT                           18                            /**< Shift for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX_MASK                            0x000C0000u                   /**< Mask for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX_BMASK                           0x3u                          /**< Base mask for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX(x)                              (((x)&0x3u)<<18)              /**< Set PmlLDOVCCLvlTX in register */
#define  GET_PML_LDO_VCC_LVL_TX(reg)                        (((reg)>>18)&0x3u)            /**< Get PmlLDOVCCLvlTX from register */
#define  PML_LDO_DIG_LVL_SHIFT                              24                            /**< Shift for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL_MASK                               0x01000000u                   /**< Mask for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL_BMASK                              0x1u                          /**< Base mask for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL(x)                                 (((x)&0x1u)<<24)              /**< Set PmlLDODigLvl in register */
#define  GET_PML_LDO_DIG_LVL(reg)                           (((reg)>>24)&0x1u)            /**< Get PmlLDODigLvl from register */

// RegPmlLvl.regs.PmlVcc
#define  PML_VCC_GSHIFT                                     0                             /**< Shift for group PmlVcc */
#define  PML_VCC_GSIZE                                      8                             /**< Size of group PmlVcc */
#define  PML_VCC_GMASK                                      0x000000FFu                   /**< Mask for group PmlVcc */

#define  PML_VCC_LVL_RSHIFT                                 0                             /**< Shift for PmlVCCLvl */
#define  PML_VCC_LVL_RMASK                                  0x0Fu                         /**< Mask for PmlVCCLvl */
#define  PML_VCC_LVL_RBMASK                                 0xFu                          /**< Base mask for PmlVCCLvl */
#define  PML_VCC_LVL_R(x)                                   (((x)&0xFu)<<0)               /**< Set PmlVCCLvl in register */
#define  GET_PML_VCC_LVL_R(reg)                             (((reg)>>0)&0xFu)             /**< Get PmlVCCLvl from register */
#define  PML_VCC_LVL_TX_RSHIFT                              4                             /**< Shift for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX_RMASK                               0xF0u                         /**< Mask for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX_RBMASK                              0xFu                          /**< Base mask for PmlVCCLvlTX */
#define  PML_VCC_LVL_TX_R(x)                                (((x)&0xFu)<<4)               /**< Set PmlVCCLvlTX in register */
#define  GET_PML_VCC_LVL_TX_R(reg)                          (((reg)>>4)&0xFu)             /**< Get PmlVCCLvlTX from register */

// RegPmlLvl.regs.PmlVbat
#define  PML_VBAT_GSHIFT                                    8                             /**< Shift for group PmlVbat */
#define  PML_VBAT_GSIZE                                     8                             /**< Size of group PmlVbat */
#define  PML_VBAT_GMASK                                     0x0000FF00u                   /**< Mask for group PmlVbat */

#define  PML_VBAT_LVL_RSHIFT                                0                             /**< Shift for PmlVBATLvl */
#define  PML_VBAT_LVL_RMASK                                 0x0Fu                         /**< Mask for PmlVBATLvl */
#define  PML_VBAT_LVL_RBMASK                                0xFu                          /**< Base mask for PmlVBATLvl */
#define  PML_VBAT_LVL_R(x)                                  (((x)&0xFu)<<0)               /**< Set PmlVBATLvl in register */
#define  GET_PML_VBAT_LVL_R(reg)                            (((reg)>>0)&0xFu)             /**< Get PmlVBATLvl from register */
#define  PML_VBAT_1P7_LVL_RSHIFT                            4                             /**< Shift for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL_RMASK                             0x10u                         /**< Mask for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL_RBMASK                            0x1u                          /**< Base mask for PmlVBAT1p7Lvl */
#define  PML_VBAT_1P7_LVL_R(x)                              (((x)&0x1u)<<4)               /**< Set PmlVBAT1p7Lvl in register */
#define  GET_PML_VBAT_1P7_LVL_R(reg)                        (((reg)>>4)&0x1u)             /**< Get PmlVBAT1p7Lvl from register */

// RegPmlLvl.regs.PmlLdoVcc
#define  PML_LDO_VCC_GSHIFT                                 16                            /**< Shift for group PmlLdoVcc */
#define  PML_LDO_VCC_GSIZE                                  8                             /**< Size of group PmlLdoVcc */
#define  PML_LDO_VCC_GMASK                                  0x00FF0000u                   /**< Mask for group PmlLdoVcc */

#define  PML_LDO_VCC_LVL_RSHIFT                             0                             /**< Shift for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL_RMASK                              0x03u                         /**< Mask for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL_RBMASK                             0x3u                          /**< Base mask for PmlLDOVCCLvl */
#define  PML_LDO_VCC_LVL_R(x)                               (((x)&0x3u)<<0)               /**< Set PmlLDOVCCLvl in register */
#define  GET_PML_LDO_VCC_LVL_R(reg)                         (((reg)>>0)&0x3u)             /**< Get PmlLDOVCCLvl from register */
#define  PML_LDO_VCC_LVL_TX_RSHIFT                          2                             /**< Shift for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX_RMASK                           0x0Cu                         /**< Mask for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX_RBMASK                          0x3u                          /**< Base mask for PmlLDOVCCLvlTX */
#define  PML_LDO_VCC_LVL_TX_R(x)                            (((x)&0x3u)<<2)               /**< Set PmlLDOVCCLvlTX in register */
#define  GET_PML_LDO_VCC_LVL_TX_R(reg)                      (((reg)>>2)&0x3u)             /**< Get PmlLDOVCCLvlTX from register */

// RegPmlLvl.regs.PmlLdoDig
#define  PML_LDO_DIG_GSHIFT                                 24                            /**< Shift for group PmlLdoDig */
#define  PML_LDO_DIG_GSIZE                                  8                             /**< Size of group PmlLdoDig */
#define  PML_LDO_DIG_GMASK                                  0xFF000000u                   /**< Mask for group PmlLdoDig */

#define  PML_LDO_DIG_LVL_RSHIFT                             0                             /**< Shift for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL_RMASK                              0x01u                         /**< Mask for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL_RBMASK                             0x1u                          /**< Base mask for PmlLDODigLvl */
#define  PML_LDO_DIG_LVL_R(x)                               (((x)&0x1u)<<0)               /**< Set PmlLDODigLvl in register */
#define  GET_PML_LDO_DIG_LVL_R(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlLDODigLvl from register */
/** @} */


/**
 * @name RegPmlPadWake
 * @{
 */
// RegPmlPadWake.r32
#define  REG_PML_PAD_WAKE_RESET_VALUE                       0x00000000u                   /**< Reset value of RegPmlPadWake */
#define  REG_PML_PAD_WAKE_MASK                              0x0FFF0FFFu                   /**< Mask for RegPmlPadWake */

#define  PML_PAD_WAKE_EN_SHIFT                              0                             /**< Shift for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_MASK                               0x00000FFFu                   /**< Mask for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_BMASK                              0xFFFu                        /**< Base mask for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN(x)                                 (((x)&0xFFFu)<<0)             /**< Set PmlPadWakeEn in register */
#define  GET_PML_PAD_WAKE_EN(reg)                           (((reg)>>0)&0xFFFu)           /**< Get PmlPadWakeEn from register */
#define  PML_PAD_WAKE_POL_SHIFT                             16                            /**< Shift for PmlPadWakePol */
#define  PML_PAD_WAKE_POL_MASK                              0x0FFF0000u                   /**< Mask for PmlPadWakePol */
#define  PML_PAD_WAKE_POL_BMASK                             0xFFFu                        /**< Base mask for PmlPadWakePol */
#define  PML_PAD_WAKE_POL(x)                                (((x)&0xFFFu)<<16)            /**< Set PmlPadWakePol in register */
#define  GET_PML_PAD_WAKE_POL(reg)                          (((reg)>>16)&0xFFFu)          /**< Get PmlPadWakePol from register */

// RegPmlPadWake.regs.PmlPadWakeEn
#define  PML_PAD_WAKE_EN_GSHIFT                             0                             /**< Shift for group PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_GSIZE                              16                            /**< Size of group PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_GMASK                              0x0000FFFFu                   /**< Mask for group PmlPadWakeEn */

#define  PML_PAD_WAKE_EN_RSHIFT                             0                             /**< Shift for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_RMASK                              0x00000FFFu                   /**< Mask for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_RBMASK                             0xFFFu                        /**< Base mask for PmlPadWakeEn */
#define  PML_PAD_WAKE_EN_R(x)                               (((x)&0xFFFu)<<0)             /**< Set PmlPadWakeEn in register */
#define  GET_PML_PAD_WAKE_EN_R(reg)                         (((reg)>>0)&0xFFFu)           /**< Get PmlPadWakeEn from register */

// RegPmlPadWake.regs.PmlPadWakePol
#define  PML_PAD_WAKE_POL_GSHIFT                            16                            /**< Shift for group PmlPadWakePol */
#define  PML_PAD_WAKE_POL_GSIZE                             16                            /**< Size of group PmlPadWakePol */
#define  PML_PAD_WAKE_POL_GMASK                             0xFFFF0000u                   /**< Mask for group PmlPadWakePol */

#define  PML_PAD_WAKE_POL_RSHIFT                            0                             /**< Shift for PmlPadWakePol */
#define  PML_PAD_WAKE_POL_RMASK                             0x00000FFFu                   /**< Mask for PmlPadWakePol */
#define  PML_PAD_WAKE_POL_RBMASK                            0xFFFu                        /**< Base mask for PmlPadWakePol */
#define  PML_PAD_WAKE_POL_R(x)                              (((x)&0xFFFu)<<0)             /**< Set PmlPadWakePol in register */
#define  GET_PML_PAD_WAKE_POL_R(reg)                        (((reg)>>0)&0xFFFu)           /**< Get PmlPadWakePol from register */
/** @} */


/**
 * @name RegPmlDCDCTim
 * @{
 */
// RegPmlDCDCTim.r32
#define  REG_PML_DCDC_TIM_RESET_VALUE                       0x0E060D06u                   /**< Reset value of RegPmlDCDCTim */
#define  REG_PML_DCDC_TIM_MASK                              0x1F1F1F1Fu                   /**< Mask for RegPmlDCDCTim */

#define  PML_DCDC_T1_SHIFT                                  0                             /**< Shift for PmlDCDCT1 */
#define  PML_DCDC_T1_MASK                                   0x0000001Fu                   /**< Mask for PmlDCDCT1 */
#define  PML_DCDC_T1_BMASK                                  0x1Fu                         /**< Base mask for PmlDCDCT1 */
#define  PML_DCDC_T1(x)                                     (((x)&0x1Fu)<<0)              /**< Set PmlDCDCT1 in register */
#define  GET_PML_DCDC_T1(reg)                               (((reg)>>0)&0x1Fu)            /**< Get PmlDCDCT1 from register */
#define  PML_DCDC_T2_SHIFT                                  8                             /**< Shift for PmlDCDCT2 */
#define  PML_DCDC_T2_MASK                                   0x00001F00u                   /**< Mask for PmlDCDCT2 */
#define  PML_DCDC_T2_BMASK                                  0x1Fu                         /**< Base mask for PmlDCDCT2 */
#define  PML_DCDC_T2(x)                                     (((x)&0x1Fu)<<8)              /**< Set PmlDCDCT2 in register */
#define  GET_PML_DCDC_T2(reg)                               (((reg)>>8)&0x1Fu)            /**< Get PmlDCDCT2 from register */
#define  PML_DCDC_T1_TX_SHIFT                               16                            /**< Shift for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_MASK                                0x001F0000u                   /**< Mask for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_BMASK                               0x1Fu                         /**< Base mask for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX(x)                                  (((x)&0x1Fu)<<16)             /**< Set PmlDCDCT1TX in register */
#define  GET_PML_DCDC_T1_TX(reg)                            (((reg)>>16)&0x1Fu)           /**< Get PmlDCDCT1TX from register */
#define  PML_DCDC_T2_TX_SHIFT                               24                            /**< Shift for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_MASK                                0x1F000000u                   /**< Mask for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_BMASK                               0x1Fu                         /**< Base mask for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX(x)                                  (((x)&0x1Fu)<<24)             /**< Set PmlDCDCT2TX in register */
#define  GET_PML_DCDC_T2_TX(reg)                            (((reg)>>24)&0x1Fu)           /**< Get PmlDCDCT2TX from register */

// RegPmlDCDCTim.regs.PmlDCDCT1
#define  PML_DCDC_T1_GSHIFT                                 0                             /**< Shift for group PmlDCDCT1 */
#define  PML_DCDC_T1_GSIZE                                  8                             /**< Size of group PmlDCDCT1 */
#define  PML_DCDC_T1_GMASK                                  0x000000FFu                   /**< Mask for group PmlDCDCT1 */

#define  PML_DCDC_T1_RSHIFT                                 0                             /**< Shift for PmlDCDCT1 */
#define  PML_DCDC_T1_RMASK                                  0x0000001Fu                   /**< Mask for PmlDCDCT1 */
#define  PML_DCDC_T1_RBMASK                                 0x1Fu                         /**< Base mask for PmlDCDCT1 */
#define  PML_DCDC_T1_R(x)                                   (((x)&0x1Fu)<<0)              /**< Set PmlDCDCT1 in register */
#define  GET_PML_DCDC_T1_R(reg)                             (((reg)>>0)&0x1Fu)            /**< Get PmlDCDCT1 from register */

// RegPmlDCDCTim.regs.PmlDCDCT2
#define  PML_DCDC_T2_GSHIFT                                 8                             /**< Shift for group PmlDCDCT2 */
#define  PML_DCDC_T2_GSIZE                                  8                             /**< Size of group PmlDCDCT2 */
#define  PML_DCDC_T2_GMASK                                  0x0000FF00u                   /**< Mask for group PmlDCDCT2 */

#define  PML_DCDC_T2_RSHIFT                                 0                             /**< Shift for PmlDCDCT2 */
#define  PML_DCDC_T2_RMASK                                  0x0000001Fu                   /**< Mask for PmlDCDCT2 */
#define  PML_DCDC_T2_RBMASK                                 0x1Fu                         /**< Base mask for PmlDCDCT2 */
#define  PML_DCDC_T2_R(x)                                   (((x)&0x1Fu)<<0)              /**< Set PmlDCDCT2 in register */
#define  GET_PML_DCDC_T2_R(reg)                             (((reg)>>0)&0x1Fu)            /**< Get PmlDCDCT2 from register */

// RegPmlDCDCTim.regs.PmlDCDCT1TX
#define  PML_DCDC_T1_TX_GSHIFT                              16                            /**< Shift for group PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_GSIZE                               8                             /**< Size of group PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_GMASK                               0x00FF0000u                   /**< Mask for group PmlDCDCT1TX */

#define  PML_DCDC_T1_TX_RSHIFT                              0                             /**< Shift for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_RMASK                               0x0000001Fu                   /**< Mask for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_RBMASK                              0x1Fu                         /**< Base mask for PmlDCDCT1TX */
#define  PML_DCDC_T1_TX_R(x)                                (((x)&0x1Fu)<<0)              /**< Set PmlDCDCT1TX in register */
#define  GET_PML_DCDC_T1_TX_R(reg)                          (((reg)>>0)&0x1Fu)            /**< Get PmlDCDCT1TX from register */

// RegPmlDCDCTim.regs.PmlDCDCT2TX
#define  PML_DCDC_T2_TX_GSHIFT                              24                            /**< Shift for group PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_GSIZE                               8                             /**< Size of group PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_GMASK                               0xFF000000u                   /**< Mask for group PmlDCDCT2TX */

#define  PML_DCDC_T2_TX_RSHIFT                              0                             /**< Shift for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_RMASK                               0x0000001Fu                   /**< Mask for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_RBMASK                              0x1Fu                         /**< Base mask for PmlDCDCT2TX */
#define  PML_DCDC_T2_TX_R(x)                                (((x)&0x1Fu)<<0)              /**< Set PmlDCDCT2TX in register */
#define  GET_PML_DCDC_T2_TX_R(reg)                          (((reg)>>0)&0x1Fu)            /**< Get PmlDCDCT2TX from register */
/** @} */


/**
 * @name RegPmlDCDCPer
 * @{
 */
// RegPmlDCDCPer.r32
#define  REG_PML_DCDC_PER_RESET_VALUE                       0x30D42F2Fu                   /**< Reset value of RegPmlDCDCPer */
#define  REG_PML_DCDC_PER_MASK                              0xFFFF7F7Fu                   /**< Mask for RegPmlDCDCPer */

#define  PML_DCDC_PER_SHIFT                                 0                             /**< Shift for PmlDCDCPer */
#define  PML_DCDC_PER_MASK                                  0x0000007Fu                   /**< Mask for PmlDCDCPer */
#define  PML_DCDC_PER_BMASK                                 0x7Fu                         /**< Base mask for PmlDCDCPer */
#define  PML_DCDC_PER(x)                                    (((x)&0x7Fu)<<0)              /**< Set PmlDCDCPer in register */
#define  GET_PML_DCDC_PER(reg)                              (((reg)>>0)&0x7Fu)            /**< Get PmlDCDCPer from register */
#define  PML_ADC_PER_SHIFT                                  8                             /**< Shift for PmlADCPer */
#define  PML_ADC_PER_MASK                                   0x00007F00u                   /**< Mask for PmlADCPer */
#define  PML_ADC_PER_BMASK                                  0x7Fu                         /**< Base mask for PmlADCPer */
#define  PML_ADC_PER(x)                                     (((x)&0x7Fu)<<8)              /**< Set PmlADCPer in register */
#define  GET_PML_ADC_PER(reg)                               (((reg)>>8)&0x7Fu)            /**< Get PmlADCPer from register */
#define  PML_BYPASS_TIM_SHIFT                               16                            /**< Shift for PmlBypassTim */
#define  PML_BYPASS_TIM_MASK                                0xFFFF0000u                   /**< Mask for PmlBypassTim */
#define  PML_BYPASS_TIM_BMASK                               0xFFFFu                       /**< Base mask for PmlBypassTim */
#define  PML_BYPASS_TIM(x)                                  (((x)&0xFFFFu)<<16)           /**< Set PmlBypassTim in register */
#define  GET_PML_BYPASS_TIM(reg)                            (((reg)>>16)&0xFFFFu)         /**< Get PmlBypassTim from register */

// RegPmlDCDCPer.regs.PmlDCDCPer
#define  PML_DCDC_PER_GSHIFT                                0                             /**< Shift for group PmlDCDCPer */
#define  PML_DCDC_PER_GSIZE                                 8                             /**< Size of group PmlDCDCPer */
#define  PML_DCDC_PER_GMASK                                 0x000000FFu                   /**< Mask for group PmlDCDCPer */

#define  PML_DCDC_PER_RSHIFT                                0                             /**< Shift for PmlDCDCPer */
#define  PML_DCDC_PER_RMASK                                 0x0000007Fu                   /**< Mask for PmlDCDCPer */
#define  PML_DCDC_PER_RBMASK                                0x7Fu                         /**< Base mask for PmlDCDCPer */
#define  PML_DCDC_PER_R(x)                                  (((x)&0x7Fu)<<0)              /**< Set PmlDCDCPer in register */
#define  GET_PML_DCDC_PER_R(reg)                            (((reg)>>0)&0x7Fu)            /**< Get PmlDCDCPer from register */

// RegPmlDCDCPer.regs.PmlADCPer
#define  PML_ADC_PER_GSHIFT                                 8                             /**< Shift for group PmlADCPer */
#define  PML_ADC_PER_GSIZE                                  8                             /**< Size of group PmlADCPer */
#define  PML_ADC_PER_GMASK                                  0x0000FF00u                   /**< Mask for group PmlADCPer */

#define  PML_ADC_PER_RSHIFT                                 0                             /**< Shift for PmlADCPer */
#define  PML_ADC_PER_RMASK                                  0x0000007Fu                   /**< Mask for PmlADCPer */
#define  PML_ADC_PER_RBMASK                                 0x7Fu                         /**< Base mask for PmlADCPer */
#define  PML_ADC_PER_R(x)                                   (((x)&0x7Fu)<<0)              /**< Set PmlADCPer in register */
#define  GET_PML_ADC_PER_R(reg)                             (((reg)>>0)&0x7Fu)            /**< Get PmlADCPer from register */

// RegPmlDCDCPer.regs.PmlBypassTim
#define  PML_BYPASS_TIM_GSHIFT                              16                            /**< Shift for group PmlBypassTim */
#define  PML_BYPASS_TIM_GSIZE                               16                            /**< Size of group PmlBypassTim */
#define  PML_BYPASS_TIM_GMASK                               0xFFFF0000u                   /**< Mask for group PmlBypassTim */

#define  PML_BYPASS_TIM_RSHIFT                              0                             /**< Shift for PmlBypassTim */
#define  PML_BYPASS_TIM_RMASK                               0x0000FFFFu                   /**< Mask for PmlBypassTim */
#define  PML_BYPASS_TIM_RBMASK                              0xFFFFu                       /**< Base mask for PmlBypassTim */
#define  PML_BYPASS_TIM_R(x)                                (((x)&0xFFFFu)<<0)            /**< Set PmlBypassTim in register */
#define  GET_PML_BYPASS_TIM_R(reg)                          (((reg)>>0)&0xFFFFu)          /**< Get PmlBypassTim from register */
/** @} */


/**
 * @name RegPmlDCDCCtrl
 * @{
 */
// RegPmlDCDCCtrl.r32
#define  REG_PML_DCDC_CTRL_RESET_VALUE                      0x00070002u                   /**< Reset value of RegPmlDCDCCtrl */
#define  REG_PML_DCDC_CTRL_MASK                             0x000F1F07u                   /**< Mask for RegPmlDCDCCtrl */

#define  PML_DCDC_BOOST_EN_SHIFT                            0                             /**< Shift for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN_MASK                             0x00000001u                   /**< Mask for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN_BMASK                            0x1u                          /**< Base mask for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN(x)                               (((x)&0x1u)<<0)               /**< Set PmlDCDCBoostEn in register */
#define  GET_PML_DCDC_BOOST_EN(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlDCDCBoostEn from register */
#define  PML_DCDC_T2_AUTO_SHIFT                             1                             /**< Shift for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO_MASK                              0x00000002u                   /**< Mask for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO_BMASK                             0x1u                          /**< Base mask for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO(x)                                (((x)&0x1u)<<1)               /**< Set PmlDCDCT2auto in register */
#define  GET_PML_DCDC_T2_AUTO(reg)                          (((reg)>>1)&0x1u)             /**< Get PmlDCDCT2auto from register */
#define  PML_VBAT1_SW_EN_SHIFT                              2                             /**< Shift for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN_MASK                               0x00000004u                   /**< Mask for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN_BMASK                              0x1u                          /**< Base mask for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN(x)                                 (((x)&0x1u)<<2)               /**< Set PmlVBAT1SwEn in register */
#define  GET_PML_VBAT1_SW_EN(reg)                           (((reg)>>2)&0x1u)             /**< Get PmlVBAT1SwEn from register */
#define  PML_SC_DB_EN_SHIFT                                 8                             /**< Shift for PmlScDbEn */
#define  PML_SC_DB_EN_MASK                                  0x00000100u                   /**< Mask for PmlScDbEn */
#define  PML_SC_DB_EN_BMASK                                 0x1u                          /**< Base mask for PmlScDbEn */
#define  PML_SC_DB_EN(x)                                    (((x)&0x1u)<<8)               /**< Set PmlScDbEn in register */
#define  GET_PML_SC_DB_EN(reg)                              (((reg)>>8)&0x1u)             /**< Get PmlScDbEn from register */
#define  PML_SC_DB_INIT_N_SHIFT                             9                             /**< Shift for PmlScDbInitN */
#define  PML_SC_DB_INIT_N_MASK                              0x00000200u                   /**< Mask for PmlScDbInitN */
#define  PML_SC_DB_INIT_N_BMASK                             0x1u                          /**< Base mask for PmlScDbInitN */
#define  PML_SC_DB_INIT_N(x)                                (((x)&0x1u)<<9)               /**< Set PmlScDbInitN in register */
#define  GET_PML_SC_DB_INIT_N(reg)                          (((reg)>>9)&0x1u)             /**< Get PmlScDbInitN from register */
#define  PML_SC_DB_MODE_SHIFT                               10                            /**< Shift for PmlScDbMode */
#define  PML_SC_DB_MODE_MASK                                0x00000C00u                   /**< Mask for PmlScDbMode */
#define  PML_SC_DB_MODE_BMASK                               0x3u                          /**< Base mask for PmlScDbMode */
#define  PML_SC_DB_MODE(x)                                  (((x)&0x3u)<<10)              /**< Set PmlScDbMode in register */
#define  GET_PML_SC_DB_MODE(reg)                            (((reg)>>10)&0x3u)            /**< Get PmlScDbMode from register */
#define  PML_SC_DB_SEL_CLK_SHIFT                            12                            /**< Shift for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK_MASK                             0x00001000u                   /**< Mask for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK_BMASK                            0x1u                          /**< Base mask for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK(x)                               (((x)&0x1u)<<12)              /**< Set PmlScDbSelClk in register */
#define  GET_PML_SC_DB_SEL_CLK(reg)                         (((reg)>>12)&0x1u)            /**< Get PmlScDbSelClk from register */
#define  PML_SC_DB_PWM_SHIFT                                16                            /**< Shift for PmlScDbPwm */
#define  PML_SC_DB_PWM_MASK                                 0x000F0000u                   /**< Mask for PmlScDbPwm */
#define  PML_SC_DB_PWM_BMASK                                0xFu                          /**< Base mask for PmlScDbPwm */
#define  PML_SC_DB_PWM(x)                                   (((x)&0xFu)<<16)              /**< Set PmlScDbPwm in register */
#define  GET_PML_SC_DB_PWM(reg)                             (((reg)>>16)&0xFu)            /**< Get PmlScDbPwm from register */

// RegPmlDCDCCtrl.regs.PmlDcdcCtrl
#define  PML_DCDC_CTRL_GSHIFT                               0                             /**< Shift for group PmlDcdcCtrl */
#define  PML_DCDC_CTRL_GSIZE                                8                             /**< Size of group PmlDcdcCtrl */
#define  PML_DCDC_CTRL_GMASK                                0x000000FFu                   /**< Mask for group PmlDcdcCtrl */

#define  PML_DCDC_BOOST_EN_RSHIFT                           0                             /**< Shift for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN_RMASK                            0x01u                         /**< Mask for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN_RBMASK                           0x1u                          /**< Base mask for PmlDCDCBoostEn */
#define  PML_DCDC_BOOST_EN_R(x)                             (((x)&0x1u)<<0)               /**< Set PmlDCDCBoostEn in register */
#define  GET_PML_DCDC_BOOST_EN_R(reg)                       (((reg)>>0)&0x1u)             /**< Get PmlDCDCBoostEn from register */
#define  PML_DCDC_T2_AUTO_RSHIFT                            1                             /**< Shift for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO_RMASK                             0x02u                         /**< Mask for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO_RBMASK                            0x1u                          /**< Base mask for PmlDCDCT2auto */
#define  PML_DCDC_T2_AUTO_R(x)                              (((x)&0x1u)<<1)               /**< Set PmlDCDCT2auto in register */
#define  GET_PML_DCDC_T2_AUTO_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PmlDCDCT2auto from register */
#define  PML_VBAT1_SW_EN_RSHIFT                             2                             /**< Shift for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN_RMASK                              0x04u                         /**< Mask for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN_RBMASK                             0x1u                          /**< Base mask for PmlVBAT1SwEn */
#define  PML_VBAT1_SW_EN_R(x)                               (((x)&0x1u)<<2)               /**< Set PmlVBAT1SwEn in register */
#define  GET_PML_VBAT1_SW_EN_R(reg)                         (((reg)>>2)&0x1u)             /**< Get PmlVBAT1SwEn from register */

// RegPmlDCDCCtrl.regs.PmlScDbCtrl
#define  PML_SC_DB_CTRL_GSHIFT                              8                             /**< Shift for group PmlScDbCtrl */
#define  PML_SC_DB_CTRL_GSIZE                               8                             /**< Size of group PmlScDbCtrl */
#define  PML_SC_DB_CTRL_GMASK                               0x0000FF00u                   /**< Mask for group PmlScDbCtrl */

#define  PML_SC_DB_EN_RSHIFT                                0                             /**< Shift for PmlScDbEn */
#define  PML_SC_DB_EN_RMASK                                 0x01u                         /**< Mask for PmlScDbEn */
#define  PML_SC_DB_EN_RBMASK                                0x1u                          /**< Base mask for PmlScDbEn */
#define  PML_SC_DB_EN_R(x)                                  (((x)&0x1u)<<0)               /**< Set PmlScDbEn in register */
#define  GET_PML_SC_DB_EN_R(reg)                            (((reg)>>0)&0x1u)             /**< Get PmlScDbEn from register */
#define  PML_SC_DB_INIT_N_RSHIFT                            1                             /**< Shift for PmlScDbInitN */
#define  PML_SC_DB_INIT_N_RMASK                             0x02u                         /**< Mask for PmlScDbInitN */
#define  PML_SC_DB_INIT_N_RBMASK                            0x1u                          /**< Base mask for PmlScDbInitN */
#define  PML_SC_DB_INIT_N_R(x)                              (((x)&0x1u)<<1)               /**< Set PmlScDbInitN in register */
#define  GET_PML_SC_DB_INIT_N_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PmlScDbInitN from register */
#define  PML_SC_DB_MODE_RSHIFT                              2                             /**< Shift for PmlScDbMode */
#define  PML_SC_DB_MODE_RMASK                               0x0Cu                         /**< Mask for PmlScDbMode */
#define  PML_SC_DB_MODE_RBMASK                              0x3u                          /**< Base mask for PmlScDbMode */
#define  PML_SC_DB_MODE_R(x)                                (((x)&0x3u)<<2)               /**< Set PmlScDbMode in register */
#define  GET_PML_SC_DB_MODE_R(reg)                          (((reg)>>2)&0x3u)             /**< Get PmlScDbMode from register */
#define  PML_SC_DB_SEL_CLK_RSHIFT                           4                             /**< Shift for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK_RMASK                            0x10u                         /**< Mask for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK_RBMASK                           0x1u                          /**< Base mask for PmlScDbSelClk */
#define  PML_SC_DB_SEL_CLK_R(x)                             (((x)&0x1u)<<4)               /**< Set PmlScDbSelClk in register */
#define  GET_PML_SC_DB_SEL_CLK_R(reg)                       (((reg)>>4)&0x1u)             /**< Get PmlScDbSelClk from register */

// RegPmlDCDCCtrl.regs.PmlScDbPwm
#define  PML_SC_DB_PWM_GSHIFT                               16                            /**< Shift for group PmlScDbPwm */
#define  PML_SC_DB_PWM_GSIZE                                8                             /**< Size of group PmlScDbPwm */
#define  PML_SC_DB_PWM_GMASK                                0x00FF0000u                   /**< Mask for group PmlScDbPwm */

#define  PML_SC_DB_PWM_RSHIFT                               0                             /**< Shift for PmlScDbPwm */
#define  PML_SC_DB_PWM_RMASK                                0x0Fu                         /**< Mask for PmlScDbPwm */
#define  PML_SC_DB_PWM_RBMASK                               0xFu                          /**< Base mask for PmlScDbPwm */
#define  PML_SC_DB_PWM_R(x)                                 (((x)&0xFu)<<0)               /**< Set PmlScDbPwm in register */
#define  GET_PML_SC_DB_PWM_R(reg)                           (((reg)>>0)&0xFu)             /**< Get PmlScDbPwm from register */
/** @} */


/**
 * @name RegPmlLockBits
 * @{
 */
// RegPmlLockBits.r32
#define  REG_PML_LOCK_BITS_RESET_VALUE                      0x003F0F00u                   /**< Reset value of RegPmlLockBits */
#define  REG_PML_LOCK_BITS_MASK                             0x033F0F07u                   /**< Mask for RegPmlLockBits */

#define  PML_JTAG_LOCK_SHIFT                                0                             /**< Shift for PmlJtagLock */
#define  PML_JTAG_LOCK_MASK                                 0x00000001u                   /**< Mask for PmlJtagLock */
#define  PML_JTAG_LOCK_BMASK                                0x1u                          /**< Base mask for PmlJtagLock */
#define  PML_JTAG_LOCK(x)                                   (((x)&0x1u)<<0)               /**< Set PmlJtagLock in register */
#define  GET_PML_JTAG_LOCK(reg)                             (((reg)>>0)&0x1u)             /**< Get PmlJtagLock from register */
#define  PML_USB_LOCK_SHIFT                                 1                             /**< Shift for PmlUsbLock */
#define  PML_USB_LOCK_MASK                                  0x00000002u                   /**< Mask for PmlUsbLock */
#define  PML_USB_LOCK_BMASK                                 0x1u                          /**< Base mask for PmlUsbLock */
#define  PML_USB_LOCK(x)                                    (((x)&0x1u)<<1)               /**< Set PmlUsbLock in register */
#define  GET_PML_USB_LOCK(reg)                              (((reg)>>1)&0x1u)             /**< Get PmlUsbLock from register */
#define  PML_TM_LOCK_SHIFT                                  2                             /**< Shift for PmlTmLock */
#define  PML_TM_LOCK_MASK                                   0x00000004u                   /**< Mask for PmlTmLock */
#define  PML_TM_LOCK_BMASK                                  0x1u                          /**< Base mask for PmlTmLock */
#define  PML_TM_LOCK(x)                                     (((x)&0x1u)<<2)               /**< Set PmlTmLock in register */
#define  GET_PML_TM_LOCK(reg)                               (((reg)>>2)&0x1u)             /**< Get PmlTmLock from register */
#define  PML_LDO_ANT_TRIM_LOCK_SHIFT                        8                             /**< Shift for PmlLdoAntTrimLock */
#define  PML_LDO_ANT_TRIM_LOCK_MASK                         0x00000F00u                   /**< Mask for PmlLdoAntTrimLock */
#define  PML_LDO_ANT_TRIM_LOCK_BMASK                        0xFu                          /**< Base mask for PmlLdoAntTrimLock */
#define  PML_LDO_ANT_TRIM_LOCK(x)                           (((x)&0xFu)<<8)               /**< Set PmlLdoAntTrimLock in register */
#define  GET_PML_LDO_ANT_TRIM_LOCK(reg)                     (((reg)>>8)&0xFu)             /**< Get PmlLdoAntTrimLock from register */
#define  PML_TX_PA_PWR_LOCK_SHIFT                           16                            /**< Shift for PmlTxPaPwrLock */
#define  PML_TX_PA_PWR_LOCK_MASK                            0x003F0000u                   /**< Mask for PmlTxPaPwrLock */
#define  PML_TX_PA_PWR_LOCK_BMASK                           0x3Fu                         /**< Base mask for PmlTxPaPwrLock */
#define  PML_TX_PA_PWR_LOCK(x)                              (((x)&0x3Fu)<<16)             /**< Set PmlTxPaPwrLock in register */
#define  GET_PML_TX_PA_PWR_LOCK(reg)                        (((reg)>>16)&0x3Fu)           /**< Get PmlTxPaPwrLock from register */
#define  PML_JTAG_4W_EN_SHIFT                               24                            /**< Shift for PmlJtag4wEn */
#define  PML_JTAG_4W_EN_MASK                                0x01000000u                   /**< Mask for PmlJtag4wEn */
#define  PML_JTAG_4W_EN_BMASK                               0x1u                          /**< Base mask for PmlJtag4wEn */
#define  PML_JTAG_4W_EN(x)                                  (((x)&0x1u)<<24)              /**< Set PmlJtag4wEn in register */
#define  GET_PML_JTAG_4W_EN(reg)                            (((reg)>>24)&0x1u)            /**< Get PmlJtag4wEn from register */
#define  PML_JTAG_2W_EN_SHIFT                               25                            /**< Shift for PmlJtag2wEn */
#define  PML_JTAG_2W_EN_MASK                                0x02000000u                   /**< Mask for PmlJtag2wEn */
#define  PML_JTAG_2W_EN_BMASK                               0x1u                          /**< Base mask for PmlJtag2wEn */
#define  PML_JTAG_2W_EN(x)                                  (((x)&0x1u)<<25)              /**< Set PmlJtag2wEn in register */
#define  GET_PML_JTAG_2W_EN(reg)                            (((reg)>>25)&0x1u)            /**< Get PmlJtag2wEn from register */
/** @} */


/**
 * @name RegPmlSWRst
 * @{
 */
// RegPmlSWRst.r32
#define  REG_PML_SW_RST_RESET_VALUE                         0x00000000u                   /**< Reset value of RegPmlSWRst */
#define  REG_PML_SW_RST_MASK                                0xFFFFFFFFu                   /**< Mask for RegPmlSWRst */

#define  PML_SW_RST_SHIFT                                   0                             /**< Shift for PmlSWRst */
#define  PML_SW_RST_MASK                                    0xFFFFFFFFu                   /**< Mask for PmlSWRst */
#define  PML_SW_RST_BMASK                                   0xFFFFFFFFu                   /**< Base mask for PmlSWRst */
#define  PML_SW_RST(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set PmlSWRst in register */
#define  GET_PML_SW_RST(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get PmlSWRst from register */
/** @} */


/**
 * @name RegPmlTrim
 * @{
 */
// RegPmlTrim.r32
#define  REG_PML_TRIM_RESET_VALUE                           0x07CBEFEFu                   /**< Reset value of RegPmlTrim */
#define  REG_PML_TRIM_MASK                                  0x3FFFFFFFu                   /**< Mask for RegPmlTrim */

#define  PML_VREF_TRIM_SHIFT                                0                             /**< Shift for PmlVRefTrim */
#define  PML_VREF_TRIM_MASK                                 0x0000001Fu                   /**< Mask for PmlVRefTrim */
#define  PML_VREF_TRIM_BMASK                                0x1Fu                         /**< Base mask for PmlVRefTrim */
#define  PML_VREF_TRIM(x)                                   (((x)&0x1Fu)<<0)              /**< Set PmlVRefTrim in register */
#define  GET_PML_VREF_TRIM(reg)                             (((reg)>>0)&0x1Fu)            /**< Get PmlVRefTrim from register */
#define  PML_LF_RC_FCHOP_SHIFT                              5                             /**< Shift for PmlLFRCFChop */
#define  PML_LF_RC_FCHOP_MASK                               0x000000E0u                   /**< Mask for PmlLFRCFChop */
#define  PML_LF_RC_FCHOP_BMASK                              0x7u                          /**< Base mask for PmlLFRCFChop */
#define  PML_LF_RC_FCHOP(x)                                 (((x)&0x7u)<<5)               /**< Set PmlLFRCFChop in register */
#define  GET_PML_LF_RC_FCHOP(reg)                           (((reg)>>5)&0x7u)             /**< Get PmlLFRCFChop from register */
#define  PML_LF_RC_TRIM_P_SHIFT                             8                             /**< Shift for PmlLFRCTrimP */
#define  PML_LF_RC_TRIM_P_MASK                              0x00000F00u                   /**< Mask for PmlLFRCTrimP */
#define  PML_LF_RC_TRIM_P_BMASK                             0xFu                          /**< Base mask for PmlLFRCTrimP */
#define  PML_LF_RC_TRIM_P(x)                                (((x)&0xFu)<<8)               /**< Set PmlLFRCTrimP in register */
#define  GET_PML_LF_RC_TRIM_P(reg)                          (((reg)>>8)&0xFu)             /**< Get PmlLFRCTrimP from register */
#define  PML_LF_RC_TRIM_N_SHIFT                             12                            /**< Shift for PmlLFRCTrimN */
#define  PML_LF_RC_TRIM_N_MASK                              0x0000F000u                   /**< Mask for PmlLFRCTrimN */
#define  PML_LF_RC_TRIM_N_BMASK                             0xFu                          /**< Base mask for PmlLFRCTrimN */
#define  PML_LF_RC_TRIM_N(x)                                (((x)&0xFu)<<12)              /**< Set PmlLFRCTrimN in register */
#define  GET_PML_LF_RC_TRIM_N(reg)                          (((reg)>>12)&0xFu)            /**< Get PmlLFRCTrimN from register */
#define  PML_HF_RC_TRIM_SHIFT                               16                            /**< Shift for PmlHFRCTrim */
#define  PML_HF_RC_TRIM_MASK                                0x003F0000u                   /**< Mask for PmlHFRCTrim */
#define  PML_HF_RC_TRIM_BMASK                               0x3Fu                         /**< Base mask for PmlHFRCTrim */
#define  PML_HF_RC_TRIM(x)                                  (((x)&0x3Fu)<<16)             /**< Set PmlHFRCTrim in register */
#define  GET_PML_HF_RC_TRIM(reg)                            (((reg)>>16)&0x3Fu)           /**< Get PmlHFRCTrim from register */
#define  PML_LF_RC_TRIM_SHIFT                               22                            /**< Shift for PmlLFRCTrim */
#define  PML_LF_RC_TRIM_MASK                                0x00C00000u                   /**< Mask for PmlLFRCTrim */
#define  PML_LF_RC_TRIM_BMASK                               0x3u                          /**< Base mask for PmlLFRCTrim */
#define  PML_LF_RC_TRIM(x)                                  (((x)&0x3u)<<22)              /**< Set PmlLFRCTrim in register */
#define  GET_PML_LF_RC_TRIM(reg)                            (((reg)>>22)&0x3u)            /**< Get PmlLFRCTrim from register */
#define  PML_BGR_P_TC_SHIFT                                 24                            /**< Shift for PmlBgrPTC */
#define  PML_BGR_P_TC_MASK                                  0x0F000000u                   /**< Mask for PmlBgrPTC */
#define  PML_BGR_P_TC_BMASK                                 0xFu                          /**< Base mask for PmlBgrPTC */
#define  PML_BGR_P_TC(x)                                    (((x)&0xFu)<<24)              /**< Set PmlBgrPTC in register */
#define  GET_PML_BGR_P_TC(reg)                              (((reg)>>24)&0xFu)            /**< Get PmlBgrPTC from register */
#define  PML_USB_TX_TRIM_SHIFT                              28                            /**< Shift for PmlUSBTXTrim */
#define  PML_USB_TX_TRIM_MASK                               0x30000000u                   /**< Mask for PmlUSBTXTrim */
#define  PML_USB_TX_TRIM_BMASK                              0x3u                          /**< Base mask for PmlUSBTXTrim */
#define  PML_USB_TX_TRIM(x)                                 (((x)&0x3u)<<28)              /**< Set PmlUSBTXTrim in register */
#define  GET_PML_USB_TX_TRIM(reg)                           (((reg)>>28)&0x3u)            /**< Get PmlUSBTXTrim from register */
/** @} */


/**
 * @name RegPmlRev
 * @{
 */
// RegPmlRev.r32
#define  REG_PML_REV_RESET_VALUE                            0x00000000u                   /**< Reset value of RegPmlRev */
#define  REG_PML_REV_MASK                                   0x00000FFFu                   /**< Mask for RegPmlRev */

#define  PML_DEV_REVISION_SHIFT                             8                             /**< Shift for PmlDevRevision */
#define  PML_DEV_REVISION_MASK                              0x00000F00u                   /**< Mask for PmlDevRevision */
#define  PML_DEV_REVISION_BMASK                             0xFu                          /**< Base mask for PmlDevRevision */
#define  PML_DEV_REVISION(x)                                (((x)&0xFu)<<8)               /**< Set PmlDevRevision in register */
#define  GET_PML_DEV_REVISION(reg)                          (((reg)>>8)&0xFu)             /**< Get PmlDevRevision from register */
#define  PML_MASK_REV_M4_SHIFT                              6                             /**< Shift for PmlMaskRevM4 */
#define  PML_MASK_REV_M4_MASK                               0x000000C0u                   /**< Mask for PmlMaskRevM4 */
#define  PML_MASK_REV_M4_BMASK                              0x3u                          /**< Base mask for PmlMaskRevM4 */
#define  PML_MASK_REV_M4(x)                                 (((x)&0x3u)<<6)               /**< Set PmlMaskRevM4 in register */
#define  GET_PML_MASK_REV_M4(reg)                           (((reg)>>6)&0x3u)             /**< Get PmlMaskRevM4 from register */
#define  PML_MASK_REV_M3_SHIFT                              4                             /**< Shift for PmlMaskRevM3 */
#define  PML_MASK_REV_M3_MASK                               0x00000030u                   /**< Mask for PmlMaskRevM3 */
#define  PML_MASK_REV_M3_BMASK                              0x3u                          /**< Base mask for PmlMaskRevM3 */
#define  PML_MASK_REV_M3(x)                                 (((x)&0x3u)<<4)               /**< Set PmlMaskRevM3 in register */
#define  GET_PML_MASK_REV_M3(reg)                           (((reg)>>4)&0x3u)             /**< Get PmlMaskRevM3 from register */
#define  PML_MASK_REV_M2_SHIFT                              2                             /**< Shift for PmlMaskRevM2 */
#define  PML_MASK_REV_M2_MASK                               0x0000000Cu                   /**< Mask for PmlMaskRevM2 */
#define  PML_MASK_REV_M2_BMASK                              0x3u                          /**< Base mask for PmlMaskRevM2 */
#define  PML_MASK_REV_M2(x)                                 (((x)&0x3u)<<2)               /**< Set PmlMaskRevM2 in register */
#define  GET_PML_MASK_REV_M2(reg)                           (((reg)>>2)&0x3u)             /**< Get PmlMaskRevM2 from register */
#define  PML_MASK_REV_M1_SHIFT                              0                             /**< Shift for PmlMaskRevM1 */
#define  PML_MASK_REV_M1_MASK                               0x00000003u                   /**< Mask for PmlMaskRevM1 */
#define  PML_MASK_REV_M1_BMASK                              0x3u                          /**< Base mask for PmlMaskRevM1 */
#define  PML_MASK_REV_M1(x)                                 (((x)&0x3u)<<0)               /**< Set PmlMaskRevM1 in register */
#define  GET_PML_MASK_REV_M1(reg)                           (((reg)>>0)&0x3u)             /**< Get PmlMaskRevM1 from register */
/** @} */


/**
 * @name RegPmlSysMode
 * @{
 */
// RegPmlSysMode.r32
#define  REG_PML_SYS_MODE_RESET_VALUE                       0x00000000u                   /**< Reset value of RegPmlSysMode */
#define  REG_PML_SYS_MODE_MASK                              0xFFFFFFFFu                   /**< Mask for RegPmlSysMode */

#define  PML_PAD_SYS_MODE_SHIFT                             0                             /**< Shift for PmlPadSysMode */
#define  PML_PAD_SYS_MODE_MASK                              0x00000FFFu                   /**< Mask for PmlPadSysMode */
#define  PML_PAD_SYS_MODE_BMASK                             0xFFFu                        /**< Base mask for PmlPadSysMode */
#define  PML_PAD_SYS_MODE(x)                                (((x)&0xFFFu)<<0)             /**< Set PmlPadSysMode in register */
#define  GET_PML_PAD_SYS_MODE(reg)                          (((reg)>>0)&0xFFFu)           /**< Get PmlPadSysMode from register */
#define  PML_SPARE_SHIFT                                    12                            /**< Shift for PmlSpare */
#define  PML_SPARE_MASK                                     0xFFFFF000u                   /**< Mask for PmlSpare */
#define  PML_SPARE_BMASK                                    0xFFFFFu                      /**< Base mask for PmlSpare */
#define  PML_SPARE(x)                                       (((x)&0xFFFFFu)<<12)          /**< Set PmlSpare in register */
#define  GET_PML_SPARE(reg)                                 (((reg)>>12)&0xFFFFFu)        /**< Get PmlSpare from register */
/** @} */


/**
 * @name RegPmlPadClk
 * @{
 */
// RegPmlPadClk.r32
#define  REG_PML_PAD_CLK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPmlPadClk */
#define  REG_PML_PAD_CLK_MASK                               0x00FFFFFFu                   /**< Mask for RegPmlPadClk */

#define  PML_SPARE_2_SHIFT                                  0                             /**< Shift for PmlSpare2 */
#define  PML_SPARE_2_MASK                                   0x000000FFu                   /**< Mask for PmlSpare2 */
#define  PML_SPARE_2_BMASK                                  0xFFu                         /**< Base mask for PmlSpare2 */
#define  PML_SPARE_2(x)                                     (((x)&0xFFu)<<0)              /**< Set PmlSpare2 in register */
#define  GET_PML_SPARE_2(reg)                               (((reg)>>0)&0xFFu)            /**< Get PmlSpare2 from register */
#define  PML_PAD_CLK_GPIO4_SHIFT                            8                             /**< Shift for PmlPadClkGPIO4 */
#define  PML_PAD_CLK_GPIO4_MASK                             0x00000300u                   /**< Mask for PmlPadClkGPIO4 */
#define  PML_PAD_CLK_GPIO4_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO4 */
#define  PML_PAD_CLK_GPIO4(x)                               (((x)&0x3u)<<8)               /**< Set PmlPadClkGPIO4 in register */
#define  GET_PML_PAD_CLK_GPIO4(reg)                         (((reg)>>8)&0x3u)             /**< Get PmlPadClkGPIO4 from register */
#define  PML_PAD_CLK_GPIO5_SHIFT                            10                            /**< Shift for PmlPadClkGPIO5 */
#define  PML_PAD_CLK_GPIO5_MASK                             0x00000C00u                   /**< Mask for PmlPadClkGPIO5 */
#define  PML_PAD_CLK_GPIO5_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO5 */
#define  PML_PAD_CLK_GPIO5(x)                               (((x)&0x3u)<<10)              /**< Set PmlPadClkGPIO5 in register */
#define  GET_PML_PAD_CLK_GPIO5(reg)                         (((reg)>>10)&0x3u)            /**< Get PmlPadClkGPIO5 from register */
#define  PML_PAD_CLK_GPIO6_SHIFT                            12                            /**< Shift for PmlPadClkGPIO6 */
#define  PML_PAD_CLK_GPIO6_MASK                             0x00003000u                   /**< Mask for PmlPadClkGPIO6 */
#define  PML_PAD_CLK_GPIO6_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO6 */
#define  PML_PAD_CLK_GPIO6(x)                               (((x)&0x3u)<<12)              /**< Set PmlPadClkGPIO6 in register */
#define  GET_PML_PAD_CLK_GPIO6(reg)                         (((reg)>>12)&0x3u)            /**< Get PmlPadClkGPIO6 from register */
#define  PML_PAD_CLK_GPIO7_SHIFT                            14                            /**< Shift for PmlPadClkGPIO7 */
#define  PML_PAD_CLK_GPIO7_MASK                             0x0000C000u                   /**< Mask for PmlPadClkGPIO7 */
#define  PML_PAD_CLK_GPIO7_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO7 */
#define  PML_PAD_CLK_GPIO7(x)                               (((x)&0x3u)<<14)              /**< Set PmlPadClkGPIO7 in register */
#define  GET_PML_PAD_CLK_GPIO7(reg)                         (((reg)>>14)&0x3u)            /**< Get PmlPadClkGPIO7 from register */
#define  PML_PAD_CLK_GPIO8_SHIFT                            16                            /**< Shift for PmlPadClkGPIO8 */
#define  PML_PAD_CLK_GPIO8_MASK                             0x00030000u                   /**< Mask for PmlPadClkGPIO8 */
#define  PML_PAD_CLK_GPIO8_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO8 */
#define  PML_PAD_CLK_GPIO8(x)                               (((x)&0x3u)<<16)              /**< Set PmlPadClkGPIO8 in register */
#define  GET_PML_PAD_CLK_GPIO8(reg)                         (((reg)>>16)&0x3u)            /**< Get PmlPadClkGPIO8 from register */
#define  PML_PAD_CLK_GPIO9_SHIFT                            18                            /**< Shift for PmlPadClkGPIO9 */
#define  PML_PAD_CLK_GPIO9_MASK                             0x000C0000u                   /**< Mask for PmlPadClkGPIO9 */
#define  PML_PAD_CLK_GPIO9_BMASK                            0x3u                          /**< Base mask for PmlPadClkGPIO9 */
#define  PML_PAD_CLK_GPIO9(x)                               (((x)&0x3u)<<18)              /**< Set PmlPadClkGPIO9 in register */
#define  GET_PML_PAD_CLK_GPIO9(reg)                         (((reg)>>18)&0x3u)            /**< Get PmlPadClkGPIO9 from register */
#define  PML_PAD_CLK_GPIO10_SHIFT                           20                            /**< Shift for PmlPadClkGPIO10 */
#define  PML_PAD_CLK_GPIO10_MASK                            0x00300000u                   /**< Mask for PmlPadClkGPIO10 */
#define  PML_PAD_CLK_GPIO10_BMASK                           0x3u                          /**< Base mask for PmlPadClkGPIO10 */
#define  PML_PAD_CLK_GPIO10(x)                              (((x)&0x3u)<<20)              /**< Set PmlPadClkGPIO10 in register */
#define  GET_PML_PAD_CLK_GPIO10(reg)                        (((reg)>>20)&0x3u)            /**< Get PmlPadClkGPIO10 from register */
#define  PML_PAD_CLK_GPIO11_SHIFT                           22                            /**< Shift for PmlPadClkGPIO11 */
#define  PML_PAD_CLK_GPIO11_MASK                            0x00C00000u                   /**< Mask for PmlPadClkGPIO11 */
#define  PML_PAD_CLK_GPIO11_BMASK                           0x3u                          /**< Base mask for PmlPadClkGPIO11 */
#define  PML_PAD_CLK_GPIO11(x)                              (((x)&0x3u)<<22)              /**< Set PmlPadClkGPIO11 in register */
#define  GET_PML_PAD_CLK_GPIO11(reg)                        (((reg)>>22)&0x3u)            /**< Get PmlPadClkGPIO11 from register */
/** @} */


/**
 * @name RegGPIOCfgDeb
 * @{
 */
// RegGPIOCfgDeb.r32
#define  REG_GPIO_CFG_DEB_RESET_VALUE                       0x00000000u                   /**< Reset value of RegGPIOCfgDeb */
#define  REG_GPIO_CFG_DEB_MASK                              0x00070FFFu                   /**< Mask for RegGPIOCfgDeb */

#define  GPIO_DEB_EN_SHIFT                                  0                             /**< Shift for GPIODebEn */
#define  GPIO_DEB_EN_MASK                                   0x00000FFFu                   /**< Mask for GPIODebEn */
#define  GPIO_DEB_EN_BMASK                                  0xFFFu                        /**< Base mask for GPIODebEn */
#define  GPIO_DEB_EN(x)                                     (((x)&0xFFFu)<<0)             /**< Set GPIODebEn in register */
#define  GET_GPIO_DEB_EN(reg)                               (((reg)>>0)&0xFFFu)           /**< Get GPIODebEn from register */
#define  GPIO_DEB_CLOCK_SHIFT                               16                            /**< Shift for GPIODebClock */
#define  GPIO_DEB_CLOCK_MASK                                0x00070000u                   /**< Mask for GPIODebClock */
#define  GPIO_DEB_CLOCK_BMASK                               0x7u                          /**< Base mask for GPIODebClock */
#define  GPIO_DEB_CLOCK(x)                                  (((x)&0x7u)<<16)              /**< Set GPIODebClock in register */
#define  GET_GPIO_DEB_CLOCK(reg)                            (((reg)>>16)&0x7u)            /**< Get GPIODebClock from register */

// RegGPIOCfgDeb.regs.GPIODebEn
#define  GPIO_DEB_EN_GSHIFT                                 0                             /**< Shift for group GPIODebEn */
#define  GPIO_DEB_EN_GSIZE                                  16                            /**< Size of group GPIODebEn */
#define  GPIO_DEB_EN_GMASK                                  0x0000FFFFu                   /**< Mask for group GPIODebEn */

#define  GPIO_DEB_EN_RSHIFT                                 0                             /**< Shift for GPIODebEn */
#define  GPIO_DEB_EN_RMASK                                  0x00000FFFu                   /**< Mask for GPIODebEn */
#define  GPIO_DEB_EN_RBMASK                                 0xFFFu                        /**< Base mask for GPIODebEn */
#define  GPIO_DEB_EN_R(x)                                   (((x)&0xFFFu)<<0)             /**< Set GPIODebEn in register */
#define  GET_GPIO_DEB_EN_R(reg)                             (((reg)>>0)&0xFFFu)           /**< Get GPIODebEn from register */

// RegGPIOCfgDeb.regs.GPIODebClock
#define  GPIO_DEB_CLOCK_GSHIFT                              16                            /**< Shift for group GPIODebClock */
#define  GPIO_DEB_CLOCK_GSIZE                               16                            /**< Size of group GPIODebClock */
#define  GPIO_DEB_CLOCK_GMASK                               0xFFFF0000u                   /**< Mask for group GPIODebClock */

#define  GPIO_DEB_CLOCK_RSHIFT                              0                             /**< Shift for GPIODebClock */
#define  GPIO_DEB_CLOCK_RMASK                               0x00000007u                   /**< Mask for GPIODebClock */
#define  GPIO_DEB_CLOCK_RBMASK                              0x7u                          /**< Base mask for GPIODebClock */
#define  GPIO_DEB_CLOCK_R(x)                                (((x)&0x7u)<<0)               /**< Set GPIODebClock in register */
#define  GET_GPIO_DEB_CLOCK_R(reg)                          (((reg)>>0)&0x7u)             /**< Get GPIODebClock from register */
/** @} */


/**
 * @name RegTstEn
 * @{
 */
// RegTstEn.r32
#define  REG_TST_EN_RESET_VALUE                             0x00000000u                   /**< Reset value of RegTstEn */
#define  REG_TST_EN_MASK                                    0xFFFFFFFFu                   /**< Mask for RegTstEn */

#define  TST_EN_SHIFT                                       0                             /**< Shift for TstEn */
#define  TST_EN_MASK                                        0xFFFFFFFFu                   /**< Mask for TstEn */
#define  TST_EN_BMASK                                       0xFFFFFFFFu                   /**< Base mask for TstEn */
#define  TST_EN(x)                                          (((x)&0xFFFFFFFFu)<<0)        /**< Set TstEn in register */
#define  GET_TST_EN(reg)                                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get TstEn from register */
/** @} */


/**
 * @name RegTstScanEn
 * @{
 */
// RegTstScanEn.r32
#define  REG_TST_SCAN_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegTstScanEn */
#define  REG_TST_SCAN_EN_MASK                               0xFFFFFFFFu                   /**< Mask for RegTstScanEn */

#define  TST_SCAN_EN_SHIFT                                  0                             /**< Shift for TstScanEn */
#define  TST_SCAN_EN_MASK                                   0xFFFFFFFFu                   /**< Mask for TstScanEn */
#define  TST_SCAN_EN_BMASK                                  0xFFFFFFFFu                   /**< Base mask for TstScanEn */
#define  TST_SCAN_EN(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set TstScanEn in register */
#define  GET_TST_SCAN_EN(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get TstScanEn from register */
/** @} */


/**
 * @name RegTstPadMode
 * @{
 */
// RegTstPadMode.r32
#define  REG_TST_PAD_MODE_RESET_VALUE                       0x00000000u                   /**< Reset value of RegTstPadMode */
#define  REG_TST_PAD_MODE_MASK                              0x00FFFFFFu                   /**< Mask for RegTstPadMode */

#define  TST_GPIO0_MODE_SHIFT                               0                             /**< Shift for TstGPIO0Mode */
#define  TST_GPIO0_MODE_MASK                                0x00000003u                   /**< Mask for TstGPIO0Mode */
#define  TST_GPIO0_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO0Mode */
#define  TST_GPIO0_MODE(x)                                  (((x)&0x3u)<<0)               /**< Set TstGPIO0Mode in register */
#define  GET_TST_GPIO0_MODE(reg)                            (((reg)>>0)&0x3u)             /**< Get TstGPIO0Mode from register */
#define  TST_GPIO1_MODE_SHIFT                               2                             /**< Shift for TstGPIO1Mode */
#define  TST_GPIO1_MODE_MASK                                0x0000000Cu                   /**< Mask for TstGPIO1Mode */
#define  TST_GPIO1_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO1Mode */
#define  TST_GPIO1_MODE(x)                                  (((x)&0x3u)<<2)               /**< Set TstGPIO1Mode in register */
#define  GET_TST_GPIO1_MODE(reg)                            (((reg)>>2)&0x3u)             /**< Get TstGPIO1Mode from register */
#define  TST_GPIO2_MODE_SHIFT                               4                             /**< Shift for TstGPIO2Mode */
#define  TST_GPIO2_MODE_MASK                                0x00000030u                   /**< Mask for TstGPIO2Mode */
#define  TST_GPIO2_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO2Mode */
#define  TST_GPIO2_MODE(x)                                  (((x)&0x3u)<<4)               /**< Set TstGPIO2Mode in register */
#define  GET_TST_GPIO2_MODE(reg)                            (((reg)>>4)&0x3u)             /**< Get TstGPIO2Mode from register */
#define  TST_GPIO3_MODE_SHIFT                               6                             /**< Shift for TstGPIO3Mode */
#define  TST_GPIO3_MODE_MASK                                0x000000C0u                   /**< Mask for TstGPIO3Mode */
#define  TST_GPIO3_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO3Mode */
#define  TST_GPIO3_MODE(x)                                  (((x)&0x3u)<<6)               /**< Set TstGPIO3Mode in register */
#define  GET_TST_GPIO3_MODE(reg)                            (((reg)>>6)&0x3u)             /**< Get TstGPIO3Mode from register */
#define  TST_GPIO4_MODE_SHIFT                               8                             /**< Shift for TstGPIO4Mode */
#define  TST_GPIO4_MODE_MASK                                0x00000300u                   /**< Mask for TstGPIO4Mode */
#define  TST_GPIO4_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO4Mode */
#define  TST_GPIO4_MODE(x)                                  (((x)&0x3u)<<8)               /**< Set TstGPIO4Mode in register */
#define  GET_TST_GPIO4_MODE(reg)                            (((reg)>>8)&0x3u)             /**< Get TstGPIO4Mode from register */
#define  TST_GPIO5_MODE_SHIFT                               10                            /**< Shift for TstGPIO5Mode */
#define  TST_GPIO5_MODE_MASK                                0x00000C00u                   /**< Mask for TstGPIO5Mode */
#define  TST_GPIO5_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO5Mode */
#define  TST_GPIO5_MODE(x)                                  (((x)&0x3u)<<10)              /**< Set TstGPIO5Mode in register */
#define  GET_TST_GPIO5_MODE(reg)                            (((reg)>>10)&0x3u)            /**< Get TstGPIO5Mode from register */
#define  TST_GPIO6_MODE_SHIFT                               12                            /**< Shift for TstGPIO6Mode */
#define  TST_GPIO6_MODE_MASK                                0x00003000u                   /**< Mask for TstGPIO6Mode */
#define  TST_GPIO6_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO6Mode */
#define  TST_GPIO6_MODE(x)                                  (((x)&0x3u)<<12)              /**< Set TstGPIO6Mode in register */
#define  GET_TST_GPIO6_MODE(reg)                            (((reg)>>12)&0x3u)            /**< Get TstGPIO6Mode from register */
#define  TST_GPIO7_MODE_SHIFT                               14                            /**< Shift for TstGPIO7Mode */
#define  TST_GPIO7_MODE_MASK                                0x0000C000u                   /**< Mask for TstGPIO7Mode */
#define  TST_GPIO7_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO7Mode */
#define  TST_GPIO7_MODE(x)                                  (((x)&0x3u)<<14)              /**< Set TstGPIO7Mode in register */
#define  GET_TST_GPIO7_MODE(reg)                            (((reg)>>14)&0x3u)            /**< Get TstGPIO7Mode from register */
#define  TST_GPIO8_MODE_SHIFT                               16                            /**< Shift for TstGPIO8Mode */
#define  TST_GPIO8_MODE_MASK                                0x00030000u                   /**< Mask for TstGPIO8Mode */
#define  TST_GPIO8_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO8Mode */
#define  TST_GPIO8_MODE(x)                                  (((x)&0x3u)<<16)              /**< Set TstGPIO8Mode in register */
#define  GET_TST_GPIO8_MODE(reg)                            (((reg)>>16)&0x3u)            /**< Get TstGPIO8Mode from register */
#define  TST_GPIO9_MODE_SHIFT                               18                            /**< Shift for TstGPIO9Mode */
#define  TST_GPIO9_MODE_MASK                                0x000C0000u                   /**< Mask for TstGPIO9Mode */
#define  TST_GPIO9_MODE_BMASK                               0x3u                          /**< Base mask for TstGPIO9Mode */
#define  TST_GPIO9_MODE(x)                                  (((x)&0x3u)<<18)              /**< Set TstGPIO9Mode in register */
#define  GET_TST_GPIO9_MODE(reg)                            (((reg)>>18)&0x3u)            /**< Get TstGPIO9Mode from register */
#define  TST_GPIO10_MODE_SHIFT                              20                            /**< Shift for TstGPIO10Mode */
#define  TST_GPIO10_MODE_MASK                               0x00300000u                   /**< Mask for TstGPIO10Mode */
#define  TST_GPIO10_MODE_BMASK                              0x3u                          /**< Base mask for TstGPIO10Mode */
#define  TST_GPIO10_MODE(x)                                 (((x)&0x3u)<<20)              /**< Set TstGPIO10Mode in register */
#define  GET_TST_GPIO10_MODE(reg)                           (((reg)>>20)&0x3u)            /**< Get TstGPIO10Mode from register */
#define  TST_GPIO11_MODE_SHIFT                              22                            /**< Shift for TstGPIO11Mode */
#define  TST_GPIO11_MODE_MASK                               0x00C00000u                   /**< Mask for TstGPIO11Mode */
#define  TST_GPIO11_MODE_BMASK                              0x3u                          /**< Base mask for TstGPIO11Mode */
#define  TST_GPIO11_MODE(x)                                 (((x)&0x3u)<<22)              /**< Set TstGPIO11Mode in register */
#define  GET_TST_GPIO11_MODE(reg)                           (((reg)>>22)&0x3u)            /**< Get TstGPIO11Mode from register */
/** @} */


/**
 * @name RegTstPadLoop
 * @{
 */
// RegTstPadLoop.r32
#define  REG_TST_PAD_LOOP_RESET_VALUE                       0x00000000u                   /**< Reset value of RegTstPadLoop */
#define  REG_TST_PAD_LOOP_MASK                              0x00000001u                   /**< Mask for RegTstPadLoop */

#define  TST_PAD_INP_SHIFT                                  0                             /**< Shift for TstPadInp */
#define  TST_PAD_INP_MASK                                   0x00000001u                   /**< Mask for TstPadInp */
#define  TST_PAD_INP_BMASK                                  0x1u                          /**< Base mask for TstPadInp */
#define  TST_PAD_INP(x)                                     (((x)&0x1u)<<0)               /**< Set TstPadInp in register */
#define  GET_TST_PAD_INP(reg)                               (((reg)>>0)&0x1u)             /**< Get TstPadInp from register */
/** @} */


/**
 * @name RegTstCtrl
 * @{
 */
// RegTstCtrl.r32
#define  REG_TST_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegTstCtrl */
#define  REG_TST_CTRL_MASK                                  0x010F7F3Fu                   /**< Mask for RegTstCtrl */

#define  TST_GPIO4_OUT_SHIFT                                0                             /**< Shift for TstGPIO4Out */
#define  TST_GPIO4_OUT_MASK                                 0x00000007u                   /**< Mask for TstGPIO4Out */
#define  TST_GPIO4_OUT_BMASK                                0x7u                          /**< Base mask for TstGPIO4Out */
#define  TST_GPIO4_OUT(x)                                   (((x)&0x7u)<<0)               /**< Set TstGPIO4Out in register */
#define  GET_TST_GPIO4_OUT(reg)                             (((reg)>>0)&0x7u)             /**< Get TstGPIO4Out from register */
#define  TST_GPIO5_OUT_SHIFT                                3                             /**< Shift for TstGPIO5Out */
#define  TST_GPIO5_OUT_MASK                                 0x00000038u                   /**< Mask for TstGPIO5Out */
#define  TST_GPIO5_OUT_BMASK                                0x7u                          /**< Base mask for TstGPIO5Out */
#define  TST_GPIO5_OUT(x)                                   (((x)&0x7u)<<3)               /**< Set TstGPIO5Out in register */
#define  GET_TST_GPIO5_OUT(reg)                             (((reg)>>3)&0x7u)             /**< Get TstGPIO5Out from register */
#define  TST_DIS_PWRCHK_SHIFT                               8                             /**< Shift for TstDisPwrchk */
#define  TST_DIS_PWRCHK_MASK                                0x00000100u                   /**< Mask for TstDisPwrchk */
#define  TST_DIS_PWRCHK_BMASK                               0x1u                          /**< Base mask for TstDisPwrchk */
#define  TST_DIS_PWRCHK(x)                                  (((x)&0x1u)<<8)               /**< Set TstDisPwrchk in register */
#define  GET_TST_DIS_PWRCHK(reg)                            (((reg)>>8)&0x1u)             /**< Get TstDisPwrchk from register */
#define  TST_EXT_DCDC_SHIFT                                 9                             /**< Shift for TstExtDCDC */
#define  TST_EXT_DCDC_MASK                                  0x00000200u                   /**< Mask for TstExtDCDC */
#define  TST_EXT_DCDC_BMASK                                 0x1u                          /**< Base mask for TstExtDCDC */
#define  TST_EXT_DCDC(x)                                    (((x)&0x1u)<<9)               /**< Set TstExtDCDC in register */
#define  GET_TST_EXT_DCDC(reg)                              (((reg)>>9)&0x1u)             /**< Get TstExtDCDC from register */
#define  TST_AUTOMODE_SHIFT                                 10                            /**< Shift for TstAutomode */
#define  TST_AUTOMODE_MASK                                  0x00000400u                   /**< Mask for TstAutomode */
#define  TST_AUTOMODE_BMASK                                 0x1u                          /**< Base mask for TstAutomode */
#define  TST_AUTOMODE(x)                                    (((x)&0x1u)<<10)              /**< Set TstAutomode in register */
#define  GET_TST_AUTOMODE(reg)                              (((reg)>>10)&0x1u)            /**< Get TstAutomode from register */
#define  TST_GPIO_INP_SHIFT                                 11                            /**< Shift for TstGPIOInp */
#define  TST_GPIO_INP_MASK                                  0x00000800u                   /**< Mask for TstGPIOInp */
#define  TST_GPIO_INP_BMASK                                 0x1u                          /**< Base mask for TstGPIOInp */
#define  TST_GPIO_INP(x)                                    (((x)&0x1u)<<11)              /**< Set TstGPIOInp in register */
#define  GET_TST_GPIO_INP(reg)                              (((reg)>>11)&0x1u)            /**< Get TstGPIOInp from register */
#define  TST_GPIO5_ANA_BUF_SHIFT                            12                            /**< Shift for TstGPIO5AnaBuf */
#define  TST_GPIO5_ANA_BUF_MASK                             0x00001000u                   /**< Mask for TstGPIO5AnaBuf */
#define  TST_GPIO5_ANA_BUF_BMASK                            0x1u                          /**< Base mask for TstGPIO5AnaBuf */
#define  TST_GPIO5_ANA_BUF(x)                               (((x)&0x1u)<<12)              /**< Set TstGPIO5AnaBuf in register */
#define  GET_TST_GPIO5_ANA_BUF(reg)                         (((reg)>>12)&0x1u)            /**< Get TstGPIO5AnaBuf from register */
#define  TST_EXT_LF_RC_SHIFT                                13                            /**< Shift for TstExtLFRC */
#define  TST_EXT_LF_RC_MASK                                 0x00002000u                   /**< Mask for TstExtLFRC */
#define  TST_EXT_LF_RC_BMASK                                0x1u                          /**< Base mask for TstExtLFRC */
#define  TST_EXT_LF_RC(x)                                   (((x)&0x1u)<<13)              /**< Set TstExtLFRC in register */
#define  GET_TST_EXT_LF_RC(reg)                             (((reg)>>13)&0x1u)            /**< Get TstExtLFRC from register */
#define  TST_EXT_HF_RC_SHIFT                                14                            /**< Shift for TstExtHFRC */
#define  TST_EXT_HF_RC_MASK                                 0x00004000u                   /**< Mask for TstExtHFRC */
#define  TST_EXT_HF_RC_BMASK                                0x1u                          /**< Base mask for TstExtHFRC */
#define  TST_EXT_HF_RC(x)                                   (((x)&0x1u)<<14)              /**< Set TstExtHFRC in register */
#define  GET_TST_EXT_HF_RC(reg)                             (((reg)>>14)&0x1u)            /**< Get TstExtHFRC from register */
#define  TST_DCDC_BUCK_SHIFT                                16                            /**< Shift for TstDCDCBuck */
#define  TST_DCDC_BUCK_MASK                                 0x00010000u                   /**< Mask for TstDCDCBuck */
#define  TST_DCDC_BUCK_BMASK                                0x1u                          /**< Base mask for TstDCDCBuck */
#define  TST_DCDC_BUCK(x)                                   (((x)&0x1u)<<16)              /**< Set TstDCDCBuck in register */
#define  GET_TST_DCDC_BUCK(reg)                             (((reg)>>16)&0x1u)            /**< Get TstDCDCBuck from register */
#define  TST_DCDC_BOOST_SHIFT                               17                            /**< Shift for TstDCDCBoost */
#define  TST_DCDC_BOOST_MASK                                0x00020000u                   /**< Mask for TstDCDCBoost */
#define  TST_DCDC_BOOST_BMASK                               0x1u                          /**< Base mask for TstDCDCBoost */
#define  TST_DCDC_BOOST(x)                                  (((x)&0x1u)<<17)              /**< Set TstDCDCBoost in register */
#define  GET_TST_DCDC_BOOST(reg)                            (((reg)>>17)&0x1u)            /**< Get TstDCDCBoost from register */
#define  TST_DCDC_S1_SHIFT                                  18                            /**< Shift for TstDCDCS1 */
#define  TST_DCDC_S1_MASK                                   0x00040000u                   /**< Mask for TstDCDCS1 */
#define  TST_DCDC_S1_BMASK                                  0x1u                          /**< Base mask for TstDCDCS1 */
#define  TST_DCDC_S1(x)                                     (((x)&0x1u)<<18)              /**< Set TstDCDCS1 in register */
#define  GET_TST_DCDC_S1(reg)                               (((reg)>>18)&0x1u)            /**< Get TstDCDCS1 from register */
#define  TST_DCDC_S2_SHIFT                                  19                            /**< Shift for TstDCDCS2 */
#define  TST_DCDC_S2_MASK                                   0x00080000u                   /**< Mask for TstDCDCS2 */
#define  TST_DCDC_S2_BMASK                                  0x1u                          /**< Base mask for TstDCDCS2 */
#define  TST_DCDC_S2(x)                                     (((x)&0x1u)<<19)              /**< Set TstDCDCS2 in register */
#define  GET_TST_DCDC_S2(reg)                               (((reg)>>19)&0x1u)            /**< Get TstDCDCS2 from register */
#define  TST_LDO_DIG_HVT_SHIFT                              24                            /**< Shift for TstLdoDigHvt */
#define  TST_LDO_DIG_HVT_MASK                               0x01000000u                   /**< Mask for TstLdoDigHvt */
#define  TST_LDO_DIG_HVT_BMASK                              0x1u                          /**< Base mask for TstLdoDigHvt */
#define  TST_LDO_DIG_HVT(x)                                 (((x)&0x1u)<<24)              /**< Set TstLdoDigHvt in register */
#define  GET_TST_LDO_DIG_HVT(reg)                           (((reg)>>24)&0x1u)            /**< Get TstLdoDigHvt from register */
/** @} */


/**
 * @name RegTstAna
 * @{
 */
// RegTstAna.r32
#define  REG_TST_ANA_RESET_VALUE                            0x00000000u                   /**< Reset value of RegTstAna */
#define  REG_TST_ANA_MASK                                   0x00037F01u                   /**< Mask for RegTstAna */

#define  TST_ANA_CTRL_EN_SHIFT                              0                             /**< Shift for TstAnaCtrlEn */
#define  TST_ANA_CTRL_EN_MASK                               0x00000001u                   /**< Mask for TstAnaCtrlEn */
#define  TST_ANA_CTRL_EN_BMASK                              0x1u                          /**< Base mask for TstAnaCtrlEn */
#define  TST_ANA_CTRL_EN(x)                                 (((x)&0x1u)<<0)               /**< Set TstAnaCtrlEn in register */
#define  GET_TST_ANA_CTRL_EN(reg)                           (((reg)>>0)&0x1u)             /**< Get TstAnaCtrlEn from register */
#define  TST_HF_RC_EN_SHIFT                                 8                             /**< Shift for TstHFRCEn */
#define  TST_HF_RC_EN_MASK                                  0x00000100u                   /**< Mask for TstHFRCEn */
#define  TST_HF_RC_EN_BMASK                                 0x1u                          /**< Base mask for TstHFRCEn */
#define  TST_HF_RC_EN(x)                                    (((x)&0x1u)<<8)               /**< Set TstHFRCEn in register */
#define  GET_TST_HF_RC_EN(reg)                              (((reg)>>8)&0x1u)             /**< Get TstHFRCEn from register */
#define  TST_HF_XTAL_EN_SHIFT                               9                             /**< Shift for TstHFXTALEn */
#define  TST_HF_XTAL_EN_MASK                                0x00000200u                   /**< Mask for TstHFXTALEn */
#define  TST_HF_XTAL_EN_BMASK                               0x1u                          /**< Base mask for TstHFXTALEn */
#define  TST_HF_XTAL_EN(x)                                  (((x)&0x1u)<<9)               /**< Set TstHFXTALEn in register */
#define  GET_TST_HF_XTAL_EN(reg)                            (((reg)>>9)&0x1u)             /**< Get TstHFXTALEn from register */
#define  TST_BGRP_EN_SHIFT                                  10                            /**< Shift for TstBGRPEn */
#define  TST_BGRP_EN_MASK                                   0x00000400u                   /**< Mask for TstBGRPEn */
#define  TST_BGRP_EN_BMASK                                  0x1u                          /**< Base mask for TstBGRPEn */
#define  TST_BGRP_EN(x)                                     (((x)&0x1u)<<10)              /**< Set TstBGRPEn in register */
#define  GET_TST_BGRP_EN(reg)                               (((reg)>>10)&0x1u)            /**< Get TstBGRPEn from register */
#define  TST_SVLD_EN_SHIFT                                  11                            /**< Shift for TstSVLDEn */
#define  TST_SVLD_EN_MASK                                   0x00000800u                   /**< Mask for TstSVLDEn */
#define  TST_SVLD_EN_BMASK                                  0x1u                          /**< Base mask for TstSVLDEn */
#define  TST_SVLD_EN(x)                                     (((x)&0x1u)<<11)              /**< Set TstSVLDEn in register */
#define  GET_TST_SVLD_EN(reg)                               (((reg)>>11)&0x1u)            /**< Get TstSVLDEn from register */
#define  TST_SW_VCC_EN_SHIFT                                12                            /**< Shift for TstSwVCCEn */
#define  TST_SW_VCC_EN_MASK                                 0x00001000u                   /**< Mask for TstSwVCCEn */
#define  TST_SW_VCC_EN_BMASK                                0x1u                          /**< Base mask for TstSwVCCEn */
#define  TST_SW_VCC_EN(x)                                   (((x)&0x1u)<<12)              /**< Set TstSwVCCEn in register */
#define  GET_TST_SW_VCC_EN(reg)                             (((reg)>>12)&0x1u)            /**< Get TstSwVCCEn from register */
#define  TST_LDO_VCC_EN_SHIFT                               13                            /**< Shift for TstLDOVCCEn */
#define  TST_LDO_VCC_EN_MASK                                0x00002000u                   /**< Mask for TstLDOVCCEn */
#define  TST_LDO_VCC_EN_BMASK                               0x1u                          /**< Base mask for TstLDOVCCEn */
#define  TST_LDO_VCC_EN(x)                                  (((x)&0x1u)<<13)              /**< Set TstLDOVCCEn in register */
#define  GET_TST_LDO_VCC_EN(reg)                            (((reg)>>13)&0x1u)            /**< Get TstLDOVCCEn from register */
#define  TST_LDO_DIG_EN_SHIFT                               14                            /**< Shift for TstLDODigEn */
#define  TST_LDO_DIG_EN_MASK                                0x00004000u                   /**< Mask for TstLDODigEn */
#define  TST_LDO_DIG_EN_BMASK                               0x1u                          /**< Base mask for TstLDODigEn */
#define  TST_LDO_DIG_EN(x)                                  (((x)&0x1u)<<14)              /**< Set TstLDODigEn in register */
#define  GET_TST_LDO_DIG_EN(reg)                            (((reg)>>14)&0x1u)            /**< Get TstLDODigEn from register */
#define  TST_LF_RC_EN_SHIFT                                 16                            /**< Shift for TstLFRCEn */
#define  TST_LF_RC_EN_MASK                                  0x00010000u                   /**< Mask for TstLFRCEn */
#define  TST_LF_RC_EN_BMASK                                 0x1u                          /**< Base mask for TstLFRCEn */
#define  TST_LF_RC_EN(x)                                    (((x)&0x1u)<<16)              /**< Set TstLFRCEn in register */
#define  GET_TST_LF_RC_EN(reg)                              (((reg)>>16)&0x1u)            /**< Get TstLFRCEn from register */
#define  TST_SVLD_LP_SHIFT                                  17                            /**< Shift for TstSVLDLP */
#define  TST_SVLD_LP_MASK                                   0x00020000u                   /**< Mask for TstSVLDLP */
#define  TST_SVLD_LP_BMASK                                  0x1u                          /**< Base mask for TstSVLDLP */
#define  TST_SVLD_LP(x)                                     (((x)&0x1u)<<17)              /**< Set TstSVLDLP in register */
#define  GET_TST_SVLD_LP(reg)                               (((reg)>>17)&0x1u)            /**< Get TstSVLDLP from register */
/** @} */


/**
 * @name RegTstBus
 * @{
 */
// RegTstBus.r32
#define  REG_TST_BUS_RESET_VALUE                            0x00000000u                   /**< Reset value of RegTstBus */
#define  REG_TST_BUS_MASK                                   0x3F070307u                   /**< Mask for RegTstBus */

#define  TST_SVLD_OUT_SHIFT                                 0                             /**< Shift for TstSVLDOut */
#define  TST_SVLD_OUT_MASK                                  0x00000001u                   /**< Mask for TstSVLDOut */
#define  TST_SVLD_OUT_BMASK                                 0x1u                          /**< Base mask for TstSVLDOut */
#define  TST_SVLD_OUT(x)                                    (((x)&0x1u)<<0)               /**< Set TstSVLDOut in register */
#define  GET_TST_SVLD_OUT(reg)                              (((reg)>>0)&0x1u)             /**< Get TstSVLDOut from register */
#define  TST_BGR_P_OUT_SHIFT                                1                             /**< Shift for TstBgrPOut */
#define  TST_BGR_P_OUT_MASK                                 0x00000002u                   /**< Mask for TstBgrPOut */
#define  TST_BGR_P_OUT_BMASK                                0x1u                          /**< Base mask for TstBgrPOut */
#define  TST_BGR_P_OUT(x)                                   (((x)&0x1u)<<1)               /**< Set TstBgrPOut in register */
#define  GET_TST_BGR_P_OUT(reg)                             (((reg)>>1)&0x1u)             /**< Get TstBgrPOut from register */
#define  TST_LDO_SLP_OUT_SHIFT                              2                             /**< Shift for TstLDOSlpOut */
#define  TST_LDO_SLP_OUT_MASK                               0x00000004u                   /**< Mask for TstLDOSlpOut */
#define  TST_LDO_SLP_OUT_BMASK                              0x1u                          /**< Base mask for TstLDOSlpOut */
#define  TST_LDO_SLP_OUT(x)                                 (((x)&0x1u)<<2)               /**< Set TstLDOSlpOut in register */
#define  GET_TST_LDO_SLP_OUT(reg)                           (((reg)>>2)&0x1u)             /**< Get TstLDOSlpOut from register */
#define  TST_VBAT_PTAT_OUT_SHIFT                            8                             /**< Shift for TstVBATPTATOut */
#define  TST_VBAT_PTAT_OUT_MASK                             0x00000100u                   /**< Mask for TstVBATPTATOut */
#define  TST_VBAT_PTAT_OUT_BMASK                            0x1u                          /**< Base mask for TstVBATPTATOut */
#define  TST_VBAT_PTAT_OUT(x)                               (((x)&0x1u)<<8)               /**< Set TstVBATPTATOut in register */
#define  GET_TST_VBAT_PTAT_OUT(reg)                         (((reg)>>8)&0x1u)             /**< Get TstVBATPTATOut from register */
#define  TST_LDO_DIG_OUT_SHIFT                              9                             /**< Shift for TstLDODigOut */
#define  TST_LDO_DIG_OUT_MASK                               0x00000200u                   /**< Mask for TstLDODigOut */
#define  TST_LDO_DIG_OUT_BMASK                              0x1u                          /**< Base mask for TstLDODigOut */
#define  TST_LDO_DIG_OUT(x)                                 (((x)&0x1u)<<9)               /**< Set TstLDODigOut in register */
#define  GET_TST_LDO_DIG_OUT(reg)                           (((reg)>>9)&0x1u)             /**< Get TstLDODigOut from register */
#define  TST_ADC_SAR_0_OUT_SHIFT                            16                            /**< Shift for TstADCSAR0Out */
#define  TST_ADC_SAR_0_OUT_MASK                             0x00010000u                   /**< Mask for TstADCSAR0Out */
#define  TST_ADC_SAR_0_OUT_BMASK                            0x1u                          /**< Base mask for TstADCSAR0Out */
#define  TST_ADC_SAR_0_OUT(x)                               (((x)&0x1u)<<16)              /**< Set TstADCSAR0Out in register */
#define  GET_TST_ADC_SAR_0_OUT(reg)                         (((reg)>>16)&0x1u)            /**< Get TstADCSAR0Out from register */
#define  TST_ADC_SAR_1_OUT_SHIFT                            17                            /**< Shift for TstADCSAR1Out */
#define  TST_ADC_SAR_1_OUT_MASK                             0x00020000u                   /**< Mask for TstADCSAR1Out */
#define  TST_ADC_SAR_1_OUT_BMASK                            0x1u                          /**< Base mask for TstADCSAR1Out */
#define  TST_ADC_SAR_1_OUT(x)                               (((x)&0x1u)<<17)              /**< Set TstADCSAR1Out in register */
#define  GET_TST_ADC_SAR_1_OUT(reg)                         (((reg)>>17)&0x1u)            /**< Get TstADCSAR1Out from register */
#define  TST_RF_OUT_SHIFT                                   18                            /**< Shift for TstRfOut */
#define  TST_RF_OUT_MASK                                    0x00040000u                   /**< Mask for TstRfOut */
#define  TST_RF_OUT_BMASK                                   0x1u                          /**< Base mask for TstRfOut */
#define  TST_RF_OUT(x)                                      (((x)&0x1u)<<18)              /**< Set TstRfOut in register */
#define  GET_TST_RF_OUT(reg)                                (((reg)>>18)&0x1u)            /**< Get TstRfOut from register */
#define  TST_NVM_OUT_SHIFT                                  24                            /**< Shift for TstNvmOut */
#define  TST_NVM_OUT_MASK                                   0x0F000000u                   /**< Mask for TstNvmOut */
#define  TST_NVM_OUT_BMASK                                  0xFu                          /**< Base mask for TstNvmOut */
#define  TST_NVM_OUT(x)                                     (((x)&0xFu)<<24)              /**< Set TstNvmOut in register */
#define  GET_TST_NVM_OUT(reg)                               (((reg)>>24)&0xFu)            /**< Get TstNvmOut from register */
#define  TST_USB_TM_SHIFT                                   28                            /**< Shift for TstUsbTm */
#define  TST_USB_TM_MASK                                    0x30000000u                   /**< Mask for TstUsbTm */
#define  TST_USB_TM_BMASK                                   0x3u                          /**< Base mask for TstUsbTm */
#define  TST_USB_TM(x)                                      (((x)&0x3u)<<28)              /**< Set TstUsbTm in register */
#define  GET_TST_USB_TM(reg)                                (((reg)>>28)&0x3u)            /**< Get TstUsbTm from register */
/** @} */


/**
 * @name RegSleepTimCtrl
 * @{
 */
// RegSleepTimCtrl.r32
#define  REG_SLEEP_TIM_CTRL_RESET_VALUE                     0x00000000u                   /**< Reset value of RegSleepTimCtrl */
#define  REG_SLEEP_TIM_CTRL_MASK                            0x00000301u                   /**< Mask for RegSleepTimCtrl */

#define  ST_RUN_EN_SHIFT                                    0                             /**< Shift for STRunEn */
#define  ST_RUN_EN_MASK                                     0x00000001u                   /**< Mask for STRunEn */
#define  ST_RUN_EN_BMASK                                    0x1u                          /**< Base mask for STRunEn */
#define  ST_RUN_EN(x)                                       (((x)&0x1u)<<0)               /**< Set STRunEn in register */
#define  GET_ST_RUN_EN(reg)                                 (((reg)>>0)&0x1u)             /**< Get STRunEn from register */
#define  ST_CLEAR_SHIFT                                     8                             /**< Shift for STClear */
#define  ST_CLEAR_MASK                                      0x00000100u                   /**< Mask for STClear */
#define  ST_CLEAR_BMASK                                     0x1u                          /**< Base mask for STClear */
#define  ST_CLEAR(x)                                        (((x)&0x1u)<<8)               /**< Set STClear in register */
#define  GET_ST_CLEAR(reg)                                  (((reg)>>8)&0x1u)             /**< Get STClear from register */
#define  ST_LOAD_SHIFT                                      9                             /**< Shift for STLoad */
#define  ST_LOAD_MASK                                       0x00000200u                   /**< Mask for STLoad */
#define  ST_LOAD_BMASK                                      0x1u                          /**< Base mask for STLoad */
#define  ST_LOAD(x)                                         (((x)&0x1u)<<9)               /**< Set STLoad in register */
#define  GET_ST_LOAD(reg)                                   (((reg)>>9)&0x1u)             /**< Get STLoad from register */

// RegSleepTimCtrl.regs.STRunEn
#define  ST_RUN_EN_GSHIFT                                   0                             /**< Shift for group STRunEn */
#define  ST_RUN_EN_GSIZE                                    8                             /**< Size of group STRunEn */
#define  ST_RUN_EN_GMASK                                    0x000000FFu                   /**< Mask for group STRunEn */

#define  ST_RUN_EN_RSHIFT                                   0                             /**< Shift for STRunEn */
#define  ST_RUN_EN_RMASK                                    0x00000001u                   /**< Mask for STRunEn */
#define  ST_RUN_EN_RBMASK                                   0x1u                          /**< Base mask for STRunEn */
#define  ST_RUN_EN_R(x)                                     (((x)&0x1u)<<0)               /**< Set STRunEn in register */
#define  GET_ST_RUN_EN_R(reg)                               (((reg)>>0)&0x1u)             /**< Get STRunEn from register */

// RegSleepTimCtrl.regs.STCtrl
#define  ST_CTRL_GSHIFT                                     8                             /**< Shift for group STCtrl */
#define  ST_CTRL_GSIZE                                      8                             /**< Size of group STCtrl */
#define  ST_CTRL_GMASK                                      0x0000FF00u                   /**< Mask for group STCtrl */

#define  ST_CLEAR_RSHIFT                                    0                             /**< Shift for STClear */
#define  ST_CLEAR_RMASK                                     0x01u                         /**< Mask for STClear */
#define  ST_CLEAR_RBMASK                                    0x1u                          /**< Base mask for STClear */
#define  ST_CLEAR_R(x)                                      (((x)&0x1u)<<0)               /**< Set STClear in register */
#define  GET_ST_CLEAR_R(reg)                                (((reg)>>0)&0x1u)             /**< Get STClear from register */
#define  ST_LOAD_RSHIFT                                     1                             /**< Shift for STLoad */
#define  ST_LOAD_RMASK                                      0x02u                         /**< Mask for STLoad */
#define  ST_LOAD_RBMASK                                     0x1u                          /**< Base mask for STLoad */
#define  ST_LOAD_R(x)                                       (((x)&0x1u)<<1)               /**< Set STLoad in register */
#define  GET_ST_LOAD_R(reg)                                 (((reg)>>1)&0x1u)             /**< Get STLoad from register */
/** @} */


/**
 * @name RegSleepTimCount
 * @{
 */
// RegSleepTimCount.r32
#define  REG_SLEEP_TIM_COUNT_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSleepTimCount */
#define  REG_SLEEP_TIM_COUNT_MASK                           0xFFFFFFFFu                   /**< Mask for RegSleepTimCount */

#define  ST_COUNT_SHIFT                                     0                             /**< Shift for STCount */
#define  ST_COUNT_MASK                                      0xFFFFFFFFu                   /**< Mask for STCount */
#define  ST_COUNT_BMASK                                     0xFFFFFFFFu                   /**< Base mask for STCount */
#define  ST_COUNT(x)                                        (((x)&0xFFFFFFFFu)<<0)        /**< Set STCount in register */
#define  GET_ST_COUNT(reg)                                  (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCount from register */
/** @} */


/**
 * @name RegSleepTimCountHigh
 * @{
 */
// RegSleepTimCountHigh.r32
#define  REG_SLEEP_TIM_COUNT_HIGH_RESET_VALUE               0x00000000u                   /**< Reset value of RegSleepTimCountHigh */
#define  REG_SLEEP_TIM_COUNT_HIGH_MASK                      0x0000FFFFu                   /**< Mask for RegSleepTimCountHigh */

#define  ST_COUNT_HIGH_SHIFT                                0                             /**< Shift for STCountHigh */
#define  ST_COUNT_HIGH_MASK                                 0x0000FFFFu                   /**< Mask for STCountHigh */
#define  ST_COUNT_HIGH_BMASK                                0xFFFFu                       /**< Base mask for STCountHigh */
#define  ST_COUNT_HIGH(x)                                   (((x)&0xFFFFu)<<0)            /**< Set STCountHigh in register */
#define  GET_ST_COUNT_HIGH(reg)                             (((reg)>>0)&0xFFFFu)          /**< Get STCountHigh from register */
/** @} */


/**
 * @name RegSleepTimCompareCfg
 * @{
 */
// RegSleepTimCompareCfg.r32
#define  REG_SLEEP_TIM_COMPARE_CFG_RESET_VALUE              0x00000000u                   /**< Reset value of RegSleepTimCompareCfg */
#define  REG_SLEEP_TIM_COMPARE_CFG_MASK                     0x000F000Fu                   /**< Mask for RegSleepTimCompareCfg */

#define  ST_COMPARE_EN_SHIFT                                0                             /**< Shift for STCompareEn */
#define  ST_COMPARE_EN_MASK                                 0x0000000Fu                   /**< Mask for STCompareEn */
#define  ST_COMPARE_EN_BMASK                                0xFu                          /**< Base mask for STCompareEn */
#define  ST_COMPARE_EN(x)                                   (((x)&0xFu)<<0)               /**< Set STCompareEn in register */
#define  GET_ST_COMPARE_EN(reg)                             (((reg)>>0)&0xFu)             /**< Get STCompareEn from register */
#define  ST_WAKE_UP_EN_SHIFT                                16                            /**< Shift for STWakeUpEn */
#define  ST_WAKE_UP_EN_MASK                                 0x000F0000u                   /**< Mask for STWakeUpEn */
#define  ST_WAKE_UP_EN_BMASK                                0xFu                          /**< Base mask for STWakeUpEn */
#define  ST_WAKE_UP_EN(x)                                   (((x)&0xFu)<<16)              /**< Set STWakeUpEn in register */
#define  GET_ST_WAKE_UP_EN(reg)                             (((reg)>>16)&0xFu)            /**< Get STWakeUpEn from register */

// RegSleepTimCompareCfg.regs.STCompareEn
#define  ST_COMPARE_EN_GSHIFT                               0                             /**< Shift for group STCompareEn */
#define  ST_COMPARE_EN_GSIZE                                8                             /**< Size of group STCompareEn */
#define  ST_COMPARE_EN_GMASK                                0x000000FFu                   /**< Mask for group STCompareEn */

#define  ST_COMPARE_EN_RSHIFT                               0                             /**< Shift for STCompareEn */
#define  ST_COMPARE_EN_RMASK                                0x0000000Fu                   /**< Mask for STCompareEn */
#define  ST_COMPARE_EN_RBMASK                               0xFu                          /**< Base mask for STCompareEn */
#define  ST_COMPARE_EN_R(x)                                 (((x)&0xFu)<<0)               /**< Set STCompareEn in register */
#define  GET_ST_COMPARE_EN_R(reg)                           (((reg)>>0)&0xFu)             /**< Get STCompareEn from register */

// RegSleepTimCompareCfg.regs.STWakeUpEn
#define  ST_WAKE_UP_EN_GSHIFT                               16                            /**< Shift for group STWakeUpEn */
#define  ST_WAKE_UP_EN_GSIZE                                8                             /**< Size of group STWakeUpEn */
#define  ST_WAKE_UP_EN_GMASK                                0x00FF0000u                   /**< Mask for group STWakeUpEn */

#define  ST_WAKE_UP_EN_RSHIFT                               0                             /**< Shift for STWakeUpEn */
#define  ST_WAKE_UP_EN_RMASK                                0x0000000Fu                   /**< Mask for STWakeUpEn */
#define  ST_WAKE_UP_EN_RBMASK                               0xFu                          /**< Base mask for STWakeUpEn */
#define  ST_WAKE_UP_EN_R(x)                                 (((x)&0xFu)<<0)               /**< Set STWakeUpEn in register */
#define  GET_ST_WAKE_UP_EN_R(reg)                           (((reg)>>0)&0xFu)             /**< Get STWakeUpEn from register */
/** @} */


/**
 * @name RegSleepTimCompare0
 * @{
 */
// RegSleepTimCompare0.r32
#define  REG_SLEEP_TIM_COMPARE0_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCompare0 */
#define  REG_SLEEP_TIM_COMPARE0_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCompare0 */

#define  ST_COMPARE0_SHIFT                                  0                             /**< Shift for STCompare0 */
#define  ST_COMPARE0_MASK                                   0xFFFFFFFFu                   /**< Mask for STCompare0 */
#define  ST_COMPARE0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCompare0 */
#define  ST_COMPARE0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCompare0 in register */
#define  GET_ST_COMPARE0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCompare0 from register */
/** @} */


/**
 * @name RegSleepTimCompare1
 * @{
 */
// RegSleepTimCompare1.r32
#define  REG_SLEEP_TIM_COMPARE1_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCompare1 */
#define  REG_SLEEP_TIM_COMPARE1_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCompare1 */

#define  ST_COMPARE1_SHIFT                                  0                             /**< Shift for STCompare1 */
#define  ST_COMPARE1_MASK                                   0xFFFFFFFFu                   /**< Mask for STCompare1 */
#define  ST_COMPARE1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCompare1 */
#define  ST_COMPARE1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCompare1 in register */
#define  GET_ST_COMPARE1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCompare1 from register */
/** @} */


/**
 * @name RegSleepTimCompare2
 * @{
 */
// RegSleepTimCompare2.r32
#define  REG_SLEEP_TIM_COMPARE2_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCompare2 */
#define  REG_SLEEP_TIM_COMPARE2_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCompare2 */

#define  ST_COMPARE2_SHIFT                                  0                             /**< Shift for STCompare2 */
#define  ST_COMPARE2_MASK                                   0xFFFFFFFFu                   /**< Mask for STCompare2 */
#define  ST_COMPARE2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCompare2 */
#define  ST_COMPARE2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCompare2 in register */
#define  GET_ST_COMPARE2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCompare2 from register */
/** @} */


/**
 * @name RegSleepTimCompare3
 * @{
 */
// RegSleepTimCompare3.r32
#define  REG_SLEEP_TIM_COMPARE3_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCompare3 */
#define  REG_SLEEP_TIM_COMPARE3_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCompare3 */

#define  ST_COMPARE3_SHIFT                                  0                             /**< Shift for STCompare3 */
#define  ST_COMPARE3_MASK                                   0xFFFFFFFFu                   /**< Mask for STCompare3 */
#define  ST_COMPARE3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCompare3 */
#define  ST_COMPARE3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCompare3 in register */
#define  GET_ST_COMPARE3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCompare3 from register */
/** @} */


/**
 * @name RegSleepTimCaptureCtrl
 * @{
 */
// RegSleepTimCaptureCtrl.r32
#define  REG_SLEEP_TIM_CAPTURE_CTRL_RESET_VALUE             0x00000000u                   /**< Reset value of RegSleepTimCaptureCtrl */
#define  REG_SLEEP_TIM_CAPTURE_CTRL_MASK                    0x000F1F07u                   /**< Mask for RegSleepTimCaptureCtrl */

#define  ST_CAPTURE_SW_SHIFT                                0                             /**< Shift for STCaptureSW */
#define  ST_CAPTURE_SW_MASK                                 0x00000007u                   /**< Mask for STCaptureSW */
#define  ST_CAPTURE_SW_BMASK                                0x7u                          /**< Base mask for STCaptureSW */
#define  ST_CAPTURE_SW(x)                                   (((x)&0x7u)<<0)               /**< Set STCaptureSW in register */
#define  GET_ST_CAPTURE_SW(reg)                             (((reg)>>0)&0x7u)             /**< Get STCaptureSW from register */
#define  ST_GPIO_SEL_SHIFT                                  8                             /**< Shift for STGPIOSel */
#define  ST_GPIO_SEL_MASK                                   0x00000F00u                   /**< Mask for STGPIOSel */
#define  ST_GPIO_SEL_BMASK                                  0xFu                          /**< Base mask for STGPIOSel */
#define  ST_GPIO_SEL(x)                                     (((x)&0xFu)<<8)               /**< Set STGPIOSel in register */
#define  GET_ST_GPIO_SEL(reg)                               (((reg)>>8)&0xFu)             /**< Get STGPIOSel from register */
#define  ST_GPIO_POL_SHIFT                                  12                            /**< Shift for STGPIOPol */
#define  ST_GPIO_POL_MASK                                   0x00001000u                   /**< Mask for STGPIOPol */
#define  ST_GPIO_POL_BMASK                                  0x1u                          /**< Base mask for STGPIOPol */
#define  ST_GPIO_POL(x)                                     (((x)&0x1u)<<12)              /**< Set STGPIOPol in register */
#define  GET_ST_GPIO_POL(reg)                               (((reg)>>12)&0x1u)            /**< Get STGPIOPol from register */
#define  ST_CAPTURE_HW_SHIFT                                16                            /**< Shift for STCaptureHW */
#define  ST_CAPTURE_HW_MASK                                 0x000F0000u                   /**< Mask for STCaptureHW */
#define  ST_CAPTURE_HW_BMASK                                0xFu                          /**< Base mask for STCaptureHW */
#define  ST_CAPTURE_HW(x)                                   (((x)&0xFu)<<16)              /**< Set STCaptureHW in register */
#define  GET_ST_CAPTURE_HW(reg)                             (((reg)>>16)&0xFu)            /**< Get STCaptureHW from register */

// RegSleepTimCaptureCtrl.regs.STCaptureSW
#define  ST_CAPTURE_SW_GSHIFT                               0                             /**< Shift for group STCaptureSW */
#define  ST_CAPTURE_SW_GSIZE                                8                             /**< Size of group STCaptureSW */
#define  ST_CAPTURE_SW_GMASK                                0x000000FFu                   /**< Mask for group STCaptureSW */

#define  ST_CAPTURE_SW_RSHIFT                               0                             /**< Shift for STCaptureSW */
#define  ST_CAPTURE_SW_RMASK                                0x00000007u                   /**< Mask for STCaptureSW */
#define  ST_CAPTURE_SW_RBMASK                               0x7u                          /**< Base mask for STCaptureSW */
#define  ST_CAPTURE_SW_R(x)                                 (((x)&0x7u)<<0)               /**< Set STCaptureSW in register */
#define  GET_ST_CAPTURE_SW_R(reg)                           (((reg)>>0)&0x7u)             /**< Get STCaptureSW from register */

// RegSleepTimCaptureCtrl.regs.STGPIOEvtCfg
#define  ST_GPIO_EVT_CFG_GSHIFT                             8                             /**< Shift for group STGPIOEvtCfg */
#define  ST_GPIO_EVT_CFG_GSIZE                              8                             /**< Size of group STGPIOEvtCfg */
#define  ST_GPIO_EVT_CFG_GMASK                              0x0000FF00u                   /**< Mask for group STGPIOEvtCfg */

#define  ST_GPIO_SEL_RSHIFT                                 0                             /**< Shift for STGPIOSel */
#define  ST_GPIO_SEL_RMASK                                  0x0Fu                         /**< Mask for STGPIOSel */
#define  ST_GPIO_SEL_RBMASK                                 0xFu                          /**< Base mask for STGPIOSel */
#define  ST_GPIO_SEL_R(x)                                   (((x)&0xFu)<<0)               /**< Set STGPIOSel in register */
#define  GET_ST_GPIO_SEL_R(reg)                             (((reg)>>0)&0xFu)             /**< Get STGPIOSel from register */
#define  ST_GPIO_POL_RSHIFT                                 4                             /**< Shift for STGPIOPol */
#define  ST_GPIO_POL_RMASK                                  0x10u                         /**< Mask for STGPIOPol */
#define  ST_GPIO_POL_RBMASK                                 0x1u                          /**< Base mask for STGPIOPol */
#define  ST_GPIO_POL_R(x)                                   (((x)&0x1u)<<4)               /**< Set STGPIOPol in register */
#define  GET_ST_GPIO_POL_R(reg)                             (((reg)>>4)&0x1u)             /**< Get STGPIOPol from register */

// RegSleepTimCaptureCtrl.regs.STCaptureHW
#define  ST_CAPTURE_HW_GSHIFT                               16                            /**< Shift for group STCaptureHW */
#define  ST_CAPTURE_HW_GSIZE                                8                             /**< Size of group STCaptureHW */
#define  ST_CAPTURE_HW_GMASK                                0x00FF0000u                   /**< Mask for group STCaptureHW */

#define  ST_CAPTURE_HW_RSHIFT                               0                             /**< Shift for STCaptureHW */
#define  ST_CAPTURE_HW_RMASK                                0x0Fu                         /**< Mask for STCaptureHW */
#define  ST_CAPTURE_HW_RBMASK                               0xFu                          /**< Base mask for STCaptureHW */
#define  ST_CAPTURE_HW_R(x)                                 (((x)&0xFu)<<0)               /**< Set STCaptureHW in register */
#define  GET_ST_CAPTURE_HW_R(reg)                           (((reg)>>0)&0xFu)             /**< Get STCaptureHW from register */
/** @} */


/**
 * @name RegSleepTimCaptureHWEvtSel
 * @{
 */
// RegSleepTimCaptureHWEvtSel.r32
#define  REG_SLEEP_TIM_CAPTURE_HW_EVT_SEL_RESET_VALUE       0x00000000u                   /**< Reset value of RegSleepTimCaptureHWEvtSel */
#define  REG_SLEEP_TIM_CAPTURE_HW_EVT_SEL_MASK              0x00010101u                   /**< Mask for RegSleepTimCaptureHWEvtSel */

#define  ST_CAPTURE0_HW_EVT_SEL_SHIFT                       0                             /**< Shift for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_MASK                        0x00000001u                   /**< Mask for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_BMASK                       0x1u                          /**< Base mask for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL(x)                          (((x)&0x1u)<<0)               /**< Set STCapture0HWEvtSel in register */
#define  GET_ST_CAPTURE0_HW_EVT_SEL(reg)                    (((reg)>>0)&0x1u)             /**< Get STCapture0HWEvtSel from register */
#define  ST_CAPTURE1_HW_EVT_SEL_SHIFT                       8                             /**< Shift for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_MASK                        0x00000100u                   /**< Mask for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_BMASK                       0x1u                          /**< Base mask for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL(x)                          (((x)&0x1u)<<8)               /**< Set STCapture1HWEvtSel in register */
#define  GET_ST_CAPTURE1_HW_EVT_SEL(reg)                    (((reg)>>8)&0x1u)             /**< Get STCapture1HWEvtSel from register */
#define  ST_CAPTURE2_HW_EVT_SEL_SHIFT                       16                            /**< Shift for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_MASK                        0x00010000u                   /**< Mask for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_BMASK                       0x1u                          /**< Base mask for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL(x)                          (((x)&0x1u)<<16)              /**< Set STCapture2HWEvtSel in register */
#define  GET_ST_CAPTURE2_HW_EVT_SEL(reg)                    (((reg)>>16)&0x1u)            /**< Get STCapture2HWEvtSel from register */

// RegSleepTimCaptureHWEvtSel.regs.STCapture0HWEvtSel
#define  ST_CAPTURE0_HW_EVT_SEL_GSHIFT                      0                             /**< Shift for group STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_GSIZE                       8                             /**< Size of group STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_GMASK                       0x000000FFu                   /**< Mask for group STCapture0HWEvtSel */

#define  ST_CAPTURE0_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_RMASK                       0x00000001u                   /**< Mask for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_RBMASK                      0x1u                          /**< Base mask for STCapture0HWEvtSel */
#define  ST_CAPTURE0_HW_EVT_SEL_R(x)                        (((x)&0x1u)<<0)               /**< Set STCapture0HWEvtSel in register */
#define  GET_ST_CAPTURE0_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x1u)             /**< Get STCapture0HWEvtSel from register */

// RegSleepTimCaptureHWEvtSel.regs.STCapture1HWEvtSel
#define  ST_CAPTURE1_HW_EVT_SEL_GSHIFT                      8                             /**< Shift for group STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_GSIZE                       8                             /**< Size of group STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_GMASK                       0x0000FF00u                   /**< Mask for group STCapture1HWEvtSel */

#define  ST_CAPTURE1_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_RMASK                       0x00000001u                   /**< Mask for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_RBMASK                      0x1u                          /**< Base mask for STCapture1HWEvtSel */
#define  ST_CAPTURE1_HW_EVT_SEL_R(x)                        (((x)&0x1u)<<0)               /**< Set STCapture1HWEvtSel in register */
#define  GET_ST_CAPTURE1_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x1u)             /**< Get STCapture1HWEvtSel from register */

// RegSleepTimCaptureHWEvtSel.regs.STCapture2HWEvtSel
#define  ST_CAPTURE2_HW_EVT_SEL_GSHIFT                      16                            /**< Shift for group STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_GSIZE                       8                             /**< Size of group STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_GMASK                       0x00FF0000u                   /**< Mask for group STCapture2HWEvtSel */

#define  ST_CAPTURE2_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_RMASK                       0x00000001u                   /**< Mask for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_RBMASK                      0x1u                          /**< Base mask for STCapture2HWEvtSel */
#define  ST_CAPTURE2_HW_EVT_SEL_R(x)                        (((x)&0x1u)<<0)               /**< Set STCapture2HWEvtSel in register */
#define  GET_ST_CAPTURE2_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x1u)             /**< Get STCapture2HWEvtSel from register */
/** @} */


/**
 * @name RegSleepTimCapture0
 * @{
 */
// RegSleepTimCapture0.r32
#define  REG_SLEEP_TIM_CAPTURE0_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCapture0 */
#define  REG_SLEEP_TIM_CAPTURE0_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCapture0 */

#define  ST_CAPTURE0_SHIFT                                  0                             /**< Shift for STCapture0 */
#define  ST_CAPTURE0_MASK                                   0xFFFFFFFFu                   /**< Mask for STCapture0 */
#define  ST_CAPTURE0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCapture0 */
#define  ST_CAPTURE0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCapture0 in register */
#define  GET_ST_CAPTURE0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCapture0 from register */
/** @} */


/**
 * @name RegSleepTimCapture1
 * @{
 */
// RegSleepTimCapture1.r32
#define  REG_SLEEP_TIM_CAPTURE1_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCapture1 */
#define  REG_SLEEP_TIM_CAPTURE1_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCapture1 */

#define  ST_CAPTURE1_SHIFT                                  0                             /**< Shift for STCapture1 */
#define  ST_CAPTURE1_MASK                                   0xFFFFFFFFu                   /**< Mask for STCapture1 */
#define  ST_CAPTURE1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCapture1 */
#define  ST_CAPTURE1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCapture1 in register */
#define  GET_ST_CAPTURE1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCapture1 from register */
/** @} */


/**
 * @name RegSleepTimCapture2
 * @{
 */
// RegSleepTimCapture2.r32
#define  REG_SLEEP_TIM_CAPTURE2_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCapture2 */
#define  REG_SLEEP_TIM_CAPTURE2_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCapture2 */

#define  ST_CAPTURE2_SHIFT                                  0                             /**< Shift for STCapture2 */
#define  ST_CAPTURE2_MASK                                   0xFFFFFFFFu                   /**< Mask for STCapture2 */
#define  ST_CAPTURE2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCapture2 */
#define  ST_CAPTURE2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCapture2 in register */
#define  GET_ST_CAPTURE2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCapture2 from register */
/** @} */


/**
 * @name RegSleepTimCapture3
 * @{
 */
// RegSleepTimCapture3.r32
#define  REG_SLEEP_TIM_CAPTURE3_RESET_VALUE                 0x00000000u                   /**< Reset value of RegSleepTimCapture3 */
#define  REG_SLEEP_TIM_CAPTURE3_MASK                        0xFFFFFFFFu                   /**< Mask for RegSleepTimCapture3 */

#define  ST_CAPTURE3_SHIFT                                  0                             /**< Shift for STCapture3 */
#define  ST_CAPTURE3_MASK                                   0xFFFFFFFFu                   /**< Mask for STCapture3 */
#define  ST_CAPTURE3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for STCapture3 */
#define  ST_CAPTURE3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set STCapture3 in register */
#define  GET_ST_CAPTURE3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get STCapture3 from register */
/** @} */


/**
 * @name RegNvmLockMain0
 * @{
 */
// RegNvmLockMain0.r32
#define  REG_NVM_LOCK_MAIN0_RESET_VALUE                     0x00000000u                   /**< Reset value of RegNvmLockMain0 */
#define  REG_NVM_LOCK_MAIN0_MASK                            0xFFFFFFFFu                   /**< Mask for RegNvmLockMain0 */

#define  NVM_LOCK_MAIN_PAGE0_SHIFT                          0                             /**< Shift for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_MASK                           0xFFFFFFFFu                   /**< Mask for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_BMASK                          0xFFFFFFFFu                   /**< Base mask for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0(x)                             (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmLockMainPage0 in register */
#define  GET_NVM_LOCK_MAIN_PAGE0(reg)                       (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmLockMainPage0 from register */

// RegNvmLockMain0.regs.NvmLockMainPage0
#define  NVM_LOCK_MAIN_PAGE0_GSHIFT                         0                             /**< Shift for group NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_GSIZE                          32                            /**< Size of group NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_GMASK                          0xFFFFFFFFu                   /**< Mask for group NvmLockMainPage0 */

#define  NVM_LOCK_MAIN_PAGE0_RSHIFT                         0                             /**< Shift for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_RMASK                          0xFFFFFFFFu                   /**< Mask for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_RBMASK                         0xFFFFFFFFu                   /**< Base mask for NvmLockMainPage0 */
#define  NVM_LOCK_MAIN_PAGE0_R(x)                           (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmLockMainPage0 in register */
#define  GET_NVM_LOCK_MAIN_PAGE0_R(reg)                     (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmLockMainPage0 from register */
/** @} */


/**
 * @name RegNvmLockMain1
 * @{
 */
// RegNvmLockMain1.r32
#define  REG_NVM_LOCK_MAIN1_RESET_VALUE                     0x00000000u                   /**< Reset value of RegNvmLockMain1 */
#define  REG_NVM_LOCK_MAIN1_MASK                            0xFFFFFFFFu                   /**< Mask for RegNvmLockMain1 */

#define  NVM_LOCK_MAIN_PAGE1_SHIFT                          0                             /**< Shift for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_MASK                           0xFFFFFFFFu                   /**< Mask for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_BMASK                          0xFFFFFFFFu                   /**< Base mask for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1(x)                             (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmLockMainPage1 in register */
#define  GET_NVM_LOCK_MAIN_PAGE1(reg)                       (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmLockMainPage1 from register */

// RegNvmLockMain1.regs.NvmLockMainPage1
#define  NVM_LOCK_MAIN_PAGE1_GSHIFT                         0                             /**< Shift for group NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_GSIZE                          32                            /**< Size of group NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_GMASK                          0xFFFFFFFFu                   /**< Mask for group NvmLockMainPage1 */

#define  NVM_LOCK_MAIN_PAGE1_RSHIFT                         0                             /**< Shift for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_RMASK                          0xFFFFFFFFu                   /**< Mask for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_RBMASK                         0xFFFFFFFFu                   /**< Base mask for NvmLockMainPage1 */
#define  NVM_LOCK_MAIN_PAGE1_R(x)                           (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmLockMainPage1 in register */
#define  GET_NVM_LOCK_MAIN_PAGE1_R(reg)                     (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmLockMainPage1 from register */
/** @} */


/**
 * @name RegNvmLockInfo
 * @{
 */
// RegNvmLockInfo.r32
#define  REG_NVM_LOCK_INFO_RESET_VALUE                      0x00000000u                   /**< Reset value of RegNvmLockInfo */
#define  REG_NVM_LOCK_INFO_MASK                             0x0003000Fu                   /**< Mask for RegNvmLockInfo */

#define  NVM_LOCK_INFO_PAGE_SHIFT                           0                             /**< Shift for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_MASK                            0x0000000Fu                   /**< Mask for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_BMASK                           0xFu                          /**< Base mask for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE(x)                              (((x)&0xFu)<<0)               /**< Set NvmLockInfoPage in register */
#define  GET_NVM_LOCK_INFO_PAGE(reg)                        (((reg)>>0)&0xFu)             /**< Get NvmLockInfoPage from register */
#define  NVM_WRITE_LOCK_INFO_PAGE0_SHIFT                    16                            /**< Shift for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0_MASK                     0x00010000u                   /**< Mask for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0_BMASK                    0x1u                          /**< Base mask for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0(x)                       (((x)&0x1u)<<16)              /**< Set NvmWriteLockInfoPage0 in register */
#define  GET_NVM_WRITE_LOCK_INFO_PAGE0(reg)                 (((reg)>>16)&0x1u)            /**< Get NvmWriteLockInfoPage0 from register */
#define  NVM_ERASE_LOCK_INFO_PAGE0_SHIFT                    17                            /**< Shift for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0_MASK                     0x00020000u                   /**< Mask for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0_BMASK                    0x1u                          /**< Base mask for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0(x)                       (((x)&0x1u)<<17)              /**< Set NvmEraseLockInfoPage0 in register */
#define  GET_NVM_ERASE_LOCK_INFO_PAGE0(reg)                 (((reg)>>17)&0x1u)            /**< Get NvmEraseLockInfoPage0 from register */

// RegNvmLockInfo.regs.NvmLockInfoPage
#define  NVM_LOCK_INFO_PAGE_GSHIFT                          0                             /**< Shift for group NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_GSIZE                           16                            /**< Size of group NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_GMASK                           0x0000FFFFu                   /**< Mask for group NvmLockInfoPage */

#define  NVM_LOCK_INFO_PAGE_RSHIFT                          0                             /**< Shift for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_RMASK                           0x0000000Fu                   /**< Mask for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_RBMASK                          0xFu                          /**< Base mask for NvmLockInfoPage */
#define  NVM_LOCK_INFO_PAGE_R(x)                            (((x)&0xFu)<<0)               /**< Set NvmLockInfoPage in register */
#define  GET_NVM_LOCK_INFO_PAGE_R(reg)                      (((reg)>>0)&0xFu)             /**< Get NvmLockInfoPage from register */
#define  NVM_WRITE_LOCK_INFO_PAGE0_RSHIFT                   16                            /**< Shift for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0_RMASK                    0x00010000u                   /**< Mask for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0_RBMASK                   0x1u                          /**< Base mask for NvmWriteLockInfoPage0 */
#define  NVM_WRITE_LOCK_INFO_PAGE0_R(x)                     (((x)&0x1u)<<16)              /**< Set NvmWriteLockInfoPage0 in register */
#define  GET_NVM_WRITE_LOCK_INFO_PAGE0_R(reg)               (((reg)>>16)&0x1u)            /**< Get NvmWriteLockInfoPage0 from register */
#define  NVM_ERASE_LOCK_INFO_PAGE0_RSHIFT                   17                            /**< Shift for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0_RMASK                    0x00020000u                   /**< Mask for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0_RBMASK                   0x1u                          /**< Base mask for NvmEraseLockInfoPage0 */
#define  NVM_ERASE_LOCK_INFO_PAGE0_R(x)                     (((x)&0x1u)<<17)              /**< Set NvmEraseLockInfoPage0 in register */
#define  GET_NVM_ERASE_LOCK_INFO_PAGE0_R(reg)               (((reg)>>17)&0x1u)            /**< Get NvmEraseLockInfoPage0 from register */
/** @} */


/**
 * @name RegNvmLockMaster
 * @{
 */
// RegNvmLockMaster.r32
#define  REG_NVM_LOCK_MASTER_RESET_VALUE                    0x00000000u                   /**< Reset value of RegNvmLockMaster */
#define  REG_NVM_LOCK_MASTER_MASK                           0x00010103u                   /**< Mask for RegNvmLockMaster */

#define  NVM_LOCK_ERASE_MAIN_SHIFT                          0                             /**< Shift for NvmLockEraseMain */
#define  NVM_LOCK_ERASE_MAIN_MASK                           0x00000001u                   /**< Mask for NvmLockEraseMain */
#define  NVM_LOCK_ERASE_MAIN_BMASK                          0x1u                          /**< Base mask for NvmLockEraseMain */
#define  NVM_LOCK_ERASE_MAIN(x)                             (((x)&0x1u)<<0)               /**< Set NvmLockEraseMain in register */
#define  GET_NVM_LOCK_ERASE_MAIN(reg)                       (((reg)>>0)&0x1u)             /**< Get NvmLockEraseMain from register */
#define  NVM_LOCK_ERASE_FULL_SHIFT                          1                             /**< Shift for NvmLockEraseFull */
#define  NVM_LOCK_ERASE_FULL_MASK                           0x00000002u                   /**< Mask for NvmLockEraseFull */
#define  NVM_LOCK_ERASE_FULL_BMASK                          0x1u                          /**< Base mask for NvmLockEraseFull */
#define  NVM_LOCK_ERASE_FULL(x)                             (((x)&0x1u)<<1)               /**< Set NvmLockEraseFull in register */
#define  GET_NVM_LOCK_ERASE_FULL(reg)                       (((reg)>>1)&0x1u)             /**< Get NvmLockEraseFull from register */
#define  NVM_LOCK_REDUND_SHIFT                              8                             /**< Shift for NvmLockRedund */
#define  NVM_LOCK_REDUND_MASK                               0x00000100u                   /**< Mask for NvmLockRedund */
#define  NVM_LOCK_REDUND_BMASK                              0x1u                          /**< Base mask for NvmLockRedund */
#define  NVM_LOCK_REDUND(x)                                 (((x)&0x1u)<<8)               /**< Set NvmLockRedund in register */
#define  GET_NVM_LOCK_REDUND(reg)                           (((reg)>>8)&0x1u)             /**< Get NvmLockRedund from register */
#define  NVM_LOCK_MASTER_SHIFT                              16                            /**< Shift for NvmLockMaster */
#define  NVM_LOCK_MASTER_MASK                               0x00010000u                   /**< Mask for NvmLockMaster */
#define  NVM_LOCK_MASTER_BMASK                              0x1u                          /**< Base mask for NvmLockMaster */
#define  NVM_LOCK_MASTER(x)                                 (((x)&0x1u)<<16)              /**< Set NvmLockMaster in register */
#define  GET_NVM_LOCK_MASTER(reg)                           (((reg)>>16)&0x1u)            /**< Get NvmLockMaster from register */
/** @} */


/**
 * @name RegNvmKcLockKey
 * @{
 */
// RegNvmKcLockKey.r32
#define  REG_NVM_KC_LOCK_KEY_RESET_VALUE                    0x00000000u                   /**< Reset value of RegNvmKcLockKey */
#define  REG_NVM_KC_LOCK_KEY_MASK                           0x000000FFu                   /**< Mask for RegNvmKcLockKey */

#define  NVM_KC_LOCK_KEY_SHIFT                              0                             /**< Shift for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_MASK                               0x000000FFu                   /**< Mask for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_BMASK                              0xFFu                         /**< Base mask for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY(x)                                 (((x)&0xFFu)<<0)              /**< Set NvmKcLockKey in register */
#define  GET_NVM_KC_LOCK_KEY(reg)                           (((reg)>>0)&0xFFu)            /**< Get NvmKcLockKey from register */

// RegNvmKcLockKey.regs.NvmKcLockKey
#define  NVM_KC_LOCK_KEY_GSHIFT                             0                             /**< Shift for group NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_GSIZE                              8                             /**< Size of group NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_GMASK                              0x000000FFu                   /**< Mask for group NvmKcLockKey */

#define  NVM_KC_LOCK_KEY_RSHIFT                             0                             /**< Shift for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_RMASK                              0x000000FFu                   /**< Mask for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_RBMASK                             0xFFu                         /**< Base mask for NvmKcLockKey */
#define  NVM_KC_LOCK_KEY_R(x)                               (((x)&0xFFu)<<0)              /**< Set NvmKcLockKey in register */
#define  GET_NVM_KC_LOCK_KEY_R(reg)                         (((reg)>>0)&0xFFu)            /**< Get NvmKcLockKey from register */
/** @} */


/**
 * @name RegNvmRedunCfg
 * @{
 */
// RegNvmRedunCfg.r32
#define  REG_NVM_REDUN_CFG_RESET_VALUE                      0x00000000u                   /**< Reset value of RegNvmRedunCfg */
#define  REG_NVM_REDUN_CFG_MASK                             0x013F013Fu                   /**< Mask for RegNvmRedunCfg */

#define  NVM_REDUN_PAGE0_MAP_SHIFT                          0                             /**< Shift for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP_MASK                           0x0000003Fu                   /**< Mask for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP_BMASK                          0x3Fu                         /**< Base mask for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP(x)                             (((x)&0x3Fu)<<0)              /**< Set NvmRedunPage0Map in register */
#define  GET_NVM_REDUN_PAGE0_MAP(reg)                       (((reg)>>0)&0x3Fu)            /**< Get NvmRedunPage0Map from register */
#define  NVM_REDUN_PAGE0_EN_SHIFT                           8                             /**< Shift for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN_MASK                            0x00000100u                   /**< Mask for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN_BMASK                           0x1u                          /**< Base mask for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN(x)                              (((x)&0x1u)<<8)               /**< Set NvmRedunPage0En in register */
#define  GET_NVM_REDUN_PAGE0_EN(reg)                        (((reg)>>8)&0x1u)             /**< Get NvmRedunPage0En from register */
#define  NVM_REDUN_PAGE1_MAP_SHIFT                          16                            /**< Shift for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP_MASK                           0x003F0000u                   /**< Mask for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP_BMASK                          0x3Fu                         /**< Base mask for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP(x)                             (((x)&0x3Fu)<<16)             /**< Set NvmRedunPage1Map in register */
#define  GET_NVM_REDUN_PAGE1_MAP(reg)                       (((reg)>>16)&0x3Fu)           /**< Get NvmRedunPage1Map from register */
#define  NVM_REDUN_PAGE1_EN_SHIFT                           24                            /**< Shift for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN_MASK                            0x01000000u                   /**< Mask for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN_BMASK                           0x1u                          /**< Base mask for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN(x)                              (((x)&0x1u)<<24)              /**< Set NvmRedunPage1En in register */
#define  GET_NVM_REDUN_PAGE1_EN(reg)                        (((reg)>>24)&0x1u)            /**< Get NvmRedunPage1En from register */

// RegNvmRedunCfg.regs.NvmRedunPage0
#define  NVM_REDUN_PAGE0_GSHIFT                             0                             /**< Shift for group NvmRedunPage0 */
#define  NVM_REDUN_PAGE0_GSIZE                              16                            /**< Size of group NvmRedunPage0 */
#define  NVM_REDUN_PAGE0_GMASK                              0x0000FFFFu                   /**< Mask for group NvmRedunPage0 */

#define  NVM_REDUN_PAGE0_MAP_RSHIFT                         0                             /**< Shift for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP_RMASK                          0x003Fu                       /**< Mask for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP_RBMASK                         0x3Fu                         /**< Base mask for NvmRedunPage0Map */
#define  NVM_REDUN_PAGE0_MAP_R(x)                           (((x)&0x3Fu)<<0)              /**< Set NvmRedunPage0Map in register */
#define  GET_NVM_REDUN_PAGE0_MAP_R(reg)                     (((reg)>>0)&0x3Fu)            /**< Get NvmRedunPage0Map from register */
#define  NVM_REDUN_PAGE0_EN_RSHIFT                          8                             /**< Shift for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN_RMASK                           0x0100u                       /**< Mask for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN_RBMASK                          0x1u                          /**< Base mask for NvmRedunPage0En */
#define  NVM_REDUN_PAGE0_EN_R(x)                            (((x)&0x1u)<<8)               /**< Set NvmRedunPage0En in register */
#define  GET_NVM_REDUN_PAGE0_EN_R(reg)                      (((reg)>>8)&0x1u)             /**< Get NvmRedunPage0En from register */

// RegNvmRedunCfg.regs.NvmRedunPage1
#define  NVM_REDUN_PAGE1_GSHIFT                             16                            /**< Shift for group NvmRedunPage1 */
#define  NVM_REDUN_PAGE1_GSIZE                              16                            /**< Size of group NvmRedunPage1 */
#define  NVM_REDUN_PAGE1_GMASK                              0xFFFF0000u                   /**< Mask for group NvmRedunPage1 */

#define  NVM_REDUN_PAGE1_MAP_RSHIFT                         0                             /**< Shift for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP_RMASK                          0x003Fu                       /**< Mask for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP_RBMASK                         0x3Fu                         /**< Base mask for NvmRedunPage1Map */
#define  NVM_REDUN_PAGE1_MAP_R(x)                           (((x)&0x3Fu)<<0)              /**< Set NvmRedunPage1Map in register */
#define  GET_NVM_REDUN_PAGE1_MAP_R(reg)                     (((reg)>>0)&0x3Fu)            /**< Get NvmRedunPage1Map from register */
#define  NVM_REDUN_PAGE1_EN_RSHIFT                          8                             /**< Shift for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN_RMASK                           0x0100u                       /**< Mask for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN_RBMASK                          0x1u                          /**< Base mask for NvmRedunPage1En */
#define  NVM_REDUN_PAGE1_EN_R(x)                            (((x)&0x1u)<<8)               /**< Set NvmRedunPage1En in register */
#define  GET_NVM_REDUN_PAGE1_EN_R(reg)                      (((reg)>>8)&0x1u)             /**< Get NvmRedunPage1En from register */
/** @} */


/**
 * @name RegTstLFRC
 * @{
 */
// RegTstLFRC.r32
#define  REG_TST_LF_RC_RESET_VALUE                          0x00000000u                   /**< Reset value of RegTstLFRC */
#define  REG_TST_LF_RC_MASK                                 0x00000001u                   /**< Mask for RegTstLFRC */

#define  TST_LF_RC_OUT_SHIFT                                0                             /**< Shift for TstLFRCOut */
#define  TST_LF_RC_OUT_MASK                                 0x00000001u                   /**< Mask for TstLFRCOut */
#define  TST_LF_RC_OUT_BMASK                                0x1u                          /**< Base mask for TstLFRCOut */
#define  TST_LF_RC_OUT(x)                                   (((x)&0x1u)<<0)               /**< Set TstLFRCOut in register */
#define  GET_TST_LF_RC_OUT(reg)                             (((reg)>>0)&0x1u)             /**< Get TstLFRCOut from register */
/** @} */


/**
 * @name RegPmlLFRC
 * @{
 */
// RegPmlLFRC.r32
#define  REG_PML_LF_RC_RESET_VALUE                          0x00000000u                   /**< Reset value of RegPmlLFRC */
#define  REG_PML_LF_RC_MASK                                 0x00000001u                   /**< Mask for RegPmlLFRC */

#define  PML_LF_RC_CHOP_EN_SHIFT                            0                             /**< Shift for PmlLFRCChopEn */
#define  PML_LF_RC_CHOP_EN_MASK                             0x00000001u                   /**< Mask for PmlLFRCChopEn */
#define  PML_LF_RC_CHOP_EN_BMASK                            0x1u                          /**< Base mask for PmlLFRCChopEn */
#define  PML_LF_RC_CHOP_EN(x)                               (((x)&0x1u)<<0)               /**< Set PmlLFRCChopEn in register */
#define  GET_PML_LF_RC_CHOP_EN(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlLFRCChopEn from register */
/** @} */



/** @} End of group PML_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_PML_H */
