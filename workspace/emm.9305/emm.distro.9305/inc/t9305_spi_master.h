////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_spi_master.h
///
/// @project    T9305
///
/// @brief      SPI Master register and bit field definitions
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

#ifndef _T9305_SPI_MASTER_H
#define _T9305_SPI_MASTER_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup SPIMaster_Registers SPI Master Register Map - registers
 * @{
 ******************************************************************************/


/** SPI master configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMCfg_t;


/** SPI master control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMCtrl_t;


/** SPI master status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMStat_t;


/** SPI Master command to transmit - it may include command and/or target address */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMTxCmd_t;


/** SPI Master transmit buffer bytes 0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMTxBuffer0_t;


/** SPI Master transmit buffer bytes 4-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMTxBuffer1_t;


/** SPI Master transmit buffer bytes 8-11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMTxBuffer2_t;


/** SPI Master transmit buffer bytes 12-15 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMTxBuffer3_t;


/** SPI Master data received during command sending */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMRxCmd_t;


/** SPI Master receive buffer bytes 0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMRxBuffer0_t;


/** SPI Master receive buffer bytes 4-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMRxBuffer1_t;


/** SPI Master receive buffer bytes 8-11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMRxBuffer2_t;


/** SPI Master receive buffer bytes 12-15 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPIMRxBuffer3_t;

/** @} end of group SPIMaster_Regs */



/***************************************************************************//**
 * @defgroup SPIMaster_RegMap SPI Master Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegSPIMCfg_t                                      RegSPIMCfg;                   /**< SPI master configuration */
    __IO  RegSPIMCtrl_t                                     RegSPIMCtrl;                  /**< SPI master control */
    __I   RegSPIMStat_t                                     RegSPIMStat;                  /**< SPI master status */
    __IO  RegSPIMTxCmd_t                                    RegSPIMTxCmd;                 /**< SPI Master command to transmit - it may include command and/or target address */
    __IO  RegSPIMTxBuffer0_t                                RegSPIMTxBuffer0;             /**< SPI Master transmit buffer bytes 0-3 */
    __IO  RegSPIMTxBuffer1_t                                RegSPIMTxBuffer1;             /**< SPI Master transmit buffer bytes 4-7 */
    __IO  RegSPIMTxBuffer2_t                                RegSPIMTxBuffer2;             /**< SPI Master transmit buffer bytes 8-11 */
    __IO  RegSPIMTxBuffer3_t                                RegSPIMTxBuffer3;             /**< SPI Master transmit buffer bytes 12-15 */
    __I   RegSPIMRxCmd_t                                    RegSPIMRxCmd;                 /**< SPI Master data received during command sending */
    __I   RegSPIMRxBuffer0_t                                RegSPIMRxBuffer0;             /**< SPI Master receive buffer bytes 0-3 */
    __I   RegSPIMRxBuffer1_t                                RegSPIMRxBuffer1;             /**< SPI Master receive buffer bytes 4-7 */
    __I   RegSPIMRxBuffer2_t                                RegSPIMRxBuffer2;             /**< SPI Master receive buffer bytes 8-11 */
    __I   RegSPIMRxBuffer3_t                                RegSPIMRxBuffer3;             /**< SPI Master receive buffer bytes 12-15 */
} SPIMaster_RegMap_t;

/** @} end of group SPIMaster_RegMap */



/***************************************************************************//**
 * @defgroup SPIMaster_BitFields SPIMaster bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegSPIMCfg
 * @{
 */
// RegSPIMCfg.r32
#define  REG_SPIM_CFG_RESET_VALUE                           0x00000000u                   /**< Reset value of RegSPIMCfg */
#define  REG_SPIM_CFG_MASK                                  0x000101FFu                   /**< Mask for RegSPIMCfg */

