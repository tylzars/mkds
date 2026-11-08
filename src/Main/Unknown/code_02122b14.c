#include "Main/Unknown/code_02122b14.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

// Sets the session up for variant a (0 to 3): case 0 resets masks, records and picks and sets mStep 0, case 1 only
// packs the indices and counts the karts, cases 2 and 3 reset the picks and set mStep 7 and 3.
void SetupWiFiSession(u32 mode) {
    u8 i;
    u8 ownIndex;
    func_0211fe44();
    switch (mode) {
        case 0:
            MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
            MI_CpuFill8(gWiFiSession->mIndexMessages, 0, 0x110);
            MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, 0x110);
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50()) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mPlayerRecords[i], 0x244);
                    GetRaceSetupCopy()->mEntries[i].mPlayerKind = 3;
                } else {
                    gWiFiSession->mPlayerRecords[i].mUnk_238 = data_0217aa08->mFirstBlock->mUnk_34[4];
                    gWiFiSession->mPlayerRecords[i].mUnk_23c = data_0217aa08->mFirstBlock->mUnk_34[5];
                    GetRaceSetupCopy()->mEntries[i].mPlayerKind = 0;
                }
                GetRaceSetupCopy()->mEntries[i].mCharacterIndex = -1;
                GetRaceSetupCopy()->mEntries[i].mKartIndex = -1;
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[i].mCharacterIndex = -1;
                gWiFiSession->mIndexMessages[i].mKartIndex = -1;
                gWiFiSession->mIndexMessages[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            ownIndex = func_ov000_0219bb50();
            gWiFiSession->mPlayerRecords[ownIndex].mSeed = OS_GetTick();
            PackWiFiSessionIndices();
            gWiFiSession->mStep = 0;
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gWiFiSession->mStartKartCount);
            break;
        case 1:
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case 2:
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mReceiveBuffers[i], 0x44);
                }
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 7;
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case 3:
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mReceiveBuffers[i], 0x44);
                }
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                GetRaceSetupCopy()->mEntries[i].mCharacterIndex = -1;
                GetRaceSetupCopy()->mEntries[i].mKartIndex = -1;
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[i].mCharacterIndex = -1;
                gWiFiSession->mIndexMessages[i].mKartIndex = -1;
                gWiFiSession->mIndexMessages[i].mPickedCourseId = 0;
                gWiFiSession->mIndexMessages[i].mUnk_40 = 0;
                gWiFiSession->mReceiveBuffers[i].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mUnk_40 = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 3;
            break;
    }
}

// One frame of the exchange: counts the frames since each kart last called back, marks silent karts and drops them,
// then runs the handler of the current mStep (steps 2, 6, 7, 11 and 12 inline). Always returns 0.
s32 UpdateWiFiSessionStep(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    s32 waitFlag;
    Unk0217d384_1d00 *ownRecord;
    BackupAccess *backup;
    UpdateWiFiSessionKartTimeouts();
    RemoveWiFiSessionKarts();
    switch (gWiFiSession->mStep) {
        case 0:
            AdvanceWiFiSessionStep0();
            break;
        case 1:
            AdvanceWiFiSessionStep1();
            break;
        case 2:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (data_0217aa08->mBusy == 0) {
                backup = gBackupAccess;
                if (backup->mBackupEnabled != 0) {
                    waitFlag = backup->mCommandRunning;
                } else {
                    waitFlag = 0;
                }
            } else {
                waitFlag = 1;
            }
            if (waitFlag == 0) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 5;
            }
            break;
        case 3:
            AdvanceWiFiSessionStep3();
            break;
        case 4:
            AdvanceWiFiSessionStep4();
            break;
        case 5:
            AdvanceWiFiSessionStep5();
            break;
        case 6:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = func_021216a8();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = func_ov000_0219bb50();
                ownIndex = func_ov000_0219bb50();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = 4;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                CombineKartRemoveMask();
                gWiFiSession->mStep = 7;
                gWiFiSession->mStepFrames = 0;
            }
            break;
        case 7:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = func_021216a8();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = func_ov000_0219bb50();
                ownIndex = func_ov000_0219bb50();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = 5;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                ownIndex = func_ov000_0219bb50();
                if (gWiFiSession->mIndexMessages[ownIndex].mPickedCourseId != 0) {
                    gWiFiSession->mSendRecordMask = 0;
                    gWiFiSession->mReceivedMask = 0;
                    gWiFiSession->mStep = 8;
                    gWiFiSession->mStepFrames = 0;
                }
            }
            break;
        case 8:
            AdvanceWiFiSessionStep8();
            break;
        case 9:
            AdvanceWiFiSessionStep9();
            break;
        case 11:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (func_ov000_0219bb68() <= 1) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 12;
            }
            break;
        case 12:
            break;
    }
    return 0;
}

