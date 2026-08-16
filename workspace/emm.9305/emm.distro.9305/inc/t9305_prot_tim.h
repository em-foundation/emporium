////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_prot_tim.h
///
/// @project    T9305
///
/// @brief      Protocol Timer register and bit field definitions
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

#ifndef _T9305_PROT_TIM_H
#define _T9305_PROT_TIM_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup ProtTim_Registers Protocol Timer Register Map - registers
 * @{
 ******************************************************************************/


/** Protocol Timer control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PTCtrl1;                                   /**< Protocol Timer control register 1 */
        uint8_t  PTCtrl2;                                   /**< Protocol Timer control register 2 */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegProtTimCtrl_t;


/** Protocol Timer configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PTDivFactor;                               /**< Protocol Timer divider factor */
        uint8_t  PTDivEn;                                   /**< Protocol Timer divider enable */
        uint8_t  PTCfg;                                     /**< Protocol Timer configuration */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegProtTimCfg_t;


/** Protocol Timer counter value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCount_t;


/** Protocol Timer status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimStat_t;


/** Protocol Timer full value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimFullVal_t;


/** Protocol Timer load value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimLoadVal_t;


/** Protocol Timer output compare configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PTCompareEn;                               /**< Protocol Timer output compare enable */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  PTRFTriggerEn;                             /**< Protocol Timer RF trigger enable */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegProtTimCompareCfg_t;


/** Protocol Timer output compare value - channel 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare0_t;


/** Protocol Timer output compare value - channel 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare1_t;


/** Protocol Timer output compare value - channel 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare2_t;


/** Protocol Timer output compare value - channel 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare3_t;


/** Protocol Timer output compare value - channel 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare4_t;


/** Protocol Timer output compare value - channel 5 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare5_t;


/** Protocol Timer output compare value - channel 6 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare6_t;


/** Protocol Timer output compare value - channel 7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCompare7_t;


/** Protocol Timer input capture control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PTCaptureSW;                               /**< Protocol Timer input capture SW */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  PTCaptureHW;                               /**< Protocol Timer input capture enable by HW event */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegProtTimCaptureCtrl_t;


/** Protocol Timer HW event synchronizer selection */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimHWEvtSyncSel_t;


/** Protocol Timer input capture HW event selection */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PTCapture0HWEvtSel;                        /**< Protocol Timer input capture HW event selection - channel 0 */
        uint8_t  PTCapture1HWEvtSel;                        /**< Protocol Timer input capture HW event selection - channel 1 */
        uint8_t  PTCapture2HWEvtSel;                        /**< Protocol Timer input capture HW event selection - channel 2 */
        uint8_t  PTCapture3HWEvtSel;                        /**< Protocol Timer input capture HW event selection - channel 3 */
    } regs;
} RegProtTimCaptureHWEvtSel_t;


/** Protocol Timer input capture value - channel 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCapture0_t;


/** Protocol Timer input capture value - channel 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCapture1_t;


/** Protocol Timer input capture value - channel 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCapture2_t;


/** Protocol Timer input capture value - channel 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegProtTimCapture3_t;

/** @} end of group ProtTim_Regs */



/***************************************************************************//**
 * @defgroup ProtTim_RegMap Protocol Timer Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __O   RegProtTimCtrl_t                                  RegProtTimCtrl;               /**< Protocol Timer control */
    __IO  RegProtTimCfg_t                                   RegProtTimCfg;                /**< Protocol Timer configuration */
    __I   RegProtTimCount_t                                 RegProtTimCount;              /**< Protocol Timer counter value */
    __I   RegProtTimStat_t                                  RegProtTimStat;               /**< Protocol Timer status */
    __IO  RegProtTimFullVal_t                               RegProtTimFullVal;            /**< Protocol Timer full value */
    __IO  RegProtTimLoadVal_t                               RegProtTimLoadVal;            /**< Protocol Timer load value */
    __IO  RegProtTimCompareCfg_t                            RegProtTimCompareCfg;         /**< Protocol Timer output compare configuration */
    __IO  RegProtTimCompare0_t                              RegProtTimCompare0;           /**< Protocol Timer output compare value - channel 0 */
    __IO  RegProtTimCompare1_t                              RegProtTimCompare1;           /**< Protocol Timer output compare value - channel 1 */
    __IO  RegProtTimCompare2_t                              RegProtTimCompare2;           /**< Protocol Timer output compare value - channel 2 */
    __IO  RegProtTimCompare3_t                              RegProtTimCompare3;           /**< Protocol Timer output compare value - channel 3 */
    __IO  RegProtTimCompare4_t                              RegProtTimCompare4;           /**< Protocol Timer output compare value - channel 4 */
    __IO  RegProtTimCompare5_t                              RegProtTimCompare5;           /**< Protocol Timer output compare value - channel 5 */
    __IO  RegProtTimCompare6_t                              RegProtTimCompare6;           /**< Protocol Timer output compare value - channel 6 */
    __IO  RegProtTimCompare7_t                              RegProtTimCompare7;           /**< Protocol Timer output compare value - channel 7 */
    __IO  RegProtTimCaptureCtrl_t                           RegProtTimCaptureCtrl;        /**< Protocol Timer input capture control */
    __IO  RegProtTimHWEvtSyncSel_t                          RegProtTimHWEvtSyncSel;       /**< Protocol Timer HW event synchronizer selection */
    __IO  RegProtTimCaptureHWEvtSel_t                       RegProtTimCaptureHWEvtSel;    /**< Protocol Timer input capture HW event selection */
    __I   RegProtTimCapture0_t                              RegProtTimCapture0;           /**< Protocol Timer input capture value - channel 0 */
    __I   RegProtTimCapture1_t                              RegProtTimCapture1;           /**< Protocol Timer input capture value - channel 1 */
    __I   RegProtTimCapture2_t                              RegProtTimCapture2;           /**< Protocol Timer input capture value - channel 2 */
    __I   RegProtTimCapture3_t                              RegProtTimCapture3;           /**< Protocol Timer input capture value - channel 3 */
} ProtTim_RegMap_t;

