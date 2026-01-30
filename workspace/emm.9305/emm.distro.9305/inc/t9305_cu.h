////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_cu.h
///
/// @project    T9305
///
/// @brief      Crypto Unit register and bit field definitions
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

#ifndef _T9305_CU_H
#define _T9305_CU_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup CU_Registers Crypto Unit Register Map - registers
 * @{
 ******************************************************************************/


/** Crypto unit control register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuCtrl_t;


/** Crypto unit status register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuSts_t;


/** Crypto unit input data (bytes 0:3) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataIn0_t;


/** Crypto unit input data (bytes 4:7) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataIn1_t;


/** Crypto unit input data (bytes 8:11) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataIn2_t;


/** Crypto unit input data (bytes 12:15) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataIn3_t;


/** Crypto unit key (bytes 0:3) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuKey0_t;


/** Crypto unit key (bytes 4:7) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuKey1_t;


/** Crypto unit key (bytes 8:11) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuKey2_t;


/** Crypto unit key (bytes 12:15) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuKey3_t;


/** Crypto unit output data (bytes 0:3) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataOut0_t;


/** Crypto unit output data (bytes 4:7) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataOut1_t;


/** Crypto unit output data (bytes 8:11) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataOut2_t;


/** Crypto unit output data (bytes 12:15) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegCuDataOut3_t;

/** @} end of group CU_Regs */



/***************************************************************************//**
 * @defgroup CU_RegMap Crypto Unit Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegCuCtrl_t                                       RegCuCtrl;                    /**< Crypto unit control register */
    __I   RegCuSts_t                                        RegCuSts;                     /**< Crypto unit status register */
    __IO  RegCuDataIn0_t                                    RegCuDataIn0;                 /**< Crypto unit input data (bytes 0:3) */
    __IO  RegCuDataIn1_t                                    RegCuDataIn1;                 /**< Crypto unit input data (bytes 4:7) */
    __IO  RegCuDataIn2_t                                    RegCuDataIn2;                 /**< Crypto unit input data (bytes 8:11) */
    __IO  RegCuDataIn3_t                                    RegCuDataIn3;                 /**< Crypto unit input data (bytes 12:15) */
    __O   RegCuKey0_t                                       RegCuKey0;                    /**< Crypto unit key (bytes 0:3) */
    __O   RegCuKey1_t                                       RegCuKey1;                    /**< Crypto unit key (bytes 4:7) */
    __O   RegCuKey2_t                                       RegCuKey2;                    /**< Crypto unit key (bytes 8:11) */
    __O   RegCuKey3_t                                       RegCuKey3;                    /**< Crypto unit key (bytes 12:15) */
    __I   RegCuDataOut0_t                                   RegCuDataOut0;                /**< Crypto unit output data (bytes 0:3) */
    __I   RegCuDataOut1_t                                   RegCuDataOut1;                /**< Crypto unit output data (bytes 4:7) */
    __I   RegCuDataOut2_t                                   RegCuDataOut2;                /**< Crypto unit output data (bytes 8:11) */
    __I   RegCuDataOut3_t                                   RegCuDataOut3;                /**< Crypto unit output data (bytes 12:15) */
} CU_RegMap_t;

/** @} end of group CU_RegMap */



/***************************************************************************//**
 * @defgroup CU_BitFields CU bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegCuCtrl
 * @{
 */
// RegCuCtrl.r32
#define  REG_CU_CTRL_RESET_VALUE                            0x00000000u                   /**< Reset value of RegCuCtrl */
#define  REG_CU_CTRL_MASK                                   0x01FF0303u                   /**< Mask for RegCuCtrl */

