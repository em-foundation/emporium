////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_gpio.h
///
/// @project    T9305
///
/// @brief      GPIO register and bit field definitions
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

#ifndef _T9305_GPIO_H
#define _T9305_GPIO_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup GPIO_Registers GPIO Register Map - registers
 * @{
 ******************************************************************************/


/** GPIO input enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOInputEn_t;


/** GPIO output enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOOutputEn_t;


/** GPIO pull up enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOPuEn_t;


/** GPIO pull down enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOPdEn_t;


/** GPIO Open Drain enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOOdEn_t;


/** GPIO output switch matrix selection 0: P0-P3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOOutSel0;                               /**< Output switch matrix selection - P0 */
        uint8_t  GPIOOutSel1;                               /**< Output switch matrix selection - P1 */
        uint8_t  GPIOOutSel2;                               /**< Output switch matrix selection - P2 */
        uint8_t  GPIOOutSel3;                               /**< Output switch matrix selection - P3 */
    } regs;
} RegGPIOOutSel0_t;


/** GPIO output switch matrix selection 1: P4-P7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOOutSel4;                               /**< Output switch matrix selection - P4 */
        uint8_t  GPIOOutSel5;                               /**< Output switch matrix selection  - P5 */
        uint8_t  GPIOOutSel6;                               /**< Output switch matrix selection - P6 */
        uint8_t  GPIOOutSel7;                               /**< Output switch matrix selection - P7 */
    } regs;
} RegGPIOOutSel1_t;


/** GPIO output switch matrix selection 2: P8-P11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOOutSel8;                               /**< Output switch matrix selection - P8 - reset value JTAG assigned */
        uint8_t  GPIOOutSel9;                               /**< Output switch matrix selection - P9  - reset value JTAG assigned */
        uint8_t  GPIOOutSel10;                              /**< Output switch matrix selection - P10  - reset value JTAG assigned */
        uint8_t  GPIOOutSel11;                              /**< Output switch matrix selection - P11 -  - reset value JTAG assigned */
    } regs;
} RegGPIOOutSel2_t;


/** GPIO input switch matrix selection 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOInSelSSCSN;                            /**< SPI slave CSN selector */
        uint8_t  GPIOInSelSSSCK;                            /**< SPI slave SCK selector */
        uint8_t  GPIOInSelSSMOSI;                           /**< SPI slave MOSI selector */
        uint8_t  GPIOInSelSMMISO;                           /**< SPI master MISO selector */
    } regs;
} RegGPIOInpSel0_t;


/** GPIO input switch matrix selection 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOInSelUARTRDX;                          /**< UART RDX selector */
        uint8_t  GPIOInSelUARTCTS;                          /**< UART RTS selector */
        uint8_t  GPIOInSelTim2Start;                        /**< Timer 2 start/stop */
        uint8_t  GPIOInSelTim2Cap;                          /**< Timer 2 capture */
    } regs;
} RegGPIOInpSel1_t;


/** GPIO input switch matrix selection 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOInSelTim3Start;                        /**< Timer 3 start/stop */
        uint8_t  GPIOInSelTim3Cap;                          /**< Timer 0 capture */
        uint8_t  GPIOInSelTim2Clk;                          /**< Timer 2 external clock */
        uint8_t  GPIOInSelTim3Clk;                          /**< Timer 3 external clock */
    } regs;
} RegGPIOInpSel2_t;


/** GPIO input switch matrix selection 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  GPIOInSelI2sSClk;                          /**< I2S serial clock */
        uint8_t  GPIOInSelI2sFsync;                         /**< I2S frame sync */
        uint8_t  GPIOInSelI2sSData;                         /**< I2S serial data */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegGPIOInpSel3_t;


/** GPIO data output to pins */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIODataOut_t;


/** GPIO data output to pins - set to '1' */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIODataOutSet_t;


/** GPIO data output to pins - clear to '0' */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIODataOutClr_t;


/** GPIO data input from pins */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIODataIn_t;


/** GPIO IRQ polarity */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegGPIOIRQPolarity_t;


/** GPIO configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t GPIOHighDrive;                             /**< High drive configuration for GPIO - GPIO 1-3 */
        uint16_t GPIOUsbCfg;                                /**< USB GPIO configuration, for testing only */
    } regs;
} RegGPIOCfg_t;

/** @} end of group GPIO_Regs */



/***************************************************************************//**
 * @defgroup GPIO_RegMap GPIO Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegGPIOInputEn_t                                  RegGPIOInputEn;               /**< GPIO input enable */
    __IO  RegGPIOOutputEn_t                                 RegGPIOOutputEn;              /**< GPIO output enable */
    __IO  RegGPIOPuEn_t                                     RegGPIOPuEn;                  /**< GPIO pull up enable */
    __IO  RegGPIOPdEn_t                                     RegGPIOPdEn;                  /**< GPIO pull down enable */
    __IO  RegGPIOOdEn_t                                     RegGPIOOdEn;                  /**< GPIO Open Drain enable */
    __IO  RegGPIOOutSel0_t                                  RegGPIOOutSel0;               /**< GPIO output switch matrix selection 0: P0-P3 */
    __IO  RegGPIOOutSel1_t                                  RegGPIOOutSel1;               /**< GPIO output switch matrix selection 1: P4-P7 */
    __IO  RegGPIOOutSel2_t                                  RegGPIOOutSel2;               /**< GPIO output switch matrix selection 2: P8-P11 */
    __IO  RegGPIOInpSel0_t                                  RegGPIOInpSel0;               /**< GPIO input switch matrix selection 0 */
    __IO  RegGPIOInpSel1_t                                  RegGPIOInpSel1;               /**< GPIO input switch matrix selection 1 */
    __IO  RegGPIOInpSel2_t                                  RegGPIOInpSel2;               /**< GPIO input switch matrix selection 2 */
    __IO  RegGPIOInpSel3_t                                  RegGPIOInpSel3;               /**< GPIO input switch matrix selection 3 */
    __IO  RegGPIODataOut_t                                  RegGPIODataOut;               /**< GPIO data output to pins */
    __O   RegGPIODataOutSet_t                               RegGPIODataOutSet;            /**< GPIO data output to pins - set to '1' */
    __O   RegGPIODataOutClr_t                               RegGPIODataOutClr;            /**< GPIO data output to pins - clear to '0' */
    __I   RegGPIODataIn_t                                   RegGPIODataIn;                /**< GPIO data input from pins */
    __IO  RegGPIOIRQPolarity_t                              RegGPIOIRQPolarity;           /**< GPIO IRQ polarity */
    __IO  RegGPIOCfg_t                                      RegGPIOCfg;                   /**< GPIO configuration */
} GPIO_RegMap_t;

/** @} end of group GPIO_RegMap */



/***************************************************************************//**
 * @defgroup GPIO_BitFields GPIO bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegGPIOInputEn
 * @{
 */
// RegGPIOInputEn.r32
#define  REG_GPIO_INPUT_EN_RESET_VALUE                      0x00000000u                   /**< Reset value of RegGPIOInputEn */
#define  REG_GPIO_INPUT_EN_MASK                             0x00000FFFu                   /**< Mask for RegGPIOInputEn */

#define  GPIO_INPUT_EN_SHIFT                                0                             /**< Shift for GPIOInputEn */
#define  GPIO_INPUT_EN_MASK                                 0x00000FFFu                   /**< Mask for GPIOInputEn */
#define  GPIO_INPUT_EN_BMASK                                0xFFFu                        /**< Base mask for GPIOInputEn */
#define  GPIO_INPUT_EN(x)                                   (((x)&0xFFFu)<<0)             /**< Set GPIOInputEn in register */
#define  GET_GPIO_INPUT_EN(reg)                             (((reg)>>0)&0xFFFu)           /**< Get GPIOInputEn from register */
/** @} */


/**
 * @name RegGPIOOutputEn
 * @{
 */
// RegGPIOOutputEn.r32
#define  REG_GPIO_OUTPUT_EN_RESET_VALUE                     0x00000000u                   /**< Reset value of RegGPIOOutputEn */
#define  REG_GPIO_OUTPUT_EN_MASK                            0x00000FFFu                   /**< Mask for RegGPIOOutputEn */

#define  GPIO_OUTPUT_EN_SHIFT                               0                             /**< Shift for GPIOOutputEn */
#define  GPIO_OUTPUT_EN_MASK                                0x00000FFFu                   /**< Mask for GPIOOutputEn */
#define  GPIO_OUTPUT_EN_BMASK                               0xFFFu                        /**< Base mask for GPIOOutputEn */
#define  GPIO_OUTPUT_EN(x)                                  (((x)&0xFFFu)<<0)             /**< Set GPIOOutputEn in register */
#define  GET_GPIO_OUTPUT_EN(reg)                            (((reg)>>0)&0xFFFu)           /**< Get GPIOOutputEn from register */
/** @} */


