#pragma once

#include "types.h"

typedef struct Unk02197e8c Unk02197e8c;
typedef struct Unk02197fe8 Unk02197fe8;

typedef struct Unk02198af4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u32 mUnk_0c;
} Unk02198af4;

BOOL func_ov000_0219a654(const u8 *a, u32 *b, u16 *c);

BOOL func_ov000_021981d0(Unk02197fe8 *a, void *b);
BOOL func_ov000_02198258(Unk02197fe8 *a, void *b, int c, int d);
BOOL func_ov000_021982f4(Unk02197fe8 *a, int b, void *c, int d);
BOOL func_ov000_02198394(Unk02197e8c *a, Unk02197fe8 *b, int c, int d, int e, int f, int g);
BOOL func_ov000_02198448(Unk02197e8c *a);
void func_ov000_021984b4(Unk02197fe8 *a);
void func_ov000_02198514(Unk02197fe8 *a, ...);
void func_ov000_02198548(Unk02197fe8 *a, int b);
