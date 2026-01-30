////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_i2c_master.h
///
/// @project    T9305
///
/// @brief      I2C Master register and bit field definitions
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

#ifndef _T9305_I2C_MASTER_H
#define _T9305_I2C_MASTER_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup I2CMaster_Registers I2C Master Register Map - registers
 * @{
 ******************************************************************************/


/** I2C Master control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  I2CMRegAddress;                            /**< Register address in I2C device */
        uint8_t  I2CMSlaveAddress;                          /**< I2C Slave address */
        uint8_t  I2CMTransLength;                           /**< Data transfer length in bytes */
        uint8_t  I2CMTransCtrl;                             /**< I2C Master transaction control */
    } regs;
} RegI2CMCtrl_t;


/** I2C Master timing configuration 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  I2CMSCLLowPeriod;                          /**< SCL low period count */
        uint8_t  I2CMSCLHighPeriod;                         /**< SCL high period count */
        uint8_t  I2CMSCLStopPeriod;                         /**< SCL stop period count */
        uint8_t  I2CMSCLStartPeriod;                        /**< SCL start period count */
    } regs;
} RegI2CMTimingCfg0_t;


/** I2C Master timing configuration 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  I2CMSDAOutHoldTime;                        /**< SDA output hold time */
        uint8_t  I2CMSDALowTime;                            /**< SDA input low time */
        uint8_t  I2CMSCLRiseTime;                           /**< SCL rise time count */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegI2CMTimingCfg1_t;


/** I2C Master configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  I2CMCfg;                                   /**< I2C Master configuration */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
        uint8_t  RESERVED2;                                 /**< RESERVED */
    } regs;
} RegI2CMCfg_t;


/** I2C Master status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t I2CMStat;                                  /**< I2C Master status */
        uint8_t  I2CMTransLengthSts;                        /**< Number of bytes transfered */
        uint8_t  I2CMTstFSMSt;                              /**< FSM state observation */
    } regs;
} RegI2CMStat_t;


/** I2C Master transmit buffer bytes 0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMTxBuffer0_t;


/** I2C Master transmit buffer bytes 4-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMTxBuffer1_t;


/** I2C Master transmit buffer bytes 8-11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMTxBuffer2_t;


/** I2C Master transmit buffer bytes 12-15 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMTxBuffer3_t;


/** I2C Master receive buffer bytes 0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMRxBuffer0_t;


/** I2C Master receive buffer bytes 4-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMRxBuffer1_t;


/** I2C Master receive buffer bytes 8-11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMRxBuffer2_t;


/** I2C Master receive buffer bytes 12-15 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegI2CMRxBuffer3_t;

/** @} end of group I2CMaster_Regs */



/***************************************************************************//**
 * @defgroup I2CMaster_RegMap I2C Master Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegI2CMCtrl_t                                     RegI2CMCtrl;                  /**< I2C Master control */
    __IO  RegI2CMTimingCfg0_t                               RegI2CMTimingCfg0;            /**< I2C Master timing configuration 0 */
    __IO  RegI2CMTimingCfg1_t                               RegI2CMTimingCfg1;            /**< I2C Master timing configuration 1 */
    __IO  RegI2CMCfg_t                                      RegI2CMCfg;                   /**< I2C Master configuration */
    __I   RegI2CMStat_t                                     RegI2CMStat;                  /**< I2C Master status */
    __IO  RegI2CMTxBuffer0_t                                RegI2CMTxBuffer0;             /**< I2C Master transmit buffer bytes 0-3 */
    __IO  RegI2CMTxBuffer1_t                                RegI2CMTxBuffer1;             /**< I2C Master transmit buffer bytes 4-7 */
    __IO  RegI2CMTxBuffer2_t                                RegI2CMTxBuffer2;             /**< I2C Master transmit buffer bytes 8-11 */
    __IO  RegI2CMTxBuffer3_t                                RegI2CMTxBuffer3;             /**< I2C Master transmit buffer bytes 12-15 */
    __I   RegI2CMRxBuffer0_t                                RegI2CMRxBuffer0;             /**< I2C Master receive buffer bytes 0-3 */
    __I   RegI2CMRxBuffer1_t                                RegI2CMRxBuffer1;             /**< I2C Master receive buffer bytes 4-7 */
    __I   RegI2CMRxBuffer2_t                                RegI2CMRxBuffer2;             /**< I2C Master receive buffer bytes 8-11 */
    __I   RegI2CMRxBuffer3_t                                RegI2CMRxBuffer3;             /**< I2C Master receive buffer bytes 12-15 */
} I2CMaster_RegMap_t;

/** @} end of group I2CMaster_RegMap */



/***************************************************************************//**
 * @defgroup I2CMaster_BitFields I2CMaster bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegI2CMCtrl
 * @{
 */
// RegI2CMCtrl.r32
#define  REG_I2CM_CTRL_RESET_VALUE                          0x00000000u                   /**< Reset value of RegI2CMCtrl */
#define  REG_I2CM_CTRL_MASK                                 0x83BFFFFFu                   /**< Mask for RegI2CMCtrl */

