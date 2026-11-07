#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_020579d0(u32 a, const void *b) {
    u32 t;
    void *p;

    t = a * 0xe00;
    p = data_021759d4->mBuffer;
    if (data_021759d4->mBackupEnabled != 0) {
        MI_CpuCopy8(b, p, 0xe00);
        *(u32 *) p = 0x47504b4e;
        func_0204b418(t + 0xaf00, p, 0xe00, 0);
    }
}

void func_0205798c(u8 a, GhostRecord *b) {
    u32 t;
    Unk021759d4 *d;
    void *p;

    t = a * 0xe00;
    d = data_021759d4;
    p = d->mBuffer;
    if (d->mBackupEnabled != 0) {
        d->mReadTarget = b;
        func_0204b6f8(t + 0xaf00, p, 0xe00, CopyBackupReadToBlock, 0x47504b4e);
    }
}

void func_02057944(s32 a, const void *b) {
    u32 t;
    void *p;

    t = a << 12;
    p = data_021759d4->mBuffer;
    if (data_021759d4->mBackupEnabled != 0) {
        MI_CpuCopy8(b, p, 0x1000);
        *(u32 *) p = 0x47444b4e;
        func_0204b418(t + 0x26f00, p, 0x1000, 0);
    }
}

void func_020578fc(u32 a, GhostRecord *b) {
    u32 t;
    Unk021759d4 *d;
    s32 c;

    t = a << 12;
    d = data_021759d4;
    c = d->mBackupEnabled;
    if (c != 0) {
        d->mReadTarget = b;
        data_021759d4->mUnk_6c = a;
        func_0204b6f8(t + 0x26f00, data_021759d4->mBuffer, 0x1000, CopyBackupReadToBlock, 0x47444b4e);
    }
}

#pragma thumb off
