#include "Main/Unknown/code_0204b714.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02176000.h"
#include "code_02003be0.h"
#include "os_thread.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_02133458.h"
#include "code_021457ec.h"
#include "01/code_021956dc.h"

void RunFileReadThread(void *a) {
    FSArchive *archive;
    RomArchiveTransfer *g;
    Unk021762e0 *b;
    s32 i;
    RomArchiveFileNode *r;
    u32 waitIrqState;
    u32 updateIrqState;
    s32 offset;
    u8 *chunk;
    archive = FS_FindArchive(gRomArchiveName, 3);
    g = &gRomArchiveTransfer;
    while (1) {
        waitIrqState = OS_DisableInterrupts();
        b = (Unk021762e0 *) &data_usa_021762e0;
        r = b->mUnk_46c8;
        if (r == NULL) {
            do {
                if (g->mState == 0) {
                    OS_RestoreInterrupts(waitIrqState);
                    return;
                }
                OS_SleepThread(NULL);
                r = b->mUnk_46c8;
            } while (r == NULL);
        }
        OS_RestoreInterrupts(waitIrqState);
        if (r->mState == 1) {
            FS_OpenFileDirect(&r->mFile, archive, r->mFileStart, r->mFileStart + r->mFileLength, r->mBlockId);
            i = 0;
            offset = 0;
            chunk = r->mBuffers[0];
            for (; i < 2; i++) {
                r->mBufferOffsets[i] = offset;
                FS_ReadFile(&r->mFile, chunk, 0x400);
                offset += 0x400;
                chunk += 0x400;
            }
            r->mUnk_098 = 0;
            r->mUnk_0a0 = 1;
            r->mUnk_09c = 2;
            updateIrqState = OS_DisableInterrupts();
            func_0204d18c(&data_usa_021762e0, r, 1);
            OS_RestoreInterrupts(updateIrqState);
        } else {
            FS_CloseFile(&r->mFile);
            updateIrqState = OS_DisableInterrupts();
            FreeRomArchiveNode(&data_usa_021762e0, r);
            OS_RestoreInterrupts(updateIrqState);
        }
    }
}

void StartFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    fileReadThread->mUnk_4c4 = 0;
    fileReadThread->mUnk_4c0 = fileReadThread->mUnk_4c4;
    OS_CreateThread(&fileReadThread->mThread, (void (*)(void *)) RunFileReadThread, fileReadThread,
                    (u8 *) &fileReadThread->mThread, 0x400, 15);
    OS_WakeupThreadDirect(&fileReadThread->mThread);
}

void StopFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    if (OS_IsThreadTerminated(&fileReadThread->mThread) != 0) {
        return;
    }
    do {
        OS_WakeupThreadDirect(&fileReadThread->mThread);
        OS_JoinThread(&fileReadThread->mThread);
    } while (OS_IsThreadTerminated(&fileReadThread->mThread) == 0);
}

#pragma thumb on

void func_0204ba7c(void) {
    gBackupAccess->mUnk_00 = 0;
}

void CreateBackupAccess(void *heap) {
    gBackupAccess = HeapAlloc(heap, 0x70);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        gBackupAccess->mBuffer = HeapAllocAligned(heap, 0x2c00, 0x20);
        gBackupAccess->mUnk_64 = HeapAllocAligned(heap, 1, 0x20);
    }
    gBackupAccess->mBackupEnabled = 0;
}

void InitBackupAccess(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || OS_IsRunOnEmulator() != 0) {
        gBackupAccess->mBackupEnabled = 0;
        return;
    }
    gBackupAccess->mBackupEnabled = 1;
    TryLockBackup();
    CARD_IdentifyBackup(0x1202);
    UnlockBackup();
    gBackupAccess->mUnk_00 = 0;
    gBackupAccess->mErrorCode = 0;
    gBackupAccess->mLockId = -3;
    gBackupAccess->mCommandRunning = 0;
    gBackupAccess->mCopyPass = 0;
    gBackupAccess->mReadDestination = NULL;
    gBackupAccess->mReadSize = 0;
    gBackupAccess->mWriteSource = NULL;
    gBackupAccess->mWriteSize = 0;
    gBackupAccess->mUnk_58 = -1;
    gBackupAccess->mUnk_5c = -1;
}

BOOL CheckBackupBlockPrefix(u8 *cursor) {
    BOOL allMatch;
    u8 index;
    allMatch = TRUE;
    index = 0;
    while (allMatch == TRUE && index < 8) {
        if (*cursor != (u8) (func_02133458(0x3031565353444b4dull, index * 8) & 0xff)) {
            allMatch = FALSE;
        }
        index++;
        cursor++;
    }
    return allMatch;
}