#define  I2CM_REG_ADDRESS_SHIFT                             0                             /**< Shift for I2CMRegAddress */
#define  I2CM_REG_ADDRESS_MASK                              0x000000FFu                   /**< Mask for I2CMRegAddress */
#define  I2CM_REG_ADDRESS_BMASK                             0xFFu                         /**< Base mask for I2CMRegAddress */
#define  I2CM_REG_ADDRESS(x)                                (((x)&0xFFu)<<0)              /**< Set I2CMRegAddress in register */
#define  GET_I2CM_REG_ADDRESS(reg)                          (((reg)>>0)&0xFFu)            /**< Get I2CMRegAddress from register */
#define  I2CM_SLAVE_ADDRESS_SHIFT                           8                             /**< Shift for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_MASK                            0x00007F00u                   /**< Mask for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_BMASK                           0x7Fu                         /**< Base mask for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS(x)                              (((x)&0x7Fu)<<8)              /**< Set I2CMSlaveAddress in register */
#define  GET_I2CM_SLAVE_ADDRESS(reg)                        (((reg)>>8)&0x7Fu)            /**< Get I2CMSlaveAddress from register */
#define  I2CM_READ_WRITE_SEL_SHIFT                          15                            /**< Shift for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL_MASK                           0x00008000u                   /**< Mask for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL_BMASK                          0x1u                          /**< Base mask for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL(x)                             (((x)&0x1u)<<15)              /**< Set I2CMReadWriteSel in register */
#define  GET_I2CM_READ_WRITE_SEL(reg)                       (((reg)>>15)&0x1u)            /**< Get I2CMReadWriteSel from register */
#define  I2CM_TRANS_LENGTH_SHIFT                            16                            /**< Shift for I2CMTransLength */
#define  I2CM_TRANS_LENGTH_MASK                             0x001F0000u                   /**< Mask for I2CMTransLength */
#define  I2CM_TRANS_LENGTH_BMASK                            0x1Fu                         /**< Base mask for I2CMTransLength */
#define  I2CM_TRANS_LENGTH(x)                               (((x)&0x1Fu)<<16)             /**< Set I2CMTransLength in register */
#define  GET_I2CM_TRANS_LENGTH(reg)                         (((reg)>>16)&0x1Fu)           /**< Get I2CMTransLength from register */
#define  I2CM_NO_STOP_SHIFT                                 21                            /**< Shift for I2CMNoStop */
#define  I2CM_NO_STOP_MASK                                  0x00200000u                   /**< Mask for I2CMNoStop */
#define  I2CM_NO_STOP_BMASK                                 0x1u                          /**< Base mask for I2CMNoStop */
#define  I2CM_NO_STOP(x)                                    (((x)&0x1u)<<21)              /**< Set I2CMNoStop in register */
#define  GET_I2CM_NO_STOP(reg)                              (((reg)>>21)&0x1u)            /**< Get I2CMNoStop from register */
#define  I2CM_REG_ADDRESS_EN_SHIFT                          23                            /**< Shift for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN_MASK                           0x00800000u                   /**< Mask for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN_BMASK                          0x1u                          /**< Base mask for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN(x)                             (((x)&0x1u)<<23)              /**< Set I2CMRegAddressEn in register */
#define  GET_I2CM_REG_ADDRESS_EN(reg)                       (((reg)>>23)&0x1u)            /**< Get I2CMRegAddressEn from register */
#define  I2CM_START_TRANS_SHIFT                             24                            /**< Shift for I2CMStartTrans */
#define  I2CM_START_TRANS_MASK                              0x01000000u                   /**< Mask for I2CMStartTrans */
#define  I2CM_START_TRANS_BMASK                             0x1u                          /**< Base mask for I2CMStartTrans */
#define  I2CM_START_TRANS(x)                                (((x)&0x1u)<<24)              /**< Set I2CMStartTrans in register */
#define  GET_I2CM_START_TRANS(reg)                          (((reg)>>24)&0x1u)            /**< Get I2CMStartTrans from register */
#define  I2CM_STOP_TRANS_SHIFT                              25                            /**< Shift for I2CMStopTrans */
#define  I2CM_STOP_TRANS_MASK                               0x02000000u                   /**< Mask for I2CMStopTrans */
#define  I2CM_STOP_TRANS_BMASK                              0x1u                          /**< Base mask for I2CMStopTrans */
#define  I2CM_STOP_TRANS(x)                                 (((x)&0x1u)<<25)              /**< Set I2CMStopTrans in register */
#define  GET_I2CM_STOP_TRANS(reg)                           (((reg)>>25)&0x1u)            /**< Get I2CMStopTrans from register */
#define  I2CM_RESET_SHIFT                                   31                            /**< Shift for I2CMReset */
#define  I2CM_RESET_MASK                                    0x80000000u                   /**< Mask for I2CMReset */
#define  I2CM_RESET_BMASK                                   0x1u                          /**< Base mask for I2CMReset */
#define  I2CM_RESET(x)                                      (((x)&0x1u)<<31)              /**< Set I2CMReset in register */
#define  GET_I2CM_RESET(reg)                                (((reg)>>31)&0x1u)            /**< Get I2CMReset from register */

// RegI2CMCtrl.regs.I2CMRegAddress
#define  I2CM_REG_ADDRESS_GSHIFT                            0                             /**< Shift for group I2CMRegAddress */
#define  I2CM_REG_ADDRESS_GSIZE                             8                             /**< Size of group I2CMRegAddress */
#define  I2CM_REG_ADDRESS_GMASK                             0x000000FFu                   /**< Mask for group I2CMRegAddress */

#define  I2CM_REG_ADDRESS_RSHIFT                            0                             /**< Shift for I2CMRegAddress */
#define  I2CM_REG_ADDRESS_RMASK                             0x000000FFu                   /**< Mask for I2CMRegAddress */
#define  I2CM_REG_ADDRESS_RBMASK                            0xFFu                         /**< Base mask for I2CMRegAddress */
#define  I2CM_REG_ADDRESS_R(x)                              (((x)&0xFFu)<<0)              /**< Set I2CMRegAddress in register */
#define  GET_I2CM_REG_ADDRESS_R(reg)                        (((reg)>>0)&0xFFu)            /**< Get I2CMRegAddress from register */

// RegI2CMCtrl.regs.I2CMSlaveAddress
#define  I2CM_SLAVE_ADDRESS_GSHIFT                          8                             /**< Shift for group I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_GSIZE                           8                             /**< Size of group I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_GMASK                           0x0000FF00u                   /**< Mask for group I2CMSlaveAddress */

#define  I2CM_SLAVE_ADDRESS_RSHIFT                          0                             /**< Shift for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_RMASK                           0x0000007Fu                   /**< Mask for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_RBMASK                          0x7Fu                         /**< Base mask for I2CMSlaveAddress */
#define  I2CM_SLAVE_ADDRESS_R(x)                            (((x)&0x7Fu)<<0)              /**< Set I2CMSlaveAddress in register */
#define  GET_I2CM_SLAVE_ADDRESS_R(reg)                      (((reg)>>0)&0x7Fu)            /**< Get I2CMSlaveAddress from register */
#define  I2CM_READ_WRITE_SEL_RSHIFT                         7                             /**< Shift for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL_RMASK                          0x00000080u                   /**< Mask for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL_RBMASK                         0x1u                          /**< Base mask for I2CMReadWriteSel */
#define  I2CM_READ_WRITE_SEL_R(x)                           (((x)&0x1u)<<7)               /**< Set I2CMReadWriteSel in register */
#define  GET_I2CM_READ_WRITE_SEL_R(reg)                     (((reg)>>7)&0x1u)             /**< Get I2CMReadWriteSel from register */

// RegI2CMCtrl.regs.I2CMTransLength
#define  I2CM_TRANS_LENGTH_GSHIFT                           16                            /**< Shift for group I2CMTransLength */
#define  I2CM_TRANS_LENGTH_GSIZE                            8                             /**< Size of group I2CMTransLength */
#define  I2CM_TRANS_LENGTH_GMASK                            0x00FF0000u                   /**< Mask for group I2CMTransLength */

#define  I2CM_TRANS_LENGTH_RSHIFT                           0                             /**< Shift for I2CMTransLength */
#define  I2CM_TRANS_LENGTH_RMASK                            0x0000001Fu                   /**< Mask for I2CMTransLength */
#define  I2CM_TRANS_LENGTH_RBMASK                           0x1Fu                         /**< Base mask for I2CMTransLength */
#define  I2CM_TRANS_LENGTH_R(x)                             (((x)&0x1Fu)<<0)              /**< Set I2CMTransLength in register */
#define  GET_I2CM_TRANS_LENGTH_R(reg)                       (((reg)>>0)&0x1Fu)            /**< Get I2CMTransLength from register */
#define  I2CM_NO_STOP_RSHIFT                                5                             /**< Shift for I2CMNoStop */
#define  I2CM_NO_STOP_RMASK                                 0x00000020u                   /**< Mask for I2CMNoStop */
#define  I2CM_NO_STOP_RBMASK                                0x1u                          /**< Base mask for I2CMNoStop */
#define  I2CM_NO_STOP_R(x)                                  (((x)&0x1u)<<5)               /**< Set I2CMNoStop in register */
#define  GET_I2CM_NO_STOP_R(reg)                            (((reg)>>5)&0x1u)             /**< Get I2CMNoStop from register */
#define  I2CM_REG_ADDRESS_EN_RSHIFT                         7                             /**< Shift for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN_RMASK                          0x00000080u                   /**< Mask for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN_RBMASK                         0x1u                          /**< Base mask for I2CMRegAddressEn */
#define  I2CM_REG_ADDRESS_EN_R(x)                           (((x)&0x1u)<<7)               /**< Set I2CMRegAddressEn in register */
#define  GET_I2CM_REG_ADDRESS_EN_R(reg)                     (((reg)>>7)&0x1u)             /**< Get I2CMRegAddressEn from register */

