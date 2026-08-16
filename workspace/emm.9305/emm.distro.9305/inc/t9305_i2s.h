////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_i2s.h
///
/// @project    T9305
///
/// @brief      I2S register and bit field definitions
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

#ifndef _T9305_I2S_H
#define _T9305_I2S_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup I2S_Registers I2S Register Map - registers
 * @{
 ******************************************************************************/


/** I2S Receive FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sRxFifo1B_t;


/** I2S Receive FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sRxFifo2B_t;


/** I2S Receive FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sRxFifo3B_t;


/** I2S Receive FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sRxFifo4B_t;


/** I2S Transmit FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sTxFifo1B_t;


/** I2S Transmit FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sTxFifo2B_t;


/** I2S Transmit FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sTxFifo3B_t;


/** I2S Transmit FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sTxFifo4B_t;


/** I2S FIFO configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sFifoCfg_t;


/** I2S general configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sCfg_t;


/** I2S general control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sCtrl_t;


/** I2S Fsync configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sFsyncCfg_t;


/** I2S Phase 0 configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh0Cfg_t;


/** I2S Phase 1 configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh1Cfg_t;


/** I2S Phase length config */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPhLengthCfg_t;


/** I2S Frame Sync master mode divider config */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sFsyncDivCfg_t;


/** I2S SClk master mode divider config */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sSClkDivCfg_t;


/** I2S MCLK master mode divider config */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sMClkDivCfg_t;


/** I2S Phase0 TX channels */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh0ChTx_t;


/** I2S Phase1 TX channels */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh1ChTx_t;


/** I2S Phase0 RX channels */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh0ChRx_t;


/** I2S Phase1 RX channels */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sPh1ChRx_t;


/** I2S FIFO control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2sFifoCtrl_t;


/** I2S FIFO status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  I2sFifoSts;                                /**< I2S FIFO status */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  I2sTxFifoNumBytes;                         /**< I2S TX FIFO - number of available bytes */
        uint8_t  I2sRxFifoNumBytes;                         /**< I2S RX FIFO - number of available bytes */
    } regs;
} RegI2sFifoSts_t;

/** @} end of group I2S_Regs */



/***************************************************************************//**
 * @defgroup I2S_RegMap I2S Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __I   RegI2sRxFifo1B_t                                  RegI2sRxFifo1B;               /**< I2S Receive FIFO - 1 byte access */
    __I   RegI2sRxFifo2B_t                                  RegI2sRxFifo2B;               /**< I2S Receive FIFO - 2 byte access */
    __I   RegI2sRxFifo3B_t                                  RegI2sRxFifo3B;               /**< I2S Receive FIFO - 3 byte access */
    __I   RegI2sRxFifo4B_t                                  RegI2sRxFifo4B;               /**< I2S Receive FIFO - 4 byte access */
    __O   RegI2sTxFifo1B_t                                  RegI2sTxFifo1B;               /**< I2S Transmit FIFO - 1 byte access */
    __O   RegI2sTxFifo2B_t                                  RegI2sTxFifo2B;               /**< I2S Transmit FIFO - 2 byte access */
    __O   RegI2sTxFifo3B_t                                  RegI2sTxFifo3B;               /**< I2S Transmit FIFO - 3 byte access */
    __O   RegI2sTxFifo4B_t                                  RegI2sTxFifo4B;               /**< I2S Transmit FIFO - 4 byte access */
    __IO  RegI2sFifoCfg_t                                   RegI2sFifoCfg;                /**< I2S FIFO configuration */
    __IO  RegI2sCfg_t                                       RegI2sCfg;                    /**< I2S general configuration */
    __IO  RegI2sCtrl_t                                      RegI2sCtrl;                   /**< I2S general control */
    __IO  RegI2sFsyncCfg_t                                  RegI2sFsyncCfg;               /**< I2S Fsync configuration */
    __IO  RegI2sPh0Cfg_t                                    RegI2sPh0Cfg;                 /**< I2S Phase 0 configuration */
    __IO  RegI2sPh1Cfg_t                                    RegI2sPh1Cfg;                 /**< I2S Phase 1 configuration */
    __IO  RegI2sPhLengthCfg_t                               RegI2sPhLengthCfg;            /**< I2S Phase length config */
    __IO  RegI2sFsyncDivCfg_t                               RegI2sFsyncDivCfg;            /**< I2S Frame Sync master mode divider config */
    __IO  RegI2sSClkDivCfg_t                                RegI2sSClkDivCfg;             /**< I2S SClk master mode divider config */
    __IO  RegI2sMClkDivCfg_t                                RegI2sMClkDivCfg;             /**< I2S MCLK master mode divider config */
    __O   RegI2sPh0ChTx_t                                   RegI2sPh0ChTx;                /**< I2S Phase0 TX channels */
    __O   RegI2sPh1ChTx_t                                   RegI2sPh1ChTx;                /**< I2S Phase1 TX channels */
    __O   RegI2sPh0ChRx_t                                   RegI2sPh0ChRx;                /**< I2S Phase0 RX channels */
    __O   RegI2sPh1ChRx_t                                   RegI2sPh1ChRx;                /**< I2S Phase1 RX channels */
    __O   RegI2sFifoCtrl_t                                  RegI2sFifoCtrl;               /**< I2S FIFO control */
    __I   RegI2sFifoSts_t                                   RegI2sFifoSts;                /**< I2S FIFO status */
} I2S_RegMap_t;

/** @} end of group I2S_RegMap */



/***************************************************************************//**
 * @defgroup I2S_BitFields I2S bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegI2sRxFifo1B
 * @{
 */
// RegI2sRxFifo1B.r32
#define  REG_I2S_RX_FIFO_1B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sRxFifo1B */
#define  REG_I2S_RX_FIFO_1B_MASK                            0x000000FFu                   /**< Mask for RegI2sRxFifo1B */

