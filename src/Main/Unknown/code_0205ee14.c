#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "00/code_021832d8.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c8dc.h"

#pragma opt_rebuildconditionals off

static inline BOOL func_0205f218_inline(void) {
    ConnectionWork *connectionWork;

    connectionWork = data_0217aa00;
    return (connectionWork == NULL ? 0 : connectionWork->mUnk_0000) != 0 && connectionWork->mUnk_0004 != 13;
}

BOOL FormatTimeRecordChars(u8 *charsOut, TimeRecord *timeRecord, s32 courseId) {
    u8 packedBytes[10] = {0};
    u32 e;
    s32 cupCourseIndex;
    u32 characterKartValue;
    u8 bitPosition;
    s32 charIndex;
    u16 charValue;
    u8 bitIndex;
    u32 bitOffset;
    s32 byteIndex;
    u8 q;
    s32 xorKey;

    e = timeRecord->mMillisecond + (timeRecord->mSecond * 1000 + timeRecord->mMinute * 60000);
    if (e >= 240000) {
        return 0;
    }
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex < 0 || cupCourseIndex >= 32) {
        return 0;
    }
    characterKartValue = timeRecord->mCharacterIndex * 37 + timeRecord->mKartIndex;
    if (characterKartValue >= 0x200) {
        return 0;
    }
    e = ((e & 0x3ffff) << 14) | ((cupCourseIndex & 0x1f) << 9);
    *(u32 *) &packedBytes[0] = e | (characterKartValue & 0x1ff);
    MI_CpuCopy8(&timeRecord->mName, &packedBytes[4], 4);
    *(u16 *) &packedBytes[8] = 0;
    WriteBlockTail(packedBytes, 10, 1);
    xorKey = 0xc3;
    for (byteIndex = 9; byteIndex >= 0; byteIndex--) {
        packedBytes[byteIndex] ^= xorKey;
        xorKey = packedBytes[byteIndex];
    }
    for (charIndex = 0, bitOffset = 0; charIndex < 16; charIndex++) {
        charValue = 0;
        for (bitIndex = 0; bitIndex < 5; bitIndex++) {
            q = bitOffset;
            bitPosition = q + bitIndex;
            charValue = (u16) (charValue | ((packedBytes[(u8) (bitPosition / 8)] >> (u8) (7 - bitPosition % 8)) & 1))
                        << 1;
        }
        charsOut[charIndex] = gTimeRecordCharTable[(u8) (charValue / 2)];
        bitOffset += 5;
    }
    return 1;
}

BOOL FormatFirstCourseTimeRecord(s32 courseId, void *charsOut) {
    TimeRecord timeRecord;
    BOOL hasRecord;

    hasRecord = FALSE;
    if (GetCourseTimeRecord(courseId, 0, &timeRecord) != 0 && timeRecord.mFilled != 0) {
        hasRecord = TRUE;
    }
    if (hasRecord == FALSE) {
        return 0;
    }
    return FormatTimeRecordChars(charsOut, &timeRecord, courseId);
}

BOOL GetMissionRecordValue(s32 row, s32 column, s32 *valueOut) {
    UnpackedMissionRecord missionRecord;
    BOOL isFilled;

    isFilled = FALSE;
    GetMissionRecord(row, column, &missionRecord);
    if (missionRecord.mFilled == 1) {
        isFilled = TRUE;
        *valueOut = missionRecord.mValue;
    }
    return isFilled;
}

BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    limit = func_02056d98();
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return 1;
    }
    return 0;
}

