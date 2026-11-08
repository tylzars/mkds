#include "01/code_02185ef4.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "01/code_0218d520.h"
#include "01/unk_021a9000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_0209b000.h"
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
#include "Main/Unknown/code_020d3000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "01/code_02188950.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "01/code_0219b240.h"
#include "ITCM/code_01ffd000.h"
#include "code_02146d78.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_0219b250.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02148000.h"
#include "01/callees_0219b000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_021a2034.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void ThrowItemBombFromPosition(void *bomb, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (bomb != NULL && position != NULL) {
        upNormal = data_ov001_021a7a64;
        normalPointer = &upNormal;
        func_020fd684(bomb, normalPointer, position);
        if (velocity != NULL) {
            func_020fd540(&bomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            func_020fd540(&bomb, &zeroVelocity, timer);
        }
    }
}

void ThrowItemKinokoFromPosition(void *kinoko, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (kinoko != NULL && position != NULL) {
        upNormal = data_ov001_021a7a70;
        normalPointer = &upNormal;
        func_020f4e78(kinoko, normalPointer, position);
        if (velocity != NULL) {
            StartBouncingItemKinoko(&kinoko, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            StartBouncingItemKinoko(&kinoko, &zeroVelocity, timer);
        }
    }
}

void ReleaseEffects(Unk02188950 *mapObject) {
    s32 effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            func_0208b6b0(&mapObject->mEffects[effectIndex].mEffect);
        }
    }
    mapObject->mUnk_0b8 = 0;
}

// Writes a point for one entry of the object's table; the entry's type (1-5) picks how, others write nothing.
void ComputeEffectPosition(Unk02188950 *mapObject, int effectIndex, Vec3 *position) {
    Camera *camera;
    s32 scaledX;
    s32 scaledY;
    s32 scaledZ;
    s32 offsetComponent;

    switch (mapObject->mEffects[effectIndex].mKind) {
        case 1:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12) +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12);
            position->y = mapObject->mUnk_000.mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12) -
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12);
            break;
        case 3:
            // As case 1 with mUnk_024 of the object from GetCurrentCamera added, then halved.
            camera = GetCurrentCamera();
            position->x = mapObject->mUnk_000.mPos.x + camera->mPos.x +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12) +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12);
            position->y = mapObject->mUnk_000.mPos.y + camera->mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z + camera->mPos.z +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12) -
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12);
            position->x >>= 1;
            position->y >>= 1;
            position->z >>= 1;
            break;
        case 2:
            // The entry's mUnk_08 is first multiplied per component by param_1->mUnk_01c, mUnk_020 and mUnk_024.
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.y;
            scaledY = (((s64) offsetComponent * mapObject->mUnk_000.mScale.y) >> 12);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.x;
            scaledX = (((s64) offsetComponent * mapObject->mUnk_000.mScale.x) >> 12);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.z;
            scaledZ = (((s64) offsetComponent * mapObject->mUnk_000.mScale.z) >> 12);
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (((s64) scaledZ * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >> 12) +
                          (s32) (((s64) scaledX * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >> 12);
            position->y = mapObject->mUnk_000.mPos.y + scaledY;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (((s64) scaledZ * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >> 12) -
                          (s32) (((s64) scaledX * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >> 12);
            break;
        case 4:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12) +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12);
            position->y = mapObject->mUnk_000.mCourseMapRow->mUnk_00.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12) -
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12);
            break;
        case 5:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12) +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12);
            position->y = mapObject->mEffects[effectIndex].mOffset.y - GetHeightAboveWaterOrEfct(0);
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.z *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]) >>
                                 12) -
                          (s32) (((s64) mapObject->mEffects[effectIndex].mOffset.x *
                                  gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2]) >>
                                 12);
            break;
    }
}

void StartEffectInSlot(Unk02188950 *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ, u32 effectId,
                       s32 timer) {
    Vec3 position;

    mapObject->mEffects[effectIndex].mTimer = timer;
    if ((mapObject->mUnk_000.mFlags & 0x400) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
    mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
    mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
    ComputeEffectPosition(mapObject, effectIndex, &position);
    if (effectId != 0) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            func_0208b6b0(&mapObject->mEffects[effectIndex].mEffect);
        }
        mapObject->mEffects[effectIndex].mEffect = StartEffect(effectId, &position);
    }
}

