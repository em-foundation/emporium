#define __EM_BOOT_FLASH__ 0

#include <stdbool.h>
#include <stdint.h>

#include "intr.cpp"

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

extern "C" void __attribute__((section(".start"), noreturn)) em__start() {
    asm(".option norelax");
    asm("lui     gp,     %hi(__global_pointer__)");
    asm("addi    gp, gp, %lo(__global_pointer__)");
    asm("lui     tp,     %hi(__bss_addr__)");
    asm("addi    tp, tp, %lo(__bss_addr__)");
    asm("lui     t0,     %hi(__stack_top__)");
    asm("addi    sp, t0, %lo(__stack_top__)");
    asm(".option relax");
    main();
    __builtin_unreachable();
}
