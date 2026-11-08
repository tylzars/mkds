#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma thumb on

void PackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord) {
    if (unpackedMissionRecord->mFilled != 0) {
        missionRecord->mFilled = 1;
        missionRecord->mUnk_00_1 = unpackedMissionRecord->mValue;
    } else {
        missionRecord->mFilled = 0;
    }
}

void UnpackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord) {
    if (missionRecord->mFilled != 0) {
        unpackedMissionRecord->mFilled = 1;
        unpackedMissionRecord->mValue = missionRecord->mUnk_00_1;
    } else {
        unpackedMissionRecord->mFilled = 0;
    }
}

void SetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord) {
    PackMissionRecord(&data_0217aa08->mMissionRecordBlock->mRecords[(row - 1) * 9 + column - 1], unpackedMissionRecord);
}

s32 GetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord) {
    UnpackMissionRecord(&data_0217aa08->mMissionRecordBlock->mRecords[(row - 1) * 9 + column - 1],
                        unpackedMissionRecord);
    return 1;
}

void SetEmblemRecordAndWriteBackup(void *emblemData) {
    MI_CpuCopy8(emblemData, data_0217aa08->mEmblemRecord->mEmblemData, 0x200);
    data_0217aa08->mEmblemRecord->mFilled = 1;
    WriteBackupEmblem();
}

void FillAndWriteCourseGhostRecord(s32 courseId, u16 entryIndex) {
    GhostRecord *ghostRecord;
    s32 playerIndex;
    s32 cupCourseIndex;
    u8 courseIndexByte;
    u8 lapNumber;
    u8 byteOffset;
    s32 clockDate[4];
    KartTime kartTime;
    u8 lapBytes[0xf];
    u32 tempValue;

    cupCourseIndex = FindCupCourseIndex();
    playerIndex = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
    ghostRecord = data_0217aa08->mGhostRecords[0];
    if (cupCourseIndex == -1) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, 0xe00);
    GetClockDateOrDefault(clockDate);
    ghostRecord->mYear = clockDate[0];
    ghostRecord->mMonth = clockDate[1];
    ghostRecord->mDay = clockDate[2];
    tempValue = gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
    ghostRecord->mCharacterIndex = (u8) tempValue;
    tempValue = gRaceSetup->mCurrentEntries[entryIndex].mKartIndex;
    ghostRecord->mKartIndex = (u8) tempValue;
    tempValue = gRaceSetup->mCourseId;
    ghostRecord->mCourseId = (u8) tempValue;
    ghostRecord->mFilled = 1;
    ghostRecord->mUnk_08_1 = 0;
    ghostRecord->mUnk_08_2 = data_021759d0->mUnk_00;
    ghostRecord->mUnk_08_4 = 0;
    ghostRecord->mUnk_2f_0 = func_02056208();
    GetKartFinishTime(entryIndex, &kartTime.mMinute, &kartTime.mSecond, &kartTime.mMillisecond);
    ghostRecord->mMinute = kartTime.mMinute;
    ghostRecord->mSecond = kartTime.mSecond;
    ghostRecord->mMillisecond = kartTime.mMillisecond;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, ghostRecord->mName, 0x14);
    MI_CpuCopy8(data_02175628[playerIndex].mUnk_28, ghostRecord->mUnk_30, 0xdcc);
    MI_CpuFill8(lapBytes, 0, 0xf);
    for (lapNumber = 1; lapNumber <= GetLapCount(); lapNumber++) {
        byteOffset = (lapNumber - 1) * 3;
        GetKartLapTime(entryIndex, lapNumber, &kartTime.mMinute, &kartTime.mSecond, &kartTime.mMillisecond);
        tempValue = 0;
        tempValue |= (kartTime.mMinute & 0x7f) << 17;
        tempValue |= (kartTime.mSecond & 0x7f) << 10;
        tempValue |= kartTime.mMillisecond & 0x3ff;
        lapBytes[byteOffset] = tempValue >> 16;
        lapBytes[byteOffset + 1] = tempValue >> 8;
        lapBytes[byteOffset + 2] = tempValue;
    }
    MI_CpuCopy8(lapBytes, ghostRecord->mLapTimes, 0xf);
    courseIndexByte = cupCourseIndex;
    WriteBackupCourseGhost(courseIndexByte, ghostRecord);
    if (IsCourseGhostBitSet(courseIndexByte) == 0) {
        SetBitArrayBit(courseIndexByte, data_0217aa08->mFirstBlock->mCourseGhostBits, 4);
        StartWriteBackupFirstBlock();
    }
}

void ReadCourseGhostRecord(u32 courseId) {
    s32 cupCourseIndex;
    BOOL noGhost;
    GhostRecord *ghostRecord;

    noGhost = FALSE;
    cupCourseIndex = FindCupCourseIndex(courseId);
    ghostRecord = data_0217aa08->mGhostRecords[0];
    if (cupCourseIndex == -1) {
        noGhost = TRUE;
    } else if (IsCourseGhostBitSet(cupCourseIndex) == 0) {
        noGhost = TRUE;
    }
    if (noGhost != FALSE) {
        ghostRecord->mFilled = 0;
    } else {
        ReadBackupCourseGhost(cupCourseIndex, ghostRecord);
    }
}

#pragma thumb off
