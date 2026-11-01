#include "Main/Unknown/code_0209af64.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"

s32 func_0209af64(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

s16 func_0209af80(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

void func_0209af98(Unk0209af98 *p) {
    s32 i;
    Unk0209a7dc *o;
    Unk020f41c4_B *r;

    if (p == 0) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != 0; i++) {
        o->mUnk_0d0.mUnk_00 = 0;
        o->mUnk_0d0.mUnk_0c = 0;
        o->mUnk_0d0.mUnk_10 = 0x1c7;
        o->mUnk_0d0.mUnk_14 = 0;
        o->mUnk_0d0.mUnk_18 = 0xe39;
        o->mUnk_0d0.mUnk_1c = 0;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        o->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
        o->mUnk_114 = 0;
    }
}

void func_0209b088(void *a, Unk0209a7dc *b) {
    s32 w;
    s32 f0[9];
    s32 f1[9];

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_020e6d88(&b->mUnk_000.mUnk_28.mUnk_0c);
    func_01ff9048(0x19, func_020e6bd0(&b->mUnk_000.mUnk_04), 0xc);
    if (b->mUnk_0a2 != 0) {
        func_02146d60(f0, data_0215d4b4[(b->mUnk_0a2 >> 4) * 2], data_0215d4b4[(b->mUnk_0a2 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, f0, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_000.mUnk_1c, 3);
    func_0209b688(data_usa_0217b158, (u16) (b->mUnk_0a8 >> 12));
    func_0209bbd0(a, data_usa_0217b158);
    func_0209bb2c(a, data_usa_0217b158, b);
    func_02146d60(f1, data_0215d4b4[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2],
                  data_0215d4b4[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, f1, 9);
    func_0209b688(data_usa_0217b154, (u16) (b->mUnk_0ac >> 12));
    func_0209bbd0(a, data_usa_0217b154);
    func_0209bb2c(a, data_usa_0217b154, b);
}
