#include "Main/Unknown/code_020ed5c0.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/unk_0216c000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "code_02147cd8.h"

BOOL func_020ee528(ItemInUse *a) {
    Kart *p;
    Vec3 v;
    s32 s;

    p = a->mKart;
    a->mUnk_02c = *(Unk020eda5c_02c *) &p->mUnk_150;
    a->mUnk_050 = p->mUnk_98;
    a->mKartVelocity = p->mVelocity;
    a->mKartVelocityLength = p->mVelocityLength;
    a->mUnk_078 = ((s64) p->mPhysicalParam->mUnk_08 * p->mScale.z + 0x800) >> 12;
    a->mKartHopHeight = p->mHopHeight;
    a->mUnk_080 = Vec3DotUnrounded(&a->mUnk_02c.mUnk_18, &a->mKartVelocity) > 0;
    VEC_Subtract(&a->mUnk_050, &p->mPrevPos, &a->mUnk_06c);
    v.x = ((s64) p->mScaleFactor.x * p->mScaleBase.x) >> 12;
    v.y = ((s64) p->mScaleFactor.y * p->mScaleBase.y) >> 12;
    v.z = ((s64) p->mScaleFactor.z * p->mScaleBase.z) >> 12;
    s = (a->mUnk_084.x == v.x && a->mUnk_084.y == v.y && a->mUnk_084.z == v.z) ? 1 : 0;
    if (s == 0) {
        a->mUnk_084 = v;
        return TRUE;
    }
    return FALSE;
}

void StartItemInUse(ItemInUse *a, Unk020f40dc *b) {
    void (*f1)(void *);
    s32 t;
    s32 k;
    void (*f2)(void *, void *);
    BOOL s;
    ItemObject **v;
    s32 n;
    ItemObject *q;
    s32 i;
    u16 *r;
    s32 u;

    k = b->mUnk_00;
    t = gItemInfos[k].mUseKind;
    s = data_021759c0->mMode == 5;
    if (b->mUnk_0c != 0) {
        if (b->mUnk_10 > b->mUnk_12) {
            return;
        }
    }
    f1 = gItemInUseStartTable[t];
    f2 = gItemInfos[k].mUseHook;
    if (!s) {
        func_020be8e4(a->mKartIndex, k, b->mUnk_08);
    }
    if (t == ITEM_USE_KIND_HOOK_ONLY) {
        if (f1 != NULL) {
            f1(a);
        }
        if (f2 != NULL) {
            f2(a, b);
        }
        func_02071894(a->mKart);
        return;
    }
    a->mObjectKind = gItemInfos[k].mObjectKind;
    a->mObjectCount = gItemInfos[k].mObjectCount;
    a->mUseKind = t;
    a->mItemInfoIndex = k;
    a->mUnk_170 = NULL;
    a->mUnk_0e8 = gItemInfos[k].mObjectKind == 8 ? 0xb400 : 0x4333;
    u = *(vs32 *) &a->mObjectKind;
    TakeItemPoolObjects(&gItemPools[u], a->mObjectCount, a->mObjects, a->mKart->mIndex, &a->mUnk_050);
    func_020ee528(a);
    if (f1 != NULL) {
        f1(a);
    }
    if (f2 != NULL) {
        f2(a, b);
    }
    func_0206c11c(a->mKart);
    func_020f4718(b);
    if (a->mUnk_170 != NULL) {
        SetActiveItem(a->mKartItems, a->mItemInfoIndex);
    }
    v = a->mObjects;
    r = &a->mKart->mKartModelsEntry->mUnk_040;
    n = a->mObjectCount;
    for (i = 0; i < n; i++) {
        q = v[i];
        q->mAgeFrames = 0;
        q->mPrevPos = q->mPos;
        q->mVelocity = a->mKartVelocity;
        func_020f9f08(q, a->mUnk_084.x, a->mUnk_084.y);
        q->mUnk_90 = r;
        q->mFlags |= 0x1000;
    }
}

BOOL func_020ee284(ItemObject *p, Vec3 *v, s32 d) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    t = d + p->mUnk_e0;
    x = p->mPos.x - v->x;
    y = p->mPos.y - v->y;
    z = p->mPos.z - v->z;
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

