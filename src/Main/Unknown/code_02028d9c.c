#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02078580.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0201e000.h"

#include "Main/Unknown/code_0214d000.h"
#include "code_0201ea30.h"
#include "code_0214d018.h"

void *func_02028f08(s32 a, Unk0201ea30 *b) {
    return func_0201ea30(b, a);
}

#pragma thumb on

void func_02028ec0(s32 a, s32 b, s32 c, Unk02174e14_00 *d) {
    Unk0201ea84 *p = func_02028f08(a, d->mUnk_0c);
    Unk0201ea84 *q = func_02028f08(b, d->mUnk_0c);
    d->mUnk_18[a].mUnk_04 = (100 - c) * (q->mUnk_00_0 - p->mUnk_00_0) / 100;
}

#pragma thumb off

#pragma thumb on

void func_02028e38(void) {
    int v1;
    Unk02174e14_00 *v3;
    short *v2;
    v1 = func_020280dc();
    if (v1 == 0) {
        v2 = func_02078b04(gSelectKart->mUnk_0a8, gSelectKart->mUnk_0a4);
        v3 = (Unk02174e14_00 *) &gSelectKart->mUnk_064;
        func_02028ec0(10, 0x10, *v2, v3);
        func_02028ec0(9, 0xf, v2[1], v3);
        func_02028ec0(8, 0xe, v2[2], v3);
        func_02028ec0(7, 0xd, v2[3], v3);
        func_02028ec0(6, 0xc, v2[4], v3);
        func_02028ec0(5, 0xb, v2[5], v3);
    }
}

#pragma thumb off

void func_02028e14(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MemFillWordsByBlock(v, a, c);
}

void func_02028e00(void *a, u32 b) {
    func_02028e14(a, 0, b);
}

u16 func_02028dd4(void) {
    int v1;
    if (data_0217aa00->mUnk_0000 == 2) {
        v1 = data_0217aa00->mUnk_0432;
    } else {
        v1 = 0;
    }
    return v1;
}

u32 func_02028db8(u32 p0) {
    return ((u32) data_0217aa00->mUnk_1e52[p0].mUnk_00);
}

u32 func_02028d9c(void) {
    u32 value0;
    value0 = (u32) func_02028dd4();
    value0 = (u32) func_02028db8(value0);
    return value0;
}
