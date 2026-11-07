#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

typedef struct DWCAccUserData DWCAccUserData;

s32 func_021522a0(const u32 *date);
u32 IsMultipleOf4(u32 year);
void DWC_ReportUserData(const DWCAccUserData *userdata);
void DWC_ReportFriendData(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
BOOL DWC_IsEqualFriendData(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2);
void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username);