// RegI2CMCtrl.regs.I2CMTransCtrl
#define  I2CM_TRANS_CTRL_GSHIFT                             24                            /**< Shift for group I2CMTransCtrl */
#define  I2CM_TRANS_CTRL_GSIZE                              8                             /**< Size of group I2CMTransCtrl */
#define  I2CM_TRANS_CTRL_GMASK                              0xFF000000u                   /**< Mask for group I2CMTransCtrl */

#define  I2CM_START_TRANS_RSHIFT                            0                             /**< Shift for I2CMStartTrans */
#define  I2CM_START_TRANS_RMASK                             0x01u                         /**< Mask for I2CMStartTrans */
#define  I2CM_START_TRANS_RBMASK                            0x1u                          /**< Base mask for I2CMStartTrans */
#define  I2CM_START_TRANS_R(x)                              (((x)&0x1u)<<0)               /**< Set I2CMStartTrans in register */
#define  GET_I2CM_START_TRANS_R(reg)                        (((reg)>>0)&0x1u)             /**< Get I2CMStartTrans from register */
#define  I2CM_STOP_TRANS_RSHIFT                             1                             /**< Shift for I2CMStopTrans */
#define  I2CM_STOP_TRANS_RMASK                              0x02u                         /**< Mask for I2CMStopTrans */
#define  I2CM_STOP_TRANS_RBMASK                             0x1u                          /**< Base mask for I2CMStopTrans */
#define  I2CM_STOP_TRANS_R(x)                               (((x)&0x1u)<<1)               /**< Set I2CMStopTrans in register */
#define  GET_I2CM_STOP_TRANS_R(reg)                         (((reg)>>1)&0x1u)             /**< Get I2CMStopTrans from register */
#define  I2CM_RESET_RSHIFT                                  7                             /**< Shift for I2CMReset */
#define  I2CM_RESET_RMASK                                   0x80u                         /**< Mask for I2CMReset */
#define  I2CM_RESET_RBMASK                                  0x1u                          /**< Base mask for I2CMReset */
#define  I2CM_RESET_R(x)                                    (((x)&0x1u)<<7)               /**< Set I2CMReset in register */
#define  GET_I2CM_RESET_R(reg)                              (((reg)>>7)&0x1u)             /**< Get I2CMReset from register */
/** @} */


/**
 * @name RegI2CMTimingCfg0
 * @{
 */
// RegI2CMTimingCfg0.r32
#define  REG_I2CM_TIMING_CFG0_RESET_VALUE                   0x00000000u                   /**< Reset value of RegI2CMTimingCfg0 */
#define  REG_I2CM_TIMING_CFG0_MASK                          0xFFFFFFFFu                   /**< Mask for RegI2CMTimingCfg0 */

#define  I2CM_SCL_LOW_PERIOD_SHIFT                          0                             /**< Shift for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_MASK                           0x000000FFu                   /**< Mask for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_BMASK                          0xFFu                         /**< Base mask for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD(x)                             (((x)&0xFFu)<<0)              /**< Set I2CMSCLLowPeriod in register */
#define  GET_I2CM_SCL_LOW_PERIOD(reg)                       (((reg)>>0)&0xFFu)            /**< Get I2CMSCLLowPeriod from register */
#define  I2CM_SCL_HIGH_PERIOD_SHIFT                         8                             /**< Shift for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_MASK                          0x0000FF00u                   /**< Mask for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_BMASK                         0xFFu                         /**< Base mask for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD(x)                            (((x)&0xFFu)<<8)              /**< Set I2CMSCLHighPeriod in register */
#define  GET_I2CM_SCL_HIGH_PERIOD(reg)                      (((reg)>>8)&0xFFu)            /**< Get I2CMSCLHighPeriod from register */
#define  I2CM_SCL_STOP_PERIOD_SHIFT                         16                            /**< Shift for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_MASK                          0x00FF0000u                   /**< Mask for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_BMASK                         0xFFu                         /**< Base mask for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD(x)                            (((x)&0xFFu)<<16)             /**< Set I2CMSCLStopPeriod in register */
#define  GET_I2CM_SCL_STOP_PERIOD(reg)                      (((reg)>>16)&0xFFu)           /**< Get I2CMSCLStopPeriod from register */
#define  I2CM_SCL_START_PERIOD_SHIFT                        24                            /**< Shift for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_MASK                         0xFF000000u                   /**< Mask for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_BMASK                        0xFFu                         /**< Base mask for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD(x)                           (((x)&0xFFu)<<24)             /**< Set I2CMSCLStartPeriod in register */
#define  GET_I2CM_SCL_START_PERIOD(reg)                     (((reg)>>24)&0xFFu)           /**< Get I2CMSCLStartPeriod from register */

// RegI2CMTimingCfg0.regs.I2CMSCLLowPeriod
#define  I2CM_SCL_LOW_PERIOD_GSHIFT                         0                             /**< Shift for group I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_GSIZE                          8                             /**< Size of group I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_GMASK                          0x000000FFu                   /**< Mask for group I2CMSCLLowPeriod */

#define  I2CM_SCL_LOW_PERIOD_RSHIFT                         0                             /**< Shift for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_RMASK                          0x000000FFu                   /**< Mask for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_RBMASK                         0xFFu                         /**< Base mask for I2CMSCLLowPeriod */
#define  I2CM_SCL_LOW_PERIOD_R(x)                           (((x)&0xFFu)<<0)              /**< Set I2CMSCLLowPeriod in register */
#define  GET_I2CM_SCL_LOW_PERIOD_R(reg)                     (((reg)>>0)&0xFFu)            /**< Get I2CMSCLLowPeriod from register */

// RegI2CMTimingCfg0.regs.I2CMSCLHighPeriod
#define  I2CM_SCL_HIGH_PERIOD_GSHIFT                        8                             /**< Shift for group I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_GSIZE                         8                             /**< Size of group I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_GMASK                         0x0000FF00u                   /**< Mask for group I2CMSCLHighPeriod */

#define  I2CM_SCL_HIGH_PERIOD_RSHIFT                        0                             /**< Shift for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_RMASK                         0x000000FFu                   /**< Mask for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_RBMASK                        0xFFu                         /**< Base mask for I2CMSCLHighPeriod */
#define  I2CM_SCL_HIGH_PERIOD_R(x)                          (((x)&0xFFu)<<0)              /**< Set I2CMSCLHighPeriod in register */
#define  GET_I2CM_SCL_HIGH_PERIOD_R(reg)                    (((reg)>>0)&0xFFu)            /**< Get I2CMSCLHighPeriod from register */

// RegI2CMTimingCfg0.regs.I2CMSCLStopPeriod
#define  I2CM_SCL_STOP_PERIOD_GSHIFT                        16                            /**< Shift for group I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_GSIZE                         8                             /**< Size of group I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_GMASK                         0x00FF0000u                   /**< Mask for group I2CMSCLStopPeriod */

