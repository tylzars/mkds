#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b33d8.h"

#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020d3d94.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50b4.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d4990.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50e0.h"

ViewFrustum *GetViewFrustum(void) {
    return &gViewFrustum;
}

void RequestViewTestRefresh(void) {
    gViewFrustum.mViewTestRefreshRequested = TRUE;
    gViewFrustum.mViewTestRefreshPending = FALSE;
}

u32 GetViewTestRefreshPending(void) {
    u32 value0;
    value0 = gViewFrustum.mViewTestRefreshPending;
    return value0;
}

void UpdateViewFrustum(Unk020d4f94 *viewMatrix) {
    s32 buf[10];

    MTX_Transpose33_(viewMatrix, buf);
    MTX_MultVec33(&viewMatrix->mUnk_24, buf, &gViewFrustum.mCameraPos);
    gViewFrustum.mCameraPos.x = -gViewFrustum.mCameraPos.x;
    gViewFrustum.mCameraPos.y = -gViewFrustum.mCameraPos.y;
    gViewFrustum.mCameraPos.z = -gViewFrustum.mCameraPos.z;
    gViewFrustum.mCameraPos.x = gViewFrustum.mCameraPos.x << 4;
    gViewFrustum.mCameraPos.y = gViewFrustum.mCameraPos.y << 4;
    gViewFrustum.mCameraPos.z = gViewFrustum.mCameraPos.z << 4;
    gViewFrustum.mViewDirection.x = -buf[6];
    gViewFrustum.mViewDirection.y = -buf[7];
    gViewFrustum.mViewDirection.z = -buf[8];
    MTX_MultVec33(&gViewFrustumBeforeRotation.mUnk_20, buf, &gViewFrustum.mUnk_20);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mUnk_2c, buf, &gViewFrustum.mUnk_2c);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mUnk_38, buf, &gViewFrustum.mUnk_38);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mUnk_44, buf, &gViewFrustum.mUnk_44);
    if (gViewFrustum.mViewTestRefreshRequested != FALSE) {
        gViewFrustum.mViewTestRefreshRequested = FALSE;
        gViewFrustum.mViewTestRefreshPending = TRUE;
    } else {
        gViewFrustum.mViewTestRefreshPending = FALSE;
    }
}

u32 func_020d4f34(Vec3 *position, s32 b, s32 c, s32 distanceLimitSquared) {
    s32 deltaX;
    s32 deltaZ;
    s32 distanceSquared;
    u32 result;

    deltaX = (position->x - gViewFrustum.mCameraPos.x) >> 12;
    deltaZ = (position->z - gViewFrustum.mCameraPos.z) >> 12;
    distanceSquared = deltaX * deltaX + deltaZ * deltaZ;
    result = distanceSquared & ~0xc000001f;
    if (distanceSquared > distanceLimitSquared) {
        result |= data_021568f4;
    }
    return result | 3;
}

s32 GetHorizontalCameraDistanceSquared(Vec3 *position) {
    s32 x;
    s32 z;

    if (position == NULL) {
        return 0;
    }
    x = (position->x - gViewFrustum.mCameraPos.x) >> 12;
    z = (position->z - gViewFrustum.mCameraPos.z) >> 12;
    return x * x + z * z;
}

