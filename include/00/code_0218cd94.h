#pragma once

#include "types.h"

// Four bytes copied byte by byte (func_ov000_0218ce14_inline in code_0218cdd8.c); the target may be unaligned.
typedef struct Unk0218cd94 {
    /* 0 */ u8 mUnk_00[4];
} Unk0218cd94;

void func_ov000_0218cd94(u8 **a, u32 b, s32 *c);
