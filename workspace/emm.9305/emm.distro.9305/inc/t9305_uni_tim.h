////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_uni_tim.h
///
/// @project    T9305
///
/// @brief      Universal Timers register and bit field definitions
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

#ifndef _T9305_UNI_TIM_H
#define _T9305_UNI_TIM_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup UniTim_Registers Universal Timers Register Map - registers
 * @{
 ******************************************************************************/


/** Universal Timer2 configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Cfg_t;


/** Universal Timer2 control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Ctrl_t;


/** Universal Timer2 status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Stat_t;


/** Universal Timer2 counter value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Count_t;


/** Universal Timer2 Limit - Reset to zero when timer value reaches this value and trigger limit action */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Limit_t;


/** Universal Timer2 Compare0 - Trigger compare action on channel 0 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Compare0_t;


/** Universal Timer2 Compare1 - Trigger compare action on channel 1 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Compare1_t;


/** Universal Timer2 Compare2 - Trigger compare action on channel 2 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Compare2_t;


/** Universal Timer2 Compare3 - Trigger compare action on channel 3 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Compare3_t;


/** Universal Timer2 captured value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer2Capture_t;


/** Universal Timer3 configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Cfg_t;


/** Universal Timer3 control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Ctrl_t;


/** Universal Timer3 status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Stat_t;


/** Universal Timer3 counter value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Count_t;


/** Universal Timer3 Limit - Reset to zero when timer value reaches this value and trigger limit action */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Limit_t;


/** Universal Timer3 Compare0 - Trigger compare action on channel 0 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Compare0_t;


/** Universal Timer3 Compare1 - Trigger compare action on channel 1 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Compare1_t;


/** Universal Timer3 Compare2 - Trigger compare action on channel 2 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Compare2_t;


/** Universal Timer3 Compare3 - Trigger compare action on channel 3 when timer status reaches this value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Compare3_t;


/** Universal Timer3 captured value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUniTimer3Capture_t;

/** @} end of group UniTim_Regs */



/***************************************************************************//**
 * @defgroup UniTim_RegMap Universal Timers Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegUniTimer2Cfg_t                                 RegUniTimer2Cfg;              /**< Universal Timer2 configuration */
    __IO  RegUniTimer2Ctrl_t                                RegUniTimer2Ctrl;             /**< Universal Timer2 control */
    __I   RegUniTimer2Stat_t                                RegUniTimer2Stat;             /**< Universal Timer2 status */
    __I   RegUniTimer2Count_t                               RegUniTimer2Count;            /**< Universal Timer2 counter value */
    __IO  RegUniTimer2Limit_t                               RegUniTimer2Limit;            /**< Universal Timer2 Limit - Reset to zero when timer value reaches this value and trigger limit action */
    __IO  RegUniTimer2Compare0_t                            RegUniTimer2Compare0;         /**< Universal Timer2 Compare0 - Trigger compare action on channel 0 when timer status reaches this value */
    __IO  RegUniTimer2Compare1_t                            RegUniTimer2Compare1;         /**< Universal Timer2 Compare1 - Trigger compare action on channel 1 when timer status reaches this value */
    __IO  RegUniTimer2Compare2_t                            RegUniTimer2Compare2;         /**< Universal Timer2 Compare2 - Trigger compare action on channel 2 when timer status reaches this value */
    __IO  RegUniTimer2Compare3_t                            RegUniTimer2Compare3;         /**< Universal Timer2 Compare3 - Trigger compare action on channel 3 when timer status reaches this value */
    __I   RegUniTimer2Capture_t                             RegUniTimer2Capture;          /**< Universal Timer2 captured value */
    __IO  RegUniTimer3Cfg_t                                 RegUniTimer3Cfg;              /**< Universal Timer3 configuration */
    __IO  RegUniTimer3Ctrl_t                                RegUniTimer3Ctrl;             /**< Universal Timer3 control */
    __I   RegUniTimer3Stat_t                                RegUniTimer3Stat;             /**< Universal Timer3 status */
    __I   RegUniTimer3Count_t                               RegUniTimer3Count;            /**< Universal Timer3 counter value */
    __IO  RegUniTimer3Limit_t                               RegUniTimer3Limit;            /**< Universal Timer3 Limit - Reset to zero when timer value reaches this value and trigger limit action */
    __IO  RegUniTimer3Compare0_t                            RegUniTimer3Compare0;         /**< Universal Timer3 Compare0 - Trigger compare action on channel 0 when timer status reaches this value */
    __IO  RegUniTimer3Compare1_t                            RegUniTimer3Compare1;         /**< Universal Timer3 Compare1 - Trigger compare action on channel 1 when timer status reaches this value */
    __IO  RegUniTimer3Compare2_t                            RegUniTimer3Compare2;         /**< Universal Timer3 Compare2 - Trigger compare action on channel 2 when timer status reaches this value */
    __IO  RegUniTimer3Compare3_t                            RegUniTimer3Compare3;         /**< Universal Timer3 Compare3 - Trigger compare action on channel 3 when timer status reaches this value */
    __I   RegUniTimer3Capture_t                             RegUniTimer3Capture;          /**< Universal Timer3 captured value */
} UniTim_RegMap_t;

/** @} end of group UniTim_RegMap */



/***************************************************************************//**
 * @defgroup UniTim_BitFields UniTim bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegUniTimer2Cfg
 * @{
 */
