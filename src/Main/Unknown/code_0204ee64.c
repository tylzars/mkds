#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = data_0217aa00->mUnk_000c;
    u8 mask;
    s32 s = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (s == 1) {
        mask = data_0217aa00->mUnk_0044.mChildMask;
    } else {
        mask = 1;
    }
    data_0217aa00->mUnk_000c = 0x2a;
    data_0217aa00->mRequestPending = 1;
    if (RequestBlockCount(mask, BlockCountRequestCallback) == 0) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_000c = savedValue;
    }
}

void BlockCountRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 2) {
        if (record->mCallbackCode == 3) {
            data_0217aa00->mBlockCount = *(s16 *) &record->mUnk_14;
            data_0217aa00->mRequestPending = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = data_0217aa00->mUnk_000c;
    data_0217aa00->mUnk_000c = 0x2b;
    data_0217aa00->mRequestPending = 1;
    if (RequestBlockNode(1, data_0217aa00->mBlockIndex, data_0217aa00->mBlockInfos, BlockNodeRequestCallback) == 0) {
        data_0217aa00->mUnk_000c = savedValue;
        data_0217aa00->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 6) {
        if (record->mCallbackCode == 7) {
            data_0217aa00->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        func_02050e60(8);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = data_0217aa00->mUnk_000c;
    data_0217aa00->mUnk_000c = 0x2c;
    data_0217aa00->mRequestPending = 1;
    data_0217aa00->mUnk_1d60 = data_0217aa00->mBlockEntries[data_0217aa00->mBlockIndex].mBuffer;
    if (RequestBlockData(1, data_0217aa00->mBlockInfos[0]->mBlockId, &data_0217aa00->mUnk_1d60,
                         data_0217aa00->mBlockInfos[0]->mSize, data_0217aa00->mChunkBitmaps,
                         BlockDataRequestCallback) == 0) {
        data_0217aa00->mUnk_000c = savedValue;
        data_0217aa00->mRequestPending = 0;
    }
}

void BlockDataRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 4) {
        if (record->mCallbackCode == 5) {
            data_0217aa00->mRequestPending = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void SetOwnIndexFromConnection(void) {
    s32 v = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (v == 2) {
        if (data_0217aa00->mOwnIndex == 0xffff) {
            func_02050e60(8);
            return;
        }
        SetOwnIndex(data_0217aa00->mOwnIndex);
    }
}

void func_0204ef1c(void) {
    data_0217aa00->mUnk_000c = 0xb;
    data_0217aa00->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, data_0217aa00->mMPReceiveBuffer, data_0217aa00->mMPReceiveBufferSize,
                     data_0217aa00->mMPSendBuffer, data_0217aa00->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        func_02050e60(2);
    }
}

void AddGhostDataBlock(u8 *data, u32 size) {
    u16 index = data_0217aa00->mGhostBlockCount;
    AddBlock(&data_0217aa00->mBlockEntries[index].mNode, (u16) (index + 0x3e8), gGhostBlockInfo, data, size, 0);
    data_0217aa00->mBlockEntries[index].mBuffer = (u32 *) data;
    data_0217aa00->mGhostBlockCount++;
}

void func_0204eeac(u8 *data, u32 size) {
    AddGhostDataBlock(data, size);
}

void RemoveGhostDataBlocks(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        RemoveBlock((u16) (i + 0x3e8));
        data_0217aa00->mBlockEntries[i].mBuffer = 0;
    }
    data_0217aa00->mGhostBlockCount = 0;
}

#pragma thumb off
