#include "kernel.h"
#include "scheduler.c"

volatile uint16_t* vga = (uint16_t*)VGA_ADDRESS;

void kmain() {
    kprint("Booting BC-OS Kernel Phase 1...\n");

    init_scheduler(); // start basic task switching

    while(1) {
        __asm__ __volatile__("hlt");
    }
}

void kprint(const char* str) {
    static int row = 0;
    static int col = 0;

    while (*str) {
        if (*str == '\n') {
            row++;
            col = 0;
        } else {
            vga[row * VGA_WIDTH + col] = (uint16_t)(*str | 0x0F << 8);
            col++;
        }
        str++;
    }
}

#include "kernel.h"
#include "scheduler.c"
#include "keyboard.c"
#include "shell.c"

void kmain() {
    kprint("Booting BC-OS Phase 2...\n");

    shell(); // now interactive
}
