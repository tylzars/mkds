#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

s32 GpiReadKeyValue(GpConnection *a, s8 *buffer, s32 *c, s8 *key, s8 *value);
u32 GpiCheckConnectComplete(GpConnection *a, u32 b, u32 *c);

typedef struct GpConnection GpConnection;

BOOL GpiGetValue(const char *command, const char *key, char *value, s32 len);
BOOL GpiReadError(GpConnection *a, const char *b, s32 c);

void GpiCopyString(char *dest, const char *src, s32 c);

extern char data_ov000_021b3a0c[];
extern char data_ov000_021b3a2c[];
extern char data_ov000_021b3a38[];
extern char data_ov000_021b3a48[];
extern char data_ov000_021b3ad4[];
extern char data_ov000_021b3ae4[];
extern char data_ov000_021b3aec[];
extern char data_ov000_021b3af4[];
extern char data_ov000_021b3afc[];
extern char data_ov000_021b3b08[];

void func_ov000_0219690c(GpConnection *a, const char *b, ...);
