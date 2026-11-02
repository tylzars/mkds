#pragma once

#include "types.h"

typedef struct Unk021d1ffc {
    /* 00 */ u8 mUnk_00[0x34];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
} Unk021d1ffc;

void func_ov003_021d214c(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4,
                         unsigned int p5);

#include "Main/Unknown/types_02180728.h"
#include "code_02023374.h"

// 0x38-byte object; func_ov003_021d2288 sets it up.
typedef struct Unk021d2188 {
    /* 00 */ Unk02023374 mUnk_00;
    /* 20 */ Unk02180728 mUnk_20;
    /* 30 */ u8 *mUnk_30;
    /* 34 */ u32 mUnk_34;
} Unk021d2188;

#include "03/code_021d1d88.h"

typedef struct Unk021d1fd0 {
    /* 000 */ u8 mUnk_000[0x718];
    /* 718 */ Unk021d2188 mUnk_718[2];
    /* 788 */ Unk021d1d88 *mUnk_788;
    /* 78c */ u8 mUnk_78c[8];
    /* 794 */ u8 mUnk_794;
    /* 795 */ u8 mUnk_795;
} Unk021d1fd0;

void func_ov003_021d2070(Unk021d2188 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6,
                         u32 param_7, void *param_8);

#include "03/code_021d2fa0.h"

typedef struct Unk021d23b0 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct Unk021d23b0 *a, u32 b);
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ struct Unk021d23b0 *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ Unk021d309c *mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
} Unk021d23b0;

typedef struct Unk021d2490 {
    /* 000 */ Unk02022aa8 mUnk_000[2];
    /* 018 */ u8 mUnk_018[0x770];
    /* 788 */ Unk021d1d88 *mUnk_788;
    /* 78c */ Unk02021f9c *mUnk_78c[2];
    /* 794 */ u8 mUnk_794[4];
} Unk021d2490;

#include "03/code_021d1770.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02024000.h"
#include "code_02021f9c.h"
#include "code_02022aa8.h"

void func_ov003_021d1fd0(void *object);
void func_ov003_021d1ffc(Unk021d1ffc *param_1, s32 param_2, s32 param_3, Unk021d1770 *param_4, s32 param_5);
void func_ov003_021d2060(Unk021d2188 *object, u32 value);
void func_ov003_021d2094(void *param_1, s32 param_2, u32 param_3, u32 param_4, s32 param_5, u16 *param_6, s32 param_7);
void func_ov003_021d211c(void *param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, int param_6);
void func_ov003_021d2168(u32 index);
void func_ov003_021d2188(Unk021d2188 *param_1);
void func_ov003_021d21f8(u32 param_1, u8 *param_2);
Unk021d2188 *func_ov003_021d2288(u32 param_1, u32 param_2);
void func_ov003_021d2388(int param_1);
Unk021d23b0 *func_ov003_021d23b0(u32 a, u16 b, u16 c, s32 d, u32 *e, s32 f);
void func_ov003_021d244c(void);
void func_ov003_021d2490(void);
