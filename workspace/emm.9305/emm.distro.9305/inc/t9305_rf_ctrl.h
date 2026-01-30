////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_rf_ctrl.h
///
/// @project    T9305
///
/// @brief      RF Controller register and bit field definitions
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

#ifndef _T9305_RF_CTRL_H
#define _T9305_RF_CTRL_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup RfCtrl_Registers Rf Controller Register Map - registers
 * @{
 ******************************************************************************/


/** RF controller control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcCtrlSw;                                 /**< SW control */
        uint8_t  RfcCtrlHw;                                 /**< HW control */
        uint8_t  RfcEn;                                     /**< Enable RF controller */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegRfcCtrl_t;


/** RF controller configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcStopPp;                                 /**< Stop PP operation */
        uint8_t  RfcRxTimeoutEn;                            /**< Rx timeout enable */
        uint8_t  RfcSpiSpeed;                               /**< SPI speed used for RF IP communication */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegRfcCfg_t;


/** RF controller status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfcStatus_t;


/** MAC transition configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcMacEn;                                  /**< MAC enable */
        uint8_t  RfcMacCfg;                                 /**< MAC mode configuration */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegRfcMacCfg_t;


/** MAC transition timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t RfcRxMacTime;                              /**< Time to wait after Rx mode, granularity=0.25us */
        uint16_t RfcTxMacTime;                              /**< Time to wait after Tx mode, granularity=0.25us */
    } regs;
} RegRfcMacTime_t;


/** Radio start timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t RfcTxStartTime;                            /**< Time needed for radio to start in Tx mode, granularity=0.25us */
        uint16_t RfcRxStartTime;                            /**< Time needed for radio to start in Rx mode, granularity=0.25us */
    } regs;
} RegRfcStartTime_t;


/** Radio stop timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcStopTime;                               /**< Time needed for radio to stop, granularity=0.25us */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
        uint8_t  RESERVED2;                                 /**< RESERVED */
    } regs;
} RegRfcStopTime_t;


/** External PA and LNA timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcExtPaStartTime;                         /**< Time needed for external PA to start, granularity=0.25us */
        uint8_t  RfcExtLnaStartTime;                        /**< Time needed for external LNA to start, granularity=0.25us */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegRfcPaLnaTime_t;


/** Rx timeout for syncword receiving */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfcRxTimeout_t;


/** RF IP mirrored register - BURST_CFG_TXRX */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfcMirrBurstCfgTxrx_t;


/** RF IP mirrored register - RSSI */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfcRssi_t;


/** RF configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RfcRfIqSel;                                /**< IQ Selection */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
        uint8_t  RESERVED2;                                 /**< RESERVED */
    } regs;
} RegRfcRfCfg_t;

/** @} end of group RfCtrl_Regs */



/***************************************************************************//**
 * @defgroup RfCtrl_RegMap Rf Controller Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegRfcCtrl_t                                      RegRfcCtrl;                   /**< RF controller control */
    __IO  RegRfcCfg_t                                       RegRfcCfg;                    /**< RF controller configuration */
    __I   RegRfcStatus_t                                    RegRfcStatus;                 /**< RF controller status */
    __IO  RegRfcMacCfg_t                                    RegRfcMacCfg;                 /**< MAC transition configuration */
    __IO  RegRfcMacTime_t                                   RegRfcMacTime;                /**< MAC transition timing */
    __IO  RegRfcStartTime_t                                 RegRfcStartTime;              /**< Radio start timing */
    __IO  RegRfcStopTime_t                                  RegRfcStopTime;               /**< Radio stop timing */
    __IO  RegRfcPaLnaTime_t                                 RegRfcPaLnaTime;              /**< External PA and LNA timing */
    __IO  RegRfcRxTimeout_t                                 RegRfcRxTimeout;              /**< Rx timeout for syncword receiving */
    __IO  RegRfcMirrBurstCfgTxrx_t                          RegRfcMirrBurstCfgTxrx;       /**< RF IP mirrored register - BURST_CFG_TXRX */
    __I   RegRfcRssi_t                                      RegRfcRssi;                   /**< RF IP mirrored register - RSSI */
    __IO  RegRfcRfCfg_t                                     RegRfcRfCfg;                  /**< RF configuration */
} RfCtrl_RegMap_t;

/** @} end of group RfCtrl_RegMap */



/***************************************************************************//**
 * @defgroup RfCtrl_BitFields RfCtrl bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegRfcCtrl
 * @{
 */
// RegRfcCtrl.r32
#define  REG_RFC_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRfcCtrl */
#define  REG_RFC_CTRL_MASK                                  0x00010307u                   /**< Mask for RegRfcCtrl */

