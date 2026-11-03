#pragma once

#include "types.h"

typedef struct Unk021d1d88 Unk021d1d88;
typedef struct Unk021c250c Unk021c250c;

typedef struct Unk021da190 {
    /* 00 */ u8 pad_00[0x60];
    /* 60 */ Unk021d1d88 *mUnk_60;
} Unk021da190;

extern Unk021da190 *data_ov003_021da190;

int func_ov003_021c2530(int *a, u32 b);
void func_ov003_021c2544(int a);
Unk021c250c *func_ov003_021c2564(void *a);
void func_ov003_021c25a4(void);
void func_ov003_021c25b4(void);
