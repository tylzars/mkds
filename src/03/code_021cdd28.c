#include "03/code_021cdd28.h"

#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1770.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021ce110.h"
#include "03/code_021d1c18.h"
#include "03/code_021cdcb8.h"
#include "03/code_021d1970.h"
#include "03/code_021d3000.h"

void func_ov003_021ce0f0(u32 task) {
    func_ov003_021d34c8(0, task);
    data_ov003_021da27c->mTask = 0;
}

void func_ov003_021ce0c4(void) {
    data_ov003_021da27c->mUnk_18 = 1;
    data_ov003_021da27c->mTask = func_ov003_021d3544(0, func_ov003_021cdf98, NULL, 0x78);
}

void func_ov003_021ce024(u32 a) {
    s32 i;
    for (i = 0; i < 5; i += 2) {
        func_ov003_021d1c3c(1, data_ov003_021d6688[a][i], func_ov003_021d1974(data_ov003_021da27c->mUnk_00[i], 0));
        func_ov003_021d1790(data_ov003_021da27c->mUnk_00[i], -1, 0);
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, data_ov003_021d66a8[i].mUnk_00,
                            data_ov003_021d66a8[i].mUnk_02);
        func_ov003_021d1890(data_ov003_021da27c->mUnk_00[i], -1, 0, data_ov003_021d6698[a][i]);
    }
    func_ov003_021cdcf0(a);
}

u32 func_ov003_021ce00c(void) {
    if (data_ov003_021da27c->mTask != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021cdf98(TaskEntry *a) {
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

void func_ov003_021cdf00(TaskEntry *a) {
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

void func_ov003_021cde68(TaskEntry *a) {
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

void func_ov003_021cddd0(TaskEntry *a) {
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

void func_ov003_021cdd48(TaskEntry *a) {
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
        FreeExpHeapBlockAndClearPointer(&data_ov003_021da27c);
    }
}

u32 func_ov003_021cdd28(void) {
    if (data_ov003_021da27c == NULL) {
        return 1;
    }
    if (data_ov003_021da27c->mUnk_18 == 0) {
        return 1;
    }
    return 0;
}
