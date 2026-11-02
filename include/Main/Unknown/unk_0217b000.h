#pragma once

#include "types.h"
#include "Main/Unknown/unk_02165000.h" // Unk02165ff0
#include "Main/Unknown/code_020846c0.h" // Unk0208526c
#include "code_0212da38.h" // Unk02017328
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ffdee4.h" // Unk0217b614
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0209bc74.h" // Unk0209bc74
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/unk_0217d000.h" // Unk0217d3f0_2098
#include "Main/Unknown/types_02180728.h" // Unk02180728
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_02089fa0.h" // Unk0208a69c
#include "code_0214a748.h" // Unk0214ad4c

struct Unk020f41c4_B;
struct Unk0217b4f0;
struct Unk020d9cf4;
struct Unk0217b43c;
struct Unk020b47d8;
struct Unk020b4934;
struct Unk020b4a44;
struct Unk02022aa8;
struct Unk020a3fa8_a4;

// Element of 0x14 bytes of the table behind data_0217b704.
typedef struct Unk020de84c_14 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk020de84c_14;

// Element of 8 bytes of the table behind data_0217b708.
typedef struct Unk020de84c_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020de84c_08;

// 8-byte elements of the table at member 0xc of Unk0217b498 (UnkPair020b502c of code_020b502c.h is this type).
typedef struct Unk0217b498_0c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b498_0c;

// 0x14-byte elements of the table at member 0x10 of Unk0217b498.
typedef struct Unk0217b498_10 {
    /* 00 */ Unk0217b498_0c mUnk_00;
    /* 08 */ struct Unk020224e0_c *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} Unk0217b498_10;

// Elements of the table at member 0 of Unk0217b498.
typedef struct Unk0217b498_00 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x5e];
    /* 7e */ u16 mUnk_7e;
    /* 80 */ u8 mUnk_80[0x28];
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ u8 mUnk_b4[4];
    /* b8 */ u16 mUnk_b8;
} Unk0217b498_00;

// Object behind data_0217b3fc to data_0217b420, data_0217b42c to data_0217b434, data_0217b440 to data_0217b484,
// data_0217b48c, data_0217b494, data_0217b498, data_0217b4a0 and the ov001 pointers data_ov001_021a9b8c and
// data_ov001_021a9ba4 to data_ov001_021a9bc4 (func_020c0c2c and func_020c0ba8 allocate it, func_020c0b84 clears it).
typedef struct Unk0217b498 {
    /* 00 */ Unk0217b498_00 **mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk0217b498_0c *mUnk_0c;
    /* 10 */ Unk0217b498_10 *mUnk_10;
} Unk0217b498;

// Halfwords from 0x02 of Unk0217b490 read by func_020cf340 when data_021759c0->mUnk_00 is 0x20: six, two rows
// of three and two.
typedef struct Unk0217b490_02_03 {
    /* 00 */ u16 mUnk_00[6];
    /* 0c */ u16 mUnk_0c[2][3];
    /* 18 */ u16 mUnk_18[2];
} Unk0217b490_02_03;

// The halfwords from 0x02 of Unk0217b490 as func_020cf340 and func_020cfca4 index them for the values of
// data_021759c0->mUnk_00: a run of 0x15 (0x1c, 0x1f, 0x2e), nine rows of three (0xf), five rows of four (0x11)
// and Unk0217b490_02_03 (0x20).
typedef union Unk0217b490_02 {
    u16 mUnk_00[0x15];
    u16 mUnk_01[9][3];
    u16 mUnk_02[5][4];
    Unk0217b490_02_03 mUnk_03;
} Unk0217b490_02;

// Object behind data_0217b490, 0x38 bytes (allocated by func_020cffa0).
typedef struct Unk0217b490 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ Unk0217b490_02 mUnk_02;
} Unk0217b490;

// Object behind data_0217b4b4, 0x28 bytes; mUnk_18 points into mUnk_08.
typedef struct Unk0217b4b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08[4];
    /* 18 */ s32 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ s32 mUnk_24;
} Unk0217b4b4;

// Object behind data_0217b4d8: the words at 0x00 to 0x0c.
typedef struct Unk0217b4d8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217b4d8;

// Object at data_0217b4f8: six vectors between words at 0x00/0x04 and 0x50/0x54.
typedef struct Unk0217b4f8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ Vec3 mUnk_14;
    /* 20 */ Vec3 mUnk_20;
    /* 2c */ Vec3 mUnk_2c;
    /* 38 */ Vec3 mUnk_38;
    /* 44 */ Vec3 mUnk_44;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} Unk0217b4f8;

// Object behind data_0217b438, 0x6c bytes (func_020ca6c4 allocates it); func_020ca9e4 calls the function at 0x0c.
typedef struct Unk0217b438 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ UnkFunc *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0217d3f0_2098 mUnk_30;
    /* 50 */ Unk02180728 mUnk_50;
    /* 60 */ struct Unk020b4a44 *mUnk_60;
    /* 64 */ struct Unk020b4934 *mUnk_64;
    /* 68 */ struct Unk020b47d8 *mUnk_68;
} Unk0217b438;

