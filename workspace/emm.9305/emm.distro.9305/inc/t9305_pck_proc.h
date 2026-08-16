////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_pck_proc.h
///
/// @project    T9305
///
/// @brief      Packet Processor register and bit field definitions
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

#ifndef _T9305_PCK_PROC_H
#define _T9305_PCK_PROC_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup PckProc_Registers Packet Processor Register Map - registers
 * @{
 ******************************************************************************/


/** Packet processor control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpEn;                                      /**< Packet processor block enable */
        uint8_t  PpCtrlMode;                                /**< Control Mode. 0=HW control (by HW signals), 1=SW control (by registers). */
        uint8_t  PpCtrlSw;                                  /**< SW control */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegPpCtrl_t;


/** Packet processor configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PpPhyMode;                                 /**< PHY mode */
        uint8_t  PpPhyTxOnExtraTim;                         /**< Time to wait between finishing data stream on TX_DATA and deasserting TX_ON, Range 0 ... 7.75us, granularity=0.25us */
        uint8_t  PpMode;                                    /**< Packet format mode : 0 = standard mode, 1 = custom mode #1, 2 = Zigbee mode */
    } regs;
} RegPpCfg_t;


/** Preamble configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpPreamPattern;                            /**< Preamble pattern */
        uint8_t  PpPreamLen;                                /**< Preamble length (# bytes) */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegPpPream_t;


/** Sync word 0 for RX/TX operation, bytes  0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord0Lo_t;


/** Sync word 0 for RX/TX operation, byte 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord0Hi_t;


/** Sync word 1 for RX/TX operation, bytes  0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord1Lo_t;


/** Sync word 1 for RX/TX operation, byte 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord1Hi_t;


/** Sync word 2 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord2Ex_t;


/** Sync word 3 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord3Ex_t;


/** Sync word 4 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord4Ex_t;


/** Sync word 5 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSyncWord5Ex_t;


/** Sync word configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpSyncWordLen;                             /**< Sync word length 1-5 octets */
        uint8_t  PpSyncWordTxSel;                           /**< Sync word selection for TX operation: 0 = RegPpSyncWord0, 1 = RegPpSyncWord1, 2 = Received RX sync word shall be used for subsequent TX operation, 3 = RFU */
        uint8_t  PpSyncWordRxEn;                            /**< Sync word 0 - 5 enable for RX operation. Multiple sync words can be enabled in parallel. */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegPpSyncWordCfg_t;


/** CRC polynomial */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpCrcPoly_t;


/** CRC initial value for sync word 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpCrcInit0_t;


/** CRC initial value for sync word 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpCrcInit1_t;


/** CRC configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpCrcCfg_t;


/** Whitening polynomial */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpWhitePoly_t;


/** Whitening initial value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpWhiteInit_t;


/** Whitening configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpWhiteCfg_t;


/** PDU length configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PpPduLen;                                  /**< PDU length in fixed packet mode */
        uint8_t  PpPduLenPos;                               /**< Length field position in the PDU */
        uint8_t  PpPduLenCorr;                              /**< Correction value for PDU length (signed value) */
    } regs;
} RegPpPduLen_t;


/** Packet handling */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpPckHndl_t;


/** Packet processor status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpSts_t;


/** Tx FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpTxFifo1B_t;


/** Tx FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpTxFifo2B_t;


/** Tx FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpTxFifo3B_t;


/** Tx FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpTxFifo4B_t;


/** Rx FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpRxFifo1B_t;


/** Rx FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpRxFifo2B_t;


/** Rx FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpRxFifo3B_t;


/** Rx FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpRxFifo4B_t;


/** Fifo Configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpTxFifoLimit;                             /**< Tx FIFO limit */
        uint8_t  PpRxFifoLimit;                             /**< Rx FIFO limit */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegPpFifoCfg_t;


/** Fifo Status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpTxFifoCount;                             /**< Number of bytes in Tx FIFO */
        uint8_t  PpRxFifoCount;                             /**< Number of bytes in Rx FIFO */
        uint8_t  PpTxFifoStatus;                            /**< Tx FIFO status */
        uint8_t  PpRxFifoStatus;                            /**< Rx FIFO status */
    } regs;
} RegPpFifoSts_t;


/** Fifo commands */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpFifoCmd_t;


/** AES encryption key (bit 31:0) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesKey0_t;


/** AES encryption key (bit 63:32) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesKey1_t;


/** AES encryption key (bit 95:64) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesKey2_t;


/** AES encryption key (bit 127:96) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesKey3_t;


/** AES encryption counter block (bit 31:0) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesCtrBlock0_t;


/** AES encryption counter block (bit 63:32) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesCtrBlock1_t;


/** AES encryption counter block (bit 95:64) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesCtrBlock2_t;


/** AES encryption counter block (bit 127:96) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesCtrBlock3_t;


/** AES configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpAesEn;                                   /**< AES enable */
        uint8_t  PpAesMode;                                 /**< Encryption mode. 0 : BLE mode, 1 : Custom mode., 2 : Zigbee mode no MIC, 3 : Zigbee mode MIC32, 4 : Zigbee mode MIC64, 5 : Zigbee mode MIC128 */
        uint8_t  PpAesPduStart;                             /**< Encryption applied only to PDU bytes starting at specified position till the end of PDU in custom mode. Range : 0 - 15 */
        uint8_t  PpAesCtrSize;                              /**< Size of counter value in custom mode. Range 1 - 16 bytes */
    } regs;
} RegPpAesCfg_t;


/** AES status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpAesSts_t;


/** BLE CTE configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PpBleCteCfg;                               /**< CTE in BLE packets configuration */
        uint8_t  PpBleCteCpBitPos;                          /**< CTE CP bit position in PDU (byte 0-31, bit 0-7) */
        uint8_t  PpBleCteCteInfoPos;                        /**< CTE Info field position in PDU (byte 0-63) */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegPpBleCteCfg_t;


/** BLE CTE RX timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PpBleCteRxTimSwitch;                       /**< Time referenced to end of CRC field to start antenna switching procedure during RX operation (signed value) */
        uint16_t PpBleCteRxTimSample;                       /**< Time referenced to end of CRC field to start IQ sampling (signed value) */
    } regs;
} RegPpBleCteRxTim_t;


/** BLE CTE TX Timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpBleCteTxTim_t;


/** BLE CTE Status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpBleCteSts_t;


/** Test modes */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPpRfTst_t;

/** @} end of group PckProc_Regs */



/***************************************************************************//**
 * @defgroup PckProc_RegMap Packet Processor Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegPpCtrl_t                                       RegPpCtrl;                    /**< Packet processor control */
    __IO  RegPpCfg_t                                        RegPpCfg;                     /**< Packet processor configuration */
    __IO  RegPpPream_t                                      RegPpPream;                   /**< Preamble configuration */
    __IO  RegPpSyncWord0Lo_t                                RegPpSyncWord0Lo;             /**< Sync word 0 for RX/TX operation, bytes  0-3 */
    __IO  RegPpSyncWord0Hi_t                                RegPpSyncWord0Hi;             /**< Sync word 0 for RX/TX operation, byte 4 */
    __IO  RegPpSyncWord1Lo_t                                RegPpSyncWord1Lo;             /**< Sync word 1 for RX/TX operation, bytes  0-3 */
    __IO  RegPpSyncWord1Hi_t                                RegPpSyncWord1Hi;             /**< Sync word 1 for RX/TX operation, byte 4 */
    __IO  RegPpSyncWord2Ex_t                                RegPpSyncWord2Ex;             /**< Sync word 2 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
    __IO  RegPpSyncWord3Ex_t                                RegPpSyncWord3Ex;             /**< Sync word 3 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
    __IO  RegPpSyncWord4Ex_t                                RegPpSyncWord4Ex;             /**< Sync word 4 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
    __IO  RegPpSyncWord5Ex_t                                RegPpSyncWord5Ex;             /**< Sync word 5 for RX operation (last byte). Base part is taken from RegPpSyncWord1Lo */
    __IO  RegPpSyncWordCfg_t                                RegPpSyncWordCfg;             /**< Sync word configuration */
    __IO  RegPpCrcPoly_t                                    RegPpCrcPoly;                 /**< CRC polynomial */
    __IO  RegPpCrcInit0_t                                   RegPpCrcInit0;                /**< CRC initial value for sync word 0 */
    __IO  RegPpCrcInit1_t                                   RegPpCrcInit1;                /**< CRC initial value for sync word 1 */
    __IO  RegPpCrcCfg_t                                     RegPpCrcCfg;                  /**< CRC configuration */
    __IO  RegPpWhitePoly_t                                  RegPpWhitePoly;               /**< Whitening polynomial */
    __IO  RegPpWhiteInit_t                                  RegPpWhiteInit;               /**< Whitening initial value */
    __IO  RegPpWhiteCfg_t                                   RegPpWhiteCfg;                /**< Whitening configuration */
    __IO  RegPpPduLen_t                                     RegPpPduLen;                  /**< PDU length configuration */
    __IO  RegPpPckHndl_t                                    RegPpPckHndl;                 /**< Packet handling */
    __I   RegPpSts_t                                        RegPpSts;                     /**< Packet processor status */
    __O   RegPpTxFifo1B_t                                   RegPpTxFifo1B;                /**< Tx FIFO - 1 byte access */
    __O   RegPpTxFifo2B_t                                   RegPpTxFifo2B;                /**< Tx FIFO - 2 byte access */
    __O   RegPpTxFifo3B_t                                   RegPpTxFifo3B;                /**< Tx FIFO - 3 byte access */
    __O   RegPpTxFifo4B_t                                   RegPpTxFifo4B;                /**< Tx FIFO - 4 byte access */
    __I   RegPpRxFifo1B_t                                   RegPpRxFifo1B;                /**< Rx FIFO - 1 byte access */
    __I   RegPpRxFifo2B_t                                   RegPpRxFifo2B;                /**< Rx FIFO - 2 byte access */
    __I   RegPpRxFifo3B_t                                   RegPpRxFifo3B;                /**< Rx FIFO - 3 byte access */
    __I   RegPpRxFifo4B_t                                   RegPpRxFifo4B;                /**< Rx FIFO - 4 byte access */
    __IO  RegPpFifoCfg_t                                    RegPpFifoCfg;                 /**< Fifo Configuration */
    __I   RegPpFifoSts_t                                    RegPpFifoSts;                 /**< Fifo Status */
    __O   RegPpFifoCmd_t                                    RegPpFifoCmd;                 /**< Fifo commands */
    __IO  RegPpAesKey0_t                                    RegPpAesKey0;                 /**< AES encryption key (bit 31:0) */
    __IO  RegPpAesKey1_t                                    RegPpAesKey1;                 /**< AES encryption key (bit 63:32) */
    __IO  RegPpAesKey2_t                                    RegPpAesKey2;                 /**< AES encryption key (bit 95:64) */
    __IO  RegPpAesKey3_t                                    RegPpAesKey3;                 /**< AES encryption key (bit 127:96) */
    __IO  RegPpAesCtrBlock0_t                               RegPpAesCtrBlock0;            /**< AES encryption counter block (bit 31:0) */
    __IO  RegPpAesCtrBlock1_t                               RegPpAesCtrBlock1;            /**< AES encryption counter block (bit 63:32) */
    __IO  RegPpAesCtrBlock2_t                               RegPpAesCtrBlock2;            /**< AES encryption counter block (bit 95:64) */
    __IO  RegPpAesCtrBlock3_t                               RegPpAesCtrBlock3;            /**< AES encryption counter block (bit 127:96) */
    __IO  RegPpAesCfg_t                                     RegPpAesCfg;                  /**< AES configuration */
    __I   RegPpAesSts_t                                     RegPpAesSts;                  /**< AES status */
    __IO  RegPpBleCteCfg_t                                  RegPpBleCteCfg;               /**< BLE CTE configuration */
    __IO  RegPpBleCteRxTim_t                                RegPpBleCteRxTim;             /**< BLE CTE RX timing */
    __IO  RegPpBleCteTxTim_t                                RegPpBleCteTxTim;             /**< BLE CTE TX Timing */
    __I   RegPpBleCteSts_t                                  RegPpBleCteSts;               /**< BLE CTE Status */
    __IO  RegPpRfTst_t                                      RegPpRfTst;                   /**< Test modes */
} PckProc_RegMap_t;

/** @} end of group PckProc_RegMap */



/***************************************************************************//**
 * @defgroup PckProc_BitFields PckProc bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegPpCtrl
 * @{
 */
// RegPpCtrl.r32
#define  REG_PP_CTRL_RESET_VALUE                            0x00000000u                   /**< Reset value of RegPpCtrl */
#define  REG_PP_CTRL_MASK                                   0x00030101u                   /**< Mask for RegPpCtrl */

#define  PP_EN_SHIFT                                        0                             /**< Shift for PpEn */
#define  PP_EN_MASK                                         0x00000001u                   /**< Mask for PpEn */
#define  PP_EN_BMASK                                        0x1u                          /**< Base mask for PpEn */
#define  PP_EN(x)                                           (((x)&0x1u)<<0)               /**< Set PpEn in register */
#define  GET_PP_EN(reg)                                     (((reg)>>0)&0x1u)             /**< Get PpEn from register */
#define  PP_CTRL_MODE_SHIFT                                 8                             /**< Shift for PpCtrlMode */
#define  PP_CTRL_MODE_MASK                                  0x00000100u                   /**< Mask for PpCtrlMode */
#define  PP_CTRL_MODE_BMASK                                 0x1u                          /**< Base mask for PpCtrlMode */
#define  PP_CTRL_MODE(x)                                    (((x)&0x1u)<<8)               /**< Set PpCtrlMode in register */
#define  GET_PP_CTRL_MODE(reg)                              (((reg)>>8)&0x1u)             /**< Get PpCtrlMode from register */
#define  PP_RX_EN_SHIFT                                     16                            /**< Shift for PpRxEn */
#define  PP_RX_EN_MASK                                      0x00010000u                   /**< Mask for PpRxEn */
#define  PP_RX_EN_BMASK                                     0x1u                          /**< Base mask for PpRxEn */
#define  PP_RX_EN(x)                                        (((x)&0x1u)<<16)              /**< Set PpRxEn in register */
#define  GET_PP_RX_EN(reg)                                  (((reg)>>16)&0x1u)            /**< Get PpRxEn from register */
#define  PP_TX_EN_SHIFT                                     17                            /**< Shift for PpTxEn */
#define  PP_TX_EN_MASK                                      0x00020000u                   /**< Mask for PpTxEn */
#define  PP_TX_EN_BMASK                                     0x1u                          /**< Base mask for PpTxEn */
#define  PP_TX_EN(x)                                        (((x)&0x1u)<<17)              /**< Set PpTxEn in register */
#define  GET_PP_TX_EN(reg)                                  (((reg)>>17)&0x1u)            /**< Get PpTxEn from register */

// RegPpCtrl.regs.PpEn
#define  PP_EN_GSHIFT                                       0                             /**< Shift for group PpEn */
#define  PP_EN_GSIZE                                        8                             /**< Size of group PpEn */
#define  PP_EN_GMASK                                        0x000000FFu                   /**< Mask for group PpEn */

#define  PP_EN_RSHIFT                                       0                             /**< Shift for PpEn */
#define  PP_EN_RMASK                                        0x00000001u                   /**< Mask for PpEn */
#define  PP_EN_RBMASK                                       0x1u                          /**< Base mask for PpEn */
#define  PP_EN_R(x)                                         (((x)&0x1u)<<0)               /**< Set PpEn in register */
#define  GET_PP_EN_R(reg)                                   (((reg)>>0)&0x1u)             /**< Get PpEn from register */

// RegPpCtrl.regs.PpCtrlMode
#define  PP_CTRL_MODE_GSHIFT                                8                             /**< Shift for group PpCtrlMode */
#define  PP_CTRL_MODE_GSIZE                                 8                             /**< Size of group PpCtrlMode */
#define  PP_CTRL_MODE_GMASK                                 0x0000FF00u                   /**< Mask for group PpCtrlMode */

#define  PP_CTRL_MODE_RSHIFT                                0                             /**< Shift for PpCtrlMode */
#define  PP_CTRL_MODE_RMASK                                 0x00000001u                   /**< Mask for PpCtrlMode */
#define  PP_CTRL_MODE_RBMASK                                0x1u                          /**< Base mask for PpCtrlMode */
#define  PP_CTRL_MODE_R(x)                                  (((x)&0x1u)<<0)               /**< Set PpCtrlMode in register */
#define  GET_PP_CTRL_MODE_R(reg)                            (((reg)>>0)&0x1u)             /**< Get PpCtrlMode from register */

