#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_020e662c.h"
#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020e6fc4.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline GrpconfTblRow *func_020d34e4_inline(u16 f) {
    s32 j;
    for (j = 0; j < 1000; j++) {
        if (f == gGrpconfTbl[j].mUnk_00) {
            return &gGrpconfTbl[j];
        }
    }
    return NULL;
}

MapObject *CreateMapObject(u32 kind, CourseMapRow *courseRow, MapObject *source) {
    s32 i;
    s32 j;
    MapObjectKindRow *row;
    Unk021000d0 *a;
    Unk021000d0 *o;
    MapObjectKindData *kindData;
    GrpconfTblRow *t;
    MapObject *object;
    s32 v;
    u32 m;
    for (i = 0; i < data_0217b4ec; i++) {
        {
            row = &data_0216b288[i];
            if (kind != row->mKind) {
                continue;
            }
            a = row->mUnk_04;
            if (a->mObjectCount == 0) {
                for (j = 0; j < data_0217b4ec; j++) {
                    o = data_0216b288[j].mUnk_04;
                    if (o == NULL) {
                        continue;
                    }
                    if (o->mCreateDrawList0 == a->mCreateDrawList0 && o->mLists[0] != NULL) {
                        a->mLists[0] = o->mLists[0];
                    }
                    if (o->mCreateDrawList0 == a->mCreateDrawList1 && o->mLists[0] != NULL) {
                        a->mLists[1] = o->mLists[0];
                    }
                    if (o->mCreateDrawList0 == a->mCreateDrawList2 && o->mLists[0] != NULL) {
                        a->mLists[2] = o->mLists[0];
                    }
                    if (o->mCreateDrawList1 == a->mCreateDrawList0 && o->mLists[1] != NULL) {
                        a->mLists[0] = o->mLists[1];
                    }
                    if (o->mCreateDrawList1 == a->mCreateDrawList1 && o->mLists[1] != NULL) {
                        a->mLists[1] = o->mLists[1];
                    }
                    if (o->mCreateDrawList1 == a->mCreateDrawList2 && o->mLists[1] != NULL) {
                        a->mLists[2] = o->mLists[1];
                    }
                    if (o->mCreateDrawList2 == a->mCreateDrawList0 && o->mLists[2] != NULL) {
                        a->mLists[0] = o->mLists[2];
                    }
                    if (o->mCreateDrawList2 == a->mCreateDrawList1 && o->mLists[2] != NULL) {
                        a->mLists[1] = o->mLists[2];
                    }
                    if (o->mCreateDrawList2 == a->mCreateDrawList2 && o->mLists[2] != NULL) {
                        a->mLists[2] = o->mLists[2];
                    }
                    if (o->mCreateUpdateList == a->mCreateUpdateList && o->mLists[3] != NULL) {
                        a->mLists[3] = o->mLists[3];
                    }
                }
                if (a->mKindData == NULL && a->mCreateKindData != NULL) {
                    a->mKindData = a->mCreateKindData();
                    if (a->mKindData == NULL) {
                        return NULL;
                    }
                    if (a->mKindData->mUnk_24 == 0) {
                        a->mKindData->mUnk_24 = -1;
                    }
                    if (a->mKindData->mUnk_28 == 0) {
                        a->mKindData->mUnk_28 = -1;
                    }
                    if (a->mKindData->mUnk_38 == 0) {
                        a->mKindData->mUnk_38 = 0x64000;
                    }
                    if (a->mKindData->mUnk_3c == 0) {
                        a->mKindData->mUnk_3c = -0x64000;
                    }
                    if (gRaceSetup->mUnk_00c == 2) {
                        if (a->mKindData->mUnk_38 < 0x44c000) {
                            a->mKindData->mUnk_38 = 0x44c000;
                        }
                    }
                }
                t = func_020d34e4_inline(row->mKind);
                if (t->mUnk_02 != 0) {
                    a->mKindData->mUnk_34 = t->mUnk_02 >= 2 ? 1 : 0;
                    v = t->mUnk_04;
                    a->mKindData->mUnk_2c = v != 0 ? (v << 12) + 0.5f : (v << 12) - 0.5f;
                    v = t->mUnk_06;
                    a->mKindData->mUnk_30 = v != 0 ? (v << 12) + 0.5f : (v << 12) - 0.5f;
                }
                if (t->mUnk_08 != 0) {
                    a->mKindData->mUnk_08 = t->mUnk_08;
                    v = t->mUnk_0a;
                    a->mKindData->mUnk_0c = v != 0 ? (v << 12) + 0.5f : (v << 12) - 0.5f;
                    v = t->mUnk_0c;
                    a->mKindData->mUnk_10 = v != 0 ? (v << 12) + 0.5f : (v << 12) - 0.5f;
                    v = t->mUnk_0e;
                    a->mKindData->mUnk_14 = v != 0 ? (v << 12) + 0.5f : (v << 12) - 0.5f;
                }
                if (a->mLists[0] == NULL && a->mCreateDrawList0 != NULL) {
                    a->mLists[0] = a->mCreateDrawList0();
                }
                if (a->mLists[1] == NULL && a->mCreateDrawList1 != NULL) {
                    a->mLists[1] = a->mCreateDrawList1();
                }
                if (a->mLists[2] == NULL && a->mCreateDrawList2 != NULL) {
                    a->mLists[2] = a->mCreateDrawList2();
                }
                if (a->mLists[3] == NULL && a->mCreateUpdateList != NULL) {
                    a->mLists[3] = a->mCreateUpdateList();
                }
            }
            if (a == NULL) {
                continue;
            }
            kindData = a->mKindData;
            object = HeapAlloc(GetHeap(func_020364e8()), a->mObjectSize);
            a->mObjectCount++;
            if (courseRow != NULL) {
                object->mCourseMapRow = courseRow;
            } else if (source != NULL) {
                object->mCourseMapRow = source->mCourseMapRow;
            }
            object->mKind = kind;
            object->mFlags = 0;
            if (data_0217b4e0 != 0) {
                object->mFlags |= data_021568c8;
            }
            object->mCollisionSlotIndex = -1;
            if (courseRow != NULL) {
                object->mPos.x = courseRow->mUnk_00.x;
                object->mPos.y = courseRow->mUnk_00.y;
                object->mPos.z = courseRow->mUnk_00.z;
            } else if (source != NULL) {
                object->mPos.x = source->mPos.x;
                object->mPos.y = source->mPos.y;
                object->mPos.z = source->mPos.z;
            }
            if (kindData->mUnk_20 == 0 || kindData->mUnk_20 == 2) {
                object->mUnk_10.x = 0;
                object->mUnk_10.y = 0;
                object->mUnk_10.z = 0;
            } else {
                object->mUnk_10.x = 0x270f000;
                object->mUnk_10.y = 0x270f000;
                object->mUnk_10.z = 0x270f000;
            }
            if (courseRow != NULL) {
                object->mAngle = ((s64) courseRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44;
                Matrix3x3FromVec3Degrees(&courseRow->mUnk_0c, (s32 *) &object->mMatrix);
            } else if (source != NULL) {
                object->mAngle = source->mAngle;
                object->mMatrix = source->mMatrix;
            }
            object->mKindData = kindData;
            if (courseRow != NULL) {
                SetMapObjectScale(object, &courseRow->mUnk_18);
            } else {
                SetMapObjectScale(object, &source->mScale);
            }
            func_020d24d8(object, kindData->mUnk_30);
            object->mUseTwoPlaneViewTest = kindData->mUnk_34;
            if (kindData->mUnk_08 != 0) {
                object->mFlags &= ~1;
            } else {
                object->mFlags |= data_021568cc;
            }
            if (kindData->mUnk_1c != 0) {
                object->mFlags &= ~0x40;
            } else {
                object->mFlags |= data_021568d0;
            }
            if ((a->mLists[0] != NULL && a->mLists[0]->mForEachObject != NULL) ||
                (a->mLists[1] != NULL && a->mLists[1]->mForEachObject != NULL) ||
                (a->mLists[2] != NULL && a->mLists[2]->mForEachObject != NULL)) {
                object->mFlags &= ~2;
                object->mFlags &= ~8;
                object->mAlpha = 0x1f;
            } else {
                object->mFlags |= data_021568d4;
                object->mFlags |= data_021568d8;
            }
            if (source != NULL) {
                object->mDigitMask = source->mDigitMask;
                object->mFlags |= source->mFlags & 0x80;
            } else if (courseRow != NULL) {
                if (courseRow->mUnk_36 != 0) {
                    SetMapObjectMaskAndFlagFromNumber(courseRow->mUnk_36, object);
                }
            }
            if (a->mLists[3] != NULL && a->mLists[3]->mForEachObject != NULL) {
                object->mFlags &= ~4;
            } else {
                object->mFlags |= data_021568dc;
            }
            object->mFarDistanceSquared = gSoundFalloffs[2].mUnk_20;
            if (courseRow != NULL) {
                if (a->mInitObject != NULL) {
                    a->mInitObject(object, courseRow, data_0216b288[i].mUnk_08);
                }
            } else if (source != NULL) {
                if (a->mInitObject != NULL) {
                    a->mInitObject(object, NULL, source);
                }
            }
            if (kindData->mUnk_08 != 0) {
                m = 0x2000;
                if (kindData->mUnk_20 == 0) {
                    m |= data_021568e0;
                }
                if (IsKoopaBlockKind(object->mKind) != 0 || func_020e4320(object->mKind) != FALSE ||
                    func_020e3af0(object->mKind) != FALSE || func_020ffabc(object->mKind) != FALSE) {
                    m |= data_021568e4;
                }
                object->mCollisionSlotIndex = func_020d555c(&object->mPos, func_020d252c(object), m, object);
            }
            j = gMapObjects->mMapObjectCount;
            gMapObjects->mMapObjectCount = j + 1;
            gMapObjects->mMapObjects[j] = object;
            if (gMapObjects->mMapObjectCount >= 0x100) {
                gMapObjects->mMapObjectCount = 0xff;
            }
            return object;
        }
    }
    return NULL;
}

MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind) {
    return CreateMapObject(kind, NULL, source);
}

