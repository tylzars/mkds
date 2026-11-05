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
        gCourseMap->mGroupEntries = 0;
    } else {
        gCourseMap->mGroupEntries = (s32) a;
    }
    return 1;
}

static inline CourseMapCheckpoint *func_02043078_inline(u16 i) {
    return &gCourseMap->mCheckpoints[i];
}

s32 func_02043078(u16 a) {
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
        c = (e->mUnk_04)[m];
        if (c != -1 && c != 0) {
            s += func_02043078(c);
            n++;
        }
    }
    if (n != 0) {
        t += s / n;
    }
    return t;
}

void func_02043038(void) {
    u32 a;
    u32 b;

    a = 0;
    b = 0;
    if (gCourseMap->mStartPlacementCount <= 1) {
        a = func_02043078(0);
        b = a / 15000;
    }
    gCourseMap->mUnk_104 = a;
    gCourseMap->mUnk_108 = b;
}

void func_02042fd8(void *a) {
    CourseMap *g;
    Unk02175620_94 *t;
    u16 n;
    s32 d;
    u32 z;
    u16 i;
    CourseMapEntryGroup *r;

    g = gCourseMap;
    n = g->mEntryGroupCount;
    z = n << 3;
    d = g->mGroupEntries;
    if (z != 0) {
        t = HeapAlloc(a, z);
        gCourseMap->mUnk_94 = t;
        for (i = 0; i < n; i++) {
            r = gCourseMap->mEntryGroups + i;
            t->mUnk_00 = r;
            t->mUnk_04 = (void *) d;
            d += r->mEntryCount * 0x14;
            t++;
        }
    } else {
        g->mUnk_94 = NULL;
    }
    func_02043038();
}
#pragma thumb off

#pragma thumb on

u32 func_02042fc4(u32 p0) {
    return ((u32) gCourseMap->mUnk_94) + (((p0) << 3));
}

#pragma thumb off

