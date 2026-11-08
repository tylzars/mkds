#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acebc.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_020ace8c(InputSlotPair *inputSlotPair) {
    if (func_020acebc(inputSlotPair) == 0) {
        if (inputSlotPair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 func_020ace68(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ace34(InputSlotPair *inputSlotPair) {
    u32 r;

    if (func_020ace8c(inputSlotPair) == 0 && func_020ace68(inputSlotPair) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_020ace14(u32 slotIndex) {
    return func_020ace34((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}
