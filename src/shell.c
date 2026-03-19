#include "kernel.h"

void shell() {
    char buffer[128];
    int pos = 0;
    kprint("BC-OS> ");

    while(1) {
        char c = get_key();
        if(c == '\n') {
            buffer[pos] = 0;
            kprint("\n");

            if(strcmp(buffer, "help") == 0) {
                kprint("Commands: help, echo, cls\n");
            } else if(strncmp(buffer, "echo ", 5) == 0) {
                kprint(buffer + 5);
                kprint("\n");
            } else if(strcmp(buffer, "cls") == 0) {
                // clear screen
                for(int i=0;i<80*25;i++) ((uint16_t*)VGA_ADDRESS)[i] = 0;
            } else {
                kprint("Unknown command\n");
            }

            pos = 0;
            kprint("BC-OS> ");
        } else {
            buffer[pos++] = c;
        }
    }
}
