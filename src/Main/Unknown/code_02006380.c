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

u32 BuildChildPacket(u8 *a, s32 b) {
    if (b > 0 && a != NULL) {
        func_02006b50(a, b);
    }
}

void ReceiveParentPacketChecked(const u8 *a, u32 b) {
    if (a != NULL && b != 0 && b != 0xffff) {
        func_02006bec(a, b);
    }
}

// Packet kind 1: the header and one byte, sent when nothing else is waiting.
s32 WriteEmptyPacket(u8 *a, u16 b, u8 c) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 1;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    MI_CpuCopy8(&c, v1, 1);
    return v1 + 1 - a;
}

// Packet kind 2: asks for the block count and carries both chunk sizes.
s32 WriteBlockCountRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 2;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 2);
    MI_CpuCopy8(&e, v1, 2);
    return v1 + 2 - a;
}

// Packet kind 3: answers kind 2 with the block count and both chunk sizes.
s32 WriteBlockCountReplyPacket(u8 *a, u16 b, u8 c, s16 d, u32 e, u32 f) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 3;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 2);
    v1 = func_0214d1fc_inline(&e, v1, 2);
    MI_CpuCopy8(&f, v1, 2);
    return v1 + 2 - a;
}

// Packet kind 4: asks for one chunk of the block with this id.
s32 WriteBlockDataRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 4;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    MI_CpuCopy8(&e, v1, 4);
    return v1 + 4 - a;
}

// Packet kind 5: one chunk of a block (zeros when no data pointer is given).
s32 WriteBlockDataPacket(u8 *a, u32 b, u8 c, u32 d, u32 e, u32 f, s32 g) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 5;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    v1 = func_0214d1fc_inline(&e, v1, 4);
    if (f == 0) {
        MI_CpuFill8(v1, 0, g);
    } else {
        MI_CpuCopy8((void *) f, v1, g);
    }
    return v1 + g - a;
}

// Packet kind 6: asks for one chunk of a block node by id.
s32 WriteBlockNodeRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 6;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    MI_CpuCopy8(&e, v1, 4);
    return v1 + 4 - a;
}

// Packet kind 7: one chunk of a block node (zeros when no data pointer is given).
s32 WriteBlockNodePacket(u8 *a, u32 b, u8 c, u32 d, u32 e, u32 f, u32 g) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 7;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&d, v1, 4);
    v1 = func_0214d1fc_inline(&e, v1, 4);
    if (f == 0) {
        MI_CpuFill8(v1, 0, g);
    } else {
        MI_CpuCopy8((void *) f, v1, g);
    }
    return v1 + g - a;
}

// Packet kind 8: carries the block id; sent instead of a chunk request when no chunk of the block is missing.
s32 func_020065f8(u8 *a, u16 b, u8 c, u32 d) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 8;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    MI_CpuCopy8(&d, v1, 4);
    return v1 + 4 - a;
}

// Packet kind 9: answers kind 8 with the block id.
s32 func_020065a8(u8 *a, u16 b, u8 c, u32 d) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 9;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    MI_CpuCopy8(&d, v1, 4);
    return v1 + 4 - a;
}

// Packet kind 10: up to 9 raw bytes and their length.
s32 WriteBytesPacket(u8 *a, u16 b, u8 c, u32 *d, u32 e) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 0xa;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    v1 = func_0214d1fc_inline(&c, v1, 1);
    v1 = func_0214d1fc_inline(&e, v1, 1);
    MI_CpuCopy8(d, v1, 9);
    return v1 + 9 - a;
}

// Packet kind 11: answers kind 10.
s32 WriteBytesReplyPacket(u8 *a, u16 b, u8 c) {
    struct {
        u8 m0;
        u16 m2;
    } v;
    u8 *v1;
    v1 = a;
    v.m2 = b;
    v.m0 = 0xb;
    v1 = func_0214d1fc_inline(&v, v1, 1);
    v1 = func_0214d1fc_inline(&v.m2, v1, 2);
    MI_CpuCopy8(&c, v1, 1);
    return v1 + 1 - a;
}

// Picks the chunk to send next: skips the last two indexes sent for this block; -1 for an unknown id.
s32 PickSendChunkIndex(u32 a, s32 b) {
    BlockListNode *v1;
    s32 i;
    v1 = GetBlockListHead();
    if (a < 1000) {
        return b;
    }
    for (; v1 != NULL; v1 = v1->mNext) {
        if (v1->mId == a) {
            if (a == gLastSentBlockId) {
                i = 0;
                while (b == gLastSentChunkIndex || b == gPrevSentChunkIndex) {
                    b++;
                    if (b > (v1->mSize + (s32) GetSendChunkSize() - 1) / (s32) GetSendChunkSize() - 1) {
                        b = 0;
                    }
                    i++;
                    if (i > 2) {
                        break;
                    }
                }
            }
            gLastSentBlockId = a;
            gPrevSentChunkIndex = gLastSentChunkIndex;
            gLastSentChunkIndex = b;
            return b;
        }
    }
    return -1;
}

// Address of one chunk; ids under 1000 count positions in the block list, higher ids are block ids.
u32 GetBlockChunkAddress(u32 a, u32 b) {
    BlockListNode *v1;
    u32 i;
    v1 = GetBlockListHead();
    if (a < 1000) {
        for (i = 0;; i++, v1 = v1->mNext) {
            if (v1 == NULL) {
                break;
            }
            if (i == a) {
                return (u32) v1 + b * GetSendChunkSize();
            }
        }
        return 0;
    }
    for (; v1 != NULL; v1 = v1->mNext) {
        if (v1->mId == a) {
            v1 = (BlockListNode *) v1->mData;
            return (u32) v1 + b * GetSendChunkSize();
        }
    }
    return 0;
}

void SetupChunkReceiveState(ChunkReceiveState *a, s32 b, void *c, u32 d) {
    s32 v1;
    v1 = GetReceiveChunkSize();
    a->mSize = b;
    a->mPickedChunkIndex = 0;
    a->mLastReceivedChunkIndex = 0;
    a->mReceivedChunkCount = 0;
    a->mChunkCount = b / v1 + ((b % v1) != 0 ? 1 : 0);
    a->mChunkBitmap = c;
    a->mBuffer = (u8 *) d;
    MI_CpuFill8(c, 0, GetChunkBitmapSize(b));
}

BOOL IsChunkReceived(ChunkReceiveState *a, s32 b) {
    u32 v1;
    v1 = a->mChunkBitmap[b >> 5];
    if ((v1 & (1 << (b & 0x1f))) != 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off
