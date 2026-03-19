#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

void kprint(const char* str);
void init_scheduler();

#endif
