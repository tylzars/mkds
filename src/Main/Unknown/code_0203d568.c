#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02147cd8.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_0203ca38.h"

#pragma opt_rebuildconditionals off

static inline s32 func_0203d568_inline(Unk0217aa00 *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline void func_0203d568_b_inline(void) {
    u16 i;

    if (data_021759c0->mUnk_00c == 0 && GetNextSceneNumber() != 10 &&
        (GetNextSceneNumber() != 6 || data_0217b488->mUnk_74 != 2) && func_0203d568_inline(data_0217aa00) != 0) {
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            if (data_021759c0->mCurrentEntries[i].mPlayer.mKind == 0 &&
                (data_0217aa00->mUnk_15f6 & (1 << data_0217aa00->mUnk_1e8c[i])) == 0) {
                func_0204451c(i);
            }
        }
    }
}

static inline s32 func_0203d568_c_inline(void) {
    s32 r;
    if (data_0217aa08->mUnk_28 == 0) {
        r = data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0;
    } else {
        r = 1;
    }
    return r;
}

static inline u16 func_0203df74_inline(u16 a) {
    u16 i;
    u16 v1;
    u16 v2;
    CourseMapRoute *r;

    for (i = 0; i < gCourseMap->mCheckpointRouteCount; i++) {
        r = &gCourseMap->mCheckpointRoutes[i];
        v1 = r->mFirstEntry;
        v2 = v1 + r->mEntryCount;
        if (a >= v1 && a < v2) {
            return i;
        }
    }
    return 0;
}

static inline s16 func_0203df74_b_inline(RaceProgressKart *b, s32 *v, Vec3 *a) {
    u16 i;
    u16 k;
    u16 lo;
    u16 hi;
    CourseMapRoute *r;

    for (i = 0; i < gCourseMap->mCheckpointRouteCount; i++) {
        r = &gCourseMap->mCheckpointRoutes[i];
        lo = r->mFirstEntry;
        hi = lo + r->mEntryCount;
        for (k = lo; k < hi; k++) {
            if (func_0203fa60(b, v, a, i, k) != 0) {
                return k;
            }
        }
    }
    return -1;
}

static inline s32 func_0203df74_c_inline(CourseMapRoute *r, u16 c, s32 v) {
    s32 x;
    s32 t;

    t = (c - r->mFirstEntry) << 12;
    if (r->mEntryCount == 0) {
        x = 0;
    } else {
        x = DivFixed12(t + v, r->mEntryCount << 12);
    }
    t = x + (r->mUnk_0a << 12);
    return (s32) (((s64) t * gRaceProgress->mUnk_4e4 + 0x800) >> 12);
}

static inline void func_0203e550_inline(s32 a) {
    if (data_021759c0->mMode == 4) {
        func_0203e788(a, 0);
    }
}

