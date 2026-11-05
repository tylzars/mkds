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

void func_0203fed4(void) {
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
        if (data_021759c0->mMode == 5 && e > 0x4650) {
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
                    if (func_0203ef58() != 0) {
                        switch (data_021759c0->mMode) {
                            case 1:
                                break;
                            case 2:
                                func_020a12b8();
                                break;
                            case 4:
                                func_0203eb38();
                                break;
                            case 5:
                                func_0203ecf0();
                                break;
                            default:
                                func_0203ee28();
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
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            v = gRaceProgress->mUnk_000[i].mLapFrames;
            if (v <= 0x57e40) {
                v++;
            }
            gRaceProgress->mUnk_000[i].mLapFrames = v;
        }
        if (t != 0) {
            switch (data_021759c0->mMode) {
                case 4:
                    func_0203e788((u16) data_021759c0->mEntryIndex, 1);
                    g = data_0217d084.mUnk_04 == 2 || data_0217d084.mUnk_04 == 3;
                    if (g) {
                        func_0212ecc0(&data_0217d068, 0, 0x4a);
                    }
                    break;
                case 2:
                    if (data_021759c0->mUnk_18 == 1) {
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

BOOL func_0203fde0(const Vec3 *a, const CourseMapCheckpoint *b, const CourseMapCheckpoint *c) {
    volatile UnkPair020b502c p;
    s32 d;

    p.mUnk_00 = a->x;
    p.mUnk_04 = a->z;
    if ((s32) (((s64) ((b->mUnk_04 - c->mUnk_04) >> 4) * ((a->x - c->mUnk_00) >> 4) + 0x800) >> 12) -
            (s32) (((s64) ((b->mUnk_00 - c->mUnk_00) >> 4) * ((a->z - c->mUnk_04) >> 4) + 0x800) >> 12) <
        0) {
        return FALSE;
    }
    d = (c->mUnk_08 - b->mUnk_08) >> 4;
    if ((s32) (((s64) ((c->mUnk_0c - b->mUnk_0c) >> 4) * ((a->x - b->mUnk_08) >> 4) + 0x800) >> 12) -
            (s32) (((s64) d * ((a->z - b->mUnk_0c) >> 4) + 0x800) >> 12) >=
        0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0203fcac(const Vec3 *a, u16 b, u16 c) {
    CourseMapCheckpoint *q;
    CourseMapCheckpoint *r;
    UnkPair020b502c l[3];
    s64 x;
    s64 y;

    q = &gCourseMap->mCheckpoints[b];
    r = &gCourseMap->mCheckpoints[c];
    if (func_0203fde0(a, q, r) == FALSE) {
        return -0x1000;
    }
    l[0].mUnk_00 = a->x - q->mUnk_08;
    l[0].mUnk_04 = a->z - q->mUnk_0c;
    l[1].mUnk_00 = a->x - r->mUnk_00;
    l[1].mUnk_04 = a->z - r->mUnk_04;
    l[2].mUnk_00 = -r->mUnk_10.mUnk_00;
    l[2].mUnk_04 = -r->mUnk_10.mUnk_04;
    x = func_02040d24(&l[0], &q->mUnk_10);
    y = x + func_02040d24(&l[1], &l[2]);
    if (x > 0x7fffffff || y > 0x7fffffff || x < -0x80000000LL || y < -0x80000000LL) {
        x >>= 10;
        y >>= 10;
    }
    return DivFixed12((s32) x, (s32) y);
}

BOOL func_0203fa60(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e) {
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
    f = a->mUnk_4c[w];
    if ((f & m) != 0) {
        return FALSE;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        for (j = 0; j < 3; j++) {
            k = (p->mUnk_04)[j];
            if (k != -1) {
                *b = func_0203fcac(c, e, gCourseMap->mCheckpointRoutes[(u16) k].mFirstEntry);
                if (*b >= -2 && *b <= 0x1002) {
                    if ((gCourseMap->mCheckpoints[e].mUnk_23 & 1) != 0) {
                        if (data_021759c0->mMode == 5) {
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
        *b = func_0203fcac(c, e, e + 1);
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
    a->mUnk_4c[w] |= m;
    return r;
}

s16 func_0203f91c(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f) {
    s16 t;
    s8 k;
    s32 j;
    s16 r;
    CourseMapRoute *p;

    t = gCourseMap->mCheckpoints[e].mUnk_1c;
    if (func_0203fa60(a, b, c, d, e) != 0) {
        return e;
    }
    if (f == 0) {
        return -1;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        r = -1;
        for (j = 0; j < 3; j++) {
            k = (p->mUnk_04)[j];
            if (k != -1) {
                r = func_0203f91c(a, b, c, (u16) k, gCourseMap->mCheckpointRoutes[(u16) k].mFirstEntry, f - 1);
                if (r != -1) {
                    return r;
                }
            }
        }
        return r;
    }
    return func_0203f91c(a, b, c, d, e + 1, f - 1);
}

s16 func_0203f7c0(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f) {
    s16 t;
    s8 k;
    s32 j;
    s16 r;
    CourseMapRoute *p;

    t = gCourseMap->mCheckpoints[e].mUnk_1e;
    if (func_0203fa60(a, b, c, d, e) != 0) {
        return e;
    }
    if (f == 0) {
        return -1;
    }
    if (t != -1) {
        p = &gCourseMap->mCheckpointRoutes[d];
        r = -1;
        for (j = 0; j < 3; j++) {
            k = (&p->mUnk_07)[j];
            if (k != -1) {
                r = func_0203f7c0(a, b, c, (u16) k,
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
    return func_0203f7c0(a, b, c, d, e - 1, f - 1);
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

void func_0203f544(const Unk0217aa1c_144_00 *a, const Unk0217aa1c_144_00 *b, Unk0217aa1c_144_00 *c) {
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

void func_0203f334(RaceProgressKart *a, s32 b) {
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
    func_0207a948(&u, (u32) (a->mUnk_3c << 24) >> 28);
    GetKartPrevPos(&v, (u32) (a->mUnk_3c << 24) >> 28);
    Vec3Sub(&u, &v, &w);
    w.x = (s64) w.x * -240 >> 12;
    w.y = (s64) w.y * -240 >> 12;
    w.z = (s64) w.z * -240 >> 12;
    p = u;
    if (t == -1) {
        t = 1;
    }
    k = t;
    do {
        n = func_0203fcac(&p, 0, k);
        Vec3Add(&p, &w, &p);
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
        func_0203f544(&e[j], q, q);
    }
    if (b != 0) {
        return;
    }
    a->mFinishTimeMs = (q->mUnk_02 * 60 + q->mUnk_03) * 1000 + q->mUnk_00;
}
