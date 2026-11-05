#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/code_02077bc0.h"

Unk02175620_bc *func_02040da8(u32 a) {
    return &gCourseMap->mUnk_b8[gCourseMap->mUnk_34[gCourseMap->mUnk_fc[a]].mUnk_18];
}

s32 func_02040d68(const UnkPair020b502c *a, const UnkPair020b502c *b) {
    return (s32) (((s64) a->mUnk_00 * b->mUnk_00 + (s64) a->mUnk_04 * b->mUnk_04 + 0x800) >> 12);
}

s64 func_02040d24(const UnkPair020b502c *a, const UnkPair020b502c *b) {
    return ((s64) a->mUnk_00 * b->mUnk_00 + (s64) a->mUnk_04 * b->mUnk_04 + 0x800) >> 12;
}

static inline s32 func_02040bc0_inline(s8 i) {
    BOOL f = FALSE;
    if ((u32) data_021759c0->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
        ((1 << data_021759c0->mCurrentEntries[(u16) i].mPlayer.mKind) & 0xd) != 0) {
        f = TRUE;
    }
    return f;
}

BOOL func_02040bc0(void) {
    BOOL r = FALSE;
    BOOL g;
    s8 i = data_021759c0->mEntryIndex;

    if (i == -1 || func_02040bc0_inline(i) == 0) {
        r = TRUE;
    }
    if (r != FALSE) {
        return r;
    }
    switch (data_021759c0->mMode) {
        case MODE_MISSION_RUN:
            g = FALSE;
            switch (gRaceProgress->mUnk_000[(u16) i].mStatus) {
                case 1:
                case 2:
                case 3:
                    g = TRUE;
                    break;
            }
            if (g == FALSE) {
                if (gRaceProgress->mUnk_4e0 != 0) {
                    return r;
                }
            }
            return TRUE;
        case MODE_BATTLE:
            if (gRaceProgress->mRaceDone != 0) {
                r = TRUE;
            }
            return r;
        default:
            g = FALSE;
            switch (gRaceProgress->mUnk_000[(u16) i].mStatus) {
                case 1:
                case 2:
                case 3:
                    g = TRUE;
                    break;
            }
            if (g != FALSE) {
                r = TRUE;
            }
            return r;
    }
}

void func_02040a8c(Unk0217561c_500 *a, s32 b) {
    EntryKartCounters *t = GetEntryKartCounters();
    RaceProgress *d = gRaceProgress;
    RaceProgressKart *e = &d->mKarts[b];
    RankTimeGp *r = d->mRankTimeGpFile;

    if (d->mUnk_000[0].mRankTime == 0) {
        a->mUnk_00 = 0;
    } else {
        a->mUnk_00 = (DivFixed12(r->mUnk_0a * (d->mUnk_000[0].mRankTime - d->mUnk_000[0].mElapsedFrames),
                                 d->mUnk_000[0].mRankTime) +
                      0x800) >>
                     12;
    }
    a->mUnk_04 =
        (r->mUnk_0c * DivFixed12(e->mFirstPlaceFrames << 12, gRaceProgress->mUnk_000[0].mRankTime << 12)) >> 12;
    if (t->mUnk_00 != 0) {
        a->mUnk_08 = r->mUnk_0e;
    } else {
        a->mUnk_08 = 0;
    }
    a->mUnk_0c = r->mUnk_10 * t->mUnk_04;
    a->mUnk_10 = r->mUnk_12 * t->mUnk_08;
    a->mUnk_14 = -((u32) (t->mUnk_0c * ReciprocalFixed12(r->mUnk_14 << 12)) >> 12);
    a->mUnk_18 = t->mUnk_10 * -r->mUnk_16;
    a->mUnk_1c = t->mUnk_14 * -r->mUnk_18;
    a->mUnk_20 = t->mUnk_18 * -r->mUnk_1a;
}

s16 func_020408f0(s32 a) {
    Unk0217561c_500 b;
    EntryKartCounters *t;
    Unk021759c0 *g;
    RaceProgress *d = gRaceProgress;
    Unk0217561c_500 *o = &d->mUnk_500;
    s32 s;
    u8 *h;

    if ((d->mUnk_000[a].mFlags & 1) == 0) {
        return 0;
    }
    g = data_021759c0;
    switch (g->mMode) {
        case MODE_GRAND_PRIX:
            func_02040a8c(&b, a);
            break;
        case MODE_MISSION_RUN:
            h = (u8 *) g + 0x28;
            t = GetEntryKartCounters();
            b.mUnk_00 =
                DivFixed12(*(s16 *) (h + 4) * (*(u16 *) (h + 2) - d->mUnk_000[0].mElapsedFrames) << 12, 0x3e8000) >> 12;
            b.mUnk_04 = 0;
            b.mUnk_08 = 0;
            b.mUnk_0c = 0;
            b.mUnk_10 = t->mUnk_08 * -5;
            b.mUnk_14 = 0;
            b.mUnk_18 = t->mUnk_10 * -5;
            b.mUnk_1c = t->mUnk_14 * -10;
            b.mUnk_20 = t->mUnk_18 * -20;
            break;
        default:
            return 0;
    }
    *o = b;
    s = o->mUnk_00 + o->mUnk_04 + o->mUnk_08 + o->mUnk_0c + o->mUnk_10 + o->mUnk_14 + o->mUnk_18 + o->mUnk_1c +
        o->mUnk_20;
    if (s < -9999) {
        s = -9999;
    }
    if (s > 9999) {
        s = 9999;
    }
    return (s16) s;
}