#define  I2CM_SCL_STOP_PERIOD_RSHIFT                        0                             /**< Shift for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_RMASK                         0x000000FFu                   /**< Mask for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_RBMASK                        0xFFu                         /**< Base mask for I2CMSCLStopPeriod */
#define  I2CM_SCL_STOP_PERIOD_R(x)                          (((x)&0xFFu)<<0)              /**< Set I2CMSCLStopPeriod in register */
#define  GET_I2CM_SCL_STOP_PERIOD_R(reg)                    (((reg)>>0)&0xFFu)            /**< Get I2CMSCLStopPeriod from register */

// RegI2CMTimingCfg0.regs.I2CMSCLStartPeriod
#define  I2CM_SCL_START_PERIOD_GSHIFT                       24                            /**< Shift for group I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_GSIZE                        8                             /**< Size of group I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_GMASK                        0xFF000000u                   /**< Mask for group I2CMSCLStartPeriod */

#define  I2CM_SCL_START_PERIOD_RSHIFT                       0                             /**< Shift for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_RMASK                        0x000000FFu                   /**< Mask for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_RBMASK                       0xFFu                         /**< Base mask for I2CMSCLStartPeriod */
#define  I2CM_SCL_START_PERIOD_R(x)                         (((x)&0xFFu)<<0)              /**< Set I2CMSCLStartPeriod in register */
#define  GET_I2CM_SCL_START_PERIOD_R(reg)                   (((reg)>>0)&0xFFu)            /**< Get I2CMSCLStartPeriod from register */
/** @} */


/**
 * @name RegI2CMTimingCfg1
 * @{
 */
// RegI2CMTimingCfg1.r32
#define  REG_I2CM_TIMING_CFG1_RESET_VALUE                   0x00000000u                   /**< Reset value of RegI2CMTimingCfg1 */
#define  REG_I2CM_TIMING_CFG1_MASK                          0x00FFFFFFu                   /**< Mask for RegI2CMTimingCfg1 */

#define  I2CM_SDA_OUT_HOLD_TIME_SHIFT                       0                             /**< Shift for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_MASK                        0x000000FFu                   /**< Mask for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_BMASK                       0xFFu                         /**< Base mask for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME(x)                          (((x)&0xFFu)<<0)              /**< Set I2CMSDAOutHoldTime in register */
#define  GET_I2CM_SDA_OUT_HOLD_TIME(reg)                    (((reg)>>0)&0xFFu)            /**< Get I2CMSDAOutHoldTime from register */
#define  I2CM_SDA_LOW_TIME_SHIFT                            8                             /**< Shift for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_MASK                             0x0000FF00u                   /**< Mask for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_BMASK                            0xFFu                         /**< Base mask for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME(x)                               (((x)&0xFFu)<<8)              /**< Set I2CMSDALowTime in register */
#define  GET_I2CM_SDA_LOW_TIME(reg)                         (((reg)>>8)&0xFFu)            /**< Get I2CMSDALowTime from register */
#define  I2CM_SCL_RISE_TIME_SHIFT                           16                            /**< Shift for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_MASK                            0x00FF0000u                   /**< Mask for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_BMASK                           0xFFu                         /**< Base mask for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME(x)                              (((x)&0xFFu)<<16)             /**< Set I2CMSCLRiseTime in register */
#define  GET_I2CM_SCL_RISE_TIME(reg)                        (((reg)>>16)&0xFFu)           /**< Get I2CMSCLRiseTime from register */

// RegI2CMTimingCfg1.regs.I2CMSDAOutHoldTime
#define  I2CM_SDA_OUT_HOLD_TIME_GSHIFT                      0                             /**< Shift for group I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_GSIZE                       8                             /**< Size of group I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_GMASK                       0x000000FFu                   /**< Mask for group I2CMSDAOutHoldTime */

#define  I2CM_SDA_OUT_HOLD_TIME_RSHIFT                      0                             /**< Shift for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_RMASK                       0x000000FFu                   /**< Mask for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_RBMASK                      0xFFu                         /**< Base mask for I2CMSDAOutHoldTime */
#define  I2CM_SDA_OUT_HOLD_TIME_R(x)                        (((x)&0xFFu)<<0)              /**< Set I2CMSDAOutHoldTime in register */
#define  GET_I2CM_SDA_OUT_HOLD_TIME_R(reg)                  (((reg)>>0)&0xFFu)            /**< Get I2CMSDAOutHoldTime from register */

// RegI2CMTimingCfg1.regs.I2CMSDALowTime
#define  I2CM_SDA_LOW_TIME_GSHIFT                           8                             /**< Shift for group I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_GSIZE                            8                             /**< Size of group I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_GMASK                            0x0000FF00u                   /**< Mask for group I2CMSDALowTime */

#define  I2CM_SDA_LOW_TIME_RSHIFT                           0                             /**< Shift for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_RMASK                            0x000000FFu                   /**< Mask for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_RBMASK                           0xFFu                         /**< Base mask for I2CMSDALowTime */
#define  I2CM_SDA_LOW_TIME_R(x)                             (((x)&0xFFu)<<0)              /**< Set I2CMSDALowTime in register */
#define  GET_I2CM_SDA_LOW_TIME_R(reg)                       (((reg)>>0)&0xFFu)            /**< Get I2CMSDALowTime from register */

// RegI2CMTimingCfg1.regs.I2CMSCLRiseTime
#define  I2CM_SCL_RISE_TIME_GSHIFT                          16                            /**< Shift for group I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_GSIZE                           8                             /**< Size of group I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_GMASK                           0x00FF0000u                   /**< Mask for group I2CMSCLRiseTime */

#define  I2CM_SCL_RISE_TIME_RSHIFT                          0                             /**< Shift for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_RMASK                           0x000000FFu                   /**< Mask for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_RBMASK                          0xFFu                         /**< Base mask for I2CMSCLRiseTime */
#define  I2CM_SCL_RISE_TIME_R(x)                            (((x)&0xFFu)<<0)              /**< Set I2CMSCLRiseTime in register */
#define  GET_I2CM_SCL_RISE_TIME_R(reg)                      (((reg)>>0)&0xFFu)            /**< Get I2CMSCLRiseTime from register */
/** @} */


/**
 * @name RegI2CMCfg
 * @{
 */
// RegI2CMCfg.r32
#define  REG_I2CM_CFG_RESET_VALUE                           0x00000002u                   /**< Reset value of RegI2CMCfg */
#define  REG_I2CM_CFG_MASK                                  0x00000107u                   /**< Mask for RegI2CMCfg */

#define  I2CM_SDA_LOW_DET_DIS_SHIFT                         0                             /**< Shift for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS_MASK                          0x00000001u                   /**< Mask for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS_BMASK                         0x1u                          /**< Base mask for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS(x)                            (((x)&0x1u)<<0)               /**< Set I2CMSDALowDetDis in register */
#define  GET_I2CM_SDA_LOW_DET_DIS(reg)                      (((reg)>>0)&0x1u)             /**< Get I2CMSDALowDetDis from register */
#define  I2CM_CK_STRETCH_EN_SHIFT                           1                             /**< Shift for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN_MASK                            0x00000002u                   /**< Mask for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN_BMASK                           0x1u                          /**< Base mask for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN(x)                              (((x)&0x1u)<<1)               /**< Set I2CMCkStretchEn in register */
#define  GET_I2CM_CK_STRETCH_EN(reg)                        (((reg)>>1)&0x1u)             /**< Get I2CMCkStretchEn from register */
#define  I2CM_DRIVE_STRENGTH_SHIFT                          2                             /**< Shift for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH_MASK                           0x00000004u                   /**< Mask for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH_BMASK                          0x1u                          /**< Base mask for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH(x)                             (((x)&0x1u)<<2)               /**< Set I2CMDriveStrength in register */
#define  GET_I2CM_DRIVE_STRENGTH(reg)                       (((reg)>>2)&0x1u)             /**< Get I2CMDriveStrength from register */
#define  I2CM_EN_SHIFT                                      8                             /**< Shift for I2CMEn */
#define  I2CM_EN_MASK                                       0x00000100u                   /**< Mask for I2CMEn */
#define  I2CM_EN_BMASK                                      0x1u                          /**< Base mask for I2CMEn */
#define  I2CM_EN(x)                                         (((x)&0x1u)<<8)               /**< Set I2CMEn in register */
#define  GET_I2CM_EN(reg)                                   (((reg)>>8)&0x1u)             /**< Get I2CMEn from register */

