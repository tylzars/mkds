#pragma once

#include "types.h"

typedef struct Unk021b5df4 Unk021b5df4;

typedef struct Unk021a3a18 {
    /* 000 */ u32 mUnk_00;
    /* 004 */ char mUnk_04[0x80];
    /* 084 */ s8 mUnk_84[0x18];
    /* 09c */ void (*mUnk_9c)(s8 a, u8 *b, u32 c);
    /* 0a0 */ void (*mUnk_a0)(u32 a, u32 b);
    /* 0a4 */ void (*mUnk_a4)(s8 *a, s32 b, u32 c);
    /* 0a8 */ s32 mUnk_a8;
    /* 0ac */ u32 mUnk_ac;
    /* 0b0 */ u32 mUnk_b0;
    /* 0b4 */ u32 mUnk_b4;
    /* 0b8 */ s32 mUnk_b8;
    /* 0bc */ s32 mUnk_bc;
    /* 0c0 */ u32 mUnk_c0;
    /* 0c4 */ u8 pad_c4[4];
    /* 0c8 */ s32 mUnk_c8;
    /* 0cc */ u8 mUnk_cc[8];
    /* 0d4 */ void (*mUnk_d4)(s8 *a, s32 b, void *c);
    /* 0d8 */ s32 mUnk_d8[10];
    /* 100 */ s32 mUnk_100;
    /* 104 */ u32 mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u8 pad_10a[2];
    /* 10c */ u32 mUnk_10c;
} Unk021a3a18;

// A buffer and its length, which follows the 0x800 bytes of the buffer.
typedef struct Unk021a4480 {
    /* 000 */ u8 mUnk_000[0x800];
    /* 800 */ s32 mUnk_800;
} Unk021a4480;

typedef struct Unk021a3a18 Unk021a3a18;

typedef struct Unk021a3a18 Unk021a3a18;

typedef struct Unk021a3eb0 {
    /* 0 */ u8 mUnk_00[6];
} Unk021a3eb0;

typedef struct Unk021a471c Unk021a471c;
typedef struct Unk021a4a08 Unk021a4a08;

typedef struct Unk021a8f84 Unk021a8f84;

// Output buffer the string writers append to: bytes at mUnk_000, used length at mUnk_800.
typedef struct Unk021a471c {
    /* 000 */ u8 mUnk_000[0x800];
    /* 800 */ s32 mUnk_800;
} Unk021a471c;

// Address record filled by func_ov000_021a4654.
typedef struct Unk021a4654 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021a4654;

// Four-byte entry moved by func_ov000_021a46d4.
typedef struct Unk021a46d4 {
    /* 0 */ u8 mUnk_00[4];
} Unk021a46d4;

typedef struct Unk021a4a08 Unk021a4a08;

// List of values and their count; filled by the callback at mUnk_094 of an Unk021a4a08.
typedef struct Unk021a3fc8 {
    /* 000 */ u8 mUnk_000[0x100];
    /* 100 */ s32 mUnk_100;
} Unk021a3fc8;

typedef void (*Unk021a4a08Func88)(u8 a, Unk021a471c *b, void *c);
typedef void (*Unk021a4a08Func8c)(u8 a, s32 b, Unk021a471c *c, void *d);
typedef void (*Unk021a4a08Func94)(s32 a, Unk021a3fc8 *b, void *c);
typedef s32 (*Unk021a4a08Func98)(s32 a, void *b);
typedef void (*Unk021a4a08Func9c)(s32 a, const u8 *b, void *c);
typedef void (*Unk021a4a08Funca8)(u32 a, u16 b, void *c);

