////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_adc.h
///
/// @project    T9305
///
/// @brief      ADC register and bit field definitions
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

#ifndef _T9305_ADC_H
#define _T9305_ADC_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup ADC_Registers ADC Register Map - registers
 * @{
 ******************************************************************************/


/** ADC control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegAdcCtrl_t;


/** ADC config */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegAdcCfg_t;


/** ADC status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegAdcSts_t;


/** ADC conversion result */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegAdcData_t;


/** ADC test mode control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegAdcTstCtrl_t;

/** @} end of group ADC_Regs */



/***************************************************************************//**
 * @defgroup ADC_RegMap ADC Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegAdcCtrl_t                                      RegAdcCtrl;                   /**< ADC control */
    __IO  RegAdcCfg_t                                       RegAdcCfg;                    /**< ADC config */
    __I   RegAdcSts_t                                       RegAdcSts;                    /**< ADC status */
    __I   RegAdcData_t                                      RegAdcData;                   /**< ADC conversion result */
    __IO  RegAdcTstCtrl_t                                   RegAdcTstCtrl;                /**< ADC test mode control */
} ADC_RegMap_t;

/** @} end of group ADC_RegMap */



/***************************************************************************//**
 * @defgroup ADC_BitFields ADC bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegAdcCtrl
 * @{
 */
// RegAdcCtrl.r32
#define  REG_ADC_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegAdcCtrl */
#define  REG_ADC_CTRL_MASK                                  0x0001000Fu                   /**< Mask for RegAdcCtrl */

#define  ADC_START_SINGLE_SHIFT                             0                             /**< Shift for AdcStartSingle */
#define  ADC_START_SINGLE_MASK                              0x00000001u                   /**< Mask for AdcStartSingle */
#define  ADC_START_SINGLE_BMASK                             0x1u                          /**< Base mask for AdcStartSingle */
#define  ADC_START_SINGLE(x)                                (((x)&0x1u)<<0)               /**< Set AdcStartSingle in register */
#define  GET_ADC_START_SINGLE(reg)                          (((reg)>>0)&0x1u)             /**< Get AdcStartSingle from register */
#define  ADC_START_CONT_SHIFT                               1                             /**< Shift for AdcStartCont */
#define  ADC_START_CONT_MASK                                0x00000002u                   /**< Mask for AdcStartCont */
#define  ADC_START_CONT_BMASK                               0x1u                          /**< Base mask for AdcStartCont */
#define  ADC_START_CONT(x)                                  (((x)&0x1u)<<1)               /**< Set AdcStartCont in register */
#define  GET_ADC_START_CONT(reg)                            (((reg)>>1)&0x1u)             /**< Get AdcStartCont from register */
#define  ADC_STOP_SHIFT                                     2                             /**< Shift for AdcStop */
#define  ADC_STOP_MASK                                      0x00000004u                   /**< Mask for AdcStop */
#define  ADC_STOP_BMASK                                     0x1u                          /**< Base mask for AdcStop */
#define  ADC_STOP(x)                                        (((x)&0x1u)<<2)               /**< Set AdcStop in register */
#define  GET_ADC_STOP(reg)                                  (((reg)>>2)&0x1u)             /**< Get AdcStop from register */
#define  ADC_CLEAR_DATA_VALID_SHIFT                         3                             /**< Shift for AdcClearDataValid */
#define  ADC_CLEAR_DATA_VALID_MASK                          0x00000008u                   /**< Mask for AdcClearDataValid */
#define  ADC_CLEAR_DATA_VALID_BMASK                         0x1u                          /**< Base mask for AdcClearDataValid */
#define  ADC_CLEAR_DATA_VALID(x)                            (((x)&0x1u)<<3)               /**< Set AdcClearDataValid in register */
#define  GET_ADC_CLEAR_DATA_VALID(reg)                      (((reg)>>3)&0x1u)             /**< Get AdcClearDataValid from register */
#define  ADC_EN_SHIFT                                       16                            /**< Shift for AdcEn */
#define  ADC_EN_MASK                                        0x00010000u                   /**< Mask for AdcEn */
#define  ADC_EN_BMASK                                       0x1u                          /**< Base mask for AdcEn */
#define  ADC_EN(x)                                          (((x)&0x1u)<<16)              /**< Set AdcEn in register */
#define  GET_ADC_EN(reg)                                    (((reg)>>16)&0x1u)            /**< Get AdcEn from register */
/** @} */


