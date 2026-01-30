////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_aoad_matrix.h
///
/// @project    T9305
///
/// @brief      Angle of Arrival Departure Matrix register and bit field definitions
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

#ifndef _T9305_AOAD_MATRIX_H
#define _T9305_AOAD_MATRIX_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup AoADMatrix_Registers AoA/AoD Matrix Register Map - registers
 * @{
 ******************************************************************************/


/** Angle of Arrival / Angle of Departure Matrix Control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadEn;                                    /**< AoA/AoD Matrix enable : '0' - stopped, '1' - enabled, waiting for HW or SW start */
        uint8_t  AoadCtrlMode;                              /**< AoA/AoD Matrix SW control : '0' - matrix switching start/stop controlled from HW, '1' - matrix switching start/stop controled from SW */
        uint16_t AoadCtrlSw;                                /**< SW control of AoA/AoD matrix - valid when Aoad_Ctrl_Mode = 1 */
    } regs;
} RegAoadCtrl_t;


/** AoA/AoD GPIO Selector 0. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadGpioOutSel0;                           /**< Defines which LUT bit is selected to GPIO0 */
        uint8_t  AoadGpioOutSel1;                           /**< Defines which LUT bit is selected to GPIO1 */
        uint8_t  AoadGpioOutSel2;                           /**< Defines which LUT bit is selected to GPIO2 */
        uint8_t  AoadGpioOutSel3;                           /**< Defines which LUT bit is selected to GPIO3 */
    } regs;
} RegAoadGpioSel0_t;


/** AoA/AoD GPIO Selector 1. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadGpioOutSel4;                           /**< Defines which LUT bit is selected to GPIO4 */
        uint8_t  AoadGpioOutSel5;                           /**< Defines which LUT bit is selected to GPIO5 */
        uint8_t  AoadGpioOutSel6;                           /**< Defines which LUT bit is selected to GPIO6 */
        uint8_t  AoadGpioOutSel7;                           /**< Defines which LUT bit is selected to GPIO7 */
    } regs;
} RegAoadGpioSel1_t;


/** AoA/AoD GPIO Selector 2. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadGpioOutSel8;                           /**< Defines which LUT bit is selected to GPIO8 */
        uint8_t  AoadGpioOutSel9;                           /**< Defines which LUT bit is selected to GPIO9 */
        uint8_t  AoadGpioOutSel10;                          /**< Defines which LUT bit is selected to GPIO10 */
        uint8_t  AoadGpioOutSel11;                          /**< Defines which LUT bit is selected to GPIO11 */
    } regs;
} RegAoadGpioSel2_t;


/** AoA/AoD Matrix Look-Up register 0It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut0;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 0 */
        uint8_t  AoadLut1;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 1 */
        uint8_t  AoadLut2;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 2 */
        uint8_t  AoadLut3;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 3 */
    } regs;
} RegAoadLut0_t;


/** AoA/AoD Matrix Look-Up register 1It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut4;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 4 */
        uint8_t  AoadLut5;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 5 */
        uint8_t  AoadLut6;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 6 */
        uint8_t  AoadLut7;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 7 */
    } regs;
} RegAoadLut1_t;


/** AoA/AoD Matrix Look-Up register 2It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut8;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 8 */
        uint8_t  AoadLut9;                                  /**< AoA/AoD Matrix Look-Up value for CTE Sample 9 */
        uint8_t  AoadLut10;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 10 */
        uint8_t  AoadLut11;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 11 */
    } regs;
} RegAoadLut2_t;


/** AoA/AoD Matrix Look-Up register 3It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut12;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 12 */
        uint8_t  AoadLut13;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 13 */
        uint8_t  AoadLut14;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 14 */
        uint8_t  AoadLut15;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 15 */
    } regs;
} RegAoadLut3_t;


/** AoA/AoD Matrix Look-Up register 4It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut16;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 16 */
        uint8_t  AoadLut17;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 17 */
        uint8_t  AoadLut18;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 18 */
        uint8_t  AoadLut19;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 19 */
    } regs;
} RegAoadLut4_t;


/** AoA/AoD Matrix Look-Up register 5It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut20;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 20 */
        uint8_t  AoadLut21;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 21 */
        uint8_t  AoadLut22;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 22 */
        uint8_t  AoadLut23;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 23 */
    } regs;
} RegAoadLut5_t;


/** AoA/AoD Matrix Look-Up register 6It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut24;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 24 */
        uint8_t  AoadLut25;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 25 */
        uint8_t  AoadLut26;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 26 */
        uint8_t  AoadLut27;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 27 */
    } regs;
} RegAoadLut6_t;


/** AoA/AoD Matrix Look-Up register 7It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut28;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 28 */
        uint8_t  AoadLut29;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 29 */
        uint8_t  AoadLut30;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 30 */
        uint8_t  AoadLut31;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 31 */
    } regs;
} RegAoadLut7_t;


/** AoA/AoD Matrix Look-Up register 8It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut32;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 32 */
        uint8_t  AoadLut33;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 33 */
        uint8_t  AoadLut34;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 34 */
        uint8_t  AoadLut35;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 35 */
    } regs;
} RegAoadLut8_t;


/** AoA/AoD Matrix Look-Up register 9It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut36;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 36 */
        uint8_t  AoadLut37;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 37 */
        uint8_t  AoadLut38;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 38 */
        uint8_t  AoadLut39;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 39 */
    } regs;
} RegAoadLut9_t;


/** AoA/AoD Matrix Look-Up register 10It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut40;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 40 */
        uint8_t  AoadLut41;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 41 */
        uint8_t  AoadLut42;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 42 */
        uint8_t  AoadLut43;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 43 */
    } regs;
} RegAoadLut10_t;


/** AoA/AoD Matrix Look-Up register 11It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut44;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 44 */
        uint8_t  AoadLut45;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 45 */
        uint8_t  AoadLut46;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 46 */
        uint8_t  AoadLut47;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 47 */
    } regs;
} RegAoadLut11_t;


/** AoA/AoD Matrix Look-Up register 12It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut48;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 48 */
        uint8_t  AoadLut49;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 49 */
        uint8_t  AoadLut50;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 50 */
        uint8_t  AoadLut51;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 51 */
    } regs;
} RegAoadLut12_t;


/** AoA/AoD Matrix Look-Up register 13It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut52;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 52 */
        uint8_t  AoadLut53;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 53 */
        uint8_t  AoadLut54;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 54 */
        uint8_t  AoadLut55;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 55 */
    } regs;
} RegAoadLut13_t;


/** AoA/AoD Matrix Look-Up register 14It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut56;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 56 */
        uint8_t  AoadLut57;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 57 */
        uint8_t  AoadLut58;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 58 */
        uint8_t  AoadLut59;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 59 */
    } regs;
} RegAoadLut14_t;


/** AoA/AoD Matrix Look-Up register 15It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut60;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 60 */
        uint8_t  AoadLut61;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 61 */
        uint8_t  AoadLut62;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 62 */
        uint8_t  AoadLut63;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 63 */
    } regs;
} RegAoadLut15_t;


/** AoA/AoD Matrix Look-Up register 16It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut64;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 64 */
        uint8_t  AoadLut65;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 65 */
        uint8_t  AoadLut66;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 66 */
        uint8_t  AoadLut67;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 67 */
    } regs;
} RegAoadLut16_t;


/** AoA/AoD Matrix Look-Up register 17It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut68;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 68 */
        uint8_t  AoadLut69;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 69 */
        uint8_t  AoadLut70;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 70 */
        uint8_t  AoadLut71;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 71 */
    } regs;
} RegAoadLut17_t;


/** AoA/AoD Matrix Look-Up register 18It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  AoadLut72;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 72 */
        uint8_t  AoadLut73;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 73 */
        uint8_t  AoadLut74;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 74 */
        uint8_t  AoadLut75;                                 /**< AoA/AoD Matrix Look-Up value for CTE Sample 75 */
    } regs;
} RegAoadLut18_t;

/** @} end of group AoADMatrix_Regs */



/***************************************************************************//**
 * @defgroup AoADMatrix_RegMap AoA/AoD Matrix Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegAoadCtrl_t                                     RegAoadCtrl;                  /**< Angle of Arrival / Angle of Departure Matrix Control */
    __IO  RegAoadGpioSel0_t                                 RegAoadGpioSel0;              /**< AoA/AoD GPIO Selector 0. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
    __IO  RegAoadGpioSel1_t                                 RegAoadGpioSel1;              /**< AoA/AoD GPIO Selector 1. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
    __IO  RegAoadGpioSel2_t                                 RegAoadGpioSel2;              /**< AoA/AoD GPIO Selector 2. Defines which LUT bit will be connected to particular GPIO matrix input bits  */
    __IO  RegAoadLut0_t                                     RegAoadLut0;                  /**< AoA/AoD Matrix Look-Up register 0It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut1_t                                     RegAoadLut1;                  /**< AoA/AoD Matrix Look-Up register 1It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut2_t                                     RegAoadLut2;                  /**< AoA/AoD Matrix Look-Up register 2It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut3_t                                     RegAoadLut3;                  /**< AoA/AoD Matrix Look-Up register 3It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut4_t                                     RegAoadLut4;                  /**< AoA/AoD Matrix Look-Up register 4It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut5_t                                     RegAoadLut5;                  /**< AoA/AoD Matrix Look-Up register 5It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut6_t                                     RegAoadLut6;                  /**< AoA/AoD Matrix Look-Up register 6It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut7_t                                     RegAoadLut7;                  /**< AoA/AoD Matrix Look-Up register 7It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut8_t                                     RegAoadLut8;                  /**< AoA/AoD Matrix Look-Up register 8It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut9_t                                     RegAoadLut9;                  /**< AoA/AoD Matrix Look-Up register 9It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut10_t                                    RegAoadLut10;                 /**< AoA/AoD Matrix Look-Up register 10It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut11_t                                    RegAoadLut11;                 /**< AoA/AoD Matrix Look-Up register 11It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut12_t                                    RegAoadLut12;                 /**< AoA/AoD Matrix Look-Up register 12It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut13_t                                    RegAoadLut13;                 /**< AoA/AoD Matrix Look-Up register 13It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut14_t                                    RegAoadLut14;                 /**< AoA/AoD Matrix Look-Up register 14It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut15_t                                    RegAoadLut15;                 /**< AoA/AoD Matrix Look-Up register 15It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut16_t                                    RegAoadLut16;                 /**< AoA/AoD Matrix Look-Up register 16It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut17_t                                    RegAoadLut17;                 /**< AoA/AoD Matrix Look-Up register 17It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
    __IO  RegAoadLut18_t                                    RegAoadLut18;                 /**< AoA/AoD Matrix Look-Up register 18It contains 4x7 values. Each value is value represents the 7 bit value propagated to Switching matrix output in each sample of CTE. */
} AoADMatrix_RegMap_t;

/** @} end of group AoADMatrix_RegMap */



/***************************************************************************//**
 * @defgroup AoADMatrix_BitFields AoADMatrix bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegAoadCtrl
 * @{
 */
// RegAoadCtrl.r32
#define  REG_AOAD_CTRL_RESET_VALUE                          0x00000800u                   /**< Reset value of RegAoadCtrl */
#define  REG_AOAD_CTRL_MASK                                 0x037F0F01u                   /**< Mask for RegAoadCtrl */

#define  AOAD_EN_SHIFT                                      0                             /**< Shift for AoadEn */
#define  AOAD_EN_MASK                                       0x00000001u                   /**< Mask for AoadEn */
#define  AOAD_EN_BMASK                                      0x1u                          /**< Base mask for AoadEn */
#define  AOAD_EN(x)                                         (((x)&0x1u)<<0)               /**< Set AoadEn in register */
#define  GET_AOAD_EN(reg)                                   (((reg)>>0)&0x1u)             /**< Get AoadEn from register */
#define  AOAD_CTRL_MODE_SHIFT                               8                             /**< Shift for AoadCtrlMode */
#define  AOAD_CTRL_MODE_MASK                                0x00000100u                   /**< Mask for AoadCtrlMode */
#define  AOAD_CTRL_MODE_BMASK                               0x1u                          /**< Base mask for AoadCtrlMode */
#define  AOAD_CTRL_MODE(x)                                  (((x)&0x1u)<<8)               /**< Set AoadCtrlMode in register */
#define  GET_AOAD_CTRL_MODE(reg)                            (((reg)>>8)&0x1u)             /**< Get AoadCtrlMode from register */
#define  AOAD_REF_TIME_SHIFT                                9                             /**< Shift for AoadRefTime */
#define  AOAD_REF_TIME_MASK                                 0x00000E00u                   /**< Mask for AoadRefTime */
#define  AOAD_REF_TIME_BMASK                                0x7u                          /**< Base mask for AoadRefTime */
#define  AOAD_REF_TIME(x)                                   (((x)&0x7u)<<9)               /**< Set AoadRefTime in register */
#define  GET_AOAD_REF_TIME(reg)                             (((reg)>>9)&0x7u)             /**< Get AoadRefTime from register */
#define  AOAD_SW_NUM_SHIFT                                  16                            /**< Shift for AoadSwNum */
#define  AOAD_SW_NUM_MASK                                   0x007F0000u                   /**< Mask for AoadSwNum */
#define  AOAD_SW_NUM_BMASK                                  0x7Fu                         /**< Base mask for AoadSwNum */
#define  AOAD_SW_NUM(x)                                     (((x)&0x7Fu)<<16)             /**< Set AoadSwNum in register */
#define  GET_AOAD_SW_NUM(reg)                               (((reg)>>16)&0x7Fu)           /**< Get AoadSwNum from register */
#define  AOAD_SW_EN_SHIFT                                   24                            /**< Shift for AoadSwEn */
#define  AOAD_SW_EN_MASK                                    0x01000000u                   /**< Mask for AoadSwEn */
#define  AOAD_SW_EN_BMASK                                   0x1u                          /**< Base mask for AoadSwEn */
#define  AOAD_SW_EN(x)                                      (((x)&0x1u)<<24)              /**< Set AoadSwEn in register */
#define  GET_AOAD_SW_EN(reg)                                (((reg)>>24)&0x1u)            /**< Get AoadSwEn from register */
#define  AOAD_SW_PER_SHIFT                                  25                            /**< Shift for AoadSwPer */
#define  AOAD_SW_PER_MASK                                   0x02000000u                   /**< Mask for AoadSwPer */
#define  AOAD_SW_PER_BMASK                                  0x1u                          /**< Base mask for AoadSwPer */
#define  AOAD_SW_PER(x)                                     (((x)&0x1u)<<25)              /**< Set AoadSwPer in register */
#define  GET_AOAD_SW_PER(reg)                               (((reg)>>25)&0x1u)            /**< Get AoadSwPer from register */

// RegAoadCtrl.regs.AoadEn
#define  AOAD_EN_GSHIFT                                     0                             /**< Shift for group AoadEn */
#define  AOAD_EN_GSIZE                                      8                             /**< Size of group AoadEn */
#define  AOAD_EN_GMASK                                      0x000000FFu                   /**< Mask for group AoadEn */

#define  AOAD_EN_RSHIFT                                     0                             /**< Shift for AoadEn */
#define  AOAD_EN_RMASK                                      0x00000001u                   /**< Mask for AoadEn */
#define  AOAD_EN_RBMASK                                     0x1u                          /**< Base mask for AoadEn */
#define  AOAD_EN_R(x)                                       (((x)&0x1u)<<0)               /**< Set AoadEn in register */
#define  GET_AOAD_EN_R(reg)                                 (((reg)>>0)&0x1u)             /**< Get AoadEn from register */

// RegAoadCtrl.regs.AoadCtrlMode
#define  AOAD_CTRL_MODE_GSHIFT                              8                             /**< Shift for group AoadCtrlMode */
#define  AOAD_CTRL_MODE_GSIZE                               8                             /**< Size of group AoadCtrlMode */
#define  AOAD_CTRL_MODE_GMASK                               0x0000FF00u                   /**< Mask for group AoadCtrlMode */

