#include "code_021457ec.h"

#include "Main/Unknown/unk_0217f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "os_thread.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_021458b4.h"

u8 gAccessEnabled[0x20];

// Returns the enable flag.
u32 CARD_IsEnabled(void) {
    return *(u32 *) gAccessEnabled;
}

// Ends in OS_Terminate unless card access is enabled.
void CARD_CheckEnabled(void) {
    if (CARD_IsEnabled() != 0) {
        return;
    }
    OS_Terminate();
}

// Sets the enable flag.
void CARD_Enable(u32 enable) {
    *(u32 *) gAccessEnabled = enable;
}

// Waits while a transfer is running. Returns 1 when CARDiCommandArg.mResult is 0.
int CARDi_WaitAsync(void) {
    CARDiCommon *p;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    OS_RestoreInterrupts(enabled);
    return p->mCmd->mResult == 0;
}

// Returns 1 when no transfer is running.
int CARDi_TryWaitAsync(void) {
    return (gAccessState.mFlag & 4) == 0;
}

// Returns CARDiCommandArg.mResult of the last request, 0 when it succeeded.
u32 CARD_GetResultCode(void) {
    return gAccessState.mCmd->mResult;
}