void func_0203e550(RaceProgressKart *a) {
    BOOL f;
    BOOL g;
    Unk021759c0_28 *s;
    Unk0206cdd4_B *t;

    if (a->mLap < 0x7fffffff) {
        a->mLap = a->mLap + 1;
    }
    a->mUnk_36 = -1;
    a->mUnk_34 = -1;
    f = FALSE;
    switch (a->mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if (a->mLap <= a->mHighestLap) {
        return;
    }
    if ((a->mFlags & 1) != 0) {
        func_02106ab8();
    }
    func_0203f334(a, a->mLap > (s32) func_02044618());
    a->mHighestLap = a->mLap;
    if ((a->mFlags & 1) != 0) {
        func_020b1a34();
    }
    f = FALSE;
    if (data_021759c0->mMode != 4) {
        f = TRUE;
    } else {
        switch (data_021759c0->mUnk_2f) {
            case 2:
            case 4:
            case 6:
                f = TRUE;
                break;
        }
    }
    if (f == FALSE) {
        return;
    }
    if (a->mHighestLap <= func_02044618()) {
        return;
    }
    a->mHighestLap = func_02044618();
    if (data_021759c0->mMode == 4) {
        s = &data_021759c0->mUnk_28_view;
        g = TRUE;
        t = func_0207a6b0();
        switch (s->mUnk_07) {
            case 4:
                if (s->mUnk_0f > (u32) t->mUnk_04) {
                    g = FALSE;
                }
                break;
            case 6:
                if (a->mUnk_3c_0 != 1) {
                    g = FALSE;
                }
                break;
        }
        if (g != FALSE) {
            func_0203e550_inline(a->mUnk_3c_4);
        } else {
            func_0203e788(a->mUnk_3c_4, 4);
        }
    } else {
        if ((a->mFlags & 1) == 0 && data_021759c0->mMode == 5) {
            return;
        }
        a->mFlags |= 0x40;
    }
}

void func_0203e4c4(u32 a, u32 b) {
    RaceProgressKart *e;
    u16 c;

    e = &gRaceProgress->mKarts[a];
    c = b != 0 ? 1 : 2;
    e->mUnk_3c = (e->mUnk_3c & ~0x300) | ((c & 3) << 8);
    if (gRaceProgress->mUnk_000[0].mFinishedCount + gRaceProgress->mUnk_000[0].mRemovedCount >=
        data_021759c0->mKartCount) {
        func_0203d21c();
    }
}

void func_0203e370(RaceProgressKart *a, s32 b) {
    s16 c;

    c = gCourseMap->mCheckpoints[a->mCheckpoint].mNumber;
    if (c != -1) {
        a->mUnk_36 = c;
        if (a->mUnk_34 + 1 >= c) {
            a->mUnk_34 = c;
        }
    }
    if (b == 0 && a->mUnk_34 >= gCourseMap->mNumberedCheckpointCount - 1) {
        func_0203e550(a);
    } else if (a->mCheckpoint == 0 && b == gCourseMap->mLastCheckpoint) {
        if (a->mLap > -100) {
            a->mLap = a->mLap - 1;
        }
        a->mUnk_36 = gCourseMap->mNumberedCheckpointCount - 1;
        a->mUnk_34 = gCourseMap->mNumberedCheckpointCount - 1;
    }
    a->mCheckpoint = b;
    a->mRoute = func_0203df74_inline(b);
}

void UpdateRaceProgressKart(Vec3 *a, RaceProgressKart *b) {
    s32 v;
    u16 c;
    u16 d;
    s16 p;
    s32 w;
    s32 k;
    CourseMapRoute *r;

    c = b->mCheckpoint;
    d = b->mRoute;
    p = (s16) c;
    v = 0;
    if (func_0207a5c4(b->mUnk_3c_4) != 0) {
        return;
    }
    if (func_0203fa60(b, &v, a, d, c) == 0) {
        if (v >= 0) {
            p = func_0203f91c(b, &v, a, d, c, 5);
            if (p == -1) {
                p = func_0203f7c0(b, &v, a, d, c, 5);
            }
        } else {
            p = func_0203f7c0(b, &v, a, d, c, 5);
            if (p == -1) {
                p = func_0203f91c(b, &v, a, d, c, 5);
            }
        }
        if (p == -1) {
            p = func_0203df74_b_inline(b, &v, a);
        }
        if (p == -1) {
            return;
        }
        d = func_0203df74_inline(p);
    }
    r = &gCourseMap->mCheckpointRoutes[d];
    w = func_0203df74_c_inline(r, p, v);
    k = 0;
    if (p != -1) {
        if (gCourseMap->mNumberedCheckpointCount >= 1) {
            k = gRaceProgress->mCheckpointLapProgress[gCourseMap->mNumberedCheckpointCount - 1];
        }
        if (w <= gRaceProgress->mCheckpointLapProgress[b->mUnk_34 + 1]) {
            func_0203e370(b, p);
        } else if (b->mCheckpoint == 0 && w > k) {
            func_0203e370(b, p);
        } else {
            v = b->mUnk_40;
            w = func_0203df74_c_inline(r, b->mCheckpoint, v);
        }
    }
    b->mUnk_40 = v;
    b->mLapProgress = w;
    k = ((b->mLap - 1) << 12) + b->mLapProgress;
    b->mRaceProgress = (s32) (((s64) k * gRaceProgress->mUnk_4e8 + 0x800) >> 12);
}

void UpdateRaceProgressKarts(void) {
    Unk02040d24 t;
    s32 a[8];
    s32 b[8];
    s32 c[8];
    u16 d[8];
    Vec3 v;
    Vec3 w;
    u16 i;
    s32 k;
    RaceProgressKart *e;
    BOOL f;
    RaceProgress *p;
    Unk02040d24 *o;
    u16 m;
    s32 x;
    s32 y;
    s32 n;
    s32 h;
    s32 q;
    s32 r;
    s32 u;
    u16 g;
    RaceProgressKart *s;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        e = &gRaceProgress->mKarts[i];
        if (e->mStatus != 4 && data_021759c0->mUnk_00c != 6) {
            for (k = 0; k < 16; k++) {
                e->mUnk_4c[k] = 0;
            }
            func_0207a948(&v, i);
            GetKartForward(GetKart(i), &w);
            UpdateRaceProgressKart(&v, e);
            f = FALSE;
            if (func_0207a7fc(e->mUnk_3c_4) == 0) {
                o = &gCourseMap->mCheckpoints[e->mCheckpoint].mUnk_10;
                t.mUnk_00 = w.x;
                t.mUnk_04 = w.z;
                if (func_02040d68(&t, o) < -1394) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                e->mFlags |= 4;
            } else {
                e->mFlags &= ~4;
            }
            a[i] = e->mRaceProgress;
        }
    }
    if ((u32) data_021759c0->mKartCount > 1) {
        p = gRaceProgress;
        y = data_021759c0->mKartCount - p->mUnk_000[0].mRemovedCount;
        x = p->mUnk_000[0].mFinishedCount;
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            h = p->mUnk_000[i].mUnk_50_0 - 1;
            b[h] = a[i];
            d[h] = i;
            c[h] = p->mUnk_000[(u32) i].mLap;
        }
        for (i = x + 1; i < y; i++) {
            q = b[i];
            u = d[i];
            r = c[i];
            for (n = i; n > x && (c[n - 1] < r || (r == c[n - 1] && b[n - 1] < q)); n--) {
                c[n] = c[n - 1];
                b[n] = b[n - 1];
                d[n] = d[n - 1];
            }
            b[n] = q;
            d[n] = u;
        }
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            if (d[i] < 8) {
                gRaceProgress->mKarts[d[i]].mUnk_3c_0 = i + 1;
            }
        }
        gRaceProgress->mUnk_000[d[0]].mFirstPlaceFrames++;
        for (g = 0; g < (u32) data_021759c0->mKartCount; g++) {
            gRaceProgress->mKartAtRank[g] = d[g];
        }
        for (; g < 8; g++) {
            gRaceProgress->mKartAtRank[g] = -1;
        }
    } else {
        gRaceProgress->mUnk_000[0].mUnk_50_0 = 1;
        gRaceProgress->mUnk_000[0].mFirstPlaceFrames++;
        gRaceProgress->mKartAtRank[0] = 0;
        for (g = 1; g < 8; g++) {
            gRaceProgress->mKartAtRank[g] = -1;
        }
    }
    f = FALSE;
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
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = &gRaceProgress->mKarts[i];
        f = FALSE;
        switch (s->mStatus) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && (s->mFlags & 0x40) != 0) {
            FinishRaceProgressKart(s, 1);
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
            s->mFlags &= ~0x40;
        }
        if ((s->mFlags & 8) != 0) {
            s->mFlags &= ~8;
            if (data_021759c0->mMode != 4) {
                func_0207a828(s->mUnk_3c_4);
                if ((s->mFlags & 1) != 0) {
                    func_02110cc8(0);
                }
            }
        }
    }
}

