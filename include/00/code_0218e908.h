#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

u32 GpSendMessage(GpConnection *a, s32 b, const char *c);
u32 GpSetStatus(GpConnection *a, s32 b, const char *c, const char *d);
u32 func_ov000_0218eb44(GpConnection *a, u32 b);
