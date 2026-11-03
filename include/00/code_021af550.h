#pragma once

#include "types.h"
#include "code_0200db4c.h"

typedef struct Unk021a998c Unk021a998c;
typedef struct Unk021b6434 Unk021b6434;

// Frame built by func_ov000_021afc5c.
typedef struct Unk021afc5c {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u8 mUnk_20[6];
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
} Unk021afc5c;

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b641a[];
extern Unk0200db5c data_ov000_021b661c;
extern Unk0200db5c data_ov000_021b655c;
extern u16 data_ov000_021b636c;
extern u16 data_ov000_021b6370;
extern u16 data_ov000_021b6374;
extern u16 data_ov000_021b6378;
extern u8 data_ov000_021b6368;
extern u8 data_ov000_021b4c2c[6];
extern u32 data_ov000_021b4c28;
extern Unk021b6434 data_ov000_021b6434[8];

void func_ov000_021af550(u8 *a, u32 b, Unk021a998c *c, u32 d, u16 e);
void func_ov000_021af70c(u8 *a, u32 b, Unk021a998c *c);
void func_ov000_021af7e4(u8 *a, u32 b, Unk021a998c *c);
void func_ov000_021af858(u8 *a, u32 b, u8 *c, u32 d, u32 e, u8 f);
void func_ov000_021af9d0(u8 *a, u32 b, void *c, u32 d, u32 e, u32 f);
void func_ov000_021afaac(u8 *a, u32 b, void *c, u32 d, u32 e, u16 f);
void func_ov000_021afb58(u8 *a, u32 b, u32 c);
u8 *func_ov000_021afc20(u32 a);
void func_ov000_021afc5c(u32 a);
u8 *func_ov000_021afd00(u32 a);
void func_ov000_021afd8c(void);
u8 *func_ov000_021afdcc(u32 *a);
