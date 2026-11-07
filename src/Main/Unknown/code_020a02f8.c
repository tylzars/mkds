#include "Main/Unknown/code_020a02f8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02068000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a1728.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020a22ac.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_02077bc0.h"

void SetStandingsKartBalloons(KartBalloons *p0) {
    gStandings->mKartBalloons = p0;
}

KartBalloons *GetStandingsKartBalloons(void) {
    return gStandings->mKartBalloons;
}

void SetStandingsKartHitByKartCallback(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) gStandings)) + 896) = p0;
}

void SetStandingsKartsHitEachOtherCallback(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) gStandings)) + 900) = p0;
}

void SetStandingsKartHitCallback(s32 (*p0)(u16 a, u16 b)) {
    gStandings->mKartHitCallback = p0;
}

// Stores the kart-eliminated callback.
void SetStandingsKartEliminatedCallback(void (*p0)(u16 a)) {
    gStandings->mKartEliminatedCallback = p0;
}

// Stores the end callback.
void SetStandingsEndCallback(void (*a)(void)) {
    gStandings->mEndCallback = a;
}

void SetStandingsKartOffsetCallback(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) gStandings)) + 924) = p0;
}

void func_020a22ac(u16 a) {
    if (IsRaceStarted() != 1) {
        return;
    }
    if (func_01ffc67c(GetKart(a)) != FALSE) {
        return;
    }
    gStandings->mKarts[a].mUnk_64 = 10;
}

void func_020a228c(int a) {
    *(u32 *) (a * 0x70 + (u32) gStandings + 100) = 0xffffffff;
}

s32 func_020a2264(u16 a) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[a].mUnk_64;
}

s32 func_020a223c(u16 a) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[a].mUnk_68;
}

void func_020a2220(u16 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &gStandings;
    value2 = 0x70u;
    value3 = *(const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    *(u32 *) ((value2) + (108)) = value1;
}

u32 func_020a2204(u16 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStandings;
    value1 = 0x70u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (108));
    return value0;
}

void func_020a21bc(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (gStandings->mKartOffsetCallback != NULL) {
        gStandings->mKartOffsetCallback(a, b);
    }
}

