////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_rng.h
///
/// @project    T9305
///
/// @brief      RNG register and bit field definitions
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

#ifndef _T9305_RNG_H
#define _T9305_RNG_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup RNG_Registers RNG Register Map - registers
 * @{
 ******************************************************************************/


/** RNG controls */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RNGStartReset;                             /**< RNG start and reset for RNG core 0..3 */
        uint8_t  RNGSampling;                               /**< RNG sampling for RNG core 0..3 */
        uint8_t  RNGSel;                                    /**< RNG mux selector */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegRNGCtrl_t;


/** RNG status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegRNGStat_t;


/** Random number generated */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  RNGOutCore0;                               /**< Random number - core 0 */
        uint8_t  RNGOutCore1;                               /**< Random number - core 1 */
        uint8_t  RNGOutCore2;                               /**< Random number - core 2 */
        uint8_t  RNGOutCore3;                               /**< Random number - core 3 */
    } regs;
} RegRNGOut_t;

/** @} end of group RNG_Regs */



/***************************************************************************//**
 * @defgroup RNG_RegMap RNG Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegRNGCtrl_t                                      RegRNGCtrl;                   /**< RNG controls */
    __I   RegRNGStat_t                                      RegRNGStat;                   /**< RNG status */
    __I   RegRNGOut_t                                       RegRNGOut;                    /**< Random number generated */
} RNG_RegMap_t;

/** @} end of group RNG_RegMap */



/***************************************************************************//**
 * @defgroup RNG_BitFields RNG bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegRNGCtrl
 * @{
 */
// RegRNGCtrl.r32
#define  REG_RNG_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRNGCtrl */
#define  REG_RNG_CTRL_MASK                                  0x00007F0Fu                   /**< Mask for RegRNGCtrl */

#define  RNG_START_SHIFT                                    0                             /**< Shift for RNGStart */
#define  RNG_START_MASK                                     0x0000000Fu                   /**< Mask for RNGStart */
#define  RNG_START_BMASK                                    0xFu                          /**< Base mask for RNGStart */
#define  RNG_START(x)                                       (((x)&0xFu)<<0)               /**< Set RNGStart in register */
#define  GET_RNG_START(reg)                                 (((reg)>>0)&0xFu)             /**< Get RNGStart from register */
#define  RNG_SAMPLING_SHIFT                                 8                             /**< Shift for RNGSampling */
#define  RNG_SAMPLING_MASK                                  0x00000F00u                   /**< Mask for RNGSampling */
#define  RNG_SAMPLING_BMASK                                 0xFu                          /**< Base mask for RNGSampling */
#define  RNG_SAMPLING(x)                                    (((x)&0xFu)<<8)               /**< Set RNGSampling in register */
#define  GET_RNG_SAMPLING(reg)                              (((reg)>>8)&0xFu)             /**< Get RNGSampling from register */
#define  RNG_SEL_SHIFT                                      12                            /**< Shift for RNGSel */
#define  RNG_SEL_MASK                                       0x00007000u                   /**< Mask for RNGSel */
#define  RNG_SEL_BMASK                                      0x7u                          /**< Base mask for RNGSel */
#define  RNG_SEL(x)                                         (((x)&0x7u)<<12)              /**< Set RNGSel in register */
#define  GET_RNG_SEL(reg)                                   (((reg)>>12)&0x7u)            /**< Get RNGSel from register */

// RegRNGCtrl.regs.RNGStartReset
#define  RNG_START_RESET_GSHIFT                             0                             /**< Shift for group RNGStartReset */
#define  RNG_START_RESET_GSIZE                              8                             /**< Size of group RNGStartReset */
#define  RNG_START_RESET_GMASK                              0x000000FFu                   /**< Mask for group RNGStartReset */

#define  RNG_START_RSHIFT                                   0                             /**< Shift for RNGStart */
#define  RNG_START_RMASK                                    0x0Fu                         /**< Mask for RNGStart */
#define  RNG_START_RBMASK                                   0xFu                          /**< Base mask for RNGStart */
#define  RNG_START_R(x)                                     (((x)&0xFu)<<0)               /**< Set RNGStart in register */
#define  GET_RNG_START_R(reg)                               (((reg)>>0)&0xFu)             /**< Get RNGStart from register */

// RegRNGCtrl.regs.RNGSampling
#define  RNG_SAMPLING_GSHIFT                                8                             /**< Shift for group RNGSampling */
#define  RNG_SAMPLING_GSIZE                                 8                             /**< Size of group RNGSampling */
#define  RNG_SAMPLING_GMASK                                 0x0000FF00u                   /**< Mask for group RNGSampling */

