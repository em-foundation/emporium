import '@$$emscript'
export const $U = $declare('MODULE', MathOpsI)

import * as MathOpsI from '@em.crypto.p256/MathOpsI.em'
import * as T from '@em.crypto.p256/Types.em'

export namespace em$meta { }

//>> ---- em$targ ---- <<//

a$`naked,noinline`
export function add(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11}
                /* Adapt the reference custom ABI to a := a + b mod p. */
                push    {r0}
                mov     r2,r1
                mov     r1,r0
    
                ldm     r2,{r2-r9}
                ldm     r1!,{r0,r10,r11,r12}
                adds    r2,r0
                adcs    r3,r10
                adcs    r4,r11
                adcs    r5,r12
                ldm     r1,{r0,r1,r11,r12}
                adcs    r6,r0
                adcs    r7,r1
                adcs    r8,r11
                adcs    r9,r12
                movs    r10,#0
                adcs    r10,r10
    
                /* Conditional subtraction of p. */
                subs    r2,#0xffffffff
                sbcs    r3,#0xffffffff
                sbcs    r4,#0xffffffff
                sbcs    r5,#0
                sbcs    r6,#0
                sbcs    r7,#0
                sbcs    r8,#1
                sbcs    r9,#0xffffffff
                sbcs    r10,#0
    
                adds    r0,r2,r10
                adcs    r1,r3,r10
                adcs    r2,r4,r10
                adcs    r3,r5,#0
                adcs    r4,r6,#0
                adcs    r5,r7,#0
                adcs    r6,r8,r10,lsr #31
                adcs    r7,r9,r10
    
                pop     {r8}
                stm     r8,{r0-r7}
                pop     {r4-r11}
                bx      lr
            )"
        );
    `
}

export function copy(a: T.U256_Ref, b: T.U256_Ref) {
    T.copyU256(a, b)
}


a$`naked,noinline`
export function doublePoint(p: $$<T.PointJ>) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11,lr}
                sub     sp,#96
                mov     r4,r0

                /* t1 = Z1^2 */
                mov     r0,sp
                add     r1,r4,#64
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                mov     r0,sp
                bl      _ZN27em_crypto_p256_MathOpsArmM4L6squareEN2em5ptr_tIjEE

                /* Z2 = Y1 * Z1 */
                add     r0,r4,#64
                add     r1,r4,#32
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3mulEN2em5ptr_tIjEES2_

                /* t2 = X1 + t1 */
                add     r0,sp,#32
                mov     r1,r4
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                add     r0,sp,#32
                mov     r1,sp
                bl      92f

                /* t3 = (X1 - t1) * t2 */
                add     r0,sp,#64
                mov     r1,r4
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                add     r0,sp,#64
                mov     r1,sp
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3subEN2em5ptr_tIjEES2_
                add     r0,sp,#64
                add     r1,sp,#32
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3mulEN2em5ptr_tIjEES2_

                /* t3 = 3/2 * t3 */
                mov     r0,sp
                add     r1,sp,#64
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                mov     r0,sp
                bl      93f
                add     r0,sp,#64
                mov     r1,sp
                bl      92f

                /* t2 = t3^2 */
                add     r0,sp,#32
                add     r1,sp,#64
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                add     r0,sp,#32
                bl      _ZN27em_crypto_p256_MathOpsArmM4L6squareEN2em5ptr_tIjEE

                /* Y2 = Y1^2; t1 = Y2^2 */
                add     r0,r4,#32
                bl      _ZN27em_crypto_p256_MathOpsArmM4L6squareEN2em5ptr_tIjEE
                mov     r0,sp
                add     r1,r4,#32
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                mov     r0,sp
                bl      _ZN27em_crypto_p256_MathOpsArmM4L6squareEN2em5ptr_tIjEE

                /* Y2 = X1 * Y2 */
                add     r0,r4,#32
                mov     r1,r4
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3mulEN2em5ptr_tIjEES2_

                /* X2 = 2 * Y2 */
                mov     r0,r4
                add     r1,r4,#32
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}
                mov     r0,r4
                bl      _ZN27em_crypto_p256_MathOpsArmM4L6times2EN2em5ptr_tIjEE

                /* X2 = t2 - X2 */
                add     r0,sp,#32
                mov     r1,r4
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3subEN2em5ptr_tIjEES2_
                mov     r0,r4
                add     r1,sp,#32
                ldm     r1!,{r5-r12}
                stm     r0!,{r5-r12}

                /* Y2 = t3 * (Y2 - X2) - t1 */
                add     r0,r4,#32
                mov     r1,r4
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3subEN2em5ptr_tIjEES2_
                add     r0,r4,#32
                add     r1,sp,#64
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3mulEN2em5ptr_tIjEES2_
                add     r0,r4,#32
                mov     r1,sp
                bl      _ZN27em_crypto_p256_MathOpsArmM4L3subEN2em5ptr_tIjEES2_

                add     sp,#96
                pop     {r4-r11,pc}

                b       99f

                /* add helper: r0=dst, r1=src */
92:
                push    {r4-r11}
                push    {r0}
                mov     r2,r1
                mov     r1,r0
                ldm     r2,{r2-r9}
                ldm     r1!,{r0,r10,r11,r12}
                adds    r2,r0
                adcs    r3,r10
                adcs    r4,r11
                adcs    r5,r12
                ldm     r1,{r0,r1,r11,r12}
                adcs    r6,r0
                adcs    r7,r1
                adcs    r8,r11
                adcs    r9,r12
                movs    r10,#0
                adcs    r10,r10
                subs    r2,#0xffffffff
                sbcs    r3,#0xffffffff
                sbcs    r4,#0xffffffff
                sbcs    r5,#0
                sbcs    r6,#0
                sbcs    r7,#0
                sbcs    r8,#1
                sbcs    r9,#0xffffffff
                sbcs    r10,#0
                adds    r0,r2,r10
                adcs    r1,r3,r10
                adcs    r2,r4,r10
                adcs    r3,r5,#0
                adcs    r4,r6,#0
                adcs    r5,r7,#0
                adcs    r6,r8,r10,lsr #31
                adcs    r7,r9,r10
                pop     {r8}
                stm     r8,{r0-r7}
                pop     {r4-r11}
                bx      lr

                /* half helper: r0=dst */
93:
                push    {r4-r11}
                push    {r0}
                ldm     r0,{r0-r7}
                lsl     r8,r0,#31
                adds    r0,r0,r8,asr #31
                adcs    r1,r1,r8,asr #31
                adcs    r2,r2,r8,asr #31
                adcs    r3,#0
                adcs    r4,#0
                adcs    r5,#0
                adcs    r6,r6,r8,lsr #31
                adcs    r7,r7,r8,asr #31
                rrxs    r7,r7
                rrxs    r6,r6
                rrxs    r5,r5
                rrxs    r4,r4
                rrxs    r3,r3
                rrxs    r2,r2
                rrxs    r1,r1
                rrx     r0,r0
                pop     {r8}
                stm     r8,{r0-r7}
                pop     {r4-r11}
                bx      lr

99:
            )"
        );
    `
}


