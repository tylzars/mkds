#include "Main/Unknown/code_0204f644.h"
#include "Main/Unknown/code_02036820.h"
#include "code_02003be0.h"
#include "fs_file.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void UncompressPendingFile(void) {
    s16 index = data_0217aa00->mNextLoadIndex - 1;
    u32 uncompressedSize = *data_0217aa00->mBlockEntries[index].mBuffer >> 8;
    void *destination = data_0217aa00->mBlockEntries[index].mUncompressedBuffer;
    if (destination == NULL) {
        destination = HeapAllocAligned(data_0217aa00->mBlockEntries[index].mHeap, uncompressedSize, 0x20);
        *data_0217aa00->mBlockEntries[index].mDataOutput = destination;
    }
    MI_UncompressLZ8(data_0217aa00->mBlockEntries[index].mBuffer, destination);
    data_0217aa00->mBlockEntries[index].mUncompressPending = 0;
}

// Staged: one step per call; returns TRUE when no queued file is left.
BOOL LoadPendingFiles(void) {
    u16 nextIndex = data_0217aa00->mNextLoadIndex;
    s16 previousIndex = nextIndex - 1;
    FSFile *file = &data_0217aa00->mFile;
    void *q;
    s32 size;
    u32 *buffer;
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        return FALSE;
    }
    if (previousIndex >= 0 && data_0217aa00->mBlockEntries[previousIndex].mUncompressPending != 0) {
        if (gThreadFunctionQueue->mRunRequested != 0) {
            return FALSE;
        }
        QueueThreadFunction(UncompressPendingFile);
        gThreadFunctionQueue->mRunRequested = 1;
        return FALSE;
    }
    if (nextIndex >= 12 || data_0217aa00->mBlockEntries[nextIndex].mPath == 0) {
        return TRUE;
    }
    q = &data_0217aa00->mBlockEntries[nextIndex].mPath;
    if (((file->mStat & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    FS_InitFile(file);
    if (FS_OpenFile(file, q) != 0) {
        q = data_0217aa00;
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        buffer = ((ConnectionWork *) q)->mBlockEntries[nextIndex].mBuffer;
        if (buffer == NULL) {
            buffer = HeapAllocAligned(data_0217aa00->mBlockEntries[nextIndex].mHeap, size, 0x20);
            *data_0217aa00->mBlockEntries[nextIndex].mDataOutput = buffer;
        }
        FS_ReadFileAsync(file, buffer, size);
        data_0217aa00->mNextLoadIndex++;
    }
    return FALSE;
}

#pragma thumb off
