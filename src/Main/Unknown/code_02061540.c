#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void ReadCourseGhostRecords(void) {
    u8 i;
    u8 *records;
    GhostRecord *record;

    records = data_0217aa08->mReadDestination;
    for (i = 0; i < 0x20; i++) {
        record = (GhostRecord *) (records + i * 0x30);
        if (IsCourseGhostBitSet(i) != 0) {
            func_0205786c(1, i, record);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
            if (gBackupAccess->mErrorCode != 0) {
                record->mFilled = 0;
            }
        } else {
            record->mFilled = 0;
        }
    }
    data_0217aa08->mReadDestination = NULL;
    ClearBackupBusy();
}

void StartReadCourseGhostRecords(void *records) {
    data_0217aa08->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction((void (*)(void)) ReadCourseGhostRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}
