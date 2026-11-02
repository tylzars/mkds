#include "Main/Unknown/code_0202de00.h"

#pragma thumb on

void func_0202de00(Unk02174e14 *a, s16 (*b)[4], void *c, s32 d, s32 e, s32 f, Unk0202de00_g *g) {
    u16 s[10];
    u16 t[11];
    Unk02174e14_00 *h;
    h = &a->mUnk_038;
    func_0212426c(0, b[0][0], a->mUnk_000.mUnk_14, GetBmgEntry(a->mUnk_058, func_02025d8c(f)), a->mUnk_000.mUnk_0c,
                  a->mUnk_000.mUnk_18);
    func_02025cd0((short *) s, g->mUnk_02, g->mUnk_03, g->mUnk_00);
    func_02124224(0, b[1][0], a->mUnk_000.mUnk_14, s, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_18, 7);
    func_0214cffc(c, t, 0x14);
    t[10] = 0;
    func_0212426c(0, b[2][0], a->mUnk_000.mUnk_14, t, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_18);
    func_0212463c(d, h->mUnk_08, a->mUnk_038.mUnk_00, h->mUnk_04, h->mUnk_0c, 0, b[0][3], a->mUnk_000.mUnk_08,
                  a->mUnk_000.mUnk_0c);
    func_021171a0(e, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, b[1][3],
                  func_02124a68(b[1][3], a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c), 0);
}

#pragma thumb off
