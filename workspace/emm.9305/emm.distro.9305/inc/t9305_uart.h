////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_uart.h
///
/// @project    T9305
///
/// @brief      UART register and bit field definitions
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

#ifndef _T9305_UART_H
#define _T9305_UART_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup UART_Registers UART Register Map - registers
 * @{
 ******************************************************************************/


/** UART configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTCfg_t;


/** UART control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  UARTCtrl1;                                 /**< UART control register 1 */
        uint8_t  UARTCtrl2;                                 /**< UART control register 2 */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegUARTCtrl_t;


/** UART status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTStat_t;


/** UART Baud Rate configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t UARTClockDiv;                              /**< UART clock divisor */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  UARTOversampling;                          /**< UART oversampling factor */
    } regs;
} RegUARTBaudRate_t;


/** UART Receive FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTRxFIFO1B_t;


/** UART Receive FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTRxFIFO2B_t;


/** UART Receive FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTRxFIFO3B_t;


/** UART Receive FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTRxFIFO4B_t;


/** UART Transmit FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTTxFIFO1B_t;


/** UART Transmit FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTTxFIFO2B_t;


/** UART Transmit FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTTxFIFO3B_t;


/** UART Transmit FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTTxFIFO4B_t;


/** UART FIFO configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  UARTTxFIFOLimit;                           /**< UART TX FIFO limit */
        uint8_t  UARTRxFIFOLimit;                           /**< UART RX FIFO limit */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegUARTFIFOCfg_t;


/** UART FIFO control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUARTFIFOCtrl_t;


/** UART FIFO status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  UARTFIFOStat;                              /**< UART FIFO status */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  UARTTxFIFONumBytes;                        /**< UART TX FIFO - number of available bytes */
        uint8_t  UARTRxFIFONumBytes;                        /**< UART RX FIFO - number of available bytes */
    } regs;
} RegUARTFIFOStat_t;

/** @} end of group UART_Regs */



/***************************************************************************//**
 * @defgroup UART_RegMap UART Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegUARTCfg_t                                      RegUARTCfg;                   /**< UART configuration */
    __IO  RegUARTCtrl_t                                     RegUARTCtrl;                  /**< UART control */
    __I   RegUARTStat_t                                     RegUARTStat;                  /**< UART status */
    __IO  RegUARTBaudRate_t                                 RegUARTBaudRate;              /**< UART Baud Rate configuration */
    __I   RegUARTRxFIFO1B_t                                 RegUARTRxFIFO1B;              /**< UART Receive FIFO - 1 byte access */
    __I   RegUARTRxFIFO2B_t                                 RegUARTRxFIFO2B;              /**< UART Receive FIFO - 2 byte access */
    __I   RegUARTRxFIFO3B_t                                 RegUARTRxFIFO3B;              /**< UART Receive FIFO - 3 byte access */
    __I   RegUARTRxFIFO4B_t                                 RegUARTRxFIFO4B;              /**< UART Receive FIFO - 4 byte access */
    __O   RegUARTTxFIFO1B_t                                 RegUARTTxFIFO1B;              /**< UART Transmit FIFO - 1 byte access */
    __O   RegUARTTxFIFO2B_t                                 RegUARTTxFIFO2B;              /**< UART Transmit FIFO - 2 byte access */
    __O   RegUARTTxFIFO3B_t                                 RegUARTTxFIFO3B;              /**< UART Transmit FIFO - 3 byte access */
    __O   RegUARTTxFIFO4B_t                                 RegUARTTxFIFO4B;              /**< UART Transmit FIFO - 4 byte access */
    __IO  RegUARTFIFOCfg_t                                  RegUARTFIFOCfg;               /**< UART FIFO configuration */
    __O   RegUARTFIFOCtrl_t                                 RegUARTFIFOCtrl;              /**< UART FIFO control */
    __I   RegUARTFIFOStat_t                                 RegUARTFIFOStat;              /**< UART FIFO status */
} UART_RegMap_t;

/** @} end of group UART_RegMap */



/***************************************************************************//**
 * @defgroup UART_BitFields UART bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegUARTCfg
 * @{
 */
// RegUARTCfg.r32
#define  REG_UART_CFG_RESET_VALUE                           0x00000000u                   /**< Reset value of RegUARTCfg */
#define  REG_UART_CFG_MASK                                  0x0000003Fu                   /**< Mask for RegUARTCfg */

