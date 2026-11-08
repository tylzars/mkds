#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

// Position of the start placement with key c (the only one when there are not several) moved by d along the negated
// first and e along the negated third axis of its rotation, and the rotation angles in b.
void GetCourseMapStartPlacementWithOffsets(Vec3 *outPos, Vec3 *outRotation, s32 key, s32 firstAxisOffset,
                                           s32 thirdAxisOffset) {
    CourseMapPlacement *placement = NULL;
    CourseMapPlacement *candidate;
    s32 i;
    u16 angleX;
    u16 angleY;
    u16 angleZ;
    MtxFx43 rotationMatrix;
    MtxFx43 rotationMatrixX;
    MtxFx43 rotationMatrixY;
    MtxFx43 rotationMatrixZ;
    s32 negatedFirstAxisX;
    s32 negatedFirstAxisY;
    s32 negatedFirstAxisZ;
    s32 negatedThirdAxisX;
    s32 negatedThirdAxisY;
    s32 negatedThirdAxisZ;

    if (gCourseMap->mSettings->mUnk_04 != 0) {
        firstAxisOffset = 0x1000 - firstAxisOffset;
    }
    if (gCourseMap->mStartPlacementCount > 1) {
        for (i = 0; i < gCourseMap->mStartPlacementCount; i++) {
            candidate = &(gCourseMap->mStartPlacements)[i];
            if (key == (s16) candidate->mKey) {
                placement = candidate;
                break;
            }
        }
    } else {
        placement = gCourseMap->mStartPlacements;
    }
    angleX = (placement->mUnk_0c.x >> 12) * 0xb6;
    angleY = (placement->mUnk_0c.y >> 12) * 0xb6;
    angleZ = (placement->mUnk_0c.z >> 12) * 0xb6;
    MTX_RotX43_((s32 *) &rotationMatrixX, gPairsByAngle[(angleX >> 4) * 2], gPairsByAngle[(angleX >> 4) * 2 + 1]);
    MTX_RotY43_(&rotationMatrixY, gPairsByAngle[(angleY >> 4) * 2], gPairsByAngle[(angleY >> 4) * 2 + 1]);
    MTX_RotZ43_((s32 *) &rotationMatrixZ, gPairsByAngle[(angleZ >> 4) * 2], gPairsByAngle[(angleZ >> 4) * 2 + 1]);
    MTX_Concat43(&rotationMatrixX, &rotationMatrixZ, &rotationMatrix);
    MTX_Concat43(&rotationMatrixY, &rotationMatrix, &rotationMatrix);
    negatedFirstAxisX = -rotationMatrix.mUnk_00[0].x;
    negatedFirstAxisY = -rotationMatrix.mUnk_00[0].y;
    negatedFirstAxisZ = -rotationMatrix.mUnk_00[0].z;
    negatedThirdAxisX = -rotationMatrix.mUnk_00[2].x;
    negatedThirdAxisY = -rotationMatrix.mUnk_00[2].y;
    negatedThirdAxisZ = -rotationMatrix.mUnk_00[2].z;
    outPos->x = placement->mPos.x + (s32) (((s64) negatedFirstAxisX * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisX * thirdAxisOffset + 0x800) >> 12);
    outPos->y = placement->mPos.y + (s32) (((s64) negatedFirstAxisY * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisY * thirdAxisOffset + 0x800) >> 12);
    outPos->z = placement->mPos.z + (s32) (((s64) negatedFirstAxisZ * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisZ * thirdAxisOffset + 0x800) >> 12);
    outRotation->x = placement->mUnk_0c.x;
    outRotation->y = placement->mUnk_0c.y;
    outRotation->z = placement->mUnk_0c.z;
}

// Position and rotation of the start spot of kart c by mode: a staggered grid by rank in a race, by key
// (kart + mStartPlacementOffset) % 8 in battle.
void GetCourseMapKartStartPlacement(Vec3 *outPos, Vec3 *outRotation, s32 kartIndex) {
    u16 lastKartIndex = gRaceSetup->mKartCount - 1;
    s32 rankIndex = (u16) (GetKartStartRank(kartIndex) - 1);
    s32 k;
    s32 l;
    s32 n;
    s32 t;
    s32 d;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0, 0);
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation,
                                                  (u16) ((rankIndex + gRaceProgress->mStartPlacementOffset) % 8), 0, 0);
            break;
        case MODE_TIME_ATTACK:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0x800, 0);
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mKartCount <= 1) {
                GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0x800, 0);
            } else {
                GetCourseMapStartPlacementWithOffsets(outPos, outRotation, kartIndex,
                                                      (1 - kartIndex * 2) * 0x14000 + 0x800, 0);
            }
            break;
        default:
            k = data_0215406c[lastKartIndex * 2];
            l = k;
            n = rankIndex;
            if (rankIndex >= k) {
                l = data_0215406d[lastKartIndex * 2];
                n = rankIndex - k;
            }
            if ((l & 1) == 1) {
                n = (n - l / 2) * 2;
            } else {
                n = n * 2 + 1 - l;
            }
            if (rankIndex >= k) {
                if (k == data_0215406d[(u32) lastKartIndex * 2]) {
                    n = n + 1;
                }
            }
            d = n * 0x11000;
            t = 0;
            if (rankIndex >= k) {
                t = 1;
            }
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, d, rankIndex * 0x19000 + t * 0x14000);
            break;
    }
}