// RegUniTimer2Cfg.r32
#define  REG_UNI_TIMER2_CFG_RESET_VALUE                     0x00000000u                   /**< Reset value of RegUniTimer2Cfg */
#define  REG_UNI_TIMER2_CFG_MASK                            0x0001FDE7u                   /**< Mask for RegUniTimer2Cfg */

#define  UT2_PRESCALER_SEL_SHIFT                            0                             /**< Shift for UT2PrescalerSel */
#define  UT2_PRESCALER_SEL_MASK                             0x00000007u                   /**< Mask for UT2PrescalerSel */
#define  UT2_PRESCALER_SEL_BMASK                            0x7u                          /**< Base mask for UT2PrescalerSel */
#define  UT2_PRESCALER_SEL(x)                               (((x)&0x7u)<<0)               /**< Set UT2PrescalerSel in register */
#define  GET_UT2_PRESCALER_SEL(reg)                         (((reg)>>0)&0x7u)             /**< Get UT2PrescalerSel from register */
#define  UT2_CLK_SEL_SHIFT                                  5                             /**< Shift for UT2ClkSel */
#define  UT2_CLK_SEL_MASK                                   0x00000020u                   /**< Mask for UT2ClkSel */
#define  UT2_CLK_SEL_BMASK                                  0x1u                          /**< Base mask for UT2ClkSel */
#define  UT2_CLK_SEL(x)                                     (((x)&0x1u)<<5)               /**< Set UT2ClkSel in register */
#define  GET_UT2_CLK_SEL(reg)                               (((reg)>>5)&0x1u)             /**< Get UT2ClkSel from register */
#define  UT2_START_SEL_SHIFT                                6                             /**< Shift for UT2StartSel */
#define  UT2_START_SEL_MASK                                 0x00000040u                   /**< Mask for UT2StartSel */
#define  UT2_START_SEL_BMASK                                0x1u                          /**< Base mask for UT2StartSel */
#define  UT2_START_SEL(x)                                   (((x)&0x1u)<<6)               /**< Set UT2StartSel in register */
#define  GET_UT2_START_SEL(reg)                             (((reg)>>6)&0x1u)             /**< Get UT2StartSel from register */
#define  UT2_PULSE_CFG_SHIFT                                7                             /**< Shift for UT2PulseCfg */
#define  UT2_PULSE_CFG_MASK                                 0x00000080u                   /**< Mask for UT2PulseCfg */
#define  UT2_PULSE_CFG_BMASK                                0x1u                          /**< Base mask for UT2PulseCfg */
#define  UT2_PULSE_CFG(x)                                   (((x)&0x1u)<<7)               /**< Set UT2PulseCfg in register */
#define  GET_UT2_PULSE_CFG(reg)                             (((reg)>>7)&0x1u)             /**< Get UT2PulseCfg from register */
#define  UT2_AUTO_RESTART_CFG_SHIFT                         8                             /**< Shift for UT2AutoRestartCfg */
#define  UT2_AUTO_RESTART_CFG_MASK                          0x00000100u                   /**< Mask for UT2AutoRestartCfg */
#define  UT2_AUTO_RESTART_CFG_BMASK                         0x1u                          /**< Base mask for UT2AutoRestartCfg */
#define  UT2_AUTO_RESTART_CFG(x)                            (((x)&0x1u)<<8)               /**< Set UT2AutoRestartCfg in register */
#define  GET_UT2_AUTO_RESTART_CFG(reg)                      (((reg)>>8)&0x1u)             /**< Get UT2AutoRestartCfg from register */
#define  UT2_CPT_EVT_SRC_SHIFT                              10                            /**< Shift for UT2CptEvtSrc */
#define  UT2_CPT_EVT_SRC_MASK                               0x00000400u                   /**< Mask for UT2CptEvtSrc */
#define  UT2_CPT_EVT_SRC_BMASK                              0x1u                          /**< Base mask for UT2CptEvtSrc */
#define  UT2_CPT_EVT_SRC(x)                                 (((x)&0x1u)<<10)              /**< Set UT2CptEvtSrc in register */
#define  GET_UT2_CPT_EVT_SRC(reg)                           (((reg)>>10)&0x1u)            /**< Get UT2CptEvtSrc from register */
#define  UT2_CAPT_EDG_SHIFT                                 11                            /**< Shift for UT2CaptEdg */
#define  UT2_CAPT_EDG_MASK                                  0x00001800u                   /**< Mask for UT2CaptEdg */
#define  UT2_CAPT_EDG_BMASK                                 0x3u                          /**< Base mask for UT2CaptEdg */
#define  UT2_CAPT_EDG(x)                                    (((x)&0x3u)<<11)              /**< Set UT2CaptEdg in register */
#define  GET_UT2_CAPT_EDG(reg)                              (((reg)>>11)&0x3u)            /**< Get UT2CaptEdg from register */
#define  UT2_ACT_COMPARE_SHIFT                              13                            /**< Shift for UT2ActCompare */
#define  UT2_ACT_COMPARE_MASK                               0x00006000u                   /**< Mask for UT2ActCompare */
#define  UT2_ACT_COMPARE_BMASK                              0x3u                          /**< Base mask for UT2ActCompare */
#define  UT2_ACT_COMPARE(x)                                 (((x)&0x3u)<<13)              /**< Set UT2ActCompare in register */
#define  GET_UT2_ACT_COMPARE(reg)                           (((reg)>>13)&0x3u)            /**< Get UT2ActCompare from register */
#define  UT2_ACT_LIMIT_SHIFT                                15                            /**< Shift for UT2ActLimit */
#define  UT2_ACT_LIMIT_MASK                                 0x00018000u                   /**< Mask for UT2ActLimit */
#define  UT2_ACT_LIMIT_BMASK                                0x3u                          /**< Base mask for UT2ActLimit */
#define  UT2_ACT_LIMIT(x)                                   (((x)&0x3u)<<15)              /**< Set UT2ActLimit in register */
#define  GET_UT2_ACT_LIMIT(reg)                             (((reg)>>15)&0x3u)            /**< Get UT2ActLimit from register */
/** @} */