// RegPpCtrl.regs.PpCtrlSw
#define  PP_CTRL_SW_GSHIFT                                  16                            /**< Shift for group PpCtrlSw */
#define  PP_CTRL_SW_GSIZE                                   8                             /**< Size of group PpCtrlSw */
#define  PP_CTRL_SW_GMASK                                   0x00FF0000u                   /**< Mask for group PpCtrlSw */

#define  PP_RX_EN_RSHIFT                                    0                             /**< Shift for PpRxEn */
#define  PP_RX_EN_RMASK                                     0x01u                         /**< Mask for PpRxEn */
#define  PP_RX_EN_RBMASK                                    0x1u                          /**< Base mask for PpRxEn */
#define  PP_RX_EN_R(x)                                      (((x)&0x1u)<<0)               /**< Set PpRxEn in register */
#define  GET_PP_RX_EN_R(reg)                                (((reg)>>0)&0x1u)             /**< Get PpRxEn from register */
#define  PP_TX_EN_RSHIFT                                    1                             /**< Shift for PpTxEn */
#define  PP_TX_EN_RMASK                                     0x02u                         /**< Mask for PpTxEn */
#define  PP_TX_EN_RBMASK                                    0x1u                          /**< Base mask for PpTxEn */
#define  PP_TX_EN_R(x)                                      (((x)&0x1u)<<1)               /**< Set PpTxEn in register */
#define  GET_PP_TX_EN_R(reg)                                (((reg)>>1)&0x1u)             /**< Get PpTxEn from register */
/** @} */


/**
 * @name RegPpCfg
 * @{
 */
// RegPpCfg.r32
#define  REG_PP_CFG_RESET_VALUE                             0x00000000u                   /**< Reset value of RegPpCfg */
#define  REG_PP_CFG_MASK                                    0x0F1F0707u                   /**< Mask for RegPpCfg */

#define  PP_PHY_MODE_TX_SHIFT                               0                             /**< Shift for PpPhyModeTx */
#define  PP_PHY_MODE_TX_MASK                                0x00000007u                   /**< Mask for PpPhyModeTx */
#define  PP_PHY_MODE_TX_BMASK                               0x7u                          /**< Base mask for PpPhyModeTx */
#define  PP_PHY_MODE_TX(x)                                  (((x)&0x7u)<<0)               /**< Set PpPhyModeTx in register */
#define  GET_PP_PHY_MODE_TX(reg)                            (((reg)>>0)&0x7u)             /**< Get PpPhyModeTx from register */
#define  PP_PHY_MODE_RX_SHIFT                               8                             /**< Shift for PpPhyModeRx */
#define  PP_PHY_MODE_RX_MASK                                0x00000700u                   /**< Mask for PpPhyModeRx */
#define  PP_PHY_MODE_RX_BMASK                               0x7u                          /**< Base mask for PpPhyModeRx */
#define  PP_PHY_MODE_RX(x)                                  (((x)&0x7u)<<8)               /**< Set PpPhyModeRx in register */
#define  GET_PP_PHY_MODE_RX(reg)                            (((reg)>>8)&0x7u)             /**< Get PpPhyModeRx from register */
#define  PP_PHY_TX_ON_EXTRA_TIM_SHIFT                       16                            /**< Shift for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_MASK                        0x001F0000u                   /**< Mask for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_BMASK                       0x1Fu                         /**< Base mask for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM(x)                          (((x)&0x1Fu)<<16)             /**< Set PpPhyTxOnExtraTim in register */
#define  GET_PP_PHY_TX_ON_EXTRA_TIM(reg)                    (((reg)>>16)&0x1Fu)           /**< Get PpPhyTxOnExtraTim from register */
#define  PP_MODE_SHIFT                                      24                            /**< Shift for PpMode */
#define  PP_MODE_MASK                                       0x03000000u                   /**< Mask for PpMode */
#define  PP_MODE_BMASK                                      0x3u                          /**< Base mask for PpMode */
#define  PP_MODE(x)                                         (((x)&0x3u)<<24)              /**< Set PpMode in register */
#define  GET_PP_MODE(reg)                                   (((reg)>>24)&0x3u)            /**< Get PpMode from register */
#define  ZB_SPREAD_ENABLE_SHIFT                             26                            /**< Shift for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE_MASK                              0x04000000u                   /**< Mask for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE_BMASK                             0x1u                          /**< Base mask for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE(x)                                (((x)&0x1u)<<26)              /**< Set ZBSpreadEnable in register */
#define  GET_ZB_SPREAD_ENABLE(reg)                          (((reg)>>26)&0x1u)            /**< Get ZBSpreadEnable from register */
#define  ZB_MSK_ORDER_SHIFT                                 27                            /**< Shift for ZBMSKOrder */
#define  ZB_MSK_ORDER_MASK                                  0x08000000u                   /**< Mask for ZBMSKOrder */
#define  ZB_MSK_ORDER_BMASK                                 0x1u                          /**< Base mask for ZBMSKOrder */
#define  ZB_MSK_ORDER(x)                                    (((x)&0x1u)<<27)              /**< Set ZBMSKOrder in register */
#define  GET_ZB_MSK_ORDER(reg)                              (((reg)>>27)&0x1u)            /**< Get ZBMSKOrder from register */

// RegPpCfg.regs.PpPhyMode
#define  PP_PHY_MODE_GSHIFT                                 0                             /**< Shift for group PpPhyMode */
#define  PP_PHY_MODE_GSIZE                                  16                            /**< Size of group PpPhyMode */
#define  PP_PHY_MODE_GMASK                                  0x0000FFFFu                   /**< Mask for group PpPhyMode */

#define  PP_PHY_MODE_TX_RSHIFT                              0                             /**< Shift for PpPhyModeTx */
#define  PP_PHY_MODE_TX_RMASK                               0x0007u                       /**< Mask for PpPhyModeTx */
#define  PP_PHY_MODE_TX_RBMASK                              0x7u                          /**< Base mask for PpPhyModeTx */
#define  PP_PHY_MODE_TX_R(x)                                (((x)&0x7u)<<0)               /**< Set PpPhyModeTx in register */
#define  GET_PP_PHY_MODE_TX_R(reg)                          (((reg)>>0)&0x7u)             /**< Get PpPhyModeTx from register */
#define  PP_PHY_MODE_RX_RSHIFT                              8                             /**< Shift for PpPhyModeRx */
#define  PP_PHY_MODE_RX_RMASK                               0x0700u                       /**< Mask for PpPhyModeRx */
#define  PP_PHY_MODE_RX_RBMASK                              0x7u                          /**< Base mask for PpPhyModeRx */
#define  PP_PHY_MODE_RX_R(x)                                (((x)&0x7u)<<8)               /**< Set PpPhyModeRx in register */
#define  GET_PP_PHY_MODE_RX_R(reg)                          (((reg)>>8)&0x7u)             /**< Get PpPhyModeRx from register */

// RegPpCfg.regs.PpPhyTxOnExtraTim
#define  PP_PHY_TX_ON_EXTRA_TIM_GSHIFT                      16                            /**< Shift for group PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_GSIZE                       8                             /**< Size of group PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_GMASK                       0x00FF0000u                   /**< Mask for group PpPhyTxOnExtraTim */

#define  PP_PHY_TX_ON_EXTRA_TIM_RSHIFT                      0                             /**< Shift for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_RMASK                       0x001Fu                       /**< Mask for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_RBMASK                      0x1Fu                         /**< Base mask for PpPhyTxOnExtraTim */
#define  PP_PHY_TX_ON_EXTRA_TIM_R(x)                        (((x)&0x1Fu)<<0)              /**< Set PpPhyTxOnExtraTim in register */
#define  GET_PP_PHY_TX_ON_EXTRA_TIM_R(reg)                  (((reg)>>0)&0x1Fu)            /**< Get PpPhyTxOnExtraTim from register */

// RegPpCfg.regs.PpMode
#define  PP_MODE_GSHIFT                                     24                            /**< Shift for group PpMode */
#define  PP_MODE_GSIZE                                      8                             /**< Size of group PpMode */
#define  PP_MODE_GMASK                                      0xFF000000u                   /**< Mask for group PpMode */

#define  PP_MODE_RSHIFT                                     0                             /**< Shift for PpMode */
#define  PP_MODE_RMASK                                      0x0003u                       /**< Mask for PpMode */
#define  PP_MODE_RBMASK                                     0x3u                          /**< Base mask for PpMode */
#define  PP_MODE_R(x)                                       (((x)&0x3u)<<0)               /**< Set PpMode in register */
#define  GET_PP_MODE_R(reg)                                 (((reg)>>0)&0x3u)             /**< Get PpMode from register */
#define  ZB_SPREAD_ENABLE_RSHIFT                            2                             /**< Shift for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE_RMASK                             0x0004u                       /**< Mask for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE_RBMASK                            0x1u                          /**< Base mask for ZBSpreadEnable */
#define  ZB_SPREAD_ENABLE_R(x)                              (((x)&0x1u)<<2)               /**< Set ZBSpreadEnable in register */
#define  GET_ZB_SPREAD_ENABLE_R(reg)                        (((reg)>>2)&0x1u)             /**< Get ZBSpreadEnable from register */
#define  ZB_MSK_ORDER_RSHIFT                                3                             /**< Shift for ZBMSKOrder */
#define  ZB_MSK_ORDER_RMASK                                 0x0008u                       /**< Mask for ZBMSKOrder */
#define  ZB_MSK_ORDER_RBMASK                                0x1u                          /**< Base mask for ZBMSKOrder */
#define  ZB_MSK_ORDER_R(x)                                  (((x)&0x1u)<<3)               /**< Set ZBMSKOrder in register */
#define  GET_ZB_MSK_ORDER_R(reg)                            (((reg)>>3)&0x1u)             /**< Get ZBMSKOrder from register */
/** @} */


/**
 * @name RegPpPream
 * @{
 */
// RegPpPream.r32
#define  REG_PP_PREAM_RESET_VALUE                           0x00000100u                   /**< Reset value of RegPpPream */
#define  REG_PP_PREAM_MASK                                  0x00000FFFu                   /**< Mask for RegPpPream */

#define  PP_PREAM_PATTERN_SHIFT                             0                             /**< Shift for PpPreamPattern */
#define  PP_PREAM_PATTERN_MASK                              0x000000FFu                   /**< Mask for PpPreamPattern */
#define  PP_PREAM_PATTERN_BMASK                             0xFFu                         /**< Base mask for PpPreamPattern */
#define  PP_PREAM_PATTERN(x)                                (((x)&0xFFu)<<0)              /**< Set PpPreamPattern in register */
#define  GET_PP_PREAM_PATTERN(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpPreamPattern from register */
#define  PP_PREAM_LEN_SHIFT                                 8                             /**< Shift for PpPreamLen */
#define  PP_PREAM_LEN_MASK                                  0x00000F00u                   /**< Mask for PpPreamLen */
#define  PP_PREAM_LEN_BMASK                                 0xFu                          /**< Base mask for PpPreamLen */
#define  PP_PREAM_LEN(x)                                    (((x)&0xFu)<<8)               /**< Set PpPreamLen in register */
#define  GET_PP_PREAM_LEN(reg)                              (((reg)>>8)&0xFu)             /**< Get PpPreamLen from register */

// RegPpPream.regs.PpPreamPattern
#define  PP_PREAM_PATTERN_GSHIFT                            0                             /**< Shift for group PpPreamPattern */
#define  PP_PREAM_PATTERN_GSIZE                             8                             /**< Size of group PpPreamPattern */
#define  PP_PREAM_PATTERN_GMASK                             0x000000FFu                   /**< Mask for group PpPreamPattern */

#define  PP_PREAM_PATTERN_RSHIFT                            0                             /**< Shift for PpPreamPattern */
#define  PP_PREAM_PATTERN_RMASK                             0x000000FFu                   /**< Mask for PpPreamPattern */
#define  PP_PREAM_PATTERN_RBMASK                            0xFFu                         /**< Base mask for PpPreamPattern */
#define  PP_PREAM_PATTERN_R(x)                              (((x)&0xFFu)<<0)              /**< Set PpPreamPattern in register */
#define  GET_PP_PREAM_PATTERN_R(reg)                        (((reg)>>0)&0xFFu)            /**< Get PpPreamPattern from register */

// RegPpPream.regs.PpPreamLen
#define  PP_PREAM_LEN_GSHIFT                                8                             /**< Shift for group PpPreamLen */
#define  PP_PREAM_LEN_GSIZE                                 8                             /**< Size of group PpPreamLen */
#define  PP_PREAM_LEN_GMASK                                 0x0000FF00u                   /**< Mask for group PpPreamLen */

#define  PP_PREAM_LEN_RSHIFT                                0                             /**< Shift for PpPreamLen */
#define  PP_PREAM_LEN_RMASK                                 0x0000000Fu                   /**< Mask for PpPreamLen */
#define  PP_PREAM_LEN_RBMASK                                0xFu                          /**< Base mask for PpPreamLen */
#define  PP_PREAM_LEN_R(x)                                  (((x)&0xFu)<<0)               /**< Set PpPreamLen in register */
#define  GET_PP_PREAM_LEN_R(reg)                            (((reg)>>0)&0xFu)             /**< Get PpPreamLen from register */
/** @} */


/**
 * @name RegPpSyncWord0Lo
 * @{
 */
// RegPpSyncWord0Lo.r32
#define  REG_PP_SYNC_WORD0_LO_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord0Lo */
#define  REG_PP_SYNC_WORD0_LO_MASK                          0xFFFFFFFFu                   /**< Mask for RegPpSyncWord0Lo */

#define  PP_SYNC_WORD0_LO_SHIFT                             0                             /**< Shift for PpSyncWord0Lo */
#define  PP_SYNC_WORD0_LO_MASK                              0xFFFFFFFFu                   /**< Mask for PpSyncWord0Lo */
#define  PP_SYNC_WORD0_LO_BMASK                             0xFFFFFFFFu                   /**< Base mask for PpSyncWord0Lo */
#define  PP_SYNC_WORD0_LO(x)                                (((x)&0xFFFFFFFFu)<<0)        /**< Set PpSyncWord0Lo in register */
#define  GET_PP_SYNC_WORD0_LO(reg)                          (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpSyncWord0Lo from register */
/** @} */


/**
 * @name RegPpSyncWord0Hi
 * @{
 */
// RegPpSyncWord0Hi.r32
#define  REG_PP_SYNC_WORD0_HI_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord0Hi */
#define  REG_PP_SYNC_WORD0_HI_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord0Hi */

#define  PP_SYNC_WORD0_HI_SHIFT                             0                             /**< Shift for PpSyncWord0Hi */
#define  PP_SYNC_WORD0_HI_MASK                              0x000000FFu                   /**< Mask for PpSyncWord0Hi */
#define  PP_SYNC_WORD0_HI_BMASK                             0xFFu                         /**< Base mask for PpSyncWord0Hi */
#define  PP_SYNC_WORD0_HI(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord0Hi in register */
#define  GET_PP_SYNC_WORD0_HI(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord0Hi from register */
/** @} */


/**
 * @name RegPpSyncWord1Lo
 * @{
 */
// RegPpSyncWord1Lo.r32
#define  REG_PP_SYNC_WORD1_LO_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord1Lo */
#define  REG_PP_SYNC_WORD1_LO_MASK                          0xFFFFFFFFu                   /**< Mask for RegPpSyncWord1Lo */

#define  PP_SYNC_WORD1_LO_SHIFT                             0                             /**< Shift for PpSyncWord1Lo */
#define  PP_SYNC_WORD1_LO_MASK                              0xFFFFFFFFu                   /**< Mask for PpSyncWord1Lo */
#define  PP_SYNC_WORD1_LO_BMASK                             0xFFFFFFFFu                   /**< Base mask for PpSyncWord1Lo */
#define  PP_SYNC_WORD1_LO(x)                                (((x)&0xFFFFFFFFu)<<0)        /**< Set PpSyncWord1Lo in register */
#define  GET_PP_SYNC_WORD1_LO(reg)                          (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpSyncWord1Lo from register */
/** @} */


/**
 * @name RegPpSyncWord1Hi
 * @{
 */
// RegPpSyncWord1Hi.r32
#define  REG_PP_SYNC_WORD1_HI_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord1Hi */
#define  REG_PP_SYNC_WORD1_HI_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord1Hi */

#define  PP_SYNC_WORD1_HI_SHIFT                             0                             /**< Shift for PpSyncWord1Hi */
#define  PP_SYNC_WORD1_HI_MASK                              0x000000FFu                   /**< Mask for PpSyncWord1Hi */
#define  PP_SYNC_WORD1_HI_BMASK                             0xFFu                         /**< Base mask for PpSyncWord1Hi */
#define  PP_SYNC_WORD1_HI(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord1Hi in register */
#define  GET_PP_SYNC_WORD1_HI(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord1Hi from register */
/** @} */