#define  SPIM_CLOCK_SELECT_SHIFT                            0                             /**< Shift for SPIMClockSelect */
#define  SPIM_CLOCK_SELECT_MASK                             0x00000007u                   /**< Mask for SPIMClockSelect */
#define  SPIM_CLOCK_SELECT_BMASK                            0x7u                          /**< Base mask for SPIMClockSelect */
#define  SPIM_CLOCK_SELECT(x)                               (((x)&0x7u)<<0)               /**< Set SPIMClockSelect in register */
#define  GET_SPIM_CLOCK_SELECT(reg)                         (((reg)>>0)&0x7u)             /**< Get SPIMClockSelect from register */
#define  SPIM_CPHA_SHIFT                                    3                             /**< Shift for SPIMCPHA */
#define  SPIM_CPHA_MASK                                     0x00000008u                   /**< Mask for SPIMCPHA */
#define  SPIM_CPHA_BMASK                                    0x1u                          /**< Base mask for SPIMCPHA */
#define  SPIM_CPHA(x)                                       (((x)&0x1u)<<3)               /**< Set SPIMCPHA in register */
#define  GET_SPIM_CPHA(reg)                                 (((reg)>>3)&0x1u)             /**< Get SPIMCPHA from register */
#define  SPIM_CPOL_SHIFT                                    4                             /**< Shift for SPIMCPOL */
#define  SPIM_CPOL_MASK                                     0x00000010u                   /**< Mask for SPIMCPOL */
#define  SPIM_CPOL_BMASK                                    0x1u                          /**< Base mask for SPIMCPOL */
#define  SPIM_CPOL(x)                                       (((x)&0x1u)<<4)               /**< Set SPIMCPOL in register */
#define  GET_SPIM_CPOL(reg)                                 (((reg)>>4)&0x1u)             /**< Get SPIMCPOL from register */
#define  SPIM_MSB_FIRST_SHIFT                               5                             /**< Shift for SPIMMSBFirst */
#define  SPIM_MSB_FIRST_MASK                                0x00000020u                   /**< Mask for SPIMMSBFirst */
#define  SPIM_MSB_FIRST_BMASK                               0x1u                          /**< Base mask for SPIMMSBFirst */
#define  SPIM_MSB_FIRST(x)                                  (((x)&0x1u)<<5)               /**< Set SPIMMSBFirst in register */
#define  GET_SPIM_MSB_FIRST(reg)                            (((reg)>>5)&0x1u)             /**< Get SPIMMSBFirst from register */
#define  SPIM_ICFG_SHIFT                                    6                             /**< Shift for SPIMICfg */
#define  SPIM_ICFG_MASK                                     0x00000040u                   /**< Mask for SPIMICfg */
#define  SPIM_ICFG_BMASK                                    0x1u                          /**< Base mask for SPIMICfg */
#define  SPIM_ICFG(x)                                       (((x)&0x1u)<<6)               /**< Set SPIMICfg in register */
#define  GET_SPIM_ICFG(reg)                                 (((reg)>>6)&0x1u)             /**< Get SPIMICfg from register */
#define  SPIM_RXPHASE_SHIFT                                 7                             /**< Shift for SPIMRxPhase */
#define  SPIM_RXPHASE_MASK                                  0x00000080u                   /**< Mask for SPIMRxPhase */
#define  SPIM_RXPHASE_BMASK                                 0x1u                          /**< Base mask for SPIMRxPhase */
#define  SPIM_RXPHASE(x)                                    (((x)&0x1u)<<7)               /**< Set SPIMRxPhase in register */
#define  GET_SPIM_RXPHASE(reg)                              (((reg)>>7)&0x1u)             /**< Get SPIMRxPhase from register */
#define  SPIM_ENABLE_SHIFT                                  8                             /**< Shift for SPIMEnable */
#define  SPIM_ENABLE_MASK                                   0x00000100u                   /**< Mask for SPIMEnable */
#define  SPIM_ENABLE_BMASK                                  0x1u                          /**< Base mask for SPIMEnable */
#define  SPIM_ENABLE(x)                                     (((x)&0x1u)<<8)               /**< Set SPIMEnable in register */
#define  GET_SPIM_ENABLE(reg)                               (((reg)>>8)&0x1u)             /**< Get SPIMEnable from register */
#define  SPIM_RW_SEL_SHIFT                                  16                            /**< Shift for SPIMRwSel */
#define  SPIM_RW_SEL_MASK                                   0x00010000u                   /**< Mask for SPIMRwSel */
#define  SPIM_RW_SEL_BMASK                                  0x1u                          /**< Base mask for SPIMRwSel */
#define  SPIM_RW_SEL(x)                                     (((x)&0x1u)<<16)              /**< Set SPIMRwSel in register */
#define  GET_SPIM_RW_SEL(reg)                               (((reg)>>16)&0x1u)            /**< Get SPIMRwSel from register */
/** @} */


