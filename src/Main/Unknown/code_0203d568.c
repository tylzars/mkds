#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203d568.h"
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

    if (data_021759c0->mUnk_00c == 0 && func_0205e090() != 10 &&
        (func_0205e090() != 6 || data_0217b488->mUnk_74 != 2) && func_0203d568_inline(data_0217aa00) != 0) {
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            if (data_021759c0->mCurrentEntries[i].mUnk_08.mKind == 0 &&
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

static inline s16 func_0203df74_b_inline(Unk0217561c_14 *b, s32 *v, Vec3 *a) {
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
    return (s32) (((s64) t * data_0217561c->mUnk_4e4 + 0x800) >> 12);
}

static inline void func_0203e550_inline(s32 a) {
    if (data_021759c0->mMode == 4) {
        func_0203e788(a, 0);
    }
}

void func_0203e550(Unk0217561c_14 *a) {
    BOOL f;
    BOOL g;
    Unk021759c0_28 *s;
    Unk0206cdd4_B *t;

    if (a->mUnk_24 < 0x7fffffff) {
        a->mUnk_24 = a->mUnk_24 + 1;
    }
    a->mUnk_36 = -1;
    a->mUnk_34 = -1;
    f = FALSE;
    switch (a->mUnk_00) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if (a->mUnk_24 <= a->mUnk_3a) {
        return;
    }
    if ((a->mUnk_30 & 1) != 0) {
        func_02106ab8();
    }
    func_0203f334(a, a->mUnk_24 > (s32) func_02044618());
    a->mUnk_3a = a->mUnk_24;
    if ((a->mUnk_30 & 1) != 0) {
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
    if (a->mUnk_3a <= func_02044618()) {
        return;
    }
    a->mUnk_3a = func_02044618();
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
        if ((a->mUnk_30 & 1) == 0 && data_021759c0->mMode == 5) {
            return;
        }
        a->mUnk_30 |= 0x40;
    }
}

void func_0203e4c4(u32 a, u32 b) {
    Unk0217561c_14 *e;
    u16 c;

    e = &data_0217561c->mUnk_14[a];
    c = b != 0 ? 1 : 2;
    e->mUnk_3c = (e->mUnk_3c & ~0x300) | ((c & 3) << 8);
    if (data_0217561c->mUnk_000[0].mUnk_0e + data_0217561c->mUnk_000[0].mUnk_10 >= data_021759c0->mKartCount) {
        func_0203d21c();
    }
}

void func_0203e370(Unk0217561c_14 *a, s32 b) {
    s16 c;

    c = gCourseMap->mCheckpoints[a->mUnk_32].mNumber;
    if (c != -1) {
        a->mUnk_36 = c;
        if (a->mUnk_34 + 1 >= c) {
            a->mUnk_34 = c;
        }
    }
    if (b == 0 && a->mUnk_34 >= gCourseMap->mNumberedCheckpointCount - 1) {
        func_0203e550(a);
    } else if (a->mUnk_32 == 0 && b == gCourseMap->mLastCheckpoint) {
        if (a->mUnk_24 > -100) {
            a->mUnk_24 = a->mUnk_24 - 1;
        }
        a->mUnk_36 = gCourseMap->mNumberedCheckpointCount - 1;
        a->mUnk_34 = gCourseMap->mNumberedCheckpointCount - 1;
    }
    a->mUnk_32 = b;
    a->mUnk_38 = func_0203df74_inline(b);
}

void func_0203df74(Vec3 *a, Unk0217561c_14 *b) {
    s32 v;
    u16 c;
    u16 d;
    s16 p;
    s32 w;
    s32 k;
    CourseMapRoute *r;

    c = b->mUnk_32;
    d = b->mUnk_38;
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
            k = data_0217561c->mUnk_4d4[gCourseMap->mNumberedCheckpointCount - 1];
        }
        if (w <= data_0217561c->mUnk_4d4[b->mUnk_34 + 1]) {
            func_0203e370(b, p);
        } else if (b->mUnk_32 == 0 && w > k) {
            func_0203e370(b, p);
        } else {
            v = b->mUnk_40;
            w = func_0203df74_c_inline(r, b->mUnk_32, v);
        }
    }
    b->mUnk_40 = v;
    b->mUnk_48 = w;
    k = ((b->mUnk_24 - 1) << 12) + b->mUnk_48;
    b->mUnk_44 = (s32) (((s64) k * data_0217561c->mUnk_4e8 + 0x800) >> 12);
}

