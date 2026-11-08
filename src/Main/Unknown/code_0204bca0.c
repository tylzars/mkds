#include "Main/Unknown/code_0204bca0.h"

#include "03/code_021b94b8.h"
#include "os_thread.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02176000.h"
#include "Main/Unknown/unk_02179000.h"
#include "Main/Unknown/code_0204b714.h"
#include "Main/Unknown/code_0204c000.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "code_02003be0.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/unk_02154000.h"
#include "fs_file.h"
#include "code_02004dc0.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/unk_02165000.h"

typedef struct Unk0204d610_t {
    u8 *mUnk_00;
    u32 mUnk_04;
} Unk0204d610_t;

typedef struct RomTableHeader {
    u8 mUnk_00[0x40];
    u32 mFntOffset;
    u32 mFntSize;
    u32 mFatOffset;
    u32 mFatSize;
    u32 mOverlayTable0Offset;
    u32 mOverlayTable0Size;
    u32 mOverlayTable1Offset;
    u32 mOverlayTable1Size;
} RomTableHeader;

s32 RomArchiveChildProc(FSFile *file, u32 command) {
    switch (command) {
        case 0:
            if (gRomArchiveTransfer.mState != 2) {
                return 5;
            }
            if (file->mArg.p.mUnk_08 == 0) {
                return 0;
            }
            RequestRomArchiveBytes(file);
            return 6;
        case 1:
            return 4;
        default:
            return 8;
    }
}

void CreateRomArchiveBlock(FSFile *file, s32 appendOverlays) {
    RomTableHeader fileHeader;
    FSFile romFile;
    Unk0204d610_t tables[4];
    u32 paddedSizes[4];
    u32 *tablePointers[4];
    u32 *block;
    u32 blockSize;
    enum { K0 } appendOverlayEntries;
    u32 imageOffset;
    u32 positionOffset;
    RomTableHeader *header;
    u32 origin;
    u32 pairSize;
    u32 v13;
    BOOL noFile;
    s32 i;
    BOOL k;

    blockSize = 0;
    noFile = file == NULL;
    appendOverlayEntries = 0;
    appendOverlayEntries = (s32) appendOverlayEntries;
    if (noFile == FALSE) {
        if (appendOverlays != 0) {
            appendOverlayEntries = 1;
        }
    }
    FS_InitFile(&romFile);
    FS_OpenFileDirect(&romFile, FS_FindArchive(data_021651d8, 3), 0, 0x7fffffff, -1);
    if (noFile != FALSE) {
        imageOffset = 0;
        positionOffset = 0;
        header = (RomTableHeader *) 0x027ffe00;
    } else {
        i = file->mUnk_2c - file->mProp.w.mUnk_04;
        imageOffset = i + file->mProp.w.mUnk_04;
        header = &fileHeader;
        positionOffset = imageOffset;
        FS_ReadFile(file, header, 0x60);
        FS_SeekFile(file, i, 0);
    }
    if (appendOverlayEntries == 0) {
        tables[0] = *(Unk0204d610_t *) &header->mFatOffset;
        tables[1] = *(Unk0204d610_t *) &header->mFntOffset;
        tables[2] = *(Unk0204d610_t *) &header->mOverlayTable0Offset;
        tables[3] = *(Unk0204d610_t *) &header->mOverlayTable1Offset;
    } else {
        tables[0] = *(Unk0204d610_t *) 0x027ffe48;
        tables[1] = *(Unk0204d610_t *) 0x027ffe40;
        positionOffset = 0;
        tables[2].mUnk_00 = (u8 *) (header->mOverlayTable0Offset + imageOffset);
        tables[2].mUnk_04 = header->mOverlayTable0Size;
        tables[3].mUnk_00 = (u8 *) (header->mOverlayTable1Offset + imageOffset);
        tables[3].mUnk_04 = header->mOverlayTable1Size;
    }
    blockSize = blockSize + 4;
    for (i = 0; i < 4; i++) {
        paddedSizes[i] = (tables[i].mUnk_04 + 0x1f) & ~0x1f;
        blockSize = blockSize + (paddedSizes[i] + 4);
    }
    if (appendOverlayEntries != 0) {
        for (i = 2; i < 4; i++) {
            v13 = (((tables[i].mUnk_04 >> 5) << 3) + 0x1f) & ~0x1f;
            paddedSizes[0] = paddedSizes[0] + v13;
            blockSize = blockSize + v13;
        }
    }
    v13 = OS_DisableInterrupts();
    block = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, blockSize, NULL);
    OS_RestoreInterrupts(v13);
    *block = positionOffset;
    origin = 0;
    k = FALSE;
    {
        u32 *cursor = block + 1;
        u32 *q;
        s32 j;
        for (j = 0; j < 4; j++) {
            tablePointers[j] = cursor;
            q = tablePointers[j];
            *q = tables[j].mUnk_04;
            FS_SeekFile(&romFile, positionOffset + (u32) tables[j].mUnk_00, origin);
            FS_ReadFile(&romFile, q + 1, *q);
            cursor = OFFSET_PTR(u32, cursor, (paddedSizes[j] + 4));
        }
    }
    if (appendOverlayEntries != 0) {
        u32 *fatBlock = tablePointers[0];
        u8 *fatEntries = (u8 *) (fatBlock + 1);
        s32 entryCount = *fatBlock >> 3;
        OverlayTableEntry *q;
        s32 l;
        u32 *appendCursor = (u32 *) (fatEntries + (entryCount << 3));
        u32 fatPosition = imageOffset + header->mFatOffset;
        pairSize = 8;
        for (i = 2; i < 4; i++) {
            u32 *overlayTable = tablePointers[i];
            s32 overlayCount;
            q = (OverlayTableEntry *) (overlayTable + 1);
            overlayCount = *overlayTable >> 5;
            for (l = 0; l < overlayCount; l++) {
                FS_SeekFile(&romFile, fatPosition + (q[l].mFileId << 3), origin);
                FS_ReadFile(&romFile, appendCursor, pairSize);
                *(u32 *) (fatEntries + ((u32) entryCount * 8)) =
                    *(u32 *) (fatEntries + ((u32) entryCount * 8)) + imageOffset;
                ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] =
                    ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] + imageOffset;
                q[l].mFileId = entryCount;
                entryCount++;
                appendCursor += 2;
            }
        }
        *tablePointers[0] = entryCount << 3;
    }
    DC_FlushRange(block, blockSize);
    DC_WaitWriteBufferEmpty();
    FS_CloseFile(&romFile);
    gRomArchiveTransfer.mArchiveBlock = block;
    gRomArchiveTransfer.mArchiveBlockSize = blockSize;
}