#define  AOAD_CTRL_MODE_RSHIFT                              0                             /**< Shift for AoadCtrlMode */
#define  AOAD_CTRL_MODE_RMASK                               0x00000001u                   /**< Mask for AoadCtrlMode */
#define  AOAD_CTRL_MODE_RBMASK                              0x1u                          /**< Base mask for AoadCtrlMode */
#define  AOAD_CTRL_MODE_R(x)                                (((x)&0x1u)<<0)               /**< Set AoadCtrlMode in register */
#define  GET_AOAD_CTRL_MODE_R(reg)                          (((reg)>>0)&0x1u)             /**< Get AoadCtrlMode from register */
#define  AOAD_REF_TIME_RSHIFT                               1                             /**< Shift for AoadRefTime */
#define  AOAD_REF_TIME_RMASK                                0x0000000Eu                   /**< Mask for AoadRefTime */
#define  AOAD_REF_TIME_RBMASK                               0x7u                          /**< Base mask for AoadRefTime */
#define  AOAD_REF_TIME_R(x)                                 (((x)&0x7u)<<1)               /**< Set AoadRefTime in register */
#define  GET_AOAD_REF_TIME_R(reg)                           (((reg)>>1)&0x7u)             /**< Get AoadRefTime from register */

// RegAoadCtrl.regs.AoadCtrlSw
#define  AOAD_CTRL_SW_GSHIFT                                16                            /**< Shift for group AoadCtrlSw */
#define  AOAD_CTRL_SW_GSIZE                                 16                            /**< Size of group AoadCtrlSw */
#define  AOAD_CTRL_SW_GMASK                                 0xFFFF0000u                   /**< Mask for group AoadCtrlSw */

#define  AOAD_SW_NUM_RSHIFT                                 0                             /**< Shift for AoadSwNum */
#define  AOAD_SW_NUM_RMASK                                  0x007Fu                       /**< Mask for AoadSwNum */
#define  AOAD_SW_NUM_RBMASK                                 0x7Fu                         /**< Base mask for AoadSwNum */
#define  AOAD_SW_NUM_R(x)                                   (((x)&0x7Fu)<<0)              /**< Set AoadSwNum in register */
#define  GET_AOAD_SW_NUM_R(reg)                             (((reg)>>0)&0x7Fu)            /**< Get AoadSwNum from register */
#define  AOAD_SW_EN_RSHIFT                                  8                             /**< Shift for AoadSwEn */
#define  AOAD_SW_EN_RMASK                                   0x0100u                       /**< Mask for AoadSwEn */
#define  AOAD_SW_EN_RBMASK                                  0x1u                          /**< Base mask for AoadSwEn */
#define  AOAD_SW_EN_R(x)                                    (((x)&0x1u)<<8)               /**< Set AoadSwEn in register */
#define  GET_AOAD_SW_EN_R(reg)                              (((reg)>>8)&0x1u)             /**< Get AoadSwEn from register */
#define  AOAD_SW_PER_RSHIFT                                 9                             /**< Shift for AoadSwPer */
#define  AOAD_SW_PER_RMASK                                  0x0200u                       /**< Mask for AoadSwPer */
#define  AOAD_SW_PER_RBMASK                                 0x1u                          /**< Base mask for AoadSwPer */
#define  AOAD_SW_PER_R(x)                                   (((x)&0x1u)<<9)               /**< Set AoadSwPer in register */
#define  GET_AOAD_SW_PER_R(reg)                             (((reg)>>9)&0x1u)             /**< Get AoadSwPer from register */
/** @} */


/**
 * @name RegAoadGpioSel0
 * @{
 */
// RegAoadGpioSel0.r32
#define  REG_AOAD_GPIO_SEL0_RESET_VALUE                     0x00000000u                   /**< Reset value of RegAoadGpioSel0 */
#define  REG_AOAD_GPIO_SEL0_MASK                            0x07070707u                   /**< Mask for RegAoadGpioSel0 */

#define  AOAD_GPIO_OUT_SEL0_SHIFT                           0                             /**< Shift for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_MASK                            0x00000007u                   /**< Mask for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0(x)                              (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel0 in register */
#define  GET_AOAD_GPIO_OUT_SEL0(reg)                        (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel0 from register */
#define  AOAD_GPIO_OUT_SEL1_SHIFT                           8                             /**< Shift for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_MASK                            0x00000700u                   /**< Mask for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1(x)                              (((x)&0x7u)<<8)               /**< Set AoadGpioOutSel1 in register */
#define  GET_AOAD_GPIO_OUT_SEL1(reg)                        (((reg)>>8)&0x7u)             /**< Get AoadGpioOutSel1 from register */
#define  AOAD_GPIO_OUT_SEL2_SHIFT                           16                            /**< Shift for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_MASK                            0x00070000u                   /**< Mask for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2(x)                              (((x)&0x7u)<<16)              /**< Set AoadGpioOutSel2 in register */
#define  GET_AOAD_GPIO_OUT_SEL2(reg)                        (((reg)>>16)&0x7u)            /**< Get AoadGpioOutSel2 from register */
#define  AOAD_GPIO_OUT_SEL3_SHIFT                           24                            /**< Shift for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_MASK                            0x07000000u                   /**< Mask for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3(x)                              (((x)&0x7u)<<24)              /**< Set AoadGpioOutSel3 in register */
#define  GET_AOAD_GPIO_OUT_SEL3(reg)                        (((reg)>>24)&0x7u)            /**< Get AoadGpioOutSel3 from register */

// RegAoadGpioSel0.regs.AoadGpioOutSel0
#define  AOAD_GPIO_OUT_SEL0_GSHIFT                          0                             /**< Shift for group AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_GSIZE                           8                             /**< Size of group AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_GMASK                           0x000000FFu                   /**< Mask for group AoadGpioOutSel0 */

#define  AOAD_GPIO_OUT_SEL0_RSHIFT                          0                             /**< Shift for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel0 */
#define  AOAD_GPIO_OUT_SEL0_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel0 in register */
#define  GET_AOAD_GPIO_OUT_SEL0_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel0 from register */

// RegAoadGpioSel0.regs.AoadGpioOutSel1
#define  AOAD_GPIO_OUT_SEL1_GSHIFT                          8                             /**< Shift for group AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_GSIZE                           8                             /**< Size of group AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_GMASK                           0x0000FF00u                   /**< Mask for group AoadGpioOutSel1 */

#define  AOAD_GPIO_OUT_SEL1_RSHIFT                          0                             /**< Shift for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel1 */
#define  AOAD_GPIO_OUT_SEL1_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel1 in register */
#define  GET_AOAD_GPIO_OUT_SEL1_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel1 from register */

// RegAoadGpioSel0.regs.AoadGpioOutSel2
#define  AOAD_GPIO_OUT_SEL2_GSHIFT                          16                            /**< Shift for group AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_GSIZE                           8                             /**< Size of group AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_GMASK                           0x00FF0000u                   /**< Mask for group AoadGpioOutSel2 */

#define  AOAD_GPIO_OUT_SEL2_RSHIFT                          0                             /**< Shift for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel2 */
#define  AOAD_GPIO_OUT_SEL2_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel2 in register */
#define  GET_AOAD_GPIO_OUT_SEL2_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel2 from register */

// RegAoadGpioSel0.regs.AoadGpioOutSel3
#define  AOAD_GPIO_OUT_SEL3_GSHIFT                          24                            /**< Shift for group AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_GSIZE                           8                             /**< Size of group AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_GMASK                           0xFF000000u                   /**< Mask for group AoadGpioOutSel3 */

#define  AOAD_GPIO_OUT_SEL3_RSHIFT                          0                             /**< Shift for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel3 */
#define  AOAD_GPIO_OUT_SEL3_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel3 in register */
#define  GET_AOAD_GPIO_OUT_SEL3_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel3 from register */
/** @} */


/**
 * @name RegAoadGpioSel1
 * @{
 */
// RegAoadGpioSel1.r32
#define  REG_AOAD_GPIO_SEL1_RESET_VALUE                     0x00000000u                   /**< Reset value of RegAoadGpioSel1 */
#define  REG_AOAD_GPIO_SEL1_MASK                            0x07070707u                   /**< Mask for RegAoadGpioSel1 */

#define  AOAD_GPIO_OUT_SEL4_SHIFT                           0                             /**< Shift for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_MASK                            0x00000007u                   /**< Mask for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4(x)                              (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel4 in register */
#define  GET_AOAD_GPIO_OUT_SEL4(reg)                        (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel4 from register */
#define  AOAD_GPIO_OUT_SEL5_SHIFT                           8                             /**< Shift for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_MASK                            0x00000700u                   /**< Mask for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5(x)                              (((x)&0x7u)<<8)               /**< Set AoadGpioOutSel5 in register */
#define  GET_AOAD_GPIO_OUT_SEL5(reg)                        (((reg)>>8)&0x7u)             /**< Get AoadGpioOutSel5 from register */
#define  AOAD_GPIO_OUT_SEL6_SHIFT                           16                            /**< Shift for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_MASK                            0x00070000u                   /**< Mask for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6(x)                              (((x)&0x7u)<<16)              /**< Set AoadGpioOutSel6 in register */
#define  GET_AOAD_GPIO_OUT_SEL6(reg)                        (((reg)>>16)&0x7u)            /**< Get AoadGpioOutSel6 from register */
#define  AOAD_GPIO_OUT_SEL7_SHIFT                           24                            /**< Shift for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_MASK                            0x07000000u                   /**< Mask for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7(x)                              (((x)&0x7u)<<24)              /**< Set AoadGpioOutSel7 in register */
#define  GET_AOAD_GPIO_OUT_SEL7(reg)                        (((reg)>>24)&0x7u)            /**< Get AoadGpioOutSel7 from register */

// RegAoadGpioSel1.regs.AoadGpioOutSel4
#define  AOAD_GPIO_OUT_SEL4_GSHIFT                          0                             /**< Shift for group AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_GSIZE                           8                             /**< Size of group AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_GMASK                           0x000000FFu                   /**< Mask for group AoadGpioOutSel4 */

#define  AOAD_GPIO_OUT_SEL4_RSHIFT                          0                             /**< Shift for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel4 */
#define  AOAD_GPIO_OUT_SEL4_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel4 in register */
#define  GET_AOAD_GPIO_OUT_SEL4_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel4 from register */

// RegAoadGpioSel1.regs.AoadGpioOutSel5
#define  AOAD_GPIO_OUT_SEL5_GSHIFT                          8                             /**< Shift for group AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_GSIZE                           8                             /**< Size of group AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_GMASK                           0x0000FF00u                   /**< Mask for group AoadGpioOutSel5 */

#define  AOAD_GPIO_OUT_SEL5_RSHIFT                          0                             /**< Shift for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel5 */
#define  AOAD_GPIO_OUT_SEL5_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel5 in register */
#define  GET_AOAD_GPIO_OUT_SEL5_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel5 from register */

// RegAoadGpioSel1.regs.AoadGpioOutSel6
#define  AOAD_GPIO_OUT_SEL6_GSHIFT                          16                            /**< Shift for group AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_GSIZE                           8                             /**< Size of group AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_GMASK                           0x00FF0000u                   /**< Mask for group AoadGpioOutSel6 */

#define  AOAD_GPIO_OUT_SEL6_RSHIFT                          0                             /**< Shift for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel6 */
#define  AOAD_GPIO_OUT_SEL6_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel6 in register */
#define  GET_AOAD_GPIO_OUT_SEL6_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel6 from register */

// RegAoadGpioSel1.regs.AoadGpioOutSel7
#define  AOAD_GPIO_OUT_SEL7_GSHIFT                          24                            /**< Shift for group AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_GSIZE                           8                             /**< Size of group AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_GMASK                           0xFF000000u                   /**< Mask for group AoadGpioOutSel7 */

#define  AOAD_GPIO_OUT_SEL7_RSHIFT                          0                             /**< Shift for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel7 */
#define  AOAD_GPIO_OUT_SEL7_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel7 in register */
#define  GET_AOAD_GPIO_OUT_SEL7_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel7 from register */
/** @} */


/**
 * @name RegAoadGpioSel2
 * @{
 */
// RegAoadGpioSel2.r32
#define  REG_AOAD_GPIO_SEL2_RESET_VALUE                     0x00000000u                   /**< Reset value of RegAoadGpioSel2 */
#define  REG_AOAD_GPIO_SEL2_MASK                            0x07070707u                   /**< Mask for RegAoadGpioSel2 */

#define  AOAD_GPIO_OUT_SEL8_SHIFT                           0                             /**< Shift for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_MASK                            0x00000007u                   /**< Mask for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8(x)                              (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel8 in register */
#define  GET_AOAD_GPIO_OUT_SEL8(reg)                        (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel8 from register */
#define  AOAD_GPIO_OUT_SEL9_SHIFT                           8                             /**< Shift for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_MASK                            0x00000700u                   /**< Mask for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_BMASK                           0x7u                          /**< Base mask for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9(x)                              (((x)&0x7u)<<8)               /**< Set AoadGpioOutSel9 in register */
#define  GET_AOAD_GPIO_OUT_SEL9(reg)                        (((reg)>>8)&0x7u)             /**< Get AoadGpioOutSel9 from register */
#define  AOAD_GPIO_OUT_SEL10_SHIFT                          16                            /**< Shift for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_MASK                           0x00070000u                   /**< Mask for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_BMASK                          0x7u                          /**< Base mask for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10(x)                             (((x)&0x7u)<<16)              /**< Set AoadGpioOutSel10 in register */
#define  GET_AOAD_GPIO_OUT_SEL10(reg)                       (((reg)>>16)&0x7u)            /**< Get AoadGpioOutSel10 from register */
#define  AOAD_GPIO_OUT_SEL11_SHIFT                          24                            /**< Shift for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_MASK                           0x07000000u                   /**< Mask for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_BMASK                          0x7u                          /**< Base mask for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11(x)                             (((x)&0x7u)<<24)              /**< Set AoadGpioOutSel11 in register */
#define  GET_AOAD_GPIO_OUT_SEL11(reg)                       (((reg)>>24)&0x7u)            /**< Get AoadGpioOutSel11 from register */

// RegAoadGpioSel2.regs.AoadGpioOutSel8
#define  AOAD_GPIO_OUT_SEL8_GSHIFT                          0                             /**< Shift for group AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_GSIZE                           8                             /**< Size of group AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_GMASK                           0x000000FFu                   /**< Mask for group AoadGpioOutSel8 */

#define  AOAD_GPIO_OUT_SEL8_RSHIFT                          0                             /**< Shift for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel8 */
#define  AOAD_GPIO_OUT_SEL8_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel8 in register */
#define  GET_AOAD_GPIO_OUT_SEL8_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel8 from register */

// RegAoadGpioSel2.regs.AoadGpioOutSel9
#define  AOAD_GPIO_OUT_SEL9_GSHIFT                          8                             /**< Shift for group AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_GSIZE                           8                             /**< Size of group AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_GMASK                           0x0000FF00u                   /**< Mask for group AoadGpioOutSel9 */

#define  AOAD_GPIO_OUT_SEL9_RSHIFT                          0                             /**< Shift for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_RMASK                           0x00000007u                   /**< Mask for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_RBMASK                          0x7u                          /**< Base mask for AoadGpioOutSel9 */
#define  AOAD_GPIO_OUT_SEL9_R(x)                            (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel9 in register */
#define  GET_AOAD_GPIO_OUT_SEL9_R(reg)                      (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel9 from register */

// RegAoadGpioSel2.regs.AoadGpioOutSel10
#define  AOAD_GPIO_OUT_SEL10_GSHIFT                         16                            /**< Shift for group AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_GSIZE                          8                             /**< Size of group AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_GMASK                          0x00FF0000u                   /**< Mask for group AoadGpioOutSel10 */

#define  AOAD_GPIO_OUT_SEL10_RSHIFT                         0                             /**< Shift for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_RMASK                          0x00000007u                   /**< Mask for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_RBMASK                         0x7u                          /**< Base mask for AoadGpioOutSel10 */
#define  AOAD_GPIO_OUT_SEL10_R(x)                           (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel10 in register */
#define  GET_AOAD_GPIO_OUT_SEL10_R(reg)                     (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel10 from register */