#define  UART_MSB_FIRST_SHIFT                               0                             /**< Shift for UARTMSBFirst */
#define  UART_MSB_FIRST_MASK                                0x00000001u                   /**< Mask for UARTMSBFirst */
#define  UART_MSB_FIRST_BMASK                               0x1u                          /**< Base mask for UARTMSBFirst */
#define  UART_MSB_FIRST(x)                                  (((x)&0x1u)<<0)               /**< Set UARTMSBFirst in register */
#define  GET_UART_MSB_FIRST(reg)                            (((reg)>>0)&0x1u)             /**< Get UARTMSBFirst from register */
#define  UART_PARITY_MODE_SHIFT                             1                             /**< Shift for UARTParityMode */
#define  UART_PARITY_MODE_MASK                              0x00000002u                   /**< Mask for UARTParityMode */
#define  UART_PARITY_MODE_BMASK                             0x1u                          /**< Base mask for UARTParityMode */
#define  UART_PARITY_MODE(x)                                (((x)&0x1u)<<1)               /**< Set UARTParityMode in register */
#define  GET_UART_PARITY_MODE(reg)                          (((reg)>>1)&0x1u)             /**< Get UARTParityMode from register */
#define  UART_EVEN_PARITY_SHIFT                             2                             /**< Shift for UARTEvenParity */
#define  UART_EVEN_PARITY_MASK                              0x00000004u                   /**< Mask for UARTEvenParity */
#define  UART_EVEN_PARITY_BMASK                             0x1u                          /**< Base mask for UARTEvenParity */
#define  UART_EVEN_PARITY(x)                                (((x)&0x1u)<<2)               /**< Set UARTEvenParity in register */
#define  GET_UART_EVEN_PARITY(reg)                          (((reg)>>2)&0x1u)             /**< Get UARTEvenParity from register */
#define  UART_FLOW_CTRL_EN_SHIFT                            3                             /**< Shift for UARTFlowCtrlEn */
#define  UART_FLOW_CTRL_EN_MASK                             0x00000008u                   /**< Mask for UARTFlowCtrlEn */
#define  UART_FLOW_CTRL_EN_BMASK                            0x1u                          /**< Base mask for UARTFlowCtrlEn */
#define  UART_FLOW_CTRL_EN(x)                               (((x)&0x1u)<<3)               /**< Set UARTFlowCtrlEn in register */
#define  GET_UART_FLOW_CTRL_EN(reg)                         (((reg)>>3)&0x1u)             /**< Get UARTFlowCtrlEn from register */
#define  UART_MAJORITY_DIS_SHIFT                            4                             /**< Shift for UARTMajorityDis */
#define  UART_MAJORITY_DIS_MASK                             0x00000010u                   /**< Mask for UARTMajorityDis */
#define  UART_MAJORITY_DIS_BMASK                            0x1u                          /**< Base mask for UARTMajorityDis */
#define  UART_MAJORITY_DIS(x)                               (((x)&0x1u)<<4)               /**< Set UARTMajorityDis in register */
#define  GET_UART_MAJORITY_DIS(reg)                         (((reg)>>4)&0x1u)             /**< Get UARTMajorityDis from register */
#define  UART_LOOP_BACK_EN_SHIFT                            5                             /**< Shift for UARTLoopBackEn */
#define  UART_LOOP_BACK_EN_MASK                             0x00000020u                   /**< Mask for UARTLoopBackEn */
#define  UART_LOOP_BACK_EN_BMASK                            0x1u                          /**< Base mask for UARTLoopBackEn */
#define  UART_LOOP_BACK_EN(x)                               (((x)&0x1u)<<5)               /**< Set UARTLoopBackEn in register */
#define  GET_UART_LOOP_BACK_EN(reg)                         (((reg)>>5)&0x1u)             /**< Get UARTLoopBackEn from register */
/** @} */


/**
 * @name RegUARTCtrl
 * @{
 */
// RegUARTCtrl.r32
#define  REG_UART_CTRL_RESET_VALUE                          0x00000000u                   /**< Reset value of RegUARTCtrl */
#define  REG_UART_CTRL_MASK                                 0x00000103u                   /**< Mask for RegUARTCtrl */

#define  UART_RX_EN_SHIFT                                   0                             /**< Shift for UARTRxEn */
#define  UART_RX_EN_MASK                                    0x00000001u                   /**< Mask for UARTRxEn */
#define  UART_RX_EN_BMASK                                   0x1u                          /**< Base mask for UARTRxEn */
#define  UART_RX_EN(x)                                      (((x)&0x1u)<<0)               /**< Set UARTRxEn in register */
#define  GET_UART_RX_EN(reg)                                (((reg)>>0)&0x1u)             /**< Get UARTRxEn from register */
#define  UART_TX_EN_SHIFT                                   1                             /**< Shift for UARTTxEn */
#define  UART_TX_EN_MASK                                    0x00000002u                   /**< Mask for UARTTxEn */
#define  UART_TX_EN_BMASK                                   0x1u                          /**< Base mask for UARTTxEn */
#define  UART_TX_EN(x)                                      (((x)&0x1u)<<1)               /**< Set UARTTxEn in register */
#define  GET_UART_TX_EN(reg)                                (((reg)>>1)&0x1u)             /**< Get UARTTxEn from register */
#define  UART_FORCE_RTS_SHIFT                               8                             /**< Shift for UARTForceRTS */
#define  UART_FORCE_RTS_MASK                                0x00000100u                   /**< Mask for UARTForceRTS */
#define  UART_FORCE_RTS_BMASK                               0x1u                          /**< Base mask for UARTForceRTS */
#define  UART_FORCE_RTS(x)                                  (((x)&0x1u)<<8)               /**< Set UARTForceRTS in register */
#define  GET_UART_FORCE_RTS(reg)                            (((reg)>>8)&0x1u)             /**< Get UARTForceRTS from register */

