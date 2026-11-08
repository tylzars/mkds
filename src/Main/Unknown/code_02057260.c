#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02057260(void) {
    MI_CpuFill8(((u32 *) (u32) data_0217aa08->mGhostRecords[0]), 0, (0x00000e00u));
    MI_CpuFill8(((u32 *) (u32) data_0217aa08->mGhostRecords[1]), 0, (0x00001000u));
}

#pragma thumb off
