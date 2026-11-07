#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

BOOL DWC_IsBuddyFriendData(const DWCAccFriendData *frienddata);
u32 DWCi_Acc_GetFlag_DataType(const DWCAccFriendData *frienddata);