s32 func_020a1ee4(s32 a, s32 b) {
    Kart *v1;
    Kart *v2;
    KartStanding *v3;
    KartStanding *v4;
    BOOL f5;
    s32 f4;
    BOOL f11;
    BOOL t;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    v1 = GetKart(a);
    v2 = GetKart(b);
    v4 = &gStandings->mKarts[b];
    v3 = &gStandings->mKarts[a];
    f5 = FALSE;
    if (v4->mUnk_24[a] == 0) {
        if ((v1->mUnk_48 & 0x100000) != 0) {
            f5 = TRUE;
        }
    }
    f4 = 0;
    if (v3->mUnk_24[b] == 0) {
        if ((v2->mUnk_48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = TRUE;
    if ((v1->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(a) != 1) {
            f11 = FALSE;
        }
    }
    t = TRUE;
    if ((v2->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(b) != 1) {
            t = FALSE;
        }
    }
    if (f4 != 0) {
        v3->mUnk_24[b] = 1;
    }
    if (f5 != FALSE) {
        v4->mUnk_24[a] = 1;
    }
    if (f11 == FALSE && t == FALSE && f5 != FALSE && f4 != 0) {
        if (gStandings->mKartsHitEachOtherCallback != NULL) {
            gStandings->mKartsHitEachOtherCallback(a, b);
            return 1;
        }
    } else if (f11 == FALSE && f4 != 0) {
        f4 = 0;
        if (func_0207a8a4(b) == 1) {
            v3->mUnk_20 = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                f4 = gStandings->mKartHitByKartCallback(a, b);
                if ((v1->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v1);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            f4 = gStandings->mKartHitByKartCallback(a, b);
            if ((v1->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v1);
            }
        }
        return f4;
    } else if (t == FALSE && f5 != FALSE) {
        f4 = 0;
        if (func_0207a8a4(a) == 1) {
            v4->mUnk_20 = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                f4 = gStandings->mKartHitByKartCallback(b, a);
                if ((v2->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v2);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            f4 = gStandings->mKartHitByKartCallback(b, a);
            if ((v2->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v2);
            }
        }
        return f4;
    }
    return 0;
}

void func_020a1e40(s32 a, ItemObject *p) {
    u16 v;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (GetKart(a)->mState == KART_STATE_NORMAL) {
        return;
    }
    if (p->mKind != 0 && p->mKind != 1 && p->mKind != 9) {
        return;
    }
    v = p->mUnk_78;
    if ((v & 0x8000) != 0) {
        return;
    }
    gStandings->mKarts[a].mUnk_44 = v & ~0xff00;
}

u32 func_020a1e3c(u32 p0) {
    return p0;
}

void func_020a1ddc(s32 a) {
    s32 i;
    s32 n;

    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        gStandings->mKarts[i].mUnk_24[a] = 0;
    }
}

static inline u16 func_020a1790_inline(Standings *d, s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == d->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

u16 func_020a1cd8(s32 a) {
    s32 v;
    s32 i;
    s32 v1;

    if (data_021759c0->mMode == MODE_BATTLE) {
        if (data_021759c0->mUnk_18 == 0) {
            v = 3 - gStandings->mKarts[a].mBalloonOrShineCount;
            v += 1;
        } else if (data_021759c0->mUnk_18 == 1) {
            v1 = 1;
            for (i = 0; i < data_021759c0->mKartCount; i++) {
                if (gStandings->mKarts[i].mBalloonOrShineCount > v1) {
                    v1 = gStandings->mKarts[i].mBalloonOrShineCount;
                }
            }
            v = (v1 + 1 - gStandings->mKarts[a].mBalloonOrShineCount) / 2 + 1;
        } else {
            v = a;
        }
    } else {
        v = 3 - gStandings->mKarts[a].mBalloonOrShineCount;
        v += 1;
    }
    if (v < 1) {
        v = 1;
    } else if (v > 3) {
        v = 3;
    }
    return v;
}

void MoveKartTowardFirstRankAndRefreshCountRange(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    KartStanding *e0;
    u16 r1;
    u16 r0;
    KartStanding *e1;

    for (i = gStandings->mKarts[a].mRankIndex - 1; i >= 0; i--) {
        e1 = &gStandings->mKarts[func_020a1790_inline(gStandings, i)];
        r1 = e1->mRankIndex;
        r0 = gStandings->mKarts[a].mRankIndex;
        e0 = &gStandings->mKarts[a];
        if (r0 > r1) {
            if (e0->mBalloonOrShineCount > e1->mBalloonOrShineCount ||
                (e0->mEliminationStatus == 0 && e1->mEliminationStatus != 0)) {
                e1->mRankIndex = r0;
                gStandings->mKarts[a].mRankIndex = r1;
            }
        }
    }
    n = data_021759c0->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < n; j++) {
        v = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount =
            (v < gStandings->mLowestBalloonOrShineCount && v >= 0) ? v : gStandings->mLowestBalloonOrShineCount;
        v = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (v > gStandings->mHighestBalloonOrShineCount) ? v : gStandings->mHighestBalloonOrShineCount;
    }
}

void MoveKartTowardLastRankAndRefreshCountRange(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    KartStanding *e0;
    u16 r1;
    u16 r0;
    KartStanding *e1;

    for (i = gStandings->mKarts[a].mRankIndex + 1; i < 8; i++) {
        e1 = &gStandings->mKarts[func_020a1790_inline(gStandings, i)];
        r1 = e1->mRankIndex;
        r0 = gStandings->mKarts[a].mRankIndex;
        e0 = &gStandings->mKarts[a];
        if (r0 < r1) {
            if (e0->mBalloonOrShineCount < e1->mBalloonOrShineCount ||
                (e0->mEliminationStatus != 0 && e1->mEliminationStatus == 0)) {
                e1->mRankIndex = r0;
                gStandings->mKarts[a].mRankIndex = r1;
            }
        }
    }
    n = data_021759c0->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < n; j++) {
        v = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount =
            (v < gStandings->mLowestBalloonOrShineCount && v >= 0) ? v : gStandings->mLowestBalloonOrShineCount;
        v = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (v > gStandings->mHighestBalloonOrShineCount) ? v : gStandings->mHighestBalloonOrShineCount;
    }
}

// Takes one kart out of play: runs the kart-eliminated callback, sets its status to 1, in mode 2 sets its count to -1,
// re-sorts the ranks and starts the mode's out handling of the kart (mode 2: a kart handler call; mode 4: two bits in
// the kart's words).
void EliminateKart(u16 a) {
    Kart *c;

    if (gStandings->mKartEliminatedCallback != NULL) {
        gStandings->mKartEliminatedCallback(a);
    }
    gStandings->mKarts[a].mEliminationStatus = 1;
    if (data_021759c0->mMode == MODE_BATTLE) {
        gStandings->mKarts[a].mBalloonOrShineCount = -1;
        gStandings->mKarts[a].mUnk_50 = 0;
    }
    if ((u32) a >= data_021759c0->mKartCount) {
        return;
    }
    MoveKartTowardLastRankAndRefreshCountRange(a);
    if (data_021759c0->mMode == MODE_BATTLE) {
        func_02068b5c(GetKart(a));
    } else if (data_021759c0->mMode == MODE_MISSION_RUN) {
        c = GetKart(a);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
}

void SetWinnerAndEndTimerWhenOneTeamRemains(void) {
    s32 n;
    s32 v;
    s32 i;
    s32 j;
    s32 v1;
    s32 k;
    u16 x;
    Standings *d;
    KartStanding *e;
    Kart *c;

    n = data_021759c0->mKartCount;
    d = gStandings;
    for (k = 0; k < 8; k++) {
        if (d->mKarts[k].mRankIndex == 0) {
            x = k;
            goto found;
        }
    }
    x = 0;
found:
    v = d->mKarts[x].mTeamId;
    e = d->mKarts;
    for (j = 0; j < 8; j++, e++) {
        if (e->mEliminationStatus == 0) {
            if (v != e->mTeamId) {
                return;
            }
        }
    }
    for (i = 0; i < n; i++) {
        c = GetKart((u16) i);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
    gStandings->mWinnerTeamId = v;
    if (data_021759c0->mMode == MODE_BATTLE) {
        if (data_021759c0->mUnk_18 == 1) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4a);
        }
        gStandings->mEndTimer = 0x5a;
    } else if (data_021759c0->mMode == MODE_MISSION_RUN) {
        v1 = data_021759c0->mEntryIndex;
        if (gStandings->mWinnerTeamId == v1) {
            func_0203e74c(v1);
        } else {
            func_0203cd04(v1);
        }
        gStandings->mEndTimer = 0;
    }
}

void func_020a1748(u16 a) {
    KartStanding *e;

    e = &gStandings->mKarts[a];
    e->mUnk_1c = -2;
    e->mUnk_18 = -2;
    e->mUnk_44 = a;
    gStandings->mKartHitCallback(a, a);
}

void func_020a1728(int a) {
    *(u32 *) (a * 0x70 + (u32) gStandings + 8) = 0;
}

static inline u16 func_020a12b8_inline(s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == gStandings->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

void EliminateKartAndCheckWinner(u16 a) {
    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gStandings->mKarts[a].mEliminationStatus != 0) {
        return;
    }
    EliminateKart(a);
    SetWinnerAndEndTimerWhenOneTeamRemains();
}

u16 func_020a1520(void) {
    NNSSndSeqPlayer **h;
    s32 v;
    u16 k;
    s32 i;
    s32 m;
    s32 n;
    s32 a;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    v = gStandings->mUnk_3a4 + 1;
    if (v >= 3) {
        v = 3;
    }
    gStandings->mUnk_3a4 = v;
    gStandings->mUnk_3a2 = data_021565f0[gStandings->mUnk_3a4];
    a = gStandings->mLowestBalloonOrShineCount;
    if (a != gStandings->mHighestBalloonOrShineCount) {
        n = data_021759c0->mKartCount;
        for (m = 0; m <= a; m++) {
            for (i = n - 1; i >= 0; i--) {
                k = func_020a12b8_inline(i);
                if (m == gStandings->mKarts[k].mBalloonOrShineCount) {
                    EliminateKart(k);
                }
            }
            SetWinnerAndEndTimerWhenOneTeamRemains();
            if (gStandings->mWinnerTeamId >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        h = func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (h[0] != NULL) {
                NNS_SndPlayerStopSeq(h, 0);
            }
            if (h[0] != NULL) {
                NNS_SndPlayerStopSeq(h, 0);
            }
            NNS_SndArcPlayerStartSeqArc(h, 0, 0x4b);
        }
    }
    return gStandings->mUnk_3a2;
}

void EliminateKartsUntilWinnerDecided(void) {
    s32 n;
    s32 i;
    u16 k;
    s32 m;
    u16 s;
    Unk020f41c4_B *r;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        n = data_021759c0->mKartCount;
        if (data_021759c0->mUnk_18 == 0) {
            if (gStandings->mWinnerTeamId >= 0) {
                return;
            }
            s = n;
            do {
                r = &gRaceProgress->mRandom;
                if ((u16) n == 0) {
                    m = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    if (s == 0) {
                        m = (u32) (r->mUnk_00 >> 32);
                    } else {
                        m = (u32) (((u64) (u32) (r->mUnk_00 >> 32) * (u64) s) >> 32);
                    }
                }
                k = m;
                if (gStandings->mKarts[k].mEliminationStatus == 0) {
                    EliminateKartAndCheckWinner(k);
                    gStandings->mKarts[k].mEliminationStatus = 2;
                }
            } while (gStandings->mWinnerTeamId < 0);
        } else if (data_021759c0->mUnk_18 == 1) {
            for (i = n - 1; i >= 0; i--) {
                if (gStandings->mWinnerTeamId < 0) {
                    k = func_020a12b8_inline(i);
                    if (gStandings->mKarts[k].mEliminationStatus == 0) {
                        EliminateKartAndCheckWinner(k);
                        gStandings->mKarts[k].mEliminationStatus = 2;
                    }
                }
            }
        }
    } else if (data_021759c0->mMode == MODE_MISSION_RUN) {
        for (i = 7; i >= 0; i--) {
            k = func_020a12b8_inline(i);
            if (k != data_021759c0->mEntryIndex && gStandings->mWinnerTeamId < 0) {
                EliminateKartAndCheckWinner(k);
            }
        }
    }
}

u32 IsWinnerDecidedAndEndReached(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    s32 compareLeft0;
    s32 compareRight0;
    s32 compareLeft1;
    s32 compareRight1;
    value1 = (u32) &gStandings;
    value0 = 0u;
    value2 = *(const u32 *) ((value1) + (0));
    value1 = *(const u32 *) ((value2) + (948));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 < compareRight0) {
        return value0;
    }
    value1 = *(const u32 *) ((value2) + (936));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 < compareRight1) {
        value0 = 1u;
    }
    return value0;
}

// TRUE when mWinnerTeamId is not negative.
BOOL IsWinnerDecided(void) {
    if (gStandings->mWinnerTeamId >= 0) {
        return TRUE;
    }
    return FALSE;
}

// Returns the kart's mRankIndex.
u16 GetKartStandingRankIndex(int arg0) {
    return gStandings->mKarts[arg0].mRankIndex;
}

// Returns mShineCount.
u32 GetShineCount(void) {
    return (gStandings->mShineCount);
}

// Adds its argument to mShineCount (+1 when a shine is placed, -1 when one is finished).
void AddShineCount(short a) {
    Standings *v1;
    v1 = gStandings;
    v1->mShineCount = v1->mShineCount + a;
}

u16 GetTotalBalloonOrShineCount(void) {
    s32 i;
    s32 v1;
    s32 n;
    s32 v;

    v1 = 0;
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        v = gStandings->mKarts[(u16) i].mBalloonOrShineCount;
        if (v <= 0) {
            v = 0;
        }
        v1 += (u16) v;
    }
    return v1;
}

