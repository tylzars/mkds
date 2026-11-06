#include "code_0214d564.h"

// Starts a stepped LZ expansion: output at dest, the expanded size from header, every other member cleared.
void MI_InitUncompContextLZ(MIUncompContextLZ *context, u8 *dest, const MICompressionHeader *header) {
    context->mDestp = dest;
    context->mDestCount = header->mDestSize;
    context->mFlags = 0;
    context->mFlagIndex = 0;
    context->mLength = 0;
    context->mLengthFlg = 0;
    context->mDestTmp = 0;
    context->mDestTmpCnt = 0;
}
