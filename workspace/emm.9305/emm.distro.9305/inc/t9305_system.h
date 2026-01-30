////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_system.h
///
/// @project    T9305
///
/// @brief      System register and bit field definitions
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

#ifndef _T9305_SYSTEM_H
#define _T9305_SYSTEM_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup System_Registers System Register Map - registers
 * @{
 ******************************************************************************/


/** Clock configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t ClkSelFreq;                                /**< Select clock frequency. 0: 24MHz, 1: 48Mhz */
        uint16_t MemMarginSts;                              /**< Memory margin status, 0:low, 1: high */
    } regs;
} RegClkCfg_t;


/** Clock control - force clock enable for block specific clock tree */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegClkCtrlForce_t;


/** Clock control - disable clock for block specific clock tree */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegClkCtrlDisable_t;


/** Memory margin control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t MemRamMarginHigh;                          /**< RAM memory margin - high voltage (1.0V) */
        uint16_t MemRamMarginLow;                           /**< RAM memory margin - low voltage (0.9V) */
    } regs;
} RegMemRamMargin_t;


/** Memory margin control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t MemRomMarginHigh;                          /**< ROM memory margin - high voltage (1.0V) */
        uint16_t MemRomMarginLow;                           /**< ROM memory margin - low voltage (0.9V) */
    } regs;
} RegMemRomMargin_t;


/** Memory configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegMemCfg_t;


/** Memory test mode enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegMemTst_t;


/** DMA channel source configuration: channel 0-3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegDmaChSrcCfg1_t;


/** DMA channel source configuration: channel 4-7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegDmaChSrcCfg2_t;


/** USB mode control bit */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbEn_t;


/** USB test bits (status) */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbTst_t;


/** DPR GPIO pad Test mode selector 0: P4-P7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegDPRTstSel0_t;


/** DPR GPIO pad Test mode selector 1: P8-P11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegDPRTstSel1_t;


/** DPR test configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegDprTstCfg1_t;


/** PML status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  PmlCompSts;                                /**< Comparator statuses */
        uint8_t  PmlDomainSts;                              /**< Power domain status */
        uint8_t  STStat;                                    /**< Sleep Timer status */
        uint8_t  PmlMode;                                   /**< System/application modes */
    } regs;
} RegPmlSts_t;


/** PML wake-up status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PmlWakePadSts;                             /**< Pad wake-up status */
        uint8_t  PmlWakeSleepTimSts;                        /**< Sleep timer wake-up status */
        uint8_t  PmlWakeQDecSts;                            /**< QDEC wake-up status */
    } regs;
} RegPmlWakeSts_t;


/** Actual value of DCDC T2 register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegPmlDcdcT2_t;


/** Power meter configuration and control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PwrMetPer;                                 /**< Frame period of the power meter */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegPwrMetCtrl_t;


/** Power meter value and status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t PwrMetVal;                                 /**< Number of active period of the DCDC */
        uint16_t PwrMetStsRun;                              /**< Measurement running status */
    } regs;
} RegPwrMetVal_t;

/** @} end of group System_Regs */



/***************************************************************************//**
 * @defgroup System_RegMap System Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegClkCfg_t                                       RegClkCfg;                    /**< Clock configuration */
    __IO  RegClkCtrlForce_t                                 RegClkCtrlForce;              /**< Clock control - force clock enable for block specific clock tree */
    __IO  RegClkCtrlDisable_t                               RegClkCtrlDisable;            /**< Clock control - disable clock for block specific clock tree */
    __IO  RegMemRamMargin_t                                 RegMemRamMargin;              /**< Memory margin control */
    __IO  RegMemRomMargin_t                                 RegMemRomMargin;              /**< Memory margin control */
    __IO  RegMemCfg_t                                       RegMemCfg;                    /**< Memory configuration */
    __IO  RegMemTst_t                                       RegMemTst;                    /**< Memory test mode enable */
    __IO  RegDmaChSrcCfg1_t                                 RegDmaChSrcCfg1;              /**< DMA channel source configuration: channel 0-3 */
    __IO  RegDmaChSrcCfg2_t                                 RegDmaChSrcCfg2;              /**< DMA channel source configuration: channel 4-7 */
    __IO  RegUsbEn_t                                        RegUsbEn;                     /**< USB mode control bit */
    __IO  RegUsbTst_t                                       RegUsbTst;                    /**< USB test bits (status) */
    __IO  RegDPRTstSel0_t                                   RegDPRTstSel0;                /**< DPR GPIO pad Test mode selector 0: P4-P7 */
    __IO  RegDPRTstSel1_t                                   RegDPRTstSel1;                /**< DPR GPIO pad Test mode selector 1: P8-P11 */
    __IO  RegDprTstCfg1_t                                   RegDprTstCfg1;                /**< DPR test configuration */
    __I   RegPmlSts_t                                       RegPmlSts;                    /**< PML status */
    __I   RegPmlWakeSts_t                                   RegPmlWakeSts;                /**< PML wake-up status */
    __I   RegPmlDcdcT2_t                                    RegPmlDcdcT2;                 /**< Actual value of DCDC T2 register */
    __IO  RegPwrMetCtrl_t                                   RegPwrMetCtrl;                /**< Power meter configuration and control */
    __I   RegPwrMetVal_t                                    RegPwrMetVal;                 /**< Power meter value and status */
} System_RegMap_t;

/** @} end of group System_RegMap */



/***************************************************************************//**
 * @defgroup System_BitFields System bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegClkCfg
 * @{
 */
// RegClkCfg.r32
#define  REG_CLK_CFG_RESET_VALUE                            0x00000000u                   /**< Reset value of RegClkCfg */
#define  REG_CLK_CFG_MASK                                   0x00010001u                   /**< Mask for RegClkCfg */

#define  CLK_SEL_FREQ_SHIFT                                 0                             /**< Shift for ClkSelFreq */
#define  CLK_SEL_FREQ_MASK                                  0x00000001u                   /**< Mask for ClkSelFreq */
#define  CLK_SEL_FREQ_BMASK                                 0x1u                          /**< Base mask for ClkSelFreq */
#define  CLK_SEL_FREQ(x)                                    (((x)&0x1u)<<0)               /**< Set ClkSelFreq in register */
#define  GET_CLK_SEL_FREQ(reg)                              (((reg)>>0)&0x1u)             /**< Get ClkSelFreq from register */
#define  MEM_MARGIN_STS_SHIFT                               16                            /**< Shift for MemMarginSts */
#define  MEM_MARGIN_STS_MASK                                0x00010000u                   /**< Mask for MemMarginSts */
#define  MEM_MARGIN_STS_BMASK                               0x1u                          /**< Base mask for MemMarginSts */
#define  MEM_MARGIN_STS(x)                                  (((x)&0x1u)<<16)              /**< Set MemMarginSts in register */
#define  GET_MEM_MARGIN_STS(reg)                            (((reg)>>16)&0x1u)            /**< Get MemMarginSts from register */

// RegClkCfg.regs.ClkSelFreq
#define  CLK_SEL_FREQ_GSHIFT                                0                             /**< Shift for group ClkSelFreq */
#define  CLK_SEL_FREQ_GSIZE                                 16                            /**< Size of group ClkSelFreq */
#define  CLK_SEL_FREQ_GMASK                                 0x0000FFFFu                   /**< Mask for group ClkSelFreq */

#define  CLK_SEL_FREQ_RSHIFT                                0                             /**< Shift for ClkSelFreq */
#define  CLK_SEL_FREQ_RMASK                                 0x00000001u                   /**< Mask for ClkSelFreq */
#define  CLK_SEL_FREQ_RBMASK                                0x1u                          /**< Base mask for ClkSelFreq */
#define  CLK_SEL_FREQ_R(x)                                  (((x)&0x1u)<<0)               /**< Set ClkSelFreq in register */
#define  GET_CLK_SEL_FREQ_R(reg)                            (((reg)>>0)&0x1u)             /**< Get ClkSelFreq from register */

// RegClkCfg.regs.MemMarginSts
#define  MEM_MARGIN_STS_GSHIFT                              16                            /**< Shift for group MemMarginSts */
#define  MEM_MARGIN_STS_GSIZE                               16                            /**< Size of group MemMarginSts */
#define  MEM_MARGIN_STS_GMASK                               0xFFFF0000u                   /**< Mask for group MemMarginSts */

#define  MEM_MARGIN_STS_RSHIFT                              0                             /**< Shift for MemMarginSts */
#define  MEM_MARGIN_STS_RMASK                               0x00000001u                   /**< Mask for MemMarginSts */
#define  MEM_MARGIN_STS_RBMASK                              0x1u                          /**< Base mask for MemMarginSts */
#define  MEM_MARGIN_STS_R(x)                                (((x)&0x1u)<<0)               /**< Set MemMarginSts in register */
#define  GET_MEM_MARGIN_STS_R(reg)                          (((reg)>>0)&0x1u)             /**< Get MemMarginSts from register */
/** @} */


/**
 * @name RegClkCtrlForce
 * @{
 */
// RegClkCtrlForce.r32
#define  REG_CLK_CTRL_FORCE_RESET_VALUE                     0x00000000u                   /**< Reset value of RegClkCtrlForce */
#define  REG_CLK_CTRL_FORCE_MASK                            0x000FFFFFu                   /**< Mask for RegClkCtrlForce */

