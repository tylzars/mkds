#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056cac(PackedCourseTimeRecord *a, TimeRecord *b) {
    if (b->mFilled != 0) {
        MI_CpuCopy8(b->mName, a->mName, 0x14);
        a->mFilled = 1;
        a->mCharacterIndex = b->mCharacterIndex;
        a->mKartIndex = b->mKartIndex;
        a->mMinute = b->mMinute;
        a->mSecond = b->mSecond;
        a->mMillisecond = b->mMillisecond;
    } else {
        MI_CpuFill8(a, 0, 0x1c);
    }
}

#pragma thumb off
