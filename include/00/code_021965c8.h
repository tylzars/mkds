#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

extern char data_ov000_021b3a0c[];
extern char data_ov000_021b3a2c[];
extern char data_ov000_021b3a38[];
extern char data_ov000_021b3a48[];

s32 GpiReadKeyValue(GpConnection *a, s8 *buffer, s32 *c, s8 *key, s8 *value);
u32 GpiCheckConnectComplete(GpConnection *a, u32 b, u32 *c);
