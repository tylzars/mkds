#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0204b418.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupFirstBlock(void *block) {
    u32 *buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        enum { K0 = 0x53444b4d } firstWord;
        enum { K1 = 0x30315653 } secondWord;
        MI_CpuCopy8(block, buffer, 0x100);
        firstWord = K0;
        secondWord = K1;
        buffer[0] = firstWord;
        buffer[1] = secondWord;
        buffer[2] = 0x59534b4e;
        StartBackupWriteTwoCopies(0, 0x30f00, buffer, 0x100, NULL, 1);
    }
}

#pragma thumb off