/**
 * @name RegGPIOPuEn
 * @{
 */
// RegGPIOPuEn.r32
#define  REG_GPIO_PU_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegGPIOPuEn */
#define  REG_GPIO_PU_EN_MASK                                0x00000FFFu                   /**< Mask for RegGPIOPuEn */

#define  GPIO_PU_EN_SHIFT                                   0                             /**< Shift for GPIOPuEn */
#define  GPIO_PU_EN_MASK                                    0x00000FFFu                   /**< Mask for GPIOPuEn */
#define  GPIO_PU_EN_BMASK                                   0xFFFu                        /**< Base mask for GPIOPuEn */
#define  GPIO_PU_EN(x)                                      (((x)&0xFFFu)<<0)             /**< Set GPIOPuEn in register */
#define  GET_GPIO_PU_EN(reg)                                (((reg)>>0)&0xFFFu)           /**< Get GPIOPuEn from register */
/** @} */


/**
 * @name RegGPIOPdEn
 * @{
 */
// RegGPIOPdEn.r32
#define  REG_GPIO_PD_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegGPIOPdEn */
#define  REG_GPIO_PD_EN_MASK                                0x00000FFFu                   /**< Mask for RegGPIOPdEn */

#define  GPIO_PD_EN_SHIFT                                   0                             /**< Shift for GPIOPdEn */
#define  GPIO_PD_EN_MASK                                    0x00000FFFu                   /**< Mask for GPIOPdEn */
#define  GPIO_PD_EN_BMASK                                   0xFFFu                        /**< Base mask for GPIOPdEn */
#define  GPIO_PD_EN(x)                                      (((x)&0xFFFu)<<0)             /**< Set GPIOPdEn in register */
#define  GET_GPIO_PD_EN(reg)                                (((reg)>>0)&0xFFFu)           /**< Get GPIOPdEn from register */
/** @} */


/**
 * @name RegGPIOOdEn
 * @{
 */
// RegGPIOOdEn.r32
#define  REG_GPIO_OD_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegGPIOOdEn */
#define  REG_GPIO_OD_EN_MASK                                0x00000F33u                   /**< Mask for RegGPIOOdEn */

#define  GPIO_OD_EN0_SHIFT                                  0                             /**< Shift for GPIOOdEn0 */
#define  GPIO_OD_EN0_MASK                                   0x00000001u                   /**< Mask for GPIOOdEn0 */
#define  GPIO_OD_EN0_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn0 */
#define  GPIO_OD_EN0(x)                                     (((x)&0x1u)<<0)               /**< Set GPIOOdEn0 in register */
#define  GET_GPIO_OD_EN0(reg)                               (((reg)>>0)&0x1u)             /**< Get GPIOOdEn0 from register */
#define  GPIO_OD_EN1_SHIFT                                  1                             /**< Shift for GPIOOdEn1 */
#define  GPIO_OD_EN1_MASK                                   0x00000002u                   /**< Mask for GPIOOdEn1 */
#define  GPIO_OD_EN1_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn1 */
#define  GPIO_OD_EN1(x)                                     (((x)&0x1u)<<1)               /**< Set GPIOOdEn1 in register */
#define  GET_GPIO_OD_EN1(reg)                               (((reg)>>1)&0x1u)             /**< Get GPIOOdEn1 from register */
#define  GPIO_OD_EN4_SHIFT                                  4                             /**< Shift for GPIOOdEn4 */
#define  GPIO_OD_EN4_MASK                                   0x00000010u                   /**< Mask for GPIOOdEn4 */
#define  GPIO_OD_EN4_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn4 */
#define  GPIO_OD_EN4(x)                                     (((x)&0x1u)<<4)               /**< Set GPIOOdEn4 in register */
#define  GET_GPIO_OD_EN4(reg)                               (((reg)>>4)&0x1u)             /**< Get GPIOOdEn4 from register */
#define  GPIO_OD_EN5_SHIFT                                  5                             /**< Shift for GPIOOdEn5 */
#define  GPIO_OD_EN5_MASK                                   0x00000020u                   /**< Mask for GPIOOdEn5 */
#define  GPIO_OD_EN5_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn5 */
#define  GPIO_OD_EN5(x)                                     (((x)&0x1u)<<5)               /**< Set GPIOOdEn5 in register */
#define  GET_GPIO_OD_EN5(reg)                               (((reg)>>5)&0x1u)             /**< Get GPIOOdEn5 from register */
#define  GPIO_OD_EN8_SHIFT                                  8                             /**< Shift for GPIOOdEn8 */
#define  GPIO_OD_EN8_MASK                                   0x00000100u                   /**< Mask for GPIOOdEn8 */
#define  GPIO_OD_EN8_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn8 */
#define  GPIO_OD_EN8(x)                                     (((x)&0x1u)<<8)               /**< Set GPIOOdEn8 in register */
#define  GET_GPIO_OD_EN8(reg)                               (((reg)>>8)&0x1u)             /**< Get GPIOOdEn8 from register */
#define  GPIO_OD_EN9_SHIFT                                  9                             /**< Shift for GPIOOdEn9 */
#define  GPIO_OD_EN9_MASK                                   0x00000200u                   /**< Mask for GPIOOdEn9 */
#define  GPIO_OD_EN9_BMASK                                  0x1u                          /**< Base mask for GPIOOdEn9 */
#define  GPIO_OD_EN9(x)                                     (((x)&0x1u)<<9)               /**< Set GPIOOdEn9 in register */
#define  GET_GPIO_OD_EN9(reg)                               (((reg)>>9)&0x1u)             /**< Get GPIOOdEn9 from register */
#define  GPIO_OD_EN10_SHIFT                                 10                            /**< Shift for GPIOOdEn10 */
#define  GPIO_OD_EN10_MASK                                  0x00000400u                   /**< Mask for GPIOOdEn10 */
#define  GPIO_OD_EN10_BMASK                                 0x1u                          /**< Base mask for GPIOOdEn10 */
#define  GPIO_OD_EN10(x)                                    (((x)&0x1u)<<10)              /**< Set GPIOOdEn10 in register */
#define  GET_GPIO_OD_EN10(reg)                              (((reg)>>10)&0x1u)            /**< Get GPIOOdEn10 from register */
#define  GPIO_OD_EN11_SHIFT                                 11                            /**< Shift for GPIOOdEn11 */
#define  GPIO_OD_EN11_MASK                                  0x00000800u                   /**< Mask for GPIOOdEn11 */
#define  GPIO_OD_EN11_BMASK                                 0x1u                          /**< Base mask for GPIOOdEn11 */
#define  GPIO_OD_EN11(x)                                    (((x)&0x1u)<<11)              /**< Set GPIOOdEn11 in register */
#define  GET_GPIO_OD_EN11(reg)                              (((reg)>>11)&0x1u)            /**< Get GPIOOdEn11 from register */
/** @} */


/**
 * @name RegGPIOOutSel0
 * @{
 */
// RegGPIOOutSel0.r32
#define  REG_GPIO_OUT_SEL0_RESET_VALUE                      0x00000000u                   /**< Reset value of RegGPIOOutSel0 */
#define  REG_GPIO_OUT_SEL0_MASK                             0x1F1F1F1Fu                   /**< Mask for RegGPIOOutSel0 */

#define  GPIO_OUT_SEL0_SHIFT                                0                             /**< Shift for GPIOOutSel0 */
#define  GPIO_OUT_SEL0_MASK                                 0x0000001Fu                   /**< Mask for GPIOOutSel0 */
#define  GPIO_OUT_SEL0_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel0 */
#define  GPIO_OUT_SEL0(x)                                   (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel0 in register */
#define  GET_GPIO_OUT_SEL0(reg)                             (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel0 from register */
#define  GPIO_OUT_SEL1_SHIFT                                8                             /**< Shift for GPIOOutSel1 */
#define  GPIO_OUT_SEL1_MASK                                 0x00001F00u                   /**< Mask for GPIOOutSel1 */
#define  GPIO_OUT_SEL1_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel1 */
#define  GPIO_OUT_SEL1(x)                                   (((x)&0x1Fu)<<8)              /**< Set GPIOOutSel1 in register */
#define  GET_GPIO_OUT_SEL1(reg)                             (((reg)>>8)&0x1Fu)            /**< Get GPIOOutSel1 from register */
#define  GPIO_OUT_SEL2_SHIFT                                16                            /**< Shift for GPIOOutSel2 */
#define  GPIO_OUT_SEL2_MASK                                 0x001F0000u                   /**< Mask for GPIOOutSel2 */
#define  GPIO_OUT_SEL2_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel2 */
#define  GPIO_OUT_SEL2(x)                                   (((x)&0x1Fu)<<16)             /**< Set GPIOOutSel2 in register */
#define  GET_GPIO_OUT_SEL2(reg)                             (((reg)>>16)&0x1Fu)           /**< Get GPIOOutSel2 from register */
#define  GPIO_OUT_SEL3_SHIFT                                24                            /**< Shift for GPIOOutSel3 */
#define  GPIO_OUT_SEL3_MASK                                 0x1F000000u                   /**< Mask for GPIOOutSel3 */
#define  GPIO_OUT_SEL3_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel3 */
#define  GPIO_OUT_SEL3(x)                                   (((x)&0x1Fu)<<24)             /**< Set GPIOOutSel3 in register */
#define  GET_GPIO_OUT_SEL3(reg)                             (((reg)>>24)&0x1Fu)           /**< Get GPIOOutSel3 from register */

