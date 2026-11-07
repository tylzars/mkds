#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020d50ec.h"

void FreeItemObjectCollisionSlot(int object) {
    u32 value0 = object;
    u32 noSlot;
    u32 objectAddress;
    u32 slotIndex;
    u32 noSlotCompared;
    objectAddress = value0;
    value0 = *(const s16 *) ((objectAddress) + (218));
    noSlot = ~(0u);
    slotIndex = value0;
    noSlotCompared = noSlot;
    if (slotIndex == noSlotCompared) {
    }
    if (slotIndex == noSlotCompared) {
        return;
    }
    value0 = FreeCollisionSlot(value0);
    *(u16 *) ((objectAddress) + (218)) = value0;
}
