#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, Unk020e6fd4
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_020e516c.h" // Unk020e516c

// Object of func_02095544: after the shared part, a counter at 0xa0, a vector at 0xa4 and a state at 0xb0.
typedef struct Unk02095544 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ Vec3 mUnk_a4;
    /* b0 */ u32 mUnk_b0;
} Unk02095544;

// Object of func_02095a3c: after the shared part, three counters from 0xa0, a halfword at 0xac, a value at 0xb0, an
// Unk020e0144 at 0xb4, a state at 0xd8 and an Unk020e516c at 0xdc.
typedef struct Unk02095a3c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ u16 mUnk_ac;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ Unk020e0144 mUnk_b4;
    /* d8 */ u32 mUnk_d8;
    /* dc */ Unk020e516c mUnk_dc;
} Unk02095a3c;

void func_02095504(void);
void func_02095524(void);
void func_02095544(void *a, Unk02095544 *p);
void func_020957ec(Unk020e6fd4 *p);
void func_02095848(void *a, Unk02095544 *p);
void CreateBakubakuAndBakuShadow(void *a);
void func_020959bc(void);
void func_020959dc(void);
void func_020959fc(void);
void func_02095a3c(void *a, Unk02095a3c *p);
void func_02095d1c(Unk020e6fd4 *p);
void func_02095db8(void *a, Unk02095a3c *p, u32 c, u32 d);
void CreateMoveTree(void *a);
u8 func_02095efc(Unk02095a3c *a, Unk0206bcb0 *b, u8 *c, u8 *d);