/**
 * @name RegAdcCfg
 * @{
 */
// RegAdcCfg.r32
#define  REG_ADC_CFG_RESET_VALUE                            0x00000100u                   /**< Reset value of RegAdcCfg */
#define  REG_ADC_CFG_MASK                                   0x00071F1Bu                   /**< Mask for RegAdcCfg */

#define  ADC_SOURCE_SHIFT                                   0                             /**< Shift for AdcSource */
#define  ADC_SOURCE_MASK                                    0x00000003u                   /**< Mask for AdcSource */
#define  ADC_SOURCE_BMASK                                   0x3u                          /**< Base mask for AdcSource */
#define  ADC_SOURCE(x)                                      (((x)&0x3u)<<0)               /**< Set AdcSource in register */
#define  GET_ADC_SOURCE(reg)                                (((reg)>>0)&0x3u)             /**< Get AdcSource from register */
#define  ADC_RANGE_SHIFT                                    3                             /**< Shift for AdcRange */
#define  ADC_RANGE_MASK                                     0x00000018u                   /**< Mask for AdcRange */
#define  ADC_RANGE_BMASK                                    0x3u                          /**< Base mask for AdcRange */
#define  ADC_RANGE(x)                                       (((x)&0x3u)<<3)               /**< Set AdcRange in register */
#define  GET_ADC_RANGE(reg)                                 (((reg)>>3)&0x3u)             /**< Get AdcRange from register */
#define  ADC_SH_DUR_SHIFT                                   8                             /**< Shift for AdcShDur */
#define  ADC_SH_DUR_MASK                                    0x00000300u                   /**< Mask for AdcShDur */
#define  ADC_SH_DUR_BMASK                                   0x3u                          /**< Base mask for AdcShDur */
#define  ADC_SH_DUR(x)                                      (((x)&0x3u)<<8)               /**< Set AdcShDur in register */
#define  GET_ADC_SH_DUR(reg)                                (((reg)>>8)&0x3u)             /**< Get AdcShDur from register */
#define  ADC_SH_EN_SHIFT                                    10                            /**< Shift for AdcShEn */
#define  ADC_SH_EN_MASK                                     0x00000400u                   /**< Mask for AdcShEn */
#define  ADC_SH_EN_BMASK                                    0x1u                          /**< Base mask for AdcShEn */
#define  ADC_SH_EN(x)                                       (((x)&0x1u)<<10)              /**< Set AdcShEn in register */
#define  GET_ADC_SH_EN(reg)                                 (((reg)>>10)&0x1u)            /**< Get AdcShEn from register */
#define  ADC_SEL_VHI_SHIFT                                  11                            /**< Shift for AdcSelVhi */
#define  ADC_SEL_VHI_MASK                                   0x00000800u                   /**< Mask for AdcSelVhi */
#define  ADC_SEL_VHI_BMASK                                  0x1u                          /**< Base mask for AdcSelVhi */
#define  ADC_SEL_VHI(x)                                     (((x)&0x1u)<<11)              /**< Set AdcSelVhi in register */
#define  GET_ADC_SEL_VHI(reg)                               (((reg)>>11)&0x1u)            /**< Get AdcSelVhi from register */
#define  ADC_RESOLUTION_SHIFT                               12                            /**< Shift for AdcResolution */
#define  ADC_RESOLUTION_MASK                                0x00001000u                   /**< Mask for AdcResolution */
#define  ADC_RESOLUTION_BMASK                               0x1u                          /**< Base mask for AdcResolution */
#define  ADC_RESOLUTION(x)                                  (((x)&0x1u)<<12)              /**< Set AdcResolution in register */
#define  GET_ADC_RESOLUTION(reg)                            (((reg)>>12)&0x1u)            /**< Get AdcResolution from register */
#define  ADC_CLK_CFG_SHIFT                                  16                            /**< Shift for AdcClkCfg */
#define  ADC_CLK_CFG_MASK                                   0x00070000u                   /**< Mask for AdcClkCfg */
#define  ADC_CLK_CFG_BMASK                                  0x7u                          /**< Base mask for AdcClkCfg */
#define  ADC_CLK_CFG(x)                                     (((x)&0x7u)<<16)              /**< Set AdcClkCfg in register */
#define  GET_ADC_CLK_CFG(reg)                               (((reg)>>16)&0x7u)            /**< Get AdcClkCfg from register */
/** @} */