// RegI2CMCfg.regs.I2CMCfg
#define  I2CM_CFG_GSHIFT                                    0                             /**< Shift for group I2CMCfg */
#define  I2CM_CFG_GSIZE                                     8                             /**< Size of group I2CMCfg */
#define  I2CM_CFG_GMASK                                     0x000000FFu                   /**< Mask for group I2CMCfg */

#define  I2CM_SDA_LOW_DET_DIS_RSHIFT                        0                             /**< Shift for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS_RMASK                         0x01u                         /**< Mask for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS_RBMASK                        0x1u                          /**< Base mask for I2CMSDALowDetDis */
#define  I2CM_SDA_LOW_DET_DIS_R(x)                          (((x)&0x1u)<<0)               /**< Set I2CMSDALowDetDis in register */
#define  GET_I2CM_SDA_LOW_DET_DIS_R(reg)                    (((reg)>>0)&0x1u)             /**< Get I2CMSDALowDetDis from register */
#define  I2CM_CK_STRETCH_EN_RSHIFT                          1                             /**< Shift for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN_RMASK                           0x02u                         /**< Mask for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN_RBMASK                          0x1u                          /**< Base mask for I2CMCkStretchEn */
#define  I2CM_CK_STRETCH_EN_R(x)                            (((x)&0x1u)<<1)               /**< Set I2CMCkStretchEn in register */
#define  GET_I2CM_CK_STRETCH_EN_R(reg)                      (((reg)>>1)&0x1u)             /**< Get I2CMCkStretchEn from register */
#define  I2CM_DRIVE_STRENGTH_RSHIFT                         2                             /**< Shift for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH_RMASK                          0x04u                         /**< Mask for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH_RBMASK                         0x1u                          /**< Base mask for I2CMDriveStrength */
#define  I2CM_DRIVE_STRENGTH_R(x)                           (((x)&0x1u)<<2)               /**< Set I2CMDriveStrength in register */
#define  GET_I2CM_DRIVE_STRENGTH_R(reg)                     (((reg)>>2)&0x1u)             /**< Get I2CMDriveStrength from register */
#define  I2CM_EN_RSHIFT                                     8                             /**< Shift for I2CMEn */
#define  I2CM_EN_RMASK                                      0x100u                        /**< Mask for I2CMEn */
#define  I2CM_EN_RBMASK                                     0x1u                          /**< Base mask for I2CMEn */
#define  I2CM_EN_R(x)                                       (((x)&0x1u)<<8)               /**< Set I2CMEn in register */
#define  GET_I2CM_EN_R(reg)                                 (((reg)>>8)&0x1u)             /**< Get I2CMEn from register */
/** @} */


/**
 * @name RegI2CMStat
 * @{
 */
// RegI2CMStat.r32
#define  REG_I2CM_STAT_RESET_VALUE                          0x00000000u                   /**< Reset value of RegI2CMStat */
#define  REG_I2CM_STAT_MASK                                 0x0F1F3FFFu                   /**< Mask for RegI2CMStat */

