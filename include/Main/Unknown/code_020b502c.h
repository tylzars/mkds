#pragma once

#include "types.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_0217b000.h"

// Two words (the elements at member 0xc of Unk0217b498).
typedef Unk0217b498_0c UnkPair020b502c;

// Object returned by func_020b57e4.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
} Unk020b57e4;

// One entry of the table at CourseMap::mUnk_08.
typedef struct {
    /* 00 */ u8 mUnk_00[1];
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk02175620_08;

// Object behind CourseMap::mUnk_018.
typedef struct {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u16 mUnk_18[4];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk02175620_18;

// 0x48-byte entries of the table at CourseMap::mUnk_74 (func_020423fc returns one).
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ Vec3 mUnk_30;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ s16 mUnk_3e;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mUnk_42;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mUnk_44;
    /* 45 */ u8 mUnk_45[3];
} Unk02175620_74;

// 0x18-byte entries of the table at CourseMap::mUnk_84 (func_020a0f0c returns one).
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
} Unk02175620_84;

// 0x30-byte entries of the table at CourseMap::mUnk_bc (func_02080908 searches it).
typedef struct Unk02175620_bc {
    /* 00 */ struct Unk02175620_bc *mUnk_00[3];
    /* 0c */ struct Unk02175620_bc *mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ Vec3 *mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s16 *mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
} Unk02175620_bc;

struct Unk020fa294;

// 0x1c-byte entries of the table at CourseMap::mUnk_34: two vectors.
typedef struct Unk02175620_34 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} Unk02175620_34;

// 0x20-byte entries of the table at CourseMap::mUnk_24.
typedef struct Unk02175620_24 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ u8 mUnk_1e[2];
} Unk02175620_24;

// The same two words as UnkPair020b502c.
typedef Unk0217b498_0c Unk02040d24;

// 0x24-byte entries of the table at CourseMap::mUnk_44.
typedef struct Unk02175620_44 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ Unk02040d24 mUnk_10;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s16 mUnk_20;
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
} Unk02175620_44;

// 0x0c-byte entries of the table at CourseMap::mUnk_4c.
typedef struct Unk02175620_4c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[3];
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
} Unk02175620_4c;

// 0x14-byte entries of the table at CourseMap::mUnk_54.
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11[3];
} Unk02175620_54;

// 0x10-byte entries of the same table (used while CourseMap::mUnk_10c is below 0x21).
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
} Unk02175620_54_10;

// 0x4c-byte entries of the table at CourseMap::mUnk_7c.
typedef Unk020748b8_218 Unk02175620_7c;

// 0x14-byte entries of the table at CourseMap::mUnk_8c.
typedef struct {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u8 mUnk_0c[8];
} Unk02175620_8c;

// 8-byte entries of the table at CourseMap::mUnk_94.
typedef struct {
    /* 00 */ Unk02175620_08 *mUnk_00;
    /* 04 */ void *mUnk_04;
} Unk02175620_94;