#define  I2S_RX_FIFO_1B_SHIFT                               0                             /**< Shift for I2sRxFifo1B */
#define  I2S_RX_FIFO_1B_MASK                                0x000000FFu                   /**< Mask for I2sRxFifo1B */
#define  I2S_RX_FIFO_1B_BMASK                               0xFFu                         /**< Base mask for I2sRxFifo1B */
#define  I2S_RX_FIFO_1B(x)                                  (((x)&0xFFu)<<0)              /**< Set I2sRxFifo1B in register */
#define  GET_I2S_RX_FIFO_1B(reg)                            (((reg)>>0)&0xFFu)            /**< Get I2sRxFifo1B from register */
/** @} */


/**
 * @name RegI2sRxFifo2B
 * @{
 */
// RegI2sRxFifo2B.r32
#define  REG_I2S_RX_FIFO_2B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sRxFifo2B */
#define  REG_I2S_RX_FIFO_2B_MASK                            0x0000FFFFu                   /**< Mask for RegI2sRxFifo2B */

#define  I2S_RX_FIFO_2B_SHIFT                               0                             /**< Shift for I2sRxFifo2B */
#define  I2S_RX_FIFO_2B_MASK                                0x0000FFFFu                   /**< Mask for I2sRxFifo2B */
#define  I2S_RX_FIFO_2B_BMASK                               0xFFFFu                       /**< Base mask for I2sRxFifo2B */
#define  I2S_RX_FIFO_2B(x)                                  (((x)&0xFFFFu)<<0)            /**< Set I2sRxFifo2B in register */
#define  GET_I2S_RX_FIFO_2B(reg)                            (((reg)>>0)&0xFFFFu)          /**< Get I2sRxFifo2B from register */
/** @} */


/**
 * @name RegI2sRxFifo3B
 * @{
 */
// RegI2sRxFifo3B.r32
#define  REG_I2S_RX_FIFO_3B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sRxFifo3B */
#define  REG_I2S_RX_FIFO_3B_MASK                            0x00FFFFFFu                   /**< Mask for RegI2sRxFifo3B */

#define  I2S_RX_FIFO_3B_SHIFT                               0                             /**< Shift for I2sRxFifo3B */
#define  I2S_RX_FIFO_3B_MASK                                0x00FFFFFFu                   /**< Mask for I2sRxFifo3B */
#define  I2S_RX_FIFO_3B_BMASK                               0xFFFFFFu                     /**< Base mask for I2sRxFifo3B */
#define  I2S_RX_FIFO_3B(x)                                  (((x)&0xFFFFFFu)<<0)          /**< Set I2sRxFifo3B in register */
#define  GET_I2S_RX_FIFO_3B(reg)                            (((reg)>>0)&0xFFFFFFu)        /**< Get I2sRxFifo3B from register */
/** @} */


/**
 * @name RegI2sRxFifo4B
 * @{
 */
// RegI2sRxFifo4B.r32
#define  REG_I2S_RX_FIFO_4B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sRxFifo4B */
#define  REG_I2S_RX_FIFO_4B_MASK                            0xFFFFFFFFu                   /**< Mask for RegI2sRxFifo4B */

#define  I2S_RX_FIFO_4B_SHIFT                               0                             /**< Shift for I2sRxFifo4B */
#define  I2S_RX_FIFO_4B_MASK                                0xFFFFFFFFu                   /**< Mask for I2sRxFifo4B */
#define  I2S_RX_FIFO_4B_BMASK                               0xFFFFFFFFu                   /**< Base mask for I2sRxFifo4B */
#define  I2S_RX_FIFO_4B(x)                                  (((x)&0xFFFFFFFFu)<<0)        /**< Set I2sRxFifo4B in register */
#define  GET_I2S_RX_FIFO_4B(reg)                            (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2sRxFifo4B from register */
/** @} */


/**
 * @name RegI2sTxFifo1B
 * @{
 */
// RegI2sTxFifo1B.r32
#define  REG_I2S_TX_FIFO_1B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sTxFifo1B */
#define  REG_I2S_TX_FIFO_1B_MASK                            0x000000FFu                   /**< Mask for RegI2sTxFifo1B */

#define  I2S_TX_FIFO_1B_SHIFT                               0                             /**< Shift for I2sTxFifo1B */
#define  I2S_TX_FIFO_1B_MASK                                0x000000FFu                   /**< Mask for I2sTxFifo1B */
#define  I2S_TX_FIFO_1B_BMASK                               0xFFu                         /**< Base mask for I2sTxFifo1B */
#define  I2S_TX_FIFO_1B(x)                                  (((x)&0xFFu)<<0)              /**< Set I2sTxFifo1B in register */
#define  GET_I2S_TX_FIFO_1B(reg)                            (((reg)>>0)&0xFFu)            /**< Get I2sTxFifo1B from register */
/** @} */


/**
 * @name RegI2sTxFifo2B
 * @{
 */
// RegI2sTxFifo2B.r32
#define  REG_I2S_TX_FIFO_2B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sTxFifo2B */
#define  REG_I2S_TX_FIFO_2B_MASK                            0x0000FFFFu                   /**< Mask for RegI2sTxFifo2B */

#define  I2S_TX_FIFO_2B_SHIFT                               0                             /**< Shift for I2sTxFifo2B */
#define  I2S_TX_FIFO_2B_MASK                                0x0000FFFFu                   /**< Mask for I2sTxFifo2B */
#define  I2S_TX_FIFO_2B_BMASK                               0xFFFFu                       /**< Base mask for I2sTxFifo2B */
#define  I2S_TX_FIFO_2B(x)                                  (((x)&0xFFFFu)<<0)            /**< Set I2sTxFifo2B in register */
#define  GET_I2S_TX_FIFO_2B(reg)                            (((reg)>>0)&0xFFFFu)          /**< Get I2sTxFifo2B from register */
/** @} */


/**
 * @name RegI2sTxFifo3B
 * @{
 */
// RegI2sTxFifo3B.r32
#define  REG_I2S_TX_FIFO_3B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sTxFifo3B */
#define  REG_I2S_TX_FIFO_3B_MASK                            0x00FFFFFFu                   /**< Mask for RegI2sTxFifo3B */

