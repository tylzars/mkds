#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0

// Object returned by func_0209bfa8: the words at 0x38 and 0x3c are set by func_020a5918.
typedef struct Unk0209bfa8 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bfa8;

#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object reached through func_02100138(0x6a), set up by func_020a5744 and updated by func_020a5958: the shared
// MapObject part, then words up to 0xe8. func_020a5958 switches on the word at 0xe0 (0 to 6).
typedef struct Unk020a5958 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ u8 mUnk_ac[4];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ u16 mUnk_c8;
    /* ca */ u16 mUnk_ca;
    /* cc */ Vec3 mUnk_cc;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ void *mUnk_e4;
    /* e8 */ s32 mUnk_e8;
} Unk020a5958;

#include "Main/Unknown/code_020a3fa8.h" // Unk020a3fa8

u32 func_020a3f2c(void);
u32 func_020a3f48(void);
void func_020a49d4(Unk020a3fa8 *a);
void func_020a4b70(u16 a, Vec3 *b);
void func_020a4c20(void);
void func_020a4c58(u16 a);
BOOL func_020a4d94(u16 a, u16 b);
s32 func_020a4f54(u16 a, u16 b);
BOOL func_020a5268(u16 a, u16 b);
void func_020a5608(Unk0206bcb0 *a, Unk0206bcb0 *b);
void func_020a5744(Vec3 *a, s32 b, s32 c);
void func_020a5848(void);
u32 func_020a58b4(void);
u32 func_020a58d0(void);
u32 func_020a58f4(void);
void func_020a5918(void);
void func_020a5958(void *a, Unk020a5958 *p);
