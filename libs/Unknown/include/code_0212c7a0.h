#pragma once

#include "types.h"
#include "code_0212da38.h" // LinkedList

// 0x24 bytes; data_0217d89c holds an array of them. mUnk_0c is a list header.
typedef struct Unk0212c7a0 {
    /* 00 */ LinkedList mUnk_00;
    /* 0c */ LinkedList mUnk_0c;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20;
    /* 21 */ u8 mUnk_21[3];
} Unk0212c7a0;

void func_0212c7a0(u32 a, u32 b);
void func_0212c7b8(u32 a, u32 b);
void func_0212c7d8(u32 a, u32 b);