#define  I2S_TX_FIFO_3B_SHIFT                               0                             /**< Shift for I2sTxFifo3B */
#define  I2S_TX_FIFO_3B_MASK                                0x00FFFFFFu                   /**< Mask for I2sTxFifo3B */
#define  I2S_TX_FIFO_3B_BMASK                               0xFFFFFFu                     /**< Base mask for I2sTxFifo3B */
#define  I2S_TX_FIFO_3B(x)                                  (((x)&0xFFFFFFu)<<0)          /**< Set I2sTxFifo3B in register */
#define  GET_I2S_TX_FIFO_3B(reg)                            (((reg)>>0)&0xFFFFFFu)        /**< Get I2sTxFifo3B from register */
/** @} */


/**
 * @name RegI2sTxFifo4B
 * @{
 */
// RegI2sTxFifo4B.r32
#define  REG_I2S_TX_FIFO_4B_RESET_VALUE                     0x00000000u                   /**< Reset value of RegI2sTxFifo4B */
#define  REG_I2S_TX_FIFO_4B_MASK                            0xFFFFFFFFu                   /**< Mask for RegI2sTxFifo4B */

#define  I2S_TX_FIFO_4B_SHIFT                               0                             /**< Shift for I2sTxFifo4B */
#define  I2S_TX_FIFO_4B_MASK                                0xFFFFFFFFu                   /**< Mask for I2sTxFifo4B */
#define  I2S_TX_FIFO_4B_BMASK                               0xFFFFFFFFu                   /**< Base mask for I2sTxFifo4B */
#define  I2S_TX_FIFO_4B(x)                                  (((x)&0xFFFFFFFFu)<<0)        /**< Set I2sTxFifo4B in register */
#define  GET_I2S_TX_FIFO_4B(reg)                            (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2sTxFifo4B from register */
/** @} */


/**
 * @name RegI2sFifoCfg
 * @{
 */
// RegI2sFifoCfg.r32
#define  REG_I2S_FIFO_CFG_RESET_VALUE                       0x00000808u                   /**< Reset value of RegI2sFifoCfg */
#define  REG_I2S_FIFO_CFG_MASK                              0x00001F1Fu                   /**< Mask for RegI2sFifoCfg */

#define  I2S_TX_FIFO_LIMIT_SHIFT                            0                             /**< Shift for I2sTxFifoLimit */
#define  I2S_TX_FIFO_LIMIT_MASK                             0x0000001Fu                   /**< Mask for I2sTxFifoLimit */
#define  I2S_TX_FIFO_LIMIT_BMASK                            0x1Fu                         /**< Base mask for I2sTxFifoLimit */
#define  I2S_TX_FIFO_LIMIT(x)                               (((x)&0x1Fu)<<0)              /**< Set I2sTxFifoLimit in register */
#define  GET_I2S_TX_FIFO_LIMIT(reg)                         (((reg)>>0)&0x1Fu)            /**< Get I2sTxFifoLimit from register */
#define  I2S_RX_FIFO_LIMIT_SHIFT                            8                             /**< Shift for I2sRxFifoLimit */
#define  I2S_RX_FIFO_LIMIT_MASK                             0x00001F00u                   /**< Mask for I2sRxFifoLimit */
#define  I2S_RX_FIFO_LIMIT_BMASK                            0x1Fu                         /**< Base mask for I2sRxFifoLimit */
#define  I2S_RX_FIFO_LIMIT(x)                               (((x)&0x1Fu)<<8)              /**< Set I2sRxFifoLimit in register */
#define  GET_I2S_RX_FIFO_LIMIT(reg)                         (((reg)>>8)&0x1Fu)            /**< Get I2sRxFifoLimit from register */
/** @} */


/**
 * @name RegI2sCfg
 * @{
 */
// RegI2sCfg.r32
#define  REG_I2S_CFG_RESET_VALUE                            0x00000010u                   /**< Reset value of RegI2sCfg */
#define  REG_I2S_CFG_MASK                                   0x00001F1Fu                   /**< Mask for RegI2sCfg */

