#pragma once

#include "types.h"

// Two words passed and returned by value.
typedef struct Unk02134008 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02134008;

typedef Unk02134008 (*Unk02134008Func)(Unk02134008 a, Unk02134008 b, u32 c);

// Returned by func_02142584; func_0213428c calls one of the function pointers at 0x04-0x14.
typedef struct Unk0217ee98 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02134008Func mUnk_04;
    /* 08 */ Unk02134008Func mUnk_08;
    /* 0c */ Unk02134008Func mUnk_0c;
    /* 10 */ Unk02134008Func mUnk_10;
    /* 14 */ Unk02134008Func mUnk_14;
} Unk0217ee98;

u32 func_02134008(u32 a, u32 b, u32 c, u32 d, u32 e);
u64 func_0213406c(u32 a, u32 b, u32 c, u32 d, u32 e);
u32 func_021340d4(u32 a, u32 b, u32 c);
u64 func_0213412c(u32 a, u32 b, u32 c);
u64 func_02134188(u32 a, u32 b);
u32 func_021341e0(u32 a, u32 b, u32 c);
u32 func_02134238(u32 a, u32 b);
Unk02134008 func_0213428c(Unk02134008 a, Unk02134008 b, u32 c);
