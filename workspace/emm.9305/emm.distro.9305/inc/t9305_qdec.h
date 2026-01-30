////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_qdec.h
///
/// @project    T9305
///
/// @brief      QDEC register and bit field definitions
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

#ifndef _T9305_QDEC_H
#define _T9305_QDEC_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup QDec_Registers QDec Register Map - registers
 * @{
 ******************************************************************************/


/** QDEC enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecEn_t;


/** QDEC configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecCfg_t;


/** QDEC pin selection */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecPinSel_t;


/** Capture control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecCaptureCtrl_t;


/** Sample and report period configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecPeriodCfg_t;


/** Debounce and LED timing configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecTimeCfg_t;


/** Sample value */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecSample_t;


/** Accumulator */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecAcc_t;


/** Double movements accumulator */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecAccDbl_t;


/** Accumulator capture */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecAccCapture_t;


/** Double movements accumulator capture */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegQDecAccDblCapture_t;

/** @} end of group QDec_Regs */



/***************************************************************************//**
 * @defgroup QDec_RegMap QDec Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegQDecEn_t                                       RegQDecEn;                    /**< QDEC enable */
    __IO  RegQDecCfg_t                                      RegQDecCfg;                   /**< QDEC configuration */
    __IO  RegQDecPinSel_t                                   RegQDecPinSel;                /**< QDEC pin selection */
    __IO  RegQDecCaptureCtrl_t                              RegQDecCaptureCtrl;           /**< Capture control */
    __IO  RegQDecPeriodCfg_t                                RegQDecPeriodCfg;             /**< Sample and report period configuration */
    __IO  RegQDecTimeCfg_t                                  RegQDecTimeCfg;               /**< Debounce and LED timing configuration */
    __I   RegQDecSample_t                                   RegQDecSample;                /**< Sample value */
    __I   RegQDecAcc_t                                      RegQDecAcc;                   /**< Accumulator */
    __I   RegQDecAccDbl_t                                   RegQDecAccDbl;                /**< Double movements accumulator */
    __I   RegQDecAccCapture_t                               RegQDecAccCapture;            /**< Accumulator capture */
    __I   RegQDecAccDblCapture_t                            RegQDecAccDblCapture;         /**< Double movements accumulator capture */
} QDec_RegMap_t;

/** @} end of group QDec_RegMap */



/***************************************************************************//**
 * @defgroup QDec_BitFields QDec bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegQDecEn
 * @{
 */
// RegQDecEn.r32
#define  REG_QDEC_EN_RESET_VALUE                            0x00000000u                   /**< Reset value of RegQDecEn */
#define  REG_QDEC_EN_MASK                                   0x00010001u                   /**< Mask for RegQDecEn */

#define  QDEC_EN_SHIFT                                      0                             /**< Shift for QDecEn */
#define  QDEC_EN_MASK                                       0x00000001u                   /**< Mask for QDecEn */
#define  QDEC_EN_BMASK                                      0x1u                          /**< Base mask for QDecEn */
#define  QDEC_EN(x)                                         (((x)&0x1u)<<0)               /**< Set QDecEn in register */
#define  GET_QDEC_EN(reg)                                   (((reg)>>0)&0x1u)             /**< Get QDecEn from register */
#define  QDEC_RUNNING_SHIFT                                 16                            /**< Shift for QDecRunning */
#define  QDEC_RUNNING_MASK                                  0x00010000u                   /**< Mask for QDecRunning */
#define  QDEC_RUNNING_BMASK                                 0x1u                          /**< Base mask for QDecRunning */
#define  QDEC_RUNNING(x)                                    (((x)&0x1u)<<16)              /**< Set QDecRunning in register */
#define  GET_QDEC_RUNNING(reg)                              (((reg)>>16)&0x1u)            /**< Get QDecRunning from register */
/** @} */


/**
 * @name RegQDecCfg
 * @{
 */
// RegQDecCfg.r32
#define  REG_QDEC_CFG_RESET_VALUE                           0x00000000u                   /**< Reset value of RegQDecCfg */
#define  REG_QDEC_CFG_MASK                                  0x00070103u                   /**< Mask for RegQDecCfg */

