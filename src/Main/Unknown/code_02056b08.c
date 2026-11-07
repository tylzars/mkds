#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void SetGrandPrixRecord(int cup, int engineClass, TimeRecord *record) {
    func_02056b30(&data_0217aa08->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
}

#pragma thumb off
