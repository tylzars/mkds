#include "Main/Unknown/code_020d4990.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

#pragma thumb on
void func_020d4990(Unk020e6fd4 *p) {
    s32 i;

    if (p->mUnk_1c != 0) {
        p->mUnk_24 = func_02036bec(func_020364e0(func_020364e8()), p->mUnk_04 * 4);
        for (i = 0; i < p->mUnk_04; i++) {
            p->mUnk_24[i] = p->mUnk_00[i];
        }
    } else {
        p->mUnk_24 = p->mUnk_00;
    }
}
#pragma thumb off