BOOL func_0205fc98(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    if (func_0205f218_inline() != FALSE) {
        limit = data_0217aa08->mParticipantMinValue;
    } else {
        limit = func_02056d98();
    }
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBitSetInAllParticipants(s32 bitIndex) {
    if (func_0205f218_inline() == FALSE) {
        return IsBackupFlagSet(bitIndex);
    }
    return func_02056e00(bitIndex, data_0217aa08->mParticipantAndBits);
}

s32 IsBitSetInAnyParticipant(s32 bitIndex) {
    if (func_0205f218_inline() == FALSE) {
        return IsBackupFlagSet(bitIndex);
    }
    return func_02056e00(bitIndex, data_0217aa08->mParticipantOrBits);
}

void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind) {
    RaceSetup *raceSetup;
    BuddyRecord buddyRecord;
    u16 *firstCount;
    u16 *secondCount;
    u8 buddyIndex;
    s32 foundIndex;

    raceSetup = gRaceSetup;
    if (entryIndex == raceSetup->mEntryIndex) {
        return;
    }
    if (raceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_20 == 0) {
        return;
    }
    foundIndex = func_0206105c((const void *) raceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_20);
    if (foundIndex == -1) {
        return;
    }
    buddyIndex = foundIndex;
    GetBuddyRecord(buddyIndex, &buddyRecord);
    if (buddyRecord.mFilled == 0) {
        ResetBuddyRecord((u32) &buddyRecord);
    }
    if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName != NULL) {
        MI_CpuCopy8(gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName, buddyRecord.mName, 0x14);
    }
    switch (matchKind) {
        case 0:
            firstCount = &buddyRecord.mResultCounts[0][0];
            secondCount = &buddyRecord.mResultCounts[0][1];
            break;
        case 1:
            firstCount = &buddyRecord.mResultCounts[1][0];
            secondCount = &buddyRecord.mResultCounts[1][1];
            break;
        case 2:
            firstCount = &buddyRecord.mResultCounts[2][0];
            secondCount = &buddyRecord.mResultCounts[2][1];
            break;
    }
    switch (resultKind) {
        case 0:
            if (*firstCount < 0xffff) {
                *firstCount = *firstCount + 1;
            }
            break;
        case 1:
            if (*secondCount < 0xffff) {
                *secondCount = *secondCount + 1;
            }
            break;
    }
    buddyRecord.mYear = date[0];
    buddyRecord.mMonth = date[1];
    buddyRecord.mDay = date[2];
    buddyRecord.mFilled = 1;
    SetBuddyRecord(buddyIndex, &buddyRecord);
}

static inline u32 func_0205f700_inline(u16 kartIndex, u32 ownRank) {
    if (GetKartRank(kartIndex) > ownRank) {
        return 0;
    }
    return 1;
}

void AddVSBuddyRecordResults(void) {
    BOOL countsChanged;
    u32 outcome;
    u16 entryIndex;
    u32 ownRank;
    u32 firstTotal;
    u32 secondTotal;
    s32 teamIndex;
    s32 playerKind;
    s32 date[3];

    countsChanged = FALSE;
    teamIndex = -1;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    ownRank = GetKartRank((u16) gRaceSetup->mEntryIndex);
    if (gRaceSetup->mUseTeams != 0) {
        teamIndex = gRaceSetup->mCurrentEntries[(u16) gRaceSetup->mEntryIndex].mPlayer.mTeamIndex;
    }
    firstTotal = data_0217aa08->mFirstBlock->mUnk_34[0];
    secondTotal = data_0217aa08->mFirstBlock->mUnk_34[1];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        if (gRaceSetup->mUseTeams != 0) {
            if (teamIndex == gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex) {
                outcome = 2;
            } else {
                switch (gRaceSetup->mRuleKind) {
                    case 0:
                    case 2:
                        outcome = func_0205f700_inline(entryIndex, ownRank);
                        break;
                    case 1:
                        if (teamIndex == GetCupWinningTeam()) {
                            outcome = 0;
                        } else if (gRaceProgress->mUnk_000[entryIndex].mStatus == 4) {
                            outcome = 2;
                        } else {
                            outcome = 1;
                        }
                        break;
                }
            }
        } else {
            outcome = func_0205f700_inline(entryIndex, ownRank);
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[entryIndex]])) == 0) {
            AddBuddyRecordResult(entryIndex, date, 0, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                firstTotal++;
                countsChanged = TRUE;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                secondTotal++;
                countsChanged = TRUE;
            }
        }
    }
    if (countsChanged != FALSE) {
        data_0217aa08->mFirstBlock->mUnk_34[0] = firstTotal;
        data_0217aa08->mFirstBlock->mUnk_34[1] = secondTotal;
        func_0205edcc();
    } else {
        WriteBackupBuddyRecords();
    }
}

void AddBattleBuddyRecordResults(void) {
    u16 entryIndex;
    u32 firstTotal;
    u32 secondTotal;
    BOOL countsChanged;
    u32 outcome;
    s32 playerKind;
    s32 date[5];

    countsChanged = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    firstTotal = data_0217aa08->mFirstBlock->mUnk_34[2];
    secondTotal = data_0217aa08->mFirstBlock->mUnk_34[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (gRaceProgress->mUnk_000[entryIndex].mStatus != 4) {
                outcome = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[entryIndex]])) == 0) {
            AddBuddyRecordResult(entryIndex, date, 1, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        data_0217aa08->mFirstBlock->mUnk_34[2] = firstTotal;
        data_0217aa08->mFirstBlock->mUnk_34[3] = secondTotal;
        func_0205edcc();
    } else {
        WriteBackupBuddyRecords();
    }
}

