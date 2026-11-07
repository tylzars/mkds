#include "Main/Unknown/code_020470c4.h"

void ResetInputSlotPair(Unk02175628_48 *pair) {
    pair->mNoPairCount = 0xffffu;
    pair->mUnk_12[0] = 0x0u;
    pair->mPairX = 0xffu;
    pair->mPairY = 0xffu;
    pair->mHasPair = 0x0u;
    pair->mValidity = 0x3u;
    pair->mPrevPairX = 0xffu;
    pair->mPrevPairY = 0xffu;
    pair->mPrevHasPair = 0x0u;
    pair->mPrevValidity = 0x3u;
}
