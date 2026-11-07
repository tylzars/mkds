#include "Main/Unknown/code_0200c0d8.h"

#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"
#include "03/code_021b94b8.h"

#pragma thumb on

void SetupPieceSizes(s32 packetSize) {
    gPieceSizes.mPieceSize = packetSize - 2;
    gPieceSizes.mPieceCount = 0x1e / gPieceSizes.mPieceSize;
    gPieceSizes.mUnk_08 = 0x1e;
}

#pragma thumb off

#pragma thumb on
void SetupPieceBuffer(u32 buffer) {
    u32 address = buffer;
    u32 value1;
    u32 byteCount;
    u32 value3;
    value1 = (u32) &gPieceBuffer;
    *(u32 *) ((value1) + 0u) = address;
    value1 = 0u;
    byteCount = 0x21cu;
    MI_CpuFill8((void *) address, value1, byteCount);
}
#pragma thumb off

#pragma thumb on

void ClearChildPieces(s32 child) {
    s32 i;

    if (gPieceBuffer != NULL) {
        i = child - 1;
        MI_CpuFill8(&gPieceBuffer->mSlots[i * 0x20], 0, 0x1e);
        gPieceBuffer->mReceivedPieceMasks[i] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u8 *WriteParentMessage(u8 *input, u8 *output) {
    ParentMessage *message;
    u8 *cursor;
    message = (ParentMessage *) input;
    cursor = output;
    *cursor++ = message->mKind;
    switch (message->mKind) {
        case 4:
            *cursor++ = message->mUnk_02;
            *cursor++ = (message->mUnk_02 & 0xff00) >> 8;
            *cursor++ = message->mUnk_04;
            *cursor++ = (message->mUnk_04 & 0xff00) >> 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return cursor;
}

u8 *ReadChildMessage(u8 *bytes, ChildMessage *message, u32 child) {
    u8 *v1;
    message->mKind = bytes[0];
    switch (message->mKind) {
        case 7:
            if (AreAllPiecesReceived(child) != 0) {
                return (u8 *) gPieceBuffer + (child - 1) * 0x20;
            }
            *(u8 *) &message->mUnk_02 = bytes[1];
            if (*(u8 *) &message->mUnk_02 > gPieceSizes.mPieceCount) {
                return NULL;
            }
            MI_CpuCopy8(bytes + 2, (u8 *) message + 3, gPieceSizes.mPieceSize);
            v1 = StorePiece(message, child);
            break;
        case 8:
            message->mUnk_02 = bytes[1] & 0xff;
            v1 = bytes + 3;
            message->mUnk_02 |= (bytes[2] << 8) & 0xff00;
            break;
        case 9:
            message->mUnk_02 = bytes[1] & 0xff;
            v1 = bytes + 3;
            message->mUnk_02 |= (bytes[2] << 8) & 0xff00;
            MI_CpuCopy8(v1, message->mUnk_04, gPieceSizes.mPieceSize);
            v1 += gPieceSizes.mPieceSize;
            break;
        default:
            return NULL;
    }
    return v1;
}

u8 *StorePiece(ChildMessage *message, u32 child) {
    PieceBuffer *pieceBuffer;
    u8 pieceIndex;
    u32 slotOffset;
    u32 slotIndex;
    pieceBuffer = gPieceBuffer;
    if (pieceBuffer == NULL) {
        return NULL;
    }
    pieceIndex = *(u8 *) &message->mUnk_02;
    if (pieceIndex > gPieceSizes.mPieceCount) {
        return NULL;
    }
    slotIndex = child - 1;
    slotOffset = slotIndex << 5;
    MI_CpuCopy8((u8 *) message + 3, (u8 *) pieceBuffer + slotOffset + pieceIndex * gPieceSizes.mPieceSize,
                gPieceSizes.mPieceSize);
    gPieceBuffer->mReceivedPieceMasks[slotIndex] |= 1 << pieceIndex;
    if (AreAllPiecesReceived(child) != 0) {
        return (u8 *) gPieceBuffer + slotOffset;
    }
    return NULL;
}

u32 AreAllPiecesReceived(u32 child) {
    u16 i;
    s32 pieceCount;
    u32 receivedMask;
    i = 0;
    pieceCount = gPieceSizes.mPieceCount;
    if (pieceCount > 0) {
        receivedMask = gPieceBuffer->mReceivedPieceMasks[child - 1];
        do {
            if (((1 << i) & receivedMask) == 0) {
                return 0;
            }
            i++;
        } while (i < pieceCount);
    }
    return 1;
}

u8 *WriteChildMessage(ChildMessage *message, u8 *buffer) {
    u8 *cursor;
    cursor = buffer;
    *cursor++ = message->mKind;
    switch (message->mKind) {
        case 7:
            *cursor++ = *(u8 *) &message->mUnk_02;
            if (*(u8 *) &message->mUnk_02 > gPieceSizes.mPieceCount) {
                return NULL;
            }
            MI_CpuCopy8((u8 *) message + 3, cursor, gPieceSizes.mPieceSize);
            cursor += gPieceSizes.mPieceSize;
            break;
        case 9:
            *cursor++ = message->mUnk_02;
            *cursor++ = (message->mUnk_02 & 0xff00) >> 8;
            MI_CpuCopy8(message->mUnk_04, cursor, gPieceSizes.mPieceSize);
            cursor += gPieceSizes.mPieceSize;
            break;
        case 8:
        case 10:
        case 11:
            break;
        default:
            return NULL;
    }
    return cursor;
}

u8 CopyNextPiece(void *output, void *pieces) {
    gLastPieceIndex = (gLastPieceIndex + 1) % gPieceSizes.mPieceCount;
    MI_CpuCopy8((u8 *) pieces + gLastPieceIndex * gPieceSizes.mPieceSize, output, gPieceSizes.mPieceSize);
    return gLastPieceIndex;
}

u8 *ReadParentMessage(ParentMessage *message, u8 *buffer) {
    u8 *v1;
    message->mKind = *buffer++;
    switch (message->mKind) {
        case 4:
            message->mUnk_02 = buffer[0];
            message->mUnk_02 |= buffer[1] << 8;
            message->mUnk_04 = buffer[2];
            v1 = buffer + 3;
            buffer += 4;
            message->mUnk_04 |= *v1 << 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return buffer;
}

#pragma thumb off