/**
 * @name RegPpSyncWord2Ex
 * @{
 */
// RegPpSyncWord2Ex.r32
#define  REG_PP_SYNC_WORD2_EX_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord2Ex */
#define  REG_PP_SYNC_WORD2_EX_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord2Ex */

#define  PP_SYNC_WORD2_EX_SHIFT                             0                             /**< Shift for PpSyncWord2Ex */
#define  PP_SYNC_WORD2_EX_MASK                              0x000000FFu                   /**< Mask for PpSyncWord2Ex */
#define  PP_SYNC_WORD2_EX_BMASK                             0xFFu                         /**< Base mask for PpSyncWord2Ex */
#define  PP_SYNC_WORD2_EX(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord2Ex in register */
#define  GET_PP_SYNC_WORD2_EX(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord2Ex from register */
/** @} */


/**
 * @name RegPpSyncWord3Ex
 * @{
 */
// RegPpSyncWord3Ex.r32
#define  REG_PP_SYNC_WORD3_EX_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord3Ex */
#define  REG_PP_SYNC_WORD3_EX_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord3Ex */

#define  PP_SYNC_WORD3_EX_SHIFT                             0                             /**< Shift for PpSyncWord3Ex */
#define  PP_SYNC_WORD3_EX_MASK                              0x000000FFu                   /**< Mask for PpSyncWord3Ex */
#define  PP_SYNC_WORD3_EX_BMASK                             0xFFu                         /**< Base mask for PpSyncWord3Ex */
#define  PP_SYNC_WORD3_EX(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord3Ex in register */
#define  GET_PP_SYNC_WORD3_EX(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord3Ex from register */
/** @} */


/**
 * @name RegPpSyncWord4Ex
 * @{
 */
// RegPpSyncWord4Ex.r32
#define  REG_PP_SYNC_WORD4_EX_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord4Ex */
#define  REG_PP_SYNC_WORD4_EX_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord4Ex */

#define  PP_SYNC_WORD4_EX_SHIFT                             0                             /**< Shift for PpSyncWord4Ex */
#define  PP_SYNC_WORD4_EX_MASK                              0x000000FFu                   /**< Mask for PpSyncWord4Ex */
#define  PP_SYNC_WORD4_EX_BMASK                             0xFFu                         /**< Base mask for PpSyncWord4Ex */
#define  PP_SYNC_WORD4_EX(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord4Ex in register */
#define  GET_PP_SYNC_WORD4_EX(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord4Ex from register */
/** @} */


/**
 * @name RegPpSyncWord5Ex
 * @{
 */
// RegPpSyncWord5Ex.r32
#define  REG_PP_SYNC_WORD5_EX_RESET_VALUE                   0x00000000u                   /**< Reset value of RegPpSyncWord5Ex */
#define  REG_PP_SYNC_WORD5_EX_MASK                          0x000000FFu                   /**< Mask for RegPpSyncWord5Ex */

#define  PP_SYNC_WORD5_EX_SHIFT                             0                             /**< Shift for PpSyncWord5Ex */
#define  PP_SYNC_WORD5_EX_MASK                              0x000000FFu                   /**< Mask for PpSyncWord5Ex */
#define  PP_SYNC_WORD5_EX_BMASK                             0xFFu                         /**< Base mask for PpSyncWord5Ex */
#define  PP_SYNC_WORD5_EX(x)                                (((x)&0xFFu)<<0)              /**< Set PpSyncWord5Ex in register */
#define  GET_PP_SYNC_WORD5_EX(reg)                          (((reg)>>0)&0xFFu)            /**< Get PpSyncWord5Ex from register */
/** @} */


/**
 * @name RegPpSyncWordCfg
 * @{
 */
// RegPpSyncWordCfg.r32
#define  REG_PP_SYNC_WORD_CFG_RESET_VALUE                   0x00010003u                   /**< Reset value of RegPpSyncWordCfg */
#define  REG_PP_SYNC_WORD_CFG_MASK                          0x003F0307u                   /**< Mask for RegPpSyncWordCfg */

#define  PP_SYNC_WORD_LEN_SHIFT                             0                             /**< Shift for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_MASK                              0x00000007u                   /**< Mask for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_BMASK                             0x7u                          /**< Base mask for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN(x)                                (((x)&0x7u)<<0)               /**< Set PpSyncWordLen in register */
#define  GET_PP_SYNC_WORD_LEN(reg)                          (((reg)>>0)&0x7u)             /**< Get PpSyncWordLen from register */
#define  PP_SYNC_WORD_TX_SEL_SHIFT                          8                             /**< Shift for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_MASK                           0x00000300u                   /**< Mask for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_BMASK                          0x3u                          /**< Base mask for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL(x)                             (((x)&0x3u)<<8)               /**< Set PpSyncWordTxSel in register */
#define  GET_PP_SYNC_WORD_TX_SEL(reg)                       (((reg)>>8)&0x3u)             /**< Get PpSyncWordTxSel from register */
#define  PP_SYNC_WORD_RX_EN_SHIFT                           16                            /**< Shift for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_MASK                            0x003F0000u                   /**< Mask for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_BMASK                           0x3Fu                         /**< Base mask for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN(x)                              (((x)&0x3Fu)<<16)             /**< Set PpSyncWordRxEn in register */
#define  GET_PP_SYNC_WORD_RX_EN(reg)                        (((reg)>>16)&0x3Fu)           /**< Get PpSyncWordRxEn from register */

// RegPpSyncWordCfg.regs.PpSyncWordLen
#define  PP_SYNC_WORD_LEN_GSHIFT                            0                             /**< Shift for group PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_GSIZE                             8                             /**< Size of group PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_GMASK                             0x000000FFu                   /**< Mask for group PpSyncWordLen */

#define  PP_SYNC_WORD_LEN_RSHIFT                            0                             /**< Shift for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_RMASK                             0x00000007u                   /**< Mask for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_RBMASK                            0x7u                          /**< Base mask for PpSyncWordLen */
#define  PP_SYNC_WORD_LEN_R(x)                              (((x)&0x7u)<<0)               /**< Set PpSyncWordLen in register */
#define  GET_PP_SYNC_WORD_LEN_R(reg)                        (((reg)>>0)&0x7u)             /**< Get PpSyncWordLen from register */

// RegPpSyncWordCfg.regs.PpSyncWordTxSel
#define  PP_SYNC_WORD_TX_SEL_GSHIFT                         8                             /**< Shift for group PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_GSIZE                          8                             /**< Size of group PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_GMASK                          0x0000FF00u                   /**< Mask for group PpSyncWordTxSel */

#define  PP_SYNC_WORD_TX_SEL_RSHIFT                         0                             /**< Shift for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_RMASK                          0x00000003u                   /**< Mask for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_RBMASK                         0x3u                          /**< Base mask for PpSyncWordTxSel */
#define  PP_SYNC_WORD_TX_SEL_R(x)                           (((x)&0x3u)<<0)               /**< Set PpSyncWordTxSel in register */
#define  GET_PP_SYNC_WORD_TX_SEL_R(reg)                     (((reg)>>0)&0x3u)             /**< Get PpSyncWordTxSel from register */

// RegPpSyncWordCfg.regs.PpSyncWordRxEn
#define  PP_SYNC_WORD_RX_EN_GSHIFT                          16                            /**< Shift for group PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_GSIZE                           8                             /**< Size of group PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_GMASK                           0x00FF0000u                   /**< Mask for group PpSyncWordRxEn */

#define  PP_SYNC_WORD_RX_EN_RSHIFT                          0                             /**< Shift for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_RMASK                           0x0000003Fu                   /**< Mask for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_RBMASK                          0x3Fu                         /**< Base mask for PpSyncWordRxEn */
#define  PP_SYNC_WORD_RX_EN_R(x)                            (((x)&0x3Fu)<<0)              /**< Set PpSyncWordRxEn in register */
#define  GET_PP_SYNC_WORD_RX_EN_R(reg)                      (((reg)>>0)&0x3Fu)            /**< Get PpSyncWordRxEn from register */
/** @} */


/**
 * @name RegPpCrcPoly
 * @{
 */
// RegPpCrcPoly.r32
#define  REG_PP_CRC_POLY_RESET_VALUE                        0x0080032Du                   /**< Reset value of RegPpCrcPoly */
#define  REG_PP_CRC_POLY_MASK                               0xFFFFFFFFu                   /**< Mask for RegPpCrcPoly */

#define  PP_CRC_POLY_SHIFT                                  0                             /**< Shift for PpCrcPoly */
#define  PP_CRC_POLY_MASK                                   0xFFFFFFFFu                   /**< Mask for PpCrcPoly */
#define  PP_CRC_POLY_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PpCrcPoly */
#define  PP_CRC_POLY(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PpCrcPoly in register */
#define  GET_PP_CRC_POLY(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpCrcPoly from register */
/** @} */


/**
 * @name RegPpCrcInit0
 * @{
 */
// RegPpCrcInit0.r32
#define  REG_PP_CRC_INIT0_RESET_VALUE                       0x00555555u                   /**< Reset value of RegPpCrcInit0 */
#define  REG_PP_CRC_INIT0_MASK                              0xFFFFFFFFu                   /**< Mask for RegPpCrcInit0 */

#define  PP_CRC_INIT0_SHIFT                                 0                             /**< Shift for PpCrcInit0 */
#define  PP_CRC_INIT0_MASK                                  0xFFFFFFFFu                   /**< Mask for PpCrcInit0 */
#define  PP_CRC_INIT0_BMASK                                 0xFFFFFFFFu                   /**< Base mask for PpCrcInit0 */
#define  PP_CRC_INIT0(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set PpCrcInit0 in register */
#define  GET_PP_CRC_INIT0(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpCrcInit0 from register */
/** @} */


/**
 * @name RegPpCrcInit1
 * @{
 */
// RegPpCrcInit1.r32
#define  REG_PP_CRC_INIT1_RESET_VALUE                       0x00555555u                   /**< Reset value of RegPpCrcInit1 */
#define  REG_PP_CRC_INIT1_MASK                              0xFFFFFFFFu                   /**< Mask for RegPpCrcInit1 */

#define  PP_CRC_INIT1_SHIFT                                 0                             /**< Shift for PpCrcInit1 */
#define  PP_CRC_INIT1_MASK                                  0xFFFFFFFFu                   /**< Mask for PpCrcInit1 */
#define  PP_CRC_INIT1_BMASK                                 0xFFFFFFFFu                   /**< Base mask for PpCrcInit1 */
#define  PP_CRC_INIT1(x)                                    (((x)&0xFFFFFFFFu)<<0)        /**< Set PpCrcInit1 in register */
#define  GET_PP_CRC_INIT1(reg)                              (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpCrcInit1 from register */
/** @} */


/**
 * @name RegPpCrcCfg
 * @{
 */
// RegPpCrcCfg.r32
#define  REG_PP_CRC_CFG_RESET_VALUE                         0x00000002u                   /**< Reset value of RegPpCrcCfg */
#define  REG_PP_CRC_CFG_MASK                                0x0000003Bu                   /**< Mask for RegPpCrcCfg */

#define  PP_CRC_LEN_SHIFT                                   0                             /**< Shift for PpCrcLen */
#define  PP_CRC_LEN_MASK                                    0x00000003u                   /**< Mask for PpCrcLen */
#define  PP_CRC_LEN_BMASK                                   0x3u                          /**< Base mask for PpCrcLen */
#define  PP_CRC_LEN(x)                                      (((x)&0x3u)<<0)               /**< Set PpCrcLen in register */
#define  GET_PP_CRC_LEN(reg)                                (((reg)>>0)&0x3u)             /**< Get PpCrcLen from register */
#define  PP_CRC_RANGE_SYNC_SHIFT                            3                             /**< Shift for PpCrcRangeSync */
#define  PP_CRC_RANGE_SYNC_MASK                             0x00000008u                   /**< Mask for PpCrcRangeSync */
#define  PP_CRC_RANGE_SYNC_BMASK                            0x1u                          /**< Base mask for PpCrcRangeSync */
#define  PP_CRC_RANGE_SYNC(x)                               (((x)&0x1u)<<3)               /**< Set PpCrcRangeSync in register */
#define  GET_PP_CRC_RANGE_SYNC(reg)                         (((reg)>>3)&0x1u)             /**< Get PpCrcRangeSync from register */
#define  PP_CRC_AFTER_WHITE_SHIFT                           4                             /**< Shift for PpCrcAfterWhite */
#define  PP_CRC_AFTER_WHITE_MASK                            0x00000010u                   /**< Mask for PpCrcAfterWhite */
#define  PP_CRC_AFTER_WHITE_BMASK                           0x1u                          /**< Base mask for PpCrcAfterWhite */
#define  PP_CRC_AFTER_WHITE(x)                              (((x)&0x1u)<<4)               /**< Set PpCrcAfterWhite in register */
#define  GET_PP_CRC_AFTER_WHITE(reg)                        (((reg)>>4)&0x1u)             /**< Get PpCrcAfterWhite from register */
#define  PP_CRC_STORE_RX_SHIFT                              5                             /**< Shift for PpCrcStoreRx */
#define  PP_CRC_STORE_RX_MASK                               0x00000020u                   /**< Mask for PpCrcStoreRx */
#define  PP_CRC_STORE_RX_BMASK                              0x1u                          /**< Base mask for PpCrcStoreRx */
#define  PP_CRC_STORE_RX(x)                                 (((x)&0x1u)<<5)               /**< Set PpCrcStoreRx in register */
#define  GET_PP_CRC_STORE_RX(reg)                           (((reg)>>5)&0x1u)             /**< Get PpCrcStoreRx from register */
/** @} */


/**
 * @name RegPpWhitePoly
 * @{
 */
// RegPpWhitePoly.r32
#define  REG_PP_WHITE_POLY_RESET_VALUE                      0x00000048u                   /**< Reset value of RegPpWhitePoly */
#define  REG_PP_WHITE_POLY_MASK                             0xFFFFFFFFu                   /**< Mask for RegPpWhitePoly */

#define  PP_WHITE_POLY_SHIFT                                0                             /**< Shift for PpWhitePoly */
#define  PP_WHITE_POLY_MASK                                 0xFFFFFFFFu                   /**< Mask for PpWhitePoly */
#define  PP_WHITE_POLY_BMASK                                0xFFFFFFFFu                   /**< Base mask for PpWhitePoly */
#define  PP_WHITE_POLY(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set PpWhitePoly in register */
#define  GET_PP_WHITE_POLY(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpWhitePoly from register */
/** @} */


/**
 * @name RegPpWhiteInit
 * @{
 */
// RegPpWhiteInit.r32
#define  REG_PP_WHITE_INIT_RESET_VALUE                      0x00000001u                   /**< Reset value of RegPpWhiteInit */
#define  REG_PP_WHITE_INIT_MASK                             0xFFFFFFFFu                   /**< Mask for RegPpWhiteInit */

#define  PP_WHITE_INIT_SHIFT                                0                             /**< Shift for PpWhiteInit */
#define  PP_WHITE_INIT_MASK                                 0xFFFFFFFFu                   /**< Mask for PpWhiteInit */
#define  PP_WHITE_INIT_BMASK                                0xFFFFFFFFu                   /**< Base mask for PpWhiteInit */
#define  PP_WHITE_INIT(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set PpWhiteInit in register */
#define  GET_PP_WHITE_INIT(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpWhiteInit from register */
/** @} */


/**
 * @name RegPpWhiteCfg
 * @{
 */
// RegPpWhiteCfg.r32
#define  REG_PP_WHITE_CFG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegPpWhiteCfg */
#define  REG_PP_WHITE_CFG_MASK                              0x00000003u                   /**< Mask for RegPpWhiteCfg */

#define  PP_WHITE_BIT_SWAP_PDU_SHIFT                        0                             /**< Shift for PpWhiteBitSwapPdu */
#define  PP_WHITE_BIT_SWAP_PDU_MASK                         0x00000001u                   /**< Mask for PpWhiteBitSwapPdu */
#define  PP_WHITE_BIT_SWAP_PDU_BMASK                        0x1u                          /**< Base mask for PpWhiteBitSwapPdu */
#define  PP_WHITE_BIT_SWAP_PDU(x)                           (((x)&0x1u)<<0)               /**< Set PpWhiteBitSwapPdu in register */
#define  GET_PP_WHITE_BIT_SWAP_PDU(reg)                     (((reg)>>0)&0x1u)             /**< Get PpWhiteBitSwapPdu from register */
#define  PP_WHITE_BIT_SWAP_CRC_SHIFT                        1                             /**< Shift for PpWhiteBitSwapCrc */
#define  PP_WHITE_BIT_SWAP_CRC_MASK                         0x00000002u                   /**< Mask for PpWhiteBitSwapCrc */
#define  PP_WHITE_BIT_SWAP_CRC_BMASK                        0x1u                          /**< Base mask for PpWhiteBitSwapCrc */
#define  PP_WHITE_BIT_SWAP_CRC(x)                           (((x)&0x1u)<<1)               /**< Set PpWhiteBitSwapCrc in register */
#define  GET_PP_WHITE_BIT_SWAP_CRC(reg)                     (((reg)>>1)&0x1u)             /**< Get PpWhiteBitSwapCrc from register */
/** @} */


