#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056cac(Unk0217aa08_0c_04 *a, TimeRecord *b) {
    if (b->mFilled != 0) {
        MI_CpuCopy8(b->mName, a->mUnk_08, 0x14);
        a->mUnk_00_0 = 1;
        a->mUnk_00_1 = b->mCharacterIndex;
        a->mUnk_04 = b->mKartIndex;
        a->mUnk_00_8 = b->mMinute;
        a->mUnk_00_15 = b->mSecond;
        a->mUnk_00_22 = b->mMillisecond;
    } else {
        MI_CpuFill8(a, 0, 0x1c);
    }
}

#pragma thumb off