void StartEffectAtOffset(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 1;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtScaledOffset(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 2;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtRowHeight(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 4;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtWaterHeight(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 5;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartModelEffectAtWaterHeight(Unk02188950 *mapObject, u32 modelEffectKind, int timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mOffset.x = mapObject->mUnk_000.mPos.x;
            mapObject->mEffects[effectIndex].mOffset.y = -GetHeightAboveWaterOrEfct(0);
            mapObject->mEffects[effectIndex].mOffset.z = mapObject->mUnk_000.mPos.z;
            if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                func_0208b6b0(&mapObject->mEffects[effectIndex].mEffect);
            }
            StartModelEffect(modelEffectKind, &mapObject->mEffects[effectIndex].mOffset, 1);
            mapObject->mEffects[effectIndex].mKind = 0;
            mapObject->mEffects[effectIndex].mTimer = timer;
            return;
        }
    }
}

void func_ov001_0218742c(Unk0201ca6c *a, const Vec3s16 *b) {
    a->mUnk_50 = *b;
}

void func_ov001_021872e0(Unk02188950 *mapObject, int offsetX, int offsetY, int offsetZ, int emitterParamX,
                         int emitterParamY, int emitterParamZ, int effectId, u32 timer) {
    int effectIndex;
    Vec3 position;
    Vec3s16 emitterParams;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 1;
            mapObject->mEffects[effectIndex].mTimer = timer;
            mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
            mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
            mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
            ComputeEffectPosition(mapObject, effectIndex, &position);
            if (effectId != 0) {
                if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                    func_0208b6b0(&mapObject->mEffects[effectIndex].mEffect);
                }
                emitterParams.x = ((s64) emitterParamZ * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2] >> 12) +
                                  ((s64) emitterParamX * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1] >> 12);
                emitterParams.y = emitterParamY;
                emitterParams.z = ((s64) emitterParamZ * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1] >> 12) -
                                  ((s64) emitterParamX * gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2] >> 12);
                func_0208b748(effectId, &position, &emitterParams, func_ov001_0218742c);
            }
        }
    }
}

void func_ov001_02187218(Unk02188950 *mapObject, int b, s32 (*nextFunc)(Unk02188950 *)) {
    mapObject->mUnk_158 = NULL;
    mapObject->mUnk_15c = nextFunc;
    mapObject->mUnk_150 = b;
    mapObject->mStateFrames = 0;
    mapObject->mUnk_0b4 = mapObject->mUnk_0b4 > 0 ? mapObject->mUnk_0b4 - 1 : 0;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    if (mapObject->mUnk_2c4 == FALSE) {
        mapObject->mAnimationFrameCallbackFrameIndex = 0;
        mapObject->mAnimationEndCallback = NULL;
        mapObject->mAnimationFrameCallback = NULL;
        mapObject->mUnk_1e0 = 0;
        mapObject->mUnk_1e4 = NULL;
        mapObject->mUnk_1e8 = 0;
        mapObject->mUnk_1ec = NULL;
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrameCountCallback = NULL;
        mapObject->mPointInRangeCallback = NULL;
        mapObject->mUnk_224 = NULL;
        mapObject->mStoppedCallback = NULL;
        mapObject->mCourseCollisionCallback = NULL;
        ReleaseEffects(mapObject);
    }
}

void DisableMissionRunMapObjectGravity(Unk02188950 *mapObject) {
    mapObject->mGravityEnabled = FALSE;
}

u32 func_ov001_021871f8(Unk02188950 *mapObject, int b) {
    if (mapObject->mUnk_150 < b) {
        return 1;
    }
    return 0;
}

BOOL func_ov001_021871d0(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x800) != 0 && mapObject->mVelocity.y <= 0) {
        return TRUE;
    }
    return FALSE;
}

