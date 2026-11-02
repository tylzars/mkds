#pragma once

#include "types.h"

// Object passed to func_ov003_021d34e0, which stores its second argument at 0x08.
typedef struct Unk021d34e0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ UnkFunc *mUnk_08;
} Unk021d34e0;

typedef struct Unk021d34e4 {
    /* 00 */ struct Unk021d34e4 *mUnk_00;
    /* 04 */ struct Unk021d34e4 *mUnk_04;
    /* 08 */ void (*mUnk_08)(struct Unk021d34e4 *a, u32 b);
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u8 mUnk_12[2];
} Unk021d34e4;

#include "03/code_021d1d88.h"

typedef struct Unk021d34c8 {
    /* 00 */ Unk021d1d88 *mUnk_00;
    /* 04 */ struct Unk021d1d88 *mResource;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021d34e4 mUnk_0c;
    /* 20 */ Unk021d34e4 mUnk_20;
    /* 34 */ s32 mUnk_34;
    /* 38 */ Unk021d34e4 *mUnk_38;
} Unk021d34c8;

#include "03/code_021d2e68.h"

void func_ov003_021d3488(int param_1, int param_2);
void func_ov003_021d34c0(u32 arg0, u32 arg1);
void func_ov003_021d34c8(u32 index, u32 value);
void func_ov003_021d34e0(Unk021d34e0 *param_1, UnkFunc *param_2);
Unk021d34e4 *func_ov003_021d34e4(u32 a, void (*b)(Unk021d34e4 *a, u32 b), u32 c, u32 d, u8 e);
unsigned int func_ov003_021d3544(unsigned int p0, void *p1, void *p2, unsigned int p3);
void func_ov003_021d3558(int a);
void func_ov003_021d35c0(void);
void func_ov003_021d35f4(void);