export function addPointJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    // Rearranged like Emil Lenngren's P256_add_j.
    // Composite backend operation keeps the hot Jacobian-add sequence local
    // to the selected field backend, matching doublePoint() structurally.

    let t1 = T.U256.$make()
    copy(t1.$ptr(), q.$$.z.$ptr())
    square(t1.$ptr())

    mul(p.$$.x.$ptr(), t1.$ptr())

    mul(t1.$ptr(), q.$$.z.$ptr())
    mul(p.$$.y.$ptr(), t1.$ptr())

    copy(t1.$ptr(), p.$$.z.$ptr())
    square(t1.$ptr())

    let t2 = T.U256.$make()
    copy(t2.$ptr(), q.$$.x.$ptr())
    mul(t2.$ptr(), t1.$ptr())

    mul(t1.$ptr(), p.$$.z.$ptr())
    mul(t1.$ptr(), q.$$.y.$ptr())

    sub(p.$$.x.$ptr(), t2.$ptr())

    let t3 = T.U256.$make()
    copy(t3.$ptr(), p.$$.x.$ptr())
    square(t3.$ptr())

    mul(p.$$.z.$ptr(), p.$$.x.$ptr())
    mul(p.$$.z.$ptr(), q.$$.z.$ptr())

    mul(p.$$.x.$ptr(), t3.$ptr())

    sub(p.$$.y.$ptr(), t1.$ptr())

    mul(t2.$ptr(), t3.$ptr())

    copy(t3.$ptr(), p.$$.y.$ptr())
    square(t3.$ptr())

    mul(t1.$ptr(), p.$$.x.$ptr())

    sub(t3.$ptr(), p.$$.x.$ptr())
    copy(p.$$.x.$ptr(), t2.$ptr())
    times2(p.$$.x.$ptr())
    sub(t3.$ptr(), p.$$.x.$ptr())
    copy(p.$$.x.$ptr(), t3.$ptr())

    copy(t3.$ptr(), t2.$ptr())
    sub(t3.$ptr(), p.$$.x.$ptr())
    mul(t3.$ptr(), p.$$.y.$ptr())
    sub(t3.$ptr(), t1.$ptr())
    copy(p.$$.y.$ptr(), t3.$ptr())
}







