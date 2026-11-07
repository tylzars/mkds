#include "code_02146a50.h"
#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200007e.h"

// Powers the console off when the lid-closed bit is set, otherwise sends the terminate word on tag 14, then ends in
// OS_Terminate.
void CARD_TerminateForPulledOut(void) {
    if (((s32) (*(vu16 *) 0x027FFFA8 & 0x8000)) >> 15 != 0) {
        PM_ForceToPowerOff();
    }
    CARDi_SendtoPxi(1, 1);
    OS_Terminate();
}

// Sends the word on tag 14, waiting and trying again until it is accepted.
void CARDi_SendtoPxi(u32 data, s32 wait) {
    while (PXI_SendWordByFifo(14, data, 0) != 0) {
        WaitByLoop(wait);
    }
}
