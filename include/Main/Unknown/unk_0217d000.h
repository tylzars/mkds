#pragma once

#include "types.h"

#include "code_0212c478.h" // Unk0212c400
#include "code_0212c7a0.h" // Unk0212c7a0
#include "code_0212c7f0.h" // Unk0212c8a4
#include "code_0212c9d4.h" // Unk0212ccd4, Unk0212c9d4
#include "code_0201ea58.h" // Unk0201ea30
#include "Main/Unknown/code_02124094.h" // Unk02124b1c
#include "code_0212da38.h" // Unk02017328, Unk0212d9dc
#include "Main/Unknown/types_02180728.h" // Unk02180728

typedef struct Unk0200eb90 Unk0200eb90;

// Three words derived from a halfword.
typedef struct Unk0217d410_2c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217d410_2c;

// Object behind data_0217d410: 0x90 bytes allocated by func_0212b928.
typedef struct Unk0217d410 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a[5];
    /* 14 */ u16 mUnk_14[4];
    /* 1c */ u16 mUnk_1c[4];
    /* 24 */ u16 mUnk_24[3];
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ Unk0217d410_2c mUnk_2c[4];
    /* 5c */ Unk0217d410_2c mUnk_5c[4];
    /* 8c */ s32 mUnk_8c;
} Unk0217d410;

// Object behind data_0217d358.
typedef struct Unk0217d358 {
    /* 00 */ u8 *mUnk_00;
} Unk0217d358;

struct Nclr;

// Object behind data_0217d35c: 0x18 bytes allocated by func_021172a8; members 0x0, 0x4 and 0x8 + 4 * i are filled
// through LocateNcgr2, LocateNcer and LocateNclr.
typedef struct Unk0217d35c {
    /* 00 */ struct Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ struct Nclr *mUnk_08[3];
    /* 14 */ void *mUnk_14;
} Unk0217d35c;

struct Unk0212d5f8;
struct Unk0212ef48;
struct Ncgr;
struct Nclr;
struct Nscr;

// Object behind data_0217d354; the object at its member 0x8 has 0xc added to it.
typedef struct Unk0217d354_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk0217d354_08;

typedef struct Unk0217d354 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk0217d354_08 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u16 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 28 */ s32 mUnk_28;
} Unk0217d354;

// Object behind data_0217d350 members 0x10 and 0x20.
typedef struct Unk0217d350_10 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
} Unk0217d350_10;

// Object behind data_0217d350.
typedef struct Unk0217d350 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0217d350_10 *mUnk_10;
    /* 14 */ Unk02124b1c *mUnk_14;
    /* 18 */ Unk0201ea30 *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk0217d350_10 *mUnk_20;
    /* 24 */ Unk02124b1c *mUnk_24;
    /* 28 */ struct Ncgr *mUnk_28;
    /* 2c */ struct Unk02021dc8 *mUnk_2c;
    /* 30 */ Unk0201ea30 *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ Unk02124b1c *mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ void *mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s16 mUnk_74;
    /* 76 */ s16 mUnk_76;
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ u32 mUnk_84;
    /* 88 */ void *mUnk_88;
    /* 8c */ void *mUnk_8c;
    /* 90 */ s32 mUnk_90[2];
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ s32 mUnk_a0;
} Unk0217d350;

