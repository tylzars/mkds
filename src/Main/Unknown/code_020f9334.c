#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

BOOL func_020f9c08(ItemObject *param_1) {
    if (param_1->mAgeFrames > 0x12c && (param_1->mFlags & 0x8000) != 0 &&
        param_1->mUnk_120 == (void (*)(ItemObject *)) func_020f68b0) {
        return TRUE;
    }
    return FALSE;
}

void func_020f9ba8(ItemObject *param_1) {
    if (param_1->mAgeFrames <= 0x12c) {
        return;
    }
    if ((param_1->mFlags & 0x8000) == 0) {
        return;
    }
    if (param_1->mUnk_120 != (void (*)(ItemObject *)) func_020f68b0) {
        return;
    }
    func_020f7658(param_1, 1);
}

void func_020f9b0c(ItemObject *param_1) {
    if ((param_1->mFlags & 0x8000) != 0) {
        func_020f7658(param_1, 1);
        return;
    }
    param_1->mVelocity.x = ((s64) param_1->mVelocity.x * 0x99a) >> 12;
    param_1->mVelocity.y = ((s64) param_1->mVelocity.y * 0x99a) >> 12;
    param_1->mVelocity.z = ((s64) param_1->mVelocity.z * 0x99a) >> 12;
    func_020f6fc4(param_1, 1);
}

void ResetItemObject(ItemObject *param_1, s32 param_2) {
    void (*f)(void *);

    f = gItemKinds[param_2].mReset;
    param_1->mKind = param_2;
    param_1->mFlags = 0;
    param_1->mUnk_7a = 0;
    param_1->mUnk_68.x = 0;
    param_1->mUnk_68.y = 0;
    param_1->mUnk_68.z = 0;
    param_1->mUnk_100 = 0;
    param_1->mUnk_dc = 0x7b;
    param_1->mUnk_e0 = 0x7b;
    param_1->mUnk_d8 = 0x1f;
    param_1->mUnk_fc = 0;
    param_1->mUnk_118 = 0;
    param_1->mUnk_114 = 5;
    param_1->mUnk_124 = NULL;
    param_1->mUnk_d0 = &param_1->mPos;
    param_1->mUnk_da = -1;
    param_1->mUnk_104->mUnk_00 = NULL;
    if (gRaceSetup->mMode == 5) {
        param_1->mFlags |= 0x8000000;
    }
    param_1->mUnk_78 |= data_02159cac;
    func_0208adc8(param_1->mUnk_7c.mUnk_00, 1);
    param_1->mUnk_90 = NULL;
    if (f != NULL) {
        f(param_1);
    }
    param_1->mUnk_128 = 0;
}

void ResetItemObjectAtPos(ItemObject *param_1, s32 param_2, u16 param_3, Vec3 *param_4) {
    param_1->mPos = *param_4;
    param_1->mUnk_78 = param_3;
    ResetItemObject(param_1, param_2);
    if ((param_1->mFlags & 0x8000000) == 0) {
        return;
    }
    param_1->mId = ComputeItemObjectId(param_1);
}

void ReleaseItemObject(ItemObject *param_1) {
    enum { K0 } k;

    if (param_1->mUnk_da != -1) {
        param_1->mUnk_da = func_020d5344(param_1->mUnk_da);
    }
    if ((param_1->mFlags & 0x400000) != 0) {
        func_02109054(&param_1->mSoundSource);
        param_1->mSoundSource.mUnk_30 = NULL;
        param_1->mFlags &= ~0x400000;
    }
    param_1->mFlags |= 4;
    k = param_1->mKind;
    if (gItemKinds[k].mRelease != NULL) {
        gItemKinds[k].mRelease(param_1);
    }
}

void func_020f98a0(ItemObject *param_1, Vec3 *param_2, Vec3 *param_3, u16 *param_4, s32 param_5) {
    ItemObject *a = param_1;
    a->mPrevPos = *param_2;
    if (param_4 != NULL) {
        a->mUnk_7c = *(Unk020f41c4_C *) param_4;
    } else {
        func_0208adc8(a->mUnk_7c.mUnk_00, 1);
    }
    a->mUnk_f0 = *param_3;
    a->mUnk_116 = param_5 != 0 ? 0 : 5;
}

s32 func_020f9880(ItemObject *param_1) {
    return gItemKinds[param_1->mKind].mUnk_84;
}

BOOL func_020f97e0(ItemObject *param_1, Kart *param_2) {
    Vec3 d;
    s32 n;

    if (param_1->mUnk_da == -1 ||
        param_2->mIndex == (u16) ((param_1->mUnk_78 & 0x4000) != 0 ? (u16) (param_1->mUnk_78 & ~0xff00) : 8)) {
        return FALSE;
    }
    n = param_2->mRadius + param_1->mUnk_e0;
    d.x = param_1->mPos.x - param_2->mUnk_1d8.x;
    d.y = param_1->mPos.y - param_2->mUnk_1d8.y;
    d.z = param_1->mPos.z - param_2->mUnk_1d8.z;
    return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
}