#define  RFC_START_TX_SHIFT                                 0                             /**< Shift for RfcStartTx */
#define  RFC_START_TX_MASK                                  0x00000001u                   /**< Mask for RfcStartTx */
#define  RFC_START_TX_BMASK                                 0x1u                          /**< Base mask for RfcStartTx */
#define  RFC_START_TX(x)                                    (((x)&0x1u)<<0)               /**< Set RfcStartTx in register */
#define  GET_RFC_START_TX(reg)                              (((reg)>>0)&0x1u)             /**< Get RfcStartTx from register */
#define  RFC_START_RX_SHIFT                                 1                             /**< Shift for RfcStartRx */
#define  RFC_START_RX_MASK                                  0x00000002u                   /**< Mask for RfcStartRx */
#define  RFC_START_RX_BMASK                                 0x1u                          /**< Base mask for RfcStartRx */
#define  RFC_START_RX(x)                                    (((x)&0x1u)<<1)               /**< Set RfcStartRx in register */
#define  GET_RFC_START_RX(reg)                              (((reg)>>1)&0x1u)             /**< Get RfcStartRx from register */
#define  RFC_STOP_SHIFT                                     2                             /**< Shift for RfcStop */
#define  RFC_STOP_MASK                                      0x00000004u                   /**< Mask for RfcStop */
#define  RFC_STOP_BMASK                                     0x1u                          /**< Base mask for RfcStop */
#define  RFC_STOP(x)                                        (((x)&0x1u)<<2)               /**< Set RfcStop in register */
#define  GET_RFC_STOP(reg)                                  (((reg)>>2)&0x1u)             /**< Get RfcStop from register */
#define  RFC_START_HW_EN_SHIFT                              8                             /**< Shift for RfcStartHwEn */
#define  RFC_START_HW_EN_MASK                               0x00000100u                   /**< Mask for RfcStartHwEn */
#define  RFC_START_HW_EN_BMASK                              0x1u                          /**< Base mask for RfcStartHwEn */
#define  RFC_START_HW_EN(x)                                 (((x)&0x1u)<<8)               /**< Set RfcStartHwEn in register */
#define  GET_RFC_START_HW_EN(reg)                           (((reg)>>8)&0x1u)             /**< Get RfcStartHwEn from register */
#define  RFC_START_HW_TXNRX_SHIFT                           9                             /**< Shift for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX_MASK                            0x00000200u                   /**< Mask for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX_BMASK                           0x1u                          /**< Base mask for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX(x)                              (((x)&0x1u)<<9)               /**< Set RfcStartHwTxNrx in register */
#define  GET_RFC_START_HW_TXNRX(reg)                        (((reg)>>9)&0x1u)             /**< Get RfcStartHwTxNrx from register */
#define  RFC_EN_SHIFT                                       16                            /**< Shift for RfcEn */
#define  RFC_EN_MASK                                        0x00010000u                   /**< Mask for RfcEn */
#define  RFC_EN_BMASK                                       0x1u                          /**< Base mask for RfcEn */
#define  RFC_EN(x)                                          (((x)&0x1u)<<16)              /**< Set RfcEn in register */
#define  GET_RFC_EN(reg)                                    (((reg)>>16)&0x1u)            /**< Get RfcEn from register */

// RegRfcCtrl.regs.RfcCtrlSw
#define  RFC_CTRL_SW_GSHIFT                                 0                             /**< Shift for group RfcCtrlSw */
#define  RFC_CTRL_SW_GSIZE                                  8                             /**< Size of group RfcCtrlSw */
#define  RFC_CTRL_SW_GMASK                                  0x000000FFu                   /**< Mask for group RfcCtrlSw */

#define  RFC_START_TX_RSHIFT                                0                             /**< Shift for RfcStartTx */
#define  RFC_START_TX_RMASK                                 0x01u                         /**< Mask for RfcStartTx */
#define  RFC_START_TX_RBMASK                                0x1u                          /**< Base mask for RfcStartTx */
#define  RFC_START_TX_R(x)                                  (((x)&0x1u)<<0)               /**< Set RfcStartTx in register */
#define  GET_RFC_START_TX_R(reg)                            (((reg)>>0)&0x1u)             /**< Get RfcStartTx from register */
#define  RFC_START_RX_RSHIFT                                1                             /**< Shift for RfcStartRx */
#define  RFC_START_RX_RMASK                                 0x02u                         /**< Mask for RfcStartRx */
#define  RFC_START_RX_RBMASK                                0x1u                          /**< Base mask for RfcStartRx */
#define  RFC_START_RX_R(x)                                  (((x)&0x1u)<<1)               /**< Set RfcStartRx in register */
#define  GET_RFC_START_RX_R(reg)                            (((reg)>>1)&0x1u)             /**< Get RfcStartRx from register */
#define  RFC_STOP_RSHIFT                                    2                             /**< Shift for RfcStop */
#define  RFC_STOP_RMASK                                     0x04u                         /**< Mask for RfcStop */
#define  RFC_STOP_RBMASK                                    0x1u                          /**< Base mask for RfcStop */
#define  RFC_STOP_R(x)                                      (((x)&0x1u)<<2)               /**< Set RfcStop in register */
#define  GET_RFC_STOP_R(reg)                                (((reg)>>2)&0x1u)             /**< Get RfcStop from register */

// RegRfcCtrl.regs.RfcCtrlHw
#define  RFC_CTRL_HW_GSHIFT                                 8                             /**< Shift for group RfcCtrlHw */
#define  RFC_CTRL_HW_GSIZE                                  8                             /**< Size of group RfcCtrlHw */
#define  RFC_CTRL_HW_GMASK                                  0x0000FF00u                   /**< Mask for group RfcCtrlHw */

#define  RFC_START_HW_EN_RSHIFT                             0                             /**< Shift for RfcStartHwEn */
#define  RFC_START_HW_EN_RMASK                              0x01u                         /**< Mask for RfcStartHwEn */
#define  RFC_START_HW_EN_RBMASK                             0x1u                          /**< Base mask for RfcStartHwEn */
#define  RFC_START_HW_EN_R(x)                               (((x)&0x1u)<<0)               /**< Set RfcStartHwEn in register */
#define  GET_RFC_START_HW_EN_R(reg)                         (((reg)>>0)&0x1u)             /**< Get RfcStartHwEn from register */
#define  RFC_START_HW_TXNRX_RSHIFT                          1                             /**< Shift for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX_RMASK                           0x02u                         /**< Mask for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX_RBMASK                          0x1u                          /**< Base mask for RfcStartHwTxNrx */
#define  RFC_START_HW_TXNRX_R(x)                            (((x)&0x1u)<<1)               /**< Set RfcStartHwTxNrx in register */
#define  GET_RFC_START_HW_TXNRX_R(reg)                      (((reg)>>1)&0x1u)             /**< Get RfcStartHwTxNrx from register */

// RegRfcCtrl.regs.RfcEn
#define  RFC_EN_GSHIFT                                      16                            /**< Shift for group RfcEn */
#define  RFC_EN_GSIZE                                       8                             /**< Size of group RfcEn */
#define  RFC_EN_GMASK                                       0x00FF0000u                   /**< Mask for group RfcEn */

#define  RFC_EN_RSHIFT                                      0                             /**< Shift for RfcEn */
#define  RFC_EN_RMASK                                       0x01u                         /**< Mask for RfcEn */
#define  RFC_EN_RBMASK                                      0x1u                          /**< Base mask for RfcEn */
#define  RFC_EN_R(x)                                        (((x)&0x1u)<<0)               /**< Set RfcEn in register */
#define  GET_RFC_EN_R(reg)                                  (((reg)>>0)&0x1u)             /**< Get RfcEn from register */
/** @} */


/**
 * @name RegRfcCfg
 * @{
 */
