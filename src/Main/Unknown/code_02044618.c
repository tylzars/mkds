#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_021202f0.h"
#include "Main/Unknown/code_0211d4a8.h"
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
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

static inline void func_020446e0_inline(s32 f, u32 teamIndex, s32 playerKind, u32 kartIndex, u32 characterIndex,
                                        s32 entryIndex) {
    SetNextRaceEntry(entryIndex, characterIndex, kartIndex, playerKind, teamIndex, f);
}

static inline Unk0217aa00_45c *func_02045084_inline(ConnectionWork *q, s32 entryIndex) {
    u16 participantIndex;

    participantIndex = q->mUnk_1e8c[entryIndex];
    return participantIndex == 0xffff ? 0 : &q->mUnk_045c[participantIndex];
}

static inline BOOL func_02045084_inline2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return TRUE;
    }
    return FALSE;
}

void ResetRaceSetup(void) {
    u16 i;
    MinuteSecondMillisecondTime *time;

    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_CROSS;
    gRaceSetup->mNextHeader.mCupIndex = 0;
    gRaceSetup->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    gRaceSetup->mNextHeader.mEngineIndex = 0;
    gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mGhostRecordIndex = 0;
    MI_CpuFill8(&gRaceSetup->mNextHeader.mMissionFileRow, 0, 0x2c);
    gRaceSetup->mNextHeader.mMissionTableRow = -1;
    gRaceSetup->mNextHeader.mMissionTableColumn = -1;
    gRaceSetup->mNextHeader.mUnk_56[0] = 0;
    gRaceSetup->mNextHeader.mMirrorMode = 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mUnk_5c = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    gRaceSetup->mNextHeader.mEntryIndex = -1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    gRaceSetup->mNextHeader.mLapCount = -1;
    for (i = 0; i < 8; i++) {
        gRaceSetup->mNextEntries[i].mCharacterIndex = i;
        gRaceSetup->mNextEntries[i].mKartIndex = i * 3;
        gRaceSetup->mNextEntries[i].mPlayer.mKind = i == 0 ? PLAYER_KIND_HUMAN : PLAYER_KIND_CPU;
        gRaceSetup->mNextEntries[i].mPlayer.mTeamIndex = -1;
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_08 = 3;
        gRaceSetup->mNextEntries[i].mPlayer.mIndex = i;
        gRaceSetup->mNextEntries[i].mPlayer.mGhostRecordIndex = 3;
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_14 = 0;
        gRaceSetup->mNextEntries[i].mPlayer.mName = NULL;
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_24 = 0;
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_25 = data_021759d0->mUnk_00;
        gRaceSetup->mNextEntries[i].mPlayer.mEmblemData = NULL;
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_20 = 0;
    }
    gRaceSetup->mNextEntries[7].mPlayer.mUnk_08 = 0;
    gRaceSetup->mNextEntries[6].mPlayer.mUnk_08 = 1;
    gRaceSetup->mKartCount = 0;
    gRaceSetup->mHumanAndPeerKartCount = 0;
    for (i = 0; i < 2; i++) {
        gRaceSetup->mTeamKartCounts[i] = 0;
    }
    gRaceSetup->mUnk_3d4 = 0;
    for (i = 0; i < 2; i++) {
        gRaceSetup->mUnk_3d5[i] = -1;
    }
    gRaceSetup->mCourseCount = 0;
    for (i = 0; i < 0x21; i++) {
        gRaceSetup->mCourseList[i] = 0;
    }
    gRaceSetup->mCourseListIndex = 0;
    time = &gRaceSetup->mGhostTime;
    time->mMinute = 0;
    time->mSecond = 0;
    time->mMillisecond = 0;
    for (i = 0; i < 5; i++) {
        time = &gRaceSetup->mGhostLapTimes[i];
        time->mMinute = 0;
        time->mSecond = 0;
        time->mMillisecond = 0;
    }
    ResetCupRecords();
    func_0205d07c();
    SetCurrentRaceFromNext();
}

