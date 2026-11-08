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

KartEffects *GetKartEffects(int kartIndex) {
    u32 value0 = kartIndex;
    u32 entrySize;
    u32 value2;
    value2 = (u32) &gKartEffects;
    entrySize = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (entrySize) * (value0) + (value2);
    return (KartEffects *) value0;
}

void InitKartEffects(u32 kartCount) {
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    i = 0;
    gKartEffects = HeapAlloc(GetHeap(GetCurrentHeapCall()), kartCount * 0x58);
    data_0217ae70 = kartCount;
    for (; i < kartCount; i++) {
        kartEffects = &gKartEffects[i];
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mUnk_28 = NULL;
        kartEffects->mKillerEffect = NULL;
        kartEffects->mUnk_30 = NULL;
        kartEffects->mCurrentEffectId = -1;
        kartEffects->mWaterEffect0 = kartEffects->mWaterEffect1 = 0;
        for (j = 0; j < 2; j++) {
            kartEffects->mEffectPairs[j].mEffect0 = kartEffects->mEffectPairs[j].mEffect1 = 0;
            kartEffects->mEffectIds[j] = -1;
        }
    }
    gKartBoostCameraEffect = NULL;
}

void ComputeKartSidePoints(Kart *kart) {
    u16 i;
    KartEffects *kartEffects;
    Vec3 scaledPoint;
    Vec3 sideDirection;
    Vec3 modelPoint;

    kartEffects = &gKartEffects[kart->mIndex];
    kart->mUnk_174 = *kart->mPosSource;
    for (i = 0; i < 2; i++) {
        modelPoint = kart->mKartModelsEntry->mKartOffsetData->mUnk_14[i + 2];
        modelPoint.y = 0;
        modelPoint.x = modelPoint.x + gKartSideOffsetsX[i];
        scaledPoint.x = ((s64) modelPoint.x * kart->mScale.x) >> 12;
        scaledPoint.y = ((s64) modelPoint.y * kart->mScale.y) >> 12;
        scaledPoint.z = ((s64) modelPoint.z * kart->mScale.z) >> 12;
        MTX_MultVec43(&scaledPoint, &kart->mUnk_150_m, &kartEffects->mSidePositions[i]);
        kartEffects->mSidePositions[i].x = kartEffects->mSidePositions[i].x >> 4;
        kartEffects->mSidePositions[i].y = kartEffects->mSidePositions[i].y >> 4;
        kartEffects->mSidePositions[i].z = kartEffects->mSidePositions[i].z >> 4;
        MTX_MultVec33(&gKartSideDirectionVectors[i], &kart->mUnk_150.x, &sideDirection);
        kartEffects->mSideDirections[i].x = sideDirection.x;
        kartEffects->mSideDirections[i].y = sideDirection.y;
        kartEffects->mSideDirections[i].z = sideDirection.z;
    }
}

void func_0208442c(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
}

