////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_spi_slave.h
///
/// @project    T9305
///
/// @brief      SPI Slave register and bit field definitions
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

#ifndef _T9305_SPI_SLAVE_H
#define _T9305_SPI_SLAVE_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup SPISlave_Registers SPI Slave Register Map - registers
 * @{
 ******************************************************************************/


/** SPI Slave configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISCfg_t;


/** SPI Slave control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  SPISCtrl1;                                 /**< SPIS control register 1 */
        uint8_t  SPISCtrl2;                                 /**< SPIS control register 2 */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegSPISCtrl_t;


/** SPI Slave status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISStat_t;


/** SPI Slave Receive FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISRxFIFO1B_t;


/** SPI Slave Receive FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISRxFIFO2B_t;


/** SPI Slave Receive FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISRxFIFO3B_t;


/** SPI Slave Receive FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISRxFIFO4B_t;


/** SPI Slave Transmit FIFO - 1 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISTxFIFO1B_t;


/** SPI Slave Transmit FIFO - 2 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISTxFIFO2B_t;


/** SPI Slave Transmit FIFO - 3 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISTxFIFO3B_t;


/** SPI Slave Transmit FIFO - 4 byte access */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISTxFIFO4B_t;


/** SPI Slave FIFO configuration */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  SPISTxFIFOLimit;                           /**< SPI Slave TX FIFO limit */
        uint8_t  SPISRxFIFOLimit;                           /**< SPI Slave RX FIFO limit */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  RESERVED1;                                 /**< RESERVED */
    } regs;
} RegSPISFIFOCfg_t;


/** SPI Slave FIFO control */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegSPISFIFOCtrl_t;


/** SPI Slave FIFO status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
    struct PACKED_STRUCT {
        uint8_t  SPISFIFOStat;                              /**< SPI Slave FIFO status */
        uint8_t  RESERVED0;                                 /**< RESERVED */
        uint8_t  SPISTxFIFONumBytes;                        /**< SPI Slave TX FIFO - number of available bytes */
        uint8_t  SPISRxFIFONumBytes;                        /**< SPI Slave RX FIFO - number of available bytes */
    } regs;
} RegSPISFIFOStat_t;

/** @} end of group SPISlave_Regs */



/***************************************************************************//**
 * @defgroup SPISlave_RegMap SPI Slave Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegSPISCfg_t                                      RegSPISCfg;                   /**< SPI Slave configuration */
    __IO  RegSPISCtrl_t                                     RegSPISCtrl;                  /**< SPI Slave control */
    __I   RegSPISStat_t                                     RegSPISStat;                  /**< SPI Slave status */
    __I   RegSPISRxFIFO1B_t                                 RegSPISRxFIFO1B;              /**< SPI Slave Receive FIFO - 1 byte access */
    __I   RegSPISRxFIFO2B_t                                 RegSPISRxFIFO2B;              /**< SPI Slave Receive FIFO - 2 byte access */
    __I   RegSPISRxFIFO3B_t                                 RegSPISRxFIFO3B;              /**< SPI Slave Receive FIFO - 3 byte access */
    __I   RegSPISRxFIFO4B_t                                 RegSPISRxFIFO4B;              /**< SPI Slave Receive FIFO - 4 byte access */
    __O   RegSPISTxFIFO1B_t                                 RegSPISTxFIFO1B;              /**< SPI Slave Transmit FIFO - 1 byte access */
    __O   RegSPISTxFIFO2B_t                                 RegSPISTxFIFO2B;              /**< SPI Slave Transmit FIFO - 2 byte access */
    __O   RegSPISTxFIFO3B_t                                 RegSPISTxFIFO3B;              /**< SPI Slave Transmit FIFO - 3 byte access */
    __O   RegSPISTxFIFO4B_t                                 RegSPISTxFIFO4B;              /**< SPI Slave Transmit FIFO - 4 byte access */
    __IO  RegSPISFIFOCfg_t                                  RegSPISFIFOCfg;               /**< SPI Slave FIFO configuration */
    __O   RegSPISFIFOCtrl_t                                 RegSPISFIFOCtrl;              /**< SPI Slave FIFO control */
    __I   RegSPISFIFOStat_t                                 RegSPISFIFOStat;              /**< SPI Slave FIFO status */
} SPISlave_RegMap_t;

/** @} end of group SPISlave_RegMap */



/***************************************************************************//**
 * @defgroup SPISlave_BitFields SPISlave bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegSPISCfg
 * @{
 */
