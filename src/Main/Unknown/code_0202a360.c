#include "Main/Unknown/code_0202a360.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02122734.h"
#include "00/code_02181f98.h"

#pragma opt_rebuildconditionals off

#pragma thumb on

static inline Unk0217aa1c_144_00 *func_0202a360_inline(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

u32 func_0202a360(void) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 ownEntryIndex;
    s32 scores[8];
    s32 unused;
    s32 i;
    s32 maxScore;
    s32 allEqual;
    s32 kartIndex;
    s32 courseIndex;
    s32 team0Score;
    s32 team1Score;
    s32 ownTeamIndex;
    s32 ownIndex;
    KartCourseResult *record;

    raceSetup = gRaceSetup;
    kartCount = raceSetup->mKartCount;
    if (raceSetup->mMode == MODE_GRAND_PRIX) {
        if (data_0217b488->mCupRankIndex < 3) {
            return 0;
        }
        return 1;
    }
    switch (data_021759d0->mUnk_20) {
        case 0:
            ownEntryIndex = 0;
            break;
        case 1:
        case 2:
            if (data_0217aa00->mUnk_0000 == 2) {
                ownIndex = data_0217aa00->mOwnIndex;
            } else {
                ownIndex = 0;
            }
            ownEntryIndex = data_0217aa00->mUnk_1e52[(u16) ownIndex].mEntryIndex;
            break;
        case 3:
            ownEntryIndex = (u16) GetPackedIndex(func_ov000_0219bb50());
            break;
    }
    if (gRaceSetup->mUseTeams != 0) {
        ownTeamIndex = gRaceSetup->mCurrentEntries[ownEntryIndex].mPlayer.mTeamIndex;
        switch (gRaceSetup->mRuleKind) {
            case 1:
                team0Score = func_0202a360_inline(0)->mUnk_02;
                team1Score = func_0202a360_inline(1)->mUnk_02;
                break;
            case 2:
                team0Score = func_0202a360_inline(0)->mUnk_00;
                team1Score = func_0202a360_inline(1)->mUnk_00;
                break;
        }
        if (team0Score == team1Score) {
            return 7;
        }
        if (team0Score > team1Score) {
            if (ownTeamIndex == 0) {
                return 5;
            }
            return 6;
        }
        if (ownTeamIndex == 1) {
            return 5;
        }
        return 6;
    }
    i = 0;
    maxScore = -1;
    allEqual = 1;
    for (; i < kartCount; i++) {
        if (data_021759d0->mUnk_20 == 3 || gRaceSetup->mRuleKind == 2) {
            kartIndex = GetLowByte((u16) i);
            courseIndex = GetCourseIndexInCup();
            record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
            scores[i] = record->mTotalPoints;
        } else {
            kartIndex = GetLowByte((u16) i);
            courseIndex = GetCourseIndexInCup();
            record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
            scores[i] = record->mWinCount;
        }
        if (maxScore < scores[i]) {
            maxScore = scores[i];
        }
    }
    for (i = 1; i < kartCount; i++) {
        allEqual = allEqual & (scores[0] == scores[i]);
    }
    if (allEqual != 0) {
        return 4;
    }
    if (maxScore == scores[ownEntryIndex]) {
        return 2;
    }
    return 3;
}

#pragma thumb off
