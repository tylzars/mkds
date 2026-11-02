#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58
#include "01/code_02188950.h"
#include "01/code_0218d520.h"

extern Unk02012f58 data_0217c600;

extern Unk02012f58 data_0217ba88;

extern Unk02012f58 data_0217ba58;

extern Unk02012f58 data_0217bab8;

// Object returned by func_020ac524(0xc9).
typedef struct Unk020ac524 {
    /* 00 */ u8 mUnk_00[0xac];
    /* ac */ s32 mUnk_ac;
    /* b0 */ u8 mUnk_b0[0x42];
    /* f2 */ u16 mUnk_f2;
    /* f4 */ u16 mUnk_f4;
} Unk020ac524;

// Element at Unk02187d14::mUnk_00.
typedef struct Unk02187d14_00 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
} Unk02187d14_00;

// Argument of func_ov001_02187d14.
typedef struct Unk02187d14 {
    /* 00 */ Unk02187d14_00 *mUnk_00;
    /* 04 */ Unk0219b250_10 *mUnk_04;
} Unk02187d14;

void func_ov001_02187d14(Unk02187d14 *c);
void *func_ov001_02187dd4(void);
void *func_ov001_02187e00(u16 a);
void func_ov001_02187e48(Unk02188950 *a, s32 b);
