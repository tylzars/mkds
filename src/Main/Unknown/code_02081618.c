#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02081000.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_0201c528.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147288.h"
#include "Main/Unknown/code_02077bc0.h"

KartEffects *GetKartEffects(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartEffects;
    value1 = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (KartEffects *) value0;
}

void InitKartEffects(u32 a) {
    KartEffects *e;
    u16 i;
    u16 j;

    i = 0;
    gKartEffects = HeapAlloc(GetHeap(func_020364e8()), a * 0x58);
    data_0217ae70 = a;
    for (; i < a; i++) {
        e = &gKartEffects[i];
        e->mCurrentEffect = NULL;
        e->mUnk_28 = NULL;
        e->mKillerEffect = NULL;
        e->mUnk_30 = NULL;
        e->mCurrentEffectId = -1;
        e->mWaterEffect0 = e->mWaterEffect1 = 0;
        for (j = 0; j < 2; j++) {
            e->mEffectPairs[j].mEffect0 = e->mEffectPairs[j].mEffect1 = 0;
            e->mEffectIds[j] = -1;
        }
    }
    gKartBoostCameraEffect = NULL;
}

void ComputeKartSidePoints(Kart *p) {
    u16 i;
    KartEffects *e;
    Vec3 q;
    Vec3 w;
    Vec3 v;

    e = &gKartEffects[p->mIndex];
    p->mUnk_174 = *p->mPosSource;
    for (i = 0; i < 2; i++) {
        v = p->mKartModelsEntry->mUnk_020->mUnk_14[i + 2];
        v.y = 0;
        v.x = v.x + gKartSideOffsetsX[i];
        q.x = ((s64) v.x * p->mScale.x) >> 12;
        q.y = ((s64) v.y * p->mScale.y) >> 12;
        q.z = ((s64) v.z * p->mScale.z) >> 12;
        MTX_MultVec43(&q, &p->mUnk_150_m, &e->mSidePositions[i]);
        e->mSidePositions[i].x = e->mSidePositions[i].x >> 4;
        e->mSidePositions[i].y = e->mSidePositions[i].y >> 4;
        e->mSidePositions[i].z = e->mSidePositions[i].z >> 4;
        MTX_MultVec33(&gKartSideDirectionVectors[i], &p->mUnk_150.x, &w);
        e->mSideDirections[i].x = w.x;
        e->mSideDirections[i].y = w.y;
        e->mSideDirections[i].z = w.z;
    }
}

void func_0208442c(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(p, 0);
}

void func_020843d8(Kart *p) {
    gKartSurfaceEffectRows[0].mStartEffects(&gKartSurfaceEffectRows[0].mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                            gKartSurfaceEffectRows[0].mVelocityFactorIndex, p);
    StopKartEffectPairs(p, 0);
}

void func_02084384(Kart *p) {
    gKartSurfaceEffectRow1.mStartEffects(&gKartSurfaceEffectRow1.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow1.mVelocityFactorIndex, p);
    StopKartEffectPairs(p, 0);
}

void func_02084334(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    func_02083de8(2, p);
}

void func_020842ac(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow3.mStartEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow3.mVelocityFactorIndex, p);
}

void func_02084224(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow4.mStartEffects(&gKartSurfaceEffectRow4.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow4.mVelocityFactorIndex, p);
}

void func_0208419c(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow5.mStartEffects(&gKartSurfaceEffectRow5.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow5.mVelocityFactorIndex, p);
}

void func_02084114(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow6.mStartEffects(&gKartSurfaceEffectRow6.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow6.mVelocityFactorIndex, p);
}

void func_020840c0(Kart *p) {
    gKartSurfaceEffectRow7.mStartEffects(&gKartSurfaceEffectRow7.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]],
                                         gKartSurfaceEffectRow7.mVelocityFactorIndex, p);
    StopKartEffectPairs(p, 0);
}

// Starts the boost effect in front of the chase camera; the previous one is told to end.
void StartKartBoostCameraEffect(u32 a, Kart *p) {
    Unk0201ca6c *o;

    if (GetCurrentCameraKind() != 0) {
        return;
    }
    GetChaseCamera();
    if (gKartBoostCameraEffect != NULL) {
        gKartBoostCameraEffect->mUnk_24.mUnk_00_0 = 1;
    }
    o = StartEffect(gKartBoostCameraEffectIds[a], &data_02155a14);
    o->mUnk_98 = 0;
    o->mUnk_94 = p;
    o->mUnk_90 = AdvanceKartBoostCameraEffect;
    gKartBoostCameraEffect = o;
}

