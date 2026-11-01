#pragma once

#include "types.h"
#include "code_02017550.h" // Unk02017584

// Entry of 16 bytes, linked through mUnk_0c.
typedef struct Unk02017f58 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ struct Unk02017f58 *mUnk_0c;
} Unk02017f58;

// Two addresses that func_02018174 and func_020181f0 move towards each other, and the entries of an Unk02017f58 chain.
typedef struct Unk02018174 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ Unk02017f58 *mUnk_08;
} Unk02018174;

// Unk02017584 followed by an Unk02018174.
typedef struct Unk02017f24 {
    /* 00 */ Unk02017584 mUnk_00;
    /* 24 */ Unk02018174 mUnk_24;
} Unk02017f24;

u32 func_02017f24(Unk02017f24 *a);
u32 func_02017f58(Unk02017f24 *a, u32 b);
u32 func_02017fb4(Unk02017f24 *a, u32 b);
u32 func_0201800c(Unk02017f24 *a, u32 b);
void func_0201804c(Unk02017f24 *a, u32 b);
void *func_0201808c(Unk02017f24 *a, u32 b, s32 c);
void func_020180d4(Unk02017584 *a);
Unk02017f24 *func_020180e0(void *a, u32 b, u16 c);
void func_0201812c(Unk02017f24 *a);
void func_0201815c(Unk02017f24 *a);
u32 func_02018174(Unk02018174 *a, u32 b, u32 c);
void *func_020181f0(Unk02018174 *a, u32 b, u32 c);
Unk02017f24 *func_02018270(Unk02017f24 *a, u32 b, u16 c);
