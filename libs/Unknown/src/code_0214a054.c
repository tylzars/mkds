#include "code_0214a054.h"

u32 G2Bg2CntBits8To12Address(void) {
    u32 a;
    u32 h;
    u32 b;
    u32 x;

    a = *(vu32 *) 0x4000000 & 0x7;
    h = *(vu16 *) 0x400000c;
    b = ((*(vu32 *) 0x4000000 & 0x38000000) >> 27) << 16;
    x = (h & 0x1f00) >> 8;
    switch (a) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return b + 0x6000000 + (x << 11);
        case 5:
            if (h & 0x80) {
                return (x << 14) + 0x6000000;
            }
            return b + 0x6000000 + (x << 11);
        case 6:
            return 0x6000000;
    }
    return 0;
}

u32 G2sBg2CntBits8To12Address(void) {
    u32 a;
    u32 h;
    u32 x;

    a = *(vu32 *) 0x4001000 & 0x7;
    h = *(vu16 *) 0x400100c;
    x = (h & 0x1f00) >> 8;
    switch (a) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return (x << 11) + 0x6200000;
        case 5:
            if (h & 0x80) {
                return (x << 14) + 0x6200000;
            }
            return (x << 11) + 0x6200000;
        case 6:
            return 0;
    }
    return 0;
}

u32 G2Bg3CntBits8To12Address(void) {
    u32 a;
    u32 h;
    u32 b;
    u32 x;

    a = *(vu32 *) 0x4000000 & 0x7;
    h = *(vu16 *) 0x400000e;
    b = ((*(vu32 *) 0x4000000 & 0x38000000) >> 27) << 16;
    x = (h & 0x1f00) >> 8;
    switch (a) {
        case 0:
        case 1:
        case 2:
            return b + 0x6000000 + (x << 11);
        case 3:
        case 4:
        case 5:
            if (h & 0x80) {
                return (x << 14) + 0x6000000;
            }
            return b + 0x6000000 + (x << 11);
        case 6:
            return 0;
    }
    return 0;
}

u32 G2sBg3CntBits8To12Address(void) {
    u32 a;
    u32 h;
    u32 x;

    a = *(vu32 *) 0x4001000 & 0x7;
    h = *(vu16 *) 0x400100e;
    x = (h & 0x1f00) >> 8;
    switch (a) {
        case 0:
        case 1:
        case 2:
            return (x << 11) + 0x6200000;
        case 3:
        case 4:
        case 5:
            if (h & 0x80) {
                return (x << 14) + 0x6200000;
            }
            return (x << 11) + 0x6200000;
        case 6:
            return 0;
    }
    return 0;
}

u32 G2Bg0CntBits2To5Address(void) {
    u32 a;
    u32 b;

    a = *(vu16 *) 0x4000008;
    b = (*(vu32 *) 0x4000000 & 0x7000000) >> 24;
    a &= 0x3c;
    b <<= 16;
    a = (s32) a >> 2;
    return b + 0x6000000 + (a << 14);
}