/**
 * @name RegSPIMCtrl
 * @{
 */
// RegSPIMCtrl.r32
#define  REG_SPIM_CTRL_RESET_VALUE                          0x00000000u                   /**< Reset value of RegSPIMCtrl */
#define  REG_SPIM_CTRL_MASK                                 0x8003071Fu                   /**< Mask for RegSPIMCtrl */

#define  SPIM_TRANS_LENGTH_SHIFT                            0                             /**< Shift for SPIMTransLength */
#define  SPIM_TRANS_LENGTH_MASK                             0x0000001Fu                   /**< Mask for SPIMTransLength */
#define  SPIM_TRANS_LENGTH_BMASK                            0x1Fu                         /**< Base mask for SPIMTransLength */
#define  SPIM_TRANS_LENGTH(x)                               (((x)&0x1Fu)<<0)              /**< Set SPIMTransLength in register */
#define  GET_SPIM_TRANS_LENGTH(reg)                         (((reg)>>0)&0x1Fu)            /**< Get SPIMTransLength from register */
#define  SPIM_CMD_LENGTH_SHIFT                              8                             /**< Shift for SPIMCmdLength */
#define  SPIM_CMD_LENGTH_MASK                               0x00000700u                   /**< Mask for SPIMCmdLength */
#define  SPIM_CMD_LENGTH_BMASK                              0x7u                          /**< Base mask for SPIMCmdLength */
#define  SPIM_CMD_LENGTH(x)                                 (((x)&0x7u)<<8)               /**< Set SPIMCmdLength in register */
#define  GET_SPIM_CMD_LENGTH(reg)                           (((reg)>>8)&0x7u)             /**< Get SPIMCmdLength from register */
#define  SPIM_START_TRANS_SHIFT                             16                            /**< Shift for SPIMStartTrans */
#define  SPIM_START_TRANS_MASK                              0x00010000u                   /**< Mask for SPIMStartTrans */
#define  SPIM_START_TRANS_BMASK                             0x1u                          /**< Base mask for SPIMStartTrans */
#define  SPIM_START_TRANS(x)                                (((x)&0x1u)<<16)              /**< Set SPIMStartTrans in register */
#define  GET_SPIM_START_TRANS(reg)                          (((reg)>>16)&0x1u)            /**< Get SPIMStartTrans from register */
#define  SPIM_STOP_TRANS_SHIFT                              17                            /**< Shift for SPIMStopTrans */
#define  SPIM_STOP_TRANS_MASK                               0x00020000u                   /**< Mask for SPIMStopTrans */
#define  SPIM_STOP_TRANS_BMASK                              0x1u                          /**< Base mask for SPIMStopTrans */
#define  SPIM_STOP_TRANS(x)                                 (((x)&0x1u)<<17)              /**< Set SPIMStopTrans in register */
#define  GET_SPIM_STOP_TRANS(reg)                           (((reg)>>17)&0x1u)            /**< Get SPIMStopTrans from register */
#define  SPIM_RESET_SHIFT                                   31                            /**< Shift for SPIMReset */
#define  SPIM_RESET_MASK                                    0x80000000u                   /**< Mask for SPIMReset */
#define  SPIM_RESET_BMASK                                   0x1u                          /**< Base mask for SPIMReset */
#define  SPIM_RESET(x)                                      (((x)&0x1u)<<31)              /**< Set SPIMReset in register */
#define  GET_SPIM_RESET(reg)                                (((reg)>>31)&0x1u)            /**< Get SPIMReset from register */
/** @} */


/**
 * @name RegSPIMStat
 * @{
 */
// RegSPIMStat.r32
#define  REG_SPIM_STAT_RESET_VALUE                          0x00000000u                   /**< Reset value of RegSPIMStat */
#define  REG_SPIM_STAT_MASK                                 0x3F071F17u                   /**< Mask for RegSPIMStat */