a$`naked,noinline`
export function quadDoubleAddPointJacobian(p: $$<T.PointJ>, q: $$<T.PointJ>) {
    e$`
        asm volatile (
            R"(
                /* Hot fixed-window step: 4 Jacobian doubles + 1 Jacobian add.
                 * Exact Emil register-ABI point kernels and one shared copy of
                 * their raw field kernels.  This is a speed-architecture probe.
                 */
                push    {r4-r6,lr}
                mov     r4,r0
                mov     r5,r1

                mov     r0,r4
                mov     r1,r4
                bl      90f
                mov     r0,r4
                mov     r1,r4
                bl      90f
                mov     r0,r4
                mov     r1,r4
                bl      90f
                mov     r0,r4
                mov     r1,r4
                bl      90f

                mov     r0,r4
                mov     r1,r5
                bl      91f

                pop     {r4-r6,pc}

90:
	push {r0,r1,r4-r11,lr}
	//frame push {r4-r11,lr}
	//frame address sp,44
	
	// https://eprint.iacr.org/2014/130.pdf, algorithm 10
	
	// t1 = Z1^2
	adds r1,#64
	ldm r1,{r0-r7}
	bl __em_p256_raw_sqr
	push {r0-r7}
	//frame address sp,76
	
	// Z2 = Y1 * Z1
	ldr r1,[sp,#36]
	adds r1,#32
	add r2,r1,#32
	bl __em_p256_raw_mul
	ldr r8,[sp,#32]
	add r8,#64
	stm r8,{r0-r7}
	
	// t2 = X1 + t1
	ldr r1,[sp,#36]
	mov r2,sp
	bl __em_p256_raw_add
	push {r0-r7}
	//frame address sp,108
	
	// t1 = X1 - t1
	ldr r1,[sp,#68]
	add r2,sp,#32
	bl __em_p256_raw_sub
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// t1 = t1 * t2
	add r1,sp,#32
	mov r2,sp
	bl __em_p256_raw_mul
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// t2 = t1 / 2
	lsl r8,r0,#31
	adds r0,r0,r8, asr #31
	adcs r1,r1,r8, asr #31
	adcs r2,r2,r8, asr #31
	adcs r3,#0
	adcs r4,#0
	adcs r5,#0
	adcs r6,r6,r8, lsr #31
	adcs r7,r7,r8, asr #31
	rrxs r7,r7
	rrxs r6,r6
	rrxs r5,r5
	rrxs r4,r4
	rrxs r3,r3
	rrxs r2,r2
	rrxs r1,r1
	rrx r0,r0
	stm sp,{r0-r7}
	
	// t1 = t1 + t2
	add r1,sp,#32
	mov r2,sp
	bl __em_p256_raw_add
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// t2 = t1^2
	bl __em_p256_raw_sqr
	stm sp,{r0-r7}
	
	// Y2 = Y1^2
	ldr r0,[sp,#68]
	adds r0,#32
	ldm r0,{r0-r7}
	bl __em_p256_raw_sqr
	ldr r8,[sp,#64]
	add r8,#32
	stm r8,{r0-r7}
	
	// t3 = Y2^2
	bl __em_p256_raw_sqr
	push {r0-r7}
	//frame address sp,140
	
	// Y2 = X1 * Y2
	ldrd r0,r1,[sp,#96]
	add r2,r0,#32
	bl __em_p256_raw_mul
	ldr r8,[sp,#96]
	add r8,#32
	stm r8,{r0-r7}
	
	// X2 = 2 * Y2
	bl __em_p256_raw_times2
	ldr r8,[sp,#96]
	stm r8,{r0-r7}
	
	// X2 = t2 - X2
	add r1,sp,#32
	mov r2,r8
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	stm r8,{r0-r7}
	
	// t2 = Y2 - X2
	mov r2,r8
	add r1,r2,#32
	bl __em_p256_raw_sub
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// t1 = t1 * t2
	add r1,sp,#64
	add r2,sp,#32
	bl __em_p256_raw_mul
	add r8,sp,#64
	stm r8,{r0-r7}
	
	// Y2 = t1 - t3
	add r1,sp,#64
	mov r2,sp
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	add r8,#32
	stm r8,{r0-r7}
	
	add sp,#104
	//frame address sp,36
	
	pop {r4-r11,pc}
	

91:
	push {r0,r1,r4-r11,lr}
	//frame push {r4-r11,lr}
	//frame address sp,44
	
	// Here a variant of
	// https://www.hyperelliptic.org/EFD/g1p/auto-code/shortw/jacobian-3/addition/add-1998-cmo-2.op3
	// is used, but rearranged and uses less temporaries.
	// The first operand to the function is both (X3,Y3,Z3) and (X2,Y2,Z2).
	// The second operand to the function is (X1,Y1,Z1)
	
	// Z1Z1 = Z1^2
	adds r1,#64
	ldm r1,{r0-r7}
	bl __em_p256_raw_sqr
	push {r0-r7}
	//frame address sp,76
	
	// U2 = X2*Z1Z1
	ldr r1,[sp,#32]
	mov r2,sp
	bl __em_p256_raw_mul
	ldr r8,[sp,#32]
	stm r8,{r0-r7}
	
	// t1 = Z1*Z1Z1
	ldr r1,[sp,#36]
	adds r1,#64
	mov r2,sp
	bl __em_p256_raw_mul
	stm sp,{r0-r7}
	
	// S2 = Y2*t1
	ldr r1,[sp,#32]
	adds r1,#32
	mov r2,sp
	bl __em_p256_raw_mul
	ldr r8,[sp,#32]
	add r8,#32
	stm r8,{r0-r7}
	
	// Z2Z2 = Z2^2
	ldr r1,[sp,#32]
	adds r1,#64
	ldm r1,{r0-r7}
	bl __em_p256_raw_sqr
	push {r0-r7}
	//frame address sp,108
	
	// U1 = X1*Z2Z2
	ldr r1,[sp,#68]
	mov r2,sp
	bl __em_p256_raw_mul
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// t2 = Z2*Z2Z2
	ldr r1,[sp,#64]
	adds r1,#64
	mov r2,sp
	bl __em_p256_raw_mul
	stm sp,{r0-r7}
	
	// S1 = Y1*t2
	ldr r1,[sp,#68]
	adds r1,#32
	mov r2,sp
	bl __em_p256_raw_mul
	stm sp,{r0-r7}
	
	
	// H = U2-U1
	ldr r1,[sp,#64]
	add r2,sp,#32
	bl __em_p256_raw_sub
	ldr r8,[sp,#64]
	stm r8,{r0-r7}
	
	// HH = H^2
	bl __em_p256_raw_sqr
	push {r0-r7}
	//frame address sp,140
	
	// Z3 = Z2*H
	ldr r2,[sp,#96]
	add r1,r2,#64
	bl __em_p256_raw_mul
	ldr r8,[sp,#96]
	add r8,#64
	stm r8,{r0-r7}
	
	// Z3 = Z1*Z3
	ldr r1,[sp,#100]
	adds r1,#64
	mov r2,r8
	bl __em_p256_raw_mul
	ldr r8,[sp,#96]
	add r8,#64
	stm r8,{r0-r7}
	
	// HHH = H*HH
	ldr r1,[sp,#96]
	mov r2,sp
	bl __em_p256_raw_mul
	ldr r8,[sp,#96]
	stm r8!,{r0-r7}
	
	// r = S2-S1
	mov r1,r8
	add r2,sp,#32
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	add r8,#32
	stm r8,{r0-r7}
	
	// V = U1*HH
	add r1,sp,#64
	mov r2,sp
	bl __em_p256_raw_mul
	add r8,sp,#64
	stm r8,{r0-r7}
	
	// t3 = r^2
	ldr r0,[sp,#96]
	adds r0,#32
	ldm r0,{r0-r7}
	bl __em_p256_raw_sqr
	stm sp,{r0-r7}
	
	// t2 = S1*HHH
	add r1,sp,#32
	ldr r2,[sp,#96]
	bl __em_p256_raw_mul
	add r8,sp,#32
	stm r8,{r0-r7}
	
	// X3 = t3-HHH
	mov r1,sp
	ldr r2,[sp,#96]
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	stm r8,{r0-r7}
	
	// t3 = 2*V
	add r0,sp,#64
	ldm r0,{r0-r7}
	bl __em_p256_raw_times2
	stm sp,{r0-r7}
	
	// X3 = X3-t3
	ldr r1,[sp,#96]
	mov r2,sp
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	stm r8,{r0-r7}
	
	// t3 = V-X3
	add r1,sp,#64
	ldr r2,[sp,#96]
	bl __em_p256_raw_sub
	stm sp,{r0-r7}
	
	// t3 = r*t3
	ldr r1,[sp,#96]
	adds r1,#32
	mov r2,sp
	bl __em_p256_raw_mul
	stm sp,{r0-r7}
	
	// Y3 = t3-t2
	mov r1,sp
	add r2,sp,#32
	bl __em_p256_raw_sub
	ldr r8,[sp,#96]
	add r8,#32
	stm r8,{r0-r7}
	
	add sp,#104
	//frame address sp,36
	
	pop {r4-r11,pc}
	

.global __em_p256_raw_sqr
__em_p256_raw_sqr:
	push {lr}
	//frame push {lr}
	
	//mul 01, 00
	umull r10,r9,r0,r0
	umull r11,r12,r0,r1
	adds r11,r11,r11
	mov lr,#0
	umaal r9,r11,lr,lr
	
	//r9 r10 done
	//r12 carry for 3rd before col
	//r11+C carry for 3rd final col
	
	push {r9,r10}
	//frame address sp,12
	
	//mul 02, 11
	mov r9,#0
	umaal r9,r12,r0,r2
	adcs r9,r9,r9
	umaal r9,r11,r1,r1
	
	//r9 done (3rd col)
	//r12 carry for 4th before col
	//r11+C carry for 4th final col
	
	//mul 03, 12
	umull r8,r10,r0,r3
	umaal r8,r12,r1,r2
	adcs r8,r8,r8
	umaal r8,r11,lr,lr
	
	//r8 done (4th col)
	//r10+r12 carry for 5th before col
	//r11+C carry for 5th final col
	
	push {r8,r9}
	//frame address sp,20
	
	//mul 04, 13, 22
	mov r9,#0
	umaal r9,r10,r0,r4
	umaal r9,r12,r1,r3
	adcs r9,r9,r9
	umaal r9,r11,r2,r2
	
	//r9 done (5th col)
	//r10+r12 carry for 6th before col
	//r11+C carry for 6th final col
	
	push {r9}
	//frame address sp,24
	
	//mul 05, 14, 23
	umull r9,r8,r0,r5
	umaal r9,r10,r1,r4
	umaal r9,r12,r2,r3
	adcs r9,r9,r9
	umaal r9,r11,lr,lr
	
	//r9 done (6th col)
	//r10+r12+r8 carry for 7th before col
	//r11+C carry for 7th final col
	
	push {r9}
	//frame address sp,28
	
	//mul 06, 15, 24, 33
	mov r9,#0
	umaal r9,r8,r1,r5
	umaal r9,r12,r2,r4
	umaal r9,r10,r0,r6
	adcs r9,r9,r9
	umaal r9,r11,r3,r3
	
	//r9 done (7th col)
	//r8+r10+r12 carry for 8th before col
	//r11+C carry for 8th final col
	
	push {r9}
	//frame address sp,32
	
	//mul 07, 16, 25, 34
	umull r9,r0,r0,r7
	umaal r9,r10,r1,r6
	umaal r9,r12,r2,r5
	umaal r9,r8,r3,r4
	adcs r9,r9,r9
	umaal r9,r11,lr,lr
	
	//r9 done (8th col)
	//r0+r8+r10+r12 carry for 9th before col
	//r11+C carry for 9th final col
	
	//mul 17, 26, 35, 44
	umaal r0,r8,r1,r7 //r1 is now dead
	umaal r0,r10,r2,r6
	umaal r0,r12,r3,r5
	adcs r0,r0,r0
	umaal r11,r0,r4,r4
	
	//r11 done (9th col)
	//r8+r10+r12 carry for 10th before col
	//r0+C carry for 10th final col
	
	//mul 27, 36, 45
	umaal r12,r8,r2,r7 //r2 is now dead
	umaal r12,r10,r3,r6
	movs r2,#0
	umaal r12,r2,r4,r5
	adcs r1,r12,r12
	umaal r0,r1,lr,lr
	
	//r0 done (10th col)
	//r8+r10+r2 carry for 11th before col
	//r1+C carry for 11th final col
	
	//mul 37, 46, 55
	umaal r2,r8,r3,r7 //r3 is now dead
	umaal r2,r10,r4,r6
	adcs r2,r2,r2
	umaal r1,r2,r5,r5
	
	//r1 done (11th col)
	//r8+r10 carry for 12th before col
	//r2+C carry for 12th final col
	
	//mul 47, 56
	movs r3,#0
	umaal r3,r8,r4,r7 //r4 is now dead
	umaal r3,r10,r5,r6
	adcs r3,r3,r3
	umaal r2,r3,lr,lr
	
	//r2 done (12th col)
	//r8+r10 carry for 13th before col
	//r3+C carry for 13th final col
	
	//mul 57, 66
	umaal r8,r10,r5,r7 //r5 is now dead
	adcs r8,r8,r8
	umaal r3,r8,r6,r6
	
	//r3 done (13th col)
	//r10 carry for 14th before col
	//r8+C carry for 14th final col
	
	//mul 67
	umull r4,r5,lr,lr // set 0
	umaal r4,r10,r6,r7
	adcs r4,r4,r4
	umaal r4,r8,lr,lr
	
	//r4 done (14th col)
	//r10 carry for 15th before col
	//r8+C carry for 15th final col
	
	//mul 77
	adcs r10,r10,r10
	umaal r8,r10,r7,r7
	adcs r10,r10,lr
	
	//r8 done (15th col)
	//r10 done (16th col)
	
	//msb -> lsb: r10 r8 r4 r3 r2 r1 r0 r11 r9 sp sp+4 sp+8 sp+12 sp+16 sp+20 sp+24
	//now do reduction
	
	push {r4,r8,r10}
	//frame address sp,44
	add r4,sp,#12
	ldm r4,{r4-r8,r10,r12}
	//lr is already 0
	X0 .req r12
	X1 .req r10
	X2 .req r8
	X3 .req r7
	X4 .req r6
	X5 .req r5
	X6 .req r4
	X7 .req r9
	X8 .req r11
	X9 .req r0
	X10 .req r1
	X11 .req r2
	X12 .req r3

	X13 .req r7
	X14 .req r8
	X15 .req r10

	adcs X3,X0
	adcs X4,X1
	adcs X5,X2
	adcs X6,X0
	adcs X7,X1
	adcs X8,X0
	adcs X9,X1
	adcs X10,#0
	adcs X11,#0
	adcs lr,#0

	adds X6,X3
	adcs X7,X4 // X4 instead of 0
	adcs X8,X2
	adcs X9,X3
	adcs X10,X2
	adcs X11,X3
	adcs lr,#0

	subs X7,X0
	sbcs X8,X1
	sbcs X9,X2
	sbcs X10,X3
	sbcs X11,#0
	sbcs lr,#0 // lr is between 0 and 2
	
	pop {X13,X14,X15}
	//frame address sp,32

	adds X0,X12,lr
	adcs X13,#0
	mov lr,#0
	adcs lr,#0

	//adds X7,X4 (added above instead)
	adcs X8,X5
	adcs X9,X6
	adcs X10,X4
	adcs X11,X5
	adcs X0,X4
	adcs X13,X5
	adcs X14,lr
	adcs X15,#0
	mov lr,#0
	adcs lr,#0

	adcs X10,X7
	adcs X11,#0
	adcs X0,X6
	adcs X13,X7
	adcs X14,X6
	adcs X15,X7
	adcs lr,#0

	subs X11,X4
	sbcs X0,X5
	sbcs X13,X6
	sbcs X14,X7
	sbcs X15,#0
	sbcs lr,#0
	
	// now (T + mN) / R is
	// X8 X9 X10 X11 X0 X13 X14 X15 lr (lsb -> msb)
	// r11 r0 r1 r2 r12 r7 r8 r10 lr
	
	subs r11,r11,#0xffffffff
	sbcs r9,r0,#0xffffffff
	sbcs r4,r1,#0xffffffff
	sbcs r3,r2,#0
	sbcs r6,r12,#0
	sbcs r5,r7,#0
	sbcs r12,r8,#1
	sbcs r8,r10,#0xffffffff
	sbcs r7,lr,#0
	
	adds r0,r11,r7
	adcs r1,r9,r7
	adcs r2,r4,r7
	adcs r3,r3,#0
	adcs r4,r6,#0
	adcs r5,r5,#0
	adcs r6,r12,r7, lsr #31
	adcs r7,r8,r7
	
	add sp,#28
	//frame address sp,4
	pop {pc}
	
	

.global __em_p256_raw_mul
__em_p256_raw_mul:
	
	push {r2,lr}
	//frame push {lr}
	//frame address sp,8
	
	sub sp,#36
	//frame address sp,44
	ldm r2,{r2,r3,r4,r5}
	
	ldm r1!,{r0,r10,lr}
	umull r6,r11,r2,r0
	
	umull r7,r12,r3,r0
	umaal r7,r11,r2,r10
	
	push {r6,r7}
	//frame address sp,52
	
	umull r8,r6,r4,r0
	umaal r8,r11,r3,r10
	
	umull r9,r7,r5,r0
	umaal r9,r11,r4,r10
	
	umaal r11,r7,r5,r10
	
	umaal r8,r12,r2,lr
	umaal r9,r12,r3,lr
	umaal r11,r12,r4,lr
	umaal r12,r7,r5,lr
	
	ldm r1!,{r0,r10,lr}
	
	umaal r9,r6,r2,r0
	umaal r11,r6,r3,r0
	umaal r12,r6,r4,r0
	umaal r6,r7,r5,r0
	
	strd r8,r9,[sp,#8]
	
	mov r9,#0
	umaal r11,r9,r2,r10
	umaal r12,r9,r3,r10
	umaal r6,r9,r4,r10
	umaal r7,r9,r5,r10
	
	mov r10,#0
	umaal r12,r10,r2,lr
	umaal r6,r10,r3,lr
	umaal r7,r10,r4,lr
	umaal r9,r10,r5,lr
	
	ldr r8,[r1],#4
	mov lr,#0
	umaal lr,r6,r2,r8
	umaal r7,r6,r3,r8
	umaal r9,r6,r4,r8
	umaal r10,r6,r5,r8
	
	//_ _ _ _ _ 6 10 9| 7 | lr 12 11 _ _ _ _
	
	ldr r8,[r1],#-28
	mov r0,#0
	umaal r7,r0,r2,r8
	umaal r9,r0,r3,r8
	umaal r10,r0,r4,r8
	umaal r6,r0,r5,r8
	
	push {r0}
	//frame address sp,56
	
	//_ _ _ _ s 6 10 9| 7 | lr 12 11 _ _ _ _
	
	ldr r2,[sp,#48]
	adds r2,r2,#16
	ldm r2,{r2,r3,r4,r5}
	
	ldr r8,[r1],#4
	mov r0,#0
	umaal r11,r0,r2,r8
	str r11,[sp,#16+4]
	umaal r12,r0,r3,r8
	umaal lr,r0,r4,r8
	umaal r0,r7,r5,r8 // 7=carry for 9
	
	//_ _ _ _ s 6 10 9+7| 0 | lr 12 _ _ _ _ _
	
	ldr r8,[r1],#4
	mov r11,#0
	umaal r12,r11,r2,r8
	str r12,[sp,#20+4]
	umaal lr,r11,r3,r8
	umaal r0,r11,r4,r8
	umaal r11,r7,r5,r8 // 7=carry for 10
	
	//_ _ _ _ s 6 10+7 9+11| 0 | lr _ _ _ _ _ _
	
	ldr r8,[r1],#4
	mov r12,#0
	umaal lr,r12,r2,r8
	str lr,[sp,#24+4]
	umaal r0,r12,r3,r8
	umaal r11,r12,r4,r8
	umaal r10,r12,r5,r8 // 12=carry for 6
	
	//_ _ _ _ s 6+12 10+7 9+11| 0 | _ _ _ _ _ _ _
	
	ldr r8,[r1],#4
	mov lr,#0
	umaal r0,lr,r2,r8
	str r0,[sp,#28+4]
	umaal r11,lr,r3,r8
	umaal r10,lr,r4,r8
	umaal r6,lr,r5,r8 // lr=carry for saved
	
	//_ _ _ _ s+lr 6+12 10+7 9+11| _ | _ _ _ _ _ _ _
	
	ldm r1!,{r0,r8}
	umaal r11,r9,r2,r0
	str r11,[sp,#32+4]
	umaal r9,r10,r3,r0
	umaal r10,r6,r4,r0
	pop {r11}
	//frame address sp,52
	umaal r11,r6,r5,r0 // 6=carry for next
	
	//_ _ _ 6 11+lr 10+12 9+7 _ | _ | _ _ _ _ _ _ _
	
	umaal r9,r7,r2,r8
	umaal r10,r7,r3,r8
	umaal r11,r7,r4,r8
	umaal r6,r7,r5,r8
	
	ldm r1!,{r0,r8}
	umaal r10,r12,r2,r0
	umaal r11,r12,r3,r0
	umaal r6,r12,r4,r0
	umaal r7,r12,r5,r0
	
	umaal r11,lr,r2,r8
	umaal lr,r6,r3,r8
	umaal r6,r7,r4,r8
	umaal r7,r12,r5,r8
	
	// 12 7 6 lr 11 10 9 stack*9
	strd r6,r7,[sp,#36]
	str r12,[sp,#44]
	pop {r0-r8}
	//frame address sp,16
	
	mov r12,#0

	adds r3,r0
	adcs r4,r1
	adcs r5,r2
	adcs r6,r0
	adcs r7,r1
	adcs r8,r0
	adcs r9,r1
	adcs r10,#0
	adcs r11,#0
	adcs r12,#0

	adds r6,r3
	adcs r7,r4 // r4 instead of 0
	adcs r8,r2
	adcs r9,r3
	adcs r10,r2
	adcs r11,r3
	adcs r12,#0

	subs r7,r0
	sbcs r8,r1
	sbcs r9,r2
	sbcs r10,r3
	sbcs r11,#0
	sbcs r12,#0 // r12 is between 0 and 2

	pop {r1-r3}
	//frame address sp,4

	adds r0,lr,r12
	adcs r1,#0
	mov r12,#0
	adcs r12,#0

	//adds r7,r4 (added above instead)
	adcs r8,r5
	adcs r9,r6
	adcs r10,r4
	adcs r11,r5
	adcs r0,r4
	adcs r1,r5
	adcs r2,r12
	adcs r3,#0
	mov r12,#0
	adcs r12,#0

	adcs r10,r7
	adcs r11,#0
	adcs r0,r6
	adcs r1,r7
	adcs r2,r6
	adcs r3,r7
	adcs r12,#0

	subs r11,r4
	sbcs r0,r5
	sbcs r1,r6
	sbcs r2,r7
	sbcs r3,#0
	sbcs r12,#0
	
	// now (T + mN) / R is
	// 8 9 10 11 0 1 2 3 12 (lsb -> msb)
	
	subs r8,r8,#0xffffffff
	sbcs r9,r9,#0xffffffff
	sbcs r10,r10,#0xffffffff
	sbcs r11,r11,#0
	sbcs r4,r0,#0
	sbcs r5,r1,#0
	sbcs r6,r2,#1
	sbcs r7,r3,#0xffffffff
	sbc r12,r12,#0
	
	adds r0,r8,r12
	adcs r1,r9,r12
	adcs r2,r10,r12
	adcs r3,r11,#0
	adcs r4,r4,#0
	adcs r5,r5,#0
	adcs r6,r6,r12, lsr #31
	adcs r7,r7,r12
	
	pop {pc}
	
	

.global __em_p256_raw_add
__em_p256_raw_add:
	ldm r2,{r2-r9}
	ldm r1!,{r0,r10,r11,r12}
	adds r2,r0
	adcs r3,r10
	adcs r4,r11
	adcs r5,r12
	ldm r1,{r0,r1,r11,r12}
	adcs r6,r0
	adcs r7,r1
	adcs r8,r11
	adcs r9,r12
	movs r10,#0
	adcs r10,r10
	
	subs r2,#0xffffffff
	sbcs r3,#0xffffffff
	sbcs r4,#0xffffffff
	sbcs r5,#0
	sbcs r6,#0
	sbcs r7,#0
	sbcs r8,#1
	sbcs r9,#0xffffffff
	sbcs r10,#0
	
	adds r0,r2,r10
	adcs r1,r3,r10
	adcs r2,r4,r10
	adcs r3,r5,#0
	adcs r4,r6,#0
	adcs r5,r7,#0
	adcs r6,r8,r10, lsr #31
	adcs r7,r9,r10
	
	bx lr
	
	

.global __em_p256_raw_sub
__em_p256_raw_sub:
	ldm r1,{r3-r10}
	ldm r2!,{r0,r1,r11,r12}
	subs r3,r0
	sbcs r4,r1
	sbcs r5,r11
	sbcs r6,r12
	ldm r2,{r0,r1,r11,r12}
	sbcs r7,r0
	sbcs r8,r1
	sbcs r9,r11
	sbcs r10,r12
	
	sbcs r11,r11
	
	adds r0,r3,r11
	adcs r1,r4,r11
	adcs r2,r5,r11
	adcs r3,r6,#0
	adcs r4,r7,#0
	adcs r5,r8,#0
	adcs r6,r9,r11, lsr #31
	adcs r7,r10,r11
	
	bx lr
	
	

.global __em_p256_raw_times2
__em_p256_raw_times2:
	adds r0,r0
	adcs r1,r1
	adcs r2,r2
	adcs r3,r3
	adcs r4,r4
	adcs r5,r5
	adcs r6,r6
	adcs r7,r7
	mov r8,#0
	adcs r8,r8
	
	subs r0,#0xffffffff
	sbcs r1,#0xffffffff
	sbcs r2,#0xffffffff
	sbcs r3,#0
	sbcs r4,#0
	sbcs r5,#0
	sbcs r6,#1
	sbcs r7,#0xffffffff
	sbcs r8,#0
	
	adds r0,r8
	adcs r1,r8
	adcs r2,r8
	adcs r3,#0
	adcs r4,#0
	adcs r5,#0
	adcs r6,r6,r8, lsr #31
	adcs r7,r8
	
	bx lr
	

            )"
        );
    `
}

