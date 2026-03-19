; kernel_entry.asm
; Switches to long mode and jumps to kernel C code
BITS 64
global _start

section .text
_start:
    ; Just jump straight to C kernel
    extern kmain
    call kmain

    ; Infinite loop
.hang:
    hlt
    jmp .hang