u16 GetHighestBalloonOrShineCount(void) {
    return gStandings->mHighestBalloonOrShineCount;
}

// Returns the kart's count, 0 when it is negative.
u16 GetBalloonOrShineCount(u16 a) {
    s32 v;

    v = gStandings->mKarts[a].mBalloonOrShineCount;
    if (v <= 0) {
        v = 0;
    }
    return v;
}

void AddBalloonOrShineCountAndMoveRank(u16 a, s32 b) {
    gStandings->mKarts[a].mBalloonOrShineCount += b;
    if (b > 0) {
        MoveKartTowardFirstRankAndRefreshCountRange(a);
    } else if (b < 0) {
        MoveKartTowardLastRankAndRefreshCountRange(a);
    }
}

u16 func_020a10d4(u16 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStandings;
    value1 = 0x70u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u16 *) ((value1) + (80));
    return value0;
}

void func_020a10ac(u16 a, s32 b) {
    gStandings->mKarts[a].mUnk_50 += b;
}

// TRUE when the kart's elimination status is not 0.
BOOL IsKartEliminated(int a) {
    if (gStandings->mKarts[a].mEliminationStatus != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 IsKartAtLowestBalloonOrShineCountBelowHighest(u16 a) {
    Standings *d;
    BOOL r;
    s32 v;

    d = gStandings;
    r = FALSE;
    v = d->mKarts[a].mBalloonOrShineCount;
    if (d->mLowestBalloonOrShineCount == v) {
        if (d->mHighestBalloonOrShineCount != v) {
            r = TRUE;
        }
    }
    return r;
}

s32 IsKartOnWinningTeamAtEnd(s32 a) {
    KartStanding *e;
    BOOL r;

    e = &gStandings->mKarts[a];
    r = FALSE;
    if (gStandings->mWinnerTeamId == e->mTeamId) {
        if (gStandings->mEndTimer < 0) {
            r = TRUE;
        }
    }
    return r;
}

// Returns the address of the kart's saved position (mKarts[i].mPos), not its rank.
Vec3 *GetKartStandingPos(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStandings;
    value1 = 0x70u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0xcu);
    return (Vec3 *) value0;
}

Unk02175620_84 *MoveToRandomForwardBattlePoint(void) {
    Unk020f41c4_B *a;
    u16 v;
    s32 w;

    a = &gRaceProgress->mRandom;
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    v = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 5) >> 32) + 1;
    w = gStandings->mUnk_3b8 + v;
    if (w >= gCourseMap->mBattlePointCount) {
        w = 0;
    }
    gStandings->mUnk_3b8 = w;
    return &gCourseMap->mBattlePoints[gStandings->mUnk_3b8];
}