export function inv(a: T.U256_Ref) {
    // Fixed addition chain for p - 2, following the Cortex-M4 speed-optimized
    // P256_modinv schedule.  Input and output remain in Montgomery form.
    let x = T.U256.$make()
    copy(x.$ptr(), a)

    // a^3
    let r = T.U256.$make()
    copy(r.$ptr(), x.$ptr())
    square(r.$ptr())
    mul(r.$ptr(), x.$ptr())

    // a^12
    let a12 = T.U256.$make()
    copy(a12.$ptr(), r.$ptr())
    square(a12.$ptr())
    square(a12.$ptr())

    // a^15
    let a15 = T.U256.$make()
    copy(a15.$ptr(), a12.$ptr())
    mul(a15.$ptr(), r.$ptr())

    // a^(2^8 - 1)
    copy(r.$ptr(), a15.$ptr())
    for (const i of $range(4)) square(r.$ptr())
    mul(r.$ptr(), a15.$ptr())
    let a255 = T.U256.$make()
    copy(a255.$ptr(), r.$ptr())

    // a^(2^16 - 1)
    for (const i of $range(8)) square(r.$ptr())
    mul(r.$ptr(), a255.$ptr())
    let a65535 = T.U256.$make()
    copy(a65535.$ptr(), r.$ptr())

    // a^(2^32 - 1)
    for (const i of $range(16)) square(r.$ptr())
    mul(r.$ptr(), a65535.$ptr())
    let a32m1 = T.U256.$make()
    copy(a32m1.$ptr(), r.$ptr())

    // Remaining fixed chain from Emil Lenngren's speed-optimized P256_modinv.
    for (const i of $range(32)) square(r.$ptr())
    mul(r.$ptr(), x.$ptr())

    for (const i of $range(128)) square(r.$ptr())
    mul(r.$ptr(), a32m1.$ptr())

    for (const i of $range(32)) square(r.$ptr())
    mul(r.$ptr(), a32m1.$ptr())

    for (const i of $range(16)) square(r.$ptr())
    mul(r.$ptr(), a65535.$ptr())

    for (const i of $range(8)) square(r.$ptr())
    mul(r.$ptr(), a255.$ptr())

    for (const i of $range(4)) square(r.$ptr())
    mul(r.$ptr(), a15.$ptr())

    for (const i of $range(4)) square(r.$ptr())
    mul(r.$ptr(), a12.$ptr())

    mul(r.$ptr(), x.$ptr())
    copy(a, r.$ptr())
}

