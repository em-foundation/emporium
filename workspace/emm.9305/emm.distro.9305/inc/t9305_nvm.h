////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_nvm.h
///
/// @project    T9305
///
/// @brief      NVM register and bit field definitions
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

#ifndef _T9305_NVM_H
#define _T9305_NVM_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup NVM_Registers NVM Register Map - registers
 * @{
 ******************************************************************************/


/** NVM control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmCtrl_t;


/** NVM Status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmSts_t;


/** NVM command parameters */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  NvmPageNum;                                /**< NVM page number to erase */
        uint8_t  NvmWriteSize;                              /**< Number of words to write from buffer - max size 8 */
        uint8_t  NvmTargetArea;                             /**< Target area for write and erase page operation: 0 = main area, 1 = information area. */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegNvmCmdPrms_t;


/** NVM address to write */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmAddr_t;


/** NVM write/erase operation timing */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmTime_t;


/** NVM data buffer - word 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer0_t;


/** NVM data buffer - word 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer1_t;


/** NVM data buffer - word 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer2_t;


/** NVM data buffer - word 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer3_t;


/** NVM data buffer - word 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer4_t;


/** NVM data buffer - word 5 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer5_t;


/** NVM data buffer - word 6 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer6_t;


/** NVM data buffer - word 7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmBufer7_t;


/** Nvm test mode control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint16_t NvmTmVal;                                  /**< NVM test mode values */
        uint16_t NvmTmEn;                                   /**< NVM test mode enables */
    } regs;
} RegNvmTmCtrl0_t;


/** Nvm test mode control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmTmCtrl1_t;


/** NVM mass read configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  NvmMrStartPage;                            /**< Mass read start page of the NVM block */
        uint8_t  NvmMrStopPage;                             /**< Mass read stop page of the NVM block */
        uint8_t  NvmMrCycleLenght;                          /**< Number of clock cycles for one read, 0 - one cycle, 1 - two cycles, 15 - 16 cycles */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegNvmMrCfg_t;


/** NVM mass read status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegNvmMrSts_t;

/** @} end of group NVM_Regs */



/***************************************************************************//**
 * @defgroup NVM_RegMap NVM Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __O   RegNvmCtrl_t                                      RegNvmCtrl;                   /**< NVM control */
    __I   RegNvmSts_t                                       RegNvmSts;                    /**< NVM Status */
    __IO  RegNvmCmdPrms_t                                   RegNvmCmdPrms;                /**< NVM command parameters */
    __IO  RegNvmAddr_t                                      RegNvmAddr;                   /**< NVM address to write */
    __IO  RegNvmTime_t                                      RegNvmTime;                   /**< NVM write/erase operation timing */
    __IO  RegNvmBufer0_t                                    RegNvmBufer0;                 /**< NVM data buffer - word 0 */
    __IO  RegNvmBufer1_t                                    RegNvmBufer1;                 /**< NVM data buffer - word 1 */
    __IO  RegNvmBufer2_t                                    RegNvmBufer2;                 /**< NVM data buffer - word 2 */
    __IO  RegNvmBufer3_t                                    RegNvmBufer3;                 /**< NVM data buffer - word 3 */
    __IO  RegNvmBufer4_t                                    RegNvmBufer4;                 /**< NVM data buffer - word 4 */
    __IO  RegNvmBufer5_t                                    RegNvmBufer5;                 /**< NVM data buffer - word 5 */
    __IO  RegNvmBufer6_t                                    RegNvmBufer6;                 /**< NVM data buffer - word 6 */
    __IO  RegNvmBufer7_t                                    RegNvmBufer7;                 /**< NVM data buffer - word 7 */
    __IO  RegNvmTmCtrl0_t                                   RegNvmTmCtrl0;                /**< Nvm test mode control */
    __IO  RegNvmTmCtrl1_t                                   RegNvmTmCtrl1;                /**< Nvm test mode control */
    __IO  RegNvmMrCfg_t                                     RegNvmMrCfg;                  /**< NVM mass read configuration */
    __I   RegNvmMrSts_t                                     RegNvmMrSts;                  /**< NVM mass read status */
} NVM_RegMap_t;

/** @} end of group NVM_RegMap */



/***************************************************************************//**
 * @defgroup NVM_BitFields NVM bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegNvmCtrl
 * @{
 */
// RegNvmCtrl.r32
#define  REG_NVM_CTRL_RESET_VALUE                           0x00000000u                   /**< Reset value of RegNvmCtrl */
#define  REG_NVM_CTRL_MASK                                  0x0000001Fu                   /**< Mask for RegNvmCtrl */

#define  NVM_WRITE_SHIFT                                    0                             /**< Shift for NvmWrite */
#define  NVM_WRITE_MASK                                     0x00000001u                   /**< Mask for NvmWrite */
#define  NVM_WRITE_BMASK                                    0x1u                          /**< Base mask for NvmWrite */
#define  NVM_WRITE(x)                                       (((x)&0x1u)<<0)               /**< Set NvmWrite in register */
#define  GET_NVM_WRITE(reg)                                 (((reg)>>0)&0x1u)             /**< Get NvmWrite from register */
#define  NVM_ERASE_PAGE_SHIFT                               1                             /**< Shift for NvmErasePage */
#define  NVM_ERASE_PAGE_MASK                                0x00000002u                   /**< Mask for NvmErasePage */
#define  NVM_ERASE_PAGE_BMASK                               0x1u                          /**< Base mask for NvmErasePage */
#define  NVM_ERASE_PAGE(x)                                  (((x)&0x1u)<<1)               /**< Set NvmErasePage in register */
#define  GET_NVM_ERASE_PAGE(reg)                            (((reg)>>1)&0x1u)             /**< Get NvmErasePage from register */
#define  NVM_ERASE_MAIN_SHIFT                               2                             /**< Shift for NvmEraseMain */
#define  NVM_ERASE_MAIN_MASK                                0x00000004u                   /**< Mask for NvmEraseMain */
#define  NVM_ERASE_MAIN_BMASK                               0x1u                          /**< Base mask for NvmEraseMain */
#define  NVM_ERASE_MAIN(x)                                  (((x)&0x1u)<<2)               /**< Set NvmEraseMain in register */
#define  GET_NVM_ERASE_MAIN(reg)                            (((reg)>>2)&0x1u)             /**< Get NvmEraseMain from register */
#define  NVM_ERASE_FULL_SHIFT                               3                             /**< Shift for NvmEraseFull */
#define  NVM_ERASE_FULL_MASK                                0x00000008u                   /**< Mask for NvmEraseFull */
#define  NVM_ERASE_FULL_BMASK                               0x1u                          /**< Base mask for NvmEraseFull */
#define  NVM_ERASE_FULL(x)                                  (((x)&0x1u)<<3)               /**< Set NvmEraseFull in register */
#define  GET_NVM_ERASE_FULL(reg)                            (((reg)>>3)&0x1u)             /**< Get NvmEraseFull from register */
#define  NVM_MASS_READ_SHIFT                                4                             /**< Shift for NvmMassRead */
#define  NVM_MASS_READ_MASK                                 0x00000010u                   /**< Mask for NvmMassRead */
#define  NVM_MASS_READ_BMASK                                0x1u                          /**< Base mask for NvmMassRead */
#define  NVM_MASS_READ(x)                                   (((x)&0x1u)<<4)               /**< Set NvmMassRead in register */
#define  GET_NVM_MASS_READ(reg)                             (((reg)>>4)&0x1u)             /**< Get NvmMassRead from register */
/** @} */