/**
 * @name RegUniTimer2Ctrl
 * @{
 */
// RegUniTimer2Ctrl.r32
#define  REG_UNI_TIMER2_CTRL_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUniTimer2Ctrl */
#define  REG_UNI_TIMER2_CTRL_MASK                           0x00070F07u                   /**< Mask for RegUniTimer2Ctrl */

#define  UT2_ENABLE_SHIFT                                   0                             /**< Shift for UT2Enable */
#define  UT2_ENABLE_MASK                                    0x00000001u                   /**< Mask for UT2Enable */
#define  UT2_ENABLE_BMASK                                   0x1u                          /**< Base mask for UT2Enable */
#define  UT2_ENABLE(x)                                      (((x)&0x1u)<<0)               /**< Set UT2Enable in register */
#define  GET_UT2_ENABLE(reg)                                (((reg)>>0)&0x1u)             /**< Get UT2Enable from register */
#define  UT2_START_SW_SHIFT                                 1                             /**< Shift for UT2StartSW */
#define  UT2_START_SW_MASK                                  0x00000002u                   /**< Mask for UT2StartSW */
#define  UT2_START_SW_BMASK                                 0x1u                          /**< Base mask for UT2StartSW */
#define  UT2_START_SW(x)                                    (((x)&0x1u)<<1)               /**< Set UT2StartSW in register */
#define  GET_UT2_START_SW(reg)                              (((reg)>>1)&0x1u)             /**< Get UT2StartSW from register */
#define  UT2_CAPTURE_SW_SHIFT                               2                             /**< Shift for UT2CaptureSW */
#define  UT2_CAPTURE_SW_MASK                                0x00000004u                   /**< Mask for UT2CaptureSW */
#define  UT2_CAPTURE_SW_BMASK                               0x1u                          /**< Base mask for UT2CaptureSW */
#define  UT2_CAPTURE_SW(x)                                  (((x)&0x1u)<<2)               /**< Set UT2CaptureSW in register */
#define  GET_UT2_CAPTURE_SW(reg)                            (((reg)>>2)&0x1u)             /**< Get UT2CaptureSW from register */
#define  UT2_OUT_EN0_SHIFT                                  8                             /**< Shift for UT2OutEn0 */
#define  UT2_OUT_EN0_MASK                                   0x00000100u                   /**< Mask for UT2OutEn0 */
#define  UT2_OUT_EN0_BMASK                                  0x1u                          /**< Base mask for UT2OutEn0 */
#define  UT2_OUT_EN0(x)                                     (((x)&0x1u)<<8)               /**< Set UT2OutEn0 in register */
#define  GET_UT2_OUT_EN0(reg)                               (((reg)>>8)&0x1u)             /**< Get UT2OutEn0 from register */
#define  UT2_OUT_EN1_SHIFT                                  9                             /**< Shift for UT2OutEn1 */
#define  UT2_OUT_EN1_MASK                                   0x00000200u                   /**< Mask for UT2OutEn1 */
#define  UT2_OUT_EN1_BMASK                                  0x1u                          /**< Base mask for UT2OutEn1 */
#define  UT2_OUT_EN1(x)                                     (((x)&0x1u)<<9)               /**< Set UT2OutEn1 in register */
#define  GET_UT2_OUT_EN1(reg)                               (((reg)>>9)&0x1u)             /**< Get UT2OutEn1 from register */
#define  UT2_OUT_EN2_SHIFT                                  10                            /**< Shift for UT2OutEn2 */
#define  UT2_OUT_EN2_MASK                                   0x00000400u                   /**< Mask for UT2OutEn2 */
#define  UT2_OUT_EN2_BMASK                                  0x1u                          /**< Base mask for UT2OutEn2 */
#define  UT2_OUT_EN2(x)                                     (((x)&0x1u)<<10)              /**< Set UT2OutEn2 in register */
#define  GET_UT2_OUT_EN2(reg)                               (((reg)>>10)&0x1u)            /**< Get UT2OutEn2 from register */
#define  UT2_OUT_EN3_SHIFT                                  11                            /**< Shift for UT2OutEn3 */
#define  UT2_OUT_EN3_MASK                                   0x00000800u                   /**< Mask for UT2OutEn3 */
#define  UT2_OUT_EN3_BMASK                                  0x1u                          /**< Base mask for UT2OutEn3 */
#define  UT2_OUT_EN3(x)                                     (((x)&0x1u)<<11)              /**< Set UT2OutEn3 in register */
#define  GET_UT2_OUT_EN3(reg)                               (((reg)>>11)&0x1u)            /**< Get UT2OutEn3 from register */
#define  UT2_CLEAR_SHIFT                                    16                            /**< Shift for UT2Clear */
#define  UT2_CLEAR_MASK                                     0x00010000u                   /**< Mask for UT2Clear */
#define  UT2_CLEAR_BMASK                                    0x1u                          /**< Base mask for UT2Clear */
#define  UT2_CLEAR(x)                                       (((x)&0x1u)<<16)              /**< Set UT2Clear in register */
#define  GET_UT2_CLEAR(reg)                                 (((reg)>>16)&0x1u)            /**< Get UT2Clear from register */
#define  UT2_CLEAR_OUT_SHIFT                                17                            /**< Shift for UT2ClearOut */
#define  UT2_CLEAR_OUT_MASK                                 0x00020000u                   /**< Mask for UT2ClearOut */
#define  UT2_CLEAR_OUT_BMASK                                0x1u                          /**< Base mask for UT2ClearOut */
#define  UT2_CLEAR_OUT(x)                                   (((x)&0x1u)<<17)              /**< Set UT2ClearOut in register */
#define  GET_UT2_CLEAR_OUT(reg)                             (((reg)>>17)&0x1u)            /**< Get UT2ClearOut from register */
#define  UT2_SET_OUT_SHIFT                                  18                            /**< Shift for UT2SetOut */
#define  UT2_SET_OUT_MASK                                   0x00040000u                   /**< Mask for UT2SetOut */
#define  UT2_SET_OUT_BMASK                                  0x1u                          /**< Base mask for UT2SetOut */
#define  UT2_SET_OUT(x)                                     (((x)&0x1u)<<18)              /**< Set UT2SetOut in register */
#define  GET_UT2_SET_OUT(reg)                               (((reg)>>18)&0x1u)            /**< Get UT2SetOut from register */
/** @} */


