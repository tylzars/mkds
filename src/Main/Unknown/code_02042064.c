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
u16 ReadCourseMapSectionCount(void **a) {
    u32 *p;
    u16 v;

    *a = (u32 *) *a + 1;
    p = *a;
    v = *p;
    *a = p + 1;
    return v;
}

s32 LoadCourseMapRowsData(void *a, ...) {
    gCourseMap->mRowCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mRowCount == 0) {
        gCourseMap->mRows = NULL;
    } else {
        gCourseMap->mRows = a;
    }
    return 1;
}

s32 LoadCourseMapEntryGroupsData(void *a, ...) {
    gCourseMap->mEntryGroupCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mEntryGroupCount == 0) {
        gCourseMap->mEntryGroups = NULL;
    } else {
        gCourseMap->mEntryGroups = a;
    }
    return 1;
}

s32 LoadCourseMapGroupEntriesData(void *a, ...) {
    gCourseMap->mGroupEntryCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mGroupEntryCount == 0) {
        gCourseMap->mGroupEntries = NULL;
    } else {
        gCourseMap->mGroupEntries = a;
    }
    return 1;
}

static inline CourseMapCheckpoint *func_02043078_inline(u16 i) {
    return &gCourseMap->mCheckpoints[i];
}

// Sums mUnk_18 along the route, plus the average of the sums of the routes that follow it.
s32 ComputeCourseMapRouteCheckpointSum(u16 a) {
    u16 n;
    s32 s;
    CourseMapRoute *e;
    s32 t;
    u16 k;
    u16 m;
    s8 c;

    e = gCourseMap->mCheckpointRoutes + a;
    s = 0;
    n = 0;
    t = 0;
    for (k = 0; k < e->mEntryCount; k++) {
        t += func_02043078_inline(e->mFirstEntry + k)->mUnk_18;
    }
    for (m = 0; m < 3; m++) {
        c = (e->mNextRoutes)[m];
        if (c != -1 && c != 0) {
            s += ComputeCourseMapRouteCheckpointSum(c);
            n++;
        }
    }
    if (n != 0) {
        t += s / n;
    }
    return t;
}

// Both values are 0 on courses with more than one start placement.
void SetCourseMapCheckpointTotals(void) {
    u32 a;
    u32 b;

    a = 0;
    b = 0;
    if (gCourseMap->mStartPlacementCount <= 1) {
        a = ComputeCourseMapRouteCheckpointSum(0);
        b = a / 15000;
    }
    gCourseMap->mCheckpointSum = a;
    gCourseMap->mCheckpointSumQuotient = b;
}

void BuildCourseMapEntryGroupTable(void *a) {
    CourseMap *g;
    Unk02175620_94 *t;
    u16 n;
    Unk02042044 *d;
    u32 z;
    u16 i;
    CourseMapEntryGroup *r;

    g = gCourseMap;
    n = g->mEntryGroupCount;
    z = n << 3;
    d = g->mGroupEntries;
    if (z != 0) {
        t = HeapAlloc(a, z);
        gCourseMap->mEntryGroupTable = t;
        for (i = 0; i < n; i++) {
            r = gCourseMap->mEntryGroups + i;
            t->mGroup = r;
            t->mEntries = d;
            d += r->mEntryCount;
            t++;
        }
    } else {
        g->mEntryGroupTable = NULL;
    }
    SetCourseMapCheckpointTotals();
}
#pragma thumb off

#pragma thumb on

