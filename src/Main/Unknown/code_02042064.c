#include "Main/Unknown/code_02042064.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020431bc.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02043000.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
u16 ReadCourseMapSectionCount(void **cursor) {
    u32 *countWord;
    u16 count;

    *cursor = (u32 *) *cursor + 1;
    countWord = *cursor;
    count = *countWord;
    *cursor = countWord + 1;
    return count;
}

s32 LoadCourseMapRowsData(void *section, ...) {
    gCourseMap->mRowCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mRowCount == 0) {
        gCourseMap->mRows = NULL;
    } else {
        gCourseMap->mRows = section;
    }
    return 1;
}

s32 LoadCourseMapEntryGroupsData(void *section, ...) {
    gCourseMap->mEntryGroupCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mEntryGroupCount == 0) {
        gCourseMap->mEntryGroups = NULL;
    } else {
        gCourseMap->mEntryGroups = section;
    }
    return 1;
}

s32 LoadCourseMapGroupEntriesData(void *section, ...) {
    gCourseMap->mGroupEntryCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mGroupEntryCount == 0) {
        gCourseMap->mGroupEntries = NULL;
    } else {
        gCourseMap->mGroupEntries = section;
    }
    return 1;
}

static inline CourseMapCheckpoint *func_02043078_inline(u16 i) {
    return &gCourseMap->mCheckpoints[i];
}

// Sums mUnk_18 along the route, plus the average of the sums of the routes that follow it.
s32 ComputeCourseMapRouteCheckpointSum(u16 routeIndex) {
    u16 followingCount;
    s32 followingSum;
    CourseMapRoute *route;
    s32 total;
    u16 entryOffset;
    u16 nextSlot;
    s8 nextRoute;

    route = gCourseMap->mCheckpointRoutes + routeIndex;
    followingSum = 0;
    followingCount = 0;
    total = 0;
    for (entryOffset = 0; entryOffset < route->mEntryCount; entryOffset++) {
        total += func_02043078_inline(route->mFirstEntry + entryOffset)->mUnk_18;
    }
    for (nextSlot = 0; nextSlot < 3; nextSlot++) {
        nextRoute = (route->mNextRoutes)[nextSlot];
        if (nextRoute != -1 && nextRoute != 0) {
            followingSum += ComputeCourseMapRouteCheckpointSum(nextRoute);
            followingCount++;
        }
    }
    if (followingCount != 0) {
        total += followingSum / followingCount;
    }
    return total;
}

// Both values are 0 on courses with more than one start placement.
void SetCourseMapCheckpointTotals(void) {
    u32 checkpointSum;
    u32 checkpointSumQuotient;

    checkpointSum = 0;
    checkpointSumQuotient = 0;
    if (gCourseMap->mStartPlacementCount <= 1) {
        checkpointSum = ComputeCourseMapRouteCheckpointSum(0);
        checkpointSumQuotient = checkpointSum / 15000;
    }
    gCourseMap->mCheckpointSum = checkpointSum;
    gCourseMap->mCheckpointSumQuotient = checkpointSumQuotient;
}

void BuildCourseMapEntryGroupTable(void *heap) {
    CourseMap *courseMap;
    CourseMapEntryGroupTableRow *row;
    u16 groupCount;
    CourseMapGroupEntry *groupEntries;
    u32 size;
    u16 i;
    CourseMapEntryGroup *group;

    courseMap = gCourseMap;
    groupCount = courseMap->mEntryGroupCount;
    size = groupCount << 3;
    groupEntries = courseMap->mGroupEntries;
    if (size != 0) {
        row = HeapAlloc(heap, size);
        gCourseMap->mEntryGroupTable = row;
        for (i = 0; i < groupCount; i++) {
            group = gCourseMap->mEntryGroups + i;
            row->mGroup = group;
            row->mEntries = groupEntries;
            groupEntries += group->mEntryCount;
            row++;
        }
    } else {
        courseMap->mEntryGroupTable = NULL;
    }
    SetCourseMapCheckpointTotals();
}
#pragma thumb off