u32 ReloadRomArchiveFromBlock(u32 *block) {
    Unk0204d610_t tables[4];
    u32 positionOffset;
    FSArchive *archive;
    s32 i;

    archive = FS_FindArchive(data_021651d4, 3);
    FS_UnloadArchive(archive);
    FS_SetArchiveProc(archive, RomArchiveChildProc, -1);
    positionOffset = *block++;
    for (i = 0; i < 4; i++) {
        tables[i].mUnk_00 = (u8 *) (block + 1);
        tables[i].mUnk_04 = *block;
        block = (u32 *) (tables[i].mUnk_00 + ((tables[i].mUnk_04 + 0x1f) & ~0x1f));
    }
    FS_LoadArchive(archive, NULL, (u32) tables[0].mUnk_00, tables[0].mUnk_04, (u32) tables[1].mUnk_00,
                   tables[1].mUnk_04, func_0204db48, func_0204db40);
    FS_AttachOverlayTable(0, tables[2].mUnk_00, tables[2].mUnk_04);
    FS_AttachOverlayTable(1, tables[3].mUnk_00, tables[3].mUnk_04);
    return positionOffset;
}

void RomArchiveSendCallback(void) {
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;

    if (transfer->mState == 0) {
        return;
    }
    if (transfer->mIsParent == 0) {
        return;
    }
    transfer->mUnk_0440.mMessageSendPending = FALSE;
    SendRomArchiveMessage();
}