void func_0204b7b8(void (*callback)(u32 *, u32)) {
    u32 *p;
    u32 xorByteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    u16 tailHalfword;
    u16 firstPassTailHalfword;
    result = 0;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    UnlockBackup();
    gBackupAccess->mCommandRunning = 0;
    switch (resultCode) {
        case 0:
            DC_StoreRange(gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
            if (gBackupAccess->mReadHasPrefix != 0) {
                p = OFFSET_PTR(u32, gBackupAccess->mReadDestination, 8);
                xorByteCount = gBackupAccess->mReadSize - 8;
                if (CheckBackupBlockPrefix((u8 *) gBackupAccess->mReadDestination) == 0) {
                    result = 4;
                }
            } else {
                p = gBackupAccess->mReadDestination;
                xorByteCount = gBackupAccess->mReadSize;
            }
            if (result == 0) {
                if (TryXorBackupWordsAtFoundIndex(p, xorByteCount, gBackupAccess->mExpectedFirstWord) == 0) {
                    result = 3;
                } else if (ClearTickBytesAndCheckBlockCrc((u8 *) gBackupAccess->mReadDestination,
                                                          gBackupAccess->mReadSize, 0) == 0) {
                    result = 3;
                } else if (gBackupAccess->mExpectedFirstWord != 0 && *p != gBackupAccess->mExpectedFirstWord) {
                    result = 3;
                }
            }
            break;
        case 1:
        case 4:
        case 6:
            result = 2;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        default:
            result = 1;
            break;
    }
    p = gBackupAccess->mReadDestination;
    tailHalfword = *(u16 *) ((u8 *) p + gBackupAccess->mReadSize - 4);
    switch (gBackupAccess->mCopyPass) {
        case 0:
            break;
        case 1:
            if (result != 2) {
                gBackupAccess->mFirstPassResult = result;
                gBackupAccess->mFirstPassBuffer = gBackupAccess->mReadDestination;
                gBackupAccess->mFirstPassTailHalfword = tailHalfword;
                p = OFFSET_PTR(u32, gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
                StartBackupRead(gBackupAccess->mSecondPassAddress, p, gBackupAccess->mReadSize, callback, 2,
                                gBackupAccess->mExpectedFirstWord, gBackupAccess->mReadHasPrefix);
                finished = FALSE;
            } else {
                finished = TRUE;
            }
            break;
        case 2:
            if (result == 0) {
                if (gBackupAccess->mFirstPassResult == 0) {
                    firstPassTailHalfword = gBackupAccess->mFirstPassTailHalfword;
                    if ((firstPassTailHalfword == 0 && tailHalfword == 0xffff) ||
                        firstPassTailHalfword >= tailHalfword) {
                        p = gBackupAccess->mFirstPassBuffer;
                    }
                }
            } else {
                if (gBackupAccess->mFirstPassResult == 0) {
                    result = 0;
                    p = gBackupAccess->mFirstPassBuffer;
                } else if (result == 2 || gBackupAccess->mFirstPassResult == 2) {
                    result = 2;
                } else if (result != 1 && gBackupAccess->mFirstPassResult != 1) {
                    if (result == 4 && gBackupAccess->mFirstPassResult == 4) {
                        result = 4;
                    } else {
                        result = 3;
                    }
                } else {
                    result = 1;
                }
            }
            break;
    }
    if (finished != FALSE) {
        if (result == 0) {
            if (callback != NULL) {
                callback(p, gBackupAccess->mReadSize);
            }
            func_0204ba7c();
            return;
        }
        if (result == 2) {
            gBackupAccess->mBackupEnabled = 0;
        }
        func_0204b344(result);
    }
}

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix) {
    if (gBackupAccess->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (TryLockBackup() == 0) {
        return 0;
    }
    gBackupAccess->mErrorCode = 0;
    gBackupAccess->mCommandRunning = 1;
    gBackupAccess->mUnk_00 = 3;
    gBackupAccess->mReadAddress = address;
    gBackupAccess->mReadDestination = destination;
    gBackupAccess->mReadSize = byteCount;
    gBackupAccess->mExpectedFirstWord = expectedFirstWord;
    gBackupAccess->mReadHasPrefix = hasPrefix;
    gBackupAccess->mCopyPass = copyPass;
    DC_InvalidateRange(destination, byteCount);
    CARDi_RequestStreamCommand(address, (u32) destination, byteCount, (UnkFunc *) func_0204b7b8, callback, 1, 6, 1, 0);
    return 1;
}
