#pragma once

#include "types.h"

typedef struct Unk020e0144_00_0 Unk020e0144_00_0;

// Second argument of func_020d7e44: a byte at 0x01 and a halfword at 0x02.
typedef struct Unk020d7e44 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mEntryCount;
} Unk020d7e44;

#include "Main/Unknown/unk_0217b000.h"

void func_020d7db4(Unk020e0144 *a, u16 b, int c);
void func_020d7df8(void);
void func_020d7e44(u32 a, int m);
void func_020d80e4(Unk020e0144_00_0 *p, s32 a, s32 b, Vec3 *c, Vec3 *d, Vec3 *e, Vec3 *f);
void func_020d8460(void *m, Vec3 *v);
