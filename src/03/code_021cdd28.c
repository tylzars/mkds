#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"

#include "03/code_021ce0f0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1770.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"

u32 func_ov003_021ce00c(void) {
    if (data_ov003_021da27c->mTask != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021cdf98(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[4], 0, (u32 *) &w, &h);
    w -= 8;
    if (w > data_ov003_021d66a8[3].mUnk_00) {
        for (i = 4; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[3].mUnk_00;
    for (i = 4; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021cdf00);
}

void func_ov003_021cdf00(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[3], 0, (u32 *) &w, &h);
    w -= 8;
    if (w > data_ov003_021d66a8[2].mUnk_00) {
        for (i = 3; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[2].mUnk_00;
    for (i = 3; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021cde68);
}

void func_ov003_021cde68(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[2], 0, (u32 *) &w, &h);
    w -= 8;
    if (w > data_ov003_021d66a8[1].mUnk_00) {
        for (i = 2; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[1].mUnk_00;
    for (i = 2; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021cddd0);
}

void func_ov003_021cddd0(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[1], 0, (u32 *) &w, &h);
    w -= 8;
    if (w > data_ov003_021d66a8[0].mUnk_00) {
        for (i = 1; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[0].mUnk_00;
    for (i = 1; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021cdd48);
}

void func_ov003_021cdd48(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[0], 0, (u32 *) &w, &h);
    w -= 8;
    for (i = 0; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    if (w <= 0x1d6 && w >= 0x100) {
        func_ov003_021d34c8(0, (u32) a);
        for (i = 0; i < 5; i++) {
            func_ov003_021d197c(data_ov003_021da27c->mUnk_00[i]);
        }
        func_ov003_021d2808(&data_ov003_021da27c);
    }
}

u32 func_ov003_021cdd28(void) {
    if (data_ov003_021da27c == 0) {
        return 1;
    }
    if (data_ov003_021da27c->mUnk_18 == 0) {
        return 1;
    }
    return 0;
}