#define  CLK_FORCE_CPU_SHIFT                                0                             /**< Shift for ClkForceCPU */
#define  CLK_FORCE_CPU_MASK                                 0x00000001u                   /**< Mask for ClkForceCPU */
#define  CLK_FORCE_CPU_BMASK                                0x1u                          /**< Base mask for ClkForceCPU */
#define  CLK_FORCE_CPU(x)                                   (((x)&0x1u)<<0)               /**< Set ClkForceCPU in register */
#define  GET_CLK_FORCE_CPU(reg)                             (((reg)>>0)&0x1u)             /**< Get ClkForceCPU from register */
#define  CLK_FORCE_IRQ_SHIFT                                1                             /**< Shift for ClkForceIRQ */
#define  CLK_FORCE_IRQ_MASK                                 0x00000002u                   /**< Mask for ClkForceIRQ */
#define  CLK_FORCE_IRQ_BMASK                                0x1u                          /**< Base mask for ClkForceIRQ */
#define  CLK_FORCE_IRQ(x)                                   (((x)&0x1u)<<1)               /**< Set ClkForceIRQ in register */
#define  GET_CLK_FORCE_IRQ(reg)                             (((reg)>>1)&0x1u)             /**< Get ClkForceIRQ from register */
#define  CLK_FORCE_RNG_SHIFT                                2                             /**< Shift for ClkForceRNG */
#define  CLK_FORCE_RNG_MASK                                 0x00000004u                   /**< Mask for ClkForceRNG */
#define  CLK_FORCE_RNG_BMASK                                0x1u                          /**< Base mask for ClkForceRNG */
#define  CLK_FORCE_RNG(x)                                   (((x)&0x1u)<<2)               /**< Set ClkForceRNG in register */
#define  GET_CLK_FORCE_RNG(reg)                             (((reg)>>2)&0x1u)             /**< Get ClkForceRNG from register */
#define  CLK_FORCE_UT2_SHIFT                                3                             /**< Shift for ClkForceUT2 */
#define  CLK_FORCE_UT2_MASK                                 0x00000008u                   /**< Mask for ClkForceUT2 */
#define  CLK_FORCE_UT2_BMASK                                0x1u                          /**< Base mask for ClkForceUT2 */
#define  CLK_FORCE_UT2(x)                                   (((x)&0x1u)<<3)               /**< Set ClkForceUT2 in register */
#define  GET_CLK_FORCE_UT2(reg)                             (((reg)>>3)&0x1u)             /**< Get ClkForceUT2 from register */
#define  CLK_FORCE_UT3_SHIFT                                4                             /**< Shift for ClkForceUT3 */
#define  CLK_FORCE_UT3_MASK                                 0x00000010u                   /**< Mask for ClkForceUT3 */
#define  CLK_FORCE_UT3_BMASK                                0x1u                          /**< Base mask for ClkForceUT3 */
#define  CLK_FORCE_UT3(x)                                   (((x)&0x1u)<<4)               /**< Set ClkForceUT3 in register */
#define  GET_CLK_FORCE_UT3(reg)                             (((reg)>>4)&0x1u)             /**< Get ClkForceUT3 from register */
#define  CLK_FORCE_PT_SHIFT                                 5                             /**< Shift for ClkForcePT */
#define  CLK_FORCE_PT_MASK                                  0x00000020u                   /**< Mask for ClkForcePT */
#define  CLK_FORCE_PT_BMASK                                 0x1u                          /**< Base mask for ClkForcePT */
#define  CLK_FORCE_PT(x)                                    (((x)&0x1u)<<5)               /**< Set ClkForcePT in register */
#define  GET_CLK_FORCE_PT(reg)                              (((reg)>>5)&0x1u)             /**< Get ClkForcePT from register */
#define  CLK_FORCE_RC_CALIB_SHIFT                           6                             /**< Shift for ClkForceRCCalib */
#define  CLK_FORCE_RC_CALIB_MASK                            0x00000040u                   /**< Mask for ClkForceRCCalib */
#define  CLK_FORCE_RC_CALIB_BMASK                           0x1u                          /**< Base mask for ClkForceRCCalib */
#define  CLK_FORCE_RC_CALIB(x)                              (((x)&0x1u)<<6)               /**< Set ClkForceRCCalib in register */
#define  GET_CLK_FORCE_RC_CALIB(reg)                        (((reg)>>6)&0x1u)             /**< Get ClkForceRCCalib from register */
#define  CLK_FORCE_UART_SHIFT                               7                             /**< Shift for ClkForceUART */
#define  CLK_FORCE_UART_MASK                                0x00000080u                   /**< Mask for ClkForceUART */
#define  CLK_FORCE_UART_BMASK                               0x1u                          /**< Base mask for ClkForceUART */
#define  CLK_FORCE_UART(x)                                  (((x)&0x1u)<<7)               /**< Set ClkForceUART in register */
#define  GET_CLK_FORCE_UART(reg)                            (((reg)>>7)&0x1u)             /**< Get ClkForceUART from register */
#define  CLK_FORCE_I2C_MASTER_SHIFT                         8                             /**< Shift for ClkForceI2CMaster */
#define  CLK_FORCE_I2C_MASTER_MASK                          0x00000100u                   /**< Mask for ClkForceI2CMaster */
#define  CLK_FORCE_I2C_MASTER_BMASK                         0x1u                          /**< Base mask for ClkForceI2CMaster */
#define  CLK_FORCE_I2C_MASTER(x)                            (((x)&0x1u)<<8)               /**< Set ClkForceI2CMaster in register */
#define  GET_CLK_FORCE_I2C_MASTER(reg)                      (((reg)>>8)&0x1u)             /**< Get ClkForceI2CMaster from register */
#define  CLK_FORCE_SPI_MASTER_SHIFT                         9                             /**< Shift for ClkForceSPIMaster */
#define  CLK_FORCE_SPI_MASTER_MASK                          0x00000200u                   /**< Mask for ClkForceSPIMaster */
#define  CLK_FORCE_SPI_MASTER_BMASK                         0x1u                          /**< Base mask for ClkForceSPIMaster */
#define  CLK_FORCE_SPI_MASTER(x)                            (((x)&0x1u)<<9)               /**< Set ClkForceSPIMaster in register */
#define  GET_CLK_FORCE_SPI_MASTER(reg)                      (((reg)>>9)&0x1u)             /**< Get ClkForceSPIMaster from register */
#define  CLK_FORCE_SPI_SLAVE_SHIFT                          10                            /**< Shift for ClkForceSPISlave */
#define  CLK_FORCE_SPI_SLAVE_MASK                           0x00000400u                   /**< Mask for ClkForceSPISlave */
#define  CLK_FORCE_SPI_SLAVE_BMASK                          0x1u                          /**< Base mask for ClkForceSPISlave */
#define  CLK_FORCE_SPI_SLAVE(x)                             (((x)&0x1u)<<10)              /**< Set ClkForceSPISlave in register */
#define  GET_CLK_FORCE_SPI_SLAVE(reg)                       (((reg)>>10)&0x1u)            /**< Get ClkForceSPISlave from register */
#define  CLK_FORCE_GPIO_SHIFT                               11                            /**< Shift for ClkForceGPIO */
#define  CLK_FORCE_GPIO_MASK                                0x00000800u                   /**< Mask for ClkForceGPIO */
#define  CLK_FORCE_GPIO_BMASK                               0x1u                          /**< Base mask for ClkForceGPIO */
#define  CLK_FORCE_GPIO(x)                                  (((x)&0x1u)<<11)              /**< Set ClkForceGPIO in register */
#define  GET_CLK_FORCE_GPIO(reg)                            (((reg)>>11)&0x1u)            /**< Get ClkForceGPIO from register */
#define  CLK_FORCE_RF_CTRL_SHIFT                            12                            /**< Shift for ClkForceRfCtrl */
#define  CLK_FORCE_RF_CTRL_MASK                             0x00001000u                   /**< Mask for ClkForceRfCtrl */
#define  CLK_FORCE_RF_CTRL_BMASK                            0x1u                          /**< Base mask for ClkForceRfCtrl */
#define  CLK_FORCE_RF_CTRL(x)                               (((x)&0x1u)<<12)              /**< Set ClkForceRfCtrl in register */
#define  GET_CLK_FORCE_RF_CTRL(reg)                         (((reg)>>12)&0x1u)            /**< Get ClkForceRfCtrl from register */
#define  CLK_FORCE_NVM_SHIFT                                13                            /**< Shift for ClkForceNVM */
#define  CLK_FORCE_NVM_MASK                                 0x00002000u                   /**< Mask for ClkForceNVM */
#define  CLK_FORCE_NVM_BMASK                                0x1u                          /**< Base mask for ClkForceNVM */
#define  CLK_FORCE_NVM(x)                                   (((x)&0x1u)<<13)              /**< Set ClkForceNVM in register */
#define  GET_CLK_FORCE_NVM(reg)                             (((reg)>>13)&0x1u)            /**< Get ClkForceNVM from register */
#define  CLK_FORCE_PCK_PROC_SHIFT                           14                            /**< Shift for ClkForcePckProc */
#define  CLK_FORCE_PCK_PROC_MASK                            0x00004000u                   /**< Mask for ClkForcePckProc */
#define  CLK_FORCE_PCK_PROC_BMASK                           0x1u                          /**< Base mask for ClkForcePckProc */
#define  CLK_FORCE_PCK_PROC(x)                              (((x)&0x1u)<<14)              /**< Set ClkForcePckProc in register */
#define  GET_CLK_FORCE_PCK_PROC(reg)                        (((reg)>>14)&0x1u)            /**< Get ClkForcePckProc from register */
#define  CLK_FORCE_AOAD_SHIFT                               15                            /**< Shift for ClkForceAoad */
#define  CLK_FORCE_AOAD_MASK                                0x00008000u                   /**< Mask for ClkForceAoad */
#define  CLK_FORCE_AOAD_BMASK                               0x1u                          /**< Base mask for ClkForceAoad */
#define  CLK_FORCE_AOAD(x)                                  (((x)&0x1u)<<15)              /**< Set ClkForceAoad in register */
#define  GET_CLK_FORCE_AOAD(reg)                            (((reg)>>15)&0x1u)            /**< Get ClkForceAoad from register */
#define  CLK_FORCE_IQ_SHIFT                                 16                            /**< Shift for ClkForceIq */
#define  CLK_FORCE_IQ_MASK                                  0x00010000u                   /**< Mask for ClkForceIq */
#define  CLK_FORCE_IQ_BMASK                                 0x1u                          /**< Base mask for ClkForceIq */
#define  CLK_FORCE_IQ(x)                                    (((x)&0x1u)<<16)              /**< Set ClkForceIq in register */
#define  GET_CLK_FORCE_IQ(reg)                              (((reg)>>16)&0x1u)            /**< Get ClkForceIq from register */
#define  CLK_FORCE_CC_SHIFT                                 17                            /**< Shift for ClkForceCC */
#define  CLK_FORCE_CC_MASK                                  0x00020000u                   /**< Mask for ClkForceCC */
#define  CLK_FORCE_CC_BMASK                                 0x1u                          /**< Base mask for ClkForceCC */
#define  CLK_FORCE_CC(x)                                    (((x)&0x1u)<<17)              /**< Set ClkForceCC in register */
#define  GET_CLK_FORCE_CC(reg)                              (((reg)>>17)&0x1u)            /**< Get ClkForceCC from register */
#define  CLK_FORCE_I2S_SHIFT                                18                            /**< Shift for ClkForceI2s */
#define  CLK_FORCE_I2S_MASK                                 0x00040000u                   /**< Mask for ClkForceI2s */
#define  CLK_FORCE_I2S_BMASK                                0x1u                          /**< Base mask for ClkForceI2s */
#define  CLK_FORCE_I2S(x)                                   (((x)&0x1u)<<18)              /**< Set ClkForceI2s in register */
#define  GET_CLK_FORCE_I2S(reg)                             (((reg)>>18)&0x1u)            /**< Get ClkForceI2s from register */
#define  CLK_FORCE_USB_SHIFT                                19                            /**< Shift for ClkForceUsb */
#define  CLK_FORCE_USB_MASK                                 0x00080000u                   /**< Mask for ClkForceUsb */
#define  CLK_FORCE_USB_BMASK                                0x1u                          /**< Base mask for ClkForceUsb */
#define  CLK_FORCE_USB(x)                                   (((x)&0x1u)<<19)              /**< Set ClkForceUsb in register */
#define  GET_CLK_FORCE_USB(reg)                             (((reg)>>19)&0x1u)            /**< Get ClkForceUsb from register */
/** @} */


/**
 * @name RegClkCtrlDisable
 * @{
 */
// RegClkCtrlDisable.r32
#define  REG_CLK_CTRL_DISABLE_RESET_VALUE                   0x00000000u                   /**< Reset value of RegClkCtrlDisable */
#define  REG_CLK_CTRL_DISABLE_MASK                          0x000FFFFFu                   /**< Mask for RegClkCtrlDisable */

#define  CLK_DIS_CPU_SHIFT                                  0                             /**< Shift for ClkDisCPU */
#define  CLK_DIS_CPU_MASK                                   0x00000001u                   /**< Mask for ClkDisCPU */
#define  CLK_DIS_CPU_BMASK                                  0x1u                          /**< Base mask for ClkDisCPU */
#define  CLK_DIS_CPU(x)                                     (((x)&0x1u)<<0)               /**< Set ClkDisCPU in register */
#define  GET_CLK_DIS_CPU(reg)                               (((reg)>>0)&0x1u)             /**< Get ClkDisCPU from register */
#define  CLK_DIS_IRQ_SHIFT                                  1                             /**< Shift for ClkDisIRQ */
#define  CLK_DIS_IRQ_MASK                                   0x00000002u                   /**< Mask for ClkDisIRQ */
#define  CLK_DIS_IRQ_BMASK                                  0x1u                          /**< Base mask for ClkDisIRQ */
#define  CLK_DIS_IRQ(x)                                     (((x)&0x1u)<<1)               /**< Set ClkDisIRQ in register */
#define  GET_CLK_DIS_IRQ(reg)                               (((reg)>>1)&0x1u)             /**< Get ClkDisIRQ from register */
#define  CLK_DIS_RNG_SHIFT                                  2                             /**< Shift for ClkDisRNG */
#define  CLK_DIS_RNG_MASK                                   0x00000004u                   /**< Mask for ClkDisRNG */
#define  CLK_DIS_RNG_BMASK                                  0x1u                          /**< Base mask for ClkDisRNG */
#define  CLK_DIS_RNG(x)                                     (((x)&0x1u)<<2)               /**< Set ClkDisRNG in register */
#define  GET_CLK_DIS_RNG(reg)                               (((reg)>>2)&0x1u)             /**< Get ClkDisRNG from register */
#define  CLK_DIS_UT2_SHIFT                                  3                             /**< Shift for ClkDisUT2 */
#define  CLK_DIS_UT2_MASK                                   0x00000008u                   /**< Mask for ClkDisUT2 */
#define  CLK_DIS_UT2_BMASK                                  0x1u                          /**< Base mask for ClkDisUT2 */
#define  CLK_DIS_UT2(x)                                     (((x)&0x1u)<<3)               /**< Set ClkDisUT2 in register */
#define  GET_CLK_DIS_UT2(reg)                               (((reg)>>3)&0x1u)             /**< Get ClkDisUT2 from register */
#define  CLK_DIS_UT3_SHIFT                                  4                             /**< Shift for ClkDisUT3 */
#define  CLK_DIS_UT3_MASK                                   0x00000010u                   /**< Mask for ClkDisUT3 */
#define  CLK_DIS_UT3_BMASK                                  0x1u                          /**< Base mask for ClkDisUT3 */
#define  CLK_DIS_UT3(x)                                     (((x)&0x1u)<<4)               /**< Set ClkDisUT3 in register */
#define  GET_CLK_DIS_UT3(reg)                               (((reg)>>4)&0x1u)             /**< Get ClkDisUT3 from register */
#define  CLK_DIS_PT_SHIFT                                   5                             /**< Shift for ClkDisPT */
#define  CLK_DIS_PT_MASK                                    0x00000020u                   /**< Mask for ClkDisPT */
#define  CLK_DIS_PT_BMASK                                   0x1u                          /**< Base mask for ClkDisPT */
#define  CLK_DIS_PT(x)                                      (((x)&0x1u)<<5)               /**< Set ClkDisPT in register */
#define  GET_CLK_DIS_PT(reg)                                (((reg)>>5)&0x1u)             /**< Get ClkDisPT from register */
#define  CLK_DIS_RC_CALIB_SHIFT                             6                             /**< Shift for ClkDisRCCalib */
#define  CLK_DIS_RC_CALIB_MASK                              0x00000040u                   /**< Mask for ClkDisRCCalib */
#define  CLK_DIS_RC_CALIB_BMASK                             0x1u                          /**< Base mask for ClkDisRCCalib */
#define  CLK_DIS_RC_CALIB(x)                                (((x)&0x1u)<<6)               /**< Set ClkDisRCCalib in register */
#define  GET_CLK_DIS_RC_CALIB(reg)                          (((reg)>>6)&0x1u)             /**< Get ClkDisRCCalib from register */
#define  CLK_DIS_UART_SHIFT                                 7                             /**< Shift for ClkDisUART */
#define  CLK_DIS_UART_MASK                                  0x00000080u                   /**< Mask for ClkDisUART */
#define  CLK_DIS_UART_BMASK                                 0x1u                          /**< Base mask for ClkDisUART */
#define  CLK_DIS_UART(x)                                    (((x)&0x1u)<<7)               /**< Set ClkDisUART in register */
#define  GET_CLK_DIS_UART(reg)                              (((reg)>>7)&0x1u)             /**< Get ClkDisUART from register */
#define  CLK_DIS_I2C_MASTER_SHIFT                           8                             /**< Shift for ClkDisI2CMaster */
#define  CLK_DIS_I2C_MASTER_MASK                            0x00000100u                   /**< Mask for ClkDisI2CMaster */
#define  CLK_DIS_I2C_MASTER_BMASK                           0x1u                          /**< Base mask for ClkDisI2CMaster */
#define  CLK_DIS_I2C_MASTER(x)                              (((x)&0x1u)<<8)               /**< Set ClkDisI2CMaster in register */
#define  GET_CLK_DIS_I2C_MASTER(reg)                        (((reg)>>8)&0x1u)             /**< Get ClkDisI2CMaster from register */
#define  CLK_DIS_SPI_MASTER_SHIFT                           9                             /**< Shift for ClkDisSPIMaster */
#define  CLK_DIS_SPI_MASTER_MASK                            0x00000200u                   /**< Mask for ClkDisSPIMaster */
#define  CLK_DIS_SPI_MASTER_BMASK                           0x1u                          /**< Base mask for ClkDisSPIMaster */
#define  CLK_DIS_SPI_MASTER(x)                              (((x)&0x1u)<<9)               /**< Set ClkDisSPIMaster in register */
#define  GET_CLK_DIS_SPI_MASTER(reg)                        (((reg)>>9)&0x1u)             /**< Get ClkDisSPIMaster from register */
#define  CLK_DIS_SPI_SLAVE_SHIFT                            10                            /**< Shift for ClkDisSPISlave */
#define  CLK_DIS_SPI_SLAVE_MASK                             0x00000400u                   /**< Mask for ClkDisSPISlave */
#define  CLK_DIS_SPI_SLAVE_BMASK                            0x1u                          /**< Base mask for ClkDisSPISlave */
#define  CLK_DIS_SPI_SLAVE(x)                               (((x)&0x1u)<<10)              /**< Set ClkDisSPISlave in register */
#define  GET_CLK_DIS_SPI_SLAVE(reg)                         (((reg)>>10)&0x1u)            /**< Get ClkDisSPISlave from register */
#define  CLK_DIS_GPIO_SHIFT                                 11                            /**< Shift for ClkDisGPIO */
#define  CLK_DIS_GPIO_MASK                                  0x00000800u                   /**< Mask for ClkDisGPIO */
#define  CLK_DIS_GPIO_BMASK                                 0x1u                          /**< Base mask for ClkDisGPIO */
#define  CLK_DIS_GPIO(x)                                    (((x)&0x1u)<<11)              /**< Set ClkDisGPIO in register */
#define  GET_CLK_DIS_GPIO(reg)                              (((reg)>>11)&0x1u)            /**< Get ClkDisGPIO from register */
#define  CLK_DIS_RF_CTRL_SHIFT                              12                            /**< Shift for ClkDisRfCtrl */
#define  CLK_DIS_RF_CTRL_MASK                               0x00001000u                   /**< Mask for ClkDisRfCtrl */
#define  CLK_DIS_RF_CTRL_BMASK                              0x1u                          /**< Base mask for ClkDisRfCtrl */
#define  CLK_DIS_RF_CTRL(x)                                 (((x)&0x1u)<<12)              /**< Set ClkDisRfCtrl in register */
#define  GET_CLK_DIS_RF_CTRL(reg)                           (((reg)>>12)&0x1u)            /**< Get ClkDisRfCtrl from register */
#define  CLK_DIS_NVM_SHIFT                                  13                            /**< Shift for ClkDisNVM */
#define  CLK_DIS_NVM_MASK                                   0x00002000u                   /**< Mask for ClkDisNVM */
#define  CLK_DIS_NVM_BMASK                                  0x1u                          /**< Base mask for ClkDisNVM */
#define  CLK_DIS_NVM(x)                                     (((x)&0x1u)<<13)              /**< Set ClkDisNVM in register */
#define  GET_CLK_DIS_NVM(reg)                               (((reg)>>13)&0x1u)            /**< Get ClkDisNVM from register */
#define  CLK_DIS_PCK_PROC_SHIFT                             14                            /**< Shift for ClkDisPckProc */
#define  CLK_DIS_PCK_PROC_MASK                              0x00004000u                   /**< Mask for ClkDisPckProc */
#define  CLK_DIS_PCK_PROC_BMASK                             0x1u                          /**< Base mask for ClkDisPckProc */
#define  CLK_DIS_PCK_PROC(x)                                (((x)&0x1u)<<14)              /**< Set ClkDisPckProc in register */
#define  GET_CLK_DIS_PCK_PROC(reg)                          (((reg)>>14)&0x1u)            /**< Get ClkDisPckProc from register */
#define  CLK_DIS_AOAD_SHIFT                                 15                            /**< Shift for ClkDisAoad */
#define  CLK_DIS_AOAD_MASK                                  0x00008000u                   /**< Mask for ClkDisAoad */
#define  CLK_DIS_AOAD_BMASK                                 0x1u                          /**< Base mask for ClkDisAoad */
#define  CLK_DIS_AOAD(x)                                    (((x)&0x1u)<<15)              /**< Set ClkDisAoad in register */
#define  GET_CLK_DIS_AOAD(reg)                              (((reg)>>15)&0x1u)            /**< Get ClkDisAoad from register */
#define  CLK_DIS_IQ_SHIFT                                   16                            /**< Shift for ClkDisIq */
#define  CLK_DIS_IQ_MASK                                    0x00010000u                   /**< Mask for ClkDisIq */
#define  CLK_DIS_IQ_BMASK                                   0x1u                          /**< Base mask for ClkDisIq */
#define  CLK_DIS_IQ(x)                                      (((x)&0x1u)<<16)              /**< Set ClkDisIq in register */
#define  GET_CLK_DIS_IQ(reg)                                (((reg)>>16)&0x1u)            /**< Get ClkDisIq from register */
#define  CLK_DIS_CC_SHIFT                                   17                            /**< Shift for ClkDisCC */
#define  CLK_DIS_CC_MASK                                    0x00020000u                   /**< Mask for ClkDisCC */
#define  CLK_DIS_CC_BMASK                                   0x1u                          /**< Base mask for ClkDisCC */
#define  CLK_DIS_CC(x)                                      (((x)&0x1u)<<17)              /**< Set ClkDisCC in register */
#define  GET_CLK_DIS_CC(reg)                                (((reg)>>17)&0x1u)            /**< Get ClkDisCC from register */
#define  CLK_DIS_I2S_SHIFT                                  18                            /**< Shift for ClkDisI2s */
#define  CLK_DIS_I2S_MASK                                   0x00040000u                   /**< Mask for ClkDisI2s */
#define  CLK_DIS_I2S_BMASK                                  0x1u                          /**< Base mask for ClkDisI2s */
#define  CLK_DIS_I2S(x)                                     (((x)&0x1u)<<18)              /**< Set ClkDisI2s in register */
#define  GET_CLK_DIS_I2S(reg)                               (((reg)>>18)&0x1u)            /**< Get ClkDisI2s from register */
#define  CLK_DIS_USB_SHIFT                                  19                            /**< Shift for ClkDisUsb */
#define  CLK_DIS_USB_MASK                                   0x00080000u                   /**< Mask for ClkDisUsb */
#define  CLK_DIS_USB_BMASK                                  0x1u                          /**< Base mask for ClkDisUsb */
#define  CLK_DIS_USB(x)                                     (((x)&0x1u)<<19)              /**< Set ClkDisUsb in register */
#define  GET_CLK_DIS_USB(reg)                               (((reg)>>19)&0x1u)            /**< Get ClkDisUsb from register */
/** @} */


