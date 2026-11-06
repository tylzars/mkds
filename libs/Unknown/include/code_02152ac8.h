#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

u64 DWCi_Acc_GetUserId(const DWCAccFriendData *userdata);
BOOL DWCi_Acc_SetMaskBits(u32 *ptr, u32 data, u32 shift, u32 mask);
u32 DWC_Init(u8 *work);