// RegGPIOOutSel0.regs.GPIOOutSel0
#define  GPIO_OUT_SEL0_GSHIFT                               0                             /**< Shift for group GPIOOutSel0 */
#define  GPIO_OUT_SEL0_GSIZE                                8                             /**< Size of group GPIOOutSel0 */
#define  GPIO_OUT_SEL0_GMASK                                0x000000FFu                   /**< Mask for group GPIOOutSel0 */

#define  GPIO_OUT_SEL0_RSHIFT                               0                             /**< Shift for GPIOOutSel0 */
#define  GPIO_OUT_SEL0_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel0 */
#define  GPIO_OUT_SEL0_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel0 */
#define  GPIO_OUT_SEL0_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel0 in register */
#define  GET_GPIO_OUT_SEL0_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel0 from register */

// RegGPIOOutSel0.regs.GPIOOutSel1
#define  GPIO_OUT_SEL1_GSHIFT                               8                             /**< Shift for group GPIOOutSel1 */
#define  GPIO_OUT_SEL1_GSIZE                                8                             /**< Size of group GPIOOutSel1 */
#define  GPIO_OUT_SEL1_GMASK                                0x0000FF00u                   /**< Mask for group GPIOOutSel1 */

#define  GPIO_OUT_SEL1_RSHIFT                               0                             /**< Shift for GPIOOutSel1 */
#define  GPIO_OUT_SEL1_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel1 */
#define  GPIO_OUT_SEL1_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel1 */
#define  GPIO_OUT_SEL1_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel1 in register */
#define  GET_GPIO_OUT_SEL1_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel1 from register */

// RegGPIOOutSel0.regs.GPIOOutSel2
#define  GPIO_OUT_SEL2_GSHIFT                               16                            /**< Shift for group GPIOOutSel2 */
#define  GPIO_OUT_SEL2_GSIZE                                8                             /**< Size of group GPIOOutSel2 */
#define  GPIO_OUT_SEL2_GMASK                                0x00FF0000u                   /**< Mask for group GPIOOutSel2 */

#define  GPIO_OUT_SEL2_RSHIFT                               0                             /**< Shift for GPIOOutSel2 */
#define  GPIO_OUT_SEL2_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel2 */
#define  GPIO_OUT_SEL2_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel2 */
#define  GPIO_OUT_SEL2_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel2 in register */
#define  GET_GPIO_OUT_SEL2_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel2 from register */

// RegGPIOOutSel0.regs.GPIOOutSel3
#define  GPIO_OUT_SEL3_GSHIFT                               24                            /**< Shift for group GPIOOutSel3 */
#define  GPIO_OUT_SEL3_GSIZE                                8                             /**< Size of group GPIOOutSel3 */
#define  GPIO_OUT_SEL3_GMASK                                0xFF000000u                   /**< Mask for group GPIOOutSel3 */

#define  GPIO_OUT_SEL3_RSHIFT                               0                             /**< Shift for GPIOOutSel3 */
#define  GPIO_OUT_SEL3_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel3 */
#define  GPIO_OUT_SEL3_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel3 */
#define  GPIO_OUT_SEL3_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel3 in register */
#define  GET_GPIO_OUT_SEL3_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel3 from register */
/** @} */


/**
 * @name RegGPIOOutSel1
 * @{
 */
// RegGPIOOutSel1.r32
#define  REG_GPIO_OUT_SEL1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegGPIOOutSel1 */
#define  REG_GPIO_OUT_SEL1_MASK                             0x1F1F1F1Fu                   /**< Mask for RegGPIOOutSel1 */

#define  GPIO_OUT_SEL4_SHIFT                                0                             /**< Shift for GPIOOutSel4 */
#define  GPIO_OUT_SEL4_MASK                                 0x0000001Fu                   /**< Mask for GPIOOutSel4 */
#define  GPIO_OUT_SEL4_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel4 */
#define  GPIO_OUT_SEL4(x)                                   (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel4 in register */
#define  GET_GPIO_OUT_SEL4(reg)                             (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel4 from register */
#define  GPIO_OUT_SEL5_SHIFT                                8                             /**< Shift for GPIOOutSel5 */
#define  GPIO_OUT_SEL5_MASK                                 0x00001F00u                   /**< Mask for GPIOOutSel5 */
#define  GPIO_OUT_SEL5_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel5 */
#define  GPIO_OUT_SEL5(x)                                   (((x)&0x1Fu)<<8)              /**< Set GPIOOutSel5 in register */
#define  GET_GPIO_OUT_SEL5(reg)                             (((reg)>>8)&0x1Fu)            /**< Get GPIOOutSel5 from register */
#define  GPIO_OUT_SEL6_SHIFT                                16                            /**< Shift for GPIOOutSel6 */
#define  GPIO_OUT_SEL6_MASK                                 0x001F0000u                   /**< Mask for GPIOOutSel6 */
#define  GPIO_OUT_SEL6_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel6 */
#define  GPIO_OUT_SEL6(x)                                   (((x)&0x1Fu)<<16)             /**< Set GPIOOutSel6 in register */
#define  GET_GPIO_OUT_SEL6(reg)                             (((reg)>>16)&0x1Fu)           /**< Get GPIOOutSel6 from register */
#define  GPIO_OUT_SEL7_SHIFT                                24                            /**< Shift for GPIOOutSel7 */
#define  GPIO_OUT_SEL7_MASK                                 0x1F000000u                   /**< Mask for GPIOOutSel7 */
#define  GPIO_OUT_SEL7_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel7 */
#define  GPIO_OUT_SEL7(x)                                   (((x)&0x1Fu)<<24)             /**< Set GPIOOutSel7 in register */
#define  GET_GPIO_OUT_SEL7(reg)                             (((reg)>>24)&0x1Fu)           /**< Get GPIOOutSel7 from register */

// RegGPIOOutSel1.regs.GPIOOutSel4
#define  GPIO_OUT_SEL4_GSHIFT                               0                             /**< Shift for group GPIOOutSel4 */
#define  GPIO_OUT_SEL4_GSIZE                                8                             /**< Size of group GPIOOutSel4 */
#define  GPIO_OUT_SEL4_GMASK                                0x000000FFu                   /**< Mask for group GPIOOutSel4 */

#define  GPIO_OUT_SEL4_RSHIFT                               0                             /**< Shift for GPIOOutSel4 */
#define  GPIO_OUT_SEL4_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel4 */
#define  GPIO_OUT_SEL4_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel4 */
#define  GPIO_OUT_SEL4_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel4 in register */
#define  GET_GPIO_OUT_SEL4_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel4 from register */

// RegGPIOOutSel1.regs.GPIOOutSel5
#define  GPIO_OUT_SEL5_GSHIFT                               8                             /**< Shift for group GPIOOutSel5 */
#define  GPIO_OUT_SEL5_GSIZE                                8                             /**< Size of group GPIOOutSel5 */
#define  GPIO_OUT_SEL5_GMASK                                0x0000FF00u                   /**< Mask for group GPIOOutSel5 */

#define  GPIO_OUT_SEL5_RSHIFT                               0                             /**< Shift for GPIOOutSel5 */
#define  GPIO_OUT_SEL5_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel5 */
#define  GPIO_OUT_SEL5_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel5 */
#define  GPIO_OUT_SEL5_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel5 in register */
#define  GET_GPIO_OUT_SEL5_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel5 from register */

// RegGPIOOutSel1.regs.GPIOOutSel6
#define  GPIO_OUT_SEL6_GSHIFT                               16                            /**< Shift for group GPIOOutSel6 */
#define  GPIO_OUT_SEL6_GSIZE                                8                             /**< Size of group GPIOOutSel6 */
#define  GPIO_OUT_SEL6_GMASK                                0x00FF0000u                   /**< Mask for group GPIOOutSel6 */

#define  GPIO_OUT_SEL6_RSHIFT                               0                             /**< Shift for GPIOOutSel6 */
#define  GPIO_OUT_SEL6_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel6 */
#define  GPIO_OUT_SEL6_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel6 */
#define  GPIO_OUT_SEL6_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel6 in register */
#define  GET_GPIO_OUT_SEL6_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel6 from register */