// RegSPISCfg.r32
#define  REG_SPIS_CFG_RESET_VALUE                           0x00C00000u                   /**< Reset value of RegSPISCfg */
#define  REG_SPIS_CFG_MASK                                  0x00FF001Fu                   /**< Mask for RegSPISCfg */

#define  SPIS_MSB_FIRST_SHIFT                               0                             /**< Shift for SPISMSBFirst */
#define  SPIS_MSB_FIRST_MASK                                0x00000001u                   /**< Mask for SPISMSBFirst */
#define  SPIS_MSB_FIRST_BMASK                               0x1u                          /**< Base mask for SPISMSBFirst */
#define  SPIS_MSB_FIRST(x)                                  (((x)&0x1u)<<0)               /**< Set SPISMSBFirst in register */
#define  GET_SPIS_MSB_FIRST(reg)                            (((reg)>>0)&0x1u)             /**< Get SPISMSBFirst from register */
#define  SPIS_CPOL_SHIFT                                    1                             /**< Shift for SPISCPOL */
#define  SPIS_CPOL_MASK                                     0x00000002u                   /**< Mask for SPISCPOL */
#define  SPIS_CPOL_BMASK                                    0x1u                          /**< Base mask for SPISCPOL */
#define  SPIS_CPOL(x)                                       (((x)&0x1u)<<1)               /**< Set SPISCPOL in register */
#define  GET_SPIS_CPOL(reg)                                 (((reg)>>1)&0x1u)             /**< Get SPISCPOL from register */
#define  SPIS_CPHA_SHIFT                                    2                             /**< Shift for SPISCPHA */
#define  SPIS_CPHA_MASK                                     0x00000004u                   /**< Mask for SPISCPHA */
#define  SPIS_CPHA_BMASK                                    0x1u                          /**< Base mask for SPISCPHA */
#define  SPIS_CPHA(x)                                       (((x)&0x1u)<<2)               /**< Set SPISCPHA in register */
#define  GET_SPIS_CPHA(reg)                                 (((reg)>>2)&0x1u)             /**< Get SPISCPHA from register */
#define  SPIS_MODE_SHIFT                                    3                             /**< Shift for SPISMode */
#define  SPIS_MODE_MASK                                     0x00000008u                   /**< Mask for SPISMode */
#define  SPIS_MODE_BMASK                                    0x1u                          /**< Base mask for SPISMode */
#define  SPIS_MODE(x)                                       (((x)&0x1u)<<3)               /**< Set SPISMode in register */
#define  GET_SPIS_MODE(reg)                                 (((reg)>>3)&0x1u)             /**< Get SPISMode from register */
#define  SPIS_TX_PHASE_SHIFT                                4                             /**< Shift for SPISTxPhase */
#define  SPIS_TX_PHASE_MASK                                 0x00000010u                   /**< Mask for SPISTxPhase */
#define  SPIS_TX_PHASE_BMASK                                0x1u                          /**< Base mask for SPISTxPhase */
#define  SPIS_TX_PHASE(x)                                   (((x)&0x1u)<<4)               /**< Set SPISTxPhase in register */
#define  GET_SPIS_TX_PHASE(reg)                             (((reg)>>4)&0x1u)             /**< Get SPISTxPhase from register */
#define  SPIS_STS1_SHIFT                                    16                            /**< Shift for SPISSTS1 */
#define  SPIS_STS1_MASK                                     0x00FF0000u                   /**< Mask for SPISSTS1 */
#define  SPIS_STS1_BMASK                                    0xFFu                         /**< Base mask for SPISSTS1 */
#define  SPIS_STS1(x)                                       (((x)&0xFFu)<<16)             /**< Set SPISSTS1 in register */
#define  GET_SPIS_STS1(reg)                                 (((reg)>>16)&0xFFu)           /**< Get SPISSTS1 from register */
/** @} */


/**
 * @name RegSPISCtrl
 * @{
 */
// RegSPISCtrl.r32
#define  REG_SPIS_CTRL_RESET_VALUE                          0x00000000u                   /**< Reset value of RegSPISCtrl */
#define  REG_SPIS_CTRL_MASK                                 0x00000101u                   /**< Mask for RegSPISCtrl */

