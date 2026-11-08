#include "Main/Unknown/code_020b3728.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/code_020b3b08.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0217b35c.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020b3f64.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

u32 RequestRaceEndStemSet(void) {
    u32 value0;
    u32 trueValue;
    value0 = (u32) &gRaceEnd;
    trueValue = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = trueValue;
    return value0;
}

void SetKartCupRanks(void) {
    RaceSetup *raceSetup = gRaceSetup;
    s32 sortKeys[8];
    s32 sortedIndices[8];
    u16 i;
    u16 j;
    s32 keySign = -1;
    s32 humanGhostOrPeerBit;
    s32 lowByte;
    s32 courseIndexInCup;
    s32 cupScore;
    BOOL isHumanGhostOrPeer;
    KartCourseResult *courseResult;

    if (raceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = FALSE;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3) {
                if ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isHumanGhostOrPeer = TRUE;
                }
            }
            humanGhostOrPeerBit = isHumanGhostOrPeer != FALSE ? 1 : 0;
            lowByte = GetLowByte(i);
            courseIndexInCup = GetCourseIndexInCup();
            cupScore = gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)].mWinCount;
            sortKeys[i] = (cupScore << 4) + (humanGhostOrPeerBit << 3) + 8 - GetKartRank(i);
        } else {
            isHumanGhostOrPeer = FALSE;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3) {
                if ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isHumanGhostOrPeer = TRUE;
                }
            }
            humanGhostOrPeerBit = isHumanGhostOrPeer != FALSE ? 1 : 0;
            lowByte = GetLowByte(i);
            courseIndexInCup = GetCourseIndexInCup();
            courseResult = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
            cupScore = courseResult->mTotalPoints;
            sortKeys[i] = (cupScore << 4) + (humanGhostOrPeerBit << 3) + 8 - GetKartRank(i);
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        sortedIndices[i] = i;
        sortKeys[i] = sortKeys[i] * keySign;
    }
    SortIndicesByKey(sortedIndices, sortKeys, gRaceSetup->mKartCount);
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        for (j = 0; j < (u32) gRaceSetup->mKartCount; j++) {
            if (i == sortedIndices[j]) {
                SetKartCupRank(i, j + 1);
                break;
            }
        }
    }
}

static inline Unk0217aa1c_144_00 *func_020b3b58_inline(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

static inline CourseTeamResults *func_020b3b58_inline2(void) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()];
}

void SetCupWinningTeamFromRecords(void) {
    RaceSetup *raceSetup = gRaceSetup;
    s32 firstTeamScore;
    s32 secondTeamScore;
    BOOL isRuleKind1OrBattle;
    u16 i;
    Unk0217aa1c_144_00 *firstTeamRecord;

    if (raceSetup->mUseTeams == 0) {
        return;
    }
    if (raceSetup->mRuleKind == 1 || raceSetup->mMode == MODE_BATTLE) {
        firstTeamScore = func_020b3b58_inline(0)->mUnk_02;
    } else {
        firstTeamRecord = &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[0];
        firstTeamScore = firstTeamRecord->mUnk_00;
    }
    raceSetup = gRaceSetup;
    isRuleKind1OrBattle = TRUE;
    if (raceSetup->mRuleKind != 1 && raceSetup->mMode != MODE_BATTLE) {
        isRuleKind1OrBattle = FALSE;
    }
    if (isRuleKind1OrBattle) {
        secondTeamScore = func_020b3b58_inline(1)->mUnk_02;
    } else {
        secondTeamScore = func_020b3b58_inline2()->mTeams[1].mUnk_00;
    }
    if (firstTeamScore > secondTeamScore) {
        SetCupWinningTeam(0);
        return;
    }
    if (secondTeamScore > firstTeamScore) {
        SetCupWinningTeam(1);
        return;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (GetKartRank(i) == 1) {
            break;
        }
    }
    SetCupWinningTeam(gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex);
}