// RegAoadGpioSel2.regs.AoadGpioOutSel11
#define  AOAD_GPIO_OUT_SEL11_GSHIFT                         24                            /**< Shift for group AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_GSIZE                          8                             /**< Size of group AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_GMASK                          0xFF000000u                   /**< Mask for group AoadGpioOutSel11 */

#define  AOAD_GPIO_OUT_SEL11_RSHIFT                         0                             /**< Shift for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_RMASK                          0x00000007u                   /**< Mask for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_RBMASK                         0x7u                          /**< Base mask for AoadGpioOutSel11 */
#define  AOAD_GPIO_OUT_SEL11_R(x)                           (((x)&0x7u)<<0)               /**< Set AoadGpioOutSel11 in register */
#define  GET_AOAD_GPIO_OUT_SEL11_R(reg)                     (((reg)>>0)&0x7u)             /**< Get AoadGpioOutSel11 from register */
/** @} */


/**
 * @name RegAoadLut0
 * @{
 */
// RegAoadLut0.r32
#define  REG_AOAD_LUT0_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut0 */
#define  REG_AOAD_LUT0_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut0 */

#define  AOAD_LUT0_SHIFT                                    0                             /**< Shift for AoadLut0 */
#define  AOAD_LUT0_MASK                                     0x000000FFu                   /**< Mask for AoadLut0 */
#define  AOAD_LUT0_BMASK                                    0xFFu                         /**< Base mask for AoadLut0 */
#define  AOAD_LUT0(x)                                       (((x)&0xFFu)<<0)              /**< Set AoadLut0 in register */
#define  GET_AOAD_LUT0(reg)                                 (((reg)>>0)&0xFFu)            /**< Get AoadLut0 from register */
#define  AOAD_LUT1_SHIFT                                    8                             /**< Shift for AoadLut1 */
#define  AOAD_LUT1_MASK                                     0x0000FF00u                   /**< Mask for AoadLut1 */
#define  AOAD_LUT1_BMASK                                    0xFFu                         /**< Base mask for AoadLut1 */
#define  AOAD_LUT1(x)                                       (((x)&0xFFu)<<8)              /**< Set AoadLut1 in register */
#define  GET_AOAD_LUT1(reg)                                 (((reg)>>8)&0xFFu)            /**< Get AoadLut1 from register */
#define  AOAD_LUT2_SHIFT                                    16                            /**< Shift for AoadLut2 */
#define  AOAD_LUT2_MASK                                     0x00FF0000u                   /**< Mask for AoadLut2 */
#define  AOAD_LUT2_BMASK                                    0xFFu                         /**< Base mask for AoadLut2 */
#define  AOAD_LUT2(x)                                       (((x)&0xFFu)<<16)             /**< Set AoadLut2 in register */
#define  GET_AOAD_LUT2(reg)                                 (((reg)>>16)&0xFFu)           /**< Get AoadLut2 from register */
#define  AOAD_LUT3_SHIFT                                    24                            /**< Shift for AoadLut3 */
#define  AOAD_LUT3_MASK                                     0xFF000000u                   /**< Mask for AoadLut3 */
#define  AOAD_LUT3_BMASK                                    0xFFu                         /**< Base mask for AoadLut3 */
#define  AOAD_LUT3(x)                                       (((x)&0xFFu)<<24)             /**< Set AoadLut3 in register */
#define  GET_AOAD_LUT3(reg)                                 (((reg)>>24)&0xFFu)           /**< Get AoadLut3 from register */

// RegAoadLut0.regs.AoadLut0
#define  AOAD_LUT0_GSHIFT                                   0                             /**< Shift for group AoadLut0 */
#define  AOAD_LUT0_GSIZE                                    8                             /**< Size of group AoadLut0 */
#define  AOAD_LUT0_GMASK                                    0x000000FFu                   /**< Mask for group AoadLut0 */

#define  AOAD_LUT0_RSHIFT                                   0                             /**< Shift for AoadLut0 */
#define  AOAD_LUT0_RMASK                                    0x000000FFu                   /**< Mask for AoadLut0 */
#define  AOAD_LUT0_RBMASK                                   0xFFu                         /**< Base mask for AoadLut0 */
#define  AOAD_LUT0_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut0 in register */
#define  GET_AOAD_LUT0_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut0 from register */

// RegAoadLut0.regs.AoadLut1
#define  AOAD_LUT1_GSHIFT                                   8                             /**< Shift for group AoadLut1 */
#define  AOAD_LUT1_GSIZE                                    8                             /**< Size of group AoadLut1 */
#define  AOAD_LUT1_GMASK                                    0x0000FF00u                   /**< Mask for group AoadLut1 */

#define  AOAD_LUT1_RSHIFT                                   0                             /**< Shift for AoadLut1 */
#define  AOAD_LUT1_RMASK                                    0x000000FFu                   /**< Mask for AoadLut1 */
#define  AOAD_LUT1_RBMASK                                   0xFFu                         /**< Base mask for AoadLut1 */
#define  AOAD_LUT1_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut1 in register */
#define  GET_AOAD_LUT1_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut1 from register */

// RegAoadLut0.regs.AoadLut2
#define  AOAD_LUT2_GSHIFT                                   16                            /**< Shift for group AoadLut2 */
#define  AOAD_LUT2_GSIZE                                    8                             /**< Size of group AoadLut2 */
#define  AOAD_LUT2_GMASK                                    0x00FF0000u                   /**< Mask for group AoadLut2 */

#define  AOAD_LUT2_RSHIFT                                   0                             /**< Shift for AoadLut2 */
#define  AOAD_LUT2_RMASK                                    0x000000FFu                   /**< Mask for AoadLut2 */
#define  AOAD_LUT2_RBMASK                                   0xFFu                         /**< Base mask for AoadLut2 */
#define  AOAD_LUT2_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut2 in register */
#define  GET_AOAD_LUT2_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut2 from register */

// RegAoadLut0.regs.AoadLut3
#define  AOAD_LUT3_GSHIFT                                   24                            /**< Shift for group AoadLut3 */
#define  AOAD_LUT3_GSIZE                                    8                             /**< Size of group AoadLut3 */
#define  AOAD_LUT3_GMASK                                    0xFF000000u                   /**< Mask for group AoadLut3 */

#define  AOAD_LUT3_RSHIFT                                   0                             /**< Shift for AoadLut3 */
#define  AOAD_LUT3_RMASK                                    0x000000FFu                   /**< Mask for AoadLut3 */
#define  AOAD_LUT3_RBMASK                                   0xFFu                         /**< Base mask for AoadLut3 */
#define  AOAD_LUT3_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut3 in register */
#define  GET_AOAD_LUT3_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut3 from register */
/** @} */


/**
 * @name RegAoadLut1
 * @{
 */
// RegAoadLut1.r32
#define  REG_AOAD_LUT1_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut1 */
#define  REG_AOAD_LUT1_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut1 */

#define  AOAD_LUT4_SHIFT                                    0                             /**< Shift for AoadLut4 */
#define  AOAD_LUT4_MASK                                     0x000000FFu                   /**< Mask for AoadLut4 */
#define  AOAD_LUT4_BMASK                                    0xFFu                         /**< Base mask for AoadLut4 */
#define  AOAD_LUT4(x)                                       (((x)&0xFFu)<<0)              /**< Set AoadLut4 in register */
#define  GET_AOAD_LUT4(reg)                                 (((reg)>>0)&0xFFu)            /**< Get AoadLut4 from register */
#define  AOAD_LUT5_SHIFT                                    8                             /**< Shift for AoadLut5 */
#define  AOAD_LUT5_MASK                                     0x0000FF00u                   /**< Mask for AoadLut5 */
#define  AOAD_LUT5_BMASK                                    0xFFu                         /**< Base mask for AoadLut5 */
#define  AOAD_LUT5(x)                                       (((x)&0xFFu)<<8)              /**< Set AoadLut5 in register */
#define  GET_AOAD_LUT5(reg)                                 (((reg)>>8)&0xFFu)            /**< Get AoadLut5 from register */
#define  AOAD_LUT6_SHIFT                                    16                            /**< Shift for AoadLut6 */
#define  AOAD_LUT6_MASK                                     0x00FF0000u                   /**< Mask for AoadLut6 */
#define  AOAD_LUT6_BMASK                                    0xFFu                         /**< Base mask for AoadLut6 */
#define  AOAD_LUT6(x)                                       (((x)&0xFFu)<<16)             /**< Set AoadLut6 in register */
#define  GET_AOAD_LUT6(reg)                                 (((reg)>>16)&0xFFu)           /**< Get AoadLut6 from register */
#define  AOAD_LUT7_SHIFT                                    24                            /**< Shift for AoadLut7 */
#define  AOAD_LUT7_MASK                                     0xFF000000u                   /**< Mask for AoadLut7 */
#define  AOAD_LUT7_BMASK                                    0xFFu                         /**< Base mask for AoadLut7 */
#define  AOAD_LUT7(x)                                       (((x)&0xFFu)<<24)             /**< Set AoadLut7 in register */
#define  GET_AOAD_LUT7(reg)                                 (((reg)>>24)&0xFFu)           /**< Get AoadLut7 from register */

// RegAoadLut1.regs.AoadLut4
#define  AOAD_LUT4_GSHIFT                                   0                             /**< Shift for group AoadLut4 */
#define  AOAD_LUT4_GSIZE                                    8                             /**< Size of group AoadLut4 */
#define  AOAD_LUT4_GMASK                                    0x000000FFu                   /**< Mask for group AoadLut4 */

#define  AOAD_LUT4_RSHIFT                                   0                             /**< Shift for AoadLut4 */
#define  AOAD_LUT4_RMASK                                    0x000000FFu                   /**< Mask for AoadLut4 */
#define  AOAD_LUT4_RBMASK                                   0xFFu                         /**< Base mask for AoadLut4 */
#define  AOAD_LUT4_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut4 in register */
#define  GET_AOAD_LUT4_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut4 from register */

// RegAoadLut1.regs.AoadLut5
#define  AOAD_LUT5_GSHIFT                                   8                             /**< Shift for group AoadLut5 */
#define  AOAD_LUT5_GSIZE                                    8                             /**< Size of group AoadLut5 */
#define  AOAD_LUT5_GMASK                                    0x0000FF00u                   /**< Mask for group AoadLut5 */

#define  AOAD_LUT5_RSHIFT                                   0                             /**< Shift for AoadLut5 */
#define  AOAD_LUT5_RMASK                                    0x000000FFu                   /**< Mask for AoadLut5 */
#define  AOAD_LUT5_RBMASK                                   0xFFu                         /**< Base mask for AoadLut5 */
#define  AOAD_LUT5_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut5 in register */
#define  GET_AOAD_LUT5_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut5 from register */

// RegAoadLut1.regs.AoadLut6
#define  AOAD_LUT6_GSHIFT                                   16                            /**< Shift for group AoadLut6 */
#define  AOAD_LUT6_GSIZE                                    8                             /**< Size of group AoadLut6 */
#define  AOAD_LUT6_GMASK                                    0x00FF0000u                   /**< Mask for group AoadLut6 */

#define  AOAD_LUT6_RSHIFT                                   0                             /**< Shift for AoadLut6 */
#define  AOAD_LUT6_RMASK                                    0x000000FFu                   /**< Mask for AoadLut6 */
#define  AOAD_LUT6_RBMASK                                   0xFFu                         /**< Base mask for AoadLut6 */
#define  AOAD_LUT6_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut6 in register */
#define  GET_AOAD_LUT6_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut6 from register */

// RegAoadLut1.regs.AoadLut7
#define  AOAD_LUT7_GSHIFT                                   24                            /**< Shift for group AoadLut7 */
#define  AOAD_LUT7_GSIZE                                    8                             /**< Size of group AoadLut7 */
#define  AOAD_LUT7_GMASK                                    0xFF000000u                   /**< Mask for group AoadLut7 */

#define  AOAD_LUT7_RSHIFT                                   0                             /**< Shift for AoadLut7 */
#define  AOAD_LUT7_RMASK                                    0x000000FFu                   /**< Mask for AoadLut7 */
#define  AOAD_LUT7_RBMASK                                   0xFFu                         /**< Base mask for AoadLut7 */
#define  AOAD_LUT7_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut7 in register */
#define  GET_AOAD_LUT7_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut7 from register */
/** @} */


/**
 * @name RegAoadLut2
 * @{
 */
// RegAoadLut2.r32
#define  REG_AOAD_LUT2_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut2 */
#define  REG_AOAD_LUT2_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut2 */

#define  AOAD_LUT8_SHIFT                                    0                             /**< Shift for AoadLut8 */
#define  AOAD_LUT8_MASK                                     0x000000FFu                   /**< Mask for AoadLut8 */
#define  AOAD_LUT8_BMASK                                    0xFFu                         /**< Base mask for AoadLut8 */
#define  AOAD_LUT8(x)                                       (((x)&0xFFu)<<0)              /**< Set AoadLut8 in register */
#define  GET_AOAD_LUT8(reg)                                 (((reg)>>0)&0xFFu)            /**< Get AoadLut8 from register */
#define  AOAD_LUT9_SHIFT                                    8                             /**< Shift for AoadLut9 */
#define  AOAD_LUT9_MASK                                     0x0000FF00u                   /**< Mask for AoadLut9 */
#define  AOAD_LUT9_BMASK                                    0xFFu                         /**< Base mask for AoadLut9 */
#define  AOAD_LUT9(x)                                       (((x)&0xFFu)<<8)              /**< Set AoadLut9 in register */
#define  GET_AOAD_LUT9(reg)                                 (((reg)>>8)&0xFFu)            /**< Get AoadLut9 from register */
#define  AOAD_LUT10_SHIFT                                   16                            /**< Shift for AoadLut10 */
#define  AOAD_LUT10_MASK                                    0x00FF0000u                   /**< Mask for AoadLut10 */
#define  AOAD_LUT10_BMASK                                   0xFFu                         /**< Base mask for AoadLut10 */
#define  AOAD_LUT10(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut10 in register */
#define  GET_AOAD_LUT10(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut10 from register */
#define  AOAD_LUT11_SHIFT                                   24                            /**< Shift for AoadLut11 */
#define  AOAD_LUT11_MASK                                    0xFF000000u                   /**< Mask for AoadLut11 */
#define  AOAD_LUT11_BMASK                                   0xFFu                         /**< Base mask for AoadLut11 */
#define  AOAD_LUT11(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut11 in register */
#define  GET_AOAD_LUT11(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut11 from register */

// RegAoadLut2.regs.AoadLut8
#define  AOAD_LUT8_GSHIFT                                   0                             /**< Shift for group AoadLut8 */
#define  AOAD_LUT8_GSIZE                                    8                             /**< Size of group AoadLut8 */
#define  AOAD_LUT8_GMASK                                    0x000000FFu                   /**< Mask for group AoadLut8 */

#define  AOAD_LUT8_RSHIFT                                   0                             /**< Shift for AoadLut8 */
#define  AOAD_LUT8_RMASK                                    0x000000FFu                   /**< Mask for AoadLut8 */
#define  AOAD_LUT8_RBMASK                                   0xFFu                         /**< Base mask for AoadLut8 */
#define  AOAD_LUT8_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut8 in register */
#define  GET_AOAD_LUT8_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut8 from register */

// RegAoadLut2.regs.AoadLut9
#define  AOAD_LUT9_GSHIFT                                   8                             /**< Shift for group AoadLut9 */
#define  AOAD_LUT9_GSIZE                                    8                             /**< Size of group AoadLut9 */
#define  AOAD_LUT9_GMASK                                    0x0000FF00u                   /**< Mask for group AoadLut9 */

#define  AOAD_LUT9_RSHIFT                                   0                             /**< Shift for AoadLut9 */
#define  AOAD_LUT9_RMASK                                    0x000000FFu                   /**< Mask for AoadLut9 */
#define  AOAD_LUT9_RBMASK                                   0xFFu                         /**< Base mask for AoadLut9 */
#define  AOAD_LUT9_R(x)                                     (((x)&0xFFu)<<0)              /**< Set AoadLut9 in register */
#define  GET_AOAD_LUT9_R(reg)                               (((reg)>>0)&0xFFu)            /**< Get AoadLut9 from register */

