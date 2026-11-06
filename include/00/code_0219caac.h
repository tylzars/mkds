#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "03/code_021b94b8.h"

void InitWiFiLogin(WiFiLogin *a, DWCAccUserData *b, GpConnection *c, u32 d, u32 e, void (*f)(), void *g);
u32 GetPendingStatsRequestCount(void);