#define  CU_AES_START_SHIFT                                 0                             /**< Shift for CuAesStart */
#define  CU_AES_START_MASK                                  0x00000001u                   /**< Mask for CuAesStart */
#define  CU_AES_START_BMASK                                 0x1u                          /**< Base mask for CuAesStart */
#define  CU_AES_START(x)                                    (((x)&0x1u)<<0)               /**< Set CuAesStart in register */
#define  GET_CU_AES_START(reg)                              (((reg)>>0)&0x1u)             /**< Get CuAesStart from register */
#define  CU_LOAD_KEY_SHIFT                                  1                             /**< Shift for CuLoadKey */
#define  CU_LOAD_KEY_MASK                                   0x00000002u                   /**< Mask for CuLoadKey */
#define  CU_LOAD_KEY_BMASK                                  0x1u                          /**< Base mask for CuLoadKey */
#define  CU_LOAD_KEY(x)                                     (((x)&0x1u)<<1)               /**< Set CuLoadKey in register */
#define  GET_CU_LOAD_KEY(reg)                               (((reg)>>1)&0x1u)             /**< Get CuLoadKey from register */
#define  CU_AES_MODE_SHIFT                                  8                             /**< Shift for CuAesMode */
#define  CU_AES_MODE_MASK                                   0x00000100u                   /**< Mask for CuAesMode */
#define  CU_AES_MODE_BMASK                                  0x1u                          /**< Base mask for CuAesMode */
#define  CU_AES_MODE(x)                                     (((x)&0x1u)<<8)               /**< Set CuAesMode in register */
#define  GET_CU_AES_MODE(reg)                               (((reg)>>8)&0x1u)             /**< Get CuAesMode from register */
#define  CU_KEY_SOURCE_SHIFT                                9                             /**< Shift for CuKeySource */
#define  CU_KEY_SOURCE_MASK                                 0x00000200u                   /**< Mask for CuKeySource */
#define  CU_KEY_SOURCE_BMASK                                0x1u                          /**< Base mask for CuKeySource */
#define  CU_KEY_SOURCE(x)                                   (((x)&0x1u)<<9)               /**< Set CuKeySource in register */
#define  GET_CU_KEY_SOURCE(reg)                             (((reg)>>9)&0x1u)             /**< Get CuKeySource from register */
#define  CU_KEY_INDEX_SHIFT                                 16                            /**< Shift for CuKeyIndex */
#define  CU_KEY_INDEX_MASK                                  0x01FF0000u                   /**< Mask for CuKeyIndex */
#define  CU_KEY_INDEX_BMASK                                 0x1FFu                        /**< Base mask for CuKeyIndex */
#define  CU_KEY_INDEX(x)                                    (((x)&0x1FFu)<<16)            /**< Set CuKeyIndex in register */
#define  GET_CU_KEY_INDEX(reg)                              (((reg)>>16)&0x1FFu)          /**< Get CuKeyIndex from register */
/** @} */


/**
 * @name RegCuSts
 * @{
 */
// RegCuSts.r32
#define  REG_CU_STS_RESET_VALUE                             0x00000000u                   /**< Reset value of RegCuSts */
#define  REG_CU_STS_MASK                                    0x0000001Fu                   /**< Mask for RegCuSts */

