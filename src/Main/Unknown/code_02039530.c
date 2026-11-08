#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0200f5ac.h"

void UpdateInputSlot(u32 keys, InputSlot *slot) {
    u16 maskedBits;
    if (slot->mUnk_20 != 0) {
        WriteKeyBitsToStream(keys);
    }
    slot->mPressedBits = keys & (keys ^ slot->mBits);
    slot->mClearedBits = (keys ^ 0xffff) & (keys ^ slot->mBits);
    slot->mBits = keys;
    slot->mRepeatBits = 0;
    switch (slot->mRepeatState) {
        case 0:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatState = 1;
                slot->mRepeatCallCount = 0;
                slot->mRepeatBits = keys & slot->mRepeatMask;
            }
            break;
        case 1:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatCallCount++;
                if (slot->mRepeatCallCount >= slot->mRepeatDelayLimit) {
                    slot->mRepeatState = 2;
                    slot->mRepeatCallCount = 0;
                    slot->mRepeatBits = keys & slot->mRepeatMask;
                }
            } else {
                slot->mRepeatState = 0;
            }
            break;
        case 2:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatCallCount++;
                if (slot->mRepeatCallCount >= slot->mRepeatIntervalLimit) {
                    slot->mRepeatCallCount = 0;
                    slot->mRepeatBits = keys & slot->mRepeatMask;
                }
            } else {
                slot->mRepeatState = 0;
            }
            break;
    }
    maskedBits = slot->mBits & 0x30c;
    if (slot->mUnk_14 != 0 && maskedBits == 0x30c) {
        if (slot->mPressedBits & 0x30c) {
            slot->mHoldStartTick = OS_GetTick();
            slot->mHoldLong = 0;
            return;
        }
        if (slot->mHoldLong != 0) {
            return;
        }
        if ((u32) (OS_GetTick() - slot->mHoldStartTick) > 0x3fec4) {
            slot->mHoldLong = 1;
        }
        return;
    }
    if (maskedBits != 0x30c) {
        slot->mUnk_14 = 1;
    }
    slot->mHoldLong = 0;
}
