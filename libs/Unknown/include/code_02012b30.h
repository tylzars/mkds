#pragma once

#include "types.h"

// Matrix of three direction vectors and a position.
typedef struct Unk02012f58 {
    /* 00 */ Vec3 mUnk_00[4];
} Unk02012f58;

// Entry of the table at mUnk_08 of Unk0201290c.
typedef struct Unk0201290c_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c; // bits 16-20 are tested
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e; // bits 0-3, 5 and 13 are tested
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u8 mUnk_2c[1];
} Unk0201290c_08;

// Object with the offsets of two tables at mUnk_08 and mUnk_0c, counted from this object.
typedef struct Unk0201290c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mEntriesOffset;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[6];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mEntryCount; // the per-entry functions run for indexes below this
    /* 19 */ u8 mUnk_19[3];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk0201290c;

// Argument of func_020136f0 and func_02013c18: a tag word at 0x00, at 0x0c the offset of a table of word offsets and
// at 0x0e the number of entries (1 selects the layout func_020136f0 tests the tag for).
typedef struct Unk020136f0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk020136f0;

void func_02012b30(Unk020136f0 *a);
s32 func_02012cbc(Unk020136f0 *a);
void func_02012f24(void);
void func_02012f58(Unk02012f58 *a, void *b);
void func_02012ffc(Unk0201290c *a, u32 b);
void func_02013044(Unk0201290c *a, u32 b);
void func_0201308c(Unk0201290c *a, u32 b);
void func_020130d4(Unk0201290c *a, u32 b);
void func_0201311c(Unk0201290c *a, u32 b);
void func_02013164(Unk0201290c *a, u32 b);
void func_020131ac(Unk0201290c *a, u32 b);
void func_020131f4(Unk0201290c *a, u32 b);
void func_0201323c(Unk0201290c *a, u32 b);
void func_02013284(Unk0201290c *a, u32 b);
void func_020132cc(Unk0201290c *a, u32 b);
u32 func_02013314(Unk0201290c *a, u32 b);
u32 func_02013344(Unk0201290c *a, u32 b);
u32 func_02013378(Unk0201290c *a, u32 b);
u32 func_020133ac(Unk0201290c *a, u32 b);
void func_020133e0(Unk0201290c *a, u32 b, s32 c);
void func_02013424(Unk0201290c *a, u32 b, s32 c);
void func_02013468(Unk0201290c *a, u32 b, u32 c);
void func_020134b0(Unk0201290c *a, u32 b, u32 c);
void func_020134f8(Unk0201290c *a, u32 b, u32 c);
void func_02013540(Unk0201290c *a, u32 b, u32 c);
void func_02013588(Unk0201290c *a, u32 b, u32 c);
void func_020135d0(Unk0201290c *a, u32 b, u32 c);
void func_02013618(Unk0201290c *a, u32 b, u32 c);
void func_02013660(Unk0201290c *a, u32 b, u32 c);
void func_020136a8(Unk0201290c *a, u32 b, u32 c);
void *func_020136f0(Unk020136f0 *a);
