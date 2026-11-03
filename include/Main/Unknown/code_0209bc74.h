#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h" // Unk020e6488
#include "Main/Unknown/code_020ea670.h" // Unk020ea670
#include "Main/Unknown/code_02087d0c.h" // Unk02087d0c

// Object the functions below receive: a value at 0x18.
typedef struct Unk0209bc74_a {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ s32 mUnk_18;
} Unk0209bc74_a;

// Three words written to the start of the objects of func_0209bc74, func_0209bd08, func_0209bd90 and func_0209be84.
typedef struct Unk0209bc74_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0209bc74_00;

// Object at 0x14 of Unk0209bc74 (0x74 bytes): two halfwords at 0x6c and 0x6e.
typedef struct Unk0209bc74_14 {
    /* 00 */ u8 mUnk_00[0x6c];
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
} Unk0209bc74_14;

// Object returned by func_0209bc74, func_0209bd08, func_0209bd90 and func_0209be84.
typedef struct Unk0209bc74 {
    /* 00 */ Unk0209bc74_00 mUnk_00;
    /* 0c */ Unk020e6488 *mUnk_0c;
    /* 10 */ Unk020ea670 *mUnk_10;
    /* 14 */ Unk0209bc74_14 *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk02087d0c * mUnk_1c[4];
} Unk0209bc74;

extern Unk0209bc74_00 data_021565a0;
extern Unk0209bc74_00 data_021565ac;
extern Unk0209bc74_00 data_021565b8;
extern Unk0209bc74_00 data_021565c4;