void InitRaceProgressKart(RaceProgressKart *a, s32 b) {
    s32 i;
    Unk0217aa1c_144_00 *p;
    CourseMapRoute *e;
    s32 m;

    if (gCourseMap->mCheckpoints == NULL) {
        a->mRoute = 0;
        a->mCheckpoint = 0;
    } else {
        a->mRoute = gCourseMap->mCheckpointRoutes->mUnk_07;
        e = &gCourseMap->mCheckpointRoutes[a->mRoute];
        m = gCourseMap->mCheckpointRoutes[a->mRoute].mFirstEntry;
        a->mCheckpoint = m + e->mEntryCount - 1;
    }
    a->mLapFrames = 0;
    a->mUnk_08 = 0;
    a->mFinishTimeMs = 0;
    a->mHighestLap = 1;
    a->mLap = 0;
    a->mStatus = 0;
    a->mFlags = 0;
    a->mUnk_34 = gCourseMap->mNumberedCheckpointCount - 1;
    a->mUnk_36 = gCourseMap->mNumberedCheckpointCount - 1;
    a->mUnk_3c = (a->mUnk_3c & ~0xf0) | (((u16) b & 0xf) << 4);
    a->mRaceProgress = 0;
    a->mLapProgress = 0;
    a->mScore = 0;
    a->mFirstPlaceFrames = 0;
    a->mUnk_40 = 0;
    a->mUnk_3c = a->mUnk_3c & ~0x300;
    p = a->mLapTimes;
    for (i = 0; i < 5; i++) {
        ComputeRaceTime(&p->mUnk_02, &p->mUnk_03, &p->mUnk_00, 0, gRaceProgress->mUnk_000[0].mElapsedFrames);
        p++;
    }
    ComputeRaceTime(&a->mLapTimes[5].mUnk_02, &a->mLapTimes[5].mUnk_03, &a->mLapTimes[5].mUnk_00, 0,
                    gRaceProgress->mUnk_000[0].mElapsedFrames);
    if (b == data_021759c0->mEntryIndex) {
        a->mFlags = a->mFlags | 1;
    }
    a->mUnk_3c = (a->mUnk_3c & ~0xf) | ((u16) (b + 1) & 0xf);
}

static inline u32 func_020401ac_inline(Unk0217aa00 *p) {
    return p == NULL ? 0 : p->mUnk_0000;
}

static inline void func_020401ac_inline2(Unk0217561c_000 *q) {
    q->mElapsedFrames = 0;
    q->mClockEnabled = 0;
}

static inline void func_020401ac_inline3(Unk0217aa1c_144_00 *p, u32 e) {
    ComputeRaceTime(&p->mUnk_02, &p->mUnk_03, &p->mUnk_00, 0, e);
}

static inline void func_020401ac_inline4(Unk020f41c4_B *x, u32 s) {
    x->mUnk_00 = s;
    x->mUnk_08 = 0x5d588b656c078965;
    x->mUnk_10 = 0x269ec3;
}

static inline s32 func_020401ac_inline5(s32 a, s32 b) {
    return b == 0 ? 0 : DivFixed12(a + 0x1000, b << 12);
}

static inline u32 func_020401ac_inline6(Unk020f41c4_B *x, u32 n) {
    x->mUnk_00 = (s64) x->mUnk_08 * (s64) x->mUnk_00 + x->mUnk_10;
    return ((s64) (x->mUnk_00 >> 32) * n) >> 32;
}

