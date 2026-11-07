#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_0219b580.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205af90.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_02077bc0.h"

void UpdateRaceClock(void) {
    RaceProgress *p;
    s32 t;
    RaceProgress *q;
    u32 e;
    u32 l;
    u32 h;
    BOOL f;
    BOOL g;
    s8 k;
    u16 i;
    Unk020f41c4_B *r;
    u16 *c;
    u32 v;

    t = 0;
    p = gRaceProgress;
    q = p;
    if (p->mUnk_000[0].mClockEnabled != 0) {
        h = p->mTimeLimitFrameCount;
        l = 0x57e40;
        f = FALSE;
        e = p->mUnk_000[0].mElapsedFrames;
        if (h != 0) {
            l = h;
            f = TRUE;
        }
        if (gRaceSetup->mMode == 5 && e > 0x4650) {
            k = data_0217aa18->mUnk_06[func_ov000_0219bb50()];
            if (k >= 0) {
                g = FALSE;
                switch (gRaceProgress->mUnk_000[(u8) k].mStatus) {
                    case 1:
                    case 2:
                    case 3:
                        g = TRUE;
                        break;
                }
                if (g == FALSE) {
                    FinishRaceProgressKart(&gRaceProgress->mKarts[k], 0);
                    if (IsRaceEndConditionMet() != 0) {
                        switch (gRaceSetup->mMode) {
                            case MODE_TIME_ATTACK:
                                break;
                            case MODE_BATTLE:
                                EliminateKartsUntilWinnerDecided();
                                break;
                            case MODE_MISSION_RUN:
                                FinishRemainingMissionRunKarts();
                                break;
                            case 5:
                                func_0203ecf0();
                                break;
                            default:
                                FinishRemainingRaceProgressKarts();
                                break;
                        }
                    }
                    func_0205af90();
                }
            }
        }
        if (e <= l) {
            e++;
        } else if (f != FALSE) {
            t = 1;
        }
        p->mUnk_000[0].mElapsedFrames = e;
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            v = gRaceProgress->mUnk_000[i].mLapFrames;
            if (v <= 0x57e40) {
                v++;
            }
            gRaceProgress->mUnk_000[i].mLapFrames = v;
        }
        if (t != 0) {
            switch (gRaceSetup->mMode) {
                case MODE_MISSION_RUN:
                    FinishRaceProgressKartWithEndKind((u16) gRaceSetup->mEntryIndex, 1);
                    g = data_0217d084.mUnk_04 == 2 || data_0217d084.mUnk_04 == 3;
                    if (g) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4a);
                    }
                    break;
                case MODE_BATTLE:
                    if (gRaceSetup->mUnk_18 == 1) {
                        gRaceProgress->mTimeLimitFrameCount = func_020a1520() * 0x3c;
                        p->mUnk_000[0].mElapsedFrames = 0;
                    }
                    break;
            }
        }
        q = gRaceProgress;
        r = &q->mRandom;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        t = -(s16) (u16) (r->mUnk_00 >> 32 >> 20);
    }
    c = &q->mUnk_000[0].mUnk_08;
    ComputeRaceTime((u8 *) c + 2, (u8 *) c + 3, c, t, p->mUnk_000[0].mElapsedFrames);
}

BOOL IsPointBetweenCheckpointLines(const Vec3 *a, const CourseMapCheckpoint *b, const CourseMapCheckpoint *c) {
    volatile UnkPair020b502c p;
    s32 d;

    p.mUnk_00 = a->x;
    p.mUnk_04 = a->z;
    if ((s32) (((s64) ((b->mPointAZ - c->mPointAZ) >> 4) * ((a->x - c->mPointAX) >> 4) + 0x800) >> 12) -
            (s32) (((s64) ((b->mPointAX - c->mPointAX) >> 4) * ((a->z - c->mPointAZ) >> 4) + 0x800) >> 12) <
        0) {
        return FALSE;
    }
    d = (c->mPointBX - b->mPointBX) >> 4;
    if ((s32) (((s64) ((c->mPointBZ - b->mPointBZ) >> 4) * ((a->x - b->mPointBX) >> 4) + 0x800) >> 12) -
            (s32) (((s64) d * ((a->z - b->mPointBZ) >> 4) + 0x800) >> 12) >=
        0) {
        return TRUE;
    }
    return FALSE;
}