void func_020d4e28(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags) {
    s32 cameraHeightAboveItem;

    if (distanceAndFlags & 4) {
        if (itemObject->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
        return;
    }
    cameraHeightAboveItem = gViewFrustum.mCameraPos.y - position->y;
    if (cameraHeightAboveItem > -0x12c000 && cameraHeightAboveItem < data_0217b4f4) {
        if (!(itemObject->mSoundSource.mSourceFlags & 1)) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
    } else {
        if (itemObject->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
    }
}

BOOL func_020d4ddc(MapObject *mapObject) {
    s32 cameraHeightAboveObject;

    if (mapObject->mDistanceSquaredAndFlags & 4) {
        return TRUE;
    }
    cameraHeightAboveObject = gViewFrustum.mCameraPos.y - mapObject->mPos.y;
    if (mapObject->mKindData->mUnk_3c < cameraHeightAboveObject &&
        cameraHeightAboveObject < mapObject->mKindData->mUnk_38) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_020d4d60(MapObject *mapObject, s32 distanceSquared) {
    s32 heightAboveCamera;
    Vec3 *position;
    MapObjectKindData *kindData;

    position = &mapObject->mPos;
    if (distanceSquared > mapObject->mFarDistanceSquared) {
        return TRUE;
    }
    kindData = mapObject->mKindData;
    heightAboveCamera = (position->y - gViewFrustum.mCameraPos.y) >> 12;
    if (heightAboveCamera < kindData->mUnk_3c || kindData->mUnk_38 < heightAboveCamera) {
        return TRUE;
    }
    return (GetKartKind3ShapeMask() & mapObject->mDigitMask) != 0;
}

void func_020d4d44(MtxFx43 *viewMatrix) {
    SetViewMatrices(viewMatrix);
    SetViewYawQuaternion(viewMatrix);
}

void DrawMapObjectList(MapObjectList *list, MtxFx43 *viewMatrix) {
    s32 i;
    MapObject *mapObject;
    UnkFunc *forEachObject;
    s32 objectCount;
    void **objects;
    MapObject *lastObject;
    s32 lastIndex;

    forEachObject = list->mForEachObject;
    objectCount = list->mMapObjectCount;
    objects = list->mUnk_24;
    if (forEachObject == NULL) {
        return;
    }
    if (list->mUnk_1c != NULL) {
        lastObject = NULL;
        for (i = 0; i < objectCount; i++) {
            mapObject = objects[i];
            if (!(mapObject->mFlags & 0x12) && mapObject->mAlpha != 0) {
                forEachObject(list, mapObject, viewMatrix, mapObject->mAlpha);
                if (lastObject != NULL && (s32) (mapObject->mDistanceSquaredAndFlags & ~0xc000001f) >
                                              (s32) (lastObject->mDistanceSquaredAndFlags & ~0xc000001f)) {
                    objects[lastIndex] = mapObject;
                    objects[i] = lastObject;
                } else {
                    lastObject = mapObject;
                }
                lastIndex = i;
            }
        }
    } else {
        for (i = 0; i < objectCount; i++) {
            mapObject = objects[i];
            if (!(mapObject->mFlags & 0x12) && mapObject->mAlpha != 0) {
                forEachObject(list, mapObject, viewMatrix, mapObject->mAlpha);
            }
        }
    }
}

#pragma thumb on

void func_020d4bf0(void) {
    gViewFrustum.mViewTestRefreshRequested = TRUE;
    gViewFrustum.mViewTestRefreshPending = FALSE;
    if (gRaceSetup->mRaceKind == 2) {
        data_0217b4f4 = 0x258000;
        return;
    }
    data_0217b4f4 = 0x12c000;
}

#pragma thumb off

#pragma thumb on
void RefreshViewFrustumFromProjection(s32 a, s32 b, s32 c, s32 d, s32 nearDistance, s32 farDistance) {
    gViewFrustumBeforeRotation.mNear = nearDistance << 4;
    gViewFrustum.mNear = nearDistance << 4;
    gViewFrustumBeforeRotation.mFar = farDistance << 4;
    gViewFrustum.mFar = farDistance << 4;

    gViewFrustumBeforeRotation.mUnk_20.x = nearDistance;
    gViewFrustumBeforeRotation.mUnk_20.y = 0;
    gViewFrustumBeforeRotation.mUnk_20.z = -c;
    if ((s64) gViewFrustumBeforeRotation.mUnk_20.z * gViewFrustumBeforeRotation.mUnk_20.z +
            ((s64) gViewFrustumBeforeRotation.mUnk_20.x * gViewFrustumBeforeRotation.mUnk_20.x +
             (s64) gViewFrustumBeforeRotation.mUnk_20.y * gViewFrustumBeforeRotation.mUnk_20.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mUnk_20, &gViewFrustumBeforeRotation.mUnk_20);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        gViewFrustumBeforeRotation.mUnk_20.x = -gViewFrustumBeforeRotation.mUnk_20.x;
        gViewFrustumBeforeRotation.mUnk_20.y = -gViewFrustumBeforeRotation.mUnk_20.y;
        gViewFrustumBeforeRotation.mUnk_20.z = -gViewFrustumBeforeRotation.mUnk_20.z;
    }

    gViewFrustumBeforeRotation.mUnk_2c.x = -nearDistance;
    gViewFrustumBeforeRotation.mUnk_2c.y = 0;
    gViewFrustumBeforeRotation.mUnk_2c.z = d;
    if ((s64) gViewFrustumBeforeRotation.mUnk_2c.z * gViewFrustumBeforeRotation.mUnk_2c.z +
            ((s64) gViewFrustumBeforeRotation.mUnk_2c.x * gViewFrustumBeforeRotation.mUnk_2c.x +
             (s64) gViewFrustumBeforeRotation.mUnk_2c.y * gViewFrustumBeforeRotation.mUnk_2c.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mUnk_2c, &gViewFrustumBeforeRotation.mUnk_2c);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        gViewFrustumBeforeRotation.mUnk_2c.x = -gViewFrustumBeforeRotation.mUnk_2c.x;
        gViewFrustumBeforeRotation.mUnk_2c.y = -gViewFrustumBeforeRotation.mUnk_2c.y;
        gViewFrustumBeforeRotation.mUnk_2c.z = -gViewFrustumBeforeRotation.mUnk_2c.z;
    }

    gViewFrustumBeforeRotation.mUnk_38.x = 0;
    gViewFrustumBeforeRotation.mUnk_38.y = -nearDistance;
    gViewFrustumBeforeRotation.mUnk_38.z = a;
    if ((s64) gViewFrustumBeforeRotation.mUnk_38.z * gViewFrustumBeforeRotation.mUnk_38.z +
            ((s64) gViewFrustumBeforeRotation.mUnk_38.x * gViewFrustumBeforeRotation.mUnk_38.x +
             (s64) gViewFrustumBeforeRotation.mUnk_38.y * gViewFrustumBeforeRotation.mUnk_38.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mUnk_38, &gViewFrustumBeforeRotation.mUnk_38);
    }

    gViewFrustumBeforeRotation.mUnk_44.x = 0;
    gViewFrustumBeforeRotation.mUnk_44.y = nearDistance;
    gViewFrustumBeforeRotation.mUnk_44.z = -b;
    if ((s64) gViewFrustumBeforeRotation.mUnk_44.z * gViewFrustumBeforeRotation.mUnk_44.z +
            ((s64) gViewFrustumBeforeRotation.mUnk_44.x * gViewFrustumBeforeRotation.mUnk_44.x +
             (s64) gViewFrustumBeforeRotation.mUnk_44.y * gViewFrustumBeforeRotation.mUnk_44.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mUnk_44, &gViewFrustumBeforeRotation.mUnk_44);
    }
}
#pragma thumb off

#pragma thumb on
void ClearMapObjectList(MapObjectList *list) {
    list->mMapObjects = NULL;
    list->mMapObjectCount = 0;
}
#pragma thumb off

#pragma thumb on
void func_020d4a10(MapObjectList *list, s32 count) {
    list->mMapObjectCount += count;
}
#pragma thumb off

#pragma thumb on
u32 InitMapObjectDrawList(MapObjectList *list) {
    list->mMapObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mMapObjectCount << 2);
    list->mMapObjectCount = 0;
    return 0;
}
#pragma thumb off

#pragma thumb on
u32 AddMapObjectToDrawList(MapObjectList *list, MapObject *mapObject) {
    u32 index = list->mMapObjectCount;
    list->mMapObjectCount = index + 1;
    list->mMapObjects[index] = mapObject;
    return index << 2;
}
#pragma thumb off

#pragma thumb on

void func_020d49d8(void *listSlot) {
    *(u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) listSlot + 0))) + 40) = (u32) listSlot;
}

