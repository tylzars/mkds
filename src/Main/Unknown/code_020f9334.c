#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

BOOL func_020f9c08(ItemObject *item) {
    if (item->mAgeFrames > 0x12c && (item->mFlags & 0x8000) != 0 &&
        item->mAdvance == (void (*)(ItemObject *)) AdvanceRestingItemObject) {
        return TRUE;
    }
    return FALSE;
}

void func_020f9ba8(ItemObject *item) {
    if (item->mAgeFrames <= 0x12c) {
        return;
    }
    if ((item->mFlags & 0x8000) == 0) {
        return;
    }
    if (item->mAdvance != (void (*)(ItemObject *)) AdvanceRestingItemObject) {
        return;
    }
    func_020f7658(item, 1);
}

void func_020f9b0c(ItemObject *item) {
    if ((item->mFlags & 0x8000) != 0) {
        func_020f7658(item, 1);
        return;
    }
    item->mVelocity.x = ((s64) item->mVelocity.x * 0x99a) >> 12;
    item->mVelocity.y = ((s64) item->mVelocity.y * 0x99a) >> 12;
    item->mVelocity.z = ((s64) item->mVelocity.z * 0x99a) >> 12;
    func_020f6fc4(item, 1);
}

void ResetItemObject(ItemObject *item, s32 kind) {
    void (*reset)(void *);

    reset = gItemKinds[kind].mReset;
    item->mKind = kind;
    item->mFlags = 0;
    item->mUnk_7a = 0;
    item->mScale.x = 0;
    item->mScale.y = 0;
    item->mScale.z = 0;
    item->mUnk_100 = 0;
    item->mUnk_dc = 0x7b;
    item->mRadius = 0x7b;
    item->mAlpha = 0x1f;
    item->mCollisionBits = 0;
    item->mUnk_118 = 0;
    item->mUnk_114 = 5;
    item->mBounce = NULL;
    item->mUnk_d0 = &item->mPos;
    item->mCollisionSlotIndex = -1;
    item->mUnk_104->mUnk_00 = NULL;
    if (gRaceSetup->mMode == 5) {
        item->mFlags |= 0x8000000;
    }
    item->mUnk_78 |= data_02159cac;
    InitCourseColorBlend(item->mColorBlend.mUnk_00, 1);
    item->mUnk_90 = NULL;
    if (reset != NULL) {
        reset(item);
    }
    item->mUnk_128 = 0;
}

void ResetItemObjectAtPos(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos) {
    item->mPos = *pos;
    item->mUnk_78 = ownerAndFlags;
    ResetItemObject(item, kind);
    if ((item->mFlags & 0x8000000) == 0) {
        return;
    }
    item->mId = ComputeItemObjectId(item);
}

void ReleaseItemObject(ItemObject *item) {
    enum { K0 } kind;

    if (item->mCollisionSlotIndex != -1) {
        item->mCollisionSlotIndex = FreeCollisionSlot(item->mCollisionSlotIndex);
    }
    if ((item->mFlags & 0x400000) != 0) {
        func_02109054(&item->mSoundSource);
        item->mSoundSource.mTrackParamsFunction = NULL;
        item->mFlags &= ~0x400000;
    }
    item->mFlags |= 4;
    kind = item->mKind;
    if (gItemKinds[kind].mRelease != NULL) {
        gItemKinds[kind].mRelease(item);
    }
}

void func_020f98a0(ItemObject *itemParam, Vec3 *prevPos, Vec3 *normal, u16 *colorBlend, s32 param_5) {
    ItemObject *item = itemParam;
    item->mPrevPos = *prevPos;
    if (colorBlend != NULL) {
        item->mColorBlend = *(Unk020f41c4_C *) colorBlend;
    } else {
        InitCourseColorBlend(item->mColorBlend.mUnk_00, 1);
    }
    item->mNormal = *normal;
    item->mUnk_116 = param_5 != 0 ? 0 : 5;
}

s32 func_020f9880(ItemObject *item) {
    return gItemKinds[item->mKind].mUnk_84;
}

