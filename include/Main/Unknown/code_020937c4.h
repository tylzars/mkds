#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, Unk020e6fd4
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

// Object of func_020937c4: after the shared part, a counter at 0xa0 and a word at 0xa4.
typedef struct Unk020937c4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
} Unk020937c4;

// Object of func_02093910: after the shared part, a counter at 0xa0, a state at 0xa4 and an object at 0xa8.
typedef struct Unk02093910 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ Unk0210b7ec *mUnk_a8;
} Unk02093910;

// Object of func_02093cf4: after the shared part, a counter at 0xa0, a state at 0xa8 and an Unk020e0144 at 0xac.
typedef struct Unk02093cf4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u8 mUnk_a4[4];
    /* a8 */ s32 mUnk_a8;
    /* ac */ Unk020e0144 mUnk_ac;
} Unk02093cf4;

void func_020937c4(Vec3 *a, Vec3 *b, u16 c);
void func_02093884(void);
void func_020938a0(void);
void func_020938c0(void);
void func_02093910(void *a, Unk02093910 *p);
void func_02093a50(void *a, Unk02093910 *p);
void CreateNsKiller2AndNsKiller2S(void *a);
u8 func_02093b7c(Unk02093910 *a, Unk0206bcb0 *b, u8 *c, u8 *d);
void func_02093c64(Unk02093910 *p);
void func_02093cb4(void);
void func_02093cd4(void);
void func_02093cf4(void *a, Unk02093cf4 *p);
void func_02093eac(Unk020e6fd4 *p);
void func_02093ee8(void *a, Unk02093cf4 *p);
void CreateNsKiller1(void *a);
