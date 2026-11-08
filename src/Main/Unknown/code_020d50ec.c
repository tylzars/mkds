#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d275c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d8654.h"

// Calls StartEffectWithCallback twice at the rock; skipped when bit 0 of mDistanceSquaredAndFlags is set, or when b is
// 0 and bit 1 is set. Then resets the rock.
void func_020d634c(RockObject *rock, s32 b) {
    EmitterParams firstEmitterParams;
    EmitterParams secondEmitterParams;
    s32 scaleY;
    u32 distanceAndFlags;
    s32 k;
    s32 j;
    s32 a;
    s16 c;
    s16 d;
    s32 e;
    s32 f;
    s16 g;
    s16 h;
    s32 i;

    distanceAndFlags = rock->mMapObject.mDistanceSquaredAndFlags;
    scaleY = rock->mMapObject.mScale.y;
    if (!(distanceAndFlags & 1)) {
        if (b != 0 || !(distanceAndFlags & 3)) {
            if (scaleY > 0x1000) {
                k = 1;
                j = 0;
            } else {
                k = 3;
                j = 2;
            }
            a = data_02156960[k];
            d = data_02156938[k];
            c = data_02156930[k];
            g = data_02156928[k];
            h = data_02156948[k];
            firstEmitterParams.mUnk_00 = data_02156960[j] + (s32) (((s64) a * scaleY) >> 12);
            i = data_02156940[k];
            firstEmitterParams.mUnk_04 = data_02156940[j] + (s32) (((s64) i * scaleY) >> 12);
            e = data_02156950[k];
            firstEmitterParams.mUnk_06 = data_02156948[j] + (s32) (((s64) h * scaleY) >> 12);
            secondEmitterParams.mUnk_00 = data_02156950[j] + (s32) (((s64) e * scaleY) >> 12);
            f = data_02156920[k];
            firstEmitterParams.mUnk_08 = data_02156920[j] + (s32) (((s64) f * scaleY) >> 12);
            secondEmitterParams.mUnk_04 = data_02156928[j] + (s32) (((s64) g * scaleY) >> 12);
            secondEmitterParams.mUnk_06 = data_02156930[j] + (s32) (((s64) c * scaleY) >> 12);
            secondEmitterParams.mUnk_08 = data_02156938[j] + (s32) (((s64) d * scaleY) >> 12);
            if (rock->mMapObject.mKind == 0x192) {
                StartEffectWithCallback(0x54, &rock->mMapObject.mPos, &firstEmitterParams, func_020d6538);
                StartEffectWithCallback(0x57, &rock->mMapObject.mPos, &secondEmitterParams, func_020d6538);
            } else {
                StartEffectWithCallback(0x56, &rock->mMapObject.mPos, &firstEmitterParams, func_020d6538);
                StartEffectWithCallback(0x55, &rock->mMapObject.mPos, &secondEmitterParams, func_020d6538);
            }
        }
    }
    ResetRock(rock);
}

