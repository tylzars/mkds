#include "code_02022a60.h"
#include "code_02022a90.h"

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte) {
    NNSG2dCellTransferState *state;

    state = NNSi_G2dGetCellTransferState(handle);
    state->mTransferRequested = ~0;
    state->mSrcOffset = srcOffset;
    state->mSzByte = szByte;
}
