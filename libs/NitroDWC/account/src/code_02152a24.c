#include "code_02152a24.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on

u32 DWCi_Acc_GetFlag_DataType(const DWCAccFriendData *frienddata) {
    return GetFriendDataFlags(frienddata) & 3;
}

BOOL DWC_IsBuddyFriendData(const DWCAccFriendData *frienddata) {
    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3) {
        if ((GetFriendDataFlags(frienddata) & 4) == 4) {
            return 1;
        }
        return 0;
    }
    return 0;
}

#pragma thumb off