#define  I2CM_BUSY_SHIFT                                    0                             /**< Shift for I2CMBusy */
#define  I2CM_BUSY_MASK                                     0x00000001u                   /**< Mask for I2CMBusy */
#define  I2CM_BUSY_BMASK                                    0x1u                          /**< Base mask for I2CMBusy */
#define  I2CM_BUSY(x)                                       (((x)&0x1u)<<0)               /**< Set I2CMBusy in register */
#define  GET_I2CM_BUSY(reg)                                 (((reg)>>0)&0x1u)             /**< Get I2CMBusy from register */
#define  I2CM_CLK_STRETCH_SHIFT                             1                             /**< Shift for I2CMClkStretch */
#define  I2CM_CLK_STRETCH_MASK                              0x00000002u                   /**< Mask for I2CMClkStretch */
#define  I2CM_CLK_STRETCH_BMASK                             0x1u                          /**< Base mask for I2CMClkStretch */
#define  I2CM_CLK_STRETCH(x)                                (((x)&0x1u)<<1)               /**< Set I2CMClkStretch in register */
#define  GET_I2CM_CLK_STRETCH(reg)                          (((reg)>>1)&0x1u)             /**< Get I2CMClkStretch from register */
#define  I2CM_NACK_MASTER_SHIFT                             2                             /**< Shift for I2CMNackMaster */
#define  I2CM_NACK_MASTER_MASK                              0x00000004u                   /**< Mask for I2CMNackMaster */
#define  I2CM_NACK_MASTER_BMASK                             0x1u                          /**< Base mask for I2CMNackMaster */
#define  I2CM_NACK_MASTER(x)                                (((x)&0x1u)<<2)               /**< Set I2CMNackMaster in register */
#define  GET_I2CM_NACK_MASTER(reg)                          (((reg)>>2)&0x1u)             /**< Get I2CMNackMaster from register */
#define  I2CM_DATA_TRANS_SHIFT                              3                             /**< Shift for I2CMDataTrans */
#define  I2CM_DATA_TRANS_MASK                               0x00000008u                   /**< Mask for I2CMDataTrans */
#define  I2CM_DATA_TRANS_BMASK                              0x1u                          /**< Base mask for I2CMDataTrans */
#define  I2CM_DATA_TRANS(x)                                 (((x)&0x1u)<<3)               /**< Set I2CMDataTrans in register */
#define  GET_I2CM_DATA_TRANS(reg)                           (((reg)>>3)&0x1u)             /**< Get I2CMDataTrans from register */
#define  I2CM_STOP_SHIFT                                    4                             /**< Shift for I2CMStop */
#define  I2CM_STOP_MASK                                     0x00000010u                   /**< Mask for I2CMStop */
#define  I2CM_STOP_BMASK                                    0x1u                          /**< Base mask for I2CMStop */
#define  I2CM_STOP(x)                                       (((x)&0x1u)<<4)               /**< Set I2CMStop in register */
#define  GET_I2CM_STOP(reg)                                 (((reg)>>4)&0x1u)             /**< Get I2CMStop from register */
#define  I2CM_NACK_SLAVE_SHIFT                              5                             /**< Shift for I2CMNackSlave */
#define  I2CM_NACK_SLAVE_MASK                               0x00000020u                   /**< Mask for I2CMNackSlave */
#define  I2CM_NACK_SLAVE_BMASK                              0x1u                          /**< Base mask for I2CMNackSlave */
#define  I2CM_NACK_SLAVE(x)                                 (((x)&0x1u)<<5)               /**< Set I2CMNackSlave in register */
#define  GET_I2CM_NACK_SLAVE(reg)                           (((reg)>>5)&0x1u)             /**< Get I2CMNackSlave from register */
#define  I2CM_REG_ADDR_SENT_SHIFT                           6                             /**< Shift for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT_MASK                            0x00000040u                   /**< Mask for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT_BMASK                           0x1u                          /**< Base mask for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT(x)                              (((x)&0x1u)<<6)               /**< Set I2CMRegAddrSent in register */
#define  GET_I2CM_REG_ADDR_SENT(reg)                        (((reg)>>6)&0x1u)             /**< Get I2CMRegAddrSent from register */
#define  I2CM_SLV_ADDR_SENT_READ_SHIFT                      7                             /**< Shift for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ_MASK                       0x00000080u                   /**< Mask for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ_BMASK                      0x1u                          /**< Base mask for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ(x)                         (((x)&0x1u)<<7)               /**< Set I2CMSlvAddrSentRead in register */
#define  GET_I2CM_SLV_ADDR_SENT_READ(reg)                   (((reg)>>7)&0x1u)             /**< Get I2CMSlvAddrSentRead from register */
#define  I2CM_SLV_ADDR_SENT_WRITE_SHIFT                     8                             /**< Shift for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE_MASK                      0x00000100u                   /**< Mask for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE_BMASK                     0x1u                          /**< Base mask for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE(x)                        (((x)&0x1u)<<8)               /**< Set I2CMSlvAddrSentWrite in register */
#define  GET_I2CM_SLV_ADDR_SENT_WRITE(reg)                  (((reg)>>8)&0x1u)             /**< Get I2CMSlvAddrSentWrite from register */
#define  I2CM_START_SHIFT                                   9                             /**< Shift for I2CMStart */
#define  I2CM_START_MASK                                    0x00000200u                   /**< Mask for I2CMStart */
#define  I2CM_START_BMASK                                   0x1u                          /**< Base mask for I2CMStart */
#define  I2CM_START(x)                                      (((x)&0x1u)<<9)               /**< Set I2CMStart in register */
#define  GET_I2CM_START(reg)                                (((reg)>>9)&0x1u)             /**< Get I2CMStart from register */
#define  I2CM_SDA_LOW_SHIFT                                 10                            /**< Shift for I2CMSDALow */
#define  I2CM_SDA_LOW_MASK                                  0x00000400u                   /**< Mask for I2CMSDALow */
#define  I2CM_SDA_LOW_BMASK                                 0x1u                          /**< Base mask for I2CMSDALow */
#define  I2CM_SDA_LOW(x)                                    (((x)&0x1u)<<10)              /**< Set I2CMSDALow in register */
#define  GET_I2CM_SDA_LOW(reg)                              (((reg)>>10)&0x1u)            /**< Get I2CMSDALow from register */
#define  I2CM_START_TRANS_STS_SHIFT                         11                            /**< Shift for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS_MASK                          0x00000800u                   /**< Mask for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS_BMASK                         0x1u                          /**< Base mask for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS(x)                            (((x)&0x1u)<<11)              /**< Set I2CMStartTransSts in register */
#define  GET_I2CM_START_TRANS_STS(reg)                      (((reg)>>11)&0x1u)            /**< Get I2CMStartTransSts from register */
#define  I2CM_STOP_TRANS_STS_SHIFT                          12                            /**< Shift for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS_MASK                           0x00001000u                   /**< Mask for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS_BMASK                          0x1u                          /**< Base mask for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS(x)                             (((x)&0x1u)<<12)              /**< Set I2CMStopTransSts in register */
#define  GET_I2CM_STOP_TRANS_STS(reg)                       (((reg)>>12)&0x1u)            /**< Get I2CMStopTransSts from register */
#define  I2CM_PAUSE_STS_SHIFT                               13                            /**< Shift for I2CMPauseSts */
#define  I2CM_PAUSE_STS_MASK                                0x00002000u                   /**< Mask for I2CMPauseSts */
#define  I2CM_PAUSE_STS_BMASK                               0x1u                          /**< Base mask for I2CMPauseSts */
#define  I2CM_PAUSE_STS(x)                                  (((x)&0x1u)<<13)              /**< Set I2CMPauseSts in register */
#define  GET_I2CM_PAUSE_STS(reg)                            (((reg)>>13)&0x1u)            /**< Get I2CMPauseSts from register */
#define  I2CM_TRANS_LENGTH_STS_SHIFT                        16                            /**< Shift for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_MASK                         0x001F0000u                   /**< Mask for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_BMASK                        0x1Fu                         /**< Base mask for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS(x)                           (((x)&0x1Fu)<<16)             /**< Set I2CMTransLengthSts in register */
#define  GET_I2CM_TRANS_LENGTH_STS(reg)                     (((reg)>>16)&0x1Fu)           /**< Get I2CMTransLengthSts from register */
#define  I2CM_TST_FSM_ST_SHIFT                              24                            /**< Shift for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_MASK                               0x0F000000u                   /**< Mask for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_BMASK                              0xFu                          /**< Base mask for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST(x)                                 (((x)&0xFu)<<24)              /**< Set I2CMTstFSMSt in register */
#define  GET_I2CM_TST_FSM_ST(reg)                           (((reg)>>24)&0xFu)            /**< Get I2CMTstFSMSt from register */

// RegI2CMStat.regs.I2CMStat
#define  I2CM_STAT_GSHIFT                                   0                             /**< Shift for group I2CMStat */
#define  I2CM_STAT_GSIZE                                    16                            /**< Size of group I2CMStat */
#define  I2CM_STAT_GMASK                                    0x0000FFFFu                   /**< Mask for group I2CMStat */

