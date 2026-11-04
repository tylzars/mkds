#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

#pragma thumb on

u16 func_020ae5c4(void *a) {
    u16 *p;
    u16 v;

    p = (u16 *) ((u8 *) a + 0x402);
    v = *p;
    *p = v + 1;
    return v;
}

s32 func_020ae584(s32 a) {
    s32 v1[15] = {4, 8, 10, 13, 12, 12, 12, 4, -4, -8, -12, -16, -16, -24, -40};

    if (a < 0) {
        return 0;
    }
    if (a >= 15) {
        return -40;
    }
    return v1[a];
}

#pragma thumb off

s16 func_020ae564(s32 a) {
    return data_0215d4b4[(a >> 4) * 2 + 1];
}

s32 func_020ae554(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

s32 func_020ae54c(s32 a) {
    return a >> 12;
}

#pragma thumb on

s16 func_020ae4c0(s32 a, s16 b, s16 c, s32 d, s32 e) {
    s32 t;
    s32 v1;
    float f;

    if (d <= 0) {
        return b;
    }
    if (d >= e) {
        return c;
    }
    switch (a) {
        case 0:
            return b + d * (c - b) / e;
        case 1:
            t = func_020ae564((d << 15) / e);
            v1 = c - b;
            if (v1 > 0) {
                f = 0.5f + (float) (v1 << 12);
            } else {
                f = (float) (v1 << 12) - 0.5f;
            }
            return b + func_020ae54c(func_020ae554((s32) f, 0x1000 - t)) / 2;
    }
}

s16 func_020ae488(s32 a) {
    if (a < 0) {
        return 0;
    }
    if (a < 3) {
        return a * -3;
    }
    if (a < 7) {
        return -9;
    }
    if (a < 10) {
        return (a - 7) * 3 - 9;
    }
    return 0;
}

#pragma thumb off

u16 func_020ae474(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020ae458(u32 a, u32 b) {
    return func_020ae474(&data_02175628[a], b);
}

u16 func_020ae444(Unk02175628 *a, u32 b) {
    return a->mRepeatBits & b;
}

u16 func_020ae428(u32 a, u32 b) {
    return func_020ae444(&data_02175628[a], b);
}

