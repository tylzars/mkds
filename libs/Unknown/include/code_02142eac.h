#pragma once

#include "types.h"

typedef struct Unk021425e8 Unk021425e8;
typedef void (*Unk021425e8Func)(Unk021425e8 *);

// func_02142c98 sets up the object that data_0217eed4 points to. func_02142c0c stores a word at offset 0x18 + 4 * n;
// func_0214358c stores a function and its argument at mUnk_0c4[n] and mUnk_104[n]. The tables mUnk_018, mUnk_0c4
// and mUnk_104 are indexed by the value in mUnk_00 of the object that func_021425e8 takes.
typedef struct Unk02142aa8 {
    /* 000 */ void *mUnk_000;
    /* 004 */ struct Unk02142988 *mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ u16 *mUnk_00c;
    /* 010 */ Unk021425e8 *mUnk_010;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u16 mUnk_016;
    /* 018 */ Unk021425e8Func mUnk_018[0x2a];
    /* 0c0 */ Unk021425e8Func mUnk_0c0;
    /* 0c4 */ UnkFunc *mUnk_0c4[16];
    /* 104 */ void *mUnk_104[16];
} Unk02142aa8;

// 0x7bc bytes (func_02143520 copies them); the members are the ones the code reads. Pointed to by the word
// func_02142aa8 returns at mUnk_004.
typedef struct Unk02142988 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u8 mUnk_002[2];
    /* 004 */ void *mUnk_004;
    /* 008 */ u8 mUnk_008[4];
    /* 00c */ u32 mUnk_00c;
    /* 010 */ u32 mUnk_010;
    /* 014 */ u8 mUnk_014[0x32];
    /* 046 */ u16 mUnk_046;
    /* 048 */ u8 mUnk_048[8];
    /* 050 */ void *mUnk_050;
    /* 054 */ u8 mUnk_054[0x32];
    /* 086 */ u16 mUnk_086;
    /* 088 */ u8 mUnk_088[0x30];
    /* 0b8 */ u16 mUnk_0b8;
    /* 0ba */ u8 mUnk_0ba[8];
    /* 0c2 */ u16 mUnk_0c2;
    /* 0c4 */ u8 mUnk_0c4[0x30];
    /* 0f4 */ u16 mUnk_0f4;
    /* 0f6 */ u8 mUnk_0f6[0x88];
    /* 17e */ u16 mUnk_17e;
    /* 180 */ u8 mUnk_180[4];
    /* 184 */ u16 mUnk_184;
    /* 186 */ u8 mUnk_186[8];
    /* 18e */ u16 mUnk_18e;
    /* 190 */ u16 mUnk_190;
    /* 192 */ u8 mUnk_192[0x62a];
} Unk02142988;

// Object func_021425e8 takes; the members are the ones the code reads.
struct Unk021425e8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ union {
        struct {
            void *mUnk_08;
            void *mUnk_0c;
        };
        struct {
            u16 mUnk_08_0;
            u16 mUnk_08_2;
        };
        struct {
            u8 mUnk_08_b[2];
            u8 mUnk_0a[6];
        };
    };
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ void *mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u8 mUnk_24[0x12];
    /* 36 */ u16 mUnk_36;
    /* 38 */ struct {
        u32 mUnk_00[0x20];
    } mUnk_38;
};

// 0x84 bytes; mUnk_00 counts the entries of mUnk_04 that func_02142f24 fills.
typedef struct Unk02142f24 {
    /* 00 */ u8 mUnk_00;
    /* 04 */ struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 04 */ const u8 *mUnk_04;
    } mUnk_04[16];
} Unk02142f24;

// Count at mUnk_04 and entry size at mUnk_06; the entries start at mUnk_0a and hold the value func_021432ac compares at
// +4.
typedef struct Unk021432ac {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a[1];
} Unk021432ac;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by func_021437d8.
typedef struct Unk021437d8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u16 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[2];
    /* 26 */ u16 mUnk_26;
} Unk021437d8;

// Taken by func_021438f0.
typedef struct Unk021438f0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[6];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[0x20];
    /* 34 */ u16 mUnk_34;
} Unk021438f0;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by func_021438f0.
typedef struct Unk021438f0_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[6];
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[0x20];
    /* 36 */ u16 mUnk_36;
} Unk021438f0_0c;

// Taken by func_02143a78.
typedef struct Unk02143a78 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[6];
} Unk02143a78;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by func_02143a78.
typedef struct Unk02143a78_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[6];
} Unk02143a78_0c;

// Taken by func_02143c30 and func_02143c80.
typedef struct Unk02143c30 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u8 mUnk_1a[0x18];
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
} Unk02143c30;

u16 func_02142eac(void);
Unk02142f24 func_02142f24(const u16 *a);
u16 func_02143090(void);
u16 func_02143134(void);
u16 func_021431d8(void);
u16 func_02143280(void);
void *func_021432ac(const Unk021432ac *a, u32 b);
s32 func_021433b0(void);
s32 func_0214349c(void);
s32 func_02143520(void *a);
s32 func_0214358c(u32 n, UnkFunc *f, void *p);
s32 func_021435e8(Unk021425e8Func a);
s32 func_02143634(Unk021425e8Func a, u32 b);
s32 func_021436d0(Unk021425e8Func a, u32 b);
s32 func_021437d8(Unk021425e8Func a, u16 *b, void *c, u32 d, u16 e);
s32 func_021438a8(Unk021425e8Func a);
s32 func_021438f0(Unk021425e8Func a, Unk021438f0 *b);
s32 func_02143a78(Unk021425e8Func a, Unk02143a78 *b);
s32 func_02143b7c(Unk021425e8Func a);
s32 func_02143bc4(Unk021425e8Func a);
s32 func_02143bd4(Unk021425e8Func a, u32 b);
u32 func_02143c30(const Unk02143c30 *a);
s32 func_02143c80(Unk021425e8Func a, Unk02143c30 *b);
s32 func_02143d88(Unk021425e8Func a);
s32 func_02143dd0(Unk021425e8Func a);
s32 func_02143e10(void *a, Unk021425e8Func b, u32 c);
s32 func_02143e78(Unk021425e8Func a);
s32 func_02143ec0(Unk021425e8Func a);
s32 func_02143f08(Unk021425e8Func a);
s32 func_02143f50(Unk021425e8Func a);
s32 func_02143fbc(Unk021425e8Func a);
s32 func_02144048(UnkFunc *a, void *b, void *c, s32 d, u16 e, u16 f, u16 g);
s32 func_021441d0(Unk021425e8Func a, u32 b);
s32 func_02144230(Unk021425e8Func a, u32 b, s32 c, u32 d, u16 e, u16 f, u16 g, u32 h, u32 i, u32 j, u32 k);
s32 func_021443b0(Unk021425e8Func a);
s32 func_02144438(Unk021425e8Func a, const void *b, void *c, u32 d);
s32 func_02144514(Unk021425e8Func a, void *b, u32 c);