/**
 * @name RegNvmSts
 * @{
 */
// RegNvmSts.r32
#define  REG_NVM_STS_RESET_VALUE                            0x00000000u                   /**< Reset value of RegNvmSts */
#define  REG_NVM_STS_MASK                                   0x0003001Fu                   /**< Mask for RegNvmSts */

#define  NVM_STS_WRITE_SHIFT                                0                             /**< Shift for NvmStsWrite */
#define  NVM_STS_WRITE_MASK                                 0x00000001u                   /**< Mask for NvmStsWrite */
#define  NVM_STS_WRITE_BMASK                                0x1u                          /**< Base mask for NvmStsWrite */
#define  NVM_STS_WRITE(x)                                   (((x)&0x1u)<<0)               /**< Set NvmStsWrite in register */
#define  GET_NVM_STS_WRITE(reg)                             (((reg)>>0)&0x1u)             /**< Get NvmStsWrite from register */
#define  NVM_STS_ERASE_PAGE_SHIFT                           1                             /**< Shift for NvmStsErasePage */
#define  NVM_STS_ERASE_PAGE_MASK                            0x00000002u                   /**< Mask for NvmStsErasePage */
#define  NVM_STS_ERASE_PAGE_BMASK                           0x1u                          /**< Base mask for NvmStsErasePage */
#define  NVM_STS_ERASE_PAGE(x)                              (((x)&0x1u)<<1)               /**< Set NvmStsErasePage in register */
#define  GET_NVM_STS_ERASE_PAGE(reg)                        (((reg)>>1)&0x1u)             /**< Get NvmStsErasePage from register */
#define  NVM_STS_ERASE_MAIN_SHIFT                           2                             /**< Shift for NvmStsEraseMain */
#define  NVM_STS_ERASE_MAIN_MASK                            0x00000004u                   /**< Mask for NvmStsEraseMain */
#define  NVM_STS_ERASE_MAIN_BMASK                           0x1u                          /**< Base mask for NvmStsEraseMain */
#define  NVM_STS_ERASE_MAIN(x)                              (((x)&0x1u)<<2)               /**< Set NvmStsEraseMain in register */
#define  GET_NVM_STS_ERASE_MAIN(reg)                        (((reg)>>2)&0x1u)             /**< Get NvmStsEraseMain from register */
#define  NVM_STS_ERASE_FULL_SHIFT                           3                             /**< Shift for NvmStsEraseFull */
#define  NVM_STS_ERASE_FULL_MASK                            0x00000008u                   /**< Mask for NvmStsEraseFull */
#define  NVM_STS_ERASE_FULL_BMASK                           0x1u                          /**< Base mask for NvmStsEraseFull */
#define  NVM_STS_ERASE_FULL(x)                              (((x)&0x1u)<<3)               /**< Set NvmStsEraseFull in register */
#define  GET_NVM_STS_ERASE_FULL(reg)                        (((reg)>>3)&0x1u)             /**< Get NvmStsEraseFull from register */
#define  NVM_STS_MASS_READ_SHIFT                            4                             /**< Shift for NvmStsMassRead */
#define  NVM_STS_MASS_READ_MASK                             0x00000010u                   /**< Mask for NvmStsMassRead */
#define  NVM_STS_MASS_READ_BMASK                            0x1u                          /**< Base mask for NvmStsMassRead */
#define  NVM_STS_MASS_READ(x)                               (((x)&0x1u)<<4)               /**< Set NvmStsMassRead in register */
#define  GET_NVM_STS_MASS_READ(reg)                         (((reg)>>4)&0x1u)             /**< Get NvmStsMassRead from register */
#define  NVM_STS_ERROR_LOCK_SHIFT                           16                            /**< Shift for NvmStsErrorLock */
#define  NVM_STS_ERROR_LOCK_MASK                            0x00010000u                   /**< Mask for NvmStsErrorLock */
#define  NVM_STS_ERROR_LOCK_BMASK                           0x1u                          /**< Base mask for NvmStsErrorLock */
#define  NVM_STS_ERROR_LOCK(x)                              (((x)&0x1u)<<16)              /**< Set NvmStsErrorLock in register */
#define  GET_NVM_STS_ERROR_LOCK(reg)                        (((reg)>>16)&0x1u)            /**< Get NvmStsErrorLock from register */
#define  NVM_STS_ERROR_BROWNOUT_SHIFT                       17                            /**< Shift for NvmStsErrorBrownout */
#define  NVM_STS_ERROR_BROWNOUT_MASK                        0x00020000u                   /**< Mask for NvmStsErrorBrownout */
#define  NVM_STS_ERROR_BROWNOUT_BMASK                       0x1u                          /**< Base mask for NvmStsErrorBrownout */
#define  NVM_STS_ERROR_BROWNOUT(x)                          (((x)&0x1u)<<17)              /**< Set NvmStsErrorBrownout in register */
#define  GET_NVM_STS_ERROR_BROWNOUT(reg)                    (((reg)>>17)&0x1u)            /**< Get NvmStsErrorBrownout from register */
/** @} */


/**
 * @name RegNvmCmdPrms
 * @{
 */
// RegNvmCmdPrms.r32
#define  REG_NVM_CMD_PRMS_RESET_VALUE                       0x00000100u                   /**< Reset value of RegNvmCmdPrms */
#define  REG_NVM_CMD_PRMS_MASK                              0x00010F3Fu                   /**< Mask for RegNvmCmdPrms */

#define  NVM_PAGE_NUM_SHIFT                                 0                             /**< Shift for NvmPageNum */
#define  NVM_PAGE_NUM_MASK                                  0x0000003Fu                   /**< Mask for NvmPageNum */
#define  NVM_PAGE_NUM_BMASK                                 0x3Fu                         /**< Base mask for NvmPageNum */
#define  NVM_PAGE_NUM(x)                                    (((x)&0x3Fu)<<0)              /**< Set NvmPageNum in register */
#define  GET_NVM_PAGE_NUM(reg)                              (((reg)>>0)&0x3Fu)            /**< Get NvmPageNum from register */
#define  NVM_WRITE_SIZE_SHIFT                               8                             /**< Shift for NvmWriteSize */
#define  NVM_WRITE_SIZE_MASK                                0x00000F00u                   /**< Mask for NvmWriteSize */
#define  NVM_WRITE_SIZE_BMASK                               0xFu                          /**< Base mask for NvmWriteSize */
#define  NVM_WRITE_SIZE(x)                                  (((x)&0xFu)<<8)               /**< Set NvmWriteSize in register */
#define  GET_NVM_WRITE_SIZE(reg)                            (((reg)>>8)&0xFu)             /**< Get NvmWriteSize from register */
#define  NVM_TARGET_AREA_SHIFT                              16                            /**< Shift for NvmTargetArea */
#define  NVM_TARGET_AREA_MASK                               0x00010000u                   /**< Mask for NvmTargetArea */
#define  NVM_TARGET_AREA_BMASK                              0x1u                          /**< Base mask for NvmTargetArea */
#define  NVM_TARGET_AREA(x)                                 (((x)&0x1u)<<16)              /**< Set NvmTargetArea in register */
#define  GET_NVM_TARGET_AREA(reg)                           (((reg)>>16)&0x1u)            /**< Get NvmTargetArea from register */

