#pragma once

#include "types.h"

typedef struct Unk021af1e4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021af1e4;

typedef struct Unk021af3e8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08[3];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12[3];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} Unk021af3e8;

#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"

extern u32 data_ov000_021b4c24;
extern u8 data_ov000_021b6368;
extern u16 data_ov000_021b63d0[3];
extern Unk0200db5c data_ov000_021b661c;

void func_ov000_021aefa8(void *object, u16 value);
void func_ov000_021aefb4(void *object, u16 value);
void func_ov000_021aefc0(Unk021a998c *param_1, u32 param_2, u16 param_3);
u32 func_ov000_021af010(u32 param_1);
void func_ov000_021af030(const Unk021ae87c *param_1, Unk021a998c *param_2);
Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2);
u32 func_ov000_021af0dc(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2, const Unk021a998c *param_3);
Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2);
void func_ov000_021af1e4(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
u32 func_ov000_021af284(int param_1, int param_2);
void func_ov000_021af2a0(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
void func_ov000_021af348(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
void func_ov000_021af3e8(Unk021af3e8 *param_1, u32 param_2);
void func_ov000_021af4d4(Unk021af3e8 *param_1);
