#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

extern const u8 data_ov000_021b3fa8[];

u32 func_ov000_021992d4(Gt2Socket *a, u8 *b, s32 c, u32 d, u32 e);
u32 func_ov000_021994c4(Gt2Connection *a, u32 b, u8 *c, s32 d);
u32 func_ov000_02199554(Gt2Connection *a);
u32 func_ov000_0219958c(Gt2Connection *a, u8 *b, s32 c);
