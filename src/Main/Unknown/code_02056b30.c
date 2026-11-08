#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056c0c(PackedCourseTimeRecord *a, TimeRecord *b) {
    if (a->mFilled != 0) {
        MI_CpuCopy8(a->mName, b->mName, 0x14);
        b->mCharacterIndex = a->mCharacterIndex;
        b->mKartIndex = a->mKartIndex;
        b->mMinute = a->mMinute;
        b->mSecond = a->mSecond;
        b->mMillisecond = a->mMillisecond;
        b->mFilled = 1;
    } else {
        MI_CpuFill8(b, 0, 0x20);
    }
}

s32 func_02056bc0(s32 a, s32 b, TimeRecord *c) {
    BOOL r;
    s32 n;

    n = FindCupCourseIndex(a);
    r = TRUE;
    if (n != -1) {
        func_02056c0c(&data_0217aa08->mCourseTimeRecordBlock->mRecords[b][n], c);
    } else {
        r = FALSE;
    }
    if (r == FALSE) {
        c->mFilled = 0;
    }
    return r;
}

void func_02056b30(PackedGrandPrixRecord *a, TimeRecord *b) {
    if (b->mFilled != 0) {
        MI_CpuCopy8(b->mName, a->mName, 0x14);
        a->mFilled = 1;
        a->mCharacterIndex = b->mCharacterIndex;
        a->mUnk_00_b[1] = b->mKartIndex;
        a->mMinute = b->mMinute;
        a->mSecond = b->mSecond;
        a->mMillisecond = b->mMillisecond;
        a->mUnk_00_b[3] = b->mUnk_1e;
        a->mUnk_00_b[2] = b->mTotalPoints;
        a->mUnk_04_b[0] = b->mCupRank;
    }
}

#pragma thumb off
