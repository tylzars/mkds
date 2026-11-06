#include "ITCM/code_01ff9320.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9598.h"
#include "code_02010c84.h"
#include "code_02147cd8.h"

#pragma opt_arithtransformation off

// The table below is initialized data kept in .text ahead of the code (the original has it at 0x01ff9300, right
// before func_01ff9320); 1.2 puts initialized non-const data in the section a `#pragma section` names.
#pragma define_section ITCM ".text"                                                                                    \
                            ".bss" abs32 RWX
#pragma section ITCM begin

Unk01ff9320_Fn data_01ff9300[8] = {
    (Unk01ff9320_Fn) func_01ff9828, (Unk01ff9320_Fn) func_01ff974c, (Unk01ff9320_Fn) func_01ff96cc,
    (Unk01ff9320_Fn) func_01ff9684, (Unk01ff9320_Fn) func_01ff9598, (Unk01ff9320_Fn) func_01ff94d4,
    (Unk01ff9320_Fn) func_01ff9490, (Unk01ff9320_Fn) func_01ff946c,
};

#pragma section ITCM end

void func_01ff94d4(s32 *o, const Unk0201290c_1c *v1) {
    s32 a;
    s32 b;
    s32 t;

    a = v1->mUnk_2c << 12;
    b = v1->mUnk_2e << 12;
    FX_DivAsync(b, a);
    o[0] = v1->mUnk_20[1];
    o[5] = v1->mUnk_20[1];
    o[1] = (-v1->mUnk_20[0] * FX_GetDivResult()) >> 12;
    FX_DivAsync(a, b);
    t = -(v1->mUnk_20[0] + v1->mUnk_20[1]);
    o[12] = (v1->mUnk_2c * (t + 0x1000)) << 3;
    o[13] = (v1->mUnk_2e * (v1->mUnk_20[0] - v1->mUnk_20[1] + 0x1000)) << 3;
    o[4] = (v1->mUnk_20[0] * FX_GetDivResult()) >> 12;
}

void func_01ff9490(s32 *o, const Unk0201290c_1c *v1) {
    s32 t;

    o[0] = v1->mUnk_18[0];
    o[5] = v1->mUnk_18[1];
    o[1] = 0;
    o[12] = 0;
    t = -(v1->mUnk_18[1] << 1);
    o[13] = (v1->mUnk_2e * (t + 0x2000)) << 3;
    o[4] = 0;
}

void func_01ff946c(s32 *o) {
    o[0] = 0x1000;
    o[1] = 0;
    o[4] = 0;
    o[5] = 0x1000;
    o[12] = 0;
    o[13] = 0;
}

void func_01ff9320(Unk0201290c_1c *p) {
    Unk01ff9320_buf b;

    if (p->mUnk_00 & 8) {
        b.mUnk_00 = 0x101610;
    } else {
        b.mUnk_00 = 0x101810;
    }
    b.mUnk_04 = 3;
    b.mUnk_48 = 2;
    b.mUnk_08[14] = 0;
    b.mUnk_08[11] = 0;
    b.mUnk_08[10] = 0;
    b.mUnk_08[9] = 0;
    b.mUnk_08[8] = 0;
    b.mUnk_08[7] = 0;
    b.mUnk_08[6] = 0;
    b.mUnk_08[3] = 0;
    b.mUnk_08[2] = 0;
    b.mUnk_08[15] = 0x1000;
    data_01ff9300[p->mUnk_00 & 7](b.mUnk_08, p);
    if (p->mUnk_30 != 0x1000) {
        b.mUnk_08[0] = ((s64) p->mUnk_30 * b.mUnk_08[0]) >> 12;
        b.mUnk_08[1] = ((s64) p->mUnk_30 * b.mUnk_08[1]) >> 12;
        b.mUnk_08[12] = ((s64) p->mUnk_30 * b.mUnk_08[12]) >> 12;
    }
    if (p->mUnk_34 != 0x1000) {
        b.mUnk_08[4] = ((s64) p->mUnk_34 * b.mUnk_08[4]) >> 12;
        b.mUnk_08[5] = ((s64) p->mUnk_34 * b.mUnk_08[5]) >> 12;
        b.mUnk_08[13] = ((s64) p->mUnk_34 * b.mUnk_08[13]) >> 12;
    }
    func_01ff9048(b.mUnk_00, (u32 *) &b + 1, 0x12);
}