#define  SPIS_EN_SHIFT                                      0                             /**< Shift for SPISEn */
#define  SPIS_EN_MASK                                       0x00000001u                   /**< Mask for SPISEn */
#define  SPIS_EN_BMASK                                      0x1u                          /**< Base mask for SPISEn */
#define  SPIS_EN(x)                                         (((x)&0x1u)<<0)               /**< Set SPISEn in register */
#define  GET_SPIS_EN(reg)                                   (((reg)>>0)&0x1u)             /**< Get SPISEn from register */
#define  SPIS_FORCE_RDY_SHIFT                               8                             /**< Shift for SPISForceRDY */
#define  SPIS_FORCE_RDY_MASK                                0x00000100u                   /**< Mask for SPISForceRDY */
#define  SPIS_FORCE_RDY_BMASK                               0x1u                          /**< Base mask for SPISForceRDY */
#define  SPIS_FORCE_RDY(x)                                  (((x)&0x1u)<<8)               /**< Set SPISForceRDY in register */
#define  GET_SPIS_FORCE_RDY(reg)                            (((reg)>>8)&0x1u)             /**< Get SPISForceRDY from register */

// RegSPISCtrl.regs.SPISCtrl1
#define  SPIS_CTRL1_GSHIFT                                  0                             /**< Shift for group SPISCtrl1 */
#define  SPIS_CTRL1_GSIZE                                   8                             /**< Size of group SPISCtrl1 */
#define  SPIS_CTRL1_GMASK                                   0x000000FFu                   /**< Mask for group SPISCtrl1 */

#define  SPIS_EN_RSHIFT                                     0                             /**< Shift for SPISEn */
#define  SPIS_EN_RMASK                                      0x01u                         /**< Mask for SPISEn */
#define  SPIS_EN_RBMASK                                     0x1u                          /**< Base mask for SPISEn */
#define  SPIS_EN_R(x)                                       (((x)&0x1u)<<0)               /**< Set SPISEn in register */
#define  GET_SPIS_EN_R(reg)                                 (((reg)>>0)&0x1u)             /**< Get SPISEn from register */

// RegSPISCtrl.regs.SPISCtrl2
#define  SPIS_CTRL2_GSHIFT                                  8                             /**< Shift for group SPISCtrl2 */
#define  SPIS_CTRL2_GSIZE                                   8                             /**< Size of group SPISCtrl2 */
#define  SPIS_CTRL2_GMASK                                   0x0000FF00u                   /**< Mask for group SPISCtrl2 */

#define  SPIS_FORCE_RDY_RSHIFT                              0                             /**< Shift for SPISForceRDY */
#define  SPIS_FORCE_RDY_RMASK                               0x01u                         /**< Mask for SPISForceRDY */
#define  SPIS_FORCE_RDY_RBMASK                              0x1u                          /**< Base mask for SPISForceRDY */
#define  SPIS_FORCE_RDY_R(x)                                (((x)&0x1u)<<0)               /**< Set SPISForceRDY in register */
#define  GET_SPIS_FORCE_RDY_R(reg)                          (((reg)>>0)&0x1u)             /**< Get SPISForceRDY from register */
/** @} */


/**
 * @name RegSPISStat
 * @{
 */
// RegSPISStat.r32
#define  REG_SPIS_STAT_RESET_VALUE                          0x00000000u                   /**< Reset value of RegSPISStat */
#define  REG_SPIS_STAT_MASK                                 0x00000001u                   /**< Mask for RegSPISStat */

#define  SPIS_BUSY_SHIFT                                    0                             /**< Shift for SPISBusy */
#define  SPIS_BUSY_MASK                                     0x00000001u                   /**< Mask for SPISBusy */
#define  SPIS_BUSY_BMASK                                    0x1u                          /**< Base mask for SPISBusy */
#define  SPIS_BUSY(x)                                       (((x)&0x1u)<<0)               /**< Set SPISBusy in register */
#define  GET_SPIS_BUSY(reg)                                 (((reg)>>0)&0x1u)             /**< Get SPISBusy from register */
/** @} */


/**
 * @name RegSPISRxFIFO1B
 * @{
 */
// RegSPISRxFIFO1B.r32
#define  REG_SPIS_RX_FIFO_1B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISRxFIFO1B */
#define  REG_SPIS_RX_FIFO_1B_MASK                           0x000000FFu                   /**< Mask for RegSPISRxFIFO1B */

#define  SPIS_RX_FIFO_1B_SHIFT                              0                             /**< Shift for SPISRxFIFO1B */
#define  SPIS_RX_FIFO_1B_MASK                               0x000000FFu                   /**< Mask for SPISRxFIFO1B */
#define  SPIS_RX_FIFO_1B_BMASK                              0xFFu                         /**< Base mask for SPISRxFIFO1B */
#define  SPIS_RX_FIFO_1B(x)                                 (((x)&0xFFu)<<0)              /**< Set SPISRxFIFO1B in register */
#define  GET_SPIS_RX_FIFO_1B(reg)                           (((reg)>>0)&0xFFu)            /**< Get SPISRxFIFO1B from register */
/** @} */


/**
 * @name RegSPISRxFIFO2B
 * @{
 */