/**
 * @name RegUniTimer2Stat
 * @{
 */
// RegUniTimer2Stat.r32
#define  REG_UNI_TIMER2_STAT_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUniTimer2Stat */
#define  REG_UNI_TIMER2_STAT_MASK                           0x00000001u                   /**< Mask for RegUniTimer2Stat */

#define  UT2_RUN_STAT_SHIFT                                 0                             /**< Shift for UT2RunStat */
#define  UT2_RUN_STAT_MASK                                  0x00000001u                   /**< Mask for UT2RunStat */
#define  UT2_RUN_STAT_BMASK                                 0x1u                          /**< Base mask for UT2RunStat */
#define  UT2_RUN_STAT(x)                                    (((x)&0x1u)<<0)               /**< Set UT2RunStat in register */
#define  GET_UT2_RUN_STAT(reg)                              (((reg)>>0)&0x1u)             /**< Get UT2RunStat from register */
/** @} */


/**
 * @name RegUniTimer2Count
 * @{
 */
// RegUniTimer2Count.r32
#define  REG_UNI_TIMER2_COUNT_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUniTimer2Count */
#define  REG_UNI_TIMER2_COUNT_MASK                          0xFFFFFFFFu                   /**< Mask for RegUniTimer2Count */

#define  UT2_COUNT_SHIFT                                    0                             /**< Shift for UT2Count */
#define  UT2_COUNT_MASK                                     0xFFFFFFFFu                   /**< Mask for UT2Count */
#define  UT2_COUNT_BMASK                                    0xFFFFFFFFu                   /**< Base mask for UT2Count */
#define  UT2_COUNT(x)                                       (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Count in register */
#define  GET_UT2_COUNT(reg)                                 (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Count from register */
/** @} */


/**
 * @name RegUniTimer2Limit
 * @{
 */
// RegUniTimer2Limit.r32
#define  REG_UNI_TIMER2_LIMIT_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUniTimer2Limit */
#define  REG_UNI_TIMER2_LIMIT_MASK                          0xFFFFFFFFu                   /**< Mask for RegUniTimer2Limit */

#define  UT2_LIMIT_SHIFT                                    0                             /**< Shift for UT2Limit */
#define  UT2_LIMIT_MASK                                     0xFFFFFFFFu                   /**< Mask for UT2Limit */
#define  UT2_LIMIT_BMASK                                    0xFFFFFFFFu                   /**< Base mask for UT2Limit */
#define  UT2_LIMIT(x)                                       (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Limit in register */
#define  GET_UT2_LIMIT(reg)                                 (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Limit from register */
/** @} */


/**
 * @name RegUniTimer2Compare0
 * @{
 */
// RegUniTimer2Compare0.r32
#define  REG_UNI_TIMER2_COMPARE0_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer2Compare0 */
#define  REG_UNI_TIMER2_COMPARE0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer2Compare0 */

#define  UT2_COMPARE0_SHIFT                                 0                             /**< Shift for UT2Compare0 */
#define  UT2_COMPARE0_MASK                                  0xFFFFFFFFu                   /**< Mask for UT2Compare0 */
#define  UT2_COMPARE0_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT2Compare0 */
#define  UT2_COMPARE0(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Compare0 in register */
#define  GET_UT2_COMPARE0(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Compare0 from register */
/** @} */


/**
 * @name RegUniTimer2Compare1
 * @{
 */
// RegUniTimer2Compare1.r32
#define  REG_UNI_TIMER2_COMPARE1_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer2Compare1 */
#define  REG_UNI_TIMER2_COMPARE1_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer2Compare1 */

#define  UT2_COMPARE1_SHIFT                                 0                             /**< Shift for UT2Compare1 */
#define  UT2_COMPARE1_MASK                                  0xFFFFFFFFu                   /**< Mask for UT2Compare1 */
#define  UT2_COMPARE1_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT2Compare1 */
#define  UT2_COMPARE1(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Compare1 in register */
#define  GET_UT2_COMPARE1(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Compare1 from register */
/** @} */