void SetCurrentEntryPlayer(s32 entryIndex) {
    Unk0217aa08 *p;
    ConnectionWork *q;
    void **nameSlot;
    void **emblemDataSlot;
    u8 *b2;
    u8 *b3;
    u8 *b4;
    s32 *b5;
    BOOL f;
    BOOL g;
    BOOL t;
    s8 x;
    u8 v;

    p = data_0217aa08;
    nameSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName;
    emblemDataSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mEmblemData;
    b2 = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_24;
    b3 = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_25;
    b4 = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_26;
    b5 = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_20;
    f = FALSE;
    if (p->mEmblemRecord->mFilled != 0) {
        f = p->mUnk_00->mUnk_31_3 == 0;
    }
    if (f != FALSE) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    *nameSlot = NULL;
    *emblemDataSlot = NULL;
    *b2 = 0;
    *b5 = 0;
    *b3 = data_021759d0->mUnk_00;
    *b4 = 0;
    if (entryIndex == gRaceSetup->mEntryIndex) {
        *nameSlot = &data_0217aa08->mUnk_00->mPlayerName;
        *emblemDataSlot = &data_0217aa08->mEmblemRecord->mEmblemData;
        *b2 = g != FALSE ? 1 : 0;
        *b3 = data_021759d0->mUnk_00;
        *b4 = func_02056208();
        return;
    }
    switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            q = data_0217aa00;
            t = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                t = TRUE;
            }
            if (t == FALSE) {
                return;
            }
            if (func_02045084_inline(q, entryIndex) == NULL) {
                return;
            }
            *nameSlot = func_02045084_inline(q, entryIndex);
            *emblemDataSlot = &func_02045084_inline(data_0217aa00, entryIndex)->mUnk_014;
            *b2 = func_02045084_inline(data_0217aa00, entryIndex)->mUnk_214;
            *b3 = func_02045084_inline(data_0217aa00, entryIndex)->mUnk_228_0;
            *b5 =
                func_02045084_inline2() || (data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[entryIndex])) != 0
                    ? 0
                    : (s32) &func_02045084_inline(data_0217aa00, entryIndex)->mUnk_218;
            *b4 = func_02045084_inline(data_0217aa00, entryIndex)->mUnk_229;
            break;
        case PLAYER_KIND_GHOST:
            switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mGhostRecordIndex) {
                case 0:
                    *nameSlot = &data_0217aa08->mGhostRecords[0]->mName;
                    *emblemDataSlot = &data_0217aa08->mEmblemRecord->mEmblemData;
                    *b2 = g != FALSE ? 1 : 0;
                    *b3 = data_0217aa08->mGhostRecords[0]->mUnk_08_2;
                    *b4 = 0;
                    break;
                case 1:
                    *nameSlot = &data_0217aa08->mGhostRecords[1]->mName;
                    *emblemDataSlot = &data_0217aa08->mGhostRecords[1]->mUnk_30;
                    *b2 = data_0217aa08->mGhostRecords[1]->mUnk_08_1;
                    *b3 = data_0217aa08->mGhostRecords[1]->mUnk_08_2;
                    *b4 = data_0217aa08->mGhostRecords[1]->mUnk_2f_0;
                    break;
                case 2:
                    *nameSlot = &data_0217aa08->mGhostRecords[2]->mName;
                    *emblemDataSlot = &data_0217aa08->mGhostRecords[2]->mUnk_30;
                    *b2 = 1;
                    *b3 = data_0217aa08->mGhostRecords[2]->mUnk_08_2;
                    *b4 = 1;
                    break;
            }
            break;
        case PLAYER_KIND_PEER:
            x = data_0217aa18->mUnk_00[(u8) entryIndex];
            if (x < 0) {
                return;
            }
            v = x;
            *nameSlot = GetPlayerRecordName(v);
            *emblemDataSlot = GetPlayerRecordEmblem(v);
            *b2 = func_02120278(v);
            *b3 = GetPlayerRecordRegion(v);
            *b5 = func_021202f0(v);
            *b4 = func_021201e4(v);
            break;
    }
}

