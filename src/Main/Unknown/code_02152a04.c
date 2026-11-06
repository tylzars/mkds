#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02152490.h"
#include "code_02152ac8.h"

#pragma thumb on

void func_02152a04(DWCAccFriendData *a, u32 b) {
    DWCi_Acc_SetMaskBits(&a->mUnk_00, b, 0xb, 0x1fffff);
}

#pragma thumb off