// RegAoadLut2.regs.AoadLut10
#define  AOAD_LUT10_GSHIFT                                  16                            /**< Shift for group AoadLut10 */
#define  AOAD_LUT10_GSIZE                                   8                             /**< Size of group AoadLut10 */
#define  AOAD_LUT10_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut10 */

#define  AOAD_LUT10_RSHIFT                                  0                             /**< Shift for AoadLut10 */
#define  AOAD_LUT10_RMASK                                   0x000000FFu                   /**< Mask for AoadLut10 */
#define  AOAD_LUT10_RBMASK                                  0xFFu                         /**< Base mask for AoadLut10 */
#define  AOAD_LUT10_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut10 in register */
#define  GET_AOAD_LUT10_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut10 from register */

// RegAoadLut2.regs.AoadLut11
#define  AOAD_LUT11_GSHIFT                                  24                            /**< Shift for group AoadLut11 */
#define  AOAD_LUT11_GSIZE                                   8                             /**< Size of group AoadLut11 */
#define  AOAD_LUT11_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut11 */

#define  AOAD_LUT11_RSHIFT                                  0                             /**< Shift for AoadLut11 */
#define  AOAD_LUT11_RMASK                                   0x000000FFu                   /**< Mask for AoadLut11 */
#define  AOAD_LUT11_RBMASK                                  0xFFu                         /**< Base mask for AoadLut11 */
#define  AOAD_LUT11_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut11 in register */
#define  GET_AOAD_LUT11_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut11 from register */
/** @} */


/**
 * @name RegAoadLut3
 * @{
 */
// RegAoadLut3.r32
#define  REG_AOAD_LUT3_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut3 */
#define  REG_AOAD_LUT3_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut3 */

#define  AOAD_LUT12_SHIFT                                   0                             /**< Shift for AoadLut12 */
#define  AOAD_LUT12_MASK                                    0x000000FFu                   /**< Mask for AoadLut12 */
#define  AOAD_LUT12_BMASK                                   0xFFu                         /**< Base mask for AoadLut12 */
#define  AOAD_LUT12(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut12 in register */
#define  GET_AOAD_LUT12(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut12 from register */
#define  AOAD_LUT13_SHIFT                                   8                             /**< Shift for AoadLut13 */
#define  AOAD_LUT13_MASK                                    0x0000FF00u                   /**< Mask for AoadLut13 */
#define  AOAD_LUT13_BMASK                                   0xFFu                         /**< Base mask for AoadLut13 */
#define  AOAD_LUT13(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut13 in register */
#define  GET_AOAD_LUT13(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut13 from register */
#define  AOAD_LUT14_SHIFT                                   16                            /**< Shift for AoadLut14 */
#define  AOAD_LUT14_MASK                                    0x00FF0000u                   /**< Mask for AoadLut14 */
#define  AOAD_LUT14_BMASK                                   0xFFu                         /**< Base mask for AoadLut14 */
#define  AOAD_LUT14(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut14 in register */
#define  GET_AOAD_LUT14(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut14 from register */
#define  AOAD_LUT15_SHIFT                                   24                            /**< Shift for AoadLut15 */
#define  AOAD_LUT15_MASK                                    0xFF000000u                   /**< Mask for AoadLut15 */
#define  AOAD_LUT15_BMASK                                   0xFFu                         /**< Base mask for AoadLut15 */
#define  AOAD_LUT15(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut15 in register */
#define  GET_AOAD_LUT15(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut15 from register */

// RegAoadLut3.regs.AoadLut12
#define  AOAD_LUT12_GSHIFT                                  0                             /**< Shift for group AoadLut12 */
#define  AOAD_LUT12_GSIZE                                   8                             /**< Size of group AoadLut12 */
#define  AOAD_LUT12_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut12 */

#define  AOAD_LUT12_RSHIFT                                  0                             /**< Shift for AoadLut12 */
#define  AOAD_LUT12_RMASK                                   0x000000FFu                   /**< Mask for AoadLut12 */
#define  AOAD_LUT12_RBMASK                                  0xFFu                         /**< Base mask for AoadLut12 */
#define  AOAD_LUT12_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut12 in register */
#define  GET_AOAD_LUT12_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut12 from register */

// RegAoadLut3.regs.AoadLut13
#define  AOAD_LUT13_GSHIFT                                  8                             /**< Shift for group AoadLut13 */
#define  AOAD_LUT13_GSIZE                                   8                             /**< Size of group AoadLut13 */
#define  AOAD_LUT13_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut13 */

#define  AOAD_LUT13_RSHIFT                                  0                             /**< Shift for AoadLut13 */
#define  AOAD_LUT13_RMASK                                   0x000000FFu                   /**< Mask for AoadLut13 */
#define  AOAD_LUT13_RBMASK                                  0xFFu                         /**< Base mask for AoadLut13 */
#define  AOAD_LUT13_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut13 in register */
#define  GET_AOAD_LUT13_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut13 from register */

// RegAoadLut3.regs.AoadLut14
#define  AOAD_LUT14_GSHIFT                                  16                            /**< Shift for group AoadLut14 */
#define  AOAD_LUT14_GSIZE                                   8                             /**< Size of group AoadLut14 */
#define  AOAD_LUT14_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut14 */

#define  AOAD_LUT14_RSHIFT                                  0                             /**< Shift for AoadLut14 */
#define  AOAD_LUT14_RMASK                                   0x000000FFu                   /**< Mask for AoadLut14 */
#define  AOAD_LUT14_RBMASK                                  0xFFu                         /**< Base mask for AoadLut14 */
#define  AOAD_LUT14_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut14 in register */
#define  GET_AOAD_LUT14_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut14 from register */

// RegAoadLut3.regs.AoadLut15
#define  AOAD_LUT15_GSHIFT                                  24                            /**< Shift for group AoadLut15 */
#define  AOAD_LUT15_GSIZE                                   8                             /**< Size of group AoadLut15 */
#define  AOAD_LUT15_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut15 */

#define  AOAD_LUT15_RSHIFT                                  0                             /**< Shift for AoadLut15 */
#define  AOAD_LUT15_RMASK                                   0x000000FFu                   /**< Mask for AoadLut15 */
#define  AOAD_LUT15_RBMASK                                  0xFFu                         /**< Base mask for AoadLut15 */
#define  AOAD_LUT15_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut15 in register */
#define  GET_AOAD_LUT15_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut15 from register */
/** @} */


/**
 * @name RegAoadLut4
 * @{
 */
// RegAoadLut4.r32
#define  REG_AOAD_LUT4_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut4 */
#define  REG_AOAD_LUT4_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut4 */

#define  AOAD_LUT16_SHIFT                                   0                             /**< Shift for AoadLut16 */
#define  AOAD_LUT16_MASK                                    0x000000FFu                   /**< Mask for AoadLut16 */
#define  AOAD_LUT16_BMASK                                   0xFFu                         /**< Base mask for AoadLut16 */
#define  AOAD_LUT16(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut16 in register */
#define  GET_AOAD_LUT16(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut16 from register */
#define  AOAD_LUT17_SHIFT                                   8                             /**< Shift for AoadLut17 */
#define  AOAD_LUT17_MASK                                    0x0000FF00u                   /**< Mask for AoadLut17 */
#define  AOAD_LUT17_BMASK                                   0xFFu                         /**< Base mask for AoadLut17 */
#define  AOAD_LUT17(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut17 in register */
#define  GET_AOAD_LUT17(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut17 from register */
#define  AOAD_LUT18_SHIFT                                   16                            /**< Shift for AoadLut18 */
#define  AOAD_LUT18_MASK                                    0x00FF0000u                   /**< Mask for AoadLut18 */
#define  AOAD_LUT18_BMASK                                   0xFFu                         /**< Base mask for AoadLut18 */
#define  AOAD_LUT18(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut18 in register */
#define  GET_AOAD_LUT18(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut18 from register */
#define  AOAD_LUT19_SHIFT                                   24                            /**< Shift for AoadLut19 */
#define  AOAD_LUT19_MASK                                    0xFF000000u                   /**< Mask for AoadLut19 */
#define  AOAD_LUT19_BMASK                                   0xFFu                         /**< Base mask for AoadLut19 */
#define  AOAD_LUT19(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut19 in register */
#define  GET_AOAD_LUT19(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut19 from register */

// RegAoadLut4.regs.AoadLut16
#define  AOAD_LUT16_GSHIFT                                  0                             /**< Shift for group AoadLut16 */
#define  AOAD_LUT16_GSIZE                                   8                             /**< Size of group AoadLut16 */
#define  AOAD_LUT16_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut16 */

#define  AOAD_LUT16_RSHIFT                                  0                             /**< Shift for AoadLut16 */
#define  AOAD_LUT16_RMASK                                   0x000000FFu                   /**< Mask for AoadLut16 */
#define  AOAD_LUT16_RBMASK                                  0xFFu                         /**< Base mask for AoadLut16 */
#define  AOAD_LUT16_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut16 in register */
#define  GET_AOAD_LUT16_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut16 from register */

// RegAoadLut4.regs.AoadLut17
#define  AOAD_LUT17_GSHIFT                                  8                             /**< Shift for group AoadLut17 */
#define  AOAD_LUT17_GSIZE                                   8                             /**< Size of group AoadLut17 */
#define  AOAD_LUT17_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut17 */

#define  AOAD_LUT17_RSHIFT                                  0                             /**< Shift for AoadLut17 */
#define  AOAD_LUT17_RMASK                                   0x000000FFu                   /**< Mask for AoadLut17 */
#define  AOAD_LUT17_RBMASK                                  0xFFu                         /**< Base mask for AoadLut17 */
#define  AOAD_LUT17_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut17 in register */
#define  GET_AOAD_LUT17_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut17 from register */

// RegAoadLut4.regs.AoadLut18
#define  AOAD_LUT18_GSHIFT                                  16                            /**< Shift for group AoadLut18 */
#define  AOAD_LUT18_GSIZE                                   8                             /**< Size of group AoadLut18 */
#define  AOAD_LUT18_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut18 */

#define  AOAD_LUT18_RSHIFT                                  0                             /**< Shift for AoadLut18 */
#define  AOAD_LUT18_RMASK                                   0x000000FFu                   /**< Mask for AoadLut18 */
#define  AOAD_LUT18_RBMASK                                  0xFFu                         /**< Base mask for AoadLut18 */
#define  AOAD_LUT18_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut18 in register */
#define  GET_AOAD_LUT18_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut18 from register */

// RegAoadLut4.regs.AoadLut19
#define  AOAD_LUT19_GSHIFT                                  24                            /**< Shift for group AoadLut19 */
#define  AOAD_LUT19_GSIZE                                   8                             /**< Size of group AoadLut19 */
#define  AOAD_LUT19_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut19 */

#define  AOAD_LUT19_RSHIFT                                  0                             /**< Shift for AoadLut19 */
#define  AOAD_LUT19_RMASK                                   0x000000FFu                   /**< Mask for AoadLut19 */
#define  AOAD_LUT19_RBMASK                                  0xFFu                         /**< Base mask for AoadLut19 */
#define  AOAD_LUT19_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut19 in register */
#define  GET_AOAD_LUT19_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut19 from register */
/** @} */


/**
 * @name RegAoadLut5
 * @{
 */
// RegAoadLut5.r32
#define  REG_AOAD_LUT5_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut5 */
#define  REG_AOAD_LUT5_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut5 */

#define  AOAD_LUT20_SHIFT                                   0                             /**< Shift for AoadLut20 */
#define  AOAD_LUT20_MASK                                    0x000000FFu                   /**< Mask for AoadLut20 */
#define  AOAD_LUT20_BMASK                                   0xFFu                         /**< Base mask for AoadLut20 */
#define  AOAD_LUT20(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut20 in register */
#define  GET_AOAD_LUT20(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut20 from register */
#define  AOAD_LUT21_SHIFT                                   8                             /**< Shift for AoadLut21 */
#define  AOAD_LUT21_MASK                                    0x0000FF00u                   /**< Mask for AoadLut21 */
#define  AOAD_LUT21_BMASK                                   0xFFu                         /**< Base mask for AoadLut21 */
#define  AOAD_LUT21(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut21 in register */
#define  GET_AOAD_LUT21(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut21 from register */
#define  AOAD_LUT22_SHIFT                                   16                            /**< Shift for AoadLut22 */
#define  AOAD_LUT22_MASK                                    0x00FF0000u                   /**< Mask for AoadLut22 */
#define  AOAD_LUT22_BMASK                                   0xFFu                         /**< Base mask for AoadLut22 */
#define  AOAD_LUT22(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut22 in register */
#define  GET_AOAD_LUT22(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut22 from register */
#define  AOAD_LUT23_SHIFT                                   24                            /**< Shift for AoadLut23 */
#define  AOAD_LUT23_MASK                                    0xFF000000u                   /**< Mask for AoadLut23 */
#define  AOAD_LUT23_BMASK                                   0xFFu                         /**< Base mask for AoadLut23 */
#define  AOAD_LUT23(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut23 in register */
#define  GET_AOAD_LUT23(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut23 from register */

// RegAoadLut5.regs.AoadLut20
#define  AOAD_LUT20_GSHIFT                                  0                             /**< Shift for group AoadLut20 */
#define  AOAD_LUT20_GSIZE                                   8                             /**< Size of group AoadLut20 */
#define  AOAD_LUT20_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut20 */

#define  AOAD_LUT20_RSHIFT                                  0                             /**< Shift for AoadLut20 */
#define  AOAD_LUT20_RMASK                                   0x000000FFu                   /**< Mask for AoadLut20 */
#define  AOAD_LUT20_RBMASK                                  0xFFu                         /**< Base mask for AoadLut20 */
#define  AOAD_LUT20_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut20 in register */
#define  GET_AOAD_LUT20_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut20 from register */

// RegAoadLut5.regs.AoadLut21
#define  AOAD_LUT21_GSHIFT                                  8                             /**< Shift for group AoadLut21 */
#define  AOAD_LUT21_GSIZE                                   8                             /**< Size of group AoadLut21 */
#define  AOAD_LUT21_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut21 */

#define  AOAD_LUT21_RSHIFT                                  0                             /**< Shift for AoadLut21 */
#define  AOAD_LUT21_RMASK                                   0x000000FFu                   /**< Mask for AoadLut21 */
#define  AOAD_LUT21_RBMASK                                  0xFFu                         /**< Base mask for AoadLut21 */
#define  AOAD_LUT21_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut21 in register */
#define  GET_AOAD_LUT21_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut21 from register */

// RegAoadLut5.regs.AoadLut22
#define  AOAD_LUT22_GSHIFT                                  16                            /**< Shift for group AoadLut22 */
#define  AOAD_LUT22_GSIZE                                   8                             /**< Size of group AoadLut22 */
#define  AOAD_LUT22_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut22 */

#define  AOAD_LUT22_RSHIFT                                  0                             /**< Shift for AoadLut22 */
#define  AOAD_LUT22_RMASK                                   0x000000FFu                   /**< Mask for AoadLut22 */
#define  AOAD_LUT22_RBMASK                                  0xFFu                         /**< Base mask for AoadLut22 */
#define  AOAD_LUT22_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut22 in register */
#define  GET_AOAD_LUT22_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut22 from register */

// RegAoadLut5.regs.AoadLut23
#define  AOAD_LUT23_GSHIFT                                  24                            /**< Shift for group AoadLut23 */
#define  AOAD_LUT23_GSIZE                                   8                             /**< Size of group AoadLut23 */
#define  AOAD_LUT23_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut23 */

#define  AOAD_LUT23_RSHIFT                                  0                             /**< Shift for AoadLut23 */
#define  AOAD_LUT23_RMASK                                   0x000000FFu                   /**< Mask for AoadLut23 */
#define  AOAD_LUT23_RBMASK                                  0xFFu                         /**< Base mask for AoadLut23 */
#define  AOAD_LUT23_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut23 in register */
#define  GET_AOAD_LUT23_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut23 from register */
/** @} */


/**
 * @name RegAoadLut6
 * @{
 */