// RegNvmCmdPrms.regs.NvmPageNum
#define  NVM_PAGE_NUM_GSHIFT                                0                             /**< Shift for group NvmPageNum */
#define  NVM_PAGE_NUM_GSIZE                                 8                             /**< Size of group NvmPageNum */
#define  NVM_PAGE_NUM_GMASK                                 0x000000FFu                   /**< Mask for group NvmPageNum */

#define  NVM_PAGE_NUM_RSHIFT                                0                             /**< Shift for NvmPageNum */
#define  NVM_PAGE_NUM_RMASK                                 0x0000003Fu                   /**< Mask for NvmPageNum */
#define  NVM_PAGE_NUM_RBMASK                                0x3Fu                         /**< Base mask for NvmPageNum */
#define  NVM_PAGE_NUM_R(x)                                  (((x)&0x3Fu)<<0)              /**< Set NvmPageNum in register */
#define  GET_NVM_PAGE_NUM_R(reg)                            (((reg)>>0)&0x3Fu)            /**< Get NvmPageNum from register */

// RegNvmCmdPrms.regs.NvmWriteSize
#define  NVM_WRITE_SIZE_GSHIFT                              8                             /**< Shift for group NvmWriteSize */
#define  NVM_WRITE_SIZE_GSIZE                               8                             /**< Size of group NvmWriteSize */
#define  NVM_WRITE_SIZE_GMASK                               0x0000FF00u                   /**< Mask for group NvmWriteSize */

#define  NVM_WRITE_SIZE_RSHIFT                              0                             /**< Shift for NvmWriteSize */
#define  NVM_WRITE_SIZE_RMASK                               0x0000000Fu                   /**< Mask for NvmWriteSize */
#define  NVM_WRITE_SIZE_RBMASK                              0xFu                          /**< Base mask for NvmWriteSize */
#define  NVM_WRITE_SIZE_R(x)                                (((x)&0xFu)<<0)               /**< Set NvmWriteSize in register */
#define  GET_NVM_WRITE_SIZE_R(reg)                          (((reg)>>0)&0xFu)             /**< Get NvmWriteSize from register */

// RegNvmCmdPrms.regs.NvmTargetArea
#define  NVM_TARGET_AREA_GSHIFT                             16                            /**< Shift for group NvmTargetArea */
#define  NVM_TARGET_AREA_GSIZE                              8                             /**< Size of group NvmTargetArea */
#define  NVM_TARGET_AREA_GMASK                              0x00FF0000u                   /**< Mask for group NvmTargetArea */

#define  NVM_TARGET_AREA_RSHIFT                             0                             /**< Shift for NvmTargetArea */
#define  NVM_TARGET_AREA_RMASK                              0x00000001u                   /**< Mask for NvmTargetArea */
#define  NVM_TARGET_AREA_RBMASK                             0x1u                          /**< Base mask for NvmTargetArea */
#define  NVM_TARGET_AREA_R(x)                               (((x)&0x1u)<<0)               /**< Set NvmTargetArea in register */
#define  GET_NVM_TARGET_AREA_R(reg)                         (((reg)>>0)&0x1u)             /**< Get NvmTargetArea from register */
/** @} */


/**
 * @name RegNvmAddr
 * @{
 */
// RegNvmAddr.r32
#define  REG_NVM_ADDR_RESET_VALUE                           0x00000000u                   /**< Reset value of RegNvmAddr */
#define  REG_NVM_ADDR_MASK                                  0x0001FFFFu                   /**< Mask for RegNvmAddr */

#define  NVM_ADDR_SHIFT                                     0                             /**< Shift for NvmAddr */
#define  NVM_ADDR_MASK                                      0x0001FFFFu                   /**< Mask for NvmAddr */
#define  NVM_ADDR_BMASK                                     0x1FFFFu                      /**< Base mask for NvmAddr */
#define  NVM_ADDR(x)                                        (((x)&0x1FFFFu)<<0)           /**< Set NvmAddr in register */
#define  GET_NVM_ADDR(reg)                                  (((reg)>>0)&0x1FFFFu)         /**< Get NvmAddr from register */
/** @} */


/**
 * @name RegNvmTime
 * @{
 */
// RegNvmTime.r32
#define  REG_NVM_TIME_RESET_VALUE                           0x00000808u                   /**< Reset value of RegNvmTime */
#define  REG_NVM_TIME_MASK                                  0x00000F0Fu                   /**< Mask for RegNvmTime */

#define  NVM_WRITE_TIME_SHIFT                               0                             /**< Shift for NvmWriteTime */
#define  NVM_WRITE_TIME_MASK                                0x0000000Fu                   /**< Mask for NvmWriteTime */
#define  NVM_WRITE_TIME_BMASK                               0xFu                          /**< Base mask for NvmWriteTime */
#define  NVM_WRITE_TIME(x)                                  (((x)&0xFu)<<0)               /**< Set NvmWriteTime in register */
#define  GET_NVM_WRITE_TIME(reg)                            (((reg)>>0)&0xFu)             /**< Get NvmWriteTime from register */
#define  NVM_ERASE_TIME_SHIFT                               8                             /**< Shift for NvmEraseTime */
#define  NVM_ERASE_TIME_MASK                                0x00000F00u                   /**< Mask for NvmEraseTime */
#define  NVM_ERASE_TIME_BMASK                               0xFu                          /**< Base mask for NvmEraseTime */
#define  NVM_ERASE_TIME(x)                                  (((x)&0xFu)<<8)               /**< Set NvmEraseTime in register */
#define  GET_NVM_ERASE_TIME(reg)                            (((reg)>>8)&0xFu)             /**< Get NvmEraseTime from register */
/** @} */


/**
 * @name RegNvmBufer0
 * @{
 */
// RegNvmBufer0.r32
#define  REG_NVM_BUFER0_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer0 */
#define  REG_NVM_BUFER0_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer0 */

#define  NVM_BUFER0_SHIFT                                   0                             /**< Shift for NvmBufer0 */
#define  NVM_BUFER0_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer0 */
#define  NVM_BUFER0_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer0 */
#define  NVM_BUFER0(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer0 in register */
#define  GET_NVM_BUFER0(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer0 from register */
/** @} */


/**
 * @name RegNvmBufer1
 * @{
 */
// RegNvmBufer1.r32
#define  REG_NVM_BUFER1_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer1 */
#define  REG_NVM_BUFER1_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer1 */

#define  NVM_BUFER1_SHIFT                                   0                             /**< Shift for NvmBufer1 */
#define  NVM_BUFER1_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer1 */
#define  NVM_BUFER1_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer1 */
#define  NVM_BUFER1(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer1 in register */
#define  GET_NVM_BUFER1(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer1 from register */
/** @} */


/**
 * @name RegNvmBufer2
 * @{
 */
