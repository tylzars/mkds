#pragma once

#include "types.h"

// Three 64-bit words: x, a and c of x = x * a + c. func_020d22c0 and func_020d22d0 return one; Unk0217aa00 has one
// at 0x1ee8 and RaceProgress three.
typedef struct Unk020f41c4_B {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk020f41c4_B;

typedef struct MapObject MapObject;

Unk020f41c4_B *func_020d22c0(void);
Unk020f41c4_B *func_020d22d0(void);
void func_020d22e0(void);
void func_020d233c(MapObject *a);
void func_020d2398(MapObject *a);
