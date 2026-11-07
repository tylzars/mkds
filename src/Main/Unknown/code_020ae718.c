#include "Main/Unknown/code_020ae718.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200f5ac.h"

#pragma thumb on

void func_020ae718(void) {
    u64 tick;
    tick = OS_GetTick();
    *(u64 *) &data_0217b344 = tick;
}

#pragma thumb off