/**
 * @name RegPpPduLen
 * @{
 */
// RegPpPduLen.r32
#define  REG_PP_PDU_LEN_RESET_VALUE                         0x00010000u                   /**< Reset value of RegPpPduLen */
#define  REG_PP_PDU_LEN_MASK                                0x0F0301FFu                   /**< Mask for RegPpPduLen */

#define  PP_PDU_LEN_SHIFT                                   0                             /**< Shift for PpPduLen */
#define  PP_PDU_LEN_MASK                                    0x000001FFu                   /**< Mask for PpPduLen */
#define  PP_PDU_LEN_BMASK                                   0x1FFu                        /**< Base mask for PpPduLen */
#define  PP_PDU_LEN(x)                                      (((x)&0x1FFu)<<0)             /**< Set PpPduLen in register */
#define  GET_PP_PDU_LEN(reg)                                (((reg)>>0)&0x1FFu)           /**< Get PpPduLen from register */
#define  PP_PDU_LEN_POS_SHIFT                               16                            /**< Shift for PpPduLenPos */
#define  PP_PDU_LEN_POS_MASK                                0x00030000u                   /**< Mask for PpPduLenPos */
#define  PP_PDU_LEN_POS_BMASK                               0x3u                          /**< Base mask for PpPduLenPos */
#define  PP_PDU_LEN_POS(x)                                  (((x)&0x3u)<<16)              /**< Set PpPduLenPos in register */
#define  GET_PP_PDU_LEN_POS(reg)                            (((reg)>>16)&0x3u)            /**< Get PpPduLenPos from register */
#define  PP_PDU_LEN_CORR_SHIFT                              24                            /**< Shift for PpPduLenCorr */
#define  PP_PDU_LEN_CORR_MASK                               0x0F000000u                   /**< Mask for PpPduLenCorr */
#define  PP_PDU_LEN_CORR_BMASK                              0xFu                          /**< Base mask for PpPduLenCorr */
#define  PP_PDU_LEN_CORR(x)                                 (((x)&0xFu)<<24)              /**< Set PpPduLenCorr in register */
#define  GET_PP_PDU_LEN_CORR(reg)                           (((reg)>>24)&0xFu)            /**< Get PpPduLenCorr from register */

// RegPpPduLen.regs.PpPduLen
#define  PP_PDU_LEN_GSHIFT                                  0                             /**< Shift for group PpPduLen */
#define  PP_PDU_LEN_GSIZE                                   16                            /**< Size of group PpPduLen */
#define  PP_PDU_LEN_GMASK                                   0x0000FFFFu                   /**< Mask for group PpPduLen */

#define  PP_PDU_LEN_RSHIFT                                  0                             /**< Shift for PpPduLen */
#define  PP_PDU_LEN_RMASK                                   0x000001FFu                   /**< Mask for PpPduLen */
#define  PP_PDU_LEN_RBMASK                                  0x1FFu                        /**< Base mask for PpPduLen */
#define  PP_PDU_LEN_R(x)                                    (((x)&0x1FFu)<<0)             /**< Set PpPduLen in register */
#define  GET_PP_PDU_LEN_R(reg)                              (((reg)>>0)&0x1FFu)           /**< Get PpPduLen from register */

// RegPpPduLen.regs.PpPduLenPos
#define  PP_PDU_LEN_POS_GSHIFT                              16                            /**< Shift for group PpPduLenPos */
#define  PP_PDU_LEN_POS_GSIZE                               8                             /**< Size of group PpPduLenPos */
#define  PP_PDU_LEN_POS_GMASK                               0x00FF0000u                   /**< Mask for group PpPduLenPos */

#define  PP_PDU_LEN_POS_RSHIFT                              0                             /**< Shift for PpPduLenPos */
#define  PP_PDU_LEN_POS_RMASK                               0x00000003u                   /**< Mask for PpPduLenPos */
#define  PP_PDU_LEN_POS_RBMASK                              0x3u                          /**< Base mask for PpPduLenPos */
#define  PP_PDU_LEN_POS_R(x)                                (((x)&0x3u)<<0)               /**< Set PpPduLenPos in register */
#define  GET_PP_PDU_LEN_POS_R(reg)                          (((reg)>>0)&0x3u)             /**< Get PpPduLenPos from register */

// RegPpPduLen.regs.PpPduLenCorr
#define  PP_PDU_LEN_CORR_GSHIFT                             24                            /**< Shift for group PpPduLenCorr */
#define  PP_PDU_LEN_CORR_GSIZE                              8                             /**< Size of group PpPduLenCorr */
#define  PP_PDU_LEN_CORR_GMASK                              0xFF000000u                   /**< Mask for group PpPduLenCorr */

#define  PP_PDU_LEN_CORR_RSHIFT                             0                             /**< Shift for PpPduLenCorr */
#define  PP_PDU_LEN_CORR_RMASK                              0x0000000Fu                   /**< Mask for PpPduLenCorr */
#define  PP_PDU_LEN_CORR_RBMASK                             0xFu                          /**< Base mask for PpPduLenCorr */
#define  PP_PDU_LEN_CORR_R(x)                               (((x)&0xFu)<<0)               /**< Set PpPduLenCorr in register */
#define  GET_PP_PDU_LEN_CORR_R(reg)                         (((reg)>>0)&0xFu)             /**< Get PpPduLenCorr from register */
/** @} */


/**
 * @name RegPpPckHndl
 * @{
 */
// RegPpPckHndl.r32
#define  REG_PP_PCK_HNDL_RESET_VALUE                        0x0000005Fu                   /**< Reset value of RegPpPckHndl */
#define  REG_PP_PCK_HNDL_MASK                               0x0000007Fu                   /**< Mask for RegPpPckHndl */

#define  PP_LSB_FIRST_SHIFT                                 0                             /**< Shift for PpLsbFirst */
#define  PP_LSB_FIRST_MASK                                  0x00000001u                   /**< Mask for PpLsbFirst */
#define  PP_LSB_FIRST_BMASK                                 0x1u                          /**< Base mask for PpLsbFirst */
#define  PP_LSB_FIRST(x)                                    (((x)&0x1u)<<0)               /**< Set PpLsbFirst in register */
#define  GET_PP_LSB_FIRST(reg)                              (((reg)>>0)&0x1u)             /**< Get PpLsbFirst from register */
#define  PP_PREAM_EN_SHIFT                                  1                             /**< Shift for PpPreamEn */
#define  PP_PREAM_EN_MASK                                   0x00000002u                   /**< Mask for PpPreamEn */
#define  PP_PREAM_EN_BMASK                                  0x1u                          /**< Base mask for PpPreamEn */
#define  PP_PREAM_EN(x)                                     (((x)&0x1u)<<1)               /**< Set PpPreamEn in register */
#define  GET_PP_PREAM_EN(reg)                               (((reg)>>1)&0x1u)             /**< Get PpPreamEn from register */
#define  PP_SYNC_WORD_EN_SHIFT                              2                             /**< Shift for PpSyncWordEn */
#define  PP_SYNC_WORD_EN_MASK                               0x00000004u                   /**< Mask for PpSyncWordEn */
#define  PP_SYNC_WORD_EN_BMASK                              0x1u                          /**< Base mask for PpSyncWordEn */
#define  PP_SYNC_WORD_EN(x)                                 (((x)&0x1u)<<2)               /**< Set PpSyncWordEn in register */
#define  GET_PP_SYNC_WORD_EN(reg)                           (((reg)>>2)&0x1u)             /**< Get PpSyncWordEn from register */
#define  PP_CRC_EN_SHIFT                                    3                             /**< Shift for PpCrcEn */
#define  PP_CRC_EN_MASK                                     0x00000008u                   /**< Mask for PpCrcEn */
#define  PP_CRC_EN_BMASK                                    0x1u                          /**< Base mask for PpCrcEn */
#define  PP_CRC_EN(x)                                       (((x)&0x1u)<<3)               /**< Set PpCrcEn in register */
#define  GET_PP_CRC_EN(reg)                                 (((reg)>>3)&0x1u)             /**< Get PpCrcEn from register */
#define  PP_WHITE_EN_SHIFT                                  4                             /**< Shift for PpWhiteEn */
#define  PP_WHITE_EN_MASK                                   0x00000010u                   /**< Mask for PpWhiteEn */
#define  PP_WHITE_EN_BMASK                                  0x1u                          /**< Base mask for PpWhiteEn */
#define  PP_WHITE_EN(x)                                     (((x)&0x1u)<<4)               /**< Set PpWhiteEn in register */
#define  GET_PP_WHITE_EN(reg)                               (((reg)>>4)&0x1u)             /**< Get PpWhiteEn from register */
#define  PP_FIX_PCK_LEN_EN_SHIFT                            5                             /**< Shift for PpFixPckLenEn */
#define  PP_FIX_PCK_LEN_EN_MASK                             0x00000020u                   /**< Mask for PpFixPckLenEn */
#define  PP_FIX_PCK_LEN_EN_BMASK                            0x1u                          /**< Base mask for PpFixPckLenEn */
#define  PP_FIX_PCK_LEN_EN(x)                               (((x)&0x1u)<<5)               /**< Set PpFixPckLenEn in register */
#define  GET_PP_FIX_PCK_LEN_EN(reg)                         (((reg)>>5)&0x1u)             /**< Get PpFixPckLenEn from register */
#define  PP_ZB_FRAME_VERSION_LSB_FIRST_SHIFT                6                             /**< Shift for PpZbFrameVersionLsbFirst */
#define  PP_ZB_FRAME_VERSION_LSB_FIRST_MASK                 0x00000040u                   /**< Mask for PpZbFrameVersionLsbFirst */
#define  PP_ZB_FRAME_VERSION_LSB_FIRST_BMASK                0x1u                          /**< Base mask for PpZbFrameVersionLsbFirst */
#define  PP_ZB_FRAME_VERSION_LSB_FIRST(x)                   (((x)&0x1u)<<6)               /**< Set PpZbFrameVersionLsbFirst in register */
#define  GET_PP_ZB_FRAME_VERSION_LSB_FIRST(reg)             (((reg)>>6)&0x1u)             /**< Get PpZbFrameVersionLsbFirst from register */
/** @} */


/**
 * @name RegPpSts
 * @{
 */
// RegPpSts.r32
#define  REG_PP_STS_RESET_VALUE                             0x00000000u                   /**< Reset value of RegPpSts */
#define  REG_PP_STS_MASK                                    0x3FFF03FFu                   /**< Mask for RegPpSts */

#define  PP_STS_RX_ON_SHIFT                                 0                             /**< Shift for PpStsRxOn */
#define  PP_STS_RX_ON_MASK                                  0x00000001u                   /**< Mask for PpStsRxOn */
#define  PP_STS_RX_ON_BMASK                                 0x1u                          /**< Base mask for PpStsRxOn */
#define  PP_STS_RX_ON(x)                                    (((x)&0x1u)<<0)               /**< Set PpStsRxOn in register */
#define  GET_PP_STS_RX_ON(reg)                              (((reg)>>0)&0x1u)             /**< Get PpStsRxOn from register */
#define  PP_STS_TX_ON_SHIFT                                 1                             /**< Shift for PpStsTxOn */
#define  PP_STS_TX_ON_MASK                                  0x00000002u                   /**< Mask for PpStsTxOn */
#define  PP_STS_TX_ON_BMASK                                 0x1u                          /**< Base mask for PpStsTxOn */
#define  PP_STS_TX_ON(x)                                    (((x)&0x1u)<<1)               /**< Set PpStsTxOn in register */
#define  GET_PP_STS_TX_ON(reg)                              (((reg)>>1)&0x1u)             /**< Get PpStsTxOn from register */
#define  PP_STS_RX_SYNC_WORD_WAIT_SHIFT                     2                             /**< Shift for PpStsRxSyncWordWait */
#define  PP_STS_RX_SYNC_WORD_WAIT_MASK                      0x00000004u                   /**< Mask for PpStsRxSyncWordWait */
#define  PP_STS_RX_SYNC_WORD_WAIT_BMASK                     0x1u                          /**< Base mask for PpStsRxSyncWordWait */
#define  PP_STS_RX_SYNC_WORD_WAIT(x)                        (((x)&0x1u)<<2)               /**< Set PpStsRxSyncWordWait in register */
#define  GET_PP_STS_RX_SYNC_WORD_WAIT(reg)                  (((reg)>>2)&0x1u)             /**< Get PpStsRxSyncWordWait from register */
#define  PP_STS_RX_SYNC_WORD_DETECTED_SHIFT                 3                             /**< Shift for PpStsRxSyncWordDetected */
#define  PP_STS_RX_SYNC_WORD_DETECTED_MASK                  0x00000008u                   /**< Mask for PpStsRxSyncWordDetected */
#define  PP_STS_RX_SYNC_WORD_DETECTED_BMASK                 0x1u                          /**< Base mask for PpStsRxSyncWordDetected */
#define  PP_STS_RX_SYNC_WORD_DETECTED(x)                    (((x)&0x1u)<<3)               /**< Set PpStsRxSyncWordDetected in register */
#define  GET_PP_STS_RX_SYNC_WORD_DETECTED(reg)              (((reg)>>3)&0x1u)             /**< Get PpStsRxSyncWordDetected from register */
#define  PP_STS_RX_PDU_LEN_ERR_SHIFT                        4                             /**< Shift for PpStsRxPduLenErr */
#define  PP_STS_RX_PDU_LEN_ERR_MASK                         0x00000010u                   /**< Mask for PpStsRxPduLenErr */
#define  PP_STS_RX_PDU_LEN_ERR_BMASK                        0x1u                          /**< Base mask for PpStsRxPduLenErr */
#define  PP_STS_RX_PDU_LEN_ERR(x)                           (((x)&0x1u)<<4)               /**< Set PpStsRxPduLenErr in register */
#define  GET_PP_STS_RX_PDU_LEN_ERR(reg)                     (((reg)>>4)&0x1u)             /**< Get PpStsRxPduLenErr from register */
#define  PP_STS_RX_CRC_ERR_SHIFT                            5                             /**< Shift for PpStsRxCrcErr */
#define  PP_STS_RX_CRC_ERR_MASK                             0x00000020u                   /**< Mask for PpStsRxCrcErr */
#define  PP_STS_RX_CRC_ERR_BMASK                            0x1u                          /**< Base mask for PpStsRxCrcErr */
#define  PP_STS_RX_CRC_ERR(x)                               (((x)&0x1u)<<5)               /**< Set PpStsRxCrcErr in register */
#define  GET_PP_STS_RX_CRC_ERR(reg)                         (((reg)>>5)&0x1u)             /**< Get PpStsRxCrcErr from register */
#define  PP_STS_RX_DONE_SHIFT                               6                             /**< Shift for PpStsRxDone */
#define  PP_STS_RX_DONE_MASK                                0x00000040u                   /**< Mask for PpStsRxDone */
#define  PP_STS_RX_DONE_BMASK                               0x1u                          /**< Base mask for PpStsRxDone */
#define  PP_STS_RX_DONE(x)                                  (((x)&0x1u)<<6)               /**< Set PpStsRxDone in register */
#define  GET_PP_STS_RX_DONE(reg)                            (((reg)>>6)&0x1u)             /**< Get PpStsRxDone from register */
#define  PP_STS_TX_DONE_SHIFT                               7                             /**< Shift for PpStsTxDone */
#define  PP_STS_TX_DONE_MASK                                0x00000080u                   /**< Mask for PpStsTxDone */
#define  PP_STS_TX_DONE_BMASK                               0x1u                          /**< Base mask for PpStsTxDone */
#define  PP_STS_TX_DONE(x)                                  (((x)&0x1u)<<7)               /**< Set PpStsTxDone in register */
#define  GET_PP_STS_TX_DONE(reg)                            (((reg)>>7)&0x1u)             /**< Get PpStsTxDone from register */
#define  PP_STS_RX_CODED_PHY_CI_SHIFT                       8                             /**< Shift for PpStsRxCodedPhyCi */
#define  PP_STS_RX_CODED_PHY_CI_MASK                        0x00000300u                   /**< Mask for PpStsRxCodedPhyCi */
#define  PP_STS_RX_CODED_PHY_CI_BMASK                       0x3u                          /**< Base mask for PpStsRxCodedPhyCi */
#define  PP_STS_RX_CODED_PHY_CI(x)                          (((x)&0x3u)<<8)               /**< Set PpStsRxCodedPhyCi in register */
#define  GET_PP_STS_RX_CODED_PHY_CI(reg)                    (((reg)>>8)&0x3u)             /**< Get PpStsRxCodedPhyCi from register */
#define  PP_STS_RX_SYNC_WORD_SHIFT                          16                            /**< Shift for PpStsRxSyncWord */
#define  PP_STS_RX_SYNC_WORD_MASK                           0x003F0000u                   /**< Mask for PpStsRxSyncWord */
#define  PP_STS_RX_SYNC_WORD_BMASK                          0x3Fu                         /**< Base mask for PpStsRxSyncWord */
#define  PP_STS_RX_SYNC_WORD(x)                             (((x)&0x3Fu)<<16)             /**< Set PpStsRxSyncWord in register */
#define  GET_PP_STS_RX_SYNC_WORD(reg)                       (((reg)>>16)&0x3Fu)           /**< Get PpStsRxSyncWord from register */
#define  PP_STS_RX_ZB_CA_SHIFT                              22                            /**< Shift for PpStsRxZbCa */
#define  PP_STS_RX_ZB_CA_MASK                               0x3FC00000u                   /**< Mask for PpStsRxZbCa */
#define  PP_STS_RX_ZB_CA_BMASK                              0xFFu                         /**< Base mask for PpStsRxZbCa */
#define  PP_STS_RX_ZB_CA(x)                                 (((x)&0xFFu)<<22)             /**< Set PpStsRxZbCa in register */
#define  GET_PP_STS_RX_ZB_CA(reg)                           (((reg)>>22)&0xFFu)           /**< Get PpStsRxZbCa from register */
/** @} */


