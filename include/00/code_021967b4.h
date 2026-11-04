#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

extern char data_ov000_021b3a2c[];
extern char data_ov000_021b3a38[];
extern char data_ov000_021b3ad4[];
extern char data_ov000_021b3ae4[];
extern char data_ov000_021b3aec[];
extern char data_ov000_021b3af4[];
extern char data_ov000_021b3afc[];
extern char data_ov000_021b3b08[];

BOOL GpiGetValue(const char *command, const char *key, char *value, s32 len);
BOOL GpiReadError(GpConnection *a, const char *b, s32 c);
void func_ov000_0219690c(GpConnection *a, const char *b, ...);
