#include "Main/Unknown/code_020563ec.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_020563ec(void) {
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
    func_020574a0();
}

#pragma thumb off