/**
 * @name RegAdcSts
 * @{
 */
// RegAdcSts.r32
#define  REG_ADC_STS_RESET_VALUE                            0x00000000u                   /**< Reset value of RegAdcSts */
#define  REG_ADC_STS_MASK                                   0x0000001Fu                   /**< Mask for RegAdcSts */

#define  ADC_STS_SINGLE_SHIFT                               0                             /**< Shift for AdcStsSingle */
#define  ADC_STS_SINGLE_MASK                                0x00000001u                   /**< Mask for AdcStsSingle */
#define  ADC_STS_SINGLE_BMASK                               0x1u                          /**< Base mask for AdcStsSingle */
#define  ADC_STS_SINGLE(x)                                  (((x)&0x1u)<<0)               /**< Set AdcStsSingle in register */
#define  GET_ADC_STS_SINGLE(reg)                            (((reg)>>0)&0x1u)             /**< Get AdcStsSingle from register */
#define  ADC_STS_CONT_SHIFT                                 1                             /**< Shift for AdcStsCont */
#define  ADC_STS_CONT_MASK                                  0x00000002u                   /**< Mask for AdcStsCont */
#define  ADC_STS_CONT_BMASK                                 0x1u                          /**< Base mask for AdcStsCont */
#define  ADC_STS_CONT(x)                                    (((x)&0x1u)<<1)               /**< Set AdcStsCont in register */
#define  GET_ADC_STS_CONT(reg)                              (((reg)>>1)&0x1u)             /**< Get AdcStsCont from register */
#define  ADC_STS_VALID_SHIFT                                2                             /**< Shift for AdcStsValid */
#define  ADC_STS_VALID_MASK                                 0x00000004u                   /**< Mask for AdcStsValid */
#define  ADC_STS_VALID_BMASK                                0x1u                          /**< Base mask for AdcStsValid */
#define  ADC_STS_VALID(x)                                   (((x)&0x1u)<<2)               /**< Set AdcStsValid in register */
#define  GET_ADC_STS_VALID(reg)                             (((reg)>>2)&0x1u)             /**< Get AdcStsValid from register */
#define  ADC_STS_OVERRUN_SHIFT                              3                             /**< Shift for AdcStsOverrun */
#define  ADC_STS_OVERRUN_MASK                               0x00000008u                   /**< Mask for AdcStsOverrun */
#define  ADC_STS_OVERRUN_BMASK                              0x1u                          /**< Base mask for AdcStsOverrun */
#define  ADC_STS_OVERRUN(x)                                 (((x)&0x1u)<<3)               /**< Set AdcStsOverrun in register */
#define  GET_ADC_STS_OVERRUN(reg)                           (((reg)>>3)&0x1u)             /**< Get AdcStsOverrun from register */
#define  ADC_STS_COMP_OUT_SHIFT                             4                             /**< Shift for AdcStsCompOut */
#define  ADC_STS_COMP_OUT_MASK                              0x00000010u                   /**< Mask for AdcStsCompOut */
#define  ADC_STS_COMP_OUT_BMASK                             0x1u                          /**< Base mask for AdcStsCompOut */
#define  ADC_STS_COMP_OUT(x)                                (((x)&0x1u)<<4)               /**< Set AdcStsCompOut in register */
#define  GET_ADC_STS_COMP_OUT(reg)                          (((reg)>>4)&0x1u)             /**< Get AdcStsCompOut from register */
/** @} */


/**
 * @name RegAdcData
 * @{
 */