void func_020843d8(Kart *kart) {
    gKartSurfaceEffectRows[0].mStartEffects(
        &gKartSurfaceEffectRows[0].mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
        gKartSurfaceEffectRows[0].mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

void func_02084384(Kart *kart) {
    gKartSurfaceEffectRow1.mStartEffects(&gKartSurfaceEffectRow1.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow1.mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

void func_02084334(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    func_02083de8(2, kart);
}

void func_020842ac(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow3.mStartEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow3.mVelocityFactorIndex, kart);
}

void func_02084224(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow4.mStartEffects(&gKartSurfaceEffectRow4.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow4.mVelocityFactorIndex, kart);
}

void func_0208419c(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow5.mStartEffects(&gKartSurfaceEffectRow5.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow5.mVelocityFactorIndex, kart);
}

void func_02084114(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow6.mStartEffects(&gKartSurfaceEffectRow6.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow6.mVelocityFactorIndex, kart);
}

void func_020840c0(Kart *kart) {
    gKartSurfaceEffectRow7.mStartEffects(&gKartSurfaceEffectRow7.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow7.mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

// Starts the boost effect in front of the chase camera; the previous one is told to end.
void StartKartBoostCameraEffect(u32 effectIdIndex, Kart *kart) {
    Unk0201ca6c *effect;

    if (GetCurrentCameraKind() != 0) {
        return;
    }
    GetChaseCamera();
    if (gKartBoostCameraEffect != NULL) {
        gKartBoostCameraEffect->mUnk_24.mUnk_00_0 = 1;
    }
    effect = StartEffect(gKartBoostCameraEffectIds[effectIdIndex], &data_02155a14);
    effect->mUnk_98 = 0;
    effect->mUnk_94 = kart;
    effect->mUnk_90 = AdvanceKartBoostCameraEffect;
    gKartBoostCameraEffect = effect;
}

// Runs entry a of the effect table while the kart flag is set, otherwise ends the kart effects.
void ApplyKartSurfaceEffect(s32 functionIndex, Kart *kart) {
    KartEffects *kartEffects;

    if (kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        gKartSurfaceEffectFunctions[functionIndex](kart);
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Starts the water effects while the kart flag is set, otherwise ends them.
void ApplyKartWaterEffects(Kart *kart) {
    KartEffects *kartEffects;

    if (kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        StartKartWaterEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]], 1, kart);
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

void func_02083de8(s32 rowIndex, Kart *kart) {
    KartSurfaceEffectRow *row;
    KartEffectIdSet *effectIdSet;
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    row = &gKartSurfaceEffectRows[rowIndex];
    effectIdSet = &row->mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]];
    if (row->mStartEffects(effectIdSet, row->mVelocityFactorIndex, kart) == 0) {
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    for (i = 0; i < effectIdSet->mCount; i++) {
        for (j = 0; j < 2; j++) {
            if (kartEffects->mEffectPairs[i].mUnk_00_a[j] != 0) {
                kartEffects->mEffectPairs[i].mUnk_00_a[j]->mUnk_72 = data_0217ae6c;
            }
        }
    }
}

BOOL StartKartCurrentEffect(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;

    kartEffects = &gKartEffects[kart->mIndex];
    if (effectIdSet->mEffectIds[0] == kartEffects->mCurrentEffectId) {
        return FALSE;
    }
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
    }
    effect = StartEffect(effectIdSet->mEffectIds[0], &data_02155a14);
    kartEffects->mCurrentEffect = effect;
    kartEffects->mCurrentEffectId = effectIdSet->mEffectIds[0];
    effect->mUnk_94 = kart;
    effect->mUnk_98_0 = velocityFactorIndex;
    effect->mUnk_90 = AdvanceKartCurrentEffect;
    return TRUE;
}

// Starts one effect per side of the kart for each id that is not running yet.
s32 StartKartSideEffects(KartEffectIdSet *effectIdSet, s32 unusedVelocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &gKartEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = StartEffect(kartEffects->mEffectIds[i], &data_02155a14);
                gKartEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->mUnk_94 = kart;
                effect->mUnk_98_24 = j;
                j++;
                effect->mUnk_90 = AdvanceKartSideEffect;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

s32 StartKartSideEffectsWithVelocity(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &gKartEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = StartEffect(kartEffects->mEffectIds[i], &data_02155a14);
                gKartEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->mUnk_94 = kart;
                effect->mUnk_98_24 = j;
                j++;
                effect->mUnk_98_0 = velocityFactorIndex;
                effect->mUnk_90 = AdvanceKartSideEffectWithVelocity;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

BOOL StartKartWaterEffects(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    u16 i;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0 || kartEffects->mWaterEffect1 != 0) {
        return FALSE;
    }
    for (i = 0; i < 2; i++) {
        effect = StartEffect(effectIdSet->mEffectIds[0], &data_02155a14);
        gKartEffects[kart->mIndex].mUnk_20_a[i] = effect;
        effect->mUnk_94 = kart;
        effect->mUnk_98_24 = i;
        effect->mUnk_98_0 = velocityFactorIndex;
        effect->mUnk_90 = AdvanceKartWaterEffect;
    }
    return TRUE;
}

void StopKartCurrentEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
}

void StopKartEffectPairs(Kart *kart, s32 deleteAtOnce) {
    u16 i;
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    for (i = 0; i < 2; i++) {
        if (kartEffects->mEffectPairs[i].mEffect0 != 0 || kartEffects->mEffectPairs[i].mEffect1 != 0) {
            if (deleteAtOnce == 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            } else {
                DeleteEffect(kartEffects->mEffectPairs[i].mEffect0);
                DeleteEffect(kartEffects->mEffectPairs[i].mEffect1);
            }
            kartEffects->mEffectPairs[i].mEffect0 = kartEffects->mEffectPairs[i].mEffect1 = 0;
            kartEffects->mEffectIds[i] = -1;
        }
    }
}

void StopKartWaterEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Deletes the current, side and water effects of the kart at once.
void ReleaseKartSurfaceEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        DeleteEffect(kartEffects->mCurrentEffect);
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 1);
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        DeleteEffect(kartEffects->mWaterEffect0);
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 == 0) {
        return;
    }
    DeleteEffect(kartEffects->mWaterEffect1);
    kartEffects->mWaterEffect1 = 0;
}

void AdvanceKartBoostCameraEffect(Unk0201ca6c *effect, s32 a) {
    Vec3s16 backwardDirection;
    Vec3 viewPos;
    Vec3 forwardOffset;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = effect->mUnk_94;
    if (GetCurrentCameraKind() != 0 ||
        (effect->mUnk_24.mUnk_00_1 != 0 && (effect->mUnk_98 = effect->mUnk_98 + 1, effect->mUnk_98 > 5))) {
        effect->mUnk_24.mUnk_00_0 = 1;
        gKartBoostCameraEffect = NULL;
        return;
    }
    if (!(kart->mUnk_48 & KART_48_BOOST)) {
        effect->mUnk_24.mUnk_00_1 = 1;
    }
    viewPos = chaseCamera->mViewPos;
    forwardOffset.x = ((s64) chaseCamera->mForward.x * 0x5000) >> 12;
    forwardOffset.y = ((s64) chaseCamera->mForward.y * 0x5000) >> 12;
    forwardOffset.z = ((s64) chaseCamera->mForward.z * 0x5000) >> 12;
    VEC_Add(&forwardOffset, &viewPos, &effectPos);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    backwardDirection.x = -chaseCamera->mForward.x;
    backwardDirection.y = -chaseCamera->mForward.y;
    backwardDirection.z = -chaseCamera->mForward.z;
    effect->mUnk_50 = backwardDirection;
}

void AdvanceKartCurrentEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 effectPos;
    Vec3 velocity;
    Vec3 offsetBehind;
    Kart *kart;
    Vec3 *s;
    u32 stepCount;
    s32 velocityFactor;
    u32 counting;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    velocity = kart->mEffectVelocity;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (f != 0);
    s = &kart->mUnk_138;
    offsetBehind.x = ((s64) s->x * -0x5000) >> 12;
    offsetBehind.y = ((s64) s->y * -0x5000) >> 12;
    offsetBehind.z = ((s64) s->z * -0x5000) >> 12;
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    VEC_Add(kart->mPosSource, &offsetBehind, &effectPos);
    effectPos.x = effectPos.x >> 4;
    effectPos.y = effectPos.y >> 4;
    effectPos.z = effectPos.z >> 4;
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_40 = velocity;
}