// RegAoadLut6.r32
#define  REG_AOAD_LUT6_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut6 */
#define  REG_AOAD_LUT6_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut6 */

#define  AOAD_LUT24_SHIFT                                   0                             /**< Shift for AoadLut24 */
#define  AOAD_LUT24_MASK                                    0x000000FFu                   /**< Mask for AoadLut24 */
#define  AOAD_LUT24_BMASK                                   0xFFu                         /**< Base mask for AoadLut24 */
#define  AOAD_LUT24(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut24 in register */
#define  GET_AOAD_LUT24(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut24 from register */
#define  AOAD_LUT25_SHIFT                                   8                             /**< Shift for AoadLut25 */
#define  AOAD_LUT25_MASK                                    0x0000FF00u                   /**< Mask for AoadLut25 */
#define  AOAD_LUT25_BMASK                                   0xFFu                         /**< Base mask for AoadLut25 */
#define  AOAD_LUT25(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut25 in register */
#define  GET_AOAD_LUT25(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut25 from register */
#define  AOAD_LUT26_SHIFT                                   16                            /**< Shift for AoadLut26 */
#define  AOAD_LUT26_MASK                                    0x00FF0000u                   /**< Mask for AoadLut26 */
#define  AOAD_LUT26_BMASK                                   0xFFu                         /**< Base mask for AoadLut26 */
#define  AOAD_LUT26(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut26 in register */
#define  GET_AOAD_LUT26(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut26 from register */
#define  AOAD_LUT27_SHIFT                                   24                            /**< Shift for AoadLut27 */
#define  AOAD_LUT27_MASK                                    0xFF000000u                   /**< Mask for AoadLut27 */
#define  AOAD_LUT27_BMASK                                   0xFFu                         /**< Base mask for AoadLut27 */
#define  AOAD_LUT27(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut27 in register */
#define  GET_AOAD_LUT27(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut27 from register */

// RegAoadLut6.regs.AoadLut24
#define  AOAD_LUT24_GSHIFT                                  0                             /**< Shift for group AoadLut24 */
#define  AOAD_LUT24_GSIZE                                   8                             /**< Size of group AoadLut24 */
#define  AOAD_LUT24_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut24 */

#define  AOAD_LUT24_RSHIFT                                  0                             /**< Shift for AoadLut24 */
#define  AOAD_LUT24_RMASK                                   0x000000FFu                   /**< Mask for AoadLut24 */
#define  AOAD_LUT24_RBMASK                                  0xFFu                         /**< Base mask for AoadLut24 */
#define  AOAD_LUT24_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut24 in register */
#define  GET_AOAD_LUT24_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut24 from register */

// RegAoadLut6.regs.AoadLut25
#define  AOAD_LUT25_GSHIFT                                  8                             /**< Shift for group AoadLut25 */
#define  AOAD_LUT25_GSIZE                                   8                             /**< Size of group AoadLut25 */
#define  AOAD_LUT25_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut25 */

#define  AOAD_LUT25_RSHIFT                                  0                             /**< Shift for AoadLut25 */
#define  AOAD_LUT25_RMASK                                   0x000000FFu                   /**< Mask for AoadLut25 */
#define  AOAD_LUT25_RBMASK                                  0xFFu                         /**< Base mask for AoadLut25 */
#define  AOAD_LUT25_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut25 in register */
#define  GET_AOAD_LUT25_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut25 from register */

// RegAoadLut6.regs.AoadLut26
#define  AOAD_LUT26_GSHIFT                                  16                            /**< Shift for group AoadLut26 */
#define  AOAD_LUT26_GSIZE                                   8                             /**< Size of group AoadLut26 */
#define  AOAD_LUT26_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut26 */

#define  AOAD_LUT26_RSHIFT                                  0                             /**< Shift for AoadLut26 */
#define  AOAD_LUT26_RMASK                                   0x000000FFu                   /**< Mask for AoadLut26 */
#define  AOAD_LUT26_RBMASK                                  0xFFu                         /**< Base mask for AoadLut26 */
#define  AOAD_LUT26_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut26 in register */
#define  GET_AOAD_LUT26_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut26 from register */

// RegAoadLut6.regs.AoadLut27
#define  AOAD_LUT27_GSHIFT                                  24                            /**< Shift for group AoadLut27 */
#define  AOAD_LUT27_GSIZE                                   8                             /**< Size of group AoadLut27 */
#define  AOAD_LUT27_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut27 */

#define  AOAD_LUT27_RSHIFT                                  0                             /**< Shift for AoadLut27 */
#define  AOAD_LUT27_RMASK                                   0x000000FFu                   /**< Mask for AoadLut27 */
#define  AOAD_LUT27_RBMASK                                  0xFFu                         /**< Base mask for AoadLut27 */
#define  AOAD_LUT27_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut27 in register */
#define  GET_AOAD_LUT27_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut27 from register */
/** @} */


/**
 * @name RegAoadLut7
 * @{
 */
// RegAoadLut7.r32
#define  REG_AOAD_LUT7_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut7 */
#define  REG_AOAD_LUT7_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut7 */

#define  AOAD_LUT28_SHIFT                                   0                             /**< Shift for AoadLut28 */
#define  AOAD_LUT28_MASK                                    0x000000FFu                   /**< Mask for AoadLut28 */
#define  AOAD_LUT28_BMASK                                   0xFFu                         /**< Base mask for AoadLut28 */
#define  AOAD_LUT28(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut28 in register */
#define  GET_AOAD_LUT28(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut28 from register */
#define  AOAD_LUT29_SHIFT                                   8                             /**< Shift for AoadLut29 */
#define  AOAD_LUT29_MASK                                    0x0000FF00u                   /**< Mask for AoadLut29 */
#define  AOAD_LUT29_BMASK                                   0xFFu                         /**< Base mask for AoadLut29 */
#define  AOAD_LUT29(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut29 in register */
#define  GET_AOAD_LUT29(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut29 from register */
#define  AOAD_LUT30_SHIFT                                   16                            /**< Shift for AoadLut30 */
#define  AOAD_LUT30_MASK                                    0x00FF0000u                   /**< Mask for AoadLut30 */
#define  AOAD_LUT30_BMASK                                   0xFFu                         /**< Base mask for AoadLut30 */
#define  AOAD_LUT30(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut30 in register */
#define  GET_AOAD_LUT30(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut30 from register */
#define  AOAD_LUT31_SHIFT                                   24                            /**< Shift for AoadLut31 */
#define  AOAD_LUT31_MASK                                    0xFF000000u                   /**< Mask for AoadLut31 */
#define  AOAD_LUT31_BMASK                                   0xFFu                         /**< Base mask for AoadLut31 */
#define  AOAD_LUT31(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut31 in register */
#define  GET_AOAD_LUT31(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut31 from register */

// RegAoadLut7.regs.AoadLut28
#define  AOAD_LUT28_GSHIFT                                  0                             /**< Shift for group AoadLut28 */
#define  AOAD_LUT28_GSIZE                                   8                             /**< Size of group AoadLut28 */
#define  AOAD_LUT28_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut28 */

#define  AOAD_LUT28_RSHIFT                                  0                             /**< Shift for AoadLut28 */
#define  AOAD_LUT28_RMASK                                   0x000000FFu                   /**< Mask for AoadLut28 */
#define  AOAD_LUT28_RBMASK                                  0xFFu                         /**< Base mask for AoadLut28 */
#define  AOAD_LUT28_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut28 in register */
#define  GET_AOAD_LUT28_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut28 from register */

// RegAoadLut7.regs.AoadLut29
#define  AOAD_LUT29_GSHIFT                                  8                             /**< Shift for group AoadLut29 */
#define  AOAD_LUT29_GSIZE                                   8                             /**< Size of group AoadLut29 */
#define  AOAD_LUT29_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut29 */

#define  AOAD_LUT29_RSHIFT                                  0                             /**< Shift for AoadLut29 */
#define  AOAD_LUT29_RMASK                                   0x000000FFu                   /**< Mask for AoadLut29 */
#define  AOAD_LUT29_RBMASK                                  0xFFu                         /**< Base mask for AoadLut29 */
#define  AOAD_LUT29_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut29 in register */
#define  GET_AOAD_LUT29_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut29 from register */

// RegAoadLut7.regs.AoadLut30
#define  AOAD_LUT30_GSHIFT                                  16                            /**< Shift for group AoadLut30 */
#define  AOAD_LUT30_GSIZE                                   8                             /**< Size of group AoadLut30 */
#define  AOAD_LUT30_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut30 */

#define  AOAD_LUT30_RSHIFT                                  0                             /**< Shift for AoadLut30 */
#define  AOAD_LUT30_RMASK                                   0x000000FFu                   /**< Mask for AoadLut30 */
#define  AOAD_LUT30_RBMASK                                  0xFFu                         /**< Base mask for AoadLut30 */
#define  AOAD_LUT30_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut30 in register */
#define  GET_AOAD_LUT30_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut30 from register */

// RegAoadLut7.regs.AoadLut31
#define  AOAD_LUT31_GSHIFT                                  24                            /**< Shift for group AoadLut31 */
#define  AOAD_LUT31_GSIZE                                   8                             /**< Size of group AoadLut31 */
#define  AOAD_LUT31_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut31 */

#define  AOAD_LUT31_RSHIFT                                  0                             /**< Shift for AoadLut31 */
#define  AOAD_LUT31_RMASK                                   0x000000FFu                   /**< Mask for AoadLut31 */
#define  AOAD_LUT31_RBMASK                                  0xFFu                         /**< Base mask for AoadLut31 */
#define  AOAD_LUT31_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut31 in register */
#define  GET_AOAD_LUT31_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut31 from register */
/** @} */


/**
 * @name RegAoadLut8
 * @{
 */
// RegAoadLut8.r32
#define  REG_AOAD_LUT8_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut8 */
#define  REG_AOAD_LUT8_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut8 */

#define  AOAD_LUT32_SHIFT                                   0                             /**< Shift for AoadLut32 */
#define  AOAD_LUT32_MASK                                    0x000000FFu                   /**< Mask for AoadLut32 */
#define  AOAD_LUT32_BMASK                                   0xFFu                         /**< Base mask for AoadLut32 */
#define  AOAD_LUT32(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut32 in register */
#define  GET_AOAD_LUT32(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut32 from register */
#define  AOAD_LUT33_SHIFT                                   8                             /**< Shift for AoadLut33 */
#define  AOAD_LUT33_MASK                                    0x0000FF00u                   /**< Mask for AoadLut33 */
#define  AOAD_LUT33_BMASK                                   0xFFu                         /**< Base mask for AoadLut33 */
#define  AOAD_LUT33(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut33 in register */
#define  GET_AOAD_LUT33(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut33 from register */
#define  AOAD_LUT34_SHIFT                                   16                            /**< Shift for AoadLut34 */
#define  AOAD_LUT34_MASK                                    0x00FF0000u                   /**< Mask for AoadLut34 */
#define  AOAD_LUT34_BMASK                                   0xFFu                         /**< Base mask for AoadLut34 */
#define  AOAD_LUT34(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut34 in register */
#define  GET_AOAD_LUT34(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut34 from register */
#define  AOAD_LUT35_SHIFT                                   24                            /**< Shift for AoadLut35 */
#define  AOAD_LUT35_MASK                                    0xFF000000u                   /**< Mask for AoadLut35 */
#define  AOAD_LUT35_BMASK                                   0xFFu                         /**< Base mask for AoadLut35 */
#define  AOAD_LUT35(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut35 in register */
#define  GET_AOAD_LUT35(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut35 from register */

// RegAoadLut8.regs.AoadLut32
#define  AOAD_LUT32_GSHIFT                                  0                             /**< Shift for group AoadLut32 */
#define  AOAD_LUT32_GSIZE                                   8                             /**< Size of group AoadLut32 */
#define  AOAD_LUT32_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut32 */

#define  AOAD_LUT32_RSHIFT                                  0                             /**< Shift for AoadLut32 */
#define  AOAD_LUT32_RMASK                                   0x000000FFu                   /**< Mask for AoadLut32 */
#define  AOAD_LUT32_RBMASK                                  0xFFu                         /**< Base mask for AoadLut32 */
#define  AOAD_LUT32_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut32 in register */
#define  GET_AOAD_LUT32_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut32 from register */

// RegAoadLut8.regs.AoadLut33
#define  AOAD_LUT33_GSHIFT                                  8                             /**< Shift for group AoadLut33 */
#define  AOAD_LUT33_GSIZE                                   8                             /**< Size of group AoadLut33 */
#define  AOAD_LUT33_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut33 */

#define  AOAD_LUT33_RSHIFT                                  0                             /**< Shift for AoadLut33 */
#define  AOAD_LUT33_RMASK                                   0x000000FFu                   /**< Mask for AoadLut33 */
#define  AOAD_LUT33_RBMASK                                  0xFFu                         /**< Base mask for AoadLut33 */
#define  AOAD_LUT33_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut33 in register */
#define  GET_AOAD_LUT33_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut33 from register */

// RegAoadLut8.regs.AoadLut34
#define  AOAD_LUT34_GSHIFT                                  16                            /**< Shift for group AoadLut34 */
#define  AOAD_LUT34_GSIZE                                   8                             /**< Size of group AoadLut34 */
#define  AOAD_LUT34_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut34 */

#define  AOAD_LUT34_RSHIFT                                  0                             /**< Shift for AoadLut34 */
#define  AOAD_LUT34_RMASK                                   0x000000FFu                   /**< Mask for AoadLut34 */
#define  AOAD_LUT34_RBMASK                                  0xFFu                         /**< Base mask for AoadLut34 */
#define  AOAD_LUT34_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut34 in register */
#define  GET_AOAD_LUT34_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut34 from register */

// RegAoadLut8.regs.AoadLut35
#define  AOAD_LUT35_GSHIFT                                  24                            /**< Shift for group AoadLut35 */
#define  AOAD_LUT35_GSIZE                                   8                             /**< Size of group AoadLut35 */
#define  AOAD_LUT35_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut35 */

#define  AOAD_LUT35_RSHIFT                                  0                             /**< Shift for AoadLut35 */
#define  AOAD_LUT35_RMASK                                   0x000000FFu                   /**< Mask for AoadLut35 */
#define  AOAD_LUT35_RBMASK                                  0xFFu                         /**< Base mask for AoadLut35 */
#define  AOAD_LUT35_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut35 in register */
#define  GET_AOAD_LUT35_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut35 from register */
/** @} */


/**
 * @name RegAoadLut9
 * @{
 */
// RegAoadLut9.r32
#define  REG_AOAD_LUT9_RESET_VALUE                          0x00000000u                   /**< Reset value of RegAoadLut9 */
#define  REG_AOAD_LUT9_MASK                                 0xFFFFFFFFu                   /**< Mask for RegAoadLut9 */

#define  AOAD_LUT36_SHIFT                                   0                             /**< Shift for AoadLut36 */
#define  AOAD_LUT36_MASK                                    0x000000FFu                   /**< Mask for AoadLut36 */
#define  AOAD_LUT36_BMASK                                   0xFFu                         /**< Base mask for AoadLut36 */
#define  AOAD_LUT36(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut36 in register */
#define  GET_AOAD_LUT36(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut36 from register */
#define  AOAD_LUT37_SHIFT                                   8                             /**< Shift for AoadLut37 */
#define  AOAD_LUT37_MASK                                    0x0000FF00u                   /**< Mask for AoadLut37 */
#define  AOAD_LUT37_BMASK                                   0xFFu                         /**< Base mask for AoadLut37 */
#define  AOAD_LUT37(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut37 in register */
#define  GET_AOAD_LUT37(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut37 from register */
#define  AOAD_LUT38_SHIFT                                   16                            /**< Shift for AoadLut38 */
#define  AOAD_LUT38_MASK                                    0x00FF0000u                   /**< Mask for AoadLut38 */
#define  AOAD_LUT38_BMASK                                   0xFFu                         /**< Base mask for AoadLut38 */
#define  AOAD_LUT38(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut38 in register */
#define  GET_AOAD_LUT38(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut38 from register */
#define  AOAD_LUT39_SHIFT                                   24                            /**< Shift for AoadLut39 */
#define  AOAD_LUT39_MASK                                    0xFF000000u                   /**< Mask for AoadLut39 */
#define  AOAD_LUT39_BMASK                                   0xFFu                         /**< Base mask for AoadLut39 */
#define  AOAD_LUT39(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut39 in register */
#define  GET_AOAD_LUT39(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut39 from register */

