ENTRY(em__start)

MEMORY
{
    DESC : ORIGIN = 0x2003BFE8, LENGTH = 0x00000018
    PMEM : ORIGIN = 0x2003C000, LENGTH = 0x00003E00
}

SECTIONS
{
    __boot_flag__ = 0;

    /*
     * Loader descriptor.
     * Six 32-bit words:
     *   code runtime address
     *   code load size in words
     *   data runtime address
     *   data load size in words
     *   bss runtime address
     *   bss size in words
     */
    .desc ORIGIN(DESC) :
    {
        LONG(__code_addr__);
        LONG(__code_word_size__);
        LONG(__data_addr__);
        LONG(__data_word_size__);
        LONG(__bss_addr__);
        LONG(__bss_word_size__);
    } > DESC

    /*
     * FLPR executable image.
     * INITPC should be __code_addr__ / em__start = 0x20028000.
     */
    .text :
    {
        __code_addr__ = .;
        KEEP(*(.start))
        *(.text .text.*)
        . = ALIGN(4);
     } > PMEM

    .const :
    {
        *(.rodata .rodata.*)
        *(.constdata .constdata.*)
        . = ALIGN(4);
    } > PMEM

    .intvec :
    {
        KEEP(*(.intvec))
        __text_end__ = .;
    } > PMEM

    __data_load__ = ALIGN(__text_end__, 4);

    .data : AT(__data_load__)
    {
        __data_addr__ = .;

        *(.sdata .sdata.*)
        *(.data .data.*)

        . = ALIGN(4);
        __data_end__ = .;
    } > PMEM

    /*
     * Runtime-only BSS.
     */
    .bss (NOLOAD) :
    {
        __bss_addr__ = .;

        *(.sbss .sbss.*)
        *(.bss .bss.*)
        *(COMMON)

        . = ALIGN(4);
        __bss_end__ = .;
    } > PMEM

    /*
     * Runtime symbols expected by startup.
     * Sizes are word counts.
     */
    __data_size__ = SIZEOF(.data) / 4;
    __bss_size__  = SIZEOF(.bss) / 4;

    __code_word_size__ = (__text_end__ - __code_addr__) / 4;
    __data_word_size__ = SIZEOF(.data) / 4;

    __code_size__ = __code_word_size__;

    /*
     * Load image copied by M33:
     *   .text/.rodata plus initialized .data load bytes.
     */
    __load_start__     = __code_addr__;
    __load_end__       = __data_load__ + SIZEOF(.data);
    __load_word_size__ = (__load_end__ - __load_start__) / 4;

    __bss_word_size__ = __bss_size__;

    /*
     * Compatibility aliases.
     */
    __code_load__ = __code_addr__;
    __heap_addr__ = __bss_end__;

    /*
     * RISC-V gp/sp.
     */
    __global_pointer__ = __data_addr__ + 0x800;
    __global_pointer$  = __global_pointer__;
    __stack_top__      = ORIGIN(PMEM) + LENGTH(PMEM);

    /*
     * Sanity checks.
     */
    ASSERT((__code_word_size__ * 4) == (__text_end__ - __code_addr__),
           "FLPR code image is not 4-byte aligned")

    ASSERT((__data_word_size__ * 4) == SIZEOF(.data),
           "FLPR data image is not 4-byte aligned")

    ASSERT((__load_word_size__ * 4) == (__load_end__ - __load_start__),
           "FLPR combined load image is not 4-byte aligned")

    ASSERT((__bss_word_size__ * 4) == SIZEOF(.bss),
           "FLPR bss is not 4-byte aligned")

    ASSERT(__bss_end__ <= ORIGIN(PMEM) + LENGTH(PMEM),
           "FLPR image overflows")

    ASSERT(SIZEOF(.desc) == 24,
           "FLPR descriptor must be exactly 24 bytes")
}
