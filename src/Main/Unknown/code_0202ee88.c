#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/code_0202f080.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202edfc.h"

#pragma optimize_for_size on

#pragma thumb on

// non-matching: original loads mUnk_02e << 6 into r5 before mUnk_008 into r4 and ends with adds r1, r4, r5 (3 words
// differ, same size)
void func_0202ee88(void) {
    Unk02174e48 *p = data_02174e48;
    s32 v1 = p->mUnk_02e;
    Unk02124b1c *q = p->mUnk_008;
    if (q[v1].mUnk_00 != 0) {
        q[v1].mUnk_06 = p->mUnk_030 * (p->mUnk_040 - p->mUnk_044) / (p->mUnk_034 - 5);
    }
}

void func_0202eec0(void) {
    u32 a = func_020435bc();
    u32 b;
    u32 c;
    s32 d;
    if (func_0202f0a8(a) != 0) {
        b = func_0202f080(a);
        c = func_0202f058(a);
        data_02174e48->mUnk_01c = func_020291c4(b, c, data_02174e48->mUnk_00c);
        data_02174e48->mUnk_020 = data_02174e48->mUnk_01c;
        data_02174e48->mUnk_66c = 1;
    } else {
        data_02174e48->mUnk_020 = -1;
    }
    if (data_02174e48->mUnk_66c != 0) {
        if (func_0202efc8(a) != 0) {
            b = func_0202f080(a);
            c = func_0202f058(a);
            d = func_020291c4(b, c, data_02174e48->mUnk_00c);
            if (d != data_02174e48->mUnk_01c) {
                data_02174e48->mUnk_01c = -1;
                data_02174e48->mUnk_66c = 0;
            }
        } else {
            data_02174e48->mUnk_01c = -1;
            data_02174e48->mUnk_66c = 0;
        }
    }
    if (func_0202ec7c(a, 0x40) != 0 || data_02174e48->mUnk_01c == data_02174e48->mUnk_010) {
        data_02174e48->mUnk_050 = data_02174e48->mUnk_050 + 1;
    } else {
        data_02174e48->mUnk_050 = 0;
    }
    if (func_0202ec7c(a, 0x80) != 0 || data_02174e48->mUnk_01c == data_02174e48->mUnk_014) {
        data_02174e48->mUnk_054 = data_02174e48->mUnk_054 + 1;
    } else {
        data_02174e48->mUnk_054 = 0;
    }
}

#pragma thumb off

u32 func_0202efc8(u32 a) {
    return func_0202efe8((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

u32 func_0202efe8(Unk02175628_48 *a) {
    u32 r;
    if (func_0202f028(a) != 0 || func_0202f020(a) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
