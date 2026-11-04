#include "code_02149e90.h"

u32 G2Bg2CntBits2To5Address(void) {
    s32 a;
    u32 b;

    a = *(vu32 *) 0x4000000 & 0x7;
    b = *(vu16 *) 0x400000c;
    if (a < 5 || !(b & 0x80)) {
        return (((*(vu32 *) 0x4000000 & 0x7000000) >> 24) << 16) + 0x6000000 + (((b & 0x3c) >> 2) << 14);
    }
    return 0;
}

u32 G2sBg2CntBits2To5Address(void) {
    s32 a;
    u32 b;

    a = *(vu32 *) 0x4001000 & 0x7;
    b = *(vu16 *) 0x400100c;
    if (a < 5 || !(b & 0x80)) {
        return (((b & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}

u32 G2Bg3CntBits2To5Address(void) {
    s32 a;
    u32 b;

    a = *(vu32 *) 0x4000000 & 0x7;
    b = *(vu16 *) 0x400000e;
    if (a < 3 || (a < 6 && !(b & 0x80))) {
        return (((*(vu32 *) 0x4000000 & 0x7000000) >> 24) << 16) + 0x6000000 + (((b & 0x3c) >> 2) << 14);
    }
    return 0;
}

u32 G2sBg3CntBits2To5Address(void) {
    s32 a;
    u32 b;

    a = *(vu32 *) 0x4001000 & 0x7;
    b = *(vu16 *) 0x400100e;
    if (a < 3 || (a < 6 && !(b & 0x80))) {
        return (((b & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}