void func_020ee160(ItemObject *a, ItemObject *b) {
    Vec3 v;
    s32 n;
    s32 m;

    if ((b->mFlags & 0x1000) != 0) {
        if (a->mUnk_48 > b->mUnk_48) {
            return;
        }
    }
    if (func_020ee284(a, &b->mPos, b->mUnk_e0) == FALSE) {
        if (func_020ee284(a, &b->mPrevPos, b->mUnk_e0) == FALSE) {
            return;
        }
        if (func_020ee284(b, &a->mPrevPos, a->mUnk_e0) == FALSE) {
            return;
        }
    }
    v = a->mVelocity;
    n = func_020f7ea8(a, b);
    m = func_020f7ea8(b, a);
    func_020f77f8(a, n, &b->mPos, &b->mVelocity, NULL);
    func_020f77f8(b, m, &a->mPos, &v, NULL);
    if (b->mKind != 1) {
        return;
    }
    func_020f5614(b, m, a);
}

void func_020edf10(ItemInUse *p) {
    ItemObject **d;
    s32 n;
    ItemObject *q;
    s32 i;
    s32 a;
    s32 b;
    s32 j;
    enum { K0 } idx;

    d = p->mObjects;
    n = p->mObjectCount;
    a = func_0206c0a8(p->mKart);
    b = func_0206c094(p->mKart);
    for (i = 0; i < n; i++) {
        q = d[i];
        q->mAgeFrames = q->mAgeFrames + 1;
        VEC_Subtract(&q->mPos, &q->mPrevPos, &q->mVelocity);
        q->mPrevPos = q->mPos;
        if (p->mObjectStartFramesLeft == 0) {
            q->mUnk_f0 = p->mUnk_02c.mUnk_0c;
            if (q->mUnk_f0.y < 0xff4) {
                q->mFlags |= 0x80;
            }
        }
        if (a != 0) {
            q->mFlags |= 0x40000;
        } else {
            q->mFlags &= ~0x40000;
        }
        if (b != 0) {
            q->mFlags |= 0x10000;
        } else {
            q->mFlags &= ~0x10000;
        }
    }
    for (j = n - 1; j >= 0; j--) {
        q = d[j];
        if (q->mUnk_da == -1) {
            if (func_020f91e0(q) != FALSE) {
                idx = q->mKind;
                if (gItemKinds[idx].mUnk_68 != 0) {
                    func_020f9ca8(q);
                }
            }
            continue;
        }
        func_01ffd900(q->mUnk_da, 0x6000);
        for (i = 0; i < data_0217b5a8; i++) {
            if ((data_0217b5bc[i] & 0x4000) != 0) {
                ItemObject *e = data_0217b5c4[i];
                if (e->mUnk_da == -1) {
                    continue;
                }
                if ((e->mUnk_78 & 0x4000) != 0 && p->mKartIndex == (u16) (e->mUnk_78 & ~0xff00)) {
                    continue;
                }
                func_020ee160(q, e);
            } else if ((data_0217b5bc[i] & 0x2000) != 0) {
                MapObject *e = data_0217b5c4[i];
                if (func_020d2234(e, q) == FALSE) {
                    continue;
                }
                func_020f944c(q, e);
            }
            if (q->mUnk_da == -1) {
                break;
            }
        }
    }
}

void AdvanceItemInUse(ItemInUse *p) {
    s32 id;
    s32 n;
    s32 m;
    ItemObject *q;
    Kart *o;
    enum { K0 } k;

    id = p->mUseKind;
    if (func_020ee528(p) != FALSE) {
        m = p->mObjectCount;
        for (n = 0; n < m; n++) {
            func_020f9f08(p->mObjects[n], p->mUnk_084.x, p->mUnk_084.y);
        }
    }
    if (gItemInUseAdvanceTable[id] != NULL) {
        gItemInUseAdvanceTable[id](p);
    }
    func_020edf10(p);
    if (p->mObjectCount == 0) {
        ResetItemInUse(p);
    }
    if (p->mObjectStartFramesLeft <= 0) {
        return;
    }
    p->mObjectStartFramesLeft = p->mObjectStartFramesLeft - 1;
    if (p->mObjectStartFramesLeft != 8 && p->mObjectStartFramesLeft != 4 && p->mObjectStartFramesLeft != 0) {
        return;
    }
    p->mObjectCount = p->mObjectCount - 1;
    n = p->mObjectCount;
    o = p->mKart;
    q = p->mObjects[n];
    StartItemInUseObject(p, q);
    func_020f6630(q, n + 1, &o->mUnk_98, &o->mVelocity, &o->mUnk_244);
    k = q->mKind;
    if (gItemKinds[k].mUnk_38 != NULL) {
        gItemKinds[k].mUnk_38(q);
    }
    if (p->mObjectCount != 0) {
        return;
    }
    ResetItemInUse(p);
}