// RegGPIOOutSel1.regs.GPIOOutSel7
#define  GPIO_OUT_SEL7_GSHIFT                               24                            /**< Shift for group GPIOOutSel7 */
#define  GPIO_OUT_SEL7_GSIZE                                8                             /**< Size of group GPIOOutSel7 */
#define  GPIO_OUT_SEL7_GMASK                                0xFF000000u                   /**< Mask for group GPIOOutSel7 */

#define  GPIO_OUT_SEL7_RSHIFT                               0                             /**< Shift for GPIOOutSel7 */
#define  GPIO_OUT_SEL7_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel7 */
#define  GPIO_OUT_SEL7_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel7 */
#define  GPIO_OUT_SEL7_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel7 in register */
#define  GET_GPIO_OUT_SEL7_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel7 from register */
/** @} */


/**
 * @name RegGPIOOutSel2
 * @{
 */
// RegGPIOOutSel2.r32
#define  REG_GPIO_OUT_SEL2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegGPIOOutSel2 */
#define  REG_GPIO_OUT_SEL2_MASK                             0x1F1F1F1Fu                   /**< Mask for RegGPIOOutSel2 */

#define  GPIO_OUT_SEL8_SHIFT                                0                             /**< Shift for GPIOOutSel8 */
#define  GPIO_OUT_SEL8_MASK                                 0x0000001Fu                   /**< Mask for GPIOOutSel8 */
#define  GPIO_OUT_SEL8_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel8 */
#define  GPIO_OUT_SEL8(x)                                   (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel8 in register */
#define  GET_GPIO_OUT_SEL8(reg)                             (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel8 from register */
#define  GPIO_OUT_SEL9_SHIFT                                8                             /**< Shift for GPIOOutSel9 */
#define  GPIO_OUT_SEL9_MASK                                 0x00001F00u                   /**< Mask for GPIOOutSel9 */
#define  GPIO_OUT_SEL9_BMASK                                0x1Fu                         /**< Base mask for GPIOOutSel9 */
#define  GPIO_OUT_SEL9(x)                                   (((x)&0x1Fu)<<8)              /**< Set GPIOOutSel9 in register */
#define  GET_GPIO_OUT_SEL9(reg)                             (((reg)>>8)&0x1Fu)            /**< Get GPIOOutSel9 from register */
#define  GPIO_OUT_SEL10_SHIFT                               16                            /**< Shift for GPIOOutSel10 */
#define  GPIO_OUT_SEL10_MASK                                0x001F0000u                   /**< Mask for GPIOOutSel10 */
#define  GPIO_OUT_SEL10_BMASK                               0x1Fu                         /**< Base mask for GPIOOutSel10 */
#define  GPIO_OUT_SEL10(x)                                  (((x)&0x1Fu)<<16)             /**< Set GPIOOutSel10 in register */
#define  GET_GPIO_OUT_SEL10(reg)                            (((reg)>>16)&0x1Fu)           /**< Get GPIOOutSel10 from register */
#define  GPIO_OUT_SEL11_SHIFT                               24                            /**< Shift for GPIOOutSel11 */
#define  GPIO_OUT_SEL11_MASK                                0x1F000000u                   /**< Mask for GPIOOutSel11 */
#define  GPIO_OUT_SEL11_BMASK                               0x1Fu                         /**< Base mask for GPIOOutSel11 */
#define  GPIO_OUT_SEL11(x)                                  (((x)&0x1Fu)<<24)             /**< Set GPIOOutSel11 in register */
#define  GET_GPIO_OUT_SEL11(reg)                            (((reg)>>24)&0x1Fu)           /**< Get GPIOOutSel11 from register */

// RegGPIOOutSel2.regs.GPIOOutSel8
#define  GPIO_OUT_SEL8_GSHIFT                               0                             /**< Shift for group GPIOOutSel8 */
#define  GPIO_OUT_SEL8_GSIZE                                8                             /**< Size of group GPIOOutSel8 */
#define  GPIO_OUT_SEL8_GMASK                                0x000000FFu                   /**< Mask for group GPIOOutSel8 */

#define  GPIO_OUT_SEL8_RSHIFT                               0                             /**< Shift for GPIOOutSel8 */
#define  GPIO_OUT_SEL8_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel8 */
#define  GPIO_OUT_SEL8_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel8 */
#define  GPIO_OUT_SEL8_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel8 in register */
#define  GET_GPIO_OUT_SEL8_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel8 from register */

// RegGPIOOutSel2.regs.GPIOOutSel9
#define  GPIO_OUT_SEL9_GSHIFT                               8                             /**< Shift for group GPIOOutSel9 */
#define  GPIO_OUT_SEL9_GSIZE                                8                             /**< Size of group GPIOOutSel9 */
#define  GPIO_OUT_SEL9_GMASK                                0x0000FF00u                   /**< Mask for group GPIOOutSel9 */

#define  GPIO_OUT_SEL9_RSHIFT                               0                             /**< Shift for GPIOOutSel9 */
#define  GPIO_OUT_SEL9_RMASK                                0x0000001Fu                   /**< Mask for GPIOOutSel9 */
#define  GPIO_OUT_SEL9_RBMASK                               0x1Fu                         /**< Base mask for GPIOOutSel9 */
#define  GPIO_OUT_SEL9_R(x)                                 (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel9 in register */
#define  GET_GPIO_OUT_SEL9_R(reg)                           (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel9 from register */

// RegGPIOOutSel2.regs.GPIOOutSel10
#define  GPIO_OUT_SEL10_GSHIFT                              16                            /**< Shift for group GPIOOutSel10 */
#define  GPIO_OUT_SEL10_GSIZE                               8                             /**< Size of group GPIOOutSel10 */
#define  GPIO_OUT_SEL10_GMASK                               0x00FF0000u                   /**< Mask for group GPIOOutSel10 */

#define  GPIO_OUT_SEL10_RSHIFT                              0                             /**< Shift for GPIOOutSel10 */
#define  GPIO_OUT_SEL10_RMASK                               0x0000001Fu                   /**< Mask for GPIOOutSel10 */
#define  GPIO_OUT_SEL10_RBMASK                              0x1Fu                         /**< Base mask for GPIOOutSel10 */
#define  GPIO_OUT_SEL10_R(x)                                (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel10 in register */
#define  GET_GPIO_OUT_SEL10_R(reg)                          (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel10 from register */

// RegGPIOOutSel2.regs.GPIOOutSel11
#define  GPIO_OUT_SEL11_GSHIFT                              24                            /**< Shift for group GPIOOutSel11 */
#define  GPIO_OUT_SEL11_GSIZE                               8                             /**< Size of group GPIOOutSel11 */
#define  GPIO_OUT_SEL11_GMASK                               0xFF000000u                   /**< Mask for group GPIOOutSel11 */

#define  GPIO_OUT_SEL11_RSHIFT                              0                             /**< Shift for GPIOOutSel11 */
#define  GPIO_OUT_SEL11_RMASK                               0x0000001Fu                   /**< Mask for GPIOOutSel11 */
#define  GPIO_OUT_SEL11_RBMASK                              0x1Fu                         /**< Base mask for GPIOOutSel11 */
#define  GPIO_OUT_SEL11_R(x)                                (((x)&0x1Fu)<<0)              /**< Set GPIOOutSel11 in register */
#define  GET_GPIO_OUT_SEL11_R(reg)                          (((reg)>>0)&0x1Fu)            /**< Get GPIOOutSel11 from register */
/** @} */


/**
 * @name RegGPIOInpSel0
 * @{
 */
// RegGPIOInpSel0.r32
#define  REG_GPIO_INP_SEL0_RESET_VALUE                      0x0F0F0F0Fu                   /**< Reset value of RegGPIOInpSel0 */
#define  REG_GPIO_INP_SEL0_MASK                             0x0F0F0F0Fu                   /**< Mask for RegGPIOInpSel0 */

