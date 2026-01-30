////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_rc_calib.h
///
/// @project    T9305
///
/// @brief      RC Calibration register and bit field definitions
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

#ifndef _T9305_RC_CALIB_H
#define _T9305_RC_CALIB_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup RCCalib_Registers RC Calibration Register Map - registers
 * @{
 ******************************************************************************/


/** RC calibration control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibCtrl_t;


/** RC calibration configuration  */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibCfg_t;


/** RC calibration status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibStat_t;


/** RC calibration HF_counter limit */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibHFCounterLimit_t;


/** RC calibration LF_counter limit */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibLFCounterLimit_t;


/** RC calibration HF_counter current value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibHFCounterVal_t;


/** RC calibration LF_counter current value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRCCalibLFCounterVal_t;

/** @} end of group RCCalib_Regs */



/***************************************************************************//**
 * @defgroup RCCalib_RegMap RC Calibration Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __O   RegRCCalibCtrl_t                                  RegRCCalibCtrl;               /**< RC calibration control */
    __IO  RegRCCalibCfg_t                                   RegRCCalibCfg;                /**< RC calibration configuration  */
    __I   RegRCCalibStat_t                                  RegRCCalibStat;               /**< RC calibration status */
    __IO  RegRCCalibHFCounterLimit_t                        RegRCCalibHFCounterLimit;     /**< RC calibration HF_counter limit */
    __IO  RegRCCalibLFCounterLimit_t                        RegRCCalibLFCounterLimit;     /**< RC calibration LF_counter limit */
    __I   RegRCCalibHFCounterVal_t                          RegRCCalibHFCounterVal;       /**< RC calibration HF_counter current value */
    __I   RegRCCalibLFCounterVal_t                          RegRCCalibLFCounterVal;       /**< RC calibration LF_counter current value */
} RCCalib_RegMap_t;

/** @} end of group RCCalib_RegMap */



/***************************************************************************//**
 * @defgroup RCCalib_BitFields RCCalib bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegRCCalibCtrl
 * @{
 */
// RegRCCalibCtrl.r32
#define  REG_RC_CALIB_CTRL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRCCalibCtrl */
#define  REG_RC_CALIB_CTRL_MASK                             0x00000003u                   /**< Mask for RegRCCalibCtrl */

#define  RC_CAL_START_SHIFT                                 0                             /**< Shift for RCCalStart */
#define  RC_CAL_START_MASK                                  0x00000001u                   /**< Mask for RCCalStart */
#define  RC_CAL_START_BMASK                                 0x1u                          /**< Base mask for RCCalStart */
#define  RC_CAL_START(x)                                    (((x)&0x1u)<<0)               /**< Set RCCalStart in register */
#define  GET_RC_CAL_START(reg)                              (((reg)>>0)&0x1u)             /**< Get RCCalStart from register */
#define  RC_CAL_STOP_SHIFT                                  1                             /**< Shift for RCCalStop */
#define  RC_CAL_STOP_MASK                                   0x00000002u                   /**< Mask for RCCalStop */
#define  RC_CAL_STOP_BMASK                                  0x1u                          /**< Base mask for RCCalStop */
#define  RC_CAL_STOP(x)                                     (((x)&0x1u)<<1)               /**< Set RCCalStop in register */
#define  GET_RC_CAL_STOP(reg)                               (((reg)>>1)&0x1u)             /**< Get RCCalStop from register */
/** @} */


/**
 * @name RegRCCalibCfg
 * @{
 */
// RegRCCalibCfg.r32
#define  REG_RC_CALIB_CFG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRCCalibCfg */
#define  REG_RC_CALIB_CFG_MASK                              0x00000303u                   /**< Mask for RegRCCalibCfg */