// RegSPISRxFIFO2B.r32
#define  REG_SPIS_RX_FIFO_2B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISRxFIFO2B */
#define  REG_SPIS_RX_FIFO_2B_MASK                           0x0000FFFFu                   /**< Mask for RegSPISRxFIFO2B */

#define  SPIS_RX_FIFO_2B_SHIFT                              0                             /**< Shift for SPISRxFIFO2B */
#define  SPIS_RX_FIFO_2B_MASK                               0x0000FFFFu                   /**< Mask for SPISRxFIFO2B */
#define  SPIS_RX_FIFO_2B_BMASK                              0xFFFFu                       /**< Base mask for SPISRxFIFO2B */
#define  SPIS_RX_FIFO_2B(x)                                 (((x)&0xFFFFu)<<0)            /**< Set SPISRxFIFO2B in register */
#define  GET_SPIS_RX_FIFO_2B(reg)                           (((reg)>>0)&0xFFFFu)          /**< Get SPISRxFIFO2B from register */
/** @} */


/**
 * @name RegSPISRxFIFO3B
 * @{
 */
// RegSPISRxFIFO3B.r32
#define  REG_SPIS_RX_FIFO_3B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISRxFIFO3B */
#define  REG_SPIS_RX_FIFO_3B_MASK                           0x00FFFFFFu                   /**< Mask for RegSPISRxFIFO3B */

#define  SPIS_RX_FIFO_3B_SHIFT                              0                             /**< Shift for SPISRxFIFO3B */
#define  SPIS_RX_FIFO_3B_MASK                               0x00FFFFFFu                   /**< Mask for SPISRxFIFO3B */
#define  SPIS_RX_FIFO_3B_BMASK                              0xFFFFFFu                     /**< Base mask for SPISRxFIFO3B */
#define  SPIS_RX_FIFO_3B(x)                                 (((x)&0xFFFFFFu)<<0)          /**< Set SPISRxFIFO3B in register */
#define  GET_SPIS_RX_FIFO_3B(reg)                           (((reg)>>0)&0xFFFFFFu)        /**< Get SPISRxFIFO3B from register */
/** @} */


/**
 * @name RegSPISRxFIFO4B
 * @{
 */
// RegSPISRxFIFO4B.r32
#define  REG_SPIS_RX_FIFO_4B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISRxFIFO4B */
#define  REG_SPIS_RX_FIFO_4B_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPISRxFIFO4B */

#define  SPIS_RX_FIFO_4B_SHIFT                              0                             /**< Shift for SPISRxFIFO4B */
#define  SPIS_RX_FIFO_4B_MASK                               0xFFFFFFFFu                   /**< Mask for SPISRxFIFO4B */
#define  SPIS_RX_FIFO_4B_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPISRxFIFO4B */
#define  SPIS_RX_FIFO_4B(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPISRxFIFO4B in register */
#define  GET_SPIS_RX_FIFO_4B(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPISRxFIFO4B from register */
/** @} */


/**
 * @name RegSPISTxFIFO1B
 * @{
 */
// RegSPISTxFIFO1B.r32
#define  REG_SPIS_TX_FIFO_1B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISTxFIFO1B */
#define  REG_SPIS_TX_FIFO_1B_MASK                           0x000000FFu                   /**< Mask for RegSPISTxFIFO1B */

#define  SPIS_TX_FIFO_1B_SHIFT                              0                             /**< Shift for SPISTxFIFO1B */
#define  SPIS_TX_FIFO_1B_MASK                               0x000000FFu                   /**< Mask for SPISTxFIFO1B */
#define  SPIS_TX_FIFO_1B_BMASK                              0xFFu                         /**< Base mask for SPISTxFIFO1B */
#define  SPIS_TX_FIFO_1B(x)                                 (((x)&0xFFu)<<0)              /**< Set SPISTxFIFO1B in register */
#define  GET_SPIS_TX_FIFO_1B(reg)                           (((reg)>>0)&0xFFu)            /**< Get SPISTxFIFO1B from register */
/** @} */


/**
 * @name RegSPISTxFIFO2B
 * @{
 */
// RegSPISTxFIFO2B.r32
#define  REG_SPIS_TX_FIFO_2B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISTxFIFO2B */
#define  REG_SPIS_TX_FIFO_2B_MASK                           0x0000FFFFu                   /**< Mask for RegSPISTxFIFO2B */