s32 ComputeProgressBetweenCheckpoints(const Vec3 *a, u16 b, u16 c) {
    CourseMapCheckpoint *q;
    CourseMapCheckpoint *r;
    UnkPair020b502c l[3];
    s64 x;
    s64 y;

    q = &gCourseMap->mCheckpoints[b];
    r = &gCourseMap->mCheckpoints[c];
    if (IsPointBetweenCheckpointLines(a, q, r) == FALSE) {
        return -0x1000;
    }
    l[0].mUnk_00 = a->x - q->mPointBX;
    l[0].mUnk_04 = a->z - q->mPointBZ;
    l[1].mUnk_00 = a->x - r->mPointAX;
    l[1].mUnk_04 = a->z - r->mPointAZ;
    l[2].mUnk_00 = -r->mDirection.mUnk_00;
    l[2].mUnk_04 = -r->mDirection.mUnk_04;
    x = ComputeDotOfPairsRoundedS64(&l[0], &q->mDirection);
    y = x + ComputeDotOfPairsRoundedS64(&l[1], &l[2]);
    if (x > 0x7fffffff || y > 0x7fffffff || x < -0x80000000LL || y < -0x80000000LL) {
        x >>= 10;
        y >>= 10;
    }
    return FX_Div(x, y);
}

BOOL TryGetKartCheckpointProgress(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e) {
    BOOL r;
    u32 m;
    s32 w;
    s16 t;
    s32 j;
    s8 k;
    CourseMapRoute *p;
    s32 f;

    w = e >> 5;
    m = 1 << (e & 0x1f);
    r = FALSE;
    t = gCourseMap->mCheckpoints[e].mUnk_1c;
    f = a->mCheckpointTestedBits[w];
    if ((f & m) != 0) {
        return FALSE;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        for (j = 0; j < 3; j++) {
            k = (p->mNextRoutes)[j];
            if (k != -1) {
                *b = ComputeProgressBetweenCheckpoints(c, e, gCourseMap->mCheckpointRoutes[(u16) k].mFirstEntry);
                if (*b >= -2 && *b <= 0x1002) {
                    if ((gCourseMap->mCheckpoints[e].mUnk_23 & 1) != 0) {
                        if (gRaceSetup->mMode == 5) {
                            *b = 0x1000 - (func_ov000_0219bb50() + 1) * 0x190;
                        } else {
                            *b = 0x1000 - ((u32) (a->mUnk_3c << 28) >> 28) * 0x190;
                        }
                    }
                    r = TRUE;
                    break;
                }
            }
        }
    } else {
        *b = ComputeProgressBetweenCheckpoints(c, e, e + 1);
        if (*b >= -2 && *b <= 0x1002) {
            if ((gCourseMap->mCheckpoints[e].mUnk_23 & 1) != 0) {
                *b = 0x1000 - ((u32) (a->mUnk_3c << 28) >> 28) * 0x190;
            }
            if (*b < 0) {
                *b = 0;
            }
            if (*b > 0x1000) {
                *b = 0x1000;
            }
            r = TRUE;
        }
    }
    a->mCheckpointTestedBits[w] |= m;
    return r;
}

s16 FindKartCheckpointForward(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f) {
    s16 t;
    s8 k;
    s32 j;
    s16 r;
    CourseMapRoute *p;

    t = gCourseMap->mCheckpoints[e].mUnk_1c;
    if (TryGetKartCheckpointProgress(a, b, c, d, e) != 0) {
        return e;
    }
    if (f == 0) {
        return -1;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        r = -1;
        for (j = 0; j < 3; j++) {
            k = (p->mNextRoutes)[j];
            if (k != -1) {
                r = FindKartCheckpointForward(a, b, c, k, gCourseMap->mCheckpointRoutes[(u16) k].mFirstEntry, f - 1);
                if (r != -1) {
                    return r;
                }
            }
        }
        return r;
    }
    return FindKartCheckpointForward(a, b, c, d, e + 1, f - 1);
}

s16 FindKartCheckpointBackward(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f) {
    s16 t;
    s8 k;
    s32 j;
    s16 r;
    CourseMapRoute *p;

    t = gCourseMap->mCheckpoints[e].mUnk_1e;
    if (TryGetKartCheckpointProgress(a, b, c, d, e) != 0) {
        return e;
    }
    if (f == 0) {
        return -1;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        r = -1;
        for (j = 0; j < 3; j++) {
            k = p->mPreviousRoutes[j];
            if (k != -1) {
                r = FindKartCheckpointBackward(a, b, c, k,
                                               gCourseMap->mCheckpointRoutes[(u16) k].mFirstEntry +
                                                   gCourseMap->mCheckpointRoutes[(u16) k].mEntryCount - 1,
                                               f - 1);
                if (r != -1) {
                    return r;
                }
            }
        }
        return r;
    }
    return FindKartCheckpointBackward(a, b, c, d, e - 1, f - 1);
}

