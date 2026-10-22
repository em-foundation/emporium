import '@$$emscript'
export const $U = $declare('MODULE', MathOpsI)

import * as MathOpsI from '@em.crypto.p256/MathOpsI.em'
import * as T from '@em.crypto.p256/Types.em'

/*
Copyright 2018 Emil Lenngren

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

// Inversion uses the reference fixed-chain M0 assembly schedule.
// Point doubling and addition use adapted unrolled M0 formulas.
// Field multiply, square, add, subtract and half use adapted M0 assembly.
// times2 also benefits by calling the M0 modular add with aliased inputs.
// Raw kernels clobber r4-r11; wrappers preserve them and align SP at entry.
// Inputs are consumed before the output is stored, allowing mul(a,a).
export namespace em$meta { }


//>> ---- em$targ ---- <<//

a$`naked,noinline`
export function add(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                mov r2,r1
                mov r1,r0
                bl __em_p256_m0_addmod
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
            )"
        );
    `
}

export function copy(a: T.U256_Ref, b: T.U256_Ref) {
    T.copyU256(a, b)
}


// Keep the complete doubling formula in the raw M0 calling convention,
// avoiding per-field-operation register saves and temporary copies.
a$`naked,noinline`
export function doublePoint(p: $$<T.PointJ>) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                mov r1,r0
                bl __em_p256_m0_double_j
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
            )"
        );
    `
}

// Same non-overlapping Jacobian operands as the portable formula.
// Keep field operations in the raw M0 ABI; preserve the caller's registers once.
a$`naked,noinline`
export function addPointJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                bl __em_p256_m0_add_j
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
            )"
        );
    `
}

export function quadDoubleAddPointJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    doublePoint(p)
    doublePoint(p)
    doublePoint(p)
    doublePoint(p)
    addPointJacobian(p, q)
}


// Reference fixed-chain inversion, with squaring loops using the raw M0 ABI.
// Preserve the external caller's registers once for the entire inversion.
a$`naked,noinline`
export function inv(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                bl __em_p256_m0_modinv
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
            )"
        );
    `
}

a$`naked,noinline`
export function mul(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                mov r2,r1
                mov r1,r0
                bl __em_p256_m0_mulmod
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
	.syntax unified
	.thumb
// P-256 ECDH
// Author: Emil Lenngren
// Licensed under the BSD 2-clause license.
// The 256x256->512 multiplication/square code is based on public domain ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚ÂµNaCl by Ana Helena SÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡nchez and BjÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¶rn Haase (https://munacl.cryptojedi.org/curve25519-cortexm0.shtml)

// Note on calling conventions: some of the local functions in this file use custom calling conventions.
// Exported symbols use the standard C calling conventions for ARM, which means that r4-r11 and sp are preserved and the other registers are clobbered.

// Stack usage is 1356 bytes.

// Settings below for optimizing for speed vs size.
// When optimizing fully for speed, the run time is 4 456 738 cycles and code size is 3708 bytes.
// When optimizing fully for size, the run time is 5 764 182 cycles and code size is 2416 bytes.
// Get the time taken (in seconds) by dividing the number of cycles with the clock frequency (Hz) of the cpu.
// Different optimization levels can be done by setting some to 1 and some to 0.
// Optimizing all settings for size except use_mul_for_sqr and use_smaller_modinv gives a run time of 4 851 527 cycles and code size is 2968 bytes.

	
.set use_mul_for_sqr, 0 // 1 to enable, 0 to disable (14% slower if enabled but saves 624/460 bytes (depending on use_noninlined_sqr64) of compiled code size)

	
.set use_noninlined_mul64, 0 // 1 to enable, 0 to disable (2.6%/4.0% slower (depending on use_mul_for_sqr) if enabled but saves 308 bytes of compiled code size)

	
.set use_noninlined_sqr64, 0 // 1 to enable, 0 to disable (2.4% slower if enabled and use_mul_for_sqr=0 but saves 164 bytes of compiled code size)

	
.set use_interpreter, 1 // 1 to enable, 0 to disable (3.6% slower if enabled but saves 268 bytes of compiled code size)

	
.set use_smaller_modinv, 0 // 1 to enable, 0 to disable (3.6% slower if enabled but saves 88 bytes of compiled code size)

	.text
	.align 1

	.if use_noninlined_mul64 == 1
// in: (r4,r5) = a[0..1], (r2,r3) = b[0..1]
// out: r0-r3
// clobbers r4-r9 and lr
	.type __em_p256_m0_mul64, %function
__em_p256_m0_mul64:
	mov r6,r5
	mov r1,r2
	subs r5,r4
	sbcs r0,r0
	eors r5,r0
	subs r5,r0
	subs r1,r3
	sbcs r7,r7
	eors r1,r7
	subs r1,r7
	eors r7,r0
	mov r9,r1
	mov r8,r5
	lsrs r1,r4,#16
	uxth r4,r4
	mov r0,r4
	uxth r5,r2
	lsrs r2,#16
	muls r0,r5,r0////00
	muls r5,r1,r5////10
	muls r4,r2,r4////01
	muls r1,r2,r1////11
	lsls r2,r4,#16
	lsrs r4,r4,#16
	adds r0,r2
	adcs r1,r4
	lsls r2,r5,#16
	lsrs r4,r5,#16
	adds r0,r2
	adcs r1,r4
	lsrs r4,r6,#16
	uxth r6,r6
	uxth r5,r3
	lsrs r3,r3,#16
	mov r2,r6
	muls r2,r5,r2
	muls r5,r4,r5
	muls r6,r3,r6
	muls r3,r4,r3
	lsls r4,r5,#16
	lsrs r5,r5,#16
	adds r2,r4
	adcs r3,r5
	lsls r4,r6,#16
	lsrs r5,r6,#16
	adds r2,r4
	adcs r3,r5
	eors r6,r6
	adds r2,r1
	adcs r3,r6
	mov r1,r9
	mov r5,r8
	mov r8,r0
	lsrs r0,r1,#16
	uxth r1,r1
	mov r4,r1
	lsrs r6,r5,#16
	uxth r5,r5
	muls r1,r5,r1
	muls r4,r6,r4
	muls r5,r0,r5
	muls r0,r6,r0
	lsls r6,r4,#16
	lsrs r4,#16
	adds r1,r6
	adcs r0,r4
	lsls r6,r5,#16
	lsrs r5,#16
	adds r1,r6
	adcs r0,r5
	eors r1,r7
	eors r0,r7
	eors r4,r4
	asrs r7,r7,#1
	adcs r1,r2
	adcs r2,r0
	adcs r7,r4
	mov r0,r8
	adds r1,r0
	adcs r2,r3
	adcs r3,r7
	bx lr
	.size __em_p256_m0_mul64, .-__em_p256_m0_mul64
	.endif

// in: *r10 = a, *r11 = b, (r4,r5) = a[0..1], (r2,r3) = b[0..1]
// out: r8,r9,r2-r7
// clobbers all other registers
	.type __em_p256_m0_mul128, %function
__em_p256_m0_mul128:
	.if use_noninlined_mul64 == 1
	push {lr}
	//frame push {lr}
	.endif
			/////////MUL128/////////////
			//MUL64
			.if use_noninlined_mul64 == 0
			mov r6,r5
			mov r1,r2
			subs r5,r4
			sbcs r0,r0
			eors r5,r0
			subs r5,r0
			subs r1,r3
			sbcs r7,r7
			eors r1,r7
			subs r1,r7
			eors r7,r0
			mov r9,r1
			mov r8,r5
			lsrs r1,r4,#16
			uxth r4,r4
			mov r0,r4
			uxth r5,r2
			lsrs r2,#16
			muls r0,r5,r0////00
			muls r5,r1,r5////10
			muls r4,r2,r4////01
			muls r1,r2,r1////11
			lsls r2,r4,#16
			lsrs r4,r4,#16
			adds r0,r2
			adcs r1,r4
			lsls r2,r5,#16
			lsrs r4,r5,#16
			adds r0,r2
			adcs r1,r4
			lsrs r4,r6,#16
			uxth r6,r6
			uxth r5,r3
			lsrs r3,r3,#16
			mov r2,r6
			muls r2,r5,r2
			muls r5,r4,r5
			muls r6,r3,r6
			muls r3,r4,r3
			lsls r4,r5,#16
			lsrs r5,r5,#16
			adds r2,r4
			adcs r3,r5
			lsls r4,r6,#16
			lsrs r5,r6,#16
			adds r2,r4
			adcs r3,r5
			eors r6,r6
			adds r2,r1
			adcs r3,r6
			mov r1,r9
			mov r5,r8
			mov r8,r0
			lsrs r0,r1,#16
			uxth r1,r1
			mov r4,r1
			lsrs r6,r5,#16
			uxth r5,r5
			muls r1,r5,r1
			muls r4,r6,r4
			muls r5,r0,r5
			muls r0,r6,r0
			lsls r6,r4,#16
			lsrs r4,#16
			adds r1,r6
			adcs r0,r4
			lsls r6,r5,#16
			lsrs r5,#16
			adds r1,r6
			adcs r0,r5
			eors r1,r7
			eors r0,r7
			eors r4,r4
			asrs r7,r7,#1
			adcs r1,r2
			adcs r2,r0
			adcs r7,r4
			mov r0,r8
			adds r1,r0
			adcs r2,r3
			adcs r3,r7
			.else
			bl __em_p256_m0_mul64
			.endif
		push {r0,r1}
		//frame address sp,8+use_noninlined_mul64*4
		mov r1,r10
		mov r10,r2
		ldm r1,{r0,r1,r4,r5}
		mov r2,r4
		mov r7,r5
		subs r2,r0
		sbcs r7,r1
		sbcs r6,r6
		eors r2,r6
		eors r7,r6
		subs r2,r6
		sbcs r7,r6
		push {r2,r7}
		//frame address sp,16+use_noninlined_mul64*4
		mov r2,r11
		mov r11,r3
		ldm r2,{r0,r1,r2,r3}
		subs r0,r2
		sbcs r1,r3
		sbcs r7,r7
		eors r0,r7
		eors r1,r7
		subs r0,r7
		sbcs r1,r7
		eors r7,r6
		mov r12,r7
		push {r0,r1}
		//frame address sp,24+use_noninlined_mul64*4
			//MUL64
			.if use_noninlined_mul64 == 0
			mov r6,r5
			mov r1,r2
			subs r5,r4
			sbcs r0,r0
			eors r5,r0
			subs r5,r0
			subs r1,r3
			sbcs r7,r7
			eors r1,r7
			subs r1,r7
			eors r7,r0
			mov r9,r1
			mov r8,r5
			lsrs r1,r4,#16
			uxth r4,r4
			mov r0,r4
			uxth r5,r2
			lsrs r2,#16
			muls r0,r5,r0////00
			muls r5,r1,r5////10
			muls r4,r2,r4////01
			muls r1,r2,r1////11
			lsls r2,r4,#16
			lsrs r4,r4,#16
			adds r0,r2
			adcs r1,r4
			lsls r2,r5,#16
			lsrs r4,r5,#16
			adds r0,r2
			adcs r1,r4
			lsrs r4,r6,#16
			uxth r6,r6
			uxth r5,r3
			lsrs r3,r3,#16
			mov r2,r6
			muls r2,r5,r2
			muls r5,r4,r5
			muls r6,r3,r6
			muls r3,r4,r3
			lsls r4,r5,#16
			lsrs r5,r5,#16
			adds r2,r4
			adcs r3,r5
			lsls r4,r6,#16
			lsrs r5,r6,#16
			adds r2,r4
			adcs r3,r5
			eors r6,r6
			adds r2,r1
			adcs r3,r6
			mov r1,r9
			mov r5,r8
			mov r8,r0
			lsrs r0,r1,#16
			uxth r1,r1
			mov r4,r1
			lsrs r6,r5,#16
			uxth r5,r5
			muls r1,r5,r1
			muls r4,r6,r4
			muls r5,r0,r5
			muls r0,r6,r0
			lsls r6,r4,#16
			lsrs r4,#16
			adds r1,r6
			adcs r0,r4
			lsls r6,r5,#16
			lsrs r5,#16
			adds r1,r6
			adcs r0,r5
			eors r1,r7
			eors r0,r7
			eors r4,r4
			asrs r7,r7,#1
			adcs r1,r2
			adcs r2,r0
			adcs r7,r4
			mov r0,r8
			adds r1,r0
			adcs r2,r3
			adcs r3,r7
			.else
			bl __em_p256_m0_mul64
			.endif
		mov r4,r10
		mov r5,r11
		eors r6,r6
		adds r0,r4
		adcs r1,r5
		adcs r2,r6
		adcs r3,r6
		mov r10,r2
		mov r11,r3
		pop {r2-r5}
		//frame address sp,8+use_noninlined_mul64*4
		push {r0,r1}
		//frame address sp,16+use_noninlined_mul64*4
			.if use_noninlined_mul64 == 0
			mov r6,r5
			mov r1,r2
			subs r5,r4
			sbcs r0,r0
			eors r5,r0
			subs r5,r0
			subs r1,r3
			sbcs r7,r7
			eors r1,r7
			subs r1,r7
			eors r7,r0
			mov r9,r1
			mov r8,r5
			lsrs r1,r4,#16
			uxth r4,r4
			mov r0,r4
			uxth r5,r2
			lsrs r2,#16
			muls r0,r5,r0////00
			muls r5,r1,r5////10
			muls r4,r2,r4////01
			muls r1,r2,r1////11
			lsls r2,r4,#16
			lsrs r4,r4,#16
			adds r0,r2
			adcs r1,r4
			lsls r2,r5,#16
			lsrs r4,r5,#16
			adds r0,r2
			adcs r1,r4
			lsrs r4,r6,#16
			uxth r6,r6
			uxth r5,r3
			lsrs r3,r3,#16
			mov r2,r6
			muls r2,r5,r2
			muls r5,r4,r5
			muls r6,r3,r6
			muls r3,r4,r3
			lsls r4,r5,#16
			lsrs r5,r5,#16
			adds r2,r4
			adcs r3,r5
			lsls r4,r6,#16
			lsrs r5,r6,#16
			adds r2,r4
			adcs r3,r5
			eors r6,r6
			adds r2,r1
			adcs r3,r6
			mov r1,r9
			mov r5,r8
			mov r8,r0
			lsrs r0,r1,#16
			uxth r1,r1
			mov r4,r1
			lsrs r6,r5,#16
			uxth r5,r5
			muls r1,r5,r1
			muls r4,r6,r4
			muls r5,r0,r5
			muls r0,r6,r0
			lsls r6,r4,#16
			lsrs r4,#16
			adds r1,r6
			adcs r0,r4
			lsls r6,r5,#16
			lsrs r5,#16
			adds r1,r6
			adcs r0,r5
			eors r1,r7
			eors r0,r7
			eors r4,r4
			asrs r7,r7,#1
			adcs r1,r2
			adcs r2,r0
			adcs r7,r4
			mov r0,r8
			adds r1,r0
			adcs r2,r3
			adcs r3,r7
			.else
			bl __em_p256_m0_mul64
			.endif
		pop {r4,r5}
		//frame address sp,8+use_noninlined_mul64*4
		mov r6,r12
		mov r7,r12
		eors r0,r6
		eors r1,r6
		eors r2,r6
		eors r3,r6
		asrs r6,r6,#1
		adcs r0,r4
		adcs r1,r5
		adcs r4,r2
		adcs r5,r3
		eors r2,r2
		adcs r6,r2 ////0,1
		adcs r7,r2
		pop {r2,r3}
		//frame address sp,0+use_noninlined_mul64*4
		mov r8,r2
		mov r9,r3
		adds r2,r0
		adcs r3,r1
		mov r0,r10
		mov r1,r11
		adcs r4,r0
		adcs r5,r1
		adcs r6,r0
		adcs r7,r1
	.if use_noninlined_mul64 == 1
	pop {pc}
	.else
	bx lr
	.endif
	.size __em_p256_m0_mul128, .-__em_p256_m0_mul128
	
	.if use_mul_for_sqr == 1
.thumb_func
__em_p256_m0_sqrmod :
	mov r2,r1
	// fallthrough
	.endif

// *r0 = out, *r1 = a, *r2 = b
	.type __em_p256_m0_mulmod, %function
__em_p256_m0_mulmod:
	push {r0,lr}
	//frame push {lr}
	//frame address sp,8
	sub sp,#64
	//frame address sp,72
	push {r1-r2}
	//frame address sp,80
	mov r10,r2
	mov r11,r1
	mov r0,r2
	ldm r0!,{r4,r5}
	adds r0,#8
	ldm r1!,{r2,r3}
	adds r1,#8
	push {r0,r1}
	//frame address sp,88
	
	bl __em_p256_m0_mul128
	add r0,sp,#24
	stm r0!,{r2,r3}
	add r0,sp,#16
	mov r2,r8
	mov r3,r9
	stm r0!,{r2,r3}

	//pop {r0} //result+8
	//stm r0!,{r2,r3}
	pop {r1,r2} //a+16 b+16
	//frame address sp,80
	//push {r0}
	push {r4-r7}
	//frame address sp,96
	mov r10,r1
	mov r11,r2
	ldm r1!,{r4,r5}
	ldm r2,{r2,r3}
	
	bl __em_p256_m0_mul128
	
	mov r0,r8
	mov r1,r9
	mov r8,r6
	mov r9,r7
	pop {r6,r7}
	//frame address sp,88
	adds r0,r6
	adcs r1,r7
	pop {r6,r7}
	//frame address sp,80
	adcs r2,r6
	adcs r3,r7
	//pop {r7} //result+16
	add r7,sp,#24
	stm r7!,{r0-r3}
	mov r10,r7
	eors r0,r0
	mov r6,r8
	mov r7,r9
	adcs r4,r0
	adcs r5,r0
	adcs r6,r0
	adcs r7,r0
	pop {r1,r2} //b a
	//frame address sp,72
	mov r12,r2
	push {r4-r7}
	//frame address sp,88
	ldm r1,{r0-r7}
	subs r0,r4
	sbcs r1,r5
	sbcs r2,r6
	sbcs r3,r7
	eors r4,r4
	sbcs r4,r4
	eors r0,r4
	eors r1,r4
	eors r2,r4
	eors r3,r4
	subs r0,r4
	sbcs r1,r4
	sbcs r2,r4
	sbcs r3,r4
	mov r6,r12
	mov r12,r4 ////carry
	mov r5,r10
	stm r5!,{r0-r3}
	mov r11,r5
	mov r8,r0
	mov r9,r1
	ldm r6,{r0-r7}
	subs r4,r0
	sbcs r5,r1
	sbcs r6,r2
	sbcs r7,r3
	eors r0,r0
	sbcs r0,r0
	eors r4,r0
	eors r5,r0
	eors r6,r0
	eors r7,r0
	subs r4,r0
	sbcs r5,r0
	sbcs r6,r0
	sbcs r7,r0
	mov r1,r12
	eors r0,r1
	mov r1,r11
	stm r1!,{r4-r7}
	push {r0}
	//frame address sp,92
	mov r2,r8
	mov r3,r9
	
	bl __em_p256_m0_mul128
	
	pop {r0} ////r0,r1
	//frame address sp,88
	mov r12,r0 ////negative
	eors r2,r0
	eors r3,r0
	eors r4,r0
	eors r5,r0
	eors r6,r0
	eors r7,r0
	push {r4-r7}
	//frame address sp,104
	add r1,sp,#32 //result
	ldm r1!,{r4-r7}
	//mov r11,r1 ////reference
	mov r1,r9
	eors r1,r0
	mov r10,r4
	mov r4,r8
	asrs r0,#1
	eors r0,r4
	mov r4,r10
	adcs r0,r4
	adcs r1,r5
	adcs r2,r6
	adcs r3,r7
	eors r4,r4
	adcs r4,r4
	mov r10,r4 ////carry
	//mov r4,r11
	add r4,sp,#32+16
	ldm r4,{r4-r7}
	adds r0,r4
	adcs r1,r5
	adcs r2,r6
	adcs r3,r7
	mov r9,r4
	//mov r4,r11
	add r4,sp,#32+16
	stm r4!,{r0-r3}
	//mov r11,r4
	pop {r0-r3}
	//frame address sp,88
	mov r4,r9
	adcs r4,r0
	adcs r5,r1
	adcs r6,r2
	adcs r7,r3
	movs r1,#0
	adcs r1,r1
	mov r0,r10
	mov r10,r1 ////carry
	asrs r0,#1
	pop {r0-r3}
	//frame address sp,72
	adcs r4,r0
	adcs r5,r1
	adcs r6,r2
	adcs r7,r3
	mov r8,r0
	//mov r0,r11
	add r0,sp,#32
	stm r0!,{r4-r7}
	//mov r11,r0
	mov r0,r8
	mov r6,r12
	mov r5,r10
	eors r4,r4
	adcs r5,r6
	adcs r6,r4
	adds r0,r5
	adcs r1,r6
	adcs r2,r6
	adcs r3,r6
	//mov r7,r11
	add r7,sp,#32+16
	stm r7!,{r0-r3}
	
	// multiplication done, now reducing

reduce :
	pop {r0-r7}
	//frame address sp,40
	adds r3,r0
	adcs r4,r1
	adcs r5,r2
	adcs r6,r0
	mov r8,r2
	mov r9,r3
	mov r10,r4
	mov r11,r5
	mov r12,r6
	adcs r7,r1
	pop {r2-r5} //8,9,10,11
	//frame address sp,24
	adcs r2,r0 //8+0
	adcs r3,r1 //9+1
	movs r6,#0
	adcs r4,r6 //10+#0
	adcs r5,r6 //11+#0
	adcs r6,r6 //C
	
	subs r7,r0 //7-0
	sbcs r2,r1 //8-1
	// r0,r1 dead
	mov r0,r8 //2
	mov r1,r9 //3
	sbcs r3,r0 //9-2
	sbcs r4,r1 //10-3
	movs r0,#0
	sbcs r5,r0 //11-#0
	sbcs r6,r0 //C-#0
	
	mov r0,r12 //6
	adds r0,r1 //6+3
	mov r12,r0
	mov r0,r10 //4
	adcs r7,r0 //7+4
	mov lr,r7
	mov r0,r8 //2
	adcs r2,r0 //8+2
	adcs r3,r1 //9+3
	adcs r4,r0 //10+2
	adcs r5,r1 //11+3
	movs r7,#0
	adcs r6,r7 //C+#0
	
	//2-3 are now dead (r8,r9)
	//4   5   6   7  8  9  10 11 C
	//r10 r11 r12 lr r2 r3 r4 r5 r6
	//r7: 0
	
	pop {r0,r1} //12,13
	//frame address sp,16
	
	adds r6,r0 //12+C
	adcs r1,r7 //13+#0
	adcs r7,r7 //new Carry for 14
	
	//r0 dead
	
	mov r0,r11 //5
	adds r2,r0 //8+5
	mov r8,r2
	mov r2,r12 //6
	adcs r3,r2 //9+6
	mov r9,r3
	mov r3,r10 //4
	adcs r4,r3 //10+4
	mov r10,r4
	adcs r5,r0 //11+5
	adcs r6,r3 //12+4
	adcs r1,r0 //13+5
	pop {r2,r4} //14,15
	//frame address sp,8
	adcs r2,r7 //14+C
	movs r7,#0
	adcs r4,r7 //15+#0
	adcs r7,r7 //new Carry for 16
	
	//4  5  6   7  8  9  10  11 12 13 14 15 C
	//r3 r0 r12 lr r8 r9 r10 r5 r6 r1 r2 r4 r7
	//r11 is available
	
	subs r5,r3 //11-4
	sbcs r6,r0 //12-5
	mov r3,r12 //6
	mov r0,lr //7
	sbcs r1,r3 //13-6
	sbcs r2,r0 //14-7
	movs r3,#0
	sbcs r4,r3 //15-#0
	sbcs r7,r3 //C-#0
	mov lr,r4
	mov r11,r7
	
	mov r4,r10 //10
	adds r4,r0 //10+7
	adcs r5,r3 //11+#0
	mov r7,r12 //6
	adcs r6,r7 //12+6
	adcs r1,r0 //13+7
	adcs r2,r7 //14+6
	mov r7,lr //15
	adcs r7,r0 //15+7
	mov r0,r11 //C
	adcs r0,r3 //C+#0
	
	// now (T + mN) / R is
	// 8 9 4 5 6 1 2 7 6 (lsb -> msb)
	
	subs r3,r3 //set r3 to 0 and C to 1
	mov r10,r0
	mov r0,r8
	adcs r0,r3
	mov r11,r7
	mov r7,r9
	adcs r7,r3
	mov r12,r0
	mov r9,r7
	adcs r4,r3
	sbcs r5,r3
	sbcs r6,r3
	sbcs r1,r3
	movs r3,#1
	sbcs r2,r3
	movs r3,#0
	mov r0,r11
	mov r7,r10
	adcs r0,r3
	sbcs r7,r3
	
	// r12 r9 r4 r5 | r6 r1 r2 r0
	
	mov r8,r2
	mov r2,r12
	mov r11,r0
	mov r3,r9
reduce2 :
	adds r2,r7
	adcs r3,r7
	adcs r4,r7
	movs r0,#0
	adcs r5,r0
	adcs r6,r0
	adcs r1,r0
	pop {r0}
	//frame address sp,4
	stm r0!,{r2-r6}
	movs r5,#1
	ands r5,r7
	mov r2,r8
	mov r3,r11
	adcs r2,r5
	adcs r3,r7
	stm r0!,{r1-r3}
	
	pop {pc}
	
	.size __em_p256_m0_mulmod, .-__em_p256_m0_mulmod


	.if use_mul_for_sqr == 0

	.if use_noninlined_sqr64 == 1

	.type __em_p256_m0_sqr64, %function
__em_p256_m0_sqr64:
	 // START: sqr 64 Refined Karatsuba
 // Input operands in r4,r5
 // Result in r0,r1,r2,r3
 // Clobbers: r4-r6
 // START: sqr 32
 // Input operand in r4
 // Result in r0 ,r1
 // Clobbers: r2, r3
	uxth r0,r4
	lsrs r1,r4,#16
	mov r2,r0
	muls r2,r1,r2
	muls r0,r0,r0
	muls r1,r1,r1
	lsrs r3,r2,#15
	lsls r2,r2,#17
	adds r0,r2
	adcs r1,r3
 // End: sqr 32
 // Result in r0 ,r1
	subs r4,r5
	sbcs r6,r6
	eors r4,r6
	subs r4,r6
 // START: sqr 32
 // Input operand in r5
 // Result in r2 ,r3
 // Clobbers: r5, r6
	uxth r2,r5
	lsrs r3,r5,#16
	mov r5,r2
	muls r5,r3,r5
	muls r2,r2,r2
	muls r3,r3,r3
	lsrs r6,r5,#15
	lsls r5,r5,#17
	adds r2,r5
	adcs r3,r6
 // End: sqr 32
 // Result in r2 ,r3
	movs r6,#0
	adds r2,r1
	adcs r3,r6
 // START: sqr 32
 // Input operand in r4
 // Result in r4 ,r5
 // Clobbers: r1, r6
	lsrs r5,r4,#16
	uxth r4,r4
	mov r1,r4
	muls r1,r5,r1
	muls r4,r4,r4
	muls r5,r5,r5
	lsrs r6,r1,#15
	lsls r1,r1,#17
	adds r4,r1
	adcs r5,r6
 // End: sqr 32
 // Result in r4 ,r5
	mov r1,r2
	subs r1,r4
	sbcs r2,r5
	mov r5,r3
	movs r6,#0
	sbcs r3,r6
	adds r1,r0
	adcs r2,r5
	adcs r3,r6
 // END: sqr 64 Refined Karatsuba
 // Result in r0,r1,r2,r3
 // Leaves r6 zero.
	bx lr
	.size __em_p256_m0_sqr64, .-__em_p256_m0_sqr64

	.type __em_p256_m0_sqr128, %function
__em_p256_m0_sqr128:
	push {lr}
	//frame push {lr}
 // sqr 128 Refined Karatsuba
 // Input in r4 ... r7
 // Result in r0 ... r7
 // clobbers all registers
	mov r0,r4
	mov r1,r5
	subs r0,r6
	sbcs r1,r7
	sbcs r2,r2
	eors r0,r2
	eors r1,r2
	subs r0,r2
	sbcs r1,r2
	mov r8,r0
	mov r9,r1
	mov r10,r6

	bl __em_p256_m0_sqr64

	mov r4,r10
	mov r5,r7
	mov r10,r0
	mov r11,r1
	mov r12,r2
	mov r7,r3

	bl __em_p256_m0_sqr64

	mov r4,r12
	adds r0,r4
	adcs r1,r7
	adcs r2,r6
	adcs r3,r6
	mov r7,r3
	mov r12,r0
	mov r4,r8
	mov r8,r1
	mov r5,r9
	mov r9,r2

	bl __em_p256_m0_sqr64

	mov r4,r12
	mov r5,r8
	mov r6,r9
	subs r4,r0
	sbcs r5,r1
	mov r0,r6
	mov r1,r7
	sbcs r0,r2
	sbcs r1,r3
	movs r2,#0
	sbcs r6,r2
	sbcs r7,r2
	mov r2,r10
	adds r2,r4
	mov r3,r11
	adcs r3,r5
	mov r4,r12
	adcs r4,r0
	mov r5,r8
	adcs r5,r1
	movs r0,#0
	adcs r6,r0
	adcs r7,r0
	mov r0,r10
	mov r1,r11
 // END: sqr 128 Refined Karatsuba
	pop {pc}
	.size __em_p256_m0_sqr128, .-__em_p256_m0_sqr128
	.else
	.type __em_p256_m0_sqr128, %function
__em_p256_m0_sqr128:
 // sqr 128 Refined Karatsuba
 // Input in r4 ... r7
 // Result in r0 ... r7
 // clobbers all registers
	mov r0,r4
	mov r1,r5
	subs r0,r6
	sbcs r1,r7
	sbcs r2,r2
	eors r0,r2
	eors r1,r2
	subs r0,r2
	sbcs r1,r2
	mov r8,r0
	mov r9,r1
	mov r10,r6
 // START: sqr 64 Refined Karatsuba
 // Input operands in r4,r5
 // Result in r0,r1,r2,r3
 // Clobbers: r4-r6
 // START: sqr 32
 // Input operand in r4
 // Result in r0 ,r1
 // Clobbers: r2, r3
	uxth r0,r4
	lsrs r1,r4,#16
	mov r2,r0
	muls r2,r1,r2
	muls r0,r0,r0
	muls r1,r1,r1
	lsrs r3,r2,#15
	lsls r2,r2,#17
	adds r0,r2
	adcs r1,r3
 // End: sqr 32
 // Result in r0 ,r1
	subs r4,r5
	sbcs r6,r6
	eors r4,r6
	subs r4,r6
 // START: sqr 32
 // Input operand in r5
 // Result in r2 ,r3
 // Clobbers: r5, r6
	uxth r2,r5
	lsrs r3,r5,#16
	mov r5,r2
	muls r5,r3,r5
	muls r2,r2,r2
	muls r3,r3,r3
	lsrs r6,r5,#15
	lsls r5,r5,#17
	adds r2,r5
	adcs r3,r6
 // End: sqr 32
 // Result in r2 ,r3
	movs r6,#0
	adds r2,r1
	adcs r3,r6
 // START: sqr 32
 // Input operand in r4
 // Result in r4 ,r5
 // Clobbers: r1, r6
	lsrs r5,r4,#16
	uxth r4,r4
	mov r1,r4
	muls r1,r5,r1
	muls r4,r4,r4
	muls r5,r5,r5
	lsrs r6,r1,#15
	lsls r1,r1,#17
	adds r4,r1
	adcs r5,r6
 // End: sqr 32
 // Result in r4 ,r5
	mov r1,r2
	subs r1,r4
	sbcs r2,r5
	mov r5,r3
	movs r6,#0
	sbcs r3,r6
	adds r1,r0
	adcs r2,r5
	adcs r3,r6
 // END: sqr 64 Refined Karatsuba
 // Result in r0,r1,r2,r3
 // Leaves r6 zero.
	mov r6,r10
	mov r10,r0
	mov r11,r1
	mov r12,r2
	mov r1,r3
 // START: sqr 64 Refined Karatsuba
 // Input operands in r6,r7
 // Result in r2,r3,r4,r5
 // Clobbers: r0,r7,r6
 // START: sqr 32
 // Input operand in r6
 // Result in r2 ,r3
 // Clobbers: r4, r5
	uxth r2,r6
	lsrs r3,r6,#16
	mov r4,r2
	muls r4,r3,r4
	muls r2,r2,r2
	muls r3,r3,r3
	lsrs r5,r4,#15
	lsls r4,r4,#17
	adds r2,r4
	adcs r3,r5
 // End: sqr 32
 // Result in r2 ,r3
	subs r6,r7
	sbcs r4,r4
	eors r6,r4
	subs r6,r4
 // START: sqr 32
 // Input operand in r7
 // Result in r4 ,r5
 // Clobbers: r0, r7
	uxth r4,r7
	lsrs r5,r7,#16
	mov r0,r4
	muls r0,r5,r0
	muls r4,r4,r4
	muls r5,r5,r5
	lsrs r7,r0,#15
	lsls r0,r0,#17
	adds r4,r0
	adcs r5,r7
 // End: sqr 32
 // Result in r4 ,r5
	movs r7,#0
	adds r4,r3
	adcs r5,r7
 // START: sqr 32
 // Input operand in r6
 // Result in r7 ,r0
 // Clobbers: r6, r3
	uxth r7,r6
	lsrs r0,r6,#16
	mov r6,r7
	muls r6,r0,r6
	muls r7,r7,r7
	muls r0,r0,r0
	lsrs r3,r6,#15
	lsls r6,r6,#17
	adds r7,r6
	adcs r0,r3
 // End: sqr 32
 // Result in r7 ,r0
	mov r3,r4
	subs r3,r7
	sbcs r4,r0
	mov r0,r5
	movs r6,#0
	sbcs r5,r6
	adds r3,r2
	adcs r4,r0
	adcs r5,r6
 // END: sqr 64 Refined Karatsuba
 // Result in r2,r3,r4,r5
 // Leaves r6 zero.
	mov r0,r12
	adds r2,r0
	adcs r3,r1
	adcs r4,r6
	adcs r5,r6
	mov r12,r2
	mov r2,r8
	mov r8,r3
	mov r3,r9
	mov r9,r4
 // START: sqr 64 Refined Karatsuba
 // Input operands in r2,r3
 // Result in r6,r7,r0,r1
 // Clobbers: r2,r3,r4
 // START: sqr 32
 // Input operand in r2
 // Result in r6 ,r7
 // Clobbers: r0, r1
	uxth r6,r2
	lsrs r7,r2,#16
	mov r0,r6
	muls r0,r7,r0
	muls r6,r6,r6
	muls r7,r7,r7
	lsrs r1,r0,#15
	lsls r0,r0,#17
	adds r6,r0
	adcs r7,r1
 // End: sqr 32
 // Result in r6 ,r7
	subs r2,r3
	sbcs r4,r4
	eors r2,r4
	subs r2,r4
 // START: sqr 32
 // Input operand in r3
 // Result in r0 ,r1
 // Clobbers: r3, r4
	uxth r0,r3
	lsrs r1,r3,#16
	mov r3,r0
	muls r3,r1,r3
	muls r0,r0,r0
	muls r1,r1,r1
	lsrs r4,r3,#15
	lsls r3,r3,#17
	adds r0,r3
	adcs r1,r4
 // End: sqr 32
 // Result in r0 ,r1
	movs r4,#0
	adds r0,r7
	adcs r1,r4
 // START: sqr 32
 // Input operand in r2
 // Result in r3 ,r4
 // Clobbers: r2, r7
	uxth r3,r2
	lsrs r4,r2,#16
	mov r2,r3
	muls r2,r4,r2
	muls r3,r3,r3
	muls r4,r4,r4
	lsrs r7,r2,#15
	lsls r2,r2,#17
	adds r3,r2
	adcs r4,r7
 // End: sqr 32
 // Result in r3 ,r4
	mov r7,r0
	subs r7,r3
	sbcs r0,r4
	mov r2,r1
	movs r4,#0
	sbcs r1,r4
	adds r7,r6
	adcs r0,r2
	adcs r1,r4
 // END: sqr 64 Refined Karatsuba
 // Result in r6,r7,r0,r1
 // Returns r4 as zero.
	mov r2,r12
	mov r3,r8
	mov r4,r9
	subs r2,r6
	sbcs r3,r7
	mov r6,r4
	mov r7,r5
	sbcs r4,r0
	sbcs r5,r1
	movs r0,#0
	sbcs r6,r0
	sbcs r7,r0
	mov r0,r10
	adds r2,r0
	mov r1,r11
	adcs r3,r1
	mov r0,r12
	adcs r4,r0
	mov r0,r8
	adcs r5,r0
	movs r0,#0
	adcs r6,r0
	adcs r7,r0
	mov r0,r10
 // END: sqr 128 Refined Karatsuba
 // Result in r0 ... r7
	bx lr
	.size __em_p256_m0_sqr128, .-__em_p256_m0_sqr128
	
	.endif

// ######################
// ASM Square 256 refined karatsuba:
// ######################
 // sqr 256 Refined Karatsuba
 // pInput in r1
 // pResult in r0
	.type __em_p256_m0_sqrmod, %function
__em_p256_m0_sqrmod:
	push {r0,lr}
	//frame push {lr}
	//frame address sp,8
	sub sp,#64
	//frame address sp,72
	//mov lr,sp
	push {r1}
	//frame address sp,76
	ldm r1!,{r4,r5,r6,r7}

	bl __em_p256_m0_sqr128

	push {r4,r5,r6,r7}
	//frame address sp,92
	//mov r4,lr
	add r4,sp,#20
	stm r4!,{r0,r1,r2,r3}
	ldr r4,[sp,#16]
	adds r4,#16
	ldm r4,{r4,r5,r6,r7}

	bl __em_p256_m0_sqr128

	mov r8,r4
	mov r9,r5
	mov r10,r6
	mov r11,r7
	pop {r4,r5,r6,r7}
	//frame address sp,76
	adds r0,r4
	adcs r1,r5
	adcs r2,r6
	adcs r3,r7
	mov r4,r8
	mov r5,r9
	mov r6,r10
	mov r7,r11
	mov r8,r0
	movs r0,#0
	adcs r4,r0
	adcs r5,r0
	adcs r6,r0
	adcs r7,r0
	mov r0,r8
	push {r0,r1,r2,r3,r4,r5,r6,r7}
	//frame address sp,108
	ldr r4,[sp,#32]
	ldm r4,{r0,r1,r2,r3,r4,r5,r6,r7}
	subs r4,r0
	sbcs r5,r1
	sbcs r6,r2
	sbcs r7,r3
	sbcs r0,r0
	eors r4,r0
	eors r5,r0
	eors r6,r0
	eors r7,r0
	subs r4,r0
	sbcs r5,r0
	sbcs r6,r0
	sbcs r7,r0

	bl __em_p256_m0_sqr128

	mvns r0,r0
	mvns r1,r1
	mvns r2,r2
	mvns r3,r3
	mvns r4,r4
	mvns r5,r5
	mvns r6,r6
	mvns r7,r7
	mov r8,r4
	mov r9,r5
	mov r10,r6
	mov r11,r7
	subs r4,r4
	pop {r4,r5,r6,r7}
	//frame address sp,92
	adcs r0,r4
	adcs r1,r5
	adcs r2,r6
	adcs r3,r7
	mov r12,r4
	//movs r4,#16
	//add r4,lr
	add r4,sp,#20+16
	stm r4!,{r0,r1,r2,r3}
	mov r4,r12
	mov r0,r8
	adcs r0,r4
	mov r8,r0
	mov r1,r9
	adcs r1,r5
	mov r9,r1
	mov r2,r10
	adcs r2,r6
	mov r10,r2
	mov r3,r11
	adcs r3,r7
	mov r11,r3
	movs r0,#0
	adcs r0,r0
	mov r12,r0
	//mov r0,lr
	add r0,sp,#20
	ldm r0,{r0,r1,r2,r3,r4,r5,r6,r7}
	adds r0,r4
	adcs r1,r5
	adcs r2,r6
	adcs r3,r7
	//movs r4,#16
	//add r4,lr
	add r4,sp,#20+16
	stm r4!,{r0,r1,r2,r3}
	//mov lr,r4
	mov r0,r13
	ldm r0!,{r4,r5,r6,r7}
	mov r1,r8
	adcs r4,r1
	mov r1,r9
	adcs r5,r1
	mov r1,r10
	adcs r6,r1
	mov r1,r11
	adcs r7,r1
	//mov r0,lr
	add r0,sp,#20+32
	stm r0!,{r4,r5,r6,r7}
	pop {r4,r5,r6,r7}
	//frame address sp,76
	mov r1,r12
	movs r2,#0
	mvns r2,r2
	adcs r1,r2
	asrs r2,r1,#4
	adds r4,r1
	adcs r5,r2
	adcs r6,r2
	adcs r7,r2
	stm r0!,{r4,r5,r6,r7}
	add sp,#4
	//frame address sp,72
	b reduce
	.size __em_p256_m0_sqrmod, .-__em_p256_m0_sqrmod
	.endif


// Field add/sub share the multiplication kernel's final reduction.
	.type __em_p256_m0_addmod, %function
__em_p256_m0_addmod:
	push {r0,lr}
	//frame push {lr}
	//frame address sp,8
	ldm r1!,{r0,r3,r4}
	ldm r2!,{r5,r6,r7}
	adds r0,r5
	adcs r3,r6
	adcs r4,r7
	mov r8,r0
	mov r9,r3
	mov r10,r4
	ldm r1!,{r5,r6}
	ldm r2!,{r3,r4}
	adcs r5,r3
	adcs r6,r4
	ldm r1,{r1,r3,r4}
	ldm r2,{r0,r2,r7}
	adcs r1,r0
	adcs r3,r2
	adcs r4,r7
	movs r7,#0
	adcs r7,r7
	
	subs r0,r0 //set r0 to 0 and C to 1
	mov r2,r8
	mov r8,r7
	mov r7,r9
	mov r9,r4
	mov r4,r10
	adcs r2,r0
	mov r10,r2
	adcs r7,r0
	mov r11,r7
	adcs r4,r0
	sbcs r5,r0
	sbcs r6,r0
	sbcs r1,r0
	movs r0,#1
	sbcs r3,r0
	movs r0,#0
	mov r2,r9
	adcs r2,r0
	mov r7,r8
	sbcs r7,r0
	
	// r10 r11 r4 r5 | r6 r1 r3 r2 | r7
	
	mov r8,r3
	mov r3,r11
	mov r11,r2
	mov r2,r10
	
	// r2 r3 r4 r5 | r6 r1 r8 r11 | r7
	
	b reduce2
	
	.size __em_p256_m0_addmod, .-__em_p256_m0_addmod
	
// *r0 = output, *r1 = a, *r2 = b
	.type __em_p256_m0_submod, %function
__em_p256_m0_submod:
	push {r0,lr}
	//frame push {lr}
	//frame address sp,8
	ldm r1!,{r0,r3,r4}
	ldm r2!,{r5,r6,r7}
	subs r0,r5
	sbcs r3,r6
	sbcs r4,r7
	mov r8,r0
	mov r9,r3
	mov r10,r4
	ldm r1!,{r5,r6}
	ldm r2!,{r3,r4}
	sbcs r5,r3
	sbcs r6,r4
	ldm r1,{r1,r3,r4}
	ldm r2,{r0,r2,r7}
	sbcs r1,r0
	sbcs r3,r2
	sbcs r4,r7
	
	sbcs r7,r7
	
	mov r2,r8
	mov r8,r3
	mov r11,r4
	mov r3,r9
	mov r4,r10
	b reduce2
	
	.size __em_p256_m0_submod, .-__em_p256_m0_submod


// Unrolled M0 Jacobian doubling; same eight-word Montgomery coordinates.
	.type __em_p256_m0_double_j, %function
__em_p256_m0_double_j:
	push {r0,r1,r4-r7,lr}
	//frame push {r4-r7,lr}
	//frame address sp,28
	
	// https://eprint.iacr.org/2014/130.pdf, algorithm 10
	
	// t1 = Z1^2
	sub sp,#32
	//frame address sp,60
	mov r0,sp
	adds r1,#64
	bl __em_p256_m0_sqrmod
	
	// Z2 = Y1 * Z1
	ldr r0,[sp,#32]
	ldr r1,[sp,#36]
	adds r0,#64
	adds r1,#32
	movs r2,#32
	adds r2,r1
	bl __em_p256_m0_mulmod
	
	// t2 = X1 + t1
	ldr r1,[sp,#36]
	mov r2,sp
	sub sp,#32
	//frame address sp,92
	mov r0,sp
	bl __em_p256_m0_addmod
	
	// t1 = X1 - t1
	ldr r1,[sp,#68]
	add r2,sp,#32
	mov r0,r2
	bl __em_p256_m0_submod
	
	// t1 = t1 * t2
	add r1,sp,#32
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// t2 = t1 / 2
	add sp,#32
	//frame address sp,60
	mov r7,sp
	ldm r7!,{r0-r3}
	lsls r6,r0,#31
	asrs r5,r6,#31
	lsrs r6,#31
	movs r4,#0
	adds r0,r5
	adcs r1,r5
	adcs r2,r5
	adcs r3,r4
	push {r0-r3}
	//frame address sp,76
	ldm r7!,{r0-r3}
	adcs r0,r4
	adcs r1,r4
	adcs r2,r6
	adcs r3,r5
	movs r4,#0
	adcs r4,r4
	lsls r7,r4,#31
	lsrs r6,r3,#1
	orrs r7,r6
	lsls r6,r3,#31
	lsrs r5,r2,#1
	orrs r6,r5
	lsls r5,r2,#31
	lsrs r4,r1,#1
	orrs r5,r4
	lsls r4,r1,#31
	lsrs r3,r0,#1
	orrs r4,r3
	lsls r3,r0,#31
	mov r8,r3
	pop {r0-r3}
	//frame address sp,60
	push {r4-r7}
	//frame address sp,76
	mov r7,r8
	lsrs r6,r3,#1
	orrs r7,r6
	lsls r6,r3,#31
	lsrs r5,r2,#1
	orrs r6,r5
	lsls r5,r2,#31
	lsrs r4,r1,#1
	orrs r5,r4
	lsls r4,r1,#31
	lsrs r3,r0,#1
	orrs r4,r3
	push {r4-r7}
	//frame address sp,92
	
	// t1 = t1 + t2
	add r1,sp,#32
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_addmod
	
	// t2 = t1^2
	mov r0,sp
	add r1,sp,#32
	bl __em_p256_m0_sqrmod
	
	// Y2 = Y1^2
	ldr r0,[sp,#64]
	ldr r1,[sp,#68]
	adds r0,#32
	adds r1,#32
	bl __em_p256_m0_sqrmod
	
	// t3 = Y2^2
	ldr r1,[sp,#64]
	adds r1,#32
	sub sp,#32
	//frame address sp,124
	mov r0,sp
	bl __em_p256_m0_sqrmod
	
	// Y2 = X1 * Y2
	ldr r0,[sp,#96]
	ldr r1,[sp,#100]
	adds r0,#32
	mov r2,r0
	bl __em_p256_m0_mulmod
	
	// X2 = 2 * Y2
	ldr r0,[sp,#96]
	mov r1,r0
	adds r1,#32
	mov r2,r1
	bl __em_p256_m0_addmod
	
	// X2 = t2 - X2
	ldr r0,[sp,#96]
	add r1,sp,#32
	mov r2,r0
	bl __em_p256_m0_submod
	
	// t2 = Y2 - X2
	ldr r2,[sp,#96]
	mov r1,r2
	adds r1,#32
	add r0,sp,#32
	bl __em_p256_m0_submod
	
	// t1 = t1 * t2
	add r0,sp,#64
	add r1,sp,#64
	add r2,sp,#32
	bl __em_p256_m0_mulmod
	
	// Y2 = t1 - t3
	ldr r0,[sp,#96]
	adds r0,#32
	add r1,sp,#64
	mov r2,sp
	bl __em_p256_m0_submod
	
	add sp,#104
	//frame address sp,20
	
	pop {r4-r7,pc}
	.size __em_p256_m0_double_j, .-__em_p256_m0_double_j

// Unrolled M0 Jacobian addition.
	.type __em_p256_m0_add_j, %function
__em_p256_m0_add_j:
	push {r0,r1,r4-r7,lr}
	//frame push {r4-r7,lr}
	//frame address sp,28
	
	// Here a variant of
	// https://www.hyperelliptic.org/EFD/g1p/auto-code/shortw/jacobian-3/addition/add-1998-cmo-2.op3
	// is used, but rearranged and uses less temporaries.
	// The first operand to the function is both (X3,Y3,Z3) and (X2,Y2,Z2).
	// The second operand to the function is (X1,Y1,Z1)
	
	// Z1Z1 = Z1^2
	sub sp,#32
	//frame address sp,60
	mov r0,sp
	adds r1,#64
	bl __em_p256_m0_sqrmod
	
	// U2 = X2*Z1Z1
	ldr r1,[sp,#32]
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// t1 = Z1*Z1Z1
	ldr r1,[sp,#36]
	adds r1,#64
	mov r2,sp
	mov r0,sp
	bl __em_p256_m0_mulmod
	
	// S2 = Y2*t1
	ldr r1,[sp,#32]
	adds r1,#32
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// Z2Z2 = Z2^2
	sub sp,#32
	//frame address sp,92
	mov r0,sp
	ldr r1,[sp,#64]
	adds r1,#64
	bl __em_p256_m0_sqrmod
	
	// U1 = X1*Z2Z2
	ldr r1,[sp,#68]
	mov r2,sp
	add r0,sp,#32
	bl __em_p256_m0_mulmod
	
	// t2 = Z2*Z2Z2
	ldr r1,[sp,#64]
	adds r1,#64
	mov r2,sp
	mov r0,sp
	bl __em_p256_m0_mulmod
	
	// S1 = Y1*t2
	ldr r1,[sp,#68]
	adds r1,#32
	mov r2,sp
	mov r0,sp
	bl __em_p256_m0_mulmod
	
	// H = U2-U1
	ldr r1,[sp,#64]
	add r2,sp,#32
	mov r0,r1
	bl __em_p256_m0_submod
	
	// HH = H^2
	ldr r1,[sp,#64]
	sub sp,#32
	//frame address sp,124
	mov r0,sp
	bl __em_p256_m0_sqrmod
	
	// Z3 = Z2*H
	ldr r2,[sp,#96]
	mov r1,r2
	adds r1,#64
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// Z3 = Z1*Z3
	ldr r1,[sp,#100]
	adds r1,#64
	ldr r2,[sp,#96]
	adds r2,#64
	mov r0,r2
	bl __em_p256_m0_mulmod
	
	// HHH = H*HH
	ldr r1,[sp,#96]
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// r = S2-S1
	ldr r1,[sp,#96]
	adds r1,#32
	add r2,sp,#32
	mov r0,r1
	bl __em_p256_m0_submod
	
	// V = U1*HH
	add r1,sp,#64
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_mulmod
	
	// t3 = r^2
	ldr r1,[sp,#96]
	adds r1,#32
	mov r0,sp
	bl __em_p256_m0_sqrmod
	
	// t2 = S1*HHH
	add r1,sp,#32
	ldr r2,[sp,#96]
	add r0,sp,#32
	bl __em_p256_m0_mulmod
	
	// X3 = t3-HHH
	mov r1,sp
	ldr r2,[sp,#96]
	mov r0,r2
	bl __em_p256_m0_submod
	
	// t3 = 2*V
	add r1,sp,#64
	add r2,sp,#64
	mov r0,sp
	bl __em_p256_m0_addmod
	
	// X3 = X3-t3
	ldr r1,[sp,#96]
	mov r2,sp
	mov r0,r1
	bl __em_p256_m0_submod
	
	// t3 = V-X3
	add r1,sp,#64
	ldr r2,[sp,#96]
	mov r0,sp
	bl __em_p256_m0_submod
	
	// t3 = r*t3
	ldr r1,[sp,#96]
	adds r1,#32
	mov r2,sp
	mov r0,sp
	bl __em_p256_m0_mulmod
	
	// Y3 = t3-t2
	mov r1,sp
	add r2,sp,#32
	ldr r0,[sp,#96]
	adds r0,#32
	bl __em_p256_m0_submod
	
	add sp,#104
	//frame address sp,20
	
	pop {r4-r7,pc}
	.size __em_p256_m0_add_j, .-__em_p256_m0_add_j

// M0 inversion helpers and exponent schedule (Montgomery in/out).
	.type __em_p256_m0_copy32, %function
__em_p256_m0_copy32:
	push {r4-r5,lr}
	//frame push {r4-r5,lr}
	ldm r1!,{r2-r5}
	stm r0!,{r2-r5}
	ldm r1!,{r2-r5}
	stm r0!,{r2-r5}
	pop {r4-r5,pc}
	.size __em_p256_m0_copy32, .-__em_p256_m0_copy32

	.type __em_p256_m0_sqrmod_many_and_mulmod, %function
__em_p256_m0_sqrmod_many_and_mulmod:
	push {r0,r2,lr}
	//frame push {lr}
	//frame address sp,12
	cmp r1,#0
	beq 1f
0:
	push {r1}
	//frame address sp,16
	ldr r0,[sp,#4]
	mov r1,r0
	bl __em_p256_m0_sqrmod
	pop {r1}
	//frame address sp,12
	subs r1,#1
	bne 0b
1:
	pop {r0,r1}
	//frame address sp,4
	mov r2,r0
	bl __em_p256_m0_mulmod
	pop {pc}
	.size __em_p256_m0_sqrmod_many_and_mulmod, .-__em_p256_m0_sqrmod_many_and_mulmod


// in: *r0 = value in/out
// for modinv, call input a, then if a = A * R % p, then it calculates A^-1 * R % p = (a/R)^-1 * R % p = R^2 / a % p
	.type __em_p256_m0_modinv, %function
__em_p256_m0_modinv:
	push {r0,lr}
	//frame push {lr}
	//frame address sp,8
	
	ldm r0,{r0-r7}
	push {r0-r7}
	//frame address sp,40
	
	// t = a^2*a
	ldr r0,[sp,#32]
	movs r1,#1
	mov r2,sp
	bl __em_p256_m0_sqrmod_many_and_mulmod
	ldr r0,[sp,#32]
	ldm r0,{r0-r7}
	push {r0-r7}
	//frame address sp,72
	
	// a4_2 = a2_0^(2^2)
	
	ldr r0,[sp,#64]
	mov r1,r0
	bl __em_p256_m0_sqrmod
	ldr r0,[sp,#64]
	mov r1,r0
	bl __em_p256_m0_sqrmod
	ldr r0,[sp,#64]
	ldm r0,{r0-r7}
	push {r0-r7}
	//frame address sp,104
	
	// a4_0 = a4_2*a2_0
	ldr r0,[sp,#96]
	mov r1,sp
	add r2,sp,#32
	bl __em_p256_m0_mulmod
	add r0,sp,#32
	ldr r1,[sp,#96]
	bl __em_p256_m0_copy32
	
	ldr r7,[sp,#96]
	movs r4,#0
0:
	adr r2,__em_p256_m0_invtbl
	ldrsb r0,[r2,r4]
	adds r2,#1
	ldrb r5,[r2,r4]
	lsls r6,r0,#2
	bpl 1f
	sub sp,#32
	//frame address sp,200 // not always correct
	mov r0,sp
	mov r1,r7
	bl __em_p256_m0_copy32
1:
	mov r0,r7
	uxtb r1,r6
	mov r2,r5
	add r2,sp
	push {r4,r7}
	//frame address sp,208 // not always correct
	bl __em_p256_m0_sqrmod_many_and_mulmod
	pop {r4,r7}
	//frame address sp,200 // not always correct
	adds r4,#2
	cmp r4,#22
	bne 0b

	add sp,#6*32+4
	//frame address sp,4
	
	pop {pc}
	
	.size __em_p256_m0_modinv, .-__em_p256_m0_modinv

	.align 2
__em_p256_m0_invtbl:
	.byte ((8-4)>>2)
	.byte 32
	
	.byte ((16-8)>>2)+128
	.byte 0
	
	.byte (16>>2)+128
	.byte 0
	
	.byte (32>>2)+128
	.byte 5*32
	
	.byte (192-64)>>2
	.byte 0
	
	.byte (224-192)>>2
	.byte 0
	
	.byte (240-224)>>2
	.byte 32
	
	.byte (248-240)>>2
	.byte 64
	
	.byte (252-248)>>2
	.byte 128
	
	.byte (256-252)>>2
	.byte 96
	
	.byte 0
	.byte 5*32
	

            )"
        );
    `
}

a$`naked,noinline`
export function square(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                mov r1,r0
                bl __em_p256_m0_sqrmod
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}

            )"
        );
    `
}

a$`naked,noinline`
export function sub(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r8
                mov r5,r9
                mov r6,r10
                mov r7,r11
                push {r4-r7}
                sub sp,#4
                mov r2,r1
                mov r1,r0
                bl __em_p256_m0_submod
                add sp,#4
                pop {r4-r7}
                mov r8,r4
                mov r9,r5
                mov r10,r6
                mov r11,r7
                pop {r4-r7,pc}
            )"
        );
    `
}

export function times2(a: T.U256_Ref) {
    add(a, a)
}


// Adapted in place: the raw routine reads both halves before storing.
// Only r9 is used among the high callee-saved registers; preserve it explicitly.
a$`naked,noinline`
export function half(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push {r4-r7,lr}
                mov r4,r9
                push {r4}
                mov r1,r0
	mov r9,r0
	mov r7,r1
	ldm r7!,{r0-r3}
	lsls r6,r0,#31
	asrs r5,r6,#31
	lsrs r6,#31
	movs r4,#0
	adds r0,r5
	adcs r1,r5
	adcs r2,r5
	adcs r3,r4
	push {r0-r3}
	//frame address sp,76
	ldm r7!,{r0-r3}
	adcs r0,r4
	adcs r1,r4
	adcs r2,r6
	adcs r3,r5
	movs r4,#0
	adcs r4,r4
	lsls r7,r4,#31
	lsrs r6,r3,#1
	orrs r7,r6
	lsls r6,r3,#31
	lsrs r5,r2,#1
	orrs r6,r5
	lsls r5,r2,#31
	lsrs r4,r1,#1
	orrs r5,r4
	lsls r4,r1,#31
	lsrs r3,r0,#1
	orrs r4,r3
	lsls r3,r0,#31
	mov r0,r9
	adds r0,#16
	stm r0!,{r4-r7}
	mov r7,r3
	pop {r0-r3}
	lsrs r6,r3,#1
	orrs r7,r6
	lsls r6,r3,#31
	lsrs r5,r2,#1
	orrs r6,r5
	lsls r5,r2,#31
	lsrs r4,r1,#1
	orrs r5,r4
	lsls r4,r1,#31
	lsrs r3,r0,#1
	orrs r4,r3
	mov r0,r9
	stm r0!,{r4-r7}
                pop {r4}
                mov r9,r4
                pop {r4-r7,pc}
            )"
        );
    `
}