// 16-byte rows of the table behind data_0217b4d4 (func_020d34e4 reads the halfwords).
typedef struct Unk0217b4d4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0217b4d4;

extern void *data_0217b0ec;
extern void *data_0217b0f0;
extern void *data_0217b0f4;
extern u16 data_0217b028;
extern s32 data_0217b02c;
extern Unk02165ff0 *data_0217b030;

// Objects whose layout isn't known yet.
struct Unk020184e4;

// Object behind data_0217b038, 0x14 bytes.
typedef struct Unk0217b038 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u8 *mUnk_10;
} Unk0217b038;

extern Unk0217b038 *data_0217b038;

extern struct Unk020184e4 *data_0217b03c;

extern struct Unk020184e4 *data_0217b044;
extern struct Unk020184e4 *data_0217b04c;
extern UnkFunc *data_0217b054;

// Function pointers set by func_0208c284 (the targets take different parameters).
extern UnkFunc *data_0217b058;
extern UnkFunc *data_0217b05c;
extern UnkFunc *data_0217b060;
extern UnkFunc *data_0217b064;
extern UnkFunc *data_0217b068;
extern UnkFunc *data_0217b06c;
extern UnkFunc *data_0217b070;
extern s32 (*data_0217b074)();
extern struct Unk0208c5b8 *data_0217b078;
struct Unk0208e490;

// Object behind data_0217b080, 0x60 bytes: a list at 0x00 and five lists at 0x0c (12 bytes each), and five pointers
// at 0x48 to arrays of object pointers.
typedef struct Unk0217b080 {
    /* 00 */ Unk02017328 mUnk_00;
    /* 0c */ Unk02017328 mUnk_0c[5];
    /* 48 */ struct Unk0208e490 **mUnk_48[5];
    /* 5c */ u16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
} Unk0217b080;

extern Unk0217b080 *data_0217b080;
extern s32 data_0217b07c;
extern s32 data_0217b084[2];
extern Unk0208fd8c_08 *data_0217b0a4;

// Object behind data_0217b08c, 0x38 bytes: 12-byte blocks at 0x00, 0x0c and 0x18.
typedef struct Unk0217b08c {
    /* 00 */ Unk02017328 mUnk_00;
    /* 0c */ Unk02017328 mUnk_0c;
    /* 18 */ Unk02017328 mUnk_18;
    /* 24 */ Unk0208526c mUnk_24;
    /* 34 */ s32 mUnk_34;
} Unk0217b08c;

extern Unk0217b08c *data_0217b08c;
extern UnkFunc *data_0217b090;
extern UnkFunc *data_0217b094;
extern UnkFunc *data_0217b098;
extern UnkFunc *data_0217b0a0;
extern UnkFunc *data_0217b0a8;
extern UnkFunc *data_0217b0ac;
extern Unk0208fd8c_08 *data_0217b09c;
extern s32 *data_0217b0b0;
extern void *data_0217b0b4;
extern void *data_0217b0b8;

// The 0x10 bytes at 0x784 of Unk0217b034; the callbacks at 0x794 and 0x798 get their address.
typedef struct Unk0217b034_784 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
} Unk0217b034_784;

// Object behind data_0217b034, 0x79c bytes.
typedef struct Unk0217b034 {
    /* 000 */ Unk0208a69c *mUnk_000[9];
    /* 024 */ u8 mUnk_024[0x718];
    /* 73c */ s32 mUnk_73c;
    /* 740 */ u16 mUnk_740;
    /* 742 */ u16 mUnk_742;
    /* 744 */ Unk0214ad4c mUnk_744;
    /* 784 */ Unk0217b034_784 mUnk_784;
    /* 794 */ void (*mUnk_794)(Unk0217b034_784 *);
    /* 798 */ void (*mUnk_798)(Unk0217b034_784 *);
} Unk0217b034;

extern Unk0217b034 *data_0217b034;
extern u32 data_0217b0d8;
extern void *data_0217b1a4;
// 0x70-byte entries of Unk0217b1fc, one per index 0 to 7.
typedef struct Unk0217b1fc_000 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24[8];
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a[2];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x12];
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk0217b1fc_000;

// Object behind data_0217b1fc: eight 0x70-byte entries, then callbacks at 0x380 to 0x39c (set by func_020a2300 to
// func_020a2364) and the pointer at 0x3bc (func_020a238c / func_020a2378), whose 0x38-byte entries are read like
// Unk020a3fa8_a4.
typedef struct Unk0217b1fc {
    /* 000 */ Unk0217b1fc_000 mUnk_000[8];
    /* 380 */ s32 (*mUnk_380)(s32, s32);
    /* 384 */ void (*mUnk_384)(s32, s32);
    /* 388 */ s32 (*mUnk_388)(u16, u16);
    /* 38c */ void (*mUnk_38c)(u16);
    /* 390 */ void (*mUnk_390)(void);
    /* 394 */ u8 mUnk_394[8];
    /* 39c */ void (*mUnk_39c)(s32, s32);
    /* 3a0 */ u16 mUnk_3a0;
    /* 3a2 */ u16 mUnk_3a2;
    /* 3a4 */ u16 mUnk_3a4;
    /* 3a6 */ u8 mUnk_3a6[2];
    /* 3a8 */ s32 mUnk_3a8;
    /* 3ac */ s32 mUnk_3ac;
    /* 3b0 */ s32 mUnk_3b0;
    /* 3b4 */ s32 mUnk_3b4;
    /* 3b8 */ u16 mUnk_3b8;
    /* 3ba */ u8 mUnk_3ba[2];
    /* 3bc */ struct Unk020a3fa8_a4 *mUnk_3bc;
} Unk0217b1fc;

