#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of 0xd8 bytes: the MapObject it starts with, a vector at 0xa0 and words and halfwords up to 0xd4.
typedef struct Unk0209219c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ Vec3 mUnk_a0;
    /* ac */ u16 mUnk_ac;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ u16 mUnk_c0;
    /* c2 */ u8 mUnk_c2[2];
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[3];
    /* d4 */ s32 mUnk_d4;
} Unk0209219c;

typedef struct Unk0209219c Unk0209219c;

// Object func_0209297c reads: a halfword at 0x74 and a vector at 0x80.
typedef struct Unk0209297c {
    /* 00 */ u8 mUnk_00[0x74];
    /* 74 */ u16 mUnk_74;
    /* 76 */ u8 mUnk_76[10];
    /* 80 */ Vec3 mUnk_80;
} Unk0209297c;

void CreateBasabasa(void *a);

void func_0209219c(u32 a, const Vec3 *b, const Vec3 *c, u32 d, s32 e, u16 f);
void func_02092468(void);
void func_02092484(void);
void func_020924a8(void);
void func_020924d8(void *a, Unk0209219c *b);
void func_0209280c(void *a, Unk0209219c *b);
void func_02092928(void *a);
u8 func_0209297c(Unk0209219c *a, Unk0209297c *b, void *c, u8 *d);
void func_02092b20(MapObject *arg0);