// Object behind data_0217d36c.
typedef struct Unk0217d36c {
    /* 00 */ void *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk0217d36c;

// Object behind data_0217d370 (0x10 bytes); func_0211dfb4 and func_0211df44 allocate and fill it.
typedef struct Unk0217d370 {
    /* 00 */ struct Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ struct Nclr *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0217d370;

// Object at data_0217d070 (0x14 bytes); func_0210d740 fills it. data_0217d07c names its member 0x0c.
typedef struct Unk0217d070 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ Unk0212c400 *mUnk_0c;
    /* 10 */ Unk0212c400 *mUnk_10;
} Unk0217d070;

// Object at data_0217d084 (0x1c bytes); func_0210dc60 stores its second argument at 0x00.
typedef struct Unk0217d084 {
    /* 00 */ Unk0217d070 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ Unk0212c400 **mUnk_18;
} Unk0217d084;

// Object at data_0217d32c (0x10 bytes); mUnk_08 points to a row of six words.
typedef struct Unk0217d32c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk0212d9dc *mUnk_04;
    /* 08 */ u32 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d32c;

// Object behind gRecordVS.
typedef struct Unk0217d348 {
    /* 00 */ struct Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ struct Nscr *mUnk_10;
    /* 14 */ Unk02124b1c *mUnk_14;
    /* 18 */ Unk0201ea30 *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ struct Nscr *mUnk_20;
    /* 24 */ Unk02124b1c *mUnk_24;
    /* 28 */ struct Ncgr *mUnk_28;
    /* 2c */ struct Unk02021dc8 *mUnk_2c;
    /* 30 */ Unk0201ea30 *mUnk_30;
    /* 34 */ Unk0201ea30 *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ Unk02124b1c *mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s16 mUnk_68;
    /* 6a */ s16 mUnk_6a;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s16 mUnk_74;
    /* 76 */ u8 mUnk_76[2];
    /* 78 */ void *mUnk_78;
    /* 7c */ void *mUnk_7c;
    /* 80 */ s32 mUnk_80[2];
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
} Unk0217d348;

// Object behind data_0217d360.
typedef struct Unk0217d360 {
    /* 00 */ struct Unk02021dc8 *mSelectCupMNcer;
    /* 04 */ Unk0201ea30 *mSelectCupMBncl;
    /* 08 */ void *mSelectCupMBnll;
    /* 0c */ struct Unk02021dc8 *mSelectCupSNcer;
    /* 10 */ void *mSelectCupSBncl;
    /* 14 */ Unk0201ea30 *mSelectCupSBnbl;
    /* 18 */ Unk02124b1c *mSelectCupMTable;
    /* 1c */ Unk02124b1c *mSelectCupSTable;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mCommonMessages;
    /* 28 */ void *mMenuMessages;
    /* 2c */ void *mHeap;
    /* 30 */ s32 mState;
    /* 34 */ s32 mNextState;
    /* 38 */ s32 mStateFrames;
    /* 3c */ s32 mMode;
    // Negated and shifted into the upper half-word of the BG0 offset register.
    /* 40 */ s32 mBg0Offset;
    /* 44 */ s32 mIndex;
    /* 48 */ s32 mUnk_48[8];
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s16 mUnk_78;
    /* 7a */ u8 mUnk_7a[2];
    /* 7c */ s32 mUnk_7c;
    /* 80 */ void *mUnk_80;
    /* 84 */ void *mUnk_84;
    /* 88 */ s32 mResult;
} Unk0217d360;

// Object behind gSelectCup.
typedef struct Unk0217d364 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ struct Unk02021dc8 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ Unk0201ea30 *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ Unk02124b1c *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mHeap;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ s16 mUnk_50;
    /* 52 */ u8 mUnk_52[2];
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ s32 mUnk_60;
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk0217d364;

// Object behind data_0217d368, and the object its mUnk_20 member points to.
typedef struct Unk0217d368_20 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ u16 mUnk_0c;
} Unk0217d368_20;

typedef struct Unk0217d368 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk02124b1c *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk0217d368_20 *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s16 mUnk_3c[5][2];
    /* 50 */ s16 mUnk_50[2][2];
    /* 58 */ s16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x02];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68[4];
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s32 mUnk_80;
    /* 84 */ u32 mUnk_84;
    /* 88 */ s16 mUnk_88;
    /* 8a */ s16 mUnk_8a;
    /* 8c */ u32 mUnk_8c[8];
    /* ac */ u16 mUnk_ac[2];
    /* b0 */ u16 mUnk_b0[2];
    /* b4 */ void *mUnk_b4;
    /* b8 */ vu32 mUnk_b8;
} Unk0217d368;