void func_0203d8fc(RankTimeGp *a) {
    s32 i;
    RankTimeGpEntry *e;

    gRaceProgress->mUnk_000[0].mRankTime = 0;
    for (i = 0; i < a->mEntryCount; i++) {
        e = &a->mUnk_1c[i];
        if (e->mCourseId == data_021759c0->mCourseId) {
            switch (data_021759c0->mUnk_010) {
                case 0:
                    gRaceProgress->mUnk_000[0].mRankTime = e->mUnk_02;
                    return;
                case 1:
                    gRaceProgress->mUnk_000[0].mRankTime = e->mUnk_04;
                    return;
                case 2:
                    gRaceProgress->mUnk_000[0].mRankTime = e->mUnk_06;
                    break;
            }
            return;
        }
    }
}

void CreateRaceProgress(void *a) {
    gRaceProgress = HeapAlloc(a, 0x524);
    gRaceProgress->mCheckpointLapProgress = HeapAlloc(a, (gCourseMap->mNumberedCheckpointCount + 1) << 2);
    gRaceProgress->mRankPointFile = FindMainRaceOrMainEffectFile(data_usa_021647b8);
    gRaceProgress->mRankTimeGpFile = FindMainRaceOrMainEffectFile(data_usa_021647c8);
    func_0203d8fc(gRaceProgress->mRankTimeGpFile);
    if (data_021759c0->mMode == 4) {
        func_0205e2cc(a);
    }
    InitRaceProgress();
}

void func_0203d568(void) {
    u16 i;
    enum { K0 } k;

    func_02043544(0);
    if (func_0203d568_c_inline() != 0) {
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            CARD_WaitBackupAsync();
        }
    }
    switch (data_021759c0->mMode) {
        case 3:
            func_0203d568_b_inline();
            break;
        case 4:
            func_0205e2b8();
            break;
        case 2:
            func_0203d568_b_inline();
            break;
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        k = data_021759c0->mCurrentEntries[i].mPlayer.mIndex;
        func_0204a928(&data_02175628[k].mUnk_28);
    }
}
