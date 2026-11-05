#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;
typedef struct Gt2Socket Gt2Socket;

typedef struct Unk0219887c {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 *mUnk_40;
} Unk0219887c;

u8 *func_ov000_0219887c(Unk0219887c *object);
void func_ov000_021988a4(Unk0219887c *connection, void *b);
void SetUnmatchedDataCallback(Gt2Socket *a, UnkWordFunc *b);
u32 GetSocketDescriptor(u32 *a);
int func_ov000_021988dc(Gt2Connection *a);
u16 GetSocketPort(Gt2Socket *a);
