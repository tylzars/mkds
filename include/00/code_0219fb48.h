#pragma once

#include "types.h"

u32 RestartMatching();
u32 func_ov000_0219fbec(s32 a, s32 b);
u32 func_ov000_0219fdc8(u32 a, s32 b);
u32 ReportMatchingSendResult(u32 result);
void StoreMatchingReceivedList(u32 senderProfileId, u32 *values);
u32 func_ov000_0219ff54(u32 profileId, u32 address, u16 port);
s32 func_ov000_021a0064(s32 profileId, u32 senderMode, s32 c);
