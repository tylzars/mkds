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

static inline GrpconfTblRow *func_020d34e4_inline(u16 kind) {
    s32 j;
    for (j = 0; j < 1000; j++) {
        if (kind == gGrpconfTbl[j].mUnk_00) {
            return &gGrpconfTbl[j];
        }
    }
    return NULL;
}

MapObject *CreateMapObject(u32 kind, CourseMapRow *courseRow, MapObject *source) {
    s32 i;
    s32 j;
    MapObjectKindRow *row;
    Unk021000d0 *descriptor;
    Unk021000d0 *otherDescriptor;
    MapObjectKindData *kindData;
    GrpconfTblRow *grpconfRow;
    MapObject *object;
    s32 tableValue;
    u32 slotFlags;
    for (i = 0; i < gMapObjectKindCount; i++) {
        {
            row = &data_0216b288[i];
            if (kind != row->mKind) {
                continue;
            }
            descriptor = row->mUnk_04;
            if (descriptor->mObjectCount == 0) {
                for (j = 0; j < gMapObjectKindCount; j++) {
                    otherDescriptor = data_0216b288[j].mUnk_04;
                    if (otherDescriptor == NULL) {
                        continue;
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateUpdateList == descriptor->mCreateUpdateList &&
                        otherDescriptor->mLists[3] != NULL) {
                        descriptor->mLists[3] = otherDescriptor->mLists[3];
                    }
                }
                if (descriptor->mKindData == NULL && descriptor->mCreateKindData != NULL) {
                    descriptor->mKindData = descriptor->mCreateKindData();
                    if (descriptor->mKindData == NULL) {
                        return NULL;
                    }
                    if (descriptor->mKindData->mUnk_24 == 0) {
                        descriptor->mKindData->mUnk_24 = -1;
                    }
                    if (descriptor->mKindData->mUnk_28 == 0) {
                        descriptor->mKindData->mUnk_28 = -1;
                    }
                    if (descriptor->mKindData->mUnk_38 == 0) {
                        descriptor->mKindData->mUnk_38 = 0x64000;
                    }
                    if (descriptor->mKindData->mUnk_3c == 0) {
                        descriptor->mKindData->mUnk_3c = -0x64000;
                    }
                    if (gRaceSetup->mRaceKind == 2) {
                        if (descriptor->mKindData->mUnk_38 < 0x44c000) {
                            descriptor->mKindData->mUnk_38 = 0x44c000;
                        }
                    }
                }
                grpconfRow = func_020d34e4_inline(row->mKind);
                if (grpconfRow->mUnk_02 != 0) {
                    descriptor->mKindData->mUnk_34 = grpconfRow->mUnk_02 >= 2 ? 1 : 0;
                    tableValue = grpconfRow->mUnk_04;
                    descriptor->mKindData->mUnk_2c =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->mUnk_06;
                    descriptor->mKindData->mUnk_30 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                }
                if (grpconfRow->mUnk_08 != 0) {
                    descriptor->mKindData->mShapeKind = grpconfRow->mUnk_08;
                    tableValue = grpconfRow->mUnk_0a;
                    descriptor->mKindData->mUnk_0c =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->mUnk_0c;
                    descriptor->mKindData->mUnk_10 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->mUnk_0e;
                    descriptor->mKindData->mUnk_14 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                }
                if (descriptor->mLists[0] == NULL && descriptor->mCreateDrawList0 != NULL) {
                    descriptor->mLists[0] = descriptor->mCreateDrawList0();
                }
                if (descriptor->mLists[1] == NULL && descriptor->mCreateDrawList1 != NULL) {
                    descriptor->mLists[1] = descriptor->mCreateDrawList1();
                }
                if (descriptor->mLists[2] == NULL && descriptor->mCreateDrawList2 != NULL) {
                    descriptor->mLists[2] = descriptor->mCreateDrawList2();
                }
                if (descriptor->mLists[3] == NULL && descriptor->mCreateUpdateList != NULL) {
                    descriptor->mLists[3] = descriptor->mCreateUpdateList();
                }
            }
            if (descriptor == NULL) {
                continue;
            }
            kindData = descriptor->mKindData;
            object = HeapAlloc(GetHeap(GetCurrentHeapCall()), descriptor->mObjectSize);
            descriptor->mObjectCount++;
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
            SetMapObjectDrawDistance(object, kindData->mUnk_30);
            object->mUseTwoPlaneViewTest = kindData->mUnk_34;
            if (kindData->mShapeKind != 0) {
                object->mFlags &= ~1;
            } else {
                object->mFlags |= data_021568cc;
            }
            if (kindData->mUnk_1c != 0) {
                object->mFlags &= ~0x40;
            } else {
                object->mFlags |= data_021568d0;
            }
            if ((descriptor->mLists[0] != NULL && descriptor->mLists[0]->mForEachObject != NULL) ||
                (descriptor->mLists[1] != NULL && descriptor->mLists[1]->mForEachObject != NULL) ||
                (descriptor->mLists[2] != NULL && descriptor->mLists[2]->mForEachObject != NULL)) {
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
            if (descriptor->mLists[3] != NULL && descriptor->mLists[3]->mForEachObject != NULL) {
                object->mFlags &= ~4;
            } else {
                object->mFlags |= data_021568dc;
            }
            object->mFarDistanceSquared = gSoundFalloffs[2].mUnk_20;
            if (courseRow != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, courseRow, data_0216b288[i].mUnk_08);
                }
            } else if (source != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, NULL, source);
                }
            }
            if (kindData->mShapeKind != 0) {
                slotFlags = 0x2000;
                if (kindData->mUnk_20 == 0) {
                    slotFlags |= data_021568e0;
                }
                if (IsKoopaBlockKind(object->mKind) != 0 || func_020e4320(object->mKind) != FALSE ||
                    IsBridgeKind(object->mKind) != FALSE || func_020ffabc(object->mKind) != FALSE) {
                    slotFlags |= data_021568e4;
                }
                object->mCollisionSlotIndex =
                    CreateCollisionSlot(&object->mPos, GetMapObjectCollisionRadius(object), slotFlags, object);
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
    void *heap;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    s32 c1;
    s32 c2;
    s32 s1;
    s32 s2;
    s32 listIndex;
    s32 t;
    s32 isNewList;
    u32 v;
    MapObjectKindRow *row;
    Unk021000d0 *descriptor;
    CourseMapRow *courseRow;
    MapObject *mapObject;
    MapObjectList *kindLists[3];
    MapObjectList *list;
    MapObjectList **listArray;
    MapObjects *q;
    heap = GetHeap(GetCurrentHeapCall());
    SetRaceRandomPointers();
    data_0217b4cc = GetMapObjectFirstPolygonId();
    data_0217b4c0 = data_0217b4cc + 9;
    gWrappingPolygonIdBase = data_0217b4c0 + 1;
    n = gCourseMap->mRowCount;
    gMapObjects = HeapAlloc(heap, 0x2bc);
    gMapObjects->mMapObjects = HeapAlloc(heap, 0x400);
    gFoundMapObjects = HeapAlloc(heap, 0x80);
    gFoundMapObjectVectors = HeapAlloc(heap, 0x180);
    gMapObjects->mMapObjectCount = 0;
    gMapObjects->mUnk_130 = FALSE;
    gMapObjects->mUnk_178 = FALSE;
    v = 0;
    if (gRaceSetup->mMode != 5) {
        v = 1;
    }
    gMapObjects->mRunUpdateLists = v;
    gMapObjectKindCount = 0;
    do {
        row = &data_0216b288[gMapObjectKindCount];
        descriptor = row->mUnk_04;
        if (row->mKind == 0) {
            break;
        }
        if (data_0217aa10->mUnk_00 != 1 && IsInOverlayRange(descriptor) != 0) {
            break;
        }
        if (descriptor != NULL) {
            descriptor->mKindData = NULL;
            descriptor->mLists[0] = NULL;
            descriptor->mLists[1] = NULL;
            descriptor->mLists[2] = NULL;
            descriptor->mLists[3] = NULL;
        }
        gMapObjectKindCount++;
    } while (gMapObjectKindCount < 0x85);
    gGrpconfTbl = FindMainRaceOrMainEffectFile("MapObj/grpconf.tbl");
    v = 1;
    if (gRaceSetup->mMode != MODE_TIME_ATTACK && gRaceSetup->mMode != 5) {
        v = 0;
    }
    data_0217b4e0 = v;
    gMapObjects->mHasKoopaBlock = 0;
    gMapObjects->mUnk_180 = 0;
    gMapObjects->mUnk_184 = 0;
    gMapObjects->mUnk_188 = 0;
    gCourseWater = NULL;
    gCourseWaterEfct = NULL;
    ClearOrthoQuadCreamEffectPointer();
    func_020d7df8();
    InitMatrices();
    func_020d4bf0();
    gWrappingPolygonId = gWrappingPolygonIdBase;
    gNextPolygonId = data_0217b4cc;
    for (i = 0; i < gMapObjectKindCount; i++) {
        if (data_0216b288[i].mUnk_04 != NULL) {
            data_0216b288[i].mUnk_04->mObjectCount = 0;
        }
    }
    for (i = 0; i < n; i++) {
        courseRow = OFFSET_PTR(CourseMapRow, gCourseMap->mRows, i * sizeof(CourseMapRow));
        if (gRaceSetup->mMode == MODE_TIME_ATTACK && (courseRow->mUnk_38 & 1) == 0) {
            continue;
        }
        CreateMapObject(courseRow->mKind, courseRow, NULL);
        gMapObjects->mHasKoopaBlock |= IsKoopaBlockKind(courseRow->mKind);
        gMapObjects->mUnk_180 |= func_020e4320(courseRow->mKind);
        gMapObjects->mUnk_184 |= IsBridgeKind(courseRow->mKind);
        gMapObjects->mUnk_188 |= func_020ffabc(courseRow->mKind);
    }
    if (gMapObjects->mHasKoopaBlock != 0 || gMapObjects->mUnk_180 != 0 || gMapObjects->mUnk_184 != 0 ||
        gMapObjects->mUnk_188 != 0) {
        data_0217b610 = 1;
    }
    CreatePooledMapObjects();
    gMapObjects->mDrawListCount = 0;
    for (m = 0; m < 24; m++) {
        gMapObjects->mDrawLists[m] = NULL;
    }
    for (i = 0; i < gMapObjectKindCount; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        kindLists[0] = data_0216b288[i].mUnk_04->mLists[0];
        kindLists[1] = data_0216b288[i].mUnk_04->mLists[1];
        kindLists[2] = data_0216b288[i].mUnk_04->mLists[2];
        for (j = 0; j < 3; j++) {
            s32 isNewList;
            if (kindLists[j] == NULL) {
                continue;
            }
            isNewList = 1;
            for (m = 0; m < gMapObjects->mDrawListCount; m++) {
                if (gMapObjects->mDrawLists[m] == kindLists[j]) {
                    func_020d4a10(kindLists[j], v);
                    isNewList = 0;
                }
            }
            if (isNewList != 0) {
                ClearMapObjectList(kindLists[j]);
                if (v != 0) {
                    func_020d4a10(kindLists[j], v);
                    gMapObjects->mDrawLists[gMapObjects->mDrawListCount++] = kindLists[j];
                }
            }
        }
    }
    for (i = 0; i < gMapObjects->mDrawListCount; i++) {
        InitMapObjectDrawList(gMapObjects->mDrawLists[i]);
    }
    for (i = 0; i < gMapObjects->mMapObjectCount; i++) {
        mapObject = gMapObjects->mMapObjects[i];
        for (j = 0; j < gMapObjectKindCount; j++) {
            if (mapObject->mKind == data_0216b288[j].mKind) {
                kindLists[0] = data_0216b288[j].mUnk_04->mLists[0];
                kindLists[1] = data_0216b288[j].mUnk_04->mLists[1];
                kindLists[2] = data_0216b288[j].mUnk_04->mLists[2];
                if (kindLists[0] != NULL) {
                    AddMapObjectToDrawList(kindLists[0], mapObject);
                }
                if (kindLists[1] != NULL) {
                    AddMapObjectToDrawList(kindLists[1], mapObject);
                }
                if (kindLists[2] != NULL) {
                    AddMapObjectToDrawList(kindLists[2], mapObject);
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
        list = gMapObjects->mDrawLists[t];
        if (list->mUnk_20 != 0) {
            if (list->mUnk_18 == 1) {
                c1++;
            } else if (list->mUnk_18 == 2) {
                c2++;
            }
        }
    }
    m = 0;
    for (i = 0; i < n; i++) {
        list = gMapObjects->mDrawLists[i];
        if (list->mUnk_18 == 1) {
            listArray = gMapObjects->mUnk_068;
            gMapObjects->mUnk_12a++;
            if (list->mUnk_20 != 0) {
                listIndex = s1++;
            } else {
                listIndex = c1++;
            }
        } else if (list->mUnk_18 == 2) {
            listArray = gMapObjects->mUnk_0c8;
            gMapObjects->mUnk_12c++;
            if (list->mUnk_20 != 0) {
                listIndex = s2++;
            } else {
                listIndex = c2++;
            }
        }
        listArray[listIndex] = list;
    }
    gMapObjects->mUpdateListCount = 0;
    for (i = 0; i < 16; i++) {
        gMapObjects->mUpdateLists[i] = NULL;
    }
    for (i = 0; i < gMapObjectKindCount; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        list = data_0216b288[i].mUnk_04->mLists[3];
        if (list == NULL) {
            continue;
        }
        isNewList = 1;
        for (j = 0; j < gMapObjects->mUpdateListCount; j++) {
            if (gMapObjects->mUpdateLists[j] == list) {
                AddToMapObjectListCount(list, v);
                isNewList = 0;
            }
        }
        if (isNewList != 0) {
            ClearMapObjectListCount(list);
            if (v != 0) {
                AddToMapObjectListCount(list, v);
                gMapObjects->mUpdateLists[gMapObjects->mUpdateListCount++] = list;
            }
        }
    }
    for (i = 0; i < gMapObjects->mUpdateListCount; i++) {
        InitMapObjectUpdateList(gMapObjects->mUpdateLists[i]);
    }
    for (i = 0; i < gMapObjects->mMapObjectCount; i++) {
        mapObject = gMapObjects->mMapObjects[i];
        for (j = 0; j < gMapObjectKindCount; j++) {
            if (mapObject->mKind == data_0216b288[j].mKind && data_0216b288[j].mUnk_04->mLists[3] != NULL) {
                AddMapObjectToUpdateList(data_0216b288[j].mUnk_04->mLists[3], mapObject);
            }
        }
    }
    gMapObjects->mUnk_178 = TRUE;
    RunMapObjectUpdateListInits();
}

void func_020d2e24(void) {
    s32 i;
    s32 n;
    MapObjectList **listCursor;
    n = gMapObjects->mDrawListCount;
    listCursor = gMapObjects->mDrawLists;
    if (gCourseWater != NULL) {
        InitWaterModels(gCourseWater);
    }
    CreateObjShadowAndJgShadow();
    for (i = 0; i < n; listCursor++, i++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

void RunMapObjectUpdateListInits(void) {
    s32 i;
    s32 n;
    MapObjectList **listCursor;
    n = gMapObjects->mUpdateListCount;
    listCursor = gMapObjects->mUpdateLists;
    for (i = 0; i < n; listCursor++, i++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

#pragma thumb off
