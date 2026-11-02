#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h"

// The 0xdc-byte object func_02038d88 returns is an Unk021755a0 (unk_02175000.h). Member 0x28 and member 0x70 of it
// are each followed by 0x44 bytes of the layout below.
typedef struct Unk02038e6c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
} Unk02038e6c;

// The 0x28 bytes func_02038de4 copies to the start of an Unk021755a0.
typedef struct Unk02038de4 {
    /* 00 */ u16 mUnk_00[4];
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e[13];
} Unk02038de4;

void func_02038c94(Unk021755a0 *p0, unsigned int p1);
u32 func_02038c9c(Unk021755a0 *arg0, u32 arg1, u32 arg2);
void func_02038cb0(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_02038cd8(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_02038d00(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_02038d28(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_02038d58(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void *func_02038d88(void *a, void *b);
void func_02038de4(Unk021755a0 *a, void *b);
void func_02038e6c(void *a, u32 b);