#define  I2S_MODE_SHIFT                                     0                             /**< Shift for I2sMode */
#define  I2S_MODE_MASK                                      0x00000001u                   /**< Mask for I2sMode */
#define  I2S_MODE_BMASK                                     0x1u                          /**< Base mask for I2sMode */
#define  I2S_MODE(x)                                        (((x)&0x1u)<<0)               /**< Set I2sMode in register */
#define  GET_I2S_MODE(reg)                                  (((reg)>>0)&0x1u)             /**< Get I2sMode from register */
#define  I2S_PROTOCOL_SHIFT                                 1                             /**< Shift for I2sProtocol */
#define  I2S_PROTOCOL_MASK                                  0x00000006u                   /**< Mask for I2sProtocol */
#define  I2S_PROTOCOL_BMASK                                 0x3u                          /**< Base mask for I2sProtocol */
#define  I2S_PROTOCOL(x)                                    (((x)&0x3u)<<1)               /**< Set I2sProtocol in register */
#define  GET_I2S_PROTOCOL(reg)                              (((reg)>>1)&0x3u)             /**< Get I2sProtocol from register */
#define  I2S_CPHA_SHIFT                                     3                             /**< Shift for I2sCPha */
#define  I2S_CPHA_MASK                                      0x00000008u                   /**< Mask for I2sCPha */
#define  I2S_CPHA_BMASK                                     0x1u                          /**< Base mask for I2sCPha */
#define  I2S_CPHA(x)                                        (((x)&0x1u)<<3)               /**< Set I2sCPha in register */
#define  GET_I2S_CPHA(reg)                                  (((reg)>>3)&0x1u)             /**< Get I2sCPha from register */
#define  I2S_FSYNC_POLARITY_SHIFT                           4                             /**< Shift for I2sFsyncPolarity */
#define  I2S_FSYNC_POLARITY_MASK                            0x00000010u                   /**< Mask for I2sFsyncPolarity */
#define  I2S_FSYNC_POLARITY_BMASK                           0x1u                          /**< Base mask for I2sFsyncPolarity */
#define  I2S_FSYNC_POLARITY(x)                              (((x)&0x1u)<<4)               /**< Set I2sFsyncPolarity in register */
#define  GET_I2S_FSYNC_POLARITY(reg)                        (((reg)>>4)&0x1u)             /**< Get I2sFsyncPolarity from register */
#define  I2S_PH_LENGTH_MODE_SHIFT                           8                             /**< Shift for I2sPhLengthmode */
#define  I2S_PH_LENGTH_MODE_MASK                            0x00000300u                   /**< Mask for I2sPhLengthmode */
#define  I2S_PH_LENGTH_MODE_BMASK                           0x3u                          /**< Base mask for I2sPhLengthmode */
#define  I2S_PH_LENGTH_MODE(x)                              (((x)&0x3u)<<8)               /**< Set I2sPhLengthmode in register */
#define  GET_I2S_PH_LENGTH_MODE(reg)                        (((reg)>>8)&0x3u)             /**< Get I2sPhLengthmode from register */
#define  I2S_LSBIT_FIRST_SHIFT                              10                            /**< Shift for I2sLsbitFirst */
#define  I2S_LSBIT_FIRST_MASK                               0x00000400u                   /**< Mask for I2sLsbitFirst */
#define  I2S_LSBIT_FIRST_BMASK                              0x1u                          /**< Base mask for I2sLsbitFirst */
#define  I2S_LSBIT_FIRST(x)                                 (((x)&0x1u)<<10)              /**< Set I2sLsbitFirst in register */
#define  GET_I2S_LSBIT_FIRST(reg)                           (((reg)>>10)&0x1u)            /**< Get I2sLsbitFirst from register */
#define  I2S_LSBYTE_FIRST_SHIFT                             11                            /**< Shift for I2sLsbyteFirst */
#define  I2S_LSBYTE_FIRST_MASK                              0x00000800u                   /**< Mask for I2sLsbyteFirst */
#define  I2S_LSBYTE_FIRST_BMASK                             0x1u                          /**< Base mask for I2sLsbyteFirst */
#define  I2S_LSBYTE_FIRST(x)                                (((x)&0x1u)<<11)              /**< Set I2sLsbyteFirst in register */
#define  GET_I2S_LSBYTE_FIRST(reg)                          (((reg)>>11)&0x1u)            /**< Get I2sLsbyteFirst from register */
#define  I2S_SIGN_EXTEND_EN_SHIFT                           12                            /**< Shift for I2sSignExtendEn */
#define  I2S_SIGN_EXTEND_EN_MASK                            0x00001000u                   /**< Mask for I2sSignExtendEn */
#define  I2S_SIGN_EXTEND_EN_BMASK                           0x1u                          /**< Base mask for I2sSignExtendEn */
#define  I2S_SIGN_EXTEND_EN(x)                              (((x)&0x1u)<<12)              /**< Set I2sSignExtendEn in register */
#define  GET_I2S_SIGN_EXTEND_EN(reg)                        (((reg)>>12)&0x1u)            /**< Get I2sSignExtendEn from register */
/** @} */


/**
 * @name RegI2sCtrl
 * @{
 */
// RegI2sCtrl.r32
#define  REG_I2S_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegI2sCtrl */
#define  REG_I2S_CTRL_MASK                                  0x01010101u                   /**< Mask for RegI2sCtrl */

#define  I2S_EN_SHIFT                                       0                             /**< Shift for I2sEn */
#define  I2S_EN_MASK                                        0x00000001u                   /**< Mask for I2sEn */
#define  I2S_EN_BMASK                                       0x1u                          /**< Base mask for I2sEn */
#define  I2S_EN(x)                                          (((x)&0x1u)<<0)               /**< Set I2sEn in register */
#define  GET_I2S_EN(reg)                                    (((reg)>>0)&0x1u)             /**< Get I2sEn from register */
#define  I2S_FSYNC_EN_SHIFT                                 8                             /**< Shift for I2sFsyncEn */
#define  I2S_FSYNC_EN_MASK                                  0x00000100u                   /**< Mask for I2sFsyncEn */
#define  I2S_FSYNC_EN_BMASK                                 0x1u                          /**< Base mask for I2sFsyncEn */
#define  I2S_FSYNC_EN(x)                                    (((x)&0x1u)<<8)               /**< Set I2sFsyncEn in register */
#define  GET_I2S_FSYNC_EN(reg)                              (((reg)>>8)&0x1u)             /**< Get I2sFsyncEn from register */
#define  I2S_SCLK_EN_SHIFT                                  16                            /**< Shift for I2sSClkEn */
#define  I2S_SCLK_EN_MASK                                   0x00010000u                   /**< Mask for I2sSClkEn */
#define  I2S_SCLK_EN_BMASK                                  0x1u                          /**< Base mask for I2sSClkEn */
#define  I2S_SCLK_EN(x)                                     (((x)&0x1u)<<16)              /**< Set I2sSClkEn in register */
#define  GET_I2S_SCLK_EN(reg)                               (((reg)>>16)&0x1u)            /**< Get I2sSClkEn from register */
#define  I2S_MCLK_EN_SHIFT                                  24                            /**< Shift for I2sMClkEn */
#define  I2S_MCLK_EN_MASK                                   0x01000000u                   /**< Mask for I2sMClkEn */
#define  I2S_MCLK_EN_BMASK                                  0x1u                          /**< Base mask for I2sMClkEn */
#define  I2S_MCLK_EN(x)                                     (((x)&0x1u)<<24)              /**< Set I2sMClkEn in register */
#define  GET_I2S_MCLK_EN(reg)                               (((reg)>>24)&0x1u)            /**< Get I2sMClkEn from register */
/** @} */


/**
 * @name RegI2sFsyncCfg
 * @{
 */
// RegI2sFsyncCfg.r32
#define  REG_I2S_FSYNC_CFG_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sFsyncCfg */
#define  REG_I2S_FSYNC_CFG_MASK                             0x00000FFFu                   /**< Mask for RegI2sFsyncCfg */