#define  GPIO_IN_SEL_SS_CSN_SHIFT                           0                             /**< Shift for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_MASK                            0x0000000Fu                   /**< Mask for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_BMASK                           0xFu                          /**< Base mask for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN(x)                              (((x)&0xFu)<<0)               /**< Set GPIOInSelSSCSN in register */
#define  GET_GPIO_IN_SEL_SS_CSN(reg)                        (((reg)>>0)&0xFu)             /**< Get GPIOInSelSSCSN from register */
#define  GPIO_IN_SEL_SS_SCK_SHIFT                           8                             /**< Shift for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_MASK                            0x00000F00u                   /**< Mask for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_BMASK                           0xFu                          /**< Base mask for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK(x)                              (((x)&0xFu)<<8)               /**< Set GPIOInSelSSSCK in register */
#define  GET_GPIO_IN_SEL_SS_SCK(reg)                        (((reg)>>8)&0xFu)             /**< Get GPIOInSelSSSCK from register */
#define  GPIO_IN_SEL_SS_MOSI_SHIFT                          16                            /**< Shift for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_MASK                           0x000F0000u                   /**< Mask for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_BMASK                          0xFu                          /**< Base mask for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI(x)                             (((x)&0xFu)<<16)              /**< Set GPIOInSelSSMOSI in register */
#define  GET_GPIO_IN_SEL_SS_MOSI(reg)                       (((reg)>>16)&0xFu)            /**< Get GPIOInSelSSMOSI from register */
#define  GPIO_IN_SEL_SM_MISO_SHIFT                          24                            /**< Shift for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_MASK                           0x0F000000u                   /**< Mask for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_BMASK                          0xFu                          /**< Base mask for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO(x)                             (((x)&0xFu)<<24)              /**< Set GPIOInSelSMMISO in register */
#define  GET_GPIO_IN_SEL_SM_MISO(reg)                       (((reg)>>24)&0xFu)            /**< Get GPIOInSelSMMISO from register */

// RegGPIOInpSel0.regs.GPIOInSelSSCSN
#define  GPIO_IN_SEL_SS_CSN_GSHIFT                          0                             /**< Shift for group GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_GSIZE                           8                             /**< Size of group GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_GMASK                           0x000000FFu                   /**< Mask for group GPIOInSelSSCSN */

#define  GPIO_IN_SEL_SS_CSN_RSHIFT                          0                             /**< Shift for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_RMASK                           0x0000000Fu                   /**< Mask for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_RBMASK                          0xFu                          /**< Base mask for GPIOInSelSSCSN */
#define  GPIO_IN_SEL_SS_CSN_R(x)                            (((x)&0xFu)<<0)               /**< Set GPIOInSelSSCSN in register */
#define  GET_GPIO_IN_SEL_SS_CSN_R(reg)                      (((reg)>>0)&0xFu)             /**< Get GPIOInSelSSCSN from register */

// RegGPIOInpSel0.regs.GPIOInSelSSSCK
#define  GPIO_IN_SEL_SS_SCK_GSHIFT                          8                             /**< Shift for group GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_GSIZE                           8                             /**< Size of group GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_GMASK                           0x0000FF00u                   /**< Mask for group GPIOInSelSSSCK */

#define  GPIO_IN_SEL_SS_SCK_RSHIFT                          0                             /**< Shift for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_RMASK                           0x0000000Fu                   /**< Mask for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_RBMASK                          0xFu                          /**< Base mask for GPIOInSelSSSCK */
#define  GPIO_IN_SEL_SS_SCK_R(x)                            (((x)&0xFu)<<0)               /**< Set GPIOInSelSSSCK in register */
#define  GET_GPIO_IN_SEL_SS_SCK_R(reg)                      (((reg)>>0)&0xFu)             /**< Get GPIOInSelSSSCK from register */

// RegGPIOInpSel0.regs.GPIOInSelSSMOSI
#define  GPIO_IN_SEL_SS_MOSI_GSHIFT                         16                            /**< Shift for group GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_GSIZE                          8                             /**< Size of group GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_GMASK                          0x00FF0000u                   /**< Mask for group GPIOInSelSSMOSI */

#define  GPIO_IN_SEL_SS_MOSI_RSHIFT                         0                             /**< Shift for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_RMASK                          0x0000000Fu                   /**< Mask for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_RBMASK                         0xFu                          /**< Base mask for GPIOInSelSSMOSI */
#define  GPIO_IN_SEL_SS_MOSI_R(x)                           (((x)&0xFu)<<0)               /**< Set GPIOInSelSSMOSI in register */
#define  GET_GPIO_IN_SEL_SS_MOSI_R(reg)                     (((reg)>>0)&0xFu)             /**< Get GPIOInSelSSMOSI from register */

// RegGPIOInpSel0.regs.GPIOInSelSMMISO
#define  GPIO_IN_SEL_SM_MISO_GSHIFT                         24                            /**< Shift for group GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_GSIZE                          8                             /**< Size of group GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_GMASK                          0xFF000000u                   /**< Mask for group GPIOInSelSMMISO */

#define  GPIO_IN_SEL_SM_MISO_RSHIFT                         0                             /**< Shift for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_RMASK                          0x0000000Fu                   /**< Mask for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_RBMASK                         0xFu                          /**< Base mask for GPIOInSelSMMISO */
#define  GPIO_IN_SEL_SM_MISO_R(x)                           (((x)&0xFu)<<0)               /**< Set GPIOInSelSMMISO in register */
#define  GET_GPIO_IN_SEL_SM_MISO_R(reg)                     (((reg)>>0)&0xFu)             /**< Get GPIOInSelSMMISO from register */
/** @} */


/**
 * @name RegGPIOInpSel1
 * @{
 */
// RegGPIOInpSel1.r32
#define  REG_GPIO_INP_SEL1_RESET_VALUE                      0x0F0F0F0Fu                   /**< Reset value of RegGPIOInpSel1 */
#define  REG_GPIO_INP_SEL1_MASK                             0x0F0F0F0Fu                   /**< Mask for RegGPIOInpSel1 */

#define  GPIO_IN_SEL_UART_RDX_SHIFT                         0                             /**< Shift for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_MASK                          0x0000000Fu                   /**< Mask for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_BMASK                         0xFu                          /**< Base mask for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX(x)                            (((x)&0xFu)<<0)               /**< Set GPIOInSelUARTRDX in register */
#define  GET_GPIO_IN_SEL_UART_RDX(reg)                      (((reg)>>0)&0xFu)             /**< Get GPIOInSelUARTRDX from register */
#define  GPIO_IN_SEL_UART_CTS_SHIFT                         8                             /**< Shift for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_MASK                          0x00000F00u                   /**< Mask for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_BMASK                         0xFu                          /**< Base mask for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS(x)                            (((x)&0xFu)<<8)               /**< Set GPIOInSelUARTCTS in register */
#define  GET_GPIO_IN_SEL_UART_CTS(reg)                      (((reg)>>8)&0xFu)             /**< Get GPIOInSelUARTCTS from register */
#define  GPIO_IN_SEL_TIM2_START_SHIFT                       16                            /**< Shift for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_MASK                        0x000F0000u                   /**< Mask for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_BMASK                       0xFu                          /**< Base mask for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START(x)                          (((x)&0xFu)<<16)              /**< Set GPIOInSelTim2Start in register */
#define  GET_GPIO_IN_SEL_TIM2_START(reg)                    (((reg)>>16)&0xFu)            /**< Get GPIOInSelTim2Start from register */
#define  GPIO_IN_SEL_TIM2_CAP_SHIFT                         24                            /**< Shift for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_MASK                          0x0F000000u                   /**< Mask for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_BMASK                         0xFu                          /**< Base mask for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP(x)                            (((x)&0xFu)<<24)              /**< Set GPIOInSelTim2Cap in register */
#define  GET_GPIO_IN_SEL_TIM2_CAP(reg)                      (((reg)>>24)&0xFu)            /**< Get GPIOInSelTim2Cap from register */

// RegGPIOInpSel1.regs.GPIOInSelUARTRDX
#define  GPIO_IN_SEL_UART_RDX_GSHIFT                        0                             /**< Shift for group GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_GSIZE                         8                             /**< Size of group GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_GMASK                         0x000000FFu                   /**< Mask for group GPIOInSelUARTRDX */

#define  GPIO_IN_SEL_UART_RDX_RSHIFT                        0                             /**< Shift for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_RBMASK                        0xFu                          /**< Base mask for GPIOInSelUARTRDX */
#define  GPIO_IN_SEL_UART_RDX_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelUARTRDX in register */
#define  GET_GPIO_IN_SEL_UART_RDX_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelUARTRDX from register */

// RegGPIOInpSel1.regs.GPIOInSelUARTCTS
#define  GPIO_IN_SEL_UART_CTS_GSHIFT                        8                             /**< Shift for group GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_GSIZE                         8                             /**< Size of group GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_GMASK                         0x0000FF00u                   /**< Mask for group GPIOInSelUARTCTS */

#define  GPIO_IN_SEL_UART_CTS_RSHIFT                        0                             /**< Shift for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_RBMASK                        0xFu                          /**< Base mask for GPIOInSelUARTCTS */
#define  GPIO_IN_SEL_UART_CTS_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelUARTCTS in register */
#define  GET_GPIO_IN_SEL_UART_CTS_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelUARTCTS from register */

// RegGPIOInpSel1.regs.GPIOInSelTim2Start
#define  GPIO_IN_SEL_TIM2_START_GSHIFT                      16                            /**< Shift for group GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_GSIZE                       8                             /**< Size of group GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_GMASK                       0x00FF0000u                   /**< Mask for group GPIOInSelTim2Start */

