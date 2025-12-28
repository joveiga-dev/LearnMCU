/* m.ld — Linker Script */

ENTRY(_start)

MEMORY 
{
    RAM (rxw) : ORIGIN = 0x80000000, LENGTH = 4K
}

SECTIONS
{
    .text : {
        _start = .;
        *(.text._start)   /* garante que _start vem primeiro */
        *(.text*)
    } > RAM

    .data : {
        *(.data*)
    } > RAM

    .bss : {
        *(.bss*)
        *(COMMON)
    } > RAM
}
