#pragma once

#include "types.h"

// 0x18-byte object whose first halfword selects what func_0205081c does with the rest.
typedef struct Unk0205081c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[0xb];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} Unk0205081c;

typedef struct Unk02050320 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
} Unk02050320;

typedef struct Unk020503cc {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[4];
    /* 06 */ u8 mUnk_06[4];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[7];
} Unk020503cc;

typedef struct Unk020504a4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x14];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} Unk020504a4;

#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02165000.h" // Unk021652a0
#include "code_02142eac.h" // Unk021425e8

u32 func_02050300(void);
s32 func_02050320(s32 a, u16 b, s32 c);
s32 func_020503cc(s32 a, u16 b);
s32 func_020504a4(s32 a, u16 b);
s32 func_020505a8(s32 a, u16 b);
s32 func_02050650(void *a, s32 b, u16 c, void *d, Unk021652a0 *e);
void func_02050764(Unk021425e8 *a);
void func_0205081c(u32 a, Unk0205081c *b);
void func_02050b88(u32 a);
void func_02050d80(u32 a, u8 *b, Unk0217aa00_45c *c);
void func_02050e60(s32 a);
void func_02050e80(Unk021425e8 *a);
void func_02050ec0(void);
void func_0205108c(s32 a);
s32 func_020510ac(void);
s32 func_020510c8(void);
s32 func_020510e4(void);
void func_02051108(Unk021425e8 *a);
void func_02051230(void);
void func_02051364(Unk021425e8 *a);
void func_020513ac(void);
void func_02051400(Unk021425e8 *a);
void func_0205146c(void);
void func_020514c0(void);
void func_02051528(Unk021425e8 *a);
void func_020515b0(u32 a);
