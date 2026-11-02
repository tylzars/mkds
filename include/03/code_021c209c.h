#pragma once

#include "types.h"

typedef struct Unk021da178 {
    /* 00 */ u32 mUnk_00 : 4;
} Unk021da178;

extern void (*data_ov003_021da17c)(void);

#include "03/unk_021da000.h"

extern Unk021da178 data_ov003_021da178;
extern s32 data_ov003_021da180[4];

void func_ov003_021c209c(void);
u32 func_ov003_021c20a8(u32 param_1);
u32 func_ov003_021c20c0(void);
u8 func_ov003_021c20d0(void);
void func_ov003_021c20dc(s32 *first, s32 *second);
void func_ov003_021c20f8(u32 arg0, u32 arg1);
void func_ov003_021c2104(s32 *first, s32 *second);
void func_ov003_021c2120(u32 param_1, u32 param_2);
void func_ov003_021c212c(void (*callback)(void));
void func_ov003_021c2138(void);
void func_ov003_021c2188(void);
void func_ov003_021c2398(void);
u32 func_ov003_021c2440(s32 a, u32 b);
s32 func_ov003_021c2494(void *a, s32 b, u32 c);
void func_ov003_021cdc4c(void);
void func_ov003_021d1654(void);
// Not decompiled yet.
void func_ov003_021d1b3c(void);
void func_ov003_021d1f98(void);
void func_ov003_021d2490(void);
void func_ov003_021d28e0(void);
void func_ov003_021d2d50(void);
void func_ov003_021d2dfc(void);
void func_ov003_021d2fdc(void);
void func_ov003_021d31b0(void);
void func_ov003_021d3408(void);
void func_ov003_021d35f4(void);
