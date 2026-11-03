#pragma once

#include "types.h"

typedef struct Unk021b3bdc {
    /* 00 */ s8 mUnk_00[0x2c];
} Unk021b3bdc;

extern s32 data_ov000_021b3b2c;
extern u32 data_ov000_021b3b34;
extern u8 data_ov000_021b3b38[];
extern u8 data_ov000_021b3b40[];
extern const Unk021b3bdc data_ov000_021b3bdc;
extern const u8 data_ov000_021b3e0c[];
extern char data_ov000_021b4f84[];
extern u8 data_ov000_021b4e84[];
extern u32 data_ov000_021b4e4c;

void func_ov000_021971ec(s8 *a, s32 b);
s32 func_ov000_02197220(s8 *a, s32 b);
s32 func_ov000_021972b4(void);
s32 func_ov000_0219735c(const s8 *a, u32 b);
