/* linkcmd.ld -- specialized EMS FLPR payload image
 *
 * Produces one contiguous loadable image:
 *
 *   0x20020000 : 16-byte descriptor
 *   0x20020010 : FLPR code/const/data load image
 *
 * Runtime layout:
 *
 *   IMEM/runtime image : 0x20020010..0x20028000
 *   DMEM/runtime data  : 0x20028000..0x20030000
 *   stack top          : 0x20030000
 *
 * Descriptor layout, four 32-bit words:
 *
 *   word 0: load address, 0x20020010
 *   word 1: load image size in 32-bit words
 *   word 2: bss address
 *   word 3: bss size in 32-bit words
 */

ENTRY(em__start)

MEMORY
{
    DESC : ORIGIN = 0x20020000, LENGTH = 0x00000010
    IMEM : ORIGIN = 0x20020010, LENGTH = 0x00007ff0
    DMEM : ORIGIN = 0x20028000, LENGTH = 0x00008000
}

SECTIONS
{
    __boot_flag__ = 0;

    /*
     * Loader descriptor.
     * Do not source this from C++.
     * The linker emits the actual four words.
     */
    .desc ORIGIN(DESC) :
    {
        LONG(__code_addr__);
        LONG(__load_word_size__);
        LONG(__bss_addr__);
        LONG(__bss_word_size__);
    } > DESC

    /*
     * FLPR code image starts immediately after descriptor.
     * This should be the value copied into VPR INITPC if em__start is first.
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
     * in the contiguous payload image.
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
     * BSS is runtime-only. It is not part of the load image.
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
     * Load image is what follows descriptor and must be copied by M33:
     *   .text/.rodata plus initialized .data load bytes.
     */
    __load_start__     = __code_addr__;
    __load_end__       = __data_load__ + SIZEOF(.data);
    __load_word_size__ = (__load_end__ - __load_start__) / 4;

    /*
     * Descriptor aliases.
     */
    __bss_word_size__ = __bss_size__;

    /*
     * Keep old names available.
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