#define  QDEC_LED_EN_SHIFT                                  0                             /**< Shift for QDecLedEn */
#define  QDEC_LED_EN_MASK                                   0x00000001u                   /**< Mask for QDecLedEn */
#define  QDEC_LED_EN_BMASK                                  0x1u                          /**< Base mask for QDecLedEn */
#define  QDEC_LED_EN(x)                                     (((x)&0x1u)<<0)               /**< Set QDecLedEn in register */
#define  GET_QDEC_LED_EN(reg)                               (((reg)>>0)&0x1u)             /**< Get QDecLedEn from register */
#define  QDEC_LED_POL_SHIFT                                 1                             /**< Shift for QDecLedPol */
#define  QDEC_LED_POL_MASK                                  0x00000002u                   /**< Mask for QDecLedPol */
#define  QDEC_LED_POL_BMASK                                 0x1u                          /**< Base mask for QDecLedPol */
#define  QDEC_LED_POL(x)                                    (((x)&0x1u)<<1)               /**< Set QDecLedPol in register */
#define  GET_QDEC_LED_POL(reg)                              (((reg)>>1)&0x1u)             /**< Get QDecLedPol from register */
#define  QDEC_DBC_EN_SHIFT                                  8                             /**< Shift for QDecDbcEn */
#define  QDEC_DBC_EN_MASK                                   0x00000100u                   /**< Mask for QDecDbcEn */
#define  QDEC_DBC_EN_BMASK                                  0x1u                          /**< Base mask for QDecDbcEn */
#define  QDEC_DBC_EN(x)                                     (((x)&0x1u)<<8)               /**< Set QDecDbcEn in register */
#define  GET_QDEC_DBC_EN(reg)                               (((reg)>>8)&0x1u)             /**< Get QDecDbcEn from register */
#define  QDEC_WAKE_REP_RDY_EN_SHIFT                         16                            /**< Shift for QDecWakeRepRdyEn */
#define  QDEC_WAKE_REP_RDY_EN_MASK                          0x00010000u                   /**< Mask for QDecWakeRepRdyEn */
#define  QDEC_WAKE_REP_RDY_EN_BMASK                         0x1u                          /**< Base mask for QDecWakeRepRdyEn */
#define  QDEC_WAKE_REP_RDY_EN(x)                            (((x)&0x1u)<<16)              /**< Set QDecWakeRepRdyEn in register */
#define  GET_QDEC_WAKE_REP_RDY_EN(reg)                      (((reg)>>16)&0x1u)            /**< Get QDecWakeRepRdyEn from register */
#define  QDEC_WAKE_OVF_EN_SHIFT                             17                            /**< Shift for QDecWakeOvfEn */
#define  QDEC_WAKE_OVF_EN_MASK                              0x00020000u                   /**< Mask for QDecWakeOvfEn */
#define  QDEC_WAKE_OVF_EN_BMASK                             0x1u                          /**< Base mask for QDecWakeOvfEn */
#define  QDEC_WAKE_OVF_EN(x)                                (((x)&0x1u)<<17)              /**< Set QDecWakeOvfEn in register */
#define  GET_QDEC_WAKE_OVF_EN(reg)                          (((reg)>>17)&0x1u)            /**< Get QDecWakeOvfEn from register */
#define  QDEC_WAKE_DBL_EN_SHIFT                             18                            /**< Shift for QDecWakeDblEn */
#define  QDEC_WAKE_DBL_EN_MASK                              0x00040000u                   /**< Mask for QDecWakeDblEn */
#define  QDEC_WAKE_DBL_EN_BMASK                             0x1u                          /**< Base mask for QDecWakeDblEn */
#define  QDEC_WAKE_DBL_EN(x)                                (((x)&0x1u)<<18)              /**< Set QDecWakeDblEn in register */
#define  GET_QDEC_WAKE_DBL_EN(reg)                          (((reg)>>18)&0x1u)            /**< Get QDecWakeDblEn from register */
/** @} */


/**
 * @name RegQDecPinSel
 * @{
 */
// RegQDecPinSel.r32
#define  REG_QDEC_PIN_SEL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegQDecPinSel */
#define  REG_QDEC_PIN_SEL_MASK                              0x000F0F0Fu                   /**< Mask for RegQDecPinSel */