// Object behind data_0217d37c (0x10 bytes), allocated by func_0211f2b8.
typedef struct Unk0217d37c {
    /* 00 */ struct Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ struct Nclr *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0217d37c;

// Object behind data_0217d380 (0x28 bytes), allocated by func_0211f4b0.
typedef struct Unk0217d380 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x4];
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk02124b1c *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk0217d380;

// Object at data_0217d244 (0x10 bytes).
typedef struct Unk0217d244 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d244;

// Object at data_0217d2a4.
typedef struct Unk0217d2a4 {
    /* 00 */ s32 mUnk_00[14];
    /* 38 */ s32 mUnk_38[14];
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
} Unk0217d2a4;

// Object behind data_0217d374, allocated by func_0211e480.
typedef struct Unk0217d374 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
} Unk0217d374;

// Object behind data_0217d378, allocated by func_0211e958.
typedef struct Unk0217d378 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ struct Unk02021dc8 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ u8 mUnk_44[0x04];
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ s32 mUnk_50;
} Unk0217d378;

// Halfword objects behind data_0217d34c member 0x4.
typedef struct Unk0217d34c_04 {
    /* 00 */ u16 mUnk_00;
} Unk0217d34c_04;

// Object behind data_0217d34c.
typedef struct Unk0217d34c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ Unk0217d34c_04 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0217d34c;

// Object behind data_0217d3ec: 0x814 bytes allocated by func_02125de0.
typedef struct Unk0217d3ec {
    /* 000 */ s32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ s32 mUnk_08;
    /* 00c */ s32 mBackScreenKind;
    /* 010 */ u16 mBackScreenSNscrCopy[0x400];
    /* 810 */ s32 mUnk_810;
} Unk0217d3ec;

// Objects of 0x20 bytes set up by func_02023408; the word at 0x18 is called with the object and a value.
typedef struct Unk0217d3f0_2098 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct Unk0217d3f0_2098 *, s32);
    /* 1c */ u32 mUnk_1c;
} Unk0217d3f0_2098;