/**
 * @name RegMemRamMargin
 * @{
 */
// RegMemRamMargin.r32
#define  REG_MEM_RAM_MARGIN_RESET_VALUE                     0x10461205u                   /**< Reset value of RegMemRamMargin */
#define  REG_MEM_RAM_MARGIN_MASK                            0x1FFF1FFFu                   /**< Mask for RegMemRamMargin */

#define  MEM_RAM_WA_HIGH_SHIFT                              0                             /**< Shift for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH_MASK                               0x00000007u                   /**< Mask for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH_BMASK                              0x7u                          /**< Base mask for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH(x)                                 (((x)&0x7u)<<0)               /**< Set MemRamWaHigh in register */
#define  GET_MEM_RAM_WA_HIGH(reg)                           (((reg)>>0)&0x7u)             /**< Get MemRamWaHigh from register */
#define  MEM_RAM_WPULSE_HIGH_SHIFT                          3                             /**< Shift for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH_MASK                           0x00000038u                   /**< Mask for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH_BMASK                          0x7u                          /**< Base mask for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH(x)                             (((x)&0x7u)<<3)               /**< Set MemRamWpulseHigh in register */
#define  GET_MEM_RAM_WPULSE_HIGH(reg)                       (((reg)>>3)&0x7u)             /**< Get MemRamWpulseHigh from register */
#define  MEM_RAM_RA_HIGH_SHIFT                              6                             /**< Shift for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH_MASK                               0x000000C0u                   /**< Mask for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH_BMASK                              0x3u                          /**< Base mask for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH(x)                                 (((x)&0x3u)<<6)               /**< Set MemRamRaHigh in register */
#define  GET_MEM_RAM_RA_HIGH(reg)                           (((reg)>>6)&0x3u)             /**< Get MemRamRaHigh from register */
#define  MEM_RAM_RM_HIGH_SHIFT                              8                             /**< Shift for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH_MASK                               0x00000F00u                   /**< Mask for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH_BMASK                              0xFu                          /**< Base mask for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH(x)                                 (((x)&0xFu)<<8)               /**< Set MemRamRmHigh in register */
#define  GET_MEM_RAM_RM_HIGH(reg)                           (((reg)>>8)&0xFu)             /**< Get MemRamRmHigh from register */
#define  MEM_RAM_RME_HIGH_SHIFT                             12                            /**< Shift for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH_MASK                              0x00001000u                   /**< Mask for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH_BMASK                             0x1u                          /**< Base mask for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH(x)                                (((x)&0x1u)<<12)              /**< Set MemRamRmeHigh in register */
#define  GET_MEM_RAM_RME_HIGH(reg)                          (((reg)>>12)&0x1u)            /**< Get MemRamRmeHigh from register */
#define  MEM_RAM_WA_LOW_SHIFT                               16                            /**< Shift for MemRamWaLow */
#define  MEM_RAM_WA_LOW_MASK                                0x00070000u                   /**< Mask for MemRamWaLow */
#define  MEM_RAM_WA_LOW_BMASK                               0x7u                          /**< Base mask for MemRamWaLow */
#define  MEM_RAM_WA_LOW(x)                                  (((x)&0x7u)<<16)              /**< Set MemRamWaLow in register */
#define  GET_MEM_RAM_WA_LOW(reg)                            (((reg)>>16)&0x7u)            /**< Get MemRamWaLow from register */
#define  MEM_RAM_WPULSE_LOW_SHIFT                           19                            /**< Shift for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW_MASK                            0x00380000u                   /**< Mask for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW_BMASK                           0x7u                          /**< Base mask for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW(x)                              (((x)&0x7u)<<19)              /**< Set MemRamWpulseLow in register */
#define  GET_MEM_RAM_WPULSE_LOW(reg)                        (((reg)>>19)&0x7u)            /**< Get MemRamWpulseLow from register */
#define  MEM_RAM_RA_LOW_SHIFT                               22                            /**< Shift for MemRamRaLow */
#define  MEM_RAM_RA_LOW_MASK                                0x00C00000u                   /**< Mask for MemRamRaLow */
#define  MEM_RAM_RA_LOW_BMASK                               0x3u                          /**< Base mask for MemRamRaLow */
#define  MEM_RAM_RA_LOW(x)                                  (((x)&0x3u)<<22)              /**< Set MemRamRaLow in register */
#define  GET_MEM_RAM_RA_LOW(reg)                            (((reg)>>22)&0x3u)            /**< Get MemRamRaLow from register */
#define  MEM_RAM_RM_LOW_SHIFT                               24                            /**< Shift for MemRamRmLow */
#define  MEM_RAM_RM_LOW_MASK                                0x0F000000u                   /**< Mask for MemRamRmLow */
#define  MEM_RAM_RM_LOW_BMASK                               0xFu                          /**< Base mask for MemRamRmLow */
#define  MEM_RAM_RM_LOW(x)                                  (((x)&0xFu)<<24)              /**< Set MemRamRmLow in register */
#define  GET_MEM_RAM_RM_LOW(reg)                            (((reg)>>24)&0xFu)            /**< Get MemRamRmLow from register */
#define  MEM_RAM_RME_LOW_SHIFT                              28                            /**< Shift for MemRamRmeLow */
#define  MEM_RAM_RME_LOW_MASK                               0x10000000u                   /**< Mask for MemRamRmeLow */
#define  MEM_RAM_RME_LOW_BMASK                              0x1u                          /**< Base mask for MemRamRmeLow */
#define  MEM_RAM_RME_LOW(x)                                 (((x)&0x1u)<<28)              /**< Set MemRamRmeLow in register */
#define  GET_MEM_RAM_RME_LOW(reg)                           (((reg)>>28)&0x1u)            /**< Get MemRamRmeLow from register */

// RegMemRamMargin.regs.MemRamMarginHigh
#define  MEM_RAM_MARGIN_HIGH_GSHIFT                         0                             /**< Shift for group MemRamMarginHigh */
#define  MEM_RAM_MARGIN_HIGH_GSIZE                          16                            /**< Size of group MemRamMarginHigh */
#define  MEM_RAM_MARGIN_HIGH_GMASK                          0x0000FFFFu                   /**< Mask for group MemRamMarginHigh */

#define  MEM_RAM_WA_HIGH_RSHIFT                             0                             /**< Shift for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH_RMASK                              0x0007u                       /**< Mask for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH_RBMASK                             0x7u                          /**< Base mask for MemRamWaHigh */
#define  MEM_RAM_WA_HIGH_R(x)                               (((x)&0x7u)<<0)               /**< Set MemRamWaHigh in register */
#define  GET_MEM_RAM_WA_HIGH_R(reg)                         (((reg)>>0)&0x7u)             /**< Get MemRamWaHigh from register */
#define  MEM_RAM_WPULSE_HIGH_RSHIFT                         3                             /**< Shift for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH_RMASK                          0x0038u                       /**< Mask for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH_RBMASK                         0x7u                          /**< Base mask for MemRamWpulseHigh */
#define  MEM_RAM_WPULSE_HIGH_R(x)                           (((x)&0x7u)<<3)               /**< Set MemRamWpulseHigh in register */
#define  GET_MEM_RAM_WPULSE_HIGH_R(reg)                     (((reg)>>3)&0x7u)             /**< Get MemRamWpulseHigh from register */
#define  MEM_RAM_RA_HIGH_RSHIFT                             6                             /**< Shift for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH_RMASK                              0x00C0u                       /**< Mask for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH_RBMASK                             0x3u                          /**< Base mask for MemRamRaHigh */
#define  MEM_RAM_RA_HIGH_R(x)                               (((x)&0x3u)<<6)               /**< Set MemRamRaHigh in register */
#define  GET_MEM_RAM_RA_HIGH_R(reg)                         (((reg)>>6)&0x3u)             /**< Get MemRamRaHigh from register */
#define  MEM_RAM_RM_HIGH_RSHIFT                             8                             /**< Shift for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH_RMASK                              0x0F00u                       /**< Mask for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH_RBMASK                             0xFu                          /**< Base mask for MemRamRmHigh */
#define  MEM_RAM_RM_HIGH_R(x)                               (((x)&0xFu)<<8)               /**< Set MemRamRmHigh in register */
#define  GET_MEM_RAM_RM_HIGH_R(reg)                         (((reg)>>8)&0xFu)             /**< Get MemRamRmHigh from register */
#define  MEM_RAM_RME_HIGH_RSHIFT                            12                            /**< Shift for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH_RMASK                             0x1000u                       /**< Mask for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH_RBMASK                            0x1u                          /**< Base mask for MemRamRmeHigh */
#define  MEM_RAM_RME_HIGH_R(x)                              (((x)&0x1u)<<12)              /**< Set MemRamRmeHigh in register */
#define  GET_MEM_RAM_RME_HIGH_R(reg)                        (((reg)>>12)&0x1u)            /**< Get MemRamRmeHigh from register */