// Allocates the Standings object and fills every entry (rank = own index, side id, status, count; the real karts first,
// then the unused slots) and sets the winner to -1. Called from InitRace in modes 2 and 4.
void InitStandings(void) {
    s32 i;
    KartStanding *e;

    gStandings = HeapAlloc(GetHeap(func_020364e8()), 0x3c0);
    for (i = 0; i < 8; i++) {
        e = &gStandings->mKarts[i];
        e->mUnk_1c = -2;
        e->mUnk_18 = -2;
        e->mUnk_44 = i;
        e->mRankIndex = i;
        if (i < data_021759c0->mKartCount) {
            switch (data_021759c0->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                case 0:
                    e->mTeamId = 1;
                    break;
                case 1:
                    e->mTeamId = 3;
                    break;
                default:
                    e->mTeamId = i;
                    break;
            }
            e->mEliminationStatus = 0;
            e->mBalloonOrShineCount = 0;
            e->mUnk_50 = 0;
        } else {
            e->mEliminationStatus = 2;
            e->mBalloonOrShineCount = -1;
            e->mUnk_50 = 0;
            e->mTeamId = data_021759c0->mKartCount;
        }
    }
    gStandings->mWinnerTeamId = -1;
}

void FinishStandings(void) {
    gStandings->mEndTimer = -1;
    if (gStandings->mEndCallback != NULL) {
        gStandings->mEndCallback();
    }
}

