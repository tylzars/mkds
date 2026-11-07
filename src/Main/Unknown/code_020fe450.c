#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void InitIndexLinks(u8 *usedHead, u8 *freeHead, u8 (*entries)[2]) {
    u8 index;
    u8 next;

    *usedHead = 0xff;
    *freeHead = 0;
    index = 0;
    do {
        next = index + 1;
        entries[index][0] = next;
        index = next;
    } while (next < 0x20);
    entries[next - 1][0] = 0xff;
}

void func_020fe46c(void) {
    InitIndexLinks(data_0217bd60, data_0217bd64, data_0217bd80);
}

void func_020fe450(void) {
    InitIndexLinks(data_0217bd68, data_0217bd5c, data_0217bdc0);
}

#pragma thumb off
