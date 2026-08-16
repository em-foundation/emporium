////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_radio.h
///
/// @project    T9305
///
/// @brief      Radio register and bit field definitions
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

#ifndef _T9305_RADIO_H
#define _T9305_RADIO_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup Radio_Registers Rf radio - registers
 * @{
 ******************************************************************************/


/** Device_Id */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDeviceId_t;


/** Version_Id */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfVersionId_t;


/** Mode_Cfg_Rx1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfModeCfgRx1_t;


/** Mode_Cfg_Tx1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfModeCfgTx1_t;


/** Mode_Cfg_Tx2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfModeCfgTx2_t;


/** Mode_Cfg_Txrx */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfModeCfgTxrx_t;


/** Burst_Cfg_Txrx */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfBurstCfgTxrx_t;


/** Debug_Txrx1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDebugTxrx1_t;


/** Zb_Pdet_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfZbPdetCfg_t;


/** Rssi */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRssi_t;


/** Rssi_Start */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRssiStart_t;


/** Rssi_Stop */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRssiStop_t;


/** Rssi_Filt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRssiFilt_t;


/** Lr_Freq_Corr_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLrFreqCorrCfg_t;


/** Lr_Tim_Rec_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLrTimRecCfg_t;


/** Zb_Freq_Corr_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfZbFreqCorrCfg_t;


/** Zb_Thr_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfZbThrCfg_t;


/** Mode_Cfg_Rx2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfModeCfgRx2_t;


/** Txrx_Dbg1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTxrxDbg1_t;


/** Txrx_Dbg2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTxrxDbg2_t;


/** Txrx_Dbg3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTxrxDbg3_t;


/** Txrx_Dbg4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTxrxDbg4_t;


/** Dsm_Frac1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDsmFrac1_t;


/** Agc_Thrshld1_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld11M_t;


/** Agc_Thrshld2_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld21M_t;


/** Agc_Thrshld3_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld31M_t;


/** Agc_Thrshld4_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld41M_t;


/** Agc_Thrshld5_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld51M_t;


/** Agc_Thrshld1_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld12M_t;


/** Agc_Thrshld2_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld22M_t;


/** Agc_Thrshld3_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld32M_t;


/** Agc_Thrshld4_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld42M_t;


/** Agc_Thrshld5_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcThrshld52M_t;


/** Rx_Grp_Dly_1M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGrpDly1M_t;


/** Rx_Gain_Vhg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainVhg_t;


/** Rx_Gain_Hg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainHg_t;


/** Rx_Gain_Ihg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainIhg_t;


/** Rx_Gain_Mg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainMg_t;


/** Rx_Gain_Lg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainLg_t;


/** Rx_Gain_Vlg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGainVlg_t;


/** Adc_Rbk_I */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAdcRbkI_t;


/** Adc_Rbk_Q */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAdcRbkQ_t;


/** Rx_Grp_Dly_2M */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRxGrpDly2M_t;


/** Tim_Rec_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTimRecCfg_t;


/** Freq_Corr_Cfg1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfFreqCorrCfg1_t;


/** Freq_Corr_Cfg2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfFreqCorrCfg2_t;


/** Tim_Align */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTimAlign_t;


/** Bypass_Filt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfBypassFilt_t;


/** Agc_Rssi_Rdbk */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAgcRssiRdbk_t;


/** Tim_Restart_Dly */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTimRestartDly_t;


/** Cal_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCalOwCtrl_t;


/** Cal_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCalOwVal_t;


/** Txrx_Cb_Cal_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfTxrxCbCalCtrl_t;


/** Idle_Tx_Ss1_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs1Strt_t;


/** Idle_Tx_Ss2_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs2Strt_t;


/** Idle_Tx_Ss3_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs3Strt_t;


/** Idle_Tx_Ss4_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs4Strt_t;


/** Idle_Tx_Ss5_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs5Strt_t;


/** Idle_Tx_Ss6_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs6Strt_t;


/** Idle_Tx_Ss7_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs7Strt_t;


/** Idle_Rx_Ss1_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs1Strt_t;


/** Idle_Rx_Ss2_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs2Strt_t;


/** Idle_Rx_Ss3_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs3Strt_t;


/** Idle_Rx_Ss4_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs4Strt_t;


/** Idle_Rx_Ss5_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs5Strt_t;


/** Idle_Rx_Ss6_Strt */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs6Strt_t;


/** Idle_Tx_Ss1_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs1StrtCb_t;


/** Idle_Tx_Ss2_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs2StrtCb_t;


/** Idle_Tx_Ss3_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs3StrtCb_t;


/** Idle_Tx_Ss4_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs4StrtCb_t;


/** Idle_Tx_Ss5_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs5StrtCb_t;


/** Idle_Tx_Ss6_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs6StrtCb_t;


/** Idle_Rx_Ss1_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs1StrtCb_t;


/** Idle_Rx_Ss2_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs2StrtCb_t;


/** Idle_Rx_Ss3_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs3StrtCb_t;


/** Idle_Rx_Ss4_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs4StrtCb_t;


/** Idle_Rx_Ss5_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs5StrtCb_t;


/** Idle_Rx_Ss6_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleRxSs6StrtCb_t;


/** Idle_Tx_Ss7_Strt_Cb */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfIdleTxSs7StrtCb_t;


/** Locd_Trig */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLocdTrig_t;


/** Fcal_Rdbk */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfFcalRdbk_t;


/** Fcal_Dbg2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfFcalDbg2_t;


/** Rccal_Dbg1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRccalDbg1_t;


/** Rccal_Dbg2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRccalDbg2_t;


/** Rccal_Rdbk */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRccalRdbk_t;


/** Dcoc_Bypass_Adc */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocBypassAdc_t;


/** Dcoc_Bypass_Dac */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocBypassDac_t;


/** Dcoc_Dbg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocDbg_t;


/** Dcoc_Lna_Offset */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocLnaOffset_t;


/** Dcoc_Cbpf_Offset */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocCbpfOffset_t;


/** Dcoc_Rdbk1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocRdbk1_t;


/** Dcoc_Rdbk2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocRdbk2_t;


/** Dcoc_Rdbk3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcocRdbk3_t;


/** Ldot_Dbg1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotDbg1_t;


/** Ldot_Dbg2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotDbg2_t;


/** Ldot_Dbg3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotDbg3_t;


/** Ldot_Dbg4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotDbg4_t;


/** Ldot_Rdbk1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotRdbk1_t;


/** Ldot_Rdbk2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotRdbk2_t;


/** Ldot_Rdbk3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotRdbk3_t;


/** Hpmc_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcCfg_t;


/** Hpmc_Debug */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcDebug_t;


/** Hpmc_Rdbk1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcRdbk1_t;


/** Hpmc_Rdbk2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcRdbk2_t;


/** Hpmc_Rdbk3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcRdbk3_t;


/** Hpmc_Rdbk4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfHpmcRdbk4_t;


/** Locd_Cfg */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLocdCfg_t;


/** Locd_Rdbk */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLocdRdbk_t;


/** Locd_Trgt_Cnt11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLocdTrgtCnt11_t;


/** Locd_Trgt_Cnt12 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLocdTrgtCnt12_t;


/** Cal_Done_Rdbk */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCalDoneRdbk_t;


/** Adc_Dac_Dft1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAdcDacDft1_t;


/** Adc_Dac_Dft2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfAdcDacDft2_t;


/** Dft_Mux */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDftMux_t;


/** Diag */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDiag_t;


/** Bypass_Clk_Gating */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfBypassClkGating_t;


/** Sft_Rst */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfSftRst_t;


/** Ldo1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdo1_t;


/** Ldo_Bg_Clk_Aux_Drv */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdoBgClkAuxDrv_t;


/** Lnm_Pa */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLnmPa_t;


/** Cbpf_Adc */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCbpfAdc_t;


/** Pd_Txdac */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfPdTxdac_t;


/** Vco_Ldotrim */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfVcoLdotrim_t;


/** Reg_Sparelv1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRegSparelv1_t;


/** Ldo_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdoOwCtrl_t;


/** Ldo_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdoOwVal_t;


/** Bg_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfBgOwCtrl_t;


/** Bg_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfBgOwVal_t;


/** Ldotrim_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotrimOwCtrl_t;


/** Ldotrim_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLdotrimOwVal_t;


/** Rccal_Ow_Ctrl_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRccalOwCtrlVal_t;


/** Xo_Ow_Ctrl_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoOwCtrlVal_t;


/** Lnm_Pa_Ow_Ctrl_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLnmPaOwCtrlVal_t;


/** Lnm_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfLnmOwVal_t;


/** Pa_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfPaOwVal_t;


/** Cbpf_Adc_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCbpfAdcOwCtrl_t;


/** Cbpf_Adc_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfCbpfAdcOwVal_t;


/** Pd_Divn_Fcal_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfPdDivnFcalOwCtrl_t;


/** Pd_Divn_Fcal_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfPdDivnFcalOwVal_t;


/** Vco_Lopath_Dac_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfVcoLopathDacOwCtrl_t;


/** Vco_Lopath_Dac_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfVcoLopathDacOwVal_t;


/** Seq_Sparelv_Ow_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfSeqSparelvOwCtrl_t;


/** Seq_Sparelv_Ow_Val */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfSeqSparelvOwVal_t;


/** Xo_Seq */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoSeq_t;


/** Xo_Debug */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoDebug_t;


/** Xo_Seq_Dig */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoSeqDig_t;


/** Xo_Debug_Dig */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoDebugDig_t;


/** Reg_Sparertc_Dig */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRegSparertcDig_t;


/** Rcosc_Dig */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRcoscDig_t;


/** Reg_Sparertc */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRegSparertc_t;


/** Xo_Seq_Read */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoSeqRead_t;


/** Xo_Debug_Read */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoDebugRead_t;


/** Reg_Sparertc_Read */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRegSparertcRead_t;


/** Xo_Dig_Read */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXoDigRead_t;


/** Dcdc_Status_Core */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcStatusCore_t;


/** Dcdc_Status_Fsm */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcStatusFsm_t;


/** Rcosc */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRcosc_t;


/** Dcdc_Core */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcCore_t;


/** Dcdc_Timer */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcTimer_t;


/** Dcdc_Ref */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcRef_t;


/** Dcdc_Test */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcTest_t;


/** Dcdc_Diag */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDcdcDiag_t;


/** Xo32K */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfXo32K_t;


/** Ro32K */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfRo32K_t;


/** Diag_Misctop */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDiagMisctop_t;


/** Mem_Addr */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfMemAddr_t;


/** Mem_Data_Ipath */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfMemDataIpath_t;


/** Dbg_Ctrl */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfDbgCtrl_t;


/** Start_Addr */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfStartAddr_t;


/** Stop_Addr */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfStopAddr_t;


/** Mem_Data_Qpath */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfMemDataQpath_t;


/** Strobe_Delay */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRfStrobeDelay_t;

/** @} end of group Radio_Regs */



/***************************************************************************//**
 * @defgroup Radio_RegMap Rf radio
 * @{
 ******************************************************************************/
typedef struct
{
    __I   RegRfDeviceId_t                                   RegRfDeviceId;                /**< Device_Id */
    __I   RegRfVersionId_t                                  RegRfVersionId;               /**< Version_Id */
          reg32_t  RESERVED0;                                                             /**< RESERVED */
          reg32_t  RESERVED1;                                                             /**< RESERVED */
          reg32_t  RESERVED2;                                                             /**< RESERVED */
          reg32_t  RESERVED3;                                                             /**< RESERVED */
          reg32_t  RESERVED4;                                                             /**< RESERVED */
          reg32_t  RESERVED5;                                                             /**< RESERVED */
          reg32_t  RESERVED6;                                                             /**< RESERVED */
          reg32_t  RESERVED7;                                                             /**< RESERVED */
          reg32_t  RESERVED8;                                                             /**< RESERVED */
          reg32_t  RESERVED9;                                                             /**< RESERVED */
          reg32_t  RESERVED10;                                                            /**< RESERVED */
          reg32_t  RESERVED11;                                                            /**< RESERVED */
          reg32_t  RESERVED12;                                                            /**< RESERVED */
          reg32_t  RESERVED13;                                                            /**< RESERVED */
    __IO  RegRfModeCfgRx1_t                                 RegRfModeCfgRx1;              /**< Mode_Cfg_Rx1 */
    __IO  RegRfModeCfgTx1_t                                 RegRfModeCfgTx1;              /**< Mode_Cfg_Tx1 */
    __IO  RegRfModeCfgTx2_t                                 RegRfModeCfgTx2;              /**< Mode_Cfg_Tx2 */
    __IO  RegRfModeCfgTxrx_t                                RegRfModeCfgTxrx;             /**< Mode_Cfg_Txrx */
    __IO  RegRfBurstCfgTxrx_t                               RegRfBurstCfgTxrx;            /**< Burst_Cfg_Txrx */
    __IO  RegRfDebugTxrx1_t                                 RegRfDebugTxrx1;              /**< Debug_Txrx1 */
    __IO  RegRfZbPdetCfg_t                                  RegRfZbPdetCfg;               /**< Zb_Pdet_Cfg */
    __I   RegRfRssi_t                                       RegRfRssi;                    /**< Rssi */
    __IO  RegRfRssiStart_t                                  RegRfRssiStart;               /**< Rssi_Start */
    __IO  RegRfRssiStop_t                                   RegRfRssiStop;                /**< Rssi_Stop */
    __IO  RegRfRssiFilt_t                                   RegRfRssiFilt;                /**< Rssi_Filt */
    __IO  RegRfLrFreqCorrCfg_t                              RegRfLrFreqCorrCfg;           /**< Lr_Freq_Corr_Cfg */
    __IO  RegRfLrTimRecCfg_t                                RegRfLrTimRecCfg;             /**< Lr_Tim_Rec_Cfg */
    __IO  RegRfZbFreqCorrCfg_t                              RegRfZbFreqCorrCfg;           /**< Zb_Freq_Corr_Cfg */
    __IO  RegRfZbThrCfg_t                                   RegRfZbThrCfg;                /**< Zb_Thr_Cfg */
    __IO  RegRfModeCfgRx2_t                                 RegRfModeCfgRx2;              /**< Mode_Cfg_Rx2 */
    __IO  RegRfTxrxDbg1_t                                   RegRfTxrxDbg1;                /**< Txrx_Dbg1 */
    __IO  RegRfTxrxDbg2_t                                   RegRfTxrxDbg2;                /**< Txrx_Dbg2 */
    __IO  RegRfTxrxDbg3_t                                   RegRfTxrxDbg3;                /**< Txrx_Dbg3 */
    __IO  RegRfTxrxDbg4_t                                   RegRfTxrxDbg4;                /**< Txrx_Dbg4 */
    __IO  RegRfDsmFrac1_t                                   RegRfDsmFrac1;                /**< Dsm_Frac1 */
    __IO  RegRfAgcThrshld11M_t                              RegRfAgcThrshld11M;           /**< Agc_Thrshld1_1M */
    __IO  RegRfAgcThrshld21M_t                              RegRfAgcThrshld21M;           /**< Agc_Thrshld2_1M */
    __IO  RegRfAgcThrshld31M_t                              RegRfAgcThrshld31M;           /**< Agc_Thrshld3_1M */
    __IO  RegRfAgcThrshld41M_t                              RegRfAgcThrshld41M;           /**< Agc_Thrshld4_1M */
    __IO  RegRfAgcThrshld51M_t                              RegRfAgcThrshld51M;           /**< Agc_Thrshld5_1M */
    __IO  RegRfAgcThrshld12M_t                              RegRfAgcThrshld12M;           /**< Agc_Thrshld1_2M */
    __IO  RegRfAgcThrshld22M_t                              RegRfAgcThrshld22M;           /**< Agc_Thrshld2_2M */
    __IO  RegRfAgcThrshld32M_t                              RegRfAgcThrshld32M;           /**< Agc_Thrshld3_2M */
    __IO  RegRfAgcThrshld42M_t                              RegRfAgcThrshld42M;           /**< Agc_Thrshld4_2M */
    __IO  RegRfAgcThrshld52M_t                              RegRfAgcThrshld52M;           /**< Agc_Thrshld5_2M */
    __IO  RegRfRxGrpDly1M_t                                 RegRfRxGrpDly1M;              /**< Rx_Grp_Dly_1M */
    __IO  RegRfRxGainVhg_t                                  RegRfRxGainVhg;               /**< Rx_Gain_Vhg */
    __IO  RegRfRxGainHg_t                                   RegRfRxGainHg;                /**< Rx_Gain_Hg */
    __IO  RegRfRxGainIhg_t                                  RegRfRxGainIhg;               /**< Rx_Gain_Ihg */
    __IO  RegRfRxGainMg_t                                   RegRfRxGainMg;                /**< Rx_Gain_Mg */
    __IO  RegRfRxGainLg_t                                   RegRfRxGainLg;                /**< Rx_Gain_Lg */
    __IO  RegRfRxGainVlg_t                                  RegRfRxGainVlg;               /**< Rx_Gain_Vlg */
    __I   RegRfAdcRbkI_t                                    RegRfAdcRbkI;                 /**< Adc_Rbk_I */
    __I   RegRfAdcRbkQ_t                                    RegRfAdcRbkQ;                 /**< Adc_Rbk_Q */
    __IO  RegRfRxGrpDly2M_t                                 RegRfRxGrpDly2M;              /**< Rx_Grp_Dly_2M */
    __IO  RegRfTimRecCfg_t                                  RegRfTimRecCfg;               /**< Tim_Rec_Cfg */
    __IO  RegRfFreqCorrCfg1_t                               RegRfFreqCorrCfg1;            /**< Freq_Corr_Cfg1 */
    __IO  RegRfFreqCorrCfg2_t                               RegRfFreqCorrCfg2;            /**< Freq_Corr_Cfg2 */
    __IO  RegRfTimAlign_t                                   RegRfTimAlign;                /**< Tim_Align */
    __IO  RegRfBypassFilt_t                                 RegRfBypassFilt;              /**< Bypass_Filt */
    __I   RegRfAgcRssiRdbk_t                                RegRfAgcRssiRdbk;             /**< Agc_Rssi_Rdbk */
    __IO  RegRfTimRestartDly_t                              RegRfTimRestartDly;           /**< Tim_Restart_Dly */
    __IO  RegRfCalOwCtrl_t                                  RegRfCalOwCtrl;               /**< Cal_Ow_Ctrl */
    __IO  RegRfCalOwVal_t                                   RegRfCalOwVal;                /**< Cal_Ow_Val */
    __IO  RegRfTxrxCbCalCtrl_t                              RegRfTxrxCbCalCtrl;           /**< Txrx_Cb_Cal_Ctrl */
          reg32_t  RESERVED14;                                                            /**< RESERVED */
    __IO  RegRfIdleTxSs1Strt_t                              RegRfIdleTxSs1Strt;           /**< Idle_Tx_Ss1_Strt */
    __IO  RegRfIdleTxSs2Strt_t                              RegRfIdleTxSs2Strt;           /**< Idle_Tx_Ss2_Strt */
    __IO  RegRfIdleTxSs3Strt_t                              RegRfIdleTxSs3Strt;           /**< Idle_Tx_Ss3_Strt */
    __IO  RegRfIdleTxSs4Strt_t                              RegRfIdleTxSs4Strt;           /**< Idle_Tx_Ss4_Strt */
    __IO  RegRfIdleTxSs5Strt_t                              RegRfIdleTxSs5Strt;           /**< Idle_Tx_Ss5_Strt */
    __IO  RegRfIdleTxSs6Strt_t                              RegRfIdleTxSs6Strt;           /**< Idle_Tx_Ss6_Strt */
    __IO  RegRfIdleTxSs7Strt_t                              RegRfIdleTxSs7Strt;           /**< Idle_Tx_Ss7_Strt */
          reg32_t  RESERVED15;                                                            /**< RESERVED */
    __IO  RegRfIdleRxSs1Strt_t                              RegRfIdleRxSs1Strt;           /**< Idle_Rx_Ss1_Strt */
    __IO  RegRfIdleRxSs2Strt_t                              RegRfIdleRxSs2Strt;           /**< Idle_Rx_Ss2_Strt */
    __IO  RegRfIdleRxSs3Strt_t                              RegRfIdleRxSs3Strt;           /**< Idle_Rx_Ss3_Strt */
    __IO  RegRfIdleRxSs4Strt_t                              RegRfIdleRxSs4Strt;           /**< Idle_Rx_Ss4_Strt */
    __IO  RegRfIdleRxSs5Strt_t                              RegRfIdleRxSs5Strt;           /**< Idle_Rx_Ss5_Strt */
    __IO  RegRfIdleRxSs6Strt_t                              RegRfIdleRxSs6Strt;           /**< Idle_Rx_Ss6_Strt */
    __IO  RegRfIdleTxSs1StrtCb_t                            RegRfIdleTxSs1StrtCb;         /**< Idle_Tx_Ss1_Strt_Cb */
    __IO  RegRfIdleTxSs2StrtCb_t                            RegRfIdleTxSs2StrtCb;         /**< Idle_Tx_Ss2_Strt_Cb */
    __IO  RegRfIdleTxSs3StrtCb_t                            RegRfIdleTxSs3StrtCb;         /**< Idle_Tx_Ss3_Strt_Cb */
    __IO  RegRfIdleTxSs4StrtCb_t                            RegRfIdleTxSs4StrtCb;         /**< Idle_Tx_Ss4_Strt_Cb */
    __IO  RegRfIdleTxSs5StrtCb_t                            RegRfIdleTxSs5StrtCb;         /**< Idle_Tx_Ss5_Strt_Cb */
    __IO  RegRfIdleTxSs6StrtCb_t                            RegRfIdleTxSs6StrtCb;         /**< Idle_Tx_Ss6_Strt_Cb */
    __IO  RegRfIdleRxSs1StrtCb_t                            RegRfIdleRxSs1StrtCb;         /**< Idle_Rx_Ss1_Strt_Cb */
    __IO  RegRfIdleRxSs2StrtCb_t                            RegRfIdleRxSs2StrtCb;         /**< Idle_Rx_Ss2_Strt_Cb */
    __IO  RegRfIdleRxSs3StrtCb_t                            RegRfIdleRxSs3StrtCb;         /**< Idle_Rx_Ss3_Strt_Cb */
    __IO  RegRfIdleRxSs4StrtCb_t                            RegRfIdleRxSs4StrtCb;         /**< Idle_Rx_Ss4_Strt_Cb */
    __IO  RegRfIdleRxSs5StrtCb_t                            RegRfIdleRxSs5StrtCb;         /**< Idle_Rx_Ss5_Strt_Cb */
    __IO  RegRfIdleRxSs6StrtCb_t                            RegRfIdleRxSs6StrtCb;         /**< Idle_Rx_Ss6_Strt_Cb */
    __IO  RegRfIdleTxSs7StrtCb_t                            RegRfIdleTxSs7StrtCb;         /**< Idle_Tx_Ss7_Strt_Cb */
    __IO  RegRfLocdTrig_t                                   RegRfLocdTrig;                /**< Locd_Trig */
    __I   RegRfFcalRdbk_t                                   RegRfFcalRdbk;                /**< Fcal_Rdbk */
    __IO  RegRfFcalDbg2_t                                   RegRfFcalDbg2;                /**< Fcal_Dbg2 */
          reg32_t  RESERVED16;                                                            /**< RESERVED */
    __IO  RegRfRccalDbg1_t                                  RegRfRccalDbg1;               /**< Rccal_Dbg1 */
    __IO  RegRfRccalDbg2_t                                  RegRfRccalDbg2;               /**< Rccal_Dbg2 */
    __I   RegRfRccalRdbk_t                                  RegRfRccalRdbk;               /**< Rccal_Rdbk */
          reg32_t  RESERVED17;                                                            /**< RESERVED */
    __IO  RegRfDcocBypassAdc_t                              RegRfDcocBypassAdc;           /**< Dcoc_Bypass_Adc */
    __IO  RegRfDcocBypassDac_t                              RegRfDcocBypassDac;           /**< Dcoc_Bypass_Dac */
    __IO  RegRfDcocDbg_t                                    RegRfDcocDbg;                 /**< Dcoc_Dbg */
    __IO  RegRfDcocLnaOffset_t                              RegRfDcocLnaOffset;           /**< Dcoc_Lna_Offset */
    __IO  RegRfDcocCbpfOffset_t                             RegRfDcocCbpfOffset;          /**< Dcoc_Cbpf_Offset */
    __I   RegRfDcocRdbk1_t                                  RegRfDcocRdbk1;               /**< Dcoc_Rdbk1 */
    __I   RegRfDcocRdbk2_t                                  RegRfDcocRdbk2;               /**< Dcoc_Rdbk2 */
    __I   RegRfDcocRdbk3_t                                  RegRfDcocRdbk3;               /**< Dcoc_Rdbk3 */
          reg32_t  RESERVED18;                                                            /**< RESERVED */
          reg32_t  RESERVED19;                                                            /**< RESERVED */
    __IO  RegRfLdotDbg1_t                                   RegRfLdotDbg1;                /**< Ldot_Dbg1 */
    __IO  RegRfLdotDbg2_t                                   RegRfLdotDbg2;                /**< Ldot_Dbg2 */
    __IO  RegRfLdotDbg3_t                                   RegRfLdotDbg3;                /**< Ldot_Dbg3 */
    __IO  RegRfLdotDbg4_t                                   RegRfLdotDbg4;                /**< Ldot_Dbg4 */
    __I   RegRfLdotRdbk1_t                                  RegRfLdotRdbk1;               /**< Ldot_Rdbk1 */
    __I   RegRfLdotRdbk2_t                                  RegRfLdotRdbk2;               /**< Ldot_Rdbk2 */
    __I   RegRfLdotRdbk3_t                                  RegRfLdotRdbk3;               /**< Ldot_Rdbk3 */
          reg32_t  RESERVED20;                                                            /**< RESERVED */
          reg32_t  RESERVED21;                                                            /**< RESERVED */
    __IO  RegRfHpmcCfg_t                                    RegRfHpmcCfg;                 /**< Hpmc_Cfg */
    __IO  RegRfHpmcDebug_t                                  RegRfHpmcDebug;               /**< Hpmc_Debug */
    __I   RegRfHpmcRdbk1_t                                  RegRfHpmcRdbk1;               /**< Hpmc_Rdbk1 */
    __I   RegRfHpmcRdbk2_t                                  RegRfHpmcRdbk2;               /**< Hpmc_Rdbk2 */
    __I   RegRfHpmcRdbk3_t                                  RegRfHpmcRdbk3;               /**< Hpmc_Rdbk3 */
    __I   RegRfHpmcRdbk4_t                                  RegRfHpmcRdbk4;               /**< Hpmc_Rdbk4 */
          reg32_t  RESERVED22;                                                            /**< RESERVED */
          reg32_t  RESERVED23;                                                            /**< RESERVED */
    __IO  RegRfLocdCfg_t                                    RegRfLocdCfg;                 /**< Locd_Cfg */
    __I   RegRfLocdRdbk_t                                   RegRfLocdRdbk;                /**< Locd_Rdbk */
    __IO  RegRfLocdTrgtCnt11_t                              RegRfLocdTrgtCnt11;           /**< Locd_Trgt_Cnt11 */
    __IO  RegRfLocdTrgtCnt12_t                              RegRfLocdTrgtCnt12;           /**< Locd_Trgt_Cnt12 */
          reg32_t  RESERVED24;                                                            /**< RESERVED */
          reg32_t  RESERVED25;                                                            /**< RESERVED */
    __I   RegRfCalDoneRdbk_t                                RegRfCalDoneRdbk;             /**< Cal_Done_Rdbk */
          reg32_t  RESERVED26;                                                            /**< RESERVED */
          reg32_t  RESERVED27;                                                            /**< RESERVED */
          reg32_t  RESERVED28;                                                            /**< RESERVED */
          reg32_t  RESERVED29;                                                            /**< RESERVED */
          reg32_t  RESERVED30;                                                            /**< RESERVED */
          reg32_t  RESERVED31;                                                            /**< RESERVED */
          reg32_t  RESERVED32;                                                            /**< RESERVED */
    __IO  RegRfAdcDacDft1_t                                 RegRfAdcDacDft1;              /**< Adc_Dac_Dft1 */
    __IO  RegRfAdcDacDft2_t                                 RegRfAdcDacDft2;              /**< Adc_Dac_Dft2 */
          reg32_t  RESERVED33;                                                            /**< RESERVED */
    __IO  RegRfDftMux_t                                     RegRfDftMux;                  /**< Dft_Mux */
          reg32_t  RESERVED34;                                                            /**< RESERVED */
          reg32_t  RESERVED35;                                                            /**< RESERVED */
    __IO  RegRfDiag_t                                       RegRfDiag;                    /**< Diag */
          reg32_t  RESERVED36;                                                            /**< RESERVED */
          reg32_t  RESERVED37;                                                            /**< RESERVED */
          reg32_t  RESERVED38;                                                            /**< RESERVED */
          reg32_t  RESERVED39;                                                            /**< RESERVED */
          reg32_t  RESERVED40;                                                            /**< RESERVED */
    __IO  RegRfBypassClkGating_t                            RegRfBypassClkGating;         /**< Bypass_Clk_Gating */
    __IO  RegRfSftRst_t                                     RegRfSftRst;                  /**< Sft_Rst */
          reg32_t  RESERVED41;                                                            /**< RESERVED */
          reg32_t  RESERVED42;                                                            /**< RESERVED */
    __IO  RegRfLdo1_t                                       RegRfLdo1;                    /**< Ldo1 */
    __IO  RegRfLdoBgClkAuxDrv_t                             RegRfLdoBgClkAuxDrv;          /**< Ldo_Bg_Clk_Aux_Drv */
          reg32_t  RESERVED43;                                                            /**< RESERVED */
          reg32_t  RESERVED44;                                                            /**< RESERVED */
          reg32_t  RESERVED45;                                                            /**< RESERVED */
          reg32_t  RESERVED46;                                                            /**< RESERVED */
    __IO  RegRfLnmPa_t                                      RegRfLnmPa;                   /**< Lnm_Pa */
    __IO  RegRfCbpfAdc_t                                    RegRfCbpfAdc;                 /**< Cbpf_Adc */
          reg32_t  RESERVED47;                                                            /**< RESERVED */
    __IO  RegRfPdTxdac_t                                    RegRfPdTxdac;                 /**< Pd_Txdac */
    __IO  RegRfVcoLdotrim_t                                 RegRfVcoLdotrim;              /**< Vco_Ldotrim */
          reg32_t  RESERVED48;                                                            /**< RESERVED */
          reg32_t  RESERVED49;                                                            /**< RESERVED */
          reg32_t  RESERVED50;                                                            /**< RESERVED */
    __IO  RegRfRegSparelv1_t                                RegRfRegSparelv1;             /**< Reg_Sparelv1 */
          reg32_t  RESERVED51;                                                            /**< RESERVED */
    __IO  RegRfLdoOwCtrl_t                                  RegRfLdoOwCtrl;               /**< Ldo_Ow_Ctrl */
    __IO  RegRfLdoOwVal_t                                   RegRfLdoOwVal;                /**< Ldo_Ow_Val */
    __IO  RegRfBgOwCtrl_t                                   RegRfBgOwCtrl;                /**< Bg_Ow_Ctrl */
    __IO  RegRfBgOwVal_t                                    RegRfBgOwVal;                 /**< Bg_Ow_Val */
    __IO  RegRfLdotrimOwCtrl_t                              RegRfLdotrimOwCtrl;           /**< Ldotrim_Ow_Ctrl */
    __IO  RegRfLdotrimOwVal_t                               RegRfLdotrimOwVal;            /**< Ldotrim_Ow_Val */
    __IO  RegRfRccalOwCtrlVal_t                             RegRfRccalOwCtrlVal;          /**< Rccal_Ow_Ctrl_Val */
          reg32_t  RESERVED52;                                                            /**< RESERVED */
    __IO  RegRfXoOwCtrlVal_t                                RegRfXoOwCtrlVal;             /**< Xo_Ow_Ctrl_Val */
          reg32_t  RESERVED53;                                                            /**< RESERVED */
          reg32_t  RESERVED54;                                                            /**< RESERVED */
          reg32_t  RESERVED55;                                                            /**< RESERVED */
    __IO  RegRfLnmPaOwCtrlVal_t                             RegRfLnmPaOwCtrlVal;          /**< Lnm_Pa_Ow_Ctrl_Val */
    __IO  RegRfLnmOwVal_t                                   RegRfLnmOwVal;                /**< Lnm_Ow_Val */
    __IO  RegRfPaOwVal_t                                    RegRfPaOwVal;                 /**< Pa_Ow_Val */
          reg32_t  RESERVED56;                                                            /**< RESERVED */
    __IO  RegRfCbpfAdcOwCtrl_t                              RegRfCbpfAdcOwCtrl;           /**< Cbpf_Adc_Ow_Ctrl */
    __IO  RegRfCbpfAdcOwVal_t                               RegRfCbpfAdcOwVal;            /**< Cbpf_Adc_Ow_Val */
          reg32_t  RESERVED57;                                                            /**< RESERVED */
          reg32_t  RESERVED58;                                                            /**< RESERVED */
    __IO  RegRfPdDivnFcalOwCtrl_t                           RegRfPdDivnFcalOwCtrl;        /**< Pd_Divn_Fcal_Ow_Ctrl */
    __IO  RegRfPdDivnFcalOwVal_t                            RegRfPdDivnFcalOwVal;         /**< Pd_Divn_Fcal_Ow_Val */
    __IO  RegRfVcoLopathDacOwCtrl_t                         RegRfVcoLopathDacOwCtrl;      /**< Vco_Lopath_Dac_Ow_Ctrl */
    __IO  RegRfVcoLopathDacOwVal_t                          RegRfVcoLopathDacOwVal;       /**< Vco_Lopath_Dac_Ow_Val */
          reg32_t  RESERVED59;                                                            /**< RESERVED */
          reg32_t  RESERVED60;                                                            /**< RESERVED */
    __IO  RegRfSeqSparelvOwCtrl_t                           RegRfSeqSparelvOwCtrl;        /**< Seq_Sparelv_Ow_Ctrl */
    __IO  RegRfSeqSparelvOwVal_t                            RegRfSeqSparelvOwVal;         /**< Seq_Sparelv_Ow_Val */
          reg32_t  RESERVED61;                                                            /**< RESERVED */
          reg32_t  RESERVED62;                                                            /**< RESERVED */
          reg32_t  RESERVED63;                                                            /**< RESERVED */
          reg32_t  RESERVED64;                                                            /**< RESERVED */
          reg32_t  RESERVED65;                                                            /**< RESERVED */
          reg32_t  RESERVED66;                                                            /**< RESERVED */
          reg32_t  RESERVED67;                                                            /**< RESERVED */
          reg32_t  RESERVED68;                                                            /**< RESERVED */
          reg32_t  RESERVED69;                                                            /**< RESERVED */
          reg32_t  RESERVED70;                                                            /**< RESERVED */
          reg32_t  RESERVED71;                                                            /**< RESERVED */
          reg32_t  RESERVED72;                                                            /**< RESERVED */
          reg32_t  RESERVED73;                                                            /**< RESERVED */
          reg32_t  RESERVED74;                                                            /**< RESERVED */
          reg32_t  RESERVED75;                                                            /**< RESERVED */
          reg32_t  RESERVED76;                                                            /**< RESERVED */
          reg32_t  RESERVED77;                                                            /**< RESERVED */
          reg32_t  RESERVED78;                                                            /**< RESERVED */
          reg32_t  RESERVED79;                                                            /**< RESERVED */
          reg32_t  RESERVED80;                                                            /**< RESERVED */
    __IO  RegRfXoSeq_t                                      RegRfXoSeq;                   /**< Xo_Seq */
    __IO  RegRfXoDebug_t                                    RegRfXoDebug;                 /**< Xo_Debug */
    __IO  RegRfXoSeqDig_t                                   RegRfXoSeqDig;                /**< Xo_Seq_Dig */
    __IO  RegRfXoDebugDig_t                                 RegRfXoDebugDig;              /**< Xo_Debug_Dig */
    __IO  RegRfRegSparertcDig_t                             RegRfRegSparertcDig;          /**< Reg_Sparertc_Dig */
    __IO  RegRfRcoscDig_t                                   RegRfRcoscDig;                /**< Rcosc_Dig */
    __IO  RegRfRegSparertc_t                                RegRfRegSparertc;             /**< Reg_Sparertc */
    __I   RegRfXoSeqRead_t                                  RegRfXoSeqRead;               /**< Xo_Seq_Read */
    __I   RegRfXoDebugRead_t                                RegRfXoDebugRead;             /**< Xo_Debug_Read */
    __I   RegRfRegSparertcRead_t                            RegRfRegSparertcRead;         /**< Reg_Sparertc_Read */
    __I   RegRfXoDigRead_t                                  RegRfXoDigRead;               /**< Xo_Dig_Read */
    __I   RegRfDcdcStatusCore_t                             RegRfDcdcStatusCore;          /**< Dcdc_Status_Core */
    __I   RegRfDcdcStatusFsm_t                              RegRfDcdcStatusFsm;           /**< Dcdc_Status_Fsm */
    __IO  RegRfRcosc_t                                      RegRfRcosc;                   /**< Rcosc */
          reg32_t  RESERVED81;                                                            /**< RESERVED */
          reg32_t  RESERVED82;                                                            /**< RESERVED */
    __IO  RegRfDcdcCore_t                                   RegRfDcdcCore;                /**< Dcdc_Core */
    __IO  RegRfDcdcTimer_t                                  RegRfDcdcTimer;               /**< Dcdc_Timer */
    __IO  RegRfDcdcRef_t                                    RegRfDcdcRef;                 /**< Dcdc_Ref */
    __IO  RegRfDcdcTest_t                                   RegRfDcdcTest;                /**< Dcdc_Test */
    __IO  RegRfDcdcDiag_t                                   RegRfDcdcDiag;                /**< Dcdc_Diag */
    __IO  RegRfXo32K_t                                      RegRfXo32K;                   /**< Xo32K */
    __IO  RegRfRo32K_t                                      RegRfRo32K;                   /**< Ro32K */
    __IO  RegRfDiagMisctop_t                                RegRfDiagMisctop;             /**< Diag_Misctop */
    __IO  RegRfMemAddr_t                                    RegRfMemAddr;                 /**< Mem_Addr */
    __IO  RegRfMemDataIpath_t                               RegRfMemDataIpath;            /**< Mem_Data_Ipath */
    __IO  RegRfDbgCtrl_t                                    RegRfDbgCtrl;                 /**< Dbg_Ctrl */
    __IO  RegRfStartAddr_t                                  RegRfStartAddr;               /**< Start_Addr */
    __IO  RegRfStopAddr_t                                   RegRfStopAddr;                /**< Stop_Addr */
    __IO  RegRfMemDataQpath_t                               RegRfMemDataQpath;            /**< Mem_Data_Qpath */
    __IO  RegRfStrobeDelay_t                                RegRfStrobeDelay;             /**< Strobe_Delay */
} Radio_RegMap_t;

/** @} end of group Radio_RegMap */



/***************************************************************************//**
 * @defgroup Radio_BitFields Radio bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegRfDeviceId
 * @{
 */
// RegRfDeviceId.r32
#define  REG_RF_DEVICE_ID_RESET_VALUE                       0x00000062u                   /**< Reset value of RegRfDeviceId */
#define  REG_RF_DEVICE_ID_MASK                              0x000000FFu                   /**< Mask for RegRfDeviceId */

#define  RF_DEVICE_ID_SHIFT                                 0                             /**< Shift for RfDeviceId */
#define  RF_DEVICE_ID_MASK                                  0x000000FFu                   /**< Mask for RfDeviceId */
#define  RF_DEVICE_ID_BMASK                                 0xFFu                         /**< Base mask for RfDeviceId */
#define  RF_DEVICE_ID(x)                                    (((x)&0xFFu)<<0)              /**< Set RfDeviceId in register */
#define  GET_RF_DEVICE_ID(reg)                              (((reg)>>0)&0xFFu)            /**< Get RfDeviceId from register */
/** @} */


/**
 * @name RegRfVersionId
 * @{
 */
// RegRfVersionId.r32
#define  REG_RF_VERSION_ID_RESET_VALUE                      0x00000084u                   /**< Reset value of RegRfVersionId */
#define  REG_RF_VERSION_ID_MASK                             0x000000FFu                   /**< Mask for RegRfVersionId */

#define  RF_VERSION_ID_SHIFT                                0                             /**< Shift for RfVersionId */
#define  RF_VERSION_ID_MASK                                 0x000000FFu                   /**< Mask for RfVersionId */
#define  RF_VERSION_ID_BMASK                                0xFFu                         /**< Base mask for RfVersionId */
#define  RF_VERSION_ID(x)                                   (((x)&0xFFu)<<0)              /**< Set RfVersionId in register */
#define  GET_RF_VERSION_ID(reg)                             (((reg)>>0)&0xFFu)            /**< Get RfVersionId from register */
/** @} */


/**
 * @name RegRfModeCfgRx1
 * @{
 */
// RegRfModeCfgRx1.r32
#define  REG_RF_MODE_CFG_RX1_RESET_VALUE                    0x00000416u                   /**< Reset value of RegRfModeCfgRx1 */
#define  REG_RF_MODE_CFG_RX1_MASK                           0x00003FFFu                   /**< Mask for RegRfModeCfgRx1 */

#define  RF_LR_MODE_SHIFT                                   0                             /**< Shift for RfLrMode */
#define  RF_LR_MODE_MASK                                    0x00000001u                   /**< Mask for RfLrMode */
#define  RF_LR_MODE_BMASK                                   0x1u                          /**< Base mask for RfLrMode */
#define  RF_LR_MODE(x)                                      (((x)&0x1u)<<0)               /**< Set RfLrMode in register */
#define  GET_RF_LR_MODE(reg)                                (((reg)>>0)&0x1u)             /**< Get RfLrMode from register */
#define  RF_BW_CODE_SHIFT                                   1                             /**< Shift for RfBwCode */
#define  RF_BW_CODE_MASK                                    0x0000000Eu                   /**< Mask for RfBwCode */
#define  RF_BW_CODE_BMASK                                   0x7u                          /**< Base mask for RfBwCode */
#define  RF_BW_CODE(x)                                      (((x)&0x7u)<<1)               /**< Set RfBwCode in register */
#define  GET_RF_BW_CODE(reg)                                (((reg)>>1)&0x7u)             /**< Get RfBwCode from register */
#define  RF_SC_CODE_SHIFT                                   4                             /**< Shift for RfScCode */
#define  RF_SC_CODE_MASK                                    0x00000010u                   /**< Mask for RfScCode */
#define  RF_SC_CODE_BMASK                                   0x1u                          /**< Base mask for RfScCode */
#define  RF_SC_CODE(x)                                      (((x)&0x1u)<<4)               /**< Set RfScCode in register */
#define  GET_RF_SC_CODE(reg)                                (((reg)>>4)&0x1u)             /**< Get RfScCode from register */
#define  RF_RX_DATA_CLK_DIS_SHIFT                           5                             /**< Shift for RfRxDataClkDis */
#define  RF_RX_DATA_CLK_DIS_MASK                            0x00000020u                   /**< Mask for RfRxDataClkDis */
#define  RF_RX_DATA_CLK_DIS_BMASK                           0x1u                          /**< Base mask for RfRxDataClkDis */
#define  RF_RX_DATA_CLK_DIS(x)                              (((x)&0x1u)<<5)               /**< Set RfRxDataClkDis in register */
#define  GET_RF_RX_DATA_CLK_DIS(reg)                        (((reg)>>5)&0x1u)             /**< Get RfRxDataClkDis from register */
#define  RF_IR_FILTER_MODE_SHIFT                            6                             /**< Shift for RfIrFilterMode */
#define  RF_IR_FILTER_MODE_MASK                             0x000000C0u                   /**< Mask for RfIrFilterMode */
#define  RF_IR_FILTER_MODE_BMASK                            0x3u                          /**< Base mask for RfIrFilterMode */
#define  RF_IR_FILTER_MODE(x)                               (((x)&0x3u)<<6)               /**< Set RfIrFilterMode in register */
#define  GET_RF_IR_FILTER_MODE(reg)                         (((reg)>>6)&0x3u)             /**< Get RfIrFilterMode from register */
#define  RF_ZIGBEE_MODE_RX_SHIFT                            8                             /**< Shift for RfZigbeeModeRx */
#define  RF_ZIGBEE_MODE_RX_MASK                             0x00000100u                   /**< Mask for RfZigbeeModeRx */
#define  RF_ZIGBEE_MODE_RX_BMASK                            0x1u                          /**< Base mask for RfZigbeeModeRx */
#define  RF_ZIGBEE_MODE_RX(x)                               (((x)&0x1u)<<8)               /**< Set RfZigbeeModeRx in register */
#define  GET_RF_ZIGBEE_MODE_RX(reg)                         (((reg)>>8)&0x1u)             /**< Get RfZigbeeModeRx from register */
#define  RF_FE_RTRIM_RX_SHIFT                               9                             /**< Shift for RfFeRtrimRx */
#define  RF_FE_RTRIM_RX_MASK                                0x00000E00u                   /**< Mask for RfFeRtrimRx */
#define  RF_FE_RTRIM_RX_BMASK                               0x7u                          /**< Base mask for RfFeRtrimRx */
#define  RF_FE_RTRIM_RX(x)                                  (((x)&0x7u)<<9)               /**< Set RfFeRtrimRx in register */
#define  GET_RF_FE_RTRIM_RX(reg)                            (((reg)>>9)&0x7u)             /**< Get RfFeRtrimRx from register */
#define  RF_IF_FREQ_SHIFT                                   12                            /**< Shift for RfIfFreq */
#define  RF_IF_FREQ_MASK                                    0x00003000u                   /**< Mask for RfIfFreq */
#define  RF_IF_FREQ_BMASK                                   0x3u                          /**< Base mask for RfIfFreq */
#define  RF_IF_FREQ(x)                                      (((x)&0x3u)<<12)              /**< Set RfIfFreq in register */
#define  GET_RF_IF_FREQ(reg)                                (((reg)>>12)&0x3u)            /**< Get RfIfFreq from register */
/** @} */


/**
 * @name RegRfModeCfgTx1
 * @{
 */
// RegRfModeCfgTx1.r32
#define  REG_RF_MODE_CFG_TX1_RESET_VALUE                    0x00002320u                   /**< Reset value of RegRfModeCfgTx1 */
#define  REG_RF_MODE_CFG_TX1_MASK                           0x0000FFFFu                   /**< Mask for RegRfModeCfgTx1 */

#define  RF_BLE_MODE_TX_SHIFT                               0                             /**< Shift for RfBleModeTx */
#define  RF_BLE_MODE_TX_MASK                                0x00000001u                   /**< Mask for RfBleModeTx */
#define  RF_BLE_MODE_TX_BMASK                               0x1u                          /**< Base mask for RfBleModeTx */
#define  RF_BLE_MODE_TX(x)                                  (((x)&0x1u)<<0)               /**< Set RfBleModeTx in register */
#define  GET_RF_BLE_MODE_TX(reg)                            (((reg)>>0)&0x1u)             /**< Get RfBleModeTx from register */
#define  RF_VCO_TRIM_KVM_SHIFT                              1                             /**< Shift for RfVcoTrimKvm */
#define  RF_VCO_TRIM_KVM_MASK                               0x0000000Eu                   /**< Mask for RfVcoTrimKvm */
#define  RF_VCO_TRIM_KVM_BMASK                              0x7u                          /**< Base mask for RfVcoTrimKvm */
#define  RF_VCO_TRIM_KVM(x)                                 (((x)&0x7u)<<1)               /**< Set RfVcoTrimKvm in register */
#define  GET_RF_VCO_TRIM_KVM(reg)                           (((reg)>>1)&0x7u)             /**< Get RfVcoTrimKvm from register */
#define  RF_HPMC_EXP_DIFF_COUNT_SHIFT                       4                             /**< Shift for RfHpmcExpDiffCount */
#define  RF_HPMC_EXP_DIFF_COUNT_MASK                        0x00001FF0u                   /**< Mask for RfHpmcExpDiffCount */
#define  RF_HPMC_EXP_DIFF_COUNT_BMASK                       0x1FFu                        /**< Base mask for RfHpmcExpDiffCount */
#define  RF_HPMC_EXP_DIFF_COUNT(x)                          (((x)&0x1FFu)<<4)             /**< Set RfHpmcExpDiffCount in register */
#define  GET_RF_HPMC_EXP_DIFF_COUNT(reg)                    (((reg)>>4)&0x1FFu)           /**< Get RfHpmcExpDiffCount from register */
#define  RF_DAC_TRIM_CFBK_SHIFT                             13                            /**< Shift for RfDacTrimCfbk */
#define  RF_DAC_TRIM_CFBK_MASK                              0x00006000u                   /**< Mask for RfDacTrimCfbk */
#define  RF_DAC_TRIM_CFBK_BMASK                             0x3u                          /**< Base mask for RfDacTrimCfbk */
#define  RF_DAC_TRIM_CFBK(x)                                (((x)&0x3u)<<13)              /**< Set RfDacTrimCfbk in register */
#define  GET_RF_DAC_TRIM_CFBK(reg)                          (((reg)>>13)&0x3u)            /**< Get RfDacTrimCfbk from register */
#define  RF_ZIGBEE_MODE_TX_SHIFT                            15                            /**< Shift for RfZigbeeModeTx */
#define  RF_ZIGBEE_MODE_TX_MASK                             0x00008000u                   /**< Mask for RfZigbeeModeTx */
#define  RF_ZIGBEE_MODE_TX_BMASK                            0x1u                          /**< Base mask for RfZigbeeModeTx */
#define  RF_ZIGBEE_MODE_TX(x)                               (((x)&0x1u)<<15)              /**< Set RfZigbeeModeTx in register */
#define  GET_RF_ZIGBEE_MODE_TX(reg)                         (((reg)>>15)&0x1u)            /**< Get RfZigbeeModeTx from register */
/** @} */


/**
 * @name RegRfModeCfgTx2
 * @{
 */
// RegRfModeCfgTx2.r32
#define  REG_RF_MODE_CFG_TX2_RESET_VALUE                    0x00000049u                   /**< Reset value of RegRfModeCfgTx2 */
#define  REG_RF_MODE_CFG_TX2_MASK                           0x00003FFFu                   /**< Mask for RegRfModeCfgTx2 */

#define  RF_PA_RAMP_MODE_SHIFT                              0                             /**< Shift for RfPaRampMode */
#define  RF_PA_RAMP_MODE_MASK                               0x00000003u                   /**< Mask for RfPaRampMode */
#define  RF_PA_RAMP_MODE_BMASK                              0x3u                          /**< Base mask for RfPaRampMode */
#define  RF_PA_RAMP_MODE(x)                                 (((x)&0x3u)<<0)               /**< Set RfPaRampMode in register */
#define  GET_RF_PA_RAMP_MODE(reg)                           (((reg)>>0)&0x3u)             /**< Get RfPaRampMode from register */
#define  RF_EXT_PA_EN_ASSERT_DLY_SHIFT                      2                             /**< Shift for RfExtPaEnAssertDly */
#define  RF_EXT_PA_EN_ASSERT_DLY_MASK                       0x0000001Cu                   /**< Mask for RfExtPaEnAssertDly */
#define  RF_EXT_PA_EN_ASSERT_DLY_BMASK                      0x7u                          /**< Base mask for RfExtPaEnAssertDly */
#define  RF_EXT_PA_EN_ASSERT_DLY(x)                         (((x)&0x7u)<<2)               /**< Set RfExtPaEnAssertDly in register */
#define  GET_RF_EXT_PA_EN_ASSERT_DLY(reg)                   (((reg)>>2)&0x7u)             /**< Get RfExtPaEnAssertDly from register */
#define  RF_EXT_PA_EN_DEASSERT_DLY_SHIFT                    5                             /**< Shift for RfExtPaEnDeassertDly */
#define  RF_EXT_PA_EN_DEASSERT_DLY_MASK                     0x000000E0u                   /**< Mask for RfExtPaEnDeassertDly */
#define  RF_EXT_PA_EN_DEASSERT_DLY_BMASK                    0x7u                          /**< Base mask for RfExtPaEnDeassertDly */
#define  RF_EXT_PA_EN_DEASSERT_DLY(x)                       (((x)&0x7u)<<5)               /**< Set RfExtPaEnDeassertDly in register */
#define  GET_RF_EXT_PA_EN_DEASSERT_DLY(reg)                 (((reg)>>5)&0x7u)             /**< Get RfExtPaEnDeassertDly from register */
#define  RF_PA_RAMP_ASSERT_DLY_SHIFT                        8                             /**< Shift for RfPaRampAssertDly */
#define  RF_PA_RAMP_ASSERT_DLY_MASK                         0x00000700u                   /**< Mask for RfPaRampAssertDly */
#define  RF_PA_RAMP_ASSERT_DLY_BMASK                        0x7u                          /**< Base mask for RfPaRampAssertDly */
#define  RF_PA_RAMP_ASSERT_DLY(x)                           (((x)&0x7u)<<8)               /**< Set RfPaRampAssertDly in register */
#define  GET_RF_PA_RAMP_ASSERT_DLY(reg)                     (((reg)>>8)&0x7u)             /**< Get RfPaRampAssertDly from register */
#define  RF_PA_RAMP_DEASSERT_DLY_SHIFT                      11                            /**< Shift for RfPaRampDeassertDly */
#define  RF_PA_RAMP_DEASSERT_DLY_MASK                       0x00003800u                   /**< Mask for RfPaRampDeassertDly */
#define  RF_PA_RAMP_DEASSERT_DLY_BMASK                      0x7u                          /**< Base mask for RfPaRampDeassertDly */
#define  RF_PA_RAMP_DEASSERT_DLY(x)                         (((x)&0x7u)<<11)              /**< Set RfPaRampDeassertDly in register */
#define  GET_RF_PA_RAMP_DEASSERT_DLY(reg)                   (((reg)>>11)&0x7u)            /**< Get RfPaRampDeassertDly from register */
/** @} */


/**
 * @name RegRfModeCfgTxrx
 * @{
 */
// RegRfModeCfgTxrx.r32
#define  REG_RF_MODE_CFG_TXRX_RESET_VALUE                   0x00008A04u                   /**< Reset value of RegRfModeCfgTxrx */
#define  REG_RF_MODE_CFG_TXRX_MASK                          0x0000FFFFu                   /**< Mask for RegRfModeCfgTxrx */

#define  RF_DIS_CLK_DIG_O_SHIFT                             0                             /**< Shift for RfDisClkDigO */
#define  RF_DIS_CLK_DIG_O_MASK                              0x00000001u                   /**< Mask for RfDisClkDigO */
#define  RF_DIS_CLK_DIG_O_BMASK                             0x1u                          /**< Base mask for RfDisClkDigO */
#define  RF_DIS_CLK_DIG_O(x)                                (((x)&0x1u)<<0)               /**< Set RfDisClkDigO in register */
#define  GET_RF_DIS_CLK_DIG_O(reg)                          (((reg)>>0)&0x1u)             /**< Get RfDisClkDigO from register */
#define  RF_GF_BT_SHIFT                                     1                             /**< Shift for RfGfBt */
#define  RF_GF_BT_MASK                                      0x00000002u                   /**< Mask for RfGfBt */
#define  RF_GF_BT_BMASK                                     0x1u                          /**< Base mask for RfGfBt */
#define  RF_GF_BT(x)                                        (((x)&0x1u)<<1)               /**< Set RfGfBt in register */
#define  GET_RF_GF_BT(reg)                                  (((reg)>>1)&0x1u)             /**< Get RfGfBt from register */
#define  RF_LDO_ANT_TRIM_SHIFT                              2                             /**< Shift for RfLdoAntTrim */
#define  RF_LDO_ANT_TRIM_MASK                               0x0000003Cu                   /**< Mask for RfLdoAntTrim */
#define  RF_LDO_ANT_TRIM_BMASK                              0xFu                          /**< Base mask for RfLdoAntTrim */
#define  RF_LDO_ANT_TRIM(x)                                 (((x)&0xFu)<<2)               /**< Set RfLdoAntTrim in register */
#define  GET_RF_LDO_ANT_TRIM(reg)                           (((reg)>>2)&0xFu)             /**< Get RfLdoAntTrim from register */
#define  RF_TX_PA_PWR_SHIFT                                 6                             /**< Shift for RfTxPaPwr */
#define  RF_TX_PA_PWR_MASK                                  0x00000FC0u                   /**< Mask for RfTxPaPwr */
#define  RF_TX_PA_PWR_BMASK                                 0x3Fu                         /**< Base mask for RfTxPaPwr */
#define  RF_TX_PA_PWR(x)                                    (((x)&0x3Fu)<<6)              /**< Set RfTxPaPwr in register */
#define  GET_RF_TX_PA_PWR(reg)                              (((reg)>>6)&0x3Fu)            /**< Get RfTxPaPwr from register */
#define  RF_TX_MI_SEL_SHIFT                                 12                            /**< Shift for RfTxMiSel */
#define  RF_TX_MI_SEL_MASK                                  0x00001000u                   /**< Mask for RfTxMiSel */
#define  RF_TX_MI_SEL_BMASK                                 0x1u                          /**< Base mask for RfTxMiSel */
#define  RF_TX_MI_SEL(x)                                    (((x)&0x1u)<<12)              /**< Set RfTxMiSel in register */
#define  GET_RF_TX_MI_SEL(reg)                              (((reg)>>12)&0x1u)            /**< Get RfTxMiSel from register */
#define  RF_RX_MI_SEL_SHIFT                                 13                            /**< Shift for RfRxMiSel */
#define  RF_RX_MI_SEL_MASK                                  0x00002000u                   /**< Mask for RfRxMiSel */
#define  RF_RX_MI_SEL_BMASK                                 0x1u                          /**< Base mask for RfRxMiSel */
#define  RF_RX_MI_SEL(x)                                    (((x)&0x1u)<<13)              /**< Set RfRxMiSel in register */
#define  GET_RF_RX_MI_SEL(reg)                              (((reg)>>13)&0x1u)            /**< Get RfRxMiSel from register */
#define  RF_LNA_HATTN_SHIFT                                 14                            /**< Shift for RfLnaHattn */
#define  RF_LNA_HATTN_MASK                                  0x00004000u                   /**< Mask for RfLnaHattn */
#define  RF_LNA_HATTN_BMASK                                 0x1u                          /**< Base mask for RfLnaHattn */
#define  RF_LNA_HATTN(x)                                    (((x)&0x1u)<<14)              /**< Set RfLnaHattn in register */
#define  GET_RF_LNA_HATTN(reg)                              (((reg)>>14)&0x1u)            /**< Get RfLnaHattn from register */
#define  RF_CBPF_TYPE_SHIFT                                 15                            /**< Shift for RfCbpfType */
#define  RF_CBPF_TYPE_MASK                                  0x00008000u                   /**< Mask for RfCbpfType */
#define  RF_CBPF_TYPE_BMASK                                 0x1u                          /**< Base mask for RfCbpfType */
#define  RF_CBPF_TYPE(x)                                    (((x)&0x1u)<<15)              /**< Set RfCbpfType in register */
#define  GET_RF_CBPF_TYPE(reg)                              (((reg)>>15)&0x1u)            /**< Get RfCbpfType from register */
/** @} */


/**
 * @name RegRfBurstCfgTxrx
 * @{
 */
// RegRfBurstCfgTxrx.r32
#define  REG_RF_BURST_CFG_TXRX_RESET_VALUE                  0x00000013u                   /**< Reset value of RegRfBurstCfgTxrx */
#define  REG_RF_BURST_CFG_TXRX_MASK                         0x00003FFFu                   /**< Mask for RegRfBurstCfgTxrx */

#define  RF_CHNL_NUM_SHIFT                                  0                             /**< Shift for RfChnlNum */
#define  RF_CHNL_NUM_MASK                                   0x0000003Fu                   /**< Mask for RfChnlNum */
#define  RF_CHNL_NUM_BMASK                                  0x3Fu                         /**< Base mask for RfChnlNum */
#define  RF_CHNL_NUM(x)                                     (((x)&0x3Fu)<<0)              /**< Set RfChnlNum in register */
#define  GET_RF_CHNL_NUM(reg)                               (((reg)>>0)&0x3Fu)            /**< Get RfChnlNum from register */
#define  RF_TX_EN_SHIFT                                     6                             /**< Shift for RfTxEn */
#define  RF_TX_EN_MASK                                      0x00000040u                   /**< Mask for RfTxEn */
#define  RF_TX_EN_BMASK                                     0x1u                          /**< Base mask for RfTxEn */
#define  RF_TX_EN(x)                                        (((x)&0x1u)<<6)               /**< Set RfTxEn in register */
#define  GET_RF_TX_EN(reg)                                  (((reg)>>6)&0x1u)             /**< Get RfTxEn from register */
#define  RF_RX_EN_SHIFT                                     7                             /**< Shift for RfRxEn */
#define  RF_RX_EN_MASK                                      0x00000080u                   /**< Mask for RfRxEn */
#define  RF_RX_EN_BMASK                                     0x1u                          /**< Base mask for RfRxEn */
#define  RF_RX_EN(x)                                        (((x)&0x1u)<<7)               /**< Set RfRxEn in register */
#define  GET_RF_RX_EN(reg)                                  (((reg)>>7)&0x1u)             /**< Get RfRxEn from register */
#define  RF_RX_TIM_SEQ_SEL_SHIFT                            8                             /**< Shift for RfRxTimSeqSel */
#define  RF_RX_TIM_SEQ_SEL_MASK                             0x00000100u                   /**< Mask for RfRxTimSeqSel */
#define  RF_RX_TIM_SEQ_SEL_BMASK                            0x1u                          /**< Base mask for RfRxTimSeqSel */
#define  RF_RX_TIM_SEQ_SEL(x)                               (((x)&0x1u)<<8)               /**< Set RfRxTimSeqSel in register */
#define  GET_RF_RX_TIM_SEQ_SEL(reg)                         (((reg)>>8)&0x1u)             /**< Get RfRxTimSeqSel from register */
#define  RF_TX_TIM_SEQ_SEL_SHIFT                            9                             /**< Shift for RfTxTimSeqSel */
#define  RF_TX_TIM_SEQ_SEL_MASK                             0x00000200u                   /**< Mask for RfTxTimSeqSel */
#define  RF_TX_TIM_SEQ_SEL_BMASK                            0x1u                          /**< Base mask for RfTxTimSeqSel */
#define  RF_TX_TIM_SEQ_SEL(x)                               (((x)&0x1u)<<9)               /**< Set RfTxTimSeqSel in register */
#define  GET_RF_TX_TIM_SEQ_SEL(reg)                         (((reg)>>9)&0x1u)             /**< Get RfTxTimSeqSel from register */
#define  RF_FE_CTRIM_SHIFT                                  10                            /**< Shift for RfFeCtrim */
#define  RF_FE_CTRIM_MASK                                   0x00003C00u                   /**< Mask for RfFeCtrim */
#define  RF_FE_CTRIM_BMASK                                  0xFu                          /**< Base mask for RfFeCtrim */
#define  RF_FE_CTRIM(x)                                     (((x)&0xFu)<<10)              /**< Set RfFeCtrim in register */
#define  GET_RF_FE_CTRIM(reg)                               (((reg)>>10)&0xFu)            /**< Get RfFeCtrim from register */
/** @} */


/**
 * @name RegRfDebugTxrx1
 * @{
 */
// RegRfDebugTxrx1.r32
#define  REG_RF_DEBUG_TXRX1_RESET_VALUE                     0x00000290u                   /**< Reset value of RegRfDebugTxrx1 */
#define  REG_RF_DEBUG_TXRX1_MASK                            0x000003FFu                   /**< Mask for RegRfDebugTxrx1 */

#define  RF_BYPASS_TX_CG_SHIFT                              0                             /**< Shift for RfBypassTxCg */
#define  RF_BYPASS_TX_CG_MASK                               0x00000001u                   /**< Mask for RfBypassTxCg */
#define  RF_BYPASS_TX_CG_BMASK                              0x1u                          /**< Base mask for RfBypassTxCg */
#define  RF_BYPASS_TX_CG(x)                                 (((x)&0x1u)<<0)               /**< Set RfBypassTxCg in register */
#define  GET_RF_BYPASS_TX_CG(reg)                           (((reg)>>0)&0x1u)             /**< Get RfBypassTxCg from register */
#define  RF_BYPASS_RX_CG_SHIFT                              1                             /**< Shift for RfBypassRxCg */
#define  RF_BYPASS_RX_CG_MASK                               0x00000002u                   /**< Mask for RfBypassRxCg */
#define  RF_BYPASS_RX_CG_BMASK                              0x1u                          /**< Base mask for RfBypassRxCg */
#define  RF_BYPASS_RX_CG(x)                                 (((x)&0x1u)<<1)               /**< Set RfBypassRxCg in register */
#define  GET_RF_BYPASS_RX_CG(reg)                           (((reg)>>1)&0x1u)             /**< Get RfBypassRxCg from register */
#define  RF_EN_RSSI_ADC_DATA_SHIFT                          2                             /**< Shift for RfEnRssiAdcData */
#define  RF_EN_RSSI_ADC_DATA_MASK                           0x00000004u                   /**< Mask for RfEnRssiAdcData */
#define  RF_EN_RSSI_ADC_DATA_BMASK                          0x1u                          /**< Base mask for RfEnRssiAdcData */
#define  RF_EN_RSSI_ADC_DATA(x)                             (((x)&0x1u)<<2)               /**< Set RfEnRssiAdcData in register */
#define  GET_RF_EN_RSSI_ADC_DATA(reg)                       (((reg)>>2)&0x1u)             /**< Get RfEnRssiAdcData from register */
#define  RF_TX_BYP_FILT_OW_SHIFT                            3                             /**< Shift for RfTxBypFiltOw */
#define  RF_TX_BYP_FILT_OW_MASK                             0x00000008u                   /**< Mask for RfTxBypFiltOw */
#define  RF_TX_BYP_FILT_OW_BMASK                            0x1u                          /**< Base mask for RfTxBypFiltOw */
#define  RF_TX_BYP_FILT_OW(x)                               (((x)&0x1u)<<3)               /**< Set RfTxBypFiltOw in register */
#define  GET_RF_TX_BYP_FILT_OW(reg)                         (((reg)>>3)&0x1u)             /**< Get RfTxBypFiltOw from register */
#define  RF_TX_MSK_EN_OW_SHIFT                              4                             /**< Shift for RfTxMskEnOw */
#define  RF_TX_MSK_EN_OW_MASK                               0x00000010u                   /**< Mask for RfTxMskEnOw */
#define  RF_TX_MSK_EN_OW_BMASK                              0x1u                          /**< Base mask for RfTxMskEnOw */
#define  RF_TX_MSK_EN_OW(x)                                 (((x)&0x1u)<<4)               /**< Set RfTxMskEnOw in register */
#define  GET_RF_TX_MSK_EN_OW(reg)                           (((reg)>>4)&0x1u)             /**< Get RfTxMskEnOw from register */
#define  RF_TX_BYP_FILT_VAL_SHIFT                           5                             /**< Shift for RfTxBypFiltVal */
#define  RF_TX_BYP_FILT_VAL_MASK                            0x00000020u                   /**< Mask for RfTxBypFiltVal */
#define  RF_TX_BYP_FILT_VAL_BMASK                           0x1u                          /**< Base mask for RfTxBypFiltVal */
#define  RF_TX_BYP_FILT_VAL(x)                              (((x)&0x1u)<<5)               /**< Set RfTxBypFiltVal in register */
#define  GET_RF_TX_BYP_FILT_VAL(reg)                        (((reg)>>5)&0x1u)             /**< Get RfTxBypFiltVal from register */
#define  RF_TX_MSK_EN_VAL_SHIFT                             6                             /**< Shift for RfTxMskEnVal */
#define  RF_TX_MSK_EN_VAL_MASK                              0x00000040u                   /**< Mask for RfTxMskEnVal */
#define  RF_TX_MSK_EN_VAL_BMASK                             0x1u                          /**< Base mask for RfTxMskEnVal */
#define  RF_TX_MSK_EN_VAL(x)                                (((x)&0x1u)<<6)               /**< Set RfTxMskEnVal in register */
#define  GET_RF_TX_MSK_EN_VAL(reg)                          (((reg)>>6)&0x1u)             /**< Get RfTxMskEnVal from register */
#define  RF_SLOW_RSSI_TIME_SHIFT                            7                             /**< Shift for RfSlowRssiTime */
#define  RF_SLOW_RSSI_TIME_MASK                             0x00000180u                   /**< Mask for RfSlowRssiTime */
#define  RF_SLOW_RSSI_TIME_BMASK                            0x3u                          /**< Base mask for RfSlowRssiTime */
#define  RF_SLOW_RSSI_TIME(x)                               (((x)&0x3u)<<7)               /**< Set RfSlowRssiTime in register */
#define  GET_RF_SLOW_RSSI_TIME(reg)                         (((reg)>>7)&0x3u)             /**< Get RfSlowRssiTime from register */
#define  RF_EN_CH_POW_MEAS_SHIFT                            9                             /**< Shift for RfEnChPowMeas */
#define  RF_EN_CH_POW_MEAS_MASK                             0x00000200u                   /**< Mask for RfEnChPowMeas */
#define  RF_EN_CH_POW_MEAS_BMASK                            0x1u                          /**< Base mask for RfEnChPowMeas */
#define  RF_EN_CH_POW_MEAS(x)                               (((x)&0x1u)<<9)               /**< Set RfEnChPowMeas in register */
#define  GET_RF_EN_CH_POW_MEAS(reg)                         (((reg)>>9)&0x1u)             /**< Get RfEnChPowMeas from register */
/** @} */


/**
 * @name RegRfZbPdetCfg
 * @{
 */
// RegRfZbPdetCfg.r32
#define  REG_RF_ZB_PDET_CFG_RESET_VALUE                     0x00000438u                   /**< Reset value of RegRfZbPdetCfg */
#define  REG_RF_ZB_PDET_CFG_MASK                            0x00000FFFu                   /**< Mask for RegRfZbPdetCfg */

#define  RF_ZB_DIS_RST_PDET_ISFD_SHIFT                      0                             /**< Shift for RfZbDisRstPdetIsfd */
#define  RF_ZB_DIS_RST_PDET_ISFD_MASK                       0x00000001u                   /**< Mask for RfZbDisRstPdetIsfd */
#define  RF_ZB_DIS_RST_PDET_ISFD_BMASK                      0x1u                          /**< Base mask for RfZbDisRstPdetIsfd */
#define  RF_ZB_DIS_RST_PDET_ISFD(x)                         (((x)&0x1u)<<0)               /**< Set RfZbDisRstPdetIsfd in register */
#define  GET_RF_ZB_DIS_RST_PDET_ISFD(reg)                   (((reg)>>0)&0x1u)             /**< Get RfZbDisRstPdetIsfd from register */
#define  RF_ZB_DIS_RST_PDET_ESFD_SHIFT                      1                             /**< Shift for RfZbDisRstPdetEsfd */
#define  RF_ZB_DIS_RST_PDET_ESFD_MASK                       0x00000002u                   /**< Mask for RfZbDisRstPdetEsfd */
#define  RF_ZB_DIS_RST_PDET_ESFD_BMASK                      0x1u                          /**< Base mask for RfZbDisRstPdetEsfd */
#define  RF_ZB_DIS_RST_PDET_ESFD(x)                         (((x)&0x1u)<<1)               /**< Set RfZbDisRstPdetEsfd in register */
#define  GET_RF_ZB_DIS_RST_PDET_ESFD(reg)                   (((reg)>>1)&0x1u)             /**< Get RfZbDisRstPdetEsfd from register */
#define  RF_ZB_NUM_PDET_BEFORE_SFD_SHIFT                    2                             /**< Shift for RfZbNumPdetBeforeSfd */
#define  RF_ZB_NUM_PDET_BEFORE_SFD_MASK                     0x0000000Cu                   /**< Mask for RfZbNumPdetBeforeSfd */
#define  RF_ZB_NUM_PDET_BEFORE_SFD_BMASK                    0x3u                          /**< Base mask for RfZbNumPdetBeforeSfd */
#define  RF_ZB_NUM_PDET_BEFORE_SFD(x)                       (((x)&0x3u)<<2)               /**< Set RfZbNumPdetBeforeSfd in register */
#define  GET_RF_ZB_NUM_PDET_BEFORE_SFD(reg)                 (((reg)>>2)&0x3u)             /**< Get RfZbNumPdetBeforeSfd from register */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ISFD_SHIFT               4                             /**< Shift for RfZbNumSymbCntBeforeIsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ISFD_MASK                0x000000F0u                   /**< Mask for RfZbNumSymbCntBeforeIsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ISFD_BMASK               0xFu                          /**< Base mask for RfZbNumSymbCntBeforeIsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ISFD(x)                  (((x)&0xFu)<<4)               /**< Set RfZbNumSymbCntBeforeIsfd in register */
#define  GET_RF_ZB_NUM_SYMB_CNT_BEFORE_ISFD(reg)            (((reg)>>4)&0xFu)             /**< Get RfZbNumSymbCntBeforeIsfd from register */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ESFD_SHIFT               8                             /**< Shift for RfZbNumSymbCntBeforeEsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ESFD_MASK                0x00000F00u                   /**< Mask for RfZbNumSymbCntBeforeEsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ESFD_BMASK               0xFu                          /**< Base mask for RfZbNumSymbCntBeforeEsfd */
#define  RF_ZB_NUM_SYMB_CNT_BEFORE_ESFD(x)                  (((x)&0xFu)<<8)               /**< Set RfZbNumSymbCntBeforeEsfd in register */
#define  GET_RF_ZB_NUM_SYMB_CNT_BEFORE_ESFD(reg)            (((reg)>>8)&0xFu)             /**< Get RfZbNumSymbCntBeforeEsfd from register */
/** @} */


/**
 * @name RegRfRssi
 * @{
 */
// RegRfRssi.r32
#define  REG_RF_RSSI_RESET_VALUE                            0x00000000u                   /**< Reset value of RegRfRssi */
#define  REG_RF_RSSI_MASK                                   0x00007FFFu                   /**< Mask for RegRfRssi */

#define  RF_RSSI_SHIFT                                      0                             /**< Shift for RfRssi */
#define  RF_RSSI_MASK                                       0x000007FFu                   /**< Mask for RfRssi */
#define  RF_RSSI_BMASK                                      0x7FFu                        /**< Base mask for RfRssi */
#define  RF_RSSI(x)                                         (((x)&0x7FFu)<<0)             /**< Set RfRssi in register */
#define  GET_RF_RSSI(reg)                                   (((reg)>>0)&0x7FFu)           /**< Get RfRssi from register */
#define  RF_RX_GAIN_SHIFT                                   11                            /**< Shift for RfRxGain */
#define  RF_RX_GAIN_MASK                                    0x00003800u                   /**< Mask for RfRxGain */
#define  RF_RX_GAIN_BMASK                                   0x7u                          /**< Base mask for RfRxGain */
#define  RF_RX_GAIN(x)                                      (((x)&0x7u)<<11)              /**< Set RfRxGain in register */
#define  GET_RF_RX_GAIN(reg)                                (((reg)>>11)&0x7u)            /**< Get RfRxGain from register */
#define  RF_FILTERED_SHIFT                                  14                            /**< Shift for RfFiltered */
#define  RF_FILTERED_MASK                                   0x00004000u                   /**< Mask for RfFiltered */
#define  RF_FILTERED_BMASK                                  0x1u                          /**< Base mask for RfFiltered */
#define  RF_FILTERED(x)                                     (((x)&0x1u)<<14)              /**< Set RfFiltered in register */
#define  GET_RF_FILTERED(reg)                               (((reg)>>14)&0x1u)            /**< Get RfFiltered from register */
/** @} */


/**
 * @name RegRfRssiStart
 * @{
 */
// RegRfRssiStart.r32
#define  REG_RF_RSSI_START_RESET_VALUE                      0x00000002u                   /**< Reset value of RegRfRssiStart */
#define  REG_RF_RSSI_START_MASK                             0x00000FFFu                   /**< Mask for RegRfRssiStart */

#define  RF_RSSI_START_SHIFT                                0                             /**< Shift for RfRssiStart */
#define  RF_RSSI_START_MASK                                 0x00000FFFu                   /**< Mask for RfRssiStart */
#define  RF_RSSI_START_BMASK                                0xFFFu                        /**< Base mask for RfRssiStart */
#define  RF_RSSI_START(x)                                   (((x)&0xFFFu)<<0)             /**< Set RfRssiStart in register */
#define  GET_RF_RSSI_START(reg)                             (((reg)>>0)&0xFFFu)           /**< Get RfRssiStart from register */
/** @} */


/**
 * @name RegRfRssiStop
 * @{
 */
// RegRfRssiStop.r32
#define  REG_RF_RSSI_STOP_RESET_VALUE                       0x00000FFFu                   /**< Reset value of RegRfRssiStop */
#define  REG_RF_RSSI_STOP_MASK                              0x00000FFFu                   /**< Mask for RegRfRssiStop */

#define  RF_RSSI_STOP_SHIFT                                 0                             /**< Shift for RfRssiStop */
#define  RF_RSSI_STOP_MASK                                  0x00000FFFu                   /**< Mask for RfRssiStop */
#define  RF_RSSI_STOP_BMASK                                 0xFFFu                        /**< Base mask for RfRssiStop */
#define  RF_RSSI_STOP(x)                                    (((x)&0xFFFu)<<0)             /**< Set RfRssiStop in register */
#define  GET_RF_RSSI_STOP(reg)                              (((reg)>>0)&0xFFFu)           /**< Get RfRssiStop from register */
/** @} */


/**
 * @name RegRfRssiFilt
 * @{
 */
// RegRfRssiFilt.r32
#define  REG_RF_RSSI_FILT_RESET_VALUE                       0x00000003u                   /**< Reset value of RegRfRssiFilt */
#define  REG_RF_RSSI_FILT_MASK                              0x0000000Fu                   /**< Mask for RegRfRssiFilt */

#define  RF_ALPHA_EXP_SHIFT                                 0                             /**< Shift for RfAlphaExp */
#define  RF_ALPHA_EXP_MASK                                  0x0000000Fu                   /**< Mask for RfAlphaExp */
#define  RF_ALPHA_EXP_BMASK                                 0xFu                          /**< Base mask for RfAlphaExp */
#define  RF_ALPHA_EXP(x)                                    (((x)&0xFu)<<0)               /**< Set RfAlphaExp in register */
#define  GET_RF_ALPHA_EXP(reg)                              (((reg)>>0)&0xFu)             /**< Get RfAlphaExp from register */
/** @} */


/**
 * @name RegRfLrFreqCorrCfg
 * @{
 */
// RegRfLrFreqCorrCfg.r32
#define  REG_RF_LR_FREQ_CORR_CFG_RESET_VALUE                0x00008EB7u                   /**< Reset value of RegRfLrFreqCorrCfg */
#define  REG_RF_LR_FREQ_CORR_CFG_MASK                       0x0000FFFFu                   /**< Mask for RegRfLrFreqCorrCfg */

#define  RF_LR_LAMBDA_SHIFT                                 0                             /**< Shift for RfLrLambda */
#define  RF_LR_LAMBDA_MASK                                  0x00000007u                   /**< Mask for RfLrLambda */
#define  RF_LR_LAMBDA_BMASK                                 0x7u                          /**< Base mask for RfLrLambda */
#define  RF_LR_LAMBDA(x)                                    (((x)&0x7u)<<0)               /**< Set RfLrLambda in register */
#define  GET_RF_LR_LAMBDA(reg)                              (((reg)>>0)&0x7u)             /**< Get RfLrLambda from register */
#define  RF_LR_LAMBDA_INIT_SHIFT                            3                             /**< Shift for RfLrLambdaInit */
#define  RF_LR_LAMBDA_INIT_MASK                             0x00000038u                   /**< Mask for RfLrLambdaInit */
#define  RF_LR_LAMBDA_INIT_BMASK                            0x7u                          /**< Base mask for RfLrLambdaInit */
#define  RF_LR_LAMBDA_INIT(x)                               (((x)&0x7u)<<3)               /**< Set RfLrLambdaInit in register */
#define  GET_RF_LR_LAMBDA_INIT(reg)                         (((reg)>>3)&0x7u)             /**< Get RfLrLambdaInit from register */
#define  RF_LR_NUM_GEAR_SHIFT                               6                             /**< Shift for RfLrNumGear */
#define  RF_LR_NUM_GEAR_MASK                                0x000001C0u                   /**< Mask for RfLrNumGear */
#define  RF_LR_NUM_GEAR_BMASK                               0x7u                          /**< Base mask for RfLrNumGear */
#define  RF_LR_NUM_GEAR(x)                                  (((x)&0x7u)<<6)               /**< Set RfLrNumGear in register */
#define  GET_RF_LR_NUM_GEAR(reg)                            (((reg)>>6)&0x7u)             /**< Get RfLrNumGear from register */
#define  RF_LR_START_STEP_TIME_SHIFT                        9                             /**< Shift for RfLrStartStepTime */
#define  RF_LR_START_STEP_TIME_MASK                         0x00000E00u                   /**< Mask for RfLrStartStepTime */
#define  RF_LR_START_STEP_TIME_BMASK                        0x7u                          /**< Base mask for RfLrStartStepTime */
#define  RF_LR_START_STEP_TIME(x)                           (((x)&0x7u)<<9)               /**< Set RfLrStartStepTime in register */
#define  GET_RF_LR_START_STEP_TIME(reg)                     (((reg)>>9)&0x7u)             /**< Get RfLrStartStepTime from register */
#define  RF_LR_PD_TIMER_SHIFT                               12                            /**< Shift for RfLrPdTimer */
#define  RF_LR_PD_TIMER_MASK                                0x00003000u                   /**< Mask for RfLrPdTimer */
#define  RF_LR_PD_TIMER_BMASK                               0x3u                          /**< Base mask for RfLrPdTimer */
#define  RF_LR_PD_TIMER(x)                                  (((x)&0x3u)<<12)              /**< Set RfLrPdTimer in register */
#define  GET_RF_LR_PD_TIMER(reg)                            (((reg)>>12)&0x3u)            /**< Get RfLrPdTimer from register */
#define  RF_CHF_SEL_1M_SHIFT                                14                            /**< Shift for RfChfSel1M */
#define  RF_CHF_SEL_1M_MASK                                 0x00004000u                   /**< Mask for RfChfSel1M */
#define  RF_CHF_SEL_1M_BMASK                                0x1u                          /**< Base mask for RfChfSel1M */
#define  RF_CHF_SEL_1M(x)                                   (((x)&0x1u)<<14)              /**< Set RfChfSel1M in register */
#define  GET_RF_CHF_SEL_1M(reg)                             (((reg)>>14)&0x1u)            /**< Get RfChfSel1M from register */
#define  RF_CHF_SEL_2M_SHIFT                                15                            /**< Shift for RfChfSel2M */
#define  RF_CHF_SEL_2M_MASK                                 0x00008000u                   /**< Mask for RfChfSel2M */
#define  RF_CHF_SEL_2M_BMASK                                0x1u                          /**< Base mask for RfChfSel2M */
#define  RF_CHF_SEL_2M(x)                                   (((x)&0x1u)<<15)              /**< Set RfChfSel2M in register */
#define  GET_RF_CHF_SEL_2M(reg)                             (((reg)>>15)&0x1u)            /**< Get RfChfSel2M from register */
/** @} */


/**
 * @name RegRfLrTimRecCfg
 * @{
 */
// RegRfLrTimRecCfg.r32
#define  REG_RF_LR_TIM_REC_CFG_RESET_VALUE                  0x000071C4u                   /**< Reset value of RegRfLrTimRecCfg */
#define  REG_RF_LR_TIM_REC_CFG_MASK                         0x00007FFFu                   /**< Mask for RegRfLrTimRecCfg */

#define  RF_LR_TIM_EDGE_DEV_SHIFT                           0                             /**< Shift for RfLrTimEdgeDev */
#define  RF_LR_TIM_EDGE_DEV_MASK                            0x0000000Fu                   /**< Mask for RfLrTimEdgeDev */
#define  RF_LR_TIM_EDGE_DEV_BMASK                           0xFu                          /**< Base mask for RfLrTimEdgeDev */
#define  RF_LR_TIM_EDGE_DEV(x)                              (((x)&0xFu)<<0)               /**< Set RfLrTimEdgeDev in register */
#define  GET_RF_LR_TIM_EDGE_DEV(reg)                        (((reg)>>0)&0xFu)             /**< Get RfLrTimEdgeDev from register */
#define  RF_LR_ACC_EDGE_DEV_SHIFT                           4                             /**< Shift for RfLrAccEdgeDev */
#define  RF_LR_ACC_EDGE_DEV_MASK                            0x00000070u                   /**< Mask for RfLrAccEdgeDev */
#define  RF_LR_ACC_EDGE_DEV_BMASK                           0x7u                          /**< Base mask for RfLrAccEdgeDev */
#define  RF_LR_ACC_EDGE_DEV(x)                              (((x)&0x7u)<<4)               /**< Set RfLrAccEdgeDev in register */
#define  GET_RF_LR_ACC_EDGE_DEV(reg)                        (((reg)>>4)&0x7u)             /**< Get RfLrAccEdgeDev from register */
#define  RF_LR_TOT_EDGE_DEV_SHIFT                           7                             /**< Shift for RfLrTotEdgeDev */
#define  RF_LR_TOT_EDGE_DEV_MASK                            0x00000380u                   /**< Mask for RfLrTotEdgeDev */
#define  RF_LR_TOT_EDGE_DEV_BMASK                           0x7u                          /**< Base mask for RfLrTotEdgeDev */
#define  RF_LR_TOT_EDGE_DEV(x)                              (((x)&0x7u)<<7)               /**< Set RfLrTotEdgeDev in register */
#define  GET_RF_LR_TOT_EDGE_DEV(reg)                        (((reg)>>7)&0x7u)             /**< Get RfLrTotEdgeDev from register */
#define  RF_LR_RXC_PDET_THRESH_SHIFT                        10                            /**< Shift for RfLrRxcPdetThresh */
#define  RF_LR_RXC_PDET_THRESH_MASK                         0x00007C00u                   /**< Mask for RfLrRxcPdetThresh */
#define  RF_LR_RXC_PDET_THRESH_BMASK                        0x1Fu                         /**< Base mask for RfLrRxcPdetThresh */
#define  RF_LR_RXC_PDET_THRESH(x)                           (((x)&0x1Fu)<<10)             /**< Set RfLrRxcPdetThresh in register */
#define  GET_RF_LR_RXC_PDET_THRESH(reg)                     (((reg)>>10)&0x1Fu)           /**< Get RfLrRxcPdetThresh from register */
/** @} */


/**
 * @name RegRfZbFreqCorrCfg
 * @{
 */
// RegRfZbFreqCorrCfg.r32
#define  REG_RF_ZB_FREQ_CORR_CFG_RESET_VALUE                0x00001C95u                   /**< Reset value of RegRfZbFreqCorrCfg */
#define  REG_RF_ZB_FREQ_CORR_CFG_MASK                       0x00001FFFu                   /**< Mask for RegRfZbFreqCorrCfg */

#define  RF_ZB_LAMBDA_SHIFT                                 0                             /**< Shift for RfZbLambda */
#define  RF_ZB_LAMBDA_MASK                                  0x00000007u                   /**< Mask for RfZbLambda */
#define  RF_ZB_LAMBDA_BMASK                                 0x7u                          /**< Base mask for RfZbLambda */
#define  RF_ZB_LAMBDA(x)                                    (((x)&0x7u)<<0)               /**< Set RfZbLambda in register */
#define  GET_RF_ZB_LAMBDA(reg)                              (((reg)>>0)&0x7u)             /**< Get RfZbLambda from register */
#define  RF_ZB_LAMBDA_INIT_SHIFT                            3                             /**< Shift for RfZbLambdaInit */
#define  RF_ZB_LAMBDA_INIT_MASK                             0x00000038u                   /**< Mask for RfZbLambdaInit */
#define  RF_ZB_LAMBDA_INIT_BMASK                            0x7u                          /**< Base mask for RfZbLambdaInit */
#define  RF_ZB_LAMBDA_INIT(x)                               (((x)&0x7u)<<3)               /**< Set RfZbLambdaInit in register */
#define  GET_RF_ZB_LAMBDA_INIT(reg)                         (((reg)>>3)&0x7u)             /**< Get RfZbLambdaInit from register */
#define  RF_ZB_NUM_GEAR_SHIFT                               6                             /**< Shift for RfZbNumGear */
#define  RF_ZB_NUM_GEAR_MASK                                0x000001C0u                   /**< Mask for RfZbNumGear */
#define  RF_ZB_NUM_GEAR_BMASK                               0x7u                          /**< Base mask for RfZbNumGear */
#define  RF_ZB_NUM_GEAR(x)                                  (((x)&0x7u)<<6)               /**< Set RfZbNumGear in register */
#define  GET_RF_ZB_NUM_GEAR(reg)                            (((reg)>>6)&0x7u)             /**< Get RfZbNumGear from register */
#define  RF_ZB_START_STEP_TIME_SHIFT                        9                             /**< Shift for RfZbStartStepTime */
#define  RF_ZB_START_STEP_TIME_MASK                         0x00000E00u                   /**< Mask for RfZbStartStepTime */
#define  RF_ZB_START_STEP_TIME_BMASK                        0x7u                          /**< Base mask for RfZbStartStepTime */
#define  RF_ZB_START_STEP_TIME(x)                           (((x)&0x7u)<<9)               /**< Set RfZbStartStepTime in register */
#define  GET_RF_ZB_START_STEP_TIME(reg)                     (((reg)>>9)&0x7u)             /**< Get RfZbStartStepTime from register */
#define  RF_SEIZE_ZB_INIT_DC_ON_COUNT_SHIFT                 12                            /**< Shift for RfSeizeZbInitDcOnCount */
#define  RF_SEIZE_ZB_INIT_DC_ON_COUNT_MASK                  0x00001000u                   /**< Mask for RfSeizeZbInitDcOnCount */
#define  RF_SEIZE_ZB_INIT_DC_ON_COUNT_BMASK                 0x1u                          /**< Base mask for RfSeizeZbInitDcOnCount */
#define  RF_SEIZE_ZB_INIT_DC_ON_COUNT(x)                    (((x)&0x1u)<<12)              /**< Set RfSeizeZbInitDcOnCount in register */
#define  GET_RF_SEIZE_ZB_INIT_DC_ON_COUNT(reg)              (((reg)>>12)&0x1u)            /**< Get RfSeizeZbInitDcOnCount from register */
/** @} */


/**
 * @name RegRfZbThrCfg
 * @{
 */
// RegRfZbThrCfg.r32
#define  REG_RF_ZB_THR_CFG_RESET_VALUE                      0x000000C8u                   /**< Reset value of RegRfZbThrCfg */
#define  REG_RF_ZB_THR_CFG_MASK                             0x000001FFu                   /**< Mask for RegRfZbThrCfg */

#define  RF_ZB_CORR_THR_SHIFT                               0                             /**< Shift for RfZbCorrThr */
#define  RF_ZB_CORR_THR_MASK                                0x000000FFu                   /**< Mask for RfZbCorrThr */
#define  RF_ZB_CORR_THR_BMASK                               0xFFu                         /**< Base mask for RfZbCorrThr */
#define  RF_ZB_CORR_THR(x)                                  (((x)&0xFFu)<<0)              /**< Set RfZbCorrThr in register */
#define  GET_RF_ZB_CORR_THR(reg)                            (((reg)>>0)&0xFFu)            /**< Get RfZbCorrThr from register */
#define  RF_ZB_SFB_FRM_LL_SHIFT                             8                             /**< Shift for RfZbSfbFrmLl */
#define  RF_ZB_SFB_FRM_LL_MASK                              0x00000100u                   /**< Mask for RfZbSfbFrmLl */
#define  RF_ZB_SFB_FRM_LL_BMASK                             0x1u                          /**< Base mask for RfZbSfbFrmLl */
#define  RF_ZB_SFB_FRM_LL(x)                                (((x)&0x1u)<<8)               /**< Set RfZbSfbFrmLl in register */
#define  GET_RF_ZB_SFB_FRM_LL(reg)                          (((reg)>>8)&0x1u)             /**< Get RfZbSfbFrmLl from register */
/** @} */


/**
 * @name RegRfModeCfgRx2
 * @{
 */
// RegRfModeCfgRx2.r32
#define  REG_RF_MODE_CFG_RX2_RESET_VALUE                    0x00000081u                   /**< Reset value of RegRfModeCfgRx2 */
#define  REG_RF_MODE_CFG_RX2_MASK                           0x000001FFu                   /**< Mask for RegRfModeCfgRx2 */

#define  RF_ZB_EN_MEDIAN_FILT_SHIFT                         0                             /**< Shift for RfZbEnMedianFilt */
#define  RF_ZB_EN_MEDIAN_FILT_MASK                          0x00000001u                   /**< Mask for RfZbEnMedianFilt */
#define  RF_ZB_EN_MEDIAN_FILT_BMASK                         0x1u                          /**< Base mask for RfZbEnMedianFilt */
#define  RF_ZB_EN_MEDIAN_FILT(x)                            (((x)&0x1u)<<0)               /**< Set RfZbEnMedianFilt in register */
#define  GET_RF_ZB_EN_MEDIAN_FILT(reg)                      (((reg)>>0)&0x1u)             /**< Get RfZbEnMedianFilt from register */
#define  RF_ZB_EN_FM_SPIKE_LIM_SHIFT                        1                             /**< Shift for RfZbEnFmSpikeLim */
#define  RF_ZB_EN_FM_SPIKE_LIM_MASK                         0x00000002u                   /**< Mask for RfZbEnFmSpikeLim */
#define  RF_ZB_EN_FM_SPIKE_LIM_BMASK                        0x1u                          /**< Base mask for RfZbEnFmSpikeLim */
#define  RF_ZB_EN_FM_SPIKE_LIM(x)                           (((x)&0x1u)<<1)               /**< Set RfZbEnFmSpikeLim in register */
#define  GET_RF_ZB_EN_FM_SPIKE_LIM(reg)                     (((reg)>>1)&0x1u)             /**< Get RfZbEnFmSpikeLim from register */
#define  RF_ZB_EN_SPIKE_POST_PDET_SHIFT                     2                             /**< Shift for RfZbEnSpikePostPdet */
#define  RF_ZB_EN_SPIKE_POST_PDET_MASK                      0x00000004u                   /**< Mask for RfZbEnSpikePostPdet */
#define  RF_ZB_EN_SPIKE_POST_PDET_BMASK                     0x1u                          /**< Base mask for RfZbEnSpikePostPdet */
#define  RF_ZB_EN_SPIKE_POST_PDET(x)                        (((x)&0x1u)<<2)               /**< Set RfZbEnSpikePostPdet in register */
#define  GET_RF_ZB_EN_SPIKE_POST_PDET(reg)                  (((reg)>>2)&0x1u)             /**< Get RfZbEnSpikePostPdet from register */
#define  RF_BLE_EN_MEDIAN_FILT_SHIFT                        3                             /**< Shift for RfBleEnMedianFilt */
#define  RF_BLE_EN_MEDIAN_FILT_MASK                         0x00000008u                   /**< Mask for RfBleEnMedianFilt */
#define  RF_BLE_EN_MEDIAN_FILT_BMASK                        0x1u                          /**< Base mask for RfBleEnMedianFilt */
#define  RF_BLE_EN_MEDIAN_FILT(x)                           (((x)&0x1u)<<3)               /**< Set RfBleEnMedianFilt in register */
#define  GET_RF_BLE_EN_MEDIAN_FILT(reg)                     (((reg)>>3)&0x1u)             /**< Get RfBleEnMedianFilt from register */
#define  RF_BLE_EN_FM_SPIKE_LIM_SHIFT                       4                             /**< Shift for RfBleEnFmSpikeLim */
#define  RF_BLE_EN_FM_SPIKE_LIM_MASK                        0x00000010u                   /**< Mask for RfBleEnFmSpikeLim */
#define  RF_BLE_EN_FM_SPIKE_LIM_BMASK                       0x1u                          /**< Base mask for RfBleEnFmSpikeLim */
#define  RF_BLE_EN_FM_SPIKE_LIM(x)                          (((x)&0x1u)<<4)               /**< Set RfBleEnFmSpikeLim in register */
#define  GET_RF_BLE_EN_FM_SPIKE_LIM(reg)                    (((reg)>>4)&0x1u)             /**< Get RfBleEnFmSpikeLim from register */
#define  RF_BLE_EN_SPIKE_POST_PDET_SHIFT                    5                             /**< Shift for RfBleEnSpikePostPdet */
#define  RF_BLE_EN_SPIKE_POST_PDET_MASK                     0x00000020u                   /**< Mask for RfBleEnSpikePostPdet */
#define  RF_BLE_EN_SPIKE_POST_PDET_BMASK                    0x1u                          /**< Base mask for RfBleEnSpikePostPdet */
#define  RF_BLE_EN_SPIKE_POST_PDET(x)                       (((x)&0x1u)<<5)               /**< Set RfBleEnSpikePostPdet in register */
#define  GET_RF_BLE_EN_SPIKE_POST_PDET(reg)                 (((reg)>>5)&0x1u)             /**< Get RfBleEnSpikePostPdet from register */
#define  RF_LR_EN_MEDIAN_FILT_SHIFT                         6                             /**< Shift for RfLrEnMedianFilt */
#define  RF_LR_EN_MEDIAN_FILT_MASK                          0x00000040u                   /**< Mask for RfLrEnMedianFilt */
#define  RF_LR_EN_MEDIAN_FILT_BMASK                         0x1u                          /**< Base mask for RfLrEnMedianFilt */
#define  RF_LR_EN_MEDIAN_FILT(x)                            (((x)&0x1u)<<6)               /**< Set RfLrEnMedianFilt in register */
#define  GET_RF_LR_EN_MEDIAN_FILT(reg)                      (((reg)>>6)&0x1u)             /**< Get RfLrEnMedianFilt from register */
#define  RF_LR_EN_FM_SPIKE_LIM_SHIFT                        7                             /**< Shift for RfLrEnFmSpikeLim */
#define  RF_LR_EN_FM_SPIKE_LIM_MASK                         0x00000080u                   /**< Mask for RfLrEnFmSpikeLim */
#define  RF_LR_EN_FM_SPIKE_LIM_BMASK                        0x1u                          /**< Base mask for RfLrEnFmSpikeLim */
#define  RF_LR_EN_FM_SPIKE_LIM(x)                           (((x)&0x1u)<<7)               /**< Set RfLrEnFmSpikeLim in register */
#define  GET_RF_LR_EN_FM_SPIKE_LIM(reg)                     (((reg)>>7)&0x1u)             /**< Get RfLrEnFmSpikeLim from register */
#define  RF_LR_EN_SPIKE_POST_PDET_SHIFT                     8                             /**< Shift for RfLrEnSpikePostPdet */
#define  RF_LR_EN_SPIKE_POST_PDET_MASK                      0x00000100u                   /**< Mask for RfLrEnSpikePostPdet */
#define  RF_LR_EN_SPIKE_POST_PDET_BMASK                     0x1u                          /**< Base mask for RfLrEnSpikePostPdet */
#define  RF_LR_EN_SPIKE_POST_PDET(x)                        (((x)&0x1u)<<8)               /**< Set RfLrEnSpikePostPdet in register */
#define  GET_RF_LR_EN_SPIKE_POST_PDET(reg)                  (((reg)>>8)&0x1u)             /**< Get RfLrEnSpikePostPdet from register */
/** @} */


/**
 * @name RegRfTxrxDbg1
 * @{
 */
// RegRfTxrxDbg1.r32
#define  REG_RF_TXRX_DBG1_RESET_VALUE                       0x00000014u                   /**< Reset value of RegRfTxrxDbg1 */
#define  REG_RF_TXRX_DBG1_MASK                              0x0000FFFFu                   /**< Mask for RegRfTxrxDbg1 */

#define  RF_RX_DATA_INVERT_SHIFT                            0                             /**< Shift for RfRxDataInvert */
#define  RF_RX_DATA_INVERT_MASK                             0x00000001u                   /**< Mask for RfRxDataInvert */
#define  RF_RX_DATA_INVERT_BMASK                            0x1u                          /**< Base mask for RfRxDataInvert */
#define  RF_RX_DATA_INVERT(x)                               (((x)&0x1u)<<0)               /**< Set RfRxDataInvert in register */
#define  GET_RF_RX_DATA_INVERT(reg)                         (((reg)>>0)&0x1u)             /**< Get RfRxDataInvert from register */
#define  RF_AGC_DISABLE_SHIFT                               1                             /**< Shift for RfAgcDisable */
#define  RF_AGC_DISABLE_MASK                                0x00000002u                   /**< Mask for RfAgcDisable */
#define  RF_AGC_DISABLE_BMASK                               0x1u                          /**< Base mask for RfAgcDisable */
#define  RF_AGC_DISABLE(x)                                  (((x)&0x1u)<<1)               /**< Set RfAgcDisable in register */
#define  GET_RF_AGC_DISABLE(reg)                            (((reg)>>1)&0x1u)             /**< Get RfAgcDisable from register */
#define  RF_RX_GAIN_DUPLICITE_SHIFT                         2                             /**< Shift for RfRxGainDuplicite */
#define  RF_RX_GAIN_DUPLICITE_MASK                          0x0000001Cu                   /**< Mask for RfRxGainDuplicite */
#define  RF_RX_GAIN_DUPLICITE_BMASK                         0x7u                          /**< Base mask for RfRxGainDuplicite */
#define  RF_RX_GAIN_DUPLICITE(x)                            (((x)&0x7u)<<2)               /**< Set RfRxGainDuplicite in register */
#define  GET_RF_RX_GAIN_DUPLICITE(reg)                      (((reg)>>2)&0x7u)             /**< Get RfRxGainDuplicite from register */
#define  RF_ADC_IQ_SWAP_SHIFT                               5                             /**< Shift for RfAdcIqSwap */
#define  RF_ADC_IQ_SWAP_MASK                                0x00000020u                   /**< Mask for RfAdcIqSwap */
#define  RF_ADC_IQ_SWAP_BMASK                               0x1u                          /**< Base mask for RfAdcIqSwap */
#define  RF_ADC_IQ_SWAP(x)                                  (((x)&0x1u)<<5)               /**< Set RfAdcIqSwap in register */
#define  GET_RF_ADC_IQ_SWAP(reg)                            (((reg)>>5)&0x1u)             /**< Get RfAdcIqSwap from register */
#define  RF_INVERT_CLK_DSM_SHIFT                            6                             /**< Shift for RfInvertClkDsm */
#define  RF_INVERT_CLK_DSM_MASK                             0x00000040u                   /**< Mask for RfInvertClkDsm */
#define  RF_INVERT_CLK_DSM_BMASK                            0x1u                          /**< Base mask for RfInvertClkDsm */
#define  RF_INVERT_CLK_DSM(x)                               (((x)&0x1u)<<6)               /**< Set RfInvertClkDsm in register */
#define  GET_RF_INVERT_CLK_DSM(reg)                         (((reg)>>6)&0x1u)             /**< Get RfInvertClkDsm from register */
#define  RF_DSM_FRAC_LSW_SHIFT                              7                             /**< Shift for RfDsmFracLsw */
#define  RF_DSM_FRAC_LSW_MASK                               0x00000380u                   /**< Mask for RfDsmFracLsw */
#define  RF_DSM_FRAC_LSW_BMASK                              0x7u                          /**< Base mask for RfDsmFracLsw */
#define  RF_DSM_FRAC_LSW(x)                                 (((x)&0x7u)<<7)               /**< Set RfDsmFracLsw in register */
#define  GET_RF_DSM_FRAC_LSW(reg)                           (((reg)>>7)&0x7u)             /**< Get RfDsmFracLsw from register */
#define  RF_FR_2M_NOISE_TH_SHIFT                            10                            /**< Shift for RfFr2MNoiseTh */
#define  RF_FR_2M_NOISE_TH_MASK                             0x00000400u                   /**< Mask for RfFr2MNoiseTh */
#define  RF_FR_2M_NOISE_TH_BMASK                            0x1u                          /**< Base mask for RfFr2MNoiseTh */
#define  RF_FR_2M_NOISE_TH(x)                               (((x)&0x1u)<<10)              /**< Set RfFr2MNoiseTh in register */
#define  GET_RF_FR_2M_NOISE_TH(reg)                         (((reg)>>10)&0x1u)            /**< Get RfFr2MNoiseTh from register */
#define  RF_AM_OVERRIDE_EN_SHIFT                            11                            /**< Shift for RfAmOverrideEn */
#define  RF_AM_OVERRIDE_EN_MASK                             0x00000800u                   /**< Mask for RfAmOverrideEn */
#define  RF_AM_OVERRIDE_EN_BMASK                            0x1u                          /**< Base mask for RfAmOverrideEn */
#define  RF_AM_OVERRIDE_EN(x)                               (((x)&0x1u)<<11)              /**< Set RfAmOverrideEn in register */
#define  GET_RF_AM_OVERRIDE_EN(reg)                         (((reg)>>11)&0x1u)            /**< Get RfAmOverrideEn from register */
#define  RF_AM_OVERRIDE_VAL_SHIFT                           12                            /**< Shift for RfAmOverrideVal */
#define  RF_AM_OVERRIDE_VAL_MASK                            0x00001000u                   /**< Mask for RfAmOverrideVal */
#define  RF_AM_OVERRIDE_VAL_BMASK                           0x1u                          /**< Base mask for RfAmOverrideVal */
#define  RF_AM_OVERRIDE_VAL(x)                              (((x)&0x1u)<<12)              /**< Set RfAmOverrideVal in register */
#define  GET_RF_AM_OVERRIDE_VAL(reg)                        (((reg)>>12)&0x1u)            /**< Get RfAmOverrideVal from register */
#define  RF_LOAD_PREV_GAIN_SHIFT                            13                            /**< Shift for RfLoadPrevGain */
#define  RF_LOAD_PREV_GAIN_MASK                             0x00002000u                   /**< Mask for RfLoadPrevGain */
#define  RF_LOAD_PREV_GAIN_BMASK                            0x1u                          /**< Base mask for RfLoadPrevGain */
#define  RF_LOAD_PREV_GAIN(x)                               (((x)&0x1u)<<13)              /**< Set RfLoadPrevGain in register */
#define  GET_RF_LOAD_PREV_GAIN(reg)                         (((reg)>>13)&0x1u)            /**< Get RfLoadPrevGain from register */
#define  RF_ADC_CLIP_EN_SHIFT                               14                            /**< Shift for RfAdcClipEn */
#define  RF_ADC_CLIP_EN_MASK                                0x00004000u                   /**< Mask for RfAdcClipEn */
#define  RF_ADC_CLIP_EN_BMASK                               0x1u                          /**< Base mask for RfAdcClipEn */
#define  RF_ADC_CLIP_EN(x)                                  (((x)&0x1u)<<14)              /**< Set RfAdcClipEn in register */
#define  GET_RF_ADC_CLIP_EN(reg)                            (((reg)>>14)&0x1u)            /**< Get RfAdcClipEn from register */
#define  RF_BYPASS_PDET_CG_SHIFT                            15                            /**< Shift for RfBypassPdetCg */
#define  RF_BYPASS_PDET_CG_MASK                             0x00008000u                   /**< Mask for RfBypassPdetCg */
#define  RF_BYPASS_PDET_CG_BMASK                            0x1u                          /**< Base mask for RfBypassPdetCg */
#define  RF_BYPASS_PDET_CG(x)                               (((x)&0x1u)<<15)              /**< Set RfBypassPdetCg in register */
#define  GET_RF_BYPASS_PDET_CG(reg)                         (((reg)>>15)&0x1u)            /**< Get RfBypassPdetCg from register */
/** @} */


/**
 * @name RegRfTxrxDbg2
 * @{
 */
// RegRfTxrxDbg2.r32
#define  REG_RF_TXRX_DBG2_RESET_VALUE                       0x00000064u                   /**< Reset value of RegRfTxrxDbg2 */
#define  REG_RF_TXRX_DBG2_MASK                              0x00000FFFu                   /**< Mask for RegRfTxrxDbg2 */

#define  RF_CHNL_POW_CH_PDET_RST_EN_SHIFT                   0                             /**< Shift for RfChnlPowChPdetRstEn */
#define  RF_CHNL_POW_CH_PDET_RST_EN_MASK                    0x00000001u                   /**< Mask for RfChnlPowChPdetRstEn */
#define  RF_CHNL_POW_CH_PDET_RST_EN_BMASK                   0x1u                          /**< Base mask for RfChnlPowChPdetRstEn */
#define  RF_CHNL_POW_CH_PDET_RST_EN(x)                      (((x)&0x1u)<<0)               /**< Set RfChnlPowChPdetRstEn in register */
#define  GET_RF_CHNL_POW_CH_PDET_RST_EN(reg)                (((reg)>>0)&0x1u)             /**< Get RfChnlPowChPdetRstEn from register */
#define  RF_CHNL_POW_CH_PDET_RST_VAL_SHIFT                  1                             /**< Shift for RfChnlPowChPdetRstVal */
#define  RF_CHNL_POW_CH_PDET_RST_VAL_MASK                   0x00000002u                   /**< Mask for RfChnlPowChPdetRstVal */
#define  RF_CHNL_POW_CH_PDET_RST_VAL_BMASK                  0x1u                          /**< Base mask for RfChnlPowChPdetRstVal */
#define  RF_CHNL_POW_CH_PDET_RST_VAL(x)                     (((x)&0x1u)<<1)               /**< Set RfChnlPowChPdetRstVal in register */
#define  GET_RF_CHNL_POW_CH_PDET_RST_VAL(reg)               (((reg)>>1)&0x1u)             /**< Get RfChnlPowChPdetRstVal from register */
#define  RF_RX_AMP_SETL_TIME_SHIFT                          2                             /**< Shift for RfRxAmpSetlTime */
#define  RF_RX_AMP_SETL_TIME_MASK                           0x0000000Cu                   /**< Mask for RfRxAmpSetlTime */
#define  RF_RX_AMP_SETL_TIME_BMASK                          0x3u                          /**< Base mask for RfRxAmpSetlTime */
#define  RF_RX_AMP_SETL_TIME(x)                             (((x)&0x3u)<<2)               /**< Set RfRxAmpSetlTime in register */
#define  GET_RF_RX_AMP_SETL_TIME(reg)                       (((reg)>>2)&0x3u)             /**< Get RfRxAmpSetlTime from register */
#define  RF_TH_AVG_COUNT_SHIFT                              4                             /**< Shift for RfThAvgCount */
#define  RF_TH_AVG_COUNT_MASK                               0x00000030u                   /**< Mask for RfThAvgCount */
#define  RF_TH_AVG_COUNT_BMASK                              0x3u                          /**< Base mask for RfThAvgCount */
#define  RF_TH_AVG_COUNT(x)                                 (((x)&0x3u)<<4)               /**< Set RfThAvgCount in register */
#define  GET_RF_TH_AVG_COUNT(reg)                           (((reg)>>4)&0x3u)             /**< Get RfThAvgCount from register */
#define  RF_CRSSI_CH_THN_SHIFT                              6                             /**< Shift for RfCrssiChThn */
#define  RF_CRSSI_CH_THN_MASK                               0x00000040u                   /**< Mask for RfCrssiChThn */
#define  RF_CRSSI_CH_THN_BMASK                              0x1u                          /**< Base mask for RfCrssiChThn */
#define  RF_CRSSI_CH_THN(x)                                 (((x)&0x1u)<<6)               /**< Set RfCrssiChThn in register */
#define  GET_RF_CRSSI_CH_THN(reg)                           (((reg)>>6)&0x1u)             /**< Get RfCrssiChThn from register */
#define  RF_SRSSI_CH_TH_SHIFT                               7                             /**< Shift for RfSrssiChTh */
#define  RF_SRSSI_CH_TH_MASK                                0x00000180u                   /**< Mask for RfSrssiChTh */
#define  RF_SRSSI_CH_TH_BMASK                               0x3u                          /**< Base mask for RfSrssiChTh */
#define  RF_SRSSI_CH_TH(x)                                  (((x)&0x3u)<<7)               /**< Set RfSrssiChTh in register */
#define  GET_RF_SRSSI_CH_TH(reg)                            (((reg)>>7)&0x3u)             /**< Get RfSrssiChTh from register */
#define  RF_CRSSI_CH_THP_SHIFT                              9                             /**< Shift for RfCrssiChThp */
#define  RF_CRSSI_CH_THP_MASK                               0x00000600u                   /**< Mask for RfCrssiChThp */
#define  RF_CRSSI_CH_THP_BMASK                              0x3u                          /**< Base mask for RfCrssiChThp */
#define  RF_CRSSI_CH_THP(x)                                 (((x)&0x3u)<<9)               /**< Set RfCrssiChThp in register */
#define  GET_RF_CRSSI_CH_THP(reg)                           (((reg)>>9)&0x3u)             /**< Get RfCrssiChThp from register */
#define  RF_FAST_RSSI_CLIP_SETTING_SHIFT                    11                            /**< Shift for RfFastRssiClipSetting */
#define  RF_FAST_RSSI_CLIP_SETTING_MASK                     0x00000800u                   /**< Mask for RfFastRssiClipSetting */
#define  RF_FAST_RSSI_CLIP_SETTING_BMASK                    0x1u                          /**< Base mask for RfFastRssiClipSetting */
#define  RF_FAST_RSSI_CLIP_SETTING(x)                       (((x)&0x1u)<<11)              /**< Set RfFastRssiClipSetting in register */
#define  GET_RF_FAST_RSSI_CLIP_SETTING(reg)                 (((reg)>>11)&0x1u)            /**< Get RfFastRssiClipSetting from register */
/** @} */


/**
 * @name RegRfTxrxDbg3
 * @{
 */
// RegRfTxrxDbg3.r32
#define  REG_RF_TXRX_DBG3_RESET_VALUE                       0x00002620u                   /**< Reset value of RegRfTxrxDbg3 */
#define  REG_RF_TXRX_DBG3_MASK                              0x0000FFFFu                   /**< Mask for RegRfTxrxDbg3 */

#define  RF_CHNL_FREQ_DIRECT_SHIFT                          0                             /**< Shift for RfChnlFreqDirect */
#define  RF_CHNL_FREQ_DIRECT_MASK                           0x00000001u                   /**< Mask for RfChnlFreqDirect */
#define  RF_CHNL_FREQ_DIRECT_BMASK                          0x1u                          /**< Base mask for RfChnlFreqDirect */
#define  RF_CHNL_FREQ_DIRECT(x)                             (((x)&0x1u)<<0)               /**< Set RfChnlFreqDirect in register */
#define  GET_RF_CHNL_FREQ_DIRECT(reg)                       (((reg)>>0)&0x1u)             /**< Get RfChnlFreqDirect from register */
#define  RF_CHNL_FREQ_SHIFT                                 1                             /**< Shift for RfChnlFreq */
#define  RF_CHNL_FREQ_MASK                                  0x00003FFEu                   /**< Mask for RfChnlFreq */
#define  RF_CHNL_FREQ_BMASK                                 0x1FFFu                       /**< Base mask for RfChnlFreq */
#define  RF_CHNL_FREQ(x)                                    (((x)&0x1FFFu)<<1)            /**< Set RfChnlFreq in register */
#define  GET_RF_CHNL_FREQ(reg)                              (((reg)>>1)&0x1FFFu)          /**< Get RfChnlFreq from register */
#define  RF_DSM_DITHER_DISABLE_SHIFT                        14                            /**< Shift for RfDsmDitherDisable */
#define  RF_DSM_DITHER_DISABLE_MASK                         0x00004000u                   /**< Mask for RfDsmDitherDisable */
#define  RF_DSM_DITHER_DISABLE_BMASK                        0x1u                          /**< Base mask for RfDsmDitherDisable */
#define  RF_DSM_DITHER_DISABLE(x)                           (((x)&0x1u)<<14)              /**< Set RfDsmDitherDisable in register */
#define  GET_RF_DSM_DITHER_DISABLE(reg)                     (((reg)>>14)&0x1u)            /**< Get RfDsmDitherDisable from register */
#define  RF_DSM_INT_MODE_SHIFT                              15                            /**< Shift for RfDsmIntMode */
#define  RF_DSM_INT_MODE_MASK                               0x00008000u                   /**< Mask for RfDsmIntMode */
#define  RF_DSM_INT_MODE_BMASK                              0x1u                          /**< Base mask for RfDsmIntMode */
#define  RF_DSM_INT_MODE(x)                                 (((x)&0x1u)<<15)              /**< Set RfDsmIntMode in register */
#define  GET_RF_DSM_INT_MODE(reg)                           (((reg)>>15)&0x1u)            /**< Get RfDsmIntMode from register */
/** @} */


/**
 * @name RegRfTxrxDbg4
 * @{
 */
// RegRfTxrxDbg4.r32
#define  REG_RF_TXRX_DBG4_RESET_VALUE                       0x00008903u                   /**< Reset value of RegRfTxrxDbg4 */
#define  REG_RF_TXRX_DBG4_MASK                              0x0000FFFFu                   /**< Mask for RegRfTxrxDbg4 */

#define  RF_TXC_LPM_DELAY_SHIFT                             0                             /**< Shift for RfTxcLpmDelay */
#define  RF_TXC_LPM_DELAY_MASK                              0x00000007u                   /**< Mask for RfTxcLpmDelay */
#define  RF_TXC_LPM_DELAY_BMASK                             0x7u                          /**< Base mask for RfTxcLpmDelay */
#define  RF_TXC_LPM_DELAY(x)                                (((x)&0x7u)<<0)               /**< Set RfTxcLpmDelay in register */
#define  GET_RF_TXC_LPM_DELAY(reg)                          (((reg)>>0)&0x7u)             /**< Get RfTxcLpmDelay from register */
#define  RF_AGC_SRSSI_COMP_SEL_SHIFT                        3                             /**< Shift for RfAgcSrssiCompSel */
#define  RF_AGC_SRSSI_COMP_SEL_MASK                         0x00000008u                   /**< Mask for RfAgcSrssiCompSel */
#define  RF_AGC_SRSSI_COMP_SEL_BMASK                        0x1u                          /**< Base mask for RfAgcSrssiCompSel */
#define  RF_AGC_SRSSI_COMP_SEL(x)                           (((x)&0x1u)<<3)               /**< Set RfAgcSrssiCompSel in register */
#define  GET_RF_AGC_SRSSI_COMP_SEL(reg)                     (((reg)>>3)&0x1u)             /**< Get RfAgcSrssiCompSel from register */
#define  RF_TXC_MSK_ORDER_SEL_SHIFT                         4                             /**< Shift for RfTxcMskOrderSel */
#define  RF_TXC_MSK_ORDER_SEL_MASK                          0x00000010u                   /**< Mask for RfTxcMskOrderSel */
#define  RF_TXC_MSK_ORDER_SEL_BMASK                         0x1u                          /**< Base mask for RfTxcMskOrderSel */
#define  RF_TXC_MSK_ORDER_SEL(x)                            (((x)&0x1u)<<4)               /**< Set RfTxcMskOrderSel in register */
#define  GET_RF_TXC_MSK_ORDER_SEL(reg)                      (((reg)>>4)&0x1u)             /**< Get RfTxcMskOrderSel from register */
#define  RF_CH_POW_CHNG_RST_DLY_SHIFT                       5                             /**< Shift for RfChPowChngRstDly */
#define  RF_CH_POW_CHNG_RST_DLY_MASK                        0x00001FE0u                   /**< Mask for RfChPowChngRstDly */
#define  RF_CH_POW_CHNG_RST_DLY_BMASK                       0xFFu                         /**< Base mask for RfChPowChngRstDly */
#define  RF_CH_POW_CHNG_RST_DLY(x)                          (((x)&0xFFu)<<5)              /**< Set RfChPowChngRstDly in register */
#define  GET_RF_CH_POW_CHNG_RST_DLY(reg)                    (((reg)>>5)&0xFFu)            /**< Get RfChPowChngRstDly from register */
#define  RF_CONT_ADV_SCAN_SHIFT                             13                            /**< Shift for RfContAdvScan */
#define  RF_CONT_ADV_SCAN_MASK                              0x00002000u                   /**< Mask for RfContAdvScan */
#define  RF_CONT_ADV_SCAN_BMASK                             0x1u                          /**< Base mask for RfContAdvScan */
#define  RF_CONT_ADV_SCAN(x)                                (((x)&0x1u)<<13)              /**< Set RfContAdvScan in register */
#define  GET_RF_CONT_ADV_SCAN(reg)                          (((reg)>>13)&0x1u)            /**< Get RfContAdvScan from register */
#define  RF_EN_PDET_RESTART_SHIFT                           14                            /**< Shift for RfEnPdetRestart */
#define  RF_EN_PDET_RESTART_MASK                            0x00004000u                   /**< Mask for RfEnPdetRestart */
#define  RF_EN_PDET_RESTART_BMASK                           0x1u                          /**< Base mask for RfEnPdetRestart */
#define  RF_EN_PDET_RESTART(x)                              (((x)&0x1u)<<14)              /**< Set RfEnPdetRestart in register */
#define  GET_RF_EN_PDET_RESTART(reg)                        (((reg)>>14)&0x1u)            /**< Get RfEnPdetRestart from register */
#define  RF_EN_PDET_TIMREC_RESTART_SHIFT                    15                            /**< Shift for RfEnPdetTimrecRestart */
#define  RF_EN_PDET_TIMREC_RESTART_MASK                     0x00008000u                   /**< Mask for RfEnPdetTimrecRestart */
#define  RF_EN_PDET_TIMREC_RESTART_BMASK                    0x1u                          /**< Base mask for RfEnPdetTimrecRestart */
#define  RF_EN_PDET_TIMREC_RESTART(x)                       (((x)&0x1u)<<15)              /**< Set RfEnPdetTimrecRestart in register */
#define  GET_RF_EN_PDET_TIMREC_RESTART(reg)                 (((reg)>>15)&0x1u)            /**< Get RfEnPdetTimrecRestart from register */
/** @} */


/**
 * @name RegRfDsmFrac1
 * @{
 */
// RegRfDsmFrac1.r32
#define  REG_RF_DSM_FRAC1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfDsmFrac1 */
#define  REG_RF_DSM_FRAC1_MASK                              0x0000FFFFu                   /**< Mask for RegRfDsmFrac1 */

#define  RF_DSM_FRAC_OW_SHIFT                               0                             /**< Shift for RfDsmFracOw */
#define  RF_DSM_FRAC_OW_MASK                                0x00000001u                   /**< Mask for RfDsmFracOw */
#define  RF_DSM_FRAC_OW_BMASK                               0x1u                          /**< Base mask for RfDsmFracOw */
#define  RF_DSM_FRAC_OW(x)                                  (((x)&0x1u)<<0)               /**< Set RfDsmFracOw in register */
#define  GET_RF_DSM_FRAC_OW(reg)                            (((reg)>>0)&0x1u)             /**< Get RfDsmFracOw from register */
#define  RF_DSM_FRAC_MSW_SHIFT                              1                             /**< Shift for RfDsmFracMsw */
#define  RF_DSM_FRAC_MSW_MASK                               0x0000FFFEu                   /**< Mask for RfDsmFracMsw */
#define  RF_DSM_FRAC_MSW_BMASK                              0x7FFFu                       /**< Base mask for RfDsmFracMsw */
#define  RF_DSM_FRAC_MSW(x)                                 (((x)&0x7FFFu)<<1)            /**< Set RfDsmFracMsw in register */
#define  GET_RF_DSM_FRAC_MSW(reg)                           (((reg)>>1)&0x7FFFu)          /**< Get RfDsmFracMsw from register */
/** @} */


/**
 * @name RegRfAgcThrshld11M
 * @{
 */
// RegRfAgcThrshld11M.r32
#define  REG_RF_AGC_THRSHLD1_1M_RESET_VALUE                 0x00000689u                   /**< Reset value of RegRfAgcThrshld11M */
#define  REG_RF_AGC_THRSHLD1_1M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld11M */

#define  RF_POW_000_001_SHIFT                               0                             /**< Shift for RfPow000001 */
#define  RF_POW_000_001_MASK                                0x0000007Fu                   /**< Mask for RfPow000001 */
#define  RF_POW_000_001_BMASK                               0x7Fu                         /**< Base mask for RfPow000001 */
#define  RF_POW_000_001(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow000001 in register */
#define  GET_RF_POW_000_001(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow000001 from register */
#define  RF_POW_001_010_SHIFT                               7                             /**< Shift for RfPow001010 */
#define  RF_POW_001_010_MASK                                0x00003F80u                   /**< Mask for RfPow001010 */
#define  RF_POW_001_010_BMASK                               0x7Fu                         /**< Base mask for RfPow001010 */
#define  RF_POW_001_010(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow001010 in register */
#define  GET_RF_POW_001_010(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow001010 from register */
/** @} */


/**
 * @name RegRfAgcThrshld21M
 * @{
 */
// RegRfAgcThrshld21M.r32
#define  REG_RF_AGC_THRSHLD2_1M_RESET_VALUE                 0x0000078Cu                   /**< Reset value of RegRfAgcThrshld21M */
#define  REG_RF_AGC_THRSHLD2_1M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld21M */

#define  RF_POW_010_011_SHIFT                               0                             /**< Shift for RfPow010011 */
#define  RF_POW_010_011_MASK                                0x0000007Fu                   /**< Mask for RfPow010011 */
#define  RF_POW_010_011_BMASK                               0x7Fu                         /**< Base mask for RfPow010011 */
#define  RF_POW_010_011(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow010011 in register */
#define  GET_RF_POW_010_011(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow010011 from register */
#define  RF_POW_011_100_SHIFT                               7                             /**< Shift for RfPow011100 */
#define  RF_POW_011_100_MASK                                0x00003F80u                   /**< Mask for RfPow011100 */
#define  RF_POW_011_100_BMASK                               0x7Fu                         /**< Base mask for RfPow011100 */
#define  RF_POW_011_100(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow011100 in register */
#define  GET_RF_POW_011_100(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow011100 from register */
/** @} */


/**
 * @name RegRfAgcThrshld31M
 * @{
 */
// RegRfAgcThrshld31M.r32
#define  REG_RF_AGC_THRSHLD3_1M_RESET_VALUE                 0x00000F09u                   /**< Reset value of RegRfAgcThrshld31M */
#define  REG_RF_AGC_THRSHLD3_1M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld31M */

#define  RF_POW_100_101_SHIFT                               0                             /**< Shift for RfPow100101 */
#define  RF_POW_100_101_MASK                                0x0000007Fu                   /**< Mask for RfPow100101 */
#define  RF_POW_100_101_BMASK                               0x7Fu                         /**< Base mask for RfPow100101 */
#define  RF_POW_100_101(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow100101 in register */
#define  GET_RF_POW_100_101(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow100101 from register */
#define  RF_POW_101_100_SHIFT                               7                             /**< Shift for RfPow101100 */
#define  RF_POW_101_100_MASK                                0x00003F80u                   /**< Mask for RfPow101100 */
#define  RF_POW_101_100_BMASK                               0x7Fu                         /**< Base mask for RfPow101100 */
#define  RF_POW_101_100(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow101100 in register */
#define  GET_RF_POW_101_100(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow101100 from register */
/** @} */


/**
 * @name RegRfAgcThrshld41M
 * @{
 */
// RegRfAgcThrshld41M.r32
#define  REG_RF_AGC_THRSHLD4_1M_RESET_VALUE                 0x00001E3Cu                   /**< Reset value of RegRfAgcThrshld41M */
#define  REG_RF_AGC_THRSHLD4_1M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld41M */

#define  RF_POW_100_011_SHIFT                               0                             /**< Shift for RfPow100011 */
#define  RF_POW_100_011_MASK                                0x0000007Fu                   /**< Mask for RfPow100011 */
#define  RF_POW_100_011_BMASK                               0x7Fu                         /**< Base mask for RfPow100011 */
#define  RF_POW_100_011(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow100011 in register */
#define  GET_RF_POW_100_011(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow100011 from register */
#define  RF_POW_011_010_SHIFT                               7                             /**< Shift for RfPow011010 */
#define  RF_POW_011_010_MASK                                0x00003F80u                   /**< Mask for RfPow011010 */
#define  RF_POW_011_010_BMASK                               0x7Fu                         /**< Base mask for RfPow011010 */
#define  RF_POW_011_010(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow011010 in register */
#define  GET_RF_POW_011_010(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow011010 from register */
/** @} */


/**
 * @name RegRfAgcThrshld51M
 * @{
 */
// RegRfAgcThrshld51M.r32
#define  REG_RF_AGC_THRSHLD5_1M_RESET_VALUE                 0x00001E3Cu                   /**< Reset value of RegRfAgcThrshld51M */
#define  REG_RF_AGC_THRSHLD5_1M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld51M */

#define  RF_POW_010_001_SHIFT                               0                             /**< Shift for RfPow010001 */
#define  RF_POW_010_001_MASK                                0x0000007Fu                   /**< Mask for RfPow010001 */
#define  RF_POW_010_001_BMASK                               0x7Fu                         /**< Base mask for RfPow010001 */
#define  RF_POW_010_001(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow010001 in register */
#define  GET_RF_POW_010_001(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow010001 from register */
#define  RF_POW_001_000_SHIFT                               7                             /**< Shift for RfPow001000 */
#define  RF_POW_001_000_MASK                                0x00003F80u                   /**< Mask for RfPow001000 */
#define  RF_POW_001_000_BMASK                               0x7Fu                         /**< Base mask for RfPow001000 */
#define  RF_POW_001_000(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow001000 in register */
#define  GET_RF_POW_001_000(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow001000 from register */
/** @} */


/**
 * @name RegRfAgcThrshld12M
 * @{
 */
// RegRfAgcThrshld12M.r32
#define  REG_RF_AGC_THRSHLD1_2M_RESET_VALUE                 0x00000689u                   /**< Reset value of RegRfAgcThrshld12M */
#define  REG_RF_AGC_THRSHLD1_2M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld12M */

#define  RF_POW_000_001_SHIFT                               0                             /**< Shift for RfPow000001 */
#define  RF_POW_000_001_MASK                                0x0000007Fu                   /**< Mask for RfPow000001 */
#define  RF_POW_000_001_BMASK                               0x7Fu                         /**< Base mask for RfPow000001 */
#define  RF_POW_000_001(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow000001 in register */
#define  GET_RF_POW_000_001(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow000001 from register */
#define  RF_POW_001_010_SHIFT                               7                             /**< Shift for RfPow001010 */
#define  RF_POW_001_010_MASK                                0x00003F80u                   /**< Mask for RfPow001010 */
#define  RF_POW_001_010_BMASK                               0x7Fu                         /**< Base mask for RfPow001010 */
#define  RF_POW_001_010(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow001010 in register */
#define  GET_RF_POW_001_010(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow001010 from register */
/** @} */


/**
 * @name RegRfAgcThrshld22M
 * @{
 */
// RegRfAgcThrshld22M.r32
#define  REG_RF_AGC_THRSHLD2_2M_RESET_VALUE                 0x0000078Cu                   /**< Reset value of RegRfAgcThrshld22M */
#define  REG_RF_AGC_THRSHLD2_2M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld22M */

#define  RF_POW_010_011_SHIFT                               0                             /**< Shift for RfPow010011 */
#define  RF_POW_010_011_MASK                                0x0000007Fu                   /**< Mask for RfPow010011 */
#define  RF_POW_010_011_BMASK                               0x7Fu                         /**< Base mask for RfPow010011 */
#define  RF_POW_010_011(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow010011 in register */
#define  GET_RF_POW_010_011(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow010011 from register */
#define  RF_POW_011_100_SHIFT                               7                             /**< Shift for RfPow011100 */
#define  RF_POW_011_100_MASK                                0x00003F80u                   /**< Mask for RfPow011100 */
#define  RF_POW_011_100_BMASK                               0x7Fu                         /**< Base mask for RfPow011100 */
#define  RF_POW_011_100(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow011100 in register */
#define  GET_RF_POW_011_100(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow011100 from register */
/** @} */


/**
 * @name RegRfAgcThrshld32M
 * @{
 */
// RegRfAgcThrshld32M.r32
#define  REG_RF_AGC_THRSHLD3_2M_RESET_VALUE                 0x00000F09u                   /**< Reset value of RegRfAgcThrshld32M */
#define  REG_RF_AGC_THRSHLD3_2M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld32M */

#define  RF_POW_100_101_SHIFT                               0                             /**< Shift for RfPow100101 */
#define  RF_POW_100_101_MASK                                0x0000007Fu                   /**< Mask for RfPow100101 */
#define  RF_POW_100_101_BMASK                               0x7Fu                         /**< Base mask for RfPow100101 */
#define  RF_POW_100_101(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow100101 in register */
#define  GET_RF_POW_100_101(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow100101 from register */
#define  RF_POW_101_100_SHIFT                               7                             /**< Shift for RfPow101100 */
#define  RF_POW_101_100_MASK                                0x00003F80u                   /**< Mask for RfPow101100 */
#define  RF_POW_101_100_BMASK                               0x7Fu                         /**< Base mask for RfPow101100 */
#define  RF_POW_101_100(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow101100 in register */
#define  GET_RF_POW_101_100(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow101100 from register */
/** @} */


/**
 * @name RegRfAgcThrshld42M
 * @{
 */
// RegRfAgcThrshld42M.r32
#define  REG_RF_AGC_THRSHLD4_2M_RESET_VALUE                 0x00001E3Cu                   /**< Reset value of RegRfAgcThrshld42M */
#define  REG_RF_AGC_THRSHLD4_2M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld42M */

#define  RF_POW_100_011_SHIFT                               0                             /**< Shift for RfPow100011 */
#define  RF_POW_100_011_MASK                                0x0000007Fu                   /**< Mask for RfPow100011 */
#define  RF_POW_100_011_BMASK                               0x7Fu                         /**< Base mask for RfPow100011 */
#define  RF_POW_100_011(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow100011 in register */
#define  GET_RF_POW_100_011(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow100011 from register */
#define  RF_POW_011_010_SHIFT                               7                             /**< Shift for RfPow011010 */
#define  RF_POW_011_010_MASK                                0x00003F80u                   /**< Mask for RfPow011010 */
#define  RF_POW_011_010_BMASK                               0x7Fu                         /**< Base mask for RfPow011010 */
#define  RF_POW_011_010(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow011010 in register */
#define  GET_RF_POW_011_010(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow011010 from register */
/** @} */


/**
 * @name RegRfAgcThrshld52M
 * @{
 */
// RegRfAgcThrshld52M.r32
#define  REG_RF_AGC_THRSHLD5_2M_RESET_VALUE                 0x00001E3Cu                   /**< Reset value of RegRfAgcThrshld52M */
#define  REG_RF_AGC_THRSHLD5_2M_MASK                        0x00003FFFu                   /**< Mask for RegRfAgcThrshld52M */

#define  RF_POW_010_001_SHIFT                               0                             /**< Shift for RfPow010001 */
#define  RF_POW_010_001_MASK                                0x0000007Fu                   /**< Mask for RfPow010001 */
#define  RF_POW_010_001_BMASK                               0x7Fu                         /**< Base mask for RfPow010001 */
#define  RF_POW_010_001(x)                                  (((x)&0x7Fu)<<0)              /**< Set RfPow010001 in register */
#define  GET_RF_POW_010_001(reg)                            (((reg)>>0)&0x7Fu)            /**< Get RfPow010001 from register */
#define  RF_POW_001_000_SHIFT                               7                             /**< Shift for RfPow001000 */
#define  RF_POW_001_000_MASK                                0x00003F80u                   /**< Mask for RfPow001000 */
#define  RF_POW_001_000_BMASK                               0x7Fu                         /**< Base mask for RfPow001000 */
#define  RF_POW_001_000(x)                                  (((x)&0x7Fu)<<7)              /**< Set RfPow001000 in register */
#define  GET_RF_POW_001_000(reg)                            (((reg)>>7)&0x7Fu)            /**< Get RfPow001000 from register */
/** @} */


/**
 * @name RegRfRxGrpDly1M
 * @{
 */
// RegRfRxGrpDly1M.r32
#define  REG_RF_RX_GRP_DLY_1M_RESET_VALUE                   0x00009D67u                   /**< Reset value of RegRfRxGrpDly1M */
#define  REG_RF_RX_GRP_DLY_1M_MASK                          0x0000FFFFu                   /**< Mask for RegRfRxGrpDly1M */

#define  RF_ADC_OUT_DEMOD_IN_1M_SHIFT                       0                             /**< Shift for RfAdcOutDemodIn1M */
#define  RF_ADC_OUT_DEMOD_IN_1M_MASK                        0x000000FFu                   /**< Mask for RfAdcOutDemodIn1M */
#define  RF_ADC_OUT_DEMOD_IN_1M_BMASK                       0xFFu                         /**< Base mask for RfAdcOutDemodIn1M */
#define  RF_ADC_OUT_DEMOD_IN_1M(x)                          (((x)&0xFFu)<<0)              /**< Set RfAdcOutDemodIn1M in register */
#define  GET_RF_ADC_OUT_DEMOD_IN_1M(reg)                    (((reg)>>0)&0xFFu)            /**< Get RfAdcOutDemodIn1M from register */
#define  RF_ADC_OUT_CRSSI_IN_1M_SHIFT                       8                             /**< Shift for RfAdcOutCrssiIn1M */
#define  RF_ADC_OUT_CRSSI_IN_1M_MASK                        0x0000FF00u                   /**< Mask for RfAdcOutCrssiIn1M */
#define  RF_ADC_OUT_CRSSI_IN_1M_BMASK                       0xFFu                         /**< Base mask for RfAdcOutCrssiIn1M */
#define  RF_ADC_OUT_CRSSI_IN_1M(x)                          (((x)&0xFFu)<<8)              /**< Set RfAdcOutCrssiIn1M in register */
#define  GET_RF_ADC_OUT_CRSSI_IN_1M(reg)                    (((reg)>>8)&0xFFu)            /**< Get RfAdcOutCrssiIn1M from register */
/** @} */


/**
 * @name RegRfRxGainVhg
 * @{
 */
// RegRfRxGainVhg.r32
#define  REG_RF_RX_GAIN_VHG_RESET_VALUE                     0x0000043Fu                   /**< Reset value of RegRfRxGainVhg */
#define  REG_RF_RX_GAIN_VHG_MASK                            0x000007FFu                   /**< Mask for RegRfRxGainVhg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfRxGainHg
 * @{
 */
// RegRfRxGainHg.r32
#define  REG_RF_RX_GAIN_HG_RESET_VALUE                      0x0000040Fu                   /**< Reset value of RegRfRxGainHg */
#define  REG_RF_RX_GAIN_HG_MASK                             0x000007FFu                   /**< Mask for RegRfRxGainHg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfRxGainIhg
 * @{
 */
// RegRfRxGainIhg.r32
#define  REG_RF_RX_GAIN_IHG_RESET_VALUE                     0x00000403u                   /**< Reset value of RegRfRxGainIhg */
#define  REG_RF_RX_GAIN_IHG_MASK                            0x000007FFu                   /**< Mask for RegRfRxGainIhg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfRxGainMg
 * @{
 */
// RegRfRxGainMg.r32
#define  REG_RF_RX_GAIN_MG_RESET_VALUE                      0x000004C0u                   /**< Reset value of RegRfRxGainMg */
#define  REG_RF_RX_GAIN_MG_MASK                             0x000007FFu                   /**< Mask for RegRfRxGainMg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfRxGainLg
 * @{
 */
// RegRfRxGainLg.r32
#define  REG_RF_RX_GAIN_LG_RESET_VALUE                      0x000006C0u                   /**< Reset value of RegRfRxGainLg */
#define  REG_RF_RX_GAIN_LG_MASK                             0x000007FFu                   /**< Mask for RegRfRxGainLg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfRxGainVlg
 * @{
 */
// RegRfRxGainVlg.r32
#define  REG_RF_RX_GAIN_VLG_RESET_VALUE                     0x00000340u                   /**< Reset value of RegRfRxGainVlg */
#define  REG_RF_RX_GAIN_VLG_MASK                            0x000007FFu                   /**< Mask for RegRfRxGainVlg */

#define  RF_LNA_HGAIN_SHIFT                                 0                             /**< Shift for RfLnaHgain */
#define  RF_LNA_HGAIN_MASK                                  0x0000003Fu                   /**< Mask for RfLnaHgain */
#define  RF_LNA_HGAIN_BMASK                                 0x3Fu                         /**< Base mask for RfLnaHgain */
#define  RF_LNA_HGAIN(x)                                    (((x)&0x3Fu)<<0)              /**< Set RfLnaHgain in register */
#define  GET_RF_LNA_HGAIN(reg)                              (((reg)>>0)&0x3Fu)            /**< Get RfLnaHgain from register */
#define  RF_LNA_LGAIN_SHIFT                                 6                             /**< Shift for RfLnaLgain */
#define  RF_LNA_LGAIN_MASK                                  0x000000C0u                   /**< Mask for RfLnaLgain */
#define  RF_LNA_LGAIN_BMASK                                 0x3u                          /**< Base mask for RfLnaLgain */
#define  RF_LNA_LGAIN(x)                                    (((x)&0x3u)<<6)               /**< Set RfLnaLgain in register */
#define  GET_RF_LNA_LGAIN(reg)                              (((reg)>>6)&0x3u)             /**< Get RfLnaLgain from register */
#define  RF_LNA_ATTN_SHIFT                                  8                             /**< Shift for RfLnaAttn */
#define  RF_LNA_ATTN_MASK                                   0x00000300u                   /**< Mask for RfLnaAttn */
#define  RF_LNA_ATTN_BMASK                                  0x3u                          /**< Base mask for RfLnaAttn */
#define  RF_LNA_ATTN(x)                                     (((x)&0x3u)<<8)               /**< Set RfLnaAttn in register */
#define  GET_RF_LNA_ATTN(reg)                               (((reg)>>8)&0x3u)             /**< Get RfLnaAttn from register */
#define  RF_CBPF_GAIN_SHIFT                                 10                            /**< Shift for RfCbpfGain */
#define  RF_CBPF_GAIN_MASK                                  0x00000400u                   /**< Mask for RfCbpfGain */
#define  RF_CBPF_GAIN_BMASK                                 0x1u                          /**< Base mask for RfCbpfGain */
#define  RF_CBPF_GAIN(x)                                    (((x)&0x1u)<<10)              /**< Set RfCbpfGain in register */
#define  GET_RF_CBPF_GAIN(reg)                              (((reg)>>10)&0x1u)            /**< Get RfCbpfGain from register */
/** @} */


/**
 * @name RegRfAdcRbkI
 * @{
 */
// RegRfAdcRbkI.r32
#define  REG_RF_ADC_RBK_I_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfAdcRbkI */
#define  REG_RF_ADC_RBK_I_MASK                              0x000007FFu                   /**< Mask for RegRfAdcRbkI */

#define  RF_ADC_RDBK_I_SHIFT                                0                             /**< Shift for RfAdcRdbkI */
#define  RF_ADC_RDBK_I_MASK                                 0x000007FFu                   /**< Mask for RfAdcRdbkI */
#define  RF_ADC_RDBK_I_BMASK                                0x7FFu                        /**< Base mask for RfAdcRdbkI */
#define  RF_ADC_RDBK_I(x)                                   (((x)&0x7FFu)<<0)             /**< Set RfAdcRdbkI in register */
#define  GET_RF_ADC_RDBK_I(reg)                             (((reg)>>0)&0x7FFu)           /**< Get RfAdcRdbkI from register */
/** @} */


/**
 * @name RegRfAdcRbkQ
 * @{
 */
// RegRfAdcRbkQ.r32
#define  REG_RF_ADC_RBK_Q_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfAdcRbkQ */
#define  REG_RF_ADC_RBK_Q_MASK                              0x000007FFu                   /**< Mask for RegRfAdcRbkQ */

#define  RF_ADC_RDBK_Q_SHIFT                                0                             /**< Shift for RfAdcRdbkQ */
#define  RF_ADC_RDBK_Q_MASK                                 0x000007FFu                   /**< Mask for RfAdcRdbkQ */
#define  RF_ADC_RDBK_Q_BMASK                                0x7FFu                        /**< Base mask for RfAdcRdbkQ */
#define  RF_ADC_RDBK_Q(x)                                   (((x)&0x7FFu)<<0)             /**< Set RfAdcRdbkQ in register */
#define  GET_RF_ADC_RDBK_Q(reg)                             (((reg)>>0)&0x7FFu)           /**< Get RfAdcRdbkQ from register */
/** @} */


/**
 * @name RegRfRxGrpDly2M
 * @{
 */
// RegRfRxGrpDly2M.r32
#define  REG_RF_RX_GRP_DLY_2M_RESET_VALUE                   0x00005234u                   /**< Reset value of RegRfRxGrpDly2M */
#define  REG_RF_RX_GRP_DLY_2M_MASK                          0x0000FFFFu                   /**< Mask for RegRfRxGrpDly2M */

#define  RF_ADC_OUT_DEMOD_IN_2M_SHIFT                       0                             /**< Shift for RfAdcOutDemodIn2M */
#define  RF_ADC_OUT_DEMOD_IN_2M_MASK                        0x000000FFu                   /**< Mask for RfAdcOutDemodIn2M */
#define  RF_ADC_OUT_DEMOD_IN_2M_BMASK                       0xFFu                         /**< Base mask for RfAdcOutDemodIn2M */
#define  RF_ADC_OUT_DEMOD_IN_2M(x)                          (((x)&0xFFu)<<0)              /**< Set RfAdcOutDemodIn2M in register */
#define  GET_RF_ADC_OUT_DEMOD_IN_2M(reg)                    (((reg)>>0)&0xFFu)            /**< Get RfAdcOutDemodIn2M from register */
#define  RF_ADC_OUT_CRSSI_IN_2M_SHIFT                       8                             /**< Shift for RfAdcOutCrssiIn2M */
#define  RF_ADC_OUT_CRSSI_IN_2M_MASK                        0x0000FF00u                   /**< Mask for RfAdcOutCrssiIn2M */
#define  RF_ADC_OUT_CRSSI_IN_2M_BMASK                       0xFFu                         /**< Base mask for RfAdcOutCrssiIn2M */
#define  RF_ADC_OUT_CRSSI_IN_2M(x)                          (((x)&0xFFu)<<8)              /**< Set RfAdcOutCrssiIn2M in register */
#define  GET_RF_ADC_OUT_CRSSI_IN_2M(reg)                    (((reg)>>8)&0xFFu)            /**< Get RfAdcOutCrssiIn2M from register */
/** @} */


/**
 * @name RegRfTimRecCfg
 * @{
 */
// RegRfTimRecCfg.r32
#define  REG_RF_TIM_REC_CFG_RESET_VALUE                     0x0000019Bu                   /**< Reset value of RegRfTimRecCfg */
#define  REG_RF_TIM_REC_CFG_MASK                            0x00003FFFu                   /**< Mask for RegRfTimRecCfg */

#define  RF_ACC_DEV_SHIFT                                   0                             /**< Shift for RfAccDev */
#define  RF_ACC_DEV_MASK                                    0x00000007u                   /**< Mask for RfAccDev */
#define  RF_ACC_DEV_BMASK                                   0x7u                          /**< Base mask for RfAccDev */
#define  RF_ACC_DEV(x)                                      (((x)&0x7u)<<0)               /**< Set RfAccDev in register */
#define  GET_RF_ACC_DEV(reg)                                (((reg)>>0)&0x7u)             /**< Get RfAccDev from register */
#define  RF_TOT_DEV_SHIFT                                   3                             /**< Shift for RfTotDev */
#define  RF_TOT_DEV_MASK                                    0x00000038u                   /**< Mask for RfTotDev */
#define  RF_TOT_DEV_BMASK                                   0x7u                          /**< Base mask for RfTotDev */
#define  RF_TOT_DEV(x)                                      (((x)&0x7u)<<3)               /**< Set RfTotDev in register */
#define  GET_RF_TOT_DEV(reg)                                (((reg)>>3)&0x7u)             /**< Get RfTotDev from register */
#define  RF_EDG_DEV_SHIFT                                   6                             /**< Shift for RfEdgDev */
#define  RF_EDG_DEV_MASK                                    0x000003C0u                   /**< Mask for RfEdgDev */
#define  RF_EDG_DEV_BMASK                                   0xFu                          /**< Base mask for RfEdgDev */
#define  RF_EDG_DEV(x)                                      (((x)&0xFu)<<6)               /**< Set RfEdgDev in register */
#define  GET_RF_EDG_DEV(reg)                                (((reg)>>6)&0xFu)             /**< Get RfEdgDev from register */
#define  RF_NSOFF_SHIFT                                     10                            /**< Shift for RfNsoff */
#define  RF_NSOFF_MASK                                      0x00001C00u                   /**< Mask for RfNsoff */
#define  RF_NSOFF_BMASK                                     0x7u                          /**< Base mask for RfNsoff */
#define  RF_NSOFF(x)                                        (((x)&0x7u)<<10)              /**< Set RfNsoff in register */
#define  GET_RF_NSOFF(reg)                                  (((reg)>>10)&0x7u)            /**< Get RfNsoff from register */
#define  RF_TOT_DEV_RST_SHIFT                               13                            /**< Shift for RfTotDevRst */
#define  RF_TOT_DEV_RST_MASK                                0x00002000u                   /**< Mask for RfTotDevRst */
#define  RF_TOT_DEV_RST_BMASK                               0x1u                          /**< Base mask for RfTotDevRst */
#define  RF_TOT_DEV_RST(x)                                  (((x)&0x1u)<<13)              /**< Set RfTotDevRst in register */
#define  GET_RF_TOT_DEV_RST(reg)                            (((reg)>>13)&0x1u)            /**< Get RfTotDevRst from register */
/** @} */


/**
 * @name RegRfFreqCorrCfg1
 * @{
 */
// RegRfFreqCorrCfg1.r32
#define  REG_RF_FREQ_CORR_CFG1_RESET_VALUE                  0x000002CAu                   /**< Reset value of RegRfFreqCorrCfg1 */
#define  REG_RF_FREQ_CORR_CFG1_MASK                         0x00007FFFu                   /**< Mask for RegRfFreqCorrCfg1 */

#define  RF_BYPASS_FREQ_CORR_SHIFT                          0                             /**< Shift for RfBypassFreqCorr */
#define  RF_BYPASS_FREQ_CORR_MASK                           0x00000001u                   /**< Mask for RfBypassFreqCorr */
#define  RF_BYPASS_FREQ_CORR_BMASK                          0x1u                          /**< Base mask for RfBypassFreqCorr */
#define  RF_BYPASS_FREQ_CORR(x)                             (((x)&0x1u)<<0)               /**< Set RfBypassFreqCorr in register */
#define  GET_RF_BYPASS_FREQ_CORR(reg)                       (((reg)>>0)&0x1u)             /**< Get RfBypassFreqCorr from register */
#define  RF_LAMBDA_SHIFT                                    1                             /**< Shift for RfLambda */
#define  RF_LAMBDA_MASK                                     0x0000000Eu                   /**< Mask for RfLambda */
#define  RF_LAMBDA_BMASK                                    0x7u                          /**< Base mask for RfLambda */
#define  RF_LAMBDA(x)                                       (((x)&0x7u)<<1)               /**< Set RfLambda in register */
#define  GET_RF_LAMBDA(reg)                                 (((reg)>>1)&0x7u)             /**< Get RfLambda from register */
#define  RF_NUM_GEAR_SHIFT                                  4                             /**< Shift for RfNumGear */
#define  RF_NUM_GEAR_MASK                                   0x00000070u                   /**< Mask for RfNumGear */
#define  RF_NUM_GEAR_BMASK                                  0x7u                          /**< Base mask for RfNumGear */
#define  RF_NUM_GEAR(x)                                     (((x)&0x7u)<<4)               /**< Set RfNumGear in register */
#define  GET_RF_NUM_GEAR(reg)                               (((reg)>>4)&0x7u)             /**< Get RfNumGear from register */
#define  RF_START_STEP_TIME_SHIFT                           7                             /**< Shift for RfStartStepTime */
#define  RF_START_STEP_TIME_MASK                            0x00000380u                   /**< Mask for RfStartStepTime */
#define  RF_START_STEP_TIME_BMASK                           0x7u                          /**< Base mask for RfStartStepTime */
#define  RF_START_STEP_TIME(x)                              (((x)&0x7u)<<7)               /**< Set RfStartStepTime in register */
#define  GET_RF_START_STEP_TIME(reg)                        (((reg)>>7)&0x7u)             /**< Get RfStartStepTime from register */
#define  RF_LAMBDA_AFR_AM_EN_SHIFT                          10                            /**< Shift for RfLambdaAfrAmEn */
#define  RF_LAMBDA_AFR_AM_EN_MASK                           0x00000400u                   /**< Mask for RfLambdaAfrAmEn */
#define  RF_LAMBDA_AFR_AM_EN_BMASK                          0x1u                          /**< Base mask for RfLambdaAfrAmEn */
#define  RF_LAMBDA_AFR_AM_EN(x)                             (((x)&0x1u)<<10)              /**< Set RfLambdaAfrAmEn in register */
#define  GET_RF_LAMBDA_AFR_AM_EN(reg)                       (((reg)>>10)&0x1u)            /**< Get RfLambdaAfrAmEn from register */
#define  RF_FRZ_LAST_GEAR_AFR_AM_SHIFT                      11                            /**< Shift for RfFrzLastGearAfrAm */
#define  RF_FRZ_LAST_GEAR_AFR_AM_MASK                       0x00000800u                   /**< Mask for RfFrzLastGearAfrAm */
#define  RF_FRZ_LAST_GEAR_AFR_AM_BMASK                      0x1u                          /**< Base mask for RfFrzLastGearAfrAm */
#define  RF_FRZ_LAST_GEAR_AFR_AM(x)                         (((x)&0x1u)<<11)              /**< Set RfFrzLastGearAfrAm in register */
#define  GET_RF_FRZ_LAST_GEAR_AFR_AM(reg)                   (((reg)>>11)&0x1u)            /**< Get RfFrzLastGearAfrAm from register */
#define  RF_LAMBDA_AFR_AM_SHIFT                             12                            /**< Shift for RfLambdaAfrAm */
#define  RF_LAMBDA_AFR_AM_MASK                              0x00007000u                   /**< Mask for RfLambdaAfrAm */
#define  RF_LAMBDA_AFR_AM_BMASK                             0x7u                          /**< Base mask for RfLambdaAfrAm */
#define  RF_LAMBDA_AFR_AM(x)                                (((x)&0x7u)<<12)              /**< Set RfLambdaAfrAm in register */
#define  GET_RF_LAMBDA_AFR_AM(reg)                          (((reg)>>12)&0x7u)            /**< Get RfLambdaAfrAm from register */
/** @} */


/**
 * @name RegRfFreqCorrCfg2
 * @{
 */
// RegRfFreqCorrCfg2.r32
#define  REG_RF_FREQ_CORR_CFG2_RESET_VALUE                  0x00007357u                   /**< Reset value of RegRfFreqCorrCfg2 */
#define  REG_RF_FREQ_CORR_CFG2_MASK                         0x0000FFFFu                   /**< Mask for RegRfFreqCorrCfg2 */

#define  RF_RX_PE_DET_MIN_LO_THRESH_SHIFT                   0                             /**< Shift for RfRxPeDetMinLoThresh */
#define  RF_RX_PE_DET_MIN_LO_THRESH_MASK                    0x000000FFu                   /**< Mask for RfRxPeDetMinLoThresh */
#define  RF_RX_PE_DET_MIN_LO_THRESH_BMASK                   0xFFu                         /**< Base mask for RfRxPeDetMinLoThresh */
#define  RF_RX_PE_DET_MIN_LO_THRESH(x)                      (((x)&0xFFu)<<0)              /**< Set RfRxPeDetMinLoThresh in register */
#define  GET_RF_RX_PE_DET_MIN_LO_THRESH(reg)                (((reg)>>0)&0xFFu)            /**< Get RfRxPeDetMinLoThresh from register */
#define  RF_RX_PE_DET_MIN_HI_THRESH_SHIFT                   8                             /**< Shift for RfRxPeDetMinHiThresh */
#define  RF_RX_PE_DET_MIN_HI_THRESH_MASK                    0x0000FF00u                   /**< Mask for RfRxPeDetMinHiThresh */
#define  RF_RX_PE_DET_MIN_HI_THRESH_BMASK                   0xFFu                         /**< Base mask for RfRxPeDetMinHiThresh */
#define  RF_RX_PE_DET_MIN_HI_THRESH(x)                      (((x)&0xFFu)<<8)              /**< Set RfRxPeDetMinHiThresh in register */
#define  GET_RF_RX_PE_DET_MIN_HI_THRESH(reg)                (((reg)>>8)&0xFFu)            /**< Get RfRxPeDetMinHiThresh from register */
/** @} */


/**
 * @name RegRfTimAlign
 * @{
 */
// RegRfTimAlign.r32
#define  REG_RF_TIM_ALIGN_RESET_VALUE                       0x00000013u                   /**< Reset value of RegRfTimAlign */
#define  REG_RF_TIM_ALIGN_MASK                              0x000001FFu                   /**< Mask for RegRfTimAlign */

#define  RF_TIM_CNT_SHIFT                                   0                             /**< Shift for RfTimCnt */
#define  RF_TIM_CNT_MASK                                    0x00000007u                   /**< Mask for RfTimCnt */
#define  RF_TIM_CNT_BMASK                                   0x7u                          /**< Base mask for RfTimCnt */
#define  RF_TIM_CNT(x)                                      (((x)&0x7u)<<0)               /**< Set RfTimCnt in register */
#define  GET_RF_TIM_CNT(reg)                                (((reg)>>0)&0x7u)             /**< Get RfTimCnt from register */
#define  RF_CLK_WIDTH_SHIFT                                 3                             /**< Shift for RfClkWidth */
#define  RF_CLK_WIDTH_MASK                                  0x00000018u                   /**< Mask for RfClkWidth */
#define  RF_CLK_WIDTH_BMASK                                 0x3u                          /**< Base mask for RfClkWidth */
#define  RF_CLK_WIDTH(x)                                    (((x)&0x3u)<<3)               /**< Set RfClkWidth in register */
#define  GET_RF_CLK_WIDTH(reg)                              (((reg)>>3)&0x3u)             /**< Get RfClkWidth from register */
#define  RF_RX_PE_DET_COND_SEL_SHIFT                        5                             /**< Shift for RfRxPeDetCondSel */
#define  RF_RX_PE_DET_COND_SEL_MASK                         0x000000E0u                   /**< Mask for RfRxPeDetCondSel */
#define  RF_RX_PE_DET_COND_SEL_BMASK                        0x7u                          /**< Base mask for RfRxPeDetCondSel */
#define  RF_RX_PE_DET_COND_SEL(x)                           (((x)&0x7u)<<5)               /**< Set RfRxPeDetCondSel in register */
#define  GET_RF_RX_PE_DET_COND_SEL(reg)                     (((reg)>>5)&0x7u)             /**< Get RfRxPeDetCondSel from register */
#define  RF_RX_DIS_PDET_BLANK_SHIFT                         8                             /**< Shift for RfRxDisPdetBlank */
#define  RF_RX_DIS_PDET_BLANK_MASK                          0x00000100u                   /**< Mask for RfRxDisPdetBlank */
#define  RF_RX_DIS_PDET_BLANK_BMASK                         0x1u                          /**< Base mask for RfRxDisPdetBlank */
#define  RF_RX_DIS_PDET_BLANK(x)                            (((x)&0x1u)<<8)               /**< Set RfRxDisPdetBlank in register */
#define  GET_RF_RX_DIS_PDET_BLANK(reg)                      (((reg)>>8)&0x1u)             /**< Get RfRxDisPdetBlank from register */
/** @} */


/**
 * @name RegRfBypassFilt
 * @{
 */
// RegRfBypassFilt.r32
#define  REG_RF_BYPASS_FILT_RESET_VALUE                     0x00000620u                   /**< Reset value of RegRfBypassFilt */
#define  REG_RF_BYPASS_FILT_MASK                            0x00000FFFu                   /**< Mask for RegRfBypassFilt */

#define  RF_BYPASS_FIR_SHIFT                                0                             /**< Shift for RfBypassFir */
#define  RF_BYPASS_FIR_MASK                                 0x00000001u                   /**< Mask for RfBypassFir */
#define  RF_BYPASS_FIR_BMASK                                0x1u                          /**< Base mask for RfBypassFir */
#define  RF_BYPASS_FIR(x)                                   (((x)&0x1u)<<0)               /**< Set RfBypassFir in register */
#define  GET_RF_BYPASS_FIR(reg)                             (((reg)>>0)&0x1u)             /**< Get RfBypassFir from register */
#define  RF_BYPASS_AAF_SHIFT                                1                             /**< Shift for RfBypassAaf */
#define  RF_BYPASS_AAF_MASK                                 0x00000002u                   /**< Mask for RfBypassAaf */
#define  RF_BYPASS_AAF_BMASK                                0x1u                          /**< Base mask for RfBypassAaf */
#define  RF_BYPASS_AAF(x)                                   (((x)&0x1u)<<1)               /**< Set RfBypassAaf in register */
#define  GET_RF_BYPASS_AAF(reg)                             (((reg)>>1)&0x1u)             /**< Get RfBypassAaf from register */
#define  RF_BYPASS_MIXER_SHIFT                              2                             /**< Shift for RfBypassMixer */
#define  RF_BYPASS_MIXER_MASK                               0x00000004u                   /**< Mask for RfBypassMixer */
#define  RF_BYPASS_MIXER_BMASK                              0x1u                          /**< Base mask for RfBypassMixer */
#define  RF_BYPASS_MIXER(x)                                 (((x)&0x1u)<<2)               /**< Set RfBypassMixer in register */
#define  GET_RF_BYPASS_MIXER(reg)                           (((reg)>>2)&0x1u)             /**< Get RfBypassMixer from register */
#define  RF_BYPASS_CH_FILTER_SHIFT                          3                             /**< Shift for RfBypassChFilter */
#define  RF_BYPASS_CH_FILTER_MASK                           0x00000008u                   /**< Mask for RfBypassChFilter */
#define  RF_BYPASS_CH_FILTER_BMASK                          0x1u                          /**< Base mask for RfBypassChFilter */
#define  RF_BYPASS_CH_FILTER(x)                             (((x)&0x1u)<<3)               /**< Set RfBypassChFilter in register */
#define  GET_RF_BYPASS_CH_FILTER(reg)                       (((reg)>>3)&0x1u)             /**< Get RfBypassChFilter from register */
#define  RF_START_BLANK_SHIFT                               4                             /**< Shift for RfStartBlank */
#define  RF_START_BLANK_MASK                                0x000003F0u                   /**< Mask for RfStartBlank */
#define  RF_START_BLANK_BMASK                               0x3Fu                         /**< Base mask for RfStartBlank */
#define  RF_START_BLANK(x)                                  (((x)&0x3Fu)<<4)              /**< Set RfStartBlank in register */
#define  GET_RF_START_BLANK(reg)                            (((reg)>>4)&0x3Fu)            /**< Get RfStartBlank from register */
#define  RF_BLANK_WINDOW_SHIFT                              10                            /**< Shift for RfBlankWindow */
#define  RF_BLANK_WINDOW_MASK                               0x00000C00u                   /**< Mask for RfBlankWindow */
#define  RF_BLANK_WINDOW_BMASK                              0x3u                          /**< Base mask for RfBlankWindow */
#define  RF_BLANK_WINDOW(x)                                 (((x)&0x3u)<<10)              /**< Set RfBlankWindow in register */
#define  GET_RF_BLANK_WINDOW(reg)                           (((reg)>>10)&0x3u)            /**< Get RfBlankWindow from register */
/** @} */


/**
 * @name RegRfAgcRssiRdbk
 * @{
 */
// RegRfAgcRssiRdbk.r32
#define  REG_RF_AGC_RSSI_RDBK_RESET_VALUE                   0x00000000u                   /**< Reset value of RegRfAgcRssiRdbk */
#define  REG_RF_AGC_RSSI_RDBK_MASK                          0x00000FFFu                   /**< Mask for RegRfAgcRssiRdbk */

#define  RF_SRSSI_SHIFT                                     0                             /**< Shift for RfSrssi */
#define  RF_SRSSI_MASK                                      0x000000FFu                   /**< Mask for RfSrssi */
#define  RF_SRSSI_BMASK                                     0xFFu                         /**< Base mask for RfSrssi */
#define  RF_SRSSI(x)                                        (((x)&0xFFu)<<0)              /**< Set RfSrssi in register */
#define  GET_RF_SRSSI(reg)                                  (((reg)>>0)&0xFFu)            /**< Get RfSrssi from register */
#define  RF_FRSSI_SHIFT                                     8                             /**< Shift for RfFrssi */
#define  RF_FRSSI_MASK                                      0x00000F00u                   /**< Mask for RfFrssi */
#define  RF_FRSSI_BMASK                                     0xFu                          /**< Base mask for RfFrssi */
#define  RF_FRSSI(x)                                        (((x)&0xFu)<<8)               /**< Set RfFrssi in register */
#define  GET_RF_FRSSI(reg)                                  (((reg)>>8)&0xFu)             /**< Get RfFrssi from register */
/** @} */


/**
 * @name RegRfTimRestartDly
 * @{
 */
// RegRfTimRestartDly.r32
#define  REG_RF_TIM_RESTART_DLY_RESET_VALUE                 0x00000102u                   /**< Reset value of RegRfTimRestartDly */
#define  REG_RF_TIM_RESTART_DLY_MASK                        0x0000FFFFu                   /**< Mask for RegRfTimRestartDly */

#define  RF_PD_RESTART_DLY_1M_SHIFT                         0                             /**< Shift for RfPdRestartDly1M */
#define  RF_PD_RESTART_DLY_1M_MASK                          0x000000FFu                   /**< Mask for RfPdRestartDly1M */
#define  RF_PD_RESTART_DLY_1M_BMASK                         0xFFu                         /**< Base mask for RfPdRestartDly1M */
#define  RF_PD_RESTART_DLY_1M(x)                            (((x)&0xFFu)<<0)              /**< Set RfPdRestartDly1M in register */
#define  GET_RF_PD_RESTART_DLY_1M(reg)                      (((reg)>>0)&0xFFu)            /**< Get RfPdRestartDly1M from register */
#define  RF_PD_RESTART_DLY_2M_SHIFT                         8                             /**< Shift for RfPdRestartDly2M */
#define  RF_PD_RESTART_DLY_2M_MASK                          0x0000FF00u                   /**< Mask for RfPdRestartDly2M */
#define  RF_PD_RESTART_DLY_2M_BMASK                         0xFFu                         /**< Base mask for RfPdRestartDly2M */
#define  RF_PD_RESTART_DLY_2M(x)                            (((x)&0xFFu)<<8)              /**< Set RfPdRestartDly2M in register */
#define  GET_RF_PD_RESTART_DLY_2M(reg)                      (((reg)>>8)&0xFFu)            /**< Get RfPdRestartDly2M from register */
/** @} */


/**
 * @name RegRfCalOwCtrl
 * @{
 */
// RegRfCalOwCtrl.r32
#define  REG_RF_CAL_OW_CTRL_RESET_VALUE                     0x00000040u                   /**< Reset value of RegRfCalOwCtrl */
#define  REG_RF_CAL_OW_CTRL_MASK                            0x0000FFFFu                   /**< Mask for RegRfCalOwCtrl */

#define  RF_DSM_RUN_OW_SHIFT                                0                             /**< Shift for RfDsmRunOw */
#define  RF_DSM_RUN_OW_MASK                                 0x00000001u                   /**< Mask for RfDsmRunOw */
#define  RF_DSM_RUN_OW_BMASK                                0x1u                          /**< Base mask for RfDsmRunOw */
#define  RF_DSM_RUN_OW(x)                                   (((x)&0x1u)<<0)               /**< Set RfDsmRunOw in register */
#define  GET_RF_DSM_RUN_OW(reg)                             (((reg)>>0)&0x1u)             /**< Get RfDsmRunOw from register */
#define  RF_LDOT_TX_RUN_OW_SHIFT                            1                             /**< Shift for RfLdotTxRunOw */
#define  RF_LDOT_TX_RUN_OW_MASK                             0x00000002u                   /**< Mask for RfLdotTxRunOw */
#define  RF_LDOT_TX_RUN_OW_BMASK                            0x1u                          /**< Base mask for RfLdotTxRunOw */
#define  RF_LDOT_TX_RUN_OW(x)                               (((x)&0x1u)<<1)               /**< Set RfLdotTxRunOw in register */
#define  GET_RF_LDOT_TX_RUN_OW(reg)                         (((reg)>>1)&0x1u)             /**< Get RfLdotTxRunOw from register */
#define  RF_RCCAL_RUN_OW_SHIFT                              2                             /**< Shift for RfRccalRunOw */
#define  RF_RCCAL_RUN_OW_MASK                               0x00000004u                   /**< Mask for RfRccalRunOw */
#define  RF_RCCAL_RUN_OW_BMASK                              0x1u                          /**< Base mask for RfRccalRunOw */
#define  RF_RCCAL_RUN_OW(x)                                 (((x)&0x1u)<<2)               /**< Set RfRccalRunOw in register */
#define  GET_RF_RCCAL_RUN_OW(reg)                           (((reg)>>2)&0x1u)             /**< Get RfRccalRunOw from register */
#define  RF_FCAL_TX_RUN_OW_SHIFT                            3                             /**< Shift for RfFcalTxRunOw */
#define  RF_FCAL_TX_RUN_OW_MASK                             0x00000008u                   /**< Mask for RfFcalTxRunOw */
#define  RF_FCAL_TX_RUN_OW_BMASK                            0x1u                          /**< Base mask for RfFcalTxRunOw */
#define  RF_FCAL_TX_RUN_OW(x)                               (((x)&0x1u)<<3)               /**< Set RfFcalTxRunOw in register */
#define  GET_RF_FCAL_TX_RUN_OW(reg)                         (((reg)>>3)&0x1u)             /**< Get RfFcalTxRunOw from register */
#define  RF_DCOC_RUN_OW_SHIFT                               4                             /**< Shift for RfDcocRunOw */
#define  RF_DCOC_RUN_OW_MASK                                0x00000010u                   /**< Mask for RfDcocRunOw */
#define  RF_DCOC_RUN_OW_BMASK                               0x1u                          /**< Base mask for RfDcocRunOw */
#define  RF_DCOC_RUN_OW(x)                                  (((x)&0x1u)<<4)               /**< Set RfDcocRunOw in register */
#define  GET_RF_DCOC_RUN_OW(reg)                            (((reg)>>4)&0x1u)             /**< Get RfDcocRunOw from register */
#define  RF_HPMC_RUN_OW_SHIFT                               5                             /**< Shift for RfHpmcRunOw */
#define  RF_HPMC_RUN_OW_MASK                                0x00000020u                   /**< Mask for RfHpmcRunOw */
#define  RF_HPMC_RUN_OW_BMASK                               0x1u                          /**< Base mask for RfHpmcRunOw */
#define  RF_HPMC_RUN_OW(x)                                  (((x)&0x1u)<<5)               /**< Set RfHpmcRunOw in register */
#define  GET_RF_HPMC_RUN_OW(reg)                            (((reg)>>5)&0x1u)             /**< Get RfHpmcRunOw from register */
#define  RF_LOCD_RUN_OW_SHIFT                               6                             /**< Shift for RfLocdRunOw */
#define  RF_LOCD_RUN_OW_MASK                                0x00000040u                   /**< Mask for RfLocdRunOw */
#define  RF_LOCD_RUN_OW_BMASK                               0x1u                          /**< Base mask for RfLocdRunOw */
#define  RF_LOCD_RUN_OW(x)                                  (((x)&0x1u)<<6)               /**< Set RfLocdRunOw in register */
#define  GET_RF_LOCD_RUN_OW(reg)                            (((reg)>>6)&0x1u)             /**< Get RfLocdRunOw from register */
#define  RF_DCOC_GAIN_CFG_OW_SHIFT                          7                             /**< Shift for RfDcocGainCfgOw */
#define  RF_DCOC_GAIN_CFG_OW_MASK                           0x00000080u                   /**< Mask for RfDcocGainCfgOw */
#define  RF_DCOC_GAIN_CFG_OW_BMASK                          0x1u                          /**< Base mask for RfDcocGainCfgOw */
#define  RF_DCOC_GAIN_CFG_OW(x)                             (((x)&0x1u)<<7)               /**< Set RfDcocGainCfgOw in register */
#define  GET_RF_DCOC_GAIN_CFG_OW(reg)                       (((reg)>>7)&0x1u)             /**< Get RfDcocGainCfgOw from register */
#define  RF_RX_DIG_EN_OW_SHIFT                              8                             /**< Shift for RfRxDigEnOw */
#define  RF_RX_DIG_EN_OW_MASK                               0x00000100u                   /**< Mask for RfRxDigEnOw */
#define  RF_RX_DIG_EN_OW_BMASK                              0x1u                          /**< Base mask for RfRxDigEnOw */
#define  RF_RX_DIG_EN_OW(x)                                 (((x)&0x1u)<<8)               /**< Set RfRxDigEnOw in register */
#define  GET_RF_RX_DIG_EN_OW(reg)                           (((reg)>>8)&0x1u)             /**< Get RfRxDigEnOw from register */
#define  RF_TXC_TX_EN_OW_SHIFT                              9                             /**< Shift for RfTxcTxEnOw */
#define  RF_TXC_TX_EN_OW_MASK                               0x00000200u                   /**< Mask for RfTxcTxEnOw */
#define  RF_TXC_TX_EN_OW_BMASK                              0x1u                          /**< Base mask for RfTxcTxEnOw */
#define  RF_TXC_TX_EN_OW(x)                                 (((x)&0x1u)<<9)               /**< Set RfTxcTxEnOw in register */
#define  GET_RF_TXC_TX_EN_OW(reg)                           (((reg)>>9)&0x1u)             /**< Get RfTxcTxEnOw from register */
#define  RF_TX_HPM_CAL_EN_OW_SHIFT                          10                            /**< Shift for RfTxHpmCalEnOw */
#define  RF_TX_HPM_CAL_EN_OW_MASK                           0x00000400u                   /**< Mask for RfTxHpmCalEnOw */
#define  RF_TX_HPM_CAL_EN_OW_BMASK                          0x1u                          /**< Base mask for RfTxHpmCalEnOw */
#define  RF_TX_HPM_CAL_EN_OW(x)                             (((x)&0x1u)<<10)              /**< Set RfTxHpmCalEnOw in register */
#define  GET_RF_TX_HPM_CAL_EN_OW(reg)                       (((reg)>>10)&0x1u)            /**< Get RfTxHpmCalEnOw from register */
#define  RF_TX_MOD_EN_OW_SHIFT                              11                            /**< Shift for RfTxModEnOw */
#define  RF_TX_MOD_EN_OW_MASK                               0x00000800u                   /**< Mask for RfTxModEnOw */
#define  RF_TX_MOD_EN_OW_BMASK                              0x1u                          /**< Base mask for RfTxModEnOw */
#define  RF_TX_MOD_EN_OW(x)                                 (((x)&0x1u)<<11)              /**< Set RfTxModEnOw in register */
#define  GET_RF_TX_MOD_EN_OW(reg)                           (((reg)>>11)&0x1u)            /**< Get RfTxModEnOw from register */
#define  RF_LDOT_RX_RUN_OW_SHIFT                            12                            /**< Shift for RfLdotRxRunOw */
#define  RF_LDOT_RX_RUN_OW_MASK                             0x00001000u                   /**< Mask for RfLdotRxRunOw */
#define  RF_LDOT_RX_RUN_OW_BMASK                            0x1u                          /**< Base mask for RfLdotRxRunOw */
#define  RF_LDOT_RX_RUN_OW(x)                               (((x)&0x1u)<<12)              /**< Set RfLdotRxRunOw in register */
#define  GET_RF_LDOT_RX_RUN_OW(reg)                         (((reg)>>12)&0x1u)            /**< Get RfLdotRxRunOw from register */
#define  RF_FCAL_RX_RUN_OW_SHIFT                            13                            /**< Shift for RfFcalRxRunOw */
#define  RF_FCAL_RX_RUN_OW_MASK                             0x00002000u                   /**< Mask for RfFcalRxRunOw */
#define  RF_FCAL_RX_RUN_OW_BMASK                            0x1u                          /**< Base mask for RfFcalRxRunOw */
#define  RF_FCAL_RX_RUN_OW(x)                               (((x)&0x1u)<<13)              /**< Set RfFcalRxRunOw in register */
#define  GET_RF_FCAL_RX_RUN_OW(reg)                         (((reg)>>13)&0x1u)            /**< Get RfFcalRxRunOw from register */
#define  RF_LDOT_DEBUG_RUN_OW_SHIFT                         14                            /**< Shift for RfLdotDebugRunOw */
#define  RF_LDOT_DEBUG_RUN_OW_MASK                          0x00004000u                   /**< Mask for RfLdotDebugRunOw */
#define  RF_LDOT_DEBUG_RUN_OW_BMASK                         0x1u                          /**< Base mask for RfLdotDebugRunOw */
#define  RF_LDOT_DEBUG_RUN_OW(x)                            (((x)&0x1u)<<14)              /**< Set RfLdotDebugRunOw in register */
#define  GET_RF_LDOT_DEBUG_RUN_OW(reg)                      (((reg)>>14)&0x1u)            /**< Get RfLdotDebugRunOw from register */
#define  RF_FCAL_DEBUG_RUN_OW_SHIFT                         15                            /**< Shift for RfFcalDebugRunOw */
#define  RF_FCAL_DEBUG_RUN_OW_MASK                          0x00008000u                   /**< Mask for RfFcalDebugRunOw */
#define  RF_FCAL_DEBUG_RUN_OW_BMASK                         0x1u                          /**< Base mask for RfFcalDebugRunOw */
#define  RF_FCAL_DEBUG_RUN_OW(x)                            (((x)&0x1u)<<15)              /**< Set RfFcalDebugRunOw in register */
#define  GET_RF_FCAL_DEBUG_RUN_OW(reg)                      (((reg)>>15)&0x1u)            /**< Get RfFcalDebugRunOw from register */
/** @} */


/**
 * @name RegRfCalOwVal
 * @{
 */
// RegRfCalOwVal.r32
#define  REG_RF_CAL_OW_VAL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfCalOwVal */
#define  REG_RF_CAL_OW_VAL_MASK                             0x0000FFFFu                   /**< Mask for RegRfCalOwVal */

#define  RF_DSM_RUN_SHIFT                                   0                             /**< Shift for RfDsmRun */
#define  RF_DSM_RUN_MASK                                    0x00000001u                   /**< Mask for RfDsmRun */
#define  RF_DSM_RUN_BMASK                                   0x1u                          /**< Base mask for RfDsmRun */
#define  RF_DSM_RUN(x)                                      (((x)&0x1u)<<0)               /**< Set RfDsmRun in register */
#define  GET_RF_DSM_RUN(reg)                                (((reg)>>0)&0x1u)             /**< Get RfDsmRun from register */
#define  RF_LDOT_TX_RUN_SHIFT                               1                             /**< Shift for RfLdotTxRun */
#define  RF_LDOT_TX_RUN_MASK                                0x00000002u                   /**< Mask for RfLdotTxRun */
#define  RF_LDOT_TX_RUN_BMASK                               0x1u                          /**< Base mask for RfLdotTxRun */
#define  RF_LDOT_TX_RUN(x)                                  (((x)&0x1u)<<1)               /**< Set RfLdotTxRun in register */
#define  GET_RF_LDOT_TX_RUN(reg)                            (((reg)>>1)&0x1u)             /**< Get RfLdotTxRun from register */
#define  RF_RCCAL_RUN_SHIFT                                 2                             /**< Shift for RfRccalRun */
#define  RF_RCCAL_RUN_MASK                                  0x00000004u                   /**< Mask for RfRccalRun */
#define  RF_RCCAL_RUN_BMASK                                 0x1u                          /**< Base mask for RfRccalRun */
#define  RF_RCCAL_RUN(x)                                    (((x)&0x1u)<<2)               /**< Set RfRccalRun in register */
#define  GET_RF_RCCAL_RUN(reg)                              (((reg)>>2)&0x1u)             /**< Get RfRccalRun from register */
#define  RF_FCAL_TX_RUN_SHIFT                               3                             /**< Shift for RfFcalTxRun */
#define  RF_FCAL_TX_RUN_MASK                                0x00000008u                   /**< Mask for RfFcalTxRun */
#define  RF_FCAL_TX_RUN_BMASK                               0x1u                          /**< Base mask for RfFcalTxRun */
#define  RF_FCAL_TX_RUN(x)                                  (((x)&0x1u)<<3)               /**< Set RfFcalTxRun in register */
#define  GET_RF_FCAL_TX_RUN(reg)                            (((reg)>>3)&0x1u)             /**< Get RfFcalTxRun from register */
#define  RF_DCOC_RUN_SHIFT                                  4                             /**< Shift for RfDcocRun */
#define  RF_DCOC_RUN_MASK                                   0x00000010u                   /**< Mask for RfDcocRun */
#define  RF_DCOC_RUN_BMASK                                  0x1u                          /**< Base mask for RfDcocRun */
#define  RF_DCOC_RUN(x)                                     (((x)&0x1u)<<4)               /**< Set RfDcocRun in register */
#define  GET_RF_DCOC_RUN(reg)                               (((reg)>>4)&0x1u)             /**< Get RfDcocRun from register */
#define  RF_HPMC_RUN_SHIFT                                  5                             /**< Shift for RfHpmcRun */
#define  RF_HPMC_RUN_MASK                                   0x00000020u                   /**< Mask for RfHpmcRun */
#define  RF_HPMC_RUN_BMASK                                  0x1u                          /**< Base mask for RfHpmcRun */
#define  RF_HPMC_RUN(x)                                     (((x)&0x1u)<<5)               /**< Set RfHpmcRun in register */
#define  GET_RF_HPMC_RUN(reg)                               (((reg)>>5)&0x1u)             /**< Get RfHpmcRun from register */
#define  RF_LOCD_RUN_SHIFT                                  6                             /**< Shift for RfLocdRun */
#define  RF_LOCD_RUN_MASK                                   0x00000040u                   /**< Mask for RfLocdRun */
#define  RF_LOCD_RUN_BMASK                                  0x1u                          /**< Base mask for RfLocdRun */
#define  RF_LOCD_RUN(x)                                     (((x)&0x1u)<<6)               /**< Set RfLocdRun in register */
#define  GET_RF_LOCD_RUN(reg)                               (((reg)>>6)&0x1u)             /**< Get RfLocdRun from register */
#define  RF_DCOC_GAIN_CFG_SHIFT                             7                             /**< Shift for RfDcocGainCfg */
#define  RF_DCOC_GAIN_CFG_MASK                              0x00000080u                   /**< Mask for RfDcocGainCfg */
#define  RF_DCOC_GAIN_CFG_BMASK                             0x1u                          /**< Base mask for RfDcocGainCfg */
#define  RF_DCOC_GAIN_CFG(x)                                (((x)&0x1u)<<7)               /**< Set RfDcocGainCfg in register */
#define  GET_RF_DCOC_GAIN_CFG(reg)                          (((reg)>>7)&0x1u)             /**< Get RfDcocGainCfg from register */
#define  RF_RX_DIG_EN_SHIFT                                 8                             /**< Shift for RfRxDigEn */
#define  RF_RX_DIG_EN_MASK                                  0x00000100u                   /**< Mask for RfRxDigEn */
#define  RF_RX_DIG_EN_BMASK                                 0x1u                          /**< Base mask for RfRxDigEn */
#define  RF_RX_DIG_EN(x)                                    (((x)&0x1u)<<8)               /**< Set RfRxDigEn in register */
#define  GET_RF_RX_DIG_EN(reg)                              (((reg)>>8)&0x1u)             /**< Get RfRxDigEn from register */
#define  RF_TXC_TX_EN_SHIFT                                 9                             /**< Shift for RfTxcTxEn */
#define  RF_TXC_TX_EN_MASK                                  0x00000200u                   /**< Mask for RfTxcTxEn */
#define  RF_TXC_TX_EN_BMASK                                 0x1u                          /**< Base mask for RfTxcTxEn */
#define  RF_TXC_TX_EN(x)                                    (((x)&0x1u)<<9)               /**< Set RfTxcTxEn in register */
#define  GET_RF_TXC_TX_EN(reg)                              (((reg)>>9)&0x1u)             /**< Get RfTxcTxEn from register */
#define  RF_TX_HPM_CAL_EN_SHIFT                             10                            /**< Shift for RfTxHpmCalEn */
#define  RF_TX_HPM_CAL_EN_MASK                              0x00000400u                   /**< Mask for RfTxHpmCalEn */
#define  RF_TX_HPM_CAL_EN_BMASK                             0x1u                          /**< Base mask for RfTxHpmCalEn */
#define  RF_TX_HPM_CAL_EN(x)                                (((x)&0x1u)<<10)              /**< Set RfTxHpmCalEn in register */
#define  GET_RF_TX_HPM_CAL_EN(reg)                          (((reg)>>10)&0x1u)            /**< Get RfTxHpmCalEn from register */
#define  RF_TX_MOD_EN_SHIFT                                 11                            /**< Shift for RfTxModEn */
#define  RF_TX_MOD_EN_MASK                                  0x00000800u                   /**< Mask for RfTxModEn */
#define  RF_TX_MOD_EN_BMASK                                 0x1u                          /**< Base mask for RfTxModEn */
#define  RF_TX_MOD_EN(x)                                    (((x)&0x1u)<<11)              /**< Set RfTxModEn in register */
#define  GET_RF_TX_MOD_EN(reg)                              (((reg)>>11)&0x1u)            /**< Get RfTxModEn from register */
#define  RF_LDOT_RX_RUN_SHIFT                               12                            /**< Shift for RfLdotRxRun */
#define  RF_LDOT_RX_RUN_MASK                                0x00001000u                   /**< Mask for RfLdotRxRun */
#define  RF_LDOT_RX_RUN_BMASK                               0x1u                          /**< Base mask for RfLdotRxRun */
#define  RF_LDOT_RX_RUN(x)                                  (((x)&0x1u)<<12)              /**< Set RfLdotRxRun in register */
#define  GET_RF_LDOT_RX_RUN(reg)                            (((reg)>>12)&0x1u)            /**< Get RfLdotRxRun from register */
#define  RF_FCAL_RX_RUN_SHIFT                               13                            /**< Shift for RfFcalRxRun */
#define  RF_FCAL_RX_RUN_MASK                                0x00002000u                   /**< Mask for RfFcalRxRun */
#define  RF_FCAL_RX_RUN_BMASK                               0x1u                          /**< Base mask for RfFcalRxRun */
#define  RF_FCAL_RX_RUN(x)                                  (((x)&0x1u)<<13)              /**< Set RfFcalRxRun in register */
#define  GET_RF_FCAL_RX_RUN(reg)                            (((reg)>>13)&0x1u)            /**< Get RfFcalRxRun from register */
#define  RF_LDOT_DEBUG_RUN_SHIFT                            14                            /**< Shift for RfLdotDebugRun */
#define  RF_LDOT_DEBUG_RUN_MASK                             0x00004000u                   /**< Mask for RfLdotDebugRun */
#define  RF_LDOT_DEBUG_RUN_BMASK                            0x1u                          /**< Base mask for RfLdotDebugRun */
#define  RF_LDOT_DEBUG_RUN(x)                               (((x)&0x1u)<<14)              /**< Set RfLdotDebugRun in register */
#define  GET_RF_LDOT_DEBUG_RUN(reg)                         (((reg)>>14)&0x1u)            /**< Get RfLdotDebugRun from register */
#define  RF_FCAL_DEBUG_RUN_SHIFT                            15                            /**< Shift for RfFcalDebugRun */
#define  RF_FCAL_DEBUG_RUN_MASK                             0x00008000u                   /**< Mask for RfFcalDebugRun */
#define  RF_FCAL_DEBUG_RUN_BMASK                            0x1u                          /**< Base mask for RfFcalDebugRun */
#define  RF_FCAL_DEBUG_RUN(x)                               (((x)&0x1u)<<15)              /**< Set RfFcalDebugRun in register */
#define  GET_RF_FCAL_DEBUG_RUN(reg)                         (((reg)>>15)&0x1u)            /**< Get RfFcalDebugRun from register */
/** @} */


/**
 * @name RegRfTxrxCbCalCtrl
 * @{
 */
// RegRfTxrxCbCalCtrl.r32
#define  REG_RF_TXRX_CB_CAL_CTRL_RESET_VALUE                0x00000032u                   /**< Reset value of RegRfTxrxCbCalCtrl */
#define  REG_RF_TXRX_CB_CAL_CTRL_MASK                       0x000000FFu                   /**< Mask for RegRfTxrxCbCalCtrl */

#define  RF_LDOT_TX_RUN_DUPLICITE_SHIFT                     0                             /**< Shift for RfLdotTxRunDuplicite */
#define  RF_LDOT_TX_RUN_DUPLICITE_MASK                      0x00000001u                   /**< Mask for RfLdotTxRunDuplicite */
#define  RF_LDOT_TX_RUN_DUPLICITE_BMASK                     0x1u                          /**< Base mask for RfLdotTxRunDuplicite */
#define  RF_LDOT_TX_RUN_DUPLICITE(x)                        (((x)&0x1u)<<0)               /**< Set RfLdotTxRunDuplicite in register */
#define  GET_RF_LDOT_TX_RUN_DUPLICITE(reg)                  (((reg)>>0)&0x1u)             /**< Get RfLdotTxRunDuplicite from register */
#define  RF_FCAL_TX_RUN_DUPLICITE_SHIFT                     1                             /**< Shift for RfFcalTxRunDuplicite */
#define  RF_FCAL_TX_RUN_DUPLICITE_MASK                      0x00000002u                   /**< Mask for RfFcalTxRunDuplicite */
#define  RF_FCAL_TX_RUN_DUPLICITE_BMASK                     0x1u                          /**< Base mask for RfFcalTxRunDuplicite */
#define  RF_FCAL_TX_RUN_DUPLICITE(x)                        (((x)&0x1u)<<1)               /**< Set RfFcalTxRunDuplicite in register */
#define  GET_RF_FCAL_TX_RUN_DUPLICITE(reg)                  (((reg)>>1)&0x1u)             /**< Get RfFcalTxRunDuplicite from register */
#define  RF_HPMC_RUN_DUPLICITE_SHIFT                        2                             /**< Shift for RfHpmcRunDuplicite */
#define  RF_HPMC_RUN_DUPLICITE_MASK                         0x00000004u                   /**< Mask for RfHpmcRunDuplicite */
#define  RF_HPMC_RUN_DUPLICITE_BMASK                        0x1u                          /**< Base mask for RfHpmcRunDuplicite */
#define  RF_HPMC_RUN_DUPLICITE(x)                           (((x)&0x1u)<<2)               /**< Set RfHpmcRunDuplicite in register */
#define  GET_RF_HPMC_RUN_DUPLICITE(reg)                     (((reg)>>2)&0x1u)             /**< Get RfHpmcRunDuplicite from register */
#define  RF_LDOT_RX_RUN_DUPLICITE_SHIFT                     3                             /**< Shift for RfLdotRxRunDuplicite */
#define  RF_LDOT_RX_RUN_DUPLICITE_MASK                      0x00000008u                   /**< Mask for RfLdotRxRunDuplicite */
#define  RF_LDOT_RX_RUN_DUPLICITE_BMASK                     0x1u                          /**< Base mask for RfLdotRxRunDuplicite */
#define  RF_LDOT_RX_RUN_DUPLICITE(x)                        (((x)&0x1u)<<3)               /**< Set RfLdotRxRunDuplicite in register */
#define  GET_RF_LDOT_RX_RUN_DUPLICITE(reg)                  (((reg)>>3)&0x1u)             /**< Get RfLdotRxRunDuplicite from register */
#define  RF_FCAL_RX_RUN_DUPLICITE_SHIFT                     4                             /**< Shift for RfFcalRxRunDuplicite */
#define  RF_FCAL_RX_RUN_DUPLICITE_MASK                      0x00000010u                   /**< Mask for RfFcalRxRunDuplicite */
#define  RF_FCAL_RX_RUN_DUPLICITE_BMASK                     0x1u                          /**< Base mask for RfFcalRxRunDuplicite */
#define  RF_FCAL_RX_RUN_DUPLICITE(x)                        (((x)&0x1u)<<4)               /**< Set RfFcalRxRunDuplicite in register */
#define  GET_RF_FCAL_RX_RUN_DUPLICITE(reg)                  (((reg)>>4)&0x1u)             /**< Get RfFcalRxRunDuplicite from register */
#define  RF_RCCAL_RUN_DUPLICITE_SHIFT                       5                             /**< Shift for RfRccalRunDuplicite */
#define  RF_RCCAL_RUN_DUPLICITE_MASK                        0x00000020u                   /**< Mask for RfRccalRunDuplicite */
#define  RF_RCCAL_RUN_DUPLICITE_BMASK                       0x1u                          /**< Base mask for RfRccalRunDuplicite */
#define  RF_RCCAL_RUN_DUPLICITE(x)                          (((x)&0x1u)<<5)               /**< Set RfRccalRunDuplicite in register */
#define  GET_RF_RCCAL_RUN_DUPLICITE(reg)                    (((reg)>>5)&0x1u)             /**< Get RfRccalRunDuplicite from register */
#define  RF_DCOC_RUN_DUPLICITE_SHIFT                        6                             /**< Shift for RfDcocRunDuplicite */
#define  RF_DCOC_RUN_DUPLICITE_MASK                         0x00000040u                   /**< Mask for RfDcocRunDuplicite */
#define  RF_DCOC_RUN_DUPLICITE_BMASK                        0x1u                          /**< Base mask for RfDcocRunDuplicite */
#define  RF_DCOC_RUN_DUPLICITE(x)                           (((x)&0x1u)<<6)               /**< Set RfDcocRunDuplicite in register */
#define  GET_RF_DCOC_RUN_DUPLICITE(reg)                     (((reg)>>6)&0x1u)             /**< Get RfDcocRunDuplicite from register */
#define  RF_EN_DCOC_ADC_DATA_SHIFT                          7                             /**< Shift for RfEnDcocAdcData */
#define  RF_EN_DCOC_ADC_DATA_MASK                           0x00000080u                   /**< Mask for RfEnDcocAdcData */
#define  RF_EN_DCOC_ADC_DATA_BMASK                          0x1u                          /**< Base mask for RfEnDcocAdcData */
#define  RF_EN_DCOC_ADC_DATA(x)                             (((x)&0x1u)<<7)               /**< Set RfEnDcocAdcData in register */
#define  GET_RF_EN_DCOC_ADC_DATA(reg)                       (((reg)>>7)&0x1u)             /**< Get RfEnDcocAdcData from register */
/** @} */


/**
 * @name RegRfIdleTxSs1Strt
 * @{
 */
// RegRfIdleTxSs1Strt.r32
#define  REG_RF_IDLE_TX_SS1_STRT_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfIdleTxSs1Strt */
#define  REG_RF_IDLE_TX_SS1_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs1Strt */

#define  RF_SS1_START_TIME_SHIFT                            0                             /**< Shift for RfSs1StartTime */
#define  RF_SS1_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs1StartTime */
#define  RF_SS1_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs1StartTime */
#define  RF_SS1_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs1StartTime in register */
#define  GET_RF_SS1_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs1StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs2Strt
 * @{
 */
// RegRfIdleTxSs2Strt.r32
#define  REG_RF_IDLE_TX_SS2_STRT_RESET_VALUE                0x00000021u                   /**< Reset value of RegRfIdleTxSs2Strt */
#define  REG_RF_IDLE_TX_SS2_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs2Strt */

#define  RF_SS2_START_TIME_SHIFT                            0                             /**< Shift for RfSs2StartTime */
#define  RF_SS2_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs2StartTime */
#define  RF_SS2_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs2StartTime */
#define  RF_SS2_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs2StartTime in register */
#define  GET_RF_SS2_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs2StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs3Strt
 * @{
 */
// RegRfIdleTxSs3Strt.r32
#define  REG_RF_IDLE_TX_SS3_STRT_RESET_VALUE                0x000000DBu                   /**< Reset value of RegRfIdleTxSs3Strt */
#define  REG_RF_IDLE_TX_SS3_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs3Strt */

#define  RF_SS3_START_TIME_SHIFT                            0                             /**< Shift for RfSs3StartTime */
#define  RF_SS3_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs3StartTime */
#define  RF_SS3_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs3StartTime */
#define  RF_SS3_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs3StartTime in register */
#define  GET_RF_SS3_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs3StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs4Strt
 * @{
 */
// RegRfIdleTxSs4Strt.r32
#define  REG_RF_IDLE_TX_SS4_STRT_RESET_VALUE                0x000000DCu                   /**< Reset value of RegRfIdleTxSs4Strt */
#define  REG_RF_IDLE_TX_SS4_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs4Strt */

#define  RF_SS4_START_TIME_SHIFT                            0                             /**< Shift for RfSs4StartTime */
#define  RF_SS4_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs4StartTime */
#define  RF_SS4_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs4StartTime */
#define  RF_SS4_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs4StartTime in register */
#define  GET_RF_SS4_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs4StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs5Strt
 * @{
 */
// RegRfIdleTxSs5Strt.r32
#define  REG_RF_IDLE_TX_SS5_STRT_RESET_VALUE                0x000000E1u                   /**< Reset value of RegRfIdleTxSs5Strt */
#define  REG_RF_IDLE_TX_SS5_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs5Strt */

#define  RF_SS5_START_TIME_SHIFT                            0                             /**< Shift for RfSs5StartTime */
#define  RF_SS5_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs5StartTime */
#define  RF_SS5_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs5StartTime */
#define  RF_SS5_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs5StartTime in register */
#define  GET_RF_SS5_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs5StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs6Strt
 * @{
 */
// RegRfIdleTxSs6Strt.r32
#define  REG_RF_IDLE_TX_SS6_STRT_RESET_VALUE                0x000000E1u                   /**< Reset value of RegRfIdleTxSs6Strt */
#define  REG_RF_IDLE_TX_SS6_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs6Strt */

#define  RF_SS6_START_TIME_SHIFT                            0                             /**< Shift for RfSs6StartTime */
#define  RF_SS6_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs6StartTime */
#define  RF_SS6_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs6StartTime */
#define  RF_SS6_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs6StartTime in register */
#define  GET_RF_SS6_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs6StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs7Strt
 * @{
 */
// RegRfIdleTxSs7Strt.r32
#define  REG_RF_IDLE_TX_SS7_STRT_RESET_VALUE                0x000000DBu                   /**< Reset value of RegRfIdleTxSs7Strt */
#define  REG_RF_IDLE_TX_SS7_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleTxSs7Strt */

#define  RF_SS7_START_TIME_SHIFT                            0                             /**< Shift for RfSs7StartTime */
#define  RF_SS7_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs7StartTime */
#define  RF_SS7_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs7StartTime */
#define  RF_SS7_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs7StartTime in register */
#define  GET_RF_SS7_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs7StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs1Strt
 * @{
 */
// RegRfIdleRxSs1Strt.r32
#define  REG_RF_IDLE_RX_SS1_STRT_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfIdleRxSs1Strt */
#define  REG_RF_IDLE_RX_SS1_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs1Strt */

#define  RF_SS1_START_TIME_SHIFT                            0                             /**< Shift for RfSs1StartTime */
#define  RF_SS1_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs1StartTime */
#define  RF_SS1_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs1StartTime */
#define  RF_SS1_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs1StartTime in register */
#define  GET_RF_SS1_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs1StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs2Strt
 * @{
 */
// RegRfIdleRxSs2Strt.r32
#define  REG_RF_IDLE_RX_SS2_STRT_RESET_VALUE                0x00000021u                   /**< Reset value of RegRfIdleRxSs2Strt */
#define  REG_RF_IDLE_RX_SS2_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs2Strt */

#define  RF_SS2_START_TIME_SHIFT                            0                             /**< Shift for RfSs2StartTime */
#define  RF_SS2_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs2StartTime */
#define  RF_SS2_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs2StartTime */
#define  RF_SS2_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs2StartTime in register */
#define  GET_RF_SS2_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs2StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs3Strt
 * @{
 */
// RegRfIdleRxSs3Strt.r32
#define  REG_RF_IDLE_RX_SS3_STRT_RESET_VALUE                0x00000021u                   /**< Reset value of RegRfIdleRxSs3Strt */
#define  REG_RF_IDLE_RX_SS3_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs3Strt */

#define  RF_SS3_START_TIME_SHIFT                            0                             /**< Shift for RfSs3StartTime */
#define  RF_SS3_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs3StartTime */
#define  RF_SS3_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs3StartTime */
#define  RF_SS3_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs3StartTime in register */
#define  GET_RF_SS3_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs3StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs4Strt
 * @{
 */
// RegRfIdleRxSs4Strt.r32
#define  REG_RF_IDLE_RX_SS4_STRT_RESET_VALUE                0x00000054u                   /**< Reset value of RegRfIdleRxSs4Strt */
#define  REG_RF_IDLE_RX_SS4_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs4Strt */

#define  RF_SS4_START_TIME_SHIFT                            0                             /**< Shift for RfSs4StartTime */
#define  RF_SS4_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs4StartTime */
#define  RF_SS4_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs4StartTime */
#define  RF_SS4_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs4StartTime in register */
#define  GET_RF_SS4_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs4StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs5Strt
 * @{
 */
// RegRfIdleRxSs5Strt.r32
#define  REG_RF_IDLE_RX_SS5_STRT_RESET_VALUE                0x000000AAu                   /**< Reset value of RegRfIdleRxSs5Strt */
#define  REG_RF_IDLE_RX_SS5_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs5Strt */

#define  RF_SS5_START_TIME_SHIFT                            0                             /**< Shift for RfSs5StartTime */
#define  RF_SS5_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs5StartTime */
#define  RF_SS5_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs5StartTime */
#define  RF_SS5_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs5StartTime in register */
#define  GET_RF_SS5_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs5StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs6Strt
 * @{
 */
// RegRfIdleRxSs6Strt.r32
#define  REG_RF_IDLE_RX_SS6_STRT_RESET_VALUE                0x000000AAu                   /**< Reset value of RegRfIdleRxSs6Strt */
#define  REG_RF_IDLE_RX_SS6_STRT_MASK                       0x000001FFu                   /**< Mask for RegRfIdleRxSs6Strt */

#define  RF_SS6_START_TIME_SHIFT                            0                             /**< Shift for RfSs6StartTime */
#define  RF_SS6_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs6StartTime */
#define  RF_SS6_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs6StartTime */
#define  RF_SS6_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs6StartTime in register */
#define  GET_RF_SS6_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs6StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs1StrtCb
 * @{
 */
// RegRfIdleTxSs1StrtCb.r32
#define  REG_RF_IDLE_TX_SS1_STRT_CB_RESET_VALUE             0x00000000u                   /**< Reset value of RegRfIdleTxSs1StrtCb */
#define  REG_RF_IDLE_TX_SS1_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs1StrtCb */

#define  RF_SS1_START_TIME_SHIFT                            0                             /**< Shift for RfSs1StartTime */
#define  RF_SS1_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs1StartTime */
#define  RF_SS1_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs1StartTime */
#define  RF_SS1_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs1StartTime in register */
#define  GET_RF_SS1_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs1StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs2StrtCb
 * @{
 */
// RegRfIdleTxSs2StrtCb.r32
#define  REG_RF_IDLE_TX_SS2_STRT_CB_RESET_VALUE             0x00000011u                   /**< Reset value of RegRfIdleTxSs2StrtCb */
#define  REG_RF_IDLE_TX_SS2_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs2StrtCb */

#define  RF_SS2_START_TIME_SHIFT                            0                             /**< Shift for RfSs2StartTime */
#define  RF_SS2_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs2StartTime */
#define  RF_SS2_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs2StartTime */
#define  RF_SS2_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs2StartTime in register */
#define  GET_RF_SS2_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs2StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs3StrtCb
 * @{
 */
// RegRfIdleTxSs3StrtCb.r32
#define  REG_RF_IDLE_TX_SS3_STRT_CB_RESET_VALUE             0x00000062u                   /**< Reset value of RegRfIdleTxSs3StrtCb */
#define  REG_RF_IDLE_TX_SS3_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs3StrtCb */

#define  RF_SS3_START_TIME_SHIFT                            0                             /**< Shift for RfSs3StartTime */
#define  RF_SS3_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs3StartTime */
#define  RF_SS3_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs3StartTime */
#define  RF_SS3_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs3StartTime in register */
#define  GET_RF_SS3_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs3StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs4StrtCb
 * @{
 */
// RegRfIdleTxSs4StrtCb.r32
#define  REG_RF_IDLE_TX_SS4_STRT_CB_RESET_VALUE             0x00000063u                   /**< Reset value of RegRfIdleTxSs4StrtCb */
#define  REG_RF_IDLE_TX_SS4_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs4StrtCb */

#define  RF_SS4_START_TIME_SHIFT                            0                             /**< Shift for RfSs4StartTime */
#define  RF_SS4_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs4StartTime */
#define  RF_SS4_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs4StartTime */
#define  RF_SS4_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs4StartTime in register */
#define  GET_RF_SS4_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs4StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs5StrtCb
 * @{
 */
// RegRfIdleTxSs5StrtCb.r32
#define  REG_RF_IDLE_TX_SS5_STRT_CB_RESET_VALUE             0x00000068u                   /**< Reset value of RegRfIdleTxSs5StrtCb */
#define  REG_RF_IDLE_TX_SS5_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs5StrtCb */

#define  RF_SS5_START_TIME_SHIFT                            0                             /**< Shift for RfSs5StartTime */
#define  RF_SS5_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs5StartTime */
#define  RF_SS5_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs5StartTime */
#define  RF_SS5_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs5StartTime in register */
#define  GET_RF_SS5_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs5StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs6StrtCb
 * @{
 */
// RegRfIdleTxSs6StrtCb.r32
#define  REG_RF_IDLE_TX_SS6_STRT_CB_RESET_VALUE             0x00000068u                   /**< Reset value of RegRfIdleTxSs6StrtCb */
#define  REG_RF_IDLE_TX_SS6_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs6StrtCb */

#define  RF_SS6_START_TIME_SHIFT                            0                             /**< Shift for RfSs6StartTime */
#define  RF_SS6_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs6StartTime */
#define  RF_SS6_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs6StartTime */
#define  RF_SS6_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs6StartTime in register */
#define  GET_RF_SS6_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs6StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs1StrtCb
 * @{
 */
// RegRfIdleRxSs1StrtCb.r32
#define  REG_RF_IDLE_RX_SS1_STRT_CB_RESET_VALUE             0x00000000u                   /**< Reset value of RegRfIdleRxSs1StrtCb */
#define  REG_RF_IDLE_RX_SS1_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs1StrtCb */

#define  RF_SS1_START_TIME_SHIFT                            0                             /**< Shift for RfSs1StartTime */
#define  RF_SS1_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs1StartTime */
#define  RF_SS1_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs1StartTime */
#define  RF_SS1_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs1StartTime in register */
#define  GET_RF_SS1_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs1StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs2StrtCb
 * @{
 */
// RegRfIdleRxSs2StrtCb.r32
#define  REG_RF_IDLE_RX_SS2_STRT_CB_RESET_VALUE             0x00000011u                   /**< Reset value of RegRfIdleRxSs2StrtCb */
#define  REG_RF_IDLE_RX_SS2_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs2StrtCb */

#define  RF_SS2_START_TIME_SHIFT                            0                             /**< Shift for RfSs2StartTime */
#define  RF_SS2_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs2StartTime */
#define  RF_SS2_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs2StartTime */
#define  RF_SS2_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs2StartTime in register */
#define  GET_RF_SS2_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs2StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs3StrtCb
 * @{
 */
// RegRfIdleRxSs3StrtCb.r32
#define  REG_RF_IDLE_RX_SS3_STRT_CB_RESET_VALUE             0x00000011u                   /**< Reset value of RegRfIdleRxSs3StrtCb */
#define  REG_RF_IDLE_RX_SS3_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs3StrtCb */

#define  RF_SS3_START_TIME_SHIFT                            0                             /**< Shift for RfSs3StartTime */
#define  RF_SS3_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs3StartTime */
#define  RF_SS3_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs3StartTime */
#define  RF_SS3_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs3StartTime in register */
#define  GET_RF_SS3_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs3StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs4StrtCb
 * @{
 */
// RegRfIdleRxSs4StrtCb.r32
#define  REG_RF_IDLE_RX_SS4_STRT_CB_RESET_VALUE             0x00000044u                   /**< Reset value of RegRfIdleRxSs4StrtCb */
#define  REG_RF_IDLE_RX_SS4_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs4StrtCb */

#define  RF_SS4_START_TIME_SHIFT                            0                             /**< Shift for RfSs4StartTime */
#define  RF_SS4_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs4StartTime */
#define  RF_SS4_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs4StartTime */
#define  RF_SS4_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs4StartTime in register */
#define  GET_RF_SS4_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs4StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs5StrtCb
 * @{
 */
// RegRfIdleRxSs5StrtCb.r32
#define  REG_RF_IDLE_RX_SS5_STRT_CB_RESET_VALUE             0x00000061u                   /**< Reset value of RegRfIdleRxSs5StrtCb */
#define  REG_RF_IDLE_RX_SS5_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs5StrtCb */

#define  RF_SS5_START_TIME_SHIFT                            0                             /**< Shift for RfSs5StartTime */
#define  RF_SS5_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs5StartTime */
#define  RF_SS5_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs5StartTime */
#define  RF_SS5_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs5StartTime in register */
#define  GET_RF_SS5_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs5StartTime from register */
/** @} */


/**
 * @name RegRfIdleRxSs6StrtCb
 * @{
 */
// RegRfIdleRxSs6StrtCb.r32
#define  REG_RF_IDLE_RX_SS6_STRT_CB_RESET_VALUE             0x00000061u                   /**< Reset value of RegRfIdleRxSs6StrtCb */
#define  REG_RF_IDLE_RX_SS6_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleRxSs6StrtCb */

#define  RF_SS6_START_TIME_SHIFT                            0                             /**< Shift for RfSs6StartTime */
#define  RF_SS6_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs6StartTime */
#define  RF_SS6_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs6StartTime */
#define  RF_SS6_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs6StartTime in register */
#define  GET_RF_SS6_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs6StartTime from register */
/** @} */


/**
 * @name RegRfIdleTxSs7StrtCb
 * @{
 */
// RegRfIdleTxSs7StrtCb.r32
#define  REG_RF_IDLE_TX_SS7_STRT_CB_RESET_VALUE             0x00000062u                   /**< Reset value of RegRfIdleTxSs7StrtCb */
#define  REG_RF_IDLE_TX_SS7_STRT_CB_MASK                    0x000001FFu                   /**< Mask for RegRfIdleTxSs7StrtCb */

#define  RF_SS7_START_TIME_SHIFT                            0                             /**< Shift for RfSs7StartTime */
#define  RF_SS7_START_TIME_MASK                             0x000001FFu                   /**< Mask for RfSs7StartTime */
#define  RF_SS7_START_TIME_BMASK                            0x1FFu                        /**< Base mask for RfSs7StartTime */
#define  RF_SS7_START_TIME(x)                               (((x)&0x1FFu)<<0)             /**< Set RfSs7StartTime in register */
#define  GET_RF_SS7_START_TIME(reg)                         (((reg)>>0)&0x1FFu)           /**< Get RfSs7StartTime from register */
/** @} */


/**
 * @name RegRfLocdTrig
 * @{
 */
// RegRfLocdTrig.r32
#define  REG_RF_LOCD_TRIG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfLocdTrig */
#define  REG_RF_LOCD_TRIG_MASK                              0x00000001u                   /**< Mask for RegRfLocdTrig */

#define  RF_LOCD_TRIG_SHIFT                                 0                             /**< Shift for RfLocdTrig */
#define  RF_LOCD_TRIG_MASK                                  0x00000001u                   /**< Mask for RfLocdTrig */
#define  RF_LOCD_TRIG_BMASK                                 0x1u                          /**< Base mask for RfLocdTrig */
#define  RF_LOCD_TRIG(x)                                    (((x)&0x1u)<<0)               /**< Set RfLocdTrig in register */
#define  GET_RF_LOCD_TRIG(reg)                              (((reg)>>0)&0x1u)             /**< Get RfLocdTrig from register */
/** @} */


/**
 * @name RegRfFcalRdbk
 * @{
 */
// RegRfFcalRdbk.r32
#define  REG_RF_FCAL_RDBK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfFcalRdbk */
#define  REG_RF_FCAL_RDBK_MASK                              0x00003FFFu                   /**< Mask for RegRfFcalRdbk */

#define  RF_FCAL_DEBUG_COUNT_SHIFT                          0                             /**< Shift for RfFcalDebugCount */
#define  RF_FCAL_DEBUG_COUNT_MASK                           0x00001FFFu                   /**< Mask for RfFcalDebugCount */
#define  RF_FCAL_DEBUG_COUNT_BMASK                          0x1FFFu                       /**< Base mask for RfFcalDebugCount */
#define  RF_FCAL_DEBUG_COUNT(x)                             (((x)&0x1FFFu)<<0)            /**< Set RfFcalDebugCount in register */
#define  GET_RF_FCAL_DEBUG_COUNT(reg)                       (((reg)>>0)&0x1FFFu)          /**< Get RfFcalDebugCount from register */
#define  RF_FCAL_PASS_SHIFT                                 13                            /**< Shift for RfFcalPass */
#define  RF_FCAL_PASS_MASK                                  0x00002000u                   /**< Mask for RfFcalPass */
#define  RF_FCAL_PASS_BMASK                                 0x1u                          /**< Base mask for RfFcalPass */
#define  RF_FCAL_PASS(x)                                    (((x)&0x1u)<<13)              /**< Set RfFcalPass in register */
#define  GET_RF_FCAL_PASS(reg)                              (((reg)>>13)&0x1u)            /**< Get RfFcalPass from register */
/** @} */


/**
 * @name RegRfFcalDbg2
 * @{
 */
// RegRfFcalDbg2.r32
#define  REG_RF_FCAL_DBG2_RESET_VALUE                       0x000028C0u                   /**< Reset value of RegRfFcalDbg2 */
#define  REG_RF_FCAL_DBG2_MASK                              0x00003FFFu                   /**< Mask for RegRfFcalDbg2 */

#define  RF_BYPASS_SHIFT                                    0                             /**< Shift for RfBypass */
#define  RF_BYPASS_MASK                                     0x00000001u                   /**< Mask for RfBypass */
#define  RF_BYPASS_BMASK                                    0x1u                          /**< Base mask for RfBypass */
#define  RF_BYPASS(x)                                       (((x)&0x1u)<<0)               /**< Set RfBypass in register */
#define  GET_RF_BYPASS(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfBypass from register */
#define  RF_DCAP_COARSE_OVERWRITE_SHIFT                     1                             /**< Shift for RfDcapCoarseOverwrite */
#define  RF_DCAP_COARSE_OVERWRITE_MASK                      0x0000007Eu                   /**< Mask for RfDcapCoarseOverwrite */
#define  RF_DCAP_COARSE_OVERWRITE_BMASK                     0x3Fu                         /**< Base mask for RfDcapCoarseOverwrite */
#define  RF_DCAP_COARSE_OVERWRITE(x)                        (((x)&0x3Fu)<<1)              /**< Set RfDcapCoarseOverwrite in register */
#define  GET_RF_DCAP_COARSE_OVERWRITE(reg)                  (((reg)>>1)&0x3Fu)            /**< Get RfDcapCoarseOverwrite from register */
#define  RF_DCAP_FINE_OVERWRITE_SHIFT                       7                             /**< Shift for RfDcapFineOverwrite */
#define  RF_DCAP_FINE_OVERWRITE_MASK                        0x00000180u                   /**< Mask for RfDcapFineOverwrite */
#define  RF_DCAP_FINE_OVERWRITE_BMASK                       0x3u                          /**< Base mask for RfDcapFineOverwrite */
#define  RF_DCAP_FINE_OVERWRITE(x)                          (((x)&0x3u)<<7)               /**< Set RfDcapFineOverwrite in register */
#define  GET_RF_DCAP_FINE_OVERWRITE(reg)                    (((reg)>>7)&0x3u)             /**< Get RfDcapFineOverwrite from register */
#define  RF_COUNT_POL_SHIFT                                 9                             /**< Shift for RfCountPol */
#define  RF_COUNT_POL_MASK                                  0x00000200u                   /**< Mask for RfCountPol */
#define  RF_COUNT_POL_BMASK                                 0x1u                          /**< Base mask for RfCountPol */
#define  RF_COUNT_POL(x)                                    (((x)&0x1u)<<9)               /**< Set RfCountPol in register */
#define  GET_RF_COUNT_POL(reg)                              (((reg)>>9)&0x1u)             /**< Get RfCountPol from register */
#define  RF_DEBUG_CNT_SEL_SHIFT                             10                            /**< Shift for RfDebugCntSel */
#define  RF_DEBUG_CNT_SEL_MASK                              0x00003C00u                   /**< Mask for RfDebugCntSel */
#define  RF_DEBUG_CNT_SEL_BMASK                             0xFu                          /**< Base mask for RfDebugCntSel */
#define  RF_DEBUG_CNT_SEL(x)                                (((x)&0xFu)<<10)              /**< Set RfDebugCntSel in register */
#define  GET_RF_DEBUG_CNT_SEL(reg)                          (((reg)>>10)&0xFu)            /**< Get RfDebugCntSel from register */
/** @} */


/**
 * @name RegRfRccalDbg1
 * @{
 */
// RegRfRccalDbg1.r32
#define  REG_RF_RCCAL_DBG1_RESET_VALUE                      0x00002B1Au                   /**< Reset value of RegRfRccalDbg1 */
#define  REG_RF_RCCAL_DBG1_MASK                             0x00007FFFu                   /**< Mask for RegRfRccalDbg1 */

#define  RF_BYPASS_SHIFT                                    0                             /**< Shift for RfBypass */
#define  RF_BYPASS_MASK                                     0x00000001u                   /**< Mask for RfBypass */
#define  RF_BYPASS_BMASK                                    0x1u                          /**< Base mask for RfBypass */
#define  RF_BYPASS(x)                                       (((x)&0x1u)<<0)               /**< Set RfBypass in register */
#define  GET_RF_BYPASS(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfBypass from register */
#define  RF_RCCAL_OVERWRITE_SHIFT                           1                             /**< Shift for RfRccalOverwrite */
#define  RF_RCCAL_OVERWRITE_MASK                            0x0000003Eu                   /**< Mask for RfRccalOverwrite */
#define  RF_RCCAL_OVERWRITE_BMASK                           0x1Fu                         /**< Base mask for RfRccalOverwrite */
#define  RF_RCCAL_OVERWRITE(x)                              (((x)&0x1Fu)<<1)              /**< Set RfRccalOverwrite in register */
#define  GET_RF_RCCAL_OVERWRITE(reg)                        (((reg)>>1)&0x1Fu)            /**< Get RfRccalOverwrite from register */
#define  RF_CBPF_CCODE_BYPASS_SHIFT                         6                             /**< Shift for RfCbpfCcodeBypass */
#define  RF_CBPF_CCODE_BYPASS_MASK                          0x00000040u                   /**< Mask for RfCbpfCcodeBypass */
#define  RF_CBPF_CCODE_BYPASS_BMASK                         0x1u                          /**< Base mask for RfCbpfCcodeBypass */
#define  RF_CBPF_CCODE_BYPASS(x)                            (((x)&0x1u)<<6)               /**< Set RfCbpfCcodeBypass in register */
#define  GET_RF_CBPF_CCODE_BYPASS(reg)                      (((reg)>>6)&0x1u)             /**< Get RfCbpfCcodeBypass from register */
#define  RF_CBPF_CCODE_OVERWRITE_SHIFT                      7                             /**< Shift for RfCbpfCcodeOverwrite */
#define  RF_CBPF_CCODE_OVERWRITE_MASK                       0x00003F80u                   /**< Mask for RfCbpfCcodeOverwrite */
#define  RF_CBPF_CCODE_OVERWRITE_BMASK                      0x7Fu                         /**< Base mask for RfCbpfCcodeOverwrite */
#define  RF_CBPF_CCODE_OVERWRITE(x)                         (((x)&0x7Fu)<<7)              /**< Set RfCbpfCcodeOverwrite in register */
#define  GET_RF_CBPF_CCODE_OVERWRITE(reg)                   (((reg)>>7)&0x7Fu)            /**< Get RfCbpfCcodeOverwrite from register */
#define  RF_COMP_POL_SHIFT                                  14                            /**< Shift for RfCompPol */
#define  RF_COMP_POL_MASK                                   0x00004000u                   /**< Mask for RfCompPol */
#define  RF_COMP_POL_BMASK                                  0x1u                          /**< Base mask for RfCompPol */
#define  RF_COMP_POL(x)                                     (((x)&0x1u)<<14)              /**< Set RfCompPol in register */
#define  GET_RF_COMP_POL(reg)                               (((reg)>>14)&0x1u)            /**< Get RfCompPol from register */
/** @} */


/**
 * @name RegRfRccalDbg2
 * @{
 */
// RegRfRccalDbg2.r32
#define  REG_RF_RCCAL_DBG2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfRccalDbg2 */
#define  REG_RF_RCCAL_DBG2_MASK                             0x00000007u                   /**< Mask for RegRfRccalDbg2 */

#define  RF_RCCAL_CBPF_OFFSET_SHIFT                         0                             /**< Shift for RfRccalCbpfOffset */
#define  RF_RCCAL_CBPF_OFFSET_MASK                          0x00000007u                   /**< Mask for RfRccalCbpfOffset */
#define  RF_RCCAL_CBPF_OFFSET_BMASK                         0x7u                          /**< Base mask for RfRccalCbpfOffset */
#define  RF_RCCAL_CBPF_OFFSET(x)                            (((x)&0x7u)<<0)               /**< Set RfRccalCbpfOffset in register */
#define  GET_RF_RCCAL_CBPF_OFFSET(reg)                      (((reg)>>0)&0x7u)             /**< Get RfRccalCbpfOffset from register */
/** @} */


/**
 * @name RegRfRccalRdbk
 * @{
 */
// RegRfRccalRdbk.r32
#define  REG_RF_RCCAL_RDBK_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfRccalRdbk */
#define  REG_RF_RCCAL_RDBK_MASK                             0x00000FFFu                   /**< Mask for RegRfRccalRdbk */

#define  RF_RCCAL_CODE_SHIFT                                0                             /**< Shift for RfRccalCode */
#define  RF_RCCAL_CODE_MASK                                 0x0000001Fu                   /**< Mask for RfRccalCode */
#define  RF_RCCAL_CODE_BMASK                                0x1Fu                         /**< Base mask for RfRccalCode */
#define  RF_RCCAL_CODE(x)                                   (((x)&0x1Fu)<<0)              /**< Set RfRccalCode in register */
#define  GET_RF_RCCAL_CODE(reg)                             (((reg)>>0)&0x1Fu)            /**< Get RfRccalCode from register */
#define  RF_CBPF_CCODE_SHIFT                                5                             /**< Shift for RfCbpfCcode */
#define  RF_CBPF_CCODE_MASK                                 0x00000FE0u                   /**< Mask for RfCbpfCcode */
#define  RF_CBPF_CCODE_BMASK                                0x7Fu                         /**< Base mask for RfCbpfCcode */
#define  RF_CBPF_CCODE(x)                                   (((x)&0x7Fu)<<5)              /**< Set RfCbpfCcode in register */
#define  GET_RF_CBPF_CCODE(reg)                             (((reg)>>5)&0x7Fu)            /**< Get RfCbpfCcode from register */
/** @} */


/**
 * @name RegRfDcocBypassAdc
 * @{
 */
// RegRfDcocBypassAdc.r32
#define  REG_RF_DCOC_BYPASS_ADC_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfDcocBypassAdc */
#define  REG_RF_DCOC_BYPASS_ADC_MASK                        0x00007FFFu                   /**< Mask for RegRfDcocBypassAdc */

#define  RF_DCOC_BYPASS_ADC_SHIFT                           0                             /**< Shift for RfDcocBypassAdc */
#define  RF_DCOC_BYPASS_ADC_MASK                            0x00000001u                   /**< Mask for RfDcocBypassAdc */
#define  RF_DCOC_BYPASS_ADC_BMASK                           0x1u                          /**< Base mask for RfDcocBypassAdc */
#define  RF_DCOC_BYPASS_ADC(x)                              (((x)&0x1u)<<0)               /**< Set RfDcocBypassAdc in register */
#define  GET_RF_DCOC_BYPASS_ADC(reg)                        (((reg)>>0)&0x1u)             /**< Get RfDcocBypassAdc from register */
#define  RF_DCOC_IADC_OFFSET_OVERWRITE_SHIFT                1                             /**< Shift for RfDcocIadcOffsetOverwrite */
#define  RF_DCOC_IADC_OFFSET_OVERWRITE_MASK                 0x000000FEu                   /**< Mask for RfDcocIadcOffsetOverwrite */
#define  RF_DCOC_IADC_OFFSET_OVERWRITE_BMASK                0x7Fu                         /**< Base mask for RfDcocIadcOffsetOverwrite */
#define  RF_DCOC_IADC_OFFSET_OVERWRITE(x)                   (((x)&0x7Fu)<<1)              /**< Set RfDcocIadcOffsetOverwrite in register */
#define  GET_RF_DCOC_IADC_OFFSET_OVERWRITE(reg)             (((reg)>>1)&0x7Fu)            /**< Get RfDcocIadcOffsetOverwrite from register */
#define  RF_DCOC_QADC_OFFSET_OVERWRITE_SHIFT                8                             /**< Shift for RfDcocQadcOffsetOverwrite */
#define  RF_DCOC_QADC_OFFSET_OVERWRITE_MASK                 0x00007F00u                   /**< Mask for RfDcocQadcOffsetOverwrite */
#define  RF_DCOC_QADC_OFFSET_OVERWRITE_BMASK                0x7Fu                         /**< Base mask for RfDcocQadcOffsetOverwrite */
#define  RF_DCOC_QADC_OFFSET_OVERWRITE(x)                   (((x)&0x7Fu)<<8)              /**< Set RfDcocQadcOffsetOverwrite in register */
#define  GET_RF_DCOC_QADC_OFFSET_OVERWRITE(reg)             (((reg)>>8)&0x7Fu)            /**< Get RfDcocQadcOffsetOverwrite from register */
/** @} */


/**
 * @name RegRfDcocBypassDac
 * @{
 */
// RegRfDcocBypassDac.r32
#define  REG_RF_DCOC_BYPASS_DAC_RESET_VALUE                 0x00001040u                   /**< Reset value of RegRfDcocBypassDac */
#define  REG_RF_DCOC_BYPASS_DAC_MASK                        0x00001FFFu                   /**< Mask for RegRfDcocBypassDac */

#define  RF_DCOC_BYPASS_DAC_SHIFT                           0                             /**< Shift for RfDcocBypassDac */
#define  RF_DCOC_BYPASS_DAC_MASK                            0x00000001u                   /**< Mask for RfDcocBypassDac */
#define  RF_DCOC_BYPASS_DAC_BMASK                           0x1u                          /**< Base mask for RfDcocBypassDac */
#define  RF_DCOC_BYPASS_DAC(x)                              (((x)&0x1u)<<0)               /**< Set RfDcocBypassDac in register */
#define  GET_RF_DCOC_BYPASS_DAC(reg)                        (((reg)>>0)&0x1u)             /**< Get RfDcocBypassDac from register */
#define  RF_DCOC_IDAC_CODE_OVERWRITE_SHIFT                  1                             /**< Shift for RfDcocIdacCodeOverwrite */
#define  RF_DCOC_IDAC_CODE_OVERWRITE_MASK                   0x0000007Eu                   /**< Mask for RfDcocIdacCodeOverwrite */
#define  RF_DCOC_IDAC_CODE_OVERWRITE_BMASK                  0x3Fu                         /**< Base mask for RfDcocIdacCodeOverwrite */
#define  RF_DCOC_IDAC_CODE_OVERWRITE(x)                     (((x)&0x3Fu)<<1)              /**< Set RfDcocIdacCodeOverwrite in register */
#define  GET_RF_DCOC_IDAC_CODE_OVERWRITE(reg)               (((reg)>>1)&0x3Fu)            /**< Get RfDcocIdacCodeOverwrite from register */
#define  RF_DCOC_QDAC_CODE_OVERWRITE_SHIFT                  7                             /**< Shift for RfDcocQdacCodeOverwrite */
#define  RF_DCOC_QDAC_CODE_OVERWRITE_MASK                   0x00001F80u                   /**< Mask for RfDcocQdacCodeOverwrite */
#define  RF_DCOC_QDAC_CODE_OVERWRITE_BMASK                  0x3Fu                         /**< Base mask for RfDcocQdacCodeOverwrite */
#define  RF_DCOC_QDAC_CODE_OVERWRITE(x)                     (((x)&0x3Fu)<<7)              /**< Set RfDcocQdacCodeOverwrite in register */
#define  GET_RF_DCOC_QDAC_CODE_OVERWRITE(reg)               (((reg)>>7)&0x3Fu)            /**< Get RfDcocQdacCodeOverwrite from register */
/** @} */


/**
 * @name RegRfDcocDbg
 * @{
 */
// RegRfDcocDbg.r32
#define  REG_RF_DCOC_DBG_RESET_VALUE                        0x000015BBu                   /**< Reset value of RegRfDcocDbg */
#define  REG_RF_DCOC_DBG_MASK                               0x00007FFFu                   /**< Mask for RegRfDcocDbg */

#define  RF_DCOC_SFIQ_SHIFT                                 0                             /**< Shift for RfDcocSfiq */
#define  RF_DCOC_SFIQ_MASK                                  0x00000001u                   /**< Mask for RfDcocSfiq */
#define  RF_DCOC_SFIQ_BMASK                                 0x1u                          /**< Base mask for RfDcocSfiq */
#define  RF_DCOC_SFIQ(x)                                    (((x)&0x1u)<<0)               /**< Set RfDcocSfiq in register */
#define  GET_RF_DCOC_SFIQ(reg)                              (((reg)>>0)&0x1u)             /**< Get RfDcocSfiq from register */
#define  RF_DCOC_SFQI_SHIFT                                 1                             /**< Shift for RfDcocSfqi */
#define  RF_DCOC_SFQI_MASK                                  0x00000002u                   /**< Mask for RfDcocSfqi */
#define  RF_DCOC_SFQI_BMASK                                 0x1u                          /**< Base mask for RfDcocSfqi */
#define  RF_DCOC_SFQI(x)                                    (((x)&0x1u)<<1)               /**< Set RfDcocSfqi in register */
#define  GET_RF_DCOC_SFQI(reg)                              (((reg)>>1)&0x1u)             /**< Get RfDcocSfqi from register */
#define  RF_DCOC_IDAC_SRC_POL_SHIFT                         2                             /**< Shift for RfDcocIdacSrcPol */
#define  RF_DCOC_IDAC_SRC_POL_MASK                          0x00000004u                   /**< Mask for RfDcocIdacSrcPol */
#define  RF_DCOC_IDAC_SRC_POL_BMASK                         0x1u                          /**< Base mask for RfDcocIdacSrcPol */
#define  RF_DCOC_IDAC_SRC_POL(x)                            (((x)&0x1u)<<2)               /**< Set RfDcocIdacSrcPol in register */
#define  GET_RF_DCOC_IDAC_SRC_POL(reg)                      (((reg)>>2)&0x1u)             /**< Get RfDcocIdacSrcPol from register */
#define  RF_DCOC_QDAC_SRC_POL_SHIFT                         3                             /**< Shift for RfDcocQdacSrcPol */
#define  RF_DCOC_QDAC_SRC_POL_MASK                          0x00000008u                   /**< Mask for RfDcocQdacSrcPol */
#define  RF_DCOC_QDAC_SRC_POL_BMASK                         0x1u                          /**< Base mask for RfDcocQdacSrcPol */
#define  RF_DCOC_QDAC_SRC_POL(x)                            (((x)&0x1u)<<3)               /**< Set RfDcocQdacSrcPol in register */
#define  GET_RF_DCOC_QDAC_SRC_POL(reg)                      (((reg)>>3)&0x1u)             /**< Get RfDcocQdacSrcPol from register */
#define  RF_DCOC_SFIIP_SHIFT                                4                             /**< Shift for RfDcocSfiip */
#define  RF_DCOC_SFIIP_MASK                                 0x00000010u                   /**< Mask for RfDcocSfiip */
#define  RF_DCOC_SFIIP_BMASK                                0x1u                          /**< Base mask for RfDcocSfiip */
#define  RF_DCOC_SFIIP(x)                                   (((x)&0x1u)<<4)               /**< Set RfDcocSfiip in register */
#define  GET_RF_DCOC_SFIIP(reg)                             (((reg)>>4)&0x1u)             /**< Get RfDcocSfiip from register */
#define  RF_DCOC_SFQQP_SHIFT                                5                             /**< Shift for RfDcocSfqqp */
#define  RF_DCOC_SFQQP_MASK                                 0x00000020u                   /**< Mask for RfDcocSfqqp */
#define  RF_DCOC_SFQQP_BMASK                                0x1u                          /**< Base mask for RfDcocSfqqp */
#define  RF_DCOC_SFQQP(x)                                   (((x)&0x1u)<<5)               /**< Set RfDcocSfqqp in register */
#define  GET_RF_DCOC_SFQQP(reg)                             (((reg)>>5)&0x1u)             /**< Get RfDcocSfqqp from register */
#define  RF_DCOC_SFII_SHIFT                                 6                             /**< Shift for RfDcocSfii */
#define  RF_DCOC_SFII_MASK                                  0x000003C0u                   /**< Mask for RfDcocSfii */
#define  RF_DCOC_SFII_BMASK                                 0xFu                          /**< Base mask for RfDcocSfii */
#define  RF_DCOC_SFII(x)                                    (((x)&0xFu)<<6)               /**< Set RfDcocSfii in register */
#define  GET_RF_DCOC_SFII(reg)                              (((reg)>>6)&0xFu)             /**< Get RfDcocSfii from register */
#define  RF_DCOC_SFQQ_SHIFT                                 10                            /**< Shift for RfDcocSfqq */
#define  RF_DCOC_SFQQ_MASK                                  0x00003C00u                   /**< Mask for RfDcocSfqq */
#define  RF_DCOC_SFQQ_BMASK                                 0xFu                          /**< Base mask for RfDcocSfqq */
#define  RF_DCOC_SFQQ(x)                                    (((x)&0xFu)<<10)              /**< Set RfDcocSfqq in register */
#define  GET_RF_DCOC_SFQQ(reg)                              (((reg)>>10)&0xFu)            /**< Get RfDcocSfqq from register */
#define  RF_DCOC_DAC_ORDER_SHIFT                            14                            /**< Shift for RfDcocDacOrder */
#define  RF_DCOC_DAC_ORDER_MASK                             0x00004000u                   /**< Mask for RfDcocDacOrder */
#define  RF_DCOC_DAC_ORDER_BMASK                            0x1u                          /**< Base mask for RfDcocDacOrder */
#define  RF_DCOC_DAC_ORDER(x)                               (((x)&0x1u)<<14)              /**< Set RfDcocDacOrder in register */
#define  GET_RF_DCOC_DAC_ORDER(reg)                         (((reg)>>14)&0x1u)            /**< Get RfDcocDacOrder from register */
/** @} */


/**
 * @name RegRfDcocLnaOffset
 * @{
 */
// RegRfDcocLnaOffset.r32
#define  REG_RF_DCOC_LNA_OFFSET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfDcocLnaOffset */
#define  REG_RF_DCOC_LNA_OFFSET_MASK                        0x00000FFFu                   /**< Mask for RegRfDcocLnaOffset */

#define  RF_DCOC_ILNA_OFFSET_SHIFT                          0                             /**< Shift for RfDcocIlnaOffset */
#define  RF_DCOC_ILNA_OFFSET_MASK                           0x0000003Fu                   /**< Mask for RfDcocIlnaOffset */
#define  RF_DCOC_ILNA_OFFSET_BMASK                          0x3Fu                         /**< Base mask for RfDcocIlnaOffset */
#define  RF_DCOC_ILNA_OFFSET(x)                             (((x)&0x3Fu)<<0)              /**< Set RfDcocIlnaOffset in register */
#define  GET_RF_DCOC_ILNA_OFFSET(reg)                       (((reg)>>0)&0x3Fu)            /**< Get RfDcocIlnaOffset from register */
#define  RF_DCOC_QLNA_OFFSET_SHIFT                          6                             /**< Shift for RfDcocQlnaOffset */
#define  RF_DCOC_QLNA_OFFSET_MASK                           0x00000FC0u                   /**< Mask for RfDcocQlnaOffset */
#define  RF_DCOC_QLNA_OFFSET_BMASK                          0x3Fu                         /**< Base mask for RfDcocQlnaOffset */
#define  RF_DCOC_QLNA_OFFSET(x)                             (((x)&0x3Fu)<<6)              /**< Set RfDcocQlnaOffset in register */
#define  GET_RF_DCOC_QLNA_OFFSET(reg)                       (((reg)>>6)&0x3Fu)            /**< Get RfDcocQlnaOffset from register */
/** @} */


/**
 * @name RegRfDcocCbpfOffset
 * @{
 */
// RegRfDcocCbpfOffset.r32
#define  REG_RF_DCOC_CBPF_OFFSET_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfDcocCbpfOffset */
#define  REG_RF_DCOC_CBPF_OFFSET_MASK                       0x00000FFFu                   /**< Mask for RegRfDcocCbpfOffset */

#define  RF_DCOC_ICBPF_OFFSET_SHIFT                         0                             /**< Shift for RfDcocIcbpfOffset */
#define  RF_DCOC_ICBPF_OFFSET_MASK                          0x0000003Fu                   /**< Mask for RfDcocIcbpfOffset */
#define  RF_DCOC_ICBPF_OFFSET_BMASK                         0x3Fu                         /**< Base mask for RfDcocIcbpfOffset */
#define  RF_DCOC_ICBPF_OFFSET(x)                            (((x)&0x3Fu)<<0)              /**< Set RfDcocIcbpfOffset in register */
#define  GET_RF_DCOC_ICBPF_OFFSET(reg)                      (((reg)>>0)&0x3Fu)            /**< Get RfDcocIcbpfOffset from register */
#define  RF_DCOC_QCBPF_OFFSET_SHIFT                         6                             /**< Shift for RfDcocQcbpfOffset */
#define  RF_DCOC_QCBPF_OFFSET_MASK                          0x00000FC0u                   /**< Mask for RfDcocQcbpfOffset */
#define  RF_DCOC_QCBPF_OFFSET_BMASK                         0x3Fu                         /**< Base mask for RfDcocQcbpfOffset */
#define  RF_DCOC_QCBPF_OFFSET(x)                            (((x)&0x3Fu)<<6)              /**< Set RfDcocQcbpfOffset in register */
#define  GET_RF_DCOC_QCBPF_OFFSET(reg)                      (((reg)>>6)&0x3Fu)            /**< Get RfDcocQcbpfOffset from register */
/** @} */


/**
 * @name RegRfDcocRdbk1
 * @{
 */
// RegRfDcocRdbk1.r32
#define  REG_RF_DCOC_RDBK1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfDcocRdbk1 */
#define  REG_RF_DCOC_RDBK1_MASK                             0x00000FFFu                   /**< Mask for RegRfDcocRdbk1 */

#define  RF_DCOC_IDAC_CODE_SHIFT                            0                             /**< Shift for RfDcocIdacCode */
#define  RF_DCOC_IDAC_CODE_MASK                             0x0000003Fu                   /**< Mask for RfDcocIdacCode */
#define  RF_DCOC_IDAC_CODE_BMASK                            0x3Fu                         /**< Base mask for RfDcocIdacCode */
#define  RF_DCOC_IDAC_CODE(x)                               (((x)&0x3Fu)<<0)              /**< Set RfDcocIdacCode in register */
#define  GET_RF_DCOC_IDAC_CODE(reg)                         (((reg)>>0)&0x3Fu)            /**< Get RfDcocIdacCode from register */
#define  RF_NOT_USED_SHIFT                                  6                             /**< Shift for RfNotUsed */
#define  RF_NOT_USED_MASK                                   0x00000FC0u                   /**< Mask for RfNotUsed */
#define  RF_NOT_USED_BMASK                                  0x3Fu                         /**< Base mask for RfNotUsed */
#define  RF_NOT_USED(x)                                     (((x)&0x3Fu)<<6)              /**< Set RfNotUsed in register */
#define  GET_RF_NOT_USED(reg)                               (((reg)>>6)&0x3Fu)            /**< Get RfNotUsed from register */
/** @} */


/**
 * @name RegRfDcocRdbk2
 * @{
 */
// RegRfDcocRdbk2.r32
#define  REG_RF_DCOC_RDBK2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfDcocRdbk2 */
#define  REG_RF_DCOC_RDBK2_MASK                             0x0000003Fu                   /**< Mask for RegRfDcocRdbk2 */

#define  RF_DCOC_QDAC_CODE_SHIFT                            0                             /**< Shift for RfDcocQdacCode */
#define  RF_DCOC_QDAC_CODE_MASK                             0x0000003Fu                   /**< Mask for RfDcocQdacCode */
#define  RF_DCOC_QDAC_CODE_BMASK                            0x3Fu                         /**< Base mask for RfDcocQdacCode */
#define  RF_DCOC_QDAC_CODE(x)                               (((x)&0x3Fu)<<0)              /**< Set RfDcocQdacCode in register */
#define  GET_RF_DCOC_QDAC_CODE(reg)                         (((reg)>>0)&0x3Fu)            /**< Get RfDcocQdacCode from register */
/** @} */


/**
 * @name RegRfDcocRdbk3
 * @{
 */
// RegRfDcocRdbk3.r32
#define  REG_RF_DCOC_RDBK3_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfDcocRdbk3 */
#define  REG_RF_DCOC_RDBK3_MASK                             0x00003FFFu                   /**< Mask for RegRfDcocRdbk3 */

#define  RF_DCOC_IADC_OFFSET_SHIFT                          0                             /**< Shift for RfDcocIadcOffset */
#define  RF_DCOC_IADC_OFFSET_MASK                           0x0000007Fu                   /**< Mask for RfDcocIadcOffset */
#define  RF_DCOC_IADC_OFFSET_BMASK                          0x7Fu                         /**< Base mask for RfDcocIadcOffset */
#define  RF_DCOC_IADC_OFFSET(x)                             (((x)&0x7Fu)<<0)              /**< Set RfDcocIadcOffset in register */
#define  GET_RF_DCOC_IADC_OFFSET(reg)                       (((reg)>>0)&0x7Fu)            /**< Get RfDcocIadcOffset from register */
#define  RF_DCOC_QADC_OFFSET_SHIFT                          7                             /**< Shift for RfDcocQadcOffset */
#define  RF_DCOC_QADC_OFFSET_MASK                           0x00003F80u                   /**< Mask for RfDcocQadcOffset */
#define  RF_DCOC_QADC_OFFSET_BMASK                          0x7Fu                         /**< Base mask for RfDcocQadcOffset */
#define  RF_DCOC_QADC_OFFSET(x)                             (((x)&0x7Fu)<<7)              /**< Set RfDcocQadcOffset in register */
#define  GET_RF_DCOC_QADC_OFFSET(reg)                       (((reg)>>7)&0x7Fu)            /**< Get RfDcocQadcOffset from register */
/** @} */


/**
 * @name RegRfLdotDbg1
 * @{
 */
// RegRfLdotDbg1.r32
#define  REG_RF_LDOT_DBG1_RESET_VALUE                       0x00000030u                   /**< Reset value of RegRfLdotDbg1 */
#define  REG_RF_LDOT_DBG1_MASK                              0x0000007Fu                   /**< Mask for RegRfLdotDbg1 */

#define  RF_LDOT_LDO_CAL_BYPASS_SHIFT                       0                             /**< Shift for RfLdotLdoCalBypass */
#define  RF_LDOT_LDO_CAL_BYPASS_MASK                        0x00000001u                   /**< Mask for RfLdotLdoCalBypass */
#define  RF_LDOT_LDO_CAL_BYPASS_BMASK                       0x1u                          /**< Base mask for RfLdotLdoCalBypass */
#define  RF_LDOT_LDO_CAL_BYPASS(x)                          (((x)&0x1u)<<0)               /**< Set RfLdotLdoCalBypass in register */
#define  GET_RF_LDOT_LDO_CAL_BYPASS(reg)                    (((reg)>>0)&0x1u)             /**< Get RfLdotLdoCalBypass from register */
#define  RF_LDOT_LDO_CAL_TRIM_OVERWRITE_SHIFT               1                             /**< Shift for RfLdotLdoCalTrimOverwrite */
#define  RF_LDOT_LDO_CAL_TRIM_OVERWRITE_MASK                0x0000007Eu                   /**< Mask for RfLdotLdoCalTrimOverwrite */
#define  RF_LDOT_LDO_CAL_TRIM_OVERWRITE_BMASK               0x3Fu                         /**< Base mask for RfLdotLdoCalTrimOverwrite */
#define  RF_LDOT_LDO_CAL_TRIM_OVERWRITE(x)                  (((x)&0x3Fu)<<1)              /**< Set RfLdotLdoCalTrimOverwrite in register */
#define  GET_RF_LDOT_LDO_CAL_TRIM_OVERWRITE(reg)            (((reg)>>1)&0x3Fu)            /**< Get RfLdotLdoCalTrimOverwrite from register */
/** @} */


/**
 * @name RegRfLdotDbg2
 * @{
 */
// RegRfLdotDbg2.r32
#define  REG_RF_LDOT_DBG2_RESET_VALUE                       0x00001860u                   /**< Reset value of RegRfLdotDbg2 */
#define  REG_RF_LDOT_DBG2_MASK                              0x00003FFFu                   /**< Mask for RegRfLdotDbg2 */

#define  RF_LDOT_LDO_RXTXHF_BYPASS_SHIFT                    0                             /**< Shift for RfLdotLdoRxtxhfBypass */
#define  RF_LDOT_LDO_RXTXHF_BYPASS_MASK                     0x00000001u                   /**< Mask for RfLdotLdoRxtxhfBypass */
#define  RF_LDOT_LDO_RXTXHF_BYPASS_BMASK                    0x1u                          /**< Base mask for RfLdotLdoRxtxhfBypass */
#define  RF_LDOT_LDO_RXTXHF_BYPASS(x)                       (((x)&0x1u)<<0)               /**< Set RfLdotLdoRxtxhfBypass in register */
#define  GET_RF_LDOT_LDO_RXTXHF_BYPASS(reg)                 (((reg)>>0)&0x1u)             /**< Get RfLdotLdoRxtxhfBypass from register */
#define  RF_LDOT_LDO_RXTXLF_BYPASS_SHIFT                    1                             /**< Shift for RfLdotLdoRxtxlfBypass */
#define  RF_LDOT_LDO_RXTXLF_BYPASS_MASK                     0x00000002u                   /**< Mask for RfLdotLdoRxtxlfBypass */
#define  RF_LDOT_LDO_RXTXLF_BYPASS_BMASK                    0x1u                          /**< Base mask for RfLdotLdoRxtxlfBypass */
#define  RF_LDOT_LDO_RXTXLF_BYPASS(x)                       (((x)&0x1u)<<1)               /**< Set RfLdotLdoRxtxlfBypass in register */
#define  GET_RF_LDOT_LDO_RXTXLF_BYPASS(reg)                 (((reg)>>1)&0x1u)             /**< Get RfLdotLdoRxtxlfBypass from register */
#define  RF_LDOT_LDO_RXTXHF_TRIM_OVERWRITE_SHIFT            2                             /**< Shift for RfLdotLdoRxtxhfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXHF_TRIM_OVERWRITE_MASK             0x000000FCu                   /**< Mask for RfLdotLdoRxtxhfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXHF_TRIM_OVERWRITE_BMASK            0x3Fu                         /**< Base mask for RfLdotLdoRxtxhfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXHF_TRIM_OVERWRITE(x)               (((x)&0x3Fu)<<2)              /**< Set RfLdotLdoRxtxhfTrimOverwrite in register */
#define  GET_RF_LDOT_LDO_RXTXHF_TRIM_OVERWRITE(reg)         (((reg)>>2)&0x3Fu)            /**< Get RfLdotLdoRxtxhfTrimOverwrite from register */
#define  RF_LDOT_LDO_RXTXLF_TRIM_OVERWRITE_SHIFT            8                             /**< Shift for RfLdotLdoRxtxlfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXLF_TRIM_OVERWRITE_MASK             0x00003F00u                   /**< Mask for RfLdotLdoRxtxlfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXLF_TRIM_OVERWRITE_BMASK            0x3Fu                         /**< Base mask for RfLdotLdoRxtxlfTrimOverwrite */
#define  RF_LDOT_LDO_RXTXLF_TRIM_OVERWRITE(x)               (((x)&0x3Fu)<<8)              /**< Set RfLdotLdoRxtxlfTrimOverwrite in register */
#define  GET_RF_LDOT_LDO_RXTXLF_TRIM_OVERWRITE(reg)         (((reg)>>8)&0x3Fu)            /**< Get RfLdotLdoRxtxlfTrimOverwrite from register */
/** @} */


/**
 * @name RegRfLdotDbg3
 * @{
 */
// RegRfLdotDbg3.r32
#define  REG_RF_LDOT_DBG3_RESET_VALUE                       0x00001860u                   /**< Reset value of RegRfLdotDbg3 */
#define  REG_RF_LDOT_DBG3_MASK                              0x00003FFFu                   /**< Mask for RegRfLdotDbg3 */

#define  RF_LDOT_LDO_PLL_BYPASS_SHIFT                       0                             /**< Shift for RfLdotLdoPllBypass */
#define  RF_LDOT_LDO_PLL_BYPASS_MASK                        0x00000001u                   /**< Mask for RfLdotLdoPllBypass */
#define  RF_LDOT_LDO_PLL_BYPASS_BMASK                       0x1u                          /**< Base mask for RfLdotLdoPllBypass */
#define  RF_LDOT_LDO_PLL_BYPASS(x)                          (((x)&0x1u)<<0)               /**< Set RfLdotLdoPllBypass in register */
#define  GET_RF_LDOT_LDO_PLL_BYPASS(reg)                    (((reg)>>0)&0x1u)             /**< Get RfLdotLdoPllBypass from register */
#define  RF_LDOT_LDO_VCO_BYPASS_SHIFT                       1                             /**< Shift for RfLdotLdoVcoBypass */
#define  RF_LDOT_LDO_VCO_BYPASS_MASK                        0x00000002u                   /**< Mask for RfLdotLdoVcoBypass */
#define  RF_LDOT_LDO_VCO_BYPASS_BMASK                       0x1u                          /**< Base mask for RfLdotLdoVcoBypass */
#define  RF_LDOT_LDO_VCO_BYPASS(x)                          (((x)&0x1u)<<1)               /**< Set RfLdotLdoVcoBypass in register */
#define  GET_RF_LDOT_LDO_VCO_BYPASS(reg)                    (((reg)>>1)&0x1u)             /**< Get RfLdotLdoVcoBypass from register */
#define  RF_LDOT_LDO_PLL_TRIM_OVERWRITE_SHIFT               2                             /**< Shift for RfLdotLdoPllTrimOverwrite */
#define  RF_LDOT_LDO_PLL_TRIM_OVERWRITE_MASK                0x000000FCu                   /**< Mask for RfLdotLdoPllTrimOverwrite */
#define  RF_LDOT_LDO_PLL_TRIM_OVERWRITE_BMASK               0x3Fu                         /**< Base mask for RfLdotLdoPllTrimOverwrite */
#define  RF_LDOT_LDO_PLL_TRIM_OVERWRITE(x)                  (((x)&0x3Fu)<<2)              /**< Set RfLdotLdoPllTrimOverwrite in register */
#define  GET_RF_LDOT_LDO_PLL_TRIM_OVERWRITE(reg)            (((reg)>>2)&0x3Fu)            /**< Get RfLdotLdoPllTrimOverwrite from register */
#define  RF_LDOT_LDO_VCO_TRIM_OVERWRITE_SHIFT               8                             /**< Shift for RfLdotLdoVcoTrimOverwrite */
#define  RF_LDOT_LDO_VCO_TRIM_OVERWRITE_MASK                0x00003F00u                   /**< Mask for RfLdotLdoVcoTrimOverwrite */
#define  RF_LDOT_LDO_VCO_TRIM_OVERWRITE_BMASK               0x3Fu                         /**< Base mask for RfLdotLdoVcoTrimOverwrite */
#define  RF_LDOT_LDO_VCO_TRIM_OVERWRITE(x)                  (((x)&0x3Fu)<<8)              /**< Set RfLdotLdoVcoTrimOverwrite in register */
#define  GET_RF_LDOT_LDO_VCO_TRIM_OVERWRITE(reg)            (((reg)>>8)&0x3Fu)            /**< Get RfLdotLdoVcoTrimOverwrite from register */
/** @} */


/**
 * @name RegRfLdotDbg4
 * @{
 */
// RegRfLdotDbg4.r32
#define  REG_RF_LDOT_DBG4_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfLdotDbg4 */
#define  REG_RF_LDOT_DBG4_MASK                              0x000001FFu                   /**< Mask for RegRfLdotDbg4 */

#define  RF_LDOT_INCCAL_DIS_SHIFT                           0                             /**< Shift for RfLdotInccalDis */
#define  RF_LDOT_INCCAL_DIS_MASK                            0x00000001u                   /**< Mask for RfLdotInccalDis */
#define  RF_LDOT_INCCAL_DIS_BMASK                           0x1u                          /**< Base mask for RfLdotInccalDis */
#define  RF_LDOT_INCCAL_DIS(x)                              (((x)&0x1u)<<0)               /**< Set RfLdotInccalDis in register */
#define  GET_RF_LDOT_INCCAL_DIS(reg)                        (((reg)>>0)&0x1u)             /**< Get RfLdotInccalDis from register */
#define  RF_LDOT_LDO_RXTXHF_OFFSET_SHIFT                    1                             /**< Shift for RfLdotLdoRxtxhfOffset */
#define  RF_LDOT_LDO_RXTXHF_OFFSET_MASK                     0x00000006u                   /**< Mask for RfLdotLdoRxtxhfOffset */
#define  RF_LDOT_LDO_RXTXHF_OFFSET_BMASK                    0x3u                          /**< Base mask for RfLdotLdoRxtxhfOffset */
#define  RF_LDOT_LDO_RXTXHF_OFFSET(x)                       (((x)&0x3u)<<1)               /**< Set RfLdotLdoRxtxhfOffset in register */
#define  GET_RF_LDOT_LDO_RXTXHF_OFFSET(reg)                 (((reg)>>1)&0x3u)             /**< Get RfLdotLdoRxtxhfOffset from register */
#define  RF_LDOT_LDO_RXTXLF_OFFSET_SHIFT                    3                             /**< Shift for RfLdotLdoRxtxlfOffset */
#define  RF_LDOT_LDO_RXTXLF_OFFSET_MASK                     0x00000018u                   /**< Mask for RfLdotLdoRxtxlfOffset */
#define  RF_LDOT_LDO_RXTXLF_OFFSET_BMASK                    0x3u                          /**< Base mask for RfLdotLdoRxtxlfOffset */
#define  RF_LDOT_LDO_RXTXLF_OFFSET(x)                       (((x)&0x3u)<<3)               /**< Set RfLdotLdoRxtxlfOffset in register */
#define  GET_RF_LDOT_LDO_RXTXLF_OFFSET(reg)                 (((reg)>>3)&0x3u)             /**< Get RfLdotLdoRxtxlfOffset from register */
#define  RF_LDOT_LDO_PLL_OFFSET_SHIFT                       5                             /**< Shift for RfLdotLdoPllOffset */
#define  RF_LDOT_LDO_PLL_OFFSET_MASK                        0x00000060u                   /**< Mask for RfLdotLdoPllOffset */
#define  RF_LDOT_LDO_PLL_OFFSET_BMASK                       0x3u                          /**< Base mask for RfLdotLdoPllOffset */
#define  RF_LDOT_LDO_PLL_OFFSET(x)                          (((x)&0x3u)<<5)               /**< Set RfLdotLdoPllOffset in register */
#define  GET_RF_LDOT_LDO_PLL_OFFSET(reg)                    (((reg)>>5)&0x3u)             /**< Get RfLdotLdoPllOffset from register */
#define  RF_LDOT_LDO_VCO_OFFSET_SHIFT                       7                             /**< Shift for RfLdotLdoVcoOffset */
#define  RF_LDOT_LDO_VCO_OFFSET_MASK                        0x00000180u                   /**< Mask for RfLdotLdoVcoOffset */
#define  RF_LDOT_LDO_VCO_OFFSET_BMASK                       0x3u                          /**< Base mask for RfLdotLdoVcoOffset */
#define  RF_LDOT_LDO_VCO_OFFSET(x)                          (((x)&0x3u)<<7)               /**< Set RfLdotLdoVcoOffset in register */
#define  GET_RF_LDOT_LDO_VCO_OFFSET(reg)                    (((reg)>>7)&0x3u)             /**< Get RfLdotLdoVcoOffset from register */
/** @} */


/**
 * @name RegRfLdotRdbk1
 * @{
 */
// RegRfLdotRdbk1.r32
#define  REG_RF_LDOT_RDBK1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfLdotRdbk1 */
#define  REG_RF_LDOT_RDBK1_MASK                             0x0000003Fu                   /**< Mask for RegRfLdotRdbk1 */

#define  RF_LDOT_LDO_CAL_TRIM_SHIFT                         0                             /**< Shift for RfLdotLdoCalTrim */
#define  RF_LDOT_LDO_CAL_TRIM_MASK                          0x0000003Fu                   /**< Mask for RfLdotLdoCalTrim */
#define  RF_LDOT_LDO_CAL_TRIM_BMASK                         0x3Fu                         /**< Base mask for RfLdotLdoCalTrim */
#define  RF_LDOT_LDO_CAL_TRIM(x)                            (((x)&0x3Fu)<<0)              /**< Set RfLdotLdoCalTrim in register */
#define  GET_RF_LDOT_LDO_CAL_TRIM(reg)                      (((reg)>>0)&0x3Fu)            /**< Get RfLdotLdoCalTrim from register */
/** @} */


/**
 * @name RegRfLdotRdbk2
 * @{
 */
// RegRfLdotRdbk2.r32
#define  REG_RF_LDOT_RDBK2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfLdotRdbk2 */
#define  REG_RF_LDOT_RDBK2_MASK                             0x00000FFFu                   /**< Mask for RegRfLdotRdbk2 */

#define  RF_LDOT_LDO_RXTXHF_TRIM_SHIFT                      0                             /**< Shift for RfLdotLdoRxtxhfTrim */
#define  RF_LDOT_LDO_RXTXHF_TRIM_MASK                       0x0000003Fu                   /**< Mask for RfLdotLdoRxtxhfTrim */
#define  RF_LDOT_LDO_RXTXHF_TRIM_BMASK                      0x3Fu                         /**< Base mask for RfLdotLdoRxtxhfTrim */
#define  RF_LDOT_LDO_RXTXHF_TRIM(x)                         (((x)&0x3Fu)<<0)              /**< Set RfLdotLdoRxtxhfTrim in register */
#define  GET_RF_LDOT_LDO_RXTXHF_TRIM(reg)                   (((reg)>>0)&0x3Fu)            /**< Get RfLdotLdoRxtxhfTrim from register */
#define  RF_LDOT_LDO_RXTXLF_TRIM_SHIFT                      6                             /**< Shift for RfLdotLdoRxtxlfTrim */
#define  RF_LDOT_LDO_RXTXLF_TRIM_MASK                       0x00000FC0u                   /**< Mask for RfLdotLdoRxtxlfTrim */
#define  RF_LDOT_LDO_RXTXLF_TRIM_BMASK                      0x3Fu                         /**< Base mask for RfLdotLdoRxtxlfTrim */
#define  RF_LDOT_LDO_RXTXLF_TRIM(x)                         (((x)&0x3Fu)<<6)              /**< Set RfLdotLdoRxtxlfTrim in register */
#define  GET_RF_LDOT_LDO_RXTXLF_TRIM(reg)                   (((reg)>>6)&0x3Fu)            /**< Get RfLdotLdoRxtxlfTrim from register */
/** @} */


/**
 * @name RegRfLdotRdbk3
 * @{
 */
// RegRfLdotRdbk3.r32
#define  REG_RF_LDOT_RDBK3_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfLdotRdbk3 */
#define  REG_RF_LDOT_RDBK3_MASK                             0x00000FFFu                   /**< Mask for RegRfLdotRdbk3 */

#define  RF_LDOT_LDO_PLL_TRIM_SHIFT                         0                             /**< Shift for RfLdotLdoPllTrim */
#define  RF_LDOT_LDO_PLL_TRIM_MASK                          0x0000003Fu                   /**< Mask for RfLdotLdoPllTrim */
#define  RF_LDOT_LDO_PLL_TRIM_BMASK                         0x3Fu                         /**< Base mask for RfLdotLdoPllTrim */
#define  RF_LDOT_LDO_PLL_TRIM(x)                            (((x)&0x3Fu)<<0)              /**< Set RfLdotLdoPllTrim in register */
#define  GET_RF_LDOT_LDO_PLL_TRIM(reg)                      (((reg)>>0)&0x3Fu)            /**< Get RfLdotLdoPllTrim from register */
#define  RF_LDOT_LDO_VCO_TRIM_SHIFT                         6                             /**< Shift for RfLdotLdoVcoTrim */
#define  RF_LDOT_LDO_VCO_TRIM_MASK                          0x00000FC0u                   /**< Mask for RfLdotLdoVcoTrim */
#define  RF_LDOT_LDO_VCO_TRIM_BMASK                         0x3Fu                         /**< Base mask for RfLdotLdoVcoTrim */
#define  RF_LDOT_LDO_VCO_TRIM(x)                            (((x)&0x3Fu)<<6)              /**< Set RfLdotLdoVcoTrim in register */
#define  GET_RF_LDOT_LDO_VCO_TRIM(reg)                      (((reg)>>6)&0x3Fu)            /**< Get RfLdotLdoVcoTrim from register */
/** @} */


/**
 * @name RegRfHpmcCfg
 * @{
 */
// RegRfHpmcCfg.r32
#define  REG_RF_HPMC_CFG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfHpmcCfg */
#define  REG_RF_HPMC_CFG_MASK                               0x00000007u                   /**< Mask for RegRfHpmcCfg */

#define  RF_HPMC_DAC_SWING_SHIFT                            0                             /**< Shift for RfHpmcDacSwing */
#define  RF_HPMC_DAC_SWING_MASK                             0x00000001u                   /**< Mask for RfHpmcDacSwing */
#define  RF_HPMC_DAC_SWING_BMASK                            0x1u                          /**< Base mask for RfHpmcDacSwing */
#define  RF_HPMC_DAC_SWING(x)                               (((x)&0x1u)<<0)               /**< Set RfHpmcDacSwing in register */
#define  GET_RF_HPMC_DAC_SWING(reg)                         (((reg)>>0)&0x1u)             /**< Get RfHpmcDacSwing from register */
#define  RF_HPMC_SLOW_MODE_SHIFT                            1                             /**< Shift for RfHpmcSlowMode */
#define  RF_HPMC_SLOW_MODE_MASK                             0x00000002u                   /**< Mask for RfHpmcSlowMode */
#define  RF_HPMC_SLOW_MODE_BMASK                            0x1u                          /**< Base mask for RfHpmcSlowMode */
#define  RF_HPMC_SLOW_MODE(x)                               (((x)&0x1u)<<1)               /**< Set RfHpmcSlowMode in register */
#define  GET_RF_HPMC_SLOW_MODE(reg)                         (((reg)>>1)&0x1u)             /**< Get RfHpmcSlowMode from register */
#define  RF_HPMC_COUNT_POL_SHIFT                            2                             /**< Shift for RfHpmcCountPol */
#define  RF_HPMC_COUNT_POL_MASK                             0x00000004u                   /**< Mask for RfHpmcCountPol */
#define  RF_HPMC_COUNT_POL_BMASK                            0x1u                          /**< Base mask for RfHpmcCountPol */
#define  RF_HPMC_COUNT_POL(x)                               (((x)&0x1u)<<2)               /**< Set RfHpmcCountPol in register */
#define  GET_RF_HPMC_COUNT_POL(reg)                         (((reg)>>2)&0x1u)             /**< Get RfHpmcCountPol from register */
/** @} */


/**
 * @name RegRfHpmcDebug
 * @{
 */
// RegRfHpmcDebug.r32
#define  REG_RF_HPMC_DEBUG_RESET_VALUE                      0x00000800u                   /**< Reset value of RegRfHpmcDebug */
#define  REG_RF_HPMC_DEBUG_MASK                             0x00000FFFu                   /**< Mask for RegRfHpmcDebug */

#define  RF_HPMC_BYPASS_SHIFT                               0                             /**< Shift for RfHpmcBypass */
#define  RF_HPMC_BYPASS_MASK                                0x00000001u                   /**< Mask for RfHpmcBypass */
#define  RF_HPMC_BYPASS_BMASK                               0x1u                          /**< Base mask for RfHpmcBypass */
#define  RF_HPMC_BYPASS(x)                                  (((x)&0x1u)<<0)               /**< Set RfHpmcBypass in register */
#define  GET_RF_HPMC_BYPASS(reg)                            (((reg)>>0)&0x1u)             /**< Get RfHpmcBypass from register */
#define  RF_HPMC_GAIN_OVERWRITE_SHIFT                       1                             /**< Shift for RfHpmcGainOverwrite */
#define  RF_HPMC_GAIN_OVERWRITE_MASK                        0x00000FFEu                   /**< Mask for RfHpmcGainOverwrite */
#define  RF_HPMC_GAIN_OVERWRITE_BMASK                       0x7FFu                        /**< Base mask for RfHpmcGainOverwrite */
#define  RF_HPMC_GAIN_OVERWRITE(x)                          (((x)&0x7FFu)<<1)             /**< Set RfHpmcGainOverwrite in register */
#define  GET_RF_HPMC_GAIN_OVERWRITE(reg)                    (((reg)>>1)&0x7FFu)           /**< Get RfHpmcGainOverwrite from register */
/** @} */


/**
 * @name RegRfHpmcRdbk1
 * @{
 */
// RegRfHpmcRdbk1.r32
#define  REG_RF_HPMC_RDBK1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfHpmcRdbk1 */
#define  REG_RF_HPMC_RDBK1_MASK                             0x0000FFFFu                   /**< Mask for RegRfHpmcRdbk1 */

#define  RF_HPMC_COUNT1_MSW_SHIFT                           0                             /**< Shift for RfHpmcCount1Msw */
#define  RF_HPMC_COUNT1_MSW_MASK                            0x0000FFFFu                   /**< Mask for RfHpmcCount1Msw */
#define  RF_HPMC_COUNT1_MSW_BMASK                           0xFFFFu                       /**< Base mask for RfHpmcCount1Msw */
#define  RF_HPMC_COUNT1_MSW(x)                              (((x)&0xFFFFu)<<0)            /**< Set RfHpmcCount1Msw in register */
#define  GET_RF_HPMC_COUNT1_MSW(reg)                        (((reg)>>0)&0xFFFFu)          /**< Get RfHpmcCount1Msw from register */
/** @} */


/**
 * @name RegRfHpmcRdbk2
 * @{
 */
// RegRfHpmcRdbk2.r32
#define  REG_RF_HPMC_RDBK2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfHpmcRdbk2 */
#define  REG_RF_HPMC_RDBK2_MASK                             0x0000FFFFu                   /**< Mask for RegRfHpmcRdbk2 */

#define  RF_HPMC_COUNT2_MSW_SHIFT                           0                             /**< Shift for RfHpmcCount2Msw */
#define  RF_HPMC_COUNT2_MSW_MASK                            0x0000FFFFu                   /**< Mask for RfHpmcCount2Msw */
#define  RF_HPMC_COUNT2_MSW_BMASK                           0xFFFFu                       /**< Base mask for RfHpmcCount2Msw */
#define  RF_HPMC_COUNT2_MSW(x)                              (((x)&0xFFFFu)<<0)            /**< Set RfHpmcCount2Msw in register */
#define  GET_RF_HPMC_COUNT2_MSW(reg)                        (((reg)>>0)&0xFFFFu)          /**< Get RfHpmcCount2Msw from register */
/** @} */


/**
 * @name RegRfHpmcRdbk3
 * @{
 */
// RegRfHpmcRdbk3.r32
#define  REG_RF_HPMC_RDBK3_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfHpmcRdbk3 */
#define  REG_RF_HPMC_RDBK3_MASK                             0x0000FFFFu                   /**< Mask for RegRfHpmcRdbk3 */

#define  RF_HPMC_COUNT1_LSW_SHIFT                           0                             /**< Shift for RfHpmcCount1Lsw */
#define  RF_HPMC_COUNT1_LSW_MASK                            0x00000007u                   /**< Mask for RfHpmcCount1Lsw */
#define  RF_HPMC_COUNT1_LSW_BMASK                           0x7u                          /**< Base mask for RfHpmcCount1Lsw */
#define  RF_HPMC_COUNT1_LSW(x)                              (((x)&0x7u)<<0)               /**< Set RfHpmcCount1Lsw in register */
#define  GET_RF_HPMC_COUNT1_LSW(reg)                        (((reg)>>0)&0x7u)             /**< Get RfHpmcCount1Lsw from register */
#define  RF_HPMC_COUNT2_LSW_SHIFT                           3                             /**< Shift for RfHpmcCount2Lsw */
#define  RF_HPMC_COUNT2_LSW_MASK                            0x00000038u                   /**< Mask for RfHpmcCount2Lsw */
#define  RF_HPMC_COUNT2_LSW_BMASK                           0x7u                          /**< Base mask for RfHpmcCount2Lsw */
#define  RF_HPMC_COUNT2_LSW(x)                              (((x)&0x7u)<<3)               /**< Set RfHpmcCount2Lsw in register */
#define  GET_RF_HPMC_COUNT2_LSW(reg)                        (((reg)>>3)&0x7u)             /**< Get RfHpmcCount2Lsw from register */
#define  RF_HPMC_MEAS_DIFF_COUNT_SHIFT                      6                             /**< Shift for RfHpmcMeasDiffCount */
#define  RF_HPMC_MEAS_DIFF_COUNT_MASK                       0x00007FC0u                   /**< Mask for RfHpmcMeasDiffCount */
#define  RF_HPMC_MEAS_DIFF_COUNT_BMASK                      0x1FFu                        /**< Base mask for RfHpmcMeasDiffCount */
#define  RF_HPMC_MEAS_DIFF_COUNT(x)                         (((x)&0x1FFu)<<6)             /**< Set RfHpmcMeasDiffCount in register */
#define  GET_RF_HPMC_MEAS_DIFF_COUNT(reg)                   (((reg)>>6)&0x1FFu)           /**< Get RfHpmcMeasDiffCount from register */
#define  RF_HPMC_PASS_SHIFT                                 15                            /**< Shift for RfHpmcPass */
#define  RF_HPMC_PASS_MASK                                  0x00008000u                   /**< Mask for RfHpmcPass */
#define  RF_HPMC_PASS_BMASK                                 0x1u                          /**< Base mask for RfHpmcPass */
#define  RF_HPMC_PASS(x)                                    (((x)&0x1u)<<15)              /**< Set RfHpmcPass in register */
#define  GET_RF_HPMC_PASS(reg)                              (((reg)>>15)&0x1u)            /**< Get RfHpmcPass from register */
/** @} */


/**
 * @name RegRfHpmcRdbk4
 * @{
 */
// RegRfHpmcRdbk4.r32
#define  REG_RF_HPMC_RDBK4_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfHpmcRdbk4 */
#define  REG_RF_HPMC_RDBK4_MASK                             0x000007FFu                   /**< Mask for RegRfHpmcRdbk4 */

#define  RF_HPMC_GAIN_SHIFT                                 0                             /**< Shift for RfHpmcGain */
#define  RF_HPMC_GAIN_MASK                                  0x000007FFu                   /**< Mask for RfHpmcGain */
#define  RF_HPMC_GAIN_BMASK                                 0x7FFu                        /**< Base mask for RfHpmcGain */
#define  RF_HPMC_GAIN(x)                                    (((x)&0x7FFu)<<0)             /**< Set RfHpmcGain in register */
#define  GET_RF_HPMC_GAIN(reg)                              (((reg)>>0)&0x7FFu)           /**< Get RfHpmcGain from register */
/** @} */


/**
 * @name RegRfLocdCfg
 * @{
 */
// RegRfLocdCfg.r32
#define  REG_RF_LOCD_CFG_RESET_VALUE                        0x000000E2u                   /**< Reset value of RegRfLocdCfg */
#define  REG_RF_LOCD_CFG_MASK                               0x00007FFFu                   /**< Mask for RegRfLocdCfg */

#define  RF_LOCD_DUR_SHIFT                                  0                             /**< Shift for RfLocdDur */
#define  RF_LOCD_DUR_MASK                                   0x0000007Fu                   /**< Mask for RfLocdDur */
#define  RF_LOCD_DUR_BMASK                                  0x7Fu                         /**< Base mask for RfLocdDur */
#define  RF_LOCD_DUR(x)                                     (((x)&0x7Fu)<<0)              /**< Set RfLocdDur in register */
#define  GET_RF_LOCD_DUR(reg)                               (((reg)>>0)&0x7Fu)            /**< Get RfLocdDur from register */
#define  RF_LOCD_WAIT_SHIFT                                 7                             /**< Shift for RfLocdWait */
#define  RF_LOCD_WAIT_MASK                                  0x00003F80u                   /**< Mask for RfLocdWait */
#define  RF_LOCD_WAIT_BMASK                                 0x7Fu                         /**< Base mask for RfLocdWait */
#define  RF_LOCD_WAIT(x)                                    (((x)&0x7Fu)<<7)              /**< Set RfLocdWait in register */
#define  GET_RF_LOCD_WAIT(reg)                              (((reg)>>7)&0x7Fu)            /**< Get RfLocdWait from register */
#define  RF_LOCD_CYC_SHIFT                                  14                            /**< Shift for RfLocdCyc */
#define  RF_LOCD_CYC_MASK                                   0x00004000u                   /**< Mask for RfLocdCyc */
#define  RF_LOCD_CYC_BMASK                                  0x1u                          /**< Base mask for RfLocdCyc */
#define  RF_LOCD_CYC(x)                                     (((x)&0x1u)<<14)              /**< Set RfLocdCyc in register */
#define  GET_RF_LOCD_CYC(reg)                               (((reg)>>14)&0x1u)            /**< Get RfLocdCyc from register */
/** @} */


/**
 * @name RegRfLocdRdbk
 * @{
 */
// RegRfLocdRdbk.r32
#define  REG_RF_LOCD_RDBK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfLocdRdbk */
#define  REG_RF_LOCD_RDBK_MASK                              0x00000001u                   /**< Mask for RegRfLocdRdbk */

#define  RF_LOCD_PASS_SHIFT                                 0                             /**< Shift for RfLocdPass */
#define  RF_LOCD_PASS_MASK                                  0x00000001u                   /**< Mask for RfLocdPass */
#define  RF_LOCD_PASS_BMASK                                 0x1u                          /**< Base mask for RfLocdPass */
#define  RF_LOCD_PASS(x)                                    (((x)&0x1u)<<0)               /**< Set RfLocdPass in register */
#define  GET_RF_LOCD_PASS(reg)                              (((reg)>>0)&0x1u)             /**< Get RfLocdPass from register */
/** @} */


/**
 * @name RegRfLocdTrgtCnt11
 * @{
 */
// RegRfLocdTrgtCnt11.r32
#define  REG_RF_LOCD_TRGT_CNT11_RESET_VALUE                 0x0000E984u                   /**< Reset value of RegRfLocdTrgtCnt11 */
#define  REG_RF_LOCD_TRGT_CNT11_MASK                        0x0000FFFFu                   /**< Mask for RegRfLocdTrgtCnt11 */

#define  RF_LOCD_TARGET_COUNT1_MSW_SHIFT                    0                             /**< Shift for RfLocdTargetCount1Msw */
#define  RF_LOCD_TARGET_COUNT1_MSW_MASK                     0x0000FFFFu                   /**< Mask for RfLocdTargetCount1Msw */
#define  RF_LOCD_TARGET_COUNT1_MSW_BMASK                    0xFFFFu                       /**< Base mask for RfLocdTargetCount1Msw */
#define  RF_LOCD_TARGET_COUNT1_MSW(x)                       (((x)&0xFFFFu)<<0)            /**< Set RfLocdTargetCount1Msw in register */
#define  GET_RF_LOCD_TARGET_COUNT1_MSW(reg)                 (((reg)>>0)&0xFFFFu)          /**< Get RfLocdTargetCount1Msw from register */
/** @} */


/**
 * @name RegRfLocdTrgtCnt12
 * @{
 */
// RegRfLocdTrgtCnt12.r32
#define  REG_RF_LOCD_TRGT_CNT12_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfLocdTrgtCnt12 */
#define  REG_RF_LOCD_TRGT_CNT12_MASK                        0x00000007u                   /**< Mask for RegRfLocdTrgtCnt12 */

#define  RF_LOCD_TARGET_COUNT1_LSW_SHIFT                    0                             /**< Shift for RfLocdTargetCount1Lsw */
#define  RF_LOCD_TARGET_COUNT1_LSW_MASK                     0x00000007u                   /**< Mask for RfLocdTargetCount1Lsw */
#define  RF_LOCD_TARGET_COUNT1_LSW_BMASK                    0x7u                          /**< Base mask for RfLocdTargetCount1Lsw */
#define  RF_LOCD_TARGET_COUNT1_LSW(x)                       (((x)&0x7u)<<0)               /**< Set RfLocdTargetCount1Lsw in register */
#define  GET_RF_LOCD_TARGET_COUNT1_LSW(reg)                 (((reg)>>0)&0x7u)             /**< Get RfLocdTargetCount1Lsw from register */
/** @} */


/**
 * @name RegRfCalDoneRdbk
 * @{
 */
// RegRfCalDoneRdbk.r32
#define  REG_RF_CAL_DONE_RDBK_RESET_VALUE                   0x00000000u                   /**< Reset value of RegRfCalDoneRdbk */
#define  REG_RF_CAL_DONE_RDBK_MASK                          0x0000003Fu                   /**< Mask for RegRfCalDoneRdbk */

#define  RF_LDOT_DONE_SHIFT                                 0                             /**< Shift for RfLdotDone */
#define  RF_LDOT_DONE_MASK                                  0x00000001u                   /**< Mask for RfLdotDone */
#define  RF_LDOT_DONE_BMASK                                 0x1u                          /**< Base mask for RfLdotDone */
#define  RF_LDOT_DONE(x)                                    (((x)&0x1u)<<0)               /**< Set RfLdotDone in register */
#define  GET_RF_LDOT_DONE(reg)                              (((reg)>>0)&0x1u)             /**< Get RfLdotDone from register */
#define  RF_RCCAL_DONE_SHIFT                                1                             /**< Shift for RfRccalDone */
#define  RF_RCCAL_DONE_MASK                                 0x00000002u                   /**< Mask for RfRccalDone */
#define  RF_RCCAL_DONE_BMASK                                0x1u                          /**< Base mask for RfRccalDone */
#define  RF_RCCAL_DONE(x)                                   (((x)&0x1u)<<1)               /**< Set RfRccalDone in register */
#define  GET_RF_RCCAL_DONE(reg)                             (((reg)>>1)&0x1u)             /**< Get RfRccalDone from register */
#define  RF_FCAL_DONE_SHIFT                                 2                             /**< Shift for RfFcalDone */
#define  RF_FCAL_DONE_MASK                                  0x00000004u                   /**< Mask for RfFcalDone */
#define  RF_FCAL_DONE_BMASK                                 0x1u                          /**< Base mask for RfFcalDone */
#define  RF_FCAL_DONE(x)                                    (((x)&0x1u)<<2)               /**< Set RfFcalDone in register */
#define  GET_RF_FCAL_DONE(reg)                              (((reg)>>2)&0x1u)             /**< Get RfFcalDone from register */
#define  RF_HPMC_DONE_SHIFT                                 3                             /**< Shift for RfHpmcDone */
#define  RF_HPMC_DONE_MASK                                  0x00000008u                   /**< Mask for RfHpmcDone */
#define  RF_HPMC_DONE_BMASK                                 0x1u                          /**< Base mask for RfHpmcDone */
#define  RF_HPMC_DONE(x)                                    (((x)&0x1u)<<3)               /**< Set RfHpmcDone in register */
#define  GET_RF_HPMC_DONE(reg)                              (((reg)>>3)&0x1u)             /**< Get RfHpmcDone from register */
#define  RF_DCOC_DONE_SHIFT                                 4                             /**< Shift for RfDcocDone */
#define  RF_DCOC_DONE_MASK                                  0x00000010u                   /**< Mask for RfDcocDone */
#define  RF_DCOC_DONE_BMASK                                 0x1u                          /**< Base mask for RfDcocDone */
#define  RF_DCOC_DONE(x)                                    (((x)&0x1u)<<4)               /**< Set RfDcocDone in register */
#define  GET_RF_DCOC_DONE(reg)                              (((reg)>>4)&0x1u)             /**< Get RfDcocDone from register */
#define  RF_LOCD_DONE_SHIFT                                 5                             /**< Shift for RfLocdDone */
#define  RF_LOCD_DONE_MASK                                  0x00000020u                   /**< Mask for RfLocdDone */
#define  RF_LOCD_DONE_BMASK                                 0x1u                          /**< Base mask for RfLocdDone */
#define  RF_LOCD_DONE(x)                                    (((x)&0x1u)<<5)               /**< Set RfLocdDone in register */
#define  GET_RF_LOCD_DONE(reg)                              (((reg)>>5)&0x1u)             /**< Get RfLocdDone from register */
/** @} */


/**
 * @name RegRfAdcDacDft1
 * @{
 */
// RegRfAdcDacDft1.r32
#define  REG_RF_ADC_DAC_DFT1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfAdcDacDft1 */
#define  REG_RF_ADC_DAC_DFT1_MASK                           0x00000FFFu                   /**< Mask for RegRfAdcDacDft1 */

#define  RF_DAC_DFT_DATA_SHIFT                              0                             /**< Shift for RfDacDftData */
#define  RF_DAC_DFT_DATA_MASK                               0x000007FFu                   /**< Mask for RfDacDftData */
#define  RF_DAC_DFT_DATA_BMASK                              0x7FFu                        /**< Base mask for RfDacDftData */
#define  RF_DAC_DFT_DATA(x)                                 (((x)&0x7FFu)<<0)             /**< Set RfDacDftData in register */
#define  GET_RF_DAC_DFT_DATA(reg)                           (((reg)>>0)&0x7FFu)           /**< Get RfDacDftData from register */
#define  RF_BYPASS_TXON_SHIFT                               11                            /**< Shift for RfBypassTxon */
#define  RF_BYPASS_TXON_MASK                                0x00000800u                   /**< Mask for RfBypassTxon */
#define  RF_BYPASS_TXON_BMASK                               0x1u                          /**< Base mask for RfBypassTxon */
#define  RF_BYPASS_TXON(x)                                  (((x)&0x1u)<<11)              /**< Set RfBypassTxon in register */
#define  GET_RF_BYPASS_TXON(reg)                            (((reg)>>11)&0x1u)            /**< Get RfBypassTxon from register */
/** @} */


/**
 * @name RegRfAdcDacDft2
 * @{
 */
// RegRfAdcDacDft2.r32
#define  REG_RF_ADC_DAC_DFT2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfAdcDacDft2 */
#define  REG_RF_ADC_DAC_DFT2_MASK                           0x0000007Fu                   /**< Mask for RegRfAdcDacDft2 */

#define  RF_RXTX_DBG_CTRL_SHIFT                             0                             /**< Shift for RfRxtxDbgCtrl */
#define  RF_RXTX_DBG_CTRL_MASK                              0x0000001Fu                   /**< Mask for RfRxtxDbgCtrl */
#define  RF_RXTX_DBG_CTRL_BMASK                             0x1Fu                         /**< Base mask for RfRxtxDbgCtrl */
#define  RF_RXTX_DBG_CTRL(x)                                (((x)&0x1Fu)<<0)              /**< Set RfRxtxDbgCtrl in register */
#define  GET_RF_RXTX_DBG_CTRL(reg)                          (((reg)>>0)&0x1Fu)            /**< Get RfRxtxDbgCtrl from register */
#define  RF_DBG_STRB_SEL_SHIFT                              5                             /**< Shift for RfDbgStrbSel */
#define  RF_DBG_STRB_SEL_MASK                               0x00000060u                   /**< Mask for RfDbgStrbSel */
#define  RF_DBG_STRB_SEL_BMASK                              0x3u                          /**< Base mask for RfDbgStrbSel */
#define  RF_DBG_STRB_SEL(x)                                 (((x)&0x3u)<<5)               /**< Set RfDbgStrbSel in register */
#define  GET_RF_DBG_STRB_SEL(reg)                           (((reg)>>5)&0x3u)             /**< Get RfDbgStrbSel from register */
/** @} */


/**
 * @name RegRfDftMux
 * @{
 */
// RegRfDftMux.r32
#define  REG_RF_DFT_MUX_RESET_VALUE                         0x00000000u                   /**< Reset value of RegRfDftMux */
#define  REG_RF_DFT_MUX_MASK                                0x000007FFu                   /**< Mask for RegRfDftMux */

#define  RF_MUX_SEL_SHIFT                                   0                             /**< Shift for RfMuxSel */
#define  RF_MUX_SEL_MASK                                    0x0000001Fu                   /**< Mask for RfMuxSel */
#define  RF_MUX_SEL_BMASK                                   0x1Fu                         /**< Base mask for RfMuxSel */
#define  RF_MUX_SEL(x)                                      (((x)&0x1Fu)<<0)              /**< Set RfMuxSel in register */
#define  GET_RF_MUX_SEL(reg)                                (((reg)>>0)&0x1Fu)            /**< Get RfMuxSel from register */
#define  RF_MUX_SEL2_SHIFT                                  5                             /**< Shift for RfMuxSel2 */
#define  RF_MUX_SEL2_MASK                                   0x000003E0u                   /**< Mask for RfMuxSel2 */
#define  RF_MUX_SEL2_BMASK                                  0x1Fu                         /**< Base mask for RfMuxSel2 */
#define  RF_MUX_SEL2(x)                                     (((x)&0x1Fu)<<5)              /**< Set RfMuxSel2 in register */
#define  GET_RF_MUX_SEL2(reg)                               (((reg)>>5)&0x1Fu)            /**< Get RfMuxSel2 from register */
#define  RF_DIG_DBG_READ_SEL_SHIFT                          10                            /**< Shift for RfDigDbgReadSel */
#define  RF_DIG_DBG_READ_SEL_MASK                           0x00000400u                   /**< Mask for RfDigDbgReadSel */
#define  RF_DIG_DBG_READ_SEL_BMASK                          0x1u                          /**< Base mask for RfDigDbgReadSel */
#define  RF_DIG_DBG_READ_SEL(x)                             (((x)&0x1u)<<10)              /**< Set RfDigDbgReadSel in register */
#define  GET_RF_DIG_DBG_READ_SEL(reg)                       (((reg)>>10)&0x1u)            /**< Get RfDigDbgReadSel from register */
/** @} */


/**
 * @name RegRfDiag
 * @{
 */
// RegRfDiag.r32
#define  REG_RF_DIAG_RESET_VALUE                            0x00000001u                   /**< Reset value of RegRfDiag */
#define  REG_RF_DIAG_MASK                                   0x000007FFu                   /**< Mask for RegRfDiag */

#define  RF_DIAG_DISABLE_SHIFT                              0                             /**< Shift for RfDiagDisable */
#define  RF_DIAG_DISABLE_MASK                               0x00000001u                   /**< Mask for RfDiagDisable */
#define  RF_DIAG_DISABLE_BMASK                              0x1u                          /**< Base mask for RfDiagDisable */
#define  RF_DIAG_DISABLE(x)                                 (((x)&0x1u)<<0)               /**< Set RfDiagDisable in register */
#define  GET_RF_DIAG_DISABLE(reg)                           (((reg)>>0)&0x1u)             /**< Get RfDiagDisable from register */
#define  RF_DIAG_CODE_SHIFT                                 1                             /**< Shift for RfDiagCode */
#define  RF_DIAG_CODE_MASK                                  0x0000000Eu                   /**< Mask for RfDiagCode */
#define  RF_DIAG_CODE_BMASK                                 0x7u                          /**< Base mask for RfDiagCode */
#define  RF_DIAG_CODE(x)                                    (((x)&0x7u)<<1)               /**< Set RfDiagCode in register */
#define  GET_RF_DIAG_CODE(reg)                              (((reg)>>1)&0x7u)             /**< Get RfDiagCode from register */
#define  RF_DIAG_SEL_SHIFT                                  4                             /**< Shift for RfDiagSel */
#define  RF_DIAG_SEL_MASK                                   0x000001F0u                   /**< Mask for RfDiagSel */
#define  RF_DIAG_SEL_BMASK                                  0x1Fu                         /**< Base mask for RfDiagSel */
#define  RF_DIAG_SEL(x)                                     (((x)&0x1Fu)<<4)              /**< Set RfDiagSel in register */
#define  GET_RF_DIAG_SEL(reg)                               (((reg)>>4)&0x1Fu)            /**< Get RfDiagSel from register */
#define  RF_EN_DIAG_SOC_SHIFT                               9                             /**< Shift for RfEnDiagSoc */
#define  RF_EN_DIAG_SOC_MASK                                0x00000200u                   /**< Mask for RfEnDiagSoc */
#define  RF_EN_DIAG_SOC_BMASK                               0x1u                          /**< Base mask for RfEnDiagSoc */
#define  RF_EN_DIAG_SOC(x)                                  (((x)&0x1u)<<9)               /**< Set RfEnDiagSoc in register */
#define  GET_RF_EN_DIAG_SOC(reg)                            (((reg)>>9)&0x1u)             /**< Get RfEnDiagSoc from register */
#define  RF_EN_DIAG_PAD_SHIFT                               10                            /**< Shift for RfEnDiagPad */
#define  RF_EN_DIAG_PAD_MASK                                0x00000400u                   /**< Mask for RfEnDiagPad */
#define  RF_EN_DIAG_PAD_BMASK                               0x1u                          /**< Base mask for RfEnDiagPad */
#define  RF_EN_DIAG_PAD(x)                                  (((x)&0x1u)<<10)              /**< Set RfEnDiagPad in register */
#define  GET_RF_EN_DIAG_PAD(reg)                            (((reg)>>10)&0x1u)            /**< Get RfEnDiagPad from register */
/** @} */


/**
 * @name RegRfBypassClkGating
 * @{
 */
// RegRfBypassClkGating.r32
#define  REG_RF_BYPASS_CLK_GATING_RESET_VALUE               0x00000000u                   /**< Reset value of RegRfBypassClkGating */
#define  REG_RF_BYPASS_CLK_GATING_MASK                      0x0000001Fu                   /**< Mask for RegRfBypassClkGating */

#define  RF_BYPASS_RXC_CLK_GAT_SHIFT                        0                             /**< Shift for RfBypassRxcClkGat */
#define  RF_BYPASS_RXC_CLK_GAT_MASK                         0x00000001u                   /**< Mask for RfBypassRxcClkGat */
#define  RF_BYPASS_RXC_CLK_GAT_BMASK                        0x1u                          /**< Base mask for RfBypassRxcClkGat */
#define  RF_BYPASS_RXC_CLK_GAT(x)                           (((x)&0x1u)<<0)               /**< Set RfBypassRxcClkGat in register */
#define  GET_RF_BYPASS_RXC_CLK_GAT(reg)                     (((reg)>>0)&0x1u)             /**< Get RfBypassRxcClkGat from register */
#define  RF_BYPASS_TXC_CLK_GAT_SHIFT                        1                             /**< Shift for RfBypassTxcClkGat */
#define  RF_BYPASS_TXC_CLK_GAT_MASK                         0x00000002u                   /**< Mask for RfBypassTxcClkGat */
#define  RF_BYPASS_TXC_CLK_GAT_BMASK                        0x1u                          /**< Base mask for RfBypassTxcClkGat */
#define  RF_BYPASS_TXC_CLK_GAT(x)                           (((x)&0x1u)<<1)               /**< Set RfBypassTxcClkGat in register */
#define  GET_RF_BYPASS_TXC_CLK_GAT(reg)                     (((reg)>>1)&0x1u)             /**< Get RfBypassTxcClkGat from register */
#define  RF_BYPASS_CAL_CLK_GAT_SHIFT                        2                             /**< Shift for RfBypassCalClkGat */
#define  RF_BYPASS_CAL_CLK_GAT_MASK                         0x00000004u                   /**< Mask for RfBypassCalClkGat */
#define  RF_BYPASS_CAL_CLK_GAT_BMASK                        0x1u                          /**< Base mask for RfBypassCalClkGat */
#define  RF_BYPASS_CAL_CLK_GAT(x)                           (((x)&0x1u)<<2)               /**< Set RfBypassCalClkGat in register */
#define  GET_RF_BYPASS_CAL_CLK_GAT(reg)                     (((reg)>>2)&0x1u)             /**< Get RfBypassCalClkGat from register */
#define  RF_BYPASS_TSEQ_CLK_GAT_SHIFT                       3                             /**< Shift for RfBypassTseqClkGat */
#define  RF_BYPASS_TSEQ_CLK_GAT_MASK                        0x00000008u                   /**< Mask for RfBypassTseqClkGat */
#define  RF_BYPASS_TSEQ_CLK_GAT_BMASK                       0x1u                          /**< Base mask for RfBypassTseqClkGat */
#define  RF_BYPASS_TSEQ_CLK_GAT(x)                          (((x)&0x1u)<<3)               /**< Set RfBypassTseqClkGat in register */
#define  GET_RF_BYPASS_TSEQ_CLK_GAT(reg)                    (((reg)>>3)&0x1u)             /**< Get RfBypassTseqClkGat from register */
#define  RF_BYPASS_DBG_CLK_GAT_SHIFT                        4                             /**< Shift for RfBypassDbgClkGat */
#define  RF_BYPASS_DBG_CLK_GAT_MASK                         0x00000010u                   /**< Mask for RfBypassDbgClkGat */
#define  RF_BYPASS_DBG_CLK_GAT_BMASK                        0x1u                          /**< Base mask for RfBypassDbgClkGat */
#define  RF_BYPASS_DBG_CLK_GAT(x)                           (((x)&0x1u)<<4)               /**< Set RfBypassDbgClkGat in register */
#define  GET_RF_BYPASS_DBG_CLK_GAT(reg)                     (((reg)>>4)&0x1u)             /**< Get RfBypassDbgClkGat from register */
/** @} */


/**
 * @name RegRfSftRst
 * @{
 */
// RegRfSftRst.r32
#define  REG_RF_SFT_RST_RESET_VALUE                         0x00000000u                   /**< Reset value of RegRfSftRst */
#define  REG_RF_SFT_RST_MASK                                0x0000001Fu                   /**< Mask for RegRfSftRst */

#define  RF_RXC_SFT_RST_SHIFT                               0                             /**< Shift for RfRxcSftRst */
#define  RF_RXC_SFT_RST_MASK                                0x00000001u                   /**< Mask for RfRxcSftRst */
#define  RF_RXC_SFT_RST_BMASK                               0x1u                          /**< Base mask for RfRxcSftRst */
#define  RF_RXC_SFT_RST(x)                                  (((x)&0x1u)<<0)               /**< Set RfRxcSftRst in register */
#define  GET_RF_RXC_SFT_RST(reg)                            (((reg)>>0)&0x1u)             /**< Get RfRxcSftRst from register */
#define  RF_TXC_SFT_RST_SHIFT                               1                             /**< Shift for RfTxcSftRst */
#define  RF_TXC_SFT_RST_MASK                                0x00000002u                   /**< Mask for RfTxcSftRst */
#define  RF_TXC_SFT_RST_BMASK                               0x1u                          /**< Base mask for RfTxcSftRst */
#define  RF_TXC_SFT_RST(x)                                  (((x)&0x1u)<<1)               /**< Set RfTxcSftRst in register */
#define  GET_RF_TXC_SFT_RST(reg)                            (((reg)>>1)&0x1u)             /**< Get RfTxcSftRst from register */
#define  RF_CAL_SFT_RST_SHIFT                               2                             /**< Shift for RfCalSftRst */
#define  RF_CAL_SFT_RST_MASK                                0x00000004u                   /**< Mask for RfCalSftRst */
#define  RF_CAL_SFT_RST_BMASK                               0x1u                          /**< Base mask for RfCalSftRst */
#define  RF_CAL_SFT_RST(x)                                  (((x)&0x1u)<<2)               /**< Set RfCalSftRst in register */
#define  GET_RF_CAL_SFT_RST(reg)                            (((reg)>>2)&0x1u)             /**< Get RfCalSftRst from register */
#define  RF_TSEQ_SFT_RST_SHIFT                              3                             /**< Shift for RfTseqSftRst */
#define  RF_TSEQ_SFT_RST_MASK                               0x00000008u                   /**< Mask for RfTseqSftRst */
#define  RF_TSEQ_SFT_RST_BMASK                              0x1u                          /**< Base mask for RfTseqSftRst */
#define  RF_TSEQ_SFT_RST(x)                                 (((x)&0x1u)<<3)               /**< Set RfTseqSftRst in register */
#define  GET_RF_TSEQ_SFT_RST(reg)                           (((reg)>>3)&0x1u)             /**< Get RfTseqSftRst from register */
#define  RF_DBG_SFT_RST_SHIFT                               4                             /**< Shift for RfDbgSftRst */
#define  RF_DBG_SFT_RST_MASK                                0x00000010u                   /**< Mask for RfDbgSftRst */
#define  RF_DBG_SFT_RST_BMASK                               0x1u                          /**< Base mask for RfDbgSftRst */
#define  RF_DBG_SFT_RST(x)                                  (((x)&0x1u)<<4)               /**< Set RfDbgSftRst in register */
#define  GET_RF_DBG_SFT_RST(reg)                            (((reg)>>4)&0x1u)             /**< Get RfDbgSftRst from register */
/** @} */


/**
 * @name RegRfLdo1
 * @{
 */
// RegRfLdo1.r32
#define  REG_RF_LDO1_RESET_VALUE                            0x00000000u                   /**< Reset value of RegRfLdo1 */
#define  REG_RF_LDO1_MASK                                   0x00003FFFu                   /**< Mask for RegRfLdo1 */

#define  RF_LDO_LV_BYPASS_SHIFT                             0                             /**< Shift for RfLdoLvBypass */
#define  RF_LDO_LV_BYPASS_MASK                              0x00000001u                   /**< Mask for RfLdoLvBypass */
#define  RF_LDO_LV_BYPASS_BMASK                             0x1u                          /**< Base mask for RfLdoLvBypass */
#define  RF_LDO_LV_BYPASS(x)                                (((x)&0x1u)<<0)               /**< Set RfLdoLvBypass in register */
#define  GET_RF_LDO_LV_BYPASS(reg)                          (((reg)>>0)&0x1u)             /**< Get RfLdoLvBypass from register */
#define  RF_LDO_LV_TRIM_SHIFT                               1                             /**< Shift for RfLdoLvTrim */
#define  RF_LDO_LV_TRIM_MASK                                0x00000006u                   /**< Mask for RfLdoLvTrim */
#define  RF_LDO_LV_TRIM_BMASK                               0x3u                          /**< Base mask for RfLdoLvTrim */
#define  RF_LDO_LV_TRIM(x)                                  (((x)&0x3u)<<1)               /**< Set RfLdoLvTrim in register */
#define  GET_RF_LDO_LV_TRIM(reg)                            (((reg)>>1)&0x3u)             /**< Get RfLdoLvTrim from register */
#define  RF_LDO_RXTXHF_BYPASS_SHIFT                         3                             /**< Shift for RfLdoRxtxhfBypass */
#define  RF_LDO_RXTXHF_BYPASS_MASK                          0x00000008u                   /**< Mask for RfLdoRxtxhfBypass */
#define  RF_LDO_RXTXHF_BYPASS_BMASK                         0x1u                          /**< Base mask for RfLdoRxtxhfBypass */
#define  RF_LDO_RXTXHF_BYPASS(x)                            (((x)&0x1u)<<3)               /**< Set RfLdoRxtxhfBypass in register */
#define  GET_RF_LDO_RXTXHF_BYPASS(reg)                      (((reg)>>3)&0x1u)             /**< Get RfLdoRxtxhfBypass from register */
#define  RF_LDO_RXTXHF_BOOST_SHIFT                          4                             /**< Shift for RfLdoRxtxhfBoost */
#define  RF_LDO_RXTXHF_BOOST_MASK                           0x00000010u                   /**< Mask for RfLdoRxtxhfBoost */
#define  RF_LDO_RXTXHF_BOOST_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxhfBoost */
#define  RF_LDO_RXTXHF_BOOST(x)                             (((x)&0x1u)<<4)               /**< Set RfLdoRxtxhfBoost in register */
#define  GET_RF_LDO_RXTXHF_BOOST(reg)                       (((reg)>>4)&0x1u)             /**< Get RfLdoRxtxhfBoost from register */
#define  RF_LDO_RXTXLF_BYPASS_SHIFT                         5                             /**< Shift for RfLdoRxtxlfBypass */
#define  RF_LDO_RXTXLF_BYPASS_MASK                          0x00000020u                   /**< Mask for RfLdoRxtxlfBypass */
#define  RF_LDO_RXTXLF_BYPASS_BMASK                         0x1u                          /**< Base mask for RfLdoRxtxlfBypass */
#define  RF_LDO_RXTXLF_BYPASS(x)                            (((x)&0x1u)<<5)               /**< Set RfLdoRxtxlfBypass in register */
#define  GET_RF_LDO_RXTXLF_BYPASS(reg)                      (((reg)>>5)&0x1u)             /**< Get RfLdoRxtxlfBypass from register */
#define  RF_LDO_RXTXLF_BOOST_SHIFT                          6                             /**< Shift for RfLdoRxtxlfBoost */
#define  RF_LDO_RXTXLF_BOOST_MASK                           0x00000040u                   /**< Mask for RfLdoRxtxlfBoost */
#define  RF_LDO_RXTXLF_BOOST_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxlfBoost */
#define  RF_LDO_RXTXLF_BOOST(x)                             (((x)&0x1u)<<6)               /**< Set RfLdoRxtxlfBoost in register */
#define  GET_RF_LDO_RXTXLF_BOOST(reg)                       (((reg)>>6)&0x1u)             /**< Get RfLdoRxtxlfBoost from register */
#define  RF_LDO_PLL_BYPASS_SHIFT                            7                             /**< Shift for RfLdoPllBypass */
#define  RF_LDO_PLL_BYPASS_MASK                             0x00000080u                   /**< Mask for RfLdoPllBypass */
#define  RF_LDO_PLL_BYPASS_BMASK                            0x1u                          /**< Base mask for RfLdoPllBypass */
#define  RF_LDO_PLL_BYPASS(x)                               (((x)&0x1u)<<7)               /**< Set RfLdoPllBypass in register */
#define  GET_RF_LDO_PLL_BYPASS(reg)                         (((reg)>>7)&0x1u)             /**< Get RfLdoPllBypass from register */
#define  RF_LDO_PLL_BOOST_SHIFT                             8                             /**< Shift for RfLdoPllBoost */
#define  RF_LDO_PLL_BOOST_MASK                              0x00000100u                   /**< Mask for RfLdoPllBoost */
#define  RF_LDO_PLL_BOOST_BMASK                             0x1u                          /**< Base mask for RfLdoPllBoost */
#define  RF_LDO_PLL_BOOST(x)                                (((x)&0x1u)<<8)               /**< Set RfLdoPllBoost in register */
#define  GET_RF_LDO_PLL_BOOST(reg)                          (((reg)>>8)&0x1u)             /**< Get RfLdoPllBoost from register */
#define  RF_LDO_VCO_BYPASS_SHIFT                            9                             /**< Shift for RfLdoVcoBypass */
#define  RF_LDO_VCO_BYPASS_MASK                             0x00000200u                   /**< Mask for RfLdoVcoBypass */
#define  RF_LDO_VCO_BYPASS_BMASK                            0x1u                          /**< Base mask for RfLdoVcoBypass */
#define  RF_LDO_VCO_BYPASS(x)                               (((x)&0x1u)<<9)               /**< Set RfLdoVcoBypass in register */
#define  GET_RF_LDO_VCO_BYPASS(reg)                         (((reg)>>9)&0x1u)             /**< Get RfLdoVcoBypass from register */
#define  RF_LDO_VCO_BOOST_SHIFT                             10                            /**< Shift for RfLdoVcoBoost */
#define  RF_LDO_VCO_BOOST_MASK                              0x00000400u                   /**< Mask for RfLdoVcoBoost */
#define  RF_LDO_VCO_BOOST_BMASK                             0x1u                          /**< Base mask for RfLdoVcoBoost */
#define  RF_LDO_VCO_BOOST(x)                                (((x)&0x1u)<<10)              /**< Set RfLdoVcoBoost in register */
#define  GET_RF_LDO_VCO_BOOST(reg)                          (((reg)>>10)&0x1u)            /**< Get RfLdoVcoBoost from register */
#define  RF_LDO_CAL_BYPASS_SHIFT                            11                            /**< Shift for RfLdoCalBypass */
#define  RF_LDO_CAL_BYPASS_MASK                             0x00000800u                   /**< Mask for RfLdoCalBypass */
#define  RF_LDO_CAL_BYPASS_BMASK                            0x1u                          /**< Base mask for RfLdoCalBypass */
#define  RF_LDO_CAL_BYPASS(x)                               (((x)&0x1u)<<11)              /**< Set RfLdoCalBypass in register */
#define  GET_RF_LDO_CAL_BYPASS(reg)                         (((reg)>>11)&0x1u)            /**< Get RfLdoCalBypass from register */
#define  RF_LDO_CAL_BOOST_SHIFT                             12                            /**< Shift for RfLdoCalBoost */
#define  RF_LDO_CAL_BOOST_MASK                              0x00001000u                   /**< Mask for RfLdoCalBoost */
#define  RF_LDO_CAL_BOOST_BMASK                             0x1u                          /**< Base mask for RfLdoCalBoost */
#define  RF_LDO_CAL_BOOST(x)                                (((x)&0x1u)<<12)              /**< Set RfLdoCalBoost in register */
#define  GET_RF_LDO_CAL_BOOST(reg)                          (((reg)>>12)&0x1u)            /**< Get RfLdoCalBoost from register */
#define  RF_LDO_ANT_BYPASS_SHIFT                            13                            /**< Shift for RfLdoAntBypass */
#define  RF_LDO_ANT_BYPASS_MASK                             0x00002000u                   /**< Mask for RfLdoAntBypass */
#define  RF_LDO_ANT_BYPASS_BMASK                            0x1u                          /**< Base mask for RfLdoAntBypass */
#define  RF_LDO_ANT_BYPASS(x)                               (((x)&0x1u)<<13)              /**< Set RfLdoAntBypass in register */
#define  GET_RF_LDO_ANT_BYPASS(reg)                         (((reg)>>13)&0x1u)            /**< Get RfLdoAntBypass from register */
/** @} */


/**
 * @name RegRfLdoBgClkAuxDrv
 * @{
 */
// RegRfLdoBgClkAuxDrv.r32
#define  REG_RF_LDO_BG_CLK_AUX_DRV_RESET_VALUE              0x00000180u                   /**< Reset value of RegRfLdoBgClkAuxDrv */
#define  REG_RF_LDO_BG_CLK_AUX_DRV_MASK                     0x00000FFFu                   /**< Mask for RegRfLdoBgClkAuxDrv */

#define  RF_LDO_RXTXHF_FORCE_SHIFT                          0                             /**< Shift for RfLdoRxtxhfForce */
#define  RF_LDO_RXTXHF_FORCE_MASK                           0x00000001u                   /**< Mask for RfLdoRxtxhfForce */
#define  RF_LDO_RXTXHF_FORCE_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxhfForce */
#define  RF_LDO_RXTXHF_FORCE(x)                             (((x)&0x1u)<<0)               /**< Set RfLdoRxtxhfForce in register */
#define  GET_RF_LDO_RXTXHF_FORCE(reg)                       (((reg)>>0)&0x1u)             /**< Get RfLdoRxtxhfForce from register */
#define  RF_LDO_RXTXLF_FORCE_SHIFT                          1                             /**< Shift for RfLdoRxtxlfForce */
#define  RF_LDO_RXTXLF_FORCE_MASK                           0x00000002u                   /**< Mask for RfLdoRxtxlfForce */
#define  RF_LDO_RXTXLF_FORCE_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxlfForce */
#define  RF_LDO_RXTXLF_FORCE(x)                             (((x)&0x1u)<<1)               /**< Set RfLdoRxtxlfForce in register */
#define  GET_RF_LDO_RXTXLF_FORCE(reg)                       (((reg)>>1)&0x1u)             /**< Get RfLdoRxtxlfForce from register */
#define  RF_LDO_PLL_FORCE_SHIFT                             2                             /**< Shift for RfLdoPllForce */
#define  RF_LDO_PLL_FORCE_MASK                              0x00000004u                   /**< Mask for RfLdoPllForce */
#define  RF_LDO_PLL_FORCE_BMASK                             0x1u                          /**< Base mask for RfLdoPllForce */
#define  RF_LDO_PLL_FORCE(x)                                (((x)&0x1u)<<2)               /**< Set RfLdoPllForce in register */
#define  GET_RF_LDO_PLL_FORCE(reg)                          (((reg)>>2)&0x1u)             /**< Get RfLdoPllForce from register */
#define  RF_LDO_VCO_FORCE_SHIFT                             3                             /**< Shift for RfLdoVcoForce */
#define  RF_LDO_VCO_FORCE_MASK                              0x00000008u                   /**< Mask for RfLdoVcoForce */
#define  RF_LDO_VCO_FORCE_BMASK                             0x1u                          /**< Base mask for RfLdoVcoForce */
#define  RF_LDO_VCO_FORCE(x)                                (((x)&0x1u)<<3)               /**< Set RfLdoVcoForce in register */
#define  GET_RF_LDO_VCO_FORCE(reg)                          (((reg)>>3)&0x1u)             /**< Get RfLdoVcoForce from register */
#define  RF_LDO_CAL_FORCE_SHIFT                             4                             /**< Shift for RfLdoCalForce */
#define  RF_LDO_CAL_FORCE_MASK                              0x00000010u                   /**< Mask for RfLdoCalForce */
#define  RF_LDO_CAL_FORCE_BMASK                             0x1u                          /**< Base mask for RfLdoCalForce */
#define  RF_LDO_CAL_FORCE(x)                                (((x)&0x1u)<<4)               /**< Set RfLdoCalForce in register */
#define  GET_RF_LDO_CAL_FORCE(reg)                          (((reg)>>4)&0x1u)             /**< Get RfLdoCalForce from register */
#define  RF_LDO_ANT_HIZ_SHIFT                               5                             /**< Shift for RfLdoAntHiz */
#define  RF_LDO_ANT_HIZ_MASK                                0x00000020u                   /**< Mask for RfLdoAntHiz */
#define  RF_LDO_ANT_HIZ_BMASK                               0x1u                          /**< Base mask for RfLdoAntHiz */
#define  RF_LDO_ANT_HIZ(x)                                  (((x)&0x1u)<<5)               /**< Set RfLdoAntHiz in register */
#define  GET_RF_LDO_ANT_HIZ(reg)                            (((reg)>>5)&0x1u)             /**< Get RfLdoAntHiz from register */
#define  RF_LDO_ANT_REF_SEL_SHIFT                           6                             /**< Shift for RfLdoAntRefSel */
#define  RF_LDO_ANT_REF_SEL_MASK                            0x00000040u                   /**< Mask for RfLdoAntRefSel */
#define  RF_LDO_ANT_REF_SEL_BMASK                           0x1u                          /**< Base mask for RfLdoAntRefSel */
#define  RF_LDO_ANT_REF_SEL(x)                              (((x)&0x1u)<<6)               /**< Set RfLdoAntRefSel in register */
#define  GET_RF_LDO_ANT_REF_SEL(reg)                        (((reg)>>6)&0x1u)             /**< Get RfLdoAntRefSel from register */
#define  RF_BG_TRIM_SHIFT                                   7                             /**< Shift for RfBgTrim */
#define  RF_BG_TRIM_MASK                                    0x00000380u                   /**< Mask for RfBgTrim */
#define  RF_BG_TRIM_BMASK                                   0x7u                          /**< Base mask for RfBgTrim */
#define  RF_BG_TRIM(x)                                      (((x)&0x7u)<<7)               /**< Set RfBgTrim in register */
#define  GET_RF_BG_TRIM(reg)                                (((reg)>>7)&0x7u)             /**< Get RfBgTrim from register */
#define  RF_BG_FORCE_SHIFT                                  10                            /**< Shift for RfBgForce */
#define  RF_BG_FORCE_MASK                                   0x00000400u                   /**< Mask for RfBgForce */
#define  RF_BG_FORCE_BMASK                                  0x1u                          /**< Base mask for RfBgForce */
#define  RF_BG_FORCE(x)                                     (((x)&0x1u)<<10)              /**< Set RfBgForce in register */
#define  GET_RF_BG_FORCE(reg)                               (((reg)>>10)&0x1u)            /**< Get RfBgForce from register */
#define  RF_CLK_AUX_DRV_FORCE_PDN_SHIFT                     11                            /**< Shift for RfClkAuxDrvForcePdn */
#define  RF_CLK_AUX_DRV_FORCE_PDN_MASK                      0x00000800u                   /**< Mask for RfClkAuxDrvForcePdn */
#define  RF_CLK_AUX_DRV_FORCE_PDN_BMASK                     0x1u                          /**< Base mask for RfClkAuxDrvForcePdn */
#define  RF_CLK_AUX_DRV_FORCE_PDN(x)                        (((x)&0x1u)<<11)              /**< Set RfClkAuxDrvForcePdn in register */
#define  GET_RF_CLK_AUX_DRV_FORCE_PDN(reg)                  (((reg)>>11)&0x1u)            /**< Get RfClkAuxDrvForcePdn from register */
/** @} */


/**
 * @name RegRfLnmPa
 * @{
 */
// RegRfLnmPa.r32
#define  REG_RF_LNM_PA_RESET_VALUE                          0x00000001u                   /**< Reset value of RegRfLnmPa */
#define  REG_RF_LNM_PA_MASK                                 0x000003FFu                   /**< Mask for RegRfLnmPa */

#define  RF_LNA_ITRIM_SHIFT                                 0                             /**< Shift for RfLnaItrim */
#define  RF_LNA_ITRIM_MASK                                  0x00000003u                   /**< Mask for RfLnaItrim */
#define  RF_LNA_ITRIM_BMASK                                 0x3u                          /**< Base mask for RfLnaItrim */
#define  RF_LNA_ITRIM(x)                                    (((x)&0x3u)<<0)               /**< Set RfLnaItrim in register */
#define  GET_RF_LNA_ITRIM(reg)                              (((reg)>>0)&0x3u)             /**< Get RfLnaItrim from register */
#define  RF_MIX_VBIAS_SHIFT                                 2                             /**< Shift for RfMixVbias */
#define  RF_MIX_VBIAS_MASK                                  0x0000000Cu                   /**< Mask for RfMixVbias */
#define  RF_MIX_VBIAS_BMASK                                 0x3u                          /**< Base mask for RfMixVbias */
#define  RF_MIX_VBIAS(x)                                    (((x)&0x3u)<<2)               /**< Set RfMixVbias in register */
#define  GET_RF_MIX_VBIAS(reg)                              (((reg)>>2)&0x3u)             /**< Get RfMixVbias from register */
#define  RF_PA_VBIAS_SHIFT                                  4                             /**< Shift for RfPaVbias */
#define  RF_PA_VBIAS_MASK                                   0x00000030u                   /**< Mask for RfPaVbias */
#define  RF_PA_VBIAS_BMASK                                  0x3u                          /**< Base mask for RfPaVbias */
#define  RF_PA_VBIAS(x)                                     (((x)&0x3u)<<4)               /**< Set RfPaVbias in register */
#define  GET_RF_PA_VBIAS(reg)                               (((reg)>>4)&0x3u)             /**< Get RfPaVbias from register */
#define  RF_RTFE_PTAT_FORCE_SHIFT                           6                             /**< Shift for RfRtfePtatForce */
#define  RF_RTFE_PTAT_FORCE_MASK                            0x00000040u                   /**< Mask for RfRtfePtatForce */
#define  RF_RTFE_PTAT_FORCE_BMASK                           0x1u                          /**< Base mask for RfRtfePtatForce */
#define  RF_RTFE_PTAT_FORCE(x)                              (((x)&0x1u)<<6)               /**< Set RfRtfePtatForce in register */
#define  GET_RF_RTFE_PTAT_FORCE(reg)                        (((reg)>>6)&0x1u)             /**< Get RfRtfePtatForce from register */
#define  RF_FE_RTRIM_TX_SHIFT                               7                             /**< Shift for RfFeRtrimTx */
#define  RF_FE_RTRIM_TX_MASK                                0x00000380u                   /**< Mask for RfFeRtrimTx */
#define  RF_FE_RTRIM_TX_BMASK                               0x7u                          /**< Base mask for RfFeRtrimTx */
#define  RF_FE_RTRIM_TX(x)                                  (((x)&0x7u)<<7)               /**< Set RfFeRtrimTx in register */
#define  GET_RF_FE_RTRIM_TX(reg)                            (((reg)>>7)&0x7u)             /**< Get RfFeRtrimTx from register */
/** @} */


/**
 * @name RegRfCbpfAdc
 * @{
 */
// RegRfCbpfAdc.r32
#define  REG_RF_CBPF_ADC_RESET_VALUE                        0x00000B40u                   /**< Reset value of RegRfCbpfAdc */
#define  REG_RF_CBPF_ADC_MASK                               0x00000FFFu                   /**< Mask for RegRfCbpfAdc */

#define  RF_CBPF_TRIM_I_SHIFT                               0                             /**< Shift for RfCbpfTrimI */
#define  RF_CBPF_TRIM_I_MASK                                0x00000003u                   /**< Mask for RfCbpfTrimI */
#define  RF_CBPF_TRIM_I_BMASK                               0x3u                          /**< Base mask for RfCbpfTrimI */
#define  RF_CBPF_TRIM_I(x)                                  (((x)&0x3u)<<0)               /**< Set RfCbpfTrimI in register */
#define  GET_RF_CBPF_TRIM_I(reg)                            (((reg)>>0)&0x3u)             /**< Get RfCbpfTrimI from register */
#define  RF_CBPF_TRIM_Q_SHIFT                               2                             /**< Shift for RfCbpfTrimQ */
#define  RF_CBPF_TRIM_Q_MASK                                0x0000000Cu                   /**< Mask for RfCbpfTrimQ */
#define  RF_CBPF_TRIM_Q_BMASK                               0x3u                          /**< Base mask for RfCbpfTrimQ */
#define  RF_CBPF_TRIM_Q(x)                                  (((x)&0x3u)<<2)               /**< Set RfCbpfTrimQ in register */
#define  GET_RF_CBPF_TRIM_Q(reg)                            (((reg)>>2)&0x3u)             /**< Get RfCbpfTrimQ from register */
#define  RF_CBPF_EN_DIAG_MEAS_SHIFT                         4                             /**< Shift for RfCbpfEnDiagMeas */
#define  RF_CBPF_EN_DIAG_MEAS_MASK                          0x00000010u                   /**< Mask for RfCbpfEnDiagMeas */
#define  RF_CBPF_EN_DIAG_MEAS_BMASK                         0x1u                          /**< Base mask for RfCbpfEnDiagMeas */
#define  RF_CBPF_EN_DIAG_MEAS(x)                            (((x)&0x1u)<<4)               /**< Set RfCbpfEnDiagMeas in register */
#define  GET_RF_CBPF_EN_DIAG_MEAS(reg)                      (((reg)>>4)&0x1u)             /**< Get RfCbpfEnDiagMeas from register */
#define  RF_CBPF_TRIM_SHORT_DCBIAS_SHIFT                    5                             /**< Shift for RfCbpfTrimShortDcbias */
#define  RF_CBPF_TRIM_SHORT_DCBIAS_MASK                     0x00000060u                   /**< Mask for RfCbpfTrimShortDcbias */
#define  RF_CBPF_TRIM_SHORT_DCBIAS_BMASK                    0x3u                          /**< Base mask for RfCbpfTrimShortDcbias */
#define  RF_CBPF_TRIM_SHORT_DCBIAS(x)                       (((x)&0x3u)<<5)               /**< Set RfCbpfTrimShortDcbias in register */
#define  GET_RF_CBPF_TRIM_SHORT_DCBIAS(reg)                 (((reg)>>5)&0x3u)             /**< Get RfCbpfTrimShortDcbias from register */
#define  RF_CBPF_VCM_TRIM_SHIFT                             7                             /**< Shift for RfCbpfVcmTrim */
#define  RF_CBPF_VCM_TRIM_MASK                              0x00000180u                   /**< Mask for RfCbpfVcmTrim */
#define  RF_CBPF_VCM_TRIM_BMASK                             0x3u                          /**< Base mask for RfCbpfVcmTrim */
#define  RF_CBPF_VCM_TRIM(x)                                (((x)&0x3u)<<7)               /**< Set RfCbpfVcmTrim in register */
#define  GET_RF_CBPF_VCM_TRIM(reg)                          (((reg)>>7)&0x3u)             /**< Get RfCbpfVcmTrim from register */
#define  RF_ADC_TRIM_SHIFT                                  9                             /**< Shift for RfAdcTrim */
#define  RF_ADC_TRIM_MASK                                   0x00000600u                   /**< Mask for RfAdcTrim */
#define  RF_ADC_TRIM_BMASK                                  0x3u                          /**< Base mask for RfAdcTrim */
#define  RF_ADC_TRIM(x)                                     (((x)&0x3u)<<9)               /**< Set RfAdcTrim in register */
#define  GET_RF_ADC_TRIM(reg)                               (((reg)>>9)&0x3u)             /**< Get RfAdcTrim from register */
#define  RF_ADC_INVERT_CLK_SHIFT                            11                            /**< Shift for RfAdcInvertClk */
#define  RF_ADC_INVERT_CLK_MASK                             0x00000800u                   /**< Mask for RfAdcInvertClk */
#define  RF_ADC_INVERT_CLK_BMASK                            0x1u                          /**< Base mask for RfAdcInvertClk */
#define  RF_ADC_INVERT_CLK(x)                               (((x)&0x1u)<<11)              /**< Set RfAdcInvertClk in register */
#define  GET_RF_ADC_INVERT_CLK(reg)                         (((reg)>>11)&0x1u)            /**< Get RfAdcInvertClk from register */
/** @} */


/**
 * @name RegRfPdTxdac
 * @{
 */
// RegRfPdTxdac.r32
#define  REG_RF_PD_TXDAC_RESET_VALUE                        0x00002100u                   /**< Reset value of RegRfPdTxdac */
#define  REG_RF_PD_TXDAC_MASK                               0x00003FFFu                   /**< Mask for RegRfPdTxdac */

#define  RF_PD_TRIM_FCAL_BIAS_SHIFT                         0                             /**< Shift for RfPdTrimFcalBias */
#define  RF_PD_TRIM_FCAL_BIAS_MASK                          0x00000003u                   /**< Mask for RfPdTrimFcalBias */
#define  RF_PD_TRIM_FCAL_BIAS_BMASK                         0x3u                          /**< Base mask for RfPdTrimFcalBias */
#define  RF_PD_TRIM_FCAL_BIAS(x)                            (((x)&0x3u)<<0)               /**< Set RfPdTrimFcalBias in register */
#define  GET_RF_PD_TRIM_FCAL_BIAS(reg)                      (((reg)>>0)&0x3u)             /**< Get RfPdTrimFcalBias from register */
#define  RF_PD_EN_VPD_PULLUP_SHIFT                          2                             /**< Shift for RfPdEnVpdPullup */
#define  RF_PD_EN_VPD_PULLUP_MASK                           0x00000004u                   /**< Mask for RfPdEnVpdPullup */
#define  RF_PD_EN_VPD_PULLUP_BMASK                          0x1u                          /**< Base mask for RfPdEnVpdPullup */
#define  RF_PD_EN_VPD_PULLUP(x)                             (((x)&0x1u)<<2)               /**< Set RfPdEnVpdPullup in register */
#define  GET_RF_PD_EN_VPD_PULLUP(reg)                       (((reg)>>2)&0x1u)             /**< Get RfPdEnVpdPullup from register */
#define  RF_PD_EN_VPD_PULLDN_SHIFT                          3                             /**< Shift for RfPdEnVpdPulldn */
#define  RF_PD_EN_VPD_PULLDN_MASK                           0x00000008u                   /**< Mask for RfPdEnVpdPulldn */
#define  RF_PD_EN_VPD_PULLDN_BMASK                          0x1u                          /**< Base mask for RfPdEnVpdPulldn */
#define  RF_PD_EN_VPD_PULLDN(x)                             (((x)&0x1u)<<3)               /**< Set RfPdEnVpdPulldn in register */
#define  GET_RF_PD_EN_VPD_PULLDN(reg)                       (((reg)>>3)&0x1u)             /**< Get RfPdEnVpdPulldn from register */
#define  RF_DAC_TRIM_IBIAS_SHIFT                            4                             /**< Shift for RfDacTrimIbias */
#define  RF_DAC_TRIM_IBIAS_MASK                             0x00000030u                   /**< Mask for RfDacTrimIbias */
#define  RF_DAC_TRIM_IBIAS_BMASK                            0x3u                          /**< Base mask for RfDacTrimIbias */
#define  RF_DAC_TRIM_IBIAS(x)                               (((x)&0x3u)<<4)               /**< Set RfDacTrimIbias in register */
#define  GET_RF_DAC_TRIM_IBIAS(reg)                         (((reg)>>4)&0x3u)             /**< Get RfDacTrimIbias from register */
#define  RF_DAC_TRIM_RLOAD_SHIFT                            6                             /**< Shift for RfDacTrimRload */
#define  RF_DAC_TRIM_RLOAD_MASK                             0x000000C0u                   /**< Mask for RfDacTrimRload */
#define  RF_DAC_TRIM_RLOAD_BMASK                            0x3u                          /**< Base mask for RfDacTrimRload */
#define  RF_DAC_TRIM_RLOAD(x)                               (((x)&0x3u)<<6)               /**< Set RfDacTrimRload in register */
#define  GET_RF_DAC_TRIM_RLOAD(reg)                         (((reg)>>6)&0x3u)             /**< Get RfDacTrimRload from register */
#define  RF_DAC_TRIM_VCM_SHIFT                              8                             /**< Shift for RfDacTrimVcm */
#define  RF_DAC_TRIM_VCM_MASK                               0x00000700u                   /**< Mask for RfDacTrimVcm */
#define  RF_DAC_TRIM_VCM_BMASK                              0x7u                          /**< Base mask for RfDacTrimVcm */
#define  RF_DAC_TRIM_VCM(x)                                 (((x)&0x7u)<<8)               /**< Set RfDacTrimVcm in register */
#define  GET_RF_DAC_TRIM_VCM(reg)                           (((reg)>>8)&0x7u)             /**< Get RfDacTrimVcm from register */
#define  RF_DAC_TRIM_RFBK_SHIFT                             11                            /**< Shift for RfDacTrimRfbk */
#define  RF_DAC_TRIM_RFBK_MASK                              0x00001800u                   /**< Mask for RfDacTrimRfbk */
#define  RF_DAC_TRIM_RFBK_BMASK                             0x3u                          /**< Base mask for RfDacTrimRfbk */
#define  RF_DAC_TRIM_RFBK(x)                                (((x)&0x3u)<<11)              /**< Set RfDacTrimRfbk in register */
#define  GET_RF_DAC_TRIM_RFBK(reg)                          (((reg)>>11)&0x3u)            /**< Get RfDacTrimRfbk from register */
#define  RF_DAC_INVERT_CLK_SHIFT                            13                            /**< Shift for RfDacInvertClk */
#define  RF_DAC_INVERT_CLK_MASK                             0x00002000u                   /**< Mask for RfDacInvertClk */
#define  RF_DAC_INVERT_CLK_BMASK                            0x1u                          /**< Base mask for RfDacInvertClk */
#define  RF_DAC_INVERT_CLK(x)                               (((x)&0x1u)<<13)              /**< Set RfDacInvertClk in register */
#define  GET_RF_DAC_INVERT_CLK(reg)                         (((reg)>>13)&0x1u)            /**< Get RfDacInvertClk from register */
/** @} */


/**
 * @name RegRfVcoLdotrim
 * @{
 */
// RegRfVcoLdotrim.r32
#define  REG_RF_VCO_LDOTRIM_RESET_VALUE                     0x00000037u                   /**< Reset value of RegRfVcoLdotrim */
#define  REG_RF_VCO_LDOTRIM_MASK                            0x0000003Fu                   /**< Mask for RegRfVcoLdotrim */

#define  RF_VCO_TRIM_KVT_SHIFT                              0                             /**< Shift for RfVcoTrimKvt */
#define  RF_VCO_TRIM_KVT_MASK                               0x00000007u                   /**< Mask for RfVcoTrimKvt */
#define  RF_VCO_TRIM_KVT_BMASK                              0x7u                          /**< Base mask for RfVcoTrimKvt */
#define  RF_VCO_TRIM_KVT(x)                                 (((x)&0x7u)<<0)               /**< Set RfVcoTrimKvt in register */
#define  GET_RF_VCO_TRIM_KVT(reg)                           (((reg)>>0)&0x7u)             /**< Get RfVcoTrimKvt from register */
#define  RF_VCO_EN_PKDET_SHIFT                              3                             /**< Shift for RfVcoEnPkdet */
#define  RF_VCO_EN_PKDET_MASK                               0x00000008u                   /**< Mask for RfVcoEnPkdet */
#define  RF_VCO_EN_PKDET_BMASK                              0x1u                          /**< Base mask for RfVcoEnPkdet */
#define  RF_VCO_EN_PKDET(x)                                 (((x)&0x1u)<<3)               /**< Set RfVcoEnPkdet in register */
#define  GET_RF_VCO_EN_PKDET(reg)                           (((reg)>>3)&0x1u)             /**< Get RfVcoEnPkdet from register */
#define  RF_LDOTRIM_TRIM_VREF_SHIFT                         4                             /**< Shift for RfLdotrimTrimVref */
#define  RF_LDOTRIM_TRIM_VREF_MASK                          0x00000030u                   /**< Mask for RfLdotrimTrimVref */
#define  RF_LDOTRIM_TRIM_VREF_BMASK                         0x3u                          /**< Base mask for RfLdotrimTrimVref */
#define  RF_LDOTRIM_TRIM_VREF(x)                            (((x)&0x3u)<<4)               /**< Set RfLdotrimTrimVref in register */
#define  GET_RF_LDOTRIM_TRIM_VREF(reg)                      (((reg)>>4)&0x3u)             /**< Get RfLdotrimTrimVref from register */
/** @} */


/**
 * @name RegRfRegSparelv1
 * @{
 */
// RegRfRegSparelv1.r32
#define  REG_RF_REG_SPARELV1_RESET_VALUE                    0x00000001u                   /**< Reset value of RegRfRegSparelv1 */
#define  REG_RF_REG_SPARELV1_MASK                           0x000007FFu                   /**< Mask for RegRfRegSparelv1 */

#define  RF_SPARE0_SHIFT                                    0                             /**< Shift for RfSpare0 */
#define  RF_SPARE0_MASK                                     0x00000001u                   /**< Mask for RfSpare0 */
#define  RF_SPARE0_BMASK                                    0x1u                          /**< Base mask for RfSpare0 */
#define  RF_SPARE0(x)                                       (((x)&0x1u)<<0)               /**< Set RfSpare0 in register */
#define  GET_RF_SPARE0(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfSpare0 from register */
#define  RF_SPARE1_SHIFT                                    1                             /**< Shift for RfSpare1 */
#define  RF_SPARE1_MASK                                     0x00000002u                   /**< Mask for RfSpare1 */
#define  RF_SPARE1_BMASK                                    0x1u                          /**< Base mask for RfSpare1 */
#define  RF_SPARE1(x)                                       (((x)&0x1u)<<1)               /**< Set RfSpare1 in register */
#define  GET_RF_SPARE1(reg)                                 (((reg)>>1)&0x1u)             /**< Get RfSpare1 from register */
#define  RF_SPARE2_SHIFT                                    2                             /**< Shift for RfSpare2 */
#define  RF_SPARE2_MASK                                     0x00000004u                   /**< Mask for RfSpare2 */
#define  RF_SPARE2_BMASK                                    0x1u                          /**< Base mask for RfSpare2 */
#define  RF_SPARE2(x)                                       (((x)&0x1u)<<2)               /**< Set RfSpare2 in register */
#define  GET_RF_SPARE2(reg)                                 (((reg)>>2)&0x1u)             /**< Get RfSpare2 from register */
#define  RF_SPARE3_SHIFT                                    3                             /**< Shift for RfSpare3 */
#define  RF_SPARE3_MASK                                     0x00000008u                   /**< Mask for RfSpare3 */
#define  RF_SPARE3_BMASK                                    0x1u                          /**< Base mask for RfSpare3 */
#define  RF_SPARE3(x)                                       (((x)&0x1u)<<3)               /**< Set RfSpare3 in register */
#define  GET_RF_SPARE3(reg)                                 (((reg)>>3)&0x1u)             /**< Get RfSpare3 from register */
#define  RF_SPARE4_SHIFT                                    4                             /**< Shift for RfSpare4 */
#define  RF_SPARE4_MASK                                     0x00000010u                   /**< Mask for RfSpare4 */
#define  RF_SPARE4_BMASK                                    0x1u                          /**< Base mask for RfSpare4 */
#define  RF_SPARE4(x)                                       (((x)&0x1u)<<4)               /**< Set RfSpare4 in register */
#define  GET_RF_SPARE4(reg)                                 (((reg)>>4)&0x1u)             /**< Get RfSpare4 from register */
#define  RF_SPARE5_SHIFT                                    5                             /**< Shift for RfSpare5 */
#define  RF_SPARE5_MASK                                     0x00000020u                   /**< Mask for RfSpare5 */
#define  RF_SPARE5_BMASK                                    0x1u                          /**< Base mask for RfSpare5 */
#define  RF_SPARE5(x)                                       (((x)&0x1u)<<5)               /**< Set RfSpare5 in register */
#define  GET_RF_SPARE5(reg)                                 (((reg)>>5)&0x1u)             /**< Get RfSpare5 from register */
#define  RF_SPARE6_SHIFT                                    6                             /**< Shift for RfSpare6 */
#define  RF_SPARE6_MASK                                     0x00000040u                   /**< Mask for RfSpare6 */
#define  RF_SPARE6_BMASK                                    0x1u                          /**< Base mask for RfSpare6 */
#define  RF_SPARE6(x)                                       (((x)&0x1u)<<6)               /**< Set RfSpare6 in register */
#define  GET_RF_SPARE6(reg)                                 (((reg)>>6)&0x1u)             /**< Get RfSpare6 from register */
#define  RF_SPARE7_SHIFT                                    7                             /**< Shift for RfSpare7 */
#define  RF_SPARE7_MASK                                     0x00000080u                   /**< Mask for RfSpare7 */
#define  RF_SPARE7_BMASK                                    0x1u                          /**< Base mask for RfSpare7 */
#define  RF_SPARE7(x)                                       (((x)&0x1u)<<7)               /**< Set RfSpare7 in register */
#define  GET_RF_SPARE7(reg)                                 (((reg)>>7)&0x1u)             /**< Get RfSpare7 from register */
#define  RF_SPARE8_SHIFT                                    8                             /**< Shift for RfSpare8 */
#define  RF_SPARE8_MASK                                     0x00000100u                   /**< Mask for RfSpare8 */
#define  RF_SPARE8_BMASK                                    0x1u                          /**< Base mask for RfSpare8 */
#define  RF_SPARE8(x)                                       (((x)&0x1u)<<8)               /**< Set RfSpare8 in register */
#define  GET_RF_SPARE8(reg)                                 (((reg)>>8)&0x1u)             /**< Get RfSpare8 from register */
#define  RF_SPARE9_SHIFT                                    9                             /**< Shift for RfSpare9 */
#define  RF_SPARE9_MASK                                     0x00000200u                   /**< Mask for RfSpare9 */
#define  RF_SPARE9_BMASK                                    0x1u                          /**< Base mask for RfSpare9 */
#define  RF_SPARE9(x)                                       (((x)&0x1u)<<9)               /**< Set RfSpare9 in register */
#define  GET_RF_SPARE9(reg)                                 (((reg)>>9)&0x1u)             /**< Get RfSpare9 from register */
#define  RF_SPARE10_SHIFT                                   10                            /**< Shift for RfSpare10 */
#define  RF_SPARE10_MASK                                    0x00000400u                   /**< Mask for RfSpare10 */
#define  RF_SPARE10_BMASK                                   0x1u                          /**< Base mask for RfSpare10 */
#define  RF_SPARE10(x)                                      (((x)&0x1u)<<10)              /**< Set RfSpare10 in register */
#define  GET_RF_SPARE10(reg)                                (((reg)>>10)&0x1u)            /**< Get RfSpare10 from register */
/** @} */


/**
 * @name RegRfLdoOwCtrl
 * @{
 */
// RegRfLdoOwCtrl.r32
#define  REG_RF_LDO_OW_CTRL_RESET_VALUE                     0x00000000u                   /**< Reset value of RegRfLdoOwCtrl */
#define  REG_RF_LDO_OW_CTRL_MASK                            0x000007FFu                   /**< Mask for RegRfLdoOwCtrl */

#define  RF_LDO_LV_PUP_OW_SHIFT                             0                             /**< Shift for RfLdoLvPupOw */
#define  RF_LDO_LV_PUP_OW_MASK                              0x00000001u                   /**< Mask for RfLdoLvPupOw */
#define  RF_LDO_LV_PUP_OW_BMASK                             0x1u                          /**< Base mask for RfLdoLvPupOw */
#define  RF_LDO_LV_PUP_OW(x)                                (((x)&0x1u)<<0)               /**< Set RfLdoLvPupOw in register */
#define  GET_RF_LDO_LV_PUP_OW(reg)                          (((reg)>>0)&0x1u)             /**< Get RfLdoLvPupOw from register */
#define  RF_LDO_RXTXHF_PUP_OW_SHIFT                         1                             /**< Shift for RfLdoRxtxhfPupOw */
#define  RF_LDO_RXTXHF_PUP_OW_MASK                          0x00000002u                   /**< Mask for RfLdoRxtxhfPupOw */
#define  RF_LDO_RXTXHF_PUP_OW_BMASK                         0x1u                          /**< Base mask for RfLdoRxtxhfPupOw */
#define  RF_LDO_RXTXHF_PUP_OW(x)                            (((x)&0x1u)<<1)               /**< Set RfLdoRxtxhfPupOw in register */
#define  GET_RF_LDO_RXTXHF_PUP_OW(reg)                      (((reg)>>1)&0x1u)             /**< Get RfLdoRxtxhfPupOw from register */
#define  RF_LDO_RXTXLF_PUP_OW_SHIFT                         2                             /**< Shift for RfLdoRxtxlfPupOw */
#define  RF_LDO_RXTXLF_PUP_OW_MASK                          0x00000004u                   /**< Mask for RfLdoRxtxlfPupOw */
#define  RF_LDO_RXTXLF_PUP_OW_BMASK                         0x1u                          /**< Base mask for RfLdoRxtxlfPupOw */
#define  RF_LDO_RXTXLF_PUP_OW(x)                            (((x)&0x1u)<<2)               /**< Set RfLdoRxtxlfPupOw in register */
#define  GET_RF_LDO_RXTXLF_PUP_OW(reg)                      (((reg)>>2)&0x1u)             /**< Get RfLdoRxtxlfPupOw from register */
#define  RF_LDO_PLL_PUP_OW_SHIFT                            3                             /**< Shift for RfLdoPllPupOw */
#define  RF_LDO_PLL_PUP_OW_MASK                             0x00000008u                   /**< Mask for RfLdoPllPupOw */
#define  RF_LDO_PLL_PUP_OW_BMASK                            0x1u                          /**< Base mask for RfLdoPllPupOw */
#define  RF_LDO_PLL_PUP_OW(x)                               (((x)&0x1u)<<3)               /**< Set RfLdoPllPupOw in register */
#define  GET_RF_LDO_PLL_PUP_OW(reg)                         (((reg)>>3)&0x1u)             /**< Get RfLdoPllPupOw from register */
#define  RF_LDO_VCO_PUP_OW_SHIFT                            4                             /**< Shift for RfLdoVcoPupOw */
#define  RF_LDO_VCO_PUP_OW_MASK                             0x00000010u                   /**< Mask for RfLdoVcoPupOw */
#define  RF_LDO_VCO_PUP_OW_BMASK                            0x1u                          /**< Base mask for RfLdoVcoPupOw */
#define  RF_LDO_VCO_PUP_OW(x)                               (((x)&0x1u)<<4)               /**< Set RfLdoVcoPupOw in register */
#define  GET_RF_LDO_VCO_PUP_OW(reg)                         (((reg)>>4)&0x1u)             /**< Get RfLdoVcoPupOw from register */
#define  RF_LDO_CAL_PUP_OW_SHIFT                            5                             /**< Shift for RfLdoCalPupOw */
#define  RF_LDO_CAL_PUP_OW_MASK                             0x00000020u                   /**< Mask for RfLdoCalPupOw */
#define  RF_LDO_CAL_PUP_OW_BMASK                            0x1u                          /**< Base mask for RfLdoCalPupOw */
#define  RF_LDO_CAL_PUP_OW(x)                               (((x)&0x1u)<<5)               /**< Set RfLdoCalPupOw in register */
#define  GET_RF_LDO_CAL_PUP_OW(reg)                         (((reg)>>5)&0x1u)             /**< Get RfLdoCalPupOw from register */
#define  RF_LDO_ANT_PUP_OW_SHIFT                            6                             /**< Shift for RfLdoAntPupOw */
#define  RF_LDO_ANT_PUP_OW_MASK                             0x00000040u                   /**< Mask for RfLdoAntPupOw */
#define  RF_LDO_ANT_PUP_OW_BMASK                            0x1u                          /**< Base mask for RfLdoAntPupOw */
#define  RF_LDO_ANT_PUP_OW(x)                               (((x)&0x1u)<<6)               /**< Set RfLdoAntPupOw in register */
#define  GET_RF_LDO_ANT_PUP_OW(reg)                         (((reg)>>6)&0x1u)             /**< Get RfLdoAntPupOw from register */
#define  RF_LDO_RXTXHF_FC_OW_SHIFT                          7                             /**< Shift for RfLdoRxtxhfFcOw */
#define  RF_LDO_RXTXHF_FC_OW_MASK                           0x00000080u                   /**< Mask for RfLdoRxtxhfFcOw */
#define  RF_LDO_RXTXHF_FC_OW_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxhfFcOw */
#define  RF_LDO_RXTXHF_FC_OW(x)                             (((x)&0x1u)<<7)               /**< Set RfLdoRxtxhfFcOw in register */
#define  GET_RF_LDO_RXTXHF_FC_OW(reg)                       (((reg)>>7)&0x1u)             /**< Get RfLdoRxtxhfFcOw from register */
#define  RF_LDO_RXTXLF_FC_OW_SHIFT                          8                             /**< Shift for RfLdoRxtxlfFcOw */
#define  RF_LDO_RXTXLF_FC_OW_MASK                           0x00000100u                   /**< Mask for RfLdoRxtxlfFcOw */
#define  RF_LDO_RXTXLF_FC_OW_BMASK                          0x1u                          /**< Base mask for RfLdoRxtxlfFcOw */
#define  RF_LDO_RXTXLF_FC_OW(x)                             (((x)&0x1u)<<8)               /**< Set RfLdoRxtxlfFcOw in register */
#define  GET_RF_LDO_RXTXLF_FC_OW(reg)                       (((reg)>>8)&0x1u)             /**< Get RfLdoRxtxlfFcOw from register */
#define  RF_LDO_PLL_FC_OW_SHIFT                             9                             /**< Shift for RfLdoPllFcOw */
#define  RF_LDO_PLL_FC_OW_MASK                              0x00000200u                   /**< Mask for RfLdoPllFcOw */
#define  RF_LDO_PLL_FC_OW_BMASK                             0x1u                          /**< Base mask for RfLdoPllFcOw */
#define  RF_LDO_PLL_FC_OW(x)                                (((x)&0x1u)<<9)               /**< Set RfLdoPllFcOw in register */
#define  GET_RF_LDO_PLL_FC_OW(reg)                          (((reg)>>9)&0x1u)             /**< Get RfLdoPllFcOw from register */
#define  RF_LDO_VCO_FC_OW_SHIFT                             10                            /**< Shift for RfLdoVcoFcOw */
#define  RF_LDO_VCO_FC_OW_MASK                              0x00000400u                   /**< Mask for RfLdoVcoFcOw */
#define  RF_LDO_VCO_FC_OW_BMASK                             0x1u                          /**< Base mask for RfLdoVcoFcOw */
#define  RF_LDO_VCO_FC_OW(x)                                (((x)&0x1u)<<10)              /**< Set RfLdoVcoFcOw in register */
#define  GET_RF_LDO_VCO_FC_OW(reg)                          (((reg)>>10)&0x1u)            /**< Get RfLdoVcoFcOw from register */
/** @} */


/**
 * @name RegRfLdoOwVal
 * @{
 */
// RegRfLdoOwVal.r32
#define  REG_RF_LDO_OW_VAL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfLdoOwVal */
#define  REG_RF_LDO_OW_VAL_MASK                             0x000007FFu                   /**< Mask for RegRfLdoOwVal */

#define  RF_LDO_LV_PUP_SHIFT                                0                             /**< Shift for RfLdoLvPup */
#define  RF_LDO_LV_PUP_MASK                                 0x00000001u                   /**< Mask for RfLdoLvPup */
#define  RF_LDO_LV_PUP_BMASK                                0x1u                          /**< Base mask for RfLdoLvPup */
#define  RF_LDO_LV_PUP(x)                                   (((x)&0x1u)<<0)               /**< Set RfLdoLvPup in register */
#define  GET_RF_LDO_LV_PUP(reg)                             (((reg)>>0)&0x1u)             /**< Get RfLdoLvPup from register */
#define  RF_LDO_RXTXHF_PUP_SHIFT                            1                             /**< Shift for RfLdoRxtxhfPup */
#define  RF_LDO_RXTXHF_PUP_MASK                             0x00000002u                   /**< Mask for RfLdoRxtxhfPup */
#define  RF_LDO_RXTXHF_PUP_BMASK                            0x1u                          /**< Base mask for RfLdoRxtxhfPup */
#define  RF_LDO_RXTXHF_PUP(x)                               (((x)&0x1u)<<1)               /**< Set RfLdoRxtxhfPup in register */
#define  GET_RF_LDO_RXTXHF_PUP(reg)                         (((reg)>>1)&0x1u)             /**< Get RfLdoRxtxhfPup from register */
#define  RF_LDO_RXTXLF_PUP_SHIFT                            2                             /**< Shift for RfLdoRxtxlfPup */
#define  RF_LDO_RXTXLF_PUP_MASK                             0x00000004u                   /**< Mask for RfLdoRxtxlfPup */
#define  RF_LDO_RXTXLF_PUP_BMASK                            0x1u                          /**< Base mask for RfLdoRxtxlfPup */
#define  RF_LDO_RXTXLF_PUP(x)                               (((x)&0x1u)<<2)               /**< Set RfLdoRxtxlfPup in register */
#define  GET_RF_LDO_RXTXLF_PUP(reg)                         (((reg)>>2)&0x1u)             /**< Get RfLdoRxtxlfPup from register */
#define  RF_LDO_PLL_PUP_SHIFT                               3                             /**< Shift for RfLdoPllPup */
#define  RF_LDO_PLL_PUP_MASK                                0x00000008u                   /**< Mask for RfLdoPllPup */
#define  RF_LDO_PLL_PUP_BMASK                               0x1u                          /**< Base mask for RfLdoPllPup */
#define  RF_LDO_PLL_PUP(x)                                  (((x)&0x1u)<<3)               /**< Set RfLdoPllPup in register */
#define  GET_RF_LDO_PLL_PUP(reg)                            (((reg)>>3)&0x1u)             /**< Get RfLdoPllPup from register */
#define  RF_LDO_VCO_PUP_SHIFT                               4                             /**< Shift for RfLdoVcoPup */
#define  RF_LDO_VCO_PUP_MASK                                0x00000010u                   /**< Mask for RfLdoVcoPup */
#define  RF_LDO_VCO_PUP_BMASK                               0x1u                          /**< Base mask for RfLdoVcoPup */
#define  RF_LDO_VCO_PUP(x)                                  (((x)&0x1u)<<4)               /**< Set RfLdoVcoPup in register */
#define  GET_RF_LDO_VCO_PUP(reg)                            (((reg)>>4)&0x1u)             /**< Get RfLdoVcoPup from register */
#define  RF_LDO_CAL_PUP_SHIFT                               5                             /**< Shift for RfLdoCalPup */
#define  RF_LDO_CAL_PUP_MASK                                0x00000020u                   /**< Mask for RfLdoCalPup */
#define  RF_LDO_CAL_PUP_BMASK                               0x1u                          /**< Base mask for RfLdoCalPup */
#define  RF_LDO_CAL_PUP(x)                                  (((x)&0x1u)<<5)               /**< Set RfLdoCalPup in register */
#define  GET_RF_LDO_CAL_PUP(reg)                            (((reg)>>5)&0x1u)             /**< Get RfLdoCalPup from register */
#define  RF_LDO_ANT_PUP_SHIFT                               6                             /**< Shift for RfLdoAntPup */
#define  RF_LDO_ANT_PUP_MASK                                0x00000040u                   /**< Mask for RfLdoAntPup */
#define  RF_LDO_ANT_PUP_BMASK                               0x1u                          /**< Base mask for RfLdoAntPup */
#define  RF_LDO_ANT_PUP(x)                                  (((x)&0x1u)<<6)               /**< Set RfLdoAntPup in register */
#define  GET_RF_LDO_ANT_PUP(reg)                            (((reg)>>6)&0x1u)             /**< Get RfLdoAntPup from register */
#define  RF_LDO_RXTXHF_FC_SHIFT                             7                             /**< Shift for RfLdoRxtxhfFc */
#define  RF_LDO_RXTXHF_FC_MASK                              0x00000080u                   /**< Mask for RfLdoRxtxhfFc */
#define  RF_LDO_RXTXHF_FC_BMASK                             0x1u                          /**< Base mask for RfLdoRxtxhfFc */
#define  RF_LDO_RXTXHF_FC(x)                                (((x)&0x1u)<<7)               /**< Set RfLdoRxtxhfFc in register */
#define  GET_RF_LDO_RXTXHF_FC(reg)                          (((reg)>>7)&0x1u)             /**< Get RfLdoRxtxhfFc from register */
#define  RF_LDO_RXTXLF_FC_SHIFT                             8                             /**< Shift for RfLdoRxtxlfFc */
#define  RF_LDO_RXTXLF_FC_MASK                              0x00000100u                   /**< Mask for RfLdoRxtxlfFc */
#define  RF_LDO_RXTXLF_FC_BMASK                             0x1u                          /**< Base mask for RfLdoRxtxlfFc */
#define  RF_LDO_RXTXLF_FC(x)                                (((x)&0x1u)<<8)               /**< Set RfLdoRxtxlfFc in register */
#define  GET_RF_LDO_RXTXLF_FC(reg)                          (((reg)>>8)&0x1u)             /**< Get RfLdoRxtxlfFc from register */
#define  RF_LDO_PLL_FC_SHIFT                                9                             /**< Shift for RfLdoPllFc */
#define  RF_LDO_PLL_FC_MASK                                 0x00000200u                   /**< Mask for RfLdoPllFc */
#define  RF_LDO_PLL_FC_BMASK                                0x1u                          /**< Base mask for RfLdoPllFc */
#define  RF_LDO_PLL_FC(x)                                   (((x)&0x1u)<<9)               /**< Set RfLdoPllFc in register */
#define  GET_RF_LDO_PLL_FC(reg)                             (((reg)>>9)&0x1u)             /**< Get RfLdoPllFc from register */
#define  RF_LDO_VCO_FC_SHIFT                                10                            /**< Shift for RfLdoVcoFc */
#define  RF_LDO_VCO_FC_MASK                                 0x00000400u                   /**< Mask for RfLdoVcoFc */
#define  RF_LDO_VCO_FC_BMASK                                0x1u                          /**< Base mask for RfLdoVcoFc */
#define  RF_LDO_VCO_FC(x)                                   (((x)&0x1u)<<10)              /**< Set RfLdoVcoFc in register */
#define  GET_RF_LDO_VCO_FC(reg)                             (((reg)>>10)&0x1u)            /**< Get RfLdoVcoFc from register */
/** @} */


/**
 * @name RegRfBgOwCtrl
 * @{
 */
// RegRfBgOwCtrl.r32
#define  REG_RF_BG_OW_CTRL_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfBgOwCtrl */
#define  REG_RF_BG_OW_CTRL_MASK                             0x0000003Fu                   /**< Mask for RegRfBgOwCtrl */

#define  RF_BG_PUP_OW_SHIFT                                 0                             /**< Shift for RfBgPupOw */
#define  RF_BG_PUP_OW_MASK                                  0x00000001u                   /**< Mask for RfBgPupOw */
#define  RF_BG_PUP_OW_BMASK                                 0x1u                          /**< Base mask for RfBgPupOw */
#define  RF_BG_PUP_OW(x)                                    (((x)&0x1u)<<0)               /**< Set RfBgPupOw in register */
#define  GET_RF_BG_PUP_OW(reg)                              (((reg)>>0)&0x1u)             /**< Get RfBgPupOw from register */
#define  RF_BG_FC_OW_SHIFT                                  1                             /**< Shift for RfBgFcOw */
#define  RF_BG_FC_OW_MASK                                   0x00000002u                   /**< Mask for RfBgFcOw */
#define  RF_BG_FC_OW_BMASK                                  0x1u                          /**< Base mask for RfBgFcOw */
#define  RF_BG_FC_OW(x)                                     (((x)&0x1u)<<1)               /**< Set RfBgFcOw in register */
#define  GET_RF_BG_FC_OW(reg)                               (((reg)>>1)&0x1u)             /**< Get RfBgFcOw from register */
#define  RF_BG_PUP_IBG_TX_OW_SHIFT                          2                             /**< Shift for RfBgPupIbgTxOw */
#define  RF_BG_PUP_IBG_TX_OW_MASK                           0x00000004u                   /**< Mask for RfBgPupIbgTxOw */
#define  RF_BG_PUP_IBG_TX_OW_BMASK                          0x1u                          /**< Base mask for RfBgPupIbgTxOw */
#define  RF_BG_PUP_IBG_TX_OW(x)                             (((x)&0x1u)<<2)               /**< Set RfBgPupIbgTxOw in register */
#define  GET_RF_BG_PUP_IBG_TX_OW(reg)                       (((reg)>>2)&0x1u)             /**< Get RfBgPupIbgTxOw from register */
#define  RF_BG_PUP_IBG_RX_OW_SHIFT                          3                             /**< Shift for RfBgPupIbgRxOw */
#define  RF_BG_PUP_IBG_RX_OW_MASK                           0x00000008u                   /**< Mask for RfBgPupIbgRxOw */
#define  RF_BG_PUP_IBG_RX_OW_BMASK                          0x1u                          /**< Base mask for RfBgPupIbgRxOw */
#define  RF_BG_PUP_IBG_RX_OW(x)                             (((x)&0x1u)<<3)               /**< Set RfBgPupIbgRxOw in register */
#define  GET_RF_BG_PUP_IBG_RX_OW(reg)                       (((reg)>>3)&0x1u)             /**< Get RfBgPupIbgRxOw from register */
#define  RF_BG_PUP_IBG_CAL_OW_SHIFT                         4                             /**< Shift for RfBgPupIbgCalOw */
#define  RF_BG_PUP_IBG_CAL_OW_MASK                          0x00000010u                   /**< Mask for RfBgPupIbgCalOw */
#define  RF_BG_PUP_IBG_CAL_OW_BMASK                         0x1u                          /**< Base mask for RfBgPupIbgCalOw */
#define  RF_BG_PUP_IBG_CAL_OW(x)                            (((x)&0x1u)<<4)               /**< Set RfBgPupIbgCalOw in register */
#define  GET_RF_BG_PUP_IBG_CAL_OW(reg)                      (((reg)>>4)&0x1u)             /**< Get RfBgPupIbgCalOw from register */
#define  RF_BG_PUP_IBG_ANT_OW_SHIFT                         5                             /**< Shift for RfBgPupIbgAntOw */
#define  RF_BG_PUP_IBG_ANT_OW_MASK                          0x00000020u                   /**< Mask for RfBgPupIbgAntOw */
#define  RF_BG_PUP_IBG_ANT_OW_BMASK                         0x1u                          /**< Base mask for RfBgPupIbgAntOw */
#define  RF_BG_PUP_IBG_ANT_OW(x)                            (((x)&0x1u)<<5)               /**< Set RfBgPupIbgAntOw in register */
#define  GET_RF_BG_PUP_IBG_ANT_OW(reg)                      (((reg)>>5)&0x1u)             /**< Get RfBgPupIbgAntOw from register */
/** @} */


/**
 * @name RegRfBgOwVal
 * @{
 */
// RegRfBgOwVal.r32
#define  REG_RF_BG_OW_VAL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfBgOwVal */
#define  REG_RF_BG_OW_VAL_MASK                              0x0000003Fu                   /**< Mask for RegRfBgOwVal */

#define  RF_BG_PUP_SHIFT                                    0                             /**< Shift for RfBgPup */
#define  RF_BG_PUP_MASK                                     0x00000001u                   /**< Mask for RfBgPup */
#define  RF_BG_PUP_BMASK                                    0x1u                          /**< Base mask for RfBgPup */
#define  RF_BG_PUP(x)                                       (((x)&0x1u)<<0)               /**< Set RfBgPup in register */
#define  GET_RF_BG_PUP(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfBgPup from register */
#define  RF_BG_FC_SHIFT                                     1                             /**< Shift for RfBgFc */
#define  RF_BG_FC_MASK                                      0x00000002u                   /**< Mask for RfBgFc */
#define  RF_BG_FC_BMASK                                     0x1u                          /**< Base mask for RfBgFc */
#define  RF_BG_FC(x)                                        (((x)&0x1u)<<1)               /**< Set RfBgFc in register */
#define  GET_RF_BG_FC(reg)                                  (((reg)>>1)&0x1u)             /**< Get RfBgFc from register */
#define  RF_BG_PUP_IBG_TX_SHIFT                             2                             /**< Shift for RfBgPupIbgTx */
#define  RF_BG_PUP_IBG_TX_MASK                              0x00000004u                   /**< Mask for RfBgPupIbgTx */
#define  RF_BG_PUP_IBG_TX_BMASK                             0x1u                          /**< Base mask for RfBgPupIbgTx */
#define  RF_BG_PUP_IBG_TX(x)                                (((x)&0x1u)<<2)               /**< Set RfBgPupIbgTx in register */
#define  GET_RF_BG_PUP_IBG_TX(reg)                          (((reg)>>2)&0x1u)             /**< Get RfBgPupIbgTx from register */
#define  RF_BG_PUP_IBG_RX_SHIFT                             3                             /**< Shift for RfBgPupIbgRx */
#define  RF_BG_PUP_IBG_RX_MASK                              0x00000008u                   /**< Mask for RfBgPupIbgRx */
#define  RF_BG_PUP_IBG_RX_BMASK                             0x1u                          /**< Base mask for RfBgPupIbgRx */
#define  RF_BG_PUP_IBG_RX(x)                                (((x)&0x1u)<<3)               /**< Set RfBgPupIbgRx in register */
#define  GET_RF_BG_PUP_IBG_RX(reg)                          (((reg)>>3)&0x1u)             /**< Get RfBgPupIbgRx from register */
#define  RF_BG_PUP_IBG_CAL_SHIFT                            4                             /**< Shift for RfBgPupIbgCal */
#define  RF_BG_PUP_IBG_CAL_MASK                             0x00000010u                   /**< Mask for RfBgPupIbgCal */
#define  RF_BG_PUP_IBG_CAL_BMASK                            0x1u                          /**< Base mask for RfBgPupIbgCal */
#define  RF_BG_PUP_IBG_CAL(x)                               (((x)&0x1u)<<4)               /**< Set RfBgPupIbgCal in register */
#define  GET_RF_BG_PUP_IBG_CAL(reg)                         (((reg)>>4)&0x1u)             /**< Get RfBgPupIbgCal from register */
#define  RF_BG_PUP_IBG_ANT_SHIFT                            5                             /**< Shift for RfBgPupIbgAnt */
#define  RF_BG_PUP_IBG_ANT_MASK                             0x00000020u                   /**< Mask for RfBgPupIbgAnt */
#define  RF_BG_PUP_IBG_ANT_BMASK                            0x1u                          /**< Base mask for RfBgPupIbgAnt */
#define  RF_BG_PUP_IBG_ANT(x)                               (((x)&0x1u)<<5)               /**< Set RfBgPupIbgAnt in register */
#define  GET_RF_BG_PUP_IBG_ANT(reg)                         (((reg)>>5)&0x1u)             /**< Get RfBgPupIbgAnt from register */
/** @} */


/**
 * @name RegRfLdotrimOwCtrl
 * @{
 */
// RegRfLdotrimOwCtrl.r32
#define  REG_RF_LDOTRIM_OW_CTRL_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfLdotrimOwCtrl */
#define  REG_RF_LDOTRIM_OW_CTRL_MASK                        0x0000003Fu                   /**< Mask for RegRfLdotrimOwCtrl */

#define  RF_LDOTRIM_PUP_OW_SHIFT                            0                             /**< Shift for RfLdotrimPupOw */
#define  RF_LDOTRIM_PUP_OW_MASK                             0x00000001u                   /**< Mask for RfLdotrimPupOw */
#define  RF_LDOTRIM_PUP_OW_BMASK                            0x1u                          /**< Base mask for RfLdotrimPupOw */
#define  RF_LDOTRIM_PUP_OW(x)                               (((x)&0x1u)<<0)               /**< Set RfLdotrimPupOw in register */
#define  GET_RF_LDOTRIM_PUP_OW(reg)                         (((reg)>>0)&0x1u)             /**< Get RfLdotrimPupOw from register */
#define  RF_LDOTRIM_SAMPLE_OW_SHIFT                         1                             /**< Shift for RfLdotrimSampleOw */
#define  RF_LDOTRIM_SAMPLE_OW_MASK                          0x00000002u                   /**< Mask for RfLdotrimSampleOw */
#define  RF_LDOTRIM_SAMPLE_OW_BMASK                         0x1u                          /**< Base mask for RfLdotrimSampleOw */
#define  RF_LDOTRIM_SAMPLE_OW(x)                            (((x)&0x1u)<<1)               /**< Set RfLdotrimSampleOw in register */
#define  GET_RF_LDOTRIM_SAMPLE_OW(reg)                      (((reg)>>1)&0x1u)             /**< Get RfLdotrimSampleOw from register */
#define  RF_LDO_CAL_TRIMSEL_OW_SHIFT                        2                             /**< Shift for RfLdoCalTrimselOw */
#define  RF_LDO_CAL_TRIMSEL_OW_MASK                         0x00000004u                   /**< Mask for RfLdoCalTrimselOw */
#define  RF_LDO_CAL_TRIMSEL_OW_BMASK                        0x1u                          /**< Base mask for RfLdoCalTrimselOw */
#define  RF_LDO_CAL_TRIMSEL_OW(x)                           (((x)&0x1u)<<2)               /**< Set RfLdoCalTrimselOw in register */
#define  GET_RF_LDO_CAL_TRIMSEL_OW(reg)                     (((reg)>>2)&0x1u)             /**< Get RfLdoCalTrimselOw from register */
#define  RF_LDO_RXTXHF_TRIMSEL_OW_SHIFT                     3                             /**< Shift for RfLdoRxtxhfTrimselOw */
#define  RF_LDO_RXTXHF_TRIMSEL_OW_MASK                      0x00000008u                   /**< Mask for RfLdoRxtxhfTrimselOw */
#define  RF_LDO_RXTXHF_TRIMSEL_OW_BMASK                     0x1u                          /**< Base mask for RfLdoRxtxhfTrimselOw */
#define  RF_LDO_RXTXHF_TRIMSEL_OW(x)                        (((x)&0x1u)<<3)               /**< Set RfLdoRxtxhfTrimselOw in register */
#define  GET_RF_LDO_RXTXHF_TRIMSEL_OW(reg)                  (((reg)>>3)&0x1u)             /**< Get RfLdoRxtxhfTrimselOw from register */
#define  RF_LDO_PLL_TRIMSEL_OW_SHIFT                        4                             /**< Shift for RfLdoPllTrimselOw */
#define  RF_LDO_PLL_TRIMSEL_OW_MASK                         0x00000010u                   /**< Mask for RfLdoPllTrimselOw */
#define  RF_LDO_PLL_TRIMSEL_OW_BMASK                        0x1u                          /**< Base mask for RfLdoPllTrimselOw */
#define  RF_LDO_PLL_TRIMSEL_OW(x)                           (((x)&0x1u)<<4)               /**< Set RfLdoPllTrimselOw in register */
#define  GET_RF_LDO_PLL_TRIMSEL_OW(reg)                     (((reg)>>4)&0x1u)             /**< Get RfLdoPllTrimselOw from register */
#define  RF_LDO_VCO_TRIMSEL_OW_SHIFT                        5                             /**< Shift for RfLdoVcoTrimselOw */
#define  RF_LDO_VCO_TRIMSEL_OW_MASK                         0x00000020u                   /**< Mask for RfLdoVcoTrimselOw */
#define  RF_LDO_VCO_TRIMSEL_OW_BMASK                        0x1u                          /**< Base mask for RfLdoVcoTrimselOw */
#define  RF_LDO_VCO_TRIMSEL_OW(x)                           (((x)&0x1u)<<5)               /**< Set RfLdoVcoTrimselOw in register */
#define  GET_RF_LDO_VCO_TRIMSEL_OW(reg)                     (((reg)>>5)&0x1u)             /**< Get RfLdoVcoTrimselOw from register */
/** @} */


/**
 * @name RegRfLdotrimOwVal
 * @{
 */
// RegRfLdotrimOwVal.r32
#define  REG_RF_LDOTRIM_OW_VAL_RESET_VALUE                  0x00000000u                   /**< Reset value of RegRfLdotrimOwVal */
#define  REG_RF_LDOTRIM_OW_VAL_MASK                         0x0000003Fu                   /**< Mask for RegRfLdotrimOwVal */

#define  RF_LDOTRIM_PUP_SHIFT                               0                             /**< Shift for RfLdotrimPup */
#define  RF_LDOTRIM_PUP_MASK                                0x00000001u                   /**< Mask for RfLdotrimPup */
#define  RF_LDOTRIM_PUP_BMASK                               0x1u                          /**< Base mask for RfLdotrimPup */
#define  RF_LDOTRIM_PUP(x)                                  (((x)&0x1u)<<0)               /**< Set RfLdotrimPup in register */
#define  GET_RF_LDOTRIM_PUP(reg)                            (((reg)>>0)&0x1u)             /**< Get RfLdotrimPup from register */
#define  RF_LDOTRIM_SAMPLE_SHIFT                            1                             /**< Shift for RfLdotrimSample */
#define  RF_LDOTRIM_SAMPLE_MASK                             0x00000002u                   /**< Mask for RfLdotrimSample */
#define  RF_LDOTRIM_SAMPLE_BMASK                            0x1u                          /**< Base mask for RfLdotrimSample */
#define  RF_LDOTRIM_SAMPLE(x)                               (((x)&0x1u)<<1)               /**< Set RfLdotrimSample in register */
#define  GET_RF_LDOTRIM_SAMPLE(reg)                         (((reg)>>1)&0x1u)             /**< Get RfLdotrimSample from register */
#define  RF_LDO_CAL_TRIMSEL_SHIFT                           2                             /**< Shift for RfLdoCalTrimsel */
#define  RF_LDO_CAL_TRIMSEL_MASK                            0x00000004u                   /**< Mask for RfLdoCalTrimsel */
#define  RF_LDO_CAL_TRIMSEL_BMASK                           0x1u                          /**< Base mask for RfLdoCalTrimsel */
#define  RF_LDO_CAL_TRIMSEL(x)                              (((x)&0x1u)<<2)               /**< Set RfLdoCalTrimsel in register */
#define  GET_RF_LDO_CAL_TRIMSEL(reg)                        (((reg)>>2)&0x1u)             /**< Get RfLdoCalTrimsel from register */
#define  RF_LDO_RXTXHF_TRIMSEL_SHIFT                        3                             /**< Shift for RfLdoRxtxhfTrimsel */
#define  RF_LDO_RXTXHF_TRIMSEL_MASK                         0x00000008u                   /**< Mask for RfLdoRxtxhfTrimsel */
#define  RF_LDO_RXTXHF_TRIMSEL_BMASK                        0x1u                          /**< Base mask for RfLdoRxtxhfTrimsel */
#define  RF_LDO_RXTXHF_TRIMSEL(x)                           (((x)&0x1u)<<3)               /**< Set RfLdoRxtxhfTrimsel in register */
#define  GET_RF_LDO_RXTXHF_TRIMSEL(reg)                     (((reg)>>3)&0x1u)             /**< Get RfLdoRxtxhfTrimsel from register */
#define  RF_LDO_PLL_TRIMSEL_SHIFT                           4                             /**< Shift for RfLdoPllTrimsel */
#define  RF_LDO_PLL_TRIMSEL_MASK                            0x00000010u                   /**< Mask for RfLdoPllTrimsel */
#define  RF_LDO_PLL_TRIMSEL_BMASK                           0x1u                          /**< Base mask for RfLdoPllTrimsel */
#define  RF_LDO_PLL_TRIMSEL(x)                              (((x)&0x1u)<<4)               /**< Set RfLdoPllTrimsel in register */
#define  GET_RF_LDO_PLL_TRIMSEL(reg)                        (((reg)>>4)&0x1u)             /**< Get RfLdoPllTrimsel from register */
#define  RF_LDO_VCO_TRIMSEL_SHIFT                           5                             /**< Shift for RfLdoVcoTrimsel */
#define  RF_LDO_VCO_TRIMSEL_MASK                            0x00000020u                   /**< Mask for RfLdoVcoTrimsel */
#define  RF_LDO_VCO_TRIMSEL_BMASK                           0x1u                          /**< Base mask for RfLdoVcoTrimsel */
#define  RF_LDO_VCO_TRIMSEL(x)                              (((x)&0x1u)<<5)               /**< Set RfLdoVcoTrimsel in register */
#define  GET_RF_LDO_VCO_TRIMSEL(reg)                        (((reg)>>5)&0x1u)             /**< Get RfLdoVcoTrimsel from register */
/** @} */


/**
 * @name RegRfRccalOwCtrlVal
 * @{
 */
// RegRfRccalOwCtrlVal.r32
#define  REG_RF_RCCAL_OW_CTRL_VAL_RESET_VALUE               0x00000000u                   /**< Reset value of RegRfRccalOwCtrlVal */
#define  REG_RF_RCCAL_OW_CTRL_VAL_MASK                      0x000000FFu                   /**< Mask for RegRfRccalOwCtrlVal */

#define  RF_RCCAL_PUP_OW_SHIFT                              0                             /**< Shift for RfRccalPupOw */
#define  RF_RCCAL_PUP_OW_MASK                               0x00000001u                   /**< Mask for RfRccalPupOw */
#define  RF_RCCAL_PUP_OW_BMASK                              0x1u                          /**< Base mask for RfRccalPupOw */
#define  RF_RCCAL_PUP_OW(x)                                 (((x)&0x1u)<<0)               /**< Set RfRccalPupOw in register */
#define  GET_RF_RCCAL_PUP_OW(reg)                           (((reg)>>0)&0x1u)             /**< Get RfRccalPupOw from register */
#define  RF_RCCAL_CHARGE_OW_SHIFT                           1                             /**< Shift for RfRccalChargeOw */
#define  RF_RCCAL_CHARGE_OW_MASK                            0x00000002u                   /**< Mask for RfRccalChargeOw */
#define  RF_RCCAL_CHARGE_OW_BMASK                           0x1u                          /**< Base mask for RfRccalChargeOw */
#define  RF_RCCAL_CHARGE_OW(x)                              (((x)&0x1u)<<1)               /**< Set RfRccalChargeOw in register */
#define  GET_RF_RCCAL_CHARGE_OW(reg)                        (((reg)>>1)&0x1u)             /**< Get RfRccalChargeOw from register */
#define  RF_RCCAL_DISCHARGE_OW_SHIFT                        2                             /**< Shift for RfRccalDischargeOw */
#define  RF_RCCAL_DISCHARGE_OW_MASK                         0x00000004u                   /**< Mask for RfRccalDischargeOw */
#define  RF_RCCAL_DISCHARGE_OW_BMASK                        0x1u                          /**< Base mask for RfRccalDischargeOw */
#define  RF_RCCAL_DISCHARGE_OW(x)                           (((x)&0x1u)<<2)               /**< Set RfRccalDischargeOw in register */
#define  GET_RF_RCCAL_DISCHARGE_OW(reg)                     (((reg)>>2)&0x1u)             /**< Get RfRccalDischargeOw from register */
#define  RF_RCCAL_SAMPLE_OW_SHIFT                           3                             /**< Shift for RfRccalSampleOw */
#define  RF_RCCAL_SAMPLE_OW_MASK                            0x00000008u                   /**< Mask for RfRccalSampleOw */
#define  RF_RCCAL_SAMPLE_OW_BMASK                           0x1u                          /**< Base mask for RfRccalSampleOw */
#define  RF_RCCAL_SAMPLE_OW(x)                              (((x)&0x1u)<<3)               /**< Set RfRccalSampleOw in register */
#define  GET_RF_RCCAL_SAMPLE_OW(reg)                        (((reg)>>3)&0x1u)             /**< Get RfRccalSampleOw from register */
#define  RF_RCCAL_PUP_SHIFT                                 4                             /**< Shift for RfRccalPup */
#define  RF_RCCAL_PUP_MASK                                  0x00000010u                   /**< Mask for RfRccalPup */
#define  RF_RCCAL_PUP_BMASK                                 0x1u                          /**< Base mask for RfRccalPup */
#define  RF_RCCAL_PUP(x)                                    (((x)&0x1u)<<4)               /**< Set RfRccalPup in register */
#define  GET_RF_RCCAL_PUP(reg)                              (((reg)>>4)&0x1u)             /**< Get RfRccalPup from register */
#define  RF_RCCAL_CHARGE_SHIFT                              5                             /**< Shift for RfRccalCharge */
#define  RF_RCCAL_CHARGE_MASK                               0x00000020u                   /**< Mask for RfRccalCharge */
#define  RF_RCCAL_CHARGE_BMASK                              0x1u                          /**< Base mask for RfRccalCharge */
#define  RF_RCCAL_CHARGE(x)                                 (((x)&0x1u)<<5)               /**< Set RfRccalCharge in register */
#define  GET_RF_RCCAL_CHARGE(reg)                           (((reg)>>5)&0x1u)             /**< Get RfRccalCharge from register */
#define  RF_RCCAL_DISCHARGE_SHIFT                           6                             /**< Shift for RfRccalDischarge */
#define  RF_RCCAL_DISCHARGE_MASK                            0x00000040u                   /**< Mask for RfRccalDischarge */
#define  RF_RCCAL_DISCHARGE_BMASK                           0x1u                          /**< Base mask for RfRccalDischarge */
#define  RF_RCCAL_DISCHARGE(x)                              (((x)&0x1u)<<6)               /**< Set RfRccalDischarge in register */
#define  GET_RF_RCCAL_DISCHARGE(reg)                        (((reg)>>6)&0x1u)             /**< Get RfRccalDischarge from register */
#define  RF_RCCAL_SAMPLE_SHIFT                              7                             /**< Shift for RfRccalSample */
#define  RF_RCCAL_SAMPLE_MASK                               0x00000080u                   /**< Mask for RfRccalSample */
#define  RF_RCCAL_SAMPLE_BMASK                              0x1u                          /**< Base mask for RfRccalSample */
#define  RF_RCCAL_SAMPLE(x)                                 (((x)&0x1u)<<7)               /**< Set RfRccalSample in register */
#define  GET_RF_RCCAL_SAMPLE(reg)                           (((reg)>>7)&0x1u)             /**< Get RfRccalSample from register */
/** @} */


/**
 * @name RegRfXoOwCtrlVal
 * @{
 */
// RegRfXoOwCtrlVal.r32
#define  REG_RF_XO_OW_CTRL_VAL_RESET_VALUE                  0x00000000u                   /**< Reset value of RegRfXoOwCtrlVal */
#define  REG_RF_XO_OW_CTRL_VAL_MASK                         0x0000000Fu                   /**< Mask for RegRfXoOwCtrlVal */

#define  RF_XO_EN_CLK_ADCDAC_OW_SHIFT                       0                             /**< Shift for RfXoEnClkAdcdacOw */
#define  RF_XO_EN_CLK_ADCDAC_OW_MASK                        0x00000001u                   /**< Mask for RfXoEnClkAdcdacOw */
#define  RF_XO_EN_CLK_ADCDAC_OW_BMASK                       0x1u                          /**< Base mask for RfXoEnClkAdcdacOw */
#define  RF_XO_EN_CLK_ADCDAC_OW(x)                          (((x)&0x1u)<<0)               /**< Set RfXoEnClkAdcdacOw in register */
#define  GET_RF_XO_EN_CLK_ADCDAC_OW(reg)                    (((reg)>>0)&0x1u)             /**< Get RfXoEnClkAdcdacOw from register */
#define  RF_XO_EN_CLK_REF_OW_SHIFT                          1                             /**< Shift for RfXoEnClkRefOw */
#define  RF_XO_EN_CLK_REF_OW_MASK                           0x00000002u                   /**< Mask for RfXoEnClkRefOw */
#define  RF_XO_EN_CLK_REF_OW_BMASK                          0x1u                          /**< Base mask for RfXoEnClkRefOw */
#define  RF_XO_EN_CLK_REF_OW(x)                             (((x)&0x1u)<<1)               /**< Set RfXoEnClkRefOw in register */
#define  GET_RF_XO_EN_CLK_REF_OW(reg)                       (((reg)>>1)&0x1u)             /**< Get RfXoEnClkRefOw from register */
#define  RF_XO_EN_CLK_ADCDAC_SHIFT                          2                             /**< Shift for RfXoEnClkAdcdac */
#define  RF_XO_EN_CLK_ADCDAC_MASK                           0x00000004u                   /**< Mask for RfXoEnClkAdcdac */
#define  RF_XO_EN_CLK_ADCDAC_BMASK                          0x1u                          /**< Base mask for RfXoEnClkAdcdac */
#define  RF_XO_EN_CLK_ADCDAC(x)                             (((x)&0x1u)<<2)               /**< Set RfXoEnClkAdcdac in register */
#define  GET_RF_XO_EN_CLK_ADCDAC(reg)                       (((reg)>>2)&0x1u)             /**< Get RfXoEnClkAdcdac from register */
#define  RF_XO_EN_CLK_REF_SHIFT                             3                             /**< Shift for RfXoEnClkRef */
#define  RF_XO_EN_CLK_REF_MASK                              0x00000008u                   /**< Mask for RfXoEnClkRef */
#define  RF_XO_EN_CLK_REF_BMASK                             0x1u                          /**< Base mask for RfXoEnClkRef */
#define  RF_XO_EN_CLK_REF(x)                                (((x)&0x1u)<<3)               /**< Set RfXoEnClkRef in register */
#define  GET_RF_XO_EN_CLK_REF(reg)                          (((reg)>>3)&0x1u)             /**< Get RfXoEnClkRef from register */
/** @} */


/**
 * @name RegRfLnmPaOwCtrlVal
 * @{
 */
// RegRfLnmPaOwCtrlVal.r32
#define  REG_RF_LNM_PA_OW_CTRL_VAL_RESET_VALUE              0x00000000u                   /**< Reset value of RegRfLnmPaOwCtrlVal */
#define  REG_RF_LNM_PA_OW_CTRL_VAL_MASK                     0x0000007Fu                   /**< Mask for RegRfLnmPaOwCtrlVal */

#define  RF_RX_LNA_PUP_OW_SHIFT                             0                             /**< Shift for RfRxLnaPupOw */
#define  RF_RX_LNA_PUP_OW_MASK                              0x00000001u                   /**< Mask for RfRxLnaPupOw */
#define  RF_RX_LNA_PUP_OW_BMASK                             0x1u                          /**< Base mask for RfRxLnaPupOw */
#define  RF_RX_LNA_PUP_OW(x)                                (((x)&0x1u)<<0)               /**< Set RfRxLnaPupOw in register */
#define  GET_RF_RX_LNA_PUP_OW(reg)                          (((reg)>>0)&0x1u)             /**< Get RfRxLnaPupOw from register */
#define  RF_RX_LNA_HGAIN_OW_SHIFT                           1                             /**< Shift for RfRxLnaHgainOw */
#define  RF_RX_LNA_HGAIN_OW_MASK                            0x00000002u                   /**< Mask for RfRxLnaHgainOw */
#define  RF_RX_LNA_HGAIN_OW_BMASK                           0x1u                          /**< Base mask for RfRxLnaHgainOw */
#define  RF_RX_LNA_HGAIN_OW(x)                              (((x)&0x1u)<<1)               /**< Set RfRxLnaHgainOw in register */
#define  GET_RF_RX_LNA_HGAIN_OW(reg)                        (((reg)>>1)&0x1u)             /**< Get RfRxLnaHgainOw from register */
#define  RF_RX_LNA_LGAIN_OW_SHIFT                           2                             /**< Shift for RfRxLnaLgainOw */
#define  RF_RX_LNA_LGAIN_OW_MASK                            0x00000004u                   /**< Mask for RfRxLnaLgainOw */
#define  RF_RX_LNA_LGAIN_OW_BMASK                           0x1u                          /**< Base mask for RfRxLnaLgainOw */
#define  RF_RX_LNA_LGAIN_OW(x)                              (((x)&0x1u)<<2)               /**< Set RfRxLnaLgainOw in register */
#define  GET_RF_RX_LNA_LGAIN_OW(reg)                        (((reg)>>2)&0x1u)             /**< Get RfRxLnaLgainOw from register */
#define  RF_RX_LNA_ATTN_OW_SHIFT                            3                             /**< Shift for RfRxLnaAttnOw */
#define  RF_RX_LNA_ATTN_OW_MASK                             0x00000008u                   /**< Mask for RfRxLnaAttnOw */
#define  RF_RX_LNA_ATTN_OW_BMASK                            0x1u                          /**< Base mask for RfRxLnaAttnOw */
#define  RF_RX_LNA_ATTN_OW(x)                               (((x)&0x1u)<<3)               /**< Set RfRxLnaAttnOw in register */
#define  GET_RF_RX_LNA_ATTN_OW(reg)                         (((reg)>>3)&0x1u)             /**< Get RfRxLnaAttnOw from register */
#define  RF_RX_MIX_PUP_OW_SHIFT                             4                             /**< Shift for RfRxMixPupOw */
#define  RF_RX_MIX_PUP_OW_MASK                              0x00000010u                   /**< Mask for RfRxMixPupOw */
#define  RF_RX_MIX_PUP_OW_BMASK                             0x1u                          /**< Base mask for RfRxMixPupOw */
#define  RF_RX_MIX_PUP_OW(x)                                (((x)&0x1u)<<4)               /**< Set RfRxMixPupOw in register */
#define  GET_RF_RX_MIX_PUP_OW(reg)                          (((reg)>>4)&0x1u)             /**< Get RfRxMixPupOw from register */
#define  RF_TX_PA_PUP_OW_SHIFT                              5                             /**< Shift for RfTxPaPupOw */
#define  RF_TX_PA_PUP_OW_MASK                               0x00000020u                   /**< Mask for RfTxPaPupOw */
#define  RF_TX_PA_PUP_OW_BMASK                              0x1u                          /**< Base mask for RfTxPaPupOw */
#define  RF_TX_PA_PUP_OW(x)                                 (((x)&0x1u)<<5)               /**< Set RfTxPaPupOw in register */
#define  GET_RF_TX_PA_PUP_OW(reg)                           (((reg)>>5)&0x1u)             /**< Get RfTxPaPupOw from register */
#define  RF_TX_PA_PWR_OW_SHIFT                              6                             /**< Shift for RfTxPaPwrOw */
#define  RF_TX_PA_PWR_OW_MASK                               0x00000040u                   /**< Mask for RfTxPaPwrOw */
#define  RF_TX_PA_PWR_OW_BMASK                              0x1u                          /**< Base mask for RfTxPaPwrOw */
#define  RF_TX_PA_PWR_OW(x)                                 (((x)&0x1u)<<6)               /**< Set RfTxPaPwrOw in register */
#define  GET_RF_TX_PA_PWR_OW(reg)                           (((reg)>>6)&0x1u)             /**< Get RfTxPaPwrOw from register */
/** @} */


/**
 * @name RegRfLnmOwVal
 * @{
 */
// RegRfLnmOwVal.r32
#define  REG_RF_LNM_OW_VAL_RESET_VALUE                      0x0000007Eu                   /**< Reset value of RegRfLnmOwVal */
#define  REG_RF_LNM_OW_VAL_MASK                             0x00000FFFu                   /**< Mask for RegRfLnmOwVal */

#define  RF_RX_LNA_PUP_SHIFT                                0                             /**< Shift for RfRxLnaPup */
#define  RF_RX_LNA_PUP_MASK                                 0x00000001u                   /**< Mask for RfRxLnaPup */
#define  RF_RX_LNA_PUP_BMASK                                0x1u                          /**< Base mask for RfRxLnaPup */
#define  RF_RX_LNA_PUP(x)                                   (((x)&0x1u)<<0)               /**< Set RfRxLnaPup in register */
#define  GET_RF_RX_LNA_PUP(reg)                             (((reg)>>0)&0x1u)             /**< Get RfRxLnaPup from register */
#define  RF_RX_LNA_HGAIN_SHIFT                              1                             /**< Shift for RfRxLnaHgain */
#define  RF_RX_LNA_HGAIN_MASK                               0x0000007Eu                   /**< Mask for RfRxLnaHgain */
#define  RF_RX_LNA_HGAIN_BMASK                              0x3Fu                         /**< Base mask for RfRxLnaHgain */
#define  RF_RX_LNA_HGAIN(x)                                 (((x)&0x3Fu)<<1)              /**< Set RfRxLnaHgain in register */
#define  GET_RF_RX_LNA_HGAIN(reg)                           (((reg)>>1)&0x3Fu)            /**< Get RfRxLnaHgain from register */
#define  RF_RX_LNA_LGAIN_SHIFT                              7                             /**< Shift for RfRxLnaLgain */
#define  RF_RX_LNA_LGAIN_MASK                               0x00000180u                   /**< Mask for RfRxLnaLgain */
#define  RF_RX_LNA_LGAIN_BMASK                              0x3u                          /**< Base mask for RfRxLnaLgain */
#define  RF_RX_LNA_LGAIN(x)                                 (((x)&0x3u)<<7)               /**< Set RfRxLnaLgain in register */
#define  GET_RF_RX_LNA_LGAIN(reg)                           (((reg)>>7)&0x3u)             /**< Get RfRxLnaLgain from register */
#define  RF_RX_LNA_ATTN_SHIFT                               9                             /**< Shift for RfRxLnaAttn */
#define  RF_RX_LNA_ATTN_MASK                                0x00000600u                   /**< Mask for RfRxLnaAttn */
#define  RF_RX_LNA_ATTN_BMASK                               0x3u                          /**< Base mask for RfRxLnaAttn */
#define  RF_RX_LNA_ATTN(x)                                  (((x)&0x3u)<<9)               /**< Set RfRxLnaAttn in register */
#define  GET_RF_RX_LNA_ATTN(reg)                            (((reg)>>9)&0x3u)             /**< Get RfRxLnaAttn from register */
#define  RF_RX_MIX_PUP_SHIFT                                11                            /**< Shift for RfRxMixPup */
#define  RF_RX_MIX_PUP_MASK                                 0x00000800u                   /**< Mask for RfRxMixPup */
#define  RF_RX_MIX_PUP_BMASK                                0x1u                          /**< Base mask for RfRxMixPup */
#define  RF_RX_MIX_PUP(x)                                   (((x)&0x1u)<<11)              /**< Set RfRxMixPup in register */
#define  GET_RF_RX_MIX_PUP(reg)                             (((reg)>>11)&0x1u)            /**< Get RfRxMixPup from register */
/** @} */


/**
 * @name RegRfPaOwVal
 * @{
 */
// RegRfPaOwVal.r32
#define  REG_RF_PA_OW_VAL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfPaOwVal */
#define  REG_RF_PA_OW_VAL_MASK                              0x0000007Fu                   /**< Mask for RegRfPaOwVal */

#define  RF_TX_PA_PUP_SHIFT                                 0                             /**< Shift for RfTxPaPup */
#define  RF_TX_PA_PUP_MASK                                  0x00000001u                   /**< Mask for RfTxPaPup */
#define  RF_TX_PA_PUP_BMASK                                 0x1u                          /**< Base mask for RfTxPaPup */
#define  RF_TX_PA_PUP(x)                                    (((x)&0x1u)<<0)               /**< Set RfTxPaPup in register */
#define  GET_RF_TX_PA_PUP(reg)                              (((reg)>>0)&0x1u)             /**< Get RfTxPaPup from register */
#define  RF_TX_PA_PWR_DUPLICITE_SHIFT                       1                             /**< Shift for RfTxPaPwrDuplicite */
#define  RF_TX_PA_PWR_DUPLICITE_MASK                        0x0000007Eu                   /**< Mask for RfTxPaPwrDuplicite */
#define  RF_TX_PA_PWR_DUPLICITE_BMASK                       0x3Fu                         /**< Base mask for RfTxPaPwrDuplicite */
#define  RF_TX_PA_PWR_DUPLICITE(x)                          (((x)&0x3Fu)<<1)              /**< Set RfTxPaPwrDuplicite in register */
#define  GET_RF_TX_PA_PWR_DUPLICITE(reg)                    (((reg)>>1)&0x3Fu)            /**< Get RfTxPaPwrDuplicite from register */
/** @} */


/**
 * @name RegRfCbpfAdcOwCtrl
 * @{
 */
// RegRfCbpfAdcOwCtrl.r32
#define  REG_RF_CBPF_ADC_OW_CTRL_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfCbpfAdcOwCtrl */
#define  REG_RF_CBPF_ADC_OW_CTRL_MASK                       0x0000003Fu                   /**< Mask for RegRfCbpfAdcOwCtrl */

#define  RF_CBPF_PUP_OW_SHIFT                               0                             /**< Shift for RfCbpfPupOw */
#define  RF_CBPF_PUP_OW_MASK                                0x00000001u                   /**< Mask for RfCbpfPupOw */
#define  RF_CBPF_PUP_OW_BMASK                               0x1u                          /**< Base mask for RfCbpfPupOw */
#define  RF_CBPF_PUP_OW(x)                                  (((x)&0x1u)<<0)               /**< Set RfCbpfPupOw in register */
#define  GET_RF_CBPF_PUP_OW(reg)                            (((reg)>>0)&0x1u)             /**< Get RfCbpfPupOw from register */
#define  RF_CBPF_GAIN_OW_SHIFT                              1                             /**< Shift for RfCbpfGainOw */
#define  RF_CBPF_GAIN_OW_MASK                               0x00000002u                   /**< Mask for RfCbpfGainOw */
#define  RF_CBPF_GAIN_OW_BMASK                              0x1u                          /**< Base mask for RfCbpfGainOw */
#define  RF_CBPF_GAIN_OW(x)                                 (((x)&0x1u)<<1)               /**< Set RfCbpfGainOw in register */
#define  GET_RF_CBPF_GAIN_OW(reg)                           (((reg)>>1)&0x1u)             /**< Get RfCbpfGainOw from register */
#define  RF_CBPF_HIZ_OW_SHIFT                               2                             /**< Shift for RfCbpfHizOw */
#define  RF_CBPF_HIZ_OW_MASK                                0x00000004u                   /**< Mask for RfCbpfHizOw */
#define  RF_CBPF_HIZ_OW_BMASK                               0x1u                          /**< Base mask for RfCbpfHizOw */
#define  RF_CBPF_HIZ_OW(x)                                  (((x)&0x1u)<<2)               /**< Set RfCbpfHizOw in register */
#define  GET_RF_CBPF_HIZ_OW(reg)                            (((reg)>>2)&0x1u)             /**< Get RfCbpfHizOw from register */
#define  RF_CBPF_SHORT_OW_SHIFT                             3                             /**< Shift for RfCbpfShortOw */
#define  RF_CBPF_SHORT_OW_MASK                              0x00000008u                   /**< Mask for RfCbpfShortOw */
#define  RF_CBPF_SHORT_OW_BMASK                             0x1u                          /**< Base mask for RfCbpfShortOw */
#define  RF_CBPF_SHORT_OW(x)                                (((x)&0x1u)<<3)               /**< Set RfCbpfShortOw in register */
#define  GET_RF_CBPF_SHORT_OW(reg)                          (((reg)>>3)&0x1u)             /**< Get RfCbpfShortOw from register */
#define  RF_CBPF_EN_DCOC_OW_SHIFT                           4                             /**< Shift for RfCbpfEnDcocOw */
#define  RF_CBPF_EN_DCOC_OW_MASK                            0x00000010u                   /**< Mask for RfCbpfEnDcocOw */
#define  RF_CBPF_EN_DCOC_OW_BMASK                           0x1u                          /**< Base mask for RfCbpfEnDcocOw */
#define  RF_CBPF_EN_DCOC_OW(x)                              (((x)&0x1u)<<4)               /**< Set RfCbpfEnDcocOw in register */
#define  GET_RF_CBPF_EN_DCOC_OW(reg)                        (((reg)>>4)&0x1u)             /**< Get RfCbpfEnDcocOw from register */
#define  RF_ADC_PUP_OW_SHIFT                                5                             /**< Shift for RfAdcPupOw */
#define  RF_ADC_PUP_OW_MASK                                 0x00000020u                   /**< Mask for RfAdcPupOw */
#define  RF_ADC_PUP_OW_BMASK                                0x1u                          /**< Base mask for RfAdcPupOw */
#define  RF_ADC_PUP_OW(x)                                   (((x)&0x1u)<<5)               /**< Set RfAdcPupOw in register */
#define  GET_RF_ADC_PUP_OW(reg)                             (((reg)>>5)&0x1u)             /**< Get RfAdcPupOw from register */
/** @} */


/**
 * @name RegRfCbpfAdcOwVal
 * @{
 */
// RegRfCbpfAdcOwVal.r32
#define  REG_RF_CBPF_ADC_OW_VAL_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfCbpfAdcOwVal */
#define  REG_RF_CBPF_ADC_OW_VAL_MASK                        0x0000003Fu                   /**< Mask for RegRfCbpfAdcOwVal */

#define  RF_CBPF_PUP_SHIFT                                  0                             /**< Shift for RfCbpfPup */
#define  RF_CBPF_PUP_MASK                                   0x00000001u                   /**< Mask for RfCbpfPup */
#define  RF_CBPF_PUP_BMASK                                  0x1u                          /**< Base mask for RfCbpfPup */
#define  RF_CBPF_PUP(x)                                     (((x)&0x1u)<<0)               /**< Set RfCbpfPup in register */
#define  GET_RF_CBPF_PUP(reg)                               (((reg)>>0)&0x1u)             /**< Get RfCbpfPup from register */
#define  RF_CBPF_GAIN_DUPLICITE_SHIFT                       1                             /**< Shift for RfCbpfGainDuplicite */
#define  RF_CBPF_GAIN_DUPLICITE_MASK                        0x00000002u                   /**< Mask for RfCbpfGainDuplicite */
#define  RF_CBPF_GAIN_DUPLICITE_BMASK                       0x1u                          /**< Base mask for RfCbpfGainDuplicite */
#define  RF_CBPF_GAIN_DUPLICITE(x)                          (((x)&0x1u)<<1)               /**< Set RfCbpfGainDuplicite in register */
#define  GET_RF_CBPF_GAIN_DUPLICITE(reg)                    (((reg)>>1)&0x1u)             /**< Get RfCbpfGainDuplicite from register */
#define  RF_CBPF_HIZ_SHIFT                                  2                             /**< Shift for RfCbpfHiz */
#define  RF_CBPF_HIZ_MASK                                   0x00000004u                   /**< Mask for RfCbpfHiz */
#define  RF_CBPF_HIZ_BMASK                                  0x1u                          /**< Base mask for RfCbpfHiz */
#define  RF_CBPF_HIZ(x)                                     (((x)&0x1u)<<2)               /**< Set RfCbpfHiz in register */
#define  GET_RF_CBPF_HIZ(reg)                               (((reg)>>2)&0x1u)             /**< Get RfCbpfHiz from register */
#define  RF_CBPF_SHORT_SHIFT                                3                             /**< Shift for RfCbpfShort */
#define  RF_CBPF_SHORT_MASK                                 0x00000008u                   /**< Mask for RfCbpfShort */
#define  RF_CBPF_SHORT_BMASK                                0x1u                          /**< Base mask for RfCbpfShort */
#define  RF_CBPF_SHORT(x)                                   (((x)&0x1u)<<3)               /**< Set RfCbpfShort in register */
#define  GET_RF_CBPF_SHORT(reg)                             (((reg)>>3)&0x1u)             /**< Get RfCbpfShort from register */
#define  RF_CBPF_EN_DCOC_SHIFT                              4                             /**< Shift for RfCbpfEnDcoc */
#define  RF_CBPF_EN_DCOC_MASK                               0x00000010u                   /**< Mask for RfCbpfEnDcoc */
#define  RF_CBPF_EN_DCOC_BMASK                              0x1u                          /**< Base mask for RfCbpfEnDcoc */
#define  RF_CBPF_EN_DCOC(x)                                 (((x)&0x1u)<<4)               /**< Set RfCbpfEnDcoc in register */
#define  GET_RF_CBPF_EN_DCOC(reg)                           (((reg)>>4)&0x1u)             /**< Get RfCbpfEnDcoc from register */
#define  RF_ADC_PUP_SHIFT                                   5                             /**< Shift for RfAdcPup */
#define  RF_ADC_PUP_MASK                                    0x00000020u                   /**< Mask for RfAdcPup */
#define  RF_ADC_PUP_BMASK                                   0x1u                          /**< Base mask for RfAdcPup */
#define  RF_ADC_PUP(x)                                      (((x)&0x1u)<<5)               /**< Set RfAdcPup in register */
#define  GET_RF_ADC_PUP(reg)                                (((reg)>>5)&0x1u)             /**< Get RfAdcPup from register */
/** @} */


/**
 * @name RegRfPdDivnFcalOwCtrl
 * @{
 */
// RegRfPdDivnFcalOwCtrl.r32
#define  REG_RF_PD_DIVN_FCAL_OW_CTRL_RESET_VALUE            0x00000000u                   /**< Reset value of RegRfPdDivnFcalOwCtrl */
#define  REG_RF_PD_DIVN_FCAL_OW_CTRL_MASK                   0x000000FFu                   /**< Mask for RegRfPdDivnFcalOwCtrl */

#define  RF_PD_PUP_OW_SHIFT                                 0                             /**< Shift for RfPdPupOw */
#define  RF_PD_PUP_OW_MASK                                  0x00000001u                   /**< Mask for RfPdPupOw */
#define  RF_PD_PUP_OW_BMASK                                 0x1u                          /**< Base mask for RfPdPupOw */
#define  RF_PD_PUP_OW(x)                                    (((x)&0x1u)<<0)               /**< Set RfPdPupOw in register */
#define  GET_RF_PD_PUP_OW(reg)                              (((reg)>>0)&0x1u)             /**< Get RfPdPupOw from register */
#define  RF_PD_EN_PD_DRV_OW_SHIFT                           1                             /**< Shift for RfPdEnPdDrvOw */
#define  RF_PD_EN_PD_DRV_OW_MASK                            0x00000002u                   /**< Mask for RfPdEnPdDrvOw */
#define  RF_PD_EN_PD_DRV_OW_BMASK                           0x1u                          /**< Base mask for RfPdEnPdDrvOw */
#define  RF_PD_EN_PD_DRV_OW(x)                              (((x)&0x1u)<<1)               /**< Set RfPdEnPdDrvOw in register */
#define  GET_RF_PD_EN_PD_DRV_OW(reg)                        (((reg)>>1)&0x1u)             /**< Get RfPdEnPdDrvOw from register */
#define  RF_PD_EN_FCAL_BIAS_OW_SHIFT                        2                             /**< Shift for RfPdEnFcalBiasOw */
#define  RF_PD_EN_FCAL_BIAS_OW_MASK                         0x00000004u                   /**< Mask for RfPdEnFcalBiasOw */
#define  RF_PD_EN_FCAL_BIAS_OW_BMASK                        0x1u                          /**< Base mask for RfPdEnFcalBiasOw */
#define  RF_PD_EN_FCAL_BIAS_OW(x)                           (((x)&0x1u)<<2)               /**< Set RfPdEnFcalBiasOw in register */
#define  GET_RF_PD_EN_FCAL_BIAS_OW(reg)                     (((reg)>>2)&0x1u)             /**< Get RfPdEnFcalBiasOw from register */
#define  RF_FCAL_PUP_OW_SHIFT                               3                             /**< Shift for RfFcalPupOw */
#define  RF_FCAL_PUP_OW_MASK                                0x00000008u                   /**< Mask for RfFcalPupOw */
#define  RF_FCAL_PUP_OW_BMASK                               0x1u                          /**< Base mask for RfFcalPupOw */
#define  RF_FCAL_PUP_OW(x)                                  (((x)&0x1u)<<3)               /**< Set RfFcalPupOw in register */
#define  GET_RF_FCAL_PUP_OW(reg)                            (((reg)>>3)&0x1u)             /**< Get RfFcalPupOw from register */
#define  RF_FCAL_SET_OW_SHIFT                               4                             /**< Shift for RfFcalSetOw */
#define  RF_FCAL_SET_OW_MASK                                0x00000010u                   /**< Mask for RfFcalSetOw */
#define  RF_FCAL_SET_OW_BMASK                               0x1u                          /**< Base mask for RfFcalSetOw */
#define  RF_FCAL_SET_OW(x)                                  (((x)&0x1u)<<4)               /**< Set RfFcalSetOw in register */
#define  GET_RF_FCAL_SET_OW(reg)                            (((reg)>>4)&0x1u)             /**< Get RfFcalSetOw from register */
#define  RF_FCAL_RUN_OW_SHIFT                               5                             /**< Shift for RfFcalRunOw */
#define  RF_FCAL_RUN_OW_MASK                                0x00000020u                   /**< Mask for RfFcalRunOw */
#define  RF_FCAL_RUN_OW_BMASK                               0x1u                          /**< Base mask for RfFcalRunOw */
#define  RF_FCAL_RUN_OW(x)                                  (((x)&0x1u)<<5)               /**< Set RfFcalRunOw in register */
#define  GET_RF_FCAL_RUN_OW(reg)                            (((reg)>>5)&0x1u)             /**< Get RfFcalRunOw from register */
#define  RF_DIVN_PUP_OW_SHIFT                               6                             /**< Shift for RfDivnPupOw */
#define  RF_DIVN_PUP_OW_MASK                                0x00000040u                   /**< Mask for RfDivnPupOw */
#define  RF_DIVN_PUP_OW_BMASK                               0x1u                          /**< Base mask for RfDivnPupOw */
#define  RF_DIVN_PUP_OW(x)                                  (((x)&0x1u)<<6)               /**< Set RfDivnPupOw in register */
#define  GET_RF_DIVN_PUP_OW(reg)                            (((reg)>>6)&0x1u)             /**< Get RfDivnPupOw from register */
#define  RF_DIVN_OPENLOOP_OW_SHIFT                          7                             /**< Shift for RfDivnOpenloopOw */
#define  RF_DIVN_OPENLOOP_OW_MASK                           0x00000080u                   /**< Mask for RfDivnOpenloopOw */
#define  RF_DIVN_OPENLOOP_OW_BMASK                          0x1u                          /**< Base mask for RfDivnOpenloopOw */
#define  RF_DIVN_OPENLOOP_OW(x)                             (((x)&0x1u)<<7)               /**< Set RfDivnOpenloopOw in register */
#define  GET_RF_DIVN_OPENLOOP_OW(reg)                       (((reg)>>7)&0x1u)             /**< Get RfDivnOpenloopOw from register */
/** @} */


/**
 * @name RegRfPdDivnFcalOwVal
 * @{
 */
// RegRfPdDivnFcalOwVal.r32
#define  REG_RF_PD_DIVN_FCAL_OW_VAL_RESET_VALUE             0x00000000u                   /**< Reset value of RegRfPdDivnFcalOwVal */
#define  REG_RF_PD_DIVN_FCAL_OW_VAL_MASK                    0x000000FFu                   /**< Mask for RegRfPdDivnFcalOwVal */

#define  RF_PD_PUP_SHIFT                                    0                             /**< Shift for RfPdPup */
#define  RF_PD_PUP_MASK                                     0x00000001u                   /**< Mask for RfPdPup */
#define  RF_PD_PUP_BMASK                                    0x1u                          /**< Base mask for RfPdPup */
#define  RF_PD_PUP(x)                                       (((x)&0x1u)<<0)               /**< Set RfPdPup in register */
#define  GET_RF_PD_PUP(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfPdPup from register */
#define  RF_PD_EN_PD_DRV_SHIFT                              1                             /**< Shift for RfPdEnPdDrv */
#define  RF_PD_EN_PD_DRV_MASK                               0x00000002u                   /**< Mask for RfPdEnPdDrv */
#define  RF_PD_EN_PD_DRV_BMASK                              0x1u                          /**< Base mask for RfPdEnPdDrv */
#define  RF_PD_EN_PD_DRV(x)                                 (((x)&0x1u)<<1)               /**< Set RfPdEnPdDrv in register */
#define  GET_RF_PD_EN_PD_DRV(reg)                           (((reg)>>1)&0x1u)             /**< Get RfPdEnPdDrv from register */
#define  RF_PD_EN_FCAL_BIAS_SHIFT                           2                             /**< Shift for RfPdEnFcalBias */
#define  RF_PD_EN_FCAL_BIAS_MASK                            0x00000004u                   /**< Mask for RfPdEnFcalBias */
#define  RF_PD_EN_FCAL_BIAS_BMASK                           0x1u                          /**< Base mask for RfPdEnFcalBias */
#define  RF_PD_EN_FCAL_BIAS(x)                              (((x)&0x1u)<<2)               /**< Set RfPdEnFcalBias in register */
#define  GET_RF_PD_EN_FCAL_BIAS(reg)                        (((reg)>>2)&0x1u)             /**< Get RfPdEnFcalBias from register */
#define  RF_FCAL_PUP_SHIFT                                  3                             /**< Shift for RfFcalPup */
#define  RF_FCAL_PUP_MASK                                   0x00000008u                   /**< Mask for RfFcalPup */
#define  RF_FCAL_PUP_BMASK                                  0x1u                          /**< Base mask for RfFcalPup */
#define  RF_FCAL_PUP(x)                                     (((x)&0x1u)<<3)               /**< Set RfFcalPup in register */
#define  GET_RF_FCAL_PUP(reg)                               (((reg)>>3)&0x1u)             /**< Get RfFcalPup from register */
#define  RF_FCAL_SET_SHIFT                                  4                             /**< Shift for RfFcalSet */
#define  RF_FCAL_SET_MASK                                   0x00000010u                   /**< Mask for RfFcalSet */
#define  RF_FCAL_SET_BMASK                                  0x1u                          /**< Base mask for RfFcalSet */
#define  RF_FCAL_SET(x)                                     (((x)&0x1u)<<4)               /**< Set RfFcalSet in register */
#define  GET_RF_FCAL_SET(reg)                               (((reg)>>4)&0x1u)             /**< Get RfFcalSet from register */
#define  RF_FCAL_RUN_SHIFT                                  5                             /**< Shift for RfFcalRun */
#define  RF_FCAL_RUN_MASK                                   0x00000020u                   /**< Mask for RfFcalRun */
#define  RF_FCAL_RUN_BMASK                                  0x1u                          /**< Base mask for RfFcalRun */
#define  RF_FCAL_RUN(x)                                     (((x)&0x1u)<<5)               /**< Set RfFcalRun in register */
#define  GET_RF_FCAL_RUN(reg)                               (((reg)>>5)&0x1u)             /**< Get RfFcalRun from register */
#define  RF_DIVN_PUP_SHIFT                                  6                             /**< Shift for RfDivnPup */
#define  RF_DIVN_PUP_MASK                                   0x00000040u                   /**< Mask for RfDivnPup */
#define  RF_DIVN_PUP_BMASK                                  0x1u                          /**< Base mask for RfDivnPup */
#define  RF_DIVN_PUP(x)                                     (((x)&0x1u)<<6)               /**< Set RfDivnPup in register */
#define  GET_RF_DIVN_PUP(reg)                               (((reg)>>6)&0x1u)             /**< Get RfDivnPup from register */
#define  RF_DIVN_OPENLOOP_SHIFT                             7                             /**< Shift for RfDivnOpenloop */
#define  RF_DIVN_OPENLOOP_MASK                              0x00000080u                   /**< Mask for RfDivnOpenloop */
#define  RF_DIVN_OPENLOOP_BMASK                             0x1u                          /**< Base mask for RfDivnOpenloop */
#define  RF_DIVN_OPENLOOP(x)                                (((x)&0x1u)<<7)               /**< Set RfDivnOpenloop in register */
#define  GET_RF_DIVN_OPENLOOP(reg)                          (((reg)>>7)&0x1u)             /**< Get RfDivnOpenloop from register */
/** @} */


/**
 * @name RegRfVcoLopathDacOwCtrl
 * @{
 */
// RegRfVcoLopathDacOwCtrl.r32
#define  REG_RF_VCO_LOPATH_DAC_OW_CTRL_RESET_VALUE          0x00000000u                   /**< Reset value of RegRfVcoLopathDacOwCtrl */
#define  REG_RF_VCO_LOPATH_DAC_OW_CTRL_MASK                 0x000000FFu                   /**< Mask for RegRfVcoLopathDacOwCtrl */

#define  RF_VCO_PUP_OW_SHIFT                                0                             /**< Shift for RfVcoPupOw */
#define  RF_VCO_PUP_OW_MASK                                 0x00000001u                   /**< Mask for RfVcoPupOw */
#define  RF_VCO_PUP_OW_BMASK                                0x1u                          /**< Base mask for RfVcoPupOw */
#define  RF_VCO_PUP_OW(x)                                   (((x)&0x1u)<<0)               /**< Set RfVcoPupOw in register */
#define  GET_RF_VCO_PUP_OW(reg)                             (((reg)>>0)&0x1u)             /**< Get RfVcoPupOw from register */
#define  RF_VCO_EN_HPM_OW_SHIFT                             1                             /**< Shift for RfVcoEnHpmOw */
#define  RF_VCO_EN_HPM_OW_MASK                              0x00000002u                   /**< Mask for RfVcoEnHpmOw */
#define  RF_VCO_EN_HPM_OW_BMASK                             0x1u                          /**< Base mask for RfVcoEnHpmOw */
#define  RF_VCO_EN_HPM_OW(x)                                (((x)&0x1u)<<1)               /**< Set RfVcoEnHpmOw in register */
#define  GET_RF_VCO_EN_HPM_OW(reg)                          (((reg)>>1)&0x1u)             /**< Get RfVcoEnHpmOw from register */
#define  RF_LO_PUP_VLO_RX_OW_SHIFT                          2                             /**< Shift for RfLoPupVloRxOw */
#define  RF_LO_PUP_VLO_RX_OW_MASK                           0x00000004u                   /**< Mask for RfLoPupVloRxOw */
#define  RF_LO_PUP_VLO_RX_OW_BMASK                          0x1u                          /**< Base mask for RfLoPupVloRxOw */
#define  RF_LO_PUP_VLO_RX_OW(x)                             (((x)&0x1u)<<2)               /**< Set RfLoPupVloRxOw in register */
#define  GET_RF_LO_PUP_VLO_RX_OW(reg)                       (((reg)>>2)&0x1u)             /**< Get RfLoPupVloRxOw from register */
#define  RF_LO_PUP_VLO_RXDRV_OW_SHIFT                       3                             /**< Shift for RfLoPupVloRxdrvOw */
#define  RF_LO_PUP_VLO_RXDRV_OW_MASK                        0x00000008u                   /**< Mask for RfLoPupVloRxdrvOw */
#define  RF_LO_PUP_VLO_RXDRV_OW_BMASK                       0x1u                          /**< Base mask for RfLoPupVloRxdrvOw */
#define  RF_LO_PUP_VLO_RXDRV_OW(x)                          (((x)&0x1u)<<3)               /**< Set RfLoPupVloRxdrvOw in register */
#define  GET_RF_LO_PUP_VLO_RXDRV_OW(reg)                    (((reg)>>3)&0x1u)             /**< Get RfLoPupVloRxdrvOw from register */
#define  RF_LO_PUP_VLO_TX_OW_SHIFT                          4                             /**< Shift for RfLoPupVloTxOw */
#define  RF_LO_PUP_VLO_TX_OW_MASK                           0x00000010u                   /**< Mask for RfLoPupVloTxOw */
#define  RF_LO_PUP_VLO_TX_OW_BMASK                          0x1u                          /**< Base mask for RfLoPupVloTxOw */
#define  RF_LO_PUP_VLO_TX_OW(x)                             (((x)&0x1u)<<4)               /**< Set RfLoPupVloTxOw in register */
#define  GET_RF_LO_PUP_VLO_TX_OW(reg)                       (((reg)>>4)&0x1u)             /**< Get RfLoPupVloTxOw from register */
#define  RF_LO_PUP_VLO_TXDRV_OW_SHIFT                       5                             /**< Shift for RfLoPupVloTxdrvOw */
#define  RF_LO_PUP_VLO_TXDRV_OW_MASK                        0x00000020u                   /**< Mask for RfLoPupVloTxdrvOw */
#define  RF_LO_PUP_VLO_TXDRV_OW_BMASK                       0x1u                          /**< Base mask for RfLoPupVloTxdrvOw */
#define  RF_LO_PUP_VLO_TXDRV_OW(x)                          (((x)&0x1u)<<5)               /**< Set RfLoPupVloTxdrvOw in register */
#define  GET_RF_LO_PUP_VLO_TXDRV_OW(reg)                    (((reg)>>5)&0x1u)             /**< Get RfLoPupVloTxdrvOw from register */
#define  RF_LO_PUP_VLO_FBK_OW_SHIFT                         6                             /**< Shift for RfLoPupVloFbkOw */
#define  RF_LO_PUP_VLO_FBK_OW_MASK                          0x00000040u                   /**< Mask for RfLoPupVloFbkOw */
#define  RF_LO_PUP_VLO_FBK_OW_BMASK                         0x1u                          /**< Base mask for RfLoPupVloFbkOw */
#define  RF_LO_PUP_VLO_FBK_OW(x)                            (((x)&0x1u)<<6)               /**< Set RfLoPupVloFbkOw in register */
#define  GET_RF_LO_PUP_VLO_FBK_OW(reg)                      (((reg)>>6)&0x1u)             /**< Get RfLoPupVloFbkOw from register */
#define  RF_DAC_PUP_OW_SHIFT                                7                             /**< Shift for RfDacPupOw */
#define  RF_DAC_PUP_OW_MASK                                 0x00000080u                   /**< Mask for RfDacPupOw */
#define  RF_DAC_PUP_OW_BMASK                                0x1u                          /**< Base mask for RfDacPupOw */
#define  RF_DAC_PUP_OW(x)                                   (((x)&0x1u)<<7)               /**< Set RfDacPupOw in register */
#define  GET_RF_DAC_PUP_OW(reg)                             (((reg)>>7)&0x1u)             /**< Get RfDacPupOw from register */
/** @} */


/**
 * @name RegRfVcoLopathDacOwVal
 * @{
 */
// RegRfVcoLopathDacOwVal.r32
#define  REG_RF_VCO_LOPATH_DAC_OW_VAL_RESET_VALUE           0x00000000u                   /**< Reset value of RegRfVcoLopathDacOwVal */
#define  REG_RF_VCO_LOPATH_DAC_OW_VAL_MASK                  0x000000FFu                   /**< Mask for RegRfVcoLopathDacOwVal */

#define  RF_VCO_PUP_SHIFT                                   0                             /**< Shift for RfVcoPup */
#define  RF_VCO_PUP_MASK                                    0x00000001u                   /**< Mask for RfVcoPup */
#define  RF_VCO_PUP_BMASK                                   0x1u                          /**< Base mask for RfVcoPup */
#define  RF_VCO_PUP(x)                                      (((x)&0x1u)<<0)               /**< Set RfVcoPup in register */
#define  GET_RF_VCO_PUP(reg)                                (((reg)>>0)&0x1u)             /**< Get RfVcoPup from register */
#define  RF_VCO_EN_HPM_SHIFT                                1                             /**< Shift for RfVcoEnHpm */
#define  RF_VCO_EN_HPM_MASK                                 0x00000002u                   /**< Mask for RfVcoEnHpm */
#define  RF_VCO_EN_HPM_BMASK                                0x1u                          /**< Base mask for RfVcoEnHpm */
#define  RF_VCO_EN_HPM(x)                                   (((x)&0x1u)<<1)               /**< Set RfVcoEnHpm in register */
#define  GET_RF_VCO_EN_HPM(reg)                             (((reg)>>1)&0x1u)             /**< Get RfVcoEnHpm from register */
#define  RF_LO_PUP_VLO_RX_SHIFT                             2                             /**< Shift for RfLoPupVloRx */
#define  RF_LO_PUP_VLO_RX_MASK                              0x00000004u                   /**< Mask for RfLoPupVloRx */
#define  RF_LO_PUP_VLO_RX_BMASK                             0x1u                          /**< Base mask for RfLoPupVloRx */
#define  RF_LO_PUP_VLO_RX(x)                                (((x)&0x1u)<<2)               /**< Set RfLoPupVloRx in register */
#define  GET_RF_LO_PUP_VLO_RX(reg)                          (((reg)>>2)&0x1u)             /**< Get RfLoPupVloRx from register */
#define  RF_LO_PUP_VLO_RXDRV_SHIFT                          3                             /**< Shift for RfLoPupVloRxdrv */
#define  RF_LO_PUP_VLO_RXDRV_MASK                           0x00000008u                   /**< Mask for RfLoPupVloRxdrv */
#define  RF_LO_PUP_VLO_RXDRV_BMASK                          0x1u                          /**< Base mask for RfLoPupVloRxdrv */
#define  RF_LO_PUP_VLO_RXDRV(x)                             (((x)&0x1u)<<3)               /**< Set RfLoPupVloRxdrv in register */
#define  GET_RF_LO_PUP_VLO_RXDRV(reg)                       (((reg)>>3)&0x1u)             /**< Get RfLoPupVloRxdrv from register */
#define  RF_LO_PUP_VLO_TX_SHIFT                             4                             /**< Shift for RfLoPupVloTx */
#define  RF_LO_PUP_VLO_TX_MASK                              0x00000010u                   /**< Mask for RfLoPupVloTx */
#define  RF_LO_PUP_VLO_TX_BMASK                             0x1u                          /**< Base mask for RfLoPupVloTx */
#define  RF_LO_PUP_VLO_TX(x)                                (((x)&0x1u)<<4)               /**< Set RfLoPupVloTx in register */
#define  GET_RF_LO_PUP_VLO_TX(reg)                          (((reg)>>4)&0x1u)             /**< Get RfLoPupVloTx from register */
#define  RF_LO_PUP_VLO_TXDRV_SHIFT                          5                             /**< Shift for RfLoPupVloTxdrv */
#define  RF_LO_PUP_VLO_TXDRV_MASK                           0x00000020u                   /**< Mask for RfLoPupVloTxdrv */
#define  RF_LO_PUP_VLO_TXDRV_BMASK                          0x1u                          /**< Base mask for RfLoPupVloTxdrv */
#define  RF_LO_PUP_VLO_TXDRV(x)                             (((x)&0x1u)<<5)               /**< Set RfLoPupVloTxdrv in register */
#define  GET_RF_LO_PUP_VLO_TXDRV(reg)                       (((reg)>>5)&0x1u)             /**< Get RfLoPupVloTxdrv from register */
#define  RF_LO_PUP_VLO_FBK_SHIFT                            6                             /**< Shift for RfLoPupVloFbk */
#define  RF_LO_PUP_VLO_FBK_MASK                             0x00000040u                   /**< Mask for RfLoPupVloFbk */
#define  RF_LO_PUP_VLO_FBK_BMASK                            0x1u                          /**< Base mask for RfLoPupVloFbk */
#define  RF_LO_PUP_VLO_FBK(x)                               (((x)&0x1u)<<6)               /**< Set RfLoPupVloFbk in register */
#define  GET_RF_LO_PUP_VLO_FBK(reg)                         (((reg)>>6)&0x1u)             /**< Get RfLoPupVloFbk from register */
#define  RF_DAC_PUP_SHIFT                                   7                             /**< Shift for RfDacPup */
#define  RF_DAC_PUP_MASK                                    0x00000080u                   /**< Mask for RfDacPup */
#define  RF_DAC_PUP_BMASK                                   0x1u                          /**< Base mask for RfDacPup */
#define  RF_DAC_PUP(x)                                      (((x)&0x1u)<<7)               /**< Set RfDacPup in register */
#define  GET_RF_DAC_PUP(reg)                                (((reg)>>7)&0x1u)             /**< Get RfDacPup from register */
/** @} */


/**
 * @name RegRfSeqSparelvOwCtrl
 * @{
 */
// RegRfSeqSparelvOwCtrl.r32
#define  REG_RF_SEQ_SPARELV_OW_CTRL_RESET_VALUE             0x00000000u                   /**< Reset value of RegRfSeqSparelvOwCtrl */
#define  REG_RF_SEQ_SPARELV_OW_CTRL_MASK                    0x0000000Fu                   /**< Mask for RegRfSeqSparelvOwCtrl */

#define  RF_SPARE0_OW_SHIFT                                 0                             /**< Shift for RfSpare0Ow */
#define  RF_SPARE0_OW_MASK                                  0x00000001u                   /**< Mask for RfSpare0Ow */
#define  RF_SPARE0_OW_BMASK                                 0x1u                          /**< Base mask for RfSpare0Ow */
#define  RF_SPARE0_OW(x)                                    (((x)&0x1u)<<0)               /**< Set RfSpare0Ow in register */
#define  GET_RF_SPARE0_OW(reg)                              (((reg)>>0)&0x1u)             /**< Get RfSpare0Ow from register */
#define  RF_SPARE1_OW_SHIFT                                 1                             /**< Shift for RfSpare1Ow */
#define  RF_SPARE1_OW_MASK                                  0x00000002u                   /**< Mask for RfSpare1Ow */
#define  RF_SPARE1_OW_BMASK                                 0x1u                          /**< Base mask for RfSpare1Ow */
#define  RF_SPARE1_OW(x)                                    (((x)&0x1u)<<1)               /**< Set RfSpare1Ow in register */
#define  GET_RF_SPARE1_OW(reg)                              (((reg)>>1)&0x1u)             /**< Get RfSpare1Ow from register */
#define  RF_SPARE2_OW_SHIFT                                 2                             /**< Shift for RfSpare2Ow */
#define  RF_SPARE2_OW_MASK                                  0x00000004u                   /**< Mask for RfSpare2Ow */
#define  RF_SPARE2_OW_BMASK                                 0x1u                          /**< Base mask for RfSpare2Ow */
#define  RF_SPARE2_OW(x)                                    (((x)&0x1u)<<2)               /**< Set RfSpare2Ow in register */
#define  GET_RF_SPARE2_OW(reg)                              (((reg)>>2)&0x1u)             /**< Get RfSpare2Ow from register */
#define  RF_SPARE3_OW_SHIFT                                 3                             /**< Shift for RfSpare3Ow */
#define  RF_SPARE3_OW_MASK                                  0x00000008u                   /**< Mask for RfSpare3Ow */
#define  RF_SPARE3_OW_BMASK                                 0x1u                          /**< Base mask for RfSpare3Ow */
#define  RF_SPARE3_OW(x)                                    (((x)&0x1u)<<3)               /**< Set RfSpare3Ow in register */
#define  GET_RF_SPARE3_OW(reg)                              (((reg)>>3)&0x1u)             /**< Get RfSpare3Ow from register */
/** @} */


/**
 * @name RegRfSeqSparelvOwVal
 * @{
 */
// RegRfSeqSparelvOwVal.r32
#define  REG_RF_SEQ_SPARELV_OW_VAL_RESET_VALUE              0x00000000u                   /**< Reset value of RegRfSeqSparelvOwVal */
#define  REG_RF_SEQ_SPARELV_OW_VAL_MASK                     0x0000000Fu                   /**< Mask for RegRfSeqSparelvOwVal */

#define  RF_SPARE0_SHIFT                                    0                             /**< Shift for RfSpare0 */
#define  RF_SPARE0_MASK                                     0x00000001u                   /**< Mask for RfSpare0 */
#define  RF_SPARE0_BMASK                                    0x1u                          /**< Base mask for RfSpare0 */
#define  RF_SPARE0(x)                                       (((x)&0x1u)<<0)               /**< Set RfSpare0 in register */
#define  GET_RF_SPARE0(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfSpare0 from register */
#define  RF_SPARE1_SHIFT                                    1                             /**< Shift for RfSpare1 */
#define  RF_SPARE1_MASK                                     0x00000002u                   /**< Mask for RfSpare1 */
#define  RF_SPARE1_BMASK                                    0x1u                          /**< Base mask for RfSpare1 */
#define  RF_SPARE1(x)                                       (((x)&0x1u)<<1)               /**< Set RfSpare1 in register */
#define  GET_RF_SPARE1(reg)                                 (((reg)>>1)&0x1u)             /**< Get RfSpare1 from register */
#define  RF_SPARE2_SHIFT                                    2                             /**< Shift for RfSpare2 */
#define  RF_SPARE2_MASK                                     0x00000004u                   /**< Mask for RfSpare2 */
#define  RF_SPARE2_BMASK                                    0x1u                          /**< Base mask for RfSpare2 */
#define  RF_SPARE2(x)                                       (((x)&0x1u)<<2)               /**< Set RfSpare2 in register */
#define  GET_RF_SPARE2(reg)                                 (((reg)>>2)&0x1u)             /**< Get RfSpare2 from register */
#define  RF_SPARE3_SHIFT                                    3                             /**< Shift for RfSpare3 */
#define  RF_SPARE3_MASK                                     0x00000008u                   /**< Mask for RfSpare3 */
#define  RF_SPARE3_BMASK                                    0x1u                          /**< Base mask for RfSpare3 */
#define  RF_SPARE3(x)                                       (((x)&0x1u)<<3)               /**< Set RfSpare3 in register */
#define  GET_RF_SPARE3(reg)                                 (((reg)>>3)&0x1u)             /**< Get RfSpare3 from register */
/** @} */


/**
 * @name RegRfXoSeq
 * @{
 */
// RegRfXoSeq.r32
#define  REG_RF_XO_SEQ_RESET_VALUE                          0x00000000u                   /**< Reset value of RegRfXoSeq */
#define  REG_RF_XO_SEQ_MASK                                 0x0000FFFFu                   /**< Mask for RegRfXoSeq */

#define  RF_XO_LDO_PUP_SHIFT                                0                             /**< Shift for RfXoLdoPup */
#define  RF_XO_LDO_PUP_MASK                                 0x00000001u                   /**< Mask for RfXoLdoPup */
#define  RF_XO_LDO_PUP_BMASK                                0x1u                          /**< Base mask for RfXoLdoPup */
#define  RF_XO_LDO_PUP(x)                                   (((x)&0x1u)<<0)               /**< Set RfXoLdoPup in register */
#define  GET_RF_XO_LDO_PUP(reg)                             (((reg)>>0)&0x1u)             /**< Get RfXoLdoPup from register */
#define  RF_XO_EN_SHIFT                                     1                             /**< Shift for RfXoEn */
#define  RF_XO_EN_MASK                                      0x00000002u                   /**< Mask for RfXoEn */
#define  RF_XO_EN_BMASK                                     0x1u                          /**< Base mask for RfXoEn */
#define  RF_XO_EN(x)                                        (((x)&0x1u)<<1)               /**< Set RfXoEn in register */
#define  GET_RF_XO_EN(reg)                                  (((reg)>>1)&0x1u)             /**< Get RfXoEn from register */
#define  RF_XO_EN_CLK_DIG_SHIFT                             2                             /**< Shift for RfXoEnClkDig */
#define  RF_XO_EN_CLK_DIG_MASK                              0x00000004u                   /**< Mask for RfXoEnClkDig */
#define  RF_XO_EN_CLK_DIG_BMASK                             0x1u                          /**< Base mask for RfXoEnClkDig */
#define  RF_XO_EN_CLK_DIG(x)                                (((x)&0x1u)<<2)               /**< Set RfXoEnClkDig in register */
#define  GET_RF_XO_EN_CLK_DIG(reg)                          (((reg)>>2)&0x1u)             /**< Get RfXoEnClkDig from register */
#define  RF_XO_EN_CLK_AUX_SHIFT                             3                             /**< Shift for RfXoEnClkAux */
#define  RF_XO_EN_CLK_AUX_MASK                              0x00000008u                   /**< Mask for RfXoEnClkAux */
#define  RF_XO_EN_CLK_AUX_BMASK                             0x1u                          /**< Base mask for RfXoEnClkAux */
#define  RF_XO_EN_CLK_AUX(x)                                (((x)&0x1u)<<3)               /**< Set RfXoEnClkAux in register */
#define  GET_RF_XO_EN_CLK_AUX(reg)                          (((reg)>>3)&0x1u)             /**< Get RfXoEnClkAux from register */
#define  RF_XO_MODE_SHIFT                                   4                             /**< Shift for RfXoMode */
#define  RF_XO_MODE_MASK                                    0x00000010u                   /**< Mask for RfXoMode */
#define  RF_XO_MODE_BMASK                                   0x1u                          /**< Base mask for RfXoMode */
#define  RF_XO_MODE(x)                                      (((x)&0x1u)<<4)               /**< Set RfXoMode in register */
#define  GET_RF_XO_MODE(reg)                                (((reg)>>4)&0x1u)             /**< Get RfXoMode from register */
#define  RF_XO_CAP_OFF_SHIFT                                5                             /**< Shift for RfXoCapOff */
#define  RF_XO_CAP_OFF_MASK                                 0x00000020u                   /**< Mask for RfXoCapOff */
#define  RF_XO_CAP_OFF_BMASK                                0x1u                          /**< Base mask for RfXoCapOff */
#define  RF_XO_CAP_OFF(x)                                   (((x)&0x1u)<<5)               /**< Set RfXoCapOff in register */
#define  GET_RF_XO_CAP_OFF(reg)                             (((reg)>>5)&0x1u)             /**< Get RfXoCapOff from register */
#define  RF_XO_ISEL_SHIFT                                   6                             /**< Shift for RfXoIsel */
#define  RF_XO_ISEL_MASK                                    0x000003C0u                   /**< Mask for RfXoIsel */
#define  RF_XO_ISEL_BMASK                                   0xFu                          /**< Base mask for RfXoIsel */
#define  RF_XO_ISEL(x)                                      (((x)&0xFu)<<6)               /**< Set RfXoIsel in register */
#define  GET_RF_XO_ISEL(reg)                                (((reg)>>6)&0xFu)             /**< Get RfXoIsel from register */
#define  RF_XO_CDAC_SHIFT                                   10                            /**< Shift for RfXoCdac */
#define  RF_XO_CDAC_MASK                                    0x0000FC00u                   /**< Mask for RfXoCdac */
#define  RF_XO_CDAC_BMASK                                   0x3Fu                         /**< Base mask for RfXoCdac */
#define  RF_XO_CDAC(x)                                      (((x)&0x3Fu)<<10)             /**< Set RfXoCdac in register */
#define  GET_RF_XO_CDAC(reg)                                (((reg)>>10)&0x3Fu)           /**< Get RfXoCdac from register */
/** @} */


/**
 * @name RegRfXoDebug
 * @{
 */
// RegRfXoDebug.r32
#define  REG_RF_XO_DEBUG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfXoDebug */
#define  REG_RF_XO_DEBUG_MASK                               0x00003FFFu                   /**< Mask for RegRfXoDebug */

#define  RF_XO_DYN_CAP_SHIFT                                0                             /**< Shift for RfXoDynCap */
#define  RF_XO_DYN_CAP_MASK                                 0x00000001u                   /**< Mask for RfXoDynCap */
#define  RF_XO_DYN_CAP_BMASK                                0x1u                          /**< Base mask for RfXoDynCap */
#define  RF_XO_DYN_CAP(x)                                   (((x)&0x1u)<<0)               /**< Set RfXoDynCap in register */
#define  GET_RF_XO_DYN_CAP(reg)                             (((reg)>>0)&0x1u)             /**< Get RfXoDynCap from register */
#define  RF_XO_DYN_ISEL_SHIFT                               1                             /**< Shift for RfXoDynIsel */
#define  RF_XO_DYN_ISEL_MASK                                0x00000002u                   /**< Mask for RfXoDynIsel */
#define  RF_XO_DYN_ISEL_BMASK                               0x1u                          /**< Base mask for RfXoDynIsel */
#define  RF_XO_DYN_ISEL(x)                                  (((x)&0x1u)<<1)               /**< Set RfXoDynIsel in register */
#define  GET_RF_XO_DYN_ISEL(reg)                            (((reg)>>1)&0x1u)             /**< Get RfXoDynIsel from register */
#define  RF_XO_CNT_SHIFT                                    2                             /**< Shift for RfXoCnt */
#define  RF_XO_CNT_MASK                                     0x0000000Cu                   /**< Mask for RfXoCnt */
#define  RF_XO_CNT_BMASK                                    0x3u                          /**< Base mask for RfXoCnt */
#define  RF_XO_CNT(x)                                       (((x)&0x3u)<<2)               /**< Set RfXoCnt in register */
#define  GET_RF_XO_CNT(reg)                                 (((reg)>>2)&0x3u)             /**< Get RfXoCnt from register */
#define  RF_XO_CNT_OFF_SHIFT                                4                             /**< Shift for RfXoCntOff */
#define  RF_XO_CNT_OFF_MASK                                 0x00000010u                   /**< Mask for RfXoCntOff */
#define  RF_XO_CNT_OFF_BMASK                                0x1u                          /**< Base mask for RfXoCntOff */
#define  RF_XO_CNT_OFF(x)                                   (((x)&0x1u)<<4)               /**< Set RfXoCntOff in register */
#define  GET_RF_XO_CNT_OFF(reg)                             (((reg)>>4)&0x1u)             /**< Get RfXoCntOff from register */
#define  RF_XO_SENSE_OFF_SHIFT                              5                             /**< Shift for RfXoSenseOff */
#define  RF_XO_SENSE_OFF_MASK                               0x00000020u                   /**< Mask for RfXoSenseOff */
#define  RF_XO_SENSE_OFF_BMASK                              0x1u                          /**< Base mask for RfXoSenseOff */
#define  RF_XO_SENSE_OFF(x)                                 (((x)&0x1u)<<5)               /**< Set RfXoSenseOff in register */
#define  GET_RF_XO_SENSE_OFF(reg)                           (((reg)>>5)&0x1u)             /**< Get RfXoSenseOff from register */
#define  RF_XO_FORCE_AMP_SHIFT                              6                             /**< Shift for RfXoForceAmp */
#define  RF_XO_FORCE_AMP_MASK                               0x00000040u                   /**< Mask for RfXoForceAmp */
#define  RF_XO_FORCE_AMP_BMASK                              0x1u                          /**< Base mask for RfXoForceAmp */
#define  RF_XO_FORCE_AMP(x)                                 (((x)&0x1u)<<6)               /**< Set RfXoForceAmp in register */
#define  GET_RF_XO_FORCE_AMP(reg)                           (((reg)>>6)&0x1u)             /**< Get RfXoForceAmp from register */
#define  RF_XO_LDO_TRIM_SHIFT                               7                             /**< Shift for RfXoLdoTrim */
#define  RF_XO_LDO_TRIM_MASK                                0x00000180u                   /**< Mask for RfXoLdoTrim */
#define  RF_XO_LDO_TRIM_BMASK                               0x3u                          /**< Base mask for RfXoLdoTrim */
#define  RF_XO_LDO_TRIM(x)                                  (((x)&0x3u)<<7)               /**< Set RfXoLdoTrim in register */
#define  GET_RF_XO_LDO_TRIM(reg)                            (((reg)>>7)&0x3u)             /**< Get RfXoLdoTrim from register */
#define  RF_XO_LDO_BYPASS_SHIFT                             9                             /**< Shift for RfXoLdoBypass */
#define  RF_XO_LDO_BYPASS_MASK                              0x00000200u                   /**< Mask for RfXoLdoBypass */
#define  RF_XO_LDO_BYPASS_BMASK                             0x1u                          /**< Base mask for RfXoLdoBypass */
#define  RF_XO_LDO_BYPASS(x)                                (((x)&0x1u)<<9)               /**< Set RfXoLdoBypass in register */
#define  GET_RF_XO_LDO_BYPASS(reg)                          (((reg)>>9)&0x1u)             /**< Get RfXoLdoBypass from register */
#define  RF_XO_LDO_BOOST_SHIFT                              10                            /**< Shift for RfXoLdoBoost */
#define  RF_XO_LDO_BOOST_MASK                               0x00000400u                   /**< Mask for RfXoLdoBoost */
#define  RF_XO_LDO_BOOST_BMASK                              0x1u                          /**< Base mask for RfXoLdoBoost */
#define  RF_XO_LDO_BOOST(x)                                 (((x)&0x1u)<<10)              /**< Set RfXoLdoBoost in register */
#define  GET_RF_XO_LDO_BOOST(reg)                           (((reg)>>10)&0x1u)            /**< Get RfXoLdoBoost from register */
#define  RF_XO_LDO_FORCE_SHIFT                              11                            /**< Shift for RfXoLdoForce */
#define  RF_XO_LDO_FORCE_MASK                               0x00000800u                   /**< Mask for RfXoLdoForce */
#define  RF_XO_LDO_FORCE_BMASK                              0x1u                          /**< Base mask for RfXoLdoForce */
#define  RF_XO_LDO_FORCE(x)                                 (((x)&0x1u)<<11)              /**< Set RfXoLdoForce in register */
#define  GET_RF_XO_LDO_FORCE(reg)                           (((reg)>>11)&0x1u)            /**< Get RfXoLdoForce from register */
#define  RF_ISOBRTC_SHIFT                                   12                            /**< Shift for RfIsobrtc */
#define  RF_ISOBRTC_MASK                                    0x00001000u                   /**< Mask for RfIsobrtc */
#define  RF_ISOBRTC_BMASK                                   0x1u                          /**< Base mask for RfIsobrtc */
#define  RF_ISOBRTC(x)                                      (((x)&0x1u)<<12)              /**< Set RfIsobrtc in register */
#define  GET_RF_ISOBRTC(reg)                                (((reg)>>12)&0x1u)            /**< Get RfIsobrtc from register */
#define  RF_XO_EN_DIV2_SHIFT                                13                            /**< Shift for RfXoEnDiv2 */
#define  RF_XO_EN_DIV2_MASK                                 0x00002000u                   /**< Mask for RfXoEnDiv2 */
#define  RF_XO_EN_DIV2_BMASK                                0x1u                          /**< Base mask for RfXoEnDiv2 */
#define  RF_XO_EN_DIV2(x)                                   (((x)&0x1u)<<13)              /**< Set RfXoEnDiv2 in register */
#define  GET_RF_XO_EN_DIV2(reg)                             (((reg)>>13)&0x1u)            /**< Get RfXoEnDiv2 from register */
/** @} */


/**
 * @name RegRfXoSeqDig
 * @{
 */
// RegRfXoSeqDig.r32
#define  REG_RF_XO_SEQ_DIG_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfXoSeqDig */
#define  REG_RF_XO_SEQ_DIG_MASK                             0x00007FFFu                   /**< Mask for RegRfXoSeqDig */

#define  RF_XO_EN_CLK_AUX_DIG_SHIFT                         0                             /**< Shift for RfXoEnClkAuxDig */
#define  RF_XO_EN_CLK_AUX_DIG_MASK                          0x00000001u                   /**< Mask for RfXoEnClkAuxDig */
#define  RF_XO_EN_CLK_AUX_DIG_BMASK                         0x1u                          /**< Base mask for RfXoEnClkAuxDig */
#define  RF_XO_EN_CLK_AUX_DIG(x)                            (((x)&0x1u)<<0)               /**< Set RfXoEnClkAuxDig in register */
#define  GET_RF_XO_EN_CLK_AUX_DIG(reg)                      (((reg)>>0)&0x1u)             /**< Get RfXoEnClkAuxDig from register */
#define  RF_XO_MODE_DIG_SHIFT                               1                             /**< Shift for RfXoModeDig */
#define  RF_XO_MODE_DIG_MASK                                0x00000002u                   /**< Mask for RfXoModeDig */
#define  RF_XO_MODE_DIG_BMASK                               0x1u                          /**< Base mask for RfXoModeDig */
#define  RF_XO_MODE_DIG(x)                                  (((x)&0x1u)<<1)               /**< Set RfXoModeDig in register */
#define  GET_RF_XO_MODE_DIG(reg)                            (((reg)>>1)&0x1u)             /**< Get RfXoModeDig from register */
#define  RF_XO_CAP_OFF_DIG_SHIFT                            2                             /**< Shift for RfXoCapOffDig */
#define  RF_XO_CAP_OFF_DIG_MASK                             0x00000004u                   /**< Mask for RfXoCapOffDig */
#define  RF_XO_CAP_OFF_DIG_BMASK                            0x1u                          /**< Base mask for RfXoCapOffDig */
#define  RF_XO_CAP_OFF_DIG(x)                               (((x)&0x1u)<<2)               /**< Set RfXoCapOffDig in register */
#define  GET_RF_XO_CAP_OFF_DIG(reg)                         (((reg)>>2)&0x1u)             /**< Get RfXoCapOffDig from register */
#define  RF_XO_ISEL_DIG_SHIFT                               3                             /**< Shift for RfXoIselDig */
#define  RF_XO_ISEL_DIG_MASK                                0x00000078u                   /**< Mask for RfXoIselDig */
#define  RF_XO_ISEL_DIG_BMASK                               0xFu                          /**< Base mask for RfXoIselDig */
#define  RF_XO_ISEL_DIG(x)                                  (((x)&0xFu)<<3)               /**< Set RfXoIselDig in register */
#define  GET_RF_XO_ISEL_DIG(reg)                            (((reg)>>3)&0xFu)             /**< Get RfXoIselDig from register */
#define  RF_XO_CDAC_DIG_SHIFT                               7                             /**< Shift for RfXoCdacDig */
#define  RF_XO_CDAC_DIG_MASK                                0x00001F80u                   /**< Mask for RfXoCdacDig */
#define  RF_XO_CDAC_DIG_BMASK                               0x3Fu                         /**< Base mask for RfXoCdacDig */
#define  RF_XO_CDAC_DIG(x)                                  (((x)&0x3Fu)<<7)              /**< Set RfXoCdacDig in register */
#define  GET_RF_XO_CDAC_DIG(reg)                            (((reg)>>7)&0x3Fu)            /**< Get RfXoCdacDig from register */
#define  RF_XO_LDO_TRIM_DIG_SHIFT                           13                            /**< Shift for RfXoLdoTrimDig */
#define  RF_XO_LDO_TRIM_DIG_MASK                            0x00006000u                   /**< Mask for RfXoLdoTrimDig */
#define  RF_XO_LDO_TRIM_DIG_BMASK                           0x3u                          /**< Base mask for RfXoLdoTrimDig */
#define  RF_XO_LDO_TRIM_DIG(x)                              (((x)&0x3u)<<13)              /**< Set RfXoLdoTrimDig in register */
#define  GET_RF_XO_LDO_TRIM_DIG(reg)                        (((reg)>>13)&0x3u)            /**< Get RfXoLdoTrimDig from register */
/** @} */


/**
 * @name RegRfXoDebugDig
 * @{
 */
// RegRfXoDebugDig.r32
#define  REG_RF_XO_DEBUG_DIG_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfXoDebugDig */
#define  REG_RF_XO_DEBUG_DIG_MASK                           0x00003FFFu                   /**< Mask for RegRfXoDebugDig */

#define  RF_XO_DYN_CAP_DIG_SHIFT                            0                             /**< Shift for RfXoDynCapDig */
#define  RF_XO_DYN_CAP_DIG_MASK                             0x00000001u                   /**< Mask for RfXoDynCapDig */
#define  RF_XO_DYN_CAP_DIG_BMASK                            0x1u                          /**< Base mask for RfXoDynCapDig */
#define  RF_XO_DYN_CAP_DIG(x)                               (((x)&0x1u)<<0)               /**< Set RfXoDynCapDig in register */
#define  GET_RF_XO_DYN_CAP_DIG(reg)                         (((reg)>>0)&0x1u)             /**< Get RfXoDynCapDig from register */
#define  RF_XO_DYN_ISEL_DIG_SHIFT                           1                             /**< Shift for RfXoDynIselDig */
#define  RF_XO_DYN_ISEL_DIG_MASK                            0x00000002u                   /**< Mask for RfXoDynIselDig */
#define  RF_XO_DYN_ISEL_DIG_BMASK                           0x1u                          /**< Base mask for RfXoDynIselDig */
#define  RF_XO_DYN_ISEL_DIG(x)                              (((x)&0x1u)<<1)               /**< Set RfXoDynIselDig in register */
#define  GET_RF_XO_DYN_ISEL_DIG(reg)                        (((reg)>>1)&0x1u)             /**< Get RfXoDynIselDig from register */
#define  RF_XO_CNT_DIG_SHIFT                                2                             /**< Shift for RfXoCntDig */
#define  RF_XO_CNT_DIG_MASK                                 0x0000000Cu                   /**< Mask for RfXoCntDig */
#define  RF_XO_CNT_DIG_BMASK                                0x3u                          /**< Base mask for RfXoCntDig */
#define  RF_XO_CNT_DIG(x)                                   (((x)&0x3u)<<2)               /**< Set RfXoCntDig in register */
#define  GET_RF_XO_CNT_DIG(reg)                             (((reg)>>2)&0x3u)             /**< Get RfXoCntDig from register */
#define  RF_XO_CNT_OFF_DIG_SHIFT                            4                             /**< Shift for RfXoCntOffDig */
#define  RF_XO_CNT_OFF_DIG_MASK                             0x00000010u                   /**< Mask for RfXoCntOffDig */
#define  RF_XO_CNT_OFF_DIG_BMASK                            0x1u                          /**< Base mask for RfXoCntOffDig */
#define  RF_XO_CNT_OFF_DIG(x)                               (((x)&0x1u)<<4)               /**< Set RfXoCntOffDig in register */
#define  GET_RF_XO_CNT_OFF_DIG(reg)                         (((reg)>>4)&0x1u)             /**< Get RfXoCntOffDig from register */
#define  RF_XO_SENSE_OFF_DIG_SHIFT                          5                             /**< Shift for RfXoSenseOffDig */
#define  RF_XO_SENSE_OFF_DIG_MASK                           0x00000020u                   /**< Mask for RfXoSenseOffDig */
#define  RF_XO_SENSE_OFF_DIG_BMASK                          0x1u                          /**< Base mask for RfXoSenseOffDig */
#define  RF_XO_SENSE_OFF_DIG(x)                             (((x)&0x1u)<<5)               /**< Set RfXoSenseOffDig in register */
#define  GET_RF_XO_SENSE_OFF_DIG(reg)                       (((reg)>>5)&0x1u)             /**< Get RfXoSenseOffDig from register */
#define  RF_XO_FORCE_AMP_DIG_SHIFT                          6                             /**< Shift for RfXoForceAmpDig */
#define  RF_XO_FORCE_AMP_DIG_MASK                           0x00000040u                   /**< Mask for RfXoForceAmpDig */
#define  RF_XO_FORCE_AMP_DIG_BMASK                          0x1u                          /**< Base mask for RfXoForceAmpDig */
#define  RF_XO_FORCE_AMP_DIG(x)                             (((x)&0x1u)<<6)               /**< Set RfXoForceAmpDig in register */
#define  GET_RF_XO_FORCE_AMP_DIG(reg)                       (((reg)>>6)&0x1u)             /**< Get RfXoForceAmpDig from register */
#define  RF_XO_LDO_BYPASS_DIG_SHIFT                         7                             /**< Shift for RfXoLdoBypassDig */
#define  RF_XO_LDO_BYPASS_DIG_MASK                          0x00000080u                   /**< Mask for RfXoLdoBypassDig */
#define  RF_XO_LDO_BYPASS_DIG_BMASK                         0x1u                          /**< Base mask for RfXoLdoBypassDig */
#define  RF_XO_LDO_BYPASS_DIG(x)                            (((x)&0x1u)<<7)               /**< Set RfXoLdoBypassDig in register */
#define  GET_RF_XO_LDO_BYPASS_DIG(reg)                      (((reg)>>7)&0x1u)             /**< Get RfXoLdoBypassDig from register */
#define  RF_XO_LDO_BOOST_DIG_SHIFT                          8                             /**< Shift for RfXoLdoBoostDig */
#define  RF_XO_LDO_BOOST_DIG_MASK                           0x00000100u                   /**< Mask for RfXoLdoBoostDig */
#define  RF_XO_LDO_BOOST_DIG_BMASK                          0x1u                          /**< Base mask for RfXoLdoBoostDig */
#define  RF_XO_LDO_BOOST_DIG(x)                             (((x)&0x1u)<<8)               /**< Set RfXoLdoBoostDig in register */
#define  GET_RF_XO_LDO_BOOST_DIG(reg)                       (((reg)>>8)&0x1u)             /**< Get RfXoLdoBoostDig from register */
#define  RF_XO_LDO_FORCE_DIG_SHIFT                          9                             /**< Shift for RfXoLdoForceDig */
#define  RF_XO_LDO_FORCE_DIG_MASK                           0x00000200u                   /**< Mask for RfXoLdoForceDig */
#define  RF_XO_LDO_FORCE_DIG_BMASK                          0x1u                          /**< Base mask for RfXoLdoForceDig */
#define  RF_XO_LDO_FORCE_DIG(x)                             (((x)&0x1u)<<9)               /**< Set RfXoLdoForceDig in register */
#define  GET_RF_XO_LDO_FORCE_DIG(reg)                       (((reg)>>9)&0x1u)             /**< Get RfXoLdoForceDig from register */
#define  RF_NOT_USED_DUPLICITE_SHIFT                        10                            /**< Shift for RfNotUsedDuplicite */
#define  RF_NOT_USED_DUPLICITE_MASK                         0x00001C00u                   /**< Mask for RfNotUsedDuplicite */
#define  RF_NOT_USED_DUPLICITE_BMASK                        0x7u                          /**< Base mask for RfNotUsedDuplicite */
#define  RF_NOT_USED_DUPLICITE(x)                           (((x)&0x7u)<<10)              /**< Set RfNotUsedDuplicite in register */
#define  GET_RF_NOT_USED_DUPLICITE(reg)                     (((reg)>>10)&0x7u)            /**< Get RfNotUsedDuplicite from register */
#define  RF_XO_EN_DIV2_DIG_SHIFT                            13                            /**< Shift for RfXoEnDiv2Dig */
#define  RF_XO_EN_DIV2_DIG_MASK                             0x00002000u                   /**< Mask for RfXoEnDiv2Dig */
#define  RF_XO_EN_DIV2_DIG_BMASK                            0x1u                          /**< Base mask for RfXoEnDiv2Dig */
#define  RF_XO_EN_DIV2_DIG(x)                               (((x)&0x1u)<<13)              /**< Set RfXoEnDiv2Dig in register */
#define  GET_RF_XO_EN_DIV2_DIG(reg)                         (((reg)>>13)&0x1u)            /**< Get RfXoEnDiv2Dig from register */
/** @} */


/**
 * @name RegRfRegSparertcDig
 * @{
 */
// RegRfRegSparertcDig.r32
#define  REG_RF_REG_SPARERTC_DIG_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfRegSparertcDig */
#define  REG_RF_REG_SPARERTC_DIG_MASK                       0x00000003u                   /**< Mask for RegRfRegSparertcDig */

#define  RF_SPARE0_SHIFT                                    0                             /**< Shift for RfSpare0 */
#define  RF_SPARE0_MASK                                     0x00000001u                   /**< Mask for RfSpare0 */
#define  RF_SPARE0_BMASK                                    0x1u                          /**< Base mask for RfSpare0 */
#define  RF_SPARE0(x)                                       (((x)&0x1u)<<0)               /**< Set RfSpare0 in register */
#define  GET_RF_SPARE0(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfSpare0 from register */
#define  RF_SPARE1_SHIFT                                    1                             /**< Shift for RfSpare1 */
#define  RF_SPARE1_MASK                                     0x00000002u                   /**< Mask for RfSpare1 */
#define  RF_SPARE1_BMASK                                    0x1u                          /**< Base mask for RfSpare1 */
#define  RF_SPARE1(x)                                       (((x)&0x1u)<<1)               /**< Set RfSpare1 in register */
#define  GET_RF_SPARE1(reg)                                 (((reg)>>1)&0x1u)             /**< Get RfSpare1 from register */
/** @} */


/**
 * @name RegRfRcoscDig
 * @{
 */
// RegRfRcoscDig.r32
#define  REG_RF_RCOSC_DIG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfRcoscDig */
#define  REG_RF_RCOSC_DIG_MASK                              0x000003FFu                   /**< Mask for RegRfRcoscDig */

#define  RF_REG_RCOSC_TRIM_DIG_SHIFT                        0                             /**< Shift for RfRegRcoscTrimDig */
#define  RF_REG_RCOSC_TRIM_DIG_MASK                         0x0000003Fu                   /**< Mask for RfRegRcoscTrimDig */
#define  RF_REG_RCOSC_TRIM_DIG_BMASK                        0x3Fu                         /**< Base mask for RfRegRcoscTrimDig */
#define  RF_REG_RCOSC_TRIM_DIG(x)                           (((x)&0x3Fu)<<0)              /**< Set RfRegRcoscTrimDig in register */
#define  GET_RF_REG_RCOSC_TRIM_DIG(reg)                     (((reg)>>0)&0x3Fu)            /**< Get RfRegRcoscTrimDig from register */
#define  RF_REG_RCOSC_TRIM_FINE_DIG_SHIFT                   6                             /**< Shift for RfRegRcoscTrimFineDig */
#define  RF_REG_RCOSC_TRIM_FINE_DIG_MASK                    0x000000C0u                   /**< Mask for RfRegRcoscTrimFineDig */
#define  RF_REG_RCOSC_TRIM_FINE_DIG_BMASK                   0x3u                          /**< Base mask for RfRegRcoscTrimFineDig */
#define  RF_REG_RCOSC_TRIM_FINE_DIG(x)                      (((x)&0x3u)<<6)               /**< Set RfRegRcoscTrimFineDig in register */
#define  GET_RF_REG_RCOSC_TRIM_FINE_DIG(reg)                (((reg)>>6)&0x3u)             /**< Get RfRegRcoscTrimFineDig from register */
#define  RF_REG_RCOSC_READY_FORCE_DIG_SHIFT                 8                             /**< Shift for RfRegRcoscReadyForceDig */
#define  RF_REG_RCOSC_READY_FORCE_DIG_MASK                  0x00000100u                   /**< Mask for RfRegRcoscReadyForceDig */
#define  RF_REG_RCOSC_READY_FORCE_DIG_BMASK                 0x1u                          /**< Base mask for RfRegRcoscReadyForceDig */
#define  RF_REG_RCOSC_READY_FORCE_DIG(x)                    (((x)&0x1u)<<8)               /**< Set RfRegRcoscReadyForceDig in register */
#define  GET_RF_REG_RCOSC_READY_FORCE_DIG(reg)              (((reg)>>8)&0x1u)             /**< Get RfRegRcoscReadyForceDig from register */
#define  RF_SEQ_RCOSC_PUP_DIG_SHIFT                         9                             /**< Shift for RfSeqRcoscPupDig */
#define  RF_SEQ_RCOSC_PUP_DIG_MASK                          0x00000200u                   /**< Mask for RfSeqRcoscPupDig */
#define  RF_SEQ_RCOSC_PUP_DIG_BMASK                         0x1u                          /**< Base mask for RfSeqRcoscPupDig */
#define  RF_SEQ_RCOSC_PUP_DIG(x)                            (((x)&0x1u)<<9)               /**< Set RfSeqRcoscPupDig in register */
#define  GET_RF_SEQ_RCOSC_PUP_DIG(reg)                      (((reg)>>9)&0x1u)             /**< Get RfSeqRcoscPupDig from register */
/** @} */


/**
 * @name RegRfRegSparertc
 * @{
 */
// RegRfRegSparertc.r32
#define  REG_RF_REG_SPARERTC_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfRegSparertc */
#define  REG_RF_REG_SPARERTC_MASK                           0x00000003u                   /**< Mask for RegRfRegSparertc */

#define  RF_SPARE0_SHIFT                                    0                             /**< Shift for RfSpare0 */
#define  RF_SPARE0_MASK                                     0x00000001u                   /**< Mask for RfSpare0 */
#define  RF_SPARE0_BMASK                                    0x1u                          /**< Base mask for RfSpare0 */
#define  RF_SPARE0(x)                                       (((x)&0x1u)<<0)               /**< Set RfSpare0 in register */
#define  GET_RF_SPARE0(reg)                                 (((reg)>>0)&0x1u)             /**< Get RfSpare0 from register */
#define  RF_SPARE1_SHIFT                                    1                             /**< Shift for RfSpare1 */
#define  RF_SPARE1_MASK                                     0x00000002u                   /**< Mask for RfSpare1 */
#define  RF_SPARE1_BMASK                                    0x1u                          /**< Base mask for RfSpare1 */
#define  RF_SPARE1(x)                                       (((x)&0x1u)<<1)               /**< Set RfSpare1 in register */
#define  GET_RF_SPARE1(reg)                                 (((reg)>>1)&0x1u)             /**< Get RfSpare1 from register */
/** @} */


/**
 * @name RegRfXoSeqRead
 * @{
 */
// RegRfXoSeqRead.r32
#define  REG_RF_XO_SEQ_READ_RESET_VALUE                     0x00000000u                   /**< Reset value of RegRfXoSeqRead */
#define  REG_RF_XO_SEQ_READ_MASK                            0x0000FFFFu                   /**< Mask for RegRfXoSeqRead */

#define  RF_XO_LDO_PUP_READ_SHIFT                           0                             /**< Shift for RfXoLdoPupRead */
#define  RF_XO_LDO_PUP_READ_MASK                            0x00000001u                   /**< Mask for RfXoLdoPupRead */
#define  RF_XO_LDO_PUP_READ_BMASK                           0x1u                          /**< Base mask for RfXoLdoPupRead */
#define  RF_XO_LDO_PUP_READ(x)                              (((x)&0x1u)<<0)               /**< Set RfXoLdoPupRead in register */
#define  GET_RF_XO_LDO_PUP_READ(reg)                        (((reg)>>0)&0x1u)             /**< Get RfXoLdoPupRead from register */
#define  RF_XO_EN_READ_SHIFT                                1                             /**< Shift for RfXoEnRead */
#define  RF_XO_EN_READ_MASK                                 0x00000002u                   /**< Mask for RfXoEnRead */
#define  RF_XO_EN_READ_BMASK                                0x1u                          /**< Base mask for RfXoEnRead */
#define  RF_XO_EN_READ(x)                                   (((x)&0x1u)<<1)               /**< Set RfXoEnRead in register */
#define  GET_RF_XO_EN_READ(reg)                             (((reg)>>1)&0x1u)             /**< Get RfXoEnRead from register */
#define  RF_XO_EN_CLK_DIG_READ_SHIFT                        2                             /**< Shift for RfXoEnClkDigRead */
#define  RF_XO_EN_CLK_DIG_READ_MASK                         0x00000004u                   /**< Mask for RfXoEnClkDigRead */
#define  RF_XO_EN_CLK_DIG_READ_BMASK                        0x1u                          /**< Base mask for RfXoEnClkDigRead */
#define  RF_XO_EN_CLK_DIG_READ(x)                           (((x)&0x1u)<<2)               /**< Set RfXoEnClkDigRead in register */
#define  GET_RF_XO_EN_CLK_DIG_READ(reg)                     (((reg)>>2)&0x1u)             /**< Get RfXoEnClkDigRead from register */
#define  RF_XO_EN_CLK_AUX_READ_SHIFT                        3                             /**< Shift for RfXoEnClkAuxRead */
#define  RF_XO_EN_CLK_AUX_READ_MASK                         0x00000008u                   /**< Mask for RfXoEnClkAuxRead */
#define  RF_XO_EN_CLK_AUX_READ_BMASK                        0x1u                          /**< Base mask for RfXoEnClkAuxRead */
#define  RF_XO_EN_CLK_AUX_READ(x)                           (((x)&0x1u)<<3)               /**< Set RfXoEnClkAuxRead in register */
#define  GET_RF_XO_EN_CLK_AUX_READ(reg)                     (((reg)>>3)&0x1u)             /**< Get RfXoEnClkAuxRead from register */
#define  RF_XO_MODE_READ_SHIFT                              4                             /**< Shift for RfXoModeRead */
#define  RF_XO_MODE_READ_MASK                               0x00000010u                   /**< Mask for RfXoModeRead */
#define  RF_XO_MODE_READ_BMASK                              0x1u                          /**< Base mask for RfXoModeRead */
#define  RF_XO_MODE_READ(x)                                 (((x)&0x1u)<<4)               /**< Set RfXoModeRead in register */
#define  GET_RF_XO_MODE_READ(reg)                           (((reg)>>4)&0x1u)             /**< Get RfXoModeRead from register */
#define  RF_XO_CAP_OFF_READ_SHIFT                           5                             /**< Shift for RfXoCapOffRead */
#define  RF_XO_CAP_OFF_READ_MASK                            0x00000020u                   /**< Mask for RfXoCapOffRead */
#define  RF_XO_CAP_OFF_READ_BMASK                           0x1u                          /**< Base mask for RfXoCapOffRead */
#define  RF_XO_CAP_OFF_READ(x)                              (((x)&0x1u)<<5)               /**< Set RfXoCapOffRead in register */
#define  GET_RF_XO_CAP_OFF_READ(reg)                        (((reg)>>5)&0x1u)             /**< Get RfXoCapOffRead from register */
#define  RF_XO_ISEL_READ_SHIFT                              6                             /**< Shift for RfXoIselRead */
#define  RF_XO_ISEL_READ_MASK                               0x000003C0u                   /**< Mask for RfXoIselRead */
#define  RF_XO_ISEL_READ_BMASK                              0xFu                          /**< Base mask for RfXoIselRead */
#define  RF_XO_ISEL_READ(x)                                 (((x)&0xFu)<<6)               /**< Set RfXoIselRead in register */
#define  GET_RF_XO_ISEL_READ(reg)                           (((reg)>>6)&0xFu)             /**< Get RfXoIselRead from register */
#define  RF_XO_CDAC_READ_SHIFT                              10                            /**< Shift for RfXoCdacRead */
#define  RF_XO_CDAC_READ_MASK                               0x0000FC00u                   /**< Mask for RfXoCdacRead */
#define  RF_XO_CDAC_READ_BMASK                              0x3Fu                         /**< Base mask for RfXoCdacRead */
#define  RF_XO_CDAC_READ(x)                                 (((x)&0x3Fu)<<10)             /**< Set RfXoCdacRead in register */
#define  GET_RF_XO_CDAC_READ(reg)                           (((reg)>>10)&0x3Fu)           /**< Get RfXoCdacRead from register */
/** @} */


/**
 * @name RegRfXoDebugRead
 * @{
 */
// RegRfXoDebugRead.r32
#define  REG_RF_XO_DEBUG_READ_RESET_VALUE                   0x00000000u                   /**< Reset value of RegRfXoDebugRead */
#define  REG_RF_XO_DEBUG_READ_MASK                          0x00003FFFu                   /**< Mask for RegRfXoDebugRead */

#define  RF_XO_DYN_CAP_READ_SHIFT                           0                             /**< Shift for RfXoDynCapRead */
#define  RF_XO_DYN_CAP_READ_MASK                            0x00000001u                   /**< Mask for RfXoDynCapRead */
#define  RF_XO_DYN_CAP_READ_BMASK                           0x1u                          /**< Base mask for RfXoDynCapRead */
#define  RF_XO_DYN_CAP_READ(x)                              (((x)&0x1u)<<0)               /**< Set RfXoDynCapRead in register */
#define  GET_RF_XO_DYN_CAP_READ(reg)                        (((reg)>>0)&0x1u)             /**< Get RfXoDynCapRead from register */
#define  RF_XO_DYN_ISEL_READ_SHIFT                          1                             /**< Shift for RfXoDynIselRead */
#define  RF_XO_DYN_ISEL_READ_MASK                           0x00000002u                   /**< Mask for RfXoDynIselRead */
#define  RF_XO_DYN_ISEL_READ_BMASK                          0x1u                          /**< Base mask for RfXoDynIselRead */
#define  RF_XO_DYN_ISEL_READ(x)                             (((x)&0x1u)<<1)               /**< Set RfXoDynIselRead in register */
#define  GET_RF_XO_DYN_ISEL_READ(reg)                       (((reg)>>1)&0x1u)             /**< Get RfXoDynIselRead from register */
#define  RF_XO_CNT_READ_SHIFT                               2                             /**< Shift for RfXoCntRead */
#define  RF_XO_CNT_READ_MASK                                0x0000000Cu                   /**< Mask for RfXoCntRead */
#define  RF_XO_CNT_READ_BMASK                               0x3u                          /**< Base mask for RfXoCntRead */
#define  RF_XO_CNT_READ(x)                                  (((x)&0x3u)<<2)               /**< Set RfXoCntRead in register */
#define  GET_RF_XO_CNT_READ(reg)                            (((reg)>>2)&0x3u)             /**< Get RfXoCntRead from register */
#define  RF_XO_CNT_OFF_READ_SHIFT                           4                             /**< Shift for RfXoCntOffRead */
#define  RF_XO_CNT_OFF_READ_MASK                            0x00000010u                   /**< Mask for RfXoCntOffRead */
#define  RF_XO_CNT_OFF_READ_BMASK                           0x1u                          /**< Base mask for RfXoCntOffRead */
#define  RF_XO_CNT_OFF_READ(x)                              (((x)&0x1u)<<4)               /**< Set RfXoCntOffRead in register */
#define  GET_RF_XO_CNT_OFF_READ(reg)                        (((reg)>>4)&0x1u)             /**< Get RfXoCntOffRead from register */
#define  RF_XO_SENSE_OFF_READ_SHIFT                         5                             /**< Shift for RfXoSenseOffRead */
#define  RF_XO_SENSE_OFF_READ_MASK                          0x00000020u                   /**< Mask for RfXoSenseOffRead */
#define  RF_XO_SENSE_OFF_READ_BMASK                         0x1u                          /**< Base mask for RfXoSenseOffRead */
#define  RF_XO_SENSE_OFF_READ(x)                            (((x)&0x1u)<<5)               /**< Set RfXoSenseOffRead in register */
#define  GET_RF_XO_SENSE_OFF_READ(reg)                      (((reg)>>5)&0x1u)             /**< Get RfXoSenseOffRead from register */
#define  RF_XO_FORCE_AMP_READ_SHIFT                         6                             /**< Shift for RfXoForceAmpRead */
#define  RF_XO_FORCE_AMP_READ_MASK                          0x00000040u                   /**< Mask for RfXoForceAmpRead */
#define  RF_XO_FORCE_AMP_READ_BMASK                         0x1u                          /**< Base mask for RfXoForceAmpRead */
#define  RF_XO_FORCE_AMP_READ(x)                            (((x)&0x1u)<<6)               /**< Set RfXoForceAmpRead in register */
#define  GET_RF_XO_FORCE_AMP_READ(reg)                      (((reg)>>6)&0x1u)             /**< Get RfXoForceAmpRead from register */
#define  RF_XO_LDO_TRIM_READ_SHIFT                          7                             /**< Shift for RfXoLdoTrimRead */
#define  RF_XO_LDO_TRIM_READ_MASK                           0x00000180u                   /**< Mask for RfXoLdoTrimRead */
#define  RF_XO_LDO_TRIM_READ_BMASK                          0x3u                          /**< Base mask for RfXoLdoTrimRead */
#define  RF_XO_LDO_TRIM_READ(x)                             (((x)&0x3u)<<7)               /**< Set RfXoLdoTrimRead in register */
#define  GET_RF_XO_LDO_TRIM_READ(reg)                       (((reg)>>7)&0x3u)             /**< Get RfXoLdoTrimRead from register */
#define  RF_XO_LDO_BYPASS_READ_SHIFT                        9                             /**< Shift for RfXoLdoBypassRead */
#define  RF_XO_LDO_BYPASS_READ_MASK                         0x00000200u                   /**< Mask for RfXoLdoBypassRead */
#define  RF_XO_LDO_BYPASS_READ_BMASK                        0x1u                          /**< Base mask for RfXoLdoBypassRead */
#define  RF_XO_LDO_BYPASS_READ(x)                           (((x)&0x1u)<<9)               /**< Set RfXoLdoBypassRead in register */
#define  GET_RF_XO_LDO_BYPASS_READ(reg)                     (((reg)>>9)&0x1u)             /**< Get RfXoLdoBypassRead from register */
#define  RF_XO_LDO_BOOST_READ_SHIFT                         10                            /**< Shift for RfXoLdoBoostRead */
#define  RF_XO_LDO_BOOST_READ_MASK                          0x00000400u                   /**< Mask for RfXoLdoBoostRead */
#define  RF_XO_LDO_BOOST_READ_BMASK                         0x1u                          /**< Base mask for RfXoLdoBoostRead */
#define  RF_XO_LDO_BOOST_READ(x)                            (((x)&0x1u)<<10)              /**< Set RfXoLdoBoostRead in register */
#define  GET_RF_XO_LDO_BOOST_READ(reg)                      (((reg)>>10)&0x1u)            /**< Get RfXoLdoBoostRead from register */
#define  RF_XO_LDO_FORCE_READ_SHIFT                         11                            /**< Shift for RfXoLdoForceRead */
#define  RF_XO_LDO_FORCE_READ_MASK                          0x00000800u                   /**< Mask for RfXoLdoForceRead */
#define  RF_XO_LDO_FORCE_READ_BMASK                         0x1u                          /**< Base mask for RfXoLdoForceRead */
#define  RF_XO_LDO_FORCE_READ(x)                            (((x)&0x1u)<<11)              /**< Set RfXoLdoForceRead in register */
#define  GET_RF_XO_LDO_FORCE_READ(reg)                      (((reg)>>11)&0x1u)            /**< Get RfXoLdoForceRead from register */
#define  RF_XO_READY_SHIFT                                  12                            /**< Shift for RfXoReady */
#define  RF_XO_READY_MASK                                   0x00001000u                   /**< Mask for RfXoReady */
#define  RF_XO_READY_BMASK                                  0x1u                          /**< Base mask for RfXoReady */
#define  RF_XO_READY(x)                                     (((x)&0x1u)<<12)              /**< Set RfXoReady in register */
#define  GET_RF_XO_READY(reg)                               (((reg)>>12)&0x1u)            /**< Get RfXoReady from register */
#define  RF_XO_EN_DIV2_READ_SHIFT                           13                            /**< Shift for RfXoEnDiv2Read */
#define  RF_XO_EN_DIV2_READ_MASK                            0x00002000u                   /**< Mask for RfXoEnDiv2Read */
#define  RF_XO_EN_DIV2_READ_BMASK                           0x1u                          /**< Base mask for RfXoEnDiv2Read */
#define  RF_XO_EN_DIV2_READ(x)                              (((x)&0x1u)<<13)              /**< Set RfXoEnDiv2Read in register */
#define  GET_RF_XO_EN_DIV2_READ(reg)                        (((reg)>>13)&0x1u)            /**< Get RfXoEnDiv2Read from register */
/** @} */


/**
 * @name RegRfRegSparertcRead
 * @{
 */
// RegRfRegSparertcRead.r32
#define  REG_RF_REG_SPARERTC_READ_RESET_VALUE               0x00000000u                   /**< Reset value of RegRfRegSparertcRead */
#define  REG_RF_REG_SPARERTC_READ_MASK                      0x00000003u                   /**< Mask for RegRfRegSparertcRead */

#define  RF_SPARE_READ0_SHIFT                               0                             /**< Shift for RfSpareRead0 */
#define  RF_SPARE_READ0_MASK                                0x00000001u                   /**< Mask for RfSpareRead0 */
#define  RF_SPARE_READ0_BMASK                               0x1u                          /**< Base mask for RfSpareRead0 */
#define  RF_SPARE_READ0(x)                                  (((x)&0x1u)<<0)               /**< Set RfSpareRead0 in register */
#define  GET_RF_SPARE_READ0(reg)                            (((reg)>>0)&0x1u)             /**< Get RfSpareRead0 from register */
#define  RF_SPARE_READ1_SHIFT                               1                             /**< Shift for RfSpareRead1 */
#define  RF_SPARE_READ1_MASK                                0x00000002u                   /**< Mask for RfSpareRead1 */
#define  RF_SPARE_READ1_BMASK                               0x1u                          /**< Base mask for RfSpareRead1 */
#define  RF_SPARE_READ1(x)                                  (((x)&0x1u)<<1)               /**< Set RfSpareRead1 in register */
#define  GET_RF_SPARE_READ1(reg)                            (((reg)>>1)&0x1u)             /**< Get RfSpareRead1 from register */
/** @} */


/**
 * @name RegRfXoDigRead
 * @{
 */
// RegRfXoDigRead.r32
#define  REG_RF_XO_DIG_READ_RESET_VALUE                     0x00000000u                   /**< Reset value of RegRfXoDigRead */
#define  REG_RF_XO_DIG_READ_MASK                            0x0000FFFFu                   /**< Mask for RegRfXoDigRead */

#define  RF_RCOSC_DIG_READY_SHIFT                           0                             /**< Shift for RfRcoscDigReady */
#define  RF_RCOSC_DIG_READY_MASK                            0x00000001u                   /**< Mask for RfRcoscDigReady */
#define  RF_RCOSC_DIG_READY_BMASK                           0x1u                          /**< Base mask for RfRcoscDigReady */
#define  RF_RCOSC_DIG_READY(x)                              (((x)&0x1u)<<0)               /**< Set RfRcoscDigReady in register */
#define  GET_RF_RCOSC_DIG_READY(reg)                        (((reg)>>0)&0x1u)             /**< Get RfRcoscDigReady from register */
#define  RF_TSEQ_TXRX_WARMUP_DONE_SHIFT                     1                             /**< Shift for RfTseqTxrxWarmupDone */
#define  RF_TSEQ_TXRX_WARMUP_DONE_MASK                      0x00000002u                   /**< Mask for RfTseqTxrxWarmupDone */
#define  RF_TSEQ_TXRX_WARMUP_DONE_BMASK                     0x1u                          /**< Base mask for RfTseqTxrxWarmupDone */
#define  RF_TSEQ_TXRX_WARMUP_DONE(x)                        (((x)&0x1u)<<1)               /**< Set RfTseqTxrxWarmupDone in register */
#define  GET_RF_TSEQ_TXRX_WARMUP_DONE(reg)                  (((reg)>>1)&0x1u)             /**< Get RfTseqTxrxWarmupDone from register */
#define  RF_XO_DIG_RD_SPARE_SHIFT                           2                             /**< Shift for RfXoDigRdSpare */
#define  RF_XO_DIG_RD_SPARE_MASK                            0x0000FFFCu                   /**< Mask for RfXoDigRdSpare */
#define  RF_XO_DIG_RD_SPARE_BMASK                           0x3FFFu                       /**< Base mask for RfXoDigRdSpare */
#define  RF_XO_DIG_RD_SPARE(x)                              (((x)&0x3FFFu)<<2)            /**< Set RfXoDigRdSpare in register */
#define  GET_RF_XO_DIG_RD_SPARE(reg)                        (((reg)>>2)&0x3FFFu)          /**< Get RfXoDigRdSpare from register */
/** @} */


/**
 * @name RegRfDcdcStatusCore
 * @{
 */
// RegRfDcdcStatusCore.r32
#define  REG_RF_DCDC_STATUS_CORE_RESET_VALUE                0x00000000u                   /**< Reset value of RegRfDcdcStatusCore */
#define  REG_RF_DCDC_STATUS_CORE_MASK                       0x0000FFFFu                   /**< Mask for RegRfDcdcStatusCore */

#define  RF_DCDC_WR_STAT_A_RTC_SHIFT                        0                             /**< Shift for RfDcdcWrStatARtc */
#define  RF_DCDC_WR_STAT_A_RTC_MASK                         0x0000FFFFu                   /**< Mask for RfDcdcWrStatARtc */
#define  RF_DCDC_WR_STAT_A_RTC_BMASK                        0xFFFFu                       /**< Base mask for RfDcdcWrStatARtc */
#define  RF_DCDC_WR_STAT_A_RTC(x)                           (((x)&0xFFFFu)<<0)            /**< Set RfDcdcWrStatARtc in register */
#define  GET_RF_DCDC_WR_STAT_A_RTC(reg)                     (((reg)>>0)&0xFFFFu)          /**< Get RfDcdcWrStatARtc from register */
/** @} */


/**
 * @name RegRfDcdcStatusFsm
 * @{
 */
// RegRfDcdcStatusFsm.r32
#define  REG_RF_DCDC_STATUS_FSM_RESET_VALUE                 0x00000000u                   /**< Reset value of RegRfDcdcStatusFsm */
#define  REG_RF_DCDC_STATUS_FSM_MASK                        0x0000FFFFu                   /**< Mask for RegRfDcdcStatusFsm */

#define  RF_DCDC_WR_STAT_B_RTC_SHIFT                        0                             /**< Shift for RfDcdcWrStatBRtc */
#define  RF_DCDC_WR_STAT_B_RTC_MASK                         0x0000FFFFu                   /**< Mask for RfDcdcWrStatBRtc */
#define  RF_DCDC_WR_STAT_B_RTC_BMASK                        0xFFFFu                       /**< Base mask for RfDcdcWrStatBRtc */
#define  RF_DCDC_WR_STAT_B_RTC(x)                           (((x)&0xFFFFu)<<0)            /**< Set RfDcdcWrStatBRtc in register */
#define  GET_RF_DCDC_WR_STAT_B_RTC(reg)                     (((reg)>>0)&0xFFFFu)          /**< Get RfDcdcWrStatBRtc from register */
/** @} */


/**
 * @name RegRfRcosc
 * @{
 */
// RegRfRcosc.r32
#define  REG_RF_RCOSC_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRfRcosc */
#define  REG_RF_RCOSC_MASK                                  0x000003FFu                   /**< Mask for RegRfRcosc */

#define  RF_REG_RCOSC_TRIM_RTC_SHIFT                        0                             /**< Shift for RfRegRcoscTrimRtc */
#define  RF_REG_RCOSC_TRIM_RTC_MASK                         0x0000003Fu                   /**< Mask for RfRegRcoscTrimRtc */
#define  RF_REG_RCOSC_TRIM_RTC_BMASK                        0x3Fu                         /**< Base mask for RfRegRcoscTrimRtc */
#define  RF_REG_RCOSC_TRIM_RTC(x)                           (((x)&0x3Fu)<<0)              /**< Set RfRegRcoscTrimRtc in register */
#define  GET_RF_REG_RCOSC_TRIM_RTC(reg)                     (((reg)>>0)&0x3Fu)            /**< Get RfRegRcoscTrimRtc from register */
#define  RF_REG_RCOSC_TRIM_FINE_RTC_SHIFT                   6                             /**< Shift for RfRegRcoscTrimFineRtc */
#define  RF_REG_RCOSC_TRIM_FINE_RTC_MASK                    0x000000C0u                   /**< Mask for RfRegRcoscTrimFineRtc */
#define  RF_REG_RCOSC_TRIM_FINE_RTC_BMASK                   0x3u                          /**< Base mask for RfRegRcoscTrimFineRtc */
#define  RF_REG_RCOSC_TRIM_FINE_RTC(x)                      (((x)&0x3u)<<6)               /**< Set RfRegRcoscTrimFineRtc in register */
#define  GET_RF_REG_RCOSC_TRIM_FINE_RTC(reg)                (((reg)>>6)&0x3u)             /**< Get RfRegRcoscTrimFineRtc from register */
#define  RF_REG_RCOSC_READY_FORCE_RTC_SHIFT                 8                             /**< Shift for RfRegRcoscReadyForceRtc */
#define  RF_REG_RCOSC_READY_FORCE_RTC_MASK                  0x00000100u                   /**< Mask for RfRegRcoscReadyForceRtc */
#define  RF_REG_RCOSC_READY_FORCE_RTC_BMASK                 0x1u                          /**< Base mask for RfRegRcoscReadyForceRtc */
#define  RF_REG_RCOSC_READY_FORCE_RTC(x)                    (((x)&0x1u)<<8)               /**< Set RfRegRcoscReadyForceRtc in register */
#define  GET_RF_REG_RCOSC_READY_FORCE_RTC(reg)              (((reg)>>8)&0x1u)             /**< Get RfRegRcoscReadyForceRtc from register */
#define  RF_SEQ_RCOSC_PUP_RTC_SHIFT                         9                             /**< Shift for RfSeqRcoscPupRtc */
#define  RF_SEQ_RCOSC_PUP_RTC_MASK                          0x00000200u                   /**< Mask for RfSeqRcoscPupRtc */
#define  RF_SEQ_RCOSC_PUP_RTC_BMASK                         0x1u                          /**< Base mask for RfSeqRcoscPupRtc */
#define  RF_SEQ_RCOSC_PUP_RTC(x)                            (((x)&0x1u)<<9)               /**< Set RfSeqRcoscPupRtc in register */
#define  GET_RF_SEQ_RCOSC_PUP_RTC(reg)                      (((reg)>>9)&0x1u)             /**< Get RfSeqRcoscPupRtc from register */
/** @} */


/**
 * @name RegRfDcdcCore
 * @{
 */
// RegRfDcdcCore.r32
#define  REG_RF_DCDC_CORE_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfDcdcCore */
#define  REG_RF_DCDC_CORE_MASK                              0x0000FFFFu                   /**< Mask for RegRfDcdcCore */

#define  RF_DCDC_PUP_EXT_RTC_SHIFT                          0                             /**< Shift for RfDcdcPupExtRtc */
#define  RF_DCDC_PUP_EXT_RTC_MASK                           0x00000001u                   /**< Mask for RfDcdcPupExtRtc */
#define  RF_DCDC_PUP_EXT_RTC_BMASK                          0x1u                          /**< Base mask for RfDcdcPupExtRtc */
#define  RF_DCDC_PUP_EXT_RTC(x)                             (((x)&0x1u)<<0)               /**< Set RfDcdcPupExtRtc in register */
#define  GET_RF_DCDC_PUP_EXT_RTC(reg)                       (((reg)>>0)&0x1u)             /**< Get RfDcdcPupExtRtc from register */
#define  RF_DCDC_GNDONPDN_EXT_RTC_SHIFT                     1                             /**< Shift for RfDcdcGndonpdnExtRtc */
#define  RF_DCDC_GNDONPDN_EXT_RTC_MASK                      0x00000002u                   /**< Mask for RfDcdcGndonpdnExtRtc */
#define  RF_DCDC_GNDONPDN_EXT_RTC_BMASK                     0x1u                          /**< Base mask for RfDcdcGndonpdnExtRtc */
#define  RF_DCDC_GNDONPDN_EXT_RTC(x)                        (((x)&0x1u)<<1)               /**< Set RfDcdcGndonpdnExtRtc in register */
#define  GET_RF_DCDC_GNDONPDN_EXT_RTC(reg)                  (((reg)>>1)&0x1u)             /**< Get RfDcdcGndonpdnExtRtc from register */
#define  RF_DCDC_VOUTDC_EXT_RTC_SHIFT                       2                             /**< Shift for RfDcdcVoutdcExtRtc */
#define  RF_DCDC_VOUTDC_EXT_RTC_MASK                        0x0000001Cu                   /**< Mask for RfDcdcVoutdcExtRtc */
#define  RF_DCDC_VOUTDC_EXT_RTC_BMASK                       0x7u                          /**< Base mask for RfDcdcVoutdcExtRtc */
#define  RF_DCDC_VOUTDC_EXT_RTC(x)                          (((x)&0x7u)<<2)               /**< Set RfDcdcVoutdcExtRtc in register */
#define  GET_RF_DCDC_VOUTDC_EXT_RTC(reg)                    (((reg)>>2)&0x7u)             /**< Get RfDcdcVoutdcExtRtc from register */
#define  RF_DCDC_VOUTHYST_EXT_RTC_SHIFT                     5                             /**< Shift for RfDcdcVouthystExtRtc */
#define  RF_DCDC_VOUTHYST_EXT_RTC_MASK                      0x00000060u                   /**< Mask for RfDcdcVouthystExtRtc */
#define  RF_DCDC_VOUTHYST_EXT_RTC_BMASK                     0x3u                          /**< Base mask for RfDcdcVouthystExtRtc */
#define  RF_DCDC_VOUTHYST_EXT_RTC(x)                        (((x)&0x3u)<<5)               /**< Set RfDcdcVouthystExtRtc in register */
#define  GET_RF_DCDC_VOUTHYST_EXT_RTC(reg)                  (((reg)>>5)&0x3u)             /**< Get RfDcdcVouthystExtRtc from register */
#define  RF_DCDC_IND_EXT_RTC_SHIFT                          7                             /**< Shift for RfDcdcIndExtRtc */
#define  RF_DCDC_IND_EXT_RTC_MASK                           0x00000080u                   /**< Mask for RfDcdcIndExtRtc */
#define  RF_DCDC_IND_EXT_RTC_BMASK                          0x1u                          /**< Base mask for RfDcdcIndExtRtc */
#define  RF_DCDC_IND_EXT_RTC(x)                             (((x)&0x1u)<<7)               /**< Set RfDcdcIndExtRtc in register */
#define  GET_RF_DCDC_IND_EXT_RTC(reg)                       (((reg)>>7)&0x1u)             /**< Get RfDcdcIndExtRtc from register */
#define  RF_DCDC_ILPK_EXT_RTC_SHIFT                         8                             /**< Shift for RfDcdcIlpkExtRtc */
#define  RF_DCDC_ILPK_EXT_RTC_MASK                          0x00000700u                   /**< Mask for RfDcdcIlpkExtRtc */
#define  RF_DCDC_ILPK_EXT_RTC_BMASK                         0x7u                          /**< Base mask for RfDcdcIlpkExtRtc */
#define  RF_DCDC_ILPK_EXT_RTC(x)                            (((x)&0x7u)<<8)               /**< Set RfDcdcIlpkExtRtc in register */
#define  GET_RF_DCDC_ILPK_EXT_RTC(reg)                      (((reg)>>8)&0x7u)             /**< Get RfDcdcIlpkExtRtc from register */
#define  RF_DCDC_NRGMODE_EXT_RTC_SHIFT                      11                            /**< Shift for RfDcdcNrgmodeExtRtc */
#define  RF_DCDC_NRGMODE_EXT_RTC_MASK                       0x00000800u                   /**< Mask for RfDcdcNrgmodeExtRtc */
#define  RF_DCDC_NRGMODE_EXT_RTC_BMASK                      0x1u                          /**< Base mask for RfDcdcNrgmodeExtRtc */
#define  RF_DCDC_NRGMODE_EXT_RTC(x)                         (((x)&0x1u)<<11)              /**< Set RfDcdcNrgmodeExtRtc in register */
#define  GET_RF_DCDC_NRGMODE_EXT_RTC(reg)                   (((reg)>>11)&0x1u)            /**< Get RfDcdcNrgmodeExtRtc from register */
#define  RF_DCDC_SWDRVFB_EXT_RTC_SHIFT                      12                            /**< Shift for RfDcdcSwdrvfbExtRtc */
#define  RF_DCDC_SWDRVFB_EXT_RTC_MASK                       0x00001000u                   /**< Mask for RfDcdcSwdrvfbExtRtc */
#define  RF_DCDC_SWDRVFB_EXT_RTC_BMASK                      0x1u                          /**< Base mask for RfDcdcSwdrvfbExtRtc */
#define  RF_DCDC_SWDRVFB_EXT_RTC(x)                         (((x)&0x1u)<<12)              /**< Set RfDcdcSwdrvfbExtRtc in register */
#define  GET_RF_DCDC_SWDRVFB_EXT_RTC(reg)                   (((reg)>>12)&0x1u)            /**< Get RfDcdcSwdrvfbExtRtc from register */
#define  RF_DCDC_SWGND_UNITS_EXT_RTC_SHIFT                  13                            /**< Shift for RfDcdcSwgndUnitsExtRtc */
#define  RF_DCDC_SWGND_UNITS_EXT_RTC_MASK                   0x00002000u                   /**< Mask for RfDcdcSwgndUnitsExtRtc */
#define  RF_DCDC_SWGND_UNITS_EXT_RTC_BMASK                  0x1u                          /**< Base mask for RfDcdcSwgndUnitsExtRtc */
#define  RF_DCDC_SWGND_UNITS_EXT_RTC(x)                     (((x)&0x1u)<<13)              /**< Set RfDcdcSwgndUnitsExtRtc in register */
#define  GET_RF_DCDC_SWGND_UNITS_EXT_RTC(reg)               (((reg)>>13)&0x1u)            /**< Get RfDcdcSwgndUnitsExtRtc from register */
#define  RF_DCDC_SWIN_UNITS_EXT_RTC_SHIFT                   14                            /**< Shift for RfDcdcSwinUnitsExtRtc */
#define  RF_DCDC_SWIN_UNITS_EXT_RTC_MASK                    0x00004000u                   /**< Mask for RfDcdcSwinUnitsExtRtc */
#define  RF_DCDC_SWIN_UNITS_EXT_RTC_BMASK                   0x1u                          /**< Base mask for RfDcdcSwinUnitsExtRtc */
#define  RF_DCDC_SWIN_UNITS_EXT_RTC(x)                      (((x)&0x1u)<<14)              /**< Set RfDcdcSwinUnitsExtRtc in register */
#define  GET_RF_DCDC_SWIN_UNITS_EXT_RTC(reg)                (((reg)>>14)&0x1u)            /**< Get RfDcdcSwinUnitsExtRtc from register */
#define  RF_DCDC_SPARE0_EXT_RTC_SHIFT                       15                            /**< Shift for RfDcdcSpare0ExtRtc */
#define  RF_DCDC_SPARE0_EXT_RTC_MASK                        0x00008000u                   /**< Mask for RfDcdcSpare0ExtRtc */
#define  RF_DCDC_SPARE0_EXT_RTC_BMASK                       0x1u                          /**< Base mask for RfDcdcSpare0ExtRtc */
#define  RF_DCDC_SPARE0_EXT_RTC(x)                          (((x)&0x1u)<<15)              /**< Set RfDcdcSpare0ExtRtc in register */
#define  GET_RF_DCDC_SPARE0_EXT_RTC(reg)                    (((reg)>>15)&0x1u)            /**< Get RfDcdcSpare0ExtRtc from register */
/** @} */


/**
 * @name RegRfDcdcTimer
 * @{
 */
// RegRfDcdcTimer.r32
#define  REG_RF_DCDC_TIMER_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfDcdcTimer */
#define  REG_RF_DCDC_TIMER_MASK                             0x0000FFFFu                   /**< Mask for RegRfDcdcTimer */

#define  RF_DCDC_TPUP_EXT_RTC_SHIFT                         0                             /**< Shift for RfDcdcTpupExtRtc */
#define  RF_DCDC_TPUP_EXT_RTC_MASK                          0x00000003u                   /**< Mask for RfDcdcTpupExtRtc */
#define  RF_DCDC_TPUP_EXT_RTC_BMASK                         0x3u                          /**< Base mask for RfDcdcTpupExtRtc */
#define  RF_DCDC_TPUP_EXT_RTC(x)                            (((x)&0x3u)<<0)               /**< Set RfDcdcTpupExtRtc in register */
#define  GET_RF_DCDC_TPUP_EXT_RTC(reg)                      (((reg)>>0)&0x3u)             /**< Get RfDcdcTpupExtRtc from register */
#define  RF_DCDC_TWAKEUP_EXT_RTC_SHIFT                      2                             /**< Shift for RfDcdcTwakeupExtRtc */
#define  RF_DCDC_TWAKEUP_EXT_RTC_MASK                       0x0000000Cu                   /**< Mask for RfDcdcTwakeupExtRtc */
#define  RF_DCDC_TWAKEUP_EXT_RTC_BMASK                      0x3u                          /**< Base mask for RfDcdcTwakeupExtRtc */
#define  RF_DCDC_TWAKEUP_EXT_RTC(x)                         (((x)&0x3u)<<2)               /**< Set RfDcdcTwakeupExtRtc in register */
#define  GET_RF_DCDC_TWAKEUP_EXT_RTC(reg)                   (((reg)>>2)&0x3u)             /**< Get RfDcdcTwakeupExtRtc from register */
#define  RF_DCDC_TSLEEP_EXT_RTC_SHIFT                       4                             /**< Shift for RfDcdcTsleepExtRtc */
#define  RF_DCDC_TSLEEP_EXT_RTC_MASK                        0x00000070u                   /**< Mask for RfDcdcTsleepExtRtc */
#define  RF_DCDC_TSLEEP_EXT_RTC_BMASK                       0x7u                          /**< Base mask for RfDcdcTsleepExtRtc */
#define  RF_DCDC_TSLEEP_EXT_RTC(x)                          (((x)&0x7u)<<4)               /**< Set RfDcdcTsleepExtRtc in register */
#define  GET_RF_DCDC_TSLEEP_EXT_RTC(reg)                    (((reg)>>4)&0x7u)             /**< Get RfDcdcTsleepExtRtc from register */
#define  RF_DCDC_TNRGMAX_EXT_RTC_SHIFT                      7                             /**< Shift for RfDcdcTnrgmaxExtRtc */
#define  RF_DCDC_TNRGMAX_EXT_RTC_MASK                       0x00000380u                   /**< Mask for RfDcdcTnrgmaxExtRtc */
#define  RF_DCDC_TNRGMAX_EXT_RTC_BMASK                      0x7u                          /**< Base mask for RfDcdcTnrgmaxExtRtc */
#define  RF_DCDC_TNRGMAX_EXT_RTC(x)                         (((x)&0x7u)<<7)               /**< Set RfDcdcTnrgmaxExtRtc in register */
#define  GET_RF_DCDC_TNRGMAX_EXT_RTC(reg)                   (((reg)>>7)&0x7u)             /**< Get RfDcdcTnrgmaxExtRtc from register */
#define  RF_DCDC_TDMPMAX_EXT_RTC_SHIFT                      10                            /**< Shift for RfDcdcTdmpmaxExtRtc */
#define  RF_DCDC_TDMPMAX_EXT_RTC_MASK                       0x00001C00u                   /**< Mask for RfDcdcTdmpmaxExtRtc */
#define  RF_DCDC_TDMPMAX_EXT_RTC_BMASK                      0x7u                          /**< Base mask for RfDcdcTdmpmaxExtRtc */
#define  RF_DCDC_TDMPMAX_EXT_RTC(x)                         (((x)&0x7u)<<10)              /**< Set RfDcdcTdmpmaxExtRtc in register */
#define  GET_RF_DCDC_TDMPMAX_EXT_RTC(reg)                   (((reg)>>10)&0x7u)            /**< Get RfDcdcTdmpmaxExtRtc from register */
#define  RF_DCDC_SPARE1_EXT_RTC_SHIFT                       13                            /**< Shift for RfDcdcSpare1ExtRtc */
#define  RF_DCDC_SPARE1_EXT_RTC_MASK                        0x0000E000u                   /**< Mask for RfDcdcSpare1ExtRtc */
#define  RF_DCDC_SPARE1_EXT_RTC_BMASK                       0x7u                          /**< Base mask for RfDcdcSpare1ExtRtc */
#define  RF_DCDC_SPARE1_EXT_RTC(x)                          (((x)&0x7u)<<13)              /**< Set RfDcdcSpare1ExtRtc in register */
#define  GET_RF_DCDC_SPARE1_EXT_RTC(reg)                    (((reg)>>13)&0x7u)            /**< Get RfDcdcSpare1ExtRtc from register */
/** @} */


/**
 * @name RegRfDcdcRef
 * @{
 */
// RegRfDcdcRef.r32
#define  REG_RF_DCDC_REF_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfDcdcRef */
#define  REG_RF_DCDC_REF_MASK                               0x000003FFu                   /**< Mask for RegRfDcdcRef */

#define  RF_DCDC_BG_STARTUP_DIS_EXT_RTC_SHIFT               0                             /**< Shift for RfDcdcBgStartupDisExtRtc */
#define  RF_DCDC_BG_STARTUP_DIS_EXT_RTC_MASK                0x00000001u                   /**< Mask for RfDcdcBgStartupDisExtRtc */
#define  RF_DCDC_BG_STARTUP_DIS_EXT_RTC_BMASK               0x1u                          /**< Base mask for RfDcdcBgStartupDisExtRtc */
#define  RF_DCDC_BG_STARTUP_DIS_EXT_RTC(x)                  (((x)&0x1u)<<0)               /**< Set RfDcdcBgStartupDisExtRtc in register */
#define  GET_RF_DCDC_BG_STARTUP_DIS_EXT_RTC(reg)            (((reg)>>0)&0x1u)             /**< Get RfDcdcBgStartupDisExtRtc from register */
#define  RF_DCDC_BG_EXT_RTC_SHIFT                           1                             /**< Shift for RfDcdcBgExtRtc */
#define  RF_DCDC_BG_EXT_RTC_MASK                            0x0000000Eu                   /**< Mask for RfDcdcBgExtRtc */
#define  RF_DCDC_BG_EXT_RTC_BMASK                           0x7u                          /**< Base mask for RfDcdcBgExtRtc */
#define  RF_DCDC_BG_EXT_RTC(x)                              (((x)&0x7u)<<1)               /**< Set RfDcdcBgExtRtc in register */
#define  GET_RF_DCDC_BG_EXT_RTC(reg)                        (((reg)>>1)&0x7u)             /**< Get RfDcdcBgExtRtc from register */
#define  RF_DCDC_RO_IBBUMP_EXT_RTC_SHIFT                    4                             /**< Shift for RfDcdcRoIbbumpExtRtc */
#define  RF_DCDC_RO_IBBUMP_EXT_RTC_MASK                     0x00000070u                   /**< Mask for RfDcdcRoIbbumpExtRtc */
#define  RF_DCDC_RO_IBBUMP_EXT_RTC_BMASK                    0x7u                          /**< Base mask for RfDcdcRoIbbumpExtRtc */
#define  RF_DCDC_RO_IBBUMP_EXT_RTC(x)                       (((x)&0x7u)<<4)               /**< Set RfDcdcRoIbbumpExtRtc in register */
#define  GET_RF_DCDC_RO_IBBUMP_EXT_RTC(reg)                 (((reg)>>4)&0x7u)             /**< Get RfDcdcRoIbbumpExtRtc from register */
#define  RF_DCDC_IBIAS_BUMP_EXT_RTC_SHIFT                   7                             /**< Shift for RfDcdcIbiasBumpExtRtc */
#define  RF_DCDC_IBIAS_BUMP_EXT_RTC_MASK                    0x00000380u                   /**< Mask for RfDcdcIbiasBumpExtRtc */
#define  RF_DCDC_IBIAS_BUMP_EXT_RTC_BMASK                   0x7u                          /**< Base mask for RfDcdcIbiasBumpExtRtc */
#define  RF_DCDC_IBIAS_BUMP_EXT_RTC(x)                      (((x)&0x7u)<<7)               /**< Set RfDcdcIbiasBumpExtRtc in register */
#define  GET_RF_DCDC_IBIAS_BUMP_EXT_RTC(reg)                (((reg)>>7)&0x7u)             /**< Get RfDcdcIbiasBumpExtRtc from register */
/** @} */


/**
 * @name RegRfDcdcTest
 * @{
 */
// RegRfDcdcTest.r32
#define  REG_RF_DCDC_TEST_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfDcdcTest */
#define  REG_RF_DCDC_TEST_MASK                              0x00003FFFu                   /**< Mask for RegRfDcdcTest */

#define  RF_DCDC_UVHYST_DIS_EXT_RTC_SHIFT                   0                             /**< Shift for RfDcdcUvhystDisExtRtc */
#define  RF_DCDC_UVHYST_DIS_EXT_RTC_MASK                    0x00000001u                   /**< Mask for RfDcdcUvhystDisExtRtc */
#define  RF_DCDC_UVHYST_DIS_EXT_RTC_BMASK                   0x1u                          /**< Base mask for RfDcdcUvhystDisExtRtc */
#define  RF_DCDC_UVHYST_DIS_EXT_RTC(x)                      (((x)&0x1u)<<0)               /**< Set RfDcdcUvhystDisExtRtc in register */
#define  GET_RF_DCDC_UVHYST_DIS_EXT_RTC(reg)                (((reg)>>0)&0x1u)             /**< Get RfDcdcUvhystDisExtRtc from register */
#define  RF_DCDC_VTHNRG_EXT_RTC_SHIFT                       1                             /**< Shift for RfDcdcVthnrgExtRtc */
#define  RF_DCDC_VTHNRG_EXT_RTC_MASK                        0x00000006u                   /**< Mask for RfDcdcVthnrgExtRtc */
#define  RF_DCDC_VTHNRG_EXT_RTC_BMASK                       0x3u                          /**< Base mask for RfDcdcVthnrgExtRtc */
#define  RF_DCDC_VTHNRG_EXT_RTC(x)                          (((x)&0x3u)<<1)               /**< Set RfDcdcVthnrgExtRtc in register */
#define  GET_RF_DCDC_VTHNRG_EXT_RTC(reg)                    (((reg)>>1)&0x3u)             /**< Get RfDcdcVthnrgExtRtc from register */
#define  RF_DCDC_VTHDMPSW_EXT_RTC_SHIFT                     3                             /**< Shift for RfDcdcVthdmpswExtRtc */
#define  RF_DCDC_VTHDMPSW_EXT_RTC_MASK                      0x00000018u                   /**< Mask for RfDcdcVthdmpswExtRtc */
#define  RF_DCDC_VTHDMPSW_EXT_RTC_BMASK                     0x3u                          /**< Base mask for RfDcdcVthdmpswExtRtc */
#define  RF_DCDC_VTHDMPSW_EXT_RTC(x)                        (((x)&0x3u)<<3)               /**< Set RfDcdcVthdmpswExtRtc in register */
#define  GET_RF_DCDC_VTHDMPSW_EXT_RTC(reg)                  (((reg)>>3)&0x3u)             /**< Get RfDcdcVthdmpswExtRtc from register */
#define  RF_DCDC_VTHDMP_EXT_RTC_SHIFT                       5                             /**< Shift for RfDcdcVthdmpExtRtc */
#define  RF_DCDC_VTHDMP_EXT_RTC_MASK                        0x00000060u                   /**< Mask for RfDcdcVthdmpExtRtc */
#define  RF_DCDC_VTHDMP_EXT_RTC_BMASK                       0x3u                          /**< Base mask for RfDcdcVthdmpExtRtc */
#define  RF_DCDC_VTHDMP_EXT_RTC(x)                          (((x)&0x3u)<<5)               /**< Set RfDcdcVthdmpExtRtc in register */
#define  GET_RF_DCDC_VTHDMP_EXT_RTC(reg)                    (((reg)>>5)&0x3u)             /**< Get RfDcdcVthdmpExtRtc from register */
#define  RF_DCDC_FORCE_SWGND_EN_EXT_RTC_SHIFT               7                             /**< Shift for RfDcdcForceSwgndEnExtRtc */
#define  RF_DCDC_FORCE_SWGND_EN_EXT_RTC_MASK                0x00000080u                   /**< Mask for RfDcdcForceSwgndEnExtRtc */
#define  RF_DCDC_FORCE_SWGND_EN_EXT_RTC_BMASK               0x1u                          /**< Base mask for RfDcdcForceSwgndEnExtRtc */
#define  RF_DCDC_FORCE_SWGND_EN_EXT_RTC(x)                  (((x)&0x1u)<<7)               /**< Set RfDcdcForceSwgndEnExtRtc in register */
#define  GET_RF_DCDC_FORCE_SWGND_EN_EXT_RTC(reg)            (((reg)>>7)&0x1u)             /**< Get RfDcdcForceSwgndEnExtRtc from register */
#define  RF_DCDC_FORCE_SWGND_VAL_EXT_RTC_SHIFT              8                             /**< Shift for RfDcdcForceSwgndValExtRtc */
#define  RF_DCDC_FORCE_SWGND_VAL_EXT_RTC_MASK               0x00000100u                   /**< Mask for RfDcdcForceSwgndValExtRtc */
#define  RF_DCDC_FORCE_SWGND_VAL_EXT_RTC_BMASK              0x1u                          /**< Base mask for RfDcdcForceSwgndValExtRtc */
#define  RF_DCDC_FORCE_SWGND_VAL_EXT_RTC(x)                 (((x)&0x1u)<<8)               /**< Set RfDcdcForceSwgndValExtRtc in register */
#define  GET_RF_DCDC_FORCE_SWGND_VAL_EXT_RTC(reg)           (((reg)>>8)&0x1u)             /**< Get RfDcdcForceSwgndValExtRtc from register */
#define  RF_DCDC_FORCE_SWIN_EN_EXT_RTC_SHIFT                9                             /**< Shift for RfDcdcForceSwinEnExtRtc */
#define  RF_DCDC_FORCE_SWIN_EN_EXT_RTC_MASK                 0x00000200u                   /**< Mask for RfDcdcForceSwinEnExtRtc */
#define  RF_DCDC_FORCE_SWIN_EN_EXT_RTC_BMASK                0x1u                          /**< Base mask for RfDcdcForceSwinEnExtRtc */
#define  RF_DCDC_FORCE_SWIN_EN_EXT_RTC(x)                   (((x)&0x1u)<<9)               /**< Set RfDcdcForceSwinEnExtRtc in register */
#define  GET_RF_DCDC_FORCE_SWIN_EN_EXT_RTC(reg)             (((reg)>>9)&0x1u)             /**< Get RfDcdcForceSwinEnExtRtc from register */
#define  RF_DCDC_FORCE_SWIN_VAL_EXT_RTC_SHIFT               10                            /**< Shift for RfDcdcForceSwinValExtRtc */
#define  RF_DCDC_FORCE_SWIN_VAL_EXT_RTC_MASK                0x00000400u                   /**< Mask for RfDcdcForceSwinValExtRtc */
#define  RF_DCDC_FORCE_SWIN_VAL_EXT_RTC_BMASK               0x1u                          /**< Base mask for RfDcdcForceSwinValExtRtc */
#define  RF_DCDC_FORCE_SWIN_VAL_EXT_RTC(x)                  (((x)&0x1u)<<10)              /**< Set RfDcdcForceSwinValExtRtc in register */
#define  GET_RF_DCDC_FORCE_SWIN_VAL_EXT_RTC(reg)            (((reg)>>10)&0x1u)            /**< Get RfDcdcForceSwinValExtRtc from register */
#define  RF_DCDC_FORCE_PH_EN_EXT_RTC_SHIFT                  11                            /**< Shift for RfDcdcForcePhEnExtRtc */
#define  RF_DCDC_FORCE_PH_EN_EXT_RTC_MASK                   0x00000800u                   /**< Mask for RfDcdcForcePhEnExtRtc */
#define  RF_DCDC_FORCE_PH_EN_EXT_RTC_BMASK                  0x1u                          /**< Base mask for RfDcdcForcePhEnExtRtc */
#define  RF_DCDC_FORCE_PH_EN_EXT_RTC(x)                     (((x)&0x1u)<<11)              /**< Set RfDcdcForcePhEnExtRtc in register */
#define  GET_RF_DCDC_FORCE_PH_EN_EXT_RTC(reg)               (((reg)>>11)&0x1u)            /**< Get RfDcdcForcePhEnExtRtc from register */
#define  RF_DCDC_FORCE_PH_VAL_EXT_RTC_SHIFT                 12                            /**< Shift for RfDcdcForcePhValExtRtc */
#define  RF_DCDC_FORCE_PH_VAL_EXT_RTC_MASK                  0x00003000u                   /**< Mask for RfDcdcForcePhValExtRtc */
#define  RF_DCDC_FORCE_PH_VAL_EXT_RTC_BMASK                 0x3u                          /**< Base mask for RfDcdcForcePhValExtRtc */
#define  RF_DCDC_FORCE_PH_VAL_EXT_RTC(x)                    (((x)&0x3u)<<12)              /**< Set RfDcdcForcePhValExtRtc in register */
#define  GET_RF_DCDC_FORCE_PH_VAL_EXT_RTC(reg)              (((reg)>>12)&0x3u)            /**< Get RfDcdcForcePhValExtRtc from register */
/** @} */


/**
 * @name RegRfDcdcDiag
 * @{
 */
// RegRfDcdcDiag.r32
#define  REG_RF_DCDC_DIAG_RESET_VALUE                       0x00000000u                   /**< Reset value of RegRfDcdcDiag */
#define  REG_RF_DCDC_DIAG_MASK                              0x00000FFFu                   /**< Mask for RegRfDcdcDiag */

#define  RF_DCDC_DIAG_CODE_EXT_RTC_SHIFT                    0                             /**< Shift for RfDcdcDiagCodeExtRtc */
#define  RF_DCDC_DIAG_CODE_EXT_RTC_MASK                     0x00000007u                   /**< Mask for RfDcdcDiagCodeExtRtc */
#define  RF_DCDC_DIAG_CODE_EXT_RTC_BMASK                    0x7u                          /**< Base mask for RfDcdcDiagCodeExtRtc */
#define  RF_DCDC_DIAG_CODE_EXT_RTC(x)                       (((x)&0x7u)<<0)               /**< Set RfDcdcDiagCodeExtRtc in register */
#define  GET_RF_DCDC_DIAG_CODE_EXT_RTC(reg)                 (((reg)>>0)&0x7u)             /**< Get RfDcdcDiagCodeExtRtc from register */
#define  RF_DCDC_DIAG_VOUTSNS_EXT_RTC_SHIFT                 3                             /**< Shift for RfDcdcDiagVoutsnsExtRtc */
#define  RF_DCDC_DIAG_VOUTSNS_EXT_RTC_MASK                  0x00000008u                   /**< Mask for RfDcdcDiagVoutsnsExtRtc */
#define  RF_DCDC_DIAG_VOUTSNS_EXT_RTC_BMASK                 0x1u                          /**< Base mask for RfDcdcDiagVoutsnsExtRtc */
#define  RF_DCDC_DIAG_VOUTSNS_EXT_RTC(x)                    (((x)&0x1u)<<3)               /**< Set RfDcdcDiagVoutsnsExtRtc in register */
#define  GET_RF_DCDC_DIAG_VOUTSNS_EXT_RTC(reg)              (((reg)>>3)&0x1u)             /**< Get RfDcdcDiagVoutsnsExtRtc from register */
#define  RF_DCDC_DIAG_BG_EXT_RTC_SHIFT                      4                             /**< Shift for RfDcdcDiagBgExtRtc */
#define  RF_DCDC_DIAG_BG_EXT_RTC_MASK                       0x00000010u                   /**< Mask for RfDcdcDiagBgExtRtc */
#define  RF_DCDC_DIAG_BG_EXT_RTC_BMASK                      0x1u                          /**< Base mask for RfDcdcDiagBgExtRtc */
#define  RF_DCDC_DIAG_BG_EXT_RTC(x)                         (((x)&0x1u)<<4)               /**< Set RfDcdcDiagBgExtRtc in register */
#define  GET_RF_DCDC_DIAG_BG_EXT_RTC(reg)                   (((reg)>>4)&0x1u)             /**< Get RfDcdcDiagBgExtRtc from register */
#define  RF_DCDC_DIAG_IBIAS_EXT_RTC_SHIFT                   5                             /**< Shift for RfDcdcDiagIbiasExtRtc */
#define  RF_DCDC_DIAG_IBIAS_EXT_RTC_MASK                    0x00000020u                   /**< Mask for RfDcdcDiagIbiasExtRtc */
#define  RF_DCDC_DIAG_IBIAS_EXT_RTC_BMASK                   0x1u                          /**< Base mask for RfDcdcDiagIbiasExtRtc */
#define  RF_DCDC_DIAG_IBIAS_EXT_RTC(x)                      (((x)&0x1u)<<5)               /**< Set RfDcdcDiagIbiasExtRtc in register */
#define  GET_RF_DCDC_DIAG_IBIAS_EXT_RTC(reg)                (((reg)>>5)&0x1u)             /**< Get RfDcdcDiagIbiasExtRtc from register */
#define  RF_DCDC_DIAG_TIMER_EXT_RTC_SHIFT                   6                             /**< Shift for RfDcdcDiagTimerExtRtc */
#define  RF_DCDC_DIAG_TIMER_EXT_RTC_MASK                    0x00000040u                   /**< Mask for RfDcdcDiagTimerExtRtc */
#define  RF_DCDC_DIAG_TIMER_EXT_RTC_BMASK                   0x1u                          /**< Base mask for RfDcdcDiagTimerExtRtc */
#define  RF_DCDC_DIAG_TIMER_EXT_RTC(x)                      (((x)&0x1u)<<6)               /**< Set RfDcdcDiagTimerExtRtc in register */
#define  GET_RF_DCDC_DIAG_TIMER_EXT_RTC(reg)                (((reg)>>6)&0x1u)             /**< Get RfDcdcDiagTimerExtRtc from register */
#define  RF_DCDC_DIAG_TNRGTDMP_EXT_RTC_SHIFT                7                             /**< Shift for RfDcdcDiagTnrgtdmpExtRtc */
#define  RF_DCDC_DIAG_TNRGTDMP_EXT_RTC_MASK                 0x00000780u                   /**< Mask for RfDcdcDiagTnrgtdmpExtRtc */
#define  RF_DCDC_DIAG_TNRGTDMP_EXT_RTC_BMASK                0xFu                          /**< Base mask for RfDcdcDiagTnrgtdmpExtRtc */
#define  RF_DCDC_DIAG_TNRGTDMP_EXT_RTC(x)                   (((x)&0xFu)<<7)               /**< Set RfDcdcDiagTnrgtdmpExtRtc in register */
#define  GET_RF_DCDC_DIAG_TNRGTDMP_EXT_RTC(reg)             (((reg)>>7)&0xFu)             /**< Get RfDcdcDiagTnrgtdmpExtRtc from register */
#define  RF_DCDC_DIAGD_RST_STICKY_EXT_RTC_SHIFT             11                            /**< Shift for RfDcdcDiagdRstStickyExtRtc */
#define  RF_DCDC_DIAGD_RST_STICKY_EXT_RTC_MASK              0x00000800u                   /**< Mask for RfDcdcDiagdRstStickyExtRtc */
#define  RF_DCDC_DIAGD_RST_STICKY_EXT_RTC_BMASK             0x1u                          /**< Base mask for RfDcdcDiagdRstStickyExtRtc */
#define  RF_DCDC_DIAGD_RST_STICKY_EXT_RTC(x)                (((x)&0x1u)<<11)              /**< Set RfDcdcDiagdRstStickyExtRtc in register */
#define  GET_RF_DCDC_DIAGD_RST_STICKY_EXT_RTC(reg)          (((reg)>>11)&0x1u)            /**< Get RfDcdcDiagdRstStickyExtRtc from register */
/** @} */


/**
 * @name RegRfXo32K
 * @{
 */
// RegRfXo32K.r32
#define  REG_RF_XO32K_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRfXo32K */
#define  REG_RF_XO32K_MASK                                  0x000003FFu                   /**< Mask for RegRfXo32K */

#define  RF_XO32K_PUP_RTC_SHIFT                             0                             /**< Shift for RfXo32KPupRtc */
#define  RF_XO32K_PUP_RTC_MASK                              0x00000001u                   /**< Mask for RfXo32KPupRtc */
#define  RF_XO32K_PUP_RTC_BMASK                             0x1u                          /**< Base mask for RfXo32KPupRtc */
#define  RF_XO32K_PUP_RTC(x)                                (((x)&0x1u)<<0)               /**< Set RfXo32KPupRtc in register */
#define  GET_RF_XO32K_PUP_RTC(reg)                          (((reg)>>0)&0x1u)             /**< Get RfXo32KPupRtc from register */
#define  RF_XO32K_ISEL_RTC_SHIFT                            1                             /**< Shift for RfXo32KIselRtc */
#define  RF_XO32K_ISEL_RTC_MASK                             0x00000006u                   /**< Mask for RfXo32KIselRtc */
#define  RF_XO32K_ISEL_RTC_BMASK                            0x3u                          /**< Base mask for RfXo32KIselRtc */
#define  RF_XO32K_ISEL_RTC(x)                               (((x)&0x3u)<<1)               /**< Set RfXo32KIselRtc in register */
#define  GET_RF_XO32K_ISEL_RTC(reg)                         (((reg)>>1)&0x3u)             /**< Get RfXo32KIselRtc from register */
#define  RF_XO32K_CDAC_RTC_SHIFT                            3                             /**< Shift for RfXo32KCdacRtc */
#define  RF_XO32K_CDAC_RTC_MASK                             0x00000038u                   /**< Mask for RfXo32KCdacRtc */
#define  RF_XO32K_CDAC_RTC_BMASK                            0x7u                          /**< Base mask for RfXo32KCdacRtc */
#define  RF_XO32K_CDAC_RTC(x)                               (((x)&0x7u)<<3)               /**< Set RfXo32KCdacRtc in register */
#define  GET_RF_XO32K_CDAC_RTC(reg)                         (((reg)>>3)&0x7u)             /**< Get RfXo32KCdacRtc from register */
#define  RF_XO32K_FORCE_RTC_SHIFT                           6                             /**< Shift for RfXo32KForceRtc */
#define  RF_XO32K_FORCE_RTC_MASK                            0x00000040u                   /**< Mask for RfXo32KForceRtc */
#define  RF_XO32K_FORCE_RTC_BMASK                           0x1u                          /**< Base mask for RfXo32KForceRtc */
#define  RF_XO32K_FORCE_RTC(x)                              (((x)&0x1u)<<6)               /**< Set RfXo32KForceRtc in register */
#define  GET_RF_XO32K_FORCE_RTC(reg)                        (((reg)>>6)&0x1u)             /**< Get RfXo32KForceRtc from register */
#define  RF_XO32K_EN_DRV_RTC_SHIFT                          7                             /**< Shift for RfXo32KEnDrvRtc */
#define  RF_XO32K_EN_DRV_RTC_MASK                           0x00000080u                   /**< Mask for RfXo32KEnDrvRtc */
#define  RF_XO32K_EN_DRV_RTC_BMASK                          0x1u                          /**< Base mask for RfXo32KEnDrvRtc */
#define  RF_XO32K_EN_DRV_RTC(x)                             (((x)&0x1u)<<7)               /**< Set RfXo32KEnDrvRtc in register */
#define  GET_RF_XO32K_EN_DRV_RTC(reg)                       (((reg)>>7)&0x1u)             /**< Get RfXo32KEnDrvRtc from register */
#define  RF_XO32K_SPARE_RTC_SHIFT                           8                             /**< Shift for RfXo32KSpareRtc */
#define  RF_XO32K_SPARE_RTC_MASK                            0x00000300u                   /**< Mask for RfXo32KSpareRtc */
#define  RF_XO32K_SPARE_RTC_BMASK                           0x3u                          /**< Base mask for RfXo32KSpareRtc */
#define  RF_XO32K_SPARE_RTC(x)                              (((x)&0x3u)<<8)               /**< Set RfXo32KSpareRtc in register */
#define  GET_RF_XO32K_SPARE_RTC(reg)                        (((reg)>>8)&0x3u)             /**< Get RfXo32KSpareRtc from register */
/** @} */


/**
 * @name RegRfRo32K
 * @{
 */
// RegRfRo32K.r32
#define  REG_RF_RO32K_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRfRo32K */
#define  REG_RF_RO32K_MASK                                  0x00001FFFu                   /**< Mask for RegRfRo32K */

#define  RF_RO32K_PUP_RTC_SHIFT                             0                             /**< Shift for RfRo32KPupRtc */
#define  RF_RO32K_PUP_RTC_MASK                              0x00000001u                   /**< Mask for RfRo32KPupRtc */
#define  RF_RO32K_PUP_RTC_BMASK                             0x1u                          /**< Base mask for RfRo32KPupRtc */
#define  RF_RO32K_PUP_RTC(x)                                (((x)&0x1u)<<0)               /**< Set RfRo32KPupRtc in register */
#define  GET_RF_RO32K_PUP_RTC(reg)                          (((reg)>>0)&0x1u)             /**< Get RfRo32KPupRtc from register */
#define  RF_RO32K_TRIM_FINE_RTC_SHIFT                       1                             /**< Shift for RfRo32KTrimFineRtc */
#define  RF_RO32K_TRIM_FINE_RTC_MASK                        0x00000006u                   /**< Mask for RfRo32KTrimFineRtc */
#define  RF_RO32K_TRIM_FINE_RTC_BMASK                       0x3u                          /**< Base mask for RfRo32KTrimFineRtc */
#define  RF_RO32K_TRIM_FINE_RTC(x)                          (((x)&0x3u)<<1)               /**< Set RfRo32KTrimFineRtc in register */
#define  GET_RF_RO32K_TRIM_FINE_RTC(reg)                    (((reg)>>1)&0x3u)             /**< Get RfRo32KTrimFineRtc from register */
#define  RF_RO32K_TRIM_RTC_SHIFT                            3                             /**< Shift for RfRo32KTrimRtc */
#define  RF_RO32K_TRIM_RTC_MASK                             0x000001F8u                   /**< Mask for RfRo32KTrimRtc */
#define  RF_RO32K_TRIM_RTC_BMASK                            0x3Fu                         /**< Base mask for RfRo32KTrimRtc */
#define  RF_RO32K_TRIM_RTC(x)                               (((x)&0x3Fu)<<3)              /**< Set RfRo32KTrimRtc in register */
#define  GET_RF_RO32K_TRIM_RTC(reg)                         (((reg)>>3)&0x3Fu)            /**< Get RfRo32KTrimRtc from register */
#define  RF_RO32K_SPARE_RTC_SHIFT                           9                             /**< Shift for RfRo32KSpareRtc */
#define  RF_RO32K_SPARE_RTC_MASK                            0x00000200u                   /**< Mask for RfRo32KSpareRtc */
#define  RF_RO32K_SPARE_RTC_BMASK                           0x1u                          /**< Base mask for RfRo32KSpareRtc */
#define  RF_RO32K_SPARE_RTC(x)                              (((x)&0x1u)<<9)               /**< Set RfRo32KSpareRtc in register */
#define  GET_RF_RO32K_SPARE_RTC(reg)                        (((reg)>>9)&0x1u)             /**< Get RfRo32KSpareRtc from register */
#define  RF_DCDC_SPARE2_EXT_RTC_SHIFT                       10                            /**< Shift for RfDcdcSpare2ExtRtc */
#define  RF_DCDC_SPARE2_EXT_RTC_MASK                        0x00001C00u                   /**< Mask for RfDcdcSpare2ExtRtc */
#define  RF_DCDC_SPARE2_EXT_RTC_BMASK                       0x7u                          /**< Base mask for RfDcdcSpare2ExtRtc */
#define  RF_DCDC_SPARE2_EXT_RTC(x)                          (((x)&0x7u)<<10)              /**< Set RfDcdcSpare2ExtRtc in register */
#define  GET_RF_DCDC_SPARE2_EXT_RTC(reg)                    (((reg)>>10)&0x7u)            /**< Get RfDcdcSpare2ExtRtc from register */
/** @} */


/**
 * @name RegRfDiagMisctop
 * @{
 */
// RegRfDiagMisctop.r32
#define  REG_RF_DIAG_MISCTOP_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfDiagMisctop */
#define  REG_RF_DIAG_MISCTOP_MASK                           0x000001FFu                   /**< Mask for RegRfDiagMisctop */

#define  RF_DIAG_CODE_RTC_SHIFT                             0                             /**< Shift for RfDiagCodeRtc */
#define  RF_DIAG_CODE_RTC_MASK                              0x00000007u                   /**< Mask for RfDiagCodeRtc */
#define  RF_DIAG_CODE_RTC_BMASK                             0x7u                          /**< Base mask for RfDiagCodeRtc */
#define  RF_DIAG_CODE_RTC(x)                                (((x)&0x7u)<<0)               /**< Set RfDiagCodeRtc in register */
#define  GET_RF_DIAG_CODE_RTC(reg)                          (((reg)>>0)&0x7u)             /**< Get RfDiagCodeRtc from register */
#define  RF_DIAG_SEL_XO_RTC_SHIFT                           3                             /**< Shift for RfDiagSelXoRtc */
#define  RF_DIAG_SEL_XO_RTC_MASK                            0x00000008u                   /**< Mask for RfDiagSelXoRtc */
#define  RF_DIAG_SEL_XO_RTC_BMASK                           0x1u                          /**< Base mask for RfDiagSelXoRtc */
#define  RF_DIAG_SEL_XO_RTC(x)                              (((x)&0x1u)<<3)               /**< Set RfDiagSelXoRtc in register */
#define  GET_RF_DIAG_SEL_XO_RTC(reg)                        (((reg)>>3)&0x1u)             /**< Get RfDiagSelXoRtc from register */
#define  RF_DIAG_SEL_RO_RTC_SHIFT                           4                             /**< Shift for RfDiagSelRoRtc */
#define  RF_DIAG_SEL_RO_RTC_MASK                            0x00000010u                   /**< Mask for RfDiagSelRoRtc */
#define  RF_DIAG_SEL_RO_RTC_BMASK                           0x1u                          /**< Base mask for RfDiagSelRoRtc */
#define  RF_DIAG_SEL_RO_RTC(x)                              (((x)&0x1u)<<4)               /**< Set RfDiagSelRoRtc in register */
#define  GET_RF_DIAG_SEL_RO_RTC(reg)                        (((reg)>>4)&0x1u)             /**< Get RfDiagSelRoRtc from register */
#define  RF_DIAG_DIS_RTC_SHIFT                              5                             /**< Shift for RfDiagDisRtc */
#define  RF_DIAG_DIS_RTC_MASK                               0x00000020u                   /**< Mask for RfDiagDisRtc */
#define  RF_DIAG_DIS_RTC_BMASK                              0x1u                          /**< Base mask for RfDiagDisRtc */
#define  RF_DIAG_DIS_RTC(x)                                 (((x)&0x1u)<<5)               /**< Set RfDiagDisRtc in register */
#define  GET_RF_DIAG_DIS_RTC(reg)                           (((reg)>>5)&0x1u)             /**< Get RfDiagDisRtc from register */
#define  RF_EN_DIAG_PAD_RTC_SHIFT                           6                             /**< Shift for RfEnDiagPadRtc */
#define  RF_EN_DIAG_PAD_RTC_MASK                            0x00000040u                   /**< Mask for RfEnDiagPadRtc */
#define  RF_EN_DIAG_PAD_RTC_BMASK                           0x1u                          /**< Base mask for RfEnDiagPadRtc */
#define  RF_EN_DIAG_PAD_RTC(x)                              (((x)&0x1u)<<6)               /**< Set RfEnDiagPadRtc in register */
#define  GET_RF_EN_DIAG_PAD_RTC(reg)                        (((reg)>>6)&0x1u)             /**< Get RfEnDiagPadRtc from register */
#define  RF_SPARE_RTC_SHIFT                                 7                             /**< Shift for RfSpareRtc */
#define  RF_SPARE_RTC_MASK                                  0x00000180u                   /**< Mask for RfSpareRtc */
#define  RF_SPARE_RTC_BMASK                                 0x3u                          /**< Base mask for RfSpareRtc */
#define  RF_SPARE_RTC(x)                                    (((x)&0x3u)<<7)               /**< Set RfSpareRtc in register */
#define  GET_RF_SPARE_RTC(reg)                              (((reg)>>7)&0x3u)             /**< Get RfSpareRtc from register */
/** @} */


/**
 * @name RegRfMemAddr
 * @{
 */
// RegRfMemAddr.r32
#define  REG_RF_MEM_ADDR_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfMemAddr */
#define  REG_RF_MEM_ADDR_MASK                               0x000003FFu                   /**< Mask for RegRfMemAddr */

#define  RF_MEM_ADDR_SHIFT                                  0                             /**< Shift for RfMemAddr */
#define  RF_MEM_ADDR_MASK                                   0x000003FFu                   /**< Mask for RfMemAddr */
#define  RF_MEM_ADDR_BMASK                                  0x3FFu                        /**< Base mask for RfMemAddr */
#define  RF_MEM_ADDR(x)                                     (((x)&0x3FFu)<<0)             /**< Set RfMemAddr in register */
#define  GET_RF_MEM_ADDR(reg)                               (((reg)>>0)&0x3FFu)           /**< Get RfMemAddr from register */
/** @} */


/**
 * @name RegRfMemDataIpath
 * @{
 */
// RegRfMemDataIpath.r32
#define  REG_RF_MEM_DATA_IPATH_RESET_VALUE                  0x00000000u                   /**< Reset value of RegRfMemDataIpath */
#define  REG_RF_MEM_DATA_IPATH_MASK                         0x000007FFu                   /**< Mask for RegRfMemDataIpath */

#define  RF_MEM_DATA_IPATH_SHIFT                            0                             /**< Shift for RfMemDataIpath */
#define  RF_MEM_DATA_IPATH_MASK                             0x000007FFu                   /**< Mask for RfMemDataIpath */
#define  RF_MEM_DATA_IPATH_BMASK                            0x7FFu                        /**< Base mask for RfMemDataIpath */
#define  RF_MEM_DATA_IPATH(x)                               (((x)&0x7FFu)<<0)             /**< Set RfMemDataIpath in register */
#define  GET_RF_MEM_DATA_IPATH(reg)                         (((reg)>>0)&0x7FFu)           /**< Get RfMemDataIpath from register */
/** @} */


/**
 * @name RegRfDbgCtrl
 * @{
 */
// RegRfDbgCtrl.r32
#define  REG_RF_DBG_CTRL_RESET_VALUE                        0x00000000u                   /**< Reset value of RegRfDbgCtrl */
#define  REG_RF_DBG_CTRL_MASK                               0x0000001Fu                   /**< Mask for RegRfDbgCtrl */

#define  RF_MEM_ADDR_AUTO_INCR_SHIFT                        0                             /**< Shift for RfMemAddrAutoIncr */
#define  RF_MEM_ADDR_AUTO_INCR_MASK                         0x00000001u                   /**< Mask for RfMemAddrAutoIncr */
#define  RF_MEM_ADDR_AUTO_INCR_BMASK                        0x1u                          /**< Base mask for RfMemAddrAutoIncr */
#define  RF_MEM_ADDR_AUTO_INCR(x)                           (((x)&0x1u)<<0)               /**< Set RfMemAddrAutoIncr in register */
#define  GET_RF_MEM_ADDR_AUTO_INCR(reg)                     (((reg)>>0)&0x1u)             /**< Get RfMemAddrAutoIncr from register */
#define  RF_DBG_TOP_CTRL_SHIFT                              1                             /**< Shift for RfDbgTopCtrl */
#define  RF_DBG_TOP_CTRL_MASK                               0x0000000Eu                   /**< Mask for RfDbgTopCtrl */
#define  RF_DBG_TOP_CTRL_BMASK                              0x7u                          /**< Base mask for RfDbgTopCtrl */
#define  RF_DBG_TOP_CTRL(x)                                 (((x)&0x7u)<<1)               /**< Set RfDbgTopCtrl in register */
#define  GET_RF_DBG_TOP_CTRL(reg)                           (((reg)>>1)&0x7u)             /**< Get RfDbgTopCtrl from register */
#define  RF_DBG_CLK_INV_SHIFT                               4                             /**< Shift for RfDbgClkInv */
#define  RF_DBG_CLK_INV_MASK                                0x00000010u                   /**< Mask for RfDbgClkInv */
#define  RF_DBG_CLK_INV_BMASK                               0x1u                          /**< Base mask for RfDbgClkInv */
#define  RF_DBG_CLK_INV(x)                                  (((x)&0x1u)<<4)               /**< Set RfDbgClkInv in register */
#define  GET_RF_DBG_CLK_INV(reg)                            (((reg)>>4)&0x1u)             /**< Get RfDbgClkInv from register */
/** @} */


/**
 * @name RegRfStartAddr
 * @{
 */
// RegRfStartAddr.r32
#define  REG_RF_START_ADDR_RESET_VALUE                      0x00000000u                   /**< Reset value of RegRfStartAddr */
#define  REG_RF_START_ADDR_MASK                             0x000003FFu                   /**< Mask for RegRfStartAddr */

#define  RF_START_ADDR_SHIFT                                0                             /**< Shift for RfStartAddr */
#define  RF_START_ADDR_MASK                                 0x000003FFu                   /**< Mask for RfStartAddr */
#define  RF_START_ADDR_BMASK                                0x3FFu                        /**< Base mask for RfStartAddr */
#define  RF_START_ADDR(x)                                   (((x)&0x3FFu)<<0)             /**< Set RfStartAddr in register */
#define  GET_RF_START_ADDR(reg)                             (((reg)>>0)&0x3FFu)           /**< Get RfStartAddr from register */
/** @} */


/**
 * @name RegRfStopAddr
 * @{
 */
// RegRfStopAddr.r32
#define  REG_RF_STOP_ADDR_RESET_VALUE                       0x000003FFu                   /**< Reset value of RegRfStopAddr */
#define  REG_RF_STOP_ADDR_MASK                              0x000003FFu                   /**< Mask for RegRfStopAddr */

#define  RF_STOP_ADDR_SHIFT                                 0                             /**< Shift for RfStopAddr */
#define  RF_STOP_ADDR_MASK                                  0x000003FFu                   /**< Mask for RfStopAddr */
#define  RF_STOP_ADDR_BMASK                                 0x3FFu                        /**< Base mask for RfStopAddr */
#define  RF_STOP_ADDR(x)                                    (((x)&0x3FFu)<<0)             /**< Set RfStopAddr in register */
#define  GET_RF_STOP_ADDR(reg)                              (((reg)>>0)&0x3FFu)           /**< Get RfStopAddr from register */
/** @} */


/**
 * @name RegRfMemDataQpath
 * @{
 */
// RegRfMemDataQpath.r32
#define  REG_RF_MEM_DATA_QPATH_RESET_VALUE                  0x00000000u                   /**< Reset value of RegRfMemDataQpath */
#define  REG_RF_MEM_DATA_QPATH_MASK                         0x000007FFu                   /**< Mask for RegRfMemDataQpath */

#define  RF_MEM_DATA_QPATH_SHIFT                            0                             /**< Shift for RfMemDataQpath */
#define  RF_MEM_DATA_QPATH_MASK                             0x000007FFu                   /**< Mask for RfMemDataQpath */
#define  RF_MEM_DATA_QPATH_BMASK                            0x7FFu                        /**< Base mask for RfMemDataQpath */
#define  RF_MEM_DATA_QPATH(x)                               (((x)&0x7FFu)<<0)             /**< Set RfMemDataQpath in register */
#define  GET_RF_MEM_DATA_QPATH(reg)                         (((reg)>>0)&0x7FFu)           /**< Get RfMemDataQpath from register */
/** @} */


/**
 * @name RegRfStrobeDelay
 * @{
 */
// RegRfStrobeDelay.r32
#define  REG_RF_STROBE_DELAY_RESET_VALUE                    0x00000000u                   /**< Reset value of RegRfStrobeDelay */
#define  REG_RF_STROBE_DELAY_MASK                           0x000003FFu                   /**< Mask for RegRfStrobeDelay */

#define  RF_STROBE_DELAY_SHIFT                              0                             /**< Shift for RfStrobeDelay */
#define  RF_STROBE_DELAY_MASK                               0x000003FFu                   /**< Mask for RfStrobeDelay */
#define  RF_STROBE_DELAY_BMASK                              0x3FFu                        /**< Base mask for RfStrobeDelay */
#define  RF_STROBE_DELAY(x)                                 (((x)&0x3FFu)<<0)             /**< Set RfStrobeDelay in register */
#define  GET_RF_STROBE_DELAY(reg)                           (((reg)>>0)&0x3FFu)           /**< Get RfStrobeDelay from register */
/** @} */



/** @} End of group Radio_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_RADIO_H */
