#include "Main/Unknown/code_0208537c.h"

#include "Main/Unknown/code_0203c5ac.h"
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
#include "Main/Unknown/code_0203c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_020172d0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c8dc.h"

#pragma thumb on

// Picks the row of 'kartAIparam.bin' for the course and the mode; no row in battle and when mUnk_00c is 5 or 6.
void SetKartAiParamRow(void) {
    RaceSetup *p;
    KartAiParamRow *r;
    gKartAiParamRow = NULL;
    p = gRaceSetup;
    if (p->mRaceKind != RACE_KIND_AWARD && p->mMode != MODE_BATTLE && p->mRaceKind != RACE_KIND_STAFF_ROLL) {
        r = func_02047950(data_usa_02165990);
        p = gRaceSetup;
        if (p->mMode == MODE_GRAND_PRIX) {
            r = &r[(p->mCourseId - 1) * 12 + p->mEngineIndex];
        } else {
            r = &r[(p->mCourseId - 1) * 12 + (p->mEngineIndex + 1) * 3];
            switch (p->mUnk_014) {
                case CPU_DIFFICULTY_NORMAL:
                    r++;
                    break;
                case CPU_DIFFICULTY_HARD:
                    r += 2;
                    break;
            }
        }
        gKartAiParamRow = r;
    }
}

void InitKartAiShared(void) {
    u16 i;
    BOOL z;
    s32 m;
    gKartAiShared = HeapAlloc(GetHeap(func_020364e8()), 0x144);
    z = FALSE;
    m = -1;
    for (i = 0; i < 8; i++) {
        gKartAiShared->mRaceProgressScaled[i] = z;
        gKartAiShared->mKartAtRank[i] = m;
        gKartAiShared->mKind1KartByRank[i] = m;
        gKartAiShared->mNonCpuKartByRank[i] = m;
        gKartAiShared->mTableIndex[i] = z;
    }
    gKartAiShared->mUnk_080 = m;
    gKartAiShared->mUnk_084 = m;
    gKartAiShared->mUnk_088 = m;
    gKartAiShared->mUnk_08c = z;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gKartAiShared->mRandom = &gRaceProgress->mLocalRandom;
    } else {
        gKartAiShared->mRandom = &gRaceProgress->mRandom;
    }
    if (gRaceSetup->mKartCount > 1 && gRaceSetup->mKartCount - gRaceSetup->mHumanAndPeerKartCount == 1) {
        gKartAiShared->mUnk_120 = 1;
        gKartAiShared->mUnk_124 = ((u32) gRaceSetup->mHumanAndPeerKartCount >> 1) + 1;
    } else {
        gKartAiShared->mUnk_120 = 0;
        gKartAiShared->mUnk_124 = -1;
    }
    if (gKartAiParamRow != NULL) {
        func_02085bec();
        InitKartAiTableIndices();
        if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            switch (gRaceSetup->mEngineIndex) {
                case 0:
                    gKartAiShared->mUnk_138 = 0;
                    break;
                case 1:
                    gKartAiShared->mUnk_138 = 1;
                    break;
                case 2:
                    gKartAiShared->mUnk_138 = 2;
                    break;
                default:
                    gKartAiShared->mUnk_138 = 1;
                    break;
            }
        } else {
            switch (gRaceSetup->mUnk_014) {
                case CPU_DIFFICULTY_EASY:
                    gKartAiShared->mUnk_138 = 0;
                    break;
                case CPU_DIFFICULTY_NORMAL:
                    gKartAiShared->mUnk_138 = 1;
                    break;
                case CPU_DIFFICULTY_HARD:
                    gKartAiShared->mUnk_138 = 2;
                    break;
                default:
                    gKartAiShared->mUnk_138 = 1;
                    break;
            }
        }
        gKartAiParamRow->mUnk_04 = FX_Div(gKartAiParamRow->mUnk_04, 0x3000);
    }
    InitKartAiNonCpuCounts();
    func_0207fba0();
    InitKartAiTables();
    func_0207c78c();
    if (gRaceSetup->mMode == MODE_BATTLE) {
        SetupBattleKartAiParams();
        SetupBattleItemEntries();
    }
}