// RegUARTCtrl.regs.UARTCtrl1
#define  UART_CTRL1_GSHIFT                                  0                             /**< Shift for group UARTCtrl1 */
#define  UART_CTRL1_GSIZE                                   8                             /**< Size of group UARTCtrl1 */
#define  UART_CTRL1_GMASK                                   0x000000FFu                   /**< Mask for group UARTCtrl1 */

#define  UART_RX_EN_RSHIFT                                  0                             /**< Shift for UARTRxEn */
#define  UART_RX_EN_RMASK                                   0x01u                         /**< Mask for UARTRxEn */
#define  UART_RX_EN_RBMASK                                  0x1u                          /**< Base mask for UARTRxEn */
#define  UART_RX_EN_R(x)                                    (((x)&0x1u)<<0)               /**< Set UARTRxEn in register */
#define  GET_UART_RX_EN_R(reg)                              (((reg)>>0)&0x1u)             /**< Get UARTRxEn from register */
#define  UART_TX_EN_RSHIFT                                  1                             /**< Shift for UARTTxEn */
#define  UART_TX_EN_RMASK                                   0x02u                         /**< Mask for UARTTxEn */
#define  UART_TX_EN_RBMASK                                  0x1u                          /**< Base mask for UARTTxEn */
#define  UART_TX_EN_R(x)                                    (((x)&0x1u)<<1)               /**< Set UARTTxEn in register */
#define  GET_UART_TX_EN_R(reg)                              (((reg)>>1)&0x1u)             /**< Get UARTTxEn from register */

// RegUARTCtrl.regs.UARTCtrl2
#define  UART_CTRL2_GSHIFT                                  8                             /**< Shift for group UARTCtrl2 */
#define  UART_CTRL2_GSIZE                                   8                             /**< Size of group UARTCtrl2 */
#define  UART_CTRL2_GMASK                                   0x0000FF00u                   /**< Mask for group UARTCtrl2 */

#define  UART_FORCE_RTS_RSHIFT                              0                             /**< Shift for UARTForceRTS */
#define  UART_FORCE_RTS_RMASK                               0x01u                         /**< Mask for UARTForceRTS */
#define  UART_FORCE_RTS_RBMASK                              0x1u                          /**< Base mask for UARTForceRTS */
#define  UART_FORCE_RTS_R(x)                                (((x)&0x1u)<<0)               /**< Set UARTForceRTS in register */
#define  GET_UART_FORCE_RTS_R(reg)                          (((reg)>>0)&0x1u)             /**< Get UARTForceRTS from register */
/** @} */


/**
 * @name RegUARTStat
 * @{
 */
// RegUARTStat.r32
#define  REG_UART_STAT_RESET_VALUE                          0x00000000u                   /**< Reset value of RegUARTStat */
#define  REG_UART_STAT_MASK                                 0x00000003u                   /**< Mask for RegUARTStat */

#define  UART_RX_BUSY_SHIFT                                 0                             /**< Shift for UARTRxBusy */
#define  UART_RX_BUSY_MASK                                  0x00000001u                   /**< Mask for UARTRxBusy */
#define  UART_RX_BUSY_BMASK                                 0x1u                          /**< Base mask for UARTRxBusy */
#define  UART_RX_BUSY(x)                                    (((x)&0x1u)<<0)               /**< Set UARTRxBusy in register */
#define  GET_UART_RX_BUSY(reg)                              (((reg)>>0)&0x1u)             /**< Get UARTRxBusy from register */
#define  UART_TX_BUSY_SHIFT                                 1                             /**< Shift for UARTTxBusy */
#define  UART_TX_BUSY_MASK                                  0x00000002u                   /**< Mask for UARTTxBusy */
#define  UART_TX_BUSY_BMASK                                 0x1u                          /**< Base mask for UARTTxBusy */
#define  UART_TX_BUSY(x)                                    (((x)&0x1u)<<1)               /**< Set UARTTxBusy in register */
#define  GET_UART_TX_BUSY(reg)                              (((reg)>>1)&0x1u)             /**< Get UARTTxBusy from register */
/** @} */


/**
 * @name RegUARTBaudRate
 * @{
 */
// RegUARTBaudRate.r32
#define  REG_UART_BAUD_RATE_RESET_VALUE                     0x0D000010u                   /**< Reset value of RegUARTBaudRate */
#define  REG_UART_BAUD_RATE_MASK                            0x1F003FFFu                   /**< Mask for RegUARTBaudRate */

#define  UART_CLOCK_DIV_SHIFT                               0                             /**< Shift for UARTClockDiv */
#define  UART_CLOCK_DIV_MASK                                0x00003FFFu                   /**< Mask for UARTClockDiv */
#define  UART_CLOCK_DIV_BMASK                               0x3FFFu                       /**< Base mask for UARTClockDiv */
#define  UART_CLOCK_DIV(x)                                  (((x)&0x3FFFu)<<0)            /**< Set UARTClockDiv in register */
#define  GET_UART_CLOCK_DIV(reg)                            (((reg)>>0)&0x3FFFu)          /**< Get UARTClockDiv from register */
#define  UART_OVERSAMPLING_SHIFT                            24                            /**< Shift for UARTOversampling */
#define  UART_OVERSAMPLING_MASK                             0x1F000000u                   /**< Mask for UARTOversampling */
#define  UART_OVERSAMPLING_BMASK                            0x1Fu                         /**< Base mask for UARTOversampling */
#define  UART_OVERSAMPLING(x)                               (((x)&0x1Fu)<<24)             /**< Set UARTOversampling in register */
#define  GET_UART_OVERSAMPLING(reg)                         (((reg)>>24)&0x1Fu)           /**< Get UARTOversampling from register */