#define  I2S_FSYNC_LENGTH_SHIFT                             0                             /**< Shift for I2sFsyncLength */
#define  I2S_FSYNC_LENGTH_MASK                              0x00000FFFu                   /**< Mask for I2sFsyncLength */
#define  I2S_FSYNC_LENGTH_BMASK                             0xFFFu                        /**< Base mask for I2sFsyncLength */
#define  I2S_FSYNC_LENGTH(x)                                (((x)&0xFFFu)<<0)             /**< Set I2sFsyncLength in register */
#define  GET_I2S_FSYNC_LENGTH(reg)                          (((reg)>>0)&0xFFFu)           /**< Get I2sFsyncLength from register */
/** @} */


/**
 * @name RegI2sPh0Cfg
 * @{
 */
// RegI2sPh0Cfg.r32
#define  REG_I2S_PH0_CFG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegI2sPh0Cfg */
#define  REG_I2S_PH0_CFG_MASK                               0x00070FFFu                   /**< Mask for RegI2sPh0Cfg */

#define  I2S_PH0_DELAY_SHIFT                                0                             /**< Shift for I2sPh0Delay */
#define  I2S_PH0_DELAY_MASK                                 0x00000FFFu                   /**< Mask for I2sPh0Delay */
#define  I2S_PH0_DELAY_BMASK                                0xFFFu                        /**< Base mask for I2sPh0Delay */
#define  I2S_PH0_DELAY(x)                                   (((x)&0xFFFu)<<0)             /**< Set I2sPh0Delay in register */
#define  GET_I2S_PH0_DELAY(reg)                             (((reg)>>0)&0xFFFu)           /**< Get I2sPh0Delay from register */
#define  I2S_PH0_SAMPLE_SIZE_SHIFT                          16                            /**< Shift for I2sPh0SampleSize */
#define  I2S_PH0_SAMPLE_SIZE_MASK                           0x00070000u                   /**< Mask for I2sPh0SampleSize */
#define  I2S_PH0_SAMPLE_SIZE_BMASK                          0x7u                          /**< Base mask for I2sPh0SampleSize */
#define  I2S_PH0_SAMPLE_SIZE(x)                             (((x)&0x7u)<<16)              /**< Set I2sPh0SampleSize in register */
#define  GET_I2S_PH0_SAMPLE_SIZE(reg)                       (((reg)>>16)&0x7u)            /**< Get I2sPh0SampleSize from register */
/** @} */


/**
 * @name RegI2sPh1Cfg
 * @{
 */
// RegI2sPh1Cfg.r32
#define  REG_I2S_PH1_CFG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegI2sPh1Cfg */
#define  REG_I2S_PH1_CFG_MASK                               0x00070FFFu                   /**< Mask for RegI2sPh1Cfg */

#define  I2S_PH1_DELAY_SHIFT                                0                             /**< Shift for I2sPh1Delay */
#define  I2S_PH1_DELAY_MASK                                 0x00000FFFu                   /**< Mask for I2sPh1Delay */
#define  I2S_PH1_DELAY_BMASK                                0xFFFu                        /**< Base mask for I2sPh1Delay */
#define  I2S_PH1_DELAY(x)                                   (((x)&0xFFFu)<<0)             /**< Set I2sPh1Delay in register */
#define  GET_I2S_PH1_DELAY(reg)                             (((reg)>>0)&0xFFFu)           /**< Get I2sPh1Delay from register */
#define  I2S_PH1_SAMPLE_SIZE_SHIFT                          16                            /**< Shift for I2sPh1SampleSize */
#define  I2S_PH1_SAMPLE_SIZE_MASK                           0x00070000u                   /**< Mask for I2sPh1SampleSize */
#define  I2S_PH1_SAMPLE_SIZE_BMASK                          0x7u                          /**< Base mask for I2sPh1SampleSize */
#define  I2S_PH1_SAMPLE_SIZE(x)                             (((x)&0x7u)<<16)              /**< Set I2sPh1SampleSize in register */
#define  GET_I2S_PH1_SAMPLE_SIZE(reg)                       (((reg)>>16)&0x7u)            /**< Get I2sPh1SampleSize from register */
/** @} */


/**
 * @name RegI2sPhLengthCfg
 * @{
 */
// RegI2sPhLengthCfg.r32
#define  REG_I2S_PH_LENGTH_CFG_RESET_VALUE                  0x00000000u                   /**< Reset value of RegI2sPhLengthCfg */
#define  REG_I2S_PH_LENGTH_CFG_MASK                         0x00001FFFu                   /**< Mask for RegI2sPhLengthCfg */

#define  I2S_PH0_LENGTH_SHIFT                               0                             /**< Shift for I2sPh0Length */
#define  I2S_PH0_LENGTH_MASK                                0x00001FFFu                   /**< Mask for I2sPh0Length */
#define  I2S_PH0_LENGTH_BMASK                               0x1FFFu                       /**< Base mask for I2sPh0Length */
#define  I2S_PH0_LENGTH(x)                                  (((x)&0x1FFFu)<<0)            /**< Set I2sPh0Length in register */
#define  GET_I2S_PH0_LENGTH(reg)                            (((reg)>>0)&0x1FFFu)          /**< Get I2sPh0Length from register */
/** @} */


/**
 * @name RegI2sFsyncDivCfg
 * @{
 */
// RegI2sFsyncDivCfg.r32
#define  REG_I2S_FSYNC_DIV_CFG_RESET_VALUE                  0x00000002u                   /**< Reset value of RegI2sFsyncDivCfg */
#define  REG_I2S_FSYNC_DIV_CFG_MASK                         0xFFFFFFFFu                   /**< Mask for RegI2sFsyncDivCfg */

#define  I2S_FSYNC_DIV_SHIFT                                0                             /**< Shift for I2sFsyncDiv */
#define  I2S_FSYNC_DIV_MASK                                 0xFFFFFFFFu                   /**< Mask for I2sFsyncDiv */
#define  I2S_FSYNC_DIV_BMASK                                0xFFFFFFFFu                   /**< Base mask for I2sFsyncDiv */
#define  I2S_FSYNC_DIV(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set I2sFsyncDiv in register */
#define  GET_I2S_FSYNC_DIV(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2sFsyncDiv from register */
/** @} */


