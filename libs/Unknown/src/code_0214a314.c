#include "code_0214a314.h"

u32 G2Bg0CntBits8To12Address(void) {
    u32 a;
    u32 b;

    a = *(vu16 *) 0x4000008;
    b = (*(vu32 *) 0x4000000 & 0x38000000) >> 27;
    a &= 0x1f00;
    b <<= 16;
    a = (s32) a >> 8;
    return b + 0x6000000 + (a << 11);
}
