#include "Main/Unknown/code_020cb1f4.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on
u16 func_020cb210(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 func_020cb1f4(u32 slotIndex, u32 mask) {
    return func_020cb210(&data_02175628[slotIndex], mask);
}
