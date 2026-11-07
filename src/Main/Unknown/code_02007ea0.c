#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

void SetCallback(UnkFunc *p0) {
    u32 callback = (u32) p0;
    u32 enabled = (OS_DisableInterrupts());
    u32 v3 = ((u32) (&data_0216fdac));
    u32 v4 = (*(u32 *) ((v3) + (0)));
    u32 v5 = 0x14e4u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = callback;
    v7 = (OS_RestoreInterrupts(enabled));
}

#pragma thumb off