void SendRomArchiveMessage(void) {
    RomArchiveMessage sizeMessage;
    RomArchiveMessage replyMessage;
    BOOL v6;
    Unk02175ec0_440 *firstEntry;
    s32 sendMask;
    s32 i;
    s32 v5;
    s32 v7;
    Unk02175ec0_440 *entry;
    u32 childPacketSize;
    s32 g;
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;
    RomArchiveParentView *view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    s32 blockId;

    if (transfer->mIsParent == 0) {
        return;
    }
    if (view->mMessageSendPending != FALSE) {
        return;
    }
    view->mUnk_46cc = view->mUnk_46cc & view->mUnk_46d8;
    view->mUnk_46d0 = view->mUnk_46d0 & view->mUnk_46d8;
    view->mUnk_46dc = view->mUnk_46dc & view->mUnk_46d8;
    view->mUnk_46e8 = view->mUnk_46e8 & view->mUnk_46d8;
    if (view->mUnk_46e0 != FALSE && view->mUnk_46e4 == 0) {
        g = view->mUnk_46ec;
        childPacketSize = gRomArchiveTransfer.mChildPacketSize;
        view->mUnk_46e0 = FALSE;
        gRomArchiveTransfer.mParentPacketSize = g;
        TrySetChunkSizes(g, childPacketSize);
        g = view->mUnk_46e8;
        if (g == 0) {
            return;
        }
        sizeMessage.mKind = 1;
        sizeMessage.mUnk_00_8 = 0;
        sizeMessage.mUnk_04 = 0;
        sizeMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
        sizeMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
        if (RequestSendBytes(g, &sizeMessage, 9, RomArchiveSendCallback) == 0) {
            return;
        }
        view->mMessageSendPending = TRUE;
        view->mUnk_46e8 = 0;
        return;
    }
    sendMask = view->mUnk_46cc;
    if (sendMask == 0) {
        return;
    }
    v5 = view->mUnk_46d0;
    firstEntry = NULL;
    if (v5 != 0 && v5 == (v5 & sendMask)) {
        v6 = TRUE;
    } else {
        v6 = FALSE;
    }
    if (v6 != FALSE) {
        sendMask = v5;
    } else {
        sendMask = sendMask & ~v5;
    }
    entry = view->mUnk_0000;
    for (i = 0;; entry++, i++) {
        v7 = 1 << i;
        if (v7 > sendMask) {
            break;
        }
        if ((v7 & sendMask) != 0) {
            if (firstEntry == NULL) {
                firstEntry = entry;
            } else if (firstEntry->mUnk_00_0 != entry->mUnk_00_0 || firstEntry->mUnk_04 != entry->mUnk_04) {
                sendMask = sendMask & ~v7;
            }
        }
    }
    if (v6 != FALSE) {
        if (sendMask != v5) {
            view->mUnk_46d0 = 0;
        }
    }
    if (firstEntry == NULL) {
        return;
    }
    switch (firstEntry->mUnk_00_0) {
        case 0:
            firstEntry->mUnk_00_0 = 1;
            break;
        case 2:
            firstEntry->mUnk_00_0 = 3;
            view->mUnk_46dc = view->mUnk_46dc & ~sendMask;
            break;
    }
    blockId = *(volatile s32 *) &firstEntry->mUnk_04;
    replyMessage.mKind = (u8) firstEntry->mUnk_00_0;
    replyMessage.mUnk_04 = blockId;
    replyMessage.mUnk_00_8 = 1;
    replyMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    replyMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (RequestSendBytes(sendMask, &replyMessage, 9, RomArchiveSendCallback) == 0) {
        return;
    }
    view->mMessageSendPending = TRUE;
    view->mUnk_46cc = view->mUnk_46cc & ~sendMask;
}

