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

void SetStateMachineState(void *rawStateMachine, u16 state) {
    StateMachine *stateMachine;

    stateMachine = rawStateMachine;
    stateMachine->mStateFrames = 0;
    stateMachine->mNextStateRequested = 1;
    stateMachine->mState = state;
    stateMachine->mNextState = state;
}

void AdvanceStateMachine(void *rawStateMachine) {
    StateMachine *stateMachine;
    StateCallbacks *callbacks;

    stateMachine = rawStateMachine;
    if (stateMachine->mNextStateRequested != 0) {
        stateMachine->mStateFrames = 0;
        stateMachine->mNextStateRequested = 0;
        stateMachine->mState = stateMachine->mNextState;
        stateMachine->mNextState = 0;
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
        if (callbacks->mEnter != NULL) {
            callbacks->mEnter(stateMachine->mObject);
        }
    } else {
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
    }
    if (callbacks->mUpdate != NULL) {
        callbacks->mUpdate(stateMachine->mObject);
    }
    stateMachine->mStateFrames++;
}

void func_02046ae4(void) {
    u8 *displaySettings;

    displaySettings = CreateDisplaySettings(GetHeap(GetCurrentHeapCall()), data_usa_02154868);
    SetBg1Record(displaySettings + 0x28, 0, 0, 0, 0, 4, 0, 0);
    InitDisplayFromSettings(displaySettings);
}

void func_02046ad8(void) {
    func_020446e0();
}

u32 func_02046ad4(u32 value) {
    return value;
}

u32 func_02046ad0(u32 value) {
    return value;
}

s32 func_02046a88(void *a) {
    SceneCallbacks callbacks = data_02164838;

    RunScene(a, &callbacks);
    return 0;
}

void func_02046a3c(void *heap) {
    gRaceSetup = HeapAlloc(heap, 0x400);
    gRaceSetup->mCourseList = HeapAlloc(heap, 0x21);
    CreateParticipantKartMap(heap);
    CreateCupRecords(heap);
}

void RefreshRaceSetupKartCounts(s32 entryCount) {
    u8 teamCounts[2] = {0};
    s32 i;
    u8 humanAndPeerCount;
    u8 kartCount;

    humanAndPeerCount = 0;
    kartCount = 0;
    for (i = 0; i < entryCount; i++) {
        if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_NONE) {
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN ||
                gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_PEER) {
                humanAndPeerCount++;
            }
            kartCount++;
            if (gRaceSetup->mUseTeams != 0) {
                teamCounts[gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex]++;
            }
        }
    }
    gRaceSetup->mKartCount = kartCount;
    gRaceSetup->mHumanAndPeerKartCount = humanAndPeerCount;
    for (i = 0; i < 2; i++) {
        gRaceSetup->mTeamKartCounts[i] = teamCounts[i];
    }
}

void SetNextRaceEntry(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex, int f) {
    gRaceSetup->mNextEntries[entryIndex].mCharacterIndex = characterIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind = playerKind;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    gRaceSetup->mNextEntries[entryIndex].mKartIndex = kartIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mTeamIndex = teamIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mUnk_08 = f;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = playerKind == PLAYER_KIND_GHOST ? 0 : 3;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mUnk_14 = 0;
    if (f != 3) {
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mUnk_14 |= 1;
    }
}

s32 FindCupCourseIndex(s32 courseId) {
    s32 i;
    s32 j;
    s8 courseIndex;

    courseIndex = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (courseId == gCupCourseIdTable[i][j]) {
                courseIndex = j + i * 4;
                break;
            }
        }
    }
    return courseIndex;
}

u32 GetCupCourseIdAtIndex(s32 courseIndex) {
    return gCupCourseIdTable[(u32) courseIndex / 4][courseIndex % 4];
}

s32 FindCupIndexOfCourse(s32 courseId) {
    s32 cupIndex;
    s32 i;
    s32 j;

    cupIndex = 9;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (courseId == gCupCourseIdTable[i][j]) {
                cupIndex = i;
            }
        }
    }
    return cupIndex;
}