void InitKartAiNonCpuCounts(void) {
    u16 j;
    u16 k;
    BOOL f;
    BOOL g;
    Unk021759c0_70 *e;
    j = 0;
    gKartAiShared->mNonCpuKartCount = j;
    for (k = 0; k < 2; k++) {
        gKartAiShared->mTeamNonCpuKartCounts[k] = j;
    }
    for (j = 0; (u32) j < gRaceSetup->mKartCount; j++) {
        if (gRaceSetup->mUseTeams != 0) {
            for (k = 0; k < 2; k++) {
                f = FALSE;
                if (gRaceSetup->mCurrentEntries[j].mPlayer.mKind > 3) {
                } else if ((1 << gRaceSetup->mCurrentEntries[j].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    f = TRUE;
                }
                if (f != FALSE && k == gRaceSetup->mCurrentEntries[j].mPlayer.mTeamIndex) {
                    gKartAiShared->mTeamNonCpuKartCounts[k]++;
                    break;
                }
            }
        } else {
            g = FALSE;
            e = &gRaceSetup->mCurrentEntries[j].mPlayer;
            if (e->mKind <= 3 && ((1 << e->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                g = TRUE;
            }
            if (g != FALSE) {
                gKartAiShared->mNonCpuKartCount++;
            }
        }
    }
}

void func_02085bec(void) {
    u16 i0;
    s32 m0;
    s32 m1;
    s16 i;
    u16 k;
    s32 v;
    BOOL f;
    s32 v1;

    i0 = 0;
    m0 = 0;
    m1 = 0;
    for (; i0 < 2; i0++) {
        gKartAiShared->mUnk_114[i0] = 0;
    }
    gKartAiShared->mUnk_110 = 1;
    gKartAiShared->mUnk_11c = 0;
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            k = i;
            v = GetKartPreviousTotalPoints(k);
            f = FALSE;
            if (gRaceSetup->mCurrentEntries[k].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[k].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                f = TRUE;
            }
            if (f != FALSE) {
                if (v > m0) {
                    m0 = v;
                }
            } else {
                if (v > m1) {
                    m1 = v;
                }
                if (i == gRaceSetup->mUnk_3d5[0]) {
                    gKartAiShared->mUnk_114[0] = v;
                } else if (i == gRaceSetup->mUnk_3d5[1]) {
                    gKartAiShared->mUnk_114[1] = v;
                }
            }
        }
        v1 = m0 - m1;
        if (v1 <= -5) {
            if (gRaceSetup->mUnk_3d4 > 1) {
                gKartAiShared->mUnk_110 = 0;
                if (gKartAiShared->mUnk_114[0] > gKartAiShared->mUnk_114[1]) {
                    gKartAiShared->mUnk_11c = 1;
                }
            }
        } else if (gRaceSetup->mUnk_014 != CPU_DIFFICULTY_EASY && v1 >= 4) {
            gKartAiShared->mUnk_110 = 2;
        }
    }
}

void InitKartAiTableIndices(void) {
    u16 a;
    u16 b;
    u16 i;
    u16 k;
    u16 n;
    u16 q;
    u16 j;
    RaceSetup *p;
    s32 v;
    BOOL f;
    u32 g;
    a = 0;
    b = 0;
    g = gRaceSetup->mKartCount;
    NNS_FndInitList(&gKartAiShared->mTableIndexList, 4);
    for (i = 0; i < 2; i++) {
        if (gRaceSetup->mUnk_3d5[i] >= 0) {
            a++;
        }
    }
    n = gRaceSetup->mKartCount;
    for (k = 0; (u32) k < n; k++) {
        f = FALSE;
        if (gRaceSetup->mCurrentEntries[k].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[k].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            f = TRUE;
        }
        if (f != FALSE) {
            b++;
        }
    }
    q = n - b - a;
    j = 0;
    for (; j < q; j++) {
        gKartAiShared->mTableIndexEntries[j].mTableIndex = (u16) (j + a + 1);
        NNS_FndAppendListObject(&gKartAiShared->mTableIndexList, &gKartAiShared->mTableIndexEntries[j]);
    }
    a = 0;
    p = gRaceSetup;
    for (; (u32) a < p->mKartCount; a++) {
        if (p->mMode == MODE_TIME_ATTACK) {
            v = a;
        } else {
            v = PickKartAiTableIndex(a, &g);
        }
        gKartAiShared->mTableIndex[a] = v;
        p = gRaceSetup;
    }
}

s32 PickKartAiTableIndex(u16 a, u32 *b) {
    s32 r;
    BOOL v1;
    BOOL g;
    BOOL f;
    s32 s;
    s32 m;
    s32 v;
    u16 k;
    NNSFndList *l;
    u16 n;
    u32 h;
    u16 x;
    u16 y;
    KartAiShared *d;
    RaceSetup *p;
    Unk0217aebc_128 *c;
    KartAiTableIndexEntry *e;
    v1 = FALSE;
    r = -1;
    d = gKartAiShared;
    m = d->mUnk_110;
    if (m == 2) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    f = FALSE;
    p = gRaceSetup;
    s = p->mCurrentEntries[a].mPlayer.mKind;
    if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        f = TRUE;
    }
    if (f != FALSE) {
        r = *b;
        *b = r - 1;
    } else {
        if (m == 0) {
            s = d->mUnk_11c;
            if (s != 0) {
                s = 1;
            } else {
                s = 0;
            }
            if (s == 0) {
                v = 1;
            } else {
                v = 0;
            }
            if (a == p->mUnk_3d5[s]) {
                r = 1;
                v1 = TRUE;
            } else if (a == (u16) p->mUnk_3d5[v]) {
                r = 2;
                v1 = TRUE;
            }
        } else {
            for (k = 0; k < 2; k++) {
                s = p->mUnk_3d5[k];
                if (s == a) {
                    if (k == 0) {
                        r = 1;
                    } else {
                        r = 2;
                        if (g != FALSE) {
                            r = 1;
                        }
                    }
                    v1 = TRUE;
                    break;
                }
            }
        }
        if (v1 == FALSE) {
            l = &gKartAiShared->mTableIndexList;
            n = l->mCount;
            c = gKartAiShared->mRandom;
            x = n - 1;
            if (x == 0) {
                h = 0;
            } else {
                c->mUnk_00 = (s64) c->mUnk_08 * (s64) c->mUnk_00 + c->mUnk_10;
                y = (u16) n - 1;
                if (y == 0) {
                    h = c->mUnk_00 >> 32;
                } else {
                    h = (s64) (u32) (c->mUnk_00 >> 32) * (s64) (u32) y >> 32;
                }
            }
            e = NNS_FndGetNthListObject(l, h);
            r = e->mTableIndex;
            NNS_FndRemoveListObject(l, e);
        }
    }
    return r;
}

