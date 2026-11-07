#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/unk_02175628.h"

void SetInputSlotRepeat(InputSlot *slot, u32 mask, u32 delayLimit, u32 intervalLimit) {
    slot->mRepeatMask = mask;
    slot->mRepeatDelayLimit = delayLimit;
    slot->mRepeatIntervalLimit = intervalLimit;
}