#define  CU_AES_BUSY_SHIFT                                  0                             /**< Shift for CuAesBusy */
#define  CU_AES_BUSY_MASK                                   0x00000001u                   /**< Mask for CuAesBusy */
#define  CU_AES_BUSY_BMASK                                  0x1u                          /**< Base mask for CuAesBusy */
#define  CU_AES_BUSY(x)                                     (((x)&0x1u)<<0)               /**< Set CuAesBusy in register */
#define  GET_CU_AES_BUSY(reg)                               (((reg)>>0)&0x1u)             /**< Get CuAesBusy from register */
#define  CU_KEY_LOAD_BUSY_SHIFT                             1                             /**< Shift for CuKeyLoadBusy */
#define  CU_KEY_LOAD_BUSY_MASK                              0x00000002u                   /**< Mask for CuKeyLoadBusy */
#define  CU_KEY_LOAD_BUSY_BMASK                             0x1u                          /**< Base mask for CuKeyLoadBusy */
#define  CU_KEY_LOAD_BUSY(x)                                (((x)&0x1u)<<1)               /**< Set CuKeyLoadBusy in register */
#define  GET_CU_KEY_LOAD_BUSY(reg)                          (((reg)>>1)&0x1u)             /**< Get CuKeyLoadBusy from register */
#define  CU_AES_DONE_SHIFT                                  2                             /**< Shift for CuAesDone */
#define  CU_AES_DONE_MASK                                   0x00000004u                   /**< Mask for CuAesDone */
#define  CU_AES_DONE_BMASK                                  0x1u                          /**< Base mask for CuAesDone */
#define  CU_AES_DONE(x)                                     (((x)&0x1u)<<2)               /**< Set CuAesDone in register */
#define  GET_CU_AES_DONE(reg)                               (((reg)>>2)&0x1u)             /**< Get CuAesDone from register */
#define  CU_KEY_LOADED_SHIFT                                3                             /**< Shift for CuKeyLoaded */
#define  CU_KEY_LOADED_MASK                                 0x00000008u                   /**< Mask for CuKeyLoaded */
#define  CU_KEY_LOADED_BMASK                                0x1u                          /**< Base mask for CuKeyLoaded */
#define  CU_KEY_LOADED(x)                                   (((x)&0x1u)<<3)               /**< Set CuKeyLoaded in register */
#define  GET_CU_KEY_LOADED(reg)                             (((reg)>>3)&0x1u)             /**< Get CuKeyLoaded from register */
#define  CU_KEY_LOAD_ERR_SHIFT                              4                             /**< Shift for CuKeyLoadErr */
#define  CU_KEY_LOAD_ERR_MASK                               0x00000010u                   /**< Mask for CuKeyLoadErr */
#define  CU_KEY_LOAD_ERR_BMASK                              0x1u                          /**< Base mask for CuKeyLoadErr */
#define  CU_KEY_LOAD_ERR(x)                                 (((x)&0x1u)<<4)               /**< Set CuKeyLoadErr in register */
#define  GET_CU_KEY_LOAD_ERR(reg)                           (((reg)>>4)&0x1u)             /**< Get CuKeyLoadErr from register */
/** @} */


/**
 * @name RegCuDataIn0
 * @{
 */
// RegCuDataIn0.r32
#define  REG_CU_DATA_IN0_RESET_VALUE                        0x00000000u                   /**< Reset value of RegCuDataIn0 */
#define  REG_CU_DATA_IN0_MASK                               0xFFFFFFFFu                   /**< Mask for RegCuDataIn0 */

#define  CU_DATA_IN0_SHIFT                                  0                             /**< Shift for CuDataIn0 */
#define  CU_DATA_IN0_MASK                                   0xFFFFFFFFu                   /**< Mask for CuDataIn0 */
#define  CU_DATA_IN0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for CuDataIn0 */
#define  CU_DATA_IN0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataIn0 in register */
#define  GET_CU_DATA_IN0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataIn0 from register */
/** @} */


/**
 * @name RegCuDataIn1
 * @{
 */
// RegCuDataIn1.r32
#define  REG_CU_DATA_IN1_RESET_VALUE                        0x00000000u                   /**< Reset value of RegCuDataIn1 */
#define  REG_CU_DATA_IN1_MASK                               0xFFFFFFFFu                   /**< Mask for RegCuDataIn1 */

#define  CU_DATA_IN1_SHIFT                                  0                             /**< Shift for CuDataIn1 */
#define  CU_DATA_IN1_MASK                                   0xFFFFFFFFu                   /**< Mask for CuDataIn1 */
#define  CU_DATA_IN1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for CuDataIn1 */
#define  CU_DATA_IN1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataIn1 in register */
#define  GET_CU_DATA_IN1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataIn1 from register */
/** @} */


/**
 * @name RegCuDataIn2
 * @{
 */
// RegCuDataIn2.r32
#define  REG_CU_DATA_IN2_RESET_VALUE                        0x00000000u                   /**< Reset value of RegCuDataIn2 */
#define  REG_CU_DATA_IN2_MASK                               0xFFFFFFFFu                   /**< Mask for RegCuDataIn2 */