/** @} end of group ProtTim_RegMap */



/***************************************************************************//**
 * @defgroup ProtTim_BitFields ProtTim bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegProtTimCtrl
 * @{
 */
// RegProtTimCtrl.r32
#define  REG_PROT_TIM_CTRL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegProtTimCtrl */
#define  REG_PROT_TIM_CTRL_MASK                             0x00000F03u                   /**< Mask for RegProtTimCtrl */

#define  PT_START_SHIFT                                     0                             /**< Shift for PTStart */
#define  PT_START_MASK                                      0x00000001u                   /**< Mask for PTStart */
#define  PT_START_BMASK                                     0x1u                          /**< Base mask for PTStart */
#define  PT_START(x)                                        (((x)&0x1u)<<0)               /**< Set PTStart in register */
#define  GET_PT_START(reg)                                  (((reg)>>0)&0x1u)             /**< Get PTStart from register */
#define  PT_STOP_SHIFT                                      1                             /**< Shift for PTStop */
#define  PT_STOP_MASK                                       0x00000002u                   /**< Mask for PTStop */
#define  PT_STOP_BMASK                                      0x1u                          /**< Base mask for PTStop */
#define  PT_STOP(x)                                         (((x)&0x1u)<<1)               /**< Set PTStop in register */
#define  GET_PT_STOP(reg)                                   (((reg)>>1)&0x1u)             /**< Get PTStop from register */
#define  PT_CLEAR_SHIFT                                     8                             /**< Shift for PTClear */
#define  PT_CLEAR_MASK                                      0x00000100u                   /**< Mask for PTClear */
#define  PT_CLEAR_BMASK                                     0x1u                          /**< Base mask for PTClear */
#define  PT_CLEAR(x)                                        (((x)&0x1u)<<8)               /**< Set PTClear in register */
#define  GET_PT_CLEAR(reg)                                  (((reg)>>8)&0x1u)             /**< Get PTClear from register */
#define  PT_LOAD_SHIFT                                      9                             /**< Shift for PTLoad */
#define  PT_LOAD_MASK                                       0x00000200u                   /**< Mask for PTLoad */
#define  PT_LOAD_BMASK                                      0x1u                          /**< Base mask for PTLoad */
#define  PT_LOAD(x)                                         (((x)&0x1u)<<9)               /**< Set PTLoad in register */
#define  GET_PT_LOAD(reg)                                   (((reg)>>9)&0x1u)             /**< Get PTLoad from register */
#define  PT_ADJ_SHIFT                                       10                            /**< Shift for PTAdj */
#define  PT_ADJ_MASK                                        0x00000400u                   /**< Mask for PTAdj */
#define  PT_ADJ_BMASK                                       0x1u                          /**< Base mask for PTAdj */
#define  PT_ADJ(x)                                          (((x)&0x1u)<<10)              /**< Set PTAdj in register */
#define  GET_PT_ADJ(reg)                                    (((reg)>>10)&0x1u)            /**< Get PTAdj from register */
#define  PT_DIV_CLEAR_SHIFT                                 11                            /**< Shift for PTDivClear */
#define  PT_DIV_CLEAR_MASK                                  0x00000800u                   /**< Mask for PTDivClear */
#define  PT_DIV_CLEAR_BMASK                                 0x1u                          /**< Base mask for PTDivClear */
#define  PT_DIV_CLEAR(x)                                    (((x)&0x1u)<<11)              /**< Set PTDivClear in register */
#define  GET_PT_DIV_CLEAR(reg)                              (((reg)>>11)&0x1u)            /**< Get PTDivClear from register */

// RegProtTimCtrl.regs.PTCtrl1
#define  PT_CTRL1_GSHIFT                                    0                             /**< Shift for group PTCtrl1 */
#define  PT_CTRL1_GSIZE                                     8                             /**< Size of group PTCtrl1 */
#define  PT_CTRL1_GMASK                                     0x000000FFu                   /**< Mask for group PTCtrl1 */

#define  PT_START_RSHIFT                                    0                             /**< Shift for PTStart */
#define  PT_START_RMASK                                     0x01u                         /**< Mask for PTStart */
#define  PT_START_RBMASK                                    0x1u                          /**< Base mask for PTStart */
#define  PT_START_R(x)                                      (((x)&0x1u)<<0)               /**< Set PTStart in register */
#define  GET_PT_START_R(reg)                                (((reg)>>0)&0x1u)             /**< Get PTStart from register */
#define  PT_STOP_RSHIFT                                     1                             /**< Shift for PTStop */
#define  PT_STOP_RMASK                                      0x02u                         /**< Mask for PTStop */
#define  PT_STOP_RBMASK                                     0x1u                          /**< Base mask for PTStop */
#define  PT_STOP_R(x)                                       (((x)&0x1u)<<1)               /**< Set PTStop in register */
#define  GET_PT_STOP_R(reg)                                 (((reg)>>1)&0x1u)             /**< Get PTStop from register */