BOOL IsItemObjectOverlappingSphere(ItemObject *param_1, Vec3 *param_2, s32 param_3) {
    Vec3 d;
    s32 n;

    n = param_3 + param_1->mUnk_e0;
    d.x = param_1->mPos.x - param_2->x;
    d.y = param_1->mPos.y - param_2->y;
    d.z = param_1->mPos.z - param_2->z;
    return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
}

void func_020f95d4(ItemObject *param_1, ItemObject *param_2) {
    Vec3 v;
    s32 a;
    s32 b;

    if (param_2->mUnk_da == -1) {
        return;
    }
    if ((param_2->mFlags & 0x1000) != 0) {
        return;
    }
    if ((param_2->mFlags & 0x8000) == 0) {
        if (param_1->mUnk_48 > param_2->mUnk_48) {
            return;
        }
    }
    if ((param_1->mFlags & 0x10000000) != 0 && (param_2->mFlags & 0x10000000) != 0) {
        if (func_020f7ea8(param_1, param_2) != 1 && func_020f7ea8(param_2, param_1) != 1) {
            return;
        }
    }
    if (IsItemObjectOverlappingSphere(param_1, &param_2->mPos, param_2->mUnk_e0) == FALSE) {
        if (IsItemObjectOverlappingSphere(param_1, &param_2->mPrevPos, param_2->mUnk_e0) == FALSE) {
            return;
        }
        if (IsItemObjectOverlappingSphere(param_2, &param_1->mPrevPos, param_1->mUnk_e0) == FALSE) {
            return;
        }
    }
    v = param_1->mVelocity;
    a = func_020f7ea8(param_1, param_2);
    b = func_020f7ea8(param_2, param_1);
    func_020f77f8(param_1, a, &param_2->mPos, &param_2->mVelocity, NULL);
    func_020f77f8(param_2, b, &param_1->mPos, &v, NULL);
    if (param_1->mKind == 1) {
        func_020f5614(param_1, a, param_2);
    }
    if (param_2->mKind != 1) {
        return;
    }
    func_020f5614(param_2, b, param_1);
}

void func_020f944c(ItemObject *param_1, MapObject *param_2) {
    Vec3 a;
    Vec3 t;
    s32 b;
    MapObject *q;
    ItemObject *p = param_1;
    MapObject *r = param_2;

    if (IsSphereHittingMapObject(&p->mPos, p->mUnk_e0, r, &a) == FALSE) {
        return;
    }
    if ((r->mFlags & 0x40) == 0 && (p->mFlags & 0x80000) == 0 && func_020d6968(p->mKind, r) != 0) {
        VEC_Add(&p->mPos, &a, &p->mPos);
    }
    switch (func_020d6a54(p, r, &b)) {
        case 1:
            t.x = r->mPos.x;
            t.y = p->mPos.y;
            t.z = r->mPos.z;
            a = t;
            if (b == 1 || (r->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                r->mDistanceSquaredAndFlags &= ~0x80000000;
                q = r;
            } else {
                r->mDistanceSquaredAndFlags &= ~0x80000000;
                q = NULL;
            }
            func_020f77f8(p, 1, &a, &r->mUnk_10, q);
            p->mUnk_78 &= ~0x4000;
            return;
        case 2:
            if (b == 1 || (r->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                r->mDistanceSquaredAndFlags &= ~0x80000000;
                q = r;
            } else {
                r->mDistanceSquaredAndFlags &= ~0x80000000;
                q = NULL;
            }
            func_020f77f8(p, 2, &r->mPos, &r->mUnk_10, q);
            return;
    }
}

void func_020f9334(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, Vec3 *param_5) {
    ItemObject *p = param_1;
    Vec3 v;
    u32 a;
    s32 x;
    s32 y;
    s32 z;

    a = 0;
    z = param_2->z;
    y = param_2->y - p->mUnk_dc;
    x = param_2->x;
    v.x = x;
    v.y = y;
    v.z = z;

    func_01ffdee4(&v, param_2, 0, p->mUnk_dc >> 1, 0x24, p->mUnk_da, NULL, NULL, NULL, &a, NULL, NULL, NULL, NULL);
    if ((a & 0x1e34ef) != 0 || (p->mUnk_fc & 0x80000) != 0) {
        if ((p->mFlags & 0x4000000) != 0) {
            return;
        }
        p->mFlags |= 8;
        p->mUnk_f0 = *param_5;
        return;
    }
    param_3->z = 0;
    param_3->x = param_3->z;
    if (param_3->y > 0) {
        param_3->y = 0;
        return;
    }
    if (param_3->y > -param_4) {
        param_3->y = -param_4;
    }
}
