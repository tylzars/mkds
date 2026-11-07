#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "registers.h"

void UpdateCollisionSlotBounds(void) {
    s32 i = 0;
    s32 k = 0;
    s32 n;
    s32 t;
    CollisionSlot *e;
    Vec3 *v;
    s32 r;
    u16 f;
    CollisionSlotEnd *x;
    CollisionSlotEnd *y;
    u32 w;
    CollisionSlotEnd *v1;
    CollisionSlotEnd *pa;
    CollisionSlotEnd *pb;
    if (gCollisionSlotCount > 0) {
        do {
            e = &gCollisionSlots[i];
            v = e->mCenterPos;
            r = e->mRadius;
            if (v != NULL) {
                f = e->mFlags;
                if (f & 0x600) {
                    if (f & 0x100) {
                        e->mFlags = f & ~0x100;
                    } else {
                        k++;
                        goto next;
                    }
                }
                k++;
                e->mHighZ = v->z + r;
                e->mLowZ = v->z - r;
                gCollisionSlotHighEnds[e->mHighEndIndex].mEndX = (v->x + r) >> 11;
                gCollisionSlotLowEnds[e->mLowEndIndex].mEndX = (v->x - r) >> 11;
            }
        next:
            i++;
        } while (k < gCollisionSlotCount);
    }
    for (i = 1; i < gCollisionSlotCount; i++) {
        k = i;
        while ((x = &gCollisionSlotHighEnds[k], y = &gCollisionSlotHighEnds[k - 1], y->mEndX > x->mEndX) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            v1 = gCollisionSlotLowEnds;
            pa = &v1[x->mOtherEndIndex];
            pb = &v1[y->mOtherEndIndex];
            pa->mOtherEndIndex++;
            pb->mOtherEndIndex--;
            gCollisionSlots[pa->mUnk_01].mHighEndIndex++;
            gCollisionSlots[pb->mUnk_01].mHighEndIndex--;
            if (x->mUnk_01 == y->mOtherEndIndex) {
                t = x->mUnk_01;
                do {
                    t++;
                } while (gCollisionSlotLowEnds[t].mOtherEndIndex < k);
                x->mUnk_01 = t;
            }
            if (y->mUnk_01 > x->mOtherEndIndex) {
                y->mUnk_01 = x->mOtherEndIndex;
            }
            k--;
        }
    }
    for (i = 1; i < gCollisionSlotCount; i++) {
        k = i;
        while ((x = &gCollisionSlotLowEnds[k], y = &gCollisionSlotLowEnds[k - 1], y->mEndX > x->mEndX) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            gCollisionSlotHighEnds[x->mOtherEndIndex].mOtherEndIndex++;
            gCollisionSlotHighEnds[y->mOtherEndIndex].mOtherEndIndex--;
            gCollisionSlots[x->mUnk_01].mLowEndIndex++;
            gCollisionSlots[y->mUnk_01].mLowEndIndex--;
            if (x->mOtherEndIndex > y->mOtherEndIndex) {
                for (n = x->mOtherEndIndex; n > y->mOtherEndIndex && gCollisionSlotHighEnds[n].mUnk_01 == k - 1; n--) {
                    gCollisionSlotHighEnds[n].mUnk_01++;
                }
            } else {
                n = y->mOtherEndIndex;
                while (n > x->mOtherEndIndex && gCollisionSlotHighEnds[n].mUnk_01 == k) {
                    gCollisionSlotHighEnds[n--].mUnk_01--;
                }
            }
            k--;
        }
    }
}