// RegRfcCfg.r32
#define  REG_RFC_CFG_RESET_VALUE                            0x00000000u                   /**< Reset value of RegRfcCfg */
#define  REG_RFC_CFG_MASK                                   0x00030103u                   /**< Mask for RegRfcCfg */

#define  RFC_STOP_PP_TX_UNDERFLOW_SHIFT                     0                             /**< Shift for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW_MASK                      0x00000001u                   /**< Mask for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW_BMASK                     0x1u                          /**< Base mask for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW(x)                        (((x)&0x1u)<<0)               /**< Set RfcStopPpTxUnderflow in register */
#define  GET_RFC_STOP_PP_TX_UNDERFLOW(reg)                  (((reg)>>0)&0x1u)             /**< Get RfcStopPpTxUnderflow from register */
#define  RFC_STOP_PP_RX_OVERFLOW_SHIFT                      1                             /**< Shift for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW_MASK                       0x00000002u                   /**< Mask for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW_BMASK                      0x1u                          /**< Base mask for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW(x)                         (((x)&0x1u)<<1)               /**< Set RfcStopPpRxOverflow in register */
#define  GET_RFC_STOP_PP_RX_OVERFLOW(reg)                   (((reg)>>1)&0x1u)             /**< Get RfcStopPpRxOverflow from register */
#define  RFC_RX_TIMEOUT_EN_SHIFT                            8                             /**< Shift for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_MASK                             0x00000100u                   /**< Mask for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_BMASK                            0x1u                          /**< Base mask for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN(x)                               (((x)&0x1u)<<8)               /**< Set RfcRxTimeoutEn in register */
#define  GET_RFC_RX_TIMEOUT_EN(reg)                         (((reg)>>8)&0x1u)             /**< Get RfcRxTimeoutEn from register */
#define  RFC_SPI_SPEED_RD_SHIFT                             16                            /**< Shift for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD_MASK                              0x00010000u                   /**< Mask for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD_BMASK                             0x1u                          /**< Base mask for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD(x)                                (((x)&0x1u)<<16)              /**< Set RfcSpiSpeedRd in register */
#define  GET_RFC_SPI_SPEED_RD(reg)                          (((reg)>>16)&0x1u)            /**< Get RfcSpiSpeedRd from register */
#define  RFC_SPI_SPEED_WR_SHIFT                             17                            /**< Shift for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR_MASK                              0x00020000u                   /**< Mask for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR_BMASK                             0x1u                          /**< Base mask for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR(x)                                (((x)&0x1u)<<17)              /**< Set RfcSpiSpeedWr in register */
#define  GET_RFC_SPI_SPEED_WR(reg)                          (((reg)>>17)&0x1u)            /**< Get RfcSpiSpeedWr from register */

// RegRfcCfg.regs.RfcStopPp
#define  RFC_STOP_PP_GSHIFT                                 0                             /**< Shift for group RfcStopPp */
#define  RFC_STOP_PP_GSIZE                                  8                             /**< Size of group RfcStopPp */
#define  RFC_STOP_PP_GMASK                                  0x000000FFu                   /**< Mask for group RfcStopPp */

#define  RFC_STOP_PP_TX_UNDERFLOW_RSHIFT                    0                             /**< Shift for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW_RMASK                     0x01u                         /**< Mask for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW_RBMASK                    0x1u                          /**< Base mask for RfcStopPpTxUnderflow */
#define  RFC_STOP_PP_TX_UNDERFLOW_R(x)                      (((x)&0x1u)<<0)               /**< Set RfcStopPpTxUnderflow in register */
#define  GET_RFC_STOP_PP_TX_UNDERFLOW_R(reg)                (((reg)>>0)&0x1u)             /**< Get RfcStopPpTxUnderflow from register */
#define  RFC_STOP_PP_RX_OVERFLOW_RSHIFT                     1                             /**< Shift for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW_RMASK                      0x02u                         /**< Mask for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW_RBMASK                     0x1u                          /**< Base mask for RfcStopPpRxOverflow */
#define  RFC_STOP_PP_RX_OVERFLOW_R(x)                       (((x)&0x1u)<<1)               /**< Set RfcStopPpRxOverflow in register */
#define  GET_RFC_STOP_PP_RX_OVERFLOW_R(reg)                 (((reg)>>1)&0x1u)             /**< Get RfcStopPpRxOverflow from register */

// RegRfcCfg.regs.RfcRxTimeoutEn
#define  RFC_RX_TIMEOUT_EN_GSHIFT                           8                             /**< Shift for group RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_GSIZE                            8                             /**< Size of group RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_GMASK                            0x0000FF00u                   /**< Mask for group RfcRxTimeoutEn */

#define  RFC_RX_TIMEOUT_EN_RSHIFT                           0                             /**< Shift for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_RMASK                            0x01u                         /**< Mask for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_RBMASK                           0x1u                          /**< Base mask for RfcRxTimeoutEn */
#define  RFC_RX_TIMEOUT_EN_R(x)                             (((x)&0x1u)<<0)               /**< Set RfcRxTimeoutEn in register */
#define  GET_RFC_RX_TIMEOUT_EN_R(reg)                       (((reg)>>0)&0x1u)             /**< Get RfcRxTimeoutEn from register */

// RegRfcCfg.regs.RfcSpiSpeed
#define  RFC_SPI_SPEED_GSHIFT                               16                            /**< Shift for group RfcSpiSpeed */
#define  RFC_SPI_SPEED_GSIZE                                8                             /**< Size of group RfcSpiSpeed */
#define  RFC_SPI_SPEED_GMASK                                0x00FF0000u                   /**< Mask for group RfcSpiSpeed */