#define  RC_CAL_STOP_AT_HF_LIMIT_SHIFT                      0                             /**< Shift for RCCalStopAtHFLimit */
#define  RC_CAL_STOP_AT_HF_LIMIT_MASK                       0x00000001u                   /**< Mask for RCCalStopAtHFLimit */
#define  RC_CAL_STOP_AT_HF_LIMIT_BMASK                      0x1u                          /**< Base mask for RCCalStopAtHFLimit */
#define  RC_CAL_STOP_AT_HF_LIMIT(x)                         (((x)&0x1u)<<0)               /**< Set RCCalStopAtHFLimit in register */
#define  GET_RC_CAL_STOP_AT_HF_LIMIT(reg)                   (((reg)>>0)&0x1u)             /**< Get RCCalStopAtHFLimit from register */
#define  RC_CAL_STOP_AT_LF_LIMIT_SHIFT                      1                             /**< Shift for RCCalStopAtLFLimit */
#define  RC_CAL_STOP_AT_LF_LIMIT_MASK                       0x00000002u                   /**< Mask for RCCalStopAtLFLimit */
#define  RC_CAL_STOP_AT_LF_LIMIT_BMASK                      0x1u                          /**< Base mask for RCCalStopAtLFLimit */
#define  RC_CAL_STOP_AT_LF_LIMIT(x)                         (((x)&0x1u)<<1)               /**< Set RCCalStopAtLFLimit in register */
#define  GET_RC_CAL_STOP_AT_LF_LIMIT(reg)                   (((reg)>>1)&0x1u)             /**< Get RCCalStopAtLFLimit from register */
#define  RC_CAL_LF_CLK_SEL_SHIFT                            8                             /**< Shift for RCCalLfClkSel */
#define  RC_CAL_LF_CLK_SEL_MASK                             0x00000300u                   /**< Mask for RCCalLfClkSel */
#define  RC_CAL_LF_CLK_SEL_BMASK                            0x3u                          /**< Base mask for RCCalLfClkSel */
#define  RC_CAL_LF_CLK_SEL(x)                               (((x)&0x3u)<<8)               /**< Set RCCalLfClkSel in register */
#define  GET_RC_CAL_LF_CLK_SEL(reg)                         (((reg)>>8)&0x3u)             /**< Get RCCalLfClkSel from register */
/** @} */


/**
 * @name RegRCCalibStat
 * @{
 */
// RegRCCalibStat.r32
#define  REG_RC_CALIB_STAT_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRCCalibStat */
#define  REG_RC_CALIB_STAT_MASK                             0x00000007u                   /**< Mask for RegRCCalibStat */

#define  RC_CAL_RUNNING_SHIFT                               0                             /**< Shift for RCCalRunning */
#define  RC_CAL_RUNNING_MASK                                0x00000001u                   /**< Mask for RCCalRunning */
#define  RC_CAL_RUNNING_BMASK                               0x1u                          /**< Base mask for RCCalRunning */
#define  RC_CAL_RUNNING(x)                                  (((x)&0x1u)<<0)               /**< Set RCCalRunning in register */
#define  GET_RC_CAL_RUNNING(reg)                            (((reg)>>0)&0x1u)             /**< Get RCCalRunning from register */
#define  RC_CAL_START_STS_SHIFT                             1                             /**< Shift for RCCalStartSts */
#define  RC_CAL_START_STS_MASK                              0x00000002u                   /**< Mask for RCCalStartSts */
#define  RC_CAL_START_STS_BMASK                             0x1u                          /**< Base mask for RCCalStartSts */
#define  RC_CAL_START_STS(x)                                (((x)&0x1u)<<1)               /**< Set RCCalStartSts in register */
#define  GET_RC_CAL_START_STS(reg)                          (((reg)>>1)&0x1u)             /**< Get RCCalStartSts from register */
#define  RC_CAL_STOP_STS_SHIFT                              2                             /**< Shift for RCCalStopSts */
#define  RC_CAL_STOP_STS_MASK                               0x00000004u                   /**< Mask for RCCalStopSts */
#define  RC_CAL_STOP_STS_BMASK                              0x1u                          /**< Base mask for RCCalStopSts */
#define  RC_CAL_STOP_STS(x)                                 (((x)&0x1u)<<2)               /**< Set RCCalStopSts in register */
#define  GET_RC_CAL_STOP_STS(reg)                           (((reg)>>2)&0x1u)             /**< Get RCCalStopSts from register */
/** @} */


/**
 * @name RegRCCalibHFCounterLimit
 * @{
 */
// RegRCCalibHFCounterLimit.r32
#define  REG_RC_CALIB_HF_COUNTER_LIMIT_RESET_VALUE          0x00000000u                   /**< Reset value of RegRCCalibHFCounterLimit */
#define  REG_RC_CALIB_HF_COUNTER_LIMIT_MASK                 0x00FFFFFFu                   /**< Mask for RegRCCalibHFCounterLimit */

