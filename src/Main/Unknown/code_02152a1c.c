#include "Main/Unknown/code_02152a1c.h"
#include "code_02152a24.h"

#pragma thumb on
u32 func_02152a1c(const DWCAccFriendData *a) {
    u32 value0;
    u32 value3;
    value3 = (u32) &DWCi_Acc_GetFlag_DataType;
    value0 = (u32) DWCi_Acc_GetFlag_DataType(a);
    return value0;
}
#pragma thumb off
