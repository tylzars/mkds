#include "code_021457ec.h"

#include "Main/Unknown/unk_0217f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200db4c.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_021458b4.h"

u8 gAccessEnabled[0x20];

u32 CARD_IsEnabled(void) {
    u32 value0;
    value0 = (u32) &gAccessEnabled;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void CARD_CheckEnabled(void) {
    u32 value0;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) CARD_IsEnabled();
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
        return;
    }
    OS_Terminate();
}

void CARD_Enable(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &gAccessEnabled;
    *(u32 *) ((value1) + (0)) = value0;
}

// Waits until bit 2 of mUnk_114 is clear; returns 1 when the word at mUnk_00 is 0.
int WaitForTransferEnd(void) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &gAccessState;
    s = OS_DisableInterrupts();
    while (p->mUnk_114 & 4) {
        OS_SleepThread(&p->mUnk_10c);
    }
    OS_RestoreInterrupts(s);
    return p->mUnk_00->mUnk_00 == 0;
}

// Returns 1 when bit 2 of mUnk_114 is clear.
int IsTransferIdle(void) {
    return (gAccessState.mUnk_114 & 4) == 0;
}

u32 CARD_GetResultCode(void) {
    u32 value0;
    value0 = (u32) gAccessState.mUnk_00->mUnk_00;
    return value0;
}
