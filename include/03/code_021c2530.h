#pragma once

#include "types.h"
#include "03/code_021d1d88.h"

typedef struct Unk021da190 {
    /* 00 */ u8 pad_00[0x60];
    /* 60 */ Unk021d1d88 *mUnk_60;
} Unk021da190;

#include "03/code_021c250c.h"

extern Unk021da190 *data_ov003_021da190;

int func_ov003_021c2530(int *param_1, u32 param_2);
void func_ov003_021c2544(int param_1);
Unk021c250c *func_ov003_021c2564(void *a);
void func_ov003_021c25a4(void);
void func_ov003_021c25b4(void);
