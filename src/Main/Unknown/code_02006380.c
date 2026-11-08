#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_0214d018.h"

#pragma thumb on

static inline u8 *func_0214d1fc_inline(const void *v1, u8 *v2, u32 n) {
    MI_CpuCopy8(v1, v2, n);
    return v2 + n;
}

u32 BuildChildPacket(u8 *buffer, s32 bufferSize) {
    if (bufferSize > 0 && buffer != NULL) {
        BuildChildPacketUnchecked(buffer, bufferSize);
    }
}

void ReceiveParentPacketChecked(const u8 *packet, u32 size) {
    if (packet != NULL && size != 0 && size != 0xffff) {
        ReceiveParentPacket(packet, size);
    }
}

// Packet kind 1: the header and one byte, sent when nothing else is waiting.
s32 WriteEmptyPacket(u8 *buffer, u16 indexMask, u8 requestId) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 1;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    MI_CpuCopy8(&requestId, cursor, 1);
    return cursor + 1 - buffer;
}

// Packet kind 2: asks for the block count and carries both chunk sizes.
s32 WriteBlockCountRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 sendChunkSize, u32 receiveChunkSize) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 2;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&sendChunkSize, cursor, 2);
    MI_CpuCopy8(&receiveChunkSize, cursor, 2);
    return cursor + 2 - buffer;
}

// Packet kind 3: answers kind 2 with the block count and both chunk sizes.
s32 WriteBlockCountReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, s16 blockCount, u32 sendChunkSize,
                               u32 receiveChunkSize) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 3;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&blockCount, cursor, 2);
    cursor = func_0214d1fc_inline(&sendChunkSize, cursor, 2);
    MI_CpuCopy8(&receiveChunkSize, cursor, 2);
    return cursor + 2 - buffer;
}

// Packet kind 4: asks for one chunk of the block with this id.
s32 WriteBlockDataRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 4;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&blockId, cursor, 4);
    MI_CpuCopy8(&chunkIndex, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 5: one chunk of a block (zeros when no data pointer is given).
s32 WriteBlockDataPacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, s32 dataSize) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 5;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&blockId, cursor, 4);
    cursor = func_0214d1fc_inline(&chunkIndex, cursor, 4);
    if (data == 0) {
        MI_CpuFill8(cursor, 0, dataSize);
    } else {
        MI_CpuCopy8((void *) data, cursor, dataSize);
    }
    return cursor + dataSize - buffer;
}

// Packet kind 6: asks for one chunk of a block node by id.
s32 WriteBlockNodeRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 6;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&blockId, cursor, 4);
    MI_CpuCopy8(&chunkIndex, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 7: one chunk of a block node (zeros when no data pointer is given).
s32 WriteBlockNodePacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, u32 dataSize) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 7;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&blockId, cursor, 4);
    cursor = func_0214d1fc_inline(&chunkIndex, cursor, 4);
    if (data == 0) {
        MI_CpuFill8(cursor, 0, dataSize);
    } else {
        MI_CpuCopy8((void *) data, cursor, dataSize);
    }
    return cursor + dataSize - buffer;
}

// Packet kind 8: carries the block id; sent instead of a chunk request when no chunk of the block is missing.
s32 WriteNoMissingChunkPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 8;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    MI_CpuCopy8(&blockId, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 9: answers kind 8 with the block id.
s32 WriteNoMissingChunkReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 9;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    MI_CpuCopy8(&blockId, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 10: up to 9 raw bytes and their length.
s32 WriteBytesPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 *bytes, u32 byteCount) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 0xa;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    cursor = func_0214d1fc_inline(&requestId, cursor, 1);
    cursor = func_0214d1fc_inline(&byteCount, cursor, 1);
    MI_CpuCopy8(bytes, cursor, 9);
    return cursor + 9 - buffer;
}

// Packet kind 11: answers kind 10.
s32 WriteBytesReplyPacket(u8 *buffer, u16 indexMask, u8 requestId) {
    struct {
        u8 m0;
        u16 m2;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.m2 = indexMask;
    header.m0 = 0xb;
    cursor = func_0214d1fc_inline(&header, cursor, 1);
    cursor = func_0214d1fc_inline(&header.m2, cursor, 2);
    MI_CpuCopy8(&requestId, cursor, 1);
    return cursor + 1 - buffer;
}

// Picks the chunk to send next: skips the last two indexes sent for this block; -1 for an unknown id.
s32 PickSendChunkIndex(u32 blockId, s32 chunkIndex) {
    BlockListNode *node;
    s32 i;
    node = GetBlockListHead();
    if (blockId < 1000) {
        return chunkIndex;
    }
    for (; node != NULL; node = node->mNext) {
        if (node->mId == blockId) {
            if (blockId == gLastSentBlockId) {
                i = 0;
                while (chunkIndex == gLastSentChunkIndex || chunkIndex == gPrevSentChunkIndex) {
                    chunkIndex++;
                    if (chunkIndex > (node->mSize + (s32) GetSendChunkSize() - 1) / (s32) GetSendChunkSize() - 1) {
                        chunkIndex = 0;
                    }
                    i++;
                    if (i > 2) {
                        break;
                    }
                }
            }
            gLastSentBlockId = blockId;
            gPrevSentChunkIndex = gLastSentChunkIndex;
            gLastSentChunkIndex = chunkIndex;
            return chunkIndex;
        }
    }
    return -1;
}

// Address of one chunk; ids under 1000 count positions in the block list, higher ids are block ids.
u32 GetBlockChunkAddress(u32 blockIdOrPosition, u32 chunkIndex) {
    BlockListNode *v1;
    u32 i;
    v1 = GetBlockListHead();
    if (blockIdOrPosition < 1000) {
        for (i = 0;; i++, v1 = v1->mNext) {
            if (v1 == NULL) {
                break;
            }
            if (i == blockIdOrPosition) {
                return (u32) v1 + chunkIndex * GetSendChunkSize();
            }
        }
        return 0;
    }
    for (; v1 != NULL; v1 = v1->mNext) {
        if (v1->mId == blockIdOrPosition) {
            v1 = (BlockListNode *) v1->mData;
            return (u32) v1 + chunkIndex * GetSendChunkSize();
        }
    }
    return 0;
}

void SetupChunkReceiveState(ChunkReceiveState *state, s32 size, void *chunkBitmap, u32 buffer) {
    s32 chunkSize;
    chunkSize = GetReceiveChunkSize();
    state->mSize = size;
    state->mPickedChunkIndex = 0;
    state->mLastReceivedChunkIndex = 0;
    state->mReceivedChunkCount = 0;
    state->mChunkCount = size / chunkSize + ((size % chunkSize) != 0 ? 1 : 0);
    state->mChunkBitmap = chunkBitmap;
    state->mBuffer = (u8 *) buffer;
    MI_CpuFill8(chunkBitmap, 0, GetChunkBitmapSize(size));
}

BOOL IsChunkReceived(ChunkReceiveState *state, s32 chunkIndex) {
    u32 bitmapWord;
    bitmapWord = state->mChunkBitmap[chunkIndex >> 5];
    if ((bitmapWord & (1 << (chunkIndex & 0x1f))) != 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off
