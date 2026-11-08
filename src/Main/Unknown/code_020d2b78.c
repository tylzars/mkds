#include "Main/Unknown/code_020d2b78.h"

#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d6000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d94dc.h"

#pragma thumb on

void func_020d2d94(void) {
    int index;
    MapObjectList **drawListSlot;
    void **listSlot;
    MapObjectList **updateListSlot;
    drawListSlot = gMapObjects->mDrawLists;
    updateListSlot = gMapObjects->mUpdateLists;
    index = 0;
    do {
        if (*drawListSlot != NULL) {
            listSlot = *(void ***) ((s32) *drawListSlot + 0x28);
            if (listSlot != NULL) {
                *listSlot = NULL;
            }
            *drawListSlot = NULL;
        }
        drawListSlot = drawListSlot + 1;
        index = index + 1;
    } while (index < 0x18);
    index = 0;
    do {
        if (*updateListSlot != NULL) {
            listSlot = (*updateListSlot)->mUnk_24;
            if (listSlot != NULL) {
                *listSlot = NULL;
            }
            *updateListSlot = NULL;
        }
        updateListSlot = updateListSlot + 1;
        index = index + 1;
    } while (index < 0x10);
}

#pragma thumb off

#pragma thumb on

s32 func_020d2c2c(Vec3 *position, Vec3 *velocity, s32 radius, s16 collisionSlotIndex, s32 itemKind, Vec3 *hitOffset) {
    s32 bestResponse;
    s32 i;
    bestResponse = 0;
    FindCollisionSlotsOverlappingSlot(collisionSlotIndex, 0x2000);
    i = 0;
    if (gFoundCollisionSlotCount != 0) {
        Vec3 overlapOffset;
        Vec3 lowest;
        Vec3 highest;
        ItemObject *itemObject;
        MapObject *mapObject;
        s32 response;
        s32 overlapX;
        {
            Vec3 zeroLow = {0, 0, 0};
            lowest = zeroLow;
        }
        {
            Vec3 zeroHigh = {0, 0, 0};
            highest = zeroHigh;
        }
        itemObject = &gMapObjects->mUnk_18c;
        for (; i < gFoundCollisionSlotCount; i++) {
            mapObject = gFoundCollisionSlotObjects[i];
            if (IsSphereHittingMapObject(position, radius, mapObject, &overlapOffset) != FALSE) {
                if (!(mapObject->mFlags & 0x40) && DoesItemObjectRespondToMapObject(itemKind, mapObject) != 0) {
                    overlapX = overlapOffset.x;
                    lowest.x = ((const Vec3 *) &overlapOffset)->x < lowest.x ? overlapX : lowest.x;
                    lowest.y = overlapOffset.y < lowest.y ? overlapOffset.y : lowest.y;
                    lowest.z = overlapOffset.z < lowest.z ? overlapOffset.z : lowest.z;
                    highest.x = overlapX > highest.x ? overlapX : highest.x;
                    highest.y = overlapOffset.y > highest.y ? overlapOffset.y : highest.y;
                    highest.z = overlapOffset.z > highest.z ? overlapOffset.z : highest.z;
                }
                itemObject->mPos = *position;
                itemObject->mVelocity = *velocity;
                itemObject->mKind = itemKind;
                response = func_020d6a54(itemObject, mapObject, NULL);
                if (response > bestResponse) {
                    bestResponse = response;
                }
            }
        }
        if (bestResponse != 0 && hitOffset != NULL) {
            hitOffset->x = highest.x + lowest.x;
            hitOffset->y = highest.y + lowest.y;
            if (hitOffset->y < 0) {
                hitOffset->y = 0;
            }
            hitOffset->z = highest.z + lowest.z;
        }
    }
    return bestResponse;
}

#pragma thumb off

#pragma thumb on

u32 GetMapObjectKindCount(void) {
    return (gMapObjectKindCount);
}

// The water_efct.nsbmd file: WaterEfct's if gCourseWaterEfct exists, else the Water's own when mUnk_170 is non-zero,
// else NULL; passed as an effect model file to SetupModelEffectKind.
void *GetWaterEfctNsbmdFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmdFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mUnk_170 != 0)) {
        return water->mEfctNsbmdFile;
    }
    return NULL;
}

// The water_efct.nsbca file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbcaFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbcaFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mUnk_170 != 0)) {
        return water->mEfctNsbcaFile;
    }
    return NULL;
}

// The water_efct.nsbma file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbmaFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmaFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mUnk_170 != 0)) {
        return water->mEfctNsbmaFile;
    }
    return NULL;
}

#pragma thumb off
