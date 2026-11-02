#pragma once

#include "types.h"
#include "00/code_0219a61c.h"
#include "00/code_0219a430.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a044.h"
#include "00/code_0219903c.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"
#include "00/code_02197b34.h"
#include "00/code_02197e8c.h"
#include "00/code_021a3690.h"
#include "00/code_02193818.h"
#include "00/code_0218d000.h"

typedef struct Unk02198af4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u32 mUnk_0c;
} Unk02198af4;

// Declared here until the code that defines them is decompiled.
s32 func_ov000_0219a654(const u8 *a, u32 *b, u16 *c);

int func_ov000_021981d0(Unk02197fe8 *a, void *b);
int func_ov000_02198258(Unk02197fe8 *a, void *b, int c, int d);
int func_ov000_021982f4(Unk02197fe8 *a, int b, void *c, int d);
int func_ov000_02198394(Unk02197e8c *a, Unk02197fe8 *b, int c, int d, int e, int f, int g);
int func_ov000_02198448(Unk02197e8c *a);
void func_ov000_021984b4(Unk02197fe8 *a);
void func_ov000_02198514(Unk02197fe8 *a, ...);
void func_ov000_02198548(Unk02197fe8 *a, int b);
