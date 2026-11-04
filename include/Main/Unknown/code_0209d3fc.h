#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of func_0209d3fc: the MapObject it starts with, a word at 0xac, halfwords at 0xb0 and 0xb2 and a state
// at 0xdc.
typedef struct Unk0209d3fc {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u8 mUnk_a0[0xc];
    /* ac */ u32 mUnk_ac;
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u16 mUnk_b2;
    /* b4 */ u8 mUnk_b4[0x28];
    /* dc */ u32 mUnk_dc;
} Unk0209d3fc;

void func_0209d3fc(void *a, Unk0209d3fc *b);
