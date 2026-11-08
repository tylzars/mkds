#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupBuddyRecordBlock(void *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0xc00);
        *buffer = 0x4c464b4e;
        StartBackupWriteTwoCopies(0x1f00, 0x32e00, buffer, 0xc00, NULL, 0);
    }
}

void ReadBackupBuddyRecordBlock(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        gBackupAccess->mUnk_5c = -1;
        StartBackupReadTwoCopies(0x1f00, 0x32e00, gBackupAccess->mBuffer, 0xc00, CopyBackupReadToBlock, 0x4c464b4e, 0);
    }
}

#pragma thumb off