void InitRaceEnd(void) {
    gRaceEnd = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x10);
    gRaceEnd->mEndFrames = 0;
    gRaceEnd->mStemSetRequested = FALSE;
    gRaceEnd->mStemSetRequestFrames = 0;
    gRaceEnd->mResultsSet = FALSE;
}

u32 ClearRaceEndPointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceEnd;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

u32 ResetRaceEndFrames(void) {
    u32 value0;
    u32 zeroValue;
    value0 = (u32) &gRaceEnd;
    zeroValue = 0u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (0)) = zeroValue;
    return value0;
}

void UpdateRaceEnd(void) {
    RaceSetup *raceSetup;
    s32 a;
    s32 followedKartStatus;
    BOOL playsRaceEndSound;
    u16 followedKartIndex;

    if (gRaceProgress->mRaceDone != 0 && gRaceEnd->mResultsSet == FALSE) {
        SetKartCupRanks();
        SetCupWinningTeamFromRecords();
        SetRaceResultRecords();
        gRaceEnd->mResultsSet = TRUE;
    }
    followedKartIndex = GetFollowedKartOrEntryIndex();
    if (gRaceProgress->mUnk_000[followedKartIndex].mStatus != 1 && gRaceProgress->mRaceDone == 0) {
        return;
    }
    a = gRaceEnd->mEndFrames;
    if (a < 11) {
        gRaceEnd->mEndFrames = a + 1;
        if (a == 0) {
            raceSetup = gRaceSetup;
            switch (raceSetup->mMode) {
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                    SetStemSet(3);
                    break;
                case MODE_VS:
                case 5:
                    if (raceSetup->mRuleKind != 1) {
                        if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus == 1) {
                            SetStemSet(3);
                        }
                    }
                    break;
            }
            if ((data_0217d084.mMode - 2) <= 1 && gRaceSetup->mMode != MODE_BATTLE) {
                raceSetup = gRaceSetup;
                playsRaceEndSound = TRUE;
                if (raceSetup->mRaceKind == RACE_KIND_DEMO) {
                    playsRaceEndSound = FALSE;
                } else if (raceSetup->mMode == MODE_MISSION_RUN) {
                    switch (raceSetup->mMissionKind) {
                        case 2:
                        case 4:
                        case 6:
                        case 10:
                            if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) != 0) {
                                playsRaceEndSound = FALSE;
                            }
                            break;
                        default:
                            playsRaceEndSound = FALSE;
                            break;
                    }
                }
                if (playsRaceEndSound != FALSE) {
                    if (IsRaceNewRecordTaFinishRecord() != 0 || IsRaceNewRecordTaBestLapRecord() != 0) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x44);
                    } else {
                        followedKartStatus = gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus;
                        if (followedKartStatus == 3) {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x43);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x42);
                        }
                    }
                }
            }
        } else if (a == 10) {
            raceSetup = gRaceSetup;
            switch (raceSetup->mMode) {
                case MODE_VS:
                    if (raceSetup->mRuleKind == 1) {
                        SetStemSet((GetKart(raceSetup->mEntryIndex)->mUnk_7c & 0x2000000) ? 4 : 5);
                    }
                    break;
                case MODE_BATTLE:
                    SetStemSet((GetKart(raceSetup->mEntryIndex)->mUnk_7c & 0x2000000) ? 4 : 5);
                    break;
                case MODE_MISSION_RUN:
                    if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) != 0) {
                        SetStemSet(7);
                    }
                    break;
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                case 5:
                    break;
            }
        }
    }
    if (gRaceEnd->mStemSetRequested == FALSE) {
        return;
    }
    a = gRaceEnd->mStemSetRequestFrames;
    gRaceEnd->mStemSetRequestFrames = a + 1;
    if (a != 10) {
        return;
    }
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_MISSION_RUN:
            if ((IsKartEnded((u16) raceSetup->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) == 0) {
                SetStemSet(6);
            }
            break;
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_BATTLE:
        case MODE_VS:
        case 5:
            break;
    }
    gRaceEnd->mStemSetRequested = FALSE;
}
