#include "code_02146af4.h"

#include "Main/Unknown/unk_02180000.h"
#include "code_0200fc8c.h"
#include "code_02146a50.h"
#include "code_0214d5b8.h"

UnkWordFunc *gRemovalCallback;
u32 gRemovalSeen;

// Installs CARDi_PulledOutCallback on tag 14 and clears the user callback.
void CARD_InitPulledOutCallback(void) {
    PXI_Init();
    PXI_SetFifoRecvCallback(14, CARDi_PulledOutCallback);
    gRemovalCallback = 0;
}

// Tag 14 callback: on the pulled-out command sets gRemovalSeen, calls the user callback and ends the program when there
// is none or it returns non-zero. Any other command ends in OS_Terminate.
void CARDi_PulledOutCallback(u32 tag, u32 data) {
    u32 terminate;
    UnkWordFunc *callback;

    if ((data & 0x3F) == 0x11) {
        callback = gRemovalCallback;
        gRemovalSeen = 1;
        terminate = 1;
        if (callback != 0) {
            terminate = callback();
        }
        if (terminate != 0) {
            CARD_TerminateForPulledOut();
        }
    } else {
        OS_Terminate();
    }
}

// Sets the user callback.
void CARD_SetPulledOutCallback(void *callback) {
    gRemovalCallback = callback;
}

// Returns 1 once a card removal was reported.
u32 CARD_IsPulledOut(void) {
    return gRemovalSeen;
}