// RegProtTimCtrl.regs.PTCtrl2
#define  PT_CTRL2_GSHIFT                                    8                             /**< Shift for group PTCtrl2 */
#define  PT_CTRL2_GSIZE                                     8                             /**< Size of group PTCtrl2 */
#define  PT_CTRL2_GMASK                                     0x0000FF00u                   /**< Mask for group PTCtrl2 */

#define  PT_CLEAR_RSHIFT                                    0                             /**< Shift for PTClear */
#define  PT_CLEAR_RMASK                                     0x01u                         /**< Mask for PTClear */
#define  PT_CLEAR_RBMASK                                    0x1u                          /**< Base mask for PTClear */
#define  PT_CLEAR_R(x)                                      (((x)&0x1u)<<0)               /**< Set PTClear in register */
#define  GET_PT_CLEAR_R(reg)                                (((reg)>>0)&0x1u)             /**< Get PTClear from register */
#define  PT_LOAD_RSHIFT                                     1                             /**< Shift for PTLoad */
#define  PT_LOAD_RMASK                                      0x02u                         /**< Mask for PTLoad */
#define  PT_LOAD_RBMASK                                     0x1u                          /**< Base mask for PTLoad */
#define  PT_LOAD_R(x)                                       (((x)&0x1u)<<1)               /**< Set PTLoad in register */
#define  GET_PT_LOAD_R(reg)                                 (((reg)>>1)&0x1u)             /**< Get PTLoad from register */
#define  PT_ADJ_RSHIFT                                      2                             /**< Shift for PTAdj */
#define  PT_ADJ_RMASK                                       0x04u                         /**< Mask for PTAdj */
#define  PT_ADJ_RBMASK                                      0x1u                          /**< Base mask for PTAdj */
#define  PT_ADJ_R(x)                                        (((x)&0x1u)<<2)               /**< Set PTAdj in register */
#define  GET_PT_ADJ_R(reg)                                  (((reg)>>2)&0x1u)             /**< Get PTAdj from register */
#define  PT_DIV_CLEAR_RSHIFT                                3                             /**< Shift for PTDivClear */
#define  PT_DIV_CLEAR_RMASK                                 0x08u                         /**< Mask for PTDivClear */
#define  PT_DIV_CLEAR_RBMASK                                0x1u                          /**< Base mask for PTDivClear */
#define  PT_DIV_CLEAR_R(x)                                  (((x)&0x1u)<<3)               /**< Set PTDivClear in register */
#define  GET_PT_DIV_CLEAR_R(reg)                            (((reg)>>3)&0x1u)             /**< Get PTDivClear from register */
/** @} */


/**
 * @name RegProtTimCfg
 * @{
 */
// RegProtTimCfg.r32
#define  REG_PROT_TIM_CFG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegProtTimCfg */
#define  REG_PROT_TIM_CFG_MASK                              0x000301FFu                   /**< Mask for RegProtTimCfg */

#define  PT_DIV_FACTOR_SHIFT                                0                             /**< Shift for PTDivFactor */
#define  PT_DIV_FACTOR_MASK                                 0x000000FFu                   /**< Mask for PTDivFactor */
#define  PT_DIV_FACTOR_BMASK                                0xFFu                         /**< Base mask for PTDivFactor */
#define  PT_DIV_FACTOR(x)                                   (((x)&0xFFu)<<0)              /**< Set PTDivFactor in register */
#define  GET_PT_DIV_FACTOR(reg)                             (((reg)>>0)&0xFFu)            /**< Get PTDivFactor from register */
#define  PT_DIV_EN_SHIFT                                    8                             /**< Shift for PTDivEn */
#define  PT_DIV_EN_MASK                                     0x00000100u                   /**< Mask for PTDivEn */
#define  PT_DIV_EN_BMASK                                    0x1u                          /**< Base mask for PTDivEn */
#define  PT_DIV_EN(x)                                       (((x)&0x1u)<<8)               /**< Set PTDivEn in register */
#define  GET_PT_DIV_EN(reg)                                 (((reg)>>8)&0x1u)             /**< Get PTDivEn from register */
#define  PT_AUTO_RELOAD_SHIFT                               16                            /**< Shift for PTAutoReload */
#define  PT_AUTO_RELOAD_MASK                                0x00010000u                   /**< Mask for PTAutoReload */
#define  PT_AUTO_RELOAD_BMASK                               0x1u                          /**< Base mask for PTAutoReload */
#define  PT_AUTO_RELOAD(x)                                  (((x)&0x1u)<<16)              /**< Set PTAutoReload in register */
#define  GET_PT_AUTO_RELOAD(reg)                            (((reg)>>16)&0x1u)            /**< Get PTAutoReload from register */
#define  PT_SYNC_SHIFT                                      17                            /**< Shift for PTSync */
#define  PT_SYNC_MASK                                       0x00020000u                   /**< Mask for PTSync */
#define  PT_SYNC_BMASK                                      0x1u                          /**< Base mask for PTSync */
#define  PT_SYNC(x)                                         (((x)&0x1u)<<17)              /**< Set PTSync in register */
#define  GET_PT_SYNC(reg)                                   (((reg)>>17)&0x1u)            /**< Get PTSync from register */

// RegProtTimCfg.regs.PTDivFactor
#define  PT_DIV_FACTOR_GSHIFT                               0                             /**< Shift for group PTDivFactor */
#define  PT_DIV_FACTOR_GSIZE                                8                             /**< Size of group PTDivFactor */
#define  PT_DIV_FACTOR_GMASK                                0x000000FFu                   /**< Mask for group PTDivFactor */

