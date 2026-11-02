#pragma once

#include "types.h"

// Object behind data_02174e24, 0x80c bytes (func_0202a658 allocates it).
typedef struct Unk0202a658 {
    /* 000 */ u8 mUnk_000[0x404];
    /* 404 */ u8 mUnk_404[0x404];
    /* 808 */ s32 mUnk_808;
} Unk0202a658;

#include "Main/Unknown/unk_02174000.h"

void func_0202a5a0(void);
void func_0202a5d8(void);
void func_0202a604(u32 a);
void func_0202a658(void *a);
