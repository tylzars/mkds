#pragma once

#include "types.h"

typedef struct MatchingServerList MatchingServerList;

// Declared here until the code that defines them is decompiled.

void func_ov000_0219e134(s32 a);
void WiFiMatchingServerListCallback(MatchingServerList *list, s32 event, s32 c);
u32 ReportMatchingConnectResult(u32 result);
s32 func_ov000_0219e45c(s32 a);
s32 func_ov000_0219e4a0(s32 a);
