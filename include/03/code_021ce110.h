#pragma once

#include "types.h"
#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"

// Entry of the table at offset 0x1300 of the object at data_ov003_021da280.
typedef struct Unk021ce4d4_1300 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06;
} Unk021ce4d4_1300;

// Object at data_ov003_021da280, as far as func_ov003_021ce4d4 uses it.
typedef struct Unk021ce4d4 {
    /* 0000 */ u8 mUnk_0000[0x1300];
    /* 1300 */ Unk021ce4d4_1300 mUnk_1300[0x10];
    /* 1370 */ void (*mUnk_1370)(s32);
    /* 1374 */ u8 mUnk_1374[0x800];
    /* 1b74 */ u32 mUnk_1b74[2];
    /* 1b7c */ u32 mUnk_1b7c;
    /* 1b80 */ u8 mUnk_1b80[2];
    /* 1b82 */ u8 mUnk_1b82;
} Unk021ce4d4;

extern u8 data_ov003_021d66bc[];
extern u8 data_ov003_021d6688[][5];
extern u8 data_ov003_021d6698[][5];

void func_ov003_021ce110(Unk021d34e0 *a);
void func_ov003_021ce190(Unk021d34e0 *a);
void func_ov003_021ce230(Unk021d34e0 *a);
void func_ov003_021ce2d0(Unk021d34e0 *a);
void func_ov003_021ce370(Unk021d34e0 *a);
// Declared here until the code that defines it is decompiled.
void func_ov003_021d1890(Unk021d1770 *param_1, s32 param_2, u32 param_3, u32 param_4);

void func_ov003_021ce408(u32 a);
void func_ov003_021ce4d4(u32 a);
