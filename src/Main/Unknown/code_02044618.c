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

static inline void func_020446e0_inline(s32 f, u32 e, s32 d, u32 c, u32 b, s32 a) {
    SetNextRaceEntry(a, b, c, d, e, f);
}

static inline Unk0217aa00_45c *func_02045084_inline(Unk0217aa00 *q, s32 a) {
    u16 e;

    e = q->mUnk_1e8c[a];
    return e == 0xffff ? 0 : &q->mUnk_045c[e];
}

static inline BOOL func_02045084_inline2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return TRUE;
    }
    return FALSE;
}

void ResetRaceSetup(void) {
    u16 i;
    MinuteSecondMillisecondTime *e;

    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_CROSS;
    gRaceSetup->mNextHeader.mCupIndex = 0;
    gRaceSetup->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    gRaceSetup->mNextHeader.mEngineIndex = 0;
    gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mUnk_24 = 0;
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
        gRaceSetup->mNextEntries[i].mPlayer.mUnk_10 = 3;
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
    e = &gRaceSetup->mGhostTime;
    e->mMinute = 0;
    e->mSecond = 0;
    e->mMillisecond = 0;
    for (i = 0; i < 5; i++) {
        e = &gRaceSetup->mGhostLapTimes[i];
        e->mMinute = 0;
        e->mSecond = 0;
        e->mMillisecond = 0;
    }
    ResetCupRecords();
    func_0205d07c();
    SetCurrentRaceFromNext();
}

void SetCurrentEntryPlayer(s32 a) {
    Unk0217aa08 *p;
    Unk0217aa00 *q;
    void **b0;
    void **b1;
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
    b0 = &gRaceSetup->mCurrentEntries[a].mPlayer.mName;
    b1 = &gRaceSetup->mCurrentEntries[a].mPlayer.mEmblemData;
    b2 = &gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_24;
    b3 = &gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_25;
    b4 = &gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_26;
    b5 = &gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_20;
    f = FALSE;
    if (p->mEmblemRecord->mFilled != 0) {
        f = p->mUnk_00->mUnk_31_3 == 0;
    }
    if (f != FALSE) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    *b0 = NULL;
    *b1 = NULL;
    *b2 = 0;
    *b5 = 0;
    *b3 = data_021759d0->mUnk_00;
    *b4 = 0;
    if (a == gRaceSetup->mEntryIndex) {
        *b0 = &data_0217aa08->mUnk_00->mUnk_0c;
        *b1 = &data_0217aa08->mEmblemRecord->mEmblemData;
        *b2 = g != FALSE ? 1 : 0;
        *b3 = data_021759d0->mUnk_00;
        *b4 = func_02056208();
        return;
    }
    switch (gRaceSetup->mCurrentEntries[a].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            q = data_0217aa00;
            t = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                t = TRUE;
            }
            if (t == FALSE) {
                return;
            }
            if (func_02045084_inline(q, a) == NULL) {
                return;
            }
            *b0 = func_02045084_inline(q, a);
            *b1 = &func_02045084_inline(data_0217aa00, a)->mUnk_014;
            *b2 = func_02045084_inline(data_0217aa00, a)->mUnk_214;
            *b3 = func_02045084_inline(data_0217aa00, a)->mUnk_228_0;
            *b5 = func_02045084_inline2() || (data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[a])) != 0
                      ? 0
                      : (s32) &func_02045084_inline(data_0217aa00, a)->mUnk_218;
            *b4 = func_02045084_inline(data_0217aa00, a)->mUnk_229;
            break;
        case PLAYER_KIND_GHOST:
            switch (gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_10) {
                case 0:
                    *b0 = &data_0217aa08->mUnk_14[0]->mName;
                    *b1 = &data_0217aa08->mEmblemRecord->mEmblemData;
                    *b2 = g != FALSE ? 1 : 0;
                    *b3 = data_0217aa08->mUnk_14[0]->mUnk_08_2;
                    *b4 = 0;
                    break;
                case 1:
                    *b0 = &data_0217aa08->mUnk_14[1]->mName;
                    *b1 = &data_0217aa08->mUnk_14[1]->mUnk_30;
                    *b2 = data_0217aa08->mUnk_14[1]->mUnk_08_1;
                    *b3 = data_0217aa08->mUnk_14[1]->mUnk_08_2;
                    *b4 = data_0217aa08->mUnk_14[1]->mUnk_2f_0;
                    break;
                case 2:
                    *b0 = &data_0217aa08->mUnk_14[2]->mName;
                    *b1 = &data_0217aa08->mUnk_14[2]->mUnk_30;
                    *b2 = 1;
                    *b3 = data_0217aa08->mUnk_14[2]->mUnk_08_2;
                    *b4 = 1;
                    break;
            }
            break;
        case PLAYER_KIND_PEER:
            x = data_0217aa18->mUnk_00[(u8) a];
            if (x < 0) {
                return;
            }
            v = x;
            *b0 = GetPlayerRecordName(v);
            *b1 = GetPlayerRecordEmblem(v);
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