// RegMemRamMargin.regs.MemRamMarginLow
#define  MEM_RAM_MARGIN_LOW_GSHIFT                          16                            /**< Shift for group MemRamMarginLow */
#define  MEM_RAM_MARGIN_LOW_GSIZE                           16                            /**< Size of group MemRamMarginLow */
#define  MEM_RAM_MARGIN_LOW_GMASK                           0xFFFF0000u                   /**< Mask for group MemRamMarginLow */

#define  MEM_RAM_WA_LOW_RSHIFT                              0                             /**< Shift for MemRamWaLow */
#define  MEM_RAM_WA_LOW_RMASK                               0x0007u                       /**< Mask for MemRamWaLow */
#define  MEM_RAM_WA_LOW_RBMASK                              0x7u                          /**< Base mask for MemRamWaLow */
#define  MEM_RAM_WA_LOW_R(x)                                (((x)&0x7u)<<0)               /**< Set MemRamWaLow in register */
#define  GET_MEM_RAM_WA_LOW_R(reg)                          (((reg)>>0)&0x7u)             /**< Get MemRamWaLow from register */
#define  MEM_RAM_WPULSE_LOW_RSHIFT                          3                             /**< Shift for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW_RMASK                           0x0038u                       /**< Mask for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW_RBMASK                          0x7u                          /**< Base mask for MemRamWpulseLow */
#define  MEM_RAM_WPULSE_LOW_R(x)                            (((x)&0x7u)<<3)               /**< Set MemRamWpulseLow in register */
#define  GET_MEM_RAM_WPULSE_LOW_R(reg)                      (((reg)>>3)&0x7u)             /**< Get MemRamWpulseLow from register */
#define  MEM_RAM_RA_LOW_RSHIFT                              6                             /**< Shift for MemRamRaLow */
#define  MEM_RAM_RA_LOW_RMASK                               0x00C0u                       /**< Mask for MemRamRaLow */
#define  MEM_RAM_RA_LOW_RBMASK                              0x3u                          /**< Base mask for MemRamRaLow */
#define  MEM_RAM_RA_LOW_R(x)                                (((x)&0x3u)<<6)               /**< Set MemRamRaLow in register */
#define  GET_MEM_RAM_RA_LOW_R(reg)                          (((reg)>>6)&0x3u)             /**< Get MemRamRaLow from register */
#define  MEM_RAM_RM_LOW_RSHIFT                              8                             /**< Shift for MemRamRmLow */
#define  MEM_RAM_RM_LOW_RMASK                               0x0F00u                       /**< Mask for MemRamRmLow */
#define  MEM_RAM_RM_LOW_RBMASK                              0xFu                          /**< Base mask for MemRamRmLow */
#define  MEM_RAM_RM_LOW_R(x)                                (((x)&0xFu)<<8)               /**< Set MemRamRmLow in register */
#define  GET_MEM_RAM_RM_LOW_R(reg)                          (((reg)>>8)&0xFu)             /**< Get MemRamRmLow from register */
#define  MEM_RAM_RME_LOW_RSHIFT                             12                            /**< Shift for MemRamRmeLow */
#define  MEM_RAM_RME_LOW_RMASK                              0x1000u                       /**< Mask for MemRamRmeLow */
#define  MEM_RAM_RME_LOW_RBMASK                             0x1u                          /**< Base mask for MemRamRmeLow */
#define  MEM_RAM_RME_LOW_R(x)                               (((x)&0x1u)<<12)              /**< Set MemRamRmeLow in register */
#define  GET_MEM_RAM_RME_LOW_R(reg)                         (((reg)>>12)&0x1u)            /**< Get MemRamRmeLow from register */
/** @} */


/**
 * @name RegMemRomMargin
 * @{
 */
// RegMemRomMargin.r32
#define  REG_MEM_ROM_MARGIN_RESET_VALUE                     0x00120022u                   /**< Reset value of RegMemRomMargin */
#define  REG_MEM_ROM_MARGIN_MASK                            0x001F002Fu                   /**< Mask for RegMemRomMargin */

#define  MEM_ROM_RM_HIGH_SHIFT                              0                             /**< Shift for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH_MASK                               0x0000000Fu                   /**< Mask for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH_BMASK                              0xFu                          /**< Base mask for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH(x)                                 (((x)&0xFu)<<0)               /**< Set MemRomRmHigh in register */
#define  GET_MEM_ROM_RM_HIGH(reg)                           (((reg)>>0)&0xFu)             /**< Get MemRomRmHigh from register */
#define  MEM_ROM_RME_HIGH_SHIFT                             5                             /**< Shift for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH_MASK                              0x00000020u                   /**< Mask for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH_BMASK                             0x1u                          /**< Base mask for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH(x)                                (((x)&0x1u)<<5)               /**< Set MemRomRmeHigh in register */
#define  GET_MEM_ROM_RME_HIGH(reg)                          (((reg)>>5)&0x1u)             /**< Get MemRomRmeHigh from register */
#define  MEM_ROM_RM_LOW_SHIFT                               16                            /**< Shift for MemRomRmLow */
#define  MEM_ROM_RM_LOW_MASK                                0x000F0000u                   /**< Mask for MemRomRmLow */
#define  MEM_ROM_RM_LOW_BMASK                               0xFu                          /**< Base mask for MemRomRmLow */
#define  MEM_ROM_RM_LOW(x)                                  (((x)&0xFu)<<16)              /**< Set MemRomRmLow in register */
#define  GET_MEM_ROM_RM_LOW(reg)                            (((reg)>>16)&0xFu)            /**< Get MemRomRmLow from register */
#define  MEM_ROM_RME_LOW_SHIFT                              20                            /**< Shift for MemRomRmeLow */
#define  MEM_ROM_RME_LOW_MASK                               0x00100000u                   /**< Mask for MemRomRmeLow */
#define  MEM_ROM_RME_LOW_BMASK                              0x1u                          /**< Base mask for MemRomRmeLow */
#define  MEM_ROM_RME_LOW(x)                                 (((x)&0x1u)<<20)              /**< Set MemRomRmeLow in register */
#define  GET_MEM_ROM_RME_LOW(reg)                           (((reg)>>20)&0x1u)            /**< Get MemRomRmeLow from register */

// RegMemRomMargin.regs.MemRomMarginHigh
#define  MEM_ROM_MARGIN_HIGH_GSHIFT                         0                             /**< Shift for group MemRomMarginHigh */
#define  MEM_ROM_MARGIN_HIGH_GSIZE                          16                            /**< Size of group MemRomMarginHigh */
#define  MEM_ROM_MARGIN_HIGH_GMASK                          0x0000FFFFu                   /**< Mask for group MemRomMarginHigh */

#define  MEM_ROM_RM_HIGH_RSHIFT                             0                             /**< Shift for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH_RMASK                              0x000Fu                       /**< Mask for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH_RBMASK                             0xFu                          /**< Base mask for MemRomRmHigh */
#define  MEM_ROM_RM_HIGH_R(x)                               (((x)&0xFu)<<0)               /**< Set MemRomRmHigh in register */
#define  GET_MEM_ROM_RM_HIGH_R(reg)                         (((reg)>>0)&0xFu)             /**< Get MemRomRmHigh from register */
#define  MEM_ROM_RME_HIGH_RSHIFT                            5                             /**< Shift for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH_RMASK                             0x0020u                       /**< Mask for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH_RBMASK                            0x1u                          /**< Base mask for MemRomRmeHigh */
#define  MEM_ROM_RME_HIGH_R(x)                              (((x)&0x1u)<<5)               /**< Set MemRomRmeHigh in register */
#define  GET_MEM_ROM_RME_HIGH_R(reg)                        (((reg)>>5)&0x1u)             /**< Get MemRomRmeHigh from register */

// RegMemRomMargin.regs.MemRomMarginLow
#define  MEM_ROM_MARGIN_LOW_GSHIFT                          16                            /**< Shift for group MemRomMarginLow */
#define  MEM_ROM_MARGIN_LOW_GSIZE                           16                            /**< Size of group MemRomMarginLow */
#define  MEM_ROM_MARGIN_LOW_GMASK                           0xFFFF0000u                   /**< Mask for group MemRomMarginLow */

#define  MEM_ROM_RM_LOW_RSHIFT                              0                             /**< Shift for MemRomRmLow */
#define  MEM_ROM_RM_LOW_RMASK                               0x000Fu                       /**< Mask for MemRomRmLow */
#define  MEM_ROM_RM_LOW_RBMASK                              0xFu                          /**< Base mask for MemRomRmLow */
#define  MEM_ROM_RM_LOW_R(x)                                (((x)&0xFu)<<0)               /**< Set MemRomRmLow in register */
#define  GET_MEM_ROM_RM_LOW_R(reg)                          (((reg)>>0)&0xFu)             /**< Get MemRomRmLow from register */
#define  MEM_ROM_RME_LOW_RSHIFT                             4                             /**< Shift for MemRomRmeLow */
#define  MEM_ROM_RME_LOW_RMASK                              0x0010u                       /**< Mask for MemRomRmeLow */
#define  MEM_ROM_RME_LOW_RBMASK                             0x1u                          /**< Base mask for MemRomRmeLow */
#define  MEM_ROM_RME_LOW_R(x)                               (((x)&0x1u)<<4)               /**< Set MemRomRmeLow in register */
#define  GET_MEM_ROM_RME_LOW_R(reg)                         (((reg)>>4)&0x1u)             /**< Get MemRomRmeLow from register */
/** @} */


/**
 * @name RegMemCfg
 * @{
 */
// RegMemCfg.r32
#define  REG_MEM_CFG_RESET_VALUE                            0x00010000u                   /**< Reset value of RegMemCfg */
#define  REG_MEM_CFG_MASK                                   0x00010101u                   /**< Mask for RegMemCfg */

#define  MEM_DRAM6_IN_ICCM_SHIFT                            0                             /**< Shift for MemDram6InIccm */
#define  MEM_DRAM6_IN_ICCM_MASK                             0x00000001u                   /**< Mask for MemDram6InIccm */
#define  MEM_DRAM6_IN_ICCM_BMASK                            0x1u                          /**< Base mask for MemDram6InIccm */
#define  MEM_DRAM6_IN_ICCM(x)                               (((x)&0x1u)<<0)               /**< Set MemDram6InIccm in register */
#define  GET_MEM_DRAM6_IN_ICCM(reg)                         (((reg)>>0)&0x1u)             /**< Get MemDram6InIccm from register */
#define  MEM_DRAM5_IN_ICCM_SHIFT                            8                             /**< Shift for MemDram5InIccm */
#define  MEM_DRAM5_IN_ICCM_MASK                             0x00000100u                   /**< Mask for MemDram5InIccm */
#define  MEM_DRAM5_IN_ICCM_BMASK                            0x1u                          /**< Base mask for MemDram5InIccm */
#define  MEM_DRAM5_IN_ICCM(x)                               (((x)&0x1u)<<8)               /**< Set MemDram5InIccm in register */
#define  GET_MEM_DRAM5_IN_ICCM(reg)                         (((reg)>>8)&0x1u)             /**< Get MemDram5InIccm from register */
#define  MEM_DRAM0_IN_ICCM_SHIFT                            16                            /**< Shift for MemDram0InIccm */
#define  MEM_DRAM0_IN_ICCM_MASK                             0x00010000u                   /**< Mask for MemDram0InIccm */
#define  MEM_DRAM0_IN_ICCM_BMASK                            0x1u                          /**< Base mask for MemDram0InIccm */
#define  MEM_DRAM0_IN_ICCM(x)                               (((x)&0x1u)<<16)              /**< Set MemDram0InIccm in register */
#define  GET_MEM_DRAM0_IN_ICCM(reg)                         (((reg)>>16)&0x1u)            /**< Get MemDram0InIccm from register */
/** @} */


/**
 * @name RegMemTst
 * @{
 */
// RegMemTst.r32
#define  REG_MEM_TST_RESET_VALUE                            0x00000000u                   /**< Reset value of RegMemTst */
#define  REG_MEM_TST_MASK                                   0x0103017Fu                   /**< Mask for RegMemTst */

