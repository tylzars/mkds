#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupBuddyRecordBlock(void *block) {
    u32 *buffer;
    buffer = data_021759d4->mBuffer;
    if (data_021759d4->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0xc00);
        *buffer = 0x4c464b4e;
        func_0204b430(0x1f00, 0x32e00, buffer, 0xc00, NULL, 0);
    }
}

void ReadBackupBuddyRecordBlock(void *block) {
    if (data_021759d4->mBackupEnabled != 0) {
        data_021759d4->mReadTarget = block;
        data_021759d4->mUnk_5c = -1;
        func_0204b6cc(0x1f00, 0x32e00, data_021759d4->mBuffer, 0xc00, CopyBackupReadToBlock, 0x4c464b4e, 0);
    }
}

#pragma thumb off