/**
 * @name RegUniTimer2Compare2
 * @{
 */
// RegUniTimer2Compare2.r32
#define  REG_UNI_TIMER2_COMPARE2_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer2Compare2 */
#define  REG_UNI_TIMER2_COMPARE2_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer2Compare2 */

#define  UT2_COMPARE2_SHIFT                                 0                             /**< Shift for UT2Compare2 */
#define  UT2_COMPARE2_MASK                                  0xFFFFFFFFu                   /**< Mask for UT2Compare2 */
#define  UT2_COMPARE2_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT2Compare2 */
#define  UT2_COMPARE2(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Compare2 in register */
#define  GET_UT2_COMPARE2(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Compare2 from register */
/** @} */


/**
 * @name RegUniTimer2Compare3
 * @{
 */
// RegUniTimer2Compare3.r32
#define  REG_UNI_TIMER2_COMPARE3_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer2Compare3 */
#define  REG_UNI_TIMER2_COMPARE3_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer2Compare3 */

#define  UT2_COMPARE3_SHIFT                                 0                             /**< Shift for UT2Compare3 */
#define  UT2_COMPARE3_MASK                                  0xFFFFFFFFu                   /**< Mask for UT2Compare3 */
#define  UT2_COMPARE3_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT2Compare3 */
#define  UT2_COMPARE3(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Compare3 in register */
#define  GET_UT2_COMPARE3(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Compare3 from register */
/** @} */


/**
 * @name RegUniTimer2Capture
 * @{
 */
// RegUniTimer2Capture.r32
#define  REG_UNI_TIMER2_CAPTURE_RESET_VALUE                 0x00000000u                   /**< Reset value of RegUniTimer2Capture */
#define  REG_UNI_TIMER2_CAPTURE_MASK                        0xFFFFFFFFu                   /**< Mask for RegUniTimer2Capture */

#define  UT2_CAPTURE_SHIFT                                  0                             /**< Shift for UT2Capture */
#define  UT2_CAPTURE_MASK                                   0xFFFFFFFFu                   /**< Mask for UT2Capture */
#define  UT2_CAPTURE_BMASK                                  0xFFFFFFFFu                   /**< Base mask for UT2Capture */
#define  UT2_CAPTURE(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set UT2Capture in register */
#define  GET_UT2_CAPTURE(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT2Capture from register */
/** @} */


/**
 * @name RegUniTimer3Cfg
 * @{
 */
// RegUniTimer3Cfg.r32
#define  REG_UNI_TIMER3_CFG_RESET_VALUE                     0x00000000u                   /**< Reset value of RegUniTimer3Cfg */
#define  REG_UNI_TIMER3_CFG_MASK                            0x0001FDE7u                   /**< Mask for RegUniTimer3Cfg */

