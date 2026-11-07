#pragma once

#include "types.h"

// Starts at offset 0x24 of an entry of BlockTransfer; 0x44 bytes (see func_020062f4).
typedef struct ChunkReceiveState {
    /* 00 */ s32 mSize;
    /* 04 */ s32 mChunkCount;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mLastReceivedChunkIndex;
    /* 10 */ s32 mReceivedChunkCount;
    /* 14 */ u32 *mChunkBitmap;
    /* 18 */ u8 *mBuffer;
    /* 1c */ u8 mInlineChunkBitmap[0x28];
} ChunkReceiveState;

// Entry of BlockTransfer; 0x68 bytes.
typedef struct BlockTransferEntry {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mLastCallbackId;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u8 *mUnk_20;
    /* 24 */ ChunkReceiveState mReceive;
} BlockTransferEntry;

struct BlockTransferRecord;

// Block of 0x9c bytes; BlockTransfer holds three of them.
typedef struct BlockTransferRecord {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mIndexMask;
    /* 0a */ u16 mFromIndexMask;
    /* 0c */ u8 mRequestId;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ void (*mCallback)(struct BlockTransferRecord *);
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

s32 func_0200589c(BlockTransfer *a, u8 *b, s32 c);
s32 func_02005a30(BlockTransfer *a, u8 *b, s32 c);
s32 func_02005b18(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 func_02005b80(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 func_02005bec(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 func_02005cc8(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 func_02005d08(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 func_02005d4c(BlockTransfer *a, s32 b, u8 *c, s32 d);
u32 func_02005dac(BlockTransfer *a, s32 b, const u8 *c, s32 d);
void func_02006144(BlockTransfer *a, s32 b, s32 c);
void func_020061d8(BlockTransfer *a, s32 b, s32 c, u32 d);
BOOL func_0200628c(ChunkReceiveState *a, s32 b, const u8 *c);
s32 func_020062f4(ChunkReceiveState *a);