void func_0203d9d4(void) {
    Unk02040d24 t;
    s32 a[8];
    s32 b[8];
    s32 c[8];
    u16 d[8];
    Vec3 v;
    Vec3 w;
    u16 i;
    s32 k;
    Unk0217561c_14 *e;
    BOOL f;
    Unk0217561c *p;
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
    Unk0217561c_14 *s;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        e = &data_0217561c->mUnk_14[i];
        if (e->mUnk_00 != 4 && data_021759c0->mUnk_00c != 6) {
            for (k = 0; k < 16; k++) {
                e->mUnk_4c[k] = 0;
            }
            func_0207a948(&v, i);
            func_02063b10(GetKart(i), &w);
            func_0203df74(&v, e);
            f = FALSE;
            if (func_0207a7fc(e->mUnk_3c_4) == 0) {
                o = &gCourseMap->mCheckpoints[e->mUnk_32].mUnk_10;
                t.mUnk_00 = w.x;
                t.mUnk_04 = w.z;
                if (func_02040d68(&t, o) < -1394) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                e->mUnk_30 |= 4;
            } else {
                e->mUnk_30 &= ~4;
            }
            a[i] = e->mUnk_44;
        }
    }
    if ((u32) data_021759c0->mKartCount > 1) {
        p = data_0217561c;
        y = data_021759c0->mKartCount - p->mUnk_000[0].mUnk_10;
        x = p->mUnk_000[0].mUnk_0e;
        for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
            h = p->mUnk_000[i].mUnk_50_0 - 1;
            b[h] = a[i];
            d[h] = i;
            c[h] = p->mUnk_000[(u32) i].mUnk_38;
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
                data_0217561c->mUnk_14[d[i]].mUnk_3c_0 = i + 1;
            }
        }
        data_0217561c->mUnk_000[d[0]].mUnk_3c++;
        for (g = 0; g < (u32) data_021759c0->mKartCount; g++) {
            data_0217561c->mUnk_474[g] = d[g];
        }
        for (; g < 8; g++) {
            data_0217561c->mUnk_474[g] = -1;
        }
    } else {
        data_0217561c->mUnk_000[0].mUnk_50_0 = 1;
        data_0217561c->mUnk_000[0].mUnk_3c++;
        data_0217561c->mUnk_474[0] = 0;
        for (g = 1; g < 8; g++) {
            data_0217561c->mUnk_474[g] = -1;
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
    data_0217561c->mUnk_4f0 = f;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = &data_0217561c->mUnk_14[i];
        f = FALSE;
        switch (s->mUnk_00) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && (s->mUnk_30 & 0x40) != 0) {
            func_0203e9a0(s, 1);
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
            s->mUnk_30 &= ~0x40;
        }
        if ((s->mUnk_30 & 8) != 0) {
            s->mUnk_30 &= ~8;
            if (data_021759c0->mMode != 4) {
                func_0207a828(s->mUnk_3c_4);
                if ((s->mUnk_30 & 1) != 0) {
                    func_02110cc8(0);
                }
            }
        }
    }
}

void func_0203d8fc(Unk0217561c_4c8 *a) {
    s32 i;
    Unk0217561c_4c8_1c *e;

    data_0217561c->mUnk_000[0].mUnk_0c = 0;
    for (i = 0; i < a->mUnk_08; i++) {
        e = &a->mUnk_1c[i];
        if (e->mUnk_00 == data_021759c0->mCourseId) {
            switch (data_021759c0->mUnk_010) {
                case 0:
                    data_0217561c->mUnk_000[0].mUnk_0c = e->mUnk_02;
                    return;
                case 1:
                    data_0217561c->mUnk_000[0].mUnk_0c = e->mUnk_04;
                    return;
                case 2:
                    data_0217561c->mUnk_000[0].mUnk_0c = e->mUnk_06;
                    break;
            }
            return;
        }
    }
}

void func_0203d848(void *a) {
    data_0217561c = HeapAlloc(a, 0x524);
    data_0217561c->mUnk_4d4 = HeapAlloc(a, (gCourseMap->mNumberedCheckpointCount + 1) << 2);
    data_0217561c->mUnk_4dc = FindMainRaceOrMainEffectFile(data_usa_021647b8);
    data_0217561c->mUnk_4c8 = FindMainRaceOrMainEffectFile(data_usa_021647c8);
    func_0203d8fc(data_0217561c->mUnk_4c8);
    if (data_021759c0->mMode == 4) {
        func_0205e2cc(a);
    }
    func_020401ac();
}

void func_0203d568(void) {
    u16 i;
    enum { K0 } k;

    func_02043544(0);
    if (func_0203d568_c_inline() != 0) {
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
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
        k = data_021759c0->mCurrentEntries[i].mUnk_08.mIndex;
        func_0204a928(&data_02175628[k].mUnk_28);
    }
}
