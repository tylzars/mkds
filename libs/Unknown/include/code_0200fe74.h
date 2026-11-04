#pragma once

#include "types.h"

u32 CountLeadingZeros(u32 a);

// Filled by func_0201000c.
typedef struct Unk0201000c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0201000c;

// Top-level block: a count at 0x09 and, at 0x0e, the offset from 0x08 of a table of offsets to Unk020101e8.
typedef struct Unk02010168 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u8 mUnk_08[1];
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[4];
    /* 0e */ u16 mUnk_0e;
} Unk02010168;

// Object with, at 0x08, the offset from this object of an Unk020101e8_08.
typedef struct Unk020101e8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
} Unk020101e8;

// Offsets (from this block) of two tables searched with func_020138b4 (mUnk_00 and mUnk_02), and at 0x0a the offset
// from 0x04 of a table of offsets to Unk020103c0_o and Unk020106c8_14.
typedef struct Unk020101e8_08 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mUnk_0a;
} Unk020101e8_08;

// Table searched with func_020138b4: a count at 0x01 and at 0x06 the offset of a block holding the stride of the
// entries (0x00) and the offset of an array of 16-byte values (0x02); the entries start 4 bytes into that block.
typedef struct Unk02010294_t {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[4];
    /* 06 */ u16 mUnk_06;
} Unk02010294_t;

// Block holding the stride of a table (0x00) and the offset of an array of 16-byte values (0x02).
typedef struct Unk02010310_d {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk02010310_d;

// Entry of a table: the offset of a byte list at 0x00, its length at 0x02 and a flag byte at 0x03 (bit 0 set by
// func_020103c0 and func_020106c8, cleared by func_020101e8, func_0201023c and func_0201063c).
typedef struct Unk020103c0_e {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020103c0_e;

// Entry of the table of Unk02010294 at mUnk_34; bit 0 of mUnk_02 is tested.
typedef struct Unk020103c0_d {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk020103c0_d;

typedef struct Unk020103c0_o {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ u16 mUnk_1c;
} Unk020103c0_o;

// Object with words at 0x08, 0x18 and 0x2c, at 0x34 the offset of a table searched with func_020138b4 and at 0x3c a
// table searched with it.
typedef struct Unk02010294 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u8 mUnk_30[4];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[6];
    /* 3c */ u8 mUnk_3c[1];
} Unk02010294;

// Element of the table at Unk020101e8_08.mUnk_0a.
typedef struct Unk020106c8_14 {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
} Unk020106c8_14;

// Fourth argument of func_020106c8: an entry found by func_020138b4.
typedef struct Unk020106c8_0c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk020106c8_0c;

extern u32 data_02170284;
extern u16 data_02170288[9];

void func_0200fe7c(u32 m, u16 v);
u32 func_0200ff04(u32 m, u16 v);
void func_0200ffd8(void);
void func_0201000c(Unk0201000c *p);
void func_020100fc(Unk02010168 *a);
u32 func_02010168(Unk02010168 *a, Unk02010294 *b);
u32 func_020101e8(Unk020101e8 *a, const u32 *k);
void func_0201023c(Unk020101e8 *a);
u32 func_02010294(Unk020101e8 *a, Unk02010294 *b, const u32 *k);
u32 func_02010310(Unk020101e8 *a, Unk02010294 *b);
void func_020103c0(Unk020101e8_08 *a, Unk020103c0_e *e, Unk02010294 *b, Unk020103c0_d *d);
u32 func_02010458(Unk020101e8 *a, const u32 *k);
void func_020104a4(Unk020101e8 *a);
int func_0201050c(Unk020101e8 *a, Unk02010294 *b, const u32 *k);
int func_02010584(Unk020101e8 *a, Unk02010294 *b);
void func_0201063c(Unk020101e8_08 *a, Unk020103c0_e *b);
void func_020106c8(Unk020101e8_08 *a, Unk020103c0_e *b, Unk02010294 *c, Unk020106c8_0c *d);
