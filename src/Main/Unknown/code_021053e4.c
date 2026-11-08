#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020debec.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020de000.h"
#include "Main/Unknown/unk_021759c0.h"

const Unk0215a64c data_usa_0215a64c = {
    0, 0x108, func_02105464, func_02105480, func_020df294, CreateQuestionDrawList, CreateBoxDrawList, {0}};

const Unk0215a680 data_0215a680 = {{0, 0, 0, 0xf000, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}};

u32 func_02105504(void) {
    u32 result = 0;
    u32 isNormalOrKind2;
    if (GetCurrentSceneNumber() == 2) {
        s32 raceKind = gRaceSetup->mRaceKind;
        isNormalOrKind2 = 1;
        if (raceKind != RACE_KIND_NORMAL && raceKind != 2) {
            isNormalOrKind2 = 0;
        }
        if (isNormalOrKind2 != 0) {
            result = 1;
        }
    }
    return result;
}

u32 func_021054d0(void) {
    u32 result = 0;
    s32 a = gRaceSetup->mMode;
    if (a != MODE_MISSION_RUN) {
        return result;
    }
    a = a == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1;
    if (a == 9) {
        result = 1;
    }
    return result;
}

Unk0215a680 *func_02105480(void) {
    Unk0215a680 *data = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *data = data_0215a680;
    return data;
}

void func_02105464(void *mapObject, void *q) {
    InitItemBox(mapObject, q);
    ParkMapObject(mapObject);
}

MapObject *AllocPooledMapObject(void) {
    u32 index = gPooledMapObjectNextIndex;
    MapObject **mapObjects = gPooledMapObjects;
    gPooledMapObjectNextIndex = index + 1;
    return mapObjects[index];
}

void ResetPooledMapObject(Unk021052fc *pooledObject) {
    UnparkMapObject(&pooledObject->mUnk_00);
    pooledObject->mUnk_00.mAlpha = 0x1f;
    pooledObject->mUnk_00.mFlags &= ~2;
    pooledObject->mUnk_00.mFlags &= ~8;
    pooledObject->mUnk_00.mAlpha = 0x1f;
    pooledObject->mUnk_00.mScale.x = 0;
    pooledObject->mUnk_00.mScale.y = 0;
    pooledObject->mUnk_00.mScale.z = 0;
    pooledObject->mUnk_a0 = 0;
    pooledObject->mUnk_a2 = 0;
    pooledObject->mUnk_a4 = 0x80;
}
