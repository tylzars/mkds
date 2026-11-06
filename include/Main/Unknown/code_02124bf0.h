#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk02021dc8, Unk0201ea30
#include "code_02022030.h" // Unk020224e0_o

// 0x20 bytes: four 8-byte entries (the table behind Unk02124c70 is indexed in 8-byte steps by func_02124c70 and in
// 0x20-byte steps for the groups of four it fills).
typedef struct Unk02124c70_00 {
    /* 00 */ Unk020224e0_o mUnk_00[4];
} Unk02124c70_00;

// 0x404 bytes: 0x20 groups of four 8-byte entries, then two halfwords (func_02124c70 adds the return value of
// NNS_G2dMakeCellToOams to mUnk_400; func_020ae5e4 returns mUnk_402).
typedef struct Unk02124c70 {
    /* 000 */ Unk02124c70_00 mUnk_000[0x20];
    /* 400 */ u16 mUnk_400;
    /* 402 */ u16 mUnk_402;
} Unk02124c70;

void func_02124ed0(void *a, Unk0201ea30 *b, Unk0201ea30 *c, Unk02124b1c **d);
u32 func_02124c70(s32 a, Unk02021dc8 *b, Unk0201ea30 *c, Unk0201ea30 *d, Unk02124c70 *e, Unk02124b1c *f, s32 g);
void func_02124c30(Unk0201ea30 *a, Unk02021dc8 *b, Unk0201ea30 *c, void *d, Unk02124b1c *e);
void func_02124bf0(Unk0201ea30 *a, Unk02021dc8 *b, void *c, void *d, void *e);