s32 func_020edc9c(ItemInUse *p, s32 a, s32 b, s32 c, Vec3 *d) {
    Vec3 v;
    s32 n;
    s32 r;

    n = VEC_Mag(&p->mUnk_06c);
    if (p->mUnk_080 != 0) {
        r = a + (s32) (((s64) n * b) >> 12);
        VEC_MultAdd(c, &p->mUnk_02c.mUnk_18, &p->mUnk_06c, &v);
    } else {
        Vec3 *t;

        t = &p->mKart->mUnk_1fc;
        if ((s64) t->x * t->x + (s64) t->y * t->y + (s64) t->z * t->z >= 0x10) {
            r = a + (s32) (((s64) n * b) >> 12);
            VEC_MultAdd(c, &p->mUnk_02c.mUnk_18, t, &v);
        } else {
            r = a - n;
            v = p->mUnk_02c.mUnk_18;
        }
    }
    if ((p->mKart->mUnk_48 & 1) == 0) {
        v.y = 0;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&v, d);
    }
    return r;
}

s32 func_020edb8c(ItemInUse *p, s32 a, s32 b, s32 c, Vec3 *d) {
    Vec3 v;
    s32 n;

    n = VEC_Mag(&p->mUnk_06c);
    if (p->mUnk_080 != 0) {
        a -= n;
        VEC_Subtract(&p->mUnk_06c, &p->mKart->mUnk_1fc, &v);
        VEC_MultAdd(c, &p->mUnk_02c.mUnk_18, &v, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    } else {
        a += (s32) (((s64) n * b) >> 12);
        v.x = -p->mUnk_02c.mUnk_18.x;
        v.y = -p->mUnk_02c.mUnk_18.y;
        v.z = -p->mUnk_02c.mUnk_18.z;
    }
    if ((p->mKart->mUnk_48 & 1) == 0) {
        v.y = 0;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&v, d);
    }
    return a;
}

void func_020edb00(ItemInUse *p) {
    while (p->mObjectCount > 0) {
        p->mObjectCount--;
        ReleaseItemPoolObject(&gItemPools[p->mObjects[p->mObjectCount]->mKind], p->mObjects[p->mObjectCount]);
    }
    ResetItemInUse(p);
    if (p->mUnk_170 != NULL) {
        p->mKartItems->mActiveItem = 0x13;
        p->mUnk_170 = NULL;
    }
}

void func_020edad8(ItemInUse *p) {
    p->mObjectStartFramesLeft = 0xa;
    if (p->mUnk_170 != NULL) {
        p->mKartItems->mActiveItem = 0x13;
        p->mUnk_170 = NULL;
    }
}

void RemoveItemInUseObject(ItemInUse *p, ItemObject *q) {
    s32 n;
    ItemObject *e;
    s32 i;

    e = q;
    n = p->mObjectCount;
    for (i = 0; i < n; i++) {
        if (p->mObjects[i] == e) {
            ((void (*)(void *, s32, ItemObject *))((void **) gItemInUseRemoveTable)[p->mUseKind])(p, i, e);
            if (p->mObjectCount != 0) {
                return;
            }
            ResetItemInUse(p);
            return;
        }
    }
}

void *func_020ed98c(ItemObject *p, Vec3 *v) {
    if (p->mUnk_f0.y < 0xfae || (p->mFlags & 0x80) != 0) {
        p->mUnk_94.mUnk_00[2] = *v;
        Vec3CrossUnrounded(&p->mUnk_f0, &p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_94.mUnk_00[0].x * p->mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_94.mUnk_00[0].y * p->mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_94.mUnk_00[0].z * p->mUnk_94.mUnk_00[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[0]);
        }
        Vec3CrossUnrounded(&p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[1]);
        {
            Vec3 *d0;

            d0 = p->mUnk_d0;
            p->mUnk_94.mUnk_00[3].x = d0->x >> 4;
            p->mUnk_94.mUnk_00[3].y = d0->y >> 4;
            p->mUnk_94.mUnk_00[3].z = d0->z >> 4;
        }
        return &p->mUnk_94.mUnk_00[0];
    } else {
        return func_020e6b94(p->mUnk_d0);
    }
}

