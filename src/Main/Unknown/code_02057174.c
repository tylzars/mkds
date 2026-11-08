#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void ResetBackupFirstBlockAndRecords(u32 copyOwnerName) {
    ClearEmblemRecord();
    ClearGrandPrixRecordBlock();
    ClearCourseTimeRecordBlock();
    ClearMissionRecordBlock();
    func_02057260();
    ClearBuddyRecordBlock();
    ResetBackupFirstBlock(copyOwnerName);
}

void WriteBackupFirstBlockAndRecords(void) {
    WriteBackupEmblemRecord(data_0217aa08->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupMissionRecordBlock(data_0217aa08->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupFirstBlock(data_0217aa08->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    ClearBackupBusy();
}

#pragma thumb off
