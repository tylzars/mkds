#pragma once

#include "types.h"

typedef struct Unk021bf920 Unk021bf920;
typedef struct Unk021d1770 Unk021d1770;
typedef struct Unk021d34e0 Unk021d34e0;

// Object behind data_ov003_021da160.
typedef struct Unk021da160 {
    /* 00 */ void *mUnk_00[4];
    /* 10 */ Unk021bf920 *mUnk_10[10];
    /* 38 */ Unk021bf920 *mUnk_38[2];
    /* 40 */ Unk021d1770 *mUnk_40[2];
    /* 48 */ Unk021d1770 *mUnk_48[4];
    /* 58 */ void *mUnk_58;
    /* 5c */ void *mUnk_5c;
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

void func_ov003_021c105c(Unk021d34e0 *param_1);
void func_ov003_021c10a8(Unk021d34e0 *param_1);
void func_ov003_021c10f4(Unk021d34e0 *param_1);
void func_ov003_021c1140(Unk021d34e0 *param_1);
void func_ov003_021c118c(Unk021d34e0 *param_1);
void func_ov003_021c11dc(u32 param_1);
void func_ov003_021c1268(void);
void func_ov003_021c12cc(int param_1, int param_2);
void func_ov003_021c1364(int param_1, u32 param_2);
void func_ov003_021c1510(void);
