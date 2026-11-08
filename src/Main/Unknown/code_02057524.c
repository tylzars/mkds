#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void InitBackupBuffers(void *heap) {
    data_0217aa08 = HeapAlloc(heap, 0x48);
    data_0217aa08->mFirstBlock = HeapAllocAligned(heap, 0x100, 0x20);
    data_0217aa08->mEmblemRecord = HeapAllocAligned(heap, 0x300, 0x20);
    data_0217aa08->mGrandPrixRecordBlock = HeapAllocAligned(heap, 0x400, 0x20);
    data_0217aa08->mCourseTimeRecordBlock = HeapAllocAligned(heap, 0x1600, 0x20);
    data_0217aa08->mMissionRecordBlock = HeapAllocAligned(heap, 0x100, 0x20);
    data_0217aa08->mGhostRecords[0] = HeapAllocAligned(heap, 0xe00, 0x20);
    data_0217aa08->mGhostRecords[1] = HeapAllocAligned(heap, 0x1000, 0x20);
    data_0217aa08->mGhostRecords[2] = HeapAllocAligned(heap, 0x1000, 0x20);
    data_0217aa08->mBuddyRecordBlock = HeapAllocAligned(heap, 0xc00, 0x20);
    data_0217aa08->mEmblemBlockData = HeapAllocAligned(heap, 0xb00, 0x20);
    data_0217aa08->mReadDestination = NULL;
    ResetBackupFirstBlockAndRecords(1);
    data_0217aa08->mFailedBlockBits = 0;
    data_0217aa08->mReadStatus = 0;
    data_0217aa08->mUnk_44 &= ~1;
    data_0217aa08->mBusy = 0;
}

#pragma thumb off
