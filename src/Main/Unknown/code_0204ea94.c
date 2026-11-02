#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0214d000.h"

#pragma thumb on

void func_0204eca0(void) {
    data_0217aa00->mUnk_000c = 0x2d;
    data_0217aa00->mUnk_0010 = 1;
    func_02006974();
    data_0217aa00->mUnk_0454 &= ~0x200;
    data_0217aa00->mUnk_0010 = 0;
}

void func_0204ec28(u32 a, Unk0217aa00_24_50 *b) {
    data_0217aa00->mUnk_1e48[a].mUnk_00 = b->mUnk_0e.mUnk_07_1;
    data_0217aa00->mUnk_1e48[a].mUnk_01 = b->mUnk_18_0;
    data_0217aa00->mUnk_1e48[a].mUnk_02 = func_02046828((u8) b->mUnk_18_4);
    data_0217aa00->mUnk_1e48[a].mUnk_03 = b->mUnk_18_9;
    data_0217aa00->mUnk_1e48[a].mUnk_04 = b->mUnk_18_16;
    data_0217aa00->mUnk_1e48[a].mUnk_06 = b->mUnk_18_22;
}

static inline u32 func_0204eb08_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

s32 func_0204ebb8(u8 a, void *b, u8 *c, u8 *d, u8 *e, u8 *f, u8 *g, u16 *h) {
    if (func_0204ff14(a, b) == 0) {
        return 0;
    }
    *c = data_0217aa00->mUnk_1e48[a].mUnk_00;
    *d = data_0217aa00->mUnk_1e48[a].mUnk_01;
    *e = data_0217aa00->mUnk_1e48[a].mUnk_02;
    *f = data_0217aa00->mUnk_1e48[a].mUnk_03;
    *g = data_0217aa00->mUnk_1e48[a].mUnk_04;
    *h = data_0217aa00->mUnk_1e48[a].mUnk_06;
    return 1;
}

s32 func_0204eb08(void *a) {
    s32 r;
    u8 i;
    u8 m;
    u32 v;

    r = 0;
    if (func_0204eb08_inline() == 1) {
        if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
            v = data_0217aa00->mUnk_1699;
        } else {
            v = data_0217aa00->mUnk_0044.mUnk_40;
        }
    } else {
        v = 0;
    }
    if (v != 1) {
        return 0;
    }
    if (func_0204eb08_inline() != 1) {
        return 0;
    }
    i = 1;
    m = data_0217aa00->mUnk_0044.mUnk_43;
    do {
        if ((m & (1 << i)) != 0) {
            func_0214d1fc(&data_0217aa00->mUnk_045c[i], a, 0x14);
            r = 1;
            break;
        }
        i = i + 1;
    } while (i < 8);
    return r;
}

void func_0204ead0(u16 a, s32 b) {
    s32 v;

    v = b;
    data_0217aa00->mUnk_000c = 0x2e;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02006d3c(a, &v, 4, (void (*)(void)) func_0204ea94) == 0) {
        data_0217aa00->mUnk_0010 = 0;
    }
}

void func_0204ea94(Unk0216f3dc_9c *a) {
    if (a->mUnk_00 == 10) {
        if (a->mUnk_04 == 11) {
            data_0217aa00->mUnk_0010 = 0;
            return;
        }
        func_02050e60(8);
    } else {
        func_02050e60(8);
    }
}

#pragma thumb off