#pragma thumb off

#pragma thumb on
void func_020d4990(MapObjectList *list) {
    s32 i;

    if (list->mUnk_1c != NULL) {
        list->mUnk_24 = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mMapObjectCount * 4);
        for (i = 0; i < list->mMapObjectCount; i++) {
            list->mUnk_24[i] = list->mMapObjects[i];
        }
    } else {
        list->mUnk_24 = list->mMapObjects;
    }
}
#pragma thumb off

void SetCourseWater(Water *water) {
    gCourseWater = water;
}

void SetCourseWaterEfct(void *waterEfct) {
    gCourseWaterEfct = waterEfct;
}

void UpdateMapObjectViewTests(void) {
    u32 shapeMask;
    s32 i;
    s32 n;
    MapObject *mapObject;
    MapObject **mapObjects;
    u32 frameSlot;
    u16 extraFlags;
    u32 extraViewFlags;

    n = gMapObjects->mMapObjectCount;
    mapObjects = gMapObjects->mMapObjects;
    shapeMask = GetKartKind3ShapeMask();
    frameSlot = GetRaceUpdateFrames() & 3;
    i = 0;
    if (n <= 0) {
        return;
    }
    extraFlags = data_021568ec;
    extraViewFlags = data_021568f0;
    do {
        mapObject = mapObjects[i];
        mapObject->mDistanceSquaredAndFlags &= ~8;
        if (!(mapObject->mFlags & 2)) {
            if (mapObject->mDistanceSquaredAndFlags & 1) {
                if (mapObject->mAlpha != 0) {
                    mapObject->mAlpha -= 1;
                }
            } else {
                if (mapObject->mAlpha < 0x1f) {
                    mapObject->mAlpha += 1;
                }
            }
            if ((i & 3) == frameSlot) {
                if (mapObject->mDigitMask & shapeMask) {
                    mapObject->mDistanceSquaredAndFlags = (mapObject->mDistanceSquaredAndFlags & 0x10) | 0x5f592e7;
                    mapObject->mFlags |= extraFlags;
                } else {
                    if (mapObject->mUseTwoPlaneViewTest != 0) {
                        mapObject->mDistanceSquaredAndFlags =
                            (mapObject->mDistanceSquaredAndFlags & 0x10) |
                            ComputeTwoPlaneViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                                    mapObject->mFarDistanceSquared, mapObject->mAlpha);
                    } else {
                        mapObject->mDistanceSquaredAndFlags =
                            (mapObject->mDistanceSquaredAndFlags & 0x10) |
                            ComputeViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                            mapObject->mFarDistanceSquared, mapObject->mAlpha);
                    }
                    mapObject->mDistanceSquaredAndFlags |= extraViewFlags;
                    if (mapObject->mDistanceSquaredAndFlags & 2) {
                        mapObject->mFlags |= extraFlags;
                    } else {
                        mapObject->mFlags &= ~0x10;
                    }
                }
            }
        }
    } while (++i < n);
}

