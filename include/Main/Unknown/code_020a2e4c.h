#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list func_02100138(0x6c), set up by func_020a2fe4: the shared MapObject part, then the value
// passed to func_020a2fe4 at 0xa8, two Vec3s at 0xb0 and 0xbc, words up to 0xe4, a Vec3 at 0xe8 and words up to 0xfc;
// the pointer array at 0xf8 has the count at 0xf4.
typedef struct Unk020a2fe4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ u8 mUnk_ac[4];
    /* b0 */ Vec3 mUnk_b0;
    /* bc */ Vec3 mUnk_bc;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ Vec3 mUnk_e8;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ struct Unk020a2fe4 **mUnk_f8;
    /* fc */ s32 mUnk_fc;
} Unk020a2fe4;

void func_020a2e4c(Unk020a2fe4 *p0, u16 p1, void *p2);
void func_020a2e58(Unk020a2fe4 *p0, u16 p1);
s32 func_020a2e60(Unk020a2fe4 *p0);
void func_020a2e68(Unk020a2fe4 *p0);
