////////////////////////////////////////////////////////////////////////////////
///
/// @file       common/includes/macros.h
///
/// @project    T9305
///
/// @brief      Common utility macros.
///
/// @classification  Public
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2015, EM Microelectronic-US
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


#ifndef _MACROS_H
#define _MACROS_H


/**
 * @defgroup macros Common Macros
 */


/**
 * @addtogroup macros
 * @{
 */


/**
 * @brief Access the register offset from a base register.
 * @param first The base register to offset from.
 * @param element The variable within the register to access. Example: r32.
 * @param num The number of registers away from the base register for the
 * desired register.
 *
 * The following example will edit the GPIO register RegGPIOInpSel2:
 * @code
 * REG_OFFSET(GPIO->RegGPIOInpSel0, 2) = 5;
 * @endcode
 *
 * @note Negative numbers may work but are not tested.
 */
//lint -emacro( (415), REG_OFFSET)
//lint -emacro( (416), REG_OFFSET)
//lint -emacro( (661), REG_OFFSET)
//lint -emacro( (662), REG_OFFSET)
#define REG_OFFSET(first, element, num) ((&(first) + (num))->element)


/**
 * @brief Retrive the desired bits from a register.
 * @param reg The register to get the bits from.
 * @param mask The mast to apply after reading the bits.
 * @param shift The number of bits to shift the data down.
 *
 * The data will be shifted down and then masked.
 */
#define REG_GET_BITS(reg, mask, shift) (((reg) >> (shift)) & (mask))


/**
 * @brief Set the desired bits into a register.
 * @param reg The register to set the bits in.
 * @param mask The mast to apply before writing the bits.
 * @param shift The number of bits to shift the data up.
 * @param val The unshifted and unmasked data to write.
 *
 * The data will be mask, shifted up, and combined with the register with the
 * appropriate bits masked by the shifted mask.
 */
//lint -emacro(717, REG_SET_BITS8) do ... while (0)
//lint -emacro(845, REG_SET_BITS8) argument to operator certain to be 0 (in some cases)
#define REG_SET_BITS8(reg, mask, shift, val) do { \
        (reg) = (uint8_t)( ((reg) & ~((mask) << (shift))) | \
            (((val) & (mask)) << (shift)) ); \
    } while(0)


/**
 * @brief Set the desired bits into a register.
 * @param reg The register to set the bits in.
 * @param mask The mast to apply before writing the bits.
 * @param shift The number of bits to shift the data up.
 * @param val The unshifted and unmasked data to write.
 *
 * The data will be mask, shifted up, and combined with the register with the
 * appropriate bits masked by the shifted mask.
 */
//lint -emacro(717, REG_SET_BITS16) do ... while (0)
#define REG_SET_BITS16(reg, mask, shift, val) do { \
        (reg) = (uint16_t)( ((reg) & ~((mask) << (shift))) | \
            (((val) & (mask)) << (shift)) ); \
    } while(0)


/**
 * @brief Set the desired bits into a register.
 * @param reg The register to set the bits in.
 * @param mask The mast to apply before writing the bits.
 * @param shift The number of bits to shift the data up.
 * @param val The unshifted and unmasked data to write.
 *
 * The data will be mask, shifted up, and combined with the register with the
 * appropriate bits masked by the shifted mask.
 */
//lint -emacro(717, REG_SET_BITS32) do ... while (0)
#define REG_SET_BITS32(reg, mask, shift, val) do { \
        (reg) = (uint32_t)( ((reg) & ~((mask) << (shift))) | \
            (((val) & (mask)) << (shift)) ); \
    } while(0)


/**
 * @brief Set the desired bits in a register to 1 in safe way.
 * @param reg The register to set the bits in into 1.
 * @param mask The mask indicating which bits to be set.
 *
 * Register value is ORed with mask to set specified bits to 1.
 */
//lint -emacro(717, REG_SET_BITS_SAFE) do ... while (0)
#define REG_SET_BITS_SAFE(reg, mask) do { \
        uint32_t threshold = IRQ_DisableAndSaveInterrupts(); \
        (reg) |= (mask); \
        IRQ_RestoreInterrupts(threshold); \
    } while(0)


/**
 * @brief Clear the desired bits in a register to 0 in safe way.
 * @param reg The register to clear the bits in into 0.
 * @param mask The mask indicating which bits to be clear.
 *
 * Register value is ANDed with negative mask to clear specified bits to 0.
 */
//lint -emacro(717, REG_CLEAR_BITS_SAFE) do ... while(0)
#define REG_CLEAR_BITS_SAFE(reg, mask) do { \
        uint32_t threshold = IRQ_DisableAndSaveInterrupts(); \
        (reg) &= ~(mask); \
        IRQ_RestoreInterrupts(threshold); \
    } while(0)


/**
 * @brief Write the desired bits in a register in safe way.
 * @param reg The register to clear the bits in into 0.
 * @param mask The mask indicating which bits to be modified.
 * @param val The data to write. They must be shifted to match mask value.
 *
 * Register bits are cleared according to mask and then new value is written
 * to bits previously cleared.
 */