void RefreshMapObjectViewTests(void) {
    u32 shapeMask;
    s32 i;
    s32 n;
    MapObject *mapObject;
    MapObject **mapObjects;
    u16 extraFlags;
    u32 extraViewFlags;

    shapeMask = GetKartKind3ShapeMask();
    i = 0;
    n = gMapObjects->mMapObjectCount;
    mapObjects = gMapObjects->mMapObjects;
    if (n <= 0) {
        return;
    }
    extraFlags = data_021568ec;
    extraViewFlags = data_021568f0;
    do {
        mapObject = mapObjects[i];
        mapObject->mDistanceSquaredAndFlags &= ~8;
        if (!(mapObject->mFlags & 2)) {
            if (mapObject->mDigitMask & shapeMask) {
                mapObject->mFlags |= extraFlags;
            } else {
                if (mapObject->mUseTwoPlaneViewTest != 0) {
                    mapObject->mDistanceSquaredAndFlags =
                        (mapObject->mDistanceSquaredAndFlags & 0x10) |
                        ComputeTwoPlaneViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                                mapObject->mFarDistanceSquared, mapObject->mAlpha);
                } else {
                    mapObject->mDistanceSquaredAndFlags =
                        (mapObject->mDistanceSquaredAndFlags & 0x10) |
                        ComputeViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                        mapObject->mFarDistanceSquared, mapObject->mAlpha);
                }
                mapObject->mDistanceSquaredAndFlags |= extraViewFlags;
                if (mapObject->mDistanceSquaredAndFlags & 1) {
                    mapObject->mAlpha = 0;
                } else {
                    mapObject->mAlpha = 0x1f;
                }
                if (mapObject->mDistanceSquaredAndFlags & 2) {
                    mapObject->mFlags |= extraFlags;
                } else {
                    mapObject->mFlags &= ~0x10;
                }
            }
        }
    } while (++i < n);
}