void ComputeRaceTime(u8 *a, u8 *b, u16 *c, s32 d, u32 e) {
    RaceProgress *p;
    s8 m;
    s8 s;
    s16 f;
    s32 t;
    s32 q;
    s32 w;
    s32 x;

    p = gRaceProgress;
    if (p->mTimeCountsDown != FALSE) {
        if (p->mTimeLimitFrameCount > e) {
            e = p->mTimeLimitFrameCount - e;
        } else {
            e = 0;
        }
    }
    if (e >= 0x57e40) {
        e = 0x57e3f;
        d = 0x1000;
    }
    t = e << 12;
    q = t / 60;
    w = q >> 12;
    m = w / 60;
    s = w % 60;
    f = (q & 0xfff) * 1000 >> 12;
    if (d != 0) {
        x = (s64) 0x44 * d + 0x800 >> 12;
        f += x * 1000 >> 12;
        if (f < 0) {
            f += 1000;
            s--;
        } else if (f >= 1000) {
            f -= 1000;
            s++;
        }
        if (s < 0) {
            s += 60;
            m--;
        } else if (s >= 60) {
            s -= 60;
            m++;
        }
        if (m < 0) {
            m = 0;
            s = 0;
            f = 0;
        } else if (m > 99) {
            f = 999;
            m = 99;
            s = 59;
        }
    }
    *a = m;
    *b = s;
    *c = f;
}

void AddLapTimes(const Unk0217aa1c_144_00 *a, const Unk0217aa1c_144_00 *b, Unk0217aa1c_144_00 *c) {
    s16 y;
    s16 x;
    s16 z;

    y = a->mUnk_02 + b->mUnk_02;
    x = a->mUnk_00 + b->mUnk_00;
    z = a->mUnk_03 + b->mUnk_03;
    if (x > 999) {
        x -= 1000;
        z++;
    }
    if (z > 59) {
        z -= 60;
        y++;
    }
    if (y >= 100) {
        y = 99;
        x = 999;
        z = 59;
    }
    c->mUnk_02 = y;
    c->mUnk_03 = z;
    c->mUnk_00 = x;
}

void StoreRaceProgressKartLapTime(RaceProgressKart *a, s32 b) {
    Vec3 u;
    Vec3 v;
    Vec3 p;
    Vec3 w;
    Unk0217aa1c_144_00 *q;
    u8 j;
    s32 i;
    Unk0217aa1c_144_00 *e;
    s32 n;
    u16 k;
    s16 t;

    t = gCourseMap->mCheckpoints->mUnk_1c;
    e = a->mLapTimes;
    i = 0;
    if (a->mLap <= 1) {
        return;
    }
    GetKartPos(&u, (u32) (a->mUnk_3c << 24) >> 28);
    GetKartPrevPos(&v, (u32) (a->mUnk_3c << 24) >> 28);
    VEC_Subtract(&u, &v, &w);
    w.x = (s64) w.x * -240 >> 12;
    w.y = (s64) w.y * -240 >> 12;
    w.z = (s64) w.z * -240 >> 12;
    p = u;
    if (t == -1) {
        t = 1;
    }
    k = t;
    do {
        n = ComputeProgressBetweenCheckpoints(&p, 0, k);
        VEC_Add(&p, &w, &p);
        i++;
    } while (n > 0 && i < 0x11);
    ComputeRaceTime(&e[a->mLap - 2].mUnk_02, &e[a->mLap - 2].mUnk_03, &e[a->mLap - 2].mUnk_00, -i * 0xf0,
                    a->mLapFrames);
    a->mLapFrames = 0;
    q = &e[5];
    q->mUnk_02 = 0;
    q->mUnk_03 = 0;
    e[5].mUnk_00 = 0;
    for (j = 0; j < a->mLap - 1; j++) {
        AddLapTimes(&e[j], q, q);
    }
    if (b != 0) {
        return;
    }
    a->mFinishTimeMs = (q->mUnk_02 * 60 + q->mUnk_03) * 1000 + q->mUnk_00;
}
