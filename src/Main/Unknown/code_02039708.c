#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/unk_02175628.h"

void ResetInputSlot(InputSlot *slot) {
    slot->mPressedBits = 0x0u;
    slot->mBits = 0x0u;
    slot->mClearedBits = 0x0u;
    slot->mRepeatBits = 0x0u;
    slot->mRepeatState = 0x0u;
    slot->mRepeatCallCount = 0x0u;
    slot->mRepeatMask = 0x0u;
    slot->mRepeatDelayLimit = 0x14u;
    slot->mRepeatIntervalLimit = 0x8u;
    slot->mHoldLong = 0x0u;
    slot->mUnk_14 = 0x0u;
    slot->mHoldStartTick = 0;
    slot->mUnk_20 = 0x0u;
    slot->mUnk_24 = 0x0u;
}

void ClearInputSlotBitsAndRepeat(InputSlot *slot) {
    slot->mPressedBits = 0x0u;
    slot->mBits = 0x0u;
    slot->mClearedBits = 0x0u;
    slot->mRepeatBits = 0x0u;
    slot->mRepeatState = 0x0u;
    slot->mRepeatCallCount = 0x0u;
}