#define  GPIO_IN_SEL_TIM2_START_RSHIFT                      0                             /**< Shift for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_RMASK                       0x0000000Fu                   /**< Mask for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_RBMASK                      0xFu                          /**< Base mask for GPIOInSelTim2Start */
#define  GPIO_IN_SEL_TIM2_START_R(x)                        (((x)&0xFu)<<0)               /**< Set GPIOInSelTim2Start in register */
#define  GET_GPIO_IN_SEL_TIM2_START_R(reg)                  (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim2Start from register */

// RegGPIOInpSel1.regs.GPIOInSelTim2Cap
#define  GPIO_IN_SEL_TIM2_CAP_GSHIFT                        24                            /**< Shift for group GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_GSIZE                         8                             /**< Size of group GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_GMASK                         0xFF000000u                   /**< Mask for group GPIOInSelTim2Cap */

#define  GPIO_IN_SEL_TIM2_CAP_RSHIFT                        0                             /**< Shift for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_RBMASK                        0xFu                          /**< Base mask for GPIOInSelTim2Cap */
#define  GPIO_IN_SEL_TIM2_CAP_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelTim2Cap in register */
#define  GET_GPIO_IN_SEL_TIM2_CAP_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim2Cap from register */
/** @} */


/**
 * @name RegGPIOInpSel2
 * @{
 */
// RegGPIOInpSel2.r32
#define  REG_GPIO_INP_SEL2_RESET_VALUE                      0x0F0F0F0Fu                   /**< Reset value of RegGPIOInpSel2 */
#define  REG_GPIO_INP_SEL2_MASK                             0x0F0F0F0Fu                   /**< Mask for RegGPIOInpSel2 */

#define  GPIO_IN_SEL_TIM3_START_SHIFT                       0                             /**< Shift for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_MASK                        0x0000000Fu                   /**< Mask for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_BMASK                       0xFu                          /**< Base mask for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelTim3Start in register */
#define  GET_GPIO_IN_SEL_TIM3_START(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim3Start from register */
#define  GPIO_IN_SEL_TIM3_CAP_SHIFT                         8                             /**< Shift for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_MASK                          0x00000F00u                   /**< Mask for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_BMASK                         0xFu                          /**< Base mask for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP(x)                            (((x)&0xFu)<<8)               /**< Set GPIOInSelTim3Cap in register */
#define  GET_GPIO_IN_SEL_TIM3_CAP(reg)                      (((reg)>>8)&0xFu)             /**< Get GPIOInSelTim3Cap from register */
#define  GPIO_IN_SEL_TIM2_CLK_SHIFT                         16                            /**< Shift for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_MASK                          0x000F0000u                   /**< Mask for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_BMASK                         0xFu                          /**< Base mask for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK(x)                            (((x)&0xFu)<<16)              /**< Set GPIOInSelTim2Clk in register */
#define  GET_GPIO_IN_SEL_TIM2_CLK(reg)                      (((reg)>>16)&0xFu)            /**< Get GPIOInSelTim2Clk from register */
#define  GPIO_IN_SEL_TIM3_CLK_SHIFT                         24                            /**< Shift for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_MASK                          0x0F000000u                   /**< Mask for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_BMASK                         0xFu                          /**< Base mask for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK(x)                            (((x)&0xFu)<<24)              /**< Set GPIOInSelTim3Clk in register */
#define  GET_GPIO_IN_SEL_TIM3_CLK(reg)                      (((reg)>>24)&0xFu)            /**< Get GPIOInSelTim3Clk from register */

// RegGPIOInpSel2.regs.GPIOInSelTim3Start
#define  GPIO_IN_SEL_TIM3_START_GSHIFT                      0                             /**< Shift for group GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_GSIZE                       8                             /**< Size of group GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_GMASK                       0x000000FFu                   /**< Mask for group GPIOInSelTim3Start */

#define  GPIO_IN_SEL_TIM3_START_RSHIFT                      0                             /**< Shift for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_RMASK                       0x0000000Fu                   /**< Mask for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_RBMASK                      0xFu                          /**< Base mask for GPIOInSelTim3Start */
#define  GPIO_IN_SEL_TIM3_START_R(x)                        (((x)&0xFu)<<0)               /**< Set GPIOInSelTim3Start in register */
#define  GET_GPIO_IN_SEL_TIM3_START_R(reg)                  (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim3Start from register */

// RegGPIOInpSel2.regs.GPIOInSelTim3Cap
#define  GPIO_IN_SEL_TIM3_CAP_GSHIFT                        8                             /**< Shift for group GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_GSIZE                         8                             /**< Size of group GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_GMASK                         0x0000FF00u                   /**< Mask for group GPIOInSelTim3Cap */

#define  GPIO_IN_SEL_TIM3_CAP_RSHIFT                        0                             /**< Shift for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_RBMASK                        0xFu                          /**< Base mask for GPIOInSelTim3Cap */
#define  GPIO_IN_SEL_TIM3_CAP_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelTim3Cap in register */
#define  GET_GPIO_IN_SEL_TIM3_CAP_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim3Cap from register */

// RegGPIOInpSel2.regs.GPIOInSelTim2Clk
#define  GPIO_IN_SEL_TIM2_CLK_GSHIFT                        16                            /**< Shift for group GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_GSIZE                         8                             /**< Size of group GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_GMASK                         0x00FF0000u                   /**< Mask for group GPIOInSelTim2Clk */

#define  GPIO_IN_SEL_TIM2_CLK_RSHIFT                        0                             /**< Shift for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_RBMASK                        0xFu                          /**< Base mask for GPIOInSelTim2Clk */
#define  GPIO_IN_SEL_TIM2_CLK_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelTim2Clk in register */
#define  GET_GPIO_IN_SEL_TIM2_CLK_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim2Clk from register */

// RegGPIOInpSel2.regs.GPIOInSelTim3Clk
#define  GPIO_IN_SEL_TIM3_CLK_GSHIFT                        24                            /**< Shift for group GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_GSIZE                         8                             /**< Size of group GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_GMASK                         0xFF000000u                   /**< Mask for group GPIOInSelTim3Clk */

#define  GPIO_IN_SEL_TIM3_CLK_RSHIFT                        0                             /**< Shift for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_RBMASK                        0xFu                          /**< Base mask for GPIOInSelTim3Clk */
#define  GPIO_IN_SEL_TIM3_CLK_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelTim3Clk in register */
#define  GET_GPIO_IN_SEL_TIM3_CLK_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelTim3Clk from register */
/** @} */


/**
 * @name RegGPIOInpSel3
 * @{
 */
// RegGPIOInpSel3.r32
#define  REG_GPIO_INP_SEL3_RESET_VALUE                      0x000F0F0Fu                   /**< Reset value of RegGPIOInpSel3 */
#define  REG_GPIO_INP_SEL3_MASK                             0x000F0F0Fu                   /**< Mask for RegGPIOInpSel3 */

#define  GPIO_IN_SEL_I2S_SCLK_SHIFT                         0                             /**< Shift for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_MASK                          0x0000000Fu                   /**< Mask for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_BMASK                         0xFu                          /**< Base mask for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK(x)                            (((x)&0xFu)<<0)               /**< Set GPIOInSelI2sSClk in register */
#define  GET_GPIO_IN_SEL_I2S_SCLK(reg)                      (((reg)>>0)&0xFu)             /**< Get GPIOInSelI2sSClk from register */
#define  GPIO_IN_SEL_I2S_FSYNC_SHIFT                        8                             /**< Shift for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_MASK                         0x00000F00u                   /**< Mask for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_BMASK                        0xFu                          /**< Base mask for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC(x)                           (((x)&0xFu)<<8)               /**< Set GPIOInSelI2sFsync in register */
#define  GET_GPIO_IN_SEL_I2S_FSYNC(reg)                     (((reg)>>8)&0xFu)             /**< Get GPIOInSelI2sFsync from register */
#define  GPIO_IN_SEL_I2S_SDATA_SHIFT                        16                            /**< Shift for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_MASK                         0x000F0000u                   /**< Mask for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_BMASK                        0xFu                          /**< Base mask for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA(x)                           (((x)&0xFu)<<16)              /**< Set GPIOInSelI2sSData in register */
#define  GET_GPIO_IN_SEL_I2S_SDATA(reg)                     (((reg)>>16)&0xFu)            /**< Get GPIOInSelI2sSData from register */

// RegGPIOInpSel3.regs.GPIOInSelI2sSClk
#define  GPIO_IN_SEL_I2S_SCLK_GSHIFT                        0                             /**< Shift for group GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_GSIZE                         8                             /**< Size of group GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_GMASK                         0x000000FFu                   /**< Mask for group GPIOInSelI2sSClk */