// RegNvmBufer2.r32
#define  REG_NVM_BUFER2_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer2 */
#define  REG_NVM_BUFER2_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer2 */

#define  NVM_BUFER2_SHIFT                                   0                             /**< Shift for NvmBufer2 */
#define  NVM_BUFER2_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer2 */
#define  NVM_BUFER2_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer2 */
#define  NVM_BUFER2(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer2 in register */
#define  GET_NVM_BUFER2(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer2 from register */
/** @} */


/**
 * @name RegNvmBufer3
 * @{
 */
// RegNvmBufer3.r32
#define  REG_NVM_BUFER3_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer3 */
#define  REG_NVM_BUFER3_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer3 */

#define  NVM_BUFER3_SHIFT                                   0                             /**< Shift for NvmBufer3 */
#define  NVM_BUFER3_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer3 */
#define  NVM_BUFER3_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer3 */
#define  NVM_BUFER3(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer3 in register */
#define  GET_NVM_BUFER3(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer3 from register */
/** @} */


/**
 * @name RegNvmBufer4
 * @{
 */
// RegNvmBufer4.r32
#define  REG_NVM_BUFER4_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer4 */
#define  REG_NVM_BUFER4_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer4 */

#define  NVM_BUFER4_SHIFT                                   0                             /**< Shift for NvmBufer4 */
#define  NVM_BUFER4_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer4 */
#define  NVM_BUFER4_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer4 */
#define  NVM_BUFER4(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer4 in register */
#define  GET_NVM_BUFER4(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer4 from register */
/** @} */


/**
 * @name RegNvmBufer5
 * @{
 */
// RegNvmBufer5.r32
#define  REG_NVM_BUFER5_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer5 */
#define  REG_NVM_BUFER5_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer5 */

#define  NVM_BUFER5_SHIFT                                   0                             /**< Shift for NvmBufer5 */
#define  NVM_BUFER5_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer5 */
#define  NVM_BUFER5_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer5 */
#define  NVM_BUFER5(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer5 in register */
#define  GET_NVM_BUFER5(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer5 from register */
/** @} */


/**
 * @name RegNvmBufer6
 * @{
 */
// RegNvmBufer6.r32
#define  REG_NVM_BUFER6_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer6 */
#define  REG_NVM_BUFER6_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer6 */

#define  NVM_BUFER6_SHIFT                                   0                             /**< Shift for NvmBufer6 */
#define  NVM_BUFER6_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer6 */
#define  NVM_BUFER6_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer6 */
#define  NVM_BUFER6(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer6 in register */
#define  GET_NVM_BUFER6(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer6 from register */
/** @} */


/**
 * @name RegNvmBufer7
 * @{
 */
// RegNvmBufer7.r32
#define  REG_NVM_BUFER7_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmBufer7 */
#define  REG_NVM_BUFER7_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmBufer7 */

#define  NVM_BUFER7_SHIFT                                   0                             /**< Shift for NvmBufer7 */
#define  NVM_BUFER7_MASK                                    0xFFFFFFFFu                   /**< Mask for NvmBufer7 */
#define  NVM_BUFER7_BMASK                                   0xFFFFFFFFu                   /**< Base mask for NvmBufer7 */
#define  NVM_BUFER7(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set NvmBufer7 in register */
#define  GET_NVM_BUFER7(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get NvmBufer7 from register */
/** @} */


/**
 * @name RegNvmTmCtrl0
 * @{
 */
// RegNvmTmCtrl0.r32
#define  REG_NVM_TM_CTRL0_RESET_VALUE                       0x00000000u                   /**< Reset value of RegNvmTmCtrl0 */
#define  REG_NVM_TM_CTRL0_MASK                              0x0EFF06FFu                   /**< Mask for RegNvmTmCtrl0 */

