#pragma once

#include "types.h"
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
#include "Main/Unknown/code_020f36d8.h"

extern u8 data_0215406c[];
extern u8 data_0215406d[];

// TRUE when the position of kart a lies inside any shape of list b of mKind3ShapeLists.
s32 IsKartInCourseMapKind3ShapeList(s32 kartIndex, u32 listIndex);
// Returns the element of mItemPointLinks given by mItemPointIndex of the respawn spot of slot a, NULL when there is no
// respawn spot.
struct ItemPointLink *GetCourseMapRespawnItemPointLink(u32 slot);
// Looks up the respawn spot of slot a: writes its position to b and its rotation angles to c (a default position and
// angles when there is none) and returns its element of mBattlePointLinks (mPointIndex), NULL for -1.
PointLink *GetCourseMapRespawnBattlePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation);
// Looks up the respawn spot of slot a: writes its position to b and its rotation angles to c (a default position and
// angles when there is none) and returns its element of mRacePointLinks (mPointIndex), NULL for -1.
void *GetCourseMapRespawnRacePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation);
u16 GetCourseMapRespawnSlot(u32 checkpointIndex);
// Returns CourseMapShape.mCameraIndex of the first shape of mKind 1 that contains position a, or -1 when there is none.
s32 GetCourseMapCameraIndexAtPos(Vec3 *pos);
// Returns the element of mBattlePointLinks given by mPointIndex of the first mKind 4 shape that contains position a, or
// NULL; NULL at once when the course has no kind 4 shapes.
PointLink *FindCourseMapKind4ShapeBattlePointLink(Vec3 *pos);
// Returns the element of mRacePointLinks given by mPointIndex of the first mKind 4 shape that contains position a, or
// NULL; NULL at once when the course has no kind 4 shapes.
void *FindCourseMapKind4ShapeRacePointLink(Vec3 *pos);
s32 func_0204176c(Vec3 *pos, s32 *outFlag);
s32 IsPosInCourseMapShape(Vec3 *pos, CourseMapShape *shape);
BOOL IsPosInCourseMapShapeBox(Vec3 *pos, CourseMapShape *shape);
void GetCourseMapKartStartPlacement(Vec3 *outPos, Vec3 *outRotation, s32 kartIndex);
void GetCourseMapStartPlacementWithOffsets(Vec3 *outPos, Vec3 *outRotation, s32 key, s32 firstAxisOffset,
                                           s32 thirdAxisOffset);
