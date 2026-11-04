#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object behind the words at 0xbc and 0xc0 of Unk0209d694: a flags word at 0x24, a halfword at 0x70 and a byte at 0x80.
typedef struct Unk0209d694_bc {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x48];
    /* 70 */ u16 mUnk_70;
    /* 72 */ u8 mUnk_72[0xe];
    /* 80 */ u8 mUnk_80;
} Unk0209d694_bc;

// Object of func_0209d694: after the shared part, a halfword at 0xa0, a counter at 0xa4, a position at 0xa8, a
// halfword at 0xb4, a state at 0xb8 and two objects at 0xbc and 0xc0.
typedef struct Unk0209d694 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mUnk_a4;
    /* a8 */ Vec3 mUnk_a8;
    /* b4 */ u16 mUnk_b4;
    /* b6 */ u8 mUnk_b6[2];
    /* b8 */ u32 mUnk_b8;
    /* bc */ Unk0209d694_bc *mUnk_bc;
    /* c0 */ Unk0209d694_bc *mUnk_c0;
} Unk0209d694;

void func_0209d694(Vec3 *a, Vec3 *b);
void func_0209d7e0(void);
void func_0209d800(void);
void func_0209d84c(void *a, Unk0209d694 *p);