// RegAoadLut9.regs.AoadLut36
#define  AOAD_LUT36_GSHIFT                                  0                             /**< Shift for group AoadLut36 */
#define  AOAD_LUT36_GSIZE                                   8                             /**< Size of group AoadLut36 */
#define  AOAD_LUT36_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut36 */

#define  AOAD_LUT36_RSHIFT                                  0                             /**< Shift for AoadLut36 */
#define  AOAD_LUT36_RMASK                                   0x000000FFu                   /**< Mask for AoadLut36 */
#define  AOAD_LUT36_RBMASK                                  0xFFu                         /**< Base mask for AoadLut36 */
#define  AOAD_LUT36_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut36 in register */
#define  GET_AOAD_LUT36_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut36 from register */

// RegAoadLut9.regs.AoadLut37
#define  AOAD_LUT37_GSHIFT                                  8                             /**< Shift for group AoadLut37 */
#define  AOAD_LUT37_GSIZE                                   8                             /**< Size of group AoadLut37 */
#define  AOAD_LUT37_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut37 */

#define  AOAD_LUT37_RSHIFT                                  0                             /**< Shift for AoadLut37 */
#define  AOAD_LUT37_RMASK                                   0x000000FFu                   /**< Mask for AoadLut37 */
#define  AOAD_LUT37_RBMASK                                  0xFFu                         /**< Base mask for AoadLut37 */
#define  AOAD_LUT37_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut37 in register */
#define  GET_AOAD_LUT37_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut37 from register */

// RegAoadLut9.regs.AoadLut38
#define  AOAD_LUT38_GSHIFT                                  16                            /**< Shift for group AoadLut38 */
#define  AOAD_LUT38_GSIZE                                   8                             /**< Size of group AoadLut38 */
#define  AOAD_LUT38_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut38 */

#define  AOAD_LUT38_RSHIFT                                  0                             /**< Shift for AoadLut38 */
#define  AOAD_LUT38_RMASK                                   0x000000FFu                   /**< Mask for AoadLut38 */
#define  AOAD_LUT38_RBMASK                                  0xFFu                         /**< Base mask for AoadLut38 */
#define  AOAD_LUT38_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut38 in register */
#define  GET_AOAD_LUT38_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut38 from register */

// RegAoadLut9.regs.AoadLut39
#define  AOAD_LUT39_GSHIFT                                  24                            /**< Shift for group AoadLut39 */
#define  AOAD_LUT39_GSIZE                                   8                             /**< Size of group AoadLut39 */
#define  AOAD_LUT39_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut39 */

#define  AOAD_LUT39_RSHIFT                                  0                             /**< Shift for AoadLut39 */
#define  AOAD_LUT39_RMASK                                   0x000000FFu                   /**< Mask for AoadLut39 */
#define  AOAD_LUT39_RBMASK                                  0xFFu                         /**< Base mask for AoadLut39 */
#define  AOAD_LUT39_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut39 in register */
#define  GET_AOAD_LUT39_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut39 from register */
/** @} */


/**
 * @name RegAoadLut10
 * @{
 */
// RegAoadLut10.r32
#define  REG_AOAD_LUT10_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut10 */
#define  REG_AOAD_LUT10_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut10 */

#define  AOAD_LUT40_SHIFT                                   0                             /**< Shift for AoadLut40 */
#define  AOAD_LUT40_MASK                                    0x000000FFu                   /**< Mask for AoadLut40 */
#define  AOAD_LUT40_BMASK                                   0xFFu                         /**< Base mask for AoadLut40 */
#define  AOAD_LUT40(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut40 in register */
#define  GET_AOAD_LUT40(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut40 from register */
#define  AOAD_LUT41_SHIFT                                   8                             /**< Shift for AoadLut41 */
#define  AOAD_LUT41_MASK                                    0x0000FF00u                   /**< Mask for AoadLut41 */
#define  AOAD_LUT41_BMASK                                   0xFFu                         /**< Base mask for AoadLut41 */
#define  AOAD_LUT41(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut41 in register */
#define  GET_AOAD_LUT41(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut41 from register */
#define  AOAD_LUT42_SHIFT                                   16                            /**< Shift for AoadLut42 */
#define  AOAD_LUT42_MASK                                    0x00FF0000u                   /**< Mask for AoadLut42 */
#define  AOAD_LUT42_BMASK                                   0xFFu                         /**< Base mask for AoadLut42 */
#define  AOAD_LUT42(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut42 in register */
#define  GET_AOAD_LUT42(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut42 from register */
#define  AOAD_LUT43_SHIFT                                   24                            /**< Shift for AoadLut43 */
#define  AOAD_LUT43_MASK                                    0xFF000000u                   /**< Mask for AoadLut43 */
#define  AOAD_LUT43_BMASK                                   0xFFu                         /**< Base mask for AoadLut43 */
#define  AOAD_LUT43(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut43 in register */
#define  GET_AOAD_LUT43(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut43 from register */

// RegAoadLut10.regs.AoadLut40
#define  AOAD_LUT40_GSHIFT                                  0                             /**< Shift for group AoadLut40 */
#define  AOAD_LUT40_GSIZE                                   8                             /**< Size of group AoadLut40 */
#define  AOAD_LUT40_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut40 */

#define  AOAD_LUT40_RSHIFT                                  0                             /**< Shift for AoadLut40 */
#define  AOAD_LUT40_RMASK                                   0x000000FFu                   /**< Mask for AoadLut40 */
#define  AOAD_LUT40_RBMASK                                  0xFFu                         /**< Base mask for AoadLut40 */
#define  AOAD_LUT40_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut40 in register */
#define  GET_AOAD_LUT40_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut40 from register */

// RegAoadLut10.regs.AoadLut41
#define  AOAD_LUT41_GSHIFT                                  8                             /**< Shift for group AoadLut41 */
#define  AOAD_LUT41_GSIZE                                   8                             /**< Size of group AoadLut41 */
#define  AOAD_LUT41_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut41 */

#define  AOAD_LUT41_RSHIFT                                  0                             /**< Shift for AoadLut41 */
#define  AOAD_LUT41_RMASK                                   0x000000FFu                   /**< Mask for AoadLut41 */
#define  AOAD_LUT41_RBMASK                                  0xFFu                         /**< Base mask for AoadLut41 */
#define  AOAD_LUT41_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut41 in register */
#define  GET_AOAD_LUT41_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut41 from register */

// RegAoadLut10.regs.AoadLut42
#define  AOAD_LUT42_GSHIFT                                  16                            /**< Shift for group AoadLut42 */
#define  AOAD_LUT42_GSIZE                                   8                             /**< Size of group AoadLut42 */
#define  AOAD_LUT42_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut42 */

#define  AOAD_LUT42_RSHIFT                                  0                             /**< Shift for AoadLut42 */
#define  AOAD_LUT42_RMASK                                   0x000000FFu                   /**< Mask for AoadLut42 */
#define  AOAD_LUT42_RBMASK                                  0xFFu                         /**< Base mask for AoadLut42 */
#define  AOAD_LUT42_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut42 in register */
#define  GET_AOAD_LUT42_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut42 from register */

// RegAoadLut10.regs.AoadLut43
#define  AOAD_LUT43_GSHIFT                                  24                            /**< Shift for group AoadLut43 */
#define  AOAD_LUT43_GSIZE                                   8                             /**< Size of group AoadLut43 */
#define  AOAD_LUT43_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut43 */

#define  AOAD_LUT43_RSHIFT                                  0                             /**< Shift for AoadLut43 */
#define  AOAD_LUT43_RMASK                                   0x000000FFu                   /**< Mask for AoadLut43 */
#define  AOAD_LUT43_RBMASK                                  0xFFu                         /**< Base mask for AoadLut43 */
#define  AOAD_LUT43_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut43 in register */
#define  GET_AOAD_LUT43_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut43 from register */
/** @} */


/**
 * @name RegAoadLut11
 * @{
 */
// RegAoadLut11.r32
#define  REG_AOAD_LUT11_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut11 */
#define  REG_AOAD_LUT11_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut11 */

#define  AOAD_LUT44_SHIFT                                   0                             /**< Shift for AoadLut44 */
#define  AOAD_LUT44_MASK                                    0x000000FFu                   /**< Mask for AoadLut44 */
#define  AOAD_LUT44_BMASK                                   0xFFu                         /**< Base mask for AoadLut44 */
#define  AOAD_LUT44(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut44 in register */
#define  GET_AOAD_LUT44(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut44 from register */
#define  AOAD_LUT45_SHIFT                                   8                             /**< Shift for AoadLut45 */
#define  AOAD_LUT45_MASK                                    0x0000FF00u                   /**< Mask for AoadLut45 */
#define  AOAD_LUT45_BMASK                                   0xFFu                         /**< Base mask for AoadLut45 */
#define  AOAD_LUT45(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut45 in register */
#define  GET_AOAD_LUT45(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut45 from register */
#define  AOAD_LUT46_SHIFT                                   16                            /**< Shift for AoadLut46 */
#define  AOAD_LUT46_MASK                                    0x00FF0000u                   /**< Mask for AoadLut46 */
#define  AOAD_LUT46_BMASK                                   0xFFu                         /**< Base mask for AoadLut46 */
#define  AOAD_LUT46(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut46 in register */
#define  GET_AOAD_LUT46(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut46 from register */
#define  AOAD_LUT47_SHIFT                                   24                            /**< Shift for AoadLut47 */
#define  AOAD_LUT47_MASK                                    0xFF000000u                   /**< Mask for AoadLut47 */
#define  AOAD_LUT47_BMASK                                   0xFFu                         /**< Base mask for AoadLut47 */
#define  AOAD_LUT47(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut47 in register */
#define  GET_AOAD_LUT47(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut47 from register */

// RegAoadLut11.regs.AoadLut44
#define  AOAD_LUT44_GSHIFT                                  0                             /**< Shift for group AoadLut44 */
#define  AOAD_LUT44_GSIZE                                   8                             /**< Size of group AoadLut44 */
#define  AOAD_LUT44_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut44 */

#define  AOAD_LUT44_RSHIFT                                  0                             /**< Shift for AoadLut44 */
#define  AOAD_LUT44_RMASK                                   0x000000FFu                   /**< Mask for AoadLut44 */
#define  AOAD_LUT44_RBMASK                                  0xFFu                         /**< Base mask for AoadLut44 */
#define  AOAD_LUT44_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut44 in register */
#define  GET_AOAD_LUT44_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut44 from register */

// RegAoadLut11.regs.AoadLut45
#define  AOAD_LUT45_GSHIFT                                  8                             /**< Shift for group AoadLut45 */
#define  AOAD_LUT45_GSIZE                                   8                             /**< Size of group AoadLut45 */
#define  AOAD_LUT45_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut45 */

#define  AOAD_LUT45_RSHIFT                                  0                             /**< Shift for AoadLut45 */
#define  AOAD_LUT45_RMASK                                   0x000000FFu                   /**< Mask for AoadLut45 */
#define  AOAD_LUT45_RBMASK                                  0xFFu                         /**< Base mask for AoadLut45 */
#define  AOAD_LUT45_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut45 in register */
#define  GET_AOAD_LUT45_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut45 from register */

// RegAoadLut11.regs.AoadLut46
#define  AOAD_LUT46_GSHIFT                                  16                            /**< Shift for group AoadLut46 */
#define  AOAD_LUT46_GSIZE                                   8                             /**< Size of group AoadLut46 */
#define  AOAD_LUT46_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut46 */

#define  AOAD_LUT46_RSHIFT                                  0                             /**< Shift for AoadLut46 */
#define  AOAD_LUT46_RMASK                                   0x000000FFu                   /**< Mask for AoadLut46 */
#define  AOAD_LUT46_RBMASK                                  0xFFu                         /**< Base mask for AoadLut46 */
#define  AOAD_LUT46_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut46 in register */
#define  GET_AOAD_LUT46_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut46 from register */

// RegAoadLut11.regs.AoadLut47
#define  AOAD_LUT47_GSHIFT                                  24                            /**< Shift for group AoadLut47 */
#define  AOAD_LUT47_GSIZE                                   8                             /**< Size of group AoadLut47 */
#define  AOAD_LUT47_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut47 */

#define  AOAD_LUT47_RSHIFT                                  0                             /**< Shift for AoadLut47 */
#define  AOAD_LUT47_RMASK                                   0x000000FFu                   /**< Mask for AoadLut47 */
#define  AOAD_LUT47_RBMASK                                  0xFFu                         /**< Base mask for AoadLut47 */
#define  AOAD_LUT47_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut47 in register */
#define  GET_AOAD_LUT47_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut47 from register */
/** @} */


/**
 * @name RegAoadLut12
 * @{
 */
// RegAoadLut12.r32
#define  REG_AOAD_LUT12_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut12 */
#define  REG_AOAD_LUT12_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut12 */

#define  AOAD_LUT48_SHIFT                                   0                             /**< Shift for AoadLut48 */
#define  AOAD_LUT48_MASK                                    0x000000FFu                   /**< Mask for AoadLut48 */
#define  AOAD_LUT48_BMASK                                   0xFFu                         /**< Base mask for AoadLut48 */
#define  AOAD_LUT48(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut48 in register */
#define  GET_AOAD_LUT48(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut48 from register */
#define  AOAD_LUT49_SHIFT                                   8                             /**< Shift for AoadLut49 */
#define  AOAD_LUT49_MASK                                    0x0000FF00u                   /**< Mask for AoadLut49 */
#define  AOAD_LUT49_BMASK                                   0xFFu                         /**< Base mask for AoadLut49 */
#define  AOAD_LUT49(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut49 in register */
#define  GET_AOAD_LUT49(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut49 from register */
#define  AOAD_LUT50_SHIFT                                   16                            /**< Shift for AoadLut50 */
#define  AOAD_LUT50_MASK                                    0x00FF0000u                   /**< Mask for AoadLut50 */
#define  AOAD_LUT50_BMASK                                   0xFFu                         /**< Base mask for AoadLut50 */
#define  AOAD_LUT50(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut50 in register */
#define  GET_AOAD_LUT50(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut50 from register */
#define  AOAD_LUT51_SHIFT                                   24                            /**< Shift for AoadLut51 */
#define  AOAD_LUT51_MASK                                    0xFF000000u                   /**< Mask for AoadLut51 */
#define  AOAD_LUT51_BMASK                                   0xFFu                         /**< Base mask for AoadLut51 */
#define  AOAD_LUT51(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut51 in register */
#define  GET_AOAD_LUT51(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut51 from register */

// RegAoadLut12.regs.AoadLut48
#define  AOAD_LUT48_GSHIFT                                  0                             /**< Shift for group AoadLut48 */
#define  AOAD_LUT48_GSIZE                                   8                             /**< Size of group AoadLut48 */
#define  AOAD_LUT48_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut48 */

#define  AOAD_LUT48_RSHIFT                                  0                             /**< Shift for AoadLut48 */
#define  AOAD_LUT48_RMASK                                   0x000000FFu                   /**< Mask for AoadLut48 */
#define  AOAD_LUT48_RBMASK                                  0xFFu                         /**< Base mask for AoadLut48 */
#define  AOAD_LUT48_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut48 in register */
#define  GET_AOAD_LUT48_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut48 from register */

// RegAoadLut12.regs.AoadLut49
#define  AOAD_LUT49_GSHIFT                                  8                             /**< Shift for group AoadLut49 */
#define  AOAD_LUT49_GSIZE                                   8                             /**< Size of group AoadLut49 */
#define  AOAD_LUT49_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut49 */

