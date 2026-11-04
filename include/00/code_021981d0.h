#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

typedef struct Unk02198af4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u32 mUnk_0c;
} Unk02198af4;

BOOL Gt2ParseAddress(const char *a, u32 *b, u16 *c);

BOOL func_ov000_021981d0(Gt2Connection *connection, void *b);
BOOL Gt2CallDataCallback(Gt2Connection *connection, void *b, int c, int d);
BOOL Gt2SetResultAndCallResultCallback(Gt2Connection *connection, int b, void *c, int d);
BOOL CallIncomingConnectionCallback(Gt2Socket *a, Gt2Connection *b, int c, int d, int e, int f, int g);
BOOL func_ov000_02198448(Gt2Socket *socket);
void func_ov000_021984b4(Gt2Connection *a);
void func_ov000_02198514(Gt2Connection *a, ...);
void func_ov000_02198548(Gt2Connection *a, int b);