// 0x28-byte nodes of the table at CourseMap::mUnk_a0: two lists of node pointers.
typedef struct Unk02175620_a0 {
    /* 00 */ struct Unk02175620_a0 *mUnk_00[3];
    /* 0c */ struct Unk02175620_a0 *mUnk_0c[3];
    /* 18 */ Unk02175620_84 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 *mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk02175620_a0;

// Node of the lists at CourseMap::mUnk_d8: an entry of the table at mUnk_74 and the next node.
typedef struct Unk02175620_d8 {
    /* 00 */ Unk02175620_74 *mUnk_00;
    /* 04 */ struct Unk02175620_d8 *mUnk_04;
} Unk02175620_d8;

// Object behind the word at 0x3c of the object behind gCourseMap: two vectors and the halfword at 0x1a.
typedef struct Unk02175620_3c {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[2];
    /* 1a */ s16 mUnk_1a;
} Unk02175620_3c;

// Object behind gCourseMap.
typedef struct {
    /* 00 */ struct Unk020fa294 *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ Unk02175620_08 *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 00e */ u8 mUnk_00e[0x2];
    /* 010 */ s32 mUnk_010;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ Unk02175620_18 *mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ u16 mUnk_020;
    /* 022 */ u8 mUnk_022[0x2];
    /* 024 */ Unk02175620_24 *mUnk_024;
    /* 028 */ u16 mUnk_028;
    /* 02a */ u8 mUnk_02a[0x2];
    /* 2c */ Unk020b57e4 *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ Unk02175620_34 *mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[0x2];
    /* 3c */ Unk02175620_3c *mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ Unk02175620_44 *mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a[0x2];
    /* 4c */ Unk02175620_4c *mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ Unk02175620_54 *mUnk_54;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x2];
    /* 5c */ Unk02175620_4c *mUnk_5c;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u8 mUnk_62[0x2];
    /* 64 */ Unk02175620_84 *mUnk_64;
    /* 68 */ u16 mUnk_68;
    /* 6a */ u8 mUnk_6a[0x2];
    /* 6c */ Unk02175620_4c *mUnk_6c;
    /* 70 */ u16 mUnk_70;
    /* 72 */ u8 mUnk_72[0x2];
    /* 74 */ Unk02175620_74 *mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u8 mUnk_7a[0x2];
    /* 7c */ Unk02175620_7c *mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[0x2];
    /* 84 */ Unk02175620_84 *mUnk_84;
    /* 88 */ u16 mUnk_88;
    /* 8a */ u8 mUnk_8a[2];
    /* 8c */ Unk02175620_8c *mUnk_8c;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u8 mUnk_92[2];
    /* 94 */ Unk02175620_94 *mUnk_94;
    /* 98 */ u16 mUnk_98;
    /* 9a */ u16 mUnk_9a;
    /* 9c */ u16 mUnk_9c;
    /* 9e */ u8 mUnk_9e[2];
    /* a0 */ Unk02175620_a0 *mUnk_a0;
    /* a4 */ Unk02175620_bc *mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ struct Unk020f371c *mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ Unk02175620_bc *mUnk_b8;
    /* bc */ Unk02175620_bc *mUnk_bc;
    /* c0 */ Unk02175620_bc *mUnk_c0;
    /* c4 */ Unk02175620_7c *mUnk_c4;
    /* c8 */ Unk02175620_7c *mUnk_c8;
    /* cc */ Unk02175620_7c *mUnk_cc;
    /* d0 */ Unk02175620_7c *mUnk_d0;
    /* d4 */ Unk02175620_7c *mUnk_d4;
    /* d8 */ struct Unk02175620_d8 *mUnk_d8[8];
    /* f8 */ u16 *mUnk_f8;
    /* fc */ u16 *mUnk_fc;
    /* 100 */ u16 mUnk_100;
    /* 102 */ u16 mUnk_102;
    /* 104 */ u32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u8 mUnk_10e;
    /* 10f */ u8 mUnk_10f;
} CourseMap;

// Eight words.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk020b503c;

// Object behind data_0217b3c0.
typedef struct {
    /* 00 */ UnkPair020b502c mUnk_00;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ UnkPair020b502c mUnk_10;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ UnkPair020b502c mUnk_2c;
    /* 34 */ UnkPair020b502c mUnk_34;
    /* 3c */ s64 mUnk_3c;
    /* 44 */ s64 mUnk_44;
    /* 4c */ UnkPair020b502c mUnk_4c;
    /* 54 */ UnkPair020b502c mUnk_54;
    /* 5c */ s64 mUnk_5c;
    /* 64 */ s64 mUnk_64;
    /* 6c */ UnkPair020b502c mUnk_6c;
    /* 74 */ UnkPair020b502c mUnk_74;
    /* 7c */ s64 mUnk_7c;
    /* 84 */ s64 mUnk_84;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ Vec3 mUnk_90;
} Unk0217b3c0;

extern CourseMap *gCourseMap;

#include "Main/Unknown/unk_02175628.h"

extern Unk0217b3c0 *data_0217b3c0;

extern u16 func_020435bc(void);
extern void GetKartPrevPos(Vec3 *dst, s32 idx);
extern void func_0207a91c(Vec3 *dst, u8 idx);
extern void func_0207a948(Vec3 *dst, s32 idx);
s32 func_020b502c(s32 a, s32 b);
void func_020b503c(Unk020b503c *p, s32 scale);
s32 func_020b523c(void);
s32 func_020b5250(s32 x);
s32 func_020b5258(s32 x);
s32 func_020b5270(s32 x);
void func_020b5290(void);
u16 func_020b5628(s32 idx, s32 mask);
u16 func_020b5644(Unk02175628 *p, s32 mask);
void func_020b5658(Unk020b503c *out);
s32 func_020b57b4(s32 a, s64 k);
Unk020b57e4 *func_020b57e4(void);
void func_020b57f8(Unk020b503c *out);
void func_020b58f8(Unk020b503c *out);
BOOL func_020b5ae8(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2);
void func_020b5dcc(s32 idx, UnkPair020b502c *out, s32);
BOOL func_020b5f68(const UnkPair020b502c *p);
void func_020b5fe4(const Vec3 *pos, UnkPair020b502c *out);
void func_020b6078(s32 idx, UnkPair020b502c *out);
u16 func_020b6338(s32 idx);
u16 func_020b6368(void);
s32 func_020b6430(void);
s32 func_020b64e8(void);
u32 func_020b65dc(void);