#define  SPIS_TX_FIFO_2B_SHIFT                              0                             /**< Shift for SPISTxFIFO2B */
#define  SPIS_TX_FIFO_2B_MASK                               0x0000FFFFu                   /**< Mask for SPISTxFIFO2B */
#define  SPIS_TX_FIFO_2B_BMASK                              0xFFFFu                       /**< Base mask for SPISTxFIFO2B */
#define  SPIS_TX_FIFO_2B(x)                                 (((x)&0xFFFFu)<<0)            /**< Set SPISTxFIFO2B in register */
#define  GET_SPIS_TX_FIFO_2B(reg)                           (((reg)>>0)&0xFFFFu)          /**< Get SPISTxFIFO2B from register */
/** @} */


/**
 * @name RegSPISTxFIFO3B
 * @{
 */
// RegSPISTxFIFO3B.r32
#define  REG_SPIS_TX_FIFO_3B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISTxFIFO3B */
#define  REG_SPIS_TX_FIFO_3B_MASK                           0x00FFFFFFu                   /**< Mask for RegSPISTxFIFO3B */

#define  SPIS_TX_FIFO_3B_SHIFT                              0                             /**< Shift for SPISTxFIFO3B */
#define  SPIS_TX_FIFO_3B_MASK                               0x00FFFFFFu                   /**< Mask for SPISTxFIFO3B */
#define  SPIS_TX_FIFO_3B_BMASK                              0xFFFFFFu                     /**< Base mask for SPISTxFIFO3B */
#define  SPIS_TX_FIFO_3B(x)                                 (((x)&0xFFFFFFu)<<0)          /**< Set SPISTxFIFO3B in register */
#define  GET_SPIS_TX_FIFO_3B(reg)                           (((reg)>>0)&0xFFFFFFu)        /**< Get SPISTxFIFO3B from register */
/** @} */


/**
 * @name RegSPISTxFIFO4B
 * @{
 */
// RegSPISTxFIFO4B.r32
#define  REG_SPIS_TX_FIFO_4B_RESET_VALUE                    0x00000000u                   /**< Reset value of RegSPISTxFIFO4B */
#define  REG_SPIS_TX_FIFO_4B_MASK                           0xFFFFFFFFu                   /**< Mask for RegSPISTxFIFO4B */

#define  SPIS_TX_FIFO_4B_SHIFT                              0                             /**< Shift for SPISTxFIFO4B */
#define  SPIS_TX_FIFO_4B_MASK                               0xFFFFFFFFu                   /**< Mask for SPISTxFIFO4B */
#define  SPIS_TX_FIFO_4B_BMASK                              0xFFFFFFFFu                   /**< Base mask for SPISTxFIFO4B */
#define  SPIS_TX_FIFO_4B(x)                                 (((x)&0xFFFFFFFFu)<<0)        /**< Set SPISTxFIFO4B in register */
#define  GET_SPIS_TX_FIFO_4B(reg)                           (((reg)>>0)&0xFFFFFFFFu)      /**< Get SPISTxFIFO4B from register */
/** @} */


/**
 * @name RegSPISFIFOCfg
 * @{
 */
// RegSPISFIFOCfg.r32
#define  REG_SPIS_FIFO_CFG_RESET_VALUE                      0x00000808u                   /**< Reset value of RegSPISFIFOCfg */
#define  REG_SPIS_FIFO_CFG_MASK                             0x00001F1Fu                   /**< Mask for RegSPISFIFOCfg */

#define  SPIS_TX_FIFO_LIMIT_SHIFT                           0                             /**< Shift for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_MASK                            0x0000001Fu                   /**< Mask for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_BMASK                           0x1Fu                         /**< Base mask for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT(x)                              (((x)&0x1Fu)<<0)              /**< Set SPISTxFIFOLimit in register */
#define  GET_SPIS_TX_FIFO_LIMIT(reg)                        (((reg)>>0)&0x1Fu)            /**< Get SPISTxFIFOLimit from register */
#define  SPIS_RX_FIFO_LIMIT_SHIFT                           8                             /**< Shift for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_MASK                            0x00001F00u                   /**< Mask for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_BMASK                           0x1Fu                         /**< Base mask for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT(x)                              (((x)&0x1Fu)<<8)              /**< Set SPISRxFIFOLimit in register */
#define  GET_SPIS_RX_FIFO_LIMIT(reg)                        (((reg)>>8)&0x1Fu)            /**< Get SPISRxFIFOLimit from register */

// RegSPISFIFOCfg.regs.SPISTxFIFOLimit
#define  SPIS_TX_FIFO_LIMIT_GSHIFT                          0                             /**< Shift for group SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_GSIZE                           8                             /**< Size of group SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_GMASK                           0x000000FFu                   /**< Mask for group SPISTxFIFOLimit */