void UpdateStandings(void) {
    Kart *o;
    BOOL a;
    BOOL b;
    s32 v;
    u32 f;
    s32 i;
    s32 n;
    KartStanding *e = gStandings->mKarts;

    n = data_021759c0->mKartCount;
    if (gStandings->mWinnerTeamId >= 0) {
        if (gStandings->mEndTimer > 0) {
            gStandings->mEndTimer = gStandings->mEndTimer - 1;
            if (gStandings->mEndTimer <= 0) {
                gStandings->mEndTimer = -1;
                if (gStandings->mEndCallback != NULL) {
                    gStandings->mEndCallback();
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (gStandings->mKarts[i].mEliminationStatus == 1) {
                if (i != data_021759c0->mEntryIndex) {
                    func_02068a00(GetKart((u16) i));
                }
                gStandings->mKarts[i].mEliminationStatus = 2;
            }
        }
        return;
    }
    for (i = n - 1; i >= 0; i--) {
        e = &gStandings->mKarts[i];
        if (e->mEliminationStatus == 1) {
            func_02068a00(GetKart((u16) i));
            gStandings->mKarts[i].mEliminationStatus = 2;
        } else if (gStandings->mWinnerTeamId < 0 && e->mBalloonOrShineCount > 0) {
            o = GetKart((u16) i);
            e = &gStandings->mKarts[i];
            v = e->mUnk_64 - 1;
            if (v <= 0) {
                v = 0;
            }
            e->mUnk_64 = v;
            gStandings->mKarts[i].mUnk_68 = -(gStandings->mKarts[i].mUnk_68 <= 0);
            if (func_01ffc67c(o) != FALSE || (u16) (data_02175628[o->mEntryIndex].mBits & 3) != 0) {
                gStandings->mKarts[i].mUnk_68 = -1;
                gStandings->mKarts[i].mUnk_64 = -1;
            } else if (IsRaceStarted() == 1) {
                if ((u16) (data_02175628[(u32) o->mEntryIndex].mBits & 4) != 0) {
                    gStandings->mKarts[i].mUnk_68 = 1;
                } else if (data_02175628[o->mEntryIndex].mUnk_5a != 0) {
                    gStandings->mKarts[i].mUnk_64 = 10;
                }
            }
            if (gStandings->mKartHitCallback != NULL) {
                b = TRUE;
                f = o->mUnk_48;
                a = (f & 0x200) != 0;
                if (o->mState == KART_STATE_NORMAL && (f & 0x4000000) == 0) {
                    b = FALSE;
                }
                if (e->mUnk_04 == FALSE && a != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_04 = TRUE;
                    e->mUnk_00 = FALSE;
                    e->mUnk_18 = -2;
                    e->mUnk_44 = i;
                    e->mUnk_20 = FALSE;
                    if (e->mBalloonOrShineCount <= 1) {
                        if ((data_021759c0->mMode == MODE_BATTLE && data_021759c0->mUnk_18 == 0) ||
                            data_021759c0->mMode == MODE_MISSION_RUN) {
                            o->mUnk_7c |= 0x20000000;
                            o->mUnk_48 &= ~0x2000000;
                        }
                    }
                } else if (e->mUnk_04 == TRUE && (o->mUnk_44 & 0x10000) != 0) {
                    e->mUnk_04 = FALSE;
                    e->mUnk_1c = 0;
                    if ((o->mUnk_4c & 0x400000) == 0) {
                        func_0206c17c(o);
                    }
                }
                if (e->mUnk_1c == 0) {
                    e->mUnk_1c = -2;
                    gStandings->mKartHitCallback(i, 8);
                    e->mUnk_44 = i;
                } else if (e->mUnk_1c >= 0) {
                    e->mUnk_1c = e->mUnk_1c + 1;
                }
                if (e->mUnk_00 == FALSE && b != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_00 = TRUE;
                    if (e->mBalloonOrShineCount <= 1) {
                        if ((data_021759c0->mMode == MODE_BATTLE && data_021759c0->mUnk_18 == 0) ||
                            data_021759c0->mMode == MODE_MISSION_RUN) {
                            o->mUnk_7c |= 0x20000000;
                        }
                    }
                } else if (e->mUnk_00 == TRUE && b == FALSE && (o->mUnk_48 & 0x6052840) == 0) {
                    e->mUnk_00 = FALSE;
                    if (e->mUnk_20 == FALSE) {
                        e->mUnk_18 = 0;
                        if ((o->mUnk_4c & 0x400000) == 0) {
                            func_0206c17c(o);
                        }
                    } else {
                        e->mUnk_20 = FALSE;
                    }
                }
                if (e->mUnk_18 == 0) {
                    e->mUnk_18 = -2;
                    gStandings->mKartHitCallback(i, e->mUnk_44);
                    e->mUnk_44 = i;
                } else if (e->mUnk_18 >= 0) {
                    e->mUnk_18 = e->mUnk_18 + 1;
                }
            }
            e->mPos = o->mPos;
        }
    }
}

void func_020a089c(Unk020a0318 *p) {
    s32 v;

    v = data_021759c0->mCourseId;
    if (v == COURSE_ID_MANSION) {
        p->mUnk_bc = 0x121;
    } else if (v == COURSE_ID_BEACH) {
        p->mUnk_bc = 0x111;
        p->mUnk_be = 0x10a;
    } else {
        p->mUnk_bc = 0x20d;
    }
}

void func_020a066c(Unk020a066c *p) {
    s32 i;
    Unk020a0318 *o;
    Unk020f41c4_B *a;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        if (data_021759c0->mCourseId == COURSE_ID_MANSION) {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mPos.x + 0x73a000;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z - 0x1400000;
            o->mUnk_b8 = TRUE;
        } else if (data_021759c0->mCourseId == COURSE_ID_BEACH) {
            o->mUnk_a8 = 0x546;
            o->mUnk_ac = o->mUnk_00.mPos.x + 0x28a000;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z - 0x32000;
            o->mUnk_b8 = FALSE;
        } else {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mPos.x;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z;
            o->mUnk_b8 = FALSE;
        }
        a = &gRaceProgress->mLocalRandom;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c8 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x3c) >> 32) + 0x258;
        o->mUnk_a4 = 0x7f000;
        a = &gRaceProgress->mLocalRandom;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c0 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xf) >> 32);
    }
}