Unk02175620_94 *GetCourseMapEntryGroupTableRow(u32 p0) {
    return gCourseMap->mEntryGroupTable + p0;
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapItemRouteLinks(ItemPointLink *a, CourseMapRoute *b, u16 c) {
    Unk02175620_54 *p;
    ItemPointLink *n;
    s32 i;
    s32 k;

    if (gCourseMap->mVersion < 0x21) {
        p = (Unk02175620_54 *) ((Unk02175620_54_10 *) gCourseMap->mItemPoints + c);
    } else {
        p = gCourseMap->mItemPoints + c;
    }
    n = gCourseMap->mItemPointLinks + c;
    for (k = 0; k < 3; k++) {
        if (a != NULL && n->mPreviousLinks[k] == a) {
            return;
        }
    }
    n->mPointPos = &p->mPos;
    n->mUnk_1c = p->mUnk_0c;
    if (gCourseMap->mVersion < 0x21) {
        n->mUnk_20 = 0;
    } else {
        n->mUnk_20 = p->mUnk_10;
    }
    for (k = 0; k < 3; k++) {
        if (a->mNextLinks[k] == NULL) {
            a->mNextLinks[k] = n;
            a->mNextCount++;
            break;
        }
    }
    for (k = 0; k < 3; k++) {
        if (n->mPreviousLinks[k] == NULL) {
            n->mPreviousLinks[k] = a;
            n->mPreviousCount++;
            break;
        }
    }
    if (c < b->mFirstEntry + b->mEntryCount - 1) {
        BuildCourseMapItemRouteLinks(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mNextRoutes[k];
        if (i != 0xff && i != 0) {
            BuildCourseMapItemRouteLinks(n, &gCourseMap->mItemRoutes[i], gCourseMap->mItemRoutes[i].mFirstEntry);
        }
    }
}

void BuildCourseMapItemPointLinks(void *a) {
    CourseMap *g;
    CourseMapRoute *d;
    ItemPointLink **q;
    s32 i;
    ItemPointLink *e;
    s32 k;
    s32 n;
    s32 m;
    CourseMapRoute *t;
    CourseMapRoute *h;

    g = gCourseMap;
    d = g->mItemRoutes;
    q = &g->mItemPointLinks;
    g->mItemPointLinks = HeapAlloc(a, g->mItemPointCount * 0x28);
    q[1] = g->mItemPointLinks + d->mFirstEntry;
    for (i = 0; i < gCourseMap->mItemPointCount; i++) {
        e = q[0] + i;
        for (k = 0; k < 3; k++) {
            e->mPreviousLinks[k] = NULL;
            e->mNextLinks[k] = NULL;
        }
        e->mNextCount = 0;
        e->mPreviousCount = 0;
        e->mPointPos = NULL;
        e->mUnk_20 = 0;
        e->mUnk_1c = 0;
    }
    t = gCourseMap->mItemRoutes;
    h = t + d->mPreviousRoutes[0];
    m = t[d->mPreviousRoutes[0]].mFirstEntry;
    n = m + h->mEntryCount - 1;
    q[2] = q[0] + n;
    BuildCourseMapItemRouteLinks(q[0] + n, d, d->mFirstEntry);
}

void BuildCourseMapRaceRouteLinks(Unk02175620_a0 *a, CourseMapRoute *b, u16 c) {
    Unk02175620_a0 *n;
    s32 i;
    s32 k;
    Unk02175620_84 *p;

    p = gCourseMap->mRacePoints + c;
    n = gCourseMap->mRacePointLinks + c;
    for (k = 0; k < 3; k++) {
        if (a != NULL && n->mUnk_0c[k] == a) {
            return;
        }
    }
    n->mUnk_18 = p;
    n->mUnk_1c = p->mUnk_0c;
    n->mUnk_20 = p->mUnk_10;
    if (a != NULL) {
        for (k = 0; k < 3; k++) {
            if (a->mUnk_00[k] == NULL) {
                a->mUnk_00[k] = n;
                a->mUnk_24++;
                break;
            }
        }
        for (k = 0; k < 3; k++) {
            if (n->mUnk_0c[k] == NULL) {
                n->mUnk_0c[k] = a;
                n->mUnk_26++;
                break;
            }
        }
    }
    if (c < b->mFirstEntry + b->mEntryCount - 1) {
        BuildCourseMapRaceRouteLinks(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mNextRoutes[k];
        if (i != 0xff) {
            BuildCourseMapRaceRouteLinks(n, &gCourseMap->mRaceRoutes[i], gCourseMap->mRaceRoutes[i].mFirstEntry);
        }
    }
}

void BuildCourseMapRacePointLinks(void *a) {
    CourseMap *g;
    CourseMapRoute *d;
    Unk02175620_a0 **q;
    CourseMapRoute *t;
    s32 i;
    Unk02175620_a0 *e;
    s32 k;
    s32 n;

    g = gCourseMap;
    d = g->mRaceRoutes;
    q = &g->mRacePointLinks;
    g->mRacePointLinks = HeapAlloc(a, g->mRacePointCount * 0x28);
    q[1] = g->mRacePointLinks + d->mFirstEntry;
    for (i = 0; i < gCourseMap->mRacePointCount; i++) {
        e = q[0] + i;
        for (k = 0; k < 3; k++) {
            e->mUnk_0c[k] = NULL;
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_24 = 0;
        e->mUnk_26 = 0;
        e->mUnk_18 = NULL;
        e->mUnk_20 = NULL;
        e->mUnk_1c = 0;
    }
    t = gCourseMap->mRaceRoutes + d->mPreviousRoutes[0];
    n = t->mFirstEntry + t->mEntryCount - 1;
    q[2] = q[0] + n;
    BuildCourseMapRaceRouteLinks(q[0] + n, d, d->mFirstEntry);
    for (i = 0; i < gCourseMap->mRaceRouteCount; i++) {
        t = gCourseMap->mRaceRoutes + (u16) i;
        if (q[0][t->mFirstEntry].mUnk_24 == 0) {
            BuildCourseMapRaceRouteLinks(NULL, t, t->mFirstEntry);
        }
    }
}

void BuildCourseMapBattlePointLinks(void *a) {
    CourseMap *g;
    Unk02175620_8c *r;
    Unk02175620_8c *t;
    Unk02175620_bc **q;
    s32 i;
    Unk02175620_bc *e;
    Unk02175620_bc *d;
    s32 j;
    s32 k;
    u16 m;
    u16 n;
    u16 h;
    Unk02175620_84 *s;
    u16 b;
    u16 c;

    g = gCourseMap;
    r = g->mBattleRoutes;
    q = &g->mBattlePointLinks;
    g->mBattlePointLinks = HeapAlloc(a, g->mBattlePointCount * 0x30);
    q[1] = g->mBattlePointLinks;
    q[2] = g->mBattlePointLinks + gCourseMap->mBattlePointCount;
    for (i = 0; i < gCourseMap->mBattlePointCount; i++) {
        e = q[0] + i;
        for (k = 0; k < 8; k++) {
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_2c = 0;
        e->mUnk_20 = NULL;
        e->mUnk_28 = NULL;
        e->mUnk_24 = 0;
    }
    for (j = 0; j < gCourseMap->mBattlePointCount; j++) {
        s = gCourseMap->mBattlePoints + (u16) j;
        d = q[0] + j;
        n = 0;
        for (m = 0; m < gCourseMap->mBattleRouteCount; m++) {
            t = gCourseMap->mBattleRoutes;
            r = t + m;
            if (j >= t[m].mUnk_00 && j < r->mUnk_00 + r->mUnk_02) {
                break;
            }
        }
        d->mUnk_2e = 0;
        h = r->mUnk_00 + r->mUnk_02 - 1;
        if (j == r->mUnk_00) {
            for (b = 0; b < 8; b++) {
                if (r->mUnk_0c[b] != 0xff) {
                    d->mUnk_2e |= 1 << n;
                    d->mUnk_00[n++] = q[0] + r->mUnk_0c[b];
                }
            }
            if (r->mUnk_02 > 1) {
                d->mUnk_00[n++] = d + 1;
            }
        }
        if (j == h) {
            for (c = 0; c < 8; c++) {
                if (r->mUnk_04[c] != 0xff) {
                    d->mUnk_2e |= 1 << n;
                    d->mUnk_00[n++] = q[0] + r->mUnk_04[c];
                }
            }
            if (r->mUnk_02 > 1) {
                d->mUnk_00[n++] = d - 1;
            }
        }
        if (j != r->mUnk_00 && j != h) {
            n = 0;
            d->mUnk_00[n++] = d + 1;
            d->mUnk_00[n++] = d - 1;
        }
        d->mUnk_20 = &s->mPos;
        d->mUnk_24 = s->mUnk_0c;
        d->mUnk_28 = s->mUnk_10;
        d->mUnk_2c = n;
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
s32 LoadCourseMapStartPlacementsData(void *a, ...) {
    gCourseMap->mStartPlacementCount = ReadCourseMapSectionCount(&a);
    gCourseMap->mStartPlacements = a;
    return 1;
}

s32 LoadCourseMapRespawnsData(void *a, ...) {
    s32 i;
    s32 m;
    void *h;
    s32 n;
    s32 k;
    u16 t;
    CourseMapRespawn *p;

    h = GetHeap(GetCurrentHeapCall());
    gCourseMap->mRespawnCount = ReadCourseMapSectionCount(&a);
    gCourseMap->mRespawns = a;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        n = gCourseMap->mRespawnCount;
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(h, n * 2);
        gCourseMap->mNextRespawnSlot = 0;
        for (i = 0; i < n; i++) {
            gCourseMap->mRespawnIndexBySlot[i] = i;
        }
    } else if (gCourseMap->mRespawnCount != 0) {
        m = 0;
        for (k = 0; k < gCourseMap->mRespawnCount; k++) {
            p = &gCourseMap->mRespawns[k];
            if (p->mSlot > m) {
                m = p->mSlot;
            }
        }
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(h, (m + 1) * 2);
        for (i = 0; i < m + 1; i++) {
            gCourseMap->mRespawnIndexBySlot[i] = 0xffff;
        }
        for (i = 0; i < gCourseMap->mRespawnCount; i++) {
            gCourseMap->mRespawnIndexBySlot[gCourseMap->mRespawns[i].mSlot] = i;
        }
    }
    return 1;
}

static inline u16 func_020427d4_inline(Unk020f41c4_B *p, u16 n) {
    u32 t;
    if (n == 0) {
        t = 0;
    } else {
        p->mValue = (s64) p->mMultiplier * (s64) p->mValue + p->mIncrement;
        if (n == 0) {
            t = p->mValue >> 32;
        } else {
            t = ((s64) (p->mValue >> 32) * (u32) n) >> 32;
        }
    }
    return t;
}

void ShuffleCourseMapRespawnSlots(Unk020f41c4_B *a) {
    s32 i;
    u16 n;
    u16 x;
    u16 y;
    u16 t;

    n = gCourseMap->mRespawnCount;
    for (i = 0; i < 100; i++) {
        x = func_020427d4_inline(a, n);
        y = func_020427d4_inline(a, n);
        t = gCourseMap->mRespawnIndexBySlot[y];
        gCourseMap->mRespawnIndexBySlot[y] = gCourseMap->mRespawnIndexBySlot[x];
        gCourseMap->mRespawnIndexBySlot[x] = t;
    }
}

s32 func_020427ac(void *a, ...) {
    gCourseMap->mUnk_30 = ReadCourseMapSectionCount(&a);
    gCourseMap->mUnk_2c = a;
    return 1;
}

void BuildCourseMapKeyedPlacementIndexByKey(void) {
    u16 n;
    u16 i;

    n = gCourseMap->mKeyedPlacementCount;
    if (n == 0) {
        gCourseMap->mKeyedPlacementIndexByKey = NULL;
        return;
    }
    gCourseMap->mKeyedPlacementIndexByKey = HeapAlloc(GetHeap(GetCurrentHeapCall()), n * 2);
    for (i = 0; i < n; i++) {
        gCourseMap->mKeyedPlacementIndexByKey[gCourseMap->mKeyedPlacements[i].mKey] = i;
    }
}

s32 LoadCourseMapKeyedPlacementsData(void *a, ...) {
    BOOL r = FALSE;

    if (gCourseMap->mVersion < 0x1f) {
        gCourseMap->mKeyedPlacementCount = 0;
        gCourseMap->mKeyedPlacements = NULL;
    } else {
        gCourseMap->mKeyedPlacementCount = ReadCourseMapSectionCount(&a);
        gCourseMap->mKeyedPlacements = a;
        r = TRUE;
    }
    BuildCourseMapKeyedPlacementIndexByKey();
    return r;
}

s32 func_020426ac(void *a, ...) {
    enum { K0 } r = 0;

    if (gCourseMap->mVersion < 0x24) {
        gCourseMap->mUnk_40 = r;
        gCourseMap->mUnk_3c = NULL;
        return r;
    }
    gCourseMap->mUnk_40 = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mUnk_40 != 0) {
        gCourseMap->mUnk_3c = a;
    } else {
        gCourseMap->mUnk_3c = NULL;
    }
    return 1;
}

s32 LoadCourseMapCheckpointsData(void *a, ...) {
    u16 i;
    u16 j;

    gCourseMap->mCheckpointCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mCheckpointCount == 0) {
        gCourseMap->mCheckpoints = NULL;
        return 1;
    }
    gCourseMap->mCheckpoints = a;
    j = 0;
    for (i = 0; i < gCourseMap->mCheckpointCount; i++) {
        if (gCourseMap->mCheckpoints[i].mNumber != -1) {
            j++;
        }
    }
    gCourseMap->mNumberedCheckpointCount = j;
    return 1;
}

s32 LoadCourseMapCheckpointRoutesData(void *a, ...) {
    s32 i;
    CourseMapRoute *t;
    CourseMapRoute *e;
    s32 m;

    gCourseMap->mCheckpointRouteCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mCheckpointRouteCount == 0) {
        gCourseMap->mCheckpointRoutes = NULL;
        gCourseMap->mLastCheckpoint = 0;
        return 1;
    }
    gCourseMap->mCheckpointRoutes = a;
    for (i = 0; i < gCourseMap->mCheckpointRouteCount; i++) {
        if (gCourseMap->mCheckpointRoutes[(u16) i].mFirstEntry == 0) {
            t = gCourseMap->mCheckpointRoutes;
            e = &t[(u16) (s8) t[(u16) i].mPreviousRoutes[0]];
            m = t[(u16) (s8) t[(u16) i].mPreviousRoutes[0]].mFirstEntry;
            gCourseMap->mLastCheckpoint = m + e->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 LoadCourseMapItemPointsData(void *a, ...) {
    gCourseMap->mItemPointCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mItemPointCount == 0) {
        gCourseMap->mItemPoints = NULL;
    } else {
        gCourseMap->mItemPoints = a;
    }
    return 1;
}

s32 LoadCourseMapItemRoutesData(void *a, ...) {
    gCourseMap->mItemRouteCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mItemRouteCount == 0) {
        gCourseMap->mItemRoutes = NULL;
    } else {
        gCourseMap->mItemRoutes = a;
    }
    return 1;
}

s32 LoadCourseMapBattleOrRacePointsData(void *a, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattlePointCount = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mBattlePointCount == 0) {
            gCourseMap->mBattlePoints = NULL;
        } else {
            gCourseMap->mBattlePoints = a;
            gCourseMap->mRacePoints = NULL;
            gCourseMap->mRacePointCount = 0;
        }
    } else {
        gCourseMap->mRacePointCount = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mRacePointCount == 0) {
            gCourseMap->mRacePoints = NULL;
        } else {
            gCourseMap->mRacePoints = a;
            gCourseMap->mBattlePoints = NULL;
            gCourseMap->mBattlePointCount = 0;
        }
    }
    return 1;
}

s32 LoadCourseMapBattleOrRaceRoutesData(void *a, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattleRouteCount = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mBattleRouteCount == 0) {
            gCourseMap->mBattleRoutes = NULL;
        } else {
            gCourseMap->mBattleRoutes = a;
            gCourseMap->mRaceRoutes = NULL;
            gCourseMap->mRaceRouteCount = 0;
        }
    } else {
        gCourseMap->mRaceRouteCount = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mRaceRouteCount == 0) {
            gCourseMap->mRaceRoutes = NULL;
        } else {
            gCourseMap->mRaceRoutes = a;
            gCourseMap->mBattleRoutes = NULL;
            gCourseMap->mBattleRouteCount = 0;
        }
    }
    return 1;
}
#pragma thumb off