#define  RFC_SPI_SPEED_RD_RSHIFT                            0                             /**< Shift for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD_RMASK                             0x01u                         /**< Mask for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD_RBMASK                            0x1u                          /**< Base mask for RfcSpiSpeedRd */
#define  RFC_SPI_SPEED_RD_R(x)                              (((x)&0x1u)<<0)               /**< Set RfcSpiSpeedRd in register */
#define  GET_RFC_SPI_SPEED_RD_R(reg)                        (((reg)>>0)&0x1u)             /**< Get RfcSpiSpeedRd from register */
#define  RFC_SPI_SPEED_WR_RSHIFT                            1                             /**< Shift for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR_RMASK                             0x02u                         /**< Mask for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR_RBMASK                            0x1u                          /**< Base mask for RfcSpiSpeedWr */
#define  RFC_SPI_SPEED_WR_R(x)                              (((x)&0x1u)<<1)               /**< Set RfcSpiSpeedWr in register */
#define  GET_RFC_SPI_SPEED_WR_R(reg)                        (((reg)>>1)&0x1u)             /**< Get RfcSpiSpeedWr from register */
/** @} */


/**
 * @name RegRfcStatus
 * @{
 */
// RegRfcStatus.r32
#define  REG_RFC_STATUS_RESET_VALUE                         0x00000000u                   /**< Reset value of RegRfcStatus */
#define  REG_RFC_STATUS_MASK                                0x0000007Fu                   /**< Mask for RegRfcStatus */

#define  RFC_STS_TX_SHIFT                                   0                             /**< Shift for RfcStsTx */
#define  RFC_STS_TX_MASK                                    0x00000001u                   /**< Mask for RfcStsTx */
#define  RFC_STS_TX_BMASK                                   0x1u                          /**< Base mask for RfcStsTx */
#define  RFC_STS_TX(x)                                      (((x)&0x1u)<<0)               /**< Set RfcStsTx in register */
#define  GET_RFC_STS_TX(reg)                                (((reg)>>0)&0x1u)             /**< Get RfcStsTx from register */
#define  RFC_STS_RX_SHIFT                                   1                             /**< Shift for RfcStsRx */
#define  RFC_STS_RX_MASK                                    0x00000002u                   /**< Mask for RfcStsRx */
#define  RFC_STS_RX_BMASK                                   0x1u                          /**< Base mask for RfcStsRx */
#define  RFC_STS_RX(x)                                      (((x)&0x1u)<<1)               /**< Set RfcStsRx in register */
#define  GET_RFC_STS_RX(reg)                                (((reg)>>1)&0x1u)             /**< Get RfcStsRx from register */
#define  RFC_STS_TX_MAC_SHIFT                               2                             /**< Shift for RfcStsTxMac */
#define  RFC_STS_TX_MAC_MASK                                0x00000004u                   /**< Mask for RfcStsTxMac */
#define  RFC_STS_TX_MAC_BMASK                               0x1u                          /**< Base mask for RfcStsTxMac */
#define  RFC_STS_TX_MAC(x)                                  (((x)&0x1u)<<2)               /**< Set RfcStsTxMac in register */
#define  GET_RFC_STS_TX_MAC(reg)                            (((reg)>>2)&0x1u)             /**< Get RfcStsTxMac from register */
#define  RFC_STS_RX_MAC_SHIFT                               3                             /**< Shift for RfcStsRxMac */
#define  RFC_STS_RX_MAC_MASK                                0x00000008u                   /**< Mask for RfcStsRxMac */
#define  RFC_STS_RX_MAC_BMASK                               0x1u                          /**< Base mask for RfcStsRxMac */
#define  RFC_STS_RX_MAC(x)                                  (((x)&0x1u)<<3)               /**< Set RfcStsRxMac in register */
#define  GET_RFC_STS_RX_MAC(reg)                            (((reg)>>3)&0x1u)             /**< Get RfcStsRxMac from register */
#define  RFC_STS_PP_TX_SHIFT                                4                             /**< Shift for RfcStsPpTx */
#define  RFC_STS_PP_TX_MASK                                 0x00000010u                   /**< Mask for RfcStsPpTx */
#define  RFC_STS_PP_TX_BMASK                                0x1u                          /**< Base mask for RfcStsPpTx */
#define  RFC_STS_PP_TX(x)                                   (((x)&0x1u)<<4)               /**< Set RfcStsPpTx in register */
#define  GET_RFC_STS_PP_TX(reg)                             (((reg)>>4)&0x1u)             /**< Get RfcStsPpTx from register */
#define  RFC_STS_PP_RX_SHIFT                                5                             /**< Shift for RfcStsPpRx */
#define  RFC_STS_PP_RX_MASK                                 0x00000020u                   /**< Mask for RfcStsPpRx */
#define  RFC_STS_PP_RX_BMASK                                0x1u                          /**< Base mask for RfcStsPpRx */
#define  RFC_STS_PP_RX(x)                                   (((x)&0x1u)<<5)               /**< Set RfcStsPpRx in register */
#define  GET_RFC_STS_PP_RX(reg)                             (((reg)>>5)&0x1u)             /**< Get RfcStsPpRx from register */
#define  RFC_STS_PP_RX_SYNC_SHIFT                           6                             /**< Shift for RfcStsPpRxSync */
#define  RFC_STS_PP_RX_SYNC_MASK                            0x00000040u                   /**< Mask for RfcStsPpRxSync */
#define  RFC_STS_PP_RX_SYNC_BMASK                           0x1u                          /**< Base mask for RfcStsPpRxSync */
#define  RFC_STS_PP_RX_SYNC(x)                              (((x)&0x1u)<<6)               /**< Set RfcStsPpRxSync in register */
#define  GET_RFC_STS_PP_RX_SYNC(reg)                        (((reg)>>6)&0x1u)             /**< Get RfcStsPpRxSync from register */
/** @} */


/**
 * @name RegRfcMacCfg
 * @{
 */
// RegRfcMacCfg.r32
#define  REG_RFC_MAC_CFG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfcMacCfg */
#define  REG_RFC_MAC_CFG_MASK                               0x00000303u                   /**< Mask for RegRfcMacCfg */