#define  AOAD_LUT49_RSHIFT                                  0                             /**< Shift for AoadLut49 */
#define  AOAD_LUT49_RMASK                                   0x000000FFu                   /**< Mask for AoadLut49 */
#define  AOAD_LUT49_RBMASK                                  0xFFu                         /**< Base mask for AoadLut49 */
#define  AOAD_LUT49_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut49 in register */
#define  GET_AOAD_LUT49_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut49 from register */

// RegAoadLut12.regs.AoadLut50
#define  AOAD_LUT50_GSHIFT                                  16                            /**< Shift for group AoadLut50 */
#define  AOAD_LUT50_GSIZE                                   8                             /**< Size of group AoadLut50 */
#define  AOAD_LUT50_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut50 */

#define  AOAD_LUT50_RSHIFT                                  0                             /**< Shift for AoadLut50 */
#define  AOAD_LUT50_RMASK                                   0x000000FFu                   /**< Mask for AoadLut50 */
#define  AOAD_LUT50_RBMASK                                  0xFFu                         /**< Base mask for AoadLut50 */
#define  AOAD_LUT50_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut50 in register */
#define  GET_AOAD_LUT50_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut50 from register */

// RegAoadLut12.regs.AoadLut51
#define  AOAD_LUT51_GSHIFT                                  24                            /**< Shift for group AoadLut51 */
#define  AOAD_LUT51_GSIZE                                   8                             /**< Size of group AoadLut51 */
#define  AOAD_LUT51_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut51 */

#define  AOAD_LUT51_RSHIFT                                  0                             /**< Shift for AoadLut51 */
#define  AOAD_LUT51_RMASK                                   0x000000FFu                   /**< Mask for AoadLut51 */
#define  AOAD_LUT51_RBMASK                                  0xFFu                         /**< Base mask for AoadLut51 */
#define  AOAD_LUT51_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut51 in register */
#define  GET_AOAD_LUT51_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut51 from register */
/** @} */


/**
 * @name RegAoadLut13
 * @{
 */
// RegAoadLut13.r32
#define  REG_AOAD_LUT13_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut13 */
#define  REG_AOAD_LUT13_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut13 */

#define  AOAD_LUT52_SHIFT                                   0                             /**< Shift for AoadLut52 */
#define  AOAD_LUT52_MASK                                    0x000000FFu                   /**< Mask for AoadLut52 */
#define  AOAD_LUT52_BMASK                                   0xFFu                         /**< Base mask for AoadLut52 */
#define  AOAD_LUT52(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut52 in register */
#define  GET_AOAD_LUT52(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut52 from register */
#define  AOAD_LUT53_SHIFT                                   8                             /**< Shift for AoadLut53 */
#define  AOAD_LUT53_MASK                                    0x0000FF00u                   /**< Mask for AoadLut53 */
#define  AOAD_LUT53_BMASK                                   0xFFu                         /**< Base mask for AoadLut53 */
#define  AOAD_LUT53(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut53 in register */
#define  GET_AOAD_LUT53(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut53 from register */
#define  AOAD_LUT54_SHIFT                                   16                            /**< Shift for AoadLut54 */
#define  AOAD_LUT54_MASK                                    0x00FF0000u                   /**< Mask for AoadLut54 */
#define  AOAD_LUT54_BMASK                                   0xFFu                         /**< Base mask for AoadLut54 */
#define  AOAD_LUT54(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut54 in register */
#define  GET_AOAD_LUT54(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut54 from register */
#define  AOAD_LUT55_SHIFT                                   24                            /**< Shift for AoadLut55 */
#define  AOAD_LUT55_MASK                                    0xFF000000u                   /**< Mask for AoadLut55 */
#define  AOAD_LUT55_BMASK                                   0xFFu                         /**< Base mask for AoadLut55 */
#define  AOAD_LUT55(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut55 in register */
#define  GET_AOAD_LUT55(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut55 from register */

// RegAoadLut13.regs.AoadLut52
#define  AOAD_LUT52_GSHIFT                                  0                             /**< Shift for group AoadLut52 */
#define  AOAD_LUT52_GSIZE                                   8                             /**< Size of group AoadLut52 */
#define  AOAD_LUT52_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut52 */

#define  AOAD_LUT52_RSHIFT                                  0                             /**< Shift for AoadLut52 */
#define  AOAD_LUT52_RMASK                                   0x000000FFu                   /**< Mask for AoadLut52 */
#define  AOAD_LUT52_RBMASK                                  0xFFu                         /**< Base mask for AoadLut52 */
#define  AOAD_LUT52_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut52 in register */
#define  GET_AOAD_LUT52_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut52 from register */

// RegAoadLut13.regs.AoadLut53
#define  AOAD_LUT53_GSHIFT                                  8                             /**< Shift for group AoadLut53 */
#define  AOAD_LUT53_GSIZE                                   8                             /**< Size of group AoadLut53 */
#define  AOAD_LUT53_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut53 */

#define  AOAD_LUT53_RSHIFT                                  0                             /**< Shift for AoadLut53 */
#define  AOAD_LUT53_RMASK                                   0x000000FFu                   /**< Mask for AoadLut53 */
#define  AOAD_LUT53_RBMASK                                  0xFFu                         /**< Base mask for AoadLut53 */
#define  AOAD_LUT53_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut53 in register */
#define  GET_AOAD_LUT53_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut53 from register */

// RegAoadLut13.regs.AoadLut54
#define  AOAD_LUT54_GSHIFT                                  16                            /**< Shift for group AoadLut54 */
#define  AOAD_LUT54_GSIZE                                   8                             /**< Size of group AoadLut54 */
#define  AOAD_LUT54_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut54 */

#define  AOAD_LUT54_RSHIFT                                  0                             /**< Shift for AoadLut54 */
#define  AOAD_LUT54_RMASK                                   0x000000FFu                   /**< Mask for AoadLut54 */
#define  AOAD_LUT54_RBMASK                                  0xFFu                         /**< Base mask for AoadLut54 */
#define  AOAD_LUT54_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut54 in register */
#define  GET_AOAD_LUT54_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut54 from register */

// RegAoadLut13.regs.AoadLut55
#define  AOAD_LUT55_GSHIFT                                  24                            /**< Shift for group AoadLut55 */
#define  AOAD_LUT55_GSIZE                                   8                             /**< Size of group AoadLut55 */
#define  AOAD_LUT55_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut55 */

#define  AOAD_LUT55_RSHIFT                                  0                             /**< Shift for AoadLut55 */
#define  AOAD_LUT55_RMASK                                   0x000000FFu                   /**< Mask for AoadLut55 */
#define  AOAD_LUT55_RBMASK                                  0xFFu                         /**< Base mask for AoadLut55 */
#define  AOAD_LUT55_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut55 in register */
#define  GET_AOAD_LUT55_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut55 from register */
/** @} */


/**
 * @name RegAoadLut14
 * @{
 */
// RegAoadLut14.r32
#define  REG_AOAD_LUT14_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut14 */
#define  REG_AOAD_LUT14_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut14 */

#define  AOAD_LUT56_SHIFT                                   0                             /**< Shift for AoadLut56 */
#define  AOAD_LUT56_MASK                                    0x000000FFu                   /**< Mask for AoadLut56 */
#define  AOAD_LUT56_BMASK                                   0xFFu                         /**< Base mask for AoadLut56 */
#define  AOAD_LUT56(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut56 in register */
#define  GET_AOAD_LUT56(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut56 from register */
#define  AOAD_LUT57_SHIFT                                   8                             /**< Shift for AoadLut57 */
#define  AOAD_LUT57_MASK                                    0x0000FF00u                   /**< Mask for AoadLut57 */
#define  AOAD_LUT57_BMASK                                   0xFFu                         /**< Base mask for AoadLut57 */
#define  AOAD_LUT57(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut57 in register */
#define  GET_AOAD_LUT57(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut57 from register */
#define  AOAD_LUT58_SHIFT                                   16                            /**< Shift for AoadLut58 */
#define  AOAD_LUT58_MASK                                    0x00FF0000u                   /**< Mask for AoadLut58 */
#define  AOAD_LUT58_BMASK                                   0xFFu                         /**< Base mask for AoadLut58 */
#define  AOAD_LUT58(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut58 in register */
#define  GET_AOAD_LUT58(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut58 from register */
#define  AOAD_LUT59_SHIFT                                   24                            /**< Shift for AoadLut59 */
#define  AOAD_LUT59_MASK                                    0xFF000000u                   /**< Mask for AoadLut59 */
#define  AOAD_LUT59_BMASK                                   0xFFu                         /**< Base mask for AoadLut59 */
#define  AOAD_LUT59(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut59 in register */
#define  GET_AOAD_LUT59(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut59 from register */

// RegAoadLut14.regs.AoadLut56
#define  AOAD_LUT56_GSHIFT                                  0                             /**< Shift for group AoadLut56 */
#define  AOAD_LUT56_GSIZE                                   8                             /**< Size of group AoadLut56 */
#define  AOAD_LUT56_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut56 */

#define  AOAD_LUT56_RSHIFT                                  0                             /**< Shift for AoadLut56 */
#define  AOAD_LUT56_RMASK                                   0x000000FFu                   /**< Mask for AoadLut56 */
#define  AOAD_LUT56_RBMASK                                  0xFFu                         /**< Base mask for AoadLut56 */
#define  AOAD_LUT56_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut56 in register */
#define  GET_AOAD_LUT56_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut56 from register */

// RegAoadLut14.regs.AoadLut57
#define  AOAD_LUT57_GSHIFT                                  8                             /**< Shift for group AoadLut57 */
#define  AOAD_LUT57_GSIZE                                   8                             /**< Size of group AoadLut57 */
#define  AOAD_LUT57_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut57 */

#define  AOAD_LUT57_RSHIFT                                  0                             /**< Shift for AoadLut57 */
#define  AOAD_LUT57_RMASK                                   0x000000FFu                   /**< Mask for AoadLut57 */
#define  AOAD_LUT57_RBMASK                                  0xFFu                         /**< Base mask for AoadLut57 */
#define  AOAD_LUT57_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut57 in register */
#define  GET_AOAD_LUT57_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut57 from register */

// RegAoadLut14.regs.AoadLut58
#define  AOAD_LUT58_GSHIFT                                  16                            /**< Shift for group AoadLut58 */
#define  AOAD_LUT58_GSIZE                                   8                             /**< Size of group AoadLut58 */
#define  AOAD_LUT58_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut58 */

#define  AOAD_LUT58_RSHIFT                                  0                             /**< Shift for AoadLut58 */
#define  AOAD_LUT58_RMASK                                   0x000000FFu                   /**< Mask for AoadLut58 */
#define  AOAD_LUT58_RBMASK                                  0xFFu                         /**< Base mask for AoadLut58 */
#define  AOAD_LUT58_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut58 in register */
#define  GET_AOAD_LUT58_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut58 from register */

// RegAoadLut14.regs.AoadLut59
#define  AOAD_LUT59_GSHIFT                                  24                            /**< Shift for group AoadLut59 */
#define  AOAD_LUT59_GSIZE                                   8                             /**< Size of group AoadLut59 */
#define  AOAD_LUT59_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut59 */

#define  AOAD_LUT59_RSHIFT                                  0                             /**< Shift for AoadLut59 */
#define  AOAD_LUT59_RMASK                                   0x000000FFu                   /**< Mask for AoadLut59 */
#define  AOAD_LUT59_RBMASK                                  0xFFu                         /**< Base mask for AoadLut59 */
#define  AOAD_LUT59_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut59 in register */
#define  GET_AOAD_LUT59_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut59 from register */
/** @} */


/**
 * @name RegAoadLut15
 * @{
 */
// RegAoadLut15.r32
#define  REG_AOAD_LUT15_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut15 */
#define  REG_AOAD_LUT15_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut15 */

#define  AOAD_LUT60_SHIFT                                   0                             /**< Shift for AoadLut60 */
#define  AOAD_LUT60_MASK                                    0x000000FFu                   /**< Mask for AoadLut60 */
#define  AOAD_LUT60_BMASK                                   0xFFu                         /**< Base mask for AoadLut60 */
#define  AOAD_LUT60(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut60 in register */
#define  GET_AOAD_LUT60(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut60 from register */
#define  AOAD_LUT61_SHIFT                                   8                             /**< Shift for AoadLut61 */
#define  AOAD_LUT61_MASK                                    0x0000FF00u                   /**< Mask for AoadLut61 */
#define  AOAD_LUT61_BMASK                                   0xFFu                         /**< Base mask for AoadLut61 */
#define  AOAD_LUT61(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut61 in register */
#define  GET_AOAD_LUT61(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut61 from register */
#define  AOAD_LUT62_SHIFT                                   16                            /**< Shift for AoadLut62 */
#define  AOAD_LUT62_MASK                                    0x00FF0000u                   /**< Mask for AoadLut62 */
#define  AOAD_LUT62_BMASK                                   0xFFu                         /**< Base mask for AoadLut62 */
#define  AOAD_LUT62(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut62 in register */
#define  GET_AOAD_LUT62(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut62 from register */
#define  AOAD_LUT63_SHIFT                                   24                            /**< Shift for AoadLut63 */
#define  AOAD_LUT63_MASK                                    0xFF000000u                   /**< Mask for AoadLut63 */
#define  AOAD_LUT63_BMASK                                   0xFFu                         /**< Base mask for AoadLut63 */
#define  AOAD_LUT63(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut63 in register */
#define  GET_AOAD_LUT63(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut63 from register */

// RegAoadLut15.regs.AoadLut60
#define  AOAD_LUT60_GSHIFT                                  0                             /**< Shift for group AoadLut60 */
#define  AOAD_LUT60_GSIZE                                   8                             /**< Size of group AoadLut60 */
#define  AOAD_LUT60_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut60 */

#define  AOAD_LUT60_RSHIFT                                  0                             /**< Shift for AoadLut60 */
#define  AOAD_LUT60_RMASK                                   0x000000FFu                   /**< Mask for AoadLut60 */
#define  AOAD_LUT60_RBMASK                                  0xFFu                         /**< Base mask for AoadLut60 */
#define  AOAD_LUT60_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut60 in register */
#define  GET_AOAD_LUT60_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut60 from register */

// RegAoadLut15.regs.AoadLut61
#define  AOAD_LUT61_GSHIFT                                  8                             /**< Shift for group AoadLut61 */
#define  AOAD_LUT61_GSIZE                                   8                             /**< Size of group AoadLut61 */
#define  AOAD_LUT61_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut61 */

#define  AOAD_LUT61_RSHIFT                                  0                             /**< Shift for AoadLut61 */
#define  AOAD_LUT61_RMASK                                   0x000000FFu                   /**< Mask for AoadLut61 */
#define  AOAD_LUT61_RBMASK                                  0xFFu                         /**< Base mask for AoadLut61 */
#define  AOAD_LUT61_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut61 in register */
#define  GET_AOAD_LUT61_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut61 from register */

// RegAoadLut15.regs.AoadLut62
#define  AOAD_LUT62_GSHIFT                                  16                            /**< Shift for group AoadLut62 */
#define  AOAD_LUT62_GSIZE                                   8                             /**< Size of group AoadLut62 */
#define  AOAD_LUT62_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut62 */

#define  AOAD_LUT62_RSHIFT                                  0                             /**< Shift for AoadLut62 */
#define  AOAD_LUT62_RMASK                                   0x000000FFu                   /**< Mask for AoadLut62 */
#define  AOAD_LUT62_RBMASK                                  0xFFu                         /**< Base mask for AoadLut62 */
#define  AOAD_LUT62_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut62 in register */
#define  GET_AOAD_LUT62_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut62 from register */

// RegAoadLut15.regs.AoadLut63
#define  AOAD_LUT63_GSHIFT                                  24                            /**< Shift for group AoadLut63 */
#define  AOAD_LUT63_GSIZE                                   8                             /**< Size of group AoadLut63 */
#define  AOAD_LUT63_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut63 */