// Objects of 0x10 bytes passed first to func_0212583c; member 0x00 points to one Unk0217d3f0_2098.
typedef struct Unk0217d3f0_2178 {
    /* 00 */ Unk0217d3f0_2098 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d3f0_2178;

// Object behind data_0217d3f0: 0x2278 bytes allocated by func_021274ec.
typedef struct Unk0217d3f0 {
    /* 0000 */ u32 mUnk_00;
    /* 0004 */ u32 mUnk_04;
    /* 0008 */ u32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ u32 mUnk_18[2];
    /* 0020 */ u32 mUnk_20[2];
    /* 0028 */ s32 mUnk_28;
    /* 002c */ u32 mUnk_2c;
    /* 0030 */ u32 mUnk_30;
    /* 0034 */ u32 mUnk_34;
    /* 0038 */ u32 mUnk_38;
    /* 003c */ u32 mUnk_3c;
    /* 0040 */ u32 mUnk_40;
    /* 0044 */ u32 mUnk_44;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ u32 mUnk_4c;
    /* 0050 */ u32 mUnk_50;
    /* 0054 */ u16 mUnk_54[0x800];
    /* 1054 */ u16 mUnk_1054[0x800];
    /* 2054 */ s32 mUnk_2054[2];
    /* 205c */ s32 mUnk_205c[2];
    /* 2064 */ s32 mUnk_2064[2];
    /* 206c */ s32 mUnk_206c[2];
    /* 2074 */ u32 mUnk_2074[2];
    /* 207c */ s32 mUnk_207c;
    /* 2080 */ u32 mUnk_2080[2];
    /* 2088 */ u32 mUnk_2088[2];
    /* 2090 */ u32 mUnk_2090[2];
    /* 2098 */ Unk0217d3f0_2098 mUnk_2098[7];
    /* 2178 */ Unk0217d3f0_2178 mUnk_2178[7];
    /* 21e8 */ void *mUnk_21e8[7];
    /* 2204 */ u32 mUnk_2204[7];
    /* 2220 */ u32 mUnk_2220[7];
    /* 223c */ u32 mUnk_223c[2];
    /* 2244 */ u16 mUnk_2244;
    /* 2246 */ u16 mUnk_2246;
    /* 2248 */ u32 mUnk_2248;
    /* 224c */ u32 mUnk_224c;
    /* 2250 */ s32 mUnk_2250;
    /* 2254 */ s32 mUnk_2254;
    /* 2258 */ s32 mUnk_2258;
    /* 225c */ struct Nscr *mUnk_225c[7];
} Unk0217d3f0;

// Object behind data_0217d3f4.
typedef struct Unk0217d3f4 {
    /* 000 */ u32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ u32 mUnk_08;
    /* 00c */ u32 mUnk_0c;
    /* 010 */ s32 mUnk_10;
    /* 014 */ u32 mUnk_14;
    /* 018 */ u32 mUnk_18;
    /* 01c */ u32 mUnk_1c;
    /* 020 */ u32 mUnk_20;
    /* 024 */ u32 mUnk_24;
    /* 028 */ u32 mUnk_28;
    /* 02c */ u16 mUnk_2c[0x400];
    /* 82c */ u32 mUnk_82c;
    /* 830 */ u32 mUnk_830;
    /* 834 */ Unk0217d3f0_2098 mUnk_834[2];
    /* 874 */ Unk0217d3f0_2178 mUnk_874[2];
    /* 894 */ u8 *mUnk_894[2];
    /* 89c */ s32 mUnk_89c;
    /* 8a0 */ u32 mUnk_8a0;
    /* 8a4 */ u32 mUnk_8a4;
    /* 8a8 */ s32 mUnk_8a8[2];
    /* 8b0 */ s32 mUnk_8b0;
} Unk0217d3f4;

// Object behind gSelectReturn: 0x828 bytes allocated by InitSelectReturn.
typedef struct Unk0217d3f8 {
    /* 000 */ s32 mUnk_00;
    /* 004 */ s32 mState;
    /* 008 */ s32 mUnk_08;
    /* 00c */ s32 mUnk_0c;
    /* 010 */ u16 mUnk_10[0x400];
    /* 810 */ s32 mState1Requested;
    /* 814 */ s32 mState3Requested;
    /* 818 */ s32 mState4Requested;
    /* 81c */ s32 mBg2Offset;
    /* 820 */ s32 mDisplayBitOn;
    /* 824 */ s32 mUnk_824;
} Unk0217d3f8;

// Records of 8 bytes: 0x80 of them start an Unk0217d3fc_00, and two are at member 0x10c of Unk0217d404
// (func_0212a920 copies 6 bytes of a record into one of those).
typedef struct Unk0217d3fc_00_00 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk0217d3fc_00_00;

// Objects of 0x404 bytes; two of them make the object behind data_0217d3fc.
typedef struct Unk0217d3fc_00 {
    /* 000 */ Unk0217d3fc_00_00 mUnk_00[0x80];
    /* 400 */ u16 mUnk_400;
    /* 402 */ u16 mUnk_402;
} Unk0217d3fc_00;

// Object behind data_0217d3fc: 0x808 bytes allocated by func_02128958.
typedef struct Unk0217d3fc {
    /* 000 */ Unk0217d3fc_00 mUnk_00;
    /* 404 */ Unk0217d3fc_00 mUnk_404;
} Unk0217d3fc;

// Objects of 0x18 bytes, three of them at 0x2c of Unk0217d400: 0 and 1 are read as halfword strings, 2 also as the
// fields at 0x10, 0x14 and 0x16.
typedef struct Unk0217d400_2c {
    /* 00 */ union {
        u16 mUnk_00[12];
        struct {
            /* 00 */ u16 mUnk_00_0[8];
            /* 10 */ s32 mUnk_10;
            /* 14 */ s16 mUnk_14;
            /* 16 */ s16 mUnk_16;
        };
    };
} Unk0217d400_2c;

// Object behind data_0217d400: 0xc4 bytes allocated by func_0212a1e0.
typedef struct Unk0217d400 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14[2];
    /* 1c */ s32 mUnk_1c[2];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ Unk0217d400_2c mUnk_2c[3];
    /* 74 */ Unk02124b1c *mUnk_74[2][2];
    /* 84 */ s16 mUnk_84;
    /* 86 */ s16 mUnk_86[2][2];
    /* 8e */ u8 mUnk_8e[2];
    /* 90 */ struct Unk02021dc8 *mUnk_90;
    /* 94 */ struct Ncgr *mUnk_94;
    /* 98 */ struct Nclr *mUnk_98;
    /* 9c */ Unk0201ea30 *mUnk_9c[2];
    /* a4 */ Unk0201ea30 *mUnk_a4[2];
    /* ac */ void *mUnk_ac[2];
    /* b4 */ void *mUnk_b4[2];
    /* bc */ void *mUnk_bc;
    /* c0 */ void *mUnk_c0;
} Unk0217d400;

