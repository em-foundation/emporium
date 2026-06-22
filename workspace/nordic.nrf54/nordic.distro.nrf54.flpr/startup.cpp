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

typedef struct {
    unsigned int *codeLoad;
    unsigned int *codeAddr;
    unsigned int *bssAddr;
    unsigned int bssSize;
} __em_desc_t;

extern "C" void __attribute__((section(".start"), noreturn)) em__start() {

#ifdef __EM_ARCH_riscv32__
    asm(".option norelax");
    asm("lui     gp,     %hi(__global_pointer__)");
    asm("addi    gp, gp, %lo(__global_pointer__)");
    asm("lui     tp,     %hi(__bss_addr__)");
    asm("addi    tp, tp, %lo(__bss_addr__)");
    asm("lui     t0,     %hi(__stack_top__)");
    asm("addi    sp, t0, %lo(__stack_top__)");
    asm(".option relax");
#endif

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
    main();
    __builtin_unreachable();
}

#if __EM_BOOT_FLASH__ == 1
extern "C" const void *__attribute__((
    section(".start_vec"))) __em_start_vec[] = {
    (void *)&__stack_top__,
    (void *)em__start,
};
#endif