#define  MEM_DRAM0_TST_EN_SHIFT                             0                             /**< Shift for MemDram0TstEn */
#define  MEM_DRAM0_TST_EN_MASK                              0x00000001u                   /**< Mask for MemDram0TstEn */
#define  MEM_DRAM0_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram0TstEn */
#define  MEM_DRAM0_TST_EN(x)                                (((x)&0x1u)<<0)               /**< Set MemDram0TstEn in register */
#define  GET_MEM_DRAM0_TST_EN(reg)                          (((reg)>>0)&0x1u)             /**< Get MemDram0TstEn from register */
#define  MEM_DRAM1_TST_EN_SHIFT                             1                             /**< Shift for MemDram1TstEn */
#define  MEM_DRAM1_TST_EN_MASK                              0x00000002u                   /**< Mask for MemDram1TstEn */
#define  MEM_DRAM1_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram1TstEn */
#define  MEM_DRAM1_TST_EN(x)                                (((x)&0x1u)<<1)               /**< Set MemDram1TstEn in register */
#define  GET_MEM_DRAM1_TST_EN(reg)                          (((reg)>>1)&0x1u)             /**< Get MemDram1TstEn from register */
#define  MEM_DRAM2_TST_EN_SHIFT                             2                             /**< Shift for MemDram2TstEn */
#define  MEM_DRAM2_TST_EN_MASK                              0x00000004u                   /**< Mask for MemDram2TstEn */
#define  MEM_DRAM2_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram2TstEn */
#define  MEM_DRAM2_TST_EN(x)                                (((x)&0x1u)<<2)               /**< Set MemDram2TstEn in register */
#define  GET_MEM_DRAM2_TST_EN(reg)                          (((reg)>>2)&0x1u)             /**< Get MemDram2TstEn from register */
#define  MEM_DRAM3_TST_EN_SHIFT                             3                             /**< Shift for MemDram3TstEn */
#define  MEM_DRAM3_TST_EN_MASK                              0x00000008u                   /**< Mask for MemDram3TstEn */
#define  MEM_DRAM3_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram3TstEn */
#define  MEM_DRAM3_TST_EN(x)                                (((x)&0x1u)<<3)               /**< Set MemDram3TstEn in register */
#define  GET_MEM_DRAM3_TST_EN(reg)                          (((reg)>>3)&0x1u)             /**< Get MemDram3TstEn from register */
#define  MEM_DRAM4_TST_EN_SHIFT                             4                             /**< Shift for MemDram4TstEn */
#define  MEM_DRAM4_TST_EN_MASK                              0x00000010u                   /**< Mask for MemDram4TstEn */
#define  MEM_DRAM4_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram4TstEn */
#define  MEM_DRAM4_TST_EN(x)                                (((x)&0x1u)<<4)               /**< Set MemDram4TstEn in register */
#define  GET_MEM_DRAM4_TST_EN(reg)                          (((reg)>>4)&0x1u)             /**< Get MemDram4TstEn from register */
#define  MEM_DRAM5_TST_EN_SHIFT                             5                             /**< Shift for MemDram5TstEn */
#define  MEM_DRAM5_TST_EN_MASK                              0x00000020u                   /**< Mask for MemDram5TstEn */
#define  MEM_DRAM5_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram5TstEn */
#define  MEM_DRAM5_TST_EN(x)                                (((x)&0x1u)<<5)               /**< Set MemDram5TstEn in register */
#define  GET_MEM_DRAM5_TST_EN(reg)                          (((reg)>>5)&0x1u)             /**< Get MemDram5TstEn from register */
#define  MEM_DRAM6_TST_EN_SHIFT                             6                             /**< Shift for MemDram6TstEn */
#define  MEM_DRAM6_TST_EN_MASK                              0x00000040u                   /**< Mask for MemDram6TstEn */
#define  MEM_DRAM6_TST_EN_BMASK                             0x1u                          /**< Base mask for MemDram6TstEn */
#define  MEM_DRAM6_TST_EN(x)                                (((x)&0x1u)<<6)               /**< Set MemDram6TstEn in register */
#define  GET_MEM_DRAM6_TST_EN(reg)                          (((reg)>>6)&0x1u)             /**< Get MemDram6TstEn from register */
#define  MEM_USB_FIFO_TST_EN_SHIFT                          8                             /**< Shift for MemUsbFifoTstEn */
#define  MEM_USB_FIFO_TST_EN_MASK                           0x00000100u                   /**< Mask for MemUsbFifoTstEn */
#define  MEM_USB_FIFO_TST_EN_BMASK                          0x1u                          /**< Base mask for MemUsbFifoTstEn */
#define  MEM_USB_FIFO_TST_EN(x)                             (((x)&0x1u)<<8)               /**< Set MemUsbFifoTstEn in register */
#define  GET_MEM_USB_FIFO_TST_EN(reg)                       (((reg)>>8)&0x1u)             /**< Get MemUsbFifoTstEn from register */
#define  MEM_IC_DATA0_TST_EN_SHIFT                          16                            /**< Shift for MemIcData0TstEn */
#define  MEM_IC_DATA0_TST_EN_MASK                           0x00010000u                   /**< Mask for MemIcData0TstEn */
#define  MEM_IC_DATA0_TST_EN_BMASK                          0x1u                          /**< Base mask for MemIcData0TstEn */
#define  MEM_IC_DATA0_TST_EN(x)                             (((x)&0x1u)<<16)              /**< Set MemIcData0TstEn in register */
#define  GET_MEM_IC_DATA0_TST_EN(reg)                       (((reg)>>16)&0x1u)            /**< Get MemIcData0TstEn from register */
#define  MEM_IC_TAG0_TST_EN_SHIFT                           17                            /**< Shift for MemIcTag0TstEn */
#define  MEM_IC_TAG0_TST_EN_MASK                            0x00020000u                   /**< Mask for MemIcTag0TstEn */
#define  MEM_IC_TAG0_TST_EN_BMASK                           0x1u                          /**< Base mask for MemIcTag0TstEn */
#define  MEM_IC_TAG0_TST_EN(x)                              (((x)&0x1u)<<17)              /**< Set MemIcTag0TstEn in register */
#define  GET_MEM_IC_TAG0_TST_EN(reg)                        (((reg)>>17)&0x1u)            /**< Get MemIcTag0TstEn from register */
#define  MEM_ROM_TST_EN_SHIFT                               24                            /**< Shift for MemRomTstEn */
#define  MEM_ROM_TST_EN_MASK                                0x01000000u                   /**< Mask for MemRomTstEn */
#define  MEM_ROM_TST_EN_BMASK                               0x1u                          /**< Base mask for MemRomTstEn */
#define  MEM_ROM_TST_EN(x)                                  (((x)&0x1u)<<24)              /**< Set MemRomTstEn in register */
#define  GET_MEM_ROM_TST_EN(reg)                            (((reg)>>24)&0x1u)            /**< Get MemRomTstEn from register */
/** @} */


/**
 * @name RegDmaChSrcCfg1
 * @{
 */
// RegDmaChSrcCfg1.r32
#define  REG_DMA_CH_SRC_CFG1_RESET_VALUE                    0x00000000u                   /**< Reset value of RegDmaChSrcCfg1 */
#define  REG_DMA_CH_SRC_CFG1_MASK                           0x8F8F8F8Fu                   /**< Mask for RegDmaChSrcCfg1 */

#define  DMA_CH0_SRC_SEL_SHIFT                              0                             /**< Shift for DmaCh0SrcSel */
#define  DMA_CH0_SRC_SEL_MASK                               0x0000000Fu                   /**< Mask for DmaCh0SrcSel */
#define  DMA_CH0_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh0SrcSel */
#define  DMA_CH0_SRC_SEL(x)                                 (((x)&0xFu)<<0)               /**< Set DmaCh0SrcSel in register */
#define  GET_DMA_CH0_SRC_SEL(reg)                           (((reg)>>0)&0xFu)             /**< Get DmaCh0SrcSel from register */
#define  DMA_CH0_SREQ_SHIFT                                 7                             /**< Shift for DmaCh0Sreq */
#define  DMA_CH0_SREQ_MASK                                  0x00000080u                   /**< Mask for DmaCh0Sreq */
#define  DMA_CH0_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh0Sreq */
#define  DMA_CH0_SREQ(x)                                    (((x)&0x1u)<<7)               /**< Set DmaCh0Sreq in register */
#define  GET_DMA_CH0_SREQ(reg)                              (((reg)>>7)&0x1u)             /**< Get DmaCh0Sreq from register */
#define  DMA_CH1_SRC_SEL_SHIFT                              8                             /**< Shift for DmaCh1SrcSel */
#define  DMA_CH1_SRC_SEL_MASK                               0x00000F00u                   /**< Mask for DmaCh1SrcSel */
#define  DMA_CH1_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh1SrcSel */
#define  DMA_CH1_SRC_SEL(x)                                 (((x)&0xFu)<<8)               /**< Set DmaCh1SrcSel in register */
#define  GET_DMA_CH1_SRC_SEL(reg)                           (((reg)>>8)&0xFu)             /**< Get DmaCh1SrcSel from register */
#define  DMA_CH1_SREQ_SHIFT                                 15                            /**< Shift for DmaCh1Sreq */
#define  DMA_CH1_SREQ_MASK                                  0x00008000u                   /**< Mask for DmaCh1Sreq */
#define  DMA_CH1_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh1Sreq */
#define  DMA_CH1_SREQ(x)                                    (((x)&0x1u)<<15)              /**< Set DmaCh1Sreq in register */
#define  GET_DMA_CH1_SREQ(reg)                              (((reg)>>15)&0x1u)            /**< Get DmaCh1Sreq from register */
#define  DMA_CH2_SRC_SEL_SHIFT                              16                            /**< Shift for DmaCh2SrcSel */
#define  DMA_CH2_SRC_SEL_MASK                               0x000F0000u                   /**< Mask for DmaCh2SrcSel */
#define  DMA_CH2_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh2SrcSel */
#define  DMA_CH2_SRC_SEL(x)                                 (((x)&0xFu)<<16)              /**< Set DmaCh2SrcSel in register */
#define  GET_DMA_CH2_SRC_SEL(reg)                           (((reg)>>16)&0xFu)            /**< Get DmaCh2SrcSel from register */
#define  DMA_CH2_SREQ_SHIFT                                 23                            /**< Shift for DmaCh2Sreq */
#define  DMA_CH2_SREQ_MASK                                  0x00800000u                   /**< Mask for DmaCh2Sreq */
#define  DMA_CH2_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh2Sreq */
#define  DMA_CH2_SREQ(x)                                    (((x)&0x1u)<<23)              /**< Set DmaCh2Sreq in register */
#define  GET_DMA_CH2_SREQ(reg)                              (((reg)>>23)&0x1u)            /**< Get DmaCh2Sreq from register */
#define  DMA_CH3_SRC_SEL_SHIFT                              24                            /**< Shift for DmaCh3SrcSel */
#define  DMA_CH3_SRC_SEL_MASK                               0x0F000000u                   /**< Mask for DmaCh3SrcSel */
#define  DMA_CH3_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh3SrcSel */
#define  DMA_CH3_SRC_SEL(x)                                 (((x)&0xFu)<<24)              /**< Set DmaCh3SrcSel in register */
#define  GET_DMA_CH3_SRC_SEL(reg)                           (((reg)>>24)&0xFu)            /**< Get DmaCh3SrcSel from register */
#define  DMA_CH3_SREQ_SHIFT                                 31                            /**< Shift for DmaCh3Sreq */
#define  DMA_CH3_SREQ_MASK                                  0x80000000u                   /**< Mask for DmaCh3Sreq */
#define  DMA_CH3_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh3Sreq */
#define  DMA_CH3_SREQ(x)                                    (((x)&0x1u)<<31)              /**< Set DmaCh3Sreq in register */
#define  GET_DMA_CH3_SREQ(reg)                              (((reg)>>31)&0x1u)            /**< Get DmaCh3Sreq from register */
/** @} */


/**
 * @name RegDmaChSrcCfg2
 * @{
 */
// RegDmaChSrcCfg2.r32
#define  REG_DMA_CH_SRC_CFG2_RESET_VALUE                    0x00000000u                   /**< Reset value of RegDmaChSrcCfg2 */
#define  REG_DMA_CH_SRC_CFG2_MASK                           0x8F8F8F8Fu                   /**< Mask for RegDmaChSrcCfg2 */

#define  DMA_CH4_SRC_SEL_SHIFT                              0                             /**< Shift for DmaCh4SrcSel */
#define  DMA_CH4_SRC_SEL_MASK                               0x0000000Fu                   /**< Mask for DmaCh4SrcSel */
#define  DMA_CH4_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh4SrcSel */
#define  DMA_CH4_SRC_SEL(x)                                 (((x)&0xFu)<<0)               /**< Set DmaCh4SrcSel in register */
#define  GET_DMA_CH4_SRC_SEL(reg)                           (((reg)>>0)&0xFu)             /**< Get DmaCh4SrcSel from register */
#define  DMA_CH4_SREQ_SHIFT                                 7                             /**< Shift for DmaCh4Sreq */
#define  DMA_CH4_SREQ_MASK                                  0x00000080u                   /**< Mask for DmaCh4Sreq */
#define  DMA_CH4_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh4Sreq */
#define  DMA_CH4_SREQ(x)                                    (((x)&0x1u)<<7)               /**< Set DmaCh4Sreq in register */
#define  GET_DMA_CH4_SREQ(reg)                              (((reg)>>7)&0x1u)             /**< Get DmaCh4Sreq from register */
#define  DMA_CH5_SRC_SEL_SHIFT                              8                             /**< Shift for DmaCh5SrcSel */
#define  DMA_CH5_SRC_SEL_MASK                               0x00000F00u                   /**< Mask for DmaCh5SrcSel */
#define  DMA_CH5_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh5SrcSel */
#define  DMA_CH5_SRC_SEL(x)                                 (((x)&0xFu)<<8)               /**< Set DmaCh5SrcSel in register */
#define  GET_DMA_CH5_SRC_SEL(reg)                           (((reg)>>8)&0xFu)             /**< Get DmaCh5SrcSel from register */
#define  DMA_CH5_SREQ_SHIFT                                 15                            /**< Shift for DmaCh5Sreq */
#define  DMA_CH5_SREQ_MASK                                  0x00008000u                   /**< Mask for DmaCh5Sreq */
#define  DMA_CH5_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh5Sreq */
#define  DMA_CH5_SREQ(x)                                    (((x)&0x1u)<<15)              /**< Set DmaCh5Sreq in register */
#define  GET_DMA_CH5_SREQ(reg)                              (((reg)>>15)&0x1u)            /**< Get DmaCh5Sreq from register */
#define  DMA_CH6_SRC_SEL_SHIFT                              16                            /**< Shift for DmaCh6SrcSel */
#define  DMA_CH6_SRC_SEL_MASK                               0x000F0000u                   /**< Mask for DmaCh6SrcSel */
#define  DMA_CH6_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh6SrcSel */
#define  DMA_CH6_SRC_SEL(x)                                 (((x)&0xFu)<<16)              /**< Set DmaCh6SrcSel in register */
#define  GET_DMA_CH6_SRC_SEL(reg)                           (((reg)>>16)&0xFu)            /**< Get DmaCh6SrcSel from register */
#define  DMA_CH6_SREQ_SHIFT                                 23                            /**< Shift for DmaCh6Sreq */
#define  DMA_CH6_SREQ_MASK                                  0x00800000u                   /**< Mask for DmaCh6Sreq */
#define  DMA_CH6_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh6Sreq */
#define  DMA_CH6_SREQ(x)                                    (((x)&0x1u)<<23)              /**< Set DmaCh6Sreq in register */
#define  GET_DMA_CH6_SREQ(reg)                              (((reg)>>23)&0x1u)            /**< Get DmaCh6Sreq from register */
#define  DMA_CH7_SRC_SEL_SHIFT                              24                            /**< Shift for DmaCh7SrcSel */
#define  DMA_CH7_SRC_SEL_MASK                               0x0F000000u                   /**< Mask for DmaCh7SrcSel */
#define  DMA_CH7_SRC_SEL_BMASK                              0xFu                          /**< Base mask for DmaCh7SrcSel */
#define  DMA_CH7_SRC_SEL(x)                                 (((x)&0xFu)<<24)              /**< Set DmaCh7SrcSel in register */
#define  GET_DMA_CH7_SRC_SEL(reg)                           (((reg)>>24)&0xFu)            /**< Get DmaCh7SrcSel from register */
#define  DMA_CH7_SREQ_SHIFT                                 31                            /**< Shift for DmaCh7Sreq */
#define  DMA_CH7_SREQ_MASK                                  0x80000000u                   /**< Mask for DmaCh7Sreq */
#define  DMA_CH7_SREQ_BMASK                                 0x1u                          /**< Base mask for DmaCh7Sreq */
#define  DMA_CH7_SREQ(x)                                    (((x)&0x1u)<<31)              /**< Set DmaCh7Sreq in register */
#define  GET_DMA_CH7_SREQ(reg)                              (((reg)>>31)&0x1u)            /**< Get DmaCh7Sreq from register */
/** @} */


