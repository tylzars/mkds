#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode);
BOOL DWC_Acc_CheckFriendKey(u64 friendkey, u32 gamecode);
u64 DWC_Acc_CreateFriendKey(int gsProfileId, u32 gamecode);
void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata);