#define  RFC_RX_MAC_EN_SHIFT                                0                             /**< Shift for RfcRxMacEn */
#define  RFC_RX_MAC_EN_MASK                                 0x00000001u                   /**< Mask for RfcRxMacEn */
#define  RFC_RX_MAC_EN_BMASK                                0x1u                          /**< Base mask for RfcRxMacEn */
#define  RFC_RX_MAC_EN(x)                                   (((x)&0x1u)<<0)               /**< Set RfcRxMacEn in register */
#define  GET_RFC_RX_MAC_EN(reg)                             (((reg)>>0)&0x1u)             /**< Get RfcRxMacEn from register */
#define  RFC_TX_MAC_EN_SHIFT                                1                             /**< Shift for RfcTxMacEn */
#define  RFC_TX_MAC_EN_MASK                                 0x00000002u                   /**< Mask for RfcTxMacEn */
#define  RFC_TX_MAC_EN_BMASK                                0x1u                          /**< Base mask for RfcTxMacEn */
#define  RFC_TX_MAC_EN(x)                                   (((x)&0x1u)<<1)               /**< Set RfcTxMacEn in register */
#define  GET_RFC_TX_MAC_EN(reg)                             (((reg)>>1)&0x1u)             /**< Get RfcTxMacEn from register */
#define  RFC_RX_MAC_TX_NRX_SHIFT                            8                             /**< Shift for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX_MASK                             0x00000100u                   /**< Mask for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX_BMASK                            0x1u                          /**< Base mask for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX(x)                               (((x)&0x1u)<<8)               /**< Set RfcRxMacTxNrx in register */
#define  GET_RFC_RX_MAC_TX_NRX(reg)                         (((reg)>>8)&0x1u)             /**< Get RfcRxMacTxNrx from register */
#define  RFC_TX_MAC_RX_NTX_SHIFT                            9                             /**< Shift for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX_MASK                             0x00000200u                   /**< Mask for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX_BMASK                            0x1u                          /**< Base mask for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX(x)                               (((x)&0x1u)<<9)               /**< Set RfcTxMacRxNtx in register */
#define  GET_RFC_TX_MAC_RX_NTX(reg)                         (((reg)>>9)&0x1u)             /**< Get RfcTxMacRxNtx from register */

// RegRfcMacCfg.regs.RfcMacEn
#define  RFC_MAC_EN_GSHIFT                                  0                             /**< Shift for group RfcMacEn */
#define  RFC_MAC_EN_GSIZE                                   8                             /**< Size of group RfcMacEn */
#define  RFC_MAC_EN_GMASK                                   0x000000FFu                   /**< Mask for group RfcMacEn */

#define  RFC_RX_MAC_EN_RSHIFT                               0                             /**< Shift for RfcRxMacEn */
#define  RFC_RX_MAC_EN_RMASK                                0x01u                         /**< Mask for RfcRxMacEn */
#define  RFC_RX_MAC_EN_RBMASK                               0x1u                          /**< Base mask for RfcRxMacEn */
#define  RFC_RX_MAC_EN_R(x)                                 (((x)&0x1u)<<0)               /**< Set RfcRxMacEn in register */
#define  GET_RFC_RX_MAC_EN_R(reg)                           (((reg)>>0)&0x1u)             /**< Get RfcRxMacEn from register */
#define  RFC_TX_MAC_EN_RSHIFT                               1                             /**< Shift for RfcTxMacEn */
#define  RFC_TX_MAC_EN_RMASK                                0x02u                         /**< Mask for RfcTxMacEn */
#define  RFC_TX_MAC_EN_RBMASK                               0x1u                          /**< Base mask for RfcTxMacEn */
#define  RFC_TX_MAC_EN_R(x)                                 (((x)&0x1u)<<1)               /**< Set RfcTxMacEn in register */
#define  GET_RFC_TX_MAC_EN_R(reg)                           (((reg)>>1)&0x1u)             /**< Get RfcTxMacEn from register */

// RegRfcMacCfg.regs.RfcMacCfg
#define  RFC_MAC_CFG_GSHIFT                                 8                             /**< Shift for group RfcMacCfg */
#define  RFC_MAC_CFG_GSIZE                                  8                             /**< Size of group RfcMacCfg */
#define  RFC_MAC_CFG_GMASK                                  0x0000FF00u                   /**< Mask for group RfcMacCfg */

#define  RFC_RX_MAC_TX_NRX_RSHIFT                           0                             /**< Shift for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX_RMASK                            0x01u                         /**< Mask for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX_RBMASK                           0x1u                          /**< Base mask for RfcRxMacTxNrx */
#define  RFC_RX_MAC_TX_NRX_R(x)                             (((x)&0x1u)<<0)               /**< Set RfcRxMacTxNrx in register */
#define  GET_RFC_RX_MAC_TX_NRX_R(reg)                       (((reg)>>0)&0x1u)             /**< Get RfcRxMacTxNrx from register */
#define  RFC_TX_MAC_RX_NTX_RSHIFT                           1                             /**< Shift for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX_RMASK                            0x02u                         /**< Mask for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX_RBMASK                           0x1u                          /**< Base mask for RfcTxMacRxNtx */
#define  RFC_TX_MAC_RX_NTX_R(x)                             (((x)&0x1u)<<1)               /**< Set RfcTxMacRxNtx in register */
#define  GET_RFC_TX_MAC_RX_NTX_R(reg)                       (((reg)>>1)&0x1u)             /**< Get RfcTxMacRxNtx from register */
/** @} */


/**
 * @name RegRfcMacTime
 * @{
 */
// RegRfcMacTime.r32
#define  REG_RFC_MAC_TIME_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfcMacTime */
#define  REG_RFC_MAC_TIME_MASK                              0x0FFF0FFFu                   /**< Mask for RegRfcMacTime */

#define  RFC_RX_MAC_TIME_SHIFT                              0                             /**< Shift for RfcRxMacTime */
#define  RFC_RX_MAC_TIME_MASK                               0x00000FFFu                   /**< Mask for RfcRxMacTime */
#define  RFC_RX_MAC_TIME_BMASK                              0xFFFu                        /**< Base mask for RfcRxMacTime */
#define  RFC_RX_MAC_TIME(x)                                 (((x)&0xFFFu)<<0)             /**< Set RfcRxMacTime in register */
#define  GET_RFC_RX_MAC_TIME(reg)                           (((reg)>>0)&0xFFFu)           /**< Get RfcRxMacTime from register */
#define  RFC_TX_MAC_TIME_SHIFT                              16                            /**< Shift for RfcTxMacTime */
#define  RFC_TX_MAC_TIME_MASK                               0x0FFF0000u                   /**< Mask for RfcTxMacTime */
#define  RFC_TX_MAC_TIME_BMASK                              0xFFFu                        /**< Base mask for RfcTxMacTime */
#define  RFC_TX_MAC_TIME(x)                                 (((x)&0xFFFu)<<16)            /**< Set RfcTxMacTime in register */
#define  GET_RFC_TX_MAC_TIME(reg)                           (((reg)>>16)&0xFFFu)          /**< Get RfcTxMacTime from register */