void InitMissionRunMapObject(void *mapObjectList, Unk02188950 *mapObject, const char *nsbmdName, const char *nsbcaName,
                             const char *prmName) {
    if (mapObjectList != NULL && nsbmdName != NULL) {
        mapObject->mNsbmd = LoadMapObjectModelAnimated(mapObjectList, nsbmdName);
        if (nsbcaName != NULL) {
            LoadMapObjectModelNsbcaAnimation(mapObject->mNsbmd, nsbcaName);
        }
    }
    if (prmName != NULL) {
        mapObject->mPrm = LoadMissionRunFile(prmName);
    }
    mapObject->mAngle =
        (u16) (((s64) mapObject->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    mapObject->mAlphaLimit = 0x1f000;
    if (mapObject->mPrm != NULL) {
        SetMapObjectExtentX(&mapObject->mUnk_000, mapObject->mPrm->mUnk_00c << 2);
        mapObject->mUnk_000.mScale.x = mapObject->mPrm->mScale;
        mapObject->mUnk_000.mScale.y = mapObject->mPrm->mScale;
        mapObject->mUnk_000.mScale.z = mapObject->mPrm->mScale;
    }
    mapObject->mPosWithOffset = mapObject->mUnk_000.mPos;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    mapObject->mEntryGroupIndex = mapObject->mUnk_000.mCourseMapRow->mUnk_26;
}

void LoadMissionRunMapObjectShadow(void *mapObjectList, Unk02188950 *mapObject, const char *shadowNsbmdName) {
    if (mapObjectList != NULL && shadowNsbmdName != NULL) {
        mapObject->mShadowNsbmd = LoadMapObjectModelShadow(mapObjectList, shadowNsbmdName);
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 0x3f);
        gShadowScaleToggle = 0;
    }
}

void ToggleShadowScale(void) {
    if (gShadowScaleToggle == 0) {
        gShadowScaleToggle++;
    } else {
        gShadowScaleToggle = 0;
    }
}

int StepIntTowardTarget(int target, int step, int current) {
    int next;
    if (current < target) {
        next = current + step;
        if (current + step >= target) {
            next = target;
        }
        return next;
    }
    if (current > target) {
        next = current - step;
        if (current - step <= target) {
            next = target;
        }
        return next;
    }
    return current;
}

u16 StepAngleTowardDirection(Vec3 *target, Vec3 *origin, s32 maxStep, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(target->x - origin->x, target->z - origin->z) - angle);
    s32 turn;

    if (maxStep < 0) {
        maxStep = -maxStep;
    }
    if (angleDifference > 0x8000) {
        angleDifference -= 0x10000;
    }
    turn = -maxStep;
    if (angleDifference >= turn) {
        if (angleDifference <= maxStep) {
            maxStep = angleDifference;
        }
        turn = maxStep;
    }
    return angle + turn;
}

u16 StepAngleSidewaysToPoint(Vec3 *targetPoint, Vec3 *origin, s32 signedMaxStep, s32 angleOffset, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(targetPoint->x - origin->x, targetPoint->z - origin->z) - angle);
    s32 maxTurn;
    s32 turn;
    s32 targetDifference;

    if (signedMaxStep < 0) {
        maxTurn = -signedMaxStep;
    } else {
        maxTurn = signedMaxStep;
    }
    if (angleDifference > 0x8000) {
        angleDifference -= 0x10000;
    }
    if (signedMaxStep < 0) {
        angleDifference += angleOffset;
        targetDifference = angleDifference - 0x4000;
    } else {
        angleDifference -= angleOffset;
        targetDifference = angleDifference + 0x4000;
    }
    turn = -maxTurn;
    if (targetDifference >= turn) {
        if (targetDifference <= maxTurn) {
            maxTurn = targetDifference;
        }
        turn = maxTurn;
    }
    return angle + turn;
}