BOOL func_02044e9c(s32 a, s32 b) {
    u8 i;
    BOOL r;
    GhostRecord *p;

    r = FALSE;
    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    p = data_0217aa08->mUnk_14[0];
    if (p->mFilled == 1) {
        SetNextRaceEntry(b, p->mCharacterIndex, p->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[b].mPlayer.mUnk_10 = r;
        MI_CpuCopy8(p->mUnk_30, data_02175650[b].mBuffer, 0xdcc);
        r = TRUE;
        func_02056574(0, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            func_020565ac(0, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
    }
    return r;
}

s32 func_02044d4c(s32 a, s32 b) {
    GhostRecord *p;
    s32 r;
    u8 i;

    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return 1;
    }
    p = data_0217aa08->mUnk_14[1];
    r = p->mFilled == 1 ? 1 : 0;
    if (r != 0) {
        SetNextRaceEntry(b, p->mCharacterIndex, p->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[b].mPlayer.mUnk_10 = 1;
        MI_CpuCopy8(&p->mUnk_30[0x200], data_02175650[b].mBuffer, 0xdcc);
        func_02056574(1, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            func_020565ac(1, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
    } else {
        SetNextRaceEntry(b, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return r;
}

BOOL func_02044bf8(s32 a, s32 b) {
    GhostRecord *p;
    u8 i;

    if (gRaceSetup->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    p = data_0217aa08->mUnk_14[2];
    if (p != NULL && p->mFilled == 1) {
        SetNextRaceEntry(b, p->mCharacterIndex, p->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[b].mPlayer.mUnk_10 = 2;
        MI_CpuCopy8(&p->mUnk_30[0x200], data_02175650[b].mBuffer, 0xdcc);
        func_020565e4(p, &gRaceSetup->mGhostTime);
        for (i = 1; i <= 5; i++) {
            func_0205660c(p, i, &gRaceSetup->mGhostLapTimes[i - 1]);
        }
        return TRUE;
    }
    SetNextRaceEntry(b, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void SetCurrentRaceFromNext(void) {
    s16 h;
    GhostRecord *e;
    Unk0217aa00 *q;
    u16 n;
    u16 r;
    u8 i;
    BOOL f;

    r = 0;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_BATTLE:
        case MODE_VS:
            r = 8;
            break;
        case 5:
            r = 4;
            break;
        case MODE_TIME_ATTACK:
            n = 1;
            e = data_0217aa08->mUnk_14[0];
            if (e->mFilled == 1) {
                gRaceSetup->mUnk_3e6 = 1;
                gRaceSetup->mUnk_3e4 = e->mMinute;
                gRaceSetup->mUnk_3e5 = e->mSecond;
                gRaceSetup->mUnk_3e2 = e->mMillisecond;
            } else {
                gRaceSetup->mUnk_3e6 = 0;
                gRaceSetup->mUnk_3e4 = 0;
                gRaceSetup->mUnk_3e5 = 0;
                gRaceSetup->mUnk_3e2 = 0;
            }
            switch (gRaceSetup->mNextHeader.mUnk_24) {
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
            r = n;
            break;
        case MODE_MISSION_RUN:
            r = 2;
            break;
    }
    switch (gRaceSetup->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            r = 8;
            break;
        case RACE_KIND_NORMAL:
        case 2:
        case RACE_KIND_START_GP:
        case 4:
            h = 0;
            for (i = 0; i < 8; i++) {
                if (gRaceSetup->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    h = i;
                    break;
                }
            }
            q = data_0217aa00;
            f = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                f = TRUE;
            }
            if (f != FALSE) {
                h = q->mUnk_1e52[(u16) (q->mUnk_0000 == 2 ? q->mOwnIndex : 0)].mEntryIndex;
            }
            gRaceSetup->mNextHeader.mEntryIndex = h;
            gRaceSetup->mNextHeader.mFollowedKartIndex = h;
            break;
    }
    *(Unk02044940_block *) gRaceSetup = *(Unk02044940_block *) &gRaceSetup->mNextHeader;
    RefreshRaceSetupKartCounts(r);
    func_02044fc0();
    for (n = 0; n < 8; n++) {
        SetCurrentEntryPlayer(n);
    }
}

void func_020446e0(void) {
    u8 i;
    u32 k;
    u8 m;
    u8 n;
    RaceSetupHeader *a;
    s32 b;
    u8 c;
    s32 d;

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
                for (c = 0; c < 8; c++) {
                    s8 j;
                    for (j = 0; j < gRaceSetup->mKartCount; j++) {
                        if (c + 1 == GetKartCupRank((u16) j)) {
                            break;
                        }
                    }
                    d = c * 3;
                    if (gRaceSetup->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        func_020446e0_inline(3, -1, 1, d, c, c);
                    }
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (k = 0; k < 32; k++) {
                    m = (s32) k / 4;
                    n = (s32) k % 4;
                    b = gCupCourseIdTable[m][n];
                    if (gRaceSetup->mNextHeader.mCourseId == b) {
                        break;
                    }
                    if (k == 31) {
                        m = 0;
                        n = 3;
                    }
                }
                gRaceSetup->mNextHeader.mCourseNumber = (u8) (n + 1);
                a = &gRaceSetup->mNextHeader;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                gRaceSetup->mNextHeader.mCupIndex = m;
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
    RaceSetup *p;
    u16 r;

    r = 1;
    p = gRaceSetup;
    if (p->mMode != MODE_BATTLE) {
        if (p->mLapCount <= 0) {
            r = gCourseMap->mSettings->mLapCountOrBattleSeconds;
        } else {
            r = p->mLapCount;
        }
    }
    return r;
}