// Elements of 0x20 bytes at member 0x14 of Ncgr.
typedef struct Unk0217d404_bc {
    /* 00 */ u8 mUnk_00[0x20];
} Unk0217d404_bc;

typedef struct Unk0217d404_28 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217d404_28;

// Object behind data_0217d404: 0x11c bytes allocated by func_0212abdc.
typedef struct Unk0217d404 {
    /* 000 */ s32 mUnk_000[5];
    /* 014 */ s32 mUnk_014[2];
    /* 01c */ s32 mUnk_01c[2];
    /* 024 */ s32 mUnk_024;
    /* 028 */ Unk0217d404_28 mUnk_028[2];
    /* 038 */ Unk0217d3fc_00 *mUnk_038;
    /* 03c */ u8 mUnk_03c[0x20];
    /* 05c */ u8 mUnk_05c[0x60];
    /* 0bc */ Unk0217d404_bc *mUnk_0bc[5][4];
    /* 10c */ Unk0217d3fc_00_00 mUnk_10c[2];
} Unk0217d404;

// Object behind data_0217d408: 0x1a44 bytes allocated by func_0212b158; the 0x20 bytes at 0x14 are set up by
// func_02023408.
typedef struct Unk0217d408 {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ void *mUnk_0008;
    /* 000c */ s32 mUnk_000c;
    /* 0010 */ s32 mUnk_0010;
    /* 0014 */ u8 mUnk_0014[0x20];
    /* 0034 */ Unk02180728 mUnk_0034;
    /* 0044 */ u16 mUnk_0044[0xa00];
    /* 1444 */ u16 mUnk_1444[0x300];
} Unk0217d408;

// Records of 8 bytes in the stream at member 0x18 of Unk0217d40c.
typedef struct Unk0217d40c_18 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217d40c_18;

// Object behind data_0217d40c: 0x85c bytes allocated by func_0212b5ec; the 0x20 bytes at 0x20 are set up by
// func_02023408.
typedef struct Unk0217d40c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ u8 *mUnk_018;
    /* 01c */ s8 mUnk_01c;
    /* 01d */ u8 mUnk_01d[3];
    /* 020 */ u8 mUnk_020[0x20];
    /* 040 */ Unk02180728 mUnk_040;
    /* 050 */ u8 mUnk_050[0x800];
    /* 850 */ s8 mUnk_850;
    /* 851 */ u8 mUnk_851[3];
    /* 854 */ s32 mUnk_854;
    /* 858 */ void *mUnk_858;
} Unk0217d40c;