// RegUARTBaudRate.regs.UARTClockDiv
#define  UART_CLOCK_DIV_GSHIFT                              0                             /**< Shift for group UARTClockDiv */
#define  UART_CLOCK_DIV_GSIZE                               16                            /**< Size of group UARTClockDiv */
#define  UART_CLOCK_DIV_GMASK                               0x0000FFFFu                   /**< Mask for group UARTClockDiv */

#define  UART_CLOCK_DIV_RSHIFT                              0                             /**< Shift for UARTClockDiv */
#define  UART_CLOCK_DIV_RMASK                               0x00003FFFu                   /**< Mask for UARTClockDiv */
#define  UART_CLOCK_DIV_RBMASK                              0x3FFFu                       /**< Base mask for UARTClockDiv */
#define  UART_CLOCK_DIV_R(x)                                (((x)&0x3FFFu)<<0)            /**< Set UARTClockDiv in register */
#define  GET_UART_CLOCK_DIV_R(reg)                          (((reg)>>0)&0x3FFFu)          /**< Get UARTClockDiv from register */

// RegUARTBaudRate.regs.UARTOversampling
#define  UART_OVERSAMPLING_GSHIFT                           24                            /**< Shift for group UARTOversampling */
#define  UART_OVERSAMPLING_GSIZE                            8                             /**< Size of group UARTOversampling */
#define  UART_OVERSAMPLING_GMASK                            0xFF000000u                   /**< Mask for group UARTOversampling */

#define  UART_OVERSAMPLING_RSHIFT                           0                             /**< Shift for UARTOversampling */
#define  UART_OVERSAMPLING_RMASK                            0x0000001Fu                   /**< Mask for UARTOversampling */
#define  UART_OVERSAMPLING_RBMASK                           0x1Fu                         /**< Base mask for UARTOversampling */
#define  UART_OVERSAMPLING_R(x)                             (((x)&0x1Fu)<<0)              /**< Set UARTOversampling in register */
#define  GET_UART_OVERSAMPLING_R(reg)                       (((reg)>>0)&0x1Fu)            /**< Get UARTOversampling from register */
/** @} */


/**
 * @name RegUARTRxFIFO1B
 * @{
 */
// RegUARTRxFIFO1B.r32
#define  REG_UART_RX_FIFO_1B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTRxFIFO1B */
#define  REG_UART_RX_FIFO_1B_MASK                           0x000000FFu                   /**< Mask for RegUARTRxFIFO1B */

#define  UART_RX_FIFO_1B_SHIFT                              0                             /**< Shift for UARTRxFIFO1B */
#define  UART_RX_FIFO_1B_MASK                               0x000000FFu                   /**< Mask for UARTRxFIFO1B */
#define  UART_RX_FIFO_1B_BMASK                              0xFFu                         /**< Base mask for UARTRxFIFO1B */
#define  UART_RX_FIFO_1B(x)                                 (((x)&0xFFu)<<0)              /**< Set UARTRxFIFO1B in register */
#define  GET_UART_RX_FIFO_1B(reg)                           (((reg)>>0)&0xFFu)            /**< Get UARTRxFIFO1B from register */
/** @} */


/**
 * @name RegUARTRxFIFO2B
 * @{
 */
// RegUARTRxFIFO2B.r32
#define  REG_UART_RX_FIFO_2B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTRxFIFO2B */
#define  REG_UART_RX_FIFO_2B_MASK                           0x0000FFFFu                   /**< Mask for RegUARTRxFIFO2B */

#define  UART_RX_FIFO_2B_SHIFT                              0                             /**< Shift for UARTRxFIFO2B */
#define  UART_RX_FIFO_2B_MASK                               0x0000FFFFu                   /**< Mask for UARTRxFIFO2B */
#define  UART_RX_FIFO_2B_BMASK                              0xFFFFu                       /**< Base mask for UARTRxFIFO2B */
#define  UART_RX_FIFO_2B(x)                                 (((x)&0xFFFFu)<<0)            /**< Set UARTRxFIFO2B in register */
#define  GET_UART_RX_FIFO_2B(reg)                           (((reg)>>0)&0xFFFFu)          /**< Get UARTRxFIFO2B from register */
/** @} */


/**
 * @name RegUARTRxFIFO3B
 * @{
 */
// RegUARTRxFIFO3B.r32
#define  REG_UART_RX_FIFO_3B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTRxFIFO3B */
#define  REG_UART_RX_FIFO_3B_MASK                           0x00FFFFFFu                   /**< Mask for RegUARTRxFIFO3B */

