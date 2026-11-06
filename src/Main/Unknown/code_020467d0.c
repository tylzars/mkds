#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205d0bc.h"
#include "Main/Unknown/code_0205dc54.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020364e0.h"

void func_02046bcc(void *b, u16 c) {
    Unk02046b40 *a;

    a = b;
    a->mStateFrames = 0;
    a->mNextStateRequested = 1;
    a->mState = c;
    a->mNextState = c;
}

void func_02046b40(void *b) {
    Unk02046b40 *a;
    Unk02046b40_00 *e;

    a = b;
    if (a->mNextStateRequested != 0) {
        a->mStateFrames = 0;
        a->mNextStateRequested = 0;
        a->mState = a->mNextState;
        a->mNextState = 0;
        e = &a->mUnk_00[a->mState];
        if (e->mUnk_00 != NULL) {
            e->mUnk_00(a->mUnk_08);
        }
    } else {
        e = &a->mUnk_00[a->mState];
    }
    if (e->mUnk_04 != NULL) {
        e->mUnk_04(a->mUnk_08);
    }
    a->mStateFrames++;
}

void func_02046ae4(void) {
    u8 *p;

    p = CreateDisplaySettings(GetHeap(func_020364e8()), data_usa_02154868);
    SetBg1Record(p + 0x28, 0, 0, 0, 0, 4, 0, 0);
    InitDisplayFromSettings(p);
}

void func_02046ad8(void) {
    func_020446e0();
}

u32 func_02046ad4(u32 p0) {
    return p0;
}

u32 func_02046ad0(u32 p0) {
    return p0;
}

s32 func_02046a88(void *a) {
    SceneCallbacks b = data_02164838;

    RunScene(a, &b);
    return 0;
}

void func_02046a3c(void *a) {
    data_021759c0 = HeapAlloc(a, 0x400);
    data_021759c0->mCourseList = HeapAlloc(a, 0x21);
    func_0205d0bc(a);
    func_0205dc54(a);
}

void func_02046968(s32 a) {
    u8 b[2] = {0};
    s32 i;
    u8 n;
    u8 m;

    n = 0;
    m = 0;
    for (i = 0; i < a; i++) {
        if (data_021759c0->mCurrentEntries[i].mPlayer.mKind != 4) {
            if (data_021759c0->mCurrentEntries[i].mPlayer.mKind == 0 ||
                data_021759c0->mCurrentEntries[i].mPlayer.mKind == 3) {
                n++;
            }
            m++;
            if (data_021759c0->mUseTeams != 0) {
                b[data_021759c0->mCurrentEntries[i].mPlayer.mTeamIndex]++;
            }
        }
    }
    data_021759c0->mKartCount = m;
    data_021759c0->mUnk_3d1 = n;
    for (i = 0; i < 2; i++) {
        data_021759c0->mTeamKartCounts[i] = b[i];
    }
}

void func_020468b0(int a, u32 b, u32 c, int d, u32 e, int f) {
    data_021759c0->mNextEntries[a].mCharacterIndex = b;
    data_021759c0->mNextEntries[a].mPlayer.mKind = d;
    data_021759c0->mNextEntries[a].mPlayer.mIndex = a;
    data_021759c0->mNextEntries[a].mKartIndex = c;
    data_021759c0->mNextEntries[a].mPlayer.mTeamIndex = e;
    data_021759c0->mNextEntries[a].mPlayer.mUnk_08 = f;
    data_021759c0->mNextEntries[a].mPlayer.mUnk_10 = d == 2 ? 0 : 3;
    data_021759c0->mNextEntries[a].mPlayer.mUnk_14 = 0;
    if (f != 3) {
        data_021759c0->mNextEntries[a].mPlayer.mUnk_14 |= 1;
    }
}

s32 func_0204684c(s32 a) {
    s32 i;
    s32 j;
    s8 r;

    r = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == data_02154128[i][j]) {
                r = j + i * 4;
                break;
            }
        }
    }
    return r;
}

u32 func_02046828(s32 a) {
    return data_02154128[(u32) a / 4][a % 4];
}

s32 func_020467d0(s32 a) {
    s32 r;
    s32 i;
    s32 j;

    r = 9;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == data_02154128[i][j]) {
                r = i;
            }
        }
    }
    return r;
}