extern Unk0217b1fc *data_0217b1fc;
extern void *data_0217b204;
extern Vec3 data_0217b208;
extern Vec3 data_0217b214;
// 8-byte entries of the tables Unk0217b278 points to (func_020ab338 returns one).
typedef struct Unk0217b278_10 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217b278_10;

struct Unk020b4934;
struct Unk0217b278;

// Set up by func_020aa028 (at 0x1c of Unk0217b278, which mUnk_2c then points to); mUnk_08 is called with the
// Unk0217b278 (func_020ab45c is one).
typedef struct Unk0217b278_1c {
    /* 00 */ Unk0217b278_10 *mUnk_00;
    /* 04 */ struct Unk020b4934 *mUnk_04;
    /* 08 */ void (*mUnk_08)(struct Unk0217b278 *);
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0217b278_1c;

// Four halfwords at 0x34 of Unk0217b278 (func_020ab59c, func_020ab5bc).
typedef struct Unk0217b278_34 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217b278_34;

// Object at data_0217b2cc: an Unk0217b278_34 followed by two halfwords (func_020ab528, func_020ab580).
typedef struct Unk0217b2ac {
    /* 00 */ Unk0217b278_34 mUnk_00;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk0217b2ac;

// Object at data_0217b278, 0x54 bytes. data_0217b280, data_0217b294, data_0217b2ac and data_0217b2b8 are the
// addresses of its members at 0x08, 0x1c, 0x34 and 0x40.
typedef struct Unk0217b278 {
    /* 00 */ Unk0217b278_10 mUnk_00;
    /* 08 */ Unk0217b278_10 mUnk_08;
    /* 10 */ Unk0217b278_10 *mUnk_10;
    /* 14 */ Unk0217b278_10 *mUnk_14;
    /* 18 */ Unk0217b278_10 *mUnk_18;
    /* 1c */ Unk0217b278_1c mUnk_1c;
    /* 2c */ Unk0217b278_1c *mUnk_2c;
    /* 30 */ u16 *mUnk_30;
    /* 34 */ Unk0217b278_34 mUnk_34;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 44 */ Unk0217b278_10 *mUnk_44;
    /* 48 */ u8 mUnk_48[4];
    /* 4c */ u16 (*mUnk_4c)(s32, u16);
    /* 50 */ s32 (*mUnk_50)(u32, s32);
} Unk0217b278;

extern Unk0217b278 data_0217b278;
extern Unk0217b2ac data_0217b2cc;
extern u8 data_0217b280[];
extern u16 data_0217b2b8[2];
extern Unk0217b278_1c data_0217b294;
extern Unk0217b278_34 data_0217b2ac;
// Object at data_0217b2d8, 0x28 bytes (func_020ab660 updates it, func_020ab72c clears it).
typedef struct Unk0217b2d8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c[4];
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ s32 mUnk_24;
} Unk0217b2d8;

extern Unk0217b2d8 data_0217b2d8;
extern u16 *data_0217b318;
extern u16 *data_0217b328;
extern u16 *data_0217b32c;
extern u16 *data_0217b330;
extern u16 *data_0217b300;
extern u16 *data_0217b304;
extern u16 *data_0217b308;
extern u16 *data_0217b30c;
extern u16 *data_0217b310;
extern u16 *data_0217b314;
extern u16 *data_0217b31c;
extern u16 *data_0217b320;
extern u16 *data_0217b324;
// Object behind data_0217b334, 0x78 bytes, allocated in func_020abcf4. func_020aba9c passes the pointers at 0x00
// and 0x04 to func_0200ee74 with the words at 0x08 and 0x0c.
typedef struct Unk0217b334 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ struct Unk020b4934 *mUnk_10[5];
    /* 24 */ struct Unk020b4934 *mUnk_24;
    /* 28 */ void *mUnk_28[6];
    /* 40 */ u16 *mUnk_40;
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
} Unk0217b334;

extern Unk0217b334 *data_0217b334;
extern u16 *data_0217b338;
extern void *data_0217b33c;
// Element of 8 bytes of data_02167e34: two code pointers.
typedef struct Unk020ad344_14 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ void (*mUnk_04)(s32);
} Unk020ad344_14;

struct Unk02124b1c;
struct Unk0201ea30;

