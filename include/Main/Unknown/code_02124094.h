#pragma once

#include "types.h"
#include "code_02021db0.h" // Unk02021dc8
#include "code_0201ea58.h" // Unk0201ea30

// 8-byte elements from offset 8 of an Unk0201ea30 (func_0201ea30 indexes them).
typedef struct Unk0201ea30_08 {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            Unk0201ea84 mUnk_00_0;
            Unk0201ea84 mUnk_00_2;
        };
    };
    /* 04 */ u32 mUnk_04;
} Unk0201ea30_08;

// 6-byte element of the array behind Unk02124a68.
typedef struct Unk02124a68_04 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk02124a68_04;

// What func_02021f1c returns for the functions here, and what mUnk_44 of Unk021243ac points to:
// mUnk_00 elements at mUnk_04.
typedef struct Unk02124a68 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk02124a68_04 *mUnk_04;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
} Unk02124a68;

// 0x24 bytes at member 0x20 of Unk021243ac (func_02125808 takes its address).
typedef struct Unk021243ac_20 {
    /* 00 */ struct Unk021243ac *mUnk_00;
    /* 04 */ struct Unk02022aa8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk021243ac_20;

// Object of 0x48 bytes allocated by func_021243ac.
typedef struct Unk021243ac {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct Unk021243ac *a, s32 b);
    /* 1c */ u8 mUnk_1c[0x4];
    /* 20 */ Unk021243ac_20 mUnk_20;
    /* 44 */ Unk02124a68 *mUnk_44;
} Unk021243ac;

// 0x40-byte element of the tables func_02124ed0 allocates and func_02124efc sets up: behind WiFiVSMatching::mUnk_10d4,
// members 0x14, 0x24 and 0x3c of Unk0217d350, and the tables of the objects behind gRecordVS to data_0217d380
// and of several overlay globals.
typedef struct Unk02124b1c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ BOOL mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14[4];
    /* 24 */ s32 mUnk_24[4];
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ Unk021243ac *mUnk_3c;
} Unk02124b1c;

// 8-byte elements func_021243ac fills and copies into Unk02124a68_04 elements.
typedef struct Unk02022eb0 {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u16 mUnk_00_0;
            u16 mUnk_00_2;
        };
    };
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022eb0;

// 12-byte elements of the array func_0201ea58 indexes.
typedef struct Unk0212428c {
    /* 00 */ Unk0201ea84 mUnk_00;
    /* 02 */ Unk0201ea84 mUnk_02;
    /* 04 */ s8 mUnk_04;
    /* 05 */ s8 mUnk_05;
    /* 06 */ u16 mUnk_06_0 : 8;
    /* 06 */ u16 mUnk_06_8 : 4;
    /* 06 */ u16 mUnk_06_12 : 4;
    /* 08 */ u8 mUnk_08[4];
} Unk0212428c;

// Object whose mUnk_14 is the base address func_0212463c, func_02124748 and func_0212481c add offsets to.
typedef struct Unk0212463c_c {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u8 *mUnk_14;
} Unk0212463c_c;

// Object whose mUnk_0c is the base address func_0212463c and func_0212481c add an offset to.
typedef struct Unk0212463c_d {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk0212463c_d;

BOOL func_02124ae4(s32 a, Unk02021dc8 *b, Unk0201ea30 *c);
void func_02124b1c(Unk02124b1c *a, s32 b, s32 c);
void func_02124a98(u32 a, s32 b, Unk02021dc8 *c, Unk0201ea30 *d);
u8 func_02124a68(u32 a, Unk02021dc8 *b, Unk0201ea30 *c);
void func_02124a20(s32 a, s32 b, Unk02021dc8 *c, Unk0201ea30 *d);
u8 func_021249f0(s32 a, Unk02021dc8 *b, Unk0201ea30 *c);
void func_021249a8(u32 a, u32 b, Unk02021dc8 *c, Unk0201ea30 *d);
u16 func_0212497c(u32 a, Unk02021dc8 *b, Unk0201ea30 *c);
void func_0212481c(u32 a, Unk02021dc8 *b, Unk0212463c_c *c, Unk0212463c_d *d, Unk0201ea30 *e, s32 f, u32 g,
                   Unk02021dc8 *h, Unk0201ea30 *i);
void func_02124748(u32 a, Unk02021dc8 *b, void *c, Unk0201ea30 *d, s32 e, u32 f, Unk02021dc8 *g, Unk0201ea30 *h);
void func_0212463c(u32 a, Unk02021dc8 *b, Unk0212463c_c *c, Unk0212463c_d *d, Unk0201ea30 *e, s32 f, u32 g,
                   Unk02021dc8 *h, Unk0201ea30 *i);
s32 func_021243ac(void *a, s32 b, Unk0201ea30 *c, s32 d, s32 e, s32 f, Unk02021dc8 *g, Unk0201ea30 *h, Unk02124b1c *i,
                  s32 j);
void func_0212428c(s32 a, s32 b, Unk0201ea30 *c, void *d, Unk0201ea30 *e, Unk02124b1c *f, s32 g, s8 h);
void func_0212426c(s32 a, s32 b, Unk0201ea30 *c, void *d, Unk0201ea30 *e, Unk02124b1c *f);
void func_02124248(s32 a, s32 b, void *c, void *d, Unk0201ea30 *e, Unk02124b1c *f, s8 g);
void func_02124224(s32 a, u32 b, Unk0201ea30 *c, void *d, Unk0201ea30 *e, Unk02124b1c *f, s8 g);
void func_021241c0(s32 a, s32 b, Unk0201ea30 *c, Unk0201ea30 *d, Unk02124b1c *e);
BOOL func_0212418c(s32 a, void *b, Unk02124b1c *c, Unk0201ea30 *d);
void func_02124140(u32 a, u32 b, void *c, Unk02124b1c *d, Unk0201ea30 *e);
void func_02124100(s32 a, u8 b, Unk0201ea30 *c, Unk02124b1c *d, Unk0201ea30 *e);
u8 func_021240d4(s32 a, void *b, Unk02124b1c *c, Unk0201ea30 *d);
void func_02124094(u32 a, u32 b, Unk0201ea30 *c, Unk02124b1c *d, Unk0201ea30 *e);