#define  I2CM_BUSY_RSHIFT                                   0                             /**< Shift for I2CMBusy */
#define  I2CM_BUSY_RMASK                                    0x0001u                       /**< Mask for I2CMBusy */
#define  I2CM_BUSY_RBMASK                                   0x1u                          /**< Base mask for I2CMBusy */
#define  I2CM_BUSY_R(x)                                     (((x)&0x1u)<<0)               /**< Set I2CMBusy in register */
#define  GET_I2CM_BUSY_R(reg)                               (((reg)>>0)&0x1u)             /**< Get I2CMBusy from register */
#define  I2CM_CLK_STRETCH_RSHIFT                            1                             /**< Shift for I2CMClkStretch */
#define  I2CM_CLK_STRETCH_RMASK                             0x0002u                       /**< Mask for I2CMClkStretch */
#define  I2CM_CLK_STRETCH_RBMASK                            0x1u                          /**< Base mask for I2CMClkStretch */
#define  I2CM_CLK_STRETCH_R(x)                              (((x)&0x1u)<<1)               /**< Set I2CMClkStretch in register */
#define  GET_I2CM_CLK_STRETCH_R(reg)                        (((reg)>>1)&0x1u)             /**< Get I2CMClkStretch from register */
#define  I2CM_NACK_MASTER_RSHIFT                            2                             /**< Shift for I2CMNackMaster */
#define  I2CM_NACK_MASTER_RMASK                             0x0004u                       /**< Mask for I2CMNackMaster */
#define  I2CM_NACK_MASTER_RBMASK                            0x1u                          /**< Base mask for I2CMNackMaster */
#define  I2CM_NACK_MASTER_R(x)                              (((x)&0x1u)<<2)               /**< Set I2CMNackMaster in register */
#define  GET_I2CM_NACK_MASTER_R(reg)                        (((reg)>>2)&0x1u)             /**< Get I2CMNackMaster from register */
#define  I2CM_DATA_TRANS_RSHIFT                             3                             /**< Shift for I2CMDataTrans */
#define  I2CM_DATA_TRANS_RMASK                              0x0008u                       /**< Mask for I2CMDataTrans */
#define  I2CM_DATA_TRANS_RBMASK                             0x1u                          /**< Base mask for I2CMDataTrans */
#define  I2CM_DATA_TRANS_R(x)                               (((x)&0x1u)<<3)               /**< Set I2CMDataTrans in register */
#define  GET_I2CM_DATA_TRANS_R(reg)                         (((reg)>>3)&0x1u)             /**< Get I2CMDataTrans from register */
#define  I2CM_STOP_RSHIFT                                   4                             /**< Shift for I2CMStop */
#define  I2CM_STOP_RMASK                                    0x0010u                       /**< Mask for I2CMStop */
#define  I2CM_STOP_RBMASK                                   0x1u                          /**< Base mask for I2CMStop */
#define  I2CM_STOP_R(x)                                     (((x)&0x1u)<<4)               /**< Set I2CMStop in register */
#define  GET_I2CM_STOP_R(reg)                               (((reg)>>4)&0x1u)             /**< Get I2CMStop from register */
#define  I2CM_NACK_SLAVE_RSHIFT                             5                             /**< Shift for I2CMNackSlave */
#define  I2CM_NACK_SLAVE_RMASK                              0x0020u                       /**< Mask for I2CMNackSlave */
#define  I2CM_NACK_SLAVE_RBMASK                             0x1u                          /**< Base mask for I2CMNackSlave */
#define  I2CM_NACK_SLAVE_R(x)                               (((x)&0x1u)<<5)               /**< Set I2CMNackSlave in register */
#define  GET_I2CM_NACK_SLAVE_R(reg)                         (((reg)>>5)&0x1u)             /**< Get I2CMNackSlave from register */
#define  I2CM_REG_ADDR_SENT_RSHIFT                          6                             /**< Shift for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT_RMASK                           0x0040u                       /**< Mask for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT_RBMASK                          0x1u                          /**< Base mask for I2CMRegAddrSent */
#define  I2CM_REG_ADDR_SENT_R(x)                            (((x)&0x1u)<<6)               /**< Set I2CMRegAddrSent in register */
#define  GET_I2CM_REG_ADDR_SENT_R(reg)                      (((reg)>>6)&0x1u)             /**< Get I2CMRegAddrSent from register */
#define  I2CM_SLV_ADDR_SENT_READ_RSHIFT                     7                             /**< Shift for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ_RMASK                      0x0080u                       /**< Mask for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ_RBMASK                     0x1u                          /**< Base mask for I2CMSlvAddrSentRead */
#define  I2CM_SLV_ADDR_SENT_READ_R(x)                       (((x)&0x1u)<<7)               /**< Set I2CMSlvAddrSentRead in register */
#define  GET_I2CM_SLV_ADDR_SENT_READ_R(reg)                 (((reg)>>7)&0x1u)             /**< Get I2CMSlvAddrSentRead from register */
#define  I2CM_SLV_ADDR_SENT_WRITE_RSHIFT                    8                             /**< Shift for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE_RMASK                     0x0100u                       /**< Mask for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE_RBMASK                    0x1u                          /**< Base mask for I2CMSlvAddrSentWrite */
#define  I2CM_SLV_ADDR_SENT_WRITE_R(x)                      (((x)&0x1u)<<8)               /**< Set I2CMSlvAddrSentWrite in register */
#define  GET_I2CM_SLV_ADDR_SENT_WRITE_R(reg)                (((reg)>>8)&0x1u)             /**< Get I2CMSlvAddrSentWrite from register */
#define  I2CM_START_RSHIFT                                  9                             /**< Shift for I2CMStart */
#define  I2CM_START_RMASK                                   0x0200u                       /**< Mask for I2CMStart */
#define  I2CM_START_RBMASK                                  0x1u                          /**< Base mask for I2CMStart */
#define  I2CM_START_R(x)                                    (((x)&0x1u)<<9)               /**< Set I2CMStart in register */
#define  GET_I2CM_START_R(reg)                              (((reg)>>9)&0x1u)             /**< Get I2CMStart from register */
#define  I2CM_SDA_LOW_RSHIFT                                10                            /**< Shift for I2CMSDALow */
#define  I2CM_SDA_LOW_RMASK                                 0x0400u                       /**< Mask for I2CMSDALow */
#define  I2CM_SDA_LOW_RBMASK                                0x1u                          /**< Base mask for I2CMSDALow */
#define  I2CM_SDA_LOW_R(x)                                  (((x)&0x1u)<<10)              /**< Set I2CMSDALow in register */
#define  GET_I2CM_SDA_LOW_R(reg)                            (((reg)>>10)&0x1u)            /**< Get I2CMSDALow from register */
#define  I2CM_START_TRANS_STS_RSHIFT                        11                            /**< Shift for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS_RMASK                         0x0800u                       /**< Mask for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS_RBMASK                        0x1u                          /**< Base mask for I2CMStartTransSts */
#define  I2CM_START_TRANS_STS_R(x)                          (((x)&0x1u)<<11)              /**< Set I2CMStartTransSts in register */
#define  GET_I2CM_START_TRANS_STS_R(reg)                    (((reg)>>11)&0x1u)            /**< Get I2CMStartTransSts from register */
#define  I2CM_STOP_TRANS_STS_RSHIFT                         12                            /**< Shift for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS_RMASK                          0x1000u                       /**< Mask for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS_RBMASK                         0x1u                          /**< Base mask for I2CMStopTransSts */
#define  I2CM_STOP_TRANS_STS_R(x)                           (((x)&0x1u)<<12)              /**< Set I2CMStopTransSts in register */
#define  GET_I2CM_STOP_TRANS_STS_R(reg)                     (((reg)>>12)&0x1u)            /**< Get I2CMStopTransSts from register */
#define  I2CM_PAUSE_STS_RSHIFT                              13                            /**< Shift for I2CMPauseSts */
#define  I2CM_PAUSE_STS_RMASK                               0x2000u                       /**< Mask for I2CMPauseSts */
#define  I2CM_PAUSE_STS_RBMASK                              0x1u                          /**< Base mask for I2CMPauseSts */
#define  I2CM_PAUSE_STS_R(x)                                (((x)&0x1u)<<13)              /**< Set I2CMPauseSts in register */
#define  GET_I2CM_PAUSE_STS_R(reg)                          (((reg)>>13)&0x1u)            /**< Get I2CMPauseSts from register */

// RegI2CMStat.regs.I2CMTransLengthSts
#define  I2CM_TRANS_LENGTH_STS_GSHIFT                       16                            /**< Shift for group I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_GSIZE                        8                             /**< Size of group I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_GMASK                        0x00FF0000u                   /**< Mask for group I2CMTransLengthSts */

#define  I2CM_TRANS_LENGTH_STS_RSHIFT                       0                             /**< Shift for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_RMASK                        0x001Fu                       /**< Mask for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_RBMASK                       0x1Fu                         /**< Base mask for I2CMTransLengthSts */
#define  I2CM_TRANS_LENGTH_STS_R(x)                         (((x)&0x1Fu)<<0)              /**< Set I2CMTransLengthSts in register */
#define  GET_I2CM_TRANS_LENGTH_STS_R(reg)                   (((reg)>>0)&0x1Fu)            /**< Get I2CMTransLengthSts from register */