#define  UT3_PRESCALER_SEL_SHIFT                            0                             /**< Shift for UT3PrescalerSel */
#define  UT3_PRESCALER_SEL_MASK                             0x00000007u                   /**< Mask for UT3PrescalerSel */
#define  UT3_PRESCALER_SEL_BMASK                            0x7u                          /**< Base mask for UT3PrescalerSel */
#define  UT3_PRESCALER_SEL(x)                               (((x)&0x7u)<<0)               /**< Set UT3PrescalerSel in register */
#define  GET_UT3_PRESCALER_SEL(reg)                         (((reg)>>0)&0x7u)             /**< Get UT3PrescalerSel from register */
#define  UT3_CLK_SEL_SHIFT                                  5                             /**< Shift for UT3ClkSel */
#define  UT3_CLK_SEL_MASK                                   0x00000020u                   /**< Mask for UT3ClkSel */
#define  UT3_CLK_SEL_BMASK                                  0x1u                          /**< Base mask for UT3ClkSel */
#define  UT3_CLK_SEL(x)                                     (((x)&0x1u)<<5)               /**< Set UT3ClkSel in register */
#define  GET_UT3_CLK_SEL(reg)                               (((reg)>>5)&0x1u)             /**< Get UT3ClkSel from register */
#define  UT3_START_SEL_SHIFT                                6                             /**< Shift for UT3StartSel */
#define  UT3_START_SEL_MASK                                 0x00000040u                   /**< Mask for UT3StartSel */
#define  UT3_START_SEL_BMASK                                0x1u                          /**< Base mask for UT3StartSel */
#define  UT3_START_SEL(x)                                   (((x)&0x1u)<<6)               /**< Set UT3StartSel in register */
#define  GET_UT3_START_SEL(reg)                             (((reg)>>6)&0x1u)             /**< Get UT3StartSel from register */
#define  UT3_PULSE_CFG_SHIFT                                7                             /**< Shift for UT3PulseCfg */
#define  UT3_PULSE_CFG_MASK                                 0x00000080u                   /**< Mask for UT3PulseCfg */
#define  UT3_PULSE_CFG_BMASK                                0x1u                          /**< Base mask for UT3PulseCfg */
#define  UT3_PULSE_CFG(x)                                   (((x)&0x1u)<<7)               /**< Set UT3PulseCfg in register */
#define  GET_UT3_PULSE_CFG(reg)                             (((reg)>>7)&0x1u)             /**< Get UT3PulseCfg from register */
#define  UT3_AUTO_RESTART_CFG_SHIFT                         8                             /**< Shift for UT3AutoRestartCfg */
#define  UT3_AUTO_RESTART_CFG_MASK                          0x00000100u                   /**< Mask for UT3AutoRestartCfg */
#define  UT3_AUTO_RESTART_CFG_BMASK                         0x1u                          /**< Base mask for UT3AutoRestartCfg */
#define  UT3_AUTO_RESTART_CFG(x)                            (((x)&0x1u)<<8)               /**< Set UT3AutoRestartCfg in register */
#define  GET_UT3_AUTO_RESTART_CFG(reg)                      (((reg)>>8)&0x1u)             /**< Get UT3AutoRestartCfg from register */
#define  UT3_CPT_EVT_SRC_SHIFT                              10                            /**< Shift for UT3CptEvtSrc */
#define  UT3_CPT_EVT_SRC_MASK                               0x00000400u                   /**< Mask for UT3CptEvtSrc */
#define  UT3_CPT_EVT_SRC_BMASK                              0x1u                          /**< Base mask for UT3CptEvtSrc */
#define  UT3_CPT_EVT_SRC(x)                                 (((x)&0x1u)<<10)              /**< Set UT3CptEvtSrc in register */
#define  GET_UT3_CPT_EVT_SRC(reg)                           (((reg)>>10)&0x1u)            /**< Get UT3CptEvtSrc from register */
#define  UT3_CAPT_EDG_SHIFT                                 11                            /**< Shift for UT3CaptEdg */
#define  UT3_CAPT_EDG_MASK                                  0x00001800u                   /**< Mask for UT3CaptEdg */
#define  UT3_CAPT_EDG_BMASK                                 0x3u                          /**< Base mask for UT3CaptEdg */
#define  UT3_CAPT_EDG(x)                                    (((x)&0x3u)<<11)              /**< Set UT3CaptEdg in register */
#define  GET_UT3_CAPT_EDG(reg)                              (((reg)>>11)&0x3u)            /**< Get UT3CaptEdg from register */
#define  UT3_ACT_COMPARE_SHIFT                              13                            /**< Shift for UT3ActCompare */
#define  UT3_ACT_COMPARE_MASK                               0x00006000u                   /**< Mask for UT3ActCompare */
#define  UT3_ACT_COMPARE_BMASK                              0x3u                          /**< Base mask for UT3ActCompare */
#define  UT3_ACT_COMPARE(x)                                 (((x)&0x3u)<<13)              /**< Set UT3ActCompare in register */
#define  GET_UT3_ACT_COMPARE(reg)                           (((reg)>>13)&0x3u)            /**< Get UT3ActCompare from register */
#define  UT3_ACT_LIMIT_SHIFT                                15                            /**< Shift for UT3ActLimit */
#define  UT3_ACT_LIMIT_MASK                                 0x00018000u                   /**< Mask for UT3ActLimit */
#define  UT3_ACT_LIMIT_BMASK                                0x3u                          /**< Base mask for UT3ActLimit */
#define  UT3_ACT_LIMIT(x)                                   (((x)&0x3u)<<15)              /**< Set UT3ActLimit in register */
#define  GET_UT3_ACT_LIMIT(reg)                             (((reg)>>15)&0x3u)            /**< Get UT3ActLimit from register */
/** @} */


/**
 * @name RegUniTimer3Ctrl
 * @{
 */
// RegUniTimer3Ctrl.r32
#define  REG_UNI_TIMER3_CTRL_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUniTimer3Ctrl */
#define  REG_UNI_TIMER3_CTRL_MASK                           0x00070F07u                   /**< Mask for RegUniTimer3Ctrl */