// RegRfcMacTime.regs.RfcRxMacTime
#define  RFC_RX_MAC_TIME_GSHIFT                             0                             /**< Shift for group RfcRxMacTime */
#define  RFC_RX_MAC_TIME_GSIZE                              16                            /**< Size of group RfcRxMacTime */
#define  RFC_RX_MAC_TIME_GMASK                              0x0000FFFFu                   /**< Mask for group RfcRxMacTime */

#define  RFC_RX_MAC_TIME_RSHIFT                             0                             /**< Shift for RfcRxMacTime */
#define  RFC_RX_MAC_TIME_RMASK                              0x00000FFFu                   /**< Mask for RfcRxMacTime */
#define  RFC_RX_MAC_TIME_RBMASK                             0xFFFu                        /**< Base mask for RfcRxMacTime */
#define  RFC_RX_MAC_TIME_R(x)                               (((x)&0xFFFu)<<0)             /**< Set RfcRxMacTime in register */
#define  GET_RFC_RX_MAC_TIME_R(reg)                         (((reg)>>0)&0xFFFu)           /**< Get RfcRxMacTime from register */

// RegRfcMacTime.regs.RfcTxMacTime
#define  RFC_TX_MAC_TIME_GSHIFT                             16                            /**< Shift for group RfcTxMacTime */
#define  RFC_TX_MAC_TIME_GSIZE                              16                            /**< Size of group RfcTxMacTime */
#define  RFC_TX_MAC_TIME_GMASK                              0xFFFF0000u                   /**< Mask for group RfcTxMacTime */

#define  RFC_TX_MAC_TIME_RSHIFT                             0                             /**< Shift for RfcTxMacTime */
#define  RFC_TX_MAC_TIME_RMASK                              0x00000FFFu                   /**< Mask for RfcTxMacTime */
#define  RFC_TX_MAC_TIME_RBMASK                             0xFFFu                        /**< Base mask for RfcTxMacTime */
#define  RFC_TX_MAC_TIME_R(x)                               (((x)&0xFFFu)<<0)             /**< Set RfcTxMacTime in register */
#define  GET_RFC_TX_MAC_TIME_R(reg)                         (((reg)>>0)&0xFFFu)           /**< Get RfcTxMacTime from register */
/** @} */


/**
 * @name RegRfcStartTime
 * @{
 */
// RegRfcStartTime.r32
#define  REG_RFC_START_TIME_RESET_VALUE                     0x00000000u                   /**< Reset value of RegRfcStartTime */
#define  REG_RFC_START_TIME_MASK                            0x0FFF0FFFu                   /**< Mask for RegRfcStartTime */

#define  RFC_TX_START_TIME_SHIFT                            0                             /**< Shift for RfcTxStartTime */
#define  RFC_TX_START_TIME_MASK                             0x00000FFFu                   /**< Mask for RfcTxStartTime */
#define  RFC_TX_START_TIME_BMASK                            0xFFFu                        /**< Base mask for RfcTxStartTime */
#define  RFC_TX_START_TIME(x)                               (((x)&0xFFFu)<<0)             /**< Set RfcTxStartTime in register */
#define  GET_RFC_TX_START_TIME(reg)                         (((reg)>>0)&0xFFFu)           /**< Get RfcTxStartTime from register */
#define  RFC_RX_START_TIME_SHIFT                            16                            /**< Shift for RfcRxStartTime */
#define  RFC_RX_START_TIME_MASK                             0x0FFF0000u                   /**< Mask for RfcRxStartTime */
#define  RFC_RX_START_TIME_BMASK                            0xFFFu                        /**< Base mask for RfcRxStartTime */
#define  RFC_RX_START_TIME(x)                               (((x)&0xFFFu)<<16)            /**< Set RfcRxStartTime in register */
#define  GET_RFC_RX_START_TIME(reg)                         (((reg)>>16)&0xFFFu)          /**< Get RfcRxStartTime from register */

// RegRfcStartTime.regs.RfcTxStartTime
#define  RFC_TX_START_TIME_GSHIFT                           0                             /**< Shift for group RfcTxStartTime */
#define  RFC_TX_START_TIME_GSIZE                            16                            /**< Size of group RfcTxStartTime */
#define  RFC_TX_START_TIME_GMASK                            0x0000FFFFu                   /**< Mask for group RfcTxStartTime */

#define  RFC_TX_START_TIME_RSHIFT                           0                             /**< Shift for RfcTxStartTime */
#define  RFC_TX_START_TIME_RMASK                            0x00000FFFu                   /**< Mask for RfcTxStartTime */
#define  RFC_TX_START_TIME_RBMASK                           0xFFFu                        /**< Base mask for RfcTxStartTime */
#define  RFC_TX_START_TIME_R(x)                             (((x)&0xFFFu)<<0)             /**< Set RfcTxStartTime in register */
#define  GET_RFC_TX_START_TIME_R(reg)                       (((reg)>>0)&0xFFFu)           /**< Get RfcTxStartTime from register */

// RegRfcStartTime.regs.RfcRxStartTime
#define  RFC_RX_START_TIME_GSHIFT                           16                            /**< Shift for group RfcRxStartTime */
#define  RFC_RX_START_TIME_GSIZE                            16                            /**< Size of group RfcRxStartTime */
#define  RFC_RX_START_TIME_GMASK                            0xFFFF0000u                   /**< Mask for group RfcRxStartTime */

#define  RFC_RX_START_TIME_RSHIFT                           0                             /**< Shift for RfcRxStartTime */
#define  RFC_RX_START_TIME_RMASK                            0x00000FFFu                   /**< Mask for RfcRxStartTime */
#define  RFC_RX_START_TIME_RBMASK                           0xFFFu                        /**< Base mask for RfcRxStartTime */
#define  RFC_RX_START_TIME_R(x)                             (((x)&0xFFFu)<<0)             /**< Set RfcRxStartTime in register */
#define  GET_RFC_RX_START_TIME_R(reg)                       (((reg)>>0)&0xFFFu)           /**< Get RfcRxStartTime from register */
/** @} */


