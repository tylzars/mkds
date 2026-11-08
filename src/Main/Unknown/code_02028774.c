#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_020287ec(Unk02175628_48 *pair) {
    if (func_0202881c(pair) == 0) {
        if (pair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 func_020287c8(Unk02175628_48 *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_02028794(Unk02175628_48 *pair) {
    if (func_020287ec(pair) == 0) {
        if (func_020287c8(pair) != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_02028774(u32 slot) {
    return func_02028794((Unk02175628_48 *) &data_02175628[slot].mPairX);
}