#define  PT_DIV_FACTOR_RSHIFT                               0                             /**< Shift for PTDivFactor */
#define  PT_DIV_FACTOR_RMASK                                0xFFu                         /**< Mask for PTDivFactor */
#define  PT_DIV_FACTOR_RBMASK                               0xFFu                         /**< Base mask for PTDivFactor */
#define  PT_DIV_FACTOR_R(x)                                 (((x)&0xFFu)<<0)              /**< Set PTDivFactor in register */
#define  GET_PT_DIV_FACTOR_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get PTDivFactor from register */

// RegProtTimCfg.regs.PTDivEn
#define  PT_DIV_EN_GSHIFT                                   8                             /**< Shift for group PTDivEn */
#define  PT_DIV_EN_GSIZE                                    8                             /**< Size of group PTDivEn */
#define  PT_DIV_EN_GMASK                                    0x0000FF00u                   /**< Mask for group PTDivEn */

#define  PT_DIV_EN_RSHIFT                                   0                             /**< Shift for PTDivEn */
#define  PT_DIV_EN_RMASK                                    0x01u                         /**< Mask for PTDivEn */
#define  PT_DIV_EN_RBMASK                                   0x1u                          /**< Base mask for PTDivEn */
#define  PT_DIV_EN_R(x)                                     (((x)&0x1u)<<0)               /**< Set PTDivEn in register */
#define  GET_PT_DIV_EN_R(reg)                               (((reg)>>0)&0x1u)             /**< Get PTDivEn from register */

// RegProtTimCfg.regs.PTCfg
#define  PT_CFG_GSHIFT                                      16                            /**< Shift for group PTCfg */
#define  PT_CFG_GSIZE                                       8                             /**< Size of group PTCfg */
#define  PT_CFG_GMASK                                       0x00FF0000u                   /**< Mask for group PTCfg */

#define  PT_AUTO_RELOAD_RSHIFT                              0                             /**< Shift for PTAutoReload */
#define  PT_AUTO_RELOAD_RMASK                               0x01u                         /**< Mask for PTAutoReload */
#define  PT_AUTO_RELOAD_RBMASK                              0x1u                          /**< Base mask for PTAutoReload */
#define  PT_AUTO_RELOAD_R(x)                                (((x)&0x1u)<<0)               /**< Set PTAutoReload in register */
#define  GET_PT_AUTO_RELOAD_R(reg)                          (((reg)>>0)&0x1u)             /**< Get PTAutoReload from register */
#define  PT_SYNC_RSHIFT                                     1                             /**< Shift for PTSync */
#define  PT_SYNC_RMASK                                      0x02u                         /**< Mask for PTSync */
#define  PT_SYNC_RBMASK                                     0x1u                          /**< Base mask for PTSync */
#define  PT_SYNC_R(x)                                       (((x)&0x1u)<<1)               /**< Set PTSync in register */
#define  GET_PT_SYNC_R(reg)                                 (((reg)>>1)&0x1u)             /**< Get PTSync from register */
/** @} */


/**
 * @name RegProtTimCount
 * @{
 */
// RegProtTimCount.r32
#define  REG_PROT_TIM_COUNT_RESET_VALUE                     0x00000000u                   /**< Reset value of RegProtTimCount */
#define  REG_PROT_TIM_COUNT_MASK                            0xFFFFFFFFu                   /**< Mask for RegProtTimCount */

#define  PT_COUNT_SHIFT                                     0                             /**< Shift for PTCount */
#define  PT_COUNT_MASK                                      0xFFFFFFFFu                   /**< Mask for PTCount */
#define  PT_COUNT_BMASK                                     0xFFFFFFFFu                   /**< Base mask for PTCount */
#define  PT_COUNT(x)                                        (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCount in register */
#define  GET_PT_COUNT(reg)                                  (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCount from register */
/** @} */


/**
 * @name RegProtTimStat
 * @{
 */
// RegProtTimStat.r32
#define  REG_PROT_TIM_STAT_RESET_VALUE                      0x00000000u                   /**< Reset value of RegProtTimStat */
#define  REG_PROT_TIM_STAT_MASK                             0x00000003u                   /**< Mask for RegProtTimStat */

#define  PT_RUNNING_SHIFT                                   0                             /**< Shift for PTRunning */
#define  PT_RUNNING_MASK                                    0x00000001u                   /**< Mask for PTRunning */
#define  PT_RUNNING_BMASK                                   0x1u                          /**< Base mask for PTRunning */
#define  PT_RUNNING(x)                                      (((x)&0x1u)<<0)               /**< Set PTRunning in register */
#define  GET_PT_RUNNING(reg)                                (((reg)>>0)&0x1u)             /**< Get PTRunning from register */
#define  PT_RUN_REQ_SHIFT                                   1                             /**< Shift for PTRunReq */
#define  PT_RUN_REQ_MASK                                    0x00000002u                   /**< Mask for PTRunReq */
#define  PT_RUN_REQ_BMASK                                   0x1u                          /**< Base mask for PTRunReq */
#define  PT_RUN_REQ(x)                                      (((x)&0x1u)<<1)               /**< Set PTRunReq in register */
#define  GET_PT_RUN_REQ(reg)                                (((reg)>>1)&0x1u)             /**< Get PTRunReq from register */
/** @} */


/**
 * @name RegProtTimFullVal
 * @{
 */
// RegProtTimFullVal.r32
#define  REG_PROT_TIM_FULL_VAL_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimFullVal */
#define  REG_PROT_TIM_FULL_VAL_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimFullVal */

#define  PT_FULL_VAL_SHIFT                                  0                             /**< Shift for PTFullval */
#define  PT_FULL_VAL_MASK                                   0xFFFFFFFFu                   /**< Mask for PTFullval */
#define  PT_FULL_VAL_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTFullval */
#define  PT_FULL_VAL(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTFullval in register */
#define  GET_PT_FULL_VAL(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTFullval from register */
/** @} */


