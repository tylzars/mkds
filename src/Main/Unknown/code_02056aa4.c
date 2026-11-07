#include "Main/Unknown/code_02056aa4.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056aa4(PackedGrandPrixRecord *a, TimeRecord *b) {
    if (a->mFilled != 0) {
        MI_CpuCopy8(a->mName, b->mName, 0x14);
        b->mCharacterIndex = a->mCharacterIndex;
        b->mKartIndex = a->mUnk_00_b[1];
        b->mMinute = a->mMinute;
        b->mSecond = a->mSecond;
        b->mMillisecond = a->mMillisecond;
        b->mUnk_1e = a->mUnk_00_b[3];
        b->mUnk_1d = a->mUnk_00_b[2];
        b->mCupRank = a->mUnk_04_b[0];
        b->mFilled = 1;
    } else {
        b->mFilled = 0;
    }
}

#pragma thumb off
