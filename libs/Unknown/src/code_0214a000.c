#include "code_0214a000.h"

u32 G2Bg1CntBits2To5Address(void) {
    u32 a;
    u32 b;

    a = *(vu16 *) 0x400000a;
    b = (*(vu32 *) 0x4000000 & 0x7000000) >> 24;
    a &= 0x3c;
    b <<= 16;
    a = (s32) a >> 2;
    return b + 0x6000000 + (a << 14);
}