a$`naked,noinline`
export function mul(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11,lr}
                push    {r0}
                mov     r2,r1
                mov     r1,r0
                bl      __em_p256_raw_mul
                pop     {r12}
                stm     r12,{r0-r7}
                pop     {r4-r11,pc}
            )"
        );
    `
}

a$`naked,noinline`
export function square(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11,lr}
                push    {r0}
                ldm     r0,{r0-r7}
                bl      __em_p256_raw_sqr
                pop     {r12}
                stm     r12,{r0-r7}
                pop     {r4-r11,pc}
            )"
        );
    `
}

a$`naked,noinline`
export function sub(a: T.U256_Ref, b: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11,lr}
                push    {r0}
                mov     r2,r1
                mov     r1,r0
                bl      __em_p256_raw_sub
                pop     {r12}
                stm     r12,{r0-r7}
                pop     {r4-r11,pc}
            )"
        );
    `
}


a$`naked,noinline`
export function times2(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11,lr}
                push    {r0}
                ldm     r0,{r0-r7}
                bl      __em_p256_raw_times2
                pop     {r12}
                stm     r12,{r0-r7}
                pop     {r4-r11,pc}
            )"
        );
    `
}


a$`naked,noinline`
export function half(a: T.U256_Ref) {
    e$`
        asm volatile (
            R"(
                push    {r4-r11}
                push    {r0}
                ldm     r0,{r0-r7}

                lsl     r8,r0,#31
                adds    r0,r0,r8,asr #31
                adcs    r1,r1,r8,asr #31
                adcs    r2,r2,r8,asr #31
                adcs    r3,#0
                adcs    r4,#0
                adcs    r5,#0
                adcs    r6,r6,r8,lsr #31
                adcs    r7,r7,r8,asr #31
                rrxs    r7,r7
                rrxs    r6,r6
                rrxs    r5,r5
                rrxs    r4,r4
                rrxs    r3,r3
                rrxs    r2,r2
                rrxs    r1,r1
                rrx     r0,r0

                pop     {r8}
                stm     r8,{r0-r7}
                pop     {r4-r11}
                bx      lr
            )"
        );
    `
}