/**
 * @name RegI2sSClkDivCfg
 * @{
 */
// RegI2sSClkDivCfg.r32
#define  REG_I2S_SCLK_DIV_CFG_RESET_VALUE                   0x00000002u                   /**< Reset value of RegI2sSClkDivCfg */
#define  REG_I2S_SCLK_DIV_CFG_MASK                          0xFFFFFFFFu                   /**< Mask for RegI2sSClkDivCfg */

#define  I2S_SCLK_DIV_SHIFT                                 0                             /**< Shift for I2sSClkDiv */
#define  I2S_SCLK_DIV_MASK                                  0xFFFFFFFFu                   /**< Mask for I2sSClkDiv */
#define  I2S_SCLK_DIV_BMASK                                 0xFFFFFFFFu                   /**< Base mask for I2sSClkDiv */
#define  I2S_SCLK_DIV(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set I2sSClkDiv in register */
#define  GET_I2S_SCLK_DIV(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2sSClkDiv from register */
/** @} */


/**
 * @name RegI2sMClkDivCfg
 * @{
 */
// RegI2sMClkDivCfg.r32
#define  REG_I2S_MCLK_DIV_CFG_RESET_VALUE                   0x00000002u                   /**< Reset value of RegI2sMClkDivCfg */
#define  REG_I2S_MCLK_DIV_CFG_MASK                          0xFFFFFFFFu                   /**< Mask for RegI2sMClkDivCfg */

#define  I2S_MCLK_DIV_SHIFT                                 0                             /**< Shift for I2sMClkDiv */
#define  I2S_MCLK_DIV_MASK                                  0xFFFFFFFFu                   /**< Mask for I2sMClkDiv */
#define  I2S_MCLK_DIV_BMASK                                 0xFFFFFFFFu                   /**< Base mask for I2sMClkDiv */
#define  I2S_MCLK_DIV(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set I2sMClkDiv in register */
#define  GET_I2S_MCLK_DIV(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2sMClkDiv from register */
/** @} */


/**
 * @name RegI2sPh0ChTx
 * @{
 */
// RegI2sPh0ChTx.r32
#define  REG_I2S_PH0_CH_TX_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sPh0ChTx */
#define  REG_I2S_PH0_CH_TX_MASK                             0x0000003Fu                   /**< Mask for RegI2sPh0ChTx */

#define  I2S_PH0_CH_TX_SHIFT                                0                             /**< Shift for I2sPh0ChTx */
#define  I2S_PH0_CH_TX_MASK                                 0x0000003Fu                   /**< Mask for I2sPh0ChTx */
#define  I2S_PH0_CH_TX_BMASK                                0x3Fu                         /**< Base mask for I2sPh0ChTx */
#define  I2S_PH0_CH_TX(x)                                   (((x)&0x3Fu)<<0)              /**< Set I2sPh0ChTx in register */
#define  GET_I2S_PH0_CH_TX(reg)                             (((reg)>>0)&0x3Fu)            /**< Get I2sPh0ChTx from register */
/** @} */


/**
 * @name RegI2sPh1ChTx
 * @{
 */
// RegI2sPh1ChTx.r32
#define  REG_I2S_PH1_CH_TX_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sPh1ChTx */
#define  REG_I2S_PH1_CH_TX_MASK                             0x0000003Fu                   /**< Mask for RegI2sPh1ChTx */

#define  I2S_PH1_CH_TX_SHIFT                                0                             /**< Shift for I2sPh1ChTx */
#define  I2S_PH1_CH_TX_MASK                                 0x0000003Fu                   /**< Mask for I2sPh1ChTx */
#define  I2S_PH1_CH_TX_BMASK                                0x3Fu                         /**< Base mask for I2sPh1ChTx */
#define  I2S_PH1_CH_TX(x)                                   (((x)&0x3Fu)<<0)              /**< Set I2sPh1ChTx in register */
#define  GET_I2S_PH1_CH_TX(reg)                             (((reg)>>0)&0x3Fu)            /**< Get I2sPh1ChTx from register */
/** @} */


/**
 * @name RegI2sPh0ChRx
 * @{
 */
// RegI2sPh0ChRx.r32
#define  REG_I2S_PH0_CH_RX_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sPh0ChRx */
#define  REG_I2S_PH0_CH_RX_MASK                             0x0000003Fu                   /**< Mask for RegI2sPh0ChRx */

#define  I2S_PH0_CH_RX_SHIFT                                0                             /**< Shift for I2sPh0ChRx */
#define  I2S_PH0_CH_RX_MASK                                 0x0000003Fu                   /**< Mask for I2sPh0ChRx */
#define  I2S_PH0_CH_RX_BMASK                                0x3Fu                         /**< Base mask for I2sPh0ChRx */
#define  I2S_PH0_CH_RX(x)                                   (((x)&0x3Fu)<<0)              /**< Set I2sPh0ChRx in register */
#define  GET_I2S_PH0_CH_RX(reg)                             (((reg)>>0)&0x3Fu)            /**< Get I2sPh0ChRx from register */
/** @} */


/**
 * @name RegI2sPh1ChRx
 * @{
 */
// RegI2sPh1ChRx.r32
#define  REG_I2S_PH1_CH_RX_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sPh1ChRx */
#define  REG_I2S_PH1_CH_RX_MASK                             0x0000003Fu                   /**< Mask for RegI2sPh1ChRx */

#define  I2S_PH1_CH_RX_SHIFT                                0                             /**< Shift for I2sPh1ChRx */
#define  I2S_PH1_CH_RX_MASK                                 0x0000003Fu                   /**< Mask for I2sPh1ChRx */
#define  I2S_PH1_CH_RX_BMASK                                0x3Fu                         /**< Base mask for I2sPh1ChRx */
#define  I2S_PH1_CH_RX(x)                                   (((x)&0x3Fu)<<0)              /**< Set I2sPh1ChRx in register */
#define  GET_I2S_PH1_CH_RX(reg)                             (((reg)>>0)&0x3Fu)            /**< Get I2sPh1ChRx from register */
/** @} */


