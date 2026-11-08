#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_021529e0.h"
#include "code_0214d018.h"
#include "code_02152a7c.h"

#pragma thumb on

void InitFriendDataFromGsProfileId(DWCAccFriendData *friendData, u32 gsProfileId) {
    MI_CpuFill8(friendData, 0, 0xc);
    DWCi_Acc_SetGsProfileId(friendData, gsProfileId);
    SetFriendDataType(friendData, 3);
}

#pragma thumb off
