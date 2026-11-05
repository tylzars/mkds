#pragma once

#include "types.h"

// Object at Unk021a5a58_2c.mUnk_2c.
typedef struct Unk021a5a58_2c_2c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x4];
    /* 08 */ s16 mUnk_08[4];
} Unk021a5a58_2c_2c;

// Object at Unk021a5a58.mUnk_2c.
typedef struct Unk021a5a58_2c {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ BOOL mUnk_08;
    /* 0c */ u8 mUnk_0c[0x8];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x14];
    /* 2c */ Unk021a5a58_2c_2c *mUnk_2c;
    /* 30 */ u8 mUnk_30[0x24];
} Unk021a5a58_2c;

// Object that the per-entry update callbacks around func_ov001_021a5a58 work on.
typedef struct Unk021a5a58 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ Unk021a5a58_2c mUnk_2c;
    /* 80 */ struct Unk021ca41c_085c *mUnk_80;
    /* 84 */ s32 (*mUnk_84)(struct Unk021a5a58 *);
} Unk021a5a58;

void func_ov001_021a59cc(void *obj, s32 index);
void func_ov001_021a5a40(void *obj, s32 index);
BOOL func_ov001_021a5a58(Unk021a5a58 *entry);
void func_ov001_021a5ab0(void *obj, s32 index);
void func_ov001_021a5b4c(void *obj, s32 index);
BOOL func_ov001_021a5b70(Unk021a5a58 *entry);
void func_ov001_021a5c28(void *obj, s32 index);
BOOL func_ov001_021a5c40(Unk021a5a58 *entry);
void func_ov001_021a5d00(void *obj, s32 index);
BOOL func_ov001_021a5d18(Unk021a5a58 *entry);
void func_ov001_021a5df0(void *obj, s32 index);
BOOL func_ov001_021a5e60(Unk021a5a58 *entry);
BOOL func_ov001_021a5ef4(Unk021a5a58 *entry);
s32 func_ov001_021a5f70(s32 a, s32 x, s32 y, s32 d, s32 dx, s32 dy);
void func_ov001_021a6238(s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov001_021a6278(void);
s32 func_ov001_021a62ac(void);
BOOL func_ov001_021a62c4(s32 x, s32 y);
s32 func_ov001_021a6300(void);
s32 func_ov001_021a6314(void);
s32 func_ov001_021a6328(void);
s32 func_ov001_021a633c(void);
void func_ov001_021a6350(s32 x, s32 y);
s32 func_ov001_021a637c(void);
void func_ov001_021a6388(s32 value);
s32 func_ov001_021a639c(void);
void func_ov001_021a63a8(s32 value);
u8 func_ov001_021a63b4(void);
void func_ov001_021a63c0(u8 value);
void func_ov001_021a63cc(s32 value);
void func_ov001_021a63d8(void);
