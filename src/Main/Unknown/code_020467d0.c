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

void SetStateMachineState(void *b, u16 c) {
    StateMachine *a;

    a = b;
    a->mStateFrames = 0;
    a->mNextStateRequested = 1;
    a->mState = c;
    a->mNextState = c;
}

void AdvanceStateMachine(void *b) {
    StateMachine *a;
    StateCallbacks *e;

    a = b;
    if (a->mNextStateRequested != 0) {
        a->mStateFrames = 0;
        a->mNextStateRequested = 0;
        a->mState = a->mNextState;
        a->mNextState = 0;
        e = &a->mStateTable[a->mState];
        if (e->mEnter != NULL) {
            e->mEnter(a->mObject);
        }
    } else {
        e = &a->mStateTable[a->mState];
    }
    if (e->mUpdate != NULL) {
        e->mUpdate(a->mObject);
    }
    a->mStateFrames++;
}

void func_02046ae4(void) {
    u8 *p;

    p = CreateDisplaySettings(GetHeap(GetCurrentHeapCall()), data_usa_02154868);
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
    gRaceSetup = HeapAlloc(a, 0x400);
    gRaceSetup->mCourseList = HeapAlloc(a, 0x21);
    func_0205d0bc(a);
    func_0205dc54(a);
}

void RefreshRaceSetupKartCounts(s32 a) {
    u8 b[2] = {0};
    s32 i;
    u8 n;
    u8 m;

    n = 0;
    m = 0;
    for (i = 0; i < a; i++) {
        if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_NONE) {
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN ||
                gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_PEER) {
                n++;
            }
            m++;
            if (gRaceSetup->mUseTeams != 0) {
                b[gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex]++;
            }
        }
    }
    gRaceSetup->mKartCount = m;
    gRaceSetup->mHumanAndPeerKartCount = n;
    for (i = 0; i < 2; i++) {
        gRaceSetup->mTeamKartCounts[i] = b[i];
    }
}

void SetNextRaceEntry(int a, u32 b, u32 c, int d, u32 e, int f) {
    gRaceSetup->mNextEntries[a].mCharacterIndex = b;
    gRaceSetup->mNextEntries[a].mPlayer.mKind = d;
    gRaceSetup->mNextEntries[a].mPlayer.mIndex = a;
    gRaceSetup->mNextEntries[a].mKartIndex = c;
    gRaceSetup->mNextEntries[a].mPlayer.mTeamIndex = e;
    gRaceSetup->mNextEntries[a].mPlayer.mUnk_08 = f;
    gRaceSetup->mNextEntries[a].mPlayer.mUnk_10 = d == PLAYER_KIND_GHOST ? 0 : 3;
    gRaceSetup->mNextEntries[a].mPlayer.mUnk_14 = 0;
    if (f != 3) {
        gRaceSetup->mNextEntries[a].mPlayer.mUnk_14 |= 1;
    }
}

s32 FindCupCourseIndex(s32 a) {
    s32 i;
    s32 j;
    s8 r;

    r = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == gCupCourseIdTable[i][j]) {
                r = j + i * 4;
                break;
            }
        }
    }
    return r;
}

u32 GetCupCourseIdAtIndex(s32 a) {
    return gCupCourseIdTable[(u32) a / 4][a % 4];
}

s32 FindCupIndexOfCourse(s32 a) {
    s32 r;
    s32 i;
    s32 j;

    r = 9;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == gCupCourseIdTable[i][j]) {
                r = i;
            }
        }
    }
    return r;
}