#define  SPIS_TX_FIFO_LIMIT_RSHIFT                          0                             /**< Shift for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_RMASK                           0x0000001Fu                   /**< Mask for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_RBMASK                          0x1Fu                         /**< Base mask for SPISTxFIFOLimit */
#define  SPIS_TX_FIFO_LIMIT_R(x)                            (((x)&0x1Fu)<<0)              /**< Set SPISTxFIFOLimit in register */
#define  GET_SPIS_TX_FIFO_LIMIT_R(reg)                      (((reg)>>0)&0x1Fu)            /**< Get SPISTxFIFOLimit from register */

// RegSPISFIFOCfg.regs.SPISRxFIFOLimit
#define  SPIS_RX_FIFO_LIMIT_GSHIFT                          8                             /**< Shift for group SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_GSIZE                           8                             /**< Size of group SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_GMASK                           0x0000FF00u                   /**< Mask for group SPISRxFIFOLimit */

#define  SPIS_RX_FIFO_LIMIT_RSHIFT                          0                             /**< Shift for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_RMASK                           0x0000001Fu                   /**< Mask for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_RBMASK                          0x1Fu                         /**< Base mask for SPISRxFIFOLimit */
#define  SPIS_RX_FIFO_LIMIT_R(x)                            (((x)&0x1Fu)<<0)              /**< Set SPISRxFIFOLimit in register */
#define  GET_SPIS_RX_FIFO_LIMIT_R(reg)                      (((reg)>>0)&0x1Fu)            /**< Get SPISRxFIFOLimit from register */
/** @} */


/**
 * @name RegSPISFIFOCtrl
 * @{
 */
// RegSPISFIFOCtrl.r32
#define  REG_SPIS_FIFO_CTRL_RESET_VALUE                     0x00000000u                   /**< Reset value of RegSPISFIFOCtrl */
#define  REG_SPIS_FIFO_CTRL_MASK                            0x00000003u                   /**< Mask for RegSPISFIFOCtrl */

#define  SPIS_TX_FIFO_FLUSH_SHIFT                           0                             /**< Shift for SPISTxFIFOFlush */
#define  SPIS_TX_FIFO_FLUSH_MASK                            0x00000001u                   /**< Mask for SPISTxFIFOFlush */
#define  SPIS_TX_FIFO_FLUSH_BMASK                           0x1u                          /**< Base mask for SPISTxFIFOFlush */
#define  SPIS_TX_FIFO_FLUSH(x)                              (((x)&0x1u)<<0)               /**< Set SPISTxFIFOFlush in register */
#define  GET_SPIS_TX_FIFO_FLUSH(reg)                        (((reg)>>0)&0x1u)             /**< Get SPISTxFIFOFlush from register */
#define  SPIS_RX_FIFO_FLUSH_SHIFT                           1                             /**< Shift for SPISRxFIFOFlush */
#define  SPIS_RX_FIFO_FLUSH_MASK                            0x00000002u                   /**< Mask for SPISRxFIFOFlush */
#define  SPIS_RX_FIFO_FLUSH_BMASK                           0x1u                          /**< Base mask for SPISRxFIFOFlush */
#define  SPIS_RX_FIFO_FLUSH(x)                              (((x)&0x1u)<<1)               /**< Set SPISRxFIFOFlush in register */
#define  GET_SPIS_RX_FIFO_FLUSH(reg)                        (((reg)>>1)&0x1u)             /**< Get SPISRxFIFOFlush from register */
/** @} */


/**
 * @name RegSPISFIFOStat
 * @{
 */
// RegSPISFIFOStat.r32
#define  REG_SPIS_FIFO_STAT_RESET_VALUE                     0x00000000u                   /**< Reset value of RegSPISFIFOStat */
#define  REG_SPIS_FIFO_STAT_MASK                            0x7F7F0077u                   /**< Mask for RegSPISFIFOStat */

