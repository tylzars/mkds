#pragma once

#include "types.h"

typedef struct Unk021d70f8 {
    /* 00 */ u8 mUnk_00[0x16];
} Unk021d70f8;

typedef struct Unk021d7110 {
    /* 00 */ u8 mUnk_00[0x17];
} Unk021d7110;

extern Unk021d70f8 data_ov003_021d70f8;
extern Unk021d7110 data_ov003_021d7110;
extern u8 data_ov003_021d7128[];
extern u8 data_ov003_021d7140[];
extern u16 data_ov003_021d634c[];

void func_ov003_021c3cc4(void);
void func_ov003_021c3dd4(void);
