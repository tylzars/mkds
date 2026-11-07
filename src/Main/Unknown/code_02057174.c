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

void func_0205721c(u32 a) {
    ClearEmblemRecord();
    ClearGrandPrixRecordBlock();
    ClearCourseTimeRecordBlock();
    ClearMissionRecordBlock();
    func_02057260();
    ClearBuddyRecordBlock();
    func_02057304(a);
}

void func_02057174(void) {
    WriteBackupEmblemRecord(data_0217aa08->mEmblemRecord);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupMissionRecordBlock(data_0217aa08->mMissionRecordBlock);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057ca4(data_0217aa08->mUnk_00);
    if (data_021759d4->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057504();
}

#pragma thumb off
