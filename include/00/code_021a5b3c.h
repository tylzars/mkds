#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "code_02142eac.h"
#include "00/code_02188de4.h"
#include "00/code_021a4b98.h"

// Declared here until the code that defines them is decompiled.

// 0xc0 bytes; func_ov000_021a5e84 copies one to mUnk_2140 of an Unk021b5f50, func_ov000_021a671c to a list entry.
typedef struct Unk021a5e84 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 mUnk_04[0x38];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u8 mUnk_3e[0x82];
} Unk021a5e84;

u32 func_ov000_021a5b3c(u32 a);
u32 func_ov000_021a5bfc(void);
s32 func_ov000_021a5c24(void);
s32 func_ov000_021a5db0(void);
s32 func_ov000_021a5e84(Unk021a5e84 *a, Unk02188de4 *b, u32 c);
s32 func_ov000_021a6024(void);
s32 func_ov000_021a60a4(const void *a, const u8 *b, u32 c);
s32 func_ov000_021a61c4(const void *a, const u8 *b, u32 c);
s32 func_ov000_021a61e4(void);
s32 func_ov000_021a629c(Unk021a5a78 *a, void (*b)(Unk021a586c *));
BOOL func_ov000_021a6428(void);
s32 func_ov000_021a6470(Unk021b5f50 *a, u32 b);
void func_ov000_021a6558(Unk021b5f50_2270_0c *a);
Unk021b5f50_2270_0c *func_ov000_021a65d8(u32 a);
Unk021b5f50_2270_0c *func_ov000_021a6614(const u8 *a);
