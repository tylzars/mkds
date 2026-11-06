#include "Main/Unknown/code_021526c8.h"
#include "code_02152a24.h"

#pragma thumb on

u32 func_021526c8(const DWCAccFriendData *a) {
    int v1;
    v1 = DWCi_Acc_GetFlag_DataType(a);
    if (v1 == 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
