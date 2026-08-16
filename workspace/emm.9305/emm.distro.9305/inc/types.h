////////////////////////////////////////////////////////////////////////////////
///
/// @file       types.h
///
/// @project    T9305
///
/// @brief      Standard data types
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


#ifndef _TYPES_H
#define _TYPES_H

#include "macros.h"

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>


/******************************************************************************\
 *  MACROS
\******************************************************************************/
#define NO_RETURN       __attribute__((noreturn))

#define PACKED_STRUCT   __attribute__((packed))

#ifdef _ARCVER
#define ALWAYS_INLINE   _Inline
#else
#define ALWAYS_INLINE   inline
#define _Interrupt
#endif

#define NEVER_INLINE    __attribute__ ((noinline))

#define __I             volatile const      /**< IO access (read only) */
#define __O             volatile            /**< IO access (write only) */
#define __IO            volatile            /**< IO access (read/write) */

#ifndef TRUE
#define TRUE            (bool)1             /**< True */
#endif /* !TRUE */

#ifndef FALSE
#define FALSE           (bool)0             /**< False */
#endif /* !FALSE */

#ifndef NULL
#define NULL            ((void*)0)          /**< Null pointer */
#endif /* !NULL */

#ifndef UNUSED
#define UNUSED(x)      (void)(x)           /**< Usued parameter */
#endif /* !UNUSED */


/******************************************************************************\
 *  TYPE DEFINITION
\******************************************************************************/

/** reg32_t type allowing various accesses. */
typedef union {
  uint32_t  r32;                            /**< 32b access. */
  uint16_t  r16[2];                         /**< 16b access. */
  uint8_t   r8[4];                          /**< 8b access. */
} reg32_t;

#ifndef __CPLUSPLUS__
#ifndef bool
#error bool not defined
typedef char            bool;               /**< Boolean. */
#endif /* !bool */
#endif

// Sanity check the size of a bool if it is used inside a structure.
_Static_assert(1 == sizeof(bool), "bool is not 1 byte.");
_Static_assert(0 == false, "false should evaluate to 0.");
_Static_assert(1 == true, "true should evaluate to 1.");
_Static_assert(0 == FALSE, "FALSE should evaluate to 0.");
_Static_assert(1 == TRUE, "TRUE should evaluate to 1.");

/**
 * @brief Type to access a pointer.
 *
 * This type allows access to a pointer as many different types.
 */
typedef union
{
    /// Access the pointer as a const void*.
    const void *pConstVoid;
    /// Access the pointer as a void*.
    void *pVoid;
    /// Access the pointer as a pointer to a signed 8-bit integer.
    int8_t *pInt8;
    /// Access the pointer as a pointer to a signed 16-bit integer.
    int16_t *pInt16;
    /// Access the pointer as a pointer to a signed 32-bit integer.
    int32_t *pInt32;
    /// Access the pointer as a pointer to an unsigned 8-bit integer.
    uint8_t *pUInt8;
    /// Access the pointer as a pointer to an unsigned 16-bit integer.
    uint16_t *pUInt16;
    /// Access the pointer as a pointer to an unsigned 32-bit integer.
    uint32_t *pUInt32;
    /// Access the pointer as an unsigned 32-bit integer for arithmetic.
    uint32_t u32;
} Pointer_t;

/**
 * Absolute timestamp of the system timer (sleep timer).
 */
typedef uint32_t SystemTime_t;

/**
 * @brief This macro allows testing static (private) functions
 * and variables only when building for unit tests
 */
#ifdef TEST_CODE
    #define STATIC
    #define EXTERN extern
#else
    #define STATIC static
    #define EXTERN static

#endif

#endif /* _TYPES_H */