// RegAdcData.r32
#define  REG_ADC_DATA_RESET_VALUE                           0x00000000u                   /**< Reset value of RegAdcData */
#define  REG_ADC_DATA_MASK                                  0x000001FFu                   /**< Mask for RegAdcData */

#define  ADC_DATA_SHIFT                                     0                             /**< Shift for AdcData */
#define  ADC_DATA_MASK                                      0x000001FFu                   /**< Mask for AdcData */
#define  ADC_DATA_BMASK                                     0x1FFu                        /**< Base mask for AdcData */
#define  ADC_DATA(x)                                        (((x)&0x1FFu)<<0)             /**< Set AdcData in register */
#define  GET_ADC_DATA(reg)                                  (((reg)>>0)&0x1FFu)           /**< Get AdcData from register */
/** @} */


/**
 * @name RegAdcTstCtrl
 * @{
 */
// RegAdcTstCtrl.r32
#define  REG_ADC_TST_CTRL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegAdcTstCtrl */
#define  REG_ADC_TST_CTRL_MASK                              0xC10101FFu                   /**< Mask for RegAdcTstCtrl */

#define  ADC_TST_PHI_SHIFT                                  0                             /**< Shift for AdcTstPhi */
#define  ADC_TST_PHI_MASK                                   0x000001FFu                   /**< Mask for AdcTstPhi */
#define  ADC_TST_PHI_BMASK                                  0x1FFu                        /**< Base mask for AdcTstPhi */
#define  ADC_TST_PHI(x)                                     (((x)&0x1FFu)<<0)             /**< Set AdcTstPhi in register */
#define  GET_ADC_TST_PHI(reg)                               (((reg)>>0)&0x1FFu)           /**< Get AdcTstPhi from register */
#define  ADC_TST_SH_SHIFT                                   16                            /**< Shift for AdcTstSh */
#define  ADC_TST_SH_MASK                                    0x00010000u                   /**< Mask for AdcTstSh */
#define  ADC_TST_SH_BMASK                                   0x1u                          /**< Base mask for AdcTstSh */
#define  ADC_TST_SH(x)                                      (((x)&0x1u)<<16)              /**< Set AdcTstSh in register */
#define  GET_ADC_TST_SH(reg)                                (((reg)>>16)&0x1u)            /**< Get AdcTstSh from register */
#define  ADC_TST_CK_GEN_SHIFT                               24                            /**< Shift for AdcTstCkGen */
#define  ADC_TST_CK_GEN_MASK                                0x01000000u                   /**< Mask for AdcTstCkGen */
#define  ADC_TST_CK_GEN_BMASK                               0x1u                          /**< Base mask for AdcTstCkGen */
#define  ADC_TST_CK_GEN(x)                                  (((x)&0x1u)<<24)              /**< Set AdcTstCkGen in register */
#define  GET_ADC_TST_CK_GEN(reg)                            (((reg)>>24)&0x1u)            /**< Get AdcTstCkGen from register */
#define  ADC_TST_CK_SEL_SHIFT                               30                            /**< Shift for AdcTstCkSel */
#define  ADC_TST_CK_SEL_MASK                                0x40000000u                   /**< Mask for AdcTstCkSel */
#define  ADC_TST_CK_SEL_BMASK                               0x1u                          /**< Base mask for AdcTstCkSel */
#define  ADC_TST_CK_SEL(x)                                  (((x)&0x1u)<<30)              /**< Set AdcTstCkSel in register */
#define  GET_ADC_TST_CK_SEL(reg)                            (((reg)>>30)&0x1u)            /**< Get AdcTstCkSel from register */
#define  ADC_TST_SEL_SHIFT                                  31                            /**< Shift for AdcTstSel */
#define  ADC_TST_SEL_MASK                                   0x80000000u                   /**< Mask for AdcTstSel */
#define  ADC_TST_SEL_BMASK                                  0x1u                          /**< Base mask for AdcTstSel */
#define  ADC_TST_SEL(x)                                     (((x)&0x1u)<<31)              /**< Set AdcTstSel in register */
#define  GET_ADC_TST_SEL(reg)                               (((reg)>>31)&0x1u)            /**< Get AdcTstSel from register */
/** @} */



/** @} End of group ADC_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*T9305_ADC_H */
