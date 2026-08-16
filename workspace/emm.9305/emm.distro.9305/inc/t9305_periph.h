////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/9305/includes/t9305_periph.h
///
/// @project    T9305
///
/// @brief      Peripheral access layer header file
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

#ifndef _T9305_PERIPH_H
#define _T9305_PERIPH_H



#include "types.h"
#include "t9305_pml.h"
#include "t9305_irq.h"
#include "t9305_rng.h"
#include "t9305_adc.h"
#include "t9305_uni_tim.h"
#include "t9305_prot_tim.h"
#include "t9305_rc_calib.h"
#include "t9305_uart.h"
#include "t9305_i2c_master.h"
#include "t9305_nvm.h"
#include "t9305_spi_master.h"
#include "t9305_spi_slave.h"
#include "t9305_gpio.h"
#include "t9305_system.h"
#include "t9305_qdec.h"
#include "t9305_pck_proc.h"
#include "t9305_rf_ctrl.h"
#include "t9305_radio.h"
#include "t9305_aoad_matrix.h"
#include "t9305_cu.h"
#include "t9305_i2s.h"
#include "t9305_usb.h"


/*******************************************************************************
 * @addtogroup T9305_Periphery
 * @{
 * @brief T9305 Periphery definition and description
 ******************************************************************************/



/*******************************************************************************
 * @addtogroup  Peripheral_Map  Peripheral Memory Map
 * @{
 * @brief T9305 Peripheral Memory Map
 ******************************************************************************/
#define PERIPH_BASE     (0xF00000UL)    /**< PERIPH base address  */

#define PML_BASE        (0xF00400UL)    /**< PML base address  */
#define IRQMAN_BASE     (0xF00800UL)    /**< IRQ_MAN base address  */
#define RNG_BASE        (0xF00C00UL)    /**< RNG base address  */
#define ADC_BASE        (0xF01000UL)    /**< ADC base address  */
#define UNITIM_BASE     (0xF01400UL)    /**< UNI_TIM base address  */
#define PROTTIM_BASE    (0xF01800UL)    /**< PROT_TIM base address  */
#define RCCALIB_BASE    (0xF01C00UL)    /**< RC_CALIB base address  */
#define UART_BASE       (0xF02000UL)    /**< UART base address  */
#define I2CM_BASE       (0xF02400UL)    /**< I2CM base address  */
#define NVM_BASE        (0xF02800UL)    /**< NVM base address  */
#define SPIM_BASE       (0xF02C00UL)    /**< SPIM base address  */
#define SPIS_BASE       (0xF03000UL)    /**< SPIS base address  */
#define GPIO_BASE       (0xF03400UL)    /**< GPIO base address  */
#define SYS_BASE        (0xF03800UL)    /**< SYS base address  */
#define QDEC_BASE       (0xF03C00UL)    /**< QDEC base address  */
#define PP_BASE         (0xF04000UL)    /**< PCK_PROC base address  */
#define RFCTRL_BASE     (0xF04400UL)    /**< RF_CTRL base address  */
#define RF_BASE         (0xF04800UL)    /**< RF base address  */
#define AOAD_BASE       (0xF04C00UL)    /**< AOAD base address  */
#define CU_BASE         (0xF05000UL)    /**< CU base address  */
#define I2S_BASE        (0xF05400UL)    /**< I2S base address */
#define USB_BASE        (0xF80000UL)    /**< USB base address  */
/** @} */



/*******************************************************************************
 * @addtogroup  Peripheral_Declaration  Peripheral Declarations
 * @{
 * @brief T9305 Peripheral Declarations
 ******************************************************************************/
#define PML         ((PML_RegMap_t *) PML_BASE)             /**< PML base pointer  */
#define IRQ         ((IRQ_RegMap_t *) IRQMAN_BASE)          /**< IRQ_MAN base pointer  */
#define RNG         ((RNG_RegMap_t *) RNG_BASE)             /**< RNG base pointer  */
#define ADC         ((ADC_RegMap_t *) ADC_BASE)             /**< ADC base pointer  */
#define UTIM        ((UniTim_RegMap_t *) UNITIM_BASE)       /**< UNI_TIM base pointer  */
#define PTIM        ((ProtTim_RegMap_t *) PROTTIM_BASE)     /**< PROT_TIM base pointer  */
#define RCCAL       ((RCCalib_RegMap_t *) RCCALIB_BASE)     /**< RC_CALIB base pointer  */
#define UART        ((UART_RegMap_t *) UART_BASE)           /**< UART base pointer  */
#define I2CM        ((I2CMaster_RegMap_t *) I2CM_BASE)      /**< I2CM base pointer  */
#define NVM         ((NVM_RegMap_t *) NVM_BASE)             /**< NVM base pointer  */
#define SPIM        ((SPIMaster_RegMap_t *) SPIM_BASE)      /**< SPIM base pointer  */
#define SPIS        ((SPISlave_RegMap_t *) SPIS_BASE)       /**< SPIS base pointer  */
#define GPIO        ((GPIO_RegMap_t *) GPIO_BASE)           /**< GPIO base pointer  */
#define SYS         ((System_RegMap_t *) SYS_BASE)          /**< SYS base pointer  */
#define QDEC        ((QDec_RegMap_t *) QDEC_BASE)           /**< QDEC base pointer  */
#define PP          ((PckProc_RegMap_t *) PP_BASE)          /**< PCK_PROC base pointer  */
#define RFC         ((RfCtrl_RegMap_t *) RFCTRL_BASE)       /**< RF_CTRL base pointer  */
#define RF          ((Radio_RegMap_t *) RF_BASE)            /**< RF base pointer  */
#define AOAD        ((AoADMatrix_RegMap_t *) AOAD_BASE)     /**< AOAD base pointer  */
#define CU          ((CU_RegMap_t *) CU_BASE)               /**< CU base pointer  */
#define I2S         ((I2S_RegMap_t *) I2S_BASE)             /**< I2S base pointer */
#define USB         ((USB_RegMap_t *) USB_BASE)             /**< USB base pointer  */
/** @} */

/** @} End of addtogroup T9305_Periphery */


#endif // _T9305_PERIPH_H