/**
 * @name RegProtTimLoadVal
 * @{
 */
// RegProtTimLoadVal.r32
#define  REG_PROT_TIM_LOAD_VAL_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimLoadVal */
#define  REG_PROT_TIM_LOAD_VAL_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimLoadVal */

#define  PT_LOAD_VAL_SHIFT                                  0                             /**< Shift for PTLoadVal */
#define  PT_LOAD_VAL_MASK                                   0xFFFFFFFFu                   /**< Mask for PTLoadVal */
#define  PT_LOAD_VAL_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTLoadVal */
#define  PT_LOAD_VAL(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTLoadVal in register */
#define  GET_PT_LOAD_VAL(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTLoadVal from register */
/** @} */


/**
 * @name RegProtTimCompareCfg
 * @{
 */
// RegProtTimCompareCfg.r32
#define  REG_PROT_TIM_COMPARE_CFG_RESET_VALUE               0x00000000u                   /**< Reset value of RegProtTimCompareCfg */
#define  REG_PROT_TIM_COMPARE_CFG_MASK                      0x00FF00FFu                   /**< Mask for RegProtTimCompareCfg */

#define  PT_COMPARE_EN_SHIFT                                0                             /**< Shift for PTCompareEn */
#define  PT_COMPARE_EN_MASK                                 0x000000FFu                   /**< Mask for PTCompareEn */
#define  PT_COMPARE_EN_BMASK                                0xFFu                         /**< Base mask for PTCompareEn */
#define  PT_COMPARE_EN(x)                                   (((x)&0xFFu)<<0)              /**< Set PTCompareEn in register */
#define  GET_PT_COMPARE_EN(reg)                             (((reg)>>0)&0xFFu)            /**< Get PTCompareEn from register */
#define  PT_RF_TRIGGER_EN_SHIFT                             16                            /**< Shift for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_MASK                              0x00FF0000u                   /**< Mask for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_BMASK                             0xFFu                         /**< Base mask for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN(x)                                (((x)&0xFFu)<<16)             /**< Set PTRFTriggerEn in register */
#define  GET_PT_RF_TRIGGER_EN(reg)                          (((reg)>>16)&0xFFu)           /**< Get PTRFTriggerEn from register */

// RegProtTimCompareCfg.regs.PTCompareEn
#define  PT_COMPARE_EN_GSHIFT                               0                             /**< Shift for group PTCompareEn */
#define  PT_COMPARE_EN_GSIZE                                8                             /**< Size of group PTCompareEn */
#define  PT_COMPARE_EN_GMASK                                0x000000FFu                   /**< Mask for group PTCompareEn */

#define  PT_COMPARE_EN_RSHIFT                               0                             /**< Shift for PTCompareEn */
#define  PT_COMPARE_EN_RMASK                                0x000000FFu                   /**< Mask for PTCompareEn */
#define  PT_COMPARE_EN_RBMASK                               0xFFu                         /**< Base mask for PTCompareEn */
#define  PT_COMPARE_EN_R(x)                                 (((x)&0xFFu)<<0)              /**< Set PTCompareEn in register */
#define  GET_PT_COMPARE_EN_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get PTCompareEn from register */

// RegProtTimCompareCfg.regs.PTRFTriggerEn
#define  PT_RF_TRIGGER_EN_GSHIFT                            16                            /**< Shift for group PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_GSIZE                             8                             /**< Size of group PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_GMASK                             0x00FF0000u                   /**< Mask for group PTRFTriggerEn */

#define  PT_RF_TRIGGER_EN_RSHIFT                            0                             /**< Shift for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_RMASK                             0x000000FFu                   /**< Mask for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_RBMASK                            0xFFu                         /**< Base mask for PTRFTriggerEn */
#define  PT_RF_TRIGGER_EN_R(x)                              (((x)&0xFFu)<<0)              /**< Set PTRFTriggerEn in register */
#define  GET_PT_RF_TRIGGER_EN_R(reg)                        (((reg)>>0)&0xFFu)            /**< Get PTRFTriggerEn from register */
/** @} */


/**
 * @name RegProtTimCompare0
 * @{
 */
// RegProtTimCompare0.r32
#define  REG_PROT_TIM_COMPARE0_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare0 */
#define  REG_PROT_TIM_COMPARE0_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare0 */

#define  PT_COMPARE0_SHIFT                                  0                             /**< Shift for PTCompare0 */
#define  PT_COMPARE0_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare0 */
#define  PT_COMPARE0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare0 */
#define  PT_COMPARE0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare0 in register */
#define  GET_PT_COMPARE0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare0 from register */
/** @} */


/**
 * @name RegProtTimCompare1
 * @{
 */
// RegProtTimCompare1.r32
#define  REG_PROT_TIM_COMPARE1_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare1 */
#define  REG_PROT_TIM_COMPARE1_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare1 */

#define  PT_COMPARE1_SHIFT                                  0                             /**< Shift for PTCompare1 */
#define  PT_COMPARE1_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare1 */
#define  PT_COMPARE1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare1 */
#define  PT_COMPARE1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare1 in register */
#define  GET_PT_COMPARE1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare1 from register */
/** @} */


/**
 * @name RegProtTimCompare2
 * @{
 */
// RegProtTimCompare2.r32
#define  REG_PROT_TIM_COMPARE2_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare2 */
#define  REG_PROT_TIM_COMPARE2_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare2 */