#pragma thumb off

void DecrementKartAiNonCpuCount(u32 a) {
    RaceSetup *p;
    BOOL f;
    s16 j;
    p = gRaceSetup;
    f = FALSE;
    if (p->mCurrentEntries[a].mPlayer.mKind <= 3 &&
        ((1 << p->mCurrentEntries[a].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        f = TRUE;
    }
    if (f == FALSE) {
        return;
    }
    if (p->mUseTeams != 0) {
        for (j = 0; j < 2; j++) {
            if (j == p->mCurrentEntries[a].mPlayer.mTeamIndex) {
                if (gKartAiShared->mTeamNonCpuKartCounts[j] > 0) {
                    gKartAiShared->mTeamNonCpuKartCounts[j]--;
                }
                break;
            }
        }
    } else {
        if (gKartAiShared->mNonCpuKartCount > 0) {
            gKartAiShared->mNonCpuKartCount--;
        }
    }
}

s16 func_02085824(u32 a) {
    s16 r;
    u16 j;
    r = 0;
    if (gRaceSetup->mUseTeams != 0) {
        for (j = 0; j < 2; j++) {
            if (j != gRaceSetup->mCurrentEntries[a].mPlayer.mTeamIndex) {
                r = r + gKartAiShared->mTeamNonCpuKartCounts[j];
            }
        }
    } else {
        r = gKartAiShared->mNonCpuKartCount;
    }
    return r;
}

void UpdateKartAiShared(void) {
    u32 m;
    u16 i;
    u32 v;
    if (gKartAiParamRow == NULL) {
        return;
    }
    UpdateKartAiRankLists();
    m = 1;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        v = GetKartRank(i);
        if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (v == 1) {
                gKartAiShared->mUnk_088 = i;
            }
            if (v >= m) {
                m = v;
                gKartAiShared->mUnk_084 = i;
            }
        }
    }
}