#define  QDEC_IN_SEL_PHASE_A_SHIFT                          0                             /**< Shift for QDecInSelPhaseA */
#define  QDEC_IN_SEL_PHASE_A_MASK                           0x0000000Fu                   /**< Mask for QDecInSelPhaseA */
#define  QDEC_IN_SEL_PHASE_A_BMASK                          0xFu                          /**< Base mask for QDecInSelPhaseA */
#define  QDEC_IN_SEL_PHASE_A(x)                             (((x)&0xFu)<<0)               /**< Set QDecInSelPhaseA in register */
#define  GET_QDEC_IN_SEL_PHASE_A(reg)                       (((reg)>>0)&0xFu)             /**< Get QDecInSelPhaseA from register */
#define  QDEC_IN_SEL_PHASE_B_SHIFT                          8                             /**< Shift for QDecInSelPhaseB */
#define  QDEC_IN_SEL_PHASE_B_MASK                           0x00000F00u                   /**< Mask for QDecInSelPhaseB */
#define  QDEC_IN_SEL_PHASE_B_BMASK                          0xFu                          /**< Base mask for QDecInSelPhaseB */
#define  QDEC_IN_SEL_PHASE_B(x)                             (((x)&0xFu)<<8)               /**< Set QDecInSelPhaseB in register */
#define  GET_QDEC_IN_SEL_PHASE_B(reg)                       (((reg)>>8)&0xFu)             /**< Get QDecInSelPhaseB from register */
#define  QDEC_OUT_SEL_LED_SHIFT                             16                            /**< Shift for QDecOutSelLed */
#define  QDEC_OUT_SEL_LED_MASK                              0x000F0000u                   /**< Mask for QDecOutSelLed */
#define  QDEC_OUT_SEL_LED_BMASK                             0xFu                          /**< Base mask for QDecOutSelLed */
#define  QDEC_OUT_SEL_LED(x)                                (((x)&0xFu)<<16)              /**< Set QDecOutSelLed in register */
#define  GET_QDEC_OUT_SEL_LED(reg)                          (((reg)>>16)&0xFu)            /**< Get QDecOutSelLed from register */
/** @} */


/**
 * @name RegQDecCaptureCtrl
 * @{
 */
// RegQDecCaptureCtrl.r32
#define  REG_QDEC_CAPTURE_CTRL_RESET_VALUE                  0x00000000u                   /**< Reset value of RegQDecCaptureCtrl */
#define  REG_QDEC_CAPTURE_CTRL_MASK                         0x00030003u                   /**< Mask for RegQDecCaptureCtrl */

#define  QDEC_CAPTURE_ACC_SW_SHIFT                          0                             /**< Shift for QDecCaptureAccSw */
#define  QDEC_CAPTURE_ACC_SW_MASK                           0x00000001u                   /**< Mask for QDecCaptureAccSw */
#define  QDEC_CAPTURE_ACC_SW_BMASK                          0x1u                          /**< Base mask for QDecCaptureAccSw */
#define  QDEC_CAPTURE_ACC_SW(x)                             (((x)&0x1u)<<0)               /**< Set QDecCaptureAccSw in register */
#define  GET_QDEC_CAPTURE_ACC_SW(reg)                       (((reg)>>0)&0x1u)             /**< Get QDecCaptureAccSw from register */
#define  QDEC_CAPTURE_ACC_DBL_SW_SHIFT                      1                             /**< Shift for QDecCaptureAccDblSw */
#define  QDEC_CAPTURE_ACC_DBL_SW_MASK                       0x00000002u                   /**< Mask for QDecCaptureAccDblSw */
#define  QDEC_CAPTURE_ACC_DBL_SW_BMASK                      0x1u                          /**< Base mask for QDecCaptureAccDblSw */
#define  QDEC_CAPTURE_ACC_DBL_SW(x)                         (((x)&0x1u)<<1)               /**< Set QDecCaptureAccDblSw in register */
#define  GET_QDEC_CAPTURE_ACC_DBL_SW(reg)                   (((reg)>>1)&0x1u)             /**< Get QDecCaptureAccDblSw from register */
#define  QDEC_CAPTURE_ACC_HW_SHIFT                          16                            /**< Shift for QDecCaptureAccHw */
#define  QDEC_CAPTURE_ACC_HW_MASK                           0x00010000u                   /**< Mask for QDecCaptureAccHw */
#define  QDEC_CAPTURE_ACC_HW_BMASK                          0x1u                          /**< Base mask for QDecCaptureAccHw */
#define  QDEC_CAPTURE_ACC_HW(x)                             (((x)&0x1u)<<16)              /**< Set QDecCaptureAccHw in register */
#define  GET_QDEC_CAPTURE_ACC_HW(reg)                       (((reg)>>16)&0x1u)            /**< Get QDecCaptureAccHw from register */
#define  QDEC_CAPTURE_ACC_DBL_HW_SHIFT                      17                            /**< Shift for QDecCaptureAccDblHw */
#define  QDEC_CAPTURE_ACC_DBL_HW_MASK                       0x00020000u                   /**< Mask for QDecCaptureAccDblHw */
#define  QDEC_CAPTURE_ACC_DBL_HW_BMASK                      0x1u                          /**< Base mask for QDecCaptureAccDblHw */
#define  QDEC_CAPTURE_ACC_DBL_HW(x)                         (((x)&0x1u)<<17)              /**< Set QDecCaptureAccDblHw in register */
#define  GET_QDEC_CAPTURE_ACC_DBL_HW(reg)                   (((reg)>>17)&0x1u)            /**< Get QDecCaptureAccDblHw from register */
/** @} */


