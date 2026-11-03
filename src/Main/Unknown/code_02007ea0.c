#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

void func_02007ea0(UnkFunc *p0) {
    u32 v1 = (u32) p0;
    u32 v2 = ((u32) func_0200fca0());
    u32 v3 = ((u32) (&data_0216fdac));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v5 = 0x14e4u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = ((u32) func_0200fcb4(v2));
}

#pragma thumb off