#define  UT3_ENABLE_SHIFT                                   0                             /**< Shift for UT3Enable */
#define  UT3_ENABLE_MASK                                    0x00000001u                   /**< Mask for UT3Enable */
#define  UT3_ENABLE_BMASK                                   0x1u                          /**< Base mask for UT3Enable */
#define  UT3_ENABLE(x)                                      (((x)&0x1u)<<0)               /**< Set UT3Enable in register */
#define  GET_UT3_ENABLE(reg)                                (((reg)>>0)&0x1u)             /**< Get UT3Enable from register */
#define  UT3_START_SW_SHIFT                                 1                             /**< Shift for UT3StartSW */
#define  UT3_START_SW_MASK                                  0x00000002u                   /**< Mask for UT3StartSW */
#define  UT3_START_SW_BMASK                                 0x1u                          /**< Base mask for UT3StartSW */
#define  UT3_START_SW(x)                                    (((x)&0x1u)<<1)               /**< Set UT3StartSW in register */
#define  GET_UT3_START_SW(reg)                              (((reg)>>1)&0x1u)             /**< Get UT3StartSW from register */
#define  UT3_CAPTURE_SW_SHIFT                               2                             /**< Shift for UT3CaptureSW */
#define  UT3_CAPTURE_SW_MASK                                0x00000004u                   /**< Mask for UT3CaptureSW */
#define  UT3_CAPTURE_SW_BMASK                               0x1u                          /**< Base mask for UT3CaptureSW */
#define  UT3_CAPTURE_SW(x)                                  (((x)&0x1u)<<2)               /**< Set UT3CaptureSW in register */
#define  GET_UT3_CAPTURE_SW(reg)                            (((reg)>>2)&0x1u)             /**< Get UT3CaptureSW from register */
#define  UT3_OUT_EN0_SHIFT                                  8                             /**< Shift for UT3OutEn0 */
#define  UT3_OUT_EN0_MASK                                   0x00000100u                   /**< Mask for UT3OutEn0 */
#define  UT3_OUT_EN0_BMASK                                  0x1u                          /**< Base mask for UT3OutEn0 */
#define  UT3_OUT_EN0(x)                                     (((x)&0x1u)<<8)               /**< Set UT3OutEn0 in register */
#define  GET_UT3_OUT_EN0(reg)                               (((reg)>>8)&0x1u)             /**< Get UT3OutEn0 from register */
#define  UT3_OUT_EN1_SHIFT                                  9                             /**< Shift for UT3OutEn1 */
#define  UT3_OUT_EN1_MASK                                   0x00000200u                   /**< Mask for UT3OutEn1 */
#define  UT3_OUT_EN1_BMASK                                  0x1u                          /**< Base mask for UT3OutEn1 */
#define  UT3_OUT_EN1(x)                                     (((x)&0x1u)<<9)               /**< Set UT3OutEn1 in register */
#define  GET_UT3_OUT_EN1(reg)                               (((reg)>>9)&0x1u)             /**< Get UT3OutEn1 from register */
#define  UT3_OUT_EN2_SHIFT                                  10                            /**< Shift for UT3OutEn2 */
#define  UT3_OUT_EN2_MASK                                   0x00000400u                   /**< Mask for UT3OutEn2 */
#define  UT3_OUT_EN2_BMASK                                  0x1u                          /**< Base mask for UT3OutEn2 */
#define  UT3_OUT_EN2(x)                                     (((x)&0x1u)<<10)              /**< Set UT3OutEn2 in register */
#define  GET_UT3_OUT_EN2(reg)                               (((reg)>>10)&0x1u)            /**< Get UT3OutEn2 from register */
#define  UT3_OUT_EN3_SHIFT                                  11                            /**< Shift for UT3OutEn3 */
#define  UT3_OUT_EN3_MASK                                   0x00000800u                   /**< Mask for UT3OutEn3 */
#define  UT3_OUT_EN3_BMASK                                  0x1u                          /**< Base mask for UT3OutEn3 */
#define  UT3_OUT_EN3(x)                                     (((x)&0x1u)<<11)              /**< Set UT3OutEn3 in register */
#define  GET_UT3_OUT_EN3(reg)                               (((reg)>>11)&0x1u)            /**< Get UT3OutEn3 from register */
#define  UT3_CLEAR_SHIFT                                    16                            /**< Shift for UT3Clear */
#define  UT3_CLEAR_MASK                                     0x00010000u                   /**< Mask for UT3Clear */
#define  UT3_CLEAR_BMASK                                    0x1u                          /**< Base mask for UT3Clear */
#define  UT3_CLEAR(x)                                       (((x)&0x1u)<<16)              /**< Set UT3Clear in register */
#define  GET_UT3_CLEAR(reg)                                 (((reg)>>16)&0x1u)            /**< Get UT3Clear from register */
#define  UT3_CLEAR_OUT_SHIFT                                17                            /**< Shift for UT3ClearOut */
#define  UT3_CLEAR_OUT_MASK                                 0x00020000u                   /**< Mask for UT3ClearOut */
#define  UT3_CLEAR_OUT_BMASK                                0x1u                          /**< Base mask for UT3ClearOut */
#define  UT3_CLEAR_OUT(x)                                   (((x)&0x1u)<<17)              /**< Set UT3ClearOut in register */
#define  GET_UT3_CLEAR_OUT(reg)                             (((reg)>>17)&0x1u)            /**< Get UT3ClearOut from register */
#define  UT3_SET_OUT_SHIFT                                  18                            /**< Shift for UT3SetOut */
#define  UT3_SET_OUT_MASK                                   0x00040000u                   /**< Mask for UT3SetOut */
#define  UT3_SET_OUT_BMASK                                  0x1u                          /**< Base mask for UT3SetOut */
#define  UT3_SET_OUT(x)                                     (((x)&0x1u)<<18)              /**< Set UT3SetOut in register */
#define  GET_UT3_SET_OUT(reg)                               (((reg)>>18)&0x1u)            /**< Get UT3SetOut from register */
/** @} */


/**
 * @name RegUniTimer3Stat
 * @{
 */
// RegUniTimer3Stat.r32
#define  REG_UNI_TIMER3_STAT_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUniTimer3Stat */
#define  REG_UNI_TIMER3_STAT_MASK                           0x00000001u                   /**< Mask for RegUniTimer3Stat */

#define  UT3_RUN_STAT_SHIFT                                 0                             /**< Shift for UT3RunStat */
#define  UT3_RUN_STAT_MASK                                  0x00000001u                   /**< Mask for UT3RunStat */
#define  UT3_RUN_STAT_BMASK                                 0x1u                          /**< Base mask for UT3RunStat */
#define  UT3_RUN_STAT(x)                                    (((x)&0x1u)<<0)               /**< Set UT3RunStat in register */
#define  GET_UT3_RUN_STAT(reg)                              (((reg)>>0)&0x1u)             /**< Get UT3RunStat from register */
/** @} */


/**
 * @name RegUniTimer3Count
 * @{
 */
// RegUniTimer3Count.r32
#define  REG_UNI_TIMER3_COUNT_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUniTimer3Count */
#define  REG_UNI_TIMER3_COUNT_MASK                          0xFFFFFFFFu                   /**< Mask for RegUniTimer3Count */