/**
 * @name RegQDecPeriodCfg
 * @{
 */
// RegQDecPeriodCfg.r32
#define  REG_QDEC_PERIOD_CFG_RESET_VALUE                    0x00000000u                   /**< Reset value of RegQDecPeriodCfg */
#define  REG_QDEC_PERIOD_CFG_MASK                           0x0007000Fu                   /**< Mask for RegQDecPeriodCfg */

#define  QDEC_SAMPLE_PER_SHIFT                              0                             /**< Shift for QDecSamplePer */
#define  QDEC_SAMPLE_PER_MASK                               0x0000000Fu                   /**< Mask for QDecSamplePer */
#define  QDEC_SAMPLE_PER_BMASK                              0xFu                          /**< Base mask for QDecSamplePer */
#define  QDEC_SAMPLE_PER(x)                                 (((x)&0xFu)<<0)               /**< Set QDecSamplePer in register */
#define  GET_QDEC_SAMPLE_PER(reg)                           (((reg)>>0)&0xFu)             /**< Get QDecSamplePer from register */
#define  QDEC_REPORT_PER_SHIFT                              16                            /**< Shift for QDecReportPer */
#define  QDEC_REPORT_PER_MASK                               0x00070000u                   /**< Mask for QDecReportPer */
#define  QDEC_REPORT_PER_BMASK                              0x7u                          /**< Base mask for QDecReportPer */
#define  QDEC_REPORT_PER(x)                                 (((x)&0x7u)<<16)              /**< Set QDecReportPer in register */
#define  GET_QDEC_REPORT_PER(reg)                           (((reg)>>16)&0x7u)            /**< Get QDecReportPer from register */
/** @} */


/**
 * @name RegQDecTimeCfg
 * @{
 */
// RegQDecTimeCfg.r32
#define  REG_QDEC_TIME_CFG_RESET_VALUE                      0x00000000u                   /**< Reset value of RegQDecTimeCfg */
#define  REG_QDEC_TIME_CFG_MASK                             0xFFFF0000u                   /**< Mask for RegQDecTimeCfg */

#define  QDEC_LED_TIME_SHIFT                                16                            /**< Shift for QDecLedTime */
#define  QDEC_LED_TIME_MASK                                 0xFFFF0000u                   /**< Mask for QDecLedTime */
#define  QDEC_LED_TIME_BMASK                                0xFFFFu                       /**< Base mask for QDecLedTime */
#define  QDEC_LED_TIME(x)                                   (((x)&0xFFFFu)<<16)           /**< Set QDecLedTime in register */
#define  GET_QDEC_LED_TIME(reg)                             (((reg)>>16)&0xFFFFu)         /**< Get QDecLedTime from register */
/** @} */


/**
 * @name RegQDecSample
 * @{
 */
// RegQDecSample.r32
#define  REG_QDEC_SAMPLE_RESET_VALUE                        0x00000000u                   /**< Reset value of RegQDecSample */
#define  REG_QDEC_SAMPLE_MASK                               0xFFFFFFFFu                   /**< Mask for RegQDecSample */

#define  QDEC_SAMPLE_SHIFT                                  0                             /**< Shift for QDecSample */
#define  QDEC_SAMPLE_MASK                                   0xFFFFFFFFu                   /**< Mask for QDecSample */
#define  QDEC_SAMPLE_BMASK                                  0xFFFFFFFFu                   /**< Base mask for QDecSample */
#define  QDEC_SAMPLE(x)                                     (((x)&0xFFFFFFFFu)<<0)        /**< Set QDecSample in register */
#define  GET_QDEC_SAMPLE(reg)                               (((reg)>>0)&0xFFFFFFFFu)      /**< Get QDecSample from register */
/** @} */


