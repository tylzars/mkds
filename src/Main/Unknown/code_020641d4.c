#include "Main/Unknown/code_020641d4.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147288.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "code_021471bc.h"

void func_020641f0(Kart *a) {
    KartModelsEntry *b;
    Unk0206bcb0_590_08 *c;
    Vec3 m;
    MtxFx43 d;
    MtxFx43 e;
    MtxFx43 f;
    MtxFx43 g;
    MtxFx43 h;
    s32 i;
    s32 j;
    s32 k;
    u16 l;
    u32 n;
    MtxFx43 *p;
    Vec3 *q;
    Vec4 *r;
    enum { K0 } o;

    func_01ffcd84(&a->mUnk_120, a->mUnk_50c);
    n = a->mUnk_4c;
    if ((n & 0x10) != 0) {
        p = &a->mUnk_150_m;
        MTX_Identity43_(&d);
        e = d;
        func_01ffcd84(&f, &a->mRotationQuaternion);
        q = &a->mUnk_12c;
        m.x = (s64) q->x * -0x5000 >> 12;
        m.y = (s64) q->y * -0x5000 >> 12;
        m.z = (s64) q->z * -0x5000 >> 12;
        d.mUnk_00[3] = m;
        m.x = -m.x;
        m.y = -m.y;
        m.z = -m.z;
        e.mUnk_00[3] = m;
        MTX_Concat43(&a->mUnk_120_m, &d, p);
        MTX_Concat43(p, &f, p);
        MTX_Concat43(p, &e, p);
        if ((a->mUnk_4c & 0x20) != 0) {
            i = (a->mYRotationAngle >> 4) * 2;
            MTX_RotY43_(&g, gPairsByAngle[i], gPairsByAngle[i + 1]);
            MTX_Concat43(p, &g, p);
        }
        p->mUnk_00[3].x = p->mUnk_00[3].x + a->mPosSource->x;
        p->mUnk_00[3].y = p->mUnk_00[3].y + a->mPosSource->y;
        p->mUnk_00[3].z = p->mUnk_00[3].z + a->mPosSource->z;
    } else if ((n & 0x20) != 0) {
        i = (a->mYRotationAngle >> 4) * 2;
        MTX_RotY43_(&h, gPairsByAngle[i], gPairsByAngle[i + 1]);
        MTX_Concat43(&h, &a->mUnk_120_m, &a->mUnk_150_m);
        q = a->mPosSource;
        a->mUnk_174.x = q->x;
        a->mUnk_174.y = q->y;
        a->mUnk_174.z = q->z;
    } else {
        a->mUnk_150_m = a->mUnk_120_m;
        q = a->mPosSource;
        a->mUnk_174.x = q->x;
        a->mUnk_174.y = q->y;
        a->mUnk_174.z = q->z;
    }
    a->mUnk_98 = a->mUnk_174;
    a->mUnk_174.x = a->mUnk_174.x >> 4;
    a->mUnk_174.y = a->mUnk_174.y >> 4;
    a->mUnk_174.z = a->mUnk_174.z >> 4;
    if ((a->mUnk_4c & 0x2000000) == 0) {
        a->mDrawMatrix = &a->mUnk_150_m;
    } else {
        AdvanceKartWobble(a);
        a->mDrawMatrix = &a->mWobbleMatrix;
    }
    b = a->mKartModelsEntry;
    if (b->mModels[2] != NULL) {
        r = (Vec4 *) &b->mUnk_024;
        j = (s64) r->w * r->x >> 12;
        l = (s64) j * 0xce4 >> 12;
        k = a->mVelocityLengthRatio;
        if (a->mUnk_4d4 > k) {
            a->mTireSpinAngle = a->mTireSpinAngle + (u16) ((s64) a->mUnk_4d4 * 0x7d0 >> 12);
        } else {
            k = (s64) k * 0xfa0 >> 12;
            if (func_020738f8(GetKartForwardSpeedRatio()) < 0x29) {
                k = 0;
                if ((u16) (data_0217562a[o = a->mEntryIndex].mBits & 3) != 0 && IsRaceStarted() == 1) {
                    k = k + 0x190;
                }
            } else if ((a->mUnk_44 & 0x100) != 0) {
                k *= -1;
            }
            if (k > 0xfa0) {
                k = 0xfa0;
            }
            a->mTireSpinAngle = a->mTireSpinAngle + (u16) k;
        }
        a->mUnk_4cc = l;
    }
    c = a->mKartModelsEntry->mCharacterAnimation;
    if (c != NULL && c->mUnk_18 != 0) {
        func_0207b734(a);
        if (IsKartEnded(a->mIndex) != 0) {
            func_0207b354(a);
        }
        c = a->mKartModelsEntry->mCharacterAnimation;
        *c->mUnk_1c[c->mUnk_1a] = c->mUnk_0c;
    }
    if ((a->mUnk_4c & 0x400000) != 0) {
        a->mUnk_504 = a->mUnk_504 + 1;
        a->mUnk_506 = a->mUnk_506 + 1;
        if (a->mUnk_506 > 8) {
            a->mUnk_506 = 0;
        }
        if (a->mUnk_506 >= 4) {
            a->mUnk_4c = a->mUnk_4c | 0x1000000;
        } else {
            a->mUnk_4c = a->mUnk_4c & ~0x1000000;
        }
        if (a->mUnk_504 > 0x5a) {
            a->mUnk_4c = a->mUnk_4c & ~0x1400000;
        }
    }
    func_01ff9b70(a);
}

void func_020641d4(Kart *a) {
    AdvanceKartCollision(a);
    func_020641f0(a);
}