void AdvanceMissionRunMapObject(u32 a, Unk02188950 *mapObject) {
    Vec3 probePosition;
    Vec3 pushOut;
    Vec3 v50;
    Vec3 v5c;
    Vec3 pushDirection;
    Vec3 effectPosition;
    s32 velocityScale;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 currentFrame;
    s32 previousFrame;
    s32 effectIndex;
    s32 pairWordIndex;
    s64 speed;

    if (mapObject->mUnk_158 == NULL && mapObject->mUnk_15c != NULL) {
        mapObject->mUnk_158 = mapObject->mUnk_15c;
        mapObject->mUnk_15c = NULL;
    }
    if (mapObject->mUnk_158 != NULL && mapObject->mUnk_158(mapObject)) {
        mapObject->mUnk_158 = NULL;
        mapObject->mUnk_154 = 0;
        mapObject->mStateFrames = 0;
        mapObject->mUnk_150 = 0;
    }

    switch (mapObject->mAngleState) {
        case 1:
            mapObject->mAngle = mapObject->mMoveAngle;
            break;
        case 2:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case 3:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mUnk_000.mPos, &mapObject->mAnglePoint,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case 4:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle =
                    StepAngleSidewaysToPoint(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mAnglePerCall, mapObject->mUnk_1a0, mapObject->mAngle);
            }
            break;
        case 5:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            }
            break;
        case 6:
        case 7:
        case 8:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAngleState == 6) {
                if (StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mAnglePerCall, mapObject->mAngle) -
                        mapObject->mAngle >=
                    0) {
                    mapObject->mAngleState = 8;
                } else {
                    mapObject->mAngleState = 7;
                }
            }
            if (mapObject->mAngleState == 8) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            } else if (mapObject->mAngleState == 7) {
                mapObject->mAngle -= mapObject->mAnglePerCall;
            }
            break;
    }

    switch (mapObject->mMoveAngleMode) {
        case 1:
            mapObject->mMoveAngle = mapObject->mAngle;
            break;
        case 2:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle = StepAngleTowardDirection(&mapObject->mMoveAnglePoint, &mapObject->mUnk_000.mPos,
                                                                 mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case 3:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle = StepAngleTowardDirection(&mapObject->mUnk_000.mPos, &mapObject->mMoveAnglePoint,
                                                                 mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case 4:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle =
                    StepAngleSidewaysToPoint(&mapObject->mMoveAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mMoveAnglePerCall, mapObject->mUnk_1c4, mapObject->mMoveAngle);
            }
            break;
    }

    if (mapObject->mSpeedPerCall > 0) {
        mapObject->mSpeed = StepIntTowardTarget(mapObject->mSpeedTarget, mapObject->mSpeedPerCall, mapObject->mSpeed);
    }
    if (mapObject->mOffsetPerCall > 0) {
        mapObject->mOffset.x =
            StepIntTowardTarget(mapObject->mOffsetTargetX, mapObject->mOffsetPerCall, mapObject->mOffset.x);
        mapObject->mOffset.y =
            StepIntTowardTarget(mapObject->mOffsetTargetY, mapObject->mOffsetPerCall, mapObject->mOffset.y);
        mapObject->mOffset.z =
            StepIntTowardTarget(mapObject->mOffsetTargetZ, mapObject->mOffsetPerCall, mapObject->mOffset.z);
    }
    if (mapObject->mCollisionExtentPerCall > 0) {
        mapObject->mCollisionExtent.x = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetX, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.x);
        mapObject->mCollisionExtent.y = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetY, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.y);
        mapObject->mCollisionExtent.z = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetZ, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.z);
    }
    if (mapObject->mShadowOffsetPerCall > 0) {
        mapObject->mShadowOffsetX = StepIntTowardTarget(mapObject->mShadowOffsetTargetX,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetX);
        mapObject->mShadowOffsetY = StepIntTowardTarget(mapObject->mShadowOffsetTargetY,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetY);
        mapObject->mShadowOffsetZ = StepIntTowardTarget(mapObject->mShadowOffsetTargetZ,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetZ);
    }
    if (mapObject->mShadowScalePerCall > 0) {
        mapObject->mShadowScaleX = StepIntTowardTarget(mapObject->mShadowScaleTargetX, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleX);
        mapObject->mShadowScaleY = StepIntTowardTarget(mapObject->mShadowScaleTargetY, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleY);
        mapObject->mShadowScaleZ = StepIntTowardTarget(mapObject->mShadowScaleTargetZ, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleZ);
    }

    if (mapObject->mGravityEnabled != FALSE) {
        mapObject->mVelocity.y -= mapObject->mPrm->mGravity;
    }
    if (-mapObject->mPrm->mUnk_018 < *(s32 *) &mapObject->mVelocity &&
        *(s32 *) &mapObject->mVelocity < mapObject->mPrm->mUnk_018 &&
        -mapObject->mPrm->mUnk_018 < mapObject->mVelocity.z && mapObject->mVelocity.z < mapObject->mPrm->mUnk_018) {
        mapObject->mVelocity.x = 0;
        mapObject->mVelocity.z = 0;
    } else if (mapObject->mCollisionBits & 0x1e34ef) {
        velocityScale = mapObject->mPrm->mUnk_010;
        mapObject->mVelocity.x = (((s64) mapObject->mVelocity.x * velocityScale) >> 12);
        mapObject->mVelocity.y = (((s64) mapObject->mVelocity.y * velocityScale) >> 12);
        mapObject->mVelocity.z = (((s64) mapObject->mVelocity.z * velocityScale) >> 12);
    } else {
        velocityScale = mapObject->mPrm->mUnk_014;
        mapObject->mVelocity.x = (((s64) mapObject->mVelocity.x * velocityScale) >> 12);
        mapObject->mVelocity.y = (((s64) mapObject->mVelocity.y * velocityScale) >> 12);
        mapObject->mVelocity.z = (((s64) mapObject->mVelocity.z * velocityScale) >> 12);
    }

    pairWordIndex = ((u16) mapObject->mMoveAngle >> 4) * 2;
    speed = mapObject->mSpeed;
    dy = mapObject->mVelocity.y;
    dz = mapObject->mVelocity.z + (s32) ((speed * gPairsByAngle[pairWordIndex + 1]) >> 12);
    dx = mapObject->mVelocity.x + (s32) ((speed * gPairsByAngle[pairWordIndex]) >> 12);
    mapObject->mUnk_000.mPos.x += dx;
    mapObject->mUnk_000.mPos.y += dy;
    mapObject->mUnk_000.mPos.z += dz;

    probePosition.x = mapObject->mUnk_000.mPos.x;
    probePosition.y = mapObject->mUnk_000.mPos.y + 0x14000;
    probePosition.z = mapObject->mUnk_000.mPos.z;
    mapObject->mCollisionBits = 0;
    if (func_01ffdee4(&probePosition, NULL, 0, 0x14000, mapObject->mUnk_2b8 == 1 ? (u16) 4 : (u16) 1, -2, &pushOut,
                      &v50, &v5c, &mapObject->mCollisionBits, NULL, NULL, NULL, NULL)) {
        if (mapObject->mUnk_2b8 == 2 || mapObject->mUnk_2b8 == 3) {
            mapObject->mUnk_000.mPos.y += pushOut.y;
        } else {
            mapObject->mUnk_000.mPos.x += pushOut.x;
            mapObject->mUnk_000.mPos.y += pushOut.y;
            mapObject->mUnk_000.mPos.z += pushOut.z;
        }
    }
    if (mapObject->mUnk_2b8 != 2 && (mapObject->mCollisionBits & 0x214300)) {
        if ((s64) v5c.x * v5c.x + (s64) v5c.y * v5c.y + (s64) v5c.z * v5c.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v5c, &pushDirection);
        }
        pushDirection.y = 0;
        VEC_MultAdd(mapObject->mPrm->mUnk_030, &pushDirection, &mapObject->mVelocity, &mapObject->mVelocity);
    }

    if (mapObject->mCollisionBits & 0x1e34ef) {
        if (mapObject->mVelocity.y > 0) {
            mapObject->mCollisionBits &= ~0x1e34ef;
        } else if (mapObject->mBounceEnabled != FALSE) {
            mapObject->mVelocity.y = (((s64) mapObject->mVelocity.y * -mapObject->mPrm->mUnk_020) >> 12);
            if (mapObject->mVelocity.y < mapObject->mPrm->mUnk_018) {
                mapObject->mBounceEnabled = FALSE;
                mapObject->mVelocity.y = 0;
            }
        } else {
            mapObject->mVelocity.y = 0;
        }
    }
    if (mapObject->mUnk_000.mPos.y < 0) {
        mapObject->mUnk_000.mPos.y = 0;
        mapObject->mCollisionBits |= data_ov001_021a6584;
    }
    if (mapObject->mAlphaLimitPerCall > 0) {
        mapObject->mAlphaLimit =
            StepIntTowardTarget(mapObject->mAlphaLimitTarget, mapObject->mAlphaLimitPerCall, mapObject->mAlphaLimit);
        if (mapObject->mAlphaLimit == mapObject->mAlphaLimitTarget) {
            mapObject->mAlphaLimitPerCall = 0;
        }
    }
    if (mapObject->mScalePerCall > 0) {
        mapObject->mUnk_000.mScale.x = mapObject->mUnk_000.mScale.y = mapObject->mUnk_000.mScale.z =
            StepIntTowardTarget(mapObject->mScaleTarget, mapObject->mScalePerCall, mapObject->mUnk_000.mScale.x);
    }
    if (mapObject->mCollisionShape == 1) {
        MTX_RotY33_(&mapObject->mUnk_000.mMatrix.mUnk_00[0].x, gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2],
                    gPairsByAngle[((u16) mapObject->mAngle >> 4) * 2 + 1]);
        MTX_MultVec33(&mapObject->mOffset, &mapObject->mUnk_000.mMatrix.mUnk_00[0].x, &mapObject->mPosWithOffset);
        VEC_Add(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPos, &mapObject->mPosWithOffset);
    } else {
        mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + mapObject->mOffset.x;
        mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + mapObject->mOffset.y;
        mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + mapObject->mOffset.z;
    }
    mapObject->mUnk_000.mAngle = mapObject->mAngle;

    if (mapObject->mNsbmd != NULL) {
        previousFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        func_ov001_0219b250(mapObject->mNsbmd);
        currentFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (mapObject->mAnimationFrameCallbackFrameIndex != 0) {
            if (previousFrame < mapObject->mAnimationFrameCallbackFrameIndex &&
                mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame ||
                        previousFrame < mapObject->mAnimationFrameCallbackFrameIndex)) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            }
        }
        if (mapObject->mUnk_1e0 != 0) {
            if (previousFrame < mapObject->mUnk_1e0 && mapObject->mUnk_1e0 <= currentFrame) {
                mapObject->mUnk_1e4(mapObject);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mUnk_1e0 <= currentFrame || previousFrame < mapObject->mUnk_1e0)) {
                mapObject->mUnk_1e4(mapObject);
            }
        }
        if (mapObject->mUnk_1e8 != 0) {
            if (previousFrame < mapObject->mUnk_1e8 && mapObject->mUnk_1e8 <= currentFrame) {
                mapObject->mUnk_1ec(mapObject);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mUnk_1e8 <= currentFrame || previousFrame < mapObject->mUnk_1e8)) {
                mapObject->mUnk_1ec(mapObject);
            }
        }
        if (!func_ov001_0219b240(mapObject->mNsbmd)) {
            ClearAndRunCallback(mapObject, &mapObject->mAnimationEndCallback);
        }
    }

    mapObject->mStateFrames++;
    if (mapObject->mStateFrameCount != 0 && mapObject->mStateFrames == mapObject->mStateFrameCount) {
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrames = 0;
        ClearAndRunCallback(mapObject, &mapObject->mStateFrameCountCallback);
    }
    if (mapObject->mPointInRangeCallback != NULL &&
        IsPointInRange(mapObject, &mapObject->mPoint, mapObject->mPointRadius, mapObject->mPointHalfAngle)) {
        ClearAndRunCallback(mapObject, &mapObject->mPointInRangeCallback);
    }
    if (mapObject->mUnk_224 != NULL &&
        !IsPointInRange(mapObject, &mapObject->mUnk_218, mapObject->mUnk_210, mapObject->mUnk_214)) {
        ClearAndRunCallback(mapObject, &mapObject->mUnk_224);
    }
    if (mapObject->mStoppedCallback != NULL && mapObject->mVelocity.y == 0 &&
        -mapObject->mPrm->mUnk_018 < mapObject->mSpeed && mapObject->mPrm->mUnk_018 > mapObject->mSpeed &&
        -mapObject->mPrm->mUnk_018 < mapObject->mVelocity.x && mapObject->mPrm->mUnk_018 > mapObject->mVelocity.x &&
        -mapObject->mPrm->mUnk_018 < mapObject->mVelocity.z && mapObject->mPrm->mUnk_018 > mapObject->mVelocity.z &&
        (mapObject->mCollisionBits & 0x1e34ef)) {
        ClearAndRunCallback(mapObject, &mapObject->mStoppedCallback);
    }
    if (mapObject->mCourseCollisionCallback != NULL && mapObject->mVelocity.y <= 0 &&
        (mapObject->mCollisionBits & 0x1e34ef)) {
        ClearAndRunCallback(mapObject, &mapObject->mCourseCollisionCallback);
    }

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        ComputeEffectPosition(mapObject, effectIndex, &effectPosition);
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            if (mapObject->mEffects[effectIndex].mTimer > 0 && --mapObject->mEffects[effectIndex].mTimer == 0) {
                func_0208b6b0(&mapObject->mEffects[effectIndex].mEffect);
            } else {
                func_0208b5b0(mapObject->mEffects[effectIndex].mEffect, &effectPosition);
            }
        }
    }
    if (mapObject->mTimer > 0) {
        mapObject->mTimer--;
    }
}

