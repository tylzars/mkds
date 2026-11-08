#include "Main/Unknown/code_02057800.h"
#include "Main/Unknown/code_020578d0.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0205786c(u32 isCourseGhost, u32 index, GhostRecord *ghostRecord) {
    BackupAccess *backupAccess;
    u32 sectionOffset;
    u32 recordOffset;
    u32 recordSize;
    u32 magic;
    void *buffer;

    backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        if (isCourseGhost != 0) {
            sectionOffset = 0;
            recordSize = 0xe00;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47504b4e;
        } else {
            sectionOffset = 0x1c000;
            recordSize = 0x1000;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47444b4e;
        }
        backupAccess->mReadTarget = ghostRecord;
        StartBackupReadOneCopy(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize, func_020578e8, magic);
    }
}

void func_02057800(u32 isCourseGhost, u32 index, GhostRecord *ghostRecord) {
    void (*readCallback)(u32, u32);
    BackupAccess *backupAccess;
    u32 sectionOffset;
    u32 recordOffset;
    u32 recordSize;
    u32 magic;
    void *buffer;

    backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        if (isCourseGhost != 0) {
            sectionOffset = 0;
            recordSize = 0xe00;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47504b4e;
            readCallback = func_020578e8;
        } else {
            sectionOffset = 0x1c000;
            recordSize = 0x1000;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47444b4e;
            readCallback = func_020578d0;
        }
        backupAccess->mReadTarget = ghostRecord;
        StartBackupReadOneCopy(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize, readCallback, magic);
    }
}

#pragma thumb off
