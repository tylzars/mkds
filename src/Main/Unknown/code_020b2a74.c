#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b1c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on
u32 func_020b2aec(InputSlotPair *p) {
    if (func_020b2b1c(p) == 0 && p->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_020b2ac8(InputSlotPair *p) {
    if (p->mPrevHasPair == 0 && p->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a94(InputSlotPair *p) {
    if (func_020b2aec(p) == 0 && func_020b2ac8(p) != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a74(s32 a) {
    return func_020b2a94((InputSlotPair *) &data_02175628[a].mPairX);
}
