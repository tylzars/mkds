#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Unk021da104_04 Unk021da104_04;
typedef struct Unk021d2188 Unk021d2188;
typedef struct Unk021d299c Unk021d299c;

// Object behind data_ov003_021da1f4 (0x5c bytes).
typedef struct Unk021c5c68State {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021d2188 *mUnk_0c;
    /* 10 */ Unk021da104_04 *mUnk_10[5];
    /* 24 */ Unk021da104_04 *mUnk_24[5];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42[3];
    /* 48 */ u16 mUnk_48[4];
    /* 50 */ s8 mUnk_50;
    /* 51 */ u8 mUnk_51;
    /* 52 */ u8 mUnk_52;
    /* 53 */ u8 mUnk_53;
    /* 54 */ u8 mUnk_54;
    /* 55 */ u8 mUnk_55;
    /* 56 */ u8 mUnk_56;
    /* 57 */ u8 mUnk_57;
    /* 58 */ u8 mUnk_58;
    /* 59 */ u8 mUnk_59;
} Unk021c5c68State;

extern Unk021d299c data_ov003_021d6390[];

void func_ov003_021c5c68(void);
void func_ov003_021c5cdc(void);
void func_ov003_021c5e54(void);
void func_ov003_021c5ea4(void);
void func_ov003_021c5ec4(void);
void func_ov003_021c5f9c(void);
void func_ov003_021c6184(void);
void func_ov003_021c6358(void);
void func_ov003_021c6370(void);
void func_ov003_021c6394(void);
void func_ov003_021c63c4(void);
void func_ov003_021c6e38(void);
void func_ov003_021ca8e8(void);
void func_ov003_021cce78(void);