void DrawMissionRunMapObject(void *mapObjectList, Unk02188950 *mapObject) {
    s32 materialIndex;
    s32 alphaLimit;
    NNSG3dResMdl *resMdl;
    s32 alpha;
    s32 value;
    Vec3 shiftedPosition;
    s32 rotationMatrix[9];
    s32 pairIndex;

    alphaLimit = mapObject->mAlphaLimit >> 12;
    shiftedPosition.x = mapObject->mUnk_000.mPos.x >> 4;
    shiftedPosition.y = mapObject->mUnk_000.mPos.y >> 4;
    shiftedPosition.z = mapObject->mUnk_000.mPos.z >> 4;
    alpha = func_020e69bc(&shiftedPosition);
    if (alpha >= alphaLimit) {
        alpha = alphaLimit;
    }
    if (alpha > 0) {
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        if (alpha >= 0x1f) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else if (mapObject->mUnk_27c <= 1) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else {
            resMdl = mapObject->mNsbmd->mAnimatedModel->mResMdl;
            NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
            for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
                func_0209b904(mapObject->mNsbmd, AllocPolygonIdWrapping(), materialIndex);
            }
        }
        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, SetTranslationMatrixPos(&mapObject->mUnk_000.mPos), 0xc);
        if (mapObject->mUnk_000.mAngle != 0) {
            pairIndex = mapObject->mUnk_000.mAngle >> 4;
            MTX_RotY33_(rotationMatrix, gPairsByAngle[pairIndex * 2], gPairsByAngle[pairIndex * 2 + 1]);
            func_01ff9048(0x1a, rotationMatrix, 9);
        }
        func_01ff9048(0x1b, &mapObject->mUnk_000.mScale.x, 3);
        SetMapObjectModelAlpha(mapObject->mNsbmd, alpha);
        SetMapObjectModelMirror(mapObject->mNsbmd, mapObject->mUnk_000.mFlags & 0x400, 0);
        DrawMapObjectModel(mapObjectList, mapObject->mNsbmd, mapObject);
    }
}