/**
 * @name RegI2sFifoCtrl
 * @{
 */
// RegI2sFifoCtrl.r32
#define  REG_I2S_FIFO_CTRL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegI2sFifoCtrl */
#define  REG_I2S_FIFO_CTRL_MASK                             0x00000003u                   /**< Mask for RegI2sFifoCtrl */

#define  I2S_TX_FIFO_FLUSH_SHIFT                            0                             /**< Shift for I2sTxFifoFlush */
#define  I2S_TX_FIFO_FLUSH_MASK                             0x00000001u                   /**< Mask for I2sTxFifoFlush */
#define  I2S_TX_FIFO_FLUSH_BMASK                            0x1u                          /**< Base mask for I2sTxFifoFlush */
#define  I2S_TX_FIFO_FLUSH(x)                               (((x)&0x1u)<<0)               /**< Set I2sTxFifoFlush in register */
#define  GET_I2S_TX_FIFO_FLUSH(reg)                         (((reg)>>0)&0x1u)             /**< Get I2sTxFifoFlush from register */
#define  I2S_RX_FIFO_FLUSH_SHIFT                            1                             /**< Shift for I2sRxFifoFlush */
#define  I2S_RX_FIFO_FLUSH_MASK                             0x00000002u                   /**< Mask for I2sRxFifoFlush */
#define  I2S_RX_FIFO_FLUSH_BMASK                            0x1u                          /**< Base mask for I2sRxFifoFlush */
#define  I2S_RX_FIFO_FLUSH(x)                               (((x)&0x1u)<<1)               /**< Set I2sRxFifoFlush in register */
#define  GET_I2S_RX_FIFO_FLUSH(reg)                         (((reg)>>1)&0x1u)             /**< Get I2sRxFifoFlush from register */
/** @} */


/**
 * @name RegI2sFifoSts
 * @{
 */
// RegI2sFifoSts.r32
#define  REG_I2S_FIFO_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegI2sFifoSts */
#define  REG_I2S_FIFO_STS_MASK                              0x7F7F0077u                   /**< Mask for RegI2sFifoSts */

#define  I2S_TX_FIFO_EMPTY_SHIFT                            0                             /**< Shift for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY_MASK                             0x00000001u                   /**< Mask for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY_BMASK                            0x1u                          /**< Base mask for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY(x)                               (((x)&0x1u)<<0)               /**< Set I2sTxFifoEmpty in register */
#define  GET_I2S_TX_FIFO_EMPTY(reg)                         (((reg)>>0)&0x1u)             /**< Get I2sTxFifoEmpty from register */
#define  I2S_TX_FIFO_LIMIT_DET_SHIFT                        1                             /**< Shift for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET_MASK                         0x00000002u                   /**< Mask for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET_BMASK                        0x1u                          /**< Base mask for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET(x)                           (((x)&0x1u)<<1)               /**< Set I2sTxFifoLimitDet in register */
#define  GET_I2S_TX_FIFO_LIMIT_DET(reg)                     (((reg)>>1)&0x1u)             /**< Get I2sTxFifoLimitDet from register */
#define  I2S_TX_FIFO_FULL_SHIFT                             2                             /**< Shift for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL_MASK                              0x00000004u                   /**< Mask for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL_BMASK                             0x1u                          /**< Base mask for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL(x)                                (((x)&0x1u)<<2)               /**< Set I2sTxFifoFull in register */
#define  GET_I2S_TX_FIFO_FULL(reg)                          (((reg)>>2)&0x1u)             /**< Get I2sTxFifoFull from register */
#define  I2S_RX_FIFO_EMPTY_SHIFT                            4                             /**< Shift for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY_MASK                             0x00000010u                   /**< Mask for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY_BMASK                            0x1u                          /**< Base mask for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY(x)                               (((x)&0x1u)<<4)               /**< Set I2sRxFifoEmpty in register */
#define  GET_I2S_RX_FIFO_EMPTY(reg)                         (((reg)>>4)&0x1u)             /**< Get I2sRxFifoEmpty from register */
#define  I2S_RX_FIFO_LIMIT_DET_SHIFT                        5                             /**< Shift for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET_MASK                         0x00000020u                   /**< Mask for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET_BMASK                        0x1u                          /**< Base mask for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET(x)                           (((x)&0x1u)<<5)               /**< Set I2sRxFifoLimitDet in register */
#define  GET_I2S_RX_FIFO_LIMIT_DET(reg)                     (((reg)>>5)&0x1u)             /**< Get I2sRxFifoLimitDet from register */
#define  I2S_RX_FIFO_FULL_SHIFT                             6                             /**< Shift for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL_MASK                              0x00000040u                   /**< Mask for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL_BMASK                             0x1u                          /**< Base mask for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL(x)                                (((x)&0x1u)<<6)               /**< Set I2sRxFifoFull in register */
#define  GET_I2S_RX_FIFO_FULL(reg)                          (((reg)>>6)&0x1u)             /**< Get I2sRxFifoFull from register */
#define  I2S_TX_FIFO_NUM_BYTES_SHIFT                        16                            /**< Shift for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_MASK                         0x007F0000u                   /**< Mask for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_BMASK                        0x7Fu                         /**< Base mask for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES(x)                           (((x)&0x7Fu)<<16)             /**< Set I2sTxFifoNumBytes in register */
#define  GET_I2S_TX_FIFO_NUM_BYTES(reg)                     (((reg)>>16)&0x7Fu)           /**< Get I2sTxFifoNumBytes from register */
#define  I2S_RX_FIFO_NUM_BYTES_SHIFT                        24                            /**< Shift for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_MASK                         0x7F000000u                   /**< Mask for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_BMASK                        0x7Fu                         /**< Base mask for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES(x)                           (((x)&0x7Fu)<<24)             /**< Set I2sRxFifoNumBytes in register */
#define  GET_I2S_RX_FIFO_NUM_BYTES(reg)                     (((reg)>>24)&0x7Fu)           /**< Get I2sRxFifoNumBytes from register */