#pragma thumb on

CourseMapShape *GetCourseMapShape(u32 a) {
    return &gCourseMap->mShapes[a];
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapKind3ShapeLists(void) {
    void *h;
    CourseMapShape *e;
    Unk02175620_d8 **q;
    u16 i;
    u16 j;

    h = GetHeap(GetCurrentHeapCall());
    i = 0;
    for (j = 0; j < 8; j++) {
        gCourseMap->mKind3ShapeLists[j] = NULL;
    }
    for (i = 0; i < gCourseMap->mShapeCount; i++) {
        e = GetCourseMapShape(i);
        if (e->mKind == 3) {
            q = &gCourseMap->mKind3ShapeLists[(s16) e->mUnk_3c];
            while (*q != NULL) {
                q = &(*q)->mUnk_04;
            }
            *q = HeapAlloc(h, 8);
            (*q)->mUnk_00 = e;
            (*q)->mUnk_04 = NULL;
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
s32 LoadCourseMapShapesData(void *a, ...) {
    gCourseMap->mShapeCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mShapeCount == 0) {
        gCourseMap->mShapes = NULL;
    } else {
        gCourseMap->mShapes = a;
    }
    BuildCourseMapKind3ShapeLists();
    CountCourseMapKind4Shapes();
    CountCourseMapKind2ShapesInMode4();
    return 1;
}

s32 LoadCourseMapCamerasData(void *a, ...) {
    u16 i;
    Unk02175620_7c *e;

    gCourseMap->mCameraCount = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mCameraCount == 0) {
        gCourseMap->mCameras = NULL;
        return 1;
    }
    gCourseMap->mCameras = a;
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

void CreateCourseMap(void *a) {
    char path[0x100];
    CourseMapHeader *header;
    CourseMap *courseMap;
    s32 *offset;
    u8 *base;
    s32 i;
    u16 j;

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
    courseMap = AllocCourseMap(a);
    gCourseMap = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (i = 0; i < 17; i++) {
        if (gCourseMapSectionLoaders[i](base + *offset) != 0) {
            offset++;
        }
    }
    BuildCourseMapEntryGroupTable(a);
    BuildCourseMapPointLinks(a);
    gCourseMap->mLapProgressBaseMax = 0;
    for (j = 0; j < gCourseMap->mCheckpointRouteCount; j++) {
        if (gCourseMap->mCheckpointRoutes[j].mLapProgressBase > gCourseMap->mLapProgressBaseMax) {
            gCourseMap->mLapProgressBaseMax = gCourseMap->mCheckpointRoutes[j].mLapProgressBase;
        }
    }
}
#pragma thumb off
