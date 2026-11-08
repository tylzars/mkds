#include "Main/Unknown/code_0209756c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020109c4.h"
#include "code_020184e4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void InitFlipper(Flipper *flipper) {
    flipper->mUnk_00.mFlags = flipper->mUnk_00.mFlags | data_usa_0215658c;
    RefreshMapObjectMatrixFromHitNormal(flipper);
}

u32 CollideKartWithFlipper(Flipper *flipper, Kart *kart, void *b, u8 *c) {
    u32 v;
    BOOL t;
    s32 f;
    Vec3 offset;
    s32 s;
    Vec3 *e;

    v = *c;
    t = (flipper->mState == 2 || flipper->mState == 5) && flipper->mUnk_a0 > 0;
    if (t) {
        s = -0x19a;
    } else if ((flipper->mState == 3 || flipper->mState == 6) && flipper->mUnk_a0 < 0) {
        s = 0x19a;
    } else {
        s = 0;
    }
    if (s != 0) {
        if (flipper->mUnk_ed4[kart->mIndex] != 0) {
            flipper->mUnk_00.mUnk_10.x = 0;
            flipper->mUnk_00.mUnk_10.y = 0;
            flipper->mUnk_00.mUnk_10.z = 0;
        } else {
            VEC_Subtract(&kart->mPos, &flipper->mUnk_00.mPos, &offset);
            f = VEC_Mag(&offset);
            e = &flipper->mUnk_a8[flipper->mUnk_ec0].mUnk_00[2];
            f = ((s64) f * s) >> 12;
            flipper->mUnk_00.mUnk_10.x = ((s64) e->x * f) >> 12;
            flipper->mUnk_00.mUnk_10.y = ((s64) e->y * f) >> 12;
            flipper->mUnk_00.mUnk_10.z = ((s64) e->z * f) >> 12;
            flipper->mUnk_00.mDistanceSquaredAndFlags = flipper->mUnk_00.mDistanceSquaredAndFlags | data_usa_02156588;
            func_020d26ec(kart, 0x1d1);
        }
        if (flipper->mUnk_ec8 != 0) {
            return 0xe;
        }
        return 0xc;
    }
    flipper->mUnk_00.mUnk_10.x = 0;
    flipper->mUnk_00.mUnk_10.y = 0;
    flipper->mUnk_00.mUnk_10.z = 0;
    return v;
}

u32 func_02097ed0(Flipper *flipper, Vec3 *sphereCenter, s32 b, Vec3 *pushOut) {
    s32 r;

    flipper->mUnk_a0 = 0;
    if (ComputeSphereHitOnRotatedBox(
            sphereCenter, &flipper->mUnk_00.mPos, &flipper->mUnk_a8[flipper->mUnk_ec0].mUnk_00[0],
            &data_usa_0215650c[flipper->mMirror], &data_usa_0215653c[flipper->mMirror], b, NULL) != 0) {
        r = ComputeSphereHitOnRotatedBox(
            sphereCenter, &flipper->mUnk_00.mPos, &flipper->mUnk_a8[flipper->mUnk_ec0].mUnk_00[0],
            &data_usa_02156554[flipper->mMirror], &data_usa_021564dc[flipper->mMirror], b, pushOut);
        if (r == 4 || flipper->mState == 2) {
            flipper->mUnk_a0 = 1;
        } else if (flipper->mState == 3) {
            flipper->mUnk_a0 = -1;
        }
    } else {
        if (ComputeSphereHitOnRotatedBox(
                sphereCenter, &flipper->mUnk_00.mPos, &flipper->mUnk_a8[flipper->mUnk_ec0].mUnk_00[0],
                &data_usa_021564c4[flipper->mMirror], &data_usa_02156524[flipper->mMirror], b, NULL) != 0) {
            r = ComputeSphereHitOnRotatedBox(
                sphereCenter, &flipper->mUnk_00.mPos, &flipper->mUnk_648[flipper->mUnk_ec0].mUnk_00[0],
                &data_usa_0215656c[flipper->mMirror], &data_usa_021564f4[flipper->mMirror], b, pushOut);
            if (r == 4 || flipper->mState == 3) {
                flipper->mUnk_a0 = -1;
            } else if (flipper->mState == 2) {
                flipper->mUnk_a0 = 1;
            }
        } else {
            r = ComputeSphereHitOnRotatedCylinder(sphereCenter, &flipper->mUnk_00.mPos,
                                                  &flipper->mUnk_a8[flipper->mUnk_ec0].mUnk_00[0], 0x32000, 0x3c000, 0,
                                                  b, pushOut);
        }
    }
    return r != 0;
}

void CreateFlipper(void *a) {
    gFlipper = CreateMapObjectModelAnimated(a, gFlipperNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gFlipper, gFlipperNsbtpName);
    CreateMapObjectModelNsbtaAnimation(gFlipper, gFlipperNsbtaName);
}

