#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02126138(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f0->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    p = &data_0217d3f0->mUnk_2098[4];
    p->mUnk_18(p, 0xe);
    func_0212583c(&data_0217d3f0->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1,
                  (void *) a);
    func_021257d8(&data_0217d3f0->mUnk_2178[4], 0, 0, data_0215d044[4][0] << 3, data_0215d044[4][1] << 3, 2, 0x480, 1,
                  (void *) b);
    func_02127734();
    data_0217d3f0->mUnk_2204[2] = 1;
    data_0217d3f0->mUnk_2204[4] = 1;
    func_02126700();
    data_0217d3f0->mUnk_28 = 1;
    data_0217d3f0->mUnk_2c = 0;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_20[0] = 0;
    data_0217d3f0->mUnk_20[1] = 0;
    data_0217d3f0->mUnk_2074[0] = c;
    data_0217d3f0->mUnk_2074[1] = d;
    data_0217d3f0->mUnk_3c = e;
    data_0217d3f0->mUnk_40 = f;
}

void func_0212611c(void *a, void *b, void *c, s32 d) {
    func_02125fd4((u32) a, (u32) b, (u32) c, d, 1, 1, 1, 0);
}

void func_02125fd4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f0->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    p = &data_0217d3f0->mUnk_2098[5];
    p->mUnk_18(p, 0xe);
    p = &data_0217d3f0->mUnk_2098[6];
    p->mUnk_18(p, 0xd);
    func_0212583c(&data_0217d3f0->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1,
                  (void *) a);
    func_021257d8(&data_0217d3f0->mUnk_2178[5], 0, 0, data_0215d044[5][0] << 3, data_0215d044[5][1] << 3, 2, 0x480, 1,
                  (void *) b);
    func_021257d8(&data_0217d3f0->mUnk_2178[6], 0, 0, data_0215d044[6][0] << 3, data_0215d044[6][1] << 3, 2, 0x480, 1,
                  (void *) c);
    func_02127734();
    data_0217d3f0->mUnk_2204[2] = 1;
    data_0217d3f0->mUnk_2204[5] = 1;
    data_0217d3f0->mUnk_2204[6] = 1;
    func_02126700();
    data_0217d3f0->mUnk_28 = 2;
    data_0217d3f0->mUnk_2c = d;
    data_0217d3f0->mUnk_30 = 0;
    data_0217d3f0->mUnk_20[0] = 0;
    data_0217d3f0->mUnk_20[1] = 0;
    data_0217d3f0->mUnk_2074[0] = e;
    data_0217d3f0->mUnk_2074[1] = f;
    data_0217d3f0->mUnk_3c = g;
    data_0217d3f0->mUnk_40 = h;
}

void func_02125fc0(void) {
    data_0217d3f0->mUnk_34 = 0;
    data_0217d3f0->mUnk_38 = 1;
}

s32 func_02125fa4(void) {
    s32 r;

    r = 0;
    if (data_0217d3f0->mUnk_00 == 2 && data_0217d3f0->mUnk_38 == 0) {
        r = 1;
    }
    return r;
}

s32 func_02125f88(void) {
    s32 r;

    r = 0;
    if (data_0217d3f0->mUnk_00 == 0 && data_0217d3f0->mUnk_34 == 0) {
        r = 1;
    }
    return r;
}

s32 func_02125f6c(void) {
    s32 r;

    r = 0;
    if (data_0217d3f0->mUnk_08 == 1 && data_0217d3f0->mUnk_00 == 2) {
        r = 1;
    }
    return r;
}

#pragma thumb off
