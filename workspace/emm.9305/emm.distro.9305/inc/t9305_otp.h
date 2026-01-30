////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_otp.h
///
/// @project    T9305
///
/// @brief      OTP register and bit field definitions
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

#ifndef _T9305_OTP_H
#define _T9305_OTP_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup OTP_Registers OTP Register Map - registers
 * @{
 ******************************************************************************/


/** OTP control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  OTPConnect;                                /**< OTP Connect/Standby */
        uint8_t  OTPCmd;                                    /**< OCP command */
        uint8_t  OTPMaxRetry;                               /**< OCP Smart programming max retries */
        uint8_t  RESERVED0;                                 /**< RESERVED */
    } regs;
} RegOTPCtrl_t;


/** OTP write address */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegOTPAddr_t;


/** OTP input data - word 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegOTPWData0_t;


/** OTP input data - word 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegOTPWData1_t;


/** OTP output data - ECC */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegOTPRDataECC_t;


/** OTP Status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  OTPStatus;                                 /**< OTP status register */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  OTPRetries;                                /**< OTP nunmber of write retries */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegOTPStatus_t;

/** @} end of group OTP_Regs */



/***************************************************************************//**
 * @defgroup OTP_RegMap OTP Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegOTPCtrl_t                                      RegOTPCtrl;                   /**< OTP control */
    __IO  RegOTPAddr_t                                      RegOTPAddr;                   /**< OTP write address */
    __IO  RegOTPWData0_t                                    RegOTPWData0;                 /**< OTP input data - word 0 */
    __IO  RegOTPWData1_t                                    RegOTPWData1;                 /**< OTP input data - word 1 */
    __I   RegOTPRDataECC_t                                  RegOTPRDataECC;               /**< OTP output data - ECC */
    __I   RegOTPStatus_t                                    RegOTPStatus;                 /**< OTP Status */
} OTP_RegMap_t;

/** @} end of group OTP_RegMap */



/***************************************************************************//**
 * @defgroup OTP_BitFields OTP bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegOTPCtrl
 * @{
 */
// RegOTPCtrl.r32
#define  REG_OTP_CTRL_RESET_VALUE                           0x000A0000u                   /**< Reset value of RegOTPCtrl */
#define  REG_OTP_CTRL_MASK                                  0x000F0701u                   /**< Mask for RegOTPCtrl */

#define  OTP_CONNECT_SHIFT                                  0                             /**< Shift for OTPConnect */
#define  OTP_CONNECT_MASK                                   0x00000001u                   /**< Mask for OTPConnect */
#define  OTP_CONNECT_BMASK                                  0x1u                          /**< Base mask for OTPConnect */
#define  OTP_CONNECT(x)                                     (((x)&0x1u)<<0)               /**< Set OTPConnect in register */
#define  GET_OTP_CONNECT(reg)                               (((reg)>>0)&0x1u)             /**< Get OTPConnect from register */
#define  OTP_CMD_SHIFT                                      8                             /**< Shift for OTPCmd */
#define  OTP_CMD_MASK                                       0x00000700u                   /**< Mask for OTPCmd */
#define  OTP_CMD_BMASK                                      0x7u                          /**< Base mask for OTPCmd */
#define  OTP_CMD(x)                                         (((x)&0x7u)<<8)               /**< Set OTPCmd in register */
#define  GET_OTP_CMD(reg)                                   (((reg)>>8)&0x7u)             /**< Get OTPCmd from register */
#define  OTP_MAX_RETRY_SHIFT                                16                            /**< Shift for OTPMaxRetry */
#define  OTP_MAX_RETRY_MASK                                 0x000F0000u                   /**< Mask for OTPMaxRetry */
#define  OTP_MAX_RETRY_BMASK                                0xFu                          /**< Base mask for OTPMaxRetry */
#define  OTP_MAX_RETRY(x)                                   (((x)&0xFu)<<16)              /**< Set OTPMaxRetry in register */
#define  GET_OTP_MAX_RETRY(reg)                             (((reg)>>16)&0xFu)            /**< Get OTPMaxRetry from register */

// RegOTPCtrl.regs.OTPConnect
#define  OTP_CONNECT_GSHIFT                                 0                             /**< Shift for group OTPConnect */
#define  OTP_CONNECT_GSIZE                                  8                             /**< Size of group OTPConnect */
#define  OTP_CONNECT_GMASK                                  0x000000FFu                   /**< Mask for group OTPConnect */

#define  OTP_CONNECT_RSHIFT                                 0                             /**< Shift for OTPConnect */
#define  OTP_CONNECT_RMASK                                  0x00000001u                   /**< Mask for OTPConnect */
#define  OTP_CONNECT_RBMASK                                 0x1u                          /**< Base mask for OTPConnect */
#define  OTP_CONNECT_R(x)                                   (((x)&0x1u)<<0)               /**< Set OTPConnect in register */
#define  GET_OTP_CONNECT_R(reg)                             (((reg)>>0)&0x1u)             /**< Get OTPConnect from register */