#define  UART_RX_FIFO_3B_SHIFT                              0                             /**< Shift for UARTRxFIFO3B */
#define  UART_RX_FIFO_3B_MASK                               0x00FFFFFFu                   /**< Mask for UARTRxFIFO3B */
#define  UART_RX_FIFO_3B_BMASK                              0xFFFFFFu                     /**< Base mask for UARTRxFIFO3B */
#define  UART_RX_FIFO_3B(x)                                 (((x)&0xFFFFFFu)<<0)          /**< Set UARTRxFIFO3B in register */
#define  GET_UART_RX_FIFO_3B(reg)                           (((reg)>>0)&0xFFFFFFu)        /**< Get UARTRxFIFO3B from register */
/** @} */


/**
 * @name RegUARTRxFIFO4B
 * @{
 */
// RegUARTRxFIFO4B.r32
#define  REG_UART_RX_FIFO_4B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTRxFIFO4B */
#define  REG_UART_RX_FIFO_4B_MASK                           0xFFFFFFFFu                   /**< Mask for RegUARTRxFIFO4B */

#define  UART_RX_FIFO_4B_SHIFT                              0                             /**< Shift for UARTRxFIFO4B */
#define  UART_RX_FIFO_4B_MASK                               0xFFFFFFFFu                   /**< Mask for UARTRxFIFO4B */
#define  UART_RX_FIFO_4B_BMASK                              0xFFFFFFFFu                   /**< Base mask for UARTRxFIFO4B */
#define  UART_RX_FIFO_4B(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set UARTRxFIFO4B in register */
#define  GET_UART_RX_FIFO_4B(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get UARTRxFIFO4B from register */
/** @} */


/**
 * @name RegUARTTxFIFO1B
 * @{
 */
// RegUARTTxFIFO1B.r32
#define  REG_UART_TX_FIFO_1B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTTxFIFO1B */
#define  REG_UART_TX_FIFO_1B_MASK                           0x000000FFu                   /**< Mask for RegUARTTxFIFO1B */

#define  UART_TX_FIFO_1B_SHIFT                              0                             /**< Shift for UARTTxFIFO1B */
#define  UART_TX_FIFO_1B_MASK                               0x000000FFu                   /**< Mask for UARTTxFIFO1B */
#define  UART_TX_FIFO_1B_BMASK                              0xFFu                         /**< Base mask for UARTTxFIFO1B */
#define  UART_TX_FIFO_1B(x)                                 (((x)&0xFFu)<<0)              /**< Set UARTTxFIFO1B in register */
#define  GET_UART_TX_FIFO_1B(reg)                           (((reg)>>0)&0xFFu)            /**< Get UARTTxFIFO1B from register */
/** @} */


/**
 * @name RegUARTTxFIFO2B
 * @{
 */
// RegUARTTxFIFO2B.r32
#define  REG_UART_TX_FIFO_2B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTTxFIFO2B */
#define  REG_UART_TX_FIFO_2B_MASK                           0x0000FFFFu                   /**< Mask for RegUARTTxFIFO2B */

#define  UART_TX_FIFO_2B_SHIFT                              0                             /**< Shift for UARTTxFIFO2B */
#define  UART_TX_FIFO_2B_MASK                               0x0000FFFFu                   /**< Mask for UARTTxFIFO2B */
#define  UART_TX_FIFO_2B_BMASK                              0xFFFFu                       /**< Base mask for UARTTxFIFO2B */
#define  UART_TX_FIFO_2B(x)                                 (((x)&0xFFFFu)<<0)            /**< Set UARTTxFIFO2B in register */
#define  GET_UART_TX_FIFO_2B(reg)                           (((reg)>>0)&0xFFFFu)          /**< Get UARTTxFIFO2B from register */
/** @} */


/**
 * @name RegUARTTxFIFO3B
 * @{
 */
// RegUARTTxFIFO3B.r32
#define  REG_UART_TX_FIFO_3B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTTxFIFO3B */
#define  REG_UART_TX_FIFO_3B_MASK                           0x00FFFFFFu                   /**< Mask for RegUARTTxFIFO3B */

#define  UART_TX_FIFO_3B_SHIFT                              0                             /**< Shift for UARTTxFIFO3B */
#define  UART_TX_FIFO_3B_MASK                               0x00FFFFFFu                   /**< Mask for UARTTxFIFO3B */
#define  UART_TX_FIFO_3B_BMASK                              0xFFFFFFu                     /**< Base mask for UARTTxFIFO3B */
#define  UART_TX_FIFO_3B(x)                                 (((x)&0xFFFFFFu)<<0)          /**< Set UARTTxFIFO3B in register */
#define  GET_UART_TX_FIFO_3B(reg)                           (((reg)>>0)&0xFFFFFFu)        /**< Get UARTTxFIFO3B from register */
/** @} */


/**
 * @name RegUARTTxFIFO4B
 * @{
 */
// RegUARTTxFIFO4B.r32
#define  REG_UART_TX_FIFO_4B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUARTTxFIFO4B */
#define  REG_UART_TX_FIFO_4B_MASK                           0xFFFFFFFFu                   /**< Mask for RegUARTTxFIFO4B */

