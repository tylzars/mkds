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

BOOL func_ov000_021967b4(const char *a, const char *b, char *c, s32 d);
BOOL func_ov000_02196870(GpConnection *a, const char *b, s32 c);
void func_ov000_0219690c(GpConnection *a, const char *b, ...);