// Objects whose layout isn't known yet.
extern u8 data_0217d014[];
extern u8 data_0217d018[];
extern u8 data_0217d01c[];
extern Unk02017328 data_0217d028;
extern u32 data_0217d064;
extern u8 data_0217d134[];
extern u8 data_0217d178[];
extern s32 data_0217d1f4;
extern s32 data_0217d20c;
extern s32 data_0217d21c;
extern u32 data_0217d220;
extern Unk0217d244 data_0217d244;
extern struct Unk0217d344 *data_0217d344;
extern Unk0217d350 *data_0217d350;
extern Unk0217d354 *data_0217d354;
extern Unk0217d358 *data_0217d358;
extern Unk0217d35c *data_0217d35c;
extern Unk0217d368 *data_0217d368;
extern Unk0217d36c *data_0217d36c;
extern Unk0217d370 *data_0217d370;
extern Unk0217d374 *data_0217d374;
extern Unk0217d378 *data_0217d378;
extern Unk0217d37c *data_0217d37c;
extern Unk0217d380 *data_0217d380;
extern char gKartFilterString[0x64];
extern Unk0217d3ec *data_0217d3ec;
extern Unk0217d3f0 *data_0217d3f0;
extern Unk0217d3f4 *data_0217d3f4;
extern Unk0217d3f8 *gSelectReturn;
extern Unk0217d3fc *data_0217d3fc;
extern Unk0217d400 *data_0217d400;
extern Unk0217d408 *data_0217d408;
extern u32 data_0217d1f0;
extern s32 data_0217d22c[];
extern s32 data_0217d320;
extern s32 data_0217d324;
extern s32 data_0217d328;
extern Unk0217d40c *data_0217d40c;
extern u32 data_0217d438;
extern u32 data_0217d43c;
extern u32 data_0217d440;
extern u32 data_0217dda8;
extern Unk0212ccd4 data_0217ddd0;
extern Unk0212c400 data_0217d45c[16];
extern Unk0212c7a0 data_0217d89c[];
extern Unk02017328 data_0217dd1c;
extern Unk0212c8a4 data_0217dd28[];
extern s32 data_0217ddac;
extern Unk0200eb90 data_0217ddb0;
extern Unk0212c9d4 data_0217de24[8];
extern struct Unk0212d5f8 *data_0217dec4;
extern s32 data_0217d1e8;
extern s32 data_0217d1ec;
extern s32 data_0217d1f8;
extern s32 data_0217d200;
extern s32 data_0217d208;
extern u8 data_0217d1e0;
extern u8 data_0217d1e4;
extern s32 data_0217d1fc;
extern u32 data_0217d204;
extern s32 data_0217d210;
extern s32 data_0217d214;
extern volatile s32 data_0217d218;
extern s32 data_0217d224[2];
extern Unk0217d2a4 data_0217d2a4;
extern s32 data_0217d2dc[];
extern void *data_0217d33c;
extern void *data_0217d340;
extern Unk0217d404 *data_0217d404;
extern Unk0217d410 *data_0217d410;
extern struct Unk0212ef48 *data_0217df04;
extern u8 data_0217df08[];
extern Unk0212d9dc *data_0217d130;
extern Unk0217d070 data_0217d070;
// The member at 0x0c of data_0217d070, addressed through a pool word of its own.
extern Unk0212c400 *data_0217d07c;
extern Unk0217d084 data_0217d084;
extern struct Unk0212d5f8 data_0217d0a0;
extern Unk0217d32c data_0217d32c;
extern Unk0217d348 *gRecordVS;
extern Unk0217d34c *data_0217d34c;
extern Unk0217d360 *data_0217d360;
extern Unk0217d364 *gSelectCup;
extern u32 data_0217d1bc;
extern u8 data_0217d1c0[];
extern u8 data_0217d1c4[];
extern u8 data_0217d1c8[];
extern u8 data_0217d1cc[];
extern u8 data_0217d1d0[];
extern u32 data_0217d23c[];
extern u32 data_0217d010[];
extern u32 data_0217d024[];
extern u8 data_0217d034[];
extern Unk02017328 data_0217d048[];
extern u8 data_0217d054[];
extern u32 data_0217d020;
extern void *data_0217d06c;