void UpdateRock(void *a, RockObject *rock) {
    s32 oldBaseX;
    s32 oldBaseZ;
    s32 depthBelowBase;
    s32 verticalSpeed;
    s32 sideIndex;
    s64 newScale;
    s32 newBottomOffset;
    Vec3 *scale;

    if (rock->mUnk_0e0 > 0) {
        rock->mUnk_0e0 -= 1;
        if (rock->mUnk_0e0 != 0) {
            return;
        }
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 1;
        return;
    }
    oldBaseX = rock->mBasePos.x;
    oldBaseZ = rock->mBasePos.z;
    AdvanceGroupFollowerWithSpeeds(&rock->mUnk_0a4);
    GetGroupFollowerCurveXzLinearY(&rock->mUnk_0a4.mUnk_00, &rock->mBasePos);
    rock->mMapObject.mUnk_10.x = rock->mBasePos.x - oldBaseX;
    rock->mMapObject.mUnk_10.z = rock->mBasePos.z - oldBaseZ;
    rock->mOffsetX += rock->mOffsetVelocityX;
    rock->mOffsetZ += rock->mOffsetVelocityZ;
    rock->mMapObject.mUnk_10.x += rock->mOffsetVelocityX;
    rock->mMapObject.mUnk_10.z += rock->mOffsetVelocityZ;
    rock->mMapObject.mPos.x = rock->mBasePos.x + rock->mOffsetX;
    rock->mMapObject.mPos.z = rock->mBasePos.z + rock->mOffsetZ;
    rock->mOffsetX = (rock->mOffsetX * 0x3f) >> 6;
    rock->mOffsetZ = (rock->mOffsetZ * 0x3f) >> 6;
    depthBelowBase = rock->mBasePos.y - (rock->mMapObject.mPos.y - rock->mBottomOffset);
    if (depthBelowBase > 0) {
        rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + depthBelowBase;
        verticalSpeed = rock->mMapObject.mUnk_10.y;
        if (verticalSpeed < 0) {
            if (verticalSpeed >= -0x2000) {
                rock->mMapObject.mUnk_10.y = 0;
            } else {
                rock->mMapObject.mUnk_10.y = -(s32) (((s64) verticalSpeed * rock->mBounceRatio) >> 12);
                rock->mBounceSide = (rock->mBounceSide == FALSE);
                if (rock->mMapObject.mUnk_10.y > 0x4000) {
                    sideIndex = (u16) rock->mUnk_0a4.mUnk_00.mSegmentIndex;
                    rock->mMapObject.mUnk_10.y = 0x4000;
                    if (rock->mBounceSide != FALSE) {
                        rock->mOffsetVelocityX = rock->mSideVectors[sideIndex].x << 1;
                        rock->mOffsetVelocityZ = rock->mSideVectors[sideIndex].z >> 1;
                    } else {
                        rock->mOffsetVelocityX = -rock->mSideVectors[sideIndex].x >> 1;
                        rock->mOffsetVelocityZ = -rock->mSideVectors[sideIndex].z >> 1;
                    }
                } else {
                    rock->mOffsetVelocityX = 0;
                    rock->mOffsetVelocityZ = 0;
                }
            }
        }
        rock->mSinceGroundFrames = 0;
    } else {
        rock->mSinceGroundFrames += 1;
    }
    if (rock->mSinceGroundFrames < 10) {
        StartMapObjectSoundWhileRequested(&rock->mMapObject, 0x179);
    }
    rock->mMapObject.mUnk_10.y = rock->mMapObject.mUnk_10.y - 0x400;
    rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + rock->mMapObject.mUnk_10.y;
    if (rock->mScalePerFrame != 0 && rock->mMapObject.mScale.y < rock->mScaleLimit) {
        newScale = rock->mMapObject.mScale.y + rock->mScalePerFrame;
        newBottomOffset = (newScale * 0x1e000) >> 12;
        FX_DivAsync(0x1000, newBottomOffset);
        scale = &rock->mMapObject.mScale;
        scale->x = newScale;
        scale->y = newScale;
        scale->z = newScale;
        rock->mBottomOffset = newBottomOffset;
        rock->mMapObject.mExtent.x = (newScale * 0x1b000) >> 12;
        if (rock->mMapObject.mCollisionSlotIndex >= 0) {
            SetCollisionSlotRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
        }
        rock->mMapObject.mViewRadius = ((s64) rock->mMapObject.mKindData->mUnk_2c * newScale) >> 12;
        rock->mBottomOffsetReciprocal = FX_GetDivResult();
    }
    if (rock->mUnk_0a4.mUnk_00.mForward == 0) {
        func_020d634c(rock, 0);
    } else if (rock->mMapObject.mPos.y < 0) {
        func_020d634c(rock, 0);
    }
}

// Calls func_020d634c with b = 1 when the byte at c is 1; returns the byte at d.
u8 func_020d5f8c(RockObject *rock, s32 b, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        func_020d634c(rock, 1);
    }
    return *secondResponsePtr;
}

// Same body as func_020d5f8c.
u8 func_020d5f64(RockObject *rock, s32 b, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        func_020d634c(rock, 1);
    }
    return *secondResponsePtr;
}

