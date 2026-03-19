#!/bin/bash
set -e

mkdir -p build/boot/grub
cp -r boot/* build/boot/

# Compile kernel
nasm -f elf64 src/kernel_entry.asm -o build/kernel_entry.o
gcc -ffreestanding -c src/kernel.c -Iinclude -o build/kernel.o -O2 -Wall -Wextra
ld -n -Ttext 0x1000 build/kernel_entry.o build/kernel.o -o build/boot/kernel.bin

# Create ISO
grub-mkrescue -o BC-OS-Phase1.iso build
echo "ISO created: BC-OS-Phase1.iso"