#define  UT3_COUNT_SHIFT                                    0                             /**< Shift for UT3Count */
#define  UT3_COUNT_MASK                                     0xFFFFFFFFu                   /**< Mask for UT3Count */
#define  UT3_COUNT_BMASK                                    0xFFFFFFFFu                   /**< Base mask for UT3Count */
#define  UT3_COUNT(x)                                       (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Count in register */
#define  GET_UT3_COUNT(reg)                                 (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Count from register */
/** @} */


/**
 * @name RegUniTimer3Limit
 * @{
 */
// RegUniTimer3Limit.r32
#define  REG_UNI_TIMER3_LIMIT_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUniTimer3Limit */
#define  REG_UNI_TIMER3_LIMIT_MASK                          0xFFFFFFFFu                   /**< Mask for RegUniTimer3Limit */

#define  UT3_LIMIT_SHIFT                                    0                             /**< Shift for UT3Limit */
#define  UT3_LIMIT_MASK                                     0xFFFFFFFFu                   /**< Mask for UT3Limit */
#define  UT3_LIMIT_BMASK                                    0xFFFFFFFFu                   /**< Base mask for UT3Limit */
#define  UT3_LIMIT(x)                                       (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Limit in register */
#define  GET_UT3_LIMIT(reg)                                 (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Limit from register */
/** @} */


/**
 * @name RegUniTimer3Compare0
 * @{
 */
// RegUniTimer3Compare0.r32
#define  REG_UNI_TIMER3_COMPARE0_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer3Compare0 */
#define  REG_UNI_TIMER3_COMPARE0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer3Compare0 */

#define  UT3_COMPARE0_SHIFT                                 0                             /**< Shift for UT3Compare0 */
#define  UT3_COMPARE0_MASK                                  0xFFFFFFFFu                   /**< Mask for UT3Compare0 */
#define  UT3_COMPARE0_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT3Compare0 */
#define  UT3_COMPARE0(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Compare0 in register */
#define  GET_UT3_COMPARE0(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Compare0 from register */
/** @} */


/**
 * @name RegUniTimer3Compare1
 * @{
 */
// RegUniTimer3Compare1.r32
#define  REG_UNI_TIMER3_COMPARE1_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer3Compare1 */
#define  REG_UNI_TIMER3_COMPARE1_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer3Compare1 */

#define  UT3_COMPARE1_SHIFT                                 0                             /**< Shift for UT3Compare1 */
#define  UT3_COMPARE1_MASK                                  0xFFFFFFFFu                   /**< Mask for UT3Compare1 */
#define  UT3_COMPARE1_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT3Compare1 */
#define  UT3_COMPARE1(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Compare1 in register */
#define  GET_UT3_COMPARE1(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Compare1 from register */
/** @} */


/**
 * @name RegUniTimer3Compare2
 * @{
 */
// RegUniTimer3Compare2.r32
#define  REG_UNI_TIMER3_COMPARE2_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer3Compare2 */
#define  REG_UNI_TIMER3_COMPARE2_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer3Compare2 */

#define  UT3_COMPARE2_SHIFT                                 0                             /**< Shift for UT3Compare2 */
#define  UT3_COMPARE2_MASK                                  0xFFFFFFFFu                   /**< Mask for UT3Compare2 */
#define  UT3_COMPARE2_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT3Compare2 */
#define  UT3_COMPARE2(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Compare2 in register */
#define  GET_UT3_COMPARE2(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Compare2 from register */
/** @} */


/**
 * @name RegUniTimer3Compare3
 * @{
 */
// RegUniTimer3Compare3.r32
#define  REG_UNI_TIMER3_COMPARE3_RESET_VALUE                0x00000000u                   /**< Reset value of RegUniTimer3Compare3 */
#define  REG_UNI_TIMER3_COMPARE3_MASK                       0xFFFFFFFFu                   /**< Mask for RegUniTimer3Compare3 */

#define  UT3_COMPARE3_SHIFT                                 0                             /**< Shift for UT3Compare3 */
#define  UT3_COMPARE3_MASK                                  0xFFFFFFFFu                   /**< Mask for UT3Compare3 */
#define  UT3_COMPARE3_BMASK                                 0xFFFFFFFFu                   /**< Base mask for UT3Compare3 */
#define  UT3_COMPARE3(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Compare3 in register */
#define  GET_UT3_COMPARE3(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Compare3 from register */
/** @} */


/**
 * @name RegUniTimer3Capture
 * @{
 */
// RegUniTimer3Capture.r32
#define  REG_UNI_TIMER3_CAPTURE_RESET_VALUE                 0x00000000u                   /**< Reset value of RegUniTimer3Capture */
#define  REG_UNI_TIMER3_CAPTURE_MASK                        0xFFFFFFFFu                   /**< Mask for RegUniTimer3Capture */

#define  UT3_CAPTURE_SHIFT                                  0                             /**< Shift for UT3Capture */
#define  UT3_CAPTURE_MASK                                   0xFFFFFFFFu                   /**< Mask for UT3Capture */
#define  UT3_CAPTURE_BMASK                                  0xFFFFFFFFu                   /**< Base mask for UT3Capture */
#define  UT3_CAPTURE(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set UT3Capture in register */
#define  GET_UT3_CAPTURE(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get UT3Capture from register */
/** @} */



/** @} End of group UniTim_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_UNI_TIM_H */
