#pragma once

#include "types.h"

extern void (*data_ov000_021b6384)(void);

// Thread entry functions (not lifted yet).

#include "code_0200db4c.h"

typedef struct Unk021b69dc Unk021b69dc;
typedef struct Unk021b5fa8 Unk021b5fa8;

// Object linked from Unk0200db5c.mUnk_a4.
typedef struct Unk021b04f8 {
    /* 00 */ Unk0200db5c *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
} Unk021b04f8;

extern u32 data_ov000_021b637c;
extern u32 data_ov000_021b638c;
extern u32 data_ov000_021b6390;
extern u32 data_ov000_021b63b0;
extern u32 data_ov000_021b63bc;
extern Unk021b69dc data_ov000_021b69dc[8];
extern u8 data_ov000_021b73a0[];

void func_ov000_021b0240(s32 a);
void func_ov000_021b026c(void);
void func_ov000_021b02b0(UnkFunc *arg0);
s32 func_ov000_021b02bc(void);
void func_ov000_021b02fc(Unk021b5fa8 *a);
s32 func_ov000_021b04cc(void);
void func_ov000_021b04d0(void);
void func_ov000_021b04d4(void);
void func_ov000_021b04f8(u32 a);