void FindCollisionSlotsOverlappingSlot(s32 a, s32 b) {
    CollisionSlot *e;
    s32 c;
    s32 t;
    s32 q;
    s32 u;
    s32 s;
    s32 d;
    s32 f;
    CollisionSlotEnd *y;
    s32 p;
    CollisionSlotEnd *x;
    s32 m;
    s32 h;
    s16 l;
    u32 i;
    CollisionSlot *o;
    u16 g;
    if (a < 0 || a >= 0x100) {
        return;
    }
    e = &gCollisionSlots[(s16) a];
    p = e->mHighEndIndex;
    u = e->mLowEndIndex;
    q = u;
    x = gCollisionSlotHighEnds;
    y = gCollisionSlotLowEnds;
    s = gCollisionSlotCount - 1;
    c = x[p].mEndX;
    t = y[u].mEndX;
    d = e->mHighZ;
    f = e->mLowZ;
    if (e->mCenterPos == NULL) {
        gFoundCollisionSlotCount = 0;
        return;
    }
    gFoundCollisionSlotCount = 0;
    while (p > 7 && x[p - 8].mEndX >= t) {
        p -= 8;
    }
    while (p > 0 && x[p - 1].mEndX >= t) {
        p--;
    }
    m = s - 7;
    while (q < m && y[q + 8].mEndX <= c) {
        q += 8;
    }
    while (q < s && y[q + 1].mEndX <= c) {
        q++;
    }
    h = (s16) q;
    i = x[p].mUnk_01;
    l = i;
    if (h < l) {
        return;
    }
    for (;;) {
        if (gCollisionSlotLowEnds[h].mOtherEndIndex >= p && h != u) {
            o = &gCollisionSlots[gCollisionSlotLowEnds[h].mUnk_01];
            g = o->mFlags;
            if (o->mHighZ < f || o->mLowZ > d || !(g & b) || (g & 0x200)) {
                goto next;
            }
            gFoundCollisionSlotIndices[gFoundCollisionSlotCount] = gCollisionSlotLowEnds[h].mUnk_01;
            gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = g;
            gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = o->mObject;
            gFoundCollisionSlotCount++;
            if (gFoundCollisionSlotCount == 0x80) {
                return;
            }
        }
        if (h == 0) {
            return;
        }
    next:
        h--;
        if (h < l) {
            break;
        }
    }
}

s32 ComputeViewTest(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    s32 q;
    s32 f;
    s32 g;
    c = (c + b) >> 12;
    z = (a->z - gViewFrustum.mCameraPos.z) >> 12;
    x = (a->x - gViewFrustum.mCameraPos.x) >> 12;
    f = x * x;
    q = z * z + f;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_usa_021568f8;
    }
    y = (a->y - gViewFrustum.mCameraPos.y) >> 12;
    if (x * gViewFrustum.mViewDirection.x + y * gViewFrustum.mViewDirection.y + z * gViewFrustum.mViewDirection.z <
        gViewFrustum.mNear - b) {
        return r | 2;
    }
    if (x * gViewFrustum.mUnk_20.x + y * gViewFrustum.mUnk_20.y + z * gViewFrustum.mUnk_20.z > b) {
        return r | 2;
    }
    if (x * gViewFrustum.mUnk_2c.x + y * gViewFrustum.mUnk_2c.y + z * gViewFrustum.mUnk_2c.z > b) {
        return r | 2;
    }
    if (x * gViewFrustum.mUnk_38.x + y * gViewFrustum.mUnk_38.y + z * gViewFrustum.mUnk_38.z > b) {
        return r | 2;
    }
    g = x * gViewFrustum.mUnk_44.x;
    if (z * gViewFrustum.mUnk_44.z + (y * gViewFrustum.mUnk_44.y + g) > b) {
        r |= 2;
    }
    return r;
}

static inline s32 func_01ffd648_inline(ViewFrustum *g) {
    return g->mUnk_20.y;
}

s32 ComputeTwoPlaneViewTest(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    Vec3 v;
    s32 r;
    s32 q;
    s32 h;
    c = (c + b) >> 12;
    VEC_Subtract(a, &gViewFrustum.mCameraPos, &v);
    v.x = (a->x - gViewFrustum.mCameraPos.x) >> 12;
    v.z = (a->z - gViewFrustum.mCameraPos.z) >> 12;
    q = v.x * v.x + v.z * v.z;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_usa_021568f8;
    }
    v.y = (a->y - gViewFrustum.mCameraPos.y) >> 12;
    h = ((const Vec3 *) &v)->x;
    if (v.y * func_01ffd648_inline(&gViewFrustum) + v.x * gViewFrustum.mUnk_20.x + v.z * gViewFrustum.mUnk_20.z > b) {
        return r | 2;
    }
    if (h * gViewFrustum.mUnk_2c.x + v.y * gViewFrustum.mUnk_2c.y + v.z * gViewFrustum.mUnk_2c.z > b) {
        r |= 2;
    }
    return r;
}

