#include "code_02146af4.h"

#include "Main/Unknown/unk_02180000.h"
#include "code_0200fc8c.h"
#include "code_02146a50.h"
#include "code_0214d5b8.h"

UnkWordFunc *gRemovalCallback;
u32 gRemovalSeen;

void CARD_InitPulledOutCallback(void) {
    PxiInit();
    PxiCallbackSet(14, ReceiveRemovalMessage);
    gRemovalCallback = 0;
}

void ReceiveRemovalMessage(u32 a, u32 b) {
    u32 r;
    UnkWordFunc *fn;

    if ((b & 0x3F) == 0x11) {
        fn = gRemovalCallback;
        gRemovalSeen = 1;
        r = 1;
        if (fn != 0) {
            r = fn();
        }
        if (r != 0) {
            CARD_TerminateForPulledOut();
        }
    } else {
        IrqDisableLoopForever();
    }
}

void CARD_SetPulledOutCallback(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gRemovalCallback;
    *(u32 *) ((value1) + (0)) = value0;
}

u32 CARD_IsPulledOut(void) {
    u32 value0;
    value0 = (u32) &gRemovalSeen;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}
