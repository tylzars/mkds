#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202ee3c(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < gScrollList->mUnk_000; i++) {
        ScrollList *p = gScrollList;
        p->mUnk_008[a + p->mUnk_004[i]].mUnk_00 = b;
    }
}

#pragma thumb off