/**
 * @name RegPpTxFifo1B
 * @{
 */
// RegPpTxFifo1B.r32
#define  REG_PP_TX_FIFO_1B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpTxFifo1B */
#define  REG_PP_TX_FIFO_1B_MASK                             0x000000FFu                   /**< Mask for RegPpTxFifo1B */

#define  PP_TX_FIFO_1B_SHIFT                                0                             /**< Shift for PpTxFifo1B */
#define  PP_TX_FIFO_1B_MASK                                 0x000000FFu                   /**< Mask for PpTxFifo1B */
#define  PP_TX_FIFO_1B_BMASK                                0xFFu                         /**< Base mask for PpTxFifo1B */
#define  PP_TX_FIFO_1B(x)                                   (((x)&0xFFu)<<0)              /**< Set PpTxFifo1B in register */
#define  GET_PP_TX_FIFO_1B(reg)                             (((reg)>>0)&0xFFu)            /**< Get PpTxFifo1B from register */
/** @} */


/**
 * @name RegPpTxFifo2B
 * @{
 */
// RegPpTxFifo2B.r32
#define  REG_PP_TX_FIFO_2B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpTxFifo2B */
#define  REG_PP_TX_FIFO_2B_MASK                             0x0000FFFFu                   /**< Mask for RegPpTxFifo2B */

#define  PP_TX_FIFO_2B_SHIFT                                0                             /**< Shift for PpTxFifo2B */
#define  PP_TX_FIFO_2B_MASK                                 0x0000FFFFu                   /**< Mask for PpTxFifo2B */
#define  PP_TX_FIFO_2B_BMASK                                0xFFFFu                       /**< Base mask for PpTxFifo2B */
#define  PP_TX_FIFO_2B(x)                                   (((x)&0xFFFFu)<<0)            /**< Set PpTxFifo2B in register */
#define  GET_PP_TX_FIFO_2B(reg)                             (((reg)>>0)&0xFFFFu)          /**< Get PpTxFifo2B from register */
/** @} */


/**
 * @name RegPpTxFifo3B
 * @{
 */
// RegPpTxFifo3B.r32
#define  REG_PP_TX_FIFO_3B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpTxFifo3B */
#define  REG_PP_TX_FIFO_3B_MASK                             0x00FFFFFFu                   /**< Mask for RegPpTxFifo3B */

#define  PP_TX_FIFO_3B_SHIFT                                0                             /**< Shift for PpTxFifo3B */
#define  PP_TX_FIFO_3B_MASK                                 0x00FFFFFFu                   /**< Mask for PpTxFifo3B */
#define  PP_TX_FIFO_3B_BMASK                                0xFFFFFFu                     /**< Base mask for PpTxFifo3B */
#define  PP_TX_FIFO_3B(x)                                   (((x)&0xFFFFFFu)<<0)          /**< Set PpTxFifo3B in register */
#define  GET_PP_TX_FIFO_3B(reg)                             (((reg)>>0)&0xFFFFFFu)        /**< Get PpTxFifo3B from register */
/** @} */


/**
 * @name RegPpTxFifo4B
 * @{
 */
// RegPpTxFifo4B.r32
#define  REG_PP_TX_FIFO_4B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpTxFifo4B */
#define  REG_PP_TX_FIFO_4B_MASK                             0xFFFFFFFFu                   /**< Mask for RegPpTxFifo4B */

#define  PP_TX_FIFO_4B_SHIFT                                0                             /**< Shift for PpTxFifo4B */
#define  PP_TX_FIFO_4B_MASK                                 0xFFFFFFFFu                   /**< Mask for PpTxFifo4B */
#define  PP_TX_FIFO_4B_BMASK                                0xFFFFFFFFu                   /**< Base mask for PpTxFifo4B */
#define  PP_TX_FIFO_4B(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set PpTxFifo4B in register */
#define  GET_PP_TX_FIFO_4B(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpTxFifo4B from register */
/** @} */


/**
 * @name RegPpRxFifo1B
 * @{
 */
// RegPpRxFifo1B.r32
#define  REG_PP_RX_FIFO_1B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpRxFifo1B */
#define  REG_PP_RX_FIFO_1B_MASK                             0x000000FFu                   /**< Mask for RegPpRxFifo1B */

#define  PP_RX_FIFO_1B_SHIFT                                0                             /**< Shift for PpRxFifo1B */
#define  PP_RX_FIFO_1B_MASK                                 0x000000FFu                   /**< Mask for PpRxFifo1B */
#define  PP_RX_FIFO_1B_BMASK                                0xFFu                         /**< Base mask for PpRxFifo1B */
#define  PP_RX_FIFO_1B(x)                                   (((x)&0xFFu)<<0)              /**< Set PpRxFifo1B in register */
#define  GET_PP_RX_FIFO_1B(reg)                             (((reg)>>0)&0xFFu)            /**< Get PpRxFifo1B from register */
/** @} */


/**
 * @name RegPpRxFifo2B
 * @{
 */
// RegPpRxFifo2B.r32
#define  REG_PP_RX_FIFO_2B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpRxFifo2B */
#define  REG_PP_RX_FIFO_2B_MASK                             0x0000FFFFu                   /**< Mask for RegPpRxFifo2B */

#define  PP_RX_FIFO_2B_SHIFT                                0                             /**< Shift for PpRxFifo2B */
#define  PP_RX_FIFO_2B_MASK                                 0x0000FFFFu                   /**< Mask for PpRxFifo2B */
#define  PP_RX_FIFO_2B_BMASK                                0xFFFFu                       /**< Base mask for PpRxFifo2B */
#define  PP_RX_FIFO_2B(x)                                   (((x)&0xFFFFu)<<0)            /**< Set PpRxFifo2B in register */
#define  GET_PP_RX_FIFO_2B(reg)                             (((reg)>>0)&0xFFFFu)          /**< Get PpRxFifo2B from register */
/** @} */


/**
 * @name RegPpRxFifo3B
 * @{
 */
// RegPpRxFifo3B.r32
#define  REG_PP_RX_FIFO_3B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpRxFifo3B */
#define  REG_PP_RX_FIFO_3B_MASK                             0x00FFFFFFu                   /**< Mask for RegPpRxFifo3B */

#define  PP_RX_FIFO_3B_SHIFT                                0                             /**< Shift for PpRxFifo3B */
#define  PP_RX_FIFO_3B_MASK                                 0x00FFFFFFu                   /**< Mask for PpRxFifo3B */
#define  PP_RX_FIFO_3B_BMASK                                0xFFFFFFu                     /**< Base mask for PpRxFifo3B */
#define  PP_RX_FIFO_3B(x)                                   (((x)&0xFFFFFFu)<<0)          /**< Set PpRxFifo3B in register */
#define  GET_PP_RX_FIFO_3B(reg)                             (((reg)>>0)&0xFFFFFFu)        /**< Get PpRxFifo3B from register */
/** @} */


/**
 * @name RegPpRxFifo4B
 * @{
 */
// RegPpRxFifo4B.r32
#define  REG_PP_RX_FIFO_4B_RESET_VALUE                      0x00000000u                   /**< Reset value of RegPpRxFifo4B */
#define  REG_PP_RX_FIFO_4B_MASK                             0xFFFFFFFFu                   /**< Mask for RegPpRxFifo4B */

#define  PP_RX_FIFO_4B_SHIFT                                0                             /**< Shift for PpRxFifo4B */
#define  PP_RX_FIFO_4B_MASK                                 0xFFFFFFFFu                   /**< Mask for PpRxFifo4B */
#define  PP_RX_FIFO_4B_BMASK                                0xFFFFFFFFu                   /**< Base mask for PpRxFifo4B */
#define  PP_RX_FIFO_4B(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set PpRxFifo4B in register */
#define  GET_PP_RX_FIFO_4B(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpRxFifo4B from register */
/** @} */


/**
 * @name RegPpFifoCfg
 * @{
 */
// RegPpFifoCfg.r32
#define  REG_PP_FIFO_CFG_RESET_VALUE                        0x00000808u                   /**< Reset value of RegPpFifoCfg */
#define  REG_PP_FIFO_CFG_MASK                               0x00001F1Fu                   /**< Mask for RegPpFifoCfg */

#define  PP_TX_FIFO_LIMIT_SHIFT                             0                             /**< Shift for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_MASK                              0x0000001Fu                   /**< Mask for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_BMASK                             0x1Fu                         /**< Base mask for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT(x)                                (((x)&0x1Fu)<<0)              /**< Set PpTxFifoLimit in register */
#define  GET_PP_TX_FIFO_LIMIT(reg)                          (((reg)>>0)&0x1Fu)            /**< Get PpTxFifoLimit from register */
#define  PP_RX_FIFO_LIMIT_SHIFT                             8                             /**< Shift for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_MASK                              0x00001F00u                   /**< Mask for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_BMASK                             0x1Fu                         /**< Base mask for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT(x)                                (((x)&0x1Fu)<<8)              /**< Set PpRxFifoLimit in register */
#define  GET_PP_RX_FIFO_LIMIT(reg)                          (((reg)>>8)&0x1Fu)            /**< Get PpRxFifoLimit from register */

// RegPpFifoCfg.regs.PpTxFifoLimit
#define  PP_TX_FIFO_LIMIT_GSHIFT                            0                             /**< Shift for group PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_GSIZE                             8                             /**< Size of group PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_GMASK                             0x000000FFu                   /**< Mask for group PpTxFifoLimit */

#define  PP_TX_FIFO_LIMIT_RSHIFT                            0                             /**< Shift for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_RMASK                             0x0000001Fu                   /**< Mask for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_RBMASK                            0x1Fu                         /**< Base mask for PpTxFifoLimit */
#define  PP_TX_FIFO_LIMIT_R(x)                              (((x)&0x1Fu)<<0)              /**< Set PpTxFifoLimit in register */
#define  GET_PP_TX_FIFO_LIMIT_R(reg)                        (((reg)>>0)&0x1Fu)            /**< Get PpTxFifoLimit from register */

// RegPpFifoCfg.regs.PpRxFifoLimit
#define  PP_RX_FIFO_LIMIT_GSHIFT                            8                             /**< Shift for group PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_GSIZE                             8                             /**< Size of group PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_GMASK                             0x0000FF00u                   /**< Mask for group PpRxFifoLimit */

#define  PP_RX_FIFO_LIMIT_RSHIFT                            0                             /**< Shift for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_RMASK                             0x0000001Fu                   /**< Mask for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_RBMASK                            0x1Fu                         /**< Base mask for PpRxFifoLimit */
#define  PP_RX_FIFO_LIMIT_R(x)                              (((x)&0x1Fu)<<0)              /**< Set PpRxFifoLimit in register */
#define  GET_PP_RX_FIFO_LIMIT_R(reg)                        (((reg)>>0)&0x1Fu)            /**< Get PpRxFifoLimit from register */
/** @} */


/**
 * @name RegPpFifoSts
 * @{
 */
// RegPpFifoSts.r32
#define  REG_PP_FIFO_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpFifoSts */
#define  REG_PP_FIFO_STS_MASK                               0x1F1F3F1Fu                   /**< Mask for RegPpFifoSts */

#define  PP_TX_FIFO_COUNT_SHIFT                             0                             /**< Shift for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_MASK                              0x0000001Fu                   /**< Mask for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_BMASK                             0x1Fu                         /**< Base mask for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT(x)                                (((x)&0x1Fu)<<0)              /**< Set PpTxFifoCount in register */
#define  GET_PP_TX_FIFO_COUNT(reg)                          (((reg)>>0)&0x1Fu)            /**< Get PpTxFifoCount from register */
#define  PP_RX_FIFO_COUNT_SHIFT                             8                             /**< Shift for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_MASK                              0x00003F00u                   /**< Mask for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_BMASK                             0x3Fu                         /**< Base mask for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT(x)                                (((x)&0x3Fu)<<8)              /**< Set PpRxFifoCount in register */
#define  GET_PP_RX_FIFO_COUNT(reg)                          (((reg)>>8)&0x3Fu)            /**< Get PpRxFifoCount from register */
#define  PP_TX_FIFO_EMPTY_SHIFT                             16                            /**< Shift for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY_MASK                              0x00010000u                   /**< Mask for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY_BMASK                             0x1u                          /**< Base mask for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY(x)                                (((x)&0x1u)<<16)              /**< Set PpTxFifoEmpty in register */
#define  GET_PP_TX_FIFO_EMPTY(reg)                          (((reg)>>16)&0x1u)            /**< Get PpTxFifoEmpty from register */
#define  PP_TX_FIFO_FULL_SHIFT                              17                            /**< Shift for PpTxFifoFull */
#define  PP_TX_FIFO_FULL_MASK                               0x00020000u                   /**< Mask for PpTxFifoFull */
#define  PP_TX_FIFO_FULL_BMASK                              0x1u                          /**< Base mask for PpTxFifoFull */
#define  PP_TX_FIFO_FULL(x)                                 (((x)&0x1u)<<17)              /**< Set PpTxFifoFull in register */
#define  GET_PP_TX_FIFO_FULL(reg)                           (((reg)>>17)&0x1u)            /**< Get PpTxFifoFull from register */
#define  PP_TX_FIFO_LIMIT_DET_SHIFT                         18                            /**< Shift for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET_MASK                          0x00040000u                   /**< Mask for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET_BMASK                         0x1u                          /**< Base mask for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET(x)                            (((x)&0x1u)<<18)              /**< Set PpTxFifoLimitDet in register */
#define  GET_PP_TX_FIFO_LIMIT_DET(reg)                      (((reg)>>18)&0x1u)            /**< Get PpTxFifoLimitDet from register */
#define  PP_TX_FIFO_UNDERFLOW_SHIFT                         19                            /**< Shift for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW_MASK                          0x00080000u                   /**< Mask for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW_BMASK                         0x1u                          /**< Base mask for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW(x)                            (((x)&0x1u)<<19)              /**< Set PpTxFifoUnderflow in register */
#define  GET_PP_TX_FIFO_UNDERFLOW(reg)                      (((reg)>>19)&0x1u)            /**< Get PpTxFifoUnderflow from register */
#define  PP_TX_FIFO_OVERFLOW_SHIFT                          20                            /**< Shift for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW_MASK                           0x00100000u                   /**< Mask for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW_BMASK                          0x1u                          /**< Base mask for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW(x)                             (((x)&0x1u)<<20)              /**< Set PpTxFifoOverflow in register */
#define  GET_PP_TX_FIFO_OVERFLOW(reg)                       (((reg)>>20)&0x1u)            /**< Get PpTxFifoOverflow from register */
#define  PP_RX_FIFO_EMPTY_SHIFT                             24                            /**< Shift for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY_MASK                              0x01000000u                   /**< Mask for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY_BMASK                             0x1u                          /**< Base mask for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY(x)                                (((x)&0x1u)<<24)              /**< Set PpRxFifoEmpty in register */
#define  GET_PP_RX_FIFO_EMPTY(reg)                          (((reg)>>24)&0x1u)            /**< Get PpRxFifoEmpty from register */
#define  PP_RX_FIFO_FULL_SHIFT                              25                            /**< Shift for PpRxFifoFull */
#define  PP_RX_FIFO_FULL_MASK                               0x02000000u                   /**< Mask for PpRxFifoFull */
#define  PP_RX_FIFO_FULL_BMASK                              0x1u                          /**< Base mask for PpRxFifoFull */
#define  PP_RX_FIFO_FULL(x)                                 (((x)&0x1u)<<25)              /**< Set PpRxFifoFull in register */
#define  GET_PP_RX_FIFO_FULL(reg)                           (((reg)>>25)&0x1u)            /**< Get PpRxFifoFull from register */
#define  PP_RX_FIFO_LIMIT_DET_SHIFT                         26                            /**< Shift for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET_MASK                          0x04000000u                   /**< Mask for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET_BMASK                         0x1u                          /**< Base mask for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET(x)                            (((x)&0x1u)<<26)              /**< Set PpRxFifoLimitDet in register */
#define  GET_PP_RX_FIFO_LIMIT_DET(reg)                      (((reg)>>26)&0x1u)            /**< Get PpRxFifoLimitDet from register */
#define  PP_RX_FIFO_UNDERFLOW_SHIFT                         27                            /**< Shift for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW_MASK                          0x08000000u                   /**< Mask for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW_BMASK                         0x1u                          /**< Base mask for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW(x)                            (((x)&0x1u)<<27)              /**< Set PpRxFifoUnderflow in register */
#define  GET_PP_RX_FIFO_UNDERFLOW(reg)                      (((reg)>>27)&0x1u)            /**< Get PpRxFifoUnderflow from register */
#define  PP_RX_FIFO_OVERFLOW_SHIFT                          28                            /**< Shift for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW_MASK                           0x10000000u                   /**< Mask for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW_BMASK                          0x1u                          /**< Base mask for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW(x)                             (((x)&0x1u)<<28)              /**< Set PpRxFifoOverflow in register */
#define  GET_PP_RX_FIFO_OVERFLOW(reg)                       (((reg)>>28)&0x1u)            /**< Get PpRxFifoOverflow from register */

