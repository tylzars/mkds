#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b4000.h"

s32 func_020b1bf8(Unk020b1bf8 *a, Unk020b1bf8 *b, Unk020b1a34_0c *c) {
    s32 x;
    s32 y;
    s32 d;
    s32 r;
    s32 m;
    s32 s;
    s32 n;

    x = (a->mUnk_00 * 60 + a->mUnk_04) * 1000 + a->mUnk_08;
    y = (b->mUnk_00 * 60 + b->mUnk_04) * 1000 + b->mUnk_08;
    r = x >= y;
    if (r != 0) {
        d = x - y;
    } else {
        d = y - x;
    }
    m = d / 60000;
    s = (d - m * 60000) / 1000;
    n = d % 1000;
    if (m < 100) {
        c->mUnk_02 = m;
        c->mUnk_03 = s;
        c->mUnk_00 = n;
    } else {
        c->mUnk_02 = 99;
        c->mUnk_03 = 59;
        c->mUnk_00 = 999;
    }
    return r;
}

// non-matching: the original keeps `add r0, r0, #0` between the load of member 0x08 and the `cmp r0, #1` of the range
// test (4 bytes more); with that add kept the rest is identical
void func_020b1a34(void) {
    Unk020b1a34_0c a;
    Unk020b1a34_0c b;
    Unk020b1a34_0c c;
    Unk020b1bf8 t[2];
    Unk020ae7c4 w;
    u8 i;
    u8 j;

    if ((u32) data_021759c0->mUnk_08 <= 1) {
        data_0217b350->mUnk_8dc = 1;
    }
    if (data_0217b350->mUnk_8e4 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        t[i].mUnk_00 = 0;
        t[i].mUnk_04 = 0;
        t[i].mUnk_08 = 0;
    }
    for (j = 1; j <= func_020b4d2c(); j++) {
        if (data_021759c0->mUnk_08 == 1) {
            func_0214d1fc(&data_021759c0->mUnk_3ec[j - 1], &a, 4);
        }
        t[0].mUnk_00 += a.mUnk_02;
        t[0].mUnk_04 += a.mUnk_03;
        t[0].mUnk_08 += a.mUnk_00;
        func_0203c778(func_020b4d9c(), j, &b.mUnk_02, &b.mUnk_03, &b.mUnk_00);
        t[1].mUnk_00 += b.mUnk_02;
        t[1].mUnk_04 += b.mUnk_03;
        t[1].mUnk_08 += b.mUnk_00;
    }
    data_0217b350->mUnk_8e8 = func_020b1bf8(&t[1], &t[0], &c);
    func_020ae7c4(c.mUnk_02, c.mUnk_03, c.mUnk_00, &w);
    data_0217b350->mUnk_8ec = w;
}
