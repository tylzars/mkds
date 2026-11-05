#pragma once

#include "types.h"

typedef struct Unk0217aa08_20_04 Unk0217aa08_20_04;

typedef struct Unk02056bc0 Unk02056bc0;

// The word at 0 points to rows of 13 bytes from 6.
typedef struct Unk0205fd2c_00 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06[1][13];
} Unk0205fd2c_00;

typedef struct Unk0205fd2c {
    /* 00 */ Unk0205fd2c_00 *mUnk_00;
} Unk0205fd2c;

extern u32 data_usa_021653e0;
extern u8 data_usa_0215494c[];

u32 func_0205ee14(u32 a, Unk0217aa08_20_04 *b);
void func_0205ee74(u32 a, Unk0217aa08_20_04 *b);
void func_0205eeb0(void);
void func_0205ef70(void);
void func_0205f218(void);
void func_0205f498(void);
void func_0205f700(void);
void func_0205fa00(u32 a, s32 *b, u32 c, u32 d);
s32 func_0205fbb8(s32 a);
s32 func_0205fc28(s32 a);
BOOL func_0205fc98(Unk0205fd2c *a, u32 b, u32 c);
u32 func_0205fd2c(Unk0205fd2c *a, u32 b, u32 c);
s32 func_0205fd78(s32 a, s32 b, s32 *out);
s32 func_0205fdb4(s32 a, void *b);
u32 func_0205fe1c(u8 *a, Unk02056bc0 *b, s32 c);