// RegPpFifoSts.regs.PpTxFifoCount
#define  PP_TX_FIFO_COUNT_GSHIFT                            0                             /**< Shift for group PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_GSIZE                             8                             /**< Size of group PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_GMASK                             0x000000FFu                   /**< Mask for group PpTxFifoCount */

#define  PP_TX_FIFO_COUNT_RSHIFT                            0                             /**< Shift for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_RMASK                             0x0000001Fu                   /**< Mask for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_RBMASK                            0x1Fu                         /**< Base mask for PpTxFifoCount */
#define  PP_TX_FIFO_COUNT_R(x)                              (((x)&0x1Fu)<<0)              /**< Set PpTxFifoCount in register */
#define  GET_PP_TX_FIFO_COUNT_R(reg)                        (((reg)>>0)&0x1Fu)            /**< Get PpTxFifoCount from register */

// RegPpFifoSts.regs.PpRxFifoCount
#define  PP_RX_FIFO_COUNT_GSHIFT                            8                             /**< Shift for group PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_GSIZE                             8                             /**< Size of group PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_GMASK                             0x0000FF00u                   /**< Mask for group PpRxFifoCount */

#define  PP_RX_FIFO_COUNT_RSHIFT                            0                             /**< Shift for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_RMASK                             0x0000003Fu                   /**< Mask for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_RBMASK                            0x3Fu                         /**< Base mask for PpRxFifoCount */
#define  PP_RX_FIFO_COUNT_R(x)                              (((x)&0x3Fu)<<0)              /**< Set PpRxFifoCount in register */
#define  GET_PP_RX_FIFO_COUNT_R(reg)                        (((reg)>>0)&0x3Fu)            /**< Get PpRxFifoCount from register */

// RegPpFifoSts.regs.PpTxFifoStatus
#define  PP_TX_FIFO_STATUS_GSHIFT                           16                            /**< Shift for group PpTxFifoStatus */
#define  PP_TX_FIFO_STATUS_GSIZE                            8                             /**< Size of group PpTxFifoStatus */
#define  PP_TX_FIFO_STATUS_GMASK                            0x00FF0000u                   /**< Mask for group PpTxFifoStatus */

#define  PP_TX_FIFO_EMPTY_RSHIFT                            0                             /**< Shift for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY_RMASK                             0x01u                         /**< Mask for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY_RBMASK                            0x1u                          /**< Base mask for PpTxFifoEmpty */
#define  PP_TX_FIFO_EMPTY_R(x)                              (((x)&0x1u)<<0)               /**< Set PpTxFifoEmpty in register */
#define  GET_PP_TX_FIFO_EMPTY_R(reg)                        (((reg)>>0)&0x1u)             /**< Get PpTxFifoEmpty from register */
#define  PP_TX_FIFO_FULL_RSHIFT                             1                             /**< Shift for PpTxFifoFull */
#define  PP_TX_FIFO_FULL_RMASK                              0x02u                         /**< Mask for PpTxFifoFull */
#define  PP_TX_FIFO_FULL_RBMASK                             0x1u                          /**< Base mask for PpTxFifoFull */
#define  PP_TX_FIFO_FULL_R(x)                               (((x)&0x1u)<<1)               /**< Set PpTxFifoFull in register */
#define  GET_PP_TX_FIFO_FULL_R(reg)                         (((reg)>>1)&0x1u)             /**< Get PpTxFifoFull from register */
#define  PP_TX_FIFO_LIMIT_DET_RSHIFT                        2                             /**< Shift for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET_RMASK                         0x04u                         /**< Mask for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET_RBMASK                        0x1u                          /**< Base mask for PpTxFifoLimitDet */
#define  PP_TX_FIFO_LIMIT_DET_R(x)                          (((x)&0x1u)<<2)               /**< Set PpTxFifoLimitDet in register */
#define  GET_PP_TX_FIFO_LIMIT_DET_R(reg)                    (((reg)>>2)&0x1u)             /**< Get PpTxFifoLimitDet from register */
#define  PP_TX_FIFO_UNDERFLOW_RSHIFT                        3                             /**< Shift for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW_RMASK                         0x08u                         /**< Mask for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW_RBMASK                        0x1u                          /**< Base mask for PpTxFifoUnderflow */
#define  PP_TX_FIFO_UNDERFLOW_R(x)                          (((x)&0x1u)<<3)               /**< Set PpTxFifoUnderflow in register */
#define  GET_PP_TX_FIFO_UNDERFLOW_R(reg)                    (((reg)>>3)&0x1u)             /**< Get PpTxFifoUnderflow from register */
#define  PP_TX_FIFO_OVERFLOW_RSHIFT                         4                             /**< Shift for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW_RMASK                          0x10u                         /**< Mask for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW_RBMASK                         0x1u                          /**< Base mask for PpTxFifoOverflow */
#define  PP_TX_FIFO_OVERFLOW_R(x)                           (((x)&0x1u)<<4)               /**< Set PpTxFifoOverflow in register */
#define  GET_PP_TX_FIFO_OVERFLOW_R(reg)                     (((reg)>>4)&0x1u)             /**< Get PpTxFifoOverflow from register */

// RegPpFifoSts.regs.PpRxFifoStatus
#define  PP_RX_FIFO_STATUS_GSHIFT                           24                            /**< Shift for group PpRxFifoStatus */
#define  PP_RX_FIFO_STATUS_GSIZE                            8                             /**< Size of group PpRxFifoStatus */
#define  PP_RX_FIFO_STATUS_GMASK                            0xFF000000u                   /**< Mask for group PpRxFifoStatus */

#define  PP_RX_FIFO_EMPTY_RSHIFT                            0                             /**< Shift for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY_RMASK                             0x01u                         /**< Mask for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY_RBMASK                            0x1u                          /**< Base mask for PpRxFifoEmpty */
#define  PP_RX_FIFO_EMPTY_R(x)                              (((x)&0x1u)<<0)               /**< Set PpRxFifoEmpty in register */
#define  GET_PP_RX_FIFO_EMPTY_R(reg)                        (((reg)>>0)&0x1u)             /**< Get PpRxFifoEmpty from register */
#define  PP_RX_FIFO_FULL_RSHIFT                             1                             /**< Shift for PpRxFifoFull */
#define  PP_RX_FIFO_FULL_RMASK                              0x02u                         /**< Mask for PpRxFifoFull */
#define  PP_RX_FIFO_FULL_RBMASK                             0x1u                          /**< Base mask for PpRxFifoFull */
#define  PP_RX_FIFO_FULL_R(x)                               (((x)&0x1u)<<1)               /**< Set PpRxFifoFull in register */
#define  GET_PP_RX_FIFO_FULL_R(reg)                         (((reg)>>1)&0x1u)             /**< Get PpRxFifoFull from register */
#define  PP_RX_FIFO_LIMIT_DET_RSHIFT                        2                             /**< Shift for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET_RMASK                         0x04u                         /**< Mask for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET_RBMASK                        0x1u                          /**< Base mask for PpRxFifoLimitDet */
#define  PP_RX_FIFO_LIMIT_DET_R(x)                          (((x)&0x1u)<<2)               /**< Set PpRxFifoLimitDet in register */
#define  GET_PP_RX_FIFO_LIMIT_DET_R(reg)                    (((reg)>>2)&0x1u)             /**< Get PpRxFifoLimitDet from register */
#define  PP_RX_FIFO_UNDERFLOW_RSHIFT                        3                             /**< Shift for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW_RMASK                         0x08u                         /**< Mask for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW_RBMASK                        0x1u                          /**< Base mask for PpRxFifoUnderflow */
#define  PP_RX_FIFO_UNDERFLOW_R(x)                          (((x)&0x1u)<<3)               /**< Set PpRxFifoUnderflow in register */
#define  GET_PP_RX_FIFO_UNDERFLOW_R(reg)                    (((reg)>>3)&0x1u)             /**< Get PpRxFifoUnderflow from register */
#define  PP_RX_FIFO_OVERFLOW_RSHIFT                         4                             /**< Shift for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW_RMASK                          0x10u                         /**< Mask for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW_RBMASK                         0x1u                          /**< Base mask for PpRxFifoOverflow */
#define  PP_RX_FIFO_OVERFLOW_R(x)                           (((x)&0x1u)<<4)               /**< Set PpRxFifoOverflow in register */
#define  GET_PP_RX_FIFO_OVERFLOW_R(reg)                     (((reg)>>4)&0x1u)             /**< Get PpRxFifoOverflow from register */
/** @} */


/**
 * @name RegPpFifoCmd
 * @{
 */
// RegPpFifoCmd.r32
#define  REG_PP_FIFO_CMD_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpFifoCmd */
#define  REG_PP_FIFO_CMD_MASK                               0x00000003u                   /**< Mask for RegPpFifoCmd */

#define  PP_RX_FIFO_FLUSH_SHIFT                             0                             /**< Shift for PpRxFifoFlush */
#define  PP_RX_FIFO_FLUSH_MASK                              0x00000001u                   /**< Mask for PpRxFifoFlush */
#define  PP_RX_FIFO_FLUSH_BMASK                             0x1u                          /**< Base mask for PpRxFifoFlush */
#define  PP_RX_FIFO_FLUSH(x)                                (((x)&0x1u)<<0)               /**< Set PpRxFifoFlush in register */
#define  GET_PP_RX_FIFO_FLUSH(reg)                          (((reg)>>0)&0x1u)             /**< Get PpRxFifoFlush from register */
#define  PP_TX_FIFO_FLUSH_SHIFT                             1                             /**< Shift for PpTxFifoFlush */
#define  PP_TX_FIFO_FLUSH_MASK                              0x00000002u                   /**< Mask for PpTxFifoFlush */
#define  PP_TX_FIFO_FLUSH_BMASK                             0x1u                          /**< Base mask for PpTxFifoFlush */
#define  PP_TX_FIFO_FLUSH(x)                                (((x)&0x1u)<<1)               /**< Set PpTxFifoFlush in register */
#define  GET_PP_TX_FIFO_FLUSH(reg)                          (((reg)>>1)&0x1u)             /**< Get PpTxFifoFlush from register */
/** @} */


/**
 * @name RegPpAesKey0
 * @{
 */
// RegPpAesKey0.r32
#define  REG_PP_AES_KEY0_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpAesKey0 */
#define  REG_PP_AES_KEY0_MASK                               0xFFFFFFFFu                   /**< Mask for RegPpAesKey0 */

#define  PP_AES_KEY0_SHIFT                                  0                             /**< Shift for PpAesKey0 */
#define  PP_AES_KEY0_MASK                                   0xFFFFFFFFu                   /**< Mask for PpAesKey0 */
#define  PP_AES_KEY0_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PpAesKey0 */
#define  PP_AES_KEY0(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesKey0 in register */
#define  GET_PP_AES_KEY0(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesKey0 from register */
/** @} */


/**
 * @name RegPpAesKey1
 * @{
 */
// RegPpAesKey1.r32
#define  REG_PP_AES_KEY1_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpAesKey1 */
#define  REG_PP_AES_KEY1_MASK                               0xFFFFFFFFu                   /**< Mask for RegPpAesKey1 */

#define  PP_AES_KEY1_SHIFT                                  0                             /**< Shift for PpAesKey1 */
#define  PP_AES_KEY1_MASK                                   0xFFFFFFFFu                   /**< Mask for PpAesKey1 */
#define  PP_AES_KEY1_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PpAesKey1 */
#define  PP_AES_KEY1(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesKey1 in register */
#define  GET_PP_AES_KEY1(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesKey1 from register */
/** @} */


/**
 * @name RegPpAesKey2
 * @{
 */
// RegPpAesKey2.r32
#define  REG_PP_AES_KEY2_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpAesKey2 */
#define  REG_PP_AES_KEY2_MASK                               0xFFFFFFFFu                   /**< Mask for RegPpAesKey2 */

#define  PP_AES_KEY2_SHIFT                                  0                             /**< Shift for PpAesKey2 */
#define  PP_AES_KEY2_MASK                                   0xFFFFFFFFu                   /**< Mask for PpAesKey2 */
#define  PP_AES_KEY2_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PpAesKey2 */
#define  PP_AES_KEY2(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesKey2 in register */
#define  GET_PP_AES_KEY2(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesKey2 from register */
/** @} */


/**
 * @name RegPpAesKey3
 * @{
 */
// RegPpAesKey3.r32
#define  REG_PP_AES_KEY3_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPpAesKey3 */
#define  REG_PP_AES_KEY3_MASK                               0xFFFFFFFFu                   /**< Mask for RegPpAesKey3 */

#define  PP_AES_KEY3_SHIFT                                  0                             /**< Shift for PpAesKey3 */
#define  PP_AES_KEY3_MASK                                   0xFFFFFFFFu                   /**< Mask for PpAesKey3 */
#define  PP_AES_KEY3_BMASK                                  0xFFFFFFFFu                   /**< Base mask for PpAesKey3 */
#define  PP_AES_KEY3(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesKey3 in register */
#define  GET_PP_AES_KEY3(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesKey3 from register */
/** @} */


/**
 * @name RegPpAesCtrBlock0
 * @{
 */
// RegPpAesCtrBlock0.r32
#define  REG_PP_AES_CTR_BLOCK0_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpAesCtrBlock0 */
#define  REG_PP_AES_CTR_BLOCK0_MASK                         0xFFFFFFFFu                   /**< Mask for RegPpAesCtrBlock0 */

#define  PP_AES_CTR_BLOCK0_SHIFT                            0                             /**< Shift for PpAesCtrBlock0 */
#define  PP_AES_CTR_BLOCK0_MASK                             0xFFFFFFFFu                   /**< Mask for PpAesCtrBlock0 */
#define  PP_AES_CTR_BLOCK0_BMASK                            0xFFFFFFFFu                   /**< Base mask for PpAesCtrBlock0 */
#define  PP_AES_CTR_BLOCK0(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesCtrBlock0 in register */
#define  GET_PP_AES_CTR_BLOCK0(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesCtrBlock0 from register */
/** @} */


/**
 * @name RegPpAesCtrBlock1
 * @{
 */
// RegPpAesCtrBlock1.r32
#define  REG_PP_AES_CTR_BLOCK1_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpAesCtrBlock1 */
#define  REG_PP_AES_CTR_BLOCK1_MASK                         0xFFFFFFFFu                   /**< Mask for RegPpAesCtrBlock1 */

#define  PP_AES_CTR_BLOCK1_SHIFT                            0                             /**< Shift for PpAesCtrBlock1 */
#define  PP_AES_CTR_BLOCK1_MASK                             0xFFFFFFFFu                   /**< Mask for PpAesCtrBlock1 */
#define  PP_AES_CTR_BLOCK1_BMASK                            0xFFFFFFFFu                   /**< Base mask for PpAesCtrBlock1 */
#define  PP_AES_CTR_BLOCK1(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesCtrBlock1 in register */
#define  GET_PP_AES_CTR_BLOCK1(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesCtrBlock1 from register */
/** @} */


