#include "Main/Unknown/code_02063b70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0215d000.h"

void SetKartSoundDistanceSquaredAndChange(Kart *a) {
    a->mSoundSource.mDistanceSquared = func_02086080(a->mIndex);
    func_0210b7ec(&a->mUnk_518, func_02086080(a->mIndex));
}

static inline void func_02063cc4_inline(u32 a, s32 b) {
    func_01ff9048(a, &b, 1);
}

static inline void func_02063cc4_inline2(u32 a, s32 b, s32 c, s32 d) {
    Vec3 e;

    e.x = b;
    e.y = c;
    e.z = d;
    func_01ff9048(a, &e, 3);
}

static inline void func_02063cc4_inline3(Vec3 *a, const Vec3 *b) {
    a->x = b->x >> 4;
    a->y = b->y >> 4;
    a->z = b->z >> 4;
}

void DrawKart(Kart *a) {
    u32 b;
    u32 c;
    u32 d;
    Unk0206bcb0_590 *e;
    Unk0206bcb0_590_54 *f;
    s32 g;
    s32 h;
    s32 j[9];
    s32 k[9];
    Vec3 r;
    s32 w;

    c = a->mUnk_4c;
    b = (c & 0x10) != 0;
    d = a->mUnk_7c;
    e = a->mKartModelsEntry;
    if ((d & 0x1008040) != 0 || (c & 0x11800000) != 0) {
        g = 0;
        if ((d & 0x1008040) == 0 && (c & 0x1800000) == 0) {
            g = func_02063b70(a);
        }
        func_0208155c(a->mIndex, g);
        a->mVisible = 0;
        return;
    }
    if ((d & 0x404004) != 0) {
        a->mVisible = ~a->mVisible;
        if (a->mVisible == 0) {
            return;
        }
    } else {
        a->mVisible = 0xffff;
    }
    func_02063cc4_inline(0x14, 0x1e);
    if (b != 0) {
        func_02063cc4_inline3(&a->mUnk_144, a->mPosSource);
        func_01ff9048(0x19, &a->mUnk_120, 0xc);
        func_01ff9048(0x1b, &a->mScale, 3);
        func_02063cc4_inline2(0x1b, a->mUnk_414, a->mUnk_404, a->mUnk_418);
        func_0207ae58(e->mUnk_01c);
        func_02063cc4_inline(0x14, 0x1e);
    }
    func_01ff9048(0x19, a->mUnk_1b4, 0xc);
    func_01ff9048(0x1b, &a->mScale, 3);
    func_02063cc4_inline(0x13, 0x1d);
    func_02063cc4_inline2(0x1b, a->mUnk_414, a->mUnk_404, a->mUnk_418);
    if (b == 0) {
        func_0207ae58(e->mUnk_01c);
    }
    func_0208ab4c(&e->mUnk_040);
    if (e->mUnk_058 == 0) {
        func_02079b9c(e, e->mUnk_060 == FALSE);
        func_02063cc4_inline(0x13, 0x1c);
        func_02063cc4_inline2(0x1b, a->mUnk_4f0.x, a->mUnk_4f0.y, 0x1000);
        func_020849d0(e->mUnk_010[1]);
        if (e->mUnk_010[2] != NULL) {
            f = a->mKartModelsEntry->mUnk_054;
            h = a->mKartModelsEntry->mUnk_020->mUnk_10;
            func_02063cc4_inline(0x14, 0x1c);
            func_01ff9048(0x1c, &f->mUnk_18, 3);
            w = (a->mTireSpinAngle >> 4) * 2;
            Matrix3x3FromPairX(j, gPairsByAngle[w], gPairsByAngle[w + 1]);
            func_01ff9048(0x1a, j, 9);
            func_020849d0(e->mUnk_010[2]);
            if (f->mUnk_18 != 0) {
                func_02063cc4_inline2(0x1c, f->mUnk_24, 0, 0);
                func_020849d0(e->mUnk_010[2]);
            }
            func_02063cc4_inline(0x14, 0x1c);
            func_01ff9048(0x1c, f, 3);
            func_02063cc4_inline2(0x1b, h, h, h);
            func_01ff9048(0x11, NULL, 0);
            w = (a->mUnk_4cc >> 4) * 2;
            Matrix3x3FromPairY(k, gPairsByAngle[w], gPairsByAngle[w + 1]);
            func_01ff9048(0x1a, k, 9);
            func_01ff9048(0x1a, j, 9);
            func_020849d0(e->mUnk_010[2]);
            if (f->mUnk_00 != 0) {
                func_02063cc4_inline(0x12, 1);
                func_02063cc4_inline2(0x1c, f->mUnk_0c, 0, 0);
                func_01ff9048(0x1a, k, 9);
                func_01ff9048(0x1a, j, 9);
                func_020849d0(e->mUnk_010[2]);
            }
        }
    }
    if (e->mUnk_05c != 0) {
        return;
    }
    r = ((Vec3 *) &e->mUnk_020->mUnk_44)[e->mUnk_000];
    r.y = r.y + (a->mUnk_408 + a->mUnk_4f0.z);
    func_02063cc4_inline(0x14, 0x1d);
    func_01ff9048(0x1c, &r, 3);
    func_020849d0(e->mUnk_010[0]);
}

s32 func_02063b70(Kart *a) {
    Unk0206bcb0_590 *b;
    Unk0206bcb0_590_08 *c;
    BOOL d;
    s32 e;
    s32 f;
    s32 t;
    s32 k;
    Vec3 h;
    Vec3 i;
    Unk02012f58 g;

    b = a->mKartModelsEntry;
    d = b->mUnk_058 == 0;
    if (d != FALSE) {
        t = a->mRadius + 0x5000;
        g = *a->mUnk_1b4;
        Vec3AddScaled(t, &a->mUnk_12c, a->mPosSource, &h);
        g.mUnk_00[3].x = h.x >> 4;
        g.mUnk_00[3].y = h.y >> 4;
        g.mUnk_00[3].z = h.z >> 4;
        k = a->mUnk_4c8;
        i.x = (s64) a->mScale.x * k >> 12;
        i.y = (s64) a->mScale.y * k >> 12;
        i.z = (s64) a->mScale.z * k >> 12;
        f = 0x1e;
        func_01ff9048(0x14, &f, 1);
        func_01ff9048(0x19, &g, 0xc);
        func_01ff9048(0x1b, &i, 3);
        func_0208ab4c(&b->mUnk_040);
        func_0207a30c(a->mIndex);
        e = a->mKartModelsEntry->mUnk_0a4;
        c = func_02079b60();
        c->mUnk_0c = e;
        *c->mUnk_1c[c->mUnk_1a] = c->mUnk_0c;
        func_020849d0(func_02079b88());
        func_0207ae58(func_02079b74());
    }
    return d;
}
