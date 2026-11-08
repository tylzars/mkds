#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02057c60(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        StartBackupReadTwoCopies(0, 0x30f00, gBackupAccess->mBuffer, 0x100, CopyBackupReadToBlock, 0x59534b4e, 1);
    }
}

void WriteBackupEmblemRecord(EmblemRecord *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x300);
        *buffer = 0x4d454b4e;
        StartBackupWriteTwoCopies(0x100, 0x31000, buffer, 0x300, NULL, 0);
    }
}

void ReadBackupEmblemRecord(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        StartBackupReadTwoCopies(0x100, 0x31000, gBackupAccess->mBuffer, 0x300, CopyBackupReadToBlock, 0x4d454b4e, 0);
    }
}

void WriteBackupGrandPrixRecordBlock(GrandPrixRecordBlock *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x400);
        *buffer = 0x50474b4e;
        StartBackupWriteTwoCopies(0x400, 0x31300, buffer, 0x400, NULL, 0);
    }
}

void ReadBackupGrandPrixRecordBlock(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        StartBackupReadTwoCopies(0x400, 0x31300, gBackupAccess->mBuffer, 0x400, CopyBackupReadToBlock, 0x50474b4e, 0);
    }
}

void WriteBackupCourseTimeRecordBlock(CourseTimeRecordBlock *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x1600);
        *buffer = 0x41544b4e;
        StartBackupWriteTwoCopies(0x800, 0x31700, buffer, 0x1600, NULL, 0);
    }
}

void ReadBackupCourseTimeRecordBlock(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        StartBackupReadTwoCopies(0x800, 0x31700, gBackupAccess->mBuffer, 0x1600, CopyBackupReadToBlock, 0x41544b4e, 0);
    }
}

void WriteBackupMissionRecordBlock(MissionRecordBlock *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x100);
        *buffer = 0x524d4b4e;
        StartBackupWriteTwoCopies(0x1e00, 0x32d00, buffer, 0x100, NULL, 0);
    }
}

void ReadBackupMissionRecordBlock(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        StartBackupReadTwoCopies(0x1e00, 0x32d00, gBackupAccess->mBuffer, 0x100, CopyBackupReadToBlock, 0x524d4b4e, 0);
    }
}

#pragma thumb off
