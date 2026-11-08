#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acebc.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_020ace8c(InputSlotPair *a) {
    if (func_020acebc(a) == 0) {
        if (a->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 func_020ace68(InputSlotPair *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ace34(InputSlotPair *a) {
    u32 r;

    if (func_020ace8c(a) == 0 && func_020ace68(a) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_020ace14(u32 a) {
    return func_020ace34((InputSlotPair *) &data_02175628[a].mPairX);
}
