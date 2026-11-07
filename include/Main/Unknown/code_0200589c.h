#pragma once

#include "types.h"

// Starts at offset 0x24 of an entry of BlockTransfer; 0x44 bytes (see PickMissingChunkIndex).
typedef struct ChunkReceiveState {
    /* 00 */ s32 mSize;
    /* 04 */ s32 mChunkCount;
    /* 08 */ s32 mPickedChunkIndex;
    /* 0c */ s32 mLastReceivedChunkIndex;
    /* 10 */ s32 mReceivedChunkCount;
    /* 14 */ u32 *mChunkBitmap;
    /* 18 */ u8 *mBuffer;
    /* 1c */ u8 mInlineChunkBitmap[0x28];
} ChunkReceiveState;

// Entry of BlockTransfer; 0x68 bytes.
typedef struct BlockTransferEntry {
// 1 at rest; 2 while a parsed request waits for its reply.
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mPacketKind;
    /* 02 */ u8 mRequestId;
    /* 03 */ u8 mLastCallbackId;
    /* 04 */ s16 mPacketReceiveChunkSize;
    /* 06 */ s16 mPacketSendChunkSize;
    /* 08 */ u16 mIndexMask;
    /* 0a */ s16 mBlockCount;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mByteCount;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u32 mBlockId;
    /* 14 */ u32 mChunkIndex;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u8 *mPayload;
    /* 24 */ ChunkReceiveState mReceive;
} BlockTransferEntry;

struct BlockTransferRecord;

// Block of 0x9c bytes; BlockTransfer holds three of them.
typedef struct BlockTransferRecord {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mCallbackCode;
    /* 08 */ u16 mIndexMask;
    /* 0a */ u16 mFromIndexMask;
    /* 0c */ u8 mRequestId;
    /* 0d */ u8 mReceivedRequestId;
    /* 0e */ u16 mErrorCode;
    /* 10 */ void (*mCallback)(struct BlockTransferRecord *);
// In mCallbackRecord, words 0x14 to 0x1c carry what the callback code brings: counts and chunk sizes, a block id
// and chunk, or up to 9 bytes with their length at 0x1d.
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c[16];
    /* 5c */ void *mChunkBitmaps[16];
} BlockTransferRecord;

// Object at gBlockTransfer; 0x854 bytes.
typedef struct BlockTransfer {
    /* 000 */ BlockTransferRecord mCurrentRequest;
    /* 09c */ BlockTransferRecord mNextRequest;
    /* 138 */ BlockTransferRecord mCallbackRecord;
    /* 1d4 */ BlockTransferEntry mEntries[16];
} BlockTransfer;

s32 StartNextRequest(BlockTransfer *a, u8 *b, s32 c);
s32 WriteCurrentRequestPacket(BlockTransfer *a, u8 *b, s32 c);
s32 ReplyToBlockNodeRequestAlways(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockNodeRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockDataRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBytesPacket(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToNoMissingChunk(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockCountRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
u32 ParseReceivedPacket(BlockTransfer *a, s32 b, const u8 *c, s32 d);
void RunCurrentRequestCallback(BlockTransfer *a, s32 b, s32 c);
void RunBlockTransferCallback(BlockTransfer *a, s32 b, s32 c, u32 d);
BOOL StoreReceivedChunk(ChunkReceiveState *a, s32 b, const u8 *c);
s32 PickMissingChunkIndex(ChunkReceiveState *a);
