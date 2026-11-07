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

void SetReceiveChunkSize(u32 p0) {
    gReceiveChunkSize = (u16) p0;
}

void SetSendChunkSize(u32 p0) {
    gSendChunkSize = (u16) p0;
}

BlockTransfer *GetBlockTransfer(void) {
    return (BlockTransfer *) gBlockTransfer;
}

u32 GetNextRequestAddress(void) {
    return ((u32) (&gNextRequest));
}

#pragma thumb off

#pragma thumb on

u32 TrySetNextRequest(const BlockTransferRecord *a) {
    u32 v1;
    s32 *v2;
    v1 = OS_DisableInterrupts();
    if (gBlockTransferStarted != 1) {
        OS_RestoreInterrupts(v1);
        return 0;
    }
    v2 = (s32 *) GetNextRequestAddress();
    if (v2 == NULL || *v2 != 0) {
        OS_RestoreInterrupts(v1);
        return 0;
    }
    MIi_CpuCopy32(a, gNextRequest, 0x9c);
    OS_RestoreInterrupts(v1);
    return 1;
}

#pragma thumb off

#pragma thumb on

BlockListNode *GetBlockListHead(void) {
    return data_0216f3d8;
}

void SetBlockListHead(BlockListNode *p0) {
    data_0216f3d8 = p0;
}

#pragma thumb off

#pragma thumb on

BlockListNode *FindBlockById(u32 a) {
    BlockListNode *v1;
    for (v1 = GetBlockListHead(); v1 != NULL; v1 = v1->mNext) {
        if (v1->mId == a) {
            return v1;
        }
    }
    return NULL;
}

#pragma thumb off

#pragma thumb on

void SetOwnIndex(u32 p0) {
    gOwnIndex = p0;
}

u32 GetOwnIndex(void) {
    return gOwnIndex;
}

#pragma thumb off

#pragma thumb on

s32 GetLowestSetBitIndex(s32 a) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((a >> i) & 1) != 0) {
            return i;
        }
    }
    return -1;
}

u32 GetChunkBitmapSize(s32 a) {
    s32 v1;
    s32 v2;
    v1 = GetReceiveChunkSize();
    v2 = a / v1 + ((a % v1) != 0 ? 1 : 0);
    return ((v2 >> 5) + ((v2 & 0x1f) != 0 ? 1 : 0)) << 2;
}

BOOL TryGetBlockReceiveProgress(u32 a, s32 b, s32 *c, s32 *d) {
    BlockTransfer *v1;
    ChunkReceiveState *v2;
    v1 = GetBlockTransfer();
    v2 = &v1->mEntries[b].mReceive;
    if (v1->mCurrentRequest.mKind == 4 && v1->mCurrentRequest.mUnk_14 == a) {
        *d = v2->mChunkCount;
        *c = v2->mReceivedChunkCount;
        return TRUE;
    }
    return FALSE;
}

u32 TrySetChunkSizes(s32 a, s32 b) {
    switch (GetBlockTransfer()->mCurrentRequest.mKind) {
        case 4:
        case 6:
            return 0;
    }
    SetSendChunkSize(a - 0xe);
    SetReceiveChunkSize(b - 0xe);
    return 1;
}

#pragma thumb off

#pragma thumb on

int CountBlocks(void) {
    int v1;
    BlockListNode *v2;
    v1 = 0;
    for (v2 = GetBlockListHead(); v2 != NULL; v2 = v2->mNext) {
        v1 = v1 + 1;
    }
    return v1;
}

#pragma thumb off

#pragma thumb on

s32 AddBlock(BlockListNode *a, u32 b, const void *c, u8 *d, u32 e, u16 f) {
    BlockListNode *v1;
    u32 v2;
    v2 = OS_DisableInterrupts();
    if (GetBlockListHead() == NULL) {
        SetBlockListHead(a);
    } else {
        for (v1 = GetBlockListHead(); v1->mNext != NULL; v1 = v1->mNext) {
        }
        v1->mNext = a;
    }
    if (d == NULL) {
        a->mHasNoData = 1;
    } else {
        a->mData = d;
        a->mHasNoData = 0;
    }
    a->mNext = NULL;
    a->mId = b;
    a->mSize = e;
    a->mUnk_30 = f;
    if (c != NULL) {
        MI_CpuCopy8(c, a->mUnk_08, 0x20);
    } else {
        MI_CpuFill8(a->mUnk_08, 0, 0x20);
    }
    OS_RestoreInterrupts(v2);
    return 1;
}