#define  SPIM_BUSY_SHIFT                                    0                             /**< Shift for SPIMBusy */
#define  SPIM_BUSY_MASK                                     0x00000001u                   /**< Mask for SPIMBusy */
#define  SPIM_BUSY_BMASK                                    0x1u                          /**< Base mask for SPIMBusy */
#define  SPIM_BUSY(x)                                       (((x)&0x1u)<<0)               /**< Set SPIMBusy in register */
#define  GET_SPIM_BUSY(reg)                                 (((reg)>>0)&0x1u)             /**< Get SPIMBusy from register */
#define  SPIM_CMD_SENT_SHIFT                                1                             /**< Shift for SPIMCmdSent */
#define  SPIM_CMD_SENT_MASK                                 0x00000002u                   /**< Mask for SPIMCmdSent */
#define  SPIM_CMD_SENT_BMASK                                0x1u                          /**< Base mask for SPIMCmdSent */
#define  SPIM_CMD_SENT(x)                                   (((x)&0x1u)<<1)               /**< Set SPIMCmdSent in register */
#define  GET_SPIM_CMD_SENT(reg)                             (((reg)>>1)&0x1u)             /**< Get SPIMCmdSent from register */
#define  SPIM_DATA_SENT_SHIFT                               2                             /**< Shift for SPIMDataSent */
#define  SPIM_DATA_SENT_MASK                                0x00000004u                   /**< Mask for SPIMDataSent */
#define  SPIM_DATA_SENT_BMASK                               0x1u                          /**< Base mask for SPIMDataSent */
#define  SPIM_DATA_SENT(x)                                  (((x)&0x1u)<<2)               /**< Set SPIMDataSent in register */
#define  GET_SPIM_DATA_SENT(reg)                            (((reg)>>2)&0x1u)             /**< Get SPIMDataSent from register */
#define  SPIM_STOP_TRANS_STS_SHIFT                          4                             /**< Shift for SPIMStopTransSts */
#define  SPIM_STOP_TRANS_STS_MASK                           0x00000010u                   /**< Mask for SPIMStopTransSts */
#define  SPIM_STOP_TRANS_STS_BMASK                          0x1u                          /**< Base mask for SPIMStopTransSts */
#define  SPIM_STOP_TRANS_STS(x)                             (((x)&0x1u)<<4)               /**< Set SPIMStopTransSts in register */
#define  GET_SPIM_STOP_TRANS_STS(reg)                       (((reg)>>4)&0x1u)             /**< Get SPIMStopTransSts from register */
#define  SPIM_TRANS_LENGTH_STS_SHIFT                        8                             /**< Shift for SPIMTransLengthSts */
#define  SPIM_TRANS_LENGTH_STS_MASK                         0x00001F00u                   /**< Mask for SPIMTransLengthSts */
#define  SPIM_TRANS_LENGTH_STS_BMASK                        0x1Fu                         /**< Base mask for SPIMTransLengthSts */
#define  SPIM_TRANS_LENGTH_STS(x)                           (((x)&0x1Fu)<<8)              /**< Set SPIMTransLengthSts in register */
#define  GET_SPIM_TRANS_LENGTH_STS(reg)                     (((reg)>>8)&0x1Fu)            /**< Get SPIMTransLengthSts from register */
#define  SPIM_CMD_LENGTH_STS_SHIFT                          16                            /**< Shift for SPIMCmdLengthSts */
#define  SPIM_CMD_LENGTH_STS_MASK                           0x00070000u                   /**< Mask for SPIMCmdLengthSts */
#define  SPIM_CMD_LENGTH_STS_BMASK                          0x7u                          /**< Base mask for SPIMCmdLengthSts */
#define  SPIM_CMD_LENGTH_STS(x)                             (((x)&0x7u)<<16)              /**< Set SPIMCmdLengthSts in register */
#define  GET_SPIM_CMD_LENGTH_STS(reg)                       (((reg)>>16)&0x7u)            /**< Get SPIMCmdLengthSts from register */
#define  SPIM_TST_FSM_ST_SHIFT                              24                            /**< Shift for SPIMTstFSMSt */
#define  SPIM_TST_FSM_ST_MASK                               0x07000000u                   /**< Mask for SPIMTstFSMSt */
#define  SPIM_TST_FSM_ST_BMASK                              0x7u                          /**< Base mask for SPIMTstFSMSt */
#define  SPIM_TST_FSM_ST(x)                                 (((x)&0x7u)<<24)              /**< Set SPIMTstFSMSt in register */
#define  GET_SPIM_TST_FSM_ST(reg)                           (((reg)>>24)&0x7u)            /**< Get SPIMTstFSMSt from register */
#define  SPIM_TST_CKG_ST_SHIFT                              27                            /**< Shift for SPIMTstCKGSt */
#define  SPIM_TST_CKG_ST_MASK                               0x38000000u                   /**< Mask for SPIMTstCKGSt */
#define  SPIM_TST_CKG_ST_BMASK                              0x7u                          /**< Base mask for SPIMTstCKGSt */
#define  SPIM_TST_CKG_ST(x)                                 (((x)&0x7u)<<27)              /**< Set SPIMTstCKGSt in register */
#define  GET_SPIM_TST_CKG_ST(reg)                           (((reg)>>27)&0x7u)            /**< Get SPIMTstCKGSt from register */
/** @} */


