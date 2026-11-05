#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146c98.h"

#pragma thumb on

void func_02124efc(Unk02124b1c *p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p->mUnk_00 = 1;
        p->mUnk_04 = 0;
        p->mUnk_06 = 0;
        p->mUnk_08 = FALSE;
        p->mUnk_0c = 0;
        p->mUnk_0e = 0;
        p->mUnk_10 = 0;
        Matrix2x2Identity(p->mUnk_14);
        Matrix2x2Identity(p->mUnk_24);
        p->mUnk_34 = 1;
        p->mUnk_38 = -1;
        p->mUnk_3c = NULL;
        p++;
    }
}

#pragma thumb off
