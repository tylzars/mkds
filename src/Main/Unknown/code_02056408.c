#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02056430(void) {
    WriteBackupEmblemRecord(data_0217aa08->mEmblemRecord);
}

void func_0205641c(void) {
    WriteBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
}

void func_02056408(void) {
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
}

#pragma thumb off
