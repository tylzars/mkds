#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b0.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_02030780(Unk02175628_48 *a) {
    if (func_020307b0(a) == 0 && a->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_0203075c(Unk02175628_48 *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_02030728(Unk02175628_48 *a) {
    if (func_02030780(a) == 0 && func_0203075c(a) != 0) {
        return 1;
    }
    return 0;
}

u32 func_02030708(u32 a) {
    return func_02030728((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}
