#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b1c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on
u32 func_020b2aec(InputSlotPair *inputSlotPair) {
    if (func_020b2b1c(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_020b2ac8(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a94(InputSlotPair *inputSlotPair) {
    if (func_020b2aec(inputSlotPair) == 0 && func_020b2ac8(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a74(s32 slotIndex) {
    return func_020b2a94((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}
