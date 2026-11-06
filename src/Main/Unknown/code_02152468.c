#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_021529e0.h"
#include "code_0214d018.h"
#include "code_02152a7c.h"

#pragma thumb on

void func_02152468(DWCAccFriendData *a, u32 b) {
    MI_CpuFill8(a, 0, 0xc);
    DWCi_Acc_SetGsProfileId(a, b);
    func_021529e0(a, 3);
}

#pragma thumb off
