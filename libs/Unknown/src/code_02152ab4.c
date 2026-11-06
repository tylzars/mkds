#include "code_02152ab4.h"
#include "code_02152490.h"

#pragma thumb on

u64 DWCi_Acc_GetFriendKey(const DWCAccFriendData *data) {
    return (u64) data->mUnk_08 << 32 | data->mUnk_04;
}

#pragma thumb off