void UpdateMapObjects(void) {
    MapObjectList *list;
    s32 i;
    s32 n;
    MapObjectList **lists;
    s32 startFrames;

    lists = gMapObjects->mUpdateLists;
    n = gMapObjects->mUpdateListCount;
    startFrames = GetRaceStartSequenceFrames();
    if (startFrames <= 0x168) {
        if (gRaceSetup->mRaceKind != RACE_KIND_START_GP) {
            if (startFrames == -0x73) {
                func_020d3b74();
            } else if (startFrames == 0x168) {
                func_020d3b10();
            }
        }
    }
    if (gMapObjects->mRunUpdateLists != 0) {
        for (i = 0; i < n; i++) {
            list = lists[i];
            if (list->mBeforeObjects != NULL) {
                list->mBeforeObjects(list);
            }
            UpdateMapObjectList(list);
            if (list->mAfterObjects != NULL) {
                list->mAfterObjects(list);
            }
        }
    }
    if (GetViewTestRefreshPending() != 0) {
        RefreshMapObjectViewTests();
    } else {
        UpdateMapObjectViewTests();
    }
    if (gCourseWater != NULL) {
        UpdateWater(gCourseWater);
    }
}

void DrawMapObjects(Unk020d4418 *view) {
    s32 i;
    s32 firstPassCount;
    MapObjectList **lists;
    MapObjectList *list;
    MtxFx43 *viewMatrix;
    s32 secondPassCount;
    s32 j;

    viewMatrix = &view->mUnk_30;
    func_020d4d44(viewMatrix);
    if (gCourseWater != NULL) {
        DrawWater(gCourseWater, viewMatrix);
    }
    i = 0;
    firstPassCount = gMapObjects->mUnk_12a;
    lists = gMapObjects->mUnk_068;
    for (; i < firstPassCount; i++) {
        list = lists[i];
        func_0208ab00();
        if (list->mBeforeObjects != NULL) {
            list->mBeforeObjects(list);
        }
        DrawMapObjectList(list, viewMatrix);
        if (list->mAfterObjects != NULL) {
            list->mAfterObjects(list);
        }
    }
    func_020e6a74();
    j = 0;
    secondPassCount = gMapObjects->mUnk_12c;
    lists = gMapObjects->mUnk_0c8;
    for (; j < secondPassCount; j++) {
        list = lists[j];
        if (list->mBeforeObjects != NULL) {
            list->mBeforeObjects(list);
        }
        DrawMapObjectList(list, viewMatrix);
        if (list->mAfterObjects != NULL) {
            list->mAfterObjects(list);
        }
    }
}

void func_020d4418(Unk020d4418 *view) {
    MtxFx43 *viewMatrix;

    viewMatrix = &view->mUnk_30;
    if (gMapObjects->mHasKoopaBlock != 0) {
        DrawAllKoopaBlocks(viewMatrix);
    }
    if (gMapObjects->mUnk_180 != 0) {
        func_020e435c(viewMatrix);
    }
    if (gMapObjects->mUnk_184 != 0) {
        DrawAllBridges(viewMatrix);
    }
}