#pragma thumb on

CourseMapEntryGroupTableRow *GetCourseMapEntryGroupTableRow(u32 groupIndex) {
    return gCourseMap->mEntryGroupTable + groupIndex;
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapItemRouteLinks(ItemPointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    CourseMapItemPoint *itemPoint;
    ItemPointLink *link;
    s32 nextRoute;
    s32 k;

    if (gCourseMap->mVersion < 0x21) {
        itemPoint = (CourseMapItemPoint *) ((Unk02175620_54_10 *) gCourseMap->mItemPoints + pointIndex);
    } else {
        itemPoint = gCourseMap->mItemPoints + pointIndex;
    }
    link = gCourseMap->mItemPointLinks + pointIndex;
    for (k = 0; k < 3; k++) {
        if (previousLink != NULL && link->mPreviousLinks[k] == previousLink) {
            return;
        }
    }
    link->mPointPos = &itemPoint->mPos;
    link->mUnk_1c = itemPoint->mUnk_0c;
    if (gCourseMap->mVersion < 0x21) {
        link->mUnk_20 = 0;
    } else {
        link->mUnk_20 = itemPoint->mUnk_10;
    }
    for (k = 0; k < 3; k++) {
        if (previousLink->mNextLinks[k] == NULL) {
            previousLink->mNextLinks[k] = link;
            previousLink->mNextCount++;
            break;
        }
    }
    for (k = 0; k < 3; k++) {
        if (link->mPreviousLinks[k] == NULL) {
            link->mPreviousLinks[k] = previousLink;
            link->mPreviousCount++;
            break;
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        BuildCourseMapItemRouteLinks(link, route, pointIndex + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        nextRoute = route->mNextRoutes[k];
        if (nextRoute != 0xff && nextRoute != 0) {
            BuildCourseMapItemRouteLinks(link, &gCourseMap->mItemRoutes[nextRoute],
                                         gCourseMap->mItemRoutes[nextRoute].mFirstEntry);
        }
    }
}

void BuildCourseMapItemPointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    ItemPointLink **q;
    s32 i;
    ItemPointLink *link;
    s32 k;
    s32 lastEntry;
    s32 previousFirstEntry;
    CourseMapRoute *routes;
    CourseMapRoute *previousRoute;

    courseMap = gCourseMap;
    firstRoute = courseMap->mItemRoutes;
    q = &courseMap->mItemPointLinks;
    courseMap->mItemPointLinks = HeapAlloc(heap, courseMap->mItemPointCount * 0x28);
    q[1] = courseMap->mItemPointLinks + firstRoute->mFirstEntry;
    for (i = 0; i < gCourseMap->mItemPointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 3; k++) {
            link->mPreviousLinks[k] = NULL;
            link->mNextLinks[k] = NULL;
        }
        link->mNextCount = 0;
        link->mPreviousCount = 0;
        link->mPointPos = NULL;
        link->mUnk_20 = 0;
        link->mUnk_1c = 0;
    }
    routes = gCourseMap->mItemRoutes;
    previousRoute = routes + firstRoute->mPreviousRoutes[0];
    previousFirstEntry = routes[firstRoute->mPreviousRoutes[0]].mFirstEntry;
    lastEntry = previousFirstEntry + previousRoute->mEntryCount - 1;
    q[2] = q[0] + lastEntry;
    BuildCourseMapItemRouteLinks(q[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
}

void BuildCourseMapRaceRouteLinks(RacePointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    RacePointLink *link;
    s32 nextRoute;
    s32 k;
    CourseMapPoint *racePoint;

    racePoint = gCourseMap->mRacePoints + pointIndex;
    link = gCourseMap->mRacePointLinks + pointIndex;
    for (k = 0; k < 3; k++) {
        if (previousLink != NULL && link->mUnk_0c[k] == previousLink) {
            return;
        }
    }
    link->mUnk_18 = racePoint;
    link->mUnk_1c = racePoint->mUnk_0c;
    link->mUnk_20 = racePoint->mUnk_10;
    if (previousLink != NULL) {
        for (k = 0; k < 3; k++) {
            if (previousLink->mUnk_00[k] == NULL) {
                previousLink->mUnk_00[k] = link;
                previousLink->mUnk_24++;
                break;
            }
        }
        for (k = 0; k < 3; k++) {
            if (link->mUnk_0c[k] == NULL) {
                link->mUnk_0c[k] = previousLink;
                link->mUnk_26++;
                break;
            }
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        BuildCourseMapRaceRouteLinks(link, route, pointIndex + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        nextRoute = route->mNextRoutes[k];
        if (nextRoute != 0xff) {
            BuildCourseMapRaceRouteLinks(link, &gCourseMap->mRaceRoutes[nextRoute],
                                         gCourseMap->mRaceRoutes[nextRoute].mFirstEntry);
        }
    }
}

void BuildCourseMapRacePointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    RacePointLink **q;
    CourseMapRoute *t;
    s32 i;
    RacePointLink *link;
    s32 k;
    s32 lastEntry;

    courseMap = gCourseMap;
    firstRoute = courseMap->mRaceRoutes;
    q = &courseMap->mRacePointLinks;
    courseMap->mRacePointLinks = HeapAlloc(heap, courseMap->mRacePointCount * 0x28);
    q[1] = courseMap->mRacePointLinks + firstRoute->mFirstEntry;
    for (i = 0; i < gCourseMap->mRacePointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 3; k++) {
            link->mUnk_0c[k] = NULL;
            link->mUnk_00[k] = NULL;
        }
        link->mUnk_24 = 0;
        link->mUnk_26 = 0;
        link->mUnk_18 = NULL;
        link->mUnk_20 = NULL;
        link->mUnk_1c = 0;
    }
    t = gCourseMap->mRaceRoutes + firstRoute->mPreviousRoutes[0];
    lastEntry = t->mFirstEntry + t->mEntryCount - 1;
    q[2] = q[0] + lastEntry;
    BuildCourseMapRaceRouteLinks(q[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
    for (i = 0; i < gCourseMap->mRaceRouteCount; i++) {
        t = gCourseMap->mRaceRoutes + (u16) i;
        if (q[0][t->mFirstEntry].mUnk_24 == 0) {
            BuildCourseMapRaceRouteLinks(NULL, t, t->mFirstEntry);
        }
    }
}

void BuildCourseMapBattlePointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapBattleRoute *route;
    CourseMapBattleRoute *t;
    PointLink **q;
    s32 i;
    PointLink *link;
    PointLink *pointLink;
    s32 pointIndex;
    s32 k;
    u16 routeIndex;
    u16 linkCount;
    u16 lastPoint;
    CourseMapPoint *battlePoint;
    u16 b;
    u16 c;

    courseMap = gCourseMap;
    route = courseMap->mBattleRoutes;
    q = &courseMap->mBattlePointLinks;
    courseMap->mBattlePointLinks = HeapAlloc(heap, courseMap->mBattlePointCount * 0x30);
    q[1] = courseMap->mBattlePointLinks;
    q[2] = courseMap->mBattlePointLinks + gCourseMap->mBattlePointCount;
    for (i = 0; i < gCourseMap->mBattlePointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 8; k++) {
            link->mLinks[k] = NULL;
        }
        link->mLinkCount = 0;
        link->mUnk_20 = NULL;
        link->mUnk_28 = NULL;
        link->mUnk_24 = 0;
    }
    for (pointIndex = 0; pointIndex < gCourseMap->mBattlePointCount; pointIndex++) {
        battlePoint = gCourseMap->mBattlePoints + (u16) pointIndex;
        pointLink = q[0] + pointIndex;
        linkCount = 0;
        for (routeIndex = 0; routeIndex < gCourseMap->mBattleRouteCount; routeIndex++) {
            t = gCourseMap->mBattleRoutes;
            route = t + routeIndex;
            if (pointIndex >= t[routeIndex].mUnk_00 && pointIndex < route->mUnk_00 + route->mUnk_02) {
                break;
            }
        }
        pointLink->mUnk_2e = 0;
        lastPoint = route->mUnk_00 + route->mUnk_02 - 1;
        if (pointIndex == route->mUnk_00) {
            for (b = 0; b < 8; b++) {
                if (route->mUnk_0c[b] != 0xff) {
                    pointLink->mUnk_2e |= 1 << linkCount;
                    pointLink->mLinks[linkCount++] = q[0] + route->mUnk_0c[b];
                }
            }
            if (route->mUnk_02 > 1) {
                pointLink->mLinks[linkCount++] = pointLink + 1;
            }
        }
        if (pointIndex == lastPoint) {
            for (c = 0; c < 8; c++) {
                if (route->mUnk_04[c] != 0xff) {
                    pointLink->mUnk_2e |= 1 << linkCount;
                    pointLink->mLinks[linkCount++] = q[0] + route->mUnk_04[c];
                }
            }
            if (route->mUnk_02 > 1) {
                pointLink->mLinks[linkCount++] = pointLink - 1;
            }
        }
        if (pointIndex != route->mUnk_00 && pointIndex != lastPoint) {
            linkCount = 0;
            pointLink->mLinks[linkCount++] = pointLink + 1;
            pointLink->mLinks[linkCount++] = pointLink - 1;
        }
        pointLink->mUnk_20 = &battlePoint->mPos;
        pointLink->mUnk_24 = battlePoint->mUnk_0c;
        pointLink->mUnk_28 = battlePoint->mUnk_10;
        pointLink->mLinkCount = linkCount;
    }
}

void BuildCourseMapPointLinks(void *a) {
    if (gCourseMap->mItemRouteCount != 0) {
        BuildCourseMapItemPointLinks(a);
    }
    if (gCourseMap->mRaceRouteCount != 0) {
        BuildCourseMapRacePointLinks(a);
    } else if (gCourseMap->mBattleRouteCount != 0) {
        BuildCourseMapBattlePointLinks(a);
    }
}
#pragma thumb off

#pragma thumb on
u32 LoadCourseMapSettingsData(void *arg0) {
    gCourseMap->mSettings = OFFSET_PTR(CourseMapSettings, arg0, 4);
    return 1;
}
#pragma thumb off

#pragma thumb on
s32 LoadCourseMapStartPlacementsData(void *section, ...) {
    gCourseMap->mStartPlacementCount = ReadCourseMapSectionCount(&section);
    gCourseMap->mStartPlacements = section;
    return 1;
}

s32 LoadCourseMapRespawnsData(void *section, ...) {
    s32 i;
    s32 maxSlot;
    void *heap;
    s32 respawnCount;
    s32 k;
    u16 t;
    CourseMapRespawn *respawn;

    heap = GetHeap(GetCurrentHeapCall());
    gCourseMap->mRespawnCount = ReadCourseMapSectionCount(&section);
    gCourseMap->mRespawns = section;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        respawnCount = gCourseMap->mRespawnCount;
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(heap, respawnCount * 2);
        gCourseMap->mNextRespawnSlot = 0;
        for (i = 0; i < respawnCount; i++) {
            gCourseMap->mRespawnIndexBySlot[i] = i;
        }
    } else if (gCourseMap->mRespawnCount != 0) {
        maxSlot = 0;
        for (k = 0; k < gCourseMap->mRespawnCount; k++) {
            respawn = &gCourseMap->mRespawns[k];
            if (respawn->mSlot > maxSlot) {
                maxSlot = respawn->mSlot;
            }
        }
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(heap, (maxSlot + 1) * 2);
        for (i = 0; i < maxSlot + 1; i++) {
            gCourseMap->mRespawnIndexBySlot[i] = 0xffff;
        }
        for (i = 0; i < gCourseMap->mRespawnCount; i++) {
            gCourseMap->mRespawnIndexBySlot[gCourseMap->mRespawns[i].mSlot] = i;
        }
    }
    return 1;
}

static inline u16 func_020427d4_inline(RandomState64 *randomState64, u16 limit) {
    u32 value;
    if (limit == 0) {
        value = 0;
    } else {
        randomState64->mValue =
            (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            value = randomState64->mValue >> 32;
        } else {
            value = ((s64) (randomState64->mValue >> 32) * (u32) limit) >> 32;
        }
    }
    return value;
}

void ShuffleCourseMapRespawnSlots(RandomState64 *randomState64) {
    s32 i;
    u16 respawnCount;
    u16 firstSlot;
    u16 secondSlot;
    u16 t;

    respawnCount = gCourseMap->mRespawnCount;
    for (i = 0; i < 100; i++) {
        firstSlot = func_020427d4_inline(randomState64, respawnCount);
        secondSlot = func_020427d4_inline(randomState64, respawnCount);
        t = gCourseMap->mRespawnIndexBySlot[secondSlot];
        gCourseMap->mRespawnIndexBySlot[secondSlot] = gCourseMap->mRespawnIndexBySlot[firstSlot];
        gCourseMap->mRespawnIndexBySlot[firstSlot] = t;
    }
}

s32 func_020427ac(void *section, ...) {
    gCourseMap->mUnk_30 = ReadCourseMapSectionCount(&section);
    gCourseMap->mUnk_2c = section;
    return 1;
}

void BuildCourseMapKeyedPlacementIndexByKey(void) {
    u16 placementCount;
    u16 i;

    placementCount = gCourseMap->mKeyedPlacementCount;
    if (placementCount == 0) {
        gCourseMap->mKeyedPlacementIndexByKey = NULL;
        return;
    }
    gCourseMap->mKeyedPlacementIndexByKey = HeapAlloc(GetHeap(GetCurrentHeapCall()), placementCount * 2);
    for (i = 0; i < placementCount; i++) {
        gCourseMap->mKeyedPlacementIndexByKey[gCourseMap->mKeyedPlacements[i].mKey] = i;
    }
}

s32 LoadCourseMapKeyedPlacementsData(void *section, ...) {
    BOOL loaded = FALSE;

    if (gCourseMap->mVersion < 0x1f) {
        gCourseMap->mKeyedPlacementCount = 0;
        gCourseMap->mKeyedPlacements = NULL;
    } else {
        gCourseMap->mKeyedPlacementCount = ReadCourseMapSectionCount(&section);
        gCourseMap->mKeyedPlacements = section;
        loaded = TRUE;
    }
    BuildCourseMapKeyedPlacementIndexByKey();
    return loaded;
}

s32 func_020426ac(void *section, ...) {
    enum { K0 } r = 0;

    if (gCourseMap->mVersion < 0x24) {
        gCourseMap->mUnk_40 = r;
        gCourseMap->mUnk_3c = NULL;
        return r;
    }
    gCourseMap->mUnk_40 = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mUnk_40 != 0) {
        gCourseMap->mUnk_3c = section;
    } else {
        gCourseMap->mUnk_3c = NULL;
    }
    return 1;
}

s32 LoadCourseMapCheckpointsData(void *section, ...) {
    u16 i;
    u16 j;

    gCourseMap->mCheckpointCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCheckpointCount == 0) {
        gCourseMap->mCheckpoints = NULL;
        return 1;
    }
    gCourseMap->mCheckpoints = section;
    j = 0;
    for (i = 0; i < gCourseMap->mCheckpointCount; i++) {
        if (gCourseMap->mCheckpoints[i].mNumber != -1) {
            j++;
        }
    }
    gCourseMap->mNumberedCheckpointCount = j;
    return 1;
}

