#include "Main/Unknown/code_02006954.h"

#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 GetReceiveChunkSize(void) {
    return (gReceiveChunkSize);
}

u32 GetSendChunkSize(void) {
    return (gSendChunkSize);
}

void SetReceiveChunkSize(u32 chunkSize) {
    gReceiveChunkSize = (u16) chunkSize;
}

void SetSendChunkSize(u32 chunkSize) {
    gSendChunkSize = (u16) chunkSize;
}

BlockTransfer *GetBlockTransfer(void) {
    return (BlockTransfer *) gBlockTransfer;
}

u32 GetNextRequestAddress(void) {
    return ((u32) (&gNextRequest));
}

#pragma thumb off

#pragma thumb on

u32 TrySetNextRequest(const BlockTransferRecord *request) {
    u32 savedInterrupts;
    s32 *nextRequest;
    savedInterrupts = OS_DisableInterrupts();
    if (gBlockTransferStarted != 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    nextRequest = (s32 *) GetNextRequestAddress();
    if (nextRequest == NULL || *nextRequest != 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MIi_CpuCopy32(request, gNextRequest, 0x9c);
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

#pragma thumb off

#pragma thumb on

BlockListNode *GetBlockListHead(void) {
    return gBlockListHead;
}

void SetBlockListHead(BlockListNode *head) {
    gBlockListHead = head;
}

#pragma thumb off

#pragma thumb on

BlockListNode *FindBlockById(u32 blockId) {
    BlockListNode *node;
    for (node = GetBlockListHead(); node != NULL; node = node->mNext) {
        if (node->mId == blockId) {
            return node;
        }
    }
    return NULL;
}

#pragma thumb off

#pragma thumb on

void SetOwnIndex(u32 index) {
    gOwnIndex = index;
}

u32 GetOwnIndex(void) {
    return gOwnIndex;
}

#pragma thumb off

#pragma thumb on

s32 GetLowestSetBitIndex(s32 mask) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((mask >> i) & 1) != 0) {
            return i;
        }
    }
    return -1;
}

u32 GetChunkBitmapSize(s32 size) {
    s32 chunkSize;
    s32 chunkCount;
    chunkSize = GetReceiveChunkSize();
    chunkCount = size / chunkSize + ((size % chunkSize) != 0 ? 1 : 0);
    return ((chunkCount >> 5) + ((chunkCount & 0x1f) != 0 ? 1 : 0)) << 2;
}

BOOL TryGetBlockReceiveProgress(u32 blockId, s32 entryIndex, s32 *receivedChunkCountOut, s32 *chunkCountOut) {
    BlockTransfer *transfer;
    ChunkReceiveState *receive;
    transfer = GetBlockTransfer();
    receive = &transfer->mEntries[entryIndex].mReceive;
    if (transfer->mCurrentRequest.mKind == 4 && transfer->mCurrentRequest.mUnk_14 == blockId) {
        *chunkCountOut = receive->mChunkCount;
        *receivedChunkCountOut = receive->mReceivedChunkCount;
        return TRUE;
    }
    return FALSE;
}

u32 TrySetChunkSizes(s32 sendSize, s32 receiveSize) {
    switch (GetBlockTransfer()->mCurrentRequest.mKind) {
        case 4:
        case 6:
            return 0;
    }
    SetSendChunkSize(sendSize - 0xe);
    SetReceiveChunkSize(receiveSize - 0xe);
    return 1;
}

#pragma thumb off

#pragma thumb on

int CountBlocks(void) {
    int count;
    BlockListNode *node;
    count = 0;
    for (node = GetBlockListHead(); node != NULL; node = node->mNext) {
        count = count + 1;
    }
    return count;
}

#pragma thumb off

#pragma thumb on