// RegOTPCtrl.regs.OTPCmd
#define  OTP_CMD_GSHIFT                                     8                             /**< Shift for group OTPCmd */
#define  OTP_CMD_GSIZE                                      8                             /**< Size of group OTPCmd */
#define  OTP_CMD_GMASK                                      0x0000FF00u                   /**< Mask for group OTPCmd */

#define  OTP_CMD_RSHIFT                                     0                             /**< Shift for OTPCmd */
#define  OTP_CMD_RMASK                                      0x00000007u                   /**< Mask for OTPCmd */
#define  OTP_CMD_RBMASK                                     0x7u                          /**< Base mask for OTPCmd */
#define  OTP_CMD_R(x)                                       (((x)&0x7u)<<0)               /**< Set OTPCmd in register */
#define  GET_OTP_CMD_R(reg)                                 (((reg)>>0)&0x7u)             /**< Get OTPCmd from register */

// RegOTPCtrl.regs.OTPMaxRetry
#define  OTP_MAX_RETRY_GSHIFT                               16                            /**< Shift for group OTPMaxRetry */
#define  OTP_MAX_RETRY_GSIZE                                8                             /**< Size of group OTPMaxRetry */
#define  OTP_MAX_RETRY_GMASK                                0x00FF0000u                   /**< Mask for group OTPMaxRetry */

#define  OTP_MAX_RETRY_RSHIFT                               0                             /**< Shift for OTPMaxRetry */
#define  OTP_MAX_RETRY_RMASK                                0x0000000Fu                   /**< Mask for OTPMaxRetry */
#define  OTP_MAX_RETRY_RBMASK                               0xFu                          /**< Base mask for OTPMaxRetry */
#define  OTP_MAX_RETRY_R(x)                                 (((x)&0xFu)<<0)               /**< Set OTPMaxRetry in register */
#define  GET_OTP_MAX_RETRY_R(reg)                           (((reg)>>0)&0xFu)             /**< Get OTPMaxRetry from register */
/** @} */


/**
 * @name RegOTPAddr
 * @{
 */
// RegOTPAddr.r32
#define  REG_OTP_ADDR_RESET_VALUE                           0x00000000u                   /**< Reset value of RegOTPAddr */
#define  REG_OTP_ADDR_MASK                                  0x00003FFFu                   /**< Mask for RegOTPAddr */

#define  OTP_ADDR_SHIFT                                     0                             /**< Shift for OTPAddr */
#define  OTP_ADDR_MASK                                      0x00003FFFu                   /**< Mask for OTPAddr */
#define  OTP_ADDR_BMASK                                     0x3FFFu                       /**< Base mask for OTPAddr */
#define  OTP_ADDR(x)                                        (((x)&0x3FFFu)<<0)            /**< Set OTPAddr in register */
#define  GET_OTP_ADDR(reg)                                  (((reg)>>0)&0x3FFFu)          /**< Get OTPAddr from register */
/** @} */


/**
 * @name RegOTPWData0
 * @{
 */
// RegOTPWData0.r32
#define  REG_OTP_WDATA0_RESET_VALUE                         0x00000000u                   /**< Reset value of RegOTPWData0 */
#define  REG_OTP_WDATA0_MASK                                0xFFFFFFFFu                   /**< Mask for RegOTPWData0 */

#define  OTP_WDATA0_SHIFT                                   0                             /**< Shift for OTPWData0 */
#define  OTP_WDATA0_MASK                                    0xFFFFFFFFu                   /**< Mask for OTPWData0 */
#define  OTP_WDATA0_BMASK                                   0xFFFFFFFFu                   /**< Base mask for OTPWData0 */
#define  OTP_WDATA0(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set OTPWData0 in register */
#define  GET_OTP_WDATA0(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get OTPWData0 from register */
/** @} */


/**
 * @name RegOTPWData1
 * @{
 */
// RegOTPWData1.r32
#define  REG_OTP_WDATA1_RESET_VALUE                         0x00000000u                   /**< Reset value of RegOTPWData1 */
#define  REG_OTP_WDATA1_MASK                                0xFFFFFFFFu                   /**< Mask for RegOTPWData1 */

#define  OTP_WDATA1_SHIFT                                   0                             /**< Shift for OTPWData1 */
#define  OTP_WDATA1_MASK                                    0xFFFFFFFFu                   /**< Mask for OTPWData1 */
#define  OTP_WDATA1_BMASK                                   0xFFFFFFFFu                   /**< Base mask for OTPWData1 */
#define  OTP_WDATA1(x)                                      (((x)&0xFFFFFFFFu)<<0)        /**< Set OTPWData1 in register */
#define  GET_OTP_WDATA1(reg)                                (((reg)>>0)&0xFFFFFFFFu)      /**< Get OTPWData1 from register */
/** @} */


/**
 * @name RegOTPRDataECC
 * @{
 */
// RegOTPRDataECC.r32
#define  REG_OTP_RDATA_ECC_RESET_VALUE                      0x00000000u                   /**< Reset value of RegOTPRDataECC */
#define  REG_OTP_RDATA_ECC_MASK                             0x000000FFu                   /**< Mask for RegOTPRDataECC */

