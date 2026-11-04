#pragma once

#include "types.h"

// Two bytes: a signed 12-bit number, a 2-bit selector at bit 12, and two more bits.
typedef struct Unk0201ea84 {
    /* 00 */ s16 mUnk_00_0 : 12;
    /* 00 */ u16 mUnk_00_12 : 2;
    /* 00 */ u16 mUnk_00_14 : 2;
} Unk0201ea84;

// 6-byte entry of the array RectTableGetEntry indexes: two Unk0201ea84 and the two sizes added to what func_0201ebe8
// and func_0201eba0 return for them.
typedef struct Unk0201eb54 {
    /* 00 */ Unk0201ea84 mUnk_00;
    /* 02 */ Unk0201ea84 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
} Unk0201eb54;

// Header of an array: a count at 6, then the entries from 8 (func_0201ea30 indexes 8-byte entries, func_0201ea58
// 12-byte ones, RectTableGetEntry and RectTableFindContaining 6-byte ones).
typedef struct Unk0201ea30 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk0201ea30;

void *func_0201ea58(Unk0201ea30 *a, s32 b);
s32 RectTableFindContaining(Unk0201ea30 *a, s32 b, s32 c);
Unk0201eb54 *RectTableGetEntry(Unk0201ea30 *a, s32 b);
u16 func_0201eb98(Unk0201ea30 *a);
s32 func_0201eba0(Unk0201ea84 a, s32 b);
s32 func_0201ebe8(Unk0201ea84 a, s32 b);
