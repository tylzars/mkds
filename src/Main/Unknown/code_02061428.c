#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void ReadSlotGhostRecords(void) {
    u8 i;
    u8 *records;
    GhostRecord *record;

    records = data_0217aa08->mReadDestination;
    for (i = 0; i < 10; i++) {
        record = (GhostRecord *) (records + i * 0x230);
        if (IsSlotGhostBitSet(i) != 0) {
            func_02057800(0, i, record);
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
    ClearBackupBusy();
    data_0217aa08->mReadDestination = NULL;
}

void StartReadSlotGhostRecords(void *records) {
    data_0217aa08->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction((void (*)(void)) ReadSlotGhostRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}