void func_0205f218(void) {
    u16 entryIndex;
    u32 firstTotal;
    u32 secondTotal;
    BOOL countsChanged;
    u32 outcome;
    s32 playerKind;
    s32 date[5];

    countsChanged = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    GetKartRank((u16) gRaceSetup->mEntryIndex);
    firstTotal = data_0217aa08->mFirstBlock->mUnk_34[2];
    secondTotal = data_0217aa08->mFirstBlock->mUnk_34[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (gRaceProgress->mUnk_000[entryIndex].mStatus != 4) {
                outcome = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[entryIndex]])) == 0) {
            AddBuddyRecordResult(entryIndex, date, 1, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        data_0217aa08->mFirstBlock->mUnk_34[2] = firstTotal;
        data_0217aa08->mFirstBlock->mUnk_34[3] = secondTotal;
        func_0205edcc();
    } else {
        WriteBackupBuddyRecords();
    }
}

static inline u16 func_0205ef70_inline(u16 entryIndex) {
    s32 lowByte;
    s32 courseIndexInCup;
    s32 lowByteAgain;
    KartCourseResult *courseResult;

    lowByte = GetLowByte(entryIndex);
    courseIndexInCup = GetCourseIndexInCup();
    lowByteAgain = GetLowByte(lowByte);
    courseResult = &gCupRecords->mUnk_000[courseIndexInCup][0];
    courseResult += lowByteAgain;
    return courseResult->mTotalPoints;
}

void func_0205ef70(void) {
    u16 entryIndex;
    s32 ownCupRank;
    u32 firstTotal;
    u32 secondTotal;
    u32 kartCountCopy;
    u16 ownPoints;
    u32 outcome;
    s8 otherKartCount;
    s32 date[3];

    firstTotal = data_0217aa08->mFirstBlock->mUnk_34[4];
    secondTotal = data_0217aa08->mFirstBlock->mUnk_34[5];
    func_0205b32c();
    if (gRaceSetup->mCourseNumber <= 3) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    GetClockDateOrDefault(date);
    ownCupRank = GetKartCupRank((u16) gRaceSetup->mEntryIndex);
    ownPoints = func_0205ef70_inline(gRaceSetup->mEntryIndex);
    otherKartCount = gWiFiSession->mKartCountCopy - 1;
    kartCountCopy = gWiFiSession->mKartCountCopy;
    if (otherKartCount > 0) {
        if (secondTotal < otherKartCount) {
            secondTotal = 0;
        } else {
            secondTotal -= otherKartCount;
        }
    }
    if ((s16) (kartCountCopy - gRaceSetup->mKartCount) > 0) {
        firstTotal += (s16) (kartCountCopy - gRaceSetup->mKartCount);
        if (firstTotal > gResultTotalMax) {
            firstTotal = gResultTotalMax;
        }
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        outcome = 2;
        if (entryIndex != gRaceSetup->mEntryIndex) {
            if (ownCupRank < GetKartCupRank(entryIndex)) {
                outcome = 0;
            } else if (ownCupRank > GetKartCupRank(entryIndex)) {
                outcome = 1;
            }
            if (ownPoints == func_0205ef70_inline(entryIndex)) {
                outcome = 2;
            }
            AddBuddyRecordResult(entryIndex, date, 2, outcome);
            if (outcome == 0) {
                if (firstTotal < gResultTotalMax) {
                    firstTotal++;
                }
            } else if (outcome == 1) {
                if (secondTotal < gResultTotalMax) {
                    secondTotal++;
                }
            }
        }
    }
    data_0217aa08->mFirstBlock->mElo = GetPlayerRecordElo(func_ov000_0219bb50());
    data_0217aa08->mFirstBlock->mUnk_34[4] = firstTotal;
    data_0217aa08->mFirstBlock->mUnk_34[5] = secondTotal;
    func_0205edcc();
}

void SetRaceResultRecords(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        switch (gRaceSetup->mMode) {
            case MODE_VS:
                AddVSBuddyRecordResults();
                break;
            case MODE_MISSION_RUN:
                TrySetMissionRecord();
                break;
            case MODE_BATTLE:
                switch (gRaceSetup->mBattleKind) {
                    case BATTLE_KIND_BALLOON:
                        AddBattleBuddyRecordResults();
                        break;
                    case BATTLE_KIND_SHINE:
                        func_0205f218();
                        break;
                }
                break;
            case 5:
                func_0205ef70();
                break;
        }
    }
}

void SetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecord) {
    MI_CpuCopy8(buddyRecord, &data_0217aa08->mBuddyRecordBlock->mRecords[recordIndex], 0x24);
}

u32 GetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecordOut) {
    if (buddyRecordOut != NULL) {
        MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[recordIndex], buddyRecordOut, 0x24);
    }
    return data_0217aa08->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0;
}