#define  RC_CAL_HF_COUNTER_LIMIT_SHIFT                      0                             /**< Shift for RCCalHFCounterLimit */
#define  RC_CAL_HF_COUNTER_LIMIT_MASK                       0x00FFFFFFu                   /**< Mask for RCCalHFCounterLimit */
#define  RC_CAL_HF_COUNTER_LIMIT_BMASK                      0xFFFFFFu                     /**< Base mask for RCCalHFCounterLimit */
#define  RC_CAL_HF_COUNTER_LIMIT(x)                         (((x)&0xFFFFFFu)<<0)          /**< Set RCCalHFCounterLimit in register */
#define  GET_RC_CAL_HF_COUNTER_LIMIT(reg)                   (((reg)>>0)&0xFFFFFFu)        /**< Get RCCalHFCounterLimit from register */
/** @} */


/**
 * @name RegRCCalibLFCounterLimit
 * @{
 */
// RegRCCalibLFCounterLimit.r32
#define  REG_RC_CALIB_LF_COUNTER_LIMIT_RESET_VALUE          0x00000000u                   /**< Reset value of RegRCCalibLFCounterLimit */
#define  REG_RC_CALIB_LF_COUNTER_LIMIT_MASK                 0x00003FFFu                   /**< Mask for RegRCCalibLFCounterLimit */

#define  RC_CAL_LF_COUNTER_LIMIT_SHIFT                      0                             /**< Shift for RCCalLFCounterLimit */
#define  RC_CAL_LF_COUNTER_LIMIT_MASK                       0x00003FFFu                   /**< Mask for RCCalLFCounterLimit */
#define  RC_CAL_LF_COUNTER_LIMIT_BMASK                      0x3FFFu                       /**< Base mask for RCCalLFCounterLimit */
#define  RC_CAL_LF_COUNTER_LIMIT(x)                         (((x)&0x3FFFu)<<0)            /**< Set RCCalLFCounterLimit in register */
#define  GET_RC_CAL_LF_COUNTER_LIMIT(reg)                   (((reg)>>0)&0x3FFFu)          /**< Get RCCalLFCounterLimit from register */
/** @} */


/**
 * @name RegRCCalibHFCounterVal
 * @{
 */
// RegRCCalibHFCounterVal.r32
#define  REG_RC_CALIB_HF_COUNTER_VAL_RESET_VALUE            0x00000000u                   /**< Reset value of RegRCCalibHFCounterVal */
#define  REG_RC_CALIB_HF_COUNTER_VAL_MASK                   0x00FFFFFFu                   /**< Mask for RegRCCalibHFCounterVal */

#define  RC_CAL_HF_COUNTER_VAL_SHIFT                        0                             /**< Shift for RCCalHFCounterVal */
#define  RC_CAL_HF_COUNTER_VAL_MASK                         0x00FFFFFFu                   /**< Mask for RCCalHFCounterVal */
#define  RC_CAL_HF_COUNTER_VAL_BMASK                        0xFFFFFFu                     /**< Base mask for RCCalHFCounterVal */
#define  RC_CAL_HF_COUNTER_VAL(x)                           (((x)&0xFFFFFFu)<<0)          /**< Set RCCalHFCounterVal in register */
#define  GET_RC_CAL_HF_COUNTER_VAL(reg)                     (((reg)>>0)&0xFFFFFFu)        /**< Get RCCalHFCounterVal from register */
/** @} */


/**
 * @name RegRCCalibLFCounterVal
 * @{
 */
// RegRCCalibLFCounterVal.r32
#define  REG_RC_CALIB_LF_COUNTER_VAL_RESET_VALUE            0x00000000u                   /**< Reset value of RegRCCalibLFCounterVal */
#define  REG_RC_CALIB_LF_COUNTER_VAL_MASK                   0x00003FFFu                   /**< Mask for RegRCCalibLFCounterVal */

#define  RC_CAL_LF_COUNTER_VAL_SHIFT                        0                             /**< Shift for RCCalLFCounterVal */
#define  RC_CAL_LF_COUNTER_VAL_MASK                         0x00003FFFu                   /**< Mask for RCCalLFCounterVal */
#define  RC_CAL_LF_COUNTER_VAL_BMASK                        0x3FFFu                       /**< Base mask for RCCalLFCounterVal */
#define  RC_CAL_LF_COUNTER_VAL(x)                           (((x)&0x3FFFu)<<0)            /**< Set RCCalLFCounterVal in register */
#define  GET_RC_CAL_LF_COUNTER_VAL(reg)                     (((reg)>>0)&0x3FFFu)          /**< Get RCCalLFCounterVal from register */
/** @} */



/** @} End of group RCCalib_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_RC_CALIB_H */
