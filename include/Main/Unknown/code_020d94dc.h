#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_02042044.h"
#include "code_02012b30.h" // Unk02012f58
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f9c6c.h"

struct Unk02012f58;
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e6b58.h"

// Two words of the object allocated by CreateWaterEfct; the function at 0x04, 0x08 and 0x0c holds loaded files.
typedef struct Unk020d98a4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk020d98a4;

// Object behind data_0217b67c.
typedef struct Unk020da384 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mUnk_66;
} Unk020da384;

// Object of 0x6c bytes at 0x68 and 0xd4 of Unk020d9cf4; the word at 0x04 points to a table object.
typedef struct Unk020d9cf4_68 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0201290c *mUnk_04;
    /* 08 */ u8 mUnk_08[0x64];
} Unk020d9cf4_68;

// Object behind gWater and data_0217b4e4, 0x180 bytes.
typedef struct Unk020d9cf4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u16 mUnk_52;
    /* 54 */ s32 mUnk_54;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u16 mUnk_5a;
    /* 5c */ u16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ void *mUnk_60;
    /* 64 */ void *mUnk_64;
    /* 68 */ Unk020d9cf4_68 mUnk_68;
    /* d4 */ Unk020d9cf4_68 mUnk_d4;
    /* 140 */ Unk02012f58 mUnk_140;
    /* 170 */ s32 mUnk_170;
    /* 174 */ void *mUnk_174;
    /* 178 */ void *mUnk_178;
    /* 17c */ void *mUnk_17c;
} Unk020d9cf4;

// Object allocated by func_020d9de0; 0x40 bytes.
typedef struct Unk020d9de0 {
    /* 00 */ s32 mUnk_00[0x10];
} Unk020d9de0;

// Object allocated by func_020da414; 0x40 bytes.
typedef struct Unk020da414 {
    /* 00 */ s32 mUnk_00[0x10];
} Unk020da414;

// Object of at least 0x108 bytes.
typedef struct Unk020da494 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ Unk020d7b88 mUnk_a4;
    /* b4 */ Unk020d7b88 mUnk_b4;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ Unk020e0144 mUnk_cc;
    /* f0 */ u16 mUnk_f0;
    /* f2 */ u8 mUnk_f2[2];
    /* f4 */ s32 mUnk_f4;
    /* f8 */ u16 mUnk_f8;
    /* fa */ u8 mUnk_fa[2];
    /* fc */ s32 mUnk_fc;
    /* 100 */ u16 mUnk_100;
    /* 102 */ s16 mUnk_102;
    /* 104 */ s32 mUnk_104;
} Unk020da494;

void func_020da494(Unk020da494 *a, CourseMapRow *b);
Unk020da414 *func_020da414(void);
void func_020da384(Unk020da384 *a, void *b, UnkFunc *c);
void func_020d9f8c(Unk020d9cf4 *a);
void func_020d9e60(Unk020d9cf4 *a, struct Unk02012f58 *b);
Unk020d9de0 *func_020d9de0(void);
void func_020d9cf4(s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, u16 g, u16 h, u16 i, u16 j, u16 k, u16 l, u16 m, u16 n,
                   s32 o);
void CreateMiniStage3Water(void);
void CreateBeachWater(void);
void CreateTownWater(void);
void CreateYoshiWater(void);
void CreateHyudoroWater(void);
void func_020d9900(Unk020d9cf4 *a);
void CreateWaterEfct(Unk020da384 *a);
void func_020d9810(s32 a, s32 *b, s32 *c, s32 *d, s32 *e);
void func_020d970c(s32 a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h, s32 *i);
void func_020d95c0(const Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e, s32 f);
void func_020d94dc(const Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e, s32 f);