// Object behind data_0217b340, 0x8bc bytes allocated by func_020ad344.
typedef struct Unk020ad344 {
    /* 000 */ s32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ s32 mUnk_08;
    /* 00c */ s32 mUnk_0c;
    /* 010 */ s32 mUnk_10;
    /* 014 */ Unk020ad344_14 mUnk_14[7];
    /* 04c */ s32 mUnk_4c;
    /* 050 */ s32 mUnk_50;
    /* 054 */ s32 mUnk_54;
    /* 058 */ s32 mUnk_58;
    /* 05c */ s32 mUnk_5c;
    /* 060 */ s16 mUnk_60;
    /* 062 */ u8 pad_62[2];
    /* 064 */ s32 mUnk_64;
    /* 068 */ struct Unk02124b1c *mUnk_68;
    /* 06c */ struct Unk0201ea30 *mUnk_6c;
    /* 070 */ void *mUnk_70;
    /* 074 */ struct Unk0201ea30 *mUnk_74;
    /* 078 */ struct Unk020b4a44 *mUnk_78;
    /* 07c */ struct Unk020b4934 *mUnk_7c;
    /* 080 */ struct Unk020b4a44 *mUnk_80;
    /* 084 */ struct Unk020b4934 *mUnk_84;
    /* 088 */ struct Unk020b47d8 *mUnk_88;
    /* 08c */ struct Unk020b47d8 *mUnk_8c;
    /* 090 */ struct Unk020b47d8 *mUnk_90;
    /* 094 */ u8 pad_94[0xc];
    /* 0a0 */ struct Unk020b4a44 *mUnk_a0;
    /* 0a4 */ struct Unk020b4934 *mUnk_a4;
    /* 0a8 */ struct Unk02021dc8 *mUnk_a8;
    /* 0ac */ u8 pad_ac[4];
    /* 0b0 */ Unk020ae630 mUnk_b0;
    /* 4b4 */ Unk020ae630 mUnk_4b4;
    /* 8b8 */ u8 *mUnk_8b8;
} Unk020ad344;

extern Unk020ad344 *data_0217b340;
extern const Unk020ad344_14 data_02167e34[7];
extern u8 data_0217b344[];
extern u16 *data_0217b34c;
// 0x20 bytes: four words, then four more words.
typedef struct Unk0217b350_858 {
    /* 00 */ s32 mUnk_00[4];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0217b350_858;

// Object behind data_0217b350, 0x914 bytes allocated by func_020b03bc (words from 0x828 to 0x910 read and written by
// func_020aeb7c). The pointers at 0x80c to 0x824 are written through func_020b4a7c, func_020b496c and func_020b4810.
typedef struct Unk0217b350 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x400];
    /* 404 */ u16 mUnk_404;
    /* 406 */ u16 mUnk_406;
    /* 408 */ u8 mUnk_408[0x400];
    /* 808 */ u16 mUnk_808;
    /* 80a */ u16 mUnk_80a;
    /* 80c */ struct Unk020b4a44 *mUnk_80c[2];
    /* 814 */ struct Unk020b4934 *mUnk_814[2];
    /* 81c */ struct Unk020b47d8 *mUnk_81c[3];
    /* 828 */ s32 mUnk_828;
    /* 82c */ s32 mUnk_82c;
    /* 830 */ s32 mUnk_830;
    /* 834 */ s32 mUnk_834;
    /* 838 */ s32 mUnk_838;
    /* 83c */ s32 mUnk_83c;
    /* 840 */ s32 mUnk_840;
    /* 844 */ s32 mUnk_844;
    /* 848 */ s32 mUnk_848;
    /* 84c */ s32 mUnk_84c;
    /* 850 */ s32 mUnk_850;
    /* 854 */ s32 mUnk_854;
    /* 858 */ Unk0217b350_858 mUnk_858[2];
    /* 898 */ s32 mUnk_898;
    /* 89c */ s32 mUnk_89c[8];
    /* 8bc */ s32 mUnk_8bc[8];
    /* 8dc */ s32 mUnk_8dc;
    /* 8e0 */ s32 mUnk_8e0;
    /* 8e4 */ s32 mUnk_8e4;
    /* 8e8 */ s32 mUnk_8e8;
    /* 8ec */ Unk020ae7c4 mUnk_8ec;
    /* 908 */ s32 mUnk_908;
    /* 90c */ s32 mUnk_90c;
    /* 910 */ s32 mUnk_910;
} Unk0217b350;

extern Unk0217b350 *data_0217b350;
struct Unk0217b354;
extern struct Unk0217b354 *data_0217b354;
struct Unk0217b3c4;
extern struct Unk0217b3c4 *data_0217b3c4;
// 8-byte elements at the start of Unk0217b3d8.
typedef struct Unk0217b3d8_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b3d8_00;

// 0xc-byte elements from 0xfc of Unk0217b3d8.
typedef struct Unk0217b3d8_fc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217b3d8_fc;

