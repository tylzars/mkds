#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020563ec.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_021526a0.h"
#include "Main/Unknown/code_02152918.h"
#include "code_0214d018.h"
#include "code_02152500.h"
#include "code_02152a24.h"
#include "00/code_021832d8.h"
#include "00/code_0219d948.h"

static inline s32 func_02060004_inline(s32 a, s32 b, TimeRecord *c) {
    BOOL r;

    if (func_02056bc0(a, b, c) != 0 && c->mFilled != 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

void CopyWiFiBuddiesToRecordBlock(Unk0217d384_19f0 *a) {
    MI_CpuCopy8(a, (u8 *) data_0217aa08->mBuddyRecordBlock + 0x874, 0x2d0);
}

void RefreshNotYetBuddyFlags(void) {
    BuddyRecord a;
    u8 i;

    for (i = 0; i < 60; i++) {
        func_0205ee14(i, &a);
        if (a.mFilled == 1 && a.mNotYetBuddy == 1 &&
            DWC_IsBuddyFriendData((DWCAccFriendData *) ((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + i * 12)) !=
                0) {
            a.mNotYetBuddy = 0;
            func_0205ee74(i, &a);
        }
    }
}

BOOL IsBuddyRecordFilled(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBuddyRecordFlagged(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mFlagged;
    }
    return 0;
}

s32 func_02060ac8(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[0][0];
    }
    return -1;
}

s32 func_02060a94(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[0][1];
    }
    return -1;
}

s32 func_02060a60(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[1][0];
    }
    return -1;
}

s32 func_02060a2c(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[1][1];
    }
    return -1;
}

s32 func_020609f8(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[2][0];
    }
    return -1;
}

s32 func_020609c4(u8 a) {
    BuddyRecord b;

    func_0205ee14(a, &b);
    if (b.mFilled == 1) {
        return b.mResultCounts[2][1];
    }
    return -1;
}

BOOL GetBuddyRecordDate(u8 a, u8 *b) {
    BuddyRecord c;

    func_0205ee14(a, &c);
    if (c.mFilled != 1) {
        return FALSE;
    }
    b[0] = c.mYear;
    b[1] = c.mMonth;
    b[2] = c.mDay;
    return TRUE;
}

BOOL GetBuddyRecordName(u8 a, void *b) {
    BuddyRecord c;

    func_0205ee14(a, &c);
    if (c.mFilled != 1) {
        return FALSE;
    }
    MI_CpuCopy8(c.mName, b, 0x14);
    return TRUE;
}

BOOL SetBuddyRecordFlag(u8 a, s32 b) {
    BuddyRecord c;

    func_0205ee14(a, &c);
    if (c.mFilled == 1) {
        c.mFlagged = b != 0;
        func_0205ee74(a, &c);
        return TRUE;
    }
    return FALSE;
}

