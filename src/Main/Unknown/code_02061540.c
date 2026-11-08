#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void func_02061588(void) {
    u8 i;
    u8 *a;
    GhostRecord *b;

    a = data_0217aa08->mReadDestination;
    for (i = 0; i < 0x20; i++) {
        b = (GhostRecord *) (a + i * 0x30);
        if (IsCourseGhostBitSet(i) != 0) {
            func_0205786c(1, i, b);
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
    data_0217aa08->mReadDestination = NULL;
    ClearBackupBusy();
}

void func_02061540(void *a) {
    data_0217aa08->mReadDestination = a;
    SetBackupBusy();
    QueueThreadFunction((void (*)(void)) func_02061588);
    gThreadFunctionQueue->mRunRequested = 1;
}