#define  RNG_SAMPLING_RSHIFT                                0                             /**< Shift for RNGSampling */
#define  RNG_SAMPLING_RMASK                                 0x0Fu                         /**< Mask for RNGSampling */
#define  RNG_SAMPLING_RBMASK                                0xFu                          /**< Base mask for RNGSampling */
#define  RNG_SAMPLING_R(x)                                  (((x)&0xFu)<<0)               /**< Set RNGSampling in register */
#define  GET_RNG_SAMPLING_R(reg)                            (((reg)>>0)&0xFu)             /**< Get RNGSampling from register */

// RegRNGCtrl.regs.RNGSel
#define  RNG_SEL_GSHIFT                                     12                            /**< Shift for group RNGSel */
#define  RNG_SEL_GSIZE                                      8                             /**< Size of group RNGSel */
#define  RNG_SEL_GMASK                                      0x000FF000u                   /**< Mask for group RNGSel */

#define  RNG_SEL_RSHIFT                                     0                             /**< Shift for RNGSel */
#define  RNG_SEL_RMASK                                      0x07u                         /**< Mask for RNGSel */
#define  RNG_SEL_RBMASK                                     0x7u                          /**< Base mask for RNGSel */
#define  RNG_SEL_R(x)                                       (((x)&0x7u)<<0)               /**< Set RNGSel in register */
#define  GET_RNG_SEL_R(reg)                                 (((reg)>>0)&0x7u)             /**< Get RNGSel from register */
/** @} */


/**
 * @name RegRNGStat
 * @{
 */
// RegRNGStat.r32
#define  REG_RNG_STAT_RESET_VALUE                           0x00000000u                   /**< Reset value of RegRNGStat */
#define  REG_RNG_STAT_MASK                                  0x0000000Fu                   /**< Mask for RegRNGStat */

#define  RNG_READY_SHIFT                                    0                             /**< Shift for RNGReady */
#define  RNG_READY_MASK                                     0x0000000Fu                   /**< Mask for RNGReady */
#define  RNG_READY_BMASK                                    0xFu                          /**< Base mask for RNGReady */
#define  RNG_READY(x)                                       (((x)&0xFu)<<0)               /**< Set RNGReady in register */
#define  GET_RNG_READY(reg)                                 (((reg)>>0)&0xFu)             /**< Get RNGReady from register */
/** @} */


/**
 * @name RegRNGOut
 * @{
 */
// RegRNGOut.r32
#define  REG_RNG_OUT_RESET_VALUE                            0x00000000u                   /**< Reset value of RegRNGOut */
#define  REG_RNG_OUT_MASK                                   0xFFFFFFFFu                   /**< Mask for RegRNGOut */

#define  RNG_OUT_CORE0_SHIFT                                0                             /**< Shift for RNGOutCore0 */
#define  RNG_OUT_CORE0_MASK                                 0x000000FFu                   /**< Mask for RNGOutCore0 */
#define  RNG_OUT_CORE0_BMASK                                0xFFu                         /**< Base mask for RNGOutCore0 */
#define  RNG_OUT_CORE0(x)                                   (((x)&0xFFu)<<0)              /**< Set RNGOutCore0 in register */
#define  GET_RNG_OUT_CORE0(reg)                             (((reg)>>0)&0xFFu)            /**< Get RNGOutCore0 from register */
#define  RNG_OUT_CORE1_SHIFT                                8                             /**< Shift for RNGOutCore1 */
#define  RNG_OUT_CORE1_MASK                                 0x0000FF00u                   /**< Mask for RNGOutCore1 */
#define  RNG_OUT_CORE1_BMASK                                0xFFu                         /**< Base mask for RNGOutCore1 */
#define  RNG_OUT_CORE1(x)                                   (((x)&0xFFu)<<8)              /**< Set RNGOutCore1 in register */
#define  GET_RNG_OUT_CORE1(reg)                             (((reg)>>8)&0xFFu)            /**< Get RNGOutCore1 from register */
#define  RNG_OUT_CORE2_SHIFT                                16                            /**< Shift for RNGOutCore2 */
#define  RNG_OUT_CORE2_MASK                                 0x00FF0000u                   /**< Mask for RNGOutCore2 */
#define  RNG_OUT_CORE2_BMASK                                0xFFu                         /**< Base mask for RNGOutCore2 */
#define  RNG_OUT_CORE2(x)                                   (((x)&0xFFu)<<16)             /**< Set RNGOutCore2 in register */
#define  GET_RNG_OUT_CORE2(reg)                             (((reg)>>16)&0xFFu)           /**< Get RNGOutCore2 from register */
#define  RNG_OUT_CORE3_SHIFT                                24                            /**< Shift for RNGOutCore3 */
#define  RNG_OUT_CORE3_MASK                                 0xFF000000u                   /**< Mask for RNGOutCore3 */
#define  RNG_OUT_CORE3_BMASK                                0xFFu                         /**< Base mask for RNGOutCore3 */
#define  RNG_OUT_CORE3(x)                                   (((x)&0xFFu)<<24)             /**< Set RNGOutCore3 in register */
#define  GET_RNG_OUT_CORE3(reg)                             (((reg)>>24)&0xFFu)           /**< Get RNGOutCore3 from register */

