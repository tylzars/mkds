#include "Main/Unknown/code_020d22c0.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"

// Puts a pooled map object aside: saves the low flag nibble in the high nibble, sets flags 1, 2, 8 and 4 (the update
// walk skips flag 4) and the parked bit 0x100, and disables its collision slot if it has one.
void ParkMapObject(MapObject *mapObject) {
    mapObject->mFlags &= ~0xf000;
    mapObject->mFlags |= (mapObject->mFlags & 0xf) << 12;
    mapObject->mFlags |= data_021568b4;
    mapObject->mFlags |= data_021568b8;
    mapObject->mFlags |= data_021568bc;
    mapObject->mFlags |= data_021568c0;
    if (mapObject->mCollisionSlotIndex != -1) {
        DisableCollisionSlot(mapObject->mCollisionSlotIndex);
    }
    mapObject->mFlags |= data_021568c4;
}

// Brings a parked map object back: restores the low flag nibble from the high one, sets mUnk_66 to 0x1f unless the
// restored flags contain 2, enables its collision slot if it has one and clears the parked bit 0x100.
void UnparkMapObject(MapObject *mapObject) {
    mapObject->mFlags &= ~0xf;
    mapObject->mFlags |= (mapObject->mFlags & 0xf000) >> 12;
    if (!(mapObject->mFlags & 2)) {
        mapObject->mAlpha = 0x1f;
    }
    if (mapObject->mCollisionSlotIndex != -1) {
        EnableCollisionSlot(mapObject->mCollisionSlotIndex);
    }
    mapObject->mFlags &= ~0x100;
}

void SetRaceRandomPointers(void) {
    gMapObjectRandom = gRaceSetup->mMode == 5 ? &gRaceProgress->mFixedSeedRandom : &gRaceProgress->mRandom;
    gRaceRandom = &gRaceProgress->mRandom;
}

RandomState64 *GetMapObjectRandom(void) {
    return (RandomState64 *) ((u32) gMapObjectRandom);
}

RandomState64 *GetRaceRandom(void) {
    return (RandomState64 *) ((u32) gRaceRandom);
}
