#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of kind 0xd2 (Dram) and the functions of this file: 0xc0 bytes.
typedef struct Dram {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u16 mUnk_a6;
    /* a8 */ s16 mUnk_a8;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s16 mUnk_b4[3];
    /* ba */ u8 mUnk_ba[2];
    /* bc */ s32 mUnk_bc;
} Dram;

void UpdateDramState4(Dram *p);
void EnterDramState5(Dram *p);