#define  UART_TX_FIFO_4B_SHIFT                              0                             /**< Shift for UARTTxFIFO4B */
#define  UART_TX_FIFO_4B_MASK                               0xFFFFFFFFu                   /**< Mask for UARTTxFIFO4B */
#define  UART_TX_FIFO_4B_BMASK                              0xFFFFFFFFu                   /**< Base mask for UARTTxFIFO4B */
#define  UART_TX_FIFO_4B(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set UARTTxFIFO4B in register */
#define  GET_UART_TX_FIFO_4B(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get UARTTxFIFO4B from register */
/** @} */


/**
 * @name RegUARTFIFOCfg
 * @{
 */
// RegUARTFIFOCfg.r32
#define  REG_UART_FIFO_CFG_RESET_VALUE                      0x00000808u                   /**< Reset value of RegUARTFIFOCfg */
#define  REG_UART_FIFO_CFG_MASK                             0x00001F1Fu                   /**< Mask for RegUARTFIFOCfg */

#define  UART_TX_FIFO_LIMIT_SHIFT                           0                             /**< Shift for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_MASK                            0x0000001Fu                   /**< Mask for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_BMASK                           0x1Fu                         /**< Base mask for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT(x)                              (((x)&0x1Fu)<<0)              /**< Set UARTTxFIFOLimit in register */
#define  GET_UART_TX_FIFO_LIMIT(reg)                        (((reg)>>0)&0x1Fu)            /**< Get UARTTxFIFOLimit from register */
#define  UART_RX_FIFO_LIMIT_SHIFT                           8                             /**< Shift for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_MASK                            0x00001F00u                   /**< Mask for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_BMASK                           0x1Fu                         /**< Base mask for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT(x)                              (((x)&0x1Fu)<<8)              /**< Set UARTRxFIFOLimit in register */
#define  GET_UART_RX_FIFO_LIMIT(reg)                        (((reg)>>8)&0x1Fu)            /**< Get UARTRxFIFOLimit from register */

// RegUARTFIFOCfg.regs.UARTTxFIFOLimit
#define  UART_TX_FIFO_LIMIT_GSHIFT                          0                             /**< Shift for group UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_GSIZE                           8                             /**< Size of group UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_GMASK                           0x000000FFu                   /**< Mask for group UARTTxFIFOLimit */

#define  UART_TX_FIFO_LIMIT_RSHIFT                          0                             /**< Shift for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_RMASK                           0x0000001Fu                   /**< Mask for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_RBMASK                          0x1Fu                         /**< Base mask for UARTTxFIFOLimit */
#define  UART_TX_FIFO_LIMIT_R(x)                            (((x)&0x1Fu)<<0)              /**< Set UARTTxFIFOLimit in register */
#define  GET_UART_TX_FIFO_LIMIT_R(reg)                      (((reg)>>0)&0x1Fu)            /**< Get UARTTxFIFOLimit from register */

// RegUARTFIFOCfg.regs.UARTRxFIFOLimit
#define  UART_RX_FIFO_LIMIT_GSHIFT                          8                             /**< Shift for group UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_GSIZE                           8                             /**< Size of group UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_GMASK                           0x0000FF00u                   /**< Mask for group UARTRxFIFOLimit */

#define  UART_RX_FIFO_LIMIT_RSHIFT                          0                             /**< Shift for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_RMASK                           0x0000001Fu                   /**< Mask for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_RBMASK                          0x1Fu                         /**< Base mask for UARTRxFIFOLimit */
#define  UART_RX_FIFO_LIMIT_R(x)                            (((x)&0x1Fu)<<0)              /**< Set UARTRxFIFOLimit in register */
#define  GET_UART_RX_FIFO_LIMIT_R(reg)                      (((reg)>>0)&0x1Fu)            /**< Get UARTRxFIFOLimit from register */
/** @} */


/**
 * @name RegUARTFIFOCtrl
 * @{
 */
// RegUARTFIFOCtrl.r32
#define  REG_UART_FIFO_CTRL_RESET_VALUE                     0x00000000u                   /**< Reset value of RegUARTFIFOCtrl */
#define  REG_UART_FIFO_CTRL_MASK                            0x00000003u                   /**< Mask for RegUARTFIFOCtrl */

#define  UART_TX_FIFO_FLUSH_SHIFT                           0                             /**< Shift for UARTTxFIFOFlush */
#define  UART_TX_FIFO_FLUSH_MASK                            0x00000001u                   /**< Mask for UARTTxFIFOFlush */
#define  UART_TX_FIFO_FLUSH_BMASK                           0x1u                          /**< Base mask for UARTTxFIFOFlush */
#define  UART_TX_FIFO_FLUSH(x)                              (((x)&0x1u)<<0)               /**< Set UARTTxFIFOFlush in register */
#define  GET_UART_TX_FIFO_FLUSH(reg)                        (((reg)>>0)&0x1u)             /**< Get UARTTxFIFOFlush from register */
#define  UART_RX_FIFO_FLUSH_SHIFT                           1                             /**< Shift for UARTRxFIFOFlush */
#define  UART_RX_FIFO_FLUSH_MASK                            0x00000002u                   /**< Mask for UARTRxFIFOFlush */
#define  UART_RX_FIFO_FLUSH_BMASK                           0x1u                          /**< Base mask for UARTRxFIFOFlush */
#define  UART_RX_FIFO_FLUSH(x)                              (((x)&0x1u)<<1)               /**< Set UARTRxFIFOFlush in register */
#define  GET_UART_RX_FIFO_FLUSH(reg)                        (((reg)>>1)&0x1u)             /**< Get UARTRxFIFOFlush from register */
/** @} */