/**
 * @name RegUsbEn
 * @{
 */
// RegUsbEn.r32
#define  REG_USB_EN_RESET_VALUE                             0x00000000u                   /**< Reset value of RegUsbEn */
#define  REG_USB_EN_MASK                                    0x00000001u                   /**< Mask for RegUsbEn */

#define  USB_EN_SHIFT                                       0                             /**< Shift for UsbEn */
#define  USB_EN_MASK                                        0x00000001u                   /**< Mask for UsbEn */
#define  USB_EN_BMASK                                       0x1u                          /**< Base mask for UsbEn */
#define  USB_EN(x)                                          (((x)&0x1u)<<0)               /**< Set UsbEn in register */
#define  GET_USB_EN(reg)                                    (((reg)>>0)&0x1u)             /**< Get UsbEn from register */
/** @} */


/**
 * @name RegUsbTst
 * @{
 */
// RegUsbTst.r32
#define  REG_USB_TST_RESET_VALUE                            0x00000000u                   /**< Reset value of RegUsbTst */
#define  REG_USB_TST_MASK                                   0x00010307u                   /**< Mask for RegUsbTst */

#define  USB_TST_OVR_DM_SHIFT                               0                             /**< Shift for UsbTstOvrDm */
#define  USB_TST_OVR_DM_MASK                                0x00000001u                   /**< Mask for UsbTstOvrDm */
#define  USB_TST_OVR_DM_BMASK                               0x1u                          /**< Base mask for UsbTstOvrDm */
#define  USB_TST_OVR_DM(x)                                  (((x)&0x1u)<<0)               /**< Set UsbTstOvrDm in register */
#define  GET_USB_TST_OVR_DM(reg)                            (((reg)>>0)&0x1u)             /**< Get UsbTstOvrDm from register */
#define  USB_TST_OVR_DP_SHIFT                               1                             /**< Shift for UsbTstOvrDp */
#define  USB_TST_OVR_DP_MASK                                0x00000002u                   /**< Mask for UsbTstOvrDp */
#define  USB_TST_OVR_DP_BMASK                               0x1u                          /**< Base mask for UsbTstOvrDp */
#define  USB_TST_OVR_DP(x)                                  (((x)&0x1u)<<1)               /**< Set UsbTstOvrDp in register */
#define  GET_USB_TST_OVR_DP(reg)                            (((reg)>>1)&0x1u)             /**< Get UsbTstOvrDp from register */
#define  USB_TST_RX_RCV_DATA_IN_SHIFT                       2                             /**< Shift for UsbTstRxRcvDatain */
#define  USB_TST_RX_RCV_DATA_IN_MASK                        0x00000004u                   /**< Mask for UsbTstRxRcvDatain */
#define  USB_TST_RX_RCV_DATA_IN_BMASK                       0x1u                          /**< Base mask for UsbTstRxRcvDatain */
#define  USB_TST_RX_RCV_DATA_IN(x)                          (((x)&0x1u)<<2)               /**< Set UsbTstRxRcvDatain in register */
#define  GET_USB_TST_RX_RCV_DATA_IN(reg)                    (((reg)>>2)&0x1u)             /**< Get UsbTstRxRcvDatain from register */
#define  USB_TST_OVR_DM_CLR_SHIFT                           8                             /**< Shift for UsbTstOvrDmClr */
#define  USB_TST_OVR_DM_CLR_MASK                            0x00000100u                   /**< Mask for UsbTstOvrDmClr */
#define  USB_TST_OVR_DM_CLR_BMASK                           0x1u                          /**< Base mask for UsbTstOvrDmClr */
#define  USB_TST_OVR_DM_CLR(x)                              (((x)&0x1u)<<8)               /**< Set UsbTstOvrDmClr in register */
#define  GET_USB_TST_OVR_DM_CLR(reg)                        (((reg)>>8)&0x1u)             /**< Get UsbTstOvrDmClr from register */
#define  USB_TST_OVR_DP_CLR_SHIFT                           9                             /**< Shift for UsbTstOvrDpClr */
#define  USB_TST_OVR_DP_CLR_MASK                            0x00000200u                   /**< Mask for UsbTstOvrDpClr */
#define  USB_TST_OVR_DP_CLR_BMASK                           0x1u                          /**< Base mask for UsbTstOvrDpClr */
#define  USB_TST_OVR_DP_CLR(x)                              (((x)&0x1u)<<9)               /**< Set UsbTstOvrDpClr in register */
#define  GET_USB_TST_OVR_DP_CLR(reg)                        (((reg)>>9)&0x1u)             /**< Get UsbTstOvrDpClr from register */
#define  USB_TST_OVR_CAP_EN_SHIFT                           16                            /**< Shift for UsbTstOvrCapEn */
#define  USB_TST_OVR_CAP_EN_MASK                            0x00010000u                   /**< Mask for UsbTstOvrCapEn */
#define  USB_TST_OVR_CAP_EN_BMASK                           0x1u                          /**< Base mask for UsbTstOvrCapEn */
#define  USB_TST_OVR_CAP_EN(x)                              (((x)&0x1u)<<16)              /**< Set UsbTstOvrCapEn in register */
#define  GET_USB_TST_OVR_CAP_EN(reg)                        (((reg)>>16)&0x1u)            /**< Get UsbTstOvrCapEn from register */
/** @} */


/**
 * @name RegDPRTstSel0
 * @{
 */
// RegDPRTstSel0.r32
#define  REG_DPR_TST_SEL0_RESET_VALUE                       0x00000000u                   /**< Reset value of RegDPRTstSel0 */
#define  REG_DPR_TST_SEL0_MASK                              0x3F3F3F3Fu                   /**< Mask for RegDPRTstSel0 */

#define  SYS_GPIO4_TST_MODE_SHIFT                           0                             /**< Shift for SysGPIO4TstMode */
#define  SYS_GPIO4_TST_MODE_MASK                            0x0000003Fu                   /**< Mask for SysGPIO4TstMode */
#define  SYS_GPIO4_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO4TstMode */
#define  SYS_GPIO4_TST_MODE(x)                              (((x)&0x3Fu)<<0)              /**< Set SysGPIO4TstMode in register */
#define  GET_SYS_GPIO4_TST_MODE(reg)                        (((reg)>>0)&0x3Fu)            /**< Get SysGPIO4TstMode from register */
#define  SYS_GPIO5_TST_MODE_SHIFT                           8                             /**< Shift for SysGPIO5TstMode */
#define  SYS_GPIO5_TST_MODE_MASK                            0x00003F00u                   /**< Mask for SysGPIO5TstMode */
#define  SYS_GPIO5_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO5TstMode */
#define  SYS_GPIO5_TST_MODE(x)                              (((x)&0x3Fu)<<8)              /**< Set SysGPIO5TstMode in register */
#define  GET_SYS_GPIO5_TST_MODE(reg)                        (((reg)>>8)&0x3Fu)            /**< Get SysGPIO5TstMode from register */
#define  SYS_GPIO6_TST_MODE_SHIFT                           16                            /**< Shift for SysGPIO6TstMode */
#define  SYS_GPIO6_TST_MODE_MASK                            0x003F0000u                   /**< Mask for SysGPIO6TstMode */
#define  SYS_GPIO6_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO6TstMode */
#define  SYS_GPIO6_TST_MODE(x)                              (((x)&0x3Fu)<<16)             /**< Set SysGPIO6TstMode in register */
#define  GET_SYS_GPIO6_TST_MODE(reg)                        (((reg)>>16)&0x3Fu)           /**< Get SysGPIO6TstMode from register */
#define  SYS_GPIO7_TST_MODE_SHIFT                           24                            /**< Shift for SysGPIO7TstMode */
#define  SYS_GPIO7_TST_MODE_MASK                            0x3F000000u                   /**< Mask for SysGPIO7TstMode */
#define  SYS_GPIO7_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO7TstMode */
#define  SYS_GPIO7_TST_MODE(x)                              (((x)&0x3Fu)<<24)             /**< Set SysGPIO7TstMode in register */
#define  GET_SYS_GPIO7_TST_MODE(reg)                        (((reg)>>24)&0x3Fu)           /**< Get SysGPIO7TstMode from register */
/** @} */


/**
 * @name RegDPRTstSel1
 * @{
 */
// RegDPRTstSel1.r32
#define  REG_DPR_TST_SEL1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegDPRTstSel1 */
#define  REG_DPR_TST_SEL1_MASK                              0x3F3F3F3Fu                   /**< Mask for RegDPRTstSel1 */

#define  SYS_GPIO8_TST_MODE_SHIFT                           0                             /**< Shift for SysGPIO8TstMode */
#define  SYS_GPIO8_TST_MODE_MASK                            0x0000003Fu                   /**< Mask for SysGPIO8TstMode */
#define  SYS_GPIO8_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO8TstMode */
#define  SYS_GPIO8_TST_MODE(x)                              (((x)&0x3Fu)<<0)              /**< Set SysGPIO8TstMode in register */
#define  GET_SYS_GPIO8_TST_MODE(reg)                        (((reg)>>0)&0x3Fu)            /**< Get SysGPIO8TstMode from register */
#define  SYS_GPIO9_TST_MODE_SHIFT                           8                             /**< Shift for SysGPIO9TstMode */
#define  SYS_GPIO9_TST_MODE_MASK                            0x00003F00u                   /**< Mask for SysGPIO9TstMode */
#define  SYS_GPIO9_TST_MODE_BMASK                           0x3Fu                         /**< Base mask for SysGPIO9TstMode */
#define  SYS_GPIO9_TST_MODE(x)                              (((x)&0x3Fu)<<8)              /**< Set SysGPIO9TstMode in register */
#define  GET_SYS_GPIO9_TST_MODE(reg)                        (((reg)>>8)&0x3Fu)            /**< Get SysGPIO9TstMode from register */
#define  SYS_GPIO10_TST_MODE_SHIFT                          16                            /**< Shift for SysGPIO10TstMode */
#define  SYS_GPIO10_TST_MODE_MASK                           0x003F0000u                   /**< Mask for SysGPIO10TstMode */
#define  SYS_GPIO10_TST_MODE_BMASK                          0x3Fu                         /**< Base mask for SysGPIO10TstMode */
#define  SYS_GPIO10_TST_MODE(x)                             (((x)&0x3Fu)<<16)             /**< Set SysGPIO10TstMode in register */
#define  GET_SYS_GPIO10_TST_MODE(reg)                       (((reg)>>16)&0x3Fu)           /**< Get SysGPIO10TstMode from register */
#define  SYS_GPIO11_TST_MODE_SHIFT                          24                            /**< Shift for SysGPIO11TstMode */
#define  SYS_GPIO11_TST_MODE_MASK                           0x3F000000u                   /**< Mask for SysGPIO11TstMode */
#define  SYS_GPIO11_TST_MODE_BMASK                          0x3Fu                         /**< Base mask for SysGPIO11TstMode */
#define  SYS_GPIO11_TST_MODE(x)                             (((x)&0x3Fu)<<24)             /**< Set SysGPIO11TstMode in register */
#define  GET_SYS_GPIO11_TST_MODE(reg)                       (((reg)>>24)&0x3Fu)           /**< Get SysGPIO11TstMode from register */
/** @} */


/**
 * @name RegDprTstCfg1
 * @{
 */
// RegDprTstCfg1.r32
#define  REG_DPR_TST_CFG1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegDprTstCfg1 */
#define  REG_DPR_TST_CFG1_MASK                              0x00000317u                   /**< Mask for RegDprTstCfg1 */

#define  DPR_TST_CLK_SEL_SHIFT                              0                             /**< Shift for DprTstClkSel */
#define  DPR_TST_CLK_SEL_MASK                               0x00000007u                   /**< Mask for DprTstClkSel */
#define  DPR_TST_CLK_SEL_BMASK                              0x7u                          /**< Base mask for DprTstClkSel */
#define  DPR_TST_CLK_SEL(x)                                 (((x)&0x7u)<<0)               /**< Set DprTstClkSel in register */
#define  GET_DPR_TST_CLK_SEL(reg)                           (((reg)>>0)&0x7u)             /**< Get DprTstClkSel from register */
#define  DPR_TST_CLK_EN_SHIFT                               4                             /**< Shift for DprTstClkEn */
#define  DPR_TST_CLK_EN_MASK                                0x00000010u                   /**< Mask for DprTstClkEn */
#define  DPR_TST_CLK_EN_BMASK                               0x1u                          /**< Base mask for DprTstClkEn */
#define  DPR_TST_CLK_EN(x)                                  (((x)&0x1u)<<4)               /**< Set DprTstClkEn in register */
#define  GET_DPR_TST_CLK_EN(reg)                            (((reg)>>4)&0x1u)             /**< Get DprTstClkEn from register */
#define  DPR_TST_DLL_EN_SHIFT                               8                             /**< Shift for DprTstDllEn */
#define  DPR_TST_DLL_EN_MASK                                0x00000100u                   /**< Mask for DprTstDllEn */
#define  DPR_TST_DLL_EN_BMASK                               0x1u                          /**< Base mask for DprTstDllEn */
#define  DPR_TST_DLL_EN(x)                                  (((x)&0x1u)<<8)               /**< Set DprTstDllEn in register */
#define  GET_DPR_TST_DLL_EN(reg)                            (((reg)>>8)&0x1u)             /**< Get DprTstDllEn from register */
#define  DPR_TST_DLL_RES_N_SHIFT                            9                             /**< Shift for DprTstDllResN */
#define  DPR_TST_DLL_RES_N_MASK                             0x00000200u                   /**< Mask for DprTstDllResN */
#define  DPR_TST_DLL_RES_N_BMASK                            0x1u                          /**< Base mask for DprTstDllResN */
#define  DPR_TST_DLL_RES_N(x)                               (((x)&0x1u)<<9)               /**< Set DprTstDllResN in register */
#define  GET_DPR_TST_DLL_RES_N(reg)                         (((reg)>>9)&0x1u)             /**< Get DprTstDllResN from register */
/** @} */


/**
 * @name RegPmlSts
 * @{
 */
// RegPmlSts.r32
#define  REG_PML_STS_RESET_VALUE                            0x00000000u                   /**< Reset value of RegPmlSts */
#define  REG_PML_STS_MASK                                   0x1F03031Fu                   /**< Mask for RegPmlSts */