s32 LoadCourseMapCheckpointRoutesData(void *section, ...) {
    s32 i;
    CourseMapRoute *routes;
    CourseMapRoute *lastRoute;
    s32 firstEntry;

    gCourseMap->mCheckpointRouteCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCheckpointRouteCount == 0) {
        gCourseMap->mCheckpointRoutes = NULL;
        gCourseMap->mLastCheckpoint = 0;
        return 1;
    }
    gCourseMap->mCheckpointRoutes = section;
    for (i = 0; i < gCourseMap->mCheckpointRouteCount; i++) {
        if (gCourseMap->mCheckpointRoutes[(u16) i].mFirstEntry == 0) {
            routes = gCourseMap->mCheckpointRoutes;
            lastRoute = &routes[(u16) (s8) routes[(u16) i].mPreviousRoutes[0]];
            firstEntry = routes[(u16) (s8) routes[(u16) i].mPreviousRoutes[0]].mFirstEntry;
            gCourseMap->mLastCheckpoint = firstEntry + lastRoute->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 LoadCourseMapItemPointsData(void *section, ...) {
    gCourseMap->mItemPointCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mItemPointCount == 0) {
        gCourseMap->mItemPoints = NULL;
    } else {
        gCourseMap->mItemPoints = section;
    }
    return 1;
}

s32 LoadCourseMapItemRoutesData(void *section, ...) {
    gCourseMap->mItemRouteCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mItemRouteCount == 0) {
        gCourseMap->mItemRoutes = NULL;
    } else {
        gCourseMap->mItemRoutes = section;
    }
    return 1;
}