#define  SPIS_TX_FIFO_EMPTY_SHIFT                           0                             /**< Shift for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY_MASK                            0x00000001u                   /**< Mask for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY_BMASK                           0x1u                          /**< Base mask for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY(x)                              (((x)&0x1u)<<0)               /**< Set SPISTxFIFOEmpty in register */
#define  GET_SPIS_TX_FIFO_EMPTY(reg)                        (((reg)>>0)&0x1u)             /**< Get SPISTxFIFOEmpty from register */
#define  SPIS_TX_FIFO_LIMIT_DET_SHIFT                       1                             /**< Shift for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET_MASK                        0x00000002u                   /**< Mask for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET_BMASK                       0x1u                          /**< Base mask for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET(x)                          (((x)&0x1u)<<1)               /**< Set SPISTxFIFOLimitDet in register */
#define  GET_SPIS_TX_FIFO_LIMIT_DET(reg)                    (((reg)>>1)&0x1u)             /**< Get SPISTxFIFOLimitDet from register */
#define  SPIS_TX_FIFO_FULL_SHIFT                            2                             /**< Shift for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL_MASK                             0x00000004u                   /**< Mask for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL_BMASK                            0x1u                          /**< Base mask for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL(x)                               (((x)&0x1u)<<2)               /**< Set SPISTxFIFOFull in register */
#define  GET_SPIS_TX_FIFO_FULL(reg)                         (((reg)>>2)&0x1u)             /**< Get SPISTxFIFOFull from register */
#define  SPIS_RX_FIFO_EMPTY_SHIFT                           4                             /**< Shift for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY_MASK                            0x00000010u                   /**< Mask for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY_BMASK                           0x1u                          /**< Base mask for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY(x)                              (((x)&0x1u)<<4)               /**< Set SPISRxFIFOEmpty in register */
#define  GET_SPIS_RX_FIFO_EMPTY(reg)                        (((reg)>>4)&0x1u)             /**< Get SPISRxFIFOEmpty from register */
#define  SPIS_RX_FIFO_LIMIT_DET_SHIFT                       5                             /**< Shift for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET_MASK                        0x00000020u                   /**< Mask for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET_BMASK                       0x1u                          /**< Base mask for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET(x)                          (((x)&0x1u)<<5)               /**< Set SPISRxFIFOLimitDet in register */
#define  GET_SPIS_RX_FIFO_LIMIT_DET(reg)                    (((reg)>>5)&0x1u)             /**< Get SPISRxFIFOLimitDet from register */
#define  SPIS_RX_FIFO_FULL_SHIFT                            6                             /**< Shift for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL_MASK                             0x00000040u                   /**< Mask for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL_BMASK                            0x1u                          /**< Base mask for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL(x)                               (((x)&0x1u)<<6)               /**< Set SPISRxFIFOFull in register */
#define  GET_SPIS_RX_FIFO_FULL(reg)                         (((reg)>>6)&0x1u)             /**< Get SPISRxFIFOFull from register */
#define  SPIS_TX_FIFO_NUM_BYTES_SHIFT                       16                            /**< Shift for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_MASK                        0x007F0000u                   /**< Mask for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_BMASK                       0x7Fu                         /**< Base mask for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES(x)                          (((x)&0x7Fu)<<16)             /**< Set SPISTxFIFONumBytes in register */
#define  GET_SPIS_TX_FIFO_NUM_BYTES(reg)                    (((reg)>>16)&0x7Fu)           /**< Get SPISTxFIFONumBytes from register */
#define  SPIS_RX_FIFO_NUM_BYTES_SHIFT                       24                            /**< Shift for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_MASK                        0x7F000000u                   /**< Mask for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_BMASK                       0x7Fu                         /**< Base mask for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES(x)                          (((x)&0x7Fu)<<24)             /**< Set SPISRxFIFONumBytes in register */
#define  GET_SPIS_RX_FIFO_NUM_BYTES(reg)                    (((reg)>>24)&0x7Fu)           /**< Get SPISRxFIFONumBytes from register */

// RegSPISFIFOStat.regs.SPISFIFOStat
#define  SPIS_FIFO_STAT_GSHIFT                              0                             /**< Shift for group SPISFIFOStat */
#define  SPIS_FIFO_STAT_GSIZE                               8                             /**< Size of group SPISFIFOStat */
#define  SPIS_FIFO_STAT_GMASK                               0x000000FFu                   /**< Mask for group SPISFIFOStat */

