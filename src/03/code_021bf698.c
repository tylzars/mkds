#include "03/code_021bf698.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021d5000.h"

#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void InitSelectionObjects(void) {
    gSelectionObjects = func_ov003_021d283c(0x10, 4);
}

void ReleaseSelectionObjects(void) {
    ReleaseSelectionObjectSlots();
    func_ov003_021d2808(&gSelectionObjects);
}

void PlaceSelectionPair(u32 pairIndex, u32 leftX, u32 rightX, u32 yPos) {
    s32 i;
    u8 *objectIds;

    ReleaseSelectionObjectSlots();
    i = 0;
    objectIds = data_ov003_021d5f4c + pairIndex * 2;
    for (; i < 2; i++) {
        gSelectionObjects[i] = func_ov003_021d1be4(0, *objectIds, 1);
        func_ov003_021d1790(gSelectionObjects[i], -1, 1);
        objectIds++;
    }
    func_ov003_021d17d4(gSelectionObjects[0], -1, leftX, yPos);
    func_ov003_021d17d4(gSelectionObjects[1], -1, rightX, yPos);
}

void PlaceSelectionCorners(u32 left, u32 right, u32 top, u32 bottom) {
    int objectId;
    int count;
    int slot;
    Unk021d1770 *object;
    objectId = 6;
    ReleaseSelectionObjectSlots();
    count = 0;
    slot = 0;
    do {
        object = func_ov003_021d1be4(0, objectId, 1);
        gSelectionObjects[slot] = object;
        func_ov003_021d1790(gSelectionObjects[slot], 0xffffffff, 1);
        slot = slot + 1;
        count = count + 1;
        objectId = objectId + 1;
    } while (count < 4);
    func_ov003_021d17d4(gSelectionObjects[0], 0xffffffff, left, top);
    func_ov003_021d17d4(gSelectionObjects[1], 0xffffffff, right, top);
    func_ov003_021d17d4(gSelectionObjects[2], 0xffffffff, left, bottom);
    func_ov003_021d17d4(gSelectionObjects[3], 0xffffffff, right, bottom);
}

void ReleaseSelectionObjectSlots(void) {
    int count;
    int slot;
    Unk021d1770 *object;
    count = 0;
    slot = 0;
    do {
        object = gSelectionObjects[slot];
        if (NULL != object) {
            func_ov003_021d197c(object);
            gSelectionObjects[slot] = NULL;
        }
        slot = slot + 1;
        count = count + 1;
    } while (count < 4);
}