// Puts the rock back at its start: timer, position, speed and scale.
void ResetRock(RockObject *rock) {
    s64 startScale;
    s32 bottomOffset;
    s32 zero;
    Vec3 *scale;

    SetupGroupFollowerWithSpeeds(&rock->mUnk_0a4, 0, 1);
    GetGroupFollowerCurvePosStepXz(&rock->mUnk_0a4.mUnk_00, &rock->mMapObject.mPos, &rock->mMapObject.mUnk_10);
    rock->mUnk_0e0 = rock->mUnk_0dc;
    if (rock->mUnk_0e0 != 0) {
        rock->mMapObject.mFlags |= data_0215691c;
        rock->mMapObject.mFlags |= data_02156914;
    }
    rock->mBasePos = rock->mMapObject.mPos;
    rock->mBounceSide = TRUE;
    zero = 0;
    rock->mOffsetVelocityX = zero;
    rock->mOffsetVelocityZ = zero;
    rock->mOffsetX = zero;
    rock->mOffsetZ = zero;
    rock->mMapObject.mPos.y = rock->mStartY;
    rock->mMapObject.mUnk_10.y = 0x8000;
    rock->mMapObject.mMatrix.mUnk_00[0] = data_021569d8;
    rock->mMapObject.mMatrix.mUnk_00[1] = data_021569e4;
    rock->mMapObject.mMatrix.mUnk_00[2] = data_021569f0;
    startScale = rock->mStartScale;
    bottomOffset = (startScale * 0x1e000) >> 12;
    FX_DivAsync(0x1000, bottomOffset);
    scale = &rock->mMapObject.mScale;
    scale->x = startScale;
    scale->y = startScale;
    scale->z = startScale;
    rock->mBottomOffset = bottomOffset;
    rock->mMapObject.mExtent.x = (startScale * 0x1b000) >> 12;
    if (rock->mMapObject.mCollisionSlotIndex >= 0) {
        SetCollisionSlotRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
    }
    rock->mMapObject.mViewRadius = ((s64) rock->mMapObject.mKindData->mUnk_2c * startScale) >> 12;
    rock->mBottomOffsetReciprocal = FX_GetDivResult();
}

#pragma thumb on
void CreateNsbmdAndShadowNsbmd(void *a, const char *name, const char *shadowName) {
    CreateNsbmd((void **) &gRock, FindCourseMapObjFile(name), NULL);
    CreateShadowModel((void **) &gRockShadow, FindCourseMapObjFile(shadowName), 7);
    func_02084968(gRock, 0x3f, 2, 0x294a);
    SetNsbmdPolygonIdAll(gRock, 7);
}
#pragma thumb off

