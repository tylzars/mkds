#include "01/code_021843b0.h"

#include "01/code_02184cc8.h"
#include "01/code_02188950.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188158.h"
#include "01/code_02184000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
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
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020d275c.h"

void func_ov001_02184874(Unk02188950 *d, Kart *e) {
    s32 scale;

    if ((GetKart(e->mIndex)->mUnk_48 & 0x20) && e->mBoostTimer > 0) {
        if (func_ov001_021871f8(d, 8)) {
            if (d->mPrm->mUnk_1dc > 0 || d->mPrm->mUnk_1e0 > 0) {
                Vec3 a = {0, 0, 0};
                a.x = e->mVelocity.x;
                a.z = e->mVelocity.z;
                if ((s64) a.z * a.z + ((s64) a.x * a.x + (s64) a.y * a.y) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&a, &a);
                }
                scale = d->mPrm->mUnk_1e0;
                a.x = ((s64) a.x * scale) >> 12;
                a.y = ((s64) a.y * scale) >> 12;
                a.z = ((s64) a.z * scale) >> 12;
                a.y = d->mPrm->mUnk_1dc;
                func_ov001_02187218(d, 7, NULL);
                func_ov001_02188d64(d, d->mPrm->mUnk_1d4, d->mPrm->mUnk_1d8);
                func_ov001_02188a8c(d, d->mPrm->mUnk_1e4, 0x270f000);
                SetVelocity(d, &a);
                func_ov001_02188dcc(d, func_ov001_02184d70);
                func_ov001_02188cec(d, 0);
            }
            {
                Vec3 b;

                VEC_Subtract(&d->mUnk_000.mPos, &e->mCollisionCenter, &b);
                if ((s64) b.z * b.z + ((s64) b.x * b.x + (s64) b.y * b.y) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&b, &b);
                }
                VEC_MultAdd(e->mRadius, &b, &e->mCollisionCenter, &b);
                if (d->mUnk_000.mKind == 0x1f5) {
                    d->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                    StopSound(&d->mUnk_000.mSound->mSoundSource, 0x214);
                    StartMapObjectSound(&d->mUnk_000, 0x211);
                    StartEffect(0x3e9, &b);
                    StartEffect(0x3e8, &b);
                    StartEffect(0x3ea, &b);
                    func_ov001_02187518(d, 0x99a, 0, 0x75c, 0x3f3, 0);
                    func_ov001_02187518(d, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (d->mUnk_000.mKind == 0x1f6) {
                    d->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                    StopSound(&d->mUnk_000.mSound->mSoundSource, 0x245);
                    StartMapObjectSound(&d->mUnk_000, 0x23f);
                    StartEffect(0x3fa, &b);
                    StartEffect(0x3fb, &b);
                    StartEffect(0x3fc, &b);
                    func_ov001_02187518(d, -0x11ec, 0, 0x1800, 0x445, 0);
                    func_ov001_02187518(d, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (func_ov001_021871f8(d, 7)) {
        if (d->mPrm->mUnk_1c4 > 0 || d->mPrm->mUnk_1c8 > 0) {
            Vec3 c = {0, 0, 0};
            c.x = e->mVelocity.x;
            c.z = e->mVelocity.z;
            if ((s64) c.z * c.z + ((s64) c.x * c.x + (s64) c.y * c.y) >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&c, &c);
            }
            scale = d->mPrm->mUnk_1c8;
            c.x = ((s64) c.x * scale) >> 12;
            c.y = ((s64) c.y * scale) >> 12;
            c.z = ((s64) c.z * scale) >> 12;
            c.y = d->mPrm->mUnk_1c4;
            func_ov001_02187218(d, 7, NULL);
            func_ov001_02188d64(d, d->mPrm->mUnk_1bc, d->mPrm->mUnk_1c0);
            func_ov001_02188a8c(d, d->mPrm->mUnk_1cc, 0x270f000);
            SetVelocity(d, &c);
            func_ov001_02188dcc(d, NULL);
            func_ov001_02188cec(d, 0);
        }
    }
    func_ov001_02188200(d, func_ov001_02184874);
    d->mUnk_2d8 = 13;
}

void func_ov001_021843b0(Unk02188950 *a, Kart *b) {
    Vec3 vec1;
    Vec3 vec2;
    Vec3 vec3;

    if ((GetKart(b->mIndex)->mUnk_48 & 0x20) && b->mBoostTimer > 0) {
        if (func_ov001_021871f8(a, 8)) {
            if (a->mPrm->mUnk_1a8 > 0 || a->mPrm->mUnk_1ac > 0) {
                vec1.x = ((s64) -a->mPrm->mUnk_1ac * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2]) >> 12;
                vec1.y = a->mPrm->mUnk_1a8;
                vec1.z = ((s64) -a->mPrm->mUnk_1ac * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1]) >> 12;
                func_ov001_02187218(a, 7, NULL);
                func_ov001_02188d64(a, a->mPrm->mUnk_1a0, a->mPrm->mUnk_1a4);
                func_ov001_02188a8c(a, a->mPrm->mUnk_1b0, 0x270f000);
                SetVelocity(a, &vec1);
                func_ov001_02188dcc(a, func_ov001_02184d70);
                func_ov001_02188cec(a, 0);
            }
            VEC_Subtract(&a->mUnk_000.mPos, &b->mCollisionCenter, &vec2);
            if ((s64) vec2.x * vec2.x + (s64) vec2.y * vec2.y + (s64) vec2.z * vec2.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&vec2, &vec2);
            }
            VEC_MultAdd(b->mRadius, &vec2, &b->mCollisionCenter, &vec2);
            if (a->mUnk_000.mKind == 0x1f5) {
                a->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                StopSound(&a->mUnk_000.mSound->mSoundSource, 0x214);
                StartMapObjectSound(&a->mUnk_000, 0x211);
                StartEffect(0x3e9, &vec2);
                StartEffect(0x3e8, &vec2);
                StartEffect(0x3ea, &vec2);
                func_ov001_02187518(a, 0x99a, 0, 0x75c, 0x3f3, 0);
                func_ov001_02187518(a, -0x99a, 0, 0x75c, 0x3f3, 0);
            } else if (a->mUnk_000.mKind == 0x1f6) {
                a->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                StopSound(&a->mUnk_000.mSound->mSoundSource, 0x245);
                StartMapObjectSound(&a->mUnk_000, 0x23f);
                StartEffect(0x3fa, &vec2);
                StartEffect(0x3fb, &vec2);
                StartEffect(0x3fc, &vec2);
                func_ov001_02187518(a, -0x11ec, 0, 0x1800, 0x445, 0);
                func_ov001_02187518(a, 0x11ec, 0, 0x1800, 0x445, 0);
            }
            a->mUnk_000.mUnk_10.x = ((s64) a->mPrm->mUnk_1b8 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2]) >> 12;
            a->mUnk_000.mUnk_10.y = 0;
            a->mUnk_000.mUnk_10.z = ((s64) a->mPrm->mUnk_1b8 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1]) >> 12;
            a->mUnk_000.mPos.x -= a->mUnk_000.mUnk_10.x;
            a->mUnk_000.mPos.y -= a->mUnk_000.mUnk_10.y;
            a->mUnk_000.mPos.z -= a->mUnk_000.mUnk_10.z;
        }
    } else if (func_ov001_021871f8(a, 7)) {
        if (a->mPrm->mUnk_18c > 0 || a->mPrm->mUnk_190 > 0) {
            vec3.x = ((s64) -a->mPrm->mUnk_190 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2]) >> 12;
            vec3.y = a->mPrm->mUnk_18c;
            vec3.z = ((s64) -a->mPrm->mUnk_190 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1]) >> 12;
            func_ov001_02187218(a, 7, NULL);
            func_ov001_02188d64(a, a->mPrm->mUnk_184, a->mPrm->mUnk_188);
            func_ov001_02188a8c(a, a->mPrm->mUnk_194, 0x270f000);
            SetVelocity(a, &vec3);
            func_ov001_02188dcc(a, func_ov001_02184cc8);
            func_ov001_02188cec(a, 0);
        }
        a->mUnk_000.mUnk_10.x = ((s64) a->mPrm->mUnk_19c * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2]) >> 12;
        a->mUnk_000.mUnk_10.y = 0;
        a->mUnk_000.mUnk_10.z = ((s64) a->mPrm->mUnk_19c * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1]) >> 12;
        a->mUnk_000.mPos.x -= a->mUnk_000.mUnk_10.x;
        a->mUnk_000.mPos.y -= a->mUnk_000.mUnk_10.y;
        a->mUnk_000.mPos.z -= a->mUnk_000.mUnk_10.z;
        a->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
        StartMapObjectSound(&a->mUnk_000, 0x213);
    }
    func_ov001_02188200(a, func_ov001_02184874);
    a->mUnk_2d8 = 0xd;
    func_02073fb0(a->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
}