BOOL IsPosInCourseMapShapeBox(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 distance;
    s32 extent;

    VEC_Subtract(pos, &shape->mPos, &offset);
    distance = VEC_DotProduct(&offset, &shape->mAxisY);
    if (distance > (s32) (((s64) shape->mScale.y * 0x64000 + 0x800) >> 12) || distance < 0) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisX);
    extent = ((s64) shape->mScale.x * 0x32000 + 0x800) >> 12;
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisZ);
    extent = ((s64) shape->mScale.z * 0x32000 + 0x800) >> 12;
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    return TRUE;
}

s32 IsPosInCourseMapShape(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 inside = 0;
    s32 x;
    s32 y;
    s32 radius;

    switch (shape->mShapeKind) {
        case 0:
            inside = IsPosInCourseMapShapeBox(pos, shape);
            break;
        case 1:
            VEC_Subtract(pos, &shape->mPos, &offset);
            if (VEC_DotProduct(&offset, &shape->mAxisY) > (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                inside = 0;
            } else {
                x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                inside = (s32) (((s64) radius * radius + 0x800) >> 12) >=
                         (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12);
            }
            break;
    }
    return inside;
}

s32 func_0204176c(Vec3 *pos, s32 *outFlag) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    BOOL found = FALSE;
    s32 x;
    s32 y;
    s32 radius;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == 2) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                if ((s16) shape->mUnk_3c == 0) {
                    *outFlag = 1;
                } else {
                    *outFlag = 0;
                }
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

void *FindCourseMapKind4ShapeRacePointLink(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    void *link = NULL;
    s32 inside;

    if (gCourseMap->mKind4ShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == 4) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = (u8 *) gCourseMap->mRacePointLinks + shape->mPointIndex * 0x28;
                break;
            }
        }
    }
    return link;
}

PointLink *FindCourseMapKind4ShapeBattlePointLink(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    PointLink *link = NULL;
    s32 inside;

    if (gCourseMap->mKind4ShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == 4) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &gCourseMap->mBattlePointLinks[shape->mPointIndex];
                break;
            }
        }
    }
    return link;
}

s32 GetCourseMapCameraIndexAtPos(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    s32 cameraIndex = -1;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == 1) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) >
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        inside = 0;
                    } else {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) <
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 0;
                        } else {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                cameraIndex = shape->mCameraIndex;
                break;
            }
        }
    }
    return cameraIndex;
}

// Mode 2: returns mNextRespawnSlot and advances it modulo mRespawnCount (the argument is ignored); otherwise returns
// mCheckpoints[a].mRespawnSlot, a = the kart's current entry.
u16 GetCourseMapRespawnSlot(u32 checkpointIndex) {
    u16 respawnSlot;
    CourseMap *courseMap;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        courseMap = gCourseMap;
        respawnSlot = courseMap->mNextRespawnSlot;
        courseMap->mNextRespawnSlot = (respawnSlot + 1) % courseMap->mRespawnCount;
    } else {
        respawnSlot = gCourseMap->mCheckpoints[checkpointIndex].mRespawnSlot;
    }
    return respawnSlot;
}

void *GetCourseMapRespawnRacePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->mUnk_0c.x;
        outRotation->y = respawn->mUnk_0c.y;
        outRotation->z = respawn->mUnk_0c.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return (u8 *) gCourseMap->mRacePointLinks + pointIndex * 0x28;
}

PointLink *GetCourseMapRespawnBattlePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->mUnk_0c.x;
        outRotation->y = respawn->mUnk_0c.y;
        outRotation->z = respawn->mUnk_0c.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return &gCourseMap->mBattlePointLinks[pointIndex];
}

struct ItemPointLink *GetCourseMapRespawnItemPointLink(u32 slot) {
    CourseMapRespawn *respawn;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        return NULL;
    }
    return &gCourseMap->mItemPointLinks[respawn->mItemPointIndex];
}

s32 IsKartInCourseMapKind3ShapeList(s32 kartIndex, u32 listIndex) {
    CourseMapKind3ShapeNode *node;
    s32 inside;
    CourseMapShape *shape;
    Vec3 kartPos;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    BOOL found = FALSE;

    node = gCourseMap->mKind3ShapeLists[listIndex];
    GetKartPos(&kartPos, kartIndex);
    for (; found == FALSE && node != NULL; node = node->mUnk_04) {
        shape = node->mUnk_00;
        inside = 0;
        switch (shape->mShapeKind) {
            case 0:
                inside = IsPosInCourseMapShapeBox(&kartPos, shape);
                break;
            case 1:
                VEC_Subtract(&kartPos, &shape->mPos, &offset);
                if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                    (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                    x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                    y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                    radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                    if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                        (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                        inside = 1;
                    }
                }
                break;
        }
        if (inside != 0) {
            found = TRUE;
        }
    }
    return found;
}