#define  NVM_IFREN1_TM_VAL_SHIFT                            0                             /**< Shift for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL_MASK                             0x00000001u                   /**< Mask for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL_BMASK                            0x1u                          /**< Base mask for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL(x)                               (((x)&0x1u)<<0)               /**< Set NvmIfren1TmVal in register */
#define  GET_NVM_IFREN1_TM_VAL(reg)                         (((reg)>>0)&0x1u)             /**< Get NvmIfren1TmVal from register */
#define  NVM_REDEN_TM_VAL_SHIFT                             1                             /**< Shift for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL_MASK                              0x00000002u                   /**< Mask for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL_BMASK                             0x1u                          /**< Base mask for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL(x)                                (((x)&0x1u)<<1)               /**< Set NvmRedenTmVal in register */
#define  GET_NVM_REDEN_TM_VAL(reg)                          (((reg)>>1)&0x1u)             /**< Get NvmRedenTmVal from register */
#define  NVM_TMR_TM_VAL_SHIFT                               2                             /**< Shift for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL_MASK                                0x00000004u                   /**< Mask for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL_BMASK                               0x1u                          /**< Base mask for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL(x)                                  (((x)&0x1u)<<2)               /**< Set NvmTmrTmVal in register */
#define  GET_NVM_TMR_TM_VAL(reg)                            (((reg)>>2)&0x1u)             /**< Get NvmTmrTmVal from register */
#define  NVM_IFREN_TM_VAL_SHIFT                             3                             /**< Shift for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL_MASK                              0x00000008u                   /**< Mask for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL_BMASK                             0x1u                          /**< Base mask for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL(x)                                (((x)&0x1u)<<3)               /**< Set NvmIfrenTmVal in register */
#define  GET_NVM_IFREN_TM_VAL(reg)                          (((reg)>>3)&0x1u)             /**< Get NvmIfrenTmVal from register */
#define  NVM_NVSTR_TM_VAL_SHIFT                             4                             /**< Shift for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL_MASK                              0x00000010u                   /**< Mask for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL_BMASK                             0x1u                          /**< Base mask for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL(x)                                (((x)&0x1u)<<4)               /**< Set NvmNvstrTmVal in register */
#define  GET_NVM_NVSTR_TM_VAL(reg)                          (((reg)>>4)&0x1u)             /**< Get NvmNvstrTmVal from register */
#define  NVM_PROG_TM_VAL_SHIFT                              5                             /**< Shift for NvmProgTmVal */
#define  NVM_PROG_TM_VAL_MASK                               0x00000020u                   /**< Mask for NvmProgTmVal */
#define  NVM_PROG_TM_VAL_BMASK                              0x1u                          /**< Base mask for NvmProgTmVal */
#define  NVM_PROG_TM_VAL(x)                                 (((x)&0x1u)<<5)               /**< Set NvmProgTmVal in register */
#define  GET_NVM_PROG_TM_VAL(reg)                           (((reg)>>5)&0x1u)             /**< Get NvmProgTmVal from register */
#define  NVM_MAS1_TM_VAL_SHIFT                              6                             /**< Shift for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL_MASK                               0x00000040u                   /**< Mask for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL_BMASK                              0x1u                          /**< Base mask for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL(x)                                 (((x)&0x1u)<<6)               /**< Set NvmMas1TmVal in register */
#define  GET_NVM_MAS1_TM_VAL(reg)                           (((reg)>>6)&0x1u)             /**< Get NvmMas1TmVal from register */
#define  NVM_ERASE_TM_VAL_SHIFT                             7                             /**< Shift for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL_MASK                              0x00000080u                   /**< Mask for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL_BMASK                             0x1u                          /**< Base mask for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL(x)                                (((x)&0x1u)<<7)               /**< Set NvmEraseTmVal in register */
#define  GET_NVM_ERASE_TM_VAL(reg)                          (((reg)>>7)&0x1u)             /**< Get NvmEraseTmVal from register */
#define  NVM_YE_TM_VAL_SHIFT                                9                             /**< Shift for NvmYeTmVal */
#define  NVM_YE_TM_VAL_MASK                                 0x00000200u                   /**< Mask for NvmYeTmVal */
#define  NVM_YE_TM_VAL_BMASK                                0x1u                          /**< Base mask for NvmYeTmVal */
#define  NVM_YE_TM_VAL(x)                                   (((x)&0x1u)<<9)               /**< Set NvmYeTmVal in register */
#define  GET_NVM_YE_TM_VAL(reg)                             (((reg)>>9)&0x1u)             /**< Get NvmYeTmVal from register */
#define  NVM_XE_TM_VAL_SHIFT                                10                            /**< Shift for NvmXeTmVal */
#define  NVM_XE_TM_VAL_MASK                                 0x00000400u                   /**< Mask for NvmXeTmVal */
#define  NVM_XE_TM_VAL_BMASK                                0x1u                          /**< Base mask for NvmXeTmVal */
#define  NVM_XE_TM_VAL(x)                                   (((x)&0x1u)<<10)              /**< Set NvmXeTmVal in register */
#define  GET_NVM_XE_TM_VAL(reg)                             (((reg)>>10)&0x1u)            /**< Get NvmXeTmVal from register */
#define  NVM_IFREN1_TM_EN_SHIFT                             16                            /**< Shift for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN_MASK                              0x00010000u                   /**< Mask for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN_BMASK                             0x1u                          /**< Base mask for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN(x)                                (((x)&0x1u)<<16)              /**< Set NvmIfren1TmEn in register */
#define  GET_NVM_IFREN1_TM_EN(reg)                          (((reg)>>16)&0x1u)            /**< Get NvmIfren1TmEn from register */
#define  NVM_REDEN_TM_EN_SHIFT                              17                            /**< Shift for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN_MASK                               0x00020000u                   /**< Mask for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN_BMASK                              0x1u                          /**< Base mask for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN(x)                                 (((x)&0x1u)<<17)              /**< Set NvmRedenTmEn in register */
#define  GET_NVM_REDEN_TM_EN(reg)                           (((reg)>>17)&0x1u)            /**< Get NvmRedenTmEn from register */
#define  NVM_TMR_TM_EN_SHIFT                                18                            /**< Shift for NvmTmrTmEn */
#define  NVM_TMR_TM_EN_MASK                                 0x00040000u                   /**< Mask for NvmTmrTmEn */
#define  NVM_TMR_TM_EN_BMASK                                0x1u                          /**< Base mask for NvmTmrTmEn */
#define  NVM_TMR_TM_EN(x)                                   (((x)&0x1u)<<18)              /**< Set NvmTmrTmEn in register */
#define  GET_NVM_TMR_TM_EN(reg)                             (((reg)>>18)&0x1u)            /**< Get NvmTmrTmEn from register */
#define  NVM_IFREN_TM_EN_SHIFT                              19                            /**< Shift for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN_MASK                               0x00080000u                   /**< Mask for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN_BMASK                              0x1u                          /**< Base mask for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN(x)                                 (((x)&0x1u)<<19)              /**< Set NvmIfrenTmEn in register */
#define  GET_NVM_IFREN_TM_EN(reg)                           (((reg)>>19)&0x1u)            /**< Get NvmIfrenTmEn from register */
#define  NVM_NVSTR_TM_EN_SHIFT                              20                            /**< Shift for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN_MASK                               0x00100000u                   /**< Mask for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN_BMASK                              0x1u                          /**< Base mask for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN(x)                                 (((x)&0x1u)<<20)              /**< Set NvmNvstrTmEn in register */
#define  GET_NVM_NVSTR_TM_EN(reg)                           (((reg)>>20)&0x1u)            /**< Get NvmNvstrTmEn from register */
#define  NVM_PROG_TM_EN_SHIFT                               21                            /**< Shift for NvmProgTmEn */
#define  NVM_PROG_TM_EN_MASK                                0x00200000u                   /**< Mask for NvmProgTmEn */
#define  NVM_PROG_TM_EN_BMASK                               0x1u                          /**< Base mask for NvmProgTmEn */
#define  NVM_PROG_TM_EN(x)                                  (((x)&0x1u)<<21)              /**< Set NvmProgTmEn in register */
#define  GET_NVM_PROG_TM_EN(reg)                            (((reg)>>21)&0x1u)            /**< Get NvmProgTmEn from register */
#define  NVM_MAS1_TM_EN_SHIFT                               22                            /**< Shift for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN_MASK                                0x00400000u                   /**< Mask for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN_BMASK                               0x1u                          /**< Base mask for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN(x)                                  (((x)&0x1u)<<22)              /**< Set NvmMas1TmEn in register */
#define  GET_NVM_MAS1_TM_EN(reg)                            (((reg)>>22)&0x1u)            /**< Get NvmMas1TmEn from register */
#define  NVM_ERASE_TM_EN_SHIFT                              23                            /**< Shift for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN_MASK                               0x00800000u                   /**< Mask for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN_BMASK                              0x1u                          /**< Base mask for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN(x)                                 (((x)&0x1u)<<23)              /**< Set NvmEraseTmEn in register */
#define  GET_NVM_ERASE_TM_EN(reg)                           (((reg)>>23)&0x1u)            /**< Get NvmEraseTmEn from register */
#define  NVM_YE_TM_EN_SHIFT                                 25                            /**< Shift for NvmYeTmEn */
#define  NVM_YE_TM_EN_MASK                                  0x02000000u                   /**< Mask for NvmYeTmEn */
#define  NVM_YE_TM_EN_BMASK                                 0x1u                          /**< Base mask for NvmYeTmEn */
#define  NVM_YE_TM_EN(x)                                    (((x)&0x1u)<<25)              /**< Set NvmYeTmEn in register */
#define  GET_NVM_YE_TM_EN(reg)                              (((reg)>>25)&0x1u)            /**< Get NvmYeTmEn from register */
#define  NVM_XE_TM_EN_SHIFT                                 26                            /**< Shift for NvmXeTmEn */
#define  NVM_XE_TM_EN_MASK                                  0x04000000u                   /**< Mask for NvmXeTmEn */
#define  NVM_XE_TM_EN_BMASK                                 0x1u                          /**< Base mask for NvmXeTmEn */
#define  NVM_XE_TM_EN(x)                                    (((x)&0x1u)<<26)              /**< Set NvmXeTmEn in register */
#define  GET_NVM_XE_TM_EN(reg)                              (((reg)>>26)&0x1u)            /**< Get NvmXeTmEn from register */
#define  NVM_ADDR_DIN_SEL_TM_SHIFT                          27                            /**< Shift for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM_MASK                           0x08000000u                   /**< Mask for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM_BMASK                          0x1u                          /**< Base mask for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM(x)                             (((x)&0x1u)<<27)              /**< Set NvmAddrDinSelTm in register */
#define  GET_NVM_ADDR_DIN_SEL_TM(reg)                       (((reg)>>27)&0x1u)            /**< Get NvmAddrDinSelTm from register */

