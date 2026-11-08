#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02090354.h"

static inline u32 func_02046524_inline(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

BOOL func_02046648(s32 a) {
    u32 n;
    n = (u8) gRaceSetup->mNextHeader.mEngineIndex;
    if (gRaceSetup->mNextHeader.mMirrorMode != 0) {
        n = 3;
    }
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (func_0205fbb8(n)) {
                return TRUE;
            }
            break;
        case 3:
            if (func_0205fbb8(n + 4)) {
                return TRUE;
            }
            break;
        case 6:
            if (func_0205fbb8(n + 8)) {
                return TRUE;
            }
            break;
        case 7:
            if (func_0205fbb8(n + 12)) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void AssignCpuNumbers(void) {
    u8 nextCpuNumber;
    BOOL f;
    u8 i;
    nextCpuNumber = 1;
    f = FALSE;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
        case 5:
            f = TRUE;
            break;
    }
    for (i = 0; i < 8; i++) {
        if (f == FALSE && gRaceSetup->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_CPU) {
            gRaceSetup->mNextEntries[i].mPlayer.mNumber = nextCpuNumber;
            nextCpuNumber = nextCpuNumber + 1;
        } else {
            gRaceSetup->mNextEntries[i].mPlayer.mNumber = -1;
        }
    }
    gRaceSetup->mNextCpuNumber = nextCpuNumber;
}

u32 func_02046524(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

void BuildCourseList(s32 isVersus) {
    s32 f;
    u32 m;
    const u32 *t;
    u32 i;
    u32 n;
    f = 0;
    ResetCupRecords();
    gRaceSetup->mCourseListIndex = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    if (isVersus != 0) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else if (data_021759d0->mUnk_1c_2) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceSetup->mNextHeader.mRaceKind = 4;
    }
    for (i = 0; i < 0x21; i++) {
        gRaceSetup->mCourseList[i] = 0;
    }
    switch (data_021759d0->mUnk_20) {
        case 1:
        case 2:
            f = (data_0217aa00->mUnk_0454 & 0x40) != 0;
            break;
    }
    switch (gRaceSetup->mNextHeader.mCourseListMode) {
        case 1:
            if (isVersus != 0) {
                u8 p;
                u8 q;
                u32 n;
                s32 e;
                s32 c;
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                e = gRaceSetup->mNextHeader.mCourseId;
                n = m * 4;
                for (f = 0; f < n; f++) {
                    p = f / 4;
                    q = f % 4;
                    if (e == gCupCourseIdTable[t[p]][q]) {
                        break;
                    }
                }
                c = 0;
                for (f = 0; f < n; f++) {
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceSetup->mCourseList[c] = gCupCourseIdTable[t[p]][q];
                        c = (u8) (c + 1);
                    }
                    q = q + 1;
                    if (q >= 4) {
                        q = 0;
                        p = p + 1;
                        if (p >= m) {
                            p = 0;
                        }
                    }
                }
                return;
            } else {
                s32 e;
                u32 s;
                n = f != 0 ? 3 : 6;
                s = 0;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                e = gRaceSetup->mNextHeader.mCourseId;
                for (i = 0; i < n; i++) {
                    s = i;
                    if (e == t[i]) {
                        break;
                    }
                }
                for (i = 0; i < n; i++) {
                    gRaceSetup->mCourseList[i] = t[s];
                    s++;
                    if (s >= n) {
                        s = 0;
                    }
                }
                return;
            }
        case 2:
            if (isVersus != 0) {
                RandomState64 *g;
                u32 n;
                s32 k;
                s32 c;
                u8 q;
                u8 p;
                u8 w;
                u8 x;
                u8 y;
                s32 h;
                s32 z;
                g = GetRandomState();
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                n = m * 4;
                c = 0;
                for (k = 0; k < n; k++) {
                    p = k / 4;
                    q = k % 4;
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceSetup->mCourseList[c] = gCupCourseIdTable[t[p]][q];
                        c = (u8) (c + 1);
                    }
                }
                h = c * 2;
                for (z = 0; z < h; z++) {
                    w = func_02046524(g, (vu16) (c - 1));
                    x = z % c;
                    y = gRaceSetup->mCourseList[x];
                    if (w >= x) {
                        w = w + 1;
                    }
                    gRaceSetup->mCourseList[x] = gRaceSetup->mCourseList[w];
                    gRaceSetup->mCourseList[w] = y;
                }
            } else {
                s32 k;
                RandomState64 *g;
                g = GetRandomState();
                n = f != 0 ? 3 : 6;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                for (k = 0; k < n; k++) {
                    gRaceSetup->mCourseList[k] = t[k];
                }
                k = 0;
                if (k < n) {
                    m = (u16) (n - 1);
                    for (; k < n; k++) {
                        u8 w;
                        u8 y;
                        w = func_02046524_inline(g, m);
                        y = gRaceSetup->mCourseList[k];
                        if (w >= k) {
                            w = w + 1;
                        }
                        gRaceSetup->mCourseList[k] = gRaceSetup->mCourseList[w];
                        gRaceSetup->mCourseList[w] = y;
                    }
                }
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[0];
            break;
    }
}

void func_02045ed0(void) {
    u8 i;
    u8 humanIndex;
    AssignCpuNumbers();
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            ResetCupRecords();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            gRaceSetup->mNextHeader.mCourseId =
                gCupCourseIdTable[gRaceSetup->mNextHeader.mCupIndex][gRaceSetup->mNextHeader.mCourseNumber - 1];
            break;
        case MODE_VS:
            BuildCourseList(1);
            break;
        case MODE_BATTLE:
            BuildCourseList(0);
            break;
        case 5:
            humanIndex = 0xff;
            ResetCupRecords();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            for (i = 0; i < 4; i++) {
                if (gRaceSetup->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    humanIndex = i;
                    break;
                }
            }
            gRaceSetup->mNextHeader.mFollowedKartIndex = humanIndex;
            break;
        case MODE_MISSION_RUN:
            ResetCupRecords();
            if (gRaceSetup->mNextHeader.mMissionTableColumn == 9) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            } else {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            }
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            break;
    }
}

