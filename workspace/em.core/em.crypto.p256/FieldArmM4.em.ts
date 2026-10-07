import '@$$emscript'
export const $U = $declare('MODULE', FieldI)

import * as FieldI from '@em.crypto.p256/FieldI.em'
import * as T from '@em.crypto.p256/Types.em'
import * as Mem from '@em.utils/Mem.em'

export namespace em$meta {
    export function em$generate() {
        let out = $outfile('em.crypto.p256/FieldArmM4-gen.cpp')
        out.addFrag(`
                    |-> namespace em_crypto_p256_FieldArmM4 {
                    |->  
                    |-> __attribute__((noinline))
                    |-> void add_asm(T::U256_Ref a, T::U256_Ref b) {
                    |->     register uint32_t *ra asm("r0") = a.p_;
                    |->     register uint32_t *rb asm("r1") = b.p_;
                    |->  
                    |->     asm volatile (
                    |->         R"(
                    |->             /* Adapt the reference custom ABI to a := a + b mod p. */
                    |->             push    {r0}
                    |->             mov     r2,r1
                    |->             mov     r1,r0
                    |->  
                    |->             ldm     r2,{r2-r9}
                    |->             ldm     r1!,{r0,r10,r11,r12}
                    |->             adds    r2,r0
                    |->             adcs    r3,r10
                    |->             adcs    r4,r11
                    |->             adcs    r5,r12
                    |->             ldm     r1,{r0,r1,r11,r12}
                    |->             adcs    r6,r0
                    |->             adcs    r7,r1
                    |->             adcs    r8,r11
                    |->             adcs    r9,r12
                    |->             movs    r10,#0
                    |->             adcs    r10,r10
                    |->  
                    |->             /* Conditional subtraction of p. */
                    |->             subs    r2,#0xffffffff
                    |->             sbcs    r3,#0xffffffff
                    |->             sbcs    r4,#0xffffffff
                    |->             sbcs    r5,#0
                    |->             sbcs    r6,#0
                    |->             sbcs    r7,#0
                    |->             sbcs    r8,#1
                    |->             sbcs    r9,#0xffffffff
                    |->             sbcs    r10,#0
                    |->  
                    |->             adds    r0,r2,r10
                    |->             adcs    r1,r3,r10
                    |->             adcs    r2,r4,r10
                    |->             adcs    r3,r5,#0
                    |->             adcs    r4,r6,#0
                    |->             adcs    r5,r7,#0
                    |->             adcs    r6,r8,r10,lsr #31
                    |->             adcs    r7,r9,r10
                    |->  
                    |->             pop     {r8}
                    |->             stm     r8,{r0-r7}
                    |->         )"
                    |->         : "+r" (ra), "+r" (rb)
                    |->         :
                    |->         : "r2", "r3", "r4", "r5", "r6", "r7",
                    |->           "r8", "r9", "r10", "r11", "r12", "cc", "memory"
                    |->     );
                    |-> }
                    |->  
                    |-> };
    `
        )
        out.addFrag(`
                    |-> namespace em_crypto_p256_FieldArmM4 {
                    |->  
                    |-> __attribute__((noinline))
                    |-> void mul_asm(T::U256_Ref a, T::U256_Ref b) {
                    |->     register uint32_t *ra asm("r0") = a.p_;
                    |->     register uint32_t *rb asm("r1") = b.p_;
                    |->  
                    |->     asm volatile (
                    |->         R"(
                    |->             /* Save the public ABI operands; the kernel uses a custom register ABI. */
                    |->             push    {r0,r1}
                    |->     
                    |->             mov     r2,r1
                    |->             mov     r1,r0
                    |->     
                    |->             /* Original P256_mulmod custom ABI:
                    |->              *   r1 = in1, r2 = in2
                    |->              *   result = r0-r7
                    |->              */
                    |->             push    {r2,r12}
                    |->             sub     sp,#36
                    |->             ldm     r2,{r2,r3,r4,r5}
                    |->     
                    |->             ldm     r1!,{r0,r10,lr}
                    |->             umull   r6,r11,r2,r0
                    |->     
                    |->             umull   r7,r12,r3,r0
                    |->             umaal   r7,r11,r2,r10
                    |->     
                    |->             push    {r6,r7}
                    |->     
                    |->             umull   r8,r6,r4,r0
                    |->             umaal   r8,r11,r3,r10
                    |->     
                    |->             umull   r9,r7,r5,r0
                    |->             umaal   r9,r11,r4,r10
                    |->     
                    |->             umaal   r11,r7,r5,r10
                    |->     
                    |->             umaal   r8,r12,r2,lr
                    |->             umaal   r9,r12,r3,lr
                    |->             umaal   r11,r12,r4,lr
                    |->             umaal   r12,r7,r5,lr
                    |->     
                    |->             ldm     r1!,{r0,r10,lr}
                    |->     
                    |->             umaal   r9,r6,r2,r0
                    |->             umaal   r11,r6,r3,r0
                    |->             umaal   r12,r6,r4,r0
                    |->             umaal   r6,r7,r5,r0
                    |->     
                    |->             strd    r8,r9,[sp,#8]
                    |->     
                    |->             mov     r9,#0
                    |->             umaal   r11,r9,r2,r10
                    |->             umaal   r12,r9,r3,r10
                    |->             umaal   r6,r9,r4,r10
                    |->             umaal   r7,r9,r5,r10
                    |->     
                    |->             mov     r10,#0
                    |->             umaal   r12,r10,r2,lr
                    |->             umaal   r6,r10,r3,lr
                    |->             umaal   r7,r10,r4,lr
                    |->             umaal   r9,r10,r5,lr
                    |->     
                    |->             ldr     r8,[r1],#4
                    |->             mov     lr,#0
                    |->             umaal   lr,r6,r2,r8
                    |->             umaal   r7,r6,r3,r8
                    |->             umaal   r9,r6,r4,r8
                    |->             umaal   r10,r6,r5,r8
                    |->     
                    |->             ldr     r8,[r1],#-28
                    |->             mov     r0,#0
                    |->             umaal   r7,r0,r2,r8
                    |->             umaal   r9,r0,r3,r8
                    |->             umaal   r10,r0,r4,r8
                    |->             umaal   r6,r0,r5,r8
                    |->     
                    |->             push    {r0}
                    |->     
                    |->             ldr     r2,[sp,#48]
                    |->             adds    r2,r2,#16
                    |->             ldm     r2,{r2,r3,r4,r5}
                    |->     
                    |->             ldr     r8,[r1],#4
                    |->             mov     r0,#0
                    |->             umaal   r11,r0,r2,r8
                    |->             str     r11,[sp,#20]
                    |->             umaal   r12,r0,r3,r8
                    |->             umaal   lr,r0,r4,r8
                    |->             umaal   r0,r7,r5,r8
                    |->     
                    |->             ldr     r8,[r1],#4
                    |->             mov     r11,#0
                    |->             umaal   r12,r11,r2,r8
                    |->             str     r12,[sp,#24]
                    |->             umaal   lr,r11,r3,r8
                    |->             umaal   r0,r11,r4,r8
                    |->             umaal   r11,r7,r5,r8
                    |->     
                    |->             ldr     r8,[r1],#4
                    |->             mov     r12,#0
                    |->             umaal   lr,r12,r2,r8
                    |->             str     lr,[sp,#28]
                    |->             umaal   r0,r12,r3,r8
                    |->             umaal   r11,r12,r4,r8
                    |->             umaal   r10,r12,r5,r8
                    |->     
                    |->             ldr     r8,[r1],#4
                    |->             mov     lr,#0
                    |->             umaal   r0,lr,r2,r8
                    |->             str     r0,[sp,#32]
                    |->             umaal   r11,lr,r3,r8
                    |->             umaal   r10,lr,r4,r8
                    |->             umaal   r6,lr,r5,r8
                    |->     
                    |->             ldm     r1!,{r0,r8}
                    |->             umaal   r11,r9,r2,r0
                    |->             str     r11,[sp,#36]
                    |->             umaal   r9,r10,r3,r0
                    |->             umaal   r10,r6,r4,r0
                    |->             pop     {r11}
                    |->             umaal   r11,r6,r5,r0
                    |->     
                    |->             umaal   r9,r7,r2,r8
                    |->             umaal   r10,r7,r3,r8
                    |->             umaal   r11,r7,r4,r8
                    |->             umaal   r6,r7,r5,r8
                    |->     
                    |->             ldm     r1!,{r0,r8}
                    |->             umaal   r10,r12,r2,r0
                    |->             umaal   r11,r12,r3,r0
                    |->             umaal   r6,r12,r4,r0
                    |->             umaal   r7,r12,r5,r0
                    |->     
                    |->             umaal   r11,lr,r2,r8
                    |->             umaal   lr,r6,r3,r8
                    |->             umaal   r6,r7,r4,r8
                    |->             umaal   r7,r12,r5,r8
                    |->     
                    |->             strd    r6,r7,[sp,#36]
                    |->             str     r12,[sp,#44]
                    |->             pop     {r0-r8}
                    |->     
                    |->             mov     r12,#0
                    |->     
                    |->             adds    r3,r0
                    |->             adcs    r4,r1
                    |->             adcs    r5,r2
                    |->             adcs    r6,r0
                    |->             adcs    r7,r1
                    |->             adcs    r8,r0
                    |->             adcs    r9,r1
                    |->             adcs    r10,#0
                    |->             adcs    r11,#0
                    |->             adcs    r12,#0
                    |->     
                    |->             adds    r6,r3
                    |->             adcs    r7,r4
                    |->             adcs    r8,r2
                    |->             adcs    r9,r3
                    |->             adcs    r10,r2
                    |->             adcs    r11,r3
                    |->             adcs    r12,#0
                    |->     
                    |->             subs    r7,r0
                    |->             sbcs    r8,r1
                    |->             sbcs    r9,r2
                    |->             sbcs    r10,r3
                    |->             sbcs    r11,#0
                    |->             sbcs    r12,#0
                    |->     
                    |->             pop     {r1-r3}
                    |->     
                    |->             adds    r0,lr,r12
                    |->             adcs    r1,#0
                    |->             mov     r12,#0
                    |->             adcs    r12,#0
                    |->     
                    |->             adcs    r8,r5
                    |->             adcs    r9,r6
                    |->             adcs    r10,r4
                    |->             adcs    r11,r5
                    |->             adcs    r0,r4
                    |->             adcs    r1,r5
                    |->             adcs    r2,r12
                    |->             adcs    r3,#0
                    |->             mov     r12,#0
                    |->             adcs    r12,#0
                    |->     
                    |->             adcs    r10,r7
                    |->             adcs    r11,#0
                    |->             adcs    r0,r6
                    |->             adcs    r1,r7
                    |->             adcs    r2,r6
                    |->             adcs    r3,r7
                    |->             adcs    r12,#0
                    |->     
                    |->             subs    r11,r4
                    |->             sbcs    r0,r5
                    |->             sbcs    r1,r6
                    |->             sbcs    r2,r7
                    |->             sbcs    r3,#0
                    |->             sbcs    r12,#0
                    |->     
                    |->             /* Conditional subtraction of p. */
                    |->             subs    r8,r8,#0xffffffff
                    |->             sbcs    r9,r9,#0xffffffff
                    |->             sbcs    r10,r10,#0xffffffff
                    |->             sbcs    r11,r11,#0
                    |->             sbcs    r4,r0,#0
                    |->             sbcs    r5,r1,#0
                    |->             sbcs    r6,r2,#1
                    |->             sbcs    r7,r3,#0xffffffff
                    |->             sbc     r12,r12,#0
                    |->     
                    |->             adds    r0,r8,r12
                    |->             adcs    r1,r9,r12
                    |->             adcs    r2,r10,r12
                    |->             adcs    r3,r11,#0
                    |->             adcs    r4,r4,#0
                    |->             adcs    r5,r5,#0
                    |->             adcs    r6,r6,r12,lsr #31
                    |->             adcs    r7,r7,r12
                    |->     
                    |->             /* Discard the kernel's saved filler word (reference kernel returned here). */
                    |->             pop     {r12}
                    |->     
                    |->             /* Store r0-r7 through the original destination pointer. */
                    |->             ldr     r8,[sp,#0]
                    |->             stm     r8,{r0-r7}
                    |->             add     sp,#8
                    |->         )"
                    |->         : "+r" (ra), "+r" (rb)
                    |->         :
                    |->         : "r2", "r3", "r4", "r5", "r6", "r7",
                    |->           "r8", "r9", "r10", "r11", "r12", "lr", "cc", "memory"
                    |->     );
                    |-> }
                    |->  
                    |-> };
    `
        )
        out.addFrag(`
                    |-> namespace em_crypto_p256_FieldArmM4 {
                    |->  
                    |-> __attribute__((noinline))
                    |-> void sub_asm(T::U256_Ref a, T::U256_Ref b) {
                    |->     register uint32_t *ra asm("r0") = a.p_;
                    |->     register uint32_t *rb asm("r1") = b.p_;
                    |->  
                    |->     asm volatile (
                    |->         R"(
                    |->             /* Adapt the reference custom ABI to a := a - b mod p. */
                    |->             push    {r0}
                    |->             mov     r2,r1
                    |->             mov     r1,r0
                    |->  
                    |->             ldm     r1,{r3-r10}
                    |->             ldm     r2!,{r0,r1,r11,r12}
                    |->             subs    r3,r0
                    |->             sbcs    r4,r1
                    |->             sbcs    r5,r11
                    |->             sbcs    r6,r12
                    |->             ldm     r2,{r0,r1,r11,r12}
                    |->             sbcs    r7,r0
                    |->             sbcs    r8,r1
                    |->             sbcs    r9,r11
                    |->             sbcs    r10,r12
                    |->  
                    |->             sbcs    r11,r11
                    |->  
                    |->             /* Conditionally add p back after a borrow. */
                    |->             adds    r0,r3,r11
                    |->             adcs    r1,r4,r11
                    |->             adcs    r2,r5,r11
                    |->             adcs    r3,r6,#0
                    |->             adcs    r4,r7,#0
                    |->             adcs    r5,r8,#0
                    |->             adcs    r6,r9,r11,lsr #31
                    |->             adcs    r7,r10,r11
                    |->  
                    |->             pop     {r8}
                    |->             stm     r8,{r0-r7}
                    |->         )"
                    |->         : "+r" (ra), "+r" (rb)
                    |->         :
                    |->         : "r2", "r3", "r4", "r5", "r6", "r7",
                    |->           "r8", "r9", "r10", "r11", "r12", "cc", "memory"
                    |->     );
                    |-> }
                    |->  
                    |-> };
    `
        )

        out.addFrag(`
                    |-> namespace em_crypto_p256_FieldArmM4 {
                    |->  
                    |-> __attribute__((noinline))
                    |-> void square_asm(T::U256_Ref a) {
                    |->     register uint32_t *ra asm("r0") = a.p_;
                    |->  
                    |->     asm volatile (
                    |->         R"(
                    |->             /* Save destination, then load the field element into r0-r7. */
                    |->             push    {r0}
                    |->             ldm     r0,{r0-r7}
                    |->  
                    |->             /* Reference P256_sqrmod uses one saved-word frame slot. */
                    |->             push    {r12}
                    |->  
                    |->             /* mul 01, 00 */
                    |->             umull   r10,r9,r0,r0
                    |->             umull   r11,r12,r0,r1
                    |->             adds    r11,r11,r11
                    |->             mov     lr,#0
                    |->             umaal   r9,r11,lr,lr
                    |->  
                    |->             push    {r9,r10}
                    |->  
                    |->             /* mul 02, 11 */
                    |->             mov     r9,#0
                    |->             umaal   r9,r12,r0,r2
                    |->             adcs    r9,r9,r9
                    |->             umaal   r9,r11,r1,r1
                    |->  
                    |->             /* mul 03, 12 */
                    |->             umull   r8,r10,r0,r3
                    |->             umaal   r8,r12,r1,r2
                    |->             adcs    r8,r8,r8
                    |->             umaal   r8,r11,lr,lr
                    |->  
                    |->             push    {r8,r9}
                    |->  
                    |->             /* mul 04, 13, 22 */
                    |->             mov     r9,#0
                    |->             umaal   r9,r10,r0,r4
                    |->             umaal   r9,r12,r1,r3
                    |->             adcs    r9,r9,r9
                    |->             umaal   r9,r11,r2,r2
                    |->  
                    |->             push    {r9}
                    |->  
                    |->             /* mul 05, 14, 23 */
                    |->             umull   r9,r8,r0,r5
                    |->             umaal   r9,r10,r1,r4
                    |->             umaal   r9,r12,r2,r3
                    |->             adcs    r9,r9,r9
                    |->             umaal   r9,r11,lr,lr
                    |->  
                    |->             push    {r9}
                    |->  
                    |->             /* mul 06, 15, 24, 33 */
                    |->             mov     r9,#0
                    |->             umaal   r9,r8,r1,r5
                    |->             umaal   r9,r12,r2,r4
                    |->             umaal   r9,r10,r0,r6
                    |->             adcs    r9,r9,r9
                    |->             umaal   r9,r11,r3,r3
                    |->  
                    |->             push    {r9}
                    |->  
                    |->             /* mul 07, 16, 25, 34 */
                    |->             umull   r9,r0,r0,r7
                    |->             umaal   r9,r10,r1,r6
                    |->             umaal   r9,r12,r2,r5
                    |->             umaal   r9,r8,r3,r4
                    |->             adcs    r9,r9,r9
                    |->             umaal   r9,r11,lr,lr
                    |->  
                    |->             /* mul 17, 26, 35, 44 */
                    |->             umaal   r0,r8,r1,r7
                    |->             umaal   r0,r10,r2,r6
                    |->             umaal   r0,r12,r3,r5
                    |->             adcs    r0,r0,r0
                    |->             umaal   r11,r0,r4,r4
                    |->  
                    |->             /* mul 27, 36, 45 */
                    |->             umaal   r12,r8,r2,r7
                    |->             umaal   r12,r10,r3,r6
                    |->             movs    r2,#0
                    |->             umaal   r12,r2,r4,r5
                    |->             adcs    r1,r12,r12
                    |->             umaal   r0,r1,lr,lr
                    |->  
                    |->             /* mul 37, 46, 55 */
                    |->             umaal   r2,r8,r3,r7
                    |->             umaal   r2,r10,r4,r6
                    |->             adcs    r2,r2,r2
                    |->             umaal   r1,r2,r5,r5
                    |->  
                    |->             /* mul 47, 56 */
                    |->             movs    r3,#0
                    |->             umaal   r3,r8,r4,r7
                    |->             umaal   r3,r10,r5,r6
                    |->             adcs    r3,r3,r3
                    |->             umaal   r2,r3,lr,lr
                    |->  
                    |->             /* mul 57, 66 */
                    |->             umaal   r8,r10,r5,r7
                    |->             adcs    r8,r8,r8
                    |->             umaal   r3,r8,r6,r6
                    |->  
                    |->             /* mul 67 */
                    |->             umull   r4,r5,lr,lr
                    |->             umaal   r4,r10,r6,r7
                    |->             adcs    r4,r4,r4
                    |->             umaal   r4,r8,lr,lr
                    |->  
                    |->             /* mul 77 */
                    |->             adcs    r10,r10,r10
                    |->             umaal   r8,r10,r7,r7
                    |->             adcs    r10,r10,lr
                    |->  
                    |->             /* Montgomery reduction. */
                    |->             push    {r4,r8,r10}
                    |->             add     r4,sp,#12
                    |->             ldm     r4,{r4-r8,r10,r12}
                    |->  
                    |->             X0 .req r12
                    |->             X1 .req r10
                    |->             X2 .req r8
                    |->             X3 .req r7
                    |->             X4 .req r6
                    |->             X5 .req r5
                    |->             X6 .req r4
                    |->             X7 .req r9
                    |->             X8 .req r11
                    |->             X9 .req r0
                    |->             X10 .req r1
                    |->             X11 .req r2
                    |->             X12 .req r3
                    |->             X13 .req r7
                    |->             X14 .req r8
                    |->             X15 .req r10
                    |->  
                    |->             adcs    X3,X0
                    |->             adcs    X4,X1
                    |->             adcs    X5,X2
                    |->             adcs    X6,X0
                    |->             adcs    X7,X1
                    |->             adcs    X8,X0
                    |->             adcs    X9,X1
                    |->             adcs    X10,#0
                    |->             adcs    X11,#0
                    |->             adcs    lr,#0
                    |->  
                    |->             adds    X6,X3
                    |->             adcs    X7,X4
                    |->             adcs    X8,X2
                    |->             adcs    X9,X3
                    |->             adcs    X10,X2
                    |->             adcs    X11,X3
                    |->             adcs    lr,#0
                    |->  
                    |->             subs    X7,X0
                    |->             sbcs    X8,X1
                    |->             sbcs    X9,X2
                    |->             sbcs    X10,X3
                    |->             sbcs    X11,#0
                    |->             sbcs    lr,#0
                    |->  
                    |->             pop     {X13,X14,X15}
                    |->  
                    |->             adds    X0,X12,lr
                    |->             adcs    X13,#0
                    |->             mov     lr,#0
                    |->             adcs    lr,#0
                    |->  
                    |->             adcs    X8,X5
                    |->             adcs    X9,X6
                    |->             adcs    X10,X4
                    |->             adcs    X11,X5
                    |->             adcs    X0,X4
                    |->             adcs    X13,X5
                    |->             adcs    X14,lr
                    |->             adcs    X15,#0
                    |->             mov     lr,#0
                    |->             adcs    lr,#0
                    |->  
                    |->             adcs    X10,X7
                    |->             adcs    X11,#0
                    |->             adcs    X0,X6
                    |->             adcs    X13,X7
                    |->             adcs    X14,X6
                    |->             adcs    X15,X7
                    |->             adcs    lr,#0
                    |->  
                    |->             subs    X11,X4
                    |->             sbcs    X0,X5
                    |->             sbcs    X13,X6
                    |->             sbcs    X14,X7
                    |->             sbcs    X15,#0
                    |->             sbcs    lr,#0
                    |->  
                    |->             /* Conditional subtraction of p. */
                    |->             subs    r11,r11,#0xffffffff
                    |->             sbcs    r9,r0,#0xffffffff
                    |->             sbcs    r4,r1,#0xffffffff
                    |->             sbcs    r3,r2,#0
                    |->             sbcs    r6,r12,#0
                    |->             sbcs    r5,r7,#0
                    |->             sbcs    r12,r8,#1
                    |->             sbcs    r8,r10,#0xffffffff
                    |->             sbcs    r7,lr,#0
                    |->  
                    |->             adds    r0,r11,r7
                    |->             adcs    r1,r9,r7
                    |->             adcs    r2,r4,r7
                    |->             adcs    r3,r3,#0
                    |->             adcs    r4,r6,#0
                    |->             adcs    r5,r5,#0
                    |->             adcs    r6,r12,r7,lsr #31
                    |->             adcs    r7,r8,r7
                    |->  
                    |->             .unreq X0
                    |->             .unreq X1
                    |->             .unreq X2
                    |->             .unreq X3
                    |->             .unreq X4
                    |->             .unreq X5
                    |->             .unreq X6
                    |->             .unreq X7
                    |->             .unreq X8
                    |->             .unreq X9
                    |->             .unreq X10
                    |->             .unreq X11
                    |->             .unreq X12
                    |->             .unreq X13
                    |->             .unreq X14
                    |->             .unreq X15
                    |->  
                    |->             add     sp,#28
                    |->             pop     {r12}
                    |->  
                    |->             /* Restore destination pointer and store the result. */
                    |->             pop     {r12}
                    |->             stm     r12,{r0-r7}
                    |->         )"
                    |->         : "+r" (ra)
                    |->         :
                    |->         : "r1", "r2", "r3", "r4", "r5", "r6", "r7",
                    |->           "r8", "r9", "r10", "r11", "r12", "lr", "cc", "memory"
                    |->     );
                    |-> }
                    |->  
                    |-> };
    `
        )

        out.addFrag(`
                    |-> namespace em_crypto_p256_FieldArmM4 {
                    |->  
                    |-> __attribute__((noinline))
                    |-> void copy_asm(T::U256_Ref a, T::U256_Ref b) {
                    |->     register uint32_t *ra asm("r0") = a.p_;
                    |->     register uint32_t *rb asm("r1") = b.p_;
                    |->  
                    |->     asm volatile (
                    |->         R"(
                    |->             ldmia   r1!,{r2,r3,r12}
                    |->             stmia   r0!,{r2,r3,r12}
                    |->             ldmia   r1!,{r2,r3,r12}
                    |->             stmia   r0!,{r2,r3,r12}
                    |->             ldmia   r1!,{r2,r3}
                    |->             stmia   r0!,{r2,r3}
                    |->         )"
                    |->         : "+r" (ra), "+r" (rb)
                    |->         :
                    |->         : "r2", "r3", "r12", "memory"
                    |->     );
                    |-> }
                    |->  
                    |-> };
        `
        )

        out.close()
    }


}

//>> ---- em$targ ---- <<//

export function add(a: T.U256_Ref, b: T.U256_Ref) {
    e$`add_asm(a, b)`
}


export function copy(a: T.U256_Ref, b: T.U256_Ref) {
    e$`copy_asm(a, b)`
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

export function mul(a: T.U256_Ref, b: T.U256_Ref) {
    e$`mul_asm(a, b)`
}

export function square(a: T.U256_Ref) {
    e$`square_asm(a)`
}


export function sub(a: T.U256_Ref, b: T.U256_Ref) {
    e$`sub_asm(a, b)`
}
