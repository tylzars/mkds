#include "Main/Unknown/code_021526c8.h"
#include "code_02152a24.h"

#pragma thumb on

u32 IsFriendDataLoginId(const DWCAccFriendData *friendData) {
    int dataType;
    dataType = DWCi_Acc_GetFlag_DataType(friendData);
    if (dataType == 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
