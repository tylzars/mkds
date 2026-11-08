#include "Main/Unknown/code_020435c4.h"

#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_0214d018.h"

static inline void func_02043a34_inline(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        data_02175624->mPadKeys = 0;
    } else {
        data_02175624->mPadKeys = ((*(vu16 *) 0x4000130 | *(vu16 *) 0x027fffa8) ^ 0x2fff) & 0x2fff;
    }
    UpdateTouchMicInput();
}

static inline void func_02043c14_inline(void) {
    s32 i;
    s32 k;
    InputSlot *inputSlot;
    InputSlot *slot;

    for (i = 0; i < 10; i++) {
        inputSlot = &data_02175628[(u32) i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording((KeyRecording *) &inputSlot->mUnk_28);
        ResetInputSlotPair((InputSlotPair *) &inputSlot->mPairX);
    }
    data_02175628[8].mSourceKind = 5;
    data_02175628[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
    slot = data_02175628;
    for (k = 0; k < 10; k++) {
        ResetInputSlot(slot);
        slot->mRequestedBits = 0;
        SetInputSlotRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
}

static inline RaceSetup *func_02043f28_inline(void) {
    return gRaceSetup;
}

void func_0204451c(u32 entryIndex) {
    s32 f;
    RaceSetup *raceSetup;

    f = 3;
    if (gRaceSetup->mUnk_3d5[0] == -1) {
        f = 0;
    } else if (gRaceSetup->mUnk_3d5[1] == -1) {
        f = 1;
    }
    SetNextRaceEntry(entryIndex, gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex,
                     gRaceSetup->mCurrentEntries[entryIndex].mKartIndex, PLAYER_KIND_CPU,
                     gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex, f);
    raceSetup = gRaceSetup;
    raceSetup->mCurrentEntries[entryIndex] = raceSetup->mNextEntries[entryIndex];
    if (f < 2) {
        raceSetup->mUnk_3d5[f] = entryIndex;
    }
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mNumber = gRaceSetup->mNextCpuNumber;
    gRaceSetup->mNextCpuNumber = gRaceSetup->mNextCpuNumber + 1;
}

void func_02044380(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn) {
    u8 i;

    gRaceSetup->mNextHeader.mMissionFileRow = *missionFileRow;
    gRaceSetup->mNextHeader.mMissionTableRow = tableRow;
    gRaceSetup->mNextHeader.mMissionTableColumn = tableColumn;
    gRaceSetup->mNextHeader.mMode = MODE_MISSION_RUN;
    gRaceSetup->mNextHeader.mCourseId = missionFileRow->mCourseId;
    gRaceSetup->mNextHeader.mMirrorMode = (missionFileRow->mUnk_1c & 0x10) != 0 ? 1 : 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mCourseCount = 0;
    gRaceSetup->mNextHeader.mEngineIndex = missionFileRow->mEngineIndex;
    SetNextRaceEntry(0, missionFileRow->mCharacterIndex0, missionFileRow->mKartIndex0, PLAYER_KIND_HUMAN, -1, 3);
    if (missionFileRow->mCharacterIndex1 != 0xff && missionFileRow->mKartIndex1 != 0xff) {
        SetNextRaceEntry(1, missionFileRow->mCharacterIndex1, missionFileRow->mKartIndex1, PLAYER_KIND_CPU, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = 2;
    } else {
        SetNextRaceEntry(1, -1, -1, PLAYER_KIND_NONE, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    }
    for (i = 2; i < 8; i++) {
        SetNextRaceEntry(i, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
}

void func_020442d0(u32 courseId) {
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != NULL) {
        data_0217aa08->mGhostRecords[0]->mFilled = 0;
    }
}

void func_0204419c(u32 courseId, u32 b) {
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != NULL) {
        data_0217aa08->mGhostRecords[0]->mFilled = 0;
    }
    ReadSlotGhostRecord(b);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != NULL) {
        data_0217aa08->mGhostRecords[1]->mFilled = 0;
    }
}

void func_02044060(u32 courseId) {
    GhostRecord *ghostRecord;
    char path[0x80];

    ghostRecord = NULL;
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != NULL) {
        data_0217aa08->mGhostRecords[0]->mFilled = 0;
    }
    if (TryFormatGhostPath(courseId, path, 0x80) != FALSE) {
        ghostRecord = LoadGhostRecordFile(path);
    }
    if (ghostRecord != NULL) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, 0x1000);
    ghostRecord->mFilled = 0;
}

void func_02043fb0(u32 courseId) {
    data_0217aa08->mGhostRecords[1]->mFilled = 0;
    data_0217aa08->mGhostRecords[2]->mFilled = 0;
    data_0217aa08->mGhostRecords[0]->mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != NULL) {
        data_0217aa08->mGhostRecords[0]->mFilled = 0;
    }
}

void func_02043f28(u32 a) {
    u16 i;
    RaceSetup *raceSetup;
    u32 r;

    r = 0;
    i = 0;
    for (; i < (u32) (raceSetup = func_02043f28_inline())->mKartCount; i++) {
        if (a != 0) {
            r |= data_021540ec[raceSetup->mCurrentEntries[i].mCharacterIndex];
        } else {
            r |= data_021540ec[raceSetup->mNextEntries[i].mCharacterIndex];
        }
    }
    LoadSndBanksAndWaveArcsIfChanged(r);
}

void func_02043d10(void *heap) {
    s32 i;

    InitTouchPanelAndSetCalibration();
    InitTouchMicInput(heap);
    for (i = 0; i <= 1; i++) {
        InitKeyRecordingBuffer((u32) &data_02175628[i].mUnk_28, (u32) heap);
    }
    for (; i < 10; i++) {
        func_0204a9f8((KeyRecording *) &data_02175628[i].mUnk_28);
    }
    data_02175624 = HeapAlloc(heap, 0x10);
    func_02043c14_inline();
    func_02043a34_inline();
    func_02043a34_inline();
}

void ResetInputSlots(void) {
    func_02043c14_inline();
}

void func_02043b48(void) {
    s32 i;
    s32 j;
    InputSlot *inputSlot;
    InputSlot *slot;

    inputSlot = data_02175628;
    for (i = 0; i < 10; i++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    StartTouchAutoSampling();
    func_02043648();
    slot = data_02175628;
    for (j = 0; j < 10; j++) {
        slot->mHoldLong = 0;
        slot->mUnk_14 = 0;
        SetInputSlotRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
    data_02175624->mPadKeys = 0;
    data_02175624->mFlags = 0;
}

void func_02043b3c(void) {
    StopTouchAutoSampling();
}

void func_02043b04(void) {
    s32 i;
    InputSlot *inputSlot;

    inputSlot = data_02175628;
    for (i = 0; i < 10; i++) {
        ClearInputSlotBitsAndRepeat(inputSlot);
        inputSlot++;
    }
}

void func_02043ae0(void) {
    data_02175624->mFlags |= 8;
    func_02043648();
}

void func_02043ad4(void) {
    func_02046c74();
}

void SetLeftRightKeysSwapped(u32 mirrorMode) {
    if (mirrorMode != 0) {
        data_02175624->mFlags |= 4;
    } else {
        data_02175624->mFlags &= ~4;
    }
}

void func_02043a34(void) {
    func_02043a34_inline();
}

u32 GetPadKeys(void) {
    return (data_02175624->mPadKeys);
}

static inline s32 func_02043648_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

void func_02043648(void) {
    u8 slotIndex;
    u16 y;
    u16 a;
    u16 b;
    u16 padKeys;
    s32 k;
    u16 slotKeys;
    u16 t;
    s32 n;
    InputSlot *inputSlot;
    s32 o;
    BOOL skipUpdate;
    s32 c;
    s32 f;
    s32 sourceKind;
    u16 flags;

    padKeys = data_02175624->mPadKeys;
    y = GetPackedTouchPoint();
    a = padKeys;
    b = y;
    k = gTouchMicInput->mMicOverThreshold;
    if (func_02043648_inline(data_0217aa00) != 0) {
        a = func_0204ffe8(GetParticipantIndex(data_02175624->mUnk_08));
        b = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(data_02175624->mUnk_08)].mUnk_00[2];
        GetParticipantIndex(data_02175624->mUnk_08);
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        slotKeys = 0;
        n = 0xffff;
        o = slotKeys;
        f = (data_02175624->mFlags & INPUT_STATE_OPEN_DURING_RACE) ? 1 : 0;
        skipUpdate = FALSE;
        c = (GetCurrentSceneNumber() != 2 || (data_02175624->mFlags & INPUT_STATE_READ_RACE_KEYS)) ? 1 : 0;
        inputSlot = &data_02175628[slotIndex];
        flags = data_02175624->mFlags;
        if (!(flags & 8)) {
            sourceKind = inputSlot->mSourceKind;
            if (f == 0) {
                f = inputSlot->mUnk_44;
            }
            switch (sourceKind) {
                case 1:
                    if (f == 0) {
                        if (c != 0) {
                            slotKeys = ReadKeysFromKeyRecording((KeyRecording *) &inputSlot->mUnk_28);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    n = 0xffff;
                    o = 0;
                    break;
                case 2:
                    if (f == 0) {
                        if (c != 0) {
                            slotKeys = padKeys;
                            if (flags & 4) {
                                slotKeys = padKeys & 0xffcf;
                                if (padKeys & PAD_KEY_LEFT) {
                                    slotKeys |= PAD_KEY_RIGHT;
                                }
                                if (padKeys & PAD_KEY_RIGHT) {
                                    slotKeys |= PAD_KEY_LEFT;
                                }
                            }
                            AppendKeysToKeyRecording((KeyRecording *) &inputSlot->mUnk_28, slotKeys);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    n = y;
                    o = k;
                    break;
                case 3:
                case 7:
                    if (f != 0) {
                        skipUpdate = TRUE;
                    } else {
                        o = 0;
                        slotKeys = inputSlot->mRequestedBits;
                        n = 0xffff;
                        inputSlot->mRequestedBits = o;
                    }
                    break;
                case 5:
                    slotKeys = a;
                    n = b;
                    o = 0;
                    break;
                case 4:
                    if (f == 0) {
                        if (c != 0) {
                            slotKeys = func_0204ffe8(GetParticipantIndex(slotIndex));
                            if (data_02175624->mFlags & 4) {
                                t = slotKeys & 0xffcf;
                                if (slotKeys & PAD_KEY_LEFT) {
                                    t |= PAD_KEY_RIGHT;
                                }
                                if (slotKeys & PAD_KEY_RIGHT) {
                                    t |= PAD_KEY_LEFT;
                                }
                                slotKeys = t;
                            }
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    n = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(slotIndex)].mUnk_00[2];
                    o = data_0217aa00->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(slotIndex)].mUnk_06_7;
                    break;
                case 6:
                    slotKeys = padKeys;
                    n = y;
                    o = k;
                    break;
                case 0:
                    slotKeys = 0;
                    n = 0xffff;
                    o = slotKeys;
                    break;
            }
        }
        t = slotKeys & inputSlot->mBitMask;
        if (skipUpdate == FALSE) {
            UpdateInputSlot(t, inputSlot);
        }
        func_02046ca8((InputSlotPair *) &inputSlot->mPairX, n, o);
    }
}

// Takes effect only for slots whose source kind is 3 or 7.
void RequestBits(s32 slotIndex, u32 bits) {
    if (data_02175628[slotIndex].mSourceKind == 3 || data_02175628[slotIndex].mSourceKind == 7) {
        data_02175628[slotIndex].mRequestedBits |= bits;
    }
}

void SetInputOpenDuringRace(u32 openDuringRace) {
    if (openDuringRace != 0) {
        data_02175624->mFlags |= INPUT_STATE_OPEN_DURING_RACE;
        return;
    }
    data_02175624->mFlags &= ~INPUT_STATE_OPEN_DURING_RACE;
}

u32 func_020435c4(void) {
    u32 value0;
    value0 = (u32) &data_02175928;
    value0 = *(const u16 *) ((value0) + (78));
    return value0;
}