void AdvanceKartAiHeading(struct KartAi *p, Vec3 *a, Vec3 *b) {
    Kart *q = p->mKart;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v6;
    Vec3 v4;
    Vec3 v7;
    Vec3 v5;
    Vec3 v8;
    Vec3 v11;
    Vec3 v10;
    Vec3 v9;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    BOOL r;
    Vec3 *u;
    Kart *o;
    if (q->mState != KART_STATE_NORMAL) {
        return;
    }
    if (q->mUnk_44 & 2) {
        return;
    }
    if (q->mUnk_4c & 0x10000000) {
        return;
    }
    r = FALSE;
    CallKartAiLinkPosAndDirection(&v0, &v1, p);
    if (p->mUnk_a8 == 1) {
        u = &q->mUnk_12c;
        d = VEC_DotProduct(u, &v1);
        v5.x = v1.x - (s32) (((s64) u->x * d) >> 12);
        v5.y = v1.y - (s32) (((s64) u->y * d) >> 12);
        v5.z = v1.z - (s32) (((s64) u->z * d) >> 12);
        if (Vec3DotUnrounded(&q->mUnk_138, &v5) > -0x333) {
            CallKartAiLinkPosAndDirection(&v2, &v3, p);
            o = p->mKart;
            r = TRUE;
            VEC_Subtract(&o->mPos, &v2, &v9);
            v9.y = 0;
            GetKartUp(o, &v8);
            d = VEC_DotProduct(&v8, &v3);
            v10.x = v3.x - (s32) (((s64) v8.x * d) >> 12);
            v10.y = v3.y - (s32) (((s64) v8.y * d) >> 12);
            v10.z = v3.z - (s32) (((s64) v8.z * d) >> 12);
            Vec3CrossUnrounded(&v9, &v10, &v11);
            g = Vec3DotUnrounded(&v8, &v11) > 0 ? 1 : -1;
            q->mHeadingAngle += g * 200;
            goto end;
        }
    }
    if (p->mTurnAngleDegrees > 0x2000) {
        e = ((s64) q->mVelocityLength * *data_usa_0217ae40) >> 12;
        if (e > 0x1000) {
            e = 0x1000;
        }
        GetKartUp(q, &v6);
        d = VEC_DotProduct(&v6, a);
        v7.x = a->x - (s32) (((s64) v6.x * d) >> 12);
        v7.y = a->y - (s32) (((s64) v6.y * d) >> 12);
        v7.z = a->z - (s32) (((s64) v6.z * d) >> 12);
        Vec3CrossUnrounded(b, &v7, &v4);
        q->mHeadingAngle +=
            (g = Vec3DotUnrounded(&v6, &v4) > 0 ? 1 : -1) *
            ((s32) (((s64) ((s32) (((s64) p->mTurnAngleDegrees * 0xB60B60B60BLL + 0x80000000LL) >> 32)) *
                     (s32) (((s64) e * 0xa4) >> 12)) >>
                    12) >>
             12);
        r = TRUE;
    }
    if ((q->mUnk_4c & 0x8000000) && p->mTurnAngleDegrees < 0x46000 && (q->mUnk_44 & KART_44_ON_GROUND) &&
        !(q->mUnk_48 & 0x8020) && q->mVelocityLength > 0x3000 && p->mUnk_90 != 2 && p->mUnk_a8 == 0) {
        p->mUnk_c8 += 0x44c;
        p->mUnk_ca = ((s64) gPairsByAngle[(p->mUnk_c8 >> 4) * 2] * 0xfa + 0x800) >> 12;
        q->mHeadingAngle += (s16) p->mUnk_ca * p->mUnk_cc;
        r = TRUE;
    } else {
        p->mUnk_ca = 0;
        p->mUnk_c8 = 0;
    }
end:
    if (r == FALSE) {
        return;
    }
    if (g > 0) {
        q->mUnk_48 |= KART_48_TURN_LEFT;
    } else {
        q->mUnk_48 |= KART_48_TURN_RIGHT;
    }
}

void QuaternionFromAxisAngle(const Vec3 *a, s32 b, Vec4 *c) {
    s32 i = (s32) ((u32) (b << 15) >> 16) >> 4;
    s32 s = gPairsByAngle[i * 2];
    c->x = ((s64) a->x * s + 0x800) >> 12;
    c->y = ((s64) a->y * s + 0x800) >> 12;
    c->z = ((s64) a->z * s + 0x800) >> 12;
    c->w = gPairsByAngle[i * 2 + 1];
}

s32 TryQuaternionFromVectors(Vec4 *a, const Vec3 *b, const Vec3 *c) {
    Vec3 v;
    s32 r;
    BOOL k = TRUE;
    VEC_CrossProduct(b, c, &v);
    r = FX_Sqrt((VEC_DotProduct(b, c) + 0x1000) << 1);
    *a = data_usa_02155194;
    if (r <= 0) {
        k = FALSE;
    } else {
        a->x = FX_Div(v.x, r);
        a->y = FX_Div(v.y, r);
        a->z = FX_Div(v.z, r);
        a->w = r >> 1;
    }
    return k;
}

void QuaternionNormalize(const Vec4 *a, Vec4 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) a->x * a->x;
    w += (s64) a->y * a->y;
    w += (s64) a->z * a->z;
    w += (s64) a->w * a->w;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->y = (t * a->y + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
    b->w = (t * a->w + 0x100000000000LL) >> 45;
}
