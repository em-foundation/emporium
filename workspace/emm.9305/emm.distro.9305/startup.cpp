#include <stdbool.h>
#include <stdint.h>

#include "../em.arch.arc/intr.cpp"

extern uint32_t __bss_addr__;
extern uint32_t __bss_size__;
extern uint32_t __code_addr__;
extern uint32_t __code_load__;
extern uint32_t __code_size__;
extern uint32_t __data_addr__;
extern uint32_t __data_load__;
extern uint32_t __data_size__;
extern uint32_t __global_pointer__;
extern uint32_t __stack_top__;

extern "C" int main();

extern "C" void COMMON_WaitUs(uint32_t us);
extern "C" void memcpy32(uint32_t *pDestination, const uint32_t *pSource, uint32_t numBytes);


extern "C" __attribute__ ((section(".entry"), noreturn)) void em__start() {
    asm ("mov_s	%sp,__stack_top__");

    if (!em__IS_WARM()) {
        uint32_t *src;
        uint32_t *dst;
        uint32_t sz;
        sz = (uint32_t)&__bss_size__;
        dst = &__bss_addr__;
        while (sz > 0) {
            *dst++ = 0;
            sz -= 1;
        }
        sz = (uint32_t)&__data_size__;
        src = &__data_load__;
        dst = &__data_addr__;
        memcpy32(dst, src, sz * 4);
    #if __EM_BOOT_FLASH__ == 1
        sz = (uint32_t)&__code_size__;
        src = &__code_load__;
        dst = &__code_addr__;
        memcpy32(dst, src, sz * 4);
    #endif
    }

    #if __EM_BOOT_FLASH__ == 1
        *em::$reg32((uint32_t)&SYS->RegMemCfg) |= MEM_DRAM5_IN_ICCM_MASK;
    #endif

    main();
    __builtin_unreachable();    
}

// need for C++ constructors
extern "C"  void* memset(void *s, int c, size_t n) {
    unsigned char *ptr = (unsigned char *)s;
    unsigned char value = (unsigned char)c;
    for (size_t i = 0; i < n; i++) {
        ptr[i] = value;
    }
    return s;
}