#pragma thumb on
void func_02042ec0(Unk020f371c *a, CourseMapRoute *b, u16 c) {
    Unk02175620_54 *p;
    Unk020f371c *n;
    s32 i;
    s32 k;

    if (gCourseMap->mVersion < 0x21) {
        p = (Unk02175620_54 *) ((Unk02175620_54_10 *) gCourseMap->mUnk_54 + c);
    } else {
        p = gCourseMap->mUnk_54 + c;
    }
    n = gCourseMap->mUnk_ac + c;
    for (k = 0; k < 3; k++) {
        if (a != NULL && n->mUnk_0c[k] == a) {
            return;
        }
    }
    n->mUnk_18 = (Vec3 *) p;
    n->mUnk_1c = p->mUnk_0c;
    if (gCourseMap->mVersion < 0x21) {
        n->mUnk_20 = 0;
    } else {
        n->mUnk_20 = p->mUnk_10;
    }
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
    if (c < b->mFirstEntry + b->mEntryCount - 1) {
        func_02042ec0(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mUnk_04[k];
        if (i != 0xff && i != 0) {
            func_02042ec0(n, &gCourseMap->mUnk_5c[i], gCourseMap->mUnk_5c[i].mFirstEntry);
        }
    }
}

void func_02042e0c(void *a) {
    CourseMap *g;
    CourseMapRoute *d;
    Unk020f371c **q;
    s32 i;
    Unk020f371c *e;
    s32 k;
    s32 n;
    s32 m;
    CourseMapRoute *t;
    CourseMapRoute *h;

    g = gCourseMap;
    d = g->mUnk_5c;
    q = &g->mUnk_ac;
    g->mUnk_ac = HeapAlloc(a, g->mUnk_58 * 0x28);
    q[1] = g->mUnk_ac + d->mFirstEntry;
    for (i = 0; i < gCourseMap->mUnk_58; i++) {
        e = q[0] + i;
        for (k = 0; k < 3; k++) {
            e->mUnk_0c[k] = NULL;
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_24 = 0;
        e->mUnk_26 = 0;
        e->mUnk_18 = NULL;
        e->mUnk_20 = 0;
        e->mUnk_1c = 0;
    }
    t = gCourseMap->mUnk_5c;
    h = t + d->mUnk_07;
    m = t[d->mUnk_07].mFirstEntry;
    n = m + h->mEntryCount - 1;
    q[2] = q[0] + n;
    func_02042ec0(q[0] + n, d, d->mFirstEntry);
}

void func_02042d34(Unk02175620_a0 *a, CourseMapRoute *b, u16 c) {
    Unk02175620_a0 *n;
    s32 i;
    s32 k;
    Unk02175620_84 *p;

    p = gCourseMap->mUnk_64 + c;
    n = gCourseMap->mUnk_a0 + c;
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
        func_02042d34(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mUnk_04[k];
        if (i != 0xff) {
            func_02042d34(n, &gCourseMap->mUnk_6c[i], gCourseMap->mUnk_6c[i].mFirstEntry);
        }
    }
}

void func_02042c3c(void *a) {
    CourseMap *g;
    CourseMapRoute *d;
    Unk02175620_a0 **q;
    CourseMapRoute *t;
    s32 i;
    Unk02175620_a0 *e;
    s32 k;
    s32 n;

    g = gCourseMap;
    d = g->mUnk_6c;
    q = &g->mUnk_a0;
    g->mUnk_a0 = HeapAlloc(a, g->mUnk_68 * 0x28);
    q[1] = g->mUnk_a0 + d->mFirstEntry;
    for (i = 0; i < gCourseMap->mUnk_68; i++) {
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
    t = gCourseMap->mUnk_6c + d->mUnk_07;
    n = t->mFirstEntry + t->mEntryCount - 1;
    q[2] = q[0] + n;
    func_02042d34(q[0] + n, d, d->mFirstEntry);
    for (i = 0; i < gCourseMap->mUnk_70; i++) {
        t = gCourseMap->mUnk_6c + (u16) i;
        if (q[0][t->mFirstEntry].mUnk_24 == 0) {
            func_02042d34(NULL, t, t->mFirstEntry);
        }
    }
}

void func_02042a10(void *a) {
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
    r = g->mUnk_8c;
    q = &g->mUnk_b8;
    g->mUnk_b8 = HeapAlloc(a, g->mUnk_88 * 0x30);
    q[1] = g->mUnk_b8;
    q[2] = g->mUnk_b8 + gCourseMap->mUnk_88;
    for (i = 0; i < gCourseMap->mUnk_88; i++) {
        e = q[0] + i;
        for (k = 0; k < 8; k++) {
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_2c = 0;
        e->mUnk_20 = NULL;
        e->mUnk_28 = NULL;
        e->mUnk_24 = 0;
    }
    for (j = 0; j < gCourseMap->mUnk_88; j++) {
        s = gCourseMap->mUnk_84 + (u16) j;
        d = q[0] + j;
        n = 0;
        for (m = 0; m < gCourseMap->mUnk_90; m++) {
            t = gCourseMap->mUnk_8c;
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
        d->mUnk_20 = (Vec3 *) s;
        d->mUnk_24 = s->mUnk_0c;
        d->mUnk_28 = (s16 *) s->mUnk_10;
        d->mUnk_2c = n;
    }
}

void func_020429c8(void *a) {
    if (gCourseMap->mUnk_60 != 0) {
        func_02042e0c(a);
    }
    if (gCourseMap->mUnk_70 != 0) {
        func_02042c3c(a);
    } else if (gCourseMap->mUnk_90 != 0) {
        func_02042a10(a);
    }
}
#pragma thumb off

#pragma thumb on
u32 LoadCourseMapSettingsData(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0) + (4u);
    value0 = (u32) &gCourseMap;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    *(u32 *) ((value0) + 24u) = (u32) value1;
    value0 = 1u;
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
s32 LoadCourseMapStartPlacementsData(void *a, ...) {
    gCourseMap->mStartPlacementCount = ReadCourseMapSectionCount(&a);
    gCourseMap->mStartPlacements = (s32) a;
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

    h = GetHeap(func_020364e8());
    gCourseMap->mRespawnCount = ReadCourseMapSectionCount(&a);
    gCourseMap->mRespawns = a;
    if (data_021759c0->mMode == 2) {
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
        p->mUnk_00 = (s64) p->mUnk_08 * (s64) p->mUnk_00 + p->mUnk_10;
        if (n == 0) {
            t = p->mUnk_00 >> 32;
        } else {
            t = ((s64) (p->mUnk_00 >> 32) * (u32) n) >> 32;
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

void func_0204274c(void) {
    u16 n;
    u16 i;

    n = gCourseMap->mUnk_38;
    if (n == 0) {
        gCourseMap->mUnk_fc = NULL;
        return;
    }
    gCourseMap->mUnk_fc = HeapAlloc(GetHeap(func_020364e8()), n * 2);
    for (i = 0; i < n; i++) {
        gCourseMap->mUnk_fc[gCourseMap->mUnk_34[i].mUnk_1a] = i;
    }
}

s32 func_02042708(void *a, ...) {
    BOOL r = FALSE;

    if (gCourseMap->mVersion < 0x1f) {
        gCourseMap->mUnk_38 = 0;
        gCourseMap->mUnk_34 = NULL;
    } else {
        gCourseMap->mUnk_38 = ReadCourseMapSectionCount(&a);
        gCourseMap->mUnk_34 = a;
        r = TRUE;
    }
    func_0204274c();
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
            e = &t[(u16) (s8) t[(u16) i].mUnk_07];
            m = t[(u16) (s8) t[(u16) i].mUnk_07].mFirstEntry;
            gCourseMap->mLastCheckpoint = m + e->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 func_02042558(void *a, ...) {
    gCourseMap->mUnk_58 = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mUnk_58 == 0) {
        gCourseMap->mUnk_54 = NULL;
    } else {
        gCourseMap->mUnk_54 = a;
    }
    return 1;
}

s32 func_02042520(void *a, ...) {
    gCourseMap->mUnk_60 = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mUnk_60 == 0) {
        gCourseMap->mUnk_5c = NULL;
    } else {
        gCourseMap->mUnk_5c = a;
    }
    return 1;
}

s32 func_02042498(void *a, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mUnk_88 = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mUnk_88 == 0) {
            gCourseMap->mUnk_84 = NULL;
        } else {
            gCourseMap->mUnk_84 = a;
            gCourseMap->mUnk_64 = NULL;
            gCourseMap->mUnk_68 = 0;
        }
    } else {
        gCourseMap->mUnk_68 = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mUnk_68 == 0) {
            gCourseMap->mUnk_64 = NULL;
        } else {
            gCourseMap->mUnk_64 = a;
            gCourseMap->mUnk_84 = NULL;
            gCourseMap->mUnk_88 = 0;
        }
    }
    return 1;
}

s32 func_02042410(void *a, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mUnk_90 = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mUnk_90 == 0) {
            gCourseMap->mUnk_8c = NULL;
        } else {
            gCourseMap->mUnk_8c = a;
            gCourseMap->mUnk_6c = NULL;
            gCourseMap->mUnk_70 = 0;
        }
    } else {
        gCourseMap->mUnk_70 = ReadCourseMapSectionCount(&a);
        if (gCourseMap->mUnk_70 == 0) {
            gCourseMap->mUnk_6c = NULL;
        } else {
            gCourseMap->mUnk_6c = a;
            gCourseMap->mUnk_8c = NULL;
            gCourseMap->mUnk_90 = 0;
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

    h = GetHeap(func_020364e8());
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
    if (data_021759c0->mMode == 4) {
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
s32 func_02042280(void *a, ...) {
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

s32 func_02042170(void *a, ...) {
    u16 i;
    Unk02175620_7c *e;

    gCourseMap->mUnk_80 = ReadCourseMapSectionCount(&a);
    if (gCourseMap->mUnk_80 == 0) {
        gCourseMap->mUnk_7c = NULL;
        return 1;
    }
    gCourseMap->mUnk_7c = a;
    gCourseMap->mUnk_c4 = NULL;
    gCourseMap->mUnk_c8 = NULL;
    gCourseMap->mUnk_cc = NULL;
    gCourseMap->mUnk_d0 = NULL;
    for (i = 0; i < gCourseMap->mUnk_80; i++) {
        e = gCourseMap->mUnk_7c + i;
        if (gCourseMap->mUnk_c4 == NULL && e->mUnk_4a == 1) {
            gCourseMap->mUnk_c4 = e;
        }
        if (gCourseMap->mUnk_c8 == NULL && e->mUnk_4a == 2) {
            gCourseMap->mUnk_c8 = e;
        }
        if (gCourseMap->mUnk_cc == NULL && e->mKind == 6) {
            gCourseMap->mUnk_cc = e;
        }
        if (data_021759c0->mMode == 2 && gCourseMap->mUnk_d0 == NULL && e->mKind == 7) {
            gCourseMap->mUnk_d0 = e;
        }
        if (data_021759c0->mMode == 4 && gCourseMap->mUnk_d4 == NULL && e->mKind == 8) {
            gCourseMap->mUnk_d4 = e;
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

    switch (data_021759c0->mMode) {
        case 4:
            if (data_021759c0->mUnk_00c == 6) {
                header = FindCourseFile("/course_map.nkm");
            } else {
                snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", data_021759c0->mMissionRunStem);
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
    courseMap = AllocCourseMap((u32) a);
    gCourseMap = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (i = 0; i < 17; i++) {
        if (gCourseMapSectionLoaders[i](base + *offset) != 0) {
            offset++;
        }
    }
    func_02042fd8(a);
    func_020429c8(a);
    gCourseMap->mUnk_9c = 0;
    for (j = 0; j < gCourseMap->mCheckpointRouteCount; j++) {
        if (gCourseMap->mCheckpointRoutes[j].mUnk_0a > gCourseMap->mUnk_9c) {
            gCourseMap->mUnk_9c = gCourseMap->mCheckpointRoutes[j].mUnk_0a;
        }
    }
}
#pragma thumb off
