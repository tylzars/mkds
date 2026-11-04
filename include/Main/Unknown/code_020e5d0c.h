#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e5684.h"

// Second argument of func_020e5e24, read at 0x00..0x2b.
typedef struct Unk020e5e24_2 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x08];
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x04];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
} Unk020e5e24_2;

// Object behind Unk020e5e24.mUnk_98: a word at 0x10.
typedef struct Unk020e5e24_98 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ s32 mUnk_10;
} Unk020e5e24_98;

// Object handled by func_020e5e24, func_020e5fb4, func_020e61a8 and
// func_020e630c; at least 0x110 bytes.
typedef struct Unk020e5e24 {
    /* 00 */ u8 mUnk_00[0x04];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ Unk020e43a8_28 mUnk_28;
    /* 4c */ Vec3 mUnk_4c;
    /* 58 */ u8 mUnk_58[0x04];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u8 mUnk_60[0x10];
    /* 70 */ s32 mUnk_70;
    /* 74 */ u8 mUnk_74[0x04];
    /* 78 */ u32 mUnk_78;
    /* 7c */ u8 mUnk_7c[0x1c];
    /* 98 */ Unk020e5e24_98 *mUnk_98;
    /* 9c */ u8 mUnk_9c[0x04];
    /* a0 */ u32 mUnk_a0[4];
    /* b0 */ Vec3 mUnk_b0;
    /* bc */ Vec3 mUnk_bc;
    /* c8 */ Unk020e43a8_28 mUnk_c8;
    /* ec */ Vec3 mUnk_ec;
    /* f8 */ s32 mUnk_f8;
    /* fc */ u16 mUnk_fc;
    /* fe */ u16 mUnk_fe;
    /* 100 */ u16 mUnk_100;
    /* 102 */ u8 mUnk_102[0x02];
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
} Unk020e5e24;

// Allocated by func_020e6488 and func_020ed4d0, filled in by func_020e6514, 0x2c bytes.
typedef struct Unk020e6488 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 *mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
} Unk020e6488;

extern Unk020e6488 data_0217ba00;

extern Unk020e6488 data_0217ba2c;

// Second argument of func_020e6514, allocated as 0x38 bytes by func_020e64b8.
typedef struct Unk020e6514 {
    /* 000 */ u8 mUnk_000[0x0c];
    /* 00c */ u32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0x0a];
    /* 01a */ u16 mUnk_1a;
    /* 01c */ Unk02015b9c_b **mUnk_1c;
    /* 020 */ u8 mUnk_020[0x18];
} Unk020e6514;

// Work area of func_020e6514 on the stack: two words, then the object
// func_02015b9c fills in.
typedef struct Unk020e6514_8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ Unk02015b9c mUnk_08;
} Unk020e6514_8;

void func_020e5d0c(void);
Unk020e59e4 *func_020e5d24(void);
Unk020e5a40 *func_020e5d78(void);
Unk020e5a9c *func_020e5dd4(void);
void func_020e5e24(Unk020e5e24 *p, Unk020e5e24_2 *q);
void CreatePendulumAndPendulumShadow(void);
BOOL func_020e5fb4(Unk020e5e24 *a, Vec3 *b, s32 c, Vec3 *out);
void func_020e61a8(u32 param_1, Unk020e5e24 *a);
void func_020e630c(u32 param_1, Unk020e5e24 *a, u32 param_3, u32 param_4);
Unk020e59e4 *func_020e6380(void);
Unk020e5a40 *func_020e63dc(void);
Unk020e5a9c *func_020e6438(void);
void func_020e6488(Unk020e6488 **param_1, void *param_2, u32 param_3, u32 param_4);
void func_020e64b8(void *p, void *a, void *b, s32 c);
void func_020e6514(Unk020e52bc *param_1, Unk020e6514 *param_2, Unk020e6488 *p);
