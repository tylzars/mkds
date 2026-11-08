#include "01/code_02188484.h"
#include "01/code_02188950.h"

void SetShadowOffsetYAndScale(Unk02188950 *mapObject, s32 offsetY, s32 scaleXZ) {
    if (offsetY == 0) {
        mapObject->mUnk_27c = 1;
    } else {
        mapObject->mUnk_27c = 2;
    }
    mapObject->mShadowOffsetX = mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetY = mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetZ = mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = 0;
    mapObject->mShadowScaleX = mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleY = mapObject->mShadowScaleTargetY = 0xa000;
    mapObject->mShadowScaleZ = mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetYAndScaleTarget(Unk02188950 *mapObject, int offsetY, u32 offsetPerCall, u32 scaleXZ,
                                    u32 scalePerCall) {
    if (offsetY == 0) {
        mapObject->mUnk_27c = 1;
    } else {
        mapObject->mUnk_27c = 2;
    }
    mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionOffsetAndExtent(Unk02188950 *mapObject, s32 offsetY, s32 extentXZ, s32 extentY) {
    if (extentY == 0) {
        mapObject->mCollisionShape = 0;
    } else {
        mapObject->mCollisionShape = 2;
    }
    mapObject->mOffset.x = mapObject->mOffsetTargetX = 0;
    mapObject->mOffset.y = mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffset.z = mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = 0;
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtent.y = mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtent.z = mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + mapObject->mOffset.x;
    mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + mapObject->mOffset.y;
    mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + mapObject->mOffset.z;
}

void SetCollisionOffsetAndExtentTarget(Unk02188950 *mapObject, u32 offsetY, u32 offsetPerCall, u32 extentXZ,
                                       int extentY, u32 extentPerCall) {
    if (extentY == 0) {
        mapObject->mCollisionShape = 0;
    } else {
        mapObject->mCollisionShape = 2;
    }
    mapObject->mOffsetTargetX = 0;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}

void SetShadowOffsetAndScale(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 scaleX, u32 f,
                             u32 scaleZ) {
    int *v1;
    int *v2;
    mapObject->mUnk_27c = 0;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    v2 = &mapObject->mShadowOffsetTargetX;
    *v2 = offsetX;
    mapObject->mShadowOffsetX = *v2;
    v1 = &mapObject->mShadowOffsetTargetY;
    *v1 = offsetY;
    mapObject->mShadowOffsetY = *v1;
    v1 = &mapObject->mShadowOffsetTargetZ;
    *v1 = offsetZ;
    mapObject->mShadowOffsetZ = *v1;
    mapObject->mShadowOffsetPerCall = 0;
    v1 = &mapObject->mShadowScaleTargetX;
    *v1 = scaleX;
    mapObject->mShadowScaleX = *v1;
    v1 = &mapObject->mShadowScaleTargetY;
    *v1 = (0x0000a000u);
    mapObject->mShadowScaleY = *v1;
    v1 = &mapObject->mShadowScaleTargetZ;
    *v1 = scaleZ;
    mapObject->mShadowScaleZ = *v1;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetAndScaleTarget(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 offsetPerCall,
                                   u32 scaleX, u32 g, u32 scaleZ, u32 scalePerCall) {
    mapObject->mUnk_27c = 0;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mShadowOffsetTargetX = offsetX;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = offsetZ;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleX;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionBoxOffsetAndExtent(Unk02188950 *mapObject, int offsetX, int offsetY, int offsetZ, u32 extentX,
                                    u32 extentY, u32 extentZ) {
    int *v1;
    int *v2;
    int *v3;
    int *v4;
    int *v5;
    mapObject->mCollisionShape = 1;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    v2 = &mapObject->mOffsetTargetX;
    *v2 = offsetX;
    v1 = &mapObject->mOffset.x;
    *v1 = *v2;
    v3 = &mapObject->mOffsetTargetY;
    *v3 = offsetY;
    v2 = &mapObject->mOffset.y;
    *v2 = *v3;
    v4 = &mapObject->mOffsetTargetZ;
    *v4 = offsetZ;
    v3 = &mapObject->mOffset.z;
    *v3 = *v4;
    mapObject->mOffsetPerCall = 0;
    v5 = &mapObject->mCollisionExtentTargetX;
    *v5 = extentX;
    mapObject->mCollisionExtent.x = *v5;
    v5 = &mapObject->mCollisionExtentTargetY;
    *v5 = extentY;
    mapObject->mCollisionExtent.y = *v5;
    v5 = &mapObject->mCollisionExtentTargetZ;
    *v5 = extentZ;
    mapObject->mCollisionExtent.z = *v5;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + *v1;
    mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + *v2;
    mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + *v3;
}

void SetCollisionBoxOffsetAndExtentTarget(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                          u32 offsetPerCall, u32 extentX, u32 extentY, u32 extentZ, u32 extentPerCall) {
    mapObject->mCollisionShape = 1;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mOffsetTargetX = offsetX;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = offsetZ;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentX;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}