// RegNvmTmCtrl0.regs.NvmTmVal
#define  NVM_TM_VAL_GSHIFT                                  0                             /**< Shift for group NvmTmVal */
#define  NVM_TM_VAL_GSIZE                                   16                            /**< Size of group NvmTmVal */
#define  NVM_TM_VAL_GMASK                                   0x0000FFFFu                   /**< Mask for group NvmTmVal */

#define  NVM_IFREN1_TM_VAL_RSHIFT                           0                             /**< Shift for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL_RMASK                            0x0001u                       /**< Mask for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL_RBMASK                           0x1u                          /**< Base mask for NvmIfren1TmVal */
#define  NVM_IFREN1_TM_VAL_R(x)                             (((x)&0x1u)<<0)               /**< Set NvmIfren1TmVal in register */
#define  GET_NVM_IFREN1_TM_VAL_R(reg)                       (((reg)>>0)&0x1u)             /**< Get NvmIfren1TmVal from register */
#define  NVM_REDEN_TM_VAL_RSHIFT                            1                             /**< Shift for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL_RMASK                             0x0002u                       /**< Mask for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL_RBMASK                            0x1u                          /**< Base mask for NvmRedenTmVal */
#define  NVM_REDEN_TM_VAL_R(x)                              (((x)&0x1u)<<1)               /**< Set NvmRedenTmVal in register */
#define  GET_NVM_REDEN_TM_VAL_R(reg)                        (((reg)>>1)&0x1u)             /**< Get NvmRedenTmVal from register */
#define  NVM_TMR_TM_VAL_RSHIFT                              2                             /**< Shift for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL_RMASK                               0x0004u                       /**< Mask for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL_RBMASK                              0x1u                          /**< Base mask for NvmTmrTmVal */
#define  NVM_TMR_TM_VAL_R(x)                                (((x)&0x1u)<<2)               /**< Set NvmTmrTmVal in register */
#define  GET_NVM_TMR_TM_VAL_R(reg)                          (((reg)>>2)&0x1u)             /**< Get NvmTmrTmVal from register */
#define  NVM_IFREN_TM_VAL_RSHIFT                            3                             /**< Shift for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL_RMASK                             0x0008u                       /**< Mask for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL_RBMASK                            0x1u                          /**< Base mask for NvmIfrenTmVal */
#define  NVM_IFREN_TM_VAL_R(x)                              (((x)&0x1u)<<3)               /**< Set NvmIfrenTmVal in register */
#define  GET_NVM_IFREN_TM_VAL_R(reg)                        (((reg)>>3)&0x1u)             /**< Get NvmIfrenTmVal from register */
#define  NVM_NVSTR_TM_VAL_RSHIFT                            4                             /**< Shift for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL_RMASK                             0x0010u                       /**< Mask for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL_RBMASK                            0x1u                          /**< Base mask for NvmNvstrTmVal */
#define  NVM_NVSTR_TM_VAL_R(x)                              (((x)&0x1u)<<4)               /**< Set NvmNvstrTmVal in register */
#define  GET_NVM_NVSTR_TM_VAL_R(reg)                        (((reg)>>4)&0x1u)             /**< Get NvmNvstrTmVal from register */
#define  NVM_PROG_TM_VAL_RSHIFT                             5                             /**< Shift for NvmProgTmVal */
#define  NVM_PROG_TM_VAL_RMASK                              0x0020u                       /**< Mask for NvmProgTmVal */
#define  NVM_PROG_TM_VAL_RBMASK                             0x1u                          /**< Base mask for NvmProgTmVal */
#define  NVM_PROG_TM_VAL_R(x)                               (((x)&0x1u)<<5)               /**< Set NvmProgTmVal in register */
#define  GET_NVM_PROG_TM_VAL_R(reg)                         (((reg)>>5)&0x1u)             /**< Get NvmProgTmVal from register */
#define  NVM_MAS1_TM_VAL_RSHIFT                             6                             /**< Shift for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL_RMASK                              0x0040u                       /**< Mask for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL_RBMASK                             0x1u                          /**< Base mask for NvmMas1TmVal */
#define  NVM_MAS1_TM_VAL_R(x)                               (((x)&0x1u)<<6)               /**< Set NvmMas1TmVal in register */
#define  GET_NVM_MAS1_TM_VAL_R(reg)                         (((reg)>>6)&0x1u)             /**< Get NvmMas1TmVal from register */
#define  NVM_ERASE_TM_VAL_RSHIFT                            7                             /**< Shift for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL_RMASK                             0x0080u                       /**< Mask for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL_RBMASK                            0x1u                          /**< Base mask for NvmEraseTmVal */
#define  NVM_ERASE_TM_VAL_R(x)                              (((x)&0x1u)<<7)               /**< Set NvmEraseTmVal in register */
#define  GET_NVM_ERASE_TM_VAL_R(reg)                        (((reg)>>7)&0x1u)             /**< Get NvmEraseTmVal from register */
#define  NVM_YE_TM_VAL_RSHIFT                               9                             /**< Shift for NvmYeTmVal */
#define  NVM_YE_TM_VAL_RMASK                                0x0200u                       /**< Mask for NvmYeTmVal */
#define  NVM_YE_TM_VAL_RBMASK                               0x1u                          /**< Base mask for NvmYeTmVal */
#define  NVM_YE_TM_VAL_R(x)                                 (((x)&0x1u)<<9)               /**< Set NvmYeTmVal in register */
#define  GET_NVM_YE_TM_VAL_R(reg)                           (((reg)>>9)&0x1u)             /**< Get NvmYeTmVal from register */
#define  NVM_XE_TM_VAL_RSHIFT                               10                            /**< Shift for NvmXeTmVal */
#define  NVM_XE_TM_VAL_RMASK                                0x0400u                       /**< Mask for NvmXeTmVal */
#define  NVM_XE_TM_VAL_RBMASK                               0x1u                          /**< Base mask for NvmXeTmVal */
#define  NVM_XE_TM_VAL_R(x)                                 (((x)&0x1u)<<10)              /**< Set NvmXeTmVal in register */
#define  GET_NVM_XE_TM_VAL_R(reg)                           (((reg)>>10)&0x1u)            /**< Get NvmXeTmVal from register */

// RegNvmTmCtrl0.regs.NvmTmEn
#define  NVM_TM_EN_GSHIFT                                   16                            /**< Shift for group NvmTmEn */
#define  NVM_TM_EN_GSIZE                                    16                            /**< Size of group NvmTmEn */
#define  NVM_TM_EN_GMASK                                    0xFFFF0000u                   /**< Mask for group NvmTmEn */

