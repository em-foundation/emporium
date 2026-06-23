#define __EM_BOOT_FLASH__ 0

#include <stdbool.h>
#include <stdint.h>

extern "C" uint32_t __bss_addr__;
extern "C" uint32_t __bss_size__;
extern "C" uint32_t __code_addr__;
extern "C" uint32_t __code_load__;
extern "C" uint32_t __code_size__;
extern "C" uint32_t __data_addr__;
extern "C" uint32_t __data_load__;
extern "C" uint32_t __data_size__;
extern "C" uint32_t __global_pointer__;
extern "C" uint32_t __stack_top__;

extern "C" int main();

#if 0
extern "C" void __attribute__((section(".start"), naked, used, noreturn))
em__start() {
    asm volatile(".option push\n"
                 ".option norelax\n"
                 "lui     gp,     %hi(__global_pointer__)\n"
                 "addi    gp, gp, %lo(__global_pointer__)\n"
                 ".option pop\n"

                 "lui     t0,     %hi(__stack_top__)\n"
                 "addi    sp, t0, %lo(__stack_top__)\n"

                 /* mark IMEM-ish area: 0x20028100 = 0x00000111 */
                 "lui     t0, 0x20028\n"
                 "li      t1, 0x111\n"
                 "sw      t1, 0x100(t0)\n"

                 /* mark DMEM/BSS base: 0x20030000 = 0x00000222 */
                 "lui     t0, 0x20030\n"
                 "li      t1, 0x222\n"
                 "sw      t1, 0(t0)\n"

                 /* stay here forever */
                 "1: j 1b\n");
}
#endif

extern "C" void __attribute__((section(".start"), noreturn)) em__start() {

    asm(".option norelax");
    asm("lui     gp,     %hi(__global_pointer__)");
    asm("addi    gp, gp, %lo(__global_pointer__)");
    asm("lui     tp,     %hi(__bss_addr__)");
    asm("addi    tp, tp, %lo(__bss_addr__)");
    asm("lui     t0,     %hi(__stack_top__)");
    asm("addi    sp, t0, %lo(__stack_top__)");
    asm(".option relax");

#if 0
     uint32_t *src;
     uint32_t *dst;
     volatile uint32_t sz;
     sz = (uint32_t)&__bss_size__;
     dst = &__bss_addr__;
     asm("nop");
     asm("nop");
     asm("nop");
     for (uint32_t i = 0; i < sz; i++) { // TODO -- while (sz--) not working
         dst[i] = 0;
     }
     sz = (uint32_t)&__data_size__;
     src = &__data_load__;
     dst = &__data_addr__;
     for (uint32_t i = 0; i < sz; i++) {
         dst[i] = src[i];
     }
#endif
    main();
    __builtin_unreachable();
}