void DrawFlipper(void *a, Flipper *flipper) {
    s32 v;
    MtxFx43 *matrix;
    ModelAnimation *s;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    matrix = &flipper->mUnk_a8[flipper->mUnk_ec0];
    matrix->mUnk_00[3].x = flipper->mUnk_00.mPos.x >> 4;
    matrix->mUnk_00[3].y = flipper->mUnk_00.mPos.y >> 4;
    matrix->mUnk_00[3].z = flipper->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &flipper->mUnk_00.mScale, 3);
    SetMapObjectModelMirror(gFlipper, flipper->mMirror, 0);
    s = gFlipper->mAnimations[1];
    s->mFrameIndex = flipper->mNsbtpFrameIndex << 12;
    s->mAnmObjs[s->mCurrentIndex]->mFrame = s->mFrameIndex;
    s = gFlipper->mAnimations[3];
    s->mFrameIndex = flipper->mNsbtaFrameIndex << 12;
    s->mAnmObjs[s->mCurrentIndex]->mFrame = s->mFrameIndex;
    DrawMapObjectModel(a, gFlipper, flipper);
}

void InitFlipperObjects(MapObjectList *mapObjectList) {
    s32 i;
    s32 j;
    s32 v1;
    s32 d;
    s32 k;
    u32 e;
    Flipper *flipper;
    MtxFx43 *q;
    s32 m2[9];
    s32 m1[9];

    if (mapObjectList == NULL) {
        return;
    }
    v1 = data_usa_0215653c[0].x;
    for (i = 0; i < mapObjectList->mMapObjectCount && (flipper = mapObjectList->mMapObjects[i]) != NULL; i++) {
        switch (flipper->mUnk_00.mCourseMapRow->mUnk_28) {
            case 0:
                flipper->mMirror = 0;
                flipper->mUnk_00.mFlags &= ~0x400;
                flipper->mUnk_00.mAngle = 0x2000;
                flipper->mState1Timer = 0x1e;
                MTX_RotY33_(m2, data_usa_02160fb4[0x74], data_usa_02160fb4[0x75]);
                break;
            case 1:
                flipper->mMirror = 1;
                flipper->mUnk_00.mFlags |= data_usa_02156584;
                flipper->mUnk_00.mAngle = 0x2000;
                flipper->mState1Timer = 0x1e;
                MTX_RotY33_(m2, data_usa_0215d8b4[10], data_usa_0215d8b4[11]);
                break;
        }
        flipper->mUnk_ec8 = 0;
        if (flipper->mMirror == 0) {
            e = flipper->mUnk_00.mAngle;
        } else {
            e = -flipper->mUnk_00.mAngle;
        }
        for (j = 0; j < 30; j++) {
            if (flipper->mMirror == 0) {
                d = 0x16c;
            } else {
                d = -0x16c;
            }
            e = e - d;
            k = (u16) e >> 4;
            MTX_RotY33_(m1, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
            q = &flipper->mUnk_a8[j];
            MTX_Concat33(m1, &flipper->mUnk_00.mMatrix.mUnk_00[0].x, &q->mUnk_00[0].x);
            MTX_Concat33(m2, &q->mUnk_00[0].x, &flipper->mUnk_648[j].mUnk_00[0].x);
            flipper->mUnk_be8[j].x = flipper->mUnk_00.mPos.x >> 4;
            flipper->mUnk_be8[j].y = flipper->mUnk_00.mPos.y >> 4;
            flipper->mUnk_be8[j].z = flipper->mUnk_00.mPos.z >> 4;
            if (flipper->mMirror == 0) {
                k = (u16) (-e + FX_Atan2Idx(-2, -10)) >> 4;
                flipper->mUnk_d50[j].x =
                    (flipper->mUnk_00.mPos.x + (s32) (((s64) v1 * gPairsByAngle[k * 2 + 1]) >> 12)) >> 4;
                flipper->mUnk_d50[j].y = flipper->mUnk_00.mPos.y >> 4;
                flipper->mUnk_d50[j].z =
                    (flipper->mUnk_00.mPos.z + (s32) (((s64) v1 * gPairsByAngle[k * 2]) >> 12)) >> 4;
            } else {
                k = (u16) (-e - FX_Atan2Idx(-2, -10)) >> 4;
                flipper->mUnk_d50[j].x =
                    (flipper->mUnk_00.mPos.x - (s32) (((s64) v1 * gPairsByAngle[k * 2 + 1]) >> 12)) >> 4;
                flipper->mUnk_d50[j].y = flipper->mUnk_00.mPos.y >> 4;
                flipper->mUnk_d50[j].z =
                    (flipper->mUnk_00.mPos.z - (s32) (((s64) v1 * gPairsByAngle[k * 2]) >> 12)) >> 4;
            }
        }
    }
}

void UpdateFlipper(void *a, Flipper *flipper) {
    s32 i;
    s32 kartCount;
    RandomState64 *mapObjectRandom;
    u32 r;
    s32 w;

    flipper->mUnk_ebc = flipper->mUnk_ebc - (flipper->mUnk_ebc > 0);
    switch (flipper->mState) {
        case 0:
            flipper->mUnk_ed0 = StartEffect(0x5f, &flipper->mUnk_00.mPos);
            flipper->mState = 1;
            break;
        case 1:
            if (flipper->mUnk_ebc != 0) {
                flipper->mState = 4;
            } else {
                flipper->mState1Timer = flipper->mState1Timer - 1;
                if (flipper->mState1Timer <= 0) {
                    flipper->mUnk_ec0 = 0;
                    flipper->mState = 2;
                }
            }
            flipper->mUnk_ec8 = 0;
            break;
        case 2:
            flipper->mUnk_00.mAngle -= 0x16c;
            flipper->mUnk_ec0 = flipper->mUnk_ec0 + 1;
            if (flipper->mUnk_ec0 >= 0x1d) {
                flipper->mUnk_ec0 = 0x1d;
                flipper->mState = 3;
            }
            flipper->mUnk_ec8 = 1;
            break;
        case 3:
            flipper->mUnk_00.mAngle += 0x16c;
            if (flipper->mUnk_ec0 >= 0xf) {
                flipper->mUnk_ec8 = 1;
            } else {
                flipper->mUnk_ec8 = 0;
            }
            flipper->mUnk_ec0 = flipper->mUnk_ec0 - 1;
            if (flipper->mUnk_ec0 <= 0) {
                flipper->mUnk_ec0 = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                r = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mState1Timer = (u16) ((u16) r * 0x14);
                flipper->mState = 1;
            }
            break;
        case 4:
            if (flipper->mUnk_ebc <= 0) {
                flipper->mUnk_ec0 = 0;
                flipper->mState = 5;
            }
            flipper->mUnk_ec8 = 0;
            break;
        case 5:
            flipper->mUnk_00.mAngle -= 0x2d8;
            flipper->mUnk_ec0 = flipper->mUnk_ec0 + 2;
            if (flipper->mUnk_ec0 >= 0x1c) {
                flipper->mUnk_ec0 = 0x1c;
                flipper->mState = 6;
            }
            flipper->mUnk_ec8 = 1;
            break;
        case 6:
            flipper->mUnk_00.mAngle += 0x2d8;
            if (flipper->mUnk_ec0 >= 0xf) {
                flipper->mUnk_ec8 = 1;
            } else {
                flipper->mUnk_ec8 = 0;
            }
            flipper->mUnk_ec0 = flipper->mUnk_ec0 - 2;
            if (flipper->mUnk_ec0 <= 0) {
                flipper->mUnk_ec0 = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                r = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 12) >> 32;
                flipper->mState1Timer = (u16) ((u16) r * 0x14);
                flipper->mState = 1;
            }
            break;
    }
    if (flipper->mUnk_ec8 != 0 && (flipper->mUnk_00.mFlags & 0x12) == 0) {
        w = flipper->mNsbtpFrameIndex + 1;
        if (w >= GetMapObjectModelNsbtpFrameCount(gFlipper)) {
            w = 1;
        }
        flipper->mNsbtpFrameIndex = w;
        w = flipper->mNsbtaFrameIndex + 1;
        if (w >= GetMapObjectModelNsbtaFrameCount(gFlipper)) {
            w = 1;
        }
        flipper->mNsbtaFrameIndex = w;
        flipper->mUnk_ed0->mUnk_24.mUnk_00_1 = 0;
        SPLUtil_SetCylinderEmitterDir(flipper->mUnk_ed0, &flipper->mUnk_be8[flipper->mUnk_ec0],
                                      &flipper->mUnk_d50[flipper->mUnk_ec0]);
    } else {
        flipper->mNsbtpFrameIndex = 0;
        flipper->mNsbtaFrameIndex = 0;
        flipper->mUnk_ed0->mUnk_24.mUnk_00_1 = 1;
    }
    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        if (flipper->mUnk_ed4[i] > 0) {
            flipper->mUnk_ed4[i] = flipper->mUnk_ed4[i] - 1;
        }
    }
}

void CreateFlipperKindData(void) {
    func_0209bf70(CollideKartWithFlipper, NULL, func_02097ed0, 0, 1, 0x1d0);
}

void *CreateFlipperDrawList(void) {
    return CreateMapObjectDrawList1(CreateFlipper, DrawFlipper, NULL);
}

void *CreateFlipperUpdateList(void) {
    return CreateMapObjectUpdateList(InitFlipperObjects, UpdateFlipper, NULL);
}