void InitRaceProgress(void) {
    BOOL f;
    s32 i;
    u32 s;
    s32 v1;
    u64 a;
    u64 c;
    u64 d;
    u16 j;
    u16 k;
    u16 v2;
    s32 v;
    Unk0217aa00 *p;
    CourseMapRoute *e;
    CourseMapCheckpoint *q;

    func_020401ac_inline2(&gRaceProgress->mUnk_000[0]);
    func_020401ac_inline3(&gRaceProgress->mUnk_000[0].mUnk_08_view, gRaceProgress->mUnk_000[0].mElapsedFrames);
    f = FALSE;
    gRaceProgress->mUnk_000[0].mFinishedCount = 0;
    gRaceProgress->mUnk_000[0].mRemovedCount = 0;
    gRaceProgress->mRaceDone = 0;
    switch (data_021759c0->mUnk_00c) {
        case 1:
        case 2:
        case 6:
            f = TRUE;
            break;
        case 0:
            if (func_02040bc0() != 0) {
                f = TRUE;
            }
            break;
    }
    gRaceProgress->mUnk_4f0 = f;
    gRaceProgress->mUnk_4e0 = 6;
    gRaceProgress->mTimeCountsDown = FALSE;
    gRaceProgress->mTimeLimitFrameCount = 0;
    switch (data_021759c0->mMode) {
        case MODE_MISSION_RUN:
            if (data_021759c0->mUnk_2f == 6) {
                gRaceProgress->mTimeCountsDown = FALSE;
            } else {
                gRaceProgress->mTimeCountsDown = TRUE;
            }
            gRaceProgress->mTimeLimitFrameCount = data_021759c0->mUnk_028;
            break;
        case MODE_BATTLE:
            if (data_021759c0->mUnk_18 == 1) {
                gRaceProgress->mTimeCountsDown = TRUE;
                gRaceProgress->mTimeLimitFrameCount = gCourseMap->mSettings->mUnk_02 * 0x3c;
            }
            break;
    }
    for (i = 0; i < 8; i++) {
        InitRaceProgressKart(&gRaceProgress->mKarts[i], i);
        gRaceProgress->mKartAtRank[i] = -1;
    }
    switch (data_021759c0->mUnk_00c) {
        case 2:
            s = data_021759c0->mUnk_05c;
            break;
        case 5:
            s = 0xc240793;
            break;
        case 6:
            s = 0x71abc95;
            break;
        default:
            switch (data_021759c0->mMode) {
                case MODE_TIME_ATTACK:
                    s = 0x34a8f71;
                    break;
                case MODE_MISSION_RUN:
                    s = 0x158b76f;
                    break;
                case 5:
                    s = 0x5b12f73;
                    break;
                default:
                    p = data_0217aa00;
                    v = 0;
                    if (func_020401ac_inline(p) != 0) {
                        if (p->mUnk_0004 != 0xd) {
                            v = 1;
                        }
                    }
                    if (v != 0) {
                        s = p->mUnk_1eb0;
                    } else {
                        a = OS_GetTick();
                        s = (a << 16) + OS_GetTick();
                    }
                    break;
            }
            break;
    }
    func_020401ac_inline4(&gRaceProgress->mRandom, s);
    gRaceProgress->mSeed = s;
    data_021759c0->mNextHeader.mUnk_5c = s;
    a = OS_GetTick();
    c = OS_GetTick();
    d = OS_GetTick();
    func_020401ac_inline4(&gRaceProgress->mLocalRandom, a + ((c << 24) + (d << 8)));
    func_020401ac_inline4(&gRaceProgress->mUnk_4b0, 0xa094a2f);
    if (data_021759c0->mMode == MODE_BATTLE) {
        ShuffleCourseMapRespawnSlots(&gRaceProgress->mRandom);
    }
    gRaceProgress->mUnk_4d0 = 0;
    gRaceProgress->mUnk_4e4 = ReciprocalFixed12((gCourseMap->mUnk_9c + 1) << 12);
    gRaceProgress->mUnk_4e8 = ReciprocalFixed12(func_02044618() << 12);
    for (i = 0; i < gCourseMap->mNumberedCheckpointCount + 1; i++) {
        v1 = i % (gCourseMap->mNumberedCheckpointCount + 1);
        if (v1 == gCourseMap->mNumberedCheckpointCount) {
            gRaceProgress->mCheckpointLapProgress[i] = 0x1000;
        } else {
            for (j = 0; j < gCourseMap->mCheckpointRouteCount; j++) {
                e = &gCourseMap->mCheckpointRoutes[j];
                for (k = 0; k < e->mEntryCount; k++) {
                    v2 = k + e->mFirstEntry;
                    q = &gCourseMap->mCheckpoints[v2];
                    if (q->mNumber == v1) {
                        v = func_020401ac_inline5((v2 - e->mFirstEntry) << 12, e->mEntryCount);
                        v += e->mUnk_0a << 12;
                        gRaceProgress->mCheckpointLapProgress[i] = ((s64) v * gRaceProgress->mUnk_4e4 + 0x800) >> 12;
                    }
                }
            }
        }
    }
    if (data_021759c0->mMode != MODE_BATTLE) {
        gRaceProgress->mStartPlacementOffset = 0;
        return;
    }
    gRaceProgress->mStartPlacementOffset = func_020401ac_inline6(&gRaceProgress->mRandom, 8);
}
