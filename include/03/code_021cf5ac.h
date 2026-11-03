#pragma once

#include "types.h"

// Fourteen bytes moved as one value.
typedef struct Unk021cf5ac {
    /* 00 */ u16 mUnk_00[7];
} Unk021cf5ac;

// Object with the path pointer at 0x00 that func_ov003_021cf8ac takes.
typedef struct Unk021cf8ac {
    /* 00 */ const u8 *mUnk_00;
} Unk021cf8ac;

void func_ov003_021cf5ac(void);
u32 func_ov003_021cf64c(void);
void func_ov003_021cf69c(void);
void func_ov003_021cf72c(u32 a);
void func_ov003_021cf7b8(u32 a);
void func_ov003_021cf844(u32 a);
u32 func_ov003_021cf8ac(Unk021cf8ac *a);
void func_ov003_021cf93c(Unk021cf8ac *a, u16 b);
void func_ov003_021cf978(u32 a, u32 b);