#define  NVM_IFREN1_TM_EN_RSHIFT                            0                             /**< Shift for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN_RMASK                             0x0001u                       /**< Mask for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN_RBMASK                            0x1u                          /**< Base mask for NvmIfren1TmEn */
#define  NVM_IFREN1_TM_EN_R(x)                              (((x)&0x1u)<<0)               /**< Set NvmIfren1TmEn in register */
#define  GET_NVM_IFREN1_TM_EN_R(reg)                        (((reg)>>0)&0x1u)             /**< Get NvmIfren1TmEn from register */
#define  NVM_REDEN_TM_EN_RSHIFT                             1                             /**< Shift for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN_RMASK                              0x0002u                       /**< Mask for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN_RBMASK                             0x1u                          /**< Base mask for NvmRedenTmEn */
#define  NVM_REDEN_TM_EN_R(x)                               (((x)&0x1u)<<1)               /**< Set NvmRedenTmEn in register */
#define  GET_NVM_REDEN_TM_EN_R(reg)                         (((reg)>>1)&0x1u)             /**< Get NvmRedenTmEn from register */
#define  NVM_TMR_TM_EN_RSHIFT                               2                             /**< Shift for NvmTmrTmEn */
#define  NVM_TMR_TM_EN_RMASK                                0x0004u                       /**< Mask for NvmTmrTmEn */
#define  NVM_TMR_TM_EN_RBMASK                               0x1u                          /**< Base mask for NvmTmrTmEn */
#define  NVM_TMR_TM_EN_R(x)                                 (((x)&0x1u)<<2)               /**< Set NvmTmrTmEn in register */
#define  GET_NVM_TMR_TM_EN_R(reg)                           (((reg)>>2)&0x1u)             /**< Get NvmTmrTmEn from register */
#define  NVM_IFREN_TM_EN_RSHIFT                             3                             /**< Shift for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN_RMASK                              0x0008u                       /**< Mask for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN_RBMASK                             0x1u                          /**< Base mask for NvmIfrenTmEn */
#define  NVM_IFREN_TM_EN_R(x)                               (((x)&0x1u)<<3)               /**< Set NvmIfrenTmEn in register */
#define  GET_NVM_IFREN_TM_EN_R(reg)                         (((reg)>>3)&0x1u)             /**< Get NvmIfrenTmEn from register */
#define  NVM_NVSTR_TM_EN_RSHIFT                             4                             /**< Shift for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN_RMASK                              0x0010u                       /**< Mask for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN_RBMASK                             0x1u                          /**< Base mask for NvmNvstrTmEn */
#define  NVM_NVSTR_TM_EN_R(x)                               (((x)&0x1u)<<4)               /**< Set NvmNvstrTmEn in register */
#define  GET_NVM_NVSTR_TM_EN_R(reg)                         (((reg)>>4)&0x1u)             /**< Get NvmNvstrTmEn from register */
#define  NVM_PROG_TM_EN_RSHIFT                              5                             /**< Shift for NvmProgTmEn */
#define  NVM_PROG_TM_EN_RMASK                               0x0020u                       /**< Mask for NvmProgTmEn */
#define  NVM_PROG_TM_EN_RBMASK                              0x1u                          /**< Base mask for NvmProgTmEn */
#define  NVM_PROG_TM_EN_R(x)                                (((x)&0x1u)<<5)               /**< Set NvmProgTmEn in register */
#define  GET_NVM_PROG_TM_EN_R(reg)                          (((reg)>>5)&0x1u)             /**< Get NvmProgTmEn from register */
#define  NVM_MAS1_TM_EN_RSHIFT                              6                             /**< Shift for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN_RMASK                               0x0040u                       /**< Mask for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN_RBMASK                              0x1u                          /**< Base mask for NvmMas1TmEn */
#define  NVM_MAS1_TM_EN_R(x)                                (((x)&0x1u)<<6)               /**< Set NvmMas1TmEn in register */
#define  GET_NVM_MAS1_TM_EN_R(reg)                          (((reg)>>6)&0x1u)             /**< Get NvmMas1TmEn from register */
#define  NVM_ERASE_TM_EN_RSHIFT                             7                             /**< Shift for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN_RMASK                              0x0080u                       /**< Mask for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN_RBMASK                             0x1u                          /**< Base mask for NvmEraseTmEn */
#define  NVM_ERASE_TM_EN_R(x)                               (((x)&0x1u)<<7)               /**< Set NvmEraseTmEn in register */
#define  GET_NVM_ERASE_TM_EN_R(reg)                         (((reg)>>7)&0x1u)             /**< Get NvmEraseTmEn from register */
#define  NVM_YE_TM_EN_RSHIFT                                9                             /**< Shift for NvmYeTmEn */
#define  NVM_YE_TM_EN_RMASK                                 0x0200u                       /**< Mask for NvmYeTmEn */
#define  NVM_YE_TM_EN_RBMASK                                0x1u                          /**< Base mask for NvmYeTmEn */
#define  NVM_YE_TM_EN_R(x)                                  (((x)&0x1u)<<9)               /**< Set NvmYeTmEn in register */
#define  GET_NVM_YE_TM_EN_R(reg)                            (((reg)>>9)&0x1u)             /**< Get NvmYeTmEn from register */
#define  NVM_XE_TM_EN_RSHIFT                                10                            /**< Shift for NvmXeTmEn */
#define  NVM_XE_TM_EN_RMASK                                 0x0400u                       /**< Mask for NvmXeTmEn */
#define  NVM_XE_TM_EN_RBMASK                                0x1u                          /**< Base mask for NvmXeTmEn */
#define  NVM_XE_TM_EN_R(x)                                  (((x)&0x1u)<<10)              /**< Set NvmXeTmEn in register */
#define  GET_NVM_XE_TM_EN_R(reg)                            (((reg)>>10)&0x1u)            /**< Get NvmXeTmEn from register */
#define  NVM_ADDR_DIN_SEL_TM_RSHIFT                         11                            /**< Shift for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM_RMASK                          0x0800u                       /**< Mask for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM_RBMASK                         0x1u                          /**< Base mask for NvmAddrDinSelTm */
#define  NVM_ADDR_DIN_SEL_TM_R(x)                           (((x)&0x1u)<<11)              /**< Set NvmAddrDinSelTm in register */
#define  GET_NVM_ADDR_DIN_SEL_TM_R(reg)                     (((reg)>>11)&0x1u)            /**< Get NvmAddrDinSelTm from register */
/** @} */


/**
 * @name RegNvmTmCtrl1
 * @{
 */
// RegNvmTmCtrl1.r32
#define  REG_NVM_TM_CTRL1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegNvmTmCtrl1 */
#define  REG_NVM_TM_CTRL1_MASK                              0x01000100u                   /**< Mask for RegNvmTmCtrl1 */

#define  NVM_SE_TM_VAL_SHIFT                                8                             /**< Shift for NvmSeTmVal */
#define  NVM_SE_TM_VAL_MASK                                 0x00000100u                   /**< Mask for NvmSeTmVal */
#define  NVM_SE_TM_VAL_BMASK                                0x1u                          /**< Base mask for NvmSeTmVal */
#define  NVM_SE_TM_VAL(x)                                   (((x)&0x1u)<<8)               /**< Set NvmSeTmVal in register */
#define  GET_NVM_SE_TM_VAL(reg)                             (((reg)>>8)&0x1u)             /**< Get NvmSeTmVal from register */
#define  NVM_SE_TM_EN_SHIFT                                 24                            /**< Shift for NvmSeTmEn */
#define  NVM_SE_TM_EN_MASK                                  0x01000000u                   /**< Mask for NvmSeTmEn */
#define  NVM_SE_TM_EN_BMASK                                 0x1u                          /**< Base mask for NvmSeTmEn */
#define  NVM_SE_TM_EN(x)                                    (((x)&0x1u)<<24)              /**< Set NvmSeTmEn in register */
#define  GET_NVM_SE_TM_EN(reg)                              (((reg)>>24)&0x1u)            /**< Get NvmSeTmEn from register */
/** @} */