#define  PT_COMPARE2_SHIFT                                  0                             /**< Shift for PTCompare2 */
#define  PT_COMPARE2_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare2 */
#define  PT_COMPARE2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare2 */
#define  PT_COMPARE2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare2 in register */
#define  GET_PT_COMPARE2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare2 from register */
/** @} */


/**
 * @name RegProtTimCompare3
 * @{
 */
// RegProtTimCompare3.r32
#define  REG_PROT_TIM_COMPARE3_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare3 */
#define  REG_PROT_TIM_COMPARE3_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare3 */

#define  PT_COMPARE3_SHIFT                                  0                             /**< Shift for PTCompare3 */
#define  PT_COMPARE3_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare3 */
#define  PT_COMPARE3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare3 */
#define  PT_COMPARE3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare3 in register */
#define  GET_PT_COMPARE3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare3 from register */
/** @} */


/**
 * @name RegProtTimCompare4
 * @{
 */
// RegProtTimCompare4.r32
#define  REG_PROT_TIM_COMPARE4_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare4 */
#define  REG_PROT_TIM_COMPARE4_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare4 */

#define  PT_COMPARE4_SHIFT                                  0                             /**< Shift for PTCompare4 */
#define  PT_COMPARE4_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare4 */
#define  PT_COMPARE4_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare4 */
#define  PT_COMPARE4(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare4 in register */
#define  GET_PT_COMPARE4(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare4 from register */
/** @} */


/**
 * @name RegProtTimCompare5
 * @{
 */
// RegProtTimCompare5.r32
#define  REG_PROT_TIM_COMPARE5_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare5 */
#define  REG_PROT_TIM_COMPARE5_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare5 */

#define  PT_COMPARE5_SHIFT                                  0                             /**< Shift for PTCompare5 */
#define  PT_COMPARE5_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare5 */
#define  PT_COMPARE5_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare5 */
#define  PT_COMPARE5(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare5 in register */
#define  GET_PT_COMPARE5(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare5 from register */
/** @} */


/**
 * @name RegProtTimCompare6
 * @{
 */
// RegProtTimCompare6.r32
#define  REG_PROT_TIM_COMPARE6_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare6 */
#define  REG_PROT_TIM_COMPARE6_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare6 */

#define  PT_COMPARE6_SHIFT                                  0                             /**< Shift for PTCompare6 */
#define  PT_COMPARE6_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare6 */
#define  PT_COMPARE6_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare6 */
#define  PT_COMPARE6(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare6 in register */
#define  GET_PT_COMPARE6(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare6 from register */
/** @} */


/**
 * @name RegProtTimCompare7
 * @{
 */
// RegProtTimCompare7.r32
#define  REG_PROT_TIM_COMPARE7_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCompare7 */
#define  REG_PROT_TIM_COMPARE7_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCompare7 */

#define  PT_COMPARE7_SHIFT                                  0                             /**< Shift for PTCompare7 */
#define  PT_COMPARE7_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCompare7 */
#define  PT_COMPARE7_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCompare7 */
#define  PT_COMPARE7(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCompare7 in register */
#define  GET_PT_COMPARE7(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCompare7 from register */
/** @} */


/**
 * @name RegProtTimCaptureCtrl
 * @{
 */
// RegProtTimCaptureCtrl.r32
#define  REG_PROT_TIM_CAPTURE_CTRL_RESET_VALUE              0x00000000u                   /**< Reset value of RegProtTimCaptureCtrl */
#define  REG_PROT_TIM_CAPTURE_CTRL_MASK                     0x000F000Fu                   /**< Mask for RegProtTimCaptureCtrl */

#define  PT_CAPTURE_SW_SHIFT                                0                             /**< Shift for PTCaptureSW */
#define  PT_CAPTURE_SW_MASK                                 0x0000000Fu                   /**< Mask for PTCaptureSW */
#define  PT_CAPTURE_SW_BMASK                                0xFu                          /**< Base mask for PTCaptureSW */
#define  PT_CAPTURE_SW(x)                                   (((x)&0xFu)<<0)               /**< Set PTCaptureSW in register */
#define  GET_PT_CAPTURE_SW(reg)                             (((reg)>>0)&0xFu)             /**< Get PTCaptureSW from register */
#define  PT_CAPTURE_HW_SHIFT                                16                            /**< Shift for PTCaptureHW */
#define  PT_CAPTURE_HW_MASK                                 0x000F0000u                   /**< Mask for PTCaptureHW */
#define  PT_CAPTURE_HW_BMASK                                0xFu                          /**< Base mask for PTCaptureHW */
#define  PT_CAPTURE_HW(x)                                   (((x)&0xFu)<<16)              /**< Set PTCaptureHW in register */
#define  GET_PT_CAPTURE_HW(reg)                             (((reg)>>16)&0xFu)            /**< Get PTCaptureHW from register */

// RegProtTimCaptureCtrl.regs.PTCaptureSW
#define  PT_CAPTURE_SW_GSHIFT                               0                             /**< Shift for group PTCaptureSW */
#define  PT_CAPTURE_SW_GSIZE                                8                             /**< Size of group PTCaptureSW */
#define  PT_CAPTURE_SW_GMASK                                0x000000FFu                   /**< Mask for group PTCaptureSW */

#define  PT_CAPTURE_SW_RSHIFT                               0                             /**< Shift for PTCaptureSW */
#define  PT_CAPTURE_SW_RMASK                                0x0000000Fu                   /**< Mask for PTCaptureSW */
#define  PT_CAPTURE_SW_RBMASK                               0xFu                          /**< Base mask for PTCaptureSW */
#define  PT_CAPTURE_SW_R(x)                                 (((x)&0xFu)<<0)               /**< Set PTCaptureSW in register */
#define  GET_PT_CAPTURE_SW_R(reg)                           (((reg)>>0)&0xFu)             /**< Get PTCaptureSW from register */

