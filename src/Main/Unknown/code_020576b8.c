#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02057710(Unk0217aa08_24 *a, s32 b) {
    s32 c = b * 0xb00;
    u32 *v;
    v = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(a, v, 0xb00);
        v[0] = 0x45464b4e;
        StartBackupWriteTwoCopies(c + 0x2b00, c + 0x33a00, v, 0xb00, NULL, 0);
    }
}

void func_020576b8(Unk0217aa08_24 *a, s32 b) {
    s32 c = b * 0xb00;
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = a;
        gBackupAccess->mUnk_5c = -1;
        StartBackupReadTwoCopies(c + 0x2b00, c + 0x33a00, gBackupAccess->mBuffer, 0xb00, CopyBackupReadToBlock,
                                 0x45464b4e, 0);
    }
}

#pragma thumb off