#define  GPIO_IN_SEL_I2S_SCLK_RSHIFT                        0                             /**< Shift for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_RMASK                         0x0000000Fu                   /**< Mask for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_RBMASK                        0xFu                          /**< Base mask for GPIOInSelI2sSClk */
#define  GPIO_IN_SEL_I2S_SCLK_R(x)                          (((x)&0xFu)<<0)               /**< Set GPIOInSelI2sSClk in register */
#define  GET_GPIO_IN_SEL_I2S_SCLK_R(reg)                    (((reg)>>0)&0xFu)             /**< Get GPIOInSelI2sSClk from register */

// RegGPIOInpSel3.regs.GPIOInSelI2sFsync
#define  GPIO_IN_SEL_I2S_FSYNC_GSHIFT                       8                             /**< Shift for group GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_GSIZE                        8                             /**< Size of group GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_GMASK                        0x0000FF00u                   /**< Mask for group GPIOInSelI2sFsync */

#define  GPIO_IN_SEL_I2S_FSYNC_RSHIFT                       0                             /**< Shift for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_RMASK                        0x0000000Fu                   /**< Mask for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_RBMASK                       0xFu                          /**< Base mask for GPIOInSelI2sFsync */
#define  GPIO_IN_SEL_I2S_FSYNC_R(x)                         (((x)&0xFu)<<0)               /**< Set GPIOInSelI2sFsync in register */
#define  GET_GPIO_IN_SEL_I2S_FSYNC_R(reg)                   (((reg)>>0)&0xFu)             /**< Get GPIOInSelI2sFsync from register */

// RegGPIOInpSel3.regs.GPIOInSelI2sSData
#define  GPIO_IN_SEL_I2S_SDATA_GSHIFT                       16                            /**< Shift for group GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_GSIZE                        8                             /**< Size of group GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_GMASK                        0x00FF0000u                   /**< Mask for group GPIOInSelI2sSData */

#define  GPIO_IN_SEL_I2S_SDATA_RSHIFT                       0                             /**< Shift for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_RMASK                        0x0000000Fu                   /**< Mask for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_RBMASK                       0xFu                          /**< Base mask for GPIOInSelI2sSData */
#define  GPIO_IN_SEL_I2S_SDATA_R(x)                         (((x)&0xFu)<<0)               /**< Set GPIOInSelI2sSData in register */
#define  GET_GPIO_IN_SEL_I2S_SDATA_R(reg)                   (((reg)>>0)&0xFu)             /**< Get GPIOInSelI2sSData from register */
/** @} */


/**
 * @name RegGPIODataOut
 * @{
 */
// RegGPIODataOut.r32
#define  REG_GPIO_DATA_OUT_RESET_VALUE                      0x00000000u                   /**< Reset value of RegGPIODataOut */
#define  REG_GPIO_DATA_OUT_MASK                             0x00000FFFu                   /**< Mask for RegGPIODataOut */

#define  GPIO_DATA_OUT_SHIFT                                0                             /**< Shift for GPIODataOut */
#define  GPIO_DATA_OUT_MASK                                 0x00000FFFu                   /**< Mask for GPIODataOut */
#define  GPIO_DATA_OUT_BMASK                                0xFFFu                        /**< Base mask for GPIODataOut */
#define  GPIO_DATA_OUT(x)                                   (((x)&0xFFFu)<<0)             /**< Set GPIODataOut in register */
#define  GET_GPIO_DATA_OUT(reg)                             (((reg)>>0)&0xFFFu)           /**< Get GPIODataOut from register */
/** @} */


/**
 * @name RegGPIODataOutSet
 * @{
 */
// RegGPIODataOutSet.r32
#define  REG_GPIO_DATA_OUT_SET_RESET_VALUE                  0x00000000u                   /**< Reset value of RegGPIODataOutSet */
#define  REG_GPIO_DATA_OUT_SET_MASK                         0x00000FFFu                   /**< Mask for RegGPIODataOutSet */

#define  GPIO_DATA_OUT_SET_SHIFT                            0                             /**< Shift for GPIODataOutSet */
#define  GPIO_DATA_OUT_SET_MASK                             0x00000FFFu                   /**< Mask for GPIODataOutSet */
#define  GPIO_DATA_OUT_SET_BMASK                            0xFFFu                        /**< Base mask for GPIODataOutSet */
#define  GPIO_DATA_OUT_SET(x)                               (((x)&0xFFFu)<<0)             /**< Set GPIODataOutSet in register */
#define  GET_GPIO_DATA_OUT_SET(reg)                         (((reg)>>0)&0xFFFu)           /**< Get GPIODataOutSet from register */
/** @} */


/**
 * @name RegGPIODataOutClr
 * @{
 */
// RegGPIODataOutClr.r32
#define  REG_GPIO_DATA_OUT_CLR_RESET_VALUE                  0x00000000u                   /**< Reset value of RegGPIODataOutClr */
#define  REG_GPIO_DATA_OUT_CLR_MASK                         0x00000FFFu                   /**< Mask for RegGPIODataOutClr */

#define  GPIO_DATA_OUT_CLR_SHIFT                            0                             /**< Shift for GPIODataOutClr */
#define  GPIO_DATA_OUT_CLR_MASK                             0x00000FFFu                   /**< Mask for GPIODataOutClr */
#define  GPIO_DATA_OUT_CLR_BMASK                            0xFFFu                        /**< Base mask for GPIODataOutClr */
#define  GPIO_DATA_OUT_CLR(x)                               (((x)&0xFFFu)<<0)             /**< Set GPIODataOutClr in register */
#define  GET_GPIO_DATA_OUT_CLR(reg)                         (((reg)>>0)&0xFFFu)           /**< Get GPIODataOutClr from register */
/** @} */


/**
 * @name RegGPIODataIn
 * @{
 */
// RegGPIODataIn.r32
#define  REG_GPIO_DATA_IN_RESET_VALUE                       0x00000000u                   /**< Reset value of RegGPIODataIn */
#define  REG_GPIO_DATA_IN_MASK                              0x00000FFFu                   /**< Mask for RegGPIODataIn */

#define  GPIO_DATA_IN_SHIFT                                 0                             /**< Shift for GPIODataIn */
#define  GPIO_DATA_IN_MASK                                  0x00000FFFu                   /**< Mask for GPIODataIn */
#define  GPIO_DATA_IN_BMASK                                 0xFFFu                        /**< Base mask for GPIODataIn */
#define  GPIO_DATA_IN(x)                                    (((x)&0xFFFu)<<0)             /**< Set GPIODataIn in register */
#define  GET_GPIO_DATA_IN(reg)                              (((reg)>>0)&0xFFFu)           /**< Get GPIODataIn from register */
/** @} */


/**
 * @name RegGPIOIRQPolarity
 * @{
 */
// RegGPIOIRQPolarity.r32
#define  REG_GPIO_IRQ_POLARITY_RESET_VALUE                  0x00000000u                   /**< Reset value of RegGPIOIRQPolarity */
#define  REG_GPIO_IRQ_POLARITY_MASK                         0x00000FFFu                   /**< Mask for RegGPIOIRQPolarity */

#define  GPIO_IRQ_POLARITY_SHIFT                            0                             /**< Shift for GPIOIRQPolarity */
#define  GPIO_IRQ_POLARITY_MASK                             0x00000FFFu                   /**< Mask for GPIOIRQPolarity */
#define  GPIO_IRQ_POLARITY_BMASK                            0xFFFu                        /**< Base mask for GPIOIRQPolarity */
#define  GPIO_IRQ_POLARITY(x)                               (((x)&0xFFFu)<<0)             /**< Set GPIOIRQPolarity in register */
#define  GET_GPIO_IRQ_POLARITY(reg)                         (((reg)>>0)&0xFFFu)           /**< Get GPIOIRQPolarity from register */
/** @} */


/**
 * @name RegGPIOCfg
 * @{
 */
// RegGPIOCfg.r32
#define  REG_GPIO_CFG_RESET_VALUE                           0x00180000u                   /**< Reset value of RegGPIOCfg */
#define  REG_GPIO_CFG_MASK                                  0x003F000Fu                   /**< Mask for RegGPIOCfg */