#define  CU_DATA_IN2_SHIFT                                  0                             /**< Shift for CuDataIn2 */
#define  CU_DATA_IN2_MASK                                   0xFFFFFFFFu                   /**< Mask for CuDataIn2 */
#define  CU_DATA_IN2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for CuDataIn2 */
#define  CU_DATA_IN2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataIn2 in register */
#define  GET_CU_DATA_IN2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataIn2 from register */
/** @} */


/**
 * @name RegCuDataIn3
 * @{
 */
// RegCuDataIn3.r32
#define  REG_CU_DATA_IN3_RESET_VALUE                        0x00000000u                   /**< Reset value of RegCuDataIn3 */
#define  REG_CU_DATA_IN3_MASK                               0xFFFFFFFFu                   /**< Mask for RegCuDataIn3 */

#define  CU_DATA_IN3_SHIFT                                  0                             /**< Shift for CuDataIn3 */
#define  CU_DATA_IN3_MASK                                   0xFFFFFFFFu                   /**< Mask for CuDataIn3 */
#define  CU_DATA_IN3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for CuDataIn3 */
#define  CU_DATA_IN3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataIn3 in register */
#define  GET_CU_DATA_IN3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataIn3 from register */
/** @} */


/**
 * @name RegCuKey0
 * @{
 */
// RegCuKey0.r32
#define  REG_CU_KEY0_RESET_VALUE                            0x00000000u                   /**< Reset value of RegCuKey0 */
#define  REG_CU_KEY0_MASK                                   0xFFFFFFFFu                   /**< Mask for RegCuKey0 */

#define  CU_KEY0_SHIFT                                      0                             /**< Shift for CuKey0 */
#define  CU_KEY0_MASK                                       0xFFFFFFFFu                   /**< Mask for CuKey0 */
#define  CU_KEY0_BMASK                                      0xFFFFFFFFu                   /**< Base mask for CuKey0 */
#define  CU_KEY0(x)                                         (((x)&0xFFFFFFFFu)<<0)        /**< Set CuKey0 in register */
#define  GET_CU_KEY0(reg)                                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuKey0 from register */
/** @} */


/**
 * @name RegCuKey1
 * @{
 */
// RegCuKey1.r32
#define  REG_CU_KEY1_RESET_VALUE                            0x00000000u                   /**< Reset value of RegCuKey1 */
#define  REG_CU_KEY1_MASK                                   0xFFFFFFFFu                   /**< Mask for RegCuKey1 */

#define  CU_KEY1_SHIFT                                      0                             /**< Shift for CuKey1 */
#define  CU_KEY1_MASK                                       0xFFFFFFFFu                   /**< Mask for CuKey1 */
#define  CU_KEY1_BMASK                                      0xFFFFFFFFu                   /**< Base mask for CuKey1 */
#define  CU_KEY1(x)                                         (((x)&0xFFFFFFFFu)<<0)        /**< Set CuKey1 in register */
#define  GET_CU_KEY1(reg)                                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuKey1 from register */
/** @} */


/**
 * @name RegCuKey2
 * @{
 */
// RegCuKey2.r32
#define  REG_CU_KEY2_RESET_VALUE                            0x00000000u                   /**< Reset value of RegCuKey2 */
#define  REG_CU_KEY2_MASK                                   0xFFFFFFFFu                   /**< Mask for RegCuKey2 */

#define  CU_KEY2_SHIFT                                      0                             /**< Shift for CuKey2 */
#define  CU_KEY2_MASK                                       0xFFFFFFFFu                   /**< Mask for CuKey2 */
#define  CU_KEY2_BMASK                                      0xFFFFFFFFu                   /**< Base mask for CuKey2 */
#define  CU_KEY2(x)                                         (((x)&0xFFFFFFFFu)<<0)        /**< Set CuKey2 in register */
#define  GET_CU_KEY2(reg)                                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuKey2 from register */
/** @} */


/**
 * @name RegCuKey3
 * @{
 */
// RegCuKey3.r32
#define  REG_CU_KEY3_RESET_VALUE                            0x00000000u                   /**< Reset value of RegCuKey3 */
#define  REG_CU_KEY3_MASK                                   0xFFFFFFFFu                   /**< Mask for RegCuKey3 */