//lint -emacro(717, REG_WRITE_BITS_SAFE) do ... while(0)
#define REG_WRITE_BITS_SAFE(reg, mask, val) do { \
        uint32_t threshold = IRQ_DisableAndSaveInterrupts(); \
        (reg) = ((reg) & ~(mask)) | ((mask) & (val)); \
        IRQ_RestoreInterrupts(threshold); \
    } while(0)


/**
 * @brief Provides the number of entires in an array.
 * @param array_ The array to determine the number of entries for.
 */
#define ARRAY_DIM(array_) (sizeof(array_) / sizeof((array_)[0]))


#ifndef MIN

/**
 * @brief Return the minimum of a and b.
 * @param a One of the values.
 * @param b One of the values.
 * @returns The minimum of a and b.
 */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#endif /* MIN */


#ifndef MAX

/**
 * @brief Return the maximum of a and b.
 * @param a One of the values.
 * @param b One of the values.
 * @returns The maximum of a and b.
 */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif /* MAX */

/**
 * @brief convert uint32_t to little endian byte stream.
 * @param p little endian byte stream.
 * @param n uint32_t.
 */
#define UINT32_TO_BUF(p, n)       {(p)[0] = (uint8_t)(n); (p)[1] = (uint8_t)((n) >> 8); (p)[2] = (uint8_t)((n) >> 16); (p)[3] = (uint8_t)((n) >> 24);}


/**
 * @brief convert little endian byte buffer to uint32_t.
 * @param n uint32_t.
 * @param p little endian byte stream.
 */
#define BUF_TO_UINT32(n, p)     {n = ((uint32_t)(p)[0] + ((uint32_t)(p)[1] << 8) + \
                                        ((uint32_t)(p)[2] << 16) + ((uint32_t)(p)[3] << 24));}


/**
 * @brief convert little endian byte buffer to uint16_t.
 * @param n uint16_t.
 * @param p little endian byte stream.
 */
#define BUF_TO_UINT16(n, p)     {n = (uint16_t)((uint16_t)(p)[0] + ((uint16_t)(p)[1] << 8));}


/**
 * @brief Memory barrier to ensure instructions are not re-ordered.
 */
#define MEM_BARRIER() __asm__ __volatile__("" : : : "memory")


/**
 * @brief Specify the section to place the function or static variable in.
 * @param name Name of the section to place the item in.
 */
#define SECTION(name) __attribute__ ((section(name), used))


/**
 * @brief Place the structure before all other configuration structures in
 *   non-persistent memory.
 */
#define SECTION_MASTER_CONFIG volatile SECTION(".master_config")


/**
 * @brief Group the structure with all other configuration structures after
 *   the main configuration structure in non-persistent memory.
 */
#define SECTION_CONFIG volatile SECTION(".config")


/**
 * @brief Group the structure with NVM bootloader section
 */
#ifndef TEST_CODE
# define SECTION_NVM_BOOTLOADER SECTION(".nvm_bootloader")
#else
// Remove the .nvm_bootloader section to be able to test the functions in unit tests.
# define SECTION_NVM_BOOTLOADER
#endif


/**
 * @brief Group the structure with NVM init section
 */
#define SECTION_NVM_ENTRY SECTION(".nvm_entry")


/**
 * @brief Place the variable in persistent memory.
 * @note This veriable is not initialized by initcopy.
 */
#define SECTION_PERSISTENT SECTION(".persistent")


/**
 * @brief Place the variable in non-persistent memory.
 * @note This variable is not initialized by initcopy. // @todo Currently it is initialized...
 */
#define SECTION_NONPERSISTENT SECTION(".non_persistent")


/**
 * @brief Place the variable in non-persistent memory and do not initialize it
 * with a value.
 */
#define SECTION_NP_NOINIT SECTION(".noinit")


/**
 * @brief Place the constant in ROM.
 * @note This variable will NOT be copied into RAM for future patching.
 */
#define ROM_CONST SECTION(".rom_const")


/**
 * @brief Place the constant in ROM.
 * @note This variable will NOT be copied into RAM for future patching.
 */
#define IROM_CONST SECTION(".irom_const")


/**
 * @brief Place the constant in NVM main area.
 */
#define NVM_CONST SECTION(".nvm_const")


/**
 * @brief Place the constant in NVM info area.
 */
#define NVM_INFO_CONST SECTION(".nvm_info_const")


/**
 * @brief Place the constant in ROM or in NVM depending on the linker.
 */
#define ROM_NVM_CONST SECTION(".rom_nvm_const")


/**
 * @brief ROM version information.
 * @note This variable will NOT be copied into RAM for future patching.
 */
#define SECTION_ROM_VERSION SECTION(".rom_version")


/**
 * @brief Replace a JLI entry with the given function.
 * @param entry JLI entry name to replace.
 * @param symbol Name of the function (or symbol) to replace it with.
 */