void UpdateKartAiRankLists(void) {
    s32 m;
    u16 i;
    s32 v;
    s32 w;
    s32 n;
    s32 k;
    s32 x;
    s32 y;
    u16 q;
    BOOL f;
    m = 1;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        w = gCourseMap->mCheckpointSumQuotient;
        x = GetKartRaceProgress(i);
        w = ((s64) x * w + 0x800) >> 12;
        v = GetKartRank(i);
        gKartAiShared->mRaceProgressScaled[i] = w;
        if (v > 0) {
            q = v - 1;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_CPU) {
                if (v > m) {
                    m = v;
                    gKartAiShared->mUnk_080 = i;
                }
            }
            gKartAiShared->mKartAtRank[q] = i;
        }
        if (v == 1) {
            if (w >= 0) {
                gKartAiShared->mUnk_08c = FX_Div(gKartAiShared->mRaceProgressScaled[i], 0x4ce);
                if (gKartAiShared->mUnk_08c < 0x19a) {
                    gKartAiShared->mUnk_08c = 0x19a;
                } else if (gKartAiShared->mUnk_08c > 0x1000) {
                    gKartAiShared->mUnk_08c = 0x1000;
                }
            } else {
                gKartAiShared->mUnk_08c = 0;
            }
        }
    }
    n = 0;
    for (k = 0; k < gRaceSetup->mKartCount; k++) {
        x = gKartAiShared->mKartAtRank[k];
        if (x >= 0) {
            q = x;
            if (gRaceSetup->mCurrentEntries[q].mPlayer.mKind == PLAYER_KIND_CPU) {
                gKartAiShared->mKind1KartByRank[n] = x;
                n++;
            }
        }
    }
    if (gKartAiShared->mUnk_120 == 0) {
        return;
    }
    n = 0;
    for (k = 0; k < gRaceSetup->mKartCount; k++) {
        y = gKartAiShared->mKartAtRank[k];
        if (y >= 0) {
            q = y;
            f = FALSE;
            if (gRaceSetup->mCurrentEntries[q].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[q].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                f = TRUE;
            }
            if (f != FALSE) {
                gKartAiShared->mNonCpuKartByRank[n] = y;
                n++;
            }
        }
    }
}

s32 GetKartRankAmongKind1(u16 a) {
    s32 r;
    u16 i;
    r = -1;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        if (a == (u16) gKartAiShared->mKind1KartByRank[i]) {
            r = i + 1;
            break;
        }
    }
    return r;
}

s32 func_020854a0(u32 p0, u32 p1) {
    return gKartAiShared->mKind1KartByRank[(((p1) + (p0))) - (0x1u)];
}

s32 func_0208548c(void) {
    return gKartAiShared->mUnk_08c;
}

s32 GetFirstKind1KartByRank(void) {
    return gKartAiShared->mKind1KartByRank[0];
}

s32 func_02085458(s32 a) {
    s32 i = a - 2;
    s32 r = -1;

    if (i >= 0) {
        r = gKartAiShared->mKind1KartByRank[i];
    }
    return r;
}

s32 func_02085434(void) {
    return gKartAiShared->mNonCpuKartByRank[((gKartAiShared->mUnk_124)) - (0x1u)];
}

KartAiParamRow *GetKartAiParamRow(void) {
    return gKartAiParamRow;
}

s32 GetKartIndexAtRank(u32 rank) {
    return gKartAiShared->mKartAtRank[(rank) - (0x1u)];
}

u32 GetKartAiTableIndex(u32 p0) {
    return (gKartAiShared->mTableIndex[p0]);
}

u32 func_020853dc(void) {
    return (gKartAiShared->mUnk_138);
}

// Race progress times CourseMap.mUnk_108 as a 1.12 fixed-point product, rounded.
s32 GetKartRaceProgressScaled(u32 a) {
    s32 m;
    s32 v;
    m = gCourseMap->mCheckpointSumQuotient;
    v = GetKartRaceProgress(a);
    return ((s64) v * m + 0x800) >> 12;
}

u32 func_02085390(void) {
    return (gKartAiShared->mUnk_120);
}

Unk0217aebc_128 *GetKartAiRandom(void) {
    return gKartAiShared->mRandom;
}
