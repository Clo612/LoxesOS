#include "kernel.h"
#include <stdint.h>

#define KEYBOARD_PORT 0x60

extern uint8_t inb(uint16_t port);

char scancode_to_ascii(uint8_t scancode) {
    switch(scancode) {
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x04: return '3';
        case 0x05: return '4';
        case 0x06: return '5';
        case 0x0E: return '\b';
        case 0x1C: return '\n';
        case 0x39: return ' ';
        default: return '?';
    }
}

char get_key() {
    uint8_t scancode;
    do { scancode = inb(KEYBOARD_PORT); } while(scancode == 0);
    return scancode_to_ascii(scancode);
}
