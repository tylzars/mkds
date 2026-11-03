#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

extern u8 data_ov000_021b3a0c[];
extern u8 data_ov000_021b3a2c[];
extern u8 data_ov000_021b3a38[];
extern u8 data_ov000_021b3a48[];

s32 func_ov000_021965c8(GpConnection *a, s8 *b, s32 *c, s8 *d, s8 *e);
u32 func_ov000_02196714(GpConnection *a, u32 b, u32 *c);
