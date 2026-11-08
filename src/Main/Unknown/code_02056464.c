#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152490.h"

#pragma thumb on

void func_02056670(u32 a) {
    GhostRecord *p;

    p = data_0217aa08->mUnk_14[1];
    if (func_020573c8(a) == 0) {
        p->mFilled = 0;
    } else {
        func_020578fc(a, p);
    }
}

s32 func_0205660c(GhostRecord *a, s32 b, MinuteSecondMillisecondTime *c) {
    u8 i;
    u32 v;

    i = (b - 1) * 3;
    v = 0;
    if (a->mFilled == 0) {
        return v;
    }
    v |= a->mLapTimes[i] << 16;
    v |= a->mLapTimes[i + 1] << 8;
    v |= a->mLapTimes[i + 2];
    c->mMinute = (v >> 17) & 0x7f;
    c->mSecond = (v >> 10) & 0x7f;
    c->mMillisecond = v & 0x3ff;
    return 1;
}

BOOL func_020565e4(GhostRecord *a, MinuteSecondMillisecondTime *b) {
    if (a->mFilled == 0) {
        return FALSE;
    }
    b->mMinute = a->mMinute;
    b->mSecond = a->mSecond;
    b->mMillisecond = a->mMillisecond;
    return TRUE;
}

s32 func_020565ac(s32 a, s32 b, MinuteSecondMillisecondTime *c) {
    s32 r;

    r = 0;
    switch (a) {
        case 0:
            r = func_0205660c(data_0217aa08->mUnk_14[0], b, c);
            break;
        case 1:
            r = func_0205660c(data_0217aa08->mUnk_14[1], b, c);
            break;
        case 2:
            break;
    }
    return r;
}

s32 func_02056574(s32 a, MinuteSecondMillisecondTime *b) {
    s32 r;

    r = 0;
    switch (a) {
        case 0:
            r = func_020565e4(data_0217aa08->mUnk_14[0], b);
            break;
        case 1:
            r = func_020565e4(data_0217aa08->mUnk_14[1], b);
            break;
        case 2:
            break;
    }
    return r;
}

void func_02056464(Unk0217aa00_45c *a) {
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, a->mUnk_000, 0x14);
    if (data_0217aa08->mEmblemRecord->mFilled != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        a->mUnk_214 = 1;
        MI_CpuCopy8(data_0217aa08->mEmblemRecord->mEmblemData, &a->mUnk_014, 0x200);
    } else {
        a->mUnk_214 = 0;
        MI_CpuFill8(&a->mUnk_014, 0, 0x200);
    }
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_20, a->mBits, 4);
    a->mUnk_228_0 = data_021759d0->mUnk_00;
    a->mUnk_228_4 = data_021759d0->mLanguageIndex;
    a->mUnk_216 = data_0217aa08->mUnk_00->mUnk_24;
    a->mUnk_229 = func_02056208();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        MI_CpuFill8(&a->mUnk_218, 0, 0xc);
    } else {
        DWC_CreateExchangeToken((DWCAccUserData *) data_0217aa08->mUnk_00->mUnk_4c, (DWCAccFriendData *) &a->mUnk_218);
    }
}

#pragma thumb off
