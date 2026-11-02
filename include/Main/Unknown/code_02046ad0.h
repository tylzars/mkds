#pragma once

#include "types.h"

// Pair of callbacks at an element of the table behind the first word of Unk02046b40.
typedef struct Unk02046b40_00 {
    /* 00 */ void (*mUnk_00)(void *);
    /* 04 */ void (*mUnk_04)(void *);
} Unk02046b40_00;

// Object func_02046b40 and func_02046bcc take (the code reaches it through a void pointer).
typedef struct Unk02046b40 {
    /* 00 */ Unk02046b40_00 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[0x2];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk02046b40;

unsigned int func_02046ad0(unsigned int p0);
unsigned int func_02046ad4(unsigned int p0);
void func_02046ad8(void);
void func_02046ae4(void);
void func_02046b40(void *b);
void func_02046bcc(void *b, u16 c);
