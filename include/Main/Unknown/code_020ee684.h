#pragma once

#include "types.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"

// Element of the 0x210-byte array behind data_027e00c8: a Unk020f40dc at 0x030, a Unk020eda5c at 0x058, a
// Unk020f371c_Ref at 0x1f0, the Kart at 0x1fc and words from 0x200 to 0x20c.
typedef struct Unk020ee684 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ struct Unk020ee684 *mUnk_018;
    /* 01c */ BOOL mUnk_01c;
    /* 020 */ BOOL mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ u32 mUnk_028;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ Unk020f40dc mUnk_030;
    /* 058 */ Unk020eda5c mUnk_058;
    /* 1ec */ u16 mUnk_1ec;
    /* 1ee */ u8 mUnk_1ee[2];
    /* 1f0 */ Unk020f371c_Ref mUnk_1f0;
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ Kart *mUnk_1fc;
    /* 200 */ s32 mUnk_200;
    /* 204 */ BOOL mUnk_204;
    /* 208 */ BOOL mUnk_208;
    /* 20c */ BOOL mUnk_20c;
} Unk020ee684;

// Element of the table behind data_0217562a.
typedef struct Unk0217562a {
    /* 00 */ u16 mBits;
    /* 02 */ u8 mUnk_02[0x5a];
} Unk0217562a;

extern Unk0217562a data_0217562a[];

// Element at 0x7c of the object behind data_021759c0.
typedef struct Unk021759c0_7c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x2c];
} Unk021759c0_7c;

// The object behind data_021759c0 from its first byte: the elements at 0x7c.
typedef struct Unk021759c0_000 {
    /* 000 */ u8 mUnk_000[0x7c];
    /* 07c */ Unk021759c0_7c mUnk_07c[17];
} Unk021759c0_000;

// The object behind gCourseMap from its first byte: the halfword at 0x60
// and the word at 0xb0.
typedef struct Unk02175620_060 {
    /* 000 */ u8 mUnk_000[0x60];
    /* 060 */ u16 mUnk_060;
    /* 062 */ u8 mUnk_062[0x4e];
    /* 0b0 */ void *mUnk_0b0;
} Unk02175620_060;

void func_020ee684(Unk020eda5c *a, Unk020ee684 *b);
void func_020ee6a8(Unk020eda5c *a);
void func_020ee6e8(Unk020eda5c *a, s32 i, Unk020f41c4_A *v);
void func_020ee748(Unk020eda5c *a);
void func_020ee9b0(Unk020eda5c *a);
void func_020eea6c(Unk020eda5c *a);
void func_020eec48(Unk020eda5c *a, s32 i, Unk020f41c4_A *v);
void func_020eecdc(Unk020eda5c *a);
void func_020ef1cc(Unk020eda5c *p);
void func_020ef340(Unk020eda5c *a, Unk020f41c4_A *b, Unk020f41c4_A *c);
void func_020ef350(Unk020eda5c *a);
void func_020ef4a0(Unk020eda5c *a);
void func_020ef65c(Unk020eda5c *a, Vec3 *v, Vec3 *w);
void func_020ef8c4(Unk020eda5c *a);
void func_020ef9a8(Unk020eda5c *a);
void func_020efa48(Unk020eda5c *a, Unk020f41c4_A *v);
void func_020efa60(Unk020eda5c *a, s32 f);
void func_020efb84(Unk020eda5c *p, Unk020f41c4_A *v);
void func_020efbd4(Unk020ee684 *a, s32 n);
void func_020efc74(Unk020ee684 *p, s32 a);
void func_020efd1c(Unk020ee684 *p, Unk020f41c4_A *a);
BOOL func_020efd84(Unk020ee684 *p, s32 a);
void func_020efea4(Unk020ee684 *p);
void func_020eff40(Unk020ee684 *p);
void func_020f0044(Unk020ee684 *p);
void func_020f00f0(Unk020ee684 *p);
BOOL func_020f0154(Unk020ee684 *p);
void func_020f02c0(Unk027e00cc *q, s32 a, s32 *b);
BOOL func_020f03bc(Unk027e00cc *tab);
void func_020f03f8(Unk027e00cc *a);
void func_020f0684(Unk020f41c4_A **p, s32 i, s32 n, s32 step);
void func_020f0758(Unk027e00cc *a, s32 m, s32 b, u8 *c, s32 d);
s32 func_020f0898(Unk027e00cc *a, u8 *b);
s32 func_020f0950(Unk027e00cc *a, s32 b, s32 c);
void func_020f0b00(Unk027e00cc *tab, s32 a, void *b, s32 c);
void func_020f0d04(Unk020f41c4_A *p);
void func_020f0df8(Unk027e00cc *tab, void *a);
void func_020f0e2c(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f0ea0(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f0f70(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f1048(Unk027e00cc *tab, s32 count, Unk020f41c4_A **out, u16 kind, Vec3 *v);