/**
 * @name RegPpAesCtrBlock2
 * @{
 */
// RegPpAesCtrBlock2.r32
#define  REG_PP_AES_CTR_BLOCK2_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpAesCtrBlock2 */
#define  REG_PP_AES_CTR_BLOCK2_MASK                         0xFFFFFFFFu                   /**< Mask for RegPpAesCtrBlock2 */

#define  PP_AES_CTR_BLOCK2_SHIFT                            0                             /**< Shift for PpAesCtrBlock2 */
#define  PP_AES_CTR_BLOCK2_MASK                             0xFFFFFFFFu                   /**< Mask for PpAesCtrBlock2 */
#define  PP_AES_CTR_BLOCK2_BMASK                            0xFFFFFFFFu                   /**< Base mask for PpAesCtrBlock2 */
#define  PP_AES_CTR_BLOCK2(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesCtrBlock2 in register */
#define  GET_PP_AES_CTR_BLOCK2(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesCtrBlock2 from register */
/** @} */


/**
 * @name RegPpAesCtrBlock3
 * @{
 */
// RegPpAesCtrBlock3.r32
#define  REG_PP_AES_CTR_BLOCK3_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpAesCtrBlock3 */
#define  REG_PP_AES_CTR_BLOCK3_MASK                         0xFFFFFFFFu                   /**< Mask for RegPpAesCtrBlock3 */

#define  PP_AES_CTR_BLOCK3_SHIFT                            0                             /**< Shift for PpAesCtrBlock3 */
#define  PP_AES_CTR_BLOCK3_MASK                             0xFFFFFFFFu                   /**< Mask for PpAesCtrBlock3 */
#define  PP_AES_CTR_BLOCK3_BMASK                            0xFFFFFFFFu                   /**< Base mask for PpAesCtrBlock3 */
#define  PP_AES_CTR_BLOCK3(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set PpAesCtrBlock3 in register */
#define  GET_PP_AES_CTR_BLOCK3(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get PpAesCtrBlock3 from register */
/** @} */


/**
 * @name RegPpAesCfg
 * @{
 */
// RegPpAesCfg.r32
#define  REG_PP_AES_CFG_RESET_VALUE                         0x00000000u                   /**< Reset value of RegPpAesCfg */
#define  REG_PP_AES_CFG_MASK                                0x0FFF070Fu                   /**< Mask for RegPpAesCfg */

#define  PP_AES_ENC_RX_EN_SHIFT                             0                             /**< Shift for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN_MASK                              0x00000001u                   /**< Mask for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN_BMASK                             0x1u                          /**< Base mask for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN(x)                                (((x)&0x1u)<<0)               /**< Set PpAesEncRxEn in register */
#define  GET_PP_AES_ENC_RX_EN(reg)                          (((reg)>>0)&0x1u)             /**< Get PpAesEncRxEn from register */
#define  PP_AES_ENC_TX_EN_SHIFT                             1                             /**< Shift for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN_MASK                              0x00000002u                   /**< Mask for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN_BMASK                             0x1u                          /**< Base mask for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN(x)                                (((x)&0x1u)<<1)               /**< Set PpAesEncTxEn in register */
#define  GET_PP_AES_ENC_TX_EN(reg)                          (((reg)>>1)&0x1u)             /**< Get PpAesEncTxEn from register */
#define  PP_AES_BLE_RX_MIC_EN_SHIFT                         2                             /**< Shift for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN_MASK                          0x00000004u                   /**< Mask for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN_BMASK                         0x1u                          /**< Base mask for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN(x)                            (((x)&0x1u)<<2)               /**< Set PpAesBleRxMicEn in register */
#define  GET_PP_AES_BLE_RX_MIC_EN(reg)                      (((reg)>>2)&0x1u)             /**< Get PpAesBleRxMicEn from register */
#define  PP_AES_BLE_TX_MIC_EN_SHIFT                         3                             /**< Shift for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN_MASK                          0x00000008u                   /**< Mask for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN_BMASK                         0x1u                          /**< Base mask for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN(x)                            (((x)&0x1u)<<3)               /**< Set PpAesBleTxMicEn in register */
#define  GET_PP_AES_BLE_TX_MIC_EN(reg)                      (((reg)>>3)&0x1u)             /**< Get PpAesBleTxMicEn from register */
#define  PP_AES_MODE_SHIFT                                  8                             /**< Shift for PpAesMode */
#define  PP_AES_MODE_MASK                                   0x00000700u                   /**< Mask for PpAesMode */
#define  PP_AES_MODE_BMASK                                  0x7u                          /**< Base mask for PpAesMode */
#define  PP_AES_MODE(x)                                     (((x)&0x7u)<<8)               /**< Set PpAesMode in register */
#define  GET_PP_AES_MODE(reg)                               (((reg)>>8)&0x7u)             /**< Get PpAesMode from register */
#define  PP_AES_PDU_START_SHIFT                             16                            /**< Shift for PpAesPduStart */
#define  PP_AES_PDU_START_MASK                              0x00FF0000u                   /**< Mask for PpAesPduStart */
#define  PP_AES_PDU_START_BMASK                             0xFFu                         /**< Base mask for PpAesPduStart */
#define  PP_AES_PDU_START(x)                                (((x)&0xFFu)<<16)             /**< Set PpAesPduStart in register */
#define  GET_PP_AES_PDU_START(reg)                          (((reg)>>16)&0xFFu)           /**< Get PpAesPduStart from register */
#define  PP_AES_CTR_SIZE_SHIFT                              24                            /**< Shift for PpAesCtrSize */
#define  PP_AES_CTR_SIZE_MASK                               0x0F000000u                   /**< Mask for PpAesCtrSize */
#define  PP_AES_CTR_SIZE_BMASK                              0xFu                          /**< Base mask for PpAesCtrSize */
#define  PP_AES_CTR_SIZE(x)                                 (((x)&0xFu)<<24)              /**< Set PpAesCtrSize in register */
#define  GET_PP_AES_CTR_SIZE(reg)                           (((reg)>>24)&0xFu)            /**< Get PpAesCtrSize from register */

// RegPpAesCfg.regs.PpAesEn
#define  PP_AES_EN_GSHIFT                                   0                             /**< Shift for group PpAesEn */
#define  PP_AES_EN_GSIZE                                    8                             /**< Size of group PpAesEn */
#define  PP_AES_EN_GMASK                                    0x000000FFu                   /**< Mask for group PpAesEn */

#define  PP_AES_ENC_RX_EN_RSHIFT                            0                             /**< Shift for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN_RMASK                             0x01u                         /**< Mask for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN_RBMASK                            0x1u                          /**< Base mask for PpAesEncRxEn */
#define  PP_AES_ENC_RX_EN_R(x)                              (((x)&0x1u)<<0)               /**< Set PpAesEncRxEn in register */
#define  GET_PP_AES_ENC_RX_EN_R(reg)                        (((reg)>>0)&0x1u)             /**< Get PpAesEncRxEn from register */
#define  PP_AES_ENC_TX_EN_RSHIFT                            1                             /**< Shift for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN_RMASK                             0x02u                         /**< Mask for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN_RBMASK                            0x1u                          /**< Base mask for PpAesEncTxEn */
#define  PP_AES_ENC_TX_EN_R(x)                              (((x)&0x1u)<<1)               /**< Set PpAesEncTxEn in register */
#define  GET_PP_AES_ENC_TX_EN_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PpAesEncTxEn from register */
#define  PP_AES_BLE_RX_MIC_EN_RSHIFT                        2                             /**< Shift for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN_RMASK                         0x04u                         /**< Mask for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN_RBMASK                        0x1u                          /**< Base mask for PpAesBleRxMicEn */
#define  PP_AES_BLE_RX_MIC_EN_R(x)                          (((x)&0x1u)<<2)               /**< Set PpAesBleRxMicEn in register */
#define  GET_PP_AES_BLE_RX_MIC_EN_R(reg)                    (((reg)>>2)&0x1u)             /**< Get PpAesBleRxMicEn from register */
#define  PP_AES_BLE_TX_MIC_EN_RSHIFT                        3                             /**< Shift for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN_RMASK                         0x08u                         /**< Mask for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN_RBMASK                        0x1u                          /**< Base mask for PpAesBleTxMicEn */
#define  PP_AES_BLE_TX_MIC_EN_R(x)                          (((x)&0x1u)<<3)               /**< Set PpAesBleTxMicEn in register */
#define  GET_PP_AES_BLE_TX_MIC_EN_R(reg)                    (((reg)>>3)&0x1u)             /**< Get PpAesBleTxMicEn from register */

// RegPpAesCfg.regs.PpAesMode
#define  PP_AES_MODE_GSHIFT                                 8                             /**< Shift for group PpAesMode */
#define  PP_AES_MODE_GSIZE                                  8                             /**< Size of group PpAesMode */
#define  PP_AES_MODE_GMASK                                  0x0000FF00u                   /**< Mask for group PpAesMode */

#define  PP_AES_MODE_RSHIFT                                 0                             /**< Shift for PpAesMode */
#define  PP_AES_MODE_RMASK                                  0x07u                         /**< Mask for PpAesMode */
#define  PP_AES_MODE_RBMASK                                 0x7u                          /**< Base mask for PpAesMode */
#define  PP_AES_MODE_R(x)                                   (((x)&0x7u)<<0)               /**< Set PpAesMode in register */
#define  GET_PP_AES_MODE_R(reg)                             (((reg)>>0)&0x7u)             /**< Get PpAesMode from register */

// RegPpAesCfg.regs.PpAesPduStart
#define  PP_AES_PDU_START_GSHIFT                            16                            /**< Shift for group PpAesPduStart */
#define  PP_AES_PDU_START_GSIZE                             8                             /**< Size of group PpAesPduStart */
#define  PP_AES_PDU_START_GMASK                             0x00FF0000u                   /**< Mask for group PpAesPduStart */

#define  PP_AES_PDU_START_RSHIFT                            0                             /**< Shift for PpAesPduStart */
#define  PP_AES_PDU_START_RMASK                             0xFFu                         /**< Mask for PpAesPduStart */
#define  PP_AES_PDU_START_RBMASK                            0xFFu                         /**< Base mask for PpAesPduStart */
#define  PP_AES_PDU_START_R(x)                              (((x)&0xFFu)<<0)              /**< Set PpAesPduStart in register */
#define  GET_PP_AES_PDU_START_R(reg)                        (((reg)>>0)&0xFFu)            /**< Get PpAesPduStart from register */

// RegPpAesCfg.regs.PpAesCtrSize
#define  PP_AES_CTR_SIZE_GSHIFT                             24                            /**< Shift for group PpAesCtrSize */
#define  PP_AES_CTR_SIZE_GSIZE                              8                             /**< Size of group PpAesCtrSize */
#define  PP_AES_CTR_SIZE_GMASK                              0xFF000000u                   /**< Mask for group PpAesCtrSize */

#define  PP_AES_CTR_SIZE_RSHIFT                             0                             /**< Shift for PpAesCtrSize */
#define  PP_AES_CTR_SIZE_RMASK                              0x0Fu                         /**< Mask for PpAesCtrSize */
#define  PP_AES_CTR_SIZE_RBMASK                             0xFu                          /**< Base mask for PpAesCtrSize */
#define  PP_AES_CTR_SIZE_R(x)                               (((x)&0xFu)<<0)               /**< Set PpAesCtrSize in register */
#define  GET_PP_AES_CTR_SIZE_R(reg)                         (((reg)>>0)&0xFu)             /**< Get PpAesCtrSize from register */
/** @} */


/**
 * @name RegPpAesSts
 * @{
 */
// RegPpAesSts.r32
#define  REG_PP_AES_STS_RESET_VALUE                         0x00000000u                   /**< Reset value of RegPpAesSts */
#define  REG_PP_AES_STS_MASK                                0x0000000Fu                   /**< Mask for RegPpAesSts */

#define  PP_AES_ENC_TX_DONE_SHIFT                           0                             /**< Shift for PpAesEncTxDone */
#define  PP_AES_ENC_TX_DONE_MASK                            0x00000001u                   /**< Mask for PpAesEncTxDone */
#define  PP_AES_ENC_TX_DONE_BMASK                           0x1u                          /**< Base mask for PpAesEncTxDone */
#define  PP_AES_ENC_TX_DONE(x)                              (((x)&0x1u)<<0)               /**< Set PpAesEncTxDone in register */
#define  GET_PP_AES_ENC_TX_DONE(reg)                        (((reg)>>0)&0x1u)             /**< Get PpAesEncTxDone from register */
#define  PP_AES_ENC_RX_DONE_SHIFT                           1                             /**< Shift for PpAesEncRxDone */
#define  PP_AES_ENC_RX_DONE_MASK                            0x00000002u                   /**< Mask for PpAesEncRxDone */
#define  PP_AES_ENC_RX_DONE_BMASK                           0x1u                          /**< Base mask for PpAesEncRxDone */
#define  PP_AES_ENC_RX_DONE(x)                              (((x)&0x1u)<<1)               /**< Set PpAesEncRxDone in register */
#define  GET_PP_AES_ENC_RX_DONE(reg)                        (((reg)>>1)&0x1u)             /**< Get PpAesEncRxDone from register */
#define  PP_AES_BLE_RX_MIC_OK_SHIFT                         2                             /**< Shift for PpAesBleRxMicOk */
#define  PP_AES_BLE_RX_MIC_OK_MASK                          0x00000004u                   /**< Mask for PpAesBleRxMicOk */
#define  PP_AES_BLE_RX_MIC_OK_BMASK                         0x1u                          /**< Base mask for PpAesBleRxMicOk */
#define  PP_AES_BLE_RX_MIC_OK(x)                            (((x)&0x1u)<<2)               /**< Set PpAesBleRxMicOk in register */
#define  GET_PP_AES_BLE_RX_MIC_OK(reg)                      (((reg)>>2)&0x1u)             /**< Get PpAesBleRxMicOk from register */
#define  PP_AES_BLE_RX_PDU_LEN_ERR_SHIFT                    3                             /**< Shift for PpAesBleRxPduLenErr */
#define  PP_AES_BLE_RX_PDU_LEN_ERR_MASK                     0x00000008u                   /**< Mask for PpAesBleRxPduLenErr */
#define  PP_AES_BLE_RX_PDU_LEN_ERR_BMASK                    0x1u                          /**< Base mask for PpAesBleRxPduLenErr */
#define  PP_AES_BLE_RX_PDU_LEN_ERR(x)                       (((x)&0x1u)<<3)               /**< Set PpAesBleRxPduLenErr in register */
#define  GET_PP_AES_BLE_RX_PDU_LEN_ERR(reg)                 (((reg)>>3)&0x1u)             /**< Get PpAesBleRxPduLenErr from register */
/** @} */


/**
 * @name RegPpBleCteCfg
 * @{
 */
// RegPpBleCteCfg.r32
#define  REG_PP_BLE_CTE_CFG_RESET_VALUE                     0x0300000Cu                   /**< Reset value of RegPpBleCteCfg */
#define  REG_PP_BLE_CTE_CFG_MASK                            0x033FFF1Fu                   /**< Mask for RegPpBleCteCfg */

