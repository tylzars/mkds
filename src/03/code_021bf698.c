#include "03/code_021bf698.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021d5000.h"

#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void InitSelectionObjects(void) {
    gSelectionObjects = AllocZeroedExpHeapBlock(0x10, 4);
}

void ReleaseSelectionObjects(void) {
    ReleaseSelectionObjectSlots();
    FreeExpHeapBlockAndClearPointer(&gSelectionObjects);
}

void PlaceSelectionPair(u32 pairIndex, u32 leftX, u32 rightX, u32 yPos) {
    s32 i;
    u8 *objectIds;

    ReleaseSelectionObjectSlots();
    i = 0;
    objectIds = data_ov003_021d5f4c + pairIndex * 2;
    for (; i < 2; i++) {
        gSelectionObjects[i] = CreateOamRangeFromNceImage(0, *objectIds, 1);
        func_ov003_021d1790(gSelectionObjects[i], -1, 1);
        objectIds++;
    }
    SetOamRangePosition(gSelectionObjects[0], -1, leftX, yPos);
    SetOamRangePosition(gSelectionObjects[1], -1, rightX, yPos);
}

void PlaceSelectionCorners(u32 left, u32 right, u32 top, u32 bottom) {
    int objectId;
    int count;
    int slot;
    OamRange *object;
    objectId = 6;
    ReleaseSelectionObjectSlots();
    count = 0;
    slot = 0;
    do {
        object = CreateOamRangeFromNceImage(0, objectId, 1);
        gSelectionObjects[slot] = object;
        func_ov003_021d1790(gSelectionObjects[slot], 0xffffffff, 1);
        slot = slot + 1;
        count = count + 1;
        objectId = objectId + 1;
    } while (count < 4);
    SetOamRangePosition(gSelectionObjects[0], 0xffffffff, left, top);
    SetOamRangePosition(gSelectionObjects[1], 0xffffffff, right, top);
    SetOamRangePosition(gSelectionObjects[2], 0xffffffff, left, bottom);
    SetOamRangePosition(gSelectionObjects[3], 0xffffffff, right, bottom);
}

void ReleaseSelectionObjectSlots(void) {
    int count;
    int slot;
    OamRange *object;
    count = 0;
    slot = 0;
    do {
        object = gSelectionObjects[slot];
        if (NULL != object) {
            DeleteOamRange(object);
            gSelectionObjects[slot] = NULL;
        }
        slot = slot + 1;
        count = count + 1;
    } while (count < 4);
}
