#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02024000.h"

void StartMapObjectKindSound(MapObject *mapObject, SoundSource *soundSource, s32 d, s32 e) {
    s32 soundId;
    soundId = mapObject->mKindData->mUnk_24;
    if (soundId == -1) {
        return;
    }
    if (mapObject->mDistanceSquaredAndFlags & 0x40000000) {
        return;
    }
    if (mapObject->mSound != NULL) {
        func_02024a28(&mapObject->mSound->mSoundSource, soundId, e, d);
    } else {
        func_02024a28(soundSource, soundId, e, d);
    }
}

void StartSoundAtPositionIfNear(s32 soundId, Vec3 *position, s32 falloffKind) {
    s32 distanceSquared;
    Unk0210b7a8 request;
    distanceSquared = GetHorizontalCameraDistanceSquared(position);
    if (distanceSquared >= (falloffKind == 2 ? gSoundFalloffs[2].mUnk_20 : gSoundFalloffs[4].mUnk_20)) {
        return;
    }
    request.mSoundId = soundId;
    request.mPositionSource = position;
    request.mUnk_08 = falloffKind;
    request.mDistanceSquared = distanceSquared;
    func_0210b7a8(&request);
}

void SetMapObjectExtentY(MapObject *mapObject, s32 baseSize) {
    s32 radius;
    mapObject->mExtent.y = (s64) baseSize * mapObject->mScale.y >> 12;
    if (mapObject->mCollisionSlotIndex < 0) {
        return;
    }
    switch (mapObject->mKindData->mShapeKind) {
        case 3:
        case 4:
        case 5:
            radius = VEC_Mag(&mapObject->mExtent);
            break;
        case 0:
        case 1:
        case 2:
        default:
            radius = mapObject->mExtent.x;
            break;
    }
    SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, radius);
}

s32 GetMapObjectCollisionRadius(MapObject *mapObject) {
    switch (mapObject->mKindData->mShapeKind) {
        case 3:
        case 4:
        case 5:
            return VEC_Mag(&mapObject->mExtent);
        case 0:
        case 1:
        case 2:
        default:
            return mapObject->mExtent.x;
    }
}

void SetMapObjectDrawDistance(MapObject *mapObject, s32 drawDistance) {
    s32 maxDistance;
    mapObject->mDrawDistance = drawDistance;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        mapObject->mDrawDistance = 0x270f000;
        return;
    }
    maxDistance = gCourseMap->mSettings->mMapObjectDrawDistanceMax;
    if (maxDistance == 0) {
        return;
    }
    if (mapObject->mDrawDistance > maxDistance) {
        mapObject->mDrawDistance = maxDistance;
    }
}