// RegI2CMStat.regs.I2CMTstFSMSt
#define  I2CM_TST_FSM_ST_GSHIFT                             24                            /**< Shift for group I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_GSIZE                              8                             /**< Size of group I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_GMASK                              0xFF000000u                   /**< Mask for group I2CMTstFSMSt */

#define  I2CM_TST_FSM_ST_RSHIFT                             0                             /**< Shift for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_RMASK                              0x000Fu                       /**< Mask for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_RBMASK                             0xFu                          /**< Base mask for I2CMTstFSMSt */
#define  I2CM_TST_FSM_ST_R(x)                               (((x)&0xFu)<<0)               /**< Set I2CMTstFSMSt in register */
#define  GET_I2CM_TST_FSM_ST_R(reg)                         (((reg)>>0)&0xFu)             /**< Get I2CMTstFSMSt from register */
/** @} */


/**
 * @name RegI2CMTxBuffer0
 * @{
 */
// RegI2CMTxBuffer0.r32
#define  REG_I2CM_TX_BUFFER0_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMTxBuffer0 */
#define  REG_I2CM_TX_BUFFER0_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMTxBuffer0 */

#define  I2CM_TX_BUFFER0_SHIFT                              0                             /**< Shift for I2CMTxBuffer0 */
#define  I2CM_TX_BUFFER0_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMTxBuffer0 */
#define  I2CM_TX_BUFFER0_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMTxBuffer0 */
#define  I2CM_TX_BUFFER0(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMTxBuffer0 in register */
#define  GET_I2CM_TX_BUFFER0(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMTxBuffer0 from register */
/** @} */


/**
 * @name RegI2CMTxBuffer1
 * @{
 */
// RegI2CMTxBuffer1.r32
#define  REG_I2CM_TX_BUFFER1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMTxBuffer1 */
#define  REG_I2CM_TX_BUFFER1_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMTxBuffer1 */

#define  I2CM_TX_BUFFER1_SHIFT                              0                             /**< Shift for I2CMTxBuffer1 */
#define  I2CM_TX_BUFFER1_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMTxBuffer1 */
#define  I2CM_TX_BUFFER1_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMTxBuffer1 */
#define  I2CM_TX_BUFFER1(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMTxBuffer1 in register */
#define  GET_I2CM_TX_BUFFER1(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMTxBuffer1 from register */
/** @} */


/**
 * @name RegI2CMTxBuffer2
 * @{
 */
// RegI2CMTxBuffer2.r32
#define  REG_I2CM_TX_BUFFER2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMTxBuffer2 */
#define  REG_I2CM_TX_BUFFER2_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMTxBuffer2 */

#define  I2CM_TX_BUFFER2_SHIFT                              0                             /**< Shift for I2CMTxBuffer2 */
#define  I2CM_TX_BUFFER2_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMTxBuffer2 */
#define  I2CM_TX_BUFFER2_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMTxBuffer2 */
#define  I2CM_TX_BUFFER2(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMTxBuffer2 in register */
#define  GET_I2CM_TX_BUFFER2(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMTxBuffer2 from register */
/** @} */


/**
 * @name RegI2CMTxBuffer3
 * @{
 */
// RegI2CMTxBuffer3.r32
#define  REG_I2CM_TX_BUFFER3_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMTxBuffer3 */
#define  REG_I2CM_TX_BUFFER3_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMTxBuffer3 */

#define  I2CM_TX_BUFFER3_SHIFT                              0                             /**< Shift for I2CMTxBuffer3 */
#define  I2CM_TX_BUFFER3_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMTxBuffer3 */
#define  I2CM_TX_BUFFER3_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMTxBuffer3 */
#define  I2CM_TX_BUFFER3(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMTxBuffer3 in register */
#define  GET_I2CM_TX_BUFFER3(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMTxBuffer3 from register */
/** @} */


/**
 * @name RegI2CMRxBuffer0
 * @{
 */
// RegI2CMRxBuffer0.r32
#define  REG_I2CM_RX_BUFFER0_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMRxBuffer0 */
#define  REG_I2CM_RX_BUFFER0_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMRxBuffer0 */

#define  I2CM_RX_BUFFER0_SHIFT                              0                             /**< Shift for I2CMRxBuffer0 */
#define  I2CM_RX_BUFFER0_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMRxBuffer0 */
#define  I2CM_RX_BUFFER0_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMRxBuffer0 */
#define  I2CM_RX_BUFFER0(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMRxBuffer0 in register */
#define  GET_I2CM_RX_BUFFER0(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMRxBuffer0 from register */
/** @} */


/**
 * @name RegI2CMRxBuffer1
 * @{
 */
// RegI2CMRxBuffer1.r32
#define  REG_I2CM_RX_BUFFER1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMRxBuffer1 */
#define  REG_I2CM_RX_BUFFER1_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMRxBuffer1 */

#define  I2CM_RX_BUFFER1_SHIFT                              0                             /**< Shift for I2CMRxBuffer1 */
#define  I2CM_RX_BUFFER1_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMRxBuffer1 */
#define  I2CM_RX_BUFFER1_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMRxBuffer1 */
#define  I2CM_RX_BUFFER1(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMRxBuffer1 in register */
#define  GET_I2CM_RX_BUFFER1(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMRxBuffer1 from register */
/** @} */


/**
 * @name RegI2CMRxBuffer2
 * @{
 */
// RegI2CMRxBuffer2.r32
#define  REG_I2CM_RX_BUFFER2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMRxBuffer2 */
#define  REG_I2CM_RX_BUFFER2_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMRxBuffer2 */

#define  I2CM_RX_BUFFER2_SHIFT                              0                             /**< Shift for I2CMRxBuffer2 */
#define  I2CM_RX_BUFFER2_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMRxBuffer2 */
#define  I2CM_RX_BUFFER2_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMRxBuffer2 */
#define  I2CM_RX_BUFFER2(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMRxBuffer2 in register */
#define  GET_I2CM_RX_BUFFER2(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMRxBuffer2 from register */
/** @} */


/**
 * @name RegI2CMRxBuffer3
 * @{
 */
// RegI2CMRxBuffer3.r32
#define  REG_I2CM_RX_BUFFER3_RESET_VALUE                    0x00000000u                   /**< Reset value of RegI2CMRxBuffer3 */
#define  REG_I2CM_RX_BUFFER3_MASK                           0xFFFFFFFFu                   /**< Mask for RegI2CMRxBuffer3 */

#define  I2CM_RX_BUFFER3_SHIFT                              0                             /**< Shift for I2CMRxBuffer3 */
#define  I2CM_RX_BUFFER3_MASK                               0xFFFFFFFFu                   /**< Mask for I2CMRxBuffer3 */
#define  I2CM_RX_BUFFER3_BMASK                              0xFFFFFFFFu                   /**< Base mask for I2CMRxBuffer3 */
#define  I2CM_RX_BUFFER3(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set I2CMRxBuffer3 in register */
#define  GET_I2CM_RX_BUFFER3(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get I2CMRxBuffer3 from register */
/** @} */



/** @} End of group I2CMaster_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_I2C_MASTER_H */
