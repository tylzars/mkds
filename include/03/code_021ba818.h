#pragma once

#include "types.h"
#include "03/code_021b94b8.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"

typedef s32 Unk021ba818Func();

typedef struct Unk021d8b88 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk021d8b88;

extern u8 *data_ov003_021d8b80;
extern u32 data_ov003_021d8b84;
extern Unk021d8b88 *data_ov003_021d8b88;
extern u32 data_ov003_021d8b8c;
extern const u8 *data_ov003_021d8b90;
extern const u8 *data_ov003_021d8b94;
extern s32 data_ov003_021d8b98;
extern Unk021ba818Func *data_ov003_021d8b9c;
extern Unk021ba778Src *data_ov003_021d8ba0;
extern void *data_ov003_021d8ba4;
extern u8 data_ov003_021d8ba8[6];
extern u8 data_ov003_021d8bb0[0x20];

BOOL func_ov003_021ba818(Unk021ba818Func *a, u8 *b, s32 c);
BOOL func_ov003_021ba910(Unk021ba778Src *a, Unk021d8a4c *b, u32 c);
BOOL func_ov003_021ba9c0(void);
BOOL func_ov003_021baa28(void);
BOOL func_ov003_021baa68(void);
BOOL func_ov003_021baaac(const u8 *a, const u8 *b, s32 c, u32 d);
s32 func_ov003_021babc0(Unk021ba778Src *a, s32 b);
BOOL func_ov003_021bac0c(void);
void func_ov003_021bac90(s16 *a);
