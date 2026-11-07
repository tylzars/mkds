#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid);
void DWCi_Acc_CreateTempLoginId(DWCAccFriendData *loginid);
void DWCi_Acc_CreateUserData(DWCAccUserData *userdata, u32 gamecode);
void DWCi_Acc_LoginIdToUserName(const DWCAccFriendData *loginid, u32 gamecode, char *username);
void DWCi_Acc_U64ToString32(u64 num, s32 bitnum, char *result);
u64 DWC_StringToFriendKey(const char *string);