#define  CU_KEY3_SHIFT                                      0                             /**< Shift for CuKey3 */
#define  CU_KEY3_MASK                                       0xFFFFFFFFu                   /**< Mask for CuKey3 */
#define  CU_KEY3_BMASK                                      0xFFFFFFFFu                   /**< Base mask for CuKey3 */
#define  CU_KEY3(x)                                         (((x)&0xFFFFFFFFu)<<0)        /**< Set CuKey3 in register */
#define  GET_CU_KEY3(reg)                                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuKey3 from register */
/** @} */


/**
 * @name RegCuDataOut0
 * @{
 */
// RegCuDataOut0.r32
#define  REG_CU_DATA_OUT0_RESET_VALUE                       0x00000000u                   /**< Reset value of RegCuDataOut0 */
#define  REG_CU_DATA_OUT0_MASK                              0xFFFFFFFFu                   /**< Mask for RegCuDataOut0 */

#define  CU_DATA_OUT0_SHIFT                                 0                             /**< Shift for CuDataOut0 */
#define  CU_DATA_OUT0_MASK                                  0xFFFFFFFFu                   /**< Mask for CuDataOut0 */
#define  CU_DATA_OUT0_BMASK                                 0xFFFFFFFFu                   /**< Base mask for CuDataOut0 */
#define  CU_DATA_OUT0(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataOut0 in register */
#define  GET_CU_DATA_OUT0(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataOut0 from register */
/** @} */


/**
 * @name RegCuDataOut1
 * @{
 */
// RegCuDataOut1.r32
#define  REG_CU_DATA_OUT1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegCuDataOut1 */
#define  REG_CU_DATA_OUT1_MASK                              0xFFFFFFFFu                   /**< Mask for RegCuDataOut1 */

#define  CU_DATA_OUT1_SHIFT                                 0                             /**< Shift for CuDataOut1 */
#define  CU_DATA_OUT1_MASK                                  0xFFFFFFFFu                   /**< Mask for CuDataOut1 */
#define  CU_DATA_OUT1_BMASK                                 0xFFFFFFFFu                   /**< Base mask for CuDataOut1 */
#define  CU_DATA_OUT1(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataOut1 in register */
#define  GET_CU_DATA_OUT1(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataOut1 from register */
/** @} */


/**
 * @name RegCuDataOut2
 * @{
 */
// RegCuDataOut2.r32
#define  REG_CU_DATA_OUT2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegCuDataOut2 */
#define  REG_CU_DATA_OUT2_MASK                              0xFFFFFFFFu                   /**< Mask for RegCuDataOut2 */

#define  CU_DATA_OUT2_SHIFT                                 0                             /**< Shift for CuDataOut2 */
#define  CU_DATA_OUT2_MASK                                  0xFFFFFFFFu                   /**< Mask for CuDataOut2 */
#define  CU_DATA_OUT2_BMASK                                 0xFFFFFFFFu                   /**< Base mask for CuDataOut2 */
#define  CU_DATA_OUT2(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataOut2 in register */
#define  GET_CU_DATA_OUT2(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataOut2 from register */
/** @} */


/**
 * @name RegCuDataOut3
 * @{
 */
// RegCuDataOut3.r32
#define  REG_CU_DATA_OUT3_RESET_VALUE                       0x00000000u                   /**< Reset value of RegCuDataOut3 */
#define  REG_CU_DATA_OUT3_MASK                              0xFFFFFFFFu                   /**< Mask for RegCuDataOut3 */

#define  CU_DATA_OUT3_SHIFT                                 0                             /**< Shift for CuDataOut3 */
#define  CU_DATA_OUT3_MASK                                  0xFFFFFFFFu                   /**< Mask for CuDataOut3 */
#define  CU_DATA_OUT3_BMASK                                 0xFFFFFFFFu                   /**< Base mask for CuDataOut3 */
#define  CU_DATA_OUT3(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set CuDataOut3 in register */
#define  GET_CU_DATA_OUT3(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get CuDataOut3 from register */
/** @} */



/** @} End of group CU_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*T9305_CU_H */
