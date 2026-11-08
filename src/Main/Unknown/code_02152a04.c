#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02152490.h"
#include "code_02152ac8.h"

#pragma thumb on

void SetFriendDataFlags(DWCAccFriendData *friendData, u32 flags) {
    DWCi_Acc_SetMaskBits(&friendData->mUnk_00, flags, 0xb, 0x1fffff);
}

#pragma thumb off