#define  SPIS_TX_FIFO_EMPTY_RSHIFT                          0                             /**< Shift for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY_RMASK                           0x01u                         /**< Mask for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY_RBMASK                          0x1u                          /**< Base mask for SPISTxFIFOEmpty */
#define  SPIS_TX_FIFO_EMPTY_R(x)                            (((x)&0x1u)<<0)               /**< Set SPISTxFIFOEmpty in register */
#define  GET_SPIS_TX_FIFO_EMPTY_R(reg)                      (((reg)>>0)&0x1u)             /**< Get SPISTxFIFOEmpty from register */
#define  SPIS_TX_FIFO_LIMIT_DET_RSHIFT                      1                             /**< Shift for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET_RMASK                       0x02u                         /**< Mask for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET_RBMASK                      0x1u                          /**< Base mask for SPISTxFIFOLimitDet */
#define  SPIS_TX_FIFO_LIMIT_DET_R(x)                        (((x)&0x1u)<<1)               /**< Set SPISTxFIFOLimitDet in register */
#define  GET_SPIS_TX_FIFO_LIMIT_DET_R(reg)                  (((reg)>>1)&0x1u)             /**< Get SPISTxFIFOLimitDet from register */
#define  SPIS_TX_FIFO_FULL_RSHIFT                           2                             /**< Shift for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL_RMASK                            0x04u                         /**< Mask for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL_RBMASK                           0x1u                          /**< Base mask for SPISTxFIFOFull */
#define  SPIS_TX_FIFO_FULL_R(x)                             (((x)&0x1u)<<2)               /**< Set SPISTxFIFOFull in register */
#define  GET_SPIS_TX_FIFO_FULL_R(reg)                       (((reg)>>2)&0x1u)             /**< Get SPISTxFIFOFull from register */
#define  SPIS_RX_FIFO_EMPTY_RSHIFT                          4                             /**< Shift for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY_RMASK                           0x10u                         /**< Mask for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY_RBMASK                          0x1u                          /**< Base mask for SPISRxFIFOEmpty */
#define  SPIS_RX_FIFO_EMPTY_R(x)                            (((x)&0x1u)<<4)               /**< Set SPISRxFIFOEmpty in register */
#define  GET_SPIS_RX_FIFO_EMPTY_R(reg)                      (((reg)>>4)&0x1u)             /**< Get SPISRxFIFOEmpty from register */
#define  SPIS_RX_FIFO_LIMIT_DET_RSHIFT                      5                             /**< Shift for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET_RMASK                       0x20u                         /**< Mask for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET_RBMASK                      0x1u                          /**< Base mask for SPISRxFIFOLimitDet */
#define  SPIS_RX_FIFO_LIMIT_DET_R(x)                        (((x)&0x1u)<<5)               /**< Set SPISRxFIFOLimitDet in register */
#define  GET_SPIS_RX_FIFO_LIMIT_DET_R(reg)                  (((reg)>>5)&0x1u)             /**< Get SPISRxFIFOLimitDet from register */
#define  SPIS_RX_FIFO_FULL_RSHIFT                           6                             /**< Shift for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL_RMASK                            0x40u                         /**< Mask for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL_RBMASK                           0x1u                          /**< Base mask for SPISRxFIFOFull */
#define  SPIS_RX_FIFO_FULL_R(x)                             (((x)&0x1u)<<6)               /**< Set SPISRxFIFOFull in register */
#define  GET_SPIS_RX_FIFO_FULL_R(reg)                       (((reg)>>6)&0x1u)             /**< Get SPISRxFIFOFull from register */

// RegSPISFIFOStat.regs.SPISTxFIFONumBytes
#define  SPIS_TX_FIFO_NUM_BYTES_GSHIFT                      16                            /**< Shift for group SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_GSIZE                       8                             /**< Size of group SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_GMASK                       0x00FF0000u                   /**< Mask for group SPISTxFIFONumBytes */

#define  SPIS_TX_FIFO_NUM_BYTES_RSHIFT                      0                             /**< Shift for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_RMASK                       0x7Fu                         /**< Mask for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_RBMASK                      0x7Fu                         /**< Base mask for SPISTxFIFONumBytes */
#define  SPIS_TX_FIFO_NUM_BYTES_R(x)                        (((x)&0x7Fu)<<0)              /**< Set SPISTxFIFONumBytes in register */
#define  GET_SPIS_TX_FIFO_NUM_BYTES_R(reg)                  (((reg)>>0)&0x7Fu)            /**< Get SPISTxFIFONumBytes from register */

// RegSPISFIFOStat.regs.SPISRxFIFONumBytes
#define  SPIS_RX_FIFO_NUM_BYTES_GSHIFT                      24                            /**< Shift for group SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_GSIZE                       8                             /**< Size of group SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_GMASK                       0xFF000000u                   /**< Mask for group SPISRxFIFONumBytes */

#define  SPIS_RX_FIFO_NUM_BYTES_RSHIFT                      0                             /**< Shift for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_RMASK                       0x7Fu                         /**< Mask for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_RBMASK                      0x7Fu                         /**< Base mask for SPISRxFIFONumBytes */
#define  SPIS_RX_FIFO_NUM_BYTES_R(x)                        (((x)&0x7Fu)<<0)              /**< Set SPISRxFIFONumBytes in register */
#define  GET_SPIS_RX_FIFO_NUM_BYTES_R(reg)                  (((reg)>>0)&0x7Fu)            /**< Get SPISRxFIFONumBytes from register */
/** @} */



/** @} End of group SPISlave_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_SPI_SLAVE_H */