// Object behind data_0217b3d8, 0x15c bytes, allocated by func_020be7fc.
typedef struct Unk0217b3d8 {
    /* 000 */ Unk0217b3d8_00 mUnk_000[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ s32 mUnk_060[8];
    /* 080 */ s32 mUnk_080[8];
    /* 0a0 */ s32 mUnk_0a0[8];
    /* 0c0 */ s32 mUnk_0c0[8];
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ u16 mUnk_0e4;
    /* 0e6 */ u8 mUnk_0e6[2];
    /* 0e8 */ s32 mUnk_0e8[4];
    /* 0f8 */ u16 mUnk_0f8;
    /* 0fa */ u8 mUnk_0fa[2];
    /* 0fc */ Unk0217b3d8_fc mUnk_0fc[8];
} Unk0217b3d8;

extern Unk0217b3d8 *data_0217b3d8;
// Object behind data_0217b3dc, 0x25c bytes, allocated by func_020beb9c.
typedef struct Unk0217b3dc {
    /* 000 */ u16 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ void (*mUnk_010[49])(void);
    /* 0d4 */ void (*mUnk_0d4[49])(void);
    /* 198 */ void (*mUnk_198[49])(void *);
} Unk0217b3dc;

extern Unk0217b3dc *data_0217b3dc;
// Object behind data_0217b3e0, 0x20e4 bytes, allocated by func_020c3200.
typedef struct Unk0217b3e0 {
    /* 0000 */ s32 mUnk_0000[8];
    /* 0020 */ s32 mUnk_0020[8];
    /* 0040 */ s32 mUnk_0040[8];
    /* 0060 */ s32 mUnk_0060[8];
    /* 0080 */ s32 mUnk_0080[8];
    /* 00a0 */ s32 mUnk_00a0;
    /* 00a4 */ s32 mUnk_00a4;
    /* 00a8 */ s32 mUnk_00a8;
    /* 00ac */ void *mUnk_00ac;
    /* 00b0 */ s32 mUnk_00b0;
    /* 00b4 */ s32 mUnk_00b4;
    /* 00b8 */ struct Unk020b4a44 *mUnk_00b8;
    /* 00bc */ struct Unk020b4934 *mUnk_00bc;
    /* 00c0 */ struct Unk020b47d8 *mUnk_00c0[6];
    /* 00d8 */ u16 mUnk_00d8[2][0x800];
    /* 20d8 */ s32 mUnk_20d8;
    /* 20dc */ s32 mUnk_20dc;
    /* 20e0 */ s32 mUnk_20e0;
} Unk0217b3e0;

extern Unk0217b3e0 *data_0217b3e0;
extern struct Unk0217b3e8 *data_0217b3e8;
extern struct Unk0217b3f0 *data_0217b3f0;
extern struct Unk0217b3f4 *data_0217b3f4;
extern s32 data_0217b3f8;
extern Unk0217b438 *data_0217b438;
extern struct Unk0217b43c *data_0217b43c;
extern struct Unk0217b4a4 *data_0217b4a4;
extern struct Unk0217b4b0 *data_0217b4b0;
extern struct Unk020f41c4_B *data_0217b4b8;
extern struct Unk020f41c4_B *data_0217b4bc;
extern Unk0217b4d8 *data_0217b4d8;
extern Vec3 *data_0217b4dc;
extern s32 data_0217b4e0;
extern struct Unk020d9cf4 *data_0217b4e4;
extern s32 data_0217b4ec;
extern struct Unk0217b4f0 *data_0217b4f0;
extern s32 data_0217b4f4;
extern Unk0217b4f8 data_0217b4f8;
extern Unk0217b4f8 data_0217b550;
extern struct Unk0217b650 *data_0217b650;
extern struct Unk0217b654 *data_0217b654;
extern struct Unk020ea868 *data_0217b658;
extern struct Unk020ea670 *data_0217b65c;
extern struct Unk020d7b88 data_0217b660;
extern struct Unk020e0144_00 *data_0217b670;
extern struct Unk020db20c *data_0217b680;
extern struct Unk020db1b0 *data_0217b684;
extern Unk020e6488 *data_0217b688;
extern struct Unk020ea670 *data_0217b68c;
extern struct Unk020dbe74 *data_0217b690;
extern struct Unk020ea868 *data_0217b694;
extern struct Unk020dbed0 *data_0217b698;
extern Unk02012f58 data_0217b69c;
extern struct Unk020ea670 *data_0217b6cc;
extern struct Unk020ea868 *data_0217b6d0;
extern Unk020de334 *data_0217b6dc;
extern Unk020de2d8 *data_0217b6e0;
extern Unk020e6488 *data_0217b6e4;
extern Unk020e6488 *data_0217b6e8;
extern Unk020de2d8 *data_0217b6ec;
extern Unk020e6488 *data_0217b6f0;
extern Unk020e6488 *data_0217b6f4;
extern Unk020de334 *data_0217b6f8;
extern u16 data_0217b6fc;
extern Unk020de334 *data_0217b700;
extern Unk020de84c_14 *data_0217b704;
extern Unk020de84c_08 *data_0217b708;
extern Unk020de334 *data_0217b70c;
extern Unk020e6488 *data_0217b710;
extern Unk020de334 *data_0217b714;
extern Unk020de2d8 *data_0217b718;
extern Unk020e6488 *data_0217b71c;
extern Unk02012f58 data_0217b720;
extern u16 data_0217b750;
extern s32 data_0217b754;
extern Unk020de2d8 *data_0217b758;
extern s32 data_0217b75c;
extern Vec3 data_0217b760;
extern Unk020dfc44 *data_0217b76c;
extern void *data_0217b770;
extern Unk020de334 *data_0217b774;
extern void *data_0217b778;
extern void *data_0217b77c;
extern Unk020e6488 *data_0217b7b8;
extern Unk020e6488 *data_0217b7f0;
extern Unk020e53ac *data_0217b814;
extern Unk020e6488 *data_0217b830;
extern Unk02012f58 *data_0217b844;
extern Unk02012f58 *data_0217b848;
extern Unk02012f58 *data_0217b84c;
extern Unk02012f58 *data_0217b850;
extern Unk02012f58 *data_0217b854;
extern u8 data_0217b858[];
extern Unk02012f58 *data_0217b85c;
extern Unk02012f58 *data_0217b860;
extern u16 *data_0217b868;
extern s32 data_0217bc5c;
extern s32 data_0217bc60;

extern u16 data_0217b220;
#include "Main/Unknown/unk_0217b358.h"
#include "Main/Unknown/unk_0217b35c.h"
// Object behind data_0217b3c8, 0xc bytes, allocated by func_020ba520. The word at 0 is also read and written as two
// halfwords.
typedef struct Unk0217b3c8 {
    /* 00 */ union {
        s32 mUnk_00;
        u16 mUnk_00_h[2];
    };
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217b3c8;

extern Unk0217b3c8 *data_0217b3c8;
// Five words at 0x18 of Unk0217b3cc.
typedef struct Unk0217b3cc_18 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217b3cc_18;

// Object behind data_0217b3cc, 0x2c bytes, allocated by func_020bb530.
typedef struct Unk0217b3cc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ Unk0217b3cc_18 mUnk_18;
} Unk0217b3cc;

extern Unk0217b3cc *data_0217b3cc;
// Object behind data_0217b3d0, 0x38 bytes, allocated by func_020bc11c.
typedef struct Unk0217b3d0 {
    /* 00 */ Unk020ae7c4 mUnk_00;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20[6];
} Unk0217b3d0;

extern Unk0217b3d0 *data_0217b3d0;
// 0x18-byte elements of the tables at member 0x10 of Unk0217b3e4.
typedef struct Unk0217b3e4_10 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk0217b3e4_10;

// 0x40-byte elements of the table at member 0x790 of Unk0217b3e4.
typedef struct Unk0217b3e4_790 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04[3];
    /* 28 */ s32 mUnk_28[3];
    /* 34 */ s32 mUnk_34[3];
} Unk0217b3e4_790;

