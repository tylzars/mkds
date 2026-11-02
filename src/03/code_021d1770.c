#include "03/code_021d1770.h"

void func_ov003_021d1770(Unk021d1770 *a, int b, u32 *c, s32 *d) {
    Unk021d1770_08 *t;

    t = a->mUnk_08;
    *c = (t[b].mUnk_00 & 0x01ff0000) >> 0x10;
    *d = t[b].mUnk_00 & 0xff;
}