#pragma thumb on
void CreateRock(void *a) {
    CreateNsbmdAndShadowNsbmd(a, "rock.nsbmd", "rock_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
void CreateRock2(void *a) {
    CreateNsbmdAndShadowNsbmd(a, "rock2.nsbmd", "rock2_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
// Fills a Rock from its course map row; both Rock kinds use it.
void InitRock(RockObject *rock, struct CourseMapRow *courseRow) {
    CourseMapGroupEntry *startEntry;
    s32 rowValue;
    float scaledValue;

    func_020d7d4c(&rock->mUnk_0a4, courseRow, 0x3000, courseRow->mUnk_2a);
    rock->mUnk_0dc = courseRow->mUnk_28;
    rock->mSideVectors = CreateCourseMapGroupSideVectors(courseRow);
    startEntry = GetCourseMapGroupEntry(courseRow->mUnk_26, 0);
    rock->mStartY = startEntry->mPos.y;
    rock->mStartScale = rock->mMapObject.mScale.y;
    rowValue = courseRow->mUnk_2e;
    if (rowValue > 0) {
        scaledValue = 0.5f + (rowValue << 12);
    } else {
        scaledValue = (rowValue << 12) - 0.5f;
    }
    rock->mScalePerFrame = (s32) scaledValue / 60000;
    rowValue = courseRow->mUnk_30;
    if (rowValue > 0) {
        scaledValue = 0.5f + (rowValue << 12);
    } else {
        scaledValue = (rowValue << 12) - 0.5f;
    }
    rock->mScaleLimit = (s32) scaledValue / 1000 + 0x1000;
    ResetRock(rock);
    rock->mSinceGroundFrames = 0;
    rock->mUnk_0e0 = courseRow->mUnk_32;
    if (rock->mUnk_0e0 != 0) {
        rock->mMapObject.mFlags |= data_0215691c;
        rock->mMapObject.mFlags |= data_02156914;
    } else {
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 0x1f;
    }
    rock->mBounceRatio = (courseRow->mUnk_2c << 12) / 100;
    if (rock->mMapObject.mKind == 0x192) {
        CreateMapObjectSoundSourceFalloff4(&rock->mMapObject);
    } else {
        CreateMapObjectSoundSourceFalloff3(&rock->mMapObject);
    }
    rock->mMapObject.mFlags |= data_02156918;
}
#pragma thumb off

#pragma thumb on
// Turns the stored offsets of the loaded collision file into pointers.
void LoadCourseCollisionData(CourseCollision *collision, CourseCollision *file) {
    *collision = *file;
    collision->mUnk_00 = OFFSET_PTR(Vec3, file, (u32) collision->mUnk_00);
    collision->mUnk_04 = OFFSET_PTR(Vec3s16, file, (u32) collision->mUnk_04);
    collision->mUnk_08 = OFFSET_PTR(Unk0217b614_08, file, (u32) collision->mUnk_08);
    collision->mUnk_0c = OFFSET_PTR(u8, file, (u32) collision->mUnk_0c);
    data_0217b610 = 0;
}
#pragma thumb off

#pragma thumb on
void InitCourseCollision(void) {
    LoadCourseCollisionData(&gCourseCollision, FindCourseFile("course_collision.kcl"));
}
#pragma thumb off

// Keeps the link c on the first object of the hit list a: clears it when b has the top bit or the object changed, sets
// it when b has a bit of 0x1e34ef.
void func_020d5aa0(void *hitListPtr, u32 b, Unk020e04b0 *link, Vec3 *d, Vec3 *e) {
    Unk020d5a68 **hitList = hitListPtr;
    Unk020d5a68 *firstHit;

    if (link->mUnk_00 != NULL) {
        if (b & 0x80000000) {
            link->mUnk_00 = NULL;
            return;
        }
        func_020e0538(link, d);
        firstHit = *hitList;
        if (firstHit->mUnk_04 == 0 && link->mUnk_00 == firstHit->mUnk_00) {
            return;
        }
        link->mUnk_00 = NULL;
        return;
    }
    if (b & 0x80000000) {
        return;
    }
    firstHit = *hitList;
    if (firstHit->mUnk_00 == NULL) {
        return;
    }
    if (firstHit->mUnk_04 != 0) {
        return;
    }
    if (!(b & 0x1e34ef)) {
        return;
    }
    func_020e0584(firstHit->mUnk_00, d, e, link);
}

// TRUE when b has the top bit, the hit list a has a non-zero word at 4, or its object differs from the link c.
BOOL func_020d5a68(void *hitListPtr, u32 b, Unk020e04b0 *link) {
    Unk020d5a68 **hitList = hitListPtr;

    if ((b & 0x80000000) || (*hitList)->mUnk_04 != 0 || link->mUnk_00 != (*hitList)->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

// Returns the value of the recorded hit with the highest bits inside the mask a.
u16 PickCollisionHitValue(u32 mask) {
    s32 i;
    s32 bestIndex;
    u32 maskedBits;
    u32 bestBits;
    s32 hitCount;

    bestIndex = -1;
    i = 0;
    hitCount = gCollisionHitCount;
    if (hitCount > 0) {
        do {
            maskedBits = mask & gCollisionHitBits[i];
            if (maskedBits != 0) {
                if (bestIndex < 0 || maskedBits > bestBits) {
                    bestIndex = i;
                    bestBits = maskedBits;
                }
            }
            i++;
        } while (i < hitCount);
    }
    return gCollisionHitValues[bestIndex];
}

void InitCollisionSlots(void) {
    void *heap;
    s16 i;
    s16 j;

    heap = GetHeap(GetCurrentHeapCall());
    gCollisionSlotCount = 0;
    gFirstFreeCollisionSlot = 0;
    gCollisionSlotHighEnds = HeapAlloc(heap, 0x400);
    gCollisionSlotLowEnds = HeapAlloc(heap, 0x400);
    gCollisionSlots = HeapAlloc(heap, 0x1c00);
    gCollisionSlotNextFree = HeapAlloc(heap, 0x200);
    gFoundCollisionSlotIndices = HeapAlloc(heap, 0x100);
    gFoundCollisionSlotFlags = HeapAlloc(heap, 0x100);
    gFoundCollisionSlotObjects = HeapAlloc(heap, 0x200);
    i = 0;
    do {
        gCollisionSlotNextFree[i] = i + 1;
        i++;
    } while (i < 0x100);
    j = 0;
    do {
        gCollisionSlots[j].mCenterPos = NULL;
        j++;
    } while (j < 0x100);
}

// Returns the new slot index, or -1 when all 0x100 slots are in use.
s32 CreateCollisionSlot(Vec3 *centerPos, s32 radius, s32 flags, void *object) {
    CollisionSlot *slot;
    s16 hi;
    s16 lo;
    s32 slotIndex;
    s32 highPosition;
    s32 lowPosition;
    s32 searchStep;
    s32 highProbe;
    s32 j;
    s32 m;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (gCollisionSlotCount >= 0x100) {
        return -1;
    }
    slotIndex = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = gCollisionSlotNextFree[slotIndex];
    slot = &gCollisionSlots[slotIndex];
    slot->mHighZ = centerPos->z + radius;
    slot->mLowZ = centerPos->z - radius;
    slot->mCenterPos = centerPos;
    slot->mRadius = radius;
    slot->mFlags = flags;
    slot->mObject = object;
    hi = (centerPos->x + radius) >> 11;
    lo = (centerPos->x - radius) >> 11;
    if (gCollisionSlotCount == 0) {
        gCollisionSlotHighEnds[0].mOtherEndIndex = 0;
        gCollisionSlotHighEnds[0].mUnk_01 = 0;
        gCollisionSlotHighEnds[0].mEndX = hi;
        gCollisionSlotLowEnds[0].mOtherEndIndex = 0;
        gCollisionSlotLowEnds[0].mUnk_01 = slotIndex;
        gCollisionSlotLowEnds[0].mEndX = lo;
        gCollisionSlots[0].mHighEndIndex = 0;
        gCollisionSlots[0].mLowEndIndex = 0;
        gCollisionSlotCount = 1;
        return slotIndex;
    }
    highPosition = 0;
    lowPosition = 0;
    searchStep = gCollisionSlotCount;
    m = gCollisionSlotCount;
    for (;;) {
        highProbe = highPosition + searchStep;
        j = lowPosition + searchStep;
        if (highProbe <= m) {
            if (hi > gCollisionSlotHighEnds[highProbe - 1].mEndX) {
                highPosition = highProbe;
            }
        }
        if (j <= m) {
            if (lo > gCollisionSlotLowEnds[j - 1].mEndX) {
                lowPosition = j;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    slot->mHighEndIndex = highPosition;
    slot->mLowEndIndex = lowPosition;
    m = gCollisionSlotCount;
    if (m > highPosition) {
        do {
            endEntry = &gCollisionSlotHighEnds[m];
            *endEntry = gCollisionSlotHighEnds[m - 1];
            otherEnd = &gCollisionSlotLowEnds[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex += 1;
            gCollisionSlots[otherEnd->mUnk_01].mHighEndIndex += 1;
            m--;
            if (endEntry->mUnk_01 >= lowPosition) {
                endEntry->mUnk_01 += 1;
            }
        } while (m > highPosition);
    }
    gCollisionSlotHighEnds[highPosition].mOtherEndIndex = lowPosition;
    gCollisionSlotHighEnds[highPosition].mEndX = hi;
    if (highPosition == gCollisionSlotCount || gCollisionSlotHighEnds[highPosition + 1].mUnk_01 > lowPosition) {
        gCollisionSlotHighEnds[highPosition].mUnk_01 = lowPosition;
        for (j = highPosition - 1; j >= 0 && gCollisionSlotHighEnds[j].mUnk_01 > lowPosition; j--) {
            gCollisionSlotHighEnds[j].mUnk_01 = lowPosition;
        }
    } else {
        gCollisionSlotHighEnds[highPosition].mUnk_01 = gCollisionSlotHighEnds[highPosition + 1].mUnk_01;
    }
    m = gCollisionSlotCount;
    if (m > lowPosition) {
        do {
            endEntry = &gCollisionSlotLowEnds[m];
            *endEntry = gCollisionSlotLowEnds[m - 1];
            gCollisionSlotHighEnds[endEntry->mOtherEndIndex].mOtherEndIndex += 1;
            gCollisionSlots[endEntry->mUnk_01].mLowEndIndex += 1;
            m--;
        } while (m > lowPosition);
    }
    gCollisionSlotLowEnds[lowPosition].mOtherEndIndex = highPosition;
    gCollisionSlotLowEnds[lowPosition].mUnk_01 = slotIndex;
    gCollisionSlotLowEnds[lowPosition].mEndX = lo;
    gCollisionSlotCount += 1;
    return slotIndex;
}

// Always returns -1, which the caller stores as its slot index.
u32 FreeCollisionSlot(s32 slotIndex) {
    CollisionSlot *slot;
    s32 highIndex;
    s32 lowIndex;
    s32 k;
    s32 j;
    s32 otherIndex;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (slotIndex < 0 || slotIndex >= 0x100) {
        return -1;
    }
    slot = &gCollisionSlots[slotIndex];
    highIndex = slot->mHighEndIndex;
    lowIndex = slot->mLowEndIndex;
    if (slot->mCenterPos == NULL) {
        return -1;
    }
    k = highIndex;
    if (k < gCollisionSlotCount - 1) {
        do {
            endEntry = &gCollisionSlotHighEnds[k];
            *endEntry = gCollisionSlotHighEnds[k + 1];
            otherEnd = &gCollisionSlotLowEnds[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex -= 1;
            gCollisionSlots[otherEnd->mUnk_01].mHighEndIndex -= 1;
            if (endEntry->mUnk_01 > lowIndex) {
                endEntry->mUnk_01 -= 1;
            }
            k++;
        } while (k < gCollisionSlotCount - 1);
    }
    k = lowIndex;
    if (k < gCollisionSlotCount - 1) {
        do {
            endEntry = &gCollisionSlotLowEnds[k];
            *endEntry = gCollisionSlotLowEnds[k + 1];
            gCollisionSlotHighEnds[endEntry->mOtherEndIndex].mOtherEndIndex -= 1;
            gCollisionSlots[endEntry->mUnk_01].mLowEndIndex -= 1;
            otherIndex = endEntry->mOtherEndIndex;
            if (otherIndex < highIndex) {
                otherEnd = &gCollisionSlotHighEnds[otherIndex];
                j = otherEnd->mUnk_01;
                if (j == lowIndex) {
                    while (gCollisionSlotLowEnds[j].mOtherEndIndex < (u32) otherIndex) {
                        j++;
                    }
                    otherEnd->mUnk_01 = j;
                }
            }
            k++;
        } while (k < gCollisionSlotCount - 1);
    }
    slot->mCenterPos = NULL;
    gCollisionSlotNextFree[slotIndex] = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = slotIndex;
    gCollisionSlotCount -= 1;
    return -1;
}

// Fills the Found arrays with the slots whose x and z ranges lie within b of position a, whose flags share a bit with
// mask c and that are not disabled.
void FindCollisionSlotsAroundPos(Vec3 *position, s32 radius, s32 flagMask) {
    Vec3 *centerPos = position;
    s32 hi;
    s32 lo;
    s32 searchStep;
    s32 j;
    s32 k;
    s32 centerZ;
    s32 slotCount;
    s32 zhi;
    s32 p;
    s32 zlo;
    s32 t;
    CollisionSlot *slot;
    s32 slotFlags;

    slotCount = gCollisionSlotCount;
    k = centerPos->x;
    centerZ = centerPos->z;
    hi = (s16) ((k + radius) >> 11);
    lo = (s16) ((k - radius) >> 11);
    p = 0;
    gFoundCollisionSlotCount = 0;
    k = 0;
    zhi = centerZ + radius;
    zlo = centerZ - radius;
    searchStep = slotCount - 1;
    for (;;) {
        t = p + searchStep;
        j = k + searchStep;
        if (t <= slotCount) {
            if (lo > gCollisionSlotHighEnds[t - 1].mEndX) {
                p = t;
            }
        }
        if (j <= slotCount) {
            if (hi >= gCollisionSlotLowEnds[j].mEndX) {
                k = j;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    searchStep = gCollisionSlotHighEnds[p].mUnk_01;
    if (k < searchStep) {
        return;
    }
    do {
        if (gCollisionSlotLowEnds[k].mOtherEndIndex >= p) {
            slot = &gCollisionSlots[gCollisionSlotLowEnds[k].mUnk_01];
            slotFlags = slot->mFlags;
            if (slot->mHighZ >= zlo && slot->mLowZ <= zhi && (slotFlags & flagMask) && !(slotFlags & 0x200)) {
                gFoundCollisionSlotIndices[gFoundCollisionSlotCount] = gCollisionSlotLowEnds[k].mUnk_01;
                gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = slotFlags;
                gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = slot->mObject;
                gFoundCollisionSlotCount++;
                if (gFoundCollisionSlotCount == 0x80) {
                    return;
                }
            } else {
                continue;
            }
        }
        if (k == 0) {
            return;
        }
    } while (--k >= searchStep);
}

// A slot with flag 0x400 also gets the flags of data_02156900 set.
void SetCollisionSlotRadius(s16 slotIndex, s32 radius) {
    CollisionSlot *slot;

    slot = &gCollisionSlots[slotIndex];
    slot->mRadius = radius;
    if (slot->mFlags & 0x400) {
        slot->mFlags |= data_02156900;
    }
}

void DisableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags |= data_021568fc;
}

void EnableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags &= ~0x200;
}
