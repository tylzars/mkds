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

void func_020641f0(Kart *kart) {
    KartModelsEntry *modelsEntry;
    KartModelAnimationView *characterAnimation;
    Vec3 m;
    MtxFx43 d;
    MtxFx43 e;
    MtxFx43 rotationMatrix;
    MtxFx43 g;
    MtxFx43 h;
    s32 pairIndex;
    s32 j;
    s32 k;
    u16 l;
    u32 n;
    MtxFx43 *drawMatrix;
    Vec3 *q;
    Vec4 *r;
    enum { K0 } o;

    Matrix4x3FromQuaternion(&kart->mUnk_120, kart->mUnk_50c);
    n = kart->mUnk_4c;
    if ((n & 0x10) != 0) {
        drawMatrix = &kart->mUnk_150_m;
        MTX_Identity43_(&d);
        e = d;
        Matrix4x3FromQuaternion(&rotationMatrix, &kart->mRotationQuaternion);
        q = &kart->mUnk_12c;
        m.x = (s64) q->x * -0x5000 >> 12;
        m.y = (s64) q->y * -0x5000 >> 12;
        m.z = (s64) q->z * -0x5000 >> 12;
        d.mUnk_00[3] = m;
        m.x = -m.x;
        m.y = -m.y;
        m.z = -m.z;
        e.mUnk_00[3] = m;
        MTX_Concat43(&kart->mUnk_120_m, &d, drawMatrix);
        MTX_Concat43(drawMatrix, &rotationMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &e, drawMatrix);
        if ((kart->mUnk_4c & 0x20) != 0) {
            pairIndex = (kart->mYRotationAngle >> 4) * 2;
            MTX_RotY43_(&g, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
            MTX_Concat43(drawMatrix, &g, drawMatrix);
        }
        drawMatrix->mUnk_00[3].x = drawMatrix->mUnk_00[3].x + kart->mPosSource->x;
        drawMatrix->mUnk_00[3].y = drawMatrix->mUnk_00[3].y + kart->mPosSource->y;
        drawMatrix->mUnk_00[3].z = drawMatrix->mUnk_00[3].z + kart->mPosSource->z;
    } else if ((n & 0x20) != 0) {
        pairIndex = (kart->mYRotationAngle >> 4) * 2;
        MTX_RotY43_(&h, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
        MTX_Concat43(&h, &kart->mUnk_120_m, &kart->mUnk_150_m);
        q = kart->mPosSource;
        kart->mUnk_174.x = q->x;
        kart->mUnk_174.y = q->y;
        kart->mUnk_174.z = q->z;
    } else {
        kart->mUnk_150_m = kart->mUnk_120_m;
        q = kart->mPosSource;
        kart->mUnk_174.x = q->x;
        kart->mUnk_174.y = q->y;
        kart->mUnk_174.z = q->z;
    }
    kart->mDrawMatrixPos = kart->mUnk_174;
    kart->mUnk_174.x = kart->mUnk_174.x >> 4;
    kart->mUnk_174.y = kart->mUnk_174.y >> 4;
    kart->mUnk_174.z = kart->mUnk_174.z >> 4;
    if ((kart->mUnk_4c & 0x2000000) == 0) {
        kart->mDrawMatrix = &kart->mUnk_150_m;
    } else {
        AdvanceKartWobble(kart);
        kart->mDrawMatrix = &kart->mWobbleMatrix;
    }
    modelsEntry = kart->mKartModelsEntry;
    if (modelsEntry->mModels[2] != NULL) {
        r = (Vec4 *) &modelsEntry->mTurnFrameOffset;
        j = (s64) r->w * r->x >> 12;
        l = (s64) j * 0xce4 >> 12;
        k = kart->mVelocityLengthRatio;
        if (kart->mUnk_4d4 > k) {
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) ((s64) kart->mUnk_4d4 * 0x7d0 >> 12);
        } else {
            k = (s64) k * 0xfa0 >> 12;
            if (GetAbsoluteValue(GetKartForwardSpeedRatio()) < 0x29) {
                k = 0;
                if ((u16) (data_0217562a[o = kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0 &&
                    IsRaceStarted() == 1) {
                    k = k + 0x190;
                }
            } else if ((kart->mUnk_44 & 0x100) != 0) {
                k *= -1;
            }
            if (k > 0xfa0) {
                k = 0xfa0;
            }
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) k;
        }
        kart->mUnk_4cc = l;
    }
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation != NULL && characterAnimation->mUnk_18 != 0) {
        AdvanceKartCharacterAnimation(kart);
        if (IsKartEnded(kart->mIndex) != 0) {
            func_0207b354(kart);
        }
        characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
        *characterAnimation->mUnk_1c[characterAnimation->mUnk_1a] = characterAnimation->mUnk_0c;
    }
    if ((kart->mUnk_4c & 0x400000) != 0) {
        kart->mUnk_504 = kart->mUnk_504 + 1;
        kart->mUnk_506 = kart->mUnk_506 + 1;
        if (kart->mUnk_506 > 8) {
            kart->mUnk_506 = 0;
        }
        if (kart->mUnk_506 >= 4) {
            kart->mUnk_4c = kart->mUnk_4c | 0x1000000;
        } else {
            kart->mUnk_4c = kart->mUnk_4c & ~0x1000000;
        }
        if (kart->mUnk_504 > 0x5a) {
            kart->mUnk_4c = kart->mUnk_4c & ~0x1400000;
        }
    }
    AdvanceKartEffects(kart);
}

void func_020641d4(Kart *kart) {
    AdvanceKartCollision(kart);
    func_020641f0(kart);
}
