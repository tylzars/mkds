#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void func_02061470(void) {
    u8 i;
    u8 *a;
    GhostRecord *b;

    a = data_0217aa08->mReadDestination;
    for (i = 0; i < 10; i++) {
        b = (GhostRecord *) (a + i * 0x230);
        if (IsSlotGhostBitSet(i) != 0) {
            func_02057800(0, i, b);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
            if (gBackupAccess->mErrorCode != NULL) {
                b->mFilled = 0;
            }
        } else {
            b->mFilled = 0;
        }
    }
    ClearBackupBusy();
    data_0217aa08->mReadDestination = NULL;
}

void func_02061428(void *a) {
    data_0217aa08->mReadDestination = a;
    SetBackupBusy();
    QueueThreadFunction((void (*)(void)) func_02061470);
    gThreadFunctionQueue->mRunRequested = 1;
}