// 0x10-byte elements of the table at member 0x810 of Unk0217b3e4.
typedef struct Unk0217b3e4_810 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0217b3e4_810;

// Object behind data_0217b3e4, 0x910 bytes, allocated by func_020c4780.
typedef struct Unk0217b3e4 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004[2];
    /* 00c */ s32 mUnk_00c;
    /* 010 */ Unk0217b3e4_10 mUnk_010[2][0x28];
    /* 790 */ Unk0217b3e4_790 mUnk_790[2];
    /* 810 */ Unk0217b3e4_810 mUnk_810[16];
} Unk0217b3e4;

extern Unk0217b3e4 *data_0217b3e4;
// Object behind data_0217b3ec.
typedef struct Unk0217b3ec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217b3ec;

extern Unk0217b3ec *data_0217b3ec;
extern Unk0217b3ec *data_0217b3d4;
// Object behind data_0217b424, 0x44 bytes allocated by func_020c8d30: a table of object pointers and two counts
// (as in Unk0217b498), three halfwords and two arrays of three pairs.
typedef struct Unk0217b424 {
    /* 00 */ struct Unk020e1e98 **mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c[3];
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ Unk0217b498_0c mUnk_14[3];
    /* 2c */ Unk0217b498_0c mUnk_2c[3];
} Unk0217b424;

