#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020d50ec.h"

void FreeItemObjectCollisionSlot(int object) {
    u32 scratch = object;
    u32 noSlot;
    u32 objectAddress;
    u32 slotIndex;
    u32 noSlotCompared;
    objectAddress = scratch;
    scratch = *(const s16 *) ((objectAddress) + (218));
    noSlot = ~(0u);
    slotIndex = scratch;
    noSlotCompared = noSlot;
    if (slotIndex == noSlotCompared) {
    }
    if (slotIndex == noSlotCompared) {
        return;
    }
    scratch = FreeCollisionSlot(scratch);
    *(u16 *) ((objectAddress) + (218)) = scratch;
}
