#pragma once

#include "types.h"

// 0x1c bytes (bss). func_0214eed8 waits while mUnk_00 is 1; func_0214f1f4 and func_0214f2a8 set it and store their
// arguments in mUnk_04 and mUnk_08; func_0214f060 calls mUnk_04 and mUnk_10.
typedef struct Unk0214eed8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ void (*mUnk_10)();
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 *mUnk_18;
} Unk0214eed8;

// Argument of func_0214f264 and func_0214f2a8, 0x1c bytes.
typedef struct Unk0214f2a8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ void (*mUnk_14)();
    /* 18 */ u32 mUnk_18;
} Unk0214f2a8;

extern u16 data_02180410;
extern Unk0214eed8 data_02180414;

void func_0214eed8(void);
void func_0214eef0(u32 arg0);
s32 func_0214ef00(void);
u32 func_0214ef34(u32 a, u32 b, u32 c, u32 d);
void func_0214f060(u32 a, u32 b, u32 c);
u32 func_0214f1a0(void);
u32 func_0214f1b0(void);
u32 func_0214f1f4(void (*fn)(), u32 arg);
u32 func_0214f264(Unk0214f2a8 *p);
u32 func_0214f2a8(Unk0214f2a8 *p, void (*fn)(), u32 arg);
void func_0214f418(void);