s32 FindMapObjectsTouchingKart(Kart *kart, Vec3 *position, Vec3 *hitOffset) {
    Vec3 centre;
    Vec3 lo;
    Vec3 hi;
    s32 radius;
    BOOL kartFlagSet;
    s32 itemEffect;
    s32 i;
    MapObject *mapObject;
    s32 foundCount;
    Vec3 *foundVector;

    centre = *position;
    kartFlagSet = (kart->mUnk_48 & 0x8000000) != 0;
    radius = kart->mRadius;
    itemEffect = kart->mItemEffect;
    foundVector = gFoundMapObjectVectors;
    {
        Vec3 z1 = {0, 0, 0};
        lo = z1;
    }
    {
        Vec3 z2 = {0, 0, 0};
        hi = z2;
    }
    foundCount = 0;
    hitOffset->x = hitOffset->y = hitOffset->z = 0;
    for (i = 0; i < gFoundCollisionSlotCount; i++) {
        if (gFoundCollisionSlotFlags[i] & 0x2000) {
            mapObject = gFoundCollisionSlotObjects[i];
            if (kartFlagSet != FALSE && !(mapObject->mDistanceSquaredAndFlags & 0x10)) {
                continue;
            }
            if (IsSphereHittingMapObject(&centre, radius, mapObject, foundVector) != FALSE) {
                if (!(mapObject->mFlags & 0x40) && DoesKartRespondToMapObject(itemEffect, mapObject) != 0) {
                    lo.x = (foundVector->x < lo.x) ? foundVector->x : lo.x;
                    lo.y = (foundVector->y < lo.y) ? foundVector->y : lo.y;
                    lo.z = (foundVector->z < lo.z) ? foundVector->z : lo.z;
                    hi.x = (foundVector->x > hi.x) ? foundVector->x : hi.x;
                    hi.y = (foundVector->y > hi.y) ? foundVector->y : hi.y;
                    hi.z = (foundVector->z > hi.z) ? foundVector->z : hi.z;
                }
                gFoundMapObjects[foundCount] = mapObject;
                foundCount++;
                foundVector = &gFoundMapObjectVectors[foundCount];
                if (foundCount >= 0x20) {
                    foundCount = 0x1f;
                }
            }
        }
    }
    if (foundCount != 0 && hitOffset != NULL) {
        hitOffset->x = hi.x + lo.x;
        hitOffset->y = hi.y + lo.y;
        if (hitOffset->y < 0) {
            hitOffset->y = 0;
        }
        hitOffset->z = hi.z + lo.z;
    }
    return foundCount;
}

s32 FindMapObjectsOfKindInRadius(Vec3 *position, s32 radius, s32 kind) {
    s32 foundCount;
    MapObject *mapObject;
    s32 deltaZ;
    s32 deltaX;
    s32 i;

    foundCount = 0;
    FindCollisionSlotsAroundPos(position, radius, 0x2000);
    for (i = 0; i < gFoundCollisionSlotCount; i++) {
        mapObject = gFoundCollisionSlotObjects[i];
        if (mapObject->mKind == kind) {
            deltaX = position->x - mapObject->mPos.x;
            deltaZ = position->z - mapObject->mPos.z;
            if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) radius * radius) {
                gFoundMapObjects[foundCount] = mapObject;
                foundCount++;
            }
        }
    }
    return foundCount;
}

// Returns the i-th map object stored by the last FindMapObjectsTouchingKart or FindMapObjectsOfKindInRadius call; i
// must be below the count that call returned.
MapObject *GetFoundMapObject(u32 index) {
    return gFoundMapObjects[index];
}

Vec3 *GetFoundMapObjectVector(int index) {
    return gFoundMapObjectVectors + index;
}

