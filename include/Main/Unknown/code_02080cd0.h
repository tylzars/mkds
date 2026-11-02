#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"

// Unk0208001c followed by a halfword at 0x1c and a byte at 0x1e.
typedef struct Unk02080d34 {
    /* 00 */ Unk0208001c mUnk_00;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u8 mUnk_1e;
} Unk02080d34;

void func_02080cd0(Unk0208001c *p, Unk02175620_bc *a);
void func_02080d34(Unk02080d34 *p, u16 a);
s32 func_02080dbc(Unk0208001c *p, Vec3 *a);
s32 func_02080e2c(Unk0208001c *p, Vec3 *a);
void func_02080e88(Unk0206c1ac *p, Unk0206bcb0 *q);
void func_02080e9c(Unk0206bcb0 *p);
void func_02080ee4(Unk0206bcb0 *p);
void func_02080f44(Unk0206bcb0 *p);
void func_02080fb8(Unk0206bcb0 *p);
void func_02081000(Unk0206bcb0 *p);
void func_02081060(Unk0206bcb0 *p);
