#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b0.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_02030780(InputSlotPair *pair) {
    if (func_020307b0(pair) == 0 && pair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_0203075c(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_02030728(InputSlotPair *pair) {
    if (func_02030780(pair) == 0 && func_0203075c(pair) != 0) {
        return 1;
    }
    return 0;
}

u32 func_02030708(u32 slotIndex) {
    return func_02030728((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}
