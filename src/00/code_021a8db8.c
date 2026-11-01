#include "00/code_021a8db8.h"

void *func_ov000_021a8db8(u32 a) {
    u32 b = a + 4;
    u32 *c = data_ov000_021b6014(0, b);
    if (c != 0) {
        *c = b;
        c++;
    }
    return c;
}

s32 func_ov000_021a8dd8(Unk021a6fa8 *a, s32 b, u32 c) {
    if (a == 0) {
        return -1;
    }
    switch (b) {
        case 3:
            if (a->mUnk_72 == 1) {
                return 0;
            }
            return 4;
        case 4:
            if (c & 4) {
                a->mUnk_72 = 0;
            } else {
                a->mUnk_72 = 1;
            }
            break;
    }
    return 0;
}

s32 func_ov000_021a8e18(Unk021a6fa8 *a, Unk021a8e18 *b, s32 param_3) {
    u16 c;
    u32 d;
    s32 e = func_ov000_021a7534(a, &c, &d);
    if (e >= 0) {
        b->mUnk_02 = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
        b->mUnk_04 = ((d << 24) & 0xff000000) | (((d << 8) & 0xff0000) | (((d >> 24) & 0xff) | ((d >> 8) & 0xff00)));
    }
    return e;
}
