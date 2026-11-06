#pragma once

#include "types.h"

// 0x30-byte entry of the cell transfer state array.
typedef struct NNSG2dCellTransferState {
    /* 00 */ u32 mUnk_00[9];
    /* 24 */ u32 mTransferRequested;
    /* 28 */ u32 mSrcOffset;
    /* 2c */ u32 mSzByte;
} NNSG2dCellTransferState;

NNSG2dCellTransferState *NNSi_G2dGetCellTransferState(u32 handle);
