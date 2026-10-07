import '@$$emscript'
export const $U = $declare('MODULE', FieldI)

import * as FieldI from '@em.crypto.p256/FieldI.em'
import * as T from '@em.crypto.p256/Types.em'

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
        out.close()
    }


}

//>> ---- em$targ ---- <<//

export function add(a: T.U256_Ref, b: T.U256_Ref) {
    e$`add_asm(a, b)`
}

export function mul(a: T.U256_Ref, b: T.U256_Ref) {
    e$`mul_asm(a, b)`
}

export function sub(a: T.U256_Ref, b: T.U256_Ref) {
    e$`sub_asm(a, b)`
}
