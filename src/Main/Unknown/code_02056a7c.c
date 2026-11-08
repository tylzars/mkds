#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056aa4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

u32 GetGrandPrixRecord(int cup, int engineClass, TimeRecord *record) {
    UnpackGrandPrixRecord(&data_0217aa08->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
    return 1;
}

#pragma thumb off