//lint -emacro(19, JLI_REPLACE) "useless" code needed by configedit
#define JLI_REPLACE(entry, symbol) \
    __asm__(".global __jliReplace_" #entry "$" #symbol); \
    __asm__(".set __jliReplace_" #entry "$" #symbol ", 0")


/**
 * @brief Override a JLI entry with the implementation in the patch.
 * @param entry JLI entry name to override.
 */
//lint -emacro(19, JLI_OVERRIDE) "useless" code needed by configedit
#define JLI_OVERRIDE(entry) \
    __asm__(".global __jliReplace_" #entry "$" #entry); \
    __asm__(".set __jliReplace_" #entry "$" #entry ", 0")


#define xstr(a) str(a)
#define str(a) #a


/**
 * @brief Set a JLI entry with the implementation in the patch.
 * @param index Index of the JLI entry to set.
 * @param entry Name of the function (or symbol) to set the entry with.
 */
//lint -emacro(19, JLI_SET) "useless" code needed by configedit
#define JLI_SET(index, entry) \
    __asm__(".global __jliSet_" xstr(index) "$" #entry); \
    __asm__(".set __jliSet_" xstr(index) "$" #entry ", 0")


/**
 * @brief Declare a function that may be called by it's ID.
 * @param id ID of the function to bind.
 * @param entry Name of the function to bind.
 */
//lint -emacro(19, BIND_FUNCTION) "useless" code needed by configedit
#define BIND_FUNCTION(id, entry) \
    __asm__(".global __bindFunction_" xstr(id) "$" #entry); \
    __asm__(".set __bindFunction_" xstr(id) "$" #entry ", 0")


/**
 * @brief Declare the function as the entry point for the patch.
 * @param entry Name of the function to use as the entry point.
 */
//lint -emacro(19, ENTRY_FUNCTION) "useless" code needed by configedit
#define ENTRY_FUNCTION(entry) \
    __asm__(".global __entryFunction_" #entry); \
    __asm__(".set __entryFunction_" #entry ", 0")


/**
 * @brief Declare the function as the entry point for the patch.
 * @param entry Name of the function to use as the entry point.
 */
#define MODULE_ENTRY(entry) ENTRY_FUNCTION(entry)


/**
 * @brief Declare a function that may be called by it's ID.
 * @param id ID of the function to bind.
 * @param entry Name of the function to bind.
 */
#define MODULE_FUNCTION(id, entry) BIND_FUNCTION(id, entry)


/**
 * @brief Replace the initial data for the given variable.
 * @param original Name of the original variable.
 * @param replacement Name of the variable with the new initial data.
 */
#define VAR_REPLACE(type, original, replacement) \
    SECTION(".override_vars." #replacement) type replacement; \
    __asm__(".global __varReplace_" #original "$" #replacement); \
    __asm__(".set __varReplace_" #original "$" #replacement ", 0")


/**
 * @brief Replace the initial data for the given variable.
 * @param variable Name of the variable to replace the initial data of.
 */
#define VAR_OVERRIDE(type, variable) \
    SECTION(".override_vars." #variable) type variable; \
    __asm__(".global __varReplace_" #variable "$" #variable); \
    __asm__(".set __varReplace_" #variable "$" #variable ", 0")

/**
 * @brief Allow a constant pointer to be modified.
 * @param ptr Pointer to the constant variable to modify.
 * @returns Pointer to the variable to modify.
 * @note WARNING: This should only be used if the constant is in memory.
 */
static _Inline void* MODIFY_CONST(volatile const void *ptr)
{
    union {
        volatile const void *a;
        void *b;
    }p;
    p.a = ptr;
    return p.b;
}


/**
 * @brief Round the value up to a multiple of alignment.
 * @param alignment Make value a multiple of this number.
 * @param value Number to round.
 * @returns Value rounded up to a multiple of alignment.
 */
static _Inline unsigned int AlignUp(unsigned int value,
    unsigned int alignment)
{
    return ((value + alignment - 1u) / alignment) * alignment;
}

/**
 * @brief Round the value up to a multiple of alignment.
 * @param alignment Make value a multiple of this number.
 * @param value Number to round (unsigned short).
 * @returns Value rounded up to a multiple of alignment.
 */
static _Inline unsigned short AlignUp16(unsigned short value,
    unsigned short alignment)
{
    return ((value + alignment - 1u) / alignment) * alignment;
}


/**
 * @brief Round the value down to a multiple of alignment.
 * @param alignment Make value a multiple of this number.
 * @param value Number to round.
 * @returns Value rounded down to a multiple of alignment.
 */
static _Inline unsigned int AlignDown(unsigned int value,
    unsigned int alignment)
{
    return (value / alignment) * alignment;
}


/**
 * Read the blink register.
 * @returns Address in the blink register.
 */
static _Inline unsigned int GetReturnAddress(void)
{
    unsigned int blink; //lint !e530

    __asm__("mov %0,%%blink" : "=r"(blink) : :);

    return blink;
}


/**
 * Set the blink register.
 * @param blink Address to set the blink register to.
 */
static _Inline void SetReturnAddress(unsigned int blink)
{
    __asm__("mov %%blink,%0" : : "r"(blink) :);
}


/**
 * @}
 */


#endif /* _MACROS_H */
