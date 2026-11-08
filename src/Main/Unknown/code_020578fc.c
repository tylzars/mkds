#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupCourseGhost(u32 index, const void *record) {
    u32 offset;
    void *buffer;

    offset = index * 0xe00;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(record, buffer, 0xe00);
        *(u32 *) buffer = 0x47504b4e;
        StartBackupWriteOneCopy(offset + 0xaf00, buffer, 0xe00, 0);
    }
}

void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    void *buffer;

    offset = index * 0xe00;
    backupAccess = gBackupAccess;
    buffer = backupAccess->mBuffer;
    if (backupAccess->mBackupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        StartBackupReadOneCopy(offset + 0xaf00, buffer, 0xe00, CopyBackupReadToBlock, 0x47504b4e);
    }
}

void WriteBackupSlotGhost(s32 index, const void *record) {
    u32 offset;
    void *buffer;

    offset = index << 12;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(record, buffer, 0x1000);
        *(u32 *) buffer = 0x47444b4e;
        StartBackupWriteOneCopy(offset + 0x26f00, buffer, 0x1000, 0);
    }
}

void ReadBackupSlotGhost(u32 index, GhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    s32 backupEnabled;

    offset = index << 12;
    backupAccess = gBackupAccess;
    backupEnabled = backupAccess->mBackupEnabled;
    if (backupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        gBackupAccess->mUnk_6c = index;
        StartBackupReadOneCopy(offset + 0x26f00, gBackupAccess->mBuffer, 0x1000, CopyBackupReadToBlock, 0x47444b4e);
    }
}

#pragma thumb off