void AdvanceWiFiSessionStep0(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u32 toBit;
    WiFiPlayerRecord *ownPlayerRecord;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gWiFiSession->mSendRecordMask & toBit) != 0) {
            fromIndex = func_ov000_0219bb50();
            ownIndex = func_ov000_0219bb50();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = func_ov000_0219bb50();
            func_ov000_021a32a0(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], 0x244);
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else if ((gWiFiSession->mReceivedMask & toBit) == 0) {
            header.mFromIndex = func_ov000_0219bb50();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 0;
            header.mKartMask = gWiFiSession->mKartMask;
            func_ov000_021a32a0(toIndex, &header, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 1;
}

void AdvanceWiFiSessionStep1(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    u32 toBit;
    u32 seedSum;
    WiFiSession *session;
    WiFiPlayerRecord *ownPlayerRecord;
    RandomState64 *generator;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gWiFiSession->mSendRecordMask & toBit) != 0) {
            fromIndex = func_ov000_0219bb50();
            ownIndex = func_ov000_0219bb50();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = func_ov000_0219bb50();
            func_ov000_021a32a0(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], 0x244);
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else {
            header.mFromIndex = func_ov000_0219bb50();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 2;
            header.mKartMask = gWiFiSession->mKartMask;
            func_ov000_021a32a0(toIndex, &header, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    session = gWiFiSession;
    seedSum = 0;
    for (i = 0; i < session->mStartKartCount; i++) {
        seedSum += session->mPlayerRecords[i].mSeed;
    }
    generator = &session->mRandom;
    generator->mValue = seedSum;
    generator->mMultiplier = 0x5d588b656c078965;
    generator->mIncrement = 0x269ec3;
    func_0205e5c4(0);
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 2;
}

void AdvanceWiFiSessionStep3(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    ownIndex = func_ov000_0219bb50();
    if (gWiFiSession->mIndexMessages[ownIndex].mUnk_40 == 2) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gWiFiSession->mStep = 11;
        return;
    }
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 8;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gWiFiSession->mIndexMessages[ownIndex].mUnk_40 == 0) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 4;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep4(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    Unk0217d384_08 *stateMachine;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 9;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    if (gWiFiSession->mKartCount == 1) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        stateMachine = &gWiFiSession->mUnk_0008;
        stateMachine->mNextState = 2;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 5;
    gWiFiSession->mStepFrames = 0;
    ownIndex = func_ov000_0219bb50();
    SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[ownIndex]);
    SetSessionKartCount(gWiFiSession->mKartCount);
}

void AdvanceWiFiSessionStep5(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 3;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gWiFiSession->mIndexMessages[ownIndex].mCharacterIndex == -1) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gWiFiSession->mIndexMessages[ownIndex].mKartIndex == -1) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 6;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep8(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 6;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    CombineKartRemoveMask();
    TallyPickedCourse();
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        ownIndex = func_ov000_0219bb50();
        gWiFiSession->mIndexMessages[ownIndex].mKartIndices[i] = gWiFiSession->mIndexMessages[i].mKartIndex;
        ownIndex = func_ov000_0219bb50();
        gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[i] = gWiFiSession->mIndexMessages[i].mCharacterIndex;
    }
    ownIndex = func_ov000_0219bb50();
    gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId = GetRaceSetupCopy()->mCourseId;
    gWiFiSession->mStep = 9;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep9(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    Unk0217d384_1d00 *ownRecord;
    toIndex = func_021216a8();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 7;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(toIndex, &gWiFiSession->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
            if (SetPeerReceiveBuffer(i, gWiFiSession->mUnk_001c[i], 0x80) == FALSE) {
                return;
            }
        }
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 10;
    gWiFiSession->mStepFrames = 0;
}

// Only while 5 <= mStep < 9: ORs into mKartRemoveMask every kart in mKartMask that some stored mask (own included) does
// not list.
void CombineKartRemoveMask(void) {
    u8 i;
    u8 commonMask = 0xff;
    if (gWiFiSession->mStep < 5) {
        return;
    }
    if (gWiFiSession->mStep >= 9) {
        return;
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
            commonMask &= gWiFiSession->mIndexMessages[i].mKartMask;
        }
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
            if ((commonMask & (1 << i)) == 0) {
                gWiFiSession->mKartRemoveMask |= 1 << i;
            }
        }
    }
}