/**
 * @name RegNvmMrCfg
 * @{
 */
// RegNvmMrCfg.r32
#define  REG_NVM_MR_CFG_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmMrCfg */
#define  REG_NVM_MR_CFG_MASK                                0x000F3F3Fu                   /**< Mask for RegNvmMrCfg */

#define  NVM_MR_START_PAGE_SHIFT                            0                             /**< Shift for NvmMrStartPage */
#define  NVM_MR_START_PAGE_MASK                             0x0000003Fu                   /**< Mask for NvmMrStartPage */
#define  NVM_MR_START_PAGE_BMASK                            0x3Fu                         /**< Base mask for NvmMrStartPage */
#define  NVM_MR_START_PAGE(x)                               (((x)&0x3Fu)<<0)              /**< Set NvmMrStartPage in register */
#define  GET_NVM_MR_START_PAGE(reg)                         (((reg)>>0)&0x3Fu)            /**< Get NvmMrStartPage from register */
#define  NVM_MR_STOP_PAGE_SHIFT                             8                             /**< Shift for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_MASK                              0x00003F00u                   /**< Mask for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_BMASK                             0x3Fu                         /**< Base mask for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE(x)                                (((x)&0x3Fu)<<8)              /**< Set NvmMrStopPage in register */
#define  GET_NVM_MR_STOP_PAGE(reg)                          (((reg)>>8)&0x3Fu)            /**< Get NvmMrStopPage from register */
#define  NVM_MR_CYCLE_LENGHT_SHIFT                          16                            /**< Shift for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_MASK                           0x000F0000u                   /**< Mask for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_BMASK                          0xFu                          /**< Base mask for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT(x)                             (((x)&0xFu)<<16)              /**< Set NvmMrCycleLenght in register */
#define  GET_NVM_MR_CYCLE_LENGHT(reg)                       (((reg)>>16)&0xFu)            /**< Get NvmMrCycleLenght from register */

// RegNvmMrCfg.regs.NvmMrStartPage
#define  NVM_MR_START_PAGE_GSHIFT                           0                             /**< Shift for group NvmMrStartPage */
#define  NVM_MR_START_PAGE_GSIZE                            8                             /**< Size of group NvmMrStartPage */
#define  NVM_MR_START_PAGE_GMASK                            0x000000FFu                   /**< Mask for group NvmMrStartPage */

#define  NVM_MR_START_PAGE_RSHIFT                           0                             /**< Shift for NvmMrStartPage */
#define  NVM_MR_START_PAGE_RMASK                            0x0000003Fu                   /**< Mask for NvmMrStartPage */
#define  NVM_MR_START_PAGE_RBMASK                           0x3Fu                         /**< Base mask for NvmMrStartPage */
#define  NVM_MR_START_PAGE_R(x)                             (((x)&0x3Fu)<<0)              /**< Set NvmMrStartPage in register */
#define  GET_NVM_MR_START_PAGE_R(reg)                       (((reg)>>0)&0x3Fu)            /**< Get NvmMrStartPage from register */

// RegNvmMrCfg.regs.NvmMrStopPage
#define  NVM_MR_STOP_PAGE_GSHIFT                            8                             /**< Shift for group NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_GSIZE                             8                             /**< Size of group NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_GMASK                             0x0000FF00u                   /**< Mask for group NvmMrStopPage */

#define  NVM_MR_STOP_PAGE_RSHIFT                            0                             /**< Shift for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_RMASK                             0x0000003Fu                   /**< Mask for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_RBMASK                            0x3Fu                         /**< Base mask for NvmMrStopPage */
#define  NVM_MR_STOP_PAGE_R(x)                              (((x)&0x3Fu)<<0)              /**< Set NvmMrStopPage in register */
#define  GET_NVM_MR_STOP_PAGE_R(reg)                        (((reg)>>0)&0x3Fu)            /**< Get NvmMrStopPage from register */

// RegNvmMrCfg.regs.NvmMrCycleLenght
#define  NVM_MR_CYCLE_LENGHT_GSHIFT                         16                            /**< Shift for group NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_GSIZE                          8                             /**< Size of group NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_GMASK                          0x00FF0000u                   /**< Mask for group NvmMrCycleLenght */

#define  NVM_MR_CYCLE_LENGHT_RSHIFT                         0                             /**< Shift for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_RMASK                          0x0000000Fu                   /**< Mask for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_RBMASK                         0xFu                          /**< Base mask for NvmMrCycleLenght */
#define  NVM_MR_CYCLE_LENGHT_R(x)                           (((x)&0xFu)<<0)               /**< Set NvmMrCycleLenght in register */
#define  GET_NVM_MR_CYCLE_LENGHT_R(reg)                     (((reg)>>0)&0xFu)             /**< Get NvmMrCycleLenght from register */
/** @} */


/**
 * @name RegNvmMrSts
 * @{
 */
// RegNvmMrSts.r32
#define  REG_NVM_MR_STS_RESET_VALUE                         0x00000000u                   /**< Reset value of RegNvmMrSts */
#define  REG_NVM_MR_STS_MASK                                0xFFFFFFFFu                   /**< Mask for RegNvmMrSts */

#define  NVM_MR_FAIL_COUNT_SHIFT                            16                            /**< Shift for NvmMrFailCount */
#define  NVM_MR_FAIL_COUNT_MASK                             0xFFFF0000u                   /**< Mask for NvmMrFailCount */
#define  NVM_MR_FAIL_COUNT_BMASK                            0xFFFFu                       /**< Base mask for NvmMrFailCount */
#define  NVM_MR_FAIL_COUNT(x)                               (((x)&0xFFFFu)<<16)           /**< Set NvmMrFailCount in register */
#define  GET_NVM_MR_FAIL_COUNT(reg)                         (((reg)>>16)&0xFFFFu)         /**< Get NvmMrFailCount from register */
#define  NVM_MR_FAIL_ADDR_SHIFT                             0                             /**< Shift for NvmMrFailAddr */
#define  NVM_MR_FAIL_ADDR_MASK                              0x0000FFFFu                   /**< Mask for NvmMrFailAddr */
#define  NVM_MR_FAIL_ADDR_BMASK                             0xFFFFu                       /**< Base mask for NvmMrFailAddr */
#define  NVM_MR_FAIL_ADDR(x)                                (((x)&0xFFFFu)<<0)            /**< Set NvmMrFailAddr in register */
#define  GET_NVM_MR_FAIL_ADDR(reg)                          (((reg)>>0)&0xFFFFu)          /**< Get NvmMrFailAddr from register */
/** @} */



/** @} End of group NVM_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_NVM_H */