BOOL IsSphereHittingMapObject(Vec3 *position, s32 radius, MapObject *mapObject, Vec3 *overlapOffset) {
    s32 combinedRadius;
    s32 combinedHeight;
    s32 dx;
    s32 dy;
    s32 dz;
    BOOL isHit;
    s32 negatedRadius;
    if (mapObject->mFlags & 1) {
        return FALSE;
    }
    switch (mapObject->mKindData->mShapeKind) {
        case 1:
            combinedRadius = radius + mapObject->mExtent.x;
            negatedRadius = -combinedRadius;
            dz = position->z - mapObject->mPos.z;
            if (dz > combinedRadius || dz < negatedRadius) {
                isHit = FALSE;
            } else {
                dx = position->x - mapObject->mPos.x;
                if (dx > combinedRadius || dx < negatedRadius) {
                    isHit = FALSE;
                } else {
                    dy = position->y - mapObject->mPos.y;
                    if (dy > combinedRadius || dy < negatedRadius) {
                        isHit = FALSE;
                    } else {
                        isHit = (s64) dx * dx + (s64) dy * dy + (s64) dz * dz < (s64) combinedRadius * combinedRadius;
                    }
                }
            }
            if (isHit == FALSE) {
                return FALSE;
            }
            ComputeSphereOverlapOffset(position, &mapObject->mPos, combinedRadius, overlapOffset);
            return TRUE;
        case 2:
            combinedRadius = radius + mapObject->mExtent.x;
            combinedHeight = radius + mapObject->mExtent.y;
            negatedRadius = -combinedRadius;
            dz = position->z - mapObject->mPos.z;
            if (dz > combinedRadius || dz < negatedRadius) {
                isHit = FALSE;
            } else {
                dx = position->x - mapObject->mPos.x;
                if (dx > combinedRadius || dx < negatedRadius) {
                    isHit = FALSE;
                } else {
                    dy = position->y - mapObject->mPos.y;
                    if (dy > combinedHeight || dy < -combinedHeight) {
                        isHit = FALSE;
                    } else {
                        isHit = (s64) dx * dx + (s64) dz * dz < (s64) combinedRadius * combinedRadius;
                    }
                }
            }
            if (isHit == FALSE) {
                return FALSE;
            }
            ComputeCylinderOverlapOffset(position, &mapObject->mPos, combinedRadius, combinedHeight, overlapOffset);
            return TRUE;
        case 3:
            return ComputeSphereHitOnRotatedCylinder(position, &mapObject->mPos, &mapObject->mMatrix.mUnk_00[0],
                                                     mapObject->mExtent.x, mapObject->mExtent.y, mapObject->mExtent.y,
                                                     radius, overlapOffset) != 0;
        case 4:
            return ComputeSphereHitOnRotatedBox(position, &mapObject->mPos, &mapObject->mMatrix.mUnk_00[0],
                                                &mapObject->mExtent, &mapObject->mExtent, radius, overlapOffset) != 0;
        case 0:
            return FALSE;
        case 5:
            if (mapObject->mKindData->mSphereHitTest != NULL) {
                return mapObject->mKindData->mSphereHitTest(mapObject, position, radius, overlapOffset) != 0;
            }
            return FALSE;
        default:
            return FALSE;
    }
}

// TRUE when the course has a water object (gCourseWater is not NULL); asked by the camera and the HUD gauge.
BOOL IsWaterPresent(void) {
    return gCourseWater != NULL;
}

// y minus mHeight of gCourseWater (negative below the water), 9999.0 (fx32) when the course has no water; asked by the
// camera; it does not look at mUnk_170 or WaterEfct.
s32 GetHeightAboveWater(s32 y) {
    return gCourseWater != NULL ? y - gCourseWater->mHeight : 0x270f000;
}

// mHeightFactor of gCourseWater, 0 when the course has no water; asked by the HUD gauge.
s32 GetWaterHeightFactor(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightFactor : 0;
}

// mHeightAngle of gCourseWater, 0 when the course has no water; the HUD gauge tests 0x4000 <= angle < 0xc000 (the
// falling half).
u32 GetWaterHeightAngle(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightAngle : 0;
}

u32 func_020d3d94(void) {
    u32 result = 0;
    if (gCourseWater == NULL) {
        return result;
    }
    if (gCourseWater->mUnk_170 != 0) {
        result = 1;
    }
    return result;
}

// Y minus mHeight when the Water exists and mUnk_170 is non-zero (mini stage 3, beach), else y minus WaterEfct.mHeight,
// else 9999.0 (fx32); Or = the second source when the first is not used; asked by the kart steps, the kart sound and the
// overlay-1 objects.
s32 GetHeightAboveWaterOrEfct(s32 y) {
    if (gCourseWater != NULL && gCourseWater->mUnk_170 != 0) {
        return y - gCourseWater->mHeight;
    }
    return gCourseWaterEfct != NULL ? y - gCourseWaterEfct->mHeight : 0x270f000;
}

