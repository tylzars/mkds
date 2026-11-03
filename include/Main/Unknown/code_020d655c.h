#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ea670.h"

// Second half of the 0x5c-byte object behind data_0217b650: the words from 0x2c, then three more.
typedef struct Unk0217b650_2c {
    /* 00 */ s32 mUnk_00[9];
    /* 24 */ Vec3 mUnk_24;
} Unk0217b650_2c;

// 0x5c-byte object that func_020d67f0 and func_020d6850 allocate and fill from a table; func_020d49d8 stores
// the address of its pointer at 0x28.
typedef struct Unk0217b650 {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ struct Unk0217b650 **mUnk_28;
    /* 2c */ Unk0217b650_2c mUnk_2c;
} Unk0217b650;

// 0x28-byte object that func_020d6794 allocates and fills from a table; func_020e6f50 stores the address of its
// pointer at 0x24.
typedef struct Unk0217b654 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ struct Unk0217b654 **mUnk_24;
} Unk0217b654;

// Object of func_020d655c: the shared part, and a word at 0x118.
typedef struct Unk020d655c {
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ u8 mUnk_a0[0x78];
    /* 118 */ s32 mUnk_118;
} Unk020d655c;

// 0x40-byte object that func_020d68b0 allocates and fills from a table.
typedef struct Unk02156adc {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk02156adc;

void func_020d655c(void *a, Unk020d655c *b, void *c, s32 d);
void func_020d673c(void);
Unk0217b654 *func_020d6794(void);
Unk0217b650 *func_020d67f0(void);
Unk0217b650 *func_020d6850(void);
Unk02156adc *func_020d68b0(void);
s32 func_020d6910(s32 a, void *b);
s32 func_020d6968(s32 a, MapObject *b);
s32 func_020d69e4(s32 a, MapObject *b);
s32 func_020d6a54(Unk020f41c4_A *a, MapObject *b, s32 *c);
s32 func_020d6be0(Unk0206bcb0 *a, MapObject *b);
u32 func_020d6d34(s32 a, s32 b, s32 c, s32 d, s32 e);