/**
 * @name RegQDecAcc
 * @{
 */
// RegQDecAcc.r32
#define  REG_QDEC_ACC_RESET_VALUE                           0x00000000u                   /**< Reset value of RegQDecAcc */
#define  REG_QDEC_ACC_MASK                                  0xFFFFFFFFu                   /**< Mask for RegQDecAcc */

#define  QDEC_ACC_SHIFT                                     0                             /**< Shift for QDecAcc */
#define  QDEC_ACC_MASK                                      0xFFFFFFFFu                   /**< Mask for QDecAcc */
#define  QDEC_ACC_BMASK                                     0xFFFFFFFFu                   /**< Base mask for QDecAcc */
#define  QDEC_ACC(x)                                        (((x)&0xFFFFFFFFu)<<0)        /**< Set QDecAcc in register */
#define  GET_QDEC_ACC(reg)                                  (((reg)>>0)&0xFFFFFFFFu)      /**< Get QDecAcc from register */
/** @} */


/**
 * @name RegQDecAccDbl
 * @{
 */
// RegQDecAccDbl.r32
#define  REG_QDEC_ACC_DBL_RESET_VALUE                       0x00000000u                   /**< Reset value of RegQDecAccDbl */
#define  REG_QDEC_ACC_DBL_MASK                              0x0000000Fu                   /**< Mask for RegQDecAccDbl */

#define  QDEC_ACC_DBL_SHIFT                                 0                             /**< Shift for QDecAccDbl */
#define  QDEC_ACC_DBL_MASK                                  0x0000000Fu                   /**< Mask for QDecAccDbl */
#define  QDEC_ACC_DBL_BMASK                                 0xFu                          /**< Base mask for QDecAccDbl */
#define  QDEC_ACC_DBL(x)                                    (((x)&0xFu)<<0)               /**< Set QDecAccDbl in register */
#define  GET_QDEC_ACC_DBL(reg)                              (((reg)>>0)&0xFu)             /**< Get QDecAccDbl from register */
/** @} */


/**
 * @name RegQDecAccCapture
 * @{
 */
// RegQDecAccCapture.r32
#define  REG_QDEC_ACC_CAPTURE_RESET_VALUE                   0x00000000u                   /**< Reset value of RegQDecAccCapture */
#define  REG_QDEC_ACC_CAPTURE_MASK                          0xFFFFFFFFu                   /**< Mask for RegQDecAccCapture */

#define  QDEC_ACC_CAPTURE_SHIFT                             0                             /**< Shift for QDecAccCapture */
#define  QDEC_ACC_CAPTURE_MASK                              0xFFFFFFFFu                   /**< Mask for QDecAccCapture */
#define  QDEC_ACC_CAPTURE_BMASK                             0xFFFFFFFFu                   /**< Base mask for QDecAccCapture */
#define  QDEC_ACC_CAPTURE(x)                                (((x)&0xFFFFFFFFu)<<0)        /**< Set QDecAccCapture in register */
#define  GET_QDEC_ACC_CAPTURE(reg)                          (((reg)>>0)&0xFFFFFFFFu)      /**< Get QDecAccCapture from register */
/** @} */


/**
 * @name RegQDecAccDblCapture
 * @{
 */
// RegQDecAccDblCapture.r32
#define  REG_QDEC_ACC_DBL_CAPTURE_RESET_VALUE               0x00000000u                   /**< Reset value of RegQDecAccDblCapture */
#define  REG_QDEC_ACC_DBL_CAPTURE_MASK                      0x0000000Fu                   /**< Mask for RegQDecAccDblCapture */

#define  QDEC_ACC_DBL_CAPTURE_SHIFT                         0                             /**< Shift for QDecAccDblCapture */
#define  QDEC_ACC_DBL_CAPTURE_MASK                          0x0000000Fu                   /**< Mask for QDecAccDblCapture */
#define  QDEC_ACC_DBL_CAPTURE_BMASK                         0xFu                          /**< Base mask for QDecAccDblCapture */
#define  QDEC_ACC_DBL_CAPTURE(x)                            (((x)&0xFu)<<0)               /**< Set QDecAccDblCapture in register */
#define  GET_QDEC_ACC_DBL_CAPTURE(reg)                      (((reg)>>0)&0xFu)             /**< Get QDecAccDblCapture from register */
/** @} */



/** @} End of group QDec_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_QDEC_H */