// 0x110 bytes; func_ov000_021a4a08 fills it, data_ov000_021b426c points at the one in use.
typedef struct Unk021a4a08 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x40];
    /* 044 */ u8 mUnk_044[0x40];
    /* 084 */ u8 mUnk_084[4];
    /* 088 */ Unk021a4a08Func88 mUnk_088;
    /* 08c */ Unk021a4a08Func8c mUnk_08c;
    /* 090 */ Unk021a4a08Func8c mUnk_090;
    /* 094 */ Unk021a4a08Func94 mUnk_094;
    /* 098 */ Unk021a4a08Func98 mUnk_098;
    /* 09c */ Unk021a4a08Func9c mUnk_09c;
    /* 0a0 */ u32 mUnk_0a0;
    /* 0a4 */ u32 mUnk_0a4;
    /* 0a8 */ Unk021a4a08Funca8 mUnk_0a8;
    /* 0ac */ u32 mUnk_0ac;
    /* 0b0 */ u32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ Unk021a4654 mUnk_0cc;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8[10];
    /* 100 */ s32 mUnk_100;
    /* 104 */ u32 mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10c */ void *mUnk_10c;
} Unk021a4a08;

s32 func_ov000_021a4a08(Unk021a4a08 **a, s32 b, s32 c, const char *d, const char *e, s32 f, s32 g, Unk021a4a08Func88 h,
                        Unk021a4a08Func8c i, Unk021a4a08Func8c j, Unk021a4a08Func94 k, Unk021a4a08Func98 l,
                        Unk021a4a08Func9c m, void *n);

extern Unk021a4a08 data_ov000_021b4278;
extern s32 data_ov000_021b5df8;
extern u8 data_ov000_021b5dfc[5 * 4];
extern char data_ov000_021b5e10[];
extern s8 data_ov000_021b5e50[];

void func_ov000_021a3a18(Unk021a3a18 *a, s32 b);
void func_ov000_021a3bbc(Unk021a3a18 *a);
void func_ov000_021a3c14(Unk021a3a18 *a, s8 *b, s32 c, void *d);
u32 func_ov000_021a3e5c(Unk021a3a18 *a, int b);
void func_ov000_021a3eb0(Unk021a3a18 *a, u8 *b, s32 c);
void func_ov000_021a3f78(Unk021a4a08 *a, Unk021a471c *b);
void func_ov000_021a3fc8(Unk021a4a08 *a, Unk021a471c *b, s32 c);
void func_ov000_021a412c(Unk021a4a08 *a, Unk021a471c *b, const u8 *c, s32 d);
void func_ov000_021a41a0(Unk021a4a08 *a, Unk021a471c *b, s32 c, const u8 *d, s32 e, const u8 *f, s32 g, const u8 *h);
void func_ov000_021a41dc(Unk021a4a08 *a, Unk021a471c *b, s32 c, s32 d, const u8 *e);
void func_ov000_021a438c(Unk021a4a08 *a, const char *b);
void func_ov000_021a4418(Unk021a4a08 *a, Unk021a471c *b, const char *c, s32 d);
void func_ov000_021a4480(unsigned int p0, unsigned int p1, unsigned int p2);
void func_ov000_021a44a0(u8 *a, s32 b, u8 *c, s32 d);
void func_ov000_021a4578(const u8 *a, s32 b, u8 *c);
unsigned char func_ov000_021a4610(u32 a);
void func_ov000_021a4648(u8 *a, u8 *b);
BOOL func_ov000_021a4654(const char *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d);
void func_ov000_021a46d4(void);
void func_ov000_021a471c(Unk021a471c *a, const char *b);
void func_ov000_021a4760(Unk021a471c *a, s32 b);
void func_ov000_021a4784(u32 a, int b);
void func_ov000_021a47ac(Unk021a4a08 *a);
void func_ov000_021a4818(Unk021a4a08 *a);
void func_ov000_021a4868(Unk021a4a08 *a);
void func_ov000_021a4940(Unk021a4a08 *a);
void func_ov000_021a49a0(Unk021a4a08 *a);
void func_ov000_021a49cc(void *a, void (*b)(void *, u16));
void func_ov000_021a49e0(void *a, UnkFunc *b);
void func_ov000_021a49f4(void *a, UnkFunc *b);
// Declared here until the code that defines it is decompiled.
Unk021a8f84 *func_ov000_021a8f84(const char *a);