void DrawMissionRunMapObjectShadow(void *mapObjectList, Unk02188950 *mapObject, s32 invertDepth) {
    s32 depth;
    s32 value;
    Vec3 shadowPosition;

    depth = mapObject->mAlphaLimit >> 12;
    if (mapObject->mUnk_27c == 2) {
        shadowPosition.x = mapObject->mUnk_000.mPos.x;
        shadowPosition.y = mapObject->mUnk_000.mPos.y;
        shadowPosition.z = mapObject->mUnk_000.mPos.z;
    } else if (mapObject->mUnk_27c == 3) {
        shadowPosition.x = mapObject->mUnk_2e8.x;
        shadowPosition.y = mapObject->mUnk_000.mCourseMapRow->mUnk_00.y;
        shadowPosition.z = mapObject->mUnk_2e8.z;
    } else {
        if (depth >= 4) {
            s32 t = depth - ((mapObject->mUnk_000.mPos.y - mapObject->mUnk_000.mCourseMapRow->mUnk_00.y) >> 15);

            if (t <= 4) {
                t = 4;
            }
            depth = (u16) t;
        }
        shadowPosition.x = mapObject->mUnk_000.mPos.x;
        shadowPosition.y = mapObject->mUnk_000.mCourseMapRow->mUnk_00.y;
        shadowPosition.z = mapObject->mUnk_000.mPos.z;
    }
    if (depth > 0x10) {
        depth = 0x10;
    }
    if (invertDepth != 0) {
        depth = 0x14 - depth;
    }
    if (depth > 0) {
        s32 rotationMatrix[9];
        Vec3 w;
        Vec3 u;
        s32 pairIndex;
        s32 a;
        s32 b;
        s32 c;

        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, SetTranslationMatrixPos(&shadowPosition), 0xc);
        pairIndex = (u16) mapObject->mAngle >> 4;
        MTX_RotY33_(rotationMatrix, gPairsByAngle[pairIndex * 2], gPairsByAngle[pairIndex * 2 + 1]);
        func_01ff9048(0x1a, rotationMatrix, 9);
        c = mapObject->mShadowOffsetZ >> 4;
        b = mapObject->mShadowOffsetY >> 4;
        a = mapObject->mShadowOffsetX >> 4;
        w.x = a;
        w.y = b;
        w.z = c;
        func_01ff9048(0x1c, &w, 3);
        func_01ff9048(0x1b, &mapObject->mShadowScaleX, 3);
        if (gShadowScaleToggle == 0) {
            u.x = 0x1333;
            u.y = 0x1000;
            u.z = 0x1333;
            func_01ff9048(0x1b, &u, 3);
        }
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 3);
        SetMapObjectModelAlpha(mapObject->mShadowNsbmd, depth);
        DrawMapObjectModel(mapObjectList, mapObject->mShadowNsbmd, mapObject);
    }
}