// RegProtTimCaptureCtrl.regs.PTCaptureHW
#define  PT_CAPTURE_HW_GSHIFT                               16                            /**< Shift for group PTCaptureHW */
#define  PT_CAPTURE_HW_GSIZE                                8                             /**< Size of group PTCaptureHW */
#define  PT_CAPTURE_HW_GMASK                                0x00FF0000u                   /**< Mask for group PTCaptureHW */

#define  PT_CAPTURE_HW_RSHIFT                               0                             /**< Shift for PTCaptureHW */
#define  PT_CAPTURE_HW_RMASK                                0x0000000Fu                   /**< Mask for PTCaptureHW */
#define  PT_CAPTURE_HW_RBMASK                               0xFu                          /**< Base mask for PTCaptureHW */
#define  PT_CAPTURE_HW_R(x)                                 (((x)&0xFu)<<0)               /**< Set PTCaptureHW in register */
#define  GET_PT_CAPTURE_HW_R(reg)                           (((reg)>>0)&0xFu)             /**< Get PTCaptureHW from register */
/** @} */


/**
 * @name RegProtTimHWEvtSyncSel
 * @{
 */
// RegProtTimHWEvtSyncSel.r32
#define  REG_PROT_TIM_HW_EVT_SYNC_SEL_RESET_VALUE           0x00000000u                   /**< Reset value of RegProtTimHWEvtSyncSel */
#define  REG_PROT_TIM_HW_EVT_SYNC_SEL_MASK                  0x000000FFu                   /**< Mask for RegProtTimHWEvtSyncSel */

#define  PT_HW_EVT_SYNC_SEL_SHIFT                           0                             /**< Shift for PTHWEvtSyncSel */
#define  PT_HW_EVT_SYNC_SEL_MASK                            0x000000FFu                   /**< Mask for PTHWEvtSyncSel */
#define  PT_HW_EVT_SYNC_SEL_BMASK                           0xFFu                         /**< Base mask for PTHWEvtSyncSel */
#define  PT_HW_EVT_SYNC_SEL(x)                              (((x)&0xFFu)<<0)              /**< Set PTHWEvtSyncSel in register */
#define  GET_PT_HW_EVT_SYNC_SEL(reg)                        (((reg)>>0)&0xFFu)            /**< Get PTHWEvtSyncSel from register */
/** @} */


/**
 * @name RegProtTimCaptureHWEvtSel
 * @{
 */
// RegProtTimCaptureHWEvtSel.r32
#define  REG_PROT_TIM_CAPTURE_HW_EVT_SEL_RESET_VALUE        0x00000000u                   /**< Reset value of RegProtTimCaptureHWEvtSel */
#define  REG_PROT_TIM_CAPTURE_HW_EVT_SEL_MASK               0x07070707u                   /**< Mask for RegProtTimCaptureHWEvtSel */

#define  PT_CAPTURE0_HW_EVT_SEL_SHIFT                       0                             /**< Shift for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_MASK                        0x00000007u                   /**< Mask for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_BMASK                       0x7u                          /**< Base mask for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL(x)                          (((x)&0x7u)<<0)               /**< Set PTCapture0HWEvtSel in register */
#define  GET_PT_CAPTURE0_HW_EVT_SEL(reg)                    (((reg)>>0)&0x7u)             /**< Get PTCapture0HWEvtSel from register */
#define  PT_CAPTURE1_HW_EVT_SEL_SHIFT                       8                             /**< Shift for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_MASK                        0x00000700u                   /**< Mask for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_BMASK                       0x7u                          /**< Base mask for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL(x)                          (((x)&0x7u)<<8)               /**< Set PTCapture1HWEvtSel in register */
#define  GET_PT_CAPTURE1_HW_EVT_SEL(reg)                    (((reg)>>8)&0x7u)             /**< Get PTCapture1HWEvtSel from register */
#define  PT_CAPTURE2_HW_EVT_SEL_SHIFT                       16                            /**< Shift for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_MASK                        0x00070000u                   /**< Mask for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_BMASK                       0x7u                          /**< Base mask for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL(x)                          (((x)&0x7u)<<16)              /**< Set PTCapture2HWEvtSel in register */
#define  GET_PT_CAPTURE2_HW_EVT_SEL(reg)                    (((reg)>>16)&0x7u)            /**< Get PTCapture2HWEvtSel from register */
#define  PT_CAPTURE3_HW_EVT_SEL_SHIFT                       24                            /**< Shift for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_MASK                        0x07000000u                   /**< Mask for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_BMASK                       0x7u                          /**< Base mask for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL(x)                          (((x)&0x7u)<<24)              /**< Set PTCapture3HWEvtSel in register */
#define  GET_PT_CAPTURE3_HW_EVT_SEL(reg)                    (((reg)>>24)&0x7u)            /**< Get PTCapture3HWEvtSel from register */

// RegProtTimCaptureHWEvtSel.regs.PTCapture0HWEvtSel
#define  PT_CAPTURE0_HW_EVT_SEL_GSHIFT                      0                             /**< Shift for group PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_GSIZE                       8                             /**< Size of group PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_GMASK                       0x000000FFu                   /**< Mask for group PTCapture0HWEvtSel */

