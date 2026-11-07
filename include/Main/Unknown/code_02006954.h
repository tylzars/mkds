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

u32 func_02006954(u8 *a, s32 b);
void StopBlockTransfer(void);
void func_02006a10(void (*a)(BlockTransferRecord *));
void func_02006aac(s32 a, s32 b, void (*c)(BlockTransferRecord *));
void func_02006b50(u8 *a, s32 b);
void func_02006bec(const u8 *a, u32 b);
void ReceivePacketFromIndex(u32 a, const u8 *b, int c);
s32 func_02006c2c(u8 *a, s32 b);
u32 RequestSendBytes(u16 a, const void *b, s32 c, void (*d)(void));
u32 RequestBlockData(u16 a, u32 b, const void *c, u32 d, const void *e, void (*f)(BlockTransferRecord *));
u32 RequestBlockNode(u16 a, u32 b, const void *c, void (*d)(BlockTransferRecord *));
u32 RequestBlockCount(u16 a, void (*b)(BlockTransferRecord *));
BlockListNode *RemoveBlock(u32 a);
s32 AddBlock(BlockListNode *a, u32 b, const void *c, u8 *d, u32 e, u16 f);
int CountBlocks(void);
u32 TrySetChunkSizes(s32 a, s32 b);
BOOL TryGetBlockReceiveProgress(u32 a, s32 b, s32 *c, s32 *d);
u32 GetChunkBitmapSize(s32 a);
s32 GetLowestSetBitIndex(s32 a);
unsigned int GetOwnIndex(void);
void SetOwnIndex(unsigned int p0);
BlockListNode *FindBlockById(u32 a);
void SetBlockListHead(BlockListNode *p0);
BlockListNode *GetBlockListHead(void);
u32 TrySetNextRequest(const BlockTransferRecord *a);
unsigned int GetNextRequestAddress(void);
BlockTransfer *GetBlockTransfer(void);
void SetSendChunkSize(unsigned int p0);
void SetReceiveChunkSize(unsigned int p0);
unsigned int GetSendChunkSize(void);
unsigned int GetReceiveChunkSize(void);