/**
 * @name RegUARTFIFOStat
 * @{
 */
// RegUARTFIFOStat.r32
#define  REG_UART_FIFO_STAT_RESET_VALUE                     0x00000000u                   /**< Reset value of RegUARTFIFOStat */
#define  REG_UART_FIFO_STAT_MASK                            0x7F7F0077u                   /**< Mask for RegUARTFIFOStat */

#define  UART_TX_FIFO_EMPTY_SHIFT                           0                             /**< Shift for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY_MASK                            0x00000001u                   /**< Mask for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY_BMASK                           0x1u                          /**< Base mask for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY(x)                              (((x)&0x1u)<<0)               /**< Set UARTTxFIFOEmpty in register */
#define  GET_UART_TX_FIFO_EMPTY(reg)                        (((reg)>>0)&0x1u)             /**< Get UARTTxFIFOEmpty from register */
#define  UART_TX_FIFO_LIMIT_DET_SHIFT                       1                             /**< Shift for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET_MASK                        0x00000002u                   /**< Mask for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET_BMASK                       0x1u                          /**< Base mask for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET(x)                          (((x)&0x1u)<<1)               /**< Set UARTTxFIFOLimitDet in register */
#define  GET_UART_TX_FIFO_LIMIT_DET(reg)                    (((reg)>>1)&0x1u)             /**< Get UARTTxFIFOLimitDet from register */
#define  UART_TX_FIFO_FULL_SHIFT                            2                             /**< Shift for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL_MASK                             0x00000004u                   /**< Mask for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL_BMASK                            0x1u                          /**< Base mask for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL(x)                               (((x)&0x1u)<<2)               /**< Set UARTTxFIFOFull in register */
#define  GET_UART_TX_FIFO_FULL(reg)                         (((reg)>>2)&0x1u)             /**< Get UARTTxFIFOFull from register */
#define  UART_RX_FIFO_EMPTY_SHIFT                           4                             /**< Shift for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY_MASK                            0x00000010u                   /**< Mask for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY_BMASK                           0x1u                          /**< Base mask for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY(x)                              (((x)&0x1u)<<4)               /**< Set UARTRxFIFOEmpty in register */
#define  GET_UART_RX_FIFO_EMPTY(reg)                        (((reg)>>4)&0x1u)             /**< Get UARTRxFIFOEmpty from register */
#define  UART_RX_FIFO_LIMIT_DET_SHIFT                       5                             /**< Shift for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET_MASK                        0x00000020u                   /**< Mask for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET_BMASK                       0x1u                          /**< Base mask for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET(x)                          (((x)&0x1u)<<5)               /**< Set UARTRxFIFOLimitDet in register */
#define  GET_UART_RX_FIFO_LIMIT_DET(reg)                    (((reg)>>5)&0x1u)             /**< Get UARTRxFIFOLimitDet from register */
#define  UART_RX_FIFO_FULL_SHIFT                            6                             /**< Shift for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL_MASK                             0x00000040u                   /**< Mask for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL_BMASK                            0x1u                          /**< Base mask for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL(x)                               (((x)&0x1u)<<6)               /**< Set UARTRxFIFOFull in register */
#define  GET_UART_RX_FIFO_FULL(reg)                         (((reg)>>6)&0x1u)             /**< Get UARTRxFIFOFull from register */
#define  UART_TX_FIFO_NUM_BYTES_SHIFT                       16                            /**< Shift for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_MASK                        0x007F0000u                   /**< Mask for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_BMASK                       0x7Fu                         /**< Base mask for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES(x)                          (((x)&0x7Fu)<<16)             /**< Set UARTTxFIFONumBytes in register */
#define  GET_UART_TX_FIFO_NUM_BYTES(reg)                    (((reg)>>16)&0x7Fu)           /**< Get UARTTxFIFONumBytes from register */
#define  UART_RX_FIFO_NUM_BYTES_SHIFT                       24                            /**< Shift for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_MASK                        0x7F000000u                   /**< Mask for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_BMASK                       0x7Fu                         /**< Base mask for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES(x)                          (((x)&0x7Fu)<<24)             /**< Set UARTRxFIFONumBytes in register */
#define  GET_UART_RX_FIFO_NUM_BYTES(reg)                    (((reg)>>24)&0x7Fu)           /**< Get UARTRxFIFONumBytes from register */

// RegUARTFIFOStat.regs.UARTFIFOStat
#define  UART_FIFO_STAT_GSHIFT                              0                             /**< Shift for group UARTFIFOStat */
#define  UART_FIFO_STAT_GSIZE                               8                             /**< Size of group UARTFIFOStat */
#define  UART_FIFO_STAT_GMASK                               0x000000FFu                   /**< Mask for group UARTFIFOStat */

