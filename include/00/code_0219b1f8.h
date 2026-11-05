#pragma once

#include "types.h"
#include "00/code_0219887c.h" // Unk0219887c
#include "00/code_0219b1d4.h" // Unk0219b1d4

// Message block: word at 0 and string pointer at 8.
typedef struct Unk0219b4b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[4];
    /* 08 */ char *mUnk_08;
} Unk0219b4b4;

Unk0219b1d4 *func_ov000_0219b1f8(u32 a);
void func_ov000_0219b240(u32 *a);
void func_ov000_0219b274(Unk0219887c *a, u32 b);
void func_ov000_0219b27c(Unk0219887c *a, u32 b);
void func_ov000_0219b4a4(Unk0219887c *a, void *b, s32 c, u32 d);
void WiFiGpMessageCallback(u32 a, Unk0219b4b4 *b, u32 g);