#define  PP_BLE_CTE_RX_EN_SHIFT                             0                             /**< Shift for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN_MASK                              0x00000001u                   /**< Mask for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN_BMASK                             0x1u                          /**< Base mask for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN(x)                                (((x)&0x1u)<<0)               /**< Set PpBleCteRxEn in register */
#define  GET_PP_BLE_CTE_RX_EN(reg)                          (((reg)>>0)&0x1u)             /**< Get PpBleCteRxEn from register */
#define  PP_BLE_CTE_TX_EN_SHIFT                             1                             /**< Shift for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN_MASK                              0x00000002u                   /**< Mask for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN_BMASK                             0x1u                          /**< Base mask for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN(x)                                (((x)&0x1u)<<1)               /**< Set PpBleCteTxEn in register */
#define  GET_PP_BLE_CTE_TX_EN(reg)                          (((reg)>>1)&0x1u)             /**< Get PpBleCteTxEn from register */
#define  PP_BLE_CTE_PDU_TYPE_SHIFT                          2                             /**< Shift for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE_MASK                           0x00000004u                   /**< Mask for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE_BMASK                          0x1u                          /**< Base mask for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE(x)                             (((x)&0x1u)<<2)               /**< Set PpBleCtePduType in register */
#define  GET_PP_BLE_CTE_PDU_TYPE(reg)                       (((reg)>>2)&0x1u)             /**< Get PpBleCtePduType from register */
#define  PP_BLE_CTE_IGNORE_CRC_SHIFT                        3                             /**< Shift for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC_MASK                         0x00000008u                   /**< Mask for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC_BMASK                        0x1u                          /**< Base mask for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC(x)                           (((x)&0x1u)<<3)               /**< Set PpBleCteIgnoreCrc in register */
#define  GET_PP_BLE_CTE_IGNORE_CRC(reg)                     (((reg)>>3)&0x1u)             /**< Get PpBleCteIgnoreCrc from register */
#define  PP_BLE_CTE_POS_MANUAL_SHIFT                        4                             /**< Shift for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL_MASK                         0x00000010u                   /**< Mask for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL_BMASK                        0x1u                          /**< Base mask for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL(x)                           (((x)&0x1u)<<4)               /**< Set PpBleCtePosManual in register */
#define  GET_PP_BLE_CTE_POS_MANUAL(reg)                     (((reg)>>4)&0x1u)             /**< Get PpBleCtePosManual from register */
#define  PP_BLE_CTE_CP_BIT_POS_SHIFT                        8                             /**< Shift for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_MASK                         0x0000FF00u                   /**< Mask for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_BMASK                        0xFFu                         /**< Base mask for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS(x)                           (((x)&0xFFu)<<8)              /**< Set PpBleCteCpBitPos in register */
#define  GET_PP_BLE_CTE_CP_BIT_POS(reg)                     (((reg)>>8)&0xFFu)            /**< Get PpBleCteCpBitPos from register */
#define  PP_BLE_CTE_CTE_INFO_POS_SHIFT                      16                            /**< Shift for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_MASK                       0x003F0000u                   /**< Mask for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_BMASK                      0x3Fu                         /**< Base mask for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS(x)                         (((x)&0x3Fu)<<16)             /**< Set PpBleCteCteInfoPos in register */
#define  GET_PP_BLE_CTE_CTE_INFO_POS(reg)                   (((reg)>>16)&0x3Fu)           /**< Get PpBleCteCteInfoPos from register */
#define  PP_BLE_CTE_IQ_ORDER_SHIFT                          24                            /**< Shift for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER_MASK                           0x01000000u                   /**< Mask for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER_BMASK                          0x1u                          /**< Base mask for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER(x)                             (((x)&0x1u)<<24)              /**< Set PpBleCteIqOrder in register */
#define  GET_PP_BLE_CTE_IQ_ORDER(reg)                       (((reg)>>24)&0x1u)            /**< Get PpBleCteIqOrder from register */
#define  PP_BLE_CTE_AOA_PERIOD_SHIFT                        25                            /**< Shift for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD_MASK                         0x02000000u                   /**< Mask for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD_BMASK                        0x1u                          /**< Base mask for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD(x)                           (((x)&0x1u)<<25)              /**< Set PpBleCteAoaPeriod in register */
#define  GET_PP_BLE_CTE_AOA_PERIOD(reg)                     (((reg)>>25)&0x1u)            /**< Get PpBleCteAoaPeriod from register */

// RegPpBleCteCfg.regs.PpBleCteCfg
#define  PP_BLE_CTE_CFG_GSHIFT                              0                             /**< Shift for group PpBleCteCfg */
#define  PP_BLE_CTE_CFG_GSIZE                               8                             /**< Size of group PpBleCteCfg */
#define  PP_BLE_CTE_CFG_GMASK                               0x000000FFu                   /**< Mask for group PpBleCteCfg */

#define  PP_BLE_CTE_RX_EN_RSHIFT                            0                             /**< Shift for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN_RMASK                             0x01u                         /**< Mask for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN_RBMASK                            0x1u                          /**< Base mask for PpBleCteRxEn */
#define  PP_BLE_CTE_RX_EN_R(x)                              (((x)&0x1u)<<0)               /**< Set PpBleCteRxEn in register */
#define  GET_PP_BLE_CTE_RX_EN_R(reg)                        (((reg)>>0)&0x1u)             /**< Get PpBleCteRxEn from register */
#define  PP_BLE_CTE_TX_EN_RSHIFT                            1                             /**< Shift for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN_RMASK                             0x02u                         /**< Mask for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN_RBMASK                            0x1u                          /**< Base mask for PpBleCteTxEn */
#define  PP_BLE_CTE_TX_EN_R(x)                              (((x)&0x1u)<<1)               /**< Set PpBleCteTxEn in register */
#define  GET_PP_BLE_CTE_TX_EN_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PpBleCteTxEn from register */
#define  PP_BLE_CTE_PDU_TYPE_RSHIFT                         2                             /**< Shift for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE_RMASK                          0x04u                         /**< Mask for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE_RBMASK                         0x1u                          /**< Base mask for PpBleCtePduType */
#define  PP_BLE_CTE_PDU_TYPE_R(x)                           (((x)&0x1u)<<2)               /**< Set PpBleCtePduType in register */
#define  GET_PP_BLE_CTE_PDU_TYPE_R(reg)                     (((reg)>>2)&0x1u)             /**< Get PpBleCtePduType from register */
#define  PP_BLE_CTE_IGNORE_CRC_RSHIFT                       3                             /**< Shift for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC_RMASK                        0x08u                         /**< Mask for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC_RBMASK                       0x1u                          /**< Base mask for PpBleCteIgnoreCrc */
#define  PP_BLE_CTE_IGNORE_CRC_R(x)                         (((x)&0x1u)<<3)               /**< Set PpBleCteIgnoreCrc in register */
#define  GET_PP_BLE_CTE_IGNORE_CRC_R(reg)                   (((reg)>>3)&0x1u)             /**< Get PpBleCteIgnoreCrc from register */
#define  PP_BLE_CTE_POS_MANUAL_RSHIFT                       4                             /**< Shift for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL_RMASK                        0x10u                         /**< Mask for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL_RBMASK                       0x1u                          /**< Base mask for PpBleCtePosManual */
#define  PP_BLE_CTE_POS_MANUAL_R(x)                         (((x)&0x1u)<<4)               /**< Set PpBleCtePosManual in register */
#define  GET_PP_BLE_CTE_POS_MANUAL_R(reg)                   (((reg)>>4)&0x1u)             /**< Get PpBleCtePosManual from register */

// RegPpBleCteCfg.regs.PpBleCteCpBitPos
#define  PP_BLE_CTE_CP_BIT_POS_GSHIFT                       8                             /**< Shift for group PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_GSIZE                        8                             /**< Size of group PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_GMASK                        0x0000FF00u                   /**< Mask for group PpBleCteCpBitPos */

#define  PP_BLE_CTE_CP_BIT_POS_RSHIFT                       0                             /**< Shift for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_RMASK                        0xFFu                         /**< Mask for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_RBMASK                       0xFFu                         /**< Base mask for PpBleCteCpBitPos */
#define  PP_BLE_CTE_CP_BIT_POS_R(x)                         (((x)&0xFFu)<<0)              /**< Set PpBleCteCpBitPos in register */
#define  GET_PP_BLE_CTE_CP_BIT_POS_R(reg)                   (((reg)>>0)&0xFFu)            /**< Get PpBleCteCpBitPos from register */

// RegPpBleCteCfg.regs.PpBleCteCteInfoPos
#define  PP_BLE_CTE_CTE_INFO_POS_GSHIFT                     16                            /**< Shift for group PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_GSIZE                      8                             /**< Size of group PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_GMASK                      0x00FF0000u                   /**< Mask for group PpBleCteCteInfoPos */

#define  PP_BLE_CTE_CTE_INFO_POS_RSHIFT                     0                             /**< Shift for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_RMASK                      0x3Fu                         /**< Mask for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_RBMASK                     0x3Fu                         /**< Base mask for PpBleCteCteInfoPos */
#define  PP_BLE_CTE_CTE_INFO_POS_R(x)                       (((x)&0x3Fu)<<0)              /**< Set PpBleCteCteInfoPos in register */
#define  GET_PP_BLE_CTE_CTE_INFO_POS_R(reg)                 (((reg)>>0)&0x3Fu)            /**< Get PpBleCteCteInfoPos from register */
#define  PP_BLE_CTE_IQ_ORDER_RSHIFT                         8                             /**< Shift for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER_RMASK                          0x100u                        /**< Mask for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER_RBMASK                         0x1u                          /**< Base mask for PpBleCteIqOrder */
#define  PP_BLE_CTE_IQ_ORDER_R(x)                           (((x)&0x1u)<<8)               /**< Set PpBleCteIqOrder in register */
#define  GET_PP_BLE_CTE_IQ_ORDER_R(reg)                     (((reg)>>8)&0x1u)             /**< Get PpBleCteIqOrder from register */
#define  PP_BLE_CTE_AOA_PERIOD_RSHIFT                       9                             /**< Shift for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD_RMASK                        0x200u                        /**< Mask for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD_RBMASK                       0x1u                          /**< Base mask for PpBleCteAoaPeriod */
#define  PP_BLE_CTE_AOA_PERIOD_R(x)                         (((x)&0x1u)<<9)               /**< Set PpBleCteAoaPeriod in register */
#define  GET_PP_BLE_CTE_AOA_PERIOD_R(reg)                   (((reg)>>9)&0x1u)             /**< Get PpBleCteAoaPeriod from register */
/** @} */


/**
 * @name RegPpBleCteRxTim
 * @{
 */
// RegPpBleCteRxTim.r32
#define  REG_PP_BLE_CTE_RX_TIM_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpBleCteRxTim */
#define  REG_PP_BLE_CTE_RX_TIM_MASK                         0x1FFF1FFFu                   /**< Mask for RegPpBleCteRxTim */

#define  PP_BLE_CTE_RX_TIM_SWITCH_SHIFT                     0                             /**< Shift for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_MASK                      0x00001FFFu                   /**< Mask for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_BMASK                     0x1FFFu                       /**< Base mask for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH(x)                        (((x)&0x1FFFu)<<0)            /**< Set PpBleCteRxTimSwitch in register */
#define  GET_PP_BLE_CTE_RX_TIM_SWITCH(reg)                  (((reg)>>0)&0x1FFFu)          /**< Get PpBleCteRxTimSwitch from register */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_SHIFT                     16                            /**< Shift for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_MASK                      0x1FFF0000u                   /**< Mask for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_BMASK                     0x1FFFu                       /**< Base mask for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE(x)                        (((x)&0x1FFFu)<<16)           /**< Set PpBleCteRxTimSample in register */
#define  GET_PP_BLE_CTE_RX_TIM_SAMPLE(reg)                  (((reg)>>16)&0x1FFFu)         /**< Get PpBleCteRxTimSample from register */

// RegPpBleCteRxTim.regs.PpBleCteRxTimSwitch
#define  PP_BLE_CTE_RX_TIM_SWITCH_GSHIFT                    0                             /**< Shift for group PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_GSIZE                     16                            /**< Size of group PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_GMASK                     0x0000FFFFu                   /**< Mask for group PpBleCteRxTimSwitch */

#define  PP_BLE_CTE_RX_TIM_SWITCH_RSHIFT                    0                             /**< Shift for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_RMASK                     0x00001FFFu                   /**< Mask for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_RBMASK                    0x1FFFu                       /**< Base mask for PpBleCteRxTimSwitch */
#define  PP_BLE_CTE_RX_TIM_SWITCH_R(x)                      (((x)&0x1FFFu)<<0)            /**< Set PpBleCteRxTimSwitch in register */
#define  GET_PP_BLE_CTE_RX_TIM_SWITCH_R(reg)                (((reg)>>0)&0x1FFFu)          /**< Get PpBleCteRxTimSwitch from register */

// RegPpBleCteRxTim.regs.PpBleCteRxTimSample
#define  PP_BLE_CTE_RX_TIM_SAMPLE_GSHIFT                    16                            /**< Shift for group PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_GSIZE                     16                            /**< Size of group PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_GMASK                     0xFFFF0000u                   /**< Mask for group PpBleCteRxTimSample */

#define  PP_BLE_CTE_RX_TIM_SAMPLE_RSHIFT                    0                             /**< Shift for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_RMASK                     0x00001FFFu                   /**< Mask for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_RBMASK                    0x1FFFu                       /**< Base mask for PpBleCteRxTimSample */
#define  PP_BLE_CTE_RX_TIM_SAMPLE_R(x)                      (((x)&0x1FFFu)<<0)            /**< Set PpBleCteRxTimSample in register */
#define  GET_PP_BLE_CTE_RX_TIM_SAMPLE_R(reg)                (((reg)>>0)&0x1FFFu)          /**< Get PpBleCteRxTimSample from register */
/** @} */


/**
 * @name RegPpBleCteTxTim
 * @{
 */
// RegPpBleCteTxTim.r32
#define  REG_PP_BLE_CTE_TX_TIM_RESET_VALUE                  0x00000000u                   /**< Reset value of RegPpBleCteTxTim */
#define  REG_PP_BLE_CTE_TX_TIM_MASK                         0x00001FFFu                   /**< Mask for RegPpBleCteTxTim */

#define  PP_BLE_CTE_TX_TIM_SWITCH_SHIFT                     0                             /**< Shift for PpBleCteTxTimSwitch */
#define  PP_BLE_CTE_TX_TIM_SWITCH_MASK                      0x00001FFFu                   /**< Mask for PpBleCteTxTimSwitch */
#define  PP_BLE_CTE_TX_TIM_SWITCH_BMASK                     0x1FFFu                       /**< Base mask for PpBleCteTxTimSwitch */
#define  PP_BLE_CTE_TX_TIM_SWITCH(x)                        (((x)&0x1FFFu)<<0)            /**< Set PpBleCteTxTimSwitch in register */
#define  GET_PP_BLE_CTE_TX_TIM_SWITCH(reg)                  (((reg)>>0)&0x1FFFu)          /**< Get PpBleCteTxTimSwitch from register */
/** @} */


/**
 * @name RegPpBleCteSts
 * @{
 */
// RegPpBleCteSts.r32
#define  REG_PP_BLE_CTE_STS_RESET_VALUE                     0x00000000u                   /**< Reset value of RegPpBleCteSts */
#define  REG_PP_BLE_CTE_STS_MASK                            0x000000FFu                   /**< Mask for RegPpBleCteSts */

#define  PP_BLE_CTE_SAMPLE_COUNT_SHIFT                      0                             /**< Shift for PpBleCteSampleCount */
#define  PP_BLE_CTE_SAMPLE_COUNT_MASK                       0x000000FFu                   /**< Mask for PpBleCteSampleCount */
#define  PP_BLE_CTE_SAMPLE_COUNT_BMASK                      0xFFu                         /**< Base mask for PpBleCteSampleCount */
#define  PP_BLE_CTE_SAMPLE_COUNT(x)                         (((x)&0xFFu)<<0)              /**< Set PpBleCteSampleCount in register */
#define  GET_PP_BLE_CTE_SAMPLE_COUNT(reg)                   (((reg)>>0)&0xFFu)            /**< Get PpBleCteSampleCount from register */
/** @} */


/**
 * @name RegPpRfTst
 * @{
 */
// RegPpRfTst.r32
#define  REG_PP_RF_TST_RESET_VALUE                          0x00000000u                   /**< Reset value of RegPpRfTst */
#define  REG_PP_RF_TST_MASK                                 0x0001FFFFu                   /**< Mask for RegPpRfTst */

#define  PP_RF_TX_TST_PATTERN_SHIFT                         0                             /**< Shift for PpRfTxTstPattern */
#define  PP_RF_TX_TST_PATTERN_MASK                          0x0000FFFFu                   /**< Mask for PpRfTxTstPattern */
#define  PP_RF_TX_TST_PATTERN_BMASK                         0xFFFFu                       /**< Base mask for PpRfTxTstPattern */
#define  PP_RF_TX_TST_PATTERN(x)                            (((x)&0xFFFFu)<<0)            /**< Set PpRfTxTstPattern in register */
#define  GET_PP_RF_TX_TST_PATTERN(reg)                      (((reg)>>0)&0xFFFFu)          /**< Get PpRfTxTstPattern from register */
#define  PP_RF_TX_TST_EN_SHIFT                              16                            /**< Shift for PpRfTxTstEn */
#define  PP_RF_TX_TST_EN_MASK                               0x00010000u                   /**< Mask for PpRfTxTstEn */
#define  PP_RF_TX_TST_EN_BMASK                              0x1u                          /**< Base mask for PpRfTxTstEn */
#define  PP_RF_TX_TST_EN(x)                                 (((x)&0x1u)<<16)              /**< Set PpRfTxTstEn in register */
#define  GET_PP_RF_TX_TST_EN(reg)                           (((reg)>>16)&0x1u)            /**< Get PpRfTxTstEn from register */
/** @} */



/** @} End of group PckProc_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_PCK_PROC_H */