BlockListNode *RemoveBlock(u32 a) {
    BlockListNode *v1;
    BlockListNode *v2;
    u32 v3;
    v3 = OS_DisableInterrupts();
    v1 = GetBlockListHead();
    if (v1 == NULL) {
        OS_RestoreInterrupts(v3);
        return NULL;
    }
    if (v1->mId == a) {
        SetBlockListHead(v1->mNext);
        OS_RestoreInterrupts(v3);
        return v1;
    }
    for (v2 = v1->mNext; v2 != NULL; v1 = v2, v2 = v2->mNext) {
        if (v2->mId == a) {
            v1->mNext = v2->mNext;
            OS_RestoreInterrupts(v3);
            return v2;
        }
    }
    OS_RestoreInterrupts(v3);
    return NULL;
}

u32 RequestBlockCount(u16 a, void (*b)(BlockTransferRecord *)) {
    BlockTransferRecord v1;
    v1.mKind = 2;
    v1.mIndexMask = a;
    v1.mCallback = b;
    return TrySetNextRequest(&v1);
}

u32 RequestBlockNode(u16 a, u32 b, const void *c, void (*d)(BlockTransferRecord *)) {
    BlockTransferRecord v1;
    v1.mKind = 6;
    v1.mIndexMask = a;
    v1.mCallback = d;
    v1.mUnk_14 = b;
    v1.mUnk_18 = 0x28;
    MIi_CpuCopy32(c, &v1.mUnk_1c, 0x40);
    return TrySetNextRequest(&v1);
}

u32 RequestBlockData(u16 a, u32 b, const void *c, u32 d, const void *e, void (*f)(BlockTransferRecord *)) {
    BlockTransferRecord v1;
    v1.mKind = 4;
    v1.mIndexMask = a;
    v1.mCallback = f;
    v1.mUnk_14 = b;
    v1.mUnk_18 = d;
    MIi_CpuCopy32(c, &v1.mUnk_1c, 0x40);
    MIi_CpuCopy32(e, &v1.mChunkBitmaps, 0x40);
    return TrySetNextRequest(&v1);
}

u32 RequestSendBytes(u16 a, const void *b, s32 c, void (*d)(void)) {
    BlockTransferRecord v1;
    BlockTransferRecord *v2;
    if (c < 0 || c > 9) {
        return 0;
    }
    v1.mKind = 10;
    v2 = &v1;
    v2->mIndexMask = a;
    v2->mCallback = (void (*)(BlockTransferRecord *)) d;
    MI_CpuCopy8(b, &v2->mUnk_14, c);
    *((u8 *) v2 + 0x1d) = c;
    return TrySetNextRequest(&v1);
}

