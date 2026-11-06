#pragma once

#include "types.h"

// Header of the file returned by FindCourseFile in CreateCourseMap: a word array at 0x08 holds offsets from 0x06's
// value. The halfword at 4 is the format version (copied to CourseMap.mVersion).
typedef struct CourseMapHeader {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mVersion;
    /* 06 */ u16 mBaseOffset;
    /* 08 */ s32 mSectionOffsets[1];
} CourseMapHeader;

extern s32 (*gCourseMapSectionLoaders[17])(void *a, ...);

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

void CreateCourseMap(void *a);

typedef struct Unk020f41c4_B Unk020f41c4_B;

typedef struct CourseMapRoute CourseMapRoute;
typedef struct Unk02175620_a0 Unk02175620_a0;
typedef struct Unk020f371c Unk020f371c;

// Takes the camera section: stores mCameraCount and mCameras (NULL when empty) and remembers the first entry of chain
// 1, chain 2, kind 6, kind 7 (battle) and kind 8 (mission run) in the CourseMap members of those names. Returns 1.
s32 LoadCourseMapCamerasData(void *a, ...);
// Takes the shape section: stores mShapeCount and mShapes (NULL when empty), then builds the kind 3 lists and counts
// the kind 4 shapes and, in mission run, the kind 2 shapes. Returns 1.
s32 LoadCourseMapShapesData(void *a, ...);
void CountCourseMapKind2ShapesInMode4(void);
void CountCourseMapKind4Shapes(void);
void BuildCourseMapKind3ShapeLists(void);
CourseMapShape *GetCourseMapShape(u32 a);
// Takes the route section of table entry 14: with several start placements it stores mBattleRouteCount and
// mBattleRoutes, otherwise mRaceRouteCount and mRaceRoutes; when the section is not empty the other pair is cleared.
// Returns 1.
s32 LoadCourseMapBattleOrRaceRoutesData(void *a, ...);
// Takes the point section of table entry 13: with several start placements it stores mBattlePointCount and
// mBattlePoints, otherwise mRacePointCount and mRacePoints; when the section is not empty the other pair is cleared.
// Returns 1.
s32 LoadCourseMapBattleOrRacePointsData(void *a, ...);
// Takes the item route section: stores mItemRouteCount and mItemRoutes (NULL when empty). Returns 1.
s32 LoadCourseMapItemRoutesData(void *a, ...);
// Takes the item point section: stores mItemPointCount and mItemPoints (NULL when empty). Returns 1.
s32 LoadCourseMapItemPointsData(void *a, ...);
s32 LoadCourseMapCheckpointRoutesData(void *a, ...);
s32 LoadCourseMapCheckpointsData(void *a, ...);
s32 func_020426ac(void *a, ...);
// Takes the keyed placement section when the format version is 0x1f or more (else clears mKeyedPlacementCount and
// mKeyedPlacements), then builds the index by key. Returns 1 when the version has the section, else 0 and the same
// section offset goes to the next loader.
s32 LoadCourseMapKeyedPlacementsData(void *a, ...);
// Allocates mKeyedPlacementIndexByKey (one halfword per record) and stores in it the index of each record at its key;
// NULL when there are no records.
void BuildCourseMapKeyedPlacementIndexByKey(void);
s32 func_020427ac(void *a, ...);
void ShuffleCourseMapRespawnSlots(Unk020f41c4_B *a);
s32 LoadCourseMapRespawnsData(void *a, ...);
s32 LoadCourseMapStartPlacementsData(void *a, ...);
u32 LoadCourseMapSettingsData(void *arg0);
// Called once by CreateCourseMap after the sections are loaded: builds mItemPointLinks when mItemRouteCount is not 0,
// and mRacePointLinks when mRaceRouteCount is not 0, else mBattlePointLinks when mBattleRouteCount is not 0.
void BuildCourseMapPointLinks(void *a);
// Allocates mBattlePointLinks (one per battle point) and clears it, stores the first link and the end pointer in the
// next two CourseMap members, then fills each link from its point and its route: the first point of a route joins the
// routes named by the bytes at 0x0c of the route, the last point those named by the bytes at 0x04, inner points the
// next and previous point.
void BuildCourseMapBattlePointLinks(void *a);
// Allocates mRacePointLinks (one per race point) and clears it, stores the link of the first point of route 0 and the
// link of the last point of the route before route 0 in the next two CourseMap members, links the points route by route
// from route 0 (BuildCourseMapRaceRouteLinks), then starts every route whose first point has no previous link.
void BuildCourseMapRacePointLinks(void *a);
// Fills the link of point c of route b (pointer to its point and two values), joins it to link a when a is not NULL,
// then goes on with the next point of the route and, at the route end, with the first point of each following route
// (255 = none).
void BuildCourseMapRaceRouteLinks(Unk02175620_a0 *a, CourseMapRoute *b, u16 c);
// Allocates mItemPointLinks (one per item point) and clears it, stores the link of the first point of route 0 and the
// link of the last point of the route before route 0 in the next two CourseMap members, then links the points route by
// route from route 0 (BuildCourseMapItemRouteLinks).
void BuildCourseMapItemPointLinks(void *a);
// Fills the link of point c of route b (pointer to its point and two values), joins it to link a as next and previous
// (skipped when already joined), then goes on with the next point of the route and, at the route end, with the first
// point of each following route other than route 0 and 255.
void BuildCourseMapItemRouteLinks(Unk020f371c *a, CourseMapRoute *b, u16 c);
Unk02175620_94 *GetCourseMapEntryGroupTableRow(unsigned int p0);
void func_02042fd8(void *a);
void func_02043038(void);
s32 func_02043078(u16 a);
s32 LoadCourseMapGroupEntriesData(void *a, ...);
s32 LoadCourseMapEntryGroupsData(void *a, ...);
s32 LoadCourseMapRowsData(void *a, ...);
u16 ReadCourseMapSectionCount(void **a);
