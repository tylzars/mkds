#include "Main/Unknown/code_0204f5e4.h"

#pragma thumb on

void func_0204f5e4(void) {
    int v1;
    int v2;
    int v3;
    u32 v4;
    u32 v5;
    v4 = ((int) 0xe0000000u);
    v5 = ((u32) 0xdfffffffu);
    v2 = (int) data_0217aa00 + 0x16a0;
    v1 = 0;
    v3 = v2;
    do {
        *(u8 *) (v3 + 0x34) = 0;
        *(u32 *) (v3 + 0x74) = 0;
        *(u32 *) (v3 + 0x78) = 0;
        *(u32 *) (v3 + 0x84) = *(u32 *) (v3 + 0x84) & v5;
        *(u32 *) (v3 + 0x84) = *(u32 *) (v3 + 0x84) & v4;
        v3 = v3 + 0x88;
        v1 = v1 + 1;
    } while (v1 < 0xc);
    *(u16 *) (v2 + 0x668) = 0xc;
}

#pragma thumb off