s32 func_02006c2c(u8 *a, s32 b) {
    BlockTransfer *v1;
    s32 i;
    s32 v2;
    v1 = GetBlockTransfer();
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = ReplyToBytesPacket(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = ReplyToBlockCountRequest(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = ReplyToBlockNodeRequest(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = ReplyToNoMissingChunk(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    v2 = WriteCurrentRequestPacket(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    v2 = StartNextRequest(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = ReplyToBlockDataRequest(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    for (i = 1; i < 16; i++) {
        v2 = ReplyToBlockNodeRequestAlways(v1, i, a, b);
        if (v2 != 0) {
            return v2;
        }
    }
    return WriteEmptyPacket(a, 0xfffe, 0);
}

#pragma thumb off

#pragma thumb on

void ReceivePacketFromIndex(u32 a, const u8 *b, int c) {
    if (0 < c) {
        ParseReceivedPacket(GetBlockTransfer(), a, b, c);
    }
}

void func_02006bec(const u8 *a, u32 b) {
    ParseReceivedPacket(GetBlockTransfer(), 0, a, b);
}

#pragma thumb off

#pragma thumb on

void func_02006b50(u8 *a, s32 b) {
    BlockTransfer *v1;
    v1 = GetBlockTransfer();
    if (ReplyToBytesPacket(v1, 0, a, b) != 0) {
        return;
    }
    if (ReplyToBlockCountRequest(v1, 0, a, b) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequest(v1, 0, a, b) != 0) {
        return;
    }
    if (ReplyToNoMissingChunk(v1, 0, a, b) != 0) {
        return;
    }
    if (ReplyToBlockDataRequest(v1, 0, a, b) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequestAlways(v1, 0, a, b) != 0) {
        return;
    }
    if (WriteCurrentRequestPacket(v1, a, b) != 0) {
        return;
    }
    if (StartNextRequest(v1, a, b) != 0) {
        return;
    }
    WriteEmptyPacket(a, 0xffff, 0);
}

void func_02006aac(s32 a, s32 b, void (*c)(BlockTransferRecord *)) {
    BlockTransferRecord v1;
    BlockTransfer *v2;
    s32 i;
    u32 v3;
    v3 = OS_DisableInterrupts();
    if (gBlockTransferStarted == 1) {
        OS_RestoreInterrupts(v3);
        return;
    }
    gBlockTransferStarted = 1;
    SetOwnIndex(0);
    SetBlockListHead(NULL);
    v2 = GetBlockTransfer();
    v2->mCurrentRequest.mKind = 0;
    v2->mCurrentRequest.mIndexMask = 0;
    v2->mCurrentRequest.mFromIndexMask = 0;
    v2->mCurrentRequest.mCallback = NULL;
    v2->mCallbackRecord.mKind = 0;
    v2->mCallbackRecord.mIndexMask = 0;
    v2->mCallbackRecord.mFromIndexMask = 0;
    v2->mCallbackRecord.mCallback = c;
    for (i = 0; i < 16; i++) {
        v2->mEntries[i].mLastCallbackId = 0;
    }
    v1.mKind = 0;
    TrySetNextRequest(&v1);
    ResetRequestId();
    SetSendChunkSize(a - 0xe);
    SetReceiveChunkSize(b - 0xe);
    OS_RestoreInterrupts(v3);
}

void func_02006a10(void (*a)(BlockTransferRecord *)) {
    BlockTransferRecord v1;
    BlockTransfer *v2;
    s32 i;
    u32 v3;
    v3 = OS_DisableInterrupts();
    if (gBlockTransferStarted == 1) {
        OS_RestoreInterrupts(v3);
        return;
    }
    gBlockTransferStarted = 1;
    SetOwnIndex(-1);
    SetBlockListHead(NULL);
    v2 = GetBlockTransfer();
    v2->mCurrentRequest.mKind = 0;
    v2->mCurrentRequest.mIndexMask = 0;
    v2->mCurrentRequest.mFromIndexMask = 0;
    v2->mCurrentRequest.mCallback = NULL;
    v2->mCallbackRecord.mKind = 0;
    v2->mCallbackRecord.mIndexMask = 0;
    v2->mCallbackRecord.mFromIndexMask = 0;
    v2->mCallbackRecord.mCallback = a;
    for (i = 0; i < 16; i++) {
        v2->mEntries[i].mLastCallbackId = 0;
    }
    v1.mKind = 0;
    TrySetNextRequest(&v1);
    ResetRequestId();
    SetSendChunkSize(0);
    SetReceiveChunkSize(0);
    OS_RestoreInterrupts(v3);
}

void StopBlockTransfer(void) {
    BlockTransferRecord v1;
    BlockTransfer *v2;
    s32 i;
    u32 v3;
    v3 = OS_DisableInterrupts();
    if (gBlockTransferStarted == 0) {
        OS_RestoreInterrupts(v3);
        return;
    }
    gBlockTransferStarted = 0;
    SetOwnIndex(-1);
    SetBlockListHead(NULL);
    v2 = GetBlockTransfer();
    v2->mCurrentRequest.mKind = 0;
    v2->mCurrentRequest.mIndexMask = 0;
    v2->mCurrentRequest.mFromIndexMask = 0;
    v2->mCurrentRequest.mCallback = NULL;
    v2->mCallbackRecord.mKind = 0;
    v2->mCallbackRecord.mIndexMask = 0;
    v2->mCallbackRecord.mFromIndexMask = 0;
    v2->mCallbackRecord.mCallback = NULL;
    for (i = 0; i < 16; i++) {
        v2->mEntries[i].mLastCallbackId = 0;
    }
    v1.mKind = 0;
    TrySetNextRequest(&v1);
    ResetRequestId();
    SetSendChunkSize(-1);
    SetReceiveChunkSize(-1);
    OS_RestoreInterrupts(v3);
}

u32 func_02006954(u8 *a, s32 b) {
    u16 v1;
    v1 = 0;
    if (b > 0 && a != NULL) {
        v1 = func_02006c2c(a, b);
    }
    return v1;
}

#pragma thumb off
