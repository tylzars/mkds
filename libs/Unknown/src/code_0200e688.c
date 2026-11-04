#include "code_0200e688.h"

// non-matching: f + 4 is computed into r3 and v - 0x40 into r1 (the original adds 4 to r1 and subtracts 0x40 from
// r2 in place, then tests `ands r1, r1, #1`); everything else is equal
void ThreadInitContext(Unk0200db5c *t, void (*f)(void *), u32 v) {
    t->mUnk_40 = (u32) f + 4;
    t->mUnk_44 = v;
    t->mUnk_38 = v - 0x40;
    t->mUnk_00 = (((u32) f + 4) & 1) != 0 ? 0x3f : 0x1f;
    t->mUnk_04 = 0;
    t->mUnk_08 = 0;
    t->mUnk_0c = 0;
    t->mUnk_10 = 0;
    t->mUnk_14 = 0;
    t->mUnk_18 = 0;
    t->mUnk_1c = 0;
    t->mUnk_20 = 0;
    t->mUnk_24 = 0;
    t->mUnk_28 = 0;
    t->mUnk_2c = 0;
    t->mUnk_30 = 0;
    t->mUnk_34 = 0;
    t->mUnk_3c = 0;
}
