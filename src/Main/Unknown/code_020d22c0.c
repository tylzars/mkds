#include "Main/Unknown/code_020d22c0.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"

// Puts a pooled map object aside: saves the low flag nibble in the high nibble, sets flags 1, 2, 8 and 4 (the update
// walk skips flag 4) and the parked bit 0x100, and disables its collision slot if it has one.
void ParkMapObject(MapObject *a) {
    a->mFlags &= ~0xf000;
    a->mFlags |= (a->mFlags & 0xf) << 12;
    a->mFlags |= data_021568b4;
    a->mFlags |= data_021568b8;
    a->mFlags |= data_021568bc;
    a->mFlags |= data_021568c0;
    if (a->mUnk_64 != -1) {
        func_020d5114(a->mUnk_64);
    }
    a->mFlags |= data_021568c4;
}

// Brings a parked map object back: restores the low flag nibble from the high one, sets mUnk_66 to 0x1f unless the
// restored flags contain 2, enables its collision slot if it has one and clears the parked bit 0x100.
void UnparkMapObject(MapObject *a) {
    a->mFlags &= ~0xf;
    a->mFlags |= (a->mFlags & 0xf000) >> 12;
    if (!(a->mFlags & 2)) {
        a->mUnk_66 = 0x1f;
    }
    if (a->mUnk_64 != -1) {
        func_020d50ec(a->mUnk_64);
    }
    a->mFlags &= ~0x100;
}

void func_020d22e0(void) {
    data_0217b4bc = data_021759c0->mMode == 5 ? &gRaceProgress->mUnk_4b0 : &gRaceProgress->mRandom;
    data_0217b4b8 = &gRaceProgress->mRandom;
}

Unk020f41c4_B *func_020d22d0(void) {
    return (Unk020f41c4_B *) ((u32) data_0217b4bc);
}

Unk020f41c4_B *func_020d22c0(void) {
    return (Unk020f41c4_B *) ((u32) data_0217b4b8);
}