BOOL func_020f97e0(ItemObject *item, Kart *kart) {
    Vec3 offset;
    s32 hitRadius;

    if (item->mCollisionSlotIndex == -1 ||
        kart->mIndex == (u16) ((item->mUnk_78 & 0x4000) != 0 ? (u16) (item->mUnk_78 & ~0xff00) : 8)) {
        return FALSE;
    }
    hitRadius = kart->mRadius + item->mRadius;
    offset.x = item->mPos.x - kart->mPointAlongUp.x;
    offset.y = item->mPos.y - kart->mPointAlongUp.y;
    offset.z = item->mPos.z - kart->mPointAlongUp.z;
    return (s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z <
           (s64) hitRadius * hitRadius;
}

BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius) {
    Vec3 offset;
    s32 sumRadius;

    sumRadius = radius + item->mRadius;
    offset.x = item->mPos.x - center->x;
    offset.y = item->mPos.y - center->y;
    offset.z = item->mPos.z - center->z;
    return (s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z <
           (s64) sumRadius * sumRadius;
}

void func_020f95d4(ItemObject *item, ItemObject *other) {
    Vec3 itemVelocity;
    s32 hitType;
    s32 otherHitType;

    if (other->mCollisionSlotIndex == -1) {
        return;
    }
    if ((other->mFlags & 0x1000) != 0) {
        return;
    }
    if ((other->mFlags & 0x8000) == 0) {
        if (item->mUnk_48 > other->mUnk_48) {
            return;
        }
    }
    if ((item->mFlags & 0x10000000) != 0 && (other->mFlags & 0x10000000) != 0) {
        if (GetItemObjectHitType(item, other) != 1 && GetItemObjectHitType(other, item) != 1) {
            return;
        }
    }
    if (IsItemObjectOverlappingSphere(item, &other->mPos, other->mRadius) == FALSE) {
        if (IsItemObjectOverlappingSphere(item, &other->mPrevPos, other->mRadius) == FALSE) {
            return;
        }
        if (IsItemObjectOverlappingSphere(other, &item->mPrevPos, item->mRadius) == FALSE) {
            return;
        }
    }
    itemVelocity = item->mVelocity;
    hitType = GetItemObjectHitType(item, other);
    otherHitType = GetItemObjectHitType(other, item);
    func_020f77f8(item, hitType, &other->mPos, &other->mVelocity, NULL);
    func_020f77f8(other, otherHitType, &item->mPos, &itemVelocity, NULL);
    if (item->mKind == 1) {
        func_020f5614(item, hitType, other);
    }
    if (other->mKind != 1) {
        return;
    }
    func_020f5614(other, otherHitType, item);
}

void func_020f944c(ItemObject *itemParam, MapObject *mapObjectParam) {
    Vec3 a;
    Vec3 otherPos;
    s32 b;
    MapObject *reportedMapObject;
    ItemObject *item = itemParam;
    MapObject *mapObject = mapObjectParam;

    if (IsSphereHittingMapObject(&item->mPos, item->mRadius, mapObject, &a) == FALSE) {
        return;
    }
    if ((mapObject->mFlags & 0x40) == 0 && (item->mFlags & 0x80000) == 0 &&
        DoesItemObjectRespondToMapObject(item->mKind, mapObject) != 0) {
        VEC_Add(&item->mPos, &a, &item->mPos);
    }
    switch (func_020d6a54(item, mapObject, &b)) {
        case 1:
            otherPos.x = mapObject->mPos.x;
            otherPos.y = item->mPos.y;
            otherPos.z = mapObject->mPos.z;
            a = otherPos;
            if (b == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            func_020f77f8(item, 1, &a, &mapObject->mUnk_10, reportedMapObject);
            item->mUnk_78 &= ~0x4000;
            return;
        case 2:
            if (b == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            func_020f77f8(item, 2, &mapObject->mPos, &mapObject->mUnk_10, reportedMapObject);
            return;
    }
}

void func_020f9334(void *itemParam, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal) {
    ItemObject *item = itemParam;
    Vec3 lowerPos;
    u32 collisionBits;
    s32 x;
    s32 y;
    s32 z;

    collisionBits = 0;
    z = pos->z;
    y = pos->y - item->mUnk_dc;
    x = pos->x;
    lowerPos.x = x;
    lowerPos.y = y;
    lowerPos.z = z;

    func_01ffdee4(&lowerPos, pos, 0, item->mUnk_dc >> 1, 0x24, item->mCollisionSlotIndex, NULL, NULL, NULL,
                  &collisionBits, NULL, NULL, NULL, NULL);
    if ((collisionBits & 0x1e34ef) != 0 || (item->mCollisionBits & 0x80000) != 0) {
        if ((item->mFlags & 0x4000000) != 0) {
            return;
        }
        item->mFlags |= 8;
        item->mNormal = *normal;
        return;
    }
    velocity->z = 0;
    velocity->x = velocity->z;
    if (velocity->y > 0) {
        velocity->y = 0;
        return;
    }
    if (velocity->y > -minFallSpeed) {
        velocity->y = -minFallSpeed;
    }
}
