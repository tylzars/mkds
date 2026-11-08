#include "Main/Unknown/code_02152a1c.h"
#include "code_02152a24.h"

#pragma thumb on
u32 GetFriendDataType(const DWCAccFriendData *friendData) {
    u32 dataType;
    u32 value3;
    value3 = (u32) &DWCi_Acc_GetFlag_DataType;
    dataType = DWCi_Acc_GetFlag_DataType(friendData);
    return dataType;
}
#pragma thumb off
