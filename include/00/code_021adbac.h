#pragma once

#include "types.h"

typedef struct Unk021a998c Unk021a998c;

extern u32 (*data_ov000_021b6388)(void);
extern u8 data_ov000_021b6364;
extern u16 data_ov000_021b6370;

void func_ov000_021b04d4(void);
void func_ov000_021b04f8(u32 a);
void func_ov000_021afc5c(u32 a);

s32 func_ov000_021adbac(void);
s32 func_ov000_021adbf4(const u8 *a, s32 b);
s32 func_ov000_021adc64(const u8 *a, s32 b, const u8 *c, s32 d);
s32 func_ov000_021adcec(const u8 *a, u32 b, const u8 *c, s32 d, void *e);
void func_ov000_021ade40(const u8 *a, s32 b, const u8 *c, s32 d, Unk021a998c *e, s32 f);
s32 func_ov000_021ade6c(const u8 *a, s32 b, Unk021a998c *c, s32 d);
void func_ov000_021adf00(u32 a);
void func_ov000_021adf30(u32 a, Unk021a998c *b);
u8 *func_ov000_021adf78(u32 *a);
u8 *func_ov000_021adfc8(u32 *a, Unk021a998c *b);