s32 ComputeSphereHitOnMissionRunMapObject(Unk02188950 *mapObject, Vec3 *sphereCenter, s32 sphereRadius,
                                          Vec3 *overlapOffset) {
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    switch (mapObject->mCollisionShape) {
        case 0:
            sphereRadius += mapObject->mCollisionExtent.x;
            diffX = sphereCenter->x - mapObject->mPosWithOffset.x;
            diffY = sphereCenter->y - mapObject->mPosWithOffset.y;
            diffZ = sphereCenter->z - mapObject->mPosWithOffset.z;
            if ((s64) diffZ * diffZ + ((s64) diffX * diffX + (s64) diffY * diffY) < (s64) sphereRadius * sphereRadius) {
                ComputeSphereOverlapOffset(sphereCenter, &mapObject->mPosWithOffset, sphereRadius, overlapOffset);
                return 1;
            }
            return 0;
        case 2:
            return ComputeSphereHitOnRotatedCylinder(sphereCenter, &mapObject->mPosWithOffset,
                                                     &mapObject->mUnk_000.mMatrix.mUnk_00[0],
                                                     mapObject->mCollisionExtent.x, mapObject->mCollisionExtent.y,
                                                     mapObject->mCollisionExtent.y, sphereRadius, overlapOffset);
        case 1:
            return ComputeSphereHitOnRotatedBox(sphereCenter, &mapObject->mPosWithOffset,
                                                &mapObject->mUnk_000.mMatrix.mUnk_00[0], &mapObject->mCollisionExtent,
                                                &mapObject->mCollisionExtent, sphereRadius, overlapOffset);
        default:
            return 0;
    }
}

