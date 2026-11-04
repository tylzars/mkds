#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;
typedef struct GpiBuffer GpiBuffer;

u32 func_ov000_02190548(GpConnection *a, GpiProfile *b);
u32 func_ov000_021905d4(GpConnection *a, GpiBuffer *b);
u32 func_ov000_02190618(GpConnection *a, GpiBuffer *b, s32 *c, s32 *d, s32 *e);
