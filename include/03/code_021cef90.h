#pragma once

#include "types.h"

typedef struct Unk021d1770 Unk021d1770;

// K&R on purpose: code_021cef90.c calls func_ov003_021d2658 with a u8 array, and the typed header of this function
// declares it with u16 *.
void func_ov003_021d254c();

void func_ov003_021cef90(void);
void func_ov003_021cefc0(u32 a, s32 b, s32 c, u32 d, u32 e);
u16 func_ov003_021cf1e8(u8 *a);