// RegRNGOut.regs.RNGOutCore0
#define  RNG_OUT_CORE0_GSHIFT                               0                             /**< Shift for group RNGOutCore0 */
#define  RNG_OUT_CORE0_GSIZE                                8                             /**< Size of group RNGOutCore0 */
#define  RNG_OUT_CORE0_GMASK                                0x000000FFu                   /**< Mask for group RNGOutCore0 */

#define  RNG_OUT_CORE0_RSHIFT                               0                             /**< Shift for RNGOutCore0 */
#define  RNG_OUT_CORE0_RMASK                                0x000000FFu                   /**< Mask for RNGOutCore0 */
#define  RNG_OUT_CORE0_RBMASK                               0xFFu                         /**< Base mask for RNGOutCore0 */
#define  RNG_OUT_CORE0_R(x)                                 (((x)&0xFFu)<<0)              /**< Set RNGOutCore0 in register */
#define  GET_RNG_OUT_CORE0_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get RNGOutCore0 from register */

// RegRNGOut.regs.RNGOutCore1
#define  RNG_OUT_CORE1_GSHIFT                               8                             /**< Shift for group RNGOutCore1 */
#define  RNG_OUT_CORE1_GSIZE                                8                             /**< Size of group RNGOutCore1 */
#define  RNG_OUT_CORE1_GMASK                                0x0000FF00u                   /**< Mask for group RNGOutCore1 */

#define  RNG_OUT_CORE1_RSHIFT                               0                             /**< Shift for RNGOutCore1 */
#define  RNG_OUT_CORE1_RMASK                                0x000000FFu                   /**< Mask for RNGOutCore1 */
#define  RNG_OUT_CORE1_RBMASK                               0xFFu                         /**< Base mask for RNGOutCore1 */
#define  RNG_OUT_CORE1_R(x)                                 (((x)&0xFFu)<<0)              /**< Set RNGOutCore1 in register */
#define  GET_RNG_OUT_CORE1_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get RNGOutCore1 from register */

// RegRNGOut.regs.RNGOutCore2
#define  RNG_OUT_CORE2_GSHIFT                               16                            /**< Shift for group RNGOutCore2 */
#define  RNG_OUT_CORE2_GSIZE                                8                             /**< Size of group RNGOutCore2 */
#define  RNG_OUT_CORE2_GMASK                                0x00FF0000u                   /**< Mask for group RNGOutCore2 */

#define  RNG_OUT_CORE2_RSHIFT                               0                             /**< Shift for RNGOutCore2 */
#define  RNG_OUT_CORE2_RMASK                                0x000000FFu                   /**< Mask for RNGOutCore2 */
#define  RNG_OUT_CORE2_RBMASK                               0xFFu                         /**< Base mask for RNGOutCore2 */
#define  RNG_OUT_CORE2_R(x)                                 (((x)&0xFFu)<<0)              /**< Set RNGOutCore2 in register */
#define  GET_RNG_OUT_CORE2_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get RNGOutCore2 from register */

// RegRNGOut.regs.RNGOutCore3
#define  RNG_OUT_CORE3_GSHIFT                               24                            /**< Shift for group RNGOutCore3 */
#define  RNG_OUT_CORE3_GSIZE                                8                             /**< Size of group RNGOutCore3 */
#define  RNG_OUT_CORE3_GMASK                                0xFF000000u                   /**< Mask for group RNGOutCore3 */

#define  RNG_OUT_CORE3_RSHIFT                               0                             /**< Shift for RNGOutCore3 */
#define  RNG_OUT_CORE3_RMASK                                0x000000FFu                   /**< Mask for RNGOutCore3 */
#define  RNG_OUT_CORE3_RBMASK                               0xFFu                         /**< Base mask for RNGOutCore3 */
#define  RNG_OUT_CORE3_R(x)                                 (((x)&0xFFu)<<0)              /**< Set RNGOutCore3 in register */
#define  GET_RNG_OUT_CORE3_R(reg)                           (((reg)>>0)&0xFFu)            /**< Get RNGOutCore3 from register */
/** @} */



/** @} End of group RNG_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_RNG_H */
