#pragma once

#include "types.h"

typedef struct SbServer SbServer;

typedef struct Unk0218b30c {
    /* 0 */ const char *mUnk_00;
} Unk0218b30c;

extern char data_ov000_021b21c8[];
extern char data_ov000_021b21d0[];
extern char data_ov000_021b21d8[];
extern char data_ov000_021b21e4[];

// Declared here until the code that defines it is decompiled.

double SbServerGetDouble(SbServer *e, const char *key, double d);
s32 SbServerGetInt(SbServer *e, const char *key, s32 d);
char *SbServerGetValue(SbServer *server, const char *key, char *d);
void SbServerSetInt(SbServer *e, const char *key, u32 c);
void SbServerSetValue(SbServer *e, const char *key, const char *value);