void AdvanceKartSideEffect(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (f != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = x + effect->mUnk_20->mUnk_00->mUnk_04.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = x + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceKartSideEffectWithVelocity(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Vec3 velocity;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    s32 velocityFactor;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (f != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = x + effect->mUnk_20->mUnk_00->mUnk_04.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = x + effect->mUnk_20->mUnk_00->mUnk_04.z;
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->mUnk_40 = velocity;
}

// Keeps the water effect at the kart's side, raised by the depth below the water surface.
void AdvanceKartWaterEffect(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Vec3 velocity;
    u32 counting;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 f;
    u32 sideIndex;
    s32 velocityFactor;
    u32 g;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    g = 1;
    f = 1;
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    if (f == 0) {
        if (kart->mWaterDepth <= 0x5000) {
            g = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (g != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = x + effect->mUnk_20->mUnk_00->mUnk_04.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = x + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_28.y = effect->mUnk_28.y + (kart->mWaterDepth >> 4);
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->mUnk_40 = velocity;
}

void AdvanceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceOtherKartEffect(effect, a);
    effect->mUnk_98_24 = effect->mUnk_98_24 + 1;
    if (effect->mUnk_98_24 >= 2) {
        effect->mUnk_98_16 = (effect->mUnk_98_16 == 0);
        effect->mUnk_98_24 = 0;
    }
}

// Starts two effects for each pair of the other karts; each effect switches between the pair's two karts.
void StartEffectsAtOtherKarts(s32 pairSetIndex) {
    OtherKartEffectKind *effectKind;
    s32 kindIndex;
    KartIndexPair *pair;
    s32 startedCount;
    u32 f;
    s32 fullPairCount;
    s32 i;
    s32 oddCount;
    Unk0201ca6c *effect;

    gOtherKartPairsCopy = gOtherKartPairs[pairSetIndex];
    fullPairCount = gOtherKartFullPairCount;
    i = fullPairCount;
    if (i < 4) {
        oddCount = gOtherKartOddCount;
        do {
            if (i != fullPairCount || oddCount == 0) {
                gOtherKartPairsCopy.mPairs[i].mFirst = -1;
            }
            gOtherKartPairsCopy.mPairs[i].mSecond = -1;
            i++;
        } while (i < 4);
    }
    effectKind = gOtherKartEffectKinds;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        f = (kindIndex != 0) ? 1 : 0;
        startedCount = 0;
        pair = gOtherKartPairsCopy.mPairs;
        do {
            if (pair->mFirst < 0) {
                break;
            }
            effect = func_0208b60c(effectKind->mEffectId, &data_02155a14);
            startedCount++;
            effect->mUnk_90 = effectKind->mAdvance;
            effect->mUnk_98_0 = pair->mFirst;
            effect->mUnk_98_8 = (pair->mSecond < 0) ? 0xff : (u8) pair->mSecond;
            pair++;
            effect->mUnk_98_16 = f;
            effect->mUnk_98_24 = 0;
            effect->mUnk_94_u = 0;
        } while (startedCount < 4);
        effectKind++;
    }
}

void PlaceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    Unk0201ca6c_98 *s;
    Kart *kart;
    u32 n;
    u32 f;
    u32 x;
    s32 kartIndex;
    s32 pointX;
    s32 pointY;
    s32 pointZ;

    s = &effect->mUnk_98_b;
    kartIndex = s->mUnk_02;
    n = effect->mUnk_94_u;
    kartIndex = (kartIndex == 0) ? s->mUnk_00 : s->mUnk_01;
    x = s->mUnk_01;
    f = 1;
    if (x > 8) {
        if (kartIndex > 8) {
            f = 0;
        }
        kartIndex = s->mUnk_00;
    }
    kart = GetKart(kartIndex);
    pointX = kart->mPointAlongUp.x;
    pointY = kart->mPointAlongUp.y;
    pointZ = kart->mPointAlongUp.z;
    effect->mUnk_28.x = (pointX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (pointY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (pointZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (kart->mUnk_7c & 0x402000) {
        f = 0;
    }
    effect->mUnk_24.mUnk_00_3 = (f == 0);
    if (n + 1 >= 0x32) {
        effect->mUnk_24.mUnk_00_0 = 1;
    }
    effect->mUnk_94_u = n + 1;
}

// Sets the effect speed scale, then starts the effects of two courses and ties them to the camera.
void InitCourseCameraEffects(void) {
    s32 engineScale;
    s32 engineIndex;

    engineIndex = gRaceSetup->mEngineIndex;
    engineScale = 0x1000;
    switch (engineIndex) {
        case 1:
            engineScale = 0xd9a;
            break;
        case 0:
            engineScale = 0xb33;
            break;
    }
    data_0217ae9c = FX_Div(0x1000, ((s64) engineScale * 0x779a + 0x800) >> 12);
    gSecondCourseCameraEffect = NULL;
    gFirstCourseCameraEffect = NULL;
    switch (gRaceSetup->mCourseId) {
        case 0x25: {
            Unk0201ca6c *effect;

            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                effect = StartEffect(0x24, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_02082750;
                effect = StartEffect(0x27, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = func_02082a10;
            } else if (GetRaceUseChainCameras() != 0) {
                effect = StartEffect(0x3d, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_020824d0;
                effect = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = func_0208266c;
            } else {
                effect = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_020824d0;
                effect = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = func_0208266c;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *effect;

            if (GetRaceUseChainCameras() != 0) {
                effect = StartEffect(0x3e, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_02082034;
            } else if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                effect = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_020821cc;
                effect = StartEffect(0x25, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = func_02082368;
            } else {
                effect = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_02082034;
            }
            break;
        }
    }
}

void func_02082a10(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082750(Unk0201ca6c *effect, s32 a) {
    Vec3s16 h;
    Vec3 forwardFlat;
    Vec3 axis;
    Vec3 effectPos;
    MtxFx33 rotation;
    Vec3 rotatedVector;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;
    s32 k;
    s32 s;
    u16 angle;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &axis);
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    rotatedVector = data_02165984;
    k = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->mUnk_44 & 0x100) {
        speedRatio = speedRatio * 0xffffffff;
        k = data_02165938;
    }
    angle = (s32) (((s64) speedRatio * 0x38e3 + 0x800) >> 12);
    MTX_RotAxis33((MtxFx43 *) &rotation, &axis, gPairsByAngle[(angle >> 4) * 2], gPairsByAngle[(angle >> 4) * 2 + 1]);
    MTX_MultVec33(&rotatedVector, rotation.mUnk_00, &rotatedVector);
    h.x = rotatedVector.x;
    h.y = rotatedVector.y;
    h.z = rotatedVector.z;
    effect->mUnk_68 = (s16) ((s32) (((s64) (0x1000 - speedRatio) * 0x800 + 0x800) >> 12) + 0x800);
    effect->mUnk_50 = h;
    s = data_02165954 + k;
    VEC_MultAdd(data_02165938 + (s32) (((s64) s * (s64) speedRatio + 0x800) >> 12), &forwardFlat,
                &chaseCamera->mViewPos, &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effectPos.y = effectPos.y - (s32) (((s64) data_02165934 * speedRatio + 0x800) >> 12);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_0208266c(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    forwardFlat = currentCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020824d0(Unk0201ca6c *effect, s32 a) {
    Vec3s16 h;
    Vec3 forwardFlat;
    Vec3 x;
    Vec3 effectPos;
    Vec3 w;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = currentCamera->mForward;
    w = data_02155a08;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &x);
    w.y = w.y * 0xffffffff;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    effect->mUnk_68 = 0x1000;
    effect->mUnk_50 = h;
    VEC_MultAdd(data_02165964, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y =
        effectPos.y + (data_02165968 + (s32) (((s64) currentCamera->mForward.y * data_02165960 + 0x800) >> 12));
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082368(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    effect->mUnk_58 = ((s64) (0x1000 - speedRatio) * 0x400 + 0x800) >> 12;
}

void func_020821cc(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    s32 k;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    k = 0;
    forwardFlat.y = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->mUnk_44 & 0x100) {
        k = -0x5800;
    }
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    k = k * 3;
    VEC_MultAdd((s32) (((s64) k * (s64) speedRatio + 0x800) >> 12) + 0x5800, &forwardFlat, &chaseCamera->mViewPos,
                &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_58 = ((s64) 0x800 * speedRatio + 0x800) >> 12;
}

void func_02082034(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Vec3 extraOffset;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    forwardFlat = currentCamera->mForward;
    extraOffset = data_02155a14;
    if (func_0203c5e4() != 0) {
        FX_Atan2Idx(currentCamera->mHalfFovPairFirst, currentCamera->mHalfFovPairSecond);
        VEC_Subtract(&currentCamera->mPos, &currentCamera->mPrevPos, &extraOffset);
        extraOffset.x = extraOffset.x >> 4;
        extraOffset.y = extraOffset.y >> 4;
        extraOffset.z = extraOffset.z >> 4;
    }
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y =
        effectPos.y + (data_0216595c + (s32) (((s64) currentCamera->mForward.y * data_02165940 + 0x800) >> 12));
    VEC_Add(&effectPos, &extraOffset, &effectPos);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_58 = 0x800;
}

void func_02081f30(void) {
    Unk0201ca6c *effect;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gFirstCourseCameraEffect != NULL) {
                DeleteEffect(gFirstCourseCameraEffect);
                effect = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = func_020824d0;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            DeleteEffect(gSecondCourseCameraEffect);
            effect = StartEffect(0x3f, &data_02155a14);
            gSecondCourseCameraEffect = effect;
            effect->mUnk_90 = func_0208266c;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            if (gFirstCourseCameraEffect != NULL) {
                gFirstCourseCameraEffect->mUnk_90 = func_02082034;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            DeleteEffect(gSecondCourseCameraEffect);
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

void AdvanceKartFollowEffect(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;
    Vec3 *kartPos;
    Kart *kart;
    s32 posX;
    s32 posY;
    s32 posZ;

    if (a != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    kart = GetKart(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->mUnk_28.x = (posX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (posY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (posZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void SetupKartFollowEffectWithVelocity(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->mUnk_90 = AdvanceKartFollowEffectWithVelocity;
}

void AdvanceKartFollowEffectWithVelocity(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;
    Vec3 *kartPos;
    Kart *kart;
    s32 posX;
    s32 posY;
    s32 posZ;

    if (a != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    kart = GetKart(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->mUnk_28.x = (posX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (posY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (posZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_40 = kart->mEffectVelocity;
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void PlaceKartAheadEffect(Unk0201ca6c *effect, Kart *kart, void *a) {
    u32 r;
    u32 f;

    if (a == NULL) {
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x733, 0xb33);
        effect->mUnk_5c = (s16) (((s64) kart->mScale.z * 0xb33 + 0x800) >> 12);
    } else {
        r = 1;
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x99a, 0xe66);
        effect->mUnk_6c = (s16) kart->mScale.z;
        f = kart->mUnk_7c;
        if (!(f & 1)) {
            if (f & 0x402000) {
                r = 0;
            }
        }
        effect->mUnk_24.mUnk_00_3 = (r == 0);
    }
}

// Puts the effect ahead of the kart by b and above it by a, pointing backward.
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *effect, Kart *kart, s32 upDistance, s32 aheadDistance) {
    Vec3 position;
    Vec3 w;
    Vec3s16 backwardDirection;
    Vec3 *kartPos = kart->mPosSource;

    position.x = kartPos->x >> 4;
    position.y = kartPos->y >> 4;
    position.z = kartPos->z >> 4;
    VEC_MultAdd(((s64) kart->mScale.z * aheadDistance + 0x800) >> 12, &kart->mUnk_138, &position, &position);
    VEC_MultAdd(((s64) kart->mScale.y * upDistance + 0x800) >> 12, &kart->mUnk_12c, &position, &position);
    effect->mUnk_28.x = position.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = position.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = position.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    GetKartForward(kart, &w);
    w.x = -w.x;
    w.y = -w.y;
    w.z = -w.z;
    backwardDirection.x = w.x;
    backwardDirection.y = w.y;
    backwardDirection.z = w.z;
    effect->mUnk_50 = backwardDirection;
}

void AdvanceKartAheadEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceKartAheadEffect(effect, GetKart(effect->mUnk_98_24), effect->mUnk_94);
}

void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;

    if (a != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    PlaceKartAheadEffect(effect, GetKart(kartIndex), effect->mUnk_94);
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void StartKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            DeleteEffect(starEffects->mEffects[i]);
        }
        starEffects->mEffects[i] = StartEffect(gKartStarEffectIds[i], &GetKart(kartIndex)->mPointAlongUp);
        i = i + 1;
    } while (i < 3);
}

static inline s32 func_0208181c_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void AdvanceKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;
    s16 y;
    s16 x;
    Kart *kart;
    Vec3 velocity;
    Vec3 effectPos;

    kart = GetKart(kartIndex);
    y = func_0208181c_inline(
        data_0216593c + func_0208181c_inline(kart->mVelocityLengthRatio, data_02165950 - data_0216593c), data_02165948);
    x = func_0208181c_inline(
        data_02165944 + func_0208181c_inline(kart->mVelocityLengthRatio, data_0216594c - data_02165944), data_02165948);
    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            VEC_MultAdd(((s64) kart->mScale.y * data_02155854[kart->mKartModelsEntry->mCharacterIndex] + 0x800) >> 12,
                        &kart->mUnk_12c, &kart->mPos, &effectPos);
            PlaceEffect(starEffects->mEffects[i], &effectPos);
            velocity.x = ((s64) kart->mEffectVelocity.x * 0xc00) >> 12;
            velocity.y = ((s64) kart->mEffectVelocity.y * 0xc00) >> 12;
            velocity.z = ((s64) kart->mEffectVelocity.z * 0xc00) >> 12;
            starEffects->mEffects[i]->mUnk_40 = velocity;
            starEffects->mEffects[i]->mUnk_68 = y;
            starEffects->mEffects[i]->mUnk_64 = x;
            starEffects->mEffects[i]->mUnk_5c = (s16) (((s64) kart->mScale.z * 0x614 + 0x800) >> 12);
        }
        i = i + 1;
    } while (i < 3);
}

void StopKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            starEffects->mEffects[i]->mUnk_24.mUnk_00_0 = 1;
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void ReleaseKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            DeleteEffect(starEffects->mEffects[i]);
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void StartKartKillerEffect(s32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];

    if (kartEffects->mKillerEffect != NULL) {
        DeleteEffect(kartEffects->mKillerEffect);
    }
    kartEffects->mKillerEffect = StartEffect(0x63, &data_02155a14);
}

// Moves the Killer effect to point b and gives it the kart's velocity.
void PlaceKartKillerEffect(s32 kartIndex, Vec3 *position) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect = kartEffects->mKillerEffect;
    Kart *kart;
    Vec3 *kartVelocity;
    Vec3 velocity;

    if (effect == NULL) {
        return;
    }
    effect->mUnk_28.x = position->x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = position->y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = position->z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    kart = GetKart(kartIndex);
    kartVelocity = &kart->mEffectVelocity;
    velocity.x = ((s64) kartVelocity->x * 0xe66) >> 12;
    velocity.y = ((s64) kartVelocity->y * 0xe66) >> 12;
    velocity.z = ((s64) kartVelocity->z * 0xe66) >> 12;
    kartEffects->mKillerEffect->mUnk_40 = velocity;
}