s32 RemoveBuddyRecord(u8 a) {
    BuddyRecord b;
    BOOL c;

    func_0205ee14(a, &b);
    c = b.mFilled == 1;
    MI_CpuFill8(&b, 0, 0x24);
    b.mFilled = 0;
    func_0205ee74(a, &b);
    if (gWiFiSession->mUnk_0008.mState != 0) {
        RemoveBuddyEntry((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + a * 12);
    } else {
        MI_CpuFill8((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + a * 12, 0, 0xc);
    }
    func_0205edf8();
    return c;
}

void MergeBuddyRecords(u8 a, u8 b) {
    BuddyRecord c;
    BuddyRecord d;
    BuddyRecord e;

    func_0205ee14(a, &c);
    func_0205ee14(b, &d);
    ResetBuddyRecord((u32) &e);
    if (d.mNotYetBuddy == 0) {
        e.mResultCounts[0][0] = e.mResultCounts[0][0] + d.mResultCounts[0][0];
        e.mResultCounts[0][1] = e.mResultCounts[0][1] + d.mResultCounts[0][1];
        e.mResultCounts[1][0] = e.mResultCounts[1][0] + d.mResultCounts[1][0];
        e.mResultCounts[1][1] = e.mResultCounts[1][1] + d.mResultCounts[1][1];
        e.mResultCounts[2][0] = e.mResultCounts[2][0] + d.mResultCounts[2][0];
        e.mResultCounts[2][1] = e.mResultCounts[2][1] + d.mResultCounts[2][1];
        MI_CpuCopy8(d.mName, e.mName, 0x14);
        e.mYear = d.mYear;
        e.mMonth = d.mMonth;
        e.mDay = d.mDay;
    }
    if (c.mNotYetBuddy == 0) {
        e.mResultCounts[0][0] = e.mResultCounts[0][0] + c.mResultCounts[0][0];
        e.mResultCounts[0][1] = e.mResultCounts[0][1] + c.mResultCounts[0][1];
        e.mResultCounts[1][0] = e.mResultCounts[1][0] + c.mResultCounts[1][0];
        e.mResultCounts[1][1] = e.mResultCounts[1][1] + c.mResultCounts[1][1];
        e.mResultCounts[2][0] = e.mResultCounts[2][0] + c.mResultCounts[2][0];
        e.mResultCounts[2][1] = e.mResultCounts[2][1] + d.mResultCounts[2][1];
        MI_CpuCopy8(c.mName, e.mName, 0x14);
        e.mYear = c.mYear;
        e.mMonth = c.mMonth;
        e.mDay = c.mDay;
    }
    e.mFilled = 1;
    e.mNotYetBuddy = 0;
    e.mUnk_22_2 = c.mUnk_22_2;
    e.mFlagged = c.mFlagged == 1 || d.mFlagged == 1;
    func_0205ee74(a, &e);
    MI_CpuFill8(&d, 0, 0x24);
    d.mFilled = 0;
    func_0205ee74(b, &d);
}

s32 GetBuddyFriendKeyText(u8 a, void *b) {
    u8 *e;
    BOOL d;
    BOOL g;
    BuddyRecord c;

    d = FALSE;
    func_0205ee14(a, &c);
    e = (u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + a * 12;
    if (c.mFilled == 1 && c.mNotYetBuddy == 1 && func_021526a0(e) != 0) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    if (g != FALSE) {
        u64 f = DWC_GetFriendKey((DWCAccFriendData *) e);

        FormatFriendKey(f, f >> 32, (u32) b);
        d = TRUE;
    }
    return d;
}

s32 IsGrandPrixRecordFilled(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled == 0) {
        return 0;
    }
    return c.mFilled;
}

s32 GetGrandPrixRecordCharacterIndex(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled != 0) {
        return c.mCharacterIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordKartIndex(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled != 0) {
        return c.mKartIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordCupRank(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled != 0) {
        return c.mCupRank;
    }
    return 3;
}

s32 func_02060390(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled != 0) {
        return (s8) c.mUnk_1d;
    }
    return -1;
}

s32 func_02060364(s32 a, s32 b) {
    TimeRecord c;

    GetGrandPrixRecord(a, b, &c);
    if (c.mFilled != 0) {
        return c.mUnk_1e;
    }
    return 9;
}

BOOL GetGrandPrixRecordTime(s32 a, s32 b, void *c) {
    TimeRecord d;

    GetGrandPrixRecord(a, b, &d);
    if (d.mFilled == 0) {
        return FALSE;
    }
    MI_CpuCopy8(&d, c, 4);
    return TRUE;
}

s32 func_02060268(s32 a) {
    u8 i;
    BOOL c;
    s32 d;
    TimeRecord b;

    c = TRUE;
    d = FindCupCourseIndex(a);
    if (d == -1) {
        return c;
    }
    if (func_020573f8(d) == 0) {
        return c;
    }
    for (i = 0; i < 6; i++) {
        if (func_02060004_inline(a, i, &b)) {
            c = FALSE;
            break;
        }
    }
    return c;
}

BOOL IsTimeRecordFilled(s32 a, s32 b) {
    TimeRecord c;

    if (func_02056bc0(a, b, &c) != 0 && c.mFilled != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 GetTimeRecordCharacterIndex(s32 a, s32 b) {
    TimeRecord c;

    if (func_02060004_inline(a, b, &c)) {
        return c.mCharacterIndex;
    }
    return -1;
}

s32 GetTimeRecordKartIndex(s32 a, s32 b) {
    TimeRecord c;

    if (func_02060004_inline(a, b, &c)) {
        return c.mKartIndex;
    }
    return -1;
}

BOOL GetTimeRecordTime(s32 a, s32 b, void *v1) {
    TimeRecord c;
    TimeRecord *d;

    if (!func_02060004_inline(a, b, &c)) {
        return FALSE;
    }
    d = v1;
    d->mMinute = c.mMinute;
    d->mSecond = c.mSecond;
    d->mMillisecond = c.mMillisecond;
    return TRUE;
}

BOOL GetTimeRecordName(s32 a, s32 b, void *v1) {
    TimeRecord c;

    if (!func_02060004_inline(a, b, &c)) {
        return FALSE;
    }
    MI_CpuCopy8(c.mName, v1, 0x14);
    return TRUE;
}

s32 func_020600b4(s32 a) {
    return func_0203b96c(FindCupIndexOfCourse(a));
}

void ClearCourseTimeRecords(s32 a) {
    u8 i;
    BOOL d;
    u8 e;
    s32 c;
    TimeRecord b;

    c = FindCupCourseIndex(a);
    d = FALSE;
    if (c == -1) {
        return;
    }
    e = c;
    if (func_020573f8(e) != 0) {
        func_020573e0(e);
        d = TRUE;
    }
    for (i = 0; i < 6; i++) {
        MI_CpuFill8(&b, 0, 0x20);
        func_02056c6c(a, i, &b);
    }
    if (d != FALSE) {
        func_020563ec();
    } else {
        func_02056408();
    }
}