s32 LoadCourseMapBattleOrRacePointsData(void *section, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattlePointCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mBattlePointCount == 0) {
            gCourseMap->mBattlePoints = NULL;
        } else {
            gCourseMap->mBattlePoints = section;
            gCourseMap->mRacePoints = NULL;
            gCourseMap->mRacePointCount = 0;
        }
    } else {
        gCourseMap->mRacePointCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mRacePointCount == 0) {
            gCourseMap->mRacePoints = NULL;
        } else {
            gCourseMap->mRacePoints = section;
            gCourseMap->mBattlePoints = NULL;
            gCourseMap->mBattlePointCount = 0;
        }
    }
    return 1;
}

s32 LoadCourseMapBattleOrRaceRoutesData(void *section, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattleRouteCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mBattleRouteCount == 0) {
            gCourseMap->mBattleRoutes = NULL;
        } else {
            gCourseMap->mBattleRoutes = section;
            gCourseMap->mRaceRoutes = NULL;
            gCourseMap->mRaceRouteCount = 0;
        }
    } else {
        gCourseMap->mRaceRouteCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mRaceRouteCount == 0) {
            gCourseMap->mRaceRoutes = NULL;
        } else {
            gCourseMap->mRaceRoutes = section;
            gCourseMap->mBattleRoutes = NULL;
            gCourseMap->mBattleRouteCount = 0;
        }
    }
    return 1;
}
#pragma thumb off

