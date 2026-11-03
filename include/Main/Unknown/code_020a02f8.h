#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020b502c.h" // Unk02175620_84

// Object with the MapObject base at 0x00 (func_020a0318, func_020a066c, func_020a089c).
typedef struct Unk020a0318 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ u16 mUnk_bc;
    /* be */ u16 mUnk_be;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
} Unk020a0318;

// Array of object pointers: pointer to the array and the number of entries (func_020a066c).
typedef struct Unk020a066c {
    /* 00 */ Unk020a0318 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020a066c;

Unk02175620_84 *func_020a0f0c(void);
void func_020a0e00(void);
void func_020a0dbc(void);
void func_020a08ec(void);
void func_020a089c(Unk020a0318 *p);
void func_020a066c(Unk020a066c *p);
void func_020a0318(void *a, Unk020a0318 *p);
u32 func_020a02f8(void);