/**
 * @name RegRfcStopTime
 * @{
 */
// RegRfcStopTime.r32
#define  REG_RFC_STOP_TIME_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfcStopTime */
#define  REG_RFC_STOP_TIME_MASK                             0x000000FFu                   /**< Mask for RegRfcStopTime */

#define  RFC_STOP_TIME_SHIFT                                0                             /**< Shift for RfcStopTime */
#define  RFC_STOP_TIME_MASK                                 0x000000FFu                   /**< Mask for RfcStopTime */
#define  RFC_STOP_TIME_BMASK                                0xFFu                         /**< Base mask for RfcStopTime */
#define  RFC_STOP_TIME(x)                                   (((x)&0xFFu)<<0)              /**< Set RfcStopTime in register */
#define  GET_RFC_STOP_TIME(reg)                             (((reg)>>0)&0xFFu)            /**< Get RfcStopTime from register */

// RegRfcStopTime.regs.RfcStopTime
#define  RFC_STOP_TIME_GSHIFT                               0                             /**< Shift for group RfcStopTime */
#define  RFC_STOP_TIME_GSIZE                                8                             /**< Size of group RfcStopTime */
#define  RFC_STOP_TIME_GMASK                                0x000000FFu                   /**< Mask for group RfcStopTime */

#define  RFC_STOP_TIME_RSHIFT                               0                             /**< Shift for RfcStopTime */
#define  RFC_STOP_TIME_RMASK                                0x000000FFu                   /**< Mask for RfcStopTime */
#define  RFC_STOP_TIME_RBMASK                               0xFFu                         /**< Base mask for RfcStopTime */
#define  RFC_STOP_TIME_R(x)                                 (((x)&0xFFu)<<0)              /**< Set RfcStopTime in register */
#define  GET_RFC_STOP_TIME_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get RfcStopTime from register */
/** @} */


/**
 * @name RegRfcPaLnaTime
 * @{
 */
// RegRfcPaLnaTime.r32
#define  REG_RFC_PA_LNA_TIME_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfcPaLnaTime */
#define  REG_RFC_PA_LNA_TIME_MASK                           0x00003F3Fu                   /**< Mask for RegRfcPaLnaTime */

#define  RFC_EXT_PA_START_TIME_SHIFT                        0                             /**< Shift for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_MASK                         0x0000003Fu                   /**< Mask for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_BMASK                        0x3Fu                         /**< Base mask for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME(x)                           (((x)&0x3Fu)<<0)              /**< Set RfcExtPaStartTime in register */
#define  GET_RFC_EXT_PA_START_TIME(reg)                     (((reg)>>0)&0x3Fu)            /**< Get RfcExtPaStartTime from register */
#define  RFC_EXT_LNA_START_TIME_SHIFT                       8                             /**< Shift for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_MASK                        0x00003F00u                   /**< Mask for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_BMASK                       0x3Fu                         /**< Base mask for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME(x)                          (((x)&0x3Fu)<<8)              /**< Set RfcExtLnaStartTime in register */
#define  GET_RFC_EXT_LNA_START_TIME(reg)                    (((reg)>>8)&0x3Fu)            /**< Get RfcExtLnaStartTime from register */

// RegRfcPaLnaTime.regs.RfcExtPaStartTime
#define  RFC_EXT_PA_START_TIME_GSHIFT                       0                             /**< Shift for group RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_GSIZE                        8                             /**< Size of group RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_GMASK                        0x000000FFu                   /**< Mask for group RfcExtPaStartTime */

#define  RFC_EXT_PA_START_TIME_RSHIFT                       0                             /**< Shift for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_RMASK                        0x0000003Fu                   /**< Mask for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_RBMASK                       0x3Fu                         /**< Base mask for RfcExtPaStartTime */
#define  RFC_EXT_PA_START_TIME_R(x)                         (((x)&0x3Fu)<<0)              /**< Set RfcExtPaStartTime in register */
#define  GET_RFC_EXT_PA_START_TIME_R(reg)                   (((reg)>>0)&0x3Fu)            /**< Get RfcExtPaStartTime from register */

// RegRfcPaLnaTime.regs.RfcExtLnaStartTime
#define  RFC_EXT_LNA_START_TIME_GSHIFT                      8                             /**< Shift for group RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_GSIZE                       8                             /**< Size of group RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_GMASK                       0x0000FF00u                   /**< Mask for group RfcExtLnaStartTime */

#define  RFC_EXT_LNA_START_TIME_RSHIFT                      0                             /**< Shift for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_RMASK                       0x0000003Fu                   /**< Mask for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_RBMASK                      0x3Fu                         /**< Base mask for RfcExtLnaStartTime */
#define  RFC_EXT_LNA_START_TIME_R(x)                        (((x)&0x3Fu)<<0)              /**< Set RfcExtLnaStartTime in register */
#define  GET_RFC_EXT_LNA_START_TIME_R(reg)                  (((reg)>>0)&0x3Fu)            /**< Get RfcExtLnaStartTime from register */
/** @} */


/**
 * @name RegRfcRxTimeout
 * @{
 */
// RegRfcRxTimeout.r32
#define  REG_RFC_RX_TIMEOUT_RESET_VALUE                     0x00000000u                   /**< Reset value of RegRfcRxTimeout */
#define  REG_RFC_RX_TIMEOUT_MASK                            0x00FFFFFFu                   /**< Mask for RegRfcRxTimeout */

#define  RFC_RX_TIMEOUT_SHIFT                               0                             /**< Shift for RfcRxTimeout */
#define  RFC_RX_TIMEOUT_MASK                                0x00FFFFFFu                   /**< Mask for RfcRxTimeout */
#define  RFC_RX_TIMEOUT_BMASK                               0xFFFFFFu                     /**< Base mask for RfcRxTimeout */
#define  RFC_RX_TIMEOUT(x)                                  (((x)&0xFFFFFFu)<<0)          /**< Set RfcRxTimeout in register */
#define  GET_RFC_RX_TIMEOUT(reg)                            (((reg)>>0)&0xFFFFFFu)        /**< Get RfcRxTimeout from register */
/** @} */