#define  PML_VBAT_MON_STAT_SHIFT                            0                             /**< Shift for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT_MASK                             0x00000001u                   /**< Mask for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT_BMASK                            0x1u                          /**< Base mask for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT(x)                               (((x)&0x1u)<<0)               /**< Set PmlVBATMonStat in register */
#define  GET_PML_VBAT_MON_STAT(reg)                         (((reg)>>0)&0x1u)             /**< Get PmlVBATMonStat from register */
#define  PML_PWR_CHK_STAT_SHIFT                             1                             /**< Shift for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT_MASK                              0x00000002u                   /**< Mask for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT_BMASK                             0x1u                          /**< Base mask for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT(x)                                (((x)&0x1u)<<1)               /**< Set PmlPwrChkStat in register */
#define  GET_PML_PWR_CHK_STAT(reg)                          (((reg)>>1)&0x1u)             /**< Get PmlPwrChkStat from register */
#define  PML_VCC_COMP_STAT_SHIFT                            2                             /**< Shift for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT_MASK                             0x00000004u                   /**< Mask for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT_BMASK                            0x1u                          /**< Base mask for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT(x)                               (((x)&0x1u)<<2)               /**< Set PmlVCCCompStat in register */
#define  GET_PML_VCC_COMP_STAT(reg)                         (((reg)>>2)&0x1u)             /**< Get PmlVCCCompStat from register */
#define  PML_VBAT1_COMP_STAT_SHIFT                          3                             /**< Shift for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT_MASK                           0x00000008u                   /**< Mask for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT_BMASK                          0x1u                          /**< Base mask for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT(x)                             (((x)&0x1u)<<3)               /**< Set PmlVBAT1CompStat in register */
#define  GET_PML_VBAT1_COMP_STAT(reg)                       (((reg)>>3)&0x1u)             /**< Get PmlVBAT1CompStat from register */
#define  PML_NVM_BO_COMP_STAT_SHIFT                         4                             /**< Shift for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT_MASK                          0x00000010u                   /**< Mask for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT_BMASK                         0x1u                          /**< Base mask for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT(x)                            (((x)&0x1u)<<4)               /**< Set PmlNvmBoCompStat in register */
#define  GET_PML_NVM_BO_COMP_STAT(reg)                      (((reg)>>4)&0x1u)             /**< Get PmlNvmBoCompStat from register */
#define  PML_QDEC_ON_SHIFT                                  8                             /**< Shift for PmlQDECOn */
#define  PML_QDEC_ON_MASK                                   0x00000100u                   /**< Mask for PmlQDECOn */
#define  PML_QDEC_ON_BMASK                                  0x1u                          /**< Base mask for PmlQDECOn */
#define  PML_QDEC_ON(x)                                     (((x)&0x1u)<<8)               /**< Set PmlQDECOn in register */
#define  GET_PML_QDEC_ON(reg)                               (((reg)>>8)&0x1u)             /**< Get PmlQDECOn from register */
#define  PML_NVM_ON_SHIFT                                   9                             /**< Shift for PmlNvmOn */
#define  PML_NVM_ON_MASK                                    0x00000200u                   /**< Mask for PmlNvmOn */
#define  PML_NVM_ON_BMASK                                   0x1u                          /**< Base mask for PmlNvmOn */
#define  PML_NVM_ON(x)                                      (((x)&0x1u)<<9)               /**< Set PmlNvmOn in register */
#define  GET_PML_NVM_ON(reg)                                (((reg)>>9)&0x1u)             /**< Get PmlNvmOn from register */
#define  ST_BUSY_SHIFT                                      16                            /**< Shift for STBusy */
#define  ST_BUSY_MASK                                       0x00010000u                   /**< Mask for STBusy */
#define  ST_BUSY_BMASK                                      0x1u                          /**< Base mask for STBusy */
#define  ST_BUSY(x)                                         (((x)&0x1u)<<16)              /**< Set STBusy in register */
#define  GET_ST_BUSY(reg)                                   (((reg)>>16)&0x1u)            /**< Get STBusy from register */
#define  ST_RUNNING_SHIFT                                   17                            /**< Shift for STRunning */
#define  ST_RUNNING_MASK                                    0x00020000u                   /**< Mask for STRunning */
#define  ST_RUNNING_BMASK                                   0x1u                          /**< Base mask for STRunning */
#define  ST_RUNNING(x)                                      (((x)&0x1u)<<17)              /**< Set STRunning in register */
#define  GET_ST_RUNNING(reg)                                (((reg)>>17)&0x1u)            /**< Get STRunning from register */
#define  PML_SYS_MODE_SHIFT                                 24                            /**< Shift for PmlSysMode */
#define  PML_SYS_MODE_MASK                                  0x03000000u                   /**< Mask for PmlSysMode */
#define  PML_SYS_MODE_BMASK                                 0x3u                          /**< Base mask for PmlSysMode */
#define  PML_SYS_MODE(x)                                    (((x)&0x3u)<<24)              /**< Set PmlSysMode in register */
#define  GET_PML_SYS_MODE(reg)                              (((reg)>>24)&0x3u)            /**< Get PmlSysMode from register */
#define  PML_APP_MODE_SHIFT                                 26                            /**< Shift for PmlAppMode */
#define  PML_APP_MODE_MASK                                  0x0C000000u                   /**< Mask for PmlAppMode */
#define  PML_APP_MODE_BMASK                                 0x3u                          /**< Base mask for PmlAppMode */
#define  PML_APP_MODE(x)                                    (((x)&0x3u)<<26)              /**< Set PmlAppMode in register */
#define  GET_PML_APP_MODE(reg)                              (((reg)>>26)&0x3u)            /**< Get PmlAppMode from register */
#define  USB_DETECTED_SHIFT                                 28                            /**< Shift for UsbDetected */
#define  USB_DETECTED_MASK                                  0x10000000u                   /**< Mask for UsbDetected */
#define  USB_DETECTED_BMASK                                 0x1u                          /**< Base mask for UsbDetected */
#define  USB_DETECTED(x)                                    (((x)&0x1u)<<28)              /**< Set UsbDetected in register */
#define  GET_USB_DETECTED(reg)                              (((reg)>>28)&0x1u)            /**< Get UsbDetected from register */

// RegPmlSts.regs.PmlCompSts
#define  PML_COMP_STS_GSHIFT                                0                             /**< Shift for group PmlCompSts */
#define  PML_COMP_STS_GSIZE                                 8                             /**< Size of group PmlCompSts */
#define  PML_COMP_STS_GMASK                                 0x000000FFu                   /**< Mask for group PmlCompSts */

#define  PML_VBAT_MON_STAT_RSHIFT                           0                             /**< Shift for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT_RMASK                            0x01u                         /**< Mask for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT_RBMASK                           0x1u                          /**< Base mask for PmlVBATMonStat */
#define  PML_VBAT_MON_STAT_R(x)                             (((x)&0x1u)<<0)               /**< Set PmlVBATMonStat in register */
#define  GET_PML_VBAT_MON_STAT_R(reg)                       (((reg)>>0)&0x1u)             /**< Get PmlVBATMonStat from register */
#define  PML_PWR_CHK_STAT_RSHIFT                            1                             /**< Shift for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT_RMASK                             0x02u                         /**< Mask for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT_RBMASK                            0x1u                          /**< Base mask for PmlPwrChkStat */
#define  PML_PWR_CHK_STAT_R(x)                              (((x)&0x1u)<<1)               /**< Set PmlPwrChkStat in register */
#define  GET_PML_PWR_CHK_STAT_R(reg)                        (((reg)>>1)&0x1u)             /**< Get PmlPwrChkStat from register */
#define  PML_VCC_COMP_STAT_RSHIFT                           2                             /**< Shift for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT_RMASK                            0x04u                         /**< Mask for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT_RBMASK                           0x1u                          /**< Base mask for PmlVCCCompStat */
#define  PML_VCC_COMP_STAT_R(x)                             (((x)&0x1u)<<2)               /**< Set PmlVCCCompStat in register */
#define  GET_PML_VCC_COMP_STAT_R(reg)                       (((reg)>>2)&0x1u)             /**< Get PmlVCCCompStat from register */
#define  PML_VBAT1_COMP_STAT_RSHIFT                         3                             /**< Shift for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT_RMASK                          0x08u                         /**< Mask for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT_RBMASK                         0x1u                          /**< Base mask for PmlVBAT1CompStat */
#define  PML_VBAT1_COMP_STAT_R(x)                           (((x)&0x1u)<<3)               /**< Set PmlVBAT1CompStat in register */
#define  GET_PML_VBAT1_COMP_STAT_R(reg)                     (((reg)>>3)&0x1u)             /**< Get PmlVBAT1CompStat from register */
#define  PML_NVM_BO_COMP_STAT_RSHIFT                        4                             /**< Shift for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT_RMASK                         0x10u                         /**< Mask for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT_RBMASK                        0x1u                          /**< Base mask for PmlNvmBoCompStat */
#define  PML_NVM_BO_COMP_STAT_R(x)                          (((x)&0x1u)<<4)               /**< Set PmlNvmBoCompStat in register */
#define  GET_PML_NVM_BO_COMP_STAT_R(reg)                    (((reg)>>4)&0x1u)             /**< Get PmlNvmBoCompStat from register */

// RegPmlSts.regs.PmlDomainSts
#define  PML_DOMAIN_STS_GSHIFT                              8                             /**< Shift for group PmlDomainSts */
#define  PML_DOMAIN_STS_GSIZE                               8                             /**< Size of group PmlDomainSts */
#define  PML_DOMAIN_STS_GMASK                               0x0000FF00u                   /**< Mask for group PmlDomainSts */

#define  PML_QDEC_ON_RSHIFT                                 0                             /**< Shift for PmlQDECOn */
#define  PML_QDEC_ON_RMASK                                  0x01u                         /**< Mask for PmlQDECOn */
#define  PML_QDEC_ON_RBMASK                                 0x1u                          /**< Base mask for PmlQDECOn */
#define  PML_QDEC_ON_R(x)                                   (((x)&0x1u)<<0)               /**< Set PmlQDECOn in register */
#define  GET_PML_QDEC_ON_R(reg)                             (((reg)>>0)&0x1u)             /**< Get PmlQDECOn from register */
#define  PML_NVM_ON_RSHIFT                                  1                             /**< Shift for PmlNvmOn */
#define  PML_NVM_ON_RMASK                                   0x02u                         /**< Mask for PmlNvmOn */
#define  PML_NVM_ON_RBMASK                                  0x1u                          /**< Base mask for PmlNvmOn */
#define  PML_NVM_ON_R(x)                                    (((x)&0x1u)<<1)               /**< Set PmlNvmOn in register */
#define  GET_PML_NVM_ON_R(reg)                              (((reg)>>1)&0x1u)             /**< Get PmlNvmOn from register */

// RegPmlSts.regs.STStat
#define  ST_STAT_GSHIFT                                     16                            /**< Shift for group STStat */
#define  ST_STAT_GSIZE                                      8                             /**< Size of group STStat */
#define  ST_STAT_GMASK                                      0x00FF0000u                   /**< Mask for group STStat */

#define  ST_BUSY_RSHIFT                                     0                             /**< Shift for STBusy */
#define  ST_BUSY_RMASK                                      0x01u                         /**< Mask for STBusy */
#define  ST_BUSY_RBMASK                                     0x1u                          /**< Base mask for STBusy */
#define  ST_BUSY_R(x)                                       (((x)&0x1u)<<0)               /**< Set STBusy in register */
#define  GET_ST_BUSY_R(reg)                                 (((reg)>>0)&0x1u)             /**< Get STBusy from register */
#define  ST_RUNNING_RSHIFT                                  1                             /**< Shift for STRunning */
#define  ST_RUNNING_RMASK                                   0x02u                         /**< Mask for STRunning */
#define  ST_RUNNING_RBMASK                                  0x1u                          /**< Base mask for STRunning */
#define  ST_RUNNING_R(x)                                    (((x)&0x1u)<<1)               /**< Set STRunning in register */
#define  GET_ST_RUNNING_R(reg)                              (((reg)>>1)&0x1u)             /**< Get STRunning from register */

// RegPmlSts.regs.PmlMode
#define  PML_MODE_GSHIFT                                    24                            /**< Shift for group PmlMode */
#define  PML_MODE_GSIZE                                     8                             /**< Size of group PmlMode */
#define  PML_MODE_GMASK                                     0xFF000000u                   /**< Mask for group PmlMode */

#define  PML_SYS_MODE_RSHIFT                                0                             /**< Shift for PmlSysMode */
#define  PML_SYS_MODE_RMASK                                 0x03u                         /**< Mask for PmlSysMode */
#define  PML_SYS_MODE_RBMASK                                0x3u                          /**< Base mask for PmlSysMode */
#define  PML_SYS_MODE_R(x)                                  (((x)&0x3u)<<0)               /**< Set PmlSysMode in register */
#define  GET_PML_SYS_MODE_R(reg)                            (((reg)>>0)&0x3u)             /**< Get PmlSysMode from register */
#define  PML_APP_MODE_RSHIFT                                2                             /**< Shift for PmlAppMode */
#define  PML_APP_MODE_RMASK                                 0x0Cu                         /**< Mask for PmlAppMode */
#define  PML_APP_MODE_RBMASK                                0x3u                          /**< Base mask for PmlAppMode */
#define  PML_APP_MODE_R(x)                                  (((x)&0x3u)<<2)               /**< Set PmlAppMode in register */
#define  GET_PML_APP_MODE_R(reg)                            (((reg)>>2)&0x3u)             /**< Get PmlAppMode from register */
#define  USB_DETECTED_RSHIFT                                4                             /**< Shift for UsbDetected */
#define  USB_DETECTED_RMASK                                 0x10u                         /**< Mask for UsbDetected */
#define  USB_DETECTED_RBMASK                                0x1u                          /**< Base mask for UsbDetected */
#define  USB_DETECTED_R(x)                                  (((x)&0x1u)<<4)               /**< Set UsbDetected in register */
#define  GET_USB_DETECTED_R(reg)                            (((reg)>>4)&0x1u)             /**< Get UsbDetected from register */
/** @} */


/**
 * @name RegPmlWakeSts
 * @{
 */
// RegPmlWakeSts.r32
#define  REG_PML_WAKE_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegPmlWakeSts */
#define  REG_PML_WAKE_STS_MASK                              0x070F0FFFu                   /**< Mask for RegPmlWakeSts */

