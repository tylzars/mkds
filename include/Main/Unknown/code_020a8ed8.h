#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a826c.h" // Unk020a826c_a0

// Object of 0x134 bytes: the shared MapObject part, a Unk020e0144 at 0xc4 and a Unk020e516c at 0xe8.
typedef struct Unk020a9268 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ Unk020e0144 mUnk_0c4;
    /* 0e8 */ Unk020e516c mUnk_0e8;
    /* 11c */ Vec3 mUnk_11c;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
} Unk020a9268;

// Array of object pointers: pointer to the array and the number of entries (func_020a9a5c).
typedef struct Unk020a9a5c {
    /* 00 */ Unk020a9268 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020a9a5c;

// Object returned by func_0209bfa8, with words at 0x38, 0x3c and 0xc0 (func_020a9224, func_020a9de4).
typedef struct Unk020a9224 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ u8 mUnk_40[0x80];
    /* c0 */ s32 mUnk_c0;
} Unk020a9224;

void func_020a9c54(void *a, Unk020a9268 *p, u32 c, u32 d);
void func_020a9a5c(Unk020a9a5c *p);
void func_020a9268(void *a, Unk020a9268 *p);
void func_020a9224(void);
u32 func_020a9204(void);
u32 func_020a91e0(void);
u32 func_020a91c0(void);
void func_020a8ed8(Unk020a826c_a0 *a, Vec3 *b);
