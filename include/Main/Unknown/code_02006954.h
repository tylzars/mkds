#pragma once

#include "types.h"
#include "Main/Unknown/code_0200589c.h"

typedef struct BlockTransferRecord BlockTransferRecord;
typedef struct BlockTransfer BlockTransfer;

// List node; the next node is at offset 0x28.
typedef struct BlockListNode {
    /* 00 */ u32 mId;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ struct BlockListNode *mNext;
    /* 2c */ u8 *mData;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mHasNoData;
} BlockListNode;

u32 BuildParentPacket(u8 *buffer, s32 bufferSize);
void StopBlockTransfer(void);
void StartChildBlockTransfer(void (*callback)(BlockTransferRecord *));
void StartParentBlockTransfer(s32 sendSize, s32 receiveSize, void (*callback)(BlockTransferRecord *));
void BuildChildPacketUnchecked(u8 *buffer, s32 bufferSize);
void ReceiveParentPacket(const u8 *packet, u32 size);
void ReceivePacketFromIndex(u32 index, const u8 *packet, int size);
s32 BuildParentPacketUnchecked(u8 *buffer, s32 bufferSize);
u32 RequestSendBytes(u16 indexMask, const void *bytes, s32 byteCount, void (*callback)(void));
u32 RequestBlockData(u16 indexMask, u32 blockId, const void *buffers, u32 blockSize, const void *chunkBitmaps,
                     void (*callback)(BlockTransferRecord *));
u32 RequestBlockNode(u16 indexMask, u32 blockIdOrPosition, const void *buffers,
                     void (*callback)(BlockTransferRecord *));
u32 RequestBlockCount(u16 indexMask, void (*callback)(BlockTransferRecord *));
BlockListNode *RemoveBlock(u32 blockId);
s32 AddBlock(BlockListNode *node, u32 blockId, const void *info, u8 *data, u32 size, u16 f);
int CountBlocks(void);
u32 TrySetChunkSizes(s32 sendSize, s32 receiveSize);
BOOL TryGetBlockReceiveProgress(u32 blockId, s32 entryIndex, s32 *receivedChunkCountOut, s32 *chunkCountOut);
u32 GetChunkBitmapSize(s32 size);
s32 GetLowestSetBitIndex(s32 mask);
unsigned int GetOwnIndex(void);
void SetOwnIndex(unsigned int index);
BlockListNode *FindBlockById(u32 blockId);
void SetBlockListHead(BlockListNode *head);
BlockListNode *GetBlockListHead(void);
u32 TrySetNextRequest(const BlockTransferRecord *request);
unsigned int GetNextRequestAddress(void);
BlockTransfer *GetBlockTransfer(void);
void SetSendChunkSize(unsigned int chunkSize);
void SetReceiveChunkSize(unsigned int chunkSize);
unsigned int GetSendChunkSize(void);
unsigned int GetReceiveChunkSize(void);
