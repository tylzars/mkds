#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void StartWriteBackupFirstBlock(void) {
    SetBackupBusy();
    QueueThreadFunction(WriteBackupFirstBlockAndWait);
    gThreadFunctionQueue->mRunRequested = 1;
}

#pragma thumb off
