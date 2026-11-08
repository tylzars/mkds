#pragma once

#include "types.h"

void func_0211fef4(u32 fromIndex, void *message, u32 size);
void func_0211fe44(void);
void RequestWiFiSessionLogin(void);
void func_0211fe18(void);
u32 func_0211fda8(void);
s32 GetWiFiSessionLoginResult(void);
void func_0211fd28(void);
void SetupWiFiSessionLogin(void);
void func_0211fa70(void);
u32 UpdateWiFiSessionLogin(void);
void WiFiSessionLoginCallback(s32 result);
void WiFiSessionBuddySyncCallback(s32 result, s32 changed);
void func_0211f6e8(u32 a, u32 b);
void SetBuddyStatus(u32 index, u8 status);