/**
 * @name RegRfcMirrBurstCfgTxrx
 * @{
 */
// RegRfcMirrBurstCfgTxrx.r32
#define  REG_RFC_MIRR_BURST_CFG_TXRX_RESET_VALUE            0x00000000u                   /**< Reset value of RegRfcMirrBurstCfgTxrx */
#define  REG_RFC_MIRR_BURST_CFG_TXRX_MASK                   0x00003F3Fu                   /**< Mask for RegRfcMirrBurstCfgTxrx */

#define  RFC_CHNL_NUM_SHIFT                                 0                             /**< Shift for RfcChnlNum */
#define  RFC_CHNL_NUM_MASK                                  0x0000003Fu                   /**< Mask for RfcChnlNum */
#define  RFC_CHNL_NUM_BMASK                                 0x3Fu                         /**< Base mask for RfcChnlNum */
#define  RFC_CHNL_NUM(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfcChnlNum in register */
#define  GET_RFC_CHNL_NUM(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfcChnlNum from register */
#define  RFC_RX_TIM_SEQ_SEL_SHIFT                           8                             /**< Shift for RfcRxTimSeqSel */
#define  RFC_RX_TIM_SEQ_SEL_MASK                            0x00000100u                   /**< Mask for RfcRxTimSeqSel */
#define  RFC_RX_TIM_SEQ_SEL_BMASK                           0x1u                          /**< Base mask for RfcRxTimSeqSel */
#define  RFC_RX_TIM_SEQ_SEL(x)                              (((x)&0x1u)<<8)               /**< Set RfcRxTimSeqSel in register */
#define  GET_RFC_RX_TIM_SEQ_SEL(reg)                        (((reg)>>8)&0x1u)             /**< Get RfcRxTimSeqSel from register */
#define  RFC_TX_TIM_SEQ_SEL_SHIFT                           9                             /**< Shift for RfcTxTimSeqSel */
#define  RFC_TX_TIM_SEQ_SEL_MASK                            0x00000200u                   /**< Mask for RfcTxTimSeqSel */
#define  RFC_TX_TIM_SEQ_SEL_BMASK                           0x1u                          /**< Base mask for RfcTxTimSeqSel */
#define  RFC_TX_TIM_SEQ_SEL(x)                              (((x)&0x1u)<<9)               /**< Set RfcTxTimSeqSel in register */
#define  GET_RFC_TX_TIM_SEQ_SEL(reg)                        (((reg)>>9)&0x1u)             /**< Get RfcTxTimSeqSel from register */
#define  RFC_FE_CTRIM_SHIFT                                 10                            /**< Shift for RfcFeCtrim */
#define  RFC_FE_CTRIM_MASK                                  0x00003C00u                   /**< Mask for RfcFeCtrim */
#define  RFC_FE_CTRIM_BMASK                                 0xFu                          /**< Base mask for RfcFeCtrim */
#define  RFC_FE_CTRIM(x)                                    (((x)&0xFu)<<10)              /**< Set RfcFeCtrim in register */
#define  GET_RFC_FE_CTRIM(reg)                              (((reg)>>10)&0xFu)            /**< Get RfcFeCtrim from register */
/** @} */


/**
 * @name RegRfcRssi
 * @{
 */
// RegRfcRssi.r32
#define  REG_RFC_RSSI_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRfcRssi */
#define  REG_RFC_RSSI_MASK                                  0x0000FFFFu                   /**< Mask for RegRfcRssi */

#define  RFC_RSSI_SHIFT                                     0                             /**< Shift for RfcRssi */
#define  RFC_RSSI_MASK                                      0x0000FFFFu                   /**< Mask for RfcRssi */
#define  RFC_RSSI_BMASK                                     0xFFFFu                       /**< Base mask for RfcRssi */
#define  RFC_RSSI(x)                                        (((x)&0xFFFFu)<<0)            /**< Set RfcRssi in register */
#define  GET_RFC_RSSI(reg)                                  (((reg)>>0)&0xFFFFu)          /**< Get RfcRssi from register */
/** @} */


/**
 * @name RegRfcRfCfg
 * @{
 */
// RegRfcRfCfg.r32
#define  REG_RFC_RF_CFG_RESET_VALUE                         0x00000000u                   /**< Reset value of RegRfcRfCfg */
#define  REG_RFC_RF_CFG_MASK                                0x00000007u                   /**< Mask for RegRfcRfCfg */

#define  RFC_RF_IQ_SEL_SHIFT                                0                             /**< Shift for RfcRfIqSel */
#define  RFC_RF_IQ_SEL_MASK                                 0x00000007u                   /**< Mask for RfcRfIqSel */
#define  RFC_RF_IQ_SEL_BMASK                                0x7u                          /**< Base mask for RfcRfIqSel */
#define  RFC_RF_IQ_SEL(x)                                   (((x)&0x7u)<<0)               /**< Set RfcRfIqSel in register */
#define  GET_RFC_RF_IQ_SEL(reg)                             (((reg)>>0)&0x7u)             /**< Get RfcRfIqSel from register */

// RegRfcRfCfg.regs.RfcRfIqSel
#define  RFC_RF_IQ_SEL_GSHIFT                               0                             /**< Shift for group RfcRfIqSel */
#define  RFC_RF_IQ_SEL_GSIZE                                8                             /**< Size of group RfcRfIqSel */
#define  RFC_RF_IQ_SEL_GMASK                                0x000000FFu                   /**< Mask for group RfcRfIqSel */

#define  RFC_RF_IQ_SEL_RSHIFT                               0                             /**< Shift for RfcRfIqSel */
#define  RFC_RF_IQ_SEL_RMASK                                0x07u                         /**< Mask for RfcRfIqSel */
#define  RFC_RF_IQ_SEL_RBMASK                               0x7u                          /**< Base mask for RfcRfIqSel */
#define  RFC_RF_IQ_SEL_R(x)                                 (((x)&0x7u)<<0)               /**< Set RfcRfIqSel in register */
#define  GET_RFC_RF_IQ_SEL_R(reg)                           (((reg)>>0)&0x7u)             /**< Get RfcRfIqSel from register */
/** @} */



/** @} End of group RfCtrl_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_RF_CTRL_H */