void func_020ed79c(Unk020ed718 *p, Vec3 *v) {
    s16 d8;
    s32 i;
    Unk020e6488 *d;
    s32 n;
    s32 sel;
    ItemObject *q;
    void *r;

    d = gItemModels[p->mUnk_000];
    n = p->mUnk_010;
    sel = p->mUnk_014;
    func_020e6a18(d);
    d->mUnk_14 &= ~0x3f000000;
    d->mUnk_14 |= 0x4000000;
    for (i = 0; i < n; i++) {
        q = p->mUnk_004[i];
        if ((q->mFlags & 0x10000) != 0) {
            continue;
        }
        if ((q->mFlags & 0x1000) != 0) {
            func_0208ab4c(q->mUnk_90);
        } else {
            func_0208ab4c(q->mUnk_7c.mUnk_00);
        }
        if ((d8 = q->mUnk_d8) != 0x1f) {
            d->mUnk_14 &= ~0x1f0000;
            d->mUnk_14 |= (u16) d8 << 16;
        }
        if (i == sel) {
            d->mUnk_14 &= ~0x3f000000;
            d->mUnk_14 |= 0x3000000;
        }
        if (q->mUnk_f0.y < 0xfae || (q->mFlags & 0x80) != 0) {
            q->mUnk_94.mUnk_00[2] = *v;
            Vec3CrossUnrounded(&q->mUnk_f0, &q->mUnk_94.mUnk_00[2], &q->mUnk_94.mUnk_00[0]);
            if ((s64) q->mUnk_94.mUnk_00[0].x * q->mUnk_94.mUnk_00[0].x +
                    (s64) q->mUnk_94.mUnk_00[0].y * q->mUnk_94.mUnk_00[0].y +
                    (s64) q->mUnk_94.mUnk_00[0].z * q->mUnk_94.mUnk_00[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&q->mUnk_94.mUnk_00[0], &q->mUnk_94.mUnk_00[0]);
            }
            Vec3CrossUnrounded(&q->mUnk_94.mUnk_00[2], &q->mUnk_94.mUnk_00[0], &q->mUnk_94.mUnk_00[1]);
            {
                Vec3 *d0;

                d0 = q->mUnk_d0;
                q->mUnk_94.mUnk_00[3].x = d0->x >> 4;
                q->mUnk_94.mUnk_00[3].y = d0->y >> 4;
                q->mUnk_94.mUnk_00[3].z = d0->z >> 4;
            }
            r = &q->mUnk_94.mUnk_00[0];
        } else {
            r = func_020e6b94(q->mUnk_d0);
        }
        func_020e67c4(d, r, &q->mUnk_68, 0, 0x1f);
        if ((d8 = q->mUnk_d8) != 0x1f) {
            d->mUnk_14 &= ~0x1f0000;
            d->mUnk_14 |= 0x1f0000;
        }
    }
}

void func_020ed718(Unk020ed718 *p, void *a, void (*cb)(void *, void *, void *)) {
    s32 n;
    s32 i;
    ItemObject *q;

    n = p->mUnk_010;
    for (i = 0; i < n; i++) {
        q = p->mUnk_004[i];
        if ((q->mFlags & 0x10000) != 0) {
            continue;
        }
        if ((q->mFlags & 0x1000) != 0) {
            func_0208ab4c(q->mUnk_90);
        } else {
            func_0208ab4c(q->mUnk_7c.mUnk_00);
        }
        cb(q, a, gItemModels[p->mUnk_000]);
    }
}

void func_020ed5c0(ItemObject *p, Unk020e6488 *q, Vec3 *v) {
    s16 d;
    void *r;

    if ((d = p->mUnk_d8) != 0x1f) {
        q->mUnk_14 &= ~0x1f0000;
        q->mUnk_14 |= (u16) d << 16;
    }
    func_020e6a18(q);
    if (p->mUnk_f0.y < 0xfae || (p->mFlags & 0x80) != 0) {
        p->mUnk_94.mUnk_00[2] = *v;
        Vec3CrossUnrounded(&p->mUnk_f0, &p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_94.mUnk_00[0].x * p->mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_94.mUnk_00[0].y * p->mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_94.mUnk_00[0].z * p->mUnk_94.mUnk_00[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[0]);
        }
        Vec3CrossUnrounded(&p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[1]);
        {
            Vec3 *d0;

            d0 = p->mUnk_d0;
            p->mUnk_94.mUnk_00[3].x = d0->x >> 4;
            p->mUnk_94.mUnk_00[3].y = d0->y >> 4;
            p->mUnk_94.mUnk_00[3].z = d0->z >> 4;
        }
        r = &p->mUnk_94.mUnk_00[0];
    } else {
        r = func_020e6b94(p->mUnk_d0);
    }
    func_020e67c4(q, r, &p->mUnk_68, 0, 0x1f);
    if ((d = p->mUnk_d8) != 0x1f) {
        q->mUnk_14 &= ~0x1f0000;
        q->mUnk_14 |= 0x1f0000;
    }
}