void func_02044fc0(void) {
    u8 n;
    s8 j;

    n = 0;
    for (j = 0; j < 2; j++) {
        gRaceSetup->mUnk_3d5[j] = -1;
    }
    for (j = 0; j < gRaceSetup->mKartCount; j++) {
        if ((gRaceSetup->mCurrentEntries[(u16) j].mPlayer.mUnk_14 & 1) != 0) {
            gRaceSetup->mUnk_3d5[(u8) gRaceSetup->mCurrentEntries[j].mPlayer.mUnk_08] = j;
            n++;
        }
    }
    gRaceSetup->mUnk_3d4 = n;
}

BOOL func_02044e9c(s32 courseId, s32 entryIndex) {
    u8 i;
    BOOL result;
    GhostRecord *ghostRecord;

    result = FALSE;
    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    ghostRecord = data_0217aa08->mGhostRecords[0];
    if (ghostRecord->mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = result;
        MI_CpuCopy8(ghostRecord->mUnk_30, data_02175650[entryIndex].mBuffer, 0xdcc);
        result = TRUE;
        GetGhostFinishTimeByIndex(0, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            GetGhostLapTimeByIndex(0, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
    }
    return result;
}

s32 func_02044d4c(s32 courseId, s32 entryIndex) {
    GhostRecord *ghostRecord;
    s32 filled;
    u8 i;

    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return 1;
    }
    ghostRecord = data_0217aa08->mGhostRecords[1];
    filled = ghostRecord->mFilled == 1 ? 1 : 0;
    if (filled != 0) {
        SetNextRaceEntry(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 1;
        MI_CpuCopy8(&ghostRecord->mUnk_30[0x200], data_02175650[entryIndex].mBuffer, 0xdcc);
        GetGhostFinishTimeByIndex(1, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            GetGhostLapTimeByIndex(1, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
    } else {
        SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return filled;
}

BOOL func_02044bf8(s32 courseId, s32 entryIndex) {
    GhostRecord *ghostRecord;
    u8 i;

    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    ghostRecord = data_0217aa08->mGhostRecords[2];
    if (ghostRecord != NULL && ghostRecord->mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 2;
        MI_CpuCopy8(&ghostRecord->mUnk_30[0x200], data_02175650[entryIndex].mBuffer, 0xdcc);
        GetGhostFinishTime(ghostRecord, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            GetGhostLapTime(ghostRecord, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
        return TRUE;
    }
    SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void SetCurrentRaceFromNext(void) {
    s16 entryIndex;
    GhostRecord *ghostRecord;
    ConnectionWork *q;
    u16 n;
    u16 entryCount;
    u8 i;
    BOOL f;

    entryCount = 0;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_BATTLE:
        case MODE_VS:
            entryCount = 8;
            break;
        case 5:
            entryCount = 4;
            break;
        case MODE_TIME_ATTACK:
            n = 1;
            ghostRecord = data_0217aa08->mGhostRecords[0];
            if (ghostRecord->mFilled == 1) {
                gRaceSetup->mFirstGhostRecordFilled = 1;
                gRaceSetup->mFirstGhostRecordMinute = ghostRecord->mMinute;
                gRaceSetup->mFirstGhostRecordSecond = ghostRecord->mSecond;
                gRaceSetup->mFirstGhostRecordMillisecond = ghostRecord->mMillisecond;
            } else {
                gRaceSetup->mFirstGhostRecordFilled = 0;
                gRaceSetup->mFirstGhostRecordMinute = 0;
                gRaceSetup->mFirstGhostRecordSecond = 0;
                gRaceSetup->mFirstGhostRecordMillisecond = 0;
            }
            switch (gRaceSetup->mNextHeader.mGhostRecordIndex) {
                case 0:
                    if (func_02044e9c(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 1:
                    if (func_02044d4c(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 2:
                    if (func_02044bf8(gRaceSetup->mNextHeader.mCourseId, 1) != FALSE) {
                        n++;
                    }
                    break;
                case 3:
                    break;
            }
            entryCount = n;
            break;
        case MODE_MISSION_RUN:
            entryCount = 2;
            break;
    }
    switch (gRaceSetup->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            entryCount = 8;
            break;
        case RACE_KIND_NORMAL:
        case 2:
        case RACE_KIND_START_GP:
        case 4:
            entryIndex = 0;
            for (i = 0; i < 8; i++) {
                if (gRaceSetup->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    entryIndex = i;
                    break;
                }
            }
            q = data_0217aa00;
            f = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                f = TRUE;
            }
            if (f != FALSE) {
                entryIndex = q->mUnk_1e52[(u16) (q->mUnk_0000 == 2 ? q->mOwnIndex : 0)].mEntryIndex;
            }
            gRaceSetup->mNextHeader.mEntryIndex = entryIndex;
            gRaceSetup->mNextHeader.mFollowedKartIndex = entryIndex;
            break;
    }
    *(RaceSetupBlock *) gRaceSetup = *(RaceSetupBlock *) &gRaceSetup->mNextHeader;
    RefreshRaceSetupKartCounts(entryCount);
    func_02044fc0();
    for (n = 0; n < 8; n++) {
        SetCurrentEntryPlayer(n);
    }
}

void func_020446e0(void) {
    u8 i;
    u32 tableIndex;
    u8 cupIndex;
    u8 courseIndexInCup;
    RaceSetupHeader *a;
    s32 cupCourseId;
    u8 rankIndex;
    s32 kartIndex;

    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            if (gRaceSetup->mNextHeader.mCourseId == COURSE_ID_AWARD) {
                gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
                for (i = 3; i < 8; i++) {
                    SetNextRaceEntry(i, i, i * 3, PLAYER_KIND_NONE, -1, 3);
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else if ((u32) (gRaceSetup->mNextHeader.mCourseId - 0x35) <= 1) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
                gRaceSetup->mNextHeader.mEngineIndex = 1;
                for (rankIndex = 0; rankIndex < 8; rankIndex++) {
                    s8 j;
                    for (j = 0; j < gRaceSetup->mKartCount; j++) {
                        if (rankIndex + 1 == GetKartCupRank((u16) j)) {
                            break;
                        }
                    }
                    kartIndex = rankIndex * 3;
                    if (gRaceSetup->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        func_020446e0_inline(3, -1, 1, kartIndex, rankIndex, rankIndex);
                    }
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (tableIndex = 0; tableIndex < 32; tableIndex++) {
                    cupIndex = (s32) tableIndex / 4;
                    courseIndexInCup = (s32) tableIndex % 4;
                    cupCourseId = gCupCourseIdTable[cupIndex][courseIndexInCup];
                    if (gRaceSetup->mNextHeader.mCourseId == cupCourseId) {
                        break;
                    }
                    if (tableIndex == 31) {
                        cupIndex = 0;
                        courseIndexInCup = 3;
                    }
                }
                gRaceSetup->mNextHeader.mCourseNumber = (u8) (courseIndexInCup + 1);
                a = &gRaceSetup->mNextHeader;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                gRaceSetup->mNextHeader.mCupIndex = cupIndex;
            }
            break;
        case MODE_BATTLE:
            if (data_021759d0->mUnk_1c_2 != 0) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            } else {
                gRaceSetup->mNextHeader.mRaceKind = 4;
            }
            break;
        case MODE_MISSION_RUN:
            break;
        default:
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
    }
}

void ResetTimeAttackNextEntries(void) {
    u16 i;

    if (gRaceSetup->mNextHeader.mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    for (i = 1; i < 8; i++) {
        gRaceSetup->mNextEntries[i].mCharacterIndex = i;
        gRaceSetup->mNextEntries[i].mKartIndex = i;
        gRaceSetup->mNextEntries[i].mPlayer.mKind = PLAYER_KIND_NONE;
        gRaceSetup->mNextEntries[i].mPlayer.mIndex = i;
    }
}

// In battle there is one lap.
u16 GetLapCount(void) {
    RaceSetup *raceSetup;
    u16 lapCount;

    lapCount = 1;
    raceSetup = gRaceSetup;
    if (raceSetup->mMode != MODE_BATTLE) {
        if (raceSetup->mLapCount <= 0) {
            lapCount = gCourseMap->mSettings->mLapCountOrBattleSeconds;
        } else {
            lapCount = raceSetup->mLapCount;
        }
    }
    return lapCount;
}