// Object behind data_0217b428, 0x194 bytes allocated by func_020c9fb8: arrays of eight entries and an Unk0217b498
// pointer at 0x190.
typedef struct Unk0217b428 {
    /* 000 */ s32 mUnk_000[8];
    /* 020 */ s32 mUnk_020[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ Unk0217b498_0c mUnk_060[8];
    /* 0a0 */ Vec3 mUnk_0a0[8];
    /* 100 */ u16 mUnk_100[8];
    /* 110 */ s32 mUnk_110[8];
    /* 130 */ s32 mUnk_130[8];
    /* 150 */ s32 mUnk_150[8];
    /* 170 */ s32 mUnk_170[8];
    /* 190 */ Unk0217b498 *mUnk_190;
} Unk0217b428;

extern Unk0217b424 *data_0217b424;
extern Unk0217b428 *data_0217b428;
extern struct Unk0217b49c *data_0217b49c;
extern u8 data_0217b4a8[];
extern struct Unk0217b4ac *data_0217b4ac;
extern Unk0217b4b4 *data_0217b4b4;
extern u16 data_0217b4c0;
extern u16 data_0217b4c4;
extern u16 data_0217b4c8;
extern u16 data_0217b4cc;
extern u16 data_0217b4d0;
extern Unk0217b4d4 *data_0217b4d4;
extern Unk020e71a0 **data_0217b4e8;
extern u8 data_0217b7c4[];
extern u8 data_0217b86c[];
extern Unk020e6488 *data_0217bbfc[];
struct Unk020f41c4_A;

extern struct Unk020f41c4_A **data_0217bd30;

extern void *data_0217b040;
extern s32 data_0217b234;
extern s32 data_0217b238;
extern u16 *data_0217b23c[2];
extern u16 *data_0217b244[2];
extern u16 *data_0217b24c[2];
// Object at data_0217b254, 0x24 bytes.
typedef struct Unk0217b254 {
    /* 00 */ struct Unk02022aa8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u16 *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk0217b254;

extern Unk0217b254 data_0217b254;
struct Unk0217b340;
struct Unk0217b344;
struct Unk020b4a44;
struct Unk02021dc8;
extern struct Unk0217b340 *data_0217b360;
extern struct Unk0217b344 *data_0217b364;
extern struct Unk020b4a44 *data_0217b368[2];
extern struct Unk020b4a44 *data_0217b36c;
extern struct Unk020b4934 *data_0217b370[2];
extern struct Unk020b4934 *data_0217b374;
extern struct Unk02021dc8 *data_0217b378[2];
extern struct Unk02021dc8 *data_0217b37c;
extern void *data_0217b380[2];
extern struct Unk020b4a44 *data_0217b388[2];
extern struct Unk020b4a44 *data_0217b38c;
extern struct Unk02022aa8 *data_0217b390[3];
extern struct Unk02022aa8 data_0217b39c;
extern struct Unk02022aa8 data_0217b3a8;
extern struct Unk02022aa8 data_0217b3b4;
extern Unk0217b498 *data_0217b3fc;
extern Unk0217b498 *data_0217b400;
extern Unk0217b498 *data_0217b404;
extern Unk0217b498 *data_0217b408;
extern Unk0217b498 *data_0217b40c;
extern Unk0217b498 *data_0217b410;
extern Unk0217b498 *data_0217b414;
extern Unk0217b498 *data_0217b418;
extern Unk0217b498 *data_0217b41c;
extern Unk0217b498 *data_0217b420;
extern Unk0217b498 *data_0217b42c;
extern Unk0217b498 *data_0217b430;
extern Unk0217b498 *data_0217b434;
extern Unk0217b498 *data_0217b440;
extern Unk0217b498 *data_0217b444;
extern Unk0217b498 *data_0217b448;
extern Unk0217b498 *data_0217b44c;
extern Unk0217b498 *data_0217b450;
extern Unk0217b498 *data_0217b454;
extern Unk0217b498 *data_0217b458;
extern Unk0217b498 *data_0217b45c;
extern Unk0217b498 *data_0217b460;
extern Unk0217b498 *data_0217b464;
extern Unk0217b498 *data_0217b468;
extern Unk0217b498 *data_0217b46c;
extern Unk0217b498 *data_0217b470;
extern Unk0217b498 *data_0217b474;
extern Unk0217b498 *data_0217b478;
extern Unk0217b498 *data_0217b47c;
extern Unk0217b498 *data_0217b480;
extern Unk0217b498 *data_0217b484;
extern Unk0217b498 *data_0217b48c;
extern Unk0217b490 *data_0217b490;
extern Unk0217b498 *data_0217b494;
extern Unk0217b498 *data_0217b498;
extern Unk0217b498 *data_0217b4a0;
extern s32 data_0217b890;
extern s32 data_0217b8ac;
extern s32 data_0217b8c4;
extern s32 data_0217b8e4;
extern s32 data_0217b900;

// Object whose halfword at 0xe is read by func_020e9d10.
typedef struct Unk0217b9ec {
    /* 000 */ u8 mUnk_000[0xe];
    /* 00e */ u16 mUnk_00e;
} Unk0217b9ec;

extern Unk0217b9ec data_0217b9ec;
extern Vec3 *data_0217bc4c;
extern void *data_0217b7d0;
extern void *data_0217b7cc;
extern void *data_0217b7c0;
extern void *data_0217b7bc;
extern void *data_0217b7b4;
extern void *data_0217b780;
extern void *data_0217b784;
extern void *data_0217b788;
extern void *data_0217b78c;
extern void *data_0217b790;
extern void *data_0217b794;
extern void *data_0217b798;
extern void *data_0217b79c;
extern void *data_0217b7a0;
extern void *data_0217b7a4;
extern void *data_0217b7a8;
extern void *data_0217b7ac;
extern void *data_0217b7b0;
extern void *data_0217b7c8;
extern void *data_0217b7d4;
extern void *data_0217b7d8;
extern void *data_0217b7e0;
extern void *data_0217b7e4;
extern void *data_0217b7e8;
extern void *data_0217b7ec;
extern void **data_0217b5c4;
extern s16 data_0217b5a8;
extern u16 *data_0217b5bc;
extern s16 data_0217b5ac;
extern s16 data_0217b5b0;
extern struct Unk0217b5b4 *data_0217b5b4;
extern struct Unk0217b5b8 *data_0217b5b8;
extern struct Unk0217b5b4 *data_0217b5c0;
extern s16 *data_0217b5c8;
extern s16 *data_0217b5cc;
extern Vec3 data_0217b800;
extern void *data_0217b838;
extern void *data_0217b83c;
extern void *data_0217b820;
extern void *data_0217b864;
extern s32 data_0217b8b4;
extern u16 data_0217b884;
extern u16 data_0217b880;
extern u16 data_0217b888;
extern u16 data_0217b870;
extern u16 data_0217b87c;
extern s32 data_0217b8b8;
extern s32 data_0217b88c;
extern s32 data_0217b8cc;
extern s32 data_0217b8ec;
extern s32 data_0217b8f0;
extern s32 data_0217b8bc;
extern s32 data_0217b894;
extern s32 data_0217b8f8;
extern s32 data_0217b8b0;
extern u16 *data_0217b8c0;
extern Vec3 data_0217b9c0;
extern Vec3 data_0217b90c;
extern Vec3 data_0217b918;
extern Vec3 data_0217b93c;
extern Vec3 data_0217b99c;
extern Vec3 data_0217b930;
extern Vec3 data_0217b948;
extern Vec3 data_0217b9b4;
extern Vec3 data_0217b924;
extern Vec3 data_0217bb28[];
extern s16 *data_0217b8a4;
extern s16 *data_0217b8a8;
extern s16 *data_0217b8a0;
extern s16 *data_0217b8e0;
extern s16 *data_0217b904;
extern s32 data_0217b8e8;
extern u32 data_0217bb04[];
extern Vec3 data_0217b96c;
extern s32 data_0217b8d0;
extern s32 data_0217b898;
extern s32 data_0217b89c;
extern s32 data_0217b8d8;
extern s32 data_0217b908;
extern Vec3 data_0217b954;
extern Vec3 data_0217b960;
extern Vec3 data_0217b978;
extern Vec3 data_0217b984;
extern Vec3 data_0217bb7c;
extern Vec3 data_0217bb34;
extern Vec3 data_0217bb40;
extern Vec3 *data_0217b9cc[4];
extern u16 data_0217b874;
extern u16 data_0217b878;
extern Vec3 data_0217b990;
extern Vec3 data_0217b9a8;
extern void *data_0217b5d0[16];
extern s32 data_0217b610;
extern Unk0217b614 data_0217b614;
extern u32 data_0217bbe8;
extern Vec3 data_0217bad0;
extern Vec3 data_0217badc;
extern Vec3 data_0217bac4;
extern Vec3 data_0217ba7c;
extern s32 data_0217b8d4;
extern s32 data_0217b8dc;
extern s32 data_0217b8f4;
extern u32 data_0217b8fc;
extern s32 data_0217bce8[];
extern s32 data_0217bc58;
extern s32 data_0217bca0[];
extern u16 data_0217bc54;
extern u16 data_0217bc50;
extern u16 data_0217bc7c[];
extern s32 data_0217bd3c;
extern s32 data_0217bd40;
extern s32 data_0217bd44;
extern volatile s32 data_0217bd34;
extern s32 data_0217bd48;
extern s32 data_0217bd4c;
extern s32 data_0217bd50;
extern s32 data_0217bd54;
extern s32 data_0217bd58;
extern u8 data_0217bd5c[];
extern u8 data_0217bd60[];
extern u8 data_0217bd64[];
extern u8 data_0217bd68[];
extern u8 data_0217bd80[][2];
extern u8 data_0217bdc0[][2];
extern u8 data_0217bd6c[];
extern u8 data_0217bdc1[];
extern u8 data_0217bd81[];
extern void *data_0217b224;
extern void *data_0217b1f8;
extern void *data_0217b228;
extern void *data_0217b22c;
extern void *data_0217b230;

extern Unk0209bc74 *data_usa_0217b0d8;
extern void *data_usa_0217b07c;
extern void *data_usa_0217b0a4;
extern void *data_0217b0c8;
extern void *data_0217b0bc;
extern void *data_0217b0c0;
extern void *data_0217b0cc;
extern void *data_0217b0d0;
extern void *data_0217b0d4;
extern void *data_0217b0dc;
extern void *data_0217b0e0;
extern void *data_0217b0e4;
extern void *data_0217b0e8;
extern void *data_usa_0217b154;
extern void *data_usa_0217b158;
extern void *data_usa_0217b15c;
extern void *data_usa_0217b160;
extern void *data_usa_0217b164;
extern void *data_usa_0217b168;
extern void *data_usa_0217b16c;
extern void *data_usa_0217b170;
extern void *data_usa_0217b174;
extern void *data_usa_0217b178;
extern void *data_usa_0217b17c;
extern void *data_usa_0217b180;