void func_0204d18c(RomArchiveParentView *view, RomArchiveFileNode *node, s32 c) {
    u32 savedInterrupts;
    s32 pendingMask;
    s32 blockId;
    s32 index;
    s32 length;
    Unk02175ec0_440 *entry;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveTransfer.mState != 0) {
        pendingMask = node->mPendingChildMask;
        node->mPendingChildMask = 0;
        view->mUnk_46cc = view->mUnk_46cc | pendingMask;
        if (node->mChildCount <= 0) {
            length = node->mFile.mProp.w.mUnk_08 - node->mFile.mProp.w.mUnk_04;
            blockId = node->mBlockId;
            AddBlock(&node->mBlockNode, blockId, data_usa_0215470c, length <= 0x400u ? node->mBuffers[0] : 0, length,
                     0);
            func_0204d110(&view->mPendingHead, &view->mActiveHead, node);
            node->mState = 2;
        }
        entry = view->mUnk_0000;
        for (index = 0;; index++) {
            if ((1 << index) > pendingMask) {
                break;
            }
            if (((1 << index) & pendingMask) != 0) {
                node->mChildCount = node->mChildCount + 1;
                entry->mUnk_04 = node->mBlockId;
            }
            entry++;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
}

// Moves node c to the head of list b when it is in list a; does nothing otherwise.
void func_0204d110(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node) {
    u32 savedInterrupts;
    RomArchiveFileNode *current;
    RomArchiveFileNode *next;

    savedInterrupts = OS_DisableInterrupts();
    current = *fromHead;
    if (current == node) {
        *fromHead = node->mNext;
        node->mNext = *toHead;
        *toHead = node;
    } else if (current != NULL) {
        do {
            next = current->mNext;
            if (next == node) {
                current->mNext = node->mNext;
                node->mNext = *toHead;
                *toHead = node;
                break;
            }
            current = next;
        } while (next != NULL);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

void FreeRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node) {
    func_0204d110(&view->mPendingHead, &view->mFreeHead, node);
    node->mState = 0;
    view->mUnk_46e4 = view->mUnk_46e4 - 1;
}

void RequestRomArchiveBytes(FSFile *file) {
    RomArchiveMessage message;
    s32 readLength;
    u32 v3;
    void *oldBuffer;
    u32 freeInterrupts;
    RomArchiveChildView *childView;
    void *newBuffer;
    u32 allocInterrupts;
    s32 requestedLength;

    readLength = file->mArg.p.mUnk_08;
    childView = (RomArchiveChildView *) &data_usa_021762e0;
    if (readLength < 0) {
        readLength = childView->mMaxReadSize;
        childView->mMaxReadSize = 0;
    }
    if (childView->mMaxReadSize < readLength) {
        childView->mMaxReadSize = readLength;
        oldBuffer = childView->mChunkBitmapBuffer;
        if (oldBuffer != NULL) {
            freeInterrupts = OS_DisableInterrupts();
            gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, oldBuffer);
            OS_RestoreInterrupts(freeInterrupts);
        }
        v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
             (gRomArchiveTransfer.mParentPacketSize - 0xe);
        v3 = ((v3 + 0x1f) >> 2) << 4;
        allocInterrupts = OS_DisableInterrupts();
        newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
        OS_RestoreInterrupts(allocInterrupts);
        childView->mChunkBitmapBuffer = newBuffer;
        childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
    }
    gRomArchiveTransfer.mPendingFile = file;
    requestedLength = *(volatile s32 *) &file->mArg.p.mUnk_08;
    message.mUnk_04 = childView->mPositionOffset + file->mUnk_2c;
    message.mKind = 0;
    message.mUnk_00_8 = requestedLength;
    message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (RequestSendBytes(1, &message, 9, RomArchiveSendCallback) != 0) {
        return;
    }
    OS_Terminate();
}

void SendRomArchivePacket(void) {
    RomArchiveTransfer *transfer;
    s32 isParent;
    u16 packetSize;
    u16 builtSize;
    u8 *buffer;

    transfer = &gRomArchiveTransfer;
    if (transfer->mState == 0) {
        return;
    }
    transfer->mUnk_0004 = TRUE;
    SendRomArchiveMessage();
    transfer = &gRomArchiveTransfer;
    isParent = transfer->mIsParent;
    if (isParent != 0) {
        packetSize = transfer->mParentPacketSize;
    } else {
        packetSize = transfer->mChildPacketSize;
    }
    if (transfer->mUnk_0004 == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = BuildParentPacket(buffer, packetSize);
    } else {
        builtSize = BuildChildPacket(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->mUnk_0004 = gRomArchiveTransfer.mSendPending == FALSE;
}

void RomArchivePortCallback(Unk0204cc94 *message) {
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    s32 isParent;
    u16 packetSize;
    u16 builtSize;
    u8 *buffer;
    const u8 *data;
    u16 dataLength;
    u16 fromIndex;

    transfer = &gRomArchiveTransfer;
    view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    if (transfer->mState == 0) {
        return;
    }
    switch (message->mUnk_04) {
        case 7:
            isParent = transfer->mIsParent;
            if (isParent == 0) {
                return;
            }
            if (transfer->mSendPending != FALSE) {
                return;
            }
            if (isParent != 0) {
                packetSize = transfer->mParentPacketSize;
            } else {
                packetSize = transfer->mChildPacketSize;
            }
            if (transfer->mUnk_0004 == FALSE) {
                return;
            }
            buffer = transfer->mPacketBuffer;
            if (isParent != 0) {
                builtSize = BuildParentPacket(buffer, packetSize);
            } else {
                builtSize = BuildChildPacket(buffer, packetSize);
            }
            transfer->mSendPending =
                WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
            transfer->mUnk_0004 = gRomArchiveTransfer.mSendPending == FALSE;
            return;
        case 9:
            if (transfer->mIsParent == 0) {
                return;
            }
            view->mUnk_46d8 = view->mUnk_46d8 & ~(1 << message->mUnk_12);
            return;
        case 21:
            data = message->mUnk_0c;
            dataLength = message->mUnk_10;
            if (transfer->mIsParent != 0) {
                fromIndex = message->mUnk_12;
                view->mUnk_46d8 = view->mUnk_46d8 | (1 << fromIndex);
                ReceivePacketFromIndexChecked(data, dataLength, fromIndex);
            } else {
                ReceiveParentPacketChecked(data, dataLength);
            }
            return;
    }
}

void RomArchiveParentCallback(Unk0204c320 *record) {
    s32 fromIndex;
    Unk0204c320_14 *payload;
    s32 v7;
    u32 fileLength;
    RomArchiveParentView *view;
    RomArchiveFileNode *queuedNode;
    u32 savedInterrupts;
    RomArchiveFileNode *activeNode;
    RomArchiveFileNode *foundNode;
    u32 v5;
    Unk0204c320_14 *q;
    s32 j;
    s32 k;
    RomArchiveFileNode *node;
    s32 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v13;
    s32 v14;
    FSFile *file;
    s32 blockId;
    s32 v17;

    fromIndex = GetLowestSetBitIndex(record->mUnk_0a);
    if (record->mUnk_00 != 0xc) {
        return;
    }
    switch (record->mUnk_04) {
        case 2:
            break;
        case 8:
            break;
        case 10:
            view = &data_usa_021762e0;
            payload = &record->mUnk_14;
            view->mUnk_0000[fromIndex] = payload->mUnk_0e;
            switch (record->mUnk_14.mUnk_m.mKind) {
                case 0:
                    fileLength = record->mUnk_14.mUnk_m.mUnk_00_8;
                    v5 = (record->mUnk_14.mUnk_m.mPacketSizeHigh << 8) | payload->mUnk_m.mPacketSizeLow;
                    v7 = payload->mUnk_m.mUnk_04;
                    if (view->mUnk_46e0 != FALSE || v5 != gRomArchiveTransfer.mParentPacketSize) {
                        view->mUnk_46e0 = TRUE;
                        view->mUnk_46e8 = view->mUnk_46e8 | (1 << fromIndex);
                        view->mUnk_46dc = view->mUnk_46dc | (1 << fromIndex);
                        return;
                    }
                    for (foundNode = view->mActiveHead; foundNode != NULL; foundNode = foundNode->mNext) {
                        if (foundNode->mState == 2 && v7 == foundNode->mFile.mProp.w.mUnk_04) {
                            file = &foundNode->mFile;
                            if (fileLength == file->mProp.w.mUnk_08 - file->mProp.w.mUnk_04) {
                                break;
                            }
                        }
                    }
                    if (foundNode != NULL) {
                        view->mUnk_46cc = view->mUnk_46cc | (1 << fromIndex);
                        view->mUnk_0000[fromIndex].mUnk_04 = foundNode->mBlockId;
                        foundNode->mChildCount = foundNode->mChildCount + 1;
                    } else {
                        for (queuedNode = view->mPendingHead; queuedNode != NULL; queuedNode = queuedNode->mNext) {
                            if (queuedNode->mState == 1 && queuedNode->mFileStart == v7 &&
                                queuedNode->mFileLength == fileLength) {
                                break;
                            }
                        }
                        if (queuedNode == NULL) {
                            queuedNode = view->mFreeHead;
                            func_0204d110(&view->mFreeHead, &view->mPendingHead, queuedNode);
                            queuedNode->mState = 1;
                            view->mUnk_46e4 = view->mUnk_46e4 + 1;
                            queuedNode->mChildCount = 0;
                            queuedNode->mFileStart = v7;
                            queuedNode->mFileLength = fileLength;
                            WakeRomArchiveThread();
                        }
                        queuedNode->mPendingChildMask = queuedNode->mPendingChildMask | (1 << fromIndex);
                    }
                    view->mUnk_46dc = view->mUnk_46dc | (1 << fromIndex);
                    return;
                case 2:
                    savedInterrupts = OS_DisableInterrupts();
                    view->mUnk_46cc = view->mUnk_46cc | (1 << fromIndex);
                    blockId = payload->mUnk_m.mUnk_04;
                    for (activeNode = view->mActiveHead; activeNode != NULL; activeNode = activeNode->mNext) {
                        if (activeNode->mState == 2 && activeNode->mBlockNode.mId == blockId) {
                            break;
                        }
                    }
                    if (activeNode != NULL) {
                        activeNode->mChildCount = activeNode->mChildCount - 1;
                        if (activeNode->mChildCount <= 0) {
                            activeNode->mPendingChildMask = 0;
                            RemoveBlock(payload->mUnk_m.mUnk_04);
                            func_0204d110(&view->mActiveHead, &view->mPendingHead, activeNode);
                            activeNode->mState = 3;
                            WakeRomArchiveThread();
                        }
                    }
                    OS_RestoreInterrupts(savedInterrupts);
                    return;
            }
            return;
        case 13:
            q = &record->mUnk_14;
            v5 = q->mUnk_w;
            q->mUnk_0e.mUnk_08 = 0;
            for (node = data_02179ec0.mUnk_b04; node != NULL; node = node->mNext) {
                if (node->mState == 2 && node->mBlockNode.mId == v5) {
                    break;
                }
            }
            if (node == NULL) {
                return;
            }
            v8 = ((Unk0204c320 *) ((u8 *) q - 0x14))->mUnk_20;
            v9 = node->mUnk_098;
            v10 = q->mUnk_0e.mUnk_04;
            if (node->mUnk_09c != 2) {
                v17 = (node->mFile.mStat & 1) != 0 ? 1 : 0;
                if (v17 == 0) {
                    node->mUnk_09c = 2;
                }
            }
            v11 = v8 * v9;
            node->mUnk_098 = v10;
            v13 = node->mUnk_09c;
            for (v7 = 0; v7 < 2; v7++) {
                if (v7 == v13) {
                    continue;
                }
                v14 = v11 - node->mBufferOffsets[v7];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 > 0x400) {
                    continue;
                }
                q->mUnk_0e.mUnk_04 = v9;
                q->mUnk_0e.mUnk_08 = (node->mBuffers[v7] + v14);
                break;
            }
            if (node->mUnk_09c != 2) {
                return;
            }
            v11 = v8 * v10;
            for (j = 0; j < 2; j++) {
                v14 = v11 - node->mBufferOffsets[j];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 <= 0x400) {
                    break;
                }
            }
            if (j < 2) {
                return;
            }
            k = node->mUnk_0a0;
            do {
                k++;
                if (k >= 2) {
                    k = 0;
                }
            } while (k == v7);
            node->mUnk_0a0 = k;
            node->mUnk_09c = k;
            node->mBufferOffsets[k] = v11 & -0x200;
            FS_SeekFile(&node->mFile, v11 & -0x200, 0);
            FS_ReadFileAsync(&node->mFile, node->mBuffers[k], 0x400);
            break;
    }
}

void RomArchiveChildCallback(Unk0204c320 *record) {
    RomArchiveChildView *childView;
    s32 fromIndex;
    u32 previousMaxSize;
    s32 v2;
    u32 v3;
    void *buffer;
    u32 savedInterrupts;
    RomArchiveMessage message;
    FSFile *file;
    RomArchiveMessage *received;
    FSArchive *archive;
    u32 allocInterrupts;
    void *newBuffer;

    fromIndex = GetLowestSetBitIndex(record->mUnk_0a);
    childView = (RomArchiveChildView *) &data_usa_021762e0;
    switch (record->mUnk_00) {
        case 2:
            if (record->mUnk_08 != 0) {
                return;
            }
            gRomArchiveTransfer.mParentPacketSize = record->mUnk_14.h.mUnk_16 + 0xe;
            gRomArchiveTransfer.mChildPacketSize = record->mUnk_14.h.mUnk_18 + 0xe;
            if (gRomArchiveTransfer.mArchiveBlock == NULL) {
                RequestBlockNode(1, 0, childView, (void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
                return;
            }
            if (gRomArchiveTransfer.mPendingFile == NULL) {
                return;
            }
            previousMaxSize = childView->mMaxReadSize;
            childView->mMaxReadSize = 0;
            if (childView->mMaxReadSize < previousMaxSize) {
                childView->mMaxReadSize = previousMaxSize;
                buffer = childView->mChunkBitmapBuffer;
                if (buffer != NULL) {
                    savedInterrupts = OS_DisableInterrupts();
                    gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, buffer);
                    OS_RestoreInterrupts(savedInterrupts);
                }
                v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                     (gRomArchiveTransfer.mParentPacketSize - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            RequestRomArchiveBytes(gRomArchiveTransfer.mPendingFile);
            return;
        case 6:
            v2 = childView->mNodeBuffers[fromIndex]->mUnk_04;
            gRomArchiveTransfer.mArchiveBlockSize = v2;
            savedInterrupts = OS_DisableInterrupts();
            buffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v2, NULL);
            OS_RestoreInterrupts(savedInterrupts);
            gRomArchiveTransfer.mArchiveBlock = buffer;
            v2 = gRomArchiveTransfer.mArchiveBlockSize;
            if (v2 < 0) {
                v2 = childView->mMaxReadSize;
                childView->mMaxReadSize = 0;
            }
            if (childView->mMaxReadSize < v2) {
                childView->mMaxReadSize = v2;
                buffer = childView->mChunkBitmapBuffer;
                if (buffer != NULL) {
                    savedInterrupts = OS_DisableInterrupts();
                    gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, buffer);
                    OS_RestoreInterrupts(savedInterrupts);
                }
                v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                     (gRomArchiveTransfer.mParentPacketSize - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            childView->mBlockBuffers[fromIndex] = (u32) gRomArchiveTransfer.mArchiveBlock;
            RequestBlockData(1, 0x20000, childView->mBlockBuffers, gRomArchiveTransfer.mArchiveBlockSize,
                             childView->mChunkBitmaps, (void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
            return;
        case 4:
            if (record->mUnk_08 != 0) {
                return;
            }
            if (gRomArchiveTransfer.mState != 2) {
                DC_FlushRange(gRomArchiveTransfer.mArchiveBlock, gRomArchiveTransfer.mArchiveBlockSize);
                childView->mPositionOffset = ReloadRomArchiveFromBlock(gRomArchiveTransfer.mArchiveBlock);
                gRomArchiveTransfer.mState = 2;
                if (gRomArchiveTransfer.mStateCallback == NULL) {
                    return;
                }
                gRomArchiveTransfer.mStateCallback(0);
                return;
            }
            message.mUnk_04 = childView->mFileBlockId;
            message.mKind = 2;
            message.mUnk_00_8 = 1;
            message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
            message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
            if (RequestSendBytes(1, &message, 9, RomArchiveSendCallback) != 0) {
                return;
            }
            OS_Terminate();
            return;
        case 12:
            if (record->mUnk_04 != 0xa) {
                return;
            }
            received = &record->mUnk_14.mUnk_m;
            switch (received->mKind) {
                case 1:
                    if (received->mUnk_00_8 == 0) {
                        RequestBlockCount(1, (void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
                        return;
                    }
                    childView->mFileBlockId = received->mUnk_04;
                    childView->mBlockBuffers[fromIndex] = gRomArchiveTransfer.mPendingFile->mArg.w.mUnk_00;
                    RequestBlockData(1, childView->mFileBlockId, childView->mBlockBuffers,
                                     gRomArchiveTransfer.mPendingFile->mArg.w.mUnk_08, childView->mChunkBitmaps,
                                     (void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
                    return;
                case 3:
                    file = gRomArchiveTransfer.mPendingFile;
                    archive = file->mArc;
                    gRomArchiveTransfer.mPendingFile = NULL;
                    file->mUnk_2c = file->mUnk_2c + file->mArg.w.mUnk_08;
                    FS_NotifyArchiveAsyncEnd(archive, 0);
                    return;
            }
            return;
    }
}

void InitRomArchive(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    RomArchiveTransfer *const transfer = &gRomArchiveTransfer;
    u16 narrowedPort;

    FS_Init(-1);
    narrowedPort = port;
    transfer->mPort = narrowedPort;
    transfer->mUnk_0004 = FALSE;
    transfer->mSendPending = FALSE;
    transfer->mState = 0;
    transfer->mStateCallback = stateCallback;
    transfer->mAllocFunc = allocFunc;
    transfer->mAllocFuncArg = allocFuncArg;
    transfer->mPendingFile = NULL;
    transfer->mArchiveBlockSize = 0;
    transfer->mArchiveBlock = NULL;
    transfer->mParentPacketSize = 0;
    transfer->mChildPacketSize = 0xe;
    data_usa_02175e80 = 0;
    if (WM_SetPortCallback(narrowedPort, RomArchivePortCallback, NULL) != 0) {
        OS_Terminate();
    }
}

void StartRomArchiveParent(u32 port, void (*stateCallback)(s32 port),
                           void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg,
                           u32 parentPacketSize, FSFile *file, s32 appendOverlays) {
    u32 savedInterrupts;
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    RomArchiveFileNode *node;
    RomArchiveFileNode *archiveNode;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        return;
    }
    gRomArchiveStarted = 1;
    InitRomArchive(port, stateCallback, allocFunc, allocFuncArg);
    OS_RestoreInterrupts(savedInterrupts);
    transfer = &gRomArchiveTransfer;
    transfer->mIsParent = 1;
    view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    DC_FlushRange(view, 0x46f0);
    DC_WaitWriteBufferEmpty();
    node = OFFSET_PTR(RomArchiveFileNode, view, 0xc0);
    view->mFreeHead = node;
    if (node + 1 < (RomArchiveFileNode *) &view->mFreeHead) {
        do {
            node->mNext = node + 1;
            FS_InitFile(&node->mFile);
            node->mChildCount = 0;
            node->mState = 0;
            node->mBlockId = (node + 0x10001) - OFFSET_PTR(RomArchiveFileNode, view, 0xc0);
            node++;
        } while (node + 1 < (RomArchiveFileNode *) &view->mFreeHead);
    }
    node->mNext = NULL;
    view->mUnk_46d0 = 0;
    view->mUnk_46cc = 0;
    view->mMessageSendPending = FALSE;
    view->mActiveHead = NULL;
    view->mPendingHead = NULL;
    transfer->mParentPacketSize = parentPacketSize;
    view->mUnk_46d8 = 1;
    view->mUnk_46dc = 0;
    view->mUnk_46e0 = FALSE;
    view->mUnk_46e8 = 0;
    view->mUnk_46e4 = 0;
    view->mUnk_46ec = transfer->mParentPacketSize;
    DC_FlushRange(view, 0x46f0);
    DC_WaitWriteBufferEmpty();
    StartParentBlockTransfer(transfer->mParentPacketSize, transfer->mChildPacketSize,
                             (void (*)(BlockTransferRecord *)) RomArchiveParentCallback);
    CreateRomArchiveBlock(file, appendOverlays);
    archiveNode = view->mFreeHead;
    view->mFreeHead = archiveNode->mNext;
    archiveNode->mNext = view->mActiveHead;
    view->mActiveHead = archiveNode;
    archiveNode->mChildCount = 1;
    MI_CpuFill8(archiveNode, 0, 0x8c0);
    AddBlock(&archiveNode->mBlockNode, 0x20000, data_usa_0215470c, transfer->mArchiveBlock,
             gRomArchiveTransfer.mArchiveBlockSize, 0);
    transfer->mState = 1;
    func_0204bad8();
}

void StartRomArchiveChild(u32 port, void (*stateCallback)(s32 port),
                          void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    u32 savedInterrupts;
    RomArchiveTransfer *transfer;
    RomArchiveChildView *view;
    s32 i;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        return;
    }
    gRomArchiveStarted = 1;
    InitRomArchive(port, stateCallback, allocFunc, allocFuncArg);
    OS_RestoreInterrupts(savedInterrupts);
    transfer = &gRomArchiveTransfer;
    transfer->mIsParent = 0;
    view = OFFSET_PTR(RomArchiveChildView, transfer, 0x440);
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    for (i = 0; i < 16; i++) {
        view->mNodeBuffers[i] = &view->mUnk_0c0[i];
        view->mBlockBuffers[i] = 0;
        view->mChunkBitmaps[i] = NULL;
    }
    view->mChunkBitmapBuffer = NULL;
    view->mMaxReadSize = 0;
    view->mFileBlockId = 0;
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    StartChildBlockTransfer((void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
    transfer->mState = 1;
}

void StartRomArchive(int isParent, u32 port, u32 parentPacketSize, void (*stateCallback)(s32 isParent),
                     void *(*allocFunc)(s32 isParent, u32 port, void *parentPacketSize), u32 allocFuncArg) {
    if (isParent != 0) {
        StartRomArchiveParent(port, stateCallback, allocFunc, allocFuncArg, parentPacketSize, NULL, 1);
        return;
    }
    StartRomArchiveChild(port, stateCallback, allocFunc, allocFuncArg);
}

static inline void func_0204bcec_inline(RomArchiveTransfer *a, void *p) {
    u32 t;
    if (p != NULL) {
        t = OS_DisableInterrupts();
        a->mAllocFunc(a->mAllocFuncArg, 0, p);
        OS_RestoreInterrupts(t);
    }
}

void func_0204be0c(void) {
    Unk021762e0 *childView;
    RomArchiveTransfer *transfer;
    u8 *buffer;
    u16 packetSize;
    u16 builtSize;
    s32 isParent;
    gRomArchiveTransfer.mUnk_0004 = TRUE;
    if (gRomArchiveTransfer.mIsParent == 0) {
        childView = (Unk021762e0 *) &data_usa_021762e0;
        WM_ReadStatus(childView->mUnk_0340);
        SetOwnIndex(childView->mUnk_04c4);
        RequestBlockCount(1, (void (*)(BlockTransferRecord *)) RomArchiveChildCallback);
    } else {
        gRomArchiveTransfer.mState = 2;
        if (gRomArchiveTransfer.mStateCallback != NULL) {
            gRomArchiveTransfer.mStateCallback(0);
        }
    }
    transfer = &gRomArchiveTransfer;
    isParent = transfer->mIsParent;
    if (isParent != 0) {
        packetSize = transfer->mParentPacketSize;
    } else {
        packetSize = transfer->mChildPacketSize;
    }
    if (transfer->mUnk_0004 == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = BuildParentPacket(buffer, packetSize);
    } else {
        builtSize = BuildChildPacket(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->mUnk_0004 = gRomArchiveTransfer.mSendPending == FALSE;
}

void StopRomArchive(void) {
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    u32 savedInterrupts;
    void *block;
    FSArchive *archive;
    transfer = &gRomArchiveTransfer;
    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        block = transfer->mArchiveBlock;
        if (block != NULL) {
            func_0204bcec_inline(&gRomArchiveTransfer, block);
            transfer->mArchiveBlock = NULL;
            transfer->mArchiveBlockSize = 0;
        }
        transfer->mState = 0;
        if (gRomArchiveTransfer.mIsParent == 0) {
            view = &transfer->mUnk_0440;
            if (transfer->mPendingFile != NULL) {
                archive = transfer->mPendingFile->mArc;
                transfer->mPendingFile = NULL;
                FS_NotifyArchiveAsyncEnd(archive, 5);
            }
            func_0204bcec_inline(&gRomArchiveTransfer, view->mUnk_0afc);
        } else {
            func_0204ba8c();
        }
        StopBlockTransfer();
        WM_SetPortCallback(gRomArchiveTransfer.mPort, NULL, NULL);
        gRomArchiveStarted = 0;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 GetRomArchiveState(void) {
    u32 state;
    state = gRomArchiveTransfer.mState;
    return state;
}

u32 func_0204bcb4(u32 value) {
    u32 value0 = value;
    Unk02179ec0 *value1;
    u32 valueWithoutBit0;
    u32 savedValue;
    savedValue = value0;
    value0 = OS_DisableInterrupts();
    value1 = &data_02179ec0;
    valueWithoutBit0 = (savedValue) & ~(1u);
    data_02179ec0.mUnk_b10 = valueWithoutBit0;
    value0 = OS_RestoreInterrupts(value0);
    return value0;
}

void WakeRomArchiveThread(void) {
    u32 threadAddress;
    u32 value12;
    threadAddress = (u32) &data_02175dd8;
    OS_WakeupThreadDirect((OSThread *) threadAddress);
}
