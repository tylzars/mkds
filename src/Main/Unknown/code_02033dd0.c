#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"

// Reads the table of gCupRecords, a row chosen by one call and a column by another.
static inline KartCourseResult *func_02033e6c_inline(u32 entryIndex) {
    return &gCupRecords->mKartResults[GetCourseIndexInCup()][GetLowByte(entryIndex)];
}

#pragma thumb on

void func_02034244(void) {
    s16 offset;
    u32 b;
    u32 c;
    s32 negatedOffset;
    s32 e;

    offset = GetInterpolatedValue(&data_02174e64->mUnk_194);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    switch (offset) {
        default:
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
            e = (reg_G2_WININ & ~0x3f) | 0x1f;
            reg_G2_WININ = e | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
            c = (reg_G2S_DB_WININ & ~0x3f) | 0x1f;
            reg_G2S_DB_WININ = c | 0x20;
            b = (reg_G2S_DB_WINOUT & ~0x3f) | 7;
            reg_G2S_DB_WINOUT = b | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
            break;
    }
}

void AssignResultsBattleTeamOrder(void) {
    ResultsBattle *o;
    s32 nextOrderIndex;
    s32 team1Count;
    s32 i;

    nextOrderIndex = 0;
    team1Count = 0;
    for (i = 0; i < gResultsBattle->mKartCount; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            gResultsBattle->mEntries[i].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
    for (i = 0; i < gResultsBattle->mKartCount; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            team1Count++;
        }
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (i = 0; i < gResultsBattle->mKartCount; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            gResultsBattle->mEntries[i].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
}

void AssignResultsBattleTeamOrderByScore(void) {
    ResultsBattle *o;
    s32 scores[8];
    s32 team0Entries[8];
    s32 team1Entries[8];
    s32 team0BestIndex;
    s32 nextOrderIndex;
    s32 k;
    s32 team0Count;
    s32 i;
    s32 team1Count;
    s32 j;
    s32 team0BestScore;
    s32 d;
    s32 team1BestScore;
    s32 team1BestIndex;

    nextOrderIndex = 0;
    team0Count = 0;
    team1Count = 0;
    for (i = 0; i < (o = gResultsBattle)->mKartCount; i++) {
        scores[i] = o->mEntries[i].mScore;
    }
    for (i = 0; i < (o = *(ResultsBattle **) &gResultsBattle)->mKartCount; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            team0Entries[team0Count] = i;
            team0Count = team0Count + 1;
        } else {
            team1Entries[team1Count] = i;
            team1Count = team1Count + 1;
        }
    }
    for (d = 0; d < team0Count; d++) {
        team0BestScore = -1;
        team0BestIndex = -1;
        for (k = 0; k < team0Count; k++) {
            if (team0BestScore < scores[team0Entries[k]]) {
                team0BestScore = scores[team0Entries[k]];
                team0BestIndex = k;
            }
        }
        gResultsBattle->mEntries[team0Entries[team0BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team0Entries[team0BestIndex]] = -2;
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (j = 0; j < team1Count; j++) {
        team1BestScore = -1;
        team1BestIndex = -1;
        for (k = 0; k < team1Count; k++) {
            if (team1BestScore < scores[team1Entries[k]]) {
                team1BestScore = scores[team1Entries[k]];
                team1BestIndex = k;
            }
        }
        gResultsBattle->mEntries[team1Entries[team1BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team1Entries[team1BestIndex]] = -2;
    }
}

void FillResultsBattleEntries(void) {
    u16 j;
    u16 k;
    s32 higherCount;

    for (k = 0; k < gResultsBattle->mKartCount; k++) {
        if (gResultsBattle->mMode == 3 || gRaceSetup->mRuleKind == 2) {
            gResultsBattle->mEntries[k].mScore = func_02033e6c_inline(GetLowByte(k))->mTotalPoints;
        } else {
            gResultsBattle->mEntries[k].mScore = func_02033e6c_inline(GetLowByte(k))->mWinCount;
        }
    }
    for (j = 0; j < gResultsBattle->mKartCount; j++) {
        higherCount = 0;
        for (k = 0; k < gResultsBattle->mKartCount; k++) {
            if (j != k && gResultsBattle->mEntries[j].mScore < gResultsBattle->mEntries[k].mScore) {
                higherCount++;
            }
        }
        gResultsBattle->mEntries[j].mRank = higherCount;
    }
    if (gRaceSetup->mUseTeams != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
            AssignResultsBattleTeamOrder();
        } else {
            AssignResultsBattleTeamOrderByScore();
        }
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        for (k = 0; k < gResultsBattle->mKartCount; k++) {
            gResultsBattle->mEntries[k].mOrderIndex = data_0217b488->mUnk_ec[k];
        }
    } else {
        for (k = 0; k < gResultsBattle->mKartCount; k++) {
            gResultsBattle->mEntries[k].mOrderIndex = GetKartCupRank(k) - 1;
        }
    }
}

s32 AreResultsBattleRanksAllZero(void) {
    s32 allRanksZero;
    s32 i;

    allRanksZero = 1;
    i = 0;
    for (; i < gResultsBattle->mKartCount; i++) {
        allRanksZero &= gResultsBattle->mEntries[i].mRank == 0 ? 1 : 0;
    }
    return allRanksZero;
}

s32 IsResultsBattleTimerRunOut(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer == 0) {
        result = TRUE;
    }
    return result;
}

s32 func_02033dd0(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer < 0x12c) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off
