#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02165000.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205e2b8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa24;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

s32 func_0205e1c4(void) {
    BOOL result = FALSE;
    u16 i = 0;
    ShapeMapObjectCount *entry;
    CourseMapShape *courseMapShape;
    s32 mapObjectCount;
    u16 j;
    u8 insideCount;
    for (i = 0; i < data_0217aa24->mEntryCount; i++) {
        entry = &data_0217aa24->mEntries[i];
        courseMapShape = GetCourseMapShape(entry->mShapeIndex);
        mapObjectCount = FindMapObjectsOfKindInRadius(&courseMapShape->mPos, entry->mRadius, courseMapShape->mUnk_3c);
        insideCount = 0;
        for (j = 0; j < mapObjectCount; j++) {
            if (IsPosInCourseMapShape(&GetFoundMapObject(j)->mPos, courseMapShape) != 0) {
                insideCount = insideCount + 1;
            }
        }
        if (entry->mMapObjectCount < insideCount) {
            entry->mIncreaseCount++;
        }
        entry->mMapObjectCount = insideCount;
        if (entry->mIncreaseCount > courseMapShape->mUnk_3e) {
            result = TRUE;
            break;
        }
    }
    return result;
}

void CreateRunScenesState(void *heap) {
    gRunScenesState = HeapAlloc(heap, 0x10);
    gRunScenesState->mUnk_00 = 0;
    gRunScenesState->mUnk_04 = 3;
    gRunScenesState->mSndHeapsBuffer = NULL;
}

void func_0205e0b0(void) {
    void *h;
    s32 m;
    h = GetHeap(GetCurrentHeapCall());
    switch (gRunScenesState->mUnk_00) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                m = 2;
            } else {
                m = 0;
                StartLoadOverlay(1);
                FinishOverlayLoad();
            }
            InitConnectionBuffers(h);
            break;
        case 1:
            m = 1;
            StartLoadOverlay(0);
            FinishOverlayLoad();
            CreateWiFiSessionHeap(h);
            break;
    }
    if (m == 2) {
        return;
    }
    h = HeapAlloc(h, GetSndHeapsBufferSize(m));
    CreateSndHeaps(m, (u32) h);
    gRunScenesState->mSndHeapsBuffer = h;
}

int GetCurrentSceneNumber(void) {
    u32 value0;
    value0 = (u32) &gSceneNumbers;
    value0 = *(const s16 *) ((value0) + (2));
    return value0;
}

u32 GetNextSceneNumber(void) {
    u32 value0;
    value0 = (u32) &gSceneNumbers;
    value0 = *(const s16 *) ((value0) + (4));
    return value0;
}