#define  GPIO_RESERVED_SHIFT                                0                             /**< Shift for GPIORESERVED */
#define  GPIO_RESERVED_MASK                                 0x00000001u                   /**< Mask for GPIORESERVED */
#define  GPIO_RESERVED_BMASK                                0x1u                          /**< Base mask for GPIORESERVED */
#define  GPIO_RESERVED(x)                                   (((x)&0x1u)<<0)               /**< Set GPIORESERVED in register */
#define  GET_GPIO_RESERVED(reg)                             (((reg)>>0)&0x1u)             /**< Get GPIORESERVED from register */
#define  GPIO_HIGH_DRIVE_SHIFT                              1                             /**< Shift for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_MASK                               0x0000000Eu                   /**< Mask for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_BMASK                              0x7u                          /**< Base mask for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE(x)                                 (((x)&0x7u)<<1)               /**< Set GPIOHighDrive in register */
#define  GET_GPIO_HIGH_DRIVE(reg)                           (((reg)>>1)&0x7u)             /**< Get GPIOHighDrive from register */
#define  GPIO_USB_MODE_SHIFT                                16                            /**< Shift for GPIOUsbMode */
#define  GPIO_USB_MODE_MASK                                 0x00010000u                   /**< Mask for GPIOUsbMode */
#define  GPIO_USB_MODE_BMASK                                0x1u                          /**< Base mask for GPIOUsbMode */
#define  GPIO_USB_MODE(x)                                   (((x)&0x1u)<<16)              /**< Set GPIOUsbMode in register */
#define  GET_GPIO_USB_MODE(reg)                             (((reg)>>16)&0x1u)            /**< Get GPIOUsbMode from register */
#define  GPIO_USB_SLEW_RATE_SHIFT                           17                            /**< Shift for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE_MASK                            0x00020000u                   /**< Mask for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE_BMASK                           0x1u                          /**< Base mask for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE(x)                              (((x)&0x1u)<<17)              /**< Set GPIOUsbSlewRate in register */
#define  GET_GPIO_USB_SLEW_RATE(reg)                        (((reg)>>17)&0x1u)            /**< Get GPIOUsbSlewRate from register */
#define  GPIO_USB_HIGH_DRIVE_SHIFT                          18                            /**< Shift for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE_MASK                           0x00040000u                   /**< Mask for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE_BMASK                          0x1u                          /**< Base mask for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE(x)                             (((x)&0x1u)<<18)              /**< Set GPIOUsbHighDrive in register */
#define  GET_GPIO_USB_HIGH_DRIVE(reg)                       (((reg)>>18)&0x1u)            /**< Get GPIOUsbHighDrive from register */
#define  GPIO_USB_RPU1_EN_N_SHIFT                           19                            /**< Shift for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N_MASK                            0x00080000u                   /**< Mask for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N_BMASK                           0x1u                          /**< Base mask for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N(x)                              (((x)&0x1u)<<19)              /**< Set GPIOUsbRpu1EnN in register */
#define  GET_GPIO_USB_RPU1_EN_N(reg)                        (((reg)>>19)&0x1u)            /**< Get GPIOUsbRpu1EnN from register */
#define  GPIO_USB_RPU2_EN_N_SHIFT                           20                            /**< Shift for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N_MASK                            0x00100000u                   /**< Mask for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N_BMASK                           0x1u                          /**< Base mask for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N(x)                              (((x)&0x1u)<<20)              /**< Set GPIOUsbRpu2EnN in register */
#define  GET_GPIO_USB_RPU2_EN_N(reg)                        (((reg)>>20)&0x1u)            /**< Get GPIOUsbRpu2EnN from register */
#define  GPIO_USB_SUSP_N_SHIFT                              21                            /**< Shift for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N_MASK                               0x00200000u                   /**< Mask for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N_BMASK                              0x1u                          /**< Base mask for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N(x)                                 (((x)&0x1u)<<21)              /**< Set GPIOUsbSuspN in register */
#define  GET_GPIO_USB_SUSP_N(reg)                           (((reg)>>21)&0x1u)            /**< Get GPIOUsbSuspN from register */

// RegGPIOCfg.regs.GPIOHighDrive
#define  GPIO_HIGH_DRIVE_GSHIFT                             0                             /**< Shift for group GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_GSIZE                              16                            /**< Size of group GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_GMASK                              0x0000FFFFu                   /**< Mask for group GPIOHighDrive */

#define  GPIO_RESERVED_RSHIFT                               0                             /**< Shift for GPIORESERVED */
#define  GPIO_RESERVED_RMASK                                0x0001u                       /**< Mask for GPIORESERVED */
#define  GPIO_RESERVED_RBMASK                               0x1u                          /**< Base mask for GPIORESERVED */
#define  GPIO_RESERVED_R(x)                                 (((x)&0x1u)<<0)               /**< Set GPIORESERVED in register */
#define  GET_GPIO_RESERVED_R(reg)                           (((reg)>>0)&0x1u)             /**< Get GPIORESERVED from register */
#define  GPIO_HIGH_DRIVE_RSHIFT                             1                             /**< Shift for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_RMASK                              0x000Eu                       /**< Mask for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_RBMASK                             0x7u                          /**< Base mask for GPIOHighDrive */
#define  GPIO_HIGH_DRIVE_R(x)                               (((x)&0x7u)<<1)               /**< Set GPIOHighDrive in register */
#define  GET_GPIO_HIGH_DRIVE_R(reg)                         (((reg)>>1)&0x7u)             /**< Get GPIOHighDrive from register */

// RegGPIOCfg.regs.GPIOUsbCfg
#define  GPIO_USB_CFG_GSHIFT                                16                            /**< Shift for group GPIOUsbCfg */
#define  GPIO_USB_CFG_GSIZE                                 16                            /**< Size of group GPIOUsbCfg */
#define  GPIO_USB_CFG_GMASK                                 0xFFFF0000u                   /**< Mask for group GPIOUsbCfg */

#define  GPIO_USB_MODE_RSHIFT                               0                             /**< Shift for GPIOUsbMode */
#define  GPIO_USB_MODE_RMASK                                0x0001u                       /**< Mask for GPIOUsbMode */
#define  GPIO_USB_MODE_RBMASK                               0x1u                          /**< Base mask for GPIOUsbMode */
#define  GPIO_USB_MODE_R(x)                                 (((x)&0x1u)<<0)               /**< Set GPIOUsbMode in register */
#define  GET_GPIO_USB_MODE_R(reg)                           (((reg)>>0)&0x1u)             /**< Get GPIOUsbMode from register */
#define  GPIO_USB_SLEW_RATE_RSHIFT                          1                             /**< Shift for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE_RMASK                           0x0002u                       /**< Mask for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE_RBMASK                          0x1u                          /**< Base mask for GPIOUsbSlewRate */
#define  GPIO_USB_SLEW_RATE_R(x)                            (((x)&0x1u)<<1)               /**< Set GPIOUsbSlewRate in register */
#define  GET_GPIO_USB_SLEW_RATE_R(reg)                      (((reg)>>1)&0x1u)             /**< Get GPIOUsbSlewRate from register */
#define  GPIO_USB_HIGH_DRIVE_RSHIFT                         2                             /**< Shift for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE_RMASK                          0x0004u                       /**< Mask for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE_RBMASK                         0x1u                          /**< Base mask for GPIOUsbHighDrive */
#define  GPIO_USB_HIGH_DRIVE_R(x)                           (((x)&0x1u)<<2)               /**< Set GPIOUsbHighDrive in register */
#define  GET_GPIO_USB_HIGH_DRIVE_R(reg)                     (((reg)>>2)&0x1u)             /**< Get GPIOUsbHighDrive from register */
#define  GPIO_USB_RPU1_EN_N_RSHIFT                          3                             /**< Shift for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N_RMASK                           0x0008u                       /**< Mask for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N_RBMASK                          0x1u                          /**< Base mask for GPIOUsbRpu1EnN */
#define  GPIO_USB_RPU1_EN_N_R(x)                            (((x)&0x1u)<<3)               /**< Set GPIOUsbRpu1EnN in register */
#define  GET_GPIO_USB_RPU1_EN_N_R(reg)                      (((reg)>>3)&0x1u)             /**< Get GPIOUsbRpu1EnN from register */
#define  GPIO_USB_RPU2_EN_N_RSHIFT                          4                             /**< Shift for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N_RMASK                           0x0010u                       /**< Mask for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N_RBMASK                          0x1u                          /**< Base mask for GPIOUsbRpu2EnN */
#define  GPIO_USB_RPU2_EN_N_R(x)                            (((x)&0x1u)<<4)               /**< Set GPIOUsbRpu2EnN in register */
#define  GET_GPIO_USB_RPU2_EN_N_R(reg)                      (((reg)>>4)&0x1u)             /**< Get GPIOUsbRpu2EnN from register */
#define  GPIO_USB_SUSP_N_RSHIFT                             5                             /**< Shift for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N_RMASK                              0x0020u                       /**< Mask for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N_RBMASK                             0x1u                          /**< Base mask for GPIOUsbSuspN */
#define  GPIO_USB_SUSP_N_R(x)                               (((x)&0x1u)<<5)               /**< Set GPIOUsbSuspN in register */
#define  GET_GPIO_USB_SUSP_N_R(reg)                         (((reg)>>5)&0x1u)             /**< Get GPIOUsbSuspN from register */
/** @} */



/** @} End of group GPIO_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*T9305_GPIO_H */
