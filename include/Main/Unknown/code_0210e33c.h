#pragma once

#include "types.h"

// Three words, at 0, 4 and 8: func_0210e33c, func_0210e3ec and func_0210e434 take one by value.
typedef struct Unk0215c380 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk0215c380;

// Object data_0217c7b4, which func_02108950 returns: an Unk0215c380 at 0 and a word at 0xc that
// func_0210e4c8 and func_0210e434 write.
typedef struct Unk0217c7b4 {
    /* 00 */ Unk0215c380 mUnk_00;
    /* 0c */ u32 mUnk_0c;
} Unk0217c7b4;

// Four bytes at 0 to 3: func_0202553c writes one, and func_0210e5e4 and func_0210e888 read the bytes at 1, 2
// and 3.
typedef struct Unk0210e524 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0210e524;

// Object data_0217d134: 16 words from 0x00 and a signed number at 0x40; func_0210e98c walks it and resets it.
typedef struct Unk0217d134 {
    /* 00 */ u32 mUnk_00[16];
    /* 40 */ s32 mUnk_40;
} Unk0217d134;

// Object data_0217d178: 16 words from 0x00 and a signed number at 0x40; func_0210e680 and func_0210ed20 add a
// word to it, func_0210ef68 walks it and func_0210efac resets it.
typedef struct Unk0217d178 {
    /* 00 */ u32 mUnk_00[16];
    /* 40 */ s32 mUnk_40;
} Unk0217d178;

extern Unk0215c380 data_0215c380;
extern Unk0215c380 data_0215c38c;
extern Unk0215c380 data_0215c398;
extern Unk0217c7b4 data_0217c7b4;

void func_0210ef34(void);
u32 func_0210ed20(u32 a, u32 b);
u32 func_0210e98c(Unk0215c380 v, u32 d);
void func_0210e920(void);
void func_0210e8f8(u32 a);
void func_0210e888(Unk0210e524 a, u32 b);
u32 func_0210e680(void);
u32 func_0210e5e4(u32 a, u32 b);
u32 func_0210e524(void);
u32 func_0210e50c(s32 a);
void func_0210e4ec(Unk0217c7b4 *p);
void func_0210e4c8(Unk0217c7b4 *p);
void func_0210e434(Unk0217c7b4 *p);
u32 func_0210e3ec(Unk0217c7b4 *p, Unk0215c380 v);
u32 func_0210e33c(Unk0217c7b4 *p, Unk0215c380 v);