#define  UART_TX_FIFO_EMPTY_RSHIFT                          0                             /**< Shift for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY_RMASK                           0x01u                         /**< Mask for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY_RBMASK                          0x1u                          /**< Base mask for UARTTxFIFOEmpty */
#define  UART_TX_FIFO_EMPTY_R(x)                            (((x)&0x1u)<<0)               /**< Set UARTTxFIFOEmpty in register */
#define  GET_UART_TX_FIFO_EMPTY_R(reg)                      (((reg)>>0)&0x1u)             /**< Get UARTTxFIFOEmpty from register */
#define  UART_TX_FIFO_LIMIT_DET_RSHIFT                      1                             /**< Shift for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET_RMASK                       0x02u                         /**< Mask for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET_RBMASK                      0x1u                          /**< Base mask for UARTTxFIFOLimitDet */
#define  UART_TX_FIFO_LIMIT_DET_R(x)                        (((x)&0x1u)<<1)               /**< Set UARTTxFIFOLimitDet in register */
#define  GET_UART_TX_FIFO_LIMIT_DET_R(reg)                  (((reg)>>1)&0x1u)             /**< Get UARTTxFIFOLimitDet from register */
#define  UART_TX_FIFO_FULL_RSHIFT                           2                             /**< Shift for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL_RMASK                            0x04u                         /**< Mask for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL_RBMASK                           0x1u                          /**< Base mask for UARTTxFIFOFull */
#define  UART_TX_FIFO_FULL_R(x)                             (((x)&0x1u)<<2)               /**< Set UARTTxFIFOFull in register */
#define  GET_UART_TX_FIFO_FULL_R(reg)                       (((reg)>>2)&0x1u)             /**< Get UARTTxFIFOFull from register */
#define  UART_RX_FIFO_EMPTY_RSHIFT                          4                             /**< Shift for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY_RMASK                           0x10u                         /**< Mask for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY_RBMASK                          0x1u                          /**< Base mask for UARTRxFIFOEmpty */
#define  UART_RX_FIFO_EMPTY_R(x)                            (((x)&0x1u)<<4)               /**< Set UARTRxFIFOEmpty in register */
#define  GET_UART_RX_FIFO_EMPTY_R(reg)                      (((reg)>>4)&0x1u)             /**< Get UARTRxFIFOEmpty from register */
#define  UART_RX_FIFO_LIMIT_DET_RSHIFT                      5                             /**< Shift for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET_RMASK                       0x20u                         /**< Mask for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET_RBMASK                      0x1u                          /**< Base mask for UARTRxFIFOLimitDet */
#define  UART_RX_FIFO_LIMIT_DET_R(x)                        (((x)&0x1u)<<5)               /**< Set UARTRxFIFOLimitDet in register */
#define  GET_UART_RX_FIFO_LIMIT_DET_R(reg)                  (((reg)>>5)&0x1u)             /**< Get UARTRxFIFOLimitDet from register */
#define  UART_RX_FIFO_FULL_RSHIFT                           6                             /**< Shift for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL_RMASK                            0x40u                         /**< Mask for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL_RBMASK                           0x1u                          /**< Base mask for UARTRxFIFOFull */
#define  UART_RX_FIFO_FULL_R(x)                             (((x)&0x1u)<<6)               /**< Set UARTRxFIFOFull in register */
#define  GET_UART_RX_FIFO_FULL_R(reg)                       (((reg)>>6)&0x1u)             /**< Get UARTRxFIFOFull from register */

// RegUARTFIFOStat.regs.UARTTxFIFONumBytes
#define  UART_TX_FIFO_NUM_BYTES_GSHIFT                      16                            /**< Shift for group UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_GSIZE                       8                             /**< Size of group UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_GMASK                       0x00FF0000u                   /**< Mask for group UARTTxFIFONumBytes */

#define  UART_TX_FIFO_NUM_BYTES_RSHIFT                      0                             /**< Shift for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_RMASK                       0x7Fu                         /**< Mask for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_RBMASK                      0x7Fu                         /**< Base mask for UARTTxFIFONumBytes */
#define  UART_TX_FIFO_NUM_BYTES_R(x)                        (((x)&0x7Fu)<<0)              /**< Set UARTTxFIFONumBytes in register */
#define  GET_UART_TX_FIFO_NUM_BYTES_R(reg)                  (((reg)>>0)&0x7Fu)            /**< Get UARTTxFIFONumBytes from register */

// RegUARTFIFOStat.regs.UARTRxFIFONumBytes
#define  UART_RX_FIFO_NUM_BYTES_GSHIFT                      24                            /**< Shift for group UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_GSIZE                       8                             /**< Size of group UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_GMASK                       0xFF000000u                   /**< Mask for group UARTRxFIFONumBytes */

#define  UART_RX_FIFO_NUM_BYTES_RSHIFT                      0                             /**< Shift for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_RMASK                       0x7Fu                         /**< Mask for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_RBMASK                      0x7Fu                         /**< Base mask for UARTRxFIFONumBytes */
#define  UART_RX_FIFO_NUM_BYTES_R(x)                        (((x)&0x7Fu)<<0)              /**< Set UARTRxFIFONumBytes in register */
#define  GET_UART_RX_FIFO_NUM_BYTES_R(reg)                  (((reg)>>0)&0x7Fu)            /**< Get UARTRxFIFONumBytes from register */
/** @} */



/** @} End of group UART_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_UART_H */