MapObject *CreateMapObjectFromCourseMapRow(CourseMapRow *courseRow, s32 kind) {
    return CreateMapObject(kind, courseRow, NULL);
}

void InitMapObjects(void) {
    void *h;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    s32 c1;
    s32 c2;
    s32 s1;
    s32 s2;
    s32 k;
    s32 t;
    s32 g;
    u32 v;
    MapObjectKindRow *row;
    Unk021000d0 *d;
    CourseMapRow *e;
    MapObject *o;
    MapObjectList *w[3];
    MapObjectList *x;
    MapObjectList **y;
    MapObjects *q;
    h = GetHeap(func_020364e8());
    func_020d22e0();
    data_0217b4cc = func_02061788();
    data_0217b4c0 = data_0217b4cc + 9;
    data_0217b4c8 = data_0217b4c0 + 1;
    n = gCourseMap->mRowCount;
    gMapObjects = HeapAlloc(h, 0x2bc);
    gMapObjects->mMapObjects = HeapAlloc(h, 0x400);
    data_0217b4e8 = HeapAlloc(h, 0x80);
    data_0217b4dc = HeapAlloc(h, 0x180);
    gMapObjects->mMapObjectCount = 0;
    gMapObjects->mUnk_130 = FALSE;
    gMapObjects->mUnk_178 = FALSE;
    v = 0;
    if (gRaceSetup->mMode != 5) {
        v = 1;
    }
    gMapObjects->mRunUpdateLists = v;
    data_0217b4ec = 0;
    do {
        row = &data_0216b288[data_0217b4ec];
        d = row->mUnk_04;
        if (row->mKind == 0) {
            break;
        }
        if (data_0217aa10->mUnk_00 != 1 && func_02059c04(d) != 0) {
            break;
        }
        if (d != NULL) {
            d->mKindData = NULL;
            d->mLists[0] = NULL;
            d->mLists[1] = NULL;
            d->mLists[2] = NULL;
            d->mLists[3] = NULL;
        }
        data_0217b4ec++;
    } while (data_0217b4ec < 0x85);
    gGrpconfTbl = FindMainRaceOrMainEffectFile("MapObj/grpconf.tbl");
    v = 1;
    if (gRaceSetup->mMode != MODE_TIME_ATTACK && gRaceSetup->mMode != 5) {
        v = 0;
    }
    data_0217b4e0 = v;
    gMapObjects->mUnk_17c = 0;
    gMapObjects->mUnk_180 = 0;
    gMapObjects->mUnk_184 = 0;
    gMapObjects->mUnk_188 = 0;
    gCourseWater = NULL;
    gCourseWaterEfct = NULL;
    ClearOrthoQuadCreamEffectPointer();
    func_020d7df8();
    InitMatrices();
    func_020d4bf0();
    data_0217b4c4 = data_0217b4c8;
    data_0217b4d0 = data_0217b4cc;
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 != NULL) {
            data_0216b288[i].mUnk_04->mObjectCount = 0;
        }
    }
    for (i = 0; i < n; i++) {
        e = OFFSET_PTR(CourseMapRow, gCourseMap->mRows, i * sizeof(CourseMapRow));
        if (gRaceSetup->mMode == MODE_TIME_ATTACK && (e->mUnk_38 & 1) == 0) {
            continue;
        }
        CreateMapObject(e->mUnk_24, e, NULL);
        gMapObjects->mUnk_17c |= IsKoopaBlockKind(e->mUnk_24);
        gMapObjects->mUnk_180 |= func_020e4320(e->mUnk_24);
        gMapObjects->mUnk_184 |= func_020e3af0(e->mUnk_24);
        gMapObjects->mUnk_188 |= func_020ffabc(e->mUnk_24);
    }
    if (gMapObjects->mUnk_17c != 0 || gMapObjects->mUnk_180 != 0 || gMapObjects->mUnk_184 != 0 ||
        gMapObjects->mUnk_188 != 0) {
        data_0217b610 = 1;
    }
    func_02105214();
    gMapObjects->mDrawListCount = 0;
    for (m = 0; m < 24; m++) {
        gMapObjects->mDrawLists[m] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        w[0] = data_0216b288[i].mUnk_04->mLists[0];
        w[1] = data_0216b288[i].mUnk_04->mLists[1];
        w[2] = data_0216b288[i].mUnk_04->mLists[2];
        for (j = 0; j < 3; j++) {
            s32 g;
            if (w[j] == NULL) {
                continue;
            }
            g = 1;
            for (m = 0; m < gMapObjects->mDrawListCount; m++) {
                if (gMapObjects->mDrawLists[m] == w[j]) {
                    func_020d4a10(w[j], v);
                    g = 0;
                }
            }
            if (g != 0) {
                ClearMapObjectList(w[j]);
                if (v != 0) {
                    func_020d4a10(w[j], v);
                    gMapObjects->mDrawLists[gMapObjects->mDrawListCount++] = w[j];
                }
            }
        }
    }
    for (i = 0; i < gMapObjects->mDrawListCount; i++) {
        InitMapObjectDrawList(gMapObjects->mDrawLists[i]);
    }
    for (i = 0; i < gMapObjects->mMapObjectCount; i++) {
        o = gMapObjects->mMapObjects[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mKind == data_0216b288[j].mKind) {
                w[0] = data_0216b288[j].mUnk_04->mLists[0];
                w[1] = data_0216b288[j].mUnk_04->mLists[1];
                w[2] = data_0216b288[j].mUnk_04->mLists[2];
                if (w[0] != NULL) {
                    AddMapObjectToDrawList(w[0], o);
                }
                if (w[1] != NULL) {
                    AddMapObjectToDrawList(w[1], o);
                }
                if (w[2] != NULL) {
                    AddMapObjectToDrawList(w[2], o);
                }
            }
        }
    }
    for (i = 0; i < gMapObjects->mDrawListCount; i++) {
        func_020d4990(gMapObjects->mDrawLists[i]);
    }
    gMapObjects->mUnk_130 = TRUE;
    func_020d2e24();
    n = gMapObjects->mDrawListCount;
    c1 = 0;
    c2 = 0;
    s1 = 0;
    s2 = 0;
    for (t = 0; t < n; t++) {
        x = gMapObjects->mDrawLists[t];
        if (x->mUnk_20 != 0) {
            if (x->mUnk_18 == 1) {
                c1++;
            } else if (x->mUnk_18 == 2) {
                c2++;
            }
        }
    }
    m = 0;
    for (i = 0; i < n; i++) {
        x = gMapObjects->mDrawLists[i];
        if (x->mUnk_18 == 1) {
            y = gMapObjects->mUnk_068;
            gMapObjects->mUnk_12a++;
            if (x->mUnk_20 != 0) {
                k = s1++;
            } else {
                k = c1++;
            }
        } else if (x->mUnk_18 == 2) {
            y = gMapObjects->mUnk_0c8;
            gMapObjects->mUnk_12c++;
            if (x->mUnk_20 != 0) {
                k = s2++;
            } else {
                k = c2++;
            }
        }
        y[k] = x;
    }
    gMapObjects->mUpdateListCount = 0;
    for (i = 0; i < 16; i++) {
        gMapObjects->mUpdateLists[i] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        x = data_0216b288[i].mUnk_04->mLists[3];
        if (x == NULL) {
            continue;
        }
        g = 1;
        for (j = 0; j < gMapObjects->mUpdateListCount; j++) {
            if (gMapObjects->mUpdateLists[j] == x) {
                AddToMapObjectListCount(x, v);
                g = 0;
            }
        }
        if (g != 0) {
            ClearMapObjectListCount(x);
            if (v != 0) {
                AddToMapObjectListCount(x, v);
                gMapObjects->mUpdateLists[gMapObjects->mUpdateListCount++] = x;
            }
        }
    }
    for (i = 0; i < gMapObjects->mUpdateListCount; i++) {
        InitMapObjectUpdateList(gMapObjects->mUpdateLists[i]);
    }
    for (i = 0; i < gMapObjects->mMapObjectCount; i++) {
        o = gMapObjects->mMapObjects[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mKind == data_0216b288[j].mKind && data_0216b288[j].mUnk_04->mLists[3] != NULL) {
                AddMapObjectToUpdateList(data_0216b288[j].mUnk_04->mLists[3], o);
            }
        }
    }
    gMapObjects->mUnk_178 = TRUE;
    func_020d2dec();
}

void func_020d2e24(void) {
    s32 i;
    s32 n;
    MapObjectList **p;
    n = gMapObjects->mDrawListCount;
    p = gMapObjects->mDrawLists;
    if (gCourseWater != NULL) {
        InitWaterModels(gCourseWater);
    }
    func_020e52bc();
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mInit != NULL) {
            (*p)->mInit(*p);
        }
    }
}

void func_020d2dec(void) {
    s32 i;
    s32 n;
    MapObjectList **p;
    n = gMapObjects->mUpdateListCount;
    p = gMapObjects->mUpdateLists;
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mInit != NULL) {
            (*p)->mInit(*p);
        }
    }
}

#pragma thumb off
