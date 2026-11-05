#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of func_021052fc (func_0210543c allocates them): the shared MapObject part, then counters that run and
// wrap and whose three fixed-point words follow the vector at mUnk_fc.
typedef struct Unk021052fc {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u8 mUnk_a6[0xa];
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u8 mUnk_b2[0x4a];
    /* fc */ Vec3 *mUnk_fc;
    /* 100 */ void *mUnk_100;
    /* 104 */ void *mUnk_104;
} Unk021052fc;

void func_02105338(Unk021052fc *p, s32 a, Vec3 *v);
void func_021052fc(Unk021052fc *p);
