#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

void DWCi_Acc_SetGsProfileId(DWCAccFriendData *data, u32 gsProfileId);
void DWCi_Acc_SetFriendKey(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi);
void DWCi_Acc_SetPlayerId(DWCAccFriendData *loginid, u32 playerid);
void DWCi_Acc_SetUserId(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi);
