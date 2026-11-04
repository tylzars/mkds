#pragma once

#include "types.h"

typedef struct Unk021052fc Unk021052fc;

// 0x40-byte object behind data_0215a680.
typedef struct Unk0215a680 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk0215a680;

extern const Unk0215a680 data_0215a680;

u32 func_02105504(void);
u32 func_021054d0(void);
Unk0215a680 *func_02105480(void);
void func_02105464(void *p, void *q);
u32 func_0210543c(void);
void func_021053e4(Unk021052fc *p);
