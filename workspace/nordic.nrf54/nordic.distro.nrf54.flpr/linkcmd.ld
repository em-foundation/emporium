ENTRY(em__start)

MEMORY
{
    /*
     * FLPR SRAM window:
     *   0x20028000 .. 0x20040000
     *
     * Descriptor is 16 bytes before IMEM.
     * Code starts cleanly at 0x20028000.
     */
    DESC : ORIGIN = 0x20027FF0, LENGTH = 0x00000010
    IMEM : ORIGIN = 0x20028000, LENGTH = 0x00008000
    DMEM : ORIGIN = 0x20030000, LENGTH = 0x00010000
}

SECTIONS
{
    __boot_flag__ = 0;

    /*
     * Loader descriptor.
     * Four 32-bit words:
     *   load address
     *   load size in words
     *   bss address
     *   bss size in words
     */
    .desc ORIGIN(DESC) :
    {
        LONG(__code_addr__);
        LONG(__load_word_size__);
        LONG(__bss_addr__);
        LONG(__bss_word_size__);
    } > DESC

    /*
     * FLPR executable image.
     * INITPC should be __code_addr__ / em__start = 0x20028000.
     */
    .text ORIGIN(IMEM) :
    {
        __code_addr__ = .;

        KEEP(*(.start))
        KEEP(*(.intvec))

        *(.text .text.*)
        *(.rodata .rodata.*)
        *(.constdata .constdata.*)

        . = ALIGN(4);
        __text_end__ = .;
    } > IMEM

    /*
     * Initialized data runs in DMEM but is loaded immediately after .text
     * in the contiguous FLPR payload image.
     */
    __data_load__ = ALIGN(__text_end__, 4);

    .data ORIGIN(DMEM) : AT(__data_load__)
    {
        __data_addr__ = .;

        *(.sdata .sdata.*)
        *(.data .data.*)

        . = ALIGN(4);
        __data_end__ = .;
    } > DMEM

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
    } > DMEM

    /*
     * Runtime symbols expected by startup.
     * Sizes are word counts.
     */
    __data_size__ = SIZEOF(.data) / 4;
    __bss_size__  = SIZEOF(.bss) / 4;

    __code_size__ = (__text_end__ - __code_addr__) / 4;

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
    __stack_top__      = ORIGIN(DMEM) + LENGTH(DMEM);

    /*
     * Sanity checks.
     */
    ASSERT((__load_word_size__ * 4) == (__load_end__ - __load_start__),
           "FLPR load image is not 4-byte aligned")

    ASSERT((__bss_word_size__ * 4) == SIZEOF(.bss),
           "FLPR bss is not 4-byte aligned")

    ASSERT(__load_end__ <= ORIGIN(IMEM) + LENGTH(IMEM),
           "FLPR load image overflows IMEM")

    ASSERT(__bss_end__ <= ORIGIN(DMEM) + LENGTH(DMEM),
           "FLPR DMEM overflows")

    ASSERT(SIZEOF(.desc) == 16,
           "FLPR descriptor must be exactly 16 bytes")
}