/**
 * @name RegSPIMTxCmd
 * @{
 */
// RegSPIMTxCmd.r32
#define  REG_SPIM_TX_CMD_RESET_VALUE                        0x00000000u                   /**< Reset value of RegSPIMTxCmd */
#define  REG_SPIM_TX_CMD_MASK                               0xFFFFFFFFu                   /**< Mask for RegSPIMTxCmd */

#define  SPIM_TX_CMD_SHIFT                                  0                             /**< Shift for SPIMTxCmd */
#define  SPIM_TX_CMD_MASK                                   0xFFFFFFFFu                   /**< Mask for SPIMTxCmd */
#define  SPIM_TX_CMD_BMASK                                  0xFFFFFFFFu                   /**< Base mask for SPIMTxCmd */
#define  SPIM_TX_CMD(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMTxCmd in register */
#define  GET_SPIM_TX_CMD(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMTxCmd from register */
/** @} */


/**
 * @name RegSPIMTxBuffer0
 * @{
 */
// RegSPIMTxBuffer0.r32
#define  REG_SPIM_TX_BUFFER0_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMTxBuffer0 */
#define  REG_SPIM_TX_BUFFER0_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMTxBuffer0 */

#define  SPIM_TX_BUFFER0_SHIFT                              0                             /**< Shift for SPIMTxBuffer0 */
#define  SPIM_TX_BUFFER0_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMTxBuffer0 */
#define  SPIM_TX_BUFFER0_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMTxBuffer0 */
#define  SPIM_TX_BUFFER0(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMTxBuffer0 in register */
#define  GET_SPIM_TX_BUFFER0(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMTxBuffer0 from register */
/** @} */


/**
 * @name RegSPIMTxBuffer1
 * @{
 */
// RegSPIMTxBuffer1.r32
#define  REG_SPIM_TX_BUFFER1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMTxBuffer1 */
#define  REG_SPIM_TX_BUFFER1_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMTxBuffer1 */

#define  SPIM_TX_BUFFER1_SHIFT                              0                             /**< Shift for SPIMTxBuffer1 */
#define  SPIM_TX_BUFFER1_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMTxBuffer1 */
#define  SPIM_TX_BUFFER1_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMTxBuffer1 */
#define  SPIM_TX_BUFFER1(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMTxBuffer1 in register */
#define  GET_SPIM_TX_BUFFER1(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMTxBuffer1 from register */
/** @} */


/**
 * @name RegSPIMTxBuffer2
 * @{
 */
// RegSPIMTxBuffer2.r32
#define  REG_SPIM_TX_BUFFER2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMTxBuffer2 */
#define  REG_SPIM_TX_BUFFER2_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMTxBuffer2 */

#define  SPIM_TX_BUFFER2_SHIFT                              0                             /**< Shift for SPIMTxBuffer2 */
#define  SPIM_TX_BUFFER2_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMTxBuffer2 */
#define  SPIM_TX_BUFFER2_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMTxBuffer2 */
#define  SPIM_TX_BUFFER2(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMTxBuffer2 in register */
#define  GET_SPIM_TX_BUFFER2(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMTxBuffer2 from register */
/** @} */


/**
 * @name RegSPIMTxBuffer3
 * @{
 */
// RegSPIMTxBuffer3.r32
#define  REG_SPIM_TX_BUFFER3_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMTxBuffer3 */
#define  REG_SPIM_TX_BUFFER3_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMTxBuffer3 */