// RegI2sFifoSts.regs.I2sFifoSts
#define  I2S_FIFO_STS_GSHIFT                                0                             /**< Shift for group I2sFifoSts */
#define  I2S_FIFO_STS_GSIZE                                 8                             /**< Size of group I2sFifoSts */
#define  I2S_FIFO_STS_GMASK                                 0x000000FFu                   /**< Mask for group I2sFifoSts */

#define  I2S_TX_FIFO_EMPTY_RSHIFT                           0                             /**< Shift for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY_RMASK                            0x01u                         /**< Mask for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY_RBMASK                           0x1u                          /**< Base mask for I2sTxFifoEmpty */
#define  I2S_TX_FIFO_EMPTY_R(x)                             (((x)&0x1u)<<0)               /**< Set I2sTxFifoEmpty in register */
#define  GET_I2S_TX_FIFO_EMPTY_R(reg)                       (((reg)>>0)&0x1u)             /**< Get I2sTxFifoEmpty from register */
#define  I2S_TX_FIFO_LIMIT_DET_RSHIFT                       1                             /**< Shift for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET_RMASK                        0x02u                         /**< Mask for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET_RBMASK                       0x1u                          /**< Base mask for I2sTxFifoLimitDet */
#define  I2S_TX_FIFO_LIMIT_DET_R(x)                         (((x)&0x1u)<<1)               /**< Set I2sTxFifoLimitDet in register */
#define  GET_I2S_TX_FIFO_LIMIT_DET_R(reg)                   (((reg)>>1)&0x1u)             /**< Get I2sTxFifoLimitDet from register */
#define  I2S_TX_FIFO_FULL_RSHIFT                            2                             /**< Shift for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL_RMASK                             0x04u                         /**< Mask for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL_RBMASK                            0x1u                          /**< Base mask for I2sTxFifoFull */
#define  I2S_TX_FIFO_FULL_R(x)                              (((x)&0x1u)<<2)               /**< Set I2sTxFifoFull in register */
#define  GET_I2S_TX_FIFO_FULL_R(reg)                        (((reg)>>2)&0x1u)             /**< Get I2sTxFifoFull from register */
#define  I2S_RX_FIFO_EMPTY_RSHIFT                           4                             /**< Shift for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY_RMASK                            0x10u                         /**< Mask for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY_RBMASK                           0x1u                          /**< Base mask for I2sRxFifoEmpty */
#define  I2S_RX_FIFO_EMPTY_R(x)                             (((x)&0x1u)<<4)               /**< Set I2sRxFifoEmpty in register */
#define  GET_I2S_RX_FIFO_EMPTY_R(reg)                       (((reg)>>4)&0x1u)             /**< Get I2sRxFifoEmpty from register */
#define  I2S_RX_FIFO_LIMIT_DET_RSHIFT                       5                             /**< Shift for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET_RMASK                        0x20u                         /**< Mask for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET_RBMASK                       0x1u                          /**< Base mask for I2sRxFifoLimitDet */
#define  I2S_RX_FIFO_LIMIT_DET_R(x)                         (((x)&0x1u)<<5)               /**< Set I2sRxFifoLimitDet in register */
#define  GET_I2S_RX_FIFO_LIMIT_DET_R(reg)                   (((reg)>>5)&0x1u)             /**< Get I2sRxFifoLimitDet from register */
#define  I2S_RX_FIFO_FULL_RSHIFT                            6                             /**< Shift for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL_RMASK                             0x40u                         /**< Mask for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL_RBMASK                            0x1u                          /**< Base mask for I2sRxFifoFull */
#define  I2S_RX_FIFO_FULL_R(x)                              (((x)&0x1u)<<6)               /**< Set I2sRxFifoFull in register */
#define  GET_I2S_RX_FIFO_FULL_R(reg)                        (((reg)>>6)&0x1u)             /**< Get I2sRxFifoFull from register */

// RegI2sFifoSts.regs.I2sTxFifoNumBytes
#define  I2S_TX_FIFO_NUM_BYTES_GSHIFT                       16                            /**< Shift for group I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_GSIZE                        8                             /**< Size of group I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_GMASK                        0x00FF0000u                   /**< Mask for group I2sTxFifoNumBytes */

#define  I2S_TX_FIFO_NUM_BYTES_RSHIFT                       0                             /**< Shift for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_RMASK                        0x7Fu                         /**< Mask for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_RBMASK                       0x7Fu                         /**< Base mask for I2sTxFifoNumBytes */
#define  I2S_TX_FIFO_NUM_BYTES_R(x)                         (((x)&0x7Fu)<<0)              /**< Set I2sTxFifoNumBytes in register */
#define  GET_I2S_TX_FIFO_NUM_BYTES_R(reg)                   (((reg)>>0)&0x7Fu)            /**< Get I2sTxFifoNumBytes from register */

// RegI2sFifoSts.regs.I2sRxFifoNumBytes
#define  I2S_RX_FIFO_NUM_BYTES_GSHIFT                       24                            /**< Shift for group I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_GSIZE                        8                             /**< Size of group I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_GMASK                        0xFF000000u                   /**< Mask for group I2sRxFifoNumBytes */

#define  I2S_RX_FIFO_NUM_BYTES_RSHIFT                       0                             /**< Shift for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_RMASK                        0x7Fu                         /**< Mask for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_RBMASK                       0x7Fu                         /**< Base mask for I2sRxFifoNumBytes */
#define  I2S_RX_FIFO_NUM_BYTES_R(x)                         (((x)&0x7Fu)<<0)              /**< Set I2sRxFifoNumBytes in register */
#define  GET_I2S_RX_FIFO_NUM_BYTES_R(reg)                   (((reg)>>0)&0x7Fu)            /**< Get I2sRxFifoNumBytes from register */
/** @} */



/** @} End of group I2S_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_I2S_H */