s32 func_020d3d10(s32 y) {
    BOOL isFarBelow;
    isFarBelow = FALSE;
    if (gCourseWaterEfct != NULL) {
        if (y - gCourseWaterEfct->mHeight < -0x32000) {
            isFarBelow = TRUE;
        }
    }
    return isFarBelow;
}

void func_020d3cc8(void) {
    s32 i;
    s32 n;
    MapObjects *mapObjects;
    MapObjectList **lists;
    i = 0;
    mapObjects = gMapObjects;
    n = mapObjects->mUpdateListCount;
    lists = mapObjects->mUpdateLists;
    for (; i < n; i++) {
        func_020e6fd4(lists[i]);
    }
}

s32 func_020d3c94(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset) {
    return func_020d2c2c(&mapObject->mPos, &mapObject->mUnk_10, mapObject->mExtent.x, mapObject->mCollisionSlotIndex,
                         itemKind, hitOffset);
}

void SetMapObjectsRunUpdateLists(void) {
    gMapObjects->mRunUpdateLists = 1;
}

u16 AllocPolygonIdWrapping(void) {
    gWrappingPolygonId++;
    if (gWrappingPolygonId > 0x3e) {
        gWrappingPolygonId = gWrappingPolygonIdBase;
    }
    return gWrappingPolygonId;
}

u16 AllocPolygonId(void) {
    return gNextPolygonId++;
}

#pragma thumb on

u16 CountMapObjectsOfKind(u32 kind) {
    s32 i;
    u16 count;
    count = 0;
    i = 0;
    for (; i < gMapObjects->mMapObjectCount; i++) {
        if (kind == gMapObjects->mMapObjects[i]->mKind) {
            count++;
        }
    }
    return count;
}

void func_020d3b74(void) {
    s32 i;
    s32 mapObjectCount;
    MapObject **mapObjectSlot;
    MapObject *mapObject;
    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjectSlot = gMapObjects->mMapObjects;
    for (i = 0; i < mapObjectCount; i++) {
        mapObject = *mapObjectSlot;
        if (mapObject->mFlags & 0x80) {
            if (mapObject->mFlags & 0x100) {
                mapObject->mFlags &= ~0x80;
            } else {
                mapObject->mFlags &= ~0xf000;
                mapObject->mFlags |= (mapObject->mFlags & 0xf) << 12;
                mapObject->mFlags |= data_021568dc;
                if (mapObject->mCollisionSlotIndex != -1) {
                    DisableCollisionSlot(mapObject->mCollisionSlotIndex);
                }
            }
        }
        mapObjectSlot++;
    }
}

void func_020d3b10(void) {
    s32 i;
    s32 mapObjectCount;
    MapObject **mapObjectSlot;
    MapObject *mapObject;
    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjectSlot = gMapObjects->mMapObjects;
    for (i = 0; i < mapObjectCount; i++) {
        mapObject = *mapObjectSlot;
        if (mapObject->mFlags & 0x80) {
            mapObject->mFlags &= ~0x80;
            mapObject->mFlags &= ~0xf;
            mapObject->mFlags |= (mapObject->mFlags & 0xf000) >> 12;
            if (mapObject->mCollisionSlotIndex != -1) {
                EnableCollisionSlot(mapObject->mCollisionSlotIndex);
            }
        }
        mapObjectSlot++;
    }
}

#pragma thumb off

#pragma thumb on

// Stores the mask of the nonzero decimal digits of a (bit d for digit d) in mUnk_74; a of 10000 or more first sets flag
// 0x80 in mFlags and loses the 10000.
void SetMapObjectMaskAndFlagFromNumber(s32 number, MapObject *mapObject) {
    int limit;
    u32 digitMask;
    limit = 0x2710;
    if (0x2710 <= number) {
        mapObject->mFlags = mapObject->mFlags | data_021568e8;
        number = (number - limit) * 0x10000 >> 0x10;
    }
    digitMask = DecimalNonZeroDigitsToBitMask(number);
    mapObject->mDigitMask = digitMask;
}

#pragma thumb off