// Runs entry a of the effect table while the kart flag is set, otherwise ends the kart effects.
void ApplyKartSurfaceEffect(s32 a, Kart *p) {
    KartEffects *e;

    if (p->mUnk_4c & 0x8000) {
        gKartSurfaceEffectFunctions[a](p);
        return;
    }
    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(p, 0);
    e = &gKartEffects[p->mIndex];
    if (e->mWaterEffect0 != 0) {
        e->mWaterEffect0->mUnk_98_8 = 1;
        e->mWaterEffect0 = 0;
    }
    if (e->mWaterEffect1 != 0) {
        e->mWaterEffect1->mUnk_98_8 = 1;
        e->mWaterEffect1 = 0;
    }
}

// Starts the water effects while the kart flag is set, otherwise ends them.
void ApplyKartWaterEffects(Kart *p) {
    KartEffects *e;

    if (p->mUnk_4c & 0x8000) {
        StartKartWaterEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]], 1, p);
        return;
    }
    e = &gKartEffects[p->mIndex];
    if (e->mWaterEffect0 != 0) {
        e->mWaterEffect0->mUnk_98_8 = 1;
        e->mWaterEffect0 = 0;
    }
    if (e->mWaterEffect1 != 0) {
        e->mWaterEffect1->mUnk_98_8 = 1;
        e->mWaterEffect1 = 0;
    }
}

void func_02083de8(s32 a, Kart *p) {
    KartSurfaceEffectRow *t;
    KartEffectIdSet *n;
    KartEffects *e;
    u16 i;
    u16 j;

    t = &gKartSurfaceEffectRows[a];
    n = &t->mEffectIdSets[gKartEffectIdSetIndex[p->mIndex]];
    if (t->mStartEffects(n, t->mVelocityFactorIndex, p) == 0) {
        return;
    }
    e = &gKartEffects[p->mIndex];
    for (i = 0; i < n->mCount; i++) {
        for (j = 0; j < 2; j++) {
            if (e->mEffectPairs[i].mUnk_00_a[j] != 0) {
                e->mEffectPairs[i].mUnk_00_a[j]->mUnk_72 = data_0217ae6c;
            }
        }
    }
}

BOOL StartKartCurrentEffect(KartEffectIdSet *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;

    e = &gKartEffects[p->mIndex];
    if (a->mEffectIds[0] == e->mCurrentEffectId) {
        return FALSE;
    }
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
    }
    o = StartEffect(a->mEffectIds[0], &data_02155a14);
    e->mCurrentEffect = o;
    e->mCurrentEffectId = a->mEffectIds[0];
    o->mUnk_94 = p;
    o->mUnk_98_0 = b;
    o->mUnk_90 = AdvanceKartCurrentEffect;
    return TRUE;
}

