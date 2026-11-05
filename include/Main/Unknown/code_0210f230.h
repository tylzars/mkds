#pragma once

#include "types.h"

// Object data_0216cb50: five 16-byte rows of eight halfwords; func_0210f458 reads one halfword of a row and
// func_0210f5d4 walks a row.
typedef struct Unk0216cb50 {
    /* 00 */ u16 mUnk_00[8];
} Unk0216cb50;

// Object data_0217d1c0: a word at 0, a word at 4 and eight bytes at 8; func_0210f230, func_0210f35c, func_0210f458
// and func_0210f5d4 read the word at 0, and func_0210f5d4 writes the two words.
typedef struct Unk0217d1c0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
} Unk0217d1c0;

// Object data_0217d1c4: a word at 0 and twelve bytes at 4; func_0210f458 writes the word at 0 and func_0210f230
// reads it.
typedef struct Unk0217d1c4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
} Unk0217d1c4;

// Object data_0217d1c8: a word at 0 and twelve bytes at 4; func_0210f458 reads the word at 0.
typedef struct Unk0217d1c8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
} Unk0217d1c8;

// Object data_0217d1cc: sixteen bytes; func_0210f230 and func_0210f35c read one byte of the row that the first
// word of the data_0217d1c0 element selects.
typedef struct Unk0217d1cc {
    /* 00 */ u8 mUnk_00[0x10];
} Unk0217d1cc;

extern u32 data_0216cb4c;
extern Unk0216cb50 data_0216cb50[5];

void func_0210f5d4(u32 a);
void func_0210f458(s32 a);
u32 func_0210f35c(s32 a, u32 b);
u32 func_0210f230(u32 a, u32 b);
