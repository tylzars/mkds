#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "code_020222ec.h"
#include "code_0214c778.h"

u16 func_020d13f8(void) {
    if (data_0217b4ac->mUnk_00 < 0x7fffffff) {
        data_0217b4ac->mUnk_00++;
    }
    if (data_0217b4ac->mUnk_00 == 0x30c) {
        func_0212b1a8();
    }
    return *(vu16 *) 0x4000304;
}

void func_020d12e0(void) {
    Unk020d029c *b;
    s32 i;
    Unk020224e0_o *e;
    Unk0217b4ac *a;
    Unk020224e0_c *c;
    u32 *w;
    s32 q[2];

    data_0217b4ac->mUnk_10.mUnk_400 = 0;
    a = data_0217b4ac;
    if (a->mUnk_00 < 0x21c) {
        b = &a->mUnk_10;
        i = b->mUnk_400;
        c = a->mUnk_0c;
        q[0] = 0x80000;
        q[1] = 0x60000;
        e = &b->mUnk_000[i];
        b->mUnk_400 += func_020224e0(e, 0x80 - i, c, 0, q, 0, 1);
        w = (u32 *) e;
        for (; i < b->mUnk_400; i++) {
            w[0] = (w[0] & ~0xc00) | 0x400;
            w[1] = (w[1] & ~0xc00) | 0x400;
            w += 2;
        }
    }
    func_0200ee74(&data_0217b4ac->mUnk_10, 0x400);
    func_0214cc04(3, &data_0217b4ac->mUnk_10.mUnk_000[data_0217b4ac->mUnk_10.mUnk_400], 0xc0,
                  (0x80 - data_0217b4ac->mUnk_10.mUnk_400) << 3);
}
