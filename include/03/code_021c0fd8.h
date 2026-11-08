#pragma once

#include "types.h"

typedef struct Unk021bf920 Unk021bf920;
typedef struct Unk021d1770 Unk021d1770;
typedef struct TaskEntry TaskEntry;

// Object behind data_ov003_021da160.
typedef struct Unk021da160 {
    /* 00 */ void *mUnk_00[4];
    /* 10 */ Unk021bf920 *mUnk_10[10];
    /* 38 */ Unk021bf920 *mUnk_38[2];
    /* 40 */ Unk021d1770 *mUnk_40[2];
    /* 48 */ Unk021d1770 *mUnk_48[4];
    /* 58 */ struct Unk021d1770 *mUnk_58;
    /* 5c */ TaskEntry *mUnk_5c;
    /* 60 */ u8 mUnk_60;
    /* 61 */ s8 mUnk_61;
    /* 62 */ s8 mUnk_62;
    /* 63 */ s8 mUnk_63;
    /* 64 */ s8 mUnk_64;
    /* 65 */ u8 mUnk_65;
    /* 66 */ u8 mUnk_66;
    /* 67 */ u8 mUnk_67;
    /* 68 */ u8 mUnk_68;
    /* 69 */ u8 mUnk_69;
} Unk021da160;

// Five bytes moved as one value.
typedef struct Unk021c1364_05 {
    /* 0 */ u8 mUnk_00[5];
} Unk021c1364_05;

void func_ov003_021c0fd8(u32 a);
void func_ov003_021c105c(TaskEntry *param_1);
void func_ov003_021c10a8(TaskEntry *param_1);
void func_ov003_021c10f4(TaskEntry *param_1);
void func_ov003_021c1140(TaskEntry *param_1);
void func_ov003_021c118c(TaskEntry *param_1);
void func_ov003_021c11dc(u32 param_1);
void func_ov003_021c1268(void);
void func_ov003_021c12cc(int param_1, int param_2);
void func_ov003_021c1364(int param_1, u32 param_2);
void func_ov003_021c1510(void);
void func_ov003_021c1648(int a);
void func_ov003_021c1680(void);
void func_ov003_021c17d4(void);
void func_ov003_021c1908(void);
void func_ov003_021c1a44(void);
void func_ov003_021c1a60(TaskEntry *param_1);
void func_ov003_021c1abc(TaskEntry *param_1);
void func_ov003_021c1b24(TaskEntry *param_1);
void func_ov003_021c1b8c(TaskEntry *param_1);
void func_ov003_021c1bf4(TaskEntry *param_1);
u32 func_ov003_021c1c5c(void);
void func_ov003_021c1c70(u8 a);
void func_ov003_021c1c80(u8 a);
void func_ov003_021c1c90(u8 a);
u8 func_ov003_021c1ca0(void);
void func_ov003_021c1cb0(void);
void func_ov003_021c1cd8(void);
