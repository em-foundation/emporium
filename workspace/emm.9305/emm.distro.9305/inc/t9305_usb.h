////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/t9305_usb.h
///
/// @project    T9305
///
/// @brief      USB register and bit field definitions
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

#ifndef _T9305_USB_H
#define _T9305_USB_H

#include "types.h"



/***************************************************************************//**
 * @addtogroup cts/T9305_Periphery
 * @{
 ******************************************************************************/


/***************************************************************************//**
 * @defgroup USB_Registers USB Device Register Map - registers
 * @{
 ******************************************************************************/


/** OTG Control and Status Register
The OTG Control and Status register controls the behavior and reflects the status of the OTG function of the controller. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGOTGCTL_t;


/** OTG Interrupt Register
The application reads this register whenever there is an OTG interrupt and clears the bits in this register to clear the OTG interrupt. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGOTGINT_t;


/** AHB Configuration Register
This register can be used to configure the core after power-on or a change in mode. This register mainly contains AHB system-related configuration parameters. Do not change this register after the initial programming. The application must program this register before starting any transactions on either the AHB or the USB. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGAHBCFG_t;


/** USB Configuration Register
This register can be used to configure the core after power-on or when changing to Host mode or Device mode. It contains USB and USB-PHY related configuration parameters. The application must program this register before starting any transactions on either the AHB or the USB. If you are using the HSIC interface, HSIC PHY must be in reset while programming this register. Do not make changes to this register after the initial programming. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGUSBCFG_t;


/** Reset Register
The application uses this register to reset various hardware features inside the controller. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGRSTCTL_t;


/** Interrupt Register

This register interrupts the application for system-level events in the current mode (Device mode or Host mode).
Some of the bits in this register are valid only in Host mode, while others are valid in Device mode only. This register also indicates the current mode. To clear the interrupt status bits of type R_SS_WC, the application must write 1'b1 to the bit.
The FIFO status interrupts are read only; once software reads from or writes to the FIFO while servicing these interrupts, FIFO interrupt conditions are cleared automatically.
The application must clear the GINTSTS register at initialization before unmasking the interrupt bit to avoid any interrupts generated prior to initialization.

Note: Read the reset value of GINTSTS.CurMod only after the following conditions:
 - If IDDIG_FILTER is disabled, read only after PHY clock is stable.
 - If IDDIG_FILTER is enabled, read only after the filter timer expires. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGINTSTS_t;


/** Interrupt Mask Register
This register works with the Interrupt Register (GINTSTS) to interrupt the application. When an interrupt bit is masked, the interrupt associated with that bit is not generated. However, the GINTSTS register bit corresponding to that interrupt is still set.

Note: The fields of this register change depending on host or device mode. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGINTMSK_t;


/** Receive Status Debug Read Register
A read to the Receive Status Debug Read register returns the contents of the top of the Receive FIFO.

The receive status contents must be interpreted differently in Host and Device modes. The core ignores the receive status read when the receive FIFO is empty and returns a value of 32'h0000_0000.

Note:
 - Use of these fields vary based on whether the core is functioning as a host or a device.
 - Do not read this register's reset value before configuring the core because the read value is 'X' in the simulation. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGRXSTSR_t;


/** Receive Status Read/Pop Register
A read to the Receive Status Read and Pop register returns the contents of the top of the Receive FIFO and additionally pops the top data entry out of the RxFIFO.
The receive status contents must be interpreted differently in Host and Device modes. The core ignores the receive status pop/read when the receive FIFO is empty and returns a value of 32'h0000_0000. The application must only pop the Receive Status FIFO when the Receive FIFO Non-Empty bit of the Core Interrupt register (GINTSTS.RxFLvl) is asserted.

Note:
 - Use of these fields vary based on whether the core is functioning as a host or a device.
 - Do not read this register's reset value before configuring the core because the read value is 'X' in the simulation. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGRXSTSP_t;


/** Receive FIFO Size Register
The application can program the RAM size that must be allocated to the RxFIFO. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGRXFSIZ_t;


/** Non-periodic Transmit FIFO Size Register
The application can program the RAM size and the memory start address for the Non-periodic TxFIFO

Note: The fields of this register change depending on host or device mode. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGNPTXFSIZ_t;


/** Non-periodic Transmit FIFO/Queue Status Register
In Device mode, this register is valid only in Shared FIFO operation.
This read-only register contains the free space information for the Non-periodic TxFIFO and the Non-periodic Transmit Request Queue. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGNPTXSTS_t;


/** Synopsys ID Register

This read-only register contains the release number of the core being used. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGSNPSID_t;


/** User Hardware Configuration 1 Register

This register contains the logical endpoint direction(s) selected using coreConsultant. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGHWCFG1_t;


/** User Hardware Configuration 2 Register

This register contains configuration options selected using coreConsultant. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGHWCFG2_t;


/** User Hardware Configuration 3 Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGHWCFG3_t;


/** User Hardware Configuration 4 Register

Note: Bit [31] is available only when Scatter/Gather DMA mode is enabled. When Scatter/Gather DMA mode is disabled, this field is reserved. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGHWCFG4_t;


/** Interrupt Mask Register 2
This register works with the Interrupt Register (GINTSTS2) to interrupt the application. When an interrupt bit is masked, the interrupt associated with that bit is not generated. However, the GINTSTS2 register bit corresponding to that interrupt is still set.

Note: The fields of this register change depending on host or device mode. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGINTMSK2_t;


/** Interrupt Register 2

This register interrupts the application for system-level events in the current mode (Device mode or Host mode).
Some of the bits in this register are valid only in Host mode, while others are valid in Device mode only. This register also indicates the current mode. To clear the interrupt status bits of type R_SS_WC, the application must write 1'b1 to the bit.
The application must clear the GINTSTS2 register at initialization before unmasking the interrupt bit to avoid any interrupts generated prior to initialization. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbGINTSTS2_t;


/** Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDPTXFSIZ1_t;


/** Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDPTXFSIZ2_t;


/** Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDPTXFSIZ3_t;


/** Device Configuration Register

This register configures the core in Device mode after power-on or after certain control commands or enumeration. Do not make changes to this register after initial programming. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDCFG_t;


/** Device Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDCTL_t;


/** Device Status Register

This register indicates the status of the core with respect to USB-related events. It must be read on interrupts from Device All Interrupts (DAINT) register. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDSTS_t;


/** Device IN Endpoint Common Interrupt Mask Register

This register works with each of the Device IN Endpoint Interrupt (DIEPINTn) registers for all endpoints to generate an interrupt per IN endpoint. The IN endpoint interrupt for a specific status in the DIEPINTn register can be masked by writing to the corresponding bit in this register. Status bits are masked by default. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPMSK_t;


/** Device OUT Endpoint Common Interrupt Mask Register

This register works with each of the Device OUT Endpoint Interrupt (DOEPINTn) registers for all endpoints to generate an interrupt per OUT endpoint. The OUT endpoint interrupt for a specific status in the DOEPINTn register can be masked by writing into the corresponding bit in this register. Status bits are masked by default. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPMSK_t;


/** Device All Endpoints Interrupt Register

When a significant event occurs on an endpoint, a Device All Endpoints Interrupt register interrupts the
application using the Device OUT Endpoints Interrupt bit or Device IN Endpoints Interrupt bit of the Core
Interrupt register (GINTSTS.OEPInt or GINTSTS.IEPInt, respectively). This is shown in Figure 5-2. There is
one interrupt bit per endpoint, up to a maximum of 16 bits for OUT endpoints and 16 bits for IN endpoints.
For a bidirectional endpoint, the corresponding IN and OUT interrupt bits are used. Bits in this register are
set and cleared when the application sets and clears bits in the corresponding Device Endpoint-n Interrupt
register (DIEPINTn/DOEPINTn). */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDAINT_t;


/** Device All Endpoints Interrupt Mask Register

 The Device Endpoint Interrupt Mask register works with the Device Endpoint Interrupt register to interrupt the application when an event occurs on a device endpoint. However, the Device All Endpoints Interrupt (DAINT) register bit corresponding to that interrupt is still set. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDAINTMSK_t;


/** Device IN Token Sequence Learning Queue Read Register 1

 This register is valid only in non-periodic Shared FIFO operation (OTG_EN_DED_TX_FIFO = 0). The depth of the IN Token Sequence Learning Queue is specified for Device Mode IN Token Sequence Learning Queue Depth during coreConsultant configuration (parameter OTG_TOKEN_QUEUE_DEPTH). The queue is 4 bits wide to store the endpoint number. A read from this register returns the first 5 endpoint entries of the IN Token Sequence Learning Queue. When the queue is full, the new token is pushed into the queue and oldest token is discarded. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTKNQR1_t;


/** Device IN Token Sequence Learning Queue Read Register 2

 This register is valid only in shared non-periodic Shared FIFO operation (OTG_EN_DED_TX_FIFO = 0). A read from this register returns the next 8 endpoint entries of the learning queue. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTKNQR2_t;


/** Device VBUS Discharge Time Register

 This register specifies the VBUS discharge time after VBUS pulsing during SRP. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDVBUSDIS_t;


/** Device VBUS Pulsing Time Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDVBUSPULSE_t;


/** Device IN Token Sequence Learning Queue Read Register 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTKNQR3_t;


/** Device IN Token Sequence Learning Queue Read Register 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTKNQR4_t;


/** Device Each Endpoints Interrupt Register

 Dependency: This register is available in device mode and only when parameter "OTG_MULTI_PROC_INTRPT" on page 121=1. There is one interrupt bit per endpoint, up to a maximum of 16 bits for OUT endpoints and 16 bits for IN endpoints. For a bidirectional endpoint, the corresponding IN and OUT interrupt bits are used. Bits in this register are set and cleared when the application sets and clears bits in the corresponding Device Endpoint-n Interrupt register (DIEPINTn/DOEPINTn). The interrupt is automatically cleared once the DOEPINTn/DIEPINTn interrupt is cleared by the application.
 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDEACHINT_t;


/** Device Each Endpoints Interrupt Mask Register

Dependency: This register is available only when parameter OTG_MULTI_PROC_INTRPT=1. The Device Each Endpoint Interrupt Mask register works with the Device Each Endpoint Interrupt register to interrupt the application when an event occurs on a device endpoint. However, the Device Each Endpoints Interrupt (DEACHINT) register bit corresponding to that interrupt remains set.
 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDEACHINTMSK_t;


/** Device Each IN Endpoint 0 Interrupt Register


Dependency: This register is available in device mode and only when parameter "OTG_MULTI_PROC_INTRPT" on page 121=1. These registers are endpoint-specific mask registers for (DIEPINTn). The IN endpoint interrupt for a specific status in the DIEPINTn register can be masked by writing 0 to the corresponding bit in this register. Status bits are masked by default.
 - Mask interrupt: 1'b0
 - Unmask interrupt: 1'b1
 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPEACHMSK0_t;


/** Device Each IN Endpoint 1 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPEACHMSK1_t;


/** Device Each IN Endpoint 2 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPEACHMSK2_t;


/** Device Each IN Endpoint 3 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPEACHMSK3_t;


/** Device Each OUT Endpoint 0 Interrupt Register
Dependency: This register is available in device mode and only when parameter OTG_MULTI_PROC_INTRPT=1. These registers are endpoint specific mask registers for (DOEPINTn). The OUT endpoint interrupt for a specific status in the DOEPINTn register can be masked by writing 0 to the corresponding bit in this register. Status bits are masked by default. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPEACHMSK0_t;


/** Device Each OUT Endpoint 1 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPEACHMSK1_t;


/** Device Each OUT Endpoint 2 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPEACHMSK2_t;


/** Device Each OUT Endpoint 3 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPEACHMSK3_t;


/** Device Control IN Endpoint 0 Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPCTL0_t;


/** Device IN Endpoint 0 Interrupt Register

 This register indicates the status of an endpoint with respect to USB- and AHB-related events. It is shown in the "Interrupt Hierarchy" figure in the databook. The application must read this register when the OUT Endpoints Interrupt bit or IN Endpoints Interrupt bit of the Core Interrupt register (GINTSTS.OEPInt or GINTSTS.IEPInt, respectively) is set. Before the application can read this register, it must first read the Device All Endpoints Interrupt (DAINT) register to get the exact endpoint number for the Device Endpoint-n Interrupt register. The application must clear the appropriate bit in this register to clear the corresponding bits in the DAINT and GINTSTS registers */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPINT0_t;


/** Device IN Endpoint 0 Transfer Size Register


The application must modify this register before enabling endpoint 0. Once endpoint 0 is enabled using Endpoint Enable bit of the Device Control Endpoint 0 Control registers (DIEPCTL0.EPEna/DOEPCTL0.EPEna), the core modifies this register. The application can only read this register once the core has cleared the Endpoint Enable bit. Nonzero endpoints use the registers for endpoints 115. When Scatter/Gather DMA mode is enabled, this register must not be programmed by the application. If the application reads this register when Scatter/Gather DMA mode is enabled, the core returns all zeros. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPTSIZ0_t;


/** Device IN Endpoint Transmit FIFO Status Register 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTXFSTS0_t;


/** Device Control IN Endpoint 1 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPCTL1_t;


/** Device IN Endpoint 1 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPINT1_t;


/** Device IN Endpoint 1 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPTSIZ1_t;


/** Device IN Endpoint Transmit FIFO Status Register 1

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTXFSTS1_t;


/** Device Control IN Endpoint 2 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPCTL2_t;


/** Device IN Endpoint 2 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPINT2_t;


/** Device IN Endpoint 2 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPTSIZ2_t;


/** Device IN Endpoint Transmit FIFO Status Register 2

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTXFSTS2_t;


/** Device Control IN Endpoint 3 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPCTL3_t;


/** Device IN Endpoint 3 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPINT3_t;


/** Device IN Endpoint 3 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDIEPTSIZ3_t;


/** Device IN Endpoint Transmit FIFO Status Register 3

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDTXFSTS3_t;


/** Device Control OUT Endpoint 0 Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPCTL0_t;


/** Device OUT Endpoint 0 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPINT0_t;


/** Device OUT Endpoint 0 Transfer Size Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPTSIZ0_t;


/** Device Control OUT Endpoint 1 Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPCTL1_t;


/** Device OUT Endpoint 1 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPINT1_t;


/** Device OUT Endpoint 1 Transfer Size Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPTSIZ1_t;


/** Device Control OUT Endpoint 2 Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPCTL2_t;


/** Device OUT Endpoint 2 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPINT2_t;


/** Device OUT Endpoint 2 Transfer Size Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPTSIZ2_t;


/** Device Control OUT Endpoint 3 Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPCTL3_t;


/** Device OUT Endpoint 3 Interrupt Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPINT3_t;


/** Device OUT Endpoint 3 Transfer Size Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDOEPTSIZ3_t;


/** Power and Clock Gating Control Register */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbPCGCCTL_t;


/** Data FIFO Access Register Map 0 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO0_t;


/** Data FIFO Access Register Map 1 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO1_t;


/** Data FIFO Access Register Map 2 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO2_t;


/** Data FIFO Access Register Map 3 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO3_t;


/** Data FIFO Access Register Map 4 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO4_t;


/** Data FIFO Access Register Map 5 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO5_t;


/** Data FIFO Access Register Map 6 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO6_t;


/** Data FIFO Access Register Map 7 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO7_t;


/** Data FIFO Access Register Map 8 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO8_t;


/** Data FIFO Access Register Map 9 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO9_t;


/** Data FIFO Access Register Map 10 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO10_t;


/** Data FIFO Access Register Map 11 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO11_t;


/** Data FIFO Access Register Map 12 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO12_t;


/** Data FIFO Access Register Map 13 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO13_t;


/** Data FIFO Access Register Map 14 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO14_t;


/** Data FIFO Access Register Map 15 */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFO15_t;


/** Data FIFO Direct Access Register Map */
typedef union {
    uint32_t r32;                                           /**< 32-bit access */
    uint16_t r16[2];                                        /**< 16-bit access */
    uint8_t  r8[4];                                         /**<  8-bit access */
} RegUsbDFIFODirectaccess_t;

/** @} end of group USB_Regs */



/***************************************************************************//**
 * @defgroup USB_RegMap USB Device Register Map
 * @{
 ******************************************************************************/
typedef struct
{
    __IO  RegUsbGOTGCTL_t                                   RegUsbGOTGCTL;                /**< OTG Control and Status Register
The OTG Control and Status register controls the behavior and reflects the status of the OTG function of the controller. */
    __IO  RegUsbGOTGINT_t                                   RegUsbGOTGINT;                /**< OTG Interrupt Register
The application reads this register whenever there is an OTG interrupt and clears the bits in this register to clear the OTG interrupt. */
    __IO  RegUsbGAHBCFG_t                                   RegUsbGAHBCFG;                /**< AHB Configuration Register
This register can be used to configure the core after power-on or a change in mode. This register mainly contains AHB system-related configuration parameters. Do not change this register after the initial programming. The application must program this register before starting any transactions on either the AHB or the USB. */
    __IO  RegUsbGUSBCFG_t                                   RegUsbGUSBCFG;                /**< USB Configuration Register
This register can be used to configure the core after power-on or when changing to Host mode or Device mode. It contains USB and USB-PHY related configuration parameters. The application must program this register before starting any transactions on either the AHB or the USB. If you are using the HSIC interface, HSIC PHY must be in reset while programming this register. Do not make changes to this register after the initial programming. */
    __IO  RegUsbGRSTCTL_t                                   RegUsbGRSTCTL;                /**< Reset Register
The application uses this register to reset various hardware features inside the controller. */
    __IO  RegUsbGINTSTS_t                                   RegUsbGINTSTS;                /**< Interrupt Register

This register interrupts the application for system-level events in the current mode (Device mode or Host mode).
Some of the bits in this register are valid only in Host mode, while others are valid in Device mode only. This register also indicates the current mode. To clear the interrupt status bits of type R_SS_WC, the application must write 1'b1 to the bit.
The FIFO status interrupts are read only; once software reads from or writes to the FIFO while servicing these interrupts, FIFO interrupt conditions are cleared automatically.
The application must clear the GINTSTS register at initialization before unmasking the interrupt bit to avoid any interrupts generated prior to initialization.

Note: Read the reset value of GINTSTS.CurMod only after the following conditions:
 - If IDDIG_FILTER is disabled, read only after PHY clock is stable.
 - If IDDIG_FILTER is enabled, read only after the filter timer expires. */
    __IO  RegUsbGINTMSK_t                                   RegUsbGINTMSK;                /**< Interrupt Mask Register
This register works with the Interrupt Register (GINTSTS) to interrupt the application. When an interrupt bit is masked, the interrupt associated with that bit is not generated. However, the GINTSTS register bit corresponding to that interrupt is still set.

Note: The fields of this register change depending on host or device mode. */
    __I   RegUsbGRXSTSR_t                                   RegUsbGRXSTSR;                /**< Receive Status Debug Read Register
A read to the Receive Status Debug Read register returns the contents of the top of the Receive FIFO.

The receive status contents must be interpreted differently in Host and Device modes. The core ignores the receive status read when the receive FIFO is empty and returns a value of 32'h0000_0000.

Note:
 - Use of these fields vary based on whether the core is functioning as a host or a device.
 - Do not read this register's reset value before configuring the core because the read value is 'X' in the simulation. */
    __I   RegUsbGRXSTSP_t                                   RegUsbGRXSTSP;                /**< Receive Status Read/Pop Register
A read to the Receive Status Read and Pop register returns the contents of the top of the Receive FIFO and additionally pops the top data entry out of the RxFIFO.
The receive status contents must be interpreted differently in Host and Device modes. The core ignores the receive status pop/read when the receive FIFO is empty and returns a value of 32'h0000_0000. The application must only pop the Receive Status FIFO when the Receive FIFO Non-Empty bit of the Core Interrupt register (GINTSTS.RxFLvl) is asserted.

Note:
 - Use of these fields vary based on whether the core is functioning as a host or a device.
 - Do not read this register's reset value before configuring the core because the read value is 'X' in the simulation. */
    __IO  RegUsbGRXFSIZ_t                                   RegUsbGRXFSIZ;                /**< Receive FIFO Size Register
The application can program the RAM size that must be allocated to the RxFIFO. */
    __IO  RegUsbGNPTXFSIZ_t                                 RegUsbGNPTXFSIZ;              /**< Non-periodic Transmit FIFO Size Register
The application can program the RAM size and the memory start address for the Non-periodic TxFIFO

Note: The fields of this register change depending on host or device mode. */
    __I   RegUsbGNPTXSTS_t                                  RegUsbGNPTXSTS;               /**< Non-periodic Transmit FIFO/Queue Status Register
In Device mode, this register is valid only in Shared FIFO operation.
This read-only register contains the free space information for the Non-periodic TxFIFO and the Non-periodic Transmit Request Queue. */
          reg32_t  RESERVED0[4];                                                          /**< RESERVED */
    __I   RegUsbGSNPSID_t                                   RegUsbGSNPSID;                /**< Synopsys ID Register

This read-only register contains the release number of the core being used. */
    __I   RegUsbGHWCFG1_t                                   RegUsbGHWCFG1;                /**< User Hardware Configuration 1 Register

This register contains the logical endpoint direction(s) selected using coreConsultant. */
    __I   RegUsbGHWCFG2_t                                   RegUsbGHWCFG2;                /**< User Hardware Configuration 2 Register

This register contains configuration options selected using coreConsultant. */
    __I   RegUsbGHWCFG3_t                                   RegUsbGHWCFG3;                /**< User Hardware Configuration 3 Register */
    __I   RegUsbGHWCFG4_t                                   RegUsbGHWCFG4;                /**< User Hardware Configuration 4 Register

Note: Bit [31] is available only when Scatter/Gather DMA mode is enabled. When Scatter/Gather DMA mode is disabled, this field is reserved. */
          reg32_t  RESERVED1[5];                                                          /**< RESERVED */
    __IO  RegUsbGINTMSK2_t                                  RegUsbGINTMSK2;               /**< Interrupt Mask Register 2
This register works with the Interrupt Register (GINTSTS2) to interrupt the application. When an interrupt bit is masked, the interrupt associated with that bit is not generated. However, the GINTSTS2 register bit corresponding to that interrupt is still set.

Note: The fields of this register change depending on host or device mode. */
    __IO  RegUsbGINTSTS2_t                                  RegUsbGINTSTS2;               /**< Interrupt Register 2

This register interrupts the application for system-level events in the current mode (Device mode or Host mode).
Some of the bits in this register are valid only in Host mode, while others are valid in Device mode only. This register also indicates the current mode. To clear the interrupt status bits of type R_SS_WC, the application must write 1'b1 to the bit.
The application must clear the GINTSTS2 register at initialization before unmasking the interrupt bit to avoid any interrupts generated prior to initialization. */
          reg32_t  RESERVED2[37];                                                         /**< RESERVED */
    __IO  RegUsbDPTXFSIZ1_t                                 RegUsbDPTXFSIZ1;              /**< Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
    __IO  RegUsbDPTXFSIZ2_t                                 RegUsbDPTXFSIZ2;              /**< Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
    __IO  RegUsbDPTXFSIZ3_t                                 RegUsbDPTXFSIZ3;              /**< Device Periodic Transmit FIFO-i Size Register $i

This register is valid only in shared FIFO operation (OTG_EN_DED_TX_FIFO = 0).

This register holds the memory start address of each periodic TxFIFO to be implemented in Device mode, as shown in "PMU Logic" and "PMU Sync Module" sections in the databook. Each periodic FIFO holds the data for one periodic IN endpoint.
This register is repeated for each periodic FIFO instantiated. */
          reg32_t  RESERVED3[444];                                                        /**< RESERVED */
    __IO  RegUsbDCFG_t                                      RegUsbDCFG;                   /**< Device Configuration Register

This register configures the core in Device mode after power-on or after certain control commands or enumeration. Do not make changes to this register after initial programming. */
    __IO  RegUsbDCTL_t                                      RegUsbDCTL;                   /**< Device Control Register */
    __I   RegUsbDSTS_t                                      RegUsbDSTS;                   /**< Device Status Register

This register indicates the status of the core with respect to USB-related events. It must be read on interrupts from Device All Interrupts (DAINT) register. */
          reg32_t  RESERVED4;                                                             /**< RESERVED */
    __IO  RegUsbDIEPMSK_t                                   RegUsbDIEPMSK;                /**< Device IN Endpoint Common Interrupt Mask Register

This register works with each of the Device IN Endpoint Interrupt (DIEPINTn) registers for all endpoints to generate an interrupt per IN endpoint. The IN endpoint interrupt for a specific status in the DIEPINTn register can be masked by writing to the corresponding bit in this register. Status bits are masked by default. */
    __IO  RegUsbDOEPMSK_t                                   RegUsbDOEPMSK;                /**< Device OUT Endpoint Common Interrupt Mask Register

This register works with each of the Device OUT Endpoint Interrupt (DOEPINTn) registers for all endpoints to generate an interrupt per OUT endpoint. The OUT endpoint interrupt for a specific status in the DOEPINTn register can be masked by writing into the corresponding bit in this register. Status bits are masked by default. */
    __I   RegUsbDAINT_t                                     RegUsbDAINT;                  /**< Device All Endpoints Interrupt Register

When a significant event occurs on an endpoint, a Device All Endpoints Interrupt register interrupts the
application using the Device OUT Endpoints Interrupt bit or Device IN Endpoints Interrupt bit of the Core
Interrupt register (GINTSTS.OEPInt or GINTSTS.IEPInt, respectively). This is shown in Figure 5-2. There is
one interrupt bit per endpoint, up to a maximum of 16 bits for OUT endpoints and 16 bits for IN endpoints.
For a bidirectional endpoint, the corresponding IN and OUT interrupt bits are used. Bits in this register are
set and cleared when the application sets and clears bits in the corresponding Device Endpoint-n Interrupt
register (DIEPINTn/DOEPINTn). */
    __IO  RegUsbDAINTMSK_t                                  RegUsbDAINTMSK;               /**< Device All Endpoints Interrupt Mask Register

 The Device Endpoint Interrupt Mask register works with the Device Endpoint Interrupt register to interrupt the application when an event occurs on a device endpoint. However, the Device All Endpoints Interrupt (DAINT) register bit corresponding to that interrupt is still set. */
    __I   RegUsbDTKNQR1_t                                   RegUsbDTKNQR1;                /**< Device IN Token Sequence Learning Queue Read Register 1

 This register is valid only in non-periodic Shared FIFO operation (OTG_EN_DED_TX_FIFO = 0). The depth of the IN Token Sequence Learning Queue is specified for Device Mode IN Token Sequence Learning Queue Depth during coreConsultant configuration (parameter OTG_TOKEN_QUEUE_DEPTH). The queue is 4 bits wide to store the endpoint number. A read from this register returns the first 5 endpoint entries of the IN Token Sequence Learning Queue. When the queue is full, the new token is pushed into the queue and oldest token is discarded. */
    __I   RegUsbDTKNQR2_t                                   RegUsbDTKNQR2;                /**< Device IN Token Sequence Learning Queue Read Register 2

 This register is valid only in shared non-periodic Shared FIFO operation (OTG_EN_DED_TX_FIFO = 0). A read from this register returns the next 8 endpoint entries of the learning queue. */
    __IO  RegUsbDVBUSDIS_t                                  RegUsbDVBUSDIS;               /**< Device VBUS Discharge Time Register

 This register specifies the VBUS discharge time after VBUS pulsing during SRP. */
    __IO  RegUsbDVBUSPULSE_t                                RegUsbDVBUSPULSE;             /**< Device VBUS Pulsing Time Register */
    __I   RegUsbDTKNQR3_t                                   RegUsbDTKNQR3;                /**< Device IN Token Sequence Learning Queue Read Register 3 */
    __I   RegUsbDTKNQR4_t                                   RegUsbDTKNQR4;                /**< Device IN Token Sequence Learning Queue Read Register 4 */
    __I   RegUsbDEACHINT_t                                  RegUsbDEACHINT;               /**< Device Each Endpoints Interrupt Register

 Dependency: This register is available in device mode and only when parameter "OTG_MULTI_PROC_INTRPT" on page 121=1. There is one interrupt bit per endpoint, up to a maximum of 16 bits for OUT endpoints and 16 bits for IN endpoints. For a bidirectional endpoint, the corresponding IN and OUT interrupt bits are used. Bits in this register are set and cleared when the application sets and clears bits in the corresponding Device Endpoint-n Interrupt register (DIEPINTn/DOEPINTn). The interrupt is automatically cleared once the DOEPINTn/DIEPINTn interrupt is cleared by the application.
 */
    __IO  RegUsbDEACHINTMSK_t                               RegUsbDEACHINTMSK;            /**< Device Each Endpoints Interrupt Mask Register

Dependency: This register is available only when parameter OTG_MULTI_PROC_INTRPT=1. The Device Each Endpoint Interrupt Mask register works with the Device Each Endpoint Interrupt register to interrupt the application when an event occurs on a device endpoint. However, the Device Each Endpoints Interrupt (DEACHINT) register bit corresponding to that interrupt remains set.
 */
    __IO  RegUsbDIEPEACHMSK0_t                              RegUsbDIEPEACHMSK0;           /**< Device Each IN Endpoint 0 Interrupt Register


Dependency: This register is available in device mode and only when parameter "OTG_MULTI_PROC_INTRPT" on page 121=1. These registers are endpoint-specific mask registers for (DIEPINTn). The IN endpoint interrupt for a specific status in the DIEPINTn register can be masked by writing 0 to the corresponding bit in this register. Status bits are masked by default.
 - Mask interrupt: 1'b0
 - Unmask interrupt: 1'b1
 */
    __IO  RegUsbDIEPEACHMSK1_t                              RegUsbDIEPEACHMSK1;           /**< Device Each IN Endpoint 1 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
    __IO  RegUsbDIEPEACHMSK2_t                              RegUsbDIEPEACHMSK2;           /**< Device Each IN Endpoint 2 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
    __IO  RegUsbDIEPEACHMSK3_t                              RegUsbDIEPEACHMSK3;           /**< Device Each IN Endpoint 3 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED5[12];                                                         /**< RESERVED */
    __IO  RegUsbDOEPEACHMSK0_t                              RegUsbDOEPEACHMSK0;           /**< Device Each OUT Endpoint 0 Interrupt Register
Dependency: This register is available in device mode and only when parameter OTG_MULTI_PROC_INTRPT=1. These registers are endpoint specific mask registers for (DOEPINTn). The OUT endpoint interrupt for a specific status in the DOEPINTn register can be masked by writing 0 to the corresponding bit in this register. Status bits are masked by default. */
    __IO  RegUsbDOEPEACHMSK1_t                              RegUsbDOEPEACHMSK1;           /**< Device Each OUT Endpoint 1 Interrupt Register */
    __IO  RegUsbDOEPEACHMSK2_t                              RegUsbDOEPEACHMSK2;           /**< Device Each OUT Endpoint 2 Interrupt Register */
    __IO  RegUsbDOEPEACHMSK3_t                              RegUsbDOEPEACHMSK3;           /**< Device Each OUT Endpoint 3 Interrupt Register */
          reg32_t  RESERVED6[28];                                                         /**< RESERVED */
    __IO  RegUsbDIEPCTL0_t                                  RegUsbDIEPCTL0;               /**< Device Control IN Endpoint 0 Control Register */
          reg32_t  RESERVED7;                                                             /**< RESERVED */
    __IO  RegUsbDIEPINT0_t                                  RegUsbDIEPINT0;               /**< Device IN Endpoint 0 Interrupt Register

 This register indicates the status of an endpoint with respect to USB- and AHB-related events. It is shown in the "Interrupt Hierarchy" figure in the databook. The application must read this register when the OUT Endpoints Interrupt bit or IN Endpoints Interrupt bit of the Core Interrupt register (GINTSTS.OEPInt or GINTSTS.IEPInt, respectively) is set. Before the application can read this register, it must first read the Device All Endpoints Interrupt (DAINT) register to get the exact endpoint number for the Device Endpoint-n Interrupt register. The application must clear the appropriate bit in this register to clear the corresponding bits in the DAINT and GINTSTS registers */
          reg32_t  RESERVED8;                                                             /**< RESERVED */
    __IO  RegUsbDIEPTSIZ0_t                                 RegUsbDIEPTSIZ0;              /**< Device IN Endpoint 0 Transfer Size Register


The application must modify this register before enabling endpoint 0. Once endpoint 0 is enabled using Endpoint Enable bit of the Device Control Endpoint 0 Control registers (DIEPCTL0.EPEna/DOEPCTL0.EPEna), the core modifies this register. The application can only read this register once the core has cleared the Endpoint Enable bit. Nonzero endpoints use the registers for endpoints 115. When Scatter/Gather DMA mode is enabled, this register must not be programmed by the application. If the application reads this register when Scatter/Gather DMA mode is enabled, the core returns all zeros. */
          reg32_t  RESERVED9;                                                             /**< RESERVED */
    __I   RegUsbDTXFSTS0_t                                  RegUsbDTXFSTS0;               /**< Device IN Endpoint Transmit FIFO Status Register 0 */
          reg32_t  RESERVED10;                                                            /**< RESERVED */
    __IO  RegUsbDIEPCTL1_t                                  RegUsbDIEPCTL1;               /**< Device Control IN Endpoint 1 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED11;                                                            /**< RESERVED */
    __IO  RegUsbDIEPINT1_t                                  RegUsbDIEPINT1;               /**< Device IN Endpoint 1 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED12;                                                            /**< RESERVED */
    __IO  RegUsbDIEPTSIZ1_t                                 RegUsbDIEPTSIZ1;              /**< Device IN Endpoint 1 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED13;                                                            /**< RESERVED */
    __I   RegUsbDTXFSTS1_t                                  RegUsbDTXFSTS1;               /**< Device IN Endpoint Transmit FIFO Status Register 1

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED14;                                                            /**< RESERVED */
    __IO  RegUsbDIEPCTL2_t                                  RegUsbDIEPCTL2;               /**< Device Control IN Endpoint 2 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED15;                                                            /**< RESERVED */
    __IO  RegUsbDIEPINT2_t                                  RegUsbDIEPINT2;               /**< Device IN Endpoint 2 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED16;                                                            /**< RESERVED */
    __IO  RegUsbDIEPTSIZ2_t                                 RegUsbDIEPTSIZ2;              /**< Device IN Endpoint 2 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED17;                                                            /**< RESERVED */
    __I   RegUsbDTXFSTS2_t                                  RegUsbDTXFSTS2;               /**< Device IN Endpoint Transmit FIFO Status Register 2

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED18;                                                            /**< RESERVED */
    __IO  RegUsbDIEPCTL3_t                                  RegUsbDIEPCTL3;               /**< Device Control IN Endpoint 3 Control Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED19;                                                            /**< RESERVED */
    __IO  RegUsbDIEPINT3_t                                  RegUsbDIEPINT3;               /**< Device IN Endpoint 3 Interrupt Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED20;                                                            /**< RESERVED */
    __IO  RegUsbDIEPTSIZ3_t                                 RegUsbDIEPTSIZ3;              /**< Device IN Endpoint 3 Transfer Size Register

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED21;                                                            /**< RESERVED */
    __I   RegUsbDTXFSTS3_t                                  RegUsbDTXFSTS3;               /**< Device IN Endpoint Transmit FIFO Status Register 3

Note: This register exists for an endpoint i if the OTG_EP_DIR_i parameter is 0 or 1 for that endpoint. */
          reg32_t  RESERVED22[97];                                                        /**< RESERVED */
    __IO  RegUsbDOEPCTL0_t                                  RegUsbDOEPCTL0;               /**< Device Control OUT Endpoint 0 Control Register */
          reg32_t  RESERVED23;                                                            /**< RESERVED */
    __IO  RegUsbDOEPINT0_t                                  RegUsbDOEPINT0;               /**< Device OUT Endpoint 0 Interrupt Register */
          reg32_t  RESERVED24;                                                            /**< RESERVED */
    __IO  RegUsbDOEPTSIZ0_t                                 RegUsbDOEPTSIZ0;              /**< Device OUT Endpoint 0 Transfer Size Register */
          reg32_t  RESERVED25[3];                                                         /**< RESERVED */
    __IO  RegUsbDOEPCTL1_t                                  RegUsbDOEPCTL1;               /**< Device Control OUT Endpoint 1 Control Register */
          reg32_t  RESERVED26;                                                            /**< RESERVED */
    __IO  RegUsbDOEPINT1_t                                  RegUsbDOEPINT1;               /**< Device OUT Endpoint 1 Interrupt Register */
          reg32_t  RESERVED27;                                                            /**< RESERVED */
    __IO  RegUsbDOEPTSIZ1_t                                 RegUsbDOEPTSIZ1;              /**< Device OUT Endpoint 1 Transfer Size Register */
          reg32_t  RESERVED28[3];                                                         /**< RESERVED */
    __IO  RegUsbDOEPCTL2_t                                  RegUsbDOEPCTL2;               /**< Device Control OUT Endpoint 2 Control Register */
          reg32_t  RESERVED29;                                                            /**< RESERVED */
    __IO  RegUsbDOEPINT2_t                                  RegUsbDOEPINT2;               /**< Device OUT Endpoint 2 Interrupt Register */
          reg32_t  RESERVED30;                                                            /**< RESERVED */
    __IO  RegUsbDOEPTSIZ2_t                                 RegUsbDOEPTSIZ2;              /**< Device OUT Endpoint 2 Transfer Size Register */
          reg32_t  RESERVED31[3];                                                         /**< RESERVED */
    __IO  RegUsbDOEPCTL3_t                                  RegUsbDOEPCTL3;               /**< Device Control OUT Endpoint 3 Control Register */
          reg32_t  RESERVED32;                                                            /**< RESERVED */
    __IO  RegUsbDOEPINT3_t                                  RegUsbDOEPINT3;               /**< Device OUT Endpoint 3 Interrupt Register */
          reg32_t  RESERVED33;                                                            /**< RESERVED */
    __IO  RegUsbDOEPTSIZ3_t                                 RegUsbDOEPTSIZ3;              /**< Device OUT Endpoint 3 Transfer Size Register */
          reg32_t  RESERVED34[163];                                                       /**< RESERVED */
    __IO  RegUsbPCGCCTL_t                                   RegUsbPCGCCTL;                /**< Power and Clock Gating Control Register */
          reg32_t  RESERVED35[127];                                                       /**< RESERVED */
    __IO  RegUsbDFIFO0_t                                    RegUsbDFIFO0;                 /**< Data FIFO Access Register Map 0 */
          reg32_t  RESERVED36[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO1_t                                    RegUsbDFIFO1;                 /**< Data FIFO Access Register Map 1 */
          reg32_t  RESERVED37[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO2_t                                    RegUsbDFIFO2;                 /**< Data FIFO Access Register Map 2 */
          reg32_t  RESERVED38[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO3_t                                    RegUsbDFIFO3;                 /**< Data FIFO Access Register Map 3 */
          reg32_t  RESERVED39[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO4_t                                    RegUsbDFIFO4;                 /**< Data FIFO Access Register Map 4 */
          reg32_t  RESERVED40[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO5_t                                    RegUsbDFIFO5;                 /**< Data FIFO Access Register Map 5 */
          reg32_t  RESERVED41[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO6_t                                    RegUsbDFIFO6;                 /**< Data FIFO Access Register Map 6 */
          reg32_t  RESERVED42[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO7_t                                    RegUsbDFIFO7;                 /**< Data FIFO Access Register Map 7 */
          reg32_t  RESERVED43[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO8_t                                    RegUsbDFIFO8;                 /**< Data FIFO Access Register Map 8 */
          reg32_t  RESERVED44[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO9_t                                    RegUsbDFIFO9;                 /**< Data FIFO Access Register Map 9 */
          reg32_t  RESERVED45[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO10_t                                   RegUsbDFIFO10;                /**< Data FIFO Access Register Map 10 */
          reg32_t  RESERVED46[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO11_t                                   RegUsbDFIFO11;                /**< Data FIFO Access Register Map 11 */
          reg32_t  RESERVED47[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO12_t                                   RegUsbDFIFO12;                /**< Data FIFO Access Register Map 12 */
          reg32_t  RESERVED48[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO13_t                                   RegUsbDFIFO13;                /**< Data FIFO Access Register Map 13 */
          reg32_t  RESERVED49[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO14_t                                   RegUsbDFIFO14;                /**< Data FIFO Access Register Map 14 */
          reg32_t  RESERVED50[1023];                                                      /**< RESERVED */
    __IO  RegUsbDFIFO15_t                                   RegUsbDFIFO15;                /**< Data FIFO Access Register Map 15 */
          reg32_t  RESERVED51[16383];                                                     /**< RESERVED */
    __IO  RegUsbDFIFODirectaccess_t                         RegUsbDFIFODirectaccess;      /**< Data FIFO Direct Access Register Map */
} USB_RegMap_t;

/** @} end of group USB_RegMap */



/***************************************************************************//**
 * @defgroup USB_BitFields USB bit field definition
 * @{
 ******************************************************************************/


/**
 * @name RegUsbGOTGCTL
 * @{
 */
// RegUsbGOTGCTL.r32
#define  REG_USB_GOTGCTL_RESET_VALUE                        0x00090000u                   /**< Reset value of RegUsbGOTGCTL */
#define  REG_USB_GOTGCTL_MASK                               0x003900C0u                   /**< Mask for RegUsbGOTGCTL */

#define  USB_GOTGCTL_BVALID_OV_EN_SHIFT                     6                             /**< Shift for UsbGOTGCTLBvalidOvEn */
#define  USB_GOTGCTL_BVALID_OV_EN_MASK                      0x00000040u                   /**< Mask for UsbGOTGCTLBvalidOvEn */
#define  USB_GOTGCTL_BVALID_OV_EN_BMASK                     0x1u                          /**< Base mask for UsbGOTGCTLBvalidOvEn */
#define  USB_GOTGCTL_BVALID_OV_EN(x)                        (((x)&0x1u)<<6)               /**< Set UsbGOTGCTLBvalidOvEn in register */
#define  GET_USB_GOTGCTL_BVALID_OV_EN(reg)                  (((reg)>>6)&0x1u)             /**< Get UsbGOTGCTLBvalidOvEn from register */
#define  USB_GOTGCTL_BVALID_OV_VAL_SHIFT                    7                             /**< Shift for UsbGOTGCTLBvalidOvVal */
#define  USB_GOTGCTL_BVALID_OV_VAL_MASK                     0x00000080u                   /**< Mask for UsbGOTGCTLBvalidOvVal */
#define  USB_GOTGCTL_BVALID_OV_VAL_BMASK                    0x1u                          /**< Base mask for UsbGOTGCTLBvalidOvVal */
#define  USB_GOTGCTL_BVALID_OV_VAL(x)                       (((x)&0x1u)<<7)               /**< Set UsbGOTGCTLBvalidOvVal in register */
#define  GET_USB_GOTGCTL_BVALID_OV_VAL(reg)                 (((reg)>>7)&0x1u)             /**< Get UsbGOTGCTLBvalidOvVal from register */
#define  USB_GOTGCTL_CON_IDSTS_SHIFT                        16                            /**< Shift for UsbGOTGCTLConIDSts */
#define  USB_GOTGCTL_CON_IDSTS_MASK                         0x00010000u                   /**< Mask for UsbGOTGCTLConIDSts */
#define  USB_GOTGCTL_CON_IDSTS_BMASK                        0x1u                          /**< Base mask for UsbGOTGCTLConIDSts */
#define  USB_GOTGCTL_CON_IDSTS(x)                           (((x)&0x1u)<<16)              /**< Set UsbGOTGCTLConIDSts in register */
#define  GET_USB_GOTGCTL_CON_IDSTS(reg)                     (((reg)>>16)&0x1u)            /**< Get UsbGOTGCTLConIDSts from register */
#define  USB_GOTGCTL_BSES_VLD_SHIFT                         19                            /**< Shift for UsbGOTGCTLBSesVld */
#define  USB_GOTGCTL_BSES_VLD_MASK                          0x00080000u                   /**< Mask for UsbGOTGCTLBSesVld */
#define  USB_GOTGCTL_BSES_VLD_BMASK                         0x1u                          /**< Base mask for UsbGOTGCTLBSesVld */
#define  USB_GOTGCTL_BSES_VLD(x)                            (((x)&0x1u)<<19)              /**< Set UsbGOTGCTLBSesVld in register */
#define  GET_USB_GOTGCTL_BSES_VLD(reg)                      (((reg)>>19)&0x1u)            /**< Get UsbGOTGCTLBSesVld from register */
#define  USB_GOTGCTL_OTGVER_SHIFT                           20                            /**< Shift for UsbGOTGCTLOTGVer */
#define  USB_GOTGCTL_OTGVER_MASK                            0x00100000u                   /**< Mask for UsbGOTGCTLOTGVer */
#define  USB_GOTGCTL_OTGVER_BMASK                           0x1u                          /**< Base mask for UsbGOTGCTLOTGVer */
#define  USB_GOTGCTL_OTGVER(x)                              (((x)&0x1u)<<20)              /**< Set UsbGOTGCTLOTGVer in register */
#define  GET_USB_GOTGCTL_OTGVER(reg)                        (((reg)>>20)&0x1u)            /**< Get UsbGOTGCTLOTGVer from register */
#define  USB_GOTGCTL_CUR_MOD_SHIFT                          21                            /**< Shift for UsbGOTGCTLCurMod */
#define  USB_GOTGCTL_CUR_MOD_MASK                           0x00200000u                   /**< Mask for UsbGOTGCTLCurMod */
#define  USB_GOTGCTL_CUR_MOD_BMASK                          0x1u                          /**< Base mask for UsbGOTGCTLCurMod */
#define  USB_GOTGCTL_CUR_MOD(x)                             (((x)&0x1u)<<21)              /**< Set UsbGOTGCTLCurMod in register */
#define  GET_USB_GOTGCTL_CUR_MOD(reg)                       (((reg)>>21)&0x1u)            /**< Get UsbGOTGCTLCurMod from register */
/** @} */


/**
 * @name RegUsbGOTGINT
 * @{
 */
// RegUsbGOTGINT.r32
#define  REG_USB_GOTGINT_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGOTGINT */
#define  REG_USB_GOTGINT_MASK                               0x00060304u                   /**< Mask for RegUsbGOTGINT */

#define  USB_GOTGINT_SES_END_DET_SHIFT                      2                             /**< Shift for UsbGOTGINTSesEndDet */
#define  USB_GOTGINT_SES_END_DET_MASK                       0x00000004u                   /**< Mask for UsbGOTGINTSesEndDet */
#define  USB_GOTGINT_SES_END_DET_BMASK                      0x1u                          /**< Base mask for UsbGOTGINTSesEndDet */
#define  USB_GOTGINT_SES_END_DET(x)                         (((x)&0x1u)<<2)               /**< Set UsbGOTGINTSesEndDet in register */
#define  GET_USB_GOTGINT_SES_END_DET(reg)                   (((reg)>>2)&0x1u)             /**< Get UsbGOTGINTSesEndDet from register */
#define  USB_GOTGINT_SES_REQ_SUC_STS_CHNG_SHIFT             8                             /**< Shift for UsbGOTGINTSesReqSucStsChng */
#define  USB_GOTGINT_SES_REQ_SUC_STS_CHNG_MASK              0x00000100u                   /**< Mask for UsbGOTGINTSesReqSucStsChng */
#define  USB_GOTGINT_SES_REQ_SUC_STS_CHNG_BMASK             0x1u                          /**< Base mask for UsbGOTGINTSesReqSucStsChng */
#define  USB_GOTGINT_SES_REQ_SUC_STS_CHNG(x)                (((x)&0x1u)<<8)               /**< Set UsbGOTGINTSesReqSucStsChng in register */
#define  GET_USB_GOTGINT_SES_REQ_SUC_STS_CHNG(reg)          (((reg)>>8)&0x1u)             /**< Get UsbGOTGINTSesReqSucStsChng from register */
#define  USB_GOTGINT_HST_NEG_SUC_STS_CHNG_SHIFT             9                             /**< Shift for UsbGOTGINTHstNegSucStsChng */
#define  USB_GOTGINT_HST_NEG_SUC_STS_CHNG_MASK              0x00000200u                   /**< Mask for UsbGOTGINTHstNegSucStsChng */
#define  USB_GOTGINT_HST_NEG_SUC_STS_CHNG_BMASK             0x1u                          /**< Base mask for UsbGOTGINTHstNegSucStsChng */
#define  USB_GOTGINT_HST_NEG_SUC_STS_CHNG(x)                (((x)&0x1u)<<9)               /**< Set UsbGOTGINTHstNegSucStsChng in register */
#define  GET_USB_GOTGINT_HST_NEG_SUC_STS_CHNG(reg)          (((reg)>>9)&0x1u)             /**< Get UsbGOTGINTHstNegSucStsChng from register */
#define  USB_GOTGINT_HST_NEG_DET_SHIFT                      17                            /**< Shift for UsbGOTGINTHstNegDet */
#define  USB_GOTGINT_HST_NEG_DET_MASK                       0x00020000u                   /**< Mask for UsbGOTGINTHstNegDet */
#define  USB_GOTGINT_HST_NEG_DET_BMASK                      0x1u                          /**< Base mask for UsbGOTGINTHstNegDet */
#define  USB_GOTGINT_HST_NEG_DET(x)                         (((x)&0x1u)<<17)              /**< Set UsbGOTGINTHstNegDet in register */
#define  GET_USB_GOTGINT_HST_NEG_DET(reg)                   (((reg)>>17)&0x1u)            /**< Get UsbGOTGINTHstNegDet from register */
#define  USB_GOTGINT_ADEV_TOUTCHG_SHIFT                     18                            /**< Shift for UsbGOTGINTADevTOUTChg */
#define  USB_GOTGINT_ADEV_TOUTCHG_MASK                      0x00040000u                   /**< Mask for UsbGOTGINTADevTOUTChg */
#define  USB_GOTGINT_ADEV_TOUTCHG_BMASK                     0x1u                          /**< Base mask for UsbGOTGINTADevTOUTChg */
#define  USB_GOTGINT_ADEV_TOUTCHG(x)                        (((x)&0x1u)<<18)              /**< Set UsbGOTGINTADevTOUTChg in register */
#define  GET_USB_GOTGINT_ADEV_TOUTCHG(reg)                  (((reg)>>18)&0x1u)            /**< Get UsbGOTGINTADevTOUTChg from register */
/** @} */


/**
 * @name RegUsbGAHBCFG
 * @{
 */
// RegUsbGAHBCFG.r32
#define  REG_USB_GAHBCFG_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGAHBCFG */
#define  REG_USB_GAHBCFG_MASK                               0x00E000BFu                   /**< Mask for RegUsbGAHBCFG */

#define  USB_GAHBCFG_GLBL_INTR_MSK_SHIFT                    0                             /**< Shift for UsbGAHBCFGGlblIntrMsk */
#define  USB_GAHBCFG_GLBL_INTR_MSK_MASK                     0x00000001u                   /**< Mask for UsbGAHBCFGGlblIntrMsk */
#define  USB_GAHBCFG_GLBL_INTR_MSK_BMASK                    0x1u                          /**< Base mask for UsbGAHBCFGGlblIntrMsk */
#define  USB_GAHBCFG_GLBL_INTR_MSK(x)                       (((x)&0x1u)<<0)               /**< Set UsbGAHBCFGGlblIntrMsk in register */
#define  GET_USB_GAHBCFG_GLBL_INTR_MSK(reg)                 (((reg)>>0)&0x1u)             /**< Get UsbGAHBCFGGlblIntrMsk from register */
#define  USB_GAHBCFG_HBST_LEN_SHIFT                         1                             /**< Shift for UsbGAHBCFGHBstLen */
#define  USB_GAHBCFG_HBST_LEN_MASK                          0x0000001Eu                   /**< Mask for UsbGAHBCFGHBstLen */
#define  USB_GAHBCFG_HBST_LEN_BMASK                         0xFu                          /**< Base mask for UsbGAHBCFGHBstLen */
#define  USB_GAHBCFG_HBST_LEN(x)                            (((x)&0xFu)<<1)               /**< Set UsbGAHBCFGHBstLen in register */
#define  GET_USB_GAHBCFG_HBST_LEN(reg)                      (((reg)>>1)&0xFu)             /**< Get UsbGAHBCFGHBstLen from register */
#define  USB_GAHBCFG_DMAEN_SHIFT                            5                             /**< Shift for UsbGAHBCFGDMAEn */
#define  USB_GAHBCFG_DMAEN_MASK                             0x00000020u                   /**< Mask for UsbGAHBCFGDMAEn */
#define  USB_GAHBCFG_DMAEN_BMASK                            0x1u                          /**< Base mask for UsbGAHBCFGDMAEn */
#define  USB_GAHBCFG_DMAEN(x)                               (((x)&0x1u)<<5)               /**< Set UsbGAHBCFGDMAEn in register */
#define  GET_USB_GAHBCFG_DMAEN(reg)                         (((reg)>>5)&0x1u)             /**< Get UsbGAHBCFGDMAEn from register */
#define  USB_GAHBCFG_NPTX_FEMP_LVL_SHIFT                    7                             /**< Shift for UsbGAHBCFGNPTxFEmpLvl */
#define  USB_GAHBCFG_NPTX_FEMP_LVL_MASK                     0x00000080u                   /**< Mask for UsbGAHBCFGNPTxFEmpLvl */
#define  USB_GAHBCFG_NPTX_FEMP_LVL_BMASK                    0x1u                          /**< Base mask for UsbGAHBCFGNPTxFEmpLvl */
#define  USB_GAHBCFG_NPTX_FEMP_LVL(x)                       (((x)&0x1u)<<7)               /**< Set UsbGAHBCFGNPTxFEmpLvl in register */
#define  GET_USB_GAHBCFG_NPTX_FEMP_LVL(reg)                 (((reg)>>7)&0x1u)             /**< Get UsbGAHBCFGNPTxFEmpLvl from register */
#define  USB_GAHBCFG_REM_MEM_SUPP_SHIFT                     21                            /**< Shift for UsbGAHBCFGRemMemSupp */
#define  USB_GAHBCFG_REM_MEM_SUPP_MASK                      0x00200000u                   /**< Mask for UsbGAHBCFGRemMemSupp */
#define  USB_GAHBCFG_REM_MEM_SUPP_BMASK                     0x1u                          /**< Base mask for UsbGAHBCFGRemMemSupp */
#define  USB_GAHBCFG_REM_MEM_SUPP(x)                        (((x)&0x1u)<<21)              /**< Set UsbGAHBCFGRemMemSupp in register */
#define  GET_USB_GAHBCFG_REM_MEM_SUPP(reg)                  (((reg)>>21)&0x1u)            /**< Get UsbGAHBCFGRemMemSupp from register */
#define  USB_GAHBCFG_NOTI_ALL_DMA_WRIT_SHIFT                22                            /**< Shift for UsbGAHBCFGNotiAllDmaWrit */
#define  USB_GAHBCFG_NOTI_ALL_DMA_WRIT_MASK                 0x00400000u                   /**< Mask for UsbGAHBCFGNotiAllDmaWrit */
#define  USB_GAHBCFG_NOTI_ALL_DMA_WRIT_BMASK                0x1u                          /**< Base mask for UsbGAHBCFGNotiAllDmaWrit */
#define  USB_GAHBCFG_NOTI_ALL_DMA_WRIT(x)                   (((x)&0x1u)<<22)              /**< Set UsbGAHBCFGNotiAllDmaWrit in register */
#define  GET_USB_GAHBCFG_NOTI_ALL_DMA_WRIT(reg)             (((reg)>>22)&0x1u)            /**< Get UsbGAHBCFGNotiAllDmaWrit from register */
#define  USB_GAHBCFG_AHBSINGLE_SHIFT                        23                            /**< Shift for UsbGAHBCFGAHBSingle */
#define  USB_GAHBCFG_AHBSINGLE_MASK                         0x00800000u                   /**< Mask for UsbGAHBCFGAHBSingle */
#define  USB_GAHBCFG_AHBSINGLE_BMASK                        0x1u                          /**< Base mask for UsbGAHBCFGAHBSingle */
#define  USB_GAHBCFG_AHBSINGLE(x)                           (((x)&0x1u)<<23)              /**< Set UsbGAHBCFGAHBSingle in register */
#define  GET_USB_GAHBCFG_AHBSINGLE(reg)                     (((reg)>>23)&0x1u)            /**< Get UsbGAHBCFGAHBSingle from register */
/** @} */


/**
 * @name RegUsbGUSBCFG
 * @{
 */
// RegUsbGUSBCFG.r32
#define  REG_USB_GUSBCFG_RESET_VALUE                        0x00001440u                   /**< Reset value of RegUsbGUSBCFG */
#define  REG_USB_GUSBCFG_MASK                               0x94403C6Fu                   /**< Mask for RegUsbGUSBCFG */

#define  USB_GUSBCFG_TOUT_CAL_SHIFT                         0                             /**< Shift for UsbGUSBCFGTOutCal */
#define  USB_GUSBCFG_TOUT_CAL_MASK                          0x00000007u                   /**< Mask for UsbGUSBCFGTOutCal */
#define  USB_GUSBCFG_TOUT_CAL_BMASK                         0x7u                          /**< Base mask for UsbGUSBCFGTOutCal */
#define  USB_GUSBCFG_TOUT_CAL(x)                            (((x)&0x7u)<<0)               /**< Set UsbGUSBCFGTOutCal in register */
#define  GET_USB_GUSBCFG_TOUT_CAL(reg)                      (((reg)>>0)&0x7u)             /**< Get UsbGUSBCFGTOutCal from register */
#define  USB_GUSBCFG_PHYIF_SHIFT                            3                             /**< Shift for UsbGUSBCFGPHYIf */
#define  USB_GUSBCFG_PHYIF_MASK                             0x00000008u                   /**< Mask for UsbGUSBCFGPHYIf */
#define  USB_GUSBCFG_PHYIF_BMASK                            0x1u                          /**< Base mask for UsbGUSBCFGPHYIf */
#define  USB_GUSBCFG_PHYIF(x)                               (((x)&0x1u)<<3)               /**< Set UsbGUSBCFGPHYIf in register */
#define  GET_USB_GUSBCFG_PHYIF(reg)                         (((reg)>>3)&0x1u)             /**< Get UsbGUSBCFGPHYIf from register */
#define  USB_GUSBCFG_FSINTF_SHIFT                           5                             /**< Shift for UsbGUSBCFGFSIntf */
#define  USB_GUSBCFG_FSINTF_MASK                            0x00000020u                   /**< Mask for UsbGUSBCFGFSIntf */
#define  USB_GUSBCFG_FSINTF_BMASK                           0x1u                          /**< Base mask for UsbGUSBCFGFSIntf */
#define  USB_GUSBCFG_FSINTF(x)                              (((x)&0x1u)<<5)               /**< Set UsbGUSBCFGFSIntf in register */
#define  GET_USB_GUSBCFG_FSINTF(reg)                        (((reg)>>5)&0x1u)             /**< Get UsbGUSBCFGFSIntf from register */
#define  USB_GUSBCFG_PHYSEL_SHIFT                           6                             /**< Shift for UsbGUSBCFGPHYSel */
#define  USB_GUSBCFG_PHYSEL_MASK                            0x00000040u                   /**< Mask for UsbGUSBCFGPHYSel */
#define  USB_GUSBCFG_PHYSEL_BMASK                           0x1u                          /**< Base mask for UsbGUSBCFGPHYSel */
#define  USB_GUSBCFG_PHYSEL(x)                              (((x)&0x1u)<<6)               /**< Set UsbGUSBCFGPHYSel in register */
#define  GET_USB_GUSBCFG_PHYSEL(reg)                        (((reg)>>6)&0x1u)             /**< Get UsbGUSBCFGPHYSel from register */
#define  USB_GUSBCFG_USBTRD_TIM_SHIFT                       10                            /**< Shift for UsbGUSBCFGUSBTrdTim */
#define  USB_GUSBCFG_USBTRD_TIM_MASK                        0x00003C00u                   /**< Mask for UsbGUSBCFGUSBTrdTim */
#define  USB_GUSBCFG_USBTRD_TIM_BMASK                       0xFu                          /**< Base mask for UsbGUSBCFGUSBTrdTim */
#define  USB_GUSBCFG_USBTRD_TIM(x)                          (((x)&0xFu)<<10)              /**< Set UsbGUSBCFGUSBTrdTim in register */
#define  GET_USB_GUSBCFG_USBTRD_TIM(reg)                    (((reg)>>10)&0xFu)            /**< Get UsbGUSBCFGUSBTrdTim from register */
#define  USB_GUSBCFG_TERM_SEL_DLPULSE_SHIFT                 22                            /**< Shift for UsbGUSBCFGTermSelDLPulse */
#define  USB_GUSBCFG_TERM_SEL_DLPULSE_MASK                  0x00400000u                   /**< Mask for UsbGUSBCFGTermSelDLPulse */
#define  USB_GUSBCFG_TERM_SEL_DLPULSE_BMASK                 0x1u                          /**< Base mask for UsbGUSBCFGTermSelDLPulse */
#define  USB_GUSBCFG_TERM_SEL_DLPULSE(x)                    (((x)&0x1u)<<22)              /**< Set UsbGUSBCFGTermSelDLPulse in register */
#define  GET_USB_GUSBCFG_TERM_SEL_DLPULSE(reg)              (((reg)>>22)&0x1u)            /**< Get UsbGUSBCFGTermSelDLPulse from register */
#define  USB_GUSBCFG_IC_USBCAP_SHIFT                        26                            /**< Shift for UsbGUSBCFGICUSBCap */
#define  USB_GUSBCFG_IC_USBCAP_MASK                         0x04000000u                   /**< Mask for UsbGUSBCFGICUSBCap */
#define  USB_GUSBCFG_IC_USBCAP_BMASK                        0x1u                          /**< Base mask for UsbGUSBCFGICUSBCap */
#define  USB_GUSBCFG_IC_USBCAP(x)                           (((x)&0x1u)<<26)              /**< Set UsbGUSBCFGICUSBCap in register */
#define  GET_USB_GUSBCFG_IC_USBCAP(reg)                     (((reg)>>26)&0x1u)            /**< Get UsbGUSBCFGICUSBCap from register */
#define  USB_GUSBCFG_TX_END_DELAY_SHIFT                     28                            /**< Shift for UsbGUSBCFGTxEndDelay */
#define  USB_GUSBCFG_TX_END_DELAY_MASK                      0x10000000u                   /**< Mask for UsbGUSBCFGTxEndDelay */
#define  USB_GUSBCFG_TX_END_DELAY_BMASK                     0x1u                          /**< Base mask for UsbGUSBCFGTxEndDelay */
#define  USB_GUSBCFG_TX_END_DELAY(x)                        (((x)&0x1u)<<28)              /**< Set UsbGUSBCFGTxEndDelay in register */
#define  GET_USB_GUSBCFG_TX_END_DELAY(reg)                  (((reg)>>28)&0x1u)            /**< Get UsbGUSBCFGTxEndDelay from register */
#define  USB_GUSBCFG_CORRUPT_TX_PKT_SHIFT                   31                            /**< Shift for UsbGUSBCFGCorruptTxPkt */
#define  USB_GUSBCFG_CORRUPT_TX_PKT_MASK                    0x80000000u                   /**< Mask for UsbGUSBCFGCorruptTxPkt */
#define  USB_GUSBCFG_CORRUPT_TX_PKT_BMASK                   0x1u                          /**< Base mask for UsbGUSBCFGCorruptTxPkt */
#define  USB_GUSBCFG_CORRUPT_TX_PKT(x)                      (((x)&0x1u)<<31)              /**< Set UsbGUSBCFGCorruptTxPkt in register */
#define  GET_USB_GUSBCFG_CORRUPT_TX_PKT(reg)                (((reg)>>31)&0x1u)            /**< Get UsbGUSBCFGCorruptTxPkt from register */
/** @} */


/**
 * @name RegUsbGRSTCTL
 * @{
 */
// RegUsbGRSTCTL.r32
#define  REG_USB_GRSTCTL_RESET_VALUE                        0x80000000u                   /**< Reset value of RegUsbGRSTCTL */
#define  REG_USB_GRSTCTL_MASK                               0xC00007FBu                   /**< Mask for RegUsbGRSTCTL */

#define  USB_GRSTCTL_CSFT_RST_SHIFT                         0                             /**< Shift for UsbGRSTCTLCSftRst */
#define  USB_GRSTCTL_CSFT_RST_MASK                          0x00000001u                   /**< Mask for UsbGRSTCTLCSftRst */
#define  USB_GRSTCTL_CSFT_RST_BMASK                         0x1u                          /**< Base mask for UsbGRSTCTLCSftRst */
#define  USB_GRSTCTL_CSFT_RST(x)                            (((x)&0x1u)<<0)               /**< Set UsbGRSTCTLCSftRst in register */
#define  GET_USB_GRSTCTL_CSFT_RST(reg)                      (((reg)>>0)&0x1u)             /**< Get UsbGRSTCTLCSftRst from register */
#define  USB_GRSTCTL_PIUFSSFT_RST_SHIFT                     1                             /**< Shift for UsbGRSTCTLPIUFSSftRst */
#define  USB_GRSTCTL_PIUFSSFT_RST_MASK                      0x00000002u                   /**< Mask for UsbGRSTCTLPIUFSSftRst */
#define  USB_GRSTCTL_PIUFSSFT_RST_BMASK                     0x1u                          /**< Base mask for UsbGRSTCTLPIUFSSftRst */
#define  USB_GRSTCTL_PIUFSSFT_RST(x)                        (((x)&0x1u)<<1)               /**< Set UsbGRSTCTLPIUFSSftRst in register */
#define  GET_USB_GRSTCTL_PIUFSSFT_RST(reg)                  (((reg)>>1)&0x1u)             /**< Get UsbGRSTCTLPIUFSSftRst from register */
#define  USB_GRSTCTL_INTKN_QFLSH_SHIFT                      3                             /**< Shift for UsbGRSTCTLINTknQFlsh */
#define  USB_GRSTCTL_INTKN_QFLSH_MASK                       0x00000008u                   /**< Mask for UsbGRSTCTLINTknQFlsh */
#define  USB_GRSTCTL_INTKN_QFLSH_BMASK                      0x1u                          /**< Base mask for UsbGRSTCTLINTknQFlsh */
#define  USB_GRSTCTL_INTKN_QFLSH(x)                         (((x)&0x1u)<<3)               /**< Set UsbGRSTCTLINTknQFlsh in register */
#define  GET_USB_GRSTCTL_INTKN_QFLSH(reg)                   (((reg)>>3)&0x1u)             /**< Get UsbGRSTCTLINTknQFlsh from register */
#define  USB_GRSTCTL_RX_FFLSH_SHIFT                         4                             /**< Shift for UsbGRSTCTLRxFFlsh */
#define  USB_GRSTCTL_RX_FFLSH_MASK                          0x00000010u                   /**< Mask for UsbGRSTCTLRxFFlsh */
#define  USB_GRSTCTL_RX_FFLSH_BMASK                         0x1u                          /**< Base mask for UsbGRSTCTLRxFFlsh */
#define  USB_GRSTCTL_RX_FFLSH(x)                            (((x)&0x1u)<<4)               /**< Set UsbGRSTCTLRxFFlsh in register */
#define  GET_USB_GRSTCTL_RX_FFLSH(reg)                      (((reg)>>4)&0x1u)             /**< Get UsbGRSTCTLRxFFlsh from register */
#define  USB_GRSTCTL_TX_FFLSH_SHIFT                         5                             /**< Shift for UsbGRSTCTLTxFFlsh */
#define  USB_GRSTCTL_TX_FFLSH_MASK                          0x00000020u                   /**< Mask for UsbGRSTCTLTxFFlsh */
#define  USB_GRSTCTL_TX_FFLSH_BMASK                         0x1u                          /**< Base mask for UsbGRSTCTLTxFFlsh */
#define  USB_GRSTCTL_TX_FFLSH(x)                            (((x)&0x1u)<<5)               /**< Set UsbGRSTCTLTxFFlsh in register */
#define  GET_USB_GRSTCTL_TX_FFLSH(reg)                      (((reg)>>5)&0x1u)             /**< Get UsbGRSTCTLTxFFlsh from register */
#define  USB_GRSTCTL_TX_FNUM_SHIFT                          6                             /**< Shift for UsbGRSTCTLTxFNum */
#define  USB_GRSTCTL_TX_FNUM_MASK                           0x000007C0u                   /**< Mask for UsbGRSTCTLTxFNum */
#define  USB_GRSTCTL_TX_FNUM_BMASK                          0x1Fu                         /**< Base mask for UsbGRSTCTLTxFNum */
#define  USB_GRSTCTL_TX_FNUM(x)                             (((x)&0x1Fu)<<6)              /**< Set UsbGRSTCTLTxFNum in register */
#define  GET_USB_GRSTCTL_TX_FNUM(reg)                       (((reg)>>6)&0x1Fu)            /**< Get UsbGRSTCTLTxFNum from register */
#define  USB_GRSTCTL_DMAREQ_SHIFT                           30                            /**< Shift for UsbGRSTCTLDMAReq */
#define  USB_GRSTCTL_DMAREQ_MASK                            0x40000000u                   /**< Mask for UsbGRSTCTLDMAReq */
#define  USB_GRSTCTL_DMAREQ_BMASK                           0x1u                          /**< Base mask for UsbGRSTCTLDMAReq */
#define  USB_GRSTCTL_DMAREQ(x)                              (((x)&0x1u)<<30)              /**< Set UsbGRSTCTLDMAReq in register */
#define  GET_USB_GRSTCTL_DMAREQ(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbGRSTCTLDMAReq from register */
#define  USB_GRSTCTL_AHBIDLE_SHIFT                          31                            /**< Shift for UsbGRSTCTLAHBIdle */
#define  USB_GRSTCTL_AHBIDLE_MASK                           0x80000000u                   /**< Mask for UsbGRSTCTLAHBIdle */
#define  USB_GRSTCTL_AHBIDLE_BMASK                          0x1u                          /**< Base mask for UsbGRSTCTLAHBIdle */
#define  USB_GRSTCTL_AHBIDLE(x)                             (((x)&0x1u)<<31)              /**< Set UsbGRSTCTLAHBIdle in register */
#define  GET_USB_GRSTCTL_AHBIDLE(reg)                       (((reg)>>31)&0x1u)            /**< Get UsbGRSTCTLAHBIdle from register */
/** @} */


/**
 * @name RegUsbGINTSTS
 * @{
 */
// RegUsbGINTSTS.r32
#define  REG_USB_GINTSTS_RESET_VALUE                        0x00000020u                   /**< Reset value of RegUsbGINTSTS */
#define  REG_USB_GINTSTS_MASK                               0xD0FEFCFFu                   /**< Mask for RegUsbGINTSTS */

#define  USB_GINTSTS_CUR_MOD_SHIFT                          0                             /**< Shift for UsbGINTSTSCurMod */
#define  USB_GINTSTS_CUR_MOD_MASK                           0x00000001u                   /**< Mask for UsbGINTSTSCurMod */
#define  USB_GINTSTS_CUR_MOD_BMASK                          0x1u                          /**< Base mask for UsbGINTSTSCurMod */
#define  USB_GINTSTS_CUR_MOD(x)                             (((x)&0x1u)<<0)               /**< Set UsbGINTSTSCurMod in register */
#define  GET_USB_GINTSTS_CUR_MOD(reg)                       (((reg)>>0)&0x1u)             /**< Get UsbGINTSTSCurMod from register */
#define  USB_GINTSTS_MODE_MIS_SHIFT                         1                             /**< Shift for UsbGINTSTSModeMis */
#define  USB_GINTSTS_MODE_MIS_MASK                          0x00000002u                   /**< Mask for UsbGINTSTSModeMis */
#define  USB_GINTSTS_MODE_MIS_BMASK                         0x1u                          /**< Base mask for UsbGINTSTSModeMis */
#define  USB_GINTSTS_MODE_MIS(x)                            (((x)&0x1u)<<1)               /**< Set UsbGINTSTSModeMis in register */
#define  GET_USB_GINTSTS_MODE_MIS(reg)                      (((reg)>>1)&0x1u)             /**< Get UsbGINTSTSModeMis from register */
#define  USB_GINTSTS_OTGINT_SHIFT                           2                             /**< Shift for UsbGINTSTSOTGInt */
#define  USB_GINTSTS_OTGINT_MASK                            0x00000004u                   /**< Mask for UsbGINTSTSOTGInt */
#define  USB_GINTSTS_OTGINT_BMASK                           0x1u                          /**< Base mask for UsbGINTSTSOTGInt */
#define  USB_GINTSTS_OTGINT(x)                              (((x)&0x1u)<<2)               /**< Set UsbGINTSTSOTGInt in register */
#define  GET_USB_GINTSTS_OTGINT(reg)                        (((reg)>>2)&0x1u)             /**< Get UsbGINTSTSOTGInt from register */
#define  USB_GINTSTS_SOF_SHIFT                              3                             /**< Shift for UsbGINTSTSSof */
#define  USB_GINTSTS_SOF_MASK                               0x00000008u                   /**< Mask for UsbGINTSTSSof */
#define  USB_GINTSTS_SOF_BMASK                              0x1u                          /**< Base mask for UsbGINTSTSSof */
#define  USB_GINTSTS_SOF(x)                                 (((x)&0x1u)<<3)               /**< Set UsbGINTSTSSof in register */
#define  GET_USB_GINTSTS_SOF(reg)                           (((reg)>>3)&0x1u)             /**< Get UsbGINTSTSSof from register */
#define  USB_GINTSTS_RX_FLVL_SHIFT                          4                             /**< Shift for UsbGINTSTSRxFLvl */
#define  USB_GINTSTS_RX_FLVL_MASK                           0x00000010u                   /**< Mask for UsbGINTSTSRxFLvl */
#define  USB_GINTSTS_RX_FLVL_BMASK                          0x1u                          /**< Base mask for UsbGINTSTSRxFLvl */
#define  USB_GINTSTS_RX_FLVL(x)                             (((x)&0x1u)<<4)               /**< Set UsbGINTSTSRxFLvl in register */
#define  GET_USB_GINTSTS_RX_FLVL(reg)                       (((reg)>>4)&0x1u)             /**< Get UsbGINTSTSRxFLvl from register */
#define  USB_GINTSTS_NPTX_FEMP_SHIFT                        5                             /**< Shift for UsbGINTSTSNPTxFEmp */
#define  USB_GINTSTS_NPTX_FEMP_MASK                         0x00000020u                   /**< Mask for UsbGINTSTSNPTxFEmp */
#define  USB_GINTSTS_NPTX_FEMP_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSNPTxFEmp */
#define  USB_GINTSTS_NPTX_FEMP(x)                           (((x)&0x1u)<<5)               /**< Set UsbGINTSTSNPTxFEmp in register */
#define  GET_USB_GINTSTS_NPTX_FEMP(reg)                     (((reg)>>5)&0x1u)             /**< Get UsbGINTSTSNPTxFEmp from register */
#define  USB_GINTSTS_GINNAK_EFF_SHIFT                       6                             /**< Shift for UsbGINTSTSGINNakEff */
#define  USB_GINTSTS_GINNAK_EFF_MASK                        0x00000040u                   /**< Mask for UsbGINTSTSGINNakEff */
#define  USB_GINTSTS_GINNAK_EFF_BMASK                       0x1u                          /**< Base mask for UsbGINTSTSGINNakEff */
#define  USB_GINTSTS_GINNAK_EFF(x)                          (((x)&0x1u)<<6)               /**< Set UsbGINTSTSGINNakEff in register */
#define  GET_USB_GINTSTS_GINNAK_EFF(reg)                    (((reg)>>6)&0x1u)             /**< Get UsbGINTSTSGINNakEff from register */
#define  USB_GINTSTS_GOUTNAK_EFF_SHIFT                      7                             /**< Shift for UsbGINTSTSGOUTNakEff */
#define  USB_GINTSTS_GOUTNAK_EFF_MASK                       0x00000080u                   /**< Mask for UsbGINTSTSGOUTNakEff */
#define  USB_GINTSTS_GOUTNAK_EFF_BMASK                      0x1u                          /**< Base mask for UsbGINTSTSGOUTNakEff */
#define  USB_GINTSTS_GOUTNAK_EFF(x)                         (((x)&0x1u)<<7)               /**< Set UsbGINTSTSGOUTNakEff in register */
#define  GET_USB_GINTSTS_GOUTNAK_EFF(reg)                   (((reg)>>7)&0x1u)             /**< Get UsbGINTSTSGOUTNakEff from register */
#define  USB_GINTSTS_ERLY_SUSP_SHIFT                        10                            /**< Shift for UsbGINTSTSErlySusp */
#define  USB_GINTSTS_ERLY_SUSP_MASK                         0x00000400u                   /**< Mask for UsbGINTSTSErlySusp */
#define  USB_GINTSTS_ERLY_SUSP_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSErlySusp */
#define  USB_GINTSTS_ERLY_SUSP(x)                           (((x)&0x1u)<<10)              /**< Set UsbGINTSTSErlySusp in register */
#define  GET_USB_GINTSTS_ERLY_SUSP(reg)                     (((reg)>>10)&0x1u)            /**< Get UsbGINTSTSErlySusp from register */
#define  USB_GINTSTS_USBSUSP_SHIFT                          11                            /**< Shift for UsbGINTSTSUSBSusp */
#define  USB_GINTSTS_USBSUSP_MASK                           0x00000800u                   /**< Mask for UsbGINTSTSUSBSusp */
#define  USB_GINTSTS_USBSUSP_BMASK                          0x1u                          /**< Base mask for UsbGINTSTSUSBSusp */
#define  USB_GINTSTS_USBSUSP(x)                             (((x)&0x1u)<<11)              /**< Set UsbGINTSTSUSBSusp in register */
#define  GET_USB_GINTSTS_USBSUSP(reg)                       (((reg)>>11)&0x1u)            /**< Get UsbGINTSTSUSBSusp from register */
#define  USB_GINTSTS_USBRST_SHIFT                           12                            /**< Shift for UsbGINTSTSUSBRst */
#define  USB_GINTSTS_USBRST_MASK                            0x00001000u                   /**< Mask for UsbGINTSTSUSBRst */
#define  USB_GINTSTS_USBRST_BMASK                           0x1u                          /**< Base mask for UsbGINTSTSUSBRst */
#define  USB_GINTSTS_USBRST(x)                              (((x)&0x1u)<<12)              /**< Set UsbGINTSTSUSBRst in register */
#define  GET_USB_GINTSTS_USBRST(reg)                        (((reg)>>12)&0x1u)            /**< Get UsbGINTSTSUSBRst from register */
#define  USB_GINTSTS_ENUM_DONE_SHIFT                        13                            /**< Shift for UsbGINTSTSEnumDone */
#define  USB_GINTSTS_ENUM_DONE_MASK                         0x00002000u                   /**< Mask for UsbGINTSTSEnumDone */
#define  USB_GINTSTS_ENUM_DONE_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSEnumDone */
#define  USB_GINTSTS_ENUM_DONE(x)                           (((x)&0x1u)<<13)              /**< Set UsbGINTSTSEnumDone in register */
#define  GET_USB_GINTSTS_ENUM_DONE(reg)                     (((reg)>>13)&0x1u)            /**< Get UsbGINTSTSEnumDone from register */
#define  USB_GINTSTS_ISOOUT_DROP_SHIFT                      14                            /**< Shift for UsbGINTSTSISOOutDrop */
#define  USB_GINTSTS_ISOOUT_DROP_MASK                       0x00004000u                   /**< Mask for UsbGINTSTSISOOutDrop */
#define  USB_GINTSTS_ISOOUT_DROP_BMASK                      0x1u                          /**< Base mask for UsbGINTSTSISOOutDrop */
#define  USB_GINTSTS_ISOOUT_DROP(x)                         (((x)&0x1u)<<14)              /**< Set UsbGINTSTSISOOutDrop in register */
#define  GET_USB_GINTSTS_ISOOUT_DROP(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbGINTSTSISOOutDrop from register */
#define  USB_GINTSTS_EOPF_SHIFT                             15                            /**< Shift for UsbGINTSTSEOPF */
#define  USB_GINTSTS_EOPF_MASK                              0x00008000u                   /**< Mask for UsbGINTSTSEOPF */
#define  USB_GINTSTS_EOPF_BMASK                             0x1u                          /**< Base mask for UsbGINTSTSEOPF */
#define  USB_GINTSTS_EOPF(x)                                (((x)&0x1u)<<15)              /**< Set UsbGINTSTSEOPF in register */
#define  GET_USB_GINTSTS_EOPF(reg)                          (((reg)>>15)&0x1u)            /**< Get UsbGINTSTSEOPF from register */
#define  USB_GINTSTS_EPMIS_SHIFT                            17                            /**< Shift for UsbGINTSTSEPMis */
#define  USB_GINTSTS_EPMIS_MASK                             0x00020000u                   /**< Mask for UsbGINTSTSEPMis */
#define  USB_GINTSTS_EPMIS_BMASK                            0x1u                          /**< Base mask for UsbGINTSTSEPMis */
#define  USB_GINTSTS_EPMIS(x)                               (((x)&0x1u)<<17)              /**< Set UsbGINTSTSEPMis in register */
#define  GET_USB_GINTSTS_EPMIS(reg)                         (((reg)>>17)&0x1u)            /**< Get UsbGINTSTSEPMis from register */
#define  USB_GINTSTS_IEPINT_SHIFT                           18                            /**< Shift for UsbGINTSTSIEPInt */
#define  USB_GINTSTS_IEPINT_MASK                            0x00040000u                   /**< Mask for UsbGINTSTSIEPInt */
#define  USB_GINTSTS_IEPINT_BMASK                           0x1u                          /**< Base mask for UsbGINTSTSIEPInt */
#define  USB_GINTSTS_IEPINT(x)                              (((x)&0x1u)<<18)              /**< Set UsbGINTSTSIEPInt in register */
#define  GET_USB_GINTSTS_IEPINT(reg)                        (((reg)>>18)&0x1u)            /**< Get UsbGINTSTSIEPInt from register */
#define  USB_GINTSTS_OEPINT_SHIFT                           19                            /**< Shift for UsbGINTSTSOEPInt */
#define  USB_GINTSTS_OEPINT_MASK                            0x00080000u                   /**< Mask for UsbGINTSTSOEPInt */
#define  USB_GINTSTS_OEPINT_BMASK                           0x1u                          /**< Base mask for UsbGINTSTSOEPInt */
#define  USB_GINTSTS_OEPINT(x)                              (((x)&0x1u)<<19)              /**< Set UsbGINTSTSOEPInt in register */
#define  GET_USB_GINTSTS_OEPINT(reg)                        (((reg)>>19)&0x1u)            /**< Get UsbGINTSTSOEPInt from register */
#define  USB_GINTSTS_INCOMP_ISOIN_SHIFT                     20                            /**< Shift for UsbGINTSTSincompISOIN */
#define  USB_GINTSTS_INCOMP_ISOIN_MASK                      0x00100000u                   /**< Mask for UsbGINTSTSincompISOIN */
#define  USB_GINTSTS_INCOMP_ISOIN_BMASK                     0x1u                          /**< Base mask for UsbGINTSTSincompISOIN */
#define  USB_GINTSTS_INCOMP_ISOIN(x)                        (((x)&0x1u)<<20)              /**< Set UsbGINTSTSincompISOIN in register */
#define  GET_USB_GINTSTS_INCOMP_ISOIN(reg)                  (((reg)>>20)&0x1u)            /**< Get UsbGINTSTSincompISOIN from register */
#define  USB_GINTSTS_INCOMPL_P_SHIFT                        21                            /**< Shift for UsbGINTSTSincomplP */
#define  USB_GINTSTS_INCOMPL_P_MASK                         0x00200000u                   /**< Mask for UsbGINTSTSincomplP */
#define  USB_GINTSTS_INCOMPL_P_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSincomplP */
#define  USB_GINTSTS_INCOMPL_P(x)                           (((x)&0x1u)<<21)              /**< Set UsbGINTSTSincomplP in register */
#define  GET_USB_GINTSTS_INCOMPL_P(reg)                     (((reg)>>21)&0x1u)            /**< Get UsbGINTSTSincomplP from register */
#define  USB_GINTSTS_FET_SUSP_SHIFT                         22                            /**< Shift for UsbGINTSTSFetSusp */
#define  USB_GINTSTS_FET_SUSP_MASK                          0x00400000u                   /**< Mask for UsbGINTSTSFetSusp */
#define  USB_GINTSTS_FET_SUSP_BMASK                         0x1u                          /**< Base mask for UsbGINTSTSFetSusp */
#define  USB_GINTSTS_FET_SUSP(x)                            (((x)&0x1u)<<22)              /**< Set UsbGINTSTSFetSusp in register */
#define  GET_USB_GINTSTS_FET_SUSP(reg)                      (((reg)>>22)&0x1u)            /**< Get UsbGINTSTSFetSusp from register */
#define  USB_GINTSTS_RESET_DET_SHIFT                        23                            /**< Shift for UsbGINTSTSResetDet */
#define  USB_GINTSTS_RESET_DET_MASK                         0x00800000u                   /**< Mask for UsbGINTSTSResetDet */
#define  USB_GINTSTS_RESET_DET_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSResetDet */
#define  USB_GINTSTS_RESET_DET(x)                           (((x)&0x1u)<<23)              /**< Set UsbGINTSTSResetDet in register */
#define  GET_USB_GINTSTS_RESET_DET(reg)                     (((reg)>>23)&0x1u)            /**< Get UsbGINTSTSResetDet from register */
#define  USB_GINTSTS_CON_IDSTS_CHNG_SHIFT                   28                            /**< Shift for UsbGINTSTSConIDStsChng */
#define  USB_GINTSTS_CON_IDSTS_CHNG_MASK                    0x10000000u                   /**< Mask for UsbGINTSTSConIDStsChng */
#define  USB_GINTSTS_CON_IDSTS_CHNG_BMASK                   0x1u                          /**< Base mask for UsbGINTSTSConIDStsChng */
#define  USB_GINTSTS_CON_IDSTS_CHNG(x)                      (((x)&0x1u)<<28)              /**< Set UsbGINTSTSConIDStsChng in register */
#define  GET_USB_GINTSTS_CON_IDSTS_CHNG(reg)                (((reg)>>28)&0x1u)            /**< Get UsbGINTSTSConIDStsChng from register */
#define  USB_GINTSTS_SESS_REQ_INT_SHIFT                     30                            /**< Shift for UsbGINTSTSSessReqInt */
#define  USB_GINTSTS_SESS_REQ_INT_MASK                      0x40000000u                   /**< Mask for UsbGINTSTSSessReqInt */
#define  USB_GINTSTS_SESS_REQ_INT_BMASK                     0x1u                          /**< Base mask for UsbGINTSTSSessReqInt */
#define  USB_GINTSTS_SESS_REQ_INT(x)                        (((x)&0x1u)<<30)              /**< Set UsbGINTSTSSessReqInt in register */
#define  GET_USB_GINTSTS_SESS_REQ_INT(reg)                  (((reg)>>30)&0x1u)            /**< Get UsbGINTSTSSessReqInt from register */
#define  USB_GINTSTS_WK_UP_INT_SHIFT                        31                            /**< Shift for UsbGINTSTSWkUpInt */
#define  USB_GINTSTS_WK_UP_INT_MASK                         0x80000000u                   /**< Mask for UsbGINTSTSWkUpInt */
#define  USB_GINTSTS_WK_UP_INT_BMASK                        0x1u                          /**< Base mask for UsbGINTSTSWkUpInt */
#define  USB_GINTSTS_WK_UP_INT(x)                           (((x)&0x1u)<<31)              /**< Set UsbGINTSTSWkUpInt in register */
#define  GET_USB_GINTSTS_WK_UP_INT(reg)                     (((reg)>>31)&0x1u)            /**< Get UsbGINTSTSWkUpInt from register */
/** @} */


/**
 * @name RegUsbGINTMSK
 * @{
 */
// RegUsbGINTMSK.r32
#define  REG_USB_GINTMSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGINTMSK */
#define  REG_USB_GINTMSK_MASK                               0xF0EEFCFEu                   /**< Mask for RegUsbGINTMSK */

#define  USB_GINTMSK_MODE_MIS_MSK_SHIFT                     1                             /**< Shift for UsbGINTMSKModeMisMsk */
#define  USB_GINTMSK_MODE_MIS_MSK_MASK                      0x00000002u                   /**< Mask for UsbGINTMSKModeMisMsk */
#define  USB_GINTMSK_MODE_MIS_MSK_BMASK                     0x1u                          /**< Base mask for UsbGINTMSKModeMisMsk */
#define  USB_GINTMSK_MODE_MIS_MSK(x)                        (((x)&0x1u)<<1)               /**< Set UsbGINTMSKModeMisMsk in register */
#define  GET_USB_GINTMSK_MODE_MIS_MSK(reg)                  (((reg)>>1)&0x1u)             /**< Get UsbGINTMSKModeMisMsk from register */
#define  USB_GINTMSK_OTGINT_MSK_SHIFT                       2                             /**< Shift for UsbGINTMSKOTGIntMsk */
#define  USB_GINTMSK_OTGINT_MSK_MASK                        0x00000004u                   /**< Mask for UsbGINTMSKOTGIntMsk */
#define  USB_GINTMSK_OTGINT_MSK_BMASK                       0x1u                          /**< Base mask for UsbGINTMSKOTGIntMsk */
#define  USB_GINTMSK_OTGINT_MSK(x)                          (((x)&0x1u)<<2)               /**< Set UsbGINTMSKOTGIntMsk in register */
#define  GET_USB_GINTMSK_OTGINT_MSK(reg)                    (((reg)>>2)&0x1u)             /**< Get UsbGINTMSKOTGIntMsk from register */
#define  USB_GINTMSK_SOF_MSK_SHIFT                          3                             /**< Shift for UsbGINTMSKSofMsk */
#define  USB_GINTMSK_SOF_MSK_MASK                           0x00000008u                   /**< Mask for UsbGINTMSKSofMsk */
#define  USB_GINTMSK_SOF_MSK_BMASK                          0x1u                          /**< Base mask for UsbGINTMSKSofMsk */
#define  USB_GINTMSK_SOF_MSK(x)                             (((x)&0x1u)<<3)               /**< Set UsbGINTMSKSofMsk in register */
#define  GET_USB_GINTMSK_SOF_MSK(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbGINTMSKSofMsk from register */
#define  USB_GINTMSK_RX_FLVL_MSK_SHIFT                      4                             /**< Shift for UsbGINTMSKRxFLvlMsk */
#define  USB_GINTMSK_RX_FLVL_MSK_MASK                       0x00000010u                   /**< Mask for UsbGINTMSKRxFLvlMsk */
#define  USB_GINTMSK_RX_FLVL_MSK_BMASK                      0x1u                          /**< Base mask for UsbGINTMSKRxFLvlMsk */
#define  USB_GINTMSK_RX_FLVL_MSK(x)                         (((x)&0x1u)<<4)               /**< Set UsbGINTMSKRxFLvlMsk in register */
#define  GET_USB_GINTMSK_RX_FLVL_MSK(reg)                   (((reg)>>4)&0x1u)             /**< Get UsbGINTMSKRxFLvlMsk from register */
#define  USB_GINTMSK_NPTX_FEMP_MSK_SHIFT                    5                             /**< Shift for UsbGINTMSKNPTxFEmpMsk */
#define  USB_GINTMSK_NPTX_FEMP_MSK_MASK                     0x00000020u                   /**< Mask for UsbGINTMSKNPTxFEmpMsk */
#define  USB_GINTMSK_NPTX_FEMP_MSK_BMASK                    0x1u                          /**< Base mask for UsbGINTMSKNPTxFEmpMsk */
#define  USB_GINTMSK_NPTX_FEMP_MSK(x)                       (((x)&0x1u)<<5)               /**< Set UsbGINTMSKNPTxFEmpMsk in register */
#define  GET_USB_GINTMSK_NPTX_FEMP_MSK(reg)                 (((reg)>>5)&0x1u)             /**< Get UsbGINTMSKNPTxFEmpMsk from register */
#define  USB_GINTMSK_GINNAK_EFF_MSK_SHIFT                   6                             /**< Shift for UsbGINTMSKGINNakEffMsk */
#define  USB_GINTMSK_GINNAK_EFF_MSK_MASK                    0x00000040u                   /**< Mask for UsbGINTMSKGINNakEffMsk */
#define  USB_GINTMSK_GINNAK_EFF_MSK_BMASK                   0x1u                          /**< Base mask for UsbGINTMSKGINNakEffMsk */
#define  USB_GINTMSK_GINNAK_EFF_MSK(x)                      (((x)&0x1u)<<6)               /**< Set UsbGINTMSKGINNakEffMsk in register */
#define  GET_USB_GINTMSK_GINNAK_EFF_MSK(reg)                (((reg)>>6)&0x1u)             /**< Get UsbGINTMSKGINNakEffMsk from register */
#define  USB_GINTMSK_GOUTNAK_EFF_MSK_SHIFT                  7                             /**< Shift for UsbGINTMSKGOUTNakEffMsk */
#define  USB_GINTMSK_GOUTNAK_EFF_MSK_MASK                   0x00000080u                   /**< Mask for UsbGINTMSKGOUTNakEffMsk */
#define  USB_GINTMSK_GOUTNAK_EFF_MSK_BMASK                  0x1u                          /**< Base mask for UsbGINTMSKGOUTNakEffMsk */
#define  USB_GINTMSK_GOUTNAK_EFF_MSK(x)                     (((x)&0x1u)<<7)               /**< Set UsbGINTMSKGOUTNakEffMsk in register */
#define  GET_USB_GINTMSK_GOUTNAK_EFF_MSK(reg)               (((reg)>>7)&0x1u)             /**< Get UsbGINTMSKGOUTNakEffMsk from register */
#define  USB_GINTMSK_ERLY_SUSP_MSK_SHIFT                    10                            /**< Shift for UsbGINTMSKErlySuspMsk */
#define  USB_GINTMSK_ERLY_SUSP_MSK_MASK                     0x00000400u                   /**< Mask for UsbGINTMSKErlySuspMsk */
#define  USB_GINTMSK_ERLY_SUSP_MSK_BMASK                    0x1u                          /**< Base mask for UsbGINTMSKErlySuspMsk */
#define  USB_GINTMSK_ERLY_SUSP_MSK(x)                       (((x)&0x1u)<<10)              /**< Set UsbGINTMSKErlySuspMsk in register */
#define  GET_USB_GINTMSK_ERLY_SUSP_MSK(reg)                 (((reg)>>10)&0x1u)            /**< Get UsbGINTMSKErlySuspMsk from register */
#define  USB_GINTMSK_USBSUSP_MSK_SHIFT                      11                            /**< Shift for UsbGINTMSKUSBSuspMsk */
#define  USB_GINTMSK_USBSUSP_MSK_MASK                       0x00000800u                   /**< Mask for UsbGINTMSKUSBSuspMsk */
#define  USB_GINTMSK_USBSUSP_MSK_BMASK                      0x1u                          /**< Base mask for UsbGINTMSKUSBSuspMsk */
#define  USB_GINTMSK_USBSUSP_MSK(x)                         (((x)&0x1u)<<11)              /**< Set UsbGINTMSKUSBSuspMsk in register */
#define  GET_USB_GINTMSK_USBSUSP_MSK(reg)                   (((reg)>>11)&0x1u)            /**< Get UsbGINTMSKUSBSuspMsk from register */
#define  USB_GINTMSK_USBRST_MSK_SHIFT                       12                            /**< Shift for UsbGINTMSKUSBRstMsk */
#define  USB_GINTMSK_USBRST_MSK_MASK                        0x00001000u                   /**< Mask for UsbGINTMSKUSBRstMsk */
#define  USB_GINTMSK_USBRST_MSK_BMASK                       0x1u                          /**< Base mask for UsbGINTMSKUSBRstMsk */
#define  USB_GINTMSK_USBRST_MSK(x)                          (((x)&0x1u)<<12)              /**< Set UsbGINTMSKUSBRstMsk in register */
#define  GET_USB_GINTMSK_USBRST_MSK(reg)                    (((reg)>>12)&0x1u)            /**< Get UsbGINTMSKUSBRstMsk from register */
#define  USB_GINTMSK_ENUM_DONE_MSK_SHIFT                    13                            /**< Shift for UsbGINTMSKEnumDoneMsk */
#define  USB_GINTMSK_ENUM_DONE_MSK_MASK                     0x00002000u                   /**< Mask for UsbGINTMSKEnumDoneMsk */
#define  USB_GINTMSK_ENUM_DONE_MSK_BMASK                    0x1u                          /**< Base mask for UsbGINTMSKEnumDoneMsk */
#define  USB_GINTMSK_ENUM_DONE_MSK(x)                       (((x)&0x1u)<<13)              /**< Set UsbGINTMSKEnumDoneMsk in register */
#define  GET_USB_GINTMSK_ENUM_DONE_MSK(reg)                 (((reg)>>13)&0x1u)            /**< Get UsbGINTMSKEnumDoneMsk from register */
#define  USB_GINTMSK_ISOOUT_DROP_MSK_SHIFT                  14                            /**< Shift for UsbGINTMSKISOOutDropMsk */
#define  USB_GINTMSK_ISOOUT_DROP_MSK_MASK                   0x00004000u                   /**< Mask for UsbGINTMSKISOOutDropMsk */
#define  USB_GINTMSK_ISOOUT_DROP_MSK_BMASK                  0x1u                          /**< Base mask for UsbGINTMSKISOOutDropMsk */
#define  USB_GINTMSK_ISOOUT_DROP_MSK(x)                     (((x)&0x1u)<<14)              /**< Set UsbGINTMSKISOOutDropMsk in register */
#define  GET_USB_GINTMSK_ISOOUT_DROP_MSK(reg)               (((reg)>>14)&0x1u)            /**< Get UsbGINTMSKISOOutDropMsk from register */
#define  USB_GINTMSK_EOPFMSK_SHIFT                          15                            /**< Shift for UsbGINTMSKEOPFMsk */
#define  USB_GINTMSK_EOPFMSK_MASK                           0x00008000u                   /**< Mask for UsbGINTMSKEOPFMsk */
#define  USB_GINTMSK_EOPFMSK_BMASK                          0x1u                          /**< Base mask for UsbGINTMSKEOPFMsk */
#define  USB_GINTMSK_EOPFMSK(x)                             (((x)&0x1u)<<15)              /**< Set UsbGINTMSKEOPFMsk in register */
#define  GET_USB_GINTMSK_EOPFMSK(reg)                       (((reg)>>15)&0x1u)            /**< Get UsbGINTMSKEOPFMsk from register */
#define  USB_GINTMSK_EPMIS_MSK_SHIFT                        17                            /**< Shift for UsbGINTMSKEPMisMsk */
#define  USB_GINTMSK_EPMIS_MSK_MASK                         0x00020000u                   /**< Mask for UsbGINTMSKEPMisMsk */
#define  USB_GINTMSK_EPMIS_MSK_BMASK                        0x1u                          /**< Base mask for UsbGINTMSKEPMisMsk */
#define  USB_GINTMSK_EPMIS_MSK(x)                           (((x)&0x1u)<<17)              /**< Set UsbGINTMSKEPMisMsk in register */
#define  GET_USB_GINTMSK_EPMIS_MSK(reg)                     (((reg)>>17)&0x1u)            /**< Get UsbGINTMSKEPMisMsk from register */
#define  USB_GINTMSK_IEPINT_MSK_SHIFT                       18                            /**< Shift for UsbGINTMSKIEPIntMsk */
#define  USB_GINTMSK_IEPINT_MSK_MASK                        0x00040000u                   /**< Mask for UsbGINTMSKIEPIntMsk */
#define  USB_GINTMSK_IEPINT_MSK_BMASK                       0x1u                          /**< Base mask for UsbGINTMSKIEPIntMsk */
#define  USB_GINTMSK_IEPINT_MSK(x)                          (((x)&0x1u)<<18)              /**< Set UsbGINTMSKIEPIntMsk in register */
#define  GET_USB_GINTMSK_IEPINT_MSK(reg)                    (((reg)>>18)&0x1u)            /**< Get UsbGINTMSKIEPIntMsk from register */
#define  USB_GINTMSK_OEPINT_MSK_SHIFT                       19                            /**< Shift for UsbGINTMSKOEPIntMsk */
#define  USB_GINTMSK_OEPINT_MSK_MASK                        0x00080000u                   /**< Mask for UsbGINTMSKOEPIntMsk */
#define  USB_GINTMSK_OEPINT_MSK_BMASK                       0x1u                          /**< Base mask for UsbGINTMSKOEPIntMsk */
#define  USB_GINTMSK_OEPINT_MSK(x)                          (((x)&0x1u)<<19)              /**< Set UsbGINTMSKOEPIntMsk in register */
#define  GET_USB_GINTMSK_OEPINT_MSK(reg)                    (((reg)>>19)&0x1u)            /**< Get UsbGINTMSKOEPIntMsk from register */
#define  USB_GINTMSK_INCOMPL_ISOOUTMSK_SHIFT                21                            /**< Shift for UsbGINTMSKincomplISOOUTMsk */
#define  USB_GINTMSK_INCOMPL_ISOOUTMSK_MASK                 0x00200000u                   /**< Mask for UsbGINTMSKincomplISOOUTMsk */
#define  USB_GINTMSK_INCOMPL_ISOOUTMSK_BMASK                0x1u                          /**< Base mask for UsbGINTMSKincomplISOOUTMsk */
#define  USB_GINTMSK_INCOMPL_ISOOUTMSK(x)                   (((x)&0x1u)<<21)              /**< Set UsbGINTMSKincomplISOOUTMsk in register */
#define  GET_USB_GINTMSK_INCOMPL_ISOOUTMSK(reg)             (((reg)>>21)&0x1u)            /**< Get UsbGINTMSKincomplISOOUTMsk from register */
#define  USB_GINTMSK_FET_SUSP_MSK_SHIFT                     22                            /**< Shift for UsbGINTMSKFetSuspMsk */
#define  USB_GINTMSK_FET_SUSP_MSK_MASK                      0x00400000u                   /**< Mask for UsbGINTMSKFetSuspMsk */
#define  USB_GINTMSK_FET_SUSP_MSK_BMASK                     0x1u                          /**< Base mask for UsbGINTMSKFetSuspMsk */
#define  USB_GINTMSK_FET_SUSP_MSK(x)                        (((x)&0x1u)<<22)              /**< Set UsbGINTMSKFetSuspMsk in register */
#define  GET_USB_GINTMSK_FET_SUSP_MSK(reg)                  (((reg)>>22)&0x1u)            /**< Get UsbGINTMSKFetSuspMsk from register */
#define  USB_GINTMSK_RESET_DET_MSK_SHIFT                    23                            /**< Shift for UsbGINTMSKResetDetMsk */
#define  USB_GINTMSK_RESET_DET_MSK_MASK                     0x00800000u                   /**< Mask for UsbGINTMSKResetDetMsk */
#define  USB_GINTMSK_RESET_DET_MSK_BMASK                    0x1u                          /**< Base mask for UsbGINTMSKResetDetMsk */
#define  USB_GINTMSK_RESET_DET_MSK(x)                       (((x)&0x1u)<<23)              /**< Set UsbGINTMSKResetDetMsk in register */
#define  GET_USB_GINTMSK_RESET_DET_MSK(reg)                 (((reg)>>23)&0x1u)            /**< Get UsbGINTMSKResetDetMsk from register */
#define  USB_GINTMSK_CON_IDSTS_CHNG_MSK_SHIFT               28                            /**< Shift for UsbGINTMSKConIDStsChngMsk */
#define  USB_GINTMSK_CON_IDSTS_CHNG_MSK_MASK                0x10000000u                   /**< Mask for UsbGINTMSKConIDStsChngMsk */
#define  USB_GINTMSK_CON_IDSTS_CHNG_MSK_BMASK               0x1u                          /**< Base mask for UsbGINTMSKConIDStsChngMsk */
#define  USB_GINTMSK_CON_IDSTS_CHNG_MSK(x)                  (((x)&0x1u)<<28)              /**< Set UsbGINTMSKConIDStsChngMsk in register */
#define  GET_USB_GINTMSK_CON_IDSTS_CHNG_MSK(reg)            (((reg)>>28)&0x1u)            /**< Get UsbGINTMSKConIDStsChngMsk from register */
#define  USB_GINTMSK_DISCONN_INT_MSK_SHIFT                  29                            /**< Shift for UsbGINTMSKDisconnIntMsk */
#define  USB_GINTMSK_DISCONN_INT_MSK_MASK                   0x20000000u                   /**< Mask for UsbGINTMSKDisconnIntMsk */
#define  USB_GINTMSK_DISCONN_INT_MSK_BMASK                  0x1u                          /**< Base mask for UsbGINTMSKDisconnIntMsk */
#define  USB_GINTMSK_DISCONN_INT_MSK(x)                     (((x)&0x1u)<<29)              /**< Set UsbGINTMSKDisconnIntMsk in register */
#define  GET_USB_GINTMSK_DISCONN_INT_MSK(reg)               (((reg)>>29)&0x1u)            /**< Get UsbGINTMSKDisconnIntMsk from register */
#define  USB_GINTMSK_SESS_REQ_INT_MSK_SHIFT                 30                            /**< Shift for UsbGINTMSKSessReqIntMsk */
#define  USB_GINTMSK_SESS_REQ_INT_MSK_MASK                  0x40000000u                   /**< Mask for UsbGINTMSKSessReqIntMsk */
#define  USB_GINTMSK_SESS_REQ_INT_MSK_BMASK                 0x1u                          /**< Base mask for UsbGINTMSKSessReqIntMsk */
#define  USB_GINTMSK_SESS_REQ_INT_MSK(x)                    (((x)&0x1u)<<30)              /**< Set UsbGINTMSKSessReqIntMsk in register */
#define  GET_USB_GINTMSK_SESS_REQ_INT_MSK(reg)              (((reg)>>30)&0x1u)            /**< Get UsbGINTMSKSessReqIntMsk from register */
#define  USB_GINTMSK_WK_UP_INT_MSK_SHIFT                    31                            /**< Shift for UsbGINTMSKWkUpIntMsk */
#define  USB_GINTMSK_WK_UP_INT_MSK_MASK                     0x80000000u                   /**< Mask for UsbGINTMSKWkUpIntMsk */
#define  USB_GINTMSK_WK_UP_INT_MSK_BMASK                    0x1u                          /**< Base mask for UsbGINTMSKWkUpIntMsk */
#define  USB_GINTMSK_WK_UP_INT_MSK(x)                       (((x)&0x1u)<<31)              /**< Set UsbGINTMSKWkUpIntMsk in register */
#define  GET_USB_GINTMSK_WK_UP_INT_MSK(reg)                 (((reg)>>31)&0x1u)            /**< Get UsbGINTMSKWkUpIntMsk from register */
/** @} */


/**
 * @name RegUsbGRXSTSR
 * @{
 */
// RegUsbGRXSTSR.r32
#define  REG_USB_GRXSTSR_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGRXSTSR */
#define  REG_USB_GRXSTSR_MASK                               0x01FFFFFFu                   /**< Mask for RegUsbGRXSTSR */

#define  USB_GRXSTSR_CH_NUM_SHIFT                           0                             /**< Shift for UsbGRXSTSRChNum */
#define  USB_GRXSTSR_CH_NUM_MASK                            0x0000000Fu                   /**< Mask for UsbGRXSTSRChNum */
#define  USB_GRXSTSR_CH_NUM_BMASK                           0xFu                          /**< Base mask for UsbGRXSTSRChNum */
#define  USB_GRXSTSR_CH_NUM(x)                              (((x)&0xFu)<<0)               /**< Set UsbGRXSTSRChNum in register */
#define  GET_USB_GRXSTSR_CH_NUM(reg)                        (((reg)>>0)&0xFu)             /**< Get UsbGRXSTSRChNum from register */
#define  USB_GRXSTSR_BCNT_SHIFT                             4                             /**< Shift for UsbGRXSTSRBCnt */
#define  USB_GRXSTSR_BCNT_MASK                              0x00007FF0u                   /**< Mask for UsbGRXSTSRBCnt */
#define  USB_GRXSTSR_BCNT_BMASK                             0x7FFu                        /**< Base mask for UsbGRXSTSRBCnt */
#define  USB_GRXSTSR_BCNT(x)                                (((x)&0x7FFu)<<4)             /**< Set UsbGRXSTSRBCnt in register */
#define  GET_USB_GRXSTSR_BCNT(reg)                          (((reg)>>4)&0x7FFu)           /**< Get UsbGRXSTSRBCnt from register */
#define  USB_GRXSTSR_DPID_SHIFT                             15                            /**< Shift for UsbGRXSTSRDPID */
#define  USB_GRXSTSR_DPID_MASK                              0x00018000u                   /**< Mask for UsbGRXSTSRDPID */
#define  USB_GRXSTSR_DPID_BMASK                             0x3u                          /**< Base mask for UsbGRXSTSRDPID */
#define  USB_GRXSTSR_DPID(x)                                (((x)&0x3u)<<15)              /**< Set UsbGRXSTSRDPID in register */
#define  GET_USB_GRXSTSR_DPID(reg)                          (((reg)>>15)&0x3u)            /**< Get UsbGRXSTSRDPID from register */
#define  USB_GRXSTSR_PKT_STS_SHIFT                          17                            /**< Shift for UsbGRXSTSRPktSts */
#define  USB_GRXSTSR_PKT_STS_MASK                           0x001E0000u                   /**< Mask for UsbGRXSTSRPktSts */
#define  USB_GRXSTSR_PKT_STS_BMASK                          0xFu                          /**< Base mask for UsbGRXSTSRPktSts */
#define  USB_GRXSTSR_PKT_STS(x)                             (((x)&0xFu)<<17)              /**< Set UsbGRXSTSRPktSts in register */
#define  GET_USB_GRXSTSR_PKT_STS(reg)                       (((reg)>>17)&0xFu)            /**< Get UsbGRXSTSRPktSts from register */
#define  USB_GRXSTSR_FN_SHIFT                               21                            /**< Shift for UsbGRXSTSRFN */
#define  USB_GRXSTSR_FN_MASK                                0x01E00000u                   /**< Mask for UsbGRXSTSRFN */
#define  USB_GRXSTSR_FN_BMASK                               0xFu                          /**< Base mask for UsbGRXSTSRFN */
#define  USB_GRXSTSR_FN(x)                                  (((x)&0xFu)<<21)              /**< Set UsbGRXSTSRFN in register */
#define  GET_USB_GRXSTSR_FN(reg)                            (((reg)>>21)&0xFu)            /**< Get UsbGRXSTSRFN from register */
/** @} */


/**
 * @name RegUsbGRXSTSP
 * @{
 */
// RegUsbGRXSTSP.r32
#define  REG_USB_GRXSTSP_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGRXSTSP */
#define  REG_USB_GRXSTSP_MASK                               0x01FFFFFFu                   /**< Mask for RegUsbGRXSTSP */

#define  USB_GRXSTSP_CH_NUM_SHIFT                           0                             /**< Shift for UsbGRXSTSPChNum */
#define  USB_GRXSTSP_CH_NUM_MASK                            0x0000000Fu                   /**< Mask for UsbGRXSTSPChNum */
#define  USB_GRXSTSP_CH_NUM_BMASK                           0xFu                          /**< Base mask for UsbGRXSTSPChNum */
#define  USB_GRXSTSP_CH_NUM(x)                              (((x)&0xFu)<<0)               /**< Set UsbGRXSTSPChNum in register */
#define  GET_USB_GRXSTSP_CH_NUM(reg)                        (((reg)>>0)&0xFu)             /**< Get UsbGRXSTSPChNum from register */
#define  USB_GRXSTSP_BCNT_SHIFT                             4                             /**< Shift for UsbGRXSTSPBCnt */
#define  USB_GRXSTSP_BCNT_MASK                              0x00007FF0u                   /**< Mask for UsbGRXSTSPBCnt */
#define  USB_GRXSTSP_BCNT_BMASK                             0x7FFu                        /**< Base mask for UsbGRXSTSPBCnt */
#define  USB_GRXSTSP_BCNT(x)                                (((x)&0x7FFu)<<4)             /**< Set UsbGRXSTSPBCnt in register */
#define  GET_USB_GRXSTSP_BCNT(reg)                          (((reg)>>4)&0x7FFu)           /**< Get UsbGRXSTSPBCnt from register */
#define  USB_GRXSTSP_DPID_SHIFT                             15                            /**< Shift for UsbGRXSTSPDPID */
#define  USB_GRXSTSP_DPID_MASK                              0x00018000u                   /**< Mask for UsbGRXSTSPDPID */
#define  USB_GRXSTSP_DPID_BMASK                             0x3u                          /**< Base mask for UsbGRXSTSPDPID */
#define  USB_GRXSTSP_DPID(x)                                (((x)&0x3u)<<15)              /**< Set UsbGRXSTSPDPID in register */
#define  GET_USB_GRXSTSP_DPID(reg)                          (((reg)>>15)&0x3u)            /**< Get UsbGRXSTSPDPID from register */
#define  USB_GRXSTSP_PKT_STS_SHIFT                          17                            /**< Shift for UsbGRXSTSPPktSts */
#define  USB_GRXSTSP_PKT_STS_MASK                           0x001E0000u                   /**< Mask for UsbGRXSTSPPktSts */
#define  USB_GRXSTSP_PKT_STS_BMASK                          0xFu                          /**< Base mask for UsbGRXSTSPPktSts */
#define  USB_GRXSTSP_PKT_STS(x)                             (((x)&0xFu)<<17)              /**< Set UsbGRXSTSPPktSts in register */
#define  GET_USB_GRXSTSP_PKT_STS(reg)                       (((reg)>>17)&0xFu)            /**< Get UsbGRXSTSPPktSts from register */
#define  USB_GRXSTSP_FN_SHIFT                               21                            /**< Shift for UsbGRXSTSPFN */
#define  USB_GRXSTSP_FN_MASK                                0x01E00000u                   /**< Mask for UsbGRXSTSPFN */
#define  USB_GRXSTSP_FN_BMASK                               0xFu                          /**< Base mask for UsbGRXSTSPFN */
#define  USB_GRXSTSP_FN(x)                                  (((x)&0xFu)<<21)              /**< Set UsbGRXSTSPFN in register */
#define  GET_USB_GRXSTSP_FN(reg)                            (((reg)>>21)&0xFu)            /**< Get UsbGRXSTSPFN from register */
/** @} */


/**
 * @name RegUsbGRXFSIZ
 * @{
 */
// RegUsbGRXFSIZ.r32
#define  REG_USB_GRXFSIZ_RESET_VALUE                        0x00000060u                   /**< Reset value of RegUsbGRXFSIZ */
#define  REG_USB_GRXFSIZ_MASK                               0x0000007Fu                   /**< Mask for RegUsbGRXFSIZ */

#define  USB_GRXFSIZ_RX_FDEP_SHIFT                          0                             /**< Shift for UsbGRXFSIZRxFDep */
#define  USB_GRXFSIZ_RX_FDEP_MASK                           0x0000007Fu                   /**< Mask for UsbGRXFSIZRxFDep */
#define  USB_GRXFSIZ_RX_FDEP_BMASK                          0x7Fu                         /**< Base mask for UsbGRXFSIZRxFDep */
#define  USB_GRXFSIZ_RX_FDEP(x)                             (((x)&0x7Fu)<<0)              /**< Set UsbGRXFSIZRxFDep in register */
#define  GET_USB_GRXFSIZ_RX_FDEP(reg)                       (((reg)>>0)&0x7Fu)            /**< Get UsbGRXFSIZRxFDep from register */
/** @} */


/**
 * @name RegUsbGNPTXFSIZ
 * @{
 */
// RegUsbGNPTXFSIZ.r32
#define  REG_USB_GNPTXFSIZ_RESET_VALUE                      0x00400060u                   /**< Reset value of RegUsbGNPTXFSIZ */
#define  REG_USB_GNPTXFSIZ_MASK                             0x007F007Fu                   /**< Mask for RegUsbGNPTXFSIZ */

#define  USB_GNPTXFSIZ_NPTX_FST_ADDR_SHIFT                  0                             /**< Shift for UsbGNPTXFSIZNPTxFStAddr */
#define  USB_GNPTXFSIZ_NPTX_FST_ADDR_MASK                   0x0000007Fu                   /**< Mask for UsbGNPTXFSIZNPTxFStAddr */
#define  USB_GNPTXFSIZ_NPTX_FST_ADDR_BMASK                  0x7Fu                         /**< Base mask for UsbGNPTXFSIZNPTxFStAddr */
#define  USB_GNPTXFSIZ_NPTX_FST_ADDR(x)                     (((x)&0x7Fu)<<0)              /**< Set UsbGNPTXFSIZNPTxFStAddr in register */
#define  GET_USB_GNPTXFSIZ_NPTX_FST_ADDR(reg)               (((reg)>>0)&0x7Fu)            /**< Get UsbGNPTXFSIZNPTxFStAddr from register */
#define  USB_GNPTXFSIZ_NPTX_FDEP_SHIFT                      16                            /**< Shift for UsbGNPTXFSIZNPTxFDep */
#define  USB_GNPTXFSIZ_NPTX_FDEP_MASK                       0x007F0000u                   /**< Mask for UsbGNPTXFSIZNPTxFDep */
#define  USB_GNPTXFSIZ_NPTX_FDEP_BMASK                      0x7Fu                         /**< Base mask for UsbGNPTXFSIZNPTxFDep */
#define  USB_GNPTXFSIZ_NPTX_FDEP(x)                         (((x)&0x7Fu)<<16)             /**< Set UsbGNPTXFSIZNPTxFDep in register */
#define  GET_USB_GNPTXFSIZ_NPTX_FDEP(reg)                   (((reg)>>16)&0x7Fu)           /**< Get UsbGNPTXFSIZNPTxFDep from register */
/** @} */


/**
 * @name RegUsbGNPTXSTS
 * @{
 */
// RegUsbGNPTXSTS.r32
#define  REG_USB_GNPTXSTS_RESET_VALUE                       0x00040040u                   /**< Reset value of RegUsbGNPTXSTS */
#define  REG_USB_GNPTXSTS_MASK                              0x7FFFFFFFu                   /**< Mask for RegUsbGNPTXSTS */

#define  USB_GNPTXSTS_NPTX_FSPC_AVAIL_SHIFT                 0                             /**< Shift for UsbGNPTXSTSNPTxFSpcAvail */
#define  USB_GNPTXSTS_NPTX_FSPC_AVAIL_MASK                  0x0000FFFFu                   /**< Mask for UsbGNPTXSTSNPTxFSpcAvail */
#define  USB_GNPTXSTS_NPTX_FSPC_AVAIL_BMASK                 0xFFFFu                       /**< Base mask for UsbGNPTXSTSNPTxFSpcAvail */
#define  USB_GNPTXSTS_NPTX_FSPC_AVAIL(x)                    (((x)&0xFFFFu)<<0)            /**< Set UsbGNPTXSTSNPTxFSpcAvail in register */
#define  GET_USB_GNPTXSTS_NPTX_FSPC_AVAIL(reg)              (((reg)>>0)&0xFFFFu)          /**< Get UsbGNPTXSTSNPTxFSpcAvail from register */
#define  USB_GNPTXSTS_NPTX_QSPC_AVAIL_SHIFT                 16                            /**< Shift for UsbGNPTXSTSNPTxQSpcAvail */
#define  USB_GNPTXSTS_NPTX_QSPC_AVAIL_MASK                  0x00FF0000u                   /**< Mask for UsbGNPTXSTSNPTxQSpcAvail */
#define  USB_GNPTXSTS_NPTX_QSPC_AVAIL_BMASK                 0xFFu                         /**< Base mask for UsbGNPTXSTSNPTxQSpcAvail */
#define  USB_GNPTXSTS_NPTX_QSPC_AVAIL(x)                    (((x)&0xFFu)<<16)             /**< Set UsbGNPTXSTSNPTxQSpcAvail in register */
#define  GET_USB_GNPTXSTS_NPTX_QSPC_AVAIL(reg)              (((reg)>>16)&0xFFu)           /**< Get UsbGNPTXSTSNPTxQSpcAvail from register */
#define  USB_GNPTXSTS_NPTX_QTOP_SHIFT                       24                            /**< Shift for UsbGNPTXSTSNPTxQTop */
#define  USB_GNPTXSTS_NPTX_QTOP_MASK                        0x7F000000u                   /**< Mask for UsbGNPTXSTSNPTxQTop */
#define  USB_GNPTXSTS_NPTX_QTOP_BMASK                       0x7Fu                         /**< Base mask for UsbGNPTXSTSNPTxQTop */
#define  USB_GNPTXSTS_NPTX_QTOP(x)                          (((x)&0x7Fu)<<24)             /**< Set UsbGNPTXSTSNPTxQTop in register */
#define  GET_USB_GNPTXSTS_NPTX_QTOP(reg)                    (((reg)>>24)&0x7Fu)           /**< Get UsbGNPTXSTSNPTxQTop from register */
/** @} */


/**
 * @name RegUsbGSNPSID
 * @{
 */
// RegUsbGSNPSID.r32
#define  REG_USB_GSNPSID_RESET_VALUE                        0x4F54400Au                   /**< Reset value of RegUsbGSNPSID */
#define  REG_USB_GSNPSID_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbGSNPSID */

#define  USB_GSNPSID_SYNOPSYS_ID_SHIFT                      0                             /**< Shift for UsbGSNPSIDSynopsysID */
#define  USB_GSNPSID_SYNOPSYS_ID_MASK                       0xFFFFFFFFu                   /**< Mask for UsbGSNPSIDSynopsysID */
#define  USB_GSNPSID_SYNOPSYS_ID_BMASK                      0xFFFFFFFFu                   /**< Base mask for UsbGSNPSIDSynopsysID */
#define  USB_GSNPSID_SYNOPSYS_ID(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbGSNPSIDSynopsysID in register */
#define  GET_USB_GSNPSID_SYNOPSYS_ID(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbGSNPSIDSynopsysID from register */
/** @} */


/**
 * @name RegUsbGHWCFG1
 * @{
 */
// RegUsbGHWCFG1.r32
#define  REG_USB_GHWCFG1_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbGHWCFG1 */
#define  REG_USB_GHWCFG1_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbGHWCFG1 */

#define  USB_GHWCFG1_EP_DIR_SHIFT                           0                             /**< Shift for UsbGHWCFG1EpDir */
#define  USB_GHWCFG1_EP_DIR_MASK                            0xFFFFFFFFu                   /**< Mask for UsbGHWCFG1EpDir */
#define  USB_GHWCFG1_EP_DIR_BMASK                           0xFFFFFFFFu                   /**< Base mask for UsbGHWCFG1EpDir */
#define  USB_GHWCFG1_EP_DIR(x)                              (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbGHWCFG1EpDir in register */
#define  GET_USB_GHWCFG1_EP_DIR(reg)                        (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbGHWCFG1EpDir from register */
/** @} */


/**
 * @name RegUsbGHWCFG2
 * @{
 */
// RegUsbGHWCFG2.r32
#define  REG_USB_GHWCFG2_RESET_VALUE                        0x1258CD0Cu                   /**< Reset value of RegUsbGHWCFG2 */
#define  REG_USB_GHWCFG2_MASK                               0x7FDFFFFFu                   /**< Mask for RegUsbGHWCFG2 */

#define  USB_GHWCFG2_OTG_MODE_SHIFT                         0                             /**< Shift for UsbGHWCFG2OtgMode */
#define  USB_GHWCFG2_OTG_MODE_MASK                          0x00000007u                   /**< Mask for UsbGHWCFG2OtgMode */
#define  USB_GHWCFG2_OTG_MODE_BMASK                         0x7u                          /**< Base mask for UsbGHWCFG2OtgMode */
#define  USB_GHWCFG2_OTG_MODE(x)                            (((x)&0x7u)<<0)               /**< Set UsbGHWCFG2OtgMode in register */
#define  GET_USB_GHWCFG2_OTG_MODE(reg)                      (((reg)>>0)&0x7u)             /**< Get UsbGHWCFG2OtgMode from register */
#define  USB_GHWCFG2_OTG_ARCH_SHIFT                         3                             /**< Shift for UsbGHWCFG2OtgArch */
#define  USB_GHWCFG2_OTG_ARCH_MASK                          0x00000018u                   /**< Mask for UsbGHWCFG2OtgArch */
#define  USB_GHWCFG2_OTG_ARCH_BMASK                         0x3u                          /**< Base mask for UsbGHWCFG2OtgArch */
#define  USB_GHWCFG2_OTG_ARCH(x)                            (((x)&0x3u)<<3)               /**< Set UsbGHWCFG2OtgArch in register */
#define  GET_USB_GHWCFG2_OTG_ARCH(reg)                      (((reg)>>3)&0x3u)             /**< Get UsbGHWCFG2OtgArch from register */
#define  USB_GHWCFG2_SING_PNT_SHIFT                         5                             /**< Shift for UsbGHWCFG2SingPnt */
#define  USB_GHWCFG2_SING_PNT_MASK                          0x00000020u                   /**< Mask for UsbGHWCFG2SingPnt */
#define  USB_GHWCFG2_SING_PNT_BMASK                         0x1u                          /**< Base mask for UsbGHWCFG2SingPnt */
#define  USB_GHWCFG2_SING_PNT(x)                            (((x)&0x1u)<<5)               /**< Set UsbGHWCFG2SingPnt in register */
#define  GET_USB_GHWCFG2_SING_PNT(reg)                      (((reg)>>5)&0x1u)             /**< Get UsbGHWCFG2SingPnt from register */
#define  USB_GHWCFG2_HSPHY_TYPE_SHIFT                       6                             /**< Shift for UsbGHWCFG2HSPhyType */
#define  USB_GHWCFG2_HSPHY_TYPE_MASK                        0x000000C0u                   /**< Mask for UsbGHWCFG2HSPhyType */
#define  USB_GHWCFG2_HSPHY_TYPE_BMASK                       0x3u                          /**< Base mask for UsbGHWCFG2HSPhyType */
#define  USB_GHWCFG2_HSPHY_TYPE(x)                          (((x)&0x3u)<<6)               /**< Set UsbGHWCFG2HSPhyType in register */
#define  GET_USB_GHWCFG2_HSPHY_TYPE(reg)                    (((reg)>>6)&0x3u)             /**< Get UsbGHWCFG2HSPhyType from register */
#define  USB_GHWCFG2_FSPHY_TYPE_SHIFT                       8                             /**< Shift for UsbGHWCFG2FSPhyType */
#define  USB_GHWCFG2_FSPHY_TYPE_MASK                        0x00000300u                   /**< Mask for UsbGHWCFG2FSPhyType */
#define  USB_GHWCFG2_FSPHY_TYPE_BMASK                       0x3u                          /**< Base mask for UsbGHWCFG2FSPhyType */
#define  USB_GHWCFG2_FSPHY_TYPE(x)                          (((x)&0x3u)<<8)               /**< Set UsbGHWCFG2FSPhyType in register */
#define  GET_USB_GHWCFG2_FSPHY_TYPE(reg)                    (((reg)>>8)&0x3u)             /**< Get UsbGHWCFG2FSPhyType from register */
#define  USB_GHWCFG2_NUM_DEV_EPS_SHIFT                      10                            /**< Shift for UsbGHWCFG2NumDevEps */
#define  USB_GHWCFG2_NUM_DEV_EPS_MASK                       0x00003C00u                   /**< Mask for UsbGHWCFG2NumDevEps */
#define  USB_GHWCFG2_NUM_DEV_EPS_BMASK                      0xFu                          /**< Base mask for UsbGHWCFG2NumDevEps */
#define  USB_GHWCFG2_NUM_DEV_EPS(x)                         (((x)&0xFu)<<10)              /**< Set UsbGHWCFG2NumDevEps in register */
#define  GET_USB_GHWCFG2_NUM_DEV_EPS(reg)                   (((reg)>>10)&0xFu)            /**< Get UsbGHWCFG2NumDevEps from register */
#define  USB_GHWCFG2_NUM_HST_CHNL_SHIFT                     14                            /**< Shift for UsbGHWCFG2NumHstChnl */
#define  USB_GHWCFG2_NUM_HST_CHNL_MASK                      0x0003C000u                   /**< Mask for UsbGHWCFG2NumHstChnl */
#define  USB_GHWCFG2_NUM_HST_CHNL_BMASK                     0xFu                          /**< Base mask for UsbGHWCFG2NumHstChnl */
#define  USB_GHWCFG2_NUM_HST_CHNL(x)                        (((x)&0xFu)<<14)              /**< Set UsbGHWCFG2NumHstChnl in register */
#define  GET_USB_GHWCFG2_NUM_HST_CHNL(reg)                  (((reg)>>14)&0xFu)            /**< Get UsbGHWCFG2NumHstChnl from register */
#define  USB_GHWCFG2_PERIO_SUPPORT_SHIFT                    18                            /**< Shift for UsbGHWCFG2PerioSupport */
#define  USB_GHWCFG2_PERIO_SUPPORT_MASK                     0x00040000u                   /**< Mask for UsbGHWCFG2PerioSupport */
#define  USB_GHWCFG2_PERIO_SUPPORT_BMASK                    0x1u                          /**< Base mask for UsbGHWCFG2PerioSupport */
#define  USB_GHWCFG2_PERIO_SUPPORT(x)                       (((x)&0x1u)<<18)              /**< Set UsbGHWCFG2PerioSupport in register */
#define  GET_USB_GHWCFG2_PERIO_SUPPORT(reg)                 (((reg)>>18)&0x1u)            /**< Get UsbGHWCFG2PerioSupport from register */
#define  USB_GHWCFG2_DYN_FIFO_SIZING_SHIFT                  19                            /**< Shift for UsbGHWCFG2DynFifoSizing */
#define  USB_GHWCFG2_DYN_FIFO_SIZING_MASK                   0x00080000u                   /**< Mask for UsbGHWCFG2DynFifoSizing */
#define  USB_GHWCFG2_DYN_FIFO_SIZING_BMASK                  0x1u                          /**< Base mask for UsbGHWCFG2DynFifoSizing */
#define  USB_GHWCFG2_DYN_FIFO_SIZING(x)                     (((x)&0x1u)<<19)              /**< Set UsbGHWCFG2DynFifoSizing in register */
#define  GET_USB_GHWCFG2_DYN_FIFO_SIZING(reg)               (((reg)>>19)&0x1u)            /**< Get UsbGHWCFG2DynFifoSizing from register */
#define  USB_GHWCFG2_MULTI_PROC_INTRPT_SHIFT                20                            /**< Shift for UsbGHWCFG2MultiProcIntrpt */
#define  USB_GHWCFG2_MULTI_PROC_INTRPT_MASK                 0x00100000u                   /**< Mask for UsbGHWCFG2MultiProcIntrpt */
#define  USB_GHWCFG2_MULTI_PROC_INTRPT_BMASK                0x1u                          /**< Base mask for UsbGHWCFG2MultiProcIntrpt */
#define  USB_GHWCFG2_MULTI_PROC_INTRPT(x)                   (((x)&0x1u)<<20)              /**< Set UsbGHWCFG2MultiProcIntrpt in register */
#define  GET_USB_GHWCFG2_MULTI_PROC_INTRPT(reg)             (((reg)>>20)&0x1u)            /**< Get UsbGHWCFG2MultiProcIntrpt from register */
#define  USB_GHWCFG2_NPTX_QDEPTH_SHIFT                      22                            /**< Shift for UsbGHWCFG2NPTxQDepth */
#define  USB_GHWCFG2_NPTX_QDEPTH_MASK                       0x00C00000u                   /**< Mask for UsbGHWCFG2NPTxQDepth */
#define  USB_GHWCFG2_NPTX_QDEPTH_BMASK                      0x3u                          /**< Base mask for UsbGHWCFG2NPTxQDepth */
#define  USB_GHWCFG2_NPTX_QDEPTH(x)                         (((x)&0x3u)<<22)              /**< Set UsbGHWCFG2NPTxQDepth in register */
#define  GET_USB_GHWCFG2_NPTX_QDEPTH(reg)                   (((reg)>>22)&0x3u)            /**< Get UsbGHWCFG2NPTxQDepth from register */
#define  USB_GHWCFG2_PTX_QDEPTH_SHIFT                       24                            /**< Shift for UsbGHWCFG2PTxQDepth */
#define  USB_GHWCFG2_PTX_QDEPTH_MASK                        0x03000000u                   /**< Mask for UsbGHWCFG2PTxQDepth */
#define  USB_GHWCFG2_PTX_QDEPTH_BMASK                       0x3u                          /**< Base mask for UsbGHWCFG2PTxQDepth */
#define  USB_GHWCFG2_PTX_QDEPTH(x)                          (((x)&0x3u)<<24)              /**< Set UsbGHWCFG2PTxQDepth in register */
#define  GET_USB_GHWCFG2_PTX_QDEPTH(reg)                    (((reg)>>24)&0x3u)            /**< Get UsbGHWCFG2PTxQDepth from register */
#define  USB_GHWCFG2_TKN_QDEPTH_SHIFT                       26                            /**< Shift for UsbGHWCFG2TknQDepth */
#define  USB_GHWCFG2_TKN_QDEPTH_MASK                        0x7C000000u                   /**< Mask for UsbGHWCFG2TknQDepth */
#define  USB_GHWCFG2_TKN_QDEPTH_BMASK                       0x1Fu                         /**< Base mask for UsbGHWCFG2TknQDepth */
#define  USB_GHWCFG2_TKN_QDEPTH(x)                          (((x)&0x1Fu)<<26)             /**< Set UsbGHWCFG2TknQDepth in register */
#define  GET_USB_GHWCFG2_TKN_QDEPTH(reg)                    (((reg)>>26)&0x1Fu)           /**< Get UsbGHWCFG2TknQDepth from register */
/** @} */


/**
 * @name RegUsbGHWCFG3
 * @{
 */
// RegUsbGHWCFG3.r32
#define  REG_USB_GHWCFG3_RESET_VALUE                        0x01000400u                   /**< Reset value of RegUsbGHWCFG3 */
#define  REG_USB_GHWCFG3_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbGHWCFG3 */

#define  USB_GHWCFG3_XFER_SIZE_WIDTH_SHIFT                  0                             /**< Shift for UsbGHWCFG3XferSizeWidth */
#define  USB_GHWCFG3_XFER_SIZE_WIDTH_MASK                   0x0000000Fu                   /**< Mask for UsbGHWCFG3XferSizeWidth */
#define  USB_GHWCFG3_XFER_SIZE_WIDTH_BMASK                  0xFu                          /**< Base mask for UsbGHWCFG3XferSizeWidth */
#define  USB_GHWCFG3_XFER_SIZE_WIDTH(x)                     (((x)&0xFu)<<0)               /**< Set UsbGHWCFG3XferSizeWidth in register */
#define  GET_USB_GHWCFG3_XFER_SIZE_WIDTH(reg)               (((reg)>>0)&0xFu)             /**< Get UsbGHWCFG3XferSizeWidth from register */
#define  USB_GHWCFG3_PKT_SIZE_WIDTH_SHIFT                   4                             /**< Shift for UsbGHWCFG3PktSizeWidth */
#define  USB_GHWCFG3_PKT_SIZE_WIDTH_MASK                    0x00000070u                   /**< Mask for UsbGHWCFG3PktSizeWidth */
#define  USB_GHWCFG3_PKT_SIZE_WIDTH_BMASK                   0x7u                          /**< Base mask for UsbGHWCFG3PktSizeWidth */
#define  USB_GHWCFG3_PKT_SIZE_WIDTH(x)                      (((x)&0x7u)<<4)               /**< Set UsbGHWCFG3PktSizeWidth in register */
#define  GET_USB_GHWCFG3_PKT_SIZE_WIDTH(reg)                (((reg)>>4)&0x7u)             /**< Get UsbGHWCFG3PktSizeWidth from register */
#define  USB_GHWCFG3_OTG_EN_SHIFT                           7                             /**< Shift for UsbGHWCFG3OtgEn */
#define  USB_GHWCFG3_OTG_EN_MASK                            0x00000080u                   /**< Mask for UsbGHWCFG3OtgEn */
#define  USB_GHWCFG3_OTG_EN_BMASK                           0x1u                          /**< Base mask for UsbGHWCFG3OtgEn */
#define  USB_GHWCFG3_OTG_EN(x)                              (((x)&0x1u)<<7)               /**< Set UsbGHWCFG3OtgEn in register */
#define  GET_USB_GHWCFG3_OTG_EN(reg)                        (((reg)>>7)&0x1u)             /**< Get UsbGHWCFG3OtgEn from register */
#define  USB_GHWCFG3_I2CINT_SEL_SHIFT                       8                             /**< Shift for UsbGHWCFG3I2CIntSel */
#define  USB_GHWCFG3_I2CINT_SEL_MASK                        0x00000100u                   /**< Mask for UsbGHWCFG3I2CIntSel */
#define  USB_GHWCFG3_I2CINT_SEL_BMASK                       0x1u                          /**< Base mask for UsbGHWCFG3I2CIntSel */
#define  USB_GHWCFG3_I2CINT_SEL(x)                          (((x)&0x1u)<<8)               /**< Set UsbGHWCFG3I2CIntSel in register */
#define  GET_USB_GHWCFG3_I2CINT_SEL(reg)                    (((reg)>>8)&0x1u)             /**< Get UsbGHWCFG3I2CIntSel from register */
#define  USB_GHWCFG3_VNDCTL_SUPT_SHIFT                      9                             /**< Shift for UsbGHWCFG3VndctlSupt */
#define  USB_GHWCFG3_VNDCTL_SUPT_MASK                       0x00000200u                   /**< Mask for UsbGHWCFG3VndctlSupt */
#define  USB_GHWCFG3_VNDCTL_SUPT_BMASK                      0x1u                          /**< Base mask for UsbGHWCFG3VndctlSupt */
#define  USB_GHWCFG3_VNDCTL_SUPT(x)                         (((x)&0x1u)<<9)               /**< Set UsbGHWCFG3VndctlSupt in register */
#define  GET_USB_GHWCFG3_VNDCTL_SUPT(reg)                   (((reg)>>9)&0x1u)             /**< Get UsbGHWCFG3VndctlSupt from register */
#define  USB_GHWCFG3_OPT_FEATURE_SHIFT                      10                            /**< Shift for UsbGHWCFG3OptFeature */
#define  USB_GHWCFG3_OPT_FEATURE_MASK                       0x00000400u                   /**< Mask for UsbGHWCFG3OptFeature */
#define  USB_GHWCFG3_OPT_FEATURE_BMASK                      0x1u                          /**< Base mask for UsbGHWCFG3OptFeature */
#define  USB_GHWCFG3_OPT_FEATURE(x)                         (((x)&0x1u)<<10)              /**< Set UsbGHWCFG3OptFeature in register */
#define  GET_USB_GHWCFG3_OPT_FEATURE(reg)                   (((reg)>>10)&0x1u)            /**< Get UsbGHWCFG3OptFeature from register */
#define  USB_GHWCFG3_RST_TYPE_SHIFT                         11                            /**< Shift for UsbGHWCFG3RstType */
#define  USB_GHWCFG3_RST_TYPE_MASK                          0x00000800u                   /**< Mask for UsbGHWCFG3RstType */
#define  USB_GHWCFG3_RST_TYPE_BMASK                         0x1u                          /**< Base mask for UsbGHWCFG3RstType */
#define  USB_GHWCFG3_RST_TYPE(x)                            (((x)&0x1u)<<11)              /**< Set UsbGHWCFG3RstType in register */
#define  GET_USB_GHWCFG3_RST_TYPE(reg)                      (((reg)>>11)&0x1u)            /**< Get UsbGHWCFG3RstType from register */
#define  USB_GHWCFG3_ADPSUPPORT_SHIFT                       12                            /**< Shift for UsbGHWCFG3ADPSupport */
#define  USB_GHWCFG3_ADPSUPPORT_MASK                        0x00001000u                   /**< Mask for UsbGHWCFG3ADPSupport */
#define  USB_GHWCFG3_ADPSUPPORT_BMASK                       0x1u                          /**< Base mask for UsbGHWCFG3ADPSupport */
#define  USB_GHWCFG3_ADPSUPPORT(x)                          (((x)&0x1u)<<12)              /**< Set UsbGHWCFG3ADPSupport in register */
#define  GET_USB_GHWCFG3_ADPSUPPORT(reg)                    (((reg)>>12)&0x1u)            /**< Get UsbGHWCFG3ADPSupport from register */
#define  USB_GHWCFG3_HSICMODE_SHIFT                         13                            /**< Shift for UsbGHWCFG3HSICMode */
#define  USB_GHWCFG3_HSICMODE_MASK                          0x00002000u                   /**< Mask for UsbGHWCFG3HSICMode */
#define  USB_GHWCFG3_HSICMODE_BMASK                         0x1u                          /**< Base mask for UsbGHWCFG3HSICMode */
#define  USB_GHWCFG3_HSICMODE(x)                            (((x)&0x1u)<<13)              /**< Set UsbGHWCFG3HSICMode in register */
#define  GET_USB_GHWCFG3_HSICMODE(reg)                      (((reg)>>13)&0x1u)            /**< Get UsbGHWCFG3HSICMode from register */
#define  USB_GHWCFG3_BCSUPPORT_SHIFT                        14                            /**< Shift for UsbGHWCFG3BCSupport */
#define  USB_GHWCFG3_BCSUPPORT_MASK                         0x00004000u                   /**< Mask for UsbGHWCFG3BCSupport */
#define  USB_GHWCFG3_BCSUPPORT_BMASK                        0x1u                          /**< Base mask for UsbGHWCFG3BCSupport */
#define  USB_GHWCFG3_BCSUPPORT(x)                           (((x)&0x1u)<<14)              /**< Set UsbGHWCFG3BCSupport in register */
#define  GET_USB_GHWCFG3_BCSUPPORT(reg)                     (((reg)>>14)&0x1u)            /**< Get UsbGHWCFG3BCSupport from register */
#define  USB_GHWCFG3_LPMMODE_SHIFT                          15                            /**< Shift for UsbGHWCFG3LPMMode */
#define  USB_GHWCFG3_LPMMODE_MASK                           0x00008000u                   /**< Mask for UsbGHWCFG3LPMMode */
#define  USB_GHWCFG3_LPMMODE_BMASK                          0x1u                          /**< Base mask for UsbGHWCFG3LPMMode */
#define  USB_GHWCFG3_LPMMODE(x)                             (((x)&0x1u)<<15)              /**< Set UsbGHWCFG3LPMMode in register */
#define  GET_USB_GHWCFG3_LPMMODE(reg)                       (((reg)>>15)&0x1u)            /**< Get UsbGHWCFG3LPMMode from register */
#define  USB_GHWCFG3_DFIFO_DEPTH_SHIFT                      16                            /**< Shift for UsbGHWCFG3DfifoDepth */
#define  USB_GHWCFG3_DFIFO_DEPTH_MASK                       0xFFFF0000u                   /**< Mask for UsbGHWCFG3DfifoDepth */
#define  USB_GHWCFG3_DFIFO_DEPTH_BMASK                      0xFFFFu                       /**< Base mask for UsbGHWCFG3DfifoDepth */
#define  USB_GHWCFG3_DFIFO_DEPTH(x)                         (((x)&0xFFFFu)<<16)           /**< Set UsbGHWCFG3DfifoDepth in register */
#define  GET_USB_GHWCFG3_DFIFO_DEPTH(reg)                   (((reg)>>16)&0xFFFFu)         /**< Get UsbGHWCFG3DfifoDepth from register */
/** @} */


/**
 * @name RegUsbGHWCFG4
 * @{
 */
// RegUsbGHWCFG4.r32
#define  REG_USB_GHWCFG4_RESET_VALUE                        0x0800A223u                   /**< Reset value of RegUsbGHWCFG4 */
#define  REG_USB_GHWCFG4_MASK                               0xFFFFFEFFu                   /**< Mask for RegUsbGHWCFG4 */

#define  USB_GHWCFG4_NUM_DEV_PERIO_EPS_SHIFT                0                             /**< Shift for UsbGHWCFG4NumDevPerioEps */
#define  USB_GHWCFG4_NUM_DEV_PERIO_EPS_MASK                 0x0000000Fu                   /**< Mask for UsbGHWCFG4NumDevPerioEps */
#define  USB_GHWCFG4_NUM_DEV_PERIO_EPS_BMASK                0xFu                          /**< Base mask for UsbGHWCFG4NumDevPerioEps */
#define  USB_GHWCFG4_NUM_DEV_PERIO_EPS(x)                   (((x)&0xFu)<<0)               /**< Set UsbGHWCFG4NumDevPerioEps in register */
#define  GET_USB_GHWCFG4_NUM_DEV_PERIO_EPS(reg)             (((reg)>>0)&0xFu)             /**< Get UsbGHWCFG4NumDevPerioEps from register */
#define  USB_GHWCFG4_PARTIAL_PWR_DN_SHIFT                   4                             /**< Shift for UsbGHWCFG4PartialPwrDn */
#define  USB_GHWCFG4_PARTIAL_PWR_DN_MASK                    0x00000010u                   /**< Mask for UsbGHWCFG4PartialPwrDn */
#define  USB_GHWCFG4_PARTIAL_PWR_DN_BMASK                   0x1u                          /**< Base mask for UsbGHWCFG4PartialPwrDn */
#define  USB_GHWCFG4_PARTIAL_PWR_DN(x)                      (((x)&0x1u)<<4)               /**< Set UsbGHWCFG4PartialPwrDn in register */
#define  GET_USB_GHWCFG4_PARTIAL_PWR_DN(reg)                (((reg)>>4)&0x1u)             /**< Get UsbGHWCFG4PartialPwrDn from register */
#define  USB_GHWCFG4_AHB_FREQ_SHIFT                         5                             /**< Shift for UsbGHWCFG4AhbFreq */
#define  USB_GHWCFG4_AHB_FREQ_MASK                          0x00000020u                   /**< Mask for UsbGHWCFG4AhbFreq */
#define  USB_GHWCFG4_AHB_FREQ_BMASK                         0x1u                          /**< Base mask for UsbGHWCFG4AhbFreq */
#define  USB_GHWCFG4_AHB_FREQ(x)                            (((x)&0x1u)<<5)               /**< Set UsbGHWCFG4AhbFreq in register */
#define  GET_USB_GHWCFG4_AHB_FREQ(reg)                      (((reg)>>5)&0x1u)             /**< Get UsbGHWCFG4AhbFreq from register */
#define  USB_GHWCFG4_HIBERNATION_SHIFT                      6                             /**< Shift for UsbGHWCFG4Hibernation */
#define  USB_GHWCFG4_HIBERNATION_MASK                       0x00000040u                   /**< Mask for UsbGHWCFG4Hibernation */
#define  USB_GHWCFG4_HIBERNATION_BMASK                      0x1u                          /**< Base mask for UsbGHWCFG4Hibernation */
#define  USB_GHWCFG4_HIBERNATION(x)                         (((x)&0x1u)<<6)               /**< Set UsbGHWCFG4Hibernation in register */
#define  GET_USB_GHWCFG4_HIBERNATION(reg)                   (((reg)>>6)&0x1u)             /**< Get UsbGHWCFG4Hibernation from register */
#define  USB_GHWCFG4_EXTENDED_HIBERNATION_SHIFT             7                             /**< Shift for UsbGHWCFG4ExtendedHibernation */
#define  USB_GHWCFG4_EXTENDED_HIBERNATION_MASK              0x00000080u                   /**< Mask for UsbGHWCFG4ExtendedHibernation */
#define  USB_GHWCFG4_EXTENDED_HIBERNATION_BMASK             0x1u                          /**< Base mask for UsbGHWCFG4ExtendedHibernation */
#define  USB_GHWCFG4_EXTENDED_HIBERNATION(x)                (((x)&0x1u)<<7)               /**< Set UsbGHWCFG4ExtendedHibernation in register */
#define  GET_USB_GHWCFG4_EXTENDED_HIBERNATION(reg)          (((reg)>>7)&0x1u)             /**< Get UsbGHWCFG4ExtendedHibernation from register */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT1_SHIFT                9                             /**< Shift for UsbGHWCFG4EnhancedLPMSupt1 */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT1_MASK                 0x00000200u                   /**< Mask for UsbGHWCFG4EnhancedLPMSupt1 */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT1_BMASK                0x1u                          /**< Base mask for UsbGHWCFG4EnhancedLPMSupt1 */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT1(x)                   (((x)&0x1u)<<9)               /**< Set UsbGHWCFG4EnhancedLPMSupt1 in register */
#define  GET_USB_GHWCFG4_ENHANCED_LPMSUPT1(reg)             (((reg)>>9)&0x1u)             /**< Get UsbGHWCFG4EnhancedLPMSupt1 from register */
#define  USB_GHWCFG4_SERV_INT_FLOW_SHIFT                    10                            /**< Shift for UsbGHWCFG4ServIntFlow */
#define  USB_GHWCFG4_SERV_INT_FLOW_MASK                     0x00000400u                   /**< Mask for UsbGHWCFG4ServIntFlow */
#define  USB_GHWCFG4_SERV_INT_FLOW_BMASK                    0x1u                          /**< Base mask for UsbGHWCFG4ServIntFlow */
#define  USB_GHWCFG4_SERV_INT_FLOW(x)                       (((x)&0x1u)<<10)              /**< Set UsbGHWCFG4ServIntFlow in register */
#define  GET_USB_GHWCFG4_SERV_INT_FLOW(reg)                 (((reg)>>10)&0x1u)            /**< Get UsbGHWCFG4ServIntFlow from register */
#define  USB_GHWCFG4_IPGISOC_SUPT_SHIFT                     11                            /**< Shift for UsbGHWCFG4ipgisocSupt */
#define  USB_GHWCFG4_IPGISOC_SUPT_MASK                      0x00000800u                   /**< Mask for UsbGHWCFG4ipgisocSupt */
#define  USB_GHWCFG4_IPGISOC_SUPT_BMASK                     0x1u                          /**< Base mask for UsbGHWCFG4ipgisocSupt */
#define  USB_GHWCFG4_IPGISOC_SUPT(x)                        (((x)&0x1u)<<11)              /**< Set UsbGHWCFG4ipgisocSupt in register */
#define  GET_USB_GHWCFG4_IPGISOC_SUPT(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbGHWCFG4ipgisocSupt from register */
#define  USB_GHWCFG4_ACGSUPT_SHIFT                          12                            /**< Shift for UsbGHWCFG4ACGSupt */
#define  USB_GHWCFG4_ACGSUPT_MASK                           0x00001000u                   /**< Mask for UsbGHWCFG4ACGSupt */
#define  USB_GHWCFG4_ACGSUPT_BMASK                          0x1u                          /**< Base mask for UsbGHWCFG4ACGSupt */
#define  USB_GHWCFG4_ACGSUPT(x)                             (((x)&0x1u)<<12)              /**< Set UsbGHWCFG4ACGSupt in register */
#define  GET_USB_GHWCFG4_ACGSUPT(reg)                       (((reg)>>12)&0x1u)            /**< Get UsbGHWCFG4ACGSupt from register */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT_SHIFT                 13                            /**< Shift for UsbGHWCFG4EnhancedLPMSupt */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT_MASK                  0x00002000u                   /**< Mask for UsbGHWCFG4EnhancedLPMSupt */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT_BMASK                 0x1u                          /**< Base mask for UsbGHWCFG4EnhancedLPMSupt */
#define  USB_GHWCFG4_ENHANCED_LPMSUPT(x)                    (((x)&0x1u)<<13)              /**< Set UsbGHWCFG4EnhancedLPMSupt in register */
#define  GET_USB_GHWCFG4_ENHANCED_LPMSUPT(reg)              (((reg)>>13)&0x1u)            /**< Get UsbGHWCFG4EnhancedLPMSupt from register */
#define  USB_GHWCFG4_PHY_DATA_WIDTH_SHIFT                   14                            /**< Shift for UsbGHWCFG4PhyDataWidth */
#define  USB_GHWCFG4_PHY_DATA_WIDTH_MASK                    0x0000C000u                   /**< Mask for UsbGHWCFG4PhyDataWidth */
#define  USB_GHWCFG4_PHY_DATA_WIDTH_BMASK                   0x3u                          /**< Base mask for UsbGHWCFG4PhyDataWidth */
#define  USB_GHWCFG4_PHY_DATA_WIDTH(x)                      (((x)&0x3u)<<14)              /**< Set UsbGHWCFG4PhyDataWidth in register */
#define  GET_USB_GHWCFG4_PHY_DATA_WIDTH(reg)                (((reg)>>14)&0x3u)            /**< Get UsbGHWCFG4PhyDataWidth from register */
#define  USB_GHWCFG4_NUM_CTL_EPS_SHIFT                      16                            /**< Shift for UsbGHWCFG4NumCtlEps */
#define  USB_GHWCFG4_NUM_CTL_EPS_MASK                       0x000F0000u                   /**< Mask for UsbGHWCFG4NumCtlEps */
#define  USB_GHWCFG4_NUM_CTL_EPS_BMASK                      0xFu                          /**< Base mask for UsbGHWCFG4NumCtlEps */
#define  USB_GHWCFG4_NUM_CTL_EPS(x)                         (((x)&0xFu)<<16)              /**< Set UsbGHWCFG4NumCtlEps in register */
#define  GET_USB_GHWCFG4_NUM_CTL_EPS(reg)                   (((reg)>>16)&0xFu)            /**< Get UsbGHWCFG4NumCtlEps from register */
#define  USB_GHWCFG4_IDDG_FLTR_SHIFT                        20                            /**< Shift for UsbGHWCFG4IddgFltr */
#define  USB_GHWCFG4_IDDG_FLTR_MASK                         0x00100000u                   /**< Mask for UsbGHWCFG4IddgFltr */
#define  USB_GHWCFG4_IDDG_FLTR_BMASK                        0x1u                          /**< Base mask for UsbGHWCFG4IddgFltr */
#define  USB_GHWCFG4_IDDG_FLTR(x)                           (((x)&0x1u)<<20)              /**< Set UsbGHWCFG4IddgFltr in register */
#define  GET_USB_GHWCFG4_IDDG_FLTR(reg)                     (((reg)>>20)&0x1u)            /**< Get UsbGHWCFG4IddgFltr from register */
#define  USB_GHWCFG4_VBUS_VALID_FLTR_SHIFT                  21                            /**< Shift for UsbGHWCFG4VBusValidFltr */
#define  USB_GHWCFG4_VBUS_VALID_FLTR_MASK                   0x00200000u                   /**< Mask for UsbGHWCFG4VBusValidFltr */
#define  USB_GHWCFG4_VBUS_VALID_FLTR_BMASK                  0x1u                          /**< Base mask for UsbGHWCFG4VBusValidFltr */
#define  USB_GHWCFG4_VBUS_VALID_FLTR(x)                     (((x)&0x1u)<<21)              /**< Set UsbGHWCFG4VBusValidFltr in register */
#define  GET_USB_GHWCFG4_VBUS_VALID_FLTR(reg)               (((reg)>>21)&0x1u)            /**< Get UsbGHWCFG4VBusValidFltr from register */
#define  USB_GHWCFG4_AVALID_FLTR_SHIFT                      22                            /**< Shift for UsbGHWCFG4AValidFltr */
#define  USB_GHWCFG4_AVALID_FLTR_MASK                       0x00400000u                   /**< Mask for UsbGHWCFG4AValidFltr */
#define  USB_GHWCFG4_AVALID_FLTR_BMASK                      0x1u                          /**< Base mask for UsbGHWCFG4AValidFltr */
#define  USB_GHWCFG4_AVALID_FLTR(x)                         (((x)&0x1u)<<22)              /**< Set UsbGHWCFG4AValidFltr in register */
#define  GET_USB_GHWCFG4_AVALID_FLTR(reg)                   (((reg)>>22)&0x1u)            /**< Get UsbGHWCFG4AValidFltr from register */
#define  USB_GHWCFG4_BVALID_FLTR_SHIFT                      23                            /**< Shift for UsbGHWCFG4BValidFltr */
#define  USB_GHWCFG4_BVALID_FLTR_MASK                       0x00800000u                   /**< Mask for UsbGHWCFG4BValidFltr */
#define  USB_GHWCFG4_BVALID_FLTR_BMASK                      0x1u                          /**< Base mask for UsbGHWCFG4BValidFltr */
#define  USB_GHWCFG4_BVALID_FLTR(x)                         (((x)&0x1u)<<23)              /**< Set UsbGHWCFG4BValidFltr in register */
#define  GET_USB_GHWCFG4_BVALID_FLTR(reg)                   (((reg)>>23)&0x1u)            /**< Get UsbGHWCFG4BValidFltr from register */
#define  USB_GHWCFG4_SESS_END_FLTR_SHIFT                    24                            /**< Shift for UsbGHWCFG4SessEndFltr */
#define  USB_GHWCFG4_SESS_END_FLTR_MASK                     0x01000000u                   /**< Mask for UsbGHWCFG4SessEndFltr */
#define  USB_GHWCFG4_SESS_END_FLTR_BMASK                    0x1u                          /**< Base mask for UsbGHWCFG4SessEndFltr */
#define  USB_GHWCFG4_SESS_END_FLTR(x)                       (((x)&0x1u)<<24)              /**< Set UsbGHWCFG4SessEndFltr in register */
#define  GET_USB_GHWCFG4_SESS_END_FLTR(reg)                 (((reg)>>24)&0x1u)            /**< Get UsbGHWCFG4SessEndFltr from register */
#define  USB_GHWCFG4_DED_FIFO_MODE_SHIFT                    25                            /**< Shift for UsbGHWCFG4DedFifoMode */
#define  USB_GHWCFG4_DED_FIFO_MODE_MASK                     0x02000000u                   /**< Mask for UsbGHWCFG4DedFifoMode */
#define  USB_GHWCFG4_DED_FIFO_MODE_BMASK                    0x1u                          /**< Base mask for UsbGHWCFG4DedFifoMode */
#define  USB_GHWCFG4_DED_FIFO_MODE(x)                       (((x)&0x1u)<<25)              /**< Set UsbGHWCFG4DedFifoMode in register */
#define  GET_USB_GHWCFG4_DED_FIFO_MODE(reg)                 (((reg)>>25)&0x1u)            /**< Get UsbGHWCFG4DedFifoMode from register */
#define  USB_GHWCFG4_INEPS_SHIFT                            26                            /**< Shift for UsbGHWCFG4INEps */
#define  USB_GHWCFG4_INEPS_MASK                             0x3C000000u                   /**< Mask for UsbGHWCFG4INEps */
#define  USB_GHWCFG4_INEPS_BMASK                            0xFu                          /**< Base mask for UsbGHWCFG4INEps */
#define  USB_GHWCFG4_INEPS(x)                               (((x)&0xFu)<<26)              /**< Set UsbGHWCFG4INEps in register */
#define  GET_USB_GHWCFG4_INEPS(reg)                         (((reg)>>26)&0xFu)            /**< Get UsbGHWCFG4INEps from register */
#define  USB_GHWCFG4_DESC_DMAENABLED_SHIFT                  30                            /**< Shift for UsbGHWCFG4DescDMAEnabled */
#define  USB_GHWCFG4_DESC_DMAENABLED_MASK                   0x40000000u                   /**< Mask for UsbGHWCFG4DescDMAEnabled */
#define  USB_GHWCFG4_DESC_DMAENABLED_BMASK                  0x1u                          /**< Base mask for UsbGHWCFG4DescDMAEnabled */
#define  USB_GHWCFG4_DESC_DMAENABLED(x)                     (((x)&0x1u)<<30)              /**< Set UsbGHWCFG4DescDMAEnabled in register */
#define  GET_USB_GHWCFG4_DESC_DMAENABLED(reg)               (((reg)>>30)&0x1u)            /**< Get UsbGHWCFG4DescDMAEnabled from register */
#define  USB_GHWCFG4_DESC_DMA_SHIFT                         31                            /**< Shift for UsbGHWCFG4DescDMA */
#define  USB_GHWCFG4_DESC_DMA_MASK                          0x80000000u                   /**< Mask for UsbGHWCFG4DescDMA */
#define  USB_GHWCFG4_DESC_DMA_BMASK                         0x1u                          /**< Base mask for UsbGHWCFG4DescDMA */
#define  USB_GHWCFG4_DESC_DMA(x)                            (((x)&0x1u)<<31)              /**< Set UsbGHWCFG4DescDMA in register */
#define  GET_USB_GHWCFG4_DESC_DMA(reg)                      (((reg)>>31)&0x1u)            /**< Get UsbGHWCFG4DescDMA from register */
/** @} */


/**
 * @name RegUsbGINTMSK2
 * @{
 */
// RegUsbGINTMSK2.r32
#define  REG_USB_GINTMSK2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbGINTMSK2 */
#define  REG_USB_GINTMSK2_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbGINTMSK2 */

#define  USB_GINTMSK2_GINTMSK2_SHIFT                        0                             /**< Shift for UsbGINTMSK2GINTMSK2 */
#define  USB_GINTMSK2_GINTMSK2_MASK                         0xFFFFFFFFu                   /**< Mask for UsbGINTMSK2GINTMSK2 */
#define  USB_GINTMSK2_GINTMSK2_BMASK                        0xFFFFFFFFu                   /**< Base mask for UsbGINTMSK2GINTMSK2 */
#define  USB_GINTMSK2_GINTMSK2(x)                           (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbGINTMSK2GINTMSK2 in register */
#define  GET_USB_GINTMSK2_GINTMSK2(reg)                     (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbGINTMSK2GINTMSK2 from register */
/** @} */


/**
 * @name RegUsbGINTSTS2
 * @{
 */
// RegUsbGINTSTS2.r32
#define  REG_USB_GINTSTS2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbGINTSTS2 */
#define  REG_USB_GINTSTS2_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbGINTSTS2 */

#define  USB_GINTSTS2_GINTSTS2_SHIFT                        0                             /**< Shift for UsbGINTSTS2GINTSTS2 */
#define  USB_GINTSTS2_GINTSTS2_MASK                         0xFFFFFFFFu                   /**< Mask for UsbGINTSTS2GINTSTS2 */
#define  USB_GINTSTS2_GINTSTS2_BMASK                        0xFFFFFFFFu                   /**< Base mask for UsbGINTSTS2GINTSTS2 */
#define  USB_GINTSTS2_GINTSTS2(x)                           (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbGINTSTS2GINTSTS2 in register */
#define  GET_USB_GINTSTS2_GINTSTS2(reg)                     (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbGINTSTS2GINTSTS2 from register */
/** @} */


/**
 * @name RegUsbDPTXFSIZ1
 * @{
 */
// RegUsbDPTXFSIZ1.r32
#define  REG_USB_DPTXFSIZ1_RESET_VALUE                      0x002000A0u                   /**< Reset value of RegUsbDPTXFSIZ1 */
#define  REG_USB_DPTXFSIZ1_MASK                             0xFFFF00FFu                   /**< Mask for RegUsbDPTXFSIZ1 */

#define  USB_DPTXFSIZ1_DPTX_FST_ADDR_SHIFT                  0                             /**< Shift for UsbDPTXFSIZ1DPTxFStAddr */
#define  USB_DPTXFSIZ1_DPTX_FST_ADDR_MASK                   0x000000FFu                   /**< Mask for UsbDPTXFSIZ1DPTxFStAddr */
#define  USB_DPTXFSIZ1_DPTX_FST_ADDR_BMASK                  0xFFu                         /**< Base mask for UsbDPTXFSIZ1DPTxFStAddr */
#define  USB_DPTXFSIZ1_DPTX_FST_ADDR(x)                     (((x)&0xFFu)<<0)              /**< Set UsbDPTXFSIZ1DPTxFStAddr in register */
#define  GET_USB_DPTXFSIZ1_DPTX_FST_ADDR(reg)               (((reg)>>0)&0xFFu)            /**< Get UsbDPTXFSIZ1DPTxFStAddr from register */
#define  USB_DPTXFSIZ1_DPTX_FSIZE_SHIFT                     16                            /**< Shift for UsbDPTXFSIZ1DPTxFSize */
#define  USB_DPTXFSIZ1_DPTX_FSIZE_MASK                      0xFFFF0000u                   /**< Mask for UsbDPTXFSIZ1DPTxFSize */
#define  USB_DPTXFSIZ1_DPTX_FSIZE_BMASK                     0xFFFFu                       /**< Base mask for UsbDPTXFSIZ1DPTxFSize */
#define  USB_DPTXFSIZ1_DPTX_FSIZE(x)                        (((x)&0xFFFFu)<<16)           /**< Set UsbDPTXFSIZ1DPTxFSize in register */
#define  GET_USB_DPTXFSIZ1_DPTX_FSIZE(reg)                  (((reg)>>16)&0xFFFFu)         /**< Get UsbDPTXFSIZ1DPTxFSize from register */
/** @} */


/**
 * @name RegUsbDPTXFSIZ2
 * @{
 */
// RegUsbDPTXFSIZ2.r32
#define  REG_USB_DPTXFSIZ2_RESET_VALUE                      0x002000C0u                   /**< Reset value of RegUsbDPTXFSIZ2 */
#define  REG_USB_DPTXFSIZ2_MASK                             0xFFFF00FFu                   /**< Mask for RegUsbDPTXFSIZ2 */

#define  USB_DPTXFSIZ2_DPTX_FST_ADDR_SHIFT                  0                             /**< Shift for UsbDPTXFSIZ2DPTxFStAddr */
#define  USB_DPTXFSIZ2_DPTX_FST_ADDR_MASK                   0x000000FFu                   /**< Mask for UsbDPTXFSIZ2DPTxFStAddr */
#define  USB_DPTXFSIZ2_DPTX_FST_ADDR_BMASK                  0xFFu                         /**< Base mask for UsbDPTXFSIZ2DPTxFStAddr */
#define  USB_DPTXFSIZ2_DPTX_FST_ADDR(x)                     (((x)&0xFFu)<<0)              /**< Set UsbDPTXFSIZ2DPTxFStAddr in register */
#define  GET_USB_DPTXFSIZ2_DPTX_FST_ADDR(reg)               (((reg)>>0)&0xFFu)            /**< Get UsbDPTXFSIZ2DPTxFStAddr from register */
#define  USB_DPTXFSIZ2_DPTX_FSIZE_SHIFT                     16                            /**< Shift for UsbDPTXFSIZ2DPTxFSize */
#define  USB_DPTXFSIZ2_DPTX_FSIZE_MASK                      0xFFFF0000u                   /**< Mask for UsbDPTXFSIZ2DPTxFSize */
#define  USB_DPTXFSIZ2_DPTX_FSIZE_BMASK                     0xFFFFu                       /**< Base mask for UsbDPTXFSIZ2DPTxFSize */
#define  USB_DPTXFSIZ2_DPTX_FSIZE(x)                        (((x)&0xFFFFu)<<16)           /**< Set UsbDPTXFSIZ2DPTxFSize in register */
#define  GET_USB_DPTXFSIZ2_DPTX_FSIZE(reg)                  (((reg)>>16)&0xFFFFu)         /**< Get UsbDPTXFSIZ2DPTxFSize from register */
/** @} */


/**
 * @name RegUsbDPTXFSIZ3
 * @{
 */
// RegUsbDPTXFSIZ3.r32
#define  REG_USB_DPTXFSIZ3_RESET_VALUE                      0x002000E0u                   /**< Reset value of RegUsbDPTXFSIZ3 */
#define  REG_USB_DPTXFSIZ3_MASK                             0xFFFF00FFu                   /**< Mask for RegUsbDPTXFSIZ3 */

#define  USB_DPTXFSIZ3_DPTX_FST_ADDR_SHIFT                  0                             /**< Shift for UsbDPTXFSIZ3DPTxFStAddr */
#define  USB_DPTXFSIZ3_DPTX_FST_ADDR_MASK                   0x000000FFu                   /**< Mask for UsbDPTXFSIZ3DPTxFStAddr */
#define  USB_DPTXFSIZ3_DPTX_FST_ADDR_BMASK                  0xFFu                         /**< Base mask for UsbDPTXFSIZ3DPTxFStAddr */
#define  USB_DPTXFSIZ3_DPTX_FST_ADDR(x)                     (((x)&0xFFu)<<0)              /**< Set UsbDPTXFSIZ3DPTxFStAddr in register */
#define  GET_USB_DPTXFSIZ3_DPTX_FST_ADDR(reg)               (((reg)>>0)&0xFFu)            /**< Get UsbDPTXFSIZ3DPTxFStAddr from register */
#define  USB_DPTXFSIZ3_DPTX_FSIZE_SHIFT                     16                            /**< Shift for UsbDPTXFSIZ3DPTxFSize */
#define  USB_DPTXFSIZ3_DPTX_FSIZE_MASK                      0xFFFF0000u                   /**< Mask for UsbDPTXFSIZ3DPTxFSize */
#define  USB_DPTXFSIZ3_DPTX_FSIZE_BMASK                     0xFFFFu                       /**< Base mask for UsbDPTXFSIZ3DPTxFSize */
#define  USB_DPTXFSIZ3_DPTX_FSIZE(x)                        (((x)&0xFFFFu)<<16)           /**< Set UsbDPTXFSIZ3DPTxFSize in register */
#define  GET_USB_DPTXFSIZ3_DPTX_FSIZE(reg)                  (((reg)>>16)&0xFFFFu)         /**< Get UsbDPTXFSIZ3DPTxFSize from register */
/** @} */


/**
 * @name RegUsbDCFG
 * @{
 */
// RegUsbDCFG.r32
#define  REG_USB_DCFG_RESET_VALUE                           0x08200000u                   /**< Reset value of RegUsbDCFG */
#define  REG_USB_DCFG_MASK                                  0xFF7CDFFFu                   /**< Mask for RegUsbDCFG */

#define  USB_DCFG_DEV_SPD_SHIFT                             0                             /**< Shift for UsbDCFGDevSpd */
#define  USB_DCFG_DEV_SPD_MASK                              0x00000003u                   /**< Mask for UsbDCFGDevSpd */
#define  USB_DCFG_DEV_SPD_BMASK                             0x3u                          /**< Base mask for UsbDCFGDevSpd */
#define  USB_DCFG_DEV_SPD(x)                                (((x)&0x3u)<<0)               /**< Set UsbDCFGDevSpd in register */
#define  GET_USB_DCFG_DEV_SPD(reg)                          (((reg)>>0)&0x3u)             /**< Get UsbDCFGDevSpd from register */
#define  USB_DCFG_NZSTS_OUTHSHK_SHIFT                       2                             /**< Shift for UsbDCFGNZStsOUTHShk */
#define  USB_DCFG_NZSTS_OUTHSHK_MASK                        0x00000004u                   /**< Mask for UsbDCFGNZStsOUTHShk */
#define  USB_DCFG_NZSTS_OUTHSHK_BMASK                       0x1u                          /**< Base mask for UsbDCFGNZStsOUTHShk */
#define  USB_DCFG_NZSTS_OUTHSHK(x)                          (((x)&0x1u)<<2)               /**< Set UsbDCFGNZStsOUTHShk in register */
#define  GET_USB_DCFG_NZSTS_OUTHSHK(reg)                    (((reg)>>2)&0x1u)             /**< Get UsbDCFGNZStsOUTHShk from register */
#define  USB_DCFG_ENA32KHZ_SUSP_SHIFT                       3                             /**< Shift for UsbDCFGEna32KHzSusp */
#define  USB_DCFG_ENA32KHZ_SUSP_MASK                        0x00000008u                   /**< Mask for UsbDCFGEna32KHzSusp */
#define  USB_DCFG_ENA32KHZ_SUSP_BMASK                       0x1u                          /**< Base mask for UsbDCFGEna32KHzSusp */
#define  USB_DCFG_ENA32KHZ_SUSP(x)                          (((x)&0x1u)<<3)               /**< Set UsbDCFGEna32KHzSusp in register */
#define  GET_USB_DCFG_ENA32KHZ_SUSP(reg)                    (((reg)>>3)&0x1u)             /**< Get UsbDCFGEna32KHzSusp from register */
#define  USB_DCFG_DEV_ADDR_SHIFT                            4                             /**< Shift for UsbDCFGDevAddr */
#define  USB_DCFG_DEV_ADDR_MASK                             0x000007F0u                   /**< Mask for UsbDCFGDevAddr */
#define  USB_DCFG_DEV_ADDR_BMASK                            0x7Fu                         /**< Base mask for UsbDCFGDevAddr */
#define  USB_DCFG_DEV_ADDR(x)                               (((x)&0x7Fu)<<4)              /**< Set UsbDCFGDevAddr in register */
#define  GET_USB_DCFG_DEV_ADDR(reg)                         (((reg)>>4)&0x7Fu)            /**< Get UsbDCFGDevAddr from register */
#define  USB_DCFG_PER_FR_INT_SHIFT                          11                            /**< Shift for UsbDCFGPerFrInt */
#define  USB_DCFG_PER_FR_INT_MASK                           0x00001800u                   /**< Mask for UsbDCFGPerFrInt */
#define  USB_DCFG_PER_FR_INT_BMASK                          0x3u                          /**< Base mask for UsbDCFGPerFrInt */
#define  USB_DCFG_PER_FR_INT(x)                             (((x)&0x3u)<<11)              /**< Set UsbDCFGPerFrInt in register */
#define  GET_USB_DCFG_PER_FR_INT(reg)                       (((reg)>>11)&0x3u)            /**< Get UsbDCFGPerFrInt from register */
#define  USB_DCFG_XCVRDLY_SHIFT                             14                            /**< Shift for UsbDCFGXCVRDLY */
#define  USB_DCFG_XCVRDLY_MASK                              0x00004000u                   /**< Mask for UsbDCFGXCVRDLY */
#define  USB_DCFG_XCVRDLY_BMASK                             0x1u                          /**< Base mask for UsbDCFGXCVRDLY */
#define  USB_DCFG_XCVRDLY(x)                                (((x)&0x1u)<<14)              /**< Set UsbDCFGXCVRDLY in register */
#define  GET_USB_DCFG_XCVRDLY(reg)                          (((reg)>>14)&0x1u)            /**< Get UsbDCFGXCVRDLY from register */
#define  USB_DCFG_ERRATIC_INT_MSK_SHIFT                     15                            /**< Shift for UsbDCFGErraticIntMsk */
#define  USB_DCFG_ERRATIC_INT_MSK_MASK                      0x00008000u                   /**< Mask for UsbDCFGErraticIntMsk */
#define  USB_DCFG_ERRATIC_INT_MSK_BMASK                     0x1u                          /**< Base mask for UsbDCFGErraticIntMsk */
#define  USB_DCFG_ERRATIC_INT_MSK(x)                        (((x)&0x1u)<<15)              /**< Set UsbDCFGErraticIntMsk in register */
#define  GET_USB_DCFG_ERRATIC_INT_MSK(reg)                  (((reg)>>15)&0x1u)            /**< Get UsbDCFGErraticIntMsk from register */
#define  USB_DCFG_EPMIS_CNT_SHIFT                           18                            /**< Shift for UsbDCFGEPMisCnt */
#define  USB_DCFG_EPMIS_CNT_MASK                            0x007C0000u                   /**< Mask for UsbDCFGEPMisCnt */
#define  USB_DCFG_EPMIS_CNT_BMASK                           0x1Fu                         /**< Base mask for UsbDCFGEPMisCnt */
#define  USB_DCFG_EPMIS_CNT(x)                              (((x)&0x1Fu)<<18)             /**< Set UsbDCFGEPMisCnt in register */
#define  GET_USB_DCFG_EPMIS_CNT(reg)                        (((reg)>>18)&0x1Fu)           /**< Get UsbDCFGEPMisCnt from register */
#define  USB_DCFG_PER_SCH_INTVL_SHIFT                       24                            /**< Shift for UsbDCFGPerSchIntvl */
#define  USB_DCFG_PER_SCH_INTVL_MASK                        0x03000000u                   /**< Mask for UsbDCFGPerSchIntvl */
#define  USB_DCFG_PER_SCH_INTVL_BMASK                       0x3u                          /**< Base mask for UsbDCFGPerSchIntvl */
#define  USB_DCFG_PER_SCH_INTVL(x)                          (((x)&0x3u)<<24)              /**< Set UsbDCFGPerSchIntvl in register */
#define  GET_USB_DCFG_PER_SCH_INTVL(reg)                    (((reg)>>24)&0x3u)            /**< Get UsbDCFGPerSchIntvl from register */
#define  USB_DCFG_RES_VALID_SHIFT                           26                            /**< Shift for UsbDCFGResValid */
#define  USB_DCFG_RES_VALID_MASK                            0xFC000000u                   /**< Mask for UsbDCFGResValid */
#define  USB_DCFG_RES_VALID_BMASK                           0x3Fu                         /**< Base mask for UsbDCFGResValid */
#define  USB_DCFG_RES_VALID(x)                              (((x)&0x3Fu)<<26)             /**< Set UsbDCFGResValid in register */
#define  GET_USB_DCFG_RES_VALID(reg)                        (((reg)>>26)&0x3Fu)           /**< Get UsbDCFGResValid from register */
/** @} */


/**
 * @name RegUsbDCTL
 * @{
 */
// RegUsbDCTL.r32
#define  REG_USB_DCTL_RESET_VALUE                           0x00000002u                   /**< Reset value of RegUsbDCTL */
#define  REG_USB_DCTL_MASK                                  0x00098FFFu                   /**< Mask for RegUsbDCTL */

#define  USB_DCTL_RMT_WK_UP_SIG_SHIFT                       0                             /**< Shift for UsbDCTLRmtWkUpSig */
#define  USB_DCTL_RMT_WK_UP_SIG_MASK                        0x00000001u                   /**< Mask for UsbDCTLRmtWkUpSig */
#define  USB_DCTL_RMT_WK_UP_SIG_BMASK                       0x1u                          /**< Base mask for UsbDCTLRmtWkUpSig */
#define  USB_DCTL_RMT_WK_UP_SIG(x)                          (((x)&0x1u)<<0)               /**< Set UsbDCTLRmtWkUpSig in register */
#define  GET_USB_DCTL_RMT_WK_UP_SIG(reg)                    (((reg)>>0)&0x1u)             /**< Get UsbDCTLRmtWkUpSig from register */
#define  USB_DCTL_SFT_DISCON_SHIFT                          1                             /**< Shift for UsbDCTLSftDiscon */
#define  USB_DCTL_SFT_DISCON_MASK                           0x00000002u                   /**< Mask for UsbDCTLSftDiscon */
#define  USB_DCTL_SFT_DISCON_BMASK                          0x1u                          /**< Base mask for UsbDCTLSftDiscon */
#define  USB_DCTL_SFT_DISCON(x)                             (((x)&0x1u)<<1)               /**< Set UsbDCTLSftDiscon in register */
#define  GET_USB_DCTL_SFT_DISCON(reg)                       (((reg)>>1)&0x1u)             /**< Get UsbDCTLSftDiscon from register */
#define  USB_DCTL_GNPINNAK_STS_SHIFT                        2                             /**< Shift for UsbDCTLGNPINNakSts */
#define  USB_DCTL_GNPINNAK_STS_MASK                         0x00000004u                   /**< Mask for UsbDCTLGNPINNakSts */
#define  USB_DCTL_GNPINNAK_STS_BMASK                        0x1u                          /**< Base mask for UsbDCTLGNPINNakSts */
#define  USB_DCTL_GNPINNAK_STS(x)                           (((x)&0x1u)<<2)               /**< Set UsbDCTLGNPINNakSts in register */
#define  GET_USB_DCTL_GNPINNAK_STS(reg)                     (((reg)>>2)&0x1u)             /**< Get UsbDCTLGNPINNakSts from register */
#define  USB_DCTL_GOUTNAK_STS_SHIFT                         3                             /**< Shift for UsbDCTLGOUTNakSts */
#define  USB_DCTL_GOUTNAK_STS_MASK                          0x00000008u                   /**< Mask for UsbDCTLGOUTNakSts */
#define  USB_DCTL_GOUTNAK_STS_BMASK                         0x1u                          /**< Base mask for UsbDCTLGOUTNakSts */
#define  USB_DCTL_GOUTNAK_STS(x)                            (((x)&0x1u)<<3)               /**< Set UsbDCTLGOUTNakSts in register */
#define  GET_USB_DCTL_GOUTNAK_STS(reg)                      (((reg)>>3)&0x1u)             /**< Get UsbDCTLGOUTNakSts from register */
#define  USB_DCTL_TST_CTL_SHIFT                             4                             /**< Shift for UsbDCTLTstCtl */
#define  USB_DCTL_TST_CTL_MASK                              0x00000070u                   /**< Mask for UsbDCTLTstCtl */
#define  USB_DCTL_TST_CTL_BMASK                             0x7u                          /**< Base mask for UsbDCTLTstCtl */
#define  USB_DCTL_TST_CTL(x)                                (((x)&0x7u)<<4)               /**< Set UsbDCTLTstCtl in register */
#define  GET_USB_DCTL_TST_CTL(reg)                          (((reg)>>4)&0x7u)             /**< Get UsbDCTLTstCtl from register */
#define  USB_DCTL_SGNPIN_NAK_SHIFT                          7                             /**< Shift for UsbDCTLSGNPInNak */
#define  USB_DCTL_SGNPIN_NAK_MASK                           0x00000080u                   /**< Mask for UsbDCTLSGNPInNak */
#define  USB_DCTL_SGNPIN_NAK_BMASK                          0x1u                          /**< Base mask for UsbDCTLSGNPInNak */
#define  USB_DCTL_SGNPIN_NAK(x)                             (((x)&0x1u)<<7)               /**< Set UsbDCTLSGNPInNak in register */
#define  GET_USB_DCTL_SGNPIN_NAK(reg)                       (((reg)>>7)&0x1u)             /**< Get UsbDCTLSGNPInNak from register */
#define  USB_DCTL_CGNPIN_NAK_SHIFT                          8                             /**< Shift for UsbDCTLCGNPInNak */
#define  USB_DCTL_CGNPIN_NAK_MASK                           0x00000100u                   /**< Mask for UsbDCTLCGNPInNak */
#define  USB_DCTL_CGNPIN_NAK_BMASK                          0x1u                          /**< Base mask for UsbDCTLCGNPInNak */
#define  USB_DCTL_CGNPIN_NAK(x)                             (((x)&0x1u)<<8)               /**< Set UsbDCTLCGNPInNak in register */
#define  GET_USB_DCTL_CGNPIN_NAK(reg)                       (((reg)>>8)&0x1u)             /**< Get UsbDCTLCGNPInNak from register */
#define  USB_DCTL_SGOUTNAK_SHIFT                            9                             /**< Shift for UsbDCTLSGOUTNak */
#define  USB_DCTL_SGOUTNAK_MASK                             0x00000200u                   /**< Mask for UsbDCTLSGOUTNak */
#define  USB_DCTL_SGOUTNAK_BMASK                            0x1u                          /**< Base mask for UsbDCTLSGOUTNak */
#define  USB_DCTL_SGOUTNAK(x)                               (((x)&0x1u)<<9)               /**< Set UsbDCTLSGOUTNak in register */
#define  GET_USB_DCTL_SGOUTNAK(reg)                         (((reg)>>9)&0x1u)             /**< Get UsbDCTLSGOUTNak from register */
#define  USB_DCTL_CGOUTNAK_SHIFT                            10                            /**< Shift for UsbDCTLCGOUTNak */
#define  USB_DCTL_CGOUTNAK_MASK                             0x00000400u                   /**< Mask for UsbDCTLCGOUTNak */
#define  USB_DCTL_CGOUTNAK_BMASK                            0x1u                          /**< Base mask for UsbDCTLCGOUTNak */
#define  USB_DCTL_CGOUTNAK(x)                               (((x)&0x1u)<<10)              /**< Set UsbDCTLCGOUTNak in register */
#define  GET_USB_DCTL_CGOUTNAK(reg)                         (((reg)>>10)&0x1u)            /**< Get UsbDCTLCGOUTNak from register */
#define  USB_DCTL_PWRON_PRG_DONE_SHIFT                      11                            /**< Shift for UsbDCTLPWROnPrgDone */
#define  USB_DCTL_PWRON_PRG_DONE_MASK                       0x00000800u                   /**< Mask for UsbDCTLPWROnPrgDone */
#define  USB_DCTL_PWRON_PRG_DONE_BMASK                      0x1u                          /**< Base mask for UsbDCTLPWROnPrgDone */
#define  USB_DCTL_PWRON_PRG_DONE(x)                         (((x)&0x1u)<<11)              /**< Set UsbDCTLPWROnPrgDone in register */
#define  GET_USB_DCTL_PWRON_PRG_DONE(reg)                   (((reg)>>11)&0x1u)            /**< Get UsbDCTLPWROnPrgDone from register */
#define  USB_DCTL_IGNR_FRM_NUM_SHIFT                        15                            /**< Shift for UsbDCTLIgnrFrmNum */
#define  USB_DCTL_IGNR_FRM_NUM_MASK                         0x00008000u                   /**< Mask for UsbDCTLIgnrFrmNum */
#define  USB_DCTL_IGNR_FRM_NUM_BMASK                        0x1u                          /**< Base mask for UsbDCTLIgnrFrmNum */
#define  USB_DCTL_IGNR_FRM_NUM(x)                           (((x)&0x1u)<<15)              /**< Set UsbDCTLIgnrFrmNum in register */
#define  GET_USB_DCTL_IGNR_FRM_NUM(reg)                     (((reg)>>15)&0x1u)            /**< Get UsbDCTLIgnrFrmNum from register */
#define  USB_DCTL_NAK_ON_BBLE_SHIFT                         16                            /**< Shift for UsbDCTLNakOnBble */
#define  USB_DCTL_NAK_ON_BBLE_MASK                          0x00010000u                   /**< Mask for UsbDCTLNakOnBble */
#define  USB_DCTL_NAK_ON_BBLE_BMASK                         0x1u                          /**< Base mask for UsbDCTLNakOnBble */
#define  USB_DCTL_NAK_ON_BBLE(x)                            (((x)&0x1u)<<16)              /**< Set UsbDCTLNakOnBble in register */
#define  GET_USB_DCTL_NAK_ON_BBLE(reg)                      (((reg)>>16)&0x1u)            /**< Get UsbDCTLNakOnBble from register */
#define  USB_DCTL_SERV_INT_SHIFT                            19                            /**< Shift for UsbDCTLServInt */
#define  USB_DCTL_SERV_INT_MASK                             0x00080000u                   /**< Mask for UsbDCTLServInt */
#define  USB_DCTL_SERV_INT_BMASK                            0x1u                          /**< Base mask for UsbDCTLServInt */
#define  USB_DCTL_SERV_INT(x)                               (((x)&0x1u)<<19)              /**< Set UsbDCTLServInt in register */
#define  GET_USB_DCTL_SERV_INT(reg)                         (((reg)>>19)&0x1u)            /**< Get UsbDCTLServInt from register */
/** @} */


/**
 * @name RegUsbDSTS
 * @{
 */
// RegUsbDSTS.r32
#define  REG_USB_DSTS_RESET_VALUE                           0x00000002u                   /**< Reset value of RegUsbDSTS */
#define  REG_USB_DSTS_MASK                                  0x00FFFF0Fu                   /**< Mask for RegUsbDSTS */

#define  USB_DSTS_SUSP_STS_SHIFT                            0                             /**< Shift for UsbDSTSSuspSts */
#define  USB_DSTS_SUSP_STS_MASK                             0x00000001u                   /**< Mask for UsbDSTSSuspSts */
#define  USB_DSTS_SUSP_STS_BMASK                            0x1u                          /**< Base mask for UsbDSTSSuspSts */
#define  USB_DSTS_SUSP_STS(x)                               (((x)&0x1u)<<0)               /**< Set UsbDSTSSuspSts in register */
#define  GET_USB_DSTS_SUSP_STS(reg)                         (((reg)>>0)&0x1u)             /**< Get UsbDSTSSuspSts from register */
#define  USB_DSTS_ENUM_SPD_SHIFT                            1                             /**< Shift for UsbDSTSEnumSpd */
#define  USB_DSTS_ENUM_SPD_MASK                             0x00000006u                   /**< Mask for UsbDSTSEnumSpd */
#define  USB_DSTS_ENUM_SPD_BMASK                            0x3u                          /**< Base mask for UsbDSTSEnumSpd */
#define  USB_DSTS_ENUM_SPD(x)                               (((x)&0x3u)<<1)               /**< Set UsbDSTSEnumSpd in register */
#define  GET_USB_DSTS_ENUM_SPD(reg)                         (((reg)>>1)&0x3u)             /**< Get UsbDSTSEnumSpd from register */
#define  USB_DSTS_ERRTIC_ERR_SHIFT                          3                             /**< Shift for UsbDSTSErrticErr */
#define  USB_DSTS_ERRTIC_ERR_MASK                           0x00000008u                   /**< Mask for UsbDSTSErrticErr */
#define  USB_DSTS_ERRTIC_ERR_BMASK                          0x1u                          /**< Base mask for UsbDSTSErrticErr */
#define  USB_DSTS_ERRTIC_ERR(x)                             (((x)&0x1u)<<3)               /**< Set UsbDSTSErrticErr in register */
#define  GET_USB_DSTS_ERRTIC_ERR(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbDSTSErrticErr from register */
#define  USB_DSTS_SOFFN_SHIFT                               8                             /**< Shift for UsbDSTSSOFFN */
#define  USB_DSTS_SOFFN_MASK                                0x003FFF00u                   /**< Mask for UsbDSTSSOFFN */
#define  USB_DSTS_SOFFN_BMASK                               0x3FFFu                       /**< Base mask for UsbDSTSSOFFN */
#define  USB_DSTS_SOFFN(x)                                  (((x)&0x3FFFu)<<8)            /**< Set UsbDSTSSOFFN in register */
#define  GET_USB_DSTS_SOFFN(reg)                            (((reg)>>8)&0x3FFFu)          /**< Get UsbDSTSSOFFN from register */
#define  USB_DSTS_DEV_LN_STS_SHIFT                          22                            /**< Shift for UsbDSTSDevLnSts */
#define  USB_DSTS_DEV_LN_STS_MASK                           0x00C00000u                   /**< Mask for UsbDSTSDevLnSts */
#define  USB_DSTS_DEV_LN_STS_BMASK                          0x3u                          /**< Base mask for UsbDSTSDevLnSts */
#define  USB_DSTS_DEV_LN_STS(x)                             (((x)&0x3u)<<22)              /**< Set UsbDSTSDevLnSts in register */
#define  GET_USB_DSTS_DEV_LN_STS(reg)                       (((reg)>>22)&0x3u)            /**< Get UsbDSTSDevLnSts from register */
/** @} */


/**
 * @name RegUsbDIEPMSK
 * @{
 */
// RegUsbDIEPMSK.r32
#define  REG_USB_DIEPMSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDIEPMSK */
#define  REG_USB_DIEPMSK_MASK                               0x0000217Bu                   /**< Mask for RegUsbDIEPMSK */

#define  USB_DIEPMSK_XFER_COMPL_MSK_SHIFT                   0                             /**< Shift for UsbDIEPMSKXferComplMsk */
#define  USB_DIEPMSK_XFER_COMPL_MSK_MASK                    0x00000001u                   /**< Mask for UsbDIEPMSKXferComplMsk */
#define  USB_DIEPMSK_XFER_COMPL_MSK_BMASK                   0x1u                          /**< Base mask for UsbDIEPMSKXferComplMsk */
#define  USB_DIEPMSK_XFER_COMPL_MSK(x)                      (((x)&0x1u)<<0)               /**< Set UsbDIEPMSKXferComplMsk in register */
#define  GET_USB_DIEPMSK_XFER_COMPL_MSK(reg)                (((reg)>>0)&0x1u)             /**< Get UsbDIEPMSKXferComplMsk from register */
#define  USB_DIEPMSK_EPDISBLD_MSK_SHIFT                     1                             /**< Shift for UsbDIEPMSKEPDisbldMsk */
#define  USB_DIEPMSK_EPDISBLD_MSK_MASK                      0x00000002u                   /**< Mask for UsbDIEPMSKEPDisbldMsk */
#define  USB_DIEPMSK_EPDISBLD_MSK_BMASK                     0x1u                          /**< Base mask for UsbDIEPMSKEPDisbldMsk */
#define  USB_DIEPMSK_EPDISBLD_MSK(x)                        (((x)&0x1u)<<1)               /**< Set UsbDIEPMSKEPDisbldMsk in register */
#define  GET_USB_DIEPMSK_EPDISBLD_MSK(reg)                  (((reg)>>1)&0x1u)             /**< Get UsbDIEPMSKEPDisbldMsk from register */
#define  USB_DIEPMSK_TIME_OUTMSK_SHIFT                      3                             /**< Shift for UsbDIEPMSKTimeOUTMsk */
#define  USB_DIEPMSK_TIME_OUTMSK_MASK                       0x00000008u                   /**< Mask for UsbDIEPMSKTimeOUTMsk */
#define  USB_DIEPMSK_TIME_OUTMSK_BMASK                      0x1u                          /**< Base mask for UsbDIEPMSKTimeOUTMsk */
#define  USB_DIEPMSK_TIME_OUTMSK(x)                         (((x)&0x1u)<<3)               /**< Set UsbDIEPMSKTimeOUTMsk in register */
#define  GET_USB_DIEPMSK_TIME_OUTMSK(reg)                   (((reg)>>3)&0x1u)             /**< Get UsbDIEPMSKTimeOUTMsk from register */
#define  USB_DIEPMSK_INTKN_TXFEMP_MSK_SHIFT                 4                             /**< Shift for UsbDIEPMSKINTknTXFEmpMsk */
#define  USB_DIEPMSK_INTKN_TXFEMP_MSK_MASK                  0x00000010u                   /**< Mask for UsbDIEPMSKINTknTXFEmpMsk */
#define  USB_DIEPMSK_INTKN_TXFEMP_MSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPMSKINTknTXFEmpMsk */
#define  USB_DIEPMSK_INTKN_TXFEMP_MSK(x)                    (((x)&0x1u)<<4)               /**< Set UsbDIEPMSKINTknTXFEmpMsk in register */
#define  GET_USB_DIEPMSK_INTKN_TXFEMP_MSK(reg)              (((reg)>>4)&0x1u)             /**< Get UsbDIEPMSKINTknTXFEmpMsk from register */
#define  USB_DIEPMSK_INTKN_EPMIS_MSK_SHIFT                  5                             /**< Shift for UsbDIEPMSKINTknEPMisMsk */
#define  USB_DIEPMSK_INTKN_EPMIS_MSK_MASK                   0x00000020u                   /**< Mask for UsbDIEPMSKINTknEPMisMsk */
#define  USB_DIEPMSK_INTKN_EPMIS_MSK_BMASK                  0x1u                          /**< Base mask for UsbDIEPMSKINTknEPMisMsk */
#define  USB_DIEPMSK_INTKN_EPMIS_MSK(x)                     (((x)&0x1u)<<5)               /**< Set UsbDIEPMSKINTknEPMisMsk in register */
#define  GET_USB_DIEPMSK_INTKN_EPMIS_MSK(reg)               (((reg)>>5)&0x1u)             /**< Get UsbDIEPMSKINTknEPMisMsk from register */
#define  USB_DIEPMSK_INEPNAK_EFF_MSK_SHIFT                  6                             /**< Shift for UsbDIEPMSKINEPNakEffMsk */
#define  USB_DIEPMSK_INEPNAK_EFF_MSK_MASK                   0x00000040u                   /**< Mask for UsbDIEPMSKINEPNakEffMsk */
#define  USB_DIEPMSK_INEPNAK_EFF_MSK_BMASK                  0x1u                          /**< Base mask for UsbDIEPMSKINEPNakEffMsk */
#define  USB_DIEPMSK_INEPNAK_EFF_MSK(x)                     (((x)&0x1u)<<6)               /**< Set UsbDIEPMSKINEPNakEffMsk in register */
#define  GET_USB_DIEPMSK_INEPNAK_EFF_MSK(reg)               (((reg)>>6)&0x1u)             /**< Get UsbDIEPMSKINEPNakEffMsk from register */
#define  USB_DIEPMSK_TXFIFO_UNDRN_MSK_SHIFT                 8                             /**< Shift for UsbDIEPMSKTxfifoUndrnMsk */
#define  USB_DIEPMSK_TXFIFO_UNDRN_MSK_MASK                  0x00000100u                   /**< Mask for UsbDIEPMSKTxfifoUndrnMsk */
#define  USB_DIEPMSK_TXFIFO_UNDRN_MSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPMSKTxfifoUndrnMsk */
#define  USB_DIEPMSK_TXFIFO_UNDRN_MSK(x)                    (((x)&0x1u)<<8)               /**< Set UsbDIEPMSKTxfifoUndrnMsk in register */
#define  GET_USB_DIEPMSK_TXFIFO_UNDRN_MSK(reg)              (((reg)>>8)&0x1u)             /**< Get UsbDIEPMSKTxfifoUndrnMsk from register */
#define  USB_DIEPMSK_NAKMSK_SHIFT                           13                            /**< Shift for UsbDIEPMSKNAKMsk */
#define  USB_DIEPMSK_NAKMSK_MASK                            0x00002000u                   /**< Mask for UsbDIEPMSKNAKMsk */
#define  USB_DIEPMSK_NAKMSK_BMASK                           0x1u                          /**< Base mask for UsbDIEPMSKNAKMsk */
#define  USB_DIEPMSK_NAKMSK(x)                              (((x)&0x1u)<<13)              /**< Set UsbDIEPMSKNAKMsk in register */
#define  GET_USB_DIEPMSK_NAKMSK(reg)                        (((reg)>>13)&0x1u)            /**< Get UsbDIEPMSKNAKMsk from register */
/** @} */


/**
 * @name RegUsbDOEPMSK
 * @{
 */
// RegUsbDOEPMSK.r32
#define  REG_USB_DOEPMSK_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDOEPMSK */
#define  REG_USB_DOEPMSK_MASK                               0x0000717Bu                   /**< Mask for RegUsbDOEPMSK */

#define  USB_DOEPMSK_XFER_COMPL_MSK_SHIFT                   0                             /**< Shift for UsbDOEPMSKXferComplMsk */
#define  USB_DOEPMSK_XFER_COMPL_MSK_MASK                    0x00000001u                   /**< Mask for UsbDOEPMSKXferComplMsk */
#define  USB_DOEPMSK_XFER_COMPL_MSK_BMASK                   0x1u                          /**< Base mask for UsbDOEPMSKXferComplMsk */
#define  USB_DOEPMSK_XFER_COMPL_MSK(x)                      (((x)&0x1u)<<0)               /**< Set UsbDOEPMSKXferComplMsk in register */
#define  GET_USB_DOEPMSK_XFER_COMPL_MSK(reg)                (((reg)>>0)&0x1u)             /**< Get UsbDOEPMSKXferComplMsk from register */
#define  USB_DOEPMSK_EPDISBLD_MSK_SHIFT                     1                             /**< Shift for UsbDOEPMSKEPDisbldMsk */
#define  USB_DOEPMSK_EPDISBLD_MSK_MASK                      0x00000002u                   /**< Mask for UsbDOEPMSKEPDisbldMsk */
#define  USB_DOEPMSK_EPDISBLD_MSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPMSKEPDisbldMsk */
#define  USB_DOEPMSK_EPDISBLD_MSK(x)                        (((x)&0x1u)<<1)               /**< Set UsbDOEPMSKEPDisbldMsk in register */
#define  GET_USB_DOEPMSK_EPDISBLD_MSK(reg)                  (((reg)>>1)&0x1u)             /**< Get UsbDOEPMSKEPDisbldMsk from register */
#define  USB_DOEPMSK_SET_UPMSK_SHIFT                        3                             /**< Shift for UsbDOEPMSKSetUPMsk */
#define  USB_DOEPMSK_SET_UPMSK_MASK                         0x00000008u                   /**< Mask for UsbDOEPMSKSetUPMsk */
#define  USB_DOEPMSK_SET_UPMSK_BMASK                        0x1u                          /**< Base mask for UsbDOEPMSKSetUPMsk */
#define  USB_DOEPMSK_SET_UPMSK(x)                           (((x)&0x1u)<<3)               /**< Set UsbDOEPMSKSetUPMsk in register */
#define  GET_USB_DOEPMSK_SET_UPMSK(reg)                     (((reg)>>3)&0x1u)             /**< Get UsbDOEPMSKSetUPMsk from register */
#define  USB_DOEPMSK_OUTTKN_EPDIS_MSK_SHIFT                 4                             /**< Shift for UsbDOEPMSKOUTTknEPdisMsk */
#define  USB_DOEPMSK_OUTTKN_EPDIS_MSK_MASK                  0x00000010u                   /**< Mask for UsbDOEPMSKOUTTknEPdisMsk */
#define  USB_DOEPMSK_OUTTKN_EPDIS_MSK_BMASK                 0x1u                          /**< Base mask for UsbDOEPMSKOUTTknEPdisMsk */
#define  USB_DOEPMSK_OUTTKN_EPDIS_MSK(x)                    (((x)&0x1u)<<4)               /**< Set UsbDOEPMSKOUTTknEPdisMsk in register */
#define  GET_USB_DOEPMSK_OUTTKN_EPDIS_MSK(reg)              (((reg)>>4)&0x1u)             /**< Get UsbDOEPMSKOUTTknEPdisMsk from register */
#define  USB_DOEPMSK_STS_PHSE_RCVD_MSK_SHIFT                5                             /**< Shift for UsbDOEPMSKStsPhseRcvdMsk */
#define  USB_DOEPMSK_STS_PHSE_RCVD_MSK_MASK                 0x00000020u                   /**< Mask for UsbDOEPMSKStsPhseRcvdMsk */
#define  USB_DOEPMSK_STS_PHSE_RCVD_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPMSKStsPhseRcvdMsk */
#define  USB_DOEPMSK_STS_PHSE_RCVD_MSK(x)                   (((x)&0x1u)<<5)               /**< Set UsbDOEPMSKStsPhseRcvdMsk in register */
#define  GET_USB_DOEPMSK_STS_PHSE_RCVD_MSK(reg)             (((reg)>>5)&0x1u)             /**< Get UsbDOEPMSKStsPhseRcvdMsk from register */
#define  USB_DOEPMSK_BACK2BACK_SETUP_SHIFT                  6                             /**< Shift for UsbDOEPMSKBack2BackSETup */
#define  USB_DOEPMSK_BACK2BACK_SETUP_MASK                   0x00000040u                   /**< Mask for UsbDOEPMSKBack2BackSETup */
#define  USB_DOEPMSK_BACK2BACK_SETUP_BMASK                  0x1u                          /**< Base mask for UsbDOEPMSKBack2BackSETup */
#define  USB_DOEPMSK_BACK2BACK_SETUP(x)                     (((x)&0x1u)<<6)               /**< Set UsbDOEPMSKBack2BackSETup in register */
#define  GET_USB_DOEPMSK_BACK2BACK_SETUP(reg)               (((reg)>>6)&0x1u)             /**< Get UsbDOEPMSKBack2BackSETup from register */
#define  USB_DOEPMSK_OUT_PKT_ERR_MSK_SHIFT                  8                             /**< Shift for UsbDOEPMSKOutPktErrMsk */
#define  USB_DOEPMSK_OUT_PKT_ERR_MSK_MASK                   0x00000100u                   /**< Mask for UsbDOEPMSKOutPktErrMsk */
#define  USB_DOEPMSK_OUT_PKT_ERR_MSK_BMASK                  0x1u                          /**< Base mask for UsbDOEPMSKOutPktErrMsk */
#define  USB_DOEPMSK_OUT_PKT_ERR_MSK(x)                     (((x)&0x1u)<<8)               /**< Set UsbDOEPMSKOutPktErrMsk in register */
#define  GET_USB_DOEPMSK_OUT_PKT_ERR_MSK(reg)               (((reg)>>8)&0x1u)             /**< Get UsbDOEPMSKOutPktErrMsk from register */
#define  USB_DOEPMSK_BBLE_ERR_MSK_SHIFT                     12                            /**< Shift for UsbDOEPMSKBbleErrMsk */
#define  USB_DOEPMSK_BBLE_ERR_MSK_MASK                      0x00001000u                   /**< Mask for UsbDOEPMSKBbleErrMsk */
#define  USB_DOEPMSK_BBLE_ERR_MSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPMSKBbleErrMsk */
#define  USB_DOEPMSK_BBLE_ERR_MSK(x)                        (((x)&0x1u)<<12)              /**< Set UsbDOEPMSKBbleErrMsk in register */
#define  GET_USB_DOEPMSK_BBLE_ERR_MSK(reg)                  (((reg)>>12)&0x1u)            /**< Get UsbDOEPMSKBbleErrMsk from register */
#define  USB_DOEPMSK_NAKMSK_SHIFT                           13                            /**< Shift for UsbDOEPMSKNAKMsk */
#define  USB_DOEPMSK_NAKMSK_MASK                            0x00002000u                   /**< Mask for UsbDOEPMSKNAKMsk */
#define  USB_DOEPMSK_NAKMSK_BMASK                           0x1u                          /**< Base mask for UsbDOEPMSKNAKMsk */
#define  USB_DOEPMSK_NAKMSK(x)                              (((x)&0x1u)<<13)              /**< Set UsbDOEPMSKNAKMsk in register */
#define  GET_USB_DOEPMSK_NAKMSK(reg)                        (((reg)>>13)&0x1u)            /**< Get UsbDOEPMSKNAKMsk from register */
#define  USB_DOEPMSK_NYETMSK_SHIFT                          14                            /**< Shift for UsbDOEPMSKNYETMsk */
#define  USB_DOEPMSK_NYETMSK_MASK                           0x00004000u                   /**< Mask for UsbDOEPMSKNYETMsk */
#define  USB_DOEPMSK_NYETMSK_BMASK                          0x1u                          /**< Base mask for UsbDOEPMSKNYETMsk */
#define  USB_DOEPMSK_NYETMSK(x)                             (((x)&0x1u)<<14)              /**< Set UsbDOEPMSKNYETMsk in register */
#define  GET_USB_DOEPMSK_NYETMSK(reg)                       (((reg)>>14)&0x1u)            /**< Get UsbDOEPMSKNYETMsk from register */
/** @} */


/**
 * @name RegUsbDAINT
 * @{
 */
// RegUsbDAINT.r32
#define  REG_USB_DAINT_RESET_VALUE                          0x00000000u                   /**< Reset value of RegUsbDAINT */
#define  REG_USB_DAINT_MASK                                 0x000F000Fu                   /**< Mask for RegUsbDAINT */

#define  USB_DAINT_IN_EP_INT0_SHIFT                         0                             /**< Shift for UsbDAINTInEpInt0 */
#define  USB_DAINT_IN_EP_INT0_MASK                          0x00000001u                   /**< Mask for UsbDAINTInEpInt0 */
#define  USB_DAINT_IN_EP_INT0_BMASK                         0x1u                          /**< Base mask for UsbDAINTInEpInt0 */
#define  USB_DAINT_IN_EP_INT0(x)                            (((x)&0x1u)<<0)               /**< Set UsbDAINTInEpInt0 in register */
#define  GET_USB_DAINT_IN_EP_INT0(reg)                      (((reg)>>0)&0x1u)             /**< Get UsbDAINTInEpInt0 from register */
#define  USB_DAINT_IN_EP_INT1_SHIFT                         1                             /**< Shift for UsbDAINTInEpInt1 */
#define  USB_DAINT_IN_EP_INT1_MASK                          0x00000002u                   /**< Mask for UsbDAINTInEpInt1 */
#define  USB_DAINT_IN_EP_INT1_BMASK                         0x1u                          /**< Base mask for UsbDAINTInEpInt1 */
#define  USB_DAINT_IN_EP_INT1(x)                            (((x)&0x1u)<<1)               /**< Set UsbDAINTInEpInt1 in register */
#define  GET_USB_DAINT_IN_EP_INT1(reg)                      (((reg)>>1)&0x1u)             /**< Get UsbDAINTInEpInt1 from register */
#define  USB_DAINT_IN_EP_INT2_SHIFT                         2                             /**< Shift for UsbDAINTInEpInt2 */
#define  USB_DAINT_IN_EP_INT2_MASK                          0x00000004u                   /**< Mask for UsbDAINTInEpInt2 */
#define  USB_DAINT_IN_EP_INT2_BMASK                         0x1u                          /**< Base mask for UsbDAINTInEpInt2 */
#define  USB_DAINT_IN_EP_INT2(x)                            (((x)&0x1u)<<2)               /**< Set UsbDAINTInEpInt2 in register */
#define  GET_USB_DAINT_IN_EP_INT2(reg)                      (((reg)>>2)&0x1u)             /**< Get UsbDAINTInEpInt2 from register */
#define  USB_DAINT_IN_EP_INT3_SHIFT                         3                             /**< Shift for UsbDAINTInEpInt3 */
#define  USB_DAINT_IN_EP_INT3_MASK                          0x00000008u                   /**< Mask for UsbDAINTInEpInt3 */
#define  USB_DAINT_IN_EP_INT3_BMASK                         0x1u                          /**< Base mask for UsbDAINTInEpInt3 */
#define  USB_DAINT_IN_EP_INT3(x)                            (((x)&0x1u)<<3)               /**< Set UsbDAINTInEpInt3 in register */
#define  GET_USB_DAINT_IN_EP_INT3(reg)                      (((reg)>>3)&0x1u)             /**< Get UsbDAINTInEpInt3 from register */
#define  USB_DAINT_OUT_EPINT0_SHIFT                         16                            /**< Shift for UsbDAINTOutEPInt0 */
#define  USB_DAINT_OUT_EPINT0_MASK                          0x00010000u                   /**< Mask for UsbDAINTOutEPInt0 */
#define  USB_DAINT_OUT_EPINT0_BMASK                         0x1u                          /**< Base mask for UsbDAINTOutEPInt0 */
#define  USB_DAINT_OUT_EPINT0(x)                            (((x)&0x1u)<<16)              /**< Set UsbDAINTOutEPInt0 in register */
#define  GET_USB_DAINT_OUT_EPINT0(reg)                      (((reg)>>16)&0x1u)            /**< Get UsbDAINTOutEPInt0 from register */
#define  USB_DAINT_OUT_EPINT1_SHIFT                         17                            /**< Shift for UsbDAINTOutEPInt1 */
#define  USB_DAINT_OUT_EPINT1_MASK                          0x00020000u                   /**< Mask for UsbDAINTOutEPInt1 */
#define  USB_DAINT_OUT_EPINT1_BMASK                         0x1u                          /**< Base mask for UsbDAINTOutEPInt1 */
#define  USB_DAINT_OUT_EPINT1(x)                            (((x)&0x1u)<<17)              /**< Set UsbDAINTOutEPInt1 in register */
#define  GET_USB_DAINT_OUT_EPINT1(reg)                      (((reg)>>17)&0x1u)            /**< Get UsbDAINTOutEPInt1 from register */
#define  USB_DAINT_OUT_EPINT2_SHIFT                         18                            /**< Shift for UsbDAINTOutEPInt2 */
#define  USB_DAINT_OUT_EPINT2_MASK                          0x00040000u                   /**< Mask for UsbDAINTOutEPInt2 */
#define  USB_DAINT_OUT_EPINT2_BMASK                         0x1u                          /**< Base mask for UsbDAINTOutEPInt2 */
#define  USB_DAINT_OUT_EPINT2(x)                            (((x)&0x1u)<<18)              /**< Set UsbDAINTOutEPInt2 in register */
#define  GET_USB_DAINT_OUT_EPINT2(reg)                      (((reg)>>18)&0x1u)            /**< Get UsbDAINTOutEPInt2 from register */
#define  USB_DAINT_OUT_EPINT3_SHIFT                         19                            /**< Shift for UsbDAINTOutEPInt3 */
#define  USB_DAINT_OUT_EPINT3_MASK                          0x00080000u                   /**< Mask for UsbDAINTOutEPInt3 */
#define  USB_DAINT_OUT_EPINT3_BMASK                         0x1u                          /**< Base mask for UsbDAINTOutEPInt3 */
#define  USB_DAINT_OUT_EPINT3(x)                            (((x)&0x1u)<<19)              /**< Set UsbDAINTOutEPInt3 in register */
#define  GET_USB_DAINT_OUT_EPINT3(reg)                      (((reg)>>19)&0x1u)            /**< Get UsbDAINTOutEPInt3 from register */
/** @} */


/**
 * @name RegUsbDAINTMSK
 * @{
 */
// RegUsbDAINTMSK.r32
#define  REG_USB_DAINTMSK_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDAINTMSK */
#define  REG_USB_DAINTMSK_MASK                              0x000F000Fu                   /**< Mask for RegUsbDAINTMSK */

#define  USB_DAINTMSK_IN_EP_MSK0_SHIFT                      0                             /**< Shift for UsbDAINTMSKInEpMsk0 */
#define  USB_DAINTMSK_IN_EP_MSK0_MASK                       0x00000001u                   /**< Mask for UsbDAINTMSKInEpMsk0 */
#define  USB_DAINTMSK_IN_EP_MSK0_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKInEpMsk0 */
#define  USB_DAINTMSK_IN_EP_MSK0(x)                         (((x)&0x1u)<<0)               /**< Set UsbDAINTMSKInEpMsk0 in register */
#define  GET_USB_DAINTMSK_IN_EP_MSK0(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDAINTMSKInEpMsk0 from register */
#define  USB_DAINTMSK_IN_EP_MSK1_SHIFT                      1                             /**< Shift for UsbDAINTMSKInEpMsk1 */
#define  USB_DAINTMSK_IN_EP_MSK1_MASK                       0x00000002u                   /**< Mask for UsbDAINTMSKInEpMsk1 */
#define  USB_DAINTMSK_IN_EP_MSK1_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKInEpMsk1 */
#define  USB_DAINTMSK_IN_EP_MSK1(x)                         (((x)&0x1u)<<1)               /**< Set UsbDAINTMSKInEpMsk1 in register */
#define  GET_USB_DAINTMSK_IN_EP_MSK1(reg)                   (((reg)>>1)&0x1u)             /**< Get UsbDAINTMSKInEpMsk1 from register */
#define  USB_DAINTMSK_IN_EP_MSK2_SHIFT                      2                             /**< Shift for UsbDAINTMSKInEpMsk2 */
#define  USB_DAINTMSK_IN_EP_MSK2_MASK                       0x00000004u                   /**< Mask for UsbDAINTMSKInEpMsk2 */
#define  USB_DAINTMSK_IN_EP_MSK2_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKInEpMsk2 */
#define  USB_DAINTMSK_IN_EP_MSK2(x)                         (((x)&0x1u)<<2)               /**< Set UsbDAINTMSKInEpMsk2 in register */
#define  GET_USB_DAINTMSK_IN_EP_MSK2(reg)                   (((reg)>>2)&0x1u)             /**< Get UsbDAINTMSKInEpMsk2 from register */
#define  USB_DAINTMSK_IN_EP_MSK3_SHIFT                      3                             /**< Shift for UsbDAINTMSKInEpMsk3 */
#define  USB_DAINTMSK_IN_EP_MSK3_MASK                       0x00000008u                   /**< Mask for UsbDAINTMSKInEpMsk3 */
#define  USB_DAINTMSK_IN_EP_MSK3_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKInEpMsk3 */
#define  USB_DAINTMSK_IN_EP_MSK3(x)                         (((x)&0x1u)<<3)               /**< Set UsbDAINTMSKInEpMsk3 in register */
#define  GET_USB_DAINTMSK_IN_EP_MSK3(reg)                   (((reg)>>3)&0x1u)             /**< Get UsbDAINTMSKInEpMsk3 from register */
#define  USB_DAINTMSK_OUT_EPMSK0_SHIFT                      16                            /**< Shift for UsbDAINTMSKOutEPMsk0 */
#define  USB_DAINTMSK_OUT_EPMSK0_MASK                       0x00010000u                   /**< Mask for UsbDAINTMSKOutEPMsk0 */
#define  USB_DAINTMSK_OUT_EPMSK0_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKOutEPMsk0 */
#define  USB_DAINTMSK_OUT_EPMSK0(x)                         (((x)&0x1u)<<16)              /**< Set UsbDAINTMSKOutEPMsk0 in register */
#define  GET_USB_DAINTMSK_OUT_EPMSK0(reg)                   (((reg)>>16)&0x1u)            /**< Get UsbDAINTMSKOutEPMsk0 from register */
#define  USB_DAINTMSK_OUT_EPMSK1_SHIFT                      17                            /**< Shift for UsbDAINTMSKOutEPMsk1 */
#define  USB_DAINTMSK_OUT_EPMSK1_MASK                       0x00020000u                   /**< Mask for UsbDAINTMSKOutEPMsk1 */
#define  USB_DAINTMSK_OUT_EPMSK1_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKOutEPMsk1 */
#define  USB_DAINTMSK_OUT_EPMSK1(x)                         (((x)&0x1u)<<17)              /**< Set UsbDAINTMSKOutEPMsk1 in register */
#define  GET_USB_DAINTMSK_OUT_EPMSK1(reg)                   (((reg)>>17)&0x1u)            /**< Get UsbDAINTMSKOutEPMsk1 from register */
#define  USB_DAINTMSK_OUT_EPMSK2_SHIFT                      18                            /**< Shift for UsbDAINTMSKOutEPMsk2 */
#define  USB_DAINTMSK_OUT_EPMSK2_MASK                       0x00040000u                   /**< Mask for UsbDAINTMSKOutEPMsk2 */
#define  USB_DAINTMSK_OUT_EPMSK2_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKOutEPMsk2 */
#define  USB_DAINTMSK_OUT_EPMSK2(x)                         (((x)&0x1u)<<18)              /**< Set UsbDAINTMSKOutEPMsk2 in register */
#define  GET_USB_DAINTMSK_OUT_EPMSK2(reg)                   (((reg)>>18)&0x1u)            /**< Get UsbDAINTMSKOutEPMsk2 from register */
#define  USB_DAINTMSK_OUT_EPMSK3_SHIFT                      19                            /**< Shift for UsbDAINTMSKOutEPMsk3 */
#define  USB_DAINTMSK_OUT_EPMSK3_MASK                       0x00080000u                   /**< Mask for UsbDAINTMSKOutEPMsk3 */
#define  USB_DAINTMSK_OUT_EPMSK3_BMASK                      0x1u                          /**< Base mask for UsbDAINTMSKOutEPMsk3 */
#define  USB_DAINTMSK_OUT_EPMSK3(x)                         (((x)&0x1u)<<19)              /**< Set UsbDAINTMSKOutEPMsk3 in register */
#define  GET_USB_DAINTMSK_OUT_EPMSK3(reg)                   (((reg)>>19)&0x1u)            /**< Get UsbDAINTMSKOutEPMsk3 from register */
/** @} */


/**
 * @name RegUsbDTKNQR1
 * @{
 */
// RegUsbDTKNQR1.r32
#define  REG_USB_DTKNQR1_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDTKNQR1 */
#define  REG_USB_DTKNQR1_MASK                               0xFFFFFF9Fu                   /**< Mask for RegUsbDTKNQR1 */

#define  USB_DTKNQR1_INTKN_WPTR_SHIFT                       0                             /**< Shift for UsbDTKNQR1INTknWPtr */
#define  USB_DTKNQR1_INTKN_WPTR_MASK                        0x0000001Fu                   /**< Mask for UsbDTKNQR1INTknWPtr */
#define  USB_DTKNQR1_INTKN_WPTR_BMASK                       0x1Fu                         /**< Base mask for UsbDTKNQR1INTknWPtr */
#define  USB_DTKNQR1_INTKN_WPTR(x)                          (((x)&0x1Fu)<<0)              /**< Set UsbDTKNQR1INTknWPtr in register */
#define  GET_USB_DTKNQR1_INTKN_WPTR(reg)                    (((reg)>>0)&0x1Fu)            /**< Get UsbDTKNQR1INTknWPtr from register */
#define  USB_DTKNQR1_WRAP_BIT_SHIFT                         7                             /**< Shift for UsbDTKNQR1WrapBit */
#define  USB_DTKNQR1_WRAP_BIT_MASK                          0x00000080u                   /**< Mask for UsbDTKNQR1WrapBit */
#define  USB_DTKNQR1_WRAP_BIT_BMASK                         0x1u                          /**< Base mask for UsbDTKNQR1WrapBit */
#define  USB_DTKNQR1_WRAP_BIT(x)                            (((x)&0x1u)<<7)               /**< Set UsbDTKNQR1WrapBit in register */
#define  GET_USB_DTKNQR1_WRAP_BIT(reg)                      (((reg)>>7)&0x1u)             /**< Get UsbDTKNQR1WrapBit from register */
#define  USB_DTKNQR1_EPTKN_SHIFT                            8                             /**< Shift for UsbDTKNQR1EPTkn */
#define  USB_DTKNQR1_EPTKN_MASK                             0xFFFFFF00u                   /**< Mask for UsbDTKNQR1EPTkn */
#define  USB_DTKNQR1_EPTKN_BMASK                            0xFFFFFFu                     /**< Base mask for UsbDTKNQR1EPTkn */
#define  USB_DTKNQR1_EPTKN(x)                               (((x)&0xFFFFFFu)<<8)          /**< Set UsbDTKNQR1EPTkn in register */
#define  GET_USB_DTKNQR1_EPTKN(reg)                         (((reg)>>8)&0xFFFFFFu)        /**< Get UsbDTKNQR1EPTkn from register */
/** @} */


/**
 * @name RegUsbDTKNQR2
 * @{
 */
// RegUsbDTKNQR2.r32
#define  REG_USB_DTKNQR2_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDTKNQR2 */
#define  REG_USB_DTKNQR2_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDTKNQR2 */

#define  USB_DTKNQR2_EPTKN_SHIFT                            0                             /**< Shift for UsbDTKNQR2EPTkn */
#define  USB_DTKNQR2_EPTKN_MASK                             0xFFFFFFFFu                   /**< Mask for UsbDTKNQR2EPTkn */
#define  USB_DTKNQR2_EPTKN_BMASK                            0xFFFFFFFFu                   /**< Base mask for UsbDTKNQR2EPTkn */
#define  USB_DTKNQR2_EPTKN(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbDTKNQR2EPTkn in register */
#define  GET_USB_DTKNQR2_EPTKN(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbDTKNQR2EPTkn from register */
/** @} */


/**
 * @name RegUsbDVBUSDIS
 * @{
 */
// RegUsbDVBUSDIS.r32
#define  REG_USB_DVBUSDIS_RESET_VALUE                       0x000017D7u                   /**< Reset value of RegUsbDVBUSDIS */
#define  REG_USB_DVBUSDIS_MASK                              0x0000FFFFu                   /**< Mask for RegUsbDVBUSDIS */

#define  USB_DVBUSDIS_DVBUSDIS_SHIFT                        0                             /**< Shift for UsbDVBUSDISDVBUSDis */
#define  USB_DVBUSDIS_DVBUSDIS_MASK                         0x0000FFFFu                   /**< Mask for UsbDVBUSDISDVBUSDis */
#define  USB_DVBUSDIS_DVBUSDIS_BMASK                        0xFFFFu                       /**< Base mask for UsbDVBUSDISDVBUSDis */
#define  USB_DVBUSDIS_DVBUSDIS(x)                           (((x)&0xFFFFu)<<0)            /**< Set UsbDVBUSDISDVBUSDis in register */
#define  GET_USB_DVBUSDIS_DVBUSDIS(reg)                     (((reg)>>0)&0xFFFFu)          /**< Get UsbDVBUSDISDVBUSDis from register */
/** @} */


/**
 * @name RegUsbDVBUSPULSE
 * @{
 */
// RegUsbDVBUSPULSE.r32
#define  REG_USB_DVBUSPULSE_RESET_VALUE                     0x000005B8u                   /**< Reset value of RegUsbDVBUSPULSE */
#define  REG_USB_DVBUSPULSE_MASK                            0x00000FFFu                   /**< Mask for RegUsbDVBUSPULSE */

#define  USB_DVBUSPULSE_DVBUSPULSE_SHIFT                    0                             /**< Shift for UsbDVBUSPULSEDVBUSPulse */
#define  USB_DVBUSPULSE_DVBUSPULSE_MASK                     0x00000FFFu                   /**< Mask for UsbDVBUSPULSEDVBUSPulse */
#define  USB_DVBUSPULSE_DVBUSPULSE_BMASK                    0xFFFu                        /**< Base mask for UsbDVBUSPULSEDVBUSPulse */
#define  USB_DVBUSPULSE_DVBUSPULSE(x)                       (((x)&0xFFFu)<<0)             /**< Set UsbDVBUSPULSEDVBUSPulse in register */
#define  GET_USB_DVBUSPULSE_DVBUSPULSE(reg)                 (((reg)>>0)&0xFFFu)           /**< Get UsbDVBUSPULSEDVBUSPulse from register */
/** @} */


/**
 * @name RegUsbDTKNQR3
 * @{
 */
// RegUsbDTKNQR3.r32
#define  REG_USB_DTKNQR3_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDTKNQR3 */
#define  REG_USB_DTKNQR3_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDTKNQR3 */

#define  USB_DTKNQR3_EPTKN_SHIFT                            0                             /**< Shift for UsbDTKNQR3EPTkn */
#define  USB_DTKNQR3_EPTKN_MASK                             0xFFFFFFFFu                   /**< Mask for UsbDTKNQR3EPTkn */
#define  USB_DTKNQR3_EPTKN_BMASK                            0xFFFFFFFFu                   /**< Base mask for UsbDTKNQR3EPTkn */
#define  USB_DTKNQR3_EPTKN(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbDTKNQR3EPTkn in register */
#define  GET_USB_DTKNQR3_EPTKN(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbDTKNQR3EPTkn from register */
/** @} */


/**
 * @name RegUsbDTKNQR4
 * @{
 */
// RegUsbDTKNQR4.r32
#define  REG_USB_DTKNQR4_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDTKNQR4 */
#define  REG_USB_DTKNQR4_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDTKNQR4 */

#define  USB_DTKNQR4_EPTKN_SHIFT                            0                             /**< Shift for UsbDTKNQR4EPTkn */
#define  USB_DTKNQR4_EPTKN_MASK                             0xFFFFFFFFu                   /**< Mask for UsbDTKNQR4EPTkn */
#define  USB_DTKNQR4_EPTKN_BMASK                            0xFFFFFFFFu                   /**< Base mask for UsbDTKNQR4EPTkn */
#define  USB_DTKNQR4_EPTKN(x)                               (((x)&0xFFFFFFFFu)<<0)        /**< Set UsbDTKNQR4EPTkn in register */
#define  GET_USB_DTKNQR4_EPTKN(reg)                         (((reg)>>0)&0xFFFFFFFFu)      /**< Get UsbDTKNQR4EPTkn from register */
/** @} */


/**
 * @name RegUsbDEACHINT
 * @{
 */
// RegUsbDEACHINT.r32
#define  REG_USB_DEACHINT_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDEACHINT */
#define  REG_USB_DEACHINT_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDEACHINT */

#define  USB_DEACHINT_ECH_IN_EP_INT_SHIFT                   0                             /**< Shift for UsbDEACHINTEchInEpInt */
#define  USB_DEACHINT_ECH_IN_EP_INT_MASK                    0x0000FFFFu                   /**< Mask for UsbDEACHINTEchInEpInt */
#define  USB_DEACHINT_ECH_IN_EP_INT_BMASK                   0xFFFFu                       /**< Base mask for UsbDEACHINTEchInEpInt */
#define  USB_DEACHINT_ECH_IN_EP_INT(x)                      (((x)&0xFFFFu)<<0)            /**< Set UsbDEACHINTEchInEpInt in register */
#define  GET_USB_DEACHINT_ECH_IN_EP_INT(reg)                (((reg)>>0)&0xFFFFu)          /**< Get UsbDEACHINTEchInEpInt from register */
#define  USB_DEACHINT_ECH_OUT_EPINT_SHIFT                   16                            /**< Shift for UsbDEACHINTEchOutEPInt */
#define  USB_DEACHINT_ECH_OUT_EPINT_MASK                    0xFFFF0000u                   /**< Mask for UsbDEACHINTEchOutEPInt */
#define  USB_DEACHINT_ECH_OUT_EPINT_BMASK                   0xFFFFu                       /**< Base mask for UsbDEACHINTEchOutEPInt */
#define  USB_DEACHINT_ECH_OUT_EPINT(x)                      (((x)&0xFFFFu)<<16)           /**< Set UsbDEACHINTEchOutEPInt in register */
#define  GET_USB_DEACHINT_ECH_OUT_EPINT(reg)                (((reg)>>16)&0xFFFFu)         /**< Get UsbDEACHINTEchOutEPInt from register */
/** @} */


/**
 * @name RegUsbDEACHINTMSK
 * @{
 */
// RegUsbDEACHINTMSK.r32
#define  REG_USB_DEACHINTMSK_RESET_VALUE                    0x00000000u                   /**< Reset value of RegUsbDEACHINTMSK */
#define  REG_USB_DEACHINTMSK_MASK                           0x000F000Fu                   /**< Mask for RegUsbDEACHINTMSK */

#define  USB_DEACHINTMSK_ECH_IN_EP_MSK0_SHIFT               0                             /**< Shift for UsbDEACHINTMSKEchInEpMsk0 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK0_MASK                0x00000001u                   /**< Mask for UsbDEACHINTMSKEchInEpMsk0 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK0_BMASK               0x1u                          /**< Base mask for UsbDEACHINTMSKEchInEpMsk0 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK0(x)                  (((x)&0x1u)<<0)               /**< Set UsbDEACHINTMSKEchInEpMsk0 in register */
#define  GET_USB_DEACHINTMSK_ECH_IN_EP_MSK0(reg)            (((reg)>>0)&0x1u)             /**< Get UsbDEACHINTMSKEchInEpMsk0 from register */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK1_SHIFT               1                             /**< Shift for UsbDEACHINTMSKEchInEpMsk1 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK1_MASK                0x00000002u                   /**< Mask for UsbDEACHINTMSKEchInEpMsk1 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK1_BMASK               0x1u                          /**< Base mask for UsbDEACHINTMSKEchInEpMsk1 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK1(x)                  (((x)&0x1u)<<1)               /**< Set UsbDEACHINTMSKEchInEpMsk1 in register */
#define  GET_USB_DEACHINTMSK_ECH_IN_EP_MSK1(reg)            (((reg)>>1)&0x1u)             /**< Get UsbDEACHINTMSKEchInEpMsk1 from register */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK2_SHIFT               2                             /**< Shift for UsbDEACHINTMSKEchInEpMsk2 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK2_MASK                0x00000004u                   /**< Mask for UsbDEACHINTMSKEchInEpMsk2 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK2_BMASK               0x1u                          /**< Base mask for UsbDEACHINTMSKEchInEpMsk2 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK2(x)                  (((x)&0x1u)<<2)               /**< Set UsbDEACHINTMSKEchInEpMsk2 in register */
#define  GET_USB_DEACHINTMSK_ECH_IN_EP_MSK2(reg)            (((reg)>>2)&0x1u)             /**< Get UsbDEACHINTMSKEchInEpMsk2 from register */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK3_SHIFT               3                             /**< Shift for UsbDEACHINTMSKEchInEpMsk3 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK3_MASK                0x00000008u                   /**< Mask for UsbDEACHINTMSKEchInEpMsk3 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK3_BMASK               0x1u                          /**< Base mask for UsbDEACHINTMSKEchInEpMsk3 */
#define  USB_DEACHINTMSK_ECH_IN_EP_MSK3(x)                  (((x)&0x1u)<<3)               /**< Set UsbDEACHINTMSKEchInEpMsk3 in register */
#define  GET_USB_DEACHINTMSK_ECH_IN_EP_MSK3(reg)            (((reg)>>3)&0x1u)             /**< Get UsbDEACHINTMSKEchInEpMsk3 from register */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK0_SHIFT              16                            /**< Shift for UsbDEACHINTMSKEchOutEpMsk0 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK0_MASK               0x00010000u                   /**< Mask for UsbDEACHINTMSKEchOutEpMsk0 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK0_BMASK              0x1u                          /**< Base mask for UsbDEACHINTMSKEchOutEpMsk0 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK0(x)                 (((x)&0x1u)<<16)              /**< Set UsbDEACHINTMSKEchOutEpMsk0 in register */
#define  GET_USB_DEACHINTMSK_ECH_OUT_EP_MSK0(reg)           (((reg)>>16)&0x1u)            /**< Get UsbDEACHINTMSKEchOutEpMsk0 from register */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK1_SHIFT              17                            /**< Shift for UsbDEACHINTMSKEchOutEpMsk1 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK1_MASK               0x00020000u                   /**< Mask for UsbDEACHINTMSKEchOutEpMsk1 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK1_BMASK              0x1u                          /**< Base mask for UsbDEACHINTMSKEchOutEpMsk1 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK1(x)                 (((x)&0x1u)<<17)              /**< Set UsbDEACHINTMSKEchOutEpMsk1 in register */
#define  GET_USB_DEACHINTMSK_ECH_OUT_EP_MSK1(reg)           (((reg)>>17)&0x1u)            /**< Get UsbDEACHINTMSKEchOutEpMsk1 from register */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK2_SHIFT              18                            /**< Shift for UsbDEACHINTMSKEchOutEpMsk2 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK2_MASK               0x00040000u                   /**< Mask for UsbDEACHINTMSKEchOutEpMsk2 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK2_BMASK              0x1u                          /**< Base mask for UsbDEACHINTMSKEchOutEpMsk2 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK2(x)                 (((x)&0x1u)<<18)              /**< Set UsbDEACHINTMSKEchOutEpMsk2 in register */
#define  GET_USB_DEACHINTMSK_ECH_OUT_EP_MSK2(reg)           (((reg)>>18)&0x1u)            /**< Get UsbDEACHINTMSKEchOutEpMsk2 from register */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK3_SHIFT              19                            /**< Shift for UsbDEACHINTMSKEchOutEpMsk3 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK3_MASK               0x00080000u                   /**< Mask for UsbDEACHINTMSKEchOutEpMsk3 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK3_BMASK              0x1u                          /**< Base mask for UsbDEACHINTMSKEchOutEpMsk3 */
#define  USB_DEACHINTMSK_ECH_OUT_EP_MSK3(x)                 (((x)&0x1u)<<19)              /**< Set UsbDEACHINTMSKEchOutEpMsk3 in register */
#define  GET_USB_DEACHINTMSK_ECH_OUT_EP_MSK3(reg)           (((reg)>>19)&0x1u)            /**< Get UsbDEACHINTMSKEchOutEpMsk3 from register */
/** @} */


/**
 * @name RegUsbDIEPEACHMSK0
 * @{
 */
// RegUsbDIEPEACHMSK0.r32
#define  REG_USB_DIEPEACHMSK0_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDIEPEACHMSK0 */
#define  REG_USB_DIEPEACHMSK0_MASK                          0x0000217Bu                   /**< Mask for RegUsbDIEPEACHMSK0 */

#define  USB_DIEPEACHMSK0_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDIEPEACHMSK0XferComplMsk */
#define  USB_DIEPEACHMSK0_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDIEPEACHMSK0XferComplMsk */
#define  USB_DIEPEACHMSK0_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDIEPEACHMSK0XferComplMsk */
#define  USB_DIEPEACHMSK0_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDIEPEACHMSK0XferComplMsk in register */
#define  GET_USB_DIEPEACHMSK0_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDIEPEACHMSK0XferComplMsk from register */
#define  USB_DIEPEACHMSK0_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDIEPEACHMSK0EPDisbldMsk */
#define  USB_DIEPEACHMSK0_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDIEPEACHMSK0EPDisbldMsk */
#define  USB_DIEPEACHMSK0_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDIEPEACHMSK0EPDisbldMsk */
#define  USB_DIEPEACHMSK0_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDIEPEACHMSK0EPDisbldMsk in register */
#define  GET_USB_DIEPEACHMSK0_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDIEPEACHMSK0EPDisbldMsk from register */
#define  USB_DIEPEACHMSK0_TIME_OUTMSK_SHIFT                 3                             /**< Shift for UsbDIEPEACHMSK0TimeOUTMsk */
#define  USB_DIEPEACHMSK0_TIME_OUTMSK_MASK                  0x00000008u                   /**< Mask for UsbDIEPEACHMSK0TimeOUTMsk */
#define  USB_DIEPEACHMSK0_TIME_OUTMSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPEACHMSK0TimeOUTMsk */
#define  USB_DIEPEACHMSK0_TIME_OUTMSK(x)                    (((x)&0x1u)<<3)               /**< Set UsbDIEPEACHMSK0TimeOUTMsk in register */
#define  GET_USB_DIEPEACHMSK0_TIME_OUTMSK(reg)              (((reg)>>3)&0x1u)             /**< Get UsbDIEPEACHMSK0TimeOUTMsk from register */
#define  USB_DIEPEACHMSK0_INTKN_TXFEMP_MSK_SHIFT            4                             /**< Shift for UsbDIEPEACHMSK0INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK0_INTKN_TXFEMP_MSK_MASK             0x00000010u                   /**< Mask for UsbDIEPEACHMSK0INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK0_INTKN_TXFEMP_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK0INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK0_INTKN_TXFEMP_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDIEPEACHMSK0INTknTXFEmpMsk in register */
#define  GET_USB_DIEPEACHMSK0_INTKN_TXFEMP_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDIEPEACHMSK0INTknTXFEmpMsk from register */
#define  USB_DIEPEACHMSK0_INTKN_EPMIS_MSK_SHIFT             5                             /**< Shift for UsbDIEPEACHMSK0INTknEPMisMsk */
#define  USB_DIEPEACHMSK0_INTKN_EPMIS_MSK_MASK              0x00000020u                   /**< Mask for UsbDIEPEACHMSK0INTknEPMisMsk */
#define  USB_DIEPEACHMSK0_INTKN_EPMIS_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK0INTknEPMisMsk */
#define  USB_DIEPEACHMSK0_INTKN_EPMIS_MSK(x)                (((x)&0x1u)<<5)               /**< Set UsbDIEPEACHMSK0INTknEPMisMsk in register */
#define  GET_USB_DIEPEACHMSK0_INTKN_EPMIS_MSK(reg)          (((reg)>>5)&0x1u)             /**< Get UsbDIEPEACHMSK0INTknEPMisMsk from register */
#define  USB_DIEPEACHMSK0_INEPNAK_EFF_MSK_SHIFT             6                             /**< Shift for UsbDIEPEACHMSK0INEPNakEffMsk */
#define  USB_DIEPEACHMSK0_INEPNAK_EFF_MSK_MASK              0x00000040u                   /**< Mask for UsbDIEPEACHMSK0INEPNakEffMsk */
#define  USB_DIEPEACHMSK0_INEPNAK_EFF_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK0INEPNakEffMsk */
#define  USB_DIEPEACHMSK0_INEPNAK_EFF_MSK(x)                (((x)&0x1u)<<6)               /**< Set UsbDIEPEACHMSK0INEPNakEffMsk in register */
#define  GET_USB_DIEPEACHMSK0_INEPNAK_EFF_MSK(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDIEPEACHMSK0INEPNakEffMsk from register */
#define  USB_DIEPEACHMSK0_TXFIFO_UNDRN_MSK_SHIFT            8                             /**< Shift for UsbDIEPEACHMSK0TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK0_TXFIFO_UNDRN_MSK_MASK             0x00000100u                   /**< Mask for UsbDIEPEACHMSK0TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK0_TXFIFO_UNDRN_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK0TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK0_TXFIFO_UNDRN_MSK(x)               (((x)&0x1u)<<8)               /**< Set UsbDIEPEACHMSK0TxfifoUndrnMsk in register */
#define  GET_USB_DIEPEACHMSK0_TXFIFO_UNDRN_MSK(reg)         (((reg)>>8)&0x1u)             /**< Get UsbDIEPEACHMSK0TxfifoUndrnMsk from register */
#define  USB_DIEPEACHMSK0_NAKMSK_SHIFT                      13                            /**< Shift for UsbDIEPEACHMSK0NAKMsk */
#define  USB_DIEPEACHMSK0_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDIEPEACHMSK0NAKMsk */
#define  USB_DIEPEACHMSK0_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDIEPEACHMSK0NAKMsk */
#define  USB_DIEPEACHMSK0_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDIEPEACHMSK0NAKMsk in register */
#define  GET_USB_DIEPEACHMSK0_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDIEPEACHMSK0NAKMsk from register */
/** @} */


/**
 * @name RegUsbDIEPEACHMSK1
 * @{
 */
// RegUsbDIEPEACHMSK1.r32
#define  REG_USB_DIEPEACHMSK1_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDIEPEACHMSK1 */
#define  REG_USB_DIEPEACHMSK1_MASK                          0x0000217Bu                   /**< Mask for RegUsbDIEPEACHMSK1 */

#define  USB_DIEPEACHMSK1_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDIEPEACHMSK1XferComplMsk */
#define  USB_DIEPEACHMSK1_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDIEPEACHMSK1XferComplMsk */
#define  USB_DIEPEACHMSK1_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDIEPEACHMSK1XferComplMsk */
#define  USB_DIEPEACHMSK1_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDIEPEACHMSK1XferComplMsk in register */
#define  GET_USB_DIEPEACHMSK1_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDIEPEACHMSK1XferComplMsk from register */
#define  USB_DIEPEACHMSK1_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDIEPEACHMSK1EPDisbldMsk */
#define  USB_DIEPEACHMSK1_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDIEPEACHMSK1EPDisbldMsk */
#define  USB_DIEPEACHMSK1_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDIEPEACHMSK1EPDisbldMsk */
#define  USB_DIEPEACHMSK1_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDIEPEACHMSK1EPDisbldMsk in register */
#define  GET_USB_DIEPEACHMSK1_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDIEPEACHMSK1EPDisbldMsk from register */
#define  USB_DIEPEACHMSK1_TIME_OUTMSK_SHIFT                 3                             /**< Shift for UsbDIEPEACHMSK1TimeOUTMsk */
#define  USB_DIEPEACHMSK1_TIME_OUTMSK_MASK                  0x00000008u                   /**< Mask for UsbDIEPEACHMSK1TimeOUTMsk */
#define  USB_DIEPEACHMSK1_TIME_OUTMSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPEACHMSK1TimeOUTMsk */
#define  USB_DIEPEACHMSK1_TIME_OUTMSK(x)                    (((x)&0x1u)<<3)               /**< Set UsbDIEPEACHMSK1TimeOUTMsk in register */
#define  GET_USB_DIEPEACHMSK1_TIME_OUTMSK(reg)              (((reg)>>3)&0x1u)             /**< Get UsbDIEPEACHMSK1TimeOUTMsk from register */
#define  USB_DIEPEACHMSK1_INTKN_TXFEMP_MSK_SHIFT            4                             /**< Shift for UsbDIEPEACHMSK1INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK1_INTKN_TXFEMP_MSK_MASK             0x00000010u                   /**< Mask for UsbDIEPEACHMSK1INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK1_INTKN_TXFEMP_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK1INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK1_INTKN_TXFEMP_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDIEPEACHMSK1INTknTXFEmpMsk in register */
#define  GET_USB_DIEPEACHMSK1_INTKN_TXFEMP_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDIEPEACHMSK1INTknTXFEmpMsk from register */
#define  USB_DIEPEACHMSK1_INTKN_EPMIS_MSK_SHIFT             5                             /**< Shift for UsbDIEPEACHMSK1INTknEPMisMsk */
#define  USB_DIEPEACHMSK1_INTKN_EPMIS_MSK_MASK              0x00000020u                   /**< Mask for UsbDIEPEACHMSK1INTknEPMisMsk */
#define  USB_DIEPEACHMSK1_INTKN_EPMIS_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK1INTknEPMisMsk */
#define  USB_DIEPEACHMSK1_INTKN_EPMIS_MSK(x)                (((x)&0x1u)<<5)               /**< Set UsbDIEPEACHMSK1INTknEPMisMsk in register */
#define  GET_USB_DIEPEACHMSK1_INTKN_EPMIS_MSK(reg)          (((reg)>>5)&0x1u)             /**< Get UsbDIEPEACHMSK1INTknEPMisMsk from register */
#define  USB_DIEPEACHMSK1_INEPNAK_EFF_MSK_SHIFT             6                             /**< Shift for UsbDIEPEACHMSK1INEPNakEffMsk */
#define  USB_DIEPEACHMSK1_INEPNAK_EFF_MSK_MASK              0x00000040u                   /**< Mask for UsbDIEPEACHMSK1INEPNakEffMsk */
#define  USB_DIEPEACHMSK1_INEPNAK_EFF_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK1INEPNakEffMsk */
#define  USB_DIEPEACHMSK1_INEPNAK_EFF_MSK(x)                (((x)&0x1u)<<6)               /**< Set UsbDIEPEACHMSK1INEPNakEffMsk in register */
#define  GET_USB_DIEPEACHMSK1_INEPNAK_EFF_MSK(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDIEPEACHMSK1INEPNakEffMsk from register */
#define  USB_DIEPEACHMSK1_TXFIFO_UNDRN_MSK_SHIFT            8                             /**< Shift for UsbDIEPEACHMSK1TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK1_TXFIFO_UNDRN_MSK_MASK             0x00000100u                   /**< Mask for UsbDIEPEACHMSK1TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK1_TXFIFO_UNDRN_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK1TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK1_TXFIFO_UNDRN_MSK(x)               (((x)&0x1u)<<8)               /**< Set UsbDIEPEACHMSK1TxfifoUndrnMsk in register */
#define  GET_USB_DIEPEACHMSK1_TXFIFO_UNDRN_MSK(reg)         (((reg)>>8)&0x1u)             /**< Get UsbDIEPEACHMSK1TxfifoUndrnMsk from register */
#define  USB_DIEPEACHMSK1_NAKMSK_SHIFT                      13                            /**< Shift for UsbDIEPEACHMSK1NAKMsk */
#define  USB_DIEPEACHMSK1_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDIEPEACHMSK1NAKMsk */
#define  USB_DIEPEACHMSK1_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDIEPEACHMSK1NAKMsk */
#define  USB_DIEPEACHMSK1_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDIEPEACHMSK1NAKMsk in register */
#define  GET_USB_DIEPEACHMSK1_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDIEPEACHMSK1NAKMsk from register */
/** @} */


/**
 * @name RegUsbDIEPEACHMSK2
 * @{
 */
// RegUsbDIEPEACHMSK2.r32
#define  REG_USB_DIEPEACHMSK2_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDIEPEACHMSK2 */
#define  REG_USB_DIEPEACHMSK2_MASK                          0x0000217Bu                   /**< Mask for RegUsbDIEPEACHMSK2 */

#define  USB_DIEPEACHMSK2_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDIEPEACHMSK2XferComplMsk */
#define  USB_DIEPEACHMSK2_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDIEPEACHMSK2XferComplMsk */
#define  USB_DIEPEACHMSK2_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDIEPEACHMSK2XferComplMsk */
#define  USB_DIEPEACHMSK2_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDIEPEACHMSK2XferComplMsk in register */
#define  GET_USB_DIEPEACHMSK2_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDIEPEACHMSK2XferComplMsk from register */
#define  USB_DIEPEACHMSK2_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDIEPEACHMSK2EPDisbldMsk */
#define  USB_DIEPEACHMSK2_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDIEPEACHMSK2EPDisbldMsk */
#define  USB_DIEPEACHMSK2_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDIEPEACHMSK2EPDisbldMsk */
#define  USB_DIEPEACHMSK2_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDIEPEACHMSK2EPDisbldMsk in register */
#define  GET_USB_DIEPEACHMSK2_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDIEPEACHMSK2EPDisbldMsk from register */
#define  USB_DIEPEACHMSK2_TIME_OUTMSK_SHIFT                 3                             /**< Shift for UsbDIEPEACHMSK2TimeOUTMsk */
#define  USB_DIEPEACHMSK2_TIME_OUTMSK_MASK                  0x00000008u                   /**< Mask for UsbDIEPEACHMSK2TimeOUTMsk */
#define  USB_DIEPEACHMSK2_TIME_OUTMSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPEACHMSK2TimeOUTMsk */
#define  USB_DIEPEACHMSK2_TIME_OUTMSK(x)                    (((x)&0x1u)<<3)               /**< Set UsbDIEPEACHMSK2TimeOUTMsk in register */
#define  GET_USB_DIEPEACHMSK2_TIME_OUTMSK(reg)              (((reg)>>3)&0x1u)             /**< Get UsbDIEPEACHMSK2TimeOUTMsk from register */
#define  USB_DIEPEACHMSK2_INTKN_TXFEMP_MSK_SHIFT            4                             /**< Shift for UsbDIEPEACHMSK2INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK2_INTKN_TXFEMP_MSK_MASK             0x00000010u                   /**< Mask for UsbDIEPEACHMSK2INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK2_INTKN_TXFEMP_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK2INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK2_INTKN_TXFEMP_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDIEPEACHMSK2INTknTXFEmpMsk in register */
#define  GET_USB_DIEPEACHMSK2_INTKN_TXFEMP_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDIEPEACHMSK2INTknTXFEmpMsk from register */
#define  USB_DIEPEACHMSK2_INTKN_EPMIS_MSK_SHIFT             5                             /**< Shift for UsbDIEPEACHMSK2INTknEPMisMsk */
#define  USB_DIEPEACHMSK2_INTKN_EPMIS_MSK_MASK              0x00000020u                   /**< Mask for UsbDIEPEACHMSK2INTknEPMisMsk */
#define  USB_DIEPEACHMSK2_INTKN_EPMIS_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK2INTknEPMisMsk */
#define  USB_DIEPEACHMSK2_INTKN_EPMIS_MSK(x)                (((x)&0x1u)<<5)               /**< Set UsbDIEPEACHMSK2INTknEPMisMsk in register */
#define  GET_USB_DIEPEACHMSK2_INTKN_EPMIS_MSK(reg)          (((reg)>>5)&0x1u)             /**< Get UsbDIEPEACHMSK2INTknEPMisMsk from register */
#define  USB_DIEPEACHMSK2_INEPNAK_EFF_MSK_SHIFT             6                             /**< Shift for UsbDIEPEACHMSK2INEPNakEffMsk */
#define  USB_DIEPEACHMSK2_INEPNAK_EFF_MSK_MASK              0x00000040u                   /**< Mask for UsbDIEPEACHMSK2INEPNakEffMsk */
#define  USB_DIEPEACHMSK2_INEPNAK_EFF_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK2INEPNakEffMsk */
#define  USB_DIEPEACHMSK2_INEPNAK_EFF_MSK(x)                (((x)&0x1u)<<6)               /**< Set UsbDIEPEACHMSK2INEPNakEffMsk in register */
#define  GET_USB_DIEPEACHMSK2_INEPNAK_EFF_MSK(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDIEPEACHMSK2INEPNakEffMsk from register */
#define  USB_DIEPEACHMSK2_TXFIFO_UNDRN_MSK_SHIFT            8                             /**< Shift for UsbDIEPEACHMSK2TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK2_TXFIFO_UNDRN_MSK_MASK             0x00000100u                   /**< Mask for UsbDIEPEACHMSK2TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK2_TXFIFO_UNDRN_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK2TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK2_TXFIFO_UNDRN_MSK(x)               (((x)&0x1u)<<8)               /**< Set UsbDIEPEACHMSK2TxfifoUndrnMsk in register */
#define  GET_USB_DIEPEACHMSK2_TXFIFO_UNDRN_MSK(reg)         (((reg)>>8)&0x1u)             /**< Get UsbDIEPEACHMSK2TxfifoUndrnMsk from register */
#define  USB_DIEPEACHMSK2_NAKMSK_SHIFT                      13                            /**< Shift for UsbDIEPEACHMSK2NAKMsk */
#define  USB_DIEPEACHMSK2_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDIEPEACHMSK2NAKMsk */
#define  USB_DIEPEACHMSK2_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDIEPEACHMSK2NAKMsk */
#define  USB_DIEPEACHMSK2_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDIEPEACHMSK2NAKMsk in register */
#define  GET_USB_DIEPEACHMSK2_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDIEPEACHMSK2NAKMsk from register */
/** @} */


/**
 * @name RegUsbDIEPEACHMSK3
 * @{
 */
// RegUsbDIEPEACHMSK3.r32
#define  REG_USB_DIEPEACHMSK3_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDIEPEACHMSK3 */
#define  REG_USB_DIEPEACHMSK3_MASK                          0x0000217Bu                   /**< Mask for RegUsbDIEPEACHMSK3 */

#define  USB_DIEPEACHMSK3_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDIEPEACHMSK3XferComplMsk */
#define  USB_DIEPEACHMSK3_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDIEPEACHMSK3XferComplMsk */
#define  USB_DIEPEACHMSK3_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDIEPEACHMSK3XferComplMsk */
#define  USB_DIEPEACHMSK3_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDIEPEACHMSK3XferComplMsk in register */
#define  GET_USB_DIEPEACHMSK3_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDIEPEACHMSK3XferComplMsk from register */
#define  USB_DIEPEACHMSK3_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDIEPEACHMSK3EPDisbldMsk */
#define  USB_DIEPEACHMSK3_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDIEPEACHMSK3EPDisbldMsk */
#define  USB_DIEPEACHMSK3_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDIEPEACHMSK3EPDisbldMsk */
#define  USB_DIEPEACHMSK3_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDIEPEACHMSK3EPDisbldMsk in register */
#define  GET_USB_DIEPEACHMSK3_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDIEPEACHMSK3EPDisbldMsk from register */
#define  USB_DIEPEACHMSK3_TIME_OUTMSK_SHIFT                 3                             /**< Shift for UsbDIEPEACHMSK3TimeOUTMsk */
#define  USB_DIEPEACHMSK3_TIME_OUTMSK_MASK                  0x00000008u                   /**< Mask for UsbDIEPEACHMSK3TimeOUTMsk */
#define  USB_DIEPEACHMSK3_TIME_OUTMSK_BMASK                 0x1u                          /**< Base mask for UsbDIEPEACHMSK3TimeOUTMsk */
#define  USB_DIEPEACHMSK3_TIME_OUTMSK(x)                    (((x)&0x1u)<<3)               /**< Set UsbDIEPEACHMSK3TimeOUTMsk in register */
#define  GET_USB_DIEPEACHMSK3_TIME_OUTMSK(reg)              (((reg)>>3)&0x1u)             /**< Get UsbDIEPEACHMSK3TimeOUTMsk from register */
#define  USB_DIEPEACHMSK3_INTKN_TXFEMP_MSK_SHIFT            4                             /**< Shift for UsbDIEPEACHMSK3INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK3_INTKN_TXFEMP_MSK_MASK             0x00000010u                   /**< Mask for UsbDIEPEACHMSK3INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK3_INTKN_TXFEMP_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK3INTknTXFEmpMsk */
#define  USB_DIEPEACHMSK3_INTKN_TXFEMP_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDIEPEACHMSK3INTknTXFEmpMsk in register */
#define  GET_USB_DIEPEACHMSK3_INTKN_TXFEMP_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDIEPEACHMSK3INTknTXFEmpMsk from register */
#define  USB_DIEPEACHMSK3_INTKN_EPMIS_MSK_SHIFT             5                             /**< Shift for UsbDIEPEACHMSK3INTknEPMisMsk */
#define  USB_DIEPEACHMSK3_INTKN_EPMIS_MSK_MASK              0x00000020u                   /**< Mask for UsbDIEPEACHMSK3INTknEPMisMsk */
#define  USB_DIEPEACHMSK3_INTKN_EPMIS_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK3INTknEPMisMsk */
#define  USB_DIEPEACHMSK3_INTKN_EPMIS_MSK(x)                (((x)&0x1u)<<5)               /**< Set UsbDIEPEACHMSK3INTknEPMisMsk in register */
#define  GET_USB_DIEPEACHMSK3_INTKN_EPMIS_MSK(reg)          (((reg)>>5)&0x1u)             /**< Get UsbDIEPEACHMSK3INTknEPMisMsk from register */
#define  USB_DIEPEACHMSK3_INEPNAK_EFF_MSK_SHIFT             6                             /**< Shift for UsbDIEPEACHMSK3INEPNakEffMsk */
#define  USB_DIEPEACHMSK3_INEPNAK_EFF_MSK_MASK              0x00000040u                   /**< Mask for UsbDIEPEACHMSK3INEPNakEffMsk */
#define  USB_DIEPEACHMSK3_INEPNAK_EFF_MSK_BMASK             0x1u                          /**< Base mask for UsbDIEPEACHMSK3INEPNakEffMsk */
#define  USB_DIEPEACHMSK3_INEPNAK_EFF_MSK(x)                (((x)&0x1u)<<6)               /**< Set UsbDIEPEACHMSK3INEPNakEffMsk in register */
#define  GET_USB_DIEPEACHMSK3_INEPNAK_EFF_MSK(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDIEPEACHMSK3INEPNakEffMsk from register */
#define  USB_DIEPEACHMSK3_TXFIFO_UNDRN_MSK_SHIFT            8                             /**< Shift for UsbDIEPEACHMSK3TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK3_TXFIFO_UNDRN_MSK_MASK             0x00000100u                   /**< Mask for UsbDIEPEACHMSK3TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK3_TXFIFO_UNDRN_MSK_BMASK            0x1u                          /**< Base mask for UsbDIEPEACHMSK3TxfifoUndrnMsk */
#define  USB_DIEPEACHMSK3_TXFIFO_UNDRN_MSK(x)               (((x)&0x1u)<<8)               /**< Set UsbDIEPEACHMSK3TxfifoUndrnMsk in register */
#define  GET_USB_DIEPEACHMSK3_TXFIFO_UNDRN_MSK(reg)         (((reg)>>8)&0x1u)             /**< Get UsbDIEPEACHMSK3TxfifoUndrnMsk from register */
#define  USB_DIEPEACHMSK3_NAKMSK_SHIFT                      13                            /**< Shift for UsbDIEPEACHMSK3NAKMsk */
#define  USB_DIEPEACHMSK3_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDIEPEACHMSK3NAKMsk */
#define  USB_DIEPEACHMSK3_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDIEPEACHMSK3NAKMsk */
#define  USB_DIEPEACHMSK3_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDIEPEACHMSK3NAKMsk in register */
#define  GET_USB_DIEPEACHMSK3_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDIEPEACHMSK3NAKMsk from register */
/** @} */


/**
 * @name RegUsbDOEPEACHMSK0
 * @{
 */
// RegUsbDOEPEACHMSK0.r32
#define  REG_USB_DOEPEACHMSK0_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDOEPEACHMSK0 */
#define  REG_USB_DOEPEACHMSK0_MASK                          0x0000717Bu                   /**< Mask for RegUsbDOEPEACHMSK0 */

#define  USB_DOEPEACHMSK0_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDOEPEACHMSK0XferComplMsk */
#define  USB_DOEPEACHMSK0_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDOEPEACHMSK0XferComplMsk */
#define  USB_DOEPEACHMSK0_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDOEPEACHMSK0XferComplMsk */
#define  USB_DOEPEACHMSK0_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDOEPEACHMSK0XferComplMsk in register */
#define  GET_USB_DOEPEACHMSK0_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDOEPEACHMSK0XferComplMsk from register */
#define  USB_DOEPEACHMSK0_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDOEPEACHMSK0EPDisbldMsk */
#define  USB_DOEPEACHMSK0_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDOEPEACHMSK0EPDisbldMsk */
#define  USB_DOEPEACHMSK0_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK0EPDisbldMsk */
#define  USB_DOEPEACHMSK0_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDOEPEACHMSK0EPDisbldMsk in register */
#define  GET_USB_DOEPEACHMSK0_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDOEPEACHMSK0EPDisbldMsk from register */
#define  USB_DOEPEACHMSK0_SET_UPMSK_SHIFT                   3                             /**< Shift for UsbDOEPEACHMSK0SetUPMsk */
#define  USB_DOEPEACHMSK0_SET_UPMSK_MASK                    0x00000008u                   /**< Mask for UsbDOEPEACHMSK0SetUPMsk */
#define  USB_DOEPEACHMSK0_SET_UPMSK_BMASK                   0x1u                          /**< Base mask for UsbDOEPEACHMSK0SetUPMsk */
#define  USB_DOEPEACHMSK0_SET_UPMSK(x)                      (((x)&0x1u)<<3)               /**< Set UsbDOEPEACHMSK0SetUPMsk in register */
#define  GET_USB_DOEPEACHMSK0_SET_UPMSK(reg)                (((reg)>>3)&0x1u)             /**< Get UsbDOEPEACHMSK0SetUPMsk from register */
#define  USB_DOEPEACHMSK0_OUTTKN_EPDIS_MSK_SHIFT            4                             /**< Shift for UsbDOEPEACHMSK0OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK0_OUTTKN_EPDIS_MSK_MASK             0x00000010u                   /**< Mask for UsbDOEPEACHMSK0OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK0_OUTTKN_EPDIS_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK0OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK0_OUTTKN_EPDIS_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDOEPEACHMSK0OUTTknEPdisMsk in register */
#define  GET_USB_DOEPEACHMSK0_OUTTKN_EPDIS_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDOEPEACHMSK0OUTTknEPdisMsk from register */
#define  USB_DOEPEACHMSK0_STS_PHS_RCVD_MSK_SHIFT            5                             /**< Shift for UsbDOEPEACHMSK0StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK0_STS_PHS_RCVD_MSK_MASK             0x00000020u                   /**< Mask for UsbDOEPEACHMSK0StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK0_STS_PHS_RCVD_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK0StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK0_STS_PHS_RCVD_MSK(x)               (((x)&0x1u)<<5)               /**< Set UsbDOEPEACHMSK0StsPhsRcvdMsk in register */
#define  GET_USB_DOEPEACHMSK0_STS_PHS_RCVD_MSK(reg)         (((reg)>>5)&0x1u)             /**< Get UsbDOEPEACHMSK0StsPhsRcvdMsk from register */
#define  USB_DOEPEACHMSK0_BACK2BACK_SETUP_SHIFT             6                             /**< Shift for UsbDOEPEACHMSK0Back2BackSETup */
#define  USB_DOEPEACHMSK0_BACK2BACK_SETUP_MASK              0x00000040u                   /**< Mask for UsbDOEPEACHMSK0Back2BackSETup */
#define  USB_DOEPEACHMSK0_BACK2BACK_SETUP_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK0Back2BackSETup */
#define  USB_DOEPEACHMSK0_BACK2BACK_SETUP(x)                (((x)&0x1u)<<6)               /**< Set UsbDOEPEACHMSK0Back2BackSETup in register */
#define  GET_USB_DOEPEACHMSK0_BACK2BACK_SETUP(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDOEPEACHMSK0Back2BackSETup from register */
#define  USB_DOEPEACHMSK0_OUT_PKT_ERR_MSK_SHIFT             8                             /**< Shift for UsbDOEPEACHMSK0OutPktErrMsk */
#define  USB_DOEPEACHMSK0_OUT_PKT_ERR_MSK_MASK              0x00000100u                   /**< Mask for UsbDOEPEACHMSK0OutPktErrMsk */
#define  USB_DOEPEACHMSK0_OUT_PKT_ERR_MSK_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK0OutPktErrMsk */
#define  USB_DOEPEACHMSK0_OUT_PKT_ERR_MSK(x)                (((x)&0x1u)<<8)               /**< Set UsbDOEPEACHMSK0OutPktErrMsk in register */
#define  GET_USB_DOEPEACHMSK0_OUT_PKT_ERR_MSK(reg)          (((reg)>>8)&0x1u)             /**< Get UsbDOEPEACHMSK0OutPktErrMsk from register */
#define  USB_DOEPEACHMSK0_BBLE_ERR_MSK_SHIFT                12                            /**< Shift for UsbDOEPEACHMSK0BbleErrMsk */
#define  USB_DOEPEACHMSK0_BBLE_ERR_MSK_MASK                 0x00001000u                   /**< Mask for UsbDOEPEACHMSK0BbleErrMsk */
#define  USB_DOEPEACHMSK0_BBLE_ERR_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK0BbleErrMsk */
#define  USB_DOEPEACHMSK0_BBLE_ERR_MSK(x)                   (((x)&0x1u)<<12)              /**< Set UsbDOEPEACHMSK0BbleErrMsk in register */
#define  GET_USB_DOEPEACHMSK0_BBLE_ERR_MSK(reg)             (((reg)>>12)&0x1u)            /**< Get UsbDOEPEACHMSK0BbleErrMsk from register */
#define  USB_DOEPEACHMSK0_NAKMSK_SHIFT                      13                            /**< Shift for UsbDOEPEACHMSK0NAKMsk */
#define  USB_DOEPEACHMSK0_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDOEPEACHMSK0NAKMsk */
#define  USB_DOEPEACHMSK0_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDOEPEACHMSK0NAKMsk */
#define  USB_DOEPEACHMSK0_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDOEPEACHMSK0NAKMsk in register */
#define  GET_USB_DOEPEACHMSK0_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDOEPEACHMSK0NAKMsk from register */
#define  USB_DOEPEACHMSK0_NYETMSK_SHIFT                     14                            /**< Shift for UsbDOEPEACHMSK0NYETMsk */
#define  USB_DOEPEACHMSK0_NYETMSK_MASK                      0x00004000u                   /**< Mask for UsbDOEPEACHMSK0NYETMsk */
#define  USB_DOEPEACHMSK0_NYETMSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPEACHMSK0NYETMsk */
#define  USB_DOEPEACHMSK0_NYETMSK(x)                        (((x)&0x1u)<<14)              /**< Set UsbDOEPEACHMSK0NYETMsk in register */
#define  GET_USB_DOEPEACHMSK0_NYETMSK(reg)                  (((reg)>>14)&0x1u)            /**< Get UsbDOEPEACHMSK0NYETMsk from register */
/** @} */


/**
 * @name RegUsbDOEPEACHMSK1
 * @{
 */
// RegUsbDOEPEACHMSK1.r32
#define  REG_USB_DOEPEACHMSK1_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDOEPEACHMSK1 */
#define  REG_USB_DOEPEACHMSK1_MASK                          0x0000717Bu                   /**< Mask for RegUsbDOEPEACHMSK1 */

#define  USB_DOEPEACHMSK1_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDOEPEACHMSK1XferComplMsk */
#define  USB_DOEPEACHMSK1_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDOEPEACHMSK1XferComplMsk */
#define  USB_DOEPEACHMSK1_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDOEPEACHMSK1XferComplMsk */
#define  USB_DOEPEACHMSK1_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDOEPEACHMSK1XferComplMsk in register */
#define  GET_USB_DOEPEACHMSK1_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDOEPEACHMSK1XferComplMsk from register */
#define  USB_DOEPEACHMSK1_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDOEPEACHMSK1EPDisbldMsk */
#define  USB_DOEPEACHMSK1_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDOEPEACHMSK1EPDisbldMsk */
#define  USB_DOEPEACHMSK1_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK1EPDisbldMsk */
#define  USB_DOEPEACHMSK1_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDOEPEACHMSK1EPDisbldMsk in register */
#define  GET_USB_DOEPEACHMSK1_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDOEPEACHMSK1EPDisbldMsk from register */
#define  USB_DOEPEACHMSK1_SET_UPMSK_SHIFT                   3                             /**< Shift for UsbDOEPEACHMSK1SetUPMsk */
#define  USB_DOEPEACHMSK1_SET_UPMSK_MASK                    0x00000008u                   /**< Mask for UsbDOEPEACHMSK1SetUPMsk */
#define  USB_DOEPEACHMSK1_SET_UPMSK_BMASK                   0x1u                          /**< Base mask for UsbDOEPEACHMSK1SetUPMsk */
#define  USB_DOEPEACHMSK1_SET_UPMSK(x)                      (((x)&0x1u)<<3)               /**< Set UsbDOEPEACHMSK1SetUPMsk in register */
#define  GET_USB_DOEPEACHMSK1_SET_UPMSK(reg)                (((reg)>>3)&0x1u)             /**< Get UsbDOEPEACHMSK1SetUPMsk from register */
#define  USB_DOEPEACHMSK1_OUTTKN_EPDIS_MSK_SHIFT            4                             /**< Shift for UsbDOEPEACHMSK1OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK1_OUTTKN_EPDIS_MSK_MASK             0x00000010u                   /**< Mask for UsbDOEPEACHMSK1OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK1_OUTTKN_EPDIS_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK1OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK1_OUTTKN_EPDIS_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDOEPEACHMSK1OUTTknEPdisMsk in register */
#define  GET_USB_DOEPEACHMSK1_OUTTKN_EPDIS_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDOEPEACHMSK1OUTTknEPdisMsk from register */
#define  USB_DOEPEACHMSK1_STS_PHS_RCVD_MSK_SHIFT            5                             /**< Shift for UsbDOEPEACHMSK1StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK1_STS_PHS_RCVD_MSK_MASK             0x00000020u                   /**< Mask for UsbDOEPEACHMSK1StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK1_STS_PHS_RCVD_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK1StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK1_STS_PHS_RCVD_MSK(x)               (((x)&0x1u)<<5)               /**< Set UsbDOEPEACHMSK1StsPhsRcvdMsk in register */
#define  GET_USB_DOEPEACHMSK1_STS_PHS_RCVD_MSK(reg)         (((reg)>>5)&0x1u)             /**< Get UsbDOEPEACHMSK1StsPhsRcvdMsk from register */
#define  USB_DOEPEACHMSK1_BACK2BACK_SETUP_SHIFT             6                             /**< Shift for UsbDOEPEACHMSK1Back2BackSETup */
#define  USB_DOEPEACHMSK1_BACK2BACK_SETUP_MASK              0x00000040u                   /**< Mask for UsbDOEPEACHMSK1Back2BackSETup */
#define  USB_DOEPEACHMSK1_BACK2BACK_SETUP_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK1Back2BackSETup */
#define  USB_DOEPEACHMSK1_BACK2BACK_SETUP(x)                (((x)&0x1u)<<6)               /**< Set UsbDOEPEACHMSK1Back2BackSETup in register */
#define  GET_USB_DOEPEACHMSK1_BACK2BACK_SETUP(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDOEPEACHMSK1Back2BackSETup from register */
#define  USB_DOEPEACHMSK1_OUT_PKT_ERR_MSK_SHIFT             8                             /**< Shift for UsbDOEPEACHMSK1OutPktErrMsk */
#define  USB_DOEPEACHMSK1_OUT_PKT_ERR_MSK_MASK              0x00000100u                   /**< Mask for UsbDOEPEACHMSK1OutPktErrMsk */
#define  USB_DOEPEACHMSK1_OUT_PKT_ERR_MSK_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK1OutPktErrMsk */
#define  USB_DOEPEACHMSK1_OUT_PKT_ERR_MSK(x)                (((x)&0x1u)<<8)               /**< Set UsbDOEPEACHMSK1OutPktErrMsk in register */
#define  GET_USB_DOEPEACHMSK1_OUT_PKT_ERR_MSK(reg)          (((reg)>>8)&0x1u)             /**< Get UsbDOEPEACHMSK1OutPktErrMsk from register */
#define  USB_DOEPEACHMSK1_BBLE_ERR_MSK_SHIFT                12                            /**< Shift for UsbDOEPEACHMSK1BbleErrMsk */
#define  USB_DOEPEACHMSK1_BBLE_ERR_MSK_MASK                 0x00001000u                   /**< Mask for UsbDOEPEACHMSK1BbleErrMsk */
#define  USB_DOEPEACHMSK1_BBLE_ERR_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK1BbleErrMsk */
#define  USB_DOEPEACHMSK1_BBLE_ERR_MSK(x)                   (((x)&0x1u)<<12)              /**< Set UsbDOEPEACHMSK1BbleErrMsk in register */
#define  GET_USB_DOEPEACHMSK1_BBLE_ERR_MSK(reg)             (((reg)>>12)&0x1u)            /**< Get UsbDOEPEACHMSK1BbleErrMsk from register */
#define  USB_DOEPEACHMSK1_NAKMSK_SHIFT                      13                            /**< Shift for UsbDOEPEACHMSK1NAKMsk */
#define  USB_DOEPEACHMSK1_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDOEPEACHMSK1NAKMsk */
#define  USB_DOEPEACHMSK1_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDOEPEACHMSK1NAKMsk */
#define  USB_DOEPEACHMSK1_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDOEPEACHMSK1NAKMsk in register */
#define  GET_USB_DOEPEACHMSK1_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDOEPEACHMSK1NAKMsk from register */
#define  USB_DOEPEACHMSK1_NYETMSK_SHIFT                     14                            /**< Shift for UsbDOEPEACHMSK1NYETMsk */
#define  USB_DOEPEACHMSK1_NYETMSK_MASK                      0x00004000u                   /**< Mask for UsbDOEPEACHMSK1NYETMsk */
#define  USB_DOEPEACHMSK1_NYETMSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPEACHMSK1NYETMsk */
#define  USB_DOEPEACHMSK1_NYETMSK(x)                        (((x)&0x1u)<<14)              /**< Set UsbDOEPEACHMSK1NYETMsk in register */
#define  GET_USB_DOEPEACHMSK1_NYETMSK(reg)                  (((reg)>>14)&0x1u)            /**< Get UsbDOEPEACHMSK1NYETMsk from register */
/** @} */


/**
 * @name RegUsbDOEPEACHMSK2
 * @{
 */
// RegUsbDOEPEACHMSK2.r32
#define  REG_USB_DOEPEACHMSK2_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDOEPEACHMSK2 */
#define  REG_USB_DOEPEACHMSK2_MASK                          0x0000717Bu                   /**< Mask for RegUsbDOEPEACHMSK2 */

#define  USB_DOEPEACHMSK2_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDOEPEACHMSK2XferComplMsk */
#define  USB_DOEPEACHMSK2_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDOEPEACHMSK2XferComplMsk */
#define  USB_DOEPEACHMSK2_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDOEPEACHMSK2XferComplMsk */
#define  USB_DOEPEACHMSK2_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDOEPEACHMSK2XferComplMsk in register */
#define  GET_USB_DOEPEACHMSK2_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDOEPEACHMSK2XferComplMsk from register */
#define  USB_DOEPEACHMSK2_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDOEPEACHMSK2EPDisbldMsk */
#define  USB_DOEPEACHMSK2_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDOEPEACHMSK2EPDisbldMsk */
#define  USB_DOEPEACHMSK2_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK2EPDisbldMsk */
#define  USB_DOEPEACHMSK2_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDOEPEACHMSK2EPDisbldMsk in register */
#define  GET_USB_DOEPEACHMSK2_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDOEPEACHMSK2EPDisbldMsk from register */
#define  USB_DOEPEACHMSK2_SET_UPMSK_SHIFT                   3                             /**< Shift for UsbDOEPEACHMSK2SetUPMsk */
#define  USB_DOEPEACHMSK2_SET_UPMSK_MASK                    0x00000008u                   /**< Mask for UsbDOEPEACHMSK2SetUPMsk */
#define  USB_DOEPEACHMSK2_SET_UPMSK_BMASK                   0x1u                          /**< Base mask for UsbDOEPEACHMSK2SetUPMsk */
#define  USB_DOEPEACHMSK2_SET_UPMSK(x)                      (((x)&0x1u)<<3)               /**< Set UsbDOEPEACHMSK2SetUPMsk in register */
#define  GET_USB_DOEPEACHMSK2_SET_UPMSK(reg)                (((reg)>>3)&0x1u)             /**< Get UsbDOEPEACHMSK2SetUPMsk from register */
#define  USB_DOEPEACHMSK2_OUTTKN_EPDIS_MSK_SHIFT            4                             /**< Shift for UsbDOEPEACHMSK2OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK2_OUTTKN_EPDIS_MSK_MASK             0x00000010u                   /**< Mask for UsbDOEPEACHMSK2OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK2_OUTTKN_EPDIS_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK2OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK2_OUTTKN_EPDIS_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDOEPEACHMSK2OUTTknEPdisMsk in register */
#define  GET_USB_DOEPEACHMSK2_OUTTKN_EPDIS_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDOEPEACHMSK2OUTTknEPdisMsk from register */
#define  USB_DOEPEACHMSK2_STS_PHS_RCVD_MSK_SHIFT            5                             /**< Shift for UsbDOEPEACHMSK2StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK2_STS_PHS_RCVD_MSK_MASK             0x00000020u                   /**< Mask for UsbDOEPEACHMSK2StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK2_STS_PHS_RCVD_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK2StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK2_STS_PHS_RCVD_MSK(x)               (((x)&0x1u)<<5)               /**< Set UsbDOEPEACHMSK2StsPhsRcvdMsk in register */
#define  GET_USB_DOEPEACHMSK2_STS_PHS_RCVD_MSK(reg)         (((reg)>>5)&0x1u)             /**< Get UsbDOEPEACHMSK2StsPhsRcvdMsk from register */
#define  USB_DOEPEACHMSK2_BACK2BACK_SETUP_SHIFT             6                             /**< Shift for UsbDOEPEACHMSK2Back2BackSETup */
#define  USB_DOEPEACHMSK2_BACK2BACK_SETUP_MASK              0x00000040u                   /**< Mask for UsbDOEPEACHMSK2Back2BackSETup */
#define  USB_DOEPEACHMSK2_BACK2BACK_SETUP_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK2Back2BackSETup */
#define  USB_DOEPEACHMSK2_BACK2BACK_SETUP(x)                (((x)&0x1u)<<6)               /**< Set UsbDOEPEACHMSK2Back2BackSETup in register */
#define  GET_USB_DOEPEACHMSK2_BACK2BACK_SETUP(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDOEPEACHMSK2Back2BackSETup from register */
#define  USB_DOEPEACHMSK2_OUT_PKT_ERR_MSK_SHIFT             8                             /**< Shift for UsbDOEPEACHMSK2OutPktErrMsk */
#define  USB_DOEPEACHMSK2_OUT_PKT_ERR_MSK_MASK              0x00000100u                   /**< Mask for UsbDOEPEACHMSK2OutPktErrMsk */
#define  USB_DOEPEACHMSK2_OUT_PKT_ERR_MSK_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK2OutPktErrMsk */
#define  USB_DOEPEACHMSK2_OUT_PKT_ERR_MSK(x)                (((x)&0x1u)<<8)               /**< Set UsbDOEPEACHMSK2OutPktErrMsk in register */
#define  GET_USB_DOEPEACHMSK2_OUT_PKT_ERR_MSK(reg)          (((reg)>>8)&0x1u)             /**< Get UsbDOEPEACHMSK2OutPktErrMsk from register */
#define  USB_DOEPEACHMSK2_BBLE_ERR_MSK_SHIFT                12                            /**< Shift for UsbDOEPEACHMSK2BbleErrMsk */
#define  USB_DOEPEACHMSK2_BBLE_ERR_MSK_MASK                 0x00001000u                   /**< Mask for UsbDOEPEACHMSK2BbleErrMsk */
#define  USB_DOEPEACHMSK2_BBLE_ERR_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK2BbleErrMsk */
#define  USB_DOEPEACHMSK2_BBLE_ERR_MSK(x)                   (((x)&0x1u)<<12)              /**< Set UsbDOEPEACHMSK2BbleErrMsk in register */
#define  GET_USB_DOEPEACHMSK2_BBLE_ERR_MSK(reg)             (((reg)>>12)&0x1u)            /**< Get UsbDOEPEACHMSK2BbleErrMsk from register */
#define  USB_DOEPEACHMSK2_NAKMSK_SHIFT                      13                            /**< Shift for UsbDOEPEACHMSK2NAKMsk */
#define  USB_DOEPEACHMSK2_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDOEPEACHMSK2NAKMsk */
#define  USB_DOEPEACHMSK2_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDOEPEACHMSK2NAKMsk */
#define  USB_DOEPEACHMSK2_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDOEPEACHMSK2NAKMsk in register */
#define  GET_USB_DOEPEACHMSK2_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDOEPEACHMSK2NAKMsk from register */
#define  USB_DOEPEACHMSK2_NYETMSK_SHIFT                     14                            /**< Shift for UsbDOEPEACHMSK2NYETMsk */
#define  USB_DOEPEACHMSK2_NYETMSK_MASK                      0x00004000u                   /**< Mask for UsbDOEPEACHMSK2NYETMsk */
#define  USB_DOEPEACHMSK2_NYETMSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPEACHMSK2NYETMsk */
#define  USB_DOEPEACHMSK2_NYETMSK(x)                        (((x)&0x1u)<<14)              /**< Set UsbDOEPEACHMSK2NYETMsk in register */
#define  GET_USB_DOEPEACHMSK2_NYETMSK(reg)                  (((reg)>>14)&0x1u)            /**< Get UsbDOEPEACHMSK2NYETMsk from register */
/** @} */


/**
 * @name RegUsbDOEPEACHMSK3
 * @{
 */
// RegUsbDOEPEACHMSK3.r32
#define  REG_USB_DOEPEACHMSK3_RESET_VALUE                   0x00000000u                   /**< Reset value of RegUsbDOEPEACHMSK3 */
#define  REG_USB_DOEPEACHMSK3_MASK                          0x0000717Bu                   /**< Mask for RegUsbDOEPEACHMSK3 */

#define  USB_DOEPEACHMSK3_XFER_COMPL_MSK_SHIFT              0                             /**< Shift for UsbDOEPEACHMSK3XferComplMsk */
#define  USB_DOEPEACHMSK3_XFER_COMPL_MSK_MASK               0x00000001u                   /**< Mask for UsbDOEPEACHMSK3XferComplMsk */
#define  USB_DOEPEACHMSK3_XFER_COMPL_MSK_BMASK              0x1u                          /**< Base mask for UsbDOEPEACHMSK3XferComplMsk */
#define  USB_DOEPEACHMSK3_XFER_COMPL_MSK(x)                 (((x)&0x1u)<<0)               /**< Set UsbDOEPEACHMSK3XferComplMsk in register */
#define  GET_USB_DOEPEACHMSK3_XFER_COMPL_MSK(reg)           (((reg)>>0)&0x1u)             /**< Get UsbDOEPEACHMSK3XferComplMsk from register */
#define  USB_DOEPEACHMSK3_EPDISBLD_MSK_SHIFT                1                             /**< Shift for UsbDOEPEACHMSK3EPDisbldMsk */
#define  USB_DOEPEACHMSK3_EPDISBLD_MSK_MASK                 0x00000002u                   /**< Mask for UsbDOEPEACHMSK3EPDisbldMsk */
#define  USB_DOEPEACHMSK3_EPDISBLD_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK3EPDisbldMsk */
#define  USB_DOEPEACHMSK3_EPDISBLD_MSK(x)                   (((x)&0x1u)<<1)               /**< Set UsbDOEPEACHMSK3EPDisbldMsk in register */
#define  GET_USB_DOEPEACHMSK3_EPDISBLD_MSK(reg)             (((reg)>>1)&0x1u)             /**< Get UsbDOEPEACHMSK3EPDisbldMsk from register */
#define  USB_DOEPEACHMSK3_SET_UPMSK_SHIFT                   3                             /**< Shift for UsbDOEPEACHMSK3SetUPMsk */
#define  USB_DOEPEACHMSK3_SET_UPMSK_MASK                    0x00000008u                   /**< Mask for UsbDOEPEACHMSK3SetUPMsk */
#define  USB_DOEPEACHMSK3_SET_UPMSK_BMASK                   0x1u                          /**< Base mask for UsbDOEPEACHMSK3SetUPMsk */
#define  USB_DOEPEACHMSK3_SET_UPMSK(x)                      (((x)&0x1u)<<3)               /**< Set UsbDOEPEACHMSK3SetUPMsk in register */
#define  GET_USB_DOEPEACHMSK3_SET_UPMSK(reg)                (((reg)>>3)&0x1u)             /**< Get UsbDOEPEACHMSK3SetUPMsk from register */
#define  USB_DOEPEACHMSK3_OUTTKN_EPDIS_MSK_SHIFT            4                             /**< Shift for UsbDOEPEACHMSK3OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK3_OUTTKN_EPDIS_MSK_MASK             0x00000010u                   /**< Mask for UsbDOEPEACHMSK3OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK3_OUTTKN_EPDIS_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK3OUTTknEPdisMsk */
#define  USB_DOEPEACHMSK3_OUTTKN_EPDIS_MSK(x)               (((x)&0x1u)<<4)               /**< Set UsbDOEPEACHMSK3OUTTknEPdisMsk in register */
#define  GET_USB_DOEPEACHMSK3_OUTTKN_EPDIS_MSK(reg)         (((reg)>>4)&0x1u)             /**< Get UsbDOEPEACHMSK3OUTTknEPdisMsk from register */
#define  USB_DOEPEACHMSK3_STS_PHS_RCVD_MSK_SHIFT            5                             /**< Shift for UsbDOEPEACHMSK3StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK3_STS_PHS_RCVD_MSK_MASK             0x00000020u                   /**< Mask for UsbDOEPEACHMSK3StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK3_STS_PHS_RCVD_MSK_BMASK            0x1u                          /**< Base mask for UsbDOEPEACHMSK3StsPhsRcvdMsk */
#define  USB_DOEPEACHMSK3_STS_PHS_RCVD_MSK(x)               (((x)&0x1u)<<5)               /**< Set UsbDOEPEACHMSK3StsPhsRcvdMsk in register */
#define  GET_USB_DOEPEACHMSK3_STS_PHS_RCVD_MSK(reg)         (((reg)>>5)&0x1u)             /**< Get UsbDOEPEACHMSK3StsPhsRcvdMsk from register */
#define  USB_DOEPEACHMSK3_BACK2BACK_SETUP_SHIFT             6                             /**< Shift for UsbDOEPEACHMSK3Back2BackSETup */
#define  USB_DOEPEACHMSK3_BACK2BACK_SETUP_MASK              0x00000040u                   /**< Mask for UsbDOEPEACHMSK3Back2BackSETup */
#define  USB_DOEPEACHMSK3_BACK2BACK_SETUP_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK3Back2BackSETup */
#define  USB_DOEPEACHMSK3_BACK2BACK_SETUP(x)                (((x)&0x1u)<<6)               /**< Set UsbDOEPEACHMSK3Back2BackSETup in register */
#define  GET_USB_DOEPEACHMSK3_BACK2BACK_SETUP(reg)          (((reg)>>6)&0x1u)             /**< Get UsbDOEPEACHMSK3Back2BackSETup from register */
#define  USB_DOEPEACHMSK3_OUT_PKT_ERR_MSK_SHIFT             8                             /**< Shift for UsbDOEPEACHMSK3OutPktErrMsk */
#define  USB_DOEPEACHMSK3_OUT_PKT_ERR_MSK_MASK              0x00000100u                   /**< Mask for UsbDOEPEACHMSK3OutPktErrMsk */
#define  USB_DOEPEACHMSK3_OUT_PKT_ERR_MSK_BMASK             0x1u                          /**< Base mask for UsbDOEPEACHMSK3OutPktErrMsk */
#define  USB_DOEPEACHMSK3_OUT_PKT_ERR_MSK(x)                (((x)&0x1u)<<8)               /**< Set UsbDOEPEACHMSK3OutPktErrMsk in register */
#define  GET_USB_DOEPEACHMSK3_OUT_PKT_ERR_MSK(reg)          (((reg)>>8)&0x1u)             /**< Get UsbDOEPEACHMSK3OutPktErrMsk from register */
#define  USB_DOEPEACHMSK3_BBLE_ERR_MSK_SHIFT                12                            /**< Shift for UsbDOEPEACHMSK3BbleErrMsk */
#define  USB_DOEPEACHMSK3_BBLE_ERR_MSK_MASK                 0x00001000u                   /**< Mask for UsbDOEPEACHMSK3BbleErrMsk */
#define  USB_DOEPEACHMSK3_BBLE_ERR_MSK_BMASK                0x1u                          /**< Base mask for UsbDOEPEACHMSK3BbleErrMsk */
#define  USB_DOEPEACHMSK3_BBLE_ERR_MSK(x)                   (((x)&0x1u)<<12)              /**< Set UsbDOEPEACHMSK3BbleErrMsk in register */
#define  GET_USB_DOEPEACHMSK3_BBLE_ERR_MSK(reg)             (((reg)>>12)&0x1u)            /**< Get UsbDOEPEACHMSK3BbleErrMsk from register */
#define  USB_DOEPEACHMSK3_NAKMSK_SHIFT                      13                            /**< Shift for UsbDOEPEACHMSK3NAKMsk */
#define  USB_DOEPEACHMSK3_NAKMSK_MASK                       0x00002000u                   /**< Mask for UsbDOEPEACHMSK3NAKMsk */
#define  USB_DOEPEACHMSK3_NAKMSK_BMASK                      0x1u                          /**< Base mask for UsbDOEPEACHMSK3NAKMsk */
#define  USB_DOEPEACHMSK3_NAKMSK(x)                         (((x)&0x1u)<<13)              /**< Set UsbDOEPEACHMSK3NAKMsk in register */
#define  GET_USB_DOEPEACHMSK3_NAKMSK(reg)                   (((reg)>>13)&0x1u)            /**< Get UsbDOEPEACHMSK3NAKMsk from register */
#define  USB_DOEPEACHMSK3_NYETMSK_SHIFT                     14                            /**< Shift for UsbDOEPEACHMSK3NYETMsk */
#define  USB_DOEPEACHMSK3_NYETMSK_MASK                      0x00004000u                   /**< Mask for UsbDOEPEACHMSK3NYETMsk */
#define  USB_DOEPEACHMSK3_NYETMSK_BMASK                     0x1u                          /**< Base mask for UsbDOEPEACHMSK3NYETMsk */
#define  USB_DOEPEACHMSK3_NYETMSK(x)                        (((x)&0x1u)<<14)              /**< Set UsbDOEPEACHMSK3NYETMsk in register */
#define  GET_USB_DOEPEACHMSK3_NYETMSK(reg)                  (((reg)>>14)&0x1u)            /**< Get UsbDOEPEACHMSK3NYETMsk from register */
/** @} */


/**
 * @name RegUsbDIEPCTL0
 * @{
 */
// RegUsbDIEPCTL0.r32
#define  REG_USB_DIEPCTL0_RESET_VALUE                       0x00008000u                   /**< Reset value of RegUsbDIEPCTL0 */
#define  REG_USB_DIEPCTL0_MASK                              0xCFEEF803u                   /**< Mask for RegUsbDIEPCTL0 */

#define  USB_DIEPCTL0_MPS_SHIFT                             0                             /**< Shift for UsbDIEPCTL0MPS */
#define  USB_DIEPCTL0_MPS_MASK                              0x00000003u                   /**< Mask for UsbDIEPCTL0MPS */
#define  USB_DIEPCTL0_MPS_BMASK                             0x3u                          /**< Base mask for UsbDIEPCTL0MPS */
#define  USB_DIEPCTL0_MPS(x)                                (((x)&0x3u)<<0)               /**< Set UsbDIEPCTL0MPS in register */
#define  GET_USB_DIEPCTL0_MPS(reg)                          (((reg)>>0)&0x3u)             /**< Get UsbDIEPCTL0MPS from register */
#define  USB_DIEPCTL0_NEXT_EP_SHIFT                         11                            /**< Shift for UsbDIEPCTL0NextEp */
#define  USB_DIEPCTL0_NEXT_EP_MASK                          0x00007800u                   /**< Mask for UsbDIEPCTL0NextEp */
#define  USB_DIEPCTL0_NEXT_EP_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL0NextEp */
#define  USB_DIEPCTL0_NEXT_EP(x)                            (((x)&0xFu)<<11)              /**< Set UsbDIEPCTL0NextEp in register */
#define  GET_USB_DIEPCTL0_NEXT_EP(reg)                      (((reg)>>11)&0xFu)            /**< Get UsbDIEPCTL0NextEp from register */
#define  USB_DIEPCTL0_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDIEPCTL0USBActEP */
#define  USB_DIEPCTL0_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDIEPCTL0USBActEP */
#define  USB_DIEPCTL0_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL0USBActEP */
#define  USB_DIEPCTL0_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDIEPCTL0USBActEP in register */
#define  GET_USB_DIEPCTL0_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDIEPCTL0USBActEP from register */
#define  USB_DIEPCTL0_NAKSTS_SHIFT                          17                            /**< Shift for UsbDIEPCTL0NAKSts */
#define  USB_DIEPCTL0_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDIEPCTL0NAKSts */
#define  USB_DIEPCTL0_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDIEPCTL0NAKSts */
#define  USB_DIEPCTL0_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDIEPCTL0NAKSts in register */
#define  GET_USB_DIEPCTL0_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDIEPCTL0NAKSts from register */
#define  USB_DIEPCTL0_EPTYPE_SHIFT                          18                            /**< Shift for UsbDIEPCTL0EPType */
#define  USB_DIEPCTL0_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDIEPCTL0EPType */
#define  USB_DIEPCTL0_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDIEPCTL0EPType */
#define  USB_DIEPCTL0_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDIEPCTL0EPType in register */
#define  GET_USB_DIEPCTL0_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDIEPCTL0EPType from register */
#define  USB_DIEPCTL0_STALL_SHIFT                           21                            /**< Shift for UsbDIEPCTL0Stall */
#define  USB_DIEPCTL0_STALL_MASK                            0x00200000u                   /**< Mask for UsbDIEPCTL0Stall */
#define  USB_DIEPCTL0_STALL_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL0Stall */
#define  USB_DIEPCTL0_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDIEPCTL0Stall in register */
#define  GET_USB_DIEPCTL0_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDIEPCTL0Stall from register */
#define  USB_DIEPCTL0_TX_FNUM_SHIFT                         22                            /**< Shift for UsbDIEPCTL0TxFNum */
#define  USB_DIEPCTL0_TX_FNUM_MASK                          0x03C00000u                   /**< Mask for UsbDIEPCTL0TxFNum */
#define  USB_DIEPCTL0_TX_FNUM_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL0TxFNum */
#define  USB_DIEPCTL0_TX_FNUM(x)                            (((x)&0xFu)<<22)              /**< Set UsbDIEPCTL0TxFNum in register */
#define  GET_USB_DIEPCTL0_TX_FNUM(reg)                      (((reg)>>22)&0xFu)            /**< Get UsbDIEPCTL0TxFNum from register */
#define  USB_DIEPCTL0_CNAK_SHIFT                            26                            /**< Shift for UsbDIEPCTL0CNAK */
#define  USB_DIEPCTL0_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDIEPCTL0CNAK */
#define  USB_DIEPCTL0_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL0CNAK */
#define  USB_DIEPCTL0_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDIEPCTL0CNAK in register */
#define  GET_USB_DIEPCTL0_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDIEPCTL0CNAK from register */
#define  USB_DIEPCTL0_SNAK_SHIFT                            27                            /**< Shift for UsbDIEPCTL0SNAK */
#define  USB_DIEPCTL0_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDIEPCTL0SNAK */
#define  USB_DIEPCTL0_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL0SNAK */
#define  USB_DIEPCTL0_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDIEPCTL0SNAK in register */
#define  GET_USB_DIEPCTL0_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDIEPCTL0SNAK from register */
#define  USB_DIEPCTL0_EPDIS_SHIFT                           30                            /**< Shift for UsbDIEPCTL0EPDis */
#define  USB_DIEPCTL0_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDIEPCTL0EPDis */
#define  USB_DIEPCTL0_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL0EPDis */
#define  USB_DIEPCTL0_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDIEPCTL0EPDis in register */
#define  GET_USB_DIEPCTL0_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDIEPCTL0EPDis from register */
#define  USB_DIEPCTL0_EPENA_SHIFT                           31                            /**< Shift for UsbDIEPCTL0EPEna */
#define  USB_DIEPCTL0_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDIEPCTL0EPEna */
#define  USB_DIEPCTL0_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL0EPEna */
#define  USB_DIEPCTL0_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDIEPCTL0EPEna in register */
#define  GET_USB_DIEPCTL0_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDIEPCTL0EPEna from register */
/** @} */


/**
 * @name RegUsbDIEPINT0
 * @{
 */
// RegUsbDIEPINT0.r32
#define  REG_USB_DIEPINT0_RESET_VALUE                       0x00000080u                   /**< Reset value of RegUsbDIEPINT0 */
#define  REG_USB_DIEPINT0_MASK                              0x00007AFBu                   /**< Mask for RegUsbDIEPINT0 */

#define  USB_DIEPINT0_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDIEPINT0XferCompl */
#define  USB_DIEPINT0_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDIEPINT0XferCompl */
#define  USB_DIEPINT0_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT0XferCompl */
#define  USB_DIEPINT0_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDIEPINT0XferCompl in register */
#define  GET_USB_DIEPINT0_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDIEPINT0XferCompl from register */
#define  USB_DIEPINT0_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDIEPINT0EPDisbld */
#define  USB_DIEPINT0_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDIEPINT0EPDisbld */
#define  USB_DIEPINT0_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT0EPDisbld */
#define  USB_DIEPINT0_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDIEPINT0EPDisbld in register */
#define  GET_USB_DIEPINT0_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDIEPINT0EPDisbld from register */
#define  USB_DIEPINT0_TIME_OUT_SHIFT                        3                             /**< Shift for UsbDIEPINT0TimeOUT */
#define  USB_DIEPINT0_TIME_OUT_MASK                         0x00000008u                   /**< Mask for UsbDIEPINT0TimeOUT */
#define  USB_DIEPINT0_TIME_OUT_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT0TimeOUT */
#define  USB_DIEPINT0_TIME_OUT(x)                           (((x)&0x1u)<<3)               /**< Set UsbDIEPINT0TimeOUT in register */
#define  GET_USB_DIEPINT0_TIME_OUT(reg)                     (((reg)>>3)&0x1u)             /**< Get UsbDIEPINT0TimeOUT from register */
#define  USB_DIEPINT0_INTKN_TXFEMP_SHIFT                    4                             /**< Shift for UsbDIEPINT0INTknTXFEmp */
#define  USB_DIEPINT0_INTKN_TXFEMP_MASK                     0x00000010u                   /**< Mask for UsbDIEPINT0INTknTXFEmp */
#define  USB_DIEPINT0_INTKN_TXFEMP_BMASK                    0x1u                          /**< Base mask for UsbDIEPINT0INTknTXFEmp */
#define  USB_DIEPINT0_INTKN_TXFEMP(x)                       (((x)&0x1u)<<4)               /**< Set UsbDIEPINT0INTknTXFEmp in register */
#define  GET_USB_DIEPINT0_INTKN_TXFEMP(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDIEPINT0INTknTXFEmp from register */
#define  USB_DIEPINT0_INTKN_EPMIS_SHIFT                     5                             /**< Shift for UsbDIEPINT0INTknEPMis */
#define  USB_DIEPINT0_INTKN_EPMIS_MASK                      0x00000020u                   /**< Mask for UsbDIEPINT0INTknEPMis */
#define  USB_DIEPINT0_INTKN_EPMIS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT0INTknEPMis */
#define  USB_DIEPINT0_INTKN_EPMIS(x)                        (((x)&0x1u)<<5)               /**< Set UsbDIEPINT0INTknEPMis in register */
#define  GET_USB_DIEPINT0_INTKN_EPMIS(reg)                  (((reg)>>5)&0x1u)             /**< Get UsbDIEPINT0INTknEPMis from register */
#define  USB_DIEPINT0_INEPNAK_EFF_SHIFT                     6                             /**< Shift for UsbDIEPINT0INEPNakEff */
#define  USB_DIEPINT0_INEPNAK_EFF_MASK                      0x00000040u                   /**< Mask for UsbDIEPINT0INEPNakEff */
#define  USB_DIEPINT0_INEPNAK_EFF_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT0INEPNakEff */
#define  USB_DIEPINT0_INEPNAK_EFF(x)                        (((x)&0x1u)<<6)               /**< Set UsbDIEPINT0INEPNakEff in register */
#define  GET_USB_DIEPINT0_INEPNAK_EFF(reg)                  (((reg)>>6)&0x1u)             /**< Get UsbDIEPINT0INEPNakEff from register */
#define  USB_DIEPINT0_TX_FEMP_SHIFT                         7                             /**< Shift for UsbDIEPINT0TxFEmp */
#define  USB_DIEPINT0_TX_FEMP_MASK                          0x00000080u                   /**< Mask for UsbDIEPINT0TxFEmp */
#define  USB_DIEPINT0_TX_FEMP_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT0TxFEmp */
#define  USB_DIEPINT0_TX_FEMP(x)                            (((x)&0x1u)<<7)               /**< Set UsbDIEPINT0TxFEmp in register */
#define  GET_USB_DIEPINT0_TX_FEMP(reg)                      (((reg)>>7)&0x1u)             /**< Get UsbDIEPINT0TxFEmp from register */
#define  USB_DIEPINT0_BNAINTR_SHIFT                         9                             /**< Shift for UsbDIEPINT0BNAIntr */
#define  USB_DIEPINT0_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDIEPINT0BNAIntr */
#define  USB_DIEPINT0_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT0BNAIntr */
#define  USB_DIEPINT0_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDIEPINT0BNAIntr in register */
#define  GET_USB_DIEPINT0_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDIEPINT0BNAIntr from register */
#define  USB_DIEPINT0_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDIEPINT0PktDrpSts */
#define  USB_DIEPINT0_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDIEPINT0PktDrpSts */
#define  USB_DIEPINT0_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT0PktDrpSts */
#define  USB_DIEPINT0_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDIEPINT0PktDrpSts in register */
#define  GET_USB_DIEPINT0_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDIEPINT0PktDrpSts from register */
#define  USB_DIEPINT0_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDIEPINT0BbleErr */
#define  USB_DIEPINT0_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDIEPINT0BbleErr */
#define  USB_DIEPINT0_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT0BbleErr */
#define  USB_DIEPINT0_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDIEPINT0BbleErr in register */
#define  GET_USB_DIEPINT0_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDIEPINT0BbleErr from register */
#define  USB_DIEPINT0_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDIEPINT0NAKIntrpt */
#define  USB_DIEPINT0_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDIEPINT0NAKIntrpt */
#define  USB_DIEPINT0_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDIEPINT0NAKIntrpt */
#define  USB_DIEPINT0_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDIEPINT0NAKIntrpt in register */
#define  GET_USB_DIEPINT0_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDIEPINT0NAKIntrpt from register */
#define  USB_DIEPINT0_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDIEPINT0NYETIntrpt */
#define  USB_DIEPINT0_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDIEPINT0NYETIntrpt */
#define  USB_DIEPINT0_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT0NYETIntrpt */
#define  USB_DIEPINT0_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDIEPINT0NYETIntrpt in register */
#define  GET_USB_DIEPINT0_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDIEPINT0NYETIntrpt from register */
/** @} */


/**
 * @name RegUsbDIEPTSIZ0
 * @{
 */
// RegUsbDIEPTSIZ0.r32
#define  REG_USB_DIEPTSIZ0_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDIEPTSIZ0 */
#define  REG_USB_DIEPTSIZ0_MASK                             0x0018007Fu                   /**< Mask for RegUsbDIEPTSIZ0 */

#define  USB_DIEPTSIZ0_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDIEPTSIZ0XferSize */
#define  USB_DIEPTSIZ0_XFER_SIZE_MASK                       0x0000007Fu                   /**< Mask for UsbDIEPTSIZ0XferSize */
#define  USB_DIEPTSIZ0_XFER_SIZE_BMASK                      0x7Fu                         /**< Base mask for UsbDIEPTSIZ0XferSize */
#define  USB_DIEPTSIZ0_XFER_SIZE(x)                         (((x)&0x7Fu)<<0)              /**< Set UsbDIEPTSIZ0XferSize in register */
#define  GET_USB_DIEPTSIZ0_XFER_SIZE(reg)                   (((reg)>>0)&0x7Fu)            /**< Get UsbDIEPTSIZ0XferSize from register */
#define  USB_DIEPTSIZ0_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDIEPTSIZ0PktCnt */
#define  USB_DIEPTSIZ0_PKT_CNT_MASK                         0x00180000u                   /**< Mask for UsbDIEPTSIZ0PktCnt */
#define  USB_DIEPTSIZ0_PKT_CNT_BMASK                        0x3u                          /**< Base mask for UsbDIEPTSIZ0PktCnt */
#define  USB_DIEPTSIZ0_PKT_CNT(x)                           (((x)&0x3u)<<19)              /**< Set UsbDIEPTSIZ0PktCnt in register */
#define  GET_USB_DIEPTSIZ0_PKT_CNT(reg)                     (((reg)>>19)&0x3u)            /**< Get UsbDIEPTSIZ0PktCnt from register */
/** @} */


/**
 * @name RegUsbDTXFSTS0
 * @{
 */
// RegUsbDTXFSTS0.r32
#define  REG_USB_DTXFSTS0_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDTXFSTS0 */
#define  REG_USB_DTXFSTS0_MASK                              0x0000FFFFu                   /**< Mask for RegUsbDTXFSTS0 */

#define  USB_DTXFSTS0_INEPTX_FSPC_AVAIL_SHIFT               0                             /**< Shift for UsbDTXFSTS0INEPTxFSpcAvail */
#define  USB_DTXFSTS0_INEPTX_FSPC_AVAIL_MASK                0x0000FFFFu                   /**< Mask for UsbDTXFSTS0INEPTxFSpcAvail */
#define  USB_DTXFSTS0_INEPTX_FSPC_AVAIL_BMASK               0xFFFFu                       /**< Base mask for UsbDTXFSTS0INEPTxFSpcAvail */
#define  USB_DTXFSTS0_INEPTX_FSPC_AVAIL(x)                  (((x)&0xFFFFu)<<0)            /**< Set UsbDTXFSTS0INEPTxFSpcAvail in register */
#define  GET_USB_DTXFSTS0_INEPTX_FSPC_AVAIL(reg)            (((reg)>>0)&0xFFFFu)          /**< Get UsbDTXFSTS0INEPTxFSpcAvail from register */
/** @} */


/**
 * @name RegUsbDIEPCTL1
 * @{
 */
// RegUsbDIEPCTL1.r32
#define  REG_USB_DIEPCTL1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDIEPCTL1 */
#define  REG_USB_DIEPCTL1_MASK                              0xFFEFFFFFu                   /**< Mask for RegUsbDIEPCTL1 */

#define  USB_DIEPCTL1_MPS_SHIFT                             0                             /**< Shift for UsbDIEPCTL1MPS */
#define  USB_DIEPCTL1_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDIEPCTL1MPS */
#define  USB_DIEPCTL1_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDIEPCTL1MPS */
#define  USB_DIEPCTL1_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDIEPCTL1MPS in register */
#define  GET_USB_DIEPCTL1_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPCTL1MPS from register */
#define  USB_DIEPCTL1_NEXT_EP_SHIFT                         11                            /**< Shift for UsbDIEPCTL1NextEp */
#define  USB_DIEPCTL1_NEXT_EP_MASK                          0x00007800u                   /**< Mask for UsbDIEPCTL1NextEp */
#define  USB_DIEPCTL1_NEXT_EP_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL1NextEp */
#define  USB_DIEPCTL1_NEXT_EP(x)                            (((x)&0xFu)<<11)              /**< Set UsbDIEPCTL1NextEp in register */
#define  GET_USB_DIEPCTL1_NEXT_EP(reg)                      (((reg)>>11)&0xFu)            /**< Get UsbDIEPCTL1NextEp from register */
#define  USB_DIEPCTL1_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDIEPCTL1USBActEP */
#define  USB_DIEPCTL1_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDIEPCTL1USBActEP */
#define  USB_DIEPCTL1_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL1USBActEP */
#define  USB_DIEPCTL1_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDIEPCTL1USBActEP in register */
#define  GET_USB_DIEPCTL1_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDIEPCTL1USBActEP from register */
#define  USB_DIEPCTL1_DPID_SHIFT                            16                            /**< Shift for UsbDIEPCTL1DPID */
#define  USB_DIEPCTL1_DPID_MASK                             0x00010000u                   /**< Mask for UsbDIEPCTL1DPID */
#define  USB_DIEPCTL1_DPID_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL1DPID */
#define  USB_DIEPCTL1_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDIEPCTL1DPID in register */
#define  GET_USB_DIEPCTL1_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDIEPCTL1DPID from register */
#define  USB_DIEPCTL1_NAKSTS_SHIFT                          17                            /**< Shift for UsbDIEPCTL1NAKSts */
#define  USB_DIEPCTL1_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDIEPCTL1NAKSts */
#define  USB_DIEPCTL1_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDIEPCTL1NAKSts */
#define  USB_DIEPCTL1_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDIEPCTL1NAKSts in register */
#define  GET_USB_DIEPCTL1_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDIEPCTL1NAKSts from register */
#define  USB_DIEPCTL1_EPTYPE_SHIFT                          18                            /**< Shift for UsbDIEPCTL1EPType */
#define  USB_DIEPCTL1_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDIEPCTL1EPType */
#define  USB_DIEPCTL1_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDIEPCTL1EPType */
#define  USB_DIEPCTL1_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDIEPCTL1EPType in register */
#define  GET_USB_DIEPCTL1_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDIEPCTL1EPType from register */
#define  USB_DIEPCTL1_STALL_SHIFT                           21                            /**< Shift for UsbDIEPCTL1Stall */
#define  USB_DIEPCTL1_STALL_MASK                            0x00200000u                   /**< Mask for UsbDIEPCTL1Stall */
#define  USB_DIEPCTL1_STALL_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL1Stall */
#define  USB_DIEPCTL1_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDIEPCTL1Stall in register */
#define  GET_USB_DIEPCTL1_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDIEPCTL1Stall from register */
#define  USB_DIEPCTL1_TX_FNUM_SHIFT                         22                            /**< Shift for UsbDIEPCTL1TxFNum */
#define  USB_DIEPCTL1_TX_FNUM_MASK                          0x03C00000u                   /**< Mask for UsbDIEPCTL1TxFNum */
#define  USB_DIEPCTL1_TX_FNUM_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL1TxFNum */
#define  USB_DIEPCTL1_TX_FNUM(x)                            (((x)&0xFu)<<22)              /**< Set UsbDIEPCTL1TxFNum in register */
#define  GET_USB_DIEPCTL1_TX_FNUM(reg)                      (((reg)>>22)&0xFu)            /**< Get UsbDIEPCTL1TxFNum from register */
#define  USB_DIEPCTL1_CNAK_SHIFT                            26                            /**< Shift for UsbDIEPCTL1CNAK */
#define  USB_DIEPCTL1_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDIEPCTL1CNAK */
#define  USB_DIEPCTL1_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL1CNAK */
#define  USB_DIEPCTL1_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDIEPCTL1CNAK in register */
#define  GET_USB_DIEPCTL1_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDIEPCTL1CNAK from register */
#define  USB_DIEPCTL1_SNAK_SHIFT                            27                            /**< Shift for UsbDIEPCTL1SNAK */
#define  USB_DIEPCTL1_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDIEPCTL1SNAK */
#define  USB_DIEPCTL1_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL1SNAK */
#define  USB_DIEPCTL1_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDIEPCTL1SNAK in register */
#define  GET_USB_DIEPCTL1_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDIEPCTL1SNAK from register */
#define  USB_DIEPCTL1_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDIEPCTL1SetD0PID */
#define  USB_DIEPCTL1_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDIEPCTL1SetD0PID */
#define  USB_DIEPCTL1_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL1SetD0PID */
#define  USB_DIEPCTL1_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDIEPCTL1SetD0PID in register */
#define  GET_USB_DIEPCTL1_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDIEPCTL1SetD0PID from register */
#define  USB_DIEPCTL1_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDIEPCTL1SetD1PID */
#define  USB_DIEPCTL1_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDIEPCTL1SetD1PID */
#define  USB_DIEPCTL1_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL1SetD1PID */
#define  USB_DIEPCTL1_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDIEPCTL1SetD1PID in register */
#define  GET_USB_DIEPCTL1_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDIEPCTL1SetD1PID from register */
#define  USB_DIEPCTL1_EPDIS_SHIFT                           30                            /**< Shift for UsbDIEPCTL1EPDis */
#define  USB_DIEPCTL1_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDIEPCTL1EPDis */
#define  USB_DIEPCTL1_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL1EPDis */
#define  USB_DIEPCTL1_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDIEPCTL1EPDis in register */
#define  GET_USB_DIEPCTL1_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDIEPCTL1EPDis from register */
#define  USB_DIEPCTL1_EPENA_SHIFT                           31                            /**< Shift for UsbDIEPCTL1EPEna */
#define  USB_DIEPCTL1_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDIEPCTL1EPEna */
#define  USB_DIEPCTL1_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL1EPEna */
#define  USB_DIEPCTL1_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDIEPCTL1EPEna in register */
#define  GET_USB_DIEPCTL1_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDIEPCTL1EPEna from register */
/** @} */


/**
 * @name RegUsbDIEPINT1
 * @{
 */
// RegUsbDIEPINT1.r32
#define  REG_USB_DIEPINT1_RESET_VALUE                       0x00000080u                   /**< Reset value of RegUsbDIEPINT1 */
#define  REG_USB_DIEPINT1_MASK                              0x00007AFBu                   /**< Mask for RegUsbDIEPINT1 */

#define  USB_DIEPINT1_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDIEPINT1XferCompl */
#define  USB_DIEPINT1_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDIEPINT1XferCompl */
#define  USB_DIEPINT1_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT1XferCompl */
#define  USB_DIEPINT1_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDIEPINT1XferCompl in register */
#define  GET_USB_DIEPINT1_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDIEPINT1XferCompl from register */
#define  USB_DIEPINT1_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDIEPINT1EPDisbld */
#define  USB_DIEPINT1_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDIEPINT1EPDisbld */
#define  USB_DIEPINT1_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT1EPDisbld */
#define  USB_DIEPINT1_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDIEPINT1EPDisbld in register */
#define  GET_USB_DIEPINT1_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDIEPINT1EPDisbld from register */
#define  USB_DIEPINT1_TIME_OUT_SHIFT                        3                             /**< Shift for UsbDIEPINT1TimeOUT */
#define  USB_DIEPINT1_TIME_OUT_MASK                         0x00000008u                   /**< Mask for UsbDIEPINT1TimeOUT */
#define  USB_DIEPINT1_TIME_OUT_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT1TimeOUT */
#define  USB_DIEPINT1_TIME_OUT(x)                           (((x)&0x1u)<<3)               /**< Set UsbDIEPINT1TimeOUT in register */
#define  GET_USB_DIEPINT1_TIME_OUT(reg)                     (((reg)>>3)&0x1u)             /**< Get UsbDIEPINT1TimeOUT from register */
#define  USB_DIEPINT1_INTKN_TXFEMP_SHIFT                    4                             /**< Shift for UsbDIEPINT1INTknTXFEmp */
#define  USB_DIEPINT1_INTKN_TXFEMP_MASK                     0x00000010u                   /**< Mask for UsbDIEPINT1INTknTXFEmp */
#define  USB_DIEPINT1_INTKN_TXFEMP_BMASK                    0x1u                          /**< Base mask for UsbDIEPINT1INTknTXFEmp */
#define  USB_DIEPINT1_INTKN_TXFEMP(x)                       (((x)&0x1u)<<4)               /**< Set UsbDIEPINT1INTknTXFEmp in register */
#define  GET_USB_DIEPINT1_INTKN_TXFEMP(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDIEPINT1INTknTXFEmp from register */
#define  USB_DIEPINT1_INTKN_EPMIS_SHIFT                     5                             /**< Shift for UsbDIEPINT1INTknEPMis */
#define  USB_DIEPINT1_INTKN_EPMIS_MASK                      0x00000020u                   /**< Mask for UsbDIEPINT1INTknEPMis */
#define  USB_DIEPINT1_INTKN_EPMIS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT1INTknEPMis */
#define  USB_DIEPINT1_INTKN_EPMIS(x)                        (((x)&0x1u)<<5)               /**< Set UsbDIEPINT1INTknEPMis in register */
#define  GET_USB_DIEPINT1_INTKN_EPMIS(reg)                  (((reg)>>5)&0x1u)             /**< Get UsbDIEPINT1INTknEPMis from register */
#define  USB_DIEPINT1_INEPNAK_EFF_SHIFT                     6                             /**< Shift for UsbDIEPINT1INEPNakEff */
#define  USB_DIEPINT1_INEPNAK_EFF_MASK                      0x00000040u                   /**< Mask for UsbDIEPINT1INEPNakEff */
#define  USB_DIEPINT1_INEPNAK_EFF_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT1INEPNakEff */
#define  USB_DIEPINT1_INEPNAK_EFF(x)                        (((x)&0x1u)<<6)               /**< Set UsbDIEPINT1INEPNakEff in register */
#define  GET_USB_DIEPINT1_INEPNAK_EFF(reg)                  (((reg)>>6)&0x1u)             /**< Get UsbDIEPINT1INEPNakEff from register */
#define  USB_DIEPINT1_TX_FEMP_SHIFT                         7                             /**< Shift for UsbDIEPINT1TxFEmp */
#define  USB_DIEPINT1_TX_FEMP_MASK                          0x00000080u                   /**< Mask for UsbDIEPINT1TxFEmp */
#define  USB_DIEPINT1_TX_FEMP_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT1TxFEmp */
#define  USB_DIEPINT1_TX_FEMP(x)                            (((x)&0x1u)<<7)               /**< Set UsbDIEPINT1TxFEmp in register */
#define  GET_USB_DIEPINT1_TX_FEMP(reg)                      (((reg)>>7)&0x1u)             /**< Get UsbDIEPINT1TxFEmp from register */
#define  USB_DIEPINT1_BNAINTR_SHIFT                         9                             /**< Shift for UsbDIEPINT1BNAIntr */
#define  USB_DIEPINT1_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDIEPINT1BNAIntr */
#define  USB_DIEPINT1_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT1BNAIntr */
#define  USB_DIEPINT1_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDIEPINT1BNAIntr in register */
#define  GET_USB_DIEPINT1_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDIEPINT1BNAIntr from register */
#define  USB_DIEPINT1_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDIEPINT1PktDrpSts */
#define  USB_DIEPINT1_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDIEPINT1PktDrpSts */
#define  USB_DIEPINT1_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT1PktDrpSts */
#define  USB_DIEPINT1_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDIEPINT1PktDrpSts in register */
#define  GET_USB_DIEPINT1_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDIEPINT1PktDrpSts from register */
#define  USB_DIEPINT1_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDIEPINT1BbleErr */
#define  USB_DIEPINT1_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDIEPINT1BbleErr */
#define  USB_DIEPINT1_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT1BbleErr */
#define  USB_DIEPINT1_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDIEPINT1BbleErr in register */
#define  GET_USB_DIEPINT1_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDIEPINT1BbleErr from register */
#define  USB_DIEPINT1_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDIEPINT1NAKIntrpt */
#define  USB_DIEPINT1_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDIEPINT1NAKIntrpt */
#define  USB_DIEPINT1_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDIEPINT1NAKIntrpt */
#define  USB_DIEPINT1_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDIEPINT1NAKIntrpt in register */
#define  GET_USB_DIEPINT1_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDIEPINT1NAKIntrpt from register */
#define  USB_DIEPINT1_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDIEPINT1NYETIntrpt */
#define  USB_DIEPINT1_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDIEPINT1NYETIntrpt */
#define  USB_DIEPINT1_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT1NYETIntrpt */
#define  USB_DIEPINT1_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDIEPINT1NYETIntrpt in register */
#define  GET_USB_DIEPINT1_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDIEPINT1NYETIntrpt from register */
/** @} */


/**
 * @name RegUsbDIEPTSIZ1
 * @{
 */
// RegUsbDIEPTSIZ1.r32
#define  REG_USB_DIEPTSIZ1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDIEPTSIZ1 */
#define  REG_USB_DIEPTSIZ1_MASK                             0x607807FFu                   /**< Mask for RegUsbDIEPTSIZ1 */

#define  USB_DIEPTSIZ1_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDIEPTSIZ1XferSize */
#define  USB_DIEPTSIZ1_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDIEPTSIZ1XferSize */
#define  USB_DIEPTSIZ1_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDIEPTSIZ1XferSize */
#define  USB_DIEPTSIZ1_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDIEPTSIZ1XferSize in register */
#define  GET_USB_DIEPTSIZ1_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPTSIZ1XferSize from register */
#define  USB_DIEPTSIZ1_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDIEPTSIZ1PktCnt */
#define  USB_DIEPTSIZ1_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDIEPTSIZ1PktCnt */
#define  USB_DIEPTSIZ1_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDIEPTSIZ1PktCnt */
#define  USB_DIEPTSIZ1_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDIEPTSIZ1PktCnt in register */
#define  GET_USB_DIEPTSIZ1_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDIEPTSIZ1PktCnt from register */
#define  USB_DIEPTSIZ1_MC_SHIFT                             29                            /**< Shift for UsbDIEPTSIZ1MC */
#define  USB_DIEPTSIZ1_MC_MASK                              0x60000000u                   /**< Mask for UsbDIEPTSIZ1MC */
#define  USB_DIEPTSIZ1_MC_BMASK                             0x3u                          /**< Base mask for UsbDIEPTSIZ1MC */
#define  USB_DIEPTSIZ1_MC(x)                                (((x)&0x3u)<<29)              /**< Set UsbDIEPTSIZ1MC in register */
#define  GET_USB_DIEPTSIZ1_MC(reg)                          (((reg)>>29)&0x3u)            /**< Get UsbDIEPTSIZ1MC from register */
/** @} */


/**
 * @name RegUsbDTXFSTS1
 * @{
 */
// RegUsbDTXFSTS1.r32
#define  REG_USB_DTXFSTS1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDTXFSTS1 */
#define  REG_USB_DTXFSTS1_MASK                              0x0000FFFFu                   /**< Mask for RegUsbDTXFSTS1 */

#define  USB_DTXFSTS1_INEPTX_FSPC_AVAIL_SHIFT               0                             /**< Shift for UsbDTXFSTS1INEPTxFSpcAvail */
#define  USB_DTXFSTS1_INEPTX_FSPC_AVAIL_MASK                0x0000FFFFu                   /**< Mask for UsbDTXFSTS1INEPTxFSpcAvail */
#define  USB_DTXFSTS1_INEPTX_FSPC_AVAIL_BMASK               0xFFFFu                       /**< Base mask for UsbDTXFSTS1INEPTxFSpcAvail */
#define  USB_DTXFSTS1_INEPTX_FSPC_AVAIL(x)                  (((x)&0xFFFFu)<<0)            /**< Set UsbDTXFSTS1INEPTxFSpcAvail in register */
#define  GET_USB_DTXFSTS1_INEPTX_FSPC_AVAIL(reg)            (((reg)>>0)&0xFFFFu)          /**< Get UsbDTXFSTS1INEPTxFSpcAvail from register */
/** @} */


/**
 * @name RegUsbDIEPCTL2
 * @{
 */
// RegUsbDIEPCTL2.r32
#define  REG_USB_DIEPCTL2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDIEPCTL2 */
#define  REG_USB_DIEPCTL2_MASK                              0xFFEFFFFFu                   /**< Mask for RegUsbDIEPCTL2 */

#define  USB_DIEPCTL2_MPS_SHIFT                             0                             /**< Shift for UsbDIEPCTL2MPS */
#define  USB_DIEPCTL2_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDIEPCTL2MPS */
#define  USB_DIEPCTL2_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDIEPCTL2MPS */
#define  USB_DIEPCTL2_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDIEPCTL2MPS in register */
#define  GET_USB_DIEPCTL2_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPCTL2MPS from register */
#define  USB_DIEPCTL2_NEXT_EP_SHIFT                         11                            /**< Shift for UsbDIEPCTL2NextEp */
#define  USB_DIEPCTL2_NEXT_EP_MASK                          0x00007800u                   /**< Mask for UsbDIEPCTL2NextEp */
#define  USB_DIEPCTL2_NEXT_EP_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL2NextEp */
#define  USB_DIEPCTL2_NEXT_EP(x)                            (((x)&0xFu)<<11)              /**< Set UsbDIEPCTL2NextEp in register */
#define  GET_USB_DIEPCTL2_NEXT_EP(reg)                      (((reg)>>11)&0xFu)            /**< Get UsbDIEPCTL2NextEp from register */
#define  USB_DIEPCTL2_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDIEPCTL2USBActEP */
#define  USB_DIEPCTL2_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDIEPCTL2USBActEP */
#define  USB_DIEPCTL2_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL2USBActEP */
#define  USB_DIEPCTL2_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDIEPCTL2USBActEP in register */
#define  GET_USB_DIEPCTL2_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDIEPCTL2USBActEP from register */
#define  USB_DIEPCTL2_DPID_SHIFT                            16                            /**< Shift for UsbDIEPCTL2DPID */
#define  USB_DIEPCTL2_DPID_MASK                             0x00010000u                   /**< Mask for UsbDIEPCTL2DPID */
#define  USB_DIEPCTL2_DPID_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL2DPID */
#define  USB_DIEPCTL2_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDIEPCTL2DPID in register */
#define  GET_USB_DIEPCTL2_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDIEPCTL2DPID from register */
#define  USB_DIEPCTL2_NAKSTS_SHIFT                          17                            /**< Shift for UsbDIEPCTL2NAKSts */
#define  USB_DIEPCTL2_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDIEPCTL2NAKSts */
#define  USB_DIEPCTL2_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDIEPCTL2NAKSts */
#define  USB_DIEPCTL2_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDIEPCTL2NAKSts in register */
#define  GET_USB_DIEPCTL2_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDIEPCTL2NAKSts from register */
#define  USB_DIEPCTL2_EPTYPE_SHIFT                          18                            /**< Shift for UsbDIEPCTL2EPType */
#define  USB_DIEPCTL2_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDIEPCTL2EPType */
#define  USB_DIEPCTL2_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDIEPCTL2EPType */
#define  USB_DIEPCTL2_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDIEPCTL2EPType in register */
#define  GET_USB_DIEPCTL2_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDIEPCTL2EPType from register */
#define  USB_DIEPCTL2_STALL_SHIFT                           21                            /**< Shift for UsbDIEPCTL2Stall */
#define  USB_DIEPCTL2_STALL_MASK                            0x00200000u                   /**< Mask for UsbDIEPCTL2Stall */
#define  USB_DIEPCTL2_STALL_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL2Stall */
#define  USB_DIEPCTL2_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDIEPCTL2Stall in register */
#define  GET_USB_DIEPCTL2_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDIEPCTL2Stall from register */
#define  USB_DIEPCTL2_TX_FNUM_SHIFT                         22                            /**< Shift for UsbDIEPCTL2TxFNum */
#define  USB_DIEPCTL2_TX_FNUM_MASK                          0x03C00000u                   /**< Mask for UsbDIEPCTL2TxFNum */
#define  USB_DIEPCTL2_TX_FNUM_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL2TxFNum */
#define  USB_DIEPCTL2_TX_FNUM(x)                            (((x)&0xFu)<<22)              /**< Set UsbDIEPCTL2TxFNum in register */
#define  GET_USB_DIEPCTL2_TX_FNUM(reg)                      (((reg)>>22)&0xFu)            /**< Get UsbDIEPCTL2TxFNum from register */
#define  USB_DIEPCTL2_CNAK_SHIFT                            26                            /**< Shift for UsbDIEPCTL2CNAK */
#define  USB_DIEPCTL2_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDIEPCTL2CNAK */
#define  USB_DIEPCTL2_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL2CNAK */
#define  USB_DIEPCTL2_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDIEPCTL2CNAK in register */
#define  GET_USB_DIEPCTL2_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDIEPCTL2CNAK from register */
#define  USB_DIEPCTL2_SNAK_SHIFT                            27                            /**< Shift for UsbDIEPCTL2SNAK */
#define  USB_DIEPCTL2_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDIEPCTL2SNAK */
#define  USB_DIEPCTL2_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL2SNAK */
#define  USB_DIEPCTL2_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDIEPCTL2SNAK in register */
#define  GET_USB_DIEPCTL2_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDIEPCTL2SNAK from register */
#define  USB_DIEPCTL2_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDIEPCTL2SetD0PID */
#define  USB_DIEPCTL2_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDIEPCTL2SetD0PID */
#define  USB_DIEPCTL2_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL2SetD0PID */
#define  USB_DIEPCTL2_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDIEPCTL2SetD0PID in register */
#define  GET_USB_DIEPCTL2_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDIEPCTL2SetD0PID from register */
#define  USB_DIEPCTL2_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDIEPCTL2SetD1PID */
#define  USB_DIEPCTL2_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDIEPCTL2SetD1PID */
#define  USB_DIEPCTL2_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL2SetD1PID */
#define  USB_DIEPCTL2_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDIEPCTL2SetD1PID in register */
#define  GET_USB_DIEPCTL2_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDIEPCTL2SetD1PID from register */
#define  USB_DIEPCTL2_EPDIS_SHIFT                           30                            /**< Shift for UsbDIEPCTL2EPDis */
#define  USB_DIEPCTL2_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDIEPCTL2EPDis */
#define  USB_DIEPCTL2_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL2EPDis */
#define  USB_DIEPCTL2_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDIEPCTL2EPDis in register */
#define  GET_USB_DIEPCTL2_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDIEPCTL2EPDis from register */
#define  USB_DIEPCTL2_EPENA_SHIFT                           31                            /**< Shift for UsbDIEPCTL2EPEna */
#define  USB_DIEPCTL2_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDIEPCTL2EPEna */
#define  USB_DIEPCTL2_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL2EPEna */
#define  USB_DIEPCTL2_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDIEPCTL2EPEna in register */
#define  GET_USB_DIEPCTL2_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDIEPCTL2EPEna from register */
/** @} */


/**
 * @name RegUsbDIEPINT2
 * @{
 */
// RegUsbDIEPINT2.r32
#define  REG_USB_DIEPINT2_RESET_VALUE                       0x00000080u                   /**< Reset value of RegUsbDIEPINT2 */
#define  REG_USB_DIEPINT2_MASK                              0x00007AFBu                   /**< Mask for RegUsbDIEPINT2 */

#define  USB_DIEPINT2_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDIEPINT2XferCompl */
#define  USB_DIEPINT2_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDIEPINT2XferCompl */
#define  USB_DIEPINT2_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT2XferCompl */
#define  USB_DIEPINT2_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDIEPINT2XferCompl in register */
#define  GET_USB_DIEPINT2_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDIEPINT2XferCompl from register */
#define  USB_DIEPINT2_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDIEPINT2EPDisbld */
#define  USB_DIEPINT2_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDIEPINT2EPDisbld */
#define  USB_DIEPINT2_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT2EPDisbld */
#define  USB_DIEPINT2_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDIEPINT2EPDisbld in register */
#define  GET_USB_DIEPINT2_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDIEPINT2EPDisbld from register */
#define  USB_DIEPINT2_TIME_OUT_SHIFT                        3                             /**< Shift for UsbDIEPINT2TimeOUT */
#define  USB_DIEPINT2_TIME_OUT_MASK                         0x00000008u                   /**< Mask for UsbDIEPINT2TimeOUT */
#define  USB_DIEPINT2_TIME_OUT_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT2TimeOUT */
#define  USB_DIEPINT2_TIME_OUT(x)                           (((x)&0x1u)<<3)               /**< Set UsbDIEPINT2TimeOUT in register */
#define  GET_USB_DIEPINT2_TIME_OUT(reg)                     (((reg)>>3)&0x1u)             /**< Get UsbDIEPINT2TimeOUT from register */
#define  USB_DIEPINT2_INTKN_TXFEMP_SHIFT                    4                             /**< Shift for UsbDIEPINT2INTknTXFEmp */
#define  USB_DIEPINT2_INTKN_TXFEMP_MASK                     0x00000010u                   /**< Mask for UsbDIEPINT2INTknTXFEmp */
#define  USB_DIEPINT2_INTKN_TXFEMP_BMASK                    0x1u                          /**< Base mask for UsbDIEPINT2INTknTXFEmp */
#define  USB_DIEPINT2_INTKN_TXFEMP(x)                       (((x)&0x1u)<<4)               /**< Set UsbDIEPINT2INTknTXFEmp in register */
#define  GET_USB_DIEPINT2_INTKN_TXFEMP(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDIEPINT2INTknTXFEmp from register */
#define  USB_DIEPINT2_INTKN_EPMIS_SHIFT                     5                             /**< Shift for UsbDIEPINT2INTknEPMis */
#define  USB_DIEPINT2_INTKN_EPMIS_MASK                      0x00000020u                   /**< Mask for UsbDIEPINT2INTknEPMis */
#define  USB_DIEPINT2_INTKN_EPMIS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT2INTknEPMis */
#define  USB_DIEPINT2_INTKN_EPMIS(x)                        (((x)&0x1u)<<5)               /**< Set UsbDIEPINT2INTknEPMis in register */
#define  GET_USB_DIEPINT2_INTKN_EPMIS(reg)                  (((reg)>>5)&0x1u)             /**< Get UsbDIEPINT2INTknEPMis from register */
#define  USB_DIEPINT2_INEPNAK_EFF_SHIFT                     6                             /**< Shift for UsbDIEPINT2INEPNakEff */
#define  USB_DIEPINT2_INEPNAK_EFF_MASK                      0x00000040u                   /**< Mask for UsbDIEPINT2INEPNakEff */
#define  USB_DIEPINT2_INEPNAK_EFF_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT2INEPNakEff */
#define  USB_DIEPINT2_INEPNAK_EFF(x)                        (((x)&0x1u)<<6)               /**< Set UsbDIEPINT2INEPNakEff in register */
#define  GET_USB_DIEPINT2_INEPNAK_EFF(reg)                  (((reg)>>6)&0x1u)             /**< Get UsbDIEPINT2INEPNakEff from register */
#define  USB_DIEPINT2_TX_FEMP_SHIFT                         7                             /**< Shift for UsbDIEPINT2TxFEmp */
#define  USB_DIEPINT2_TX_FEMP_MASK                          0x00000080u                   /**< Mask for UsbDIEPINT2TxFEmp */
#define  USB_DIEPINT2_TX_FEMP_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT2TxFEmp */
#define  USB_DIEPINT2_TX_FEMP(x)                            (((x)&0x1u)<<7)               /**< Set UsbDIEPINT2TxFEmp in register */
#define  GET_USB_DIEPINT2_TX_FEMP(reg)                      (((reg)>>7)&0x1u)             /**< Get UsbDIEPINT2TxFEmp from register */
#define  USB_DIEPINT2_BNAINTR_SHIFT                         9                             /**< Shift for UsbDIEPINT2BNAIntr */
#define  USB_DIEPINT2_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDIEPINT2BNAIntr */
#define  USB_DIEPINT2_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT2BNAIntr */
#define  USB_DIEPINT2_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDIEPINT2BNAIntr in register */
#define  GET_USB_DIEPINT2_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDIEPINT2BNAIntr from register */
#define  USB_DIEPINT2_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDIEPINT2PktDrpSts */
#define  USB_DIEPINT2_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDIEPINT2PktDrpSts */
#define  USB_DIEPINT2_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT2PktDrpSts */
#define  USB_DIEPINT2_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDIEPINT2PktDrpSts in register */
#define  GET_USB_DIEPINT2_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDIEPINT2PktDrpSts from register */
#define  USB_DIEPINT2_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDIEPINT2BbleErr */
#define  USB_DIEPINT2_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDIEPINT2BbleErr */
#define  USB_DIEPINT2_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT2BbleErr */
#define  USB_DIEPINT2_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDIEPINT2BbleErr in register */
#define  GET_USB_DIEPINT2_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDIEPINT2BbleErr from register */
#define  USB_DIEPINT2_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDIEPINT2NAKIntrpt */
#define  USB_DIEPINT2_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDIEPINT2NAKIntrpt */
#define  USB_DIEPINT2_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDIEPINT2NAKIntrpt */
#define  USB_DIEPINT2_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDIEPINT2NAKIntrpt in register */
#define  GET_USB_DIEPINT2_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDIEPINT2NAKIntrpt from register */
#define  USB_DIEPINT2_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDIEPINT2NYETIntrpt */
#define  USB_DIEPINT2_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDIEPINT2NYETIntrpt */
#define  USB_DIEPINT2_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT2NYETIntrpt */
#define  USB_DIEPINT2_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDIEPINT2NYETIntrpt in register */
#define  GET_USB_DIEPINT2_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDIEPINT2NYETIntrpt from register */
/** @} */


/**
 * @name RegUsbDIEPTSIZ2
 * @{
 */
// RegUsbDIEPTSIZ2.r32
#define  REG_USB_DIEPTSIZ2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDIEPTSIZ2 */
#define  REG_USB_DIEPTSIZ2_MASK                             0x607807FFu                   /**< Mask for RegUsbDIEPTSIZ2 */

#define  USB_DIEPTSIZ2_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDIEPTSIZ2XferSize */
#define  USB_DIEPTSIZ2_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDIEPTSIZ2XferSize */
#define  USB_DIEPTSIZ2_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDIEPTSIZ2XferSize */
#define  USB_DIEPTSIZ2_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDIEPTSIZ2XferSize in register */
#define  GET_USB_DIEPTSIZ2_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPTSIZ2XferSize from register */
#define  USB_DIEPTSIZ2_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDIEPTSIZ2PktCnt */
#define  USB_DIEPTSIZ2_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDIEPTSIZ2PktCnt */
#define  USB_DIEPTSIZ2_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDIEPTSIZ2PktCnt */
#define  USB_DIEPTSIZ2_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDIEPTSIZ2PktCnt in register */
#define  GET_USB_DIEPTSIZ2_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDIEPTSIZ2PktCnt from register */
#define  USB_DIEPTSIZ2_MC_SHIFT                             29                            /**< Shift for UsbDIEPTSIZ2MC */
#define  USB_DIEPTSIZ2_MC_MASK                              0x60000000u                   /**< Mask for UsbDIEPTSIZ2MC */
#define  USB_DIEPTSIZ2_MC_BMASK                             0x3u                          /**< Base mask for UsbDIEPTSIZ2MC */
#define  USB_DIEPTSIZ2_MC(x)                                (((x)&0x3u)<<29)              /**< Set UsbDIEPTSIZ2MC in register */
#define  GET_USB_DIEPTSIZ2_MC(reg)                          (((reg)>>29)&0x3u)            /**< Get UsbDIEPTSIZ2MC from register */
/** @} */


/**
 * @name RegUsbDTXFSTS2
 * @{
 */
// RegUsbDTXFSTS2.r32
#define  REG_USB_DTXFSTS2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDTXFSTS2 */
#define  REG_USB_DTXFSTS2_MASK                              0x0000FFFFu                   /**< Mask for RegUsbDTXFSTS2 */

#define  USB_DTXFSTS2_INEPTX_FSPC_AVAIL_SHIFT               0                             /**< Shift for UsbDTXFSTS2INEPTxFSpcAvail */
#define  USB_DTXFSTS2_INEPTX_FSPC_AVAIL_MASK                0x0000FFFFu                   /**< Mask for UsbDTXFSTS2INEPTxFSpcAvail */
#define  USB_DTXFSTS2_INEPTX_FSPC_AVAIL_BMASK               0xFFFFu                       /**< Base mask for UsbDTXFSTS2INEPTxFSpcAvail */
#define  USB_DTXFSTS2_INEPTX_FSPC_AVAIL(x)                  (((x)&0xFFFFu)<<0)            /**< Set UsbDTXFSTS2INEPTxFSpcAvail in register */
#define  GET_USB_DTXFSTS2_INEPTX_FSPC_AVAIL(reg)            (((reg)>>0)&0xFFFFu)          /**< Get UsbDTXFSTS2INEPTxFSpcAvail from register */
/** @} */


/**
 * @name RegUsbDIEPCTL3
 * @{
 */
// RegUsbDIEPCTL3.r32
#define  REG_USB_DIEPCTL3_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDIEPCTL3 */
#define  REG_USB_DIEPCTL3_MASK                              0xFFEFFFFFu                   /**< Mask for RegUsbDIEPCTL3 */

#define  USB_DIEPCTL3_MPS_SHIFT                             0                             /**< Shift for UsbDIEPCTL3MPS */
#define  USB_DIEPCTL3_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDIEPCTL3MPS */
#define  USB_DIEPCTL3_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDIEPCTL3MPS */
#define  USB_DIEPCTL3_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDIEPCTL3MPS in register */
#define  GET_USB_DIEPCTL3_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPCTL3MPS from register */
#define  USB_DIEPCTL3_NEXT_EP_SHIFT                         11                            /**< Shift for UsbDIEPCTL3NextEp */
#define  USB_DIEPCTL3_NEXT_EP_MASK                          0x00007800u                   /**< Mask for UsbDIEPCTL3NextEp */
#define  USB_DIEPCTL3_NEXT_EP_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL3NextEp */
#define  USB_DIEPCTL3_NEXT_EP(x)                            (((x)&0xFu)<<11)              /**< Set UsbDIEPCTL3NextEp in register */
#define  GET_USB_DIEPCTL3_NEXT_EP(reg)                      (((reg)>>11)&0xFu)            /**< Get UsbDIEPCTL3NextEp from register */
#define  USB_DIEPCTL3_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDIEPCTL3USBActEP */
#define  USB_DIEPCTL3_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDIEPCTL3USBActEP */
#define  USB_DIEPCTL3_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL3USBActEP */
#define  USB_DIEPCTL3_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDIEPCTL3USBActEP in register */
#define  GET_USB_DIEPCTL3_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDIEPCTL3USBActEP from register */
#define  USB_DIEPCTL3_DPID_SHIFT                            16                            /**< Shift for UsbDIEPCTL3DPID */
#define  USB_DIEPCTL3_DPID_MASK                             0x00010000u                   /**< Mask for UsbDIEPCTL3DPID */
#define  USB_DIEPCTL3_DPID_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL3DPID */
#define  USB_DIEPCTL3_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDIEPCTL3DPID in register */
#define  GET_USB_DIEPCTL3_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDIEPCTL3DPID from register */
#define  USB_DIEPCTL3_NAKSTS_SHIFT                          17                            /**< Shift for UsbDIEPCTL3NAKSts */
#define  USB_DIEPCTL3_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDIEPCTL3NAKSts */
#define  USB_DIEPCTL3_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDIEPCTL3NAKSts */
#define  USB_DIEPCTL3_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDIEPCTL3NAKSts in register */
#define  GET_USB_DIEPCTL3_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDIEPCTL3NAKSts from register */
#define  USB_DIEPCTL3_EPTYPE_SHIFT                          18                            /**< Shift for UsbDIEPCTL3EPType */
#define  USB_DIEPCTL3_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDIEPCTL3EPType */
#define  USB_DIEPCTL3_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDIEPCTL3EPType */
#define  USB_DIEPCTL3_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDIEPCTL3EPType in register */
#define  GET_USB_DIEPCTL3_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDIEPCTL3EPType from register */
#define  USB_DIEPCTL3_STALL_SHIFT                           21                            /**< Shift for UsbDIEPCTL3Stall */
#define  USB_DIEPCTL3_STALL_MASK                            0x00200000u                   /**< Mask for UsbDIEPCTL3Stall */
#define  USB_DIEPCTL3_STALL_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL3Stall */
#define  USB_DIEPCTL3_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDIEPCTL3Stall in register */
#define  GET_USB_DIEPCTL3_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDIEPCTL3Stall from register */
#define  USB_DIEPCTL3_TX_FNUM_SHIFT                         22                            /**< Shift for UsbDIEPCTL3TxFNum */
#define  USB_DIEPCTL3_TX_FNUM_MASK                          0x03C00000u                   /**< Mask for UsbDIEPCTL3TxFNum */
#define  USB_DIEPCTL3_TX_FNUM_BMASK                         0xFu                          /**< Base mask for UsbDIEPCTL3TxFNum */
#define  USB_DIEPCTL3_TX_FNUM(x)                            (((x)&0xFu)<<22)              /**< Set UsbDIEPCTL3TxFNum in register */
#define  GET_USB_DIEPCTL3_TX_FNUM(reg)                      (((reg)>>22)&0xFu)            /**< Get UsbDIEPCTL3TxFNum from register */
#define  USB_DIEPCTL3_CNAK_SHIFT                            26                            /**< Shift for UsbDIEPCTL3CNAK */
#define  USB_DIEPCTL3_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDIEPCTL3CNAK */
#define  USB_DIEPCTL3_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL3CNAK */
#define  USB_DIEPCTL3_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDIEPCTL3CNAK in register */
#define  GET_USB_DIEPCTL3_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDIEPCTL3CNAK from register */
#define  USB_DIEPCTL3_SNAK_SHIFT                            27                            /**< Shift for UsbDIEPCTL3SNAK */
#define  USB_DIEPCTL3_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDIEPCTL3SNAK */
#define  USB_DIEPCTL3_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDIEPCTL3SNAK */
#define  USB_DIEPCTL3_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDIEPCTL3SNAK in register */
#define  GET_USB_DIEPCTL3_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDIEPCTL3SNAK from register */
#define  USB_DIEPCTL3_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDIEPCTL3SetD0PID */
#define  USB_DIEPCTL3_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDIEPCTL3SetD0PID */
#define  USB_DIEPCTL3_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL3SetD0PID */
#define  USB_DIEPCTL3_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDIEPCTL3SetD0PID in register */
#define  GET_USB_DIEPCTL3_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDIEPCTL3SetD0PID from register */
#define  USB_DIEPCTL3_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDIEPCTL3SetD1PID */
#define  USB_DIEPCTL3_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDIEPCTL3SetD1PID */
#define  USB_DIEPCTL3_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDIEPCTL3SetD1PID */
#define  USB_DIEPCTL3_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDIEPCTL3SetD1PID in register */
#define  GET_USB_DIEPCTL3_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDIEPCTL3SetD1PID from register */
#define  USB_DIEPCTL3_EPDIS_SHIFT                           30                            /**< Shift for UsbDIEPCTL3EPDis */
#define  USB_DIEPCTL3_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDIEPCTL3EPDis */
#define  USB_DIEPCTL3_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL3EPDis */
#define  USB_DIEPCTL3_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDIEPCTL3EPDis in register */
#define  GET_USB_DIEPCTL3_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDIEPCTL3EPDis from register */
#define  USB_DIEPCTL3_EPENA_SHIFT                           31                            /**< Shift for UsbDIEPCTL3EPEna */
#define  USB_DIEPCTL3_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDIEPCTL3EPEna */
#define  USB_DIEPCTL3_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDIEPCTL3EPEna */
#define  USB_DIEPCTL3_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDIEPCTL3EPEna in register */
#define  GET_USB_DIEPCTL3_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDIEPCTL3EPEna from register */
/** @} */


/**
 * @name RegUsbDIEPINT3
 * @{
 */
// RegUsbDIEPINT3.r32
#define  REG_USB_DIEPINT3_RESET_VALUE                       0x00000080u                   /**< Reset value of RegUsbDIEPINT3 */
#define  REG_USB_DIEPINT3_MASK                              0x00007AFBu                   /**< Mask for RegUsbDIEPINT3 */

#define  USB_DIEPINT3_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDIEPINT3XferCompl */
#define  USB_DIEPINT3_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDIEPINT3XferCompl */
#define  USB_DIEPINT3_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT3XferCompl */
#define  USB_DIEPINT3_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDIEPINT3XferCompl in register */
#define  GET_USB_DIEPINT3_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDIEPINT3XferCompl from register */
#define  USB_DIEPINT3_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDIEPINT3EPDisbld */
#define  USB_DIEPINT3_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDIEPINT3EPDisbld */
#define  USB_DIEPINT3_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT3EPDisbld */
#define  USB_DIEPINT3_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDIEPINT3EPDisbld in register */
#define  GET_USB_DIEPINT3_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDIEPINT3EPDisbld from register */
#define  USB_DIEPINT3_TIME_OUT_SHIFT                        3                             /**< Shift for UsbDIEPINT3TimeOUT */
#define  USB_DIEPINT3_TIME_OUT_MASK                         0x00000008u                   /**< Mask for UsbDIEPINT3TimeOUT */
#define  USB_DIEPINT3_TIME_OUT_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT3TimeOUT */
#define  USB_DIEPINT3_TIME_OUT(x)                           (((x)&0x1u)<<3)               /**< Set UsbDIEPINT3TimeOUT in register */
#define  GET_USB_DIEPINT3_TIME_OUT(reg)                     (((reg)>>3)&0x1u)             /**< Get UsbDIEPINT3TimeOUT from register */
#define  USB_DIEPINT3_INTKN_TXFEMP_SHIFT                    4                             /**< Shift for UsbDIEPINT3INTknTXFEmp */
#define  USB_DIEPINT3_INTKN_TXFEMP_MASK                     0x00000010u                   /**< Mask for UsbDIEPINT3INTknTXFEmp */
#define  USB_DIEPINT3_INTKN_TXFEMP_BMASK                    0x1u                          /**< Base mask for UsbDIEPINT3INTknTXFEmp */
#define  USB_DIEPINT3_INTKN_TXFEMP(x)                       (((x)&0x1u)<<4)               /**< Set UsbDIEPINT3INTknTXFEmp in register */
#define  GET_USB_DIEPINT3_INTKN_TXFEMP(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDIEPINT3INTknTXFEmp from register */
#define  USB_DIEPINT3_INTKN_EPMIS_SHIFT                     5                             /**< Shift for UsbDIEPINT3INTknEPMis */
#define  USB_DIEPINT3_INTKN_EPMIS_MASK                      0x00000020u                   /**< Mask for UsbDIEPINT3INTknEPMis */
#define  USB_DIEPINT3_INTKN_EPMIS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT3INTknEPMis */
#define  USB_DIEPINT3_INTKN_EPMIS(x)                        (((x)&0x1u)<<5)               /**< Set UsbDIEPINT3INTknEPMis in register */
#define  GET_USB_DIEPINT3_INTKN_EPMIS(reg)                  (((reg)>>5)&0x1u)             /**< Get UsbDIEPINT3INTknEPMis from register */
#define  USB_DIEPINT3_INEPNAK_EFF_SHIFT                     6                             /**< Shift for UsbDIEPINT3INEPNakEff */
#define  USB_DIEPINT3_INEPNAK_EFF_MASK                      0x00000040u                   /**< Mask for UsbDIEPINT3INEPNakEff */
#define  USB_DIEPINT3_INEPNAK_EFF_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT3INEPNakEff */
#define  USB_DIEPINT3_INEPNAK_EFF(x)                        (((x)&0x1u)<<6)               /**< Set UsbDIEPINT3INEPNakEff in register */
#define  GET_USB_DIEPINT3_INEPNAK_EFF(reg)                  (((reg)>>6)&0x1u)             /**< Get UsbDIEPINT3INEPNakEff from register */
#define  USB_DIEPINT3_TX_FEMP_SHIFT                         7                             /**< Shift for UsbDIEPINT3TxFEmp */
#define  USB_DIEPINT3_TX_FEMP_MASK                          0x00000080u                   /**< Mask for UsbDIEPINT3TxFEmp */
#define  USB_DIEPINT3_TX_FEMP_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT3TxFEmp */
#define  USB_DIEPINT3_TX_FEMP(x)                            (((x)&0x1u)<<7)               /**< Set UsbDIEPINT3TxFEmp in register */
#define  GET_USB_DIEPINT3_TX_FEMP(reg)                      (((reg)>>7)&0x1u)             /**< Get UsbDIEPINT3TxFEmp from register */
#define  USB_DIEPINT3_BNAINTR_SHIFT                         9                             /**< Shift for UsbDIEPINT3BNAIntr */
#define  USB_DIEPINT3_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDIEPINT3BNAIntr */
#define  USB_DIEPINT3_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDIEPINT3BNAIntr */
#define  USB_DIEPINT3_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDIEPINT3BNAIntr in register */
#define  GET_USB_DIEPINT3_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDIEPINT3BNAIntr from register */
#define  USB_DIEPINT3_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDIEPINT3PktDrpSts */
#define  USB_DIEPINT3_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDIEPINT3PktDrpSts */
#define  USB_DIEPINT3_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDIEPINT3PktDrpSts */
#define  USB_DIEPINT3_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDIEPINT3PktDrpSts in register */
#define  GET_USB_DIEPINT3_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDIEPINT3PktDrpSts from register */
#define  USB_DIEPINT3_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDIEPINT3BbleErr */
#define  USB_DIEPINT3_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDIEPINT3BbleErr */
#define  USB_DIEPINT3_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDIEPINT3BbleErr */
#define  USB_DIEPINT3_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDIEPINT3BbleErr in register */
#define  GET_USB_DIEPINT3_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDIEPINT3BbleErr from register */
#define  USB_DIEPINT3_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDIEPINT3NAKIntrpt */
#define  USB_DIEPINT3_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDIEPINT3NAKIntrpt */
#define  USB_DIEPINT3_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDIEPINT3NAKIntrpt */
#define  USB_DIEPINT3_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDIEPINT3NAKIntrpt in register */
#define  GET_USB_DIEPINT3_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDIEPINT3NAKIntrpt from register */
#define  USB_DIEPINT3_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDIEPINT3NYETIntrpt */
#define  USB_DIEPINT3_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDIEPINT3NYETIntrpt */
#define  USB_DIEPINT3_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDIEPINT3NYETIntrpt */
#define  USB_DIEPINT3_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDIEPINT3NYETIntrpt in register */
#define  GET_USB_DIEPINT3_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDIEPINT3NYETIntrpt from register */
/** @} */


/**
 * @name RegUsbDIEPTSIZ3
 * @{
 */
// RegUsbDIEPTSIZ3.r32
#define  REG_USB_DIEPTSIZ3_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDIEPTSIZ3 */
#define  REG_USB_DIEPTSIZ3_MASK                             0x607807FFu                   /**< Mask for RegUsbDIEPTSIZ3 */

#define  USB_DIEPTSIZ3_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDIEPTSIZ3XferSize */
#define  USB_DIEPTSIZ3_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDIEPTSIZ3XferSize */
#define  USB_DIEPTSIZ3_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDIEPTSIZ3XferSize */
#define  USB_DIEPTSIZ3_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDIEPTSIZ3XferSize in register */
#define  GET_USB_DIEPTSIZ3_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDIEPTSIZ3XferSize from register */
#define  USB_DIEPTSIZ3_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDIEPTSIZ3PktCnt */
#define  USB_DIEPTSIZ3_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDIEPTSIZ3PktCnt */
#define  USB_DIEPTSIZ3_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDIEPTSIZ3PktCnt */
#define  USB_DIEPTSIZ3_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDIEPTSIZ3PktCnt in register */
#define  GET_USB_DIEPTSIZ3_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDIEPTSIZ3PktCnt from register */
#define  USB_DIEPTSIZ3_MC_SHIFT                             29                            /**< Shift for UsbDIEPTSIZ3MC */
#define  USB_DIEPTSIZ3_MC_MASK                              0x60000000u                   /**< Mask for UsbDIEPTSIZ3MC */
#define  USB_DIEPTSIZ3_MC_BMASK                             0x3u                          /**< Base mask for UsbDIEPTSIZ3MC */
#define  USB_DIEPTSIZ3_MC(x)                                (((x)&0x3u)<<29)              /**< Set UsbDIEPTSIZ3MC in register */
#define  GET_USB_DIEPTSIZ3_MC(reg)                          (((reg)>>29)&0x3u)            /**< Get UsbDIEPTSIZ3MC from register */
/** @} */


/**
 * @name RegUsbDTXFSTS3
 * @{
 */
// RegUsbDTXFSTS3.r32
#define  REG_USB_DTXFSTS3_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDTXFSTS3 */
#define  REG_USB_DTXFSTS3_MASK                              0x0000FFFFu                   /**< Mask for RegUsbDTXFSTS3 */

#define  USB_DTXFSTS3_INEPTX_FSPC_AVAIL_SHIFT               0                             /**< Shift for UsbDTXFSTS3INEPTxFSpcAvail */
#define  USB_DTXFSTS3_INEPTX_FSPC_AVAIL_MASK                0x0000FFFFu                   /**< Mask for UsbDTXFSTS3INEPTxFSpcAvail */
#define  USB_DTXFSTS3_INEPTX_FSPC_AVAIL_BMASK               0xFFFFu                       /**< Base mask for UsbDTXFSTS3INEPTxFSpcAvail */
#define  USB_DTXFSTS3_INEPTX_FSPC_AVAIL(x)                  (((x)&0xFFFFu)<<0)            /**< Set UsbDTXFSTS3INEPTxFSpcAvail in register */
#define  GET_USB_DTXFSTS3_INEPTX_FSPC_AVAIL(reg)            (((reg)>>0)&0xFFFFu)          /**< Get UsbDTXFSTS3INEPTxFSpcAvail from register */
/** @} */


/**
 * @name RegUsbDOEPCTL0
 * @{
 */
// RegUsbDOEPCTL0.r32
#define  REG_USB_DOEPCTL0_RESET_VALUE                       0x00008000u                   /**< Reset value of RegUsbDOEPCTL0 */
#define  REG_USB_DOEPCTL0_MASK                              0xCC3E8003u                   /**< Mask for RegUsbDOEPCTL0 */

#define  USB_DOEPCTL0_MPS_SHIFT                             0                             /**< Shift for UsbDOEPCTL0MPS */
#define  USB_DOEPCTL0_MPS_MASK                              0x00000003u                   /**< Mask for UsbDOEPCTL0MPS */
#define  USB_DOEPCTL0_MPS_BMASK                             0x3u                          /**< Base mask for UsbDOEPCTL0MPS */
#define  USB_DOEPCTL0_MPS(x)                                (((x)&0x3u)<<0)               /**< Set UsbDOEPCTL0MPS in register */
#define  GET_USB_DOEPCTL0_MPS(reg)                          (((reg)>>0)&0x3u)             /**< Get UsbDOEPCTL0MPS from register */
#define  USB_DOEPCTL0_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDOEPCTL0USBActEP */
#define  USB_DOEPCTL0_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDOEPCTL0USBActEP */
#define  USB_DOEPCTL0_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL0USBActEP */
#define  USB_DOEPCTL0_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDOEPCTL0USBActEP in register */
#define  GET_USB_DOEPCTL0_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDOEPCTL0USBActEP from register */
#define  USB_DOEPCTL0_NAKSTS_SHIFT                          17                            /**< Shift for UsbDOEPCTL0NAKSts */
#define  USB_DOEPCTL0_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDOEPCTL0NAKSts */
#define  USB_DOEPCTL0_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDOEPCTL0NAKSts */
#define  USB_DOEPCTL0_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDOEPCTL0NAKSts in register */
#define  GET_USB_DOEPCTL0_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDOEPCTL0NAKSts from register */
#define  USB_DOEPCTL0_EPTYPE_SHIFT                          18                            /**< Shift for UsbDOEPCTL0EPType */
#define  USB_DOEPCTL0_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDOEPCTL0EPType */
#define  USB_DOEPCTL0_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDOEPCTL0EPType */
#define  USB_DOEPCTL0_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDOEPCTL0EPType in register */
#define  GET_USB_DOEPCTL0_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDOEPCTL0EPType from register */
#define  USB_DOEPCTL0_SNP_SHIFT                             20                            /**< Shift for UsbDOEPCTL0Snp */
#define  USB_DOEPCTL0_SNP_MASK                              0x00100000u                   /**< Mask for UsbDOEPCTL0Snp */
#define  USB_DOEPCTL0_SNP_BMASK                             0x1u                          /**< Base mask for UsbDOEPCTL0Snp */
#define  USB_DOEPCTL0_SNP(x)                                (((x)&0x1u)<<20)              /**< Set UsbDOEPCTL0Snp in register */
#define  GET_USB_DOEPCTL0_SNP(reg)                          (((reg)>>20)&0x1u)            /**< Get UsbDOEPCTL0Snp from register */
#define  USB_DOEPCTL0_STALL_SHIFT                           21                            /**< Shift for UsbDOEPCTL0Stall */
#define  USB_DOEPCTL0_STALL_MASK                            0x00200000u                   /**< Mask for UsbDOEPCTL0Stall */
#define  USB_DOEPCTL0_STALL_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL0Stall */
#define  USB_DOEPCTL0_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDOEPCTL0Stall in register */
#define  GET_USB_DOEPCTL0_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDOEPCTL0Stall from register */
#define  USB_DOEPCTL0_CNAK_SHIFT                            26                            /**< Shift for UsbDOEPCTL0CNAK */
#define  USB_DOEPCTL0_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDOEPCTL0CNAK */
#define  USB_DOEPCTL0_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL0CNAK */
#define  USB_DOEPCTL0_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDOEPCTL0CNAK in register */
#define  GET_USB_DOEPCTL0_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDOEPCTL0CNAK from register */
#define  USB_DOEPCTL0_SNAK_SHIFT                            27                            /**< Shift for UsbDOEPCTL0SNAK */
#define  USB_DOEPCTL0_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDOEPCTL0SNAK */
#define  USB_DOEPCTL0_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL0SNAK */
#define  USB_DOEPCTL0_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDOEPCTL0SNAK in register */
#define  GET_USB_DOEPCTL0_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDOEPCTL0SNAK from register */
#define  USB_DOEPCTL0_EPDIS_SHIFT                           30                            /**< Shift for UsbDOEPCTL0EPDis */
#define  USB_DOEPCTL0_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDOEPCTL0EPDis */
#define  USB_DOEPCTL0_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL0EPDis */
#define  USB_DOEPCTL0_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDOEPCTL0EPDis in register */
#define  GET_USB_DOEPCTL0_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDOEPCTL0EPDis from register */
#define  USB_DOEPCTL0_EPENA_SHIFT                           31                            /**< Shift for UsbDOEPCTL0EPEna */
#define  USB_DOEPCTL0_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDOEPCTL0EPEna */
#define  USB_DOEPCTL0_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL0EPEna */
#define  USB_DOEPCTL0_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDOEPCTL0EPEna in register */
#define  GET_USB_DOEPCTL0_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDOEPCTL0EPEna from register */
/** @} */


/**
 * @name RegUsbDOEPINT0
 * @{
 */
// RegUsbDOEPINT0.r32
#define  REG_USB_DOEPINT0_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPINT0 */
#define  REG_USB_DOEPINT0_MASK                              0x0000FA7Fu                   /**< Mask for RegUsbDOEPINT0 */

#define  USB_DOEPINT0_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDOEPINT0XferCompl */
#define  USB_DOEPINT0_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDOEPINT0XferCompl */
#define  USB_DOEPINT0_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT0XferCompl */
#define  USB_DOEPINT0_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDOEPINT0XferCompl in register */
#define  GET_USB_DOEPINT0_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDOEPINT0XferCompl from register */
#define  USB_DOEPINT0_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDOEPINT0EPDisbld */
#define  USB_DOEPINT0_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDOEPINT0EPDisbld */
#define  USB_DOEPINT0_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT0EPDisbld */
#define  USB_DOEPINT0_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDOEPINT0EPDisbld in register */
#define  GET_USB_DOEPINT0_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDOEPINT0EPDisbld from register */
#define  USB_DOEPINT0_AHBERR_SHIFT                          2                             /**< Shift for UsbDOEPINT0AHBErr */
#define  USB_DOEPINT0_AHBERR_MASK                           0x00000004u                   /**< Mask for UsbDOEPINT0AHBErr */
#define  USB_DOEPINT0_AHBERR_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT0AHBErr */
#define  USB_DOEPINT0_AHBERR(x)                             (((x)&0x1u)<<2)               /**< Set UsbDOEPINT0AHBErr in register */
#define  GET_USB_DOEPINT0_AHBERR(reg)                       (((reg)>>2)&0x1u)             /**< Get UsbDOEPINT0AHBErr from register */
#define  USB_DOEPINT0_SET_UP_SHIFT                          3                             /**< Shift for UsbDOEPINT0SetUp */
#define  USB_DOEPINT0_SET_UP_MASK                           0x00000008u                   /**< Mask for UsbDOEPINT0SetUp */
#define  USB_DOEPINT0_SET_UP_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT0SetUp */
#define  USB_DOEPINT0_SET_UP(x)                             (((x)&0x1u)<<3)               /**< Set UsbDOEPINT0SetUp in register */
#define  GET_USB_DOEPINT0_SET_UP(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbDOEPINT0SetUp from register */
#define  USB_DOEPINT0_OUTTKN_EPDIS_SHIFT                    4                             /**< Shift for UsbDOEPINT0OUTTknEPdis */
#define  USB_DOEPINT0_OUTTKN_EPDIS_MASK                     0x00000010u                   /**< Mask for UsbDOEPINT0OUTTknEPdis */
#define  USB_DOEPINT0_OUTTKN_EPDIS_BMASK                    0x1u                          /**< Base mask for UsbDOEPINT0OUTTknEPdis */
#define  USB_DOEPINT0_OUTTKN_EPDIS(x)                       (((x)&0x1u)<<4)               /**< Set UsbDOEPINT0OUTTknEPdis in register */
#define  GET_USB_DOEPINT0_OUTTKN_EPDIS(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDOEPINT0OUTTknEPdis from register */
#define  USB_DOEPINT0_STS_PHSE_RCVD_SHIFT                   5                             /**< Shift for UsbDOEPINT0StsPhseRcvd */
#define  USB_DOEPINT0_STS_PHSE_RCVD_MASK                    0x00000020u                   /**< Mask for UsbDOEPINT0StsPhseRcvd */
#define  USB_DOEPINT0_STS_PHSE_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT0StsPhseRcvd */
#define  USB_DOEPINT0_STS_PHSE_RCVD(x)                      (((x)&0x1u)<<5)               /**< Set UsbDOEPINT0StsPhseRcvd in register */
#define  GET_USB_DOEPINT0_STS_PHSE_RCVD(reg)                (((reg)>>5)&0x1u)             /**< Get UsbDOEPINT0StsPhseRcvd from register */
#define  USB_DOEPINT0_BACK2BACK_SETUP_SHIFT                 6                             /**< Shift for UsbDOEPINT0Back2BackSETup */
#define  USB_DOEPINT0_BACK2BACK_SETUP_MASK                  0x00000040u                   /**< Mask for UsbDOEPINT0Back2BackSETup */
#define  USB_DOEPINT0_BACK2BACK_SETUP_BMASK                 0x1u                          /**< Base mask for UsbDOEPINT0Back2BackSETup */
#define  USB_DOEPINT0_BACK2BACK_SETUP(x)                    (((x)&0x1u)<<6)               /**< Set UsbDOEPINT0Back2BackSETup in register */
#define  GET_USB_DOEPINT0_BACK2BACK_SETUP(reg)              (((reg)>>6)&0x1u)             /**< Get UsbDOEPINT0Back2BackSETup from register */
#define  USB_DOEPINT0_BNAINTR_SHIFT                         9                             /**< Shift for UsbDOEPINT0BNAIntr */
#define  USB_DOEPINT0_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDOEPINT0BNAIntr */
#define  USB_DOEPINT0_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDOEPINT0BNAIntr */
#define  USB_DOEPINT0_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDOEPINT0BNAIntr in register */
#define  GET_USB_DOEPINT0_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDOEPINT0BNAIntr from register */
#define  USB_DOEPINT0_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDOEPINT0PktDrpSts */
#define  USB_DOEPINT0_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDOEPINT0PktDrpSts */
#define  USB_DOEPINT0_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDOEPINT0PktDrpSts */
#define  USB_DOEPINT0_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDOEPINT0PktDrpSts in register */
#define  GET_USB_DOEPINT0_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDOEPINT0PktDrpSts from register */
#define  USB_DOEPINT0_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDOEPINT0BbleErr */
#define  USB_DOEPINT0_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDOEPINT0BbleErr */
#define  USB_DOEPINT0_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT0BbleErr */
#define  USB_DOEPINT0_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDOEPINT0BbleErr in register */
#define  GET_USB_DOEPINT0_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDOEPINT0BbleErr from register */
#define  USB_DOEPINT0_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDOEPINT0NAKIntrpt */
#define  USB_DOEPINT0_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDOEPINT0NAKIntrpt */
#define  USB_DOEPINT0_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDOEPINT0NAKIntrpt */
#define  USB_DOEPINT0_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDOEPINT0NAKIntrpt in register */
#define  GET_USB_DOEPINT0_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDOEPINT0NAKIntrpt from register */
#define  USB_DOEPINT0_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDOEPINT0NYETIntrpt */
#define  USB_DOEPINT0_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDOEPINT0NYETIntrpt */
#define  USB_DOEPINT0_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT0NYETIntrpt */
#define  USB_DOEPINT0_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDOEPINT0NYETIntrpt in register */
#define  GET_USB_DOEPINT0_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDOEPINT0NYETIntrpt from register */
#define  USB_DOEPINT0_STUP_PKT_RCVD_SHIFT                   15                            /**< Shift for UsbDOEPINT0StupPktRcvd */
#define  USB_DOEPINT0_STUP_PKT_RCVD_MASK                    0x00008000u                   /**< Mask for UsbDOEPINT0StupPktRcvd */
#define  USB_DOEPINT0_STUP_PKT_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT0StupPktRcvd */
#define  USB_DOEPINT0_STUP_PKT_RCVD(x)                      (((x)&0x1u)<<15)              /**< Set UsbDOEPINT0StupPktRcvd in register */
#define  GET_USB_DOEPINT0_STUP_PKT_RCVD(reg)                (((reg)>>15)&0x1u)            /**< Get UsbDOEPINT0StupPktRcvd from register */
/** @} */


/**
 * @name RegUsbDOEPTSIZ0
 * @{
 */
// RegUsbDOEPTSIZ0.r32
#define  REG_USB_DOEPTSIZ0_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDOEPTSIZ0 */
#define  REG_USB_DOEPTSIZ0_MASK                             0x6008007Fu                   /**< Mask for RegUsbDOEPTSIZ0 */

#define  USB_DOEPTSIZ0_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDOEPTSIZ0XferSize */
#define  USB_DOEPTSIZ0_XFER_SIZE_MASK                       0x0000007Fu                   /**< Mask for UsbDOEPTSIZ0XferSize */
#define  USB_DOEPTSIZ0_XFER_SIZE_BMASK                      0x7Fu                         /**< Base mask for UsbDOEPTSIZ0XferSize */
#define  USB_DOEPTSIZ0_XFER_SIZE(x)                         (((x)&0x7Fu)<<0)              /**< Set UsbDOEPTSIZ0XferSize in register */
#define  GET_USB_DOEPTSIZ0_XFER_SIZE(reg)                   (((reg)>>0)&0x7Fu)            /**< Get UsbDOEPTSIZ0XferSize from register */
#define  USB_DOEPTSIZ0_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDOEPTSIZ0PktCnt */
#define  USB_DOEPTSIZ0_PKT_CNT_MASK                         0x00080000u                   /**< Mask for UsbDOEPTSIZ0PktCnt */
#define  USB_DOEPTSIZ0_PKT_CNT_BMASK                        0x1u                          /**< Base mask for UsbDOEPTSIZ0PktCnt */
#define  USB_DOEPTSIZ0_PKT_CNT(x)                           (((x)&0x1u)<<19)              /**< Set UsbDOEPTSIZ0PktCnt in register */
#define  GET_USB_DOEPTSIZ0_PKT_CNT(reg)                     (((reg)>>19)&0x1u)            /**< Get UsbDOEPTSIZ0PktCnt from register */
#define  USB_DOEPTSIZ0_SUPCNT_SHIFT                         29                            /**< Shift for UsbDOEPTSIZ0SUPCnt */
#define  USB_DOEPTSIZ0_SUPCNT_MASK                          0x60000000u                   /**< Mask for UsbDOEPTSIZ0SUPCnt */
#define  USB_DOEPTSIZ0_SUPCNT_BMASK                         0x3u                          /**< Base mask for UsbDOEPTSIZ0SUPCnt */
#define  USB_DOEPTSIZ0_SUPCNT(x)                            (((x)&0x3u)<<29)              /**< Set UsbDOEPTSIZ0SUPCnt in register */
#define  GET_USB_DOEPTSIZ0_SUPCNT(reg)                      (((reg)>>29)&0x3u)            /**< Get UsbDOEPTSIZ0SUPCnt from register */
/** @} */


/**
 * @name RegUsbDOEPCTL1
 * @{
 */
// RegUsbDOEPCTL1.r32
#define  REG_USB_DOEPCTL1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPCTL1 */
#define  REG_USB_DOEPCTL1_MASK                              0xFC3F87FFu                   /**< Mask for RegUsbDOEPCTL1 */

#define  USB_DOEPCTL1_MPS_SHIFT                             0                             /**< Shift for UsbDOEPCTL1MPS */
#define  USB_DOEPCTL1_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDOEPCTL1MPS */
#define  USB_DOEPCTL1_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDOEPCTL1MPS */
#define  USB_DOEPCTL1_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDOEPCTL1MPS in register */
#define  GET_USB_DOEPCTL1_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPCTL1MPS from register */
#define  USB_DOEPCTL1_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDOEPCTL1USBActEP */
#define  USB_DOEPCTL1_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDOEPCTL1USBActEP */
#define  USB_DOEPCTL1_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL1USBActEP */
#define  USB_DOEPCTL1_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDOEPCTL1USBActEP in register */
#define  GET_USB_DOEPCTL1_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDOEPCTL1USBActEP from register */
#define  USB_DOEPCTL1_DPID_SHIFT                            16                            /**< Shift for UsbDOEPCTL1DPID */
#define  USB_DOEPCTL1_DPID_MASK                             0x00010000u                   /**< Mask for UsbDOEPCTL1DPID */
#define  USB_DOEPCTL1_DPID_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL1DPID */
#define  USB_DOEPCTL1_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDOEPCTL1DPID in register */
#define  GET_USB_DOEPCTL1_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDOEPCTL1DPID from register */
#define  USB_DOEPCTL1_NAKSTS_SHIFT                          17                            /**< Shift for UsbDOEPCTL1NAKSts */
#define  USB_DOEPCTL1_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDOEPCTL1NAKSts */
#define  USB_DOEPCTL1_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDOEPCTL1NAKSts */
#define  USB_DOEPCTL1_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDOEPCTL1NAKSts in register */
#define  GET_USB_DOEPCTL1_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDOEPCTL1NAKSts from register */
#define  USB_DOEPCTL1_EPTYPE_SHIFT                          18                            /**< Shift for UsbDOEPCTL1EPType */
#define  USB_DOEPCTL1_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDOEPCTL1EPType */
#define  USB_DOEPCTL1_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDOEPCTL1EPType */
#define  USB_DOEPCTL1_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDOEPCTL1EPType in register */
#define  GET_USB_DOEPCTL1_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDOEPCTL1EPType from register */
#define  USB_DOEPCTL1_SNP_SHIFT                             20                            /**< Shift for UsbDOEPCTL1Snp */
#define  USB_DOEPCTL1_SNP_MASK                              0x00100000u                   /**< Mask for UsbDOEPCTL1Snp */
#define  USB_DOEPCTL1_SNP_BMASK                             0x1u                          /**< Base mask for UsbDOEPCTL1Snp */
#define  USB_DOEPCTL1_SNP(x)                                (((x)&0x1u)<<20)              /**< Set UsbDOEPCTL1Snp in register */
#define  GET_USB_DOEPCTL1_SNP(reg)                          (((reg)>>20)&0x1u)            /**< Get UsbDOEPCTL1Snp from register */
#define  USB_DOEPCTL1_STALL_SHIFT                           21                            /**< Shift for UsbDOEPCTL1Stall */
#define  USB_DOEPCTL1_STALL_MASK                            0x00200000u                   /**< Mask for UsbDOEPCTL1Stall */
#define  USB_DOEPCTL1_STALL_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL1Stall */
#define  USB_DOEPCTL1_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDOEPCTL1Stall in register */
#define  GET_USB_DOEPCTL1_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDOEPCTL1Stall from register */
#define  USB_DOEPCTL1_CNAK_SHIFT                            26                            /**< Shift for UsbDOEPCTL1CNAK */
#define  USB_DOEPCTL1_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDOEPCTL1CNAK */
#define  USB_DOEPCTL1_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL1CNAK */
#define  USB_DOEPCTL1_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDOEPCTL1CNAK in register */
#define  GET_USB_DOEPCTL1_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDOEPCTL1CNAK from register */
#define  USB_DOEPCTL1_SNAK_SHIFT                            27                            /**< Shift for UsbDOEPCTL1SNAK */
#define  USB_DOEPCTL1_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDOEPCTL1SNAK */
#define  USB_DOEPCTL1_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL1SNAK */
#define  USB_DOEPCTL1_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDOEPCTL1SNAK in register */
#define  GET_USB_DOEPCTL1_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDOEPCTL1SNAK from register */
#define  USB_DOEPCTL1_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDOEPCTL1SetD0PID */
#define  USB_DOEPCTL1_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDOEPCTL1SetD0PID */
#define  USB_DOEPCTL1_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL1SetD0PID */
#define  USB_DOEPCTL1_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDOEPCTL1SetD0PID in register */
#define  GET_USB_DOEPCTL1_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDOEPCTL1SetD0PID from register */
#define  USB_DOEPCTL1_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDOEPCTL1SetD1PID */
#define  USB_DOEPCTL1_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDOEPCTL1SetD1PID */
#define  USB_DOEPCTL1_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL1SetD1PID */
#define  USB_DOEPCTL1_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDOEPCTL1SetD1PID in register */
#define  GET_USB_DOEPCTL1_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDOEPCTL1SetD1PID from register */
#define  USB_DOEPCTL1_EPDIS_SHIFT                           30                            /**< Shift for UsbDOEPCTL1EPDis */
#define  USB_DOEPCTL1_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDOEPCTL1EPDis */
#define  USB_DOEPCTL1_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL1EPDis */
#define  USB_DOEPCTL1_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDOEPCTL1EPDis in register */
#define  GET_USB_DOEPCTL1_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDOEPCTL1EPDis from register */
#define  USB_DOEPCTL1_EPENA_SHIFT                           31                            /**< Shift for UsbDOEPCTL1EPEna */
#define  USB_DOEPCTL1_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDOEPCTL1EPEna */
#define  USB_DOEPCTL1_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL1EPEna */
#define  USB_DOEPCTL1_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDOEPCTL1EPEna in register */
#define  GET_USB_DOEPCTL1_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDOEPCTL1EPEna from register */
/** @} */


/**
 * @name RegUsbDOEPINT1
 * @{
 */
// RegUsbDOEPINT1.r32
#define  REG_USB_DOEPINT1_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPINT1 */
#define  REG_USB_DOEPINT1_MASK                              0x0000FA7Fu                   /**< Mask for RegUsbDOEPINT1 */

#define  USB_DOEPINT1_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDOEPINT1XferCompl */
#define  USB_DOEPINT1_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDOEPINT1XferCompl */
#define  USB_DOEPINT1_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT1XferCompl */
#define  USB_DOEPINT1_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDOEPINT1XferCompl in register */
#define  GET_USB_DOEPINT1_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDOEPINT1XferCompl from register */
#define  USB_DOEPINT1_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDOEPINT1EPDisbld */
#define  USB_DOEPINT1_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDOEPINT1EPDisbld */
#define  USB_DOEPINT1_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT1EPDisbld */
#define  USB_DOEPINT1_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDOEPINT1EPDisbld in register */
#define  GET_USB_DOEPINT1_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDOEPINT1EPDisbld from register */
#define  USB_DOEPINT1_AHBERR_SHIFT                          2                             /**< Shift for UsbDOEPINT1AHBErr */
#define  USB_DOEPINT1_AHBERR_MASK                           0x00000004u                   /**< Mask for UsbDOEPINT1AHBErr */
#define  USB_DOEPINT1_AHBERR_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT1AHBErr */
#define  USB_DOEPINT1_AHBERR(x)                             (((x)&0x1u)<<2)               /**< Set UsbDOEPINT1AHBErr in register */
#define  GET_USB_DOEPINT1_AHBERR(reg)                       (((reg)>>2)&0x1u)             /**< Get UsbDOEPINT1AHBErr from register */
#define  USB_DOEPINT1_SET_UP_SHIFT                          3                             /**< Shift for UsbDOEPINT1SetUp */
#define  USB_DOEPINT1_SET_UP_MASK                           0x00000008u                   /**< Mask for UsbDOEPINT1SetUp */
#define  USB_DOEPINT1_SET_UP_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT1SetUp */
#define  USB_DOEPINT1_SET_UP(x)                             (((x)&0x1u)<<3)               /**< Set UsbDOEPINT1SetUp in register */
#define  GET_USB_DOEPINT1_SET_UP(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbDOEPINT1SetUp from register */
#define  USB_DOEPINT1_OUTTKN_EPDIS_SHIFT                    4                             /**< Shift for UsbDOEPINT1OUTTknEPdis */
#define  USB_DOEPINT1_OUTTKN_EPDIS_MASK                     0x00000010u                   /**< Mask for UsbDOEPINT1OUTTknEPdis */
#define  USB_DOEPINT1_OUTTKN_EPDIS_BMASK                    0x1u                          /**< Base mask for UsbDOEPINT1OUTTknEPdis */
#define  USB_DOEPINT1_OUTTKN_EPDIS(x)                       (((x)&0x1u)<<4)               /**< Set UsbDOEPINT1OUTTknEPdis in register */
#define  GET_USB_DOEPINT1_OUTTKN_EPDIS(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDOEPINT1OUTTknEPdis from register */
#define  USB_DOEPINT1_STS_PHSE_RCVD_SHIFT                   5                             /**< Shift for UsbDOEPINT1StsPhseRcvd */
#define  USB_DOEPINT1_STS_PHSE_RCVD_MASK                    0x00000020u                   /**< Mask for UsbDOEPINT1StsPhseRcvd */
#define  USB_DOEPINT1_STS_PHSE_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT1StsPhseRcvd */
#define  USB_DOEPINT1_STS_PHSE_RCVD(x)                      (((x)&0x1u)<<5)               /**< Set UsbDOEPINT1StsPhseRcvd in register */
#define  GET_USB_DOEPINT1_STS_PHSE_RCVD(reg)                (((reg)>>5)&0x1u)             /**< Get UsbDOEPINT1StsPhseRcvd from register */
#define  USB_DOEPINT1_BACK2BACK_SETUP_SHIFT                 6                             /**< Shift for UsbDOEPINT1Back2BackSETup */
#define  USB_DOEPINT1_BACK2BACK_SETUP_MASK                  0x00000040u                   /**< Mask for UsbDOEPINT1Back2BackSETup */
#define  USB_DOEPINT1_BACK2BACK_SETUP_BMASK                 0x1u                          /**< Base mask for UsbDOEPINT1Back2BackSETup */
#define  USB_DOEPINT1_BACK2BACK_SETUP(x)                    (((x)&0x1u)<<6)               /**< Set UsbDOEPINT1Back2BackSETup in register */
#define  GET_USB_DOEPINT1_BACK2BACK_SETUP(reg)              (((reg)>>6)&0x1u)             /**< Get UsbDOEPINT1Back2BackSETup from register */
#define  USB_DOEPINT1_BNAINTR_SHIFT                         9                             /**< Shift for UsbDOEPINT1BNAIntr */
#define  USB_DOEPINT1_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDOEPINT1BNAIntr */
#define  USB_DOEPINT1_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDOEPINT1BNAIntr */
#define  USB_DOEPINT1_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDOEPINT1BNAIntr in register */
#define  GET_USB_DOEPINT1_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDOEPINT1BNAIntr from register */
#define  USB_DOEPINT1_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDOEPINT1PktDrpSts */
#define  USB_DOEPINT1_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDOEPINT1PktDrpSts */
#define  USB_DOEPINT1_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDOEPINT1PktDrpSts */
#define  USB_DOEPINT1_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDOEPINT1PktDrpSts in register */
#define  GET_USB_DOEPINT1_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDOEPINT1PktDrpSts from register */
#define  USB_DOEPINT1_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDOEPINT1BbleErr */
#define  USB_DOEPINT1_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDOEPINT1BbleErr */
#define  USB_DOEPINT1_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT1BbleErr */
#define  USB_DOEPINT1_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDOEPINT1BbleErr in register */
#define  GET_USB_DOEPINT1_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDOEPINT1BbleErr from register */
#define  USB_DOEPINT1_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDOEPINT1NAKIntrpt */
#define  USB_DOEPINT1_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDOEPINT1NAKIntrpt */
#define  USB_DOEPINT1_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDOEPINT1NAKIntrpt */
#define  USB_DOEPINT1_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDOEPINT1NAKIntrpt in register */
#define  GET_USB_DOEPINT1_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDOEPINT1NAKIntrpt from register */
#define  USB_DOEPINT1_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDOEPINT1NYETIntrpt */
#define  USB_DOEPINT1_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDOEPINT1NYETIntrpt */
#define  USB_DOEPINT1_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT1NYETIntrpt */
#define  USB_DOEPINT1_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDOEPINT1NYETIntrpt in register */
#define  GET_USB_DOEPINT1_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDOEPINT1NYETIntrpt from register */
#define  USB_DOEPINT1_STUP_PKT_RCVD_SHIFT                   15                            /**< Shift for UsbDOEPINT1StupPktRcvd */
#define  USB_DOEPINT1_STUP_PKT_RCVD_MASK                    0x00008000u                   /**< Mask for UsbDOEPINT1StupPktRcvd */
#define  USB_DOEPINT1_STUP_PKT_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT1StupPktRcvd */
#define  USB_DOEPINT1_STUP_PKT_RCVD(x)                      (((x)&0x1u)<<15)              /**< Set UsbDOEPINT1StupPktRcvd in register */
#define  GET_USB_DOEPINT1_STUP_PKT_RCVD(reg)                (((reg)>>15)&0x1u)            /**< Get UsbDOEPINT1StupPktRcvd from register */
/** @} */


/**
 * @name RegUsbDOEPTSIZ1
 * @{
 */
// RegUsbDOEPTSIZ1.r32
#define  REG_USB_DOEPTSIZ1_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDOEPTSIZ1 */
#define  REG_USB_DOEPTSIZ1_MASK                             0x607807FFu                   /**< Mask for RegUsbDOEPTSIZ1 */

#define  USB_DOEPTSIZ1_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDOEPTSIZ1XferSize */
#define  USB_DOEPTSIZ1_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDOEPTSIZ1XferSize */
#define  USB_DOEPTSIZ1_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDOEPTSIZ1XferSize */
#define  USB_DOEPTSIZ1_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDOEPTSIZ1XferSize in register */
#define  GET_USB_DOEPTSIZ1_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPTSIZ1XferSize from register */
#define  USB_DOEPTSIZ1_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDOEPTSIZ1PktCnt */
#define  USB_DOEPTSIZ1_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDOEPTSIZ1PktCnt */
#define  USB_DOEPTSIZ1_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDOEPTSIZ1PktCnt */
#define  USB_DOEPTSIZ1_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDOEPTSIZ1PktCnt in register */
#define  GET_USB_DOEPTSIZ1_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDOEPTSIZ1PktCnt from register */
#define  USB_DOEPTSIZ1_RX_DPID_SHIFT                        29                            /**< Shift for UsbDOEPTSIZ1RxDPID */
#define  USB_DOEPTSIZ1_RX_DPID_MASK                         0x60000000u                   /**< Mask for UsbDOEPTSIZ1RxDPID */
#define  USB_DOEPTSIZ1_RX_DPID_BMASK                        0x3u                          /**< Base mask for UsbDOEPTSIZ1RxDPID */
#define  USB_DOEPTSIZ1_RX_DPID(x)                           (((x)&0x3u)<<29)              /**< Set UsbDOEPTSIZ1RxDPID in register */
#define  GET_USB_DOEPTSIZ1_RX_DPID(reg)                     (((reg)>>29)&0x3u)            /**< Get UsbDOEPTSIZ1RxDPID from register */
/** @} */


/**
 * @name RegUsbDOEPCTL2
 * @{
 */
// RegUsbDOEPCTL2.r32
#define  REG_USB_DOEPCTL2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPCTL2 */
#define  REG_USB_DOEPCTL2_MASK                              0xFC3F87FFu                   /**< Mask for RegUsbDOEPCTL2 */

#define  USB_DOEPCTL2_MPS_SHIFT                             0                             /**< Shift for UsbDOEPCTL2MPS */
#define  USB_DOEPCTL2_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDOEPCTL2MPS */
#define  USB_DOEPCTL2_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDOEPCTL2MPS */
#define  USB_DOEPCTL2_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDOEPCTL2MPS in register */
#define  GET_USB_DOEPCTL2_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPCTL2MPS from register */
#define  USB_DOEPCTL2_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDOEPCTL2USBActEP */
#define  USB_DOEPCTL2_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDOEPCTL2USBActEP */
#define  USB_DOEPCTL2_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL2USBActEP */
#define  USB_DOEPCTL2_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDOEPCTL2USBActEP in register */
#define  GET_USB_DOEPCTL2_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDOEPCTL2USBActEP from register */
#define  USB_DOEPCTL2_DPID_SHIFT                            16                            /**< Shift for UsbDOEPCTL2DPID */
#define  USB_DOEPCTL2_DPID_MASK                             0x00010000u                   /**< Mask for UsbDOEPCTL2DPID */
#define  USB_DOEPCTL2_DPID_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL2DPID */
#define  USB_DOEPCTL2_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDOEPCTL2DPID in register */
#define  GET_USB_DOEPCTL2_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDOEPCTL2DPID from register */
#define  USB_DOEPCTL2_NAKSTS_SHIFT                          17                            /**< Shift for UsbDOEPCTL2NAKSts */
#define  USB_DOEPCTL2_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDOEPCTL2NAKSts */
#define  USB_DOEPCTL2_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDOEPCTL2NAKSts */
#define  USB_DOEPCTL2_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDOEPCTL2NAKSts in register */
#define  GET_USB_DOEPCTL2_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDOEPCTL2NAKSts from register */
#define  USB_DOEPCTL2_EPTYPE_SHIFT                          18                            /**< Shift for UsbDOEPCTL2EPType */
#define  USB_DOEPCTL2_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDOEPCTL2EPType */
#define  USB_DOEPCTL2_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDOEPCTL2EPType */
#define  USB_DOEPCTL2_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDOEPCTL2EPType in register */
#define  GET_USB_DOEPCTL2_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDOEPCTL2EPType from register */
#define  USB_DOEPCTL2_SNP_SHIFT                             20                            /**< Shift for UsbDOEPCTL2Snp */
#define  USB_DOEPCTL2_SNP_MASK                              0x00100000u                   /**< Mask for UsbDOEPCTL2Snp */
#define  USB_DOEPCTL2_SNP_BMASK                             0x1u                          /**< Base mask for UsbDOEPCTL2Snp */
#define  USB_DOEPCTL2_SNP(x)                                (((x)&0x1u)<<20)              /**< Set UsbDOEPCTL2Snp in register */
#define  GET_USB_DOEPCTL2_SNP(reg)                          (((reg)>>20)&0x1u)            /**< Get UsbDOEPCTL2Snp from register */
#define  USB_DOEPCTL2_STALL_SHIFT                           21                            /**< Shift for UsbDOEPCTL2Stall */
#define  USB_DOEPCTL2_STALL_MASK                            0x00200000u                   /**< Mask for UsbDOEPCTL2Stall */
#define  USB_DOEPCTL2_STALL_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL2Stall */
#define  USB_DOEPCTL2_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDOEPCTL2Stall in register */
#define  GET_USB_DOEPCTL2_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDOEPCTL2Stall from register */
#define  USB_DOEPCTL2_CNAK_SHIFT                            26                            /**< Shift for UsbDOEPCTL2CNAK */
#define  USB_DOEPCTL2_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDOEPCTL2CNAK */
#define  USB_DOEPCTL2_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL2CNAK */
#define  USB_DOEPCTL2_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDOEPCTL2CNAK in register */
#define  GET_USB_DOEPCTL2_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDOEPCTL2CNAK from register */
#define  USB_DOEPCTL2_SNAK_SHIFT                            27                            /**< Shift for UsbDOEPCTL2SNAK */
#define  USB_DOEPCTL2_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDOEPCTL2SNAK */
#define  USB_DOEPCTL2_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL2SNAK */
#define  USB_DOEPCTL2_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDOEPCTL2SNAK in register */
#define  GET_USB_DOEPCTL2_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDOEPCTL2SNAK from register */
#define  USB_DOEPCTL2_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDOEPCTL2SetD0PID */
#define  USB_DOEPCTL2_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDOEPCTL2SetD0PID */
#define  USB_DOEPCTL2_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL2SetD0PID */
#define  USB_DOEPCTL2_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDOEPCTL2SetD0PID in register */
#define  GET_USB_DOEPCTL2_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDOEPCTL2SetD0PID from register */
#define  USB_DOEPCTL2_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDOEPCTL2SetD1PID */
#define  USB_DOEPCTL2_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDOEPCTL2SetD1PID */
#define  USB_DOEPCTL2_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL2SetD1PID */
#define  USB_DOEPCTL2_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDOEPCTL2SetD1PID in register */
#define  GET_USB_DOEPCTL2_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDOEPCTL2SetD1PID from register */
#define  USB_DOEPCTL2_EPDIS_SHIFT                           30                            /**< Shift for UsbDOEPCTL2EPDis */
#define  USB_DOEPCTL2_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDOEPCTL2EPDis */
#define  USB_DOEPCTL2_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL2EPDis */
#define  USB_DOEPCTL2_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDOEPCTL2EPDis in register */
#define  GET_USB_DOEPCTL2_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDOEPCTL2EPDis from register */
#define  USB_DOEPCTL2_EPENA_SHIFT                           31                            /**< Shift for UsbDOEPCTL2EPEna */
#define  USB_DOEPCTL2_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDOEPCTL2EPEna */
#define  USB_DOEPCTL2_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL2EPEna */
#define  USB_DOEPCTL2_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDOEPCTL2EPEna in register */
#define  GET_USB_DOEPCTL2_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDOEPCTL2EPEna from register */
/** @} */


/**
 * @name RegUsbDOEPINT2
 * @{
 */
// RegUsbDOEPINT2.r32
#define  REG_USB_DOEPINT2_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPINT2 */
#define  REG_USB_DOEPINT2_MASK                              0x0000FA7Fu                   /**< Mask for RegUsbDOEPINT2 */

#define  USB_DOEPINT2_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDOEPINT2XferCompl */
#define  USB_DOEPINT2_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDOEPINT2XferCompl */
#define  USB_DOEPINT2_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT2XferCompl */
#define  USB_DOEPINT2_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDOEPINT2XferCompl in register */
#define  GET_USB_DOEPINT2_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDOEPINT2XferCompl from register */
#define  USB_DOEPINT2_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDOEPINT2EPDisbld */
#define  USB_DOEPINT2_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDOEPINT2EPDisbld */
#define  USB_DOEPINT2_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT2EPDisbld */
#define  USB_DOEPINT2_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDOEPINT2EPDisbld in register */
#define  GET_USB_DOEPINT2_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDOEPINT2EPDisbld from register */
#define  USB_DOEPINT2_AHBERR_SHIFT                          2                             /**< Shift for UsbDOEPINT2AHBErr */
#define  USB_DOEPINT2_AHBERR_MASK                           0x00000004u                   /**< Mask for UsbDOEPINT2AHBErr */
#define  USB_DOEPINT2_AHBERR_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT2AHBErr */
#define  USB_DOEPINT2_AHBERR(x)                             (((x)&0x1u)<<2)               /**< Set UsbDOEPINT2AHBErr in register */
#define  GET_USB_DOEPINT2_AHBERR(reg)                       (((reg)>>2)&0x1u)             /**< Get UsbDOEPINT2AHBErr from register */
#define  USB_DOEPINT2_SET_UP_SHIFT                          3                             /**< Shift for UsbDOEPINT2SetUp */
#define  USB_DOEPINT2_SET_UP_MASK                           0x00000008u                   /**< Mask for UsbDOEPINT2SetUp */
#define  USB_DOEPINT2_SET_UP_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT2SetUp */
#define  USB_DOEPINT2_SET_UP(x)                             (((x)&0x1u)<<3)               /**< Set UsbDOEPINT2SetUp in register */
#define  GET_USB_DOEPINT2_SET_UP(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbDOEPINT2SetUp from register */
#define  USB_DOEPINT2_OUTTKN_EPDIS_SHIFT                    4                             /**< Shift for UsbDOEPINT2OUTTknEPdis */
#define  USB_DOEPINT2_OUTTKN_EPDIS_MASK                     0x00000010u                   /**< Mask for UsbDOEPINT2OUTTknEPdis */
#define  USB_DOEPINT2_OUTTKN_EPDIS_BMASK                    0x1u                          /**< Base mask for UsbDOEPINT2OUTTknEPdis */
#define  USB_DOEPINT2_OUTTKN_EPDIS(x)                       (((x)&0x1u)<<4)               /**< Set UsbDOEPINT2OUTTknEPdis in register */
#define  GET_USB_DOEPINT2_OUTTKN_EPDIS(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDOEPINT2OUTTknEPdis from register */
#define  USB_DOEPINT2_STS_PHSE_RCVD_SHIFT                   5                             /**< Shift for UsbDOEPINT2StsPhseRcvd */
#define  USB_DOEPINT2_STS_PHSE_RCVD_MASK                    0x00000020u                   /**< Mask for UsbDOEPINT2StsPhseRcvd */
#define  USB_DOEPINT2_STS_PHSE_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT2StsPhseRcvd */
#define  USB_DOEPINT2_STS_PHSE_RCVD(x)                      (((x)&0x1u)<<5)               /**< Set UsbDOEPINT2StsPhseRcvd in register */
#define  GET_USB_DOEPINT2_STS_PHSE_RCVD(reg)                (((reg)>>5)&0x1u)             /**< Get UsbDOEPINT2StsPhseRcvd from register */
#define  USB_DOEPINT2_BACK2BACK_SETUP_SHIFT                 6                             /**< Shift for UsbDOEPINT2Back2BackSETup */
#define  USB_DOEPINT2_BACK2BACK_SETUP_MASK                  0x00000040u                   /**< Mask for UsbDOEPINT2Back2BackSETup */
#define  USB_DOEPINT2_BACK2BACK_SETUP_BMASK                 0x1u                          /**< Base mask for UsbDOEPINT2Back2BackSETup */
#define  USB_DOEPINT2_BACK2BACK_SETUP(x)                    (((x)&0x1u)<<6)               /**< Set UsbDOEPINT2Back2BackSETup in register */
#define  GET_USB_DOEPINT2_BACK2BACK_SETUP(reg)              (((reg)>>6)&0x1u)             /**< Get UsbDOEPINT2Back2BackSETup from register */
#define  USB_DOEPINT2_BNAINTR_SHIFT                         9                             /**< Shift for UsbDOEPINT2BNAIntr */
#define  USB_DOEPINT2_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDOEPINT2BNAIntr */
#define  USB_DOEPINT2_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDOEPINT2BNAIntr */
#define  USB_DOEPINT2_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDOEPINT2BNAIntr in register */
#define  GET_USB_DOEPINT2_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDOEPINT2BNAIntr from register */
#define  USB_DOEPINT2_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDOEPINT2PktDrpSts */
#define  USB_DOEPINT2_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDOEPINT2PktDrpSts */
#define  USB_DOEPINT2_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDOEPINT2PktDrpSts */
#define  USB_DOEPINT2_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDOEPINT2PktDrpSts in register */
#define  GET_USB_DOEPINT2_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDOEPINT2PktDrpSts from register */
#define  USB_DOEPINT2_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDOEPINT2BbleErr */
#define  USB_DOEPINT2_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDOEPINT2BbleErr */
#define  USB_DOEPINT2_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT2BbleErr */
#define  USB_DOEPINT2_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDOEPINT2BbleErr in register */
#define  GET_USB_DOEPINT2_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDOEPINT2BbleErr from register */
#define  USB_DOEPINT2_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDOEPINT2NAKIntrpt */
#define  USB_DOEPINT2_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDOEPINT2NAKIntrpt */
#define  USB_DOEPINT2_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDOEPINT2NAKIntrpt */
#define  USB_DOEPINT2_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDOEPINT2NAKIntrpt in register */
#define  GET_USB_DOEPINT2_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDOEPINT2NAKIntrpt from register */
#define  USB_DOEPINT2_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDOEPINT2NYETIntrpt */
#define  USB_DOEPINT2_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDOEPINT2NYETIntrpt */
#define  USB_DOEPINT2_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT2NYETIntrpt */
#define  USB_DOEPINT2_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDOEPINT2NYETIntrpt in register */
#define  GET_USB_DOEPINT2_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDOEPINT2NYETIntrpt from register */
#define  USB_DOEPINT2_STUP_PKT_RCVD_SHIFT                   15                            /**< Shift for UsbDOEPINT2StupPktRcvd */
#define  USB_DOEPINT2_STUP_PKT_RCVD_MASK                    0x00008000u                   /**< Mask for UsbDOEPINT2StupPktRcvd */
#define  USB_DOEPINT2_STUP_PKT_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT2StupPktRcvd */
#define  USB_DOEPINT2_STUP_PKT_RCVD(x)                      (((x)&0x1u)<<15)              /**< Set UsbDOEPINT2StupPktRcvd in register */
#define  GET_USB_DOEPINT2_STUP_PKT_RCVD(reg)                (((reg)>>15)&0x1u)            /**< Get UsbDOEPINT2StupPktRcvd from register */
/** @} */


/**
 * @name RegUsbDOEPTSIZ2
 * @{
 */
// RegUsbDOEPTSIZ2.r32
#define  REG_USB_DOEPTSIZ2_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDOEPTSIZ2 */
#define  REG_USB_DOEPTSIZ2_MASK                             0x607807FFu                   /**< Mask for RegUsbDOEPTSIZ2 */

#define  USB_DOEPTSIZ2_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDOEPTSIZ2XferSize */
#define  USB_DOEPTSIZ2_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDOEPTSIZ2XferSize */
#define  USB_DOEPTSIZ2_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDOEPTSIZ2XferSize */
#define  USB_DOEPTSIZ2_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDOEPTSIZ2XferSize in register */
#define  GET_USB_DOEPTSIZ2_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPTSIZ2XferSize from register */
#define  USB_DOEPTSIZ2_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDOEPTSIZ2PktCnt */
#define  USB_DOEPTSIZ2_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDOEPTSIZ2PktCnt */
#define  USB_DOEPTSIZ2_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDOEPTSIZ2PktCnt */
#define  USB_DOEPTSIZ2_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDOEPTSIZ2PktCnt in register */
#define  GET_USB_DOEPTSIZ2_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDOEPTSIZ2PktCnt from register */
#define  USB_DOEPTSIZ2_RX_DPID_SHIFT                        29                            /**< Shift for UsbDOEPTSIZ2RxDPID */
#define  USB_DOEPTSIZ2_RX_DPID_MASK                         0x60000000u                   /**< Mask for UsbDOEPTSIZ2RxDPID */
#define  USB_DOEPTSIZ2_RX_DPID_BMASK                        0x3u                          /**< Base mask for UsbDOEPTSIZ2RxDPID */
#define  USB_DOEPTSIZ2_RX_DPID(x)                           (((x)&0x3u)<<29)              /**< Set UsbDOEPTSIZ2RxDPID in register */
#define  GET_USB_DOEPTSIZ2_RX_DPID(reg)                     (((reg)>>29)&0x3u)            /**< Get UsbDOEPTSIZ2RxDPID from register */
/** @} */


/**
 * @name RegUsbDOEPCTL3
 * @{
 */
// RegUsbDOEPCTL3.r32
#define  REG_USB_DOEPCTL3_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPCTL3 */
#define  REG_USB_DOEPCTL3_MASK                              0xFC3F87FFu                   /**< Mask for RegUsbDOEPCTL3 */

#define  USB_DOEPCTL3_MPS_SHIFT                             0                             /**< Shift for UsbDOEPCTL3MPS */
#define  USB_DOEPCTL3_MPS_MASK                              0x000007FFu                   /**< Mask for UsbDOEPCTL3MPS */
#define  USB_DOEPCTL3_MPS_BMASK                             0x7FFu                        /**< Base mask for UsbDOEPCTL3MPS */
#define  USB_DOEPCTL3_MPS(x)                                (((x)&0x7FFu)<<0)             /**< Set UsbDOEPCTL3MPS in register */
#define  GET_USB_DOEPCTL3_MPS(reg)                          (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPCTL3MPS from register */
#define  USB_DOEPCTL3_USBACT_EP_SHIFT                       15                            /**< Shift for UsbDOEPCTL3USBActEP */
#define  USB_DOEPCTL3_USBACT_EP_MASK                        0x00008000u                   /**< Mask for UsbDOEPCTL3USBActEP */
#define  USB_DOEPCTL3_USBACT_EP_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL3USBActEP */
#define  USB_DOEPCTL3_USBACT_EP(x)                          (((x)&0x1u)<<15)              /**< Set UsbDOEPCTL3USBActEP in register */
#define  GET_USB_DOEPCTL3_USBACT_EP(reg)                    (((reg)>>15)&0x1u)            /**< Get UsbDOEPCTL3USBActEP from register */
#define  USB_DOEPCTL3_DPID_SHIFT                            16                            /**< Shift for UsbDOEPCTL3DPID */
#define  USB_DOEPCTL3_DPID_MASK                             0x00010000u                   /**< Mask for UsbDOEPCTL3DPID */
#define  USB_DOEPCTL3_DPID_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL3DPID */
#define  USB_DOEPCTL3_DPID(x)                               (((x)&0x1u)<<16)              /**< Set UsbDOEPCTL3DPID in register */
#define  GET_USB_DOEPCTL3_DPID(reg)                         (((reg)>>16)&0x1u)            /**< Get UsbDOEPCTL3DPID from register */
#define  USB_DOEPCTL3_NAKSTS_SHIFT                          17                            /**< Shift for UsbDOEPCTL3NAKSts */
#define  USB_DOEPCTL3_NAKSTS_MASK                           0x00020000u                   /**< Mask for UsbDOEPCTL3NAKSts */
#define  USB_DOEPCTL3_NAKSTS_BMASK                          0x1u                          /**< Base mask for UsbDOEPCTL3NAKSts */
#define  USB_DOEPCTL3_NAKSTS(x)                             (((x)&0x1u)<<17)              /**< Set UsbDOEPCTL3NAKSts in register */
#define  GET_USB_DOEPCTL3_NAKSTS(reg)                       (((reg)>>17)&0x1u)            /**< Get UsbDOEPCTL3NAKSts from register */
#define  USB_DOEPCTL3_EPTYPE_SHIFT                          18                            /**< Shift for UsbDOEPCTL3EPType */
#define  USB_DOEPCTL3_EPTYPE_MASK                           0x000C0000u                   /**< Mask for UsbDOEPCTL3EPType */
#define  USB_DOEPCTL3_EPTYPE_BMASK                          0x3u                          /**< Base mask for UsbDOEPCTL3EPType */
#define  USB_DOEPCTL3_EPTYPE(x)                             (((x)&0x3u)<<18)              /**< Set UsbDOEPCTL3EPType in register */
#define  GET_USB_DOEPCTL3_EPTYPE(reg)                       (((reg)>>18)&0x3u)            /**< Get UsbDOEPCTL3EPType from register */
#define  USB_DOEPCTL3_SNP_SHIFT                             20                            /**< Shift for UsbDOEPCTL3Snp */
#define  USB_DOEPCTL3_SNP_MASK                              0x00100000u                   /**< Mask for UsbDOEPCTL3Snp */
#define  USB_DOEPCTL3_SNP_BMASK                             0x1u                          /**< Base mask for UsbDOEPCTL3Snp */
#define  USB_DOEPCTL3_SNP(x)                                (((x)&0x1u)<<20)              /**< Set UsbDOEPCTL3Snp in register */
#define  GET_USB_DOEPCTL3_SNP(reg)                          (((reg)>>20)&0x1u)            /**< Get UsbDOEPCTL3Snp from register */
#define  USB_DOEPCTL3_STALL_SHIFT                           21                            /**< Shift for UsbDOEPCTL3Stall */
#define  USB_DOEPCTL3_STALL_MASK                            0x00200000u                   /**< Mask for UsbDOEPCTL3Stall */
#define  USB_DOEPCTL3_STALL_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL3Stall */
#define  USB_DOEPCTL3_STALL(x)                              (((x)&0x1u)<<21)              /**< Set UsbDOEPCTL3Stall in register */
#define  GET_USB_DOEPCTL3_STALL(reg)                        (((reg)>>21)&0x1u)            /**< Get UsbDOEPCTL3Stall from register */
#define  USB_DOEPCTL3_CNAK_SHIFT                            26                            /**< Shift for UsbDOEPCTL3CNAK */
#define  USB_DOEPCTL3_CNAK_MASK                             0x04000000u                   /**< Mask for UsbDOEPCTL3CNAK */
#define  USB_DOEPCTL3_CNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL3CNAK */
#define  USB_DOEPCTL3_CNAK(x)                               (((x)&0x1u)<<26)              /**< Set UsbDOEPCTL3CNAK in register */
#define  GET_USB_DOEPCTL3_CNAK(reg)                         (((reg)>>26)&0x1u)            /**< Get UsbDOEPCTL3CNAK from register */
#define  USB_DOEPCTL3_SNAK_SHIFT                            27                            /**< Shift for UsbDOEPCTL3SNAK */
#define  USB_DOEPCTL3_SNAK_MASK                             0x08000000u                   /**< Mask for UsbDOEPCTL3SNAK */
#define  USB_DOEPCTL3_SNAK_BMASK                            0x1u                          /**< Base mask for UsbDOEPCTL3SNAK */
#define  USB_DOEPCTL3_SNAK(x)                               (((x)&0x1u)<<27)              /**< Set UsbDOEPCTL3SNAK in register */
#define  GET_USB_DOEPCTL3_SNAK(reg)                         (((reg)>>27)&0x1u)            /**< Get UsbDOEPCTL3SNAK from register */
#define  USB_DOEPCTL3_SET_D0PID_SHIFT                       28                            /**< Shift for UsbDOEPCTL3SetD0PID */
#define  USB_DOEPCTL3_SET_D0PID_MASK                        0x10000000u                   /**< Mask for UsbDOEPCTL3SetD0PID */
#define  USB_DOEPCTL3_SET_D0PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL3SetD0PID */
#define  USB_DOEPCTL3_SET_D0PID(x)                          (((x)&0x1u)<<28)              /**< Set UsbDOEPCTL3SetD0PID in register */
#define  GET_USB_DOEPCTL3_SET_D0PID(reg)                    (((reg)>>28)&0x1u)            /**< Get UsbDOEPCTL3SetD0PID from register */
#define  USB_DOEPCTL3_SET_D1PID_SHIFT                       29                            /**< Shift for UsbDOEPCTL3SetD1PID */
#define  USB_DOEPCTL3_SET_D1PID_MASK                        0x20000000u                   /**< Mask for UsbDOEPCTL3SetD1PID */
#define  USB_DOEPCTL3_SET_D1PID_BMASK                       0x1u                          /**< Base mask for UsbDOEPCTL3SetD1PID */
#define  USB_DOEPCTL3_SET_D1PID(x)                          (((x)&0x1u)<<29)              /**< Set UsbDOEPCTL3SetD1PID in register */
#define  GET_USB_DOEPCTL3_SET_D1PID(reg)                    (((reg)>>29)&0x1u)            /**< Get UsbDOEPCTL3SetD1PID from register */
#define  USB_DOEPCTL3_EPDIS_SHIFT                           30                            /**< Shift for UsbDOEPCTL3EPDis */
#define  USB_DOEPCTL3_EPDIS_MASK                            0x40000000u                   /**< Mask for UsbDOEPCTL3EPDis */
#define  USB_DOEPCTL3_EPDIS_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL3EPDis */
#define  USB_DOEPCTL3_EPDIS(x)                              (((x)&0x1u)<<30)              /**< Set UsbDOEPCTL3EPDis in register */
#define  GET_USB_DOEPCTL3_EPDIS(reg)                        (((reg)>>30)&0x1u)            /**< Get UsbDOEPCTL3EPDis from register */
#define  USB_DOEPCTL3_EPENA_SHIFT                           31                            /**< Shift for UsbDOEPCTL3EPEna */
#define  USB_DOEPCTL3_EPENA_MASK                            0x80000000u                   /**< Mask for UsbDOEPCTL3EPEna */
#define  USB_DOEPCTL3_EPENA_BMASK                           0x1u                          /**< Base mask for UsbDOEPCTL3EPEna */
#define  USB_DOEPCTL3_EPENA(x)                              (((x)&0x1u)<<31)              /**< Set UsbDOEPCTL3EPEna in register */
#define  GET_USB_DOEPCTL3_EPENA(reg)                        (((reg)>>31)&0x1u)            /**< Get UsbDOEPCTL3EPEna from register */
/** @} */


/**
 * @name RegUsbDOEPINT3
 * @{
 */
// RegUsbDOEPINT3.r32
#define  REG_USB_DOEPINT3_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDOEPINT3 */
#define  REG_USB_DOEPINT3_MASK                              0x0000FA7Fu                   /**< Mask for RegUsbDOEPINT3 */

#define  USB_DOEPINT3_XFER_COMPL_SHIFT                      0                             /**< Shift for UsbDOEPINT3XferCompl */
#define  USB_DOEPINT3_XFER_COMPL_MASK                       0x00000001u                   /**< Mask for UsbDOEPINT3XferCompl */
#define  USB_DOEPINT3_XFER_COMPL_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT3XferCompl */
#define  USB_DOEPINT3_XFER_COMPL(x)                         (((x)&0x1u)<<0)               /**< Set UsbDOEPINT3XferCompl in register */
#define  GET_USB_DOEPINT3_XFER_COMPL(reg)                   (((reg)>>0)&0x1u)             /**< Get UsbDOEPINT3XferCompl from register */
#define  USB_DOEPINT3_EPDISBLD_SHIFT                        1                             /**< Shift for UsbDOEPINT3EPDisbld */
#define  USB_DOEPINT3_EPDISBLD_MASK                         0x00000002u                   /**< Mask for UsbDOEPINT3EPDisbld */
#define  USB_DOEPINT3_EPDISBLD_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT3EPDisbld */
#define  USB_DOEPINT3_EPDISBLD(x)                           (((x)&0x1u)<<1)               /**< Set UsbDOEPINT3EPDisbld in register */
#define  GET_USB_DOEPINT3_EPDISBLD(reg)                     (((reg)>>1)&0x1u)             /**< Get UsbDOEPINT3EPDisbld from register */
#define  USB_DOEPINT3_AHBERR_SHIFT                          2                             /**< Shift for UsbDOEPINT3AHBErr */
#define  USB_DOEPINT3_AHBERR_MASK                           0x00000004u                   /**< Mask for UsbDOEPINT3AHBErr */
#define  USB_DOEPINT3_AHBERR_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT3AHBErr */
#define  USB_DOEPINT3_AHBERR(x)                             (((x)&0x1u)<<2)               /**< Set UsbDOEPINT3AHBErr in register */
#define  GET_USB_DOEPINT3_AHBERR(reg)                       (((reg)>>2)&0x1u)             /**< Get UsbDOEPINT3AHBErr from register */
#define  USB_DOEPINT3_SET_UP_SHIFT                          3                             /**< Shift for UsbDOEPINT3SetUp */
#define  USB_DOEPINT3_SET_UP_MASK                           0x00000008u                   /**< Mask for UsbDOEPINT3SetUp */
#define  USB_DOEPINT3_SET_UP_BMASK                          0x1u                          /**< Base mask for UsbDOEPINT3SetUp */
#define  USB_DOEPINT3_SET_UP(x)                             (((x)&0x1u)<<3)               /**< Set UsbDOEPINT3SetUp in register */
#define  GET_USB_DOEPINT3_SET_UP(reg)                       (((reg)>>3)&0x1u)             /**< Get UsbDOEPINT3SetUp from register */
#define  USB_DOEPINT3_OUTTKN_EPDIS_SHIFT                    4                             /**< Shift for UsbDOEPINT3OUTTknEPdis */
#define  USB_DOEPINT3_OUTTKN_EPDIS_MASK                     0x00000010u                   /**< Mask for UsbDOEPINT3OUTTknEPdis */
#define  USB_DOEPINT3_OUTTKN_EPDIS_BMASK                    0x1u                          /**< Base mask for UsbDOEPINT3OUTTknEPdis */
#define  USB_DOEPINT3_OUTTKN_EPDIS(x)                       (((x)&0x1u)<<4)               /**< Set UsbDOEPINT3OUTTknEPdis in register */
#define  GET_USB_DOEPINT3_OUTTKN_EPDIS(reg)                 (((reg)>>4)&0x1u)             /**< Get UsbDOEPINT3OUTTknEPdis from register */
#define  USB_DOEPINT3_STS_PHSE_RCVD_SHIFT                   5                             /**< Shift for UsbDOEPINT3StsPhseRcvd */
#define  USB_DOEPINT3_STS_PHSE_RCVD_MASK                    0x00000020u                   /**< Mask for UsbDOEPINT3StsPhseRcvd */
#define  USB_DOEPINT3_STS_PHSE_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT3StsPhseRcvd */
#define  USB_DOEPINT3_STS_PHSE_RCVD(x)                      (((x)&0x1u)<<5)               /**< Set UsbDOEPINT3StsPhseRcvd in register */
#define  GET_USB_DOEPINT3_STS_PHSE_RCVD(reg)                (((reg)>>5)&0x1u)             /**< Get UsbDOEPINT3StsPhseRcvd from register */
#define  USB_DOEPINT3_BACK2BACK_SETUP_SHIFT                 6                             /**< Shift for UsbDOEPINT3Back2BackSETup */
#define  USB_DOEPINT3_BACK2BACK_SETUP_MASK                  0x00000040u                   /**< Mask for UsbDOEPINT3Back2BackSETup */
#define  USB_DOEPINT3_BACK2BACK_SETUP_BMASK                 0x1u                          /**< Base mask for UsbDOEPINT3Back2BackSETup */
#define  USB_DOEPINT3_BACK2BACK_SETUP(x)                    (((x)&0x1u)<<6)               /**< Set UsbDOEPINT3Back2BackSETup in register */
#define  GET_USB_DOEPINT3_BACK2BACK_SETUP(reg)              (((reg)>>6)&0x1u)             /**< Get UsbDOEPINT3Back2BackSETup from register */
#define  USB_DOEPINT3_BNAINTR_SHIFT                         9                             /**< Shift for UsbDOEPINT3BNAIntr */
#define  USB_DOEPINT3_BNAINTR_MASK                          0x00000200u                   /**< Mask for UsbDOEPINT3BNAIntr */
#define  USB_DOEPINT3_BNAINTR_BMASK                         0x1u                          /**< Base mask for UsbDOEPINT3BNAIntr */
#define  USB_DOEPINT3_BNAINTR(x)                            (((x)&0x1u)<<9)               /**< Set UsbDOEPINT3BNAIntr in register */
#define  GET_USB_DOEPINT3_BNAINTR(reg)                      (((reg)>>9)&0x1u)             /**< Get UsbDOEPINT3BNAIntr from register */
#define  USB_DOEPINT3_PKT_DRP_STS_SHIFT                     11                            /**< Shift for UsbDOEPINT3PktDrpSts */
#define  USB_DOEPINT3_PKT_DRP_STS_MASK                      0x00000800u                   /**< Mask for UsbDOEPINT3PktDrpSts */
#define  USB_DOEPINT3_PKT_DRP_STS_BMASK                     0x1u                          /**< Base mask for UsbDOEPINT3PktDrpSts */
#define  USB_DOEPINT3_PKT_DRP_STS(x)                        (((x)&0x1u)<<11)              /**< Set UsbDOEPINT3PktDrpSts in register */
#define  GET_USB_DOEPINT3_PKT_DRP_STS(reg)                  (((reg)>>11)&0x1u)            /**< Get UsbDOEPINT3PktDrpSts from register */
#define  USB_DOEPINT3_BBLE_ERR_SHIFT                        12                            /**< Shift for UsbDOEPINT3BbleErr */
#define  USB_DOEPINT3_BBLE_ERR_MASK                         0x00001000u                   /**< Mask for UsbDOEPINT3BbleErr */
#define  USB_DOEPINT3_BBLE_ERR_BMASK                        0x1u                          /**< Base mask for UsbDOEPINT3BbleErr */
#define  USB_DOEPINT3_BBLE_ERR(x)                           (((x)&0x1u)<<12)              /**< Set UsbDOEPINT3BbleErr in register */
#define  GET_USB_DOEPINT3_BBLE_ERR(reg)                     (((reg)>>12)&0x1u)            /**< Get UsbDOEPINT3BbleErr from register */
#define  USB_DOEPINT3_NAKINTRPT_SHIFT                       13                            /**< Shift for UsbDOEPINT3NAKIntrpt */
#define  USB_DOEPINT3_NAKINTRPT_MASK                        0x00002000u                   /**< Mask for UsbDOEPINT3NAKIntrpt */
#define  USB_DOEPINT3_NAKINTRPT_BMASK                       0x1u                          /**< Base mask for UsbDOEPINT3NAKIntrpt */
#define  USB_DOEPINT3_NAKINTRPT(x)                          (((x)&0x1u)<<13)              /**< Set UsbDOEPINT3NAKIntrpt in register */
#define  GET_USB_DOEPINT3_NAKINTRPT(reg)                    (((reg)>>13)&0x1u)            /**< Get UsbDOEPINT3NAKIntrpt from register */
#define  USB_DOEPINT3_NYETINTRPT_SHIFT                      14                            /**< Shift for UsbDOEPINT3NYETIntrpt */
#define  USB_DOEPINT3_NYETINTRPT_MASK                       0x00004000u                   /**< Mask for UsbDOEPINT3NYETIntrpt */
#define  USB_DOEPINT3_NYETINTRPT_BMASK                      0x1u                          /**< Base mask for UsbDOEPINT3NYETIntrpt */
#define  USB_DOEPINT3_NYETINTRPT(x)                         (((x)&0x1u)<<14)              /**< Set UsbDOEPINT3NYETIntrpt in register */
#define  GET_USB_DOEPINT3_NYETINTRPT(reg)                   (((reg)>>14)&0x1u)            /**< Get UsbDOEPINT3NYETIntrpt from register */
#define  USB_DOEPINT3_STUP_PKT_RCVD_SHIFT                   15                            /**< Shift for UsbDOEPINT3StupPktRcvd */
#define  USB_DOEPINT3_STUP_PKT_RCVD_MASK                    0x00008000u                   /**< Mask for UsbDOEPINT3StupPktRcvd */
#define  USB_DOEPINT3_STUP_PKT_RCVD_BMASK                   0x1u                          /**< Base mask for UsbDOEPINT3StupPktRcvd */
#define  USB_DOEPINT3_STUP_PKT_RCVD(x)                      (((x)&0x1u)<<15)              /**< Set UsbDOEPINT3StupPktRcvd in register */
#define  GET_USB_DOEPINT3_STUP_PKT_RCVD(reg)                (((reg)>>15)&0x1u)            /**< Get UsbDOEPINT3StupPktRcvd from register */
/** @} */


/**
 * @name RegUsbDOEPTSIZ3
 * @{
 */
// RegUsbDOEPTSIZ3.r32
#define  REG_USB_DOEPTSIZ3_RESET_VALUE                      0x00000000u                   /**< Reset value of RegUsbDOEPTSIZ3 */
#define  REG_USB_DOEPTSIZ3_MASK                             0x607807FFu                   /**< Mask for RegUsbDOEPTSIZ3 */

#define  USB_DOEPTSIZ3_XFER_SIZE_SHIFT                      0                             /**< Shift for UsbDOEPTSIZ3XferSize */
#define  USB_DOEPTSIZ3_XFER_SIZE_MASK                       0x000007FFu                   /**< Mask for UsbDOEPTSIZ3XferSize */
#define  USB_DOEPTSIZ3_XFER_SIZE_BMASK                      0x7FFu                        /**< Base mask for UsbDOEPTSIZ3XferSize */
#define  USB_DOEPTSIZ3_XFER_SIZE(x)                         (((x)&0x7FFu)<<0)             /**< Set UsbDOEPTSIZ3XferSize in register */
#define  GET_USB_DOEPTSIZ3_XFER_SIZE(reg)                   (((reg)>>0)&0x7FFu)           /**< Get UsbDOEPTSIZ3XferSize from register */
#define  USB_DOEPTSIZ3_PKT_CNT_SHIFT                        19                            /**< Shift for UsbDOEPTSIZ3PktCnt */
#define  USB_DOEPTSIZ3_PKT_CNT_MASK                         0x00780000u                   /**< Mask for UsbDOEPTSIZ3PktCnt */
#define  USB_DOEPTSIZ3_PKT_CNT_BMASK                        0xFu                          /**< Base mask for UsbDOEPTSIZ3PktCnt */
#define  USB_DOEPTSIZ3_PKT_CNT(x)                           (((x)&0xFu)<<19)              /**< Set UsbDOEPTSIZ3PktCnt in register */
#define  GET_USB_DOEPTSIZ3_PKT_CNT(reg)                     (((reg)>>19)&0xFu)            /**< Get UsbDOEPTSIZ3PktCnt from register */
#define  USB_DOEPTSIZ3_RX_DPID_SHIFT                        29                            /**< Shift for UsbDOEPTSIZ3RxDPID */
#define  USB_DOEPTSIZ3_RX_DPID_MASK                         0x60000000u                   /**< Mask for UsbDOEPTSIZ3RxDPID */
#define  USB_DOEPTSIZ3_RX_DPID_BMASK                        0x3u                          /**< Base mask for UsbDOEPTSIZ3RxDPID */
#define  USB_DOEPTSIZ3_RX_DPID(x)                           (((x)&0x3u)<<29)              /**< Set UsbDOEPTSIZ3RxDPID in register */
#define  GET_USB_DOEPTSIZ3_RX_DPID(reg)                     (((reg)>>29)&0x3u)            /**< Get UsbDOEPTSIZ3RxDPID from register */
/** @} */


/**
 * @name RegUsbPCGCCTL
 * @{
 */
// RegUsbPCGCCTL.r32
#define  REG_USB_PCGCCTL_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbPCGCCTL */
#define  REG_USB_PCGCCTL_MASK                               0x000000C9u                   /**< Mask for RegUsbPCGCCTL */

#define  USB_PCGCCTL_STOP_PCLK_SHIFT                        0                             /**< Shift for UsbPCGCCTLStopPclk */
#define  USB_PCGCCTL_STOP_PCLK_MASK                         0x00000001u                   /**< Mask for UsbPCGCCTLStopPclk */
#define  USB_PCGCCTL_STOP_PCLK_BMASK                        0x1u                          /**< Base mask for UsbPCGCCTLStopPclk */
#define  USB_PCGCCTL_STOP_PCLK(x)                           (((x)&0x1u)<<0)               /**< Set UsbPCGCCTLStopPclk in register */
#define  GET_USB_PCGCCTL_STOP_PCLK(reg)                     (((reg)>>0)&0x1u)             /**< Get UsbPCGCCTLStopPclk from register */
#define  USB_PCGCCTL_RST_PDWN_MODULE_SHIFT                  3                             /**< Shift for UsbPCGCCTLRstPdwnModule */
#define  USB_PCGCCTL_RST_PDWN_MODULE_MASK                   0x00000008u                   /**< Mask for UsbPCGCCTLRstPdwnModule */
#define  USB_PCGCCTL_RST_PDWN_MODULE_BMASK                  0x1u                          /**< Base mask for UsbPCGCCTLRstPdwnModule */
#define  USB_PCGCCTL_RST_PDWN_MODULE(x)                     (((x)&0x1u)<<3)               /**< Set UsbPCGCCTLRstPdwnModule in register */
#define  GET_USB_PCGCCTL_RST_PDWN_MODULE(reg)               (((reg)>>3)&0x1u)             /**< Get UsbPCGCCTLRstPdwnModule from register */
#define  USB_PCGCCTL_PHY_SLEEP_SHIFT                        6                             /**< Shift for UsbPCGCCTLPhySleep */
#define  USB_PCGCCTL_PHY_SLEEP_MASK                         0x00000040u                   /**< Mask for UsbPCGCCTLPhySleep */
#define  USB_PCGCCTL_PHY_SLEEP_BMASK                        0x1u                          /**< Base mask for UsbPCGCCTLPhySleep */
#define  USB_PCGCCTL_PHY_SLEEP(x)                           (((x)&0x1u)<<6)               /**< Set UsbPCGCCTLPhySleep in register */
#define  GET_USB_PCGCCTL_PHY_SLEEP(reg)                     (((reg)>>6)&0x1u)             /**< Get UsbPCGCCTLPhySleep from register */
#define  USB_PCGCCTL_L1SUSPENDED_SHIFT                      7                             /**< Shift for UsbPCGCCTLL1Suspended */
#define  USB_PCGCCTL_L1SUSPENDED_MASK                       0x00000080u                   /**< Mask for UsbPCGCCTLL1Suspended */
#define  USB_PCGCCTL_L1SUSPENDED_BMASK                      0x1u                          /**< Base mask for UsbPCGCCTLL1Suspended */
#define  USB_PCGCCTL_L1SUSPENDED(x)                         (((x)&0x1u)<<7)               /**< Set UsbPCGCCTLL1Suspended in register */
#define  GET_USB_PCGCCTL_L1SUSPENDED(reg)                   (((reg)>>7)&0x1u)             /**< Get UsbPCGCCTLL1Suspended from register */
/** @} */


/**
 * @name RegUsbDFIFO0
 * @{
 */
// RegUsbDFIFO0.r32
#define  REG_USB_DFIFO_0_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO0 */
#define  REG_USB_DFIFO_0_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO0 */

#define  REG_USB_DFIFO_0_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO0field0 */
#define  REG_USB_DFIFO_0_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO0field0 */
#define  REG_USB_DFIFO_0_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO0field0 */
#define  REG_USB_DFIFO_0_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO0field0 in register */
#define  GET_REG_USB_DFIFO_0_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO0field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO1
 * @{
 */
// RegUsbDFIFO1.r32
#define  REG_USB_DFIFO_1_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO1 */
#define  REG_USB_DFIFO_1_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO1 */

#define  REG_USB_DFIFO_1_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO1field0 */
#define  REG_USB_DFIFO_1_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO1field0 */
#define  REG_USB_DFIFO_1_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO1field0 */
#define  REG_USB_DFIFO_1_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO1field0 in register */
#define  GET_REG_USB_DFIFO_1_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO1field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO2
 * @{
 */
// RegUsbDFIFO2.r32
#define  REG_USB_DFIFO_2_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO2 */
#define  REG_USB_DFIFO_2_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO2 */

#define  REG_USB_DFIFO_2_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO2field0 */
#define  REG_USB_DFIFO_2_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO2field0 */
#define  REG_USB_DFIFO_2_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO2field0 */
#define  REG_USB_DFIFO_2_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO2field0 in register */
#define  GET_REG_USB_DFIFO_2_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO2field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO3
 * @{
 */
// RegUsbDFIFO3.r32
#define  REG_USB_DFIFO_3_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO3 */
#define  REG_USB_DFIFO_3_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO3 */

#define  REG_USB_DFIFO_3_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO3field0 */
#define  REG_USB_DFIFO_3_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO3field0 */
#define  REG_USB_DFIFO_3_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO3field0 */
#define  REG_USB_DFIFO_3_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO3field0 in register */
#define  GET_REG_USB_DFIFO_3_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO3field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO4
 * @{
 */
// RegUsbDFIFO4.r32
#define  REG_USB_DFIFO_4_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO4 */
#define  REG_USB_DFIFO_4_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO4 */

#define  REG_USB_DFIFO_4_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO4field0 */
#define  REG_USB_DFIFO_4_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO4field0 */
#define  REG_USB_DFIFO_4_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO4field0 */
#define  REG_USB_DFIFO_4_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO4field0 in register */
#define  GET_REG_USB_DFIFO_4_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO4field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO5
 * @{
 */
// RegUsbDFIFO5.r32
#define  REG_USB_DFIFO_5_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO5 */
#define  REG_USB_DFIFO_5_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO5 */

#define  REG_USB_DFIFO_5_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO5field0 */
#define  REG_USB_DFIFO_5_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO5field0 */
#define  REG_USB_DFIFO_5_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO5field0 */
#define  REG_USB_DFIFO_5_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO5field0 in register */
#define  GET_REG_USB_DFIFO_5_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO5field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO6
 * @{
 */
// RegUsbDFIFO6.r32
#define  REG_USB_DFIFO_6_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO6 */
#define  REG_USB_DFIFO_6_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO6 */

#define  REG_USB_DFIFO_6_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO6field0 */
#define  REG_USB_DFIFO_6_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO6field0 */
#define  REG_USB_DFIFO_6_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO6field0 */
#define  REG_USB_DFIFO_6_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO6field0 in register */
#define  GET_REG_USB_DFIFO_6_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO6field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO7
 * @{
 */
// RegUsbDFIFO7.r32
#define  REG_USB_DFIFO_7_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO7 */
#define  REG_USB_DFIFO_7_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO7 */

#define  REG_USB_DFIFO_7_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO7field0 */
#define  REG_USB_DFIFO_7_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO7field0 */
#define  REG_USB_DFIFO_7_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO7field0 */
#define  REG_USB_DFIFO_7_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO7field0 in register */
#define  GET_REG_USB_DFIFO_7_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO7field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO8
 * @{
 */
// RegUsbDFIFO8.r32
#define  REG_USB_DFIFO_8_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO8 */
#define  REG_USB_DFIFO_8_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO8 */

#define  REG_USB_DFIFO_8_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO8field0 */
#define  REG_USB_DFIFO_8_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO8field0 */
#define  REG_USB_DFIFO_8_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO8field0 */
#define  REG_USB_DFIFO_8_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO8field0 in register */
#define  GET_REG_USB_DFIFO_8_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO8field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO9
 * @{
 */
// RegUsbDFIFO9.r32
#define  REG_USB_DFIFO_9_RESET_VALUE                        0x00000000u                   /**< Reset value of RegUsbDFIFO9 */
#define  REG_USB_DFIFO_9_MASK                               0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO9 */

#define  REG_USB_DFIFO_9_FIELD0_SHIFT                       0                             /**< Shift for RegUsbDFIFO9field0 */
#define  REG_USB_DFIFO_9_FIELD0_MASK                        0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO9field0 */
#define  REG_USB_DFIFO_9_FIELD0_BMASK                       0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO9field0 */
#define  REG_USB_DFIFO_9_FIELD0(x)                          (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO9field0 in register */
#define  GET_REG_USB_DFIFO_9_FIELD0(reg)                    (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO9field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO10
 * @{
 */
// RegUsbDFIFO10.r32
#define  REG_USB_DFIFO_10_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO10 */
#define  REG_USB_DFIFO_10_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO10 */

#define  REG_USB_DFIFO_10_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO10field0 */
#define  REG_USB_DFIFO_10_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO10field0 */
#define  REG_USB_DFIFO_10_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO10field0 */
#define  REG_USB_DFIFO_10_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO10field0 in register */
#define  GET_REG_USB_DFIFO_10_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO10field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO11
 * @{
 */
// RegUsbDFIFO11.r32
#define  REG_USB_DFIFO_11_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO11 */
#define  REG_USB_DFIFO_11_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO11 */

#define  REG_USB_DFIFO_11_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO11field0 */
#define  REG_USB_DFIFO_11_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO11field0 */
#define  REG_USB_DFIFO_11_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO11field0 */
#define  REG_USB_DFIFO_11_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO11field0 in register */
#define  GET_REG_USB_DFIFO_11_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO11field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO12
 * @{
 */
// RegUsbDFIFO12.r32
#define  REG_USB_DFIFO_12_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO12 */
#define  REG_USB_DFIFO_12_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO12 */

#define  REG_USB_DFIFO_12_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO12field0 */
#define  REG_USB_DFIFO_12_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO12field0 */
#define  REG_USB_DFIFO_12_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO12field0 */
#define  REG_USB_DFIFO_12_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO12field0 in register */
#define  GET_REG_USB_DFIFO_12_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO12field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO13
 * @{
 */
// RegUsbDFIFO13.r32
#define  REG_USB_DFIFO_13_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO13 */
#define  REG_USB_DFIFO_13_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO13 */

#define  REG_USB_DFIFO_13_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO13field0 */
#define  REG_USB_DFIFO_13_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO13field0 */
#define  REG_USB_DFIFO_13_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO13field0 */
#define  REG_USB_DFIFO_13_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO13field0 in register */
#define  GET_REG_USB_DFIFO_13_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO13field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO14
 * @{
 */
// RegUsbDFIFO14.r32
#define  REG_USB_DFIFO_14_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO14 */
#define  REG_USB_DFIFO_14_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO14 */

#define  REG_USB_DFIFO_14_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO14field0 */
#define  REG_USB_DFIFO_14_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO14field0 */
#define  REG_USB_DFIFO_14_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO14field0 */
#define  REG_USB_DFIFO_14_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO14field0 in register */
#define  GET_REG_USB_DFIFO_14_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO14field0 from register */
/** @} */


/**
 * @name RegUsbDFIFO15
 * @{
 */
// RegUsbDFIFO15.r32
#define  REG_USB_DFIFO_15_RESET_VALUE                       0x00000000u                   /**< Reset value of RegUsbDFIFO15 */
#define  REG_USB_DFIFO_15_MASK                              0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO15 */

#define  REG_USB_DFIFO_15_FIELD0_SHIFT                      0                             /**< Shift for RegUsbDFIFO15field0 */
#define  REG_USB_DFIFO_15_FIELD0_MASK                       0xFFFFFFFFu                   /**< Mask for RegUsbDFIFO15field0 */
#define  REG_USB_DFIFO_15_FIELD0_BMASK                      0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFO15field0 */
#define  REG_USB_DFIFO_15_FIELD0(x)                         (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFO15field0 in register */
#define  GET_REG_USB_DFIFO_15_FIELD0(reg)                   (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFO15field0 from register */
/** @} */


/**
 * @name RegUsbDFIFODirectaccess
 * @{
 */
// RegUsbDFIFODirectaccess.r32
#define  REG_USB_DFIFO_DIRECT_ACCESS_RESET_VALUE            0x00000000u                   /**< Reset value of RegUsbDFIFODirectaccess */
#define  REG_USB_DFIFO_DIRECT_ACCESS_MASK                   0xFFFFFFFFu                   /**< Mask for RegUsbDFIFODirectaccess */

#define  REG_USB_DFIFO_DIRECT_ACCESS_FIELD0_SHIFT           0                             /**< Shift for RegUsbDFIFODirectaccessfield0 */
#define  REG_USB_DFIFO_DIRECT_ACCESS_FIELD0_MASK            0xFFFFFFFFu                   /**< Mask for RegUsbDFIFODirectaccessfield0 */
#define  REG_USB_DFIFO_DIRECT_ACCESS_FIELD0_BMASK           0xFFFFFFFFu                   /**< Base mask for RegUsbDFIFODirectaccessfield0 */
#define  REG_USB_DFIFO_DIRECT_ACCESS_FIELD0(x)              (((x)&0xFFFFFFFFu)<<0)        /**< Set RegUsbDFIFODirectaccessfield0 in register */
#define  GET_REG_USB_DFIFO_DIRECT_ACCESS_FIELD0(reg)        (((reg)>>0)&0xFFFFFFFFu)      /**< Get RegUsbDFIFODirectaccessfield0 from register */
/** @} */



/** @} End of group USB_BitFields */
/** @} End of addtogroup cts/T9305_Periphery */

#endif /*_T9305_USB_H */