#define  OTP_ECC_SHIFT                                      0                             /**< Shift for OTPECC */
#define  OTP_ECC_MASK                                       0x000000FFu                   /**< Mask for OTPECC */
#define  OTP_ECC_BMASK                                      0xFFu                         /**< Base mask for OTPECC */
#define  OTP_ECC(x)                                         (((x)&0xFFu)<<0)              /**< Set OTPECC in register */
#define  GET_OTP_ECC(reg)                                   (((reg)>>0)&0xFFu)            /**< Get OTPECC from register */
/** @} */


/**
 * @name RegOTPStatus
 * @{
 */
// RegOTPStatus.r32
#define  REG_OTP_STATUS_RESET_VALUE                         0x00000000u                   /**< Reset value of RegOTPStatus */
#define  REG_OTP_STATUS_MASK                                0x000F0003u                   /**< Mask for RegOTPStatus */

#define  OTP_RESP_SHIFT                                     0                             /**< Shift for OTPResp */
#define  OTP_RESP_MASK                                      0x00000001u                   /**< Mask for OTPResp */
#define  OTP_RESP_BMASK                                     0x1u                          /**< Base mask for OTPResp */
#define  OTP_RESP(x)                                        (((x)&0x1u)<<0)               /**< Set OTPResp in register */
#define  GET_OTP_RESP(reg)                                  (((reg)>>0)&0x1u)             /**< Get OTPResp from register */
#define  OTP_ERROR_SHIFT                                    1                             /**< Shift for OTPError */
#define  OTP_ERROR_MASK                                     0x00000002u                   /**< Mask for OTPError */
#define  OTP_ERROR_BMASK                                    0x1u                          /**< Base mask for OTPError */
#define  OTP_ERROR(x)                                       (((x)&0x1u)<<1)               /**< Set OTPError in register */
#define  GET_OTP_ERROR(reg)                                 (((reg)>>1)&0x1u)             /**< Get OTPError from register */
#define  OTP_RETRIES_SHIFT                                  16                            /**< Shift for OTPRetries */
#define  OTP_RETRIES_MASK                                   0x000F0000u                   /**< Mask for OTPRetries */
#define  OTP_RETRIES_BMASK                                  0xFu                          /**< Base mask for OTPRetries */
#define  OTP_RETRIES(x)                                     (((x)&0xFu)<<16)              /**< Set OTPRetries in register */
#define  GET_OTP_RETRIES(reg)                               (((reg)>>16)&0xFu)            /**< Get OTPRetries from register */

// RegOTPStatus.regs.OTPStatus
#define  OTP_STATUS_GSHIFT                                  0                             /**< Shift for group OTPStatus */
#define  OTP_STATUS_GSIZE                                   8                             /**< Size of group OTPStatus */
#define  OTP_STATUS_GMASK                                   0x000000FFu                   /**< Mask for group OTPStatus */

#define  OTP_RESP_RSHIFT                                    0                             /**< Shift for OTPResp */
#define  OTP_RESP_RMASK                                     0x01u                         /**< Mask for OTPResp */
#define  OTP_RESP_RBMASK                                    0x1u                          /**< Base mask for OTPResp */
#define  OTP_RESP_R(x)                                      (((x)&0x1u)<<0)               /**< Set OTPResp in register */
#define  GET_OTP_RESP_R(reg)                                (((reg)>>0)&0x1u)             /**< Get OTPResp from register */
#define  OTP_ERROR_RSHIFT                                   1                             /**< Shift for OTPError */
#define  OTP_ERROR_RMASK                                    0x02u                         /**< Mask for OTPError */
#define  OTP_ERROR_RBMASK                                   0x1u                          /**< Base mask for OTPError */
#define  OTP_ERROR_R(x)                                     (((x)&0x1u)<<1)               /**< Set OTPError in register */
#define  GET_OTP_ERROR_R(reg)                               (((reg)>>1)&0x1u)             /**< Get OTPError from register */

// RegOTPStatus.regs.OTPRetries
#define  OTP_RETRIES_GSHIFT                                 16                            /**< Shift for group OTPRetries */
#define  OTP_RETRIES_GSIZE                                  8                             /**< Size of group OTPRetries */
#define  OTP_RETRIES_GMASK                                  0x00FF0000u                   /**< Mask for group OTPRetries */

#define  OTP_RETRIES_RSHIFT                                 0                             /**< Shift for OTPRetries */
#define  OTP_RETRIES_RMASK                                  0x0Fu                         /**< Mask for OTPRetries */
#define  OTP_RETRIES_RBMASK                                 0xFu                          /**< Base mask for OTPRetries */
#define  OTP_RETRIES_R(x)                                   (((x)&0xFu)<<0)               /**< Set OTPRetries in register */
#define  GET_OTP_RETRIES_R(reg)                             (((reg)>>0)&0xFu)             /**< Get OTPRetries from register */
/** @} */



/** @} End of group OTP_BitFields */
/** @} End of addtogroup T9305_Periphery */

#endif /*_T9305_OTP_H */
