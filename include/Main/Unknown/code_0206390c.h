#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

typedef struct Unk0206390c_04 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 *mUnk_04;
} Unk0206390c_04;

typedef struct Unk0206390c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0206390c_04 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x18];
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x6a];
    /* 92 */ u8 mUnk_92;
    /* 93 */ u8 mUnk_93[0x1b];
    /* ae */ u8 mUnk_ae;
} Unk0206390c;

extern const u32 data_02154a2c[];

void PlaceKartKillerEffectCallback(Unk0206390c *renderState);
void func_02063a68(Kart *kart);
void func_02063ad0(Kart *kart);