#pragma thumb on

CourseMapShape *GetCourseMapShape(u32 shapeIndex) {
    return &gCourseMap->mShapes[shapeIndex];
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapKind3ShapeLists(void) {
    void *heap;
    CourseMapShape *shape;
    CourseMapKind3ShapeNode **nodeSlot;
    u16 shapeIndex;
    u16 listIndex;

    heap = GetHeap(GetCurrentHeapCall());
    shapeIndex = 0;
    for (listIndex = 0; listIndex < 8; listIndex++) {
        gCourseMap->mKind3ShapeLists[listIndex] = NULL;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == 3) {
            nodeSlot = &gCourseMap->mKind3ShapeLists[(s16) shape->mUnk_3c];
            while (*nodeSlot != NULL) {
                nodeSlot = &(*nodeSlot)->mUnk_04;
            }
            *nodeSlot = HeapAlloc(heap, 8);
            (*nodeSlot)->mUnk_00 = shape;
            (*nodeSlot)->mUnk_04 = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

void CountCourseMapKind4Shapes(void) {
    u16 count;
    u16 i;
    count = 0;
    for (i = 0; i < gCourseMap->mShapeCount; i++) {
        if (GetCourseMapShape(i)->mKind == 4) {
            count++;
        }
    }
    gCourseMap->mKind4ShapeCount = count;
}

void CountCourseMapKind2ShapesInMode4(void) {
    u8 count;
    u16 i;
    count = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        for (i = 0; i < gCourseMap->mShapeCount; i++) {
            if (GetCourseMapShape(i)->mKind == 2) {
                count++;
            }
        }
    }
    gCourseMap->mKind2ShapeCountInMode4 = count;
}

#pragma thumb off

#pragma thumb on
s32 LoadCourseMapShapesData(void *section, ...) {
    gCourseMap->mShapeCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mShapeCount == 0) {
        gCourseMap->mShapes = NULL;
    } else {
        gCourseMap->mShapes = section;
    }
    BuildCourseMapKind3ShapeLists();
    CountCourseMapKind4Shapes();
    CountCourseMapKind2ShapesInMode4();
    return 1;
}

s32 LoadCourseMapCamerasData(void *section, ...) {
    u16 i;
    CourseMapCamera *e;

    gCourseMap->mCameraCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCameraCount == 0) {
        gCourseMap->mCameras = NULL;
        return 1;
    }
    gCourseMap->mCameras = section;
    gCourseMap->mFirstChainStartEntry = NULL;
    gCourseMap->mSecondChainStartEntry = NULL;
    gCourseMap->mFirstKind6Entry = NULL;
    gCourseMap->mFirstKind7EntryInMode2 = NULL;
    for (i = 0; i < gCourseMap->mCameraCount; i++) {
        e = gCourseMap->mCameras + i;
        if (gCourseMap->mFirstChainStartEntry == NULL && e->mChainStart == 1) {
            gCourseMap->mFirstChainStartEntry = e;
        }
        if (gCourseMap->mSecondChainStartEntry == NULL && e->mChainStart == 2) {
            gCourseMap->mSecondChainStartEntry = e;
        }
        if (gCourseMap->mFirstKind6Entry == NULL && e->mKind == 6) {
            gCourseMap->mFirstKind6Entry = e;
        }
        if (gRaceSetup->mMode == MODE_BATTLE && gCourseMap->mFirstKind7EntryInMode2 == NULL && e->mKind == 7) {
            gCourseMap->mFirstKind7EntryInMode2 = e;
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && gCourseMap->mFirstKind8EntryInMode4 == NULL && e->mKind == 8) {
            gCourseMap->mFirstKind8EntryInMode4 = e;
        }
    }
    return 1;
}

