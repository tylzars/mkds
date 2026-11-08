#include "Main/Unknown/code_021526a0.h"
#include "code_02152a24.h"

#pragma thumb on

u32 IsFriendDataTypeNonZero(const void *friendData) {
    int dataType;
    dataType = DWCi_Acc_GetFlag_DataType(friendData);
    if (dataType != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
