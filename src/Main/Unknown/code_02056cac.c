#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056cac(Unk0217aa08_0c_04 *a, Unk02056bc0 *b) {
    if (b->mUnk_18 != 0) {
        MI_CpuCopy8(b->mUnk_04, a->mUnk_08, 0x14);
        a->mUnk_00_0 = 1;
        a->mUnk_00_1 = b->mUnk_19;
        a->mUnk_04 = b->mUnk_1a;
        a->mUnk_00_8 = b->mUnk_02;
        a->mUnk_00_15 = b->mUnk_03;
        a->mUnk_00_22 = b->mUnk_00;
    } else {
        MI_CpuFill8(a, 0, 0x1c);
    }
}

#pragma thumb off
