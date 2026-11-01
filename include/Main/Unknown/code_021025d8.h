#pragma once

#include "types.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_0216c000.h"

typedef struct Unk021025d8 {
    /* 00 */ u8 mUnk_00[0x12c];
    /* 12c */ u8 mUnk_12c[0x14];
    /* 140 */ u32 mUnk_140;
    /* 144 */ u32 mUnk_144;
    /* 148 */ u8 mUnk_148[0xc];
    /* 154 */ u32 mUnk_154;
    /* 158 */ u32 mUnk_158;
    /* 15c */ u32 mUnk_15c;
    /* 160 */ u32 mUnk_160;
    /* 164 */ u8 mUnk_164[0xe8];
    /* 24c */ u32 mUnk_24c;
    /* 250 */ u32 mUnk_250;
    /* 254 */ u32 mUnk_254;
    /* 258 */ u32 mUnk_258;
    /* 25c */ u32 mUnk_25c;
    /* 260 */ u32 mUnk_260;
    /* 264 */ u32 mUnk_264;
    /* 268 */ u32 mUnk_268;
    /* 26c */ u32 mUnk_26c;
    /* 270 */ u32 mUnk_270;
} Unk021025d8;

void func_021025d8(Unk021025d8 *param_1);
typedef struct Unk02102668 {
    /* 00 */ u8 mUnk_00[0x170];
    /* 170 */ u32 mUnk_170;
} Unk02102668;

void func_02102668(Unk02102668 *p0);
