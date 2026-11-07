#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_020287ec(Unk02175628_48 *a) {
    if (func_0202881c(a) == 0) {
        if (a->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 func_020287c8(Unk02175628_48 *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_02028794(Unk02175628_48 *a) {
    if (func_020287ec(a) == 0) {
        if (func_020287c8(a) != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_02028774(u32 a) {
    return func_02028794((Unk02175628_48 *) &data_02175628[a].mPairX);
}