void func_020a0318(void *a, Unk020a0318 *p) {
    Kart *o;
    NNSSndSeqPlayer **h;
    Unk020f41c4_B *r;
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    s32 v;
    s32 x;
    s32 w;
    s32 z;
    s32 y;
    s64 d;

    if (p->mUnk_c0-- <= 0) {
        p->mUnk_c0 = 0xf;
        w = p->mUnk_a8;
        x = w / 2;
        o = GetKart((u16) data_021759c0->mEntryIndex);
        y = o->mPos.x - p->mUnk_ac;
        z = o->mPos.z - p->mUnk_b4;
        d = (s64) y * y + (s64) z * z;
        if (d < (s64) x * x) {
            v = 2;
        } else if (d < (s64) (w << 12) * (w << 12)) {
            v = 1;
        } else {
            v = 0;
        }
        p->mUnk_c4 = v;
        if (p->mUnk_b8 != FALSE) {
            p->mUnk_c4 = p->mUnk_c4 == 0;
        }
    }
    if (p->mUnk_c4 > 1) {
        p->mUnk_a4 = 0x7f001;
    } else if (p->mUnk_c4 > 0) {
        p->mUnk_a4 = p->mUnk_a4 + 0x4000;
        if (p->mUnk_a4 > 0x7f000) {
            p->mUnk_a4 = 0x7f000;
        }
    } else {
        p->mUnk_a4 = p->mUnk_a4 - 0x4000;
        if (p->mUnk_a4 < 0) {
            p->mUnk_a4 = 0;
        }
    }
    if (p->mUnk_bc != 0) {
        if (p->mUnk_c4 != 0) {
            if (*func_02108e6c(8) != NULL) {
                o = GetKart((u16) data_021759c0->mEntryIndex);
                p->mUnk_a0 = p->mUnk_a0 - (s32) (((s64) o->mVelocityLengthRatio * 0x1000) >> 12);
                if (p->mUnk_a0 < 0xc000) {
                    p->mUnk_a0 = 0xc000;
                }
            } else if (p->mUnk_c8-- <= 0) {
                h = func_02108e6c(8);
                s1.mUnk_00 = p->mUnk_bc;
                s1.mUnk_04 = NULL;
                s1.mUnk_08 = 4;
                s1.mUnk_0c = func_020d4ef4(NULL);
                func_0210b760(&s1, h);
                r = &gRaceProgress->mLocalRandom;
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                p->mUnk_c8 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x3c) >> 32) + 0x78;
                p->mUnk_a0 = 0x7f000;
            }
        } else if (p->mUnk_c8 > 0) {
            p->mUnk_c8 = p->mUnk_c8 - 1;
        }
        if (*func_02108e6c(8) != NULL) {
            v = p->mUnk_a4 < p->mUnk_a0 ? p->mUnk_a4 : p->mUnk_a0;
            SetSndHandleTrackVolume(func_02108e6c(8), v >> 12);
        }
    }
    if (p->mUnk_be == 0) {
        return;
    }
    if (p->mUnk_c4 != 0) {
        if (*func_02108e6c(9) == NULL) {
            h = func_02108e6c(9);
            s2.mUnk_00 = p->mUnk_be;
            s2.mUnk_04 = NULL;
            s2.mUnk_08 = 4;
            s2.mUnk_0c = func_020d4ef4(NULL);
            func_0210b760(&s2, h);
        }
    }
    if (*func_02108e6c(9) == NULL) {
        return;
    }
    SetSndHandleTrackVolume(func_02108e6c(9), p->mUnk_a4 >> 12);
}

void *func_020a02f8(void) {
    return func_0209bf48(func_020a066c, func_020a0318, NULL);
}
