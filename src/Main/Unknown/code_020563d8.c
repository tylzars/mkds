#include "Main/Unknown/code_020563d8.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void WriteBackupMissionRecords(void) {
    WriteBackupMissionRecordBlock(data_0217aa08->mMissionRecordBlock);
}

#pragma thumb off