s32 AddBlock(BlockListNode *node, u32 blockId, const void *info, u8 *data, u32 size, u16 f) {
    BlockListNode *lastNode;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (GetBlockListHead() == NULL) {
        SetBlockListHead(node);
    } else {
        for (lastNode = GetBlockListHead(); lastNode->mNext != NULL; lastNode = lastNode->mNext) {
        }
        lastNode->mNext = node;
    }
    if (data == NULL) {
        node->mHasNoData = 1;
    } else {
        node->mData = data;
        node->mHasNoData = 0;
    }
    node->mNext = NULL;
    node->mId = blockId;
    node->mSize = size;
    node->mUnk_30 = f;
    if (info != NULL) {
        MI_CpuCopy8(info, node->mUnk_08, 0x20);
    } else {
        MI_CpuFill8(node->mUnk_08, 0, 0x20);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

BlockListNode *RemoveBlock(u32 blockId) {
    BlockListNode *v1;
    BlockListNode *v2;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    v1 = GetBlockListHead();
    if (v1 == NULL) {
        OS_RestoreInterrupts(savedInterrupts);
        return NULL;
    }
    if (v1->mId == blockId) {
        SetBlockListHead(v1->mNext);
        OS_RestoreInterrupts(savedInterrupts);
        return v1;
    }
    for (v2 = v1->mNext; v2 != NULL; v1 = v2, v2 = v2->mNext) {
        if (v2->mId == blockId) {
            v1->mNext = v2->mNext;
            OS_RestoreInterrupts(savedInterrupts);
            return v2;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return NULL;
}

u32 RequestBlockCount(u16 indexMask, void (*callback)(BlockTransferRecord *)) {
    BlockTransferRecord request;
    request.mKind = 2;
    request.mIndexMask = indexMask;
    request.mCallback = callback;
    return TrySetNextRequest(&request);
}

u32 RequestBlockNode(u16 indexMask, u32 blockIdOrPosition, const void *buffers,
                     void (*callback)(BlockTransferRecord *)) {
    BlockTransferRecord request;
    request.mKind = 6;
    request.mIndexMask = indexMask;
    request.mCallback = callback;
    request.mUnk_14 = blockIdOrPosition;
    request.mUnk_18 = 0x28;
    MIi_CpuCopy32(buffers, &request.mUnk_1c, 0x40);
    return TrySetNextRequest(&request);
}

u32 RequestBlockData(u16 indexMask, u32 blockId, const void *buffers, u32 blockSize, const void *chunkBitmaps,
                     void (*callback)(BlockTransferRecord *)) {
    BlockTransferRecord request;
    request.mKind = 4;
    request.mIndexMask = indexMask;
    request.mCallback = callback;
    request.mUnk_14 = blockId;
    request.mUnk_18 = blockSize;
    MIi_CpuCopy32(buffers, &request.mUnk_1c, 0x40);
    MIi_CpuCopy32(chunkBitmaps, &request.mChunkBitmaps, 0x40);
    return TrySetNextRequest(&request);
}

u32 RequestSendBytes(u16 indexMask, const void *bytes, s32 byteCount, void (*callback)(void)) {
    BlockTransferRecord request;
    BlockTransferRecord *requestPointer;
    if (byteCount < 0 || byteCount > 9) {
        return 0;
    }
    request.mKind = 10;
    requestPointer = &request;
    requestPointer->mIndexMask = indexMask;
    requestPointer->mCallback = (void (*)(BlockTransferRecord *)) callback;
    MI_CpuCopy8(bytes, &requestPointer->mUnk_14, byteCount);
    *((u8 *) requestPointer + 0x1d) = byteCount;
    return TrySetNextRequest(&request);
}

s32 BuildParentPacketUnchecked(u8 *buffer, s32 bufferSize) {
    BlockTransfer *transfer;
    s32 i;
    s32 packetSize;
    transfer = GetBlockTransfer();
    i = gLastReplyIndex;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        packetSize = ReplyToBytesPacket(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToBlockCountRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToBlockNodeRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToNoMissingChunk(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
    } while (i != gLastReplyIndex);
    packetSize = WriteCurrentRequestPacket(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    packetSize = StartNextRequest(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    i = gLastReplyIndex;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        packetSize = ReplyToBlockDataRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
    } while (i != gLastReplyIndex);
    for (i = 1; i < 16; i++) {
        packetSize = ReplyToBlockNodeRequestAlways(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            return packetSize;
        }
    }
    return WriteEmptyPacket(buffer, 0xfffe, 0);
}

#pragma thumb off

#pragma thumb on

void ReceivePacketFromIndex(u32 index, const u8 *packet, int size) {
    if (0 < size) {
        ParseReceivedPacket(GetBlockTransfer(), index, packet, size);
    }
}

void ReceiveParentPacket(const u8 *packet, u32 size) {
    ParseReceivedPacket(GetBlockTransfer(), 0, packet, size);
}

#pragma thumb off

#pragma thumb on

void BuildChildPacketUnchecked(u8 *buffer, s32 bufferSize) {
    BlockTransfer *transfer;
    transfer = GetBlockTransfer();
    if (ReplyToBytesPacket(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockCountRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToNoMissingChunk(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockDataRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequestAlways(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (WriteCurrentRequestPacket(transfer, buffer, bufferSize) != 0) {
        return;
    }
    if (StartNextRequest(transfer, buffer, bufferSize) != 0) {
        return;
    }
    WriteEmptyPacket(buffer, 0xffff, 0);
}

void StartParentBlockTransfer(s32 sendSize, s32 receiveSize, void (*callback)(BlockTransferRecord *)) {
    BlockTransferRecord request;
    BlockTransfer *transfer;
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (gBlockTransferStarted == 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    gBlockTransferStarted = 1;
    SetOwnIndex(0);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mKind = 0;
    transfer->mCurrentRequest.mIndexMask = 0;
    transfer->mCurrentRequest.mFromIndexMask = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mKind = 0;
    transfer->mCallbackRecord.mIndexMask = 0;
    transfer->mCallbackRecord.mFromIndexMask = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mKind = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(sendSize - 0xe);
    SetReceiveChunkSize(receiveSize - 0xe);
    OS_RestoreInterrupts(savedInterrupts);
}

void StartChildBlockTransfer(void (*callback)(BlockTransferRecord *)) {
    BlockTransferRecord request;
    BlockTransfer *transfer;
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (gBlockTransferStarted == 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    gBlockTransferStarted = 1;
    SetOwnIndex(-1);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mKind = 0;
    transfer->mCurrentRequest.mIndexMask = 0;
    transfer->mCurrentRequest.mFromIndexMask = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mKind = 0;
    transfer->mCallbackRecord.mIndexMask = 0;
    transfer->mCallbackRecord.mFromIndexMask = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mKind = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(0);
    SetReceiveChunkSize(0);
    OS_RestoreInterrupts(savedInterrupts);
}

void StopBlockTransfer(void) {
    BlockTransferRecord request;
    BlockTransfer *transfer;
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (gBlockTransferStarted == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    gBlockTransferStarted = 0;
    SetOwnIndex(-1);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mKind = 0;
    transfer->mCurrentRequest.mIndexMask = 0;
    transfer->mCurrentRequest.mFromIndexMask = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mKind = 0;
    transfer->mCallbackRecord.mIndexMask = 0;
    transfer->mCallbackRecord.mFromIndexMask = 0;
    transfer->mCallbackRecord.mCallback = NULL;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mKind = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(-1);
    SetReceiveChunkSize(-1);
    OS_RestoreInterrupts(savedInterrupts);
}

u32 BuildParentPacket(u8 *buffer, s32 bufferSize) {
    u16 packetSize;
    packetSize = 0;
    if (bufferSize > 0 && buffer != NULL) {
        packetSize = BuildParentPacketUnchecked(buffer, bufferSize);
    }
    return packetSize;
}

#pragma thumb off