// Starts one effect per side of the kart for each id that is not running yet.
s32 StartKartSideEffects(KartEffectIdSet *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mCount; i++) {
        e = &gKartEffects[p->mIndex];
        j = 0;
        if (a->mEffectIds[i] != e->mEffectIds[i]) {
            if (e->mEffectPairs[i].mEffect0 != 0) {
                e->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (e->mEffectPairs[i].mEffect1 != 0) {
                e->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            e->mEffectIds[i] = a->mEffectIds[i];
            do {
                o = StartEffect(e->mEffectIds[i], &data_02155a14);
                gKartEffects[p->mIndex].mEffectPairs[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_90 = AdvanceKartSideEffect;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

s32 StartKartSideEffectsWithVelocity(KartEffectIdSet *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mCount; i++) {
        e = &gKartEffects[p->mIndex];
        j = 0;
        if (a->mEffectIds[i] != e->mEffectIds[i]) {
            if (e->mEffectPairs[i].mEffect0 != 0) {
                e->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (e->mEffectPairs[i].mEffect1 != 0) {
                e->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            e->mEffectIds[i] = a->mEffectIds[i];
            do {
                o = StartEffect(e->mEffectIds[i], &data_02155a14);
                gKartEffects[p->mIndex].mEffectPairs[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_98_0 = b;
                o->mUnk_90 = AdvanceKartSideEffectWithVelocity;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

BOOL StartKartWaterEffects(KartEffectIdSet *a, s32 b, Kart *p) {
    KartEffects *e;
    Unk0201ca6c *o;
    u16 i;

    e = &gKartEffects[p->mIndex];
    if (e->mWaterEffect0 != 0 || e->mWaterEffect1 != 0) {
        return FALSE;
    }
    for (i = 0; i < 2; i++) {
        o = StartEffect(a->mEffectIds[0], &data_02155a14);
        gKartEffects[p->mIndex].mUnk_20_a[i] = o;
        o->mUnk_94 = p;
        o->mUnk_98_24 = i;
        o->mUnk_98_0 = b;
        o->mUnk_90 = AdvanceKartWaterEffect;
    }
    return TRUE;
}

void StopKartCurrentEffects(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        e->mCurrentEffect->mUnk_98_8 = 1;
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(p, 0);
}

void StopKartEffectPairs(Kart *p, s32 a) {
    u16 i;
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    for (i = 0; i < 2; i++) {
        if (e->mEffectPairs[i].mEffect0 != 0 || e->mEffectPairs[i].mEffect1 != 0) {
            if (a == 0) {
                e->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
                e->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            } else {
                func_0208b710(e->mEffectPairs[i].mEffect0);
                func_0208b710(e->mEffectPairs[i].mEffect1);
            }
            e->mEffectPairs[i].mEffect0 = e->mEffectPairs[i].mEffect1 = 0;
            e->mEffectIds[i] = -1;
        }
    }
}

void StopKartWaterEffects(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mWaterEffect0 != 0) {
        e->mWaterEffect0->mUnk_98_8 = 1;
        e->mWaterEffect0 = 0;
    }
    if (e->mWaterEffect1 != 0) {
        e->mWaterEffect1->mUnk_98_8 = 1;
        e->mWaterEffect1 = 0;
    }
}

// Deletes the current, side and water effects of the kart at once.
void ReleaseKartSurfaceEffects(Kart *p) {
    KartEffects *e;

    e = &gKartEffects[p->mIndex];
    if (e->mCurrentEffect != NULL) {
        func_0208b710(e->mCurrentEffect);
        e->mCurrentEffect = NULL;
        e->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(p, 1);
    e = &gKartEffects[p->mIndex];
    if (e->mWaterEffect0 != 0) {
        func_0208b710(e->mWaterEffect0);
        e->mWaterEffect0 = 0;
    }
    if (e->mWaterEffect1 == 0) {
        return;
    }
    func_0208b710(e->mWaterEffect1);
    e->mWaterEffect1 = 0;
}

void AdvanceKartBoostCameraEffect(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 w;
    Vec3 u;
    Unk020748a8 *g;
    Kart *q;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = p->mUnk_94;
    if (GetCurrentCameraKind() != 0 || (p->mUnk_24.mUnk_00_1 != 0 && (p->mUnk_98 = p->mUnk_98 + 1, p->mUnk_98 > 5))) {
        p->mUnk_24.mUnk_00_0 = 1;
        gKartBoostCameraEffect = NULL;
        return;
    }
    if (!(q->mUnk_48 & KART_48_BOOST)) {
        p->mUnk_24.mUnk_00_1 = 1;
    }
    v = g->mViewPos;
    w.x = ((s64) g->mForward.x * 0x5000) >> 12;
    w.y = ((s64) g->mForward.y * 0x5000) >> 12;
    w.z = ((s64) g->mForward.z * 0x5000) >> 12;
    VEC_Add(&w, &v, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    h.x = -g->mForward.x;
    h.y = -g->mForward.y;
    h.z = -g->mForward.z;
    p->mUnk_50 = h;
}

void AdvanceKartCurrentEffect(Unk0201ca6c *p, s32 a) {
    Vec3 x;
    Vec3 v;
    Vec3 w;
    Kart *q;
    Vec3 *s;
    u32 n;
    s32 k;
    u32 m;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    v = q->mEffectVelocity;
    k = gKartEffectVelocityFactors[p->mUnk_98_b.mUnk_00];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    f = 1;
    if (IsKartTurnEffectsActive(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    s = &q->mUnk_138;
    w.x = ((s64) s->x * -0x5000) >> 12;
    w.y = ((s64) s->y * -0x5000) >> 12;
    w.z = ((s64) s->z * -0x5000) >> 12;
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    VEC_Add(q->mPosSource, &w, &x);
    x.x = x.x >> 4;
    x.y = x.y >> 4;
    x.z = x.z >> 4;
    v.x = ((s64) v.x * k) >> 12;
    v.y = ((s64) v.y * k) >> 12;
    v.z = ((s64) v.z * k) >> 12;
    p->mUnk_28.x = x.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = x.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = x.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = v;
}

void AdvanceKartSideEffect(Unk0201ca6c *p, s32 a) {
    s32 x;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 m;
    u32 r;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    f = 1;
    if (IsKartTurnEffectsActive(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mSideDirections[r];
    x = e->mSidePositions[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mSidePositions[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mSidePositions[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceKartSideEffectWithVelocity(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 m;
    u32 r;
    s32 k;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    v = q->mEffectVelocity;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = gKartEffectVelocityFactors[p->mUnk_98_b.mUnk_00];
    f = 1;
    if (IsKartTurnEffectsActive(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mSideDirections[r];
    x = e->mSidePositions[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mSidePositions[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mSidePositions[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    v.x = ((s64) v.x * k) >> 12;
    v.y = ((s64) v.y * k) >> 12;
    v.z = ((s64) v.z * k) >> 12;
    p->mUnk_40 = v;
}

// Keeps the water effect at the kart's side, raised by the depth below the water surface.
void AdvanceKartWaterEffect(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    u32 m;
    Kart *q;
    u32 n;
    KartEffects *e;
    u32 f;
    u32 r;
    s32 k;
    u32 g;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &gKartEffects[q->mIndex];
    v = q->mEffectVelocity;
    g = 1;
    f = 1;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = gKartEffectVelocityFactors[p->mUnk_98_b.mUnk_00];
    if (IsKartTurnEffectsActive(q) == 0) {
        if (q->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    if (f == 0) {
        if (q->mWaterDepth <= 0x5000) {
            g = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (g != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mSideDirections[r];
    x = e->mSidePositions[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mSidePositions[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mSidePositions[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_28.y = p->mUnk_28.y + (q->mWaterDepth >> 4);
    v.x = ((s64) v.x * k) >> 12;
    v.y = ((s64) v.y * k) >> 12;
    v.z = ((s64) v.z * k) >> 12;
    p->mUnk_40 = v;
}

void AdvanceOtherKartEffect(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceOtherKartEffect(p, a);
    p->mUnk_98_24 = p->mUnk_98_24 + 1;
    if (p->mUnk_98_24 >= 2) {
        p->mUnk_98_16 = (p->mUnk_98_16 == 0);
        p->mUnk_98_24 = 0;
    }
}

// Starts two effects for each pair of the other karts; each effect switches between the pair's two karts.
void StartEffectsAtOtherKarts(s32 a) {
    OtherKartEffectKind *e;
    s32 j;
    KartIndexPair *d;
    s32 k;
    u32 f;
    s32 n;
    s32 i;
    s32 m;
    Unk0201ca6c *o;

    gOtherKartPairsCopy = gOtherKartPairs[a];
    n = gOtherKartFullPairCount;
    i = n;
    if (i < 4) {
        m = gOtherKartOddCount;
        do {
            if (i != n || m == 0) {
                gOtherKartPairsCopy.mPairs[i].mFirst = -1;
            }
            gOtherKartPairsCopy.mPairs[i].mSecond = -1;
            i++;
        } while (i < 4);
    }
    e = gOtherKartEffectKinds;
    for (j = 0; j < 2; j++) {
        f = (j != 0) ? 1 : 0;
        k = 0;
        d = gOtherKartPairsCopy.mPairs;
        do {
            if (d->mFirst < 0) {
                break;
            }
            o = func_0208b60c(e->mEffectId, &data_02155a14);
            k++;
            o->mUnk_90 = e->mAdvance;
            o->mUnk_98_0 = d->mFirst;
            o->mUnk_98_8 = (d->mSecond < 0) ? 0xff : (u8) d->mSecond;
            d++;
            o->mUnk_98_16 = f;
            o->mUnk_98_24 = 0;
            o->mUnk_94_u = 0;
        } while (k < 4);
        e++;
    }
}

void PlaceOtherKartEffect(Unk0201ca6c *p, s32 a) {
    Unk0201ca6c_98 *s;
    Kart *q;
    u32 n;
    u32 f;
    u32 x;
    s32 y;
    s32 v1;
    s32 v2;
    s32 v3;

    s = &p->mUnk_98_b;
    y = s->mUnk_02;
    n = p->mUnk_94_u;
    y = (y == 0) ? s->mUnk_00 : s->mUnk_01;
    x = s->mUnk_01;
    f = 1;
    if (x > 8) {
        if (y > 8) {
            f = 0;
        }
        y = s->mUnk_00;
    }
    q = GetKart(y);
    v1 = q->mPointAlongUp.x;
    v2 = q->mPointAlongUp.y;
    v3 = q->mPointAlongUp.z;
    p->mUnk_28.x = (v1 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (v2 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (v3 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (q->mUnk_7c & 0x402000) {
        f = 0;
    }
    p->mUnk_24.mUnk_00_3 = (f == 0);
    if (n + 1 >= 0x32) {
        p->mUnk_24.mUnk_00_0 = 1;
    }
    p->mUnk_94_u = n + 1;
}

// Sets the effect speed scale, then starts the effects of two courses and ties them to the camera.
void InitCourseCameraEffects(void) {
    s32 x;
    s32 m;

    m = gRaceSetup->mEngineIndex;
    x = 0x1000;
    switch (m) {
        case 1:
            x = 0xd9a;
            break;
        case 0:
            x = 0xb33;
            break;
    }
    data_0217ae9c = FX_Div(0x1000, ((s64) x * 0x779a + 0x800) >> 12);
    gSecondCourseCameraEffect = NULL;
    gFirstCourseCameraEffect = NULL;
    switch (gRaceSetup->mCourseId) {
        case 0x25: {
            Unk0201ca6c *p;

            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                p = StartEffect(0x24, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_02082750;
                p = StartEffect(0x27, &data_02155a14);
                gSecondCourseCameraEffect = p;
                p->mUnk_90 = func_02082a10;
            } else if (GetRaceUseChainCameras() != 0) {
                p = StartEffect(0x3d, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_020824d0;
                p = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = p;
                p->mUnk_90 = func_0208266c;
            } else {
                p = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_020824d0;
                p = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = p;
                p->mUnk_90 = func_0208266c;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *p;

            if (GetRaceUseChainCameras() != 0) {
                p = StartEffect(0x3e, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_02082034;
            } else if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                p = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_020821cc;
                p = StartEffect(0x25, &data_02155a14);
                gSecondCourseCameraEffect = p;
                p->mUnk_90 = func_02082368;
            } else {
                p = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_02082034;
            }
            break;
        }
    }
}

void func_02082a10(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_MultAdd(0x5800, &v, &g->mViewPos, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082750(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    MtxFx33 m;
    Vec3 y;
    Unk020748a8 *g;
    Kart *q;
    s32 t;
    s32 k;
    s32 s;
    u16 i;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(gRaceSetup->mEntryIndex);
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_CrossProduct(&data_02155a08, &v, &x);
    t = ((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    y = data_02165984;
    k = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        t = t * 0xffffffff;
        k = data_02165938;
    }
    i = (s32) (((s64) t * 0x38e3 + 0x800) >> 12);
    MTX_RotAxis33((MtxFx43 *) &m, &x, gPairsByAngle[(i >> 4) * 2], gPairsByAngle[(i >> 4) * 2 + 1]);
    MTX_MultVec33(&y, m.mUnk_00, &y);
    h.x = y.x;
    h.y = y.y;
    h.z = y.z;
    p->mUnk_68 = (s16) ((s32) (((s64) (0x1000 - t) * 0x800 + 0x800) >> 12) + 0x800);
    p->mUnk_50 = h;
    s = data_02165954 + k;
    VEC_MultAdd(data_02165938 + (s32) (((s64) s * (s64) t + 0x800) >> 12), &v, &g->mViewPos, &u);
    u.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    u.y = u.y - (s32) (((s64) data_02165934 * t + 0x800) >> 12);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_0208266c(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_MultAdd(data_02165958, &v, &g->mViewPos, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020824d0(Unk0201ca6c *p, s32 a) {
    Vec3s16 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    Vec3 w;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    GetKart(gRaceSetup->mEntryIndex);
    v = g->mForward;
    w = data_02155a08;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_CrossProduct(&data_02155a08, &v, &x);
    w.y = w.y * 0xffffffff;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    p->mUnk_68 = 0x1000;
    p->mUnk_50 = h;
    VEC_MultAdd(data_02165964, &v, &g->mViewPos, &u);
    u.y = u.y + (data_02165968 + (s32) (((s64) g->mForward.y * data_02165960 + 0x800) >> 12));
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082368(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    Kart *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(gRaceSetup->mEntryIndex);
    v = g->mForward;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_MultAdd(0x5800, &v, &g->mViewPos, &u);
    u.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    t = ((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    if (t > 0x1000) {
        t = 0x1000;
    }
    p->mUnk_58 = ((s64) (0x1000 - t) * 0x400 + 0x800) >> 12;
}

void func_020821cc(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    s32 k;
    Kart *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = GetChaseCamera();
    q = GetKart(gRaceSetup->mEntryIndex);
    v = g->mForward;
    t = ((s64) q->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    k = 0;
    v.y = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        k = -0x5800;
    }
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    k = k * 3;
    VEC_MultAdd((s32) (((s64) k * (s64) t + 0x800) >> 12) + 0x5800, &v, &g->mViewPos, &u);
    u.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = ((s64) 0x800 * t + 0x800) >> 12;
}

void func_02082034(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Camera *g;

    if (a != 0) {
        return;
    }
    g = GetCurrentCamera();
    v = g->mForward;
    w = data_02155a14;
    if (func_0203c5e4() != 0) {
        FX_Atan2Idx(g->mHalfFovPairFirst, g->mHalfFovPairSecond);
        VEC_Subtract(&g->mPos, &g->mPrevPos, &w);
        w.x = w.x >> 4;
        w.y = w.y >> 4;
        w.z = w.z >> 4;
    }
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    }
    VEC_MultAdd(data_02165958, &v, &g->mViewPos, &u);
    u.y = u.y + (data_0216595c + (s32) (((s64) g->mForward.y * data_02165940 + 0x800) >> 12));
    VEC_Add(&u, &w, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = 0x800;
}

void func_02081f30(void) {
    Unk0201ca6c *p;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gFirstCourseCameraEffect != NULL) {
                func_0208b710(gFirstCourseCameraEffect);
                p = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = p;
                p->mUnk_90 = func_020824d0;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            func_0208b710(gSecondCourseCameraEffect);
            p = StartEffect(0x3f, &data_02155a14);
            gSecondCourseCameraEffect = p;
            p->mUnk_90 = func_0208266c;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            if (gFirstCourseCameraEffect != NULL) {
                gFirstCourseCameraEffect->mUnk_90 = func_02082034;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            func_0208b710(gSecondCourseCameraEffect);
            gSecondCourseCameraEffect = NULL;
            break;
    }
}

void SetupKartFollowEffect(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->mUnk_90 = AdvanceKartFollowEffect;
}

void AdvanceKartFollowEffect(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Kart *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = GetKart(i);
    v = q->mPosSource;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void SetupKartFollowEffectWithVelocity(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->mUnk_90 = AdvanceKartFollowEffectWithVelocity;
}

void AdvanceKartFollowEffectWithVelocity(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Kart *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = GetKart(i);
    v = q->mPosSource;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = q->mEffectVelocity;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void PlaceKartAheadEffect(Unk0201ca6c *p, Kart *q, void *a) {
    u32 r;
    u32 f;

    if (a == NULL) {
        PlaceEffectAheadAndUpOfKart(p, q, 0x733, 0xb33);
        p->mUnk_5c = (s16) (((s64) q->mScale.z * 0xb33 + 0x800) >> 12);
    } else {
        r = 1;
        PlaceEffectAheadAndUpOfKart(p, q, 0x99a, 0xe66);
        p->mUnk_6c = (s16) q->mScale.z;
        f = q->mUnk_7c;
        if (!(f & 1)) {
            if (f & 0x402000) {
                r = 0;
            }
        }
        p->mUnk_24.mUnk_00_3 = (r == 0);
    }
}

// Puts the effect ahead of the kart by b and above it by a, pointing backward.
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *p, Kart *q, s32 a, s32 b) {
    Vec3 v;
    Vec3 w;
    Vec3s16 h;
    Vec3 *s = q->mPosSource;

    v.x = s->x >> 4;
    v.y = s->y >> 4;
    v.z = s->z >> 4;
    VEC_MultAdd(((s64) q->mScale.z * b + 0x800) >> 12, &q->mUnk_138, &v, &v);
    VEC_MultAdd(((s64) q->mScale.y * a + 0x800) >> 12, &q->mUnk_12c, &v, &v);
    p->mUnk_28.x = v.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = v.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = v.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    GetKartForward(q, &w);
    w.x = -w.x;
    w.y = -w.y;
    w.z = -w.z;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    p->mUnk_50 = h;
}

void AdvanceKartAheadEffect(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceKartAheadEffect(p, GetKart(p->mUnk_98_24), p->mUnk_94);
}

void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    PlaceKartAheadEffect(p, GetKart(i), p->mUnk_94);
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}

void StartKartStarEffects(s32 a) {
    KartStarEffects *e = &gKartStarEffects[a];
    u16 i;

    i = 0;
    do {
        if (e->mEffects[i] != NULL) {
            func_0208b710(e->mEffects[i]);
        }
        e->mEffects[i] = StartEffect(gKartStarEffectIds[i], &GetKart(a)->mPointAlongUp);
        i = i + 1;
    } while (i < 3);
}

static inline s32 func_0208181c_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void AdvanceKartStarEffects(s32 a) {
    KartStarEffects *e = &gKartStarEffects[a];
    u16 i;
    s16 y;
    s16 x;
    Kart *q;
    Vec3 w;
    Vec3 v;

    q = GetKart(a);
    y = func_0208181c_inline(
        data_0216593c + func_0208181c_inline(q->mVelocityLengthRatio, data_02165950 - data_0216593c), data_02165948);
    x = func_0208181c_inline(
        data_02165944 + func_0208181c_inline(q->mVelocityLengthRatio, data_0216594c - data_02165944), data_02165948);
    i = 0;
    do {
        if (e->mEffects[i] != NULL) {
            VEC_MultAdd(((s64) q->mScale.y * data_02155854[q->mKartModelsEntry->mUnk_000] + 0x800) >> 12, &q->mUnk_12c,
                        &q->mPos, &v);
            func_0208b5b0(e->mEffects[i], &v);
            w.x = ((s64) q->mEffectVelocity.x * 0xc00) >> 12;
            w.y = ((s64) q->mEffectVelocity.y * 0xc00) >> 12;
            w.z = ((s64) q->mEffectVelocity.z * 0xc00) >> 12;
            e->mEffects[i]->mUnk_40 = w;
            e->mEffects[i]->mUnk_68 = y;
            e->mEffects[i]->mUnk_64 = x;
            e->mEffects[i]->mUnk_5c = (s16) (((s64) q->mScale.z * 0x614 + 0x800) >> 12);
        }
        i = i + 1;
    } while (i < 3);
}

void StopKartStarEffects(s32 a) {
    KartStarEffects *e = &gKartStarEffects[a];
    u16 i;

    i = 0;
    do {
        if (e->mEffects[i] != NULL) {
            e->mEffects[i]->mUnk_24.mUnk_00_0 = 1;
            e->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void ReleaseKartStarEffects(s32 a) {
    KartStarEffects *e = &gKartStarEffects[a];
    u16 i;

    i = 0;
    do {
        if (e->mEffects[i] != NULL) {
            func_0208b710(e->mEffects[i]);
            e->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void StartKartKillerEffect(s32 a) {
    KartEffects *e = &gKartEffects[a];

    if (e->mKillerEffect != NULL) {
        func_0208b710(e->mKillerEffect);
    }
    e->mKillerEffect = StartEffect(0x63, &data_02155a14);
}

// Moves the Killer effect to point b and gives it the kart's velocity.
void PlaceKartKillerEffect(s32 a, Vec3 *b) {
    KartEffects *e = &gKartEffects[a];
    Unk0201ca6c *p = e->mKillerEffect;
    Kart *q;
    Vec3 *s;
    Vec3 v;

    if (p == NULL) {
        return;
    }
    p->mUnk_28.x = b->x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = b->y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = b->z + p->mUnk_20->mUnk_00->mUnk_04.z;
    q = GetKart(a);
    s = &q->mEffectVelocity;
    v.x = ((s64) s->x * 0xe66) >> 12;
    v.y = ((s64) s->y * 0xe66) >> 12;
    v.z = ((s64) s->z * 0xe66) >> 12;
    e->mKillerEffect->mUnk_40 = v;
}