void CreateCourseMap(void *heap) {
    char path[0x100];
    CourseMapHeader *header;
    CourseMap *courseMap;
    s32 *offset;
    u8 *base;
    s32 sectionIndex;
    u16 routeIndex;

    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                header = FindCourseFile("/course_map.nkm");
            } else {
                snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", gRaceSetup->mMissionRunStem);
                header = FindCourseFile(path);
            }
            break;
        case 5:
            header = FindCourseFile("/Net/net_course_map.nkm");
            if (header == NULL) {
                header = FindCourseFile("/course_map.nkm");
            }
            break;
        default:
            header = FindCourseFile("/course_map.nkm");
            break;
    }
    courseMap = AllocCourseMap(heap);
    gCourseMap = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (sectionIndex = 0; sectionIndex < 17; sectionIndex++) {
        if (gCourseMapSectionLoaders[sectionIndex](base + *offset) != 0) {
            offset++;
        }
    }
    BuildCourseMapEntryGroupTable(heap);
    BuildCourseMapPointLinks(heap);
    gCourseMap->mLapProgressBaseMax = 0;
    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        if (gCourseMap->mCheckpointRoutes[routeIndex].mLapProgressBase > gCourseMap->mLapProgressBaseMax) {
            gCourseMap->mLapProgressBaseMax = gCourseMap->mCheckpointRoutes[routeIndex].mLapProgressBase;
        }
    }
}
#pragma thumb off