#define  PT_CAPTURE0_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_RMASK                       0x00000007u                   /**< Mask for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_RBMASK                      0x7u                          /**< Base mask for PTCapture0HWEvtSel */
#define  PT_CAPTURE0_HW_EVT_SEL_R(x)                        (((x)&0x7u)<<0)               /**< Set PTCapture0HWEvtSel in register */
#define  GET_PT_CAPTURE0_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x7u)             /**< Get PTCapture0HWEvtSel from register */

// RegProtTimCaptureHWEvtSel.regs.PTCapture1HWEvtSel
#define  PT_CAPTURE1_HW_EVT_SEL_GSHIFT                      8                             /**< Shift for group PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_GSIZE                       8                             /**< Size of group PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_GMASK                       0x0000FF00u                   /**< Mask for group PTCapture1HWEvtSel */

#define  PT_CAPTURE1_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_RMASK                       0x00000007u                   /**< Mask for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_RBMASK                      0x7u                          /**< Base mask for PTCapture1HWEvtSel */
#define  PT_CAPTURE1_HW_EVT_SEL_R(x)                        (((x)&0x7u)<<0)               /**< Set PTCapture1HWEvtSel in register */
#define  GET_PT_CAPTURE1_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x7u)             /**< Get PTCapture1HWEvtSel from register */

// RegProtTimCaptureHWEvtSel.regs.PTCapture2HWEvtSel
#define  PT_CAPTURE2_HW_EVT_SEL_GSHIFT                      16                            /**< Shift for group PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_GSIZE                       8                             /**< Size of group PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_GMASK                       0x00FF0000u                   /**< Mask for group PTCapture2HWEvtSel */

#define  PT_CAPTURE2_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_RMASK                       0x00000007u                   /**< Mask for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_RBMASK                      0x7u                          /**< Base mask for PTCapture2HWEvtSel */
#define  PT_CAPTURE2_HW_EVT_SEL_R(x)                        (((x)&0x7u)<<0)               /**< Set PTCapture2HWEvtSel in register */
#define  GET_PT_CAPTURE2_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x7u)             /**< Get PTCapture2HWEvtSel from register */

// RegProtTimCaptureHWEvtSel.regs.PTCapture3HWEvtSel
#define  PT_CAPTURE3_HW_EVT_SEL_GSHIFT                      24                            /**< Shift for group PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_GSIZE                       8                             /**< Size of group PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_GMASK                       0xFF000000u                   /**< Mask for group PTCapture3HWEvtSel */

#define  PT_CAPTURE3_HW_EVT_SEL_RSHIFT                      0                             /**< Shift for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_RMASK                       0x00000007u                   /**< Mask for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_RBMASK                      0x7u                          /**< Base mask for PTCapture3HWEvtSel */
#define  PT_CAPTURE3_HW_EVT_SEL_R(x)                        (((x)&0x7u)<<0)               /**< Set PTCapture3HWEvtSel in register */
#define  GET_PT_CAPTURE3_HW_EVT_SEL_R(reg)                  (((reg)>>0)&0x7u)             /**< Get PTCapture3HWEvtSel from register */
/** @} */


/**
 * @name RegProtTimCapture0
 * @{
 */
// RegProtTimCapture0.r32
#define  REG_PROT_TIM_CAPTURE0_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCapture0 */
#define  REG_PROT_TIM_CAPTURE0_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCapture0 */

#define  PT_CAPTURE0_SHIFT                                  0                             /**< Shift for PTCapture0 */
#define  PT_CAPTURE0_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCapture0 */
#define  PT_CAPTURE0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCapture0 */
#define  PT_CAPTURE0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCapture0 in register */
#define  GET_PT_CAPTURE0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCapture0 from register */
/** @} */


/**
 * @name RegProtTimCapture1
 * @{
 */
// RegProtTimCapture1.r32
#define  REG_PROT_TIM_CAPTURE1_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCapture1 */
#define  REG_PROT_TIM_CAPTURE1_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCapture1 */

#define  PT_CAPTURE1_SHIFT                                  0                             /**< Shift for PTCapture1 */
#define  PT_CAPTURE1_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCapture1 */
#define  PT_CAPTURE1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCapture1 */
#define  PT_CAPTURE1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCapture1 in register */
#define  GET_PT_CAPTURE1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCapture1 from register */
/** @} */


/**
 * @name RegProtTimCapture2
 * @{
 */
// RegProtTimCapture2.r32
#define  REG_PROT_TIM_CAPTURE2_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCapture2 */
#define  REG_PROT_TIM_CAPTURE2_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCapture2 */

#define  PT_CAPTURE2_SHIFT                                  0                             /**< Shift for PTCapture2 */
#define  PT_CAPTURE2_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCapture2 */
#define  PT_CAPTURE2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCapture2 */
#define  PT_CAPTURE2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCapture2 in register */
#define  GET_PT_CAPTURE2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCapture2 from register */
/** @} */


/**
 * @name RegProtTimCapture3
 * @{
 */
// RegProtTimCapture3.r32
#define  REG_PROT_TIM_CAPTURE3_RESET_VALUE                  0x00000000u                   /**< Reset value of RegProtTimCapture3 */
#define  REG_PROT_TIM_CAPTURE3_MASK                         0xFFFFFFFFu                   /**< Mask for RegProtTimCapture3 */

#define  PT_CAPTURE3_SHIFT                                  0                             /**< Shift for PTCapture3 */
#define  PT_CAPTURE3_MASK                                   0xFFFFFFFFu                   /**< Mask for PTCapture3 */
#define  PT_CAPTURE3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PTCapture3 */
#define  PT_CAPTURE3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PTCapture3 in register */
#define  GET_PT_CAPTURE3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PTCapture3 from register */
/** @} */



/** @} End of group ProtTim_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_PROT_TIM_H */
