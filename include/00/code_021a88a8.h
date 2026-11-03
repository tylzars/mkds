#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

typedef struct Unk021a8ab8 Unk021a8ab8;

// The 0x64 bytes func_ov000_021a88e4 hands to func_ov000_021ae304: two blocks of a size and a start address.
typedef struct Unk021a88e4 {
    /* 00 */ u8 mUnk_00[0x3c];
    /* 3c */ Unk021a71a4 mReceiveBuffer;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ Unk021a71a4 mSendBuffer;
    /* 50 */ u8 mUnk_50[0x14];
} Unk021a88e4;

s32 func_ov000_021a88a8(u32 a);
s32 func_ov000_021a88e4(const char *a);
s32 func_ov000_021a8960(Unk021a6fa8 *a);
u32 func_ov000_021a8994(Unk021a6fa8 *a);
u32 func_ov000_021a8a54(int a);
BOOL func_ov000_021a8a5c(Unk021a8ab8 *node);
