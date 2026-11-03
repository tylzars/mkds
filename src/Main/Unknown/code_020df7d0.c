#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_020df7d0.h"

#include "Main/Unknown/code_020df7d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020df85c.h"

void func_020df85c(Unk020df85c *p0) {
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_0215877c))) + 0)))));
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_02158780))) + 0)))));
}

void func_020df83c(Unk020df6c8 *a) {
    if (a->mUnk_00.mUnk_80.mUnk_04 >= a->mUnk_a0) {
        a->mUnk_00.mUnk_80.mUnk_10 = 0;
        a->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u8 func_020df7d8(Unk020df6c8 *a, Unk020dea50_1 *b, void *c, u8 *d) {
    u32 m;

    m = (1 << b->mUnk_74) & 0xff;
    if ((a->mUnk_e4 & m) == 0) {
        if (func_020d26f8(&a->mUnk_00, (Unk0206bcb0 *) b) != 0) {
            a->mUnk_00.mUnk_78 |= data_02158778;
            a->mUnk_e4 |= m;
        }
    }
    return *d;
}

u32 func_020df7d0(u32 p0, u32 p1, u32 p2, u32 p3) {
    return ((u32) * (const u8 *) ((u8 *) p3 + 0));
}
