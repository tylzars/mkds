#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk020136f0, Unk0201290c
#include "code_0212d214.h"

typedef struct Unk02012f58 Unk02012f58;

// Object func_020850c4 prepares; it returns 0 without doing anything when bit 0 of one of the halfwords at 0x10, 0x20
// and 0x32 is set. mUnk_14 is the size func_02084b2c copies.
typedef struct Unk020850c4 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[10];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u8 mUnk_30[2];
    /* 32 */ u16 mUnk_32;
} Unk020850c4;

// 16-byte element of the list at data_0217aeb0 (links at 0x00): mUnk_08 is the argument of func_020136f0 and
// mUnk_0c the object it returns.
typedef struct Unk0208526c {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk020136f0 *mUnk_08;
    /* 0c */ Unk020850c4 *mUnk_0c;
} Unk0208526c;

// Object with an Unk0201290c at 0x04 and an Unk0208526c at 0x5c.
typedef struct Unk02084b2c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0201290c *mUnk_04;
    /* 08 */ u8 mUnk_08[0x4c];
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ Unk0208526c mUnk_5c;
} Unk02084b2c;

void func_020846c0(void *a);
void func_020848fc(void);
void func_02084958(void *a, u32 b);
void func_02084968(void *a, u32 b, u32 c, u32 d);
void func_020849a0(void *a, u32 b);
void func_020849b0(void *a, u32 b);
void func_020849c0(void *a, u32 b);
void func_020849d0(void *a);
void func_020849f8(void *a, Unk02012f58 *b, u32 *c);
void func_02084a88(void *a, u8 b, u8 c);
void func_02084ad8(void *a, u8 b);
Unk0201290c *func_02084b2c(void *a, Unk02084b2c *b, Unk020136f0 *c, Unk020136f0 *d);
Unk0201290c *func_02084c54(Unk02084b2c *a, Unk020136f0 *b);
Unk0201290c *func_02084d3c(Unk02084b2c *a, Unk020136f0 *b, Unk020136f0 *c);
Unk0201290c *func_02084e28(void *a, Unk020136f0 *b);
void func_02084f10(Unk02084b2c *a, Unk0201290c *b);
void func_02084f20(Unk02084b2c *a);
void func_02084f68(Unk02084b2c *a);
void func_02084fb0(Unk02084b2c *a, Unk0201290c *b, u32 c);
u32 func_020850c4(Unk020850c4 *a);
void func_0208526c(Unk0208526c *a, Unk020136f0 *b, Unk020136f0 *c);
