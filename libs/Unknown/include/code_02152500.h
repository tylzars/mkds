#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

u64 DWC_CreateFriendKey(const DWCAccUserData *userdata);
int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
u64 DWC_GetFriendKey(const DWCAccFriendData *frienddata);
void DWCi_Acc_ClearDirty(DWCAccUserData *userdata);
BOOL DWCi_Acc_IsDirty(const DWCAccUserData *userdata);
void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId);
BOOL DWC_CheckValidConsole(const DWCAccUserData *userdata);
void DWC_CreateUserData(DWCAccUserData *userdata, u32 gamecode);