#define  SPIM_TX_BUFFER3_SHIFT                              0                             /**< Shift for SPIMTxBuffer3 */
#define  SPIM_TX_BUFFER3_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMTxBuffer3 */
#define  SPIM_TX_BUFFER3_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMTxBuffer3 */
#define  SPIM_TX_BUFFER3(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMTxBuffer3 in register */
#define  GET_SPIM_TX_BUFFER3(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMTxBuffer3 from register */
/** @} */


/**
 * @name RegSPIMRxCmd
 * @{
 */
// RegSPIMRxCmd.r32
#define  REG_SPIM_RX_CMD_RESET_VALUE                        0x00000000u                   /**< Reset value of RegSPIMRxCmd */
#define  REG_SPIM_RX_CMD_MASK                               0xFFFFFFFFu                   /**< Mask for RegSPIMRxCmd */

#define  SPIM_RX_CMD_SHIFT                                  0                             /**< Shift for SPIMRxCmd */
#define  SPIM_RX_CMD_MASK                                   0xFFFFFFFFu                   /**< Mask for SPIMRxCmd */
#define  SPIM_RX_CMD_BMASK                                  0xFFFFFFFFu                   /**< Base mask for SPIMRxCmd */
#define  SPIM_RX_CMD(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMRxCmd in register */
#define  GET_SPIM_RX_CMD(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMRxCmd from register */
/** @} */


/**
 * @name RegSPIMRxBuffer0
 * @{
 */
// RegSPIMRxBuffer0.r32
#define  REG_SPIM_RX_BUFFER0_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMRxBuffer0 */
#define  REG_SPIM_RX_BUFFER0_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMRxBuffer0 */

#define  SPIM_RX_BUFFER0_SHIFT                              0                             /**< Shift for SPIMRxBuffer0 */
#define  SPIM_RX_BUFFER0_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMRxBuffer0 */
#define  SPIM_RX_BUFFER0_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMRxBuffer0 */
#define  SPIM_RX_BUFFER0(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMRxBuffer0 in register */
#define  GET_SPIM_RX_BUFFER0(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMRxBuffer0 from register */
/** @} */


/**
 * @name RegSPIMRxBuffer1
 * @{
 */
// RegSPIMRxBuffer1.r32
#define  REG_SPIM_RX_BUFFER1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMRxBuffer1 */
#define  REG_SPIM_RX_BUFFER1_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMRxBuffer1 */

#define  SPIM_RX_BUFFER1_SHIFT                              0                             /**< Shift for SPIMRxBuffer1 */
#define  SPIM_RX_BUFFER1_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMRxBuffer1 */
#define  SPIM_RX_BUFFER1_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMRxBuffer1 */
#define  SPIM_RX_BUFFER1(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMRxBuffer1 in register */
#define  GET_SPIM_RX_BUFFER1(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMRxBuffer1 from register */
/** @} */


/**
 * @name RegSPIMRxBuffer2
 * @{
 */
// RegSPIMRxBuffer2.r32
#define  REG_SPIM_RX_BUFFER2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMRxBuffer2 */
#define  REG_SPIM_RX_BUFFER2_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMRxBuffer2 */

#define  SPIM_RX_BUFFER2_SHIFT                              0                             /**< Shift for SPIMRxBuffer2 */
#define  SPIM_RX_BUFFER2_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMRxBuffer2 */
#define  SPIM_RX_BUFFER2_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMRxBuffer2 */
#define  SPIM_RX_BUFFER2(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMRxBuffer2 in register */
#define  GET_SPIM_RX_BUFFER2(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMRxBuffer2 from register */
/** @} */


/**
 * @name RegSPIMRxBuffer3
 * @{
 */
// RegSPIMRxBuffer3.r32
#define  REG_SPIM_RX_BUFFER3_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPIMRxBuffer3 */
#define  REG_SPIM_RX_BUFFER3_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPIMRxBuffer3 */

#define  SPIM_RX_BUFFER3_SHIFT                              0                             /**< Shift for SPIMRxBuffer3 */
#define  SPIM_RX_BUFFER3_MASK                               0xFFFFFFFFu                   /**< Mask for SPIMRxBuffer3 */
#define  SPIM_RX_BUFFER3_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPIMRxBuffer3 */
#define  SPIM_RX_BUFFER3(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPIMRxBuffer3 in register */
#define  GET_SPIM_RX_BUFFER3(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPIMRxBuffer3 from register */
/** @} */



/** @} End of group SPIMaster_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_SPI_MASTER_H */
