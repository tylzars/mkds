#pragma once

#include "types.h"
#include "00/code_02187484.h"
#include "00/code_02188008.h"
#include "00/code_021884d8.h"
#include "code_0214d018.h"
#include "00/code_021a5b3c.h"
#include "00/code_0218973c.h"
#include "00/code_0218a294.h"
#include "00/code_021898dc.h"
#include "00/code_02188ee0.h"

// Argument of func_ov000_02188868: the first two words go to the Unk021884e4 and the Unk02188114 it sets up, the
// bytes at 8 to 0xb to the object at data_ov000_021b4d00.
typedef struct Unk02188868 {
    /* 00 */ void *(*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
} Unk02188868;

// Argument of func_ov000_02188d78.
typedef struct Unk02188d78 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ Unk02188408Entry0xc0 *mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02188d78;

static inline void func_0214d018_inline(void *p, u32 n) {
    vu32 v = 0;
    MemFillWords(v, p, n);
}

// Declared here until the code that defines them is decompiled.

u32 func_ov000_02188720(void);
u32 func_ov000_02188758(void);
s32 func_ov000_021887cc(void);
u32 func_ov000_02188868(Unk02188868 *p);
void func_ov000_021889b0(u32 a, Unk02188408 *s);
void func_ov000_02188a74(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s);
void func_ov000_02188ad4(u8 a, Unk02188408Entry0xc0 *p, Unk02188408 *s);
s32 func_ov000_02188b20(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s);
s32 func_ov000_02188bc0(Unk02188408Entry0xc0 *p, s32 n, Unk02188408Entry24 *t);
s32 func_ov000_02188c1c(Unk02188408Entry0xc0 *p);
void func_ov000_02188ca8(Unk02188408Entry0xc0 *p);
void func_ov000_02188d78(Unk02188d78 *p);
