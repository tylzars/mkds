#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void WriteBackupEmblem(void) {
    WriteBackupEmblemRecord(data_0217aa08->mEmblemRecord);
}

void WriteBackupGrandPrixRecords(void) {
    WriteBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
}

void WriteBackupCourseTimeRecords(void) {
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
}

#pragma thumb off
