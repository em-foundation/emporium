////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_irq.h
///
/// @project    T9305
///
/// @brief      IRQ register and bit field definitions
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

#ifndef _T9305_IRQ_H
#define _T9305_IRQ_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup IRQ_Registers Interrupt Manager Register Map - registers
 * @{
 ******************************************************************************/


/** Protocol Timer IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimEn_t;


/** Protocol Timer IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimEnSet_t;


/** Protocol Timer IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimEnClr_t;


/** Protocol Timer IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimMsk_t;


/** Protocol Timer IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimMskSet_t;


/** Protocol Timer IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimMskClr_t;


/** Protocol Timer IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimSts_t;


/** Protocol Timer IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimStsSet_t;


/** Protocol Timer IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQProtTimStsClr_t;


/** Sleep Timer IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimEn_t;


/** Sleep Timer IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimEnSet_t;


/** Sleep Timer IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimEnClr_t;


/** Sleep Timer IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimMsk_t;


/** Sleep Timer IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimMskSet_t;


/** Sleep Timer IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimMskClr_t;


/** Sleep Timer IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimSts_t;


/** Sleep Timer IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimStsSet_t;


/** Sleep Timer IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSleepTimStsClr_t;


/** Radio IRQ (RF controller + Packet processor) enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFEn_t;


/** Radio IRQ (RF controller + Packet processor) enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFEnSet_t;


/** Radio IRQ (RF controller + Packet processor) enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFEnClr_t;


/** Radio IRQ (RF controller + Packet processor) mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFMsk_t;


/** Radio IRQ (RF controller + Packet processor) mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFMskSet_t;


/** Radio IRQ (RF controller + Packet processor) mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFMskClr_t;


/** Radio IRQ (RF controller + Packet processor) status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFSts_t;


/** Radio IRQ (RF controller + Packet processor) status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFStsSet_t;


/** Radio IRQ (RF controller + Packet processor) status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRFStsClr_t;


/** SPI Slave IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISEn_t;


/** SPI Slave IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISEnSet_t;


/** SPI Slave IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISEnClr_t;


/** SPI Slave IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISMsk_t;


/** SPI Slave IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISMskSet_t;


/** SPI Slave IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISMskClr_t;


/** SPI Slave IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISSts_t;


/** SPI Slave IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISStsSet_t;


/** SPI Slave IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPISStsClr_t;


/** UART IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTEn_t;


/** UART IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTEnSet_t;


/** UART IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTEnClr_t;


/** UART IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTMsk_t;


/** UART IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTMskSet_t;


/** UART IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTMskClr_t;


/** UART IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTSts_t;


/** UART IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTStsSet_t;


/** UART IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUARTStsClr_t;


/** GPIO IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOEn_t;


/** GPIO IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOEnSet_t;


/** GPIO IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOEnClr_t;


/** GPIO IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOMsk_t;


/** GPIO IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOMskSet_t;


/** GPIO IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOMskClr_t;


/** GPIO IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOSts_t;


/** GPIO IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOStsSet_t;


/** GPIO IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQGPIOStsClr_t;


/** Universal Timer IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimEn_t;


/** Universal Timer IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimEnSet_t;


/** Universal Timer IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimEnClr_t;


/** Universal Timer IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimMsk_t;


/** Universal Timer IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimMskSet_t;


/** Universal Timer IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimMskClr_t;


/** Universal Timer IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimSts_t;


/** Universal Timer IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimStsSet_t;


/** Universal Timer IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQUniTimStsClr_t;


/** SPI Master IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMEn_t;


/** SPI Master IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMEnSet_t;


/** SPI Master IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMEnClr_t;


/** SPI Master IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMMsk_t;


/** SPI Master IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMMskSet_t;


/** SPI Master IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMMskClr_t;


/** SPI Master IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMSts_t;


/** SPI Master IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMStsSet_t;


/** SPI Master IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSPIMStsClr_t;


/** I2C Master IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CEn_t;


/** I2C Master IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CEnSet_t;


/** I2C Master IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CEnClr_t;


/** I2C Master IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CMsk_t;


/** I2C Master IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CMskSet_t;


/** I2C Master IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CMskClr_t;


/** I2C Master IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CSts_t;


/** I2C Master IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CStsSet_t;


/** I2C Master IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQI2CStsClr_t;


/** RC Calibration IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalEn_t;


/** RC Calibration IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalEnSet_t;


/** RC Calibration IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalEnClr_t;


/** RC Calibration IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalMsk_t;


/** RC Calibration IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalMskSet_t;


/** RC Calibration IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalMskClr_t;


/** RC Calibration IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalSts_t;


/** RC Calibration IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalStsSet_t;


/** RC Calibration IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRCCalStsClr_t;


/** A/D convertor IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcEn_t;


/** A/D convertor IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcEnSet_t;


/** A/D convertor IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcEnClr_t;


/** A/D convertor IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcMsk_t;


/** A/D convertor IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcMskSet_t;


/** A/D convertor IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcMskClr_t;


/** A/D convertor IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcSts_t;


/** A/D convertor IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcStsSet_t;


/** A/D convertor IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqAdcStsClr_t;


/** PML IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLEn_t;


/** PML IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLEnSet_t;


/** PML IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLEnClr_t;


/** PML IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLMsk_t;


/** PML IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLMskSet_t;


/** PML IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLMskClr_t;


/** PML IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLSts_t;


/** PML IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLStsSet_t;


/** PML IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQPMLStsClr_t;


/** NVM IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmEn_t;


/** NVM IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmEnSet_t;


/** NVM IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmEnClr_t;


/** NVM IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmMsk_t;


/** NVM IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmMskSet_t;


/** NVM IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmMskClr_t;


/** NVM IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmSts_t;


/** NVM IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmStsSet_t;


/** NVM IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqNvmStsClr_t;


/** QDec IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecEn_t;


/** QDec IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecEnSet_t;


/** QDec IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecEnClr_t;


/** QDec IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecMsk_t;


/** QDec IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecMskSet_t;


/** QDec IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecMskClr_t;


/** QDec IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecSts_t;


/** QDec IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecStsSet_t;


/** QDec IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqQDecStsClr_t;


/** USB EPs IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbEn_t;


/** USB EPs IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbEnSet_t;


/** USB EPs IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbEnClr_t;


/** USB EPs IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbMsk_t;


/** USB EPs IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbMskSet_t;


/** USB EPs IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbMskClr_t;


/** USB EPs IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbSts_t;


/** USB EPs IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbStsSet_t;


/** USB EPs IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqUsbStsClr_t;


/** Crypto Unit IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoEn_t;


/** Crypto Unit IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoEnSet_t;


/** Crypto Unit IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoEnClr_t;


/** Crypto Unit IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoMsk_t;


/** Crypto Unit IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoMskSet_t;


/** Crypto Unit IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoMskClr_t;


/** Crypto Unit IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoSts_t;


/** Crypto Unit IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoStsSet_t;


/** Crypto Unit IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqCryptoStsClr_t;


/** I2S IRQ enable */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sEn_t;


/** I2S IRQ enable set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sEnSet_t;


/** I2S IRQ enable clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sEnClr_t;


/** I2S IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sMsk_t;


/** I2S IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sMskSet_t;


/** I2S IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sMskClr_t;


/** I2S IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sSts_t;


/** I2S IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sStsSet_t;


/** I2S IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIrqI2sStsClr_t;


/** RESERVED */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRESERVED0_t;


/** RESERVED */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRESERVED1_t;


/** RESERVED */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQRESERVED2_t;


/** Software IRQ mask */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWIMsk_t;


/** Software IRQ mask set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWIMskSet_t;


/** Software IRQ mask clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWIMskClr_t;


/** Software IRQ status */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWISts_t;


/** Software IRQ status set */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWIStsSet_t;


/** Software IRQ status clear */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegIRQSWIStsClr_t;

/** @} end of group IRQ_Regs */



/***************************************************************************//**
 * @defgroup IRQ_RegMap Interrupt Manager Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegIRQProtTimEn_t                                 RegIRQProtTimEn;              /**< Protocol Timer IRQ enable */
    __O   RegIRQProtTimEnSet_t                              RegIRQProtTimEnSet;           /**< Protocol Timer IRQ enable set */
    __O   RegIRQProtTimEnClr_t                              RegIRQProtTimEnClr;           /**< Protocol Timer IRQ enable clear */
    __IO  RegIRQProtTimMsk_t                                RegIRQProtTimMsk;             /**< Protocol Timer IRQ mask */
    __O   RegIRQProtTimMskSet_t                             RegIRQProtTimMskSet;          /**< Protocol Timer IRQ mask set */
    __O   RegIRQProtTimMskClr_t                             RegIRQProtTimMskClr;          /**< Protocol Timer IRQ mask clear */
    __I   RegIRQProtTimSts_t                                RegIRQProtTimSts;             /**< Protocol Timer IRQ status */
    __O   RegIRQProtTimStsSet_t                             RegIRQProtTimStsSet;          /**< Protocol Timer IRQ status set */
    __O   RegIRQProtTimStsClr_t                             RegIRQProtTimStsClr;          /**< Protocol Timer IRQ status clear */
    __IO  RegIRQSleepTimEn_t                                RegIRQSleepTimEn;             /**< Sleep Timer IRQ enable */
    __O   RegIRQSleepTimEnSet_t                             RegIRQSleepTimEnSet;          /**< Sleep Timer IRQ enable set */
    __O   RegIRQSleepTimEnClr_t                             RegIRQSleepTimEnClr;          /**< Sleep Timer IRQ enable clear */
    __IO  RegIRQSleepTimMsk_t                               RegIRQSleepTimMsk;            /**< Sleep Timer IRQ mask */
    __O   RegIRQSleepTimMskSet_t                            RegIRQSleepTimMskSet;         /**< Sleep Timer IRQ mask set */
    __O   RegIRQSleepTimMskClr_t                            RegIRQSleepTimMskClr;         /**< Sleep Timer IRQ mask clear */
    __I   RegIRQSleepTimSts_t                               RegIRQSleepTimSts;            /**< Sleep Timer IRQ status */
    __O   RegIRQSleepTimStsSet_t                            RegIRQSleepTimStsSet;         /**< Sleep Timer IRQ status set */
    __O   RegIRQSleepTimStsClr_t                            RegIRQSleepTimStsClr;         /**< Sleep Timer IRQ status clear */
    __IO  RegIRQRFEn_t                                      RegIRQRFEn;                   /**< Radio IRQ (RF controller + Packet processor) enable */
    __O   RegIRQRFEnSet_t                                   RegIRQRFEnSet;                /**< Radio IRQ (RF controller + Packet processor) enable set */
    __O   RegIRQRFEnClr_t                                   RegIRQRFEnClr;                /**< Radio IRQ (RF controller + Packet processor) enable clear */
    __IO  RegIRQRFMsk_t                                     RegIRQRFMsk;                  /**< Radio IRQ (RF controller + Packet processor) mask */
    __O   RegIRQRFMskSet_t                                  RegIRQRFMskSet;               /**< Radio IRQ (RF controller + Packet processor) mask set */
    __O   RegIRQRFMskClr_t                                  RegIRQRFMskClr;               /**< Radio IRQ (RF controller + Packet processor) mask clear */
    __I   RegIRQRFSts_t                                     RegIRQRFSts;                  /**< Radio IRQ (RF controller + Packet processor) status */
    __O   RegIRQRFStsSet_t                                  RegIRQRFStsSet;               /**< Radio IRQ (RF controller + Packet processor) status set */
    __O   RegIRQRFStsClr_t                                  RegIRQRFStsClr;               /**< Radio IRQ (RF controller + Packet processor) status clear */
    __IO  RegIRQSPISEn_t                                    RegIRQSPISEn;                 /**< SPI Slave IRQ enable */
    __O   RegIRQSPISEnSet_t                                 RegIRQSPISEnSet;              /**< SPI Slave IRQ enable set */
    __O   RegIRQSPISEnClr_t                                 RegIRQSPISEnClr;              /**< SPI Slave IRQ enable clear */
    __IO  RegIRQSPISMsk_t                                   RegIRQSPISMsk;                /**< SPI Slave IRQ mask */
    __O   RegIRQSPISMskSet_t                                RegIRQSPISMskSet;             /**< SPI Slave IRQ mask set */
    __O   RegIRQSPISMskClr_t                                RegIRQSPISMskClr;             /**< SPI Slave IRQ mask clear */
    __I   RegIRQSPISSts_t                                   RegIRQSPISSts;                /**< SPI Slave IRQ status */
    __O   RegIRQSPISStsSet_t                                RegIRQSPISStsSet;             /**< SPI Slave IRQ status set */
    __O   RegIRQSPISStsClr_t                                RegIRQSPISStsClr;             /**< SPI Slave IRQ status clear */
    __IO  RegIRQUARTEn_t                                    RegIRQUARTEn;                 /**< UART IRQ enable */
    __O   RegIRQUARTEnSet_t                                 RegIRQUARTEnSet;              /**< UART IRQ enable set */
    __O   RegIRQUARTEnClr_t                                 RegIRQUARTEnClr;              /**< UART IRQ enable clear */
    __IO  RegIRQUARTMsk_t                                   RegIRQUARTMsk;                /**< UART IRQ mask */
    __O   RegIRQUARTMskSet_t                                RegIRQUARTMskSet;             /**< UART IRQ mask set */
    __O   RegIRQUARTMskClr_t                                RegIRQUARTMskClr;             /**< UART IRQ mask clear */
    __I   RegIRQUARTSts_t                                   RegIRQUARTSts;                /**< UART IRQ status */
    __O   RegIRQUARTStsSet_t                                RegIRQUARTStsSet;             /**< UART IRQ status set */
    __O   RegIRQUARTStsClr_t                                RegIRQUARTStsClr;             /**< UART IRQ status clear */
    __IO  RegIRQGPIOEn_t                                    RegIRQGPIOEn;                 /**< GPIO IRQ enable */
    __O   RegIRQGPIOEnSet_t                                 RegIRQGPIOEnSet;              /**< GPIO IRQ enable set */
    __O   RegIRQGPIOEnClr_t                                 RegIRQGPIOEnClr;              /**< GPIO IRQ enable clear */
    __IO  RegIRQGPIOMsk_t                                   RegIRQGPIOMsk;                /**< GPIO IRQ mask */
    __O   RegIRQGPIOMskSet_t                                RegIRQGPIOMskSet;             /**< GPIO IRQ mask set */
    __O   RegIRQGPIOMskClr_t                                RegIRQGPIOMskClr;             /**< GPIO IRQ mask clear */
    __I   RegIRQGPIOSts_t                                   RegIRQGPIOSts;                /**< GPIO IRQ status */
    __O   RegIRQGPIOStsSet_t                                RegIRQGPIOStsSet;             /**< GPIO IRQ status set */
    __O   RegIRQGPIOStsClr_t                                RegIRQGPIOStsClr;             /**< GPIO IRQ status clear */
    __IO  RegIRQUniTimEn_t                                  RegIRQUniTimEn;               /**< Universal Timer IRQ enable */
    __O   RegIRQUniTimEnSet_t                               RegIRQUniTimEnSet;            /**< Universal Timer IRQ enable set */
    __O   RegIRQUniTimEnClr_t                               RegIRQUniTimEnClr;            /**< Universal Timer IRQ enable clear */
    __IO  RegIRQUniTimMsk_t                                 RegIRQUniTimMsk;              /**< Universal Timer IRQ mask */
    __O   RegIRQUniTimMskSet_t                              RegIRQUniTimMskSet;           /**< Universal Timer IRQ mask set */
    __O   RegIRQUniTimMskClr_t                              RegIRQUniTimMskClr;           /**< Universal Timer IRQ mask clear */
    __I   RegIRQUniTimSts_t                                 RegIRQUniTimSts;              /**< Universal Timer IRQ status */
    __O   RegIRQUniTimStsSet_t                              RegIRQUniTimStsSet;           /**< Universal Timer IRQ status set */
    __O   RegIRQUniTimStsClr_t                              RegIRQUniTimStsClr;           /**< Universal Timer IRQ status clear */
    __IO  RegIRQSPIMEn_t                                    RegIRQSPIMEn;                 /**< SPI Master IRQ enable */
    __O   RegIRQSPIMEnSet_t                                 RegIRQSPIMEnSet;              /**< SPI Master IRQ enable set */
    __O   RegIRQSPIMEnClr_t                                 RegIRQSPIMEnClr;              /**< SPI Master IRQ enable clear */
    __IO  RegIRQSPIMMsk_t                                   RegIRQSPIMMsk;                /**< SPI Master IRQ mask */
    __O   RegIRQSPIMMskSet_t                                RegIRQSPIMMskSet;             /**< SPI Master IRQ mask set */
    __O   RegIRQSPIMMskClr_t                                RegIRQSPIMMskClr;             /**< SPI Master IRQ mask clear */
    __I   RegIRQSPIMSts_t                                   RegIRQSPIMSts;                /**< SPI Master IRQ status */
    __O   RegIRQSPIMStsSet_t                                RegIRQSPIMStsSet;             /**< SPI Master IRQ status set */
    __O   RegIRQSPIMStsClr_t                                RegIRQSPIMStsClr;             /**< SPI Master IRQ status clear */
    __IO  RegIRQI2CEn_t                                     RegIRQI2CEn;                  /**< I2C Master IRQ enable */
    __O   RegIRQI2CEnSet_t                                  RegIRQI2CEnSet;               /**< I2C Master IRQ enable set */
    __O   RegIRQI2CEnClr_t                                  RegIRQI2CEnClr;               /**< I2C Master IRQ enable clear */
    __IO  RegIRQI2CMsk_t                                    RegIRQI2CMsk;                 /**< I2C Master IRQ mask */
    __O   RegIRQI2CMskSet_t                                 RegIRQI2CMskSet;              /**< I2C Master IRQ mask set */
    __O   RegIRQI2CMskClr_t                                 RegIRQI2CMskClr;              /**< I2C Master IRQ mask clear */
    __I   RegIRQI2CSts_t                                    RegIRQI2CSts;                 /**< I2C Master IRQ status */
    __O   RegIRQI2CStsSet_t                                 RegIRQI2CStsSet;              /**< I2C Master IRQ status set */
    __O   RegIRQI2CStsClr_t                                 RegIRQI2CStsClr;              /**< I2C Master IRQ status clear */
    __IO  RegIRQRCCalEn_t                                   RegIRQRCCalEn;                /**< RC Calibration IRQ enable */
    __O   RegIRQRCCalEnSet_t                                RegIRQRCCalEnSet;             /**< RC Calibration IRQ enable set */
    __O   RegIRQRCCalEnClr_t                                RegIRQRCCalEnClr;             /**< RC Calibration IRQ enable clear */
    __IO  RegIRQRCCalMsk_t                                  RegIRQRCCalMsk;               /**< RC Calibration IRQ mask */
    __O   RegIRQRCCalMskSet_t                               RegIRQRCCalMskSet;            /**< RC Calibration IRQ mask set */
    __O   RegIRQRCCalMskClr_t                               RegIRQRCCalMskClr;            /**< RC Calibration IRQ mask clear */
    __I   RegIRQRCCalSts_t                                  RegIRQRCCalSts;               /**< RC Calibration IRQ status */
    __O   RegIRQRCCalStsSet_t                               RegIRQRCCalStsSet;            /**< RC Calibration IRQ status set */
    __O   RegIRQRCCalStsClr_t                               RegIRQRCCalStsClr;            /**< RC Calibration IRQ status clear */
    __IO  RegIrqAdcEn_t                                     RegIrqAdcEn;                  /**< A/D convertor IRQ enable */
    __O   RegIrqAdcEnSet_t                                  RegIrqAdcEnSet;               /**< A/D convertor IRQ enable set */
    __O   RegIrqAdcEnClr_t                                  RegIrqAdcEnClr;               /**< A/D convertor IRQ enable clear */
    __IO  RegIrqAdcMsk_t                                    RegIrqAdcMsk;                 /**< A/D convertor IRQ mask */
    __O   RegIrqAdcMskSet_t                                 RegIrqAdcMskSet;              /**< A/D convertor IRQ mask set */
    __O   RegIrqAdcMskClr_t                                 RegIrqAdcMskClr;              /**< A/D convertor IRQ mask clear */
    __I   RegIrqAdcSts_t                                    RegIrqAdcSts;                 /**< A/D convertor IRQ status */
    __O   RegIrqAdcStsSet_t                                 RegIrqAdcStsSet;              /**< A/D convertor IRQ status set */
    __O   RegIrqAdcStsClr_t                                 RegIrqAdcStsClr;              /**< A/D convertor IRQ status clear */
    __IO  RegIRQPMLEn_t                                     RegIRQPMLEn;                  /**< PML IRQ enable */
    __O   RegIRQPMLEnSet_t                                  RegIRQPMLEnSet;               /**< PML IRQ enable set */
    __O   RegIRQPMLEnClr_t                                  RegIRQPMLEnClr;               /**< PML IRQ enable clear */
    __IO  RegIRQPMLMsk_t                                    RegIRQPMLMsk;                 /**< PML IRQ mask */
    __O   RegIRQPMLMskSet_t                                 RegIRQPMLMskSet;              /**< PML IRQ mask set */
    __O   RegIRQPMLMskClr_t                                 RegIRQPMLMskClr;              /**< PML IRQ mask clear */
    __I   RegIRQPMLSts_t                                    RegIRQPMLSts;                 /**< PML IRQ status */
    __O   RegIRQPMLStsSet_t                                 RegIRQPMLStsSet;              /**< PML IRQ status set */
    __O   RegIRQPMLStsClr_t                                 RegIRQPMLStsClr;              /**< PML IRQ status clear */
    __IO  RegIrqNvmEn_t                                     RegIrqNvmEn;                  /**< NVM IRQ enable */
    __O   RegIrqNvmEnSet_t                                  RegIrqNvmEnSet;               /**< NVM IRQ enable set */
    __O   RegIrqNvmEnClr_t                                  RegIrqNvmEnClr;               /**< NVM IRQ enable clear */
    __IO  RegIrqNvmMsk_t                                    RegIrqNvmMsk;                 /**< NVM IRQ mask */
    __O   RegIrqNvmMskSet_t                                 RegIrqNvmMskSet;              /**< NVM IRQ mask set */
    __O   RegIrqNvmMskClr_t                                 RegIrqNvmMskClr;              /**< NVM IRQ mask clear */
    __I   RegIrqNvmSts_t                                    RegIrqNvmSts;                 /**< NVM IRQ status */
    __O   RegIrqNvmStsSet_t                                 RegIrqNvmStsSet;              /**< NVM IRQ status set */
    __O   RegIrqNvmStsClr_t                                 RegIrqNvmStsClr;              /**< NVM IRQ status clear */
    __IO  RegIrqQDecEn_t                                    RegIrqQDecEn;                 /**< QDec IRQ enable */
    __O   RegIrqQDecEnSet_t                                 RegIrqQDecEnSet;              /**< QDec IRQ enable set */
    __O   RegIrqQDecEnClr_t                                 RegIrqQDecEnClr;              /**< QDec IRQ enable clear */
    __IO  RegIrqQDecMsk_t                                   RegIrqQDecMsk;                /**< QDec IRQ mask */
    __O   RegIrqQDecMskSet_t                                RegIrqQDecMskSet;             /**< QDec IRQ mask set */
    __O   RegIrqQDecMskClr_t                                RegIrqQDecMskClr;             /**< QDec IRQ mask clear */
    __I   RegIrqQDecSts_t                                   RegIrqQDecSts;                /**< QDec IRQ status */
    __O   RegIrqQDecStsSet_t                                RegIrqQDecStsSet;             /**< QDec IRQ status set */
    __O   RegIrqQDecStsClr_t                                RegIrqQDecStsClr;             /**< QDec IRQ status clear */
    __IO  RegIrqUsbEn_t                                     RegIrqUsbEn;                  /**< USB EPs IRQ enable */
    __O   RegIrqUsbEnSet_t                                  RegIrqUsbEnSet;               /**< USB EPs IRQ enable set */
    __O   RegIrqUsbEnClr_t                                  RegIrqUsbEnClr;               /**< USB EPs IRQ enable clear */
    __IO  RegIrqUsbMsk_t                                    RegIrqUsbMsk;                 /**< USB EPs IRQ mask */
    __O   RegIrqUsbMskSet_t                                 RegIrqUsbMskSet;              /**< USB EPs IRQ mask set */
    __O   RegIrqUsbMskClr_t                                 RegIrqUsbMskClr;              /**< USB EPs IRQ mask clear */
    __I   RegIrqUsbSts_t                                    RegIrqUsbSts;                 /**< USB EPs IRQ status */
    __O   RegIrqUsbStsSet_t                                 RegIrqUsbStsSet;              /**< USB EPs IRQ status set */
    __O   RegIrqUsbStsClr_t                                 RegIrqUsbStsClr;              /**< USB EPs IRQ status clear */
    __IO  RegIrqCryptoEn_t                                  RegIrqCryptoEn;               /**< Crypto Unit IRQ enable */
    __O   RegIrqCryptoEnSet_t                               RegIrqCryptoEnSet;            /**< Crypto Unit IRQ enable set */
    __O   RegIrqCryptoEnClr_t                               RegIrqCryptoEnClr;            /**< Crypto Unit IRQ enable clear */
    __IO  RegIrqCryptoMsk_t                                 RegIrqCryptoMsk;              /**< Crypto Unit IRQ mask */
    __O   RegIrqCryptoMskSet_t                              RegIrqCryptoMskSet;           /**< Crypto Unit IRQ mask set */
    __O   RegIrqCryptoMskClr_t                              RegIrqCryptoMskClr;           /**< Crypto Unit IRQ mask clear */
    __I   RegIrqCryptoSts_t                                 RegIrqCryptoSts;              /**< Crypto Unit IRQ status */
    __O   RegIrqCryptoStsSet_t                              RegIrqCryptoStsSet;           /**< Crypto Unit IRQ status set */
    __O   RegIrqCryptoStsClr_t                              RegIrqCryptoStsClr;           /**< Crypto Unit IRQ status clear */
    __IO  RegIrqI2sEn_t                                     RegIrqI2sEn;                  /**< I2S IRQ enable */
    __O   RegIrqI2sEnSet_t                                  RegIrqI2sEnSet;               /**< I2S IRQ enable set */
    __O   RegIrqI2sEnClr_t                                  RegIrqI2sEnClr;               /**< I2S IRQ enable clear */
    __IO  RegIrqI2sMsk_t                                    RegIrqI2sMsk;                 /**< I2S IRQ mask */
    __O   RegIrqI2sMskSet_t                                 RegIrqI2sMskSet;              /**< I2S IRQ mask set */
    __O   RegIrqI2sMskClr_t                                 RegIrqI2sMskClr;              /**< I2S IRQ mask clear */
    __I   RegIrqI2sSts_t                                    RegIrqI2sSts;                 /**< I2S IRQ status */
    __O   RegIrqI2sStsSet_t                                 RegIrqI2sStsSet;              /**< I2S IRQ status set */
    __O   RegIrqI2sStsClr_t                                 RegIrqI2sStsClr;              /**< I2S IRQ status clear */
    __I   RegIRQRESERVED0_t                                 RegIRQRESERVED0;              /**< RESERVED */
    __I   RegIRQRESERVED1_t                                 RegIRQRESERVED1;              /**< RESERVED */
    __I   RegIRQRESERVED2_t                                 RegIRQRESERVED2;              /**< RESERVED */
    __IO  RegIRQSWIMsk_t                                    RegIRQSWIMsk;                 /**< Software IRQ mask */
    __O   RegIRQSWIMskSet_t                                 RegIRQSWIMskSet;              /**< Software IRQ mask set */
    __O   RegIRQSWIMskClr_t                                 RegIRQSWIMskClr;              /**< Software IRQ mask clear */
    __I   RegIRQSWISts_t                                    RegIRQSWISts;                 /**< Software IRQ status */
    __O   RegIRQSWIStsSet_t                                 RegIRQSWIStsSet;              /**< Software IRQ status set */
    __O   RegIRQSWIStsClr_t                                 RegIRQSWIStsClr;              /**< Software IRQ status clear */
} IRQ_RegMap_t;

/** @} end of group IRQ_RegMap */



/***************************************************************************//**
 * @defgroup IRQ_BitFields IRQ bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegIRQProtTimEn
 * @{
 */
// RegIRQProtTimEn.r32
#define  REG_IRQ_PROT_TIM_EN_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQProtTimEn */
#define  REG_IRQ_PROT_TIM_EN_MASK                           0x000007FFu                   /**< Mask for RegIRQProtTimEn */

#define  IRQ_PT_OUT_CMP_EN_SHIFT                            0                             /**< Shift for IRQPTOutCmpEn */
#define  IRQ_PT_OUT_CMP_EN_MASK                             0x000000FFu                   /**< Mask for IRQPTOutCmpEn */
#define  IRQ_PT_OUT_CMP_EN_BMASK                            0xFFu                         /**< Base mask for IRQPTOutCmpEn */
#define  IRQ_PT_OUT_CMP_EN(x)                               (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpEn in register */
#define  GET_IRQ_PT_OUT_CMP_EN(reg)                         (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpEn from register */
#define  IRQ_PT_FULL_VAL_EN_SHIFT                           8                             /**< Shift for IRQPTFullValEn */
#define  IRQ_PT_FULL_VAL_EN_MASK                            0x00000100u                   /**< Mask for IRQPTFullValEn */
#define  IRQ_PT_FULL_VAL_EN_BMASK                           0x1u                          /**< Base mask for IRQPTFullValEn */
#define  IRQ_PT_FULL_VAL_EN(x)                              (((x)&0x1u)<<8)               /**< Set IRQPTFullValEn in register */
#define  GET_IRQ_PT_FULL_VAL_EN(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQPTFullValEn from register */
#define  IRQ_PT_SYNC_START_EN_SHIFT                         9                             /**< Shift for IRQPTSyncStartEn */
#define  IRQ_PT_SYNC_START_EN_MASK                          0x00000200u                   /**< Mask for IRQPTSyncStartEn */
#define  IRQ_PT_SYNC_START_EN_BMASK                         0x1u                          /**< Base mask for IRQPTSyncStartEn */
#define  IRQ_PT_SYNC_START_EN(x)                            (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartEn in register */
#define  GET_IRQ_PT_SYNC_START_EN(reg)                      (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartEn from register */
#define  IRQ_PT_SYNC_STOP_EN_SHIFT                          10                            /**< Shift for IRQPTSyncStopEn */
#define  IRQ_PT_SYNC_STOP_EN_MASK                           0x00000400u                   /**< Mask for IRQPTSyncStopEn */
#define  IRQ_PT_SYNC_STOP_EN_BMASK                          0x1u                          /**< Base mask for IRQPTSyncStopEn */
#define  IRQ_PT_SYNC_STOP_EN(x)                             (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopEn in register */
#define  GET_IRQ_PT_SYNC_STOP_EN(reg)                       (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopEn from register */
/** @} */


/**
 * @name RegIRQProtTimEnSet
 * @{
 */
// RegIRQProtTimEnSet.r32
#define  REG_IRQ_PROT_TIM_EN_SET_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQProtTimEnSet */
#define  REG_IRQ_PROT_TIM_EN_SET_MASK                       0x000007FFu                   /**< Mask for RegIRQProtTimEnSet */

#define  IRQ_PT_OUT_CMP_EN_SET_SHIFT                        0                             /**< Shift for IRQPTOutCmpEnSet */
#define  IRQ_PT_OUT_CMP_EN_SET_MASK                         0x000000FFu                   /**< Mask for IRQPTOutCmpEnSet */
#define  IRQ_PT_OUT_CMP_EN_SET_BMASK                        0xFFu                         /**< Base mask for IRQPTOutCmpEnSet */
#define  IRQ_PT_OUT_CMP_EN_SET(x)                           (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpEnSet in register */
#define  GET_IRQ_PT_OUT_CMP_EN_SET(reg)                     (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpEnSet from register */
#define  IRQ_PT_FULL_VAL_EN_SET_SHIFT                       8                             /**< Shift for IRQPTFullValEnSet */
#define  IRQ_PT_FULL_VAL_EN_SET_MASK                        0x00000100u                   /**< Mask for IRQPTFullValEnSet */
#define  IRQ_PT_FULL_VAL_EN_SET_BMASK                       0x1u                          /**< Base mask for IRQPTFullValEnSet */
#define  IRQ_PT_FULL_VAL_EN_SET(x)                          (((x)&0x1u)<<8)               /**< Set IRQPTFullValEnSet in register */
#define  GET_IRQ_PT_FULL_VAL_EN_SET(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQPTFullValEnSet from register */
#define  IRQ_PT_SYNC_START_EN_SET_SHIFT                     9                             /**< Shift for IRQPTSyncStartEnSet */
#define  IRQ_PT_SYNC_START_EN_SET_MASK                      0x00000200u                   /**< Mask for IRQPTSyncStartEnSet */
#define  IRQ_PT_SYNC_START_EN_SET_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStartEnSet */
#define  IRQ_PT_SYNC_START_EN_SET(x)                        (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartEnSet in register */
#define  GET_IRQ_PT_SYNC_START_EN_SET(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartEnSet from register */
#define  IRQ_PT_SYNC_STOP_EN_SET_SHIFT                      10                            /**< Shift for IRQPTSyncStopEnSet */
#define  IRQ_PT_SYNC_STOP_EN_SET_MASK                       0x00000400u                   /**< Mask for IRQPTSyncStopEnSet */
#define  IRQ_PT_SYNC_STOP_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQPTSyncStopEnSet */
#define  IRQ_PT_SYNC_STOP_EN_SET(x)                         (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopEnSet in register */
#define  GET_IRQ_PT_SYNC_STOP_EN_SET(reg)                   (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopEnSet from register */
/** @} */


/**
 * @name RegIRQProtTimEnClr
 * @{
 */
// RegIRQProtTimEnClr.r32
#define  REG_IRQ_PROT_TIM_EN_CLR_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQProtTimEnClr */
#define  REG_IRQ_PROT_TIM_EN_CLR_MASK                       0x000007FFu                   /**< Mask for RegIRQProtTimEnClr */

#define  IRQ_PT_OUT_CMP_EN_CLR_SHIFT                        0                             /**< Shift for IRQPTOutCmpEnClr */
#define  IRQ_PT_OUT_CMP_EN_CLR_MASK                         0x000000FFu                   /**< Mask for IRQPTOutCmpEnClr */
#define  IRQ_PT_OUT_CMP_EN_CLR_BMASK                        0xFFu                         /**< Base mask for IRQPTOutCmpEnClr */
#define  IRQ_PT_OUT_CMP_EN_CLR(x)                           (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpEnClr in register */
#define  GET_IRQ_PT_OUT_CMP_EN_CLR(reg)                     (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpEnClr from register */
#define  IRQ_PT_FULL_VAL_EN_CLR_SHIFT                       8                             /**< Shift for IRQPTFullValEnClr */
#define  IRQ_PT_FULL_VAL_EN_CLR_MASK                        0x00000100u                   /**< Mask for IRQPTFullValEnClr */
#define  IRQ_PT_FULL_VAL_EN_CLR_BMASK                       0x1u                          /**< Base mask for IRQPTFullValEnClr */
#define  IRQ_PT_FULL_VAL_EN_CLR(x)                          (((x)&0x1u)<<8)               /**< Set IRQPTFullValEnClr in register */
#define  GET_IRQ_PT_FULL_VAL_EN_CLR(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQPTFullValEnClr from register */
#define  IRQ_PT_SYNC_START_EN_CLR_SHIFT                     9                             /**< Shift for IRQPTSyncStartEnClr */
#define  IRQ_PT_SYNC_START_EN_CLR_MASK                      0x00000200u                   /**< Mask for IRQPTSyncStartEnClr */
#define  IRQ_PT_SYNC_START_EN_CLR_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStartEnClr */
#define  IRQ_PT_SYNC_START_EN_CLR(x)                        (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartEnClr in register */
#define  GET_IRQ_PT_SYNC_START_EN_CLR(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartEnClr from register */
#define  IRQ_PT_SYNC_STOP_EN_CLR_SHIFT                      10                            /**< Shift for IRQPTSyncStopEnClr */
#define  IRQ_PT_SYNC_STOP_EN_CLR_MASK                       0x00000400u                   /**< Mask for IRQPTSyncStopEnClr */
#define  IRQ_PT_SYNC_STOP_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQPTSyncStopEnClr */
#define  IRQ_PT_SYNC_STOP_EN_CLR(x)                         (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopEnClr in register */
#define  GET_IRQ_PT_SYNC_STOP_EN_CLR(reg)                   (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopEnClr from register */
/** @} */


/**
 * @name RegIRQProtTimMsk
 * @{
 */
// RegIRQProtTimMsk.r32
#define  REG_IRQ_PROT_TIM_MSK_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQProtTimMsk */
#define  REG_IRQ_PROT_TIM_MSK_MASK                          0x000007FFu                   /**< Mask for RegIRQProtTimMsk */

#define  IRQ_PT_OUT_CMP_MSK_SHIFT                           0                             /**< Shift for IRQPTOutCmpMsk */
#define  IRQ_PT_OUT_CMP_MSK_MASK                            0x000000FFu                   /**< Mask for IRQPTOutCmpMsk */
#define  IRQ_PT_OUT_CMP_MSK_BMASK                           0xFFu                         /**< Base mask for IRQPTOutCmpMsk */
#define  IRQ_PT_OUT_CMP_MSK(x)                              (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpMsk in register */
#define  GET_IRQ_PT_OUT_CMP_MSK(reg)                        (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpMsk from register */
#define  IRQ_PT_FULL_VAL_MSK_SHIFT                          8                             /**< Shift for IRQPTFullValMsk */
#define  IRQ_PT_FULL_VAL_MSK_MASK                           0x00000100u                   /**< Mask for IRQPTFullValMsk */
#define  IRQ_PT_FULL_VAL_MSK_BMASK                          0x1u                          /**< Base mask for IRQPTFullValMsk */
#define  IRQ_PT_FULL_VAL_MSK(x)                             (((x)&0x1u)<<8)               /**< Set IRQPTFullValMsk in register */
#define  GET_IRQ_PT_FULL_VAL_MSK(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQPTFullValMsk from register */
#define  IRQ_PT_SYNC_START_MSK_SHIFT                        9                             /**< Shift for IRQPTSyncStartMsk */
#define  IRQ_PT_SYNC_START_MSK_MASK                         0x00000200u                   /**< Mask for IRQPTSyncStartMsk */
#define  IRQ_PT_SYNC_START_MSK_BMASK                        0x1u                          /**< Base mask for IRQPTSyncStartMsk */
#define  IRQ_PT_SYNC_START_MSK(x)                           (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartMsk in register */
#define  GET_IRQ_PT_SYNC_START_MSK(reg)                     (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartMsk from register */
#define  IRQ_PT_SYNC_STOP_MSK_SHIFT                         10                            /**< Shift for IRQPTSyncStopMsk */
#define  IRQ_PT_SYNC_STOP_MSK_MASK                          0x00000400u                   /**< Mask for IRQPTSyncStopMsk */
#define  IRQ_PT_SYNC_STOP_MSK_BMASK                         0x1u                          /**< Base mask for IRQPTSyncStopMsk */
#define  IRQ_PT_SYNC_STOP_MSK(x)                            (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopMsk in register */
#define  GET_IRQ_PT_SYNC_STOP_MSK(reg)                      (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopMsk from register */
/** @} */


/**
 * @name RegIRQProtTimMskSet
 * @{
 */
// RegIRQProtTimMskSet.r32
#define  REG_IRQ_PROT_TIM_MSK_SET_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQProtTimMskSet */
#define  REG_IRQ_PROT_TIM_MSK_SET_MASK                      0x000007FFu                   /**< Mask for RegIRQProtTimMskSet */

#define  IRQ_PT_OUT_CMP_MSK_SET_SHIFT                       0                             /**< Shift for IRQPTOutCmpMskSet */
#define  IRQ_PT_OUT_CMP_MSK_SET_MASK                        0x000000FFu                   /**< Mask for IRQPTOutCmpMskSet */
#define  IRQ_PT_OUT_CMP_MSK_SET_BMASK                       0xFFu                         /**< Base mask for IRQPTOutCmpMskSet */
#define  IRQ_PT_OUT_CMP_MSK_SET(x)                          (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpMskSet in register */
#define  GET_IRQ_PT_OUT_CMP_MSK_SET(reg)                    (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpMskSet from register */
#define  IRQ_PT_FULL_VAL_MSK_SET_SHIFT                      8                             /**< Shift for IRQPTFullValMskSet */
#define  IRQ_PT_FULL_VAL_MSK_SET_MASK                       0x00000100u                   /**< Mask for IRQPTFullValMskSet */
#define  IRQ_PT_FULL_VAL_MSK_SET_BMASK                      0x1u                          /**< Base mask for IRQPTFullValMskSet */
#define  IRQ_PT_FULL_VAL_MSK_SET(x)                         (((x)&0x1u)<<8)               /**< Set IRQPTFullValMskSet in register */
#define  GET_IRQ_PT_FULL_VAL_MSK_SET(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQPTFullValMskSet from register */
#define  IRQ_PT_SYNC_START_MSK_SET_SHIFT                    9                             /**< Shift for IRQPTSyncStartMskSet */
#define  IRQ_PT_SYNC_START_MSK_SET_MASK                     0x00000200u                   /**< Mask for IRQPTSyncStartMskSet */
#define  IRQ_PT_SYNC_START_MSK_SET_BMASK                    0x1u                          /**< Base mask for IRQPTSyncStartMskSet */
#define  IRQ_PT_SYNC_START_MSK_SET(x)                       (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartMskSet in register */
#define  GET_IRQ_PT_SYNC_START_MSK_SET(reg)                 (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartMskSet from register */
#define  IRQ_PT_SYNC_STOP_MSK_SET_SHIFT                     10                            /**< Shift for IRQPTSyncStopMskSet */
#define  IRQ_PT_SYNC_STOP_MSK_SET_MASK                      0x00000400u                   /**< Mask for IRQPTSyncStopMskSet */
#define  IRQ_PT_SYNC_STOP_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStopMskSet */
#define  IRQ_PT_SYNC_STOP_MSK_SET(x)                        (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopMskSet in register */
#define  GET_IRQ_PT_SYNC_STOP_MSK_SET(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopMskSet from register */
/** @} */


/**
 * @name RegIRQProtTimMskClr
 * @{
 */
// RegIRQProtTimMskClr.r32
#define  REG_IRQ_PROT_TIM_MSK_CLR_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQProtTimMskClr */
#define  REG_IRQ_PROT_TIM_MSK_CLR_MASK                      0x000007FFu                   /**< Mask for RegIRQProtTimMskClr */

#define  IRQ_PT_OUT_CMP_MSK_CLR_SHIFT                       0                             /**< Shift for IRQPTOutCmpMskClr */
#define  IRQ_PT_OUT_CMP_MSK_CLR_MASK                        0x000000FFu                   /**< Mask for IRQPTOutCmpMskClr */
#define  IRQ_PT_OUT_CMP_MSK_CLR_BMASK                       0xFFu                         /**< Base mask for IRQPTOutCmpMskClr */
#define  IRQ_PT_OUT_CMP_MSK_CLR(x)                          (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpMskClr in register */
#define  GET_IRQ_PT_OUT_CMP_MSK_CLR(reg)                    (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpMskClr from register */
#define  IRQ_PT_FULL_VAL_MSK_CLR_SHIFT                      8                             /**< Shift for IRQPTFullValMskClr */
#define  IRQ_PT_FULL_VAL_MSK_CLR_MASK                       0x00000100u                   /**< Mask for IRQPTFullValMskClr */
#define  IRQ_PT_FULL_VAL_MSK_CLR_BMASK                      0x1u                          /**< Base mask for IRQPTFullValMskClr */
#define  IRQ_PT_FULL_VAL_MSK_CLR(x)                         (((x)&0x1u)<<8)               /**< Set IRQPTFullValMskClr in register */
#define  GET_IRQ_PT_FULL_VAL_MSK_CLR(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQPTFullValMskClr from register */
#define  IRQ_PT_SYNC_START_MSK_CLR_SHIFT                    9                             /**< Shift for IRQPTSyncStartMskClr */
#define  IRQ_PT_SYNC_START_MSK_CLR_MASK                     0x00000200u                   /**< Mask for IRQPTSyncStartMskClr */
#define  IRQ_PT_SYNC_START_MSK_CLR_BMASK                    0x1u                          /**< Base mask for IRQPTSyncStartMskClr */
#define  IRQ_PT_SYNC_START_MSK_CLR(x)                       (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartMskClr in register */
#define  GET_IRQ_PT_SYNC_START_MSK_CLR(reg)                 (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartMskClr from register */
#define  IRQ_PT_SYNC_STOP_MSK_CLR_SHIFT                     10                            /**< Shift for IRQPTSyncStopMskClr */
#define  IRQ_PT_SYNC_STOP_MSK_CLR_MASK                      0x00000400u                   /**< Mask for IRQPTSyncStopMskClr */
#define  IRQ_PT_SYNC_STOP_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStopMskClr */
#define  IRQ_PT_SYNC_STOP_MSK_CLR(x)                        (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopMskClr in register */
#define  GET_IRQ_PT_SYNC_STOP_MSK_CLR(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopMskClr from register */
/** @} */


/**
 * @name RegIRQProtTimSts
 * @{
 */
// RegIRQProtTimSts.r32
#define  REG_IRQ_PROT_TIM_STS_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQProtTimSts */
#define  REG_IRQ_PROT_TIM_STS_MASK                          0x000007FFu                   /**< Mask for RegIRQProtTimSts */

#define  IRQ_PT_OUT_CMP_STS_SHIFT                           0                             /**< Shift for IRQPTOutCmpSts */
#define  IRQ_PT_OUT_CMP_STS_MASK                            0x000000FFu                   /**< Mask for IRQPTOutCmpSts */
#define  IRQ_PT_OUT_CMP_STS_BMASK                           0xFFu                         /**< Base mask for IRQPTOutCmpSts */
#define  IRQ_PT_OUT_CMP_STS(x)                              (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpSts in register */
#define  GET_IRQ_PT_OUT_CMP_STS(reg)                        (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpSts from register */
#define  IRQ_PT_FULL_VAL_STS_SHIFT                          8                             /**< Shift for IRQPTFullValSts */
#define  IRQ_PT_FULL_VAL_STS_MASK                           0x00000100u                   /**< Mask for IRQPTFullValSts */
#define  IRQ_PT_FULL_VAL_STS_BMASK                          0x1u                          /**< Base mask for IRQPTFullValSts */
#define  IRQ_PT_FULL_VAL_STS(x)                             (((x)&0x1u)<<8)               /**< Set IRQPTFullValSts in register */
#define  GET_IRQ_PT_FULL_VAL_STS(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQPTFullValSts from register */
#define  IRQ_PT_SYNC_START_STS_SHIFT                        9                             /**< Shift for IRQPTSyncStartSts */
#define  IRQ_PT_SYNC_START_STS_MASK                         0x00000200u                   /**< Mask for IRQPTSyncStartSts */
#define  IRQ_PT_SYNC_START_STS_BMASK                        0x1u                          /**< Base mask for IRQPTSyncStartSts */
#define  IRQ_PT_SYNC_START_STS(x)                           (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartSts in register */
#define  GET_IRQ_PT_SYNC_START_STS(reg)                     (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartSts from register */
#define  IRQ_PT_SYNC_STOP_STS_SHIFT                         10                            /**< Shift for IRQPTSyncStopSts */
#define  IRQ_PT_SYNC_STOP_STS_MASK                          0x00000400u                   /**< Mask for IRQPTSyncStopSts */
#define  IRQ_PT_SYNC_STOP_STS_BMASK                         0x1u                          /**< Base mask for IRQPTSyncStopSts */
#define  IRQ_PT_SYNC_STOP_STS(x)                            (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopSts in register */
#define  GET_IRQ_PT_SYNC_STOP_STS(reg)                      (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopSts from register */
/** @} */


/**
 * @name RegIRQProtTimStsSet
 * @{
 */
// RegIRQProtTimStsSet.r32
#define  REG_IRQ_PROT_TIM_STS_SET_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQProtTimStsSet */
#define  REG_IRQ_PROT_TIM_STS_SET_MASK                      0x000007FFu                   /**< Mask for RegIRQProtTimStsSet */

#define  IRQ_PT_OUT_CMP_STS_SET_SHIFT                       0                             /**< Shift for IRQPTOutCmpStsSet */
#define  IRQ_PT_OUT_CMP_STS_SET_MASK                        0x000000FFu                   /**< Mask for IRQPTOutCmpStsSet */
#define  IRQ_PT_OUT_CMP_STS_SET_BMASK                       0xFFu                         /**< Base mask for IRQPTOutCmpStsSet */
#define  IRQ_PT_OUT_CMP_STS_SET(x)                          (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpStsSet in register */
#define  GET_IRQ_PT_OUT_CMP_STS_SET(reg)                    (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpStsSet from register */
#define  IRQ_PT_FULL_VAL_STS_SET_SHIFT                      8                             /**< Shift for IRQPTFullValStsSet */
#define  IRQ_PT_FULL_VAL_STS_SET_MASK                       0x00000100u                   /**< Mask for IRQPTFullValStsSet */
#define  IRQ_PT_FULL_VAL_STS_SET_BMASK                      0x1u                          /**< Base mask for IRQPTFullValStsSet */
#define  IRQ_PT_FULL_VAL_STS_SET(x)                         (((x)&0x1u)<<8)               /**< Set IRQPTFullValStsSet in register */
#define  GET_IRQ_PT_FULL_VAL_STS_SET(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQPTFullValStsSet from register */
#define  IRQ_PT_SYNC_START_STS_SET_SHIFT                    9                             /**< Shift for IRQPTSyncStartStsSet */
#define  IRQ_PT_SYNC_START_STS_SET_MASK                     0x00000200u                   /**< Mask for IRQPTSyncStartStsSet */
#define  IRQ_PT_SYNC_START_STS_SET_BMASK                    0x1u                          /**< Base mask for IRQPTSyncStartStsSet */
#define  IRQ_PT_SYNC_START_STS_SET(x)                       (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartStsSet in register */
#define  GET_IRQ_PT_SYNC_START_STS_SET(reg)                 (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartStsSet from register */
#define  IRQ_PT_SYNC_STOP_STS_SET_SHIFT                     10                            /**< Shift for IRQPTSyncStopStsSet */
#define  IRQ_PT_SYNC_STOP_STS_SET_MASK                      0x00000400u                   /**< Mask for IRQPTSyncStopStsSet */
#define  IRQ_PT_SYNC_STOP_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStopStsSet */
#define  IRQ_PT_SYNC_STOP_STS_SET(x)                        (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopStsSet in register */
#define  GET_IRQ_PT_SYNC_STOP_STS_SET(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopStsSet from register */
/** @} */


/**
 * @name RegIRQProtTimStsClr
 * @{
 */
// RegIRQProtTimStsClr.r32
#define  REG_IRQ_PROT_TIM_STS_CLR_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQProtTimStsClr */
#define  REG_IRQ_PROT_TIM_STS_CLR_MASK                      0x000007FFu                   /**< Mask for RegIRQProtTimStsClr */

#define  IRQ_PT_OUT_CMP_STS_CLR_SHIFT                       0                             /**< Shift for IRQPTOutCmpStsClr */
#define  IRQ_PT_OUT_CMP_STS_CLR_MASK                        0x000000FFu                   /**< Mask for IRQPTOutCmpStsClr */
#define  IRQ_PT_OUT_CMP_STS_CLR_BMASK                       0xFFu                         /**< Base mask for IRQPTOutCmpStsClr */
#define  IRQ_PT_OUT_CMP_STS_CLR(x)                          (((x)&0xFFu)<<0)              /**< Set IRQPTOutCmpStsClr in register */
#define  GET_IRQ_PT_OUT_CMP_STS_CLR(reg)                    (((reg)>>0)&0xFFu)            /**< Get IRQPTOutCmpStsClr from register */
#define  IRQ_PT_FULL_VAL_STS_CLR_SHIFT                      8                             /**< Shift for IRQPTFullValStsClr */
#define  IRQ_PT_FULL_VAL_STS_CLR_MASK                       0x00000100u                   /**< Mask for IRQPTFullValStsClr */
#define  IRQ_PT_FULL_VAL_STS_CLR_BMASK                      0x1u                          /**< Base mask for IRQPTFullValStsClr */
#define  IRQ_PT_FULL_VAL_STS_CLR(x)                         (((x)&0x1u)<<8)               /**< Set IRQPTFullValStsClr in register */
#define  GET_IRQ_PT_FULL_VAL_STS_CLR(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQPTFullValStsClr from register */
#define  IRQ_PT_SYNC_START_STS_CLR_SHIFT                    9                             /**< Shift for IRQPTSyncStartStsClr */
#define  IRQ_PT_SYNC_START_STS_CLR_MASK                     0x00000200u                   /**< Mask for IRQPTSyncStartStsClr */
#define  IRQ_PT_SYNC_START_STS_CLR_BMASK                    0x1u                          /**< Base mask for IRQPTSyncStartStsClr */
#define  IRQ_PT_SYNC_START_STS_CLR(x)                       (((x)&0x1u)<<9)               /**< Set IRQPTSyncStartStsClr in register */
#define  GET_IRQ_PT_SYNC_START_STS_CLR(reg)                 (((reg)>>9)&0x1u)             /**< Get IRQPTSyncStartStsClr from register */
#define  IRQ_PT_SYNC_STOP_STS_CLR_SHIFT                     10                            /**< Shift for IRQPTSyncStopStsClr */
#define  IRQ_PT_SYNC_STOP_STS_CLR_MASK                      0x00000400u                   /**< Mask for IRQPTSyncStopStsClr */
#define  IRQ_PT_SYNC_STOP_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQPTSyncStopStsClr */
#define  IRQ_PT_SYNC_STOP_STS_CLR(x)                        (((x)&0x1u)<<10)              /**< Set IRQPTSyncStopStsClr in register */
#define  GET_IRQ_PT_SYNC_STOP_STS_CLR(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQPTSyncStopStsClr from register */
/** @} */


/**
 * @name RegIRQSleepTimEn
 * @{
 */
// RegIRQSleepTimEn.r32
#define  REG_IRQ_SLEEP_TIM_EN_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSleepTimEn */
#define  REG_IRQ_SLEEP_TIM_EN_MASK                          0x0000001Fu                   /**< Mask for RegIRQSleepTimEn */

#define  IRQ_ST_OUT_CMP_EN_SHIFT                            0                             /**< Shift for IRQSTOutCmpEn */
#define  IRQ_ST_OUT_CMP_EN_MASK                             0x0000000Fu                   /**< Mask for IRQSTOutCmpEn */
#define  IRQ_ST_OUT_CMP_EN_BMASK                            0xFu                          /**< Base mask for IRQSTOutCmpEn */
#define  IRQ_ST_OUT_CMP_EN(x)                               (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpEn in register */
#define  GET_IRQ_ST_OUT_CMP_EN(reg)                         (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpEn from register */
#define  IRQ_ST_FULL_VAL_EN_SHIFT                           4                             /**< Shift for IRQSTFullValEn */
#define  IRQ_ST_FULL_VAL_EN_MASK                            0x00000010u                   /**< Mask for IRQSTFullValEn */
#define  IRQ_ST_FULL_VAL_EN_BMASK                           0x1u                          /**< Base mask for IRQSTFullValEn */
#define  IRQ_ST_FULL_VAL_EN(x)                              (((x)&0x1u)<<4)               /**< Set IRQSTFullValEn in register */
#define  GET_IRQ_ST_FULL_VAL_EN(reg)                        (((reg)>>4)&0x1u)             /**< Get IRQSTFullValEn from register */
/** @} */


/**
 * @name RegIRQSleepTimEnSet
 * @{
 */
// RegIRQSleepTimEnSet.r32
#define  REG_IRQ_SLEEP_TIM_EN_SET_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQSleepTimEnSet */
#define  REG_IRQ_SLEEP_TIM_EN_SET_MASK                      0x0000001Fu                   /**< Mask for RegIRQSleepTimEnSet */

#define  IRQ_ST_OUT_CMP_EN_SET_SHIFT                        0                             /**< Shift for IRQSTOutCmpEnSet */
#define  IRQ_ST_OUT_CMP_EN_SET_MASK                         0x0000000Fu                   /**< Mask for IRQSTOutCmpEnSet */
#define  IRQ_ST_OUT_CMP_EN_SET_BMASK                        0xFu                          /**< Base mask for IRQSTOutCmpEnSet */
#define  IRQ_ST_OUT_CMP_EN_SET(x)                           (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpEnSet in register */
#define  GET_IRQ_ST_OUT_CMP_EN_SET(reg)                     (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpEnSet from register */
#define  IRQ_ST_FULL_VAL_EN_SET_SHIFT                       4                             /**< Shift for IRQSTFullValEnSet */
#define  IRQ_ST_FULL_VAL_EN_SET_MASK                        0x00000010u                   /**< Mask for IRQSTFullValEnSet */
#define  IRQ_ST_FULL_VAL_EN_SET_BMASK                       0x1u                          /**< Base mask for IRQSTFullValEnSet */
#define  IRQ_ST_FULL_VAL_EN_SET(x)                          (((x)&0x1u)<<4)               /**< Set IRQSTFullValEnSet in register */
#define  GET_IRQ_ST_FULL_VAL_EN_SET(reg)                    (((reg)>>4)&0x1u)             /**< Get IRQSTFullValEnSet from register */
/** @} */


/**
 * @name RegIRQSleepTimEnClr
 * @{
 */
// RegIRQSleepTimEnClr.r32
#define  REG_IRQ_SLEEP_TIM_EN_CLR_RESET_VALUE               0x00000000u                   /**< Reset value of RegIRQSleepTimEnClr */
#define  REG_IRQ_SLEEP_TIM_EN_CLR_MASK                      0x0000001Fu                   /**< Mask for RegIRQSleepTimEnClr */

#define  IRQ_ST_OUT_CMP_EN_CLR_SHIFT                        0                             /**< Shift for IRQSTOutCmpEnClr */
#define  IRQ_ST_OUT_CMP_EN_CLR_MASK                         0x0000000Fu                   /**< Mask for IRQSTOutCmpEnClr */
#define  IRQ_ST_OUT_CMP_EN_CLR_BMASK                        0xFu                          /**< Base mask for IRQSTOutCmpEnClr */
#define  IRQ_ST_OUT_CMP_EN_CLR(x)                           (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpEnClr in register */
#define  GET_IRQ_ST_OUT_CMP_EN_CLR(reg)                     (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpEnClr from register */
#define  IRQ_ST_FULL_VAL_EN_CLR_SHIFT                       4                             /**< Shift for IRQSTFullValEnClr */
#define  IRQ_ST_FULL_VAL_EN_CLR_MASK                        0x00000010u                   /**< Mask for IRQSTFullValEnClr */
#define  IRQ_ST_FULL_VAL_EN_CLR_BMASK                       0x1u                          /**< Base mask for IRQSTFullValEnClr */
#define  IRQ_ST_FULL_VAL_EN_CLR(x)                          (((x)&0x1u)<<4)               /**< Set IRQSTFullValEnClr in register */
#define  GET_IRQ_ST_FULL_VAL_EN_CLR(reg)                    (((reg)>>4)&0x1u)             /**< Get IRQSTFullValEnClr from register */
/** @} */


/**
 * @name RegIRQSleepTimMsk
 * @{
 */
// RegIRQSleepTimMsk.r32
#define  REG_IRQ_SLEEP_TIM_MSK_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIRQSleepTimMsk */
#define  REG_IRQ_SLEEP_TIM_MSK_MASK                         0x0000001Fu                   /**< Mask for RegIRQSleepTimMsk */

#define  IRQ_ST_OUT_CMP_MSK_SHIFT                           0                             /**< Shift for IRQSTOutCmpMsk */
#define  IRQ_ST_OUT_CMP_MSK_MASK                            0x0000000Fu                   /**< Mask for IRQSTOutCmpMsk */
#define  IRQ_ST_OUT_CMP_MSK_BMASK                           0xFu                          /**< Base mask for IRQSTOutCmpMsk */
#define  IRQ_ST_OUT_CMP_MSK(x)                              (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpMsk in register */
#define  GET_IRQ_ST_OUT_CMP_MSK(reg)                        (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpMsk from register */
#define  IRQ_ST_FULL_VAL_MSK_SHIFT                          4                             /**< Shift for IRQSTFullValMsk */
#define  IRQ_ST_FULL_VAL_MSK_MASK                           0x00000010u                   /**< Mask for IRQSTFullValMsk */
#define  IRQ_ST_FULL_VAL_MSK_BMASK                          0x1u                          /**< Base mask for IRQSTFullValMsk */
#define  IRQ_ST_FULL_VAL_MSK(x)                             (((x)&0x1u)<<4)               /**< Set IRQSTFullValMsk in register */
#define  GET_IRQ_ST_FULL_VAL_MSK(reg)                       (((reg)>>4)&0x1u)             /**< Get IRQSTFullValMsk from register */
/** @} */


/**
 * @name RegIRQSleepTimMskSet
 * @{
 */
// RegIRQSleepTimMskSet.r32
#define  REG_IRQ_SLEEP_TIM_MSK_SET_RESET_VALUE              0x00000000u                   /**< Reset value of RegIRQSleepTimMskSet */
#define  REG_IRQ_SLEEP_TIM_MSK_SET_MASK                     0x0000001Fu                   /**< Mask for RegIRQSleepTimMskSet */

#define  IRQ_ST_OUT_CMP_MSK_SET_SHIFT                       0                             /**< Shift for IRQSTOutCmpMskSet */
#define  IRQ_ST_OUT_CMP_MSK_SET_MASK                        0x0000000Fu                   /**< Mask for IRQSTOutCmpMskSet */
#define  IRQ_ST_OUT_CMP_MSK_SET_BMASK                       0xFu                          /**< Base mask for IRQSTOutCmpMskSet */
#define  IRQ_ST_OUT_CMP_MSK_SET(x)                          (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpMskSet in register */
#define  GET_IRQ_ST_OUT_CMP_MSK_SET(reg)                    (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpMskSet from register */
#define  IRQ_ST_FULL_VAL_MSK_SET_SHIFT                      4                             /**< Shift for IRQSTFullValMskSet */
#define  IRQ_ST_FULL_VAL_MSK_SET_MASK                       0x00000010u                   /**< Mask for IRQSTFullValMskSet */
#define  IRQ_ST_FULL_VAL_MSK_SET_BMASK                      0x1u                          /**< Base mask for IRQSTFullValMskSet */
#define  IRQ_ST_FULL_VAL_MSK_SET(x)                         (((x)&0x1u)<<4)               /**< Set IRQSTFullValMskSet in register */
#define  GET_IRQ_ST_FULL_VAL_MSK_SET(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQSTFullValMskSet from register */
/** @} */


/**
 * @name RegIRQSleepTimMskClr
 * @{
 */
// RegIRQSleepTimMskClr.r32
#define  REG_IRQ_SLEEP_TIM_MSK_CLR_RESET_VALUE              0x00000000u                   /**< Reset value of RegIRQSleepTimMskClr */
#define  REG_IRQ_SLEEP_TIM_MSK_CLR_MASK                     0x0000001Fu                   /**< Mask for RegIRQSleepTimMskClr */

#define  IRQ_ST_OUT_CMP_MSK_CLR_SHIFT                       0                             /**< Shift for IRQSTOutCmpMskClr */
#define  IRQ_ST_OUT_CMP_MSK_CLR_MASK                        0x0000000Fu                   /**< Mask for IRQSTOutCmpMskClr */
#define  IRQ_ST_OUT_CMP_MSK_CLR_BMASK                       0xFu                          /**< Base mask for IRQSTOutCmpMskClr */
#define  IRQ_ST_OUT_CMP_MSK_CLR(x)                          (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpMskClr in register */
#define  GET_IRQ_ST_OUT_CMP_MSK_CLR(reg)                    (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpMskClr from register */
#define  IRQ_ST_FULL_VAL_MSK_CLR_SHIFT                      4                             /**< Shift for IRQSTFullValMskClr */
#define  IRQ_ST_FULL_VAL_MSK_CLR_MASK                       0x00000010u                   /**< Mask for IRQSTFullValMskClr */
#define  IRQ_ST_FULL_VAL_MSK_CLR_BMASK                      0x1u                          /**< Base mask for IRQSTFullValMskClr */
#define  IRQ_ST_FULL_VAL_MSK_CLR(x)                         (((x)&0x1u)<<4)               /**< Set IRQSTFullValMskClr in register */
#define  GET_IRQ_ST_FULL_VAL_MSK_CLR(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQSTFullValMskClr from register */
/** @} */


/**
 * @name RegIRQSleepTimSts
 * @{
 */
// RegIRQSleepTimSts.r32
#define  REG_IRQ_SLEEP_TIM_STS_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIRQSleepTimSts */
#define  REG_IRQ_SLEEP_TIM_STS_MASK                         0x0000001Fu                   /**< Mask for RegIRQSleepTimSts */

#define  IRQ_ST_OUT_CMP_STS_SHIFT                           0                             /**< Shift for IRQSTOutCmpSts */
#define  IRQ_ST_OUT_CMP_STS_MASK                            0x0000000Fu                   /**< Mask for IRQSTOutCmpSts */
#define  IRQ_ST_OUT_CMP_STS_BMASK                           0xFu                          /**< Base mask for IRQSTOutCmpSts */
#define  IRQ_ST_OUT_CMP_STS(x)                              (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpSts in register */
#define  GET_IRQ_ST_OUT_CMP_STS(reg)                        (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpSts from register */
#define  IRQ_ST_FULL_VAL_STS_SHIFT                          4                             /**< Shift for IRQSTFullValSts */
#define  IRQ_ST_FULL_VAL_STS_MASK                           0x00000010u                   /**< Mask for IRQSTFullValSts */
#define  IRQ_ST_FULL_VAL_STS_BMASK                          0x1u                          /**< Base mask for IRQSTFullValSts */
#define  IRQ_ST_FULL_VAL_STS(x)                             (((x)&0x1u)<<4)               /**< Set IRQSTFullValSts in register */
#define  GET_IRQ_ST_FULL_VAL_STS(reg)                       (((reg)>>4)&0x1u)             /**< Get IRQSTFullValSts from register */
/** @} */


/**
 * @name RegIRQSleepTimStsSet
 * @{
 */
// RegIRQSleepTimStsSet.r32
#define  REG_IRQ_SLEEP_TIM_STS_SET_RESET_VALUE              0x00000000u                   /**< Reset value of RegIRQSleepTimStsSet */
#define  REG_IRQ_SLEEP_TIM_STS_SET_MASK                     0x0000001Fu                   /**< Mask for RegIRQSleepTimStsSet */

#define  IRQ_ST_OUT_CMP_STS_SET_SHIFT                       0                             /**< Shift for IRQSTOutCmpStsSet */
#define  IRQ_ST_OUT_CMP_STS_SET_MASK                        0x0000000Fu                   /**< Mask for IRQSTOutCmpStsSet */
#define  IRQ_ST_OUT_CMP_STS_SET_BMASK                       0xFu                          /**< Base mask for IRQSTOutCmpStsSet */
#define  IRQ_ST_OUT_CMP_STS_SET(x)                          (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpStsSet in register */
#define  GET_IRQ_ST_OUT_CMP_STS_SET(reg)                    (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpStsSet from register */
#define  IRQ_ST_FULL_VAL_STS_SET_SHIFT                      4                             /**< Shift for IRQSTFullValStsSet */
#define  IRQ_ST_FULL_VAL_STS_SET_MASK                       0x00000010u                   /**< Mask for IRQSTFullValStsSet */
#define  IRQ_ST_FULL_VAL_STS_SET_BMASK                      0x1u                          /**< Base mask for IRQSTFullValStsSet */
#define  IRQ_ST_FULL_VAL_STS_SET(x)                         (((x)&0x1u)<<4)               /**< Set IRQSTFullValStsSet in register */
#define  GET_IRQ_ST_FULL_VAL_STS_SET(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQSTFullValStsSet from register */
/** @} */


/**
 * @name RegIRQSleepTimStsClr
 * @{
 */
// RegIRQSleepTimStsClr.r32
#define  REG_IRQ_SLEEP_TIM_STS_CLR_RESET_VALUE              0x00000000u                   /**< Reset value of RegIRQSleepTimStsClr */
#define  REG_IRQ_SLEEP_TIM_STS_CLR_MASK                     0x0000001Fu                   /**< Mask for RegIRQSleepTimStsClr */

#define  IRQ_ST_OUT_CMP_STS_CLR_SHIFT                       0                             /**< Shift for IRQSTOutCmpStsClr */
#define  IRQ_ST_OUT_CMP_STS_CLR_MASK                        0x0000000Fu                   /**< Mask for IRQSTOutCmpStsClr */
#define  IRQ_ST_OUT_CMP_STS_CLR_BMASK                       0xFu                          /**< Base mask for IRQSTOutCmpStsClr */
#define  IRQ_ST_OUT_CMP_STS_CLR(x)                          (((x)&0xFu)<<0)               /**< Set IRQSTOutCmpStsClr in register */
#define  GET_IRQ_ST_OUT_CMP_STS_CLR(reg)                    (((reg)>>0)&0xFu)             /**< Get IRQSTOutCmpStsClr from register */
#define  IRQ_ST_FULL_VAL_STS_CLR_SHIFT                      4                             /**< Shift for IRQSTFullValStsClr */
#define  IRQ_ST_FULL_VAL_STS_CLR_MASK                       0x00000010u                   /**< Mask for IRQSTFullValStsClr */
#define  IRQ_ST_FULL_VAL_STS_CLR_BMASK                      0x1u                          /**< Base mask for IRQSTFullValStsClr */
#define  IRQ_ST_FULL_VAL_STS_CLR(x)                         (((x)&0x1u)<<4)               /**< Set IRQSTFullValStsClr in register */
#define  GET_IRQ_ST_FULL_VAL_STS_CLR(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQSTFullValStsClr from register */
/** @} */


/**
 * @name RegIRQRFEn
 * @{
 */
// RegIRQRFEn.r32
#define  REG_IRQ_RF_EN_RESET_VALUE                          0x00000000u                   /**< Reset value of RegIRQRFEn */
#define  REG_IRQ_RF_EN_MASK                                 0x037F013Fu                   /**< Mask for RegIRQRFEn */

#define  IRQ_RF_TX_EN_SHIFT                                 0                             /**< Shift for IRQRFTxEn */
#define  IRQ_RF_TX_EN_MASK                                  0x00000001u                   /**< Mask for IRQRFTxEn */
#define  IRQ_RF_TX_EN_BMASK                                 0x1u                          /**< Base mask for IRQRFTxEn */
#define  IRQ_RF_TX_EN(x)                                    (((x)&0x1u)<<0)               /**< Set IRQRFTxEn in register */
#define  GET_IRQ_RF_TX_EN(reg)                              (((reg)>>0)&0x1u)             /**< Get IRQRFTxEn from register */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_SHIFT                      1                             /**< Shift for IRQRFTxFIFOEmptyEn */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_MASK                       0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyEn */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_BMASK                      0x1u                          /**< Base mask for IRQRFTxFIFOEmptyEn */
#define  IRQ_RF_TX_FIFO_EMPTY_EN(x)                         (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyEn in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_EN(reg)                   (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyEn from register */
#define  IRQ_RF_TX_FIFO_FULL_EN_SHIFT                       2                             /**< Shift for IRQRFTxFIFOFullEn */
#define  IRQ_RF_TX_FIFO_FULL_EN_MASK                        0x00000004u                   /**< Mask for IRQRFTxFIFOFullEn */
#define  IRQ_RF_TX_FIFO_FULL_EN_BMASK                       0x1u                          /**< Base mask for IRQRFTxFIFOFullEn */
#define  IRQ_RF_TX_FIFO_FULL_EN(x)                          (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullEn in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_EN(reg)                    (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullEn from register */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_SHIFT                      3                             /**< Shift for IRQRFTxFIFOLimitEn */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_MASK                       0x00000008u                   /**< Mask for IRQRFTxFIFOLimitEn */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_BMASK                      0x1u                          /**< Base mask for IRQRFTxFIFOLimitEn */
#define  IRQ_RF_TX_FIFO_LIMIT_EN(x)                         (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitEn in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_EN(reg)                   (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitEn from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_SHIFT                  4                             /**< Shift for IRQRFTxFIFOUnderflowEn */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_MASK                   0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowEn */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowEn */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN(x)                     (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowEn in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_EN(reg)               (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowEn from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_SHIFT                   5                             /**< Shift for IRQRFTxFIFOOverflowEn */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_MASK                    0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowEn */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_BMASK                   0x1u                          /**< Base mask for IRQRFTxFIFOOverflowEn */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN(x)                      (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowEn in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_EN(reg)                (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowEn from register */
#define  IRQ_RF_TX_DONE_EN_SHIFT                            8                             /**< Shift for IRQRFTxDoneEn */
#define  IRQ_RF_TX_DONE_EN_MASK                             0x00000100u                   /**< Mask for IRQRFTxDoneEn */
#define  IRQ_RF_TX_DONE_EN_BMASK                            0x1u                          /**< Base mask for IRQRFTxDoneEn */
#define  IRQ_RF_TX_DONE_EN(x)                               (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneEn in register */
#define  GET_IRQ_RF_TX_DONE_EN(reg)                         (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneEn from register */
#define  IRQ_RF_RX_EN_SHIFT                                 16                            /**< Shift for IRQRFRxEn */
#define  IRQ_RF_RX_EN_MASK                                  0x00010000u                   /**< Mask for IRQRFRxEn */
#define  IRQ_RF_RX_EN_BMASK                                 0x1u                          /**< Base mask for IRQRFRxEn */
#define  IRQ_RF_RX_EN(x)                                    (((x)&0x1u)<<16)              /**< Set IRQRFRxEn in register */
#define  GET_IRQ_RF_RX_EN(reg)                              (((reg)>>16)&0x1u)            /**< Get IRQRFRxEn from register */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_SHIFT                      17                            /**< Shift for IRQRFRxFIFOEmptyEn */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_MASK                       0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyEn */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_BMASK                      0x1u                          /**< Base mask for IRQRFRxFIFOEmptyEn */
#define  IRQ_RF_RX_FIFO_EMPTY_EN(x)                         (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyEn in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_EN(reg)                   (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyEn from register */
#define  IRQ_RF_RX_FIFO_FULL_EN_SHIFT                       18                            /**< Shift for IRQRFRxFIFOFullEn */
#define  IRQ_RF_RX_FIFO_FULL_EN_MASK                        0x00040000u                   /**< Mask for IRQRFRxFIFOFullEn */
#define  IRQ_RF_RX_FIFO_FULL_EN_BMASK                       0x1u                          /**< Base mask for IRQRFRxFIFOFullEn */
#define  IRQ_RF_RX_FIFO_FULL_EN(x)                          (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullEn in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_EN(reg)                    (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullEn from register */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_SHIFT                      19                            /**< Shift for IRQRFRxFIFOLimitEn */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_MASK                       0x00080000u                   /**< Mask for IRQRFRxFIFOLimitEn */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_BMASK                      0x1u                          /**< Base mask for IRQRFRxFIFOLimitEn */
#define  IRQ_RF_RX_FIFO_LIMIT_EN(x)                         (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitEn in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_EN(reg)                   (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitEn from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_SHIFT                  20                            /**< Shift for IRQRFRxFIFOUnderflowEn */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_MASK                   0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowEn */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowEn */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN(x)                     (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowEn in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_EN(reg)               (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowEn from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_SHIFT                   21                            /**< Shift for IRQRFRxFIFOOverflowEn */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_MASK                    0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowEn */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_BMASK                   0x1u                          /**< Base mask for IRQRFRxFIFOOverflowEn */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN(x)                      (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowEn in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_EN(reg)                (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowEn from register */
#define  IRQ_RF_RX_SYNC_EN_SHIFT                            22                            /**< Shift for IRQRFRxSyncEn */
#define  IRQ_RF_RX_SYNC_EN_MASK                             0x00400000u                   /**< Mask for IRQRFRxSyncEn */
#define  IRQ_RF_RX_SYNC_EN_BMASK                            0x1u                          /**< Base mask for IRQRFRxSyncEn */
#define  IRQ_RF_RX_SYNC_EN(x)                               (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncEn in register */
#define  GET_IRQ_RF_RX_SYNC_EN(reg)                         (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncEn from register */
#define  IRQ_RF_RX_DONE_EN_SHIFT                            24                            /**< Shift for IRQRFRxDoneEn */
#define  IRQ_RF_RX_DONE_EN_MASK                             0x01000000u                   /**< Mask for IRQRFRxDoneEn */
#define  IRQ_RF_RX_DONE_EN_BMASK                            0x1u                          /**< Base mask for IRQRFRxDoneEn */
#define  IRQ_RF_RX_DONE_EN(x)                               (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneEn in register */
#define  GET_IRQ_RF_RX_DONE_EN(reg)                         (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneEn from register */
#define  IRQ_RF_RX_TIMEOUT_EN_SHIFT                         25                            /**< Shift for IRQRFRxTimeoutEn */
#define  IRQ_RF_RX_TIMEOUT_EN_MASK                          0x02000000u                   /**< Mask for IRQRFRxTimeoutEn */
#define  IRQ_RF_RX_TIMEOUT_EN_BMASK                         0x1u                          /**< Base mask for IRQRFRxTimeoutEn */
#define  IRQ_RF_RX_TIMEOUT_EN(x)                            (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutEn in register */
#define  GET_IRQ_RF_RX_TIMEOUT_EN(reg)                      (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutEn from register */
/** @} */


/**
 * @name RegIRQRFEnSet
 * @{
 */
// RegIRQRFEnSet.r32
#define  REG_IRQ_RF_EN_SET_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRFEnSet */
#define  REG_IRQ_RF_EN_SET_MASK                             0x037F013Fu                   /**< Mask for RegIRQRFEnSet */

#define  IRQ_RF_TX_EN_SET_SHIFT                             0                             /**< Shift for IRQRFTxEnSet */
#define  IRQ_RF_TX_EN_SET_MASK                              0x00000001u                   /**< Mask for IRQRFTxEnSet */
#define  IRQ_RF_TX_EN_SET_BMASK                             0x1u                          /**< Base mask for IRQRFTxEnSet */
#define  IRQ_RF_TX_EN_SET(x)                                (((x)&0x1u)<<0)               /**< Set IRQRFTxEnSet in register */
#define  GET_IRQ_RF_TX_EN_SET(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQRFTxEnSet from register */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_SET_SHIFT                  1                             /**< Shift for IRQRFTxFIFOEmptyEnSet */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_SET_MASK                   0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyEnSet */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_SET_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOEmptyEnSet */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_SET(x)                     (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyEnSet in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_EN_SET(reg)               (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyEnSet from register */
#define  IRQ_RF_TX_FIFO_FULL_EN_SET_SHIFT                   2                             /**< Shift for IRQRFTxFIFOFullEnSet */
#define  IRQ_RF_TX_FIFO_FULL_EN_SET_MASK                    0x00000004u                   /**< Mask for IRQRFTxFIFOFullEnSet */
#define  IRQ_RF_TX_FIFO_FULL_EN_SET_BMASK                   0x1u                          /**< Base mask for IRQRFTxFIFOFullEnSet */
#define  IRQ_RF_TX_FIFO_FULL_EN_SET(x)                      (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullEnSet in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_EN_SET(reg)                (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullEnSet from register */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_SET_SHIFT                  3                             /**< Shift for IRQRFTxFIFOLimitEnSet */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_SET_MASK                   0x00000008u                   /**< Mask for IRQRFTxFIFOLimitEnSet */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_SET_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOLimitEnSet */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_SET(x)                     (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitEnSet in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_EN_SET(reg)               (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitEnSet from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_SET_SHIFT              4                             /**< Shift for IRQRFTxFIFOUnderflowEnSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_SET_MASK               0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowEnSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_SET_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowEnSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_SET(x)                 (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowEnSet in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_EN_SET(reg)           (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowEnSet from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_SET_SHIFT               5                             /**< Shift for IRQRFTxFIFOOverflowEnSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_SET_MASK                0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowEnSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_SET_BMASK               0x1u                          /**< Base mask for IRQRFTxFIFOOverflowEnSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_SET(x)                  (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowEnSet in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_EN_SET(reg)            (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowEnSet from register */
#define  IRQ_RF_TX_DONE_EN_SET_SHIFT                        8                             /**< Shift for IRQRFTxDoneEnSet */
#define  IRQ_RF_TX_DONE_EN_SET_MASK                         0x00000100u                   /**< Mask for IRQRFTxDoneEnSet */
#define  IRQ_RF_TX_DONE_EN_SET_BMASK                        0x1u                          /**< Base mask for IRQRFTxDoneEnSet */
#define  IRQ_RF_TX_DONE_EN_SET(x)                           (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneEnSet in register */
#define  GET_IRQ_RF_TX_DONE_EN_SET(reg)                     (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneEnSet from register */
#define  IRQ_RF_RX_EN_SET_SHIFT                             16                            /**< Shift for IRQRFRxEnSet */
#define  IRQ_RF_RX_EN_SET_MASK                              0x00010000u                   /**< Mask for IRQRFRxEnSet */
#define  IRQ_RF_RX_EN_SET_BMASK                             0x1u                          /**< Base mask for IRQRFRxEnSet */
#define  IRQ_RF_RX_EN_SET(x)                                (((x)&0x1u)<<16)              /**< Set IRQRFRxEnSet in register */
#define  GET_IRQ_RF_RX_EN_SET(reg)                          (((reg)>>16)&0x1u)            /**< Get IRQRFRxEnSet from register */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_SET_SHIFT                  17                            /**< Shift for IRQRFRxFIFOEmptyEnSet */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_SET_MASK                   0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyEnSet */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_SET_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOEmptyEnSet */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_SET(x)                     (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyEnSet in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_EN_SET(reg)               (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyEnSet from register */
#define  IRQ_RF_RX_FIFO_FULL_EN_SET_SHIFT                   18                            /**< Shift for IRQRFRxFIFOFullEnSet */
#define  IRQ_RF_RX_FIFO_FULL_EN_SET_MASK                    0x00040000u                   /**< Mask for IRQRFRxFIFOFullEnSet */
#define  IRQ_RF_RX_FIFO_FULL_EN_SET_BMASK                   0x1u                          /**< Base mask for IRQRFRxFIFOFullEnSet */
#define  IRQ_RF_RX_FIFO_FULL_EN_SET(x)                      (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullEnSet in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_EN_SET(reg)                (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullEnSet from register */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_SET_SHIFT                  19                            /**< Shift for IRQRFRxFIFOLimitEnSet */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_SET_MASK                   0x00080000u                   /**< Mask for IRQRFRxFIFOLimitEnSet */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_SET_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOLimitEnSet */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_SET(x)                     (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitEnSet in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_EN_SET(reg)               (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitEnSet from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_SET_SHIFT              20                            /**< Shift for IRQRFRxFIFOUnderflowEnSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_SET_MASK               0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowEnSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_SET_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowEnSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_SET(x)                 (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowEnSet in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_EN_SET(reg)           (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowEnSet from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_SET_SHIFT               21                            /**< Shift for IRQRFRxFIFOOverflowEnSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_SET_MASK                0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowEnSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_SET_BMASK               0x1u                          /**< Base mask for IRQRFRxFIFOOverflowEnSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_SET(x)                  (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowEnSet in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_EN_SET(reg)            (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowEnSet from register */
#define  IRQ_RF_RX_SYNC_EN_SET_SHIFT                        22                            /**< Shift for IRQRFRxSyncEnSet */
#define  IRQ_RF_RX_SYNC_EN_SET_MASK                         0x00400000u                   /**< Mask for IRQRFRxSyncEnSet */
#define  IRQ_RF_RX_SYNC_EN_SET_BMASK                        0x1u                          /**< Base mask for IRQRFRxSyncEnSet */
#define  IRQ_RF_RX_SYNC_EN_SET(x)                           (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncEnSet in register */
#define  GET_IRQ_RF_RX_SYNC_EN_SET(reg)                     (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncEnSet from register */
#define  IRQ_RF_RX_DONE_EN_SET_SHIFT                        24                            /**< Shift for IRQRFRxDoneEnSet */
#define  IRQ_RF_RX_DONE_EN_SET_MASK                         0x01000000u                   /**< Mask for IRQRFRxDoneEnSet */
#define  IRQ_RF_RX_DONE_EN_SET_BMASK                        0x1u                          /**< Base mask for IRQRFRxDoneEnSet */
#define  IRQ_RF_RX_DONE_EN_SET(x)                           (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneEnSet in register */
#define  GET_IRQ_RF_RX_DONE_EN_SET(reg)                     (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneEnSet from register */
#define  IRQ_RF_RX_TIMEOUT_EN_SET_SHIFT                     25                            /**< Shift for IRQRFRxTimeoutEnSet */
#define  IRQ_RF_RX_TIMEOUT_EN_SET_MASK                      0x02000000u                   /**< Mask for IRQRFRxTimeoutEnSet */
#define  IRQ_RF_RX_TIMEOUT_EN_SET_BMASK                     0x1u                          /**< Base mask for IRQRFRxTimeoutEnSet */
#define  IRQ_RF_RX_TIMEOUT_EN_SET(x)                        (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutEnSet in register */
#define  GET_IRQ_RF_RX_TIMEOUT_EN_SET(reg)                  (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutEnSet from register */
/** @} */


/**
 * @name RegIRQRFEnClr
 * @{
 */
// RegIRQRFEnClr.r32
#define  REG_IRQ_RF_EN_CLR_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRFEnClr */
#define  REG_IRQ_RF_EN_CLR_MASK                             0x037F013Fu                   /**< Mask for RegIRQRFEnClr */

#define  IRQ_RF_TX_EN_CLR_SHIFT                             0                             /**< Shift for IRQRFTxEnClr */
#define  IRQ_RF_TX_EN_CLR_MASK                              0x00000001u                   /**< Mask for IRQRFTxEnClr */
#define  IRQ_RF_TX_EN_CLR_BMASK                             0x1u                          /**< Base mask for IRQRFTxEnClr */
#define  IRQ_RF_TX_EN_CLR(x)                                (((x)&0x1u)<<0)               /**< Set IRQRFTxEnClr in register */
#define  GET_IRQ_RF_TX_EN_CLR(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQRFTxEnClr from register */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_CLR_SHIFT                  1                             /**< Shift for IRQRFTxFIFOEmptyEnClr */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_CLR_MASK                   0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyEnClr */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOEmptyEnClr */
#define  IRQ_RF_TX_FIFO_EMPTY_EN_CLR(x)                     (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyEnClr in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_EN_CLR(reg)               (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyEnClr from register */
#define  IRQ_RF_TX_FIFO_FULL_EN_CLR_SHIFT                   2                             /**< Shift for IRQRFTxFIFOFullEnClr */
#define  IRQ_RF_TX_FIFO_FULL_EN_CLR_MASK                    0x00000004u                   /**< Mask for IRQRFTxFIFOFullEnClr */
#define  IRQ_RF_TX_FIFO_FULL_EN_CLR_BMASK                   0x1u                          /**< Base mask for IRQRFTxFIFOFullEnClr */
#define  IRQ_RF_TX_FIFO_FULL_EN_CLR(x)                      (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullEnClr in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_EN_CLR(reg)                (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullEnClr from register */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_CLR_SHIFT                  3                             /**< Shift for IRQRFTxFIFOLimitEnClr */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_CLR_MASK                   0x00000008u                   /**< Mask for IRQRFTxFIFOLimitEnClr */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOLimitEnClr */
#define  IRQ_RF_TX_FIFO_LIMIT_EN_CLR(x)                     (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitEnClr in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_EN_CLR(reg)               (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitEnClr from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_CLR_SHIFT              4                             /**< Shift for IRQRFTxFIFOUnderflowEnClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_CLR_MASK               0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowEnClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_CLR_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowEnClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_EN_CLR(x)                 (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowEnClr in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_EN_CLR(reg)           (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowEnClr from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_CLR_SHIFT               5                             /**< Shift for IRQRFTxFIFOOverflowEnClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_CLR_MASK                0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowEnClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_CLR_BMASK               0x1u                          /**< Base mask for IRQRFTxFIFOOverflowEnClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_EN_CLR(x)                  (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowEnClr in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_EN_CLR(reg)            (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowEnClr from register */
#define  IRQ_RF_TX_DONE_EN_CLR_SHIFT                        8                             /**< Shift for IRQRFTxDoneEnClr */
#define  IRQ_RF_TX_DONE_EN_CLR_MASK                         0x00000100u                   /**< Mask for IRQRFTxDoneEnClr */
#define  IRQ_RF_TX_DONE_EN_CLR_BMASK                        0x1u                          /**< Base mask for IRQRFTxDoneEnClr */
#define  IRQ_RF_TX_DONE_EN_CLR(x)                           (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneEnClr in register */
#define  GET_IRQ_RF_TX_DONE_EN_CLR(reg)                     (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneEnClr from register */
#define  IRQ_RF_RX_EN_CLR_SHIFT                             16                            /**< Shift for IRQRFRxEnClr */
#define  IRQ_RF_RX_EN_CLR_MASK                              0x00010000u                   /**< Mask for IRQRFRxEnClr */
#define  IRQ_RF_RX_EN_CLR_BMASK                             0x1u                          /**< Base mask for IRQRFRxEnClr */
#define  IRQ_RF_RX_EN_CLR(x)                                (((x)&0x1u)<<16)              /**< Set IRQRFRxEnClr in register */
#define  GET_IRQ_RF_RX_EN_CLR(reg)                          (((reg)>>16)&0x1u)            /**< Get IRQRFRxEnClr from register */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_CLR_SHIFT                  17                            /**< Shift for IRQRFRxFIFOEmptyEnClr */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_CLR_MASK                   0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyEnClr */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOEmptyEnClr */
#define  IRQ_RF_RX_FIFO_EMPTY_EN_CLR(x)                     (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyEnClr in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_EN_CLR(reg)               (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyEnClr from register */
#define  IRQ_RF_RX_FIFO_FULL_EN_CLR_SHIFT                   18                            /**< Shift for IRQRFRxFIFOFullEnClr */
#define  IRQ_RF_RX_FIFO_FULL_EN_CLR_MASK                    0x00040000u                   /**< Mask for IRQRFRxFIFOFullEnClr */
#define  IRQ_RF_RX_FIFO_FULL_EN_CLR_BMASK                   0x1u                          /**< Base mask for IRQRFRxFIFOFullEnClr */
#define  IRQ_RF_RX_FIFO_FULL_EN_CLR(x)                      (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullEnClr in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_EN_CLR(reg)                (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullEnClr from register */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_CLR_SHIFT                  19                            /**< Shift for IRQRFRxFIFOLimitEnClr */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_CLR_MASK                   0x00080000u                   /**< Mask for IRQRFRxFIFOLimitEnClr */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOLimitEnClr */
#define  IRQ_RF_RX_FIFO_LIMIT_EN_CLR(x)                     (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitEnClr in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_EN_CLR(reg)               (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitEnClr from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_CLR_SHIFT              20                            /**< Shift for IRQRFRxFIFOUnderflowEnClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_CLR_MASK               0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowEnClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_CLR_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowEnClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_EN_CLR(x)                 (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowEnClr in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_EN_CLR(reg)           (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowEnClr from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_CLR_SHIFT               21                            /**< Shift for IRQRFRxFIFOOverflowEnClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_CLR_MASK                0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowEnClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_CLR_BMASK               0x1u                          /**< Base mask for IRQRFRxFIFOOverflowEnClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_EN_CLR(x)                  (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowEnClr in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_EN_CLR(reg)            (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowEnClr from register */
#define  IRQ_RF_RX_SYNC_EN_CLR_SHIFT                        22                            /**< Shift for IRQRFRxSyncEnClr */
#define  IRQ_RF_RX_SYNC_EN_CLR_MASK                         0x00400000u                   /**< Mask for IRQRFRxSyncEnClr */
#define  IRQ_RF_RX_SYNC_EN_CLR_BMASK                        0x1u                          /**< Base mask for IRQRFRxSyncEnClr */
#define  IRQ_RF_RX_SYNC_EN_CLR(x)                           (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncEnClr in register */
#define  GET_IRQ_RF_RX_SYNC_EN_CLR(reg)                     (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncEnClr from register */
#define  IRQ_RF_RX_DONE_EN_CLR_SHIFT                        24                            /**< Shift for IRQRFRxDoneEnClr */
#define  IRQ_RF_RX_DONE_EN_CLR_MASK                         0x01000000u                   /**< Mask for IRQRFRxDoneEnClr */
#define  IRQ_RF_RX_DONE_EN_CLR_BMASK                        0x1u                          /**< Base mask for IRQRFRxDoneEnClr */
#define  IRQ_RF_RX_DONE_EN_CLR(x)                           (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneEnClr in register */
#define  GET_IRQ_RF_RX_DONE_EN_CLR(reg)                     (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneEnClr from register */
#define  IRQ_RF_RX_TIMEOUT_EN_CLR_SHIFT                     25                            /**< Shift for IRQRFRxTimeoutEnClr */
#define  IRQ_RF_RX_TIMEOUT_EN_CLR_MASK                      0x02000000u                   /**< Mask for IRQRFRxTimeoutEnClr */
#define  IRQ_RF_RX_TIMEOUT_EN_CLR_BMASK                     0x1u                          /**< Base mask for IRQRFRxTimeoutEnClr */
#define  IRQ_RF_RX_TIMEOUT_EN_CLR(x)                        (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutEnClr in register */
#define  GET_IRQ_RF_RX_TIMEOUT_EN_CLR(reg)                  (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutEnClr from register */
/** @} */


/**
 * @name RegIRQRFMsk
 * @{
 */
// RegIRQRFMsk.r32
#define  REG_IRQ_RF_MSK_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIRQRFMsk */
#define  REG_IRQ_RF_MSK_MASK                                0x037F013Fu                   /**< Mask for RegIRQRFMsk */

#define  IRQ_RF_TX_MSK_SHIFT                                0                             /**< Shift for IRQRFTxMsk */
#define  IRQ_RF_TX_MSK_MASK                                 0x00000001u                   /**< Mask for IRQRFTxMsk */
#define  IRQ_RF_TX_MSK_BMASK                                0x1u                          /**< Base mask for IRQRFTxMsk */
#define  IRQ_RF_TX_MSK(x)                                   (((x)&0x1u)<<0)               /**< Set IRQRFTxMsk in register */
#define  GET_IRQ_RF_TX_MSK(reg)                             (((reg)>>0)&0x1u)             /**< Get IRQRFTxMsk from register */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_SHIFT                     1                             /**< Shift for IRQRFTxFIFOEmptyMsk */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_MASK                      0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyMsk */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_BMASK                     0x1u                          /**< Base mask for IRQRFTxFIFOEmptyMsk */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK(x)                        (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyMsk in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_MSK(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyMsk from register */
#define  IRQ_RF_TX_FIFO_FULL_MSK_SHIFT                      2                             /**< Shift for IRQRFTxFIFOFullMsk */
#define  IRQ_RF_TX_FIFO_FULL_MSK_MASK                       0x00000004u                   /**< Mask for IRQRFTxFIFOFullMsk */
#define  IRQ_RF_TX_FIFO_FULL_MSK_BMASK                      0x1u                          /**< Base mask for IRQRFTxFIFOFullMsk */
#define  IRQ_RF_TX_FIFO_FULL_MSK(x)                         (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullMsk in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_MSK(reg)                   (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullMsk from register */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_SHIFT                     3                             /**< Shift for IRQRFTxFIFOLimitMsk */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_MASK                      0x00000008u                   /**< Mask for IRQRFTxFIFOLimitMsk */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_BMASK                     0x1u                          /**< Base mask for IRQRFTxFIFOLimitMsk */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK(x)                        (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitMsk in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_MSK(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitMsk from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SHIFT                 4                             /**< Shift for IRQRFTxFIFOUnderflowMsk */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_MASK                  0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowMsk */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowMsk */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK(x)                    (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowMsk in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_MSK(reg)              (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowMsk from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_SHIFT                  5                             /**< Shift for IRQRFTxFIFOOverflowMsk */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_MASK                   0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowMsk */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOOverflowMsk */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK(x)                     (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowMsk in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_MSK(reg)               (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowMsk from register */
#define  IRQ_RF_TX_DONE_MSK_SHIFT                           8                             /**< Shift for IRQRFTxDoneMsk */
#define  IRQ_RF_TX_DONE_MSK_MASK                            0x00000100u                   /**< Mask for IRQRFTxDoneMsk */
#define  IRQ_RF_TX_DONE_MSK_BMASK                           0x1u                          /**< Base mask for IRQRFTxDoneMsk */
#define  IRQ_RF_TX_DONE_MSK(x)                              (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneMsk in register */
#define  GET_IRQ_RF_TX_DONE_MSK(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneMsk from register */
#define  IRQ_RF_RX_MSK_SHIFT                                16                            /**< Shift for IRQRFRxMsk */
#define  IRQ_RF_RX_MSK_MASK                                 0x00010000u                   /**< Mask for IRQRFRxMsk */
#define  IRQ_RF_RX_MSK_BMASK                                0x1u                          /**< Base mask for IRQRFRxMsk */
#define  IRQ_RF_RX_MSK(x)                                   (((x)&0x1u)<<16)              /**< Set IRQRFRxMsk in register */
#define  GET_IRQ_RF_RX_MSK(reg)                             (((reg)>>16)&0x1u)            /**< Get IRQRFRxMsk from register */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_SHIFT                     17                            /**< Shift for IRQRFRxFIFOEmptyMsk */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_MASK                      0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyMsk */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_BMASK                     0x1u                          /**< Base mask for IRQRFRxFIFOEmptyMsk */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK(x)                        (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyMsk in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_MSK(reg)                  (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyMsk from register */
#define  IRQ_RF_RX_FIFO_FULL_MSK_SHIFT                      18                            /**< Shift for IRQRFRxFIFOFullMsk */
#define  IRQ_RF_RX_FIFO_FULL_MSK_MASK                       0x00040000u                   /**< Mask for IRQRFRxFIFOFullMsk */
#define  IRQ_RF_RX_FIFO_FULL_MSK_BMASK                      0x1u                          /**< Base mask for IRQRFRxFIFOFullMsk */
#define  IRQ_RF_RX_FIFO_FULL_MSK(x)                         (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullMsk in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_MSK(reg)                   (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullMsk from register */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_SHIFT                     19                            /**< Shift for IRQRFRxFIFOLimitMsk */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_MASK                      0x00080000u                   /**< Mask for IRQRFRxFIFOLimitMsk */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_BMASK                     0x1u                          /**< Base mask for IRQRFRxFIFOLimitMsk */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK(x)                        (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitMsk in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_MSK(reg)                  (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitMsk from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SHIFT                 20                            /**< Shift for IRQRFRxFIFOUnderflowMsk */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_MASK                  0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowMsk */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowMsk */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK(x)                    (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowMsk in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_MSK(reg)              (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowMsk from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_SHIFT                  21                            /**< Shift for IRQRFRxFIFOOverflowMsk */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_MASK                   0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowMsk */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOOverflowMsk */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK(x)                     (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowMsk in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_MSK(reg)               (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowMsk from register */
#define  IRQ_RF_RX_SYNC_MSK_SHIFT                           22                            /**< Shift for IRQRFRxSyncMsk */
#define  IRQ_RF_RX_SYNC_MSK_MASK                            0x00400000u                   /**< Mask for IRQRFRxSyncMsk */
#define  IRQ_RF_RX_SYNC_MSK_BMASK                           0x1u                          /**< Base mask for IRQRFRxSyncMsk */
#define  IRQ_RF_RX_SYNC_MSK(x)                              (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncMsk in register */
#define  GET_IRQ_RF_RX_SYNC_MSK(reg)                        (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncMsk from register */
#define  IRQ_RF_RX_DONE_MSK_SHIFT                           24                            /**< Shift for IRQRFRxDoneMsk */
#define  IRQ_RF_RX_DONE_MSK_MASK                            0x01000000u                   /**< Mask for IRQRFRxDoneMsk */
#define  IRQ_RF_RX_DONE_MSK_BMASK                           0x1u                          /**< Base mask for IRQRFRxDoneMsk */
#define  IRQ_RF_RX_DONE_MSK(x)                              (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneMsk in register */
#define  GET_IRQ_RF_RX_DONE_MSK(reg)                        (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneMsk from register */
#define  IRQ_RF_RX_TIMEOUT_MSK_SHIFT                        25                            /**< Shift for IRQRFRxTimeoutMsk */
#define  IRQ_RF_RX_TIMEOUT_MSK_MASK                         0x02000000u                   /**< Mask for IRQRFRxTimeoutMsk */
#define  IRQ_RF_RX_TIMEOUT_MSK_BMASK                        0x1u                          /**< Base mask for IRQRFRxTimeoutMsk */
#define  IRQ_RF_RX_TIMEOUT_MSK(x)                           (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutMsk in register */
#define  GET_IRQ_RF_RX_TIMEOUT_MSK(reg)                     (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutMsk from register */
/** @} */


/**
 * @name RegIRQRFMskSet
 * @{
 */
// RegIRQRFMskSet.r32
#define  REG_IRQ_RF_MSK_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRFMskSet */
#define  REG_IRQ_RF_MSK_SET_MASK                            0x037F013Fu                   /**< Mask for RegIRQRFMskSet */

#define  IRQ_RF_TX_MSK_SET_SHIFT                            0                             /**< Shift for IRQRFTxMskSet */
#define  IRQ_RF_TX_MSK_SET_MASK                             0x00000001u                   /**< Mask for IRQRFTxMskSet */
#define  IRQ_RF_TX_MSK_SET_BMASK                            0x1u                          /**< Base mask for IRQRFTxMskSet */
#define  IRQ_RF_TX_MSK_SET(x)                               (((x)&0x1u)<<0)               /**< Set IRQRFTxMskSet in register */
#define  GET_IRQ_RF_TX_MSK_SET(reg)                         (((reg)>>0)&0x1u)             /**< Get IRQRFTxMskSet from register */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_SET_SHIFT                 1                             /**< Shift for IRQRFTxFIFOEmptyMskSet */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_SET_MASK                  0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyMskSet */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_SET_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOEmptyMskSet */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_SET(x)                    (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyMskSet in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_MSK_SET(reg)              (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyMskSet from register */
#define  IRQ_RF_TX_FIFO_FULL_MSK_SET_SHIFT                  2                             /**< Shift for IRQRFTxFIFOFullMskSet */
#define  IRQ_RF_TX_FIFO_FULL_MSK_SET_MASK                   0x00000004u                   /**< Mask for IRQRFTxFIFOFullMskSet */
#define  IRQ_RF_TX_FIFO_FULL_MSK_SET_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOFullMskSet */
#define  IRQ_RF_TX_FIFO_FULL_MSK_SET(x)                     (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullMskSet in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_MSK_SET(reg)               (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullMskSet from register */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_SET_SHIFT                 3                             /**< Shift for IRQRFTxFIFOLimitMskSet */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_SET_MASK                  0x00000008u                   /**< Mask for IRQRFTxFIFOLimitMskSet */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_SET_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOLimitMskSet */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_SET(x)                    (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitMskSet in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_MSK_SET(reg)              (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitMskSet from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SET_SHIFT             4                             /**< Shift for IRQRFTxFIFOUnderflowMskSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SET_MASK              0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowMskSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SET_BMASK             0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowMskSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SET(x)                (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowMskSet in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_MSK_SET(reg)          (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowMskSet from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_SET_SHIFT              5                             /**< Shift for IRQRFTxFIFOOverflowMskSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_SET_MASK               0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowMskSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_SET_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOOverflowMskSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_SET(x)                 (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowMskSet in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_MSK_SET(reg)           (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowMskSet from register */
#define  IRQ_RF_TX_DONE_MSK_SET_SHIFT                       8                             /**< Shift for IRQRFTxDoneMskSet */
#define  IRQ_RF_TX_DONE_MSK_SET_MASK                        0x00000100u                   /**< Mask for IRQRFTxDoneMskSet */
#define  IRQ_RF_TX_DONE_MSK_SET_BMASK                       0x1u                          /**< Base mask for IRQRFTxDoneMskSet */
#define  IRQ_RF_TX_DONE_MSK_SET(x)                          (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneMskSet in register */
#define  GET_IRQ_RF_TX_DONE_MSK_SET(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneMskSet from register */
#define  IRQ_RF_RX_MSK_SET_SHIFT                            16                            /**< Shift for IRQRFRxMskSet */
#define  IRQ_RF_RX_MSK_SET_MASK                             0x00010000u                   /**< Mask for IRQRFRxMskSet */
#define  IRQ_RF_RX_MSK_SET_BMASK                            0x1u                          /**< Base mask for IRQRFRxMskSet */
#define  IRQ_RF_RX_MSK_SET(x)                               (((x)&0x1u)<<16)              /**< Set IRQRFRxMskSet in register */
#define  GET_IRQ_RF_RX_MSK_SET(reg)                         (((reg)>>16)&0x1u)            /**< Get IRQRFRxMskSet from register */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_SET_SHIFT                 17                            /**< Shift for IRQRFRxFIFOEmptyMskSet */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_SET_MASK                  0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyMskSet */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_SET_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOEmptyMskSet */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_SET(x)                    (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyMskSet in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_MSK_SET(reg)              (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyMskSet from register */
#define  IRQ_RF_RX_FIFO_FULL_MSK_SET_SHIFT                  18                            /**< Shift for IRQRFRxFIFOFullMskSet */
#define  IRQ_RF_RX_FIFO_FULL_MSK_SET_MASK                   0x00040000u                   /**< Mask for IRQRFRxFIFOFullMskSet */
#define  IRQ_RF_RX_FIFO_FULL_MSK_SET_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOFullMskSet */
#define  IRQ_RF_RX_FIFO_FULL_MSK_SET(x)                     (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullMskSet in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_MSK_SET(reg)               (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullMskSet from register */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_SET_SHIFT                 19                            /**< Shift for IRQRFRxFIFOLimitMskSet */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_SET_MASK                  0x00080000u                   /**< Mask for IRQRFRxFIFOLimitMskSet */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_SET_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOLimitMskSet */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_SET(x)                    (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitMskSet in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_MSK_SET(reg)              (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitMskSet from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SET_SHIFT             20                            /**< Shift for IRQRFRxFIFOUnderflowMskSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SET_MASK              0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowMskSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SET_BMASK             0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowMskSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SET(x)                (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowMskSet in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_MSK_SET(reg)          (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowMskSet from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_SET_SHIFT              21                            /**< Shift for IRQRFRxFIFOOverflowMskSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_SET_MASK               0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowMskSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_SET_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOOverflowMskSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_SET(x)                 (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowMskSet in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_MSK_SET(reg)           (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowMskSet from register */
#define  IRQ_RF_RX_SYNC_MSK_SET_SHIFT                       22                            /**< Shift for IRQRFRxSyncMskSet */
#define  IRQ_RF_RX_SYNC_MSK_SET_MASK                        0x00400000u                   /**< Mask for IRQRFRxSyncMskSet */
#define  IRQ_RF_RX_SYNC_MSK_SET_BMASK                       0x1u                          /**< Base mask for IRQRFRxSyncMskSet */
#define  IRQ_RF_RX_SYNC_MSK_SET(x)                          (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncMskSet in register */
#define  GET_IRQ_RF_RX_SYNC_MSK_SET(reg)                    (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncMskSet from register */
#define  IRQ_RF_RX_DONE_MSK_SET_SHIFT                       24                            /**< Shift for IRQRFRxDoneMskSet */
#define  IRQ_RF_RX_DONE_MSK_SET_MASK                        0x01000000u                   /**< Mask for IRQRFRxDoneMskSet */
#define  IRQ_RF_RX_DONE_MSK_SET_BMASK                       0x1u                          /**< Base mask for IRQRFRxDoneMskSet */
#define  IRQ_RF_RX_DONE_MSK_SET(x)                          (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneMskSet in register */
#define  GET_IRQ_RF_RX_DONE_MSK_SET(reg)                    (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneMskSet from register */
#define  IRQ_RF_RX_TIMEOUT_MSK_SET_SHIFT                    25                            /**< Shift for IRQRFRxTimeoutMskSet */
#define  IRQ_RF_RX_TIMEOUT_MSK_SET_MASK                     0x02000000u                   /**< Mask for IRQRFRxTimeoutMskSet */
#define  IRQ_RF_RX_TIMEOUT_MSK_SET_BMASK                    0x1u                          /**< Base mask for IRQRFRxTimeoutMskSet */
#define  IRQ_RF_RX_TIMEOUT_MSK_SET(x)                       (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutMskSet in register */
#define  GET_IRQ_RF_RX_TIMEOUT_MSK_SET(reg)                 (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutMskSet from register */
/** @} */


/**
 * @name RegIRQRFMskClr
 * @{
 */
// RegIRQRFMskClr.r32
#define  REG_IRQ_RF_MSK_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRFMskClr */
#define  REG_IRQ_RF_MSK_CLR_MASK                            0x037F013Fu                   /**< Mask for RegIRQRFMskClr */

#define  IRQ_RF_TX_MSK_CLR_SHIFT                            0                             /**< Shift for IRQRFTxMskClr */
#define  IRQ_RF_TX_MSK_CLR_MASK                             0x00000001u                   /**< Mask for IRQRFTxMskClr */
#define  IRQ_RF_TX_MSK_CLR_BMASK                            0x1u                          /**< Base mask for IRQRFTxMskClr */
#define  IRQ_RF_TX_MSK_CLR(x)                               (((x)&0x1u)<<0)               /**< Set IRQRFTxMskClr in register */
#define  GET_IRQ_RF_TX_MSK_CLR(reg)                         (((reg)>>0)&0x1u)             /**< Get IRQRFTxMskClr from register */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_CLR_SHIFT                 1                             /**< Shift for IRQRFTxFIFOEmptyMskClr */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_CLR_MASK                  0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyMskClr */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOEmptyMskClr */
#define  IRQ_RF_TX_FIFO_EMPTY_MSK_CLR(x)                    (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyMskClr in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_MSK_CLR(reg)              (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyMskClr from register */
#define  IRQ_RF_TX_FIFO_FULL_MSK_CLR_SHIFT                  2                             /**< Shift for IRQRFTxFIFOFullMskClr */
#define  IRQ_RF_TX_FIFO_FULL_MSK_CLR_MASK                   0x00000004u                   /**< Mask for IRQRFTxFIFOFullMskClr */
#define  IRQ_RF_TX_FIFO_FULL_MSK_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOFullMskClr */
#define  IRQ_RF_TX_FIFO_FULL_MSK_CLR(x)                     (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullMskClr in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_MSK_CLR(reg)               (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullMskClr from register */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_CLR_SHIFT                 3                             /**< Shift for IRQRFTxFIFOLimitMskClr */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_CLR_MASK                  0x00000008u                   /**< Mask for IRQRFTxFIFOLimitMskClr */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOLimitMskClr */
#define  IRQ_RF_TX_FIFO_LIMIT_MSK_CLR(x)                    (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitMskClr in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_MSK_CLR(reg)              (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitMskClr from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_CLR_SHIFT             4                             /**< Shift for IRQRFTxFIFOUnderflowMskClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_CLR_MASK              0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowMskClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_CLR_BMASK             0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowMskClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_MSK_CLR(x)                (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowMskClr in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_MSK_CLR(reg)          (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowMskClr from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_CLR_SHIFT              5                             /**< Shift for IRQRFTxFIFOOverflowMskClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_CLR_MASK               0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowMskClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_CLR_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOOverflowMskClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_MSK_CLR(x)                 (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowMskClr in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_MSK_CLR(reg)           (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowMskClr from register */
#define  IRQ_RF_TX_DONE_MSK_CLR_SHIFT                       8                             /**< Shift for IRQRFTxDoneMskClr */
#define  IRQ_RF_TX_DONE_MSK_CLR_MASK                        0x00000100u                   /**< Mask for IRQRFTxDoneMskClr */
#define  IRQ_RF_TX_DONE_MSK_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFTxDoneMskClr */
#define  IRQ_RF_TX_DONE_MSK_CLR(x)                          (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneMskClr in register */
#define  GET_IRQ_RF_TX_DONE_MSK_CLR(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneMskClr from register */
#define  IRQ_RF_RX_MSK_CLR_SHIFT                            16                            /**< Shift for IRQRFRxMskClr */
#define  IRQ_RF_RX_MSK_CLR_MASK                             0x00010000u                   /**< Mask for IRQRFRxMskClr */
#define  IRQ_RF_RX_MSK_CLR_BMASK                            0x1u                          /**< Base mask for IRQRFRxMskClr */
#define  IRQ_RF_RX_MSK_CLR(x)                               (((x)&0x1u)<<16)              /**< Set IRQRFRxMskClr in register */
#define  GET_IRQ_RF_RX_MSK_CLR(reg)                         (((reg)>>16)&0x1u)            /**< Get IRQRFRxMskClr from register */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_CLR_SHIFT                 17                            /**< Shift for IRQRFRxFIFOEmptyMskClr */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_CLR_MASK                  0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyMskClr */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOEmptyMskClr */
#define  IRQ_RF_RX_FIFO_EMPTY_MSK_CLR(x)                    (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyMskClr in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_MSK_CLR(reg)              (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyMskClr from register */
#define  IRQ_RF_RX_FIFO_FULL_MSK_CLR_SHIFT                  18                            /**< Shift for IRQRFRxFIFOFullMskClr */
#define  IRQ_RF_RX_FIFO_FULL_MSK_CLR_MASK                   0x00040000u                   /**< Mask for IRQRFRxFIFOFullMskClr */
#define  IRQ_RF_RX_FIFO_FULL_MSK_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOFullMskClr */
#define  IRQ_RF_RX_FIFO_FULL_MSK_CLR(x)                     (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullMskClr in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_MSK_CLR(reg)               (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullMskClr from register */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_CLR_SHIFT                 19                            /**< Shift for IRQRFRxFIFOLimitMskClr */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_CLR_MASK                  0x00080000u                   /**< Mask for IRQRFRxFIFOLimitMskClr */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOLimitMskClr */
#define  IRQ_RF_RX_FIFO_LIMIT_MSK_CLR(x)                    (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitMskClr in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_MSK_CLR(reg)              (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitMskClr from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_CLR_SHIFT             20                            /**< Shift for IRQRFRxFIFOUnderflowMskClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_CLR_MASK              0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowMskClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_CLR_BMASK             0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowMskClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_MSK_CLR(x)                (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowMskClr in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_MSK_CLR(reg)          (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowMskClr from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_CLR_SHIFT              21                            /**< Shift for IRQRFRxFIFOOverflowMskClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_CLR_MASK               0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowMskClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_CLR_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOOverflowMskClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_MSK_CLR(x)                 (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowMskClr in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_MSK_CLR(reg)           (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowMskClr from register */
#define  IRQ_RF_RX_SYNC_MSK_CLR_SHIFT                       22                            /**< Shift for IRQRFRxSyncMskClr */
#define  IRQ_RF_RX_SYNC_MSK_CLR_MASK                        0x00400000u                   /**< Mask for IRQRFRxSyncMskClr */
#define  IRQ_RF_RX_SYNC_MSK_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFRxSyncMskClr */
#define  IRQ_RF_RX_SYNC_MSK_CLR(x)                          (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncMskClr in register */
#define  GET_IRQ_RF_RX_SYNC_MSK_CLR(reg)                    (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncMskClr from register */
#define  IRQ_RF_RX_DONE_MSK_CLR_SHIFT                       24                            /**< Shift for IRQRFRxDoneMskClr */
#define  IRQ_RF_RX_DONE_MSK_CLR_MASK                        0x01000000u                   /**< Mask for IRQRFRxDoneMskClr */
#define  IRQ_RF_RX_DONE_MSK_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFRxDoneMskClr */
#define  IRQ_RF_RX_DONE_MSK_CLR(x)                          (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneMskClr in register */
#define  GET_IRQ_RF_RX_DONE_MSK_CLR(reg)                    (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneMskClr from register */
#define  IRQ_RF_RX_TIMEOUT_MSK_CLR_SHIFT                    25                            /**< Shift for IRQRFRxTimeoutMskClr */
#define  IRQ_RF_RX_TIMEOUT_MSK_CLR_MASK                     0x02000000u                   /**< Mask for IRQRFRxTimeoutMskClr */
#define  IRQ_RF_RX_TIMEOUT_MSK_CLR_BMASK                    0x1u                          /**< Base mask for IRQRFRxTimeoutMskClr */
#define  IRQ_RF_RX_TIMEOUT_MSK_CLR(x)                       (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutMskClr in register */
#define  GET_IRQ_RF_RX_TIMEOUT_MSK_CLR(reg)                 (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutMskClr from register */
/** @} */


/**
 * @name RegIRQRFSts
 * @{
 */
// RegIRQRFSts.r32
#define  REG_IRQ_RF_STS_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIRQRFSts */
#define  REG_IRQ_RF_STS_MASK                                0x037F013Fu                   /**< Mask for RegIRQRFSts */

#define  IRQ_RF_TX_STS_SHIFT                                0                             /**< Shift for IRQRFTxSts */
#define  IRQ_RF_TX_STS_MASK                                 0x00000001u                   /**< Mask for IRQRFTxSts */
#define  IRQ_RF_TX_STS_BMASK                                0x1u                          /**< Base mask for IRQRFTxSts */
#define  IRQ_RF_TX_STS(x)                                   (((x)&0x1u)<<0)               /**< Set IRQRFTxSts in register */
#define  GET_IRQ_RF_TX_STS(reg)                             (((reg)>>0)&0x1u)             /**< Get IRQRFTxSts from register */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_SHIFT                     1                             /**< Shift for IRQRFTxFIFOEmptySts */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_MASK                      0x00000002u                   /**< Mask for IRQRFTxFIFOEmptySts */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_BMASK                     0x1u                          /**< Base mask for IRQRFTxFIFOEmptySts */
#define  IRQ_RF_TX_FIFO_EMPTY_STS(x)                        (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptySts in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_STS(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptySts from register */
#define  IRQ_RF_TX_FIFO_FULL_STS_SHIFT                      2                             /**< Shift for IRQRFTxFIFOFullSts */
#define  IRQ_RF_TX_FIFO_FULL_STS_MASK                       0x00000004u                   /**< Mask for IRQRFTxFIFOFullSts */
#define  IRQ_RF_TX_FIFO_FULL_STS_BMASK                      0x1u                          /**< Base mask for IRQRFTxFIFOFullSts */
#define  IRQ_RF_TX_FIFO_FULL_STS(x)                         (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullSts in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_STS(reg)                   (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullSts from register */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_SHIFT                     3                             /**< Shift for IRQRFTxFIFOLimitSts */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_MASK                      0x00000008u                   /**< Mask for IRQRFTxFIFOLimitSts */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_BMASK                     0x1u                          /**< Base mask for IRQRFTxFIFOLimitSts */
#define  IRQ_RF_TX_FIFO_LIMIT_STS(x)                        (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitSts in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_STS(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitSts from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_SHIFT                 4                             /**< Shift for IRQRFTxFIFOUnderflowSts */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_MASK                  0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowSts */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowSts */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS(x)                    (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowSts in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_STS(reg)              (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowSts from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_SHIFT                  5                             /**< Shift for IRQRFTxFIFOOverflowSts */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_MASK                   0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowSts */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOOverflowSts */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS(x)                     (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowSts in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_STS(reg)               (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowSts from register */
#define  IRQ_RF_TX_DONE_STS_SHIFT                           8                             /**< Shift for IRQRFTxDoneSts */
#define  IRQ_RF_TX_DONE_STS_MASK                            0x00000100u                   /**< Mask for IRQRFTxDoneSts */
#define  IRQ_RF_TX_DONE_STS_BMASK                           0x1u                          /**< Base mask for IRQRFTxDoneSts */
#define  IRQ_RF_TX_DONE_STS(x)                              (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneSts in register */
#define  GET_IRQ_RF_TX_DONE_STS(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneSts from register */
#define  IRQ_RF_RX_STS_SHIFT                                16                            /**< Shift for IRQRFRxSts */
#define  IRQ_RF_RX_STS_MASK                                 0x00010000u                   /**< Mask for IRQRFRxSts */
#define  IRQ_RF_RX_STS_BMASK                                0x1u                          /**< Base mask for IRQRFRxSts */
#define  IRQ_RF_RX_STS(x)                                   (((x)&0x1u)<<16)              /**< Set IRQRFRxSts in register */
#define  GET_IRQ_RF_RX_STS(reg)                             (((reg)>>16)&0x1u)            /**< Get IRQRFRxSts from register */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_SHIFT                     17                            /**< Shift for IRQRFRxFIFOEmptySts */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_MASK                      0x00020000u                   /**< Mask for IRQRFRxFIFOEmptySts */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_BMASK                     0x1u                          /**< Base mask for IRQRFRxFIFOEmptySts */
#define  IRQ_RF_RX_FIFO_EMPTY_STS(x)                        (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptySts in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_STS(reg)                  (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptySts from register */
#define  IRQ_RF_RX_FIFO_FULL_STS_SHIFT                      18                            /**< Shift for IRQRFRxFIFOFullSts */
#define  IRQ_RF_RX_FIFO_FULL_STS_MASK                       0x00040000u                   /**< Mask for IRQRFRxFIFOFullSts */
#define  IRQ_RF_RX_FIFO_FULL_STS_BMASK                      0x1u                          /**< Base mask for IRQRFRxFIFOFullSts */
#define  IRQ_RF_RX_FIFO_FULL_STS(x)                         (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullSts in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_STS(reg)                   (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullSts from register */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_SHIFT                     19                            /**< Shift for IRQRFRxFIFOLimitSts */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_MASK                      0x00080000u                   /**< Mask for IRQRFRxFIFOLimitSts */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_BMASK                     0x1u                          /**< Base mask for IRQRFRxFIFOLimitSts */
#define  IRQ_RF_RX_FIFO_LIMIT_STS(x)                        (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitSts in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_STS(reg)                  (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitSts from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_SHIFT                 20                            /**< Shift for IRQRFRxFIFOUnderflowSts */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_MASK                  0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowSts */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowSts */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS(x)                    (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowSts in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_STS(reg)              (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowSts from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_SHIFT                  21                            /**< Shift for IRQRFRxFIFOOverflowSts */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_MASK                   0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowSts */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOOverflowSts */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS(x)                     (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowSts in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_STS(reg)               (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowSts from register */
#define  IRQ_RF_RX_SYNC_STS_SHIFT                           22                            /**< Shift for IRQRFRxSyncSts */
#define  IRQ_RF_RX_SYNC_STS_MASK                            0x00400000u                   /**< Mask for IRQRFRxSyncSts */
#define  IRQ_RF_RX_SYNC_STS_BMASK                           0x1u                          /**< Base mask for IRQRFRxSyncSts */
#define  IRQ_RF_RX_SYNC_STS(x)                              (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncSts in register */
#define  GET_IRQ_RF_RX_SYNC_STS(reg)                        (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncSts from register */
#define  IRQ_RF_RX_DONE_STS_SHIFT                           24                            /**< Shift for IRQRFRxDoneSts */
#define  IRQ_RF_RX_DONE_STS_MASK                            0x01000000u                   /**< Mask for IRQRFRxDoneSts */
#define  IRQ_RF_RX_DONE_STS_BMASK                           0x1u                          /**< Base mask for IRQRFRxDoneSts */
#define  IRQ_RF_RX_DONE_STS(x)                              (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneSts in register */
#define  GET_IRQ_RF_RX_DONE_STS(reg)                        (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneSts from register */
#define  IRQ_RF_RX_TIMEOUT_STS_SHIFT                        25                            /**< Shift for IRQRFRxTimeoutSts */
#define  IRQ_RF_RX_TIMEOUT_STS_MASK                         0x02000000u                   /**< Mask for IRQRFRxTimeoutSts */
#define  IRQ_RF_RX_TIMEOUT_STS_BMASK                        0x1u                          /**< Base mask for IRQRFRxTimeoutSts */
#define  IRQ_RF_RX_TIMEOUT_STS(x)                           (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutSts in register */
#define  GET_IRQ_RF_RX_TIMEOUT_STS(reg)                     (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutSts from register */
/** @} */


/**
 * @name RegIRQRFStsSet
 * @{
 */
// RegIRQRFStsSet.r32
#define  REG_IRQ_RF_STS_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRFStsSet */
#define  REG_IRQ_RF_STS_SET_MASK                            0x037F013Fu                   /**< Mask for RegIRQRFStsSet */

#define  IRQ_RF_TX_STS_SET_SHIFT                            0                             /**< Shift for IRQRFTxStsSet */
#define  IRQ_RF_TX_STS_SET_MASK                             0x00000001u                   /**< Mask for IRQRFTxStsSet */
#define  IRQ_RF_TX_STS_SET_BMASK                            0x1u                          /**< Base mask for IRQRFTxStsSet */
#define  IRQ_RF_TX_STS_SET(x)                               (((x)&0x1u)<<0)               /**< Set IRQRFTxStsSet in register */
#define  GET_IRQ_RF_TX_STS_SET(reg)                         (((reg)>>0)&0x1u)             /**< Get IRQRFTxStsSet from register */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_SET_SHIFT                 1                             /**< Shift for IRQRFTxFIFOEmptyStsSet */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_SET_MASK                  0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyStsSet */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_SET_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOEmptyStsSet */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_SET(x)                    (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyStsSet in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_STS_SET(reg)              (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyStsSet from register */
#define  IRQ_RF_TX_FIFO_FULL_STS_SET_SHIFT                  2                             /**< Shift for IRQRFTxFIFOFullStsSet */
#define  IRQ_RF_TX_FIFO_FULL_STS_SET_MASK                   0x00000004u                   /**< Mask for IRQRFTxFIFOFullStsSet */
#define  IRQ_RF_TX_FIFO_FULL_STS_SET_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOFullStsSet */
#define  IRQ_RF_TX_FIFO_FULL_STS_SET(x)                     (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullStsSet in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_STS_SET(reg)               (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullStsSet from register */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_SET_SHIFT                 3                             /**< Shift for IRQRFTxFIFOLimitStsSet */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_SET_MASK                  0x00000008u                   /**< Mask for IRQRFTxFIFOLimitStsSet */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_SET_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOLimitStsSet */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_SET(x)                    (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitStsSet in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_STS_SET(reg)              (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitStsSet from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_SET_SHIFT             4                             /**< Shift for IRQRFTxFIFOUnderflowStsSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_SET_MASK              0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowStsSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_SET_BMASK             0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowStsSet */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_SET(x)                (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowStsSet in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_STS_SET(reg)          (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowStsSet from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_SET_SHIFT              5                             /**< Shift for IRQRFTxFIFOOverflowStsSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_SET_MASK               0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowStsSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_SET_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOOverflowStsSet */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_SET(x)                 (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowStsSet in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_STS_SET(reg)           (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowStsSet from register */
#define  IRQ_RF_TX_DONE_STS_SET_SHIFT                       8                             /**< Shift for IRQRFTxDoneStsSet */
#define  IRQ_RF_TX_DONE_STS_SET_MASK                        0x00000100u                   /**< Mask for IRQRFTxDoneStsSet */
#define  IRQ_RF_TX_DONE_STS_SET_BMASK                       0x1u                          /**< Base mask for IRQRFTxDoneStsSet */
#define  IRQ_RF_TX_DONE_STS_SET(x)                          (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneStsSet in register */
#define  GET_IRQ_RF_TX_DONE_STS_SET(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneStsSet from register */
#define  IRQ_RF_RX_STS_SET_SHIFT                            16                            /**< Shift for IRQRFRxStsSet */
#define  IRQ_RF_RX_STS_SET_MASK                             0x00010000u                   /**< Mask for IRQRFRxStsSet */
#define  IRQ_RF_RX_STS_SET_BMASK                            0x1u                          /**< Base mask for IRQRFRxStsSet */
#define  IRQ_RF_RX_STS_SET(x)                               (((x)&0x1u)<<16)              /**< Set IRQRFRxStsSet in register */
#define  GET_IRQ_RF_RX_STS_SET(reg)                         (((reg)>>16)&0x1u)            /**< Get IRQRFRxStsSet from register */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_SET_SHIFT                 17                            /**< Shift for IRQRFRxFIFOEmptyStsSet */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_SET_MASK                  0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyStsSet */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_SET_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOEmptyStsSet */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_SET(x)                    (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyStsSet in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_STS_SET(reg)              (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyStsSet from register */
#define  IRQ_RF_RX_FIFO_FULL_STS_SET_SHIFT                  18                            /**< Shift for IRQRFRxFIFOFullStsSet */
#define  IRQ_RF_RX_FIFO_FULL_STS_SET_MASK                   0x00040000u                   /**< Mask for IRQRFRxFIFOFullStsSet */
#define  IRQ_RF_RX_FIFO_FULL_STS_SET_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOFullStsSet */
#define  IRQ_RF_RX_FIFO_FULL_STS_SET(x)                     (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullStsSet in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_STS_SET(reg)               (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullStsSet from register */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_SET_SHIFT                 19                            /**< Shift for IRQRFRxFIFOLimitStsSet */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_SET_MASK                  0x00080000u                   /**< Mask for IRQRFRxFIFOLimitStsSet */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_SET_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOLimitStsSet */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_SET(x)                    (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitStsSet in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_STS_SET(reg)              (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitStsSet from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_SET_SHIFT             20                            /**< Shift for IRQRFRxFIFOUnderflowStsSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_SET_MASK              0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowStsSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_SET_BMASK             0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowStsSet */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_SET(x)                (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowStsSet in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_STS_SET(reg)          (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowStsSet from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_SET_SHIFT              21                            /**< Shift for IRQRFRxFIFOOverflowStsSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_SET_MASK               0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowStsSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_SET_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOOverflowStsSet */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_SET(x)                 (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowStsSet in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_STS_SET(reg)           (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowStsSet from register */
#define  IRQ_RF_RX_SYNC_STS_SET_SHIFT                       22                            /**< Shift for IRQRFRxSyncStsSet */
#define  IRQ_RF_RX_SYNC_STS_SET_MASK                        0x00400000u                   /**< Mask for IRQRFRxSyncStsSet */
#define  IRQ_RF_RX_SYNC_STS_SET_BMASK                       0x1u                          /**< Base mask for IRQRFRxSyncStsSet */
#define  IRQ_RF_RX_SYNC_STS_SET(x)                          (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncStsSet in register */
#define  GET_IRQ_RF_RX_SYNC_STS_SET(reg)                    (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncStsSet from register */
#define  IRQ_RF_RX_DONE_STS_SET_SHIFT                       24                            /**< Shift for IRQRFRxDoneStsSet */
#define  IRQ_RF_RX_DONE_STS_SET_MASK                        0x01000000u                   /**< Mask for IRQRFRxDoneStsSet */
#define  IRQ_RF_RX_DONE_STS_SET_BMASK                       0x1u                          /**< Base mask for IRQRFRxDoneStsSet */
#define  IRQ_RF_RX_DONE_STS_SET(x)                          (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneStsSet in register */
#define  GET_IRQ_RF_RX_DONE_STS_SET(reg)                    (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneStsSet from register */
#define  IRQ_RF_RX_TIMEOUT_STS_SET_SHIFT                    25                            /**< Shift for IRQRFRxTimeoutStsSet */
#define  IRQ_RF_RX_TIMEOUT_STS_SET_MASK                     0x02000000u                   /**< Mask for IRQRFRxTimeoutStsSet */
#define  IRQ_RF_RX_TIMEOUT_STS_SET_BMASK                    0x1u                          /**< Base mask for IRQRFRxTimeoutStsSet */
#define  IRQ_RF_RX_TIMEOUT_STS_SET(x)                       (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutStsSet in register */
#define  GET_IRQ_RF_RX_TIMEOUT_STS_SET(reg)                 (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutStsSet from register */
/** @} */


/**
 * @name RegIRQRFStsClr
 * @{
 */
// RegIRQRFStsClr.r32
#define  REG_IRQ_RF_STS_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRFStsClr */
#define  REG_IRQ_RF_STS_CLR_MASK                            0x037F013Fu                   /**< Mask for RegIRQRFStsClr */

#define  IRQ_RF_TX_STS_CLR_SHIFT                            0                             /**< Shift for IRQRFTxStsClr */
#define  IRQ_RF_TX_STS_CLR_MASK                             0x00000001u                   /**< Mask for IRQRFTxStsClr */
#define  IRQ_RF_TX_STS_CLR_BMASK                            0x1u                          /**< Base mask for IRQRFTxStsClr */
#define  IRQ_RF_TX_STS_CLR(x)                               (((x)&0x1u)<<0)               /**< Set IRQRFTxStsClr in register */
#define  GET_IRQ_RF_TX_STS_CLR(reg)                         (((reg)>>0)&0x1u)             /**< Get IRQRFTxStsClr from register */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_CLR_SHIFT                 1                             /**< Shift for IRQRFTxFIFOEmptyStsClr */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_CLR_MASK                  0x00000002u                   /**< Mask for IRQRFTxFIFOEmptyStsClr */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOEmptyStsClr */
#define  IRQ_RF_TX_FIFO_EMPTY_STS_CLR(x)                    (((x)&0x1u)<<1)               /**< Set IRQRFTxFIFOEmptyStsClr in register */
#define  GET_IRQ_RF_TX_FIFO_EMPTY_STS_CLR(reg)              (((reg)>>1)&0x1u)             /**< Get IRQRFTxFIFOEmptyStsClr from register */
#define  IRQ_RF_TX_FIFO_FULL_STS_CLR_SHIFT                  2                             /**< Shift for IRQRFTxFIFOFullStsClr */
#define  IRQ_RF_TX_FIFO_FULL_STS_CLR_MASK                   0x00000004u                   /**< Mask for IRQRFTxFIFOFullStsClr */
#define  IRQ_RF_TX_FIFO_FULL_STS_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFTxFIFOFullStsClr */
#define  IRQ_RF_TX_FIFO_FULL_STS_CLR(x)                     (((x)&0x1u)<<2)               /**< Set IRQRFTxFIFOFullStsClr in register */
#define  GET_IRQ_RF_TX_FIFO_FULL_STS_CLR(reg)               (((reg)>>2)&0x1u)             /**< Get IRQRFTxFIFOFullStsClr from register */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_CLR_SHIFT                 3                             /**< Shift for IRQRFTxFIFOLimitStsClr */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_CLR_MASK                  0x00000008u                   /**< Mask for IRQRFTxFIFOLimitStsClr */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFTxFIFOLimitStsClr */
#define  IRQ_RF_TX_FIFO_LIMIT_STS_CLR(x)                    (((x)&0x1u)<<3)               /**< Set IRQRFTxFIFOLimitStsClr in register */
#define  GET_IRQ_RF_TX_FIFO_LIMIT_STS_CLR(reg)              (((reg)>>3)&0x1u)             /**< Get IRQRFTxFIFOLimitStsClr from register */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_CLR_SHIFT             4                             /**< Shift for IRQRFTxFIFOUnderflowStsClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_CLR_MASK              0x00000010u                   /**< Mask for IRQRFTxFIFOUnderflowStsClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_CLR_BMASK             0x1u                          /**< Base mask for IRQRFTxFIFOUnderflowStsClr */
#define  IRQ_RF_TX_FIFO_UNDERFLOW_STS_CLR(x)                (((x)&0x1u)<<4)               /**< Set IRQRFTxFIFOUnderflowStsClr in register */
#define  GET_IRQ_RF_TX_FIFO_UNDERFLOW_STS_CLR(reg)          (((reg)>>4)&0x1u)             /**< Get IRQRFTxFIFOUnderflowStsClr from register */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_CLR_SHIFT              5                             /**< Shift for IRQRFTxFIFOOverflowStsClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_CLR_MASK               0x00000020u                   /**< Mask for IRQRFTxFIFOOverflowStsClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_CLR_BMASK              0x1u                          /**< Base mask for IRQRFTxFIFOOverflowStsClr */
#define  IRQ_RF_TX_FIFO_OVERFLOW_STS_CLR(x)                 (((x)&0x1u)<<5)               /**< Set IRQRFTxFIFOOverflowStsClr in register */
#define  GET_IRQ_RF_TX_FIFO_OVERFLOW_STS_CLR(reg)           (((reg)>>5)&0x1u)             /**< Get IRQRFTxFIFOOverflowStsClr from register */
#define  IRQ_RF_TX_DONE_STS_CLR_SHIFT                       8                             /**< Shift for IRQRFTxDoneStsClr */
#define  IRQ_RF_TX_DONE_STS_CLR_MASK                        0x00000100u                   /**< Mask for IRQRFTxDoneStsClr */
#define  IRQ_RF_TX_DONE_STS_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFTxDoneStsClr */
#define  IRQ_RF_TX_DONE_STS_CLR(x)                          (((x)&0x1u)<<8)               /**< Set IRQRFTxDoneStsClr in register */
#define  GET_IRQ_RF_TX_DONE_STS_CLR(reg)                    (((reg)>>8)&0x1u)             /**< Get IRQRFTxDoneStsClr from register */
#define  IRQ_RF_RX_STS_CLR_SHIFT                            16                            /**< Shift for IRQRFRxStsClr */
#define  IRQ_RF_RX_STS_CLR_MASK                             0x00010000u                   /**< Mask for IRQRFRxStsClr */
#define  IRQ_RF_RX_STS_CLR_BMASK                            0x1u                          /**< Base mask for IRQRFRxStsClr */
#define  IRQ_RF_RX_STS_CLR(x)                               (((x)&0x1u)<<16)              /**< Set IRQRFRxStsClr in register */
#define  GET_IRQ_RF_RX_STS_CLR(reg)                         (((reg)>>16)&0x1u)            /**< Get IRQRFRxStsClr from register */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_CLR_SHIFT                 17                            /**< Shift for IRQRFRxFIFOEmptyStsClr */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_CLR_MASK                  0x00020000u                   /**< Mask for IRQRFRxFIFOEmptyStsClr */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOEmptyStsClr */
#define  IRQ_RF_RX_FIFO_EMPTY_STS_CLR(x)                    (((x)&0x1u)<<17)              /**< Set IRQRFRxFIFOEmptyStsClr in register */
#define  GET_IRQ_RF_RX_FIFO_EMPTY_STS_CLR(reg)              (((reg)>>17)&0x1u)            /**< Get IRQRFRxFIFOEmptyStsClr from register */
#define  IRQ_RF_RX_FIFO_FULL_STS_CLR_SHIFT                  18                            /**< Shift for IRQRFRxFIFOFullStsClr */
#define  IRQ_RF_RX_FIFO_FULL_STS_CLR_MASK                   0x00040000u                   /**< Mask for IRQRFRxFIFOFullStsClr */
#define  IRQ_RF_RX_FIFO_FULL_STS_CLR_BMASK                  0x1u                          /**< Base mask for IRQRFRxFIFOFullStsClr */
#define  IRQ_RF_RX_FIFO_FULL_STS_CLR(x)                     (((x)&0x1u)<<18)              /**< Set IRQRFRxFIFOFullStsClr in register */
#define  GET_IRQ_RF_RX_FIFO_FULL_STS_CLR(reg)               (((reg)>>18)&0x1u)            /**< Get IRQRFRxFIFOFullStsClr from register */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_CLR_SHIFT                 19                            /**< Shift for IRQRFRxFIFOLimitStsClr */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_CLR_MASK                  0x00080000u                   /**< Mask for IRQRFRxFIFOLimitStsClr */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_CLR_BMASK                 0x1u                          /**< Base mask for IRQRFRxFIFOLimitStsClr */
#define  IRQ_RF_RX_FIFO_LIMIT_STS_CLR(x)                    (((x)&0x1u)<<19)              /**< Set IRQRFRxFIFOLimitStsClr in register */
#define  GET_IRQ_RF_RX_FIFO_LIMIT_STS_CLR(reg)              (((reg)>>19)&0x1u)            /**< Get IRQRFRxFIFOLimitStsClr from register */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_CLR_SHIFT             20                            /**< Shift for IRQRFRxFIFOUnderflowStsClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_CLR_MASK              0x00100000u                   /**< Mask for IRQRFRxFIFOUnderflowStsClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_CLR_BMASK             0x1u                          /**< Base mask for IRQRFRxFIFOUnderflowStsClr */
#define  IRQ_RF_RX_FIFO_UNDERFLOW_STS_CLR(x)                (((x)&0x1u)<<20)              /**< Set IRQRFRxFIFOUnderflowStsClr in register */
#define  GET_IRQ_RF_RX_FIFO_UNDERFLOW_STS_CLR(reg)          (((reg)>>20)&0x1u)            /**< Get IRQRFRxFIFOUnderflowStsClr from register */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_CLR_SHIFT              21                            /**< Shift for IRQRFRxFIFOOverflowStsClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_CLR_MASK               0x00200000u                   /**< Mask for IRQRFRxFIFOOverflowStsClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_CLR_BMASK              0x1u                          /**< Base mask for IRQRFRxFIFOOverflowStsClr */
#define  IRQ_RF_RX_FIFO_OVERFLOW_STS_CLR(x)                 (((x)&0x1u)<<21)              /**< Set IRQRFRxFIFOOverflowStsClr in register */
#define  GET_IRQ_RF_RX_FIFO_OVERFLOW_STS_CLR(reg)           (((reg)>>21)&0x1u)            /**< Get IRQRFRxFIFOOverflowStsClr from register */
#define  IRQ_RF_RX_SYNC_STS_CLR_SHIFT                       22                            /**< Shift for IRQRFRxSyncStsClr */
#define  IRQ_RF_RX_SYNC_STS_CLR_MASK                        0x00400000u                   /**< Mask for IRQRFRxSyncStsClr */
#define  IRQ_RF_RX_SYNC_STS_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFRxSyncStsClr */
#define  IRQ_RF_RX_SYNC_STS_CLR(x)                          (((x)&0x1u)<<22)              /**< Set IRQRFRxSyncStsClr in register */
#define  GET_IRQ_RF_RX_SYNC_STS_CLR(reg)                    (((reg)>>22)&0x1u)            /**< Get IRQRFRxSyncStsClr from register */
#define  IRQ_RF_RX_DONE_STS_CLR_SHIFT                       24                            /**< Shift for IRQRFRxDoneStsClr */
#define  IRQ_RF_RX_DONE_STS_CLR_MASK                        0x01000000u                   /**< Mask for IRQRFRxDoneStsClr */
#define  IRQ_RF_RX_DONE_STS_CLR_BMASK                       0x1u                          /**< Base mask for IRQRFRxDoneStsClr */
#define  IRQ_RF_RX_DONE_STS_CLR(x)                          (((x)&0x1u)<<24)              /**< Set IRQRFRxDoneStsClr in register */
#define  GET_IRQ_RF_RX_DONE_STS_CLR(reg)                    (((reg)>>24)&0x1u)            /**< Get IRQRFRxDoneStsClr from register */
#define  IRQ_RF_RX_TIMEOUT_STS_CLR_SHIFT                    25                            /**< Shift for IRQRFRxTimeoutStsClr */
#define  IRQ_RF_RX_TIMEOUT_STS_CLR_MASK                     0x02000000u                   /**< Mask for IRQRFRxTimeoutStsClr */
#define  IRQ_RF_RX_TIMEOUT_STS_CLR_BMASK                    0x1u                          /**< Base mask for IRQRFRxTimeoutStsClr */
#define  IRQ_RF_RX_TIMEOUT_STS_CLR(x)                       (((x)&0x1u)<<25)              /**< Set IRQRFRxTimeoutStsClr in register */
#define  GET_IRQ_RF_RX_TIMEOUT_STS_CLR(reg)                 (((reg)>>25)&0x1u)            /**< Get IRQRFRxTimeoutStsClr from register */
/** @} */


/**
 * @name RegIRQSPISEn
 * @{
 */
// RegIRQSPISEn.r32
#define  REG_IRQ_SPIS_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQSPISEn */
#define  REG_IRQ_SPIS_EN_MASK                               0x00003D3Bu                   /**< Mask for RegIRQSPISEn */

#define  IRQ_SPIS_TX_EN_SHIFT                               0                             /**< Shift for IRQSPISTxEn */
#define  IRQ_SPIS_TX_EN_MASK                                0x00000001u                   /**< Mask for IRQSPISTxEn */
#define  IRQ_SPIS_TX_EN_BMASK                               0x1u                          /**< Base mask for IRQSPISTxEn */
#define  IRQ_SPIS_TX_EN(x)                                  (((x)&0x1u)<<0)               /**< Set IRQSPISTxEn in register */
#define  GET_IRQ_SPIS_TX_EN(reg)                            (((reg)>>0)&0x1u)             /**< Get IRQSPISTxEn from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_SHIFT                    1                             /**< Shift for IRQSPISTxFIFOEmptyEn */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_MASK                     0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyEn */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_BMASK                    0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyEn */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN(x)                       (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyEn in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_EN(reg)                 (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyEn from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_SHIFT                    3                             /**< Shift for IRQSPISTxFIFOLimitEn */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_MASK                     0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitEn */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_BMASK                    0x1u                          /**< Base mask for IRQSPISTxFIFOLimitEn */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN(x)                       (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitEn in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_EN(reg)                 (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitEn from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SHIFT                4                             /**< Shift for IRQSPISTxFIFOUnderflowEn */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_MASK                 0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowEn */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowEn */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN(x)                   (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowEn in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_EN(reg)             (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowEn from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SHIFT                 5                             /**< Shift for IRQSPISTxFIFOOverflowEn */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_MASK                  0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowEn */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowEn */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN(x)                    (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowEn in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_EN(reg)              (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowEn from register */
#define  IRQ_SPIS_RX_EN_SHIFT                               8                             /**< Shift for IRQSPISRxEn */
#define  IRQ_SPIS_RX_EN_MASK                                0x00000100u                   /**< Mask for IRQSPISRxEn */
#define  IRQ_SPIS_RX_EN_BMASK                               0x1u                          /**< Base mask for IRQSPISRxEn */
#define  IRQ_SPIS_RX_EN(x)                                  (((x)&0x1u)<<8)               /**< Set IRQSPISRxEn in register */
#define  GET_IRQ_SPIS_RX_EN(reg)                            (((reg)>>8)&0x1u)             /**< Get IRQSPISRxEn from register */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_SHIFT                     10                            /**< Shift for IRQSPISRxFIFOFullEn */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_MASK                      0x00000400u                   /**< Mask for IRQSPISRxFIFOFullEn */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_BMASK                     0x1u                          /**< Base mask for IRQSPISRxFIFOFullEn */
#define  IRQ_SPIS_RX_FIFO_FULL_EN(x)                        (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullEn in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_EN(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullEn from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_SHIFT                    11                            /**< Shift for IRQSPISRxFIFOLimitEn */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_MASK                     0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitEn */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_BMASK                    0x1u                          /**< Base mask for IRQSPISRxFIFOLimitEn */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN(x)                       (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitEn in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_EN(reg)                 (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitEn from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SHIFT                12                            /**< Shift for IRQSPISRxFIFOUnderflowEn */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_MASK                 0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowEn */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowEn */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN(x)                   (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowEn in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_EN(reg)             (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowEn from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SHIFT                 13                            /**< Shift for IRQSPISRxFIFOOverflowEn */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_MASK                  0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowEn */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowEn */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN(x)                    (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowEn in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_EN(reg)              (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowEn from register */
/** @} */


/**
 * @name RegIRQSPISEnSet
 * @{
 */
// RegIRQSPISEnSet.r32
#define  REG_IRQ_SPIS_EN_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSPISEnSet */
#define  REG_IRQ_SPIS_EN_SET_MASK                           0x00003D3Bu                   /**< Mask for RegIRQSPISEnSet */

#define  IRQ_SPIS_TX_EN_SET_SHIFT                           0                             /**< Shift for IRQSPISTxEnSet */
#define  IRQ_SPIS_TX_EN_SET_MASK                            0x00000001u                   /**< Mask for IRQSPISTxEnSet */
#define  IRQ_SPIS_TX_EN_SET_BMASK                           0x1u                          /**< Base mask for IRQSPISTxEnSet */
#define  IRQ_SPIS_TX_EN_SET(x)                              (((x)&0x1u)<<0)               /**< Set IRQSPISTxEnSet in register */
#define  GET_IRQ_SPIS_TX_EN_SET(reg)                        (((reg)>>0)&0x1u)             /**< Get IRQSPISTxEnSet from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_SET_SHIFT                1                             /**< Shift for IRQSPISTxFIFOEmptyEnSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_SET_MASK                 0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyEnSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_SET_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyEnSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_SET(x)                   (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyEnSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_EN_SET(reg)             (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyEnSet from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_SET_SHIFT                3                             /**< Shift for IRQSPISTxFIFOLimitEnSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_SET_MASK                 0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitEnSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_SET_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOLimitEnSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_SET(x)                   (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitEnSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_EN_SET(reg)             (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitEnSet from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SET_SHIFT            4                             /**< Shift for IRQSPISTxFIFOUnderflowEnSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SET_MASK             0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowEnSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SET_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowEnSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SET(x)               (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowEnSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_SET(reg)         (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowEnSet from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SET_SHIFT             5                             /**< Shift for IRQSPISTxFIFOOverflowEnSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SET_MASK              0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowEnSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowEnSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SET(x)                (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowEnSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_EN_SET(reg)          (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowEnSet from register */
#define  IRQ_SPIS_RX_EN_SET_SHIFT                           8                             /**< Shift for IRQSPISRxEnSet */
#define  IRQ_SPIS_RX_EN_SET_MASK                            0x00000100u                   /**< Mask for IRQSPISRxEnSet */
#define  IRQ_SPIS_RX_EN_SET_BMASK                           0x1u                          /**< Base mask for IRQSPISRxEnSet */
#define  IRQ_SPIS_RX_EN_SET(x)                              (((x)&0x1u)<<8)               /**< Set IRQSPISRxEnSet in register */
#define  GET_IRQ_SPIS_RX_EN_SET(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQSPISRxEnSet from register */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_SET_SHIFT                 10                            /**< Shift for IRQSPISRxFIFOFullEnSet */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_SET_MASK                  0x00000400u                   /**< Mask for IRQSPISRxFIFOFullEnSet */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_SET_BMASK                 0x1u                          /**< Base mask for IRQSPISRxFIFOFullEnSet */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_SET(x)                    (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullEnSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_EN_SET(reg)              (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullEnSet from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_SET_SHIFT                11                            /**< Shift for IRQSPISRxFIFOLimitEnSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_SET_MASK                 0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitEnSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_SET_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOLimitEnSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_SET(x)                   (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitEnSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_EN_SET(reg)             (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitEnSet from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SET_SHIFT            12                            /**< Shift for IRQSPISRxFIFOUnderflowEnSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SET_MASK             0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowEnSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SET_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowEnSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SET(x)               (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowEnSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_SET(reg)         (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowEnSet from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SET_SHIFT             13                            /**< Shift for IRQSPISRxFIFOOverflowEnSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SET_MASK              0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowEnSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowEnSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SET(x)                (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowEnSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_EN_SET(reg)          (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowEnSet from register */
/** @} */


/**
 * @name RegIRQSPISEnClr
 * @{
 */
// RegIRQSPISEnClr.r32
#define  REG_IRQ_SPIS_EN_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSPISEnClr */
#define  REG_IRQ_SPIS_EN_CLR_MASK                           0x00003D3Bu                   /**< Mask for RegIRQSPISEnClr */

#define  IRQ_SPIS_TX_EN_CLR_SHIFT                           0                             /**< Shift for IRQSPISTxEnClr */
#define  IRQ_SPIS_TX_EN_CLR_MASK                            0x00000001u                   /**< Mask for IRQSPISTxEnClr */
#define  IRQ_SPIS_TX_EN_CLR_BMASK                           0x1u                          /**< Base mask for IRQSPISTxEnClr */
#define  IRQ_SPIS_TX_EN_CLR(x)                              (((x)&0x1u)<<0)               /**< Set IRQSPISTxEnClr in register */
#define  GET_IRQ_SPIS_TX_EN_CLR(reg)                        (((reg)>>0)&0x1u)             /**< Get IRQSPISTxEnClr from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_CLR_SHIFT                1                             /**< Shift for IRQSPISTxFIFOEmptyEnClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_CLR_MASK                 0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyEnClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyEnClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_EN_CLR(x)                   (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyEnClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_EN_CLR(reg)             (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyEnClr from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_CLR_SHIFT                3                             /**< Shift for IRQSPISTxFIFOLimitEnClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_CLR_MASK                 0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitEnClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOLimitEnClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_EN_CLR(x)                   (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitEnClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_EN_CLR(reg)             (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitEnClr from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_CLR_SHIFT            4                             /**< Shift for IRQSPISTxFIFOUnderflowEnClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_CLR_MASK             0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowEnClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowEnClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_CLR(x)               (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowEnClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_EN_CLR(reg)         (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowEnClr from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_CLR_SHIFT             5                             /**< Shift for IRQSPISTxFIFOOverflowEnClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_CLR_MASK              0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowEnClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowEnClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_EN_CLR(x)                (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowEnClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_EN_CLR(reg)          (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowEnClr from register */
#define  IRQ_SPIS_RX_EN_CLR_SHIFT                           8                             /**< Shift for IRQSPISRxEnClr */
#define  IRQ_SPIS_RX_EN_CLR_MASK                            0x00000100u                   /**< Mask for IRQSPISRxEnClr */
#define  IRQ_SPIS_RX_EN_CLR_BMASK                           0x1u                          /**< Base mask for IRQSPISRxEnClr */
#define  IRQ_SPIS_RX_EN_CLR(x)                              (((x)&0x1u)<<8)               /**< Set IRQSPISRxEnClr in register */
#define  GET_IRQ_SPIS_RX_EN_CLR(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQSPISRxEnClr from register */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_CLR_SHIFT                 10                            /**< Shift for IRQSPISRxFIFOFullEnClr */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_CLR_MASK                  0x00000400u                   /**< Mask for IRQSPISRxFIFOFullEnClr */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_CLR_BMASK                 0x1u                          /**< Base mask for IRQSPISRxFIFOFullEnClr */
#define  IRQ_SPIS_RX_FIFO_FULL_EN_CLR(x)                    (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullEnClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_EN_CLR(reg)              (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullEnClr from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_CLR_SHIFT                11                            /**< Shift for IRQSPISRxFIFOLimitEnClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_CLR_MASK                 0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitEnClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOLimitEnClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_EN_CLR(x)                   (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitEnClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_EN_CLR(reg)             (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitEnClr from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_CLR_SHIFT            12                            /**< Shift for IRQSPISRxFIFOUnderflowEnClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_CLR_MASK             0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowEnClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowEnClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_CLR(x)               (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowEnClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_EN_CLR(reg)         (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowEnClr from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_CLR_SHIFT             13                            /**< Shift for IRQSPISRxFIFOOverflowEnClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_CLR_MASK              0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowEnClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowEnClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_EN_CLR(x)                (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowEnClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_EN_CLR(reg)          (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowEnClr from register */
/** @} */


/**
 * @name RegIRQSPISMsk
 * @{
 */
// RegIRQSPISMsk.r32
#define  REG_IRQ_SPIS_MSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQSPISMsk */
#define  REG_IRQ_SPIS_MSK_MASK                              0x00003D3Bu                   /**< Mask for RegIRQSPISMsk */

#define  IRQ_SPIS_TX_MSK_SHIFT                              0                             /**< Shift for IRQSPISTxMsk */
#define  IRQ_SPIS_TX_MSK_MASK                               0x00000001u                   /**< Mask for IRQSPISTxMsk */
#define  IRQ_SPIS_TX_MSK_BMASK                              0x1u                          /**< Base mask for IRQSPISTxMsk */
#define  IRQ_SPIS_TX_MSK(x)                                 (((x)&0x1u)<<0)               /**< Set IRQSPISTxMsk in register */
#define  GET_IRQ_SPIS_TX_MSK(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQSPISTxMsk from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_SHIFT                   1                             /**< Shift for IRQSPISTxFIFOEmptyMsk */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_MASK                    0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyMsk */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_BMASK                   0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyMsk */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK(x)                      (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyMsk in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_MSK(reg)                (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyMsk from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_SHIFT                   3                             /**< Shift for IRQSPISTxFIFOLimitMsk */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_MASK                    0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitMsk */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_BMASK                   0x1u                          /**< Base mask for IRQSPISTxFIFOLimitMsk */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK(x)                      (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitMsk in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_MSK(reg)                (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitMsk from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SHIFT               4                             /**< Shift for IRQSPISTxFIFOUnderflowMsk */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_MASK                0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowMsk */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowMsk */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK(x)                  (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowMsk in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK(reg)            (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowMsk from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SHIFT                5                             /**< Shift for IRQSPISTxFIFOOverflowMsk */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_MASK                 0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowMsk */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowMsk */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK(x)                   (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowMsk in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_MSK(reg)             (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowMsk from register */
#define  IRQ_SPIS_RX_MSK_SHIFT                              8                             /**< Shift for IRQSPISRxMsk */
#define  IRQ_SPIS_RX_MSK_MASK                               0x00000100u                   /**< Mask for IRQSPISRxMsk */
#define  IRQ_SPIS_RX_MSK_BMASK                              0x1u                          /**< Base mask for IRQSPISRxMsk */
#define  IRQ_SPIS_RX_MSK(x)                                 (((x)&0x1u)<<8)               /**< Set IRQSPISRxMsk in register */
#define  GET_IRQ_SPIS_RX_MSK(reg)                           (((reg)>>8)&0x1u)             /**< Get IRQSPISRxMsk from register */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_SHIFT                    10                            /**< Shift for IRQSPISRxFIFOFullMsk */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_MASK                     0x00000400u                   /**< Mask for IRQSPISRxFIFOFullMsk */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_BMASK                    0x1u                          /**< Base mask for IRQSPISRxFIFOFullMsk */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK(x)                       (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullMsk in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_MSK(reg)                 (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullMsk from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_SHIFT                   11                            /**< Shift for IRQSPISRxFIFOLimitMsk */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_MASK                    0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitMsk */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_BMASK                   0x1u                          /**< Base mask for IRQSPISRxFIFOLimitMsk */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK(x)                      (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitMsk in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_MSK(reg)                (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitMsk from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SHIFT               12                            /**< Shift for IRQSPISRxFIFOUnderflowMsk */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_MASK                0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowMsk */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowMsk */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK(x)                  (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowMsk in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK(reg)            (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowMsk from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SHIFT                13                            /**< Shift for IRQSPISRxFIFOOverflowMsk */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_MASK                 0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowMsk */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowMsk */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK(x)                   (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowMsk in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_MSK(reg)             (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowMsk from register */
/** @} */


/**
 * @name RegIRQSPISMskSet
 * @{
 */
// RegIRQSPISMskSet.r32
#define  REG_IRQ_SPIS_MSK_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPISMskSet */
#define  REG_IRQ_SPIS_MSK_SET_MASK                          0x00003D3Bu                   /**< Mask for RegIRQSPISMskSet */

#define  IRQ_SPIS_TX_MSK_SET_SHIFT                          0                             /**< Shift for IRQSPISTxMskSet */
#define  IRQ_SPIS_TX_MSK_SET_MASK                           0x00000001u                   /**< Mask for IRQSPISTxMskSet */
#define  IRQ_SPIS_TX_MSK_SET_BMASK                          0x1u                          /**< Base mask for IRQSPISTxMskSet */
#define  IRQ_SPIS_TX_MSK_SET(x)                             (((x)&0x1u)<<0)               /**< Set IRQSPISTxMskSet in register */
#define  GET_IRQ_SPIS_TX_MSK_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQSPISTxMskSet from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_SET_SHIFT               1                             /**< Shift for IRQSPISTxFIFOEmptyMskSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_SET_MASK                0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyMskSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyMskSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyMskSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_MSK_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyMskSet from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_SET_SHIFT               3                             /**< Shift for IRQSPISTxFIFOLimitMskSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_SET_MASK                0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitMskSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOLimitMskSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitMskSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_MSK_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitMskSet from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SET_SHIFT           4                             /**< Shift for IRQSPISTxFIFOUnderflowMskSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SET_MASK            0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowMskSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SET_BMASK           0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowMskSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SET(x)              (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowMskSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_SET(reg)        (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowMskSet from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SET_SHIFT            5                             /**< Shift for IRQSPISTxFIFOOverflowMskSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SET_MASK             0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowMskSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowMskSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SET(x)               (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowMskSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_SET(reg)         (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowMskSet from register */
#define  IRQ_SPIS_RX_MSK_SET_SHIFT                          8                             /**< Shift for IRQSPISRxMskSet */
#define  IRQ_SPIS_RX_MSK_SET_MASK                           0x00000100u                   /**< Mask for IRQSPISRxMskSet */
#define  IRQ_SPIS_RX_MSK_SET_BMASK                          0x1u                          /**< Base mask for IRQSPISRxMskSet */
#define  IRQ_SPIS_RX_MSK_SET(x)                             (((x)&0x1u)<<8)               /**< Set IRQSPISRxMskSet in register */
#define  GET_IRQ_SPIS_RX_MSK_SET(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQSPISRxMskSet from register */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_SET_SHIFT                10                            /**< Shift for IRQSPISRxFIFOFullMskSet */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_SET_MASK                 0x00000400u                   /**< Mask for IRQSPISRxFIFOFullMskSet */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_SET_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOFullMskSet */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_SET(x)                   (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullMskSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_MSK_SET(reg)             (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullMskSet from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_SET_SHIFT               11                            /**< Shift for IRQSPISRxFIFOLimitMskSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_SET_MASK                0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitMskSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOLimitMskSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_SET(x)                  (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitMskSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_MSK_SET(reg)            (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitMskSet from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SET_SHIFT           12                            /**< Shift for IRQSPISRxFIFOUnderflowMskSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SET_MASK            0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowMskSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SET_BMASK           0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowMskSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SET(x)              (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowMskSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_SET(reg)        (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowMskSet from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SET_SHIFT            13                            /**< Shift for IRQSPISRxFIFOOverflowMskSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SET_MASK             0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowMskSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowMskSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SET(x)               (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowMskSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_SET(reg)         (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowMskSet from register */
/** @} */


/**
 * @name RegIRQSPISMskClr
 * @{
 */
// RegIRQSPISMskClr.r32
#define  REG_IRQ_SPIS_MSK_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPISMskClr */
#define  REG_IRQ_SPIS_MSK_CLR_MASK                          0x00003D3Bu                   /**< Mask for RegIRQSPISMskClr */

#define  IRQ_SPIS_TX_MSK_CLR_SHIFT                          0                             /**< Shift for IRQSPISTxMskClr */
#define  IRQ_SPIS_TX_MSK_CLR_MASK                           0x00000001u                   /**< Mask for IRQSPISTxMskClr */
#define  IRQ_SPIS_TX_MSK_CLR_BMASK                          0x1u                          /**< Base mask for IRQSPISTxMskClr */
#define  IRQ_SPIS_TX_MSK_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IRQSPISTxMskClr in register */
#define  GET_IRQ_SPIS_TX_MSK_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQSPISTxMskClr from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_CLR_SHIFT               1                             /**< Shift for IRQSPISTxFIFOEmptyMskClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_CLR_MASK                0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyMskClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyMskClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_MSK_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyMskClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_MSK_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyMskClr from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_CLR_SHIFT               3                             /**< Shift for IRQSPISTxFIFOLimitMskClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_CLR_MASK                0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitMskClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOLimitMskClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_MSK_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitMskClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_MSK_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitMskClr from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_CLR_SHIFT           4                             /**< Shift for IRQSPISTxFIFOUnderflowMskClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_CLR_MASK            0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowMskClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_CLR_BMASK           0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowMskClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_CLR(x)              (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowMskClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_MSK_CLR(reg)        (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowMskClr from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_CLR_SHIFT            5                             /**< Shift for IRQSPISTxFIFOOverflowMskClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_CLR_MASK             0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowMskClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowMskClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_CLR(x)               (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowMskClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_MSK_CLR(reg)         (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowMskClr from register */
#define  IRQ_SPIS_RX_MSK_CLR_SHIFT                          8                             /**< Shift for IRQSPISRxMskClr */
#define  IRQ_SPIS_RX_MSK_CLR_MASK                           0x00000100u                   /**< Mask for IRQSPISRxMskClr */
#define  IRQ_SPIS_RX_MSK_CLR_BMASK                          0x1u                          /**< Base mask for IRQSPISRxMskClr */
#define  IRQ_SPIS_RX_MSK_CLR(x)                             (((x)&0x1u)<<8)               /**< Set IRQSPISRxMskClr in register */
#define  GET_IRQ_SPIS_RX_MSK_CLR(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQSPISRxMskClr from register */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_CLR_SHIFT                10                            /**< Shift for IRQSPISRxFIFOFullMskClr */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_CLR_MASK                 0x00000400u                   /**< Mask for IRQSPISRxFIFOFullMskClr */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_CLR_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOFullMskClr */
#define  IRQ_SPIS_RX_FIFO_FULL_MSK_CLR(x)                   (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullMskClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_MSK_CLR(reg)             (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullMskClr from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_CLR_SHIFT               11                            /**< Shift for IRQSPISRxFIFOLimitMskClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_CLR_MASK                0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitMskClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOLimitMskClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_MSK_CLR(x)                  (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitMskClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_MSK_CLR(reg)            (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitMskClr from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_CLR_SHIFT           12                            /**< Shift for IRQSPISRxFIFOUnderflowMskClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_CLR_MASK            0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowMskClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_CLR_BMASK           0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowMskClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_CLR(x)              (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowMskClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_MSK_CLR(reg)        (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowMskClr from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_CLR_SHIFT            13                            /**< Shift for IRQSPISRxFIFOOverflowMskClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_CLR_MASK             0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowMskClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowMskClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_CLR(x)               (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowMskClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_MSK_CLR(reg)         (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowMskClr from register */
/** @} */


/**
 * @name RegIRQSPISSts
 * @{
 */
// RegIRQSPISSts.r32
#define  REG_IRQ_SPIS_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQSPISSts */
#define  REG_IRQ_SPIS_STS_MASK                              0x00003D3Bu                   /**< Mask for RegIRQSPISSts */

#define  IRQ_SPIS_TX_STS_SHIFT                              0                             /**< Shift for IRQSPISTxSts */
#define  IRQ_SPIS_TX_STS_MASK                               0x00000001u                   /**< Mask for IRQSPISTxSts */
#define  IRQ_SPIS_TX_STS_BMASK                              0x1u                          /**< Base mask for IRQSPISTxSts */
#define  IRQ_SPIS_TX_STS(x)                                 (((x)&0x1u)<<0)               /**< Set IRQSPISTxSts in register */
#define  GET_IRQ_SPIS_TX_STS(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQSPISTxSts from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_SHIFT                   1                             /**< Shift for IRQSPISTxFIFOEmptySts */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_MASK                    0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptySts */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_BMASK                   0x1u                          /**< Base mask for IRQSPISTxFIFOEmptySts */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS(x)                      (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptySts in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_STS(reg)                (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptySts from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_SHIFT                   3                             /**< Shift for IRQSPISTxFIFOLimitSts */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_MASK                    0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitSts */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_BMASK                   0x1u                          /**< Base mask for IRQSPISTxFIFOLimitSts */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS(x)                      (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitSts in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_STS(reg)                (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitSts from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SHIFT               4                             /**< Shift for IRQSPISTxFIFOUnderflowSts */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_MASK                0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowSts */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowSts */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS(x)                  (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowSts in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_STS(reg)            (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowSts from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SHIFT                5                             /**< Shift for IRQSPISTxFIFOOverflowSts */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_MASK                 0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowSts */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_BMASK                0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowSts */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS(x)                   (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowSts in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_STS(reg)             (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowSts from register */
#define  IRQ_SPIS_RX_STS_SHIFT                              8                             /**< Shift for IRQSPISRxSts */
#define  IRQ_SPIS_RX_STS_MASK                               0x00000100u                   /**< Mask for IRQSPISRxSts */
#define  IRQ_SPIS_RX_STS_BMASK                              0x1u                          /**< Base mask for IRQSPISRxSts */
#define  IRQ_SPIS_RX_STS(x)                                 (((x)&0x1u)<<8)               /**< Set IRQSPISRxSts in register */
#define  GET_IRQ_SPIS_RX_STS(reg)                           (((reg)>>8)&0x1u)             /**< Get IRQSPISRxSts from register */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_SHIFT                    10                            /**< Shift for IRQSPISRxFIFOFullSts */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_MASK                     0x00000400u                   /**< Mask for IRQSPISRxFIFOFullSts */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_BMASK                    0x1u                          /**< Base mask for IRQSPISRxFIFOFullSts */
#define  IRQ_SPIS_RX_FIFO_FULL_STS(x)                       (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullSts in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_STS(reg)                 (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullSts from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_SHIFT                   11                            /**< Shift for IRQSPISRxFIFOLimitSts */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_MASK                    0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitSts */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_BMASK                   0x1u                          /**< Base mask for IRQSPISRxFIFOLimitSts */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS(x)                      (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitSts in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_STS(reg)                (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitSts from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SHIFT               12                            /**< Shift for IRQSPISRxFIFOUnderflowSts */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_MASK                0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowSts */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowSts */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS(x)                  (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowSts in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_STS(reg)            (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowSts from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SHIFT                13                            /**< Shift for IRQSPISRxFIFOOverflowSts */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_MASK                 0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowSts */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowSts */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS(x)                   (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowSts in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_STS(reg)             (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowSts from register */
/** @} */


/**
 * @name RegIRQSPISStsSet
 * @{
 */
// RegIRQSPISStsSet.r32
#define  REG_IRQ_SPIS_STS_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPISStsSet */
#define  REG_IRQ_SPIS_STS_SET_MASK                          0x00003D3Bu                   /**< Mask for RegIRQSPISStsSet */

#define  IRQ_SPIS_TX_STS_SET_SHIFT                          0                             /**< Shift for IRQSPISTxStsSet */
#define  IRQ_SPIS_TX_STS_SET_MASK                           0x00000001u                   /**< Mask for IRQSPISTxStsSet */
#define  IRQ_SPIS_TX_STS_SET_BMASK                          0x1u                          /**< Base mask for IRQSPISTxStsSet */
#define  IRQ_SPIS_TX_STS_SET(x)                             (((x)&0x1u)<<0)               /**< Set IRQSPISTxStsSet in register */
#define  GET_IRQ_SPIS_TX_STS_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQSPISTxStsSet from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_SET_SHIFT               1                             /**< Shift for IRQSPISTxFIFOEmptyStsSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_SET_MASK                0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyStsSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_SET_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyStsSet */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyStsSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_STS_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyStsSet from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_SET_SHIFT               3                             /**< Shift for IRQSPISTxFIFOLimitStsSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_SET_MASK                0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitStsSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_SET_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOLimitStsSet */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitStsSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_STS_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitStsSet from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SET_SHIFT           4                             /**< Shift for IRQSPISTxFIFOUnderflowStsSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SET_MASK            0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowStsSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SET_BMASK           0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowStsSet */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SET(x)              (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowStsSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_SET(reg)        (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowStsSet from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SET_SHIFT            5                             /**< Shift for IRQSPISTxFIFOOverflowStsSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SET_MASK             0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowStsSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowStsSet */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SET(x)               (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowStsSet in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_STS_SET(reg)         (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowStsSet from register */
#define  IRQ_SPIS_RX_STS_SET_SHIFT                          8                             /**< Shift for IRQSPISRxStsSet */
#define  IRQ_SPIS_RX_STS_SET_MASK                           0x00000100u                   /**< Mask for IRQSPISRxStsSet */
#define  IRQ_SPIS_RX_STS_SET_BMASK                          0x1u                          /**< Base mask for IRQSPISRxStsSet */
#define  IRQ_SPIS_RX_STS_SET(x)                             (((x)&0x1u)<<8)               /**< Set IRQSPISRxStsSet in register */
#define  GET_IRQ_SPIS_RX_STS_SET(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQSPISRxStsSet from register */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_SET_SHIFT                10                            /**< Shift for IRQSPISRxFIFOFullStsSet */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_SET_MASK                 0x00000400u                   /**< Mask for IRQSPISRxFIFOFullStsSet */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_SET_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOFullStsSet */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_SET(x)                   (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullStsSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_STS_SET(reg)             (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullStsSet from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_SET_SHIFT               11                            /**< Shift for IRQSPISRxFIFOLimitStsSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_SET_MASK                0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitStsSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_SET_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOLimitStsSet */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_SET(x)                  (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitStsSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_STS_SET(reg)            (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitStsSet from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SET_SHIFT           12                            /**< Shift for IRQSPISRxFIFOUnderflowStsSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SET_MASK            0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowStsSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SET_BMASK           0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowStsSet */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SET(x)              (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowStsSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_SET(reg)        (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowStsSet from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SET_SHIFT            13                            /**< Shift for IRQSPISRxFIFOOverflowStsSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SET_MASK             0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowStsSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowStsSet */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SET(x)               (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowStsSet in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_STS_SET(reg)         (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowStsSet from register */
/** @} */


/**
 * @name RegIRQSPISStsClr
 * @{
 */
// RegIRQSPISStsClr.r32
#define  REG_IRQ_SPIS_STS_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPISStsClr */
#define  REG_IRQ_SPIS_STS_CLR_MASK                          0x00003D3Bu                   /**< Mask for RegIRQSPISStsClr */

#define  IRQ_SPIS_TX_STS_CLR_SHIFT                          0                             /**< Shift for IRQSPISTxStsClr */
#define  IRQ_SPIS_TX_STS_CLR_MASK                           0x00000001u                   /**< Mask for IRQSPISTxStsClr */
#define  IRQ_SPIS_TX_STS_CLR_BMASK                          0x1u                          /**< Base mask for IRQSPISTxStsClr */
#define  IRQ_SPIS_TX_STS_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IRQSPISTxStsClr in register */
#define  GET_IRQ_SPIS_TX_STS_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQSPISTxStsClr from register */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_CLR_SHIFT               1                             /**< Shift for IRQSPISTxFIFOEmptyStsClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_CLR_MASK                0x00000002u                   /**< Mask for IRQSPISTxFIFOEmptyStsClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOEmptyStsClr */
#define  IRQ_SPIS_TX_FIFO_EMPTY_STS_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQSPISTxFIFOEmptyStsClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_EMPTY_STS_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQSPISTxFIFOEmptyStsClr from register */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_CLR_SHIFT               3                             /**< Shift for IRQSPISTxFIFOLimitStsClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_CLR_MASK                0x00000008u                   /**< Mask for IRQSPISTxFIFOLimitStsClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISTxFIFOLimitStsClr */
#define  IRQ_SPIS_TX_FIFO_LIMIT_STS_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQSPISTxFIFOLimitStsClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_LIMIT_STS_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQSPISTxFIFOLimitStsClr from register */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_CLR_SHIFT           4                             /**< Shift for IRQSPISTxFIFOUnderflowStsClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_CLR_MASK            0x00000010u                   /**< Mask for IRQSPISTxFIFOUnderflowStsClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_CLR_BMASK           0x1u                          /**< Base mask for IRQSPISTxFIFOUnderflowStsClr */
#define  IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_CLR(x)              (((x)&0x1u)<<4)               /**< Set IRQSPISTxFIFOUnderflowStsClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_UNDERFLOW_STS_CLR(reg)        (((reg)>>4)&0x1u)             /**< Get IRQSPISTxFIFOUnderflowStsClr from register */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_CLR_SHIFT            5                             /**< Shift for IRQSPISTxFIFOOverflowStsClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_CLR_MASK             0x00000020u                   /**< Mask for IRQSPISTxFIFOOverflowStsClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISTxFIFOOverflowStsClr */
#define  IRQ_SPIS_TX_FIFO_OVERFLOW_STS_CLR(x)               (((x)&0x1u)<<5)               /**< Set IRQSPISTxFIFOOverflowStsClr in register */
#define  GET_IRQ_SPIS_TX_FIFO_OVERFLOW_STS_CLR(reg)         (((reg)>>5)&0x1u)             /**< Get IRQSPISTxFIFOOverflowStsClr from register */
#define  IRQ_SPIS_RX_STS_CLR_SHIFT                          8                             /**< Shift for IRQSPISRxStsClr */
#define  IRQ_SPIS_RX_STS_CLR_MASK                           0x00000100u                   /**< Mask for IRQSPISRxStsClr */
#define  IRQ_SPIS_RX_STS_CLR_BMASK                          0x1u                          /**< Base mask for IRQSPISRxStsClr */
#define  IRQ_SPIS_RX_STS_CLR(x)                             (((x)&0x1u)<<8)               /**< Set IRQSPISRxStsClr in register */
#define  GET_IRQ_SPIS_RX_STS_CLR(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQSPISRxStsClr from register */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_CLR_SHIFT                10                            /**< Shift for IRQSPISRxFIFOFullStsClr */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_CLR_MASK                 0x00000400u                   /**< Mask for IRQSPISRxFIFOFullStsClr */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_CLR_BMASK                0x1u                          /**< Base mask for IRQSPISRxFIFOFullStsClr */
#define  IRQ_SPIS_RX_FIFO_FULL_STS_CLR(x)                   (((x)&0x1u)<<10)              /**< Set IRQSPISRxFIFOFullStsClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_FULL_STS_CLR(reg)             (((reg)>>10)&0x1u)            /**< Get IRQSPISRxFIFOFullStsClr from register */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_CLR_SHIFT               11                            /**< Shift for IRQSPISRxFIFOLimitStsClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_CLR_MASK                0x00000800u                   /**< Mask for IRQSPISRxFIFOLimitStsClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQSPISRxFIFOLimitStsClr */
#define  IRQ_SPIS_RX_FIFO_LIMIT_STS_CLR(x)                  (((x)&0x1u)<<11)              /**< Set IRQSPISRxFIFOLimitStsClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_LIMIT_STS_CLR(reg)            (((reg)>>11)&0x1u)            /**< Get IRQSPISRxFIFOLimitStsClr from register */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_CLR_SHIFT           12                            /**< Shift for IRQSPISRxFIFOUnderflowStsClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_CLR_MASK            0x00001000u                   /**< Mask for IRQSPISRxFIFOUnderflowStsClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_CLR_BMASK           0x1u                          /**< Base mask for IRQSPISRxFIFOUnderflowStsClr */
#define  IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_CLR(x)              (((x)&0x1u)<<12)              /**< Set IRQSPISRxFIFOUnderflowStsClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_UNDERFLOW_STS_CLR(reg)        (((reg)>>12)&0x1u)            /**< Get IRQSPISRxFIFOUnderflowStsClr from register */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_CLR_SHIFT            13                            /**< Shift for IRQSPISRxFIFOOverflowStsClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_CLR_MASK             0x00002000u                   /**< Mask for IRQSPISRxFIFOOverflowStsClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IRQSPISRxFIFOOverflowStsClr */
#define  IRQ_SPIS_RX_FIFO_OVERFLOW_STS_CLR(x)               (((x)&0x1u)<<13)              /**< Set IRQSPISRxFIFOOverflowStsClr in register */
#define  GET_IRQ_SPIS_RX_FIFO_OVERFLOW_STS_CLR(reg)         (((reg)>>13)&0x1u)            /**< Get IRQSPISRxFIFOOverflowStsClr from register */
/** @} */


/**
 * @name RegIRQUARTEn
 * @{
 */
// RegIRQUARTEn.r32
#define  REG_IRQ_UART_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQUARTEn */
#define  REG_IRQ_UART_EN_MASK                               0x0000FD2Bu                   /**< Mask for RegIRQUARTEn */

#define  IRQ_UART_TX_EN_SHIFT                               0                             /**< Shift for IRQUARTTxEn */
#define  IRQ_UART_TX_EN_MASK                                0x00000001u                   /**< Mask for IRQUARTTxEn */
#define  IRQ_UART_TX_EN_BMASK                               0x1u                          /**< Base mask for IRQUARTTxEn */
#define  IRQ_UART_TX_EN(x)                                  (((x)&0x1u)<<0)               /**< Set IRQUARTTxEn in register */
#define  GET_IRQ_UART_TX_EN(reg)                            (((reg)>>0)&0x1u)             /**< Get IRQUARTTxEn from register */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_SHIFT                    1                             /**< Shift for IRQUARTTxFIFOEmptyEn */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_MASK                     0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyEn */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_BMASK                    0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyEn */
#define  IRQ_UART_TX_FIFO_EMPTY_EN(x)                       (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyEn in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_EN(reg)                 (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyEn from register */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_SHIFT                    3                             /**< Shift for IRQUARTTxFIFOLimitEn */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_MASK                     0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitEn */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_BMASK                    0x1u                          /**< Base mask for IRQUARTTxFIFOLimitEn */
#define  IRQ_UART_TX_FIFO_LIMIT_EN(x)                       (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitEn in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_EN(reg)                 (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitEn from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_SHIFT                 5                             /**< Shift for IRQUARTTxFIFOOverflowEn */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_MASK                  0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowEn */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowEn */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN(x)                    (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowEn in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_EN(reg)              (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowEn from register */
#define  IRQ_UART_RX_EN_SHIFT                               8                             /**< Shift for IRQUARTRxEn */
#define  IRQ_UART_RX_EN_MASK                                0x00000100u                   /**< Mask for IRQUARTRxEn */
#define  IRQ_UART_RX_EN_BMASK                               0x1u                          /**< Base mask for IRQUARTRxEn */
#define  IRQ_UART_RX_EN(x)                                  (((x)&0x1u)<<8)               /**< Set IRQUARTRxEn in register */
#define  GET_IRQ_UART_RX_EN(reg)                            (((reg)>>8)&0x1u)             /**< Get IRQUARTRxEn from register */
#define  IRQ_UART_RX_FIFO_FULL_EN_SHIFT                     10                            /**< Shift for IRQUARTRxFIFOFullEn */
#define  IRQ_UART_RX_FIFO_FULL_EN_MASK                      0x00000400u                   /**< Mask for IRQUARTRxFIFOFullEn */
#define  IRQ_UART_RX_FIFO_FULL_EN_BMASK                     0x1u                          /**< Base mask for IRQUARTRxFIFOFullEn */
#define  IRQ_UART_RX_FIFO_FULL_EN(x)                        (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullEn in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_EN(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullEn from register */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_SHIFT                    11                            /**< Shift for IRQUARTRxFIFOLimitEn */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_MASK                     0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitEn */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_BMASK                    0x1u                          /**< Base mask for IRQUARTRxFIFOLimitEn */
#define  IRQ_UART_RX_FIFO_LIMIT_EN(x)                       (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitEn in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_EN(reg)                 (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitEn from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_SHIFT                12                            /**< Shift for IRQUARTRxFIFOUnderflowEn */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_MASK                 0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowEn */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowEn */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN(x)                   (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowEn in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_EN(reg)             (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowEn from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_SHIFT                 13                            /**< Shift for IRQUARTRxFIFOOverflowEn */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_MASK                  0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowEn */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowEn */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN(x)                    (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowEn in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_EN(reg)              (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowEn from register */
#define  IRQ_UART_RX_FRAME_ERROR_EN_SHIFT                   14                            /**< Shift for IRQUARTRxFrameErrorEn */
#define  IRQ_UART_RX_FRAME_ERROR_EN_MASK                    0x00004000u                   /**< Mask for IRQUARTRxFrameErrorEn */
#define  IRQ_UART_RX_FRAME_ERROR_EN_BMASK                   0x1u                          /**< Base mask for IRQUARTRxFrameErrorEn */
#define  IRQ_UART_RX_FRAME_ERROR_EN(x)                      (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorEn in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_EN(reg)                (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorEn from register */
#define  IRQ_UART_RX_PARITY_ERROR_EN_SHIFT                  15                            /**< Shift for IRQUARTRxParityErrorEn */
#define  IRQ_UART_RX_PARITY_ERROR_EN_MASK                   0x00008000u                   /**< Mask for IRQUARTRxParityErrorEn */
#define  IRQ_UART_RX_PARITY_ERROR_EN_BMASK                  0x1u                          /**< Base mask for IRQUARTRxParityErrorEn */
#define  IRQ_UART_RX_PARITY_ERROR_EN(x)                     (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorEn in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_EN(reg)               (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorEn from register */
/** @} */


/**
 * @name RegIRQUARTEnSet
 * @{
 */
// RegIRQUARTEnSet.r32
#define  REG_IRQ_UART_EN_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQUARTEnSet */
#define  REG_IRQ_UART_EN_SET_MASK                           0x0000FD2Bu                   /**< Mask for RegIRQUARTEnSet */

#define  IRQ_UART_TX_EN_SET_SHIFT                           0                             /**< Shift for IRQUARTTxEnSet */
#define  IRQ_UART_TX_EN_SET_MASK                            0x00000001u                   /**< Mask for IRQUARTTxEnSet */
#define  IRQ_UART_TX_EN_SET_BMASK                           0x1u                          /**< Base mask for IRQUARTTxEnSet */
#define  IRQ_UART_TX_EN_SET(x)                              (((x)&0x1u)<<0)               /**< Set IRQUARTTxEnSet in register */
#define  GET_IRQ_UART_TX_EN_SET(reg)                        (((reg)>>0)&0x1u)             /**< Get IRQUARTTxEnSet from register */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_SET_SHIFT                1                             /**< Shift for IRQUARTTxFIFOEmptyEnSet */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_SET_MASK                 0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyEnSet */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_SET_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyEnSet */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_SET(x)                   (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyEnSet in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_EN_SET(reg)             (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyEnSet from register */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_SET_SHIFT                3                             /**< Shift for IRQUARTTxFIFOLimitEnSet */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_SET_MASK                 0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitEnSet */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_SET_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOLimitEnSet */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_SET(x)                   (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitEnSet in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_EN_SET(reg)             (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitEnSet from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_SET_SHIFT             5                             /**< Shift for IRQUARTTxFIFOOverflowEnSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_SET_MASK              0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowEnSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowEnSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_SET(x)                (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowEnSet in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_EN_SET(reg)          (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowEnSet from register */
#define  IRQ_UART_RX_EN_SET_SHIFT                           8                             /**< Shift for IRQUARTRxEnSet */
#define  IRQ_UART_RX_EN_SET_MASK                            0x00000100u                   /**< Mask for IRQUARTRxEnSet */
#define  IRQ_UART_RX_EN_SET_BMASK                           0x1u                          /**< Base mask for IRQUARTRxEnSet */
#define  IRQ_UART_RX_EN_SET(x)                              (((x)&0x1u)<<8)               /**< Set IRQUARTRxEnSet in register */
#define  GET_IRQ_UART_RX_EN_SET(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQUARTRxEnSet from register */
#define  IRQ_UART_RX_FIFO_FULL_EN_SET_SHIFT                 10                            /**< Shift for IRQUARTRxFIFOFullEnSet */
#define  IRQ_UART_RX_FIFO_FULL_EN_SET_MASK                  0x00000400u                   /**< Mask for IRQUARTRxFIFOFullEnSet */
#define  IRQ_UART_RX_FIFO_FULL_EN_SET_BMASK                 0x1u                          /**< Base mask for IRQUARTRxFIFOFullEnSet */
#define  IRQ_UART_RX_FIFO_FULL_EN_SET(x)                    (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullEnSet in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_EN_SET(reg)              (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullEnSet from register */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_SET_SHIFT                11                            /**< Shift for IRQUARTRxFIFOLimitEnSet */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_SET_MASK                 0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitEnSet */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_SET_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOLimitEnSet */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_SET(x)                   (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitEnSet in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_EN_SET(reg)             (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitEnSet from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_SET_SHIFT            12                            /**< Shift for IRQUARTRxFIFOUnderflowEnSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_SET_MASK             0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowEnSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_SET_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowEnSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_SET(x)               (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowEnSet in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_EN_SET(reg)         (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowEnSet from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_SET_SHIFT             13                            /**< Shift for IRQUARTRxFIFOOverflowEnSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_SET_MASK              0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowEnSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowEnSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_SET(x)                (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowEnSet in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_EN_SET(reg)          (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowEnSet from register */
#define  IRQ_UART_RX_FRAME_ERROR_EN_SET_SHIFT               14                            /**< Shift for IRQUARTRxFrameErrorEnSet */
#define  IRQ_UART_RX_FRAME_ERROR_EN_SET_MASK                0x00004000u                   /**< Mask for IRQUARTRxFrameErrorEnSet */
#define  IRQ_UART_RX_FRAME_ERROR_EN_SET_BMASK               0x1u                          /**< Base mask for IRQUARTRxFrameErrorEnSet */
#define  IRQ_UART_RX_FRAME_ERROR_EN_SET(x)                  (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorEnSet in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_EN_SET(reg)            (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorEnSet from register */
#define  IRQ_UART_RX_PARITY_ERROR_EN_SET_SHIFT              15                            /**< Shift for IRQUARTRxParityErrorEnSet */
#define  IRQ_UART_RX_PARITY_ERROR_EN_SET_MASK               0x00008000u                   /**< Mask for IRQUARTRxParityErrorEnSet */
#define  IRQ_UART_RX_PARITY_ERROR_EN_SET_BMASK              0x1u                          /**< Base mask for IRQUARTRxParityErrorEnSet */
#define  IRQ_UART_RX_PARITY_ERROR_EN_SET(x)                 (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorEnSet in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_EN_SET(reg)           (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorEnSet from register */
/** @} */


/**
 * @name RegIRQUARTEnClr
 * @{
 */
// RegIRQUARTEnClr.r32
#define  REG_IRQ_UART_EN_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQUARTEnClr */
#define  REG_IRQ_UART_EN_CLR_MASK                           0x0000FD2Bu                   /**< Mask for RegIRQUARTEnClr */

#define  IRQ_UART_TX_EN_CLR_SHIFT                           0                             /**< Shift for IRQUARTTxEnClr */
#define  IRQ_UART_TX_EN_CLR_MASK                            0x00000001u                   /**< Mask for IRQUARTTxEnClr */
#define  IRQ_UART_TX_EN_CLR_BMASK                           0x1u                          /**< Base mask for IRQUARTTxEnClr */
#define  IRQ_UART_TX_EN_CLR(x)                              (((x)&0x1u)<<0)               /**< Set IRQUARTTxEnClr in register */
#define  GET_IRQ_UART_TX_EN_CLR(reg)                        (((reg)>>0)&0x1u)             /**< Get IRQUARTTxEnClr from register */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_CLR_SHIFT                1                             /**< Shift for IRQUARTTxFIFOEmptyEnClr */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_CLR_MASK                 0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyEnClr */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyEnClr */
#define  IRQ_UART_TX_FIFO_EMPTY_EN_CLR(x)                   (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyEnClr in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_EN_CLR(reg)             (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyEnClr from register */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_CLR_SHIFT                3                             /**< Shift for IRQUARTTxFIFOLimitEnClr */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_CLR_MASK                 0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitEnClr */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOLimitEnClr */
#define  IRQ_UART_TX_FIFO_LIMIT_EN_CLR(x)                   (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitEnClr in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_EN_CLR(reg)             (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitEnClr from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_CLR_SHIFT             5                             /**< Shift for IRQUARTTxFIFOOverflowEnClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_CLR_MASK              0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowEnClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowEnClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_EN_CLR(x)                (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowEnClr in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_EN_CLR(reg)          (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowEnClr from register */
#define  IRQ_UART_RX_EN_CLR_SHIFT                           8                             /**< Shift for IRQUARTRxEnClr */
#define  IRQ_UART_RX_EN_CLR_MASK                            0x00000100u                   /**< Mask for IRQUARTRxEnClr */
#define  IRQ_UART_RX_EN_CLR_BMASK                           0x1u                          /**< Base mask for IRQUARTRxEnClr */
#define  IRQ_UART_RX_EN_CLR(x)                              (((x)&0x1u)<<8)               /**< Set IRQUARTRxEnClr in register */
#define  GET_IRQ_UART_RX_EN_CLR(reg)                        (((reg)>>8)&0x1u)             /**< Get IRQUARTRxEnClr from register */
#define  IRQ_UART_RX_FIFO_FULL_EN_CLR_SHIFT                 10                            /**< Shift for IRQUARTRxFIFOFullEnClr */
#define  IRQ_UART_RX_FIFO_FULL_EN_CLR_MASK                  0x00000400u                   /**< Mask for IRQUARTRxFIFOFullEnClr */
#define  IRQ_UART_RX_FIFO_FULL_EN_CLR_BMASK                 0x1u                          /**< Base mask for IRQUARTRxFIFOFullEnClr */
#define  IRQ_UART_RX_FIFO_FULL_EN_CLR(x)                    (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullEnClr in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_EN_CLR(reg)              (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullEnClr from register */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_CLR_SHIFT                11                            /**< Shift for IRQUARTRxFIFOLimitEnClr */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_CLR_MASK                 0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitEnClr */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOLimitEnClr */
#define  IRQ_UART_RX_FIFO_LIMIT_EN_CLR(x)                   (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitEnClr in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_EN_CLR(reg)             (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitEnClr from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_CLR_SHIFT            12                            /**< Shift for IRQUARTRxFIFOUnderflowEnClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_CLR_MASK             0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowEnClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_CLR_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowEnClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_EN_CLR(x)               (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowEnClr in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_EN_CLR(reg)         (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowEnClr from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_CLR_SHIFT             13                            /**< Shift for IRQUARTRxFIFOOverflowEnClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_CLR_MASK              0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowEnClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowEnClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_EN_CLR(x)                (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowEnClr in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_EN_CLR(reg)          (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowEnClr from register */
#define  IRQ_UART_RX_FRAME_ERROR_EN_CLR_SHIFT               14                            /**< Shift for IRQUARTRxFrameErrorEnClr */
#define  IRQ_UART_RX_FRAME_ERROR_EN_CLR_MASK                0x00004000u                   /**< Mask for IRQUARTRxFrameErrorEnClr */
#define  IRQ_UART_RX_FRAME_ERROR_EN_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTRxFrameErrorEnClr */
#define  IRQ_UART_RX_FRAME_ERROR_EN_CLR(x)                  (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorEnClr in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_EN_CLR(reg)            (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorEnClr from register */
#define  IRQ_UART_RX_PARITY_ERROR_EN_CLR_SHIFT              15                            /**< Shift for IRQUARTRxParityErrorEnClr */
#define  IRQ_UART_RX_PARITY_ERROR_EN_CLR_MASK               0x00008000u                   /**< Mask for IRQUARTRxParityErrorEnClr */
#define  IRQ_UART_RX_PARITY_ERROR_EN_CLR_BMASK              0x1u                          /**< Base mask for IRQUARTRxParityErrorEnClr */
#define  IRQ_UART_RX_PARITY_ERROR_EN_CLR(x)                 (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorEnClr in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_EN_CLR(reg)           (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorEnClr from register */
/** @} */


/**
 * @name RegIRQUARTMsk
 * @{
 */
// RegIRQUARTMsk.r32
#define  REG_IRQ_UART_MSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQUARTMsk */
#define  REG_IRQ_UART_MSK_MASK                              0x0000FD2Bu                   /**< Mask for RegIRQUARTMsk */

#define  IRQ_UART_TX_MSK_SHIFT                              0                             /**< Shift for IRQUARTTxMsk */
#define  IRQ_UART_TX_MSK_MASK                               0x00000001u                   /**< Mask for IRQUARTTxMsk */
#define  IRQ_UART_TX_MSK_BMASK                              0x1u                          /**< Base mask for IRQUARTTxMsk */
#define  IRQ_UART_TX_MSK(x)                                 (((x)&0x1u)<<0)               /**< Set IRQUARTTxMsk in register */
#define  GET_IRQ_UART_TX_MSK(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQUARTTxMsk from register */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_SHIFT                   1                             /**< Shift for IRQUARTTxFIFOEmptyMsk */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_MASK                    0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyMsk */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_BMASK                   0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyMsk */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK(x)                      (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyMsk in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_MSK(reg)                (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyMsk from register */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_SHIFT                   3                             /**< Shift for IRQUARTTxFIFOLimitMsk */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_MASK                    0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitMsk */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_BMASK                   0x1u                          /**< Base mask for IRQUARTTxFIFOLimitMsk */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK(x)                      (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitMsk in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_MSK(reg)                (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitMsk from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_SHIFT                5                             /**< Shift for IRQUARTTxFIFOOverflowMsk */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_MASK                 0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowMsk */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowMsk */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK(x)                   (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowMsk in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_MSK(reg)             (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowMsk from register */
#define  IRQ_UART_RX_MSK_SHIFT                              8                             /**< Shift for IRQUARTRxMsk */
#define  IRQ_UART_RX_MSK_MASK                               0x00000100u                   /**< Mask for IRQUARTRxMsk */
#define  IRQ_UART_RX_MSK_BMASK                              0x1u                          /**< Base mask for IRQUARTRxMsk */
#define  IRQ_UART_RX_MSK(x)                                 (((x)&0x1u)<<8)               /**< Set IRQUARTRxMsk in register */
#define  GET_IRQ_UART_RX_MSK(reg)                           (((reg)>>8)&0x1u)             /**< Get IRQUARTRxMsk from register */
#define  IRQ_UART_RX_FIFO_FULL_MSK_SHIFT                    10                            /**< Shift for IRQUARTRxFIFOFullMsk */
#define  IRQ_UART_RX_FIFO_FULL_MSK_MASK                     0x00000400u                   /**< Mask for IRQUARTRxFIFOFullMsk */
#define  IRQ_UART_RX_FIFO_FULL_MSK_BMASK                    0x1u                          /**< Base mask for IRQUARTRxFIFOFullMsk */
#define  IRQ_UART_RX_FIFO_FULL_MSK(x)                       (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullMsk in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_MSK(reg)                 (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullMsk from register */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_SHIFT                   11                            /**< Shift for IRQUARTRxFIFOLimitMsk */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_MASK                    0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitMsk */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_BMASK                   0x1u                          /**< Base mask for IRQUARTRxFIFOLimitMsk */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK(x)                      (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitMsk in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_MSK(reg)                (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitMsk from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SHIFT               12                            /**< Shift for IRQUARTRxFIFOUnderflowMsk */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_MASK                0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowMsk */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowMsk */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK(x)                  (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowMsk in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_MSK(reg)            (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowMsk from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_SHIFT                13                            /**< Shift for IRQUARTRxFIFOOverflowMsk */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_MASK                 0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowMsk */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowMsk */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK(x)                   (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowMsk in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_MSK(reg)             (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowMsk from register */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_SHIFT                  14                            /**< Shift for IRQUARTRxFrameErrorMsk */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_MASK                   0x00004000u                   /**< Mask for IRQUARTRxFrameErrorMsk */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_BMASK                  0x1u                          /**< Base mask for IRQUARTRxFrameErrorMsk */
#define  IRQ_UART_RX_FRAME_ERROR_MSK(x)                     (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorMsk in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_MSK(reg)               (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorMsk from register */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_SHIFT                 15                            /**< Shift for IRQUARTRxParityErrorMsk */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_MASK                  0x00008000u                   /**< Mask for IRQUARTRxParityErrorMsk */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_BMASK                 0x1u                          /**< Base mask for IRQUARTRxParityErrorMsk */
#define  IRQ_UART_RX_PARITY_ERROR_MSK(x)                    (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorMsk in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_MSK(reg)              (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorMsk from register */
/** @} */


/**
 * @name RegIRQUARTMskSet
 * @{
 */
// RegIRQUARTMskSet.r32
#define  REG_IRQ_UART_MSK_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQUARTMskSet */
#define  REG_IRQ_UART_MSK_SET_MASK                          0x0000FD2Bu                   /**< Mask for RegIRQUARTMskSet */

#define  IRQ_UART_TX_MSK_SET_SHIFT                          0                             /**< Shift for IRQUARTTxMskSet */
#define  IRQ_UART_TX_MSK_SET_MASK                           0x00000001u                   /**< Mask for IRQUARTTxMskSet */
#define  IRQ_UART_TX_MSK_SET_BMASK                          0x1u                          /**< Base mask for IRQUARTTxMskSet */
#define  IRQ_UART_TX_MSK_SET(x)                             (((x)&0x1u)<<0)               /**< Set IRQUARTTxMskSet in register */
#define  GET_IRQ_UART_TX_MSK_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQUARTTxMskSet from register */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_SET_SHIFT               1                             /**< Shift for IRQUARTTxFIFOEmptyMskSet */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_SET_MASK                0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyMskSet */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyMskSet */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyMskSet in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_MSK_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyMskSet from register */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_SET_SHIFT               3                             /**< Shift for IRQUARTTxFIFOLimitMskSet */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_SET_MASK                0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitMskSet */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOLimitMskSet */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitMskSet in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_MSK_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitMskSet from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_SET_SHIFT            5                             /**< Shift for IRQUARTTxFIFOOverflowMskSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_SET_MASK             0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowMskSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowMskSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_SET(x)               (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowMskSet in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_MSK_SET(reg)         (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowMskSet from register */
#define  IRQ_UART_RX_MSK_SET_SHIFT                          8                             /**< Shift for IRQUARTRxMskSet */
#define  IRQ_UART_RX_MSK_SET_MASK                           0x00000100u                   /**< Mask for IRQUARTRxMskSet */
#define  IRQ_UART_RX_MSK_SET_BMASK                          0x1u                          /**< Base mask for IRQUARTRxMskSet */
#define  IRQ_UART_RX_MSK_SET(x)                             (((x)&0x1u)<<8)               /**< Set IRQUARTRxMskSet in register */
#define  GET_IRQ_UART_RX_MSK_SET(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQUARTRxMskSet from register */
#define  IRQ_UART_RX_FIFO_FULL_MSK_SET_SHIFT                10                            /**< Shift for IRQUARTRxFIFOFullMskSet */
#define  IRQ_UART_RX_FIFO_FULL_MSK_SET_MASK                 0x00000400u                   /**< Mask for IRQUARTRxFIFOFullMskSet */
#define  IRQ_UART_RX_FIFO_FULL_MSK_SET_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOFullMskSet */
#define  IRQ_UART_RX_FIFO_FULL_MSK_SET(x)                   (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullMskSet in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_MSK_SET(reg)             (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullMskSet from register */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_SET_SHIFT               11                            /**< Shift for IRQUARTRxFIFOLimitMskSet */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_SET_MASK                0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitMskSet */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOLimitMskSet */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_SET(x)                  (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitMskSet in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_MSK_SET(reg)            (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitMskSet from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SET_SHIFT           12                            /**< Shift for IRQUARTRxFIFOUnderflowMskSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SET_MASK            0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowMskSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SET_BMASK           0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowMskSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SET(x)              (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowMskSet in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_MSK_SET(reg)        (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowMskSet from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_SET_SHIFT            13                            /**< Shift for IRQUARTRxFIFOOverflowMskSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_SET_MASK             0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowMskSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowMskSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_SET(x)               (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowMskSet in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_MSK_SET(reg)         (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowMskSet from register */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_SET_SHIFT              14                            /**< Shift for IRQUARTRxFrameErrorMskSet */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_SET_MASK               0x00004000u                   /**< Mask for IRQUARTRxFrameErrorMskSet */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_SET_BMASK              0x1u                          /**< Base mask for IRQUARTRxFrameErrorMskSet */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_SET(x)                 (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorMskSet in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_MSK_SET(reg)           (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorMskSet from register */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_SET_SHIFT             15                            /**< Shift for IRQUARTRxParityErrorMskSet */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_SET_MASK              0x00008000u                   /**< Mask for IRQUARTRxParityErrorMskSet */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_SET_BMASK             0x1u                          /**< Base mask for IRQUARTRxParityErrorMskSet */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_SET(x)                (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorMskSet in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_MSK_SET(reg)          (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorMskSet from register */
/** @} */


/**
 * @name RegIRQUARTMskClr
 * @{
 */
// RegIRQUARTMskClr.r32
#define  REG_IRQ_UART_MSK_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQUARTMskClr */
#define  REG_IRQ_UART_MSK_CLR_MASK                          0x0000FD2Bu                   /**< Mask for RegIRQUARTMskClr */

#define  IRQ_UART_TX_MSK_CLR_SHIFT                          0                             /**< Shift for IRQUARTTxMskClr */
#define  IRQ_UART_TX_MSK_CLR_MASK                           0x00000001u                   /**< Mask for IRQUARTTxMskClr */
#define  IRQ_UART_TX_MSK_CLR_BMASK                          0x1u                          /**< Base mask for IRQUARTTxMskClr */
#define  IRQ_UART_TX_MSK_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IRQUARTTxMskClr in register */
#define  GET_IRQ_UART_TX_MSK_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQUARTTxMskClr from register */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_CLR_SHIFT               1                             /**< Shift for IRQUARTTxFIFOEmptyMskClr */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_CLR_MASK                0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyMskClr */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyMskClr */
#define  IRQ_UART_TX_FIFO_EMPTY_MSK_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyMskClr in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_MSK_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyMskClr from register */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_CLR_SHIFT               3                             /**< Shift for IRQUARTTxFIFOLimitMskClr */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_CLR_MASK                0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitMskClr */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOLimitMskClr */
#define  IRQ_UART_TX_FIFO_LIMIT_MSK_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitMskClr in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_MSK_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitMskClr from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_CLR_SHIFT            5                             /**< Shift for IRQUARTTxFIFOOverflowMskClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_CLR_MASK             0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowMskClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowMskClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_MSK_CLR(x)               (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowMskClr in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_MSK_CLR(reg)         (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowMskClr from register */
#define  IRQ_UART_RX_MSK_CLR_SHIFT                          8                             /**< Shift for IRQUARTRxMskClr */
#define  IRQ_UART_RX_MSK_CLR_MASK                           0x00000100u                   /**< Mask for IRQUARTRxMskClr */
#define  IRQ_UART_RX_MSK_CLR_BMASK                          0x1u                          /**< Base mask for IRQUARTRxMskClr */
#define  IRQ_UART_RX_MSK_CLR(x)                             (((x)&0x1u)<<8)               /**< Set IRQUARTRxMskClr in register */
#define  GET_IRQ_UART_RX_MSK_CLR(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQUARTRxMskClr from register */
#define  IRQ_UART_RX_FIFO_FULL_MSK_CLR_SHIFT                10                            /**< Shift for IRQUARTRxFIFOFullMskClr */
#define  IRQ_UART_RX_FIFO_FULL_MSK_CLR_MASK                 0x00000400u                   /**< Mask for IRQUARTRxFIFOFullMskClr */
#define  IRQ_UART_RX_FIFO_FULL_MSK_CLR_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOFullMskClr */
#define  IRQ_UART_RX_FIFO_FULL_MSK_CLR(x)                   (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullMskClr in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_MSK_CLR(reg)             (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullMskClr from register */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_CLR_SHIFT               11                            /**< Shift for IRQUARTRxFIFOLimitMskClr */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_CLR_MASK                0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitMskClr */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOLimitMskClr */
#define  IRQ_UART_RX_FIFO_LIMIT_MSK_CLR(x)                  (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitMskClr in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_MSK_CLR(reg)            (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitMskClr from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_CLR_SHIFT           12                            /**< Shift for IRQUARTRxFIFOUnderflowMskClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_CLR_MASK            0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowMskClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_CLR_BMASK           0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowMskClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_MSK_CLR(x)              (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowMskClr in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_MSK_CLR(reg)        (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowMskClr from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_CLR_SHIFT            13                            /**< Shift for IRQUARTRxFIFOOverflowMskClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_CLR_MASK             0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowMskClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowMskClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_MSK_CLR(x)               (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowMskClr in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_MSK_CLR(reg)         (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowMskClr from register */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_CLR_SHIFT              14                            /**< Shift for IRQUARTRxFrameErrorMskClr */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_CLR_MASK               0x00004000u                   /**< Mask for IRQUARTRxFrameErrorMskClr */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_CLR_BMASK              0x1u                          /**< Base mask for IRQUARTRxFrameErrorMskClr */
#define  IRQ_UART_RX_FRAME_ERROR_MSK_CLR(x)                 (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorMskClr in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_MSK_CLR(reg)           (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorMskClr from register */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_CLR_SHIFT             15                            /**< Shift for IRQUARTRxParityErrorMskClr */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_CLR_MASK              0x00008000u                   /**< Mask for IRQUARTRxParityErrorMskClr */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_CLR_BMASK             0x1u                          /**< Base mask for IRQUARTRxParityErrorMskClr */
#define  IRQ_UART_RX_PARITY_ERROR_MSK_CLR(x)                (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorMskClr in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_MSK_CLR(reg)          (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorMskClr from register */
/** @} */


/**
 * @name RegIRQUARTSts
 * @{
 */
// RegIRQUARTSts.r32
#define  REG_IRQ_UART_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQUARTSts */
#define  REG_IRQ_UART_STS_MASK                              0x0000FD2Bu                   /**< Mask for RegIRQUARTSts */

#define  IRQ_UART_TX_STS_SHIFT                              0                             /**< Shift for IRQUARTTxSts */
#define  IRQ_UART_TX_STS_MASK                               0x00000001u                   /**< Mask for IRQUARTTxSts */
#define  IRQ_UART_TX_STS_BMASK                              0x1u                          /**< Base mask for IRQUARTTxSts */
#define  IRQ_UART_TX_STS(x)                                 (((x)&0x1u)<<0)               /**< Set IRQUARTTxSts in register */
#define  GET_IRQ_UART_TX_STS(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQUARTTxSts from register */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_SHIFT                   1                             /**< Shift for IRQUARTTxFIFOEmptySts */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_MASK                    0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptySts */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_BMASK                   0x1u                          /**< Base mask for IRQUARTTxFIFOEmptySts */
#define  IRQ_UART_TX_FIFO_EMPTY_STS(x)                      (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptySts in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_STS(reg)                (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptySts from register */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_SHIFT                   3                             /**< Shift for IRQUARTTxFIFOLimitSts */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_MASK                    0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitSts */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_BMASK                   0x1u                          /**< Base mask for IRQUARTTxFIFOLimitSts */
#define  IRQ_UART_TX_FIFO_LIMIT_STS(x)                      (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitSts in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_STS(reg)                (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitSts from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_SHIFT                5                             /**< Shift for IRQUARTTxFIFOOverflowSts */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_MASK                 0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowSts */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_BMASK                0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowSts */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS(x)                   (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowSts in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_STS(reg)             (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowSts from register */
#define  IRQ_UART_RX_STS_SHIFT                              8                             /**< Shift for IRQUARTRxSts */
#define  IRQ_UART_RX_STS_MASK                               0x00000100u                   /**< Mask for IRQUARTRxSts */
#define  IRQ_UART_RX_STS_BMASK                              0x1u                          /**< Base mask for IRQUARTRxSts */
#define  IRQ_UART_RX_STS(x)                                 (((x)&0x1u)<<8)               /**< Set IRQUARTRxSts in register */
#define  GET_IRQ_UART_RX_STS(reg)                           (((reg)>>8)&0x1u)             /**< Get IRQUARTRxSts from register */
#define  IRQ_UART_RX_FIFO_FULL_STS_SHIFT                    10                            /**< Shift for IRQUARTRxFIFOFullSts */
#define  IRQ_UART_RX_FIFO_FULL_STS_MASK                     0x00000400u                   /**< Mask for IRQUARTRxFIFOFullSts */
#define  IRQ_UART_RX_FIFO_FULL_STS_BMASK                    0x1u                          /**< Base mask for IRQUARTRxFIFOFullSts */
#define  IRQ_UART_RX_FIFO_FULL_STS(x)                       (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullSts in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_STS(reg)                 (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullSts from register */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_SHIFT                   11                            /**< Shift for IRQUARTRxFIFOLimitSts */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_MASK                    0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitSts */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_BMASK                   0x1u                          /**< Base mask for IRQUARTRxFIFOLimitSts */
#define  IRQ_UART_RX_FIFO_LIMIT_STS(x)                      (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitSts in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_STS(reg)                (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitSts from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_SHIFT               12                            /**< Shift for IRQUARTRxFIFOUnderflowSts */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_MASK                0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowSts */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowSts */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS(x)                  (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowSts in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_STS(reg)            (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowSts from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_SHIFT                13                            /**< Shift for IRQUARTRxFIFOOverflowSts */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_MASK                 0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowSts */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowSts */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS(x)                   (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowSts in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_STS(reg)             (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowSts from register */
#define  IRQ_UART_RX_FRAME_ERROR_STS_SHIFT                  14                            /**< Shift for IRQUARTRxFrameErrorSts */
#define  IRQ_UART_RX_FRAME_ERROR_STS_MASK                   0x00004000u                   /**< Mask for IRQUARTRxFrameErrorSts */
#define  IRQ_UART_RX_FRAME_ERROR_STS_BMASK                  0x1u                          /**< Base mask for IRQUARTRxFrameErrorSts */
#define  IRQ_UART_RX_FRAME_ERROR_STS(x)                     (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorSts in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_STS(reg)               (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorSts from register */
#define  IRQ_UART_RX_PARITY_ERROR_STS_SHIFT                 15                            /**< Shift for IRQUARTRxParityErrorSts */
#define  IRQ_UART_RX_PARITY_ERROR_STS_MASK                  0x00008000u                   /**< Mask for IRQUARTRxParityErrorSts */
#define  IRQ_UART_RX_PARITY_ERROR_STS_BMASK                 0x1u                          /**< Base mask for IRQUARTRxParityErrorSts */
#define  IRQ_UART_RX_PARITY_ERROR_STS(x)                    (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorSts in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_STS(reg)              (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorSts from register */
/** @} */


/**
 * @name RegIRQUARTStsSet
 * @{
 */
// RegIRQUARTStsSet.r32
#define  REG_IRQ_UART_STS_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQUARTStsSet */
#define  REG_IRQ_UART_STS_SET_MASK                          0x0000FD2Bu                   /**< Mask for RegIRQUARTStsSet */

#define  IRQ_UART_TX_STS_SET_SHIFT                          0                             /**< Shift for IRQUARTTxStsSet */
#define  IRQ_UART_TX_STS_SET_MASK                           0x00000001u                   /**< Mask for IRQUARTTxStsSet */
#define  IRQ_UART_TX_STS_SET_BMASK                          0x1u                          /**< Base mask for IRQUARTTxStsSet */
#define  IRQ_UART_TX_STS_SET(x)                             (((x)&0x1u)<<0)               /**< Set IRQUARTTxStsSet in register */
#define  GET_IRQ_UART_TX_STS_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQUARTTxStsSet from register */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_SET_SHIFT               1                             /**< Shift for IRQUARTTxFIFOEmptyStsSet */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_SET_MASK                0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyStsSet */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_SET_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyStsSet */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyStsSet in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_STS_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyStsSet from register */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_SET_SHIFT               3                             /**< Shift for IRQUARTTxFIFOLimitStsSet */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_SET_MASK                0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitStsSet */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_SET_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOLimitStsSet */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitStsSet in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_STS_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitStsSet from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_SET_SHIFT            5                             /**< Shift for IRQUARTTxFIFOOverflowStsSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_SET_MASK             0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowStsSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowStsSet */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_SET(x)               (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowStsSet in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_STS_SET(reg)         (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowStsSet from register */
#define  IRQ_UART_RX_STS_SET_SHIFT                          8                             /**< Shift for IRQUARTRxStsSet */
#define  IRQ_UART_RX_STS_SET_MASK                           0x00000100u                   /**< Mask for IRQUARTRxStsSet */
#define  IRQ_UART_RX_STS_SET_BMASK                          0x1u                          /**< Base mask for IRQUARTRxStsSet */
#define  IRQ_UART_RX_STS_SET(x)                             (((x)&0x1u)<<8)               /**< Set IRQUARTRxStsSet in register */
#define  GET_IRQ_UART_RX_STS_SET(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQUARTRxStsSet from register */
#define  IRQ_UART_RX_FIFO_FULL_STS_SET_SHIFT                10                            /**< Shift for IRQUARTRxFIFOFullStsSet */
#define  IRQ_UART_RX_FIFO_FULL_STS_SET_MASK                 0x00000400u                   /**< Mask for IRQUARTRxFIFOFullStsSet */
#define  IRQ_UART_RX_FIFO_FULL_STS_SET_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOFullStsSet */
#define  IRQ_UART_RX_FIFO_FULL_STS_SET(x)                   (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullStsSet in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_STS_SET(reg)             (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullStsSet from register */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_SET_SHIFT               11                            /**< Shift for IRQUARTRxFIFOLimitStsSet */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_SET_MASK                0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitStsSet */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_SET_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOLimitStsSet */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_SET(x)                  (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitStsSet in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_STS_SET(reg)            (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitStsSet from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_SET_SHIFT           12                            /**< Shift for IRQUARTRxFIFOUnderflowStsSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_SET_MASK            0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowStsSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_SET_BMASK           0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowStsSet */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_SET(x)              (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowStsSet in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_STS_SET(reg)        (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowStsSet from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_SET_SHIFT            13                            /**< Shift for IRQUARTRxFIFOOverflowStsSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_SET_MASK             0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowStsSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowStsSet */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_SET(x)               (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowStsSet in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_STS_SET(reg)         (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowStsSet from register */
#define  IRQ_UART_RX_FRAME_ERROR_STS_SET_SHIFT              14                            /**< Shift for IRQUARTRxFrameErrorStsSet */
#define  IRQ_UART_RX_FRAME_ERROR_STS_SET_MASK               0x00004000u                   /**< Mask for IRQUARTRxFrameErrorStsSet */
#define  IRQ_UART_RX_FRAME_ERROR_STS_SET_BMASK              0x1u                          /**< Base mask for IRQUARTRxFrameErrorStsSet */
#define  IRQ_UART_RX_FRAME_ERROR_STS_SET(x)                 (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorStsSet in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_STS_SET(reg)           (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorStsSet from register */
#define  IRQ_UART_RX_PARITY_ERROR_STS_SET_SHIFT             15                            /**< Shift for IRQUARTRxParityErrorStsSet */
#define  IRQ_UART_RX_PARITY_ERROR_STS_SET_MASK              0x00008000u                   /**< Mask for IRQUARTRxParityErrorStsSet */
#define  IRQ_UART_RX_PARITY_ERROR_STS_SET_BMASK             0x1u                          /**< Base mask for IRQUARTRxParityErrorStsSet */
#define  IRQ_UART_RX_PARITY_ERROR_STS_SET(x)                (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorStsSet in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_STS_SET(reg)          (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorStsSet from register */
/** @} */


/**
 * @name RegIRQUARTStsClr
 * @{
 */
// RegIRQUARTStsClr.r32
#define  REG_IRQ_UART_STS_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQUARTStsClr */
#define  REG_IRQ_UART_STS_CLR_MASK                          0x0000FD2Bu                   /**< Mask for RegIRQUARTStsClr */

#define  IRQ_UART_TX_STS_CLR_SHIFT                          0                             /**< Shift for IRQUARTTxStsClr */
#define  IRQ_UART_TX_STS_CLR_MASK                           0x00000001u                   /**< Mask for IRQUARTTxStsClr */
#define  IRQ_UART_TX_STS_CLR_BMASK                          0x1u                          /**< Base mask for IRQUARTTxStsClr */
#define  IRQ_UART_TX_STS_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IRQUARTTxStsClr in register */
#define  GET_IRQ_UART_TX_STS_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQUARTTxStsClr from register */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_CLR_SHIFT               1                             /**< Shift for IRQUARTTxFIFOEmptyStsClr */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_CLR_MASK                0x00000002u                   /**< Mask for IRQUARTTxFIFOEmptyStsClr */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOEmptyStsClr */
#define  IRQ_UART_TX_FIFO_EMPTY_STS_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQUARTTxFIFOEmptyStsClr in register */
#define  GET_IRQ_UART_TX_FIFO_EMPTY_STS_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQUARTTxFIFOEmptyStsClr from register */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_CLR_SHIFT               3                             /**< Shift for IRQUARTTxFIFOLimitStsClr */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_CLR_MASK                0x00000008u                   /**< Mask for IRQUARTTxFIFOLimitStsClr */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTTxFIFOLimitStsClr */
#define  IRQ_UART_TX_FIFO_LIMIT_STS_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQUARTTxFIFOLimitStsClr in register */
#define  GET_IRQ_UART_TX_FIFO_LIMIT_STS_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQUARTTxFIFOLimitStsClr from register */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_CLR_SHIFT            5                             /**< Shift for IRQUARTTxFIFOOverflowStsClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_CLR_MASK             0x00000020u                   /**< Mask for IRQUARTTxFIFOOverflowStsClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IRQUARTTxFIFOOverflowStsClr */
#define  IRQ_UART_TX_FIFO_OVERFLOW_STS_CLR(x)               (((x)&0x1u)<<5)               /**< Set IRQUARTTxFIFOOverflowStsClr in register */
#define  GET_IRQ_UART_TX_FIFO_OVERFLOW_STS_CLR(reg)         (((reg)>>5)&0x1u)             /**< Get IRQUARTTxFIFOOverflowStsClr from register */
#define  IRQ_UART_RX_STS_CLR_SHIFT                          8                             /**< Shift for IRQUARTRxStsClr */
#define  IRQ_UART_RX_STS_CLR_MASK                           0x00000100u                   /**< Mask for IRQUARTRxStsClr */
#define  IRQ_UART_RX_STS_CLR_BMASK                          0x1u                          /**< Base mask for IRQUARTRxStsClr */
#define  IRQ_UART_RX_STS_CLR(x)                             (((x)&0x1u)<<8)               /**< Set IRQUARTRxStsClr in register */
#define  GET_IRQ_UART_RX_STS_CLR(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQUARTRxStsClr from register */
#define  IRQ_UART_RX_FIFO_FULL_STS_CLR_SHIFT                10                            /**< Shift for IRQUARTRxFIFOFullStsClr */
#define  IRQ_UART_RX_FIFO_FULL_STS_CLR_MASK                 0x00000400u                   /**< Mask for IRQUARTRxFIFOFullStsClr */
#define  IRQ_UART_RX_FIFO_FULL_STS_CLR_BMASK                0x1u                          /**< Base mask for IRQUARTRxFIFOFullStsClr */
#define  IRQ_UART_RX_FIFO_FULL_STS_CLR(x)                   (((x)&0x1u)<<10)              /**< Set IRQUARTRxFIFOFullStsClr in register */
#define  GET_IRQ_UART_RX_FIFO_FULL_STS_CLR(reg)             (((reg)>>10)&0x1u)            /**< Get IRQUARTRxFIFOFullStsClr from register */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_CLR_SHIFT               11                            /**< Shift for IRQUARTRxFIFOLimitStsClr */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_CLR_MASK                0x00000800u                   /**< Mask for IRQUARTRxFIFOLimitStsClr */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQUARTRxFIFOLimitStsClr */
#define  IRQ_UART_RX_FIFO_LIMIT_STS_CLR(x)                  (((x)&0x1u)<<11)              /**< Set IRQUARTRxFIFOLimitStsClr in register */
#define  GET_IRQ_UART_RX_FIFO_LIMIT_STS_CLR(reg)            (((reg)>>11)&0x1u)            /**< Get IRQUARTRxFIFOLimitStsClr from register */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_CLR_SHIFT           12                            /**< Shift for IRQUARTRxFIFOUnderflowStsClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_CLR_MASK            0x00001000u                   /**< Mask for IRQUARTRxFIFOUnderflowStsClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_CLR_BMASK           0x1u                          /**< Base mask for IRQUARTRxFIFOUnderflowStsClr */
#define  IRQ_UART_RX_FIFO_UNDERFLOW_STS_CLR(x)              (((x)&0x1u)<<12)              /**< Set IRQUARTRxFIFOUnderflowStsClr in register */
#define  GET_IRQ_UART_RX_FIFO_UNDERFLOW_STS_CLR(reg)        (((reg)>>12)&0x1u)            /**< Get IRQUARTRxFIFOUnderflowStsClr from register */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_CLR_SHIFT            13                            /**< Shift for IRQUARTRxFIFOOverflowStsClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_CLR_MASK             0x00002000u                   /**< Mask for IRQUARTRxFIFOOverflowStsClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IRQUARTRxFIFOOverflowStsClr */
#define  IRQ_UART_RX_FIFO_OVERFLOW_STS_CLR(x)               (((x)&0x1u)<<13)              /**< Set IRQUARTRxFIFOOverflowStsClr in register */
#define  GET_IRQ_UART_RX_FIFO_OVERFLOW_STS_CLR(reg)         (((reg)>>13)&0x1u)            /**< Get IRQUARTRxFIFOOverflowStsClr from register */
#define  IRQ_UART_RX_FRAME_ERROR_STS_CLR_SHIFT              14                            /**< Shift for IRQUARTRxFrameErrorStsClr */
#define  IRQ_UART_RX_FRAME_ERROR_STS_CLR_MASK               0x00004000u                   /**< Mask for IRQUARTRxFrameErrorStsClr */
#define  IRQ_UART_RX_FRAME_ERROR_STS_CLR_BMASK              0x1u                          /**< Base mask for IRQUARTRxFrameErrorStsClr */
#define  IRQ_UART_RX_FRAME_ERROR_STS_CLR(x)                 (((x)&0x1u)<<14)              /**< Set IRQUARTRxFrameErrorStsClr in register */
#define  GET_IRQ_UART_RX_FRAME_ERROR_STS_CLR(reg)           (((reg)>>14)&0x1u)            /**< Get IRQUARTRxFrameErrorStsClr from register */
#define  IRQ_UART_RX_PARITY_ERROR_STS_CLR_SHIFT             15                            /**< Shift for IRQUARTRxParityErrorStsClr */
#define  IRQ_UART_RX_PARITY_ERROR_STS_CLR_MASK              0x00008000u                   /**< Mask for IRQUARTRxParityErrorStsClr */
#define  IRQ_UART_RX_PARITY_ERROR_STS_CLR_BMASK             0x1u                          /**< Base mask for IRQUARTRxParityErrorStsClr */
#define  IRQ_UART_RX_PARITY_ERROR_STS_CLR(x)                (((x)&0x1u)<<15)              /**< Set IRQUARTRxParityErrorStsClr in register */
#define  GET_IRQ_UART_RX_PARITY_ERROR_STS_CLR(reg)          (((reg)>>15)&0x1u)            /**< Get IRQUARTRxParityErrorStsClr from register */
/** @} */


/**
 * @name RegIRQGPIOEn
 * @{
 */
// RegIRQGPIOEn.r32
#define  REG_IRQ_GPIO_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQGPIOEn */
#define  REG_IRQ_GPIO_EN_MASK                               0x00000FFFu                   /**< Mask for RegIRQGPIOEn */

#define  IRQ_GPIO_EN_SHIFT                                  0                             /**< Shift for IRQGPIOEn */
#define  IRQ_GPIO_EN_MASK                                   0x00000FFFu                   /**< Mask for IRQGPIOEn */
#define  IRQ_GPIO_EN_BMASK                                  0xFFFu                        /**< Base mask for IRQGPIOEn */
#define  IRQ_GPIO_EN(x)                                     (((x)&0xFFFu)<<0)             /**< Set IRQGPIOEn in register */
#define  GET_IRQ_GPIO_EN(reg)                               (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOEn from register */
/** @} */


/**
 * @name RegIRQGPIOEnSet
 * @{
 */
// RegIRQGPIOEnSet.r32
#define  REG_IRQ_GPIO_EN_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQGPIOEnSet */
#define  REG_IRQ_GPIO_EN_SET_MASK                           0x00000FFFu                   /**< Mask for RegIRQGPIOEnSet */

#define  IRQ_GPIO_EN_SET_SHIFT                              0                             /**< Shift for IRQGPIOEnSet */
#define  IRQ_GPIO_EN_SET_MASK                               0x00000FFFu                   /**< Mask for IRQGPIOEnSet */
#define  IRQ_GPIO_EN_SET_BMASK                              0xFFFu                        /**< Base mask for IRQGPIOEnSet */
#define  IRQ_GPIO_EN_SET(x)                                 (((x)&0xFFFu)<<0)             /**< Set IRQGPIOEnSet in register */
#define  GET_IRQ_GPIO_EN_SET(reg)                           (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOEnSet from register */
/** @} */


/**
 * @name RegIRQGPIOEnClr
 * @{
 */
// RegIRQGPIOEnClr.r32
#define  REG_IRQ_GPIO_EN_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQGPIOEnClr */
#define  REG_IRQ_GPIO_EN_CLR_MASK                           0x00000FFFu                   /**< Mask for RegIRQGPIOEnClr */

#define  IRQ_GPIO_EN_CLR_SHIFT                              0                             /**< Shift for IRQGPIOEnClr */
#define  IRQ_GPIO_EN_CLR_MASK                               0x00000FFFu                   /**< Mask for IRQGPIOEnClr */
#define  IRQ_GPIO_EN_CLR_BMASK                              0xFFFu                        /**< Base mask for IRQGPIOEnClr */
#define  IRQ_GPIO_EN_CLR(x)                                 (((x)&0xFFFu)<<0)             /**< Set IRQGPIOEnClr in register */
#define  GET_IRQ_GPIO_EN_CLR(reg)                           (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOEnClr from register */
/** @} */


/**
 * @name RegIRQGPIOMsk
 * @{
 */
// RegIRQGPIOMsk.r32
#define  REG_IRQ_GPIO_MSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQGPIOMsk */
#define  REG_IRQ_GPIO_MSK_MASK                              0x00000FFFu                   /**< Mask for RegIRQGPIOMsk */

#define  IRQ_GPIO_MSK_SHIFT                                 0                             /**< Shift for IRQGPIOMsk */
#define  IRQ_GPIO_MSK_MASK                                  0x00000FFFu                   /**< Mask for IRQGPIOMsk */
#define  IRQ_GPIO_MSK_BMASK                                 0xFFFu                        /**< Base mask for IRQGPIOMsk */
#define  IRQ_GPIO_MSK(x)                                    (((x)&0xFFFu)<<0)             /**< Set IRQGPIOMsk in register */
#define  GET_IRQ_GPIO_MSK(reg)                              (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOMsk from register */
/** @} */


/**
 * @name RegIRQGPIOMskSet
 * @{
 */
// RegIRQGPIOMskSet.r32
#define  REG_IRQ_GPIO_MSK_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQGPIOMskSet */
#define  REG_IRQ_GPIO_MSK_SET_MASK                          0x00000FFFu                   /**< Mask for RegIRQGPIOMskSet */

#define  IRQ_GPIO_MSK_SET_SHIFT                             0                             /**< Shift for IRQGPIOMskSet */
#define  IRQ_GPIO_MSK_SET_MASK                              0x00000FFFu                   /**< Mask for IRQGPIOMskSet */
#define  IRQ_GPIO_MSK_SET_BMASK                             0xFFFu                        /**< Base mask for IRQGPIOMskSet */
#define  IRQ_GPIO_MSK_SET(x)                                (((x)&0xFFFu)<<0)             /**< Set IRQGPIOMskSet in register */
#define  GET_IRQ_GPIO_MSK_SET(reg)                          (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOMskSet from register */
/** @} */


/**
 * @name RegIRQGPIOMskClr
 * @{
 */
// RegIRQGPIOMskClr.r32
#define  REG_IRQ_GPIO_MSK_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQGPIOMskClr */
#define  REG_IRQ_GPIO_MSK_CLR_MASK                          0x00000FFFu                   /**< Mask for RegIRQGPIOMskClr */

#define  IRQ_GPIO_MSK_CLR_SHIFT                             0                             /**< Shift for IRQGPIOMskClr */
#define  IRQ_GPIO_MSK_CLR_MASK                              0x00000FFFu                   /**< Mask for IRQGPIOMskClr */
#define  IRQ_GPIO_MSK_CLR_BMASK                             0xFFFu                        /**< Base mask for IRQGPIOMskClr */
#define  IRQ_GPIO_MSK_CLR(x)                                (((x)&0xFFFu)<<0)             /**< Set IRQGPIOMskClr in register */
#define  GET_IRQ_GPIO_MSK_CLR(reg)                          (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOMskClr from register */
/** @} */


/**
 * @name RegIRQGPIOSts
 * @{
 */
// RegIRQGPIOSts.r32
#define  REG_IRQ_GPIO_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQGPIOSts */
#define  REG_IRQ_GPIO_STS_MASK                              0x00000FFFu                   /**< Mask for RegIRQGPIOSts */

#define  IRQ_GPIO_STS_SHIFT                                 0                             /**< Shift for IRQGPIOSts */
#define  IRQ_GPIO_STS_MASK                                  0x00000FFFu                   /**< Mask for IRQGPIOSts */
#define  IRQ_GPIO_STS_BMASK                                 0xFFFu                        /**< Base mask for IRQGPIOSts */
#define  IRQ_GPIO_STS(x)                                    (((x)&0xFFFu)<<0)             /**< Set IRQGPIOSts in register */
#define  GET_IRQ_GPIO_STS(reg)                              (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOSts from register */
/** @} */


/**
 * @name RegIRQGPIOStsSet
 * @{
 */
// RegIRQGPIOStsSet.r32
#define  REG_IRQ_GPIO_STS_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQGPIOStsSet */
#define  REG_IRQ_GPIO_STS_SET_MASK                          0x00000FFFu                   /**< Mask for RegIRQGPIOStsSet */

#define  IRQ_GPIO_STS_SET_SHIFT                             0                             /**< Shift for IRQGPIOStsSet */
#define  IRQ_GPIO_STS_SET_MASK                              0x00000FFFu                   /**< Mask for IRQGPIOStsSet */
#define  IRQ_GPIO_STS_SET_BMASK                             0xFFFu                        /**< Base mask for IRQGPIOStsSet */
#define  IRQ_GPIO_STS_SET(x)                                (((x)&0xFFFu)<<0)             /**< Set IRQGPIOStsSet in register */
#define  GET_IRQ_GPIO_STS_SET(reg)                          (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOStsSet from register */
/** @} */


/**
 * @name RegIRQGPIOStsClr
 * @{
 */
// RegIRQGPIOStsClr.r32
#define  REG_IRQ_GPIO_STS_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQGPIOStsClr */
#define  REG_IRQ_GPIO_STS_CLR_MASK                          0x00000FFFu                   /**< Mask for RegIRQGPIOStsClr */

#define  IRQ_GPIO_STS_CLR_SHIFT                             0                             /**< Shift for IRQGPIOStsClr */
#define  IRQ_GPIO_STS_CLR_MASK                              0x00000FFFu                   /**< Mask for IRQGPIOStsClr */
#define  IRQ_GPIO_STS_CLR_BMASK                             0xFFFu                        /**< Base mask for IRQGPIOStsClr */
#define  IRQ_GPIO_STS_CLR(x)                                (((x)&0xFFFu)<<0)             /**< Set IRQGPIOStsClr in register */
#define  GET_IRQ_GPIO_STS_CLR(reg)                          (((reg)>>0)&0xFFFu)           /**< Get IRQGPIOStsClr from register */
/** @} */


/**
 * @name RegIRQUniTimEn
 * @{
 */
// RegIRQUniTimEn.r32
#define  REG_IRQ_UNI_TIM_EN_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQUniTimEn */
#define  REG_IRQ_UNI_TIM_EN_MASK                            0x00003F3Fu                   /**< Mask for RegIRQUniTimEn */

#define  IRQ_UT2_OUT_CMP0_EN_SHIFT                          0                             /**< Shift for IRQUT2OutCmp0En */
#define  IRQ_UT2_OUT_CMP0_EN_MASK                           0x00000001u                   /**< Mask for IRQUT2OutCmp0En */
#define  IRQ_UT2_OUT_CMP0_EN_BMASK                          0x1u                          /**< Base mask for IRQUT2OutCmp0En */
#define  IRQ_UT2_OUT_CMP0_EN(x)                             (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0En in register */
#define  GET_IRQ_UT2_OUT_CMP0_EN(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0En from register */
#define  IRQ_UT2_OUT_CMP1_EN_SHIFT                          1                             /**< Shift for IRQUT2OutCmp1En */
#define  IRQ_UT2_OUT_CMP1_EN_MASK                           0x00000002u                   /**< Mask for IRQUT2OutCmp1En */
#define  IRQ_UT2_OUT_CMP1_EN_BMASK                          0x1u                          /**< Base mask for IRQUT2OutCmp1En */
#define  IRQ_UT2_OUT_CMP1_EN(x)                             (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1En in register */
#define  GET_IRQ_UT2_OUT_CMP1_EN(reg)                       (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1En from register */
#define  IRQ_UT2_OUT_CMP2_EN_SHIFT                          2                             /**< Shift for IRQUT2OutCmp2En */
#define  IRQ_UT2_OUT_CMP2_EN_MASK                           0x00000004u                   /**< Mask for IRQUT2OutCmp2En */
#define  IRQ_UT2_OUT_CMP2_EN_BMASK                          0x1u                          /**< Base mask for IRQUT2OutCmp2En */
#define  IRQ_UT2_OUT_CMP2_EN(x)                             (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2En in register */
#define  GET_IRQ_UT2_OUT_CMP2_EN(reg)                       (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2En from register */
#define  IRQ_UT2_OUT_CMP3_EN_SHIFT                          3                             /**< Shift for IRQUT2OutCmp3En */
#define  IRQ_UT2_OUT_CMP3_EN_MASK                           0x00000008u                   /**< Mask for IRQUT2OutCmp3En */
#define  IRQ_UT2_OUT_CMP3_EN_BMASK                          0x1u                          /**< Base mask for IRQUT2OutCmp3En */
#define  IRQ_UT2_OUT_CMP3_EN(x)                             (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3En in register */
#define  GET_IRQ_UT2_OUT_CMP3_EN(reg)                       (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3En from register */
#define  IRQ_UT2_FULL_VAL_EN_SHIFT                          4                             /**< Shift for IRQUT2FullValEn */
#define  IRQ_UT2_FULL_VAL_EN_MASK                           0x00000010u                   /**< Mask for IRQUT2FullValEn */
#define  IRQ_UT2_FULL_VAL_EN_BMASK                          0x1u                          /**< Base mask for IRQUT2FullValEn */
#define  IRQ_UT2_FULL_VAL_EN(x)                             (((x)&0x1u)<<4)               /**< Set IRQUT2FullValEn in register */
#define  GET_IRQ_UT2_FULL_VAL_EN(reg)                       (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValEn from register */
#define  IRQ_UT2_IN_CPT_EN_SHIFT                            5                             /**< Shift for IRQUT2InCptEn */
#define  IRQ_UT2_IN_CPT_EN_MASK                             0x00000020u                   /**< Mask for IRQUT2InCptEn */
#define  IRQ_UT2_IN_CPT_EN_BMASK                            0x1u                          /**< Base mask for IRQUT2InCptEn */
#define  IRQ_UT2_IN_CPT_EN(x)                               (((x)&0x1u)<<5)               /**< Set IRQUT2InCptEn in register */
#define  GET_IRQ_UT2_IN_CPT_EN(reg)                         (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptEn from register */
#define  IRQ_UT3_OUT_CMP0_EN_SHIFT                          8                             /**< Shift for IRQUT3OutCmp0En */
#define  IRQ_UT3_OUT_CMP0_EN_MASK                           0x00000100u                   /**< Mask for IRQUT3OutCmp0En */
#define  IRQ_UT3_OUT_CMP0_EN_BMASK                          0x1u                          /**< Base mask for IRQUT3OutCmp0En */
#define  IRQ_UT3_OUT_CMP0_EN(x)                             (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0En in register */
#define  GET_IRQ_UT3_OUT_CMP0_EN(reg)                       (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0En from register */
#define  IRQ_UT3_OUT_CMP1_EN_SHIFT                          9                             /**< Shift for IRQUT3OutCmp1En */
#define  IRQ_UT3_OUT_CMP1_EN_MASK                           0x00000200u                   /**< Mask for IRQUT3OutCmp1En */
#define  IRQ_UT3_OUT_CMP1_EN_BMASK                          0x1u                          /**< Base mask for IRQUT3OutCmp1En */
#define  IRQ_UT3_OUT_CMP1_EN(x)                             (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1En in register */
#define  GET_IRQ_UT3_OUT_CMP1_EN(reg)                       (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1En from register */
#define  IRQ_UT3_OUT_CMP2_EN_SHIFT                          10                            /**< Shift for IRQUT3OutCmp2En */
#define  IRQ_UT3_OUT_CMP2_EN_MASK                           0x00000400u                   /**< Mask for IRQUT3OutCmp2En */
#define  IRQ_UT3_OUT_CMP2_EN_BMASK                          0x1u                          /**< Base mask for IRQUT3OutCmp2En */
#define  IRQ_UT3_OUT_CMP2_EN(x)                             (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2En in register */
#define  GET_IRQ_UT3_OUT_CMP2_EN(reg)                       (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2En from register */
#define  IRQ_UT3_OUT_CMP3_EN_SHIFT                          11                            /**< Shift for IRQUT3OutCmp3En */
#define  IRQ_UT3_OUT_CMP3_EN_MASK                           0x00000800u                   /**< Mask for IRQUT3OutCmp3En */
#define  IRQ_UT3_OUT_CMP3_EN_BMASK                          0x1u                          /**< Base mask for IRQUT3OutCmp3En */
#define  IRQ_UT3_OUT_CMP3_EN(x)                             (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3En in register */
#define  GET_IRQ_UT3_OUT_CMP3_EN(reg)                       (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3En from register */
#define  IRQ_UT3_FULL_VAL_EN_SHIFT                          12                            /**< Shift for IRQUT3FullValEn */
#define  IRQ_UT3_FULL_VAL_EN_MASK                           0x00001000u                   /**< Mask for IRQUT3FullValEn */
#define  IRQ_UT3_FULL_VAL_EN_BMASK                          0x1u                          /**< Base mask for IRQUT3FullValEn */
#define  IRQ_UT3_FULL_VAL_EN(x)                             (((x)&0x1u)<<12)              /**< Set IRQUT3FullValEn in register */
#define  GET_IRQ_UT3_FULL_VAL_EN(reg)                       (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValEn from register */
#define  IRQ_UT3_IN_CPT_EN_SHIFT                            13                            /**< Shift for IRQUT3InCptEn */
#define  IRQ_UT3_IN_CPT_EN_MASK                             0x00002000u                   /**< Mask for IRQUT3InCptEn */
#define  IRQ_UT3_IN_CPT_EN_BMASK                            0x1u                          /**< Base mask for IRQUT3InCptEn */
#define  IRQ_UT3_IN_CPT_EN(x)                               (((x)&0x1u)<<13)              /**< Set IRQUT3InCptEn in register */
#define  GET_IRQ_UT3_IN_CPT_EN(reg)                         (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptEn from register */
/** @} */


/**
 * @name RegIRQUniTimEnSet
 * @{
 */
// RegIRQUniTimEnSet.r32
#define  REG_IRQ_UNI_TIM_EN_SET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQUniTimEnSet */
#define  REG_IRQ_UNI_TIM_EN_SET_MASK                        0x00003F3Fu                   /**< Mask for RegIRQUniTimEnSet */

#define  IRQ_UT2_OUT_CMP0_EN_SET_SHIFT                      0                             /**< Shift for IRQUT2OutCmp0EnSet */
#define  IRQ_UT2_OUT_CMP0_EN_SET_MASK                       0x00000001u                   /**< Mask for IRQUT2OutCmp0EnSet */
#define  IRQ_UT2_OUT_CMP0_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp0EnSet */
#define  IRQ_UT2_OUT_CMP0_EN_SET(x)                         (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0EnSet in register */
#define  GET_IRQ_UT2_OUT_CMP0_EN_SET(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0EnSet from register */
#define  IRQ_UT2_OUT_CMP1_EN_SET_SHIFT                      1                             /**< Shift for IRQUT2OutCmp1EnSet */
#define  IRQ_UT2_OUT_CMP1_EN_SET_MASK                       0x00000002u                   /**< Mask for IRQUT2OutCmp1EnSet */
#define  IRQ_UT2_OUT_CMP1_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp1EnSet */
#define  IRQ_UT2_OUT_CMP1_EN_SET(x)                         (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1EnSet in register */
#define  GET_IRQ_UT2_OUT_CMP1_EN_SET(reg)                   (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1EnSet from register */
#define  IRQ_UT2_OUT_CMP2_EN_SET_SHIFT                      2                             /**< Shift for IRQUT2OutCmp2EnSet */
#define  IRQ_UT2_OUT_CMP2_EN_SET_MASK                       0x00000004u                   /**< Mask for IRQUT2OutCmp2EnSet */
#define  IRQ_UT2_OUT_CMP2_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp2EnSet */
#define  IRQ_UT2_OUT_CMP2_EN_SET(x)                         (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2EnSet in register */
#define  GET_IRQ_UT2_OUT_CMP2_EN_SET(reg)                   (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2EnSet from register */
#define  IRQ_UT2_OUT_CMP3_EN_SET_SHIFT                      3                             /**< Shift for IRQUT2OutCmp3EnSet */
#define  IRQ_UT2_OUT_CMP3_EN_SET_MASK                       0x00000008u                   /**< Mask for IRQUT2OutCmp3EnSet */
#define  IRQ_UT2_OUT_CMP3_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp3EnSet */
#define  IRQ_UT2_OUT_CMP3_EN_SET(x)                         (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3EnSet in register */
#define  GET_IRQ_UT2_OUT_CMP3_EN_SET(reg)                   (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3EnSet from register */
#define  IRQ_UT2_FULL_VAL_EN_SET_SHIFT                      4                             /**< Shift for IRQUT2FullValEnSet */
#define  IRQ_UT2_FULL_VAL_EN_SET_MASK                       0x00000010u                   /**< Mask for IRQUT2FullValEnSet */
#define  IRQ_UT2_FULL_VAL_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT2FullValEnSet */
#define  IRQ_UT2_FULL_VAL_EN_SET(x)                         (((x)&0x1u)<<4)               /**< Set IRQUT2FullValEnSet in register */
#define  GET_IRQ_UT2_FULL_VAL_EN_SET(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValEnSet from register */
#define  IRQ_UT2_IN_CPT_EN_SET_SHIFT                        5                             /**< Shift for IRQUT2InCptEnSet */
#define  IRQ_UT2_IN_CPT_EN_SET_MASK                         0x00000020u                   /**< Mask for IRQUT2InCptEnSet */
#define  IRQ_UT2_IN_CPT_EN_SET_BMASK                        0x1u                          /**< Base mask for IRQUT2InCptEnSet */
#define  IRQ_UT2_IN_CPT_EN_SET(x)                           (((x)&0x1u)<<5)               /**< Set IRQUT2InCptEnSet in register */
#define  GET_IRQ_UT2_IN_CPT_EN_SET(reg)                     (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptEnSet from register */
#define  IRQ_UT3_OUT_CMP0_EN_SET_SHIFT                      8                             /**< Shift for IRQUT3OutCmp0EnSet */
#define  IRQ_UT3_OUT_CMP0_EN_SET_MASK                       0x00000100u                   /**< Mask for IRQUT3OutCmp0EnSet */
#define  IRQ_UT3_OUT_CMP0_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp0EnSet */
#define  IRQ_UT3_OUT_CMP0_EN_SET(x)                         (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0EnSet in register */
#define  GET_IRQ_UT3_OUT_CMP0_EN_SET(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0EnSet from register */
#define  IRQ_UT3_OUT_CMP1_EN_SET_SHIFT                      9                             /**< Shift for IRQUT3OutCmp1EnSet */
#define  IRQ_UT3_OUT_CMP1_EN_SET_MASK                       0x00000200u                   /**< Mask for IRQUT3OutCmp1EnSet */
#define  IRQ_UT3_OUT_CMP1_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp1EnSet */
#define  IRQ_UT3_OUT_CMP1_EN_SET(x)                         (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1EnSet in register */
#define  GET_IRQ_UT3_OUT_CMP1_EN_SET(reg)                   (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1EnSet from register */
#define  IRQ_UT3_OUT_CMP2_EN_SET_SHIFT                      10                            /**< Shift for IRQUT3OutCmp2EnSet */
#define  IRQ_UT3_OUT_CMP2_EN_SET_MASK                       0x00000400u                   /**< Mask for IRQUT3OutCmp2EnSet */
#define  IRQ_UT3_OUT_CMP2_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp2EnSet */
#define  IRQ_UT3_OUT_CMP2_EN_SET(x)                         (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2EnSet in register */
#define  GET_IRQ_UT3_OUT_CMP2_EN_SET(reg)                   (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2EnSet from register */
#define  IRQ_UT3_OUT_CMP3_EN_SET_SHIFT                      11                            /**< Shift for IRQUT3OutCmp3EnSet */
#define  IRQ_UT3_OUT_CMP3_EN_SET_MASK                       0x00000800u                   /**< Mask for IRQUT3OutCmp3EnSet */
#define  IRQ_UT3_OUT_CMP3_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp3EnSet */
#define  IRQ_UT3_OUT_CMP3_EN_SET(x)                         (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3EnSet in register */
#define  GET_IRQ_UT3_OUT_CMP3_EN_SET(reg)                   (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3EnSet from register */
#define  IRQ_UT3_FULL_VAL_EN_SET_SHIFT                      12                            /**< Shift for IRQUT3FullValEnSet */
#define  IRQ_UT3_FULL_VAL_EN_SET_MASK                       0x00001000u                   /**< Mask for IRQUT3FullValEnSet */
#define  IRQ_UT3_FULL_VAL_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQUT3FullValEnSet */
#define  IRQ_UT3_FULL_VAL_EN_SET(x)                         (((x)&0x1u)<<12)              /**< Set IRQUT3FullValEnSet in register */
#define  GET_IRQ_UT3_FULL_VAL_EN_SET(reg)                   (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValEnSet from register */
#define  IRQ_UT3_IN_CPT_EN_SET_SHIFT                        13                            /**< Shift for IRQUT3InCptEnSet */
#define  IRQ_UT3_IN_CPT_EN_SET_MASK                         0x00002000u                   /**< Mask for IRQUT3InCptEnSet */
#define  IRQ_UT3_IN_CPT_EN_SET_BMASK                        0x1u                          /**< Base mask for IRQUT3InCptEnSet */
#define  IRQ_UT3_IN_CPT_EN_SET(x)                           (((x)&0x1u)<<13)              /**< Set IRQUT3InCptEnSet in register */
#define  GET_IRQ_UT3_IN_CPT_EN_SET(reg)                     (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptEnSet from register */
/** @} */


/**
 * @name RegIRQUniTimEnClr
 * @{
 */
// RegIRQUniTimEnClr.r32
#define  REG_IRQ_UNI_TIM_EN_CLR_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQUniTimEnClr */
#define  REG_IRQ_UNI_TIM_EN_CLR_MASK                        0x00003F3Fu                   /**< Mask for RegIRQUniTimEnClr */

#define  IRQ_UT2_OUT_CMP0_EN_CLR_SHIFT                      0                             /**< Shift for IRQUT2OutCmp0EnClr */
#define  IRQ_UT2_OUT_CMP0_EN_CLR_MASK                       0x00000001u                   /**< Mask for IRQUT2OutCmp0EnClr */
#define  IRQ_UT2_OUT_CMP0_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp0EnClr */
#define  IRQ_UT2_OUT_CMP0_EN_CLR(x)                         (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0EnClr in register */
#define  GET_IRQ_UT2_OUT_CMP0_EN_CLR(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0EnClr from register */
#define  IRQ_UT2_OUT_CMP1_EN_CLR_SHIFT                      1                             /**< Shift for IRQUT2OutCmp1EnClr */
#define  IRQ_UT2_OUT_CMP1_EN_CLR_MASK                       0x00000002u                   /**< Mask for IRQUT2OutCmp1EnClr */
#define  IRQ_UT2_OUT_CMP1_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp1EnClr */
#define  IRQ_UT2_OUT_CMP1_EN_CLR(x)                         (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1EnClr in register */
#define  GET_IRQ_UT2_OUT_CMP1_EN_CLR(reg)                   (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1EnClr from register */
#define  IRQ_UT2_OUT_CMP2_EN_CLR_SHIFT                      2                             /**< Shift for IRQUT2OutCmp2EnClr */
#define  IRQ_UT2_OUT_CMP2_EN_CLR_MASK                       0x00000004u                   /**< Mask for IRQUT2OutCmp2EnClr */
#define  IRQ_UT2_OUT_CMP2_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp2EnClr */
#define  IRQ_UT2_OUT_CMP2_EN_CLR(x)                         (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2EnClr in register */
#define  GET_IRQ_UT2_OUT_CMP2_EN_CLR(reg)                   (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2EnClr from register */
#define  IRQ_UT2_OUT_CMP3_EN_CLR_SHIFT                      3                             /**< Shift for IRQUT2OutCmp3EnClr */
#define  IRQ_UT2_OUT_CMP3_EN_CLR_MASK                       0x00000008u                   /**< Mask for IRQUT2OutCmp3EnClr */
#define  IRQ_UT2_OUT_CMP3_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT2OutCmp3EnClr */
#define  IRQ_UT2_OUT_CMP3_EN_CLR(x)                         (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3EnClr in register */
#define  GET_IRQ_UT2_OUT_CMP3_EN_CLR(reg)                   (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3EnClr from register */
#define  IRQ_UT2_FULL_VAL_EN_CLR_SHIFT                      4                             /**< Shift for IRQUT2FullValEnClr */
#define  IRQ_UT2_FULL_VAL_EN_CLR_MASK                       0x00000010u                   /**< Mask for IRQUT2FullValEnClr */
#define  IRQ_UT2_FULL_VAL_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT2FullValEnClr */
#define  IRQ_UT2_FULL_VAL_EN_CLR(x)                         (((x)&0x1u)<<4)               /**< Set IRQUT2FullValEnClr in register */
#define  GET_IRQ_UT2_FULL_VAL_EN_CLR(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValEnClr from register */
#define  IRQ_UT2_IN_CPT_EN_CLR_SHIFT                        5                             /**< Shift for IRQUT2InCptEnClr */
#define  IRQ_UT2_IN_CPT_EN_CLR_MASK                         0x00000020u                   /**< Mask for IRQUT2InCptEnClr */
#define  IRQ_UT2_IN_CPT_EN_CLR_BMASK                        0x1u                          /**< Base mask for IRQUT2InCptEnClr */
#define  IRQ_UT2_IN_CPT_EN_CLR(x)                           (((x)&0x1u)<<5)               /**< Set IRQUT2InCptEnClr in register */
#define  GET_IRQ_UT2_IN_CPT_EN_CLR(reg)                     (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptEnClr from register */
#define  IRQ_UT3_OUT_CMP0_EN_CLR_SHIFT                      8                             /**< Shift for IRQUT3OutCmp0EnClr */
#define  IRQ_UT3_OUT_CMP0_EN_CLR_MASK                       0x00000100u                   /**< Mask for IRQUT3OutCmp0EnClr */
#define  IRQ_UT3_OUT_CMP0_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp0EnClr */
#define  IRQ_UT3_OUT_CMP0_EN_CLR(x)                         (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0EnClr in register */
#define  GET_IRQ_UT3_OUT_CMP0_EN_CLR(reg)                   (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0EnClr from register */
#define  IRQ_UT3_OUT_CMP1_EN_CLR_SHIFT                      9                             /**< Shift for IRQUT3OutCmp1EnClr */
#define  IRQ_UT3_OUT_CMP1_EN_CLR_MASK                       0x00000200u                   /**< Mask for IRQUT3OutCmp1EnClr */
#define  IRQ_UT3_OUT_CMP1_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp1EnClr */
#define  IRQ_UT3_OUT_CMP1_EN_CLR(x)                         (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1EnClr in register */
#define  GET_IRQ_UT3_OUT_CMP1_EN_CLR(reg)                   (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1EnClr from register */
#define  IRQ_UT3_OUT_CMP2_EN_CLR_SHIFT                      10                            /**< Shift for IRQUT3OutCmp2EnClr */
#define  IRQ_UT3_OUT_CMP2_EN_CLR_MASK                       0x00000400u                   /**< Mask for IRQUT3OutCmp2EnClr */
#define  IRQ_UT3_OUT_CMP2_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp2EnClr */
#define  IRQ_UT3_OUT_CMP2_EN_CLR(x)                         (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2EnClr in register */
#define  GET_IRQ_UT3_OUT_CMP2_EN_CLR(reg)                   (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2EnClr from register */
#define  IRQ_UT3_OUT_CMP3_EN_CLR_SHIFT                      11                            /**< Shift for IRQUT3OutCmp3EnClr */
#define  IRQ_UT3_OUT_CMP3_EN_CLR_MASK                       0x00000800u                   /**< Mask for IRQUT3OutCmp3EnClr */
#define  IRQ_UT3_OUT_CMP3_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT3OutCmp3EnClr */
#define  IRQ_UT3_OUT_CMP3_EN_CLR(x)                         (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3EnClr in register */
#define  GET_IRQ_UT3_OUT_CMP3_EN_CLR(reg)                   (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3EnClr from register */
#define  IRQ_UT3_FULL_VAL_EN_CLR_SHIFT                      12                            /**< Shift for IRQUT3FullValEnClr */
#define  IRQ_UT3_FULL_VAL_EN_CLR_MASK                       0x00001000u                   /**< Mask for IRQUT3FullValEnClr */
#define  IRQ_UT3_FULL_VAL_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQUT3FullValEnClr */
#define  IRQ_UT3_FULL_VAL_EN_CLR(x)                         (((x)&0x1u)<<12)              /**< Set IRQUT3FullValEnClr in register */
#define  GET_IRQ_UT3_FULL_VAL_EN_CLR(reg)                   (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValEnClr from register */
#define  IRQ_UT3_IN_CPT_EN_CLR_SHIFT                        13                            /**< Shift for IRQUT3InCptEnClr */
#define  IRQ_UT3_IN_CPT_EN_CLR_MASK                         0x00002000u                   /**< Mask for IRQUT3InCptEnClr */
#define  IRQ_UT3_IN_CPT_EN_CLR_BMASK                        0x1u                          /**< Base mask for IRQUT3InCptEnClr */
#define  IRQ_UT3_IN_CPT_EN_CLR(x)                           (((x)&0x1u)<<13)              /**< Set IRQUT3InCptEnClr in register */
#define  GET_IRQ_UT3_IN_CPT_EN_CLR(reg)                     (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptEnClr from register */
/** @} */


/**
 * @name RegIRQUniTimMsk
 * @{
 */
// RegIRQUniTimMsk.r32
#define  REG_IRQ_UNI_TIM_MSK_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQUniTimMsk */
#define  REG_IRQ_UNI_TIM_MSK_MASK                           0x00003F3Fu                   /**< Mask for RegIRQUniTimMsk */

#define  IRQ_UT2_OUT_CMP0_MSK_SHIFT                         0                             /**< Shift for IRQUT2OutCmp0Msk */
#define  IRQ_UT2_OUT_CMP0_MSK_MASK                          0x00000001u                   /**< Mask for IRQUT2OutCmp0Msk */
#define  IRQ_UT2_OUT_CMP0_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp0Msk */
#define  IRQ_UT2_OUT_CMP0_MSK(x)                            (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0Msk in register */
#define  GET_IRQ_UT2_OUT_CMP0_MSK(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0Msk from register */
#define  IRQ_UT2_OUT_CMP1_MSK_SHIFT                         1                             /**< Shift for IRQUT2OutCmp1Msk */
#define  IRQ_UT2_OUT_CMP1_MSK_MASK                          0x00000002u                   /**< Mask for IRQUT2OutCmp1Msk */
#define  IRQ_UT2_OUT_CMP1_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp1Msk */
#define  IRQ_UT2_OUT_CMP1_MSK(x)                            (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1Msk in register */
#define  GET_IRQ_UT2_OUT_CMP1_MSK(reg)                      (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1Msk from register */
#define  IRQ_UT2_OUT_CMP2_MSK_SHIFT                         2                             /**< Shift for IRQUT2OutCmp2Msk */
#define  IRQ_UT2_OUT_CMP2_MSK_MASK                          0x00000004u                   /**< Mask for IRQUT2OutCmp2Msk */
#define  IRQ_UT2_OUT_CMP2_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp2Msk */
#define  IRQ_UT2_OUT_CMP2_MSK(x)                            (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2Msk in register */
#define  GET_IRQ_UT2_OUT_CMP2_MSK(reg)                      (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2Msk from register */
#define  IRQ_UT2_OUT_CMP3_MSK_SHIFT                         3                             /**< Shift for IRQUT2OutCmp3Msk */
#define  IRQ_UT2_OUT_CMP3_MSK_MASK                          0x00000008u                   /**< Mask for IRQUT2OutCmp3Msk */
#define  IRQ_UT2_OUT_CMP3_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp3Msk */
#define  IRQ_UT2_OUT_CMP3_MSK(x)                            (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3Msk in register */
#define  GET_IRQ_UT2_OUT_CMP3_MSK(reg)                      (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3Msk from register */
#define  IRQ_UT2_FULL_VAL_MSK_SHIFT                         4                             /**< Shift for IRQUT2FullValMsk */
#define  IRQ_UT2_FULL_VAL_MSK_MASK                          0x00000010u                   /**< Mask for IRQUT2FullValMsk */
#define  IRQ_UT2_FULL_VAL_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT2FullValMsk */
#define  IRQ_UT2_FULL_VAL_MSK(x)                            (((x)&0x1u)<<4)               /**< Set IRQUT2FullValMsk in register */
#define  GET_IRQ_UT2_FULL_VAL_MSK(reg)                      (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValMsk from register */
#define  IRQ_UT2_IN_CPT_MSK_SHIFT                           5                             /**< Shift for IRQUT2InCptMsk */
#define  IRQ_UT2_IN_CPT_MSK_MASK                            0x00000020u                   /**< Mask for IRQUT2InCptMsk */
#define  IRQ_UT2_IN_CPT_MSK_BMASK                           0x1u                          /**< Base mask for IRQUT2InCptMsk */
#define  IRQ_UT2_IN_CPT_MSK(x)                              (((x)&0x1u)<<5)               /**< Set IRQUT2InCptMsk in register */
#define  GET_IRQ_UT2_IN_CPT_MSK(reg)                        (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptMsk from register */
#define  IRQ_UT3_OUT_CMP0_MSK_SHIFT                         8                             /**< Shift for IRQUT3OutCmp0Msk */
#define  IRQ_UT3_OUT_CMP0_MSK_MASK                          0x00000100u                   /**< Mask for IRQUT3OutCmp0Msk */
#define  IRQ_UT3_OUT_CMP0_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp0Msk */
#define  IRQ_UT3_OUT_CMP0_MSK(x)                            (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0Msk in register */
#define  GET_IRQ_UT3_OUT_CMP0_MSK(reg)                      (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0Msk from register */
#define  IRQ_UT3_OUT_CMP1_MSK_SHIFT                         9                             /**< Shift for IRQUT3OutCmp1Msk */
#define  IRQ_UT3_OUT_CMP1_MSK_MASK                          0x00000200u                   /**< Mask for IRQUT3OutCmp1Msk */
#define  IRQ_UT3_OUT_CMP1_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp1Msk */
#define  IRQ_UT3_OUT_CMP1_MSK(x)                            (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1Msk in register */
#define  GET_IRQ_UT3_OUT_CMP1_MSK(reg)                      (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1Msk from register */
#define  IRQ_UT3_OUT_CMP2_MSK_SHIFT                         10                            /**< Shift for IRQUT3OutCmp2Msk */
#define  IRQ_UT3_OUT_CMP2_MSK_MASK                          0x00000400u                   /**< Mask for IRQUT3OutCmp2Msk */
#define  IRQ_UT3_OUT_CMP2_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp2Msk */
#define  IRQ_UT3_OUT_CMP2_MSK(x)                            (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2Msk in register */
#define  GET_IRQ_UT3_OUT_CMP2_MSK(reg)                      (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2Msk from register */
#define  IRQ_UT3_OUT_CMP3_MSK_SHIFT                         11                            /**< Shift for IRQUT3OutCmp3Msk */
#define  IRQ_UT3_OUT_CMP3_MSK_MASK                          0x00000800u                   /**< Mask for IRQUT3OutCmp3Msk */
#define  IRQ_UT3_OUT_CMP3_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp3Msk */
#define  IRQ_UT3_OUT_CMP3_MSK(x)                            (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3Msk in register */
#define  GET_IRQ_UT3_OUT_CMP3_MSK(reg)                      (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3Msk from register */
#define  IRQ_UT3_FULL_VAL_MSK_SHIFT                         12                            /**< Shift for IRQUT3FullValMsk */
#define  IRQ_UT3_FULL_VAL_MSK_MASK                          0x00001000u                   /**< Mask for IRQUT3FullValMsk */
#define  IRQ_UT3_FULL_VAL_MSK_BMASK                         0x1u                          /**< Base mask for IRQUT3FullValMsk */
#define  IRQ_UT3_FULL_VAL_MSK(x)                            (((x)&0x1u)<<12)              /**< Set IRQUT3FullValMsk in register */
#define  GET_IRQ_UT3_FULL_VAL_MSK(reg)                      (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValMsk from register */
#define  IRQ_UT3_IN_CPT_MSK_SHIFT                           13                            /**< Shift for IRQUT3InCptMsk */
#define  IRQ_UT3_IN_CPT_MSK_MASK                            0x00002000u                   /**< Mask for IRQUT3InCptMsk */
#define  IRQ_UT3_IN_CPT_MSK_BMASK                           0x1u                          /**< Base mask for IRQUT3InCptMsk */
#define  IRQ_UT3_IN_CPT_MSK(x)                              (((x)&0x1u)<<13)              /**< Set IRQUT3InCptMsk in register */
#define  GET_IRQ_UT3_IN_CPT_MSK(reg)                        (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptMsk from register */
/** @} */


/**
 * @name RegIRQUniTimMskSet
 * @{
 */
// RegIRQUniTimMskSet.r32
#define  REG_IRQ_UNI_TIM_MSK_SET_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQUniTimMskSet */
#define  REG_IRQ_UNI_TIM_MSK_SET_MASK                       0x00003F3Fu                   /**< Mask for RegIRQUniTimMskSet */

#define  IRQ_UT2_OUT_CMP0_MSK_SET_SHIFT                     0                             /**< Shift for IRQUT2OutCmp0MskSet */
#define  IRQ_UT2_OUT_CMP0_MSK_SET_MASK                      0x00000001u                   /**< Mask for IRQUT2OutCmp0MskSet */
#define  IRQ_UT2_OUT_CMP0_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp0MskSet */
#define  IRQ_UT2_OUT_CMP0_MSK_SET(x)                        (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0MskSet in register */
#define  GET_IRQ_UT2_OUT_CMP0_MSK_SET(reg)                  (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0MskSet from register */
#define  IRQ_UT2_OUT_CMP1_MSK_SET_SHIFT                     1                             /**< Shift for IRQUT2OutCmp1MskSet */
#define  IRQ_UT2_OUT_CMP1_MSK_SET_MASK                      0x00000002u                   /**< Mask for IRQUT2OutCmp1MskSet */
#define  IRQ_UT2_OUT_CMP1_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp1MskSet */
#define  IRQ_UT2_OUT_CMP1_MSK_SET(x)                        (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1MskSet in register */
#define  GET_IRQ_UT2_OUT_CMP1_MSK_SET(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1MskSet from register */
#define  IRQ_UT2_OUT_CMP2_MSK_SET_SHIFT                     2                             /**< Shift for IRQUT2OutCmp2MskSet */
#define  IRQ_UT2_OUT_CMP2_MSK_SET_MASK                      0x00000004u                   /**< Mask for IRQUT2OutCmp2MskSet */
#define  IRQ_UT2_OUT_CMP2_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp2MskSet */
#define  IRQ_UT2_OUT_CMP2_MSK_SET(x)                        (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2MskSet in register */
#define  GET_IRQ_UT2_OUT_CMP2_MSK_SET(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2MskSet from register */
#define  IRQ_UT2_OUT_CMP3_MSK_SET_SHIFT                     3                             /**< Shift for IRQUT2OutCmp3MskSet */
#define  IRQ_UT2_OUT_CMP3_MSK_SET_MASK                      0x00000008u                   /**< Mask for IRQUT2OutCmp3MskSet */
#define  IRQ_UT2_OUT_CMP3_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp3MskSet */
#define  IRQ_UT2_OUT_CMP3_MSK_SET(x)                        (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3MskSet in register */
#define  GET_IRQ_UT2_OUT_CMP3_MSK_SET(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3MskSet from register */
#define  IRQ_UT2_FULL_VAL_MSK_SET_SHIFT                     4                             /**< Shift for IRQUT2FullValMskSet */
#define  IRQ_UT2_FULL_VAL_MSK_SET_MASK                      0x00000010u                   /**< Mask for IRQUT2FullValMskSet */
#define  IRQ_UT2_FULL_VAL_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2FullValMskSet */
#define  IRQ_UT2_FULL_VAL_MSK_SET(x)                        (((x)&0x1u)<<4)               /**< Set IRQUT2FullValMskSet in register */
#define  GET_IRQ_UT2_FULL_VAL_MSK_SET(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValMskSet from register */
#define  IRQ_UT2_IN_CPT_MSK_SET_SHIFT                       5                             /**< Shift for IRQUT2InCptMskSet */
#define  IRQ_UT2_IN_CPT_MSK_SET_MASK                        0x00000020u                   /**< Mask for IRQUT2InCptMskSet */
#define  IRQ_UT2_IN_CPT_MSK_SET_BMASK                       0x1u                          /**< Base mask for IRQUT2InCptMskSet */
#define  IRQ_UT2_IN_CPT_MSK_SET(x)                          (((x)&0x1u)<<5)               /**< Set IRQUT2InCptMskSet in register */
#define  GET_IRQ_UT2_IN_CPT_MSK_SET(reg)                    (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptMskSet from register */
#define  IRQ_UT3_OUT_CMP0_MSK_SET_SHIFT                     8                             /**< Shift for IRQUT3OutCmp0MskSet */
#define  IRQ_UT3_OUT_CMP0_MSK_SET_MASK                      0x00000100u                   /**< Mask for IRQUT3OutCmp0MskSet */
#define  IRQ_UT3_OUT_CMP0_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp0MskSet */
#define  IRQ_UT3_OUT_CMP0_MSK_SET(x)                        (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0MskSet in register */
#define  GET_IRQ_UT3_OUT_CMP0_MSK_SET(reg)                  (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0MskSet from register */
#define  IRQ_UT3_OUT_CMP1_MSK_SET_SHIFT                     9                             /**< Shift for IRQUT3OutCmp1MskSet */
#define  IRQ_UT3_OUT_CMP1_MSK_SET_MASK                      0x00000200u                   /**< Mask for IRQUT3OutCmp1MskSet */
#define  IRQ_UT3_OUT_CMP1_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp1MskSet */
#define  IRQ_UT3_OUT_CMP1_MSK_SET(x)                        (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1MskSet in register */
#define  GET_IRQ_UT3_OUT_CMP1_MSK_SET(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1MskSet from register */
#define  IRQ_UT3_OUT_CMP2_MSK_SET_SHIFT                     10                            /**< Shift for IRQUT3OutCmp2MskSet */
#define  IRQ_UT3_OUT_CMP2_MSK_SET_MASK                      0x00000400u                   /**< Mask for IRQUT3OutCmp2MskSet */
#define  IRQ_UT3_OUT_CMP2_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp2MskSet */
#define  IRQ_UT3_OUT_CMP2_MSK_SET(x)                        (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2MskSet in register */
#define  GET_IRQ_UT3_OUT_CMP2_MSK_SET(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2MskSet from register */
#define  IRQ_UT3_OUT_CMP3_MSK_SET_SHIFT                     11                            /**< Shift for IRQUT3OutCmp3MskSet */
#define  IRQ_UT3_OUT_CMP3_MSK_SET_MASK                      0x00000800u                   /**< Mask for IRQUT3OutCmp3MskSet */
#define  IRQ_UT3_OUT_CMP3_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp3MskSet */
#define  IRQ_UT3_OUT_CMP3_MSK_SET(x)                        (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3MskSet in register */
#define  GET_IRQ_UT3_OUT_CMP3_MSK_SET(reg)                  (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3MskSet from register */
#define  IRQ_UT3_FULL_VAL_MSK_SET_SHIFT                     12                            /**< Shift for IRQUT3FullValMskSet */
#define  IRQ_UT3_FULL_VAL_MSK_SET_MASK                      0x00001000u                   /**< Mask for IRQUT3FullValMskSet */
#define  IRQ_UT3_FULL_VAL_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3FullValMskSet */
#define  IRQ_UT3_FULL_VAL_MSK_SET(x)                        (((x)&0x1u)<<12)              /**< Set IRQUT3FullValMskSet in register */
#define  GET_IRQ_UT3_FULL_VAL_MSK_SET(reg)                  (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValMskSet from register */
#define  IRQ_UT3_IN_CPT_MSK_SET_SHIFT                       13                            /**< Shift for IRQUT3InCptMskSet */
#define  IRQ_UT3_IN_CPT_MSK_SET_MASK                        0x00002000u                   /**< Mask for IRQUT3InCptMskSet */
#define  IRQ_UT3_IN_CPT_MSK_SET_BMASK                       0x1u                          /**< Base mask for IRQUT3InCptMskSet */
#define  IRQ_UT3_IN_CPT_MSK_SET(x)                          (((x)&0x1u)<<13)              /**< Set IRQUT3InCptMskSet in register */
#define  GET_IRQ_UT3_IN_CPT_MSK_SET(reg)                    (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptMskSet from register */
/** @} */


/**
 * @name RegIRQUniTimMskClr
 * @{
 */
// RegIRQUniTimMskClr.r32
#define  REG_IRQ_UNI_TIM_MSK_CLR_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQUniTimMskClr */
#define  REG_IRQ_UNI_TIM_MSK_CLR_MASK                       0x00003F3Fu                   /**< Mask for RegIRQUniTimMskClr */

#define  IRQ_UT2_OUT_CMP0_MSK_CLR_SHIFT                     0                             /**< Shift for IRQUT2OutCmp0MskClr */
#define  IRQ_UT2_OUT_CMP0_MSK_CLR_MASK                      0x00000001u                   /**< Mask for IRQUT2OutCmp0MskClr */
#define  IRQ_UT2_OUT_CMP0_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp0MskClr */
#define  IRQ_UT2_OUT_CMP0_MSK_CLR(x)                        (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0MskClr in register */
#define  GET_IRQ_UT2_OUT_CMP0_MSK_CLR(reg)                  (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0MskClr from register */
#define  IRQ_UT2_OUT_CMP1_MSK_CLR_SHIFT                     1                             /**< Shift for IRQUT2OutCmp1MskClr */
#define  IRQ_UT2_OUT_CMP1_MSK_CLR_MASK                      0x00000002u                   /**< Mask for IRQUT2OutCmp1MskClr */
#define  IRQ_UT2_OUT_CMP1_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp1MskClr */
#define  IRQ_UT2_OUT_CMP1_MSK_CLR(x)                        (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1MskClr in register */
#define  GET_IRQ_UT2_OUT_CMP1_MSK_CLR(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1MskClr from register */
#define  IRQ_UT2_OUT_CMP2_MSK_CLR_SHIFT                     2                             /**< Shift for IRQUT2OutCmp2MskClr */
#define  IRQ_UT2_OUT_CMP2_MSK_CLR_MASK                      0x00000004u                   /**< Mask for IRQUT2OutCmp2MskClr */
#define  IRQ_UT2_OUT_CMP2_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp2MskClr */
#define  IRQ_UT2_OUT_CMP2_MSK_CLR(x)                        (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2MskClr in register */
#define  GET_IRQ_UT2_OUT_CMP2_MSK_CLR(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2MskClr from register */
#define  IRQ_UT2_OUT_CMP3_MSK_CLR_SHIFT                     3                             /**< Shift for IRQUT2OutCmp3MskClr */
#define  IRQ_UT2_OUT_CMP3_MSK_CLR_MASK                      0x00000008u                   /**< Mask for IRQUT2OutCmp3MskClr */
#define  IRQ_UT2_OUT_CMP3_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp3MskClr */
#define  IRQ_UT2_OUT_CMP3_MSK_CLR(x)                        (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3MskClr in register */
#define  GET_IRQ_UT2_OUT_CMP3_MSK_CLR(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3MskClr from register */
#define  IRQ_UT2_FULL_VAL_MSK_CLR_SHIFT                     4                             /**< Shift for IRQUT2FullValMskClr */
#define  IRQ_UT2_FULL_VAL_MSK_CLR_MASK                      0x00000010u                   /**< Mask for IRQUT2FullValMskClr */
#define  IRQ_UT2_FULL_VAL_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2FullValMskClr */
#define  IRQ_UT2_FULL_VAL_MSK_CLR(x)                        (((x)&0x1u)<<4)               /**< Set IRQUT2FullValMskClr in register */
#define  GET_IRQ_UT2_FULL_VAL_MSK_CLR(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValMskClr from register */
#define  IRQ_UT2_IN_CPT_MSK_CLR_SHIFT                       5                             /**< Shift for IRQUT2InCptMskClr */
#define  IRQ_UT2_IN_CPT_MSK_CLR_MASK                        0x00000020u                   /**< Mask for IRQUT2InCptMskClr */
#define  IRQ_UT2_IN_CPT_MSK_CLR_BMASK                       0x1u                          /**< Base mask for IRQUT2InCptMskClr */
#define  IRQ_UT2_IN_CPT_MSK_CLR(x)                          (((x)&0x1u)<<5)               /**< Set IRQUT2InCptMskClr in register */
#define  GET_IRQ_UT2_IN_CPT_MSK_CLR(reg)                    (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptMskClr from register */
#define  IRQ_UT3_OUT_CMP0_MSK_CLR_SHIFT                     8                             /**< Shift for IRQUT3OutCmp0MskClr */
#define  IRQ_UT3_OUT_CMP0_MSK_CLR_MASK                      0x00000100u                   /**< Mask for IRQUT3OutCmp0MskClr */
#define  IRQ_UT3_OUT_CMP0_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp0MskClr */
#define  IRQ_UT3_OUT_CMP0_MSK_CLR(x)                        (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0MskClr in register */
#define  GET_IRQ_UT3_OUT_CMP0_MSK_CLR(reg)                  (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0MskClr from register */
#define  IRQ_UT3_OUT_CMP1_MSK_CLR_SHIFT                     9                             /**< Shift for IRQUT3OutCmp1MskClr */
#define  IRQ_UT3_OUT_CMP1_MSK_CLR_MASK                      0x00000200u                   /**< Mask for IRQUT3OutCmp1MskClr */
#define  IRQ_UT3_OUT_CMP1_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp1MskClr */
#define  IRQ_UT3_OUT_CMP1_MSK_CLR(x)                        (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1MskClr in register */
#define  GET_IRQ_UT3_OUT_CMP1_MSK_CLR(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1MskClr from register */
#define  IRQ_UT3_OUT_CMP2_MSK_CLR_SHIFT                     10                            /**< Shift for IRQUT3OutCmp2MskClr */
#define  IRQ_UT3_OUT_CMP2_MSK_CLR_MASK                      0x00000400u                   /**< Mask for IRQUT3OutCmp2MskClr */
#define  IRQ_UT3_OUT_CMP2_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp2MskClr */
#define  IRQ_UT3_OUT_CMP2_MSK_CLR(x)                        (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2MskClr in register */
#define  GET_IRQ_UT3_OUT_CMP2_MSK_CLR(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2MskClr from register */
#define  IRQ_UT3_OUT_CMP3_MSK_CLR_SHIFT                     11                            /**< Shift for IRQUT3OutCmp3MskClr */
#define  IRQ_UT3_OUT_CMP3_MSK_CLR_MASK                      0x00000800u                   /**< Mask for IRQUT3OutCmp3MskClr */
#define  IRQ_UT3_OUT_CMP3_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp3MskClr */
#define  IRQ_UT3_OUT_CMP3_MSK_CLR(x)                        (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3MskClr in register */
#define  GET_IRQ_UT3_OUT_CMP3_MSK_CLR(reg)                  (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3MskClr from register */
#define  IRQ_UT3_FULL_VAL_MSK_CLR_SHIFT                     12                            /**< Shift for IRQUT3FullValMskClr */
#define  IRQ_UT3_FULL_VAL_MSK_CLR_MASK                      0x00001000u                   /**< Mask for IRQUT3FullValMskClr */
#define  IRQ_UT3_FULL_VAL_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3FullValMskClr */
#define  IRQ_UT3_FULL_VAL_MSK_CLR(x)                        (((x)&0x1u)<<12)              /**< Set IRQUT3FullValMskClr in register */
#define  GET_IRQ_UT3_FULL_VAL_MSK_CLR(reg)                  (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValMskClr from register */
#define  IRQ_UT3_IN_CPT_MSK_CLR_SHIFT                       13                            /**< Shift for IRQUT3InCptMskClr */
#define  IRQ_UT3_IN_CPT_MSK_CLR_MASK                        0x00002000u                   /**< Mask for IRQUT3InCptMskClr */
#define  IRQ_UT3_IN_CPT_MSK_CLR_BMASK                       0x1u                          /**< Base mask for IRQUT3InCptMskClr */
#define  IRQ_UT3_IN_CPT_MSK_CLR(x)                          (((x)&0x1u)<<13)              /**< Set IRQUT3InCptMskClr in register */
#define  GET_IRQ_UT3_IN_CPT_MSK_CLR(reg)                    (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptMskClr from register */
/** @} */


/**
 * @name RegIRQUniTimSts
 * @{
 */
// RegIRQUniTimSts.r32
#define  REG_IRQ_UNI_TIM_STS_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQUniTimSts */
#define  REG_IRQ_UNI_TIM_STS_MASK                           0x00003F3Fu                   /**< Mask for RegIRQUniTimSts */

#define  IRQ_UT2_OUT_CMP0_STS_SHIFT                         0                             /**< Shift for IRQUT2OutCmp0Sts */
#define  IRQ_UT2_OUT_CMP0_STS_MASK                          0x00000001u                   /**< Mask for IRQUT2OutCmp0Sts */
#define  IRQ_UT2_OUT_CMP0_STS_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp0Sts */
#define  IRQ_UT2_OUT_CMP0_STS(x)                            (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0Sts in register */
#define  GET_IRQ_UT2_OUT_CMP0_STS(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0Sts from register */
#define  IRQ_UT2_OUT_CMP1_STS_SHIFT                         1                             /**< Shift for IRQUT2OutCmp1Sts */
#define  IRQ_UT2_OUT_CMP1_STS_MASK                          0x00000002u                   /**< Mask for IRQUT2OutCmp1Sts */
#define  IRQ_UT2_OUT_CMP1_STS_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp1Sts */
#define  IRQ_UT2_OUT_CMP1_STS(x)                            (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1Sts in register */
#define  GET_IRQ_UT2_OUT_CMP1_STS(reg)                      (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1Sts from register */
#define  IRQ_UT2_OUT_CMP2_STS_SHIFT                         2                             /**< Shift for IRQUT2OutCmp2Sts */
#define  IRQ_UT2_OUT_CMP2_STS_MASK                          0x00000004u                   /**< Mask for IRQUT2OutCmp2Sts */
#define  IRQ_UT2_OUT_CMP2_STS_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp2Sts */
#define  IRQ_UT2_OUT_CMP2_STS(x)                            (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2Sts in register */
#define  GET_IRQ_UT2_OUT_CMP2_STS(reg)                      (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2Sts from register */
#define  IRQ_UT2_OUT_CMP3_STS_SHIFT                         3                             /**< Shift for IRQUT2OutCmp3Sts */
#define  IRQ_UT2_OUT_CMP3_STS_MASK                          0x00000008u                   /**< Mask for IRQUT2OutCmp3Sts */
#define  IRQ_UT2_OUT_CMP3_STS_BMASK                         0x1u                          /**< Base mask for IRQUT2OutCmp3Sts */
#define  IRQ_UT2_OUT_CMP3_STS(x)                            (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3Sts in register */
#define  GET_IRQ_UT2_OUT_CMP3_STS(reg)                      (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3Sts from register */
#define  IRQ_UT2_FULL_VAL_STS_SHIFT                         4                             /**< Shift for IRQUT2FullValSts */
#define  IRQ_UT2_FULL_VAL_STS_MASK                          0x00000010u                   /**< Mask for IRQUT2FullValSts */
#define  IRQ_UT2_FULL_VAL_STS_BMASK                         0x1u                          /**< Base mask for IRQUT2FullValSts */
#define  IRQ_UT2_FULL_VAL_STS(x)                            (((x)&0x1u)<<4)               /**< Set IRQUT2FullValSts in register */
#define  GET_IRQ_UT2_FULL_VAL_STS(reg)                      (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValSts from register */
#define  IRQ_UT2_IN_CPT_STS_SHIFT                           5                             /**< Shift for IRQUT2InCptSts */
#define  IRQ_UT2_IN_CPT_STS_MASK                            0x00000020u                   /**< Mask for IRQUT2InCptSts */
#define  IRQ_UT2_IN_CPT_STS_BMASK                           0x1u                          /**< Base mask for IRQUT2InCptSts */
#define  IRQ_UT2_IN_CPT_STS(x)                              (((x)&0x1u)<<5)               /**< Set IRQUT2InCptSts in register */
#define  GET_IRQ_UT2_IN_CPT_STS(reg)                        (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptSts from register */
#define  IRQ_UT3_OUT_CMP0_STS_SHIFT                         8                             /**< Shift for IRQUT3OutCmp0Sts */
#define  IRQ_UT3_OUT_CMP0_STS_MASK                          0x00000100u                   /**< Mask for IRQUT3OutCmp0Sts */
#define  IRQ_UT3_OUT_CMP0_STS_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp0Sts */
#define  IRQ_UT3_OUT_CMP0_STS(x)                            (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0Sts in register */
#define  GET_IRQ_UT3_OUT_CMP0_STS(reg)                      (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0Sts from register */
#define  IRQ_UT3_OUT_CMP1_STS_SHIFT                         9                             /**< Shift for IRQUT3OutCmp1Sts */
#define  IRQ_UT3_OUT_CMP1_STS_MASK                          0x00000200u                   /**< Mask for IRQUT3OutCmp1Sts */
#define  IRQ_UT3_OUT_CMP1_STS_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp1Sts */
#define  IRQ_UT3_OUT_CMP1_STS(x)                            (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1Sts in register */
#define  GET_IRQ_UT3_OUT_CMP1_STS(reg)                      (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1Sts from register */
#define  IRQ_UT3_OUT_CMP2_STS_SHIFT                         10                            /**< Shift for IRQUT3OutCmp2Sts */
#define  IRQ_UT3_OUT_CMP2_STS_MASK                          0x00000400u                   /**< Mask for IRQUT3OutCmp2Sts */
#define  IRQ_UT3_OUT_CMP2_STS_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp2Sts */
#define  IRQ_UT3_OUT_CMP2_STS(x)                            (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2Sts in register */
#define  GET_IRQ_UT3_OUT_CMP2_STS(reg)                      (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2Sts from register */
#define  IRQ_UT3_OUT_CMP3_STS_SHIFT                         11                            /**< Shift for IRQUT3OutCmp3Sts */
#define  IRQ_UT3_OUT_CMP3_STS_MASK                          0x00000800u                   /**< Mask for IRQUT3OutCmp3Sts */
#define  IRQ_UT3_OUT_CMP3_STS_BMASK                         0x1u                          /**< Base mask for IRQUT3OutCmp3Sts */
#define  IRQ_UT3_OUT_CMP3_STS(x)                            (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3Sts in register */
#define  GET_IRQ_UT3_OUT_CMP3_STS(reg)                      (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3Sts from register */
#define  IRQ_UT3_FULL_VAL_STS_SHIFT                         12                            /**< Shift for IRQUT3FullValSts */
#define  IRQ_UT3_FULL_VAL_STS_MASK                          0x00001000u                   /**< Mask for IRQUT3FullValSts */
#define  IRQ_UT3_FULL_VAL_STS_BMASK                         0x1u                          /**< Base mask for IRQUT3FullValSts */
#define  IRQ_UT3_FULL_VAL_STS(x)                            (((x)&0x1u)<<12)              /**< Set IRQUT3FullValSts in register */
#define  GET_IRQ_UT3_FULL_VAL_STS(reg)                      (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValSts from register */
#define  IRQ_UT3_IN_CPT_STS_SHIFT                           13                            /**< Shift for IRQUT3InCptSts */
#define  IRQ_UT3_IN_CPT_STS_MASK                            0x00002000u                   /**< Mask for IRQUT3InCptSts */
#define  IRQ_UT3_IN_CPT_STS_BMASK                           0x1u                          /**< Base mask for IRQUT3InCptSts */
#define  IRQ_UT3_IN_CPT_STS(x)                              (((x)&0x1u)<<13)              /**< Set IRQUT3InCptSts in register */
#define  GET_IRQ_UT3_IN_CPT_STS(reg)                        (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptSts from register */
/** @} */


/**
 * @name RegIRQUniTimStsSet
 * @{
 */
// RegIRQUniTimStsSet.r32
#define  REG_IRQ_UNI_TIM_STS_SET_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQUniTimStsSet */
#define  REG_IRQ_UNI_TIM_STS_SET_MASK                       0x00003F3Fu                   /**< Mask for RegIRQUniTimStsSet */

#define  IRQ_UT2_OUT_CMP0_STS_SET_SHIFT                     0                             /**< Shift for IRQUT2OutCmp0StsSet */
#define  IRQ_UT2_OUT_CMP0_STS_SET_MASK                      0x00000001u                   /**< Mask for IRQUT2OutCmp0StsSet */
#define  IRQ_UT2_OUT_CMP0_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp0StsSet */
#define  IRQ_UT2_OUT_CMP0_STS_SET(x)                        (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0StsSet in register */
#define  GET_IRQ_UT2_OUT_CMP0_STS_SET(reg)                  (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0StsSet from register */
#define  IRQ_UT2_OUT_CMP1_STS_SET_SHIFT                     1                             /**< Shift for IRQUT2OutCmp1StsSet */
#define  IRQ_UT2_OUT_CMP1_STS_SET_MASK                      0x00000002u                   /**< Mask for IRQUT2OutCmp1StsSet */
#define  IRQ_UT2_OUT_CMP1_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp1StsSet */
#define  IRQ_UT2_OUT_CMP1_STS_SET(x)                        (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1StsSet in register */
#define  GET_IRQ_UT2_OUT_CMP1_STS_SET(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1StsSet from register */
#define  IRQ_UT2_OUT_CMP2_STS_SET_SHIFT                     2                             /**< Shift for IRQUT2OutCmp2StsSet */
#define  IRQ_UT2_OUT_CMP2_STS_SET_MASK                      0x00000004u                   /**< Mask for IRQUT2OutCmp2StsSet */
#define  IRQ_UT2_OUT_CMP2_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp2StsSet */
#define  IRQ_UT2_OUT_CMP2_STS_SET(x)                        (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2StsSet in register */
#define  GET_IRQ_UT2_OUT_CMP2_STS_SET(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2StsSet from register */
#define  IRQ_UT2_OUT_CMP3_STS_SET_SHIFT                     3                             /**< Shift for IRQUT2OutCmp3StsSet */
#define  IRQ_UT2_OUT_CMP3_STS_SET_MASK                      0x00000008u                   /**< Mask for IRQUT2OutCmp3StsSet */
#define  IRQ_UT2_OUT_CMP3_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp3StsSet */
#define  IRQ_UT2_OUT_CMP3_STS_SET(x)                        (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3StsSet in register */
#define  GET_IRQ_UT2_OUT_CMP3_STS_SET(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3StsSet from register */
#define  IRQ_UT2_FULL_VAL_STS_SET_SHIFT                     4                             /**< Shift for IRQUT2FullValStsSet */
#define  IRQ_UT2_FULL_VAL_STS_SET_MASK                      0x00000010u                   /**< Mask for IRQUT2FullValStsSet */
#define  IRQ_UT2_FULL_VAL_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT2FullValStsSet */
#define  IRQ_UT2_FULL_VAL_STS_SET(x)                        (((x)&0x1u)<<4)               /**< Set IRQUT2FullValStsSet in register */
#define  GET_IRQ_UT2_FULL_VAL_STS_SET(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValStsSet from register */
#define  IRQ_UT2_IN_CPT_STS_SET_SHIFT                       5                             /**< Shift for IRQUT2InCptStsSet */
#define  IRQ_UT2_IN_CPT_STS_SET_MASK                        0x00000020u                   /**< Mask for IRQUT2InCptStsSet */
#define  IRQ_UT2_IN_CPT_STS_SET_BMASK                       0x1u                          /**< Base mask for IRQUT2InCptStsSet */
#define  IRQ_UT2_IN_CPT_STS_SET(x)                          (((x)&0x1u)<<5)               /**< Set IRQUT2InCptStsSet in register */
#define  GET_IRQ_UT2_IN_CPT_STS_SET(reg)                    (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptStsSet from register */
#define  IRQ_UT3_OUT_CMP0_STS_SET_SHIFT                     8                             /**< Shift for IRQUT3OutCmp0StsSet */
#define  IRQ_UT3_OUT_CMP0_STS_SET_MASK                      0x00000100u                   /**< Mask for IRQUT3OutCmp0StsSet */
#define  IRQ_UT3_OUT_CMP0_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp0StsSet */
#define  IRQ_UT3_OUT_CMP0_STS_SET(x)                        (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0StsSet in register */
#define  GET_IRQ_UT3_OUT_CMP0_STS_SET(reg)                  (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0StsSet from register */
#define  IRQ_UT3_OUT_CMP1_STS_SET_SHIFT                     9                             /**< Shift for IRQUT3OutCmp1StsSet */
#define  IRQ_UT3_OUT_CMP1_STS_SET_MASK                      0x00000200u                   /**< Mask for IRQUT3OutCmp1StsSet */
#define  IRQ_UT3_OUT_CMP1_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp1StsSet */
#define  IRQ_UT3_OUT_CMP1_STS_SET(x)                        (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1StsSet in register */
#define  GET_IRQ_UT3_OUT_CMP1_STS_SET(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1StsSet from register */
#define  IRQ_UT3_OUT_CMP2_STS_SET_SHIFT                     10                            /**< Shift for IRQUT3OutCmp2StsSet */
#define  IRQ_UT3_OUT_CMP2_STS_SET_MASK                      0x00000400u                   /**< Mask for IRQUT3OutCmp2StsSet */
#define  IRQ_UT3_OUT_CMP2_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp2StsSet */
#define  IRQ_UT3_OUT_CMP2_STS_SET(x)                        (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2StsSet in register */
#define  GET_IRQ_UT3_OUT_CMP2_STS_SET(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2StsSet from register */
#define  IRQ_UT3_OUT_CMP3_STS_SET_SHIFT                     11                            /**< Shift for IRQUT3OutCmp3StsSet */
#define  IRQ_UT3_OUT_CMP3_STS_SET_MASK                      0x00000800u                   /**< Mask for IRQUT3OutCmp3StsSet */
#define  IRQ_UT3_OUT_CMP3_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp3StsSet */
#define  IRQ_UT3_OUT_CMP3_STS_SET(x)                        (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3StsSet in register */
#define  GET_IRQ_UT3_OUT_CMP3_STS_SET(reg)                  (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3StsSet from register */
#define  IRQ_UT3_FULL_VAL_STS_SET_SHIFT                     12                            /**< Shift for IRQUT3FullValStsSet */
#define  IRQ_UT3_FULL_VAL_STS_SET_MASK                      0x00001000u                   /**< Mask for IRQUT3FullValStsSet */
#define  IRQ_UT3_FULL_VAL_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQUT3FullValStsSet */
#define  IRQ_UT3_FULL_VAL_STS_SET(x)                        (((x)&0x1u)<<12)              /**< Set IRQUT3FullValStsSet in register */
#define  GET_IRQ_UT3_FULL_VAL_STS_SET(reg)                  (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValStsSet from register */
#define  IRQ_UT3_IN_CPT_STS_SET_SHIFT                       13                            /**< Shift for IRQUT3InCptStsSet */
#define  IRQ_UT3_IN_CPT_STS_SET_MASK                        0x00002000u                   /**< Mask for IRQUT3InCptStsSet */
#define  IRQ_UT3_IN_CPT_STS_SET_BMASK                       0x1u                          /**< Base mask for IRQUT3InCptStsSet */
#define  IRQ_UT3_IN_CPT_STS_SET(x)                          (((x)&0x1u)<<13)              /**< Set IRQUT3InCptStsSet in register */
#define  GET_IRQ_UT3_IN_CPT_STS_SET(reg)                    (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptStsSet from register */
/** @} */


/**
 * @name RegIRQUniTimStsClr
 * @{
 */
// RegIRQUniTimStsClr.r32
#define  REG_IRQ_UNI_TIM_STS_CLR_RESET_VALUE                0x00000000u                   /**< Reset value of RegIRQUniTimStsClr */
#define  REG_IRQ_UNI_TIM_STS_CLR_MASK                       0x00003F3Fu                   /**< Mask for RegIRQUniTimStsClr */

#define  IRQ_UT2_OUT_CMP0_STS_CLR_SHIFT                     0                             /**< Shift for IRQUT2OutCmp0StsClr */
#define  IRQ_UT2_OUT_CMP0_STS_CLR_MASK                      0x00000001u                   /**< Mask for IRQUT2OutCmp0StsClr */
#define  IRQ_UT2_OUT_CMP0_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp0StsClr */
#define  IRQ_UT2_OUT_CMP0_STS_CLR(x)                        (((x)&0x1u)<<0)               /**< Set IRQUT2OutCmp0StsClr in register */
#define  GET_IRQ_UT2_OUT_CMP0_STS_CLR(reg)                  (((reg)>>0)&0x1u)             /**< Get IRQUT2OutCmp0StsClr from register */
#define  IRQ_UT2_OUT_CMP1_STS_CLR_SHIFT                     1                             /**< Shift for IRQUT2OutCmp1StsClr */
#define  IRQ_UT2_OUT_CMP1_STS_CLR_MASK                      0x00000002u                   /**< Mask for IRQUT2OutCmp1StsClr */
#define  IRQ_UT2_OUT_CMP1_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp1StsClr */
#define  IRQ_UT2_OUT_CMP1_STS_CLR(x)                        (((x)&0x1u)<<1)               /**< Set IRQUT2OutCmp1StsClr in register */
#define  GET_IRQ_UT2_OUT_CMP1_STS_CLR(reg)                  (((reg)>>1)&0x1u)             /**< Get IRQUT2OutCmp1StsClr from register */
#define  IRQ_UT2_OUT_CMP2_STS_CLR_SHIFT                     2                             /**< Shift for IRQUT2OutCmp2StsClr */
#define  IRQ_UT2_OUT_CMP2_STS_CLR_MASK                      0x00000004u                   /**< Mask for IRQUT2OutCmp2StsClr */
#define  IRQ_UT2_OUT_CMP2_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp2StsClr */
#define  IRQ_UT2_OUT_CMP2_STS_CLR(x)                        (((x)&0x1u)<<2)               /**< Set IRQUT2OutCmp2StsClr in register */
#define  GET_IRQ_UT2_OUT_CMP2_STS_CLR(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQUT2OutCmp2StsClr from register */
#define  IRQ_UT2_OUT_CMP3_STS_CLR_SHIFT                     3                             /**< Shift for IRQUT2OutCmp3StsClr */
#define  IRQ_UT2_OUT_CMP3_STS_CLR_MASK                      0x00000008u                   /**< Mask for IRQUT2OutCmp3StsClr */
#define  IRQ_UT2_OUT_CMP3_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2OutCmp3StsClr */
#define  IRQ_UT2_OUT_CMP3_STS_CLR(x)                        (((x)&0x1u)<<3)               /**< Set IRQUT2OutCmp3StsClr in register */
#define  GET_IRQ_UT2_OUT_CMP3_STS_CLR(reg)                  (((reg)>>3)&0x1u)             /**< Get IRQUT2OutCmp3StsClr from register */
#define  IRQ_UT2_FULL_VAL_STS_CLR_SHIFT                     4                             /**< Shift for IRQUT2FullValStsClr */
#define  IRQ_UT2_FULL_VAL_STS_CLR_MASK                      0x00000010u                   /**< Mask for IRQUT2FullValStsClr */
#define  IRQ_UT2_FULL_VAL_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT2FullValStsClr */
#define  IRQ_UT2_FULL_VAL_STS_CLR(x)                        (((x)&0x1u)<<4)               /**< Set IRQUT2FullValStsClr in register */
#define  GET_IRQ_UT2_FULL_VAL_STS_CLR(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQUT2FullValStsClr from register */
#define  IRQ_UT2_IN_CPT_STS_CLR_SHIFT                       5                             /**< Shift for IRQUT2InCptStsClr */
#define  IRQ_UT2_IN_CPT_STS_CLR_MASK                        0x00000020u                   /**< Mask for IRQUT2InCptStsClr */
#define  IRQ_UT2_IN_CPT_STS_CLR_BMASK                       0x1u                          /**< Base mask for IRQUT2InCptStsClr */
#define  IRQ_UT2_IN_CPT_STS_CLR(x)                          (((x)&0x1u)<<5)               /**< Set IRQUT2InCptStsClr in register */
#define  GET_IRQ_UT2_IN_CPT_STS_CLR(reg)                    (((reg)>>5)&0x1u)             /**< Get IRQUT2InCptStsClr from register */
#define  IRQ_UT3_OUT_CMP0_STS_CLR_SHIFT                     8                             /**< Shift for IRQUT3OutCmp0StsClr */
#define  IRQ_UT3_OUT_CMP0_STS_CLR_MASK                      0x00000100u                   /**< Mask for IRQUT3OutCmp0StsClr */
#define  IRQ_UT3_OUT_CMP0_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp0StsClr */
#define  IRQ_UT3_OUT_CMP0_STS_CLR(x)                        (((x)&0x1u)<<8)               /**< Set IRQUT3OutCmp0StsClr in register */
#define  GET_IRQ_UT3_OUT_CMP0_STS_CLR(reg)                  (((reg)>>8)&0x1u)             /**< Get IRQUT3OutCmp0StsClr from register */
#define  IRQ_UT3_OUT_CMP1_STS_CLR_SHIFT                     9                             /**< Shift for IRQUT3OutCmp1StsClr */
#define  IRQ_UT3_OUT_CMP1_STS_CLR_MASK                      0x00000200u                   /**< Mask for IRQUT3OutCmp1StsClr */
#define  IRQ_UT3_OUT_CMP1_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp1StsClr */
#define  IRQ_UT3_OUT_CMP1_STS_CLR(x)                        (((x)&0x1u)<<9)               /**< Set IRQUT3OutCmp1StsClr in register */
#define  GET_IRQ_UT3_OUT_CMP1_STS_CLR(reg)                  (((reg)>>9)&0x1u)             /**< Get IRQUT3OutCmp1StsClr from register */
#define  IRQ_UT3_OUT_CMP2_STS_CLR_SHIFT                     10                            /**< Shift for IRQUT3OutCmp2StsClr */
#define  IRQ_UT3_OUT_CMP2_STS_CLR_MASK                      0x00000400u                   /**< Mask for IRQUT3OutCmp2StsClr */
#define  IRQ_UT3_OUT_CMP2_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp2StsClr */
#define  IRQ_UT3_OUT_CMP2_STS_CLR(x)                        (((x)&0x1u)<<10)              /**< Set IRQUT3OutCmp2StsClr in register */
#define  GET_IRQ_UT3_OUT_CMP2_STS_CLR(reg)                  (((reg)>>10)&0x1u)            /**< Get IRQUT3OutCmp2StsClr from register */
#define  IRQ_UT3_OUT_CMP3_STS_CLR_SHIFT                     11                            /**< Shift for IRQUT3OutCmp3StsClr */
#define  IRQ_UT3_OUT_CMP3_STS_CLR_MASK                      0x00000800u                   /**< Mask for IRQUT3OutCmp3StsClr */
#define  IRQ_UT3_OUT_CMP3_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3OutCmp3StsClr */
#define  IRQ_UT3_OUT_CMP3_STS_CLR(x)                        (((x)&0x1u)<<11)              /**< Set IRQUT3OutCmp3StsClr in register */
#define  GET_IRQ_UT3_OUT_CMP3_STS_CLR(reg)                  (((reg)>>11)&0x1u)            /**< Get IRQUT3OutCmp3StsClr from register */
#define  IRQ_UT3_FULL_VAL_STS_CLR_SHIFT                     12                            /**< Shift for IRQUT3FullValStsClr */
#define  IRQ_UT3_FULL_VAL_STS_CLR_MASK                      0x00001000u                   /**< Mask for IRQUT3FullValStsClr */
#define  IRQ_UT3_FULL_VAL_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQUT3FullValStsClr */
#define  IRQ_UT3_FULL_VAL_STS_CLR(x)                        (((x)&0x1u)<<12)              /**< Set IRQUT3FullValStsClr in register */
#define  GET_IRQ_UT3_FULL_VAL_STS_CLR(reg)                  (((reg)>>12)&0x1u)            /**< Get IRQUT3FullValStsClr from register */
#define  IRQ_UT3_IN_CPT_STS_CLR_SHIFT                       13                            /**< Shift for IRQUT3InCptStsClr */
#define  IRQ_UT3_IN_CPT_STS_CLR_MASK                        0x00002000u                   /**< Mask for IRQUT3InCptStsClr */
#define  IRQ_UT3_IN_CPT_STS_CLR_BMASK                       0x1u                          /**< Base mask for IRQUT3InCptStsClr */
#define  IRQ_UT3_IN_CPT_STS_CLR(x)                          (((x)&0x1u)<<13)              /**< Set IRQUT3InCptStsClr in register */
#define  GET_IRQ_UT3_IN_CPT_STS_CLR(reg)                    (((reg)>>13)&0x1u)            /**< Get IRQUT3InCptStsClr from register */
/** @} */


/**
 * @name RegIRQSPIMEn
 * @{
 */
// RegIRQSPIMEn.r32
#define  REG_IRQ_SPIM_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQSPIMEn */
#define  REG_IRQ_SPIM_EN_MASK                               0x00000001u                   /**< Mask for RegIRQSPIMEn */

#define  IRQ_SPIM_EN_SHIFT                                  0                             /**< Shift for IRQSPIMEn */
#define  IRQ_SPIM_EN_MASK                                   0x00000001u                   /**< Mask for IRQSPIMEn */
#define  IRQ_SPIM_EN_BMASK                                  0x1u                          /**< Base mask for IRQSPIMEn */
#define  IRQ_SPIM_EN(x)                                     (((x)&0x1u)<<0)               /**< Set IRQSPIMEn in register */
#define  GET_IRQ_SPIM_EN(reg)                               (((reg)>>0)&0x1u)             /**< Get IRQSPIMEn from register */
/** @} */


/**
 * @name RegIRQSPIMEnSet
 * @{
 */
// RegIRQSPIMEnSet.r32
#define  REG_IRQ_SPIM_EN_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSPIMEnSet */
#define  REG_IRQ_SPIM_EN_SET_MASK                           0x00000001u                   /**< Mask for RegIRQSPIMEnSet */

#define  IRQ_SPIM_EN_SET_SHIFT                              0                             /**< Shift for IRQSPIMEnSet */
#define  IRQ_SPIM_EN_SET_MASK                               0x00000001u                   /**< Mask for IRQSPIMEnSet */
#define  IRQ_SPIM_EN_SET_BMASK                              0x1u                          /**< Base mask for IRQSPIMEnSet */
#define  IRQ_SPIM_EN_SET(x)                                 (((x)&0x1u)<<0)               /**< Set IRQSPIMEnSet in register */
#define  GET_IRQ_SPIM_EN_SET(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQSPIMEnSet from register */
/** @} */


/**
 * @name RegIRQSPIMEnClr
 * @{
 */
// RegIRQSPIMEnClr.r32
#define  REG_IRQ_SPIM_EN_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSPIMEnClr */
#define  REG_IRQ_SPIM_EN_CLR_MASK                           0x00000001u                   /**< Mask for RegIRQSPIMEnClr */

#define  IRQ_SPIM_EN_CLR_SHIFT                              0                             /**< Shift for IRQSPIMEnClr */
#define  IRQ_SPIM_EN_CLR_MASK                               0x00000001u                   /**< Mask for IRQSPIMEnClr */
#define  IRQ_SPIM_EN_CLR_BMASK                              0x1u                          /**< Base mask for IRQSPIMEnClr */
#define  IRQ_SPIM_EN_CLR(x)                                 (((x)&0x1u)<<0)               /**< Set IRQSPIMEnClr in register */
#define  GET_IRQ_SPIM_EN_CLR(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQSPIMEnClr from register */
/** @} */


/**
 * @name RegIRQSPIMMsk
 * @{
 */
// RegIRQSPIMMsk.r32
#define  REG_IRQ_SPIM_MSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQSPIMMsk */
#define  REG_IRQ_SPIM_MSK_MASK                              0x00000001u                   /**< Mask for RegIRQSPIMMsk */

#define  IRQ_SPIM_MSK_SHIFT                                 0                             /**< Shift for IRQSPIMMsk */
#define  IRQ_SPIM_MSK_MASK                                  0x00000001u                   /**< Mask for IRQSPIMMsk */
#define  IRQ_SPIM_MSK_BMASK                                 0x1u                          /**< Base mask for IRQSPIMMsk */
#define  IRQ_SPIM_MSK(x)                                    (((x)&0x1u)<<0)               /**< Set IRQSPIMMsk in register */
#define  GET_IRQ_SPIM_MSK(reg)                              (((reg)>>0)&0x1u)             /**< Get IRQSPIMMsk from register */
/** @} */


/**
 * @name RegIRQSPIMMskSet
 * @{
 */
// RegIRQSPIMMskSet.r32
#define  REG_IRQ_SPIM_MSK_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPIMMskSet */
#define  REG_IRQ_SPIM_MSK_SET_MASK                          0x00000001u                   /**< Mask for RegIRQSPIMMskSet */

#define  IRQ_SPIM_MSK_SET_SHIFT                             0                             /**< Shift for IRQSPIMMskSet */
#define  IRQ_SPIM_MSK_SET_MASK                              0x00000001u                   /**< Mask for IRQSPIMMskSet */
#define  IRQ_SPIM_MSK_SET_BMASK                             0x1u                          /**< Base mask for IRQSPIMMskSet */
#define  IRQ_SPIM_MSK_SET(x)                                (((x)&0x1u)<<0)               /**< Set IRQSPIMMskSet in register */
#define  GET_IRQ_SPIM_MSK_SET(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQSPIMMskSet from register */
/** @} */


/**
 * @name RegIRQSPIMMskClr
 * @{
 */
// RegIRQSPIMMskClr.r32
#define  REG_IRQ_SPIM_MSK_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPIMMskClr */
#define  REG_IRQ_SPIM_MSK_CLR_MASK                          0x00000001u                   /**< Mask for RegIRQSPIMMskClr */

#define  IRQ_SPIM_MSK_CLR_SHIFT                             0                             /**< Shift for IRQSPIMMskClr */
#define  IRQ_SPIM_MSK_CLR_MASK                              0x00000001u                   /**< Mask for IRQSPIMMskClr */
#define  IRQ_SPIM_MSK_CLR_BMASK                             0x1u                          /**< Base mask for IRQSPIMMskClr */
#define  IRQ_SPIM_MSK_CLR(x)                                (((x)&0x1u)<<0)               /**< Set IRQSPIMMskClr in register */
#define  GET_IRQ_SPIM_MSK_CLR(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQSPIMMskClr from register */
/** @} */


/**
 * @name RegIRQSPIMSts
 * @{
 */
// RegIRQSPIMSts.r32
#define  REG_IRQ_SPIM_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIRQSPIMSts */
#define  REG_IRQ_SPIM_STS_MASK                              0x00000001u                   /**< Mask for RegIRQSPIMSts */

#define  IRQ_SPIM_STS_SHIFT                                 0                             /**< Shift for IRQSPIMSts */
#define  IRQ_SPIM_STS_MASK                                  0x00000001u                   /**< Mask for IRQSPIMSts */
#define  IRQ_SPIM_STS_BMASK                                 0x1u                          /**< Base mask for IRQSPIMSts */
#define  IRQ_SPIM_STS(x)                                    (((x)&0x1u)<<0)               /**< Set IRQSPIMSts in register */
#define  GET_IRQ_SPIM_STS(reg)                              (((reg)>>0)&0x1u)             /**< Get IRQSPIMSts from register */
/** @} */


/**
 * @name RegIRQSPIMStsSet
 * @{
 */
// RegIRQSPIMStsSet.r32
#define  REG_IRQ_SPIM_STS_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPIMStsSet */
#define  REG_IRQ_SPIM_STS_SET_MASK                          0x00000001u                   /**< Mask for RegIRQSPIMStsSet */

#define  IRQ_SPIM_STS_SET_SHIFT                             0                             /**< Shift for IRQSPIMStsSet */
#define  IRQ_SPIM_STS_SET_MASK                              0x00000001u                   /**< Mask for IRQSPIMStsSet */
#define  IRQ_SPIM_STS_SET_BMASK                             0x1u                          /**< Base mask for IRQSPIMStsSet */
#define  IRQ_SPIM_STS_SET(x)                                (((x)&0x1u)<<0)               /**< Set IRQSPIMStsSet in register */
#define  GET_IRQ_SPIM_STS_SET(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQSPIMStsSet from register */
/** @} */


/**
 * @name RegIRQSPIMStsClr
 * @{
 */
// RegIRQSPIMStsClr.r32
#define  REG_IRQ_SPIM_STS_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIRQSPIMStsClr */
#define  REG_IRQ_SPIM_STS_CLR_MASK                          0x00000001u                   /**< Mask for RegIRQSPIMStsClr */

#define  IRQ_SPIM_STS_CLR_SHIFT                             0                             /**< Shift for IRQSPIMStsClr */
#define  IRQ_SPIM_STS_CLR_MASK                              0x00000001u                   /**< Mask for IRQSPIMStsClr */
#define  IRQ_SPIM_STS_CLR_BMASK                             0x1u                          /**< Base mask for IRQSPIMStsClr */
#define  IRQ_SPIM_STS_CLR(x)                                (((x)&0x1u)<<0)               /**< Set IRQSPIMStsClr in register */
#define  GET_IRQ_SPIM_STS_CLR(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQSPIMStsClr from register */
/** @} */


/**
 * @name RegIRQI2CEn
 * @{
 */
// RegIRQI2CEn.r32
#define  REG_IRQ_I2C_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIRQI2CEn */
#define  REG_IRQ_I2C_EN_MASK                                0x00000001u                   /**< Mask for RegIRQI2CEn */

#define  IRQ_I2C_EN_SHIFT                                   0                             /**< Shift for IRQI2CEn */
#define  IRQ_I2C_EN_MASK                                    0x00000001u                   /**< Mask for IRQI2CEn */
#define  IRQ_I2C_EN_BMASK                                   0x1u                          /**< Base mask for IRQI2CEn */
#define  IRQ_I2C_EN(x)                                      (((x)&0x1u)<<0)               /**< Set IRQI2CEn in register */
#define  GET_IRQ_I2C_EN(reg)                                (((reg)>>0)&0x1u)             /**< Get IRQI2CEn from register */
/** @} */


/**
 * @name RegIRQI2CEnSet
 * @{
 */
// RegIRQI2CEnSet.r32
#define  REG_IRQ_I2C_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQI2CEnSet */
#define  REG_IRQ_I2C_EN_SET_MASK                            0x00000001u                   /**< Mask for RegIRQI2CEnSet */

#define  IRQ_I2C_EN_SET_SHIFT                               0                             /**< Shift for IRQI2CEnSet */
#define  IRQ_I2C_EN_SET_MASK                                0x00000001u                   /**< Mask for IRQI2CEnSet */
#define  IRQ_I2C_EN_SET_BMASK                               0x1u                          /**< Base mask for IRQI2CEnSet */
#define  IRQ_I2C_EN_SET(x)                                  (((x)&0x1u)<<0)               /**< Set IRQI2CEnSet in register */
#define  GET_IRQ_I2C_EN_SET(reg)                            (((reg)>>0)&0x1u)             /**< Get IRQI2CEnSet from register */
/** @} */


/**
 * @name RegIRQI2CEnClr
 * @{
 */
// RegIRQI2CEnClr.r32
#define  REG_IRQ_I2C_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQI2CEnClr */
#define  REG_IRQ_I2C_EN_CLR_MASK                            0x00000001u                   /**< Mask for RegIRQI2CEnClr */

#define  IRQ_I2C_EN_CLR_SHIFT                               0                             /**< Shift for IRQI2CEnClr */
#define  IRQ_I2C_EN_CLR_MASK                                0x00000001u                   /**< Mask for IRQI2CEnClr */
#define  IRQ_I2C_EN_CLR_BMASK                               0x1u                          /**< Base mask for IRQI2CEnClr */
#define  IRQ_I2C_EN_CLR(x)                                  (((x)&0x1u)<<0)               /**< Set IRQI2CEnClr in register */
#define  GET_IRQ_I2C_EN_CLR(reg)                            (((reg)>>0)&0x1u)             /**< Get IRQI2CEnClr from register */
/** @} */


/**
 * @name RegIRQI2CMsk
 * @{
 */
// RegIRQI2CMsk.r32
#define  REG_IRQ_I2C_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQI2CMsk */
#define  REG_IRQ_I2C_MSK_MASK                               0x00000001u                   /**< Mask for RegIRQI2CMsk */

#define  IRQ_I2C_MSK_SHIFT                                  0                             /**< Shift for IRQI2CMsk */
#define  IRQ_I2C_MSK_MASK                                   0x00000001u                   /**< Mask for IRQI2CMsk */
#define  IRQ_I2C_MSK_BMASK                                  0x1u                          /**< Base mask for IRQI2CMsk */
#define  IRQ_I2C_MSK(x)                                     (((x)&0x1u)<<0)               /**< Set IRQI2CMsk in register */
#define  GET_IRQ_I2C_MSK(reg)                               (((reg)>>0)&0x1u)             /**< Get IRQI2CMsk from register */
/** @} */


/**
 * @name RegIRQI2CMskSet
 * @{
 */
// RegIRQI2CMskSet.r32
#define  REG_IRQ_I2C_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQI2CMskSet */
#define  REG_IRQ_I2C_MSK_SET_MASK                           0x00000001u                   /**< Mask for RegIRQI2CMskSet */

#define  IRQ_I2C_MSK_SET_SHIFT                              0                             /**< Shift for IRQI2CMskSet */
#define  IRQ_I2C_MSK_SET_MASK                               0x00000001u                   /**< Mask for IRQI2CMskSet */
#define  IRQ_I2C_MSK_SET_BMASK                              0x1u                          /**< Base mask for IRQI2CMskSet */
#define  IRQ_I2C_MSK_SET(x)                                 (((x)&0x1u)<<0)               /**< Set IRQI2CMskSet in register */
#define  GET_IRQ_I2C_MSK_SET(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQI2CMskSet from register */
/** @} */


/**
 * @name RegIRQI2CMskClr
 * @{
 */
// RegIRQI2CMskClr.r32
#define  REG_IRQ_I2C_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQI2CMskClr */
#define  REG_IRQ_I2C_MSK_CLR_MASK                           0x00000001u                   /**< Mask for RegIRQI2CMskClr */

#define  IRQ_I2C_MSK_CLR_SHIFT                              0                             /**< Shift for IRQI2CMskClr */
#define  IRQ_I2C_MSK_CLR_MASK                               0x00000001u                   /**< Mask for IRQI2CMskClr */
#define  IRQ_I2C_MSK_CLR_BMASK                              0x1u                          /**< Base mask for IRQI2CMskClr */
#define  IRQ_I2C_MSK_CLR(x)                                 (((x)&0x1u)<<0)               /**< Set IRQI2CMskClr in register */
#define  GET_IRQ_I2C_MSK_CLR(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQI2CMskClr from register */
/** @} */


/**
 * @name RegIRQI2CSts
 * @{
 */
// RegIRQI2CSts.r32
#define  REG_IRQ_I2C_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQI2CSts */
#define  REG_IRQ_I2C_STS_MASK                               0x00000001u                   /**< Mask for RegIRQI2CSts */

#define  IRQ_I2C_STS_SHIFT                                  0                             /**< Shift for IRQI2CSts */
#define  IRQ_I2C_STS_MASK                                   0x00000001u                   /**< Mask for IRQI2CSts */
#define  IRQ_I2C_STS_BMASK                                  0x1u                          /**< Base mask for IRQI2CSts */
#define  IRQ_I2C_STS(x)                                     (((x)&0x1u)<<0)               /**< Set IRQI2CSts in register */
#define  GET_IRQ_I2C_STS(reg)                               (((reg)>>0)&0x1u)             /**< Get IRQI2CSts from register */
/** @} */


/**
 * @name RegIRQI2CStsSet
 * @{
 */
// RegIRQI2CStsSet.r32
#define  REG_IRQ_I2C_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQI2CStsSet */
#define  REG_IRQ_I2C_STS_SET_MASK                           0x00000001u                   /**< Mask for RegIRQI2CStsSet */

#define  IRQ_I2C_STS_SET_SHIFT                              0                             /**< Shift for IRQI2CStsSet */
#define  IRQ_I2C_STS_SET_MASK                               0x00000001u                   /**< Mask for IRQI2CStsSet */
#define  IRQ_I2C_STS_SET_BMASK                              0x1u                          /**< Base mask for IRQI2CStsSet */
#define  IRQ_I2C_STS_SET(x)                                 (((x)&0x1u)<<0)               /**< Set IRQI2CStsSet in register */
#define  GET_IRQ_I2C_STS_SET(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQI2CStsSet from register */
/** @} */


/**
 * @name RegIRQI2CStsClr
 * @{
 */
// RegIRQI2CStsClr.r32
#define  REG_IRQ_I2C_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQI2CStsClr */
#define  REG_IRQ_I2C_STS_CLR_MASK                           0x00000001u                   /**< Mask for RegIRQI2CStsClr */

#define  IRQ_I2C_STS_CLR_SHIFT                              0                             /**< Shift for IRQI2CStsClr */
#define  IRQ_I2C_STS_CLR_MASK                               0x00000001u                   /**< Mask for IRQI2CStsClr */
#define  IRQ_I2C_STS_CLR_BMASK                              0x1u                          /**< Base mask for IRQI2CStsClr */
#define  IRQ_I2C_STS_CLR(x)                                 (((x)&0x1u)<<0)               /**< Set IRQI2CStsClr in register */
#define  GET_IRQ_I2C_STS_CLR(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQI2CStsClr from register */
/** @} */


/**
 * @name RegIRQRCCalEn
 * @{
 */
// RegIRQRCCalEn.r32
#define  REG_IRQ_RC_CAL_EN_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRCCalEn */
#define  REG_IRQ_RC_CAL_EN_MASK                             0x00000001u                   /**< Mask for RegIRQRCCalEn */

#define  IRQ_RC_CAL_DONE_EN_SHIFT                           0                             /**< Shift for IRQRCCalDoneEn */
#define  IRQ_RC_CAL_DONE_EN_MASK                            0x00000001u                   /**< Mask for IRQRCCalDoneEn */
#define  IRQ_RC_CAL_DONE_EN_BMASK                           0x1u                          /**< Base mask for IRQRCCalDoneEn */
#define  IRQ_RC_CAL_DONE_EN(x)                              (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneEn in register */
#define  GET_IRQ_RC_CAL_DONE_EN(reg)                        (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneEn from register */
/** @} */


/**
 * @name RegIRQRCCalEnSet
 * @{
 */
// RegIRQRCCalEnSet.r32
#define  REG_IRQ_RC_CAL_EN_SET_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIRQRCCalEnSet */
#define  REG_IRQ_RC_CAL_EN_SET_MASK                         0x00000001u                   /**< Mask for RegIRQRCCalEnSet */

#define  IRQ_RC_CAL_DONE_EN_SET_SHIFT                       0                             /**< Shift for IRQRCCalDoneEnSet */
#define  IRQ_RC_CAL_DONE_EN_SET_MASK                        0x00000001u                   /**< Mask for IRQRCCalDoneEnSet */
#define  IRQ_RC_CAL_DONE_EN_SET_BMASK                       0x1u                          /**< Base mask for IRQRCCalDoneEnSet */
#define  IRQ_RC_CAL_DONE_EN_SET(x)                          (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneEnSet in register */
#define  GET_IRQ_RC_CAL_DONE_EN_SET(reg)                    (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneEnSet from register */
/** @} */


/**
 * @name RegIRQRCCalEnClr
 * @{
 */
// RegIRQRCCalEnClr.r32
#define  REG_IRQ_RC_CAL_EN_CLR_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIRQRCCalEnClr */
#define  REG_IRQ_RC_CAL_EN_CLR_MASK                         0x00000001u                   /**< Mask for RegIRQRCCalEnClr */

#define  IRQ_RC_CAL_DONE_EN_CLR_SHIFT                       0                             /**< Shift for IRQRCCalDoneEnClr */
#define  IRQ_RC_CAL_DONE_EN_CLR_MASK                        0x00000001u                   /**< Mask for IRQRCCalDoneEnClr */
#define  IRQ_RC_CAL_DONE_EN_CLR_BMASK                       0x1u                          /**< Base mask for IRQRCCalDoneEnClr */
#define  IRQ_RC_CAL_DONE_EN_CLR(x)                          (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneEnClr in register */
#define  GET_IRQ_RC_CAL_DONE_EN_CLR(reg)                    (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneEnClr from register */
/** @} */


/**
 * @name RegIRQRCCalMsk
 * @{
 */
// RegIRQRCCalMsk.r32
#define  REG_IRQ_RC_CAL_MSK_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRCCalMsk */
#define  REG_IRQ_RC_CAL_MSK_MASK                            0x00000001u                   /**< Mask for RegIRQRCCalMsk */

#define  IRQ_RC_CAL_DONE_MSK_SHIFT                          0                             /**< Shift for IRQRCCalDoneMsk */
#define  IRQ_RC_CAL_DONE_MSK_MASK                           0x00000001u                   /**< Mask for IRQRCCalDoneMsk */
#define  IRQ_RC_CAL_DONE_MSK_BMASK                          0x1u                          /**< Base mask for IRQRCCalDoneMsk */
#define  IRQ_RC_CAL_DONE_MSK(x)                             (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneMsk in register */
#define  GET_IRQ_RC_CAL_DONE_MSK(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneMsk from register */
/** @} */


/**
 * @name RegIRQRCCalMskSet
 * @{
 */
// RegIRQRCCalMskSet.r32
#define  REG_IRQ_RC_CAL_MSK_SET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQRCCalMskSet */
#define  REG_IRQ_RC_CAL_MSK_SET_MASK                        0x00000001u                   /**< Mask for RegIRQRCCalMskSet */

#define  IRQ_RC_CAL_DONE_MSK_SET_SHIFT                      0                             /**< Shift for IRQRCCalDoneMskSet */
#define  IRQ_RC_CAL_DONE_MSK_SET_MASK                       0x00000001u                   /**< Mask for IRQRCCalDoneMskSet */
#define  IRQ_RC_CAL_DONE_MSK_SET_BMASK                      0x1u                          /**< Base mask for IRQRCCalDoneMskSet */
#define  IRQ_RC_CAL_DONE_MSK_SET(x)                         (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneMskSet in register */
#define  GET_IRQ_RC_CAL_DONE_MSK_SET(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneMskSet from register */
/** @} */


/**
 * @name RegIRQRCCalMskClr
 * @{
 */
// RegIRQRCCalMskClr.r32
#define  REG_IRQ_RC_CAL_MSK_CLR_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQRCCalMskClr */
#define  REG_IRQ_RC_CAL_MSK_CLR_MASK                        0x00000001u                   /**< Mask for RegIRQRCCalMskClr */

#define  IRQ_RC_CAL_DONE_MSK_CLR_SHIFT                      0                             /**< Shift for IRQRCCalDoneMskClr */
#define  IRQ_RC_CAL_DONE_MSK_CLR_MASK                       0x00000001u                   /**< Mask for IRQRCCalDoneMskClr */
#define  IRQ_RC_CAL_DONE_MSK_CLR_BMASK                      0x1u                          /**< Base mask for IRQRCCalDoneMskClr */
#define  IRQ_RC_CAL_DONE_MSK_CLR(x)                         (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneMskClr in register */
#define  GET_IRQ_RC_CAL_DONE_MSK_CLR(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneMskClr from register */
/** @} */


/**
 * @name RegIRQRCCalSts
 * @{
 */
// RegIRQRCCalSts.r32
#define  REG_IRQ_RC_CAL_STS_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQRCCalSts */
#define  REG_IRQ_RC_CAL_STS_MASK                            0x00000001u                   /**< Mask for RegIRQRCCalSts */

#define  IRQ_RC_CAL_DONE_STS_SHIFT                          0                             /**< Shift for IRQRCCalDoneSts */
#define  IRQ_RC_CAL_DONE_STS_MASK                           0x00000001u                   /**< Mask for IRQRCCalDoneSts */
#define  IRQ_RC_CAL_DONE_STS_BMASK                          0x1u                          /**< Base mask for IRQRCCalDoneSts */
#define  IRQ_RC_CAL_DONE_STS(x)                             (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneSts in register */
#define  GET_IRQ_RC_CAL_DONE_STS(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneSts from register */
/** @} */


/**
 * @name RegIRQRCCalStsSet
 * @{
 */
// RegIRQRCCalStsSet.r32
#define  REG_IRQ_RC_CAL_STS_SET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQRCCalStsSet */
#define  REG_IRQ_RC_CAL_STS_SET_MASK                        0x00000001u                   /**< Mask for RegIRQRCCalStsSet */

#define  IRQ_RC_CAL_DONE_STS_SET_SHIFT                      0                             /**< Shift for IRQRCCalDoneStsSet */
#define  IRQ_RC_CAL_DONE_STS_SET_MASK                       0x00000001u                   /**< Mask for IRQRCCalDoneStsSet */
#define  IRQ_RC_CAL_DONE_STS_SET_BMASK                      0x1u                          /**< Base mask for IRQRCCalDoneStsSet */
#define  IRQ_RC_CAL_DONE_STS_SET(x)                         (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneStsSet in register */
#define  GET_IRQ_RC_CAL_DONE_STS_SET(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneStsSet from register */
/** @} */


/**
 * @name RegIRQRCCalStsClr
 * @{
 */
// RegIRQRCCalStsClr.r32
#define  REG_IRQ_RC_CAL_STS_CLR_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIRQRCCalStsClr */
#define  REG_IRQ_RC_CAL_STS_CLR_MASK                        0x00000001u                   /**< Mask for RegIRQRCCalStsClr */

#define  IRQ_RC_CAL_DONE_STS_CLR_SHIFT                      0                             /**< Shift for IRQRCCalDoneStsClr */
#define  IRQ_RC_CAL_DONE_STS_CLR_MASK                       0x00000001u                   /**< Mask for IRQRCCalDoneStsClr */
#define  IRQ_RC_CAL_DONE_STS_CLR_BMASK                      0x1u                          /**< Base mask for IRQRCCalDoneStsClr */
#define  IRQ_RC_CAL_DONE_STS_CLR(x)                         (((x)&0x1u)<<0)               /**< Set IRQRCCalDoneStsClr in register */
#define  GET_IRQ_RC_CAL_DONE_STS_CLR(reg)                   (((reg)>>0)&0x1u)             /**< Get IRQRCCalDoneStsClr from register */
/** @} */


/**
 * @name RegIrqAdcEn
 * @{
 */
// RegIrqAdcEn.r32
#define  REG_IRQ_ADC_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIrqAdcEn */
#define  REG_IRQ_ADC_EN_MASK                                0x00000001u                   /**< Mask for RegIrqAdcEn */

#define  IRQ_ADC_DONE_EN_SHIFT                              0                             /**< Shift for IrqAdcDoneEn */
#define  IRQ_ADC_DONE_EN_MASK                               0x00000001u                   /**< Mask for IrqAdcDoneEn */
#define  IRQ_ADC_DONE_EN_BMASK                              0x1u                          /**< Base mask for IrqAdcDoneEn */
#define  IRQ_ADC_DONE_EN(x)                                 (((x)&0x1u)<<0)               /**< Set IrqAdcDoneEn in register */
#define  GET_IRQ_ADC_DONE_EN(reg)                           (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneEn from register */
/** @} */


/**
 * @name RegIrqAdcEnSet
 * @{
 */
// RegIrqAdcEnSet.r32
#define  REG_IRQ_ADC_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqAdcEnSet */
#define  REG_IRQ_ADC_EN_SET_MASK                            0x00000001u                   /**< Mask for RegIrqAdcEnSet */

#define  IRQ_ADC_DONE_EN_SET_SHIFT                          0                             /**< Shift for IrqAdcDoneEnSet */
#define  IRQ_ADC_DONE_EN_SET_MASK                           0x00000001u                   /**< Mask for IrqAdcDoneEnSet */
#define  IRQ_ADC_DONE_EN_SET_BMASK                          0x1u                          /**< Base mask for IrqAdcDoneEnSet */
#define  IRQ_ADC_DONE_EN_SET(x)                             (((x)&0x1u)<<0)               /**< Set IrqAdcDoneEnSet in register */
#define  GET_IRQ_ADC_DONE_EN_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneEnSet from register */
/** @} */


/**
 * @name RegIrqAdcEnClr
 * @{
 */
// RegIrqAdcEnClr.r32
#define  REG_IRQ_ADC_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqAdcEnClr */
#define  REG_IRQ_ADC_EN_CLR_MASK                            0x00000001u                   /**< Mask for RegIrqAdcEnClr */

#define  IRQ_ADC_DONE_EN_CLR_SHIFT                          0                             /**< Shift for IrqAdcDoneEnClr */
#define  IRQ_ADC_DONE_EN_CLR_MASK                           0x00000001u                   /**< Mask for IrqAdcDoneEnClr */
#define  IRQ_ADC_DONE_EN_CLR_BMASK                          0x1u                          /**< Base mask for IrqAdcDoneEnClr */
#define  IRQ_ADC_DONE_EN_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IrqAdcDoneEnClr in register */
#define  GET_IRQ_ADC_DONE_EN_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneEnClr from register */
/** @} */


/**
 * @name RegIrqAdcMsk
 * @{
 */
// RegIrqAdcMsk.r32
#define  REG_IRQ_ADC_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqAdcMsk */
#define  REG_IRQ_ADC_MSK_MASK                               0x00000001u                   /**< Mask for RegIrqAdcMsk */

#define  IRQ_ADC_DONE_MSK_SHIFT                             0                             /**< Shift for IrqAdcDoneMsk */
#define  IRQ_ADC_DONE_MSK_MASK                              0x00000001u                   /**< Mask for IrqAdcDoneMsk */
#define  IRQ_ADC_DONE_MSK_BMASK                             0x1u                          /**< Base mask for IrqAdcDoneMsk */
#define  IRQ_ADC_DONE_MSK(x)                                (((x)&0x1u)<<0)               /**< Set IrqAdcDoneMsk in register */
#define  GET_IRQ_ADC_DONE_MSK(reg)                          (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneMsk from register */
/** @} */


/**
 * @name RegIrqAdcMskSet
 * @{
 */
// RegIrqAdcMskSet.r32
#define  REG_IRQ_ADC_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqAdcMskSet */
#define  REG_IRQ_ADC_MSK_SET_MASK                           0x00000001u                   /**< Mask for RegIrqAdcMskSet */

#define  IRQ_ADC_DONE_MSK_SET_SHIFT                         0                             /**< Shift for IrqAdcDoneMskSet */
#define  IRQ_ADC_DONE_MSK_SET_MASK                          0x00000001u                   /**< Mask for IrqAdcDoneMskSet */
#define  IRQ_ADC_DONE_MSK_SET_BMASK                         0x1u                          /**< Base mask for IrqAdcDoneMskSet */
#define  IRQ_ADC_DONE_MSK_SET(x)                            (((x)&0x1u)<<0)               /**< Set IrqAdcDoneMskSet in register */
#define  GET_IRQ_ADC_DONE_MSK_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneMskSet from register */
/** @} */


/**
 * @name RegIrqAdcMskClr
 * @{
 */
// RegIrqAdcMskClr.r32
#define  REG_IRQ_ADC_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqAdcMskClr */
#define  REG_IRQ_ADC_MSK_CLR_MASK                           0x00000001u                   /**< Mask for RegIrqAdcMskClr */

#define  IRQ_ADC_DONE_MSK_CLR_SHIFT                         0                             /**< Shift for IrqAdcDoneMskClr */
#define  IRQ_ADC_DONE_MSK_CLR_MASK                          0x00000001u                   /**< Mask for IrqAdcDoneMskClr */
#define  IRQ_ADC_DONE_MSK_CLR_BMASK                         0x1u                          /**< Base mask for IrqAdcDoneMskClr */
#define  IRQ_ADC_DONE_MSK_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IrqAdcDoneMskClr in register */
#define  GET_IRQ_ADC_DONE_MSK_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneMskClr from register */
/** @} */


/**
 * @name RegIrqAdcSts
 * @{
 */
// RegIrqAdcSts.r32
#define  REG_IRQ_ADC_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqAdcSts */
#define  REG_IRQ_ADC_STS_MASK                               0x00000001u                   /**< Mask for RegIrqAdcSts */

#define  IRQ_ADC_DONE_STS_SHIFT                             0                             /**< Shift for IrqAdcDoneSts */
#define  IRQ_ADC_DONE_STS_MASK                              0x00000001u                   /**< Mask for IrqAdcDoneSts */
#define  IRQ_ADC_DONE_STS_BMASK                             0x1u                          /**< Base mask for IrqAdcDoneSts */
#define  IRQ_ADC_DONE_STS(x)                                (((x)&0x1u)<<0)               /**< Set IrqAdcDoneSts in register */
#define  GET_IRQ_ADC_DONE_STS(reg)                          (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneSts from register */
/** @} */


/**
 * @name RegIrqAdcStsSet
 * @{
 */
// RegIrqAdcStsSet.r32
#define  REG_IRQ_ADC_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqAdcStsSet */
#define  REG_IRQ_ADC_STS_SET_MASK                           0x00000001u                   /**< Mask for RegIrqAdcStsSet */

#define  IRQ_ADC_DONE_STS_SET_SHIFT                         0                             /**< Shift for IrqAdcDoneStsSet */
#define  IRQ_ADC_DONE_STS_SET_MASK                          0x00000001u                   /**< Mask for IrqAdcDoneStsSet */
#define  IRQ_ADC_DONE_STS_SET_BMASK                         0x1u                          /**< Base mask for IrqAdcDoneStsSet */
#define  IRQ_ADC_DONE_STS_SET(x)                            (((x)&0x1u)<<0)               /**< Set IrqAdcDoneStsSet in register */
#define  GET_IRQ_ADC_DONE_STS_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneStsSet from register */
/** @} */


/**
 * @name RegIrqAdcStsClr
 * @{
 */
// RegIrqAdcStsClr.r32
#define  REG_IRQ_ADC_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqAdcStsClr */
#define  REG_IRQ_ADC_STS_CLR_MASK                           0x00000001u                   /**< Mask for RegIrqAdcStsClr */

#define  IRQ_ADC_DONE_STS_CLR_SHIFT                         0                             /**< Shift for IrqAdcDoneStsClr */
#define  IRQ_ADC_DONE_STS_CLR_MASK                          0x00000001u                   /**< Mask for IrqAdcDoneStsClr */
#define  IRQ_ADC_DONE_STS_CLR_BMASK                         0x1u                          /**< Base mask for IrqAdcDoneStsClr */
#define  IRQ_ADC_DONE_STS_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IrqAdcDoneStsClr in register */
#define  GET_IRQ_ADC_DONE_STS_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqAdcDoneStsClr from register */
/** @} */


/**
 * @name RegIRQPMLEn
 * @{
 */
// RegIRQPMLEn.r32
#define  REG_IRQ_PML_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIRQPMLEn */
#define  REG_IRQ_PML_EN_MASK                                0x0000001Fu                   /**< Mask for RegIRQPMLEn */

#define  IRQ_PML_SVLD_EN_SHIFT                              0                             /**< Shift for IRQPMLSVLDEn */
#define  IRQ_PML_SVLD_EN_MASK                               0x00000001u                   /**< Mask for IRQPMLSVLDEn */
#define  IRQ_PML_SVLD_EN_BMASK                              0x1u                          /**< Base mask for IRQPMLSVLDEn */
#define  IRQ_PML_SVLD_EN(x)                                 (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDEn in register */
#define  GET_IRQ_PML_SVLD_EN(reg)                           (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDEn from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_SHIFT                    1                             /**< Shift for IRQPMLHFXTALActiveEn */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_MASK                     0x00000002u                   /**< Mask for IRQPMLHFXTALActiveEn */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_BMASK                    0x1u                          /**< Base mask for IRQPMLHFXTALActiveEn */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN(x)                       (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveEn in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_EN(reg)                 (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveEn from register */
#define  IRQ_PML_HF_RC_ACTIVE_EN_SHIFT                      2                             /**< Shift for IRQPMLHFRCActiveEn */
#define  IRQ_PML_HF_RC_ACTIVE_EN_MASK                       0x00000004u                   /**< Mask for IRQPMLHFRCActiveEn */
#define  IRQ_PML_HF_RC_ACTIVE_EN_BMASK                      0x1u                          /**< Base mask for IRQPMLHFRCActiveEn */
#define  IRQ_PML_HF_RC_ACTIVE_EN(x)                         (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveEn in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_EN(reg)                   (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveEn from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_SHIFT                    3                             /**< Shift for IRQPMLLFXTALActiveEn */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_MASK                     0x00000008u                   /**< Mask for IRQPMLLFXTALActiveEn */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_BMASK                    0x1u                          /**< Base mask for IRQPMLLFXTALActiveEn */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN(x)                       (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveEn in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_EN(reg)                 (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveEn from register */
#define  IRQ_PWR_MET_DONE_EN_SHIFT                          4                             /**< Shift for IRQPwrMetDoneEn */
#define  IRQ_PWR_MET_DONE_EN_MASK                           0x00000010u                   /**< Mask for IRQPwrMetDoneEn */
#define  IRQ_PWR_MET_DONE_EN_BMASK                          0x1u                          /**< Base mask for IRQPwrMetDoneEn */
#define  IRQ_PWR_MET_DONE_EN(x)                             (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneEn in register */
#define  GET_IRQ_PWR_MET_DONE_EN(reg)                       (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneEn from register */
/** @} */


/**
 * @name RegIRQPMLEnSet
 * @{
 */
// RegIRQPMLEnSet.r32
#define  REG_IRQ_PML_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQPMLEnSet */
#define  REG_IRQ_PML_EN_SET_MASK                            0x0000001Fu                   /**< Mask for RegIRQPMLEnSet */

#define  IRQ_PML_SVLD_EN_SET_SHIFT                          0                             /**< Shift for IRQPMLSVLDEnSet */
#define  IRQ_PML_SVLD_EN_SET_MASK                           0x00000001u                   /**< Mask for IRQPMLSVLDEnSet */
#define  IRQ_PML_SVLD_EN_SET_BMASK                          0x1u                          /**< Base mask for IRQPMLSVLDEnSet */
#define  IRQ_PML_SVLD_EN_SET(x)                             (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDEnSet in register */
#define  GET_IRQ_PML_SVLD_EN_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDEnSet from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_SET_SHIFT                1                             /**< Shift for IRQPMLHFXTALActiveEnSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_SET_MASK                 0x00000002u                   /**< Mask for IRQPMLHFXTALActiveEnSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_SET_BMASK                0x1u                          /**< Base mask for IRQPMLHFXTALActiveEnSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_SET(x)                   (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveEnSet in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_EN_SET(reg)             (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveEnSet from register */
#define  IRQ_PML_HF_RC_ACTIVE_EN_SET_SHIFT                  2                             /**< Shift for IRQPMLHFRCActiveEnSet */
#define  IRQ_PML_HF_RC_ACTIVE_EN_SET_MASK                   0x00000004u                   /**< Mask for IRQPMLHFRCActiveEnSet */
#define  IRQ_PML_HF_RC_ACTIVE_EN_SET_BMASK                  0x1u                          /**< Base mask for IRQPMLHFRCActiveEnSet */
#define  IRQ_PML_HF_RC_ACTIVE_EN_SET(x)                     (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveEnSet in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_EN_SET(reg)               (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveEnSet from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_SET_SHIFT                3                             /**< Shift for IRQPMLLFXTALActiveEnSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_SET_MASK                 0x00000008u                   /**< Mask for IRQPMLLFXTALActiveEnSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_SET_BMASK                0x1u                          /**< Base mask for IRQPMLLFXTALActiveEnSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_SET(x)                   (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveEnSet in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_EN_SET(reg)             (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveEnSet from register */
#define  IRQ_PWR_MET_DONE_EN_SET_SHIFT                      4                             /**< Shift for IRQPwrMetDoneEnSet */
#define  IRQ_PWR_MET_DONE_EN_SET_MASK                       0x00000010u                   /**< Mask for IRQPwrMetDoneEnSet */
#define  IRQ_PWR_MET_DONE_EN_SET_BMASK                      0x1u                          /**< Base mask for IRQPwrMetDoneEnSet */
#define  IRQ_PWR_MET_DONE_EN_SET(x)                         (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneEnSet in register */
#define  GET_IRQ_PWR_MET_DONE_EN_SET(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneEnSet from register */
/** @} */


/**
 * @name RegIRQPMLEnClr
 * @{
 */
// RegIRQPMLEnClr.r32
#define  REG_IRQ_PML_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIRQPMLEnClr */
#define  REG_IRQ_PML_EN_CLR_MASK                            0x0000001Fu                   /**< Mask for RegIRQPMLEnClr */

#define  IRQ_PML_SVLD_EN_CLR_SHIFT                          0                             /**< Shift for IRQPMLSVLDEnClr */
#define  IRQ_PML_SVLD_EN_CLR_MASK                           0x00000001u                   /**< Mask for IRQPMLSVLDEnClr */
#define  IRQ_PML_SVLD_EN_CLR_BMASK                          0x1u                          /**< Base mask for IRQPMLSVLDEnClr */
#define  IRQ_PML_SVLD_EN_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDEnClr in register */
#define  GET_IRQ_PML_SVLD_EN_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDEnClr from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_CLR_SHIFT                1                             /**< Shift for IRQPMLHFXTALActiveEnClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_CLR_MASK                 0x00000002u                   /**< Mask for IRQPMLHFXTALActiveEnClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQPMLHFXTALActiveEnClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_EN_CLR(x)                   (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveEnClr in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_EN_CLR(reg)             (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveEnClr from register */
#define  IRQ_PML_HF_RC_ACTIVE_EN_CLR_SHIFT                  2                             /**< Shift for IRQPMLHFRCActiveEnClr */
#define  IRQ_PML_HF_RC_ACTIVE_EN_CLR_MASK                   0x00000004u                   /**< Mask for IRQPMLHFRCActiveEnClr */
#define  IRQ_PML_HF_RC_ACTIVE_EN_CLR_BMASK                  0x1u                          /**< Base mask for IRQPMLHFRCActiveEnClr */
#define  IRQ_PML_HF_RC_ACTIVE_EN_CLR(x)                     (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveEnClr in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_EN_CLR(reg)               (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveEnClr from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_CLR_SHIFT                3                             /**< Shift for IRQPMLLFXTALActiveEnClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_CLR_MASK                 0x00000008u                   /**< Mask for IRQPMLLFXTALActiveEnClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_CLR_BMASK                0x1u                          /**< Base mask for IRQPMLLFXTALActiveEnClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_EN_CLR(x)                   (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveEnClr in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_EN_CLR(reg)             (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveEnClr from register */
#define  IRQ_PWR_MET_DONE_EN_CLR_SHIFT                      4                             /**< Shift for IRQPwrMetDoneEnClr */
#define  IRQ_PWR_MET_DONE_EN_CLR_MASK                       0x00000010u                   /**< Mask for IRQPwrMetDoneEnClr */
#define  IRQ_PWR_MET_DONE_EN_CLR_BMASK                      0x1u                          /**< Base mask for IRQPwrMetDoneEnClr */
#define  IRQ_PWR_MET_DONE_EN_CLR(x)                         (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneEnClr in register */
#define  GET_IRQ_PWR_MET_DONE_EN_CLR(reg)                   (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneEnClr from register */
/** @} */


/**
 * @name RegIRQPMLMsk
 * @{
 */
// RegIRQPMLMsk.r32
#define  REG_IRQ_PML_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQPMLMsk */
#define  REG_IRQ_PML_MSK_MASK                               0x0000001Fu                   /**< Mask for RegIRQPMLMsk */

#define  IRQ_PML_SVLD_MSK_SHIFT                             0                             /**< Shift for IRQPMLSVLDMsk */
#define  IRQ_PML_SVLD_MSK_MASK                              0x00000001u                   /**< Mask for IRQPMLSVLDMsk */
#define  IRQ_PML_SVLD_MSK_BMASK                             0x1u                          /**< Base mask for IRQPMLSVLDMsk */
#define  IRQ_PML_SVLD_MSK(x)                                (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDMsk in register */
#define  GET_IRQ_PML_SVLD_MSK(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDMsk from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_SHIFT                   1                             /**< Shift for IRQPMLHFXTALActiveMsk */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_MASK                    0x00000002u                   /**< Mask for IRQPMLHFXTALActiveMsk */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_BMASK                   0x1u                          /**< Base mask for IRQPMLHFXTALActiveMsk */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK(x)                      (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveMsk in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_MSK(reg)                (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveMsk from register */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_SHIFT                     2                             /**< Shift for IRQPMLHFRCActiveMsk */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_MASK                      0x00000004u                   /**< Mask for IRQPMLHFRCActiveMsk */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_BMASK                     0x1u                          /**< Base mask for IRQPMLHFRCActiveMsk */
#define  IRQ_PML_HF_RC_ACTIVE_MSK(x)                        (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveMsk in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_MSK(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveMsk from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_SHIFT                   3                             /**< Shift for IRQPMLLFXTALActiveMsk */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_MASK                    0x00000008u                   /**< Mask for IRQPMLLFXTALActiveMsk */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_BMASK                   0x1u                          /**< Base mask for IRQPMLLFXTALActiveMsk */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK(x)                      (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveMsk in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_MSK(reg)                (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveMsk from register */
#define  IRQ_PWR_MET_DONE_MSK_SHIFT                         4                             /**< Shift for IRQPwrMetDoneMsk */
#define  IRQ_PWR_MET_DONE_MSK_MASK                          0x00000010u                   /**< Mask for IRQPwrMetDoneMsk */
#define  IRQ_PWR_MET_DONE_MSK_BMASK                         0x1u                          /**< Base mask for IRQPwrMetDoneMsk */
#define  IRQ_PWR_MET_DONE_MSK(x)                            (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneMsk in register */
#define  GET_IRQ_PWR_MET_DONE_MSK(reg)                      (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneMsk from register */
/** @} */


/**
 * @name RegIRQPMLMskSet
 * @{
 */
// RegIRQPMLMskSet.r32
#define  REG_IRQ_PML_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQPMLMskSet */
#define  REG_IRQ_PML_MSK_SET_MASK                           0x0000001Fu                   /**< Mask for RegIRQPMLMskSet */

#define  IRQ_PML_SVLD_MSK_SET_SHIFT                         0                             /**< Shift for IRQPMLSVLDMskSet */
#define  IRQ_PML_SVLD_MSK_SET_MASK                          0x00000001u                   /**< Mask for IRQPMLSVLDMskSet */
#define  IRQ_PML_SVLD_MSK_SET_BMASK                         0x1u                          /**< Base mask for IRQPMLSVLDMskSet */
#define  IRQ_PML_SVLD_MSK_SET(x)                            (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDMskSet in register */
#define  GET_IRQ_PML_SVLD_MSK_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDMskSet from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_SET_SHIFT               1                             /**< Shift for IRQPMLHFXTALActiveMskSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_SET_MASK                0x00000002u                   /**< Mask for IRQPMLHFXTALActiveMskSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQPMLHFXTALActiveMskSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveMskSet in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_MSK_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveMskSet from register */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_SET_SHIFT                 2                             /**< Shift for IRQPMLHFRCActiveMskSet */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_SET_MASK                  0x00000004u                   /**< Mask for IRQPMLHFRCActiveMskSet */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_SET_BMASK                 0x1u                          /**< Base mask for IRQPMLHFRCActiveMskSet */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_SET(x)                    (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveMskSet in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_MSK_SET(reg)              (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveMskSet from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_SET_SHIFT               3                             /**< Shift for IRQPMLLFXTALActiveMskSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_SET_MASK                0x00000008u                   /**< Mask for IRQPMLLFXTALActiveMskSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_SET_BMASK               0x1u                          /**< Base mask for IRQPMLLFXTALActiveMskSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveMskSet in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_MSK_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveMskSet from register */
#define  IRQ_PWR_MET_DONE_MSK_SET_SHIFT                     4                             /**< Shift for IRQPwrMetDoneMskSet */
#define  IRQ_PWR_MET_DONE_MSK_SET_MASK                      0x00000010u                   /**< Mask for IRQPwrMetDoneMskSet */
#define  IRQ_PWR_MET_DONE_MSK_SET_BMASK                     0x1u                          /**< Base mask for IRQPwrMetDoneMskSet */
#define  IRQ_PWR_MET_DONE_MSK_SET(x)                        (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneMskSet in register */
#define  GET_IRQ_PWR_MET_DONE_MSK_SET(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneMskSet from register */
/** @} */


/**
 * @name RegIRQPMLMskClr
 * @{
 */
// RegIRQPMLMskClr.r32
#define  REG_IRQ_PML_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQPMLMskClr */
#define  REG_IRQ_PML_MSK_CLR_MASK                           0x0000001Fu                   /**< Mask for RegIRQPMLMskClr */

#define  IRQ_PML_SVLD_MSK_CLR_SHIFT                         0                             /**< Shift for IRQPMLSVLDMskClr */
#define  IRQ_PML_SVLD_MSK_CLR_MASK                          0x00000001u                   /**< Mask for IRQPMLSVLDMskClr */
#define  IRQ_PML_SVLD_MSK_CLR_BMASK                         0x1u                          /**< Base mask for IRQPMLSVLDMskClr */
#define  IRQ_PML_SVLD_MSK_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDMskClr in register */
#define  GET_IRQ_PML_SVLD_MSK_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDMskClr from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_CLR_SHIFT               1                             /**< Shift for IRQPMLHFXTALActiveMskClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_CLR_MASK                0x00000002u                   /**< Mask for IRQPMLHFXTALActiveMskClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQPMLHFXTALActiveMskClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_MSK_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveMskClr in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_MSK_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveMskClr from register */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_CLR_SHIFT                 2                             /**< Shift for IRQPMLHFRCActiveMskClr */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_CLR_MASK                  0x00000004u                   /**< Mask for IRQPMLHFRCActiveMskClr */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IRQPMLHFRCActiveMskClr */
#define  IRQ_PML_HF_RC_ACTIVE_MSK_CLR(x)                    (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveMskClr in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_MSK_CLR(reg)              (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveMskClr from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_CLR_SHIFT               3                             /**< Shift for IRQPMLLFXTALActiveMskClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_CLR_MASK                0x00000008u                   /**< Mask for IRQPMLLFXTALActiveMskClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_CLR_BMASK               0x1u                          /**< Base mask for IRQPMLLFXTALActiveMskClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_MSK_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveMskClr in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_MSK_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveMskClr from register */
#define  IRQ_PWR_MET_DONE_MSK_CLR_SHIFT                     4                             /**< Shift for IRQPwrMetDoneMskClr */
#define  IRQ_PWR_MET_DONE_MSK_CLR_MASK                      0x00000010u                   /**< Mask for IRQPwrMetDoneMskClr */
#define  IRQ_PWR_MET_DONE_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IRQPwrMetDoneMskClr */
#define  IRQ_PWR_MET_DONE_MSK_CLR(x)                        (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneMskClr in register */
#define  GET_IRQ_PWR_MET_DONE_MSK_CLR(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneMskClr from register */
/** @} */


/**
 * @name RegIRQPMLSts
 * @{
 */
// RegIRQPMLSts.r32
#define  REG_IRQ_PML_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQPMLSts */
#define  REG_IRQ_PML_STS_MASK                               0x0000001Fu                   /**< Mask for RegIRQPMLSts */

#define  IRQ_PML_SVLD_STS_SHIFT                             0                             /**< Shift for IRQPMLSVLDSts */
#define  IRQ_PML_SVLD_STS_MASK                              0x00000001u                   /**< Mask for IRQPMLSVLDSts */
#define  IRQ_PML_SVLD_STS_BMASK                             0x1u                          /**< Base mask for IRQPMLSVLDSts */
#define  IRQ_PML_SVLD_STS(x)                                (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDSts in register */
#define  GET_IRQ_PML_SVLD_STS(reg)                          (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDSts from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_SHIFT                   1                             /**< Shift for IRQPMLHFXTALActiveSts */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_MASK                    0x00000002u                   /**< Mask for IRQPMLHFXTALActiveSts */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_BMASK                   0x1u                          /**< Base mask for IRQPMLHFXTALActiveSts */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS(x)                      (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveSts in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_STS(reg)                (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveSts from register */
#define  IRQ_PML_HF_RC_ACTIVE_STS_SHIFT                     2                             /**< Shift for IRQPMLHFRCActiveSts */
#define  IRQ_PML_HF_RC_ACTIVE_STS_MASK                      0x00000004u                   /**< Mask for IRQPMLHFRCActiveSts */
#define  IRQ_PML_HF_RC_ACTIVE_STS_BMASK                     0x1u                          /**< Base mask for IRQPMLHFRCActiveSts */
#define  IRQ_PML_HF_RC_ACTIVE_STS(x)                        (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveSts in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_STS(reg)                  (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveSts from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_SHIFT                   3                             /**< Shift for IRQPMLLFXTALActiveSts */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_MASK                    0x00000008u                   /**< Mask for IRQPMLLFXTALActiveSts */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_BMASK                   0x1u                          /**< Base mask for IRQPMLLFXTALActiveSts */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS(x)                      (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveSts in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_STS(reg)                (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveSts from register */
#define  IRQ_PWR_MET_DONE_STS_SHIFT                         4                             /**< Shift for IRQPwrMetDoneSts */
#define  IRQ_PWR_MET_DONE_STS_MASK                          0x00000010u                   /**< Mask for IRQPwrMetDoneSts */
#define  IRQ_PWR_MET_DONE_STS_BMASK                         0x1u                          /**< Base mask for IRQPwrMetDoneSts */
#define  IRQ_PWR_MET_DONE_STS(x)                            (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneSts in register */
#define  GET_IRQ_PWR_MET_DONE_STS(reg)                      (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneSts from register */
/** @} */


/**
 * @name RegIRQPMLStsSet
 * @{
 */
// RegIRQPMLStsSet.r32
#define  REG_IRQ_PML_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQPMLStsSet */
#define  REG_IRQ_PML_STS_SET_MASK                           0x0000001Fu                   /**< Mask for RegIRQPMLStsSet */

#define  IRQ_PML_SVLD_STS_SET_SHIFT                         0                             /**< Shift for IRQPMLSVLDStsSet */
#define  IRQ_PML_SVLD_STS_SET_MASK                          0x00000001u                   /**< Mask for IRQPMLSVLDStsSet */
#define  IRQ_PML_SVLD_STS_SET_BMASK                         0x1u                          /**< Base mask for IRQPMLSVLDStsSet */
#define  IRQ_PML_SVLD_STS_SET(x)                            (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDStsSet in register */
#define  GET_IRQ_PML_SVLD_STS_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDStsSet from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_SET_SHIFT               1                             /**< Shift for IRQPMLHFXTALActiveStsSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_SET_MASK                0x00000002u                   /**< Mask for IRQPMLHFXTALActiveStsSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_SET_BMASK               0x1u                          /**< Base mask for IRQPMLHFXTALActiveStsSet */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_SET(x)                  (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveStsSet in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_STS_SET(reg)            (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveStsSet from register */
#define  IRQ_PML_HF_RC_ACTIVE_STS_SET_SHIFT                 2                             /**< Shift for IRQPMLHFRCActiveStsSet */
#define  IRQ_PML_HF_RC_ACTIVE_STS_SET_MASK                  0x00000004u                   /**< Mask for IRQPMLHFRCActiveStsSet */
#define  IRQ_PML_HF_RC_ACTIVE_STS_SET_BMASK                 0x1u                          /**< Base mask for IRQPMLHFRCActiveStsSet */
#define  IRQ_PML_HF_RC_ACTIVE_STS_SET(x)                    (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveStsSet in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_STS_SET(reg)              (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveStsSet from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_SET_SHIFT               3                             /**< Shift for IRQPMLLFXTALActiveStsSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_SET_MASK                0x00000008u                   /**< Mask for IRQPMLLFXTALActiveStsSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_SET_BMASK               0x1u                          /**< Base mask for IRQPMLLFXTALActiveStsSet */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_SET(x)                  (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveStsSet in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_STS_SET(reg)            (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveStsSet from register */
#define  IRQ_PWR_MET_DONE_STS_SET_SHIFT                     4                             /**< Shift for IRQPwrMetDoneStsSet */
#define  IRQ_PWR_MET_DONE_STS_SET_MASK                      0x00000010u                   /**< Mask for IRQPwrMetDoneStsSet */
#define  IRQ_PWR_MET_DONE_STS_SET_BMASK                     0x1u                          /**< Base mask for IRQPwrMetDoneStsSet */
#define  IRQ_PWR_MET_DONE_STS_SET(x)                        (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneStsSet in register */
#define  GET_IRQ_PWR_MET_DONE_STS_SET(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneStsSet from register */
/** @} */


/**
 * @name RegIRQPMLStsClr
 * @{
 */
// RegIRQPMLStsClr.r32
#define  REG_IRQ_PML_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQPMLStsClr */
#define  REG_IRQ_PML_STS_CLR_MASK                           0x0000001Fu                   /**< Mask for RegIRQPMLStsClr */

#define  IRQ_PML_SVLD_STS_CLR_SHIFT                         0                             /**< Shift for IRQPMLSVLDStsClr */
#define  IRQ_PML_SVLD_STS_CLR_MASK                          0x00000001u                   /**< Mask for IRQPMLSVLDStsClr */
#define  IRQ_PML_SVLD_STS_CLR_BMASK                         0x1u                          /**< Base mask for IRQPMLSVLDStsClr */
#define  IRQ_PML_SVLD_STS_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IRQPMLSVLDStsClr in register */
#define  GET_IRQ_PML_SVLD_STS_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IRQPMLSVLDStsClr from register */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_CLR_SHIFT               1                             /**< Shift for IRQPMLHFXTALActiveStsClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_CLR_MASK                0x00000002u                   /**< Mask for IRQPMLHFXTALActiveStsClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQPMLHFXTALActiveStsClr */
#define  IRQ_PML_HF_XTAL_ACTIVE_STS_CLR(x)                  (((x)&0x1u)<<1)               /**< Set IRQPMLHFXTALActiveStsClr in register */
#define  GET_IRQ_PML_HF_XTAL_ACTIVE_STS_CLR(reg)            (((reg)>>1)&0x1u)             /**< Get IRQPMLHFXTALActiveStsClr from register */
#define  IRQ_PML_HF_RC_ACTIVE_STS_CLR_SHIFT                 2                             /**< Shift for IRQPMLHFRCActiveStsClr */
#define  IRQ_PML_HF_RC_ACTIVE_STS_CLR_MASK                  0x00000004u                   /**< Mask for IRQPMLHFRCActiveStsClr */
#define  IRQ_PML_HF_RC_ACTIVE_STS_CLR_BMASK                 0x1u                          /**< Base mask for IRQPMLHFRCActiveStsClr */
#define  IRQ_PML_HF_RC_ACTIVE_STS_CLR(x)                    (((x)&0x1u)<<2)               /**< Set IRQPMLHFRCActiveStsClr in register */
#define  GET_IRQ_PML_HF_RC_ACTIVE_STS_CLR(reg)              (((reg)>>2)&0x1u)             /**< Get IRQPMLHFRCActiveStsClr from register */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_CLR_SHIFT               3                             /**< Shift for IRQPMLLFXTALActiveStsClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_CLR_MASK                0x00000008u                   /**< Mask for IRQPMLLFXTALActiveStsClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_CLR_BMASK               0x1u                          /**< Base mask for IRQPMLLFXTALActiveStsClr */
#define  IRQ_PML_LF_XTAL_ACTIVE_STS_CLR(x)                  (((x)&0x1u)<<3)               /**< Set IRQPMLLFXTALActiveStsClr in register */
#define  GET_IRQ_PML_LF_XTAL_ACTIVE_STS_CLR(reg)            (((reg)>>3)&0x1u)             /**< Get IRQPMLLFXTALActiveStsClr from register */
#define  IRQ_PWR_MET_DONE_STS_CLR_SHIFT                     4                             /**< Shift for IRQPwrMetDoneStsClr */
#define  IRQ_PWR_MET_DONE_STS_CLR_MASK                      0x00000010u                   /**< Mask for IRQPwrMetDoneStsClr */
#define  IRQ_PWR_MET_DONE_STS_CLR_BMASK                     0x1u                          /**< Base mask for IRQPwrMetDoneStsClr */
#define  IRQ_PWR_MET_DONE_STS_CLR(x)                        (((x)&0x1u)<<4)               /**< Set IRQPwrMetDoneStsClr in register */
#define  GET_IRQ_PWR_MET_DONE_STS_CLR(reg)                  (((reg)>>4)&0x1u)             /**< Get IRQPwrMetDoneStsClr from register */
/** @} */


/**
 * @name RegIrqNvmEn
 * @{
 */
// RegIrqNvmEn.r32
#define  REG_IRQ_NVM_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIrqNvmEn */
#define  REG_IRQ_NVM_EN_MASK                                0x00000001u                   /**< Mask for RegIrqNvmEn */

#define  IRQ_NVM_DONE_EN_SHIFT                              0                             /**< Shift for IrqNvmDoneEn */
#define  IRQ_NVM_DONE_EN_MASK                               0x00000001u                   /**< Mask for IrqNvmDoneEn */
#define  IRQ_NVM_DONE_EN_BMASK                              0x1u                          /**< Base mask for IrqNvmDoneEn */
#define  IRQ_NVM_DONE_EN(x)                                 (((x)&0x1u)<<0)               /**< Set IrqNvmDoneEn in register */
#define  GET_IRQ_NVM_DONE_EN(reg)                           (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneEn from register */
/** @} */


/**
 * @name RegIrqNvmEnSet
 * @{
 */
// RegIrqNvmEnSet.r32
#define  REG_IRQ_NVM_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqNvmEnSet */
#define  REG_IRQ_NVM_EN_SET_MASK                            0x00000001u                   /**< Mask for RegIrqNvmEnSet */

#define  IRQ_NVM_DONE_EN_SET_SHIFT                          0                             /**< Shift for IrqNvmDoneEnSet */
#define  IRQ_NVM_DONE_EN_SET_MASK                           0x00000001u                   /**< Mask for IrqNvmDoneEnSet */
#define  IRQ_NVM_DONE_EN_SET_BMASK                          0x1u                          /**< Base mask for IrqNvmDoneEnSet */
#define  IRQ_NVM_DONE_EN_SET(x)                             (((x)&0x1u)<<0)               /**< Set IrqNvmDoneEnSet in register */
#define  GET_IRQ_NVM_DONE_EN_SET(reg)                       (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneEnSet from register */
/** @} */


/**
 * @name RegIrqNvmEnClr
 * @{
 */
// RegIrqNvmEnClr.r32
#define  REG_IRQ_NVM_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqNvmEnClr */
#define  REG_IRQ_NVM_EN_CLR_MASK                            0x00000001u                   /**< Mask for RegIrqNvmEnClr */

#define  IRQ_NVM_DONE_EN_CLR_SHIFT                          0                             /**< Shift for IrqNvmDoneEnClr */
#define  IRQ_NVM_DONE_EN_CLR_MASK                           0x00000001u                   /**< Mask for IrqNvmDoneEnClr */
#define  IRQ_NVM_DONE_EN_CLR_BMASK                          0x1u                          /**< Base mask for IrqNvmDoneEnClr */
#define  IRQ_NVM_DONE_EN_CLR(x)                             (((x)&0x1u)<<0)               /**< Set IrqNvmDoneEnClr in register */
#define  GET_IRQ_NVM_DONE_EN_CLR(reg)                       (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneEnClr from register */
/** @} */


/**
 * @name RegIrqNvmMsk
 * @{
 */
// RegIrqNvmMsk.r32
#define  REG_IRQ_NVM_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqNvmMsk */
#define  REG_IRQ_NVM_MSK_MASK                               0x00000001u                   /**< Mask for RegIrqNvmMsk */

#define  IRQ_NVM_DONE_MSK_SHIFT                             0                             /**< Shift for IrqNvmDoneMsk */
#define  IRQ_NVM_DONE_MSK_MASK                              0x00000001u                   /**< Mask for IrqNvmDoneMsk */
#define  IRQ_NVM_DONE_MSK_BMASK                             0x1u                          /**< Base mask for IrqNvmDoneMsk */
#define  IRQ_NVM_DONE_MSK(x)                                (((x)&0x1u)<<0)               /**< Set IrqNvmDoneMsk in register */
#define  GET_IRQ_NVM_DONE_MSK(reg)                          (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneMsk from register */
/** @} */


/**
 * @name RegIrqNvmMskSet
 * @{
 */
// RegIrqNvmMskSet.r32
#define  REG_IRQ_NVM_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqNvmMskSet */
#define  REG_IRQ_NVM_MSK_SET_MASK                           0x00000001u                   /**< Mask for RegIrqNvmMskSet */

#define  IRQ_NVM_DONE_MSK_SET_SHIFT                         0                             /**< Shift for IrqNvmDoneMskSet */
#define  IRQ_NVM_DONE_MSK_SET_MASK                          0x00000001u                   /**< Mask for IrqNvmDoneMskSet */
#define  IRQ_NVM_DONE_MSK_SET_BMASK                         0x1u                          /**< Base mask for IrqNvmDoneMskSet */
#define  IRQ_NVM_DONE_MSK_SET(x)                            (((x)&0x1u)<<0)               /**< Set IrqNvmDoneMskSet in register */
#define  GET_IRQ_NVM_DONE_MSK_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneMskSet from register */
/** @} */


/**
 * @name RegIrqNvmMskClr
 * @{
 */
// RegIrqNvmMskClr.r32
#define  REG_IRQ_NVM_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqNvmMskClr */
#define  REG_IRQ_NVM_MSK_CLR_MASK                           0x00000001u                   /**< Mask for RegIrqNvmMskClr */

#define  IRQ_NVM_DONE_MSK_CLR_SHIFT                         0                             /**< Shift for IrqNvmDoneMskClr */
#define  IRQ_NVM_DONE_MSK_CLR_MASK                          0x00000001u                   /**< Mask for IrqNvmDoneMskClr */
#define  IRQ_NVM_DONE_MSK_CLR_BMASK                         0x1u                          /**< Base mask for IrqNvmDoneMskClr */
#define  IRQ_NVM_DONE_MSK_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IrqNvmDoneMskClr in register */
#define  GET_IRQ_NVM_DONE_MSK_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneMskClr from register */
/** @} */


/**
 * @name RegIrqNvmSts
 * @{
 */
// RegIrqNvmSts.r32
#define  REG_IRQ_NVM_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqNvmSts */
#define  REG_IRQ_NVM_STS_MASK                               0x00000001u                   /**< Mask for RegIrqNvmSts */

#define  IRQ_NVM_DONE_STS_SHIFT                             0                             /**< Shift for IrqNvmDoneSts */
#define  IRQ_NVM_DONE_STS_MASK                              0x00000001u                   /**< Mask for IrqNvmDoneSts */
#define  IRQ_NVM_DONE_STS_BMASK                             0x1u                          /**< Base mask for IrqNvmDoneSts */
#define  IRQ_NVM_DONE_STS(x)                                (((x)&0x1u)<<0)               /**< Set IrqNvmDoneSts in register */
#define  GET_IRQ_NVM_DONE_STS(reg)                          (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneSts from register */
/** @} */


/**
 * @name RegIrqNvmStsSet
 * @{
 */
// RegIrqNvmStsSet.r32
#define  REG_IRQ_NVM_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqNvmStsSet */
#define  REG_IRQ_NVM_STS_SET_MASK                           0x00000001u                   /**< Mask for RegIrqNvmStsSet */

#define  IRQ_NVM_DONE_STS_SET_SHIFT                         0                             /**< Shift for IrqNvmDoneStsSet */
#define  IRQ_NVM_DONE_STS_SET_MASK                          0x00000001u                   /**< Mask for IrqNvmDoneStsSet */
#define  IRQ_NVM_DONE_STS_SET_BMASK                         0x1u                          /**< Base mask for IrqNvmDoneStsSet */
#define  IRQ_NVM_DONE_STS_SET(x)                            (((x)&0x1u)<<0)               /**< Set IrqNvmDoneStsSet in register */
#define  GET_IRQ_NVM_DONE_STS_SET(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneStsSet from register */
/** @} */


/**
 * @name RegIrqNvmStsClr
 * @{
 */
// RegIrqNvmStsClr.r32
#define  REG_IRQ_NVM_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqNvmStsClr */
#define  REG_IRQ_NVM_STS_CLR_MASK                           0x00000001u                   /**< Mask for RegIrqNvmStsClr */

#define  IRQ_NVM_DONE_STS_CLR_SHIFT                         0                             /**< Shift for IrqNvmDoneStsClr */
#define  IRQ_NVM_DONE_STS_CLR_MASK                          0x00000001u                   /**< Mask for IrqNvmDoneStsClr */
#define  IRQ_NVM_DONE_STS_CLR_BMASK                         0x1u                          /**< Base mask for IrqNvmDoneStsClr */
#define  IRQ_NVM_DONE_STS_CLR(x)                            (((x)&0x1u)<<0)               /**< Set IrqNvmDoneStsClr in register */
#define  GET_IRQ_NVM_DONE_STS_CLR(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqNvmDoneStsClr from register */
/** @} */


/**
 * @name RegIrqQDecEn
 * @{
 */
// RegIrqQDecEn.r32
#define  REG_IRQ_QDEC_EN_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqQDecEn */
#define  REG_IRQ_QDEC_EN_MASK                               0x00000007u                   /**< Mask for RegIrqQDecEn */

#define  IRQ_QDEC_REP_RDY_EN_SHIFT                          0                             /**< Shift for IrqQDecRepRdyEn */
#define  IRQ_QDEC_REP_RDY_EN_MASK                           0x00000001u                   /**< Mask for IrqQDecRepRdyEn */
#define  IRQ_QDEC_REP_RDY_EN_BMASK                          0x1u                          /**< Base mask for IrqQDecRepRdyEn */
#define  IRQ_QDEC_REP_RDY_EN(x)                             (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyEn in register */
#define  GET_IRQ_QDEC_REP_RDY_EN(reg)                       (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyEn from register */
#define  IRQ_QDEC_OVF_EN_SHIFT                              1                             /**< Shift for IrqQDecOvfEn */
#define  IRQ_QDEC_OVF_EN_MASK                               0x00000002u                   /**< Mask for IrqQDecOvfEn */
#define  IRQ_QDEC_OVF_EN_BMASK                              0x1u                          /**< Base mask for IrqQDecOvfEn */
#define  IRQ_QDEC_OVF_EN(x)                                 (((x)&0x1u)<<1)               /**< Set IrqQDecOvfEn in register */
#define  GET_IRQ_QDEC_OVF_EN(reg)                           (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfEn from register */
#define  IRQ_QDEC_DBL_EN_SHIFT                              2                             /**< Shift for IrqQDecDblEn */
#define  IRQ_QDEC_DBL_EN_MASK                               0x00000004u                   /**< Mask for IrqQDecDblEn */
#define  IRQ_QDEC_DBL_EN_BMASK                              0x1u                          /**< Base mask for IrqQDecDblEn */
#define  IRQ_QDEC_DBL_EN(x)                                 (((x)&0x1u)<<2)               /**< Set IrqQDecDblEn in register */
#define  GET_IRQ_QDEC_DBL_EN(reg)                           (((reg)>>2)&0x1u)             /**< Get IrqQDecDblEn from register */
/** @} */


/**
 * @name RegIrqQDecEnSet
 * @{
 */
// RegIrqQDecEnSet.r32
#define  REG_IRQ_QDEC_EN_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqQDecEnSet */
#define  REG_IRQ_QDEC_EN_SET_MASK                           0x00000007u                   /**< Mask for RegIrqQDecEnSet */

#define  IRQ_QDEC_REP_RDY_EN_SET_SHIFT                      0                             /**< Shift for IrqQDecRepRdyEnSet */
#define  IRQ_QDEC_REP_RDY_EN_SET_MASK                       0x00000001u                   /**< Mask for IrqQDecRepRdyEnSet */
#define  IRQ_QDEC_REP_RDY_EN_SET_BMASK                      0x1u                          /**< Base mask for IrqQDecRepRdyEnSet */
#define  IRQ_QDEC_REP_RDY_EN_SET(x)                         (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyEnSet in register */
#define  GET_IRQ_QDEC_REP_RDY_EN_SET(reg)                   (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyEnSet from register */
#define  IRQ_QDEC_OVF_EN_SET_SHIFT                          1                             /**< Shift for IrqQDecOvfEnSet */
#define  IRQ_QDEC_OVF_EN_SET_MASK                           0x00000002u                   /**< Mask for IrqQDecOvfEnSet */
#define  IRQ_QDEC_OVF_EN_SET_BMASK                          0x1u                          /**< Base mask for IrqQDecOvfEnSet */
#define  IRQ_QDEC_OVF_EN_SET(x)                             (((x)&0x1u)<<1)               /**< Set IrqQDecOvfEnSet in register */
#define  GET_IRQ_QDEC_OVF_EN_SET(reg)                       (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfEnSet from register */
#define  IRQ_QDEC_DBL_EN_SET_SHIFT                          2                             /**< Shift for IrqQDecDblEnSet */
#define  IRQ_QDEC_DBL_EN_SET_MASK                           0x00000004u                   /**< Mask for IrqQDecDblEnSet */
#define  IRQ_QDEC_DBL_EN_SET_BMASK                          0x1u                          /**< Base mask for IrqQDecDblEnSet */
#define  IRQ_QDEC_DBL_EN_SET(x)                             (((x)&0x1u)<<2)               /**< Set IrqQDecDblEnSet in register */
#define  GET_IRQ_QDEC_DBL_EN_SET(reg)                       (((reg)>>2)&0x1u)             /**< Get IrqQDecDblEnSet from register */
/** @} */


/**
 * @name RegIrqQDecEnClr
 * @{
 */
// RegIrqQDecEnClr.r32
#define  REG_IRQ_QDEC_EN_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqQDecEnClr */
#define  REG_IRQ_QDEC_EN_CLR_MASK                           0x00000007u                   /**< Mask for RegIrqQDecEnClr */

#define  IRQ_QDEC_REP_RDY_EN_CLR_SHIFT                      0                             /**< Shift for IrqQDecRepRdyEnClr */
#define  IRQ_QDEC_REP_RDY_EN_CLR_MASK                       0x00000001u                   /**< Mask for IrqQDecRepRdyEnClr */
#define  IRQ_QDEC_REP_RDY_EN_CLR_BMASK                      0x1u                          /**< Base mask for IrqQDecRepRdyEnClr */
#define  IRQ_QDEC_REP_RDY_EN_CLR(x)                         (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyEnClr in register */
#define  GET_IRQ_QDEC_REP_RDY_EN_CLR(reg)                   (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyEnClr from register */
#define  IRQ_QDEC_OVF_EN_CLR_SHIFT                          1                             /**< Shift for IrqQDecOvfEnClr */
#define  IRQ_QDEC_OVF_EN_CLR_MASK                           0x00000002u                   /**< Mask for IrqQDecOvfEnClr */
#define  IRQ_QDEC_OVF_EN_CLR_BMASK                          0x1u                          /**< Base mask for IrqQDecOvfEnClr */
#define  IRQ_QDEC_OVF_EN_CLR(x)                             (((x)&0x1u)<<1)               /**< Set IrqQDecOvfEnClr in register */
#define  GET_IRQ_QDEC_OVF_EN_CLR(reg)                       (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfEnClr from register */
#define  IRQ_QDEC_DBL_EN_CLR_SHIFT                          2                             /**< Shift for IrqQDecDblEnClr */
#define  IRQ_QDEC_DBL_EN_CLR_MASK                           0x00000004u                   /**< Mask for IrqQDecDblEnClr */
#define  IRQ_QDEC_DBL_EN_CLR_BMASK                          0x1u                          /**< Base mask for IrqQDecDblEnClr */
#define  IRQ_QDEC_DBL_EN_CLR(x)                             (((x)&0x1u)<<2)               /**< Set IrqQDecDblEnClr in register */
#define  GET_IRQ_QDEC_DBL_EN_CLR(reg)                       (((reg)>>2)&0x1u)             /**< Get IrqQDecDblEnClr from register */
/** @} */


/**
 * @name RegIrqQDecMsk
 * @{
 */
// RegIrqQDecMsk.r32
#define  REG_IRQ_QDEC_MSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIrqQDecMsk */
#define  REG_IRQ_QDEC_MSK_MASK                              0x00000007u                   /**< Mask for RegIrqQDecMsk */

#define  IRQ_QDEC_REP_RDY_MSK_SHIFT                         0                             /**< Shift for IrqQDecRepRdyMsk */
#define  IRQ_QDEC_REP_RDY_MSK_MASK                          0x00000001u                   /**< Mask for IrqQDecRepRdyMsk */
#define  IRQ_QDEC_REP_RDY_MSK_BMASK                         0x1u                          /**< Base mask for IrqQDecRepRdyMsk */
#define  IRQ_QDEC_REP_RDY_MSK(x)                            (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyMsk in register */
#define  GET_IRQ_QDEC_REP_RDY_MSK(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyMsk from register */
#define  IRQ_QDEC_OVF_MSK_SHIFT                             1                             /**< Shift for IrqQDecOvfMsk */
#define  IRQ_QDEC_OVF_MSK_MASK                              0x00000002u                   /**< Mask for IrqQDecOvfMsk */
#define  IRQ_QDEC_OVF_MSK_BMASK                             0x1u                          /**< Base mask for IrqQDecOvfMsk */
#define  IRQ_QDEC_OVF_MSK(x)                                (((x)&0x1u)<<1)               /**< Set IrqQDecOvfMsk in register */
#define  GET_IRQ_QDEC_OVF_MSK(reg)                          (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfMsk from register */
#define  IRQ_QDEC_DBL_MSK_SHIFT                             2                             /**< Shift for IrqQDecDblMsk */
#define  IRQ_QDEC_DBL_MSK_MASK                              0x00000004u                   /**< Mask for IrqQDecDblMsk */
#define  IRQ_QDEC_DBL_MSK_BMASK                             0x1u                          /**< Base mask for IrqQDecDblMsk */
#define  IRQ_QDEC_DBL_MSK(x)                                (((x)&0x1u)<<2)               /**< Set IrqQDecDblMsk in register */
#define  GET_IRQ_QDEC_DBL_MSK(reg)                          (((reg)>>2)&0x1u)             /**< Get IrqQDecDblMsk from register */
/** @} */


/**
 * @name RegIrqQDecMskSet
 * @{
 */
// RegIrqQDecMskSet.r32
#define  REG_IRQ_QDEC_MSK_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIrqQDecMskSet */
#define  REG_IRQ_QDEC_MSK_SET_MASK                          0x00000007u                   /**< Mask for RegIrqQDecMskSet */

#define  IRQ_QDEC_REP_RDY_MSK_SET_SHIFT                     0                             /**< Shift for IrqQDecRepRdyMskSet */
#define  IRQ_QDEC_REP_RDY_MSK_SET_MASK                      0x00000001u                   /**< Mask for IrqQDecRepRdyMskSet */
#define  IRQ_QDEC_REP_RDY_MSK_SET_BMASK                     0x1u                          /**< Base mask for IrqQDecRepRdyMskSet */
#define  IRQ_QDEC_REP_RDY_MSK_SET(x)                        (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyMskSet in register */
#define  GET_IRQ_QDEC_REP_RDY_MSK_SET(reg)                  (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyMskSet from register */
#define  IRQ_QDEC_OVF_MSK_SET_SHIFT                         1                             /**< Shift for IrqQDecOvfMskSet */
#define  IRQ_QDEC_OVF_MSK_SET_MASK                          0x00000002u                   /**< Mask for IrqQDecOvfMskSet */
#define  IRQ_QDEC_OVF_MSK_SET_BMASK                         0x1u                          /**< Base mask for IrqQDecOvfMskSet */
#define  IRQ_QDEC_OVF_MSK_SET(x)                            (((x)&0x1u)<<1)               /**< Set IrqQDecOvfMskSet in register */
#define  GET_IRQ_QDEC_OVF_MSK_SET(reg)                      (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfMskSet from register */
#define  IRQ_QDEC_DBL_MSK_SET_SHIFT                         2                             /**< Shift for IrqQDecDblMskSet */
#define  IRQ_QDEC_DBL_MSK_SET_MASK                          0x00000004u                   /**< Mask for IrqQDecDblMskSet */
#define  IRQ_QDEC_DBL_MSK_SET_BMASK                         0x1u                          /**< Base mask for IrqQDecDblMskSet */
#define  IRQ_QDEC_DBL_MSK_SET(x)                            (((x)&0x1u)<<2)               /**< Set IrqQDecDblMskSet in register */
#define  GET_IRQ_QDEC_DBL_MSK_SET(reg)                      (((reg)>>2)&0x1u)             /**< Get IrqQDecDblMskSet from register */
/** @} */


/**
 * @name RegIrqQDecMskClr
 * @{
 */
// RegIrqQDecMskClr.r32
#define  REG_IRQ_QDEC_MSK_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIrqQDecMskClr */
#define  REG_IRQ_QDEC_MSK_CLR_MASK                          0x00000007u                   /**< Mask for RegIrqQDecMskClr */

#define  IRQ_QDEC_REP_RDY_MSK_CLR_SHIFT                     0                             /**< Shift for IrqQDecRepRdyMskClr */
#define  IRQ_QDEC_REP_RDY_MSK_CLR_MASK                      0x00000001u                   /**< Mask for IrqQDecRepRdyMskClr */
#define  IRQ_QDEC_REP_RDY_MSK_CLR_BMASK                     0x1u                          /**< Base mask for IrqQDecRepRdyMskClr */
#define  IRQ_QDEC_REP_RDY_MSK_CLR(x)                        (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyMskClr in register */
#define  GET_IRQ_QDEC_REP_RDY_MSK_CLR(reg)                  (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyMskClr from register */
#define  IRQ_QDEC_OVF_MSK_CLR_SHIFT                         1                             /**< Shift for IrqQDecOvfMskClr */
#define  IRQ_QDEC_OVF_MSK_CLR_MASK                          0x00000002u                   /**< Mask for IrqQDecOvfMskClr */
#define  IRQ_QDEC_OVF_MSK_CLR_BMASK                         0x1u                          /**< Base mask for IrqQDecOvfMskClr */
#define  IRQ_QDEC_OVF_MSK_CLR(x)                            (((x)&0x1u)<<1)               /**< Set IrqQDecOvfMskClr in register */
#define  GET_IRQ_QDEC_OVF_MSK_CLR(reg)                      (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfMskClr from register */
#define  IRQ_QDEC_DBL_MSK_CLR_SHIFT                         2                             /**< Shift for IrqQDecDblMskClr */
#define  IRQ_QDEC_DBL_MSK_CLR_MASK                          0x00000004u                   /**< Mask for IrqQDecDblMskClr */
#define  IRQ_QDEC_DBL_MSK_CLR_BMASK                         0x1u                          /**< Base mask for IrqQDecDblMskClr */
#define  IRQ_QDEC_DBL_MSK_CLR(x)                            (((x)&0x1u)<<2)               /**< Set IrqQDecDblMskClr in register */
#define  GET_IRQ_QDEC_DBL_MSK_CLR(reg)                      (((reg)>>2)&0x1u)             /**< Get IrqQDecDblMskClr from register */
/** @} */


/**
 * @name RegIrqQDecSts
 * @{
 */
// RegIrqQDecSts.r32
#define  REG_IRQ_QDEC_STS_RESET_VALUE                       0x00000000u                   /**< Reset value of RegIrqQDecSts */
#define  REG_IRQ_QDEC_STS_MASK                              0x00000007u                   /**< Mask for RegIrqQDecSts */

#define  IRQ_QDEC_REP_RDY_STS_SHIFT                         0                             /**< Shift for IrqQDecRepRdySts */
#define  IRQ_QDEC_REP_RDY_STS_MASK                          0x00000001u                   /**< Mask for IrqQDecRepRdySts */
#define  IRQ_QDEC_REP_RDY_STS_BMASK                         0x1u                          /**< Base mask for IrqQDecRepRdySts */
#define  IRQ_QDEC_REP_RDY_STS(x)                            (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdySts in register */
#define  GET_IRQ_QDEC_REP_RDY_STS(reg)                      (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdySts from register */
#define  IRQ_QDEC_OVF_STS_SHIFT                             1                             /**< Shift for IrqQDecOvfSts */
#define  IRQ_QDEC_OVF_STS_MASK                              0x00000002u                   /**< Mask for IrqQDecOvfSts */
#define  IRQ_QDEC_OVF_STS_BMASK                             0x1u                          /**< Base mask for IrqQDecOvfSts */
#define  IRQ_QDEC_OVF_STS(x)                                (((x)&0x1u)<<1)               /**< Set IrqQDecOvfSts in register */
#define  GET_IRQ_QDEC_OVF_STS(reg)                          (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfSts from register */
#define  IRQ_QDEC_DBL_STS_SHIFT                             2                             /**< Shift for IrqQDecDblSts */
#define  IRQ_QDEC_DBL_STS_MASK                              0x00000004u                   /**< Mask for IrqQDecDblSts */
#define  IRQ_QDEC_DBL_STS_BMASK                             0x1u                          /**< Base mask for IrqQDecDblSts */
#define  IRQ_QDEC_DBL_STS(x)                                (((x)&0x1u)<<2)               /**< Set IrqQDecDblSts in register */
#define  GET_IRQ_QDEC_DBL_STS(reg)                          (((reg)>>2)&0x1u)             /**< Get IrqQDecDblSts from register */
/** @} */


/**
 * @name RegIrqQDecStsSet
 * @{
 */
// RegIrqQDecStsSet.r32
#define  REG_IRQ_QDEC_STS_SET_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIrqQDecStsSet */
#define  REG_IRQ_QDEC_STS_SET_MASK                          0x00000007u                   /**< Mask for RegIrqQDecStsSet */

#define  IRQ_QDEC_REP_RDY_STS_SET_SHIFT                     0                             /**< Shift for IrqQDecRepRdyStsSet */
#define  IRQ_QDEC_REP_RDY_STS_SET_MASK                      0x00000001u                   /**< Mask for IrqQDecRepRdyStsSet */
#define  IRQ_QDEC_REP_RDY_STS_SET_BMASK                     0x1u                          /**< Base mask for IrqQDecRepRdyStsSet */
#define  IRQ_QDEC_REP_RDY_STS_SET(x)                        (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyStsSet in register */
#define  GET_IRQ_QDEC_REP_RDY_STS_SET(reg)                  (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyStsSet from register */
#define  IRQ_QDEC_OVF_STS_SET_SHIFT                         1                             /**< Shift for IrqQDecOvfStsSet */
#define  IRQ_QDEC_OVF_STS_SET_MASK                          0x00000002u                   /**< Mask for IrqQDecOvfStsSet */
#define  IRQ_QDEC_OVF_STS_SET_BMASK                         0x1u                          /**< Base mask for IrqQDecOvfStsSet */
#define  IRQ_QDEC_OVF_STS_SET(x)                            (((x)&0x1u)<<1)               /**< Set IrqQDecOvfStsSet in register */
#define  GET_IRQ_QDEC_OVF_STS_SET(reg)                      (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfStsSet from register */
#define  IRQ_QDEC_DBL_STS_SET_SHIFT                         2                             /**< Shift for IrqQDecDblStsSet */
#define  IRQ_QDEC_DBL_STS_SET_MASK                          0x00000004u                   /**< Mask for IrqQDecDblStsSet */
#define  IRQ_QDEC_DBL_STS_SET_BMASK                         0x1u                          /**< Base mask for IrqQDecDblStsSet */
#define  IRQ_QDEC_DBL_STS_SET(x)                            (((x)&0x1u)<<2)               /**< Set IrqQDecDblStsSet in register */
#define  GET_IRQ_QDEC_DBL_STS_SET(reg)                      (((reg)>>2)&0x1u)             /**< Get IrqQDecDblStsSet from register */
/** @} */


/**
 * @name RegIrqQDecStsClr
 * @{
 */
// RegIrqQDecStsClr.r32
#define  REG_IRQ_QDEC_STS_CLR_RESET_VALUE                   0x00000000u                   /**< Reset value of RegIrqQDecStsClr */
#define  REG_IRQ_QDEC_STS_CLR_MASK                          0x00000007u                   /**< Mask for RegIrqQDecStsClr */

#define  IRQ_QDEC_REP_RDY_STS_CLR_SHIFT                     0                             /**< Shift for IrqQDecRepRdyStsClr */
#define  IRQ_QDEC_REP_RDY_STS_CLR_MASK                      0x00000001u                   /**< Mask for IrqQDecRepRdyStsClr */
#define  IRQ_QDEC_REP_RDY_STS_CLR_BMASK                     0x1u                          /**< Base mask for IrqQDecRepRdyStsClr */
#define  IRQ_QDEC_REP_RDY_STS_CLR(x)                        (((x)&0x1u)<<0)               /**< Set IrqQDecRepRdyStsClr in register */
#define  GET_IRQ_QDEC_REP_RDY_STS_CLR(reg)                  (((reg)>>0)&0x1u)             /**< Get IrqQDecRepRdyStsClr from register */
#define  IRQ_QDEC_OVF_STS_CLR_SHIFT                         1                             /**< Shift for IrqQDecOvfStsClr */
#define  IRQ_QDEC_OVF_STS_CLR_MASK                          0x00000002u                   /**< Mask for IrqQDecOvfStsClr */
#define  IRQ_QDEC_OVF_STS_CLR_BMASK                         0x1u                          /**< Base mask for IrqQDecOvfStsClr */
#define  IRQ_QDEC_OVF_STS_CLR(x)                            (((x)&0x1u)<<1)               /**< Set IrqQDecOvfStsClr in register */
#define  GET_IRQ_QDEC_OVF_STS_CLR(reg)                      (((reg)>>1)&0x1u)             /**< Get IrqQDecOvfStsClr from register */
#define  IRQ_QDEC_DBL_STS_CLR_SHIFT                         2                             /**< Shift for IrqQDecDblStsClr */
#define  IRQ_QDEC_DBL_STS_CLR_MASK                          0x00000004u                   /**< Mask for IrqQDecDblStsClr */
#define  IRQ_QDEC_DBL_STS_CLR_BMASK                         0x1u                          /**< Base mask for IrqQDecDblStsClr */
#define  IRQ_QDEC_DBL_STS_CLR(x)                            (((x)&0x1u)<<2)               /**< Set IrqQDecDblStsClr in register */
#define  GET_IRQ_QDEC_DBL_STS_CLR(reg)                      (((reg)>>2)&0x1u)             /**< Get IrqQDecDblStsClr from register */
/** @} */


/**
 * @name RegIrqUsbEn
 * @{
 */
// RegIrqUsbEn.r32
#define  REG_IRQ_USB_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIrqUsbEn */
#define  REG_IRQ_USB_EN_MASK                                0x0000001Fu                   /**< Mask for RegIrqUsbEn */

#define  IRQ_USB_EN_SHIFT                                   0                             /**< Shift for IrqUsbEn */
#define  IRQ_USB_EN_MASK                                    0x0000001Fu                   /**< Mask for IrqUsbEn */
#define  IRQ_USB_EN_BMASK                                   0x1Fu                         /**< Base mask for IrqUsbEn */
#define  IRQ_USB_EN(x)                                      (((x)&0x1Fu)<<0)              /**< Set IrqUsbEn in register */
#define  GET_IRQ_USB_EN(reg)                                (((reg)>>0)&0x1Fu)            /**< Get IrqUsbEn from register */
/** @} */


/**
 * @name RegIrqUsbEnSet
 * @{
 */
// RegIrqUsbEnSet.r32
#define  REG_IRQ_USB_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqUsbEnSet */
#define  REG_IRQ_USB_EN_SET_MASK                            0x0000001Fu                   /**< Mask for RegIrqUsbEnSet */

#define  IRQ_USB_EN_SET_SHIFT                               0                             /**< Shift for IrqUsbEnSet */
#define  IRQ_USB_EN_SET_MASK                                0x0000001Fu                   /**< Mask for IrqUsbEnSet */
#define  IRQ_USB_EN_SET_BMASK                               0x1Fu                         /**< Base mask for IrqUsbEnSet */
#define  IRQ_USB_EN_SET(x)                                  (((x)&0x1Fu)<<0)              /**< Set IrqUsbEnSet in register */
#define  GET_IRQ_USB_EN_SET(reg)                            (((reg)>>0)&0x1Fu)            /**< Get IrqUsbEnSet from register */
/** @} */


/**
 * @name RegIrqUsbEnClr
 * @{
 */
// RegIrqUsbEnClr.r32
#define  REG_IRQ_USB_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqUsbEnClr */
#define  REG_IRQ_USB_EN_CLR_MASK                            0x0000001Fu                   /**< Mask for RegIrqUsbEnClr */

#define  IRQ_USB_EN_CLR_SHIFT                               0                             /**< Shift for IrqUsbEnClr */
#define  IRQ_USB_EN_CLR_MASK                                0x0000001Fu                   /**< Mask for IrqUsbEnClr */
#define  IRQ_USB_EN_CLR_BMASK                               0x1Fu                         /**< Base mask for IrqUsbEnClr */
#define  IRQ_USB_EN_CLR(x)                                  (((x)&0x1Fu)<<0)              /**< Set IrqUsbEnClr in register */
#define  GET_IRQ_USB_EN_CLR(reg)                            (((reg)>>0)&0x1Fu)            /**< Get IrqUsbEnClr from register */
/** @} */


/**
 * @name RegIrqUsbMsk
 * @{
 */
// RegIrqUsbMsk.r32
#define  REG_IRQ_USB_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqUsbMsk */
#define  REG_IRQ_USB_MSK_MASK                               0x0000001Fu                   /**< Mask for RegIrqUsbMsk */

#define  IRQ_USB_MSK_SHIFT                                  0                             /**< Shift for IrqUsbMsk */
#define  IRQ_USB_MSK_MASK                                   0x0000001Fu                   /**< Mask for IrqUsbMsk */
#define  IRQ_USB_MSK_BMASK                                  0x1Fu                         /**< Base mask for IrqUsbMsk */
#define  IRQ_USB_MSK(x)                                     (((x)&0x1Fu)<<0)              /**< Set IrqUsbMsk in register */
#define  GET_IRQ_USB_MSK(reg)                               (((reg)>>0)&0x1Fu)            /**< Get IrqUsbMsk from register */
/** @} */


/**
 * @name RegIrqUsbMskSet
 * @{
 */
// RegIrqUsbMskSet.r32
#define  REG_IRQ_USB_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqUsbMskSet */
#define  REG_IRQ_USB_MSK_SET_MASK                           0x0000001Fu                   /**< Mask for RegIrqUsbMskSet */

#define  IRQ_USB_MSK_SET_SHIFT                              0                             /**< Shift for IrqUsbMskSet */
#define  IRQ_USB_MSK_SET_MASK                               0x0000001Fu                   /**< Mask for IrqUsbMskSet */
#define  IRQ_USB_MSK_SET_BMASK                              0x1Fu                         /**< Base mask for IrqUsbMskSet */
#define  IRQ_USB_MSK_SET(x)                                 (((x)&0x1Fu)<<0)              /**< Set IrqUsbMskSet in register */
#define  GET_IRQ_USB_MSK_SET(reg)                           (((reg)>>0)&0x1Fu)            /**< Get IrqUsbMskSet from register */
/** @} */


/**
 * @name RegIrqUsbMskClr
 * @{
 */
// RegIrqUsbMskClr.r32
#define  REG_IRQ_USB_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqUsbMskClr */
#define  REG_IRQ_USB_MSK_CLR_MASK                           0x0000001Fu                   /**< Mask for RegIrqUsbMskClr */

#define  IRQ_USB_MSK_CLR_SHIFT                              0                             /**< Shift for IrqUsbMskClr */
#define  IRQ_USB_MSK_CLR_MASK                               0x0000001Fu                   /**< Mask for IrqUsbMskClr */
#define  IRQ_USB_MSK_CLR_BMASK                              0x1Fu                         /**< Base mask for IrqUsbMskClr */
#define  IRQ_USB_MSK_CLR(x)                                 (((x)&0x1Fu)<<0)              /**< Set IrqUsbMskClr in register */
#define  GET_IRQ_USB_MSK_CLR(reg)                           (((reg)>>0)&0x1Fu)            /**< Get IrqUsbMskClr from register */
/** @} */


/**
 * @name RegIrqUsbSts
 * @{
 */
// RegIrqUsbSts.r32
#define  REG_IRQ_USB_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqUsbSts */
#define  REG_IRQ_USB_STS_MASK                               0x0000001Fu                   /**< Mask for RegIrqUsbSts */

#define  IRQ_USB_STS_SHIFT                                  0                             /**< Shift for IrqUsbSts */
#define  IRQ_USB_STS_MASK                                   0x0000001Fu                   /**< Mask for IrqUsbSts */
#define  IRQ_USB_STS_BMASK                                  0x1Fu                         /**< Base mask for IrqUsbSts */
#define  IRQ_USB_STS(x)                                     (((x)&0x1Fu)<<0)              /**< Set IrqUsbSts in register */
#define  GET_IRQ_USB_STS(reg)                               (((reg)>>0)&0x1Fu)            /**< Get IrqUsbSts from register */
/** @} */


/**
 * @name RegIrqUsbStsSet
 * @{
 */
// RegIrqUsbStsSet.r32
#define  REG_IRQ_USB_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqUsbStsSet */
#define  REG_IRQ_USB_STS_SET_MASK                           0x0000001Fu                   /**< Mask for RegIrqUsbStsSet */

#define  IRQ_USB_STS_SET_SHIFT                              0                             /**< Shift for IrqUsbStsSet */
#define  IRQ_USB_STS_SET_MASK                               0x0000001Fu                   /**< Mask for IrqUsbStsSet */
#define  IRQ_USB_STS_SET_BMASK                              0x1Fu                         /**< Base mask for IrqUsbStsSet */
#define  IRQ_USB_STS_SET(x)                                 (((x)&0x1Fu)<<0)              /**< Set IrqUsbStsSet in register */
#define  GET_IRQ_USB_STS_SET(reg)                           (((reg)>>0)&0x1Fu)            /**< Get IrqUsbStsSet from register */
/** @} */


/**
 * @name RegIrqUsbStsClr
 * @{
 */
// RegIrqUsbStsClr.r32
#define  REG_IRQ_USB_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqUsbStsClr */
#define  REG_IRQ_USB_STS_CLR_MASK                           0x0000001Fu                   /**< Mask for RegIrqUsbStsClr */

#define  IRQ_USB_STS_CLR_SHIFT                              0                             /**< Shift for IrqUsbStsClr */
#define  IRQ_USB_STS_CLR_MASK                               0x0000001Fu                   /**< Mask for IrqUsbStsClr */
#define  IRQ_USB_STS_CLR_BMASK                              0x1Fu                         /**< Base mask for IrqUsbStsClr */
#define  IRQ_USB_STS_CLR(x)                                 (((x)&0x1Fu)<<0)              /**< Set IrqUsbStsClr in register */
#define  GET_IRQ_USB_STS_CLR(reg)                           (((reg)>>0)&0x1Fu)            /**< Get IrqUsbStsClr from register */
/** @} */


/**
 * @name RegIrqCryptoEn
 * @{
 */
// RegIrqCryptoEn.r32
#define  REG_IRQ_CRYPTO_EN_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIrqCryptoEn */
#define  REG_IRQ_CRYPTO_EN_MASK                             0x0000001Fu                   /**< Mask for RegIrqCryptoEn */

#define  IRQ_CRYPTO_EN_SHIFT                                0                             /**< Shift for IrqCryptoEn */
#define  IRQ_CRYPTO_EN_MASK                                 0x0000001Fu                   /**< Mask for IrqCryptoEn */
#define  IRQ_CRYPTO_EN_BMASK                                0x1Fu                         /**< Base mask for IrqCryptoEn */
#define  IRQ_CRYPTO_EN(x)                                   (((x)&0x1Fu)<<0)              /**< Set IrqCryptoEn in register */
#define  GET_IRQ_CRYPTO_EN(reg)                             (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoEn from register */
/** @} */


/**
 * @name RegIrqCryptoEnSet
 * @{
 */
// RegIrqCryptoEnSet.r32
#define  REG_IRQ_CRYPTO_EN_SET_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIrqCryptoEnSet */
#define  REG_IRQ_CRYPTO_EN_SET_MASK                         0x0000001Fu                   /**< Mask for RegIrqCryptoEnSet */

#define  IRQ_CRYPTO_EN_SET_SHIFT                            0                             /**< Shift for IrqCryptoEnSet */
#define  IRQ_CRYPTO_EN_SET_MASK                             0x0000001Fu                   /**< Mask for IrqCryptoEnSet */
#define  IRQ_CRYPTO_EN_SET_BMASK                            0x1Fu                         /**< Base mask for IrqCryptoEnSet */
#define  IRQ_CRYPTO_EN_SET(x)                               (((x)&0x1Fu)<<0)              /**< Set IrqCryptoEnSet in register */
#define  GET_IRQ_CRYPTO_EN_SET(reg)                         (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoEnSet from register */
/** @} */


/**
 * @name RegIrqCryptoEnClr
 * @{
 */
// RegIrqCryptoEnClr.r32
#define  REG_IRQ_CRYPTO_EN_CLR_RESET_VALUE                  0x00000000u                   /**< Reset value of RegIrqCryptoEnClr */
#define  REG_IRQ_CRYPTO_EN_CLR_MASK                         0x0000001Fu                   /**< Mask for RegIrqCryptoEnClr */

#define  IRQ_CRYPTO_EN_CLR_SHIFT                            0                             /**< Shift for IrqCryptoEnClr */
#define  IRQ_CRYPTO_EN_CLR_MASK                             0x0000001Fu                   /**< Mask for IrqCryptoEnClr */
#define  IRQ_CRYPTO_EN_CLR_BMASK                            0x1Fu                         /**< Base mask for IrqCryptoEnClr */
#define  IRQ_CRYPTO_EN_CLR(x)                               (((x)&0x1Fu)<<0)              /**< Set IrqCryptoEnClr in register */
#define  GET_IRQ_CRYPTO_EN_CLR(reg)                         (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoEnClr from register */
/** @} */


/**
 * @name RegIrqCryptoMsk
 * @{
 */
// RegIrqCryptoMsk.r32
#define  REG_IRQ_CRYPTO_MSK_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqCryptoMsk */
#define  REG_IRQ_CRYPTO_MSK_MASK                            0x0000001Fu                   /**< Mask for RegIrqCryptoMsk */

#define  IRQ_CRYPTO_MSK_SHIFT                               0                             /**< Shift for IrqCryptoMsk */
#define  IRQ_CRYPTO_MSK_MASK                                0x0000001Fu                   /**< Mask for IrqCryptoMsk */
#define  IRQ_CRYPTO_MSK_BMASK                               0x1Fu                         /**< Base mask for IrqCryptoMsk */
#define  IRQ_CRYPTO_MSK(x)                                  (((x)&0x1Fu)<<0)              /**< Set IrqCryptoMsk in register */
#define  GET_IRQ_CRYPTO_MSK(reg)                            (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoMsk from register */
/** @} */


/**
 * @name RegIrqCryptoMskSet
 * @{
 */
// RegIrqCryptoMskSet.r32
#define  REG_IRQ_CRYPTO_MSK_SET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIrqCryptoMskSet */
#define  REG_IRQ_CRYPTO_MSK_SET_MASK                        0x0000001Fu                   /**< Mask for RegIrqCryptoMskSet */

#define  IRQ_CRYPTO_MSK_SET_SHIFT                           0                             /**< Shift for IrqCryptoMskSet */
#define  IRQ_CRYPTO_MSK_SET_MASK                            0x0000001Fu                   /**< Mask for IrqCryptoMskSet */
#define  IRQ_CRYPTO_MSK_SET_BMASK                           0x1Fu                         /**< Base mask for IrqCryptoMskSet */
#define  IRQ_CRYPTO_MSK_SET(x)                              (((x)&0x1Fu)<<0)              /**< Set IrqCryptoMskSet in register */
#define  GET_IRQ_CRYPTO_MSK_SET(reg)                        (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoMskSet from register */
/** @} */


/**
 * @name RegIrqCryptoMskClr
 * @{
 */
// RegIrqCryptoMskClr.r32
#define  REG_IRQ_CRYPTO_MSK_CLR_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIrqCryptoMskClr */
#define  REG_IRQ_CRYPTO_MSK_CLR_MASK                        0x0000001Fu                   /**< Mask for RegIrqCryptoMskClr */

#define  IRQ_CRYPTO_MSK_CLR_SHIFT                           0                             /**< Shift for IrqCryptoMskClr */
#define  IRQ_CRYPTO_MSK_CLR_MASK                            0x0000001Fu                   /**< Mask for IrqCryptoMskClr */
#define  IRQ_CRYPTO_MSK_CLR_BMASK                           0x1Fu                         /**< Base mask for IrqCryptoMskClr */
#define  IRQ_CRYPTO_MSK_CLR(x)                              (((x)&0x1Fu)<<0)              /**< Set IrqCryptoMskClr in register */
#define  GET_IRQ_CRYPTO_MSK_CLR(reg)                        (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoMskClr from register */
/** @} */


/**
 * @name RegIrqCryptoSts
 * @{
 */
// RegIrqCryptoSts.r32
#define  REG_IRQ_CRYPTO_STS_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqCryptoSts */
#define  REG_IRQ_CRYPTO_STS_MASK                            0x0000001Fu                   /**< Mask for RegIrqCryptoSts */

#define  IRQ_CRYPTO_STS_SHIFT                               0                             /**< Shift for IrqCryptoSts */
#define  IRQ_CRYPTO_STS_MASK                                0x0000001Fu                   /**< Mask for IrqCryptoSts */
#define  IRQ_CRYPTO_STS_BMASK                               0x1Fu                         /**< Base mask for IrqCryptoSts */
#define  IRQ_CRYPTO_STS(x)                                  (((x)&0x1Fu)<<0)              /**< Set IrqCryptoSts in register */
#define  GET_IRQ_CRYPTO_STS(reg)                            (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoSts from register */
/** @} */


/**
 * @name RegIrqCryptoStsSet
 * @{
 */
// RegIrqCryptoStsSet.r32
#define  REG_IRQ_CRYPTO_STS_SET_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIrqCryptoStsSet */
#define  REG_IRQ_CRYPTO_STS_SET_MASK                        0x0000001Fu                   /**< Mask for RegIrqCryptoStsSet */

#define  IRQ_CRYPTO_STS_SET_SHIFT                           0                             /**< Shift for IrqCryptoStsSet */
#define  IRQ_CRYPTO_STS_SET_MASK                            0x0000001Fu                   /**< Mask for IrqCryptoStsSet */
#define  IRQ_CRYPTO_STS_SET_BMASK                           0x1Fu                         /**< Base mask for IrqCryptoStsSet */
#define  IRQ_CRYPTO_STS_SET(x)                              (((x)&0x1Fu)<<0)              /**< Set IrqCryptoStsSet in register */
#define  GET_IRQ_CRYPTO_STS_SET(reg)                        (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoStsSet from register */
/** @} */


/**
 * @name RegIrqCryptoStsClr
 * @{
 */
// RegIrqCryptoStsClr.r32
#define  REG_IRQ_CRYPTO_STS_CLR_RESET_VALUE                 0x00000000u                   /**< Reset value of RegIrqCryptoStsClr */
#define  REG_IRQ_CRYPTO_STS_CLR_MASK                        0x0000001Fu                   /**< Mask for RegIrqCryptoStsClr */

#define  IRQ_CRYPTO_STS_CLR_SHIFT                           0                             /**< Shift for IrqCryptoStsClr */
#define  IRQ_CRYPTO_STS_CLR_MASK                            0x0000001Fu                   /**< Mask for IrqCryptoStsClr */
#define  IRQ_CRYPTO_STS_CLR_BMASK                           0x1Fu                         /**< Base mask for IrqCryptoStsClr */
#define  IRQ_CRYPTO_STS_CLR(x)                              (((x)&0x1Fu)<<0)              /**< Set IrqCryptoStsClr in register */
#define  GET_IRQ_CRYPTO_STS_CLR(reg)                        (((reg)>>0)&0x1Fu)            /**< Get IrqCryptoStsClr from register */
/** @} */


/**
 * @name RegIrqI2sEn
 * @{
 */
// RegIrqI2sEn.r32
#define  REG_IRQ_I2S_EN_RESET_VALUE                         0x00000000u                   /**< Reset value of RegIrqI2sEn */
#define  REG_IRQ_I2S_EN_MASK                                0x00003D3Bu                   /**< Mask for RegIrqI2sEn */

#define  IRQ_I2S_TX_EN_SHIFT                                0                             /**< Shift for IrqI2sTxEn */
#define  IRQ_I2S_TX_EN_MASK                                 0x00000001u                   /**< Mask for IrqI2sTxEn */
#define  IRQ_I2S_TX_EN_BMASK                                0x1u                          /**< Base mask for IrqI2sTxEn */
#define  IRQ_I2S_TX_EN(x)                                   (((x)&0x1u)<<0)               /**< Set IrqI2sTxEn in register */
#define  GET_IRQ_I2S_TX_EN(reg)                             (((reg)>>0)&0x1u)             /**< Get IrqI2sTxEn from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_SHIFT                     1                             /**< Shift for IrqI2sTxFifoEmptyEn */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_MASK                      0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyEn */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_BMASK                     0x1u                          /**< Base mask for IrqI2sTxFifoEmptyEn */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN(x)                        (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyEn in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_EN(reg)                  (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyEn from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_SHIFT                     3                             /**< Shift for IrqI2sTxFifoLimitEn */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_MASK                      0x00000008u                   /**< Mask for IrqI2sTxFifoLimitEn */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_BMASK                     0x1u                          /**< Base mask for IrqI2sTxFifoLimitEn */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN(x)                        (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitEn in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_EN(reg)                  (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitEn from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SHIFT                 4                             /**< Shift for IrqI2sTxFifoUnderflowEn */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_MASK                  0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowEn */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowEn */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN(x)                    (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowEn in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_EN(reg)              (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowEn from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_SHIFT                  5                             /**< Shift for IrqI2sTxFifoOverflowEn */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_MASK                   0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowEn */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_BMASK                  0x1u                          /**< Base mask for IrqI2sTxFifoOverflowEn */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN(x)                     (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowEn in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_EN(reg)               (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowEn from register */
#define  IRQ_I2S_RX_EN_SHIFT                                8                             /**< Shift for IrqI2sRxEn */
#define  IRQ_I2S_RX_EN_MASK                                 0x00000100u                   /**< Mask for IrqI2sRxEn */
#define  IRQ_I2S_RX_EN_BMASK                                0x1u                          /**< Base mask for IrqI2sRxEn */
#define  IRQ_I2S_RX_EN(x)                                   (((x)&0x1u)<<8)               /**< Set IrqI2sRxEn in register */
#define  GET_IRQ_I2S_RX_EN(reg)                             (((reg)>>8)&0x1u)             /**< Get IrqI2sRxEn from register */
#define  IRQ_I2S_RX_FIFO_FULL_EN_SHIFT                      10                            /**< Shift for IrqI2sRxFifoFullEn */
#define  IRQ_I2S_RX_FIFO_FULL_EN_MASK                       0x00000400u                   /**< Mask for IrqI2sRxFifoFullEn */
#define  IRQ_I2S_RX_FIFO_FULL_EN_BMASK                      0x1u                          /**< Base mask for IrqI2sRxFifoFullEn */
#define  IRQ_I2S_RX_FIFO_FULL_EN(x)                         (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullEn in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_EN(reg)                   (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullEn from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_SHIFT                     11                            /**< Shift for IrqI2sRxFifoLimitEn */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_MASK                      0x00000800u                   /**< Mask for IrqI2sRxFifoLimitEn */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_BMASK                     0x1u                          /**< Base mask for IrqI2sRxFifoLimitEn */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN(x)                        (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitEn in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_EN(reg)                  (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitEn from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SHIFT                 12                            /**< Shift for IrqI2sRxFifoUnderflowEn */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_MASK                  0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowEn */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowEn */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN(x)                    (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowEn in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_EN(reg)              (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowEn from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_SHIFT                  13                            /**< Shift for IrqI2sRxFifoOverflowEn */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_MASK                   0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowEn */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_BMASK                  0x1u                          /**< Base mask for IrqI2sRxFifoOverflowEn */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN(x)                     (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowEn in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_EN(reg)               (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowEn from register */
/** @} */


/**
 * @name RegIrqI2sEnSet
 * @{
 */
// RegIrqI2sEnSet.r32
#define  REG_IRQ_I2S_EN_SET_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqI2sEnSet */
#define  REG_IRQ_I2S_EN_SET_MASK                            0x00003D3Bu                   /**< Mask for RegIrqI2sEnSet */

#define  IRQ_I2S_TX_EN_SET_SHIFT                            0                             /**< Shift for IrqI2sTxEnSet */
#define  IRQ_I2S_TX_EN_SET_MASK                             0x00000001u                   /**< Mask for IrqI2sTxEnSet */
#define  IRQ_I2S_TX_EN_SET_BMASK                            0x1u                          /**< Base mask for IrqI2sTxEnSet */
#define  IRQ_I2S_TX_EN_SET(x)                               (((x)&0x1u)<<0)               /**< Set IrqI2sTxEnSet in register */
#define  GET_IRQ_I2S_TX_EN_SET(reg)                         (((reg)>>0)&0x1u)             /**< Get IrqI2sTxEnSet from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_SET_SHIFT                 1                             /**< Shift for IrqI2sTxFifoEmptyEnSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_SET_MASK                  0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyEnSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_SET_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoEmptyEnSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_SET(x)                    (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyEnSet in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_EN_SET(reg)              (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyEnSet from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_SET_SHIFT                 3                             /**< Shift for IrqI2sTxFifoLimitEnSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_SET_MASK                  0x00000008u                   /**< Mask for IrqI2sTxFifoLimitEnSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_SET_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoLimitEnSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_SET(x)                    (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitEnSet in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_EN_SET(reg)              (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitEnSet from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SET_SHIFT             4                             /**< Shift for IrqI2sTxFifoUnderflowEnSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SET_MASK              0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowEnSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowEnSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SET(x)                (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowEnSet in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_EN_SET(reg)          (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowEnSet from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_SET_SHIFT              5                             /**< Shift for IrqI2sTxFifoOverflowEnSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_SET_MASK               0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowEnSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_SET_BMASK              0x1u                          /**< Base mask for IrqI2sTxFifoOverflowEnSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_SET(x)                 (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowEnSet in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_EN_SET(reg)           (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowEnSet from register */
#define  IRQ_I2S_RX_EN_SET_SHIFT                            8                             /**< Shift for IrqI2sRxEnSet */
#define  IRQ_I2S_RX_EN_SET_MASK                             0x00000100u                   /**< Mask for IrqI2sRxEnSet */
#define  IRQ_I2S_RX_EN_SET_BMASK                            0x1u                          /**< Base mask for IrqI2sRxEnSet */
#define  IRQ_I2S_RX_EN_SET(x)                               (((x)&0x1u)<<8)               /**< Set IrqI2sRxEnSet in register */
#define  GET_IRQ_I2S_RX_EN_SET(reg)                         (((reg)>>8)&0x1u)             /**< Get IrqI2sRxEnSet from register */
#define  IRQ_I2S_RX_FIFO_FULL_EN_SET_SHIFT                  10                            /**< Shift for IrqI2sRxFifoFullEnSet */
#define  IRQ_I2S_RX_FIFO_FULL_EN_SET_MASK                   0x00000400u                   /**< Mask for IrqI2sRxFifoFullEnSet */
#define  IRQ_I2S_RX_FIFO_FULL_EN_SET_BMASK                  0x1u                          /**< Base mask for IrqI2sRxFifoFullEnSet */
#define  IRQ_I2S_RX_FIFO_FULL_EN_SET(x)                     (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullEnSet in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_EN_SET(reg)               (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullEnSet from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_SET_SHIFT                 11                            /**< Shift for IrqI2sRxFifoLimitEnSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_SET_MASK                  0x00000800u                   /**< Mask for IrqI2sRxFifoLimitEnSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_SET_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoLimitEnSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_SET(x)                    (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitEnSet in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_EN_SET(reg)              (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitEnSet from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SET_SHIFT             12                            /**< Shift for IrqI2sRxFifoUnderflowEnSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SET_MASK              0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowEnSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SET_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowEnSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SET(x)                (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowEnSet in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_EN_SET(reg)          (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowEnSet from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_SET_SHIFT              13                            /**< Shift for IrqI2sRxFifoOverflowEnSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_SET_MASK               0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowEnSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_SET_BMASK              0x1u                          /**< Base mask for IrqI2sRxFifoOverflowEnSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_SET(x)                 (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowEnSet in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_EN_SET(reg)           (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowEnSet from register */
/** @} */


/**
 * @name RegIrqI2sEnClr
 * @{
 */
// RegIrqI2sEnClr.r32
#define  REG_IRQ_I2S_EN_CLR_RESET_VALUE                     0x00000000u                   /**< Reset value of RegIrqI2sEnClr */
#define  REG_IRQ_I2S_EN_CLR_MASK                            0x00003D3Bu                   /**< Mask for RegIrqI2sEnClr */

#define  IRQ_I2S_TX_EN_CLR_SHIFT                            0                             /**< Shift for IrqI2sTxEnClr */
#define  IRQ_I2S_TX_EN_CLR_MASK                             0x00000001u                   /**< Mask for IrqI2sTxEnClr */
#define  IRQ_I2S_TX_EN_CLR_BMASK                            0x1u                          /**< Base mask for IrqI2sTxEnClr */
#define  IRQ_I2S_TX_EN_CLR(x)                               (((x)&0x1u)<<0)               /**< Set IrqI2sTxEnClr in register */
#define  GET_IRQ_I2S_TX_EN_CLR(reg)                         (((reg)>>0)&0x1u)             /**< Get IrqI2sTxEnClr from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_CLR_SHIFT                 1                             /**< Shift for IrqI2sTxFifoEmptyEnClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_CLR_MASK                  0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyEnClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_CLR_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoEmptyEnClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_EN_CLR(x)                    (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyEnClr in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_EN_CLR(reg)              (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyEnClr from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_CLR_SHIFT                 3                             /**< Shift for IrqI2sTxFifoLimitEnClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_CLR_MASK                  0x00000008u                   /**< Mask for IrqI2sTxFifoLimitEnClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_CLR_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoLimitEnClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_EN_CLR(x)                    (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitEnClr in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_EN_CLR(reg)              (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitEnClr from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_CLR_SHIFT             4                             /**< Shift for IrqI2sTxFifoUnderflowEnClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_CLR_MASK              0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowEnClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowEnClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_EN_CLR(x)                (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowEnClr in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_EN_CLR(reg)          (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowEnClr from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_CLR_SHIFT              5                             /**< Shift for IrqI2sTxFifoOverflowEnClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_CLR_MASK               0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowEnClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_CLR_BMASK              0x1u                          /**< Base mask for IrqI2sTxFifoOverflowEnClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_EN_CLR(x)                 (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowEnClr in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_EN_CLR(reg)           (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowEnClr from register */
#define  IRQ_I2S_RX_EN_CLR_SHIFT                            8                             /**< Shift for IrqI2sRxEnClr */
#define  IRQ_I2S_RX_EN_CLR_MASK                             0x00000100u                   /**< Mask for IrqI2sRxEnClr */
#define  IRQ_I2S_RX_EN_CLR_BMASK                            0x1u                          /**< Base mask for IrqI2sRxEnClr */
#define  IRQ_I2S_RX_EN_CLR(x)                               (((x)&0x1u)<<8)               /**< Set IrqI2sRxEnClr in register */
#define  GET_IRQ_I2S_RX_EN_CLR(reg)                         (((reg)>>8)&0x1u)             /**< Get IrqI2sRxEnClr from register */
#define  IRQ_I2S_RX_FIFO_FULL_EN_CLR_SHIFT                  10                            /**< Shift for IrqI2sRxFifoFullEnClr */
#define  IRQ_I2S_RX_FIFO_FULL_EN_CLR_MASK                   0x00000400u                   /**< Mask for IrqI2sRxFifoFullEnClr */
#define  IRQ_I2S_RX_FIFO_FULL_EN_CLR_BMASK                  0x1u                          /**< Base mask for IrqI2sRxFifoFullEnClr */
#define  IRQ_I2S_RX_FIFO_FULL_EN_CLR(x)                     (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullEnClr in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_EN_CLR(reg)               (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullEnClr from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_CLR_SHIFT                 11                            /**< Shift for IrqI2sRxFifoLimitEnClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_CLR_MASK                  0x00000800u                   /**< Mask for IrqI2sRxFifoLimitEnClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_CLR_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoLimitEnClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_EN_CLR(x)                    (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitEnClr in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_EN_CLR(reg)              (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitEnClr from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_CLR_SHIFT             12                            /**< Shift for IrqI2sRxFifoUnderflowEnClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_CLR_MASK              0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowEnClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowEnClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_EN_CLR(x)                (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowEnClr in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_EN_CLR(reg)          (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowEnClr from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_CLR_SHIFT              13                            /**< Shift for IrqI2sRxFifoOverflowEnClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_CLR_MASK               0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowEnClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_CLR_BMASK              0x1u                          /**< Base mask for IrqI2sRxFifoOverflowEnClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_EN_CLR(x)                 (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowEnClr in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_EN_CLR(reg)           (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowEnClr from register */
/** @} */


/**
 * @name RegIrqI2sMsk
 * @{
 */
// RegIrqI2sMsk.r32
#define  REG_IRQ_I2S_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqI2sMsk */
#define  REG_IRQ_I2S_MSK_MASK                               0x00003D3Bu                   /**< Mask for RegIrqI2sMsk */

#define  IRQ_I2S_TX_MSK_SHIFT                               0                             /**< Shift for IrqI2sTxMsk */
#define  IRQ_I2S_TX_MSK_MASK                                0x00000001u                   /**< Mask for IrqI2sTxMsk */
#define  IRQ_I2S_TX_MSK_BMASK                               0x1u                          /**< Base mask for IrqI2sTxMsk */
#define  IRQ_I2S_TX_MSK(x)                                  (((x)&0x1u)<<0)               /**< Set IrqI2sTxMsk in register */
#define  GET_IRQ_I2S_TX_MSK(reg)                            (((reg)>>0)&0x1u)             /**< Get IrqI2sTxMsk from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_SHIFT                    1                             /**< Shift for IrqI2sTxFifoEmptyMsk */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_MASK                     0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyMsk */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_BMASK                    0x1u                          /**< Base mask for IrqI2sTxFifoEmptyMsk */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK(x)                       (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyMsk in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_MSK(reg)                 (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyMsk from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_SHIFT                    3                             /**< Shift for IrqI2sTxFifoLimitMsk */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_MASK                     0x00000008u                   /**< Mask for IrqI2sTxFifoLimitMsk */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_BMASK                    0x1u                          /**< Base mask for IrqI2sTxFifoLimitMsk */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK(x)                       (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitMsk in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_MSK(reg)                 (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitMsk from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SHIFT                4                             /**< Shift for IrqI2sTxFifoUnderflowMsk */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_MASK                 0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowMsk */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowMsk */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK(x)                   (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowMsk in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_MSK(reg)             (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowMsk from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SHIFT                 5                             /**< Shift for IrqI2sTxFifoOverflowMsk */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_MASK                  0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowMsk */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoOverflowMsk */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK(x)                    (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowMsk in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_MSK(reg)              (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowMsk from register */
#define  IRQ_I2S_RX_MSK_SHIFT                               8                             /**< Shift for IrqI2sRxMsk */
#define  IRQ_I2S_RX_MSK_MASK                                0x00000100u                   /**< Mask for IrqI2sRxMsk */
#define  IRQ_I2S_RX_MSK_BMASK                               0x1u                          /**< Base mask for IrqI2sRxMsk */
#define  IRQ_I2S_RX_MSK(x)                                  (((x)&0x1u)<<8)               /**< Set IrqI2sRxMsk in register */
#define  GET_IRQ_I2S_RX_MSK(reg)                            (((reg)>>8)&0x1u)             /**< Get IrqI2sRxMsk from register */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_SHIFT                     10                            /**< Shift for IrqI2sRxFifoFullMsk */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_MASK                      0x00000400u                   /**< Mask for IrqI2sRxFifoFullMsk */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_BMASK                     0x1u                          /**< Base mask for IrqI2sRxFifoFullMsk */
#define  IRQ_I2S_RX_FIFO_FULL_MSK(x)                        (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullMsk in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_MSK(reg)                  (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullMsk from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_SHIFT                    11                            /**< Shift for IrqI2sRxFifoLimitMsk */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_MASK                     0x00000800u                   /**< Mask for IrqI2sRxFifoLimitMsk */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_BMASK                    0x1u                          /**< Base mask for IrqI2sRxFifoLimitMsk */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK(x)                       (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitMsk in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_MSK(reg)                 (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitMsk from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SHIFT                12                            /**< Shift for IrqI2sRxFifoUnderflowMsk */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_MASK                 0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowMsk */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowMsk */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK(x)                   (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowMsk in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_MSK(reg)             (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowMsk from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SHIFT                 13                            /**< Shift for IrqI2sRxFifoOverflowMsk */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_MASK                  0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowMsk */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoOverflowMsk */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK(x)                    (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowMsk in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_MSK(reg)              (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowMsk from register */
/** @} */


/**
 * @name RegIrqI2sMskSet
 * @{
 */
// RegIrqI2sMskSet.r32
#define  REG_IRQ_I2S_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqI2sMskSet */
#define  REG_IRQ_I2S_MSK_SET_MASK                           0x00003D3Bu                   /**< Mask for RegIrqI2sMskSet */

#define  IRQ_I2S_TX_MSK_SET_SHIFT                           0                             /**< Shift for IrqI2sTxMskSet */
#define  IRQ_I2S_TX_MSK_SET_MASK                            0x00000001u                   /**< Mask for IrqI2sTxMskSet */
#define  IRQ_I2S_TX_MSK_SET_BMASK                           0x1u                          /**< Base mask for IrqI2sTxMskSet */
#define  IRQ_I2S_TX_MSK_SET(x)                              (((x)&0x1u)<<0)               /**< Set IrqI2sTxMskSet in register */
#define  GET_IRQ_I2S_TX_MSK_SET(reg)                        (((reg)>>0)&0x1u)             /**< Get IrqI2sTxMskSet from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_SET_SHIFT                1                             /**< Shift for IrqI2sTxFifoEmptyMskSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_SET_MASK                 0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyMskSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_SET_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoEmptyMskSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_SET(x)                   (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyMskSet in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_MSK_SET(reg)             (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyMskSet from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_SET_SHIFT                3                             /**< Shift for IrqI2sTxFifoLimitMskSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_SET_MASK                 0x00000008u                   /**< Mask for IrqI2sTxFifoLimitMskSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_SET_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoLimitMskSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_SET(x)                   (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitMskSet in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_MSK_SET(reg)             (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitMskSet from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SET_SHIFT            4                             /**< Shift for IrqI2sTxFifoUnderflowMskSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SET_MASK             0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowMskSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowMskSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SET(x)               (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowMskSet in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_SET(reg)         (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowMskSet from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SET_SHIFT             5                             /**< Shift for IrqI2sTxFifoOverflowMskSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SET_MASK              0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowMskSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SET_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoOverflowMskSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SET(x)                (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowMskSet in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_MSK_SET(reg)          (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowMskSet from register */
#define  IRQ_I2S_RX_MSK_SET_SHIFT                           8                             /**< Shift for IrqI2sRxMskSet */
#define  IRQ_I2S_RX_MSK_SET_MASK                            0x00000100u                   /**< Mask for IrqI2sRxMskSet */
#define  IRQ_I2S_RX_MSK_SET_BMASK                           0x1u                          /**< Base mask for IrqI2sRxMskSet */
#define  IRQ_I2S_RX_MSK_SET(x)                              (((x)&0x1u)<<8)               /**< Set IrqI2sRxMskSet in register */
#define  GET_IRQ_I2S_RX_MSK_SET(reg)                        (((reg)>>8)&0x1u)             /**< Get IrqI2sRxMskSet from register */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_SET_SHIFT                 10                            /**< Shift for IrqI2sRxFifoFullMskSet */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_SET_MASK                  0x00000400u                   /**< Mask for IrqI2sRxFifoFullMskSet */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_SET_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoFullMskSet */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_SET(x)                    (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullMskSet in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_MSK_SET(reg)              (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullMskSet from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_SET_SHIFT                11                            /**< Shift for IrqI2sRxFifoLimitMskSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_SET_MASK                 0x00000800u                   /**< Mask for IrqI2sRxFifoLimitMskSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_SET_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoLimitMskSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_SET(x)                   (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitMskSet in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_MSK_SET(reg)             (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitMskSet from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SET_SHIFT            12                            /**< Shift for IrqI2sRxFifoUnderflowMskSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SET_MASK             0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowMskSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SET_BMASK            0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowMskSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SET(x)               (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowMskSet in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_SET(reg)         (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowMskSet from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SET_SHIFT             13                            /**< Shift for IrqI2sRxFifoOverflowMskSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SET_MASK              0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowMskSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SET_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoOverflowMskSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SET(x)                (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowMskSet in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_MSK_SET(reg)          (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowMskSet from register */
/** @} */


/**
 * @name RegIrqI2sMskClr
 * @{
 */
// RegIrqI2sMskClr.r32
#define  REG_IRQ_I2S_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqI2sMskClr */
#define  REG_IRQ_I2S_MSK_CLR_MASK                           0x00003D3Bu                   /**< Mask for RegIrqI2sMskClr */

#define  IRQ_I2S_TX_MSK_CLR_SHIFT                           0                             /**< Shift for IrqI2sTxMskClr */
#define  IRQ_I2S_TX_MSK_CLR_MASK                            0x00000001u                   /**< Mask for IrqI2sTxMskClr */
#define  IRQ_I2S_TX_MSK_CLR_BMASK                           0x1u                          /**< Base mask for IrqI2sTxMskClr */
#define  IRQ_I2S_TX_MSK_CLR(x)                              (((x)&0x1u)<<0)               /**< Set IrqI2sTxMskClr in register */
#define  GET_IRQ_I2S_TX_MSK_CLR(reg)                        (((reg)>>0)&0x1u)             /**< Get IrqI2sTxMskClr from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_CLR_SHIFT                1                             /**< Shift for IrqI2sTxFifoEmptyMskClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_CLR_MASK                 0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyMskClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoEmptyMskClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_MSK_CLR(x)                   (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyMskClr in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_MSK_CLR(reg)             (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyMskClr from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_CLR_SHIFT                3                             /**< Shift for IrqI2sTxFifoLimitMskClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_CLR_MASK                 0x00000008u                   /**< Mask for IrqI2sTxFifoLimitMskClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoLimitMskClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_MSK_CLR(x)                   (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitMskClr in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_MSK_CLR(reg)             (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitMskClr from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_CLR_SHIFT            4                             /**< Shift for IrqI2sTxFifoUnderflowMskClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_CLR_MASK             0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowMskClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowMskClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_CLR(x)               (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowMskClr in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_MSK_CLR(reg)         (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowMskClr from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_CLR_SHIFT             5                             /**< Shift for IrqI2sTxFifoOverflowMskClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_CLR_MASK              0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowMskClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoOverflowMskClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_MSK_CLR(x)                (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowMskClr in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_MSK_CLR(reg)          (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowMskClr from register */
#define  IRQ_I2S_RX_MSK_CLR_SHIFT                           8                             /**< Shift for IrqI2sRxMskClr */
#define  IRQ_I2S_RX_MSK_CLR_MASK                            0x00000100u                   /**< Mask for IrqI2sRxMskClr */
#define  IRQ_I2S_RX_MSK_CLR_BMASK                           0x1u                          /**< Base mask for IrqI2sRxMskClr */
#define  IRQ_I2S_RX_MSK_CLR(x)                              (((x)&0x1u)<<8)               /**< Set IrqI2sRxMskClr in register */
#define  GET_IRQ_I2S_RX_MSK_CLR(reg)                        (((reg)>>8)&0x1u)             /**< Get IrqI2sRxMskClr from register */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_CLR_SHIFT                 10                            /**< Shift for IrqI2sRxFifoFullMskClr */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_CLR_MASK                  0x00000400u                   /**< Mask for IrqI2sRxFifoFullMskClr */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_CLR_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoFullMskClr */
#define  IRQ_I2S_RX_FIFO_FULL_MSK_CLR(x)                    (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullMskClr in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_MSK_CLR(reg)              (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullMskClr from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_CLR_SHIFT                11                            /**< Shift for IrqI2sRxFifoLimitMskClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_CLR_MASK                 0x00000800u                   /**< Mask for IrqI2sRxFifoLimitMskClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoLimitMskClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_MSK_CLR(x)                   (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitMskClr in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_MSK_CLR(reg)             (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitMskClr from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_CLR_SHIFT            12                            /**< Shift for IrqI2sRxFifoUnderflowMskClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_CLR_MASK             0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowMskClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_CLR_BMASK            0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowMskClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_CLR(x)               (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowMskClr in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_MSK_CLR(reg)         (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowMskClr from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_CLR_SHIFT             13                            /**< Shift for IrqI2sRxFifoOverflowMskClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_CLR_MASK              0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowMskClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoOverflowMskClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_MSK_CLR(x)                (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowMskClr in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_MSK_CLR(reg)          (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowMskClr from register */
/** @} */


/**
 * @name RegIrqI2sSts
 * @{
 */
// RegIrqI2sSts.r32
#define  REG_IRQ_I2S_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIrqI2sSts */
#define  REG_IRQ_I2S_STS_MASK                               0x00003D3Bu                   /**< Mask for RegIrqI2sSts */

#define  IRQ_I2S_TX_STS_SHIFT                               0                             /**< Shift for IrqI2sTxSts */
#define  IRQ_I2S_TX_STS_MASK                                0x00000001u                   /**< Mask for IrqI2sTxSts */
#define  IRQ_I2S_TX_STS_BMASK                               0x1u                          /**< Base mask for IrqI2sTxSts */
#define  IRQ_I2S_TX_STS(x)                                  (((x)&0x1u)<<0)               /**< Set IrqI2sTxSts in register */
#define  GET_IRQ_I2S_TX_STS(reg)                            (((reg)>>0)&0x1u)             /**< Get IrqI2sTxSts from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_SHIFT                    1                             /**< Shift for IrqI2sTxFifoEmptySts */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_MASK                     0x00000002u                   /**< Mask for IrqI2sTxFifoEmptySts */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_BMASK                    0x1u                          /**< Base mask for IrqI2sTxFifoEmptySts */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS(x)                       (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptySts in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_STS(reg)                 (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptySts from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_SHIFT                    3                             /**< Shift for IrqI2sTxFifoLimitSts */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_MASK                     0x00000008u                   /**< Mask for IrqI2sTxFifoLimitSts */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_BMASK                    0x1u                          /**< Base mask for IrqI2sTxFifoLimitSts */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS(x)                       (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitSts in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_STS(reg)                 (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitSts from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SHIFT                4                             /**< Shift for IrqI2sTxFifoUnderflowSts */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_MASK                 0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowSts */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowSts */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS(x)                   (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowSts in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_STS(reg)             (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowSts from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_SHIFT                 5                             /**< Shift for IrqI2sTxFifoOverflowSts */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_MASK                  0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowSts */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_BMASK                 0x1u                          /**< Base mask for IrqI2sTxFifoOverflowSts */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS(x)                    (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowSts in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_STS(reg)              (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowSts from register */
#define  IRQ_I2S_RX_STS_SHIFT                               8                             /**< Shift for IrqI2sRxSts */
#define  IRQ_I2S_RX_STS_MASK                                0x00000100u                   /**< Mask for IrqI2sRxSts */
#define  IRQ_I2S_RX_STS_BMASK                               0x1u                          /**< Base mask for IrqI2sRxSts */
#define  IRQ_I2S_RX_STS(x)                                  (((x)&0x1u)<<8)               /**< Set IrqI2sRxSts in register */
#define  GET_IRQ_I2S_RX_STS(reg)                            (((reg)>>8)&0x1u)             /**< Get IrqI2sRxSts from register */
#define  IRQ_I2S_RX_FIFO_FULL_STS_SHIFT                     10                            /**< Shift for IrqI2sRxFifoFullSts */
#define  IRQ_I2S_RX_FIFO_FULL_STS_MASK                      0x00000400u                   /**< Mask for IrqI2sRxFifoFullSts */
#define  IRQ_I2S_RX_FIFO_FULL_STS_BMASK                     0x1u                          /**< Base mask for IrqI2sRxFifoFullSts */
#define  IRQ_I2S_RX_FIFO_FULL_STS(x)                        (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullSts in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_STS(reg)                  (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullSts from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_SHIFT                    11                            /**< Shift for IrqI2sRxFifoLimitSts */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_MASK                     0x00000800u                   /**< Mask for IrqI2sRxFifoLimitSts */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_BMASK                    0x1u                          /**< Base mask for IrqI2sRxFifoLimitSts */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS(x)                       (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitSts in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_STS(reg)                 (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitSts from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SHIFT                12                            /**< Shift for IrqI2sRxFifoUnderflowSts */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_MASK                 0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowSts */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowSts */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS(x)                   (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowSts in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_STS(reg)             (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowSts from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_SHIFT                 13                            /**< Shift for IrqI2sRxFifoOverflowSts */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_MASK                  0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowSts */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoOverflowSts */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS(x)                    (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowSts in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_STS(reg)              (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowSts from register */
/** @} */


/**
 * @name RegIrqI2sStsSet
 * @{
 */
// RegIrqI2sStsSet.r32
#define  REG_IRQ_I2S_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqI2sStsSet */
#define  REG_IRQ_I2S_STS_SET_MASK                           0x00003D3Bu                   /**< Mask for RegIrqI2sStsSet */

#define  IRQ_I2S_TX_STS_SET_SHIFT                           0                             /**< Shift for IrqI2sTxStsSet */
#define  IRQ_I2S_TX_STS_SET_MASK                            0x00000001u                   /**< Mask for IrqI2sTxStsSet */
#define  IRQ_I2S_TX_STS_SET_BMASK                           0x1u                          /**< Base mask for IrqI2sTxStsSet */
#define  IRQ_I2S_TX_STS_SET(x)                              (((x)&0x1u)<<0)               /**< Set IrqI2sTxStsSet in register */
#define  GET_IRQ_I2S_TX_STS_SET(reg)                        (((reg)>>0)&0x1u)             /**< Get IrqI2sTxStsSet from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_SET_SHIFT                1                             /**< Shift for IrqI2sTxFifoEmptyStsSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_SET_MASK                 0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyStsSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_SET_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoEmptyStsSet */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_SET(x)                   (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyStsSet in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_STS_SET(reg)             (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyStsSet from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_SET_SHIFT                3                             /**< Shift for IrqI2sTxFifoLimitStsSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_SET_MASK                 0x00000008u                   /**< Mask for IrqI2sTxFifoLimitStsSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_SET_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoLimitStsSet */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_SET(x)                   (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitStsSet in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_STS_SET(reg)             (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitStsSet from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SET_SHIFT            4                             /**< Shift for IrqI2sTxFifoUnderflowStsSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SET_MASK             0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowStsSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowStsSet */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SET(x)               (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowStsSet in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_STS_SET(reg)         (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowStsSet from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_SET_SHIFT             5                             /**< Shift for IrqI2sTxFifoOverflowStsSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_SET_MASK              0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowStsSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_SET_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoOverflowStsSet */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_SET(x)                (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowStsSet in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_STS_SET(reg)          (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowStsSet from register */
#define  IRQ_I2S_RX_STS_SET_SHIFT                           8                             /**< Shift for IrqI2sRxStsSet */
#define  IRQ_I2S_RX_STS_SET_MASK                            0x00000100u                   /**< Mask for IrqI2sRxStsSet */
#define  IRQ_I2S_RX_STS_SET_BMASK                           0x1u                          /**< Base mask for IrqI2sRxStsSet */
#define  IRQ_I2S_RX_STS_SET(x)                              (((x)&0x1u)<<8)               /**< Set IrqI2sRxStsSet in register */
#define  GET_IRQ_I2S_RX_STS_SET(reg)                        (((reg)>>8)&0x1u)             /**< Get IrqI2sRxStsSet from register */
#define  IRQ_I2S_RX_FIFO_FULL_STS_SET_SHIFT                 10                            /**< Shift for IrqI2sRxFifoFullStsSet */
#define  IRQ_I2S_RX_FIFO_FULL_STS_SET_MASK                  0x00000400u                   /**< Mask for IrqI2sRxFifoFullStsSet */
#define  IRQ_I2S_RX_FIFO_FULL_STS_SET_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoFullStsSet */
#define  IRQ_I2S_RX_FIFO_FULL_STS_SET(x)                    (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullStsSet in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_STS_SET(reg)              (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullStsSet from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_SET_SHIFT                11                            /**< Shift for IrqI2sRxFifoLimitStsSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_SET_MASK                 0x00000800u                   /**< Mask for IrqI2sRxFifoLimitStsSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_SET_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoLimitStsSet */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_SET(x)                   (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitStsSet in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_STS_SET(reg)             (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitStsSet from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SET_SHIFT            12                            /**< Shift for IrqI2sRxFifoUnderflowStsSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SET_MASK             0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowStsSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SET_BMASK            0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowStsSet */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SET(x)               (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowStsSet in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_STS_SET(reg)         (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowStsSet from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_SET_SHIFT             13                            /**< Shift for IrqI2sRxFifoOverflowStsSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_SET_MASK              0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowStsSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_SET_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoOverflowStsSet */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_SET(x)                (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowStsSet in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_STS_SET(reg)          (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowStsSet from register */
/** @} */


/**
 * @name RegIrqI2sStsClr
 * @{
 */
// RegIrqI2sStsClr.r32
#define  REG_IRQ_I2S_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIrqI2sStsClr */
#define  REG_IRQ_I2S_STS_CLR_MASK                           0x00003D3Bu                   /**< Mask for RegIrqI2sStsClr */

#define  IRQ_I2S_TX_STS_CLR_SHIFT                           0                             /**< Shift for IrqI2sTxStsClr */
#define  IRQ_I2S_TX_STS_CLR_MASK                            0x00000001u                   /**< Mask for IrqI2sTxStsClr */
#define  IRQ_I2S_TX_STS_CLR_BMASK                           0x1u                          /**< Base mask for IrqI2sTxStsClr */
#define  IRQ_I2S_TX_STS_CLR(x)                              (((x)&0x1u)<<0)               /**< Set IrqI2sTxStsClr in register */
#define  GET_IRQ_I2S_TX_STS_CLR(reg)                        (((reg)>>0)&0x1u)             /**< Get IrqI2sTxStsClr from register */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_CLR_SHIFT                1                             /**< Shift for IrqI2sTxFifoEmptyStsClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_CLR_MASK                 0x00000002u                   /**< Mask for IrqI2sTxFifoEmptyStsClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoEmptyStsClr */
#define  IRQ_I2S_TX_FIFO_EMPTY_STS_CLR(x)                   (((x)&0x1u)<<1)               /**< Set IrqI2sTxFifoEmptyStsClr in register */
#define  GET_IRQ_I2S_TX_FIFO_EMPTY_STS_CLR(reg)             (((reg)>>1)&0x1u)             /**< Get IrqI2sTxFifoEmptyStsClr from register */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_CLR_SHIFT                3                             /**< Shift for IrqI2sTxFifoLimitStsClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_CLR_MASK                 0x00000008u                   /**< Mask for IrqI2sTxFifoLimitStsClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sTxFifoLimitStsClr */
#define  IRQ_I2S_TX_FIFO_LIMIT_STS_CLR(x)                   (((x)&0x1u)<<3)               /**< Set IrqI2sTxFifoLimitStsClr in register */
#define  GET_IRQ_I2S_TX_FIFO_LIMIT_STS_CLR(reg)             (((reg)>>3)&0x1u)             /**< Get IrqI2sTxFifoLimitStsClr from register */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_CLR_SHIFT            4                             /**< Shift for IrqI2sTxFifoUnderflowStsClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_CLR_MASK             0x00000010u                   /**< Mask for IrqI2sTxFifoUnderflowStsClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IrqI2sTxFifoUnderflowStsClr */
#define  IRQ_I2S_TX_FIFO_UNDERFLOW_STS_CLR(x)               (((x)&0x1u)<<4)               /**< Set IrqI2sTxFifoUnderflowStsClr in register */
#define  GET_IRQ_I2S_TX_FIFO_UNDERFLOW_STS_CLR(reg)         (((reg)>>4)&0x1u)             /**< Get IrqI2sTxFifoUnderflowStsClr from register */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_CLR_SHIFT             5                             /**< Shift for IrqI2sTxFifoOverflowStsClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_CLR_MASK              0x00000020u                   /**< Mask for IrqI2sTxFifoOverflowStsClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sTxFifoOverflowStsClr */
#define  IRQ_I2S_TX_FIFO_OVERFLOW_STS_CLR(x)                (((x)&0x1u)<<5)               /**< Set IrqI2sTxFifoOverflowStsClr in register */
#define  GET_IRQ_I2S_TX_FIFO_OVERFLOW_STS_CLR(reg)          (((reg)>>5)&0x1u)             /**< Get IrqI2sTxFifoOverflowStsClr from register */
#define  IRQ_I2S_RX_STS_CLR_SHIFT                           8                             /**< Shift for IrqI2sRxStsClr */
#define  IRQ_I2S_RX_STS_CLR_MASK                            0x00000100u                   /**< Mask for IrqI2sRxStsClr */
#define  IRQ_I2S_RX_STS_CLR_BMASK                           0x1u                          /**< Base mask for IrqI2sRxStsClr */
#define  IRQ_I2S_RX_STS_CLR(x)                              (((x)&0x1u)<<8)               /**< Set IrqI2sRxStsClr in register */
#define  GET_IRQ_I2S_RX_STS_CLR(reg)                        (((reg)>>8)&0x1u)             /**< Get IrqI2sRxStsClr from register */
#define  IRQ_I2S_RX_FIFO_FULL_STS_CLR_SHIFT                 10                            /**< Shift for IrqI2sRxFifoFullStsClr */
#define  IRQ_I2S_RX_FIFO_FULL_STS_CLR_MASK                  0x00000400u                   /**< Mask for IrqI2sRxFifoFullStsClr */
#define  IRQ_I2S_RX_FIFO_FULL_STS_CLR_BMASK                 0x1u                          /**< Base mask for IrqI2sRxFifoFullStsClr */
#define  IRQ_I2S_RX_FIFO_FULL_STS_CLR(x)                    (((x)&0x1u)<<10)              /**< Set IrqI2sRxFifoFullStsClr in register */
#define  GET_IRQ_I2S_RX_FIFO_FULL_STS_CLR(reg)              (((reg)>>10)&0x1u)            /**< Get IrqI2sRxFifoFullStsClr from register */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_CLR_SHIFT                11                            /**< Shift for IrqI2sRxFifoLimitStsClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_CLR_MASK                 0x00000800u                   /**< Mask for IrqI2sRxFifoLimitStsClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_CLR_BMASK                0x1u                          /**< Base mask for IrqI2sRxFifoLimitStsClr */
#define  IRQ_I2S_RX_FIFO_LIMIT_STS_CLR(x)                   (((x)&0x1u)<<11)              /**< Set IrqI2sRxFifoLimitStsClr in register */
#define  GET_IRQ_I2S_RX_FIFO_LIMIT_STS_CLR(reg)             (((reg)>>11)&0x1u)            /**< Get IrqI2sRxFifoLimitStsClr from register */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_CLR_SHIFT            12                            /**< Shift for IrqI2sRxFifoUnderflowStsClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_CLR_MASK             0x00001000u                   /**< Mask for IrqI2sRxFifoUnderflowStsClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_CLR_BMASK            0x1u                          /**< Base mask for IrqI2sRxFifoUnderflowStsClr */
#define  IRQ_I2S_RX_FIFO_UNDERFLOW_STS_CLR(x)               (((x)&0x1u)<<12)              /**< Set IrqI2sRxFifoUnderflowStsClr in register */
#define  GET_IRQ_I2S_RX_FIFO_UNDERFLOW_STS_CLR(reg)         (((reg)>>12)&0x1u)            /**< Get IrqI2sRxFifoUnderflowStsClr from register */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_CLR_SHIFT             13                            /**< Shift for IrqI2sRxFifoOverflowStsClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_CLR_MASK              0x00002000u                   /**< Mask for IrqI2sRxFifoOverflowStsClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_CLR_BMASK             0x1u                          /**< Base mask for IrqI2sRxFifoOverflowStsClr */
#define  IRQ_I2S_RX_FIFO_OVERFLOW_STS_CLR(x)                (((x)&0x1u)<<13)              /**< Set IrqI2sRxFifoOverflowStsClr in register */
#define  GET_IRQ_I2S_RX_FIFO_OVERFLOW_STS_CLR(reg)          (((reg)>>13)&0x1u)            /**< Get IrqI2sRxFifoOverflowStsClr from register */
/** @} */


/**
 * @name RegIRQRESERVED0
 * @{
 */
// RegIRQRESERVED0.r32
#define  REG_IRQ_RESERVED0_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRESERVED0 */
#define  REG_IRQ_RESERVED0_MASK                             0xFFFFFFFFu                   /**< Mask for RegIRQRESERVED0 */

#define  IRQ_RESERVED0_SHIFT                                0                             /**< Shift for IRQRESERVED0 */
#define  IRQ_RESERVED0_MASK                                 0xFFFFFFFFu                   /**< Mask for IRQRESERVED0 */
#define  IRQ_RESERVED0_BMASK                                0xFFFFFFFFu                   /**< Base mask for IRQRESERVED0 */
#define  IRQ_RESERVED0(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set IRQRESERVED0 in register */
#define  GET_IRQ_RESERVED0(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get IRQRESERVED0 from register */
/** @} */


/**
 * @name RegIRQRESERVED1
 * @{
 */
// RegIRQRESERVED1.r32
#define  REG_IRQ_RESERVED1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRESERVED1 */
#define  REG_IRQ_RESERVED1_MASK                             0xFFFFFFFFu                   /**< Mask for RegIRQRESERVED1 */

#define  IRQ_RESERVED1_SHIFT                                0                             /**< Shift for IRQRESERVED1 */
#define  IRQ_RESERVED1_MASK                                 0xFFFFFFFFu                   /**< Mask for IRQRESERVED1 */
#define  IRQ_RESERVED1_BMASK                                0xFFFFFFFFu                   /**< Base mask for IRQRESERVED1 */
#define  IRQ_RESERVED1(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set IRQRESERVED1 in register */
#define  GET_IRQ_RESERVED1(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get IRQRESERVED1 from register */
/** @} */


/**
 * @name RegIRQRESERVED2
 * @{
 */
// RegIRQRESERVED2.r32
#define  REG_IRQ_RESERVED2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegIRQRESERVED2 */
#define  REG_IRQ_RESERVED2_MASK                             0xFFFFFFFFu                   /**< Mask for RegIRQRESERVED2 */

#define  IRQ_RESERVED2_SHIFT                                0                             /**< Shift for IRQRESERVED2 */
#define  IRQ_RESERVED2_MASK                                 0xFFFFFFFFu                   /**< Mask for IRQRESERVED2 */
#define  IRQ_RESERVED2_BMASK                                0xFFFFFFFFu                   /**< Base mask for IRQRESERVED2 */
#define  IRQ_RESERVED2(x)                                   (((x)&0xFFFFFFFFu)<<0)        /**< Set IRQRESERVED2 in register */
#define  GET_IRQ_RESERVED2(reg)                             (((reg)>>0)&0xFFFFFFFFu)      /**< Get IRQRESERVED2 from register */
/** @} */


/**
 * @name RegIRQSWIMsk
 * @{
 */
// RegIRQSWIMsk.r32
#define  REG_IRQ_SWI_MSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQSWIMsk */
#define  REG_IRQ_SWI_MSK_MASK                               0x000003FFu                   /**< Mask for RegIRQSWIMsk */

#define  IRQ_SWI_MSK_SHIFT                                  0                             /**< Shift for IRQSWIMsk */
#define  IRQ_SWI_MSK_MASK                                   0x000003FFu                   /**< Mask for IRQSWIMsk */
#define  IRQ_SWI_MSK_BMASK                                  0x3FFu                        /**< Base mask for IRQSWIMsk */
#define  IRQ_SWI_MSK(x)                                     (((x)&0x3FFu)<<0)             /**< Set IRQSWIMsk in register */
#define  GET_IRQ_SWI_MSK(reg)                               (((reg)>>0)&0x3FFu)           /**< Get IRQSWIMsk from register */
/** @} */


/**
 * @name RegIRQSWIMskSet
 * @{
 */
// RegIRQSWIMskSet.r32
#define  REG_IRQ_SWI_MSK_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSWIMskSet */
#define  REG_IRQ_SWI_MSK_SET_MASK                           0x000003FFu                   /**< Mask for RegIRQSWIMskSet */

#define  IRQ_SWI_MSK_SET_SHIFT                              0                             /**< Shift for IRQSWIMskSet */
#define  IRQ_SWI_MSK_SET_MASK                               0x000003FFu                   /**< Mask for IRQSWIMskSet */
#define  IRQ_SWI_MSK_SET_BMASK                              0x3FFu                        /**< Base mask for IRQSWIMskSet */
#define  IRQ_SWI_MSK_SET(x)                                 (((x)&0x3FFu)<<0)             /**< Set IRQSWIMskSet in register */
#define  GET_IRQ_SWI_MSK_SET(reg)                           (((reg)>>0)&0x3FFu)           /**< Get IRQSWIMskSet from register */
/** @} */


/**
 * @name RegIRQSWIMskClr
 * @{
 */
// RegIRQSWIMskClr.r32
#define  REG_IRQ_SWI_MSK_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSWIMskClr */
#define  REG_IRQ_SWI_MSK_CLR_MASK                           0x000003FFu                   /**< Mask for RegIRQSWIMskClr */

#define  IRQ_SWI_MSK_CLR_SHIFT                              0                             /**< Shift for IRQSWIMskClr */
#define  IRQ_SWI_MSK_CLR_MASK                               0x000003FFu                   /**< Mask for IRQSWIMskClr */
#define  IRQ_SWI_MSK_CLR_BMASK                              0x3FFu                        /**< Base mask for IRQSWIMskClr */
#define  IRQ_SWI_MSK_CLR(x)                                 (((x)&0x3FFu)<<0)             /**< Set IRQSWIMskClr in register */
#define  GET_IRQ_SWI_MSK_CLR(reg)                           (((reg)>>0)&0x3FFu)           /**< Get IRQSWIMskClr from register */
/** @} */


/**
 * @name RegIRQSWISts
 * @{
 */
// RegIRQSWISts.r32
#define  REG_IRQ_SWI_STS_RESET_VALUE                        0x00000000u                   /**< Reset value of RegIRQSWISts */
#define  REG_IRQ_SWI_STS_MASK                               0x000003FFu                   /**< Mask for RegIRQSWISts */

#define  IRQ_SWI_STS_SHIFT                                  0                             /**< Shift for IRQSWISts */
#define  IRQ_SWI_STS_MASK                                   0x000003FFu                   /**< Mask for IRQSWISts */
#define  IRQ_SWI_STS_BMASK                                  0x3FFu                        /**< Base mask for IRQSWISts */
#define  IRQ_SWI_STS(x)                                     (((x)&0x3FFu)<<0)             /**< Set IRQSWISts in register */
#define  GET_IRQ_SWI_STS(reg)                               (((reg)>>0)&0x3FFu)           /**< Get IRQSWISts from register */
/** @} */


/**
 * @name RegIRQSWIStsSet
 * @{
 */
// RegIRQSWIStsSet.r32
#define  REG_IRQ_SWI_STS_SET_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSWIStsSet */
#define  REG_IRQ_SWI_STS_SET_MASK                           0x000003FFu                   /**< Mask for RegIRQSWIStsSet */

#define  IRQ_SWI_STS_SET_SHIFT                              0                             /**< Shift for IRQSWIStsSet */
#define  IRQ_SWI_STS_SET_MASK                               0x000003FFu                   /**< Mask for IRQSWIStsSet */
#define  IRQ_SWI_STS_SET_BMASK                              0x3FFu                        /**< Base mask for IRQSWIStsSet */
#define  IRQ_SWI_STS_SET(x)                                 (((x)&0x3FFu)<<0)             /**< Set IRQSWIStsSet in register */
#define  GET_IRQ_SWI_STS_SET(reg)                           (((reg)>>0)&0x3FFu)           /**< Get IRQSWIStsSet from register */
/** @} */


/**
 * @name RegIRQSWIStsClr
 * @{
 */
// RegIRQSWIStsClr.r32
#define  REG_IRQ_SWI_STS_CLR_RESET_VALUE                    0x00000000u                   /**< Reset value of RegIRQSWIStsClr */
#define  REG_IRQ_SWI_STS_CLR_MASK                           0x000003FFu                   /**< Mask for RegIRQSWIStsClr */

#define  IRQ_SWI_STS_CLR_SHIFT                              0                             /**< Shift for IRQSWIStsClr */
#define  IRQ_SWI_STS_CLR_MASK                               0x000003FFu                   /**< Mask for IRQSWIStsClr */
#define  IRQ_SWI_STS_CLR_BMASK                              0x3FFu                        /**< Base mask for IRQSWIStsClr */
#define  IRQ_SWI_STS_CLR(x)                                 (((x)&0x3FFu)<<0)             /**< Set IRQSWIStsClr in register */
#define  GET_IRQ_SWI_STS_CLR(reg)                           (((reg)>>0)&0x3FFu)           /**< Get IRQSWIStsClr from register */
/** @} */



/** @} End of group IRQ_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_IRQ_H */
