#pragma once

#include "types.h"
#include "code_02021f9c.h" // Unk02021f9c
#include "code_02022aa8.h" // Unk02022ce4

// Bit reader: a pointer to the next byte, the number of unread bits of the current byte at 4 and the byte at 5.
typedef struct Unk020247fc {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ s8 mUnk_04;
    /* 05 */ u8 mUnk_05;
} Unk020247fc;

// Body of a part of an Unk02021f9c, which starts 8 bytes after the part: words from 04 are offsets from the start of
// the Unk02021f9c, relocated by func_020245a4.
typedef struct Unk020245a4_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04[4];
} Unk020245a4_08;

void func_020245a4(Unk02021f9c *a);
u32 func_0202469c(Unk02021f9c *a, Unk02022ce4 **b);
u32 BitStreamReadBits(Unk020247fc *a, s32 b);
u16 CharReadByte(u8 **a);
u16 CharReadByteOrPair(u8 **a);
u16 CharReadOneToThreeBytes(u8 **a);
u16 CharReadHalfword(u16 **a);