s32 CollideKartWithMissionRunMapObject(Unk02188950 *mapObject, Unk02185fb0_1 *kart, u8 *c, u8 *d) {
    Vec3 awayDirection;
    s64 pushStrength;
    u32 mode;
    UnkFunc *collisionCallback;

    mode = *c;
    mapObject->mUnk_2d8 = *d;
    mapObject->mUnk_000.mUnk_10.x = 0;
    mapObject->mUnk_000.mUnk_10.y = 0;
    mapObject->mUnk_000.mUnk_10.z = 0;
    if (mode == 1) {
        awayDirection.x = mapObject->mUnk_000.mPos.x - kart->mUnk_80;
        awayDirection.y = 0;
        awayDirection.z = mapObject->mUnk_000.mPos.z - kart->mUnk_88;
        if ((s64) awayDirection.z * awayDirection.z +
                ((s64) awayDirection.x * awayDirection.x + (s64) awayDirection.y * awayDirection.y) >=
            16) {
            Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
            pushStrength = -mapObject->mPrm->mUnk_024;
            mapObject->mUnk_000.mUnk_10.x = (((s64) awayDirection.x * pushStrength) >> 12);
            mapObject->mUnk_000.mUnk_10.y = (((s64) awayDirection.y * pushStrength) >> 12);
            mapObject->mUnk_000.mUnk_10.z = (((s64) awayDirection.z * pushStrength) >> 12);
            VEC_MultAdd(mapObject->mPrm->mUnk_028, &awayDirection, &mapObject->mVelocity, &mapObject->mVelocity);
        }
        collisionCallback = mapObject->mKartCollisionCallback;
        mapObject->mKartCollisionCallback = NULL;
        if (collisionCallback) {
            collisionCallback(mapObject, kart);
        }
    }
    if (mapObject->mTimer == 0) {
        mapObject->mTimer = 0x1f;
    }
    return mapObject->mUnk_2d8;
}

s32 CollideItemWithMissionRunMapObject(Unk02188950 *mapObject, Unk02185f04_1 *itemObject, u8 *c, u8 *d) {
    Vec3 awayDirection;
    UnkFunc *collisionCallback;

    mapObject->mUnk_2e0 = *d;
    awayDirection.x = mapObject->mUnk_000.mPos.x - itemObject->mUnk_50;
    awayDirection.y = 0;
    awayDirection.z = mapObject->mUnk_000.mPos.z - itemObject->mUnk_58;
    if ((s64) awayDirection.z * awayDirection.z +
            ((s64) awayDirection.x * awayDirection.x + (s64) awayDirection.y * awayDirection.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
        VEC_MultAdd(mapObject->mPrm->mUnk_02c, &awayDirection, &mapObject->mVelocity, &mapObject->mVelocity);
    }
    collisionCallback = mapObject->mItemCollisionCallback;
    mapObject->mItemCollisionCallback = NULL;
    if (collisionCallback) {
        collisionCallback(mapObject, itemObject);
    }
    return mapObject->mUnk_2e0;
}

void *CreateEmptyMapObjectUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, NULL, NULL);
}
