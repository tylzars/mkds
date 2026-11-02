#pragma once

#include "types.h"

typedef struct Unk021a5a78 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021a5a78;

#include "00/code_021a4b98.h"

extern u8 data_ov000_021b07bc[];
extern u8 data_ov000_021b07c4[];

void func_ov000_021a574c(void);
void func_ov000_021a5794(void *a);
void func_ov000_021a57a8(void);
void func_ov000_021a57fc(u32 a);
void func_ov000_021a586c(s16 a, u32 b, void *c, u32 d, u32 e);
void func_ov000_021a58a4(u32 param_1, const void *param_2, u32 param_3, u32 param_4);
u16 func_ov000_021a58dc(u16 a);
void func_ov000_021a5930(void);
void func_ov000_021a5948(const void *a, const u8 *b, u32 c);
void func_ov000_021a5a78(Unk021a5a78 *a, void (*b)(Unk021a586c *));
Unk021b5f50 *func_ov000_021a5b30(void);