#define  PML_WAKE_PAD_STS_SHIFT                             0                             /**< Shift for PmlWakePadSts */
#define  PML_WAKE_PAD_STS_MASK                              0x00000FFFu                   /**< Mask for PmlWakePadSts */
#define  PML_WAKE_PAD_STS_BMASK                             0xFFFu                        /**< Base mask for PmlWakePadSts */
#define  PML_WAKE_PAD_STS(x)                                (((x)&0xFFFu)<<0)             /**< Set PmlWakePadSts in register */
#define  GET_PML_WAKE_PAD_STS(reg)                          (((reg)>>0)&0xFFFu)           /**< Get PmlWakePadSts from register */
#define  PML_WAKE_SLEEP_TIM_STS_SHIFT                       16                            /**< Shift for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_MASK                        0x000F0000u                   /**< Mask for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_BMASK                       0xFu                          /**< Base mask for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS(x)                          (((x)&0xFu)<<16)              /**< Set PmlWakeSleepTimSts in register */
#define  GET_PML_WAKE_SLEEP_TIM_STS(reg)                    (((reg)>>16)&0xFu)            /**< Get PmlWakeSleepTimSts from register */
#define  PML_WAKE_QDEC_REP_RDY_STS_SHIFT                    24                            /**< Shift for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS_MASK                     0x01000000u                   /**< Mask for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS_BMASK                    0x1u                          /**< Base mask for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS(x)                       (((x)&0x1u)<<24)              /**< Set PmlWakeQDecRepRdySts in register */
#define  GET_PML_WAKE_QDEC_REP_RDY_STS(reg)                 (((reg)>>24)&0x1u)            /**< Get PmlWakeQDecRepRdySts from register */
#define  PML_WAKE_QDEC_OVF_STS_SHIFT                        25                            /**< Shift for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS_MASK                         0x02000000u                   /**< Mask for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS_BMASK                        0x1u                          /**< Base mask for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS(x)                           (((x)&0x1u)<<25)              /**< Set PmlWakeQDecOvfSts in register */
#define  GET_PML_WAKE_QDEC_OVF_STS(reg)                     (((reg)>>25)&0x1u)            /**< Get PmlWakeQDecOvfSts from register */
#define  PML_WAKE_QDEC_DBL_STS_SHIFT                        26                            /**< Shift for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS_MASK                         0x04000000u                   /**< Mask for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS_BMASK                        0x1u                          /**< Base mask for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS(x)                           (((x)&0x1u)<<26)              /**< Set PmlWakeQDecDblSts in register */
#define  GET_PML_WAKE_QDEC_DBL_STS(reg)                     (((reg)>>26)&0x1u)            /**< Get PmlWakeQDecDblSts from register */

// RegPmlWakeSts.regs.PmlWakePadSts
#define  PML_WAKE_PAD_STS_GSHIFT                            0                             /**< Shift for group PmlWakePadSts */
#define  PML_WAKE_PAD_STS_GSIZE                             16                            /**< Size of group PmlWakePadSts */
#define  PML_WAKE_PAD_STS_GMASK                             0x0000FFFFu                   /**< Mask for group PmlWakePadSts */

#define  PML_WAKE_PAD_STS_RSHIFT                            0                             /**< Shift for PmlWakePadSts */
#define  PML_WAKE_PAD_STS_RMASK                             0x00000FFFu                   /**< Mask for PmlWakePadSts */
#define  PML_WAKE_PAD_STS_RBMASK                            0xFFFu                        /**< Base mask for PmlWakePadSts */
#define  PML_WAKE_PAD_STS_R(x)                              (((x)&0xFFFu)<<0)             /**< Set PmlWakePadSts in register */
#define  GET_PML_WAKE_PAD_STS_R(reg)                        (((reg)>>0)&0xFFFu)           /**< Get PmlWakePadSts from register */

// RegPmlWakeSts.regs.PmlWakeSleepTimSts
#define  PML_WAKE_SLEEP_TIM_STS_GSHIFT                      16                            /**< Shift for group PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_GSIZE                       8                             /**< Size of group PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_GMASK                       0x00FF0000u                   /**< Mask for group PmlWakeSleepTimSts */

#define  PML_WAKE_SLEEP_TIM_STS_RSHIFT                      0                             /**< Shift for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_RMASK                       0x0000000Fu                   /**< Mask for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_RBMASK                      0xFu                          /**< Base mask for PmlWakeSleepTimSts */
#define  PML_WAKE_SLEEP_TIM_STS_R(x)                        (((x)&0xFu)<<0)               /**< Set PmlWakeSleepTimSts in register */
#define  GET_PML_WAKE_SLEEP_TIM_STS_R(reg)                  (((reg)>>0)&0xFu)             /**< Get PmlWakeSleepTimSts from register */

// RegPmlWakeSts.regs.PmlWakeQDecSts
#define  PML_WAKE_QDEC_STS_GSHIFT                           24                            /**< Shift for group PmlWakeQDecSts */
#define  PML_WAKE_QDEC_STS_GSIZE                            8                             /**< Size of group PmlWakeQDecSts */
#define  PML_WAKE_QDEC_STS_GMASK                            0xFF000000u                   /**< Mask for group PmlWakeQDecSts */

#define  PML_WAKE_QDEC_REP_RDY_STS_RSHIFT                   0                             /**< Shift for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS_RMASK                    0x01u                         /**< Mask for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS_RBMASK                   0x1u                          /**< Base mask for PmlWakeQDecRepRdySts */
#define  PML_WAKE_QDEC_REP_RDY_STS_R(x)                     (((x)&0x1u)<<0)               /**< Set PmlWakeQDecRepRdySts in register */
#define  GET_PML_WAKE_QDEC_REP_RDY_STS_R(reg)               (((reg)>>0)&0x1u)             /**< Get PmlWakeQDecRepRdySts from register */
#define  PML_WAKE_QDEC_OVF_STS_RSHIFT                       1                             /**< Shift for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS_RMASK                        0x02u                         /**< Mask for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS_RBMASK                       0x1u                          /**< Base mask for PmlWakeQDecOvfSts */
#define  PML_WAKE_QDEC_OVF_STS_R(x)                         (((x)&0x1u)<<1)               /**< Set PmlWakeQDecOvfSts in register */
#define  GET_PML_WAKE_QDEC_OVF_STS_R(reg)                   (((reg)>>1)&0x1u)             /**< Get PmlWakeQDecOvfSts from register */
#define  PML_WAKE_QDEC_DBL_STS_RSHIFT                       2                             /**< Shift for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS_RMASK                        0x04u                         /**< Mask for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS_RBMASK                       0x1u                          /**< Base mask for PmlWakeQDecDblSts */
#define  PML_WAKE_QDEC_DBL_STS_R(x)                         (((x)&0x1u)<<2)               /**< Set PmlWakeQDecDblSts in register */
#define  GET_PML_WAKE_QDEC_DBL_STS_R(reg)                   (((reg)>>2)&0x1u)             /**< Get PmlWakeQDecDblSts from register */
/** @} */


/**
 * @name RegPmlDcdcT2
 * @{
 */
// RegPmlDcdcT2.r32
#define  REG_PML_DCDC_T2_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPmlDcdcT2 */
#define  REG_PML_DCDC_T2_MASK                               0x0000001Fu                   /**< Mask for RegPmlDcdcT2 */

#define  PML_DCDC_T2_ACT_SHIFT                              0                             /**< Shift for PmlDcdcT2Act */
#define  PML_DCDC_T2_ACT_MASK                               0x0000001Fu                   /**< Mask for PmlDcdcT2Act */
#define  PML_DCDC_T2_ACT_BMASK                              0x1Fu                         /**< Base mask for PmlDcdcT2Act */
#define  PML_DCDC_T2_ACT(x)                                 (((x)&0x1Fu)<<0)              /**< Set PmlDcdcT2Act in register */
#define  GET_PML_DCDC_T2_ACT(reg)                           (((reg)>>0)&0x1Fu)            /**< Get PmlDcdcT2Act from register */
/** @} */


/**
 * @name RegPwrMetCtrl
 * @{
 */
// RegPwrMetCtrl.r32
#define  REG_PWR_MET_CTRL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegPwrMetCtrl */
#define  REG_PWR_MET_CTRL_MASK                              0x00010FFFu                   /**< Mask for RegPwrMetCtrl */

#define  PWR_MET_PER_SHIFT                                  0                             /**< Shift for PwrMetPer */
#define  PWR_MET_PER_MASK                                   0x00000FFFu                   /**< Mask for PwrMetPer */
#define  PWR_MET_PER_BMASK                                  0xFFFu                        /**< Base mask for PwrMetPer */
#define  PWR_MET_PER(x)                                     (((x)&0xFFFu)<<0)             /**< Set PwrMetPer in register */
#define  GET_PWR_MET_PER(reg)                               (((reg)>>0)&0xFFFu)           /**< Get PwrMetPer from register */
#define  PWR_MET_START_SHIFT                                16                            /**< Shift for PwrMetStart */
#define  PWR_MET_START_MASK                                 0x00010000u                   /**< Mask for PwrMetStart */
#define  PWR_MET_START_BMASK                                0x1u                          /**< Base mask for PwrMetStart */
#define  PWR_MET_START(x)                                   (((x)&0x1u)<<16)              /**< Set PwrMetStart in register */
#define  GET_PWR_MET_START(reg)                             (((reg)>>16)&0x1u)            /**< Get PwrMetStart from register */

// RegPwrMetCtrl.regs.PwrMetPer
#define  PWR_MET_PER_GSHIFT                                 0                             /**< Shift for group PwrMetPer */
#define  PWR_MET_PER_GSIZE                                  16                            /**< Size of group PwrMetPer */
#define  PWR_MET_PER_GMASK                                  0x0000FFFFu                   /**< Mask for group PwrMetPer */

#define  PWR_MET_PER_RSHIFT                                 0                             /**< Shift for PwrMetPer */
#define  PWR_MET_PER_RMASK                                  0x00000FFFu                   /**< Mask for PwrMetPer */
#define  PWR_MET_PER_RBMASK                                 0xFFFu                        /**< Base mask for PwrMetPer */
#define  PWR_MET_PER_R(x)                                   (((x)&0xFFFu)<<0)             /**< Set PwrMetPer in register */
#define  GET_PWR_MET_PER_R(reg)                             (((reg)>>0)&0xFFFu)           /**< Get PwrMetPer from register */
#define  PWR_MET_START_RSHIFT                               16                            /**< Shift for PwrMetStart */
#define  PWR_MET_START_RMASK                                0x00010000u                   /**< Mask for PwrMetStart */
#define  PWR_MET_START_RBMASK                               0x1u                          /**< Base mask for PwrMetStart */
#define  PWR_MET_START_R(x)                                 (((x)&0x1u)<<16)              /**< Set PwrMetStart in register */
#define  GET_PWR_MET_START_R(reg)                           (((reg)>>16)&0x1u)            /**< Get PwrMetStart from register */
/** @} */


/**
 * @name RegPwrMetVal
 * @{
 */
// RegPwrMetVal.r32
#define  REG_PWR_MET_VAL_RESET_VALUE                        0x00000000u                   /**< Reset value of RegPwrMetVal */
#define  REG_PWR_MET_VAL_MASK                               0x00010FFFu                   /**< Mask for RegPwrMetVal */

#define  PWR_MET_VAL_SHIFT                                  0                             /**< Shift for PwrMetVal */
#define  PWR_MET_VAL_MASK                                   0x00000FFFu                   /**< Mask for PwrMetVal */
#define  PWR_MET_VAL_BMASK                                  0xFFFu                        /**< Base mask for PwrMetVal */
#define  PWR_MET_VAL(x)                                     (((x)&0xFFFu)<<0)             /**< Set PwrMetVal in register */
#define  GET_PWR_MET_VAL(reg)                               (((reg)>>0)&0xFFFu)           /**< Get PwrMetVal from register */
#define  PWR_MET_STS_RUN_SHIFT                              16                            /**< Shift for PwrMetStsRun */
#define  PWR_MET_STS_RUN_MASK                               0x00010000u                   /**< Mask for PwrMetStsRun */
#define  PWR_MET_STS_RUN_BMASK                              0x1u                          /**< Base mask for PwrMetStsRun */
#define  PWR_MET_STS_RUN(x)                                 (((x)&0x1u)<<16)              /**< Set PwrMetStsRun in register */
#define  GET_PWR_MET_STS_RUN(reg)                           (((reg)>>16)&0x1u)            /**< Get PwrMetStsRun from register */

// RegPwrMetVal.regs.PwrMetVal
#define  PWR_MET_VAL_GSHIFT                                 0                             /**< Shift for group PwrMetVal */
#define  PWR_MET_VAL_GSIZE                                  16                            /**< Size of group PwrMetVal */
#define  PWR_MET_VAL_GMASK                                  0x0000FFFFu                   /**< Mask for group PwrMetVal */

#define  PWR_MET_VAL_RSHIFT                                 0                             /**< Shift for PwrMetVal */
#define  PWR_MET_VAL_RMASK                                  0x00000FFFu                   /**< Mask for PwrMetVal */
#define  PWR_MET_VAL_RBMASK                                 0xFFFu                        /**< Base mask for PwrMetVal */
#define  PWR_MET_VAL_R(x)                                   (((x)&0xFFFu)<<0)             /**< Set PwrMetVal in register */
#define  GET_PWR_MET_VAL_R(reg)                             (((reg)>>0)&0xFFFu)           /**< Get PwrMetVal from register */

// RegPwrMetVal.regs.PwrMetStsRun
#define  PWR_MET_STS_RUN_GSHIFT                             16                            /**< Shift for group PwrMetStsRun */
#define  PWR_MET_STS_RUN_GSIZE                              16                            /**< Size of group PwrMetStsRun */
#define  PWR_MET_STS_RUN_GMASK                              0xFFFF0000u                   /**< Mask for group PwrMetStsRun */

#define  PWR_MET_STS_RUN_RSHIFT                             0                             /**< Shift for PwrMetStsRun */
#define  PWR_MET_STS_RUN_RMASK                              0x00000001u                   /**< Mask for PwrMetStsRun */
#define  PWR_MET_STS_RUN_RBMASK                             0x1u                          /**< Base mask for PwrMetStsRun */
#define  PWR_MET_STS_RUN_R(x)                               (((x)&0x1u)<<0)               /**< Set PwrMetStsRun in register */
#define  GET_PWR_MET_STS_RUN_R(reg)                         (((reg)>>0)&0x1u)             /**< Get PwrMetStsRun from register */
/** @} */



/** @} End of group System_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_SYSTEM_H */