#define  AOAD_LUT63_RSHIFT                                  0                             /**< Shift for AoadLut63 */
#define  AOAD_LUT63_RMASK                                   0x000000FFu                   /**< Mask for AoadLut63 */
#define  AOAD_LUT63_RBMASK                                  0xFFu                         /**< Base mask for AoadLut63 */
#define  AOAD_LUT63_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut63 in register */
#define  GET_AOAD_LUT63_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut63 from register */
/** @} */


/**
 * @name RegAoadLut16
 * @{
 */
// RegAoadLut16.r32
#define  REG_AOAD_LUT16_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut16 */
#define  REG_AOAD_LUT16_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut16 */

#define  AOAD_LUT64_SHIFT                                   0                             /**< Shift for AoadLut64 */
#define  AOAD_LUT64_MASK                                    0x000000FFu                   /**< Mask for AoadLut64 */
#define  AOAD_LUT64_BMASK                                   0xFFu                         /**< Base mask for AoadLut64 */
#define  AOAD_LUT64(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut64 in register */
#define  GET_AOAD_LUT64(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut64 from register */
#define  AOAD_LUT65_SHIFT                                   8                             /**< Shift for AoadLut65 */
#define  AOAD_LUT65_MASK                                    0x0000FF00u                   /**< Mask for AoadLut65 */
#define  AOAD_LUT65_BMASK                                   0xFFu                         /**< Base mask for AoadLut65 */
#define  AOAD_LUT65(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut65 in register */
#define  GET_AOAD_LUT65(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut65 from register */
#define  AOAD_LUT66_SHIFT                                   16                            /**< Shift for AoadLut66 */
#define  AOAD_LUT66_MASK                                    0x00FF0000u                   /**< Mask for AoadLut66 */
#define  AOAD_LUT66_BMASK                                   0xFFu                         /**< Base mask for AoadLut66 */
#define  AOAD_LUT66(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut66 in register */
#define  GET_AOAD_LUT66(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut66 from register */
#define  AOAD_LUT67_SHIFT                                   24                            /**< Shift for AoadLut67 */
#define  AOAD_LUT67_MASK                                    0xFF000000u                   /**< Mask for AoadLut67 */
#define  AOAD_LUT67_BMASK                                   0xFFu                         /**< Base mask for AoadLut67 */
#define  AOAD_LUT67(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut67 in register */
#define  GET_AOAD_LUT67(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut67 from register */

// RegAoadLut16.regs.AoadLut64
#define  AOAD_LUT64_GSHIFT                                  0                             /**< Shift for group AoadLut64 */
#define  AOAD_LUT64_GSIZE                                   8                             /**< Size of group AoadLut64 */
#define  AOAD_LUT64_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut64 */

#define  AOAD_LUT64_RSHIFT                                  0                             /**< Shift for AoadLut64 */
#define  AOAD_LUT64_RMASK                                   0x000000FFu                   /**< Mask for AoadLut64 */
#define  AOAD_LUT64_RBMASK                                  0xFFu                         /**< Base mask for AoadLut64 */
#define  AOAD_LUT64_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut64 in register */
#define  GET_AOAD_LUT64_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut64 from register */

// RegAoadLut16.regs.AoadLut65
#define  AOAD_LUT65_GSHIFT                                  8                             /**< Shift for group AoadLut65 */
#define  AOAD_LUT65_GSIZE                                   8                             /**< Size of group AoadLut65 */
#define  AOAD_LUT65_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut65 */

#define  AOAD_LUT65_RSHIFT                                  0                             /**< Shift for AoadLut65 */
#define  AOAD_LUT65_RMASK                                   0x000000FFu                   /**< Mask for AoadLut65 */
#define  AOAD_LUT65_RBMASK                                  0xFFu                         /**< Base mask for AoadLut65 */
#define  AOAD_LUT65_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut65 in register */
#define  GET_AOAD_LUT65_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut65 from register */

// RegAoadLut16.regs.AoadLut66
#define  AOAD_LUT66_GSHIFT                                  16                            /**< Shift for group AoadLut66 */
#define  AOAD_LUT66_GSIZE                                   8                             /**< Size of group AoadLut66 */
#define  AOAD_LUT66_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut66 */

#define  AOAD_LUT66_RSHIFT                                  0                             /**< Shift for AoadLut66 */
#define  AOAD_LUT66_RMASK                                   0x000000FFu                   /**< Mask for AoadLut66 */
#define  AOAD_LUT66_RBMASK                                  0xFFu                         /**< Base mask for AoadLut66 */
#define  AOAD_LUT66_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut66 in register */
#define  GET_AOAD_LUT66_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut66 from register */

// RegAoadLut16.regs.AoadLut67
#define  AOAD_LUT67_GSHIFT                                  24                            /**< Shift for group AoadLut67 */
#define  AOAD_LUT67_GSIZE                                   8                             /**< Size of group AoadLut67 */
#define  AOAD_LUT67_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut67 */

#define  AOAD_LUT67_RSHIFT                                  0                             /**< Shift for AoadLut67 */
#define  AOAD_LUT67_RMASK                                   0x000000FFu                   /**< Mask for AoadLut67 */
#define  AOAD_LUT67_RBMASK                                  0xFFu                         /**< Base mask for AoadLut67 */
#define  AOAD_LUT67_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut67 in register */
#define  GET_AOAD_LUT67_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut67 from register */
/** @} */


/**
 * @name RegAoadLut17
 * @{
 */
// RegAoadLut17.r32
#define  REG_AOAD_LUT17_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut17 */
#define  REG_AOAD_LUT17_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut17 */

#define  AOAD_LUT68_SHIFT                                   0                             /**< Shift for AoadLut68 */
#define  AOAD_LUT68_MASK                                    0x000000FFu                   /**< Mask for AoadLut68 */
#define  AOAD_LUT68_BMASK                                   0xFFu                         /**< Base mask for AoadLut68 */
#define  AOAD_LUT68(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut68 in register */
#define  GET_AOAD_LUT68(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut68 from register */
#define  AOAD_LUT69_SHIFT                                   8                             /**< Shift for AoadLut69 */
#define  AOAD_LUT69_MASK                                    0x0000FF00u                   /**< Mask for AoadLut69 */
#define  AOAD_LUT69_BMASK                                   0xFFu                         /**< Base mask for AoadLut69 */
#define  AOAD_LUT69(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut69 in register */
#define  GET_AOAD_LUT69(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut69 from register */
#define  AOAD_LUT70_SHIFT                                   16                            /**< Shift for AoadLut70 */
#define  AOAD_LUT70_MASK                                    0x00FF0000u                   /**< Mask for AoadLut70 */
#define  AOAD_LUT70_BMASK                                   0xFFu                         /**< Base mask for AoadLut70 */
#define  AOAD_LUT70(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut70 in register */
#define  GET_AOAD_LUT70(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut70 from register */
#define  AOAD_LUT71_SHIFT                                   24                            /**< Shift for AoadLut71 */
#define  AOAD_LUT71_MASK                                    0xFF000000u                   /**< Mask for AoadLut71 */
#define  AOAD_LUT71_BMASK                                   0xFFu                         /**< Base mask for AoadLut71 */
#define  AOAD_LUT71(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut71 in register */
#define  GET_AOAD_LUT71(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut71 from register */

// RegAoadLut17.regs.AoadLut68
#define  AOAD_LUT68_GSHIFT                                  0                             /**< Shift for group AoadLut68 */
#define  AOAD_LUT68_GSIZE                                   8                             /**< Size of group AoadLut68 */
#define  AOAD_LUT68_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut68 */

#define  AOAD_LUT68_RSHIFT                                  0                             /**< Shift for AoadLut68 */
#define  AOAD_LUT68_RMASK                                   0x000000FFu                   /**< Mask for AoadLut68 */
#define  AOAD_LUT68_RBMASK                                  0xFFu                         /**< Base mask for AoadLut68 */
#define  AOAD_LUT68_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut68 in register */
#define  GET_AOAD_LUT68_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut68 from register */

// RegAoadLut17.regs.AoadLut69
#define  AOAD_LUT69_GSHIFT                                  8                             /**< Shift for group AoadLut69 */
#define  AOAD_LUT69_GSIZE                                   8                             /**< Size of group AoadLut69 */
#define  AOAD_LUT69_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut69 */

#define  AOAD_LUT69_RSHIFT                                  0                             /**< Shift for AoadLut69 */
#define  AOAD_LUT69_RMASK                                   0x000000FFu                   /**< Mask for AoadLut69 */
#define  AOAD_LUT69_RBMASK                                  0xFFu                         /**< Base mask for AoadLut69 */
#define  AOAD_LUT69_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut69 in register */
#define  GET_AOAD_LUT69_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut69 from register */

// RegAoadLut17.regs.AoadLut70
#define  AOAD_LUT70_GSHIFT                                  16                            /**< Shift for group AoadLut70 */
#define  AOAD_LUT70_GSIZE                                   8                             /**< Size of group AoadLut70 */
#define  AOAD_LUT70_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut70 */

#define  AOAD_LUT70_RSHIFT                                  0                             /**< Shift for AoadLut70 */
#define  AOAD_LUT70_RMASK                                   0x000000FFu                   /**< Mask for AoadLut70 */
#define  AOAD_LUT70_RBMASK                                  0xFFu                         /**< Base mask for AoadLut70 */
#define  AOAD_LUT70_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut70 in register */
#define  GET_AOAD_LUT70_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut70 from register */

// RegAoadLut17.regs.AoadLut71
#define  AOAD_LUT71_GSHIFT                                  24                            /**< Shift for group AoadLut71 */
#define  AOAD_LUT71_GSIZE                                   8                             /**< Size of group AoadLut71 */
#define  AOAD_LUT71_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut71 */

#define  AOAD_LUT71_RSHIFT                                  0                             /**< Shift for AoadLut71 */
#define  AOAD_LUT71_RMASK                                   0x000000FFu                   /**< Mask for AoadLut71 */
#define  AOAD_LUT71_RBMASK                                  0xFFu                         /**< Base mask for AoadLut71 */
#define  AOAD_LUT71_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut71 in register */
#define  GET_AOAD_LUT71_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut71 from register */
/** @} */


/**
 * @name RegAoadLut18
 * @{
 */
// RegAoadLut18.r32
#define  REG_AOAD_LUT18_RESET_VALUE                         0x00000000u                   /**< Reset value of RegAoadLut18 */
#define  REG_AOAD_LUT18_MASK                                0xFFFFFFFFu                   /**< Mask for RegAoadLut18 */

#define  AOAD_LUT72_SHIFT                                   0                             /**< Shift for AoadLut72 */
#define  AOAD_LUT72_MASK                                    0x000000FFu                   /**< Mask for AoadLut72 */
#define  AOAD_LUT72_BMASK                                   0xFFu                         /**< Base mask for AoadLut72 */
#define  AOAD_LUT72(x)                                      (((x)&0xFFu)<<0)              /**< Set AoadLut72 in register */
#define  GET_AOAD_LUT72(reg)                                (((reg)>>0)&0xFFu)            /**< Get AoadLut72 from register */
#define  AOAD_LUT73_SHIFT                                   8                             /**< Shift for AoadLut73 */
#define  AOAD_LUT73_MASK                                    0x0000FF00u                   /**< Mask for AoadLut73 */
#define  AOAD_LUT73_BMASK                                   0xFFu                         /**< Base mask for AoadLut73 */
#define  AOAD_LUT73(x)                                      (((x)&0xFFu)<<8)              /**< Set AoadLut73 in register */
#define  GET_AOAD_LUT73(reg)                                (((reg)>>8)&0xFFu)            /**< Get AoadLut73 from register */
#define  AOAD_LUT74_SHIFT                                   16                            /**< Shift for AoadLut74 */
#define  AOAD_LUT74_MASK                                    0x00FF0000u                   /**< Mask for AoadLut74 */
#define  AOAD_LUT74_BMASK                                   0xFFu                         /**< Base mask for AoadLut74 */
#define  AOAD_LUT74(x)                                      (((x)&0xFFu)<<16)             /**< Set AoadLut74 in register */
#define  GET_AOAD_LUT74(reg)                                (((reg)>>16)&0xFFu)           /**< Get AoadLut74 from register */
#define  AOAD_LUT75_SHIFT                                   24                            /**< Shift for AoadLut75 */
#define  AOAD_LUT75_MASK                                    0xFF000000u                   /**< Mask for AoadLut75 */
#define  AOAD_LUT75_BMASK                                   0xFFu                         /**< Base mask for AoadLut75 */
#define  AOAD_LUT75(x)                                      (((x)&0xFFu)<<24)             /**< Set AoadLut75 in register */
#define  GET_AOAD_LUT75(reg)                                (((reg)>>24)&0xFFu)           /**< Get AoadLut75 from register */

// RegAoadLut18.regs.AoadLut72
#define  AOAD_LUT72_GSHIFT                                  0                             /**< Shift for group AoadLut72 */
#define  AOAD_LUT72_GSIZE                                   8                             /**< Size of group AoadLut72 */
#define  AOAD_LUT72_GMASK                                   0x000000FFu                   /**< Mask for group AoadLut72 */

#define  AOAD_LUT72_RSHIFT                                  0                             /**< Shift for AoadLut72 */
#define  AOAD_LUT72_RMASK                                   0x000000FFu                   /**< Mask for AoadLut72 */
#define  AOAD_LUT72_RBMASK                                  0xFFu                         /**< Base mask for AoadLut72 */
#define  AOAD_LUT72_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut72 in register */
#define  GET_AOAD_LUT72_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut72 from register */

// RegAoadLut18.regs.AoadLut73
#define  AOAD_LUT73_GSHIFT                                  8                             /**< Shift for group AoadLut73 */
#define  AOAD_LUT73_GSIZE                                   8                             /**< Size of group AoadLut73 */
#define  AOAD_LUT73_GMASK                                   0x0000FF00u                   /**< Mask for group AoadLut73 */

#define  AOAD_LUT73_RSHIFT                                  0                             /**< Shift for AoadLut73 */
#define  AOAD_LUT73_RMASK                                   0x000000FFu                   /**< Mask for AoadLut73 */
#define  AOAD_LUT73_RBMASK                                  0xFFu                         /**< Base mask for AoadLut73 */
#define  AOAD_LUT73_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut73 in register */
#define  GET_AOAD_LUT73_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut73 from register */

// RegAoadLut18.regs.AoadLut74
#define  AOAD_LUT74_GSHIFT                                  16                            /**< Shift for group AoadLut74 */
#define  AOAD_LUT74_GSIZE                                   8                             /**< Size of group AoadLut74 */
#define  AOAD_LUT74_GMASK                                   0x00FF0000u                   /**< Mask for group AoadLut74 */

#define  AOAD_LUT74_RSHIFT                                  0                             /**< Shift for AoadLut74 */
#define  AOAD_LUT74_RMASK                                   0x000000FFu                   /**< Mask for AoadLut74 */
#define  AOAD_LUT74_RBMASK                                  0xFFu                         /**< Base mask for AoadLut74 */
#define  AOAD_LUT74_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut74 in register */
#define  GET_AOAD_LUT74_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut74 from register */

// RegAoadLut18.regs.AoadLut75
#define  AOAD_LUT75_GSHIFT                                  24                            /**< Shift for group AoadLut75 */
#define  AOAD_LUT75_GSIZE                                   8                             /**< Size of group AoadLut75 */
#define  AOAD_LUT75_GMASK                                   0xFF000000u                   /**< Mask for group AoadLut75 */

#define  AOAD_LUT75_RSHIFT                                  0                             /**< Shift for AoadLut75 */
#define  AOAD_LUT75_RMASK                                   0x000000FFu                   /**< Mask for AoadLut75 */
#define  AOAD_LUT75_RBMASK                                  0xFFu                         /**< Base mask for AoadLut75 */
#define  AOAD_LUT75_R(x)                                    (((x)&0xFFu)<<0)              /**< Set AoadLut75 in register */
#define  GET_AOAD_LUT75_R(reg)                              (((reg)>>0)&0xFFu)            /**< Get AoadLut75 from register */
/** @} */



/** @} End of group AoADMatrix_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*T9305_AOAD_MATRIX_H */