BOOL func_02045bd4(void) {
    s8 entryIndex;
    u8 i;
    s8 j;
    u8 courseIndexInCup;
    u32 lowByte;
    s32 rankIndex;
    KartCourseResult *courseResult;
    entryIndex = gRaceSetup->mEntryIndex;
    data_0217b488->mCupRankIndex = GetKartCupRank((u16) entryIndex) - 1;
    data_0217b488->mUnk_80 = func_0205d190();
    data_0217b488->mCharacterIndex = gRaceSetup->mCurrentEntries[(u8) entryIndex].mCharacterIndex;
    data_0217b488->mCupIndex = gRaceSetup->mCupIndex;
    data_0217b488->mEngineIndex = gRaceSetup->mEngineIndex;
    data_0217b488->mMirrorMode = gRaceSetup->mMirrorMode;
    lowByte = GetLowByte((u8) entryIndex);
    courseIndexInCup = GetCourseIndexInCup();
    courseResult = &gCupRecords->mUnk_000[courseIndexInCup][GetLowByte(lowByte)];
    data_0217b488->mTotalPoints = courseResult->mTotalPoints;
    data_0217b488->mKartIndex = gRaceSetup->mCurrentEntries[(u8) entryIndex].mKartIndex;
    for (i = 0; i < 4; i++) {
        Unk0217aa1c_144_00 finishTime;
        GetKartCourseFinishTime(&finishTime, (u16) gRaceSetup->mEntryIndex, i);
        data_0217b488->mCourseTimes[i] = finishTime;
    }
    if ((u32) GetKartCupRank((u16) gRaceSetup->mEntryIndex) > 3) {
        return FALSE;
    }
    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gRaceSetup->mKartCount; j++) {
            if (GetKartCupRank((u16) j) == i + 1) {
                break;
            }
        }
        SetNextRaceEntry(i, gRaceSetup->mCurrentEntries[(u16) j].mCharacterIndex,
                         gRaceSetup->mCurrentEntries[(u16) j].mKartIndex, PLAYER_KIND_CPU, -1, 3);
    }
    for (; i < 8; i++) {
        SetNextRaceEntry(i, i, i * 3, PLAYER_KIND_NONE, -1, 3);
    }
    for (i = 0; i < 8; i++) {
        rankIndex = GetKartCupRank(i) - 1;
        data_0217b488->mUnk_cc[rankIndex] = gRaceSetup->mCurrentEntries[i].mKartIndex;
        data_0217b488->mUnk_ac[rankIndex] = gRaceSetup->mCurrentEntries[i].mCharacterIndex;
    }
    gRaceSetup->mNextHeader.mFollowedKartIndex = GetKartCupRank((u16) gRaceSetup->mEntryIndex) - 1;
    return TRUE;
}

void SetupStaffRollRace(s32 useTrueStaffRoll) {
    u8 i;
    s8 j;
    s32 characterIndex;
    s32 kartIndex;
    if (useTrueStaffRoll != 0) {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLLTRUE;
    } else {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLL;
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
    gRaceSetup->mNextHeader.mEngineIndex = 1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < gRaceSetup->mKartCount; j++) {
            if (GetKartCupRank((u16) j) == i + 1) {
                break;
            }
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            if ((gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1) == 6 &&
                (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
                if (i == 0) {
                    characterIndex = 7;
                    kartIndex = 0x15;
                } else if (i == 7) {
                    characterIndex = 0;
                    kartIndex = characterIndex;
                } else {
                    characterIndex = i;
                    kartIndex = i * 3;
                }
            } else {
                characterIndex = i;
                kartIndex = i * 3;
            }
        } else if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (func_020909cc() != 2) {
                characterIndex = i;
                kartIndex = i * 3;
            } else {
                characterIndex = data_0217b488->mUnk_ac[i];
                kartIndex = data_0217b488->mUnk_cc[i];
            }
        } else {
            characterIndex = i;
            kartIndex = i * 3;
        }
        SetNextRaceEntry(i, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, 3);
    }
}

s32 AdvanceToNextCourse(void) {
    BOOL result;
    s32 i;
    s32 v;
    s32 x;
    result = TRUE;
    gRaceSetup->mNextHeader.mCourseNumber++;
    if (gRaceSetup->mUnk_3d4 > 1) {
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            x = gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_08;
            v = 3;
            if (x != 0) {
                if (x == 1) {
                    v = 0;
                }
            } else {
                v = 1;
            }
            gRaceSetup->mNextEntries[i].mPlayer.mUnk_08 = v;
        }
    }
    switch (gRaceSetup->mCourseListMode) {
        case 0:
            result = FALSE;
            break;
        case 1:
        case 2:
            gRaceSetup->mCourseListIndex++;
            if (gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex] == 0) {
                gRaceSetup->mCourseListIndex = 0;
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex];
            break;
    }
    return result;
}

s32 func_02045914(void) {
    return AdvanceToNextCourse();
}

s32 func_020458cc(void) {
    if (data_021759d0->mUnk_1c_2) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceSetup->mNextHeader.mRaceKind = 4;
    }
    return AdvanceToNextCourse();
}

BOOL func_02045874(void) {
    data_0217b488->mUnk_5c[gRaceSetup->mCourseNumber] = gRaceSetup->mCourseId;
    gRaceSetup->mNextHeader.mCourseNumber++;
    return gRaceSetup->mNextHeader.mCourseNumber <= 4;
}
