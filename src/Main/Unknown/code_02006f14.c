#include "Main/Unknown/code_02006f14.h"
#include "Main/Unknown/code_020070b0.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on

s32 func_02006fdc(s32 a) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((a >> i) & 1) != 0) {
            return i;
        }
    }
    return -1;
}

u32 func_02006f98(s32 a) {
    s32 v1;
    s32 v2;
    v1 = func_020070e4();
    v2 = a / v1 + ((a % v1) != 0 ? 1 : 0);
    return ((v2 >> 5) + ((v2 & 0x1f) != 0 ? 1 : 0)) << 2;
}

s32 func_02006f50(u32 a, s32 b, s32 *c, s32 *d) {
    Unk0216f3dc *v1;
    Unk0200628c *v2;
    v1 = func_020070b8();
    v2 = &v1->mUnk_1d4[b].mUnk_24;
    if (v1->mUnk_000.mUnk_00 == 4 && v1->mUnk_000.mUnk_14 == a) {
        *d = v2->mUnk_04;
        *c = v2->mUnk_10;
        return 1;
    }
    return 0;
}

u32 func_02006f14(s32 a, s32 b) {
    switch (func_020070b8()->mUnk_000.mUnk_00) {
        case 4:
        case 6:
            return 0;
    }
    func_020070c0(a - 0xe);
    func_020070cc(b - 0xe);
    return 1;
}

#pragma thumb off
