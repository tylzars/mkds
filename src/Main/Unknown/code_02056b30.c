#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056c0c(Unk0217aa08_0c_04 *a, TimeRecord *b) {
    if (a->mUnk_00_0 != 0) {
        MI_CpuCopy8(a->mUnk_08, b->mName, 0x14);
        b->mCharacterIndex = a->mUnk_00_1;
        b->mKartIndex = a->mUnk_04;
        b->mMinute = a->mUnk_00_8;
        b->mSecond = a->mUnk_00_15;
        b->mMillisecond = a->mUnk_00_22;
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
        func_02056c0c(&data_0217aa08->mUnk_0c->mUnk_004[b][n], c);
    } else {
        r = FALSE;
    }
    if (r == FALSE) {
        c->mFilled = 0;
    }
    return r;
}

void func_02056b30(Unk0217aa08_08_04 *a, TimeRecord *b) {
    if (b->mFilled != 0) {
        MI_CpuCopy8(b->mName, a->mUnk_08, 0x14);
        a->mUnk_00_0 = 1;
        a->mUnk_00_1 = b->mCharacterIndex;
        a->mUnk_00_b[1] = b->mKartIndex;
        a->mUnk_04_8 = b->mMinute;
        a->mUnk_04_15 = b->mSecond;
        a->mUnk_04_22 = b->mMillisecond;
        a->mUnk_00_b[3] = b->mUnk_1e;
        a->mUnk_00_b[2] = b->mUnk_1d;
        a->mUnk_04_b[0] = b->mCupRank;
    }
}

#pragma thumb off
